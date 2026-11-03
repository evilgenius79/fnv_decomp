
// src/fallout/interface/menus/racesexmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/racesexmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct RaceSexMenu
{
    int __thiscall FUN_007ac4f0();
};

// @fnv 0x007ac4f0
int __thiscall RaceSexMenu::FUN_007ac4f0()
{
    return 0x40c;
}

// @fnv 0x007ac9c0
int __cdecl FUN_007ac9c0()
{
    return 0x40c;
}

struct FUN_007b2550_shell
{
    void SetByteAtOffsetE4(unsigned char param);
};

// @fnv 0x007b2550
void __thiscall FUN_007b2550_shell::SetByteAtOffsetE4(unsigned char ucValue)
{
    ((unsigned char*)this)[0xe4] = ucValue;
}

struct FUN_007b2570_shell
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    char FUN_007b2570();
};

struct C
{
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
};

// @fnv 0x007b2570
char FUN_007b2570_shell::FUN_007b2570()
{
    return m_iFourthElementInteger && ((C*)m_iFourthElementInteger)->m_f;
}

struct FUN_007b3720_shell
{
    void FUN_007b3720(int value);
};

// @fnv 0x007b3720
void FUN_007b3720_shell::FUN_007b3720(int value)
{
    *(int*)((char*)this + 0x1d8) = value;
}

struct TGF
{
    float GetFloat(int);
};

struct RaceSexMenu_MenuOption
{
    TGF* pTGF;
    void FUN_007b3840(int& aiLow, int& aiHigh);
};

// If pTGF is set, reads floats 0x1006 and 0x1007 from it and stores them as ints into aiLow and aiHigh.
// @fnv 0x007b3840
void RaceSexMenu_MenuOption::FUN_007b3840(int& aiLow, int& aiHigh)
{
    if (pTGF)
    {
        aiLow = (int)pTGF->GetFloat(0x1006);
        aiHigh = (int)pTGF->GetFloat(0x1007);
    }
}

struct FUN_007b3b80_shell
{
    void CreateEntry(int a, const char* s, int b, int c);
    void FUN_007b3b80(int a, int b);
};

// @fnv 0x007b3b80
void FUN_007b3b80_shell::FUN_007b3b80(int aiArg1, int aiArg2)
{
    CreateEntry(aiArg1, "RSM_list_item_template", aiArg2, 0);
}

struct Tile
{
    void Set(int, float, bool);
};

int __cdecl GetTileValueID(const char*, int);

struct FUN_007b4180_shell
{
    Tile* m_tile;
    void SetSelected();
};

// @fnv 0x007b4180
void FUN_007b4180_shell::SetSelected()
{
    if (m_tile)
    {
        m_tile->Set(GetTileValueID("_selected", -1), 1.0f, true);
    }
}

struct FUN_007ac530_shell
{
    void FUN_007ac560();
    void* FUN_007ac530(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_007ac560, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007ac530
void* FUN_007ac530_shell::FUN_007ac530(unsigned int flags)
{
    FUN_007ac560();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_007b3af0_shell
{
    void __thiscall FUN_007b3af0();
};
struct FUN_007ac700_shell
{
    void* __thiscall FUN_007ac700(unsigned int flags);
};
// @fnv 0x007ac700
void* __thiscall FUN_007ac700_shell::FUN_007ac700(unsigned int flags)
{
    ((FUN_007b3af0_shell*)this)->FUN_007b3af0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_007acb30 {
extern "C" void __cdecl _Deallocate(void*);
struct FUN_007acb30_shell
{
    void __thiscall FUN_007fed10();
    void* __thiscall FUN_007acb30(unsigned int flags);
};
// Calls FUN_007fed10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007acb30
void* __thiscall FUN_007acb30_shell::FUN_007acb30(unsigned int flags)
{
    FUN_007fed10();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_007acb30

extern "C" void* DAT_011da634;

struct ArrSI
{
    unsigned int GetFlags();
};

struct MiddleHighProcess
{
    unsigned int GetAnimation();
};

// Returns 1 if si is non-null, has flags, and DAT_011da634's process animation equals si's flags; otherwise 0.
// @fnv 0x007ad8d0
char __cdecl IsAnimationMatch(ArrSI* pArrSI)
{
    int result;
    if (pArrSI && pArrSI->GetFlags() && DAT_011da634 && *(int*)((char*)DAT_011da634 + 0xd8) &&
        ((MiddleHighProcess*)*(int*)((char*)DAT_011da634 + 0xd8))->GetAnimation() == pArrSI->GetFlags())
        result = 1;
    else
        result = 0;
    return (char)result;
}

struct FUN_007ae160_Obj
{
    TGF* pTGF;
    bool IsSelected();
};
// Returns true when pTGF is non-null and its _selected float equals 2.0.
// @fnv 0x007ae160
bool FUN_007ae160_Obj::IsSelected()
{
    return pTGF && (pTGF->GetFloat(GetTileValueID("_selected", -1)) == 2.0);
}

struct FUN_007b3740_shell
{
    TGF* m_pTGF;
    int GetFloat1005();
};

// @fnv 0x007b3740
int FUN_007b3740_shell::GetFloat1005()
{
    return (int)m_pTGF->GetFloat(0x1005);
}

struct Tile_Set_Helper
{
    void __thiscall Set(int, int);
};
struct TileValueAccessor
{
    Tile* m_tile;
    int __thiscall GetFloat1005();
    void __thiscall FUN_007b3760(int value);
    void __thiscall FUN_007b3890(int aiLow, int aiHigh);
};
// @fnv 0x007b3890
void __thiscall TileValueAccessor::FUN_007b3890(int aiLow, int aiHigh)
{
    if (m_tile)
    {
        ((Tile_Set_Helper*)m_tile)->Set(0x1006, aiLow);
        ((Tile_Set_Helper*)m_tile)->Set(0x1007, aiHigh);
        if (GetFloat1005() < aiLow)
            FUN_007b3760(aiLow);
        if (GetFloat1005() > aiHigh)
            FUN_007b3760(aiHigh);
    }
}

namespace fnv_007b3970 {
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct FUN_007b3970_shell
{
    Tile_Set_Helper* m_tile;
    void SetTileEnabled(bool abEnabled);
};
// If m_tile is set, calls Set on it with the "_enabled" key and abEnabled.
// @fnv 0x007b3970
void FUN_007b3970_shell::SetTileEnabled(bool abEnabled)
{
    if (m_tile)
        m_tile->Set(GetTileValueID("_enabled", -1), abEnabled);
}
}  // namespace fnv_007b3970

struct S007b39b0
{
    TGF* m_iWordAt00;
    int __thiscall GetPosition();
};
// @fnv 0x007b39b0
int __thiscall S007b39b0::GetPosition()
{
    return (int)m_iWordAt00->GetFloat(GetTileValueID("_position", -1));
}

extern float DAT_010162c0;
extern const char $SG2670[];

struct FUN_007b4140_shell
{
    Tile* m_tile;
    void SetTileValue();
};

// @fnv 0x007b4140
void FUN_007b4140_shell::SetTileValue()
{
    if (m_tile)
        m_tile->Set(GetTileValueID($SG2670, -1), DAT_010162c0, true);
}

struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*&);
};
struct S
{
    Tile* FUN_007b41c0(int);
};
// Walks the linked list starting at the value stored in this, returning the first Tile whose first int equals a, or 0 if none matches.
// @fnv 0x007b41c0
Tile* S::FUN_007b41c0(int a)
{
    void* cur = (void*)(unsigned int)(*(Flt*)this);
    while (cur)
    {
        Tile* item = ((TL*)this)->GetNext(cur);
        if (*(int*)item == a)
            return item;
    }
    return 0;
}

namespace fnv_007b4210 {
struct Flt
{
    operator unsigned int();
};
struct TL
{
    Tile*& GetNext(void*&);
};
struct TileValueAccessor
{
    int _00;
    unsigned int _04;
};
struct FUN_007b4210_shell
{
    TileValueAccessor* FindByColor(unsigned int);
};
// Walks the tile list from this object, returning the first entry whose _04 equals aiColor, or null if none matches.
// @fnv 0x007b4210
TileValueAccessor* FUN_007b4210_shell::FindByColor(unsigned int aiColor)
{
    void* piter;
    TileValueAccessor* popt;
    piter = (void*)((Flt*)this)->operator unsigned int();
    while (piter)
    {
        popt = (TileValueAccessor*)(Tile*)((TL*)this)->GetNext(piter);
        if (popt->_04 == aiColor)
            return popt;
    }
    return 0;
}
}  // namespace fnv_007b4210

struct FUN_007b4900_shell
{
    int m0;
    int m1;
    int m2;
    FUN_007b4900_shell* FUN_007b4900();
};
// Sets m0 and m2 to zero and returns this.
// @fnv 0x007b4900
FUN_007b4900_shell* FUN_007b4900_shell::FUN_007b4900()
{
    m0 = 0;
    m2 = 0;
    return this;
}

struct FUN_007b5300_param
{
    int _0;
    int _4;
};
struct FUN_007b5300_shell
{
    int GetSecondField(FUN_007b5300_param* p);
};
// Returns the second field of the given parameter struct, or 0 if the pointer is null.
// @fnv 0x007b5300
int FUN_007b5300_shell::GetSecondField(FUN_007b5300_param* p)
{
    return p ? p->_4 : 0;
}

namespace fnv_007ac500 {
struct Tile;
struct RaceSexMenu
{
    char pad[0x78];
    Tile* m_pTiles[24];
    void SetTile(int aiID, Tile* apTile);
};

// @fnv 0x007ac500
void RaceSexMenu::SetTile(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 6)
        m_pTiles[aiID] = apTile;
}
}  // namespace fnv_007ac500

struct FUN_007adc30_shell
{
    char _pad[0xec];
    unsigned int m_flags;
    bool FUN_007adc30(int trait);
};

// Returns whether the bit for the given trait index is set in m_flags.
// @fnv 0x007adc30
bool FUN_007adc30_shell::FUN_007adc30(int trait)
{
    return (m_flags & (1 << trait)) != 0;
}

struct TileHelper
{
    void Set(int, const char*, bool);
};
struct BSAudio
{
    int GetAudioBackendData();
};
struct OptList
{
    void FUN_007b4410();
    int FUN_0084e3a0();
};
struct FORenderedMenu
{
    void UpdateSlotSelection(int);
};
struct InterfaceManager
{
    FORenderedMenu* GetActiveRenderedMenu();
};
InterfaceManager* FUN_004b7210();
extern Flt g_011da700;
extern Flt g_011da70c;
struct FUN_007af180_shell : FUN_007adc30_shell
{
    void PopulateHairOptions();
    void PopulateEyesList();
    void SyncListItemTemplate();
    void UpdateMinusPlusTiles();
    bool FUN_007af180(int aeList);
};
// @fnv 0x007af180
bool FUN_007af180_shell::FUN_007af180(int aeList)
{
    if (aeList < 20)
    {
        (*(Tile_Set_Helper**)((char*)this + 4))->Set(0x1004, aeList);
        ((OptList**)((char*)this + 0x28))[aeList]->FUN_007b4410();
        if (aeList == 5 && FUN_007adc30(0))
            PopulateHairOptions();
        else if (aeList == 8 && FUN_007adc30(1))
            PopulateEyesList();
        else if (aeList == 3)
            SyncListItemTemplate();
        UpdateMinusPlusTiles();
        if (FUN_004b7210()->GetActiveRenderedMenu() && aeList < 4)
            FUN_004b7210()->GetActiveRenderedMenu()->UpdateSlotSelection(aeList);
        (*(Tile_Set_Helper**)((char*)this + 0x88))
            ->Set(0xfa3, ((OptList**)((char*)this + 0x28))[aeList]->FUN_0084e3a0() < 20);
        (*(Tile_Set_Helper**)((char*)this + 0x8c))
            ->Set(0xfa3, ((BSAudio**)((char*)this + 0x28))[aeList]->GetAudioBackendData() < 20 ||
                             aeList == *(int*)((char*)this + 0x120));
        (*(TileHelper**)((char*)this + 0x8c))
            ->Set(0xfc4, (const char*)(unsigned int)(aeList == *(int*)((char*)this + 0x120) ? g_011da70c : g_011da700),
                  true);
        return true;
    }
    else
        return false;
}

struct TESActorBase
{
    int GetSex();
};
struct HairResult
{
    int a;
    int b;
};
struct FUN_004ac110_shell
{
    HairResult* FUN_004ac110();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
    bool FUN_0076b610();
    unsigned int GetFlags();
};
struct MenuOption2
{
    MenuOption2* FindByColor(int);
    void SetTileEnabled(bool);
    void FUN_007b3890(int, int);
};
void __cdecl FUN_00603280(HairResult*, int, GlobalObject_00869f00*);
struct FUN_007af610_shell
{
    void UpdateHairMenuOption();
};
// @fnv 0x007af610
void FUN_007af610_shell::UpdateHairMenuOption()
{
    ((GlobalObject_00869f00*)((char*)this + 0xdc))->Clear(false);
    FUN_00603280(((FUN_004ac110_shell*)*((FUN_004ac110_shell**)((char*)this + 0xd8)))->FUN_004ac110(),
                 ((TESActorBase*)*((TESActorBase**)((char*)this + 0xd8)))->GetSex(),
                 (GlobalObject_00869f00*)((char*)this + 0xdc));
    MenuOption2* popt = ((MenuOption2*)*((MenuOption2**)((char*)this + 0x30)))->FindByColor(0x18);
    if (((GlobalObject_00869f00*)((char*)this + 0xdc))->FUN_0076b610())
    {
        popt->SetTileEnabled(false);
    }
    else
    {
        popt->SetTileEnabled(true);
        popt->FUN_007b3890(true, ((GlobalObject_00869f00*)((char*)this + 0xdc))->GetFlags());
    }
}

namespace fnv_007b1ca0 {
struct TESNPC;
struct TESEyes;
struct TESHair
{
    bool IsValidForNPC(TESNPC*);
    bool FUN_005fdf60();
    bool IsFlag4Clear();
};
struct FUN_005fdf40_shell
{
    bool FUN_005fdf40();
};
struct FUN_005fc5f0_shell
{
    bool CanBeNPC(TESNPC*);
};
struct TESActorBase
{
    int GetSex();
};
struct HairNode
{
    TESHair** _ref_006815c0();
    HairNode* _ref_00726070();
};
struct TESRace
{
    TESHair* FUN_00613870(int);
    TESEyes* GetReferencedValue();
};
struct FUN_004ac110_shell
{
    TESRace* FUN_004ac110();
};
HairNode* __fastcall FUN_0045bb80(TESRace*);
struct TESNPC
{
    TESHair* GetHair();
    void SetHair(TESHair*);
    void SetEyes(TESEyes*);
};
struct FUN_007adc60_shell
{
    void FUN_007adc60(int, bool);
};
struct FUN_007b1ca0_t
{
    char pad[0xd8];
    TESNPC* pNPC;
    void RebuildFaceGen(int);
    void UpdateEyeTextures();
    void UpdateHairAndEyes();
};

// @fnv 0x007b1ca0
void FUN_007b1ca0_t::UpdateHairAndEyes()
{
    if (!pNPC->GetHair()->IsValidForNPC(pNPC))
    {
        TESHair* m_pHair = ((FUN_004ac110_shell*)pNPC)->FUN_004ac110()->FUN_00613870(((TESActorBase*)pNPC)->GetSex());
        for (HairNode* pNode = FUN_0045bb80(((FUN_004ac110_shell*)pNPC)->FUN_004ac110());
             m_pHair == 0 && pNode && *pNode->_ref_006815c0(); pNode = pNode->_ref_00726070())
        {
            if (((FUN_005fdf40_shell*)*pNode->_ref_006815c0())->FUN_005fdf40())
            {
                if ((((TESActorBase*)pNPC)->GetSex() == 0 && (*pNode->_ref_006815c0())->FUN_005fdf60()) ||
                    (((TESActorBase*)pNPC)->GetSex() == 1 && (*pNode->_ref_006815c0())->IsFlag4Clear()))
                    m_pHair = *pNode->_ref_006815c0();
            }
        }
        pNPC->SetHair(m_pHair);
        RebuildFaceGen(1);
    }
    if (!((FUN_005fc5f0_shell*)((MiddleHighProcess*)pNPC)->GetAnimation())->CanBeNPC(pNPC))
    {
        pNPC->SetEyes(((FUN_004ac110_shell*)pNPC)->FUN_004ac110()->GetReferencedValue());
        UpdateEyeTextures();
    }
    ((FUN_007adc60_shell*)this)->FUN_007adc60(0, true);
    ((FUN_007adc60_shell*)this)->FUN_007adc60(1, true);
}
}  // namespace fnv_007b1ca0

struct NiUpdateData
{
    float f;
    bool b;
    bool c;
    NiUpdateData(float, bool, bool);
};
struct NiNode
{
    void Update(NiUpdateData const&);
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
struct ShadowSceneNode
{
    void RemoveSceneObject(NiNode*, bool);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_007fd660_shell
{
    void FUN_007fd660(float);
};
extern PC_00605d70* g_thePlayer;
struct FUN_007b1ae0_shell
{
    void UpdateShadowSceneNode();
};
// Updates the shadow scene node for the player's node, then updates the node and, if a condition holds, calls FUN_007fd660 with 1.0f.
// @fnv 0x007b1ae0
void FUN_007b1ae0_shell::UpdateShadowSceneNode()
{
    int pad;
    NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3)->RemoveSceneObject(g_thePlayer->GetNode(false), false);
    NiUpdateData data(0.0f, false, false);
    reinterpret_cast<NiNode*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))->Update(data);
    if (FUN_004b7210()->GetActiveRenderedMenu())
        reinterpret_cast<FUN_007fd660_shell*>(FUN_004b7210()->GetActiveRenderedMenu())->FUN_007fd660(1.0f);
}

struct IMStandIn
{
    void FUN_00715860(int, int, int);
};
struct InputFocusController
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    IMStandIn* m_20;
    bool SetFocus(bool abFocus);
};
// @fnv 0x007b3fd0
bool InputFocusController::SetFocus(bool abFocus)
{
    bool bret = false;
    if (abFocus)
    {
        if (m_20 && *(void**)m_20)
        {
            reinterpret_cast<IMStandIn*>(FUN_004b7210())->FUN_00715860((int)*(void**)m_20, 0xfc3, 1);
            bret = true;
        }
    }
    else
    {
        reinterpret_cast<IMStandIn*>(FUN_004b7210())->FUN_00715860(0, 0xfc3, 1);
        m_20 = 0;
        bret = true;
    }
    return bret;
}

struct FUN_007b5180_shell : FUN_007af610_shell
{
    char _pad[0xc4];
    MenuOption2* m_pCurrentOption;
    void HandleOptionSelection();
    void CreateMenuOption();
};
// @fnv 0x007b5180
void FUN_007b5180_shell::CreateMenuOption()
{
    int ilow;
    int ihigh;
    UpdateHairMenuOption();
    m_pCurrentOption = ((MenuOption2*)*(void**)((char*)this + 0x30))->FindByColor(0x18);
    ((RaceSexMenu_MenuOption*)m_pCurrentOption)->FUN_007b3840(ilow, ihigh);
    ((TileValueAccessor*)m_pCurrentOption)->FUN_007b3760(ilow);
    HandleOptionSelection();
    m_pCurrentOption = 0;
}

struct FUN_00601830_shell
{
    void RandomizeFace(int, int, int);
};
struct FUN_007adc60_shell
{
    void FUN_007adc60(int, bool);
};
struct FUN_007b18f0_shell
{
    void HandleMenuKey(int);
};
struct FUN_007b1e70_shell
{
    void UpdateFaceGen(int, int, int);
};
struct FUN_007b25a0_shell
{
    void UpdatePlayerHead();
};
struct FUN_007b51f0_shell : FUN_007adc30_shell
{
    void FUN_007b51f0();
};
char __cdecl ConsumeByteAtE4();
// @fnv 0x007b51f0
void __cdecl FUN_007b51f0()
{
    if (DAT_011da634)
    {
        if (ConsumeByteAtE4() == 1 || ((FUN_007adc30_shell*)DAT_011da634)->FUN_007adc30(7))
        {
            ((FUN_00601830_shell*)(void*)(*((char**)DAT_011da634 + 0xd8 / 4)))->RandomizeFace(1, 0, 1);
            ((FUN_007adc60_shell*)DAT_011da634)->FUN_007adc60(7, true);
            ((FUN_007b18f0_shell*)DAT_011da634)->HandleMenuKey(0x22);
            ((FUN_007b18f0_shell*)DAT_011da634)->HandleMenuKey(0x23);
            ((FUN_007b1e70_shell*)DAT_011da634)->UpdateFaceGen(1, 1, 0);
            ((FUN_007b25a0_shell*)DAT_011da634)->UpdatePlayerHead();
            ((FUN_007adc60_shell*)DAT_011da634)->FUN_007adc60(8, false);
            ((FUN_007adc60_shell*)DAT_011da634)->FUN_007adc60(9, false);
        }
    }
}

struct _ref_006815c0_shell
{
    int* __thiscall _ref_006815c0();
};

struct FUN_007b1e50_shell
{
    unsigned char _pad[0xa8];
    _ref_006815c0_shell m_ref;

