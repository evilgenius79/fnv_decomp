// src/fallout/interface/menus/bookmenu_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BookMenu, Menu, Tile). The skeleton of src/fallout/interface/menus/bookmenu.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.


// src/fallout/interface/menus/bookmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/bookmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Menu
{
    virtual ~Menu();  // the original class is polymorphic (rtti_variants.py)
    Menu();
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    unsigned int m_g;
    unsigned int m_h;
    unsigned int m_i;
};
extern unsigned int DAT_01070ecc;
struct FUN_0073acb0 : Menu
{
    void* m_pHighlightedTile;
    void* m_pObject;
    FUN_0073acb0();
};
struct BookMenu
{
    virtual ~BookMenu();  // the original class is polymorphic (rtti_variants.py)
    int FUN_0073acf0();
};
struct FUN_0073af60_shell
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0c;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    int m_0x1c;
    int m_0x20;
    int m_0x24;
    int m_0x28;
    int m_0x2c;
    bool __thiscall FUN_0073af60();
};
void __cdecl _Deallocate(void*);
struct FUN_0073ad00_shell
{
    void __thiscall FUN_0073ad30();
    void* __thiscall FUN_0073ad00(unsigned int);
};
struct BSCullingProcess;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct ShaderRenderProperty;
struct FOPipboyManager;
struct FORenderedMenu;
struct ShadowLightData;
struct InventoryStackRecord;
struct ListBoxBase;
struct Menu;
struct MobileObject;
struct NiAVObject;
struct NiAlphaProperty;
struct NiDirectionalLight;
struct NiNode;
struct SceneGraph;
struct ShadowSceneNode;
struct TESImageSpaceModifier;
struct TESObjectREFR;
struct Tile;
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
    char m_kFirstVectorData[12];
    char m_kSecondVectorData[12];
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
    char m_kReferenceData[12];
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
struct FUN_0073b020_shell : public InterfaceManager
{
    int FUN_0073b020();
};
float __cdecl FUN_00715da0();
struct FUN_0073b460_shell
{
    bool __thiscall FUN_0073b460();
};
struct Inner73b430
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void foo(int, int)
    {}
};
struct Holder73b430
{
    char _pad[0x94];
    Inner73b430 inner;
    void __thiscall CallInnerFoo();
};
extern unsigned int DAT_01077abc;
struct FUN_007e7a80 : Menu
{
    char _pad[0x50];
    int m_78;
    int m_7c;
    FUN_007e7a80();
};
struct TGF
{
    virtual ~TGF();  // the original class is polymorphic (rtti_variants.py)
    float GetFloat(int);
};
struct Tile : TGF
{
    float GetScreenY();
    void Set(int, int);
};
FUN_0073b020_shell* __cdecl _FUN_004b7210();
int __cdecl __ftol2_sse(double);
struct FUN_0073b050_shell : Menu
{
    Tile* m_pHighlightedTile;
    Tile* m_pObject;
    unsigned int m_0x30;
    unsigned int m_0x34;
    float m_fValue;

    void __thiscall FUN_0073b050(int, Tile*);
};
struct FUN_00a1c520_shell
{
    void __thiscall FUN_00a1c520();
};
struct Res_0073b0f0
{
    short FUN_00418770();
};
struct Obj30_0073b0f0
{
    Res_0073b0f0* FUN_005d43c0(int);
};
struct VT_0073b0f0
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
    virtual void vSlot(Obj30_0073b0f0*, int);
};
extern VT_0073b0f0* DAT_011dea3c;
struct FUN_0073b0f0_cls
{
    char _pad[0x30];
    Obj30_0073b0f0* m_0x30;
    void __thiscall UpdateMenuTile();
    void __thiscall HandleMessage(int, int);
};
struct BookInput
{
    bool FUN_00409700();
    const char* CallInnerFoo();
    bool FUN_0073b460();
};
struct BookTile
{
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
};
struct BSStringTChar
{
    char* data;
    unsigned short length;
    unsigned short capacity;
    BSStringTChar(const char*);
    ~BSStringTChar();
};
struct BookTarget : Menu
{
    void* unk28;
    void* unk2c;
    int unk30;
    BookTile* FUN_00726070();
    void UpdateBookMenu(BookInput*, int);
};
void __cdecl FUN_00717280(int);
struct MyTile
{
    bool IsTraitNonZero(int);
    float FUN_00a011b0(int);
    void Set(int, int);
};
struct BookMenu_Shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    MyTile* m_pHighlightedTile;
    MyTile* m_pObject;

    MyTile* FUN_00726070();
    void HandleScrollInput(int a1, int a2);
};
extern const char DAT_01070fa8[];
extern const char DAT_01070f84[];
template <class T> struct BSStringT
{
    T* data;
    unsigned short length, capacity;
    BSStringT();
    BSStringT(const T*);
    ~BSStringT();
    const T* FUN_00559450();
    unsigned int FUN_004048e0();
};
struct NiFile
{
    enum OpenMode
    {
        read = 0
    };
};
struct BSFile
{
    unsigned int vtable;
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
    char filename[260];
    unsigned int unk148, unk14c, unk150, unk154;
    BSFile(const char*, NiFile::OpenMode, unsigned int, bool);
    ~BSFile();
    bool FUN_00aff300(bool, bool);
    bool FUN_008905f0();
    void FUN_00aff7c0(BSStringT<char>*, int);
};
extern void __cdecl FUN_00703c00(const char*, ...);
struct LoadBook
{
    BookTile* FUN_00726070();
    void LoadBookFile();
};

