// fallout/interface/menus/statsmenu.cpp: StatsMenu, BodyPartDisplay, ClickMenu, BGSPerk and more (87 functions)

#include "../../../statsmenu_types.h"

static const int kGetClassValue = 1003;

// @fnv 0x0071f660
int StatsMenu::GetClass()
{
    return kGetClassValue;
}

// @fnv 0x007df1f0
float ActiveEffect::GetDuration() const
{
    return fDuration;
}
// @fnv 0x007df1d0
EffectSetting* ActiveEffect::GetEffectSetting() const
{
    return pEffect->GetEffectSetting();
}
// @fnv 0x007dd8a0
bool BGSPerk::IsPerkHidden() const
{
    return Data.bHidden;
}
// @fnv 0x007ddef0
float StatsMenu::GetChartScale()
{
    return 1000.0f;
}
// @fnv 0x007dfd00
void StatsMenu::SetStatsPage(unsigned char page)
{
    if (ms_pInventoryMenu)
        ms_pInventoryMenu->SetCurrentPage(static_cast<Page>(page));
}
// Returns the current page as a Page enum, read from the menu's float value at 0x1004.
// @fnv 0x007dcc00
StatsMenu::Page StatsMenu::GetCurrentPage()
{
    return static_cast<Page>(static_cast<unsigned int>(pMenu->GetFloat(0x1004)));
}
// Maps HEALTH, ACTION_POINTS and EXPERIENCE_POINTS actor values to trait IDs 0x1009-0x100B, returning INT_MIN otherwise.
// @fnv 0x007dfdf0
int StatsMenu::GetTraitForValue(ActorValue::Index value)
{
    switch (value)
    {
    case ActorValue::ActorValue__Index_HEALTH:
        return 0x1009;
    case ActorValue::ActorValue__Index_ACTION_POINTS:
        return 0x100A;
    case ActorValue::ActorValue__Index_EXPERIENCE_POINTS:
        return 0x100B;
    default:
        return (-2147483647 - 1);
    }
}
// @fnv 0x007df5d0
void StatsMenu::UpdateStatusEffects()
{
    if (ms_pInventoryMenu && ms_pInventoryMenu->m_pTiles[37])
        ms_pInventoryMenu->m_pTiles[37]->Set(0xFC4, TESActorBaseData::GetActorDisplayName(g_thePlayer), true);
}
// @fnv 0x007dda60
void StatsMenu::ClearPerks()
{
    if (ms_pInventoryMenu && ms_pInventoryMenu->m_pTiles[34])
        ms_pInventoryMenu->m_kPerkRankList.ClearList();
}
// @fnv 0x007ddad0
void StatsMenu::RefreshMiscStat(MiscStatManager__MiscStatID value)
{
    UpdateMiscStatTile(m_kMiscStatList.GetTileForData(value), value);
}
// @fnv 0x007dcfc0
void StatsMenu::UpdateActorValueTiles()
{
    RefreshActorValueTile(ActorValue::ActorValue__Index_HEALTH);
    RefreshActorValueTile(ActorValue::ActorValue__Index_ACTION_POINTS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_EXPERIENCE_POINTS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_RADIATION_RADS);
    RefreshActorValueTile(ActorValue::ActorValue__Index_RADIATION_RESISTANCE);
    for (int value = 25; value < 32; ++value)
        RefreshActorValueTile(static_cast<ActorValue::Index>(value));
    m_pTiles[6]->Set(0x1004, 0);
    m_kPrimaryActorValueList.Traverse(UpdatePrimaryActorValueTile, 0, 2147483647);
    m_pTiles[7]->Set(0x1004, 0);
    m_kSecondaryActorValueList.Traverse(UpdateSecondaryActorValueTile, 0, 2147483647);
    RefreshActorValueTile(ActorValue::ActorValue__Index_KARMA);
}
// Sets a tile's current actor value and, if it differs from the permanent value, marks it with a (+)/(-) indicator and flags the parent.
// @fnv 0x007dfa30
void StatsMenu::UpdatePrimaryActorValueTile(Tile* tile, ActorValue::Index value)
{
    if (tile)
    {
        struct ActorValues
        {
            int current;
            int permanent;
        } values;
        values.current = g_thePlayer->GetActorValueAsInteger(value);
        values.permanent = g_thePlayer->GetPermanentActorValue(value);
        tile->Set(0x1005, values.current);
        if (values.permanent == values.current)
            tile->Set(0x1004, 0);
        else
        {
            tile->Set(0x1004, 1);
            tile->Set(0x1006, values.current > values.permanent ? "(+)" : "(-)", true);
            tile->GetParent()->Set(0x1004, 1);
        }
    }
}

// @fnv 0x007df1b0
bool EffectSetting::IsScriptEffect()
{
    return MagicEffectSystem::IsFlagSet(GetEffectArchetype(), 0x40);
}

struct TileF
{
    void Set(int, float, bool);
    void Set(int, unsigned int);
    void SetName(const char*);
};
struct ParSI
{
    float GetTotalFloat();
    float GetAccumulatedFloat();
};
struct OptSI
{
    int pad;
    const char* name;
};
struct VObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    void FUN_007d74f0(int);
    Tile* CreateListItem(OptSI*, int, int, int);
};
struct MenuSI
{
    char pad0[0x44];
    Tile* t44;
    char pad1[0x30];
    Tile* t78;
    char pad2[0x68];
    VObj e4;
    void FadeTile(int, int, unsigned int, float);
    void PopulateListBoxTiles(void*, int, int, int, bool);
};
struct ListBoxSI
{
    bool AddItem(void*);
};
struct ArrSI
{
    unsigned int GetFlags();
    OptSI*& GetAt(unsigned int);
};
extern ArrSI g_011dab88;
// Resets the menu, sets tile values from a, b, c and d, then adds each entry of g_011dab88 to lb and creates a named tile for it.
// @fnv 0x007d49a0
void MenuSI::PopulateListBoxTiles(void* apListBox, int aiValueA, int aiValueB, int auiValueC, bool abFlag)
{
    unsigned int i;
    this->e4.v7();
    this->e4.FUN_007d74f0(1);
    this->FadeTile(7, 1, 0x80000000, -1.0f);
    ((TileF*)this->t44)->Set(0xfa1, (float)(aiValueA - ((ParSI*)this->t44->GetParent())->GetTotalFloat()), true);
    ((TileF*)this->t44)->Set(0xfa2, (float)(aiValueB - ((ParSI*)this->t44->GetParent())->GetAccumulatedFloat()), true);
    ((TileF*)this->t44)->Set(0xfb1, (unsigned int)auiValueC);
    this->t78->Set(0xfa3, (int)abFlag);
    for (i = 0; i < g_011dab88.GetFlags(); i++)
    {
        if (((ListBoxSI*)g_011dab88.GetAt(i))->AddItem(apListBox))
        {
            Tile* ptile = this->e4.CreateListItem(g_011dab88.GetAt(i), 0, 0, 0);
            ptile->Set(0xfc4, g_011dab88.GetAt(i)->name, true);
            ((TileF*)ptile)->SetName(g_011dab88.GetAt(i)->name);
        }
    }
}

struct FUN_007dcc40_shell : public StatsMenu
{
    int FUN_007dcc40();
};

// @fnv 0x007dcc40
int FUN_007dcc40_shell::FUN_007dcc40()
{
    return (unsigned int)m_pTiles[5]->GetFloat(0x1004);
}

struct FUN_007df210_shell : public ActiveEffect
{
    bool FUN_007df210();
};

// @fnv 0x007df210
bool FUN_007df210_shell::FUN_007df210()
{
    return (*(int*)((char*)this + 0x18) & 0x80) != 0;
}

int __cdecl TruncateFloatToInt(float);
float __cdecl GetSkillValue(void*, int, bool);

// @fnv 0x007dfb00
void __cdecl UpdateActorValueTile(Tile* apTile, ActorValue::Index aeIndex)
{
    if (apTile)
    {
        int ival = g_thePlayer->GetActorValueAsInteger(aeIndex);
        int ibase = g_thePlayer->GetPermanentActorValue(aeIndex);
        float fderivedVal = GetSkillValue((ActorValueOwner*)g_thePlayer, aeIndex, false);
        float fderivedBase = GetSkillValue((ActorValueOwner*)g_thePlayer, aeIndex, true);
        int idelta = (ival - ibase) + TruncateFloatToInt(fderivedVal - fderivedBase);

        apTile->Set(0x1005, ival);
        if (idelta != 0)
        {
            apTile->Set(0x1004, 1);
            apTile->Set(0x1006, idelta > 0 ? "(+)" : "(-)", true);
            apTile->GetParent()->Set(0x1004, 1);
        }
        else
        {
            apTile->Set(0x1004, 0);
        }
    }
}

int __cdecl FUN_005a3370(int);

// If apTile is non-null, calls Set with 0x1005 and the result of FUN_005a3370(aeID).
// @fnv 0x007dfc60
void __cdecl FUN_007dfc60(Tile* apTile, int aeID)
{
    if (apTile)
    {
        apTile->Set(0x1005, FUN_005a3370(aeID));
    }
}

bool __fastcall FUN_004d1360(PlayerCharacter* pPlayer);
bool __cdecl FUN_004b71d0(void);
int __cdecl GetStatusResult(void);

struct DummyAVOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetActorValueI(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetPermanentActorValueI(int);
};

// Checks whether the player's current actor value is below its permanent value, choosing the target actor value based on hardcore mode and aHO[2].
// @fnv 0x007e05f0
bool __cdecl IsActorValueBelowPermanent(int* aHO)
{
    bool bIsHardcore = FUN_004d1360(g_thePlayer);
    if (aHO[2] != 0)
    {
        int etargetAV = GetStatusResult();
        if (bIsHardcore && etargetAV != -1)
        {
            return false;
        }
        else
        {
            if (bIsHardcore || !FUN_004b71d0() || etargetAV == -1)
            {
                etargetAV = 0x10;
            }
        }
        return ((DummyAVOwner*)((char*)g_thePlayer + 0xa4))->GetActorValueI(etargetAV) <
               ((DummyAVOwner*)((char*)g_thePlayer + 0xa4))->GetPermanentActorValueI(etargetAV);
    }
    else
    {
        return false;
    }
}

struct Dummy_0071f9c0
{
    void* FUN_0071f9c0(unsigned int);
};

bool __fastcall _ref_008256d0(void*);
Dummy_0071f9c0** __fastcall _ref_006815c0(void*);
void* __fastcall FUN_0071f9c0(Dummy_0071f9c0*, int, unsigned int);
void __fastcall _ref_0063f7b0(void*);

struct Caller_0071f9c0
{
    void* call_del(unsigned int f)
    {
        return FUN_0071f9c0((Dummy_0071f9c0*)this, 0, f);
    }
};

// @fnv 0x007e07f0
void __fastcall FUN_007e07f0(char* this_ptr)
{
    while (!_ref_008256d0(this_ptr + 4))
    {
        Dummy_0071f9c0* p1;
        Dummy_0071f9c0* p2 = (p1 = *_ref_006815c0(this_ptr + 4));
        (p2 != 0) ? ((void*(__thiscall*)(Dummy_0071f9c0*, unsigned int))FUN_0071f9c0)(p2, 1) : 0;
        _ref_0063f7b0(this_ptr + 4);
    }
}

struct BGSRadiationStage;
struct SpellListEntry;
struct BSCullingProcess;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderProperty;
struct FOPipboyManager;
struct FORenderedMenu;
struct ShadowLightData;
struct InventoryStackRecord;
struct NiAVObject;
struct NiAlphaProperty;
struct NiDirectionalLight;
struct NiNode;
struct SceneGraph;
struct ShadowSceneNode;
struct SpellItem;
struct TESFile;
struct TESImageSpaceModifier;
struct TileImage;
struct ViewCaster;
struct blob12
{
    char b[12];
};
struct InterfaceManager
{
    static InterfaceManager* Instance();
    static void Free();
    static void Initialize(unsigned int, bool);
    void Init(bool);
    void RefreshInterfaceState();
    SceneGraph* GetOrCreateSceneGraph(SceneGraph*, char*, bool);
    bool IsDoneFirstInit();
    bool IsDoneSecondInit();
    static void PlayUISound(int);
    SceneGraph* GetSceneGraph();
    SceneGraph* Get3DSceneGraph();
    char GetStatsPageNumber();
    char GetInventoryPageNumber();
    char GetMagicPageNumber();
    char GetMapPageNumber();
    void UpdateStatsPageNumber(char);
    void UpdateInventoryPageNumber(char);
    void UpdateMagicPageNumber(char);
    void UpdateMapPageNumber(char);
    void SetStatsPageNumber(char);
    void SetInventoryPageNumber(char);
    void SetMapPageNumber(char);
    static bool IsPipboyMenuActive();
    static bool IsInterfaceMenuActive();
    static bool IsCurrentRenderedMenuTopmost();
    int GetCurrentMainMenu();
    void SetCurrentMainMenu(int);
    void PreIdleStuff();
    void Idle();
    void ProcessGamepadInput(int);
    int GetGamepadInput(bool, bool, bool*);
    void RefreshGamepadState();
    void RefreshInputState();
    void RecursiveFade(NiAVObject*, float, float);
    Tile* GetPickTarget(bool);
    void SetPickDistance(int);
    int GetPickDistance();
    void SetTelekinesisDistance(int);
    char GetMenuMode();
    bool IsSaveLoadActive();
    void InternalSetMenuMode(int);
    void CalculateConsolePickRefs();
    void ClearMenuInput();
    int GetPickCursorX();
    int GetCursorY();
    int GetMouseWheel();
    int GetRealCursorX();
    int GetRealCursorY();
    float GetRawCursorX();
    float GetRawCursorY();
    void SetRawCursorX(float);
    void SetRawCursorY(float);
    void SetCursorPos(float, float);
    static void SetCursorAlpha(int);
    int GetCursorOffsetX();
    int GetCursorOffsetY();
    int GetTargetID();
    Tile* GetTarget();
    void SetCursorOffsetX(int);
    void SetCursorOffsetY(int);
    void SetTargetID(int);
    void SetTarget(Tile*);
    float GetMouseHeldTime();
    void SetMouseHeldTime(float);
    void Accumulate();
    void Click(BSRenderedTexture*, BSRenderedTexture*);
    TileImage* GetMouseCursorImage();
    void SwitchControllerModes(bool);
    static bool Get360ControllerDisabled();
    void Disable360Controller(bool);
    bool GetMouseVisible();
    void ToggleMouseVisible();
    void SetDebugTextVisible(bool);
    bool GetDebugTextVisible();
    NiNode* GetInterfaceNode();
    Tile* GetCursor();
    NiNode* GetCursorRoot();
    NiNode* GetPlayerRoot();
    Tile* GetPrimaryInterfaceTile();
    Tile* GetSecondaryInterfaceTile();
    void SetStringRoot(Tile*);
    NiNode* GetDebugTextRoot();
    float GetOneToOneDistance();
    ShadowSceneNode* GetShadowNode();
    BSShaderAccumulator* GetAccumulator();
    BSShaderAccumulator* Get3dAccumulator();
    TESImageSpaceModifier* GetImageSpaceModifier();
    void SetMenuFocusEnabled(bool);
    Tile* GetCurrentFocusTarget();
    void ClearInterfaceState(Tile*, int, bool);
    void ClearCurrentFocusTarget();
    void GetDefaultFocus();
    static float GetFourthInterfaceFloat();
    static float GetThirdInterfaceFloat();
    static float GetRealScreenLeft();
    static float GetRealScreenRight();
    static float GetRealScreenTop();
    static float GetRealScreenBottom();
    static float UpdateInterfaceState();
    static float GetFirstInterfaceFloat();
    static float GetScreenLeft();
    static float GetScreenRight();
    static float GetScreenTop();
    static float GetScreenBottom();
    static float GetScreenAspect();
    static float GetScreenSafeX();
    static float GetScreenSafeY();
    static float GetMenuHeight();
    static unsigned int GetLastXDefault(int);
    static int GetInputButtonCode(int, bool);
    static void SendGamepadButton(int);
    int GetDragDroppingState();
    void SetDragDroppingState(int);
    void UpdateScreenShape(int, int);
    void ToggleReticle(int);
    void ToggleSafeZone(int);
    void SetNamedMenuOption(char*, bool);
    void SetFirstChanceTextureRelease(bool);
    void ReleaseMenuTextures();
    bool IsAnyMenuOpen();
    Tile* ScanForMaxFocus(int*, Tile*);
    void SetClickMultithreaded(bool);
    bool GetClickMultithreaded();
    void SetRepeatingKey(int);
    int GetRepeatingKey(float);
    void RefreshTargetReference();
    TESObjectREFR* GetTargetREFR();
    void ClearTargetREFR();
    void SetTargetREFR(TESObjectREFR*);
    TESObjectREFR* GetPickedREFR();
    void ClearPickedREFR();
    void SetPickedREFR(TESObjectREFR*);
    TESObjectREFR* GetActivateREFR();
    TESObjectREFR* GetCurrentPickedREFR();
    struct blob12 GetActivatePickLocation();
    bool IsActivatePickFuzzy();
    void ClearActivatePickResults();
    void SetActivatePickReference(TESObjectREFR*);
    int GetActivatePickResult(int);
    int GetTopEnterStackEntry();
    int GetMenuStackEntry(int);
    int AddMenuStackEntry(int, bool);
    bool IsMenuInStack(unsigned int);
    void Test();
    NiAlphaProperty* GetAlphaProp();
    void NeedToUpdate(bool);
    unsigned short GetKeyModifiers();
    int GetChar(int, int);
    bool IsAltDown();
    bool IsControlDown();
    bool IsShiftDown();
    bool TileIsAcceptingEvents(Tile*);
    static void LocalMessgeResults();
    void FreeTimerList();
    void UpdateAllTimers();
    static void NewTimer(void*, float);
    static void ClearTimer(void*);
    static float GetTimerPercent(void*);
    void CullInterfaceMenus();
    void RestoreMenuVisibility();
    void ProcessMenuCulling(BSCullingProcess*, bool);
    void CullPipboyMenus();
    void UncullPipboyMenus();
    void UpdateMenuCulling();
    void RenderBlur(BSRenderedTexture*);
    FOPipboyManager* GetPipboyManagerInstance();
    ShaderRenderProperty* GetHUDEffects();
    ShadowLightData* GetVATSEffect();
    void SetPipboyPickResults(bool, float, float, int);
    void ClearPipboyPickResults();
    void ShowPipboy(int*, int);
    void ClosePipboy(int*);
    void UpdatePipboyState();
    void SetCurrentRenderedMenu(FORenderedMenu*);
    bool IsPipboyMenuOpen();
    FORenderedMenu* GetActiveRenderedMenu();
    void DumpMenuPackingInfo();
    float GetPipboyMouseX();
    float GetPipboyMouseY();
    void GetPipboyMouseCoords(float*, float*);
    static void RegisterListBox(ListBoxBase*);
    static void UnregisterListBox(ListBoxBase*);
    void HandleMenuTileEvent(Menu*, int, Tile*);
    void HandleMenuMouseEvent(Menu*, int, Tile*);
    void HandleMenuSelection(Menu*, int, Tile*);
    bool HandleMenuInput(Menu*, int, float);
    void AddTileIfAbsent(Tile*);
    void RemoveTileFromUpdateList(Tile*);
    void RefreshInterface();
    void QueueCloseSupportMenus();
    void UpdateQueuedMenuClosings();
    static bool Has360Controller();
    static int ConvertGamepadButton(int);
    static void SetDiskError(bool);
    static bool GetMainDiskError();
    bool QLockpickControlsDisable();
    void SetLockpickControlsDisable(bool);
    static void SetContainerMenuQueued(bool);
    static bool GetContainerMenuQueued();
    static void UpdateContainerMenu(Tile*, Tile*, Tile*, InventoryStackRecord*, bool);
    void* __vecDelDtor(unsigned int);
    bool m_bFirstStateEnabled;
    bool m_bSecondStateEnabled;
    char _pad_2[2];
    char m_kFirstStateData[4];
    char m_kSecondStateData[4];
    int m_iStateEntryCount;
    bool m_bFirstStateActive;
    bool m_bSecondStateActive;
    char m_cFirstStateCode;
    char m_cSecondStateCode;
    char m_cCurrentStateCode;
    char m_kInterfaceAdditionalData;
    char _pad_16[2];
    int m_kDisplayManagerData;
    int m_iSecondaryState;
    unsigned char m_ucFirstFlag;
    unsigned char m_ucSecondFlag;
    char _pad_22[2];
    NiDirectionalLight* m_pDirectionalLight;
    TileImage* kArgumentPosition;
    NiPoint3 m_kFirstVectorData;
    NiPoint3 m_kSecondVectorData;
    float m_fImageTileLeadingValue;
    float m_fImageTileScale;
    Tile* m_pImageTile;
    int m_iImageTileIndex;
    float m_fImageTileOpacity;
    float m_fImageTileBlendAmount;
    int m_iImageTileFirstState;
    int m_iImageTileFirstIndex;
    int m_iImageTileSecondIndex;
    int m_iTargetIndex;
    Tile* pTarget;
    char m_cTargetTextBuffer[8];
    int m_iTargetTextLength;
    bool m_bTargetTextFlag;
    bool m_kInterfaceExtensionData;
    char _pad_7e[2];
    NiNode* m_pFirstSceneNode;
    NiNode* m_pSecondSceneNode;
    ShadowSceneNode* m_pFirstShadowSceneNode;
    char m_kFirstShadowData[4];
    char m_kSecondShadowData[4];
    ShadowSceneNode* m_pSecondShadowSceneNode;
    ShadowSceneNode* m_pThirdShadowSceneNode;
    Tile* m_pFirstSceneTile;
    Tile* m_pSecondSceneTile;
    NiNode* m_pThirdSceneNode;
    float m_fSceneNodeBlendAmount;
    char m_kSceneMetadata[4];
    bool m_bCursorVisible;
    char _pad_b1[1];
    unsigned short m_usPickDistance;
    Tile* m_pFirstAuxiliaryTile;
    Tile* m_pSecondAuxiliaryTile;
    Tile* m_pThirdAuxiliaryTile;
    unsigned int m_uiAuxiliaryTileFlags;
    int m_iAuxiliaryTileIndex;
    bool m_bFirstMenuFirstFlag;
    bool m_bFirstMenuSecondFlag;
    char _pad_ca[2];
    Tile* m_pFirstMenuTile;
    Menu* m_pFirstMenu;
    Tile* m_pSecondMenuTile;
    Menu* m_pSecondMenu;
    bool m_bSecondMenuFirstFlag;
    bool m_bSecondMenuSecondFlag;
    char _pad_de[2];
    Menu* m_pThirdMenu;
    char m_cThirdMenuState;
    char _pad_e5[3];
    int* m_pMenuIndexArray;
    bool m_bFirstReferenceActive;
    bool m_bSecondReferenceActive;
    char _pad_ee[2];
    TESObjectREFR* m_pFirstReference;
    TESObjectREFR* m_pSecondReference;
    TESObjectREFR* m_pThirdReference;
    TESObjectREFR* m_pFourthReference;
    TESObjectREFR* m_pFifthReference;
    NiPoint3 m_kReferenceData;
    bool m_bActivatePickFuzzy;
    char _pad_111[3];
    char m_cPickedObjectName[40];
    ViewCaster* m_pViewCaster;
    MobileObject* m_pFirstMobileObject;
    MobileObject* m_pSecondMobileObject;
    bool m_bMouseVisible;
    bool m_bControllerModeActive;
    char _pad_14a[2];
    int m_kMenuManagerData;
    int m_kInputManagerData;
    unsigned int m_kCursorManagerData;
    unsigned int m_kReferenceManagerData;
    int m_iValueBetweenReferenceAndOverlay;
    unsigned int m_kOverlayManagerData;
    void* m_ppMeasurements;
    bool m_bRenderedMenuActive;
    char _pad_169[3];
    FORenderedMenu* m_pRenderedMenu;
    bool m_bPipboyMenuActive;
    char _pad_171[3];
    FOPipboyManager* m_pPipboyManager;
    char HUDEffects[100];
    char VATSEffect[452];
    float m_fHUDEffectTime;
    float m_fVATSEffectTime;
    bool m_bVATEffectActive;
    char _pad_3a9[3];
    int m_iHUDEffectState;
    int m_iVATEffectState;
    int* m_pInterfaceIntegerData;
    char m_cDebugTextBuffer[8];
    bool m_bDebugInfoVisible;
    bool m_bDebugTextVisible;
    char _pad_3c2[2];
    float m_fDebugTextScale;
    bool m_bDebugOverlayVisible;
    char _pad_3c9[3];
    char m_kInterfaceStateData[172];
};
typedef char _sizecheck_InterfaceManager[sizeof(InterfaceManager) == 1144 ? 1 : -1];