    int GetReferencedValue();
};

// @fnv 0x007b1e50
int FUN_007b1e50_shell::GetReferencedValue()
{
    return *m_ref._ref_006815c0();
}

struct Menu
{
};
struct InterfaceManager_helper
{
    Tile* FUN_00586150();
};
struct TileH
{
    Tile* ReadFile(const char*);
    Menu* GetMenu();
};
struct TileNode
{
    NiNode* FUN_0056c7f0();
};
struct Tile_Helper
{
    static void UpdateAll(bool);
};
struct Str6a70
{
    Str6a70& operator=(const char*);
};
Tile* __cdecl FUN_00a09030(int);
extern const char DAT_010759bc[];
struct FUN_00a1dc70_shell
{
    void FUN_00a1dc70(Tile*, bool);
};
struct SettingT_GameSettingCollection_
{
    const char* String();
};
struct GlobalObject_0040c150
{
};
extern GlobalObject_0040c150 g_011d35c4, g_011d34b0, g_011d1fec;
struct StrH
{
    void FUN_007b52a0();
};
struct GlobalObject_004037b0
{
};
extern GlobalObject_004037b0 g_011da6f4;
int __cdecl FUN_004b7220();
struct Actor
{
    unsigned char FUN_008a6970();
    void SetWantsWeaponOut(int);
    void UnEquipObject(void*, int, void*, bool, bool, bool);
};
extern Actor* pPlayer;
extern "C" unsigned char DAT_011da688;
struct InventoryChanges
{
    static InventoryChanges* GetOrAddInventoryChanges(Actor*);
    ArrSI* FUN_004c8c10(unsigned int, int);
};
extern "C" ArrSI* DAT_011da638[];
struct RaceInit
{
    void SetupRaceMenu(int);
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011db620;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct FUN_007ac9f0
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
    FUN_007ac9f0();
    void FUN_007ac9d0(int);
};
struct MagicHitEffect
{
    void FUN_00984f60(unsigned int);
};
struct NiPick
{
    void FUN_00705fc0(void*);
};
struct Im7181
{
    void SetRenderedMenu(int);
};
// @fnv 0x007ac730
Tile* __cdecl GetOrCreateMenuTile(int param)
{
    Tile* previous = FUN_00a09030(FUN_007ac9c0());
    if (previous)
        return previous;
    Tile* tile = ((TileH*)((InterfaceManager_helper*)FUN_004b7210())->FUN_00586150())->ReadFile(DAT_010759bc);
    if (tile)
    {
        DAT_011da634 = ((TileH*)tile)->GetMenu();
        ((FUN_00a1dc70_shell*)DAT_011da634)->FUN_00a1dc70(tile, false);
        if (!(unsigned int)g_011da70c)
        {
            *(Str6a70*)&g_011da70c = ((SettingT_GameSettingCollection_*)&g_011d35c4)->String();
            *(Str6a70*)&g_011da700 = ((SettingT_GameSettingCollection_*)&g_011d34b0)->String();
            *(Str6a70*)&g_011da6f4 = ((SettingT_GameSettingCollection_*)&g_011d1fec)->String();
            if (FUN_004b7220() != 3)
            {
                ((StrH*)&g_011da70c)->FUN_007b52a0();
                ((StrH*)&g_011da700)->FUN_007b52a0();
                ((StrH*)&g_011da6f4)->FUN_007b52a0();
            }
        }
        DAT_011da688 = pPlayer->FUN_008a6970();
        pPlayer->SetWantsWeaponOut(0);
        InventoryChanges* inventory = InventoryChanges::GetOrAddInventoryChanges(pPlayer);
        for (unsigned int i = 0; i < 20; i++)
        {
            switch (i)
            {
            case 0:
            case 1:
            case 5:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 14:
            case 15:
                DAT_011da638[i] = inventory->FUN_004c8c10(i, 0);
                if (DAT_011da638[i])
                    pPlayer->UnEquipObject((void*)DAT_011da638[i]->GetFlags(), 1, 0, 0, 0, 1);
                break;
            }
        }
        ((RaceInit*)DAT_011da634)->SetupRaceMenu(param);
        if (*g_011db620.Bool())
        {
            Tile_Helper::UpdateAll(false);
            FUN_007ac9f0* pRenderData = new FUN_007ac9f0;
            pRenderData->FUN_007ac9d0(param);
            ((MagicHitEffect*)pRenderData)->FUN_00984f60((unsigned int)tile);
            ((NiPick*)pRenderData)->FUN_00705fc0(((TileNode*)tile)->FUN_0056c7f0());
            ((Im7181*)FUN_004b7210())->SetRenderedMenu((int)pRenderData);
        }
    }
    return tile;
}

struct Obj0
{
    int FUN_0044ddc0();
};

struct Obj1
{
    int FUN_00603b50();
};

struct Holder
{
    char _pad[0xd8];
    Obj1* m_d8;
};

// Returns 1 if p and DAT_011da634 and its m_d8 are non-null and m_d8's FUN_00603b50 equals p's FUN_0044ddc0, else 0.
// @fnv 0x007ad860
unsigned char __cdecl FUN_007ad860(Obj0* pObject)
{
    int r;
    if (pObject != 0 && pObject->FUN_0044ddc0() != 0 && DAT_011da634 != 0 && ((Holder*)DAT_011da634)->m_d8 != 0 &&
        ((Holder*)DAT_011da634)->m_d8->FUN_00603b50() == pObject->FUN_0044ddc0())
    {
        r = 1;
    }
    else
    {
        r = 0;
    }
    return r;
}

struct FUN_007ad940_Holder
{
    char unk00[0xd8];
    void* m_d8;
};

int __fastcall FUN_005f0cc0(void* self);
int __fastcall FUN_00726070(int value);

// @fnv 0x007ad940
unsigned char __cdecl FUN_007ad940(int aiValue)
{
    int result;
    if (aiValue != 0 && DAT_011da634 != 0 && ((FUN_007ad940_Holder*)DAT_011da634)->m_d8 != 0 &&
        ((FUN_005f0cc0(((FUN_007ad940_Holder*)DAT_011da634)->m_d8) == 0 && FUN_00726070(aiValue) == 0x15) ||
         (FUN_005f0cc0(((FUN_007ad940_Holder*)DAT_011da634)->m_d8) == 1 && FUN_00726070(aiValue) == 0x16)))
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return (unsigned char)result;
}

struct FUN_007ad9c0_Sub
{
    bool Probe();
    int* Lookup();
};

struct FUN_007ad9c0_Owner
{
    FUN_007ad9c0_Sub* GetSub();
};

struct FUN_007ad9c0_Arg
{
    int Value();
};

// Returns 1 when a1 is non-null and DAT_011da634's sub at offset 0xd8 fails Probe and its Lookup equals a1->Value(); otherwise 0.
// @fnv 0x007ad9c0
char __cdecl IsArgValueInSubLookup(FUN_007ad9c0_Arg* a1)
{
    int result;
    if (a1 != 0 && DAT_011da634 != 0 && *(void**)((char*)DAT_011da634 + 0xd8) != 0 &&
        ((FUN_007ad9c0_Owner*)*(void**)((char*)DAT_011da634 + 0xd8))->GetSub()->Probe() == false &&
        *((FUN_007ad9c0_Owner*)*(void**)((char*)DAT_011da634 + 0xd8))->GetSub()->Lookup() == a1->Value())
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return (char)result;
}

struct RSTile
{
    bool IsVisible();
    void Set(int id, int value);
};

struct RSOptionList
{
    bool SetFocus(bool abFocus);
    void FUN_007b4410();
};

struct RSMenu
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
    RSOptionList* optionLists[4];
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
    RSTile* tile8C;

    bool HasTrait(int trait);
    void Refresh();
    void SetTrait(int trait, bool on);
    int GetCurrentPage();
    void Accept();
    RSTile* GetTile();
    void Close();
};

struct RSIM
{
    void ShowMessage(RSTile* tile, int id, int flag);
};

struct RSItem
{
    ~RSItem();
    void* GetForm();
};

struct RSPlayer
{
    void EquipObject(void* form, int count, void* extra, bool a, bool b, bool c);
    void SetFlagX(bool b);
    void Finish(bool b);
};

extern RSMenu* g_raceSexMenu;
extern RSItem* g_raceSexItems[20];
extern bool g_raceSexFlag;
extern RSPlayer* g_thePlayerRS;

char __cdecl ConsumeByteAtE4();
bool __cdecl RS_IsSomething();
RSIM* __cdecl RS_GetIM();
void __cdecl RS_Helper();
bool __cdecl RS_Check();
int __cdecl RS_Lookup(int a, int b);
void __cdecl RS_Use(int x);

// @fnv 0x007ada40
void __cdecl UpdateRaceSexMenu()
{
    if (g_raceSexMenu)
    {
        if (g_raceSexMenu->HasTrait(9))
        {
            g_raceSexMenu->Refresh();
            g_raceSexMenu->SetTrait(9, false);
        }
        if (ConsumeByteAtE4() == 1)
        {
            if (RS_IsSomething())
            {
                if (!g_raceSexMenu->optionLists[g_raceSexMenu->GetCurrentPage()]->SetFocus(true))
                {
                    if (g_raceSexMenu->tile8C->IsVisible())
                    {
                        RS_GetIM()->ShowMessage(g_raceSexMenu->tile8C, 0xfc3, 1);
                    }
                    else
                    {
                        g_raceSexMenu->optionLists[g_raceSexMenu->GetCurrentPage()]->FUN_007b4410();
                        g_raceSexMenu->Accept();
                    }
                }
            }
        }
        else
        {
            RS_Helper();
            g_raceSexMenu->GetTile()->Set(0x1772, 1);
            g_raceSexMenu->Close();
            g_raceSexMenu = 0;
            if (RS_Check())
            {
                RS_Use(RS_Lookup(5, 4));
            }
            for (int i = 0; i < 20; i++)
            {
                if (g_raceSexItems[i])
                {
                    g_thePlayerRS->EquipObject(g_raceSexItems[i]->GetForm(), 1, 0, true, false, true);
                    delete g_raceSexItems[i];
                    g_raceSexItems[i] = 0;
                }
            }
            g_thePlayerRS->SetFlagX(g_raceSexFlag);
            g_thePlayerRS->Finish(true);
        }
    }
}

class HighProcess7AE
{
  public:
    int GetProcessLevel();
};

class Tile7AE
{
  public:
    int GetValue();
};

class TileList7AE
{
  public:
    Tile7AE* GetTile(int iLevel);
};

class Timer7AE
{
  public:
    float GetTime();
};

Timer7AE* GetInterfaceTimer7AE();

class StatsMenu7AE
{
  public:
    int GetCurrentPage();
    void FUN_007ae1b0(int iType, HighProcess7AE* pkProcess);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24;
    TileList7AE* m_apkLists[10];
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4;
    float m_fTime;
    int m_iValue;
    HighProcess7AE* m_pkProcess;
    Tile7AE* m_pkTile;
};

// For type 0x69 stores the process and its level tile value; for type 1 stores the interface timer time.
// @fnv 0x007ae1b0
void StatsMenu7AE::FUN_007ae1b0(int iType, HighProcess7AE* pkProcess)
{
    switch (iType)
    {
    case 0x69:
        m_pkProcess = pkProcess;
        m_pkTile = m_apkLists[GetCurrentPage()]->GetTile(pkProcess->GetProcessLevel());
        m_iValue = m_pkTile->GetValue();
    case 1:
        m_fTime = GetInterfaceTimer7AE()->GetTime();
    }
}

class TESNPC;
struct TESFullName
{
    const char* GetFullName();
};
struct Hair
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    TESFullName fullName;
    bool FUN_005fdf40();
    bool IsHairValidForNPC(TESNPC*);
};
struct HairNode
{
    Hair** FUN_006815c0();
    HairNode* FUN_00726070();
};
struct TESDataHandler
{
    HairNode* GetTESHairList();
};
extern TESDataHandler* DAT_011c3f2c;
struct HairOption
{
    void FUN_00403550(Hair*);
};
struct HairOptions
{
    void FUN_007b45b0();
    HairOption* FUN_007b3b80(const char*, int);
    HairOption* FUN_007af430();
    bool FUN_007b4260(int);
    void ApplyToAllTiles();
};
bool __cdecl FUN_007ad860(HairOption*);
struct HairMenu
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
    HairOptions* options;
    unsigned int unk40;
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
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
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
    TESNPC* npc;
    void PopulateHairOptions();
    void UpdateMinusPlusTiles();
    void FUN_007adc60(int, bool);
};
// @fnv 0x007af300
void HairMenu::PopulateHairOptions()
{
    options->FUN_007b45b0();
    HairOption* pChosenOption = 0;
    for (HairNode* node = DAT_011c3f2c->GetTESHairList(); node && *node->FUN_006815c0(); node = node->FUN_00726070())
    {
        if ((*node->FUN_006815c0())->FUN_005fdf40() && (*node->FUN_006815c0())->IsHairValidForNPC(npc))
        {
            HairOption* option = options->FUN_007b3b80((*node->FUN_006815c0())->fullName.GetFullName(), 27);
            option->FUN_00403550(*node->FUN_006815c0());
            if (!pChosenOption && FUN_007ad860(option))
                pChosenOption = option;
        }
    }
    UpdateMinusPlusTiles();
    while (pChosenOption && pChosenOption != options->FUN_007af430() && options->FUN_007b4260(2))
    {
    }
    options->ApplyToAllTiles();
    FUN_007adc60(0, false);
}

class B7AF450NPC;

class B7AF450Texture
{
  public:
    const char* GetTextureResourceName() const;
};

class B7AF450Eyes
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B7AF450Texture m_kTexture;

    bool IsPlayable();
    bool CanBeUsedBy(B7AF450NPC* pkNPC);
};

class B7AF450EyesNode
{
  public:
    B7AF450Eyes** GetItem();
    B7AF450EyesNode* GetNext();
};

class B7AF450DataHandler
{
  public:
    B7AF450EyesNode* GetEyesList();
};

class B7AF450ListItem
{
  public:
    void SetData(B7AF450Eyes* pkEyes);
};

class B7AF450ListBox
{
  public:
    void Clear();
    B7AF450ListItem* AddItem(const char* pcText, int iType);
    void Finish();
};

extern B7AF450DataHandler* g_pkB7AF450DataHandler;

class B7AF450RaceMenu
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
    B7AF450ListBox* m_pkListBox;
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
    int unkD0;
    int unkD4;
    B7AF450NPC* m_pkNPC;

    void FUN_007adc60(int iIndex, bool bFlag);
    void PopulateEyesList();
};

// @fnv 0x007af450
void B7AF450RaceMenu::PopulateEyesList()
{
    m_pkListBox->Clear();
    for (B7AF450EyesNode* pkIter = g_pkB7AF450DataHandler->GetEyesList(); pkIter && *pkIter->GetItem();
         pkIter = pkIter->GetNext())
    {
        if ((*pkIter->GetItem())->IsPlayable() && (*pkIter->GetItem())->CanBeUsedBy(m_pkNPC))
            m_pkListBox->AddItem((*pkIter->GetItem())->m_kTexture.GetTextureResourceName(), 0x21)
                ->SetData(*pkIter->GetItem());
    }
    m_pkListBox->Finish();
    FUN_007adc60(1, false);
}

// SyncListItemTemplate: thiscall, /MT /Od /GS /EHsc. Two guarded blocks on flags from this->m_34 / this->m_d8.
struct Opt34
{
    Opt34* FindByColor(int);
    void FUN_007b3d50(int, const char*);
    void RemoveOptionById(int);
};
struct D8Obj
{
    int FUN_005f0cc0();
};
struct SpStr
{
    void* m_ptr;
    int m_len;
    SpStr();
    ~SpStr();
    const char* FUN_00559450(const char*, int);
};
struct StrTable
{
    const char* FUN_00403df0();
};
extern StrTable DAT_011d23a0;
extern "C" void __cdecl FUN_00406f60(SpStr* dst, const char* fmt, ...);

struct FUN_007af520_cls
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
    Opt34* m_34;
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
    int unkD0;
    int unkD4;
    D8Obj* m_d8;
    void SyncListItemTemplate();
};

// @fnv 0x007af520
void FUN_007af520_cls::SyncListItemTemplate()
{
    bool e = m_34->FindByColor(7) != 0;
    bool d = m_d8->FUN_005f0cc0() == 0;
    if (d && !e)
    {
        SpStr s;
        FUN_00406f60(&s, "%s %c", DAT_011d23a0.FUN_00403df0(), 0x3e);
        m_34->FUN_007b3d50(2, s.FUN_00559450("RSM_list_item_template", 7));
    }
    else if (e && !d)
    {
        m_34->RemoveOptionById(7);
    }
}

namespace fnv_007af900 {
struct BSStringTChar
{
    char* data;
    unsigned short length;
    unsigned short capacity;
    BSStringTChar();
    ~BSStringTChar();
    operator const char*() const;
};
struct SettingT_GameSettingCollection_
{
    const char* String();
    int* Int();
};
struct GameSettingCollection
{
    static GameSettingCollection* Instance();
    bool GetSetting(const char*, SettingT_GameSettingCollection_**);
};
int __cdecl FUN_00406f60(BSStringTChar*, const char*, ...);
struct HairOption
{
    int FUN_00726070();
    int GetFloat1005();
    void FUN_007b3810(const char*);
};
struct HairOptionList
{
    HairOption* FindByColor(int);
};
struct GlobalObject_0040c150
{
    const char* String();
};
extern GlobalObject_0040c150 g_011d3528;
struct HairMenu
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
    HairOptionList* unk40;
    void ApplyHairOption(HairOption* option);
    void FUN_007afa40(int);
    void FUN_007b3660();
};
// @fnv 0x007af900
void HairMenu::ApplyHairOption(HairOption* option)
{
    if (!option)
        return;
    if (option->FUN_00726070() == 29)
    {
        SettingT_GameSettingCollection_* setting = 0;
        SettingT_GameSettingCollection_* valueSetting = 0;
        bool found;
        {
            BSStringTChar name;
            FUN_00406f60(&name, "iHairColor%02d", option->GetFloat1005());
            found = GameSettingCollection::Instance()->GetSetting(name, &valueSetting);
            FUN_00406f60(&name, "sHairColor%d", option->GetFloat1005());
            found = GameSettingCollection::Instance()->GetSetting(name, &setting);
            option->FUN_007b3810(setting->String());
            FUN_007afa40(*valueSetting->Int());
        }
    }
    else
    {
        unk40->FindByColor(29)->FUN_007b3810(g_011d3528.String());
    }
    FUN_007b3660();
}
}  // namespace fnv_007af900

struct FUN_007afa40_mgr
{
    void* FUN_00559450();
    void** FUN_0057cbe0(void** pp);
};
struct FUN_00726070_shell
{
    int FUN_00726070();
};
struct FUN_007afa40_cls
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    FUN_007afa40_mgr* m_40;
    void FUN_007afa40(unsigned int value);
};

// @fnv 0x007afa40
void FUN_007afa40_cls::FUN_007afa40(unsigned int uiPackedValue)
{
    void* cur = m_40->FUN_00559450();
    while (cur != 0)
    {
        void* item = *m_40->FUN_0057cbe0(&cur);
        switch (((FUN_00726070_shell*)item)->FUN_00726070())
        {
        case 0x1e:
            ((TileValueAccessor*)item)->FUN_007b3760((unsigned char)(uiPackedValue & 0xff));
            break;
        case 0x1f:
            ((TileValueAccessor*)item)->FUN_007b3760((unsigned char)((((unsigned short)uiPackedValue) >> 8) & 0xff));
            break;
        case 0x20:
            ((TileValueAccessor*)item)->FUN_007b3760((unsigned char)((uiPackedValue >> 16) & 0xff));
            break;
        }
    }
}

class B7B18F0Menu
{
  public:
    bool ClampSliderOptions(int iFrom, int iTo, bool bForward);
    void HandleMenuKey(int iKey);
};

// @fnv 0x007b18f0
void B7B18F0Menu::HandleMenuKey(int iKey)
{
    bool bOk = false;
    unsigned int uiCounter = 0;
    if (iKey == 0x22)
    {
        do
        {
            bOk = ClampSliderOptions(10, 0x13, false);
        } while (bOk && uiCounter++ < 3);
    }
    else if (iKey == 0x23)
    {
        do
        {
            bOk = ClampSliderOptions(0x13, 0x14, true);
        } while (bOk && uiCounter++ < 3);
    }
}

struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void DecomposeToEulerAngles(float&, float&, float&);
    void FUN_004a0c90(float);
    void SetMatrixElement(int, int, float);
    Matrix FUN_0043f8d0(const Matrix&) const;
};
extern Matrix DAT_011f4248;
struct SceneObject
{
    Matrix* FUN_006a9540();
    void FUN_0043fa80(const Matrix*);
};
struct ScenePointer
{
    SceneObject* FUN_00559450();
};
struct ScaleObject
{
    float GetWeight();
    float FUN_00944300();
};
struct Target
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
    ScenePointer scene;
    ScaleObject* scale;
    void UpdateShadowSceneNode();
    bool FUN_007b1970(float, bool);
};
// @fnv 0x007b1970
bool Target::FUN_007b1970(float offset, bool force)
{
    Matrix p = *scene.FUN_00559450()->FUN_006a9540();
    float s, a, i;
    p.DecomposeToEulerAngles(s, a, i);
    float h = i - offset;
    if (h < 0.0)
        h += 6.2831854820251465;
    else if (h > 6.2831854820251465)
        h -= 6.2831854820251465;
    if (i == h && !force)
        return false;
    p.FUN_004a0c90(h);
    Matrix f = DAT_011f4248;
    f.SetMatrixElement(0, 0, scale->GetWeight());
    f.SetMatrixElement(1, 1, scale->GetWeight());
    f.SetMatrixElement(2, 2, scale->FUN_00944300());
    p = p.FUN_0043f8d0(f);
    scene.FUN_00559450()->FUN_0043fa80(&p);
    UpdateShadowSceneNode();
    return true;
}

