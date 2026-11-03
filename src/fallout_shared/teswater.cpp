// fallout_shared/teswater.cpp: BGSPlaceableWater, TESObjectCELL, WaterZoneManager, Owner and more (135 functions)

#include "teswater_decls.h"

// Initializes the two members of BSMultiBound to zero.
// @fnv 0x00c35e00
BSMultiBound::BSMultiBound()
{
    m_uiBoundFlags = 0;
    pShape = 0;
}

#include "teswater_work.h"

// Updates the exterior cell grid around location, queues neighbouring cells, refreshes worldspace and physics, and returns 1 when the grid changed or 0 otherwise.
// @fnv 0x00452580
int TES::FindCellAtPosition(const NiPoint3* location, bool updatePhysics)
{
    FUN_0045bb80()->RemoveAll();
    InitFromMatrix();
    if (DAT_011c3c0c && !DAT_011f94aa && !IsCellInterior())
    {
        DAT_011c3c0c = false;
        InitSoundGrid();
    }
    if (g_BGSSaveLoadGame->FUN_0042ce10())
        ((LoadedAreaBound*)m_spLoadedAreaBound)->FUN_00628da0();
    ((LoadedAreaBound*)m_spLoadedAreaBound)->FUN_006271b0(GetDetailedActorPathHandler(), m_pGridCells);
    if (!g_dataHandler)
        return 0;
    if (iFirstValue == 0x7fffffff || iSecondValue == 0x7fffffff)
    {
        if (location)
        {
            iFirstValue = TruncateFloatToInt(location->x) >> 12;
            iSecondValue = TruncateFloatToInt(location->y) >> 12;
            m_iGridWidth = iFirstValue;
            m_iGridHeight = iSecondValue;
        }
        RefreshWorldState(1, (int)m_pContainingWorldspace, 0);
        FUN_004515a0(location, false);
        return 1;
    }
    struct WorldCoordinates
    {
        int x;
        int y;
    } position;
    position.x = TruncateFloatToInt(location->x);
    position.y = TruncateFloatToInt(location->y);
    int iGridDeltaX = position.x - ((iFirstValue << 12) + 2048);
    int iDeltaY = position.y - ((iSecondValue << 12) + 2048);
    float fThreshold = 4096.0f;
    if (DAT_011c63cc.Int()->ui == 3)
        fThreshold = 3072.0f;
    m_fFirstWorldspaceValue = fThreshold - FUN_00ec7d40(iGridDeltaX);
    m_fSecondWorldspaceValue = fThreshold - FUN_00ec7d40(iDeltaY);
    bool bIsLoading = false;
    bIsLoading = g_BGSSaveLoadGame->FUN_0042ce10();
    if (m_fFirstWorldspaceValue > 0.0 && m_fSecondWorldspaceValue > 0.0 && !bIsLoading)
    {
        if (DAT_011c9670.Bool()->b && !IsCellInterior())
        {
            int iQueueX = position.x >> 12;
            int iQueueY = position.y >> 12;
            if (m_iGridWidth != iQueueX || m_iGridHeight != iQueueY)
            {
                if (DAT_011c3d40.Bool()->b && GetInteriorBufferCount(true))
                    SetTESActive(false);
                int iHalfGridCount = DAT_011c63cc.Int()->ui >> 1;
                int iQueuedX = m_iGridWidth;
                int iQueueDX;
                if (iQueueDX = iQueueX - m_iGridWidth)
                {
                    iQueuedX += (iHalfGridCount + 1) * iQueueDX;
                    for (int j = -iHalfGridCount; j <= iHalfGridCount; j++)
                        DAT_011c9618->FUN_005283c0(FindCellByGridCoordinates(iQueuedX, j + m_iGridHeight));
                }
                int iY = m_iGridHeight;
                int iQueueDY;
                if (iQueueDY = iQueueY - m_iGridHeight)
                {
                    iY += (iHalfGridCount + 1) * iQueueDY;
                    for (int j = -iHalfGridCount; j <= iHalfGridCount; j++)
                        DAT_011c9618->FUN_005283c0(FindCellByGridCoordinates(j + m_iGridWidth, iY));
                }
                if (iQueueDX && iQueueDY)
                    DAT_011c9618->FUN_005283c0(FindCellByGridCoordinates(iQueuedX, iY));
            }
            m_iGridWidth = iQueueX;
            m_iGridHeight = iQueueY;
        }
        return 0;
    }
    FUN_00452e40(false);
    bool bIsLoadingMenu = Interface::IsGamePaused();
    if (!bIsLoadingMenu && DAT_011c9618->CallVirtual17() && !g_BGSSaveLoadGame->FUN_0042ce10())
    {
        FUN_004581e0("Loading Area (queued cells)...");
        bIsLoadingMenu = true;
    }
    int iGridX = position.x >> 12;
    int iGridY = position.y >> 12;
    if (g_BGSSaveLoadGame->FUN_0042ce10() && g_BGSSaveLoadGame->IsFlag20Set())
    {
        iGridX = iFirstValue;
        iGridY = iSecondValue;
    }
    iGridDeltaX = iGridX - iFirstValue;
    iDeltaY = iGridY - iSecondValue;
    iFirstValue = iGridX;
    iSecondValue = iGridY;
    m_iGridWidth = iFirstValue;
    m_iGridHeight = iSecondValue;
    DAT_011f9634 = DAT_011f962c;
    DAT_011f962c = NiPoint2((iFirstValue + 0.5) * 4096.0, (iSecondValue + 0.5) * 4096.0);
    if (DAT_011f9634.FUN_00452df0(DAT_011f4980) || FUN_00ec7d40(iGridDeltaX) > 1 || FUN_00ec7d40(iDeltaY) > 1)
        DAT_011f9634 = DAT_011f962c;
    DAT_011f94ac = FUN_00452e70(false);
    DAT_011c3c0c = true;
    DAT_011f94aa = DAT_011c3c0c;
    InitFromMatrix();
    InitSoundGrid();
    DAT_011c9618->ProcessQueries();
    int iQueued = DAT_011c9618->FUN_005281f0();
    if (iQueued)
        DAT_011c9618->FUN_005282d0();
    if (!IsCellInterior() || bIsLoading)
    {
        if (DAT_011c3d40.Bool()->b && GetInteriorBufferCount(true))
            SetTESActive(false);
        if (!GetParentWorldSpace())
            AssignWorldSpace(g_dataHandler->GetSourceFiles()->GetItem());
        bool bMovedFar = false;
        if (FUN_00ec7d40(iGridDeltaX) > 1 || FUN_00ec7d40(iDeltaY) > 1)
            bMovedFar = true;
        if (TESObjectCELL::GetExteriorbhkWorld())
        {
            if (bMovedFar || !updatePhysics)
            {
                TESObjectCELL::GetExteriorbhkWorld()->FUN_00c6b540(false);
                TESObjectCELL::GetExteriorbhkWorld()->SetWorldActive(false);
            }
            TESObjectCELL::GetExteriorbhkWorld()->FUN_00c66310();
        }
        m_pGridCells->SetGridPosition(iGridX, iGridY);
        if (TESObjectCELL::GetExteriorbhkWorld())
        {
            if (!bIsLoadingMenu && (!bMovedFar || !DAT_011c9618->CallVirtual17()))
                TESObjectCELL::GetExteriorbhkWorld()->RefreshWorld();
            if (bMovedFar)
                TESObjectCELL::GetExteriorbhkWorld()->SetWorldActive(false);
            else
                TESObjectCELL::GetExteriorbhkWorld()->SetWorldActive(updatePhysics);
        }
        if (!bIsLoadingMenu && !IsCellBuffering() && !g_BGSSaveLoadGame->FUN_0042ce10())
        {
            FUN_004581e0("Loading Area (unloaded cells)...");
            bIsLoadingMenu = true;
        }
        if (FUN_00ec7d40(iGridDeltaX) > 1 || FUN_00ec7d40(iDeltaY) > 1)
            SetSkyMode(0);
        if (TESObjectCELL::GetExteriorbhkWorld())
            TESObjectCELL::GetExteriorbhkWorld()->FUN_00c66300();
        RefreshGrid();
        FUN_00452e50();
        if (TESObjectCELL::GetExteriorbhkWorld())
        {
            if (bMovedFar)
                TESObjectCELL::GetExteriorbhkWorld()->FUN_00c6b540(false);
            else
                TESObjectCELL::GetExteriorbhkWorld()->FUN_00c6b540(updatePhysics);
        }
    }
    SetTESActive(false);
    RefreshWorldSpace();
    if (!IsCellInterior())
        m_pContainingWorldspace->GetWorldTerrainManager()->Update(g_thePlayer->GetPos(), 15);
    FUN_00452e40(true);
    return 1;
}

// @fnv 0x004e59f0
WaterSurface* WaterZoneManager::GetWaterZone(TESObjectREFR* apWaterRef, TESObjectREFR* apLookupRef, float afHeight)
{
    NiPoint3 kNormal(0.0f, 0.0f, 1.0f);
    NiPoint3 kPosition = NiPoint3::ZERO;
    TESWaterForm* m_pOwningWater = 0;
    if (apWaterRef)
    {
        if (!apWaterRef->GetNiNode_v())
            return 0;
        kNormal = apWaterRef->GetNiNode_v()->FUN_00461130() * kNormal;
        kNormal.ComputeMagnitude();
        kPosition = apWaterRef->GetNiNode_v()->FUN_0045bb80();
        m_pOwningWater = apWaterRef->GetObjectReference()->GetAssociatedWaterForm();
    }
    else
    {
        kPosition = NiPoint3(0.0f, 0.0f, afHeight);
        m_pOwningWater = apLookupRef->GetParentCell()->GetAssociatedWaterForm();
    }
    NiPlane m_kFogPlane(kNormal, kPosition);
    void* pGroupPos = m_kWaterZoneList.GetHeadPos();
    {
        void* pNextPos = 0;
        WaterSurface* pWaterGroup = 0;
        while (pGroupPos)
        {
            pNextPos = m_kWaterZoneList.DereferenceIfNotNull(pGroupPos);
            if (pGroupPos)
            {
                pWaterGroup = m_kWaterZoneList.AddEight(pGroupPos);
                if (AreVectorsEqual(pWaterGroup->m_kWaterPlane.GetPlaneNormal(), m_kFogPlane.GetPlaneNormal(), 0.01f) &&
                    IsApproximatelyEqual(pWaterGroup->m_kWaterPlane.FUN_0084d030(), m_kFogPlane.FUN_0084d030(),
                                         0.01f) &&
                    pWaterGroup->m_pOwningWater == m_pOwningWater)
                {
                    if (!apWaterRef)
                        return pWaterGroup;
                    else
                    {
                        void* pPlaceablePos = pWaterGroup->m_kWaterReferences.GetHeadPos();
                        for (void* pNextRef = 0; pPlaceablePos;)
                        {
                            pNextRef = pWaterGroup->m_kWaterReferences.DereferenceIfNotNull(pPlaceablePos);
                            if (pPlaceablePos)
                            {
                                TESObjectREFR* pRef = pWaterGroup->m_kWaterReferences.AddEight(pPlaceablePos);
                                if (!apWaterRef || pRef == apWaterRef)
                                    return pWaterGroup;
                                pPlaceablePos = pNextRef;
                            }
                        }
                    }
                }
            }
            pGroupPos = pNextPos;
        }
    }
    return 0;
}

// @fnv 0x004e5df0
void WaterZoneManager::UpdateWaterZone(TESObjectREFR* apWaterRef, TESObjectREFR* apLookupRef, float afHeight)
{
    if (!apWaterRef && (!apLookupRef || !apLookupRef->GetParentCell()))
        return;
    WaterSurface* pGroup = GetWaterZone(apWaterRef, apLookupRef, afHeight);
    if (!pGroup)
        return;
    RemoveReferenceFromCell(apLookupRef, pGroup);
}

struct FUN_004e2120_s
{
    void f(bool abUnderWater);
};
// @fnv 0x004e2120
void FUN_004e2120_s::f(bool abUnderWater)
{
    *((bool*)this + 0x167) = abUnderWater;
}

struct BSMultiBoundNode;
struct BSParticleSystemManager;
struct BSRenderedTexture;
struct BSShaderAccumulator;
struct Controls;
struct EngineGraphicsType;
struct HINSTANCE__;
struct HWND__;
struct ImageSpaceManager;
struct NiAVObject;
struct NiCamera;
struct NiGeometry;
struct NiRenderedTexture;
struct GraphicsRenderer;
struct SceneGraph;
struct Sun;
struct Main
{
    void Main_AudioInit();
    void SetSceneRoot(NiNode*);
    void InitRenderer();
    void PreSwapProcess();
    void Swap();
    void PostSwapProcess();
    void DrawWorld_BeginRenderTarget(BSRenderedTexture*, bool, bool);
    void DrawWorld_ClearRenderTarget(BSRenderedTexture*, bool);
    void DrawWorld_CopyRenderTarget(BSRenderedTexture*, bool);
    void DrawWorld_ResolveRenderTarget(BSRenderedTexture*, bool);
    void DrawWorld_EndRenderTarget(BSRenderedTexture*);
    void DrawWorld_DoSunShafts(BSRenderedTexture*, ImageSpaceManager*, GraphicsRenderer*, Sun*);
    void DrawWorld_StopRenderTarget(bool, BSRenderedTexture*);
    void DrawWorld_RenderGeometry(NiGeometry*, GraphicsRenderer*);
    void DrawWorld_CopyDepth(bool, BSRenderedTexture*, GraphicsRenderer*, BSRenderedTexture*);
    void DrawWorld_DoDepth(BSShaderAccumulator*, BSRenderedTexture*);
    void DrawWorld_DoVolumetricFog(BSShaderAccumulator*, BSRenderedTexture*);
    void DrawWorld_FinishRender();
    void DrawWorld_PrepareRender();
    void DrawWorld_RenderSunGeometry(GraphicsRenderer*, NiGeometry*, Sun*, BSRenderedTexture*);
    void DrawWorld_DoVelocity(ImageSpaceManager*, GraphicsRenderer*, BSRenderedTexture*);
    void DrawWorld_DoImageSpace(ImageSpaceManager*, GraphicsRenderer*, bool, BSRenderedTexture*);
    void DrawWorld_Navmesh();
    void DrawWorld_RestartRenderTexture(BSRenderedTexture*, bool, unsigned int);
    void DrawWorld_VATS(bool);
    void DrawWorld_RenderAccumulator(BSShaderAccumulator*, BSRenderedTexture*);
    void DrawWorld_ResolveColor(BSRenderedTexture*);
    void DrawWorld_ResolveDepth(BSRenderedTexture*);
    void DrawWorld_ClearRenderState();
    void DrawWorld_WaitForParallelUpdate();
    Sun* DrawWorld_Init();
    bool DrawWorld_VATSOcclusionQuery();
    void DrawWorld_PrepareScreenSplatter();
    BSRenderedTexture* DrawWorld_GetRenderTarget(GraphicsRenderer*, BSRenderedTexture*, bool, bool);
    void DrawWorld_RenderSun(Sun*, bool, bool, bool);
    void DrawWorld_ScreenSplatter(GraphicsRenderer*);
    void DrawWorld_PostScreenSplatter();
    void DrawWorld_Finalize();
    void OnIdle_ScaleLOD();
    void OnIdle_FixActorBones();
    void OnIdle_UpdateMessageBox();
    void OnIdle_UpdateTimer();
    void OnIdle_ProcessPostTimerTask();
    void OnIdle_ProcessTaskBeforeGridA();
    void OnIdle_ProcessTaskBeforeGridB();
    void OnIdle_ProcessTaskBeforeGridC();
    void OnIdle_ProcessTaskBeforeGridD();
    void OnIdle_UpdateCurrentGridCell();
    void OnIdle_ProcessTaskBeforeInterface();
    void OnIdle_DoInterfaceIdle();
    void OnIdle_UpdateImageSpace(bool);
    void OnIdle_ProcessPostImageSpaceTask();
    bool UpdateTextures(float);
    bool IsLocationHighDetail(void*);
    void ForceUpdateTextures();
    void RestoreTextureRangeDefaults();
    void RunCameraPath();
    void OnGameLoaded();
    void RunScripts();
    void DrawDebugText();
    static TESObjectREFR* GetDebugTextRef();
    static void ClearDebugTextRef();
    void QuitGame();
    void ResetGame();
    void SetGame();
    bool GameReset();
    bool GameOver();
    void GameInitialize();
    bool GameReload();
    bool IsSaveLoadActive();
    void ChangeSignedInPlayer();
    void SetSignedInState(bool);
    static void ForceFileCacheCallback(bool);
    static void ClearCustomLaunchData();
    void SetCustomLaunchData(EngineGraphicsType*);
    bool IsThisAReboot();
    void SetActive(bool);
    bool GetActive();
    void SetOnIdle(bool);
    bool GetOnIdle();
    HWND__* GetWindow();
    HINSTANCE__* GetInstance();
    unsigned long GetThread();
    void* GetThreadHandle();
    Controls* GetInputControls();
    bool WmMouseMove(int, int);
    void RefreshAfterSave();
    static NiAVObject* GetSceneGraph(int);
    static SceneGraph* GetWorldSceneGraph();
    static NiNode* WorldRootNode();
    static NiCamera* WorldRootCamera();
    static BSMultiBoundNode* SkyRootNode();
    static NiNode* WeatherRootNode();
    static SceneGraph* MenuRootNode();
    static NiCamera* MenuRootCamera();
    static SceneGraph* MenuRootNode3D();
    static NiCamera* MenuRootCamera3D();
    static void FreeMenuRootNode();
    static void FreeMenuRootNode3D();
    static void CreateMenuRootNode();
    static void CreateMenuSceneGraph();
    static NiNode* LandLODNode();
    static NiNode* ObjectLODNode();
    static NiNode* WaterLODNode();
    static void SetSceneIsComplex(bool);
    static bool GetSceneIsComplex();
    static BSParticleSystemManager* GetMasterParticleSystemManager();
    void RunFrame();
    bool QQuit();
    static unsigned int QFrameCount();
    bool GetFreezeTime();
    void SetFreezeTime(bool);
    bool GetFlyCamera();
    void SetFlyCamera(bool);
    NiRenderedTexture* GetMenuBGTexture();
    static float QFrameAnimTime();
    static bool QFaderToBlackVisible();
    static bool GetOpenConsole();
    static void SetOpenConsole(bool);
    BSShaderAccumulator* QDrawWorldAccum();
    void TakeMenuBackgroundPicture();
    bool ArePathsEqual(char*, char*);
    void* __vecDelDtor(unsigned int);
    bool m_bStateFlag;
    bool m_bSecondaryStateFlag;
    bool m_bTertiaryStateFlag;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    bool m_bSeventhStateFlag;
    bool m_bEighthStateFlag;
    EngineGraphicsType* m_pAssociatedObject;
    bool m_bWindowActive;
    char _pad_d[3];
    HWND__* hWnd;
    HINSTANCE__* hInstance;
    unsigned long m_uiThreadId;
    void* m_pUserData;
    char m_cBuffer20A[20];
    char TaskProcessor[40];
    char m_cBuffer20B[20];
    char m_cBuffer40A[40];
    char m_acDataA[4];
    char m_acDataB[4];
    char m_acDataC[4];
    char m_acDataD[4];
    char m_acStateData[4];
    bool m_bStateDataFlag;
    char _pad_ad[3];
    char m_acTrailingData[4];
};
typedef char _sizecheck_Main[sizeof(Main) == 180 ? 1 : -1];
struct FUN_004e2190_shell : public Main
{
    BSShaderAccumulator* FUN_004e2190();
};

template <typename T> struct BSStringT
{
    operator const char*() const;
};

// @fnv 0x004e2190
BSShaderAccumulator* FUN_004e2190_shell::FUN_004e2190()
{
    return (BSShaderAccumulator*)(const char*)(*(BSStringT<char>*)((char*)this + 0x88));
}

double __cdecl FUN_00ec9e10(double);

// @fnv 0x004e4450
float __cdecl FUN_004e4450(float _X)
{
    return static_cast<float>(FUN_00ec9e10(_X));
}

float __cdecl FUN_004b1520(float, float);

// Wraps *aVal into [aMin, aMax] using FUN_004b1520 when it is out of range; returns early if aMin > aMax.
// @fnv 0x004e44f0
void __cdecl WrapValueToRange(float* aVal, float aMin, float aMax)
{
    if (aMin > aMax)
        return;

    if (*aVal > aMax)
    {
        *aVal = FUN_004b1520(*aVal - aMin, aMax - aMin) + aMin;
    }
    else if (*aVal < aMin)
    {
        *aVal = FUN_004b1520(*aVal - aMin, aMax - aMin) + aMax;
    }
}

namespace fnv_004e6540 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x004e6540
const char* __fastcall FUN_004e6540(char* this_ptr)
{
    return *(const BSStringT<char>*)(this_ptr + 0xf8);
}
}  // namespace fnv_004e6540

struct NiRenderer
{
    int FUN_004e9530(void);
};

NiRenderer* __cdecl FUN_0043c4b0(void);

// @fnv 0x004e9510
bool __cdecl FUN_004e9510()
{
    return FUN_0043c4b0()->FUN_004e9530() == 0;
}

struct M9c10
{
    void FUN_00439f50(unsigned int, NiPoint3&);
};
struct S9c10
{
    char pad[0x68];
    M9c10 m;
    NiPoint3 GetPoint();
};
// Calls m.FUN_00439f50 with 1 and an uninitialized NiPoint3, then returns that NiPoint3.
// @fnv 0x004e9c10
NiPoint3 S9c10::GetPoint()
{
    NiPoint3 k;
    m.FUN_00439f50(1, k);
    return k;
}

struct M9c50
{
    void FUN_00439f50(unsigned int, NiPoint3&);
};
struct S9c50
{
    char pad[0x68];
    M9c50 m;
    NiPoint3 FUN_004e9c50();
};
// Calls m.FUN_00439f50 with index 2 to fill a NiPoint3 and returns it.
// @fnv 0x004e9c50
NiPoint3 S9c50::FUN_004e9c50()
{
    NiPoint3 k;
    m.FUN_00439f50(2, k);
    return k;
}

// @fnv 0x004ea950
int __fastcall FUN_004ea950(int param_1)
{
    return param_1 + 0x60;
}

struct FUN_004eaf60_shell : public PlayerCharacter
{
    bool FUN_004eaf60();
};

// @fnv 0x004eaf60
bool FUN_004eaf60_shell::FUN_004eaf60()
{
    return *((bool*)this + 0x64a);
}

struct BSRenderedTexture;
struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceTexture;
struct RgbaColor;
struct NiScreenElements;
struct NiTexture;
struct GraphicsRenderer;
struct blob16
{
    char b[16];
};
struct ImageSpaceManager
{
    void Initialize();
    void Shutdown();
    void InitDefaultParameter();
    ImageSpaceEffect* GetEffect(int);
    void AddEffect(int, ImageSpaceEffect*);
    bool IsEffectActive(int);
    void SetupEffects();
    void SetupShader();
    void RenderEndOfFrameEffects(GraphicsRenderer*, BSRenderedTexture**, BSRenderedTexture**);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*,
                      bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, NiTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(ImageSpaceEffect*, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*,
                      ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void RenderEffect(int, GraphicsRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, bool);
    void ModifyParameterData(int, unsigned int, int, float);
    void ApplyCurrentParameterData(bool);
    void SetBaseParameterData(void*);
    void SetOverrideBaseParameterData(void*);
    void ResetToBaseParameterData();
    void ResetWeatherData();
    void BeginParamModifiers();
    void ApplyParamModifier(int, unsigned int, float*, float);
    void ApplyParamModifierWeather(int, unsigned int, float*, float);
    void ApplyTintColorParamModifier(RgbaColor*);
    void ApplyTintColorParamModifierWeather(RgbaColor*);
    void SetFadeColorParamModifier(RgbaColor*);
    void ApplyFadeColorParamModifierWeather(RgbaColor*);
    void SetBlurRadiusParamModifier(float);
    void ApplyBlurRadiusParamModifierWeather(float);
    void ApplyDoubleVisionParamModifier(float);
    void ApplyDoubleVisionParamModifierWeather(float);
    void SetRadialBlurParameters(float, float, float, float, float, void*);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, float, float, void*);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, void*);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDepthOfFieldParameters(float, unsigned int, float, void*);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void ApplyMotionBlurStrengthParamModifier(float);
    void ApplyMotionBlurStrengthParamModifierWeather(float);
    void EndWeatherModifiers();
    void EndParamModifiers();
    float ApplyOperation(int, float, float);
    void GetRadialBlurCenterFromWorldBound(void*, NiPoint2*);
    void GetDepthOfFieldParamsFromWorldBound(void*, NiPoint2*);
    void EnableSunbeams(bool);
    void SetSunPosition(void*);
    BSRenderedTexture* GetRefractionNormalsTexture(bool);
    BSRenderedTexture* GetVolumetricFogTexture();
    void ReturnVolumetricFogTexture();
    float GetHDREmissiveMult();
    float GetHDRBlurRadius();
    float GetHDRBrightClamp();
    float GetHDRBrightScale();
    float GetHDREyeAdaptSpeed();
    float GetHDRTargetLUM();
    float GetHDRUpperLUMClamp();
    void SetVolumetricFogProps(struct blob16);
    void SetMotionBlurConst(float);
    void SetMenuBGBlendEnabled(bool);
    void SetMenuBGBlendValue(float);
    void EnablePartialRender(bool, NiScreenElements*);
    void SetMenuBackgroundBlend(float, float, void*);
    NiTexture* GetDepthTexture();
    ImageSpaceTexture* GetDepthImageSpaceTexture();
    BSRenderedTexture* GetDepthRenderedTexture();
    void SetDepthTexture(BSRenderedTexture*);
    void SetDepthTexture(NiTexture*);
    void ReturnDepthTexture();
    NiScreenElements* GetMenuUnpackGeom();
    void SetMenuUnpackGeom(NiScreenElements*);
    void SetRefractionTint(void*);
    void* GetRefractionTint();
    void SetCustomViewPort(float, float, float, float);
    void ClearCustomViewPort();
    void* GetCustomViewport();
    BSRenderedTexture* GetSwapTarget();
    void InitEffects();
    void CreateMenuBackgroundGeometry();
    void ShutdownEffects();
    void ShutdownGeometry();
    void PrepareEndOfFrameEffects();
    void* __vecDelDtor(unsigned int);
    BSRenderedTexture* m_pCurrentRenderedTexture;
    char pEffectList[16];
    char m_kBlendedParameterData[152];
    void* m_pCurrentModifierParameterData;
    void* m_pPreviousModifierParameterData;
    char m_kModifierParameterData[304];
    bool m_bEndOfFrameEffectsEnabled;
    char _pad_1e5[3];
    int m_iEndOfFrameEffectCount;
    int m_eEndOfFrameEffect;
    char m_pMenuBackgroundScreenGeometry[4];
    char m_pMenuBackgroundScreenElementsData[4];
    char m_pMenuBackgroundScreenElements[4];
    bool m_bPartialRenderEnabled;
    char _pad_1fd[3];
    char m_pPartialRenderScreenElements[4];
    char m_kDepthTexture[16];
    char m_kModifierColor[16];
    char m_kPartialRenderColor[16];
    float m_fPartialRenderBlend;
    char m_kAccumulatedColor[16];
    char m_kWeatherFadeColor[16];
    float m_fFadeColorAlpha;
    float m_fDoubleVisionStrength;
    float m_fWeatherBlurRadius;
    float m_fWeatherDoubleVisionStrength;
    float m_fAdditionalImageSpaceValue;
    float m_fRadialBlurStrength;
    float m_fRadialBlurRampUp;
    float m_fRadialBlurStart;
    float m_fRadialBlurRampDown;
    float m_fRadialBlurDownStart;
    float m_fWeatherRadialBlurStrength;
    float m_fWeatherRadialBlurRampUp;
    float m_fWeatherRadialBlurStart;
    float m_fWeatherRadialBlurRampDown;
    float m_fWeatherRadialBlurDownStart;
    NiPoint2 m_kRadialBlurCenter;
    NiPoint2 m_kWeatherRadialBlurCenter;
    float m_fDepthOfFieldStrength;
    float m_fDepthOfFieldMaskConstant;
    float m_fDepthOfFieldDistance;
    float m_fDepthOfFieldRange;
    float m_fDepthOfFieldEffectStrength;
    float m_fDepthOfFieldEffectDistance;
    float m_fDepthOfFieldEffectRange;
    float m_fDepthOfFieldMaskValue;
    int m_eDepthOfFieldMode;
    int m_eDepthOfFieldTargetMode;
    bool m_bDepthOfFieldUsesObject;
    bool m_bMenuBackgroundBlendEnabled;
    char _pad_2ce[2];
    float m_fBlurRadius;
    float m_fRadialBlurTransition;
    float m_fRadialBlurStartValue;
    float m_fRadialBlurDistance;
    float m_fRadialBlurRange;
    NiPoint2 m_kRadialBlurOrigin;
    int m_eRadialBlurMode;
    float m_fMenuBackgroundBlendValue;
    float m_fMenuBackgroundBlendTarget;
    char m_kMenuBackgroundTint[16];
    char m_kMenuBackgroundRect[16];
    BSRenderedTexture* m_pMenuBackgroundTexture;
};
typedef char _sizecheck_ImageSpaceManager[sizeof(ImageSpaceManager) == 796 ? 1 : -1];
struct FUN_004ebbc0_shell : public ImageSpaceManager
{
    ImageSpaceEffect* FUN_004ebbc0(int);
};

template <class T, int N> class BSSimpleArray
{
  public:
    T& GetAt(unsigned int);
};

// @fnv 0x004ebbc0
ImageSpaceEffect* FUN_004ebbc0_shell::FUN_004ebbc0(int aiIndex)
{
    return (ImageSpaceEffect*)((BSSimpleArray<unsigned int, 1024>*)pEffectList)->GetAt(aiIndex);
}

extern double DAT_010231e8;

struct StackArgs_004ed230
{
    int aeType;
    float fScaledValue;
    float fMin;
};

// @fnv 0x004ed230
float __fastcall FUN_004ed230(const unsigned char* _this, StackArgs_004ed230 args)
{
    return (_this + args.aeType)[0xe0] * DAT_010231e8 * (args.fScaledValue - args.fMin) + args.fMin;
}

// @fnv 0x004ed270
bool __fastcall IsFlagBit2Set(const unsigned char* _this)
{
    return (_this[0xeb] & 4) != 0;
}

struct FUN_00507700_cls
{
    char pad[0xfc];
    float fMaxFarNearRatio;
    void FUN_00507700(float fScaledValue);
};

// @fnv 0x00507700
void FUN_00507700_cls::FUN_00507700(float afRatio)
{
    fMaxFarNearRatio = afRatio;
}

// @fnv 0x006447d0
float __fastcall FUN_006447d0(const char* pThis)
{
    return *(const float*)(pThis + 0xf4);
}