struct VDtor
{
    virtual ~VDtor();
};
struct MenuV
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
    virtual int v0d();
};
struct LBV
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(void* callback);
};
struct StartMenu
{
    const char* GetMenuTitle();
};
struct P09AV
{
    static bool __cdecl GetFlag(int, unsigned int);
};
struct FNStub
{
    const char* GetFullName();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct IMH
{
    Tile* FUN_00586150();
};
struct BGSDefaultObjectManager
{
    static TESForm* __cdecl GetDefaultObjectByIndex(int);
};
struct BSStringTChar : public BSStringT<char>
{
    using BSStringT<char>::operator=;
    BSStringTChar& operator+=(const char* text);
    BSStringTChar& AppendString(const BSStringT<char>& other);
    unsigned int GetLength() const;
    operator const char*() const;
};
class MagicItem : public TESFullName
{
};
class SpellItem : public TESForm
{
};
class AlchemyItem : public TESForm
{
};
struct BGSRadiationStage
{
    static BGSRadiationStage* __cdecl GetStageForLevel(float level);
    SpellItem* GetSpell();
};
struct BGSDehydrationStage
{
    static BGSDehydrationStage* __cdecl FindStage(float level);
    SpellItem* GetSpell();
};
struct BGSSleepDeprevationStage
{
    SpellItem* GetSpell();
};
struct BGSHungerStage
{
    SpellItem* GetSpell();
};
struct GameSettingString
{
    const char* GetString();
};
struct EquipTypeComponent
{
    int GetEquipType();
};
template <class T> class BSSimpleListEx : public BSSimpleList<T>
{
  public:
    int GetSize();
};
class StatsMenu__StatusEffect
{
  public:
    class EffectDataList : public BSSimpleListEx<MagicEffectEntry*>
    {
      public:
        virtual ~EffectDataList();
        void ApplyParamToEntry(ActiveEffect* effect);
    };
    class NamedEffectsList : public BSSimpleListEx<EffectSetting*>
    {
      public:
        virtual ~NamedEffectsList();
    };
    TESForm* pForm;
    EffectDataList xEffectData;
    NamedEffectsList m_kNamedEffectsList;
    StatsMenu__StatusEffect(SpellItem* spell);
    ~StatsMenu__StatusEffect();
};
class StatusEffectListOps : public BSSimpleList<StatsMenu__StatusEffect*>
{
  public:
    virtual ~StatusEffectListOps();
    void FUN_007e07f0();
    void AddEffectToGroup(ActiveEffect* effect);
};
struct StatusEffectListBox : public ListBox_StatsMenu__StatusEffect___
{
    Tile* AddItem(StatsMenu__StatusEffect* item, int a, int b, int c);
    int GetNumItems();
    void Synchronize();
};
struct MagicTargetVT : public MagicTarget
{
    virtual void Unk_01();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
};
struct ActorMagicTargetView : public MobileObject, public MagicCaster, public MagicTargetVT
{
};
struct ActiveEffectOps : public ActiveEffect
{
    bool FUN_00833c20();
    EffectItem* GetEffectItem();
    MagicItem* GetMagicItem();
    int GetSpellType();
    bool FUN_007df210();
};
struct EffectItemOps : public EffectItem
{
    bool IsScriptBasedEffect();
    bool FUN_00403ee0();
    int GetAffectedActorValue();
};
struct EffectSettingOps : public EffectSetting
{
    bool IsFlagSet(unsigned int flag);
    BSStringTChar GetEffectName() const;
};
struct TileOps : public Tile
{
    void ResetImage();
    void FUN_007df120(BSStringT<char>& name);
    void Set(int trait, float value, bool clearActions);
};
struct MenuOps : public Menu
{
    Tile* CreateTileFromTemplate(Tile* parent, const char* templateName, Tile* insertBefore);
};
struct TESFullNameOps : public TESFullName
{
    const char* GetFullName();
};
struct StatsMenuActiveEffects : public StatsMenu
{
    void FUN_007ddf00();
};

struct ActorValueUtility
{
    static int __cdecl ConvertActorValue(int);
};
struct AVH
{
    static const char* __cdecl GetActorValueName(ActorValue::Index);
    static ActorValue::Index __cdecl GetActorValueForSectionIndex(int, unsigned char);
    static unsigned int __cdecl GetCountForSection(int);
};
struct TutorialState
{
    bool ShowMessage(int, int, unsigned int);
};
struct LBH
{
    void Initialize(Tile*, const char*);
    Tile* AddListEntry(int, int, int, int);
    Tile* FUN_007e1190(int, int, int, int);
};
struct TESReputation
{
    static unsigned int* __cdecl GetUnsignedIntegerPointer(unsigned int*);
};
struct MenuH
{
    void FUN_00867a20();
    static bool __cdecl ReadMenuDefinition(const char*, Menu*);
    void SetMenuVisibility(bool);
    void SetTileMenu(TileMenu*, bool);
    int _ref_00726070();
    bool HasAllSlots();
    void UpdateXboxButtonState();
};
struct ActorH
{
    unsigned short GetLevel();
};
struct Calendar
{
    unsigned int GetDaysPassed();
};
struct TileH
{
    void SetName(const char*);
    Tile* ReadFile(const char*);
    Menu* GetMenu();
    static float __cdecl GetInterfaceScale();
    void Set(int, float, bool);
    void Set(int, unsigned int);
};
struct StatusH
{
    void FUN_007db250(Tile*);
    void SetFieldBits(int, int);
};
struct StrH
{
    void FUN_007b52a0();
};

struct Flt
{
    operator unsigned int() const;
};
int __cdecl FUN_005a3370(int);

void* __cdecl FUN_004b7210();
int __cdecl FUN_004d5e00();
void __cdecl _FNV_Warning(const char*, ...);
const char* __cdecl GetGameSettingString(int);
void __cdecl CompareActorValueNames();
StatusH* __stdcall FUN_007db1c0(int);
void __cdecl FUN_007dd710();
void __cdecl UpdateStatsMenuLevelText();
bool __cdecl IsActorValueBelowPermanent(int*);
bool __cdecl IsHealingOptionAvailable(int*);
bool __cdecl IsPlayerSubObjectValueAboveThreshold(int*);
int __cdecl GetTileValueID(const char*, int);
Menu* __cdecl FindMenuById(int);
extern double _DAT_010704f0;
extern double _DAT_010704e8;
extern const char DAT_01019f08[];
extern const char _DAT_0106ed20[];
extern GlobalObject2_0040c150 g_011d0c60;
extern StartMenu g_011d1f08;
extern StartMenu g_011d1f5c;
extern StartMenu g_011d246c;
extern StartMenu g_011d2994;
extern StartMenu g_011d2e80;
extern StartMenu g_011d2ebc;
extern StartMenu g_011d2f88;
extern StartMenu g_011d30c0;
extern StartMenu g_011d37c8;
extern StartMenu g_011d3b08;
extern StartMenu g_011d3bd4;
extern StartMenu g_011d3e74;
extern StartMenu g_011d3fdc;
extern StartMenu g_011d41bc;
extern StartMenu g_011d44a4;
extern StartMenu g_011d472c;
extern StartMenu g_011d47ec;
extern StartMenu g_011d48d0;
extern StartMenu g_011d4bd0;
extern StartMenu g_011d4ef4;
extern StartMenu g_011d50b0;

// @fnv 0x007da2c0
Tile* FUN_007da2c0()
{
    Menu* pold_menu_tile = FindMenuById(FUN_004d5e00());
    if (pold_menu_tile)
        delete (VDtor*)pold_menu_tile;
    InterfaceManager* pin = (InterfaceManager*)FUN_004b7210();
    float ftop_depth = TileH::GetInterfaceScale();
    Tile* ptile = ((TileH*)((IMH*)pin)->FUN_00586150())->ReadFile("Data\\Menus\\Main\\stats_menu.xml");
    StatsMenu::ms_pInventoryMenu = (StatsMenu*)((TileH*)ptile)->GetMenu();
    MenuH::ReadMenuDefinition("Data\\Menus\\Main\\stats_menu.xml", StatsMenu::ms_pInventoryMenu);
    ((MenuH*)StatsMenu::ms_pInventoryMenu)->FUN_00867a20();
    if (StatsMenu::ms_pInventoryMenu && ((MenuV*)StatsMenu::ms_pInventoryMenu)->v0d() == FUN_004d5e00())
    {
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->SetTileMenu((TileMenu*)ptile, false);
        if (!((MenuH*)StatsMenu::ms_pInventoryMenu)->HasAllSlots())
        {
            _FNV_Warning("MENUS: Stats Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (ptile->GetFloat(0xfa7) == _DAT_010704f0 || ptile->GetFloat(0xfa7) == _DAT_010704e8)
            ((TileH*)ptile)->Set(0xfad, ftop_depth, true);
        ((TutorialState*)((char*)FUN_004b7210() + 0x4d4))->ShowMessage(0x19, FUN_004d5e00(), 0x200);
        UpdateStatsMenuLevelText();
        BGSRadiationStage* pstage = BGSRadiationStage::GetStageForLevel(3.402823466e+38F);
        ((TileH*)ptile)->Set(0x1006, pstage ? ((Calendar*)pstage)->GetDaysPassed() : 1000);
        BSStringT<char> strtmp;
        const char* pformat = "%d/%d";
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)0x10),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)0x10));
        ptile->Set(0x1009, (const char*)(unsigned int)*(Flt*)&strtmp, true);
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)0xc),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)0xc));
        ptile->Set(0x100a, (const char*)(unsigned int)*(Flt*)&strtmp, true);
        if (((ActorH*)g_thePlayer)->GetLevel() >= *g_011d0c60.Int())
        {
            strtmp.PrintfString(DAT_01019f08, g_011d472c.GetMenuTitle());
        }
        else
        {
            strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)0x18),
                           ActorValueUtility::ConvertActorValue(((ActorH*)g_thePlayer)->GetLevel() + 1));
        }
        ptile->Set(0x100b, (const char*)(unsigned int)*(Flt*)&strtmp, true);
        ptile->Set(0x100c, ((ActorH*)g_thePlayer)->GetLevel());
        strtmp = "stats_list_template";
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPrimaryActorValueList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[6], (const char*)(unsigned int)*(Flt*)&strtmp);
        for (int i = 0; i < AVH::GetCountForSection(0); i++)
        {
            ActorValue::Index eindex = AVH::GetActorValueForSectionIndex(0, (unsigned char)i);
            if (!P09AV::GetFlag(eindex, 0x2000) && eindex != 0x1f)
            {
                Tile* ptmp =
                    ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPrimaryActorValueList)->AddListEntry(eindex, 0, 0, 0);
                ptmp->Set(0xfc4, AVH::GetActorValueName(eindex), true);
                ((TileH*)ptmp)->SetName(AVH::GetActorValueName(eindex));
            }
        }
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[7], (const char*)(unsigned int)*(Flt*)&strtmp);
        for (int i = 0; i < AVH::GetCountForSection(2); i++)
        {
            ActorValue::Index eindex = AVH::GetActorValueForSectionIndex(2, (unsigned char)i);
            if (!P09AV::GetFlag(eindex, 0x2000) && eindex != 0x1f)
            {
                Tile* ptmp =
                    ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)->AddListEntry(eindex, 0, 0, 0);
                ptmp->Set(0xfc4, AVH::GetActorValueName(eindex), true);
                ((TileH*)ptmp)->SetName(AVH::GetActorValueName(eindex));
            }
        }
        ((LBV*)&StatsMenu::ms_pInventoryMenu->m_kSecondaryActorValueList)->v08((void*)CompareActorValueNames);
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kPerkRankList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[34], (const char*)(unsigned int)*(Flt*)&strtmp);
        FUN_007dd710();
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kReputationList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[46], (const char*)(unsigned int)*(Flt*)&strtmp);
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kMiscStatList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[8], (const char*)(unsigned int)*(Flt*)&strtmp);
        for (MiscStatManager__MiscStatID eMiscStat = MiscStatManager__MiscStatID_MS_QUESTS_COMPLETED;
             eMiscStat < MiscStatManager__MiscStatID_MS_COUNT;
             TESReputation::GetUnsignedIntegerPointer((unsigned int*)&eMiscStat))
        {
            Tile* ptile = ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kMiscStatList)->FUN_007e1190(eMiscStat, 0, 0, 0);
            const char* ptext = GetGameSettingString(eMiscStat);
            ptile->Set(0xfc4, ptext, true);
            ptile->Set(0x1005, FUN_005a3370(eMiscStat));
            ((TileH*)ptile)->SetName(ptext);
        }
        StatsMenu::ms_pInventoryMenu->m_pTiles[47]->Set(0xfcc, "Interface\\shared\\solid_black.dds", true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[47]->Set(0xfa3, 0);
        TESForm* pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(0);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[10];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].pTile->Set(
            0x1004, ((FNStub*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[0].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsActorValueBelowPermanent;
        pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(0x15);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[59];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].pTile->Set(
            0x1004, ((FNStub*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[3].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsHealingOptionAvailable;
        pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(2);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[31];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[1].pTile->Set(
            0x1004, ((FNStub*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        pform = BGSDefaultObjectManager::GetDefaultObjectByIndex(3);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].m_pHealingItem = dynamic_cast<AlchemyItem*>(pform);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].pTile = StatsMenu::ms_pInventoryMenu->m_pTiles[11];
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].pTile->Set(
            0x1004, ((FNStub*)dynamic_cast<TESFullName*>(pform))->GetFullName(), true);
        StatsMenu::ms_pInventoryMenu->m_kHealingOptions[2].m_pfnIsAvailable =
            (bool___cdecl__StatsMenu__HealingOption__*)IsPlayerSubObjectValueAboveThreshold;
        ((LBH*)&StatsMenu::ms_pInventoryMenu->m_kStatusEffectList)
            ->Initialize(StatsMenu::ms_pInventoryMenu->m_pTiles[33], "stats_effects_template");
        FUN_007db1c0(0)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[12]);
        FUN_007db1c0(0)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[13]);
        FUN_007db1c0(0)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[24]);
        FUN_007db1c0(1)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[18]);
        FUN_007db1c0(1)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[19]);
        FUN_007db1c0(2)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[14]);
        FUN_007db1c0(2)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[15]);
        FUN_007db1c0(3)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[16]);
        FUN_007db1c0(3)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[17]);
        FUN_007db1c0(4)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[22]);
        FUN_007db1c0(4)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[23]);
        FUN_007db1c0(5)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[20]);
        FUN_007db1c0(5)->FUN_007db250(StatsMenu::ms_pInventoryMenu->m_pTiles[21]);
        FUN_007db1c0(0)->SetFieldBits(1, 2);
        FUN_007db1c0(0)->SetFieldBits(2, 1);
        FUN_007db1c0(0)->SetFieldBits(3, 3);
        FUN_007db1c0(2)->SetFieldBits(0, 0);
        FUN_007db1c0(2)->SetFieldBits(1, 4);
        FUN_007db1c0(2)->SetFieldBits(2, 1);
        FUN_007db1c0(2)->SetFieldBits(3, 3);
        FUN_007db1c0(1)->SetFieldBits(0, 0);
        FUN_007db1c0(1)->SetFieldBits(1, 4);
        FUN_007db1c0(1)->SetFieldBits(3, 2);
        FUN_007db1c0(3)->SetFieldBits(0, 0);
        FUN_007db1c0(3)->SetFieldBits(1, 5);
        FUN_007db1c0(3)->SetFieldBits(2, 2);
        FUN_007db1c0(4)->SetFieldBits(0, 2);
        FUN_007db1c0(4)->SetFieldBits(3, 5);
        FUN_007db1c0(5)->SetFieldBits(0, 2);
        FUN_007db1c0(5)->SetFieldBits(2, 4);
        StatsMenu::ms_pInventoryMenu->UpdateActorValueTiles();
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->UpdateXboxButtonState();
        strtmp = g_011d30c0.GetMenuTitle();
        ((StrH*)&strtmp)->FUN_007b52a0();
        ptile->Set(GetTileValueID("_rads", -1), (const char*)(unsigned int)*(Flt*)&strtmp, true);
        strtmp = g_011d1f08.GetMenuTitle();
        ((StrH*)&strtmp)->FUN_007b52a0();
        ptile->Set(GetTileValueID("_h20", -1), (const char*)(unsigned int)*(Flt*)&strtmp, true);
        strtmp = g_011d37c8.GetMenuTitle();
        ((StrH*)&strtmp)->FUN_007b52a0();
        ptile->Set(GetTileValueID("_hunger", -1), (const char*)(unsigned int)*(Flt*)&strtmp, true);
        strtmp = g_011d246c.GetMenuTitle();
        ((StrH*)&strtmp)->FUN_007b52a0();
        ptile->Set(GetTileValueID("_sleep", -1), (const char*)(unsigned int)*(Flt*)&strtmp, true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[39]->Set(0xfc4, g_011d3fdc.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[40]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d1f5c.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[41]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d50b0.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[42]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d44a4.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[43]->Set(GetTileValueID(_DAT_0106ed20, -1), g_011d3bd4.GetMenuTitle(),
                                                        true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[28]->Set(0xfc4, g_011d48d0.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[29]->Set(0xfc4, g_011d3e74.GetMenuTitle(), true);
        ptile->Set(0x100d, g_011d2e80.GetMenuTitle(), true);
        ptile->Set(0x100e, g_011d41bc.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[44]->Set(0xfc4, g_011d47ec.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[45]->Set(0xfc4, g_011d2ebc.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[0]->Set(0xfc4, g_011d2f88.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[1]->Set(0xfc4, g_011d2994.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[2]->Set(0xfc4, g_011d3b08.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[3]->Set(0xfc4, g_011d4bd0.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[4]->Set(0xfc4, g_011d4ef4.GetMenuTitle(), true);
        ((MenuH*)StatsMenu::ms_pInventoryMenu)->SetMenuVisibility(true);
        return ptile;
    }
    else
    {
        if (StatsMenu::ms_pInventoryMenu && ((MenuH*)StatsMenu::ms_pInventoryMenu)->_ref_00726070())
            delete (VDtor*)StatsMenu::ms_pInventoryMenu;
    }
    return 0;
}

namespace fnv_00404820 {
unsigned int __cdecl BSStringLength(const char*);
void* __cdecl memcpy(void*, const void*, unsigned int);
struct Flt
{
    operator unsigned int() const;
};
struct S7010
{
    unsigned int Length();
};
struct StrMem
{
    bool Set(const char*, unsigned int);
};
struct StrArg
{
    const char* p;
};
// Appends arg.p to the BSStringT, growing the buffer via Set when the combined length exceeds MaxLength, then copies the string and updates the length.
// @fnv 0x00404820
BSStringT<char>* __fastcall FUN_00404820(BSStringT<char>* self, StrArg aStrArg)
{
    unsigned int uiTotalLen;
    unsigned int uiSrcLen;
    if (aStrArg.p)
    {
        if ((unsigned int)*(Flt*)self)
        {
            uiSrcLen = aStrArg.p ? BSStringLength(aStrArg.p) : 0;
            uiTotalLen = ((S7010*)self)->Length() + uiSrcLen;
            if (uiTotalLen > self->MaxLength())
                ((StrMem*)self)->Set((const char*)(unsigned int)*(Flt*)self, uiTotalLen);
            memcpy(*(char**)self + ((S7010*)self)->Length(), aStrArg.p, uiSrcLen + 1);
            self->SetLength(uiTotalLen);
        }
        else
        {
            ((StrMem*)self)->Set(aStrArg.p, 0);
        }
    }
    return self;
}
}  // namespace fnv_00404820

namespace fnv_007dd090 {
struct Setting_S
{
    float* Float();
    const char* String();
};
struct Setting_I
{
    int* Int();
};
struct ActorValueUtility
{
    static int __cdecl ConvertActorValue(int level);
};
struct StatsMenuImpl : public StatsMenu
{
    void UpdateStatEntry(int aeWhich);
};
struct TileF
{
    void Set(int trait, float value, bool propagate);
};
struct ActorLevelHelper
{
    unsigned short GetLevel();
};
struct StatsMenuHelper
{
    Tile* FUN_00726070();
    void UpdatePipboyNeedle();
    void FUN_007ddf00();
    void UpdateOption(int mode);
    int FUN_007dfe40();
};
unsigned int __cdecl FUN_0047e040(float);
int __cdecl MinInt(int, int);
int __cdecl GetTileValueID(const char* name, int index);
extern Setting_S originalRuntimeFloatSetting1017;
extern Setting_I g_011d0c60;
extern Setting_S g_011d472c;
extern Setting_S g_011d31d4;
extern Setting_S g_011d3204;
extern Setting_S g_011d41b0;
extern Setting_S g_011d457c;
extern Setting_S g_011d4ffc;
extern const char* DAT_011a0a80[];

// Updates the stats menu tile for the given actor value: formats value text, sets image/bar tiles, and handles special cases like level, resistances, and karma.
// @fnv 0x007dd090
void StatsMenuImpl::UpdateStatEntry(int aeWhich)
{
    int eimage = 60;
    int ebar = 60;
    BSStringT<char> strtmp;
    const char* pformat = "%d/%d";

    switch (aeWhich)
    {
    case 16:
        strtmp.PrintfString("Interface\\Stats\\face_%02d.dds", ((StatsMenuHelper*)this)->FUN_007dfe40());
        m_pTiles[24]->Set(0xfcc, strtmp.String(), true);
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)16),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)16));
        ((StatsMenuHelper*)this)->FUN_00726070()->Set(GetTraitForValue((ActorValue::Index)16), strtmp.String(), true);
        ((StatsMenuHelper*)this)->UpdateOption(0);
        break;
    case 12:
        strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)12),
                       g_thePlayer->GetPermanentActorValue((ActorValue::Index)12));
        ((StatsMenuHelper*)this)->FUN_00726070()->Set(GetTraitForValue((ActorValue::Index)12), strtmp.String(), true);
        break;
    case 24:
        if (((ActorLevelHelper*)g_thePlayer)->GetLevel() >= *g_011d0c60.Int())
            strtmp.PrintfString("%s", g_011d472c.String());
        else
            strtmp.PrintfString(pformat, g_thePlayer->GetActorValue((ActorValue::Index)24),
                           ActorValueUtility::ConvertActorValue(((ActorLevelHelper*)g_thePlayer)->GetLevel() + 1));
        ((StatsMenuHelper*)this)->FUN_00726070()->Set(GetTraitForValue((ActorValue::Index)24), strtmp.String(), true);
        break;
    case 54:
        ((StatsMenuHelper*)this)->UpdatePipboyNeedle();
        ((StatsMenuHelper*)this)->UpdateOption(2);
        ((StatsMenuHelper*)this)->FUN_007ddf00();
        break;
    case 20: {
        int iresist = MinInt((int)*originalRuntimeFloatSetting1017.Float(),
                             g_thePlayer->GetActorValueAsInteger((ActorValue::Index)20));
        strtmp.PrintfString("%d%%", iresist);
        m_pTiles[38]->Set(0xfc4, strtmp.String(), true);
        ((StatsMenuHelper*)this)->FUN_007ddf00();
        break;
    }
    case 25:
        eimage = 12;
        ebar = 13;
    case 26:
        if (eimage == 60)
        {
            eimage = 14;
            ebar = 15;
        }
    case 27:
        if (eimage == 60)
        {
            eimage = 16;
            ebar = 17;
        }
    case 28:
        if (eimage == 60)
        {
            eimage = 18;
            ebar = 19;
        }
    case 29:
        if (eimage == 60)
        {
            eimage = 20;
            ebar = 21;
        }
    case 30:
        if (eimage == 60)
        {
            eimage = 22;
            ebar = 23;
        }
        {
            float fval = g_thePlayer->GetCurrentActorValue((ActorValue::Index)aeWhich) / 100.0;
            strtmp.PrintfString(fval > 0.0 ? "Interface\\Stats\\%s.dds" : "Interface\\Stats\\%s_broken.dds",
                           DAT_011a0a80[aeWhich]);
            m_pTiles[eimage]->Set(0xfcc, strtmp.String(), true);
            ((TileF*)m_pTiles[ebar])->Set(GetTileValueID("_Value", -1), fval, true);
            if (m_bUpdateOption)
                ((StatsMenuHelper*)this)->UpdateOption(0);
            break;
        }
    case 23:
        switch (FUN_0047e040(g_thePlayer->GetCurrentActorValue((ActorValue::Index)23)))
        {
        case 1:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_neutral.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d3204.String(), true);
            break;
        case 0:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_good.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d41b0.String(), true);
            break;
        case 2:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_bad.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d457c.String(), true);
            break;
        case 3:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_saintly.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d4ffc.String(), true);
            break;
        case 4:
            m_pTiles[36]->Set(0xfcc, "Interface\\Icons\\PipboyImages\\Karma icons\\karma_evil.dds", true);
            m_pTiles[35]->Set(0xfc4, g_011d31d4.String(), true);
            break;
        }
        StatsMenu::UpdateStatusEffects();
        break;
    default:
        StatsMenu::UpdatePrimaryActorValueTile(((ListBox_enum_MiscStatManager__MiscStatID_*)&m_kPrimaryActorValueList)
                                                   ->GetTileForData(*(MiscStatManager__MiscStatID*)&aeWhich),
                                               (ActorValue::Index)aeWhich);
        StatsMenu::UpdateSecondaryActorValueTile(
            ((ListBox_enum_MiscStatManager__MiscStatID_*)&m_kSecondaryActorValueList)
                ->GetTileForData(*(MiscStatManager__MiscStatID*)&aeWhich),
            (ActorValue::Index)aeWhich);
        break;
    }
}
}  // namespace fnv_007dd090