namespace fnv_007b2b50 {
struct StringB50
{
    char* text;
    unsigned short length, capacity;
    StringB50();
    ~StringB50();
};
struct FixedB50
{
    char* text;
    FixedB50(const char*);
    ~FixedB50();
    operator const char*() const;
};
struct ColorB50
{
    float r, g, b, a;
    ColorB50(float, float, float, float);
};
struct PropertyB50
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    ColorB50 color;
    int FUN_00441110();
};
struct PointB50
{
    float x, y, z;
    PointB50(float, bool, bool);
};
struct NodeB50
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual NodeB50* v01c();
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
    virtual NodeB50* v09c(const FixedB50&);
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
    virtual void v0e8(NodeB50*);
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
    PropertyB50* FUN_00a59d30(int);
    void FUN_00a5a040();
    unsigned FUN_0043b480();
    NodeB50* FUN_0043b4a0(unsigned);
    FixedB50& FUN_00413f40();
    void FUN_00a59c60(const PointB50&);
};
struct PtrB50
{
    NodeB50* ptr;
    PtrB50(NodeB50*);
    ~PtrB50();
    PtrB50& operator=(NodeB50*);
    operator NodeB50*() const;
};
struct SnapshotB50
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    unsigned unkdc;
    unsigned unke0;
    unsigned unke4;
    unsigned unke8;
    SnapshotB50();
    ~SnapshotB50();
};
struct BaseB50
{
    void UpdateFaceGenHairVisibility(void*, bool);
};
struct FaceB50
{
    void BuildAppearance(BaseB50*, SnapshotB50*, int, bool);
};
struct ObjectB50
{
    void FUN_00a6e960();
};
struct ControllerB50
{
    void* GetStringAtOffset();
};
struct AnimationB50
{
    ControllerB50* FUN_00496940();
};
struct PlayerB50
{
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
    virtual NodeB50* v1ac(bool);
    virtual NodeB50* v1b0(bool);
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
    virtual FaceB50* v37c();
    BaseB50* FUN_007af430();
    int FUN_0087f4c0();
    AnimationB50* FUN_00950a60(bool);
};
extern PlayerB50* pPlayer;
struct DataB50
{
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
    virtual void v048(int);
    unsigned FUN_004169d0();
    float FUN_00602130();
};
struct HostB50
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    DataB50* data;
    bool RebuildFaceGen(bool);
    void UpdateShadowSceneNode();
};
char* __cdecl FUN_00657820(char*, int);
void __cdecl BuildHairFaceGenNodes(NodeB50**, NodeB50**, SnapshotB50*, bool);
extern unsigned DAT_011f4a04;
ObjectB50* __cdecl FUN_00653270(unsigned*, void*);
void __cdecl FUN_00b57e30(NodeB50*, int, int);
unsigned __cdecl FUN_0044a670(const char*);
int __cdecl FUN_004564f0(const char*, const char*, unsigned);
void __cdecl FUN_00653470(NodeB50*, float);
// @fnv 0x007b2b50
bool HostB50::RebuildFaceGen(bool rebuild)
{
    int k = 0;
    PtrB50 e(0);
    PtrB50 eb(0);
    StringB50 c, f, cf, q, ba;

    NodeB50* b;

    AnimationB50* j;

    if (!pPlayer->v1ac(false))
        return false;
    data->v048(2048);
    if (rebuild)
    {
        char p[32];
        SnapshotB50 i;
        pPlayer->v37c()->BuildAppearance(pPlayer->FUN_007af430(), &i, pPlayer->FUN_0087f4c0(), false);
        NodeB50* h = pPlayer->v1ac(false);
        NodeB50* cf = pPlayer->v1b0(false);
        for (int i = 0; i < 2; i++)
        {
            NodeB50* part = h->v09c(FixedB50(FUN_00657820(p, i)));
            if (part)
                h->v0e8(part);
        }
        BuildHairFaceGenNodes(&h, &cf, &i, false);
        j = pPlayer->FUN_00950a60(false);
        void* a = j->FUN_00496940()->GetStringAtOffset();
        if (a)
        {
            ObjectB50* object = FUN_00653270(&DAT_011f4a04, a);
            if (object)
                object->FUN_00a6e960();
        }
        pPlayer->FUN_007af430()->UpdateFaceGenHairVisibility(pPlayer, false);
        for (int i = 0; i < 2; i++)
        {
            NodeB50* part = h->v09c(FixedB50(FUN_00657820(p, i)));
            if (part)
            {
                FUN_00b57e30(part, 0, 0);
                PropertyB50* color = part->FUN_00a59d30(3);
                PropertyB50* typed = (!color ? false : color->FUN_00441110() == 8) ? color : 0;
                unsigned property = data->FUN_004169d0();
                if (typed)
                    typed->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                            (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                            (unsigned char)((property >> 16) & 255) / 255.0, 1);
                else
                {
                    PropertyB50* otherTyped = (!color ? false : color->FUN_00441110() == 12) ? color : 0;
                    if (otherTyped)
                        otherTyped->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                                     (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                                     (unsigned char)((property >> 16) & 255) / 255.0, 1);
                }
            }
        }
        h->FUN_00a5a040();
    }
    else
    {
        unsigned count = pPlayer->v1ac(false)->FUN_0043b480();
        for (unsigned i = 0; i < count; i++)
        {
            b = pPlayer->v1ac(false)->FUN_0043b4a0(i);
            bool hair = b && !FUN_004564f0(b->FUN_00413f40(), "FaceGenHair", FUN_0044a670("FaceGenHair"));
            bool accessory =
                !hair && b && !FUN_004564f0(b->FUN_00413f40(), "FaceGenAccessory", FUN_0044a670("FaceGenAccessory"));
            if (hair || accessory)
            {
                eb = b->v01c();
                if ((NodeB50*)eb)
                {
                    if (hair)
                        FUN_00653470(eb, data->FUN_00602130());
                    PropertyB50* color = ((NodeB50*)eb)->FUN_00a59d30(3);
                    PropertyB50* typed = (!color ? false : color->FUN_00441110() == 8) ? color : 0;
                    if (typed)
                    {
                        unsigned property = data->FUN_004169d0();
                        typed->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                                (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                                (unsigned char)((property >> 16) & 255) / 255.0, 1);
                    }
                    else
                    {
                        PropertyB50* otherTyped = (!color ? false : color->FUN_00441110() == 12) ? color : 0;
                        if (otherTyped)
                        {
                            unsigned property = data->FUN_004169d0();
                            otherTyped->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                                         (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                                         (unsigned char)((property >> 16) & 255) / 255.0, 1);
                        }
                    }
                }
            }
        }
    }
    PointB50 l(0, false, false);
    pPlayer->v1ac(false)->FUN_00a59c60(l);
    UpdateShadowSceneNode();
    return true;
}
}  // namespace fnv_007b2b50

struct Trait
{
    int FUN_0084e3a0();
    void __thiscall FUN_00a0a270(float value, unsigned int update);
};
struct TileFor3760
{
    void __thiscall FUN_00700320(unsigned int id, int value);
    Trait* __thiscall FUN_00a00f30(unsigned int id);
};
struct MenuOptionFor3760
{
    TileFor3760* tile;
    int __thiscall GetFloat1005();
    void __thiscall FUN_007b3840(int& fTargetUpperBound, int& fMinimumInputValue);
    bool __thiscall FUN_007b3760(int value);
};

// Clamps value between the option's min and max, and if it differs from the current value, updates the tile and its trait, returning true.
// @fnv 0x007b3760
bool MenuOptionFor3760::FUN_007b3760(int value)
{
    if (tile != 0)
    {
        int currentValue = GetFloat1005();
        int fTargetUpperBound, fMinimumInputValue;
        FUN_007b3840(fTargetUpperBound, fMinimumInputValue);
        if (value < fTargetUpperBound)
            value = fTargetUpperBound;
        if (value > fMinimumInputValue)
            value = fMinimumInputValue;
        if (currentValue != value)
        {
            tile->FUN_00700320(0x1005, value);
            Trait* trait = tile->FUN_00a00f30(0x1009);
            if (trait->FUN_0084e3a0() == 0)
                trait->FUN_00a0a270((float)value, 1);
            return true;
        }
    }
    return false;
}

extern double DAT_01012070;

struct OptionValueReader
{
    TGF* m_iWordAt00;
    unsigned int ReadOptionValue();
};

// @fnv 0x007b3900
unsigned int OptionValueReader::ReadOptionValue()
{
    if (m_iWordAt00 != 0)
    {
        float f = m_iWordAt00->GetFloat(0x100a);
        return (f <= DAT_01012070) ? 1 : (unsigned int)f;
    }
    else
    {
        return 0;
    }
}

extern "C" void* DAT_011da634;
extern "C" const char str_01075b10[];
extern "C" const char str_01075b5c[];

struct FUN_0048f200
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0048f200();
    ~FUN_0048f200();
};

struct PropertyObject : Tile_Set_Helper
{
    void FUN_00a01350(int kind, int value, bool enabled);
    void FUN_00a04640(bool enabled);
};
struct InterfaceRoot
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
    void* unk78;
    PropertyObject* AddTileFromTemplate(void* parent, const char* name, int mode);
};
int __cdecl TraitNameToIDAdd(const char* name, int index);
struct FUN_007b39e0 : FUN_0048f200
{
    int unk0c;
    int unk10;
    PropertyObject* unk14;
    float unk18;
    int unk1c;
    int unk20;
    FUN_007b39e0(int low, int high);
};
// @fnv 0x007b39e0
FUN_007b39e0::FUN_007b39e0(int low, int high)
{
    unk10 = 20;
    unk0c = 20;
    unk18 = 0.0f;
    unk1c = 0;
    unk14 = ((InterfaceRoot*)DAT_011da634)->AddTileFromTemplate(((InterfaceRoot*)DAT_011da634)->unk78, str_01075b10, 0);
    unk14->Set(0x1004, low);
    unk14->FUN_00a01350(0xfc4, high, true);
    unk14->Set(0xfaf, 0);
    unk14->Set(TraitNameToIDAdd(str_01075b5c, -1), 1);
    unk14->FUN_00a04640(false);
    unk20 = 0;
}

struct S_007b3af0_Item
{
    virtual ~S_007b3af0_Item();
};
struct S_007b3af0_Base
{
    int unk00;
    ~S_007b3af0_Base();
};
struct FUN_007b3af0 : S_007b3af0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_007b3af0_Item* m_item;
    void FUN_007b45b0();
    ~FUN_007b3af0();
};
// Deletes m_item, clears it to null, then calls FUN_007b45b0.
// @fnv 0x007b3af0
FUN_007b3af0::~FUN_007b3af0()
{
    delete m_item;
    m_item = 0;
    FUN_007b45b0();
}

struct TempString_007b3bb0
{
    void* unk00;
    void* unk04;
    TempString_007b3bb0();
    ~TempString_007b3bb0();
    const char* FUN_00559450(const char* format, unsigned int value);
};
extern const char DAT_01075b28[];
extern const char DAT_01075b10[];
void __cdecl FUN_00406f60(TempString_007b3bb0* result, const char* format, const char* input, int limit);
struct SelectedOption_007b3bb0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int value0c;
    int unk10;
    TGF* pTGF;
};
struct Menu_007b3bb0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    TGF* pTGF;
    int CreateEntry(const char* text, int flags);
    int AddFloatOption(const char* input, SelectedOption_007b3bb0* selected);
};
// @fnv 0x007b3bb0
int Menu_007b3bb0::AddFloatOption(const char* input, SelectedOption_007b3bb0* selected)
{
    TempString_007b3bb0 text;
    FUN_00406f60(&text, DAT_01075b28, input, 0x3e);
    selected->value0c = (unsigned int)pTGF->GetFloat(0x1004);
    return CreateEntry(text.FUN_00559450(DAT_01075b10, (unsigned int)selected->pTGF->GetFloat(0x1004)), 0);
}

// RaceSex menu: add a slider option (range [iLow, iHigh], initial value) whose thumb width covers
// fSequenceTimeRatio of the range, at least one step.

class B3CA0Tile
{
  public:
    void Set(int eValue, float fValue, bool bPropagate);
};

class B3CA0SliderOption
{
  public:
    B3CA0Tile* m_pkTile;

    void SetRange(int iLow, int iHigh);
    void SetValue(int iValue);
};

float __cdecl B3CA0Max(float fA, float fB);

class B3CA0Menu
{
  public:
    B3CA0SliderOption* AddOption(int m_uiSoundID, const char* pcTemplate, int iParent, int iUnk);
    B3CA0SliderOption* FUN_007b3ca0(int m_uiSoundID, int iParent, int iLow, int iHigh, int iValue, float fSequenceTimeRatio);
};

// @fnv 0x007b3ca0
B3CA0SliderOption* B3CA0Menu::FUN_007b3ca0(int m_uiSoundID, int iParent, int iLow, int iHigh, int iValue, float afFraction)
{
    if (afFraction < 0.0)
        afFraction = 0.0f;
    if (afFraction > 1.0)
        afFraction = 1.0f;

    B3CA0SliderOption* pkOption = AddOption(m_uiSoundID, "RSM_slider_option_template", iParent, 0);
    pkOption->SetRange(iLow, iHigh);
    pkOption->SetValue(iValue);
    pkOption->m_pkTile->Set(0x1008, B3CA0Max((float)(iHigh - iLow + 1) * afFraction, 1.0f), true);
    return pkOption;
}

struct LocalTile
{
    virtual ~LocalTile();
    double FUN_00a011b0(int);
    LocalTile* GetParent();
    void Set(int, float, bool);
    void FUN_00a04640(bool);
};
struct Date
{
    LocalTile* tile;
    ~Date();
    int FUN_00726070();
};
int __cdecl TraitNameToIDAdd(const char*, int);
void __cdecl FUN_00706ff0(LocalTile*);
struct OptionList
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    Date* selected;
    operator void*() const;
    Date*& FUN_0057cbe0(void*&);
    Date*& AddEight(void*);
    Date*& FUN_007b5370();
    void FUN_0057c730(Date*&);
    void* GetSecondField(void*);
    void RemoveOptionById(int id);
};
// Removes the option whose id matches, updates selected, then repositions remaining options using the _top_bound value.
// @fnv 0x007b3dd0
void OptionList::RemoveOptionById(int id)
{
    void* pos = *this;
    while (pos)
    {
        Date* option = FUN_0057cbe0(pos);
        if (option->FUN_00726070() == id)
        {
            if (selected == option)
            {
                selected = pos ? AddEight(pos) : FUN_007b5370();
                FUN_00706ff0(selected->tile);
            }
            delete option->tile;
            delete option;
            FUN_0057c730(option);
            break;
        }
    }
    while (pos)
    {
        void* prev = GetSecondField(pos);
        Date* current = prev ? AddEight(prev) : 0;
        Date* before = FUN_0057cbe0(pos);
        before->tile->Set(0xfa2,
                          current ? current->tile->FUN_00a011b0(0xfa2) + current->tile->FUN_00a011b0(0xfb0)
                                  : before->tile->GetParent()->FUN_00a011b0(TraitNameToIDAdd("_top_bound", -1)),
                          true);
        before->tile->FUN_00a04640(false);
    }
}

struct FUN_007b4050_shell
{
    int unknown00, unknown04, unknown08, currentValue, previousValue;
    TGF* control;
    void CopyControlValues(FUN_007b4050_shell* other);
};
// Reads control's float at 0x1004 into other->currentValue and other->control's float at 0x1004 into previousValue.
// @fnv 0x007b4050
void FUN_007b4050_shell::CopyControlValues(FUN_007b4050_shell* other)
{
    previousValue = (unsigned int)other->control->GetFloat(0x1004);
    other->currentValue = (unsigned int)control->GetFloat(0x1004);
}

struct TileList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* GetHeadPos() const;
    Tile*& GetNext(void*& pos);
};
struct S_007b40d0_Owner : TileList
{
    bool(__cdecl* m1c)(Tile* item);
    void ApplyToAllTiles();
};
// If m1c is set, walks the tile list and calls SetTileValue on items where m1c returns true, otherwise SetSelected.
// @fnv 0x007b40d0
void S_007b40d0_Owner::ApplyToAllTiles()
{
    if (m1c)
    {
        void* pos = GetHeadPos();
        while (pos)
        {
            Tile* item = GetNext(pos);
            if (m1c(item))
                ((FUN_007b4140_shell*)item)->SetTileValue();
            else
                ((FUN_007b4180_shell*)item)->SetSelected();
        }
    }
}

struct Item
{
    virtual ~Item();
};

struct NodeT
{
    Item* m_item;
    ~NodeT();
};

struct FUN_007b45b0_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;

    void* FUN_00559450();
    NodeT*& FUN_0057cbe0(void*& it);
    void FUN_004ed900();
    void FUN_007b45b0();
};

// Iterates the list from FUN_00559450, deleting each node's m_item and the node, then calls FUN_004ed900 and clears m_20.
// @fnv 0x007b45b0
void FUN_007b45b0_shell::FUN_007b45b0()
{
    void* it = FUN_00559450();
    while (it != 0)
    {
        NodeT* node = FUN_0057cbe0(it);
        delete node->m_item;
        delete node;
    }
    FUN_004ed900();
    m_20 = 0;
}

// Race/sex menu initialization.
class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
class TESNPC : public TESBoundObject
{
  public:
    int FUN_005f0cc0();
    unsigned int FUN_004169d0();
};
struct InitPlayer
{
    TESBoundObject* FUN_007af430();
};
extern InitPlayer* DAT_011dea3c;
struct BSStringTChar
{
    void* data;
    unsigned short length, capacity;
    BSStringTChar();
    ~BSStringTChar();
    void FUN_004037f0(const char*, int);
    const char* FUN_00559450();
    void FUN_004afad0();
};
struct InitSetting
{
    const char* FUN_00403df0();
    const char* FUN_004c69f0();
    float* FUN_00403e20();
};
struct InitTile
{
    double FUN_00a011b0(int);
    void FUN_00a012d0(int, float);
    void FUN_00a01350(int, const char*, bool);
};
struct InitItem
{
    void FUN_00403550(void*);
    void FUN_007b3810(const char*);
};
struct InitOptions
{
    void FUN_0050f9a0(void*);
    InitItem* FUN_007b3b80(const char*, int);
    InitItem* FUN_007b3ca0(const char*, int, int, int, int, float);
    void AddFloatOption(const char*, InitOptions*);
    void FUN_0041fd00(int);
    void CopyControlValues(InitOptions*);
    void ApplyToAllTiles();
};
struct InitForm
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    struct Name
    {
        const char* FUN_00408da0();
    } name;
    bool FUN_0059f610();
    bool FUN_005e7a60();
};
struct InitNode
{
    InitForm** FUN_006815c0();
    InitNode* FUN_00726070();
};
struct InitData
{
    InitNode* FUN_004ea950();
    InitNode* FUN_00624700();
};

struct InitString
{
    const char* FUN_00559450();
};
extern InitString DAT_011da6f4;
struct InitSub
{
    int unk00, unk04, unk08;
    void Play(int);
};
struct InitManager
{
    void FUN_00718630(int, void*, int);
};
struct InitRootManager
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
    InitManager messages;
};
float __stdcall FUN_00a01530(int);
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);
void __cdecl FUN_00406f60(BSStringTChar*, const char*, ...);
char __cdecl IsHairMatching(int);
extern InitSetting DAT_011d1f38;
extern InitSetting DAT_011d20dc;
extern InitSetting DAT_011d2058;
extern InitSetting DAT_011d43d8;
extern InitSetting DAT_011d36e4;
extern InitSetting DAT_011d22d4;
extern InitSetting DAT_011d4a74;