struct S5460
{
    virtual void v0();
    virtual void* v1(unsigned int);
    void* data;
    unsigned int count;
    unsigned int cap;
    bool FUN_00438b90();
    unsigned int FUN_009a3910();
    void FUN_006a2770(unsigned int, unsigned int);
    unsigned int FUN_00845460();
};
// @fnv 0x00845460
unsigned int S5460::FUN_00845460()
{
    if (FUN_00438b90())
    {
        if (cap == 0)
        {
            unsigned int uiNewCapacity = 4;
            data = v1(uiNewCapacity);
            cap = uiNewCapacity;
        }
        else
        {
            unsigned int uiNewCapacity = FUN_009a3910();
            FUN_006a2770(uiNewCapacity, count);
            cap = uiNewCapacity;
        }
    }
    count++;
    return count - 1;
}

class GlobalObject_0045cf30
{
  public:
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011c7b20;

// @fnv 0x004e2160
bool FUN_004e2160()
{
    return g_011c7b20.Bool()->b;
}

extern unsigned char DAT_011c7a59;

// @fnv 0x004e2180
unsigned char FUN_004e2180()
{
    return DAT_011c7a59;
}

extern int g_011ca13c;

// @fnv 0x004e3260
int* __cdecl FUN_004e3260()
{
    return &g_011ca13c;
}

struct FUN_004e32c0_shell
{
    void __thiscall HasFlags(int);
    void __thiscall FUN_004e32c0();
};

// @fnv 0x004e32c0
void __thiscall FUN_004e32c0_shell::FUN_004e32c0()
{
    HasFlags(0x8000000);
}

struct FUN_004e45e0_shell
{
    float __thiscall GetFieldE8Float();
};

// @fnv 0x004e45e0
float __thiscall FUN_004e45e0_shell::GetFieldE8Float()
{
    return *(float*)((char*)this + 0xe8);
}

struct FUN_004e4600_shell
{
    float FUN_004e4600();
};

// @fnv 0x004e4600
float FUN_004e4600_shell::FUN_004e4600()
{
    return *(float*)((char*)this + 0xf0);
}

struct FUN_004e4620_shell
{
    virtual ~FUN_004e4620_shell();
    float FUN_004e4620();
};

// @fnv 0x004e4620
float FUN_004e4620_shell::FUN_004e4620()
{
    return *(float*)((char*)this + 0xf8);
}

struct FUN_004e4640_shell
{
    char GetByteAtOffset190();
};

// @fnv 0x004e4640
char FUN_004e4640_shell::GetByteAtOffset190()
{
    return *(char*)((char*)this + 0x190);
}

struct FUN_004e4660_shell
{
    void SetByteAtOffset190(unsigned char b);
};

// @fnv 0x004e4660
void FUN_004e4660_shell::SetByteAtOffset190(unsigned char abValue)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x190) = abValue;
}

extern int DAT_011ffe44;

// @fnv 0x004e4680
int FUN_004e4680()
{
    return DAT_011ffe44;
}

struct FUN_004e4690_shell
{
    unsigned char GetByteAtOffset2B8();
};

// @fnv 0x004e4690
unsigned char FUN_004e4690_shell::GetByteAtOffset2B8()
{
    return *(unsigned char*)((char*)this + 0x2b8);
}

struct FUN_004e6560_class
{
    short __thiscall FUN_004e6560();
};

// @fnv 0x004e6560
short __thiscall FUN_004e6560_class::FUN_004e6560()
{
    return *reinterpret_cast<short*>(reinterpret_cast<char*>(this) + 0x110);
}

extern int DAT_011ff370;

// @fnv 0x004e69d0
int FUN_004e69d0()
{
    return DAT_011ff370;
}

struct NP
{
    NP& operator=(void*);
};

struct FUN_004e69e0_shell
{
    NP m_NP;  // at offset 0x23c
    void FUN_004e69e0(void* arg);
};

// @fnv 0x004e69e0
void FUN_004e69e0_shell::FUN_004e69e0(void* arg)
{
    *(NP*)((char*)this + 0x23c) = arg;
}

namespace fnv_004e6a00 {
struct NP
{
    NP& operator=(void*);
};

struct FUN_004e6a00_shell
{
    NP* member_238;
    void AssignMember238(void* arg);
};

// @fnv 0x004e6a00
void FUN_004e6a00_shell::AssignMember238(void* arg)
{
    ((NP*)(((char*)this) + 0x238))->operator=(arg);
}
}  // namespace fnv_004e6a00

namespace fnv_004e6a20 {
struct NP
{
    NP& operator=(void*);
};

struct FUN_004e6a20_shell
{
    NP m_field;  // +0x248
    void SetParam(void* apParam);
};

// @fnv 0x004e6a20
void FUN_004e6a20_shell::SetParam(void* apParam)
{
    *(reinterpret_cast<NP*>(this) + 0x248) = apParam;
}
}  // namespace fnv_004e6a20

namespace fnv_004e6a40 {
struct NP
{
    NP& operator=(void*);
};

struct FUN_004e6a40_shell
{
    NP m_NP;  // +0x24c
    void FUN_004e6a40(void* a1);
};

// @fnv 0x004e6a40
void FUN_004e6a40_shell::FUN_004e6a40(void* apNP)
{
    *(NP*)((char*)this + 0x24c) = apNP;
}
}  // namespace fnv_004e6a40

extern int DAT_011ffff8;

// @fnv 0x004e6a60
int FUN_004e6a60()
{
    return DAT_011ffff8;
}

extern int DAT_0120006c;

// @fnv 0x004e6a70
int __cdecl FUN_004e6a70()
{
    return DAT_0120006c;
}

extern SettingT_GameSettingCollection_ g_011c7b2c;

struct FUN_004e7600_shell
{
    int __thiscall GetIntValue();
};

// @fnv 0x004e7600
int __thiscall FUN_004e7600_shell::GetIntValue()
{
    return g_011c7b2c.Int()->i;
}

namespace fnv_004e9530 {
struct NiRenderer
{
    virtual ~NiRenderer();
    unsigned int FUN_004e9530();
};

// @fnv 0x004e9530
unsigned int NiRenderer::FUN_004e9530()
{
    return *(unsigned int*)((char*)this + 0x200);
}
}  // namespace fnv_004e9530

extern unsigned short DAT_011f941c;

// Sets or clears bit (index % 16) of DAT_011f941c according to set.
// @fnv 0x004e9ce0
void FUN_004e9ce0(int index, bool set)
{
    unsigned int r = (unsigned int)index % 0x10;
    unsigned int uiMask = 1 << r;
    if (set)
        DAT_011f941c |= uiMask;
    else
        DAT_011f941c &= ~uiMask;
}

struct FUN_004ea860_shell
{
    unsigned char bFlag;
    void FUN_004ea860(unsigned char param);
};

// @fnv 0x004ea860
void FUN_004ea860_shell::FUN_004ea860(unsigned char abFlag)
{
    *(unsigned char*)(this + 0x164) = abFlag;
}

struct FUN_00452460_shell
{
    bool HasFlags(int b);
};

bool FUN_00452460_shell::HasFlags(int b)
{
    return b == 0x40;
}

struct FUN_004ea930_shell
{
    bool FUN_004ea930();
};

// @fnv 0x004ea930
bool FUN_004ea930_shell::FUN_004ea930()
{
    return reinterpret_cast<FUN_00452460_shell*>(this)->HasFlags(0x40);
}

extern "C" void __cdecl UpdateSpawnedObjectFlags(int, int, int, int, int, int, int);
extern int DAT_011ffa14;

// Subtracts param_1 from DAT_011ffa14, then calls UpdateSpawnedObjectFlags with all-zero arguments.
// @fnv 0x004eb510
void FUN_004eb510(int param_1)
{
    DAT_011ffa14 = DAT_011ffa14 - param_1;
    UpdateSpawnedObjectFlags(0, 0, 0, 0, 0, 0, 0);
}

extern int g_011ca144;

// @fnv 0x004ec7b0
int* FUN_004ec7b0()
{
    return &g_011ca144;
}

struct FUN_004ec7c0_shell
{
    void FUN_004ec7c0(bool value);
};

// @fnv 0x004ec7c0
void FUN_004ec7c0_shell::FUN_004ec7c0(bool value)
{
    ((char*)this)[0x165] = value;
}

struct FUN_004ec7e0_shell
{
    void __thiscall HasFlags(int);
    void __thiscall FUN_004ec7e0();
};

// @fnv 0x004ec7e0
void FUN_004ec7e0_shell::FUN_004ec7e0()
{
    this->HasFlags(0x400);
}

struct FUN_004ecaf0_shell
{
    unsigned int __thiscall GetField8B8();
};

// @fnv 0x004ecaf0
unsigned int __thiscall FUN_004ecaf0_shell::GetField8B8()
{
    return *(unsigned int*)(this + 0x8b8);
}

extern int DAT_011ff9d8[];

// Decrements the counter at DAT_011ff9d8[a] if it is nonzero.
// @fnv 0x004ecb10
void __cdecl FUN_004ecb10(int aiIndex)
{
    if (DAT_011ff9d8[aiIndex] != 0)
    {
        DAT_011ff9d8[aiIndex]--;
    }
}

extern "C" void __cdecl UpdateRendererStateCount(unsigned int, unsigned int);
extern unsigned int DAT_011ff9fc;

// @fnv 0x004ecb40
void __cdecl FUN_004ecb40(unsigned int auiAmount)
{
    DAT_011ff9fc = DAT_011ff9fc - auiAmount;
    UpdateRendererStateCount(0, 0);
}

struct BSRenderStateManager
{
    static void __cdecl SetColorWriteMask(unsigned int, unsigned int);
};

extern unsigned int DAT_011ffa18;

// @fnv 0x004eced0
void __cdecl FUN_004eced0(unsigned int auiAmount)
{
    DAT_011ffa18 -= auiAmount;
    BSRenderStateManager::SetColorWriteMask(7, 0);
}

extern void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

struct FUN_004ed110_shell
{
    void* __thiscall CopyFrom(const void* src);
};

// Copies 0x40 bytes from src into this object and returns this.
// @fnv 0x004ed110
void* FUN_004ed110_shell::CopyFrom(const void* apSource)
{
    _memmove(this, apSource, 0x40);
    return this;
}

extern NiPoint3 DAT_011f474c;

// @fnv 0x004ed180
NiPoint3* FUN_004ed180()
{
    return &DAT_011f474c;
}

struct FUN_004ed1f0_shell
{
    void* GetOffset980();
};

// @fnv 0x004ed1f0
void* FUN_004ed1f0_shell::GetOffset980()
{
    return reinterpret_cast<char*>(this) + 0x980;
}

struct FUN_004ed210_shell
{
    void* GetOffsetPointer();
};

// @fnv 0x004ed210
void* FUN_004ed210_shell::GetOffsetPointer()
{
    return reinterpret_cast<char*>(this) + 0x9C0;
}

extern unsigned char DAT_01189624;

// @fnv 0x005d2a40
unsigned char FUN_005d2a40()
{
    return DAT_01189624;
}

void UpdateSoundListItems();

// @fnv 0x006fd1b0
void FUN_006fd1b0()
{
    UpdateSoundListItems();
}

extern "C" void __cdecl FUN_006fd1d0(int);

// @fnv 0x006fd1c0
void FUN_006fd1c0()
{
    FUN_006fd1d0(1);
}

extern unsigned char DAT_011f5b3c;

// @fnv 0x006fd1d0
void FUN_006fd1d0(unsigned char value)
{
    DAT_011f5b3c = value;
}

extern "C" void __cdecl FUN_006fd1d0(int);

// @fnv 0x006fd1e0
void __cdecl FUN_006fd1e0()
{
    FUN_006fd1d0(0);
}

struct FUN_004e2140_shell
{
    void SetValue(int value);
};

// @fnv 0x004e2140
void FUN_004e2140_shell::SetValue(int value)
{
    *(int*)((char*)this + 0x168) = value;
}

struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
};

bool BGSPlaceableWater::HasFlags(unsigned int)
{
    return true;
}

struct FUN_004e32a0_shell
{
    BGSPlaceableWater m_water;
    void FUN_004e32a0();
};

// @fnv 0x004e32a0
void FUN_004e32a0_shell::FUN_004e32a0()
{
    m_water.HasFlags(0x800);
}

struct FUN_004e45c0_shell
{
    float __thiscall GetField130();
};

// @fnv 0x004e45c0
float __thiscall FUN_004e45c0_shell::GetField130()
{
    return *(float*)((char*)this + 0x130);
}

struct GlobalObject2_0045cfe0 : SettingT_GameSettingCollection_
{
};
extern GlobalObject2_0045cfe0 g_011c7bb0;

struct FUN_004e7620_shell
{
    int __thiscall GetGameSettingInt();
};

// @fnv 0x004e7620
int __thiscall FUN_004e7620_shell::GetGameSettingInt()
{
    return g_011c7bb0.Int()->i;
}

struct Setting_S
{
    float* Float();
};

struct GlobalObject_0044f440
{
    float* Float();
};

extern GlobalObject_0044f440 g_011c7bd8;

struct FUN_004e7640_shell
{
    float FUN_004e7640();
};

// @fnv 0x004e7640
float __thiscall FUN_004e7640_shell::FUN_004e7640()
{
    return *g_011c7bd8.Float();
}

namespace fnv_004ea8b0 {
struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
    bool FUN_004ea8b0();
};

// @fnv 0x004ea8b0
bool BGSPlaceableWater::FUN_004ea8b0()
{
    return BGSPlaceableWater::HasFlags(4);
}
}  // namespace fnv_004ea8b0

namespace fnv_004ea8d0 {
struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
    bool FUN_004ea8d0();
};

bool BGSPlaceableWater::HasFlags(unsigned int)
{
    return HasFlags(8);
}

// @fnv 0x004ea8d0
bool BGSPlaceableWater::FUN_004ea8d0()
{
    return HasFlags(8);
}
}  // namespace fnv_004ea8d0

namespace fnv_004ea8f0 {
struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
    bool FUN_004ea8f0();
};

// @fnv 0x004ea8f0
bool BGSPlaceableWater::FUN_004ea8f0()
{
    return HasFlags(0x10);
}
}  // namespace fnv_004ea8f0

namespace fnv_004ea910 {
struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
    bool FUN_004ea910();
};

// @fnv 0x004ea910
bool BGSPlaceableWater::FUN_004ea910()
{
    return HasFlags(0x20);
}
}  // namespace fnv_004ea910

namespace std {
float abs(float);
}
// Returns whether the absolute difference between afA and afB is less than or equal to afEpsilon.
// @fnv 0x0049e390
bool IsApproximatelyEqual(float afA, float afB, float afEpsilon)
{
    return std::abs(afA - afB) <= afEpsilon;
}

namespace fnv_004e32e0 {
struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
};

struct FUN_004e32e0_shell : BGSPlaceableWater
{
    void FUN_004e32e0();
};

// @fnv 0x004e32e0
void FUN_004e32e0_shell::FUN_004e32e0()
{
    HasFlags(0x10000000);
}
}  // namespace fnv_004e32e0