namespace fnv_007df4e0 {
struct LevelS
{
    unsigned short GetLevel();
    const char* GetFullName();
};
struct MenuActiveS
{
    const char* GetMenuTitle();
};
struct MenuTileS
{
    Tile* _ref_00726070();
};
struct GlobalObject_0040c150
{
    int x;
};
struct Flt
{
    operator unsigned int() const;
};
extern GlobalObject_0040c150 g_011d2028;

// @fnv 0x007df4e0
void UpdateStatsMenuLevelText()
{
    if (StatsMenu::ms_pInventoryMenu && g_thePlayer)
    {
        BSStringT<char> strtmp;
        strtmp.PrintfString("%s - %s %hd", ((LevelS*)g_thePlayer)->GetFullName(),
                       ((MenuActiveS*)&g_011d2028)->GetMenuTitle(), ((LevelS*)g_thePlayer)->GetLevel());
        StatsMenu::ms_pInventoryMenu->m_pTiles[27]->Set(0xfc4, (const char*)(unsigned int)*(Flt*)&strtmp, true);
        ((MenuTileS*)StatsMenu::ms_pInventoryMenu)->_ref_00726070()->Set(0x100c, ((LevelS*)g_thePlayer)->GetLevel());
    }
}
}  // namespace fnv_007df4e0

struct FUN_007dfe40_shell : public StatsMenu
{
    int FUN_007dfe40();
};

struct Script
{
    int GetText();
};
struct AEHelper
{
    bool FUN_00833c20();
};
struct NodeHelper
{
    NodeHelper* FUN_00726070();
    Script** FUN_006815c0();
};
struct EffectList
{
    virtual void v0();
    virtual void v1();
    virtual NodeHelper* GetFirst();
};
struct ValueSrc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetMax(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetCur(int);
};
extern const double DAT_01020998;

// @fnv 0x007dfe40
int FUN_007dfe40_shell::FUN_007dfe40()
{
    NodeHelper* node;
    float fdmg;
    float fmax;
    int iLevel;
    for (node = ((EffectList*)((char*)g_thePlayer + 0x94))->GetFirst(); node && *node->FUN_006815c0();
         node = node->FUN_00726070())
    {
        if ((*node->FUN_006815c0())->GetText() == 10 && ((AEHelper*)*node->FUN_006815c0())->FUN_00833c20())
            return 10;
    }
    fmax = (float)((ValueSrc*)((char*)g_thePlayer + 0xa4))->GetCur(0x10);
    fdmg = fmax - ((ValueSrc*)((char*)g_thePlayer + 0xa4))->GetMax(0x10);
    iLevel = (int)(fdmg / fmax * 5.0);
    if (iLevel < 0)
        iLevel = 0;
    if (iLevel > 4)
        iLevel = 4;
    return iLevel;
}

struct FUN_00404210_t
{
    MagicEffectEntry data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    unsigned int GetFormID();
    int FUN_00404390();
    int FUN_00404420();
    int FUN_004044d0();
    int GetAffectedActorValue();
    PerkEntryConditionSet* GetConditions();
    void FUN_00404560(unsigned int range);
    void FUN_004043d0(int magnitude);
    void FUN_00404470(int area);
    void FUN_00404510(int duration);
    void SetOwner(int actorValue);
    void FUN_00404760(PerkEntryConditionSet* conditions);
    void CopyFrom(FUN_00404210_t* apSource);
};

// @fnv 0x00404210
void FUN_00404210_t::CopyFrom(FUN_00404210_t* apSource)
{
    m_pEffectSetting = apSource->m_pEffectSetting;
    FUN_00404560(apSource->GetFormID());
    FUN_004043d0(apSource->FUN_00404390());
    FUN_00404470(apSource->FUN_00404420());
    FUN_00404510(apSource->FUN_004044d0());
    SetOwner(apSource->GetAffectedActorValue());
    FUN_00404760(apSource->GetConditions());
    m_fCost = -1.0f;
}

struct BodyPartDisplay
{
    int m_currentBodyPart;
    void SetBodyPart(int aeBodyPart, bool abFlash);
    void FUN_007dbfe0(int arg);
};

// @fnv 0x007dbfa0
void BodyPartDisplay::SetBodyPart(int aeBodyPart, bool abFlash)
{
    if (abFlash)
    {
        FUN_007dbfe0(0);
    }
    m_currentBodyPart = aeBodyPart;
    if (abFlash)
    {
        FUN_007dbfe0(1);
    }
}

namespace fnv_007dcb40 {
struct FNStub
{
    const char* GetFullName();
};
struct TESReputation
{
    const char* GetReputationName();
    const char* FUN_00616710();
};
struct FUN_007dcb40_t : public StatsMenu
{
    void SetReputationEntry(TESReputation* pRep);
};

// @fnv 0x007dcb40
void FUN_007dcb40_t::SetReputationEntry(TESReputation* pRep)
{
    if (!pRep)
        return;
    m_pTiles[47]->Set(0xfcc, pRep->GetReputationName(), true);
    m_pTiles[47]->Set(0xfa3, 1);
    m_pTiles[48]->Set(0xfa3, 1);
    m_pTiles[51]->Set(0xfa3, 1);
    m_pTiles[51]->Set(0xfc4, ((FNStub*)((char*)pRep + 0x18))->GetFullName(), true);
    m_pTiles[48]->Set(0xfc4, pRep->FUN_00616710(), true);
}
}  // namespace fnv_007dcb40

struct FOPipboyManager
{
    void SetValue(int page, bool abPlaySounds);
};
struct Interface
{
    FOPipboyManager* GetPipboyManager();
};

void* __cdecl FUN_004b7210(void);

// If a stats menu exists, gets the pipboy manager and plays sounds for the menu's current page.
// @fnv 0x007dfc90
void PlayPipboyPageSound(bool abPlaySounds)
{
    if (StatsMenu::ms_pInventoryMenu)
        reinterpret_cast<Interface*>(FUN_004b7210())
            ->GetPipboyManager()
            ->SetValue(StatsMenu::ms_pInventoryMenu->GetCurrentPage(), abPlaySounds);
}