extern InitSetting DAT_011d31c8;
extern InitSetting DAT_011d26d0;
extern InitSetting DAT_011d3eb0;
extern InitSetting DAT_011d4480;
extern InitSetting DAT_011d4318;
extern InitSetting DAT_011d3084;
extern InitSetting DAT_011d4d20;
extern InitSetting DAT_011d4180;
extern InitSetting DAT_011d3078;
extern InitSetting DAT_011d50e0;
extern InitSetting DAT_011d3618;
extern InitSetting DAT_011d2250;
extern InitSetting DAT_011d37ec;
extern InitSetting DAT_011d2d3c;
extern InitSetting DAT_011d3ff4;
extern InitSetting DAT_011d3d48;
extern InitSetting DAT_011d4084;
extern InitSetting DAT_011d3528;
extern InitSetting DAT_011d2a84;
extern InitSetting DAT_011d25a4;
extern InitSetting DAT_011d2d48;
extern InitSetting DAT_011d454c;
extern InitSetting DAT_011d4108;
extern InitSetting DAT_011da6cc;
extern const char DAT_01063ab4[];
extern const char DAT_010692d0[];
extern const char DAT_01075ae4[];
extern const char DAT_01075adc[];
extern const char DAT_01075ad4[];
extern const char DAT_01075acc[];
extern const char DAT_01020770[];
extern const char DAT_01075aac[];
extern const char DAT_01075a74[];
extern const char DAT_01075a4c[];
extern const char DAT_01074e34[];
struct InitRaceMenu
{
    int unk000;
    InitTile* tile;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    FUN_007b39e0* options[20];
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    InitTile* display;
    int unk08c;
    BSStringTChar title;
    BSStringTChar question;
    float valuea0;
    float valuea4;
    float valuea8;
    float valueac;
    float valueb0;
    float valueb4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    float valuec8;
    int unk0cc;
    float valued0;
    int unk0d4;
    TESNPC* npc;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    InitSub sub0;
    InitSub sub1;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    InitTile* FUN_00726070();
    void BuildMorphOptions();
    void UpdateHairMenuOption();
    bool FUN_007af180(int);
    void FUN_00a1dc20(int);
    void SetupRaceMenu(int mode);
};
// @fnv 0x007acb60
void InitRaceMenu::SetupRaceMenu(int mode)
{
    const char* names[20];
    if (tile->FUN_00a011b0(0xfa7) == 6006.0 || tile->FUN_00a011b0(0xfa7) == 102.0)
        tile->FUN_00a012d0(0xfad, FUN_00a01530(1));
    ((InitRootManager*)FUN_004b7210())->messages.FUN_00718630(15, (void*)FUN_007ac9c0(), 0x200);
    FUN_00726070()->FUN_00a01350(0x1005, DAT_01063ab4, true);
    FUN_00726070()->FUN_00a01350(0x1006, DAT_010692d0, true);
    npc = dynamic_cast<TESNPC*>(DAT_011dea3c->FUN_007af430());
    display->FUN_00a01350(0xfc4, DAT_011da6f4.FUN_00559450(), true);
    {
        BSStringTChar aLabelStrings[4];
        {
            int page;
            {
                unsigned int color;
                {
                    InitItem* slider;
                    {
                        switch (mode)
                        {
                        case 2:
                        case 3:
                            aLabelStrings[0].FUN_004037f0(DAT_011d1f38.FUN_00403df0(), 0);
                            aLabelStrings[1].FUN_004037f0(DAT_011d20dc.FUN_00403df0(), 0);
                            aLabelStrings[2].FUN_004037f0(DAT_011d2058.FUN_00403df0(), 0);
                            aLabelStrings[3].FUN_004037f0(DAT_011d43d8.FUN_00403df0(), 0);
                            break;
                        default:
                            FUN_00406f60(&aLabelStrings[0], DAT_01075ae4, DAT_011d1f38.FUN_00403df0());
                            FUN_00406f60(&aLabelStrings[1], DAT_01075adc, DAT_011d20dc.FUN_00403df0());
                            FUN_00406f60(&aLabelStrings[2], DAT_01075ad4, DAT_011d2058.FUN_00403df0());
                            FUN_00406f60(&aLabelStrings[3], DAT_01075acc, DAT_011d43d8.FUN_00403df0());
                            break;
                        }
                        names[0] = aLabelStrings[0].FUN_00559450();
                        names[1] = aLabelStrings[1].FUN_00559450();
                        names[2] = aLabelStrings[2].FUN_00559450();
                        names[3] = aLabelStrings[3].FUN_00559450();
                        names[4] = DAT_011d36e4.FUN_00403df0();
                        names[5] = DAT_011d22d4.FUN_00403df0();
                        names[6] = DAT_011d4a74.FUN_00403df0();
                        names[7] = DAT_011d23a0.FUN_00403df0();
                        names[8] = DAT_011d31c8.FUN_00403df0();
                        names[9] = DAT_011d26d0.FUN_00403df0();
                        names[10] = DAT_011d3eb0.FUN_00403df0();
                        names[11] = DAT_011d4480.FUN_00403df0();
                        names[12] = DAT_011d4318.FUN_00403df0();
                        names[13] = DAT_011d3084.FUN_00403df0();
                        names[14] = DAT_011d4d20.FUN_00403df0();
                        names[15] = DAT_011d4180.FUN_00403df0();
                        names[16] = DAT_011d3078.FUN_00403df0();
                        names[17] = DAT_011d50e0.FUN_00403df0();
                        names[18] = DAT_011d3618.FUN_00403df0();
                        names[19] = DAT_011d2250.FUN_00403df0();
                        for (int i = 0; i < 20; i++)
                        {
                            options[i] = new FUN_007b39e0(i, (int)names[i]);
                        }
                        ((InitOptions*)options[0])->FUN_0050f9a0((void*)FUN_007ad940);
                        ((InitOptions*)options[1])->FUN_0050f9a0((void*)IsHairMatching);
                        ((InitOptions*)options[5])->FUN_0050f9a0((void*)(unsigned char(__cdecl*)(Obj0*))FUN_007ad860);
                        ((InitOptions*)options[8])->FUN_0050f9a0((void*)IsAnimationMatch);
                        ((InitOptions*)options[7])->FUN_0050f9a0((void*)IsArgValueInSubLookup);
                        ((InitOptions*)options[0])->FUN_007b3b80(DAT_011d37ec.FUN_004c69f0(), 21);
                        ((InitOptions*)options[0])->FUN_007b3b80(DAT_011d2d3c.FUN_004c69f0(), 22);
                        for (InitNode* pRaceNode = ((InitData*)DAT_011c3f2c)->FUN_004ea950();
                             pRaceNode && *pRaceNode->FUN_006815c0(); pRaceNode = pRaceNode->FUN_00726070())
                        {
                            if ((*pRaceNode->FUN_006815c0())->FUN_0059f610())
                                ((InitOptions*)options[1])
                                    ->FUN_007b3b80((*pRaceNode->FUN_006815c0())->name.FUN_00408da0(), 23)
                                    ->FUN_00403550(*pRaceNode->FUN_006815c0());
                        }
                        ((InitOptions*)options[2])
                            ->FUN_007b3ca0(DAT_011d3ff4.FUN_004c69f0(), 24, 1, 20, 0x80000001, 0.25f);
                        ((InitOptions*)options[2])
                            ->AddFloatOption(DAT_011d36e4.FUN_004c69f0(), ((InitOptions*)options[4]));
                        ((InitOptions*)options[2])->FUN_007b3b80(DAT_011d3d48.FUN_004c69f0(), 25);
                        slider = ((InitOptions*)options[2])
                                     ->FUN_007b3ca0(DAT_011d4084.FUN_004c69f0(), 26, 1, 10, 0x80000001, 0.25f);
                        slider->FUN_007b3810(DAT_01020770);
                        ((InitOptions*)options[3])
                            ->AddFloatOption(DAT_011d22d4.FUN_004c69f0(), ((InitOptions*)options[5]));
                        ((InitOptions*)options[3])
                            ->AddFloatOption(DAT_011d4a74.FUN_004c69f0(), ((InitOptions*)options[6]));
                        if (!npc->FUN_005f0cc0())
                            ((InitOptions*)options[3])
                                ->AddFloatOption(((InitSetting*)&DAT_011d23a0)->FUN_004c69f0(),
                                                 ((InitOptions*)options[7]));
                        else
                            ((InitOptions*)options[7])->FUN_0041fd00(3);
                        ((InitOptions*)options[4])
                            ->AddFloatOption(DAT_011d26d0.FUN_004c69f0(), ((InitOptions*)options[9]));
                        ((InitOptions*)options[4])
                            ->AddFloatOption(DAT_011d2250.FUN_004c69f0(), ((InitOptions*)options[19]));
                        ((InitOptions*)options[4])
                            ->AddFloatOption(DAT_011d31c8.FUN_004c69f0(), ((InitOptions*)options[8]));
                        color = npc->FUN_004169d0();
                        ((InitOptions*)options[6])
                            ->FUN_007b3ca0(DAT_011d3ff4.FUN_004c69f0(), 29, 0, 15, 0x80000001, 0.25f)
                            ->FUN_007b3810(DAT_011d3528.FUN_00403df0());
                        ((InitOptions*)options[6])
                            ->FUN_007b3ca0(DAT_011d2a84.FUN_004c69f0(), 30, 0, 255, (unsigned char)(color & 255),
                                           0.125f);
                        ((InitOptions*)options[6])
                            ->FUN_007b3ca0(DAT_011d25a4.FUN_004c69f0(), 31, 0, 255,
                                           (unsigned char)(((unsigned short)color >> 8) & 255), 0.125f);
                        ((InitOptions*)options[6])
                            ->FUN_007b3ca0(DAT_011d2d48.FUN_004c69f0(), 32, 0, 255,
                                           (unsigned char)((color >> 16) & 255), 0.125f);
                        for (InitNode* pBeardNode = ((InitData*)DAT_011c3f2c)->FUN_00624700();
                             pBeardNode && *pBeardNode->FUN_006815c0(); pBeardNode = pBeardNode->FUN_00726070())
                        {
                            if ((*pBeardNode->FUN_006815c0())->FUN_005e7a60())
                                ((InitOptions*)options[7])
                                    ->FUN_007b3b80((*pBeardNode->FUN_006815c0())->name.FUN_00408da0(), 28)
                                    ->FUN_00403550(*pBeardNode->FUN_006815c0());
                        }
                        for (int j = 10; j < 19; j++)
                            ((InitOptions*)options[9])->AddFloatOption(names[j], ((InitOptions*)options[j]));
                        BuildMorphOptions();
                        BSStringTChar doneLabel;
                        switch (mode)
                        {
                        case 2:
                            title.FUN_004037f0(DAT_01075aac, 0);
                            doneLabel.FUN_004037f0(DAT_011d43d8.FUN_00403df0(), 0);
                            page = 3;
                            unk120 = page;
                            valuea0 = -7.4f;
                            valuea4 = 80.0f;
                            valuea8 = -0.84f;
                            valueac = -12.4f;
                            valueb0 = 135.0f;
                            valueb4 = -0.8f;
                            break;
                        case 3:
                            title.FUN_004037f0(DAT_01075a74, 0);
                            doneLabel.FUN_004037f0(DAT_011d2058.FUN_00403df0(), 0);
                            page = 2;
                            unk120 = page;
                            valuea0 = -5.2f;
                            valuea4 = 55.0f;
                            valuea8 = -0.84f;
                            valueac = -12.4f;
                            valueb0 = 135.0f;
                            valueb4 = -0.77f;
                            UpdateHairMenuOption();
                            break;
                        default:
                            title.FUN_004037f0(DAT_01075a4c, 0);
                            doneLabel.FUN_004037f0(DAT_011d454c.FUN_00403df0(), 0);
                            ((InitOptions*)options[0])->CopyControlValues(((InitOptions*)options[1]));
                            ((InitOptions*)options[1])->CopyControlValues(((InitOptions*)options[2]));
                            ((InitOptions*)options[2])->CopyControlValues(((InitOptions*)options[3]));
                            unk120 = 3;
                            page = 0;
                            valuea0 = -4.7f;
                            valuea4 = 55.0f;
                            valuea8 = -0.84f;
                            valueac = -11.4f;
                            valueb0 = 135.0f;
                            valueb4 = -0.8f;
                            UpdateHairMenuOption();
                            break;
                        }
                        if (FUN_004b7220() != 1)
                            doneLabel.FUN_004afad0();
                        FUN_00406f60(&question, DAT_01074e34, DAT_011d4108.FUN_00403df0(), doneLabel.FUN_00559450());
                        valued0 = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, *DAT_011da6cc.FUN_00403e20()));
                        valuec8 = valued0;
                        ((InitOptions*)options[0])->ApplyToAllTiles();
                        ((InitOptions*)options[1])->ApplyToAllTiles();
                        ((InitOptions*)options[7])->ApplyToAllTiles();
                        sub0.Play(0);
                        sub1.Play(0);
                        FUN_007af180(page);
                        FUN_00a1dc20(0);
                    }
                }
            }
        }
    }
}

struct Tile7
{
    float GetValue(int aiID);
    Tile7* GetChild(int aiID);
    Tile7* GetParent();
};
struct MenuOption7
{
    void FUN_007b3840(int& aiLow, int& aiHigh);
    bool FUN_007b3760(int aiValue);
};
struct OptionList7
{
    MenuOption7* FUN_007b41c0(Tile7* apTile);
};
struct IM7
{
    float FUN_007697f0();
};
IM7* GetInterfaceMgr7();
float __cdecl FUN_004bd510(float a, float b);

struct RaceSexMenu7
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
    OptionList7* optionLists[5];
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
    Tile7* tile7c;
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
    float fLastTime;
    int iBase;
    Tile7* pActiveTile;
    MenuOption7* pActiveOption;
    int GetCurrentPage();
    void HandleOptionSelection();
    bool FUN_007b1970(float afAngle, int a2);
    void FUN_007adc60(int aiID, bool abVal);
    void FUN_007ae240(int aiID, Tile7* apTile);
};

// @fnv 0x007ae240
void RaceSexMenu7::FUN_007ae240(int aiID, Tile7* apTile)
{
    float fDelta2 = GetInterfaceMgr7()->FUN_007697f0() - fLastTime;
    if (fDelta2 != 0.0)
    {
        if (aiID == 0x69 && apTile)
        {
            int iPage = GetCurrentPage();
            MenuOption7* pOption = optionLists[iPage]->FUN_007b41c0(apTile->GetParent());
            if (pOption)
            {
                int iLow6;
                int iHigh;
                pOption->FUN_007b3840(iLow6, iHigh);
                float fRatio = fDelta2 / apTile->GetParent()->GetChild(0x65)->GetValue(0xfb1);
                if (pOption->FUN_007b3760(FUN_004bd510(iBase + (iHigh - iLow6) * fRatio, 1.0f)))
                {
                    pActiveOption = pOption;
                    pActiveTile = apTile;
                    HandleOptionSelection();
                }
            }
        }
        else if (aiID == 1)
        {
            static float sfWidth = tile7c->GetValue(0xfb1);
            FUN_007adc60(5, FUN_007b1970(fDelta2 / sfWidth * 6.2831854820251465, 0));
            fLastTime = GetInterfaceMgr7()->FUN_007697f0();
        }
    }
}

namespace AppearanceInput {
struct Sound
{
    unsigned int unk0, unk4, unk8;
    int FUN_0044ddc0();
    void Play(int);
    bool FUN_00ad8930();
    void FUN_00ad88f0();
    void FUN_00ad88b0();
};
struct Input
{
    int GetAxisState(int, int);
    int FUN_00a23a50(int, int);
};
struct OS
{
    Input* FUN_00877720();
};
extern OS* DAT_011dea0c;
struct Interface
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
    unsigned int unk3c;
    unsigned int unk40;
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
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    void* selected;
    int FUN_0070ec70();
};
Interface* FUN_004b7210();
bool FUN_004b71d0();
unsigned int FUN_00457fe0();
bool FUN_00702450(int);
int FUN_0072fa60(int);
int MinInt(int, int);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
extern int DAT_011a07b0, DAT_011a07ac;
extern double DAT_01075af8, DAT_01075af0, DAT_01017b70, DAT_01012060;
extern float DAT_01075aec, DAT_0105559c;
struct Menu
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void Select(int, int);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual int Id();
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
    unsigned int unk3c;
    unsigned int unk40;
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
    void* zoomTile;
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
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    int dragX, dragY;
    float desired, velocity, current;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    Sound sounds[4];
    void FUN_007adc60(int, bool);
    bool FUN_007adc30(int);
    bool UpdateProgress(float, int);
    bool FUN_007b1970(float, int);
    void HandleOptionSelection();
    void HandlePendingTileAction();
    void UpdateZoomAndScroll();
};
// Per frame, while the menu is active, drives zoom/scroll velocity from input and plays or stops the four sounds based on state.
// @fnv 0x007ae420
void Menu::UpdateZoomAndScroll()
{
    if (FUN_00702450(Id()))
    {
        for (unsigned int i = 0; i < 4; i++)
            if (sounds[i].FUN_0044ddc0() == 3)
                sounds[i].Play(0);
        static unsigned int previous = FUN_00457fe0();
        unsigned int time = FUN_00457fe0();
        if (FUN_004b71d0())
        {
            int horizontalSlot1 = 0;
            int verticalSlot17 = 0;
            horizontalSlot1 = DAT_011dea0c->FUN_00877720()->GetAxisState(0, 9);
            verticalSlot17 = DAT_011dea0c->FUN_00877720()->GetAxisState(0, 10);
            int absXSlot10 = FUN_0072fa60(horizontalSlot1);
            int absYSlot39 = FUN_0072fa60(verticalSlot17);
            FUN_007adc60(5, 0);
            FUN_007adc60(6, 0);
            if (absYSlot39 > 8689 && absYSlot39 > absXSlot10)
            {
                int span = DAT_011a07b0 - 8689;
                int amountSlot0 = span - (DAT_011a07b0 - MinInt(absYSlot39, DAT_011a07b0));
                velocity += amountSlot0 * DAT_01075af8 / span * (time - previous);
                FUN_007adc60(
                    6, UpdateProgress((verticalSlot17 > DAT_01012060 ? -1 : 1) * velocity * (time - previous), 0));
            }
            else
            {
                if (absXSlot10 > 8689 && absXSlot10 > absYSlot39)
                {
                    float ratio = horizontalSlot1 > 0 ? (float)(horizontalSlot1 - 8689) / (DAT_011a07b0 - 8689)
                                                      : (float)(-horizontalSlot1 - 8689) / (DAT_011a07ac + 8689);
                    FUN_007adc60(5, FUN_007b1970(ratio * DAT_01075af0 * (time - previous) / DAT_01017b70, 0));
                }
                velocity = 0.0f;
            }
            if (FUN_007adc30(5) && !sounds[3].FUN_00ad8930())
                sounds[3].Play(0);
            else if (!FUN_007adc30(5) && sounds[3].FUN_00ad8930())
                sounds[3].FUN_00ad88f0();
            if (FUN_007adc30(6) && !sounds[2].FUN_00ad8930())
                sounds[2].Play(0);
            else if (!FUN_007adc30(6) && sounds[2].FUN_00ad8930())
                sounds[2].FUN_00ad88f0();
            if (dragY && FUN_007adc30(4))
            {
                HandleOptionSelection();
                dragY = 0;
                dragX = 0;
            }
        }
        else
        {
            FUN_007adc60(6, 0);
            if (FUN_004b7210()->FUN_0070ec70() && FUN_004b7210()->selected)
            {
                bool up = FUN_004b7210()->FUN_0070ec70() > DAT_01012060;
                if (FUN_004b7210()->selected == zoomTile)
                {
                    desired += up ? DAT_01075aec : DAT_0105559c;
                    desired = FUN_00404010(FUN_0040ebd0(desired, 1.0f), 0.0f);
                }
                else
                {
                    if (up)
                        Select(2, 0);
                    else
                        Select(3, 0);
                }
            }
            if (current < desired)
            {
                velocity += (time - previous) * DAT_01075af8;
                float increase = (time - previous) * velocity;
                if (desired < current + increase)
                    increase = desired - current;
                FUN_007adc60(6, UpdateProgress(increase, 0));
            }
            else if (current > desired)
            {
                velocity -= (time - previous) * DAT_01075af8;
                float decrease = (time - previous) * velocity;
                if (desired > current + decrease)
                    decrease = desired - current;
                FUN_007adc60(6, UpdateProgress(decrease, 0));
            }
            else
                velocity = 0.0f;
            if (FUN_007adc30(6) && !sounds[2].FUN_00ad8930())
                sounds[2].Play(0);
            else if (!FUN_007adc30(6) && sounds[2].FUN_00ad8930())
                sounds[2].FUN_00ad88f0();
            if (FUN_007adc30(5) && !sounds[3].FUN_00ad8930())
                sounds[3].Play(0);
            else if (!FUN_007adc30(5) && sounds[3].FUN_00ad8930())
                sounds[3].FUN_00ad88f0();
            FUN_007adc60(5, 0);
            if (dragY && DAT_011dea0c->FUN_00877720() && DAT_011dea0c->FUN_00877720()->FUN_00a23a50(0, 2))
                HandlePendingTileAction();
        }
        previous = time;
    }
    else
    {
        for (unsigned int j = 0; j < 4; j++)
            if (sounds[j].FUN_0044ddc0() == 1)
                sounds[j].FUN_00ad88b0();
    }
}
}

struct Tile67
{
    Tile67* FUN_0045cd60();
    bool IsAllChildrenFlag0();
    Tile67* FUN_00a03eb0(int);
};
struct Option67
{
    int FUN_0084e3a0();
    int FUN_0044edb0();
    bool FUN_007b4260(int);
    void SetFocus(int);
};
struct Sound67
{
    int unk00, unk04, unk08;
    ~Sound67();
    void Play();
};
struct Audio67
{
    Sound67 FUN_00ad7550(const char*, int, int);
};
Audio67* FUN_00453a70();
struct Value67
{
    int GetAxisState();
};
struct Input67
{
    Value67* FUN_00877720(int, int);
};
struct Interface67
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
    Tile67* focused;
    Tile67* GetFieldBC();
};
struct Setting67
{
    const char* FUN_00403df0();
};
struct String67
{
    const char* FUN_00559450();
};
extern Input67* DAT_011dea0c;
extern Setting67 DAT_011d34f8, DAT_011d3684;
extern char DAT_0106f380[], DAT_01075b00[];
bool FUN_00702450(int);
int FUN_0072fa60(int);
bool FUN_004b71d0();
void FUN_00706ff0(Tile67*);
void UpdateRaceSexMenu();
void ShowMessageBox(const char*, int, int, void (*)(), int, int, float, float, const char*, const char*, int);
struct Menu67
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Activate(int, Tile67*);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int Id();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Option67* options[20];
    Tile67* parent;
    int unk7c, unk80, unk84;
    Tile67* left;
    Tile67* right;
    int unk90, unk94;
    String67 message;
    void FUN_007adc60(int, bool);
    int FUN_007dcc00();
    bool FUN_007af180(int);
    bool HandleAction(int, int);
};
// @fnv 0x007aecb0
bool Menu67::HandleAction(int action, int argument)
{
    if (FUN_00702450(Id()))
    {
        if (action >= 0)
        {
            int key = DAT_011dea0c->FUN_00877720(0, 7)->GetAxisState();
            FUN_007adc60(4, action != 4 && action != 3 && FUN_0072fa60(key) < 0x1ea9);
        }
        switch (action)
        {
        case 10:
            if (FUN_007af180(options[FUN_007dcc00()]->FUN_0084e3a0()))
                FUN_00453a70()->FUN_00ad7550(DAT_0106f380, 0x121, 0).Play();
            return true;
        case 13:
        case 14: {
            int iOptionIndex = FUN_007dcc00();
            while (iOptionIndex >= 4)
                iOptionIndex = options[iOptionIndex]->FUN_0084e3a0();
            bool bChanged = action == 13 ? FUN_007af180(options[iOptionIndex]->FUN_0084e3a0())
                                         : FUN_007af180(options[iOptionIndex]->FUN_0044edb0());
            if (bChanged)
                FUN_00453a70()->FUN_00ad7550(DAT_01075b00, 0x121, 0).Play();
            else if (action == 14)
                ShowMessageBox(message.FUN_00559450(), 0, 0, UpdateRaceSexMenu, 1, 0x12, 0.0f, 0.0f,
                             DAT_011d3684.FUN_00403df0(), DAT_011d34f8.FUN_00403df0(), 0);
            return true;
        }
        case 3:
        case 4:
        case 15:
        case 16: {
            Tile67* tile = ((Interface67*)FUN_004b7210())->GetFieldBC();
            if (!tile && !FUN_004b71d0())
            {
                tile = ((Interface67*)FUN_004b7210())->focused;
                while (tile && tile->FUN_0045cd60() != parent)
                    tile = tile->FUN_0045cd60();
            }
            if (tile == left && action == 3 && right->IsAllChildrenFlag0())
            {
                FUN_00706ff0(right);
                return true;
            }
            else if (tile == right && action == 4 && left->IsAllChildrenFlag0())
            {
                FUN_00706ff0(left);
                return true;
            }
            else if (tile)
            {
                int trait7;
                if (action == 15)
                    trait7 = 0x66;
                else if (action == 16)
                    trait7 = 0x67;
                else if (action == 3)
                    trait7 = 0x68;
                else if (action == 4)
                    trait7 = 0x64;
                else
                    return false;
                Tile67* pDestination = tile->FUN_00a03eb0(trait7);
                if (pDestination)
                {
                    Activate(trait7, pDestination);
                    return true;
                }
            }
        }
        case 1:
            return options[FUN_007dcc00()]->FUN_007b4260(action);
        case 2:
            if (((Interface67*)FUN_004b7210())->GetFieldBC() == left ||
                ((Interface67*)FUN_004b7210())->GetFieldBC() == right || options[FUN_007dcc00()]->FUN_007b4260(action))
                return true;
            else if (left->IsAllChildrenFlag0())
            {
                options[FUN_007dcc00()]->SetFocus(0);
                FUN_00706ff0(left);
                return true;
            }
            else if (right->IsAllChildrenFlag0())
            {
                options[FUN_007dcc00()]->SetFocus(0);
                FUN_00706ff0(right);
                return true;
            }
            break;
        }
    }
    return false;
}

struct StatsMenuItem
{
    int GetPosition();
};
struct StatsMenuItemList
{
    StatsMenuItem* FUN_00559450();
    StatsMenuItem** FUN_0057cbe0(StatsMenuItem*& p);
};
struct StatsMenuTile
{
    void FUN_00700320(int, int);
};
extern void __cdecl FUN_00a04200(int);
class StatsMenu
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    StatsMenuItemList* m_pageLists[2];
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    StatsMenuTile* m_minusTile;
    StatsMenuTile* m_plusTile;
    int FUN_007dcc00();
    void UpdateMinusPlusTiles();
};
// Scans the current page's items for entries returning -1 or 1 and toggles the minus and plus tiles accordingly.
// @fnv 0x007af6b0
void StatsMenu::UpdateMinusPlusTiles()
{
    StatsMenuItem* pos;
    StatsMenuItemList* pOwner = m_pageLists[FUN_007dcc00()];
    pos = pOwner->FUN_00559450();
    bool foundPlus;
    {
        bool foundMinus = false;
        foundPlus = false;
        FUN_00a04200(0);
        while (pos && (!foundMinus || !foundPlus))
        {
            switch ((*pOwner->FUN_0057cbe0(pos))->GetPosition())
            {
            case -1:
                foundMinus = true;
                break;
            case 1:
                foundPlus = true;
                break;
            }
        }
        m_minusTile->FUN_00700320(0xFA3, foundMinus);
        m_plusTile->FUN_00700320(0xFA3, foundPlus);
    }
}