struct Fake52
{
    void FUN_004ed3e0();
    void* FUN_004e52c0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_004ed3e0, then if flags has bit 1 set deallocates this and returns this.
// @fnv 0x004e52c0
void* Fake52::FUN_004e52c0(unsigned int flags)
{
    this->FUN_004ed3e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_004e65d0 {
extern unsigned char DAT_01189624;
extern unsigned char DAT_011ad86e;
struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011c7adc;
struct S_004e65d0
{
    void FUN_004e6370(int, int, int);
    bool FUN_004e65d0();
};
// @fnv 0x004e65d0
bool S_004e65d0::FUN_004e65d0()
{
    DAT_011ad86e = 1;
    if (!DAT_01189624)
    {
        if (g_011c7adc.Bool()->b)
        {
            DAT_01189624 = 1;
            FUN_004e6370(1, 0, 0);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_004e65d0

struct S004e7530
{
    float x;
    float y;
    S004e7530& DivideBy(float);
};
// Divides x and y by f and returns a reference to this object.
// @fnv 0x004e7530
S004e7530& S004e7530::DivideBy(float afDivisor)
{
    x /= afDivisor;
    y /= afDivisor;
    return *this;
}

namespace fnv_004e7660 {
struct GlobalObject_0044f440
{
    float* Float();
};
extern GlobalObject_0044f440 g_011c7ba4;

struct FUN_004e7660_shell
{
    float FUN_004e7660();
};

// @fnv 0x004e7660
float FUN_004e7660_shell::FUN_004e7660()
{
    return *g_011c7ba4.Float();
}
}  // namespace fnv_004e7660

struct Unk7730
{
    void FUN_004e7730(float, int, int, unsigned char, unsigned char);
    void FUN_004e7770(float, float, int, int, unsigned char, unsigned char);
};
// Forwards the arguments to FUN_004e7770, passing the same float value for both float parameters.
// @fnv 0x004e7730
void Unk7730::FUN_004e7730(float afValue, int aiArg1, int aiArg2, unsigned char d, unsigned char e)
{
    FUN_004e7770(afValue, afValue, aiArg1, aiArg2, d, e);
}

struct S148c0
{
    bool FUN_004a0e10(char const*, int);
    virtual void F0() = 0;
    virtual void F1() = 0;
    virtual void F2() = 0;
    virtual void F3() = 0;
    virtual void F4() = 0;
    virtual void F5() = 0;
    virtual void F6() = 0;
    virtual void F7() = 0;
    virtual void F8() = 0;
    virtual void F9() = 0;
    virtual void F10() = 0;
    virtual void F11() = 0;
    virtual void F12() = 0;
    virtual void F13() = 0;
    virtual void F14() = 0;
    virtual void F15() = 0;
    virtual void F16() = 0;
    virtual void F17() = 0;
    virtual void F18() = 0;
    virtual void F19() = 0;
    virtual void F20() = 0;
    virtual void F21() = 0;
    virtual void F22() = 0;
    virtual void F23() = 0;
    virtual void F24() = 0;
    virtual void F25() = 0;
    virtual void F26() = 0;
    virtual void F27() = 0;
    virtual void F28() = 0;
    virtual void F29() = 0;
    virtual void F30() = 0;
    virtual void F31() = 0;
    virtual void F32() = 0;
    virtual void F33() = 0;
    virtual void F34() = 0;
    virtual void F35() = 0;
    virtual void F36() = 0;
    virtual void F37() = 0;
    virtual void F38() = 0;
    virtual void F39() = 0;
    virtual void F40() = 0;
    virtual void F41() = 0;
    virtual void F42() = 0;
    virtual void F43() = 0;
    virtual void F44() = 0;
    virtual void F45() = 0;
    virtual void F46() = 0;
    virtual void F47() = 0;
    virtual void F48() = 0;
    virtual void F49() = 0;
    virtual void F50() = 0;
    virtual void F51() = 0;
    virtual void F52() = 0;
    virtual void F53() = 0;
    virtual void F54() = 0;
    virtual void F55() = 0;
    virtual void F56() = 0;
    virtual void F57() = 0;
    virtual void F58() = 0;
    virtual void F59() = 0;
    virtual void F60() = 0;
    virtual void F61() = 0;
    virtual void F62() = 0;
    virtual void F63() = 0;
    virtual void F64() = 0;
    virtual void F65() = 0;
    virtual void F66() = 0;
    virtual void F67() = 0;
    virtual void F68() = 0;
    virtual void F69() = 0;
    virtual void F70() = 0;
    virtual void F71() = 0;
    virtual void F72() = 0;
    virtual void F73() = 0;
    virtual void F74() = 0;
    virtual void F75() = 0;
    virtual void F76() = 0;
    virtual void F77() = 0;
    virtual void F78() = 0;
    virtual void F79() = 0;
    virtual void F80() = 0;
    virtual void F81() = 0;
    virtual void F82() = 0;
    virtual void F83() = 0;
    virtual void F84() = 0;
    virtual void F85() = 0;
    virtual void F86() = 0;
    virtual void F87() = 0;
    virtual void F88() = 0;
    virtual void F89() = 0;
    virtual void F90() = 0;
    virtual void F91() = 0;
    virtual void F92() = 0;
    virtual void F93() = 0;
    virtual void F94() = 0;
    virtual void F95() = 0;
    virtual void F96() = 0;
    virtual void F97() = 0;
    virtual void F98() = 0;
    virtual void F99(int, int, int, int, int, int) = 0;
    void FUN_004e9c90(int, int, int, int, int, int);
};
// @fnv 0x004e9c90
void S148c0::FUN_004e9c90(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6)
{
    if (!FUN_004a0e10("SetCameraData", 1))
        return;
    F99(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, aiArg6);
}

struct Flt
{
    operator unsigned int(void);
};
struct FUN_004ea980_shell
{
    unsigned int GetFloatAsUInt();
};
// @fnv 0x004ea980
unsigned int FUN_004ea980_shell::GetFloatAsUInt()
{
    return ((Flt*)((char*)this + 0x134))->operator unsigned int();
}

struct ImageSpaceEffectParam
{
    void FUN_004eba90();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_004eba90, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004ebb00
void* ImageSpaceEffectParam::DestroyIfFlagged(unsigned int flags)
{
    FUN_004eba90();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004ebb30_shell
{
    void FUN_004edc60();
    void FUN_004ebb30();
};

// @fnv 0x004ebb30
void FUN_004ebb30_shell::FUN_004ebb30()
{
    FUN_004edc60();
}

struct FUN_004ebb50_shell
{
    void InitAndDeallocate();
    void FUN_004ebb50();
};

// @fnv 0x004ebb50
void FUN_004ebb50_shell::FUN_004ebb50()
{
    InitAndDeallocate();
}

struct GO
{
    int v;
    GO(int);
};
struct FUN_004ebb70
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    GO g;
    int d;
    int e;
    FUN_004ebb70();
};
// Initializes all members of the object to zero.
// @fnv 0x004ebb70
FUN_004ebb70::FUN_004ebb70() : a(0), b(0), c(0), g(0), d(0), e(0)
{}

struct R
{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16;
};
struct S
{
    R FUN_004ed140(int);
};
void __stdcall FUN_00ee6de0(R*, S*, int);
// @fnv 0x004ed140
R S::FUN_004ed140(int a)
{
    R tmp;
    ((NiPlane*)&tmp)->GetPlaneNormal();
    FUN_00ee6de0(&tmp, this, a);
    return tmp;
}

namespace fnv_006db840 {
struct S5460
{
    unsigned int FUN_00845460();
};
struct BSSimpleArray
{
    unsigned int m_uiItemCount;
    NiPoint2* pBuffer;
    void ConstructElements(NiPoint2* p, int i);
    unsigned int InsertAtEnd(const NiPoint2& value);
};
// @fnv 0x006db840
unsigned int BSSimpleArray::InsertAtEnd(const NiPoint2& value)
{
    unsigned int index = ((S5460*)this)->FUN_00845460();
    ConstructElements(pBuffer + index, 1);
    pBuffer[index] = value;
    return index;
}
}  // namespace fnv_006db840

extern int g_TES;

struct FUN_00759d80_shell
{
    bool FUN_00759d80();
};

// @fnv 0x006fd150
char FUN_006fd150()
{
    TESWorldSpace* ws = ((TES*)g_TES)->GetParentWorldSpace();
    if (ws && ws->GetWorldTerrainManager() && ((FUN_00759d80_shell*)ws->GetWorldTerrainManager())->FUN_00759d80())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

extern float DAT_011ad834;
struct FUN_004e6580_shell
{
    char _pad[0xD8];
    float fD8;
    float fDC;
    bool FUN_004e6580();
};
// Returns true when fDC is at least DAT_011ad834 and fD8 is at most 0.1.
// @fnv 0x004e6580
bool FUN_004e6580_shell::FUN_004e6580()
{
    return fDC >= DAT_011ad834 && fD8 <= (double)0.1f;
}

struct FUN_004ea880_Data
{
    int a, b, c, d;
};

struct FUN_004ea880_shell
{
    char pad[0x154];
    FUN_004ea880_Data m_154;
    void FUN_004ea880(const FUN_004ea880_Data* src);
};

// Copies the four-int data block pointed to by src into the m_154 member.
// @fnv 0x004ea880
void FUN_004ea880_shell::FUN_004ea880(const FUN_004ea880_Data* apData)
{
    m_154 = *apData;
}

struct Vin_4ed190
{
    virtual void p00() = 0;
    virtual void p01() = 0;
    virtual void p02() = 0;
    virtual void p03() = 0;
    virtual void p04() = 0;
    virtual void p05() = 0;
    virtual void p06() = 0;
    virtual void p07() = 0;
    virtual void p08() = 0;
    virtual void p09() = 0;
    virtual void p10() = 0;
    virtual void p11() = 0;
    virtual void p12() = 0;
    virtual void p13() = 0;
    virtual void p14() = 0;
    virtual void p15() = 0;
    virtual void p16() = 0;
    virtual void p17() = 0;
    virtual void p18() = 0;
    virtual void p19() = 0;
    virtual void p20() = 0;
    virtual void p21() = 0;
    virtual void p22() = 0;
    virtual void p23() = 0;
    virtual void p24() = 0;
    virtual void p25() = 0;
    virtual void p26() = 0;
    virtual void p27() = 0;
    virtual void p28() = 0;
    virtual void p29() = 0;
    virtual void p30() = 0;
    virtual void p31() = 0;
    virtual void p32() = 0;
    virtual void p33() = 0;
    virtual void p34() = 0;
    virtual void p35() = 0;
    virtual void p36() = 0;
    virtual void p37() = 0;
    virtual void p38() = 0;
    virtual void p39() = 0;
    virtual void p40() = 0;
    virtual void p41() = 0;
    virtual void p42() = 0;
    virtual void p43() = 0;
    virtual void p44() = 0;
    virtual void p45() = 0;
    virtual void p46() = 0;
    virtual void p47() = 0;
    virtual void p48() = 0;
    virtual void p49() = 0;
    virtual void p50() = 0;
    virtual void p51() = 0;
    virtual void p52() = 0;
    virtual void p53() = 0;
    virtual void p54() = 0;
    virtual void __stdcall Foo(char*, int*) = 0;
};
struct Host_4ed190
{
    char _pad[0x288];
    Vin_4ed190* pm;
    void CallFooForEachElement(char*, int, int*);
};
// Calls pm->Foo on each of a2 elements, passing &a1[i] and &a3[i*4].
// @fnv 0x004ed190
void Host_4ed190::CallFooForEachElement(char* pcData, int iCount, int* a3)
{
    for (int i = 0; i < iCount; ++i)
        pm->Foo(&pcData[i], &a3[i * 4]);
}

namespace fnv_004e3520 {
struct Flt
{
    operator unsigned int();
};
struct FUN_006317a0_struct
{
    int AddEight(int);
};
struct FUN_004e3590_shell
{
    void FUN_004e3590(void*, void*);
    void FUN_004e3520(void* apList);
};
// @fnv 0x004e3520
void FUN_004e3590_shell::FUN_004e3520(void* apList)
{
    unsigned int uiCount2 = ((Flt*)((char*)apList + 0x24))->operator unsigned int();
    void* pvItem2 = 0;
    while (uiCount2)
    {
        pvItem2 = ((NiTPointerList<WaterSurface>*)((char*)apList + 0x24))->DereferenceIfNotNull((void*)uiCount2);
        if (uiCount2)
        {
            void* pvNext = *(void**)((FUN_006317a0_struct*)((char*)apList + 0x24))->AddEight(uiCount2);
            FUN_004e3590(apList, pvNext);
        }
        uiCount2 = (unsigned int)pvItem2;
    }
}
}  // namespace fnv_004e3520

struct NiPoint3_ext
{
    float x, y, z;
    float Length() const;
};
extern double DAT_01017cf8;

struct FUN_004e7560_shell
{
    float NormalizeXY();
};

// Computes the vector length; if it exceeds DAT_01017cf8, scales x and y by its inverse, otherwise zeroes x and y and returns 0.
// @fnv 0x004e7560
float FUN_004e7560_shell::NormalizeXY()
{
    float len = ((NiPoint3_ext*)this)->Length();
    if (len > DAT_01017cf8)
    {
        float fInvLength = 1.0f / len;
        ((NiPoint3_ext*)this)->x *= fInvLength;
        ((NiPoint3_ext*)this)->y *= fInvLength;
    }
    else
    {
        ((NiPoint3_ext*)this)->x = 0.0f;
        ((NiPoint3_ext*)this)->y = 0.0f;
        len = 0.0f;
    }
    return len;
}

struct Helper62d0
{
    void* operator=(void const*);
};

struct FUN_004e45a0_shell
{
    char pad[0x1c];
    Helper62d0 member;

    void AssignMemberToSource(Helper62d0* source);
};

// @fnv 0x004e45a0
void FUN_004e45a0_shell::AssignMemberToSource(Helper62d0* source)
{
    source->operator=(&member);
}

namespace fnv_004e5640 {
struct FUN_006317a0_struct : public NiTPointerList<WaterSurface*>
{
    int AddEight(int);
};

struct GO : public FUN_006317a0_struct
{
    operator unsigned int() const;
};

struct FUN_004e5640_shell
{
    char padding[0x3c];
    GO go;

    void SetBitFlagsOnListItems();
};

// Iterates the go list, setting bit (1 << count) at offset 0xac of each item's object, incrementing count per item.
// @fnv 0x004e5640
void FUN_004e5640_shell::SetBitFlagsOnListItems()
{
    void* current;
    unsigned int count;
    void* next;
    void* object;

    count = 1;
    current = reinterpret_cast<void*>(go.operator unsigned int());
    next = 0;

    while (current)
    {
        next = go.DereferenceIfNotNull(current);

        if (current)
        {
            object = *reinterpret_cast<void**>(reinterpret_cast<void*>(go.AddEight(reinterpret_cast<int>(current))));

            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(object) + 0xac) = 1 << count;

            ++count;
        }

        current = next;
    }
}
}  // namespace fnv_004e5640

namespace fnv_004e7680 {
struct A51BF0Base
{
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

struct FUN_00a74480 : A51BF0Base
{
    unsigned char padding[0xc4];

    FUN_00a74480(unsigned int value);
};

typedef FUN_00a74480 BSRenderedTexture;

struct AutoMemHelper
{
    void* p;

    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};

extern const char str_0102301c[];

struct TESWaterSystem_shell
{
    BSRenderedTexture* CreateRenderedTexture(unsigned int value);
};

// @fnv 0x004e7680
BSRenderedTexture* TESWaterSystem_shell::CreateRenderedTexture(unsigned int value)
{
    AutoMemHelper tempMemContext(0x1d, true, str_0102301c, 0xb91);
    return new BSRenderedTexture(value);
}
}  // namespace fnv_004e7680

struct S_004e46b0_Obj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* vfn_1d0();
};
struct S_004e46b0_Cls
{
    void FUN_004e4730(S_004e46b0_Obj*, const NiPoint3*, const ThreeByThreeMatrix*);
    void FUN_004e46b0(S_004e46b0_Obj* a);
};
// @fnv 0x004e46b0
void S_004e46b0_Cls::FUN_004e46b0(S_004e46b0_Obj* pObj)
{
    NiPoint3 pos = pObj->vfn_1d0()->FUN_0045bb80();
    ThreeByThreeMatrix rot = pObj->vfn_1d0()->FUN_00461130();
    FUN_004e4730(pObj, &pos, &rot);
}

struct Ref5140;

struct List5140
{
    void* GetHeadPos() const;
    void* GetNextPos(void* iterPos) const;
    Ref5140*& GetAt(void* iterPos) const;
    Ref5140* RemovePos(void*& iterPos);
    int IsEmpty();
};

struct Owner5140
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
    List5140 kList;
    void* FUN_004e52c0(unsigned int flags);
};

struct Ref5140
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void r88();
    virtual void r89();
    virtual void r90();
    virtual void r91();
    virtual void r92();
    virtual void r93();
    virtual void r94();
    virtual void r95();
    virtual void r96();
    virtual void r97();
    virtual void r98();
    virtual void r99();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void r114();
    virtual void r115();
    virtual void* GetBase();
};

struct Target5140
{
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual void t45();
    virtual void t46();
    virtual void t47();
    virtual void t48();
    virtual void t49();
    virtual void t50();
    virtual void t51();
    virtual void t52();
    virtual void t53();
    virtual void t54();
    virtual void t55();
    virtual void t56();
    virtual void t57();
    virtual void SetBase(void* base);
};

struct NP5140
{
    NP5140& operator=(void* p);
};

struct Prop5140
{
    char unk00[0x13c];
    NP5140 spTex;
};

struct NiAV5140
{
    Prop5140* GetProperty(unsigned int idx);
};

struct Arr5140
{
    bool FUN_0076b610() const;
};

extern int DAT_011c7a4c;

struct Cls5140
{
    int unk00[15];
    Arr5140 kArr;
    int unk40;
    int unk44;
    Owner5140* pOwner;
    NiAV5140* FUN_004e8030(Ref5140* ref);
    void ReleaseWaterResources(int a, int b);
    void DetachRef(Ref5140* apRef, int aiUnused, Target5140* apTarget);
};

// @fnv 0x004e5140
void Cls5140::DetachRef(Ref5140* apRef, int aiUnused, Target5140* apTarget)
{
    apTarget->SetBase(apRef->GetBase());
    if (pOwner)
    {
        void* iterPos = pOwner->kList.GetHeadPos();
        void* next = 0;
        while (iterPos)
        {
            next = pOwner->kList.GetNextPos(iterPos);
            if (iterPos)
            {
                Ref5140* item = pOwner->kList.GetAt(iterPos);
                if (item == apRef)
                {
                    pOwner->kList.RemovePos(iterPos);
                    DAT_011c7a4c--;
                    NiAV5140* node = FUN_004e8030(item);
                    if (node)
                    {
                        Prop5140* prop = node->GetProperty(3);
                        Prop5140* tex = prop;
                        tex->spTex = 0;
                    }
                    if (!pOwner->kList.IsEmpty())
                    {
                        Owner5140* pDel = pOwner;
                        Owner5140* pDel2 = pDel;
                        pDel2 ? pDel2->FUN_004e52c0(1) : 0;
                        pOwner = 0;
                    }
                    if (kArr.FUN_0076b610() && !pOwner)
                    {
                        ReleaseWaterResources(1, 0);
                    }
                }
                iterPos = next;
            }
        }
    }
}

class FUN_004e52f0_arg
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* vfn_1d0();
};

class FUN_004e52f0_cls
{
  public:
    void RemoveWaterRef(FUN_004e52f0_arg* a, const NiPoint3* pos, const ThreeByThreeMatrix* mat);
    void FUN_004e52f0(FUN_004e52f0_arg* arg);
};

// @fnv 0x004e52f0
void FUN_004e52f0_cls::FUN_004e52f0(FUN_004e52f0_arg* arg)
{
    NiPoint3 pos = arg->vfn_1d0()->FUN_0045bb80();
    ThreeByThreeMatrix mat = arg->vfn_1d0()->FUN_00461130();
    RemoveWaterRef(arg, &pos, &mat);
}

struct Settings
{
    void FUN_006e5cc0(const Settings*);
};
struct Property
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
    Settings settings;
};
struct SceneObject
{
    Property* FUN_00a59d30(int);
};
struct Water
{
    bool FUN_004e32c0();
};
struct Form
{
    bool FUN_00450ff0();
};
struct Reference
{
    Water* FUN_007af430();
    Form* FUN_008d6f30();
};
struct Handle
{
    void* value;
    void* FUN_00559450();
    Reference** FUN_0057cbe0(void**);
};
struct Context
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
    Handle list;
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
    Settings settings;
    Handle object;
    bool enabled;
};
struct Player
{
    int FUN_005f36f0();
};
extern Player* DAT_011dea10;
extern int DAT_011fa018;
extern Settings DAT_011c7ad4;
extern Settings DAT_011c7c2c;
bool __cdecl FUN_0045bad0(int*, Property*);
struct Worker
{
    SceneObject* FUN_004e8030(Reference*);
    void UpdateWaterSettings(Context*);
};
// Iterates the context's reference list and applies water settings to matching properties, then applies settings to the context's own object.
// @fnv 0x004e56c0
void Worker::UpdateWaterSettings(Context* context)
{
    void* position = context->list.FUN_00559450();
    while (position)
    {
        Reference* reference = *context->list.FUN_0057cbe0(&position);
        Water* water = reference->FUN_007af430();
        if (reference && ((reference->FUN_008d6f30() && reference->FUN_008d6f30()->FUN_00450ff0()) ||
                          (water && water->FUN_004e32c0() && !DAT_011dea10->FUN_005f36f0())))
        {
            SceneObject* object = FUN_004e8030(reference);
            if (object)
            {
                Property* property = object->FUN_00a59d30(3);
                Property* base = 0;
                if (FUN_0045bad0(&DAT_011fa018, property))
                    base = property;
                if (base)
                {
                    if (DAT_011dea10->FUN_005f36f0())
                        base->settings.FUN_006e5cc0(&context->settings);
                    else if (context->enabled)
                        base->settings.FUN_006e5cc0(&DAT_011c7ad4);
                    else
                        base->settings.FUN_006e5cc0(&DAT_011c7c2c);
                }
            }
        }
    }
    if (context->object.FUN_00559450())
    {
        Property* pObjectProperty = static_cast<SceneObject*>(context->object.FUN_00559450())->FUN_00a59d30(3);
        Property* base2 = pObjectProperty;
        if (DAT_011dea10->FUN_005f36f0())
            base2->settings.FUN_006e5cc0(&context->settings);
        else if (context->enabled)
            base2->settings.FUN_006e5cc0(&DAT_011c7ad4);
        else
            base2->settings.FUN_006e5cc0(&DAT_011c7c2c);
    }
}

struct FUN_004e62e0_cls
{
    bool FUN_004e62e0(TESObjectREFR* aRef, void* aParam);
};

struct SceneNodeOps
{
    void* GetChild(int aIndex);
};

struct SceneValue
{
    void* Resolve();
};

struct SceneValue2
{
    void* Resolve();
};

struct SceneValue3
{
    int Count();
};

extern char DAT_01202e74;
bool __cdecl CheckFlagPair(void* aFlags, void* aValue);
bool __cdecl ProcessNode(void* aNode, void* aParam);

// Gets the reference's NiNode; if its first child matches DAT_01202e74, returns whether the resolved value's count is 1, otherwise calls ProcessNode.
// @fnv 0x004e62e0
bool FUN_004e62e0_cls::FUN_004e62e0(TESObjectREFR* aRef, void* aParam)
{
    NiNode* node = aRef->GetNiNode_v();
    if (node != 0)
    {
        if (CheckFlagPair(&DAT_01202e74, reinterpret_cast<SceneNodeOps*>(node)->GetChild(0)))
        {
            void* w = reinterpret_cast<SceneNodeOps*>(node)->GetChild(0);
            return reinterpret_cast<SceneValue3*>(
                       reinterpret_cast<SceneValue2*>(reinterpret_cast<SceneValue*>(w)->Resolve())->Resolve())
                       ->Count() == 1;
        }
        else
        {
            return ProcessNode(node, aParam);
        }
    }
    return false;
}

struct WaterAVObject : NiNode
{
    bool GetAppCulled();
    void SetAppCulled(bool abCulled);
};

struct PlaceableWaterBase
{
    bool IsEnabled();
};

struct WaterRefr : TESObjectREFR
{
    PlaceableWaterBase* GetPlaceableWaterBase();
};

struct WaterSystem6370 : WaterZoneManager
{
    void FUN_004e6370(bool abShow, bool abCheckBase, bool abToggle);
};

// Iterates water groups and their refs, toggling or setting each water node's app-culled flag based on abShow, abToggle and abCheckBase.
// @fnv 0x004e6370
void WaterSystem6370::FUN_004e6370(bool abShow, bool abCheckBase, bool abToggle)
{
    void* pos2 = m_kWaterZoneList.GetHeadPos();
    void* next_ = 0;
    while (pos2)
    {
        next_ = m_kWaterZoneList.DereferenceIfNotNull(pos2);
        if (pos2)
        {
            WaterSurface* pGroup3 = m_kWaterZoneList.AddEight(pos2);
            void* waterPosB = pGroup3->m_kWaterReferences.GetHeadPos();
            void* waterNext9 = 0;
            while (waterPosB)
            {
                waterNext9 = pGroup3->m_kWaterReferences.DereferenceIfNotNull(waterPosB);
                if (waterPosB)
                {
                    if (abCheckBase)
                    {
                        WaterRefr* pRef = static_cast<WaterRefr*>(pGroup3->m_kWaterReferences.AddEight(waterPosB));
                        PlaceableWaterBase* pBase = pRef->GetPlaceableWaterBase();
                        if (pBase->IsEnabled())
                        {
                            if (abToggle)
                            {
                                static_cast<WaterAVObject*>(pRef->GetNiNode_v())
                                    ->SetAppCulled(!static_cast<WaterAVObject*>(pRef->GetNiNode_v())->GetAppCulled());
                            }
                            else
                            {
                                static_cast<WaterAVObject*>(pRef->GetNiNode_v())->SetAppCulled(!abShow);
                            }
                        }
                    }
                    else
                    {
                        TESObjectREFR* pRef = pGroup3->m_kWaterReferences.AddEight(waterPosB);
                        if (abToggle)
                        {
                            static_cast<WaterAVObject*>(pRef->GetNiNode_v())
                                ->SetAppCulled(!static_cast<WaterAVObject*>(pRef->GetNiNode_v())->GetAppCulled());
                        }
                        else
                        {
                            static_cast<WaterAVObject*>(pRef->GetNiNode_v())->SetAppCulled(!abShow);
                        }
                    }
                }
                waterPosB = waterNext9;
            }
        }
        pos2 = next_;
    }
}

struct Vec_004e83e0
{
    float x, y, z;
    Vec_004e83e0 FUN_00439ef0(const Vec_004e83e0&) const;
    float FUN_00457990() const;
};
struct WaterActor_004e83e0 : PlayerCharacter
{
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool IsExcludedFromWaterCheck(int);
};
struct RangeSetting_004e83e0
{
    float* FUN_00403e20();
};
extern RangeSetting_004e83e0 DAT_011c7b54;
struct WaterList_004e83e0
{
    void* FUN_00559450() const;
    void* DereferenceIfNotNull(void*) const;
    WaterActor_004e83e0*& AddEight(void*) const;
};
struct WaterScanner_004e83e0
{
    bool IsPlayerNearWaterActor(void* collection);
};
// Scans the collection's water list and returns true if the player is an entry or within the configured distance of a non-excluded actor.
// @fnv 0x004e83e0
bool WaterScanner_004e83e0::IsPlayerNearWaterActor(void* collection)
{
    void* position;
    void* nextPosition =
        reinterpret_cast<WaterList_004e83e0*>(reinterpret_cast<char*>(collection) + 0x3c)->FUN_00559450();
    position = 0;
    while (nextPosition)
    {
        position = reinterpret_cast<WaterList_004e83e0*>(reinterpret_cast<char*>(collection) + 0x3c)
                       ->DereferenceIfNotNull(nextPosition);
        if (nextPosition)
        {
            WaterActor_004e83e0* object =
                reinterpret_cast<WaterList_004e83e0*>(reinterpret_cast<char*>(collection) + 0x3c)
                    ->AddEight(nextPosition);
            if (g_thePlayer == object)
                return true;
            else if (!object->IsExcludedFromWaterCheck(0))
            {
                Vec_004e83e0 vPlayerPos = *reinterpret_cast<const Vec_004e83e0*>(&g_thePlayer->GetPos());
                Vec_004e83e0 distance = *reinterpret_cast<const Vec_004e83e0*>(&object->GetPos());
                vPlayerPos.z = 0.0f;
                distance.z = 0.0f;
                float playerPos = vPlayerPos.FUN_00439ef0(distance).FUN_00457990();
                if (playerPos <= *DAT_011c7b54.FUN_00403e20())
                    return true;
            }
        }
        nextPosition = position;
    }
    return false;
}

namespace fnv_004e8a00 {
struct Pt3
{
    float x, y, z;
};
struct Pt2
{
    float x, y;
    Pt2();
};

struct WRef
{
    virtual void v0();
    TESObjectREFR* dummy();
    char pad[0x4];
    const Pt3& GetPos_v();
    float FUN_008d6f30(float);
    bool FUN_00885520(const Pt3&, float);
    bool FUN_004938e0();
};

struct WPlayerV
{
    virtual void vfn_0();
};

struct RefPos
{
    virtual void f000();
    virtual void f004();
    virtual void f008();
    virtual void f00c();
};

struct WList
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void* FUN_00559450() const;
    void* DereferenceIfNotNull(void*) const;
    void*& AddEight(void*) const;
    bool FUN_0076b610() const;
    void FUN_0066b0d0(void*);
};

struct WList4
{
    void* m_pkHead;
    void* FUN_00559450() const;
    void FUN_0066b0d0(void*);
};

struct WGroup
{
    void* m_pOwningWater;
    NiPlane plane;
    char pad14[0x3c - 0x14];
    WList refs;
    char pad48[0x58 - 0x48];
    WList4 list58;
    char pad5c;
    bool bActive;
};

struct WData
{
    float f0, f4, f8, fc;
    Pt3 m5;
    WData();
};

struct WMap
{
    bool GetAt(void*, WData*&);
    void FUN_00844700(void*, WData*);
    void RemoveKey(void*);
};

struct WSetting
{
    float* FUN_00403e20();
};
struct WGame
{
    void* FUN_005f36f0();
};
struct WCell
{
    bool FUN_004518e0();
};

extern WGame* DAT_011dea10;
extern WSetting DAT_011c7b54;
extern float DAT_010231a0, DAT_0102319c, DAT_01016248, DAT_0102295c;
float LinearInterpolate(float, float, float, float, float);
int __stdcall FUN_004e7ff0(float);

struct PosObj;
struct VRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
};

struct WObj;
extern WObj* DAT_011dea3c;
struct WObj
{
    void* vt;
};

struct WVirt
{
    virtual void p00();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p0a();
    virtual void p0b();
    virtual void p0c();
    virtual void p0d();
    virtual void p0e();
    virtual void p0f();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p1a();
    virtual void p1b();
    virtual void p1c();
    virtual void p1d();
    virtual void p1e();
    virtual void p1f();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p2a();
    virtual void p2b();
    virtual void p2c();
    virtual void p2d();
    virtual void p2e();
    virtual void p2f();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p3a();
    virtual void p3b();
    virtual void p3c();
    virtual void p3d();
    virtual void p3e();
    virtual void p3f();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p4a();
    virtual void p4b();
    virtual void p4c();
    virtual void p4d();
    virtual void p4e();
    virtual void p4f();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p5a();
    virtual void p5b();
    virtual void p5c();
    virtual void p5d();
    virtual void p5e();
    virtual void p5f();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p6a();
    virtual void p6b();
    virtual void p6c();
    virtual void p6d();
    virtual void p6e();
    virtual void p6f();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p7a();
    virtual void p7b();
    virtual void p7c();
    virtual const Pt3& GetPos();
    void* FUN_008d6f30(float);
    bool FUN_00885520(const Pt3&, void*);
    bool FUN_004938e0();
};

extern WVirt* g_thePlayerW;

struct WSys
{
    char pad[0x3c];
    WList groups;
    char pad48[0x7c - 0x48];
    WMap map;
    bool IsPlayerNearWaterActor(WGroup*);
    void* CreateWaterShaderNode(WGroup*, int);
    void FUN_004e8a00();
};

// @fnv 0x004e8a00
void WSys::FUN_004e8a00()
{
    WCell* ct = (WCell*)DAT_011dea10->FUN_005f36f0();
    if (ct && !ct->FUN_004518e0())
        return;
    bool f1 = false;
    void* m5 = groups.FUN_00559450();
    void* nd = 0;
    while (m5)
    {
        nd = groups.DereferenceIfNotNull(m5);
        if (m5)
        {
            WGroup* group = (WGroup*)groups.AddEight(m5);
            if (group->bActive && !group->refs.FUN_0076b610() && IsPlayerNearWaterActor(group))
            {
                void* pos2 = group->refs.FUN_00559450();
                void* ne = 0;
                while (pos2)
                {
                    ne = group->refs.DereferenceIfNotNull(pos2);
                    if (pos2)
                    {
                        f1 = true;
                        WVirt* ref = (WVirt*)group->refs.AddEight(pos2);
                        bool inside = ref->FUN_00885520(ref->GetPos(), ref->FUN_008d6f30(1.0f));
                        if (!inside && ref->FUN_004938e0())
                        {
                            if (!group->list58.FUN_00559450())
                                group->list58.FUN_0066b0d0(
                                    CreateWaterShaderNode(group, FUN_004e7ff0(*DAT_011c7b54.FUN_00403e20())));
                            Pt3 ny = ((WVirt*)DAT_011dea3c)->GetPos();
                            Pt3 refPos = ref->GetPos();
                            refPos.z = group->plane.FUN_0084d030();
                            WData* ea = 0;
                            if (!map.GetAt(ref, ea))
                            {
                                ea = new WData;
                                ea->m5 = refPos;
                                map.FUN_00844700(ref, ea);
                            }
                            Pt2 da;
                            Pt2 m7;
                            da.x = refPos.x - ny.x;
                            da.y = refPos.y - ny.y;
                            m7.x = ea->m5.x - ny.x;
                            m7.y = ea->m5.y - ny.y;
                            ea->m5 = refPos;
                            ea->f0 = LinearInterpolate(DAT_0102295c, DAT_01016248, DAT_0102319c, DAT_010231a0, da.x);
                            ea->f4 = LinearInterpolate(DAT_0102295c, DAT_01016248, DAT_0102319c, DAT_010231a0, da.y);
                            ea->f8 = LinearInterpolate(DAT_0102295c, DAT_01016248, DAT_0102319c, DAT_010231a0, m7.x);
                            ea->fc = LinearInterpolate(DAT_0102295c, DAT_01016248, DAT_0102319c, DAT_010231a0, m7.y);
                        }
                        else
                        {
                            WData* old = 0;
                            if (map.GetAt(ref, old))
                                map.RemoveKey(ref);
                        }
                    }
                    pos2 = ne;
                }
            }
        }
        m5 = nd;
    }
}
}  // namespace fnv_004e8a00

struct Vec2
{
    unsigned int x;
    unsigned int y;
    void FUN_006815c0();
};
struct Vec3
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    void FUN_006815c0();
};
extern Vec3 DAT_011f426c;

struct FUN_004e8e40_owner
{
    Vec2 first;
    Vec2 second;
    Vec3 third;
    FUN_004e8e40_owner* FUN_004e8e40();
};
// Calls FUN_006815c0 on first, second and third, then assigns DAT_011f4980 to first and second and DAT_011f426c to third, returning this.
// @fnv 0x004e8e40
FUN_004e8e40_owner* FUN_004e8e40_owner::FUN_004e8e40()
{
    first.FUN_006815c0();
    second.FUN_006815c0();
    third.FUN_006815c0();
    first = *reinterpret_cast<const Vec2*>(&DAT_011f4980);
    second = *reinterpret_cast<const Vec2*>(&DAT_011f4980);
    third = DAT_011f426c;
    return this;
}

extern void* DAT_010231cc;

struct FUN_004eba20_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    FUN_004eba20_Sub(int aFlag, int aCount);
    ~FUN_004eba20_Sub();
};

struct FUN_004eba20_Tail
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    FUN_004eba20_Tail(int aFlag, int aCount);
};

struct FUN_004eba20_Base
{
    void* m_vptr;

    // Sets the object's vtable pointer to DAT_010231cc.
// @fnv 0x004eba20
    FUN_004eba20_Base()
    {
        m_vptr = &DAT_010231cc;
    }
};

struct FUN_004eba20_cls : FUN_004eba20_Base
{
    FUN_004eba20_Sub m_sub04;
    FUN_004eba20_Tail m_sub14;

    FUN_004eba20_cls();
};

FUN_004eba20_cls::FUN_004eba20_cls() : m_sub04(0, 1), m_sub14(0, 1)
{}

struct FUN_004ebb30_m
{
    int pad[4];
    ~FUN_004ebb30_m();
};
struct FUN_004ebb50_m
{
    int pad[4];
    ~FUN_004ebb50_m();
};
struct FUN_004eba90
{
    // Empty constructor that takes an int argument and does nothing.
// @fnv 0x004eba90
    FUN_004eba90(int)
    {}
    virtual ~FUN_004eba90();
    FUN_004ebb30_m m4;
    FUN_004ebb50_m m14;
};
FUN_004eba90::~FUN_004eba90()
{}

enum MEM_CONTEXT
{
    MC_Water = 0x1d
};
struct AutoMemContext
{
    int iPrevious;
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
};

struct WaterColorParam
{
    float r;
    float g;
    float b;
    float a;
    WaterColorParam(float fR, float fG, float fB, float fA);
};

struct NiRenderTargetGroup;
struct WaterRenderedTexture
{
    NiRenderTargetGroup* GetGroup();
};

struct WaterRenderer
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
    virtual void SetBackgroundColor(const WaterColorParam& kColor);
    virtual void v44();
    virtual void GetBackgroundColor(WaterColorParam& kColor);
};

struct WaterTextureManager
{
    WaterRenderedTexture* CreateTexture(WaterRenderer* pRenderer, int iType, int a, int b, int c);
};

WaterRenderer* GetWaterRenderer();
WaterTextureManager* __stdcall GetWaterTextureManager();
void SetRenderTargetGroup(unsigned int uiTarget, NiRenderTargetGroup* pGroup);
void ClearRenderTarget();

struct TESWaterStub
{
    WaterRenderedTexture* FUN_004ed290();
};

// @fnv 0x004ed290
WaterRenderedTexture* TESWaterStub::FUN_004ed290()
{
    AutoMemContext kMemContext(MC_Water, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                               0x138a);
    WaterColorParam kOldColor2(0.0f, 0.0f, 0.0f, 0.0f);
    WaterRenderedTexture* pTexture7 = GetWaterTextureManager()->CreateTexture(GetWaterRenderer(), 8, 0, 0, 0);
    GetWaterRenderer()->GetBackgroundColor(kOldColor2);
    GetWaterRenderer()->SetBackgroundColor(WaterColorParam(0.5f, 0.5f, 0.5f, 0.5f));
    SetRenderTargetGroup(7, pTexture7->GetGroup());
    ClearRenderTarget();
    GetWaterRenderer()->SetBackgroundColor(kOldColor2);
    return pTexture7;
}

struct FUN_00a69940
{
    unsigned int word0, word1, word2, word3;
    FUN_00a69940();
};
struct FUN_0048f200
{
    float x, y, z;
    FUN_0048f200();
    ~FUN_0048f200();
};
struct FUN_00633c90
{
    void* object;
    FUN_00633c90(int);
    ~FUN_00633c90();
    void FUN_0066b0d0(int);
};
struct FUN_004ed5f0
{
    unsigned int state;
    FUN_00a69940 first;
    FUN_00a69940 second;
    FUN_0048f200 translation0;
    FUN_0048f200 translation1;
    FUN_0048f200 translation2;
    FUN_0048f200 translation3;
    FUN_00633c90 pointer0;
    FUN_00633c90 pointer1;
    bool enabled;
    bool flag5d;
    bool flag5e;
    bool visible;
    bool selected;
    FUN_0048f200 rotation0;
    FUN_0048f200 rotation1;
    FUN_0048f200 rotation2;
    FUN_0048f200 rotation3;
    FUN_00633c90 pointer2;
    FUN_00633c90 pointer3;
    void* resource;
    void* listener;
    FUN_00633c90 pointer4;
    FUN_00633c90 pointer5;
    FUN_004ed5f0();
};
// @fnv 0x004ed5f0
FUN_004ed5f0::FUN_004ed5f0() : pointer0(0), pointer1(0), pointer2(0), pointer3(0), pointer4(0), pointer5(0)
{
    pointer2.FUN_0066b0d0(0);
    pointer3.FUN_0066b0d0(0);
    pointer1.FUN_0066b0d0(0);
    selected = false;
    visible = false;
    enabled = false;
}

struct WaterPoint
{
    float x, y, z;
    void FUN_004a0c10();
};
struct WaterColor
{
    float x, y, z, w;
    WaterColor(float, float, float, float);
};
struct WaterCell
{
    float FUN_005471e0();
};
struct WaterPlayer
{
    WaterCell* FUN_008d6f30();
};
struct WaterCamera
{
    WaterPoint& FUN_0045bb80();
};
struct WaterContext
{
    int old;
    WaterContext(int, bool, const char*, int);
    ~WaterContext();
};
struct WaterTime
{
    void FUN_00483710();
};
struct WaterShader
{
    void FUN_004e2120(bool);
    void SetValue(int);
    void SetByteAtOffset166(bool);
};
struct WaterMain
{
    WaterShader* FUN_004e2190();
};
struct WaterVectorSource
{
    WaterPoint& FUN_0043c490();
};
struct WaterData
{
    WaterVectorSource* FUN_009611e0();
};
struct WaterLight
{
    WaterData* FUN_005585e0();
    float GetLinkedValueFloat();
};
struct WaterSky
{
    WaterLight* FUN_0045cd60();
    WaterPoint& FUN_0043b5d0();
};
WaterSky* WaterGetSky();
struct WaterWorld
{
    void* FUN_005f36f0();
};
struct WaterState
{
    bool FUN_0076b610();
};
extern WaterPlayer* waterPlayer;
extern WaterMain* waterMain;
extern WaterWorld* waterWorld;
extern WaterTime waterTime;
extern bool waterSkip, waterEnabled, waterOverride, waterUnder, waterRenderUnder, waterShaderUnder, waterWorldUnder,
    waterHasWorld, waterNewFrame, waterForceA, waterForceB;
extern float waterCameraZ, waterLightX, waterLightY, waterLightZ, waterIntensity, waterOffsetX, waterOffsetY,
    waterOffsetZ, waterBlend;
extern WaterCamera* waterCamera;
void WaterSetUpdate(int);
void WaterSetColor(int, WaterColor);
void WaterSetFlag(int);
double WaterMin(float, double);
double WaterMax(float, double);
bool WaterDisableBlend();
bool WaterRenderEnabled();
int WaterRenderMode(int);
struct WaterUpdate
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
    WaterState state;
    void UpdateWaterGroup(WaterCamera*, bool);
    void UpdateWaterGroups(WaterCamera*, bool);
    bool FUN_004e8950();
    void FUN_004e8a00();
    void UpdateWaterObjects();
    void UpdateWaterSound();
    void FUN_004e1bc0(WaterCamera*, void*);
};
// @fnv 0x004e1bc0
void WaterUpdate::FUN_004e1bc0(WaterCamera* camera, void* unused)
{
    WaterContext context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp", 279);
    unk00 = 0;
    unk04 = 0;
    if (!waterPlayer->FUN_008d6f30())
        return;
    if (waterSkip)
    {
        waterSkip = false;
        return;
    }
    WaterSetUpdate(0);
    waterTime.FUN_00483710();
    WaterPoint position4 = camera->FUN_0045bb80();
    WaterSetColor(30, WaterColor(position4.x, position4.y, position4.z, 0.0f));
    waterCamera = camera;
    if (!waterEnabled)
    {
        waterTime.FUN_00483710();
        return;
    }
    WaterSetFlag(0);
    if (waterPlayer && waterPlayer->FUN_008d6f30())
    {
        if (waterOverride || camera->FUN_0045bb80().z < waterPlayer->FUN_008d6f30()->FUN_005471e0())
        {
            waterUnder = true;
            waterMain->FUN_004e2190()->FUN_004e2120(true);
            waterRenderUnder = true;
            waterCameraZ = camera->FUN_0045bb80().z;
        }
        else
        {
            waterUnder = false;
            waterMain->FUN_004e2190()->FUN_004e2120(false);
            waterRenderUnder = false;
        }
        waterShaderUnder = waterUnder;
        waterMain->FUN_004e2190()->SetValue((int)waterPlayer->FUN_008d6f30()->FUN_005471e0());
        waterMain->FUN_004e2190()->SetByteAtOffset166(true);
    }
    else
        waterMain->FUN_004e2190()->SetByteAtOffset166(false);
    waterShaderUnder = waterUnder;
    WaterPoint lightDir = WaterGetSky()->FUN_0045cd60()->FUN_005585e0()->FUN_009611e0()->FUN_0043c490();
    lightDir.FUN_004a0c10();
    waterLightX = lightDir.x;
    waterLightY = lightDir.y;
    waterLightZ = lightDir.z;
    waterIntensity =
        (float)WaterMin(1.0f, WaterMax(0.0f, WaterGetSky()->FUN_0045cd60()->GetLinkedValueFloat() * 100.0));
    WaterPoint skyOffset = WaterGetSky()->FUN_0043b5d0();
    waterOffsetX = skyOffset.x;
    waterOffsetY = skyOffset.y;
    waterOffsetZ = skyOffset.z;
    if (waterIntensity == 0.0)
        waterBlend = 0.0f;
    else
        waterBlend = waterIntensity;
    if (WaterDisableBlend())
        waterBlend = 0.0f;
    if (waterWorld->FUN_005f36f0())
        waterHasWorld = true;
    else
        waterHasWorld = false;
    UpdateWaterGroup(camera, waterNewFrame);
    if (!state.FUN_0076b610() || waterForceA || waterForceB)
    {
        UpdateWaterGroups(camera, waterNewFrame);
        waterNewFrame = false;
        if (WaterRenderEnabled() && WaterRenderMode(0) >= 2 && !state.FUN_0076b610())
        {
            if (FUN_004e8950())
                FUN_004e8a00();
            UpdateWaterObjects();
        }
        UpdateWaterSound();
    }
    waterForceB = false;
    waterForceA = false;
    WaterSetFlag(1);
    waterTime.FUN_00483710();
}