namespace fnv_007dff40 {
struct FUN_007dff40_shell : public StatsMenu
{
    void SetPage(int);
};

void* __cdecl FUN_004b7210();
class FORenderedMenu
{
  public:
    void StartBurst(float, float, float);
    bool GetInitialized();
};
class FOPipboyManager : public FORenderedMenu
{
};
class Interface
{
  public:
    FOPipboyManager* GetPipboyManager();
};
struct VATSMenuView
{
    unsigned int FUN_00726710();
    void* FUN_007d86c0(int, int);
};
struct FUN_007dc7e0_t
{
    void UpdateStatsDisplay(int);
    void UpdateScrollBar(void*);
    void RefreshHealingOptions();
};
void __cdecl PlayPipboyPageSound(int);
struct Setting_S
{
    float* Float();
};
extern Setting_S g_011db37c;
extern Setting_S g_011db458;

// Validates aePage (0-4), updates the Pipboy menu, sets menu value 0x1004 to aePage, and applies page-specific actions.
// @fnv 0x007dff40
void FUN_007dff40_shell::SetPage(int aePage)
{
    if (aePage < 0 || aePage > 4)
        return;
    ((Interface*)FUN_004b7210())->GetPipboyManager()->StartBurst(*g_011db458.Float(), *g_011db37c.Float(), 0.5f);
    pMenu->Set(0x1004, aePage);
    if (((Interface*)FUN_004b7210())->GetPipboyManager()->GetInitialized())
        PlayPipboyPageSound(1);
    if (m_bUpdateOption)
        ((FUN_007dc7e0_t*)this)->RefreshHealingOptions();
    if (aePage == 1)
        ((FUN_007dc7e0_t*)this)->UpdateStatsDisplay(5);
    else if (aePage == 2)
        ((FUN_007dc7e0_t*)this)->UpdateStatsDisplay(0x20);
    else if (aePage == 3 && ((VATSMenuView*)&m_kPerkRankList)->FUN_00726710())
        ((FUN_007dc7e0_t*)this)->UpdateScrollBar(((VATSMenuView*)&m_kPerkRankList)->FUN_007d86c0(0, 0));
    else
        m_pTiles[25]->Set(0xfa3, 0);
}
}  // namespace fnv_007dff40

struct FUN_007e0160_t : public StatsMenu
{
    bool GetTileIndex(int aiTileID, int* apIndex);
};

// Maps a tile ID (0x1c,0x1d,0x1e,0x35,0x37,0x39) to an index written to apIndex and returns true, otherwise returns false.
// @fnv 0x007e0160
bool FUN_007e0160_t::GetTileIndex(int aiTileID, int* apIndex)
{
    switch (aiTileID)
    {
    case 0x1c:
        *apIndex = 0;
        return true;
    case 0x1d:
        *apIndex = 1;
        return true;
    case 0x1e:
        *apIndex = 2;
        return true;
    case 0x35:
        *apIndex = 3;
        return true;
    case 0x37:
        *apIndex = 4;
        return true;
    case 0x39:
        *apIndex = 5;
        return true;
    }
    return false;
}

namespace fnv_007e0510 {
class FNStub
{
  public:
    char const* GetFullName(void);
};

int __cdecl _stricmp(const char*, const char*);

// Compares the full names of the FNStub objects referenced at offset 4 of a and b using _stricmp and returns the result.
// @fnv 0x007e0510
int __cdecl CompareEntryNames(void* pEntryA, void* pEntryB)
{
    return _stricmp(((FNStub*)((char*)*(void**)((char*)pEntryA + 4) + 0x18))->GetFullName(),
                    ((FNStub*)((char*)*(void**)((char*)pEntryB + 4) + 0x18))->GetFullName());
}
}  // namespace fnv_007e0510

int __cdecl _stricmp(const char* str1, const char* str2);

struct FUN_007e0540_effect
{
    BSStringTChar GetEffectName() const;
};

// Compares the effect names of two effects case-insensitively via _stricmp and returns the result.
// @fnv 0x007e0540
int __cdecl CompareEffectNames(FUN_007e0540_effect* apEffectA, FUN_007e0540_effect* apEffectB)
{
    return _stricmp(apEffectA->GetEffectName(), apEffectB->GetEffectName());
}

bool __fastcall FUN_004d1360(PlayerCharacter* pPlayer);
int __cdecl GetStatusResult();
// @fnv 0x007e06f0
bool __cdecl IsHealingOptionAvailable(StatsMenu__HealingOption* apOption)
{
    bool bResult = FUN_004d1360(g_thePlayer);
    if (apOption->m_pStatusEffect)
    {
        int iIndex = GetStatusResult();
        if (!bResult && iIndex != -1)
            return false;
        for (int i = 0x19; i < 0x1f; i++)
        {
            if (g_thePlayer->GetActorValue((ActorValue::Index)i) <
                g_thePlayer->GetPermanentActorValue((ActorValue::Index)i))
                return true;
        }
    }
    return false;
}

namespace fnv_007e0850 {
void __fastcall _ref_0063f7b0(void*);
void** __fastcall _ref_006815c0(void*);
bool __fastcall _ref_008256d0(void*);
void __cdecl _Deallocate(void*);

// @fnv 0x007e0850
void __fastcall FUN_007e0850(void* thisPtr)
{
    void* p;
    while (!_ref_008256d0((char*)thisPtr + 4))
    {
        p = *(_ref_006815c0((char*)thisPtr + 4));
        _Deallocate(p);
        _ref_0063f7b0((char*)thisPtr + 4);
    }
}
}  // namespace fnv_007e0850

struct FUN_007e0c50_item
{
    TESForm* pForm;
};
struct FUN_007e0c50_node
{
    FUN_007e0c50_node* FUN_00726070();
    FUN_007e0c50_item*& FUN_006815c0();
};
struct FUN_007e0c50_list
{
    void** m_ppVirtualMethodTable;
    FUN_007e0c50_node xList;
    FUN_007e0c50_item* FUN_007e0c50(unsigned int formID);
};

// Walks the list nodes and returns the first item whose form's GetFormID matches formID, or null if none matches.
// @fnv 0x007e0c50
FUN_007e0c50_item* FUN_007e0c50_list::FUN_007e0c50(unsigned int formID)
{
    FUN_007e0c50_node* pNode;
    FUN_007e0c50_item* pEffect = 0;
    for (pNode = this ? &xList : 0; !pEffect && pNode && pNode->FUN_006815c0(); pNode = pNode->FUN_00726070())
    {
        if (pNode->FUN_006815c0()->pForm->GetFormID() == formID)
            pEffect = pNode->FUN_006815c0();
    }
    return pEffect;
}

namespace fnv_007e0d60 {
struct MenuH
{
    void UpdateXboxButtonState();
    void FUN_007e0d60(bool abHas360Controller);
};

// @fnv 0x007e0d60
void MenuH::FUN_007e0d60(bool abHas360Controller)
{
    MenuH::UpdateXboxButtonState();
}
}  // namespace fnv_007e0d60

// Maps an index 0-5 to a fixed code value (0x19-0x1e) via a switch, returning -1 for any other index.
// @fnv 0x007df9c0
int MapIndexToCode(int aiIndex)
{
    switch (aiIndex)
    {
    case 0:
        return 0x19;
    case 1:
        return 0x1c;
    case 2:
        return 0x1a;
    case 3:
        return 0x1b;
    case 4:
        return 0x1e;
    case 5:
        return 0x1d;
    default:
        return -1;
    }
}

// Returns the current page of the stats menu, or 0 when the menu is not open.
// @fnv 0x007dfcd0
char GetStatsMenuPage()
{
    int page;
    if (StatsMenu::ms_pInventoryMenu)
        page = StatsMenu::ms_pInventoryMenu->GetCurrentPage();
    else
        page = 0;
    return (char)page;
}

struct List_009e03e0
{
    void RemoveAll();
};

struct FUN_007e09b0_class
{
    int m;
    void FUN_007e09b0();
};

// @fnv 0x007e09b0
void FUN_007e09b0_class::FUN_007e09b0()
{
    ((List_009e03e0*)((char*)this + 4))->RemoveAll();
}

void _Deallocate(void*);

struct FUN_0071f9c0_class
{
    void FUN_0071f9f0();
    void* FUN_0071f9c0(unsigned int flags);
};

// Calls FUN_0071f9f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f9c0
void* FUN_0071f9c0_class::FUN_0071f9c0(unsigned int flags)
{
    FUN_0071f9f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct G2
{
    int d[2];
    void AddHead(int*&);
};
struct S
{
    int pad;
    G2 arr[1];
    void FUN_007db250(int idx, int* val);
};
// Calls AddHead on the element of arr at idx, passing val.
// @fnv 0x007db250
void S::FUN_007db250(int aiIndex, int* apValue)
{
    arr[aiIndex].AddHead(apValue);
}

namespace fnv_007dbfe0 {
bool __cdecl FUN_007dc040(Tile*, unsigned int);
struct Elem8
{
    int x0;
    int x1;
    void __thiscall FUN_007e0e30(bool(__cdecl*)(Tile*, unsigned int), unsigned int);
};
struct BodyPartDisplay
{
    int mIndex;
    Elem8 mElems[1];
    void FUN_007dbfe0(unsigned int);
};
// Calls FUN_007e0e30 on the element at mIndex, passing the FUN_007dc040 callback and aiOn.
// @fnv 0x007dbfe0
void BodyPartDisplay::FUN_007dbfe0(unsigned int aiOn)
{
    mElems[mIndex].FUN_007e0e30(&FUN_007dc040, aiOn);
}
}  // namespace fnv_007dbfe0

struct S_007dc010
{
    unsigned char _pad[52];
    unsigned int arr[1];
    unsigned int GetByte(unsigned int, unsigned int);
};
// Returns byte b of the 32-bit value stored at arr[a] by masking and shifting.
// @fnv 0x007dc010
unsigned int S_007dc010::GetByte(unsigned int auiIndex, unsigned int auiByteIndex)
{
    return (arr[auiIndex] & (0xFF << (auiByteIndex * 8))) >> (auiByteIndex * 8);
}

struct Struct007ddaa0
{
    char pad[0x210];
    ListBox_enum_ActorValue__Index_ lb;
    void TraverseListBox();
};
// @fnv 0x007ddaa0
void Struct007ddaa0::TraverseListBox()
{
    int unused1;
    int unused2;
    int FlushUsageData;
    lb.Traverse((void(__cdecl*)(Tile*, ActorValue::Index))StatsMenu::UpdateMiscStatTile, 0, 0x7fffffff);
}

namespace fnv_007e0b20 {
struct FUN_00403ba0
{
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
    FUN_00403ba0();
};
struct FUN_00404210_t
{
    int GetAffectedActorValue();
    int FUN_00404390();
    int FUN_004044d0();
};
struct S3e60
{
    bool FUN_00403e60(unsigned int);
};
struct G2
{
    void AddHead(int*);
};
struct FUN_007e0b20_shell
{
    int pad00;
    G2 kList;  // +0x4
    FUN_00403ba0* FindEntryByFormID(int aiActorValue);
    void AddEffectItem(EffectItem* apEffect);
};

// @fnv 0x007e0b20
void FUN_007e0b20_shell::AddEffectItem(EffectItem* apEffect)
{
    if (apEffect)
    {
        FUN_00403ba0* pEntry = FindEntryByFormID(reinterpret_cast<FUN_00404210_t*>(apEffect)->GetAffectedActorValue());
        if (pEntry)
        {
            pEntry->m_iMagnitude += reinterpret_cast<FUN_00404210_t*>(apEffect)->FUN_00404390();
        }
        else
        {
            pEntry = new FUN_00403ba0;
            pEntry->m_eAssociatedActorValue = reinterpret_cast<FUN_00404210_t*>(apEffect)->GetAffectedActorValue();
            pEntry->m_iMagnitude = reinterpret_cast<FUN_00404210_t*>(apEffect)->FUN_00404390();
            if (reinterpret_cast<S3e60*>(apEffect->GetEffectSetting())->FUN_00403e60(4))
                pEntry->m_iMagnitude *= -1;
            if (!reinterpret_cast<S3e60*>(apEffect->GetEffectSetting())->FUN_00403e60(2))
                pEntry->m_iPayloadInteger = reinterpret_cast<FUN_00404210_t*>(apEffect)->FUN_004044d0();
            kList.AddHead(reinterpret_cast<int*>(&pEntry));
        }
    }
}
}  // namespace fnv_007e0b20

struct ListX
{
    unsigned char* m_pHead;
    unsigned char* m_pTail;
    unsigned int m_uiCount;
    ~ListX();
};
struct FUN_00406de0 : ListX
{
    virtual ~FUN_00406de0();
    void FUN_007e0850();
};
// @fnv 0x00406de0
FUN_00406de0::~FUN_00406de0()
{
    FUN_007e0850();
}

struct FUN_007db270_t
{
    void SetFieldBits(unsigned int a, unsigned int c, unsigned int b);
};

// @fnv 0x007db270
void FUN_007db270_t::SetFieldBits(unsigned int auiIndex, unsigned int auiByteOffset, unsigned int auiValue)
{
    *(unsigned int*)((char*)this + 0x34 + auiIndex * 4) &= ~(0xff << (auiByteOffset << 3));
    *(unsigned int*)((char*)this + 0x34 + auiIndex * 4) |= auiValue << (auiByteOffset << 3);
}

struct FUN_007e0230_Helper
{
    void UpdateXboxButtonState();
};

bool __cdecl IsActorValueBelowPermanent(int*);
bool __cdecl IsHealingOptionAvailable(int*);

struct FUN_007e0230 : FUN_007e0230_Helper
{
    char pad[0x2a0];
    bool m_bUpdateOption;
    void RefreshHealingOptions();
};

// @fnv 0x007e0230
void FUN_007e0230::RefreshHealingOptions()
{
    m_bUpdateOption = !m_bUpdateOption;
    (*(Tile**)((char*)this + 0x2c))->Set(0xfaf, IsActorValueBelowPermanent((int*)((char*)this + 0x28)));
    (*(Tile**)((char*)this + 0x5c))->Set(0xfaf, IsHealingOptionAvailable((int*)((char*)this + 0x58)));
    UpdateXboxButtonState();
}

namespace fnv_007dcc80 {
struct StartMenu
{
    char const* GetMenuTitle();
};

struct GlobalObject2_0045cfe0 : public StartMenu
{
};

struct Struct007ddaa0
{
    void TraverseListBox();
};

struct FUN_007dd8c0_StandIn
{
    void UpdateReputationList();
};

struct FUN_007df230_StandIn
{
    void UpdateOption(int value);
};

struct FUN_007df920_StandIn
{
    void ShowWorstLimbStatus();
};

struct Tile_helper
{
    Tile* GetNamedChild(char const* name);
};

int __cdecl FUN_00408b20(char const*, char const*);
int __cdecl TraitNameToID(char const*);

extern char const* const ENGLISH;
extern const char _DAT_0106ed20[];
extern const char str_0107732c[];
extern const char str_01077340[];
extern const char str_01077358[];
extern const char str_01077368[];
extern const char str_01077378[];
extern const char str_01077388[];
extern const char str_01077398[];

extern GlobalObject2_0045cfe0 g_011c3cb4;
extern StartMenu g_011d1f08;
extern StartMenu g_011d1f5c;
extern StartMenu g_011d246c;
extern StartMenu g_011d2994;
extern StartMenu g_011d2e80;
extern StartMenu g_011d2ebc;
extern StartMenu g_011d2f88;
extern StartMenu g_011d37c8;
extern StartMenu g_011d3b08;
extern StartMenu g_011d3bd4;
extern StartMenu g_011d3e74;
extern StartMenu g_011d3fdc;
extern StartMenu g_011d41bc;
extern StartMenu g_011d44a4;
extern StartMenu g_011d47ec;
extern StartMenu g_011d48d0;
extern StartMenu g_011d4bd0;
extern StartMenu g_011d4ef4;
extern StartMenu g_011d50b0;

struct FUN_007dcc80_StandIn : public StatsMenu
{
    void InitializeStatsMenu();
};

// Calls the base menu setup routines, then if the language is English, assigns localized text to the menu's tiles by index and by name.
// @fnv 0x007dcc80
void FUN_007dcc80_StandIn::InitializeStatsMenu()
{
    this->UpdateActorValueTiles();
    reinterpret_cast<Struct007ddaa0*>(this)->TraverseListBox();
    reinterpret_cast<FUN_007dd8c0_StandIn*>(this)->UpdateReputationList();
    reinterpret_cast<FUN_007df230_StandIn*>(this)->UpdateOption(4);
    reinterpret_cast<FUN_007df920_StandIn*>(this)->ShowWorstLimbStatus();

    if (FUN_00408b20(g_011c3cb4.GetMenuTitle(), reinterpret_cast<char const*>(&ENGLISH)))
    {
        this->m_pTiles[0]->Set(0xfc4, g_011d2f88.GetMenuTitle(), true);
        this->m_pTiles[1]->Set(0xfc4, g_011d2994.GetMenuTitle(), true);
        this->m_pTiles[2]->Set(0xfc4, g_011d3b08.GetMenuTitle(), true);
        this->m_pTiles[3]->Set(0xfc4, g_011d4bd0.GetMenuTitle(), true);
        this->m_pTiles[4]->Set(0xfc4, g_011d4ef4.GetMenuTitle(), true);
        this->m_pTiles[28]->Set(0xfc4, g_011d48d0.GetMenuTitle(), true);
        this->m_pTiles[29]->Set(0xfc4, g_011d3e74.GetMenuTitle(), true);
        this->m_pTiles[53]->Set(0xfc4, g_011d1f08.GetMenuTitle(), true);
        this->m_pTiles[57]->Set(0xfc4, g_011d246c.GetMenuTitle(), true);
        this->m_pTiles[55]->Set(0xfc4, g_011d37c8.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext())
            ->Set(0x100d, g_011d2e80.GetMenuTitle(), true);

        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext())
            ->Set(0x100e, g_011d41bc.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077398)
            ->Set(0xfc4, g_011d3fdc.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077388)
            ->Set(TraitNameToID(_DAT_0106ed20), g_011d1f5c.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077378)
            ->Set(TraitNameToID(_DAT_0106ed20), g_011d50b0.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077368)
            ->Set(TraitNameToID(_DAT_0106ed20), g_011d44a4.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077358)
            ->Set(TraitNameToID(_DAT_0106ed20), g_011d3bd4.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_01077340)
            ->Set(0xfc4, g_011d47ec.GetMenuTitle(), true);

        reinterpret_cast<Tile_helper*>(reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList<Tile*>*>(this)->GetNext()))
            ->GetNamedChild(str_0107732c)
            ->Set(0xfc4, g_011d2ebc.GetMenuTitle(), true);
    }
}
}  // namespace fnv_007dcc80

