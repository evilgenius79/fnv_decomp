// fallout/interface/interfacemanager.cpp: InterfaceManager, ConsoleManager, IFH, BSAudioManager and more (208 functions)

#include "interfacemanager_packet.h"
// @fnv 0x00714f70
int InterfaceManager::GetMenuStackEntry(int index)
{
    return enterStack[index];
}
// @fnv 0x008d8400
void MiddleHighProcess::SetRunOncePackageIndex(int aiCastingType)
{
    enchantable.SetCastingType((MagicSystem__CastingType)aiCastingType);
}
// @fnv 0x00713da0
void InterfaceManager::AddTileIfAbsent(Tile* tile)
{
    if (tile && !g_011d8b44.FUN_009962f0((TESIdleForm*&)tile))
        g_011d8b44.Add((TESIdleForm*&)tile);
}
// Multiplies both x and y of this NiPoint2 by scale and returns the resulting NiPoint2.
// @fnv 0x004a4f40
NiPoint2 NiPoint2::operator*(float scale) const
{
    NiPoint2 result = *this;
    result.x *= scale;
    result.y *= scale;
    return result;
}
// Counts the non-null items in the list by walking each node and incrementing a counter when GetItem returns a value.
// Counts the number of non-null items in the BSSimpleList by traversing from the head node to the end.
// @fnv 0x005ae380
template <> unsigned int BSSimpleList<EffectSetting*>::ItemsInList()
{
    struct Traversal
    {
        unsigned int count;
        BSSimpleList<BGSPerkEntry*>* node;
    } state;
    state.count = 0;
    state.node = (BSSimpleList<BGSPerkEntry*>*)this;
    while (state.node)
    {
        if (state.node->GetItem())
            ++state.count;
        state.node = state.node->GetNext();
    }
    return state.count;
}
// @fnv 0x00717de0
void InterfaceManager::SendGamepadButton(Interface::enumGamepadButtons button)
{
    if (FUN_004b71d0() && !((unsigned char*)FUN_004b7210())[0x7d])
    {
        InputManager* input = g_osGlobals->FUN_00877720();
        GAMEPAD_BUTTON converted = ConvertGamepadButton(button);
        input->FUN_00a25560(converted);
    }
}
// @fnv 0x00715d40
float InterfaceManager::UpdateInterfaceState()
{
    float height;
    float width = (float)FUN_004dc1f0();
    height = (float)FUN_004dc200();
    if (width > height)
        return (float)((width / height) * DAT_0106e7f8);
    else
        return DAT_0106ec38;
}
// @fnv 0x00718fb0
SystemColorManager::SystemColor* SystemColorManager::Find(int trait)
{
    struct Search
    {
        SystemColor* color;
        void* position;
    } state;
    state.position = (void*)((BSStringT<char>*)this)->String();
    while (state.position)
    {
        state.color = (SystemColor*)((NiTPointerListBase<NiTPointerAllocator<unsigned int>, BSOcclusionPlane*>*)this)
                          ->GetNext(state.position);
        if (state.color && Tile::GetTraitID((const char*)((Interface*)state.color)->GetRoot()) == trait)
            return state.color;
    }
    return 0;
}
// Scans enterStack for the first empty slot and returns the matching previousStack entry, or enterStack[9] when full and 0 when empty.
// @fnv 0x00714f00
int InterfaceManager::GetTopEnterStackEntry()
{
    int index;
    for (index = 0; index < 10; ++index)
    {
        if (!enterStack[index])
            break;
    }
    if (index >= 10)
        return enterStack[9];
    else if (index == 0)
        return 0;
    return previousStack[index];
}
// @fnv 0x00717920
bool InterfaceManager::IsInterfaceMenuActive()
{
    if (ConsoleManager::Instance(true)->IsConsoleActive())
        return false;
    int menu = FUN_004b7210()->GetTopEnterStackEntry();
    if (menu == 0x3eb || menu == 0x3ff || menu == 0x3ea || menu == 0x40b || menu == 0x425 || menu == 1)
        return true;
    return false;
}

// Initialises the object's fields: clears offsets 0x0, 0xc and 0x10, sets offset 0x4 to 0.0f and offset 0x8 to 0.001f, then returns pThis.
// @fnv 0x0070a8a0
void* __fastcall FUN_0070a8a0(void* pThis)
{
    *(int*)((char*)pThis + 0xc) = 0;
    *(int*)((char*)pThis + 0x10) = 0;
    *(float*)((char*)pThis + 4) = 0.0f;
    *(float*)((char*)pThis + 8) = 0.001f;
    *(int*)pThis = 0;
    return pThis;
}

void __fastcall ResetEntries(void*);

// @fnv 0x0070a8e0
void* __fastcall FUN_0070a8e0(void* p)
{
    ResetEntries(p);
    return p;
}

struct FUN_0070a900_Helper
{
    char _pad[0x32];
    bool m_bInterface;
    void Set(bool abInterface);
};

// @fnv 0x0070a900
void FUN_0070a900_Helper::Set(bool abInterface)
{
    m_bInterface = abInterface;
}

struct SSN
{
    void FUN_0070b760(unsigned char);
};
void FUN_00b4f2f0(unsigned char, SSN*);
// Stores a byte at offset 0x120 of this object, then passes it and this to FUN_00b4f2f0.
// @fnv 0x0070b760
void SSN::FUN_0070b760(unsigned char ucValue)
{
    *(unsigned char*)((char*)this + 0x120) = ucValue;
    FUN_00b4f2f0(ucValue, this);
}

struct EffectSetting;
struct Menu;
struct NiFixedString;
struct PerkForm;
struct TESReputation;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_0070b790_shell : public InterfaceManager
{
    void FUN_0070b790(char);
};

struct Tile_
{
    Menu* GetMenu();
};
struct Menu
{
    void SetCurrentPageFromChar(unsigned char);
};
Tile_* FindMenuById(int);
// Stores a at offset 0x12, then looks up tile 0x3eb and, if it has a menu, forwards a to that menu's SetCurrentPageFromChar.
// @fnv 0x0070b790
void FUN_0070b790_shell::FUN_0070b790(char a)
{
    *(char*)((char*)this + 0x12) = a;
    Tile_* tile = FindMenuById(0x3eb);
    Menu* m = 0;
    if (tile)
        m = tile->GetMenu();
    if (m)
        m->SetCurrentPageFromChar(a);
}

namespace fnv_0070b810 {
struct InventoryStackRecord;
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_0070b810_shell : public InterfaceManager
{
    void FUN_0070b810(char);
};

Menu* __cdecl FindMenuById(int);
void __cdecl SetInventoryTab(int);

struct Tile_GetMenu_Accessor : public Tile
{
    Menu* GetMenu(void);
};

__declspec(noalias) inline Menu* CallTileGetMenu(Tile* pTile)
{
    return ((Tile_GetMenu_Accessor*)pTile)->GetMenu();
}

// @fnv 0x0070b810
void FUN_0070b810_shell::FUN_0070b810(char acTab)
{
    *((char*)this + 0x13) = acTab;
    Tile* ptile = (Tile*)FindMenuById(0x3ea);
    Menu* pmenu = 0;
    if (ptile)
    {
        pmenu = ((Tile_GetMenu_Accessor*)ptile)->GetMenu();
    }
    if (pmenu)
    {
        SetInventoryTab(acTab);
    }
}
}  // namespace fnv_0070b810

namespace fnv_0070b870 {
struct Menu0b870;
struct Tile0b870
{
    Menu0b870* GetMenu();
};
struct Menu0b870
{
    void FUN_007069f0(int);
};
Tile0b870* __cdecl FindMenuById(int);
struct S0b870
{
    char pad[0x15];
    char tab;
    void FUN_0070b870(char c);
};
// Stores c in tab, then looks up tile 0x3ff and, if it has a menu, forwards c to FUN_007069f0.
// @fnv 0x0070b870
void S0b870::FUN_0070b870(char c)
{
    tab = c;
    Tile0b870* pmenu = FindMenuById(0x3ff);
    {
        Menu0b870* ptile = 0;
        if (pmenu)
            ptile = pmenu->GetMenu();
        if (ptile)
            ptile->FUN_007069f0(c);
    }
}
}  // namespace fnv_0070b870

struct FUN_0070b8d0_shell : public InterfaceManager
{
    void FUN_0070b8d0(int);
};

// @fnv 0x0070b8d0
void FUN_0070b8d0_shell::FUN_0070b8d0(int aiMenu)
{
    if (aiMenu == 0)
        aiMenu = 0x3EB;
}

struct BSAudio_
{
    void FUN_00ad8510(int, int);
    void FUN_0070bba0();
};
// @fnv 0x0070bba0
void BSAudio_::FUN_0070bba0()
{
    FUN_00ad8510(0x40000000, 1);
}

class BSAudioManager
{
  public:
    void DisableAudioPlayback(unsigned int, bool);
};

// @fnv 0x0070bbc0
void __fastcall FUN_0070bbc0(BSAudioManager* pAudioManager)
{
    pAudioManager->DisableAudioPlayback(0x40000000, true);
}

namespace fnv_0070bc00 {
struct BSAudioManager
{
    void DisableAudioPlayback(unsigned int, bool);
};

// @fnv 0x0070bc00
void __fastcall FUN_0070bc00(BSAudioManager* pAudioManager)
{
    pAudioManager->DisableAudioPlayback(6, true);
}
}  // namespace fnv_0070bc00

struct FUN_0070c3b0_Dummy
{
    char pad[0x698];
    float m_fValue;
    float Get()
    {
        return m_fValue;
    }
};

// @fnv 0x0070c3b0
float __fastcall FUN_0070c3b0(FUN_0070c3b0_Dummy* pThis)
{
    return pThis->m_fValue;
}

// @fnv 0x0070c3d0
char __fastcall FUN_0070c3d0(char* pThis)
{
    return pThis[0x75e];
}

// @fnv 0x0070c3f0
void* __fastcall GetFieldAtOffsetDD4(void* pThis)
{
    return reinterpret_cast<char*>(pThis) + 0xdd4;
}

int g_011d8950;

// @fnv 0x0070ec00
bool FUN_0070ec00()
{
    return g_011d8950 != 0;
}

// @fnv 0x0070ec50
char __fastcall FUN_0070ec50(char* thisPtr)
{
    return thisPtr[0x162];
}

// @fnv 0x0070ec90
unsigned int __fastcall FUN_0070ec90(char* this_ptr)
{
    return *(unsigned int*)(this_ptr + 0x64);
}

// @fnv 0x0070ecd0
bool __fastcall FUN_0070ecd0(unsigned int* pThis)
{
    return (pThis[0x53] & 1) != 0;
}

struct FUN_0070ecf0_shell : public InterfaceManager
{
    bool IsFlag4Set();
};

// @fnv 0x0070ecf0
bool FUN_0070ecf0_shell::IsFlag4Set()
{
    return (*(unsigned int*)((char*)this + 0x14c) & 4) != 0;
}

// @fnv 0x0070edc0
char __fastcall FUN_0070edc0(char* pThis)
{
    return pThis[0xd54];
}

class StartMenu
{
  public:
    enum Flag
    {
        FLAG_1 = 1
    };
    bool IsFlagSet(Flag);
};

extern StartMenu* DAT_011daac0;

// Returns true when DAT_011daac0 exists and its flag 1 is not set.
// @fnv 0x0070edf0
bool __cdecl FUN_0070edf0()
{
    return DAT_011daac0 && !DAT_011daac0->IsFlagSet((StartMenu::Flag)1);
}

struct FUN_00710ab0_Class
{
    char pad[0x670];
    float val;
    float Get()
    {
        return val;
    }
};

// @fnv 0x00710ab0
float __fastcall FUN_00710ab0(FUN_00710ab0_Class* _this)
{
    return _this->val;
}

// @fnv 0x00711e20
float FUN_00711e20()
{
    return -InterfaceManager::UpdateInterfaceState() / 2.0;
}

// @fnv 0x00711e40
float FUN_00711e40()
{
    return InterfaceManager::UpdateInterfaceState() / 2.0;
}

float __cdecl FUN_00715da0(void);

// @fnv 0x00711e60
float __cdecl GetNegativeHalfValue(void)
{
    return -FUN_00715da0() / 2.0;
}

float __cdecl FUN_00715da0(void);

// @fnv 0x00711e80
float __cdecl GetHalfValue(void)
{
    return FUN_00715da0() / 2.0;
}

struct S5
{
    void SetByteAtOffset60();
};
struct S4
{
    S5* FUN_004ebbc0(int, unsigned char);
    void FUN_007123a0(unsigned char);
};
// Calls FUN_004ebbc0 with 0xf and a, then calls SetByteAtOffset60 on the returned object.
// @fnv 0x007123a0
void S4::FUN_007123a0(unsigned char aucValue)
{
    FUN_004ebbc0(0xf, aucValue)->SetByteAtOffset60();
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
struct FUN_007123f0_shell : public ImageSpaceManager
{
    void FUN_007123f0(float);
};

struct Dummy_004ebbc0
{
    void* __thiscall FUN_004ebbc0(int);
};
struct Dummy_00712420
{
    void __thiscall FUN_00712420(float);
};

// Forwards afValue to the object returned by FUN_004ebbc0(0xf) via FUN_00712420.
// @fnv 0x007123f0
void FUN_007123f0_shell::FUN_007123f0(float afValue)
{
    ((Dummy_00712420*)((Dummy_004ebbc0*)this)->FUN_004ebbc0(0xf))->FUN_00712420(afValue);
}

struct _Rect16_00712e60
{
    float a, b, c, d;
};

struct _Cam_00712e60
{
    char pad[0x100];
    _Rect16_00712e60 m_kPort;
    void FUN_00712e60(const _Rect16_00712e60& kPort);
};

// Copies the given port rectangle into the camera's m_kPort field.
// @fnv 0x00712e60
void _Cam_00712e60::FUN_00712e60(const _Rect16_00712e60& kPort)
{
    m_kPort = kPort;
}

struct M3_
{
    void SetElement(unsigned int, float, float, float);
};
// Stores the three floats a, b and c into the 12-byte element at index i of this object.
// @fnv 0x007133b0
void M3_::SetElement(unsigned int uiIndex, float a, float b, float c)
{
    *(float*)((char*)this + uiIndex * 12) = a;
    *(float*)((char*)this + uiIndex * 12 + 4) = b;
    *(float*)((char*)this + uiIndex * 12 + 8) = c;
}

class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

class NavMeshEdgeSegment;
template <> class BSSimpleArray<NavMeshEdgeSegment, 1024>
{
  public:
    bool FUN_0076b610(void) const;
};

class Script
{
  public:
    virtual ~Script();
};

template <> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*>
{
  public:
    Script* RemoveHead(void);
};

extern ActorTaskManager g_011d8c18;
extern NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*> g_011d8b2c;

// Queries the performance counter, deletes scripts from g_011d8b2c until the array check passes, then waits for tasks during rendering.
// @fnv 0x00713c00
void WaitForTasksAndClearScripts()
{
    g_011d8c18.QueryPerformanceCounter(0);
    while (!((BSSimpleArray<NavMeshEdgeSegment, 1024>*)&g_011d8b2c)->FUN_0076b610())
    {
        delete g_011d8b2c.RemoveHead();
    }
    g_011d8c18.WaitForTasksDuringRendering();
}

class NavMesh;
class TESLoadScreen;
bool __cdecl FUN_009a3830(NavMesh* const&, NavMesh* const&);
struct LS3de0
{
    unsigned int Find(NavMesh* const&, unsigned int, bool(__cdecl*)(NavMesh* const&, NavMesh* const&));
    void UpdateEntryValue(unsigned int, unsigned int);
};
struct S3de0
{
    void FUN_00713de0(NavMesh* p);
};
// @fnv 0x00713de0
void S3de0::FUN_00713de0(NavMesh* p)
{
    unsigned int idx = ((LS3de0*)&g_011d8b44)->Find(p, 0, FUN_009a3830);
    if (idx != 0xFFFFFFFF)
        ((LS3de0*)&g_011d8b44)->UpdateEntryValue(idx, 1);
}

struct FUN_00713ee0_shell : public Tile
{
    void ClearFlag();
};

// @fnv 0x00713ee0
void FUN_00713ee0_shell::ClearFlag()
{
    *((bool*)((char*)this + 0x34)) = false;
}

struct S148c0
{
    void** vt;
    bool FUN_004a0e10(const char*, int);
    void FUN_007148c0(int a, int b);
};
typedef void(__thiscall* Fn148c0)(S148c0*, int, int);
// @fnv 0x007148c0
void S148c0::FUN_007148c0(int aiArg1, int aiArg2)
{
    if (!FUN_004a0e10("ClearBuffer", 1))
        return;
    ((Fn148c0)vt[98])(this, aiArg1, aiArg2);
}

extern unsigned char* DAT_011f5b04;

// Returns true if DAT_011f5b04 is non-null and the byte at offset 0x1b0 is set.
// @fnv 0x00714a00
bool __cdecl FUN_00714a00()
{
    return DAT_011f5b04 && DAT_011f5b04[0x1b0];
}

extern int DAT_011ff9d8;
void __cdecl FUN_00b97de0(unsigned int, unsigned int);

// @fnv 0x00714a40
void __cdecl FUN_00714a40(int aiAmount)
{
    DAT_011ff9d8 -= aiAmount;
    FUN_00b97de0(1, 0);
}

extern int DAT_011ff9dc;
void __cdecl FUN_00b97e30(unsigned int, unsigned int);

// @fnv 0x00714a60
void __cdecl FUN_00714a60(int aiAmount)
{
    DAT_011ff9dc -= aiAmount;
    FUN_00b97e30(1, 0);
}

extern int DAT_011ff9e0;
void __cdecl FUN_00b97e80(int, int);

// @fnv 0x00714a80
void __cdecl FUN_00714a80(int aiAmount)
{
    DAT_011ff9e0 -= aiAmount;
    FUN_00b97e80(3, 0);
}

extern int DAT_011ff9e8;
void __cdecl FUN_00b97ed0(int, int);

// @fnv 0x00714aa0
void __cdecl FUN_00714aa0(int aiAmount)
{
    DAT_011ff9e8 -= aiAmount;
    FUN_00b97ed0(0, 0);
}

extern int DAT_011ff9ec;
void __cdecl FUN_00b97f20(int, int, int);

// @fnv 0x00714ac0
void __cdecl FUN_00714ac0(int aiAmount)
{
    DAT_011ff9ec -= aiAmount;
    FUN_00b97f20(0, 0, 0);
}

enum BSRENDERSTATE_LOCK
{
    BSRENDERSTATE_LOCK_0 = 0
};

class BSRenderStateManager
{
  public:
    static void __cdecl SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
};

extern int DAT_011ff9f0;

// @fnv 0x00714ae0
void __cdecl FUN_00714ae0(int aiAmount)
{
    DAT_011ff9f0 -= aiAmount;
    BSRenderStateManager::SetDepthBufferEnabled(false, BSRENDERSTATE_LOCK_0);
}

extern int DAT_011ff9f4;
void __cdecl AddToTwoCounters(int, int, int);

// Subtracts param_1 from DAT_011ff9f4, then calls AddToTwoCounters with (0, 1, 0).
// @fnv 0x00714b00
void __cdecl FUN_00714b00(int aiAmount)
{
    DAT_011ff9f4 -= aiAmount;
    AddToTwoCounters(0, 1, 0);
}

extern int DAT_011ffa00;
void __cdecl FUN_00b980c0(int, int, int, int);

// Subtracts param_1 from DAT_011ffa00, then calls FUN_00b980c0 with four zero arguments.
// @fnv 0x00714b20
void __cdecl FUN_00714b20(int aiAmount)
{
    DAT_011ffa00 -= aiAmount;
    FUN_00b980c0(0, 0, 0, 0);
}

extern int DAT_011ffa04;
void __cdecl FUN_00b98180(int, int, int, int);

// Subtracts param_1 from DAT_011ffa04, then calls FUN_00b98180 with (0, 0, 0xff, 0).
// @fnv 0x00714b50
void __cdecl FUN_00714b50(int aiAmount)
{
    DAT_011ffa04 -= aiAmount;
    FUN_00b98180(0, 0, 0xff, 0);
}

extern int DAT_011ffa08;
void __cdecl AddToSlot(int, int);

// Subtracts param_1 from DAT_011ffa08, then calls AddToSlot with 0xff and 0.
// @fnv 0x00714b80
void __cdecl FUN_00714b80(int aiAmount)
{
    DAT_011ffa08 -= aiAmount;
    AddToSlot(0xff, 0);
}

extern int DAT_011ffa0c;
void __cdecl AddToCounterIfIdle(unsigned int, unsigned int);

// @fnv 0x00714bb0
void __cdecl FUN_00714bb0(int param_1)
{
    DAT_011ffa0c -= param_1;
    AddToCounterIfIdle(0, 0);
}

extern int DAT_011ffa10;

// @fnv 0x00714bd0
void __cdecl FUN_00714bd0(int param_1)
{
    DAT_011ffa10 -= param_1;
}

extern int DAT_011ff9e4;
void __cdecl SendFloatAdd(float, int);

// Subtracts param_1 from DAT_011ff9e4, then calls SendFloatAdd with 0.0f and 0.
// @fnv 0x00714bf0
void __cdecl FUN_00714bf0(int param_1)
{
    DAT_011ff9e4 -= param_1;
    SendFloatAdd(0.0f, 0);
}

extern int DAT_011ffa20;
void __cdecl FUN_00b98480(int, int);

// @fnv 0x00714c20
void __cdecl FUN_00714c20(int param_1)
{
    DAT_011ffa20 -= param_1;
    FUN_00b98480(0, 0);
}

extern int DAT_011ffa28;
int __cdecl FUN_00b98540(int, int);

// @fnv 0x00714c40
int __cdecl FUN_00714c40(int param_1)
{
    DAT_011ffa28 -= param_1;
    return FUN_00b98540(0, 0);
}

struct FUN_00714f90_shell : public InterfaceManager
{
    bool FUN_00714f90(unsigned int);
};

// @fnv 0x00714f90
bool FUN_00714f90_shell::FUN_00714f90(unsigned int aiMenuID)
{
    for (unsigned int i = 0; i < 10; ++i)
    {
        if (GetMenuStackEntry(i) == aiMenuID)
            return true;
    }
    return false;
}

namespace fnv_00714fd0 {
struct FUN_00714fd0_shell : public InterfaceManager
{
    int RemoveFromStack(int, bool);
};

class ImageSpaceManager
{
  public:
    static ImageSpaceManager* __cdecl FUN_004e3270();
    void FUN_007123a0(bool);
};

void __cdecl FUN_00703610();
void __fastcall FUN_0071d580(ConsoleManager*);

// @fnv 0x00714fd0
int FUN_00714fd0_shell::RemoveFromStack(int aiID, bool abForceRemoval)
{
    int a;
    int b;
    int c;
    bool bfound;

    if (enterStack[0] == 0)
        return -1;

    if (!abForceRemoval)
    {
        bfound = false;
        for (c = 0; c < 10; c++)
        {
            if (bfound && enterStack[c] > 1001)
                break;
            if (enterStack[c] == aiID)
                bfound = true;
        }
        if (bfound && c < 10 && aiID != 3)
            return -2;
        else if (!bfound)
            return -1;
    }

    for (a = 0, b = 0; a < 10; a++, b++)
    {
        if (enterStack[a] == aiID)
            b++;
        enterStack[a] = enterStack[b];
        if (enterStack[a] == 0)
            break;
    }

    if (enterStack[0] == 3 && enterStack[1] == 0)
    {
        if (ConsoleManager::Instance(false))
            FUN_0071d580(ConsoleManager::Instance(true));
        return this->RemoveFromStack(3, false);
    }

    if (a > 0)
    {
        if (a == 1 && enterStack[0] == 1001)
            ImageSpaceManager::FUN_004e3270()->FUN_007123a0(true);
        return previousStack[a];
    }

    if (aiID == 1)
        FUN_00703610();

    *(int*)((char*)this + 0xc) = 4;
    ImageSpaceManager::FUN_004e3270()->FUN_007123a0(aiID != 1001);
    return 0;
}
}  // namespace fnv_00714fd0

extern float DAT_0106f2dc;

// @fnv 0x00715da0
float __cdecl FUN_00715da0()
{
    float w = FUN_004dc1f0();
    float h = FUN_004dc200();
    if (h > w)
        return (h / w) * 1280.0;
    else
        return DAT_0106f2dc;
}

class TES
{
  public:
    void SetTESActive(bool);
};

class MapMenu
{
  public:
    static void __cdecl OpenMap(void);
};

struct TileVTable_007160b0
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

struct InterfaceManager_007160b0
{
    Tile* FUN_00586150(void);
};

extern TES* g_TES;
void __cdecl FUN_007ffe00();

// @fnv 0x007160b0
void __fastcall FUN_007160b0(InterfaceManager* pThis)
{
    FUN_007ffe00();
    reinterpret_cast<TileVTable_007160b0*>(reinterpret_cast<InterfaceManager_007160b0*>(pThis)->FUN_00586150())->v7();
    MapMenu::OpenMap();
    g_TES->SetTESActive(true);
}

void __cdecl operator delete(void*);

struct Node_007165d0
{
    int id;
    int unk4;
    int unk8;
    Node_007165d0* prev;
    Node_007165d0* next;
};

// Walks the list at offset 0x164 of the object returned by FUN_004b7210, unlinks and deletes the first node whose id equals param_1.
// @fnv 0x007165d0
void __cdecl RemoveNodeById(int aiId)
{
    Node_007165d0* node = (*(Node_007165d0**)((char*)FUN_004b7210() + 0x164))->next;
    while (node != 0)
    {
        if (node->id == aiId)
        {
            Node_007165d0* next = node->next;
            node->prev->next = next;
            if (next != 0)
            {
                next->prev = node->prev;
            }
            if (node->next == 0)
            {
                (*(Node_007165d0**)((char*)FUN_004b7210() + 0x164))->prev = node->prev;
            }
            delete node;
            break;
        }
        else
        {
            node = node->next;
        }
    }
}

float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);

struct Node_00716660
{
    int id;
    float f4;
    float f8;
    int iC;
    Node_00716660* next;
};

// @fnv 0x00716660
float __cdecl FUN_00716660(int aiId)
{
    Node_00716660* node = *(Node_00716660**)(*(int*)((char*)FUN_004b7210() + 0x164) + 0x10);
    while (node != 0)
    {
        if (aiId == node->id)
        {
            if (node->f8 > 0.0)
            {
                return FUN_00404010(0.0f, FUN_0040ebd0(1.0f, node->f4 / node->f8));
            }
            else
            {
                return -1.0f;
            }
        }
        node = node->next;
    }
    return 1.0f;
}

struct TimeGlobal
{
    int GetSection();
};
extern TimeGlobal g_timeGlobal;
struct AI_
{
    void FUN_007166f0(int);
};
// Stores the current time section at offset 0x154, clears offset 0x158, and stores the argument at offset 0x150.
// @fnv 0x007166f0
void AI_::FUN_007166f0(int a)
{
    *(int*)((char*)this + 0x154) = g_timeGlobal.GetSection();
    *(int*)((char*)this + 0x158) = 0;
    *(int*)((char*)this + 0x150) = a;
}

namespace fnv_00716910 {
class Menu;
Menu* __cdecl FindMenuById(int);

struct Tile_shell : Tile
{
    float GetFloat(int);
    Menu* GetMenu();
};

struct FUN_00716910_shell : InterfaceManager
{
    bool FUN_00716910(Tile_shell* pTile);
};

// Compares the tile's menu with the top tile's menu and returns false when the top tile's float at 0xfa7 is 0x66 or 0x1776 and the menus differ.
// @fnv 0x00716910
bool FUN_00716910_shell::FUN_00716910(Tile_shell* pTile)
{
    int val;
    Tile_shell* topTile = (Tile_shell*)FindMenuById(GetTopEnterStackEntry());
    if (!topTile)
        return true;
    val = (int)topTile->GetFloat(0xfa7);
    if (val == 0x66 || val == 0x1776)
    {
        if (pTile->GetMenu() != topTile->GetMenu())
            return false;
    }
    return true;
}
}  // namespace fnv_00716910

struct Str6a70
{
    char p[8];
    Str6a70& operator=(const char*);
};
struct S6a70
{
    Str6a70 a;
    Str6a70 b;
    void SetBothStrings(const char* s);
};
// Assigns the same C string to both string members a and b.
// @fnv 0x00716a70
void S6a70::SetBothStrings(const char* pcString)
{
    a = pcString;
    b = pcString;
}

struct StackInt
{
    int value;
};

// @fnv 0x00716aa0
void __fastcall FUN_00716aa0(int* pThis, StackInt arg)
{
    pThis[5] = arg.value - 5;
    if (pThis[5] < 0)
    {
        pThis[5] = static_cast<int>(FUN_004b7210()->UpdateInterfaceState());
    }
}

// @fnv 0x00716ae0
char __fastcall GetByteAtOffset33(char* pThis)
{
    return pThis[0x21];
}

struct S7010
{
    char pad[0x10];
    unsigned int len;
    char pad2[0xd];
    bool flag;
    unsigned int Length();
    void FUN_00717010(bool b);
};
// If the flag is clear and b is true, stores Length() into len; then stores b into flag.
// @fnv 0x00717010
void S7010::FUN_00717010(bool b)
{
    if (!flag && b)
        len = Length();
    flag = b;
}

namespace fnv_00717050 {
class AnimIdle
{
  public:
    int GetSection(void);
};

extern AnimIdle g_timeGlobal;

struct FUN_00717050_this
{
    char pad[0x1C];
    unsigned int unk1C;
    bool unk20;
};

// Reads the current section from g_timeGlobal and, if more than 500 units have passed since unk1C, toggles unk20 and stores the new time in unk1C.
// @fnv 0x00717050
void __fastcall ToggleFlagOnInterval(FUN_00717050_this* pThis)
{
    unsigned int t = g_timeGlobal.GetSection();
    if (t - pThis->unk1C > 500)
    {
        pThis->unk20 = !pThis->unk20;
        pThis->unk1C = t;
    }
}
}  // namespace fnv_00717050

bool __cdecl FUN_004de080(void);
float __cdecl FUN_004de0e0(void);

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011d8bd8;
extern GlobalObject2_0040c150 g_011d8bfc;

struct Interface_shell : public Interface
{
    static bool __cdecl IsInterfaceOpen(void);
};

// @fnv 0x007177c0
float __cdecl FUN_007177c0(void)
{
    if (FUN_004de080())
        return FUN_004de0e0() * 0.4f;
    return (float)(Interface_shell::IsInterfaceOpen() ? *g_011d8bfc.Int() : *g_011d8bd8.Int());
}

namespace fnv_00717820 {
class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011d8bc0;
extern GlobalObject2_0040c150 g_011d8bf0;

struct Interface_Wrap : public Interface
{
    static bool __cdecl IsInterfaceOpen(void);
};

// @fnv 0x00717820
float __cdecl FUN_00717820()
{
    return ((bool(__cdecl*)()) & Interface_Wrap::IsInterfaceOpen)() ? *g_011d8bc0.Int() : *g_011d8bf0.Int();
}
}  // namespace fnv_00717820

bool __cdecl FUN_00702680(int, unsigned int);

// @fnv 0x007178a0
bool __cdecl FUN_007178a0()
{
    if (FUN_00702680(0x3eb, 0) || FUN_00702680(0x3ea, 0) || FUN_00702680(0x40b, 0) || FUN_00702680(0x425, 0) ||
        FUN_00702680(0x3ff, 0))
    {
        return true;
    }
    return false;
}

namespace fnv_00717990 {
class BSAudio
{
  public:
    unsigned int GetSynchTime();
};

extern char* DAT_011d8a80;
class Menu* __cdecl FindMenuById(int);

namespace fnv_anon_interfacemanager {}
using namespace fnv_anon_interfacemanager;
namespace fnv_anon_interfacemanager {
struct InterfaceManager_Access : InterfaceManager
{
    static bool __cdecl IsPipboyMenuActive();
};
static bool (*const pIsInPipboyMenu)() = &InterfaceManager_Access::IsPipboyMenuActive;

struct Tile_Access : Tile
{
    NiNode* FUN_0056c7f0();
};
static NiNode* (Tile_Access::*const pTileFunc)() = &Tile_Access::FUN_0056c7f0;
}

// @fnv 0x00717990
bool __cdecl FUN_00717990()
{
    if (*(BSAudio**)(DAT_011d8a80 + 0x16c) == 0)
        return false;

    if (((bool(__cdecl*)())InterfaceManager_Access::IsPipboyMenuActive)())
        return InterfaceManager::IsInterfaceMenuActive();

    if (ConsoleManager::Instance(true)->IsConsoleActive())
        return false;

    int top = FUN_004b7210()->GetTopEnterStackEntry();
    Menu* menu = FindMenuById(top);
    NiNode* node = menu ? ((Tile_Access*)menu)->FUN_0056c7f0() : 0;

    if (node != 0 && (unsigned int)node == (*(BSAudio**)(DAT_011d8a80 + 0x16c))->GetSynchTime())
        return true;

    return false;
}
}  // namespace fnv_00717990

struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_00717e70_shell : public InterfaceManager
{
    void FUN_00717e70(Menu*, int, Tile*);
};

struct DummyItem
{
    virtual bool v0(Tile*);
};

struct DummyNode;

struct DummyMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, Tile*);
};

DummyItem** __fastcall _ref_006815c0(DummyNode*);
DummyNode* __fastcall _ref_00726070(DummyNode*);
extern DummyNode g_011d8b54;

// @fnv 0x00717e70
void FUN_00717e70_shell::FUN_00717e70(Menu* apMenu, int aiID, Tile* apTarget)
{
    for (DummyNode* pnode = &g_011d8b54; pnode != 0 && *_ref_006815c0(pnode) != 0; pnode = _ref_00726070(pnode))
    {
        if ((*_ref_006815c0(pnode))->v0(apTarget))
            break;
    }
    reinterpret_cast<DummyMenu*>(apMenu)->v4(aiID, apTarget);
}

namespace fnv_00717ef0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_00717ef0_shell : public InterfaceManager
{
    void FUN_00717ef0(Menu*, int, Tile*);
};

struct ListBoxBase_00717ef0
{
    virtual bool vfn0(int);
    virtual Tile* vfn1();
};

struct Menu_00717ef0
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5(int, Tile*);
};

struct GlobalObject2_0096a2d0;
extern GlobalObject2_0096a2d0 g_011d8b54;

ListBoxBase_00717ef0** __fastcall _ref_006815c0(GlobalObject2_0096a2d0*);
GlobalObject2_0096a2d0* __fastcall _ref_00726070(GlobalObject2_0096a2d0*);

// @fnv 0x00717ef0
void FUN_00717ef0_shell::FUN_00717ef0(Menu* apMenu, int aiID, Tile* apTarget)
{
    for (GlobalObject2_0096a2d0* pnode = &g_011d8b54; pnode && *_ref_006815c0(pnode); pnode = _ref_00726070(pnode))
    {
        if ((*_ref_006815c0(pnode))->vfn1() == apTarget && (*_ref_006815c0(pnode))->vfn0(0))
            break;
    }
    reinterpret_cast<Menu_00717ef0*>(apMenu)->vfn5(aiID, apTarget);
}
}  // namespace fnv_00717ef0

struct E8840
{
    int a : 1;
    int b : 1;
};
struct S8840
{
    E8840 e[0x29];
    bool FUN_00718840(int id);
};
// Returns true when id is in [0, 0x29) and the b bit of e[id] is set.
// @fnv 0x00718840
bool S8840::FUN_00718840(int aiIndex)
{
    return aiIndex >= 0 && aiIndex < 0x29 && e[aiIndex].b;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct AnimationKey;
struct NiColor;
struct NiColorInterpolator;
struct NiFloatInterpolator;
struct AlphaColor;
struct TimedFloatKey;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESImageSpaceModifier;
struct TESObjectREFR;
struct TESSound;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00718ab0_shell : public InterfaceManager
{
    TESImageSpaceModifier* FUN_00718ab0();
};

class PlayerCharacter
{
  public:
    static bool __cdecl UpdatePlayerStatus();
    bool FUN_00967ae0();
};

extern PlayerCharacter* pPlayer;
int __cdecl FUN_007023c0();
TESImageSpaceModifier* __cdecl _ref_004839c0(unsigned int);
bool __fastcall FUN_00967ae0(PlayerCharacter*);

struct InterfaceManager_helper
{
    Tile* FUN_00586150();
};

struct Tile_helper
{
    Tile* GetNamedChild(const char*);
};

// Returns a TESImageSpaceModifier chosen by player state, top menu ID, or whether the Player Name Entry Menu tile exists.
// @fnv 0x00718ab0
TESImageSpaceModifier* FUN_00718ab0_shell::FUN_00718ab0()
{
    TESImageSpaceModifier* presultMod = 0;
    int etopID = FUN_007023c0();
    if (PlayerCharacter::UpdatePlayerStatus())
    {
        presultMod = _ref_004839c0(0x4eee8);
    }
    else if (FUN_00967ae0(pPlayer))
    {
        presultMod = _ref_004839c0(0x96389);
    }
    else if (etopID == 0x3f6)
    {
        presultMod = _ref_004839c0(0x44f34);
    }
    else if (!reinterpret_cast<Tile_helper*>(reinterpret_cast<InterfaceManager_helper*>(FUN_004b7210())->FUN_00586150())
                  ->GetNamedChild("Player Name Entry Menu"))
    {
        presultMod = _ref_004839c0(0x32b38);
    }
    return presultMod;
}

class InventoryStackRecord
{
  public:
    InventoryStackRecord();
};

// @fnv 0x00718d90
InventoryStackRecord* __fastcall FUN_00718d90(InventoryStackRecord* pThis)
{
    pThis->InventoryStackRecord::InventoryStackRecord();
    return pThis;
}

// Packs red, green, blue and alpha bytes into a single 32-bit RGBA value with red in the high byte.
// @fnv 0x00718e90
unsigned int __cdecl PackRgba(unsigned int aiRed, unsigned int aiGreen, unsigned int aiBlue, unsigned int aiAlpha)
{
    unsigned int uirgba;
    uirgba = aiRed << 24;
    uirgba |= (aiGreen & 0xFF) << 16;
    uirgba |= (aiBlue & 0xFF) << 8;
    uirgba |= (aiAlpha & 0xFF);
    return uirgba;
}

class NavMesh;
bool __cdecl FUN_009a3830(NavMesh* const&, NavMesh* const&);

template <> class BSSimpleArray<NavMesh*, 1024>
{
  public:
    unsigned int Find(NavMesh* const&, unsigned int, bool(__cdecl*)(NavMesh* const&, NavMesh* const&));
};

struct FUN_009962f0_s
{
    bool f(NavMesh* const& aValue);
};
static bool (FUN_009962f0_s::*volatile p_f)(NavMesh* const&) = &FUN_009962f0_s::f;

// Returns whether Find locates aValue in the array using FUN_009a3830, i.e. the index is not -1.
// @fnv 0x009962f0
bool FUN_009962f0_s::f(NavMesh* const& aValue)
{
    return ((BSSimpleArray<NavMesh*, 1024>*)this)->Find(aValue, 0, FUN_009a3830) != (unsigned int)-1;
}

struct CF845
{
    unsigned int v;
    CF845(int);
};
typedef CF845 bhkFilter;
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
};
struct Flt
{
    operator bhkWorldObject*() const;
};
struct FUN_0070c440_stub
{
    char pad[0x594];
    Flt m_kNinthAdditionalHighProcessField;
    bhkFilter FUN_0070c440();
};
// @fnv 0x0070c440
bhkFilter FUN_0070c440_stub::FUN_0070c440()
{
    return m_kNinthAdditionalHighProcessField ? ((bhkWorldObject*)m_kNinthAdditionalHighProcessField)->FUN_0043b4f0()
                                              : CF845(0);
}

namespace fnv_007157b0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_007157b0_shell : public InterfaceManager
{
    void ClearMenuTargets(bool);
};

namespace fnv_00717ef0 {
struct Menu;
struct FUN_00717ef0_shell
{
    void FUN_00717ef0(Menu*, int, Tile*);
};
}
struct TileHelper
{
    void Set(int, int);
    float GetFloat(int);
};
// If leaving and both pointers are set, clears two tile values and calls FUN_00717ef0, then nulls the pointers at offsets 0xcc and 0xd0.
// @fnv 0x007157b0
void FUN_007157b0_shell::ClearMenuTargets(bool abDoLeave)
{
    if (abDoLeave && *(void**)((char*)this + 0xd0) && *(void**)((char*)this + 0xcc))
    {
        TileHelper* ptarget = *(TileHelper**)((char*)this + 0xcc);
        fnv_00717ef0::Menu* pmenu = *(fnv_00717ef0::Menu**)((char*)this + 0xd0);
        if (ptarget)
        {
            ptarget->Set(0xfc3, 0);
            ptarget->Set(0xfc7, 0);
            if (pmenu)
                ((fnv_00717ef0::FUN_00717ef0_shell*)this)
                    ->FUN_00717ef0(pmenu, (int)ptarget->GetFloat(0xfaa), (Tile*)ptarget);
        }
    }
    *(void**)((char*)this + 0xcc) = 0;
    *(void**)((char*)this + 0xd0) = 0;
}
}  // namespace fnv_007157b0

void __cdecl ClearPmeIfMatches(void*);
struct FUN_00716010_stub
{
    char pad[0xf0];
    void* a[5];
    void FUN_00716010(void* p);
};
// Clears any of the five slots that equal p, then calls ClearPmeIfMatches(p).
// @fnv 0x00716010
void FUN_00716010_stub::FUN_00716010(void* p)
{
    if (a[0] == p)
        a[0] = 0;
    if (a[1] == p)
        a[1] = 0;
    if (a[2] == p)
        a[2] = 0;
    if (a[3] == p)
        a[3] = 0;
    if (a[4] == p)
        a[4] = 0;
    ClearPmeIfMatches(p);
}

namespace fnv_007181d0 {
struct BSRenderedTexture;
struct BSShaderNoLightingProperty;
struct FORenderedMenu;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiGeometry;
struct NiPointLight;
struct NiTexture;
struct ShadowSceneNode;
struct blob16
{
    char b[16];
};
struct FUN_007181d0_shell : public InterfaceManager
{
    void SetRenderedMenu(FORenderedMenu*);
};

struct FORenderedMenu
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
    bool GetInitialized();
    void FUN_007fae70(int);
};
struct Calendar
{
    unsigned int GetDaysPassed();
};
struct TileHelper
{
    void Set(int, int);
};
struct InterfaceHelper
{
    FORenderedMenu* GetPipboyManager();
};
void __cdecl FUN_007182b0(FORenderedMenu*);
// @fnv 0x007181d0
void FUN_007181d0_shell::SetRenderedMenu(FORenderedMenu* apRenderedMenu)
{
    if (apRenderedMenu)
    {
        if (!apRenderedMenu->GetInitialized())
            apRenderedMenu->v9();
        apRenderedMenu->v12();
        *(char*)((char*)this + 0x168) = 1;
        if (((Calendar*)apRenderedMenu)->GetDaysPassed())
            ((TileHelper*)((Calendar*)apRenderedMenu)->GetDaysPassed())->Set(0xfa3, 0);
    }
    else
    {
        if (*(FORenderedMenu**)((char*)this + 0x16c))
        {
            (*(FORenderedMenu**)((char*)this + 0x16c))->FUN_007fae70(0);
            (*(FORenderedMenu**)((char*)this + 0x16c))->v13();
            if (*(FORenderedMenu**)((char*)this + 0x16c) != ((InterfaceHelper*)this)->GetPipboyManager())
                FUN_007182b0(*(FORenderedMenu**)((char*)this + 0x16c));
        }
        *(char*)((char*)this + 0x168) = 0;
    }
    *(FORenderedMenu**)((char*)this + 0x16c) = apRenderedMenu;
}
}  // namespace fnv_007181d0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DeleteIfFlagged(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0070b690
void* DelStandIn::DeleteIfFlagged(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct NiStream;
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
typedef char _sizecheck_NiColorA[sizeof(RgbaColor) == 16 ? 1 : -1];

extern float DAT_0102f0e4;
void __cdecl UnpackBytes(int, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
struct SystemColor
{
    virtual void v0();
    virtual int GetValue() const;
    void FUN_007193b0(RgbaColor* aOutColor) const;
};

// @fnv 0x007193b0
void SystemColor::FUN_007193b0(RgbaColor* aOutColor) const
{
    unsigned int igreen;
    unsigned int ired;
    unsigned int iblue;
    unsigned int ialpha;
    UnpackBytes(GetValue(), &ired, &igreen, &iblue, &ialpha);
    aOutColor->r = ired * DAT_0102f0e4;
    aOutColor->g = igreen * DAT_0102f0e4;
    aOutColor->b = iblue * DAT_0102f0e4;
}

namespace fnv_0070c4a0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuTileComponent;
struct MenuValueDescriptor;
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct GamepadManager
{
    int InitGamePads();
    void Poll(unsigned long);
    bool IsChangeDetected();
    bool IsPadActive(int);
    unsigned long GetPhysicalPort(int);
    MenuTileComponent* GetPad(int);
    unsigned int ButtonState(int, int);
    unsigned int AllButtonStates(int);
    int ButtonForce(int, int);
    bool CheckSoftReset(int);
    void SetButtonState(int, int, unsigned int);
    void SetButtonForce(int, int, int);
    static void SetDeadZoneAbs(int, float);
    static float GetDeadZoneAbs(int);
    unsigned int PressedButtons(int);
    unsigned int ClickButtons(int);
    unsigned int DebounceButtons(int);
    unsigned int RepeatButtons(int);
    void Rumble(int, float, float, int, int, int, bool, bool);
    void RumbleFull(int, int);
    void UpdateRumbles(int);
    void KillRumbles();
    void KillRumble(int);
    static bool SomeonePressedStart(int*);
    void* __vecDelDtor(unsigned int);
    char m_cPadData[816];
    bool m_bChangeDetected;
    char _pad_331[3];
};
typedef char _sizecheck_XInputManager[sizeof(GamepadManager) == 820 ? 1 : -1];
struct Controls : public GamepadManager
{
    static Controls* GetInstance();
    static void DeleteInstance();
    void Poll(float, bool, bool);
    void ClearKeystrokes();
    int GetNextKeystroke(int*);
    int GetNextKeyEvent(int*);
    void ResetControls();
    void SetMenuDeadZone(int, bool);
    void SetMenuDeadZone(bool);
    unsigned int GetButtonState(int);
    int GetButtonForce(int);
    void GetMouseDelta(unsigned int, NiPoint2*);
    void GetMouseAbs(unsigned int, NiPoint2*);
    void SetMouseSpeed(unsigned int, float);
    float GetMouseSpeed(int);
    void GetMouseAxis(int*, int*);
    void GetMouseAxis(unsigned int, int*, int*);
    int GetMouseButton(int, int);
    int TranslateKeystroke(int, int);
    int GetUserAction(int, int);
    void ForceUserAction(int);
    void ClearUserActions();
    void ClearUserAction(int);
    unsigned int GetDigitalAction(int, unsigned int);
    int GetAnalogAction(int);
    long GetJoystickAxis(int, int);
    void SetStickConfiguration(int);
    void SetDigitalAction(int, unsigned int);
    void SetAnalogAction(int, int);
    int GetControlValue(int);
    void LoadControl(int, unsigned int);
    void Rumble(float, float, int, int, int, bool, bool);
    void RumbleFull(int);
    void KillRumble();
    bool PerformAction(int);
    static void EnableRumble(bool);
    static bool IsRumbleEnabled();
    bool IsSettingControl();
    bool isControllerValid();
    bool SetCurrentController(int);
    int GetCurrentController();
    void SetFlag(unsigned short);
    bool GetFlag(unsigned short);
    unsigned int PressedButtons();
    unsigned int ClickButtons();
    unsigned int DebounceButtons();
    unsigned int RepeatButtons();
    void SaveControls();
    void LoadControls(unsigned char*, unsigned int);
    static bool Remappable(int);
    static bool RemappableButton(int);
    static void GetIconForButton(int, void*, bool);
    static void ResetMappingsToDefault(bool);
    bool RemapTo(int, int);
    int RemapAction(int, unsigned int);
    float GetRunScale();
    int GetKeyboardButton(int, int);
    void RemoveDuplicateControls(int, int);
    void UpdateMouse(float);
    void UpdateKeyboard(bool);
    int MenuUserAction(int, int);
    void* __vecDelDtor(unsigned int);
    int m_iInputValueAtOffset334;
    int m_iInputValueAtOffset338;
    bool m_bInputFlagAtOffset33C;
    bool m_bInputFlagAtOffset33D;
    char _pad_33e[2];
    float m_fInputValueAtOffset340;
    float m_fInputValueAtOffset344;
    float m_fInputValueAtOffset348;
    bool m_bInputFlagAtOffset34C;
    bool m_bInputFlagAtOffset34D;
    char _pad_34e[2];
    float m_fInputValueAtOffset350;
    float m_fInputValueAtOffset354;
    unsigned short m_uiParameterCount;
    char _pad_35a[2];
    char m_acInputDataAtOffset35C[32];
    char m_acInputDataAtOffset37C[16];
    bool m_bInputFlagAtOffset38C;
    char _pad_38d[3];
    int m_iInputValueAtOffset390;
    int m_iInputValueAtOffset394;
    char m_acInputDataAtOffset398[7];
    char _pad_39f[1];
    char m_acInputDataAtOffset3A0[208];
};
typedef char _sizecheck_Controls[sizeof(Controls) == 1136 ? 1 : -1];
struct FUN_0070c4a0_shell : public InterfaceManager
{
    void UpdateInterface();
};

struct TileH;
struct MenuH;
struct NiAVH
{
    void SetAppCulled(bool);
};
struct ListH
{
    int _a;
    void* Find(TileH* const&, void*);
    unsigned int Head();
    TileH*& GetNext(void*&);
};
struct TileH
{
    int _vt;
    ListH lst;
    NiAVH* FUN_0056c7f0();
    void Set(int, int);
    void Set(int, float, bool);
    void Set(int, const char*, bool);
    bool ContainsTrait(int);
    MenuH* GetMenu();
    TileH* GetNamedChild(const char*);
    bool IsVisible();
    float GetFloat(int);
    float GetTotalFloat();
    float GetAccumulatedFloat();
    void FUN_00a0b110(int);
    void FUN_00a04640(int);
    void* FindTraitValue(int);
    char* FUN_00a011f0(int);
    void* GetNext();
};
struct MenuH
{
    virtual void v00();
    virtual void v04();
    virtual void vf08(int, TileH*);
    virtual void vf0c(int, TileH*);
    virtual void v10();
    virtual void vf14(int, TileH*);
    virtual void vf18(int, TileH*, TileH*);
    virtual void vf1c(int, TileH*, TileH*);
    virtual void vf20(int, TileH*);
    virtual void vf24(int, TileH*);
    virtual void v28();
    virtual void vf2c();
    virtual bool vf30(int);
    unsigned int GetThreadID();
};
struct V16c
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void vf14();
    virtual bool vf18(bool, int*, int*);
};
struct PBM
{
    void UpdateFade(float);
};
struct L70
{
    int _a;
    int _b;
    unsigned int GetSize();
};
struct S178
{
    int _a;
    void UpdateIfActive();
};
struct S1dc
{
    int _a;
    void FUN_00800370();
};
struct S4d4
{
    int _a;
    void FUN_007182e0();
};
struct AMC
{
    AMC(int, bool, const char*, int);
    ~AMC();
    int _a;
};
struct NP2
{
    float x;
    float y;
    NP2(float, float);
};
struct SndH
{
    int _a;
    int _b;
    int _c;
    SndH();
    SndH& operator=(const SndH&);
    ~SndH();
    bool Play(bool);
    void PausePlayback();
};
struct AudH
{
    static AudH* GetSingleton();
    SndH GetSoundHandleByEditorID(const char*, unsigned int);
    void FUN_0070bc00();
};
struct Ctl
{
    int FUN_00a239e0(int);
    int FUN_00a23a50(int, int);
    int SetHotkeyItem(int, int);
    int HandleHotkeyInput(int, int);
    int FUN_00a23820(int*);
    int FUN_00a238a0(int, int);
    void FUN_00a237b0();
    void FUN_0070ec20(int, int);
    void FUN_00a253d0();
};
struct MCH
{
    bool Idle(int);
    bool FUN_0071d580();
};
struct MMH
{
    static MMH* Instance(bool);
    MenuH* GetFrontmostMenu();
    bool IsMenuClassVisible(int);
};
struct IFH
{
    static bool IsConsoleActive();
    static bool GetSelectedTargetIndex(int);
    static bool ShowButtonDialog(const char*, const char*, const char*, void (*)(), int, int, float, float, const char*,
                                 ...);
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
    static bool IsInterfaceActive();
};
struct HUDH
{
    static void UpdateVisibilityState(int);
};
struct SMH
{
    static bool Create(bool, bool);
};
struct DLGH
{
    static bool IsInDialog();
};
struct GSet
{
    const char* Get();
};
struct GInt
{
    int* Int();
};
struct ArrSIH
{
    unsigned int GetFlags();
};
struct TG
{
    unsigned int GetSection();
    float GetStoredFloatValue();
};
struct S4b
{
    char _p[0x20];
    unsigned char c20;
    unsigned char c21;
};
struct XS
{
    int a;
    int b;
    int c;
    int d;
};
struct PCH
{
    virtual void pv000();
    virtual void pv004();
    virtual void pv008();
    virtual void pv00c();
    virtual void pv010();
    virtual void pv014();
    virtual void pv018();
    virtual void pv01c();
    virtual void pv020();
    virtual void pv024();
    virtual void pv028();
    virtual void pv02c();
    virtual void pv030();
    virtual void pv034();
    virtual void pv038();
    virtual void pv03c();
    virtual void pv040();
    virtual void pv044();
    virtual void pv048();
    virtual void pv04c();
    virtual void pv050();
    virtual void pv054();
    virtual void pv058();
    virtual void pv05c();
    virtual void pv060();
    virtual void pv064();
    virtual void pv068();
    virtual void pv06c();
    virtual void pv070();
    virtual void pv074();
    virtual void pv078();
    virtual void pv07c();
    virtual void pv080();
    virtual void pv084();
    virtual void pv088();
    virtual void pv08c();
    virtual void pv090();
    virtual void pv094();
    virtual void pv098();
    virtual void pv09c();
    virtual void pv0a0();
    virtual void pv0a4();
    virtual void pv0a8();
    virtual void pv0ac();
    virtual void pv0b0();
    virtual void pv0b4();
    virtual void pv0b8();
    virtual void pv0bc();
    virtual void pv0c0();
    virtual void pv0c4();
    virtual void pv0c8();
    virtual void pv0cc();
    virtual void pv0d0();
    virtual void pv0d4();
    virtual void pv0d8();
    virtual void pv0dc();
    virtual void pv0e0();
    virtual void pv0e4();
    virtual void pv0e8();
    virtual void pv0ec();
    virtual void pv0f0();
    virtual void pv0f4();
    virtual void pv0f8();
    virtual void pv0fc();
    virtual void pv100();
    virtual void pv104();
    virtual void pv108();
    virtual void pv10c();
    virtual void pv110();
    virtual void pv114();
    virtual void pv118();
    virtual void pv11c();
    virtual void pv120();
    virtual void pv124();
    virtual void pv128();
    virtual void pv12c();
    virtual void pv130();
    virtual void pv134();
    virtual void pv138();
    virtual void pv13c();
    virtual void pv140();
    virtual void pv144();
    virtual void pv148();
    virtual void pv14c();
    virtual void pv150();
    virtual void pv154();
    virtual void pv158();
    virtual void pv15c();
    virtual void pv160();
    virtual void pv164();
    virtual void pv168();
    virtual void pv16c();
    virtual void pv170();
    virtual void pv174();
    virtual void pv178();
    virtual void pv17c();
    virtual void pv180();
    virtual void pv184();
    virtual void pv188();
    virtual void pv18c();
    virtual void pv190();
    virtual void pv194();
    virtual void pv198();
    virtual void pv19c();
    virtual void pv1a0();
    virtual void pv1a4();
    virtual void pv1a8();
    virtual void pv1ac();
    virtual void pv1b0();
    virtual void pv1b4();
    virtual void pv1b8();
    virtual void pv1bc();
    virtual void pv1c0();
    virtual void pv1c4();
    virtual void pv1c8();
    virtual void pv1cc();
    virtual void pv1d0();
    virtual void pv1d4();
    virtual void pv1d8();
    virtual void pv1dc();
    virtual void pv1e0();
    virtual void pv1e4();
    virtual void pv1e8();
    virtual void pv1ec();
    virtual void pv1f0();
    virtual void pv1f4();
    virtual void pv1f8();
    virtual void pv1fc();
    virtual void pv200();
    virtual void pv204();
    virtual void pv208();
    virtual void pv20c();
    virtual void pv210();
    virtual int vf214();
    virtual void pv218();
    virtual void pv21c();
    virtual void pv220();
    virtual void pv224();
    virtual void pv228();
    virtual bool vf22c(bool);
    bool FUN_005a03f0(unsigned int);
    bool FUN_00950090();
    bool IsAlert();
    void FUN_0095d090();
    void ClearActorList();
};
struct IMX
{
    char _p0[0xc];
    int mode;
    char _p1[0x18];
    TileH* t28;
    char _p2[0xc];
    float f38;
    char _p3[0x4];
    float f40;
    float f44;
    float f48;
    TileH* t4c;
    int i50;
    float f54;
    float f58;
    int i5c;
    char _p4[0x10];
    L70 l70;
    int i78;
    char _p5[0x1];
    bool b7d;
    char _p6[0x1e];
    TileH* t9c;
    char _p7[0x1c];
    TileH* tbc;
    char _p8[0x8];
    bool bc8;
    char _p9[0x3];
    TileH* tcc;
    MenuH* md0;
    TileH* td4;
    MenuH* md8;
    char _p10[0x11];
    bool bed;
    char _p11[0x7e];
    V16c* p16c;
    bool b170;
    char _p12[0x7];
    S178 o178;
    char _p13[0x60];
    S1dc o1dc;
    char _p14[0x2cc];
    int i4ac;
    int i4b0;
    bool b4b4;
    char _p15[0x3];
    int i4b8;
    int i4bc;
    char _p16[0x14];
    S4d4 o4d4;
    void UpdateControllerState(bool);
    void FUN_00717660();
    PBM* GetPipboyManager();
    void FUN_00718930(int);
    void FUN_007118d0();
    TileH* GetFieldBC();
    void UpdateFocusTarget();
    TileH* FUN_007126c0(int);
    void FUN_00717ef0(MenuH*, int, TileH*);
    void SetMode(int);
    void AddDeferredHideLimb(int);
    void ResetFieldBC();
    void FUN_00717e70(MenuH*, int, TileH*);
    void* GetActiveRenderedMenu();
    void UpdatePickObjects();
    void DrawDebugInfo();
    int GetInterval();
    int GetEffectID();
    int FUN_0070ec70();
    void FUN_00718080(MenuH*, int, TileH*);
    void HandleGamepadButton(int);
    void FUN_007166f0(int);
    int HandleKeyEvent(int, int);
    int FUN_00716730(float);
    bool IsFlag4Set();
    void PushMenuStackEntry(int);
    int AddMenuStackEntry(int, bool);
    void QueueHudCallback(int, int);
    void HandleCallbackOrStore(int);
    TileH* FUN_00586150();
    void UpdatePipboyWaiver();
};
int __stdcall FUN_009f996e(int, void*);
float GetRatio();
float FUN_00717860();
bool FUN_0070ed30();
bool IsStatsMenuActive();
int FUN_0070ede0();
bool FUN_0070edf0();
int FUN_00458030();
void* FUN_0076bfe0();
void FUN_00784c80();
bool FUN_0070ed10();
void FUN_0070ed20(int);
bool FUN_007024e0();
bool IsBothFlagsSet();
void CloseStartMenu(int);
bool FUN_0070ec00();
void FUN_00709470(int, int, int, int, int, int);
void FUN_00a0df80();
void SetDialogMenuActive(int);
int FUN_00717a40(int, int);
void FUN_00717280(int);
void ShowStatsMenu(int, int);
void FUN_007048f0(int, int, int);
void UpdatePipboyMapVisibility(int, int);
bool __fastcall FUN_0070ec50(char*);
bool __fastcall FUN_0070edc0(char*);
bool __fastcall FUN_0070ecd0(unsigned int*);
bool __fastcall FUN_00719ae0(void*);
void __fastcall FUN_0070bbc0(AudH*);
int _sprintf_s(char*, unsigned int, const char*, ...);
extern XS DAT_011d8a54;
extern XS DAT_011d8a6c;
extern bool DAT_011d8a84;
extern unsigned char DAT_011d8a85;
extern bool DAT_011d8904;
extern bool DAT_011d8905;
extern int DAT_0119f530;
extern bool DAT_0119f348;
extern GSet g_011d38b8;
extern GSet g_011d49b4;
extern GSet g_011d2760;
extern GSet g_011d475c;
extern GSet g_011d4cb4;
extern GSet g_011d3fd0;
extern GInt g_011c3ea4;
extern PCH* g_thePlayer;
extern ArrSIH DAT_011f2250;
extern const char g_011cba18_arg1[];
void* FindMenuById(int);
extern TG g_timeGlobal;
struct PCS
{
    static bool UpdatePlayerStatus();
};
struct TTH
{
    static int GetTraitID(const char*);
};
TileH* __fastcall _ref_00726070(MenuH*);
// @fnv 0x0070c4a0
void FUN_0070c4a0_shell::UpdateInterface()
{
    AMC imenuType(0xd, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp", 0x47a);
    DAT_011d8a54 = DAT_011d8a6c;
    DAT_011d8a84 = !FUN_009f996e(0, &DAT_011d8a6c);
    static bool sbPadConnected = DAT_011d8a84;
    if (sbPadConnected != DAT_011d8a84)
    {
        if (sbPadConnected == true)
        {
            IFH::ShowButtonDialog(g_011d49b4.Get(), 0, 0, 0, 0, 0x17, 0.0f, 0.0f, g_011d38b8.Get(), 0);
        }
        else
        {
            IFH::ShowButtonDialog(g_011d2760.Get(), 0, 0, 0, 0, 0x17, 0.0f, 0.0f, g_011d38b8.Get(), 0);
        }
        ((IMX*)this)->UpdateControllerState(DAT_011d8a84);
        sbPadConnected = DAT_011d8a84;
    }
    if (((IMX*)this)->bc8)
    {
        ((IMX*)this)->FUN_00717660();
    }
    ConsoleManager* pCurrentConsoleManager = 0;
    Ctl* pcontrols = (Ctl*)g_osGlobals->FUN_00877720();
    int itmpX = 0;
    int itmpY = 0;
    itmpX = pcontrols->FUN_00a239e0(1);
    itmpY = pcontrols->FUN_00a239e0(2);
    if (FUN_004b71d0())
    {
        if (!IFH::IsConsoleActive())
        {
            ((IMX*)this)->b7d = false;
            ((IMX*)this)->t28->FUN_0056c7f0()->SetAppCulled(true);
            ((IMX*)this)->t28->Set(0xfa3, 0);
        }
        else
        {
            ((IMX*)this)->b7d = true;
            ((IMX*)this)->t28->FUN_0056c7f0()->SetAppCulled(false);
            ((IMX*)this)->t28->Set(0xfa3, 1);
        }
    }
    else if (((IMX*)this)->mode != 1)
    {
        ((IMX*)this)->b7d = true;
        ((IMX*)this)->t28->FUN_0056c7f0()->SetAppCulled(false);
        ((IMX*)this)->t28->Set(0xfa3, 1);
    }
    bool bmenuModeButtonDisabled =
        !InterfaceManager::IsInterfaceMenuActive() ||
        (FUN_004b71d0() && (IFH::GetSelectedTargetIndex(0x40b) || IFH::GetSelectedTargetIndex(0x425))) ||
        (IFH::GetSelectedTargetIndex(0x3ea) && FUN_0070ed30()) || (IsStatsMenuActive() && DAT_011d8a84) ||
        FindMenuById(FUN_0070ede0());
    if (((IMX*)this)->p16c)
    {
        ((IMX*)this)->p16c->vf14();
    }
    if (FUN_0070ec50((char*)((IMX*)this)->GetPipboyManager()))
    {
        ((IMX*)this)->GetPipboyManager()->UpdateFade((float)((TG*)&g_timeGlobal)->GetSection());
    }
    ((IMX*)this)->o178.UpdateIfActive();
    ((IMX*)this)->o1dc.FUN_00800370();
    if (DAT_0119f530 != ((IMX*)this)->mode)
    {
        if (((IMX*)this)->mode == 1)
        {
            while (((S4b*)FUN_004b7210())->c21)
            {
                ((S4b*)FUN_004b7210())->c21--;
                AudH::GetSingleton()->FUN_0070bc00();
            }
            while (((S4b*)FUN_004b7210())->c20)
            {
                ((S4b*)FUN_004b7210())->c20--;
                FUN_0070bbc0(AudH::GetSingleton());
            }
            if (g_thePlayer->vf22c(false))
            {
                HUDH::UpdateVisibilityState(7);
            }
            else if (g_thePlayer->vf214())
            {
                HUDH::UpdateVisibilityState(1);
            }
            else if (FUN_00458030() != 0x18)
            {
                if (g_thePlayer->FUN_005a03f0(1))
                {
                    HUDH::UpdateVisibilityState(0xc);
                }
                else if (g_thePlayer->FUN_00950090())
                {
                    HUDH::UpdateVisibilityState(0x14);
                }
                else if (g_thePlayer->IsAlert() && !DAT_011f2250.GetFlags())
                {
                    HUDH::UpdateVisibilityState(0x16);
                }
                else if (DAT_011f2250.GetFlags() != 4)
                {
                    HUDH::UpdateVisibilityState(2);
                }
                else
                {
                    HUDH::UpdateVisibilityState(8);
                }
            }
        }
        else if (((IMX*)this)->mode == 5)
        {
            switch (GetTopEnterStackEntry())
            {
            case 0x3f1:
                HUDH::UpdateVisibilityState(6);
                break;
            case 0x420:
                HUDH::UpdateVisibilityState(7);
                break;
            case 1:
            case 0x13:
            case 0x3ea:
            case 0x3eb:
            case 0x3f6:
            case 0x3ff:
            case 0x40b:
            case 0x425:
                HUDH::UpdateVisibilityState(3);
                break;
            case 0x3f0:
                HUDH::UpdateVisibilityState(9);
                break;
            case 0x3ef:
                HUDH::UpdateVisibilityState(5);
                break;
            case 0x403:
            case 0x418:
                HUDH::UpdateVisibilityState(0xe);
                break;
            case 0x3e9:
                HUDH::UpdateVisibilityState(0x11);
                break;
            case 0x41f:
                HUDH::UpdateVisibilityState(0xf);
                break;
            case 0x421:
                HUDH::UpdateVisibilityState(0x10);
                break;
            case 0x424:
                HUDH::UpdateVisibilityState(0x12);
                break;
            case 0x432:
                HUDH::UpdateVisibilityState(0x13);
                break;
            case 0x438:
            case 0x439:
            case 0x43a:
            case 0x43b:
                HUDH::UpdateVisibilityState(0x19);
                break;
            default:
                HUDH::UpdateVisibilityState(4);
            }
        }
        DAT_0119f530 = ((IMX*)this)->mode;
    }
    if (FUN_00719ae0(this) && !((Ctl*)g_osGlobals->FUN_00877720())->SetHotkeyItem(2, 0) &&
        !((Ctl*)g_osGlobals->FUN_00877720())->SetHotkeyItem(3, 0) &&
        !((Ctl*)g_osGlobals->FUN_00877720())->SetHotkeyItem(0, 0) &&
        !((Ctl*)g_osGlobals->FUN_00877720())->SetHotkeyItem(1, 0))
    {
        ((IMX*)this)->FUN_00718930(0);
    }
    if (((IMX*)this)->mode == 1)
    {
        TileH* phud = (TileH*)FindMenuById(0x3ec);
        if (!phud)
        {
            phud = (TileH*)FUN_0076bfe0();
        }
        if (DAT_011d8904)
        {
            ((IMX*)this)->t28->Set(0xfcc, g_011d475c.Get(), true);
            ((IMX*)this)->t28->FUN_00a04640(1);
            DAT_011d8904 = false;
        }
        if (DAT_011d8905)
        {
            FUN_00784c80();
            DAT_011d8905 = false;
        }
        g_thePlayer->FUN_0095d090();
        g_thePlayer->ClearActorList();
    }
    if (((IMX*)this)->mode == 2 || ((IMX*)this)->mode == 5)
    {
        if (FUN_004b71d0() && !((IMX*)this)->b7d)
        {
            if (!IFH::IsConsoleActive())
            {
                ((IMX*)this)->bed = false;
            }
        }
        else if (IFH::IsInterfaceActive() && !FUN_0070edf0())
        {
            ((IMX*)this)->t28->FUN_0056c7f0()->SetAppCulled(true);
            ((IMX*)this)->t28->Set(0xfa3, 0);
        }
        else
        {
            ((IMX*)this)->t28->FUN_0056c7f0()->SetAppCulled(false);
            ((IMX*)this)->t28->Set(0xfa3, 1);
        }
        ((IMX*)this)->FUN_007118d0();
        if (!((IMX*)this)->bed)
        {
            if (!((IMX*)this)->GetFieldBC() || !((IMX*)this)->GetFieldBC()->IsVisible() ||
                !((IMX*)this)->GetFieldBC()->ContainsTrait(0xfaf))
            {
                ((IMX*)this)->UpdateFocusTarget();
            }
        }
        int imouse_down = 0;
        int imouse_up = 0;
        int imouse_held = 0;
        if (!FUN_004b71d0() || ((IMX*)this)->b7d)
        {
            imouse_down = pcontrols->FUN_00a23a50(0, 1);
            imouse_up = pcontrols->FUN_00a23a50(0, 2);
            imouse_held = pcontrols->FUN_00a23a50(0, 0);
            if (imouse_held)
            {
                ((IMX*)this)->f48 += ((TG*)&g_timeGlobal)->GetStoredFloatValue();
            }
            else
            {
                ((IMX*)this)->f48 = 0;
            }
        }
        else if (ConsoleManager::Instance(true)->IsConsoleActive())
        {
            imouse_down = pcontrols->SetHotkeyItem(5, 1);
            imouse_up = pcontrols->SetHotkeyItem(5, 2);
            imouse_held = pcontrols->SetHotkeyItem(5, 0);
            if (imouse_held)
            {
                ((IMX*)this)->f48 += ((TG*)&g_timeGlobal)->GetStoredFloatValue();
            }
            else
            {
                ((IMX*)this)->f48 = 0;
            }
        }
        ((IMX*)this)->f44 = (float)pcontrols->FUN_00a239e0(3);
        if (FUN_004b71d0() || (!FUN_004b71d0() && ((IMX*)this)->bed))
        {
            TileH* pover_target = ((IMX*)this)->FUN_007126c0(0);
            MenuH* pover_menu = 0;
            if (pover_target)
            {
                pover_menu = pover_target->GetMenu();
                if ((!FUN_004b71d0() || ((IMX*)this)->b7d) && ((IMX*)this)->tbc)
                {
                    ((IMX*)this)->tbc->Set(0xfc3, 0);
                    ((IMX*)this)
                        ->FUN_00717ef0(((IMX*)this)->tbc->GetMenu(), (int)((IMX*)this)->tbc->GetFloat(0xfaa),
                                       ((IMX*)this)->tcc);
                    ((IMX*)this)->tbc = 0;
                }
            }
            if ((!FUN_004b71d0() || ((IMX*)this)->b7d) && ((IMX*)this)->t4c)
            {
                NP2 CursorMenuPos(((IMX*)this)->f38 / GetRatio(), ((IMX*)this)->f40 / GetRatio());
                if (InterfaceManager::IsInterfaceMenuActive())
                {
                    CursorMenuPos.x = CursorMenuPos.x / FUN_00717860() - 195.0;
                    CursorMenuPos.y = CursorMenuPos.y / FUN_00717860() - 195.0;
                }
                ((IMX*)this)->SetMode((int)(CursorMenuPos.x - ((IMX*)this)->t4c->GetFloat(0xfea)));
                ((IMX*)this)->AddDeferredHideLimb((int)(CursorMenuPos.y - ((IMX*)this)->t4c->GetFloat(0xfeb)));
                ((IMX*)this)
                    ->t4c->Set(0xff0,
                               CursorMenuPos.x -
                                   (((IMX*)this)->t4c->GetTotalFloat() - ((IMX*)this)->t4c->GetFloat(0xfa1)),
                               true);
                ((IMX*)this)
                    ->t4c->Set(0xff1,
                               CursorMenuPos.y -
                                   (((IMX*)this)->t4c->GetAccumulatedFloat() - ((IMX*)this)->t4c->GetFloat(0xfa2)),
                               true);
            }
            if (pover_target != ((IMX*)this)->tcc && imouse_held)
            {
                if (((IMX*)this)->md8 && ((IMX*)this)->md8->GetThreadID() == 1)
                {
                    ((IMX*)this)
                        ->md8->vf1c((int)((IMX*)this)->td4->GetFloat(0xfaa), ((IMX*)this)->td4, ((IMX*)this)->tcc);
                }
                ((IMX*)this)->td4 = pover_target;
                ((IMX*)this)->md8 = pover_menu;
                if (((IMX*)this)->md8 && ((IMX*)this)->md8->GetThreadID() == 1)
                {
                    ((IMX*)this)
                        ->md8->vf18((int)((IMX*)this)->td4->GetFloat(0xfaa), ((IMX*)this)->td4, ((IMX*)this)->tcc);
                }
            }
            if (imouse_up)
            {
                if (((IMX*)this)->md0 && ((IMX*)this)->td4 == ((IMX*)this)->tcc &&
                    ((IMX*)this)->tcc->FindTraitValue(0xfaa) && ((IMX*)this)->md0->GetThreadID() == 1)
                {
                    ((IMX*)this)->tcc->FUN_00a0b110(0xfcb);
                    TileH* ptarget = ((IMX*)this)->tcc;
                    MenuH* pmenu = ((IMX*)this)->md0;
                    if (ptarget)
                    {
                        ptarget->Set(0xfc7, 1);
                        ptarget->Set(0xfc7, 0);
                        if (pmenu)
                        {
                            pmenu->vf0c((int)ptarget->GetFloat(0xfaa), ptarget);
                        }
                    }
                    if (!((IMX*)this)->tcc)
                    {
                        pover_target = 0;
                        pover_menu = 0;
                    }
                }
                ((IMX*)this)->td4 = 0;
                ((IMX*)this)->md8 = 0;
                if (((IMX*)this)->t4c)
                {
                    ((IMX*)this)->t4c->Set(0xfea, -1);
                    ((IMX*)this)->t4c->Set(0xfeb, -1);
                    ((IMX*)this)->t4c = 0;
                }
            }
            if (pover_target != ((IMX*)this)->tcc && !imouse_held && (!FUN_004b71d0() || ((IMX*)this)->b7d))
            {
                if (((IMX*)this)->md0 && ((IMX*)this)->md0->GetThreadID() == 1)
                {
                    ((IMX*)this)->tcc->Set(0xfc3, 0);
                    if (((IMX*)this)->tcc->lst.Find(pover_target, 0))
                    {
                        ((IMX*)this)->md0->vf14((int)((IMX*)this)->tcc->GetFloat(0xfaa), ((IMX*)this)->tcc);
                    }
                    else
                    {
                        ((IMX*)this)
                            ->FUN_00717ef0(((IMX*)this)->md0, (int)((IMX*)this)->tcc->GetFloat(0xfaa),
                                           ((IMX*)this)->tcc);
                    }
                }
                if (pover_menu && pover_menu->GetThreadID() == 1)
                {
                    ((IMX*)this)->tcc = pover_target;
                    ((IMX*)this)->md0 = pover_menu;
                }
                else
                {
                    ((IMX*)this)->tcc = 0;
                    ((IMX*)this)->md0 = 0;
                }
                if (((IMX*)this)->md0 && ((IMX*)this)->md0->GetThreadID() == 1)
                {
                    if (!FUN_004b71d0() || ((IMX*)this)->b7d)
                    {
                        ((IMX*)this)->tbc = ((IMX*)this)->tcc;
                    }
                    ((IMX*)this)->tcc->FUN_00a0b110(0xfe8);
                    ((IMX*)this)->tcc->Set(0xfc3, 1);
                    ((IMX*)this)
                        ->FUN_00717e70(((IMX*)this)->md0, (int)((IMX*)this)->tcc->GetFloat(0xfaa), ((IMX*)this)->tcc);
                }
                if (((IMX*)this)->bed)
                {
                    ((IMX*)this)->ResetFieldBC();
                }
            }
        }
        if (!FUN_004b71d0() || ((IMX*)this)->b7d)
        {
            if (!((IMX*)this)->GetActiveRenderedMenu())
            {
                ((IMX*)this)->b4b4 = false;
            }
            if (((IMX*)this)->GetActiveRenderedMenu() != (void*)((IMX*)this)->GetPipboyManager())
            {
                ((IMX*)this)->b170 = ((IMX*)this)->bed && ((IMX*)this)->p16c && !PCS::UpdatePlayerStatus() &&
                                     !IFH::GetSelectedTargetIndex(0x3e9) && !IFH::GetSelectedTargetIndex(0x41b) &&
                                     !IFH::GetSelectedTargetIndex(0x423) &&
                                     ((IMX*)this)->p16c->vf18(imouse_up > 0, &((IMX*)this)->i4ac, &((IMX*)this)->i4b0);
            }
            else
            {
                ((IMX*)this)->b170 = ((IMX*)this)->bed && ((IMX*)this)->p16c && !PCS::UpdatePlayerStatus() &&
                                     !IFH::GetSelectedTargetIndex(0x3e9) && !IFH::GetSelectedTargetIndex(0x41b) &&
                                     ((IMX*)this)->b4b4;
                if (((IMX*)this)->i4b8 > 0)
                {
                    SndH psoundHand;
                    psoundHand = AudH::GetSingleton()->GetSoundHandleByEditorID("UIMenuMode", 0x121);
                    switch (((IMX*)this)->i4b8)
                    {
                    case 1:
                        psoundHand.Play(false);
                        ShowStatsMenu(1, 0);
                        break;
                    case 2:
                        psoundHand.Play(false);
                        FUN_007048f0(1, 0, 1);
                        break;
                    case 3:
                        psoundHand.Play(false);
                        UpdatePipboyMapVisibility(1, 0);
                        break;
                    default:
                        psoundHand.PausePlayback();
                    }
                }
            }
        }
        if (((IMX*)this)->bed && imouse_down)
        {
            if (((IMX*)this)->tcc && ((IMX*)this)->md0 && ((IMX*)this)->md0->GetThreadID() == 1)
            {
                ((IMX*)this)->td4 = ((IMX*)this)->tcc;
                ((IMX*)this)->md8 = ((IMX*)this)->md0;
                ((IMX*)this)->md0->vf08((int)((IMX*)this)->tcc->GetFloat(0xfaa), ((IMX*)this)->tcc);
                if (((IMX*)this)->tcc && ((IMX*)this)->tcc->ContainsTrait(0xfe9))
                {
                    ((IMX*)this)->t4c = ((IMX*)this)->tcc;
                    NP2 CursorMenuPos(((IMX*)this)->f38 / GetRatio(), ((IMX*)this)->f40 / GetRatio());
                    float ftileX = ((IMX*)this)->t4c->GetTotalFloat();
                    float ftileY = ((IMX*)this)->t4c->GetAccumulatedFloat();
                    if (InterfaceManager::IsInterfaceMenuActive())
                    {
                        CursorMenuPos.x = CursorMenuPos.x / FUN_00717860() - 195.0;
                        CursorMenuPos.y = CursorMenuPos.y / FUN_00717860() - 195.0;
                    }
                    ((IMX*)this)->i50 = (int)CursorMenuPos.x;
                    ((IMX*)this)->i5c = (int)CursorMenuPos.y;
                    ((IMX*)this)->SetMode(0);
                    ((IMX*)this)->AddDeferredHideLimb(0);
                    ((IMX*)this)
                        ->t4c->Set(0xff0, CursorMenuPos.x - (ftileX - ((IMX*)this)->t4c->GetFloat(0xfa1)), true);
                    ((IMX*)this)
                        ->t4c->Set(0xff1, CursorMenuPos.y - (ftileY - ((IMX*)this)->t4c->GetFloat(0xfa2)), true);
                    ((IMX*)this)->t4c->Set(0xfea, ((IMX*)this)->i50);
                    ((IMX*)this)->t4c->Set(0xfeb, ((IMX*)this)->i5c);
                    ((IMX*)this)->t4c->Set(0xfec, CursorMenuPos.x - ftileX, true);
                    ((IMX*)this)->t4c->Set(0xfed, CursorMenuPos.y - ftileY, true);
                    ((IMX*)this)->f54 = 0;
                    ((IMX*)this)->f58 = 0;
                }
            }
            else if (ConsoleManager::Instance(true)->IsConsoleActive())
            {
                ((IMX*)this)->UpdatePickObjects();
                ((IMX*)this)->DrawDebugInfo();
            }
        }
        if (imouse_held)
        {
            if (((IMX*)this)->md0)
            {
                ((IMX*)this)->md0->vf20((int)((IMX*)this)->tcc->GetFloat(0xfaa), ((IMX*)this)->tcc);
            }
            if (((IMX*)this)->md8 && ((IMX*)this)->tcc)
            {
                ((IMX*)this)->md8->vf24((int)((IMX*)this)->tcc->GetFloat(0xfaa), ((IMX*)this)->tcc);
            }
            if (((IMX*)this)->t4c)
            {
                ((IMX*)this)->t4c->Set(0xfee, (float)((IMX*)this)->GetInterval() - ((IMX*)this)->f54, true);
                ((IMX*)this)->t4c->Set(0xfef, (float)((IMX*)this)->GetEffectID() - ((IMX*)this)->f58, true);
                ((IMX*)this)->f54 = (float)((IMX*)this)->GetInterval();
                ((IMX*)this)->f58 = (float)((IMX*)this)->GetEffectID();
            }
        }
        else if (((IMX*)this)->f44 != 0.0)
        {
            if (((IMX*)this)->md0)
            {
                TileH* ptarget = ((IMX*)this)->tcc;
                while (!ptarget->ContainsTrait(0xff2) && ptarget->GetNext())
                {
                    ptarget = (TileH*)ptarget->GetNext();
                }
                if (ptarget && ptarget->ContainsTrait(0xff2))
                {
                    ptarget->Set(0xff3, ((IMX*)this)->FUN_0070ec70() / -120);
                    ptarget->Set(0xff3, 0);
                    ((IMX*)this)->FUN_00718080(((IMX*)this)->md0, (int)ptarget->GetFloat(0xfaa), ptarget);
                }
            }
            else if (ConsoleManager::Instance(true)->IsConsoleActive())
            {
                ((IMX*)this)->i78 += (((IMX*)this)->FUN_0070ec70() >= 0) ? 1 : -1;
                if (((IMX*)this)->i78 < -1)
                {
                    ((IMX*)this)->i78 = ((IMX*)this)->l70.GetSize() - 1;
                }
                else if ((unsigned int)((IMX*)this)->i78 > ((IMX*)this)->l70.GetSize() - 1)
                {
                    ((IMX*)this)->i78 = -1;
                }
                ((IMX*)this)->DrawDebugInfo();
            }
        }
        if (FUN_004b71d0() && !((IMX*)this)->b7d)
        {
            ((IMX*)this)->HandleGamepadButton(0);
        }
        {
            int iraw_key = 0;
            int iis_down = ((Ctl*)g_osGlobals->FUN_00877720())->FUN_00a23820(&iraw_key);
            while (iis_down == 2)
            {
                ((IMX*)this)->FUN_007166f0(0);
                ((IMX*)this)->HandleKeyEvent(iis_down, iraw_key);
                iis_down = ((Ctl*)g_osGlobals->FUN_00877720())->FUN_00a23820(&iraw_key);
            }
            int ikey = ((IMX*)this)->HandleKeyEvent(iis_down, iraw_key);
            if (!ikey)
            {
                ikey = ((IMX*)this)->FUN_00716730(1.0f);
            }
            bool bConsoleUsed = false;
            pCurrentConsoleManager = ConsoleManager::Instance(false);
            if (ikey && pCurrentConsoleManager)
            {
                do
                {
                    if (iraw_key == 0x29)
                    {
                        bConsoleUsed = false;
                    }
                    else
                    {
                        bConsoleUsed = ((MCH*)pCurrentConsoleManager)->Idle(ikey);
                    }
                    if (bConsoleUsed)
                    {
                        iis_down = ((Ctl*)g_osGlobals->FUN_00877720())->FUN_00a23820(&iraw_key);
                        while (iis_down == 2)
                        {
                            ((IMX*)this)->FUN_007166f0(0);
                            ((IMX*)this)->HandleKeyEvent(iis_down, iraw_key);
                            iis_down = ((Ctl*)g_osGlobals->FUN_00877720())->FUN_00a23820(&iraw_key);
                        }
                        ikey = ((IMX*)this)->HandleKeyEvent(iis_down, iraw_key);
                    }
                } while (ikey && bConsoleUsed);
            }
            if (!ikey && (!FUN_004b71d0() || ((IMX*)this)->b7d) && pcontrols->SetHotkeyItem(0x1c, 1) &&
                IFH::GetSelectedTargetIndex(0x3e9))
            {
                ikey = 1;
                pcontrols->FUN_0070ec20(0x1c, 0);
            }
            if (ikey && !bConsoleUsed)
            {
                bool bused = false;
                MenuH* pmenu = MMH::Instance(true)->GetFrontmostMenu();
                bool bremappedPipboyKeyUsed = InterfaceManager::IsInterfaceMenuActive() &&
                                              (((Ctl*)g_osGlobals->FUN_00877720())->SetHotkeyItem(0xe, 1) ||
                                               ((Ctl*)g_osGlobals->FUN_00877720())->SetHotkeyItem(0xe, 2)) &&
                                              !((Ctl*)g_osGlobals->FUN_00877720())->HandleHotkeyInput(0xf, 0);
                if (pmenu && !bremappedPipboyKeyUsed)
                {
                    bused = pmenu->vf30(ikey);
                }
                if (!bused && pmenu && !bremappedPipboyKeyUsed)
                {
                    TileH* prefTile = 0;
                    char strName[16];
                    _sprintf_s(strName, 0x10, "%s%c", "_PCButton_",
                               ((Ctl*)g_osGlobals->FUN_00877720())->FUN_00a238a0(iraw_key, 0xff));
                    prefTile = _ref_00726070(pmenu)->GetNamedChild(
                        _ref_00726070(pmenu)->FUN_00a011f0(TTH::GetTraitID(strName)));
                    if (prefTile && prefTile->ContainsTrait(0xfa3))
                    {
                        if (prefTile->ContainsTrait(0xfaf))
                        {
                            prefTile->FUN_00a0b110(0xfcb);
                            prefTile->Set(0xfc7, 1);
                            prefTile->Set(0xfc7, 0);
                            pmenu->vf0c((int)prefTile->GetFloat(0xfaa), prefTile);
                        }
                        else
                        {
                            FUN_00717280(2);
                        }
                    }
                }
                if (!bused)
                {
                    int itype = 0;
                    switch (ikey)
                    {
                    case (int)0x80000003:
                        itype = 1;
                        break;
                    case (int)0x80000004:
                        itype = 2;
                        break;
                    case (int)0x80000001:
                        itype = 4;
                        break;
                    case (int)0x80000002:
                        itype = 3;
                        break;
                    case (int)0x80000009:
                        itype = 0xf;
                        break;
                    case (int)0x8000000a:
                        itype = 0x10;
                        break;
                    case (int)0x80000008:
                        if (((IMX*)this)->IsFlag4Set())
                        {
                            itype = 0xb;
                        }
                        else if (FUN_0070ecd0((unsigned int*)this))
                        {
                            itype = 0xc;
                        }
                        else
                        {
                            itype = -2;
                        }
                        break;
                    default:
                        itype = 0;
                    }
                    if (itype == 4 && ((IMX*)this)->IsFlag4Set())
                    {
                        itype = 0xd;
                    }
                    if (itype == 3 && ((IMX*)this)->IsFlag4Set())
                    {
                        itype = 0xe;
                    }
                    if (itype)
                    {
                        ((IMX*)this)->HandleGamepadButton(itype);
                        pcontrols->FUN_00a237b0();
                    }
                }
            }
        }
        if (pcontrols->SetHotkeyItem(0x19, 1) && !FUN_0070edf0())
        {
            IFH::ShowMessage(g_011d4cb4.Get(), 0, g_011cba18_arg1, 0, 2.0f, false);
        }
        if (pcontrols->SetHotkeyItem(0x1a, 1) && !FUN_0070edf0())
        {
            IFH::ShowMessage(g_011d3fd0.Get(), 0, g_011cba18_arg1, 0, 2.0f, false);
        }
    }
    bool tempMemContext = false;
    if (FUN_0070ed10())
    {
        FUN_0070ed20(0);
        if (!ConsoleManager::Instance(true)->IsConsoleActive())
        {
            tempMemContext = true;
        }
    }
    if (pcontrols->SetHotkeyItem(0x1d, 1) || tempMemContext)
    {
        pCurrentConsoleManager = ConsoleManager::Instance(true);
        pcontrols->FUN_00a237b0();
        if (((MCH*)pCurrentConsoleManager)->FUN_0071d580())
        {
            ((IMX*)this)->PushMenuStackEntry(3);
        }
        else
        {
            ((IMX*)this)->AddMenuStackEntry(3, false);
        }
    }
    if (pcontrols->SetHotkeyItem(0x1c, 1) && !MMH::Instance(true)->IsMenuClassVisible(0x3ef) && !FUN_0070edf0() &&
        (((IMX*)this)->i4bc == 3 || ((IMX*)this)->i4bc == 0))
    {
        if (PCS::UpdatePlayerStatus() && IFH::GetSelectedTargetIndex(0x3f5) && FUN_007024e0())
        {
            if (GetTopEnterStackEntry() == FUN_0070ede0() && !IsBothFlagsSet())
            {
                CloseStartMenu(1);
            }
        }
        else if (DAT_0119f348)
        {
            if (*g_011c3ea4.Int() == 1)
            {
                SMH::Create(true, false);
            }
            else if (!FUN_0070ec00())
            {
                FUN_00709470(6, 0, 0, 0, 1, 0);
            }
        }
    }
    FUN_00a0df80();
    bool bDidFindMatch = false;
    DAT_011d8a85 = 0;
    if (!bDidFindMatch)
    {
        void* xelem = (void*)((IMX*)this)->t9c->lst.Head();
        while (xelem && !DAT_011d8a85)
        {
            TileH* ptile = ((IMX*)this)->t9c->lst.GetNext(xelem);
            if (ptile)
            {
                MenuH* pmenu = ptile->GetMenu();
                if (pmenu)
                {
                    pmenu->vf2c();
                }
            }
        }
    }
    else if (DLGH::IsInDialog())
    {
        SetDialogMenuActive(1);
    }
    if (DAT_011d8a85)
    {
        DAT_011d8a85 = 0;
        return;
    }
    bool ikeyMenu = false;
    if (((IMX*)this)->i4bc == 3)
    {
        if (FUN_004b71d0())
        {
            ikeyMenu = (FUN_00717a40(0xa, 1) == 1 || FUN_00717a40(6, 1) == 1) && !bmenuModeButtonDisabled;
        }
        else
        {
            ikeyMenu = pcontrols->SetHotkeyItem(0xe, 2) && !bmenuModeButtonDisabled;
        }
    }
    else
    {
        ikeyMenu = FUN_0070edc0((char*)g_thePlayer);
    }
    if (ikeyMenu && ((IMX*)this)->i4bc == 0)
    {
        ((IMX*)this)->QueueHudCallback(0, 0);
    }
    else if (DAT_011f2250.GetFlags() || g_thePlayer->vf22c(false) || ikeyMenu)
    {
        if (!FUN_004b71d0() || !((IMX*)this)->b7d)
        {
            switch (((IMX*)this)->i4bc)
            {
            case 1:
            case 2:
            case 3:
                ((IMX*)this)->HandleCallbackOrStore(0);
                ((Ctl*)g_osGlobals->FUN_00877720())->FUN_00a253d0();
                break;
            }
        }
    }
    int bskipIdle = 0;
    bool itab = false;
    if (pcontrols->HandleHotkeyInput(0x3b, 1))
    {
        bskipIdle = 0x3eb;
        itab = true;
    }
    else if (pcontrols->HandleHotkeyInput(0x3c, 1))
    {
        bskipIdle = 0x3ea;
        itab = true;
    }
    else if (pcontrols->HandleHotkeyInput(0x3d, 1))
    {
        bskipIdle = 0x3ff;
        itab = true;
    }
    if (itab && ((IMX*)this)->i4bc == 0)
    {
        ((IMX*)this)->QueueHudCallback(0, bskipIdle);
    }
    if (itab && ((IMX*)this)->i4bc == 3)
    {
        if (((IMX*)this)->FUN_00586150()->GetFloat(0x1771) != bskipIdle)
        {
            switch (bskipIdle)
            {
            case 0x3ea:
                FUN_007048f0(1, 0, 1);
                break;
            case 0x3eb:
                ShowStatsMenu(1, 0);
                break;
            case 0x3ff:
                UpdatePipboyMapVisibility(1, 0);
                break;
            }
        }
        else
        {
            ((IMX*)this)->HandleCallbackOrStore(0);
        }
    }
    if (!GetTopEnterStackEntry() || InterfaceManager::IsInterfaceMenuActive())
    {
        ((IMX*)this)->UpdatePipboyWaiver();
    }
    ((IMX*)this)->o4d4.FUN_007182e0();
}
}  // namespace fnv_0070c4a0

void* __cdecl operator new(unsigned int);
struct Scratch
{
    int a;
    int b;
    int c;
    int d;
};
int __stdcall FUN_009f996e(int, Scratch*);
struct UIRoot
{
    char pad[0x20];
    bool flagA;
    bool flagB;
    char pad2[0x580 - 0x22];
    UIRoot();
    void InitInterface(bool);
    void FUN_0070b240();
};
extern UIRoot* DAT_011d8a80;
extern bool DAT_011d8a84;
// Checks FUN_009f996e into DAT_011d8a84, lazily creates DAT_011d8a80, runs stage 1 or 2 on it, then clears flagA and flagB.
// @fnv 0x00709fd0
void __cdecl InitUIRoot(unsigned int uiStage, bool abInitialLoad)
{
    Scratch buf;
    DAT_011d8a84 = FUN_009f996e(0, &buf) == 0;
    if (!DAT_011d8a80)
        DAT_011d8a80 = new UIRoot;
    if (uiStage == 1)
        DAT_011d8a80->InitInterface(abInitialLoad);
    else if (uiStage == 2)
        DAT_011d8a80->FUN_0070b240();
    DAT_011d8a80->flagA = false;
    DAT_011d8a80->flagB = false;
}

namespace fnv_0070a130 {
namespace lc1 {
class AutoMemContext
{
  public:
    AutoMemContext(int aeContext, bool abEnter, const char* apFile, int aiLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}

template <class T> class NiPointer
{
  public:
    NiPointer(T* apObject = 0);
    ~NiPointer();
    NiPointer& operator=(T* apObject);
    operator T*() const;
    T* operator->() const;
    T* m_pObject;
};

struct P3
{
    float x, y, z;
    P3();
    P3(float afX, float afY, float afZ);
};

struct SL
{
    void* m_item;
    SL* m_pNext;
    SL();
    ~SL();
};

class MenuAlphaProperty
{
  public:
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
    MenuAlphaProperty();
    void FUN_0049ed90(bool abEnable);
    void FUN_00636000(bool abEnable);
    void FUN_00439340(int aeMode);
    void FUN_00439390(int aeMode);
    char m_data[0x1c];
};

class BSShaderAccumulator
{
  public:
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
    BSShaderAccumulator(int aeMode, unsigned int auiA, unsigned int auiB);
    void FUN_004a1040(int aiValue);
    void FUN_0070a900(bool abValue);
    char m_data[0x280];
};

struct MenuSystem
{
    static MenuSystem* Instance(bool abCreate);
};

class ShadowLightData
{
  public:
    ShadowLightData();
    ~ShadowLightData();
    char m_data[0x64];
};

class Obj007ffec0
{
  public:
    Obj007ffec0();
    ~Obj007ffec0();
    char m_data[0x2d0];
};

class Obj0070a8e0
{
  public:
    Obj0070a8e0();
    ~Obj0070a8e0();
    int m_data;
};

class Obj006319e0
{
  public:
    Obj006319e0();
    char m_data[0xc];
};

class Obj0070a8a0
{
  public:
    Obj0070a8a0();
    int m_00[3];
    Obj0070a8a0* m_pSelf;
    int m_10;
};

class TimeGlobal
{
  public:
    int GetSection();
};
extern TimeGlobal g_timeGlobal;

void* __stdcall FUN_005bac60(const char* apName, int aiFlag);
void* __stdcall FUN_005bac70(const char* apName, int aiFlag);
float __cdecl FUN_004e44b0(float afAngle);
float __cdecl cos(float afAngle);

extern const float DAT_0106ef4c;
extern char DAT_011d8a50;
extern int DAT_011d8a64;
extern float DAT_011d8a68;

class InterfaceManager_FUN_0070a130
{
  public:
    bool m_00;
    bool m_01;
    NiPointer<NiNode> m_pRenderedMenuObject;
    NiPointer<NiNode> spMenu3DRoot;
    int m_0c;
    bool m_10;
    bool m_11;
    unsigned char m_12;
    unsigned char m_13;
    unsigned char m_14;
    unsigned char m_15;
    int m_18;
    int m_1c[2];
    int m_24;
    int m_28;
    P3 m_2c;
    P3 m_38;
    float m_44;
    float m_48;
    int m_4c;
    int m_50;
    int m_54[2];
    int m_5c;
    int m_60;
    int m_64;
    int m_68[2];
    SL m_70;
    int m_78;
    char m_7c;
    bool m_7d;
    int m_80;
    int m_84;
    int m_88;
    NiPointer<BSShaderAccumulator> spAccum8c;
    NiPointer<BSShaderAccumulator> spAccum90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    float m_a8;
    NiPointer<MenuAlphaProperty> spAlpha;
    short m_b0;
    short m_b2;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    bool m_c8;
    bool m_c9;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    char m_dc;
    bool m_dd;
    char m_de[6];
    unsigned char m_e4;
    int m_e8;
    bool m_ec;
    bool m_ed;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    P3 m_104;
    bool m_110;
    int m_114[10];
    Obj006319e0* m_13c;
    int m_140[2];
    bool m_148;
    bool m_149;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    Obj0070a8a0* m_164;
    bool m_168;
    int m_16c;
    bool m_170;
    int m_174;
    ShadowLightData m_178;
    Obj007ffec0 m_1dc;
    float m_4ac;
    float m_4b0;
    int m_4b4;
    int m_4b8;
    int m_4bc;
    int m_4c0;
    SL m_4c4;
    bool m_4cc;
    bool m_4cd;
    float m_4d0;
    Obj0070a8e0 m_4d4;

    InterfaceManager_FUN_0070a130();
    NiNode* FUN_00712e90(void* apNode);
};

// @fnv 0x0070a130
InterfaceManager_FUN_0070a130::InterfaceManager_FUN_0070a130()
{
    lc1::AutoMemContext tempMemContext(
        0xd, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp", 0x11d);
    m_4d0 = 1.0f;
    m_00 = false;
    m_01 = false;
    m_80 = 0;
    m_84 = 0;
    m_88 = 0;
    m_9c = 0;
    m_a4 = 0;
    m_104 = P3(0.0f, 0.0f, 0.0f);
    m_110 = false;
    m_fc = 0;
    m_100 = 0;
    m_f0 = 0;
    m_f4 = 0;
    m_f8 = 0;
    m_24 = 0;
    m_a8 = 0.0f;
    m_0c = 1;
    m_11 = false;
    m_10 = false;
    m_12 = 0xff;
    m_13 = 0xff;
    m_14 = 0xff;
    m_15 = 0xff;
    m_b2 = 0;
    m_bc = 0;
    m_cc = 0;
    m_d0 = 0;
    m_d4 = 0;
    m_d8 = 0;
    spAlpha = 0;
    m_18 = 0x50;
    m_44 = 0.0f;
    m_50 = 0;
    m_5c = 0;
    m_60 = 0;
    m_64 = 0;
    m_48 = 0.0f;
    m_28 = 0;
    m_149 = false;
    m_14c = 0;
    m_150 = 0;
    m_154 = 0;
    m_15c = 0;
    m_b4 = 0;
    m_b8 = 0;
    m_4c = 0;
    m_dd = false;
    m_e4 = 0xff;
    m_e8 = 0;
    m_ec = false;
    m_4cc = false;
    m_ed = true;
    m_c0 = 100;
    m_c9 = false;
    m_c8 = true;
    DAT_011d8a68 = 0.0f;
    DAT_011d8a50 = 0;
    DAT_011d8a64 = g_timeGlobal.GetSection();

    for (int a = 0; a < 10; a++)
        m_114[a] = 0;

    float m_fGlyphExtent = InterfaceManager::UpdateInterfaceState() / 2.0 / FUN_004e44b0(DAT_0106ef4c);
    m_a8 = cos(DAT_0106ef4c) * m_fGlyphExtent;

    if (!spAlpha)
    {
        spAlpha = new MenuAlphaProperty;
        spAlpha->FUN_0049ed90(true);
        spAlpha->FUN_00636000(false);
        spAlpha->FUN_00439340(6);
        spAlpha->FUN_00439390(7);
    }

    spMenu3DRoot = FUN_00712e90(FUN_005bac70("Menu3DRoot", 1));
    m_pRenderedMenuObject = FUN_00712e90(FUN_005bac60("MenuRoot", 0));

    MenuSystem::Instance(true);
    m_13c = new Obj006319e0;
    m_164 = new Obj0070a8a0;
    m_164->m_pSelf = m_164;
    m_4ac = 0.0f;
    m_4b0 = 0.0f;
    m_170 = false;
    m_168 = false;
    m_16c = 0;
    m_174 = 0;
    m_4bc = 0;
    m_4c0 = 0;
    m_94 = 0;

    spAccum8c = new BSShaderAccumulator(0x64, 1, 0x2f7);
    spAccum8c->FUN_004a1040(10);
    spAccum8c->FUN_0070a900(true);
    spAccum90 = new BSShaderAccumulator(0x63, 1, 0x2f7);
    m_148 = false;
    m_4b8 = 0;
    m_7d = false;
    m_4cd = false;
    m_78 = 0;
}
}  // namespace fnv_0070a130

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_0070adb0_shell : public InterfaceManager
{
    void InitInterface(bool);
};

namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}

void* __cdecl operator new(unsigned int);

struct NiUpdateDataH
{
    void FUN_0043d410(float, bool, bool);
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    const char* m_kHandle;
};

class NiAVObject : public NiMemObject
{
  public:
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
    void SetName(const NiFixedString&);
    void SetAppCulled(bool);
    void UpdateSceneObject();
    void Update(NiUpdateDataH&);
};

class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short);
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
    char pad[0xa8];
};

class BSFogProperty : public NiMemObject
{
  public:
    BSFogProperty();
    char pad[0x64];
};

template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* m_pObject;
};

class FUN_00709840
{
  public:
    FUN_00709840();
    virtual ~FUN_00709840();
    virtual void Init(Tile*, const char*, Tile*);
    char pad[0x38];
};

class FUN_007f7a70
{
  public:
    FUN_007f7a70();
    char pad[0x170];
};

struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TileH
{
    void Set(int, float, bool);
    Tile* ReadFile(const char*);
};
struct TileStandIn_009ff600
{
    void SetParent(Tile*, Tile*);
};
struct Tile_Helper
{
    static void UpdateAll(bool);
};
class Menu;
class TESForm;
struct MenuH
{
    static bool ReadMenuDefinition(const char*, Menu*);
};
struct InterfaceH
{
    static void SetQuestTarget(TESForm*, bool);
};
struct KFModel
{
    void* GetControllerSequence();
};
struct FUN_00703060_shell
{
    void FUN_00703060(bool);
};
struct Setting_S
{
    float* Float();
};
struct GlobalObject_0045cfe0
{
    void FUN_0045ce80(int);
};
struct Dummy_00718c90;

extern Setting_S g_011d3174;
extern GlobalObject_0045cfe0 g_011deec0;
extern GlobalObject_0045cfe0 g_011d8d44;
extern const double DAT_0106efa0;
extern const double DAT_010290b8;

void __cdecl FUN_009ff970();
double __cdecl FUN_00706e20();
double __cdecl FUN_00706e50();
float __cdecl FUN_00707b60();
float __cdecl FUN_00715da0();
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();
void __cdecl FUN_00a07690(Tile*);
Dummy_00718c90* __cdecl FUN_00718b60();
void __fastcall FUN_005bf9a0(BSFogProperty*, float, float);

// @fnv 0x0070adb0
void FUN_0070adb0_shell::InitInterface(bool abInitialLoad)
{
    float faspect;
    lc1::AutoMemContext tempMemContext(
        13, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp", 0x21a);
    NiNode* pscene_graph;
    NiUpdateDataH UpdateData1;

    if (abInitialLoad)
        FUN_009ff970();

    *(FUN_00709840**)((char*)this + 0x9c) = new FUN_00709840;
    (*(FUN_00709840**)((char*)this + 0x9c))->Init(0, "MenuRoot", 0);
    (*(Tile_Set_Helper**)((char*)this + 0x9c))->Set(0xfa8, 1);
    (*(Tile_Set_Helper**)((char*)this + 0x9c))->Set(0x1771, 0x3eb);
    (*(TileH**)((char*)this + 0x9c))->Set(0xfa9, 0.0f, true);
    (*(TileH**)((char*)this + 0x9c))->Set(0xfb1, InterfaceManager::UpdateInterfaceState(), true);
    (*(TileH**)((char*)this + 0x9c))->Set(0xfb0, FUN_00715da0(), true);
    (*(TileH**)((char*)this + 0x9c))->Set(0xfc0, FUN_007177c0(), true);
    (*(TileH**)((char*)this + 0x9c))->Set(0xfbf, FUN_00717820(), true);
    (*(TileH**)((char*)this + 0x9c))->Set(0xff8, FUN_00707b60(), true);
    FUN_00a07690(*(Tile**)((char*)this + 0x9c));
    Tile_Helper::UpdateAll(false);
    FUN_00718b60();
    *(Tile**)((char*)this + 0xa0) = (*(TileH**)((char*)this + 0x9c))->ReadFile("Data\\Menus\\globals.xml");
    MenuH::ReadMenuDefinition("Data\\Menus\\globals.xml", 0);
    (*(TileStandIn_009ff600**)((char*)this + 0xa0))->SetParent(0, 0);
    (*(TileH**)((char*)this + 0xa0))
        ->Set(Tile::GetTraitID("_background_fill_alpha"), *g_011d3174.Float() * 255.0, true);
    (*(Tile_Set_Helper**)((char*)this + 0xa0))->Set(Tile::GetTraitID("_Has360Controller"), FUN_004b71d0());

    *(NiNode**)((char*)this + 0xa4) = new NiNode(0);
    (*(NiNode**)((char*)this + 0xa4))->SetName(NiFixedString("InterfaceManager: DebugText Root"));
    (*(NiNode**)((char*)this + 0xa4))->SetAppCulled(false);
    (*(NiNode**)((char*)this + 0x80))->AttachChildInAvailableSlot(*(NiNode**)((char*)this + 0xa4), true);

    pscene_graph = ((Interface*)this)->GetRoot();
    pscene_graph->UpdateSceneObject();
    UpdateData1.FUN_0043d410(0.0f, false, false);
    pscene_graph->Update(UpdateData1);

    faspect = FUN_00706e50() / FUN_00706e20();
    if (faspect == DAT_0106efa0 || 1.0f / faspect == DAT_010290b8)
    {
        g_011deec0.FUN_0045ce80(0x50);
        g_011d8d44.FUN_0045ce80(0x50);
    }

    NiPointer<BSFogProperty> m_spFogProperty(new BSFogProperty);
    FUN_005bf9a0(m_spFogProperty, 0.0f, 0.0f);

    pscene_graph = (NiNode*)((KFModel*)this)->GetControllerSequence();
    ((FUN_00703060_shell*)this)->FUN_00703060(false);
    *(FUN_007f7a70**)((char*)this + 0x174) = new FUN_007f7a70;
    *(bool*)this = true;
    if (abInitialLoad)
        InterfaceH::SetQuestTarget(0, false);
}

struct NP
{
    void* p;
    NP& operator=(void*);
    ~NP();
};
struct FUN_007099b0
{
    bool FUN_00709a20();
};
struct ReleasableObject
{
    int fields[14];
    virtual ~ReleasableObject();
    void Release();
};
struct FUN_0070b6c0 : ReleasableObject
{
    NP a;
    NP b;
    ~FUN_0070b6c0();
};
// @fnv 0x0070b6c0
FUN_0070b6c0::~FUN_0070b6c0()
{
    b = 0;
    if (!reinterpret_cast<FUN_007099b0*>(this)->FUN_00709a20())
        Release();
}

namespace fnv_0070bc20 {
struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct NiStream;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_0070bc20_shell : public InterfaceManager
{
    void UpdateActivatePick();
};

struct NiAVObject;
struct bhkWorld;
struct NiCamera;

struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3& operator+=(const Vec3&);
    Vec3 operator+(const Vec3&) const;
    Vec3 operator*(float) const;
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    ThreeByThreeMatrix();
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
    void FUN_004a0c90(float);
    void FUN_00524ac0(float);
    void FUN_00439f50(unsigned int, Vec3&);
};

struct CollisionFilter
{
    unsigned int iFilter;
    CollisionFilter(int);
    void FUN_004a39f0(int);
    unsigned int FUN_004a3a20();
    void FUN_0059ce80(unsigned int);
};

struct NiPickRecord
{
    NiAVObject* FUN_00458b50();
    float GetDistance();
};

struct NiPickResults
{
    unsigned int GetEffectiveSize();
    NiPickRecord* GetAt(unsigned int);
};

struct NiPick
{
    unsigned int m_data[13];
    NiPick(int, int);
    ~NiPick();
    NiPickResults* GetResults();
};

struct TESForm
{
    unsigned char GetFormType();
};

struct TESObjectREFR
{
    static TESObjectREFR* __cdecl GetReferenceFromNiAVObject(NiAVObject*);
    TESForm* GetObjectReference();
};

struct TESObjectCELL
{
    bhkWorld* FUN_004543c0();
};

struct TESContainer
{
    static bool __cdecl IsValidContainerType(unsigned char);
};

struct HUDMainMenu
{
    static bool __cdecl UpdateTargetReference(TESObjectREFR*, bool, bool);
};

struct bhkCharacterController
{
    CollisionFilter FUN_0070c440();
};

struct PlayerCharacter
{
    virtual void Unk000();
    virtual void Unk001();
    virtual void Unk002();
    virtual void Unk003();
    virtual void Unk004();
    virtual void Unk005();
    virtual void Unk006();
    virtual void Unk007();
    virtual void Unk008();
    virtual void Unk009();
    virtual void Unk010();
    virtual void Unk011();
    virtual void Unk012();
    virtual void Unk013();
    virtual void Unk014();
    virtual void Unk015();
    virtual void Unk016();
    virtual void Unk017();
    virtual void Unk018();
    virtual void Unk019();
    virtual void Unk020();
    virtual void Unk021();
    virtual void Unk022();
    virtual void Unk023();
    virtual void Unk024();
    virtual void Unk025();
    virtual void Unk026();
    virtual void Unk027();
    virtual void Unk028();
    virtual void Unk029();
    virtual void Unk030();
    virtual void Unk031();
    virtual void Unk032();
    virtual void Unk033();
    virtual void Unk034();
    virtual void Unk035();
    virtual void Unk036();
    virtual void Unk037();
    virtual void Unk038();
    virtual void Unk039();
    virtual void Unk040();
    virtual void Unk041();
    virtual void Unk042();
    virtual void Unk043();
    virtual void Unk044();
    virtual void Unk045();
    virtual void Unk046();
    virtual void Unk047();
    virtual void Unk048();
    virtual void Unk049();
    virtual void Unk050();
    virtual void Unk051();
    virtual void Unk052();
    virtual void Unk053();
    virtual void Unk054();
    virtual void Unk055();
    virtual void Unk056();
    virtual void Unk057();
    virtual void Unk058();
    virtual void Unk059();
    virtual void Unk060();
    virtual void Unk061();
    virtual void Unk062();
    virtual void Unk063();
    virtual void Unk064();
    virtual void Unk065();
    virtual void Unk066();
    virtual void Unk067();
    virtual void Unk068();
    virtual void Unk069();
    virtual void Unk070();
    virtual void Unk071();
    virtual void Unk072();
    virtual void Unk073();
    virtual void Unk074();
    virtual void Unk075();
    virtual void Unk076();
    virtual void Unk077();
    virtual void Unk078();
    virtual void Unk079();
    virtual void Unk080();
    virtual void Unk081();
    virtual void Unk082();
    virtual void Unk083();
    virtual void Unk084();
    virtual void Unk085();
    virtual void Unk086();
    virtual void Unk087();
    virtual void Unk088();
    virtual void Unk089();
    virtual void Unk090();
    virtual void Unk091();
    virtual void Unk092();
    virtual void Unk093();
    virtual void Unk094();
    virtual void Unk095();
    virtual void Unk096();
    virtual void Unk097();
    virtual void Unk098();
    virtual void Unk099();
    virtual void Unk100();
    virtual void Unk101();
    virtual void Unk102();
    virtual void Unk103();
    virtual void Unk104();
    virtual void Unk105();
    virtual void Unk106();
    virtual void Unk107();
    virtual void Unk108();
    virtual void Unk109();
    virtual void Unk110();
    virtual void Unk111();
    virtual void Unk112();
    virtual void Unk113();
    virtual void Unk114();
    virtual void Unk115();
    virtual void Unk116();
    virtual void Unk117();
    virtual void Unk118();
    virtual void Unk119();
    virtual void Unk120();
    virtual void Unk121();
    virtual void Unk122();
    virtual void Unk123();
    virtual void Unk124();
    virtual Vec3* GetPos();
    virtual void Unk126();
    virtual void Unk127();
    virtual void Unk128();
    virtual void Unk129();
    virtual void Unk130();
    virtual void Unk131();
    virtual void Unk132();
    virtual void Unk133();
    virtual void Unk134();
    virtual void Unk135();
    virtual void Unk136();
    virtual void Unk137();
    virtual void Unk138();
    virtual void Unk139();
    virtual void Unk140();
    virtual void Unk141();
    virtual void Unk142();
    virtual void Unk143();
    virtual void Unk144();
    virtual void Unk145();
    virtual void Unk146();
    virtual void Unk147();
    virtual void Unk148();
    virtual void Unk149();
    virtual void Unk150();
    virtual void Unk151();
    virtual void Unk152();
    virtual void Unk153();
    virtual void Unk154();
    virtual void Unk155();
    virtual void Unk156();
    virtual void Unk157();
    virtual void Unk158();
    virtual void Unk159();
    virtual void Unk160();
    virtual void Unk161();
    virtual void Unk162();
    virtual void Unk163();
    virtual void Unk164();
    virtual void Unk165();
    virtual void Unk166();
    virtual void Unk167();
    virtual void Unk168();
    virtual void Unk169();
    virtual void Unk170();
    virtual void Unk171();
    virtual void Unk172();
    virtual void Unk173();
    virtual void Unk174();
    virtual float GetCurrentTargetDistance(int);
    Vec3* GetFieldAtOffsetDD4();
    float FUN_0070c3b0();
    float GetScale();
    bool FUN_00524d10();
    Vec3 GetPosition();
    float GetLooking();
    CollisionFilter GetVectorElement();
    bhkCharacterController* GetPhysicsCharacterController();
    TESObjectCELL* GetParentCell();
    bool FUN_0070c3d0();
};

struct ActivatePickHelper
{
    bool IsPatrolling();
    void FUN_00631ab0(float, unsigned int);
    bhkWorld* FUN_00621440();
    void FUN_00631ca0(bhkWorld*);
    unsigned int GetFlags();
    void FUN_00631c50(unsigned int);
    TESObjectREFR* FUN_00631d60(Vec3&, Vec3&, float, float*, int*);
};

struct TES
{
    bool ApplyToObject(NiPick&, Vec3&, Vec3&, float, int);
    bool FUN_004570d0(NiPick&, Vec3&, Vec3&, float);
};

struct SettingS
{
    bool* Bool();
    float* Float();
};

bool __fastcall FUN_00644640(void*);
Tile* FindMenuById(int);
Tile* FUN_0076bfe0();
float __cdecl FUN_0040ebd0(float, float);
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern NiCamera* DAT_011e07d0;
extern int DAT_011d8a90;
extern SettingS g_011d8afc;
extern SettingS g_011ca3ec;
extern SettingS g_011ca394;
extern SettingS g_011d8b78;

// @fnv 0x0070bc20
void FUN_0070bc20_shell::UpdateActivatePick()
{
    if (FUN_00644640(this))
        return;

    Tile* phud = FindMenuById(0x3ec);
    if (!phud)
        phud = FUN_0076bfe0();

    TESObjectREFR* pnextTeleRef = 0;
    TESObjectREFR* pnextActiRef = 0;
    Vec3 origin;
    Vec3 dir;
    ThreeByThreeMatrix dir2;
    ThreeByThreeMatrix rot;

    if (DAT_011e07d0)
        origin = *g_thePlayer->GetFieldAtOffsetDD4();
    else
    {
        origin = *g_thePlayer->GetPos();
        origin.z += g_thePlayer->FUN_0070c3b0() * g_thePlayer->GetScale();
    }
    if (g_thePlayer->FUN_00524d10())
        origin += g_thePlayer->GetPosition();

    dir2.FUN_004a0c90(g_thePlayer->GetCurrentTargetDistance(0));
    rot.FUN_00524ac0(g_thePlayer->GetLooking());
    dir2 = dir2 * rot;
    dir2.FUN_00439f50(1, dir);

    float fpickLength = *(int*)((char*)this + 0x18);
    if (phud)
    {
        DAT_011d8a90 = 1;
        TESObjectREFR* ppick_ref = 0;
        float fdistanceToRef = 0.0f;
        if (*g_011d8afc.Bool() || *g_011ca3ec.Bool() || *g_011ca394.Bool())
        {
            NiPick activatePick(0, 8);
            CollisionFilter icolFilter = g_thePlayer->GetVectorElement();
            CollisionFilter fltr(0);
            fltr.FUN_004a39f0(0x24);
            fltr.FUN_0059ce80(icolFilter.FUN_004a3a20());
            if (phud && g_TES->ApplyToObject(activatePick, origin, dir, fpickLength, 0x1f))
            {
                NiPickRecord* ppickRecord = 0;
                for (unsigned int a = 0; a < activatePick.GetResults()->GetEffectiveSize(); a++)
                {
                    ppickRecord = activatePick.GetResults()->GetAt(a);
                    ppick_ref = TESObjectREFR::GetReferenceFromNiAVObject(ppickRecord->FUN_00458b50());
                    if (ppick_ref != (TESObjectREFR*)g_thePlayer)
                    {
                        fdistanceToRef = activatePick.GetResults()->GetAt(a)->GetDistance();
                        break;
                    }
                    ppick_ref = 0;
                }
            }
        }
        else
        {
            DAT_011d8a90 = 2;
            if (!(*(ActivatePickHelper**)((char*)this + 0x13c))->IsPatrolling() && g_thePlayer)
            {
                bhkCharacterController* pcon = g_thePlayer->GetPhysicsCharacterController();
                if (pcon)
                {
                    CollisionFilter icolFilter = pcon->FUN_0070c440();
                    unsigned int igroup = icolFilter.FUN_004a3a20();
                    (*(ActivatePickHelper**)((char*)this + 0x13c))->FUN_00631ab0(*g_011d8b78.Float(), igroup);
                }
            }
            DAT_011d8a90 = 3;
            if ((*(ActivatePickHelper**)((char*)this + 0x13c))->IsPatrolling())
            {
                DAT_011d8a90 = 0x21;
                if (g_thePlayer->GetParentCell() && (*(ActivatePickHelper**)((char*)this + 0x13c))->FUN_00621440() !=
                                                        g_thePlayer->GetParentCell()->FUN_004543c0())
                    (*(ActivatePickHelper**)((char*)this + 0x13c))
                        ->FUN_00631ca0(g_thePlayer->GetParentCell()->FUN_004543c0());

                DAT_011d8a90 = 0x22;
                unsigned int igroup = g_thePlayer->GetVectorElement().FUN_004a3a20();
                if ((*(ActivatePickHelper**)((char*)this + 0x13c))->GetFlags() != igroup)
                    (*(ActivatePickHelper**)((char*)this + 0x13c))->FUN_00631c50(igroup);

                DAT_011d8a90 = 0x23;
                ppick_ref = (*(ActivatePickHelper**)((char*)this + 0x13c))
                                ->FUN_00631d60(origin, dir, fpickLength, &fdistanceToRef, (int*)((char*)this + 0x110));
                bool bcheckwater = true;
                if (ppick_ref)
                {
                    unsigned char etype = ppick_ref->GetObjectReference()->GetFormType();
                    switch (etype)
                    {
                    case 0x15:
                    case 0x1b:
                    case 0x1c:
                    case 0x2a:
                    case 0x2b:
                        bcheckwater = false;
                        break;
                    default:
                        bcheckwater = !TESContainer::IsValidContainerType(etype);
                        break;
                    }
                }
                if (bcheckwater)
                {
                    NiPick waterpick(0, 8);
                    if (g_TES->FUN_004570d0(waterpick, origin, dir, FUN_0040ebd0(fpickLength, fdistanceToRef)))
                    {
                        NiAVObject* phit3D = waterpick.GetResults()->GetAt(0)->FUN_00458b50();
                        TESObjectREFR* pwaterref = TESObjectREFR::GetReferenceFromNiAVObject(phit3D);
                        if (pwaterref)
                            ppick_ref = pwaterref;
                    }
                }
            }
        }

        DAT_011d8a90 = 4;
        if (ppick_ref)
        {
            if (g_thePlayer->FUN_0070c3d0())
            {
                pnextTeleRef = ppick_ref;
                if (fdistanceToRef <= *(int*)((char*)this + 0x18))
                    pnextActiRef = ppick_ref;
            }
            else
                pnextActiRef = ppick_ref;
        }
        else
        {
            pnextActiRef = 0;
            pnextTeleRef = 0;
        }
        *(TESObjectREFR**)((char*)this + 0x100) = pnextTeleRef;
        *(TESObjectREFR**)((char*)this + 0xfc) = pnextActiRef;
        *(Vec3*)((char*)this + 0x104) = origin + dir * fdistanceToRef;
        DAT_011d8a90 = 5;
        HUDMainMenu::UpdateTargetReference(ppick_ref, *(TESObjectREFR**)((char*)this + 0xfc) == 0, false);
    }
}
}  // namespace fnv_0070bc20

namespace fnv_0070ee80 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct FindData;
struct HWND__;
struct KFModel;
struct NiAVObject;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct NiPoint3;
struct TESAnimGroup;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESIdleForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    char m_kNodeTranslation[12];
    char m_kRootTranslation[12];
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0070ee80_shell : public InterfaceManager
{
    void UpdatePipboyWaiver();
};

struct TESObjectWEAP
{
    int GetWeaponType() const;
};
struct InventoryStackRecord
{
    TESObjectWEAP* GetFlags();
};
struct PlayerCharacter;
struct BaseProcess
{
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual void Unk_074();
    virtual void Unk_075();
    virtual void Unk_076();
    virtual void Unk_077();
    virtual void Unk_078();
    virtual void Unk_079();
    virtual void Unk_080();
    virtual void Unk_081();
    virtual InventoryStackRecord* GetActiveWeapon();
    virtual void Unk_083();
    virtual void Unk_084();
    virtual void Unk_085();
    virtual void Unk_086();
    virtual void Unk_087();
    virtual void Unk_088();
    virtual void Unk_089();
    virtual void Unk_090();
    virtual void Unk_091();
    virtual void Unk_092();
    virtual void Unk_093();
    virtual void Unk_094();
    virtual void Unk_095();
    virtual void Unk_096();
    virtual void Unk_097();
    virtual void Unk_098();
    virtual void Unk_099();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual void Unk_133();
    virtual void Unk_134();
    virtual void Unk_135();
    virtual void Unk_136();
    virtual void Unk_137();
    virtual void Unk_138();
    virtual void Unk_139();
    virtual void Unk_140();
    virtual void Unk_141();
    virtual void Unk_142();
    virtual void Unk_143();
    virtual void Unk_144();
    virtual void Unk_145();
    virtual void Unk_146();
    virtual void Unk_147();
    virtual void Unk_148();
    virtual void Unk_149();
    virtual void Unk_150();
    virtual void Unk_151();
    virtual void Unk_152();
    virtual void Unk_153();
    virtual void Unk_154();
    virtual void Unk_155();
    virtual void Unk_156();
    virtual void Unk_157();
    virtual void Unk_158();
    virtual void Unk_159();
    virtual void Unk_160();
    virtual void Unk_161();
    virtual void Unk_162();
    virtual void Unk_163();
    virtual void Unk_164();
    virtual void Unk_165();
    virtual void Unk_166();
    virtual void Unk_167();
    virtual void Unk_168();
    virtual void Unk_169();
    virtual void Unk_170();
    virtual void Unk_171();
    virtual void Unk_172();
    virtual void Unk_173();
    virtual void Unk_174();
    virtual void Unk_175();
    virtual void Unk_176();
    virtual void Unk_177();
    virtual void Unk_178();
    virtual void Unk_179();
    virtual void Unk_180();
    virtual void Unk_181();
    virtual void Unk_182();
    virtual void Unk_183();
    virtual void Unk_184();
    virtual void Unk_185();
    virtual void Unk_186();
    virtual void Unk_187();
    virtual void Unk_188();
    virtual void Unk_189();
    virtual void Unk_190();
    virtual void Unk_191();
    virtual void Unk_192();
    virtual void Unk_193();
    virtual void Unk_194();
    virtual void Unk_195();
    virtual void Unk_196();
    virtual void Unk_197();
    virtual void Unk_198();
    virtual void Unk_199();
    virtual void Unk_200();
    virtual void Unk_201();
    virtual void Unk_202();
    virtual void Unk_203();
    virtual void Unk_204();
    virtual void Unk_205();
    virtual void Unk_206();
    virtual void Unk_207();
    virtual void Unk_208();
    virtual void Unk_209();
    virtual void Unk_210();
    virtual void Unk_211();
    virtual void Unk_212();
    virtual void Unk_213();
    virtual void Unk_214();
    virtual void Unk_215();
    virtual void Unk_216();
    virtual void Unk_217();
    virtual void Unk_218();
    virtual void Unk_219();
    virtual void Unk_220();
    virtual void Unk_221();
    virtual void Unk_222();
    virtual void Unk_223();
    virtual void Unk_224();
    virtual void Unk_225();
    virtual void Unk_226();
    virtual void Unk_227();
    virtual void Unk_228();
    virtual void Unk_229();
    virtual void Unk_230();
    virtual void Unk_231();
    virtual void Unk_232();
    virtual void Unk_233();
    virtual void Unk_234();
    virtual void Unk_235();
    virtual void Unk_236();
    virtual void Unk_237();
    virtual void Unk_238();
    virtual void Unk_239();
    virtual void Unk_240();
    virtual void Unk_241();
    virtual void Unk_242();
    virtual void Unk_243();
    virtual void Unk_244();
    virtual void Unk_245();
    virtual void Unk_246();
    virtual void Unk_247();
    virtual void Unk_248();
    virtual void Unk_249();
    virtual void Unk_250();
    virtual void Unk_251();
    virtual void Unk_252();
    virtual void Unk_253();
    virtual void Unk_254();
    virtual void Unk_255();
    virtual void Unk_256();
    virtual void Unk_257();
    virtual void Unk_258();
    virtual void Unk_259();
    virtual void Unk_260();
    virtual void Unk_261();
    virtual void Unk_262();
    virtual void Unk_263();
    virtual void Unk_264();
    virtual void Unk_265();
    virtual void Unk_266();
    virtual void Unk_267();
    virtual void Unk_268();
    virtual void Unk_269();
    virtual void Unk_270();
    virtual void Unk_271();
    virtual void Unk_272();
    virtual void Unk_273();
    virtual void Unk_274();
    virtual void Unk_275();
    virtual void Unk_276();
    virtual void Unk_277();
    virtual void Unk_278();
    virtual void Unk_279();
    virtual void Unk_280();
    virtual void Unk_281();
    virtual void Unk_282();
    virtual void Unk_283();
    virtual void Unk_284();
    virtual void Unk_285();
    virtual void Unk_286();
    virtual void Unk_287();
    virtual void Unk_288();
    virtual void Unk_289();
    virtual void Unk_290();
    virtual void Unk_291();
    virtual void Unk_292();
    virtual void Unk_293();
    virtual void Unk_294();
    virtual void Unk_295();
    virtual void Unk_296();
    virtual void Unk_297();
    virtual void Unk_298();
    virtual void Unk_299();
    virtual void Unk_300();
    virtual void Unk_301();
    virtual void Unk_302();
    virtual void Unk_303();
    virtual void Unk_304();
    virtual void Unk_305();
    virtual void Unk_306();
    virtual void Unk_307();
    virtual void Unk_308();
    virtual void Unk_309();
    virtual bool IsIdleReady(PlayerCharacter*);

    void ProcessNode(PlayerCharacter*);
};
struct PlayerCharacter
{
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual void Unk_074();
    virtual void Unk_075();
    virtual void Unk_076();
    virtual void Unk_077();
    virtual void Unk_078();
    virtual void Unk_079();
    virtual void Unk_080();
    virtual void Unk_081();
    virtual void Unk_082();
    virtual void Unk_083();
    virtual void Unk_084();
    virtual void Unk_085();
    virtual void Unk_086();
    virtual void Unk_087();
    virtual void Unk_088();
    virtual void Unk_089();
    virtual void Unk_090();
    virtual void Unk_091();
    virtual void Unk_092();
    virtual void Unk_093();
    virtual void Unk_094();
    virtual void Unk_095();
    virtual void Unk_096();
    virtual void Unk_097();
    virtual void Unk_098();
    virtual void Unk_099();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual int GetSitSleepState();
    virtual void Unk_134();
    virtual void Unk_135();
    virtual void Unk_136();
    virtual void Unk_137();
    virtual void Unk_138();
    virtual void Unk_139();
    virtual void Unk_140();
    virtual void Unk_141();
    virtual void Unk_142();
    virtual void Unk_143();
    virtual void Unk_144();
    virtual void Unk_145();
    virtual void Unk_146();
    virtual void Unk_147();
    virtual void Unk_148();
    virtual void Unk_149();
    virtual void Unk_150();
    virtual void Unk_151();
    virtual void Unk_152();
    virtual void Unk_153();
    virtual void Unk_154();
    virtual void Unk_155();
    virtual void Unk_156();
    virtual void Unk_157();
    virtual void Unk_158();
    virtual void Unk_159();
    virtual void Unk_160();
    virtual void Unk_161();
    virtual void Unk_162();
    virtual void Unk_163();
    virtual void Unk_164();
    virtual void Unk_165();
    virtual void Unk_166();
    virtual void Unk_167();
    virtual void Unk_168();
    virtual void Unk_169();
    virtual void Unk_170();
    virtual void Unk_171();
    virtual void Unk_172();
    virtual void Unk_173();
    virtual void Unk_174();
    virtual void Unk_175();
    virtual void Unk_176();
    virtual void Unk_177();
    virtual void Unk_178();
    virtual void Unk_179();
    virtual void Unk_180();
    virtual void Unk_181();
    virtual void Unk_182();
    virtual void Unk_183();
    virtual void Unk_184();
    virtual void Unk_185();
    virtual void Unk_186();
    virtual void Unk_187();
    virtual void Unk_188();
    virtual void Unk_189();
    virtual void Unk_190();
    virtual void Unk_191();
    virtual void Unk_192();
    virtual void Unk_193();
    virtual void Unk_194();
    virtual void Unk_195();
    virtual void Unk_196();
    virtual void Unk_197();
    virtual void Unk_198();
    virtual void Unk_199();
    virtual void Unk_200();
    virtual void Unk_201();
    virtual void Unk_202();
    virtual void Unk_203();
    virtual void Unk_204();
    virtual void Unk_205();
    virtual void Unk_206();
    virtual void Unk_207();
    virtual void Unk_208();
    virtual void Unk_209();
    virtual void Unk_210();
    virtual void Unk_211();
    virtual void Unk_212();
    virtual void Unk_213();
    virtual void Unk_214();
    virtual void Unk_215();
    virtual void Unk_216();
    virtual void Unk_217();
    virtual void Unk_218();
    virtual void Unk_219();
    virtual void Unk_220();
    virtual void Unk_221();
    virtual void Unk_222();
    virtual void Unk_223();
    virtual void Unk_224();
    virtual void Unk_225();
    virtual void Unk_226();
    virtual void Unk_227();
    virtual void Unk_228();
    virtual void Unk_229();
    virtual void Unk_230();
    virtual void Unk_231();
    virtual void Unk_232();
    virtual void Unk_233();
    virtual void Unk_234();
    virtual void Unk_235();
    virtual void Unk_236();
    virtual void Unk_237();
    virtual void Unk_238();
    virtual void Unk_239();
    virtual void Unk_240();
    virtual void Unk_241();
    virtual void Unk_242();
    virtual void Unk_243();
    virtual void Unk_244();
    virtual void Unk_245();
    virtual void Unk_246();
    virtual void Unk_247();
    virtual void Unk_248();
    virtual void Unk_249();
    virtual void Unk_250();
    virtual void Unk_251();
    virtual void Unk_252();
    virtual void Unk_253();
    virtual void Unk_254();
    virtual void Unk_255();
    virtual void Unk_256();
    virtual void Unk_257();
    virtual void Unk_258();
    virtual void Unk_259();
    virtual void Unk_260();
    virtual void Unk_261();
    virtual void Unk_262();
    virtual void Unk_263();
    virtual void Unk_264();
    virtual void Unk_265();
    virtual void Unk_266();
    virtual void Unk_267();
    virtual void Unk_268();
    virtual void Unk_269();
    virtual void Unk_270();
    virtual void Unk_271();
    virtual void Unk_272();
    virtual void Unk_273();
    virtual void Unk_274();
    virtual void Unk_275();
    virtual void Unk_276();
    virtual void Unk_277();
    virtual void Unk_278();
    virtual void Unk_279();
    virtual void Unk_280();
    virtual void Unk_281();
    virtual void Unk_282();
    virtual void Unk_283();
    virtual void Unk_284();
    virtual void Unk_285();
    virtual void Unk_286();
    virtual void Unk_287();
    virtual void Unk_288();
    virtual void Unk_289();
    virtual void Unk_290();
    virtual void Unk_291();
    virtual void Unk_292();
    virtual void Unk_293();
    virtual void Unk_294();
    virtual void Unk_295();
    virtual void Unk_296();
    virtual void Unk_297();
    virtual void Unk_298();
    virtual void Unk_299();
    virtual void SetAnimGroup(unsigned short, int);

    int GetAnimAction();
    Animation* GetAnimation(bool);
    void FUN_00950460(int);
    void FUN_00962590();
    BaseProcess* GetLogDate();
};
extern PlayerCharacter* g_thePlayer;
struct TESAnimGroup
{
    float FUN_005f3780(int);
};
struct BSAnimGroupSequence
{
    float FUN_00639aa0();
    TESAnimGroup* GetAnimGroup() const;
};
struct AnimationHelper
{
    BSAnimGroupSequence* GetControllerSequence(int);
    void* GetKFSequence();
    unsigned short FUN_004301b0(int);
    void FUN_00496080(int, float);
    void FUN_0049bca0(float, int, int);
    void FUN_00493bd0();
    int GetSlotValue(int);
};
struct FOPipboyManager
{
    void FUN_007f8a80();
    void UpdatePipboyLight(int);
};
struct InterfaceHelper
{
    static bool GetSelectedTargetIndex(int);
    static FOPipboyManager* GetPipboyManagerInstance();
    FOPipboyManager* GetPipboyManager();
};
struct Im7181
{
    void SetRenderedMenu(FOPipboyManager*);
};
struct FUN_00714d90_struct
{
    void PushMenuStackEntry(int);
};
struct InterfaceManager_PopFromEnterStack_helper
{
    int AddMenuStackEntry(int, bool);
};
struct ContainerMenu
{
    static void Close();
};
struct HUDMainMenu
{
    static void UpdateVisibilityState(int);
};
struct MapMenuHelper
{
    static void UpdateMapPosition();
};
struct TESImageSpaceModifier
{
    static TESImageSpaceModifier* GetGetHit();
};
struct ImageSpaceModifierInstanceForm
{
    static void Stop(TESImageSpaceModifier*);
};
struct SoundPlaybackHandle
{
    int soundID;
    bool assumeSuccess;
    int state;
    ~SoundPlaybackHandle();
    bool Play();
};
struct BSAudio
{
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int, int);
    void FUN_0070bba0();
};
struct MenuCloser
{
    void FUN_007ffd50();
};
void __fastcall FUN_0070bbc0(BSAudio*);
void __cdecl HandleMenuKeyInput();
bool __cdecl FUN_007a1750();
void __cdecl FUN_0079ffb0(int);
void __cdecl FUN_008d6a80(int, void*);
bool __fastcall FUN_008a16d0(PlayerCharacter*);
bool __fastcall FUN_00967ae0(PlayerCharacter*);
void _FNV_Warning(const char*);
extern int DAT_0118a838[];
extern bool DAT_011cab24;

// Steps the pipboy waiver state machine (0x4bc): closes menus, plays the access animation, updates the pipboy and restores anim groups.
// @fnv 0x0070ee80
void FUN_0070ee80_shell::UpdatePipboyWaiver()
{
    static const char sMissingWaiverIdle[] =
        "ANIMATION: Missing dynamic idle for the pipboy waiver in the idle manager.";
    switch (*(int*)((char*)this + 0x4bc))
    {
    case 1:
        if (InterfaceHelper::GetSelectedTargetIndex(0x3f0))
        {
            ContainerMenu::Close();
        }
        else if (InterfaceHelper::GetSelectedTargetIndex(0x421) || InterfaceHelper::GetSelectedTargetIndex(0x41f))
        {
            (*(MenuCloser**)((char*)this + 0x16c))->FUN_007ffd50();
        }
        else
        {
            switch (g_thePlayer->GetAnimAction())
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 17:
                break;
            default: {
                Animation* panim = g_thePlayer->GetAnimation(false);
                if (panim)
                {
                    ((AnimationHelper*)panim)->FUN_00496080(1, 0.0f);
                    panim = g_thePlayer->GetAnimation(true);
                }
                if (panim)
                {
                    ((AnimationHelper*)panim)->FUN_00496080(1, 0.0f);
                    g_thePlayer->FUN_00950460(0);
                    panim->PlayGroup(0xe2, 1, -1, -1);
                    InterfaceHelper::GetPipboyManagerInstance()->UpdatePipboyLight(1);
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPipBoyAccessUp", 0x121, 0).Play();
                    ImageSpaceModifierInstanceForm::Stop(TESImageSpaceModifier::GetGetHit());
                    ++((unsigned char*)FUN_004b7210())[0x20];
                    BSAudio::GetSingleton()->FUN_0070bba0();
                    g_thePlayer->FUN_00962590();
                    ((FUN_00714d90_struct*)this)->PushMenuStackEntry(1);
                    HandleMenuKeyInput();
                    *(int*)((char*)this + 0x4bc) = 2;
                }
            }
            break;
            }
        }
        break;
    case 2: {
        Animation* panim = g_thePlayer->GetAnimation(true);
        if (panim && ((AnimationHelper*)panim)->GetControllerSequence(2))
        {
            if (((AnimationHelper*)panim)->GetSlotValue(2) == 1)
            {
                float ftime;
                HUDMainMenu::UpdateVisibilityState(3);
                if (FUN_008a16d0(g_thePlayer))
                {
                    TESObjectWEAP* pweapon = g_thePlayer->GetLogDate()->GetActiveWeapon()
                                                 ? g_thePlayer->GetLogDate()->GetActiveWeapon()->GetFlags()
                                                 : 0;
                    if (pweapon && g_thePlayer->GetAnimation(true) &&
                        ((AnimationHelper*)g_thePlayer->GetAnimation(true))->GetKFSequence())
                        FUN_008d6a80(DAT_0118a838[pweapon->GetWeaponType()],
                                     ((AnimationHelper*)g_thePlayer->GetAnimation(true))->GetKFSequence());
                }
                ftime = -((AnimationHelper*)panim)->GetControllerSequence(2)->FUN_00639aa0();
                ftime += ((AnimationHelper*)panim)->GetControllerSequence(2)->GetAnimGroup()->FUN_005f3780(1);
                panim->Update((TESObjectREFR*)g_thePlayer, 0.0f, ftime);
                ((AnimationHelper*)panim)->FUN_0049bca0(ftime, 0, 1);
                ((AnimationHelper*)panim)->FUN_00493bd0();
                DAT_011cab24 = true;
                if (g_thePlayer->GetLogDate()->IsIdleReady(g_thePlayer))
                    ((AnimationHelper*)g_thePlayer->GetAnimation(false))->FUN_00496080(0, 0.0f);
                else
                    _FNV_Warning(sMissingWaiverIdle);
                DAT_011cab24 = false;
                if (*(void (**)())((char*)this + 0x4c0))
                {
                    (*(void (**)())((char*)this + 0x4c0))();
                    *(void (**)())((char*)this + 0x4c0) = 0;
                }
                ((InterfaceHelper*)FUN_004b7210())->GetPipboyManager()->FUN_007f8a80();
                ((Im7181*)FUN_004b7210())->SetRenderedMenu(((InterfaceHelper*)FUN_004b7210())->GetPipboyManager());
                *(int*)((char*)this + 0x4bc) = 3;
            }
        }
        else
        {
            InterfaceHelper::GetPipboyManagerInstance()->UpdatePipboyLight(0);
            *(int*)((char*)this + 0x4bc) = 4;
        }
        if (FUN_007a1750())
            FUN_0079ffb0(0);
    }
    break;
    case 3:
        if (FUN_007a1750())
            FUN_0079ffb0(0);
        break;
    case 4:
        if (((InterfaceManager_PopFromEnterStack_helper*)this)->AddMenuStackEntry(1, false) >= 0)
        {
            InterfaceHelper::GetPipboyManagerInstance()->UpdatePipboyLight(0);
            if (g_thePlayer->GetSitSleepState() == 4)
                g_thePlayer->GetLogDate()->ProcessNode(g_thePlayer);
            g_thePlayer->SetAnimGroup(((AnimationHelper*)g_thePlayer->GetAnimation(false))->FUN_004301b0(0), 1);
            MapMenuHelper::UpdateMapPosition();
            while (((unsigned char*)FUN_004b7210())[0x20])
            {
                --((unsigned char*)FUN_004b7210())[0x20];
                FUN_0070bbc0(BSAudio::GetSingleton());
            }
            *(int*)((char*)this + 0x4bc) = 5;
        }
        break;
    case 5:
        if (!FUN_00967ae0(g_thePlayer))
        {
            g_thePlayer->SetAnimGroup(((AnimationHelper*)g_thePlayer->GetAnimation(false))->FUN_004301b0(2), 1);
            *(int*)((char*)this + 0x4bc) = 0;
            if (*(void (**)())((char*)this + 0x4c0))
            {
                (*(void (**)())((char*)this + 0x4c0))();
                *(void (**)())((char*)this + 0x4c0) = 0;
            }
        }
        break;
    }
}
}  // namespace fnv_0070ee80

namespace fnv_00712e90 {
struct NiPoint3;
struct NiStream;
struct SceneGraph;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiFrustum
{
    char* FormatToBuffer(char*);
    void __dflt_ctor_closure();
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
    char _pad_19[3];
};
typedef char _sizecheck_NiFrustum[sizeof(NiFrustum) == 28 ? 1 : -1];
struct FUN_00712e90_shell : public InterfaceManager
{
    SceneGraph* FUN_00712e90(SceneGraph*, char*, bool);
};

namespace Local {
enum MEM_CONTEXT
{
    MC_INTERFACE = 13
};
struct AutoMemContext
{
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
struct NiFrustum
{
    NiFrustum(bool);
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};
}

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    const char* m_kHandle;
};

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float, float, float);
};

struct M3_
{
    M3_();
    void SetElement(unsigned int, float, float, float);
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};

class NiRenderer
{
};

class GraphicsRenderer : public NiRenderer
{
  public:
    unsigned int GetRenderTargetHeight();
    unsigned int GetRenderTargetWidth();
};

NiRenderer* FUN_0043c4b0();
const char* PrepareScriptMessage(const char*, bool);

class NiAVObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
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
    void SetName(const NiFixedString&);
    void SetLocalRotation(const M3_&);
    NiPoint3& FUN_0043c490();
    void FUN_00440460(const NiPoint3&);
};

class NiCamera : public NiAVObject
{
  public:
    void UpdateViewFrustum(const Local::NiFrustum&);
};

class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short);
    char _pad_04[0xa8];
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
};

struct SceneGraph : public NiNode
{
    SceneGraph(const char*, bool, NiCamera*);
    char _pad_ac[0x14];
    NiCamera* GetCamera();
    void SetCameraFOV(float, int, int, int);
};

struct FaderManager
{
    void AddRoot(NiNode*, float, bool);
};

extern double DAT_01011588;
extern double DAT_01021790;
extern float DAT_01022958;
extern float DAT_0106f2dc;
extern const float runtimeFloatSettingDefault65;
extern FaderManager* DAT_011d8804;

// Creates or reuses a SceneGraph, sets its camera rotation, aspect-based frustum and position, and adds main/cursor root nodes when not a buffer.
// @fnv 0x00712e90
SceneGraph* FUN_00712e90_shell::FUN_00712e90(SceneGraph* apGraph, char* apName, bool abIsBuffer)
{
    float faspectRatio;
    Local::AutoMemContext tempMemContext(
        (Local::MEM_CONTEXT)13, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp", 3601);
    SceneGraph* pscene_graph = apGraph;
    if (!pscene_graph)
        pscene_graph = new SceneGraph(PrepareScriptMessage(apName, false), false, 0);
    GraphicsRenderer* pr = static_cast<GraphicsRenderer*>(FUN_0043c4b0());
    M3_ rot;
    rot.SetElement(0, 0.0f, 0.0f, 1.0f);
    rot.SetElement(1, 1.0f, 0.0f, 0.0f);
    rot.SetElement(2, 0.0f, 1.0f, 0.0f);
    pscene_graph->GetCamera()->SetLocalRotation(rot);

    faspectRatio = (double)pr->GetRenderTargetWidth() / (double)pr->GetRenderTargetHeight();
    *(float*)((char*)this + 0x4d0) = faspectRatio / DAT_01021790;

    Local::NiFrustum kFrustum(false);
    kFrustum.m_bOrthographic = true;
    kFrustum.m_fLeftBound = 0.0f;
    kFrustum.m_fRightBound = *(float*)((char*)this + 0x4d0) * 1280.0;
    kFrustum.m_fTopBound = DAT_0106f2dc;
    kFrustum.m_fBottomBound = 0.0f;
    kFrustum.m_fNearPlane = 0.0f;
    kFrustum.m_fFarPlane = DAT_01022958;
    pscene_graph->GetCamera()->UpdateViewFrustum(kFrustum);
    pscene_graph->GetCamera()->FUN_00440460(
        NiPoint3(-kFrustum.m_fRightBound * DAT_01011588, 0.0f, -kFrustum.m_fTopBound * DAT_01011588));

    if (!abIsBuffer)
    {
        DAT_011d8804->AddRoot(pscene_graph, *(float*)((char*)this + 0xa8), true);

        *(NiNode**)((char*)this + 0x80) = new NiNode(0);
        (*(NiNode**)((char*)this + 0x80))->SetName(NiFixedString("InterfaceManager: Main Root"));
        pscene_graph->AttachChildInAvailableSlot(*(NiNode**)((char*)this + 0x80), true);
        NiPoint3 kPosition = (*(NiNode**)((char*)this + 0x80))->FUN_0043c490();
        (*(NiNode**)((char*)this + 0x80))->FUN_00440460(NiPoint3(0.0f, *(float*)((char*)this + 0xa8), 0.0f));

        *(NiNode**)((char*)this + 0x84) = new NiNode(0);
        (*(NiNode**)((char*)this + 0x84))->SetName(NiFixedString("InterfaceManager: Cursor Root"));
        pscene_graph->AttachChildInAvailableSlot(*(NiNode**)((char*)this + 0x84), true);
        kPosition = (*(NiNode**)((char*)this + 0x84))->FUN_0043c490();
        (*(NiNode**)((char*)this + 0x84))->FUN_00440460(NiPoint3(0.0f, *(float*)((char*)this + 0xa8), 0.0f));

        DAT_011d8804->AddRoot(pscene_graph, *(float*)((char*)this + 0xa8), false);
    }
    else
    {
        pscene_graph->SetCameraFOV(runtimeFloatSettingDefault65, 0, 0, 0);
    }
    return pscene_graph;
}
}  // namespace fnv_00712e90

void* __cdecl operator new(unsigned int);
struct Widget
{
    Widget();
    virtual ~Widget();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Run();
    char pad[0x170 - 4];
};
struct Owner
{
    char pad[0x174];
    Widget* pWidget;
};
// Deletes self->pWidget if set, allocates a new Widget, stores it in self->pWidget and calls its Run method.
// @fnv 0x007133f0
void __fastcall ResetWidget(Owner* self)
{
    if (self->pWidget)
        delete self->pWidget;
    self->pWidget = new Widget;
    self->pWidget->Run();
}

namespace fnv_00713c70 {
struct FUN_00713c70_shell : public InterfaceManager
{
    void FUN_00713c70();
};

struct IntHolder0
{
    char c;
};
extern IntHolder0 g_011c3ea4;
struct IntHolder
{
    int* Int();
};
bool __cdecl FUN_0070edf0();
void* __cdecl FindMenuById(int);
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct TileHelper
{
    static void UpdateAll(bool);
    void SetSpeechChallengeFailure(bool);
};
struct LoadingMenuHelper
{
    static bool IsInterfaceActive();
};
struct Obj8c
{
    void WaitForEvent(int);
};
struct Updater
{
    void FUN_00713e20();
};
void __cdecl WaitForTasksAndClearScripts();
void __cdecl FUN_00713d60();
ATM* __cdecl FUN_00713d70();
Obj8c* __stdcall FUN_00713d80(int);
void __stdcall FUN_00713d80();
bool __cdecl FUN_00713d90();
void __cdecl FUN_00a04510();
void __cdecl FUN_00a080d0();
extern bool DAT_011d8908;
// @fnv 0x00713c70
void FUN_00713c70_shell::FUN_00713c70()
{
    NiNode* pscene_graph;
    if (*((IntHolder*)&g_011c3ea4)->Int() > 1)
    {
        FUN_00713d80();
        if (FUN_00713d90())
            FUN_00713d80(0)->WaitForEvent(1);
    }
    WaitForTasksAndClearScripts();
    DAT_011d8908 = true;
    pscene_graph = ((Interface*)this)->GetRoot();
    FUN_00a04510();
    *((bool*)this + 0xdc) = false;
    if (LoadingMenuHelper::IsInterfaceActive() && !FUN_0070edf0())
        ((TileHelper*)FindMenuById(0x3ef))->SetSpeechChallengeFailure(false);
    else
        TileHelper::UpdateAll(false);
    FUN_00a080d0();
    FUN_00713d60();
    if (!((ArrHelper*)&g_011d8b44)->FUN_0076b610())
    {
        FUN_00713d70()->QueryPerformanceCounter(0);
        ((Updater*)this)->FUN_00713e20();
        FUN_00713d70()->WaitForTasksDuringRendering();
    }
    DAT_011d8908 = false;
}
}  // namespace fnv_00713c70

bool __cdecl IsInterfaceActive();
struct FltHelper
{
    operator unsigned int() const;
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
};
struct TaskThreadManager
{
    static TaskThreadManager* GetSingleton();
    void FUN_00ba3390(void*, int, NiNode*, int, int, unsigned int, int, int, int);
};
struct FUN_007079f0_shell
{
    bool FUN_007079f0();
};
bool __fastcall FUN_00644640(void*);
void __cdecl FUN_00702c80(bool, bool);
struct IMStandIn
{
    char m_uiStandInValue[0x8c];
    char m_flt8c[0xbc];
    bool m_flag148;
    void FUN_00713c70();
    void FUN_00713f00();
};

// @fnv 0x00713f00
void IMStandIn::FUN_00713f00()
{
    m_flag148 = true;
    NiNode* root = reinterpret_cast<Interface*>(this)->GetRoot();
    if (!FUN_00644640(this) && !IsInterfaceActive())
        FUN_00713c70();
    if (reinterpret_cast<FUN_007079f0_shell*>(this)->FUN_007079f0() && !IsInterfaceActive())
        FUN_00702c80(false, false);
    TaskThreadManager::GetSingleton()->FUN_00ba3390(reinterpret_cast<BSFaceGenNiNode*>(root)->GetAnimationData(), 0,
                                                    root, 0, 0, *reinterpret_cast<FltHelper*>(m_flt8c), 1, 0x17, 0);
    reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())->FUN_00ba30f0(0, 0x17);
}

namespace fnv_00715ca0 {
struct NiNode
{
    void SetAppCulled(bool);
};
struct TileX
{
    NiNode* FUN_0056c7f0();
    void Set(int, int);
};
struct IMStandIn
{
    char m_uiStandInValue[0x28];
    TileX* m_tile28;
    char m_iValueAfterStandIn[0x7d - 0x2c];
    bool m_flag7d;
    char m_pAuxiliaryObject[0xed - 0x7e];
    bool m_flagED;
    TileX* FindHighestPriorityTile(int*, int);
    void FUN_00715860(TileX*, int, int);
    void UpdateFocusTarget();
};
bool FUN_004b71d0();

// @fnv 0x00715ca0
void IMStandIn::UpdateFocusTarget()
{
    int imax_focus = 0x80000000;
    TileX* ptarget = FindHighestPriorityTile(&imax_focus, 0);
    if (ptarget)
    {
        FUN_00715860(ptarget, 0xfc3, 1);
        if (!FUN_004b71d0() || m_flag7d)
        {
            m_tile28->FUN_0056c7f0()->SetAppCulled(true);
            m_tile28->Set(0xfa3, 0);
        }
        m_flagED = 0;
    }
    else
    {
        FUN_00715860(0, 0xfc3, 1);
    }
}
}  // namespace fnv_00715ca0

namespace fnv_00717660 {
struct FUN_00717660_shell : public InterfaceManager
{
    void FUN_00717660();
};

struct Tile_Set_Helper
{
    void Set(int, int);
};
Tile_Set_Helper* __cdecl FUN_00704be0();
Tile_Set_Helper* __cdecl CreateInventoryMenuIfModifierKey();
Tile_Set_Helper* __cdecl FUN_00704490();
Tile_Set_Helper* __cdecl FUN_007046c0();
Tile_Set_Helper* __cdecl FUN_00704140();
void __cdecl FUN_00705b70(int, int, int, int);
void __cdecl FUN_00703610();
// @fnv 0x00717660
void FUN_00717660_shell::FUN_00717660()
{
    if (*((bool*)this + 0xc8))
    {
        char cmode = *((char*)this + 0xc);
        Tile_Set_Helper* pmenutile = FUN_00704be0();
        if (pmenutile)
            pmenutile->Set(0xfa3, 0);
        pmenutile = CreateInventoryMenuIfModifierKey();
        if (pmenutile)
            pmenutile->Set(0xfa3, 0);
        pmenutile = FUN_00704490();
        if (pmenutile)
            pmenutile->Set(0xfa3, 0);
        pmenutile = FUN_007046c0();
        if (pmenutile)
            pmenutile->Set(0xfa3, 0);
        pmenutile = FUN_00704140();
        if (pmenutile)
            pmenutile->Set(0xfa3, 0);
        FUN_00705b70(0, 0, 4, 0x3eb);
        FUN_00703610();
        *((char*)this + 0xc8) = 0;
    }
}
}  // namespace fnv_00717660

namespace fnv_00717f80 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct ListBoxBase
{
    virtual bool Highlight(Tile*);
    virtual Tile* GetHighlightedItem();
    virtual Tile* GetTileForButton(int);
    virtual bool BelongsTo(void*);
    virtual void ScrollToHighlight();
    virtual Tile* GetTileAt(unsigned int, bool);
};
typedef char _sizecheck_ListBoxBase[sizeof(ListBoxBase) == 4 ? 1 : -1];
struct FUN_00717f80_shell : public InterfaceManager
{
    bool HandleMenuGamepadInput(Menu*, int, float);
};

struct MenuV
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
    virtual int GetMenuID();
    virtual bool HandleGamepad(int, float);
};
struct ListNode
{
    ListBoxBase** FUN_006815c0();
    ListNode* FUN_00726070();
};
struct IMStandIn
{
    void FUN_00715860(Tile*, int, int);
};
struct MenuIDHelper
{
    static bool GetSelectedTargetIndex(int);
};
struct DummyNode;
extern DummyNode g_011d8b54;
// Handles gamepad input for the menu, then searches list boxes belonging to it for a tile at the given button and focuses it.
// @fnv 0x00717f80
bool FUN_00717f80_shell::HandleMenuGamepadInput(Menu* apMenu, int aiButton, float afValue)
{
    ListNode* node2;
    Tile* pnewFocus;
    ListBoxBase* plbVal;
    if (((MenuV*)apMenu)->HandleGamepad(aiButton, afValue))
        return true;
    plbVal = 0;
    for (node2 = (ListNode*)&g_011d8b54; node2 && (plbVal = *node2->FUN_006815c0()) != 0; node2 = node2->FUN_00726070())
    {
        if (plbVal->BelongsTo(apMenu) && MenuIDHelper::GetSelectedTargetIndex(((MenuV*)apMenu)->GetMenuID()) &&
            plbVal->GetHighlightedItem())
        {
            pnewFocus = plbVal->GetTileForButton(aiButton);
            if (pnewFocus)
            {
                ((IMStandIn*)this)->FUN_00715860(pnewFocus, 0xfc3, 1);
                plbVal->ScrollToHighlight();
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_00717f80

struct TutorialEntry
{
    unsigned int shown : 1;
    unsigned int seen : 1;
    unsigned int rest : 30;
};
struct TutorialState
{
    TutorialEntry m_entries[1];
    unsigned int FUN_00706810();
    void LoadTutorialSeenFlags(char* apLoadString);
};

// Unpacks bits from apLoadString into the seen flag of each entry, stopping at index 0x29.
// @fnv 0x00718890
void TutorialState::LoadTutorialSeenFlags(char* apLoadString)
{
    for (unsigned int uiByteIndex = 0; uiByteIndex < FUN_00706810(); ++uiByteIndex)
    {
        unsigned char ucByte = apLoadString[uiByteIndex];
        for (unsigned int uiBitIndex = 0; uiBitIndex < 8; ++uiBitIndex)
        {
            unsigned int uiEntryIndex = uiBitIndex + uiByteIndex * 8;
            if (uiEntryIndex == 0x29)
                break;
            else
                m_entries[uiEntryIndex].seen = (ucByte & (1 << uiBitIndex)) != 0;
        }
    }
}

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
};
struct GlobalObject_00719c00;
extern GlobalObject_00719c00 g_011d8ad4;
extern GlobalObject_00719c00 g_011d8ae4;
struct FUN_00718c90 : public GlobalObject_0048f200
{
    int pad[3];
    int m_uiFormCount;
    FUN_00718c90();
    void FUN_00718db0(const char*, int, int, int, GlobalObject_00719c00*, int);
    void AddColor(const char*, int, int, int, int);
};
// @fnv 0x00718c90
FUN_00718c90::FUN_00718c90()
{
    m_uiFormCount = 1;
    FUN_00718db0("HUDMain", 0xff, 0xb6, 0x42, &g_011d8ad4, 1);
    AddColor("HUDAlt", 0xff, 0x43, 0x2a, 2);
    AddColor("Terminal", 0x21, 0xe7, 0x79, 3);
    FUN_00718db0("Pipboy", 0xff, 0xb6, 0x42, &g_011d8ae4, 4);
    AddColor("MainMenu", 0xff, 0xb6, 0x42, -1);
    AddColor("System", 0xff, 0xb6, 0x42, -1);
}

namespace fnv_0070f6e0 {
struct Menu;
struct NiFixedString;
struct TileMenu;
struct MenuValueDescriptor;
struct FUN_0070f6e0_shell : public InterfaceManager
{
    void HandleGamepadButton(int);
};

struct Menu
{
    virtual ~Menu();
    virtual void SetTile(int id, Tile* tile);
    virtual void HandleLeftClickPress(int id, Tile* tile);
    virtual void HandleClick(int id, Tile* tile);
    virtual void HandleMouseover(int id, Tile* tile);
    virtual void HandleUnmouseover(int id, Tile* tile);
    virtual void PostDragTileChange(int id, Tile* newTile, Tile* tile);
    virtual void PreDragTileChange(int id, Tile* oldTile, Tile* tile);
    virtual void HandleActiveMenuClickHeld(int id, Tile* tile);
    virtual void OnClickHeld(int id, Tile* tile);
    virtual void HandleMousewheel(int id, Tile* tile);
    virtual void Update();
    virtual bool HandleKeyboardInput(int inputChar);
    virtual int GetID();
    virtual bool HandleSpecialKeyInput(int code, float keyState);
    virtual bool HandleControllerInput(int button, float value);
    Tile* GetTile();
    unsigned int GetVisibilityState();
};
struct TileCalls
{
    Menu* GetMenu();
    bool IsVisible();
    bool ContainsTrait(int trait);
    float GetFloat(int trait);
    void Set(int trait, int value);
    Tile* GetTileForTrait(int trait, int* out);
    void ClearTrait(int trait);
    Tile* GetParent();
};
struct TileChildList
{
    void* GetHeadPos();
    Tile*& GetPrev(void*& pos);
};
struct TileRoot
{
    int unk0;
    TileChildList kChildren;
};
struct TileSimpleList
{
    Tile* item;
    TileSimpleList* next;
    TileSimpleList();
    ~TileSimpleList();
    void AddHead(Tile*& item);
    bool IsInList(Tile*& item) const;
    void RemoveAll();
};
struct PickRefList
{
    unsigned int ItemsInList();
};
struct MenuMgr
{
    static MenuMgr* Instance(bool create);
    Menu* GetFrontmostMenu();
};
struct IMGamepad
{
    TileRoot* GetMenuRoot();
    Tile* GetActiveTile();
    int GetGamepadInput(bool repeatsV, bool repeatsH, bool* isUpEvent);
    void SetGamepadState(int state);
    Tile* FindFocusTile(int* maxFocus, int unk);
    void SetActiveTile(Tile* tile, int type, int unk);
    bool HandleMenuInput(Menu* menu, int button, float value);
    void ClearMenuInput();
};
int __cdecl GetInputButtonCode(int button, int unk);
void __cdecl PlayUISound(int sound);
void __cdecl ClearGamepadButton(int button);

// Routes a gamepad button through the frontmost menu and active tile, updating focus, firing clicks, and adjusting the pick list index.
// @fnv 0x0070f6e0
void FUN_0070f6e0_shell::HandleGamepadButton(int aiButton)
{
    Tile* pmenutile;
    Menu* pmenu;
    bool bisUpEvent = false;

    if (1)
    {
        void* elem = ((IMGamepad*)this)->GetMenuRoot()->kChildren.GetHeadPos();
        while (elem)
        {
            Tile* pmenutile = ((IMGamepad*)this)->GetMenuRoot()->kChildren.GetPrev(elem);
            Menu* pmenu = 0;
            if (pmenutile)
                pmenu = ((TileCalls*)pmenutile)->GetMenu();
            if (pmenu && ((TileCalls*)pmenutile)->IsVisible() && ((IMGamepad*)this)->HandleMenuInput(pmenu, -1, 0.0f))
                return;
        }
    }

    if (FUN_004b71d0() && !((bool*)this)[0x7d])
    {
        Tile* ptarget;
        bool brepeats_h;
        bool brepeats_v;
        brepeats_v = false;
        brepeats_h = false;
        ptarget = ((IMGamepad*)this)->GetActiveTile();
        if (ptarget && ((TileCalls*)ptarget)->GetMenu() && ((TileCalls*)ptarget)->GetMenu()->GetVisibilityState() != 1)
            return;
        if (ptarget)
        {
            brepeats_v = ((TileCalls*)ptarget)->ContainsTrait(0xfcf);
            brepeats_h = ((TileCalls*)ptarget)->ContainsTrait(0xfd0);
        }
        if (aiButton == 0)
            aiButton = ((IMGamepad*)this)->GetGamepadInput(brepeats_v, brepeats_h, &bisUpEvent);
        if (aiButton != 0 && aiButton != 4 && aiButton != 3 && aiButton != 1 && aiButton != 2)
            ((IMGamepad*)this)->SetGamepadState(0);
    }

    pmenu = MenuMgr::Instance(true)->GetFrontmostMenu();
    pmenutile = pmenu ? pmenu->GetTile() : 0;
    if (pmenu && !bisUpEvent && ((IMGamepad*)this)->HandleMenuInput(pmenu, aiButton, 1.0f))
    {
        return;
    }
    else if (bisUpEvent)
    {
        if (pmenu)
            pmenu->HandleControllerInput(aiButton, 1.0f);
        return;
    }

    if (pmenu && pmenutile && aiButton)
    {
        if (aiButton == 1 || aiButton == 2 || aiButton == 4 || aiButton == 3)
        {
            int iid;
            Tile* ptarget;
            int itype;
            ((bool*)this)[0xed] = false;
            itype = 0xfc3;
            iid = 0;
            if (aiButton == 1)
                iid = 0xfd7;
            else if (aiButton == 2)
                iid = 0xfd8;
            else if (aiButton == 4)
                iid = 0xfd9;
            else if (aiButton == 3)
                iid = 0xfda;
            ptarget = ((IMGamepad*)this)->GetActiveTile();
            if (!ptarget)
            {
                int imax_focus = 0x80000000;
                Tile* ptile = ((IMGamepad*)this)->FindFocusTile(&imax_focus, 0);
                ((IMGamepad*)this)->SetActiveTile(ptile, 0xfc3, 1);
                if (!ptile)
                {
                    ptile = ((TileCalls*)pmenutile)->GetTileForTrait(iid, &itype);
                    if (ptile)
                    {
                        ((TileCalls*)ptile)->ClearTrait(0xfcb);
                        ((TileCalls*)ptile)->Set(0xfc7, 1);
                        ((TileCalls*)ptile)->Set(0xfc7, 0);
                        pmenu->HandleClick(((TileCalls*)ptile)->GetFloat(0xfaa), ptile);
                    }
                    else if (FUN_004b71d0() || !((bool*)this)[0x7d])
                    {
                        if (((IMGamepad*)this)->HandleMenuInput(pmenu, aiButton, iid))
                            return;
                    }
                }
            }
            else
            {
                Tile* m_pActionSuccessor = ((TileCalls*)ptarget)->GetTileForTrait(iid, &itype);
                TileSimpleList xlast;
                xlast.AddHead(ptarget);
                while (m_pActionSuccessor && !xlast.IsInList(m_pActionSuccessor) &&
                       (!((TileCalls*)m_pActionSuccessor)->ContainsTrait(0xfa3) ||
                        !((TileCalls*)m_pActionSuccessor)->ContainsTrait(0xfaf)))
                {
                    xlast.AddHead(m_pActionSuccessor);
                    m_pActionSuccessor = ((TileCalls*)m_pActionSuccessor)->GetTileForTrait(iid, &itype);
                }
                if (m_pActionSuccessor && xlast.IsInList(m_pActionSuccessor) &&
                    (!((TileCalls*)m_pActionSuccessor)->ContainsTrait(0xfa3) ||
                     !((TileCalls*)m_pActionSuccessor)->ContainsTrait(0xfaf)))
                    m_pActionSuccessor = 0;
                xlast.RemoveAll();
                if (m_pActionSuccessor)
                {
                    if (m_pActionSuccessor != ptarget && itype == 0xfc3)
                        ((TileCalls*)m_pActionSuccessor)->ClearTrait(0xfe8);
                    if (m_pActionSuccessor != ptarget && itype == 0xfc7)
                        ((TileCalls*)m_pActionSuccessor)->ClearTrait(0xfcb);
                    ((IMGamepad*)this)->SetActiveTile(m_pActionSuccessor, itype, 1);
                }
                else if (!((IMGamepad*)this)->HandleMenuInput(pmenu, aiButton, 1.0f) &&
                         ptarget != *(Tile**)((char*)this + 0xbc))
                {
                    ((IMGamepad*)this)->SetActiveTile(ptarget, itype, 1);
                    if (ptarget)
                        ((TileCalls*)ptarget)->ClearTrait(0xfe8);
                }
                else if (ptarget && itype == 0xfc7)
                {
                    ((TileCalls*)ptarget)->ClearTrait(0xfcb);
                }
            }
        }
        else
        {
            int iid;
            Tile* ptarget;
            void* elem = ((IMGamepad*)this)->GetMenuRoot()->kChildren.GetHeadPos();
            while (elem)
            {
                Tile* pmenutile = ((IMGamepad*)this)->GetMenuRoot()->kChildren.GetPrev(elem);
                Menu* pmenu = 0;
                if (pmenutile)
                    pmenu = ((TileCalls*)pmenutile)->GetMenu();
                if (pmenu && ((TileCalls*)pmenutile)->IsVisible() &&
                    ((IMGamepad*)this)->HandleMenuInput(pmenu, aiButton, GetInputButtonCode(aiButton, 1)))
                {
                    ClearGamepadButton(aiButton);
                    return;
                }
            }
            iid = 0;
            if (aiButton == 9)
                iid = 0xfdd;
            else if (aiButton == 10)
                iid = 0xfde;
            else if (aiButton == 11)
                iid = 0xfdf;
            else if (aiButton == 12)
                iid = 0xfe0;
            else if (aiButton == 14)
                iid = 0xfe2;
            else if (aiButton == 13)
                iid = 0xfe1;
            else if (aiButton == 16)
                iid = 0xfe4;
            else if (aiButton == 15)
                iid = 0xfe3;
            else if (aiButton == 5)
                iid = 0xfe7;
            ptarget = ((IMGamepad*)this)->GetActiveTile();
            if (!ptarget)
                ptarget = *(Tile**)((char*)this + 0xcc);
            if (!ptarget)
                ptarget = pmenutile;
            while (ptarget && !((TileCalls*)ptarget)->IsVisible())
                ptarget = ((TileCalls*)ptarget)->GetParent();
            if (ptarget)
            {
                Tile* pparent;
                int itype;
                Tile* ptile = ((TileCalls*)ptarget)->GetTileForTrait(iid, &itype);
                pparent = ptarget;
                while (!ptile && pparent)
                {
                    pparent = ((TileCalls*)pparent)->GetParent();
                    if (pparent)
                        ptile = ((TileCalls*)pparent)->GetTileForTrait(iid, &itype);
                }
                if (aiButton == -2)
                {
                    ptile = ptarget;
                    aiButton = 9;
                    iid = 0xfdd;
                }
                if (ptile && ((TileCalls*)ptile)->IsVisible() && (itype == 0xfc7 || itype == 0xfc5))
                {
                    if (((TileCalls*)ptile)->ContainsTrait(0xfaf))
                    {
                        if (itype == 0xfc5)
                            *(int*)((char*)this + 0x14c) |= 4;
                        ((TileCalls*)ptile)->ClearTrait(0xfcb);
                        ((TileCalls*)ptile)->Set(0xfc7, 1);
                        ((TileCalls*)ptile)->Set(0xfc7, 0);
                        ((TileCalls*)ptile)->GetMenu()->HandleClick(((TileCalls*)ptile)->GetFloat(0xfaa), ptile);
                        if (itype == 0xfc5)
                            *(int*)((char*)this + 0x14c) &= 0xfffb;
                        ClearGamepadButton(aiButton);
                        aiButton = 10;
                        if (aiButton)
                            ClearGamepadButton(6);
                    }
                    else
                    {
                        PlayUISound(2);
                    }
                }
                else if (aiButton == 9 && ((TileCalls*)ptarget)->ContainsTrait(0xfaf))
                {
                    ((TileCalls*)ptarget)->ClearTrait(0xfcb);
                    ((TileCalls*)ptarget)->Set(0xfc7, 1);
                    ((TileCalls*)ptarget)->Set(0xfc7, 0);
                    ((TileCalls*)ptarget)->GetMenu()->HandleClick(((TileCalls*)ptarget)->GetFloat(0xfaa), ptarget);
                    ClearGamepadButton(aiButton);
                }
            }
        }
    }
    else if (ConsoleManager::Instance(true)->IsConsoleActive() && (aiButton == 1 || aiButton == 2))
    {
        *(int*)((char*)this + 0x78) += aiButton == 2 ? -1 : 1;
        if (*(int*)((char*)this + 0x78) < -1)
            *(int*)((char*)this + 0x78) = ((PickRefList*)((char*)this + 0x70))->ItemsInList() - 1;
        else if ((unsigned int)*(int*)((char*)this + 0x78) > ((PickRefList*)((char*)this + 0x70))->ItemsInList() - 1)
            *(int*)((char*)this + 0x78) = -1;
        ((IMGamepad*)this)->ClearMenuInput();
    }
}
}  // namespace fnv_0070f6e0

struct M788
{
    void __thiscall FUN_004ed900(void);
};
extern M788 DAT_011f3324;

// @fnv 0x0070aca0
void __cdecl FUN_0070aca0()
{
    DAT_011f3324.FUN_004ed900();
}

namespace fnv_0070b5d0 {
class AnimIdle;
template <class T> class NiPointer
{
  public:
    NiPointer(T* apObject);
    ~NiPointer();
    NiPointer& operator=(T* apObject);
    T* m_pObject;
};
struct Tile3D
{
    Tile3D();
    virtual ~Tile3D();
    void* pChildHead;
    void* pChildTail;
    unsigned int uiChildCount;
    void* pValues;
    unsigned int uiValueCapacity;
    unsigned int uiValueCount;
    unsigned int uiValueGrowSize;
    char* pName;
    unsigned short usNameLength;
    unsigned short usNameMaxLength;
    Tile3D* pParent;
    void* pNode;
    unsigned int uiFlags;
    char cUnk34;
    char cUnk35;
};
struct FUN_0070b5d0 : public Tile3D
{
    float fScale;
    NiPointer<AnimIdle> spMaterial;
    NiPointer<AnimIdle> spTexture;
    bool m_bTextureLoaded;
    FUN_0070b5d0();
    virtual ~FUN_0070b5d0();
};

// @fnv 0x0070b5d0
FUN_0070b5d0::FUN_0070b5d0() : spMaterial(0), spTexture(0)
{
    fScale = 1.0f;
    spMaterial = 0;
    m_bTextureLoaded = false;
}
}  // namespace fnv_0070b5d0

struct TileImage
{
    const char* __thiscall GetImageTag();
};

// @fnv 0x0070b680
const char* __thiscall TileImage::GetImageTag()
{
    return "IMGE";
}

struct StatsMenu
{
    enum Page
    {
    };
    void SetCurrentPage(Page);
    void SetCurrentPageFromChar(char a);
};

// @fnv 0x0070b7f0
void __thiscall StatsMenu::SetCurrentPageFromChar(char acPage)
{
    SetCurrentPage((StatsMenu::Page)acPage);
}

extern unsigned char DAT_011dea2f;

// @fnv 0x0070ed10
unsigned char __cdecl FUN_0070ed10()
{
    return DAT_011dea2f;
}

extern unsigned char DAT_011dea2f;

// @fnv 0x0070ed20
void FUN_0070ed20(unsigned char value)
{
    DAT_011dea2f = value;
}

// @fnv 0x0070ede0
int __cdecl FUN_0070ede0()
{
    return 0x3f5;
}

struct FUN_00711d60Class
{
    char GetByteAtOffset1B50();
};

// @fnv 0x00711d60
char FUN_00711d60Class::GetByteAtOffset1B50()
{
    return *(char*)((char*)this + 0x1b50);
}

struct FUN_00711e00_StandIn
{
    int mPad;
    int mFlags;
    bool FUN_00711e00();
};

// @fnv 0x00711e00
bool FUN_00711e00_StandIn::FUN_00711e00()
{
    return (mFlags & 8) != 0;
}

struct FUN_00712420_Class
{
    void FUN_00712420(float value);
};

// If the byte flag at offset 0x60 is set, stores value into the float at offset 0x5c.
// @fnv 0x00712420
void FUN_00712420_Class::FUN_00712420(float value)
{
    if (*(unsigned char*)((char*)this + 0x60))
    {
        *(float*)((char*)this + 0x5c) = value;
    }
}

extern int DAT_011f32d4;

// @fnv 0x00713d60
void FUN_00713d60()
{
    DAT_011f32d4 = 0;
}

extern int DAT_011f3330;

// @fnv 0x00713d70
int* FUN_00713d70()
{
    return &DAT_011f3330;
}

struct GlobalObject_008c71d0;
extern GlobalObject_008c71d0 g_011dfa50;

// @fnv 0x00713d80
GlobalObject_008c71d0* FUN_00713d80()
{
    return &g_011dfa50;
}

extern unsigned char DAT_011dfa19;

// @fnv 0x00713d90
unsigned char FUN_00713d90()
{
    return DAT_011dfa19;
}

extern "C" unsigned char* DAT_011f5b04;

struct FUN_00714930
{
    int __thiscall Get();
};

// Returns the result of Get() on the object at offset 0x190 of DAT_011f5b04, or 0 if DAT_011f5b04 is null.
// @fnv 0x00714900
int __cdecl FUN_00714900()
{
    if (DAT_011f5b04)
        return ((FUN_00714930*)(DAT_011f5b04 + 0x190))->Get();
    return 0;
}

extern unsigned char DAT_011f5b08;

// @fnv 0x007149f0
void FUN_007149f0()
{
    DAT_011f5b08 = 1;
}

struct FUN_00714d70
{
    int m_field_0xf0;
    void SetField(int value);
};
// @fnv 0x00714d70
void FUN_00714d70::SetField(int value)
{
    *(int*)((char*)this + 0xf0) = value;
}

namespace fnv_00714d90 {
struct FUN_00714d90_shell : public InterfaceManager
{
    int PushMenuStackEntry(int);
};

struct ImageSpaceManager
{
    static ImageSpaceManager* __cdecl FUN_004e3270();
};
struct S4
{
    void FUN_007123a0(unsigned char);
};
void _FNV_Warning(const char*);

// @fnv 0x00714d90
int FUN_00714d90_shell::PushMenuStackEntry(int aiID)
{
    int a;
    if (aiID == 3)
    {
        int itemp1 = ((int*)((char*)this + 0x114))[0];
        ((int*)((char*)this + 0x114))[0] = 3;
        int a;
        int itemp2;
        for (a = 1; a < 9; a++)
        {
            itemp2 = ((int*)((char*)this + 0x114))[a];
            ((int*)((char*)this + 0x114))[a] = itemp1;
            itemp1 = itemp2;
            if (itemp2 == 0)
                break;
        }
        if (a == 9)
            _FNV_Warning("MENUS: ### Menu Stack Size is too small - a menu may have been lost");
        if (a == 1)
        {
            *(int*)((char*)this + 0xc) = 3;
            if (ImageSpaceManager::FUN_004e3270())
                ((S4*)ImageSpaceManager::FUN_004e3270())->FUN_007123a0(1);
        }
        return a;
    }
    for (a = 0; a < 10; a++)
    {
        if (((int*)((char*)this + 0x114))[a] == 0)
            break;
    }
    if (a >= 10)
        return -1;
    ((int*)((char*)this + 0x114))[a] = aiID;
    if (a == 0)
    {
        *(int*)((char*)this + 0xc) = 3;
        if (aiID != 1001 && ImageSpaceManager::FUN_004e3270())
            ((S4*)ImageSpaceManager::FUN_004e3270())->FUN_007123a0(1);
    }
    else if (a == 1 && ((int*)((char*)this + 0x114))[0] == 1001)
    {
        if (ImageSpaceManager::FUN_004e3270())
            ((S4*)ImageSpaceManager::FUN_004e3270())->FUN_007123a0(1);
    }
    return a;
}
}  // namespace fnv_00714d90

namespace fnv_00715e00 {
struct S0042fa20
{
    S0042fa20* FUN_0045ce80(int);
};
struct TileF
{
    void Set(int, float, bool);
};
struct GlobalObject_0045cfe0
{
};
extern GlobalObject_0045cfe0 g_011d8bd8;
extern GlobalObject_0045cfe0 g_011d8bf0;
float __cdecl FUN_00715da0(void);
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();

struct FUN_00715e00_t
{
    void SetTileValues(int aiWidth, int aiHeight);
};

// If aiWidth is positive, calls FUN_0045ce80 on g_011d8bd8 and on g_011d8bf0 (with aiHeight or aiWidth), then sets four tile values on the tile at this+0x9c.
// @fnv 0x00715e00
void FUN_00715e00_t::SetTileValues(int aiWidth, int aiHeight)
{
    if (aiWidth > 0)
    {
        ((S0042fa20*)&g_011d8bd8)->FUN_0045ce80(aiWidth);
        if (aiHeight > 0)
            ((S0042fa20*)&g_011d8bf0)->FUN_0045ce80(aiHeight);
        else
            ((S0042fa20*)&g_011d8bf0)->FUN_0045ce80(aiWidth);
    }
    ((TileF*)*(Tile**)((char*)this + 0x9c))->Set(0xfc0, FUN_007177c0(), true);
    ((TileF*)*(Tile**)((char*)this + 0x9c))->Set(0xfbf, FUN_00717820(), true);
    ((TileF*)*(Tile**)((char*)this + 0x9c))->Set(0xfb1, InterfaceManager::UpdateInterfaceState(), true);
    ((TileF*)*(Tile**)((char*)this + 0x9c))->Set(0xfb0, FUN_00715da0(), true);
}
}  // namespace fnv_00715e00

namespace fnv_00716320 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct hkpCharacterContext
{
    static float __cdecl GetReferenceTimeStep();
};
struct ArrSIH
{
};
struct TimeGlobal
{
};
extern ArrSIH DAT_011f2250;
extern TimeGlobal g_timeGlobal;
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);

struct FUN_00716320_Node
{
    int iKey;
    float fTimeOffset;
    float fDuration;
    FUN_00716320_Node* pNext;
    FUN_00716320_Node* pPrev;
};
struct FUN_00716320_List
{
    int iUnk00;
    int iUnk04;
    int iUnk08;
    FUN_00716320_Node* pHead;
    FUN_00716320_Node* pTail;
};
struct FUN_00716320_shell
{
    void UpdateNodeTimers();
};

// @fnv 0x00716320
void FUN_00716320_shell::UpdateNodeTimers()
{
    FUN_00716320_Node* pNode = (*(FUN_00716320_List**)((char*)this + 0x164))->pTail;
    while (pNode)
    {
        if (((ArrSI*)&DAT_011f2250)->GetFlags() == 4)
            pNode->fTimeOffset +=
                ((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue() / hkpCharacterContext::GetReferenceTimeStep();
        else
            pNode->fTimeOffset += ((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue();
        if (FUN_00404010(0.0f, FUN_0040ebd0(1.0f, pNode->fTimeOffset / pNode->fDuration)) == 1.0)
        {
            FUN_00716320_Node* pPrev = pNode->pPrev;
            pNode->pNext->pPrev = pPrev;
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            if (!pPrev)
                (*(FUN_00716320_List**)((char*)FUN_004b7210() + 0x164))->pHead = pNode->pNext;
            delete pNode;
            pNode = pPrev;
        }
        else
            pNode = pNode->pPrev;
    }
}
}  // namespace fnv_00716320

namespace fnv_007164c0 {
struct AutoMemHelper
{
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int m_iContext;
};
struct FUN_0070a8a0
{
    int iKey;
    int iUnk04;
    float fValue;
    FUN_0070a8a0* pNext;
    FUN_0070a8a0* pPrev;
    FUN_0070a8a0();
};
struct FUN_007164c0_List
{
    int iUnk00;
    int iUnk04;
    int iUnk08;
    FUN_0070a8a0* pHead;
};
void __cdecl RemoveNodeById(int);
float __cdecl FUN_00404010(float, float);

// @fnv 0x007164c0
void FUN_007164c0(int aiKey, float afValue)
{
    AutoMemHelper MemContext(13, true,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp", 5210);
    RemoveNodeById(aiKey);
    FUN_0070a8a0* pEntry7 = new FUN_0070a8a0;
    pEntry7->iKey = aiKey;
    pEntry7->fValue = FUN_00404010(afValue, 0.0f);
    pEntry7->pNext = (*(FUN_007164c0_List**)((char*)FUN_004b7210() + 0x164))->pHead;
    (*(FUN_007164c0_List**)((char*)FUN_004b7210() + 0x164))->pHead->pPrev = pEntry7;
    (*(FUN_007164c0_List**)((char*)FUN_004b7210() + 0x164))->pHead = pEntry7;
}
}  // namespace fnv_007164c0

namespace fnv_00716730 {
struct AnimIdle
{
    int GetSection();
};
struct Setting_S
{
    float* Float();
};
struct HotkeyWheelDisplay
{
    int HandleHotkeyInput(int, int);
};
struct TimeGlobal
{
};
struct GlobalObject_0044f440
{
};
extern TimeGlobal g_timeGlobal;
extern GlobalObject_0044f440 g_011d8b38;
extern GlobalObject_0044f440 g_011d8b88;

struct FUN_00716730_t : public InterfaceManager
{
    int FUN_00716730(float afScale);
};

// @fnv 0x00716730
int FUN_00716730_t::FUN_00716730(float afScale)
{
    bool bReset;
    unsigned int uiSection = ((AnimIdle*)&g_timeGlobal)->GetSection();
    if (*((Setting_S*)&g_011d8b38)->Float() < 0.0)
        return 0;
    bReset = false;
    if (*(int*)((char*)this + 0x150) == 0x80000001 &&
        !((HotkeyWheelDisplay*)g_osGlobals->FUN_00877720())->HandleHotkeyInput(0xcb, 0))
        bReset = true;
    else if (*(int*)((char*)this + 0x150) == 0x80000002 &&
             !((HotkeyWheelDisplay*)g_osGlobals->FUN_00877720())->HandleHotkeyInput(0xcd, 0))
        bReset = true;
    else if (*(int*)((char*)this + 0x150) == 0x80000003 &&
             !((HotkeyWheelDisplay*)g_osGlobals->FUN_00877720())->HandleHotkeyInput(0xc8, 0))
        bReset = true;
    else if (*(int*)((char*)this + 0x150) == 0x80000004 &&
             !((HotkeyWheelDisplay*)g_osGlobals->FUN_00877720())->HandleHotkeyInput(0xd0, 0))
        bReset = true;
    if (bReset)
    {
        *(int*)((char*)this + 0x150) = 0;
        return 0;
    }
    if (*(unsigned int*)((char*)this + 0x158) == 0)
    {
        if ((double)(uiSection - *(unsigned int*)((char*)this + 0x154)) < *((Setting_S*)&g_011d8b38)->Float())
            return 0;
        else
        {
            *(unsigned int*)((char*)this + 0x158) = uiSection;
            return *(int*)((char*)this + 0x150);
        }
    }
    else
    {
        if ((double)(uiSection - *(unsigned int*)((char*)this + 0x158)) < *((Setting_S*)&g_011d8b88)->Float() / afScale)
            return 0;
        else
        {
            *(unsigned int*)((char*)this + 0x158) = uiSection;
            return *(int*)((char*)this + 0x150);
        }
    }
}
}  // namespace fnv_00716730

namespace fnv_007170a0 {
struct S7010
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    unsigned int Length();
};
struct Str6a70
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    Str6a70& operator=(const char*);
};
struct Flt
{
    operator unsigned int() const;
};
void FUN_004046f0(char*, const char*);
extern const char g_011d31e0_arg1[];

struct TextEditString
{
    S7010 kText;
    Str6a70 kDisplayText;
    int iCursorPos;
    const char* GetDisplayText();
};

// Builds a display string from kText, inserting a cursor marker at iCursorPos when a flag is set, stores it in kDisplayText and returns it.
// @fnv 0x007170a0
const char* TextEditString::GetDisplayText()
{
    char acTemp[1024];
    char acBuffer[1024];
    {
        int iTextLen = kText.Length();
        if (kText.Length() == 0)
            FUN_004046f0(acTemp, "");
        else
            FUN_004046f0(acTemp, (const char*)(unsigned int)*(Flt*)&kText);
        {
            int iIndex;
            int j;
            for (iIndex = 0, j = 0; iIndex <= iTextLen; iIndex++, j++)
            {
                if (*(bool*)((char*)this + 0x21) && iIndex == iCursorPos)
                {
                    if (*(bool*)((char*)this + 0x20))
                        acBuffer[j] = 0x7c;
                    else
                        acBuffer[j] = 0x7f;
                    j++;
                }
                acBuffer[j] = acTemp[iIndex];
            }
            acBuffer[j] = 0;
        }
        kDisplayText = acBuffer;
        if (((S7010*)&kDisplayText)->Length() == 0)
            kDisplayText = g_011d31e0_arg1;
        return (const char*)(unsigned int)*(Flt*)&kDisplayText;
    }
}
}  // namespace fnv_007170a0

extern int DAT_011a0190;

// @fnv 0x00717890
int FUN_00717890()
{
    return DAT_011a0190;
}

namespace fnv_007187a0 {
struct TutorialState
{
    unsigned int FUN_00706810();
    bool FUN_00718840(int);
    void PackFlags(unsigned char* apFlags);
};

// Packs the results of FUN_00718840 for indices i*8+j (skipping 41) into one bitmask byte per element of apFlags.
// @fnv 0x007187a0
void TutorialState::PackFlags(unsigned char* apFlags)
{
    for (unsigned int i = 0; i < FUN_00706810(); i++)
    {
        unsigned char cFlags = 0;
        for (unsigned int j = 0; j < 8; j++)
        {
            int iIndex = i * 8 + j;
            if (iIndex == 41)
                break;
            else
            {
                if (FUN_00718840(iIndex))
                    cFlags |= 1 << j;
            }
        }
        apFlags[i] = cFlags;
    }
}
}  // namespace fnv_007187a0

// @fnv 0x007189c0
int __cdecl FUN_007189c0(int aeButton)
{
    switch (aeButton)
    {
    case 9:
        return 10;
    case 10:
        return 11;
    case 11:
        return 12;
    case 12:
        return 13;
    case 6:
        return 7;
    case 5:
        return 6;
    case 15:
        return 15;
    case 16:
        return 14;
    case 1:
        return 1;
    case 2:
        return 2;
    case 4:
        return 5;
    case 3:
        return 4;
    case 13:
        return 16;
    case 14:
        return 17;
    case 17:
        return 8;
    case 18:
        return 9;
    default:
        return -1;
    }
}

// Splits a 32-bit value into its four bytes, storing them from most significant to least significant in the four output pointers.
// @fnv 0x00719440
void UnpackBytes(unsigned int auiPacked, unsigned int* puiByte3, unsigned int* puiByte2, unsigned int* puiByte1,
                 unsigned int* puiByte0)
{
    *puiByte3 = (auiPacked >> 0x18) & 0xff;
    *puiByte2 = (auiPacked >> 0x10) & 0xff;
    *puiByte1 = (auiPacked >> 8) & 0xff;
    *puiByte0 = auiPacked & 0xff;
}

namespace fnv_0071d380 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct GlobalObject2_0040c150
{
    int* Int();
};
struct GlobalObject_0045cfe0
{
};
extern GlobalObject_0045cfe0 g_011d8cfc;

struct FUN_0071d380_t
{
    void ClampIndexByDelta(int aiDelta);
};

// Adds aiDelta to the value at offset 0x24, clamps it to the array's flags and to the global int, then stores it back.
// @fnv 0x0071d380
void FUN_0071d380_t::ClampIndexByDelta(int aiDelta)
{
    int iIndex = *(int*)((char*)this + 0x24) + aiDelta;
    if (iIndex > (int)((ArrSI*)((char*)this + 4))->GetFlags())
        iIndex = ((ArrSI*)((char*)this + 4))->GetFlags();
    int iTop = iIndex - *((GlobalObject2_0040c150*)&g_011d8cfc)->Int();
    if (iTop <= 0)
        iIndex = *((GlobalObject2_0040c150*)&g_011d8cfc)->Int();
    if (iIndex > (int)((ArrSI*)((char*)this + 4))->GetFlags())
        iIndex = ((ArrSI*)((char*)this + 4))->GetFlags();
    *(int*)((char*)this + 0x24) = iIndex;
}
}  // namespace fnv_0071d380

namespace fnv_007e6620 {
struct TileQ
{
    bool ContainsTrait(int);
};
struct Menu
{
    virtual ~Menu();
    virtual void SetTile(unsigned int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleClick(int, Tile*);
};
struct FUN_007e6620_Button
{
    bool GetByteAtOffset33();
    void FUN_00716b00(int);
};
struct FUN_007e6620_t : public Menu
{
    void FUN_007e6700();
    bool HandleTileClick(int aiTileID);
};

// @fnv 0x007e6620
bool FUN_007e6620_t::HandleTileClick(int aiTileID)
{
    if (aiTileID == 0x80000008)
    {
        if (((TileQ*)*(Tile**)((char*)this + 0x2c))->ContainsTrait(0xfaf))
        {
            HandleClick(1, *(Tile**)((char*)this + 0x2c));
            return true;
        }
        else
            return false;
    }
    else
    {
        if (((FUN_007e6620_Button*)((char*)this + 0x34))->GetByteAtOffset33())
        {
            ((FUN_007e6620_Button*)((char*)this + 0x34))->FUN_00716b00(aiTileID);
            FUN_007e6700();
            return true;
        }
        else
            return false;
    }
}
}  // namespace fnv_007e6620

namespace fnv_00ad8510 {
struct BSAudioManager
{
    static BSAudioManager& __cdecl GetRandomGenerator();
    void FUN_00adcb20(unsigned int a1, unsigned char a2);
    void FUN_00ad8510(unsigned int a1, unsigned char a2);
};

extern "C" BSAudioManager* __cdecl BSAudioManager_QInstance();

BSAudioManager& __cdecl BSAudioManager::GetRandomGenerator()
{
    return *BSAudioManager_QInstance();
}

void BSAudioManager::FUN_00adcb20(unsigned int a1, unsigned char a2)
{
    BSAudioManager::GetRandomGenerator().FUN_00adcb20(a1, a2);
}

// @fnv 0x00ad8510
void BSAudioManager::FUN_00ad8510(unsigned int a1, unsigned char a2)
{
    BSAudioManager::GetRandomGenerator().FUN_00adcb20(a1, a2);
}
}  // namespace fnv_00ad8510

struct BSSystemUtility
{
    static BSSystemUtility* ms_pSystemUtility;
    virtual int ResetSystemUtility(int);
};

// Calls ResetSystemUtility(1) on the BSSystemUtility singleton if set, then clears the singleton pointer.
// @fnv 0x0070ad30
void __cdecl ResetSystemUtility()
{
    BSSystemUtility* pInstance = BSSystemUtility::ms_pSystemUtility;
    BSSystemUtility* pTemp = pInstance;
    int result;
    if (pTemp != 0)
    {
        result = pTemp->ResetSystemUtility(1);
    }
    else
    {
        result = 0;
    }
    BSSystemUtility::ms_pSystemUtility = 0;
}

namespace fnv_0070bbe0 {
struct BSAudio_
{
    void FUN_00ad8510(int, int);
    void FUN_0070bbe0();
};

// @fnv 0x0070bbe0
void BSAudio_::FUN_0070bbe0()
{
    FUN_00ad8510(6, 1);
}
}  // namespace fnv_0070bbe0

namespace fnv_00711dc0 {
struct Setting_S
{
    float* Float();
};

extern Setting_S g_011f360c;

struct FUN_00711dc0
{
    float __thiscall GetFloat();
};

// @fnv 0x00711dc0
float __thiscall FUN_00711dc0::GetFloat()
{
    return *g_011f360c.Float();
}
}  // namespace fnv_00711dc0

struct FUN_007123d0_class
{
    void SetByteAtOffset60(unsigned char param_1);
};

// @fnv 0x007123d0
void FUN_007123d0_class::SetByteAtOffset60(unsigned char aucValue)
{
    *reinterpret_cast<unsigned char*>((char*)this + 0x60) = aucValue;
}

struct FUN_007185e0_class
{
    int m_data[0x29];
    int& operator[](int index)
    {
        return m_data[index];
    }
    bool SetFlag2(int index);
};

// If index is within 0x29, clears bit 0 and sets bit 1 of m_data[index] and returns true; otherwise returns false.
// @fnv 0x007185e0
bool FUN_007185e0_class::SetFlag2(int index)
{
    if (index >= 0 && index < 0x29)
    {
        m_data[index] &= 0xfffffffe;
        m_data[index] |= 2;
        return true;
    }
    else
        return false;
}

char __fastcall GetByteAtOffset33(char*);
void __fastcall ToggleFlagOnInterval(char*);
void __fastcall FUN_007e6700(void*);

struct TextEditMenu
{
    void __thiscall FUN_007e65f0();
};

// @fnv 0x007e65f0
void __thiscall TextEditMenu::FUN_007e65f0()
{
    if ((unsigned char)GetByteAtOffset33((char*)this + 0x34))
    {
        ToggleFlagOnInterval((char*)this + 0x34);
        FUN_007e6700(this);
    }
}

struct FUN_0070c410_class
{
    int m_auiShapeKeys[0xd58 / 4];
    struct Vec3
    {
        float x, y, z;
    } m_pos;
    Vec3& __thiscall GetPosition(Vec3& akDest);
};

// Copies m_pos into akDest and returns akDest.
// @fnv 0x0070c410
FUN_0070c410_class::Vec3& FUN_0070c410_class::GetPosition(Vec3& akDest)
{
    akDest = m_pos;
    return akDest;
}

struct FUN_0070ec20_class
{
    void __thiscall FUN_0070ec20(int a, int b);
};

// Sets the byte at this + a + b*0x1c + 0x1b94 to 0xff.
// @fnv 0x0070ec20
void __thiscall FUN_0070ec20_class::FUN_0070ec20(int a, int b)
{
    ((unsigned char*)this)[a + b * 0x1c + 0x1b94] = 0xff;
}

extern "C" long __ftol2_sse(float);

struct FUN_0070ec70_class
{
    long FUN_0070ec70();
};

// @fnv 0x0070ec70
long FUN_0070ec70_class::FUN_0070ec70()
{
    return (long)*((float*)((char*)this + 0x44));
}

namespace fnv_0070ecb0 {
float __cdecl FUN_00706e20(void);
float __cdecl FUN_00715da0(void);

// Calls FUN_00706e20 and divides its result by the value returned by FUN_00715da0, returning the quotient as a float.
// @fnv 0x0070ecb0
float __cdecl GetRatio(void)
{
    double dTemp8 = FUN_00706e20();
    float fResult = dTemp8 / FUN_00715da0();
    return fResult;
}
}  // namespace fnv_0070ecb0

struct HotkeyWheelDisplay
{
    bool GetVisible();
};

struct FUN_0070f670
{
    char pad[0x1c8];
    HotkeyWheelDisplay m;
    bool GetVisible();
};

// @fnv 0x0070f670
bool FUN_0070f670::GetVisible()
{
    return m.GetVisible();
}

struct FUN_0070f690_Class
{
    unsigned char pad_4bc[0x4bc];
    int m_4bc;
    void* m_4c0;
    void HandleCallbackOrStore(void* arg);
};

// If m_4bc is 0 and arg is set, calls arg as a function; if m_4bc is 3, sets m_4bc to 4 and stores arg in m_4c0.
// @fnv 0x0070f690
void FUN_0070f690_Class::HandleCallbackOrStore(void* apCallback)
{
    if (m_4bc == 0 && apCallback)
        ((void (*)())apCallback)();
    else if (m_4bc == 3)
    {
        m_4bc = 4;
        m_4c0 = apCallback;
    }
}

namespace fnv_007182b0 {
struct M788
{
    void FUN_004ed8c0(void*);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct GlobalObject_0048f200 : M788
{
};
extern GlobalObject_0048f200 g_011d8b2c;
extern ATM g_011d8c18;

// @fnv 0x007182b0
void FUN_007182b0(void* p)
{
    g_011d8c18.QueryPerformanceCounter(0);
    g_011d8b2c.FUN_004ed8c0(&p);
    g_011d8c18.WaitForTasksDuringRendering();
}
}  // namespace fnv_007182b0

void __cdecl _Deallocate(void*);

struct FUN_0070a100_Class
{
    void FUN_0070a920();
    void* FUN_0070a100(unsigned int flags);
};

// Calls FUN_0070a920, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0070a100
void* FUN_0070a100_Class::FUN_0070a100(unsigned int flags)
{
    FUN_0070a920();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0070ad00 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_0070ad00_Class
{
    void __thiscall FUN_0071b040();
    void* __thiscall FUN_0070ad00(unsigned int flags);
};

// Calls FUN_0071b040, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0070ad00
void* __thiscall FUN_0070ad00_Class::FUN_0070ad00(unsigned int flags)
{
    FUN_0071b040();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0070ad00

namespace fnv_0070ad80 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_0070ad80_Class
{
    void __thiscall FUN_00631a50();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_00631a50, frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0070ad80
void* __thiscall FUN_0070ad80_Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_00631a50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0070ad80

namespace fnv_0070b8f0 {
class AutoMemHelper
{
  public:
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
    int m_data;
};
class NiAVObject
{
  public:
    void SetAppCulled(bool);
};
class RgbaColor
{
  public:
    NiNode* FUN_0056c7f0();
};
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TileHelper
{
    void Set(int, const char*, bool);
};
struct FUN_00a04640_cls
{
    void FUN_00a04640(bool);
};
struct FUN_00a237b0_cls
{
    void FUN_00a237b0();
};
class StartMenu
{
  public:
    const char* GetMenuTitle();
};
class GlobalObject_0040c150 : public StartMenu
{
};
extern GlobalObject_0040c150 g_011d475c;
class TESObjectREFR;
class HUDMainMenu
{
  public:
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
};
struct FUN_0071d770_shell
{
    void FUN_0071d770();
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
};
struct BSAudio_
{
    void FUN_0070bba0();
    void FUN_0070bbe0();
    void FUN_0070bc00();
};
class BSAudioManager;
void __fastcall FUN_0070bbc0(BSAudioManager*);
bool __fastcall FUN_00644640(void*);
void __fastcall UpdateNodeTimers(InterfaceManager*);
struct FUN_0070b8f0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int m_uiContentCount;
    bool m_10;
    bool m_11;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char m_20;
    unsigned char m_21;
    unsigned short unk22;
    unsigned int unk24;
    Tile* m_tile;
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
    bool unk7C;
    bool m_7d;
    unsigned short unk7E;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    int m_bc;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    bool unkEC;
    bool m_ed;
    void UpdateStartMenuState();
};
// Advances the start menu state (3 to 5, 5 to 2), configures the tile and HUD, and toggles audio counters based on FUN_00644640.
// @fnv 0x0070b8f0
void FUN_0070b8f0_shell::UpdateStartMenuState()
{
    AutoMemHelper autoMem(0xd, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp",
                          0x33a);
    InputManager* pInputManager = g_osGlobals->FUN_00877720();
    UpdateNodeTimers((InterfaceManager*)this);
    if (m_uiContentCount == 3 && !m_11)
    {
        ((FUN_00a237b0_cls*)pInputManager)->FUN_00a237b0();
        m_uiContentCount = 5;
        if (!FUN_004b71d0() || m_7d)
        {
            ((NiAVObject*)((RgbaColor*)m_tile)->FUN_0056c7f0())->SetAppCulled(false);
            ((Tile_Set_Helper*)m_tile)->Set(0xfa3, 1);
        }
        ((TileHelper*)m_tile)->Set(0xfcc, g_011d475c.GetMenuTitle(), true);
        ((FUN_00a04640_cls*)m_tile)->FUN_00a04640(true);
        HUDMainMenu::UpdateTargetReference(0, false, false);
        m_bc = 0;
        if (FUN_004b71d0() && !m_7d)
            m_ed = false;
        ConsoleManager* pConsole = ConsoleManager::Instance(false);
        if (pConsole)
            ((FUN_0071d770_shell*)pConsole)->FUN_0071d770();
        ((FUN_0070b8f0_shell*)FUN_004b7210())->m_20++;
        ((BSAudio_*)BSAudio::GetSingleton())->FUN_0070bba0();
        ((FUN_0070b8f0_shell*)FUN_004b7210())->m_21++;
        ((BSAudio_*)BSAudio::GetSingleton())->FUN_0070bbe0();
    }
    else if (m_uiContentCount == 5)
    {
        m_uiContentCount = 2;
    }
    if (m_uiContentCount == 1)
    {
        if (FUN_00644640(this))
        {
            if (!m_10)
            {
                m_10 = true;
                ((FUN_0070b8f0_shell*)FUN_004b7210())->m_20++;
                ((BSAudio_*)BSAudio::GetSingleton())->FUN_0070bba0();
                ((FUN_0070b8f0_shell*)FUN_004b7210())->m_21++;
                ((BSAudio_*)BSAudio::GetSingleton())->FUN_0070bbe0();
            }
        }
        else if (m_10)
        {
            m_10 = false;
            if (((FUN_0070b8f0_shell*)FUN_004b7210())->m_21)
            {
                ((FUN_0070b8f0_shell*)FUN_004b7210())->m_21--;
                ((BSAudio_*)BSAudio::GetSingleton())->FUN_0070bc00();
            }
            if (((FUN_0070b8f0_shell*)FUN_004b7210())->m_20)
            {
                ((FUN_0070b8f0_shell*)FUN_004b7210())->m_20--;
                FUN_0070bbc0((BSAudioManager*)BSAudio::GetSingleton());
            }
        }
    }
}
}  // namespace fnv_0070b8f0

namespace fnv_007134d0 {
struct BSCompoundFrustum;
struct BSCullingProcess;
struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct NiAVObject;
struct NiAccumulator;
struct NiCullingProcess;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct NiVisibleArray;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;
struct FUN_007134d0_shell : public InterfaceManager
{
    void FUN_007134d0(BSCullingProcess*, bool);
};

struct CrimeFlag_007134d0
{
    unsigned char* GetLifeStateControlFlag();
};
extern CrimeFlag_007134d0 g_011d8ab0;
extern CrimeFlag_007134d0 g_011d8ba0;
extern CrimeFlag_007134d0 g_011db2cc;
struct Camera_007134d0;
struct Accum_007134d0;
struct Renderer_007134d0
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int FUN_c8();
    virtual int FUN_cc();
    void SetCurrentCamera(Camera_007134d0*);
};
Renderer_007134d0* __cdecl FUN_0043c4b0();
struct AVObject_007134d0
{
    void SetAppCulled(bool);
    bool FUN_00456610();
};
struct FUN_004a0fd0_shell
{
    void FUN_004a0fd0(::NiNode*);
};
struct MTRender_007134d0
{
    static MTRender_007134d0* __cdecl GetSingleton();
};
struct MTRenderingSystem_Helper
{
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};
struct Flt_Helper
{
    operator unsigned int() const;
};
struct Tile_Helper
{
    AVObject_007134d0* FUN_0056c7f0();
};
struct SceneRoot_007134d0
{
    Camera_007134d0* GetAnimationData();
};
struct IfaceHelper_007134d0
{
    bool FUN_00644640();
};
void __cdecl FUN_00702c80(bool, bool);
void __cdecl UpdateMenuTileVisibility();
struct Interface_Helper
{
    static bool __cdecl IsInterfaceActive();
};
struct FUN_007079f0_shell
{
    bool FUN_007079f0();
};
void __fastcall FUN_00713c70(void*);
void __cdecl FUN_00b6bee0(Camera_007134d0*, ::NiNode*, BSCullingProcess*);
struct ShaderUtil_007134d0
{
    static void __cdecl SetRenderCamera(Camera_007134d0*, Accum_007134d0*, bool);
};
struct FUN_00c4f270_shell
{
    void FUN_00c4f270(int);
    void FUN_00c4f2d0();
};
struct _Rect16_00712e60
{
    int a;
};
struct _Cam_00712e60
{
    void FUN_00712e60(const _Rect16_00712e60&);
};
struct MenuBase_007134d0;
MenuBase_007134d0* __cdecl FindMenuById(int);
extern _Rect16_00712e60 DAT_011ad840;

// @fnv 0x007134d0
void FUN_007134d0_shell::FUN_007134d0(BSCullingProcess* apCuller, bool abPipboyVisible)
{
    reinterpret_cast<FUN_00c4f270_shell*>(apCuller)->FUN_00c4f270(1);
    Renderer_007134d0* pr = FUN_0043c4b0();
    if (*g_011d8ba0.GetLifeStateControlFlag() && *g_011db2cc.GetLifeStateControlFlag())
    {
        ::NiNode* pscene_graph = reinterpret_cast<Interface*>(this)->GetRoot();
        if (*((unsigned char*)this + 0x148))
        {
            reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba3130(1, 0x17);
        }
        else
        {
            if (!reinterpret_cast<IfaceHelper_007134d0*>(this)->FUN_00644640() &&
                !Interface_Helper::IsInterfaceActive())
                FUN_00713c70(this);
            if (reinterpret_cast<FUN_007079f0_shell*>(this)->FUN_007079f0() && !Interface_Helper::IsInterfaceActive())
                FUN_00702c80(false, false);
        }
        Tile_Helper* pcomputerMenu = reinterpret_cast<Tile_Helper*>(FindMenuById(0x421));
        Tile_Helper* praceSexMenu = reinterpret_cast<Tile_Helper*>(FindMenuById(0x40c));
        Tile_Helper* phackingMenu = reinterpret_cast<Tile_Helper*>(FindMenuById(0x41f));
        if (pcomputerMenu && pcomputerMenu->FUN_0056c7f0() && !pcomputerMenu->FUN_0056c7f0()->FUN_00456610())
            pcomputerMenu->FUN_0056c7f0()->SetAppCulled(true);
        else
            pcomputerMenu = 0;
        if (praceSexMenu && praceSexMenu->FUN_0056c7f0() && !praceSexMenu->FUN_0056c7f0()->FUN_00456610())
            praceSexMenu->FUN_0056c7f0()->SetAppCulled(true);
        else
            praceSexMenu = 0;
        if (phackingMenu && phackingMenu->FUN_0056c7f0() && !phackingMenu->FUN_0056c7f0()->FUN_00456610())
            phackingMenu->FUN_0056c7f0()->SetAppCulled(true);
        else
            phackingMenu = 0;
        if (!*((unsigned char*)this + 0x148))
        {
            reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(
                (::NiNode*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c));
            FUN_00b6bee0(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(), pscene_graph,
                         apCuller);
            reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba30f0(0, 0x17);
            reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba3130(1, 0x17);
        }
        if (FUN_0043c4b0()->FUN_cc() == FUN_0043c4b0()->FUN_c8())
            reinterpret_cast<_Cam_00712e60*>(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData())
                ->FUN_00712e60(DAT_011ad840);
        ShaderUtil_007134d0::SetRenderCamera(
            reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(),
            (Accum_007134d0*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c), false);
        reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(0);
        if (pcomputerMenu && pcomputerMenu->FUN_0056c7f0() && pcomputerMenu->FUN_0056c7f0()->FUN_00456610())
            pcomputerMenu->FUN_0056c7f0()->SetAppCulled(false);
        if (praceSexMenu && praceSexMenu->FUN_0056c7f0() && praceSexMenu->FUN_0056c7f0()->FUN_00456610())
            praceSexMenu->FUN_0056c7f0()->SetAppCulled(false);
        if (phackingMenu && phackingMenu->FUN_0056c7f0() && phackingMenu->FUN_0056c7f0()->FUN_00456610())
            phackingMenu->FUN_0056c7f0()->SetAppCulled(false);
        if (reinterpret_cast<FUN_007079f0_shell*>(this)->FUN_007079f0() && !Interface_Helper::IsInterfaceActive())
            UpdateMenuTileVisibility();
        if (*g_011d8ab0.GetLifeStateControlFlag())
        {
            FUN_00702c80(true, false);
            ::NiNode* pscene_graph = reinterpret_cast<Interface*>(this)->GetRoot();
            reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(
                (::NiNode*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c));
            FUN_00b6bee0(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(), pscene_graph,
                         apCuller);
            ShaderUtil_007134d0::SetRenderCamera(
                reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(),
                (Accum_007134d0*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c), false);
            reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(0);
            UpdateMenuTileVisibility();
        }
    }
    else if (!*g_011d8ba0.GetLifeStateControlFlag() && !*g_011db2cc.GetLifeStateControlFlag())
    {
        if (*((unsigned char*)this + 0x148))
            reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba3130(1, 0x17);
        UpdateMenuTileVisibility();
        ::NiNode* pscene_graph = reinterpret_cast<Interface*>(this)->GetRoot();
        if (!*((unsigned char*)this + 0x148))
        {
            reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(
                (::NiNode*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c));
            FUN_00b6bee0(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(), pscene_graph,
                         apCuller);
        }
        ShaderUtil_007134d0::SetRenderCamera(
            reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(),
            (Accum_007134d0*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c), false);
        reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(0);
    }
    else if (!*g_011d8ba0.GetLifeStateControlFlag())
    {
        if (*((unsigned char*)this + 0x148))
            reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba3130(1, 0x17);
        FUN_00702c80(true, false);
        ::NiNode* pscene_graph = reinterpret_cast<Interface*>(this)->GetRoot();
        pr->SetCurrentCamera(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData());
        if (!*((unsigned char*)this + 0x148))
        {
            reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(
                (::NiNode*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c));
            FUN_00b6bee0(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(), pscene_graph,
                         apCuller);
        }
        ShaderUtil_007134d0::SetRenderCamera(
            reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(),
            (Accum_007134d0*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c), false);
        reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(0);
        UpdateMenuTileVisibility();
        FUN_00702c80(false, false);
        pscene_graph = reinterpret_cast<Interface*>(this)->GetRoot();
        pr->SetCurrentCamera(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData());
        reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(
            (::NiNode*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c));
        FUN_00b6bee0(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(), pscene_graph, apCuller);
        ShaderUtil_007134d0::SetRenderCamera(
            reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(),
            (Accum_007134d0*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c), false);
        reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(0);
        UpdateMenuTileVisibility();
    }
    else if (!*g_011db2cc.GetLifeStateControlFlag())
    {
        if (*((unsigned char*)this + 0x148))
            reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba3130(1, 0x17);
        FUN_00702c80(true, true);
        ::NiNode* pscene_graph = reinterpret_cast<Interface*>(this)->GetRoot();
        pr->SetCurrentCamera(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData());
        if (!*((unsigned char*)this + 0x148))
        {
            reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(
                (::NiNode*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c));
            FUN_00b6bee0(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(), pscene_graph,
                         apCuller);
        }
        if (!FUN_0043c4b0()->FUN_cc())
            reinterpret_cast<_Cam_00712e60*>(reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData())
                ->FUN_00712e60(DAT_011ad840);
        ShaderUtil_007134d0::SetRenderCamera(
            reinterpret_cast<SceneRoot_007134d0*>(pscene_graph)->GetAnimationData(),
            (Accum_007134d0*)(unsigned int)*reinterpret_cast<Flt_Helper*>((char*)this + 0x8c), false);
        reinterpret_cast<FUN_004a0fd0_shell*>(apCuller)->FUN_004a0fd0(0);
        UpdateMenuTileVisibility();
    }
    else if (*((unsigned char*)this + 0x148))
    {
        reinterpret_cast<MTRenderingSystem_Helper*>(MTRender_007134d0::GetSingleton())->FUN_00ba3130(1, 0x17);
    }
    reinterpret_cast<FUN_00c4f270_shell*>(apCuller)->FUN_00c4f2d0();
}
}  // namespace fnv_007134d0

namespace fnv_0070a0b0 {
struct FUN_0070a100_Class
{
    void* FUN_0070a100(unsigned int);
};
extern FUN_0070a100_Class* DAT_011d8a80;
// @fnv 0x0070a0b0
void FUN_0070a0b0()
{
    if (DAT_011d8a80)
    {
        FUN_0070a100_Class* q = DAT_011d8a80;
        FUN_0070a100_Class* p = q;
        void* r;
        if (p)
            r = p->FUN_0070a100(1);
        else
            r = 0;
        DAT_011d8a80 = 0;
    }
}
}  // namespace fnv_0070a0b0

struct FUN_0070acb0_s
{
    void* FUN_0070ad00(int);
};
extern ConsoleManager* DAT_MenuConsole_pInstance;
// @fnv 0x0070acb0
void DestroyMenuConsoleSingleton()
{
    ConsoleManager* a;
    FUN_0070acb0_s* p;
    void* r;
    if (DAT_MenuConsole_pInstance)
    {
        a = DAT_MenuConsole_pInstance;
        p = reinterpret_cast<FUN_0070acb0_s*>(a);
        if (p)
            r = p->FUN_0070ad00(1);
        else
            r = 0;
    }
    DAT_MenuConsole_pInstance = 0;
}

struct TileQ
{
    TileQ* GetNext();
    bool ContainsTrait(int);
};
struct InventoryMenu
{
    static InventoryMenu* ms_pInventoryMenu;
    static int ms_iKeyringOpenTileID;
};
// @fnv 0x0070ed30
char FUN_0070ed30()
{
    int result;
    if (InventoryMenu::ms_pInventoryMenu && reinterpret_cast<TileQ*>(InventoryMenu::ms_pInventoryMenu)
                                                ->GetNext()
                                                ->ContainsTrait(InventoryMenu::ms_iKeyringOpenTileID))
        result = 1;
    else
        result = 0;
    return (char)result;
}

namespace fnv_0070ee30 {
struct SM7d6
{
    enum Flag
    {
        F1 = 0x8000,
        F2 = 8
    };
    bool IsFlagSet(Flag);
};
extern SM7d6* DAT_011daac0;

// Returns true when DAT_011daac0 has both flag F1 and flag F2 set.
// @fnv 0x0070ee30
bool IsBothFlagsSet()
{
    return DAT_011daac0->IsFlagSet(SM7d6::F1) && DAT_011daac0->IsFlagSet(SM7d6::F2);
}
}  // namespace fnv_0070ee30

struct FUN_007149b0
{
    int Method(int a);
};
extern unsigned char* DAT_011f5b04;
void FUN_007149f0();
// If DAT_011f5b04 is set, calls Method(a) on the object at offset 0x190; when it returns 1, calls FUN_007149f0 and Method(-1). Returns 0.
// @fnv 0x00714960
int FUN_00714960(int a)
{
    if (DAT_011f5b04)
    {
        int r = ((FUN_007149b0*)(DAT_011f5b04 + 0x190))->Method(a);
        if (r == 1)
        {
            FUN_007149f0();
            ((FUN_007149b0*)(DAT_011f5b04 + 0x190))->Method(-1);
        }
    }
    return 0;
}

struct BSS
{
    char a[8];
    ~BSS();
};

struct FUN_00716a10
{
    BSS m0;
    BSS m1;
    ~FUN_00716a10();
};

// Destructor for a struct holding two BSS members; the body is empty and the members are destroyed implicitly.
// @fnv 0x00716a10
FUN_00716a10::~FUN_00716a10()
{}

struct TESDataHandler
{
    bool FUN_004516b0();
};
extern TESDataHandler* g_dataHandler;
extern void* _g_thePlayer;
struct FUN_00717600_shell
{
    void FUN_00717660();
    void FUN_00717600();
};
// @fnv 0x00717600
void FUN_00717600_shell::FUN_00717600()
{
    if (_g_thePlayer && ((unsigned char*)this)[0xc9] && !g_dataHandler->FUN_004516b0())
    {
        void* cmode = *(void**)((char*)this + 0xc);
        FUN_00717660();
        *(void**)((char*)this + 0xc) = cmode;
        ((char*)this)[0xc9] = 0;
    }
}

struct FUN_0070f490_Class
{
    int GetSlotValue(int index);
};

// Maps index 0x15 to slot 4 and 0x14 to slot 1, then returns the int at this+0x5c+slot*4.
// @fnv 0x0070f490
int FUN_0070f490_Class::GetSlotValue(int index)
{
    int slot = index;
    switch (index)
    {
    case 0x15:
        slot = 4;
        break;
    case 0x14:
        slot = 1;
        break;
    }
    return *(int*)((char*)this + slot * 4 + 0x5c);
}

namespace fnv_0070ed80 {
struct StatsMenu
{
    char pad[0x2a0];
    bool bIsActive;  // +0x2a0
    static StatsMenu* ms_pInventoryMenu;
};

// Returns true if the StatsMenu singleton exists and its bIsActive flag is set, otherwise false.
// @fnv 0x0070ed80
bool IsStatsMenuActive()
{
    int result;
    if (StatsMenu::ms_pInventoryMenu != 0 && StatsMenu::ms_pInventoryMenu->bIsActive)
        result = 1;
    else
        result = 0;
    return *(bool*)&result;
}
}  // namespace fnv_0070ed80

namespace fnv_00718930 {
struct LLD_PlayerCharacter
{
    void FUN_00718930(bool);
    void SetFlag4(bool);
    void SetCameraPathEnabled(bool, unsigned int);
};

LLD_PlayerCharacter* _g_thePlayer;

// @fnv 0x00718930
void LLD_PlayerCharacter::FUN_00718930(bool flag)
{
    _g_thePlayer->SetFlag4(flag);
    _g_thePlayer->SetCameraPathEnabled(flag, 1);
}
}  // namespace fnv_00718930

class NiNode;

struct TileProxy
{
    virtual ~TileProxy()
    {}
    bool ContainsTrait(int value);
    TileProxy* ReadFile();
    void Set(int value1, int value2);
    NiNode* FUN_0056c7f0();
};

struct Dummy00712450
{
    int SetNodeAlpha(NiNode* node, float value1, float value2);
    unsigned char padding[0xb8];
};

struct IMH : public Dummy00712450
{
    TileProxy* tile;
    TileProxy* FUN_00586150(const char* path);
    void SetSafeZone(int value);
};

// @fnv 0x00715ec0
void IMH::SetSafeZone(int value)
{
    bool flag = true;

    if (this->tile != 0 && value == 2)
        flag = !this->tile->ContainsTrait(0xfa3);

    if (value == 1)
        flag = true;
    else if (value == 0)
        flag = false;

    if (value == 3)
    {
        delete this->tile;
        this->tile = 0;
    }

    if (this->tile == 0)
    {
        this->tile = this->FUN_00586150("Data\\Menus\\Main\\safe_zone.xml")->ReadFile();
        this->tile->Set(0xfa3, 1);
        this->SetNodeAlpha(this->tile->FUN_0056c7f0(), 1.0f, 0.0f);
    }
    else if (this->tile != 0)
    {
        delete this->tile;
        this->tile = 0;
    }
}

struct StrObj
{
    StrObj();
    ~StrObj();
    const char* FUN_00559450();
    void* m_data;
    int m_len;
};
int __cdecl FUN_00406f60(StrObj*, const char*, ...);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
const char* __cdecl FUN_00464f30(const char*, bool);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
unsigned char __cdecl FUN_00509510(int);
struct GObj
{
    int* FUN_0043d4d0();
};
extern GObj DAT_011f33c8;
extern GObj DAT_011debac;
void* __stdcall FUN_005bd5b0(int);
struct FontObj
{
    float FUN_005bd580();
};
struct FontMgr
{
    FontObj* FUN_005bd5c0();
};
extern float DAT_0103a1c4;
extern float DAT_01012054;
extern double DAT_0102f248;
extern int DAT_011d8c78;
extern char DAT_011841cc;
extern char DAT_011846d4;
struct SettingObj
{
    const char* FUN_00403df0();
};
extern SettingObj* DAT_01184a98[];
struct PlayerObj
{
    float FUN_00567400();
};
extern PlayerObj* DAT_011dea3c;
struct DebugText
{
    int CreateLine(const char*, float, float, int, int, float, int, const void*);
};
DebugText* __cdecl FUN_00a0d9e0(bool);
struct FormObj
{
    virtual void fvp0();
    virtual void fvp1();
    virtual void fvp2();
    virtual void fvp3();
    virtual void fvp4();
    virtual void fvp5();
    virtual void fvp6();
    virtual void fvp7();
    virtual void fvp8();
    virtual void fvp9();
    virtual void fvp10();
    virtual void fvp11();
    virtual void fvp12();
    virtual void fvp13();
    virtual void fvp14();
    virtual void fvp15();
    virtual void fvp16();
    virtual void fvp17();
    virtual void fvp18();
    virtual void fvp19();
    virtual void fvp20();
    virtual void fvp21();
    virtual void fvp22();
    virtual void fvp23();
    virtual void fvp24();
    virtual void fvp25();
    virtual void fvp26();
    virtual void fvp27();
    virtual void fvp28();
    virtual void fvp29();
    virtual void fvp30();
    virtual void fvp31();
    virtual void fvp32();
    virtual void fvp33();
    virtual void fvp34();
    virtual void fvp35();
    virtual void fvp36();
    virtual void fvp37();
    virtual void fvp38();
    virtual void fvp39();
    virtual void fvp40();
    virtual void fvp41();
    virtual void fvp42();
    virtual void fvp43();
    virtual void fvp44();
    virtual void fvp45();
    virtual void fvp46();
    virtual void fvp47();
    virtual void fvp48();
    virtual void fvp49();
    virtual void fvp50();
    virtual void fvp51();
    virtual void fvp52();
    virtual void fvp53();
    virtual void fvp54();
    virtual void fvp55();
    virtual void fvp56();
    virtual void fvp57();
    virtual void fvp58();
    virtual void fvp59();
    virtual void fvp60();
    virtual void fvp61();
    virtual void fvp62();
    virtual void fvp63();
    virtual void fvp64();
    virtual void fvp65();
    virtual void fvp66();
    virtual void fvp67();
    virtual void fvp68();
    virtual void fvp69();
    virtual void fvp70();
    virtual void fvp71();
    virtual void fvp72();
    virtual void fvp73();
    virtual void fvp74();
    virtual void fvp75();
    virtual const char* fv130();
    unsigned int FUN_0084e3a0();
};
struct ExtraObj
{
    FormObj* FUN_00418800();
    short FUN_00418770();
};
struct FullName
{
    const char* FUN_00408da0();
};
struct KeyObj
{
    char pad[0x30];
    FullName m_fn;
};
struct ProcObj
{
    virtual void pvp0();
    virtual void pvp1();
    virtual void pvp2();
    virtual void pvp3();
    virtual void pvp4();
    virtual void pvp5();
    virtual void pvp6();
    virtual void pvp7();
    virtual void pvp8();
    virtual void pvp9();
    virtual void pvp10();
    virtual void pvp11();
    virtual void pvp12();
    virtual void pvp13();
    virtual void pvp14();
    virtual void pvp15();
    virtual void pvp16();
    virtual void pvp17();
    virtual void pvp18();
    virtual void pvp19();
    virtual void pvp20();
    virtual void pvp21();
    virtual void pvp22();
    virtual void pvp23();
    virtual void pvp24();
    virtual void pvp25();
    virtual void pvp26();
    virtual void pvp27();
    virtual void pvp28();
    virtual void pvp29();
    virtual void pvp30();
    virtual void pvp31();
    virtual void pvp32();
    virtual void pvp33();
    virtual void pvp34();
    virtual void pvp35();
    virtual void pvp36();
    virtual void pvp37();
    virtual void pvp38();
    virtual void pvp39();
    virtual void pvp40();
    virtual void pvp41();
    virtual void pvp42();
    virtual void pvp43();
    virtual void pvp44();
    virtual void pvp45();
    virtual void pvp46();
    virtual void pvp47();
    virtual void pvp48();
    virtual void pvp49();
    virtual void pvp50();
    virtual void pvp51();
    virtual void pvp52();
    virtual void pvp53();
    virtual void pvp54();
    virtual void pvp55();
    virtual void pvp56();
    virtual void pvp57();
    virtual void pvp58();
    virtual void pvp59();
    virtual void pvp60();
    virtual void pvp61();
    virtual void pvp62();
    virtual void pvp63();
    virtual void pvp64();
    virtual void pvp65();
    virtual void pvp66();
    virtual void pvp67();
    virtual void pvp68();
    virtual void pvp69();
    virtual void pvp70();
    virtual void pvp71();
    virtual void pvp72();
    virtual void pvp73();
    virtual void pvp74();
    virtual void pvp75();
    virtual void pvp76();
    virtual void pvp77();
    virtual void pvp78();
    virtual void pvp79();
    virtual void pvp80();
    virtual void pvp81();
    virtual void pvp82();
    virtual void pvp83();
    virtual void pvp84();
    virtual void pvp85();
    virtual void pvp86();
    virtual void pvp87();
    virtual void pvp88();
    virtual void pvp89();
    virtual void pvp90();
    virtual void pvp91();
    virtual void pvp92();
    virtual void pvp93();
    virtual void pvp94();
    virtual void pvp95();
    virtual void pvp96();
    virtual void pvp97();
    virtual void pvp98();
    virtual void pvp99();
    virtual void pvp100();
    virtual void pvp101();
    virtual void pvp102();
    virtual void pvp103();
    virtual void pvp104();
    virtual void pvp105();
    virtual void pvp106();
    virtual void pvp107();
    virtual void pvp108();
    virtual void pvp109();
    virtual void pvp110();
    virtual void pvp111();
    virtual void pvp112();
    virtual void pvp113();
    virtual void pvp114();
    virtual void pvp115();
    virtual void pvp116();
    virtual void pvp117();
    virtual void pvp118();
    virtual void pvp119();
    virtual void pvp120();
    virtual void pvp121();
    virtual void pvp122();
    virtual void pvp123();
    virtual void pvp124();
    virtual void pvp125();
    virtual void pvp126();
    virtual void pvp127();
    virtual void pvp128();
    virtual void pvp129();
    virtual void pvp130();
    virtual void pvp131();
    virtual void pvp132();
    virtual void pvp133();
    virtual void pvp134();
    virtual void pvp135();
    virtual void pvp136();
    virtual void pvp137();
    virtual void pvp138();
    virtual void pvp139();
    virtual void pvp140();
    virtual void pvp141();
    virtual void pvp142();
    virtual void pvp143();
    virtual void pvp144();
    virtual void pvp145();
    virtual void pvp146();
    virtual void pvp147();
    virtual void pvp148();
    virtual void pvp149();
    virtual void pvp150();
    virtual void pvp151();
    virtual void pvp152();
    virtual void pvp153();
    virtual void pvp154();
    virtual void pvp155();
    virtual void pvp156();
    virtual void pvp157();
    virtual void pvp158();
    virtual void pvp159();
    virtual void pvp160();
    virtual void pvp161();
    virtual void pvp162();
    virtual void pvp163();
    virtual void pvp164();
    virtual void pvp165();
    virtual void pvp166();
    virtual void pvp167();
    virtual void pvp168();
    virtual void pvp169();
    virtual void pvp170();
    virtual void pvp171();
    virtual void pvp172();
    virtual void pvp173();
    virtual void pvp174();
    virtual void pvp175();
    virtual void pvp176();
    virtual void pvp177();
    virtual void pvp178();
    virtual void pvp179();
    virtual void pvp180();
    virtual void pvp181();
    virtual void pvp182();
    virtual void pvp183();
    virtual void pvp184();
    virtual void pvp185();
    virtual void pvp186();
    virtual void pvp187();
    virtual void pvp188();
    virtual void pvp189();
    virtual void pvp190();
    virtual void pvp191();
    virtual void pvp192();
    virtual void pvp193();
    virtual void pvp194();
    virtual void pvp195();
    virtual void pvp196();
    virtual void pvp197();
    virtual void pvp198();
    virtual void pvp199();
    virtual void pvp200();
    virtual void pvp201();
    virtual void pvp202();
    virtual void pvp203();
    virtual void pvp204();
    virtual void pvp205();
    virtual void pvp206();
    virtual void pvp207();
    virtual void pvp208();
    virtual void pvp209();
    virtual void pvp210();
    virtual void pvp211();
    virtual void pvp212();
    virtual void pvp213();
    virtual void pvp214();
    virtual void pvp215();
    virtual void pvp216();
    virtual void pvp217();
    virtual void pvp218();
    virtual void pvp219();
    virtual void pvp220();
    virtual void pvp221();
    virtual void pvp222();
    virtual void pvp223();
    virtual void pvp224();
    virtual void pvp225();
    virtual void pvp226();
    virtual void pvp227();
    virtual void pvp228();
    virtual void pvp229();
    virtual void pvp230();
    virtual void pvp231();
    virtual void pvp232();
    virtual void pvp233();
    virtual void pvp234();
    virtual void pvp235();
    virtual void pvp236();
    virtual void pvp237();
    virtual void pvp238();
    virtual void pvp239();
    virtual void pvp240();
    virtual void pvp241();
    virtual void pvp242();
    virtual void pvp243();
    virtual void pvp244();
    virtual void pvp245();
    virtual void pvp246();
    virtual void pvp247();
    virtual void pvp248();
    virtual void pvp249();
    virtual void pvp250();
    virtual void pvp251();
    virtual void pvp252();
    virtual void pvp253();
    virtual void pvp254();
    virtual void pvp255();
    virtual void pvp256();
    virtual void pvp257();
    virtual void pvp258();
    virtual void pvp259();
    virtual void pvp260();
    virtual void pvp261();
    virtual void pvp262();
    virtual void pvp263();
    virtual void pvp264();
    virtual void pvp265();
    virtual void pvp266();
    virtual void pvp267();
    virtual void pvp268();
    virtual void pvp269();
    virtual void pvp270();
    virtual void pvp271();
    virtual void pvp272();
    virtual void pvp273();
    virtual void pvp274();
    virtual void pvp275();
    virtual void pvp276();
    virtual void pvp277();
    virtual void pvp278();
    virtual void pvp279();
    virtual void pvp280();
    virtual void pvp281();
    virtual void pvp282();
    virtual void pvp283();
    virtual void pvp284();
    virtual void pvp285();
    virtual void pvp286();
    virtual void pvp287();
    virtual void pvp288();
    virtual void pvp289();
    virtual void pvp290();
    virtual void pvp291();
    virtual void pvp292();
    virtual void pvp293();
    virtual void pvp294();
    virtual void pvp295();
    virtual void pvp296();
    virtual void pvp297();
    virtual void pvp298();
    virtual void pvp299();
    virtual void pvp300();
    virtual void pvp301();
    virtual void pvp302();
    virtual void pvp303();
    virtual void pvp304();
    virtual void pvp305();
    virtual struct FormObj* pv4c8();
    virtual void pvp307();
    virtual int pv4d0();
};
struct Obj50
{
    int d0;
    int d1;
    int d2;
    int d3;
    void FUN_00509890(int);
    unsigned int FUN_005094b0();
};
struct BoundObj
{
    unsigned char FUN_00509450(int);
    void FUN_00509920(float*, unsigned int, float);
    float GetFurnitureHeading(int);
};
struct CellA
{
    char pad[0x18];
    FullName m_fn;
};
struct Extra2
{
    void* FUN_0041d460();
};
struct CellB
{
    Extra2* FUN_005d43c0();
    const char* FUN_0055d520();
};
struct TeleObj
{
    CellA* FUN_0043a2b0();
    CellB* FUN_00559450();
};
struct Pt3
{
    float x;
    float y;
    float z;
};
struct LockObj
{
    int m_f0;
    KeyObj* m_f4;
    unsigned char FUN_005021a0();
    int FUN_004309e0(struct Refr*);
};
struct Refr
{
    virtual void rvp0();
    virtual void rvp1();
    virtual void rvp2();
    virtual void rvp3();
    virtual void rvp4();
    virtual void rvp5();
    virtual void rvp6();
    virtual void rvp7();
    virtual void rvp8();
    virtual void rvp9();
    virtual void rvp10();
    virtual void rvp11();
    virtual void rvp12();
    virtual void rvp13();
    virtual void rvp14();
    virtual void rvp15();
    virtual void rvp16();
    virtual void rvp17();
    virtual void rvp18();
    virtual void rvp19();
    virtual void rvp20();
    virtual void rvp21();
    virtual void rvp22();
    virtual void rvp23();
    virtual void rvp24();
    virtual void rvp25();
    virtual void rvp26();
    virtual void rvp27();
    virtual void rvp28();
    virtual void rvp29();
    virtual void rvp30();
    virtual void rvp31();
    virtual void rvp32();
    virtual void rvp33();
    virtual void rvp34();
    virtual void rvp35();
    virtual void rvp36();
    virtual void rvp37();
    virtual void rvp38();
    virtual void rvp39();
    virtual void rvp40();
    virtual void rvp41();
    virtual void rvp42();
    virtual void rvp43();
    virtual void rvp44();
    virtual void rvp45();
    virtual void rvp46();
    virtual void rvp47();
    virtual void rvp48();
    virtual void rvp49();
    virtual void rvp50();
    virtual void rvp51();
    virtual void rvp52();
    virtual void rvp53();
    virtual void rvp54();
    virtual void rvp55();
    virtual void rvp56();
    virtual void rvp57();
    virtual void rvp58();
    virtual void rvp59();
    virtual void rvp60();
    virtual void rvp61();
    virtual void rvp62();
    virtual void rvp63();
    virtual unsigned char rv100();
    virtual void rvp65();
    virtual void rvp66();
    virtual void rvp67();
    virtual void rvp68();
    virtual void rvp69();
    virtual void rvp70();
    virtual void rvp71();
    virtual void rvp72();
    virtual void rvp73();
    virtual void rvp74();
    virtual void rvp75();
    virtual void rvp76();
    virtual void rvp77();
    virtual void rvp78();
    virtual void rvp79();
    virtual void rvp80();
    virtual void rvp81();
    virtual void rvp82();
    virtual void rvp83();
    virtual void rvp84();
    virtual void rvp85();
    virtual void rvp86();
    virtual void rvp87();
    virtual void rvp88();
    virtual void rvp89();
    virtual void rvp90();
    virtual void rvp91();
    virtual void rvp92();
    virtual void rvp93();
    virtual void rvp94();
    virtual void rvp95();
    virtual void rvp96();
    virtual void rvp97();
    virtual void rvp98();
    virtual void rvp99();
    virtual void rvp100();
    virtual void rvp101();
    virtual void rvp102();
    virtual void rvp103();
    virtual void rvp104();
    virtual void rvp105();
    virtual void rvp106();
    virtual void rvp107();
    virtual void rvp108();
    virtual void rvp109();
    virtual void rvp110();
    virtual void rvp111();
    virtual void rvp112();
    virtual void rvp113();
    virtual void rvp114();
    virtual void rvp115();
    virtual void rvp116();
    virtual void rvp117();
    virtual void rvp118();
    virtual void rvp119();
    virtual void rvp120();
    virtual void rvp121();
    virtual void rvp122();
    virtual void rvp123();
    virtual void rvp124();
    virtual void rvp125();
    virtual void rvp126();
    virtual void rvp127();
    virtual void rvp128();
    virtual void rvp129();
    virtual void rvp130();
    virtual void rvp131();
    virtual void rvp132();
    virtual int rv214();
    unsigned int FUN_0084e3a0();
    const char* FUN_0055d520();
    ExtraObj* FUN_005d43c0();
    FormObj* FUN_00567790();
    unsigned char FUN_00568680();
    int FUN_00572d10();
    unsigned char FUN_00568500(int, Obj50*);
    unsigned char FUN_00567f80(int, int);
    LockObj* FUN_00569160();
    TeleObj* FUN_00568e50();
    Pt3* FUN_00430830();
    ProcObj* FUN_008d8520();
    BoundObj* FUN_007af430();
};
struct ListNode
{
    void* m_item;
    ListNode* m_next;
    ListNode* FUN_00726070();
    void** FUN_006815c0();
};
struct FUN_00710ad0_shell
{
    char pad00[0x70];
    ListNode m_kNode;
    int m_f78;
    char pad7c[0x61];
    unsigned char m_fdd;
    char padde[0x12];
    Refr* m_pReference;
    void FUN_00714d70(int);
    void DrawDebugInfo();
};
// Draws debug text lines for the selected reference (name, script, furniture, owner, count, markers, lock, teleport, action flags) and clears remaining lines.
// @fnv 0x00710ad0
void FUN_00710ad0_shell::DrawDebugInfo()
{
    static const char kStr0[] = "\"%s\" (%08x)";
    static const char kStr1[] = "Script name '%s' (%08x)";
    static const char kStr2[] = "current Furniture '%s' (%08x)";
    static const char kStr3[] = "Owner name '%s' (%08x)";
    static const char kStr4[] = "Count %d";
    static const char kStr5[] = "Furniture 'UNKNOWN' (UNKNOWN) index %d";
    static const char kStr6[] = "Furniture '%s' (%08x) index %d";
    static const char kStr7[] = "Orentation %d deg";
    static const char kStr8[] = "%s Marker %d Delta %0.2f,%0.2f,%0.2f (%d deg) %s";
    static const char kStr9[] = "Sit";
    static const char kStr10[] = "Sleep";
    static const char kStr11[] = "USED";
    static const char kStr12[] = "UNUSED";
    static const char kStr13[] = "Disabled %s Marker %d";
    static const char kStr14[] = "Lock '%s' %s.";
    static const char kStr15[] = "Locked";
    static const char kStr16[] = "Unlocked";
    static const char kStr17[] = "Key '%s'.";
    static const char kStr18[] = "Unknown";
    static const char kStr19[] = "Persistent";
    static const char kStr20[] = "Teleport Cell '%s' Door '%s'.";
    static const char kStr21[] = "Action Flags: ";
    static const char kStr22[] = "USE_DEFAULT";
    static const char kStr23[] = ", ACTIVATE";
    static const char kStr24[] = ", OPEN";
    static const char kStr25[] = ", OPEN_BY_DEFAULT";
    static const char kStr26[] = "";
    int found;
    int idx3;
    int baseY;
    int lineH;
    int y6;
    int savedY;
    ListNode* node;
    baseY = 0;
    savedY = (int)((FontMgr*)FUN_005bd5b0(*DAT_011f33c8.FUN_0043d4d0() - 1))->FUN_005bd5c0()->FUN_005bd580() + 3;
    found = *DAT_011debac.FUN_0043d4d0();
    lineH = found + 30;
    idx3 = 0;
    for (node = &m_kNode; node != 0 && *node->FUN_006815c0() != 0 && idx3 <= m_f78; node = node->FUN_00726070())
    {
        baseY = (int)*node->FUN_006815c0();
        idx3++;
    }
    if (baseY != 0)
    {
        Refr* aco;
        Refr* abo;
        int abk;
        StrObj aai;
        FUN_00714d70(baseY);
        m_pReference = (Refr*)baseY;
        FUN_00406f60(&aai, kStr0, m_pReference->FUN_0055d520(), m_pReference->FUN_0084e3a0());
        FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)found, 2, -1, DAT_01012054, 0, 0);
        if (m_fdd)
        {
            if (m_pReference->FUN_005d43c0()->FUN_00418800() != 0)
            {
                FUN_00406f60(&aai, kStr1, m_pReference->FUN_005d43c0()->FUN_00418800()->fv130(),
                             m_pReference->FUN_005d43c0()->FUN_00418800()->FUN_0084e3a0());
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
            }
            if (m_pReference->rv100())
            {
                abo = m_pReference;
                if (abo->FUN_008d8520() != 0)
                {
                    if (abo->FUN_008d8520()->pv4c8() != 0)
                    {
                        FUN_00406f60(&aai, kStr2, abo->FUN_008d8520()->pv4c8()->fv130(),
                                     abo->FUN_008d8520()->pv4c8()->FUN_0084e3a0());
                        FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1,
                                                         DAT_01012054, 0, 0);
                        lineH += savedY;
                    }
                }
            }
            if (m_pReference->FUN_00567790() != 0)
            {
                FUN_00406f60(&aai, kStr3, m_pReference->FUN_00567790()->fv130(),
                             m_pReference->FUN_00567790()->FUN_0084e3a0());
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
            }
            if ((short)m_pReference->FUN_005d43c0()->FUN_00418770() != 1)
            {
                FUN_00406f60(&aai, kStr4, (int)m_pReference->FUN_005d43c0()->FUN_00418770());
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
            }
            if (m_pReference->rv100())
            {
                aco = (Refr*)FUN_00ec43fb(m_pReference, 0, &DAT_011841cc, &DAT_011846d4, 0);
                if (aco->rv214())
                {
                    if (aco->FUN_008d8520()->pv4c8() == 0)
                    {
                        FUN_00406f60(&aai, kStr5, aco->FUN_008d8520()->pv4d0());
                    }
                    else
                    {
                        FUN_00406f60(&aai, kStr6, aco->FUN_008d8520()->pv4c8()->fv130(),
                                     aco->FUN_008d8520()->pv4c8()->FUN_0084e3a0(), aco->FUN_008d8520()->pv4d0());
                    }
                    FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1,
                                                     DAT_01012054, 0, 0);
                    lineH += savedY;
                }
            }
            if (m_pReference->FUN_00568680())
            {
                FUN_00406f60(&aai, kStr7, (int)(m_pReference->FUN_00430830()->z * DAT_0102f248));
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
                float dr[3];
                int dn;
                BoundObj* cy;
                Obj50 co;
                int ce;
                co.FUN_00509890(255);
                ce = 0;
                while (m_pReference->FUN_00568500(ce, &co))
                {
                    cy = m_pReference->FUN_007af430();
                    dn = (int)co.FUN_005094b0();
                    if (cy->FUN_00509450(ce))
                    {
                        cy->FUN_00509920(dr, co.FUN_005094b0(), DAT_011dea3c->FUN_00567400());
                        FUN_00406f60(&aai, kStr8, FUN_00509510(dn) ? kStr9 : kStr10, dn, (double)dr[0], (double)dr[1],
                                     (double)dr[2], (int)(cy->GetFurnitureHeading(dn) * DAT_0102f248),
                                     m_pReference->FUN_00567f80(ce, 1) ? kStr11 : kStr12);
                        FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1,
                                                         DAT_01012054, 0, 0);
                        lineH += savedY;
                    }
                    else
                    {
                        FUN_00406f60(&aai, kStr13, FUN_00509510(dn) ? kStr9 : kStr10, dn);
                        FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1,
                                                         DAT_01012054, 0, 0);
                        lineH += savedY;
                    }
                    ce++;
                }
            }
            if (m_pReference->FUN_00569160() != 0)
            {
                LockObj* lockObj = m_pReference->FUN_00569160();
                FUN_00406f60(&aai, kStr14, DAT_01184a98[lockObj->FUN_004309e0(m_pReference)]->FUN_00403df0(),
                             lockObj->FUN_005021a0() ? kStr15 : kStr16);
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
                if (lockObj->m_f4 != 0)
                {
                    FUN_00406f60(&aai, kStr17, lockObj->m_f4->m_fn.FUN_00408da0());
                    FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1,
                                                     DAT_01012054, 0, 0);
                    lineH += savedY;
                }
            }
            if (m_pReference->FUN_00568e50() != 0)
            {
                TeleObj* tele2 = m_pReference->FUN_00568e50();
                CellA* cellA7 = tele2->FUN_0043a2b0();
                CellB* cellB28 = tele2->FUN_00559450();
                const char* s705;
                const char* s6c45;
                s705 = kStr18;
                s6c45 = kStr18;
                if (cellA7 != 0 && cellA7->m_fn.FUN_00408da0() != 0)
                {
                    s705 = cellA7->m_fn.FUN_00408da0();
                }
                else if (cellB28 != 0 && cellB28->FUN_005d43c0()->FUN_0041d460() != 0)
                {
                    s705 = kStr19;
                }
                if (cellB28 != 0 && cellB28->FUN_0055d520() != 0)
                {
                    s6c45 = cellB28->FUN_0055d520();
                }
                FUN_00406f60(&aai, kStr20, s705, s6c45);
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
            }
            abk = m_pReference->FUN_00572d10();
            if (abk != 0)
            {
                char buf[256];
                FUN_00406d30(buf, 256, kStr21);
                if (abk & 1)
                    FUN_00406d50(buf, 256, kStr22);
                if (abk & 2)
                    FUN_00406d50(buf, 256, kStr23);
                if (abk & 4)
                    FUN_00406d50(buf, 256, kStr24);
                if (abk & 8)
                    FUN_00406d50(buf, 256, kStr25);
                FUN_00406f60(&aai, FUN_00464f30(buf, false));
                FUN_00a0d9e0(true)->CreateLine(aai.FUN_00559450(), DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0,
                                                 0);
                lineH += savedY;
            }
        }
    }
    else
    {
        int elseLineH;
        int elseBase;
        m_pReference = 0;
        FUN_00714d70(0);
        elseBase = (int)((FontMgr*)FUN_005bd5b0(*DAT_011f33c8.FUN_0043d4d0() - 1))->FUN_005bd5c0()->FUN_005bd580() + 3;
        elseLineH = *DAT_011debac.FUN_0043d4d0();
        FUN_00a0d9e0(true)->CreateLine(kStr26, DAT_0103a1c4, (float)elseLineH, 2, -1, DAT_01012054, 0, 0);
    }
    y6 = lineH;
    while (lineH < DAT_011d8c78)
    {
        FUN_00a0d9e0(true)->CreateLine(kStr26, DAT_0103a1c4, (float)lineH, 2, -1, DAT_01012054, 0, 0);
        lineH += savedY;
    }
    DAT_011d8c78 = y6;
}

struct FUN_00711d80_Global
{
    float* FUN_00403e20();
};

extern FUN_00711d80_Global DAT_011f35f4;

struct FUN_00711d80_cls
{
    int unk00;
    float GetGlobalFloat();
};

// @fnv 0x00711d80
float FUN_00711d80_cls::GetGlobalFloat()
{
    return *DAT_011f35f4.FUN_00403e20();
}

class SettingValue
{
  public:
    float* GetValue();
};

extern SettingValue DAT_011f3600;

class FUN_00711da0_cls
{
  public:
    float GetSettingValue();
};

// @fnv 0x00711da0
float FUN_00711da0_cls::GetSettingValue()
{
    return *DAT_011f3600.GetValue();
}

// FUN_00711de0: member function of a global-manager object.
// Reads a float out of the value table owned by the global object at DAT_011f3618.

class FloatValueOwner
{
  public:
    float* FUN_00403e20();
};

extern FloatValueOwner DAT_011f3618;

class FloatValueReader
{
  public:
    float FUN_00711de0();
};

// @fnv 0x00711de0
float FloatValueReader::FUN_00711de0()
{
    return *DAT_011f3618.FUN_00403e20();
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* lpPreviousCount);
unsigned int InitScriptRunLock(void* pvLock);

class B714930Semaphore
{
  public:
    int m_iArrayLength;
    int unk04;
    void* m_pSemaphore;

    int FUN_00714930();
};

// Initializes the lock, releases the semaphore by one, and returns the stored value.
// @fnv 0x00714930
int B714930Semaphore::FUN_00714930()
{
    InitScriptRunLock(this);
    ReleaseSemaphore(m_pSemaphore, 1, 0);
    return m_iArrayLength;
}

struct MenuStub
{
    virtual ~MenuStub();
};

struct TileStub
{
    MenuStub* GetMenu();
};

struct Sub71d580
{
    void Fn71d580();
};

TileStub* Fn_a09030(int id);
void FUN_00705e30();
Sub71d580* Fn_71b160(int idx);
void Fn_703610();

extern bool DAT_0119f348;

struct MenuMgr
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
    int menuIDs[10];
    void ClearMenuIDs();
};

struct MenuMgrFull : MenuMgr
{
};

// @fnv 0x00714c60
void MenuMgr::ClearMenuIDs()
{
    for (int i = 9; i >= 0; i--)
    {
        if (menuIDs[i])
        {
            TileStub* tile = Fn_a09030(menuIDs[i]);
            if (tile)
            {
                MenuStub* menu = tile->GetMenu();
                if (menu)
                {
                    if (tile == Fn_a09030(0x3ef))
                        FUN_00705e30();
                    else
                        delete menu;
                }
            }
            else if (menuIDs[i] == 3 && Fn_71b160(0))
            {
                Fn_71b160(1)->Fn71d580();
            }
            menuIDs[i] = 0;
        }
    }
    Fn_703610();
    unk0c = 4;
    DAT_0119f348 = true;
}

extern const float DAT_01016970;

struct FUN_00717230_bsobj
{
    void GetStringDimensions();
};

FUN_00717230_bsobj* __stdcall FUN_005bd5b0(float* out, int arg, void* holder, float scale, int zero);

class FUN_00717230_cls
{
  public:
    char unk00[0x14];
    int m_14;
    void* m_18;

    unsigned char FUN_00717230(int arg);
};

// @fnv 0x00717230
unsigned char FUN_00717230_cls::FUN_00717230(int arg)
{
    struct
    {
        float f;
        int u1;
        int u2;
    } p;
    FUN_005bd5b0(&p.f, arg, m_18, DAT_01016970, 0)->GetStringDimensions();
    return ((int)p.f <= m_14) ? 1 : 0;
}

struct HostY
{
    char m_auiShapeKeys[0x66d];
    signed char m_fl;
    void __thiscall SetFlag4(bool on);
};
// @fnv 0x00718960
void HostY::SetFlag4(bool on)
{
    on ? (m_fl |= 4) : (m_fl &= ~4);
}

struct FUN_007190e0_Child
{
    void Apply(int v);
};

class FUN_007190e0_cls
{
  public:
    int unk00;
    FUN_007190e0_Child* Find(int key);
    bool ApplyToChild(int a1, int a2);
};

// Finds the child entry for a1 and, if found, applies a2 to it and returns true; otherwise returns false.
// @fnv 0x007190e0
bool FUN_007190e0_cls::ApplyToChild(int aiKey, int a2)
{
    FUN_007190e0_Child* child = Find(aiKey);
    if (child != 0)
    {
        child->Apply(a2);
        return true;
    }
    else
    {
        return false;
    }
}

// Setter on a sub-object: calls a member routine on the object pointed to by
// field +0x0c and stores the stack argument through the pointer it returns.
struct FUN_00719340_value_obj
{
    int* GetValuePtr();
};

struct FUN_00719340_cls
{
    char unk00[0x0c];
    FUN_00719340_value_obj* m_pValueObj;
    void SetValue(int value);
};

// @fnv 0x00719340
void FUN_00719340_cls::SetValue(int value)
{
    *m_pValueObj->GetValuePtr() = value;
}

struct GlobalObject_011d8c4c
{
    void FUN_004de2d0(bool flag);
};
extern GlobalObject_011d8c4c DAT_011d8c4c;

struct MenuPanel_cls
{
    void UpdateControllerState();
};

struct InputHelper_cls
{
    void FUN_005407b0();
};

struct OSGlobals_cls
{
    InputHelper_cls* FUN_00877720(bool flag);
};
extern OSGlobals_cls* DAT_011dea0c;

struct InterfaceMgr_cls
{
    static MenuPanel_cls* __stdcall FUN_004b7210(bool flag);
};

struct FUN_00719740_cls
{
    void FUN_00719740(bool flag);
};

// @fnv 0x00719740
void FUN_00719740_cls::FUN_00719740(bool flag)
{
    DAT_011d8c4c.FUN_004de2d0(flag);
    InterfaceMgr_cls::FUN_004b7210(flag == 0)->UpdateControllerState();
    DAT_011dea0c->FUN_00877720(flag)->FUN_005407b0();
}

struct FUN_007e6700_Helper
{
    void* __thiscall GetDisplayText(int);
    void* __thiscall FUN_00458b50();
};

struct FUN_007e6700_Object28
{
    void __thiscall FUN_00a01350(int, void*);
};

struct FUN_007e6700_Object2C
{
    void __thiscall FUN_00700320(int, bool);
};

typedef bool(__cdecl* FUN_007e6700_Callback)(void*);

struct FUN_007e6700_Class
{
    char padding00[0x28];
    FUN_007e6700_Object28* object28;
    FUN_007e6700_Object2C* object2C;
    char padding30[4];
    FUN_007e6700_Helper helper;
    char padding38[0x58 - 0x38];
    FUN_007e6700_Callback callback;

    void __thiscall FUN_007e6700();
};

// Calls object28 with 0xFC4 and a helper result, then if callback is set calls object2C with 0xFAF and the callback's result.
// @fnv 0x007e6700
void __thiscall FUN_007e6700_Class::FUN_007e6700()
{
    object28->FUN_00a01350(0xFC4, helper.GetDisplayText(1));

    if (callback != 0)
    {
        object2C->FUN_00700320(0xFAF, callback(helper.FUN_00458b50()));
    }
}

extern float DAT_01204360;
extern const double DAT_01012060;
extern int DAT_01203b58[];
extern float DAT_01203350[];
extern int DAT_01203f58[];
extern float DAT_01203750[];
extern const double DAT_010231d8;
extern const double DAT_01017a10;
extern const double DAT_01012070;
extern "C" int __cdecl rand(void);
float __cdecl EvaluateQuinticPolynomial(float value);
void __cdecl FUN_00c5d300(float blend, float a, float b);

// @fnv 0x00c5d320
void __cdecl ApplyNoise(float input)
{
    int nIndex;
    if (DAT_01204360 == DAT_01012060)
    {
        for (nIndex = 0; nIndex < 256; ++nIndex)
        {
            DAT_01203b58[nIndex] = nIndex;
            DAT_01203350[nIndex] = float((rand() % 512) - 256) / DAT_010231d8;
        }

        while (--nIndex)
        {
            int saved = DAT_01203b58[nIndex];
            int other = rand() % 256;
            DAT_01203b58[nIndex] = DAT_01203b58[other];
            DAT_01203b58[other] = saved;
        }

        for (nIndex = 0; nIndex < 258; ++nIndex)
        {
            DAT_01203f58[nIndex] = DAT_01203b58[nIndex];
            DAT_01203750[nIndex] = DAT_01203350[nIndex];
        }
        DAT_01204360 = 1.0f;
    }

    float localValue = float(input + DAT_01017a10);
    int baseIndex = (int(localValue)) & 255;
    int second = (baseIndex + 1) & 255;
    float frac = localValue - int(localValue);
    float fractionMinusOne = frac - DAT_01012070;
    float left = EvaluateQuinticPolynomial(frac);
    float right = frac * DAT_01203350[DAT_01203b58[baseIndex]];
    float weight = fractionMinusOne * DAT_01203350[DAT_01203b58[second]];
    FUN_00c5d300(left, right, weight);
}

struct OwnedUIObject
{
    virtual ~OwnedUIObject();
};
struct OwnedNonvirtualUI
{
    ~OwnedNonvirtualUI();
    void* DestroyIfFlagged(unsigned int);
};
struct EmptySoundHandle
{
    ~EmptySoundHandle();
    void FUN_00483710();
    int state;
};
struct UISmartPointer
{
    OwnedUIObject* ptr;
    ~UISmartPointer();
    OwnedUIObject* FUN_00559450();
    void FUN_0066b0d0(OwnedUIObject*);
};
struct UIList
{
    ~UIList();
    int unk00;
    int unk04;
};
struct UIState178
{
    ~UIState178();
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
};
struct UIState1dc
{
    ~UIState1dc();
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
};
struct UIList4c4
{
    ~UIList4c4();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct UIGlobalList
{
    void FUN_00470470();
};
extern UIGlobalList DAT_011d8b54;
extern unsigned char DAT_011d8909;
void ClearPendingObject();
void FUN_00a16850();
void FUN_0071e360();
void FUN_00a00a30();
void FUN_00a1c800();
void FUN_00718bf0();
void ClearAllElements();
void FUN_00707820();
void ClearStartMenuEntries();
void WaitForTasksAndClearScripts();
struct FUN_0070a920
{
    int unk000;
    UISmartPointer rootA;
    UISmartPointer rootB;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    OwnedUIObject* object28;
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
    UIList list70;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    UISmartPointer root8c;
    UISmartPointer root90;
    OwnedUIObject* object94;
    OwnedUIObject* object98;
    OwnedUIObject* object9c;
    OwnedUIObject* objecta0;
    int unk0a4;
    int unk0a8;
    UISmartPointer rootac;
    int unk0b0;
    OwnedUIObject* objectb4;
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
    OwnedNonvirtualUI* object13c;
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
    OwnedUIObject* object174;
    UIState178 state178;
    UIState1dc state1dc;
    UIList4c4 list4c4;
    EmptySoundHandle sound;
    void FUN_00716450();
    ~FUN_0070a920();
};
// Destructor: deletes owned objects, releases smart pointers, resets globals and calls the UI teardown helpers.
// @fnv 0x0070a920
FUN_0070a920::~FUN_0070a920()
{
    if (objectb4)
    {
        delete objectb4;
        objectb4 = 0;
    }
    ResetSystemUtility();
    DestroyMenuConsoleSingleton();
    ClearPendingObject();
    FUN_00a16850();
    if (rootA.FUN_00559450())
    {
        ((EmptySoundHandle*)rootA.FUN_00559450())->FUN_00483710();
        rootA.FUN_0066b0d0(0);
    }
    if (rootB.FUN_00559450())
    {
        ((EmptySoundHandle*)rootB.FUN_00559450())->FUN_00483710();
        rootB.FUN_0066b0d0(0);
    }
    DAT_011d8909 = 1;
    delete objecta0;
    delete object9c;
    DAT_011d8909 = 0;
    FUN_0071e360();
    delete object28;
    rootac.FUN_0066b0d0(0);
    DAT_011d8a80 = 0;
    FUN_00a00a30();
    FUN_0070aca0();
    delete object13c;
    FUN_00716450();
    FUN_00a1c800();
    DAT_011d8b54.FUN_00470470();
    FUN_00718bf0();
    ClearAllElements();
    FUN_00707820();
    delete object174;
    root8c.FUN_0066b0d0(0);
    delete object94;
    delete object98;
    ClearStartMenuEntries();
    WaitForTasksAndClearScripts();
}

namespace cursor_init {
struct SceneNode
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
    virtual void AttachChildInAvailableSlot(SceneNode*, bool);
    void FUN_004bc1f0(float, float, float);
    void FUN_00a5a040();
    void Update(NiUpdateDataH&);
    void SetAppCulled(bool);
};
struct CursorTile
{
    CursorTile();
    virtual void v0();
    virtual void Init(void*, const char*, void*);
    void Set(int, int);
    void SetString(int, const char*);
    void FUN_00a04640(bool);
    SceneNode* FUN_0056c7f0();
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
};
struct Accumulator : NiMemObject
{
    Accumulator();
    void FUN_0070b760(int);
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
};
struct AccumulatorHolder
{
    void FUN_004a1020(Accumulator*);
};
struct AccumulatorPtr
{
    AccumulatorHolder* FUN_00559450();
    AccumulatorHolder* object;
};
struct Setting
{
    const char* FUN_00403df0(int);
};
extern Setting DAT_011d475c;
extern Setting DAT_011f3368;
extern const char DAT_0106ef50[];
struct Manager
{
    unsigned char state;
    bool initialized;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    CursorTile* cursor;
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
    SceneNode* root;
    int unk88;
    AccumulatorPtr accumulatorA;
    AccumulatorPtr accumulatorB;
    Accumulator* first;
    Accumulator* second;
    void FUN_007118d0();
    void FUN_0070b240();
};
void CreateFontManager();
CursorTile* FUN_0076bfe0();
void UpdateVisibilityState(int);
// @fnv 0x0070b240
void Manager::FUN_0070b240()
{
    lc1::AutoMemContext j(13, true, DAT_0106ef50, 667);
    CreateFontManager();
    CursorTile* c = new CursorTile;
    c->Init(0, "Cursor", 0);
    c->Set(0xfad, 2000);
    c->Set(0xfb1, 32);
    c->Set(0xfb0, 32);
    c->SetString(0xfcc, DAT_011d475c.FUN_00403df0(1));
    c->SetString(0xff9, DAT_011f3368.FUN_00403df0(1));
    c->Set(0xfa1, 0);
    c->Set(0xfa2, 0);
    c->Set(0xfa3, 0);
    c->Set(0xfa9, 255);
    c->Set(0xfb2, 255);
    c->Set(0xfb3, 255);
    c->Set(0xfb4, 255);
    c->FUN_00a04640(true);
    root->AttachChildInAvailableSlot(c->FUN_0056c7f0(), true);
    c->FUN_0056c7f0()->FUN_004bc1f0(0.0f, -1.0f, 0.0f);
    c->FUN_0056c7f0()->FUN_00a5a040();
    NiUpdateDataH l;
    l.FUN_0043d410(0.0f, false, false);
    c->FUN_0056c7f0()->Update(l);
    cursor = c;
    FUN_007118d0();
    cursor->FUN_0056c7f0()->SetAppCulled(true);
    first = new Accumulator;
    first->FUN_0070b760(1);
    second = new Accumulator;
    second->FUN_0070b760(3);
    accumulatorA.FUN_00559450()->FUN_004a1020(first);
    accumulatorB.FUN_00559450()->FUN_004a1020(first);
    CursorTile* e = FUN_0076bfe0();
    UpdateVisibilityState(4);
    if (e)
        e->Set(0xfa3, 0);
    cursor->FUN_0056c7f0()->SetAppCulled(true);
    cursor->Set(0xfa3, 0);
    cursor->FUN_00a04640(true);
    initialized = true;
}
}

namespace fnv_0070f4e0 {
struct TileStub
{
    void Set(int, int);
};
struct PlayerStub
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
    virtual void v05f();
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
    virtual bool v22c(int);
    virtual bool v230();
    bool FUN_005a03f0(unsigned int);
    bool FUN_004eaf60();
    bool GetUnderAIControl();
    bool FUN_005721e0();
};
bool __fastcall FUN_005737e0(PlayerStub*);
struct HUDStub
{
    bool GetVisible();
};
extern HUDStub* HUDMainMenu_pme;
struct VATSStub
{
    unsigned int CallGetFlags();
};
extern VATSStub DAT_011f2250;
extern bool DAT_011e0780;
extern const double DAT_01012060;
double __cdecl FUN_008d1cf0();
struct IfaceStub
{
    bool FUN_00701450(int);
};
extern IfaceStub* DAT_011d8804;
struct IMStub
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
    int state;
    void (*callback)();
    TileStub* FUN_00586150();
    bool FUN_00716910(int);
    void QueueHudCallback(void (*cb)(), int value);
};

// @fnv 0x0070f4e0
void IMStub::QueueHudCallback(void (*cb)(), int value)
{
    if (!((PlayerStub*)_g_thePlayer)->FUN_005a03f0(4) && !((PlayerStub*)_g_thePlayer)->v22c(0) &&
        FUN_005737e0((PlayerStub*)_g_thePlayer) == ((PlayerStub*)_g_thePlayer)->FUN_004eaf60() &&
        !((PlayerStub*)_g_thePlayer)->GetUnderAIControl() && !((PlayerStub*)_g_thePlayer)->FUN_005721e0() &&
        (!HUDMainMenu_pme || !HUDMainMenu_pme->GetVisible()) && FUN_00716910(0) &&
        !((PlayerStub*)_g_thePlayer)->v230() && !DAT_011f2250.CallGetFlags() && !DAT_011e0780 &&
        FUN_008d1cf0() == DAT_01012060 && !DAT_011d8804->FUN_00701450(1))
    {
        if (value)
            FUN_00586150()->Set(0x1771, value);
        if (state == 3 && cb)
            cb();
        else if (state == 0)
        {
            state = 1;
            callback = cb;
        }
    }
}
}  // namespace fnv_0070f4e0

namespace fnv_00710060 {
bool FUN_004b71d0();
int FUN_00717a40(int a, int b);
struct C877720
{
    int FUN_00877720();
};
struct C825c00
{
    unsigned int FUN_00825c00();
};
struct C403e20
{
    float* FUN_00403e20();
};
extern C877720* DAT_011dea0c;
extern C825c00 DAT_011f6394;
extern C403e20 DAT_011d8b38;
extern C403e20 DAT_011d8aa4;

struct FUN_00710060_cls
{
    char unk00[0x7d];
    bool unk7d;
    char pad7e[0x15c - 0x7e];
    int unk15c;
    unsigned int unk160;
    int FUN_00710060(bool p1, bool p2, bool* p3);
};

// @fnv 0x00710060
int FUN_00710060_cls::FUN_00710060(bool p1, bool p2, bool* p3)
{
    int e;
    int f1;
    int d;
    int g;
    int b4;
    int nn5;
    int c11;
    int pN7;
    int b2;
    int m6;
    int uA3;
    int a1;
    int B3;
    int aA2;
    int aA4;
    bool kPi;
    int result2;
    int aSig;
    result2 = 0;
    if (!FUN_004b71d0() || unk7d)
        return result2;
    aSig = DAT_011dea0c->FUN_00877720();
    kPi = true;
    if (FUN_00717a40(9, 1) == 2 || FUN_00717a40(9, 1) == 1)
    {
        result2 = 9;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(9, 1) == 1;
    }
    else if (FUN_00717a40(10, 1) == 2 || FUN_00717a40(10, 1) == 1)
    {
        result2 = 10;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(10, 1) == 1;
    }
    else if (FUN_00717a40(11, 1) == 2 || FUN_00717a40(11, 1) == 1)
    {
        result2 = 11;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(11, 1) == 1;
    }
    else if (FUN_00717a40(12, 1) == 2 || FUN_00717a40(12, 1) == 1)
    {
        result2 = 12;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(12, 1) == 1;
    }
    else if (FUN_00717a40(16, 1) == 2 || FUN_00717a40(16, 1) == 1)
    {
        result2 = 16;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(16, 1) == 1;
    }
    else if (FUN_00717a40(6, 1) == 2 || FUN_00717a40(6, 1) == 1)
    {
        result2 = 6;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(6, 1) == 1;
    }
    else if (FUN_00717a40(14, 1) == 2 || FUN_00717a40(14, 1) == 1)
    {
        result2 = 14;
        unk15c = 0;
        kPi = false;
        *p3 = FUN_00717a40(14, 1) == 1;
    }
    else
    {
        aA4 = FUN_00717a40(4, 1) == 2;
        uA3 = FUN_00717a40(3, 1) == 2;
        a1 = FUN_00717a40(1, 1) == 2;
        aA2 = FUN_00717a40(2, 1) == 2;
        b4 = FUN_00717a40(4, 1) == 0;
        B3 = FUN_00717a40(3, 1) == 0;
        nn5 = FUN_00717a40(1, 1) == 0;
        b2 = FUN_00717a40(2, 1) == 0;
        c11 = FUN_00717a40(17, 1) == 2;
        pN7 = FUN_00717a40(18, 1) == 2;
        if (a1 && !aA4 && !uA3 && !b4 && !B3)
            result2 = 1;
        else if (aA2 && !aA4 && !uA3 && !b4 && !B3)
            result2 = 2;
        else if (aA4 && !a1 && !aA2 && !nn5 && !b2)
            result2 = 4;
        else if (uA3 && !a1 && !aA2 && !nn5 && !b2)
            result2 = 3;
        else if (c11)
            result2 = 17;
        else if (pN7)
            result2 = 18;
        m6 = 0;
        if (nn5 && unk15c == 1)
            m6 = 1;
        else if (b2 && unk15c == 2)
            m6 = 2;
        else if (b4 && unk15c == 4)
            m6 = 4;
        else if (B3 && unk15c == 3)
            m6 = 3;
        if (!result2 && !m6 && b4 + B3 + nn5 + b2)
        {
            if (nn5)
                result2 = 1;
            else if (b2)
                result2 = 2;
            else if (b4)
                result2 = 4;
            else if (B3)
                result2 = 3;
        }
        if (result2 && unk15c != result2)
        {
            unk15c = result2;
            if ((p1 && a1 + aA2 + nn5 + b2) || (p2 && aA4 + uA3 + b4 + B3))
            {
                unk160 = (unsigned int)((double)DAT_011f6394.FUN_00825c00() + *DAT_011d8b38.FUN_00403e20());
            }
            else
            {
                unk160 = DAT_011f6394.FUN_00825c00() * 2;
            }
        }
        else if (unk15c == m6 && unk160 <= DAT_011f6394.FUN_00825c00())
        {
            result2 = unk15c;
            if ((p1 && a1 + aA2 + nn5 + b2) || (p2 && aA4 + uA3 + b4 + B3))
            {
                unk160 = (unsigned int)((double)DAT_011f6394.FUN_00825c00() + *DAT_011d8aa4.FUN_00403e20());
            }
        }
        else if (unk15c != m6)
        {
            result2 = 0;
            unk15c = result2;
        }
        else
        {
            result2 = 0;
        }
        if (aA4 + uA3 + a1 + aA2 + b4 + B3 + nn5 + b2)
            kPi = false;
    }
    if (!result2)
    {
        f1 = FUN_00717a40(15, 1) == 2;
        g = FUN_00717a40(16, 1) == 2;
        d = FUN_00717a40(13, 1) == 2;
        e = FUN_00717a40(14, 1) == 2;
        if (f1 + g + d + e)
        {
            unk15c = 0;
            kPi = false;
        }
        if (f1 && !g)
            result2 = 15;
        else if (g && !f1)
            result2 = 16;
        else if (d && !e)
            result2 = 13;
        else if (e && !d)
            result2 = 14;
    }
    if (!result2 && FUN_00717a40(5, 1) == 2)
    {
        result2 = 5;
        unk15c = 0;
        kPi = false;
    }
    if (kPi)
    {
        unk15c = 0;
        unk160 = DAT_011f6394.FUN_00825c00() * 2;
    }
    return result2;
}
}  // namespace fnv_00710060

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};
struct HitRecord
{
    void* FUN_00458b50();
};
struct HitResults
{
    unsigned int FUN_0044edb0();
    HitRecord* FUN_00968670(unsigned int);
};
struct GlobalObject_00e98f20
{
    int queryType, sortType, intersectType, coordinateType;
    int frontOnly, returnNormals, returnTextures, returnColors;
    void* root;
    void* results;
    unsigned int resultCount, resultCapacity, growBy;
    GlobalObject_00e98f20(int, int);
    ~GlobalObject_00e98f20();
    void SetByteAtOffset17(int);
    void FUN_00705fc0(void*);
    void FUN_006ecd40(int);
    bool FUN_00e98e20(NiPoint3&, NiPoint3&, int);
    HitResults* FUN_00500940();
};
struct GlobalObject2_0096a2d0
{
    void* item;
    GlobalObject2_0096a2d0* next;
    GlobalObject2_0096a2d0();
    ~GlobalObject2_0096a2d0();
    bool FUN_005f65d0(void*&);
    void FUN_00905820(void*&);
    void*& FUN_006815c0();
    GlobalObject2_0096a2d0* FUN_00726070();
    void FUN_00470470();
};
struct PickWorld
{
    void* FUN_0084e3a0();
};

struct CameraData
{
    void MapScreenToRay(int, int, NiPoint3&, NiPoint3&, int);
};
struct SceneCamera
{
    void SetCameraFOV(float, int, int, int);
    CameraData* FUN_006629f0();
};
SceneCamera* FUN_0045c670();
void* __cdecl FUN_0056f930(void*);
struct PickOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    float screenX;
    int unk3c;
    float screenY;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    GlobalObject2_0096a2d0 objects;
    int objectCount;
    void UpdatePickObjects();
};
// @fnv 0x00710880
void PickOwner::UpdatePickObjects()
{
    NiPoint3 d;
    NiPoint3 e;
    GlobalObject_00e98f20 c(0, 8);
    GlobalObject2_0096a2d0 b;
    bool a = true;
    c.SetByteAtOffset17(1);
    c.FUN_00705fc0(((PickWorld*)g_TES)->FUN_0084e3a0());
    c.FUN_006ecd40(0);
    FUN_0045c670()->SetCameraFOV(FUN_00710ab0((FUN_00710ab0_Class*)DAT_011dea3c), 0, 0, 0);
    FUN_0045c670()->FUN_006629f0()->MapScreenToRay((int)screenX, (int)screenY, d, e, 0);
    if (c.FUN_00e98e20(d, e, 0))
    {
        GlobalObject2_0096a2d0* existing = &objects;
        for (unsigned int i = 0; i < c.FUN_00500940()->FUN_0044edb0(); ++i)
        {
            void* object = FUN_0056f930(c.FUN_00500940()->FUN_00968670(i)->FUN_00458b50());
            if (!b.FUN_005f65d0(object))
            {
                b.FUN_00905820(object);
                if (existing && existing->FUN_006815c0() != object)
                    a = false;
                else if (a && existing)
                    existing = existing->FUN_00726070();
            }
        }
    }
    objects.FUN_00470470();
    objectCount = 0;
    if (!a)
    {
        for (GlobalObject2_0096a2d0* node = &b; node && node->FUN_006815c0(); node = node->FUN_00726070())
            objects.FUN_00905820(node->FUN_006815c0());
    }
    b.FUN_00470470();
}

extern const double DAT_01032980;
namespace std {
float __cdecl abs(float);
}
struct AlphaTile
{
    bool IsTraitNonZero(int);
    float FUN_00a011b0(int);
    void FUN_00700320(int, bool);
};
struct AlphaProperty
{
    void FUN_00821600(float);
};
struct AlphaGeometry
{
    AlphaProperty* GetProperty(unsigned int);
};
struct AlphaNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual AlphaNode* AsNode();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual AlphaGeometry* AsGeometry();
    AlphaNode* FUN_009611e0();
    unsigned int FUN_0043b480();
    AlphaNode* FUN_0043b4a0(unsigned int);
};
AlphaTile* __cdecl FUN_00a01630(void*);
unsigned int __cdecl FUN_00438220();
struct AlphaInterface
{
    void SetNodeAlpha(AlphaNode* node, float value, float inheritedAlpha);
};
// Applies an alpha value to a node's geometry property and recurses into children, using a tile's alpha scale when present.
// @fnv 0x00712450
void AlphaInterface::SetNodeAlpha(AlphaNode* node, float value, float inheritedAlpha)
{
    lc1::AutoMemContext contextTmp(
        13, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp", 3371);
    if (!node)
        return;
    // Node ancestor used to find the owning tile and recurse into children.
    AlphaNode* pNode = node->AsNode();
    AlphaTile* current = FUN_00a01630(pNode);
    while (!current && pNode)
    {
        pNode = pNode->FUN_009611e0();
        current = FUN_00a01630(pNode);
    }
    pNode = node->AsNode();
    float scale = inheritedAlpha;
    if (current)
    {
        if (current->IsTraitNonZero(4011))
        {
            if (std::abs(value) < 1.0)
                current->FUN_00700320(4003, false);
            else
                current->FUN_00700320(4003, true);
            return;
        }
        scale = current->FUN_00a011b0(4009) / 255.0;
    }
    AlphaGeometry* object = node->AsGeometry();
    if (object)
    {
        float alpha = std::abs(value) < DAT_01032980 ? 0.0f : FUN_00404010(0.0f, FUN_0040ebd0(value * scale, scale));
        AlphaProperty* property = object->GetProperty(FUN_00438220());
        if (property)
            property->FUN_00821600(alpha);
    }
    if (pNode && (!current || current->FUN_00a011b0(4010) != 9000.0))
    {
        for (unsigned int index = 0; index < pNode->FUN_0043b480(); ++index)
            SetNodeAlpha(pNode->FUN_0043b4a0(index), value, scale);
    }
}

extern const double DAT_01011590;
extern const double DAT_0106f290;

class FUN_006815c0
{
  public:
    float x, y, z;
    FUN_006815c0();
    bool FUN_00439090(const FUN_006815c0& arPoint);
};

class FUN_0043d410
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    FUN_0043d410(float afTime, bool abUpdateControllers, bool abParallelUpdate);
};

struct FUN_0043c490_node
{
    FUN_006815c0& FUN_0043c490();
    void FUN_00440460(const FUN_006815c0* apPos);
    void FUN_00a59c60(const FUN_0043d410& arData);
    void FUN_00450f90(bool abCulled);
};

struct FUN_0056c7f0_tile
{
    FUN_0043c490_node* FUN_0056c7f0();
    float FUN_00a011b0(int aiTrait);
    void FUN_00700320(int aiTrait, int aiValue);
};

float __cdecl FUN_00715d40();
double __cdecl FUN_00706e20();
double __cdecl FUN_00706e50();

struct FUN_007151b0_shell
{
    char pad00[0x28];
    FUN_0056c7f0_tile* pTile;
    FUN_006815c0 kPos;
    FUN_006815c0 kTarget;
    char pad44[0x7d - 0x44];
    bool bFlag7d;
    char pad7e[0xed - 0x7e];
    bool m_bDecalsEnabled;
    char FUN_00424940();
    void UpdateTilePosition(float afX, float afY);
};

// @fnv 0x007151b0
void FUN_007151b0_shell::UpdateTilePosition(float afX, float afY)
{
    static FUN_006815c0 kLast;

    kPos = pTile->FUN_0056c7f0()->FUN_0043c490();
    kPos.x = FUN_00715d40() * afX - FUN_00715d40() / DAT_01011590;
    kPos.z = FUN_00715da0() * -afY + FUN_00715da0() / DAT_01011590;
    pTile->FUN_0056c7f0()->FUN_00440460(&kPos);
    FUN_0043d410 kUpdateData(0.0f, false, false);
    pTile->FUN_0056c7f0()->FUN_00a59c60(kUpdateData);

    FUN_006815c0 kComputedPos;
    kComputedPos.x = (kPos.x + 3.0) * (FUN_00706e50() / FUN_00715d40()) + FUN_00706e50() / DAT_01011590;
    kComputedPos.y = 0.0f;
    kComputedPos.z = FUN_00706e20() / DAT_01011590 - kPos.z * (FUN_00706e20() / FUN_00715da0());
    if (kComputedPos.FUN_00439090(kLast))
    {
        kLast = kComputedPos;
        kComputedPos.y = pTile->FUN_00a011b0(0xfad) * DAT_0106f290;
        kTarget = kComputedPos;
        if (!FUN_004b71d0() || bFlag7d)
        {
            m_bDecalsEnabled = true;
            if (FUN_00424940() == 2)
            {
                pTile->FUN_0056c7f0()->FUN_00450f90(false);
                pTile->FUN_00700320(0xfa3, 1);
            }
        }
    }

    if (kTarget.x != kComputedPos.x || kTarget.z != kComputedPos.z)
    {
        m_bDecalsEnabled = true;
        kTarget.x = FUN_00706e50() / FUN_00715d40() * kTarget.x + FUN_00706e50() / DAT_01011590;
        kTarget.y = pTile->FUN_00a011b0(0xfad) * DAT_0106f290;
        kTarget.z = FUN_00706e20() / DAT_01011590 - FUN_00706e20() / FUN_00715da0() * kTarget.z;
    }
}

struct KeyTranslator
{
    int FUN_00a238a0(int key, bool shifted);
};
bool FUN_00715770();

struct KeyboardHandler : InterfaceManager
{
    int unk13c;
    int unk140;
    int unk144;
    unsigned char unk148;
    bool shifted;
    unsigned char unk14a;
    unsigned char unk14b;
    unsigned int modifiers;
    unsigned int HandleKeyEvent(int event, int key);
};

// Translates a key event into a result code, updating modifier flags and shift state and forwarding special keys to FUN_007166f0.
// @fnv 0x007154b0
unsigned int KeyboardHandler::HandleKeyEvent(int event, int key)
{
    unsigned int result = 0;
    if (event == 2)
    {
        if (key == 0x2a || key == 0x36)
        {
            modifiers &= 0xfffb;
            shifted = false;
        }
        else if (key == 0x38 || key == 0xb8)
        {
            modifiers &= 0xfffe;
        }
        else if (key == 0x1d || key == 0x9d)
        {
            modifiers &= 0xfffd;
        }
        ((AI_*)this)->FUN_007166f0(0);
    }
    else if (event == 1)
    {
        int translated = ((KeyTranslator*)g_osGlobals->FUN_00877720())->FUN_00a238a0(key, shifted);
        if (translated == 0x1b && !FUN_00715770())
        {
            result = 0;
        }
        else if (translated == 8)
        {
            result = 0x80000000;
            ((AI_*)this)->FUN_007166f0(0x80000000);
        }
        else if (translated == 0x7c)
        {
            result = 0;
        }
        else if (translated == 0xd)
        {
            result = 0x80000008;
        }
        else if (key == 0x2a || key == 0x36)
        {
            modifiers |= 4;
            shifted = true;
        }
        else if (key == 0x38 || key == 0xb8)
        {
            modifiers |= 1;
        }
        else if (key == 0x1d || key == 0x9d)
        {
            modifiers |= 2;
        }
        else if (key == 0xcb)
        {
            result = 0x80000001;
            ((AI_*)this)->FUN_007166f0(0x80000001);
        }
        else if (key == 0xcd)
        {
            result = 0x80000002;
            ((AI_*)this)->FUN_007166f0(0x80000002);
        }
        else if (key == 0xc8)
        {
            result = 0x80000003;
            ((AI_*)this)->FUN_007166f0(0x80000003);
        }
        else if (key == 0xd0)
        {
            result = 0x80000004;
            ((AI_*)this)->FUN_007166f0(0x80000004);
        }
        else if (key == 0xc7)
        {
            result = 0x80000005;
        }
        else if (key == 0xcf)
        {
            result = 0x80000006;
        }
        else if (key == 0xd1)
        {
            result = 0x8000000a;
        }
        else if (key == 0xc9)
        {
            result = 0x80000009;
        }
        else if (key == 0xd3)
        {
            result = 0x80000007;
            ((AI_*)this)->FUN_007166f0(0x80000007);
        }
        else
        {
            result = translated;
        }
    }
    return result;
}

// @fnv 0x00715770
bool __cdecl FUN_00715770()
{
    return FUN_0070edf0() && DAT_011daac0->IsFlagSet(static_cast<StartMenu::Flag>(0x80000));
}

struct FocusMenu
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Click(int, struct FocusTile*);
};
struct FocusTile
{
    float Read(int);
    void SetInt(int, int);
    void SetCount(int, int);
    FocusMenu* Owner();
    void Trigger(int);
    void Reset(int);
    bool Visible();
    bool Test(int);
};
void PlayClick(int);
struct FocusManager
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
    FocusTile* active;
    int count;
    int unkc4;
    int unkc8;
    FocusTile* hover;
    int hoverState;
    void NotifyOff(FocusMenu*, int, FocusTile*);
    void NotifyOn(FocusMenu*, int, FocusTile*);
    void Clear(int);
    void FUN_00715860(FocusTile* tile, int trait, bool sound);
};
// Updates hover and active tile state for a trait change, notifying listeners, playing sounds and clearing the active tile when needed.
// @fnv 0x00715860
void FocusManager::FUN_00715860(FocusTile* tile, int trait, bool sound)
{
    int clickSound2;
    if (active && active != tile && active->Read(0xfd6) > 0.0)
    {
        count++;
        active->SetCount(0xfd6, count);
    }
    if (tile)
    {
        if (hover)
        {
            hover->SetInt(0xfc3, 0);
            NotifyOff(hover->Owner(), (int)hover->Read(0xfaa), hover);
        }
        hover = 0;
        hoverState = 0;
    }
    if (!tile)
    {
        if (active)
        {
            active->SetInt(0xfc3, 0);
            NotifyOff(active->Owner(), (int)active->Read(0xfaa), active);
        }
        Clear(0);
        active = 0;
    }
    else if (trait == 0xfc3 && active != tile)
    {
        if (active)
        {
            active->SetInt(0xfc3, 0);
            NotifyOff(active->Owner(), (int)active->Read(0xfaa), active);
        }
        active = tile;
        if (active && active->Read(0xfd6) > 0.0)
        {
            count++;
            active->SetCount(0xfd6, count);
        }
        tile->SetInt(0xfc3, 1);
        if (sound)
            tile->Trigger(0xfe8);
        NotifyOn(active->Owner(), (int)active->Read(0xfaa), active);
    }
    else if (trait == 0xfc7)
    {
        clickSound2 = (int)tile->Read(0xfcb);
        if (sound && clickSound2)
            PlayClick(clickSound2);
        tile->SetInt(0xfc7, 1);
        tile->SetInt(0xfc7, 0);
        tile->Owner()->Click((int)tile->Read(0xfaa), tile);
        tile->Reset(0);
        if (active && (!active->Visible() || !active->Test(0xfaf)))
        {
            active->SetInt(0xfc3, 0);
            NotifyOff(active->Owner(), (int)active->Read(0xfaa), active);
            Clear(0);
            active = 0;
        }
    }
}

struct TileValue7160
{
    float FUN_00488d50();
};
struct TileMenu7160
{
    int FUN_0059bb30();
};
struct TileNode7160;
struct TileChildren7160
{
    TileNode7160* FUN_00559450();
    struct Tile7160** FUN_0057cbe0(TileNode7160**);
};
struct Tile7160
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
    TileChildren7160 children;
    TileMenu7160* FUN_00a03c90();
    bool IsTraitNonZero(int);
    TileValue7160* FindTraitValue(int);
    TileValue7160* FUN_00a00f30(int);
};
struct TileNode7160
{
    Tile7160* FUN_00726070();
};
struct TileRoot7160
{
    TileNode7160* FindTopMenu();
};
TileRoot7160* __cdecl FUN_0071e290(bool);
struct Manager7160
{
    Tile7160* FindHighestPriorityTile(int* priority, Tile7160* tile);
};
// @fnv 0x007160f0
Tile7160* Manager7160::FindHighestPriorityTile(int* priority, Tile7160* tile)
{
    int current;
    TileNode7160* childPos;
    int minOrder;
    Tile7160* result = 0;
    {
        int maxPriority = *priority;
        minOrder = 0x7fffffff;
        *priority = (-2147483647 - 1);
        current = (-2147483647 - 1);
        if (!tile)
        {
            TileNode7160* root = FUN_0071e290(true)->FindTopMenu();
            if (root)
                tile = root->FUN_00726070();
            else
                return 0;
            if (tile->GetType() == 0x389 && tile->FUN_00a03c90()->FUN_0059bb30() != 1 &&
                tile->FUN_00a03c90()->FUN_0059bb30() != 8)
                return 0;
        }
        if (!tile->IsTraitNonZero(0xfa3))
            return 0;
        childPos = tile->children.FUN_00559450();
        while (childPos)
        {
            Tile7160* child = *tile->children.FUN_0057cbe0(&childPos);
            current = (-2147483647 - 1);
            child = FindHighestPriorityTile(&current, child);
            if (child && current > maxPriority)
            {
                maxPriority = current;
                result = child;
            }
            else if (child && current == maxPriority)
            {
                TileValue7160* value = child->FindTraitValue(0xfac);
                if (value)
                {
                    int childTie = (int)value->FUN_00488d50();
                    if (childTie < minOrder)
                    {
                        minOrder = childTie;
                        result = child;
                    }
                }
            }
        }
        if (tile->IsTraitNonZero(0xfaf) && tile->IsTraitNonZero(0xfa3))
        {
            TileValue7160* value = tile->FUN_00a00f30(0xfd6);
            if (value)
            {
                current = (int)value->FUN_00488d50();
                if (current > maxPriority)
                {
                    maxPriority = current;
                    result = tile;
                }
                else if (current == maxPriority)
                {
                    value = tile->FindTraitValue(0xfac);
                    if (value)
                    {
                        int tileTie = (int)value->FUN_00488d50();
                        if (tileTie < minOrder)
                        {
                            minOrder = tileTie;
                            result = tile;
                        }
                    }
                }
            }
        }
        *priority = maxPriority;
        return result;
    }
}

// Scale an integer count by a float factor.
// Calls FUN_00717890 to get an integer value and divides it by the result of FUN_00715da0, returning the quotient as a float.
// @fnv 0x00717860
float __cdecl FUN_00717860()
{
    int value = FUN_00717890();
    return (float)((double)value / FUN_00715da0());
}

extern const double DAT_0101e568;
float __cdecl FUN_004bd510(float, float);

class FUN_00719490_cls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual int v2(unsigned int);
    int FUN_00719490(float* p);
};

// @fnv 0x00719490
int FUN_00719490_cls::FUN_00719490(float* p)
{
    return v2(PackRgba((unsigned int)FUN_004bd510((float)(p[0] * DAT_0101e568), 1.0f),
                       (unsigned int)FUN_004bd510((float)(p[1] * DAT_0101e568), 1.0f),
                       (unsigned int)FUN_004bd510((float)(p[2] * DAT_0101e568), 1.0f), 0xff));
}

void FUN_009ff8a0(const char*, bool);
int TraitNameToID(const char*);
void FUN_00719580(void*);
void UpdateStartMenuTile();
struct MenuView
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
    virtual void SetController(bool);
};
struct TileView
{
    MenuView* FUN_00a03c90();
};
struct TileList
{
    void* GetHeadPos() const;
    TileView*& GetNext(void*&);
};
struct RootTiles
{
    int unk00;
    TileList children;
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
    RootTiles* root;
    Tile_Set_Helper* target;
    void UpdateControllerState(int);
};
// @fnv 0x00719630
void Context::UpdateControllerState(int unused)
{
    FUN_004b7210();
    FUN_009ff8a0("&xenon;", FUN_004b71d0());
    FUN_004b7210();
    FUN_009ff8a0("&xbox;", FUN_004b71d0());
    target->Set(TraitNameToID("_Has360Controller"), FUN_004b71d0());
    FUN_00719580(root);
    void* position = root ? root->children.GetHeadPos() : 0;
    while (position)
    {
        TileView* tile = root->children.GetNext(position);
        if (tile && tile->FUN_00a03c90())
            tile->FUN_00a03c90()->SetController(FUN_004b71d0());
    }
    UpdateStartMenuTile();
}

struct AnimationTile
{
    void FUN_00a012d0(int trait, float value, bool propagate);
};
struct AnimationItem
{
    int FUN_00401170();
    int GetField19C();
    int GetField1BC();
    int GetUnk15C();
};
struct AnimationReference
{
    AnimationItem* FUN_0044ddc0();
};
struct AnimationActorValues
{
    virtual void Destroy();
    virtual void Copy();
    virtual void Reset();
    virtual float GetCurrentValue(int value);
    float FUN_0066ef50(int value);
};
struct AnimationPlayer
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
    AnimationActorValues values;
};
void FUN_005330e0(float*, float, float);
void FUN_005e58f0(int, PlayerObj*, ...);
extern float DAT_011d8a68;
extern unsigned int DAT_011d8a64;
extern bool DAT_011d8a50;

// Updates two animation tiles' trait 4009 values from a clamped fade level, sets a status tile, and advances the fade level between -230 and 485.
// @fnv 0x00719790
void __cdecl UpdateAnimationTileFade(AnimationTile* apFirstTile, AnimationTile* apSecondTile,
                                     AnimationTile* apStatusTile, AnimationReference* reference, bool alternate)
{
    // Local spellings and declaration order preserve the original MSVC9 stack layout.
    float elapsed = 485.0f;  // Upper animation bound.
    float rate = -230.0f;    // Lower animation bound.
    float maximum;           // Current clamped alpha.
    float minimum = 0.25f;   // Animation rate.
    maximum = DAT_011d8a68;
    FUN_005330e0(&maximum, 0.0f, 255.0f);
    float inverse = 255.0 - maximum;
    FUN_005330e0(&inverse, 0.0f, 255.0f);
    if (apFirstTile && apSecondTile)
    {
        apFirstTile->FUN_00a012d0(4009, inverse, true);
        apSecondTile->FUN_00a012d0(4009, maximum, true);
    }
    if (apStatusTile && reference && !alternate)
    {
        AnimationItem* item = reference ? reference->FUN_0044ddc0() : 0;
        float value = 0.0f;
        FUN_005e58f0(53, DAT_011dea3c, reference->FUN_0044ddc0(), &value);
        value += ((AnimationPlayer*)DAT_011dea3c)->values.FUN_0066ef50(5);
        if (item && item->FUN_00401170() == 40 && value < item->GetField19C())
            apStatusTile->FUN_00a012d0(4009, inverse > 128.0 ? inverse : maximum, true);
        else
            apStatusTile->FUN_00a012d0(4009, 255.0f, true);
    }
    else if (apStatusTile && reference && alternate)
    {
        AnimationItem* item = reference ? reference->FUN_0044ddc0() : 0;
        float value = ((AnimationPlayer*)DAT_011dea3c)->values.GetCurrentValue(item->GetUnk15C());
        if (item && item->FUN_00401170() == 40 && value < item->GetField1BC())
            apStatusTile->FUN_00a012d0(4009, inverse > 128.0 ? inverse : maximum, true);
        else
            apStatusTile->FUN_00a012d0(4009, 255.0f, true);
    }
    unsigned int alpha = g_timeGlobal.GetSection();  // Current time.
    unsigned int uiDelta = alpha - DAT_011d8a64;     // Elapsed time.
    DAT_011d8a64 = alpha;
    if (DAT_011d8a50)
        DAT_011d8a68 -= uiDelta * minimum;
    else
        DAT_011d8a68 += uiDelta * minimum;
    FUN_005330e0(&DAT_011d8a68, rate, elapsed);
    if (DAT_011d8a68 >= elapsed)
        DAT_011d8a50 = true;
    if (DAT_011d8a68 <= rate)
        DAT_011d8a50 = false;
}

namespace fnv_00713fb0 {
struct D3DVP
{
    unsigned int X;
    unsigned int Y;
    unsigned int Width;
    unsigned int Height;
    float MinZ;
    float MaxZ;
};

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float fr, float fg, float fb, float fa);
};

struct Dev
{

    virtual void __stdcall d000();
    virtual void __stdcall d004();
    virtual void __stdcall d008();
    virtual void __stdcall d00c();
    virtual void __stdcall d010();
    virtual void __stdcall d014();

    virtual void __stdcall d018();
    virtual void __stdcall d01c();
    virtual void __stdcall d020();
    virtual void __stdcall d024();
    virtual void __stdcall d028();
    virtual void __stdcall d02c();

    virtual void __stdcall d030();
    virtual void __stdcall d034();
    virtual void __stdcall d038();
    virtual void __stdcall d03c();
    virtual void __stdcall d040();
    virtual void __stdcall d044();

    virtual void __stdcall d048();
    virtual void __stdcall d04c();
    virtual void __stdcall d050();
    virtual void __stdcall d054();
    virtual void __stdcall d058();
    virtual void __stdcall d05c();

    virtual void __stdcall d060();
    virtual void __stdcall d064();
    virtual void __stdcall d068();
    virtual void __stdcall d06c();
    virtual void __stdcall d070();
    virtual void __stdcall d074();

    virtual void __stdcall d078();
    virtual void __stdcall d07c();
    virtual void __stdcall d080();
    virtual void __stdcall d084();
    virtual void __stdcall d088();
    virtual void __stdcall d08c();

    virtual void __stdcall d090();
    virtual void __stdcall d094();
    virtual void __stdcall d098();
    virtual void __stdcall d09c();
    virtual void __stdcall d0a0();
    virtual void __stdcall d0a4();

    virtual void __stdcall d0a8();
    virtual void __stdcall d0ac();
    virtual void __stdcall d0b0();
    virtual void __stdcall d0b4();
    virtual void __stdcall d0b8();

    virtual void __stdcall SetViewport(D3DVP* vp);

    virtual void __stdcall d0c0();
    virtual void __stdcall d0c4();
    virtual void __stdcall d0c8();
    virtual void __stdcall d0cc();
    virtual void __stdcall d0d0();
    virtual void __stdcall d0d4();

    virtual void __stdcall d0d8();
    virtual void __stdcall d0dc();
    virtual void __stdcall d0e0();

    virtual void __stdcall SetRenderState(int state, int value);

    virtual void __stdcall d0e8();
    virtual void __stdcall d0ec();
    virtual void __stdcall d0f0();
    virtual void __stdcall d0f4();
    virtual void __stdcall d0f8();
    virtual void __stdcall d0fc();

    virtual void __stdcall d100();
    virtual void __stdcall d104();
    virtual void __stdcall d108();
    virtual void __stdcall d10c();
    virtual void __stdcall d110();
    virtual void __stdcall d114();

    virtual void __stdcall d118();
    virtual void __stdcall d11c();
    virtual void __stdcall d120();
    virtual void __stdcall d124();
    virtual void __stdcall d128();
    virtual void __stdcall d12c();

    virtual void __stdcall d130();
    virtual void __stdcall d134();
    virtual void __stdcall d138();
    virtual void __stdcall d13c();
    virtual void __stdcall d140();
    virtual void __stdcall d144();

    virtual void __stdcall d148();
    virtual void __stdcall d14c();
    virtual void __stdcall d150();
    virtual void __stdcall d154();
    virtual void __stdcall d158();

    virtual void __stdcall SetPixelShader(int shader);

    virtual void __stdcall GetPixelShader(int* shader);

    virtual void __stdcall d164();
    virtual void __stdcall d168();
    virtual void __stdcall d16c();

    virtual void __stdcall SetVertexShader(int shader);

    virtual void __stdcall d174();
    virtual void __stdcall d178();
    virtual void __stdcall d17c();
    virtual void __stdcall d180();
    virtual void __stdcall d184();
    virtual void __stdcall d188();

    virtual void __stdcall d18c();
    virtual void __stdcall d190();
    virtual void __stdcall d194();
    virtual void __stdcall d198();
    virtual void __stdcall d19c();
    virtual void __stdcall d1a0();

    virtual void __stdcall d1a4();
    virtual void __stdcall d1a8();

    virtual void __stdcall SetFVF(int fvf);
};

struct Shadow
{

    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();

    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();

    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();

    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();

    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();

    virtual void s078();

    virtual void s07c(int a, int b);

    virtual int s080();

    virtual void s084();

    virtual void s088(int a);

    virtual void s08c(int a, int b);

    virtual int s090();

    virtual void s094();

    virtual void s098(int a);

    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();

    virtual int s0b0();

    virtual void s0b4();

    virtual void s0b8(int a);
};

struct RT
{

    virtual void r000();
    virtual void r004();
    virtual void r008();
    virtual void r00c();
    virtual void r010();
    virtual void r014();

    virtual void r018();
    virtual void r01c();
    virtual void r020();
    virtual void r024();
    virtual void r028();
    virtual void r02c();

    virtual void r030();
    virtual void r034();
    virtual void r038();
    virtual void r03c();
    virtual void r040();
    virtual void r044();

    virtual void r048();
    virtual void r04c();
    virtual void r050();
    virtual void r054();
    virtual void r058();
    virtual void r05c();

    virtual void r060();
    virtual void r064();
    virtual void r068();
    virtual void r06c();
    virtual void r070();
    virtual void r074();

    virtual void r078();
    virtual void r07c();
    virtual void r080();
    virtual void r084();
    virtual void r088();

    virtual unsigned int GetWidth(int i);

    virtual unsigned int GetHeight(int i);
};

struct ScreenObj
{
    unsigned int FUN_0044ddc0();
    unsigned int FUN_0084e3a0();
};

struct Renderer
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

    virtual void SetBackgroundColor(const RgbaColor* c);

    virtual void v0b0();

    virtual void GetBackgroundColor(RgbaColor* c);

    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();

    virtual RT* GetDefaultRT();

    virtual RT* GetCurrentRT();

    virtual void v0d0();

    virtual ScreenObj* GetScreen();

    static Renderer* __cdecl GetSingleton();

    Dev* FUN_004dc020();

    Shadow* GetField8B8();

    void* FUN_005585e0();

    void FUN_007148c0(RgbaColor* c, int b);
};

struct Obj10
{
    unsigned int FUN_0044ddc0();
};

struct Obj6629
{
    void FUN_00712e60(float* p);
};

struct Obj7fa
{
    Obj10* FUN_008d80e0();
    Obj6629* FUN_006629f0();
};

struct ScopeE8
{
    int unk0;
    ScopeE8(int a, int b, const char* f, int l);
    ~ScopeE8();
};

struct ObjE4
{

    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c;

    int u030, u034, u038, u03c, u040, u044, u048, u04c, u050, u054, u058, u05c;

    int u060, u064, u068, u06c, u070, u074, u078, u07c, u080, u084, u088, u08c;

    int u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;

    int u0c0, u0c4;

    ObjE4(unsigned int v);

    ~ObjE4();
};

struct ObjF0
{
    int unk0;
    ObjF0(void* p);
    ~ObjF0();
};

struct FlagHolder
{
    unsigned char* FUN_00408d60();
};

extern FlagHolder DAT_011db2cc;

extern unsigned char DAT_011f9426;

extern float DAT_011ad840;

extern float DAT_011ad844;

extern float DAT_011ad848;

extern float DAT_011ad84c;

extern RgbaColor DAT_011a9bd0;

extern float DAT_01026994;

extern float DAT_010340a4;

extern const char DAT_0106ef50[];

bool __cdecl FUN_004e9510();

void __cdecl FUN_00b6b890(int a, int b);

bool __cdecl FUN_004de080();

int __cdecl FUN_00683a60();

bool __cdecl FUN_00714a00();

void __cdecl FUN_00a81a80();

void __cdecl FUN_00714960(int a);

bool __cdecl FUN_007178a0();

bool __cdecl FUN_00717990();

void __cdecl FUN_00714900();

void __cdecl FUN_00b6b730();

void __cdecl FUN_00714a40(int a);

void __cdecl FUN_00714a60(int a);

void __cdecl FUN_00714a80(int a);

void __cdecl FUN_00714aa0(int a);

void __cdecl FUN_00714ac0(int a);

void __cdecl FUN_00714ae0(int a);

void __cdecl FUN_00714b00(int a);

void __cdecl FUN_004eced0(int a);

void __cdecl FUN_004ecb40(int a);

void __cdecl FUN_00714b20(int a);

void __cdecl FUN_00714b50(int a);

void __cdecl FUN_00714b80(int a);

void __cdecl FUN_00714bb0(int a);

void __cdecl FUN_00714bd0(int a);

void __cdecl FUN_004eb510(int a);

void __cdecl FUN_00714bf0(int a);

void __cdecl FUN_00714c20(int a);

void __cdecl FUN_00714c40(int a);

struct MenuMgr
{

    int u000, u004, u008, u00c, u010, u014, u018, u01c, u020, u024, u028, u02c;

    int u030, u034, u038, u03c, u040, u044, u048, u04c, u050, u054, u058, u05c;

    int u060, u064, u068, u06c, u070, u074, u078, u07c, u080, u084, u088, u08c;

    int u090, u094, u098, u09c, u0a0, u0a4, u0a8, u0ac, u0b0, u0b4, u0b8, u0bc;

    int u0c0, u0c4, u0c8, u0cc, u0d0, u0d4, u0d8, u0dc, u0e0, u0e4, u0e8, u0ec;

    int u0f0, u0f4, u0f8, u0fc, u100, u104, u108, u10c, u110, u114, u118, u11c;

    int u120, u124, u128, u12c, u130, u134, u138, u13c, u140, u144, u148, u14c;

    int u150, u154, u158, u15c, u160, u164;

    unsigned char unk168;

    int u16c, u170, u174, u178, u17c, u180, u184, u188, u18c, u190, u194, u198;

    int u19c, u1a0, u1a4, u1a8, u1ac, u1b0, u1b4, u1b8, u1bc, u1c0, u1c4, u1c8;

    int u1cc, u1d0, u1d4, u1d8, u1dc, u1e0, u1e4, u1e8, u1ec, u1f0, u1f4, u1f8;

    int u1fc, u200, u204, u208, u20c, u210, u214, u218, u21c, u220, u224, u228;

    int u22c, u230, u234, u238, u23c, u240, u244, u248, u24c, u250, u254, u258;

    int u25c, u260, u264, u268, u26c, u270, u274, u278, u27c, u280, u284, u288;

    int u28c, u290, u294, u298, u29c, u2a0, u2a4, u2a8, u2ac, u2b0, u2b4, u2b8;

    int u2bc, u2c0, u2c4, u2c8, u2cc, u2d0, u2d4, u2d8, u2dc, u2e0, u2e4, u2e8;

    int u2ec, u2f0, u2f4, u2f8, u2fc, u300, u304, u308, u30c, u310, u314, u318;

    int u31c, u320, u324, u328, u32c, u330, u334, u338, u33c, u340, u344, u348;

    int u34c, u350, u354, u358, u35c, u360, u364, u368, u36c, u370, u374, u378;

    int u37c, u380, u384, u388, u38c, u390, u394, u398, u39c, u3a0, u3a4, u3a8;

    int u3ac, u3b0, u3b4, u3b8, u3bc, u3c0, u3c4, u3c8, u3cc, u3d0, u3d4, u3d8;

    int u3dc, u3e0, u3e4, u3e8, u3ec, u3f0, u3f4, u3f8, u3fc, u400, u404, u408;

    int u40c, u410, u414, u418, u41c, u420, u424, u428, u42c, u430, u434, u438;

    int u43c, u440, u444, u448, u44c, u450, u454, u458, u45c, u460, u464, u468;

    int u46c, u470, u474, u478, u47c, u480, u484, u488, u48c, u490, u494, u498;

    int u49c, u4a0, u4a4, u4a8, u4ac, u4b0, u4b4, u4b8;

    int unk4bc;

    Obj7fa* FUN_007fa950();

    void FUN_007134d0(ObjE4* p, bool b);

    void RenderMenu(int a, int b);
};

// @fnv 0x00713fb0
void MenuMgr::RenderMenu(int a, int b)

{

    Renderer* pkRenderer = Renderer::GetSingleton();

    bool bRestorec = false;

    if (FUN_004e9510())
    {

        if (DAT_011f9426)
        {

            unsigned int uiWidth = Renderer::GetSingleton()->GetScreen()->FUN_0044ddc0();

            unsigned int uiHeighth = Renderer::GetSingleton()->GetScreen()->FUN_0084e3a0();

            D3DVP kViewportb;

            kViewportb.MinZ = 0.0f;

            kViewportb.MaxZ = 1.0f;

            kViewportb.X = (unsigned int)(uiWidth * DAT_011ad840);

            kViewportb.Width = (unsigned int)((DAT_011ad844 - DAT_011ad840) * uiWidth);

            kViewportb.Y = (unsigned int)(uiHeighth * DAT_011ad84c);

            kViewportb.Height = (unsigned int)((DAT_011ad848 - DAT_011ad84c) * uiHeighth);

            Renderer::GetSingleton()->FUN_004dc020()->SetViewport(&kViewportb);
        }

        FUN_00b6b890(7, 0);

        bRestorec = true;

        if (FUN_004de080())
        {

            RgbaColor kOldColorf(0.0f, 0.0f, 0.0f, 0.0f);

            Renderer::GetSingleton()->GetBackgroundColor(&kOldColorf);

            Renderer::GetSingleton()->SetBackgroundColor(&DAT_011a9bd0);

            RgbaColor kColord(0.0f, 0.0f, 0.0f, 0.0f);

            kColord.r = 0.0f;

            kColord.g = DAT_01026994;

            kColord.b = 1.0f;

            kColord.a = 0.0f;

            Renderer::GetSingleton()->FUN_007148c0(&kColord, 1);

            kColord.r = DAT_010340a4;

            kColord.g = 1.0f;

            kColord.b = 1.0f;

            kColord.a = 0.0f;

            Renderer::GetSingleton()->FUN_007148c0(&kColord, 1);

            Renderer::GetSingleton()->SetBackgroundColor(&kOldColorf);
        }

        if (DAT_011f9426)
        {

            FUN_007fa950()->FUN_006629f0()->FUN_00712e60(&DAT_011ad840);
        }
    }

    ScopeE8 kScopee(0xd, 1, DAT_0106ef50, 0x1069);

    Obj7fa* pMenuh8 = FUN_007fa950();

    int iEarlyh4 = 0;

    if (!pMenuh8)
    {

        iEarlyh4 = 1;

        return;
    }

    Obj10* pTilea_ = pMenuh8->FUN_008d80e0();

    ObjE4 kE4g(pTilea_->FUN_0044ddc0());

    ObjF0 kF0f6(pkRenderer->FUN_005585e0());

    if (FUN_00683a60())
    {

        if (FUN_00714a00())

            FUN_00a81a80();

        FUN_00714960(-1);
    }

    bool bFlagl;

    if (*DAT_011db2cc.FUN_00408d60())

        bFlagl = unk4bc == 2 || ((FUN_007178a0() || unk168) && FUN_00717990());

    else

        bFlagl = false;

    FUN_007134d0(&kE4g, bFlagl);

    if (bRestorec)
    {

        D3DVP kVPl;

        kVPl.X = 0;

        kVPl.Y = 0;

        kVPl.MinZ = 0.0f;

        kVPl.MaxZ = 1.0f;

        RT* pRTh = Renderer::GetSingleton()->GetCurrentRT();

        if (!pRTh)

            pRTh = Renderer::GetSingleton()->GetDefaultRT();

        kVPl.Width = pRTh->GetWidth(0);

        kVPl.Height = pRTh->GetHeight(0);

        Renderer::GetSingleton()->FUN_004dc020()->SetViewport(&kVPl);

        int iShadero = 0;

        Renderer::GetSingleton()->FUN_004dc020()->GetPixelShader(&iShadero);

        Renderer::GetSingleton()->FUN_004dc020()->SetRenderState(0x1b, 0);

        Renderer::GetSingleton()->GetField8B8()->s08c(0, 0);

        Renderer::GetSingleton()->GetField8B8()->s07c(0, 0);

        Renderer::GetSingleton()->FUN_004dc020()->SetFVF(0);

        Renderer::GetSingleton()->FUN_004dc020()->SetVertexShader(0);

        Renderer::GetSingleton()->FUN_004dc020()->SetPixelShader(iShadero);

        FUN_00714a40(0);

        FUN_00714a60(0);

        FUN_00714a80(0);

        FUN_00714aa0(0);

        FUN_00714ac0(0);

        FUN_00714ae0(0);

        FUN_00714b00(0);

        FUN_004eced0(0);

        FUN_004ecb40(0);

        FUN_00714b20(0);

        FUN_00714b50(0);

        FUN_00714b80(0);

        FUN_00714bb0(0);

        FUN_00714bd0(0);

        FUN_004eb510(0);

        FUN_00714bf0(0);

        FUN_00714c20(0);

        FUN_00714c40(0);

        FUN_00b6b730();

        Shadow* pShadowf5 = Renderer::GetSingleton()->GetField8B8();

        pShadowf5->s0b8(pShadowf5->s0b0());

        pShadowf5->s098(pShadowf5->s090());

        pShadowf5->s088(pShadowf5->s080());
    }

    if (FUN_00683a60())

        FUN_00714900();
}
}  // namespace fnv_00713fb0

namespace fnv_007126c0 {
enum MEM_CONTEXT
{
    MEM_CONTEXT_MEM_CONTEXT_INTERFACE = 13,
};

class AutoMemContext
{
  public:
    int iPrevious;
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bOverride, const char* pcFile, int iLine);
    ~AutoMemContext();
};

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
};

class FUN_00414430_Rect
{
  public:
    float fLeft, fTop, fRight, fBottom;
    FUN_00414430_Rect(float fA, float fB, float fC, float fD);
};

struct PickRect
{
    int iLeft;
    int iTop;
    int iRight;
    int iBottom;
};

class PickProperty
{
  public:
    PickRect* FUN_0050d100();
};
class PickAVObject
{
  public:
    PickProperty* FUN_00a59d30(int iType);
};
class PickNode
{
  public:
    PickAVObject* FUN_0043b4a0(int iIndex);
    void FUN_004add70();
    void* FUN_0045bc00(int iIndex);
};

class PickValue
{
  public:
    float FUN_00a011b0();
};
class PickValueNode
{
  public:
    PickValue* FUN_00726070();
};

class PickTile
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual int GetType();
    virtual void v004();
    virtual bool ContainsPoint(float fX, float fYFinal);
    bool IsTraitNonZero(int m_iValueId);
    PickNode* FUN_0056c7f0();
    PickValueNode* FUN_00a03c90(int m_iValueId);
    void* FindTraitValue(int m_iValueId);
    PickTile* FUN_0045cd60();
};
PickTile* FUN_00a01630(class PickObject* pkObject);
PickTile* FUN_00a09030(void* pvMenu);
int FUN_00438220();

class PickObject
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual PickObject* GetOwner();
    PickObject* FUN_009611e0();
};

class PickTarget
{
  public:
    PickObject* FUN_009611e0();
};
class PickRecordView
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual PickObject* GetObject();
};
class PickRecord
{
  public:
    PickRecordView* FUN_00458b50();
    unsigned short FUN_0047d3d0();
};
class PickResults
{
  public:
    int FUN_0044edb0();
    PickRecord* FUN_00968670(int iIndex);
};

class NiPick
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
    NiPick(int iA, int iB);
    ~NiPick();
    void FUN_00632d20(bool bValue);
    void SetByteAtOffset17(bool bValue);
    void FUN_00705fc0(PickNode* pkRootLoc);
    bool FUN_00e98e20(NiPoint3* pkOrigin, NiPoint3* pkDir, int iValue);
    PickResults* FUN_00500940();
};

class PickCamera
{
  public:
    void FUN_00712e60(const FUN_00414430_Rect& pDataToSerialize);
    void MapScreenToRay(int iX, int iY, NiPoint3* pkOrigin, NiPoint3* pkDir, int iValue);
};
class PickScene
{
  public:
    PickCamera* FUN_006629f0();
};

class PickCursor
{
  public:
    void FUN_00450f90(bool bValue);
};
class PickMode
{
  public:
    static bool IsStartMenuFlag1Set();
};
class PickController
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual PickMode* GetMode();
    virtual void Refresh();
};

struct PickBoolSetting
{
    unsigned char* FUN_00408d60();
};
extern PickBoolSetting DAT_011db2cc;
extern unsigned char DAT_011f9426;
float FUN_00706e50();
float FUN_00706e20();
double FUN_00706e40();
float FUN_00706e80();
float FUN_00404010(float fA, float fB);
float FUN_0040ebd0(float fA, float fB);
bool FUN_00717990();

class IMView
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
    float m_fCursorX;  // +0x38
    int unk03c;
    float m_fCursorY;  // +0x40
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
    unsigned short unk0b0;
    unsigned short m_usTileValue;  // +0xb2
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
    PickController* m_pkController;  // +0x16c
    bool m_bScaled;                  // +0x170
    unsigned char unk171;
    unsigned short unk172;
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
    float m_fScaledX;  // +0x4ac
    float m_fScaledY;  // +0x4b0
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    float m_fScale;  // +0x4d0

    PickCursor* FUN_004fd3c0();
    PickScene* FUN_007fa950();
    void* FUN_00714f00();
    bool FUN_00716910(PickTile* pkTileTmp);
    PickTile* FUN_007126c0(bool bAny);
};

// Performs a 3D pick at the cursor position, walks the hit results to find a PickTile, and returns it or null.
// @fnv 0x007126c0
PickTile* IMView::FUN_007126c0(bool bAny)
{
    AutoMemContext kMemContextCur(MEM_CONTEXT_MEM_CONTEXT_INTERFACE, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp",
                                  0xd5c);
    PickTile* pkResult = 0;
    FUN_004fd3c0()->FUN_00450f90(true);
    PickNode* pkRootLoc = (PickNode*)FUN_007fa950();
    if (m_pkController && m_pkController->GetMode()->IsStartMenuFlag1Set())
        pkRootLoc = FUN_00a09030(FUN_00714f00())->FUN_0056c7f0();
    NiPick kPickOut(0, 8);
    kPickOut.FUN_00632d20(false);
    kPickOut.SetByteAtOffset17(true);
    kPickOut.FUN_00705fc0(pkRootLoc);
    NiPoint3 kOriginVal;
    NiPoint3 kWorldPosition;
    float fX = FUN_0040ebd0(FUN_00404010(0.0f, m_fCursorX), FUN_00706e50());
    float fYFinal = FUN_0040ebd0(FUN_00404010(0.0f, m_fCursorY), FUN_00706e20());
    if (*DAT_011db2cc.FUN_00408d60())
    {
        if (m_bScaled)
        {
            fX = m_fScaledX;
            fYFinal = m_fScaledY;
        }
        else if (FUN_00717990())
            return 0;
    }
    if (DAT_011f9426)
        FUN_007fa950()->FUN_006629f0()->FUN_00712e60(FUN_00414430_Rect(0.0f, 1.0f, 1.0f, 0.0f));
    FUN_007fa950()->FUN_006629f0()->MapScreenToRay((int)fX, (int)fYFinal, &kOriginVal, &kWorldPosition, 0);
    if (kPickOut.FUN_00e98e20(&kOriginVal, &kWorldPosition, 0))
    {
        PickRecord* pkRecordVal;
        int i = 0;
        while (i < kPickOut.FUN_00500940()->FUN_0044edb0())
        {
            pkRecordVal = kPickOut.FUN_00500940()->FUN_00968670(i++);
            PickObject* pkObject = pkRecordVal->FUN_00458b50() ? pkRecordVal->FUN_00458b50()->GetObject() : 0;
            if (!pkObject && ((PickTarget*)pkRecordVal->FUN_00458b50())->FUN_009611e0())
                pkObject = ((PickTarget*)pkRecordVal->FUN_00458b50())->FUN_009611e0()->GetOwner();
            PickTile* pkTileTmp = 0;
            if (pkObject)
                pkTileTmp = FUN_00a01630(pkObject);
            while (!pkTileTmp && pkObject)
            {
                pkObject = pkObject->FUN_009611e0();
                pkTileTmp = FUN_00a01630(pkObject);
            }
            if (pkTileTmp)
            {
                if (!FUN_00716910(pkTileTmp))
                    continue;
                if (pkTileTmp->IsTraitNonZero(0xfae) && pkTileTmp->FUN_0056c7f0())
                {
                    bool bScaled = pkTileTmp->FUN_00a03c90(0xfaa)->FUN_00726070()->FUN_00a011b0() == 112.0f ? 1 : 0;
                    pkTileTmp->FUN_0056c7f0()->FUN_004add70();
                    if (pkTileTmp->FUN_0056c7f0()->FUN_0045bc00(0))
                    {
                        PickProperty* pkProperty =
                            pkTileTmp->FUN_0056c7f0()->FUN_0043b4a0(0)->FUN_00a59d30(FUN_00438220());
                        if (pkProperty)
                        {
                            PickRect pDataToSerialize = *pkProperty->FUN_0050d100();
                            if (*DAT_011db2cc.FUN_00408d60() && m_bScaled)
                            {
                                float fRatio = FUN_00706e40() / FUN_00706e80();
                                pDataToSerialize.iLeft = (int)(pDataToSerialize.iLeft * fRatio);
                                pDataToSerialize.iRight = (int)(pDataToSerialize.iRight * fRatio);
                                pDataToSerialize.iTop = (int)(pDataToSerialize.iTop * fRatio);
                                pDataToSerialize.iBottom = (int)(pDataToSerialize.iBottom * fRatio);
                            }
                            if (pDataToSerialize.iLeft || pDataToSerialize.iRight || pDataToSerialize.iTop ||
                                pDataToSerialize.iBottom)
                            {
                                float fTestX = fX;
                                if (bScaled)
                                    fTestX *= ((IMView*)FUN_004b7210())->m_fScale;
                                float fTestYVal = fYFinal;
                                if (pDataToSerialize.iLeft > fTestX || pDataToSerialize.iRight <= fTestX ||
                                    pDataToSerialize.iTop > fTestYVal || pDataToSerialize.iBottom <= fTestYVal)
                                    continue;
                            }
                        }
                    }
                }
            }
            if (pkTileTmp && !pkTileTmp->ContainsPoint(fX, fYFinal))
                continue;
            if (pkTileTmp && pkTileTmp->IsTraitNonZero(0xfaf))
            {
                if (!bAny && !pkTileTmp->FindTraitValue(0xfaa))
                {
                    PickTile* pkParent = pkTileTmp->FUN_0045cd60();
                    while (pkParent && !pkParent->FindTraitValue(0xfaa))
                        pkParent = pkParent->FUN_0045cd60();
                    if (pkParent)
                        pkTileTmp = pkParent;
                }
                pkResult = pkTileTmp;
                if (pkResult->GetType() == 0x387)
                    m_usTileValue = pkRecordVal->FUN_0047d3d0() / 2;
                else
                    m_usTileValue = 0xffff;
                break;
            }
        }
    }
    FUN_004fd3c0()->FUN_00450f90(false);
    if (m_pkController)
        m_pkController->Refresh();
    return pkResult;
}
}  // namespace fnv_007126c0

struct Entry718080
{
    float GetAccumulatedFloat();
    double FUN_00a011b0(int iKey);
};
struct Source718080
{
    virtual void Apply(Entry718080* pkEntry);
    virtual int IsActive();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual Entry718080* GetEntry(int iIndex, int iFlags);
};
struct Node718080
{
    Source718080*& GetItem();
    Node718080* GetNext();
    Source718080* m_item;
    Node718080* m_pkNext;
};
extern Node718080 g_kSources718080;
struct Target718080
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
    virtual void Update(int iA, int iB);
};
float GetRatio();
bool FUN_00717920();
float FUN_00717860();
extern double g_dOffset718080;
struct Controller718080
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
    float m_fValue40;
    void FUN_00718080(Target718080* pkTarget, int iA, int iB);
};

// Computes a time value, scans entries for each active source and applies the scan result, then calls pkTarget->Update.
// @fnv 0x00718080
void Controller718080::FUN_00718080(Target718080* pkTarget, int iA, int iB)
{
    float fTime = m_fValue40 / GetRatio();
    if (FUN_00717920())
        fTime = fTime / FUN_00717860() - g_dOffset718080;
    for (Node718080* pkNode = &g_kSources718080; pkNode && pkNode->GetItem(); pkNode = pkNode->GetNext())
    {
        if (pkNode->GetItem()->IsActive())
        {
            Entry718080* pkEntry = 0;
            int i = 0;
            do
            {
                pkEntry = pkNode->GetItem()->GetEntry(i++, 0);
            } while (pkEntry && (pkEntry->GetAccumulatedFloat() > fTime ||
                                 pkEntry->GetAccumulatedFloat() + pkEntry->FUN_00a011b0(0xfb0) < fTime));
            pkNode->GetItem()->Apply(pkEntry);
        }
    }
    pkTarget->Update(iA, iB);
}

extern char* __cdecl FUN_004046f0(char* dst, const char* src);

struct TextInputField
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int iCursor;    // 10
    int iMaxWidth;  // 14
    int unk18;
    int unk1C;
    char unk20;
    bool bActive;     // 21
    bool bSelectAll;  // 22
    char unk23;

    int FUN_004048e0();
    const char* FUN_00559450();
    void FUN_00438390(const char* text);
    bool FUN_00717230(const char* text);
    void FUN_00716b00(int key);
};

// Handles a key press in the text field, updating the cursor, text buffer, and active state based on the key code.
// @fnv 0x00716b00
void TextInputField::FUN_00716b00(int key)
{
    char abuf[0x400];
    int len;
    int iM;
    int AJ;
    int k;
    if (!bActive)
        return;
    if (FUN_004048e0() == 0)
        FUN_004046f0(abuf, "");
    else
        FUN_004046f0(abuf, FUN_00559450());
    len = FUN_004048e0();
    switch (key)
    {
    case 9:
        break;
    case (int)0x80000000:
        if (bSelectAll)
        {
            len = 0;
            abuf[len] = 0;
            iCursor = 0;
            FUN_00438390(abuf);
            bSelectAll = false;
        }
        else if (iCursor > 0)
        {
            for (AJ = iCursor - 1; AJ < len; AJ++)
                abuf[AJ] = abuf[AJ + 1];
            len--;
            iCursor--;
            abuf[len] = 0;
            FUN_00438390(abuf);
        }
        break;
    case (int)0x80000007:
        if (bSelectAll)
        {
            len = 0;
            abuf[len] = 0;
            iCursor = 0;
            FUN_00438390(abuf);
            bSelectAll = false;
        }
        else if (iCursor < len)
        {
            for (k = iCursor; k < len; k++)
                abuf[k] = abuf[k + 1];
            len--;
            abuf[len] = 0;
            FUN_00438390(abuf);
        }
        break;
    case (int)0x80000001:
        if (iCursor > 0)
            iCursor--;
        bSelectAll = false;
        break;
    case (int)0x80000002:
        if (iCursor < len)
            iCursor++;
        bSelectAll = false;
        break;
    case (int)0x80000005:
        iCursor = 0;
        bSelectAll = false;
        break;
    case (int)0x80000006:
        iCursor = len;
        bSelectAll = false;
        break;
    case (int)0x80000008:
        if (bSelectAll)
        {
            len = 0;
            abuf[len] = 0;
            iCursor = 0;
            FUN_00438390(abuf);
            bSelectAll = false;
        }
        else
        {
            bActive = false;
        }
        break;
    case (int)0x80000009:
    case (int)0x8000000A:
        bSelectAll = false;
        break;
    default:
        if (bSelectAll)
        {
            len = 0;
            abuf[len] = 0;
            iCursor = 0;
            FUN_00438390(abuf);
            bSelectAll = false;
        }
        for (iM = len; iM > iCursor; iM--)
            abuf[iM] = abuf[iM - 1];
        abuf[iM] = (char)key;
        abuf[len + 1] = 0;
        if (iMaxWidth == -1 || FUN_00717230(abuf))
        {
            len++;
            iCursor++;
            FUN_00438390(abuf);
        }
        break;
    }
}

namespace s717280 {

class BSSoundHandleEx
{
  public:
    BSSoundHandleEx();
    ~BSSoundHandleEx();

    BSSoundHandleEx& FUN_00418900(const BSSoundHandleEx& kOther);
    bool Play(bool bUnk);

    BSSoundHandleEx& operator=(const BSSoundHandleEx& kOther)
    {
        return FUN_00418900(kOther);
    }

    int m_iSoundID;
    bool m_bAssumeSuccess;
    int m_iFadeIndex;
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* pcEditorID, unsigned int uiFlags);
};

static const char s_szUIMenuMode[] = "UIMenuMode";
static const char s_szUIMenuFocus[] = "UIMenuFocus";
static const char s_szUIPopUpMessageGeneral[] = "UIPopUpMessageGeneral";
static const char s_szUIMenuPrevNext[] = "UIMenuPrevNext";
static const char s_szUIMenuOK[] = "UIMenuOK";
static const char s_szUIPopUpQuestNew[] = "UIPopUpQuestNew";
static const char s_szUIMenuCancel[] = "UIMenuCancel";
static const char s_szUILevelUp[] = "UILevelUp";

// Maps recognized values to editor IDs, assigns each fetched handle, then calls Play(false).
// @fnv 0x00717280
void FUN_00717280(int aiSoundIndex)
{
    BSSoundHandleEx kSound;
    switch (aiSoundIndex)
    {
    case -1:
        return;
    case 36:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIMenuMode, 0x121));
        break;
    case 4:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIMenuFocus, 0x121));
        break;
    case 10:
    case 19:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIPopUpMessageGeneral, 0x121));
        break;
    case 3:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIMenuPrevNext, 0x121));
        break;
    case 1:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIMenuOK, 0x121));
        break;
    case 8:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIPopUpQuestNew, 0x121));
        break;
    case 2:
    case 20:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUIMenuCancel, 0x121));
        break;
    case 21:
        kSound.FUN_00418900(BSAudio::GetSingleton()->GetSoundHandleByEditorID(s_szUILevelUp, 0x121));
        break;
    default:
        return;
    }
    kSound.Play(false);
}

}

namespace fnv_00717a40 {
struct FocusManager
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
    unsigned char unk7c;
    bool controllerBlocked;
};

extern unsigned short DAT_011d8a58;
extern unsigned char DAT_011d8a5a;
extern unsigned char DAT_011d8a5b;
extern short DAT_011d8a5c;
extern short DAT_011d8a5e;
extern unsigned short DAT_011d8a70;
extern unsigned char DAT_011d8a72;
extern unsigned char DAT_011d8a73;
extern short DAT_011d8a74;
extern short DAT_011d8a76;

// Returns 1, 2, 0, or -1 for a controller button or stick axis based on current and previous input state and FocusManager controllerBlocked.
// @fnv 0x00717a40
int __cdecl FUN_00717a40(int button, bool useStick)
{
    unsigned int uiButtonMask;
    bool currentStick;
    bool previousStick;
    if ((FUN_004b7210(), FUN_004b71d0()) && !((FocusManager*)FUN_004b7210())->controllerBlocked)
    {
        if ((FUN_004b7210(), FUN_004b71d0()) && !((FocusManager*)FUN_004b7210())->controllerBlocked)
        {
            switch (button)
            {
            case 9:
                uiButtonMask = 0x1000;
                break;
            case 10:
                uiButtonMask = 0x2000;
                break;
            case 11:
                uiButtonMask = 0x4000;
                break;
            case 12:
                uiButtonMask = 0x8000;
                break;
            case 6:
                uiButtonMask = 0x20;
                break;
            case 5:
                uiButtonMask = 0x10;
                break;
            case 15:
                uiButtonMask = 0x100;
                break;
            case 16:
                uiButtonMask = 0x200;
                break;
            case 1:
                uiButtonMask = 1;
                break;
            case 2:
                uiButtonMask = 2;
                break;
            case 4:
                uiButtonMask = 4;
                break;
            case 3:
                uiButtonMask = 8;
                break;
            case 17:
                uiButtonMask = 0x40;
                break;
            case 18:
                uiButtonMask = 0x80;
                break;
            default:
                uiButtonMask = 0;
                break;
            }
            if (button != 13 && button != 14)
            {
                currentStick = false;
                previousStick = false;
                if (useStick)
                {
                    switch (uiButtonMask)
                    {
                    case 1:
                        currentStick = DAT_011d8a5e > 7849;
                        previousStick = DAT_011d8a76 > 7849;
                        break;
                    case 2:
                        currentStick = DAT_011d8a5e < -7849;
                        previousStick = DAT_011d8a76 < -7849;
                        break;
                    case 4:
                        currentStick = DAT_011d8a5c < -7849;
                        previousStick = DAT_011d8a74 < -7849;
                        break;
                    case 8:
                        currentStick = DAT_011d8a5c > 7849;
                        previousStick = DAT_011d8a74 > 7849;
                        break;
                    }
                }
                if (currentStick || previousStick)
                {
                    if (currentStick && previousStick)
                        return 0;
                    if (!currentStick && previousStick)
                        return 2;
                    if (currentStick && !previousStick)
                        return 1;
                }
                if (DAT_011d8a70 & uiButtonMask)
                {
                    if (DAT_011d8a58 & uiButtonMask)
                        return 0;
                    else
                        return 2;
                }
                else
                {
                    if (DAT_011d8a58 & uiButtonMask)
                        return 1;
                    else
                        return -1;
                }
            }
            else if (button == 13)
            {
                if (DAT_011d8a72 > 0)
                {
                    if (DAT_011d8a5a > 0)
                        return 0;
                    else
                        return 2;
                }
                else
                {
                    if (DAT_011d8a5a > 0)
                        return 1;
                    else
                        return -1;
                }
            }
            else
            {
                if (DAT_011d8a73 > 0)
                {
                    if (DAT_011d8a5b > 0)
                        return 0;
                    else
                        return 2;
                }
                else
                {
                    if (DAT_011d8a5b > 0)
                        return 1;
                    else
                        return -1;
                }
            }
        }
        return -1;
    }
    else
        return 1;
}
}  // namespace fnv_00717a40

#include <stdlib.h>
namespace fnv_007118d0 {
struct AutoMemHelper
{
    int unk00;
    AutoMemHelper(int aiType, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemHelper();
};

struct InputMgrX
{
    int GetAxisState(int a, int b);
    int FUN_00a239e0(int a);
    float GetSettingValue();
    float GetGlobalFloat();
    char GetByteAtOffset1B50();
    float FUN_00711dc0();
    float FUN_00711de0();
    int FUN_00711e00();
};

struct SettingX
{
    float* FUN_00403e20();
};
extern SettingX DAT_011d8c5c;

struct Pt3
{
    float x, y, z;
};

struct NiUpdateData
{
    float a, b, c;
    NiUpdateData(float af, bool ab, bool ac);
};

struct NodeX
{
    void FUN_00450f90(int a);
    Pt3* FUN_0043c490();
    void FUN_00440460(Pt3* p);
    void FUN_00a59c60(NiUpdateData* r);
};

struct TileX
{
    NodeX* FUN_0056c7f0();
    void FUN_00700320(int a, int b);
    float FUN_00a011b0(int a);
};

struct CheckX
{
    bool IsConsoleOpen();
};
extern CheckX* FUN_0071b160(int a);

extern float FUN_00711e40();
extern float FUN_00711e20();
extern float GetHalfValue();
extern float GetNegativeHalfValue();
extern float FUN_0040ebd0(float a, float b);
extern float FUN_00404010(float a, float b);
extern float FUN_00715d40();
extern float FUN_00715da0();
extern float FUN_00706e50();
extern float FUN_00706e20();

extern const double DAT_0106f290;

struct CursorX
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
    TileX* tile28;
    Pt3 pos2c;
    float f38;
    float f3c;
    float f40;
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
    char unk7c;
    unsigned char b7d;
    char unk7e;
    char unk7f;
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
    char unkec;
    unsigned char bED;
    void FUN_007118d0();
};

// Reads input to adjust and bound the tile position, updates stored cursor coordinates when x or z changes, and passes update data to the node.
// @fnv 0x007118d0
void CursorX::FUN_007118d0()
{
    if (FUN_004b71d0() && !b7d && !FUN_0071b160(1)->IsConsoleOpen())
        return;
    AutoMemHelper kMarker(0xd, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\InterfaceManager.cpp",
                          0xc51);
    InputMgrX* pInput2 = (InputMgrX*)g_osGlobals->FUN_00877720();
    if ((!FUN_004b71d0() || b7d) && !pInput2->FUN_00711e00())
    {
        tile28->FUN_0056c7f0()->FUN_00450f90(0);
        tile28->FUN_00700320(0xfa3, 1);
        int iX = 0;
        int iY = 0;
        if (FUN_004b71d0() && !b7d)
        {
            iX = pInput2->GetAxisState(0, 7);
            iY = pInput2->GetAxisState(0, 8);
            iX = (int)(iX * *DAT_011d8c5c.FUN_00403e20());
            iY = (int)(-(float)iY * *DAT_011d8c5c.FUN_00403e20());
        }
        else
        {
            iX = pInput2->FUN_00a239e0(1);
            iY = pInput2->FUN_00a239e0(2);
        }
        float fScale = 1.0f;
        if (iX != 0 || iY != 0)
        {
            if (pInput2->GetSettingValue() > 0.0)
            {
                fScale =
                    pInput2->GetSettingValue() + pInput2->GetGlobalFloat() * (pInput2->GetByteAtOffset1B50() / 20.0);
            }
            if (pInput2->FUN_00711dc0() > 0.0)
            {
                fScale *= pInput2->FUN_00711de0() + (abs(iX) + abs(iY)) / pInput2->FUN_00711dc0();
            }
        }
        Pt3 kPos8 = *tile28->FUN_0056c7f0()->FUN_0043c490();
        kPos8.x = FUN_00404010(FUN_00711e20() - 2.0,
                               FUN_0040ebd0(FUN_00711e40() - 2.0, iX * FUN_00715d40() / 1280.0 * fScale + kPos8.x));
        kPos8.y = tile28->FUN_00a011b0(0xfad) * DAT_0106f290;
        kPos8.z = FUN_00404010(GetNegativeHalfValue() + 1.0,
                               FUN_0040ebd0(GetHalfValue() + 1.0, kPos8.z - iY * FUN_00715da0() / 960.0f * fScale));
        tile28->FUN_0056c7f0()->FUN_00440460(&kPos8);
        if (pos2c.x != kPos8.x || pos2c.z != kPos8.z)
        {
            pos2c = kPos8;
            bED = 1;
            f38 = FUN_00706e50() / FUN_00715d40() * pos2c.x + FUN_00706e50() / 2.0;
            f3c = tile28->FUN_00a011b0(0xfad) * DAT_0106f290;
            f40 = FUN_00706e20() / 2.0 - FUN_00706e20() / FUN_00715da0() * pos2c.z;
        }
        NiUpdateData kRot6(0.0f, false, false);
        tile28->FUN_0056c7f0()->FUN_00a59c60(&kRot6);
    }
}
}  // namespace fnv_007118d0

#include <windows.h>
extern int __cdecl FUN_004019a0(void*);

struct FUN_007149b0_StandIn
{
    int unk00;
    int unk04;
    HANDLE unk08;

    int FUN_007149b0(unsigned int a);
};

// Waits on the HANDLE in unk08 for a milliseconds; returns 1 on WAIT_TIMEOUT, otherwise calls FUN_004019a0 on this and returns its result.
// @fnv 0x007149b0
int FUN_007149b0_StandIn::FUN_007149b0(unsigned int auiTimeoutMs)
{
    unsigned int result = WaitForSingleObject(unk08, auiTimeoutMs);

    if (result == WAIT_TIMEOUT)
        return 1;

    return FUN_004019a0(this);
}

namespace s716980 {

struct OwnedString
{
    char* m_pString;
    unsigned short m_usLength;
    unsigned short m_usCapacity;

    OwnedString();
    ~OwnedString();
};

struct PlainString
{
    char* m_pString;
    unsigned short m_usLength;
    unsigned short m_usCapacity;

    PlainString();
};

class SoundEntry
{
  public:
    SoundEntry();

    OwnedString m_kName;
    PlainString m_kPath;
    int m_iHandle;
    int m_iID;
    int m_iArrayLength;
    int m_iFlags;
    bool m_bPlaying;
    bool m_bLooping;
};

// @fnv 0x00716980
SoundEntry::SoundEntry()
{
    m_bLooping = false;
    m_iHandle = 0;
    m_bPlaying = false;
    m_iID = -1;
    m_iFlags = 0;
    m_iArrayLength = 1;
}

}

namespace fnv_00718ee0 {
struct SystemColorInfo;
struct FUN_00718ee0_shell : public SystemColorManager
{
    void AddColor(char*, unsigned int, unsigned int, unsigned int, SystemColorInfo*, int);
};

void* __cdecl operator new(unsigned int);
unsigned int __cdecl PackRgba(unsigned int, unsigned int, unsigned int, unsigned int);

struct FUN_00719250_stand
{
    char pad[0x10];
    FUN_00719250_stand(const char* apName, unsigned int color, int aiID);
};

struct M788
{
    void FUN_004ed8c0(void*);
};

struct Shell5 : public FUN_00718ee0_shell
{
    void AddColor(const char* apName, unsigned int aiRed, unsigned int aiGreen, unsigned int aiBlue, int aiID);
};

// Allocates a FUN_00719250_stand entry with packed RGBA, passes it to FUN_004ed8c0, and stores aiID + 1 at offset 0xc.
// @fnv 0x00718ee0
void Shell5::AddColor(const char* apName, unsigned int aiRed, unsigned int aiGreen, unsigned int aiBlue, int aiID)
{
    if (aiID < *(int*)((char*)this + 0xc))
    {
        aiID = *(int*)((char*)this + 0xc);
    }

    FUN_00719250_stand* pColor = new FUN_00719250_stand(apName, PackRgba(aiRed, aiGreen, aiBlue, 0xff), aiID);
    ((M788*)this)->FUN_004ed8c0(&pColor);
    *(int*)((char*)this + 0xc) = aiID + 1;
}
}  // namespace fnv_00718ee0

struct TESForm
{
  public:
    virtual ~TESForm();
};

class BGSMessage : public TESForm
{
  public:
    virtual ~BGSMessage();
};

namespace s7182e0 {

struct TutorialEntry
{
    int m_bPending : 1;
    int m_bShown : 1;
    unsigned int m_uiMenu : 6;
    unsigned int m_uiDelay : 24;
};

struct GameMode
{
    int unk000;
    int unk004;
    int unk008;
    int m_iMode;
};

extern GameMode* DAT_011d8a80;

bool IsStartMenuFlag1Set();
bool FUN_0070ec00();
bool FUN_005d4a40();
unsigned int FUN_00457fe0();
bool FUN_00702450(int iMenuID);
bool FUN_007024e0();
TESForm* LookupFormByID(unsigned int auiFormId);
bool InitTutorialMenu(BGSMessage* pkMessage, int iArg);
void FUN_005b5e40(const char* pcFormat, ...);

static const char s_szTutorialError[] = "Error occurred while trying to display tutorial message";

struct TutorialState
{
    TutorialEntry m_akEntries[41];
    int m_iCurrent;
    unsigned int m_uiDueTime;

    bool SetFlag2(int iIndex);
    void FUN_007182e0();
};

// Checks game and menu conditions, updates the current entry and due time, and invokes the message and entry routines for eligible entries.
// @fnv 0x007182e0
void TutorialState::FUN_007182e0()
{
    if (IsStartMenuFlag1Set() || FUN_0070ec00())
        return;
    bool bRepeat = true;
    while (bRepeat)
    {
        bRepeat = false;
        if (!FUN_005d4a40() || DAT_011d8a80->m_iMode != 2)
        {
            m_uiDueTime = 0;
            m_iCurrent = 41;
        }
        else if (m_uiDueTime && FUN_00457fe0() >= m_uiDueTime && m_iCurrent < 41 &&
                 (!m_akEntries[m_iCurrent].m_uiMenu || FUN_00702450(m_akEntries[m_iCurrent].m_uiMenu + 1001)) &&
                 FUN_007024e0())
        {
            BGSMessage* pkMessage = dynamic_cast<BGSMessage*>(LookupFormByID(m_iCurrent + 0x168));
            if (!pkMessage || !InitTutorialMenu(pkMessage, 0) || !SetFlag2(m_iCurrent))
                FUN_005b5e40(s_szTutorialError);
            m_uiDueTime = 0;
            m_iCurrent = 41;
        }
        else
        {
            for (int i = 0; i < 41; i++)
            {
                if (m_akEntries[i].m_bPending && !m_akEntries[i].m_bShown && m_iCurrent != i &&
                    (!m_akEntries[m_iCurrent].m_uiMenu || FUN_00702450(m_akEntries[i].m_uiMenu + 1001)) &&
                    FUN_007024e0())
                {
                    if (m_iCurrent < 41 &&
                        (!m_akEntries[m_iCurrent].m_uiMenu || FUN_00702450(m_akEntries[m_iCurrent].m_uiMenu + 1001)))
                        m_akEntries[m_iCurrent].m_bPending = 0;
                    m_iCurrent = i;
                    m_uiDueTime = FUN_00457fe0() + m_akEntries[i].m_uiDelay;
                    bRepeat = m_akEntries[i].m_uiDelay == 0;
                }
            }
        }
    }
}

}

namespace TileModelsUpdateDetail {
struct UpdateData
{
    float time;
    bool updateControllers;
    bool parallelUpdate;
    bool foundParticles;
    bool foundMorphController;
    bool sceneGraphChange;
    void FUN_0043d410(float, bool, bool);
};
struct Model
{
    void FUN_00a59c60(const UpdateData&);
};
struct TileView
{
    Model* FUN_0056c7f0();
    void ClearFlag();
};
struct UpdateList
{
    unsigned int FUN_0044ddc0();
    TileView** FUN_00877a30(int);
    void FUN_008454f0(bool);
};
struct ThreadOwner
{
    unsigned int FUN_0044edb0();
};
}

extern "C" unsigned int __cdecl FUN_0040fc90();
struct TileModelsUpdateEntry
{
    void FUN_00713e20();
};

// @fnv 0x00713e20
void TileModelsUpdateEntry::FUN_00713e20()
{
    unsigned int iTileIndex;
    for (iTileIndex = 0; iTileIndex < ((TileModelsUpdateDetail::UpdateList*)&g_011d8b44)->FUN_0044ddc0(); iTileIndex++)
    {
        TileModelsUpdateDetail::TileView* ptile =
            *((TileModelsUpdateDetail::UpdateList*)&g_011d8b44)->FUN_00877a30(iTileIndex);
        TileModelsUpdateDetail::Model* pmodel = ptile ? ptile->FUN_0056c7f0() : 0;
        if (pmodel)
        {
            TileModelsUpdateDetail::UpdateData updateData;
            updateData.FUN_0043d410(0.0f, false, false);
            pmodel->FUN_00a59c60(updateData);
        }
        ptile->ClearFlag();
    }
    if (FUN_0040fc90() == ((TileModelsUpdateDetail::ThreadOwner*)g_osGlobals)->FUN_0044edb0())
        ((TileModelsUpdateDetail::UpdateList*)&g_011d8b44)->FUN_008454f0(true);
}

namespace fnv_00718db0 {
struct SystemColorInfo;
struct FUN_00718db0_shell : public SystemColorManager
{
    void FUN_00718db0(char*, unsigned int, unsigned int, unsigned int, SystemColorInfo*, int);
};

struct SystemColorInfo;

struct GlobalObject2_0040c150
{
    int* Int();
};
void* __cdecl operator new(unsigned int);
unsigned int __cdecl PackRgba(unsigned int, unsigned int, unsigned int, unsigned int);
struct FUN_007192e0
{
    int a, b, c, d;
    FUN_007192e0(char*, SystemColorInfo*, int);
};
struct M788
{
    void FUN_004ed8c0(void*);
};
// When apSetting->Int() is zero, stores FUN_00718e90(...) there; allocates and passes a FUN_007192e0 entry to FUN_004ed8c0, then stores aiID + 1 at offset 0xc.
// @fnv 0x00718db0
void FUN_00718db0_shell::FUN_00718db0(char* apName, unsigned int aiRed, unsigned int aiGreen, unsigned int aiBlue,
                                      SystemColorInfo* apSetting, int aiID)
{
    if (*((GlobalObject2_0040c150*)apSetting)->Int() == 0)
        *((GlobalObject2_0040c150*)apSetting)->Int() = PackRgba(aiRed, aiGreen, aiBlue, 0xff);
    FUN_007192e0* pColor = new FUN_007192e0(apName, apSetting, aiID);
    ((M788*)this)->FUN_004ed8c0(&pColor);
    *(int*)((char*)this + 0xc) = aiID + 1;
}
}  // namespace fnv_00718db0

struct TutorialMessageView718
{
    bool IsFlagSet();
};
extern "C" ::TESForm* __cdecl LookupFormByID(unsigned int);
bool __cdecl FUN_005d4a40();

struct TutorialMessageState718
{
    unsigned int bShown : 1;
    int bSeen : 1;
    unsigned int uiMenuID : 6;
    unsigned int m_uiRemainingBits : 24;
};
struct TutorialMessageGate718
{
    TutorialMessageState718 kMessages[41];
    bool FUN_00718630(int aeID, unsigned int aiMenuID, unsigned int auiShowDelay);
};

// For a valid index, stores the delay and accepted menu ID, then returns whether the form passes the view check, FUN_005d4a40, and unseen check.
// @fnv 0x00718630
bool TutorialMessageGate718::FUN_00718630(int aeID, unsigned int aiMenuID, unsigned int auiShowDelay)
{
    bool bshow = false;
    if (aeID >= 0 && aeID < 41)
    {
        kMessages[aeID].m_uiRemainingBits = auiShowDelay;
        if ((aiMenuID >= 1001 && aiMenuID <= 1084) || aiMenuID == 0)
        {
            if (aiMenuID)
                kMessages[aeID].uiMenuID = aiMenuID - 1001;
            else
                kMessages[aeID].uiMenuID = 0;
            ::BGSMessage* pmsg;
            ::TESForm* pform = LookupFormByID(aeID + 360);
            pmsg = pform ? dynamic_cast< ::BGSMessage*>(pform) : 0;
            bshow = pmsg && ((TutorialMessageView718*)pmsg)->IsFlagSet() && FUN_005d4a40() && !kMessages[aeID].bSeen;
        }
        kMessages[aeID].bShown = bshow;
    }
    return bshow;
}