namespace fnv_004e21b0 {
struct WPtr
{
    void* m_p;
    void* Get();
    void Set(void* p);
};
struct WListPos;
struct WPosList
{
    void* m_pFirstNode;
    void* m_pTail;
    unsigned int m_uiItemCount;
    WListPos* GetHead();
    WListPos* GetNext(WListPos* pos);
    void*& GetAt(WListPos* pos);
};
struct WSetting
{
    int unk0;
    bool* Get();
};
struct WClearable
{
    int unk0;
    void Clear();
};
struct WClearable2
{
    int unk0;
    void Reset();
};
struct WCountList
{
    int unk0;
    int Count();
};
struct WCheck
{
    int unk0;
    bool Test();
};
struct WFlag2;
struct WHolder
{
    WFlag2* GetGeom();
};
struct WFade
{
    WHolder* GetHolder();
};
WFlag2* GetGlobalFlag();
struct WFlagObj
{
    bool IsSet();
};
struct WFlag2
{
    bool Check();
};
struct WCell
{
    bool GetFlagObj();
};
struct WBase
{
    bool IsA();
    bool IsB();
    bool IsC();
    bool IsD();
    bool IsE();
    bool IsF();
};
struct WNode;
struct WShaderProp
{
    char pad[0x63];
    bool b63;
    char pad2[0x80 - 0x64];
    bool b80;
    bool b81;
    char pad3[0x138 - 0x82];
    WPtr p138;
    WPtr p13c;
    WPtr p140;
    WPtr p144;
};
struct WTex
{
    int Type();
};
struct WNode
{
    bool IsHidden();
    WTex* GetTex();
    WShaderProp* GetProperty(int i);
};
struct WWorld
{
    bool IsB();
};
struct WRef
{
    virtual void w0();
    virtual void w4();
    virtual void w8();
    virtual void wc();
    virtual void w10();
    virtual void w14();
    virtual void w18();
    virtual void w1c();
    virtual void w20();
    virtual void w24();
    virtual void w28();
    virtual void w2c();
    virtual void w30();
    virtual void w34();
    virtual void w38();
    virtual void w3c();
    virtual void w40();
    virtual void w44();
    virtual void w48();
    virtual void w4c();
    virtual void w50();
    virtual void w54();
    virtual void w58();
    virtual void w5c();
    virtual void w60();
    virtual void w64();
    virtual void w68();
    virtual void w6c();
    virtual void w70();
    virtual void w74();
    virtual void w78();
    virtual void w7c();
    virtual void w80();
    virtual void w84();
    virtual void w88();
    virtual void w8c();
    virtual void w90();
    virtual void w94();
    virtual void w98();
    virtual void w9c();
    virtual void wa0();
    virtual void wa4();
    virtual void wa8();
    virtual void wac();
    virtual void wb0();
    virtual void wb4();
    virtual void wb8();
    virtual void wbc();
    virtual void wc0();
    virtual void wc4();
    virtual void wc8();
    virtual void wcc();
    virtual void wd0();
    virtual void wd4();
    virtual void wd8();
    virtual void wdc();
    virtual void we0();
    virtual void we4();
    virtual void we8();
    virtual void wec();
    virtual void wf0();
    virtual void wf4();
    virtual void wf8();
    virtual void wfc();
    virtual void w100();
    virtual void w104();
    virtual void w108();
    virtual void w10c();
    virtual void w110();
    virtual void w114();
    virtual void w118();
    virtual void w11c();
    virtual void w120();
    virtual void w124();
    virtual void w128();
    virtual void w12c();
    virtual void w130();
    virtual void w134();
    virtual void w138();
    virtual void w13c();
    virtual void w140();
    virtual void w144();
    virtual void w148();
    virtual void w14c();
    virtual void w150();
    virtual void w154();
    virtual void w158();
    virtual void w15c();
    virtual void w160();
    virtual void w164();
    virtual void w168();
    virtual void w16c();
    virtual void w170();
    virtual void w174();
    virtual void w178();
    virtual void w17c();
    virtual void w180();
    virtual void w184();
    virtual void w188();
    virtual void w18c();
    virtual void w190();
    virtual void w194();
    virtual void w198();
    virtual void w19c();
    virtual void w1a0();
    virtual void w1a4();
    virtual void w1a8();
    virtual void w1ac();
    virtual void w1b0();
    virtual void w1b4();
    virtual void w1b8();
    virtual void w1bc();
    virtual void w1c0();
    virtual void w1c4();
    virtual void w1c8();
    virtual void w1cc();
    virtual WNode* Get3D();

    WBase* GetBase();
    WCell* GetContainingCell();
    WHolder* GetHolder();
};
struct WWater
{
    virtual void w0();
    virtual void w4();
    virtual void w8();
    virtual void wc();
    virtual void w10();
    virtual void w14();
    virtual void w18();
    virtual void w1c();
    virtual void w20();
    virtual void w24();
    virtual void w28();
    virtual void w2c();
    virtual void w30();
    virtual void w34();
    virtual void w38();
    virtual void w3c();
    virtual void w40();
    virtual void w44();
    virtual void w48();
    virtual void w4c();
    virtual void w50();
    virtual void w54();
    virtual void w58();
    virtual void w5c();
    virtual void w60();
    virtual void w64();
    virtual void w68();
    virtual void w6c();
    virtual void w70();
    virtual void w74();
    virtual void w78();
    virtual void w7c();
    virtual void w80();
    virtual void w84();
    virtual void w88();
    virtual void w8c();
    virtual void w90();
    virtual void w94();
    virtual void w98();
    virtual void w9c();
    virtual void wa0();
    virtual void wa4();
    virtual void wa8();
    virtual void wac();
    virtual void wb0();
    virtual void wb4();
    virtual void wb8();
    virtual void wbc();
    virtual void wc0();
    virtual void wc4();
    virtual void wc8();
    virtual void wcc();
    virtual void wd0();
    virtual void wd4();
    virtual void wd8();
    virtual void wdc();
    virtual void we0();
    virtual void we4();
    virtual void we8();
    virtual void wec();
    virtual void wf0();
    virtual void wf4();
    virtual void wf8();
    virtual void wfc();
    virtual void w100();
    virtual void w104();
    virtual void w108();
    virtual void w10c();
    virtual void w110();
    virtual void w114();
    virtual void w118();
    virtual void w11c();
    virtual void w120();
    virtual void w124();
    virtual void w128();
    virtual void w12c();
    virtual const char* GetEditorID();

    char pad[0x30 - 4];
    WPtr p30;
};
struct WPlane
{
    float x, y, z, d;
    float Height() const;
};
struct WAccum
{
    int unk0;
    void Accum();
};
struct WGroup
{
    WWater* water;
    WPlane plane1;
    WPlane plane2;
    WPosList refs;
    WCheck c30;
    int unk34;
    int unk38;
    WCheck c3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    WPtr p58;
    bool b5c;
    bool b5d;
    bool b5e;
    bool b5f;
    bool b60;
    char pad61[0x7c - 0x61];
    WAccum a7c;
    char pad80[0x88 - 0x80];
    WAccum a88;
    char pad8c[0x9c - 0x8c];
    int i9c;
    int ia0;
    int ia4;
    WPtr pa8;
    unsigned short usac;
};
struct WRect
{
    float l, r, t, b;
    WRect(float a, float b2, float c, float d);
};
struct WRenderer
{
    virtual void w0();
    virtual void w4();
    virtual void w8();
    virtual void wc();
    virtual void w10();
    virtual void w14();
    virtual void w18();
    virtual void w1c();
    virtual void w20();
    virtual void w24();
    virtual void w28();
    virtual void w2c();
    virtual void w30();
    virtual void w34();
    virtual void w38();
    virtual void w3c();
    virtual void w40();
    virtual void w44();
    virtual void w48();
    virtual void w4c();
    virtual void w50();
    virtual void w54();
    virtual void w58();
    virtual void w5c();
    virtual void w60();
    virtual void w64();
    virtual void w68();
    virtual void w6c();
    virtual void w70();
    virtual void w74();
    virtual void w78();
    virtual void w7c();
    virtual void w80();
    virtual void w84();
    virtual void w88();
    virtual void w8c();
    virtual void w90();
    virtual void w94();
    virtual void w98();
    virtual void w9c();
    virtual void wa0();
    virtual void wa4();
    virtual void wa8();
    virtual void SetViewport(WRect* r);
    virtual void wb0();
    virtual void GetViewport(WRect* r);
};
struct WSys
{
    int IsMenuMode();
};
struct WCam
{
    void Update();
};
struct WTexObj
{
    int Index();
};
struct WSPtrHolder
{
    void Apply();
};
struct WOffscreen
{
    char data[0x84];
    WOffscreen();
    ~WOffscreen();
    void SetFlags(int a, int b);
    void SetClear(int a, float r, float g, float b2, float al);
};
struct WDrawer
{
    void Draw(WRenderer* r, void* tex, WOffscreen* o, int z);
};
struct WObj2
{
    void Release();
};

extern int DAT_011c7a68;
extern bool DAT_011c7a66;
extern bool DAT_011c7a67;
extern int DAT_011c7a6c;
extern int DAT_011c7a70;
extern int DAT_011c7a74;
extern WSys* DAT_011dea10;
extern WSetting DAT_011c7a90;
extern WSetting DAT_011c7aa8;
extern WSetting DAT_011c7b6c;
extern WSetting DAT_011c7c60;
extern WSetting DAT_011c7bbc;
extern WSetting DAT_011c7c00;
extern WPtr DAT_011c7b68;
extern WPtr DAT_011c7b64;
extern WRect DAT_011a9bd0;

bool IsDisabled();
WCam* GetCamera();
WRenderer* GetRenderer();
WObj2* __stdcall GetRenderedTex(void* p);
WDrawer* __stdcall GetDrawer(int i);
int sprintf_s_(char* buf, int n, const char* fmt, ...);
void ConsolePrint(const char* fmt, ...);
void SetRenderTarget(int a, int b);
void BeginScene();
void SetStencil(int a, int b, int c, int d);
void EndScene();
void RenderGroupPass(int count, WRect rect);
struct WTarget
{
    int GetIdx();
};

struct WPos3
{
    float x, y, z;
};
struct WActor
{
    WPos3* GetPos();
};

struct FUN_004e21b0_cls
{
    int m_uiItemCount;
    char pad04[0x3c - 4];
    WPosList groups;
    int unk48;
    WClearable l4c;
    int unk50, unk54, unk58;
    WClearable l5c;
    int unk60, unk64, unk68;
    WClearable l6c;
    void UpdateWaterGroups(WActor* actor, bool force);
    bool ShouldShow(WRef* ref, WActor* actor);
    WNode* GetRefNode(WRef* ref);
    void Cleanup(WGroup* g, int a, int b);
    void DoReflect(WActor* actor);
    void DoRefract(WActor* actor);
    void RenderReflect(WActor* actor, WGroup* g, bool full);
    void RenderRefract(WActor* actor, WGroup* g);
    void FinishReflect();
    void FinishRefract();
    void Finalize(WGroup* g);
    void FinalizeReflect(WGroup* g);
    void SetupDepth(void* tex, WGroup* g, bool first, unsigned short id);
    void FinishDepth(WGroup* g, unsigned short id);
    void UpdateA(WGroup* g);
    void UpdateB(WGroup* g);
};

// Scans water groups and their refs, flags visible groups, renders reflection/refraction passes, and finalizes or cleans up each group.
// @fnv 0x004e21b0
void FUN_004e21b0_cls::UpdateWaterGroups(WActor* actor, bool force)
{
    WListPos* aPos3;
    WListPos* next;
    bool b = false;
    bool B = false;
    DAT_011c7a68 = 0;
    aPos3 = groups.GetHead();
    next = 0;
    while (aPos3)
    {
        next = groups.GetNext(aPos3);
        if (aPos3)
        {
            WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
            g4->b5d = false;
            g4->b5f = false;
            g4->b5e = false;
            g4->b60 = false;
            WListPos* ipos;
            WListPos* inext;
            ipos = g4->refs.GetHead();
            inext = 0;
            while (ipos)
            {
                inext = g4->refs.GetNext(ipos);
                if (ipos)
                {
                    WRef* ref = (WRef*)g4->refs.GetAt(ipos);
                    WBase* obj = ref->GetBase();
                    if (ref && ref->Get3D() &&
                        ((ref->GetContainingCell() && ref->GetContainingCell()->GetFlagObj()) ||
                         (obj->IsA() && !DAT_011dea10->IsMenuMode())) &&
                        ((!ref->Get3D()->IsHidden() && ShouldShow(ref, actor)) || force))
                    {
                        if (!g4->b5d)
                        {
                            DAT_011c7a68++;
                            g4->b5d = true;
                            b = true;
                            if (!IsDisabled())
                            {
                                if (DAT_011dea10->IsMenuMode())
                                    g4->b5f = true;
                                else if (g4->b5c)
                                    DAT_011c7a66 = true;
                                else
                                    DAT_011c7a67 = true;
                            }
                        }
                        if (obj->IsB() && obj->IsC())
                        {
                            if (!g4->c3c.Test() || !g4->c30.Test() ||
                                (ref->GetHolder()->GetGeom() && !ref->GetHolder()->GetGeom()->Check()) || obj->IsD() ||
                                (obj->IsE() && !GetGlobalFlag()->Check()))
                            {
                                g4->b5e = true;
                                B = true;
                            }
                        }
                        if (!DAT_011dea10->IsMenuMode() && *DAT_011c7a90.Get() &&
                            (obj->IsE() || *DAT_011c7aa8.Get() || obj->IsF()))
                        {
                            g4->b60 = true;
                        }
                    }
                    if (!g4 || (ref && g4 && !g4->b5d))
                    {
                        WNode* node = GetRefNode(ref);
                        if (node)
                        {
                            WNode* n = node;
                            WTex* tex = n->GetTex();
                            if (tex && tex->Type() == 13)
                            {
                                WShaderProp* raw = node->GetProperty(3);
                                WShaderProp* pMat4 = raw;
                                pMat4->p13c.Set(0);
                                pMat4->p140.Set(0);
                                pMat4->p138.Set(0);
                                pMat4->p144.Set(0);
                            }
                        }
                    }
                    else
                    {
                        WNode* node = GetRefNode(ref);
                        if (node)
                        {
                            WNode* n = node;
                            WTex* tex = n->GetTex();
                            if (tex && tex->Type() == 13)
                            {
                                WShaderProp* raw = node->GetProperty(3);
                                WShaderProp* pMat4 = raw;
                                if (!pMat4->b80 || !*DAT_011c7b6c.Get())
                                    pMat4->p13c.Set(0);
                                if (!pMat4->b81 || !*DAT_011c7c60.Get())
                                    pMat4->p140.Set(0);
                                if (!pMat4->b63 || !*DAT_011c7bbc.Get())
                                    pMat4->p144.Set(0);
                                pMat4->p138.Set(0);
                            }
                        }
                    }
                }
                ipos = inext;
            }
            if (g4 && !g4->b5d)
            {
                if (g4->p58.Get())
                {
                    WShaderProp* raw = ((WNode*)g4->p58.Get())->GetProperty(3);
                    WShaderProp* prop = raw;
                    prop->p13c.Set(0);
                    prop->p140.Set(0);
                    prop->p144.Set(0);
                    prop->p138.Set(0);
                }
                Cleanup(g4, 0, 0);
            }
            else if (g4)
            {
                if (g4->p58.Get())
                {
                    WShaderProp* raw = ((WNode*)g4->p58.Get())->GetProperty(3);
                    WShaderProp* prop = raw;
                    if (!prop->b80 || !*DAT_011c7b6c.Get())
                        prop->p13c.Set(0);
                    if (!prop->b81 || !*DAT_011c7c60.Get())
                        prop->p140.Set(0);
                    if (!prop->b63 || !*DAT_011c7bbc.Get())
                        prop->p144.Set(0);
                    prop->p138.Set(0);
                }
                if (!*DAT_011c7b6c.Get())
                    Cleanup(g4, 0, 0);
                if (!*DAT_011c7bbc.Get())
                {
                    if (DAT_011c7b68.Get())
                        GetRenderedTex(DAT_011c7b68.Get())->Release();
                    DAT_011c7b68.Set(0);
                }
            }
        }
        aPos3 = next;
    }

    if (b || DAT_011c7a66 || DAT_011c7a67)
    {
        if (!DAT_011dea10->IsMenuMode())
        {
            if (DAT_011c7a66)
            {
                DAT_011c7a6c = m_uiItemCount;
                m_uiItemCount++;
                DoReflect(actor);
            }
            if (DAT_011c7a67)
            {
                DAT_011c7a70 = m_uiItemCount;
                m_uiItemCount++;
                DoRefract(actor);
            }
        }
        aPos3 = groups.GetHead();
        next = 0;
        while (aPos3)
        {
            next = groups.GetNext(aPos3);
            if (aPos3)
            {
                WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
                if (g4->b5d && !IsDisabled())
                {
                    l4c.Clear();
                    l5c.Clear();
                    g4->a7c.Accum();
                    g4->a88.Accum();
                    if (m_uiItemCount + 1 < 16)
                    {
                        if (*DAT_011c7b6c.Get() && g4->b5f)
                        {
                            g4->i9c = m_uiItemCount;
                            m_uiItemCount++;
                            if (*DAT_011c7c00.Get() || DAT_011dea10->IsMenuMode())
                                RenderReflect(actor, g4, false);
                            else
                                RenderReflect(actor, g4, true);
                        }
                        if (g4->b5e && *DAT_011c7bbc.Get())
                        {
                            g4->ia0 = m_uiItemCount;
                            m_uiItemCount++;
                            RenderRefract(actor, g4);
                        }
                    }
                    else
                    {
                        char buf[256];
                        sprintf_s_(
                            buf, 256,
                            "WATER: Can not render water group at height %f using water type %s. You are using too many water groups : %d",
                            g4->plane1.Height(), g4->water->GetEditorID(), ((WCountList*)&groups)->Count());
                        ConsolePrint("%s", buf);
                        g4->b5d = false;
                    }
                }
            }
            aPos3 = next;
        }
        if (!DAT_011dea10->IsMenuMode())
        {
            if (DAT_011c7a66 && !IsDisabled())
                FinishReflect();
            if (DAT_011c7a67 && !IsDisabled())
                FinishRefract();
            aPos3 = groups.GetHead();
            next = 0;
            while (aPos3)
            {
                next = groups.GetNext(aPos3);
                if (aPos3)
                {
                    WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
                    if (g4->b5d && !IsDisabled())
                        Finalize(g4);
                    else
                        Cleanup(g4, 0, 0);
                }
                aPos3 = next;
            }
        }
        else
        {
            aPos3 = groups.GetHead();
            next = 0;
            while (aPos3)
            {
                next = groups.GetNext(aPos3);
                if (aPos3)
                {
                    WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
                    if (g4->b5d && !IsDisabled())
                    {
                        if (*DAT_011c7b6c.Get() && g4->b5f)
                            FinalizeReflect(g4);
                        Finalize(g4);
                    }
                    else
                    {
                        Cleanup(g4, 0, 0);
                    }
                }
                aPos3 = next;
            }
        }
        bool first = true;
        aPos3 = groups.GetHead();
        next = 0;
        WRect old(0.0f, 0.0f, 0.0f, 0.0f);
        GetRenderer()->GetViewport(&old);
        WRect full = DAT_011a9bd0;
        GetRenderer()->SetViewport(&full);
        WPos3 p9 = *actor->GetPos();
        RenderGroupPass(30, WRect(p9.x, p9.y, p9.z, 0.0f));
        while (aPos3)
        {
            next = groups.GetNext(aPos3);
            if (aPos3)
            {
                WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
                if (g4->b5d && *DAT_011c7bbc.Get() && g4->b5e && !IsDisabled())
                {
                    if (first)
                        SetRenderTarget(7, ((WTexObj*)DAT_011c7b68.Get())->Index());
                    else
                        SetRenderTarget(0, ((WTexObj*)DAT_011c7b68.Get())->Index());
                    SetupDepth(g4->pa8.Get(), g4, first, g4->usac);
                    BeginScene();
                    DAT_011c7a74 = *(int*)&g4->usac;
                    WOffscreen off;
                    off.SetFlags(0, 1);
                    off.SetClear(0, 1.0f, 0.0f, 0.0f, 1.0f);
                    SetStencil(2, 0xff, *(int*)&g4->usac, 0);
                    GetDrawer(0x28)->Draw(GetRenderer(), DAT_011c7b68.Get(), &off, 0);
                    FinishDepth(g4, g4->usac);
                    EndScene();
                    first = false;
                }
            }
            aPos3 = next;
        }
        GetRenderer()->SetViewport(&old);
        l6c.Clear();
        aPos3 = groups.GetHead();
        next = 0;
        while (aPos3)
        {
            next = groups.GetNext(aPos3);
            if (aPos3)
            {
                WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
                if (g4->b5d)
                {
                    UpdateA(g4);
                    UpdateB(g4);
                }
            }
            aPos3 = next;
        }
    }
    else
    {
        if (DAT_011c7b68.Get())
            GetRenderedTex(DAT_011c7b68.Get())->Release();
        if (DAT_011c7b64.Get())
            GetRenderedTex(DAT_011c7b64.Get())->Release();
        aPos3 = groups.GetHead();
        next = 0;
        while (aPos3)
        {
            next = groups.GetNext(aPos3);
            if (aPos3)
            {
                WGroup* g4 = (WGroup*)groups.GetAt(aPos3);
                if (g4->water && g4->water->p30.Get())
                {
                    GetRenderedTex(g4->water->p30.Get())->Release();
                    g4->water->p30.Set(0);
                }
            }
            aPos3 = next;
        }
        DAT_011c7b68.Set(0);
        DAT_011c7b64.Set(0);
    }
}
}  // namespace fnv_004e21b0

namespace fnv_004e3320 {
struct WaterGroup : WaterSurface
{
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
    unsigned char unk5c;
    bool needsUpdate;
};
struct WaterNodeLink
{
    void FUN_006e5cc0(const WaterNodeLink*);
    void FUN_0066b0d0(void*);
};
struct WaterShaderProperty
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned short unk60;
    bool reflected;
    unsigned char unk63;
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
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    WaterNodeLink node;
};
struct NiProperty;
struct NiGeometry
{
    NiProperty* GetProperty(int);
};
struct NiAVObject
{
    bool FUN_00456610();
};
struct InteriorState
{
    void* FUN_005f36f0();
};
extern WaterNodeLink DAT_011c7ad4, DAT_011c7c2c;
extern bool DAT_011c7a66, DAT_011c7a67;
void FNV_Warning(const char*);
struct WaterSystemUpdate : WaterZoneManager
{
    WaterGroup* group;
    bool FUN_004e62e0(TESObjectREFR*, void*);
    NiGeometry* FUN_004e8030(TESObjectREFR*);
    void ClearTextureAndShaderTextures(WaterGroup*, int, int);
    void FUN_004e3520(WaterGroup*);
    void UpdateWaterGroup(void* context, bool force);
};
// Iterates the group's water references, marks the group for update when a reference needs it or force is set, and updates or clears each water shader property.
// @fnv 0x004e3320
void WaterSystemUpdate::UpdateWaterGroup(void* context, bool force)
{
    if (group)
    {
        if (reinterpret_cast<InteriorState*>(g_TES)->FUN_005f36f0())
        {
            FNV_Warning("WATER: LOD Water objects still trying to update in an interior when they should not be.");
            return;
        }
        group->needsUpdate = false;
        void* position = group->m_kWaterReferences.GetHeadPos();
        void* nextPosition = 0;
        while (position)
        {
            nextPosition = group->m_kWaterReferences.DereferenceIfNotNull(position);
            if (position)
            {
                TESObjectREFR* reference = group->m_kWaterReferences.AddEight(position);
                if ((reference->GetNiNode_v() &&
                     !reinterpret_cast<NiAVObject*>(reference->GetNiNode_v())->FUN_00456610() &&
                     FUN_004e62e0(reference, context)) ||
                    force)
                {
                    group->needsUpdate = true;
                    NiGeometry* geometry = FUN_004e8030(reference);
                    if (geometry)
                    {
                        NiProperty* property = geometry->GetProperty(3);
                        WaterShaderProperty* waterProperty = reinterpret_cast<WaterShaderProperty*>(property);
                        if (!FUN_004e2180())
                        {
                            if (waterProperty->reflected)
                            {
                                DAT_011c7a66 = true;
                                waterProperty->node.FUN_006e5cc0(&DAT_011c7ad4);
                            }
                            else
                            {
                                DAT_011c7a67 = true;
                                waterProperty->node.FUN_006e5cc0(&DAT_011c7c2c);
                            }
                        }
                        else
                        {
                            ClearTextureAndShaderTextures(group, 0, 0);
                        }
                    }
                }
                else if (reference->GetNiNode_v())
                {
                    NiGeometry* geometry = FUN_004e8030(reference);
                    if (geometry)
                    {
                        NiProperty* property = geometry->GetProperty(3);
                        WaterShaderProperty* waterProperty = reinterpret_cast<WaterShaderProperty*>(property);
                        waterProperty->node.FUN_0066b0d0(0);
                    }
                }
            }
            position = nextPosition;
        }
        if (group->needsUpdate)
            FUN_004e3520(group);
    }
}
}  // namespace fnv_004e3320

namespace PlaneRegistry {
struct Vector
{
    float x, y, z;
    Vector(float, float, float);
    void FUN_004a0c10();
};
struct Matrix
{
    Vector FUN_004b4500(const Vector&);
};
struct Plane
{
    float x, y, z, d;
    Plane(const Vector&, const Vector&);
    const Vector& FUN_006815c0();
    float FUN_0084d030();
};
struct Update
{
    float time;
    int flags, extra;
    Update(float, int, int);
};
struct String
{
    const char* FUN_0043b1b0();
};
struct Node
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
    virtual void UpdateNode(Update*);
    const Vector& FUN_0045bb80();
    void FUN_00440460(const Vector&);
    String* FUN_00413f40();
};
struct Physics
{
    void FUN_00547440(float);
};
struct Base
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
    virtual void* GetType();
};
struct Object
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
    virtual bool IsSpecial();
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
    virtual Node* GetNode();
    Base* FUN_007af430();
    void FUN_00575830(const Vector&);
    Physics* FUN_008d6f30();
};
struct ReferenceListNode
{
    void* head;
    void FUN_0076b660(Object**);
};
struct Record
{
    void* type;
    Plane first, second;
    ReferenceListNode objects;
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
    bool active;
    char unk5d, unk5e, unk5f;
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
    Record();
    static void* operator new(unsigned int);
};
struct List
{
    void* head;
    void* FUN_00559450();
    void* DereferenceIfNotNull(void*);
    Record*& AddEight(void*);
    void FUN_007b5330(void*, Record**);
    void FUN_004ed8c0(Record**);
};
struct BoolSetting
{
    const bool& FUN_00408d60();
};
extern BoolSetting DAT_011c7adc;
struct FloatSetting
{
    const float& FUN_00403e20();
};
extern FloatSetting DAT_011c7a7c;
extern float DAT_01012054, DAT_01013ea4;
extern char DAT_01023130[];
bool AreVectorsEqual(const Vector&, const Vector&, float);
bool IsApproximatelyEqual(float, float, float);
void FUN_005b5e40(const char*, ...);
struct Water
{
    float FUN_0045cd80();
};
struct World
{
    int FUN_005f36f0();
    Water* FUN_004fd3e0();
};
extern World* DAT_011dea10;
struct Owner
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
    List records;
    void FUN_004e3590(Record*, Object*);
    void FUN_004e65d0();
    void SetBitFlagsOnListItems();
    bool FUN_004e4730(Object*, const Vector*, Matrix*);
};
// @fnv 0x004e4730
bool Owner::FUN_004e4730(Object* object, const Vector* origin, Matrix* rotation)
{
    if (!DAT_011c7adc.FUN_00408d60())
        return false;
    Vector normal9(0.0f, 0.0f, 1.0f);
    Vector oppositeX(0.0f, 0.0f, DAT_01012054);
    normal9 = rotation->FUN_004b4500(normal9);
    normal9.FUN_004a0c10();
    oppositeX = rotation->FUN_004b4500(oppositeX);
    oppositeX.FUN_004a0c10();
    Plane plane(normal9, *origin);
    Plane reverse4(oppositeX, *origin);
    Base* base = object->FUN_007af430();
    void* pos2 = records.FUN_00559450();
    void* next2 = 0;
    void* beforeB = 0;
    bool found = false;
    while (pos2)
    {
        next2 = records.DereferenceIfNotNull(pos2);
        if (pos2)
        {
            Record* record = records.AddEight(pos2);
            if (AreVectorsEqual(record->first.FUN_006815c0(), plane.FUN_006815c0(), DAT_01013ea4) &&
                IsApproximatelyEqual(record->first.FUN_0084d030(), plane.FUN_0084d030(), DAT_011c7a7c.FUN_00403e20()))
            {
                void* type = base->GetType();
                if (type == record->type)
                {
                    if (!object->IsSpecial() &&
                        !IsApproximatelyEqual(record->first.FUN_0084d030(), plane.FUN_0084d030(), DAT_01013ea4))
                    {
                        Vector location = object->GetNode()->FUN_0045bb80();
                        location.z = (float)record->first.FUN_0084d030();
                        object->GetNode()->FUN_00440460(location);
                        object->FUN_00575830(location);
                        Update update(0.0f, 0, 0);
                        object->GetNode()->UpdateNode(&update);
                        if (object->FUN_008d6f30())
                            object->FUN_008d6f30()->FUN_00547440(location.z);
                        FUN_005b5e40(DAT_01023130, object->GetNode()->FUN_00413f40()->FUN_0043b1b0(),
                                     plane.FUN_0084d030(), (double)location.z);
                    }
                    found = true;
                    FUN_004e3590(record, object);
                    record->objects.FUN_0076b660(&object);
                }
            }
            else if (plane.FUN_0084d030() > record->first.FUN_0084d030())
            {
                beforeB = pos2;
                break;
            }
        }
        pos2 = next2;
    }
    if (!found)
    {
        Record* added = new Record;
        added->first = plane;
        added->second = reverse4;
        added->type = base->GetType();
        FUN_004e3590(added, object);
        added->objects.FUN_0076b660(&object);
        if (beforeB)
            records.FUN_007b5330(beforeB, &added);
        else
            records.FUN_004ed8c0(&added);
        if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() &&
            IsApproximatelyEqual(DAT_011dea10->FUN_004fd3e0()->FUN_0045cd80(), added->first.FUN_0084d030(),
                                 DAT_01013ea4))
            added->active = true;
    }
    FUN_004e65d0();
    SetBitFlagsOnListItems();
    return true;
}
}