namespace fnv_007e06b0 {
struct GO
{
    operator unsigned int() const;
};

typedef GO StatusH;

bool __cdecl IsStatsMenuActive();
StatusH* __stdcall FUN_007db1c0();
int __cdecl MapIndexToCode(int);

// @fnv 0x007e06b0
int __cdecl GetStatusResult()
{
    int result;

    if (IsStatsMenuActive())
        result = MapIndexToCode(static_cast<unsigned int>(*FUN_007db1c0()));
    else
        result = -1;

    return result;
}
}  // namespace fnv_007e06b0

namespace fnv_007e02b0 {
extern int __cdecl GetTileValueID(char const*, int);
extern char const $SG2844[];

class StartMenu
{
  public:
    char const* GetMenuTitle();
};

class GlobalObject_0040c150 : public StartMenu
{
};

extern StartMenu g_011d4ef4;
extern GlobalObject_0040c150 g_011d4144;

struct FUN_007e02b0_StandIn
{
    void FUN_007e02b0();
};

// @fnv 0x007e02b0
void FUN_007e02b0_StandIn::FUN_007e02b0()
{
    static int DAT_011dad88 = GetTileValueID($SG2844, -1);
    static int DAT_011dad84 = GetTileValueID("_user0", -1);
    static bool DAT_011a0ae0 = false;

    DAT_011a0ae0 = !DAT_011a0ae0;

    StatsMenu::ms_pInventoryMenu->m_pTiles[46]->Set(DAT_011dad88, DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[46]->Set(0xFA3, DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[8]->Set(DAT_011dad88, !DAT_011a0ae0);
    StatsMenu::ms_pInventoryMenu->m_pTiles[8]->Set(0xFA3, !DAT_011a0ae0);

    if (DAT_011a0ae0)
    {
        StatsMenu::ms_pInventoryMenu->m_pTiles[49]->Set(0xFC4, g_011d4ef4.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[50]->Set(0x1004, 1);
    }
    else
    {
        StatsMenu::ms_pInventoryMenu->m_pTiles[49]->Set(0xFC4, g_011d4144.GetMenuTitle(), true);
        StatsMenu::ms_pInventoryMenu->m_pTiles[50]->Set(0x1004, 0);
    }
}
}  // namespace fnv_007e02b0

struct FUN_007d35c0_Tile
{
    void Set(int, const char*, bool);
};
struct FUN_007d35c0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
struct SM7d6
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
    FUN_007d35c0_Tile* t48;
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
    int unkD8;
    int unkDC;
    int unkE0;
    FUN_007d35c0_Obj e4;
    void FUN_0075f6f0(int, bool);
};
struct GameSettingCollection_stub
{
    const char* String();
};
extern GameSettingCollection_stub g_011d4930;
extern SM7d6* DAT_011daac0;
// If DAT_011daac0 is set, calls its e4.v7, sets tile 0xfc4 text from g_011d4930.String(), and calls FUN_0075f6f0(0x4000, true).
// @fnv 0x007d35c0
void __cdecl FUN_007d35c0()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->e4.v7();
        DAT_011daac0->t48->Set(0xfc4, g_011d4930.String(), true);
        DAT_011daac0->FUN_0075f6f0(0x4000, true);
    }
}

class FUN_007db340_cls
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
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    void* m_slots[60];
    bool HasAllSlots();
};

// Returns true only if all 60 entries of m_slots are non-null, otherwise false.
// @fnv 0x007db340
bool FUN_007db340_cls::HasAllSlots()
{
    for (int i = 0; i < 60; i++)
    {
        if (m_slots[i] == 0)
        {
            return false;
        }
    }
    return true;
}

struct FUN_007db630_Entry
{
    int unk00;
    int unk04;
    bool FUN_005f65d0(int* value);
};
struct FUN_007db630_Owner
{
    int unk00;
    FUN_007db630_Entry entries[6];
    int FindEntryIndex(int value);
};
void __cdecl FUN_007dc0a0(int* value);
// Scans up to 6 entries, returning the index of the first whose FUN_005f65d0 accepts value, otherwise 6.
// @fnv 0x007db630
int FUN_007db630_Owner::FindEntryIndex(int value)
{
    int index = 0;
    for (; index < 6; FUN_007dc0a0(&index))
    {
        if (entries[index].FUN_005f65d0(&value))
            return index;
    }
    return 6;
}

extern const char UNK_01074eb8;
extern const char UNK_0106f8f8;
extern const char UNK_010702d8;
extern const char UNK_01070250;
extern double DAT_01012070;

int __cdecl TraitNameToID(const char* name);
int __cdecl FUN_0066e9f0(void* value);
int __cdecl GetActorValueDescription(void* value);
unsigned int __cdecl GetWeaponSkillIconPath(void* value);
float __cdecl FUN_00404010(float low, float high);
float __cdecl FUN_004e4430(float value);

struct ChildList007dc7e0
{
    Tile** FUN_0073ac90();
    Tile** FUN_007b5370();
};
struct TileAdapter007dc7e0
{
    void FUN_00700320(int trait, int value);
    void FUN_00a01350(int trait, int value, bool update);
    float FUN_00a011b0(int trait);
    TileAdapter007dc7e0* FUN_0045cd60();
    void FUN_00a04640(int value);
    void FUN_00a012d0(int trait, float value, bool update);
    void SetTraitAndReset(int trait, float value);
};
struct StatsMenuFunction007dc7e0 : StatsMenu
{
    void UpdateStatsDisplay(void* actor);
};
// @fnv 0x007dc7e0
void StatsMenuFunction007dc7e0::UpdateStatsDisplay(void* actor)
{
    TileAdapter007dc7e0* pMain = *(reinterpret_cast<TileAdapter007dc7e0**>(
        reinterpret_cast<ChildList007dc7e0*>((char*)m_pTiles[26] + 4)->FUN_0073ac90()));
    TileAdapter007dc7e0* second = *(reinterpret_cast<TileAdapter007dc7e0**>(
        reinterpret_cast<ChildList007dc7e0*>((char*)m_pTiles[26] + 4)->FUN_007b5370()));
    float fMinimumInputValue = second->FUN_00a011b0(TraitNameToID(&UNK_01074eb8));
    float diff = 0.0f;
    reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[25])->FUN_00700320(0xfa3, 1);
    reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[25])->FUN_00a01350(0xfcc, FUN_0066e9f0(actor), true);
    pMain->FUN_00a01350(0xfc4, GetActorValueDescription(actor), true);
    unsigned int amount = GetWeaponSkillIconPath(actor);
    if (amount > 0)
    {
        reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[52])->FUN_00700320(0xfa3, 1);
        reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[52])->FUN_00a01350(0xfcc, amount, true);
    }
    else
    {
        reinterpret_cast<TileAdapter007dc7e0*>(m_pTiles[52])->FUN_00700320(0xfa3, 0);
    }
    pMain->FUN_00a04640(0);
    diff = pMain->FUN_00a011b0(0xfb0) - pMain->FUN_0045cd60()->FUN_00a011b0(0xfb0);
    diff = FUN_00404010(0.0f, diff);
    second->FUN_00a012d0(TraitNameToID(&UNK_0106f8f8), FUN_004e4430(diff / fMinimumInputValue) + DAT_01012070, true);
    second->FUN_00a012d0(TraitNameToID(&UNK_010702d8), 0.0f, false);
    second->SetTraitAndReset(TraitNameToID(&UNK_01070250), 1.0f);
}

struct TileValue
{
    float FUN_00a011b0();
    void FUN_00a012d0(unsigned int, float, bool);
};
struct MenuItem
{
    TileValue* FUN_00726070(unsigned int);
    unsigned int menuId;
    TileValue* value;
    void FUN_007ddc20();
};
struct TraitValues
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual float GetValue(unsigned int);
};
extern void* g_011dea3c;
extern double g_01017b70, g_01011590, g_0101ff40, g_01064f50, g_01012060, g_01012070;
float __cdecl FUN_005c5420();
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_004bd510(float, float);
// @fnv 0x007ddc20
void MenuItem::FUN_007ddc20()
{
    float a = FUN_00726070(0x1008)->FUN_00a011b0() * g_01017b70;
    float c = (-a / g_01011590) + FUN_005c5420() * a;
    float d = FUN_00404010(0.0f, ((TraitValues*)((char*)g_011dea3c + 0xa4))->GetValue(0x49));
    float e = g_01064f50 - (d + c) / g_01017b70 * g_0101ff40;
    if (d > g_01012060 && d < g_01012070)
        d = 1.0f;
    else
        d = FUN_004bd510(d, 1.0f);
    value->FUN_00a012d0(0x100f, d, true);
}

namespace fnv_007ddd10 {
struct TraitSI
{
    float FUN_00a011b0();
};
struct DisplaySI
{
    void FUN_00a012d0(int, float, bool);
};
struct ActivitySI
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float v3(int);
};
extern ActivitySI* g_011dea3c;
extern double g_01017b70, g_01011590, g_0101ff40, g_01064f50, g_01012060, g_01012070;
extern double __cdecl FUN_005c5420();
extern float __cdecl FUN_00404010(float, float);
extern float __cdecl FUN_004bd510(float, float);
struct StatsMenuSI
{
    void* unk00;
    DisplaySI* unk04;
    TraitSI* FUN_00726070(int);
    void FUN_007ddd10();
};
// @fnv 0x007ddd10
void StatsMenuSI::FUN_007ddd10()
{
    float scale;

    float adjustment;
    float currentValue;
    float unusedResult;
    scale = FUN_00726070(0x1008)->FUN_00a011b0() * g_01017b70;
    adjustment = (-scale / g_01011590) + (FUN_005c5420() * scale);
    currentValue =
        FUN_00404010(0.0f, (reinterpret_cast<ActivitySI*>(reinterpret_cast<char*>(g_011dea3c) + 0xa4))->v3(0x4a));
    unusedResult = g_01064f50 - (currentValue + adjustment) / g_01017b70 * g_0101ff40;
    if (currentValue > g_01012060 && currentValue < g_01012070)
        currentValue = 1.0f;
    else
        currentValue = FUN_004bd510(currentValue, 1.0f);
    unk04->FUN_00a012d0(0x1010, currentValue, true);
}
}  // namespace fnv_007ddd10

class B7DDE00Tile
{
  public:
    float GetFloat(int m_iValueId);
    void Set(int m_iValueId, float fValue, bool bPropagate);
};

class B7DDE00ValueOwner
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual float GetActorValue(int m_eAssociatedActorValue);
};

class B7DDE00Player
{
  public:
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
    int unk098;
    int unk09C;
    int unk0A0;
    B7DDE00ValueOwner m_kAVOwner;
};

extern const double gModifierZero;

float __cdecl FUN_005c5420();
float __cdecl FUN_00404010(float fA, float fB);
float __cdecl FUN_004bd510(float fA, float fB);

class B7DDE00Menu
{
  public:
    B7DDE00Tile* GetTile();
    void UpdateModifierTile();

    int unk00;
    B7DDE00Tile* m_pkTile;
};

// @fnv 0x007dde00
void B7DDE00Menu::UpdateModifierTile()
{
    float fRange5 = GetTile()->GetFloat(0x1008) * 1000.0;
    float fOffset5 = -fRange5 / 2.0 + FUN_005c5420() * fRange5;
    float fValue = FUN_00404010(0.0f, reinterpret_cast<B7DDE00Player*>(g_thePlayer)->m_kAVOwner.GetActorValue(0x4b));
    float fAngle2 = 1.5707963267948966 - (fValue + fOffset5) / 1000.0 * 3.1415927410125732;
    if (fValue > gModifierZero && fValue < 1.0)
        fValue = 1.0f;
    else
        fValue = FUN_004bd510(fValue, 1.0f);
    m_pkTile->Set(0x1011, fValue, true);
}

// Show the status for the player's most damaged limb.

enum DF920Limb
{
    DF920_LIMB_HEAD = 0,
    DF920_LIMB_COUNT = 6
};

DF920Limb& __cdecl operator++(DF920Limb& reLimb);
int __cdecl DF920LimbToActorValue(int m_iLimbIndex);

class DF920ActorValueOwner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual float GetActorValue(int m_eAssociatedActorValue);
};

class DF920Player
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
    DF920ActorValueOwner m_kAVOwner;
};
extern DF920Player* g_pkDF920Player;

class DF920Status
{
  public:
    void Show();
};
DF920Status* __stdcall DF920GetLimbStatus(int m_iLimbIndex, int iMode);

class DF920Menu
{
  public:
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
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    unsigned char m_ucMode;

    void ShowWorstLimbStatus();
};

// Finds the limb with the lowest actor value and shows its status for the current mode.
// @fnv 0x007df920
void DF920Menu::ShowWorstLimbStatus()
{
    int iWorstLimb = DF920_LIMB_COUNT;
    float fMinValue = 3.402823466e+38f;
    for (DF920Limb m_iActionValue = DF920_LIMB_HEAD; m_iActionValue < DF920_LIMB_COUNT; ++m_iActionValue)
    {
        float fValue = g_pkDF920Player->m_kAVOwner.GetActorValue(DF920LimbToActorValue(m_iActionValue));
        if (fValue < fMinValue)
        {
            fMinValue = fValue;
            iWorstLimb = m_iActionValue;
        }
    }
    DF920GetLimbStatus(iWorstLimb, m_ucMode)->Show();
}

struct Dummy007_obj
{
    float FUN_00a011b0(int);
};

struct GlobA_007dfd20
{
    float* Get(int);
};
struct GlobB_007dfd20
{
    float* Get();
};
extern GlobA_007dfd20 DAT_011db358;
extern GlobB_007dfd20 DAT_011db2f0;

struct Obj2_007dfd20
{
    Obj2_007dfd20* FUN_00704370();
    void FUN_007f8610();
};

Obj2_007dfd20* __stdcall FUN_004b7210(int, float, float);

struct FUN_007dfd20_cls
{
    int unk00;
    void FUN_007dfd20(Dummy007_obj* apObj, unsigned int* apOut);
};

// @fnv 0x007dfd20
void FUN_007dfd20_cls::FUN_007dfd20(Dummy007_obj* apObj, unsigned int* apOut)
{
    unsigned int v = (unsigned int)apObj->FUN_00a011b0(0xfac);
    if (*apOut < v)
    {
        FUN_004b7210(0, *DAT_011db2f0.Get(), *DAT_011db358.Get(1))->FUN_00704370()->FUN_007f8610();
    }
    else if (*apOut > v)
    {
        FUN_004b7210(0, -*DAT_011db2f0.Get(), *DAT_011db358.Get(1))->FUN_00704370()->FUN_007f8610();
    }
    *apOut = v;
}

struct FUN_00408da0_obj
{
    void* FUN_00408da0();
};
extern char DAT_01183028[];
extern char DAT_01183158[];
FUN_00408da0_obj* __cdecl FUN_00ec43fb(int a, int b, const char* c, const char* d, int e);
void __cdecl FUN_00404dc0(void* a, void* b);

// Resolves the objects referenced by *pA and *pB via FUN_00ec43fb and passes their FUN_00408da0 results to FUN_00404dc0.
// @fnv 0x007e0480
void __cdecl FUN_007e0480(int* pA, int* pB)
{
    FUN_00404dc0(FUN_00ec43fb(*pA, 0, DAT_01183028, DAT_01183158, 0)->FUN_00408da0(),
                 FUN_00ec43fb(*pB, 0, DAT_01183028, DAT_01183158, 0)->FUN_00408da0());
}

struct Text
{
    const char* __thiscall FUN_00408da0();
};
struct Item
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Text text;
};
struct Holder
{
    Item* item;
};
struct Entry
{
    unsigned int unk00;
    Holder* holder;
};
int __cdecl FUN_00404dc0(const char*, const char*);
// Compares the text strings of the items referenced by two entries via FUN_00404dc0 and returns its result.
// @fnv 0x007e04e0
int __cdecl CompareEntryText(const Entry* pLeftEntry, const Entry* pRightEntry)
{
    return FUN_00404dc0(pLeftEntry->holder->item->text.FUN_00408da0(), pRightEntry->holder->item->text.FUN_00408da0());
}

extern const double DAT_01012060;

struct SubObject_b5367
{
    virtual void Unk_00();
    virtual void Unk_04();
    virtual void Unk_08();
    virtual float Unk_0C(int aiValue);
};

// Returns true when apArg[2] is nonzero and the player's sub-object at offset 0xa4 returns a value above DAT_01012060 for 0x36.
// @fnv 0x007e07a0
bool __cdecl IsPlayerSubObjectValueAboveThreshold(int* apArg)
{
    int iResult;
    if (apArg[2] != 0 && ((SubObject_b5367*)((char*)g_thePlayer + 0xa4))->Unk_0C(0x36) > DAT_01012060)
    {
        iResult = 1;
    }
    else
    {
        iResult = 0;
    }
    return *(bool*)&iResult;
}

struct S_007e0a20_Obj
{
    int FUN_00403ea0();
};

struct S_007e0a20_Param
{
    S_007e0a20_Obj* FUN_0084e3a0();
    float GetFloatAtOffset1C();
};

struct S_007e0a20_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_007e0a20_Entry();
};

struct S_007e0a20_Owner
{
    int unk00;
    BSSimpleList<S_007e0a20_Entry*> m_kNode;
    S_007e0a20_Entry* FindEntryByFormID(int);
    void ApplyParamToEntry(S_007e0a20_Param* apParam);
};

// Looks up an entry by the param's object id; adds the param's float to its unk00, or creates a new entry with that id and value and adds it to the list.
// @fnv 0x007e0a20
void S_007e0a20_Owner::ApplyParamToEntry(S_007e0a20_Param* apParam)
{
    if (apParam)
    {
        S_007e0a20_Entry* pEntry = FindEntryByFormID(apParam->FUN_0084e3a0()->FUN_00403ea0());
        if (pEntry)
        {
            pEntry->unk00 += (int)apParam->GetFloatAtOffset1C();
        }
        else
        {
            pEntry = new S_007e0a20_Entry;
            pEntry->unk10 = apParam->FUN_0084e3a0()->FUN_00403ea0();
            pEntry->unk00 = (int)apParam->GetFloatAtOffset1C();
            m_kNode.AddHead(pEntry);
        }
    }
}

struct ItemListNode;

struct ItemListEntry
{
    unsigned char unk00[0x10];
    int formID;
};

struct ItemListNode
{
    ItemListNode* Next();
    ItemListEntry** Data();
};

class ItemListOwner
{
  public:
    void** m_ppVirtualMethodTable;
    ItemListNode xList;
    ItemListEntry* FindEntryByFormID(int formID);
};