struct TESObjectBOOK
{
    bool FUN_00409700();
};
struct Tile_00a01b00 : Tile
{
    static float __cdecl FUN_00a01530();
    Tile* ReadXML(const char*);
    Menu* FUN_00a03c90();
    void FUN_00a012d0(int, float, bool);
};
struct TileMenu : Tile
{
};
struct IMH
{
    Tile_00a01b00* FUN_00586150();
};
struct BookMenuData : Menu
{
    void* m_pHighlightedTile;
    void* m_pObject;
    void* unk30;
    TESObjectBOOK* m_pObjectToUpdateMenuTile;
    void UpdateBookMenu(TESObjectBOOK*, TESObjectREFR*);
};
struct MenuH
{
    virtual ~MenuH();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual int GetID();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
};
Menu* __cdecl FindMenuById(int);
InterfaceManager* __cdecl FUN_004b7210();
void __cdecl FNV_Warning(const char*, ...);
void __cdecl FUN_00717280(int);
void* __fastcall FUN_00726070(Menu*);

// @fnv 0x0073ad50
Tile* __cdecl FUN_0073ad50(TESObjectBOOK* apBook, TESObjectREFR* apRef)
{
    BookMenu* g_pHudMainMenuInstance;
    InterfaceManager* pin;
    Menu* pmenu;
    TESObjectBOOK* pbook;
    float ftop_depth;
    Tile_00a01b00* ptile;
    Tile* pold_menu_tile;
    pold_menu_tile = (Tile*)FindMenuById(0x402);
    if (pold_menu_tile)
        delete pold_menu_tile;
    pbook = apBook;
    if (!pbook)
        return 0;
    pin = FUN_004b7210();
    ftop_depth = Tile_00a01b00::FUN_00a01530();
    ptile = 0;
    ptile = (Tile_00a01b00*)((IMH*)pin)->FUN_00586150()->ReadXML("Data\\Menus\\book_menu.xml");
    pmenu = ptile->FUN_00a03c90();
    g_pHudMainMenuInstance = (BookMenu*)pmenu;
    ((BookMenuData*)g_pHudMainMenuInstance)->m_pObjectToUpdateMenuTile = apBook;
    if (pmenu && ((MenuH*)pmenu)->GetID() == 0x402)
    {
        ((MenuH*)pmenu)->SetTileMenu(dynamic_cast<TileMenu*>((Tile*)ptile), false);
        BookMenu* g_pHudMainMenuInstance = dynamic_cast<BookMenu*>(pmenu);
        if (!((FUN_0073af60_shell*)g_pHudMainMenuInstance)->FUN_0073af60())
        {
            FNV_Warning("MENUS: Book Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (((TGF*)ptile)->GetFloat(0xfa7) == 6006.0 || ((TGF*)ptile)->GetFloat(0xfa7) == 102.0)
            ptile->FUN_00a012d0(0xfad, ftop_depth, true);
        ((BookMenuData*)g_pHudMainMenuInstance)->UpdateBookMenu(apBook, apRef);
        if (((BookMenuData*)g_pHudMainMenuInstance)->m_pObjectToUpdateMenuTile->FUN_00409700())
            FUN_00717280(0x18);
        else
            FUN_00717280(0x1a);
        ((MenuH*)pmenu)->SetMenuVisibility(false);
        return ptile;
    }
    else if (pmenu && FUN_00726070(pmenu))
    {
        delete (MenuH*)pmenu;
    }
    return 0;
}