namespace fnv_004e4c80 {
struct Node61;
struct Reference61;
struct Form61;
struct Vec61
{
    float x, y, z;
    Vec61(float, float, float);
    void FUN_004a0c10();
};
struct Plane61
{
    float x, y, z, w;
    Plane61(const Vec61&, const Vec61&);
};
struct Matrix61
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Vec61 FUN_004b4500(const Vec61&);
};
struct Update61
{
    float time;
    int unk04, unk08;
    Update61(float, int, int);
};
struct Shader61
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Shader61();
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
    unsigned char unk060, enabled, extra, unk063;
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
};
struct Material61
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Material61();
    void FUN_0049ee30(int);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};
struct Node61
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
    virtual void Attach(Node61*, int);
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Node61();
    void FUN_00a5b230(void*);
    void FUN_00439410(void*);
    void FUN_00a5a040();
    void FUN_00a59c60(const Update61&);
};
struct Reference61
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
    virtual void Attach(Node61*, int);
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
    Reference61();
    void FUN_00484490();
    void FUN_00575690(void*);
    Form61* FUN_007af430();
};
struct Form61
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
    virtual unsigned int Kind();
};
struct ReferenceList61
{
    void FUN_0076b660(Reference61* const&);
};
struct Water61
{
    unsigned int kind;
    Plane61 plane;
    int unk14, unk18, unk1c, unk20;
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
    bool enabled;
    unsigned char unk61, unk62, unk63;
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
    Water61();
};
struct Cell61
{
    void* FUN_00580330();
};
struct World61
{
    World61* FUN_004fd3e0();
    bool IsFlagSet();
    Cell61* FUN_005860c0();
    float FUN_0045cd80();
};
struct Toggle61
{
    bool* FUN_00408d60();
};
extern World61* DAT_011dea10;
extern Matrix61 DAT_011a9448;
extern unsigned int DAT_011c7a4c;
extern Toggle61 DAT_011c7c00;
void* FUN_00438220();
void* FUN_005d9660();
void FUN_00b57e30(Node61*, int, int);
struct Main61
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
    Water61* water;
    void FUN_004e65d0();
    Reference61* CreateWaterReference(Node61*, World61*, Node61*, Node61*, bool);
};
// @fnv 0x004e4c80
Reference61* Main61::CreateWaterReference(Node61* geometry, World61* world, Node61* parent, Node61* intermediate,
                                          bool extra)
{
    if (!DAT_011dea10->FUN_004fd3e0()->IsFlagSet() && !world->IsFlagSet())
    {
        Reference61* reference2 = new Reference61;
        reference2->FUN_00484490();
        Shader61* shader82 = new Shader61;
        shader82->enabled = 1;
        if (extra)
            shader82->extra = 1;
        geometry->FUN_00a5b230(FUN_00438220());
        geometry->FUN_00439410(shader82);
        geometry->FUN_00a5a040();
        FUN_00b57e30(geometry, 0, 0);
        Material61* material11 = new Material61;
        material11->FUN_0049ee30(3);
        geometry->FUN_00a5b230(FUN_005d9660());
        geometry->FUN_00439410(material11);
        reference2->FUN_00575690(world->FUN_005860c0()->FUN_00580330());
        Node61* node15 = new Node61;
        Node61* attachment2 = node15;
        if (intermediate)
        {
            attachment2 = intermediate;
            node15->Attach(attachment2, 1);
            attachment2->Attach(geometry, 1);
        }
        else
            node15->Attach(geometry, 1);
        reference2->Attach(node15, 1);
        Update61 update5(0.0f, 0, 0);
        geometry->FUN_00a59c60(update5);
        node15->FUN_00a59c60(update5);
        attachment2->FUN_00a59c60(update5);
        Vec61 position4(0.0f, 0.0f, world->FUN_0045cd80());
        Matrix61 rotation14 = DAT_011a9448;
        if (water)
        {
            ((ReferenceList61*)&water->unk24)->FUN_0076b660(reference2);
            DAT_011c7a4c++;
        }
        else
        {
            Water61* created43 = new Water61;
            Vec61 normal3(0.0f, 0.0f, 1.0f);
            normal3 = rotation14.FUN_004b4500(normal3);
            normal3.FUN_004a0c10();
            Plane61 plane2(normal3, position4);
            created43->plane = plane2;
            Form61* form15 = reference2->FUN_007af430();
            created43->kind = form15->Kind();
            ((ReferenceList61*)&created43->unk24)->FUN_0076b660(reference2);
            if (!*DAT_011c7c00.FUN_00408d60())
                created43->enabled = 1;
            water = created43;
        }
        parent->Attach(node15, 1);
        FUN_004e65d0();
        return reference2;
    }
    return 0;
}
}  // namespace fnv_004e4c80

extern GlobalObject_0045cf30 g_011c7adc;

struct WaterPtrList
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const;
    void* DereferenceIfNotNull(void*) const;
    void*& AddEight(void*) const;
    void* RemovePos(void*&);
    unsigned int FUN_0044ddc0() const;
    bool FUN_0076b610() const;
    ~WaterPtrList();
};

struct PlaneEquation
{
    float nx, ny, nz, c;
    ~PlaneEquation();
    const NiPoint3& GetPlaneNormal() const;
    float FUN_0084d030() const;
};

struct WaterGroup
{
    TESWaterForm* m_pOwningWater;
    PlaneEquation m_kWaterPlane;
    PlaneEquation m_kSecondaryPlane;
    WaterPtrList m_kWaterReferences;
};

template <int N> struct WaterNodePtr
{
    void* m_pObject;
    WaterNodePtr& operator=(void*);
};

struct WaterShaderProp
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
    WaterNodePtr<2> unk138;
    WaterNodePtr<0> unk13c;
    WaterNodePtr<1> unk140;
    WaterNodePtr<3> unk144;
};

struct WaterGeom
{
    void* GetProperty(unsigned int);
};

struct WaterRotation
{
    NiPoint3 FUN_004b4500(const NiPoint3*) const;
};

class WaterSystem5370
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
    int unk38;
    WaterPtrList m_kWaterZoneList;
    WaterGeom* FUN_004e8030(TESObjectREFR*);
    void ReleaseWaterResources(int, int);
    void SetBitFlagsOnListItems();
    bool RemoveWaterRef(TESObjectREFR* apRef, const NiPoint3* apPos, const WaterRotation* apRot);
};

// @fnv 0x004e5370
bool WaterSystem5370::RemoveWaterRef(TESObjectREFR* apRef, const NiPoint3* apPos, const WaterRotation* apRot)
{
    if (DAT_01189624 && g_011c7adc.Bool()->b)
    {
        NiPoint3 kNormal2(0.0f, 0.0f, 1.0f);
        NiPoint3 kPoint3 = NiPoint3::ZERO;
        kNormal2 = apRot->FUN_004b4500(&kNormal2);
        kNormal2.ComputeMagnitude();
        kPoint3 = *apPos;
        NiPlane m_kFogPlane(kNormal2, kPoint3);
        void* pos5 = m_kWaterZoneList.GetHeadPos();
        void* nextPos5 = 0;
        while (pos5)
        {
            nextPos5 = m_kWaterZoneList.DereferenceIfNotNull(pos5);
            if (pos5)
            {
                WaterGroup* pGroup = (WaterGroup*)m_kWaterZoneList.AddEight(pos5);
                if (AreVectorsEqual(pGroup->m_kWaterPlane.GetPlaneNormal(), m_kFogPlane.GetPlaneNormal(), 0.01f) &&
                    IsApproximatelyEqual(pGroup->m_kWaterPlane.FUN_0084d030(), m_kFogPlane.FUN_0084d030(), 0.01f))
                {
                    void* refPos5 = pGroup->m_kWaterReferences.GetHeadPos();
                    void* nextRefPos6 = 0;
                    while (refPos5)
                    {
                        nextRefPos6 = pGroup->m_kWaterReferences.DereferenceIfNotNull(refPos5);
                        if (refPos5)
                        {
                            TESObjectREFR* pRefB = (TESObjectREFR*)pGroup->m_kWaterReferences.AddEight(refPos5);
                            if (pRefB == apRef)
                            {
                                pGroup->m_kWaterReferences.RemovePos(refPos5);
                                WaterGeom* aPGeom = FUN_004e8030(pRefB);
                                if (aPGeom)
                                {
                                    void* pPropTmp = aPGeom->GetProperty(3);
                                    WaterShaderProp* pRawProp = (WaterShaderProp*)pPropTmp;
                                    pRawProp->unk13c = 0;
                                    pRawProp->unk140 = 0;
                                    pRawProp->unk138 = 0;
                                    pRawProp->unk144 = 0;
                                }
                                if (!pGroup->m_kWaterReferences.FUN_0044ddc0())
                                {
                                    m_kWaterZoneList.RemovePos(pos5);
                                    delete pGroup;
                                    pGroup = 0;
                                }
                                if (m_kWaterZoneList.FUN_0076b610())
                                {
                                    ReleaseWaterResources(1, 0);
                                }
                                SetBitFlagsOnListItems();
                                return true;
                            }
                            refPos5 = nextRefPos6;
                        }
                    }
                }
            }
            pos5 = nextPos5;
        }
    }
    return false;
}

struct Texture58a0;
struct TextureManager58a0
{
    void ReleaseTexture(Texture58a0* apTexture);
};
TextureManager58a0* __stdcall GetTextureManager58a0();

struct TexPtr58a0
{
    Texture58a0* m_pObject;
    operator Texture58a0*() const;
    TexPtr58a0& operator=(Texture58a0* p);
};
struct NodePtr58a0
{
    NiAV5140* m_pObject;
    operator NiAV5140*() const;
};

struct Shader58a0
{
    int FUN_008d8520();
};
struct Geom58a0
{
    Shader58a0* FUN_004030b0();
};

struct Owner58a0
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
    List5140 kList;
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
    TexPtr58a0 spTexture;
    NodePtr58a0 m_pController;
};

struct Cls58a0 : Cls5140
{
    void ClearTextureAndShaderTextures(Owner58a0* apOwner, int aiUnused1, int aiUnused2);
};

// Releases the owner's texture, clears the texture pointer, and clears the texture on shader properties of nodes in its list and its node pointer.
// @fnv 0x004e58a0
void Cls58a0::ClearTextureAndShaderTextures(Owner58a0* apOwner, int aiUnused1, int aiUnused2)
{
    if (apOwner)
    {
        if (apOwner->spTexture)
        {
            GetTextureManager58a0()->ReleaseTexture(apOwner->spTexture);
            apOwner->spTexture = 0;
        }
        void* pos2 = apOwner->kList.GetHeadPos();
        void* next2 = 0;
        while (pos2)
        {
            next2 = apOwner->kList.GetNextPos(pos2);
            Ref5140* ref = apOwner->kList.GetAt(pos2);
            if (ref && ref->GetBase())
            {
                NiAV5140* nodeB = FUN_004e8030(ref);
                if (nodeB)
                {
                    Shader58a0* shader7;
                    Geom58a0* pGeom = (Geom58a0*)nodeB;
                    shader7 = pGeom->FUN_004030b0();
                    if (shader7 && shader7->FUN_008d8520() == 0xd)
                    {
                        Prop5140* prop9 = nodeB->GetProperty(3);
                        Prop5140* shadeProp9 = prop9;
                        shadeProp9->spTex = 0;
                    }
                }
            }
            pos2 = next2;
        }
        if (apOwner->m_pController)
        {
            Prop5140* prop_ = ((NiAV5140*)apOwner->m_pController)->GetProperty(3);
            Prop5140* shadeProp4 = prop_;
            shadeProp4->spTex = 0;
        }
    }
}

struct Node5c80
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* GetData();
};
struct Object5c80
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
    virtual bool IsSpecial();
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
    virtual Node5c80* GetNode();
    int FUN_008d6f30();
    bool FUN_00452370();
    bool FUN_004523e0(int);
};
struct List5c80
{
    int unk00, unk04, unk08;
    void* FUN_00559450();
    void* DereferenceIfNotNull(void*);
    Object5c80** AddEight(void*);
    int FUN_0049c680(Object5c80**, int);
    void FUN_0076b660(Object5c80**);
};
struct Entry5c80
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    List5c80 first;
    List5c80 second;
};
void __cdecl FUN_00578170(void*);
struct Target5c80
{
    Entry5c80* FUN_004e59f0(void*, Object5c80*, float);
    void AddObjectToEntry(void*, Object5c80*, float);
};
// @fnv 0x004e5c80
void Target5c80::AddObjectToEntry(void* location, Object5c80* object, float distance)
{
    if (!location && !object->FUN_008d6f30())
        return;
    void* found;
    Entry5c80* current = FUN_004e59f0(location, object, distance);
    if (!current)
        return;
    found = current->first.FUN_00559450();
    void* next = 0;
    bool entry = false;
    while (found && !entry)
    {
        next = current->first.DereferenceIfNotNull(found);
        if (found)
        {
            Object5c80* value = *current->first.AddEight(found);
            if (value == object)
                entry = true;
            found = next;
        }
    }
    if (entry)
        return;
    else
    {
        if (object->IsSpecial())
        {
            if (!current->second.FUN_0049c680(&object, 0))
                current->second.FUN_0076b660(&object);
        }
        else
            current->first.FUN_0076b660(&object);
        if (object->FUN_00452370() && object->GetNode() && object->FUN_004523e0(2))
        {
            FUN_00578170(object->GetNode()->GetData());
        }
    }
}

namespace fnv_004e6620 {
struct ClearPtr
{
    void* get() const;
    ClearPtr& FUN_0066b0d0(void*);
    void* value;
};
struct WaterProperty
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
    ClearPtr texture138, texture13c, texture140, texture144;
    __forceinline void Clear()
    {
        texture13c.FUN_0066b0d0(0);
        texture140.FUN_0066b0d0(0);
        texture138.FUN_0066b0d0(0);
        texture144.FUN_0066b0d0(0);
    }
};
struct GeometryFUN_004030b0
{
    int FUN_008d8520();
};
struct WaterGeometry
{
    WaterProperty* Property(int);
    GeometryFUN_004030b0* FUN_004030b0();
};
struct WaterList
{
    void* Head() const;
    void* Next(void*) const;
    void*& Item(void*) const;
    int head, tail, count;
};
struct WaterGroup
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
    WaterList objects;
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
    ClearPtr geometry;
};
struct TexturePool
{
    void FUN_00b6da10(void*);
};
TexturePool* __stdcall FUN_004a0ea0();
struct WaterService
{
    void AssignMember238(int);
    void FUN_004e69e0(int);
    void SetParam(int);
    void FUN_004e6a40(int);
};
struct OtherService
{
    void FUN_00ba1250();
    void FUN_00a29680();
};
struct IdFlagState
{
    bool FUN_00ad8ce0();
    void FUN_00ad8d10();
};
extern unsigned char DAT_01189624, DAT_011ad86e;
extern int DAT_011c7a68;
extern ClearPtr DAT_011c7b68, DAT_011c7b64;

struct WaterCleanup
{
    int unk000, unk004;
    ClearPtr texture08;
    int unk00c;
    ClearPtr texture10, texture14, texture18;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    WaterList groups;
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
    IdFlagState sound;
    WaterGeometry* FUN_004e8030(void*);
    void FUN_004e6370(int, int, int);
    bool ReleaseWaterResources(bool release, bool keep);
};
// Clears water textures and geometry properties, releases pooled textures and services, and optionally resets the water system.
// @fnv 0x004e6620
bool WaterCleanup::ReleaseWaterResources(bool release, bool keep)
{
    DAT_01189624 = 0;
    DAT_011ad86e = 0;
    if (release)
    {
        void* pos2 = groups.Head();
        void* next2 = 0;
        while (pos2)
        {
            next2 = groups.Next(pos2);
            if (pos2)
            {
                WaterGroup* group;
                group = (WaterGroup*)groups.Item(pos2);
                if (group->geometry.get())
                {
                    WaterProperty* n;
                    n = ((WaterGeometry*)group->geometry.get())->Property(3);
                    {
                        WaterProperty* clearFirst5 = n;
                        clearFirst5->texture13c.FUN_0066b0d0(0);
                        clearFirst5->texture140.FUN_0066b0d0(0);
                        clearFirst5->texture138.FUN_0066b0d0(0);
                        clearFirst5->texture144.FUN_0066b0d0(0);
                    }
                }
                void* child = group->objects.Head();
                void* childNext9 = 0;
                while (child)
                {
                    childNext9 = group->objects.Next(child);
                    if (child)
                    {
                        void* geomAlias2 = group->objects.Item(child);
                        if (geomAlias2)
                        {
                            WaterGeometry* kRef;
                            kRef = FUN_004e8030(geomAlias2);
                            if (kRef)
                            {
                                WaterGeometry* s;
                                s = kRef;
                                GeometryFUN_004030b0* geom9;
                                geom9 = s->FUN_004030b0();
                                if (geom9 && geom9->FUN_008d8520() == 13)
                                {
                                    WaterProperty* j;
                                    j = kRef->Property(3);
                                    WaterProperty* kClearSecond = j;
                                    kClearSecond->texture13c.FUN_0066b0d0(0);
                                    kClearSecond->texture140.FUN_0066b0d0(0);
                                    kClearSecond->texture138.FUN_0066b0d0(0);
                                    kClearSecond->texture144.FUN_0066b0d0(0);
                                }
                            }
                        }
                    }
                    child = childNext9;
                }
            }
            pos2 = next2;
        }
        if (texture08.get())
            FUN_004a0ea0()->FUN_00b6da10(texture08.get());
        if (texture10.get())
            FUN_004a0ea0()->FUN_00b6da10(texture10.get());
        if (texture14.get())
            FUN_004a0ea0()->FUN_00b6da10(texture14.get());
        if (DAT_011c7b68.get())
            FUN_004a0ea0()->FUN_00b6da10(DAT_011c7b68.get());
        texture08.FUN_0066b0d0(0);
        texture10.FUN_0066b0d0(0);
        texture14.FUN_0066b0d0(0);
        texture18.FUN_0066b0d0(0);
        DAT_011c7b68.FUN_0066b0d0(0);
        if (DAT_011c7b64.get())
            FUN_004a0ea0()->FUN_00b6da10(DAT_011c7b64.get());
        DAT_011c7b64.FUN_0066b0d0(0);
        if (((WaterService*)FUN_004e69d0()))
        {
            ((WaterService*)FUN_004e69d0())->AssignMember238(0);
            ((WaterService*)FUN_004e69d0())->FUN_004e69e0(0);
            ((WaterService*)FUN_004e69d0())->SetParam(0);
        }
        if (((OtherService*)FUN_004e6a70()))
            ((OtherService*)FUN_004e6a70())->FUN_00ba1250();
        if (((OtherService*)FUN_004e6a60()))
            ((OtherService*)FUN_004e6a60())->FUN_00a29680();
        if (sound.FUN_00ad8ce0())
            sound.FUN_00ad8d10();
        if (((WaterService*)FUN_004e69d0()))
            ((WaterService*)FUN_004e69d0())->FUN_004e6a40(0);
    }
    DAT_011c7a68 = 0;
    if (!keep)
        FUN_004e6370(0, 0, 0);
    return true;
}
}  // namespace fnv_004e6620

float FUN_00404010(float, float);
struct WaterCell098
{
    bool FUN_004518e0() const;
    bool IsInterior();
    float FUN_005471e0();
    bool FUN_00550200(const NiPoint3*);
};
struct Point2098
{
    float x, y;
    Point2098& DivideBy(float);
    float NormalizeXY();
    Point2098 operator*(float) const;
};
struct Color098
{
    float r, g, b, a;
    Color098(float, float, float, float);
};
struct DebugNode098
{
    void FUN_00440460(const NiPoint3*);
};
DebugNode098* CreateOctahedron(float, const Color098*, bool);
DebugNode098* FUN_004b3890(const NiPoint3*, const Color098*, const NiPoint3*, const Color098*, bool);
struct SoundData098
{
    unsigned int flags0, flags;
    unsigned int frequency, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct Sound098
{
    SoundData098 CopyBig();
    unsigned int FUN_0084e3a0();
};
struct WaterForm098
{
    Sound098* FUN_00407840();
};
struct CellWater098
{
    WaterForm098* FUN_00547770();
};
struct Player098 : PlayerCharacter
{
    WaterCell098* FUN_0093bba0(float);
    NiPoint3* FUN_00436aa0();
    CellWater098* FUN_008d6f30();
};
struct World098
{
    WaterCell098* FUN_00587550();
};
struct TES098
{
    WaterCell098* FUN_00457070();
    World098* FUN_004fd3e0(const NiPoint3*);
    bool GetLandHeightAt(const NiPoint3*, float*);
    void FUN_00458e20(DebugNode098*, float);
};
struct BSSoundHandleEx
{
    unsigned int soundID, state, extra;
    ~BSSoundHandleEx();
};
struct Audio098
{
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int);
};
Audio098* FUN_00453a70();
struct Handle098
{
    bool FUN_00ad8ce0();
    bool SetPos(float, float, float);
    bool FUN_00ad8930();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    bool Play(bool);
    Handle098& FUN_00418900(const void*);
};
struct WaterSound098
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74,
        unk78, unk7c, unk80, unk84, unk88;
    Handle098 handle;
    unsigned int GetIntValue();
    unsigned int GetGameSettingInt();
    double FUN_004e7640();
    double FUN_004e7660();
    void UpdateWaterSound();
};
extern unsigned char DAT_011c7a64;
extern unsigned char DAT_011c7cfc;
unsigned int GetFlagMask(unsigned int);
extern float DAT_01015f5c;
// @fnv 0x004e6a80
void WaterSound098::UpdateWaterSound()
{
    WaterCell098* cell;
    if (g_thePlayer)
        cell = ((Player098*)g_thePlayer)->FUN_0093bba0((float)GetIntValue());
    else
        cell = ((TES098*)DAT_011dea10)->FUN_00457070();
    if (cell && cell->FUN_004518e0())
    {
        float center = cell->FUN_005471e0();
        Point2098 amount = *(Point2098*)&DAT_011f4980;
        float height;
        if (cell->IsInterior())
        {
            double pos = FUN_004e7640();
            NiPoint3 range = *(((Player098*)g_thePlayer)->FUN_00436aa0());
            if (FUN_004e2180())
                height = 0.0f;
            else if (std::abs(center - range.z) < pos)
                height = (pos - std::abs(center - range.z)) / pos;
            else
                height = 0.0f;
        }
        else
        {
            float step = (float)GetGameSettingInt();
            float count = (float)GetIntValue();
            double point = FUN_004e7660();
            unsigned int current = 0;
            float range = 0.0f;
            float x;
            int y = 0;
            int pos = 0;
            x = 2.0 * count / (step - 1.0);
            NiPoint3 samples = NiPoint3::ZERO;
            NiPoint3 distance = *(((Player098*)g_thePlayer)->FUN_00436aa0());
            WaterCell098* terrain = 0;
            for (y = 0; y < step; y++)
            {
                for (pos = 0; pos < step; pos++)
                {
                    samples = *(((Player098*)g_thePlayer)->FUN_00436aa0());
                    range = 0.0f;
                    samples.x += -1.0 * count + y * x;
                    samples.y += -1.0 * count + pos * x;
                    if (!terrain || !terrain->FUN_00550200(&NiPoint3(samples.x, samples.y, 0.0f)))
                        terrain = ((TES098*)DAT_011dea10)
                                      ->FUN_004fd3e0(&NiPoint3(samples.x, samples.y, 0.0f))
                                      ->FUN_00587550();
                    float water = terrain ? terrain->FUN_005471e0() : DAT_01015f5c;
                    if (((TES098*)DAT_011dea10)->GetLandHeightAt(&samples, &range) && range < water)
                    {
                        current++;
                        amount.x += samples.x;
                        amount.y += samples.y;
                        if (DAT_011c7a64)
                        {
                            DebugNode098* node = CreateOctahedron(10.0f, &Color098(0, 1, 0, 0), true);
                            node->FUN_00440460(
                                &NiPoint3(samples.x, samples.y, FUN_00404010(cell->FUN_005471e0(), range) + 10.0));
                            ((TES098*)DAT_011dea10)->FUN_00458e20(node, 10.0f);
                        }
                    }
                    else if (DAT_011c7a64)
                    {
                        DebugNode098* node = CreateOctahedron(10.0f, &Color098(0, 0, 1, 0), true);
                        node->FUN_00440460(
                            &NiPoint3(samples.x, samples.y, FUN_00404010(cell->FUN_005471e0(), range) + 10.0));
                        ((TES098*)DAT_011dea10)->FUN_00458e20(node, 10.0f);
                    }
                }
            }
            amount.DivideBy((float)current);
            amount.x -= ((Player098*)g_thePlayer)->FUN_00436aa0()->x;
            amount.y -= ((Player098*)g_thePlayer)->FUN_00436aa0()->y;
            height = 2.0 * current / (step * step);
            if (FUN_004e2180())
                height = 0.0f;
            else if (std::abs(center - distance.z) < point)
                height *= (float)((point - std::abs(center - distance.z)) / point);
            else
                height = 0.0f;
        }
        if (height > 1.0)
            height = 1.0f;
        amount.NormalizeXY();
        amount = amount * (float)((1.0 - height) * GetIntValue());
        amount.x += ((Player098*)g_thePlayer)->FUN_00436aa0()->x;
        amount.y += ((Player098*)g_thePlayer)->FUN_00436aa0()->y;
        if (handle.FUN_00ad8ce0())
        {
            if (DAT_011c7a64)
            {
                NiPoint3 line = g_thePlayer->GetPos();
                line.z += 10.0;
                NiPoint3 node(amount.x, amount.y, line.z);
                DebugNode098* point = CreateOctahedron(10.0f, &Color098(1, 0, 0, 0), true);
                point->FUN_00440460(&node);
                ((TES098*)DAT_011dea10)->FUN_00458e20(point, 10.0f);
                DebugNode098* range = FUN_004b3890(&line, &Color098(1, 1, 0, 0), &node, &Color098(1, 1, 0, 0), true);
                ((TES098*)DAT_011dea10)->FUN_00458e20(range, 10.0f);
            }
            handle.SetPos(amount.x, amount.y, cell->FUN_005471e0());
            if (handle.FUN_00ad8930() && height <= 0.0)
            {
                DAT_011c7cfc = 0;
                handle.FUN_00ad88f0();
                handle.FUN_00ad8d10();
            }
            else if (!handle.FUN_00ad8930() && height > 0.0)
            {
                DAT_011c7cfc = 1;
                handle.Play(true);
            }
        }
        else if (height > 0.0 && g_thePlayer && ((Player098*)g_thePlayer)->FUN_008d6f30() &&
                 ((Player098*)g_thePlayer)->FUN_008d6f30()->FUN_00547770() &&
                 ((Player098*)g_thePlayer)->FUN_008d6f30()->FUN_00547770()->FUN_00407840())
        {
            unsigned int sound;
            Sound098* flags = ((Player098*)g_thePlayer)->FUN_008d6f30()->FUN_00547770()->FUN_00407840();
            sound = GetFlagMask(flags->CopyBig().flags);
            sound |= (flags->CopyBig().flags & 0x40) ? 0x8000001 : 2;
            handle.FUN_00418900(&FUN_00453a70()->FUN_00ad73b0(
                ((Player098*)g_thePlayer)->FUN_008d6f30()->FUN_00547770()->FUN_00407840()->FUN_0084e3a0(), sound));
        }
    }
    else if (DAT_011c7cfc && handle.FUN_00ad8ce0())
    {
        DAT_011c7cfc = 0;
        handle.FUN_00ad88f0();
    }
    DAT_011c7a64 = 0;
}

class NiMemObject
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
};

struct SpRef4e8
{
    void* m_pObject;
    SpRef4e8& FUN_006e5cc0(const SpRef4e8& kOther);
    SpRef4e8& FUN_0066b0d0(void* pkObject);
};

class FUN_00b6abb0 : public NiMemObject
{
  public:
    char pad000[0x60];
    unsigned char b60;
    char pad061[0x6c - 0x61];
    float f6c;
    float f70;
    char pad074[0x84 - 0x74];
    unsigned int ui84;
    char pad088[0x138 - 0x88];
    SpRef4e8 sp138;
    SpRef4e8 sp13c;
    char pad140[4];
    SpRef4e8 sp144;
    SpRef4e8 sp148;
    char pad14c[4];

    FUN_00b6abb0();
};

struct Prop4e8
{
    void CloneToTarget(FUN_00b6abb0* pkShader);
};

struct Type4e8
{
    unsigned int FUN_008d8520();
};

struct Geom4e8
{
    Type4e8* FUN_004030b0();
    Prop4e8* FUN_00a59d30(unsigned int uiType);
};

struct Node4e8
{
    void FUN_00440460(const NiPoint3* pkPos);
    void FUN_00439410(FUN_00b6abb0* pkProperty);
};

struct Renderer4e8
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
    virtual void Precache(Node4e8* pkNode, bool bFlag);
};

struct Player4e8
{
    const NiPoint3* FUN_00436aa0();
};
extern Player4e8* DAT_011dea3c;

struct TES4e8
{
    unsigned int FUN_005f36f0();
};

struct Texture4e8
{
    void* FUN_004bc320(int iValue);
};

struct Name4e8
{
    Texture4e8* FUN_00559450();
};
extern Name4e8 DAT_011c7b64;
extern SpRef4e8 DAT_011c7b68;

struct WaterBase4e8
{
    char pad00[0x30];
    SpRef4e8 sp30;
};

struct Item4e8
{
    void** FUN_0073ac90();
};

struct Water4e8
{
    WaterBase4e8* pkBase;
    char pad04[0x20];
    Item4e8 kItem;
    char pad28[0x54 - 0x28];
    SpRef4e8 sp54;
    char pad58[4];
    unsigned char b5c;
    char pad5d[0xac - 0x5d];
    unsigned int uiac;
};

Renderer4e8* __cdecl FUN_004e7ff0();
void __cdecl FUN_00b57e30(Node4e8* pkNode, int iA, int iB);

struct FUN_004e8160_shell
{
    char pad00[0x98];
    float f98;

    void* FUN_004e7730(float fSize, int iCount, int iA, unsigned char ucB, unsigned char ucC);
    Node4e8* CreateRenderedTexture(void* pkGeometry);
    Geom4e8* FUN_004e8030(void* pkRef);
    Node4e8* CreateWaterShaderNode(Water4e8* pkWater, int iUnused, float fSize);
};