// Walks the linked list and returns the first entry whose formID matches the given formID, or null if none is found.
// @fnv 0x007e0ce0
ItemListEntry* ItemListOwner::FindEntryByFormID(int formID)
{
    ItemListEntry* found = 0;
    ItemListNode* cur = this != 0 ? &xList : 0;
    for (; found == 0 && cur != 0 && *cur->Data() != 0; cur = cur->Next())
    {
        if ((*cur->Data())->formID == formID)
        {
            found = *cur->Data();
        }
    }
    return found;
}

struct FUN_007db2c0
{
    FUN_007db2c0();
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int uTmpnk;
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
};

extern FUN_007db2c0* DAT_011dace4;

// Returns the global FUN_007db2c0 instance, allocating it with new if it does not exist yet.
// @fnv 0x007db1c0
FUN_007db2c0* FUN_007db1c0()
{
    if (!DAT_011dace4)
        DAT_011dace4 = new FUN_007db2c0();
    return DAT_011dace4;
}

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
struct ClickNode
{
    AlchemyItem*& FUN_006815c0();
    ClickNode* FUN_00726070();
};
class InventoryStackRecord
{
  public:
    ClickNode* FUN_00559450();
    void* FUN_00726070();
    TESBoundObject* FUN_0044ddc0();
};
struct ClickAlchemy
{
    int FUN_00403ea0();
};
struct ClickPlayer
{
    void EquipItem(TESBoundObject*, void*, AlchemyItem*, bool, bool, bool);
};
struct ClickTile
{
    bool IsTraitNonZero(int);
};
struct ClickStatus
{
    int FindEntryIndex();
};
struct ClickVirtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void OnClick(int, Tile*);
};
struct ClickMenu : StatsMenu
{
    void FUN_007db380(int id, Tile* tile);
    bool SetIndexFromType(int, int*);
    bool GetTileIndex(int, int*);
    void SetPage(int);
    void FUN_007e0060(int);
    void FUN_007e0230();
    void FUN_007e02b0();
    void UpdateStatEntry(int);
    void UpdateOption(int);
    void FUN_007ddf00();
};
// @fnv 0x007db380
void ClickMenu::FUN_007db380(int id, Tile* tile)
{
    if (!tile && id >= 0 && id < 60)
        tile = m_pTiles[id];
    if (FUN_004b71d0() && !((ClickTile*)tile)->IsTraitNonZero(4015))
        return;
    int skill;
    if (SetIndexFromType(id, &skill))
    {
        SetPage(skill);
        return;
    }
    int special;
    if (GetTileIndex(id, &special))
    {
        FUN_007e0060(special);
        return;
    }
    if (id == 9 || (m_bUpdateOption && id == 5))
    {
        FUN_007e0230();
        return;
    }
    if (id == 49)
    {
        FUN_007e02b0();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (tile == m_kHealingOptions[i].pTile && m_kHealingOptions[i].m_pStatusEffect)
        {
            ((ClickPlayer*)g_thePlayer)
                ->EquipItem(m_kHealingOptions[i].m_pStatusEffect->FUN_0044ddc0(),
                               m_kHealingOptions[i].m_pStatusEffect->FUN_00726070(),
                               m_kHealingOptions[i].m_pStatusEffect->FUN_00559450()
                                   ? m_kHealingOptions[i].m_pStatusEffect->FUN_00559450()->FUN_006815c0()
                                   : 0,
                               false, false, true);
            TESBoundObject* object = m_kHealingOptions[i].m_pStatusEffect->FUN_0044ddc0();
            for (ClickNode* node = (ClickNode*)dynamic_cast<BSSimpleList<EffectItem*>*>(object);
                 node && node->FUN_006815c0(); node = node->FUN_00726070())
            {
                UpdateStatEntry(((ClickAlchemy*)node->FUN_006815c0())->FUN_00403ea0());
            }
            UpdateOption(i);
            m_bStatUpdatePending = false;
            FUN_007ddf00();
            i = 4;
        }
    }
    if (m_bUpdateOption && !FUN_004b71d0())
    {
        int part = ((ClickStatus*)FUN_007db1c0((int)tile))->FindEntryIndex();
        if (part != 6)
            FUN_004d1360(g_thePlayer) ? ((ClickVirtual*)this)->OnClick(59, 0) : ((ClickVirtual*)this)->OnClick(10, 0);
    }
}

// Menu input: on the accept key with the button enabled, trigger the default action and play the OK sound.

class C0E0SoundHandle
{
  public:
    ~C0E0SoundHandle();
    bool Play();

    int m_iID;
    int unk04;
    int unk08;
};

class C0E0Audio
{
  public:
    static C0E0Audio* GetSingleton();
    C0E0SoundHandle GetSoundHandleByEditorID(const char* pcEditorID, unsigned int uiFlags, int iUnused);
};

class C0E0Tile
{
  public:
    bool GetBool(int m_iValueId);
};

class C0E0Menu
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void HandleClick(int iButton, int iUnused);

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
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    C0E0Tile* m_pkButton;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    bool m_bAcceptsInput;

    bool FUN_007dc0e0(int iKey, int iUnused);
};

// @fnv 0x007dc0e0
bool C0E0Menu::FUN_007dc0e0(int iKey, int iUnused)
{
    if (m_bAcceptsInput && iKey == 10 && m_pkButton->GetBool(0xfaf))
    {
        HandleClick(9, 0);
        C0E0Audio::GetSingleton()->GetSoundHandleByEditorID("UIMenuOK", 0x121, 0).Play();
        return true;
    }
    return false;
}

struct FORenderedMenu
{
    bool IsUnk28Set();
};
FORenderedMenu* __cdecl FUN_00705990();
void* __cdecl FUN_004b7210();
bool __cdecl FUN_007178a0();
unsigned int __cdecl FUN_00457fe0();
bool __cdecl FUN_00702450(int);
bool __fastcall FUN_004d1360(void*);
extern unsigned int DAT_011dad74;
extern void* DAT_011dea3c;
extern unsigned char DAT_011a0ae1;
struct AceObj
{
    Tile* m_tiles[0x5e];
};
extern AceObj* DAT_011dace0;

struct TileF15
{
    float FUN_00a011b0(int);
};
struct Host15 : StatsMenu
{
    void UpdatePipboyNeedle();
    void FUN_007ddc20();
    void FUN_007ddd10();
    void UpdateModifierTile();
    TileF15* FUN_00726070();
    void FUN_007e0230();
    int FUN_007dcc40();
    void FUN_007e0060(int);
    void UpdateStatsMenu();
};

// @fnv 0x007dc4f0
void Host15::UpdateStatsMenu()
{
    m_bStatUpdatePending = 0;
    if (FUN_00705990()->IsUnk28Set())
    {
        FUN_004b7210();
        if (FUN_007178a0())
        {
            if (FUN_00457fe0() >= DAT_011dad74)
            {
                UpdatePipboyNeedle();
                if (DAT_011dea3c && FUN_004d1360(DAT_011dea3c))
                {
                    FUN_007ddc20();
                    FUN_007ddd10();
                    UpdateModifierTile();
                }
                DAT_011dad74 = (unsigned int)((double)FUN_00457fe0() + FUN_00726070()->FUN_00a011b0(0x1007) * 1000.0);
            }
        }
        if (m_bUpdateOption)
        {
            if (!FUN_00702450(0x3eb))
                FUN_007e0230();
        }
    }
    if (GetCurrentPage() == 0)
    {
        if (FUN_007dcc40() > (FUN_004d1360(DAT_011dea3c) ? 5 : 2))
            FUN_007e0060(0);
    }
    if (DAT_011dea3c && !FUN_004d1360(DAT_011dea3c) && DAT_011a0ae1)
    {
        DAT_011dace0->m_tiles[0x59]->Set(0xfaf, 0);
        DAT_011dace0->m_tiles[0x59]->Set(0xfa3, 0);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfaf, 0);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfa3, 0);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfaf, 0);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfa3, 0);
        DAT_011a0ae1 = 0;
    }
    else if (DAT_011dea3c && FUN_004d1360(DAT_011dea3c) && !DAT_011a0ae1)
    {
        DAT_011dace0->m_tiles[0x59]->Set(0xfaf, 1);
        DAT_011dace0->m_tiles[0x59]->Set(0xfa3, 1);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfaf, 1);
        DAT_011dace0->m_tiles[0x5d]->Set(0xfa3, 1);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfaf, 1);
        DAT_011dace0->m_tiles[0x5b]->Set(0xfa3, 1);
    }
    DAT_011a0ae1 = FUN_004d1360(DAT_011dea3c);
}

namespace fnv_007dc9b0 {
struct ChildListSI
{
    Tile*& FUN_0073ac90();
    Tile*& FUN_007b5370();
};
struct DescSI
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* GetText(void* pForm, unsigned int chunk);
    int unk04;
};
struct FNStub
{
    const char* GetFullName();
};
struct EntrySI
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
    DescSI xDesc;
    FNStub StringProvider;
};
struct TileSI : public Tile
{
    float FUN_00a011b0(int);
    void FUN_00a04640(int);
    void FUN_00a012d0(int, float, bool);
    void SetTraitAndReset(int, float);
};
int __cdecl TraitNameToID(const char*);
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_004e4430(float);

struct FUN_007dc9b0_shell : public StatsMenu
{
    void UpdateScrollBar(EntrySI** apEntry);
};

// @fnv 0x007dc9b0
void FUN_007dc9b0_shell::UpdateScrollBar(EntrySI** apEntry)
{
    TileSI* pHeadTile = (TileSI*)((ChildListSI*)((char*)m_pTiles[26] + 4))->FUN_0073ac90();
    TileSI* pTailTile = (TileSI*)((ChildListSI*)((char*)m_pTiles[26] + 4))->FUN_007b5370();
    float fTailScrollDelta = pTailTile->FUN_00a011b0(TraitNameToID("_ScrollDelta"));
    {
        float fPos = 0.0f;
        m_pTiles[25]->Set(0xfa3, 1);
        m_pTiles[25]->Set(0xfcc, (*apEntry)->StringProvider.GetFullName(), true);
        pHeadTile->Set(0xfc4, (*apEntry)->xDesc.GetText(0, 0x43534544), true);
        pHeadTile->FUN_00a04640(0);
        fPos = pHeadTile->FUN_00a011b0(0xfb0) - ((TileSI*)pHeadTile->GetParent())->FUN_00a011b0(0xfb0);
        fPos = FUN_00404010(0.0f, fPos);
        pTailTile->FUN_00a012d0(TraitNameToID("_number_of_items"), (float)(FUN_004e4430(fPos / fTailScrollDelta) + 1.0),
                                true);
    }
    pTailTile->FUN_00a012d0(TraitNameToID("_current_value"), 0.0f, false);
    pTailTile->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
}
}  // namespace fnv_007dc9b0

namespace fnv_007dd710 {
class FUN_007dd710_str
{
  public:
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    FUN_007dd710_str();
    ~FUN_007dd710_str();
    int FUN_00559450(int(__cdecl* compare)(const void*, const void*), int flags);
};

class FUN_007dd710_text
{
  public:
    const char* FUN_00408da0();
};

class FUN_007dd710_form
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    FUN_007dd710_text m18;
    bool FUN_007dd8a0();
};

class FUN_007dd710_item
{
  public:
    FUN_007dd710_form* pForm;
    unsigned char count;
};

class FUN_007dd710_node
{
  public:
    FUN_007dd710_node* FUN_00726070();
    FUN_007dd710_item*& FUN_006815c0();
};

class FUN_007dd710_sub
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    void FUN_007e0e70(FUN_007dd710_item* item, int value);
};

class FUN_007dd710_list
{
  public:
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
    virtual void v95();
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
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual FUN_007dd710_node* GetFirst(int which);
};

class FUN_007dd710_ctx
{
  public:
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
    void* unk10C;
    void* unk110;
    void* unk114;
    int m118;
    unsigned char pad11c[0x1e0 - 0x11c];
    FUN_007dd710_sub m1e0;
};

int __cdecl CompareEntryText(const void* left, const void* right);
void __cdecl FUN_00406f60(FUN_007dd710_str* out, const char* fmt, ...);

extern FUN_007dd710_ctx* DAT_011dace0;
extern FUN_007dd710_list* DAT_011dea3c;

// @fnv 0x007dd710
void __cdecl FUN_007dd710()
{
    if (DAT_011dace0 && DAT_011dace0->m118)
    {
        DAT_011dace0->m1e0.v7();
        for (FUN_007dd710_node* node = DAT_011dea3c->GetFirst(0); node != 0 && node->FUN_006815c0() != 0;
             node = node->FUN_00726070())
        {
            if (!node->FUN_006815c0()->pForm->FUN_007dd8a0())
            {
                FUN_007dd710_str strEntry;
                if (node->FUN_006815c0()->count > 1)
                {
                    FUN_00406f60(&strEntry, "%s (%d)", node->FUN_006815c0()->pForm->m18.FUN_00408da0(),
                                 (int)node->FUN_006815c0()->count);
                }
                else
                {
                    FUN_00406f60(&strEntry, "%s", node->FUN_006815c0()->pForm->m18.FUN_00408da0());
                }
                DAT_011dace0->m1e0.FUN_007e0e70(node->FUN_006815c0(), strEntry.FUN_00559450(CompareEntryText, 0));
            }
        }
    }
}
}  // namespace fnv_007dd710

namespace fnv_007dd8c0 {
struct ReputationName
{
    const char* GetName();
};
class ReputationView : public TESForm
{
  public:
    ReputationName name;
    float GetReputation(bool fame);
};
struct ReputationNode
{
    ReputationView*& Get();
    ReputationNode* Next();
};
struct ReputationDataHandler : TESDataHandler
{
    ReputationNode* GetReputations();
};
extern ReputationDataHandler* DAT_011c3f2c;
extern StatsMenu* DAT_011dace0;
extern const double DAT_01012060;
void __cdecl CompareEntryNames(void* item);
int __cdecl FUN_00406f60(BSStringT<char>* output, const char* format, ...);

struct ReputationMenuList : ListBox_TESReputation___
{
    void Insert(ReputationView* reputation, const char* label, void(__cdecl* callback)(void*), bool selected);
};

struct ReputationMenuUpdater : StatsMenu
{
    void UpdateReputationList();
};

// @fnv 0x007dd8c0
void ReputationMenuUpdater::UpdateReputationList()
{
    if (DAT_011dace0 && DAT_011dace0->m_pTiles[46])
    {
        m_pTiles[47]->Set(4003, 0);
        m_pTiles[51]->Set(4003, 0);
        m_pTiles[48]->Set(4003, 0);
        DAT_011dace0->m_kReputationList.ClearList();
        for (ReputationNode* node = DAT_011c3f2c->GetReputations(); node && node->Get(); node = node->Next())
        {
            ReputationView* reputation = node->Get();
            if (reputation &&
                (reputation->GetReputation(true) > DAT_01012060 || reputation->GetReputation(false) > DAT_01012060))
            {
                BSStringT<char> label;
                FUN_00406f60(&label, DAT_01019f08, reputation->name.GetName());
                reinterpret_cast<ReputationMenuList*>(&DAT_011dace0->m_kReputationList)
                    ->Insert(reputation, label.String(), CompareEntryNames, false);
            }
        }
    }
}
}  // namespace fnv_007dd8c0

struct TileFloatSetter
{
    void Set(int trait, float value, bool propagate);
};
struct PipboyScreenStub
{
    void SetKnobTargetAndRate(int aiMode, float afAngle, float afSpeed);
};
struct PipboyInterfaceStub
{
    PipboyScreenStub* GetPipboyManager();
};
float __cdecl FUN_005c5420();
float __cdecl FUN_00404010(float a, float b);
float __cdecl FUN_004bd510(float a, float b);
extern float g_fPipboyNeedleSpeed;

struct FUN_007ddb00_shell : public Menu
{
    Tile* GetMenuTile();
    void UpdatePipboyNeedle();
};

// @fnv 0x007ddb00
void FUN_007ddb00_shell::UpdatePipboyNeedle()
{
    float fRange5 = GetMenuTile()->GetFloat(0x1008) * 1000.0;
    float fBase2 = -fRange5 / 2.0 + FUN_005c5420() * fRange5;
    float fValue = FUN_00404010(0.0f, g_thePlayer->GetCurrentActorValue((ActorValue::Index)0x36));
    float fAngleDifference = 1.5707963267948966 - (fValue + fBase2) / 1000.0 * 3.1415927f;
    if (fValue > 0.0 && fValue < 1.0)
        fValue = 1.0f;
    else
        fValue = FUN_004bd510(fValue, 1.0f);
    ((TileFloatSetter*)pMenu)->Set(0x1005, fValue, true);
    ((PipboyInterfaceStub*)FUN_004b7210())
        ->GetPipboyManager()
        ->SetKnobTargetAndRate(1, fAngleDifference, g_fPipboyNeedleSpeed);
}

struct HealText
{
    char* data;
    unsigned short len, cap;
    HealText();
    ~HealText();
    HealText& operator=(const char*);
    operator const char*() const;
};
struct HealTile
{
    void Set(int, int);
    const char* GetString(int);
    void Set(int, const char*, bool);
};
struct HealItem
{
    ~HealItem();
    int Count();
};
struct HealOption
{
    void* item;
    HealTile* tile;
    HealItem* inventory;
    bool(__cdecl* condition)(HealOption*);
};
struct HealPlayer
{
    HealItem* Find(void*, int);
    int Count(void*);
    bool Check();
};
extern HealPlayer* g_healPlayer;
int __cdecl HealFormat(HealText*, const char*, ...);
struct HealMenu
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
    HealOption options[4];
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
    HealTile* button;
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
    bool mode;
    void Toggle();
    void UpdateOption(int which);
};

// @fnv 0x007df230
void HealMenu::UpdateOption(int aiOptionIndex)
{
    if (!g_healPlayer)
        return;
    for (int indexB = 0; indexB < 4; indexB++)
    {
        if (aiOptionIndex == indexB || aiOptionIndex == 4)
        {
            HealText text;
            delete options[indexB].inventory;
            options[indexB].inventory = g_healPlayer->Find(options[indexB].item, 0);
            options[indexB].tile->Set(0xfaf, options[indexB].condition(&options[indexB]));
            if (options[indexB].inventory)
            {
                HealFormat(&text, "(%d) %s", options[indexB].inventory->Count(),
                           options[indexB].tile->GetString(0x1004));
                if ((indexB == 0 && !g_healPlayer->Check()) || indexB == 3)
                    button->Set(0xfaf, 1);
            }
            else
                text = options[indexB].tile->GetString(0x1004);
            options[indexB].tile->Set(0xfc4, (const char*)text, true);
        }
    }
    if (aiOptionIndex == 0 || aiOptionIndex == 3 || aiOptionIndex == 4)
    {
        int first2 = g_healPlayer->Count(options[0].item);
        int last = g_healPlayer->Count(options[3].item);
        bool enabled3 = true;
        if (g_healPlayer->Check() && last == 0)
            enabled3 = false;
        else if (!g_healPlayer->Check() && last == 0 && first2 == 0)
            enabled3 = false;
        if (!enabled3)
        {
            if (mode)
                Toggle();
            button->Set(0xfaf, 0);
        }
    }
}

