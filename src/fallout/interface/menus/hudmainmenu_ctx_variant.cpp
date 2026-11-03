
// hudmainmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/hudmainmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "HUDMainMenu.h"
static const int kGetClassValue = 1004;
// m_pTiles is addressed by 1-based tile ID; slot 0 is the menu root.
enum
{
    kTileIDMax = 86
};

class NiNode;
class NiAVObject;
class NiTimeController;
class NiRTTI;
class NiSourceTexture;
class NiControllerSequence;
class ShadowSceneNode;
struct NiPoint3Stub
{
    float x;
    float y;
    float z;
};
class NiSourceTexture;
class CompassStub
{
  public:
    void FUN_007700b0(NiSourceTexture* texture);
    void FUN_007700d0(bool enable);
};
class MenuStub;
class Tile
{
  public:
    virtual ~Tile();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual CompassStub* vf20();
    void FUN_00700320(int trait, int value);
    void FUN_00a012d0(int trait, float value, bool propagate);
    float FUN_00a011b0(int trait);
    void FUN_00a01350(int trait, const char* text, bool propagate);
    Tile* ReadXML(const char* path);
    MenuStub* FUN_00a03c90();
    NiNode* FUN_0056c7f0();
};
class TileMenu : public Tile
{
};
class MenuStub
{
  public:
    virtual ~MenuStub();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual unsigned int vf34();
    void FUN_00a1dc70(Tile* tile, bool modal);
    Tile* AddTileFromTemplate(Tile* parent, const char* templateName, int unused);
    void FUN_00a1dc20(int value);
    int FUN_00726070();
    bool FUN_00770070();
    NiNode* FUN_0077ee50();
};
class HotKeyWheelStub
{
  public:
    void FUN_00701610(Tile* selector);
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};
class ATMStub
{
  public:
    void FUN_004538a0(int value);
    void FUN_004538c0();
};
class FontManagerStub
{
  public:
    NiPoint3Stub GetStringDimensions(const char* text, int font, float width, int flags);
};
class SettingString
{
  public:
    const char* FUN_00403df0();
};
class SettingInt
{
  public:
    int* FUN_0043d4d0();
};
class SettingFloat
{
  public:
    float* FUN_00403e20();
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char* text);
    ~NiFixedString();
};
class NiTextureFormatPrefs;
class NiSourceTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class ThreeByThreeMatrix
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ThreeByThreeMatrix();
    void FUN_00524ac0(float angle);
    void FUN_004a0c90(float angle);
    ThreeByThreeMatrix FUN_0043f8d0(const ThreeByThreeMatrix& other) const;
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool bUnk06;
    bool bUnk07;
    int unk08;
    NiUpdateData(float time, bool updateControllers, bool multiThreaded);
};
class NiBoundStub
{
  public:
    float FUN_0084d030();
};
class NiNode
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    unsigned int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    unsigned int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    NiNode(unsigned short childCount);
    void IncRefCount();
    void DecRefCount();
    void FUN_0043fa80(const ThreeByThreeMatrix& rotate);
    void FUN_00440490(float scale);
    void FUN_004bc1f0(float x, float y, float z);
    void FUN_00a59c60(NiUpdateData& data);
    NiBoundStub* FUN_0043d450();
    NiNode* FUN_0043b4a0(int index);
    NiTimeController* FUN_00a5c570(NiRTTI* rtti);
    void FUN_006404b0(float angle, float x, float y, float z);
};
class NiControllerManagerStub
{
  public:
    void* FUN_0047a520(const NiFixedString& name);
    void FUN_0048fef0(float time);
    void FUN_0047aab0(void* sequence, int a, int b, float weight, float easeIn, int c);
};
class ShadowSceneNode
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc(NiNode* node, bool flag);
    void FUN_00b5ca70(NiNode* node, float radius);
};
struct HUDEmptyStub
{
};
NiSourceTexture* __cdecl FUN_00a5fd70(const NiFixedString& path, NiTextureFormatPrefs& prefs, bool a, bool b);
ShadowSceneNode* __cdecl FUN_00450b80(int index);
extern NiTextureFormatPrefs DAT_011a9598;
extern NiRTTI DAT_011f36ac;
extern NiPointer<NiNode> DAT_011d9770;
extern NiPointer<NiNode> DAT_011d975c;
extern HUDEmptyStub* DAT_011d96bc;
extern HUDMainMenu* HUDMainMenu_pme;
extern SettingString DAT_011d4da4;
extern SettingString DAT_011d21d8;
extern SettingString DAT_011d2454;
extern SettingString DAT_011d1f68;
extern SettingString DAT_011d4918;
extern SettingString DAT_011d3e8c;
extern SettingString DAT_011d300c;
extern SettingInt DAT_011d32d0;
extern SettingFloat DAT_011d9774;
extern float DAT_011d979c;
InterfaceManager* __cdecl FUN_004b7210();
unsigned int __cdecl FUN_00706f20();
TileMenu* __cdecl FUN_00a09030(unsigned int id);
float __cdecl FUN_00a01530();
ATMStub* __cdecl FUN_00713d70();
float __cdecl FUN_00715d40();
float __cdecl FUN_00715da0();
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();
int __cdecl TraitNameToIDAdd(const char* name, int defaultValue);
Tile* __cdecl FUN_00a08b20(Tile* parent, const char* name);
void __cdecl FUN_00774800(Tile* tile, int style);
int __cdecl TraitNameToID(const char* name);
FontManagerStub* __cdecl FUN_005bd5b0();
void __cdecl FUN_0040fbe0(const char* message);
void __cdecl FUN_007037e0();
void __cdecl FUN_00a04200(bool value);
void __cdecl FUN_0077e430(float value);
void __cdecl UpdateVisibilityState(int value);
static const char kTemplateRightBracket[] = "template_right_bracket";
static const char kTemplateMeter3[] = "template_meter";
static const char kTemplateJustifyRightText6[] = "template_justify_right_text";
static const char kTemplateJustifyRightText5[] = "template_justify_right_text";
static const char kTemplateJustifyRightText4[] = "template_justify_right_text";
static const char kTemplateMeter2[] = "template_meter";
static const char kInterfaceVATSVatsBarDds[] = "Interface\\VATS\\vats_bar.dds";
static const char kTemplateMeterBackground[] = "template_meter_background";
static const char kCNDArrows[] = "CNDArrows";
static const char kHitPoints[] = "HitPoints";
static const char kTemplateLeftBracket[] = "template_left_bracket";
static const char kTemplateMeter[] = "template_meter";
static const char kTemplateJustifyRightText3[] = "template_justify_right_text";
static const char kTemplateCompassWindow[] = "template_compass_window";
static const char kTemplateCompassIconGroup[] = "template_compass_icon_group";
static const char kTemplateCompassIconMarker[] = "template_compass_icon_marker";
static const char kRadiationMeter[] = "RadiationMeter";
static const char kTestHeight2[] = "Test Height";
static const char kTemplateJustifyLeftText3[] = "template_justify_left_text";
static const char kTemplateReticleCenter[] = "template_reticle_center";
static const char kSneakMeter[] = "SneakMeter";
static const char kSneakNif[] = "sneak_nif";
static const char kMessages[] = "Messages";
static const char kTemplateMessageIcon[] = "template_message_icon";
static const char kTemplateJustifyLeftText2[] = "template_justify_left_text";
static const char kTemplateMessageBracket[] = "template_message_bracket";
static const char kJustifyCenterHotrect[] = "justify_center_hotrect";
static const char kPCShortcutLabel[] = "PCShortcutLabel";
static const char kXboxButton[] = "xbox_button";
static const char kTestHeight[] = "Test Height";
static const char kTemplateJustifyCenterText3[] = "template_justify_center_text";
static const char kTemplateJustifyCenterText2[] = "template_justify_center_text";
static const char kTemplateJustifyRightText2[] = "template_justify_right_text";
static const char kTemplateJustifyLeftText[] = "template_justify_left_text";
static const char kTemplateJustifyRightText[] = "template_justify_right_text";
static const char kTemplateJustifyCenterText[] = "template_justify_center_text";
static const char kHokeys[] = "Hokeys";
// @fnv 0x0076bfe0
Tile* FUN_0076bfe0()
{
    InterfaceManager* pInterfaceMgrY;
    MenuStub* pMenuXB;
    float fTileAlphaM;
    Tile* pMenuTileN;
    TileMenu* pOldMenuT;

    if (!FUN_004b7210())
        return 0;
    pOldMenuT = FUN_00a09030(FUN_00706f20());
    if (pOldMenuT)
        delete pOldMenuT;
    pInterfaceMgrY = FUN_004b7210();
    fTileAlphaM = FUN_00a01530();
    FUN_00713d70()->FUN_004538a0(0);
    pMenuTileN = pInterfaceMgrY->FUN_00586150()->ReadXML("Data\\Menus\\Main\\hud_main_menu.xml");
    pMenuXB = pMenuTileN->FUN_00a03c90();
    if (pMenuXB && pMenuXB->vf34() == FUN_00706f20())
    {
        pMenuXB->FUN_00a1dc70(pMenuTileN, false);
        int iInfoRowY;
        int iTotalWidthTraitA;
        int iInfoGapLeftAA;
        NiNode* pBreathNodeYA;
        int iOriginalXTrait14;
        float fLimbScaleAC;
        int iSafeZoneX3;
        int iInfoPadLeft_;
        float fShadowRadiusXB;
        Tile* pPlayerIcon;
        int iScreenHeightX;
        int iImageWidthTraitT;
        int iInfoPadMid34;
        NiTimeController* pController27;
        int iScreenWidthC;
        int iSafeZoneYY;
        int iQuestYAA;
        int iMessageOffsetX3;
        int iLimbOffsetXQ;
        int iLimbOffsetYB;
        int iInfoPadRightQ;
        HUDMainMenu_pme = (HUDMainMenu*)pMenuXB;
        iScreenWidthC = (int)FUN_00715d40();
        iScreenHeightX = (int)FUN_00715da0();
        iSafeZoneX3 = (int)FUN_007177c0();
        iSafeZoneYY = (int)FUN_00717820();
        iOriginalXTrait14 = TraitNameToIDAdd("_OriginalX", -1);
        iTotalWidthTraitA = TraitNameToIDAdd("_TotalWidth", -1);
        iImageWidthTraitT = TraitNameToIDAdd("_ImageWidth", -1);
        HUDMainMenu_pme->m_pTiles[59] = FUN_00a08b20(FUN_00a09030(1004), "ActionPoints");
        HUDMainMenu_pme->m_pTiles[59]->FUN_00a012d0(
            4001, (float)(iScreenWidthC - iSafeZoneX3 * 2) - HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4017) + 30.0,
            1);
        HUDMainMenu_pme->m_pTiles[59]->FUN_00a012d0(
            4002, (float)(iScreenHeightX - iSafeZoneYY * 2) - HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4016), 1);
        HUDMainMenu_pme->m_pTiles[59]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[43] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateRightBracket, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[43], 2);
        HUDMainMenu_pme->m_pTiles[43]->FUN_00700320(4001, -37);
        HUDMainMenu_pme->m_pTiles[7] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateMeter3, 0);
        HUDMainMenu_pme->m_pTiles[7]->FUN_00700320(iOriginalXTrait14, 326);
        HUDMainMenu_pme->m_pTiles[7]->FUN_00a012d0(4002, 41.0f, 1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[7], 3);
        HUDMainMenu_pme->m_pTiles[8] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateJustifyRightText6, 0);
        HUDMainMenu_pme->m_pTiles[8]->FUN_00700320(4001, 315);
        HUDMainMenu_pme->m_pTiles[8]->FUN_00700320(4002, 8);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[8], 0);
        HUDMainMenu_pme->m_pTiles[12] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateJustifyRightText5, 0);
        HUDMainMenu_pme->m_pTiles[12]->FUN_00700320(4001, 315);
        HUDMainMenu_pme->m_pTiles[12]->FUN_00700320(4002, 80);
        HUDMainMenu_pme->m_pTiles[12]->FUN_00700320(4025, 7);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[12], 0);
        HUDMainMenu_pme->m_pTiles[9] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateJustifyRightText4, 0);
        HUDMainMenu_pme->m_pTiles[9]->FUN_00700320(4001, 80);
        HUDMainMenu_pme->m_pTiles[9]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[12]->FUN_00a011b0(4002), 1);
        HUDMainMenu_pme->m_pTiles[9]->FUN_00700320(4025, 7);
        HUDMainMenu_pme->m_pTiles[9]->FUN_00a01350(4036, DAT_011d4da4.FUN_00403df0(), 1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[9], 0);
        HUDMainMenu_pme->m_pTiles[10] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateMeter2, 0);
        HUDMainMenu_pme->m_pTiles[10]->FUN_00700320(iOriginalXTrait14, 90);
        HUDMainMenu_pme->m_pTiles[10]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[12]->FUN_00a011b0(4002) + 3.0, 1);
        HUDMainMenu_pme->m_pTiles[10]->FUN_00a01350(4044, kInterfaceVATSVatsBarDds, 1);
        HUDMainMenu_pme->m_pTiles[10]->FUN_00700320(iTotalWidthTraitA, 60);
        HUDMainMenu_pme->m_pTiles[10]->FUN_00700320(iImageWidthTraitT, 1);
        HUDMainMenu_pme->m_pTiles[10]->FUN_00700320(4024, 200);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[10], 3);
        HUDMainMenu_pme->m_pTiles[11] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[59], kTemplateMeterBackground, 0);
        HUDMainMenu_pme->m_pTiles[11]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[12]->FUN_00a011b0(4002) + 3.0, 1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[11], 4);
        HUDMainMenu_pme->m_pTiles[86] = FUN_00a08b20(FUN_00a09030(1004), kCNDArrows);
        HUDMainMenu_pme->m_pTiles[86]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[9]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[10]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[11]->FUN_00a011b0(4017) * 0.75 + 8.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[86]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4002) + HUDMainMenu_pme->m_pTiles[10]->FUN_00a011b0(4002),
            1);
        HUDMainMenu_pme->m_pTiles[86]->FUN_00a012d0(4016, HUDMainMenu_pme->m_pTiles[11]->FUN_00a011b0(4016), 1);
        HUDMainMenu_pme->m_pTiles[86]->FUN_00700320(4003, 0);
        HUDMainMenu_pme->m_pTiles[60] = FUN_00a08b20(FUN_00a09030(1004), kHitPoints);
        HUDMainMenu_pme->m_pTiles[60]->FUN_00700320(4001, iSafeZoneX3 * 2 + 10);
        HUDMainMenu_pme->m_pTiles[60]->FUN_00a012d0(
            4002, (float)(iScreenHeightX - iSafeZoneYY * 2) - HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4016), 1);
        HUDMainMenu_pme->m_pTiles[60]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[42] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[60], kTemplateLeftBracket, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[42], 2);
        HUDMainMenu_pme->m_pTiles[1] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[60], kTemplateMeter, 0);
        HUDMainMenu_pme->m_pTiles[1]->FUN_00700320(iOriginalXTrait14, 20);
        HUDMainMenu_pme->m_pTiles[1]->FUN_00a012d0(4002, 41.0f, 1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[1], 3);
        HUDMainMenu_pme->m_pTiles[2] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[60], kTemplateJustifyRightText3, 0);
        HUDMainMenu_pme->m_pTiles[2]->FUN_00700320(4001, 53);
        HUDMainMenu_pme->m_pTiles[2]->FUN_00700320(4002, 8);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[2], 0);
        HUDMainMenu_pme->m_pTiles[6] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[60], kTemplateCompassWindow, 0);
        HUDMainMenu_pme->m_pTiles[3] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[6], kTemplateCompassIconGroup, 0);
        HUDMainMenu_pme->m_pTiles[3]->FUN_00700320(4002, 30);
        HUDMainMenu_pme->m_pTiles[3]->FUN_00700320(4013, 4);
        HUDMainMenu_pme->m_pTiles[4] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[6], "template_compass_icon_group", 0);
        HUDMainMenu_pme->m_pTiles[4]->FUN_00700320(4002, 30);
        HUDMainMenu_pme->m_pTiles[4]->FUN_00700320(4013, 3);
        HUDMainMenu_pme->m_pTiles[5] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[6], "template_compass_icon_group", 0);
        HUDMainMenu_pme->m_pTiles[5]->FUN_00700320(4002, 10);
        HUDMainMenu_pme->m_pTiles[5]->FUN_00700320(4013, 2);
        for (int l_e8 = 0; l_e8 < *DAT_011d32d0.FUN_0043d4d0(); l_e8++)
        {
            Tile* l_ec =
                ((MenuStub*)HUDMainMenu_pme)->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[5], "compass_npc_icon", 0);
        }
        for (int l_f0 = 0; l_f0 < 10; l_f0++)
        {
            Tile* l_f4 = ((MenuStub*)HUDMainMenu_pme)
                             ->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[4], "template_compass_icon_quest", 0);
        }
        pPlayerIcon =
            ((MenuStub*)HUDMainMenu_pme)->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[4], "template_compass_icon_player", 0);
        for (int l_f8 = 0; l_f8 < 10; l_f8++)
        {
            Tile* l_fc =
                ((MenuStub*)HUDMainMenu_pme)->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[3], kTemplateCompassIconMarker, 0);
        }
        HUDMainMenu_pme->m_pTiles[61] = FUN_00a08b20(FUN_00a09030(1004), kRadiationMeter);
        HUDMainMenu_pme->m_pTiles[61]->FUN_00a012d0(
            4001, (float)(iScreenWidthC - iSafeZoneX3 * 2) - HUDMainMenu_pme->m_pTiles[61]->FUN_00a011b0(4017) - 20.0,
            1);
        HUDMainMenu_pme->m_pTiles[61]->FUN_00700320(4002, iSafeZoneYY * 2);
        HUDMainMenu_pme->m_pTiles[17] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[61], "radiation_bracket");
        HUDMainMenu_pme->m_pTiles[18] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[61], "radiation_pointer");
        HUDMainMenu_pme->m_pTiles[20] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[61], "radiation_text");
        HUDMainMenu_pme->m_pTiles[19] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[61], "radiation_text_value");
        HUDMainMenu_pme->m_pTiles[19]->FUN_00a01350(4036, "+0", 1);
        HUDMainMenu_pme->m_pTiles[20]->FUN_00a01350(4036, DAT_011d21d8.FUN_00403df0(), 1);
        HUDMainMenu_pme->m_pTiles[62] = FUN_00a08b20(FUN_00a09030(1004), "EnemyHealth");
        HUDMainMenu_pme->m_pTiles[62]->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - HUDMainMenu_pme->m_pTiles[62]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[62]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4002) + 40.0, 1);
        HUDMainMenu_pme->m_pTiles[62]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[62]->FUN_00700320(4084, 2);
        HUDMainMenu_pme->m_pTiles[21] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[62], "template_enemy_health_bracket", 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[21], 1);
        HUDMainMenu_pme->m_pTiles[21]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[22] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[62], "template_meter", 0);
        HUDMainMenu_pme->m_pTiles[22]->FUN_00700320(iOriginalXTrait14, 171);
        HUDMainMenu_pme->m_pTiles[22]->FUN_00700320(iTotalWidthTraitA, 240);
        HUDMainMenu_pme->m_pTiles[22]->FUN_00700320(4002, 3);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[22], 3);
        HUDMainMenu_pme->m_pTiles[22]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[23] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[62], "template_justify_center_text", 0);
        HUDMainMenu_pme->m_pTiles[23]->FUN_00700320(4001, 170);
        HUDMainMenu_pme->m_pTiles[23]->FUN_00700320(4002, 35);
        HUDMainMenu_pme->m_pTiles[23]->FUN_00700320(4026, 350);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[23], 0);
        iQuestYAA = iSafeZoneYY * 2 + 170;
        HUDMainMenu_pme->m_pTiles[63] = FUN_00a08b20(FUN_00a09030(1004), "QuestReminder");
        HUDMainMenu_pme->m_pTiles[63]->FUN_00700320(4001, iSafeZoneX3 * 2 + 15);
        HUDMainMenu_pme->m_pTiles[63]->FUN_00700320(4002, iQuestYAA);
        HUDMainMenu_pme->m_pTiles[13] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[63], "QuestStages");
        HUDMainMenu_pme->m_pTiles[14] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[63], "QuestAdded");
        for (int l_100 = 0; l_100 < 64; l_100++)
        {
            ((MenuStub*)HUDMainMenu_pme)->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[14], "template_justify_left_text", 0);
        }
        for (int l_104 = 0; l_104 < 32; l_104++)
        {
            ((MenuStub*)HUDMainMenu_pme)->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[13], "template_filled_checkbox", 0);
        }
        for (int l_108 = 0; l_108 < 32; l_108++)
        {
            ((MenuStub*)HUDMainMenu_pme)->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[13], "template_justify_left_text", 0);
        }
        HUDMainMenu_pme->m_pTiles[64] = FUN_00a08b20(FUN_00a09030(1004), "Region_Location");
        HUDMainMenu_pme->m_pTiles[64]->FUN_00700320(4001, iSafeZoneX3 * 2 + 15);
        HUDMainMenu_pme->m_pTiles[64]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4002) - 75.0, 1);
        HUDMainMenu_pme->m_pTiles[15] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[64], "template_justify_left_text", 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[15], 0);
        HUDMainMenu_pme->m_pTiles[15]->FUN_00700320(4003, 1);
        NiPoint3Stub kTextSize1 =
            FUN_005bd5b0()->GetStringDimensions(kTestHeight2, (int)HUDMainMenu_pme->m_pTiles[15]->FUN_00a011b0(4025),
                                         HUDMainMenu_pme->m_pTiles[15]->FUN_00a011b0(4026), 0);
        HUDMainMenu_pme->m_pTiles[15]->FUN_00a012d0(4002, kTextSize1.y, 1);
        HUDMainMenu_pme->m_pTiles[16] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[64], kTemplateJustifyLeftText3, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[16], 0);
        HUDMainMenu_pme->m_pTiles[16]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[16]->FUN_00a012d0(4002, kTextSize1.y, 1);
        HUDMainMenu_pme->m_pTiles[65] = FUN_00a08b20(FUN_00a09030(1004), "ReticleCenter");
        HUDMainMenu_pme->m_pTiles[65]->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - HUDMainMenu_pme->m_pTiles[65]->FUN_00a011b0(4017) / 2.0 - 3.0, 1);
        HUDMainMenu_pme->m_pTiles[65]->FUN_00a012d0(
            4002, (float)(iScreenHeightX / 2) - HUDMainMenu_pme->m_pTiles[65]->FUN_00a011b0(4016) / 2.0 - 3.0, 1);
        HUDMainMenu_pme->m_pTiles[65]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[65]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[51] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[65], kTemplateReticleCenter, 0);
        HUDMainMenu_pme->m_pTiles[51]->FUN_00700320(4084, 1);
        HUDMainMenu_pme->m_pTiles[51]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[66] = FUN_00a08b20(FUN_00a09030(1004), kSneakMeter);
        HUDMainMenu_pme->m_pTiles[66]->FUN_00700320(4001, iScreenWidthC / 2);
        HUDMainMenu_pme->m_pTiles[66]->FUN_00700320(4002, iSafeZoneYY * 2);
        HUDMainMenu_pme->m_pTiles[66]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[66]->FUN_00700320(4003, 0);
        HUDMainMenu_pme->m_pTiles[24] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[66], kSneakNif);
        HUDMainMenu_pme->m_pTiles[24]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[67] = FUN_00a08b20(FUN_00a09030(1004), kMessages);
        iMessageOffsetX3 = -5;
        HUDMainMenu_pme->m_pTiles[67]->FUN_00700320(4001, iMessageOffsetX3 + iSafeZoneX3 * 2);
        HUDMainMenu_pme->m_pTiles[67]->FUN_00700320(4002, iSafeZoneYY * 2 + 25);
        HUDMainMenu_pme->m_pTiles[67]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[25] = pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[67], kTemplateMessageIcon, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[25], 6);
        HUDMainMenu_pme->m_pTiles[26] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[67], kTemplateJustifyLeftText2, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[26], 0);
        HUDMainMenu_pme->m_pTiles[26]->FUN_00700320(4001, 130);
        HUDMainMenu_pme->m_pTiles[26]->FUN_00700320(4002, 5);
        HUDMainMenu_pme->m_pTiles[26]->FUN_00700320(4026, 320);
        HUDMainMenu_pme->m_pTiles[26]->FUN_00700320(4013, 2);
        HUDMainMenu_pme->m_pTiles[26]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[26]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[27] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[67], kTemplateMessageBracket, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[27], 1);
        HUDMainMenu_pme->m_pTiles[68] = FUN_00a08b20(FUN_00a09030(1004), "Info");
        HUDMainMenu_pme->m_pTiles[68]->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[68]->FUN_00a012d0(
            4002, (float)(iScreenHeightX - iSafeZoneYY * 2) - HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4016) - 30.0,
            1);
        HUDMainMenu_pme->m_pTiles[68]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[29] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[68], kJustifyCenterHotrect);
        HUDMainMenu_pme->m_pTiles[30] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[29], kPCShortcutLabel);
        HUDMainMenu_pme->m_pTiles[31] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[29], kXboxButton);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[29], 0);
        HUDMainMenu_pme->m_pTiles[29]->FUN_00a012d0(TraitNameToID("_x"),
                                                    HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[32] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], "template_justify_center_text", 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[32], 0);
        HUDMainMenu_pme->m_pTiles[32]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[32]->FUN_00a012d0(4026, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017), 1);
        HUDMainMenu_pme->m_pTiles[32]->FUN_00700320(4002, 0);
        kTextSize1 = FUN_005bd5b0()->GetStringDimensions(kTestHeight, (int)HUDMainMenu_pme->m_pTiles[32]->FUN_00a011b0(4025),
                                                  HUDMainMenu_pme->m_pTiles[32]->FUN_00a011b0(4026), 0);
        HUDMainMenu_pme->m_pTiles[32]->FUN_00a012d0(4108, kTextSize1.y, 1);
        HUDMainMenu_pme->m_pTiles[33] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], kTemplateJustifyCenterText3, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[33], 0);
        HUDMainMenu_pme->m_pTiles[33]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[33]->FUN_00a012d0(4026, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017), 1);
        HUDMainMenu_pme->m_pTiles[33]->FUN_00700320(4002, 65);
        HUDMainMenu_pme->m_pTiles[33]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[33]->FUN_00a01350(4036, DAT_011d2454.FUN_00403df0(), 1);
        HUDMainMenu_pme->m_pTiles[33]->FUN_00700320(4003, 0);
        HUDMainMenu_pme->m_pTiles[34] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], kTemplateJustifyCenterText2, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[34], 0);
        HUDMainMenu_pme->m_pTiles[34]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[34]->FUN_00a012d0(4026, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017), 1);
        HUDMainMenu_pme->m_pTiles[34]->FUN_00700320(4002, 65);
        HUDMainMenu_pme->m_pTiles[34]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[34]->FUN_00a01350(4036, DAT_011d1f68.FUN_00403df0(), 1);
        HUDMainMenu_pme->m_pTiles[34]->FUN_00700320(4003, 0);
        iInfoRowY = 60;
        iInfoGapLeftAA = 25;
        iInfoPadLeft_ = 10;
        iInfoPadRightQ = 30;
        iInfoPadMid34 = 5;
        HUDMainMenu_pme->m_pTiles[35] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], kTemplateJustifyRightText2, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[35], 0);
        HUDMainMenu_pme->m_pTiles[35]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0 - iInfoGapLeftAA, 1);
        HUDMainMenu_pme->m_pTiles[35]->FUN_00700320(4002, iInfoRowY);
        HUDMainMenu_pme->m_pTiles[35]->FUN_00a012d0(4009, DAT_011d979c, 1);
        HUDMainMenu_pme->m_pTiles[36] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], kTemplateJustifyLeftText, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[36], 0);
        HUDMainMenu_pme->m_pTiles[36]->FUN_00700320(4001, iInfoPadLeft_);
        HUDMainMenu_pme->m_pTiles[36]->FUN_00700320(4002, iInfoRowY);
        HUDMainMenu_pme->m_pTiles[37] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], kTemplateJustifyRightText, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[37], 0);
        HUDMainMenu_pme->m_pTiles[37]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) - iInfoPadRightQ, 1);
        HUDMainMenu_pme->m_pTiles[37]->FUN_00700320(4002, iInfoRowY);
        HUDMainMenu_pme->m_pTiles[37]->FUN_00a012d0(4009, DAT_011d979c, 1);
        HUDMainMenu_pme->m_pTiles[38] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], "template_justify_left_text", 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[38], 0);
        HUDMainMenu_pme->m_pTiles[38]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4017) / 2.0 + iInfoPadMid34, 1);
        HUDMainMenu_pme->m_pTiles[38]->FUN_00700320(4002, iInfoRowY);
        HUDMainMenu_pme->m_pTiles[39] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[68], "template_info_seperator", 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[39], 2);
        HUDMainMenu_pme->m_pTiles[69] = FUN_00a08b20(FUN_00a09030(1004), "Subtitles");
        HUDMainMenu_pme->m_pTiles[69]->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - HUDMainMenu_pme->m_pTiles[69]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[69]->FUN_00a012d0(4002,
                                                    HUDMainMenu_pme->m_pTiles[68]->FUN_00a011b0(4002) -
                                                        HUDMainMenu_pme->m_pTiles[69]->FUN_00a011b0(4016) - 50.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[69]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[28] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[69], kTemplateJustifyCenterText, 0);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[28], 0);
        HUDMainMenu_pme->m_pTiles[28]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[69]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[28]->FUN_00a012d0(4026, HUDMainMenu_pme->m_pTiles[69]->FUN_00a011b0(4017), 1);
        HUDMainMenu_pme->m_pTiles[70] = FUN_00a08b20(FUN_00a09030(1004), kHokeys);
        HUDMainMenu_pme->m_pTiles[70]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4001) + 15.0, 1);
        HUDMainMenu_pme->m_pTiles[70]->FUN_00a012d0(4002,
                                                    (float)(iScreenHeightX - iSafeZoneYY * 2) -
                                                        HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4016) -
                                                        HUDMainMenu_pme->m_pTiles[70]->FUN_00a011b0(4016) - 20.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[70]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[40] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[70], "template_hotkey_selector", 0);
        ((HotKeyWheelStub*)HUDMainMenu_pme->m_kMenuData)->FUN_00701610(HUDMainMenu_pme->m_pTiles[40]);
        HUDMainMenu_pme->m_pTiles[41] =
            pMenuXB->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[70], "template_justify_center_text", 0);
        HUDMainMenu_pme->m_pTiles[41]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[70]->FUN_00a011b0(4017) / 2.0, 1);
        HUDMainMenu_pme->m_pTiles[41]->FUN_00700320(4002, -50);
        HUDMainMenu_pme->m_pTiles[41]->FUN_00700320(4003, 0);
        HUDMainMenu_pme->m_pTiles[71] = FUN_00a08b20(FUN_00a09030(1004), "XPMeter");
        HUDMainMenu_pme->m_pTiles[71]->FUN_00700320(4001, iScreenWidthC - iSafeZoneX3 * 2 - 390);
        HUDMainMenu_pme->m_pTiles[71]->FUN_00700320(4002, iScreenHeightX - iSafeZoneYY * 2 - 280);
        HUDMainMenu_pme->m_pTiles[71]->FUN_00700320(4103, iScreenHeightX - iSafeZoneYY * 2 - 280);
        HUDMainMenu_pme->m_pTiles[45] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPAmount");
        HUDMainMenu_pme->m_pTiles[46] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPLabel");
        HUDMainMenu_pme->m_pTiles[47] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPPointer");
        HUDMainMenu_pme->m_pTiles[44] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPBracket");
        HUDMainMenu_pme->m_pTiles[48] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPLastLevel");
        HUDMainMenu_pme->m_pTiles[49] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPNextLevel");
        HUDMainMenu_pme->m_pTiles[50] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[71], "XPLevelUp");
        HUDMainMenu_pme->m_pTiles[72] = FUN_00a08b20(FUN_00a09030(1004), "BreathMeter");
        HUDMainMenu_pme->m_pTiles[72]->FUN_00700320(4001, iScreenWidthC / 2);
        HUDMainMenu_pme->m_pTiles[72]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[66]->FUN_00a011b0(4002) + 80.0, 1);
        HUDMainMenu_pme->m_pTiles[73] = FUN_00a08b20(FUN_00a09030(1004), "Explosive_positioning_rect");
        HUDMainMenu_pme->m_pTiles[73]->FUN_00700320(4001, iScreenWidthC / 2);
        HUDMainMenu_pme->m_pTiles[73]->FUN_00700320(4002, iScreenHeightX / 2);
        for (int l_10c = 0; l_10c < 6; l_10c++)
        {
            Tile* l_110 = ((MenuStub*)HUDMainMenu_pme)
                              ->AddTileFromTemplate(HUDMainMenu_pme->m_pTiles[73], "template_explosive_indicator", 0);
        }
        HUDMainMenu_pme->m_pTiles[74] = FUN_00a08b20(FUN_00a09030(1004), "crippled_limb_indicator");
        iLimbOffsetXQ = 200;
        iLimbOffsetYB = 100;
        fLimbScaleAC = 75.0f;
        HUDMainMenu_pme->m_pTiles[74]->FUN_00700320(4001, iScreenWidthC - iSafeZoneX3 * 2 - iLimbOffsetXQ);
        HUDMainMenu_pme->m_pTiles[74]->FUN_00700320(4002, iLimbOffsetYB + iSafeZoneYY * 2);
        HUDMainMenu_pme->m_pTiles[53] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Head");
        HUDMainMenu_pme->m_pTiles[53]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[53]->FUN_00a012d0(4017, fLimbScaleAC * 85.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[53]->FUN_00a012d0(4016, fLimbScaleAC * 92.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[53]->FUN_00700320(4001, 0);
        HUDMainMenu_pme->m_pTiles[53]->FUN_00700320(4002, 40);
        HUDMainMenu_pme->m_pTiles[52] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Face");
        HUDMainMenu_pme->m_pTiles[52]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[52]->FUN_00a012d0(4017, fLimbScaleAC * 48.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[52]->FUN_00a012d0(4016, fLimbScaleAC * 64.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[52]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[53]->FUN_00a011b0(4001) +
                                                        (HUDMainMenu_pme->m_pTiles[53]->FUN_00a011b0(4017) -
                                                         HUDMainMenu_pme->m_pTiles[52]->FUN_00a011b0(4017)) /
                                                            2.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[52]->FUN_00a012d0(4002,
                                                    HUDMainMenu_pme->m_pTiles[53]->FUN_00a011b0(4002) +
                                                        (HUDMainMenu_pme->m_pTiles[53]->FUN_00a011b0(4016) -
                                                         HUDMainMenu_pme->m_pTiles[52]->FUN_00a011b0(4016)) /
                                                            2.0 +
                                                        fLimbScaleAC * 16.0 / 100.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[54] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Torso");
        HUDMainMenu_pme->m_pTiles[54]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[54]->FUN_00a012d0(4017, fLimbScaleAC * 102.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[54]->FUN_00a012d0(4016, fLimbScaleAC * 128.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[54]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[53]->FUN_00a011b0(4001) + fLimbScaleAC * -14.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[54]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[53]->FUN_00a011b0(4002) + fLimbScaleAC * 86.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[55] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Left_Arm");
        HUDMainMenu_pme->m_pTiles[55]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[55]->FUN_00a012d0(4017, fLimbScaleAC * 100.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[55]->FUN_00a012d0(4016, fLimbScaleAC * 52.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[55]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4001) + fLimbScaleAC * 90.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[55]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4002), 1);
        HUDMainMenu_pme->m_pTiles[56] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Right_Arm");
        HUDMainMenu_pme->m_pTiles[56]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[56]->FUN_00a012d0(4017, fLimbScaleAC * 96.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[56]->FUN_00a012d0(4016, fLimbScaleAC * 54.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[56]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4001) + fLimbScaleAC * -88.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[56]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4002) + fLimbScaleAC * -5.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[57] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Left_Leg");
        HUDMainMenu_pme->m_pTiles[57]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[57]->FUN_00a012d0(4017, fLimbScaleAC * 72.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[57]->FUN_00a012d0(4016, fLimbScaleAC * 112.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[57]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4001) + fLimbScaleAC * 47.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[57]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4002) + fLimbScaleAC * 86.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[58] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[74], "Right_Leg");
        HUDMainMenu_pme->m_pTiles[58]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[58]->FUN_00a012d0(4017, fLimbScaleAC * 84.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[58]->FUN_00a012d0(4016, fLimbScaleAC * 112.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[58]->FUN_00a012d0(
            4001, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4001) + fLimbScaleAC * -37.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[58]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[54]->FUN_00a011b0(4002) + fLimbScaleAC * 83.0 / 100.0, 1);
        HUDMainMenu_pme->m_pTiles[75] = FUN_00a08b20(FUN_00a09030(1004), "DDTIcon");
        HUDMainMenu_pme->m_pTiles[75]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4017) + 5.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[75]->FUN_00a012d0(4002,
                                                    HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4002) +
                                                        HUDMainMenu_pme->m_pTiles[6]->FUN_00a011b0(4002) - 16.0,
                                                    1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[75], 0);
        HUDMainMenu_pme->m_pTiles[75]->FUN_00700320(4003, 0);
        HUDMainMenu_pme->m_pTiles[76] = FUN_00a08b20(FUN_00a09030(1004), "DDTIconEnemy");
        HUDMainMenu_pme->m_pTiles[76]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[62]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[22]->FUN_00a011b0(4001) - 32.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[76]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[62]->FUN_00a011b0(4002) + HUDMainMenu_pme->m_pTiles[22]->FUN_00a011b0(4002),
            1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[76], 0);
        HUDMainMenu_pme->m_pTiles[76]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[76]->FUN_00700320(4084, 2);
        HUDMainMenu_pme->m_pTiles[82] = FUN_00a08b20(FUN_00a09030(1004), "DDTIcon");
        HUDMainMenu_pme->m_pTiles[82]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4017) + 5.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[82]->FUN_00a012d0(4002,
                                                    HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4002) +
                                                        HUDMainMenu_pme->m_pTiles[6]->FUN_00a011b0(4002) - 16.0,
                                                    1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[82], 0);
        HUDMainMenu_pme->m_pTiles[82]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[83] = FUN_00a08b20(FUN_00a09030(1004), "DDTIconEnemyAP");
        HUDMainMenu_pme->m_pTiles[83]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[62]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[22]->FUN_00a011b0(4001) - 32.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[83]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[62]->FUN_00a011b0(4002) + HUDMainMenu_pme->m_pTiles[22]->FUN_00a011b0(4002),
            1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[83], 0);
        HUDMainMenu_pme->m_pTiles[83]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[83]->FUN_00700320(4084, 2);
        HUDMainMenu_pme->m_pTiles[77] = FUN_00a08b20(FUN_00a09030(1004), "AmmoTypeLabel");
        HUDMainMenu_pme->m_pTiles[77]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4001) +
                                                        HUDMainMenu_pme->m_pTiles[12]->FUN_00a011b0(4001) - 165.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[77]->FUN_00a012d0(
            4002, HUDMainMenu_pme->m_pTiles[59]->FUN_00a011b0(4002) + HUDMainMenu_pme->m_pTiles[12]->FUN_00a011b0(4002),
            1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[77], 0);
        HUDMainMenu_pme->m_pTiles[77]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[78] = FUN_00a08b20(FUN_00a09030(1004), "HardcoreMode");
        HUDMainMenu_pme->m_pTiles[78]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4001) + 150.0, 1);
        HUDMainMenu_pme->m_pTiles[78]->FUN_00a012d0(4002, HUDMainMenu_pme->m_pTiles[60]->FUN_00a011b0(4002), 1);
        FUN_00774800(HUDMainMenu_pme->m_pTiles[78], 0);
        HUDMainMenu_pme->m_pTiles[78]->FUN_00700320(4003, 1);
        HUDMainMenu_pme->m_pTiles[78]->FUN_00700320(4008, 1);
        HUDMainMenu_pme->m_pTiles[79] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[78], "Dehydration");
        HUDMainMenu_pme->m_pTiles[79]->FUN_00700320(4001, 0);
        HUDMainMenu_pme->m_pTiles[79]->FUN_00700320(4002, 0);
        HUDMainMenu_pme->m_pTiles[79]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[79]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[81] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[78], "Hunger");
        HUDMainMenu_pme->m_pTiles[81]->FUN_00a012d0(4001, HUDMainMenu_pme->m_pTiles[79]->FUN_00a011b0(4017) + 10.0, 1);
        HUDMainMenu_pme->m_pTiles[81]->FUN_00700320(4002, 0);
        HUDMainMenu_pme->m_pTiles[81]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[81]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[80] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[78], "Sleep");
        HUDMainMenu_pme->m_pTiles[80]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[81]->FUN_00a011b0(4017) + 10.0 +
                                                        HUDMainMenu_pme->m_pTiles[79]->FUN_00a011b0(4017) + 10.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[80]->FUN_00700320(4002, 0);
        HUDMainMenu_pme->m_pTiles[80]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[80]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[84] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[78], "Rads");
        HUDMainMenu_pme->m_pTiles[84]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[81]->FUN_00a011b0(4017) + 10.0 +
                                                        HUDMainMenu_pme->m_pTiles[79]->FUN_00a011b0(4017) + 10.0 +
                                                        HUDMainMenu_pme->m_pTiles[80]->FUN_00a011b0(4017) + 10.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[84]->FUN_00700320(4002, 0);
        HUDMainMenu_pme->m_pTiles[84]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[84]->FUN_00700320(4009, 0);
        HUDMainMenu_pme->m_pTiles[85] = FUN_00a08b20(HUDMainMenu_pme->m_pTiles[78], "LMBs");
        HUDMainMenu_pme->m_pTiles[85]->FUN_00a012d0(4001,
                                                    HUDMainMenu_pme->m_pTiles[81]->FUN_00a011b0(4017) + 10.0 +
                                                        HUDMainMenu_pme->m_pTiles[79]->FUN_00a011b0(4017) + 10.0 +
                                                        HUDMainMenu_pme->m_pTiles[80]->FUN_00a011b0(4017) + 10.0 +
                                                        HUDMainMenu_pme->m_pTiles[84]->FUN_00a011b0(4017) + 10.0,
                                                    1);
        HUDMainMenu_pme->m_pTiles[85]->FUN_00700320(4002, 0);
        HUDMainMenu_pme->m_pTiles[85]->FUN_00a012d0(4024, fLimbScaleAC, 1);
        HUDMainMenu_pme->m_pTiles[85]->FUN_00700320(4009, 0);
        if (!((MenuStub*)HUDMainMenu_pme)->FUN_00770070())
        {
            FUN_0040fbe0(
                "Hud Menu Creation Failed... This likely means that the archives were not built and the xml doesn't match the code.");
            FUN_007037e0();
        }
        if (pMenuTileN->FUN_00a011b0(4007) == 6006.0 || pMenuTileN->FUN_00a011b0(4007) == 102.0)
            pMenuTileN->FUN_00a012d0(4013, fTileAlphaM, true);
        HUDMainMenu_pme->m_pTiles[12]->FUN_00a01350(4036, DAT_011d4918.FUN_00403df0(), 1);
        HUDMainMenu_pme->m_pTiles[8]->FUN_00a01350(4036, DAT_011d3e8c.FUN_00403df0(), 1);
        HUDMainMenu_pme->m_pTiles[2]->FUN_00a01350(4036, DAT_011d300c.FUN_00403df0(), 1);
        HUDMainMenu_pme->m_iHudValueFirstAfterUpdateList = 856;
        HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList =
            (int)(HUDMainMenu_pme->m_pTiles[6]->FUN_00a011b0(4017) / 2.0) - 35;
        HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList = 70;
        pMenuTileN->FUN_00700320(4003, 1);
        ((MenuStub*)HUDMainMenu_pme)->FUN_00726070();
        FUN_00a04200(false);
        NiPointer<NiSourceTexture> spCompassAlphaB(0);
        spCompassAlphaB = FUN_00a5fd70(NiFixedString("Textures\\Interface\\HUD\\hud_compass_alphamap.dds"),
                                       DAT_011a9598, true, false);
        HUDMainMenu_pme->m_pTiles[6]->vf20()->FUN_007700b0(spCompassAlphaB);
        HUDMainMenu_pme->m_pTiles[6]->vf20()->FUN_007700d0(true);
        DAT_011d9770 = new NiNode(0);
        ThreeByThreeMatrix kRotZXB;
        ThreeByThreeMatrix kRotXYB;
        kRotZXB.FUN_00524ac0(1.5707964f);
        kRotXYB.FUN_004a0c90(1.5707964f);
        DAT_011d9770->FUN_0043fa80(kRotZXB.FUN_0043f8d0(kRotXYB));
        DAT_011d9770->FUN_00440490(0.1f);
        DAT_011d9770->FUN_004bc1f0(380.0f, 0.0f, 0.0f);
        NiUpdateData kUpdateSceneY(0.0f, false, false);
        DAT_011d9770->FUN_00a59c60(kUpdateSceneY);
        DAT_011d975c = ((MenuStub*)HUDMainMenu_pme)->FUN_0077ee50();
        DAT_011d96bc = new HUDEmptyStub;
        FUN_00450b80(1)->vfdc(DAT_011d9770, true);
        fShadowRadiusXB = DAT_011d9770->FUN_0043d450()->FUN_0084d030() * 3.0;
        FUN_00450b80(1)->FUN_00b5ca70(DAT_011d9770, fShadowRadiusXB);
        pBreathNodeYA = HUDMainMenu_pme->m_pTiles[72]->FUN_0056c7f0();
        pController27 = pBreathNodeYA->FUN_0043b4a0(0)->FUN_00a5c570(&DAT_011f36ac);
        pBreathNodeYA->FUN_006404b0(-1.5707964f, 1.0f, 0.0f, 0.0f);
        NiUpdateData kUpdateBreath2(0.0f, true, false);
        pBreathNodeYA->FUN_0043b4a0(0)->FUN_00a59c60(kUpdateBreath2);
        if (pController27)
        {
            NiControllerManagerStub* l_114 = (NiControllerManagerStub*)pController27;
            HUDMainMenu_pme->m_pHudAnimationSequence = l_114->FUN_0047a520(NiFixedString("Forward"));
            l_114->FUN_0048fef0(0.0f);
            if (HUDMainMenu_pme->m_pHudAnimationSequence)
                l_114->FUN_0047aab0(HUDMainMenu_pme->m_pHudAnimationSequence, 0, 1, 1.0f, 0.0f, 0);
        }
        pMenuXB->FUN_00a1dc20(1);
        FUN_0077e430(*DAT_011d9774.FUN_00403e20());
        UpdateVisibilityState(5);
        FUN_00713d70()->FUN_004538c0();
        return pMenuTileN;
    }
    else
    {
        if (pMenuXB && pMenuXB->FUN_00726070())
            delete pMenuXB;
    }
    FUN_00713d70()->FUN_004538c0();
    return 0;
}