// @fnv 0x004e8160
Node4e8* FUN_004e8160_shell::CreateWaterShaderNode(Water4e8* pkWater, int iUnused, float fSize)
{
    void* pkMGeometry = FUN_004e7730(fSize, 0x200, 1, 1, 1);
    Node4e8* pkANode = CreateRenderedTexture(pkMGeometry);
    NiPoint3 kPos(0.0f, 0.0f, 0.0f);
    if (DAT_011dea3c)
        pkANode->FUN_00440460(DAT_011dea3c->FUN_00436aa0());
    else
        pkANode->FUN_00440460(&kPos);
    FUN_004e7ff0()->Precache(pkANode, true);
    FUN_00b6abb0* pkShader = new FUN_00b6abb0;
    pkANode->FUN_00439410(pkShader);
    FUN_00b57e30(pkANode, 0, 0);
    pkShader->f70 = 1.0f;
    void* pkRef = *pkWater->kItem.FUN_0073ac90();
    if (pkRef)
    {
        Geom4e8* pkGeom = FUN_004e8030(pkRef);
        if (pkGeom)
        {
            Geom4e8* pkFTemp = pkGeom;
            Type4e8* pkType = pkFTemp->FUN_004030b0();
            if (pkType && pkType->FUN_008d8520() == 0xd)
            {
                Prop4e8* pkProp = pkGeom->FUN_00a59d30(3);
                Prop4e8* pkProp2 = pkProp;
                pkProp2->CloneToTarget(pkShader);
            }
        }
    }
    if (((TES4e8*)DAT_011dea10)->FUN_005f36f0())
        pkShader->sp13c.FUN_006e5cc0(pkWater->sp54);
    else if (pkWater->b5c)
        pkShader->sp13c.FUN_006e5cc0((SpRef4e8&)DAT_011c7ad4);
    else
        pkShader->sp13c.FUN_006e5cc0((SpRef4e8&)DAT_011c7c2c);
    pkShader->sp144.FUN_006e5cc0(DAT_011c7b68);
    pkShader->sp138.FUN_006e5cc0(pkWater->pkBase->sp30);
    pkShader->sp148.FUN_0066b0d0(DAT_011c7b64.FUN_00559450()->FUN_004bc320(0));
    pkShader->b60 = 1;
    pkShader->f6c = 1.0f;
    pkShader->ui84 = pkWater->uiac;
    f98 = 0.0f;
    return pkANode;
}

namespace fnv_004e8510 {
struct Point2W
{
    float x, y;
    Point2W();
    Point2W(float, float);
    Point2W operator-(const Point2W&) const;
    float Length() const;
    Point2W& operator+=(const Point2W&);
    Point2W& operator-=(const Point2W&);
};
struct FloatSettingW
{
    float* Float();
};
struct BoolSettingW
{
    bool* Bool();
};
struct UpdateW
{
    float time;
    bool a, b, c, d, e;
    UpdateW(float, bool, bool);
};
struct NodeW
{
    void SetPosition(const NiPoint3&);
    void Update(UpdateW&);
};
struct PtrW
{
    NodeW* Get() const;
    PtrW& operator=(NodeW*);
};
struct PlaneW
{
    float x, y, z, w;
    float Height() const;
};
struct GroupW
{
    int unk00;
    PlaneW plane;
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
    PtrW node;
};
struct ListW
{
    void* Head() const;
    void* Next(void*) const;
    GroupW*& At(void*) const;
};
struct OwnerW
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
    ListW groups;
    NodeW* MakeShared();
    NodeW* CalculateNode(GroupW*, unsigned int, float);
    void SpawnGroupNodeNearPlayer(float, float, float, float);
};
extern BoolSettingW DAT_011c7c80, DAT_011c7ac4;
extern FloatSettingW DAT_011c7a7c;
extern PtrW DAT_011c7b64;
extern bool DAT_011fffec;
extern const float DAT_010231a0, DAT_0102319c, DAT_01016248, DAT_0102295c;
struct SinkW
{
    void Set(const Point2W&);
};
extern SinkW DAT_011ada00, DAT_011ada10;
unsigned int FUN_004e7ff0();
float LinearInterpolate(float, float, float, float, float);
// @fnv 0x004e8510
void OwnerW::SpawnGroupNodeNearPlayer(float x, float y, float z, float size)
{
    if (*DAT_011c7c80.Bool() && *DAT_011c7ac4.Bool())
    {
        Point2W playerPos7;
        Point2W offset_;
        playerPos7.x = g_thePlayer->GetPos().x;
        playerPos7.y = g_thePlayer->GetPos().y;
        offset_.x = x;
        offset_.y = y;
        float distance8 = (playerPos7 - offset_).Length();
        if (distance8 <= *DAT_011c7b54.FUN_00403e20())
        {
            void* _pos = groups.Head();
            void* next4 = 0;
            while (_pos)
            {
                next4 = groups.Next(_pos);
                if (_pos)
                {
                    GroupW* group8 = groups.At(_pos);
                    if (IsApproximatelyEqual(group8->plane.Height(), z, *DAT_011c7a7c.Float()) && !group8->node.Get())
                    {
                        if (!DAT_011c7b64.Get())
                        {
                            DAT_011c7b64 = MakeShared();
                            DAT_011fffec = true;
                        }
                        group8->node = CalculateNode(group8, FUN_004e7ff0(), *DAT_011c7b54.FUN_00403e20());
                        NiPoint3 position6 = g_thePlayer->GetPos();
                        position6.z = group8->plane.Height();
                        group8->node.Get()->SetPosition(position6);
                        UpdateW update(0.0f, false, false);
                        group8->node.Get()->Update(update);
                    }
                }
                _pos = next4;
            }
            offset_.x = x - g_thePlayer->GetPos().x;
            offset_.y = y - g_thePlayer->GetPos().y;
            offset_.x = LinearInterpolate(DAT_0102295c, DAT_01016248, DAT_0102319c, DAT_010231a0, offset_.x);
            offset_.y = LinearInterpolate(DAT_0102295c, DAT_01016248, DAT_0102319c, DAT_010231a0, offset_.y);
            offset_ += Point2W(size / 2.0, size / 2.0);
            DAT_011ada00.Set(offset_);
            offset_ -= Point2W(size / 2.0, size / 2.0);
            DAT_011ada10.Set(offset_);
        }
    }
}
}  // namespace fnv_004e8510

namespace fnv_004e8ec0 {
struct WObj;
struct WWaterType
{
    int unk00[12];
    int unk30;
};
struct WStr
{
    int unk0;
    void Set(const void* s);
};
struct WObjPtr
{
    WObj* m_p;
    WObj* Get();
    void Set(WObj* p);
};
struct WProp
{
    char pad00[0x84];
    int unk84;
    char pad88[0x138 - 0x88];
    WStr str138;
    char pad13c[0x144 - 0x13c];
    WStr str144;
    WObjPtr ptr148;
};
struct WRot
{
    float a, b, c;
    WRot(float x, int y, int z);
};
struct WObj
{
    const NiPoint3& GetWorldPos();
    void SetPos(const NiPoint3& p);
    void SetRot(const WRot& r);
    WProp* GetProp(int i);
    int GetTag();
    WObj* GetChild(int i);
};
struct WGroup
{
    WWaterType* waterType;
    NiPlane plane;
    char pad14[0x58 - 0x14];
    WObjPtr obj;
    char pad5c[0xac - 0x5c];
    int unkac;
};
struct WGroupList
{
    void* m_pFirstNode;
    void* m_pTail;
    unsigned int m_uiItemCount;
    void* GetHead();
    void* GetNext(void* pos);
    WGroup*& GetAt(void* pos);
};
struct WMapVal
{
    int unk0;
    int unk4;
    int unk8;
};
struct WMap
{
    int unk0;
    void* GetFirst();
    void GetNext(void** pos, int* key, WMapVal** val);
};
struct WSet
{
    int unk0;
    void Add(void* p);
    int IsEmpty();
};
struct WVec2
{
    float x, y;
    WVec2();
};
struct WMgr
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void RemoveObject(WObj* o);
};
struct WRenderer
{
    void Init(WObj* o, int a, int b);
};
struct WRenderer2
{
    void Reset();
};
struct WRange
{
    int unk0;
    float* Get();
};

bool __cdecl FUN_004e9510();
void __cdecl FUN_00b6b790();
void __cdecl FUN_00b6b8d0(int a, int b);
float __cdecl FUN_00408840(float f);
float __cdecl FUN_00406cc0(float f);
float __cdecl LinearInterpolate(float a, float b, float c, float d, float e);
int __cdecl FUN_004dc060(int a);
WMgr* __cdecl FUN_004e7ff0();
void* __stdcall FUN_004a0e90(WObj* o);
WRenderer* __stdcall FUN_004e3270(int a, void* b);
WRenderer2* __stdcall FUN_004a0ea0(WObj* o);

extern WObjPtr DAT_011c7b64;
extern bool DAT_011fffec;
extern bool DAT_011fffed;
extern bool DAT_011ad832;
extern bool DAT_01200000;
extern int DAT_011c7b68;
extern float DAT_01200024;
extern float DAT_01200028;
extern float DAT_01200014;
extern float DAT_01200018;
extern float DAT_0120001c;
extern float DAT_01200020;
extern WSet DAT_011ada00;
extern WSet DAT_011ada10;

struct FUN_004e8ec0_cls
{
    char pad00[0x3c];
    WGroupList list;
    char pad48[0x7c - 0x48];
    WMap map7c;
    char pad80[0x98 - 0x80];
    float m_fPackageValue;
    WObj* CreateObject();
    void Refresh();
    void UpdateWaterObjects();
};

// @fnv 0x004e8ec0
void FUN_004e8ec0_cls::UpdateWaterObjects()
{
    if (m_fPackageValue < 10.0)
    {
        if (!FUN_004e9510())
            FUN_00b6b790();
        if (!DAT_011c7b64.Get())
        {
            DAT_011c7b64.Set(CreateObject());
            DAT_011fffec = true;
        }
        FUN_00b6b8d0(6, DAT_011c7b64.Get()->GetTag());
        if (DAT_011ad832)
            Refresh();
        if (!FUN_004e9510())
            FUN_00b6b790();

        void* cur = list.GetHead();
        void* next = 0;
        WGroup* group9 = list.GetAt(cur);
        while (cur && !group9->obj.Get())
        {
            next = list.GetNext(cur);
            if (cur)
                group9 = list.GetAt(cur);
            cur = next;
        }
        NiPoint3 _pos = g_thePlayer->GetPos();
        NiPoint3 pos4;
        if (group9->obj.Get())
        {
            pos4 = group9->obj.Get()->GetWorldPos();
        }
        else
        {
            pos4 = _pos;
        }
        WVec2 delta;
        delta.x = _pos.x - pos4.x;
        delta.y = _pos.y - pos4.y;
        bool movedX = false;
        if (FUN_00408840(delta.x) > 4.0 || FUN_00408840(delta.y) > 4.0)
        {
            movedX = true;
            _pos.x = FUN_00406cc0(_pos.x / 4.0) * 4.0;
            _pos.y = FUN_00406cc0(_pos.y / 4.0) * 4.0;
        }
        cur = list.GetHead();
        next = 0;
        while (cur)
        {
            next = list.GetNext(cur);
            if (cur)
            {
                WGroup* g = list.GetAt(cur);
                if (g->obj.Get())
                {
                    _pos.z = g->plane.FUN_0084d030();
                    if (movedX)
                    {
                        g->obj.Get()->SetPos(_pos);
                        WRot rot(0.0f, 0, 0);
                        g->obj.Get()->SetRot(rot);
                    }
                    WProp* raw = g->obj.Get()->GetProp(3);
                    WProp* prop = raw;
                    prop->unk84 = g->unkac;
                    prop->str144.Set(&DAT_011c7b68);
                    prop->str138.Set(&g->waterType->unk30);
                    prop->ptr148.Set(DAT_011c7b64.Get()->GetChild(0));
                }
            }
            cur = next;
        }
        if (movedX)
        {
            DAT_01200024 = LinearInterpolate(-0.5f, 0.5f, -(*DAT_011c7b54.FUN_00403e20() / 2.0),
                                             *DAT_011c7b54.FUN_00403e20() / 2.0, _pos.x - pos4.x);
            DAT_01200028 = LinearInterpolate(0.5f, -0.5f, -(*DAT_011c7b54.FUN_00403e20() / 2.0),
                                             *DAT_011c7b54.FUN_00403e20() / 2.0, _pos.y - pos4.y);
        }
        else
        {
            DAT_01200024 = 0.0f;
            DAT_01200028 = 0.0f;
        }
        if (FUN_004dc060(0) >= 2)
        {
            DAT_011fffed = true;
            DAT_01200014 = 0.4f;
            DAT_01200018 = 0.6f;
            DAT_0120001c = 0.985f;
            DAT_01200020 = 0.01f;
            void* it = map7c.GetFirst();
            while (it)
            {
                WMapVal* val = 0;
                int key = 0;
                map7c.GetNext(&it, &key, &val);
                DAT_011ada00.Add(val);
                DAT_011ada10.Add(&val->unk8);
            }
            if (DAT_011ada00.IsEmpty())
            {
                m_fPackageValue = 0.0f;
            }
            else
            {
                m_fPackageValue += FUN_00452e70(true);
            }
            FUN_004e3270(0x20, FUN_004a0e90(DAT_011c7b64.Get()))->Init(DAT_011c7b64.Get(), 0, 1);
            DAT_011fffed = false;
        }
    }
    else
    {
        void* pos2 = list.GetHead();
        void* next2 = 0;
        while (pos2)
        {
            next2 = list.GetNext(pos2);
            if (pos2)
            {
                WGroup* g2 = list.GetAt(pos2);
                if (g2->obj.Get())
                {
                    FUN_004e7ff0()->RemoveObject(g2->obj.Get());
                    g2->obj.Set(0);
                }
            }
            pos2 = next2;
        }
        if (DAT_011c7b64.Get())
        {
            FUN_004a0ea0(DAT_011c7b64.Get())->Reset();
            DAT_011c7b64.Set(0);
        }
        DAT_01200000 = false;
    }
}
}  // namespace fnv_004e8ec0

namespace fnv_004e9550 {
extern NiPoint3 DAT_011a9478;
struct Frustum9550
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    Frustum9550(bool);
};
struct WUpdate
{
    float time;
    int flags04, flags08;
    WUpdate(float, bool, bool);
};
struct Camera9550
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
    Camera9550();
    ~Camera9550();
    void FUN_00440460(const NiPoint3&);
    void FUN_00a6faf0(const Frustum9550&);
    void FUN_00a59c60(WUpdate&);
    void SetLookAt(const NiPoint3&, const NiPoint3&);
    void* FUN_004a0d10();
    const Frustum9550& FUN_0045bbe0();
};
struct Culler9550
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
    Culler9550(void*);
    ~Culler9550();
    void FUN_0041fd00(Camera9550*);
    void FUN_00a694a0(const Frustum9550&);
};

struct WPlayer
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
    virtual const NiPoint3& GetPosition();
};
extern WPlayer* DAT_011dea3c;
struct WRenderer
{
    void FUN_004a0dd0(void*);
    void SetFromCamera(Camera9550*);
};

extern bool DAT_011ff375;
struct WForm
{
    bool FUN_00450ff0();
};
struct WRef
{
    WForm* FUN_008d6f30();
};
struct WData
{
    int unk00;
    unsigned short count;
};
struct WGeometry;
struct WProperty
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
    int mode;
    WData* FUN_00b69f30(WGeometry*);
};
struct WShader
{
    int FUN_008d8520();
};
struct WGeometry
{
    WShader* FUN_004030b0();
    WProperty* FUN_00a59d30(int);
};
struct WObject
{
    WShader* FUN_004030b0();
};
struct WLevel
{
    float FUN_0084d030();
};
struct WRegion;
struct WList
{
    void* FUN_00559450() const;
    void* DereferenceIfNotNull(void*) const;
    void*& AddEight(void*) const;
};
struct WRegion
{
    int unk00;
    WLevel level;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    WList refs;
};
void FUN_00b994f0(WData*, unsigned short, int, int, int);
void FUN_004e9ce0(int, bool);
namespace std {
float abs(float);
}
struct WSystem
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
    WList regions;
    WGeometry* FUN_004e8030(WRef*);
    bool FUN_004e62e0(WRef*, Camera9550*);
    void UpdateRegions();
};
// Computes the min/max region level, builds an orthographic frustum and camera, renders the scene, then updates geometry data for each region's refs.
// @fnv 0x004e9550
void WSystem::UpdateRegions()
{
    Camera9550 c;
    NiPoint3 eb = NiPoint3::ZERO;
    float b = 3.402823466e+38F;
    float j = 3.402823466e+38F;
    void* q = regions.FUN_00559450();
    void* k = 0;
    while (q)
    {
        k = regions.DereferenceIfNotNull(q);
        if (q)
        {
            WRegion* f = (WRegion*)regions.AddEight(q);
            float s = f->level.FUN_0084d030();
            if (s > b || b == 3.4028234663852886e+38)
                b = s;
            if (s < j || j == 3.4028234663852886e+38)
                j = s;
        }
        q = k;
    }
    Frustum9550 ba(false);
    ba.ortho = true;
    ba.nearPlane = 0.1f;
    ba.left = -(*DAT_011c7b54.FUN_00403e20() / 2.0);
    ba.right = *DAT_011c7b54.FUN_00403e20() / 2.0;
    ba.top = *DAT_011c7b54.FUN_00403e20() / 2.0;
    ba.bottom = -(*DAT_011c7b54.FUN_00403e20() / 2.0);
    ba.farPlane = std::abs(j - b) + 100.0;
    c.FUN_00440460(NiPoint3(DAT_011dea3c->GetPosition().x, DAT_011dea3c->GetPosition().y, b + 50.0));
    c.FUN_00a6faf0(ba);
    WUpdate l(0.0f, false, false);
    c.FUN_00a59c60(l);
    NiPoint3 e(DAT_011dea3c->GetPosition().x, DAT_011dea3c->GetPosition().y, b);
    c.SetLookAt(e, DAT_011a9478);
    ((WRenderer*)FUN_0043c4b0())->FUN_004a0dd0(c.FUN_004a0d10());
    DAT_011ff375 = true;
    Culler9550 cf(0);
    cf.FUN_0041fd00(&c);
    ((WRenderer*)FUN_0043c4b0())->SetFromCamera(&c);
    cf.FUN_00a694a0(c.FUN_0045bbe0());
    q = regions.FUN_00559450();
    k = 0;
    while (q)
    {
        k = regions.DereferenceIfNotNull(q);
        if (q)
        {
            WRegion* f = (WRegion*)regions.AddEight(q);
            void* i = f->refs.FUN_00559450();
            void* s = 0;
            while (i)
            {
                s = f->refs.DereferenceIfNotNull(i);
                if (i)
                {
                    WRef* ref = (WRef*)f->refs.AddEight(i);
                    if (ref && ref->FUN_008d6f30() && ref->FUN_008d6f30()->FUN_00450ff0())
                    {
                        WGeometry* geometry = FUN_004e8030(ref);
                        if (geometry)
                        {
                            WGeometry* s = geometry;
                            WShader* f = s->FUN_004030b0();
                            if (f && f->FUN_008d8520() == 13)
                            {
                                WProperty* _base = geometry->FUN_00a59d30(3);
                                WProperty* i = _base;
                                int f = i->mode;
                                i->mode = 1;
                                if (FUN_004e62e0(ref, &c) && i && i->FUN_00b69f30(s))
                                {
                                    WData* data = i->FUN_00b69f30(s);
                                    FUN_00b994f0(data, data->count, 0, 0, 0);
                                }
                                i->mode = f;
                            }
                        }
                    }
                }
                i = s;
            }
        }
        q = k;
    }
    cf.FUN_0041fd00(0);
    FUN_004e9ce0(0, false);
    DAT_011ff375 = false;
}
}  // namespace fnv_004e9550

class Point4E9
{
  public:
    float x, y, z;
};

class Frustum4E9
{
  public:
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
};

class Viewport4E9
{
  public:
    float m_fMinimumU, m_fMaximumU, m_fMinimumV, m_fMaximumV;
};

class Camera4E9
{
  public:
    const Viewport4E9& GetViewPort() const;
    Point4E9 GetWorldForwardVector() const;
    Point4E9 GetWorldTranslation() const;
    Point4E9 GetWorldUpVector() const;
    const Frustum4E9& GetViewFrustum() const;
    unsigned int GetLODAdjust() const;
};

class CameraState4E9
{
  public:
    void Set(const Viewport4E9& kPort, const Point4E9& kLoc, const Point4E9& kWorldPosition, const Point4E9& kUp,
             const Frustum4E9& kFrustum, unsigned int uiLODAdjust);
    void SetFromCamera(const Camera4E9& kCamera);
};

// @fnv 0x004e9bb0
void CameraState4E9::SetFromCamera(const Camera4E9& kCamera)
{
    Set(kCamera.GetViewPort(), kCamera.GetWorldForwardVector(), kCamera.GetWorldTranslation(),
        kCamera.GetWorldUpVector(), kCamera.GetViewFrustum(), kCamera.GetLODAdjust());
}

namespace fnv_004e9d40 {
struct RefActor;
struct N;
struct C;
struct Camera;
class AutoMemHelper
{
    int old;

  public:
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct P3
{
    float x, y, z;
};
struct FUN_00414430
{
    float r, g, b, a;
    FUN_00414430(float, float, float, float);
};
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a712f0 : NiMemObject
{
    FUN_00a712f0();
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
};
struct FUN_00b660d0 : NiMemObject
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void v8c(FUN_00a712f0*);
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
    FUN_00b660d0(int, int, int);
    void FUN_004a1020(N*);
    void FUN_004ea860(int);
    void SetAccumulate(int);
    void FUN_004a1040(int);
    void FUN_004ea880(FUN_00414430*);
};
struct Process
{
    P3& FUN_004ea950();
    N* FUN_007fa950();
};
struct NodeVector
{
    void FUN_006e5cc0(void*);
};
struct RenderBase
{
};
struct N : RenderBase
{
    N* FUN_00a59d30(int);
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
    NodeVector vector;
};
struct F
{
    bool FUN_004e32c0();
    bool FUN_004ea930();
    bool FUN_004ea8b0();
    bool FUN_004ea8d0();
    bool FUN_004ea8f0();
    bool FUN_004ea910();
    bool FUN_00452440();
};
struct RN
{
    bool FUN_00450ff0();
};
struct ConstraintReference
{
    N* FUN_004ea9a0();
    N* FUN_004ea9c0();
    N* FUN_004ea9e0();
};
struct Cell
{
    N* GetCellNodeAt(int);
};
struct CellHandle
{
    Cell* cell;
};
struct ListEntry;
struct RefList
{
    bool FUN_008256d0();
    ListEntry*& FUN_006815c0();
    RefList* FUN_00726070();
};
struct RefList2
{
    bool FUN_008256d0();
    RefActor*& FUN_006815c0();
    RefList2* FUN_00726070();
};
struct Extra
{
    RefList* FUN_0041f140();
};
struct CellOwner
{
    ConstraintReference* FUN_00586170();
};
struct RefActor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual N* v1d0();
    Process* FUN_008d8520();
    P3& FUN_00891170();
    F* FUN_007af430();
    RN* FUN_008d6f30();
    int FUN_005f36f0();
    CellHandle* FUN_00457050(unsigned int, unsigned int);
    CellOwner* FUN_004fd3e0();
    Extra* FUN_005d43c0();
    bool FUN_00564e60();
};
struct ListEntry
{
    RefActor* ref;
    int flags;
};
struct ColorObj
{
    RefActor* GetFloatAsUInt();
};
struct RefAcc
{
    FUN_00b660d0* pointer;
    FUN_00b660d0* FUN_00559450();
    void FUN_0066b0d0(FUN_00b660d0*);
};
struct RefCam
{
    FUN_00a712f0* pointer;
    FUN_00a712f0* FUN_00559450();
    void FUN_0066b0d0(FUN_00a712f0*);
};
struct NList
{
    int a, b, c;
    void FUN_004ed900();
    void FUN_0076b660(RenderBase* const&);
};
struct IterList
{
    int a, b, c;
    void* FUN_00559450();
    RefActor*& FUN_0057cbe0(void**);
};
struct Map
{
    bool GetAt(RefActor*, RefActor**);
    void FUN_00844700(RefActor*, RefActor*);
};
struct State
{
    int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20;
    IterList refs;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    P3 vector;
    bool colored;
    unsigned char unk61, unk62, unk63;
    NList nodes, more;
    int unk7c, unk80, unk84, unk88, unk8c, unk90;
    RefAcc acc;
    int unk98, index, unka0;
    RefCam camera;
};
struct Setting
{
    unsigned char* FUN_00408d60();
};
extern Setting DAT_011c7cc0, DAT_011c7ae8;
struct GridSetting
{
    unsigned int* FUN_0043d4d0();
};
struct GlobalList
{
    void* FUN_00559450();
    void* DereferenceIfNotNull(void*);
    RefActor*& AddEight(void*);
};
extern GlobalList DAT_011c7b8c;
extern RefActor* DAT_011dea10;
struct Manager
{
    void FUN_00ba3390(FUN_00a712f0*, int, int, NList*, NList*, FUN_00b660d0*, int, int, int);
    void FUN_00ba30f0(int, int);
};
Manager* __cdecl FUN_004ea970();
bool __cdecl FUN_004e2160();
ColorObj* __cdecl FUN_00450b80(int);
void __cdecl FUN_00c4bf40(void*, void*, FUN_00a712f0*);
bool __cdecl FUN_0045bad0(const char*, N*);
char __cdecl FUN_006fd150();
void __cdecl FUN_006fd1a0();
void __cdecl FUN_006fd1b0();
int* __cdecl FUN_004e3260();
extern const char DAT_011fa018[];
struct Target
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
    Map map;
    N* FUN_004e8030(RefActor*);
    bool FUN_004e62e0(RefActor*, void*);
    void FUN_004e9d40(void*, State*, bool);
};
// @fnv 0x004e9d40
void Target::FUN_004e9d40(void* input, State* state, bool special)
{
    bool a;
    {
        void* iter;
        {
            bool c;
            {
                AutoMemHelper context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                                      0xefb);
                {
                    bool b, d, e;
                    if (!FUN_004e2160() || !input)
                        return;
                    state->camera.FUN_0066b0d0(new FUN_00a712f0);
                    FUN_00c4bf40(input, &state->unk4, state->camera.FUN_00559450());
                    if (!state->acc.FUN_00559450())
                        state->acc.FUN_0066b0d0(new FUN_00b660d0(99, 1, 759));
                    state->acc.FUN_00559450()->FUN_004a1020((N*)FUN_00450b80(0));
                    state->acc.FUN_00559450()->FUN_004ea860(1);
                    state->acc.FUN_00559450()->v8c(state->camera.FUN_00559450());
                    state->acc.FUN_00559450()->SetAccumulate(1);
                    if (state->colored)
                    {
                        state->acc.FUN_00559450()->FUN_004a1040(15);
                        P3 light = DAT_011dea10->FUN_008d8520()->FUN_004ea950();
                        P3 tint = FUN_00450b80(0)->GetFloatAsUInt()->FUN_00891170();
                        FUN_00414430 color(light.x * tint.x, light.y * tint.y, light.z * tint.z, 1.0f);
                        state->acc.FUN_00559450()->FUN_004ea880(&color);
                    }
                    a = false;
                    d = false;
                    c = false;
                    e = false;
                    b = false;
                    state->nodes.FUN_004ed900();
                    state->more.FUN_004ed900();
                    iter = state->refs.FUN_00559450();
                    while (iter)
                    {
                        RefActor* ref = state->refs.FUN_0057cbe0(&iter);
                        F* form = ref->FUN_007af430();
                        if (ref && ((ref->FUN_008d6f30() && ref->FUN_008d6f30()->FUN_00450ff0()) ||
                                    (form && form->FUN_004e32c0() && !DAT_011dea10->FUN_005f36f0())))
                        {
                            N* root = 0;
                            N* object = FUN_004e8030(ref);
                            if (object)
                            {
                                N* child = object->FUN_00a59d30(3);
                                if (FUN_0045bad0(DAT_011fa018, child))
                                    root = child;
                            }
                            if (root)
                            {
                                root->vector.FUN_006e5cc0(&state->vector);
                                if (form && form->FUN_004ea930() && !a)
                                {
                                    a = true;
                                    state->nodes.FUN_0076b660(DAT_011dea10->FUN_008d8520()->FUN_007fa950());
                                }
                                if (!special && (*DAT_011c7cc0.FUN_00408d60() ||
                                                 (form && form->FUN_004ea8b0() && !d && !DAT_011dea10->FUN_005f36f0())))
                                {
                                    d = true;
                                    for (unsigned int i = 0; i < DAT_011c63cc.Int()->ui; ++i)
                                        for (unsigned int j = 0; j < DAT_011c63cc.Int()->ui; ++j)
                                        {
                                            CellHandle* owner = DAT_011dea10->FUN_00457050(i, j);
                                            Cell* cell = owner->cell;
                                            if (cell)
                                                for (int k = 0; k < 4; ++k)
                                                {
                                                    N* node = owner->cell->GetCellNodeAt(k);
                                                    state->nodes.FUN_0076b660(node);
                                                }
                                        }
                                }
                                if (DAT_011dea10->FUN_004fd3e0())
                                {
                                    ConstraintReference* data = DAT_011dea10->FUN_004fd3e0()->FUN_00586170();
                                    if (data)
                                    {
                                        unsigned char loaded = FUN_006fd150();
                                        if (!DAT_011dea10->FUN_005f36f0() && loaded)
                                        {
                                            FUN_006fd1a0();
                                            if (form && form->FUN_004ea8d0() && !c)
                                            {
                                                c = true;
                                                if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() &&
                                                    data->FUN_004ea9a0())
                                                    state->nodes.FUN_0076b660(data->FUN_004ea9a0());
                                            }
                                            FUN_006fd1b0();
                                            if (form && form->FUN_004ea8f0() && !e)
                                            {
                                                e = true;
                                                if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() &&
                                                    data->FUN_004ea9c0())
                                                    state->nodes.FUN_0076b660(data->FUN_004ea9c0());
                                            }
                                            if (form && form->FUN_004ea910() && !b)
                                            {
                                                b = true;
                                                if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() &&
                                                    data->FUN_004ea9e0())
                                                    state->nodes.FUN_0076b660(data->FUN_004ea9e0());
                                            }
                                        }
                                    }
                                }
                                if (!special && FUN_004e62e0(ref, input))
                                {
                                    RefList* list = ref->FUN_005d43c0()->FUN_0041f140();
                                    while (list && !list->FUN_008256d0())
                                    {
                                        if (list->FUN_006815c0()->flags & 1)
                                        {
                                            RefActor* item = list->FUN_006815c0()->ref;
                                            if (item->v1d0() && !map.GetAt(item, &item) &&
                                                (DAT_011dea10->FUN_005f36f0() ||
                                                 (!DAT_011dea10->FUN_005f36f0() && !item->FUN_00564e60())))
                                            {
                                                state->nodes.FUN_0076b660(item->v1d0());
                                                map.FUN_00844700(item, item);
                                            }
                                        }
                                        list = list->FUN_00726070();
                                    }
                                }
                                if (!DAT_011dea10->FUN_005f36f0() && !special && form && form->FUN_00452440())
                                {
                                    RefList2* list = (RefList2*)FUN_004e3260();
                                    while (list && !list->FUN_008256d0())
                                    {
                                        RefActor* item = list->FUN_006815c0();
                                        if (item && item->v1d0() && !map.GetAt(item, &item) &&
                                            !item->FUN_00564e60())
                                        {
                                            state->nodes.FUN_0076b660(item->v1d0());
                                            map.FUN_00844700(item, item);
                                        }
                                        list = list->FUN_00726070();
                                    }
                                }
                            }
                        }
                    }
                    if (*DAT_011c7ae8.FUN_00408d60())
                    {
                        void* iter = DAT_011c7b8c.FUN_00559450();
                        void* next = 0;
                        next = DAT_011c7b8c.DereferenceIfNotNull(iter);
                        if (iter)
                        {
                            RefActor* item = DAT_011c7b8c.AddEight(iter);
                            if (item->v1d0() && !map.GetAt(item, &item))
                            {
                                state->more.FUN_0076b660(item->v1d0());
                                map.FUN_00844700(item, item);
                            }
                        }
                        iter = next;
                    }
                    FUN_004ea970()->FUN_00ba3390(state->camera.FUN_00559450(), 0, 0, &state->nodes, &state->more,
                                                 state->acc.FUN_00559450(), 4, state->index + 1, 0);
                    FUN_004ea970()->FUN_00ba30f0(0, state->index + 1);
                }
            }
        }
    }
}
}  // namespace fnv_004e9d40