struct B10355_Elem
{
    B10355_Elem();
    ~B10355_Elem();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
};

struct B10355_Obj2
{
    int Calc();
};

struct B10355_Node
{
    B10355_Obj2* Get();
};

struct B10355_Holder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    B10355_Node m10c;
    void U1(void* p);
    int U2(int a);
    int U3();
};

struct B10355_Param
{
    int M1();
    int M2();
    int M3();
};

void __cdecl B10355_Ext1(void* arr, int flag, int zero, int a, float f);
void __cdecl B10355_Ext2(int a, int b, void* c, int d);

struct FUN_007af770_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    B10355_Holder* m_d8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    int unk124;
    void M4(int a, bool b);
    void ApplyParam(B10355_Param* p);
};

// @fnv 0x007af770
void FUN_007af770_cls::ApplyParam(B10355_Param* apParam)
{
    B10355_Elem arr[4];
    m_d8->U1(arr);
    float F = apParam->M1() / 10.0;
    B10355_Ext1(arr, apParam->M3() != 0x22, 0, apParam->M2(), F);
    m_d8->U1((void*)&unk124);
    B10355_Ext2(m_d8->m10c.Get()->Calc(), m_d8->U3(), arr, m_d8->U2(0));
    M4(8, true);
    if (apParam->M3() == 0x23)
    {
        M4(9, true);
    }
}