class TESForm
{
  public:
    virtual ~TESForm();
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
class TESObjectREFR : public TESForm
{
};
class Actor : public TESObjectREFR
{
  public:
    bool FUN_008c1bc0();
};
struct SubtitlePoint
{
    float x, y, z;
    SubtitlePoint();
};
class BSSoundHandleEx
{
  public:
    unsigned int soundID, unk04, unk08;
    ~BSSoundHandleEx();
    int FUN_00ad8b30();
};
struct SubtitleRecord
{
    char text[260];
    unsigned int timestamp;
    float duration;
    SubtitlePoint position;
    int visibility;
    SubtitleRecord();
};
void* __cdecl operator new(unsigned int);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
template <class T> struct SubtitleArray
{
    void* table;
    T* buffer;
    unsigned int size, capacity;
    unsigned int Add(T& item);
};
struct SubtitleTimer
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, timestamp, unk18, unk1c;
    unsigned int GetTimeStamp();
};
struct SubtitleSettingBool
{
    bool* Bool();
};
struct SubtitleSettingFloat
{
    float* Float();
};
extern SubtitleSettingBool g_011d8928;
extern SubtitleSettingFloat originalRuntimeFloatSetting1229;
extern TESObjectREFR* g_thePlayer;
class SubtitleHUD : public Menu
{
  public:
    Tile* tiles[87];
    void* active;
    float seenLevel;
    char messages[8];
    unsigned int messageStart;
    SubtitleArray<SubtitleRecord*> subtitles;
    void* currentSubtitle;
    BSSoundHandleEx geigerSound;
    void* lastObject;
    int visibilityMenuMode, visibilityUserSettings, menuMode;
    char hotkeyWheel[52];
    bool scopeVisible;
    void* breathMeterAnimation;
    bool xpMeterFinishedMoving, forceObjectiveReminders;
    unsigned int killRegionDisplay;
    void* questList;
    int compassImageWidth, compassDisplayWidth, compassHalfAngle;
    void* currentEnemy;
    bool wasSneaking;
    SubtitleTimer timer;
    bool FUN_00774fd0(const char*, BSSoundHandleEx, SubtitlePoint, TESObjectREFR*, bool);
};
// @fnv 0x00774fd0
bool SubtitleHUD::FUN_00774fd0(const char* text, BSSoundHandleEx sound, SubtitlePoint position, TESObjectREFR* speaker,
                               bool persistent)
{
    bool added = false;
    Actor* actor = speaker && speaker->IsActor() ? dynamic_cast<Actor*>(speaker) : 0;
    if (text && (*g_011d8928.Bool() || (actor && actor->FUN_008c1bc0())))
    {
        SubtitleRecord* record = new SubtitleRecord;
        FUN_00406d30(record->text, 260, text);
        record->position = position;
        record->duration = sound.FUN_00ad8b30() / 1000.0;
        if (record->duration == 0.0)
            record->duration = strlen(text) * (*originalRuntimeFloatSetting1229.Float());
        if (persistent)
            record->visibility = 0x7fffffff;
        else if (speaker == g_thePlayer)
            record->visibility = 0;
        else if (speaker)
            record->visibility = 2;
        else
            record->visibility = 1;
        record->timestamp = timer.GetTimeStamp();
        subtitles.Add(record);
        added = true;
    }
    return added;
}