namespace fnv_004eaa00 {
struct Scope60
{
    int token;
    Scope60(int, int, const char*, int);
    ~Scope60();
};
struct Vector60
{
    float x, y, z;
    Vector60(float, float, float);
};
struct Plane60
{
    float x, y, z, w;
    Plane60(const Vector60&, const Vector60&);
};
struct Color60
{
    float r, g, b, a;
    Color60(float, float, float, float);
};
struct RGB60
{
    float r, g, b;
};
struct Camera60
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Camera60();
};
struct Accumulator60
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
    virtual void SetCamera(Camera60*);
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Accumulator60(int, int, int);
    void FUN_004a1020(void*);
    void FUN_004ea860(int);
    void SetAccumulate(int);
    void FUN_004a1040(int);
    void FUN_004ea880(const Color60&);
};
template <class T> struct Smart60
{
    T* FUN_00559450();
    void FUN_0066b0d0(T*);
};
struct Toggle60
{
    bool* FUN_00408d60();
};
struct Node60
{
};
struct List60
{
    void FUN_004ed900();
    void FUN_0076b660(Node60* const&);
};
struct Weather60
{
    Node60* FUN_004ea9a0();
    Node60* FUN_004ea9c0();
    Node60* FUN_004ea9e0();
};
struct Sky60
{
    float FUN_0045cd80();
    Weather60* FUN_00586170();
};
struct Environment60
{
    RGB60* FUN_004ea950();
    Node60* FUN_007fa950();
};
struct World60
{
    Sky60* FUN_004fd3e0();
    Environment60* FUN_008d8520();
    void* FUN_005f36f0();
};
struct RGBHolder60
{
    RGB60* FUN_00891170();
};
struct Renderer60
{
    RGBHolder60* GetFloatAsUInt();
};
struct Visible60
{
    void FUN_00450f90();
};
struct Player60
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
    virtual Visible60* Visibility(int);
    bool FUN_004eaf60();
};
struct RenderJob60
{
    void FUN_00ba3390(Camera60*, int, int, List60*, List60*, Accumulator60*, int, int, int);
    void FUN_00ba30f0(int, int);
};
extern Smart60<Camera60> DAT_011c7b44;
extern Smart60<Accumulator60> DAT_011c7cb8;
extern Toggle60 DAT_011c7a90, DAT_011c7aa8, DAT_011c7c00;
extern World60* DAT_011dea10;
extern Player60* DAT_011dea3c;
extern List60 DAT_011c7ce4, DAT_011c7b80;
extern int DAT_011c7a6c;
extern char DAT_0102301c[];
bool FUN_004e2160();
Renderer60* FUN_00450b80(int);
void FUN_00c4bf40(void*, const Plane60&, Camera60*);
Node60* FUN_0045c670();
char FUN_006fd150();
void FUN_006fd1a0();
void FUN_006fd1b0();
RenderJob60* FUN_004ea970();
struct Main60
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
    bool changedVisibility;
    void FUN_004eaa00(void*);
};
// Sets up a camera and accumulator, builds a render list from the world and weather, and submits a render job for the given target.
// @fnv 0x004eaa00
void Main60::FUN_004eaa00(void* target)
{
    Scope60 scope6(0x1d, 1, DAT_0102301c, 0xfe3);
    if (!FUN_004e2160() || !target)
        return;
    DAT_011c7b44.FUN_0066b0d0(new Camera60);
    Vector60 normal3(0.0f, 0.0f, 1.0f);
    Vector60 point1(0.0f, 0.0f, DAT_011dea10->FUN_004fd3e0()->FUN_0045cd80());
    Plane60 plane2(normal3, point1);
    FUN_00c4bf40(target, plane2, DAT_011c7b44.FUN_00559450());
    if (!DAT_011c7cb8.FUN_00559450())
        DAT_011c7cb8.FUN_0066b0d0(new Accumulator60(0x63, 1, 0x2f7));
    DAT_011c7cb8.FUN_00559450()->FUN_004a1020(FUN_00450b80(0));
    DAT_011c7cb8.FUN_00559450()->FUN_004ea860(1);
    DAT_011c7cb8.FUN_00559450()->SetCamera(DAT_011c7b44.FUN_00559450());
    DAT_011c7cb8.FUN_00559450()->SetAccumulate(1);
    if (*DAT_011c7a90.FUN_00408d60() || *DAT_011c7aa8.FUN_00408d60())
    {
        DAT_011c7cb8.FUN_00559450()->FUN_004a1040(0xf);
        RGB60 ambientColor = *DAT_011dea10->FUN_008d8520()->FUN_004ea950();
        RGB60 tint = *FUN_00450b80(0)->GetFloatAsUInt()->FUN_00891170();
        Color60 color(ambientColor.r * tint.r, ambientColor.g * tint.g, ambientColor.b * tint.b, 1.0f);
        DAT_011c7cb8.FUN_00559450()->FUN_004ea880(color);
    }
    DAT_011c7ce4.FUN_004ed900();
    DAT_011c7b80.FUN_004ed900();
    if (*DAT_011c7c00.FUN_00408d60())
    {
        if (!DAT_011dea3c->FUN_004eaf60())
        {
            changedVisibility = true;
            DAT_011dea3c->Visibility(1)->FUN_00450f90();
        }
        if (DAT_011dea10->FUN_004fd3e0())
            DAT_011c7ce4.FUN_0076b660(FUN_0045c670());
    }
    else
    {
        DAT_011c7ce4.FUN_0076b660(DAT_011dea10->FUN_008d8520()->FUN_007fa950());
        if (DAT_011dea10->FUN_004fd3e0())
        {
            Weather60* weather = DAT_011dea10->FUN_004fd3e0()->FUN_00586170();
            if (weather)
            {
                unsigned char renderSky = FUN_006fd150();
                if (!DAT_011dea10->FUN_005f36f0() && renderSky)
                {
                    FUN_006fd1a0();
                    if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() && weather->FUN_004ea9a0())
                        DAT_011c7ce4.FUN_0076b660(weather->FUN_004ea9a0());
                    FUN_006fd1b0();
                    if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() && weather->FUN_004ea9c0())
                        DAT_011c7ce4.FUN_0076b660(weather->FUN_004ea9c0());
                    if (!DAT_011dea10->FUN_005f36f0() && DAT_011dea10->FUN_004fd3e0() && weather->FUN_004ea9e0())
                        DAT_011c7ce4.FUN_0076b660(weather->FUN_004ea9e0());
                }
            }
        }
    }
    FUN_004ea970()->FUN_00ba3390(DAT_011c7b44.FUN_00559450(), 0, 0, &DAT_011c7ce4, &DAT_011c7b80,
                                 DAT_011c7cb8.FUN_00559450(), 4, DAT_011c7a6c + 1, 0);
    FUN_004ea970()->FUN_00ba30f0(0, DAT_011c7a6c + 1);
}
}  // namespace fnv_004eaa00

struct WRNode;
struct WRCamera;
struct WRScene;

struct WRPoint3
{
    float x;
    float y;
    float z;

    WRPoint3(float afX, float afY, float afZ);
};

struct WRPlane
{
    WRPoint3 kNormal;
    float fConstant;

    WRPlane(const WRPoint3& arNormal, const WRPoint3& arPoint);
};

struct WRReflectNode
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

    static void* __cdecl operator new(unsigned int auiSize);
    static void __cdecl operator delete(void* apMem, unsigned int);
    WRReflectNode();
};

struct WRAccumulator
{
    virtual void v00();
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
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void SetCullingNode(WRReflectNode* apNode);

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

    static void* __cdecl operator new(unsigned int auiSize);
    static void __cdecl operator delete(void* apMem, unsigned int);
    WRAccumulator(int aiMode, unsigned int auiUnk1, unsigned int auiUnk2);
    void SetRenderScene(WRScene* apScene);
    void FUN_004ea860(bool abFlag);
    void SetAccumulate(bool abFlag);
};

struct WRNodePtr
{
    WRReflectNode* p;

    WRNodePtr& operator=(WRReflectNode* apNode);
    operator WRReflectNode*() const;
};

struct WRAccumPtr
{
    WRAccumulator* p;

    WRAccumPtr& operator=(WRAccumulator* apAccum);
    operator WRAccumulator*() const;
    WRAccumulator* operator->() const;
};

struct WRList
{
    void RemoveAll();
    void AddTail(const unsigned int& arItem);
};

struct WRWorldSpace
{
    float UpdateTESState() const;
};

struct WRProcess
{
    unsigned int GetRoot();
};

struct WRTES
{
    WRWorldSpace* GetParentWorldSpace();
    WRProcess* GetProcess();
};

struct WRRenderer
{
    void RenderReflections(WRReflectNode* apNode, int aiUnk1, int aiUnk2, WRList* apList1, WRList* apList2,
                           WRAccumulator* apAccum, int aiUnk3, int aiFrame, int aiUnk4);
    void SetFrame(int aiUnk, int aiFrame);
};

bool __cdecl WRIsEnabled();
WRScene* __cdecl WRGetScene(int aiIndex);
WRRenderer* __cdecl WRGetRenderer();
void __cdecl WRCullScene(WRCamera* apCamera, WRPlane& arPlane, WRReflectNode* apNode);

extern WRNodePtr g_spWaterReflectNode;
extern WRAccumPtr g_spWaterAccumulator;
extern WRList g_kWaterListA;
extern WRList g_kWaterListB;
extern int g_iWaterFrame;
extern WRTES* g_pWRTES;

struct WRWaterManager
{
    void UpdateWaterReflection(WRCamera* apCamera);
};

// Builds a water reflection node, culls the scene against the water plane, and renders reflections into the water accumulator for the next frame.
// @fnv 0x004eaf80
void WRWaterManager::UpdateWaterReflection(WRCamera* apCamera)
{
    AutoMemContext kMemContext4(MC_Water, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                                0x1054);
    if (!WRIsEnabled() || !apCamera)
        return;

    g_spWaterReflectNode = new WRReflectNode;
    WRPoint3 kNormal(0.0f, 0.0f, 1.0f);
    WRPoint3 kPoint(0.0f, 0.0f, g_pWRTES->GetParentWorldSpace()->UpdateTESState());
    WRPlane kPlaneTmp(kNormal, kPoint);
    WRCullScene(apCamera, kPlaneTmp, g_spWaterReflectNode);

    if (!g_spWaterAccumulator)
        g_spWaterAccumulator = new WRAccumulator(0x63, 1, 0x2f7);
    g_spWaterAccumulator->SetRenderScene(WRGetScene(0));
    g_spWaterAccumulator->FUN_004ea860(true);
    g_spWaterAccumulator->SetCullingNode(g_spWaterReflectNode);
    g_spWaterAccumulator->SetAccumulate(true);

    g_kWaterListA.RemoveAll();
    g_kWaterListB.RemoveAll();
    g_kWaterListA.AddTail(g_pWRTES->GetProcess()->GetRoot());

    WRGetRenderer()->RenderReflections(g_spWaterReflectNode, 0, 0, &g_kWaterListA, &g_kWaterListB, g_spWaterAccumulator,
                                       4, g_iWaterFrame + 1, 0);
    WRGetRenderer()->SetFrame(0, g_iWaterFrame + 1);
}

namespace fnv_004eb220 {
struct WaterPassTexture : WaterRenderedTexture
{
    void* FUN_004a0d10();
};
struct WaterTextureRef
{
    WaterPassTexture* object;
    operator WaterPassTexture*() const;
    WaterTextureRef& operator=(WaterPassTexture*);
};
struct PlaneEquation
{
    float x, y, z, constant;
    const NiPoint3& FUN_006815c0() const;
    float FUN_0084d030(int) const;
};
struct WaterPass
{
    unsigned int unk00;
    PlaneEquation plane;
    unsigned int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    unsigned int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    WaterTextureRef texture;
    unsigned int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74;
    unsigned int unk78, unk7c, unk80, unk84, unk88, unk8c, unk90;
    WaterTextureRef scene;
    unsigned int unk98;
    unsigned int index;
    unsigned int unka0;
    WaterTextureRef target;
};
struct WaterPassRenderer : NiRenderer
{
    void FUN_004a0dd0(void*);
    void SetFromCamera(WaterPassTexture*);
};
struct WaterPassTES
{
    void* FUN_005f36f0();
};
struct WaterPassThread
{
    void FUN_00ba3130(int, unsigned int);
};
WaterPassThread* FUN_004ea970();
void FUN_00b6c0d0(WaterPassTexture*, WaterPassTexture*, int);
struct WaterPassOwner
{
    void FUN_004ecef0(WaterColorParam);
    void FUN_004eb220(WaterPass* pass);
};
// @fnv 0x004eb220
void WaterPassOwner::FUN_004eb220(WaterPass* pass)
{
    AutoMemContext clear(MC_Water, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                         0x1082);
    if (!FUN_004e2160() || !pass->target)
        return;
    WaterColorParam saved(0.0f, 0.0f, 0.0f, 0.0f);
    GetWaterRenderer()->GetBackgroundColor(saved);
    WaterColorParam context = saved;
    context.a = 0.0f;
    GetWaterRenderer()->SetBackgroundColor(context);
    if (!pass->texture)
        pass->texture =
            static_cast<WaterPassTexture*>(GetWaterTextureManager()->CreateTexture(GetWaterRenderer(), 9, 0, 0, 0));
    unsigned char enabled = FUN_006fd150();
    if (!reinterpret_cast<WaterPassTES*>(g_TES)->FUN_005f36f0() && enabled)
        FUN_006fd1c0();
    SetRenderTargetGroup(7, static_cast<WaterPassTexture*>(pass->texture)->GetGroup());
    static_cast<WaterPassRenderer*>(FUN_0043c4b0())
        ->FUN_004a0dd0(static_cast<WaterPassTexture*>(pass->target)->FUN_004a0d10());
    FUN_004ea970()->FUN_00ba3130(1, pass->index + 1);
    static_cast<WaterPassRenderer*>(FUN_0043c4b0())->SetFromCamera(pass->target);
    FUN_004ecef0(WaterColorParam(pass->plane.FUN_006815c0().x, pass->plane.FUN_006815c0().y,
                                 pass->plane.FUN_006815c0().z, -pass->plane.FUN_0084d030(0)));
    UpdateSpawnedObjectFlags(1, 0, 0, 0, 0, 0, 0);
    FUN_00b6c0d0(pass->target, pass->scene, 0);
    FUN_004eb510(0);
    ClearRenderTarget();
    if (!reinterpret_cast<WaterPassTES*>(g_TES)->FUN_005f36f0() && enabled)
        FUN_006fd1e0();
    GetWaterRenderer()->SetBackgroundColor(saved);
    pass->target = 0;
}
}  // namespace fnv_004eb220

struct Color197
{
    float r, g, b, a;
    Color197(float, float, float, float);
};
struct Renderer197
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
    virtual void SetColor(const Color197&);
    virtual void v44();
    virtual void GetColor(Color197&);
};
Renderer197* FUN_004a0e90();
struct Texture197
{
    void* FUN_00b6b260();
    void* FUN_004a0d10();
};
struct Handle197
{
    Texture197* FUN_00559450();
    void FUN_0066b0d0(Texture197*);
};
extern Handle197 g_011c7b44, g_011c7ad4, g_011c7cb8;
struct Bool197
{
    bool* FUN_00408d60();
};
extern Bool197 g_011c7c00, g_011c7c48;
struct Uint197
{
    unsigned int* FUN_0043d4d0();
};
extern Uint197 g_011c7c1c;
struct Manager197
{
    Texture197* FUN_00b6e110(Renderer197*, int, int, int, int);
    void FUN_00b6da10(Texture197*);
};
Manager197* __stdcall FUN_004a0ea0();
struct Node197
{
    void FUN_00450f90();
};
struct Actor197
{
    virtual void actor0();
    virtual void actor1();
    virtual void actor2();
    virtual void actor3();
    virtual void actor4();
    virtual void actor5();
    virtual void actor6();
    virtual void actor7();
    virtual void actor8();
    virtual void actor9();
    virtual void actor10();
    virtual void actor11();
    virtual void actor12();
    virtual void actor13();
    virtual void actor14();
    virtual void actor15();
    virtual void actor16();
    virtual void actor17();
    virtual void actor18();
    virtual void actor19();
    virtual void actor20();
    virtual void actor21();
    virtual void actor22();
    virtual void actor23();
    virtual void actor24();
    virtual void actor25();
    virtual void actor26();
    virtual void actor27();
    virtual void actor28();
    virtual void actor29();
    virtual void actor30();
    virtual void actor31();
    virtual void actor32();
    virtual void actor33();
    virtual void actor34();
    virtual void actor35();
    virtual void actor36();
    virtual void actor37();
    virtual void actor38();
    virtual void actor39();
    virtual void actor40();
    virtual void actor41();
    virtual void actor42();
    virtual void actor43();
    virtual void actor44();
    virtual void actor45();
    virtual void actor46();
    virtual void actor47();
    virtual void actor48();
    virtual void actor49();
    virtual void actor50();
    virtual void actor51();
    virtual void actor52();
    virtual void actor53();
    virtual void actor54();
    virtual void actor55();
    virtual void actor56();
    virtual void actor57();
    virtual void actor58();
    virtual void actor59();
    virtual void actor60();
    virtual void actor61();
    virtual void actor62();
    virtual void actor63();
    virtual void actor64();
    virtual void actor65();
    virtual void actor66();
    virtual void actor67();
    virtual void actor68();
    virtual void actor69();
    virtual void actor70();
    virtual void actor71();
    virtual void actor72();
    virtual void actor73();
    virtual void actor74();
    virtual void actor75();
    virtual void actor76();
    virtual void actor77();
    virtual void actor78();
    virtual void actor79();
    virtual void actor80();
    virtual void actor81();
    virtual void actor82();
    virtual void actor83();
    virtual void actor84();
    virtual void actor85();
    virtual void actor86();
    virtual void actor87();
    virtual void actor88();
    virtual void actor89();
    virtual void actor90();
    virtual void actor91();
    virtual void actor92();
    virtual void actor93();
    virtual void actor94();
    virtual void actor95();
    virtual void actor96();
    virtual void actor97();
    virtual void actor98();
    virtual void actor99();
    virtual void actor100();
    virtual void actor101();
    virtual void actor102();
    virtual void actor103();
    virtual void actor104();
    virtual void actor105();
    virtual void actor106();
    virtual void actor107();
    virtual void actor108();
    virtual void actor109();
    virtual void actor110();
    virtual void actor111();
    virtual void actor112();
    virtual void actor113();
    virtual void actor114();
    virtual void actor115();
    virtual Node197* GetNode(int);
    bool FUN_004eaf60();
};
extern Actor197* g_011dea3c;
struct RendererOps197
{
    void FUN_004a0dd0(void*);
    void SetFromCamera(Texture197*);
};
struct Height197
{
    float FUN_0045cd80();
};
struct Player197
{
    int FUN_005f36f0();
    Height197* FUN_004fd3e0();
};
struct System197
{
    void FUN_00ba3130(int, int);
};
System197* FUN_004ea970();
extern int g_011c7a6c;
void FUN_00b6b8d0(int, void*);
void FUN_00b6c0d0(Texture197*, Texture197*, int);
void FUN_00b6b790();
struct Plane197
{
    NiPoint3 clearColor;
    float constant;
    Plane197(const NiPoint3&, const NiPoint3&);
    float FUN_0084d030(int) const;
    const NiPoint3& FUN_006815c0() const;
};
struct Param197
{
    unsigned int a, b, c, d;
    Param197();
    ~Param197();
    void FUN_00ba37a0(Texture197*);
};
struct EffectParam197
{
    unsigned int a, b, c, d, e, f, g, h, i;
    EffectParam197();
    ~EffectParam197();
};
struct Effect197
{
    void SetAccumulatorAt(unsigned int, Param197*, int);
};
struct Effects197
{
    Effect197* FUN_004ebbc0(int);
    void FUN_00b97550(unsigned int, Renderer197*, Texture197*, Texture197*, EffectParam197*, bool);
};
Effects197* FUN_004e3270();
extern float DAT_012003c4;
struct Water197
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
    bool enabled;
    void FUN_004ecef0(Color197);
    void UpdateWaterRendering();
};
// @fnv 0x004eb540
void Water197::UpdateWaterRendering()
{
    AutoMemContext normal(MC_Water, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                          0x10b8);
    if (!FUN_004e2160() || !g_011c7b44.FUN_00559450())
        return;
    Color197 oldColor(0.0f, 0.0f, 0.0f, 0.0f);
    FUN_004a0e90()->GetColor(oldColor);
    Color197 plane = oldColor;
    plane.a = 0.0f;
    FUN_004a0e90()->SetColor(plane);
    if (!g_011c7ad4.FUN_00559450())
        g_011c7ad4.FUN_0066b0d0(FUN_004a0ea0()->FUN_00b6e110(FUN_004a0e90(), 9, 0, 0, 0));
    bool memory = (unsigned char)FUN_006fd150() && !*g_011c7c00.FUN_00408d60();
    if (!((Player197*)DAT_011dea10)->FUN_005f36f0() && memory)
        FUN_006fd1c0();
    FUN_00b6b8d0(7, g_011c7ad4.FUN_00559450()->FUN_00b6b260());
    ((RendererOps197*)FUN_0043c4b0())->FUN_004a0dd0(g_011c7b44.FUN_00559450()->FUN_004a0d10());
    FUN_004ea970()->FUN_00ba3130(1, g_011c7a6c + 1);
    if (enabled && g_011dea3c->FUN_004eaf60())
        ((Node197*)g_011dea3c->GetNode(0))->FUN_00450f90();
    NiPoint3 clearColor(0.0f, 0.0f, 1.0f);
    NiPoint3 point(0.0f, 0.0f, ((Player197*)DAT_011dea10)->FUN_004fd3e0()->FUN_0045cd80());
    Plane197 toggle(clearColor, point);
    ((RendererOps197*)FUN_0043c4b0())->SetFromCamera(g_011c7b44.FUN_00559450());
    FUN_004ecef0(
        Color197(toggle.FUN_006815c0().x, toggle.FUN_006815c0().y, toggle.FUN_006815c0().z, -toggle.FUN_0084d030(0)));
    UpdateSpawnedObjectFlags(1, 0, 0, 0, 0, 0, 0);
    FUN_00b6c0d0(g_011c7b44.FUN_00559450(), g_011c7cb8.FUN_00559450(), 0);
    FUN_004eb510(0);
    FUN_00b6b790();
    if (!((Player197*)DAT_011dea10)->FUN_005f36f0() && memory)
        FUN_006fd1e0();
    FUN_004a0e90()->SetColor(oldColor);
    g_011c7b44.FUN_0066b0d0(0);
    if (*g_011c7c48.FUN_00408d60())
    {
        Texture197* index = FUN_004a0ea0()->FUN_00b6e110(FUN_004a0e90(), 22, 0, 0, 0);
        Param197 texture;
        texture.FUN_00ba37a0(index);
        EffectParam197 effectParam;
        DAT_012003c4 = *g_011c7c1c.FUN_0043d4d0() + 1.0;
        unsigned int param = *g_011c7c1c.FUN_0043d4d0();
        unsigned int uiEffectIndex = param + 16;
        FUN_004e3270()->FUN_004ebbc0(uiEffectIndex)->SetAccumulatorAt(2, &texture, 0);
        FUN_004e3270()->FUN_00b97550(uiEffectIndex, FUN_004a0e90(), g_011c7ad4.FUN_00559450(),
                                     g_011c7ad4.FUN_00559450(), &effectParam, true);
        FUN_004a0ea0()->FUN_00b6da10(index);
    }
}

struct TextureOps
{
    void* GetGroup();
    void* GetData();
};
struct PtrWater
{
    TextureOps* Resolve();
    PtrWater& Assign(TextureOps*);
};
extern PtrWater waterSource, waterTarget, waterOther;
struct TesOps
{
    void* Interior();
    struct WorldOps* World();
};
struct WorldOps
{
    float Height() const;
};
extern TesOps* waterTes;
extern int waterFrame;
struct RenderOps
{
    virtual void slot0();
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();

    virtual void SetColor(const WaterColorParam&);
    virtual void slot44();
    virtual void GetColor(WaterColorParam&);
    void SetData(void*);
    void SetTexture(TextureOps*);
};
RenderOps* RendererWater();
struct ManagerWater
{
    TextureOps* Create(RenderOps*, int, int, int, int);
};
ManagerWater* __stdcall ManagerWaterGet();
struct ThreadWater
{
    void Setup(int, int);
};
ThreadWater* ThreadWaterGet();
bool FUN_004e2160();
char FUN_006fd150();
void FUN_006fd1c0();
void FUN_006fd1e0();
void TargetWater(unsigned, void*);
void DrawWater(int, int, int, int, int, int, int);
void CopyWater(TextureOps*, TextureOps*, int);
void FUN_004eb510(int);
void EndWater();
struct PlaneWater : NiPlane
{
    const NiPoint3& Normal() const;
};
struct WaterPass
{
    void SetWaterColorParameter(WaterColorParam, int);
    void FUN_004ebbe0();
};
// Saves the renderer color, creates the water target if missing, sets water data and texture, draws and copies the water, then restores the color.
// @fnv 0x004ebbe0
void WaterPass::FUN_004ebbe0()
{
    AutoMemContext context2(MC_Water, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                            0x1114);
    if (!FUN_004e2160() || !waterSource.Resolve())
        return;
    WaterColorParam oldColor(0, 0, 0, 0);
    RendererWater()->GetColor(oldColor);
    WaterColorParam newColor3 = oldColor;
    newColor3.a = 0;
    RendererWater()->SetColor(newColor3);
    if (!waterTarget.Resolve())
        waterTarget.Assign(ManagerWaterGet()->Create(RendererWater(), 9, 0, 0, 0));
    unsigned char enabled2 = FUN_006fd150();
    if (!waterTes->Interior() && enabled2)
        FUN_006fd1c0();
    TargetWater(7, waterTarget.Resolve()->GetGroup());
    ((RenderOps*)FUN_0043c4b0())->SetData(waterSource.Resolve()->GetData());
    ThreadWaterGet()->Setup(1, waterFrame + 1);
    NiPoint3 normal(0, 0, 1);
    NiPoint3 point(0, 0, waterTes->World()->Height());
    NiPlane plane(normal, point);
    ((RenderOps*)FUN_0043c4b0())->SetTexture(waterSource.Resolve());
    SetWaterColorParameter(WaterColorParam(((PlaneWater&)plane).Normal().x, ((PlaneWater&)plane).Normal().y,
                                           ((PlaneWater&)plane).Normal().z, -plane.FUN_0084d030()),
                           0);
    DrawWater(1, 0, 0, 0, 0, 0, 0);
    CopyWater(waterSource.Resolve(), waterOther.Resolve(), 0);
    FUN_004eb510(0);
    EndWater();
    if (!waterTes->Interior() && enabled2)
        FUN_006fd1e0();
    RendererWater()->SetColor(oldColor);
    waterSource.Assign(0);
}

namespace fnv_004ebef0 {
struct CellFlag074
{
    bool FUN_00450ff0();
};
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct Update074
{
    float time;
    bool controllers;
    bool threading;
    int frame;
    void FUN_0043d410(float, bool, bool);
};
struct Camera074
{
    void* FUN_0045bb80();
    void* FUN_00461130();
    float FUN_008d01e0();
    float GetMaxFarNearRatio() const;
    void* GetViewFrustum() const;
};
struct FUN_00a712f0 : NiMemObject
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
    FUN_00a712f0();
    void FUN_00440460(void*);
    void FUN_0043fa80(void*);
    void FUN_00440490(float);
    void FUN_00507700(float);
    void FUN_00a6faf0(void*);
    void FUN_00a59c60(Update074&);
    void* FUN_00a59d30(int);
};
struct BSShaderAccumulator : NiMemObject
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
    virtual void Attach(FUN_00a712f0*);
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
    BSShaderAccumulator(int, unsigned int, unsigned int);
    void FUN_004a1020(void*);
    void FUN_004ec7c0(bool);
    void SetAccumulate(bool);
};
struct Ref074
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual FUN_00a712f0* Get3D();
    void* FUN_008d6f30();
    void* FUN_007af430();
    struct Extra074* FUN_005d43c0();
};
struct Cell074
{
    FUN_00a712f0* GetCellNodeAt(unsigned int);
};
struct Extra074
{
    struct Link074* FUN_0041f140();
};
struct LinkData074
{
    Ref074* ref;
    unsigned int flags;
};
struct Link074
{
    bool FUN_008256d0();
    LinkData074** FUN_006815c0();
    Link074* FUN_00726070();
};
struct List074
{
    void* FUN_00559450();
    Ref074*& FUN_0057cbe0(void*&);
    void* DereferenceIfNotNull(void*);
    Ref074*& AddEight(void*);
    int unk00, unk04, unk08;
};
struct PtrFUN_00a712f0
{
    FUN_00a712f0* p;
    FUN_00a712f0* FUN_00559450();
    void FUN_0066b0d0(FUN_00a712f0*);
    void FUN_006e5cc0(PtrFUN_00a712f0&);
};
struct PtrBSShaderAccumulator
{
    BSShaderAccumulator* p;
    BSShaderAccumulator* FUN_00559450();
    void FUN_0066b0d0(BSShaderAccumulator*);
};
struct Array074
{
    int unk00, unk04, unk08;
    void FUN_0076b660(void* const&);
};
struct Map074
{
    int unk00, unk04, unk08, unk0c;
    bool GetAt(Ref074*, Ref074*&);
    void FUN_00844700(Ref074*, Ref074*);
};
struct Property074
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
    PtrFUN_00a712f0 object;
};
struct State074
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
    List074 refs;
    List074 otherRefs;
    List074 actors;
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
    Array074 nodes;
    Array074 actorNodes;
    int unk94;
    PtrBSShaderAccumulator accumulator;
    int unk9c;
    int count;
    int unka4;
    PtrFUN_00a712f0 camera;
};
struct Render074
{
    void FUN_00ba3390(FUN_00a712f0*, int, int, Array074*, Array074*, BSShaderAccumulator*, int, int, int);
    void FUN_00ba30f0(int, int);
};
struct Texture074
{
    FUN_00a712f0* FUN_00b6e110(int, int, int, int);
};
struct Setting074
{
    unsigned int* FUN_0043d4d0();
};
struct Grid074
{
    Cell074** FUN_00457050(unsigned int, unsigned int);
};
struct Object074
{
    bool FUN_004e32e0();
    bool FUN_004e32a0();
    bool FUN_004ec7e0();
    bool FUN_00452440();
};
struct Player074
{
    bool FUN_004eaf60();
};
extern char DAT_0102301c[];
extern PtrFUN_00a712f0 DAT_011c7b68;