struct FaceMorphDescriptor
{
    int group;
    const char* name;
    float minimum, maximum;
};
struct MorphSetting
{
    const char* String();
    float Float();
};
extern MorphSetting setting_011da6a4;
extern MorphSetting setting_011da6dc;
extern MorphSetting setting_011d1ecc;
extern MorphSetting setting_011d3504;
extern MorphSetting setting_011d3840;
extern MorphSetting setting_011d4b34;
extern MorphSetting setting_011d228c;
extern MorphSetting setting_011d32dc;
extern MorphSetting setting_011d46f0;
extern MorphSetting setting_011d4714;
extern MorphSetting setting_011d3150;
extern MorphSetting setting_011d3a8c;
extern MorphSetting setting_011d4384;
extern MorphSetting setting_011d4e88;
extern MorphSetting setting_011d49f0;
extern float DAT_0104a494;
extern float DAT_010162c0;
extern MorphSetting setting_011d2ca0;
extern MorphSetting setting_011d35a0;
extern MorphSetting setting_011d3720;
extern MorphSetting setting_011d240c;
extern MorphSetting setting_011d2514;
extern MorphSetting setting_011d2778;
extern MorphSetting setting_011d34a4;
extern MorphSetting setting_011d22e0;
extern MorphSetting setting_011d3660;
extern MorphSetting setting_011d2e44;
extern MorphSetting setting_011d2dfc;
extern MorphSetting setting_011d4900;
extern float DAT_01017718;
extern MorphSetting setting_011d23e8;
extern MorphSetting setting_011d32a0;
extern MorphSetting setting_011d2b80;
extern MorphSetting setting_011d3b80;
extern MorphSetting setting_011d3078;
extern MorphSetting setting_011d4174;
extern MorphSetting setting_011d2304;
extern MorphSetting setting_011d4300;
extern MorphSetting setting_011d4c30;
extern MorphSetting setting_011d4d20;
extern MorphSetting setting_011d5104;
extern MorphSetting setting_011d33e4;
extern MorphSetting setting_011d2928;
extern MorphSetting setting_011d5098;
struct MorphData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MorphData();
    ~MorphData();
};
struct MorphRace
{
    void* FUN_005d9fb0(int);
};
struct MorphRaceLink
{
    MorphRace* FUN_00726070();
};
struct FaceActor
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    MorphRaceLink race;
    int FUN_005f0cc0();
    void* FUN_00601800();
};
void FUN_00652af0(void*, void*, MorphData*, int, float);
void* FUN_00651b30();
int FUN_006521b0(int, int);
float GetMorphCoordinateValue(MorphData*, int, int, int);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
struct MorphMenuOption
{
    void FUN_007b3810(const char*);
    void FUN_00403550(int);
};
struct MorphMenuList
{
    MorphMenuOption* FUN_007b3ca0(const char*, int, int, int, int, float);
};
extern const char morphFormat[];
struct FaceMorphMenu
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
    MorphMenuList* lists[20];
    unsigned int unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unkA0, unkA4, unkA8, unkAc,
        unkB0, unkB4, unkB8, unkBc, unkC0, unkC4, unkC8, unkCc, unkD0, unkD4;
    FaceActor* actor;
    void HandleMenuKey(int);
    bool FUN_007adc30(int);
    void UpdateFaceGen(int, int, int);
    void FUN_007adc60(int, bool);
    void UpdatePlayerHead();
    void BuildMorphOptions();
};
// @fnv 0x007afaf0
void FaceMorphMenu::BuildMorphOptions()
{
    FaceMorphDescriptor shape[] = {
        {12, setting_011d1ecc.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {12, setting_011d3504.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {12, setting_011d3840.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {16, setting_011d4b34.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {16, setting_011d228c.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {16, setting_011d32dc.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {18, setting_011d46f0.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {18, setting_011d4714.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {18, setting_011d3150.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {18, setting_011d3a8c.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {13, setting_011d4384.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {13, setting_011d4e88.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {13, setting_011d49f0.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {10, setting_011d2ca0.String(), DAT_0104a494, DAT_010162c0},
        {20, 0, 0.0f, 0.0f},
        {10, setting_011d35a0.String(), DAT_0104a494, DAT_010162c0},
        {11, setting_011d4e88.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {11, setting_011d3a8c.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {11, setting_011d3720.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {17, setting_011d240c.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {17, setting_011d2514.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {17, setting_011d2778.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {17, setting_011d32dc.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {15, setting_011d34a4.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {15, setting_011d22e0.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {14, setting_011d3660.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {14, setting_011d4384.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {14, setting_011d2e44.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {14, setting_011d2dfc.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {14, setting_011d4900.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {14, setting_011d23e8.String(), setting_011da6a4.Float(), DAT_01017718},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {14, setting_011d32a0.String(), setting_011da6a4.Float(), DAT_01017718},
        {20, 0, 0.0f, 0.0f},
    };
    FaceMorphDescriptor tone[] = {
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, setting_011d2b80.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {19, setting_011d3b80.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {19, setting_011d3078.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {19, setting_011d4174.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {19, setting_011d2304.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, setting_011d4300.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, setting_011d4c30.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, setting_011d4d20.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {19, setting_011d5104.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {19, setting_011d33e4.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {19, setting_011d2928.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
        {19, setting_011d5098.String(), setting_011da6a4.Float(), setting_011da6dc.Float()},
    };
    MorphData morphs[4];
    FUN_00652af0(actor->race.FUN_00726070()->FUN_005d9fb0(actor->FUN_005f0cc0()), actor->FUN_00601800(), morphs, 0,
                 0.0f);
    for (int index = 0; index < (FUN_00651b30(), FUN_006521b0(0, 0)); ++index)
    {
        if (shape[index].group < 20 && shape[index].name)
        {
            float value = GetMorphCoordinateValue(morphs, 0, 0, index);
            value = FUN_00404010(FUN_0040ebd0(value, shape[index].maximum), shape[index].minimum);
            MorphMenuOption* option = lists[shape[index].group]->FUN_007b3ca0(
                shape[index].name, 34, static_cast<int>(shape[index].minimum * 10.0),
                static_cast<int>(shape[index].maximum * 10.0), static_cast<int>(value * 10.0), 0.25f);
            option->FUN_007b3810(morphFormat);
            option->FUN_00403550(index);
        }
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 29);
        value = FUN_00404010(FUN_0040ebd0(value, tone[29].maximum), tone[29].minimum);
        MorphMenuOption* option = lists[tone[29].group]->FUN_007b3ca0(
            tone[29].name, 35, static_cast<int>(tone[29].minimum * 10.0), static_cast<int>(tone[29].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(29);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 28);
        value = FUN_00404010(FUN_0040ebd0(value, tone[28].maximum), tone[28].minimum);
        MorphMenuOption* option = lists[tone[28].group]->FUN_007b3ca0(
            tone[28].name, 35, static_cast<int>(tone[28].minimum * 10.0), static_cast<int>(tone[28].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(28);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 30);
        value = FUN_00404010(FUN_0040ebd0(value, tone[30].maximum), tone[30].minimum);
        MorphMenuOption* option = lists[tone[30].group]->FUN_007b3ca0(
            tone[30].name, 35, static_cast<int>(tone[30].minimum * 10.0), static_cast<int>(tone[30].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(30);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 31);
        value = FUN_00404010(FUN_0040ebd0(value, tone[31].maximum), tone[31].minimum);
        MorphMenuOption* option = lists[tone[31].group]->FUN_007b3ca0(
            tone[31].name, 35, static_cast<int>(tone[31].minimum * 10.0), static_cast<int>(tone[31].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(31);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 8);
        value = FUN_00404010(FUN_0040ebd0(value, tone[8].maximum), tone[8].minimum);
        MorphMenuOption* option = lists[tone[8].group]->FUN_007b3ca0(
            tone[8].name, 35, static_cast<int>(tone[8].minimum * 10.0), static_cast<int>(tone[8].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(8);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 9);
        value = FUN_00404010(FUN_0040ebd0(value, tone[9].maximum), tone[9].minimum);
        MorphMenuOption* option = lists[tone[9].group]->FUN_007b3ca0(
            tone[9].name, 35, static_cast<int>(tone[9].minimum * 10.0), static_cast<int>(tone[9].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(9);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 18);
        value = FUN_00404010(FUN_0040ebd0(value, tone[18].maximum), tone[18].minimum);
        MorphMenuOption* option = lists[tone[18].group]->FUN_007b3ca0(
            tone[18].name, 35, static_cast<int>(tone[18].minimum * 10.0), static_cast<int>(tone[18].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(18);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 27);
        value = FUN_00404010(FUN_0040ebd0(value, tone[27].maximum), tone[27].minimum);
        MorphMenuOption* option = lists[tone[27].group]->FUN_007b3ca0(
            tone[27].name, 35, static_cast<int>(tone[27].minimum * 10.0), static_cast<int>(tone[27].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(27);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 22);
        value = FUN_00404010(FUN_0040ebd0(value, tone[22].maximum), tone[22].minimum);
        MorphMenuOption* option = lists[tone[22].group]->FUN_007b3ca0(
            tone[22].name, 35, static_cast<int>(tone[22].minimum * 10.0), static_cast<int>(tone[22].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(22);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 5);
        value = FUN_00404010(FUN_0040ebd0(value, tone[5].maximum), tone[5].minimum);
        MorphMenuOption* option = lists[tone[5].group]->FUN_007b3ca0(
            tone[5].name, 35, static_cast<int>(tone[5].minimum * 10.0), static_cast<int>(tone[5].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(5);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 6);
        value = FUN_00404010(FUN_0040ebd0(value, tone[6].maximum), tone[6].minimum);
        MorphMenuOption* option = lists[tone[6].group]->FUN_007b3ca0(
            tone[6].name, 35, static_cast<int>(tone[6].minimum * 10.0), static_cast<int>(tone[6].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(6);
    }
    {
        float value = GetMorphCoordinateValue(morphs, 1, 0, 3);
        value = FUN_00404010(FUN_0040ebd0(value, tone[3].maximum), tone[3].minimum);
        MorphMenuOption* option = lists[tone[3].group]->FUN_007b3ca0(
            tone[3].name, 35, static_cast<int>(tone[3].minimum * 10.0), static_cast<int>(tone[3].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f);
        option->FUN_007b3810(morphFormat);
        option->FUN_00403550(3);
    }
    HandleMenuKey(34);
    HandleMenuKey(35);
    if (FUN_007adc30(8))
    {
        UpdateFaceGen(1, 1, 0);
        FUN_007adc60(8, false);
    }
    if (FUN_007adc30(9))
    {
        UpdatePlayerHead();
        FUN_007adc60(9, false);
    }
}

struct SliderOption : MenuOptionFor3760
{
    int FUN_00726070();
    int FUN_0044ddc0();
};
struct FUN_00449610
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00449610();
    ~FUN_00449610();
};
struct SliderName
{
    const char* FUN_005d9fb0(int);
};
struct SliderNameRef
{
    SliderName* FUN_00726070();
};
struct SliderActor
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108;
    SliderNameRef name;
    int FUN_005f0cc0();
    void* FUN_00601800();
};
void __cdecl FUN_00652af0(const char*, void*, FUN_00449610*, int, float);
float __cdecl GetMorphCoordinateValue(FUN_00449610*, int, int, int);
struct SliderMenu
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_007afa40_mgr* optionLists[39];
    SliderOption* selected;
    int unkc8, unkcc, unkd0, unkd4;
    SliderActor* actor;
    bool ClampSliderOptions(int iFrom, int iTo, int bForward);
};
// @fnv 0x007b16d0
bool SliderMenu::ClampSliderOptions(int iStartIndex, int iEndIndex, int bForward)
{
    bool changed = false;
    for (int i = iStartIndex; i < iEndIndex; i++)
    {
        void* position = optionLists[i]->FUN_00559450();
        while (position)
        {
            SliderOption* option = (SliderOption*)*optionLists[i]->FUN_0057cbe0(&position);
            if (option && (option->FUN_00726070() == 0x22 || option->FUN_00726070() == 0x23))
            {
                FUN_00449610 values[4];
                FUN_00652af0(actor->name.FUN_00726070()->FUN_005d9fb0(actor->FUN_005f0cc0()), actor->FUN_00601800(),
                             values, 0, 0.0f);
                {
                    int low, high;
                    {
                        int value = (int)(GetMorphCoordinateValue(values, bForward, 0, option->FUN_0044ddc0()) * 10.0);
                        option->FUN_007b3840(low, high);
                        if (value < low)
                        {
                            option->FUN_007b3760(low);
                            changed = true;
                        }
                        else if (value > high)
                        {
                            option->FUN_007b3760(high);
                            changed = true;
                        }
                        else if (option != selected)
                        {
                            option->FUN_007b3760(value);
                        }
                    }
                }
            }
        }
    }
    return changed;
}

float __cdecl FUN_0040ebd0(float a, float b);
float __cdecl FUN_00404010(float a, float b);

struct PlayerStandIn
{
    float GetActorHeight() const;
};

struct PosTarget
{
    void FUN_004bc1f0(float x, float y, float z);
};

struct PosTargetPtr
{
    PosTarget* m_pObject;
    operator PosTarget*() const;
};

struct RaceSexMenuCamera
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
    float fStartX;
    float fStartY;
    float fStartZ;
    float fEndX;
    float fEndY;
    float fEndZ;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    float fProgress;
    PosTargetPtr m_spTargetObject;

    void UpdateShadowSceneNode();
    bool UpdateProgress(float afDelta, bool abForce);
};

// Advances fProgress by afDelta clamped to [0,1]; if it changed or abForce, interpolates the start/end position, applies it, and returns true.
// @fnv 0x007b1b60
bool RaceSexMenuCamera::UpdateProgress(float afDelta, bool abForce)
{
    float fOldProgress = fProgress;
    fProgress = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, fProgress + afDelta));
    if (fOldProgress == fProgress && !abForce)
        return false;
    ((PosTarget*)m_spTargetObject)
        ->FUN_004bc1f0((fEndX - fStartX) * fProgress + fStartX, (fEndY - fStartY) * fProgress + fStartY,
                       ((PlayerStandIn*)g_thePlayer)->GetActorHeight() * ((fEndZ - fStartZ) * fProgress + fStartZ));
    UpdateShadowSceneNode();
    return true;
}

struct AppearanceObject
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual AppearanceObject* AsNode();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual AppearanceObject* AsGeometry();
    unsigned int FUN_0043b480();
    AppearanceObject* FUN_0043b4a0(unsigned int);
    void SetByteAtOffsetE4(unsigned char);

    struct AppearanceName& GetName();
    struct ShaderProperty* GetProperty(int);
};
struct FaceModel
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual FaceModel* AsFaceModel();
    unsigned char FUN_007b2570();
    void FUN_0065a840();
    void ApplyShape(void*, AppearanceObject*, int);
    bool ApplyTextureCoordinate(void*, struct TexturePointer&, unsigned int);
};
struct SkinObject
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void Remove(AppearanceObject*);
};
struct SkinRoot : AppearanceObject
{
    SkinObject* FUN_009611e0();
};
struct AppearanceProcess
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void Refresh();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43c();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44c();
    virtual void slot450();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45c();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46c();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47c();
    virtual void slot480();
    virtual void slot484();
    virtual void slot488();
    virtual void slot48c();
    virtual void slot490();
    virtual void slot494();
    virtual void slot498();
    virtual void slot49c();
    virtual void slot4a0();
    virtual void slot4a4();
    virtual void slot4a8();
    virtual void slot4ac();
    virtual void slot4b0();
    virtual void slot4b4();
    virtual void slot4b8();
    virtual void slot4bc();
    virtual void slot4c0();
    virtual void slot4c4();
    virtual void slot4c8();
    virtual void slot4cc();
    virtual void slot4d0();
    virtual void slot4d4();
    virtual void slot4d8();
    virtual void slot4dc();
    virtual void slot4e0();
    virtual void slot4e4();
    virtual void slot4e8();
    virtual void slot4ec();
    virtual void slot4f0();
    virtual void slot4f4();
    virtual void slot4f8();
    virtual void slot4fc();
    virtual void slot500();
    virtual void slot504();
    virtual void slot508();
    virtual void slot50c();
    virtual void slot510();
    virtual void slot514();
    virtual void slot518();
    virtual void slot51c();
    virtual void slot520();
    virtual void slot524();
    virtual void slot528();
    virtual void slot52c();
    virtual void slot530();
    virtual void slot534();
    virtual void slot538();
    virtual void slot53c();
    virtual void slot540();
    virtual void slot544();
    virtual void slot548();
    virtual void slot54c();
    virtual void slot550();
    virtual void slot554();
    virtual void slot558();
    virtual void slot55c();
    virtual void slot560();
    virtual void slot564();
    virtual void slot568();
    virtual void slot56c();
    virtual void slot570();
    virtual void slot574();
    virtual void slot578();
    virtual void slot57c();
    virtual void slot580();
    virtual void slot584();
    virtual void slot588();
    virtual void slot58c();
    virtual void slot590();
    virtual void slot594();
    virtual void slot598();
    virtual void slot59c();
    virtual void slot5a0();
    virtual void slot5a4();
    virtual void slot5a8();
    virtual void slot5ac();
    virtual void slot5b0();
    virtual void slot5b4();
    virtual void slot5b8();
    virtual void slot5bc();
    virtual void slot5c0();
    virtual void slot5c4();
    virtual void slot5c8();
    virtual void slot5cc();
    virtual void slot5d0();
    virtual void slot5d4();
    virtual void slot5d8();
    virtual void slot5dc();
    virtual void slot5e0();
    virtual void slot5e4();
    virtual void slot5e8();
    virtual void slot5ec();
    virtual void slot5f0();
    virtual void slot5f4();
    virtual void slot5f8();
    virtual void slot5fc();
    virtual void slot600();
    virtual void slot604();
    virtual void slot608();
    virtual void slot60c();
    virtual void slot610();
    virtual void slot614();
    virtual void slot618();
    virtual void slot61c();
    virtual void slot620();
    virtual void slot624();
    virtual void slot628();
    virtual void slot62c();
    virtual void slot630();
    virtual void slot634();
    virtual void slot638();
    virtual void slot63c();
    virtual void slot640();
    virtual void slot644();
    virtual void slot648();
    virtual void slot64c();
    virtual void slot650();
    virtual void slot654();
    virtual void slot658();
    virtual void slot65c();
    virtual void slot660();
    virtual void slot664();
    virtual void slot668();
    virtual void slot66c();
    virtual void slot670();
    virtual void slot674();
    virtual void slot678();
    virtual void slot67c();
    virtual void slot680();
    virtual void slot684();
    virtual void slot688();
    virtual void slot68c();
    virtual void slot690();
    virtual void slot694();
    virtual void slot698();
    virtual void slot69c();
    virtual void slot6a0();
    virtual void slot6a4();
    virtual void slot6a8();
    virtual void slot6ac();
    virtual void slot6b0();
    virtual void slot6b4();
    virtual void slot6b8();
    virtual void slot6bc();
    virtual void slot6c0();
    virtual void slot6c4();
    virtual void slot6c8();
    virtual void slot6cc();
    virtual void slot6d0();
    virtual void slot6d4();
    virtual void slot6d8();
    virtual void slot6dc();
    virtual void slot6e0();
    virtual void slot6e4();
    virtual void slot6e8();
    virtual void slot6ec();
    virtual void slot6f0();
    virtual void slot6f4();
    virtual void slot6f8();
    virtual void slot6fc();
    virtual void slot700();
    virtual void slot704();
    virtual void slot708();
    virtual void slot70c();
    virtual void slot710();
    virtual void slot714();
    virtual void slot718();
    virtual void slot71c();
    virtual void slot720();
    virtual void slot724();
    virtual void slot728();
    virtual void slot72c();
    virtual void slot730();
    virtual void slot734();
    virtual void slot738();
    virtual void slot73c();
    virtual void slot740();
    virtual void slot744();
    virtual void slot748();
    virtual void slot74c();
    virtual void slot750();
    virtual void slot754();
    virtual void slot758();
    virtual void slot75c();
    virtual void slot760();
    virtual void slot764();
    virtual void slot768();
    virtual void slot76c();
    virtual void slot770();
    virtual void slot774();
    virtual void slot778();
    virtual void slot77c();
    virtual void slot780();
    virtual void slot784();
    virtual void slot788();
    virtual void slot78c();
    virtual void slot790();
    virtual void ResetA(int);
    virtual void slot798();
    virtual void ResetB(int);
    virtual void slot7a0();
    virtual void ResetC(int);
};
struct AppearancePlayer
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual SkinRoot* RootA(int);
    virtual SkinRoot* RootB(int);
    AppearanceObject* GetNode(bool);
    struct AppearanceAnimation* GetAnimation(bool);
    AppearanceProcess* GetCurrentProcess();
    void* GetBipedAnim(bool);
};
struct AppearanceNPC
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void SetFlags(int);
    void FUN_005dd560();
    void FUN_00607370(int*, int*);
    void AttachHeadModels(AppearancePlayer*, void*, int, int);
    void FUN_00603ad0(void*);
};
struct ShaderProperty
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void SetTexture(int, void*);
    int FUN_00441110();
};
struct AppearanceAnimation
{
    struct AppearanceManager* FUN_00496940();
};
struct AppearanceManager
{
    void* GetStringAtOffset();
};
struct AppearanceName
{
    operator const char*() const;
};
struct FaceCoordinate
{
    int a, b, c, d, e, f, g, h;
    FaceCoordinate();
    ~FaceCoordinate();
};
struct TexturePointer
{
    void* texture;
    TexturePointer(void*);
    ~TexturePointer();
    operator void*();
};
FaceModel* __cdecl GetGeomExtraData(AppearanceObject*);
extern AppearancePlayer* appearancePlayer;
extern "C" unsigned int __cdecl strlen(const char*);
int __cdecl _mbsnicmp(const char*, const char*, unsigned int);
void __cdecl FUN_00a6e8e0(SkinRoot*, void*);
void __cdecl FUN_00652e00(void*, void*, void*, int);
unsigned int __cdecl FUN_006151d0();
struct AppearanceMenu
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
    AppearanceNPC* npc;
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
    int faceData;
    void UpdateShadowSceneNode();
    void UpdateFaceGen(bool remove, bool shape, bool texture);
};
// @fnv 0x007b1e70
void AppearanceMenu::UpdateFaceGen(bool remove, bool shape, bool texture)
{
    if (!appearancePlayer->RootA(0) || !appearancePlayer->RootB(0))
        return;
    npc->SetFlags(0x800);
    if (remove)
    {
        AppearanceObject* second = appearancePlayer->GetNode(false);
        AppearanceObject* root = second ? second->AsNode() : 0;
        if (root)
        {
            void* manager = 0;
            if (appearancePlayer->GetAnimation(false) && appearancePlayer->GetAnimation(false)->FUN_00496940())
                manager = appearancePlayer->GetAnimation(false)->FUN_00496940()->GetStringAtOffset();
            SkinRoot* controller;
            void* skin = manager;
            controller = appearancePlayer->RootB(0);
            if (controller && controller->FUN_009611e0())
            {
                FUN_00a6e8e0(controller, skin);
                appearancePlayer->GetCurrentProcess()->ResetB(0);
                controller->FUN_009611e0()->Remove(controller);
            }
            controller = appearancePlayer->RootA(0);
            if (controller && controller->FUN_009611e0())
            {
                FUN_00a6e8e0(controller, skin);
                appearancePlayer->GetCurrentProcess()->ResetA(0);
                appearancePlayer->GetCurrentProcess()->ResetC(0);
                controller->FUN_009611e0()->Remove(controller);
            }
        }
        if (appearancePlayer->GetCurrentProcess())
            appearancePlayer->GetCurrentProcess()->Refresh();
        npc->FUN_005dd560();
        int first = 0;
        int node = first;
        npc->FUN_00607370(&node, &first);
        npc->AttachHeadModels(appearancePlayer, appearancePlayer->GetBipedAnim(false), node, first);
    }
    else
    {
        FaceCoordinate coordinates[4];
        FaceCoordinate modified[4];
        npc->FUN_00603ad0(coordinates);
        if (shape)
            FUN_00652e00(&faceData, coordinates, modified, 0);
        SkinRoot* controller = appearancePlayer->RootA(0);
        for (int pass = 0; pass < 2; pass++)
        {
            if (shape)
                controller->SetByteAtOffsetE4(1);
            unsigned int count = controller->FUN_0043b480();
            for (unsigned int index = 0; index < count; index++)
            {
                AppearanceObject* geometry = controller->FUN_0043b4a0(index);
                AppearanceObject* model = geometry ? geometry->AsGeometry() : 0;
                if (!model)
                    continue;
                FaceModel* extra = GetGeomExtraData(model);
                FaceModel* object = extra ? extra->AsFaceModel() : 0;
                if (!object)
                    continue;
                if (shape)
                    object->ApplyShape(modified, model, 0);
                if (texture && !_mbsnicmp(model->GetName(), "FaceGenFace", strlen("FaceGenFace")))
                {
                    ShaderProperty* generated;
                    {
                        ShaderProperty* property = geometry->GetProperty(3);
                        generated =
                            (!property ? 0 : (property->FUN_00441110() >= 8 && property->FUN_00441110() <= 12 ? 1 : 0))
                                ? property
                                : 0;
                    }
                    if (!generated)
                        continue;
                    TexturePointer pkTexture(0);
                    if (!object->FUN_007b2570())
                        object->FUN_0065a840();
                    object->ApplyTextureCoordinate(coordinates, pkTexture, FUN_006151d0());
                    generated->SetTexture(1, pkTexture);
                }
            }
            controller = appearancePlayer->RootB(0);
        }
    }
    UpdateShadowSceneNode();
}

class Player511;
class Process511
{
  public:
    virtual void Virtual000();
    virtual void Virtual004();
    virtual void Virtual008();
    virtual void Virtual00c();
    virtual void Virtual010();
    virtual void Virtual014();
    virtual void Virtual018();
    virtual void Virtual01c();
    virtual void Virtual020();
    virtual void Virtual024();
    virtual void Virtual028();
    virtual void Virtual02c();
    virtual void Virtual030();
    virtual void Virtual034();
    virtual void Virtual038();
    virtual void Virtual03c();
    virtual void Virtual040();
    virtual void Virtual044();
    virtual void Virtual048();
    virtual void Virtual04c();
    virtual void Virtual050();
    virtual void Virtual054();
    virtual void Reset();
    virtual void Virtual05c();
    virtual void Virtual060();
    virtual void Virtual064();
    virtual void Virtual068();
    virtual void Virtual06c();
    virtual void Virtual070();
    virtual void Virtual074();
    virtual void Virtual078();
    virtual void Virtual07c();
    virtual void Virtual080();
    virtual void Virtual084();
    virtual void Virtual088();
    virtual void Virtual08c();
    virtual void Virtual090();
    virtual void Virtual094();
    virtual void Virtual098();
    virtual void Virtual09c();
    virtual void Virtual0a0();
    virtual void Virtual0a4();
    virtual void Virtual0a8();
    virtual void Virtual0ac();
    virtual void Virtual0b0();
    virtual void Virtual0b4();
    virtual void Virtual0b8();
    virtual void Virtual0bc();
    virtual void Virtual0c0();
    virtual void Virtual0c4();
    virtual void Virtual0c8();
    virtual void Virtual0cc();
    virtual void Virtual0d0();
    virtual void Virtual0d4();
    virtual void Virtual0d8();
    virtual void Virtual0dc();
    virtual void Virtual0e0();
    virtual void Virtual0e4();
    virtual void Virtual0e8();
    virtual void Virtual0ec();
    virtual void Virtual0f0();
    virtual void Virtual0f4();
    virtual void Virtual0f8();
    virtual void Virtual0fc();
    virtual void Virtual100();
    virtual void Virtual104();
    virtual void Virtual108();
    virtual void Virtual10c();
    virtual void Virtual110();
    virtual void Virtual114();
    virtual void Virtual118();
    virtual void Virtual11c();
    virtual void Virtual120();
    virtual void Virtual124();
    virtual void Virtual128();
    virtual void Virtual12c();
    virtual void Virtual130();
    virtual void Virtual134();
    virtual void Virtual138();
    virtual void Virtual13c();
    virtual void Virtual140();
    virtual void Virtual144();
    virtual void Virtual148();
    virtual void Virtual14c();
    virtual void Virtual150();
    virtual void Virtual154();
    virtual void Virtual158();
    virtual void Virtual15c();
    virtual void Virtual160();
    virtual void Virtual164();
    virtual void Virtual168();
    virtual void Virtual16c();
    virtual void Virtual170();
    virtual void Virtual174();
    virtual void Virtual178();
    virtual void Virtual17c();
    virtual void Virtual180();
    virtual void Virtual184();
    virtual void Virtual188();
    virtual void Virtual18c();
    virtual void Virtual190();
    virtual void Virtual194();
    virtual void Virtual198();
    virtual void Virtual19c();
    virtual void Virtual1a0();
    virtual void Virtual1a4();
    virtual void Virtual1a8();
    virtual void Virtual1ac();
    virtual void Virtual1b0();
    virtual void Virtual1b4();
    virtual void Virtual1b8();
    virtual void Virtual1bc();
    virtual void Virtual1c0();
    virtual void Virtual1c4();
    virtual void Virtual1c8();
    virtual void Virtual1cc();
    virtual void Virtual1d0();
    virtual void Virtual1d4();
    virtual void Virtual1d8();
    virtual void Virtual1dc();
    virtual void Virtual1e0();
    virtual void Virtual1e4();
    virtual void Virtual1e8();
    virtual void Virtual1ec();
    virtual void Virtual1f0();
    virtual void Virtual1f4();
    virtual void Virtual1f8();
    virtual void Virtual1fc();
    virtual void Virtual200();
    virtual void Virtual204();
    virtual void Virtual208();
    virtual void Virtual20c();
    virtual void Virtual210();
    virtual void Virtual214();
    virtual void Virtual218();
    virtual void Virtual21c();
    virtual void Virtual220();
    virtual void Virtual224();
    virtual void Virtual228();
    virtual void Virtual22c();
    virtual void Virtual230();
    virtual void Virtual234();
    virtual void Virtual238();
    virtual void Virtual23c();
    virtual void Virtual240();
    virtual void Virtual244();
    virtual void Virtual248();
    virtual void Virtual24c();
    virtual void Virtual250();
    virtual void Virtual254();
    virtual void Virtual258();
    virtual void Virtual25c();
    virtual void Virtual260();
    virtual void Virtual264();
    virtual void Virtual268();
    virtual void Virtual26c();
    virtual void Virtual270();
    virtual void Virtual274();
    virtual void Virtual278();
    virtual void Virtual27c();
    virtual void Virtual280();
    virtual void Virtual284();
    virtual void Virtual288();
    virtual void Virtual28c();
    virtual void Virtual290();
    virtual void Virtual294();
    virtual void Virtual298();
    virtual void Virtual29c();
    virtual void Virtual2a0();
    virtual void Virtual2a4();
    virtual void Virtual2a8();
    virtual void Virtual2ac();
    virtual void Virtual2b0();
    virtual void Virtual2b4();
    virtual void Virtual2b8();
    virtual void Virtual2bc();
    virtual void Virtual2c0();
    virtual void Virtual2c4();
    virtual void Virtual2c8();
    virtual void Virtual2cc();
    virtual void Virtual2d0();
    virtual void Virtual2d4();
    virtual void Virtual2d8();
    virtual void Virtual2dc();
    virtual void Virtual2e0();
    virtual void Virtual2e4();
    virtual void Virtual2e8();
    virtual void Virtual2ec();
    virtual void Virtual2f0();
    virtual void Virtual2f4();
    virtual void Virtual2f8();
    virtual void Virtual2fc();
    virtual void Virtual300();
    virtual void Virtual304();
    virtual void Virtual308();
    virtual void Virtual30c();
    virtual void Virtual310();
    virtual void Virtual314();
    virtual void Virtual318();
    virtual void Virtual31c();
    virtual void Virtual320();
    virtual void Virtual324();
    virtual void Virtual328();
    virtual void Virtual32c();
    virtual void Virtual330();
    virtual void Virtual334();
    virtual void Virtual338();
    virtual void Virtual33c();
    virtual void Virtual340();
    virtual void Virtual344();
    virtual void Virtual348();
    virtual void Virtual34c();
    virtual void Virtual350();
    virtual void Virtual354();
    virtual void Virtual358();
    virtual void Virtual35c();
    virtual void Virtual360();
    virtual void Virtual364();
    virtual void Virtual368();
    virtual void Virtual36c();
    virtual void Virtual370();
    virtual void Virtual374();
    virtual void Virtual378();
    virtual void Virtual37c();
    virtual void Virtual380();
    virtual void Virtual384();
    virtual void Virtual388();
    virtual void Virtual38c();
    virtual void Virtual390();
    virtual void Virtual394();
    virtual void Virtual398();
    virtual void Virtual39c();
    virtual void Virtual3a0();
    virtual void Virtual3a4();
    virtual void Virtual3a8();
    virtual void Virtual3ac();
    virtual void Virtual3b0();
    virtual void Virtual3b4();
    virtual void Virtual3b8();
    virtual void Virtual3bc();
    virtual void Virtual3c0();
    virtual void Virtual3c4();
    virtual void Virtual3c8();
    virtual void Virtual3cc();
    virtual void Virtual3d0();
    virtual void Virtual3d4();
    virtual void Virtual3d8();
    virtual void Virtual3dc();
    virtual void Virtual3e0();
    virtual void Virtual3e4();
    virtual void Virtual3e8();
    virtual void Virtual3ec();
    virtual void Virtual3f0();
    virtual void Virtual3f4();
    virtual void Virtual3f8();
    virtual void Virtual3fc();
    virtual void Virtual400();
    virtual void Virtual404();
    virtual void Virtual408();
    virtual void Virtual40c();
    virtual void Virtual410();
    virtual void Virtual414();
    virtual void Virtual418();
    virtual void Virtual41c();
    virtual void Virtual420();
    virtual void Virtual424();
    virtual void Virtual428();
    virtual void Virtual42c();
    virtual void Virtual430();
    virtual void Virtual434();
    virtual void Virtual438();
    virtual void Virtual43c();
    virtual void Virtual440();
    virtual void Virtual444();
    virtual void Virtual448();
    virtual void Virtual44c();
    virtual void Virtual450();
    virtual void Virtual454();
    virtual void Virtual458();
    virtual void Virtual45c();
    virtual void Virtual460();
    virtual void SetOwner(Player511*);
    virtual void SetMode(int);
};
class Root511
{
  public:
    virtual void Virtual000();
    virtual void Virtual004();
    virtual void Virtual008();
    virtual void Virtual00c();
    virtual void Virtual010();
    virtual void Virtual014();
    virtual void Virtual018();
    virtual void Virtual01c();
    virtual void Virtual020();
    virtual void Refresh();
    virtual void Update();
};
struct NiAVObject511
{
    void FUN_0043fa80(const Matrix*);
};
struct Node511
{
    NiAVObject511* FUN_0043b4a0(int);
};
class Player511
{
  public:
    virtual void Virtual000();
    virtual void Virtual004();
    virtual void Virtual008();
    virtual void Virtual00c();
    virtual void Virtual010();
    virtual void Virtual014();
    virtual void Virtual018();
    virtual void Virtual01c();
    virtual void Virtual020();
    virtual void Virtual024();
    virtual void Virtual028();
    virtual void Virtual02c();
    virtual void Virtual030();
    virtual void Virtual034();
    virtual void Virtual038();
    virtual void Virtual03c();
    virtual void Virtual040();
    virtual void Virtual044();
    virtual void Virtual048();
    virtual void Virtual04c();
    virtual void Virtual050();
    virtual void Virtual054();
    virtual void Virtual058();
    virtual void Virtual05c();
    virtual void Virtual060();
    virtual void Virtual064();
    virtual void Virtual068();
    virtual void Virtual06c();
    virtual void Virtual070();
    virtual void Virtual074();
    virtual void Virtual078();
    virtual void Virtual07c();
    virtual void Virtual080();
    virtual void Virtual084();
    virtual void Virtual088();
    virtual void Virtual08c();
    virtual void Virtual090();
    virtual void Virtual094();
    virtual void Virtual098();
    virtual void Virtual09c();
    virtual void Virtual0a0();
    virtual void Virtual0a4();
    virtual void Virtual0a8();
    virtual void Virtual0ac();
    virtual void Virtual0b0();
    virtual void Virtual0b4();
    virtual void Virtual0b8();
    virtual void Virtual0bc();
    virtual void Virtual0c0();
    virtual void Virtual0c4();
    virtual void Virtual0c8();
    virtual void Virtual0cc();
    virtual void Virtual0d0();
    virtual void Virtual0d4();
    virtual void Virtual0d8();
    virtual void Virtual0dc();
    virtual void Virtual0e0();
    virtual void Virtual0e4();
    virtual void Virtual0e8();
    virtual void Virtual0ec();
    virtual void Virtual0f0();
    virtual void Virtual0f4();
    virtual void Virtual0f8();
    virtual void Virtual0fc();
    virtual void Virtual100();
    virtual void Virtual104();
    virtual void Virtual108();
    virtual void Virtual10c();
    virtual void Virtual110();
    virtual void Virtual114();
    virtual void Virtual118();
    virtual void Virtual11c();
    virtual void Virtual120();
    virtual void Virtual124();
    virtual void Virtual128();
    virtual void Virtual12c();
    virtual void Virtual130();
    virtual void Virtual134();
    virtual void Virtual138();
    virtual void Virtual13c();
    virtual void Virtual140();
    virtual void Virtual144();
    virtual void Virtual148();
    virtual void Virtual14c();
    virtual void Virtual150();
    virtual void Virtual154();
    virtual void Virtual158();
    virtual void Virtual15c();
    virtual void Virtual160();
    virtual void Virtual164();
    virtual void Virtual168();
    virtual void Virtual16c();
    virtual void Virtual170();
    virtual void Virtual174();
    virtual void Virtual178();
    virtual void Virtual17c();
    virtual void Virtual180();
    virtual void Virtual184();
    virtual void Virtual188();
    virtual void Virtual18c();
    virtual void Virtual190();
    virtual void Virtual194();
    virtual void Virtual198();
    virtual void Virtual19c();
    virtual void Virtual1a0();
    virtual void Virtual1a4();
    virtual void Virtual1a8();
    virtual int HasStateA(int);
    virtual int HasStateB(int);
    HairOption* FUN_007af430();
    Process511* FUN_008d8520();
    void* FUN_00950b00(bool);
    Node511* FUN_00950bb0(bool);
    Matrix FUN_0056fac0(const Matrix&);
};
extern "C" Player511* _g_thePlayer;
extern bool DAT_011c5cb4;
extern Matrix DAT_011a9448;
struct IOManager
{
    void FUN_00456520();
};
extern IOManager* DAT_01202d98;
Root511* FUN_00705990();
void FUN_006570e0(HairOption*);
class QHeadLocal
{
  public:
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
    QHeadLocal(TESNPC*, int);
    ~QHeadLocal();
    void FUN_0043ecb0();
    void RunVirtualMethod28();
    void FUN_0043ed90(Player511*, void*);
};
struct Menu511
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
    TESNPC* npc;
    void UpdateShadowSceneNode();
    void UpdatePlayerHead();
};
// @fnv 0x007b25a0
void Menu511::UpdatePlayerHead()
{
    FUN_006570e0(_g_thePlayer->FUN_007af430());
    DAT_011c5cb4 = true;
    _g_thePlayer->FUN_008d8520()->Reset();
    _g_thePlayer->FUN_008d8520()->SetMode(3);
    _g_thePlayer->FUN_008d8520()->SetOwner(_g_thePlayer);
    if (!_g_thePlayer->HasStateB(0) && !_g_thePlayer->HasStateA(0))
    {
        QHeadLocal head(npc, 0);
        head.FUN_0043ecb0();
        head.RunVirtualMethod28();
        head.FUN_0043ed90(_g_thePlayer, _g_thePlayer->FUN_00950b00(false));
    }
    DAT_011c5cb4 = false;
    Node511* node = _g_thePlayer->FUN_00950bb0(true);
    Node511* matrix = node;
    NiAVObject511* object = matrix->FUN_0043b4a0(0);
    Matrix node2 = DAT_011a9448;
    object->FUN_0043fa80(&_g_thePlayer->FUN_0056fac0(node2));
    DAT_01202d98->FUN_00456520();
    UpdateShadowSceneNode();
    FUN_00705990()->Update();
    FUN_00705990()->Refresh();
}

struct NavTile
{
    bool IsAllChildrenFlag0();
};
struct NavItem
{
    NavTile* tile;
};
struct NavController
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Navigate(int, int);
};
void FUN_00706ff0(NavTile*);
struct NavList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NavItem* selected;
    void* FUN_0049c680(NavItem*&, int);
    void* GetSecondField(void*);
    void* DereferenceIfNotNull(void*);
    void* FUN_00726070();
    void* FUN_00559450();
    NavItem*& AddEight(void*);
    NavItem*& FUN_007b5370();
    NavItem*& FUN_0073ac90();
    bool FUN_007b4260(int);
};
// Moves the selection according to direction, retries navigation up to 100 times, then updates the selected tile.
// @fnv 0x007b4260
bool NavList::FUN_007b4260(int direction)
{
    void* position;
    bool previousVal = direction == 1 || direction == 15;
    bool bResult = true;
    switch (direction)
    {
    case 1:
    case 2: {
        position = FUN_0049c680(selected, 0);
        if (position)
        {
            position = previousVal ? GetSecondField(position) : DereferenceIfNotNull(position);
        }
        else
        {
            position = previousVal ? FUN_00726070() : FUN_00559450();
        }
        if (position)
        {
            selected = AddEight(position);
        }
        else
        {
            bResult = false;
        }
        break;
    }
    case 16:
        selected = FUN_007b5370();
        break;
    case 15:
        selected = FUN_0073ac90();
        break;
    default:
        return false;
    }
    if (selected && selected->tile)
    {
        int attempts = 100;
        while (attempts-- && !selected->tile->IsAllChildrenFlag0())
        {
            reinterpret_cast<NavController*>(DAT_011da634)->Navigate(previousVal ? 2 : 3, 0);
        }
        FUN_00706ff0(selected->tile);
    }
    return bResult;
}

struct OptTile
{
    float Read(int);
    void Text(int, const char*, bool);
    void Integer(int, int);
    OptTile* Parent();
    void Float(int, float, bool);
    void Refresh(bool);
};
struct OptEntry
{
    OptTile* tile;
    unsigned int kind;
    int unk08;
    OptEntry();
};
struct Root4650
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
    void* parent;
    OptTile* Create(void*, const char*, int);
};
extern Root4650* root4650;
int LookupTrait(const char*, int);
float FUN_00404010(float, float);
extern float DAT_010162c0;
struct List4650
{
    int unk00, unk04, unk08, unk0c, unk10;
    OptTile* tile;
    float height;
    int unk1c;
    OptEntry* selected;
    void Insert(void*, OptEntry*&);
    void Append(OptEntry*&);
    void* Find(OptEntry*&, void*);
    void* Previous(void*);
    OptEntry*& At(void*);
    OptEntry*& Next(void*&);
    OptEntry* CreateEntry(const char*, const char*, unsigned int, void*);
};
// Creates a new OptEntry tile from text and template, inserts or appends it, repositions following entries, updates height, and selects it if none is selected.
// @fnv 0x007b4650
OptEntry* List4650::CreateEntry(const char* text, const char* templ, unsigned int kind, void* pos)
{
    if (!text || !root4650 || !root4650->parent || !tile)
        return 0;
    OptEntry* entry7 = new OptEntry;
    int index = (int)tile->Read(0x1004);
    entry7->kind = kind;
    entry7->tile = root4650->Create(root4650->parent, templ, 0);
    entry7->tile->Text(0xfc4, text, true);
    entry7->tile->Integer(0x1004, index);
    entry7->tile->Integer(0xfaf, 1);
    if (pos)
        Insert(pos, entry7);
    else
        Append(entry7);
    pos = Find(entry7, 0);
    while (pos)
    {
        void* prev2 = Previous(pos);
        OptEntry* beforeB = prev2 ? At(prev2) : 0;
        OptEntry* current5 = Next(pos);
        current5->tile->Float(0xfa2,
                              beforeB ? beforeB->tile->Read(0xfa2) + beforeB->tile->Read(0xfb0)
                                      : current5->tile->Parent()->Read(LookupTrait("_top_bound", -1)),
                              true);
        current5->tile->Refresh(false);
    }
    height = FUN_00404010(height, entry7->tile->Read(0xfb0));
    if (index < 4 && entry7->kind < 4)
        entry7->tile->Text(0xfcb, "UIPipBoyMode", true);
    if (!selected)
    {
        selected = entry7;
        entry7->tile->Float(0xfd6, DAT_010162c0, true);
    }
    return entry7;
}

namespace fnv_007b4930 {
struct PendingTile : LocalTile
{
    const unsigned char* FUN_00a011f0(int trait);
    void FUN_00a0b110(int trait);
};
struct PendingOption : MenuOptionFor3760
{
    int FUN_00726070();
    int ReadOptionValue();
};
extern StrTable DAT_011d3528;
int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
struct PendingMenu
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
    PendingTile* pendingTile;
    PendingOption* pendingOption;
    bool FUN_007adc30(int trait);
    void FUN_007adc60(int trait, bool enabled);
    void HandleOptionSelection();
    void HandlePendingTileAction();
};

// @fnv 0x007b4930
void PendingMenu::HandlePendingTileAction()
{
    if (pendingTile && pendingOption)
    {
        int action = (int)pendingTile->FUN_00a011b0(0xfaa);
        bool changed = false;
        if (pendingOption->FUN_00726070() == 29 && (action == 100 || action == 104) &&
            _mbscmp(static_cast<PendingTile*>(pendingTile->GetParent())->FUN_00a011f0(0x1009),
                    reinterpret_cast<const unsigned char*>(DAT_011d3528.FUN_00403df0())) == 0)
        {
            changed = true;
        }
        else if (action == 100)
        {
            changed = pendingOption->FUN_007b3760(pendingOption->GetFloat1005() - pendingOption->ReadOptionValue());
        }
        else if (action == 104)
        {
            changed = pendingOption->FUN_007b3760(pendingOption->GetFloat1005() + pendingOption->ReadOptionValue());
        }
        else if (action == 102)
        {
            changed = pendingOption->FUN_007b3760(pendingOption->GetFloat1005() -
                                                  (int)pendingTile->GetParent()->FUN_00a011b0(0x1008));
        }
        else if (action == 103)
        {
            changed = pendingOption->FUN_007b3760(pendingOption->GetFloat1005() +
                                                  (int)pendingTile->GetParent()->FUN_00a011b0(0x1008));
        }
        else if (action == 105)
        {
            changed = FUN_007adc30(2);
        }
        if (changed)
        {
            HandleOptionSelection();
            pendingTile->FUN_00a0b110(0xfcb);
        }
        FUN_007adc60(2, false);
        pendingTile = 0;
        pendingOption = 0;
    }
}
}  // namespace fnv_007b4930

namespace fnv_007b4b50 {
struct FUN_00449610
{
    int v0, v4, v8, vc, v10, v14, v18, v1c;
    FUN_00449610();
    ~FUN_00449610();
};
struct Option7
{
    int FUN_00726070();
    int GetFloat1005();
    void ApplyToAllTiles();
    Option7* FindByColor(int);
    void FUN_007b3810(const char*);
    void FUN_007b3840(int&, int&);
    void FUN_007b3760(int);
};
struct Race7
{
    char* FUN_005d9fb0(int);
};
struct RaceRef7
{
    Race7* FUN_00726070();
};
struct NPC7
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
    RaceRef7 race;
    void FUN_00603790(void*);
    void FUN_00603ad0(FUN_00449610*);
    unsigned int FUN_004169d0();
    int GetSex();
    void* FUN_00601800();
};
struct FormArray7
{
    void*& FUN_00877a30(unsigned int);
};
struct Setting7
{
    const char* String();
};
extern Setting7 g_011d3528;
struct Menu7
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
    Option7* lists[20];
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
    Option7* selected;
    int unkc8, unkcc, unkd0, unkd4;
    NPC7* npc;
    FormArray7 forms;
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
    FUN_00449610 face[4];
    int GetCurrentPage();
    void ApplyHairOption(Option7*);
    void ApplyParam(Option7*);
    void HandleMenuKey(int);
    bool FUN_007adc30(int);
    void UpdateFaceGen(int, int, int);
    void FUN_007adc60(int, bool);
    void UpdatePlayerHead();
    void RebuildFaceGen(int);
    void UpdateEyeTextures();
    void FUN_007afa40(unsigned int);
    void HandleOptionSelection();
};

void FUN_006521f0(FUN_00449610*);
float FUN_00652440(FUN_00449610*, int, int);
void FUN_00652470(FUN_00449610*, int, int, float);
void FUN_00652e00(char*, FUN_00449610*, FUN_00449610*, int);
bool FUN_00652900(FUN_00449610*, void*);
void FUN_006529a0(FUN_00449610*, void*, int, int);
// Handles the selected menu option by page and option type, updating lists, NPC face data and menu flags.
// @fnv 0x007b4b50
void Menu7::HandleOptionSelection()
{
    if (GetCurrentPage() == 6)
    {
        ApplyHairOption(selected);
    }
    else if (selected->FUN_00726070() == 34 || selected->FUN_00726070() == 35)
    {
        ApplyParam(selected);
        HandleMenuKey(selected->FUN_00726070());
        if (FUN_007adc30(8))
        {
            if (selected->FUN_00726070() == 34)
                UpdateFaceGen(0, 1, 0);
            else
                UpdateFaceGen(0, 0, 1);
            FUN_007adc60(8, false);
        }
    }
    else if (selected->FUN_00726070() == 24)
    {
        npc->FUN_00603790(forms.FUN_00877a30(selected->GetFloat1005() - 1));
        for (int indexB = 0; indexB < 20; indexB++)
            lists[indexB]->ApplyToAllTiles();
        HandleMenuKey(34);
        HandleMenuKey(35);
        UpdateFaceGen(1, 1, 0);
        UpdatePlayerHead();
        RebuildFaceGen(1);
        UpdateEyeTextures();
        FUN_007adc60(8, false);
        FUN_007adc60(9, false);
        FUN_007afa40(npc->FUN_004169d0());
        Option7* option6 = lists[6]->FindByColor(29);
        if (option6)
        {
            option6->FUN_007b3810(g_011d3528.String());
            int low3, high;
            option6->FUN_007b3840(low3, high);
            option6->FUN_007b3760(low3);
        }
        FUN_007adc60(0, true);
    }
    else if (selected->FUN_00726070() == 26)
    {
        int amount7 = selected->GetFloat1005();
        amount7 = (int)(amount7 * 5.550000190734863 + 9.449999809265137);
        FUN_00449610 base3[4];
        FUN_00449610 result6[4];
        FUN_006521f0(result6);
        npc->FUN_00603ad0(base3);
        npc->FUN_00603ad0(face);
        float first2 = FUN_00652440(base3, 0, 0);
        float second_ = FUN_00652440(base3, 0, 1);
        float remaining = second_ - (first2 - amount7);
        amount7 = (int)(((amount7 > 15.0 ? (float)amount7 : 15.0f) < 65.0) ? (amount7 > 15.0 ? (float)amount7 : 15.0f)
                                                                           : 65.0f);
        remaining = ((remaining > 15.0 ? remaining : 15.0f) < 65.0) ? (remaining > 15.0 ? remaining : 15.0f) : 65.0f;
        FUN_00652470(base3, 0, 0, (float)amount7);
        FUN_00652470(base3, 0, 1, remaining);
        FUN_00652e00(npc->race.FUN_00726070()->FUN_005d9fb0(npc->GetSex()), base3, result6, 0);
        if (FUN_00652900(result6, npc->FUN_00601800()))
            FUN_006529a0(result6, npc->FUN_00601800(), 0, 0);
        ((Menu7*)DAT_011da634)->FUN_007adc60(7, true);
        ((Menu7*)DAT_011da634)->HandleMenuKey(34);
        ((Menu7*)DAT_011da634)->HandleMenuKey(35);
        ((Menu7*)DAT_011da634)->UpdateFaceGen(1, 1, 0);
        ((Menu7*)DAT_011da634)->FUN_007adc60(8, false);
        ((Menu7*)DAT_011da634)->FUN_007adc60(9, true);
    }
    else
        return;
    FUN_007adc60(7, false);
}
}  // namespace fnv_007b4b50

int __fastcall FUN_0044ddc0(void* self);
HairResult* __fastcall FUN_004ac110(void* self);
// Returns 1 if p is non-null, its FUN_0044ddc0 result is non-zero, and the holder's m_d8 hair result equals that value; otherwise 0.
// @fnv 0x007ad7f0
char __cdecl IsHairMatching(Obj0* p)
{
    int result;
    if (p != 0 && FUN_0044ddc0(p) != 0 && DAT_011da634 != 0 && ((Holder*)DAT_011da634)->m_d8 != 0 &&
        (int)FUN_004ac110(((Holder*)DAT_011da634)->m_d8) == FUN_0044ddc0(p))
        result = 1;
    else
        result = 0;
    return *(char*)&result;
}

extern Setting67 DAT_011d3288;

class HCTile
{
  public:
    HCTile* FUN_0045cd60();
    bool IsTraitNonZero(int m_iValueId);
};

class HCOption
{
  public:
    unsigned int FUN_00726070();  // GetID
    bool IsSelected();
    int FUN_0044ddc0();  // GetValue
};

class HCOptionList
{
  public:
    HCOption* FUN_007b41c0(HCTile* pkTile);
    void ApplyToAllTiles();
    int FUN_0084e3a0();
    int FUN_0044edb0();
    void FUN_007b4530(int iStep);
};

struct HCHairList
{
    void FUN_00470470();              // RemoveAll
    void FUN_005ae3d0(int& riValue);  // AddHead
};
struct HCFaceData
{
    void FUN_00613fd0();
};
struct HCFaceFlags
{
    void FUN_0047dd50(int iA, bool bB, int iC);
};

class HCNPC
{
  public:
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
    HCFaceFlags m_kFlags;  // +0x30
    HCHairList* FUN_00602170();
    HCFaceData* FUN_004ac110();
    void SetRace(int iValue, int iFlag);
    void SetHair(int iValue);
    void SetEyes(int iValue);
};

struct HCPlayerSub
{
    void FUN_008249d0(int iValue);
};
class HCPlayer
{
  public:
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
    HCPlayerSub m_kSub94;  // +0x94
    void FUN_0095e5f0();
    void ApplyActorSpells();
    void UpdateHurtReaction(int iValue);
};

struct HCName
{
    const char* FUN_00559450();
};

class HCMenuView
{
  public:
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
    HCOptionList* m_apLists[20];  // +0x28
    HCTile* m_apDefaultTiles[6];  // +0x78
    int unk090;
    int unk094;
    HCName m_kName;  // +0x98
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    HCTile* m_pkSelectedTile;      // +0xc0
    HCOption* m_pkSelectedOption;  // +0xc4
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    HCNPC* m_pkNPC;  // +0xd8
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
    int m_iNameList;  // +0x120

    int FUN_007dcc00();
    void CreateMenuOption();
    void UpdatePlayerHead();
    void UpdateHairAndEyes();
    bool FUN_007adc30(int m_iValueId);
    void RebuildFaceGen(int iValue);
    void UpdateEyeTextures();
    void UpdateFaceGen(int iA, int iB, int iC);
    bool FUN_007af180(int iValue);
    void FUN_007adc60(int m_uiSoundID, int iValue);
    void HandlePendingTileAction();
    void UpdateMinusPlusTiles();
    void FUN_007adce0(int aiIndex, HCTile* pkTile);
};

// @fnv 0x007adce0
void HCMenuView::FUN_007adce0(int aiIndex, HCTile* pkTile)
{
    if (!pkTile && aiIndex < 6)
        pkTile = m_apDefaultTiles[aiIndex];
    int iList = FUN_007dcc00();
    HCOption* pkOption = m_apLists[iList]->FUN_007b41c0(pkTile);
    if (pkOption)
    {
        bool bChangedTmp = false;
        bool bUpdatePlayer = false;
        switch (pkOption->FUN_00726070())
        {
        case 0x16:
            m_pkNPC->FUN_00602170()->FUN_00470470();
        case 0x15:
        case 0x17:
            if (!pkOption->IsSelected())
            {
                if (pkOption->FUN_00726070() == 0x17)
                {
                    m_pkNPC->FUN_004ac110()->FUN_00613fd0();
                    ((HCPlayer*)DAT_011dea3c)->FUN_0095e5f0();
                    ((HCPlayer*)DAT_011dea3c)->m_kSub94.FUN_008249d0(0);
                    ((HCPlayer*)DAT_011dea3c)->ApplyActorSpells();
                    m_pkNPC->SetRace(pkOption->FUN_0044ddc0(), 0);
                }
                else
                {
                    m_pkNPC->FUN_004ac110()->FUN_00613fd0();
                    m_pkNPC->m_kFlags.FUN_0047dd50(1, pkOption->FUN_00726070() == 0x16, 1);
                    bUpdatePlayer = true;
                }
                CreateMenuOption();
                UpdatePlayerHead();
                UpdateHairAndEyes();
                bChangedTmp = true;
                if (bUpdatePlayer)
                    ((HCPlayer*)DAT_011dea3c)->UpdateHurtReaction(1);
            }
            break;
        case 0x19:
            if (FUN_007adc30(7))
                FUN_007b51f0();
            else
                ShowMessageBox(DAT_011d3288.FUN_00403df0(), 0, 0, FUN_007b51f0, 0, 0x12, 0.0f, 0.0f,
                             DAT_011d3684.FUN_00403df0(), DAT_011d34f8.FUN_00403df0(), 0);
            break;
        case 0x1b:
            if (!pkOption->IsSelected())
            {
                m_pkNPC->SetHair(pkOption->FUN_0044ddc0());
                RebuildFaceGen(1);
                bChangedTmp = true;
            }
            break;
        case 0x21:
            if (!pkOption->IsSelected())
            {
                m_pkNPC->SetEyes(pkOption->FUN_0044ddc0());
                UpdateEyeTextures();
                bChangedTmp = true;
            }
            break;
        case 0x1c:
            m_pkNPC->FUN_00602170()->FUN_00470470();
            if (!pkOption->IsSelected())
            {
                int iValue = pkOption->FUN_0044ddc0();
                m_pkNPC->FUN_00602170()->FUN_005ae3d0(iValue);
            }
            UpdateFaceGen(1, 1, 0);
            bChangedTmp = true;
            break;
        default:
            if (pkOption->FUN_00726070() < 0x14)
                FUN_007af180(pkOption->FUN_00726070());
        }
        if (bChangedTmp)
        {
            m_apLists[iList]->ApplyToAllTiles();
            FUN_007adc60(7, 0);
        }
    }
    else if (aiIndex == 4)
    {
        FUN_007af180(m_apLists[iList]->FUN_0084e3a0());
    }
    else if (aiIndex == 5)
    {
        if (iList == m_iNameList)
            ShowMessageBox(m_kName.FUN_00559450(), 0, 0, UpdateRaceSexMenu, 1, 0x12, 0.0f, 0.0f,
                         DAT_011d3684.FUN_00403df0(), DAT_011d34f8.FUN_00403df0(), 0);
        else
            FUN_007af180(m_apLists[iList]->FUN_0044edb0());
    }
    else
    {
        pkOption = m_apLists[iList]->FUN_007b41c0(pkTile->FUN_0045cd60());
        if (pkOption)
        {
            m_pkSelectedTile = pkTile;
            m_pkSelectedOption = pkOption;
            HandlePendingTileAction();
        }
        else if (aiIndex == 2 && pkTile->IsTraitNonZero(0xfa3))
        {
            m_apLists[iList]->FUN_007b4530(1);
            UpdateMinusPlusTiles();
        }
        else if (aiIndex == 3 && pkTile->IsTraitNonZero(0xfa3))
        {
            m_apLists[iList]->FUN_007b4530(-1);
            UpdateMinusPlusTiles();
        }
    }
}

namespace fnv_007b27c0 {
class NiNode;
class NiAVObject;
class NiProperty;
class NiSourceTexture;
class BSShaderProperty;
class TESEyes;
class _FakeNiNode;
class PlayerCharacter;
class NiTimeController;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p = 0);
    ~NiPointer();
    NiPointer<T>& operator=(T* p);
    operator T*() const;
};

template <typename CharT = char> class BSStringT
{
  public:
    char* m_data;
    unsigned short m_bufLen;
    unsigned short m_strLen;
    BSStringT();
    ~BSStringT();
    operator const CharT*() const;
};

class NiFixedString
{
  public:
    operator const char*() const;
};

class NiAVObject
{
  public:
    virtual void av_00();
    virtual void av_01();
    virtual void av_02();
    virtual void av_03();
    virtual void av_04();
    virtual void av_05();
    virtual void av_06();
    virtual NiNode* GetNiNode();  // index 7, offset 0x1c
    NiFixedString& GetName();
    NiProperty* GetProperty(unsigned int);
};

class NiProperty
{
  public:
    virtual ~NiProperty();
};

class NiTimeController
{
  public:
    int FUN_00441110();
};

class BSShaderProperty : public NiProperty
{
  public:
    virtual void sp_01();
    virtual void sp_02();
    virtual void sp_03();
    virtual void sp_04();
    virtual void sp_05();
    virtual void sp_06();
    virtual void sp_07();
    virtual void sp_08();
    virtual void sp_09();
    virtual void sp_10();
    virtual void sp_11();
    virtual void sp_12();
    virtual void sp_13();
    virtual void sp_14();
    virtual void sp_15();
    virtual void sp_16();
    virtual void sp_17();
    virtual void sp_18();
    virtual void sp_19();
    virtual void sp_20();
    virtual void sp_21();
    virtual void sp_22();
    virtual void sp_23();
    virtual void sp_24();
    virtual void sp_25();
    virtual void sp_26();
    virtual void sp_27();
    virtual void sp_28();
    virtual void sp_29();
    virtual void sp_30();
    virtual void sp_31();
    virtual void sp_32();
    virtual void sp_33();
    virtual void sp_34();
    virtual void sp_35();
    virtual void sp_36();
    virtual void sp_37();
    virtual void sp_38();
    virtual void sp_39();
    virtual void sp_40();
    virtual void sp_41();
    virtual void sp_42();
    virtual void sp_43();
    virtual void sp_44();
    virtual void sp_45();
    virtual void sp_46();
    virtual void sp_47();
    virtual void sp_48();
    virtual void sp_49();
    virtual void sp_50();
    virtual void sp_51();
    virtual void sp_52();
    virtual void sp_53();
    virtual void sp_54();
    virtual void sp_55();
    virtual void sp_56();
    virtual void sp_57();
    virtual void sp_58();
    virtual void sp_59();
    virtual void SetTexture(int, int, NiSourceTexture*);  // index 60, offset 0xf0
};

class _FakeNiNode
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};

class PlayerCharacter
{
  public:
    virtual void pc_000();
    virtual void pc_001();
    virtual void pc_002();
    virtual void pc_003();
    virtual void pc_004();
    virtual void pc_005();
    virtual void pc_006();
    virtual void pc_007();
    virtual void pc_008();
    virtual void pc_009();
    virtual void pc_010();
    virtual void pc_011();
    virtual void pc_012();
    virtual void pc_013();
    virtual void pc_014();
    virtual void pc_015();
    virtual void pc_016();
    virtual void pc_017();
    virtual void pc_018();
    virtual void pc_019();
    virtual void pc_020();
    virtual void pc_021();
    virtual void pc_022();
    virtual void pc_023();
    virtual void pc_024();
    virtual void pc_025();
    virtual void pc_026();
    virtual void pc_027();
    virtual void pc_028();
    virtual void pc_029();
    virtual void pc_030();
    virtual void pc_031();
    virtual void pc_032();
    virtual void pc_033();
    virtual void pc_034();
    virtual void pc_035();
    virtual void pc_036();
    virtual void pc_037();
    virtual void pc_038();
    virtual void pc_039();
    virtual void pc_040();
    virtual void pc_041();
    virtual void pc_042();
    virtual void pc_043();
    virtual void pc_044();
    virtual void pc_045();
    virtual void pc_046();
    virtual void pc_047();
    virtual void pc_048();
    virtual void pc_049();
    virtual void pc_050();
    virtual void pc_051();
    virtual void pc_052();
    virtual void pc_053();
    virtual void pc_054();
    virtual void pc_055();
    virtual void pc_056();
    virtual void pc_057();
    virtual void pc_058();
    virtual void pc_059();
    virtual void pc_060();
    virtual void pc_061();
    virtual void pc_062();
    virtual void pc_063();
    virtual void pc_064();
    virtual void pc_065();
    virtual void pc_066();
    virtual void pc_067();
    virtual void pc_068();
    virtual void pc_069();
    virtual void pc_070();
    virtual void pc_071();
    virtual void pc_072();
    virtual void pc_073();
    virtual void pc_074();
    virtual void pc_075();
    virtual void pc_076();
    virtual void pc_077();
    virtual void pc_078();
    virtual void pc_079();
    virtual void pc_080();
    virtual void pc_081();
    virtual void pc_082();
    virtual void pc_083();
    virtual void pc_084();
    virtual void pc_085();
    virtual void pc_086();
    virtual void pc_087();
    virtual void pc_088();
    virtual void pc_089();
    virtual void pc_090();
    virtual void pc_091();
    virtual void pc_092();
    virtual void pc_093();
    virtual void pc_094();
    virtual void pc_095();
    virtual void pc_096();
    virtual void pc_097();
    virtual void pc_098();
    virtual void pc_099();
    virtual void pc_100();
    virtual void pc_101();
    virtual void pc_102();
    virtual void pc_103();
    virtual void pc_104();
    virtual void pc_105();
    virtual void pc_106();
    virtual _FakeNiNode* GetNode(bool);  // index 107, offset 0x1ac
};
extern PlayerCharacter* _g_thePlayer;

class TESEyes
{
  public:
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0c;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1c;
    int unk_20;
    TESFullName fullName;  // offset 0x24
};

class TESNPC
{
  public:
    virtual void npc_00();
    virtual void npc_01();
    virtual void npc_02();
    virtual void npc_03();
    virtual void npc_04();
    virtual void npc_05();
    virtual void npc_06();
    virtual void npc_07();
    virtual void npc_08();
    virtual void npc_09();
    virtual void npc_10();
    virtual void npc_11();
    virtual void npc_12();
    virtual void npc_13();
    virtual void npc_14();
    virtual void npc_15();
    virtual void npc_16();
    virtual void npc_17();
    virtual void MarkAsModified(unsigned int);  // index 18, offset 0x48
    TESEyes* FUN_00602150();
};

class TES
{
  public:
    void CreateTextureImage(const char*, NiPointer<NiSourceTexture>&, bool, bool);
};
extern TES* g_TES;

int __cdecl FUN_00408b20(const char*, const char*);

class RSMenuTarget
{
  public:
    int unk_000;
    int unk_004;
    int unk_008;
    int unk_00c;
    int unk_010;
    int unk_014;
    int unk_018;
    int unk_01c;
    int unk_020;
    int unk_024;
    int unk_028;
    int unk_02c;
    int unk_030;
    int unk_034;
    int unk_038;
    int unk_03c;
    int unk_040;
    int unk_044;
    int unk_048;
    int unk_04c;
    int unk_050;
    int unk_054;
    int unk_058;
    int unk_05c;
    int unk_060;
    int unk_064;
    int unk_068;
    int unk_06c;
    int unk_070;
    int unk_074;
    int unk_078;
    int unk_07c;
    int unk_080;
    int unk_084;
    int unk_088;
    int unk_08c;
    int unk_090;
    int unk_094;
    int unk_098;
    int unk_09c;
    int unk_0a0;
    int unk_0a4;
    int unk_0a8;
    int unk_0ac;
    int unk_0b0;
    int unk_0b4;
    int unk_0b8;
    int unk_0bc;
    int unk_0c0;
    int unk_0c4;
    int unk_0c8;
    int unk_0cc;
    int unk_0d0;
    int unk_0d4;
    TESNPC* m_npc;  // offset 0xd8
    void UpdateShadowSceneNode();
    bool UpdateEyeTextures();
};

// @fnv 0x007b27c0
bool RSMenuTarget::UpdateEyeTextures()
{
    NiPointer<NiNode> spEyeLeft2;
    NiPointer<NiNode> spEyeRight;

    if (!_g_thePlayer->GetNode(0))
    {
        return false;
    }

    this->m_npc->MarkAsModified(0x800);

    unsigned int childCount3 = _g_thePlayer->GetNode(0)->FUN_0043b480();
    NiAVObject* child;
    for (unsigned int aI = 0; aI < childCount3; ++aI)
    {
        child = _g_thePlayer->GetNode(0)->FUN_0043b4a0(aI);
        if (FUN_00408b20(child->GetName(), "FaceGenEyeLeft") == 0)
        {
            spEyeLeft2 = child->GetNiNode();
        }
        if (FUN_00408b20(child->GetName(), "FaceGenEyeRight") == 0)
        {
            spEyeRight = child->GetNiNode();
        }
    }

    if (spEyeLeft2 && spEyeRight)
    {
        BSStringT<char> strEyeTexture;
        if (this->m_npc->FUN_00602150())
        {
            FUN_00406f60((SpStr*)&strEyeTexture, "Textures\\%s", this->m_npc->FUN_00602150()->fullName.GetFullName());
        }
        else
        {
            FUN_00406f60((SpStr*)&strEyeTexture, "Textures\\Characters\\Eyes\\EyeDefault.dds");
        }
        NiPointer<NiSourceTexture> spTextureVal;
        g_TES->CreateTextureImage(strEyeTexture, spTextureVal, false, false);
        if (spTextureVal)
        {
            NiProperty* prop2 = ((NiAVObject*)(NiNode*)spEyeLeft2)->GetProperty(3);
            BSShaderProperty* shaderProp = (prop2 == 0 ? 0
                                                       : (((NiTimeController*)prop2)->FUN_00441110() >= 8 &&
                                                          ((NiTimeController*)prop2)->FUN_00441110() <= 12))
                                               ? (BSShaderProperty*)prop2
                                               : 0;
            if (shaderProp)
            {
                shaderProp->SetTexture(0, 0, spTextureVal);
            }
            prop2 = ((NiAVObject*)(NiNode*)spEyeRight)->GetProperty(3);
            shaderProp = (prop2 == 0 ? 0
                                     : (((NiTimeController*)prop2)->FUN_00441110() >= 8 &&
                                        ((NiTimeController*)prop2)->FUN_00441110() <= 12))
                             ? (BSShaderProperty*)prop2
                             : 0;
            if (shaderProp)
            {
                shaderProp->SetTexture(0, 0, spTextureVal);
            }
        }
    }

    this->UpdateShadowSceneNode();
    return true;
}
}  // namespace fnv_007b27c0

struct FUN_00559450_shell
{
    int FUN_00559450();
    int* FUN_0057cbe0(int*);
};

struct FUN_007b3720_shell_
{
    void FUN_007b3720(int value);
};
struct FUN_007b3660_shell
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
    FUN_00559450_shell* m40;
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
    int unkD0;
    int unkD4;
    FUN_007b3720_shell_* mD8;
    void FUN_007b3660();
    void RebuildFaceGen(int);
};
// Iterates m40's entries, reads the values of types 0x1e/0x1f/0x20 into f0/mid/hi, packs them into a 24-bit value passed to mD8, then calls RebuildFaceGen(0).
// @fnv 0x007b3660
void FUN_007b3660_shell::FUN_007b3660()
{
    int iter;
    int f0 = -1;
    int mid = -1;
    int hi = -1;
    iter = m40->FUN_00559450();
    while (iter != 0)
    {
        int u1 = *(m40->FUN_0057cbe0(&iter));
        switch (((FUN_00726070_shell*)u1)->FUN_00726070())
        {
        case 0x1e:
            f0 = ((FUN_007b3740_shell*)u1)->GetFloat1005();
            break;
        case 0x1f:
            mid = ((FUN_007b3740_shell*)u1)->GetFloat1005();
            break;
        case 0x20:
            hi = ((FUN_007b3740_shell*)u1)->GetFloat1005();
            break;
        }
    }
    mD8->FUN_007b3720((unsigned char)f0 | ((unsigned int)(unsigned char)mid << 8) |
                      ((unsigned int)(unsigned char)hi << 0x10));
    this->RebuildFaceGen(0);
}

template <class T> class FGPtr
{
  public:
    T* m_pObject;
    FGPtr(T* pObject);
    ~FGPtr();
    operator T*() const;
    T* operator->() const;
};

class FGFixedString
{
  public:
    const char* m_kHandle;
    FGFixedString(const char* pcString);
    ~FGFixedString();
};

class FGNameBuffer
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FGNameBuffer(int iSize);
    ~FGNameBuffer();
};

struct FGPoint2
{
    float x, y;
    FGPoint2();
};

struct FGLink
{
    int unk00;
    int unk04;
    int unk08;
    FGLink();
    void* FUN_00559450();
};

struct FGProperty
{
    void* FUN_006546e0();
    float FUN_009a9350();
    void FUN_00654700(float fValue);
};
struct FGShape
{
    void FUN_00539f20(void* pvData);
};
struct FGChildProperty
{
    FGShape* FUN_00a5d2c0(FGNameBuffer* pkBuffer);
};
struct FGSkin
{
    bool FUN_00a67360(int iFlag);
    void FUN_00a67410(FGLink* pkLink);
    void* FUN_00460140();
};
struct FGName
{
    const char* FUN_0043b1b0();
};

class FGNode
{
  public:
    void AssignFixedString(const FGFixedString& kName);
    void FUN_00440460(const void* pkTranslate);
    void FUN_0043fa80(const void* pkRotate);
    void FUN_00440490(float fScale);
    FGProperty* FUN_00a59d30(int iType);
    void ForwardToSubobject(FGProperty* pkProperty);
    void FUN_00439410(FGShape* pkShape);
    void FUN_00874460(int iFlags);
    unsigned short CallTargetV36();
    FGSkin* FUN_005495f0();
    void FUN_00a5a040();
};

class FGChild
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void* GetGeometryData();  // +0x1c
    FGName* FUN_00413f40();
    const void* FUN_0043c490();
    const void* FUN_006a9540();
    float GetFloatAt64();
    FGChildProperty* FUN_00a59d30(int iType);
    int FUN_004030b0();
};

class FGRoot
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
    virtual void SetAt(unsigned int uiIndex, FGNode* pkChild);  // +0xf8
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
    virtual void SetSelectiveUpdate(int iFlags);  // +0x128
    unsigned int FUN_0043b480();
    FGChild* FUN_0043b4a0(unsigned int uiIndex);
    int FUN_009611e0(int iFlag);
    void SetByteE0(int iFlag);
};

struct FGGeometry
{
    const char* GetFloatValue();
};
struct FGModel
{
    bool FUN_0065a910(FUN_00449610* pkCoords, FGPtr<FGNode>* pspNode);
};
struct FGGenerator;

int FUN_00408b20(const char* pcA, const char* pcB);
FGGeometry* FUN_006530e0(void* pvData);
FGGenerator* FUN_006521e0();
void FUN_006529a0(FGGenerator* pkGeneratorCur, FUN_00449610* pkCoords, int iA, int iB);
void GetModelNifFilename(BSStringTChar* pkOut, const char* pcPath);
void FUN_00653a10(BSStringTChar* pkOut, const char* pcPath);
void BuildModelFilename(BSStringTChar* pkOut, const char* pcPath);
void HashPathComponents(const char* pcPath, FGPoint2* pkA, FGPoint2* pkB);
int FindFileEntryInArchives(int iFlag, FGPoint2* pkA, FGPoint2* pkB, const char* pcPath);
const char* GetModelEgtFilename(BSStringTChar* pkOut, const char* pcPath);
const char* BuildTriPathAndSet(BSStringTChar* pkOut, const char* pcPath, int iIndex);
const char* BuildEgmFilename(BSStringTChar* pkOut, const char* pcPath, int iIndex);
FGModel* GetOrCreateFaceGenModel(const char* pcTri, const char* pcPath, const char* pcEgm, const char* pcEgt, int iA,
                                 int iB, int iC);
void FUN_00b57e30(FGNode* pkNode, int iA, int iB);
void ComputeBoundingSphere(void* pvData, FGLink* pkLink, unsigned short usFlags);

// For each non-FaceGenFace child, loads a model, builds a FaceGenFace node, copies transforms and shape properties, then replaces the child.
// @fnv 0x00653e50
void FUN_00653e50(FGRoot* pkRoot, int iMode)
{
    for (unsigned int i = 0; i < pkRoot->FUN_0043b480(); i++)
    {
        FGChild* pkChild = pkRoot->FUN_0043b4a0(i);
        if (pkChild)
        {
            const char* pcName = pkChild->FUN_00413f40()->FUN_0043b1b0();
            if (!FUN_00408b20(pcName, "FaceGenFace"))
            {
                void* pvGeomData = pkChild->GetGeometryData();
                FGGeometry* pkSampleGeom = FUN_006530e0(pvGeomData);
                FGPtr<FGNode> spFaceTmp(0);
                FGNode* pkFaceInfo = 0;
                BSStringTChar kModelPath;
                BSStringTChar kPathLast;
                BSStringTChar kTriPathData;
                BSStringTChar kEgmPathEntry;
                BSStringTChar kEgtPath;
                BSStringTChar kUnusedCur;
                FUN_00449610 akCoordsLocal[4];
                FGGenerator* pkGeneratorCur = FUN_006521e0();
                FUN_006529a0(pkGeneratorCur, akCoordsLocal, 0, 0);
                GetModelNifFilename(&kModelPath, pkSampleGeom->GetFloatValue());
                switch (iMode)
                {
                case 0:
                    FUN_00653a10(&kPathLast, kModelPath.FUN_00559450());
                    break;
                case 1:
                    BuildModelFilename(&kPathLast, kModelPath.FUN_00559450());
                }
                if (!kPathLast.FUN_00559450())
                    return;
                FGPoint2 kMinVal;
                FGPoint2 kMaxTotal;
                HashPathComponents(kPathLast.FUN_00559450(), &kMinVal, &kMaxTotal);
                int iFoundItem = FindFileEntryInArchives(0, &kMinVal, &kMaxTotal, kPathLast.FUN_00559450());
                if (!iFoundItem)
                    return;
                FGPtr<FGModel> m_pRenderedNodeEntry(GetOrCreateFaceGenModel(
                    BuildEgmFilename(&kTriPathData, kPathLast.FUN_00559450(), -1), kPathLast.FUN_00559450(),
                    BuildTriPathAndSet(&kEgmPathEntry, kPathLast.FUN_00559450(), -1),
                    GetModelEgtFilename(&kEgtPath, kPathLast.FUN_00559450()), 1, -1, 0));
                if (!m_pRenderedNodeEntry->FUN_0065a910(akCoordsLocal, &spFaceTmp) || !spFaceTmp)
                    return;
                spFaceTmp->AssignFixedString(FGFixedString("FaceGenFace"));
                pkFaceInfo = spFaceTmp;
                pkFaceInfo->FUN_00440460(pkChild->FUN_0043c490());
                pkFaceInfo->FUN_0043fa80(pkChild->FUN_006a9540());
                pkFaceInfo->FUN_00440490(pkChild->GetFloatAt64());
                FUN_00b57e30(pkFaceInfo, 0, 0);
                FGProperty* pkProperty = pkFaceInfo->FUN_00a59d30(3);
                FGChildProperty* pkChildPropertyValue = pkChild->FUN_00a59d30(3);
                FGNameBuffer kBufferData(0x101);
                FGShape* pkShape = pkChildPropertyValue->FUN_00a5d2c0(&kBufferData);
                pkShape->FUN_00539f20(pkProperty->FUN_006546e0());
                pkFaceInfo->ForwardToSubobject(pkProperty);
                pkFaceInfo->FUN_00439410(pkShape);
                pkFaceInfo->FUN_00874460(pkChild->FUN_004030b0());
                unsigned short usFlags = pkFaceInfo->CallTargetV36();
                if (pkFaceInfo->FUN_005495f0()->FUN_00a67360(1))
                {
                    FGLink kLink;
                    pkFaceInfo->FUN_005495f0()->FUN_00a67410(&kLink);
                    if (kLink.FUN_00559450())
                        ComputeBoundingSphere(pkFaceInfo->FUN_005495f0()->FUN_00460140(), &kLink, usFlags);
                }
                FGProperty* pkAlphaData = pkFaceInfo->FUN_00a59d30(2);
                if (pkAlphaData && pkAlphaData->FUN_009a9350() < 1.0)
                    pkAlphaData->FUN_00654700(4.0f);
                pkRoot->SetAt(i, pkFaceInfo);
                pkFaceInfo->FUN_00a5a040();
                pkRoot->SetSelectiveUpdate(pkRoot->FUN_009611e0(0));
                switch (iMode)
                {
                case 0:
                    pkRoot->SetByteE0(1);
                    break;
                case 1:
                    pkRoot->SetByteE0(0);
                }
            }
        }
    }
}

struct Manager7B3D
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    void* m_pkActive;
};

struct ListNode7B3D;

class StringList7B3D
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    int m_uiCount;

    ListNode7B3D* GetHeadPos()
    {
        return (ListNode7B3D*)reinterpret_cast<FUN_00726070_shell*>(this)->FUN_00726070();
    }
    ListNode7B3D* DereferenceIfNotNull(ListNode7B3D* pkPos);
    int CreateEntry(const char* pcText, int iA, int iB, ListNode7B3D* pkPos);
    int FUN_007b3d50(int iIndex, const char* pcText, int iA, int iB);
};

// Inserts a new entry with pcText at position iIndex in the string list, returning 0 on failure or the result of CreateEntry.
// @fnv 0x007b3d50
int StringList7B3D::FUN_007b3d50(int iIndex, const char* pcText, int iA, int iB)
{
    if (!pcText || !DAT_011da634 || !((Manager7B3D*)DAT_011da634)->m_pkActive || !m_uiCount)
    {
        return 0;
    }
    ListNode7B3D* pkPos = GetHeadPos();
    while (pkPos && iIndex)
    {
        pkPos = DereferenceIfNotNull(pkPos);
        iIndex--;
    }
    return CreateEntry(pcText, iA, iB, pkPos);
}

namespace fnv_007ac1f0 {
struct FUN_007ac1f0_base
{
    FUN_007ac1f0_base();
    virtual ~FUN_007ac1f0_base();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
};

struct Obj8
{
    Obj8();
    ~Obj8();
    unsigned int unk00;
    unsigned int unk04;
};

struct Pt12
{
    Pt12();
    float x;
    float y;
    float z;
};

struct ObjD4
{
    ObjD4(int a);
    ~ObjD4();
    unsigned int unk00;
    unsigned int unk04;
};

struct ObjDC
{
    ObjDC();
    ~ObjDC();
    unsigned int unk00;
    unsigned int unk04;
};

struct Res
{
    void FUN_004f15a0();
};

struct T12
{
    T12();
    ~T12();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Res* FUN_00418900(const T12& v);
};

struct Elem32
{
    Elem32();
    ~Elem32();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

struct MgrObj
{
    T12 ResolveAudioHandle(const char* name, unsigned int kind, bool flag);
};

MgrObj* FUN_00ad9060();
void __cdecl FUN_00403d30(void* p, int v, unsigned int n);
extern Pt12 DAT_011f426c;

class FUN_007ac1f0_cls : public FUN_007ac1f0_base
{
  public:
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
    Obj8 m_90;
    Obj8 m_98;
    Pt12 m_a0[2];
    float m_b8;
    unsigned int m_bc;
    unsigned int m_c0;
    unsigned int m_c4;
    float m_c8;
    float m_cc;
    float m_d0;
    ObjD4 m_d4;
    ObjDC m_dc;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int m_ec;
    T12 m_f0[4];
    unsigned int m_120;
    Elem32 m_124[4];

    FUN_007ac1f0_cls();
    virtual ~FUN_007ac1f0_cls();
};

// @fnv 0x007ac1f0
FUN_007ac1f0_cls::FUN_007ac1f0_cls() : m_d4(0)
{
    FUN_00403d30(&unk78, 0, 0x18);
    FUN_00403d30(&unk28, 0, 0x50);
    m_b8 = 0.0f;
    m_bc = 0;
    m_ec = 3;
    m_c8 = 0.0f;
    m_d0 = 0.0f;
    m_cc = 0.0f;
    m_a0[1] = DAT_011f426c;
    m_a0[0] = m_a0[1];
    MgrObj* mgr = FUN_00ad9060();
    m_f0[0].FUN_00418900(mgr->ResolveAudioHandle("OBJComputerTerminal01LP", 0x31, true))->FUN_004f15a0();
    m_f0[1].FUN_00418900(mgr->ResolveAudioHandle("QSTBirthRoomLP", 0x31, true))->FUN_004f15a0();
    m_f0[2].FUN_00418900(mgr->ResolveAudioHandle("UIFaceGenZoomLP", 0x31, true))->FUN_004f15a0();
    m_f0[3].FUN_00418900(mgr->ResolveAudioHandle("UIFaceGenRotateLP", 0x31, true))->FUN_004f15a0();
    m_c4 = 0;
    m_c0 = 0;
    m_120 = 0x14;
}
}  // namespace fnv_007ac1f0

namespace fnv_007ac560 {
struct Im7181
{
    void Fn7181(int);
};
Im7181* GetInterfaceMgr();

struct Proc613
{
    void Fn613();
};

struct PlayerStub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual void va5();
    virtual void va6();
    virtual void va7();
    virtual void va8();
    virtual void va9();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual void vba();
    virtual void vbb();
    virtual void vbc();
    virtual void vbd();
    virtual void vbe();
    virtual void vbf();
    virtual void vc0();
    virtual void vc1();
    virtual void vc2();
    virtual void vc3();
    virtual void vc4();
    virtual void vc5();
    virtual void vc6();
    virtual void vc7();
    virtual void vc8();
    virtual void vc9();
    virtual void vca();
    virtual void vcb();
    virtual void vcc();
    virtual void vcd();
    virtual void vce();
    virtual void vcf();
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vda();
    virtual void vdb();
    virtual void vdc();
    virtual void vdd();
    virtual void vde();
    virtual Proc613* GetProc();
};
extern PlayerStub* g_player;

struct Item7ac700
{
    int unk00;
    ~Item7ac700();
};

struct BSStr
{
    char* m_data;
    short m_len;
    short m_kMaximumCorner;
    ~BSStr();
};

struct NiPtr
{
    void* m_obj;
    ~NiPtr();
};

struct SimpleArr
{
    void* vtbl;
    void* m_data;
    int m_iElementCount;
    int m_alloc;
    int unk10;
    void Clear(bool);
    ~SimpleArr();
};

struct IdentifierState
{
    int unk00;
    int unk04;
    int unk08;
    void Stop();
    void FnAd8d10();
    ~IdentifierState();
};

struct Elem124
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ~Elem124();
};

struct MenuBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    virtual ~MenuBase();
};

struct FUN_007ac560 : MenuBase
{
    Item7ac700* m_items[20];
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BSStr m_str90;
    BSStr m_str98;
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
    NiPtr m_ptrd4;
    int unkd8;
    SimpleArr m_arrdc;
    IdentifierState m_sounds[4];
    int unk120;
    Elem124 m_pElements[4];
    virtual ~FUN_007ac560();
};

// Calls two manager and player routines, deletes m_items, clears m_arrdc, and calls Stop and FnAd8d10 on each sound state.
// @fnv 0x007ac560
FUN_007ac560::~FUN_007ac560()
{
    GetInterfaceMgr()->Fn7181(0);
    g_player->GetProc()->Fn613();
    for (int i = 0; i < 20; i++)
        delete m_items[i];
    m_arrdc.Clear(true);
    for (int j = 0; j < 4; j++)
    {
        m_sounds[j].Stop();
        m_sounds[j].FnAd8d10();
    }
}
}  // namespace fnv_007ac560