namespace fnv_007df620 {
int __cdecl TraitNameToIDAdd(const char* name, int index);
bool __cdecl FUN_004b71d0();
BodyPartDisplay* __cdecl FUN_007db1c0();

struct GSString_00403df0
{
    const char* FUN_00403df0();
};
extern GSString_00403df0 DAT_011d4708;
extern GSString_00403df0 DAT_011d2658;

struct StatsMenuH_007df620
{
    char unk00[0x90];
    Tile* unk90;
    Tile* unk94;
    Tile* unk98;
    Tile* unk9c;
    Tile* unka0;
    char unka4[0xb4 - 0xa4];
    Tile* unkb4;
    char unkb8[0x100 - 0xb8];
    Tile* unk100;
    Tile* unk104;
    Tile* unk108;
    char unk10c[0x164 - 0x10c];
    Tile* unk164;
    int unk168;
    Tile* unk16c;
    int unk170;
    Tile* unk174;
    char unk178[0x2a0 - 0x178];
    bool m_bUpdateOption;
    void UpdateXboxButtonState();
};

// @fnv 0x007df620
void StatsMenuH_007df620::UpdateXboxButtonState()
{
    static int iConsoleButtonTrait = TraitNameToIDAdd("_xbox_button", -1);
    static int iEnabledTrait = TraitNameToIDAdd("_enabled", -1);
    if (unkb4 && FUN_004b71d0())
    {
        unkb4->Set(iConsoleButtonTrait, !m_bUpdateOption + 10);
        unkb4->Set(0xfc4, m_bUpdateOption ? DAT_011d4708.FUN_00403df0() : DAT_011d2658.FUN_00403df0(), true);
        unk90->Set(iEnabledTrait, !m_bUpdateOption);
        unk94->Set(iEnabledTrait, !m_bUpdateOption);
        unk98->Set(iEnabledTrait, !m_bUpdateOption);
        unk9c->Set(iEnabledTrait, !m_bUpdateOption);
        unka0->Set(iEnabledTrait, !m_bUpdateOption);
        unk100->Set(iEnabledTrait, !m_bUpdateOption);
        unk104->Set(iEnabledTrait, !m_bUpdateOption);
        unk164->Set(iEnabledTrait, !m_bUpdateOption);
        unk174->Set(iEnabledTrait, !m_bUpdateOption);
        unk16c->Set(iEnabledTrait, !m_bUpdateOption);
        unk108->Set(iEnabledTrait, !m_bUpdateOption);
    }
    FUN_007db1c0()->FUN_007dbfe0(m_bUpdateOption);
}
}  // namespace fnv_007df620

namespace fnv_007e0060 {
// FUN_007e0060: /MT /Od /GS /EHsc, 114 bytes, __thiscall with one stack argument.
// Validates an index against a computed limit, then notifies the owner.

extern PlayerCharacter* g_011dea3c;

struct FUN_007e0060_owner
{
    void FUN_00700320(unsigned int flags, int id);
};

struct FUN_007e0060_cls
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
    int unkA0;
    FUN_007e0060_owner* m_pSharedOwner;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    bool m_bUpdateOption;
    void FUN_007e0230();
    int FUN_007dcc40();
    bool FUN_007e0060(int id);
};