extern Player074* DAT_011dea3c;

void* __cdecl FUN_00450b80(int);
void* __cdecl FUN_004a0e90();
Texture074* __stdcall FUN_004a0ea0(void*);
Render074* FUN_004ea970();
struct Owner074
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
    Map074 seen;
    FUN_00a712f0* FUN_004e8030(Ref074*);
    bool FUN_004e62e0(Ref074*, Camera074*);
    void RenderWaterRefs(Camera074*, State074*);
};
// @fnv 0x004ebef0
void Owner074::RenderWaterRefs(Camera074* camera, State074* state)
{
    void* position;
    {
        AutoMemContext memory(MC_Water, true, DAT_0102301c, 0x114f);
        {
            bool didGrid;
            bool didActors;
            {
                Update074 update;
                if (!FUN_004e2160() || !camera)
                    return;
                state->camera.FUN_0066b0d0(new FUN_00a712f0);
                state->camera.FUN_00559450()->FUN_00440460(camera->FUN_0045bb80());
                state->camera.FUN_00559450()->FUN_0043fa80(camera->FUN_00461130());
                state->camera.FUN_00559450()->FUN_00440490(camera->FUN_008d01e0());
                state->camera.FUN_00559450()->FUN_00507700(camera->GetMaxFarNearRatio());
                state->camera.FUN_00559450()->FUN_00a6faf0(camera->GetViewFrustum());
                update.FUN_0043d410(0.0f, false, false);
                state->camera.FUN_00559450()->FUN_00a59c60(update);
                if (!state->accumulator.FUN_00559450())
                    state->accumulator.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
                state->accumulator.FUN_00559450()->FUN_004a1020(FUN_00450b80(0));
                state->accumulator.FUN_00559450()->FUN_004ec7c0(true);
                state->accumulator.FUN_00559450()->Attach(state->camera.FUN_00559450());
                state->accumulator.FUN_00559450()->SetAccumulate(true);
                if (!DAT_011c7b68.FUN_00559450())
                    DAT_011c7b68.FUN_0066b0d0(FUN_004a0ea0(FUN_004a0e90())->FUN_00b6e110(17, 0, 0, 0));
                didActors = false;
                didGrid = false;
                position = state->refs.FUN_00559450();
                while (position)
                {
                    Ref074* ref = state->refs.FUN_0057cbe0(position);
                    if (ref && ref->FUN_008d6f30() && ((CellFlag074*)ref->FUN_008d6f30())->FUN_00450ff0())
                    {
                        FUN_00a712f0* node = FUN_004e8030(ref);
                        Property074* property = 0;
                        if (node)
                        {
                            void* found = node->FUN_00a59d30(3);
                            property = (Property074*)found;
                        }
                        if (property && FUN_004e62e0(ref, camera))
                        {
                            property->object.FUN_006e5cc0(DAT_011c7b68);
                            Object074* object = (Object074*)ref->FUN_007af430();
                            if (object->FUN_004e32e0())
                            {
                                if (object && object->FUN_004e32a0() && !didActors)
                                {
                                    didActors = true;
                                    for (unsigned int x = 0; x < *((Setting074*)&DAT_011c63cc)->FUN_0043d4d0(); x++)
                                    {
                                        for (unsigned int y = 0; y < *((Setting074*)&DAT_011c63cc)->FUN_0043d4d0(); y++)
                                        {
                                            Cell074** value = ((Grid074*)DAT_011dea10)->FUN_00457050(x, y);
                                            Cell074* cell = *value;
                                            if (cell)
                                            {
                                                for (int i = 0; i < 4; i++)
                                                {
                                                    FUN_00a712f0* child = (*value)->GetCellNodeAt(i);
                                                    state->nodes.FUN_0076b660(static_cast<void*>(child));
                                                }
                                            }
                                        }
                                    }
                                }
                                if (object && object->FUN_004ec7e0() && !didGrid)
                                {
                                    didGrid = true;
                                    void* nextActor = state->actors.FUN_00559450();
                                    void* actorPos = 0;
                                    while (nextActor)
                                    {
                                        actorPos = state->actors.DereferenceIfNotNull(nextActor);
                                        Ref074* actor = state->actors.AddEight(nextActor);
                                        if ((actor != (Ref074*)DAT_011dea3c ||
                                             (actor == (Ref074*)DAT_011dea3c && DAT_011dea3c->FUN_004eaf60())) &&
                                            actor->Get3D() && !seen.GetAt(actor, actor))
                                        {
                                            state->actorNodes.FUN_0076b660(actor->Get3D());
                                            seen.FUN_00844700(actor, actor);
                                        }
                                        nextActor = actorPos;
                                    }
                                }
                                Link074* link = ref->FUN_005d43c0()->FUN_0041f140();
                                while (link && !link->FUN_008256d0())
                                {
                                    if ((*link->FUN_006815c0())->flags & 2)
                                    {
                                        Ref074* linked = (*link->FUN_006815c0())->ref;
                                        if (linked->Get3D() && !seen.GetAt(linked, linked))
                                        {
                                            state->nodes.FUN_0076b660(linked->Get3D());
                                            seen.FUN_00844700(linked, linked);
                                        }
                                    }
                                    link = link->FUN_00726070();
                                }
                                void* otherPos;
                                void* otherNext;
                                otherNext = state->otherRefs.FUN_00559450();
                                otherPos = 0;
                                while (otherNext)
                                {
                                    otherPos = state->refs.DereferenceIfNotNull(otherNext);
                                    if (otherNext)
                                    {
                                        Ref074* other = state->otherRefs.AddEight(otherNext);
                                        if (other->Get3D() && !seen.GetAt(other, other))
                                        {
                                            state->actorNodes.FUN_0076b660(other->Get3D());
                                            seen.FUN_00844700(other, other);
                                        }
                                    }
                                    otherNext = otherPos;
                                }
                                if (object && object->FUN_00452440())
                                {
                                    Link074* special = (Link074*)FUN_004ec7b0();
                                    while (special && !special->FUN_008256d0())
                                    {
                                        Ref074* entry = (Ref074*)*special->FUN_006815c0();
                                        if (entry && entry->Get3D() && !seen.GetAt(entry, entry))
                                        {
                                            state->nodes.FUN_0076b660(entry->Get3D());
                                            seen.FUN_00844700(entry, entry);
                                        }
                                        special = special->FUN_00726070();
                                    }
                                }
                            }
                        }
                    }
                }
                FUN_004ea970()->FUN_00ba3390(state->camera.FUN_00559450(), 0, 0, &state->nodes, &state->actorNodes,
                                             state->accumulator.FUN_00559450(), 0, state->count + 1, 0);
                FUN_004ea970()->FUN_00ba30f0(0, state->count + 1);
            }
        }
    }
}
}  // namespace fnv_004ebef0

namespace fnv_004ec800 {
struct Vec
{
    float x, y, z;
};
struct Plane
{
    Vec normal;
    float constant;
    float Distance() const;
    const Vec& Normal() const;
};
struct Camera
{
    float Width();
    float Height();
};
struct Texture
{
    void* Group();
};
struct SmartTexture
{
    Texture* object;
    operator Texture*() const;
    SmartTexture& operator=(Texture*);
};
struct Accum
{
    void Set(int);
};
struct SmartAccum
{
    Accum* object;
    operator Accum*() const;
};
struct WaterPass
{
    Camera* camera;
    Plane reflect;
    Plane refract;
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
    SmartAccum accumulator;
    int unk9c;
    int count;
    int unka4;
    SmartTexture target;
};
struct Renderer
{
    void UseGroup(void*);
    void UseTexture(Texture*);
};
struct RenderHelper
{
    void Setup(int, int);
};
struct Setting
{
    float* Float();
};
extern Setting g_011c7c10;
extern NiPoint2 DAT_011f9614;
extern Plane DAT_011f9604;
bool FUN_004e2160();
Renderer* GetPassRenderer();
RenderHelper* FUN_004ea970();
void UpdateRendererStateCount(int, int);
void FUN_00b98180(int, int, int, int);
void FUN_00b980c0(int, int, int, int);
void AddToSlot(int, int);
void UpdateSpawnedObjectFlags(int, int, int, int, int, int, int);
void CopyTexture(Texture*, Accum*, int);
void FUN_004eb510(int);
struct Device
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
    virtual void State(int, int, int, int);
};
struct DeviceSource
{
    Device* DevicePtr();
};
struct DeviceManager
{
    DeviceSource* Source();
};
DeviceSource* FUN_004a0e90();
void FUN_004ecb40(int);
void FUN_004ecb10(int);
struct WaterSetup
{
    void Apply(WaterColorParam, int);
    void FUN_004ec800(WaterPass*, unsigned short);
};
// Sets up the renderer for a water pass, applies reflection/refraction planes and color, copies the target texture into the accumulator, and resets state.
// @fnv 0x004ec800
void WaterSetup::FUN_004ec800(WaterPass* pass, unsigned short flags)
{
    AutoMemContext context(MC_Water, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESWater.cpp",
                           0x1209);
    if (!FUN_004e2160() || !(Texture*)pass->target)
        return;
    GetPassRenderer()->UseGroup(((Texture*)pass->target)->Group());
    FUN_004ea970()->Setup(1, pass->count + 1);
    GetPassRenderer()->UseTexture(pass->target);
    DAT_011f9614 = NiPoint2(pass->camera->Width(), pass->camera->Height());
    ((Accum*)pass->accumulator)->Set(14);
    UpdateRendererStateCount(1, 1);
    FUN_00b98180(2, 255, flags, 1);
    FUN_00b980c0(0, 0, 0, 1);
    AddToSlot(0, 1);
    GetPassRenderer()->UseTexture(pass->target);
    DAT_011f9604 = pass->reflect;
    Apply(WaterColorParam(pass->refract.Normal().x, pass->refract.Normal().y, pass->refract.Normal().z,
                          -pass->refract.Distance() + *g_011c7c10.Float()),
          0);
    UpdateSpawnedObjectFlags(1, 0, 0, 0, 0, 0, 0);
    CopyTexture(pass->target, pass->accumulator, 0);
    FUN_004eb510(0);
    FUN_004a0e90()->DevicePtr()->State(0x98, 0, 0, 0);
    FUN_004ecb40(1);
    FUN_004ecb10(10);
    FUN_004ecb10(11);
    FUN_004ecb10(12);
    pass->target = 0;
}
}  // namespace fnv_004ec800

namespace fnv_004ecb60 {
struct NiFrustum;
struct NiUpdateData
{
    float time;
    bool updateControllers, multithreaded;
    unsigned int flags;
    NiUpdateData(float, bool, bool);
};
struct NiCamera
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
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(const ThreeByThreeMatrix*);
    void FUN_00440490(float);
    void* FUN_004a0d10();
    void FUN_00507700(float);
    void FUN_00a6faf0(const NiFrustum&);
    void Update(const NiUpdateData&);
    const NiPoint3& FUN_0045bb80() const;
    const ThreeByThreeMatrix& FUN_00461130() const;
    float FUN_008d01e0() const;
    float GetMaxFarNearRatio() const;
    const NiFrustum& GetViewFrustum() const;
    void FUN_00a6fae0();
};
struct FUN_00a712f0 : NiCamera
{
    FUN_00a712f0();
    ~FUN_00a712f0();
};
struct NiVisibleArray;
struct FUN_004a0eb0
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
    FUN_004a0eb0(NiVisibleArray*);
    void FUN_0041fd00(NiCamera*);
    void FUN_00a694a0(const NiFrustum&);
    void FUN_004a0f60();
    ~FUN_004a0eb0();
};
struct WaterPassRenderer
{
    void FUN_004a0dd0(void*);
    void SetFromCamera(NiCamera*);
};

extern bool DAT_011ff375;
void FUN_00b98380(int, int);
struct WaterRenderData
{
    unsigned int unk00;
    unsigned short count;
};
struct WaterGeometryData
{
    int FUN_008d8520();
};
struct WaterGeometry : SceneObject
{
    WaterGeometryData* FUN_004030b0();
};
struct WaterProperty : Property
{
    WaterRenderData* FUN_00b69f30(WaterGeometry*);
};
void FUN_00b994f0(void*, unsigned short, int, int, int);
struct WaterPass : Worker
{
    bool FUN_004e62e0(Reference*, NiCamera*);
    void RenderWaterGroup(NiCamera*, WaterSurface*, int, unsigned short);
};
// Builds a temporary camera from camera, renders the water pass, then iterates group's references and renders water geometry with the given index.
// @fnv 0x004ecb60
void WaterPass::RenderWaterGroup(NiCamera* camera, WaterSurface* group, int unused, unsigned short index)
{
    if (!FUN_004e2160() || !camera)
        return;
    DAT_011ff375 = true;
    FUN_00b98380(0, 1);
    FUN_00a712f0 h;
    h.FUN_00440460(camera->FUN_0045bb80());
    h.FUN_0043fa80(&camera->FUN_00461130());
    h.FUN_00440490(camera->FUN_008d01e0());
    reinterpret_cast<WaterPassRenderer*>(FUN_0043c4b0())->FUN_004a0dd0(h.FUN_004a0d10());
    h.FUN_00507700(camera->GetMaxFarNearRatio());
    h.FUN_00a6faf0(camera->GetViewFrustum());
    NiUpdateData s(0.0f, false, false);
    h.Update(s);
    FUN_004a0eb0 p(0);
    p.FUN_0041fd00(&h);
    reinterpret_cast<WaterPassRenderer*>(FUN_0043c4b0())->SetFromCamera(&h);
    p.FUN_00a694a0(h.GetViewFrustum());
    void* a = group->m_kWaterReferences.GetHeadPos();
    void* i = 0;
    while (a)
    {
        i = group->m_kWaterReferences.DereferenceIfNotNull(a);
        if (a)
        {
            Reference* reference = reinterpret_cast<Reference*>(group->m_kWaterReferences.AddEight(a));
            if (reference && reference->FUN_008d6f30() && reference->FUN_008d6f30()->FUN_00450ff0())
            {
                SceneObject* object = FUN_004e8030(reference);
                if (object)
                {
                    WaterGeometry* geometry = static_cast<WaterGeometry*>(object);
                    WaterGeometryData* data = geometry->FUN_004030b0();
                    if (data && data->FUN_008d8520() == 13)
                    {
                        Property* property = object->FUN_00a59d30(3);
                        WaterProperty* waterProperty = static_cast<WaterProperty*>(property);
                        waterProperty->unk84 = index;
                        if (FUN_004e62e0(reference, camera) && waterProperty && waterProperty->FUN_00b69f30(geometry))
                        {
                            WaterRenderData* renderData = waterProperty->FUN_00b69f30(geometry);
                            FUN_00b994f0(renderData, renderData->count, 0, 0, 0);
                        }
                    }
                }
            }
        }
        a = i;
    }
    p.FUN_0041fd00(0);
    FUN_004eced0(1);
    DAT_011ff375 = false;
}
}  // namespace fnv_004ecb60

class FUN_0042f1d0_shell
{
  public:
    void* FUN_0042f1d0();
};

extern FUN_0042f1d0_shell* __fastcall FUN_005d43c0(TESObjectREFR* a1);

template <class KEY, class VALUE> class NiTPointerMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, KEY&, VALUE&);
    bool GetAt(KEY, VALUE&) const;
};

class XL
{
  public:
    void* RemovePos(void*&);
};

class SoundH
{
  public:
    unsigned int Deallocate();
};

class NiTMap_S
{
  public:
    bool RemoveKey(unsigned int);
};

extern bool __fastcall FUN_0057b200(TESObjectREFR*);

class Helper57b240
{
  public:
    void FUN_0057b240(int);
};

class TESObjectREFR_Water
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool HasWater();
};

class TESWaterSystem_Impl : public WaterZoneManager
{
  public:
    void FUN_004e5fe0(TESObjectREFR* a1);
};

// @fnv 0x004e5fe0
void TESWaterSystem_Impl::FUN_004e5fe0(TESObjectREFR* apRef)
{
    NiTPointerMap<unsigned int, void*>* map = (NiTPointerMap<unsigned int, void*>*)FUN_005d43c0(apRef)->FUN_0042f1d0();
    {
        void* a;
        a = ((NiTPointerList<TESObjectREFR*>*)&m_kWaterZoneList)->GetHeadPos();
        void* n;
        n = 0;
        bool b;
        b = false;
        WaterSurface* kIter;
        kIter = 0;
        {
            while (a != 0 && !b)
            {
                n = ((NiTPointerList<TESObjectREFR*>*)&m_kWaterZoneList)->DereferenceIfNotNull(a);
                if (a)
                {
                    bool pObj;
                    pObj = true;
                    kIter = (WaterSurface*)((NiTPointerList<TESObjectREFR*>*)&m_kWaterZoneList)->AddEight(a);
                    if (map)
                    {
                        void* q;
                        q = map->GetFirstPos();
                        while (q)
                        {
                            unsigned int p;
                            void* subPos;
                            map->GetNext(q, p, subPos);
                            int s;
                            s = ((SoundH*)((char*)4 + p))->Deallocate();
                            void* i;
                            i = ((NiTPointerList<TESObjectREFR*>*)&kIter->m_kWaterReferences)->GetHeadPos();
                            void* res;
                            res = 0;
                            while (i)
                            {
                                res = ((NiTPointerList<TESObjectREFR*>*)&kIter->m_kWaterReferences)
                                          ->DereferenceIfNotNull(i);
                                if (i)
                                {
                                    TESObjectREFR* c;
                                    c = ((NiTPointerList<TESObjectREFR*>*)&kIter->m_kWaterReferences)->AddEight(i);
                                    if (c == (TESObjectREFR*)s)
                                    {
                                        pObj = false;
                                        break;
                                    }
                                    i = res;
                                }
                            }
                            if (pObj == 0)
                                break;
                        }
                        if (0 == pObj)
                            continue;
                    }
                    if (pObj)
                    {
                        void* nextPos;
                        if (((TESObjectREFR_Water*)apRef)->HasWater())
                            nextPos = ((NiTPointerList<TESObjectREFR*>*)((char*)kIter + 0x3c))->GetHeadPos();
                        else
                            nextPos = ((NiTPointerList<TESObjectREFR*>*)((char*)kIter + 0x30))->GetHeadPos();
                        void* ptr;
                        ptr = 0;
                        void* nextPos38;
                        nextPos38 = 0;
                        bool val;
                        val = false;
                        while (nextPos && !val)
                        {
                            if (((TESObjectREFR_Water*)apRef)->HasWater())
                                ptr = ((NiTPointerList<TESObjectREFR*>*)((char*)kIter + 0x3c))
                                          ->DereferenceIfNotNull(nextPos);
                            else
                                ptr = ((NiTPointerList<TESObjectREFR*>*)((char*)kIter + 0x30))
                                          ->DereferenceIfNotNull(nextPos);
                            if (nextPos)
                            {
                                TESObjectREFR* item44;
                                item44 = 0;
                                if (((TESObjectREFR_Water*)apRef)->HasWater())
                                    item44 =
                                        ((NiTPointerList<TESObjectREFR*>*)((char*)kIter + 0x3c))->AddEight(nextPos);
                                else
                                    item44 =
                                        ((NiTPointerList<TESObjectREFR*>*)((char*)kIter + 0x30))->AddEight(nextPos);
                                if (item44 == apRef)
                                {
                                    val = true;
                                    nextPos38 = nextPos;
                                }
                                nextPos = ptr;
                            }
                        }
                        if (val && nextPos38)
                        {
                            while (FUN_0057b200(apRef))
                            {
                                ((Helper57b240*)apRef)->FUN_0057b240(0);
                            }
                            if (((TESObjectREFR_Water*)apRef)->HasWater())
                            {
                                ((XL*)((char*)kIter + 0x3c))->RemovePos(nextPos38);
                                unsigned int z;
                                z = 0;
                                if (((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x7c))
                                        ->GetAt((unsigned int)apRef, z))
                                {
                                    ((NiTMap_S*)((char*)this + 0x7c))->RemoveKey((unsigned int)apRef);
                                }
                            }
                            else
                            {
                                ((XL*)((char*)kIter + 0x30))->RemovePos(nextPos38);
                            }
                        }
                    }
                    a = n;
                }
            }
        }
    }
}

namespace s4e5e50 {

class Ref;

struct RefNode;

struct RefList
{
    int unk00;
    int unk04;
    int unk08;

    RefNode* FUN_00559450();
    RefNode* DereferenceIfNotNull(RefNode* pkCurNode);
    Ref** AddEight(RefNode* pkCurNode);
    void FUN_0049f590(RefNode*& pkCurNode);
};

class Ref
{
  public:
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsActor();
};

struct Cell
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
    RefList m_kRefs;
    RefList m_kActors;
};

struct ReferenceIntegerMap
{
    bool GetAt(Ref* pkRef, int* piValue);
    void RemoveKey(Ref* pkRef);
};

struct Owner
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
    ReferenceIntegerMap m_kActorMap;

    void RemoveReferenceFromCell(Ref* pkRef, Cell* pkCell);
};

// Finds pkRef in pkCell's actor or reference list and removes it, also clearing its entry in m_kActorMap for actors.
// @fnv 0x004e5e50
void Owner::RemoveReferenceFromCell(Ref* pkRef, Cell* pkCell)
{
    RefNode* pkCurNode;
    if (pkRef->IsActor())
        pkCurNode = pkCell->m_kActors.FUN_00559450();
    else
        pkCurNode = pkCell->m_kRefs.FUN_00559450();
    RefNode* pkFollowing = 0;
    RefNode* pkMatch = 0;
    bool bFound = false;
    while (pkCurNode && !bFound)
    {
        if (pkRef->IsActor())
            pkFollowing = pkCell->m_kActors.DereferenceIfNotNull(pkCurNode);
        else
            pkFollowing = pkCell->m_kRefs.DereferenceIfNotNull(pkCurNode);
        if (pkCurNode)
        {
            Ref* pkItem = 0;
            if (pkRef->IsActor())
                pkItem = *pkCell->m_kActors.AddEight(pkCurNode);
            else
                pkItem = *pkCell->m_kRefs.AddEight(pkCurNode);
            if (pkItem == pkRef)
            {
                bFound = true;
                pkMatch = pkCurNode;
            }
            pkCurNode = pkFollowing;
        }
    }
    if (bFound && pkMatch)
    {
        if (pkRef->IsActor())
        {
            pkCell->m_kActors.FUN_0049f590(pkMatch);
            int iValue = 0;
            if (m_kActorMap.GetAt(pkRef, &iValue))
                m_kActorMap.RemoveKey(pkRef);
        }
        else
        {
            pkCell->m_kRefs.FUN_0049f590(pkMatch);
        }
    }
}

}

struct Big
{
    int m_data[9];
};

struct Holder
{
    char pad[0x44];
    Big m_big;
    Big* CopyBig(Big* out);
};

// Copies the m_big member into the out parameter and returns out.
// @fnv 0x004e75d0
Big* Holder::CopyBig(Big* out)
{
    *out = m_big;
    return out;
}

struct FUN_00414430
{
    float r, g, b, a;
    FUN_00414430(float, float, float, float);
};
struct WaterForm3590
{
    unsigned int FUN_004f9bf0();
    unsigned int FUN_009ee040();
    unsigned int FUN_008d80e0();
    float FUN_00644930();
    float FUN_008d01e0();
    float FUN_00580100();
    float GetField11C();
    float GetFloatAtOffset9C();
    float GetFloatAt120();
    float GetField124Float();
    float GetFloatAtOffset128();
    float GetFloatAtOffset12C();
    float GetFieldE4Float();
    float GetFieldDC();
    float FUN_00507b20();
    float FUN_004e3d00();
    float FUN_00508070();
    float FUN_009b88a0();
    float GetUnka4();
    float FUN_004e3ce0();
    float FUN_009442a0();
    float FUN_00644950();
    float FUN_00644970();
};
struct WaterMaterial125
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual unsigned short GetPassCount(int);
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
    unsigned char unk60, unk61, unk62;
    bool flag63;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    float distance74;
    float distance78;
    unsigned char unk7c, unk7d, unk7e;
    bool enabled;
    bool flag80, flag81, flag82, unk83;
    int unk84;
    FUN_00414430 color88, color98, colora8;
    float valueb8;
    float valuebc;
    float valuec0;
    float valuec4;
    float valuec8;
    float valuecc;
    float valued0;
    float valued4;
    float valued8;
    float valuedc;
    float valuee0;
    float valuee4;
    float valuee8;
    float valueec;
    float valuef0;
    float valuef4;
    float valuef8;
    float valuefc;
    float value100;
    float value104;
    float value108;
    float value10c;
    float value110;
    float value114;
    float value118;
    float value11c;
    float value120;
    float value124;
    void FUN_004e3c00();
};
struct Shader125
{
    int FUN_008d8520();
};
struct Scene125
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void* AsGeometry();
    Shader125* FUN_004030b0();
    WaterMaterial125* FUN_00a59d30(int);
};
struct Ref125
{
    TESBoundObject* FUN_007af430();
};
struct Base125 : TESBoundObject
{
    bool FUN_004e3c70();
    bool FUN_004e3c50();
    bool FUN_004e3280();
    bool FUN_004e32e0();
    bool FUN_004e3ca0();
};
struct Ptr125
{
    Scene125* FUN_00559450();
};
struct Parent125
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
    Ptr125 shader;
};
struct System125
{
    Scene125* FUN_004e8030(Ref125*);
    void FUN_004e3590(Parent125*, Ref125*);
};
extern float DAT_011ff108;
bool FUN_004e3c40();
extern SettingT<INISettingCollection> g_011c7b6c, g_011c7c60, g_011c7bbc;
// For geometry with shader result 13, copies water form properties into its enabled water material and updates related flags.
// @fnv 0x004e3590
void System125::FUN_004e3590(Parent125* parent, Ref125* reference)
{
    Scene125* geometry = FUN_004e8030(reference);
    if (geometry && geometry->AsGeometry())
    {
        Scene125* shader = geometry;
        Shader125* object = shader->FUN_004030b0();
        if (object && object->FUN_008d8520() == 13)
        {
            WaterMaterial125* property = geometry->FUN_00a59d30(3);
            WaterMaterial125* base = property;
            Base125* material = (Base125*)reference->FUN_007af430();
            WaterForm3590* water = reinterpret_cast<WaterForm3590*>(material->GetAssociatedWaterForm());
            if (base && water && base->enabled)
            {
                unsigned int color = water->FUN_004f9bf0();
                base->color88 = FUN_00414430((unsigned char)(color & 255) / 255.0,
                                             (unsigned char)(((unsigned short)color >> 8) & 255) / 255.0,
                                             (unsigned char)((color >> 16) & 255) / 255.0, 1.0f);
                color = water->FUN_009ee040();
                base->color98 = FUN_00414430((unsigned char)(color & 255) / 255.0,
                                             (unsigned char)(((unsigned short)color >> 8) & 255) / 255.0,
                                             (unsigned char)((color >> 16) & 255) / 255.0, 1.0f);
                color = water->FUN_008d80e0();
                base->colora8 = FUN_00414430((unsigned char)(color & 255) / 255.0,
                                             (unsigned char)(((unsigned short)color >> 8) & 255) / 255.0,
                                             (unsigned char)((color >> 16) & 255) / 255.0, 1.0f);
                base->valueb8 = water->FUN_00644930();
                base->valuebc = water->FUN_008d01e0();
                base->valuec0 = water->FUN_00580100();
                base->valuec4 = water->GetField11C();
                base->value118 = water->GetFloatAtOffset9C();
                base->value100 = water->GetFloatAt120();
                base->value104 = water->GetField124Float();
                base->valued0 = water->GetFloatAtOffset128();
                base->valued4 = water->GetFloatAtOffset12C();
                base->value11c = water->GetFieldE4Float();
                DAT_011ff108 = water->GetFieldDC();
                if (FUN_004e2180() || FUN_004e3c40())
                {
                    base->distance74 = water->FUN_00507b20();
                    base->distance78 = water->FUN_00507b20() - water->FUN_004e3d00();
                    if (material->FUN_004e3c70())
                        base->value120 = water->FUN_00508070();
                }
                else
                {
                    base->distance74 = water->FUN_009b88a0();
                    base->distance78 = water->FUN_009b88a0() - water->GetUnka4();
                    if (material->FUN_004e3c70())
                        base->value120 = water->FUN_004e3ce0();
                    else
                        base->value120 = 0.0f;
                }
                base->value124 = water->FUN_009442a0();
                {
                    bool flag81 = base->flag80;
                    bool flag63 = base->flag81;
                    bool flag80 = base->flag63;
                    base->flag80 = material->FUN_004e3c50() && g_011c7b6c.Bool()->b;
                    base->flag81 = material->FUN_004e3280() && g_011c7c60.Bool()->b;
                    base->flag63 = material->FUN_004e32e0() && g_011c7bbc.Bool()->b;
                    if (base->flag80 != flag81 || base->flag81 != flag63 || base->flag63 != flag80)
                    {
                        base->FUN_004e3c00();
                        if (parent->shader.FUN_00559450())
                        {
                            WaterMaterial125* nextMaterial = parent->shader.FUN_00559450()->FUN_00a59d30(3);
                            WaterMaterial125* nextProperty = nextMaterial;
                            if (nextProperty->GetPassCount(0) > 0)
                                nextProperty->FUN_004e3c00();
                        }
                    }
                }
                base->flag82 = material->FUN_004e3ca0();
                if (water->FUN_00644950() == water->FUN_00644970())
                {
                    base->valued8 = -1.0f;
                    base->valuedc = 0.0f;
                }
                else
                {
                    base->valued8 = water->FUN_00644950();
                    base->valuedc = water->FUN_00644970();
                }
            }
        }
    }
}