// @fnv 0x007e0060
bool FUN_007e0060_cls::FUN_007e0060(int id)
{
    if (id >= 0 && id <= (FUN_004d1360(g_011dea3c) ? 5 : 2) && FUN_007dcc40() != id)
    {
        if (m_bUpdateOption)
        {
            FUN_007e0230();
        }
        m_pSharedOwner->FUN_00700320(0x1004, id);
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_007e0060

struct ActiveCalls : ActiveEffect
{
    MagicItem* FUN_0044ddc0();
};
struct EntryEffects
{
    unsigned int unk00, unk04, unk08;
    void FUN_007e09d0(ActiveCalls*);
    void ApplyParamToEntry(ActiveCalls*);
};
struct EffectGroup
{
    TESForm* group;
    EntryEffects normal;
    EntryEffects special;
    EffectGroup(TESForm*);
};
int FUN_007e0480(EffectGroup*, EffectGroup*);
struct EffectGroupList
{
    void FUN_007a7eb0(EffectGroup*, int (*)(EffectGroup*, EffectGroup*));
};
struct SettingCalls
{
    bool FUN_00403e60(unsigned int);
};
struct FUN_007e08a0_shell
{
    unsigned int unk00;
    EffectGroupList forms;
    EffectGroup* FUN_007e0c50(unsigned int);
    void AddEffectToGroup(ActiveCalls*);
};
// Looks up or creates an EffectGroup for the effect's form, then adds the effect to its special or normal list based on a setting flag.
// @fnv 0x007e08a0
void FUN_007e08a0_shell::AddEffectToGroup(ActiveCalls* effect)
{
    TESForm* group = dynamic_cast<TESForm*>(effect->FUN_0044ddc0());
    EffectGroup* pGroup = FUN_007e0c50(group->GetFormID());
    if (!pGroup)
    {
        pGroup = new EffectGroup(group);
        forms.FUN_007a7eb0(pGroup, FUN_007e0480);
    }
    if (((SettingCalls*)effect->GetEffectSetting())->FUN_00403e60(0x2000))
        pGroup->special.FUN_007e09d0(effect);
    else
        pGroup->normal.ApplyParamToEntry(effect);
}

struct FUN_007e09d0_arg
{
    int FUN_007df1d0();
};

struct FUN_007e09d0_sub
{
    bool FUN_005f65d0(int* apValue);
    void FUN_007a7eb0(int aValue, int(__cdecl* apCallback)(FUN_007e0540_effect*, FUN_007e0540_effect*));
};

class FUN_007e09d0_cls
{
  public:
    int unk00;
    FUN_007e09d0_sub unk04;
    void FUN_007e09d0(FUN_007e09d0_arg* arg);
};

// @fnv 0x007e09d0
void FUN_007e09d0_cls::FUN_007e09d0(FUN_007e09d0_arg* arg)
{
    int value = arg->FUN_007df1d0();
    if (!unk04.FUN_005f65d0(&value))
    {
        unk04.FUN_007a7eb0(arg->FUN_007df1d0(), CompareEffectNames);
    }
}

struct FUN_007a62e0
{
    Tile* tile;
    ActorValue::Index value;
    bool selected;
    FUN_007a62e0(Tile*, ActorValue::Index*);
};
typedef int(__cdecl* ItemCompare)(FUN_007a62e0*, FUN_007a62e0*);
struct ItemListMethods
{
    void FUN_007a7eb0(FUN_007a62e0*, ItemCompare);
    void AddTail(FUN_007a62e0* const&);
};
struct TraitAction
{
    void RemoveFromReactions();
    void FUN_00a09130(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Refresh(bool);
};
struct ItemTileMethods
{
    void* FUN_00a00f30(int);
    TraitAction* FindTraitValue(int);
};
struct MenuTemplateMethods
{
    Tile* AddTileFromTemplate(Tile*, const char*, int);
};
int __cdecl TraitNameToIDAdd(const char*, int);
struct ItemBox : ListBox_enum_ActorValue__Index_
{
    bool FUN_007242c0(unsigned int);
    void FUN_007254d0();
    void AccumulateTileHeight(Tile*);
    void FUN_00725970();
    int GetRaceCount();
    Tile* FUN_007e1430(ActorValue::Index, const char*, ItemCompare, const char*);
};
// @fnv 0x007e1430
Tile* ItemBox::FUN_007e1430(ActorValue::Index value, const char* text, ItemCompare compare, const char* templateName)
{
    if (m_pListTile && (pTemplateName || templateName))
    {
        Tile* tile = ((MenuTemplateMethods*)((TileH*)m_pListTile)->GetMenu())
                         ->AddTileFromTemplate(m_pListTile, templateName ? templateName : pTemplateName, 0);
        if (!((ItemTileMethods*)tile)->FUN_00a00f30(4010))
            tile->Set(4010, -1);
        if (text)
            tile->Set(4036, text, true);
        if (compare)
        {
            ((ItemListMethods*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->FUN_007a7eb0(new FUN_007a62e0(tile, &value), compare);
            if (FUN_007242c0(0))
                FUN_007254d0();
        }
        else
        {
            ((ItemListMethods*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->AddTail(new FUN_007a62e0(tile, &value));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(tile);
                FUN_00725970();
            }
            tile->Set(4012, m_usSelectedIndex++);
        }
        if (GetRaceCount() == 1 &&
            ((Dummy007_obj*)m_pListTile)->FUN_00a011b0(TraitNameToIDAdd("_number_of_visible_items", -1)) > 0.0)
        {
            TraitAction* action = ((ItemTileMethods*)m_pListTile)->FindTraitValue(4016);
            action->RemoveFromReactions();
            action->FUN_00a09130(2000, tile, 4016);
            action->AppendFloatAction(
                2003, ((Dummy007_obj*)m_pListTile)->FUN_00a011b0(TraitNameToIDAdd("_number_of_visible_items", -1)));
            action->Refresh(false);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}

namespace fnv_007e16d0 {
struct FUN_007a62e0
{
    Tile* tile;
    ActorValue::Index value;
    bool filtered;
    FUN_007a62e0(Tile*, ActorValue::Index*);
};
struct ListOperations
{
    void FUN_007a7eb0(FUN_007a62e0*, int(__cdecl*)(FUN_007a62e0*, FUN_007a62e0*));
    void FUN_00905820(FUN_007a62e0* const&);
};
struct TemplateMenu
{
    Tile* AddTileFromTemplate(Tile*, const char*, int);
};
struct TileValueOperations
{
    void RemoveFromReactions();
    void FUN_00a09130(int, Tile*, int);
    void AppendFloatAction(int, float);
    void Refresh(int);
};
struct TileOperations
{
    TemplateMenu* FUN_00a03c90();
    void* FUN_00a00f30(int);
    float FUN_00a011b0(int);
    TileValueOperations* FindTraitValue(int);
};
int __cdecl TraitNameToIDAdd(const char*, int);
extern "C" const char kListBoxNumFiltered[];
struct ListBoxInsert : ListBox_enum_ActorValue__Index_
{
    bool FUN_007242c0(unsigned int);
    void ProcessSlots();
    void AccumulateTileHeight(Tile*);
    void FUN_00725f40();
    int GetRaceCount();
    Tile* FUN_007e16d0(ActorValue::Index value, const char* text,
                       int(__cdecl* comparator)(FUN_007a62e0*, FUN_007a62e0*), const char* templateName);
};
// @fnv 0x007e16d0
Tile* ListBoxInsert::FUN_007e16d0(ActorValue::Index value, const char* text,
                                  int(__cdecl* comparator)(FUN_007a62e0*, FUN_007a62e0*), const char* templateName)
{
    if (m_pListTile && (pTemplateName || templateName))
    {
        Tile* tile = ((TileOperations*)m_pListTile)
                         ->FUN_00a03c90()
                         ->AddTileFromTemplate(m_pListTile, templateName ? templateName : pTemplateName, 0);
        if (!((TileOperations*)tile)->FUN_00a00f30(0xFAA))
            tile->Set(0xFAA, -1);
        if (text)
            tile->Set(0xFC4, text, true);
        if (comparator)
        {
            ((ListOperations*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->FUN_007a7eb0(new FUN_007a62e0(tile, &value), comparator);
            if (FUN_007242c0(0))
                ProcessSlots();
        }
        else
        {
            ((ListOperations*)&bSSimpleList_ListBoxItem_enum_ActorValue__Index____Component)
                ->FUN_00905820(new FUN_007a62e0(tile, &value));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(tile);
                FUN_00725f40();
            }
            tile->Set(0xFAC, m_usSelectedIndex++);
        }
        if (GetRaceCount() == 1 &&
            ((TileOperations*)m_pListTile)->FUN_00a011b0(TraitNameToIDAdd(kListBoxNumFiltered, -1)) > 0.0)
        {
            TileValueOperations* height = ((TileOperations*)m_pListTile)->FindTraitValue(0xFB0);
            height->RemoveFromReactions();
            height->FUN_00a09130(0x7D0, tile, 0xFB0);
            height->AppendFloatAction(
                0x7D3, ((TileOperations*)m_pListTile)->FUN_00a011b0(TraitNameToIDAdd(kListBoxNumFiltered, -1)));
            height->Refresh(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_007e16d0

namespace fnv_007dc490 {
bool FUN_004b71d0();

class StatusEntry
{
  public:
    int FindEntryIndex();
};
StatusEntry* __stdcall FUN_007db1c0(int iIndex);

class StatusMenuOwner
{
  public:
    void FUN_007e0230();
    void FUN_007dc490(int iUnused, int iIndex);

    char unk000[0x160];
    Tile* m_pkTile;  // +0x160
    char unk164[0x13c];
    bool m_bModifierActive;  // +0x2a0
};

// @fnv 0x007dc490
void StatusMenuOwner::FUN_007dc490(int iUnused, int iIndex)
{
    if (m_bModifierActive && !FUN_004b71d0())
    {
        int iType = FUN_007db1c0(iIndex)->FindEntryIndex();
        if (iType != 6)
            FUN_007e0230();
    }
    m_pkTile->Set(0xfa3, 0);
}
}  // namespace fnv_007dc490

namespace fnv_007dc1b0 {
struct TileSI : public Tile
{
    float FUN_00a011b0(int);
};
struct PlayerClick
{
    bool FUN_004d1360();
};
struct ListClick
{
    bool ContainsKey(Tile*);
    void* FindItemData(Tile*);
};
struct StatusH
{
    int FindEntryIndex();
    void SetBodyPart(bool);
};
StatusH* __stdcall FUN_007db1c0(Tile*);
StatusH* __stdcall FUN_007db1c0(int);
bool __cdecl FUN_004b71d0();
class BSSoundHandleEx
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    ~BSSoundHandleEx();
    bool Play(bool);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
extern char DAT_01074f40[];
extern int DAT_011dad60, DAT_011dad64, DAT_011dad68, DAT_011dad6c, DAT_011dad70;
struct ClickMenu : public StatsMenu
{
    void FUN_007dfd20(Tile*, int*);
    void UpdateStatsDisplay(void*);
    void UpdateScrollBar(void*);
    void SetReputationEntry(void*);
    void FUN_007e0230();
    void OnTileClick(int id, Tile* tile);
};
// Handles a tile click on the stats menu by dispatching to the current page's list, updating the display, and playing a sound for status effects.
// @fnv 0x007dc1b0
void ClickMenu::OnTileClick(int aiTileIndex, Tile* tile)
{
    if (!tile && aiTileIndex >= 0 && aiTileIndex < 60)
        tile = m_pTiles[aiTileIndex];
    switch (GetCurrentPage())
    {
    case SM_STATUS:
        if (((TileSI*)tile)->FUN_00a011b0(0xfac) > 0.0)
            FUN_007dfd20(tile, &DAT_011dad60);
        if (!FUN_004b71d0())
        {
            if ((g_thePlayer && ((PlayerClick*)g_thePlayer)->FUN_004d1360()) ? m_kHealingOptions[3].m_pStatusEffect
                                                                             : m_kHealingOptions[0].m_pStatusEffect)
            {
                int status = FUN_007db1c0(tile)->FindEntryIndex();
                if (status != 6)
                {
                    FUN_007db1c0(status)->SetBodyPart(true);
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01074f40, 0x121).Play(false);
                    if (!m_bUpdateOption)
                        FUN_007e0230();
                }
            }
        }
        break;
    case SM_SPECIAL:
        if (((ListClick*)&m_kPrimaryActorValueList)->ContainsKey(tile))
        {
            FUN_007dfd20(tile, &DAT_011dad64);
            UpdateStatsDisplay(((ListClick*)&m_kPrimaryActorValueList)->FindItemData(tile));
        }
        break;
    case SM_SKILLS:
        if (((ListClick*)&m_kSecondaryActorValueList)->ContainsKey(tile))
        {
            FUN_007dfd20(tile, &DAT_011dad68);
            UpdateStatsDisplay(((ListClick*)&m_kSecondaryActorValueList)->FindItemData(tile));
        }
        break;
    case SM_PERKS:
        if (((ListClick*)&m_kPerkRankList)->ContainsKey(tile))
        {
            FUN_007dfd20(tile, &DAT_011dad6c);
            UpdateScrollBar(((ListClick*)&m_kPerkRankList)->FindItemData(tile));
        }
        break;
    case SM_GENERAL:
        if (((ListClick*)&m_kMiscStatList)->ContainsKey(tile))
            FUN_007dfd20(tile, &DAT_011dad70);
        if (((ListClick*)&m_kReputationList)->ContainsKey(tile))
        {
            SetReputationEntry(((ListClick*)&m_kReputationList)->FindItemData(tile));
            FUN_007dfd20(tile, &DAT_011dad70);
        }
        break;
    }
}
}  // namespace fnv_007dc1b0

namespace s7e00e0 {

struct Owner
{
    bool SetIndexFromType(unsigned int uiType, int* piIndex);
};

// Sets *piIndex to the matching value for uiType 0-4 and returns true, or returns false for any other value.
// @fnv 0x007e00e0
bool Owner::SetIndexFromType(unsigned int uiType, int* piIndex)
{
    switch (uiType)
    {
    case 0:
        *piIndex = 0;
        return true;
    case 1:
        *piIndex = 1;
        return true;
    case 2:
        *piIndex = 2;
        return true;
    case 3:
        *piIndex = 3;
        return true;
    case 4:
        *piIndex = 4;
        return true;
    }
    return false;
}

}

void* __cdecl operator new(unsigned int size);

BGSHungerStage* __cdecl FindHungerStage(float level);
BGSSleepDeprevationStage* __cdecl GetSleepDeprivationStage(float level);
const char* __cdecl FUN_0066eb00(int av);
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
extern const char DAT_01012630[];
extern const char DAT_01019f08[];

extern GameSettingString g_011d1ef0;

// Rebuilds the stats menu status-effect tiles and list from the player's active effects and survival stage spells.
// @fnv 0x007ddf00
void StatsMenuActiveEffects::FUN_007ddf00()
{
    BGSDehydrationStage* ph20stage;
    BGSSleepDeprevationStage* psleepstage;
    BGSRadiationStage* pradstage;
    if (m_bStatUpdatePending)
        return;
    m_bStatUpdatePending = true;
    BSStringTChar strtmp;
    Tile* ptile;
    ActiveEffect* pactiveEffect;
    BGSHungerStage* phungerstage;

    ((StatusEffectListOps*)&m_kStatusEffectEntries)->FUN_007e07f0();
    delete m_pStatusEffectAtIndex0;
    m_pStatusEffectAtIndex0 = 0;
    delete m_pStatusEffectAtIndex1;
    m_pStatusEffectAtIndex1 = 0;
    delete m_pStatusEffectAtIndex3;
    m_pStatusEffectAtIndex3 = 0;
    delete m_pStatusEffectAtIndex2;
    m_pStatusEffectAtIndex2 = 0;

    pradstage = BGSRadiationStage::GetStageForLevel(g_thePlayer->GetCurrentActorValue((ActorValue::Index)54));
    ph20stage = BGSDehydrationStage::FindStage(g_thePlayer->GetCurrentActorValue((ActorValue::Index)73));
    psleepstage = GetSleepDeprivationStage(g_thePlayer->GetCurrentActorValue((ActorValue::Index)75));
    phungerstage = FindHungerStage(g_thePlayer->GetCurrentActorValue((ActorValue::Index)74));

    for (BSSimpleList<ActiveEffect*>* pnode = ((ActorMagicTargetView*)g_thePlayer)->GetActiveEffectList();
         pnode && (pactiveEffect = pnode->GetItem()); pnode = pnode->GetNext())
    {
        if (((ActiveEffectOps*)pactiveEffect)->FUN_00833c20() &&
            !((EffectItemOps*)((ActiveEffectOps*)pactiveEffect)->GetEffectItem())->IsScriptBasedEffect() &&
            (!pactiveEffect->GetEffectSetting()->IsScriptEffect() ||
             ((EffectSettingOps*)pactiveEffect->GetEffectSetting())->IsFlagSet(0x2000)))
        {
            SpellItem* pspell = dynamic_cast<SpellItem*>(((ActiveEffectOps*)pactiveEffect)->GetMagicItem());
            if (pspell && pradstage && pspell == pradstage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex0)
                    m_pStatusEffectAtIndex0 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex0->pForm == pspell)
                    m_pStatusEffectAtIndex0->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (pspell && ph20stage && pspell == ph20stage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex1)
                    m_pStatusEffectAtIndex1 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex1->pForm == pspell)
                    m_pStatusEffectAtIndex1->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (pspell && phungerstage && pspell == phungerstage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex2)
                    m_pStatusEffectAtIndex2 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex2->pForm == pspell)
                    m_pStatusEffectAtIndex2->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (pspell && psleepstage && pspell == psleepstage->GetSpell())
            {
                if (!m_pStatusEffectAtIndex3)
                    m_pStatusEffectAtIndex3 = new StatsMenu__StatusEffect(pspell);
                if (m_pStatusEffectAtIndex3->pForm == pspell)
                    m_pStatusEffectAtIndex3->xEffectData.ApplyParamToEntry(pactiveEffect);
            }
            if (((EffectItemOps*)((ActiveEffectOps*)pactiveEffect)->GetEffectItem())->FUN_00403ee0() &&
                FUN_0066eb00(
                    ((EffectItemOps*)((ActiveEffectOps*)pactiveEffect)->GetEffectItem())->GetAffectedActorValue()) &&
                (pactiveEffect->GetDuration() != 0.0 || ((ActiveEffectOps*)pactiveEffect)->GetSpellType() == 1 ||
                 ((ActiveEffectOps*)pactiveEffect)->GetSpellType() == 6 ||
                 ((ActiveEffectOps*)pactiveEffect)->GetSpellType() == 10 ||
                 (((ActiveEffectOps*)pactiveEffect)->GetSpellType() == 4 &&
                  ((ActiveEffectOps*)pactiveEffect)->FUN_007df210())))
            {
                ((StatusEffectListOps*)&m_kStatusEffectEntries)->AddEffectToGroup(pactiveEffect);
            }
            else if (((EffectSettingOps*)pactiveEffect->GetEffectSetting())->IsFlagSet(0x2000))
            {
                ((StatusEffectListOps*)&m_kStatusEffectEntries)->AddEffectToGroup(pactiveEffect);
            }
        }
    }

    if (m_pStatusEffectAtIndex0)
    {
        ((TileOps*)m_pTiles[32])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex0->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((MenuOps*)this)->CreateTileFromTemplate(m_pTiles[32], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_rad_effect_";
            strtmp += FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue);
            ((TileOps*)ptile)->FUN_007df120(strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[32]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[32]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex1)
    {
        ((TileOps*)m_pTiles[54])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex1->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((MenuOps*)this)->CreateTileFromTemplate(m_pTiles[54], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_h20_effect_";
            strtmp += FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue);
            ((TileOps*)ptile)->FUN_007df120(strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[54]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[54]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex2)
    {
        ((TileOps*)m_pTiles[56])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex2->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((MenuOps*)this)->CreateTileFromTemplate(m_pTiles[56], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_hunger_effect_";
            strtmp += FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue);
            ((TileOps*)ptile)->FUN_007df120(strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[56]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[56]->Set(0xfa3, 0);
    }

    if (m_pStatusEffectAtIndex3)
    {
        ((TileOps*)m_pTiles[58])->ResetImage();
        int i = 0;
        for (BSSimpleList<MagicEffectEntry*>* pnode = &m_pStatusEffectAtIndex3->xEffectData; pnode && pnode->GetItem();
             pnode = pnode->GetNext())
        {
            Tile* ptile = ((MenuOps*)this)->CreateTileFromTemplate(m_pTiles[58], "stats_rad_effects_template", 0);
            ptile->Set(0xfac, i++);
            strtmp = "stats_sleep_effect_";
            strtmp += FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue);
            ((TileOps*)ptile)->FUN_007df120(strtmp);
            strtmp.PrintfString("%+d", pnode->GetItem()->m_iMagnitude);
            ptile->Set(0xfc4, strtmp, true);
            ptile->Set(0x1005, FUN_0066eb00(pnode->GetItem()->m_eAssociatedActorValue), true);
        }
        m_pTiles[58]->Set(0xfa3, 1);
    }
    else
    {
        m_pTiles[58]->Set(0xfa3, 0);
    }

    ptile = 0;
    m_kStatusEffectList.ClearList();
    for (BSSimpleList<StatsMenu__StatusEffect*>* peffectlistnode = (StatusEffectListOps*)&m_kStatusEffectEntries;
         peffectlistnode && peffectlistnode->GetItem(); peffectlistnode = peffectlistnode->GetNext())
    {
        ptile = ((StatusEffectListBox*)&m_kStatusEffectList)->AddItem(peffectlistnode->GetItem(), 0, 0, 0);
        AlchemyItem* ppotion = dynamic_cast<AlchemyItem*>(peffectlistnode->GetItem()->pForm);
        if (ppotion && ((EquipTypeComponent*)((char*)ppotion + 0x9c))->GetEquipType() == 13)
        {
            ptile->Set(0x1004, g_011d1ef0.GetString(), true);
        }
        else
        {
            TESFullName* pname = dynamic_cast<TESFullName*>(peffectlistnode->GetItem()->pForm);
            if (pname)
            {
                ptile->Set(0x1004, ((TESFullNameOps*)pname)->GetFullName(), true);
            }
            else
            {
                ptile->Set(0x1004, peffectlistnode->GetItem()->pForm->GetName(), true);
            }
        }
        BSStringTChar streffects;
        for (BSSimpleList<EffectSetting*>* pnamelistnode = &peffectlistnode->GetItem()->m_kNamedEffectsList;
             pnamelistnode && pnamelistnode->GetItem(); pnamelistnode = pnamelistnode->GetNext())
        {
            if (((EffectSettingOps*)pnamelistnode->GetItem())->GetEffectName())
            {
                strtmp.PrintfString(DAT_01019f08,
                               (const char*)((EffectSettingOps*)pnamelistnode->GetItem())->GetEffectName());
                streffects.AppendString(strtmp);
                if (pnamelistnode->GetNext())
                    streffects += DAT_01012630;
            }
        }
        if (streffects.GetLength() > 0 && peffectlistnode->GetItem()->xEffectData.GetSize())
            streffects += DAT_01012630;
        for (BSSimpleList<MagicEffectEntry*>* pdatalistnode = &peffectlistnode->GetItem()->xEffectData;
             pdatalistnode && pdatalistnode->GetItem(); pdatalistnode = pdatalistnode->GetNext())
        {
            if (pdatalistnode->GetItem()->m_iMagnitude)
            {
                strtmp.PrintfString("%s %+d", FUN_0066eb00(pdatalistnode->GetItem()->m_eAssociatedActorValue),
                               pdatalistnode->GetItem()->m_iMagnitude);
                streffects.AppendString(strtmp);
                if (pdatalistnode->GetNext())
                    streffects += DAT_01012630;
            }
        }
        ptile->Set(0x1005, streffects, true);
    }

    if (ptile)
    {
        ((TileOps*)m_pTiles[33])
            ->Set(0xfb0,
                  FUN_0042f5a0(8, ((StatusEffectListBox*)&m_kStatusEffectList)->GetNumItems()) * ptile->GetFloat(0xfb0),
                  true);
        ptile->Set(0x1006, 0);
    }
    else
    {
        m_pTiles[33]->Set(0xfb0, 0);
    }
    ((StatusEffectListBox*)&m_kStatusEffectList)->Synchronize();
}

namespace fnv_007db680 {
struct InputTile : public Tile
{
    void FUN_00a0b110(int);
    bool IsTraitNonZero(int);
    bool IsAllChildrenFlag0();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void SetTraitAndReset(int, float);
};
struct InputChildren
{
    Tile*& FUN_007b5370();
};
struct InputList
{
    InputTile* FUN_00825c00();
};
struct InputVirtualMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Click(int, Tile*);
};
struct InputStatus
{
    unsigned int FUN_00559450() const;
    int GetByte(unsigned int, int);
    void SetBodyPart(int, bool);
};
class FUN_007db2c0;
FUN_007db2c0* __cdecl FUN_007db1c0();
bool __cdecl FUN_00702450(int);
struct InputRendered
{
    bool IsUnk28Set();
};
InputRendered* __cdecl FUN_00705990();
bool __cdecl IsActorValueBelowPermanent(StatsMenu__HealingOption*);
bool __cdecl IsHealingOptionAvailable(const StatsMenu__HealingOption*);
class BSSoundHandleEx
{
  public:
    unsigned int id;
    bool assume;
    unsigned int state;
    ~BSSoundHandleEx();
    bool Play(bool);
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
BSAudio* __cdecl FUN_00453a70();
void __cdecl FUN_00717280(int);
void __cdecl UpdatePipboyMapVisibility(int, bool);
void __cdecl FUN_007048f0(int, bool, bool);
StatsMenu::Page* __cdecl DecrementInt(StatsMenu::Page*);
StatsMenu::Page* __cdecl FUN_007dc0a0(StatsMenu::Page*);
struct InputSetting
{
    float* FUN_00403e20();
};
extern InputSetting g_011db358;
extern InputSetting g_011db2f0;
struct InputPipboy
{
    void FUN_007f8610(int, float, float, bool);
};
struct InputInterface
{
    InputPipboy* FUN_00704370();
};
InputInterface* __cdecl FUN_004b7210();
bool __cdecl FUN_00709d40();
struct InputControls
{
    int GetAxisState(int, int);
};
struct InputOS
{
    InputControls* FUN_00877720();
};
extern InputOS* g_osGlobals;
double __cdecl FUN_00408820(float);
unsigned int __cdecl gm_GetTickCount();
extern unsigned int DAT_011dad5c;
int __cdecl TraitNameToID(const char*);

struct InputStats : public StatsMenu
{
    int FUN_007dcc40();
    bool FUN_007e0060(int);
    bool GetTileIndex(int, int*);
    bool FUN_007db680(int code, float amount);
};

// Processes input codes for the stats menu, updating healing options, status values, page navigation, and scrolling effect lists.
// @fnv 0x007db680
bool InputStats::FUN_007db680(int code, float amount)
{
    if (!FUN_00702450(1003) || !FUN_00705990()->IsUnk28Set())
        return false;
    if (FUN_00702450(1003))
    {
        if (m_bUpdateOption && (code == 1 || code == 2 || code == 4 || code == 3))
        {
            int direction;
            switch (code)
            {
            case 1:
                direction = 0;
                break;
            case 2:
                direction = 1;
                break;
            case 4:
                direction = 2;
                break;
            case 3:
                direction = 3;
                break;
            default:
                return false;
            }
            int selected3 =
                ((InputStatus*)FUN_007db1c0())->GetByte(((InputStatus*)FUN_007db1c0())->FUN_00559450(), direction);
            if (selected3 < 6)
            {
                ((InputStatus*)FUN_007db1c0())->SetBodyPart(selected3, true);
                m_kHealingOptions[0].pTile->Set(0xfaf, IsActorValueBelowPermanent(&m_kHealingOptions[0]));
                m_kHealingOptions[3].pTile->Set(0xfaf, IsHealingOptionAvailable(&m_kHealingOptions[3]));
                FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyHighlight", 0x121).Play(false);
            }
            return true;
        }
        else if ((code == 13 || code == 14) && amount >= 1.0)
        {
            FUN_00717280(0x24);
            if (code == 13)
                UpdatePipboyMapVisibility(1, false);
            else
                FUN_007048f0(1, false, true);
            return true;
        }
        else if (code == 4)
        {
            Page _previousPage = GetCurrentPage();
            SetCurrentPage(_previousPage == 0 ? SM_LAST_PAGE : *DecrementInt(&_previousPage));
            ((InputTile*)m_pTiles[0])->FUN_00a0b110(0xfcb);
            return true;
        }
        else if (code == 3)
        {
            Page nextPage = GetCurrentPage();
            SetCurrentPage(nextPage == 4 ? SM_FIRST_PAGE : *FUN_007dc0a0(&nextPage));
            ((InputTile*)m_pTiles[0])->FUN_00a0b110(0xfcb);
            return true;
        }
        else if (GetCurrentPage() == SM_GENERAL)
        {
            if (code == 11)
            {
                ((InputVirtualMenu*)this)->Click(0x31, 0);
                return true;
            }
        }
        else if (GetCurrentPage() == SM_STATUS)
        {
            if (code == 1 || code == 2)
            {
                int statusStep6 = code == 1 ? -1 : 1;
                int newStatusVal = FUN_007dcc40() + statusStep6;
                if (FUN_007e0060(newStatusVal))
                {
                    int limbVal = 6;
                    if (GetTileIndex(0x1c, &limbVal) && limbVal == newStatusVal)
                        ((InputTile*)m_pTiles[28])->FUN_00a0b110(0xfcb);
                    else if (GetTileIndex(0x1d, &limbVal) && limbVal == newStatusVal)
                        ((InputTile*)m_pTiles[29])->FUN_00a0b110(0xfcb);
                    else if (GetTileIndex(0x1e, &limbVal) && limbVal == newStatusVal)
                        ((InputTile*)m_pTiles[30])->FUN_00a0b110(0xfcb);
                    else if (GetTileIndex(0x35, &limbVal) && limbVal == newStatusVal)
                        ((InputTile*)m_pTiles[53])->FUN_00a0b110(0xfcb);
                    else if (GetTileIndex(0x37, &limbVal) && limbVal == newStatusVal)
                        ((InputTile*)m_pTiles[55])->FUN_00a0b110(0xfcb);
                    else if (GetTileIndex(0x39, &limbVal) && limbVal == newStatusVal)
                        ((InputTile*)m_pTiles[57])->FUN_00a0b110(0xfcb);
                    FUN_004b7210()->FUN_00704370()->FUN_007f8610(0, *g_011db2f0.FUN_00403e20() * statusStep6,
                                                                 *g_011db358.FUN_00403e20(), true);
                    return true;
                }
            }
            else if (code == 9)
            {
                switch (FUN_007dcc40())
                {
                case 0:
                    ((InputVirtualMenu*)this)->Click(10, 0);
                    return true;
                case 1:
                    ((InputVirtualMenu*)this)->Click(11, 0);
                    return true;
                default:
                    return false;
                }
            }
            else if (code == 11)
            {
                switch (FUN_007dcc40())
                {
                case 0:
                    if (!m_bUpdateOption && ((InputTile*)m_pTiles[9])->IsTraitNonZero(0xfaf))
                    {
                        ((InputVirtualMenu*)this)->Click(9, 0);
                        FUN_00453a70()->GetSoundHandleByEditorID("UIMenuOK", 0x121).Play(false);
                        return true;
                    }
                    return false;
                case 1:
                    ((InputVirtualMenu*)this)->Click(31, 0);
                    return true;
                default:
                    return false;
                }
            }
            else if (code == 12)
            {
                switch (FUN_007dcc40())
                {
                case 0:
                    if (((InputTile*)m_pTiles[9])->IsTraitNonZero(0xfaf))
                    {
                        ((InputVirtualMenu*)this)->Click(59, 0);
                        FUN_00453a70()->GetSoundHandleByEditorID("UIMenuOK", 0x121).Play(false);
                        return true;
                    }
                    return false;
                case 1:
                    ((InputVirtualMenu*)this)->Click(31, 0);
                    return true;
                default:
                    return false;
                }
            }
        }
        if (FUN_00709d40() &&
            (((InputList*)&m_kStatusEffectList)->FUN_00825c00()->IsAllChildrenFlag0() ||
             ((InputTile*)((InputChildren*)&m_pTiles[26]->m_kChildTileList)->FUN_007b5370())->IsTraitNonZero(0xfa3)))
        {
            int axisB = 0;
            int scrollStepVal4 = 0;
            axisB = g_osGlobals->FUN_00877720()->GetAxisState(0, 10);
            if (FUN_00408820((float)axisB) <= 8689.0)
                axisB = 0;
            if (axisB != 0)
                scrollStepVal4 = axisB >= 0 ? -1 : 1;
            if (scrollStepVal4 != 0 && gm_GetTickCount() > DAT_011dad5c)
            {
                InputTile* scrollTile =
                    GetCurrentPage() == SM_STATUS
                        ? ((InputList*)&m_kStatusEffectList)->FUN_00825c00()
                        : (InputTile*)((InputChildren*)&m_pTiles[26]->m_kChildTileList)->FUN_007b5370();
                int trait3 = TraitNameToID("_current_value");
                int oldValue4 = (int)scrollTile->FUN_00a011b0(trait3);
                scrollTile->FUN_00a012d0(trait3, (float)(oldValue4 + scrollStepVal4), false);
                if (oldValue4 != scrollTile->FUN_00a011b0(trait3))
                    scrollTile->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
                DAT_011dad5c =
                    gm_GetTickCount() + (DAT_011dad5c ? (int)((InputTile*)m_pTiles[33])->FUN_00a011b0(0x1004)
                                                      : (int)((InputTile*)m_pTiles[33])->FUN_00a011b0(0x1005));
            }
            else if (scrollStepVal4 == 0)
                DAT_011dad5c = 0;
        }
    }
    return false;
}
}  // namespace fnv_007db680
