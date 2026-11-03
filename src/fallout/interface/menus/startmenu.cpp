// fallout/interface/menus/startmenu.cpp: StartMenu, BGSSaveLoadUI, StartMenu_Wrap, ListBox_Option and more (184 functions)

#include "startmenu_packet.h"

// @fnv 0x004a4080
bool StartMenu::IsFlagSet(Flag aFlag)
{
    return (uiFlags & aFlag) != 0;
}

// @fnv 0x007d6e60
bool StartMenu::IsInGame()
{
    return DAT_011a0294;
}

// @fnv 0x007d1b30
void FUN_007d1b30()
{
    g_011c71ac.FUN_00450410();
}

// @fnv 0x007d1d00
float FUN_007d1d00(int type)
{
    return DAT_011ad7b8[type];
}

// @fnv 0x007d30d0
void FUN_007d30d0()
{
    g_011d8c4c.GetBoolValue();
}

// @fnv 0x007d1340
int PlayerCharacter::FUN_007d1340()
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x7C0);
}

// @fnv 0x007d3170
bool BGSSaveLoadUI::FUN_007d3170()
{
    return *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x85);
}

// @fnv 0x007d0bb0
void BGSSaveLoadUI::FUN_007d0bb0()
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x87) = true;
}

// @fnv 0x007d0bd0
void BGSSaveLoadUI::FUN_007d0bd0(bool bSet)
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x88) = bSet;
}

// @fnv 0x007d5140
char* BGSSaveLoadFileEntry::FUN_007d5140()
{
    ReadTypedData();
    return m_pSaveFileName;
}

// @fnv 0x007d5280
NiTexture* BGSSaveLoadFileEntry::FUN_007d5280()
{
    return spScreenshot.operator->();
}

struct FUN_0075f6f0_shell : public StartMenu
{
    void FUN_0075f6f0(int, bool);
};

// Sets or clears the bit aeFlag in uiFlags according to abOn.
// @fnv 0x0075f6f0
void FUN_0075f6f0_shell::FUN_0075f6f0(int aeFlag, bool abOn)
{
    abOn ? uiFlags |= aeFlag : uiFlags &= ~aeFlag;
}

struct FUN_0075f8c0_shell : public BGSSaveLoadFileEntry
{
    char* FUN_0075f8c0();
};

// @fnv 0x0075f8c0
char* FUN_0075f8c0_shell::FUN_0075f8c0()
{
    ReadTypedData();
    return *(char**)((char*)this + 0xc);
}

void __fastcall FUN_007d6f80(void* pThis);

// @fnv 0x007cb560
void __fastcall FUN_007cb560(void* pThis)
{
    FUN_007d6f80(pThis);
}

void __cdecl Deallocate(void*);
extern void* DAT_011daac4;

// Frees the global pointer DAT_011daac4 via Deallocate if it is non-null, then sets it to null.
// @fnv 0x007cb7a0
void FUN_007cb7a0()
{
    if (DAT_011daac4 != 0)
    {
        void* p = DAT_011daac4;
        Deallocate(p);
    }
    DAT_011daac4 = 0;
}

extern int DAT_01076ee0;
struct S007ce620
{
    void* vt;
    int a;
    int b;
    int c;
    S007ce620* FUN_007ce620(int a, int b, int c);
};
// Sets the vtable pointer and stores the three integer arguments into the object's fields, then returns this.
// @fnv 0x007ce620
S007ce620* S007ce620::FUN_007ce620(int pa, int pb, int pc)
{
    vt = &DAT_01076ee0;
    a = pa;
    b = pb;
    c = pc;
    return this;
}

struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_007cf8e0_shell : public StartMenu
{
    void FUN_007cf8e0(int, Tile*);
};

struct Tile
{
    void Set(int, int);
    float GetFloat(int);
    void Set(int, float, bool);
};

struct ListBox_int_
{
    bool ContainsKey(Tile*);
};

bool __cdecl FUN_004b71d0(void);
void __fastcall UpdateTargetInfo(StartMenu*);

// @fnv 0x007cf8e0
void FUN_007cf8e0_shell::FUN_007cf8e0(int aiID, Tile* apTarget)
{
    bool barrow = (aiID == 100 || aiID == 101);
    if (apTarget && barrow)
    {
        apTarget->Set(0xff5, (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x4))->GetFloat(0xff5), true);
    }
    if (!FUN_004b71d0())
    {
        if (reinterpret_cast<ListBox_int_*>(reinterpret_cast<char*>(this) + 0x174)->ContainsKey(apTarget))
        {
            UpdateTargetInfo(this);
        }
    }
    if (!barrow && *reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x6c))
    {
        (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x6c))->Set(0xfa3, 0);
    }
}

namespace fnv_007cfd20 {
struct FUN_007cfd20_shell : public StartMenu
{
    void SetTileValues();
};

class Tile
{
  public:
    void Set(int, int);
};

// Calls Set with the int at offset 0x1d0 and 1 on the Tile pointers at offsets 0x1c4 and 0x1c0.
// @fnv 0x007cfd20
void FUN_007cfd20_shell::SetTileValues()
{
    (*(Tile**)((char*)this + 0x1c4))->Set(*(int*)((char*)this + 0x1d0), 1);
    (*(Tile**)((char*)this + 0x1c0))->Set(*(int*)((char*)this + 0x1d0), 1);
}
}  // namespace fnv_007cfd20

struct FUN_007cfd60_shell : public StartMenu
{
    bool FUN_007cfd60(int);
};

class BSSystemUtility
{
  public:
    static int s_iUpdateEnabled;
};

bool __fastcall UpdateLoadingScreen(int);

// Returns true if FLAG_IIS_PREFADE is set, s_iUpdateEnabled is nonzero, and UpdateLoadingScreen accepts s_iUpdateEnabled.
// @fnv 0x007cfd60
bool FUN_007cfd60_shell::FUN_007cfd60(int aiKey)
{
    return IsFlagSet(FLAG_IIS_PREFADE) && BSSystemUtility::s_iUpdateEnabled != 0 &&
           UpdateLoadingScreen(BSSystemUtility::s_iUpdateEnabled);
}

namespace fnv_007d0490 {
struct Tile
{
    void Set(int, const char*);
};
struct StartMenuStandIn
{
    Tile* pad[18];
    Tile* t;
    void FUN_007d48a0(int, int);
};
struct GlobalObject_0040c150
{
    const char* GetMenuTitle(int);
};
extern GlobalObject_0040c150 g_011d3b50;
extern StartMenuStandIn* DAT_011daac0;
// If the start menu exists, sets tile 0xfc4 to the string from g_011d3b50 and calls FUN_007d48a0(0x80, 0).
// @fnv 0x007d0490
void FUN_007d0490()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->t->Set(0xfc4, g_011d3b50.GetMenuTitle(1));
        DAT_011daac0->FUN_007d48a0(0x80, 0);
    }
}
}  // namespace fnv_007d0490

namespace fnv_007d0680 {
struct Tile
{
    void Set(int, int);
};
struct SM0680
{
    char pad[0x64];
    Tile* t;
    void FUN_0075f6f0(int, int);
    void FUN_007d3b60();
};
extern SM0680* DAT_011daac0;
// If DAT_011daac0 is set, resets its tile via Set(0x1004, 0), calls FUN_0075f6f0(8, 0), then FUN_007d3b60.
// @fnv 0x007d0680
void FUN_007d0680()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->t->Set(0x1004, 0);
        DAT_011daac0->FUN_0075f6f0(8, 0);
        DAT_011daac0->FUN_007d3b60();
    }
}
}  // namespace fnv_007d0680

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011e0940;
struct PC7d
{
    int FUN_005be4d0();
    void FUN_007d1240(int);
};
extern PC7d* g_thePlayer;
extern StartMenu* DAT_011daac0;
struct Arg7d
{
    char p[0x14];
    int f14;
    int f18;
};
// @fnv 0x007d11d0
void FUN_007d11d0(Arg7d* a)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet((StartMenu::Flag)0x20))
    {
        int* p = g_011e0940.Int();
        *p = a->f14;
        g_thePlayer->FUN_007d1240(*p);
    }
    else
    {
        a->f14 = g_thePlayer->FUN_005be4d0();
        a->f18 = 2;
    }
}

namespace fnv_007d1260 {
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011e0940;
struct PC7d
{
    int FUN_005be4d0();
    void FUN_007d1240(int);
};
extern PC7d* g_thePlayer;
extern StartMenu* DAT_011daac0;
struct Arg7d
{
    char p[0x14];
    int f14;
    int f18;
};
// @fnv 0x007d1260
void FUN_007d1260(Arg7d* a)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet((StartMenu::Flag)0x20))
    {
        int* p = g_011e0940.Int();
        *p = a->f14;
        g_thePlayer->FUN_007d1240(*p);
    }
    else
    {
        a->f14 = g_thePlayer->FUN_005be4d0();
        a->f18 = 2;
    }
}
}  // namespace fnv_007d1260

namespace fnv_007d13a0 {
struct PC13a0
{
    bool FUN_004d1360();
    void FUN_007d1400(int);
};
struct P13a0
{
    char pad[0x14];
    int a;
    int b;
};
extern PC13a0* g_thePlayer;
extern StartMenu* DAT_011daac0;
// If the start menu has the save-options flag set, forwards p->a to the player; otherwise stores the player's boolean result in p->a and clears p->b.
// @fnv 0x007d13a0
void FUN_007d13a0(P13a0* pState)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        g_thePlayer->FUN_007d1400(pState->a);
    }
    else
    {
        pState->a = g_thePlayer->FUN_004d1360() ? 1 : 0;
        pState->b = 0;
    }
}
}  // namespace fnv_007d13a0

struct G7d1
{
    void FUN_004de2d0(bool);
    bool GetBoolValue();
};
struct CellStand
{
    int GetCellStandValue();
};
extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00 g_011d8a38;
void __cdecl FUN_007d14c0(int, int);
// @fnv 0x007d1440
void __cdecl UpdateSaveOptionsMenu(Menu* menu)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        ((G7d1*)&g_011d8a38)->FUN_004de2d0(menu->m_iModalMenuId == 1);
        FUN_007d14c0(0x40, ((CellStand*)&g_011d8a38)->GetCellStandValue());
    }
    else
    {
        menu->m_iModalMenuId = ((G7d1*)&g_011d8a38)->GetBoolValue() != 0;
        menu->m_iSecondaryValue = 1;
    }
}

struct GlobalObject_00709f00_ext
{
    void FUN_004de2d0(bool);
    unsigned char GetBoolValue();
};

extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00_ext g_011d89f0;

// If the start menu has FLAG_SAVE_OPTIONS set, updates the global from param_1[5]==1; otherwise sets param_1[5] from the global and marks param_1[6]=1.
// @fnv 0x007d1510
void __cdecl FUN_007d1510(int* param_1)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        g_011d89f0.FUN_004de2d0(param_1[5] == 1);
    }
    else
    {
        param_1[5] = g_011d89f0.GetBoolValue() != 0;
        param_1[6] = 1;
    }
}

namespace fnv_007d1570 {
struct GlobalObject_00709f00_ext : GlobalObject_00709f00
{
    void FUN_004de2d0(bool);
    bool GetBoolValue();
};

extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00 g_011d8974;

struct UnknownParam_007d1570
{
    int pad[5];
    int field_14;
    int field_18;
};

// If the start menu has the save-options flag, sets g_011d8974 from param->field_14 == 1; otherwise reads g_011d8974 into field_14 and sets field_18 to 1.
// @fnv 0x007d1570
void __cdecl FUN_007d1570(UnknownParam_007d1570* param)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        reinterpret_cast<GlobalObject_00709f00_ext*>(&g_011d8974)->FUN_004de2d0(param->field_14 == 1);
    }
    else
    {
        param->field_14 = reinterpret_cast<GlobalObject_00709f00_ext*>(&g_011d8974)->GetBoolValue() ? 1 : 0;
        param->field_18 = 1;
    }
}
}  // namespace fnv_007d1570

namespace fnv_007d15d0 {
struct GlobalObject_00709f00_ext
{
    void FUN_004de2d0(bool);
    unsigned char GetBoolValue();
};

extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00_ext g_011d89f0;

// @fnv 0x007d15d0
void __cdecl FUN_007d15d0(int* param_1)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        g_011d89f0.FUN_004de2d0(param_1[5] == 1);
    }
    else
    {
        param_1[5] = g_011d89f0.GetBoolValue() != 0;
        param_1[6] = 1;
    }
}
}  // namespace fnv_007d15d0

extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00 g_011d8934;

struct GlobalObject_00709f00_Compat
{
    void FUN_004de2d0(bool);
    bool GetBoolValue();
};

struct Param_007d1630
{
    int pad[5];
    int field_14;
    int field_18;
};

// @fnv 0x007d1630
void FUN_007d1630(Param_007d1630* pParams)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        reinterpret_cast<GlobalObject_00709f00_Compat*>(&g_011d8934)->FUN_004de2d0(pParams->field_14 == 1);
    }
    else
    {
        pParams->field_14 = reinterpret_cast<GlobalObject_00709f00_Compat*>(&g_011d8934)->GetBoolValue() != false;
        pParams->field_18 = 1;
    }
}

struct G1690
{
    bool GetBoolValue();
    void FUN_004de2d0(bool);
};
struct P1690
{
    char pad[0x14];
    int a;
    int b;
};
extern GlobalObject_00709f00 g_011d8928;
extern StartMenu* DAT_011daac0;
// If the StartMenu has FLAG_SAVE_OPTIONS set, pushes p->a==1 to g_011d8928; otherwise reads g_011d8928's flag into p->a and clears p->b.
// @fnv 0x007d1690
void FUN_007d1690(P1690* pData)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        ((G1690*)&g_011d8928)->FUN_004de2d0(pData->a == 1);
    }
    else
    {
        pData->a = ((G1690*)&g_011d8928)->GetBoolValue() ? 1 : 0;
        pData->b = 0;
    }
}

namespace fnv_007d16f0 {
struct GlobalObject_00709f00_ext
{
    void FUN_004de2d0(bool);
    unsigned char GetBoolValue();
};

extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00_ext g_011d89f0;

// If the start menu has FLAG_SAVE_OPTIONS set, updates g_011d89f0 from param_1[5]==1; otherwise sets param_1[5] from g_011d89f0 and param_1[6] to 1.
// @fnv 0x007d16f0
void __cdecl FUN_007d16f0(int* param_1)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        g_011d89f0.FUN_004de2d0(param_1[5] == 1);
    }
    else
    {
        param_1[5] = g_011d89f0.GetBoolValue() != 0;
        param_1[6] = 1;
    }
}
}  // namespace fnv_007d16f0

extern StartMenu* DAT_011daac0;
extern int DAT_0126efc4;

struct GlobalObject_004a4a40
{
    void FUN_0045ce80(int);
};
extern GlobalObject_004a4a40 g_011c779c;

struct StartMenu_Wrap : public StartMenu
{
    void FUN_0075f6f0(StartMenu::Flag flag, bool bSet);
};

// @fnv 0x007d1b40
void __cdecl FUN_007d1b40(int* pOptions)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        g_011c779c.FUN_0045ce80(pOptions[5]);
        ((StartMenu_Wrap*)DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_RESTART_REQUIRED, DAT_0126efc4 != pOptions[5]);
    }
    else
    {
        pOptions[5] = DAT_0126efc4;
        pOptions[6] = 0;
    }
}

class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    float FUN_00ad7a20();
    void FUN_00ad7b40(float);
};

class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};

struct Setting_007d28b0 : public GlobalObject_0044f440
{
    GlobalObject_0044f440* FUN_004ed780(float);
};

extern StartMenu* DAT_011daac0;
extern Setting_007d28b0 g_011f6e20;

struct UserOptionLayout_007d28b0
{
    char pad00[0x14];
    int iOptionId;      // +0x14
    int iDefaultValue;  // +0x18
    char pad1C[0x4];
    unsigned int uiNumStates;  // +0x20
};

// @fnv 0x007d28b0
void __cdecl FUN_007d28b0(UserOptionLayout_007d28b0* pOption)
{
    if (!pOption)
    {
        BSAudio::GetSingleton()->FUN_00ad7b40(g_011f6e20.FUN_00450410());
    }
    else if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        BSAudio::GetSingleton()->FUN_00ad7b40(
            g_011f6e20.FUN_004ed780((float)pOption->iOptionId / (pOption->uiNumStates - 1))->FUN_00450410());
    }
    else
    {
        pOption->iOptionId = (int)InventoryStackRecord::RoundToNearestStep(
            BSAudio::GetSingleton()->FUN_00ad7a20() * (pOption->uiNumStates - 1), 1.0f);
        pOption->iDefaultValue = (int)InventoryStackRecord::RoundToNearestStep((pOption->uiNumStates - 1) * 0.5, 1.0f);
    }
}

namespace fnv_007d29d0 {
class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton(void);
    float FUN_00ad7ab0(void);
    void FUN_00ad7bd0(float);
};

class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};

class Setting_004ed780 : public GlobalObject_0044f440
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};

extern StartMenu* DAT_011daac0;
extern Setting_004ed780 g_011f6e44;
extern const double DAT_010290b8;

struct UserOptionLayout_007d29d0
{
    char pad00[0x14];
    int i14;
    int i18;
    int i1C;
    unsigned int ui20;
};

// @fnv 0x007d29d0
void FUN_007d29d0(UserOptionLayout_007d29d0* pOption)
{
    if (!pOption)
    {
        BSAudio::GetSingleton()->FUN_00ad7bd0(g_011f6e44.FUN_00450410());
    }
    else if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        BSAudio::GetSingleton()->FUN_00ad7bd0(
            g_011f6e44.FUN_004ed780((float)pOption->i14 / (float)(pOption->ui20 - 1))->FUN_00450410());
    }
    else
    {
        pOption->i14 = (int)InventoryStackRecord::RoundToNearestStep(
            BSAudio::GetSingleton()->FUN_00ad7ab0() * (float)(pOption->ui20 - 1), 1.0f);
        pOption->i18 = (int)InventoryStackRecord::RoundToNearestStep((float)(pOption->ui20 - 1) * DAT_010290b8, 1.0f);
    }
}
}  // namespace fnv_007d29d0

struct G7d2
{
    void FUN_004de2d0(bool);
    bool GetBoolValue();
};
extern StartMenu* DAT_011daac0;
extern GlobalObject_00709f00 g_011e0a5c;
// @fnv 0x007d2e50
void __cdecl UpdateMenuSaveOptions(Menu* menu)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        ((G7d2*)&g_011e0a5c)->FUN_004de2d0(menu->m_iModalMenuId == 1);
    }
    else
    {
        menu->m_iModalMenuId = ((G7d2*)&g_011e0a5c)->GetBoolValue() != 0;
        menu->m_iSecondaryValue = 0;
    }
}

namespace fnv_007d2eb0 {
union SETTING_VALUE
{
    float f;
    int i;
};

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};

extern StartMenu* DAT_011daac0;
extern SettingT<GameSettingCollection> g_011e0a6c;

// @fnv 0x007d2eb0
void SyncSliderWithSetting(int pSlider)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float ratio = (float)*(int*)(pSlider + 0x14) / (float)(*(unsigned int*)(pSlider + 0x20) - 1);
        g_011e0a6c.Float()->f = ratio * 0.0095f + 0.0005f;
    }
    else
    {
        float ratio = (g_011e0a6c.Float()->f - 0.0005f) / 0.0095f;
        *(int*)(pSlider + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((float)(*(unsigned int*)(pSlider + 0x20) - 1) * ratio, 1.0f);
        ratio = (0.002f - 0.0005f) / 0.0095f;
        *(int*)(pSlider + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((float)(*(unsigned int*)(pSlider + 0x20) - 1) * ratio, 1.0f);
    }
}
}  // namespace fnv_007d2eb0

extern char* DAT_011f35cc;

// @fnv 0x007d30b0
void __cdecl FUN_007d30b0(char acValue)
{
    if (DAT_011f35cc)
    {
        DAT_011f35cc[0x1b88] = acValue;
    }
}

extern StartMenu* DAT_011daac0;
BGSSaveLoadUI* __cdecl FUN_00a25920();
void __cdecl FUN_007d30b0(bool);

namespace N {
class GlobalObject_00709f00
{
  public:
    GlobalObject_00709f00* FUN_004de2d0(bool);
    bool GetBoolValue();
};
}

extern N::GlobalObject_00709f00 g_011e0850;

struct Struct_007d30e0
{
    char pad[0x14];
    int field_14;
    int field_18;
};

// @fnv 0x007d30e0
void __cdecl FUN_007d30e0(Struct_007d30e0* pState)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        FUN_007d30b0(g_011e0850.FUN_004de2d0(pState->field_14 == 1)->GetBoolValue());
    }
    else
    {
        pState->field_14 = g_011e0850.GetBoolValue() != 0;
        pState->field_18 = FUN_00a25920()->FUN_007d3170() != 0;
    }
}

class VATSMenu
{
  public:
    int GetSelectedTargetIndex(void);
};

extern StartMenu* DAT_011daac0;

// @fnv 0x007d4040
bool __cdecl FUN_007d4040(int param_1)
{
    return !DAT_011daac0 ||
           (!DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_MODE) && !param_1 &&
            (unsigned int)reinterpret_cast<VATSMenu*>(&DAT_011daac0->m_kOptionHelper)->GetSelectedTargetIndex() > 1);
}

struct C7d
{
    float GetAccumulatedFloat();
};
struct B7d
{
    virtual void v0();
    virtual C7d* v1();
};
struct A7d
{
    float GetTotalFloat();
};
double __cdecl FUN_007177c0();
struct S7d8
{
    char p[0x28];
    A7d* a;
    char q[0x84 - 0x2c];
    B7d b;
    void PopulateListBoxTiles(void*, int, int, int, bool);
    void FUN_007d48a0(void* arg, unsigned char flags);
};
// @fnv 0x007d48a0
void S7d8::FUN_007d48a0(void* arg, unsigned char flags)
{
    int y;
    int x;
    int z;
    z = ((flags & 1) ? 0x58 : 0) + 0x50;
    x = (int)((double)(unsigned int)((int)a->GetTotalFloat() - z) - FUN_007177c0());
    y = (int)b.v1()->GetAccumulatedFloat() - 0x3c;
    PopulateListBoxTiles(arg, x, y, z, (flags & 2) != 0);
}

struct S007d4950
{
    void PopulateListBoxTiles(int, int, int, int, bool);
    void FUN_007d4950(int a, int b, int c, unsigned char f);
};
// Computes a value from the low bit of f and forwards a, b, c, that value and the second bit of f to PopulateListBoxTiles.
// @fnv 0x007d4950
void S007d4950::FUN_007d4950(int aiArg1, int aiArg2, int aiArg3, unsigned char f)
{
    int v = (f & 1) ? 0x53 + 0x55 - 0x53 + 0x53 : 0x55;
    PopulateListBoxTiles(aiArg1, aiArg2, aiArg3, v, (f & 2) != 0);
}

namespace fnv_007d4b40 {
struct BSSystemUtility
{
    static int s_iUpdateEnabled;
    static void __cdecl GetRandomGenerator();
};
struct N7d
{
    int* Data();
    N7d* Next();
};
struct SM7d
{
    void FUN_00851330();
    N7d* Head();
};
extern SM7d* DAT_011de134;
struct L7d
{
    void FUN_007d7da0(int, int, int, int);
};
struct S7d
{
    char p[0x174];
    L7d l;
    void FUN_007d4b40();
};
// @fnv 0x007d4b40
void S7d::FUN_007d4b40()
{
    if (BSSystemUtility::s_iUpdateEnabled)
        BSSystemUtility::GetRandomGenerator();
    DAT_011de134->FUN_00851330();
    for (N7d* n = DAT_011de134->Head(); n && *n->Data(); n = n->Next())
        l.FUN_007d7da0(*n->Data(), 0, 0, 0);
}
}  // namespace fnv_007d4b40

struct FUN_007d5160_shell : public BGSSaveLoadFileEntry
{
    unsigned int FUN_007d5160();
};

// @fnv 0x007d5160
unsigned int FUN_007d5160_shell::FUN_007d5160()
{
    ReadTypedData();
    return *(unsigned int*)((char*)this + 0x1c);
}

struct FUN_007d5180_shell : public BGSSaveLoadFileEntry
{
    char* FUN_007d5180();
};

// @fnv 0x007d5180
char* FUN_007d5180_shell::FUN_007d5180()
{
    ReadTypedData();
    return *(char**)((char*)this + 0x18);
}

namespace fnv_007d61e0 {
struct FUN_007d61e0_shell : public StartMenu
{
    void FadeTile(int, bool, int, float);
};

class Tile
{
  public:
    enum TILE_FADE_CONTROL_TYPE
    {
    };
    float GetFloat(int);
    void SetTraitFade(int, float, float, float, TILE_FADE_CONTROL_TYPE);
};

int __cdecl GetTileValueID(char const*, int);
extern double gModifierZero;
extern double DAT_0101e568;

// @fnv 0x007d61e0
void FUN_007d61e0_shell::FadeTile(int aeIndex, bool abFadeIn, int aiTrait, float afFadeTime)
{
    if (aiTrait == -0x80000000)
    {
        aiTrait = GetTileValueID("_alpha", -1);
    }
    if (afFadeTime < gModifierZero)
    {
        afFadeTime = 0.25f;
    }
    if (((Tile**)((char*)this + 0x28))[aeIndex])
    {
        if (abFadeIn && ((Tile**)((char*)this + 0x28))[aeIndex]->GetFloat(aiTrait) < DAT_0101e568)
        {
            ((Tile**)((char*)this + 0x28))[aeIndex]->SetTraitFade(aiTrait, 0.0f, 255.0f, afFadeTime,
                                                                  (Tile::TILE_FADE_CONTROL_TYPE)0);
        }
        else if (!abFadeIn && ((Tile**)((char*)this + 0x28))[aeIndex]->GetFloat(aiTrait) > gModifierZero)
        {
            ((Tile**)((char*)this + 0x28))[aeIndex]->SetTraitFade(aiTrait, 255.0f, 0.0f, afFadeTime,
                                                                  (Tile::TILE_FADE_CONTROL_TYPE)0);
        }
    }
}
}  // namespace fnv_007d61e0

struct FUN_007d6510_shell
{
    int FUN_007d76e0(int aiButton);
    int FUN_007d6510(int aiButton);
};

// Returns 0 for buttons 0xF and 0x10, otherwise forwards the button to FUN_007d76e0 and returns its result.
// @fnv 0x007d6510
int FUN_007d6510_shell::FUN_007d6510(int aiButton)
{
    return (aiButton != 0xF && aiButton != 0x10) ? FUN_007d76e0(aiButton) : 0;
}

struct FUN_007d6730_shell : public StartMenu
{
    void ProcessSaveLoadList();
};

struct BGSSaveLoadFileEntry;
typedef ListBox<BGSSaveLoadFileEntry*> LB7d6;
struct SM7d6
{
    void EnableAndRemoveHighlightedItem();
    void FUN_0075f6f0(int, int);
};
void HandleBackAction();
// @fnv 0x007d6730
void FUN_007d6730_shell::ProcessSaveLoadList()
{
    if (((LB7d6*)((char*)this + 0x84))->IsEnabled() && !IsFlagSet((StartMenu::Flag)0x20000))
    {
        while (!((LB7d6*)((char*)this + 0x84))->FUN_007d7580())
        {
            HandleBackAction();
            if (IsFlagSet((StartMenu::Flag)0x40000))
            {
                ((SM7d6*)this)->EnableAndRemoveHighlightedItem();
                ((SM7d6*)this)->FUN_0075f6f0(0x40000, 0);
            }
        }
    }
}

// @fnv 0x007d6950
int __fastcall FUN_007d6950(BGSSaveLoadFileEntry* pThis)
{
    pThis->ReadTypedData();
    return *(int*)((char*)pThis + 8);
}

// @fnv 0x007d6970
int __fastcall FUN_007d6970(BGSSaveLoadFileEntry* pThis)
{
    pThis->ReadTypedData();
    return *(int*)((char*)pThis + 0x14);
}

extern StartMenu* DAT_011daac0;

// For action 0, if DAT_011daac0 is set and its field at offset 0x1bc is nonzero, calls IsFlagSet with StartMenu::FLAG_INGAME.
// @fnv 0x007d6990
void __cdecl FUN_007d6990(int param_1)
{
    switch (param_1)
    {
    case 0:
        if (DAT_011daac0 && *(int*)((char*)DAT_011daac0 + 0x1bc))
        {
            DAT_011daac0->IsFlagSet(StartMenu::FLAG_INGAME);
        }
        break;
    }
}

namespace fnv_anon_startmenu {}
using namespace fnv_anon_startmenu;
namespace fnv_anon_startmenu {
struct Dummy7d6e90
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(int, int);
};
}

// @fnv 0x007d6e90
int __fastcall CallVirtualZero(Dummy7d6e90* pObject)
{
    return pObject->v5(0, 0);
}

namespace fnv_007d88a0 {
int __cdecl GetTileValueID(const char*, int);

class Tile
{
  public:
    bool ContainsTrait(int);
};

// @fnv 0x007d88a0
bool __fastcall FUN_007d88a0(void* pThis)
{
    static int s_trait = GetTileValueID("_enabled", -1);
    return *((Tile**)pThis + 3) && (*((Tile**)pThis + 3))->ContainsTrait(s_trait);
}
}  // namespace fnv_007d88a0

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

extern char DAT_011dd0f0;
extern char DAT_011dd1f8;
extern float DAT_011dd300;
extern float DAT_011dd304;
extern float DAT_011dd308;
extern float DAT_011dd30c;
extern char DAT_011dd310;
extern char DAT_011dd311;
extern unsigned long DAT_011dd314;
extern int DAT_011dd318;
extern int DAT_011dd31c;
extern int DAT_011dd320;
extern int DAT_011dd324;
extern unsigned long DAT_011dd328;
extern unsigned long DAT_011dd32c;
extern int DAT_011dd330;
extern unsigned long DAT_011dd334;
extern float DAT_011dd338;
extern float DAT_011dd33c;
extern float DAT_011dd340;
extern float DAT_011dd344;
extern unsigned long DAT_011dd348;
extern int DAT_011dd34c;
extern int DAT_011dd350;
extern int DAT_011dd354;
extern int DAT_011dd358;
extern unsigned long DAT_011dd35c;
extern unsigned long DAT_011dd360;
extern int DAT_011dd364;
extern unsigned long DAT_011dd368;
extern int DAT_011dd36c;

// @fnv 0x0082fa30
void __cdecl ResetTaskQueueGlobals()
{
    DAT_011dd300 = 0.0f;
    DAT_011dd304 = 0.0f;
    DAT_011dd308 = 0.0f;
    DAT_011dd30c = 0.0f;
    DAT_011dd310 = 0;
    TaskQueueInterface::CopyStringToBuffer(&DAT_011dd0f0, 0x104, "NONE");
    DAT_011dd314 = 0;
    DAT_011dd318 = 0;
    DAT_011dd31c = 0;
    DAT_011dd320 = 0;
    DAT_011dd324 = 0;
    DAT_011dd328 = 0;
    DAT_011dd32c = 0;
    DAT_011dd330 = 0;
    DAT_011dd334 = 0;
    DAT_011dd338 = 0.0f;
    DAT_011dd33c = 0.0f;
    DAT_011dd340 = 0.0f;
    DAT_011dd344 = 0.0f;
    DAT_011dd311 = 0;
    TaskQueueInterface::CopyStringToBuffer(&DAT_011dd1f8, 0x104, "NONE");
    DAT_011dd348 = 0;
    DAT_011dd34c = 0;
    DAT_011dd350 = 0;
    DAT_011dd354 = 0;
    DAT_011dd358 = 0;
    DAT_011dd35c = 0;
    DAT_011dd360 = 0;
    DAT_011dd364 = 0;
    DAT_011dd368 = 0;
    DAT_011dd36c = 0;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007cb510
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct ListX
{
    ~ListX();
};
namespace p07 {
void __cdecl FUN_007211c0(void*);
struct FUN_007d6f80
{
    ListX list;
    virtual ~FUN_007d6f80();
    void FUN_007646d0();
};
// @fnv 0x007d6f80
FUN_007d6f80::~FUN_007d6f80()
{
    FUN_007646d0();
    FUN_007211c0(this);
}
}

namespace fnv_007d1750 {
struct Setting_S
{
    float* Float();
};
struct S_004ed780
{
    S_004ed780* FUN_004ed780(float);
};
struct SM7d6
{
    void FUN_0075f6f0(int, int);
};
struct InventoryStackRecord
{
    static float __cdecl RoundToNearestStep(float, float);
};
struct StartMenuSm
{
    bool IsFlagSet(int);
};
extern Setting_S g_011d9774;
extern StartMenuSm* DAT_011daac0;

struct MenuCtl
{
    char pad[0x14];
    int a;
    int b;
    int c;
    unsigned int count;
};

// @fnv 0x007d1750
void FUN_007d1750(MenuCtl* pMenuCtl)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(0x20))
    {
        ((S_004ed780*)&g_011d9774)->FUN_004ed780((float)pMenuCtl->a / (float)(pMenuCtl->count - 1));
        ((SM7d6*)DAT_011daac0)->FUN_0075f6f0(0x40, 1);
    }
    else
    {
        pMenuCtl->a = (int)InventoryStackRecord::RoundToNearestStep(*g_011d9774.Float() * (float)(pMenuCtl->count - 1), 1.0f);
        pMenuCtl->b = (int)InventoryStackRecord::RoundToNearestStep(1.0f * (float)(pMenuCtl->count - 1), 1.0f);
    }
}
}  // namespace fnv_007d1750

struct SystemColorManager
{
    static SystemColorManager* __stdcall GetSingleton(int);
    void DispatchToTarget(int);
    int FUN_007190a0();
};
struct TileOps
{
    void FUN_00a0b350();
};
struct IMH
{
    TileOps* FUN_00586150();
};
IMH* __stdcall FUN_004b7210(int, float);

extern StartMenu* DAT_011daac0;
extern int DAT_011dac50[];
struct ColorSlot
{
    int pad[5];
    unsigned int index;
    unsigned int defaultIndex;
    int pad2;
    unsigned int count;
};
// @fnv 0x007d1840
void UpdateColorSlotIndex(ColorSlot* slot)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        SystemColorManager::GetSingleton(1)->DispatchToTarget(DAT_011dac50[slot->index]);
        FUN_004b7210(1, 0.0f)->FUN_00586150()->FUN_00a0b350();
    }
    else
    {
        slot->defaultIndex = 2;
        slot->index = 0;
        while (DAT_011dac50[slot->index] != SystemColorManager::GetSingleton(1)->FUN_007190a0())
        {
            slot->index = slot->index + 1;
            if (slot->index >= slot->count)
            {
                slot->index = slot->defaultIndex;
                break;
            }
        }
    }
}

namespace fnv_007d1900 {
struct SystemColorManager
{
    static SystemColorManager* __stdcall GetSingleton(int);
    void DispatchToTarget(int);
    int FUN_007190a0();
};
struct TileOps
{
    void FUN_00a0b350();
};
struct IMH
{
    TileOps* FUN_00586150();
};
IMH* __stdcall FUN_004b7210(int, float);

extern StartMenu* DAT_011daac0;
extern int DAT_011dac50[];
struct ColorSlot
{
    int pad[5];
    unsigned int index;
    unsigned int defaultIndex;
    int pad2;
    unsigned int count;
};
// @fnv 0x007d1900
void ApplyOrSyncColorSlot(ColorSlot* slot)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        SystemColorManager::GetSingleton(4)->DispatchToTarget(DAT_011dac50[slot->index]);
        FUN_004b7210(4, 0.0f)->FUN_00586150()->FUN_00a0b350();
    }
    else
    {
        slot->defaultIndex = 2;
        slot->index = 0;
        while (DAT_011dac50[slot->index] != SystemColorManager::GetSingleton(4)->FUN_007190a0())
        {
            slot->index = slot->index + 1;
            if (slot->index >= slot->count)
            {
                slot->index = slot->defaultIndex;
                break;
            }
        }
    }
}
}  // namespace fnv_007d1900

namespace fnv_007d2fc0 {
struct IM
{
    void FUN_00719740(bool);
};
IM* __cdecl FUN_004b7210();
struct Tile
{
    void Set(int, int);
};
struct Hot
{
    void FUN_005407b0(bool);
};
struct OSGlobals
{
    Hot* FUN_00877720();
};
void __cdecl FUN_007d30b0(bool);
extern OSGlobals* g_osGlobals;
extern StartMenu* DAT_011daac0;
struct SaveOpt
{
    int pad[5];
    int state;
    int mode;
};
// @fnv 0x007d2fc0
void UpdateSaveOption(SaveOpt* pSaveOpt)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        bool bOn = pSaveOpt->state == 1;
        FUN_004b7210()->FUN_00719740(!bOn);
        if (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011daac0) + 0x1cc))
            (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(DAT_011daac0) + 0x1cc))
                ->Set(*reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_011daac0) + 0x1d0), bOn);
    }
    else
    {
        FUN_004b7210();
        pSaveOpt->state = !reinterpret_cast<bool(__cdecl*)()>(FUN_007d30d0)();
        FUN_004b7210();
        g_osGlobals->FUN_00877720()->FUN_005407b0(reinterpret_cast<bool(__cdecl*)()>(FUN_007d30d0)());
        g_osGlobals->FUN_00877720();
        FUN_004b7210();
        FUN_007d30b0(!reinterpret_cast<bool(__cdecl*)()>(FUN_007d30d0)());
        pSaveOpt->mode = 1;
    }
}
}  // namespace fnv_007d2fc0

namespace fnv_007d51a0 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct NiTexture;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct blob4
{
    char b[4];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_007d51a0_shell : public StartMenu
{
    bool FUN_007d51a0(BGSSaveLoadFileEntry*);
};

struct NiTexture
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
    virtual unsigned int v37();
    virtual unsigned int v38();
};
struct NodeObj
{
    int FUN_009c8660();
    void FUN_007700b0(unsigned int);
};
struct Tile
{
    void Set(int, unsigned int);
    NodeObj* FUN_007d5280();
};
struct TileImage : public Tile
{
    void SetTexture(NiTexture*);
};
struct EntryOps
{
    NiTexture* ReadScreenshotFromFile();
};
struct ListOps
{
    BGSSaveLoadFileEntry* GetSelectedData();
};
struct FltOps
{
    operator unsigned int() const;
};
// @fnv 0x007d51a0
bool FUN_007d51a0_shell::FUN_007d51a0(BGSSaveLoadFileEntry* apSaveGame)
{
    if (!apSaveGame)
        apSaveGame = reinterpret_cast<ListOps*>(reinterpret_cast<char*>(this) + 0x174)->GetSelectedData();
    TileImage* pTileImage;
    NiTexture* pTexture = apSaveGame ? reinterpret_cast<EntryOps*>(apSaveGame)->ReadScreenshotFromFile() : 0;
    if (pTexture)
    {
        pTileImage = *reinterpret_cast<TileImage**>(reinterpret_cast<char*>(this) + 0x54);
        pTileImage->SetTexture(pTexture);
        pTileImage->Set(0xfb0, pTexture->v38());
        pTileImage->Set(0xfb1, pTexture->v37());
        if (!pTileImage->FUN_007d5280()->FUN_009c8660())
            pTileImage->FUN_007d5280()->FUN_007700b0(*reinterpret_cast<FltOps*>(reinterpret_cast<char*>(this) + 0x1b8));
        return true;
    }
    return false;
}
}  // namespace fnv_007d51a0

// @fnv 0x004504f0
void SetFloatAt(int index, float value)
{
    DAT_011ad7b8[index] = value;
}

void CleanupGlobalObject();
// @fnv 0x00704000
void FUN_00704000()
{
    CleanupGlobalObject();
}

void __fastcall FUN_007cb560(void* p);
void __cdecl _Deallocate(void* p);

struct FUN_007cb580_Class
{
    void* FUN_007cb580(unsigned int flags);
};

// Calls FUN_007cb560 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007cb580
void* FUN_007cb580_Class::FUN_007cb580(unsigned int flags)
{
    FUN_007cb560(this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_007cb5b0 {
bool __cdecl FUN_0070edf0(void);
void __cdecl FUN_00761460(bool abEnable);
void __cdecl FUN_0077e430(float afOpacity);
struct FalloutAudioMedia
{
    static void __cdecl FadeOutMedia(int aiTime, int aeType);
};
struct OptionManager
{
    static OptionManager* __cdecl Instance();
    static void __cdecl FUN_007cb7a0();
};
struct M788
{
    void FUN_004ed900();
};
extern M788 g_011dabd8;
class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    void FUN_0070bc00();
};
class BGSSaveLoadManager
{
  public:
    void FUN_00851540();
};
extern BGSSaveLoadManager* DAT_011de134;
extern StartMenu* DAT_011daac0;
extern GlobalObject_0044f440 g_011d9774;
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    int m_iMenuId;
    Interface__FADE_STATE m_eFadeState;
};
struct ListBoxBase
{
    virtual ~ListBoxBase();
    BSSimpleList<void*> xList;
    Tile* pParentTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float fUnk20;
    float fStoredListIndex;
    float fStoredScrollbarPos;
    unsigned short usFlags;
};
struct FUN_007cb560 : ListBoxBase
{
    ~FUN_007cb560();
};
struct Member_007a8b10 : ListBoxBase
{
    ~Member_007a8b10();
};
struct FUN_007d7d30 : ListBoxBase
{
    ~FUN_007d7d30();
};
struct GO
{
    ~GO();
    void* m_pObject;
};
struct FUN_007cb5b0 : Menu_007a8b10
{
    virtual ~FUN_007cb5b0();
    bool IsFlagSet(StartMenu::Flag aFlag);
    Tile* m_pTiles[23];
    FUN_007cb560 m_kFirstOptionListBox;
    FUN_007cb560 m_kSecondOptionListBox;
    FUN_007cb560 m_kThirdOptionListBox;
    FUN_007cb560 m_kDownloadOptions;
    Member_007a8b10 m_kOptionIndexList;
    FUN_007d7d30 m_kOptionHelper;
    StartMenu::UserOption* m_pUserOption;
    unsigned int uiFlags;
    float m_fMenuTimer;
    void* m_pData;
    StartMenu::UserOption* m_pSelectedUserOption;
    GO m_kObject;
};
// @fnv 0x007cb5b0
FUN_007cb5b0::~FUN_007cb5b0()
{
    if (IsFlagSet(StartMenu::FLAG_RESET_HUD_OPACITY))
        FUN_0077e430(g_011d9774.FUN_00450410());
    BSAudio::GetSingleton()->FUN_0070bc00();
    if (FUN_0070edf0())
    {
        FUN_00761460(false);
        FalloutAudioMedia::FadeOutMedia(2000, 0);
    }
    DAT_011de134->FUN_00851540();
    DAT_011daac0 = 0;
    g_011dabd8.FUN_004ed900();
    OptionManager::Instance()->FUN_007cb7a0();
}
}  // namespace fnv_007cb5b0

struct StartMenu_Option
{
    void InitPointer();
    void* FUN_007ce660(unsigned int flags);
};

void _Deallocate(void* p);

// @fnv 0x007ce660
void* StartMenu_Option::FUN_007ce660(unsigned int flags)
{
    InitPointer();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct GlobalObject_007da090
{
    void FUN_007d8e20(bool);
};
struct StartMenuEntryStandIn
{
    virtual ~StartMenuEntryStandIn();
};
extern ArrSI g_011dab88;
extern ArrSI g_011dab50;
extern GlobalObject_007da090 g_011daae0;

// Deletes every entry in the two start-menu arrays, clears both arrays, then calls FUN_007d8e20(true) on g_011daae0.
// @fnv 0x007ce6b0
void ClearStartMenuEntries()
{
    for (unsigned int i = 0; i < g_011dab88.GetFlags(); i++)
    {
        delete (StartMenuEntryStandIn*)*((Arr*)&g_011dab88)->GetAt(i);
    }
    ((GlobalObject_00869f00*)&g_011dab88)->Clear(true);
    for (unsigned int j = 0; j < g_011dab50.GetFlags(); j++)
    {
        delete (StartMenuEntryStandIn*)*((Arr*)&g_011dab50)->GetAt(j);
    }
    ((GlobalObject_00869f00*)&g_011dab50)->Clear(true);
    g_011daae0.FUN_007d8e20(true);
}

namespace fnv_007cf670 {
class Tile
{
  public:
    void Set(int, int);
};

struct FUN_007cf670_Class
{
    void FUN_007cf670(int aiID, Tile* apTarget);
};

// If apTarget is non-null and aiID is 0x64 or 0x65, calls apTarget->Set(0xFF5, -1).
// @fnv 0x007cf670
void FUN_007cf670_Class::FUN_007cf670(int aiID, Tile* apTarget)
{
    if (apTarget && (aiID == 0x64 || aiID == 0x65))
        apTarget->Set(0xFF5, -1);
}
}  // namespace fnv_007cf670

// @fnv 0x007d03a0
bool FUN_007d03a0(int type)
{
    return type == 0 || type == 1 || type == 2 || type == 3 || type == 4 || type == 5 || type == 6 || type == 7 ||
           type == 8 || type == 9 || type == 10 || type == 11 || type == 12 || type == 13 || type == 14 || type == 15 ||
           type == 25 || type == 26 || type == 16 || type == 27 || type == 18;
}

namespace fnv_007d04d0 {
struct SM7d6
{
    void FUN_0075f6f0(int, int);
};

struct MenuSI
{
    void FadeTile(int, int, unsigned int, float);
};

struct StartMenuStandIn : SM7d6
{
    void FadeTile(int, int, unsigned int, float);
};

extern StartMenuStandIn* DAT_011daac0;

// @fnv 0x007d04d0
void FUN_007d04d0()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->FUN_0075f6f0(0x10000, 1);
        DAT_011daac0->FadeTile(3, 0, 0xfa9, -1.0f);
        DAT_011daac0->FadeTile(0, 0, 0x80000000, -1.0f);
        DAT_011daac0->FadeTile(9, 0, 0xfa9, -1.0f);
    }
}
}  // namespace fnv_007d04d0

struct Flt
{
    operator const char*() const;
};
class TESFile
{
  public:
    bool GetByteAt428();
    Flt& GetField418();
};
struct GlobalObject_0040c150
{
    const char* GetMenuTitle();
};
struct MenuSI
{
    void FadeTile(int aiIndex, int aiValue, unsigned int auiTrait, float afTime);
};
extern TESDataHandler* g_dataHandler;
extern GlobalObject_0040c150 g_011d3ad4;
extern StartMenu* DAT_011daac0;

// @fnv 0x007d0550
void PopulateFileList()
{
    if (DAT_011daac0)
    {
        BSSimpleList<TESFile*>* pnode = g_dataHandler->GetFileList();
        DAT_011daac0->m_kOptionIndexList.RemoveAll();
        DAT_011daac0->m_kOptionIndexList.AddItem(-1, g_011d3ad4.GetMenuTitle(), 0, 0);
        while (pnode)
        {
            TESFile* pfile = pnode->GetItem();
            if (pfile && pfile->GetByteAt428())
                DAT_011daac0->m_kOptionIndexList.AddItem(0, pfile->GetField418(), 0, 0);
            pnode = pnode->GetNext();
        }
        DAT_011daac0->m_kOptionIndexList.SetEnabled(true);
        reinterpret_cast<MenuSI*>(DAT_011daac0)->FadeTile(14, 1, 0x80000000, -1.0f);
        reinterpret_cast<MenuSI*>(DAT_011daac0)->FadeTile(5, 1, 0x80000000, -1.0f);
    }
}

struct FUN_007d0660_class
{
    void* GetField418();
};

// @fnv 0x007d0660
void* FUN_007d0660_class::GetField418()
{
    return reinterpret_cast<char*>(this) + 0x418;
}

struct FUN_007d0b90_cls
{
    void FUN_007d0b90();
};

// @fnv 0x007d0b90
void FUN_007d0b90_cls::FUN_007d0b90()
{
    ((unsigned char*)this)[2] = 1;
}

namespace fnv_007d0dc0 {
struct VObj
{
    void FUN_007d74f0(int);
};

struct StartMenuStandIn
{
    void PopulateList(int);
};

extern StartMenuStandIn* DAT_011daac0;

// @fnv 0x007d0dc0
void FUN_007d0dc0()
{
    if (DAT_011daac0)
    {
        ((VObj*)((char*)DAT_011daac0 + 0xb4))->FUN_007d74f0(0);
        DAT_011daac0->PopulateList(0x20);
    }
}
}  // namespace fnv_007d0dc0

namespace fnv_007d1bb0 {
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
class SettingFloat
{
  public:
    float* Float();
};
class Setting_007d28b0
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};
struct GlobalObject_0045d060;
extern GlobalObject_0045d060 g_011c3ec0;
extern GlobalObject_0044f440 g_011daaf4;
extern GlobalObject_0044f440 g_011dab1c;
extern GlobalObject_0044f440 g_011dac38;
extern StartMenu* DAT_011daac0;
void __cdecl SetFloatAt(int, float);
float __cdecl FUN_007d1d00(int);

// @fnv 0x007d1bb0
void SyncOptionWithSettings(StartMenu::UserOption* apOption)
{
    float fHigh;
    float fLow;
    fLow = *((SettingFloat*)&g_011dab1c)->Float();
    fHigh = *((SettingFloat*)&g_011daaf4)->Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fValue;
        float fNormalizedPosition =
            (float)*(int*)((char*)apOption + 0x14) / (*(unsigned int*)((char*)apOption + 0x20) - 1);
        fValue = (fHigh - fLow) * fNormalizedPosition + fLow;
        SetFloatAt(3, fValue);
        ((Setting_007d28b0*)&g_011c3ec0)->FUN_004ed780(fValue);
    }
    else
    {
        float fRatio = (FUN_007d1d00(3) - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
        fRatio = (*((SettingFloat*)&g_011dac38)->Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
    }
}
}  // namespace fnv_007d1bb0

namespace fnv_007d1d10 {
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
class SettingFloat
{
  public:
    float* Float();
};
class Setting_007d28b0
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};
struct GlobalObject_0045d060;
extern GlobalObject_0045d060 g_011c3d0c;
extern GlobalObject_0044f440 g_011dac24;
extern GlobalObject_0044f440 g_011dabf0;
extern GlobalObject_0044f440 g_011dabc0;
extern StartMenu* DAT_011daac0;
void __cdecl SetFloatAt(int, float);
float __cdecl FUN_007d1d00(int);

// @fnv 0x007d1d10
void FUN_007d1d10(StartMenu::UserOption* apOption)
{
    float fHigh;
    float fLow;
    fLow = *((SettingFloat*)&g_011dabf0)->Float();
    fHigh = *((SettingFloat*)&g_011dac24)->Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fValue;
        float fNormalizedPosition =
            (float)*(int*)((char*)apOption + 0x14) / (*(unsigned int*)((char*)apOption + 0x20) - 1);
        fValue = (fHigh - fLow) * fNormalizedPosition + fLow;
        SetFloatAt(2, fValue);
        ((Setting_007d28b0*)&g_011c3d0c)->FUN_004ed780(fValue);
    }
    else
    {
        float fRatio = (FUN_007d1d00(2) - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
        fRatio = (*((SettingFloat*)&g_011dabc0)->Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
    }
}
}  // namespace fnv_007d1d10

namespace fnv_007d1e60 {
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
class SettingFloat
{
  public:
    float* Float();
};
class Setting_007d28b0
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};
struct GlobalObject_0045d060;
extern GlobalObject_0045d060 g_011c3d78;
extern GlobalObject_0044f440 g_011dab78;
extern GlobalObject_0044f440 g_011dab30;
extern GlobalObject_0044f440 g_011dab6c;
extern StartMenu* DAT_011daac0;
void __cdecl SetFloatAt(int, float);
float __cdecl FUN_007d1d00(int);

// @fnv 0x007d1e60
void SyncUserOptionSetting(StartMenu::UserOption* apOption)
{
    float fHigh;
    float fLow;
    fLow = *((SettingFloat*)&g_011dab30)->Float();
    fHigh = *((SettingFloat*)&g_011dab78)->Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fValue;
        float fNormalizedPosition =
            (float)*(int*)((char*)apOption + 0x14) / (*(unsigned int*)((char*)apOption + 0x20) - 1);
        fValue = (fHigh - fLow) * fNormalizedPosition + fLow;
        SetFloatAt(1, fValue);
        ((Setting_007d28b0*)&g_011c3d78)->FUN_004ed780(fValue);
    }
    else
    {
        float fRatio = (FUN_007d1d00(1) - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
        fRatio = (*((SettingFloat*)&g_011dab6c)->Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
    }
}
}  // namespace fnv_007d1e60

namespace fnv_007d1fb0 {
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
class SettingFloat
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011ca4ac;
extern GlobalObject_0044f440 g_011ca4cc;
extern GlobalObject_0044f440 g_011ca4d8;
extern GlobalObject_0044f440 DAT_011ca450;
extern StartMenu* DAT_011daac0;

// Maps a user option's slider index to/from a float setting between low and high bounds, depending on the save-options flag.
// @fnv 0x007d1fb0
void SyncUserOptionSlider(StartMenu::UserOption* apOption)
{
    float fHigh;
    float fLow;
    fLow = *((SettingFloat*)&g_011ca4ac)->Float();
    fHigh = *((SettingFloat*)&g_011ca4d8)->Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fValue;
        float fNormalizedPosition =
            (float)*(int*)((char*)apOption + 0x14) / (*(unsigned int*)((char*)apOption + 0x20) - 1);
        fValue = (fHigh - fLow) * fNormalizedPosition + fLow;
        *((SettingFloat*)&DAT_011ca450)->Float() = fValue;
    }
    else
    {
        float fRatio = (*((SettingFloat*)&DAT_011ca450)->Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
        fRatio = (*((SettingFloat*)&g_011ca4cc)->Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)apOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * fRatio, 1.0f);
    }
}
}  // namespace fnv_007d1fb0

namespace fnv_007d2510 {
struct Setting_S
{
    float* Float();
};
class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};
extern Setting_S g_011d86c4;
extern Setting_S g_011d86ec;
extern Setting_S g_011d870c;
extern Setting_S DAT_011d8724;
extern StartMenu* DAT_011daac0;

// Converts a UserOption's slider index to a float setting value, or back-converts the float settings to slider indices, depending on the save-options flag.
// @fnv 0x007d2510
void FUN_007d2510(StartMenu::UserOption* pOption)
{
    float fLow = *g_011d86c4.Float();
    float fHigh = *g_011d86ec.Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fNormalizedPosition =
            (float)*(int*)((char*)pOption + 0x14) / (float)(*(unsigned int*)((char*)pOption + 0x20) - 1);
        float fValue = (fHigh - fLow) * fNormalizedPosition + fLow;
        *DAT_011d8724.Float() = fValue;
    }
    else
    {
        float fRatio = (*DAT_011d8724.Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)pOption + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)pOption + 0x20) - 1) * fRatio, 1.0f);
        fRatio = (*g_011d870c.Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)pOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)pOption + 0x20) - 1) * fRatio, 1.0f);
    }
}
}  // namespace fnv_007d2510

namespace fnv_007d2650 {
struct Setting_S
{
    float* Float();
};
class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};
extern Setting_S g_011d8734;
extern Setting_S g_011d8718;
extern Setting_S g_011d8770;
extern Setting_S DAT_011d8788;
extern StartMenu* DAT_011daac0;

// Maps the option's stored index to a float setting (or back) using the low/high range, depending on the StartMenu save-options flag.
// @fnv 0x007d2650
void SyncOptionValue(StartMenu::UserOption* pOption)
{
    float fLow = *g_011d8734.Float();
    float fHigh = *g_011d8718.Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fNormalizedPosition =
            (float)*(int*)((char*)pOption + 0x14) / (float)(*(unsigned int*)((char*)pOption + 0x20) - 1);
        float fValue = (fHigh - fLow) * fNormalizedPosition + fLow;
        *DAT_011d8788.Float() = fValue;
    }
    else
    {
        float fRatio = (*DAT_011d8788.Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)pOption + 0x14) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)pOption + 0x20) - 1) * fRatio, 1.0f);
        fRatio = (*g_011d8770.Float() - fLow) / (fHigh - fLow);
        *(int*)((char*)pOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)pOption + 0x20) - 1) * fRatio, 1.0f);
    }
}
}  // namespace fnv_007d2650

namespace fnv_007d2790 {
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    void SetMasterVolume(float);
    float GetMasterVolume();
};
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
class Setting_007d28b0
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};
extern GlobalObject_0044f440 g_011f6e14;
extern StartMenu* DAT_011daac0;

// @fnv 0x007d2790
void FUN_007d2790(StartMenu::UserOption* apOption)
{
    if (!apOption)
    {
        BSAudio::GetSingleton()->SetMasterVolume(g_011f6e14.FUN_00450410());
    }
    else if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        BSAudio::GetSingleton()->SetMasterVolume(
            ((Setting_007d28b0*)&g_011f6e14)
                ->FUN_004ed780((float)*(int*)((char*)apOption + 0x14) / (*(unsigned int*)((char*)apOption + 0x20) - 1))
                ->FUN_00450410());
    }
    else
    {
        *(int*)((char*)apOption + 0x14) = (int)InventoryStackRecord::RoundToNearestStep(
            BSAudio::GetSingleton()->GetMasterVolume() * (*(unsigned int*)((char*)apOption + 0x20) - 1), 1.0f);
        *(int*)((char*)apOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep(1.0f * (*(unsigned int*)((char*)apOption + 0x20) - 1), 1.0f);
    }
}
}  // namespace fnv_007d2790

namespace fnv_007d2af0 {
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    void FUN_00ad7b70(float);
    float FUN_00ad7a50();
};
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
class Setting_007d28b0
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};
extern GlobalObject_0044f440 g_011f6e2c;
extern StartMenu* DAT_011daac0;

// @fnv 0x007d2af0
void FUN_007d2af0(StartMenu::UserOption* apOption)
{
    if (!apOption)
    {
        BSAudio::GetSingleton()->FUN_00ad7b70(g_011f6e2c.FUN_00450410());
    }
    else if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        BSAudio::GetSingleton()->FUN_00ad7b70(
            ((Setting_007d28b0*)&g_011f6e2c)
                ->FUN_004ed780((float)*(int*)((char*)apOption + 0x14) / (*(unsigned int*)((char*)apOption + 0x20) - 1))
                ->FUN_00450410());
    }
    else
    {
        *(int*)((char*)apOption + 0x14) = (int)InventoryStackRecord::RoundToNearestStep(
            BSAudio::GetSingleton()->FUN_00ad7a50() * (*(unsigned int*)((char*)apOption + 0x20) - 1), 1.0f);
        *(int*)((char*)apOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep((*(unsigned int*)((char*)apOption + 0x20) - 1) * 0.6f, 1.0f);
    }
}
}  // namespace fnv_007d2af0

namespace fnv_007d2c10 {
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    float FUN_00ad7a80();
    void FUN_00ad7ba0(float);
};
class InventoryStackRecord
{
  public:
    static float RoundToNearestStep(float, float);
};
struct S_004ed780
{
    GlobalObject_0044f440* FUN_004ed780(float);
};
extern GlobalObject_0044f440 g_011f6e38;
extern StartMenu* DAT_011daac0;

// @fnv 0x007d2c10
void FUN_007d2c10(StartMenu::UserOption* pUserOption)
{
    if (pUserOption == 0)
    {
        BSAudio::GetSingleton()->FUN_00ad7ba0(g_011f6e38.FUN_00450410());
    }
    else if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        BSAudio::GetSingleton()->FUN_00ad7ba0(((S_004ed780*)&g_011f6e38)
                                                  ->FUN_004ed780((float)*(int*)((char*)pUserOption + 0x14) /
                                                                 (*(unsigned int*)((char*)pUserOption + 0x20) - 1))
                                                  ->FUN_00450410());
    }
    else
    {
        *(int*)((char*)pUserOption + 0x14) = (int)InventoryStackRecord::RoundToNearestStep(
            BSAudio::GetSingleton()->FUN_00ad7a80() * (*(unsigned int*)((char*)pUserOption + 0x20) - 1), 1.0f);
        *(int*)((char*)pUserOption + 0x18) =
            (int)InventoryStackRecord::RoundToNearestStep(1.0f * (*(unsigned int*)((char*)pUserOption + 0x20) - 1), 1.0f);
    }
}
}  // namespace fnv_007d2c10

namespace fnv_007d2d30 {
struct UserOptionStandIn
{
    void** m_ppVirtualMethodTable;           // +0x0
    const char* pText;         // +0x4
    void* pCallback;           // +0x8
    unsigned int uiFlags;      // +0xC
    const char* pTemplate;     // +0x10
    int iOptionId;             // +0x14
    int iDefaultValue;         // +0x18
    int iType;                 // +0x1C
    unsigned int uiNumValues;  // +0x20
};
class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    void FUN_00ad7c00(float);
    float GetMusicVolume();
};
class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};
class S_004ed780
{
  public:
    GlobalObject_0044f440* FUN_004ed780(float);
};
extern S_004ed780 g_011f6e50;
extern StartMenu* DAT_011daac0;

// @fnv 0x007d2d30
void FUN_007d2d30(UserOptionStandIn* pOption)
{
    if (pOption == 0)
    {
        BSAudio::GetSingleton()->FUN_00ad7c00(((GlobalObject_0044f440*)&g_011f6e50)->FUN_00450410());
    }
    else if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        BSAudio::GetSingleton()->FUN_00ad7c00(
            g_011f6e50.FUN_004ed780((float)pOption->iOptionId / (pOption->uiNumValues - 1))->FUN_00450410());
    }
    else
    {
        pOption->iOptionId = (int)InventoryStackRecord::RoundToNearestStep(
            BSAudio::GetSingleton()->GetMusicVolume() * (pOption->uiNumValues - 1), 1.0f);
        pOption->iDefaultValue = (int)InventoryStackRecord::RoundToNearestStep((pOption->uiNumValues - 1) * 0.5, 1.0f);
    }
}
}  // namespace fnv_007d2d30

struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
struct Interface
{
    static bool __cdecl ShowButtonDialog(const char*, const char*, const char*, void(__cdecl*)(), int, int, float,
                                         float, ...);
};
struct SaveEntryStandIn
{
    bool IsSaveEntryValid();
    bool LoadSaveEntry();
};
struct SaveEntryNode
{
    SaveEntryStandIn** FUN_006815c0();
};
struct SaveListPointer
{
    operator SaveEntryNode*() const;
};
struct SaveLoadManagerStandIn : SaveListPointer
{
    void FUN_00851330();
};
extern SaveLoadManagerStandIn* DAT_011de134;
extern InventoryMenuSetting g_011d1f14;
extern InventoryMenuSetting g_011d38b8;
extern InventoryMenuSetting g_011d48ac;
void __cdecl FUN_00af59e0();
void HandleBackAction();

// @fnv 0x007d3190
void HandleSaveLoadMenuAction()
{
    if (!(SaveEntryNode*)*DAT_011de134 || !*((SaveEntryNode*)*DAT_011de134)->FUN_006815c0())
        DAT_011de134->FUN_00851330();
    if ((SaveEntryNode*)*DAT_011de134 && *((SaveEntryNode*)*DAT_011de134)->FUN_006815c0())
    {
        if ((*((SaveEntryNode*)*DAT_011de134)->FUN_006815c0())->IsSaveEntryValid())
        {
            Interface::ShowButtonDialog(g_011d1f14.FUN_00403df0(), 0, 0, 0, 0, 5, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                                        0);
        }
        else
        {
            FUN_00af59e0();
            (*((SaveEntryNode*)*DAT_011de134)->FUN_006815c0())->LoadSaveEntry();
        }
    }
    else
    {
        Interface::ShowButtonDialog(g_011d48ac.FUN_00403df0(), 0, 0, 0, 0, 5, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(), 0);
    }
    HandleBackAction();
}

namespace fnv_007d3aa0 {
typedef void(__cdecl* UserOptionCallback)(StartMenu::UserOption*);
struct UserOptionArray
{
    unsigned int FUN_0044ddc0();
    StartMenu::UserOption** FUN_00877a30(unsigned int);
};
extern UserOptionArray g_011dab50;
void __cdecl FUN_007d19c0(StartMenu::UserOption*);
struct StartMenu_Wrap : StartMenu
{
    void FUN_0075f6f0(StartMenu::Flag, bool);
    void ApplyUserOptions();
};

// Clears FLAG_SAVE_OPTIONS, invokes each user option's callback, stores the option whose callback is FUN_007d19c0 at this+0x1b4, then sets the flag.
// @fnv 0x007d3aa0
void StartMenu_Wrap::ApplyUserOptions()
{
    FUN_0075f6f0(FLAG_SAVE_OPTIONS, false);
    for (int i = 0; i < g_011dab50.FUN_0044ddc0(); i++)
    {
        if (*(UserOptionCallback*)((char*)*g_011dab50.FUN_00877a30(i) + 0x2c))
            (*(UserOptionCallback*)((char*)*g_011dab50.FUN_00877a30(i) + 0x2c))(*g_011dab50.FUN_00877a30(i));
        if (*(UserOptionCallback*)((char*)*g_011dab50.FUN_00877a30(i) + 0x2c) == FUN_007d19c0)
            *(StartMenu::UserOption**)((char*)this + 0x1b4) = *g_011dab50.FUN_00877a30(i);
    }
    FUN_0075f6f0(FLAG_SAVE_OPTIONS, true);
}
}  // namespace fnv_007d3aa0

namespace fnv_007d5f50 {
struct StartMenuStandIn
{
    void FUN_0075f6f0(int, int);
};

void __cdecl ClearAllElements();
void __cdecl FUN_00704000();
void __cdecl HandleBackAction();

// @fnv 0x007d5f50
void FUN_007d5f50()
{
    extern StartMenuStandIn* DAT_011daac0;
    DAT_011daac0->FUN_0075f6f0(0x8000000, 0);
    ClearAllElements();
    FUN_00704000();
    HandleBackAction();
}
}  // namespace fnv_007d5f50

bool __cdecl FUN_004b71d0(void);
struct HotkeyWheelDisplay
{
    int DispatchByType(int key);
};
struct OSGlobals
{
    HotkeyWheelDisplay* FUN_00877720(void);
};
extern OSGlobals* g_osGlobals;
struct FUN_007d6030_shell
{
    char _base[0x1c8];
    int iKey;
    bool IsKeyActive();
};
// Returns false for key 0xff; otherwise checks FUN_004b71d0 and compares iKey to 3 or queries the OS globals key lookup.
// @fnv 0x007d6030
bool FUN_007d6030_shell::IsKeyActive()
{
    if (iKey == 0xff)
        return false;
    else if (FUN_004b71d0())
        return iKey == 3;
    else
        return iKey != 3 && g_osGlobals->FUN_00877720()->DispatchByType(iKey);
}

struct FUN_007d6120_Class
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28;
    int m_2c;
    int FUN_007d6120();
};
// @fnv 0x007d6120
int FUN_007d6120_Class::FUN_007d6120()
{
    return m_2c != 0;
}

struct FUN_007d6140_Class
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
    int m_0x30;
    int FUN_007d6140();
};
// @fnv 0x007d6140
int FUN_007d6140_Class::FUN_007d6140()
{
    return m_0x30 != 0;
}

namespace fnv_007d69d0 {
struct StartMenuStandIn
{
    void FUN_0075f6f0(int, int);
};
extern StartMenuStandIn* DAT_011daac0;

// @fnv 0x007d69d0
void FUN_007d69d0()
{
    if (DAT_011daac0)
        DAT_011daac0->FUN_0075f6f0(0x800, 1);
}
}  // namespace fnv_007d69d0

namespace fnv_007d6c90 {
enum MEDIATYPE
{
};
class TESGlobal
{
  public:
    void SetValue(float);
};
class LoadingMenu
{
  public:
    static void __cdecl UpdateLoadingScreenThread();
};
class FalloutAudioMedia
{
  public:
    static void __cdecl PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static void __cdecl EndMediaUpdate();
    static bool __cdecl IsMediaPlaying(MEDIATYPE, bool);
};
void* memset(void*, int, unsigned int);
int _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl FUN_00761460(bool);
extern TESGlobal* DAT_011c3f3c;
extern bool DAT_011daacd;
struct StartMenu_Wrap : StartMenu
{
    void FUN_0075f6f0(StartMenu::Flag, bool);
    void FUN_007d6c90();
};

// @fnv 0x007d6c90
void StartMenu_Wrap::FUN_007d6c90()
{
    char szMusicPath[64];
    if (IsFlagSet(FLAG_INGAME))
        return;
    if (FalloutAudioMedia::IsMediaPlaying((MEDIATYPE)8, true))
    {
        memset(szMusicPath, 0, 64);
        _sprintf_s(szMusicPath, 64, "Data\\Music\\Special\\MainTitle.mp3");
        FUN_00761460(true);
        FalloutAudioMedia::PlayMedia((MEDIATYPE)8, szMusicPath, 1000, true, true, 0.0f, 0);
        FalloutAudioMedia::EndMediaUpdate();
    }
    FUN_0075f6f0(FLAG_FADE_IN, true);
    FUN_0075f6f0(FLAG_SHOWING_CREDITS, false);
    DAT_011daacd = true;
    DAT_011c3f3c->SetValue(0.0f);
    LoadingMenu::UpdateLoadingScreenThread();
}
}  // namespace fnv_007d6c90

namespace fnv_007d6d70 {
struct TgtOps
{
    const char* GetPosition();
};
struct SettingCollectionStandIn
{
    bool FUN_005e01b0(const char*);
};
SettingCollectionStandIn* __cdecl FUN_0045d180();
struct INIPrefSettingCollectionHelper
{
    static SettingCollectionStandIn* __cdecl GetCollection();
};
struct SettingString
{
    const char* GetString();
};
struct Interface
{
    static bool __cdecl ShowButtonDialog(const char*, const char*, const char*, void(__cdecl*)(), int, int, float,
                                         float, ...);
};
struct InputManagerStandIn
{
    void FUN_00a22e10();
};
class OSGlobals
{
  public:
    InputManagerStandIn* FUN_00877720();
};
struct SM7d6
{
    void FUN_0075f6f0(int, int);
};
extern OSGlobals* g_osGlobals;
extern StartMenu* DAT_011daac0;
extern SettingString g_011d3138;
extern SettingString g_011d38b8;
extern SettingString g_011d493c;

// @fnv 0x007d6d70
void FUN_007d6d70()
{
    FUN_0045d180()->FUN_005e01b0(((TgtOps*)FUN_0045d180())->GetPosition());
    if (INIPrefSettingCollectionHelper::GetCollection()->FUN_005e01b0(
            ((TgtOps*)INIPrefSettingCollectionHelper::GetCollection())->GetPosition()))
    {
        g_osGlobals->FUN_00877720()->FUN_00a22e10();
        if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_RESTART_REQUIRED))
        {
            Interface::ShowButtonDialog(g_011d493c.GetString(), 0, 0, 0, 0, 0x12, 0.0f, 0.0f, g_011d38b8.GetString(),
                                        0);
            ((SM7d6*)DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_RESTART_REQUIRED, 0);
        }
    }
    else
    {
        Interface::ShowButtonDialog(g_011d3138.GetString(), 0, 0, 0, 0, 0x12, 0.0f, 0.0f, g_011d38b8.GetString(), 0);
    }
}
}  // namespace fnv_007d6d70

extern bool DAT_011a0294;

// @fnv 0x007d6e60
bool __cdecl FUN_007d6e60()
{
    return DAT_011a0294;
}

namespace fnv_007d7aa0 {
class Tile
{
  public:
    bool ContainsTrait(int);
};
int __cdecl GetTileValueID(const char*, int);
class ListBoxBase
{
  public:
    virtual ~ListBoxBase();
    BSSimpleList<Tile*> xList;
};
struct ListBox_Option : ListBoxBase
{
    bool IsSelected(Tile* apSelectItem);
};

// Returns true when the _selected trait index is set and apSelectItem has that trait.
// @fnv 0x007d7aa0
bool ListBox_Option::IsSelected(Tile* apSelectItem)
{
    static int iSelectedTrait = GetTileValueID("_selected", -1);
    return iSelectedTrait && apSelectItem && apSelectItem->ContainsTrait(iSelectedTrait);
}
}  // namespace fnv_007d7aa0

namespace fnv_007d7bd0 {
class Tile
{
  public:
    void Set(int, int);
};
int __cdecl GetTileValueID(const char*, int);
class ListBoxBase
{
  public:
    virtual ~ListBoxBase();
    BSSimpleList<Tile*> xList;
};
struct ListBox_int : ListBoxBase
{
    Tile* m_pListTile;
    void FUN_007d7bd0(bool abVal);
};

// Sets the _enabled trait on the list box's tile to abVal, caching the trait index in a static.
// @fnv 0x007d7bd0
void ListBox_int::FUN_007d7bd0(bool abVal)
{
    static int iEnabledTrait = GetTileValueID("_enabled", -1);
    m_pListTile->Set(iEnabledTrait, abVal);
}
}  // namespace fnv_007d7bd0

namespace fnv_007d80f0 {
struct TGF
{
    float GetFloat(int);
};
struct ListBoxItemStandIn
{
    TGF* pTile;
};
struct ListBoxItemList
{
    ListBoxItemStandIn* m_item;
    ListBoxItemList* m_pkNext;
    bool FUN_008256d0() const;
    ListBoxItemStandIn** FUN_006815c0() const;
    const ListBoxItemList* FUN_00726070() const;
};
struct ListBoxBase
{
    virtual ~ListBoxBase();
};
struct ListBoxSaveLoad : ListBoxBase, ListBoxItemList
{
    bool RemoveItemNode(const ListBoxItemList* pnode, const ListBoxItemList* plast);
    bool FUN_007d80f0(unsigned int aiIndex, bool abLiteral);
};

// @fnv 0x007d80f0
bool ListBoxSaveLoad::FUN_007d80f0(unsigned int aiIndex, bool abLiteral)
{
    if (FUN_008256d0())
        return false;
    const ListBoxItemList* pnode = this;
    const ListBoxItemList* plast = this;
    if (abLiteral)
    {
        unsigned int i = 0;
        while (pnode && i++ != aiIndex)
        {
            plast = pnode;
            pnode = pnode->FUN_00726070();
        }
    }
    else
    {
        while (pnode && (*pnode->FUN_006815c0())->pTile->GetFloat(0xfac) != aiIndex)
        {
            plast = pnode;
            pnode = pnode->FUN_00726070();
        }
    }
    return RemoveItemNode(pnode, plast);
}
}  // namespace fnv_007d80f0

namespace fnv_007d8f10 {
class Tile
{
  public:
    void Set(int, int);
};
class ListBoxBase
{
  public:
    virtual ~ListBoxBase();
};
struct ListBoxItem_Option
{
    Tile* pTile;
    void* pObject;
    bool m_bFiltered;
};
struct ListBoxNode_Option
{
    ListBoxItem_Option** FUN_006815c0();
    ListBoxNode_Option* FUN_00726070();
    ListBoxItem_Option* pItem;
    ListBoxNode_Option* pNext;
};
struct ListBox_Option : ListBoxBase, ListBoxNode_Option
{
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    void AccumulateTileHeight(Tile*);
    void UpdateHighlightBox();
    void FUN_007d9460();
    void UpdateItemTiles();
};

// @fnv 0x007d8f10
void ListBox_Option::UpdateItemTiles()
{
    m_usSelectedIndex = 0;
    m_fFirstListValue = 0.0f;
    ListBoxNode_Option* pnode;
    for (pnode = this; pnode && *pnode->FUN_006815c0(); pnode = pnode->FUN_00726070())
    {
        if (!(*pnode->FUN_006815c0())->m_bFiltered)
        {
            (*pnode->FUN_006815c0())->pTile->Set(0xfac, m_usSelectedIndex++);
            AccumulateTileHeight((*pnode->FUN_006815c0())->pTile);
        }
    }
    FUN_007d9460();
    UpdateHighlightBox();
}
}  // namespace fnv_007d8f10

namespace fnv_007d9590 {
class BGSSaveLoadFileEntry;
class Tile
{
  public:
    void Set(int, int);
};
class ListBoxBase
{
  public:
    virtual ~ListBoxBase();
};
struct ListBoxItem_SaveLoad
{
    Tile* pTile;
    BGSSaveLoadFileEntry* pObject;
    bool m_bFiltered;
};
struct ListBoxNode_SaveLoad
{
    ListBoxItem_SaveLoad** FUN_006815c0();
    ListBoxNode_SaveLoad* FUN_00726070();
    ListBoxItem_SaveLoad* pItem;
    ListBoxNode_SaveLoad* pNext;
};
struct ListBox_SaveLoad : ListBoxBase, ListBoxNode_SaveLoad
{
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    void AccumulateTileHeight(Tile*);
    void FUN_007d97a0();
    void FUN_007d9d50();
    void UpdateSaveLoadList();
};

// @fnv 0x007d9590
void ListBox_SaveLoad::UpdateSaveLoadList()
{
    m_usSelectedIndex = 0;
    m_fFirstListValue = 0.0f;
    ListBoxNode_SaveLoad* pnode;
    for (pnode = this; pnode && *pnode->FUN_006815c0(); pnode = pnode->FUN_00726070())
    {
        if (!(*pnode->FUN_006815c0())->m_bFiltered)
        {
            (*pnode->FUN_006815c0())->pTile->Set(0xfac, m_usSelectedIndex++);
            AccumulateTileHeight((*pnode->FUN_006815c0())->pTile);
        }
    }
    FUN_007d9d50();
    FUN_007d97a0();
}
}  // namespace fnv_007d9590

namespace fnv_007d9ee0 {
class Tile
{
  public:
    float GetFloat(int);
};
int __cdecl GetTileValueID(const char*, int);
class ListBoxBase
{
  public:
    virtual ~ListBoxBase();
    BSSimpleList<Tile*> xList;
};
struct ListBox_Option : ListBoxBase
{
    Tile* m_pListTile;
    int GetRaceCount();
    unsigned int FUN_007d9ee0();
};

// @fnv 0x007d9ee0
unsigned int ListBox_Option::FUN_007d9ee0()
{
    static int iNumFilteredTrait = GetTileValueID("_num_filtered", -1);
    return GetRaceCount() - (unsigned int)m_pListTile->GetFloat(iNumFilteredTrait);
}
}  // namespace fnv_007d9ee0

struct HWND__;
extern "C" __declspec(dllimport) HWND__* __stdcall GetForegroundWindow();
struct DIGUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};
struct DIDATAFORMAT;
struct IDirectInputDevice8A
{
    virtual long __stdcall QueryInterface(const DIGUID& riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCapabilities(void* lpDIDevCaps) = 0;
    virtual long __stdcall EnumObjects(void* lpCallback, void* pvRef, unsigned long dwFlags) = 0;
    virtual long __stdcall GetProperty(const DIGUID& rguidProp, void* pdiph) = 0;
    virtual long __stdcall SetProperty(const DIGUID& rguidProp, const void* pdiph) = 0;
    virtual long __stdcall Acquire() = 0;
    virtual long __stdcall Unacquire() = 0;
    virtual long __stdcall GetDeviceState(unsigned long cbData, void* lpvData) = 0;
    virtual long __stdcall GetDeviceData(unsigned long cbObjectData, void* rgdod, unsigned long* pdwInOut,
                                         unsigned long dwFlags) = 0;
    virtual long __stdcall SetDataFormat(const DIDATAFORMAT* lpdf) = 0;
    virtual long __stdcall SetEventNotification(void* hEvent) = 0;
    virtual long __stdcall SetCooperativeLevel(HWND__* hwnd, unsigned long dwFlags) = 0;
};
struct IDirectInput8A
{
    virtual long __stdcall QueryInterface(const DIGUID& riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall CreateDevice(const DIGUID& rguid, IDirectInputDevice8A** lplpDirectInputDevice,
                                        void* pUnkOuter) = 0;
};
extern DIGUID DAT_01100f74;
extern DIDATAFORMAT DAT_01100aac;
struct MouseInputStandIn
{
    void RecreateDevice(bool abNonExclusive);
};

// Releases and recreates the DirectInput device, sets its cooperative level from abNonExclusive, updates the flags at offset 4, and applies the data format.
// @fnv 0x00a23c00
void MouseInputStandIn::RecreateDevice(bool abNonExclusive)
{
    if (!*(IDirectInputDevice8A**)((char*)this + 0x30))
        return;
    (*(IDirectInputDevice8A**)((char*)this + 0x30))->Unacquire();
    (*(IDirectInputDevice8A**)((char*)this + 0x30))->Release();
    IDirectInputDevice8A* pDevice;
    long hr = (*(IDirectInput8A**)((char*)this + 8))->CreateDevice(DAT_01100f74, &pDevice, 0);
    if (hr == 0)
    {
        *(IDirectInputDevice8A**)((char*)this + 0x30) = pDevice;
        if (abNonExclusive)
        {
            hr = (*(IDirectInputDevice8A**)((char*)this + 0x30))->SetCooperativeLevel(GetForegroundWindow(), 2 | 4);
            *(unsigned int*)((char*)this + 4) |= 8;
        }
        else
        {
            hr = (*(IDirectInputDevice8A**)((char*)this + 0x30))->SetCooperativeLevel(GetForegroundWindow(), 1 | 4);
            *(unsigned int*)((char*)this + 4) &= ~8;
        }
        switch (hr)
        {
        case (long)0x80070057L:
            hr = 1;
            break;
        case (long)0x80070015L:
            hr = 1;
            break;
        case (long)0x80070006L:
            hr = 1;
            break;
        }
        (*(IDirectInputDevice8A**)((char*)this + 0x30))->SetDataFormat(&DAT_01100aac);
    }
}

struct OSInputGlobalsStandIn
{
    bool BindInputKey(int aiControl, int aiDevice, unsigned char aucKey);
};

// Rejects certain device/key combinations, then stores aucKey at the device's aiControl slot, swapping any existing matching entry into that slot.
// @fnv 0x00a24fc0
bool OSInputGlobalsStandIn::BindInputKey(int aiControl, int aiDevice, unsigned char aucKey)
{
    if (aiDevice == 0 &&
        (aucKey == 1 || aucKey == 0x29 || aucKey == 0xb7 || aucKey == 2 || aucKey == 3 || aucKey == 4 || aucKey == 5 ||
         aucKey == 6 || aucKey == 7 || aucKey == 8 || aucKey == 9 || aucKey == 0x3b || aucKey == 0x3c ||
         aucKey == 0x3d || aucKey == 0x3e || aucKey == 0xc7 || aucKey == 0x2b))
        return false;
    if (aiDevice == 3 && aucKey != 8 && aucKey != 9 && aucKey != 0xa && aucKey != 0xb && aucKey != 0xc &&
        aucKey != 0xd && aucKey != 0xe && aucKey != 0xf && aucKey != 0x10 && aucKey != 7 && aucKey != 0x11)
        return false;
    for (int i = 0; i < 28; i++)
    {
        if (((unsigned char(*)[28])((char*)this + 0x1b94))[aiDevice][i] == aucKey)
        {
            ((unsigned char(*)[28])((char*)this + 0x1b94))[aiDevice][i] =
                ((unsigned char(*)[28])((char*)this + 0x1b94))[aiDevice][aiControl];
            break;
        }
    }
    ((unsigned char(*)[28])((char*)this + 0x1b94))[aiDevice][aiControl] = aucKey;
    return true;
}

struct FUN_007cf5c0_Class
{
    int a;
    int b;
    void Reset();
};

// @fnv 0x007cf5c0
void FUN_007cf5c0_Class::Reset()
{
    b = 0;
    a = 0;
}

namespace fnv_007d0700 {
struct VObj
{
    void FUN_007d74f0(int);
    void ForEachEntry(int);
};
struct MenuSI
{
    void FadeTile(int, int, unsigned int, float);
};
struct SM7d6
{
    void FadeTile(int, int, unsigned int, float);
};
SM7d6* DAT_011daac0;

// @fnv 0x007d0700
void FUN_007d0700()
{
    if (DAT_011daac0 != 0)
    {
        ((VObj*)((char*)DAT_011daac0 + 0xb4))->FUN_007d74f0(1);
        DAT_011daac0->FadeTile(1, 1, 0x80000000, -1.0f);
        ((VObj*)((char*)DAT_011daac0 + 0xb4))->ForEachEntry(1);
        DAT_011daac0->FadeTile(5, 1, 0x80000000, -1.0f);
    }
}
}  // namespace fnv_007d0700

namespace fnv_007d0bf0 {
struct BSAudio;

struct NiAVObject
{
    void SetAppCulled(bool);
};

struct NiNode
{
    NiAVObject* operator->()
    {
        return 0;
    }
};

struct TESResponse
{
    int GetNext(void);
};

struct Tile
{
    NiAVObject* FUN_0056c7f0(void);
};

struct IMH
{
    Tile* FUN_00586150(void);
    Tile* GetNext(void);
    void RenderMenu(int, int);
};

struct FUN_005b6cb0_Class
{
    void FUN_005b6cb0(void);
};

extern "C" void* __cdecl FUN_004b7210(void);
extern BSAudio* g_osGlobals;

// @fnv 0x007d0bf0
void FUN_007d0bf0()
{
    void* p = FUN_004b7210();
    ((IMH*)p)->FUN_00586150()->FUN_0056c7f0()->SetAppCulled(true);
    ((IMH*)p)->GetNext()->FUN_0056c7f0()->SetAppCulled(true);
    ((IMH*)p)->RenderMenu(0, 0);
    ((FUN_005b6cb0_Class*)g_osGlobals)->FUN_005b6cb0();
}
}  // namespace fnv_007d0bf0

namespace fnv_007d0c50 {
struct SM7d6
{
    void FUN_0075f6f0(int, int);
    void FUN_007d6160();
};

struct MenuSI
{
    void FadeTile(int, int, unsigned int, float);
};

struct FUN_007d6030_shell
{
    bool IsKeyActive();
};

extern SM7d6* DAT_011daac0;

// @fnv 0x007d0c50
void FUN_007d0c50()
{
    if (DAT_011daac0)
    {
        ((MenuSI*)DAT_011daac0)->FadeTile(2, 0, 0x80000000, -1.0f);
        DAT_011daac0->FUN_0075f6f0(0x1000, 1);
        if (!((FUN_007d6030_shell*)DAT_011daac0)->IsKeyActive())
            DAT_011daac0->FUN_007d6160();
    }
}
}  // namespace fnv_007d0c50

namespace fnv_007d0d40 {
struct VObj
{
    void FUN_007d74f0(int);
};
void VObj::FUN_007d74f0(int)
{}

struct SM7d6
{
    void PopulateList(int);
};

extern SM7d6* DAT_011daac0;

// If DAT_011daac0 is set, calls FUN_007d74f0(0) on the VObj at offset 0xb4 and then PopulateList(8) on DAT_011daac0.
// @fnv 0x007d0d40
void FUN_007d0d40()
{
    if (DAT_011daac0)
    {
        (reinterpret_cast<VObj*>(reinterpret_cast<char*>(DAT_011daac0) + 0xb4))->FUN_007d74f0(0);
        DAT_011daac0->PopulateList(8);
    }
}
}  // namespace fnv_007d0d40

extern void* _pme;

// Sets or clears bits in the flags field at offset 0x1c0 of _pme when _pme is non-null.
// @fnv 0x007d14c0
void FUN_007d14c0(int aFlags, int aSet)
{
    if (_pme)
    {
        if (aSet)
            *(int*)((char*)_pme + 0x1c0) |= aFlags;
        else
            *(int*)((char*)_pme + 0x1c0) &= ~aFlags;
    }
}

struct FUN_00b008d0_StandIn
{
    void* m_pUnk;
    void* FUN_00b008d0();
};

// @fnv 0x00b008d0
void* FUN_00b008d0_StandIn::FUN_00b008d0()
{
    return m_pUnk;
}

extern int DAT_01076ee0;

struct FUN_007ce690_cls
{
    int* p;
    void InitPointer();
};

// @fnv 0x007ce690
void FUN_007ce690_cls::InitPointer()
{
    p = &DAT_01076ee0;
}

struct FUN_007d1240_Class
{
    void __thiscall FUN_007d1240(int value);
};

// @fnv 0x007d1240
void __thiscall FUN_007d1240_Class::FUN_007d1240(int value)
{
    *(int*)((char*)this + 0x7b8) = value;
}

struct FUN_007d1320_Class
{
    void FUN_007d1320(int value);
};

// @fnv 0x007d1320
void FUN_007d1320_Class::FUN_007d1320(int value)
{
    *(int*)((char*)this + 0x7c0) = value;
}

unsigned int __cdecl gm_GetTickCount();

struct FUN_007d5120_Class
{
    unsigned int a;
    unsigned int b;
    void __thiscall FUN_007d5120();
};

// @fnv 0x007d5120
void __thiscall FUN_007d5120_Class::FUN_007d5120()
{
    a = gm_GetTickCount();
    b = 0;
}

struct FUN_007d6100_class
{
    unsigned int GetField18F4();
};

// @fnv 0x007d6100
unsigned int FUN_007d6100_class::GetField18F4()
{
    return *(unsigned int*)((char*)this + 0x18f4);
}

// Increments the integer pointed to by counter and wraps it back to 0 once it reaches 4.
// @fnv 0x007d61b0
int* AdvanceCounter(int* piCounter)
{
    *piCounter = *piCounter + 1;
    if (*piCounter >= 4)
        *piCounter = 0;
    return piCounter;
}

extern "C" void __cdecl _ref_008256d0();

struct FUN_007d6e70_class
{
    char pad[4];
    void __thiscall CallOnMemberAtOffset4();
};

// @fnv 0x007d6e70
void __thiscall FUN_007d6e70_class::CallOnMemberAtOffset4()
{
    ((void(__thiscall*)(void*))_ref_008256d0)((char*)this + 4);
}

struct WeatherEntry;
struct FUN_007d74c0_class
{
    void UpdateItemTiles();
    void SortWeatherEntries(int (*fn)(WeatherEntry*, WeatherEntry*));
};
// Sorts the WeatherEntry list at offset 4 using the given comparison function, then calls UpdateItemTiles.
// @fnv 0x007d74c0
void FUN_007d74c0_class::SortWeatherEntries(int (*fn)(WeatherEntry*, WeatherEntry*))
{
    ((BSSimpleList<WeatherEntry*>*)((char*)this + 4))->Sort(fn);
    UpdateItemTiles();
}

struct FUN_007d9000_shell
{
    void ApplySelectionAction(int a, int b);
};

struct FUN_007d8fe0_shell
{
    void FUN_007d8fe0(int a);
};

// @fnv 0x007d8fe0
void FUN_007d8fe0_shell::FUN_007d8fe0(int a)
{
    ((FUN_007d9000_shell*)this)->ApplySelectionAction(a, 1);
}

namespace fnv_007d64a0 {
extern "C" void __cdecl _Deallocate(void*);
void __cdecl Initialize();
struct FUN_007d64a0
{
    void Initialize();
    void* DeleteThis(unsigned int flags);
};
// Calls Initialize, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007d64a0
void* FUN_007d64a0::DeleteThis(unsigned int flags)
{
    Initialize();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_007d64a0

namespace fnv_007d6ff0 {
void* __cdecl operator new(unsigned int);
struct Tile
{
    struct Value;
    Value* GetValue(int);
    void Set(int, int);
    void Set(int, const char*, bool);
    Menu* GetMenu();
};
struct DebrisData;
struct AEList
{
    void Insert(DebrisData*, int(__cdecl*)(DebrisData*, DebrisData*));
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_007242c0_shell
{
    bool FUN_007242c0(unsigned int);
};
struct FUN_007254d0_t
{
    void AccumulateTileHeight(Tile*);
};
struct VATSMenu
{
    int GetSelectedTargetIndex();
};
struct FUN_007d74c0_class
{
    void UpdateItemTiles();
};
struct FUN_007a62e0
{
    int a;
    int b;
    int c;
    FUN_007a62e0(Tile*, int*);
};
struct FUN_00a1ddb0_shell
{
    Tile* AddTileFromTemplate(Tile*, const char*, Tile*);
};
struct TGF
{
    float GetFloat(int);
};
struct FUN_00a00e90_shell
{
    void* FindTraitValue(int);
};
struct P03Value
{
    void AppendFloatAction(int, float);
    void FUN_00a09130(int, Tile*, int);
    void RemoveFromReactions();
    void Refresh(int);
};
int __cdecl GetTileValueID(const char*, int);
extern double _gModifierZero;
extern const char _kListBoxNumFiltered[];

struct FUN_007d6ff0_shell
{
    int pad0;
    int list[2];
    Tile* pParent;
    int pad10;
    int pad14;
    const char* pcTemplate;
    unsigned short m_usPassCountLocal;
    Tile* CreateListItem(int aAssociatedData, const char* apcItemString,
                         int(__cdecl* apCompareFn)(DebrisData*, DebrisData*), const char* apcTemplateName);
    void FUN_007d9460();
};

// @fnv 0x007d6ff0
Tile* FUN_007d6ff0_shell::CreateListItem(int aAssociatedData, const char* apcItemString,
                                         int(__cdecl* apCompareFn)(DebrisData*, DebrisData*),
                                         const char* apcTemplateName)
{
    Tile* pTile;
    if (pParent && (pcTemplate || apcTemplateName))
    {
        pTile = ((FUN_00a1ddb0_shell*)pParent->GetMenu())
                    ->AddTileFromTemplate(pParent, apcTemplateName ? apcTemplateName : pcTemplate, 0);
        if (!pTile->GetValue(0xfaa))
            pTile->Set(0xfaa, -1);
        if (apcItemString)
            pTile->Set(0xfc4, apcItemString, true);
        if (apCompareFn)
        {
            ((AEList*)list)->Insert((DebrisData*)new FUN_007a62e0(pTile, &aAssociatedData), apCompareFn);
            if (((FUN_007242c0_shell*)this)->FUN_007242c0(0))
                ((FUN_007d74c0_class*)this)->UpdateItemTiles();
        }
        else
        {
            ((SoundListView*)list)->AddTail((char*)new FUN_007a62e0(pTile, &aAssociatedData));
            if (((FUN_007242c0_shell*)this)->FUN_007242c0(0))
            {
                ((FUN_007254d0_t*)this)->AccumulateTileHeight(pTile);
                FUN_007d9460();
            }
            pTile->Set(0xfac, m_usPassCountLocal++);
        }
        if (((VATSMenu*)this)->GetSelectedTargetIndex() == 1 &&
            ((TGF*)pParent)->GetFloat(GetTileValueID(_kListBoxNumFiltered, -1)) > _gModifierZero)
        {
            P03Value* pheight = (P03Value*)((FUN_00a00e90_shell*)pParent)->FindTraitValue(0xfb0);
            pheight->RemoveFromReactions();
            pheight->FUN_00a09130(0x7d0, pTile, 0xfb0);
            pheight->AppendFloatAction(0x7d3, ((TGF*)pParent)->GetFloat(GetTileValueID(_kListBoxNumFiltered, -1)));
            pheight->Refresh(0);
        }
        return pTile;
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_007d6ff0

namespace fnv_007ce7a0 {
struct FORenderedMenu
{
};
struct FOPipboyManager : public FORenderedMenu
{
    void FUN_007f7f40();
};
class Interface
{
  public:
    static FOPipboyManager* GetPipboyManagerInstance();
    static bool IsPipboyMenuOpen();
    static bool IsInDialog();
};
struct PlayerCharacterQ
{
    static bool UpdatePlayerStatus();
};
struct StartMenuQ
{
    bool IsStartMenuActive();
};
struct ListBoxQ
{
    void Traverse(void(__cdecl*)(Tile*, TESObjectREFR*), int, int);
};
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
    Tile*& GetNext(void*&);
};
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct FUN_00a1d910_shell
{
    void FUN_00a1d910();
};
class Main
{
  public:
    void RunFrame();
};
struct GlobalObject_0048f200;
extern GlobalObject_0048f200 g_011dabd8;
extern Main* g_osGlobals;
extern StartMenu* DAT_011daac0;
FORenderedMenu* __cdecl FUN_00707ad0();
void __cdecl SetDialogMenuActive(bool);
void __cdecl FUN_007aaf20(bool);
void __cdecl FUN_007ce970(Tile*, TESObjectREFR*);

// @fnv 0x007ce7a0
void CloseStartMenu(bool abDeleteOnFade)
{
    void* piter;
    if (PlayerCharacterQ::UpdatePlayerStatus() && FUN_00707ad0() &&
        FUN_00707ad0() == Interface::GetPipboyManagerInstance())
        Interface::GetPipboyManagerInstance()->FUN_007f7f40();
    if (!DAT_011daac0 || ((StartMenuQ*)DAT_011daac0)->IsStartMenuActive())
        return;
    if (Interface::IsInDialog())
        SetDialogMenuActive(false);
    if (!DAT_011daac0->IsFlagSet(StartMenu::FLAG_FORCE_RELOAD))
    {
        if (DAT_011daac0->IsFlagSet(StartMenu::FLAG_ACTION_MAPPING))
            ((ListBoxQ*)&DAT_011daac0->m_kDownloadOptions)->Traverse(FUN_007ce970, 0, 0x7fffffff);
        if (PlayerCharacterQ::UpdatePlayerStatus())
            FUN_007aaf20(false);
        piter = (void*)(unsigned int)*(Flt*)&g_011dabd8;
        while (piter)
            ((Tile_Set_Helper*)((TL*)&g_011dabd8)->GetNext(piter))->Set(4003, 1);
        ((Tile_Set_Helper*)DAT_011daac0->pMenu)->Set(6002, abDeleteOnFade);
        ((FUN_00a1d910_shell*)DAT_011daac0)->FUN_00a1d910();
        DAT_011daac0 = 0;
    }
    if (Interface::IsPipboyMenuOpen())
        g_osGlobals->RunFrame();
}
}  // namespace fnv_007ce7a0

class StartMenuUserOptionFields
{
  public:
    virtual ~StartMenuUserOptionFields();
    const char* pName;
    int m_uiSoundID;
    int iFlags;
    const char* pTemplateName;
    int iValue;
    int iSelected;
    int iType;
    unsigned int ItemUpdateArray;
};
class SettingFloat
{
  public:
    float* Float();
};
class ItemChangeStepRound
{
  public:
    static float __cdecl RoundToNearestStep(float afValue, float afStep);
};
struct StartMenuEx : StartMenu
{
    static float __cdecl FUN_007d1b30();
};
void __cdecl FUN_004dc2d0(float afValue);
extern SettingFloat g_011dab98;
extern SettingFloat g_011dab60;
extern StartMenu* DAT_011daac0;
// @fnv 0x007d19c0
void __cdecl FUN_007d19c0(StartMenu::UserOption* apOption)
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fMinimum = *g_011dab98.Float();
        float fScaledValue = *g_011dab60.Float();
        float fRatio = ((StartMenuUserOptionFields*)apOption)->iValue /
                       (float)(((StartMenuUserOptionFields*)apOption)->ItemUpdateArray - 1);
        FUN_004dc2d0((fScaledValue - fMinimum) * fRatio + fMinimum);
    }
    else
    {
        float fNormalizedPosition =
            (StartMenuEx::FUN_007d1b30() - *g_011dab98.Float()) / (*g_011dab60.Float() - *g_011dab98.Float());
        ((StartMenuUserOptionFields*)apOption)->iValue = (int)ItemChangeStepRound::RoundToNearestStep(
            (((StartMenuUserOptionFields*)apOption)->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
        fNormalizedPosition = (1.0f - *g_011dab98.Float()) / (*g_011dab60.Float() - *g_011dab98.Float());
        ((StartMenuUserOptionFields*)apOption)->iSelected = (int)ItemChangeStepRound::RoundToNearestStep(
            (((StartMenuUserOptionFields*)apOption)->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
    }
}

namespace fnv_007d20f0 {
class UserOptionView_007d20f0
{
  public:
    virtual ~UserOptionView_007d20f0();
    const char* pName;
    int m_uiSoundID;
    int iFlags;
    const char* pTemplateName;
    int iValue;
    int iSelected;
    int iType;
    unsigned int ItemUpdateArray;
};
class SettingFloat
{
  public:
    float* Float();
};
extern SettingFloat g_011c7294;
extern SettingFloat g_011c71b8;
extern SettingFloat g_011c7278;
extern SettingFloat g_011c7400;
extern SettingFloat DAT_011c7568;
class ItemChangeMath_007d20f0
{
  public:
    static float __cdecl RoundToNearestStep(float afValue, float afStep);
};
extern float DAT_011f944c;
extern float DAT_011f9450;
extern StartMenu* DAT_011daac0;
// @fnv 0x007d20f0
void __cdecl FUN_007d20f0(StartMenu::UserOption* apOption)
{
    float fLow = *g_011c7294.Float();
    float fHigh = *g_011c71b8.Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fRatio =
            ((UserOptionView_007d20f0*)apOption)->iValue / (float)(((UserOptionView_007d20f0*)apOption)->ItemUpdateArray - 1);
        float fGamma = (fHigh - fLow) * fRatio + fLow;
        *DAT_011c7568.Float() = fGamma;
        DAT_011f944c = fGamma;
        DAT_011f9450 = fGamma + *g_011c7400.Float();
    }
    else
    {
        float fNormalizedPosition = (*DAT_011c7568.Float() - fLow) / (fHigh - fLow);
        ((UserOptionView_007d20f0*)apOption)->iValue = (int)ItemChangeMath_007d20f0::RoundToNearestStep(
            (((UserOptionView_007d20f0*)apOption)->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
        fNormalizedPosition = (*g_011c7278.Float() - fLow) / (fHigh - fLow);
        ((UserOptionView_007d20f0*)apOption)->iSelected = (int)ItemChangeMath_007d20f0::RoundToNearestStep(
            (((UserOptionView_007d20f0*)apOption)->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
    }
}
}  // namespace fnv_007d20f0

class GammaOptionFields
{
  public:
    virtual ~GammaOptionFields();
    const char* pName;
    int m_uiSoundID;
    int iFlags;
    const char* pTemplateName;
    int iValue;
    int iSelected;
    int iType;
    unsigned int ItemUpdateArray;
};
class GammaSettingFloat
{
  public:
    float* Float();
};
extern GammaSettingFloat g_011c7294;
extern GammaSettingFloat g_011c71b8;
extern GammaSettingFloat g_011c7278;
extern GammaSettingFloat g_011c7400;
extern GammaSettingFloat DAT_011c7568;
class GammaStepRound
{
  public:
    static float __cdecl RoundToNearestStep(float afValue, float afStep);
};
extern float DAT_011f944c;
extern float DAT_011f9450;
extern StartMenu* DAT_011daac0;
// @fnv 0x007d2250
void __cdecl FUN_007d2250(StartMenu::UserOption* apOption)
{
    float fLow = *g_011c7294.Float();
    float fHigh = *g_011c71b8.Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fRatio = ((GammaOptionFields*)apOption)->iValue / (float)(((GammaOptionFields*)apOption)->ItemUpdateArray - 1);
        float fGamma = (fHigh - fLow) * fRatio + fLow;
        *DAT_011c7568.Float() = fGamma;
        DAT_011f944c = fGamma;
        DAT_011f9450 = fGamma + *g_011c7400.Float();
    }
    else
    {
        float fNormalizedPosition = (*DAT_011c7568.Float() - fLow) / (fHigh - fLow);
        ((GammaOptionFields*)apOption)->iValue = (int)GammaStepRound::RoundToNearestStep(
            (((GammaOptionFields*)apOption)->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
        fNormalizedPosition = (*g_011c7278.Float() - fLow) / (fHigh - fLow);
        ((GammaOptionFields*)apOption)->iSelected = (int)GammaStepRound::RoundToNearestStep(
            (((GammaOptionFields*)apOption)->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
    }
}

class UserOptionView_007d23b0
{
  public:
    virtual ~UserOptionView_007d23b0();
    const char* pName;
    int m_uiSoundID;
    int iFlags;
    const char* pTemplateName;
    int iValue;
    int iSelected;
    int iType;
    unsigned int ItemUpdateArray;
};
class SettingFloat_007d23b0
{
  public:
    float* Float();
};
extern SettingFloat_007d23b0 g_011c7440;
extern SettingFloat_007d23b0 g_011c71d0;
extern SettingFloat_007d23b0 g_011c7494;
extern SettingFloat_007d23b0 g_011c7634;
extern SettingFloat_007d23b0 DAT_011c7598;
class ItemChange_007d23b0
{
  public:
    static float __cdecl RoundToNearestStep(float afValue, float afStep);
};
extern float DAT_011f9454;
extern float DAT_011f9458;
extern StartMenu* DAT_011daac0;
// @fnv 0x007d23b0
void __cdecl FUN_007d23b0(UserOptionView_007d23b0* apOption)
{
    float fLow = *g_011c7440.Float();
    float fHigh = *g_011c71d0.Float();
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_OPTIONS))
    {
        float fRatio = apOption->iValue / (float)(apOption->ItemUpdateArray - 1);
        float fGamma = (fHigh - fLow) * fRatio + fLow;
        *DAT_011c7598.Float() = fGamma;
        DAT_011f9454 = fGamma;
        DAT_011f9458 = fGamma + *g_011c7634.Float();
    }
    else
    {
        float fNormalizedPosition = (*DAT_011c7598.Float() - fLow) / (fHigh - fLow);
        apOption->iValue =
            (int)ItemChange_007d23b0::RoundToNearestStep((apOption->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
        fNormalizedPosition = (*g_011c7494.Float() - fLow) / (fHigh - fLow);
        apOption->iSelected =
            (int)ItemChange_007d23b0::RoundToNearestStep((apOption->ItemUpdateArray - 1) * fNormalizedPosition, 1.0f);
    }
}

struct TESForm
{
    virtual ~TESForm();
    int GetFormType() const;
    static TESForm* GetFormByID(unsigned int auiFormID);
};
struct TESBoundObject : public TESForm
{
};
struct TESQuest : public TESForm
{
    void SetEnabled(bool abEnabled);
};
struct TESNPC : public TESBoundObject
{
};
struct TESFullNameSetFullNameAccess
{
    void SetFullName(const char* apName);
};
struct Tile_r7d32b0
{
    void Set(int aiID, int aiValue);
};
struct PC_r7d32b0
{
    void FUN_005d1530(bool abFlag);
    void FUN_005d14d0(bool abFlag);
    void SetAllow(bool abFlag);
    TESBoundObject* GetNext();
};
struct PC7d;
extern PC7d* g_thePlayer;
void __cdecl HandleBackAction();
BGSSaveLoadUI* __cdecl FUN_00a25920();
struct MenuSetting_r7d32b0
{
    const char* FUN_00403df0();
};
struct SettingString
{
    char* GetString();
};
extern MenuSetting_r7d32b0 g_011dac00;
extern SettingString g_011d4f78;
extern bool DAT_011d8907;
struct BSSystemUtilityHelper
{
    static StartMenu* s_iUpdateEnabled;
};
class Interface_r7d32b0
{
  public:
    static void __cdecl PrintDebugMessage();
};
struct FalloutAudioMedia
{
    static void __cdecl BeginMediaUpdate();
};
struct TutorialState
{
    bool ShowMessage(int aiType, int aiMessage, unsigned int auiFlags);
};
class InterfaceManager;
InterfaceManager* __cdecl FUN_004b7210(void);
unsigned int __cdecl FUN_00ec8d08(const char* apString, char** appEnd, int aiRadix);
void __cdecl CloseStartMenu(int aiReason);
void __cdecl FUN_00af59e0();
void __cdecl FUN_004581c0(bool abFlag);
void __cdecl FUN_00761460(bool abFlag);
void __cdecl FUN_00788a90(unsigned char aucFlag);
int __cdecl Warning(const char* apFormat, ...);
// @fnv 0x007d32b0
void __cdecl StartCharacterGeneration()
{
    TESQuest* pcharGenQuest;
    char* pstopString;
    unsigned int icharGenQuest = FUN_00ec8d08(g_011dac00.FUN_00403df0(), &pstopString, 16);
    TESForm* pform = TESForm::GetFormByID(icharGenQuest);
    TESNPC* pplayerBase;
    pcharGenQuest = 0;
    if (g_thePlayer)
    {
        ((PC_r7d32b0*)g_thePlayer)->FUN_005d1530(false);
        ((PC_r7d32b0*)g_thePlayer)->FUN_005d14d0(true);
    }
    if (pform && pform->GetFormType() == 0x47)
        pcharGenQuest = dynamic_cast<TESQuest*>(pform);
    if (pcharGenQuest)
    {
        CloseStartMenu(0);
        FUN_00af59e0();
        DAT_011d8907 = true;
        ((PC_r7d32b0*)g_thePlayer)->SetAllow(false);
        pplayerBase = dynamic_cast<TESNPC*>(((PC_r7d32b0*)g_thePlayer)->GetNext());
        ((TESFullNameSetFullNameAccess*)((char*)pplayerBase + 0xd0))->SetFullName(g_011d4f78.GetString());
        pcharGenQuest->SetEnabled(true);
        ((Tile_r7d32b0*)BSSystemUtilityHelper::s_iUpdateEnabled->m_pTiles[11])->Set(0xfa3, 1);
        FUN_004581c0(true);
        Interface_r7d32b0::PrintDebugMessage();
        FUN_00761460(false);
        FalloutAudioMedia::BeginMediaUpdate();
        if (FUN_00a25920())
        {
            FUN_00a25920()->FUN_007d0bd0(true);
            FUN_00a25920()->FUN_007d0bb0();
        }
        FUN_00788a90(1);
        ((TutorialState*)((char*)FUN_004b7210() + 0x4d4))->ShowMessage(0x19, 0x3eb, 0x200);
        ((TutorialState*)((char*)FUN_004b7210() + 0x4d4))->ShowMessage(0x1a, 0x3ff, 0x200);
    }
    else
    {
        Warning("QUESTS: Unable to find character generation quest \x27%s\x27.", g_011dac00.FUN_00403df0());
        HandleBackAction();
    }
}

struct FUN_007ce620
{
    FUN_007ce620(const char* apName, int aiUnused, int aiID);
    virtual ~FUN_007ce620();
    const char* pName;
    int m_uiSoundID;
    int iFlags;
    const char* pTemplateName;
};
struct FUN_007d6350 : FUN_007ce620
{
    FUN_007d6350(const char* apName, void* apCallback, int aiID, int aiType, unsigned int auiCount, int aiDefault, ...);
    virtual ~FUN_007d6350();
    int iValue;
    int iSelected;
    int iType;
    unsigned int ItemUpdateArray;
    int iDefault;
    int* pValues;
    void* pCallback;
};
// Constructs a list-box entry: stores type, count, default and callback, then allocates and fills pValues for toggle types or clears it for meter types.
// @fnv 0x007d6350
FUN_007d6350::FUN_007d6350(const char* apName, void* apCallback, int aiID, int aiType, unsigned int auiCount,
                           int aiDefault, ...)
    : FUN_007ce620(apName, 0, aiID)
{
    iValue = 0;
    iSelected = 0;
    iType = aiType;
    ItemUpdateArray = auiCount;
    iDefault = aiDefault;
    pCallback = apCallback;
    switch (aiType)
    {
    case 0:
    case 1: {
        pTemplateName = "lb_toggle_template";
        pValues = new int[ItemUpdateArray];
        char* args = (char*)&aiDefault + sizeof(int);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
            pValues[i] = *(int*)((args += sizeof(int)) - sizeof(int));
        args = 0;
    }
    break;
    case 2:
        pTemplateName = "lb_meter_template";
        pValues = 0;
        break;
    }
}

namespace fnv_007d67b0 {
struct Tile
{
    bool ContainsTrait(int aiID);
    void Set(int aiID, int aiValue);
    void Set(int aiID, const char* apValue, bool abPropagate);
};
int __cdecl GetTileValueID(const char* apName, int aiIndex);
struct BSStringHelper
{
    operator const char*() const;
};
struct SaveLoadEntryHelper
{
    bool IsLegacyAutosaveFileName();
    bool FUN_00846ad0();
    bool IsAutoSave();
    bool IsSaveEntryValid();
    int FUN_007d6950();
    const char* FUN_007d6970();
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting g_011d3f10;
extern InventoryMenuSetting g_011d4e1c;
extern InventoryMenuSetting g_011d4e04;
extern InventoryMenuSetting g_011d46e4;
// @fnv 0x007d67b0
void __cdecl InitSaveLoadTile(Tile* apTile, BGSSaveLoadFileEntry* apSaveGame)
{
    if (apTile && apSaveGame && !apTile->ContainsTrait(GetTileValueID("_initialized", -1)))
    {
        if (((SaveLoadEntryHelper*)apSaveGame)->IsLegacyAutosaveFileName())
            apTile->Set(0x1004, g_011d3f10.FUN_00403df0(), true);
        else if (((SaveLoadEntryHelper*)apSaveGame)->FUN_00846ad0())
            apTile->Set(0x1004, g_011d4e1c.FUN_00403df0(), true);
        else if (((SaveLoadEntryHelper*)apSaveGame)->IsAutoSave())
            apTile->Set(0x1004, g_011d4e04.FUN_00403df0(), true);
        else
        {
            BSStringT<char> strName;
            strName.PrintfString("#%04d", ((SaveLoadEntryHelper*)apSaveGame)->FUN_007d6950());
            apTile->Set(0x1004, *(BSStringHelper*)&strName, true);
        }
        apTile->Set(0x1005,
                    ((SaveLoadEntryHelper*)apSaveGame)->IsSaveEntryValid()
                        ? g_011d46e4.FUN_00403df0()
                        : ((SaveLoadEntryHelper*)apSaveGame)->FUN_007d6970(),
                    true);
        apTile->Set(GetTileValueID("_initialized", -1), 1);
    }
}
}  // namespace fnv_007d67b0

namespace fnv_007190a0 {
struct SystemColor
{
    virtual void v0();
    virtual void* v1();
};
struct SystemColorManager
{
    SystemColor* Find(int);
};
struct FUN_007190a0_shell : SystemColorManager
{
    void* FUN_007190a0(int);
};
// Looks up a SystemColor by id and returns the result of its v1() virtual call, or null if not found.
// @fnv 0x007190a0
void* FUN_007190a0_shell::FUN_007190a0(int aiColorId)
{
    SystemColor* c = Find(aiColorId);
    return c ? c->v1() : 0;
}
}  // namespace fnv_007190a0

namespace fnv_007d0440 {
bool FUN_0070edf0();
void CloseStartMenu(int);
struct GlobalObject_0040c150
{
    const char* GetMenuTitle();
};
extern GlobalObject_0040c150 g_011d2be0;
struct Tile
{
    void Set(int, const char*, bool);
};
struct S7d8
{
    void FUN_007d48a0(void*, unsigned char);
};
struct SM7d6
{
    Tile* GetTile();
    S7d8* GetS7d8();
};
extern SM7d6* DAT_011daac0;

// @fnv 0x007d0440
void FUN_007d0440()
{
    if (FUN_0070edf0())
    {
        (*(Tile**)((char*)DAT_011daac0 + 0x48))->Set(0xfc4, g_011d2be0.GetMenuTitle(), true);
        ((S7d8*)DAT_011daac0)->FUN_007d48a0((void*)0x100, 0);
    }
    else
    {
        CloseStartMenu(1);
    }
}
}  // namespace fnv_007d0440

struct FUN_007d09c0_t
{
    unsigned int m_000[0x29];
    int FindIndexByValue(int value);
};

// Scans the 0x29 entries for one whose bits 2-7 plus 0x3e9 equal value and returns the matching index, or 0x29 if none match.
// @fnv 0x007d09c0
int FUN_007d09c0_t::FindIndexByValue(int value)
{
    int i;
    for (i = 0; i < 0x29; ++i)
    {
        if ((m_000[i] >> 2 & 0x3f) + 0x3e9 == value)
            break;
    }
    return i;
}

namespace fnv_007d0a10 {
struct TileStandIn
{
    void Set(int, const char*, bool);
};
struct GlobalObject_0040c150
{
    const char* GetMenuTitle();
};
extern GlobalObject_0040c150 g_011d3984;
struct PlayerCharacterStandIn
{
    static bool UpdatePlayerStatus();
};
struct S7d8
{
    void FUN_007d48a0(void*, unsigned char);
};
struct SM7d6
{
    char pad[0x48];
    TileStandIn* m_pTiles;
};
extern SM7d6* DAT_011daac0;
// @fnv 0x007d0a10
void FUN_007d0a10()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->m_pTiles->Set(0xfc4, g_011d3984.GetMenuTitle(), true);
        if (PlayerCharacterStandIn::UpdatePlayerStatus())
            ((S7d8*)DAT_011daac0)->FUN_007d48a0((void*)0x2000, 3);
        else
            ((S7d8*)DAT_011daac0)->FUN_007d48a0((void*)0x1000, 1);
    }
}
}  // namespace fnv_007d0a10

namespace fnv_007d0d70 {
struct Tile
{
    void Set(int, int);
};
struct VObj
{
    void FUN_007d74f0(int);
};
struct SM7d6
{
    void PopulateList(int);
    Tile* m_pTiles[21];
};
extern SM7d6* DAT_011daac0;

// If DAT_011daac0 is set, sets tile slot 20 to 0xfa3/1, calls FUN_007d74f0(0) on the object at offset 0xb4, and calls PopulateList(0x10).
// @fnv 0x007d0d70
void FUN_007d0d70()
{
    if (DAT_011daac0)
    {
        DAT_011daac0->m_pTiles[20]->Set(0xfa3, 1);
        ((VObj*)((char*)DAT_011daac0 + 0xb4))->FUN_007d74f0(0);
        DAT_011daac0->PopulateList(0x10);
    }
}
}  // namespace fnv_007d0d70

namespace fnv_007d0df0 {
struct Tile
{
    void Set(int, int);
};
struct VObj
{
    void FUN_007d74f0(int);
};
struct StartMenuStub
{
    void PopulateList(int);
    char pad[0x64];
    Tile* tiles;
};
extern StartMenuStub* DAT_011daac0;

// @fnv 0x007d0df0
void FUN_007d0df0()
{
    if (DAT_011daac0)
    {
        ((VObj*)((char*)DAT_011daac0 + 0xb4))->FUN_007d74f0(0);
        DAT_011daac0->tiles->Set(0x1004, 0);
        DAT_011daac0->PopulateList(0x40);
    }
}
}  // namespace fnv_007d0df0

namespace fnv_007d12d0 {
struct FUN_007d1320_Class
{
    void FUN_007d1320(int);
};
struct VATS
{
    void Update(int, bool);
};
struct FUN_007d1360_Class
{
    unsigned char FUN_007d1360();
};
struct FUN_007d12d0_Class : PlayerCharacter
{
    void FUN_007d12d0(int arg);
};
// @fnv 0x007d12d0
void FUN_007d12d0_Class::FUN_007d12d0(int arg)
{
    int oldValue = FUN_007d1340();
    ((FUN_007d1320_Class*)this)->FUN_007d1320(arg);
    if (oldValue != FUN_007d1340() && ((FUN_007d1360_Class*)this)->FUN_007d1360())
        ((VATS*)this)->Update(oldValue, true);
}
}  // namespace fnv_007d12d0

namespace fnv_007d60b0 {
struct FUN_007d6100_class
{
    unsigned int GetField18F4();
};
struct FUN_007d6120_Class
{
    int FUN_007d6120();
};
struct FUN_007d6140_Class
{
    int FUN_007d6140();
};
struct FUN_007d60b0_Class
{
    int DispatchByType(int type);
};
// Dispatches on type: calls FUN_007d6120 for 0, FUN_007d6140 for 1, GetField18F4 for 2, otherwise returns 0.
// @fnv 0x007d60b0
int FUN_007d60b0_Class::DispatchByType(int type)
{
    switch (type)
    {
    case 0:
        return ((FUN_007d6120_Class*)this)->FUN_007d6120();
    case 1:
        return ((FUN_007d6140_Class*)this)->FUN_007d6140();
    case 2:
        return ((FUN_007d6100_class*)this)->GetField18F4();
    default:
        return 0;
    }
}
}  // namespace fnv_007d60b0

namespace fnv_007d6160 {
struct FUN_007d6030_shell
{
    bool IsKeyActive();
};
int* __cdecl AdvanceCounter(int*);
struct FUN_007d6160_shell
{
    void FUN_007d6160();
};
// Loops up to four times calling AdvanceCounter on the object at offset 0x1c8, stopping early if IsKeyActive returns true.
// @fnv 0x007d6160
void FUN_007d6160_shell::FUN_007d6160()
{
    unsigned char i = 4;
    while (i)
    {
        AdvanceCounter((int*)((char*)this + 0x1c8));
        if (((FUN_007d6030_shell*)this)->IsKeyActive())
            break;
        --i;
    }
}
}  // namespace fnv_007d6160

class DispatchTarget
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008(int a1);
};

class FUN_00719120_cls
{
  public:
    DispatchTarget* FUN_00718fb0(int a1);
    bool DispatchToTarget(int a1, int a2);
};

// Looks up a DispatchTarget by a1 and, if found, calls its vf008 with a2 and returns true; otherwise returns false.
// @fnv 0x00719120
bool FUN_00719120_cls::DispatchToTarget(int a1, int a2)
{
    DispatchTarget* p = FUN_00718fb0(a1);
    if (p != 0)
    {
        p->vf008(a2);
        return true;
    }
    else
    {
        return false;
    }
}

struct FUN_007d6eb0
{
    FUN_007d6eb0();
    virtual void v0();
};

FUN_007d6eb0::FUN_007d6eb0()
{}

void FUN_007d6eb0::v0()
{}

struct FUN_007cb540 : public FUN_007d6eb0
{
    FUN_007cb540();
};

// @fnv 0x007cb540
FUN_007cb540::FUN_007cb540() : FUN_007d6eb0()
{}

struct ConfigEntry
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    void(__cdecl* m_2c)(void*);
};

extern char DAT_011a0960;
extern char DAT_011a0980;

ConfigEntry* FUN_00ec43fb(int a1, int a2, void* a3, void* a4, int a5);
struct StartMenu;
extern StartMenu* DAT_011daac0;
struct SMCall
{
    void FUN_007d4ce0(void* a1, void* a2);
    void FUN_0075f6f0(int a1, int a2);
};

// Looks up a ConfigEntry for a1; if its m_14 differs from m_18, syncs m_14 to m_18, calls FUN_007d4ce0, and runs m_2c if set.
// @fnv 0x007cfdc0
void ApplyConfigEntry(void* a0, int a1)
{
    ConfigEntry* entry = FUN_00ec43fb(a1, 0, &DAT_011a0960, &DAT_011a0980, 0);
    if (entry != 0)
    {
        if (entry->m_14 != entry->m_18)
        {
            entry->m_14 = entry->m_18;
            reinterpret_cast<SMCall*>(DAT_011daac0)->FUN_007d4ce0(entry, a0);
            if (entry->m_2c != 0)
            {
                entry->m_2c(entry);
                reinterpret_cast<SMCall*>(DAT_011daac0)->FUN_0075f6f0(2, 1);
            }
        }
    }
}

struct MenuSetting
{
    const char* FUN_00403df0();
};
extern MenuSetting* DAT_011d51d0[];
extern MenuSetting* DAT_011d5730[];
extern char DAT_01076e94[];
void FUN_007dc0a0(int*);
bool FUN_007d03a0(int);
void FUN_007d0cb0();
void UpdateBindingText();
bool FUN_004b71d0();
struct MenuItem
{
    unsigned unk00;
    const char* name;
    unsigned unk08, unk0c;
    MenuItem(const char*, void (*)(), int);
};
struct MenuTile
{
    void FUN_00707e10(const char*);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
};
struct MenuList
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Clear();
    void FUN_007d74f0(int);
    MenuTile* CreateListItem(MenuItem*, const char*, int, const char*);
    void FUN_007314c0(void (*)(), int, int);
};
struct MenuWork
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
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
    MenuTile* tile;
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
    unsigned unkec;
    unsigned unkf0;
    unsigned unkf4;
    unsigned unkf8;
    unsigned unkfc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    MenuList list;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    int mode;
    void BuildMenuList();
};
// Clears the list, adds menu entries for indices selected by mode or FUN_007d03a0, sets the callback, and updates the tile when FUN_004b71d0 is false.
// @fnv 0x007d01b0
void MenuWork::BuildMenuList()
{
    list.Clear();
    list.FUN_007d74f0(1);
    for (int i = 0; i < 28; FUN_007dc0a0(&i))
    {
        if ((mode == 3 && (i == 14 || i == 5 || i == 4 || i == 7 || i == 8 || i == 12 || i == 13 || i == 15 || i == 6 ||
                           i == 16 || i == 27)) ||
            (mode != 3 && FUN_007d03a0(i)))
        {
            MenuItem* entry = new MenuItem(DAT_011d51d0[i]->FUN_00403df0(), FUN_007d0cb0, i);
            MenuTile* item = list.CreateListItem(entry, entry->name, 0, DAT_01076e94);
            item->FUN_00707e10(DAT_011d51d0[i]->FUN_00403df0());
        }
    }
    list.FUN_007314c0(UpdateBindingText, 0, 0x7fffffff);
    if (!FUN_004b71d0())
    {
        tile->FUN_00a01350(0xfc4, DAT_011d5730[mode]->FUN_00403df0(), true);
        tile->FUN_00700320(0xfa3, 1);
    }
}

extern "C" double gModifierZero;

class C7D1360Actor
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
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    int unkDEC;
    int unkDF0;
    int unkDF4;
    int unkDF8;
    int unkDFC;
    int unkE00;
    int unkE04;
    int unkE08;
    int unkE0C;
    int unkE10;
    int unkE14;
    float m_fValue;

    bool FUN_007d1360();
};

// Returns whether m_fValue is greater than gModifierZero.
// @fnv 0x007d1360
bool C7D1360Actor::FUN_007d1360()
{
    return m_fValue > gModifierZero;
}

struct FUN_007d1400_Class
{
    void __thiscall FUN_00969e90(int, int);
    void __thiscall FUN_007d1400(int);
};

// Calls FUN_00969e90 with the given argument and 0 when the argument is 0 or 1.
// @fnv 0x007d1400
void FUN_007d1400_Class::FUN_007d1400(int arg)
{
    if (arg == 1)
    {
        this->FUN_00969e90(arg, 0);
    }
    else if (arg == 0)
    {
        this->FUN_00969e90(arg, 0);
    }
}

class FUN_007d5eb0_cls
{
  public:
    int m_00;
    int m_04;
    bool Check1();
    bool Check2();
    int FUN_007d5eb0();
};

int FUN_00457fe0();

// Returns m_04 - m_00 when Check1 and Check2 pass, FUN_00457fe0() - m_00 when only Check1 passes, otherwise 0.
// @fnv 0x007d5eb0
int FUN_007d5eb0_cls::FUN_007d5eb0()
{
    return Check1() ? (Check2() ? m_04 - m_00 : FUN_00457fe0() - m_00) : 0;
}

class FUN_007d5f10_Class
{
  public:
    int m_00;
    bool FUN_007d5f10();
};

// @fnv 0x007d5f10
bool FUN_007d5f10_Class::FUN_007d5f10()
{
    return (unsigned int)0 < (unsigned int)m_00;
}

struct FUN_007d5f30_cls
{
    int unk00;
    unsigned int m_04;
    int FUN_007d5f30();
};

// @fnv 0x007d5f30
int FUN_007d5f30_cls::FUN_007d5f30()
{
    return 0u < m_04;
}

class SMMemContext
{
    int m_eOldMemContext;

  public:
    SMMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~SMMemContext();
};

struct SMMenu;
struct SMTile;

struct SMTileList
{
    void* GetHeadPos();
    SMTile*& GetNext(void*& arPos);
};

struct SMTile
{
    int unk00;
    SMTileList kChildren;

    SMTile* ReadFile(const char* apPath);
    SMMenu* GetMenu();
    float GetFloat(int aiID);
    void SetFloat(int aiID, float afValue, bool abPropagate);
};

struct SMInterfaceManager
{
    static SMInterfaceManager* __cdecl GetSingleton();
    SMTile* GetMenuRoot();
};

struct SMMenu
{
    virtual ~SMMenu();
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
    virtual int GetID();

    int IsVisible();
    int GetMenuMode();
    void SetTile(SMTile* apTile, bool abFlag);
    void Init(bool abNewGame, bool abFlag);
};

typedef void(__cdecl* SMCallback)();
void __cdecl SMOnSaveLoad();

struct SMSaveLoadManager
{
    void SetCallback(SMCallback apfnCallback);
    void SetCallback2(SMCallback apfnCallback);
};

struct SMMenuQueue
{
    bool HasPending();
};

unsigned int __cdecl SMGetTickCount();
void __cdecl SMUnk0078d280(bool abFlag);
void __cdecl SMUnk007cc6e0();
SMMenu* __cdecl SMGetMenuByType(int aiType);
float __cdecl SMGetMenuDepth();
void __cdecl SMBeginLoad();
void __cdecl SMEndLoad();
int __cdecl SMGetStartMenuID();

extern unsigned int g_uiStartMenuTime;
extern unsigned int g_uiStartMenuTime2;
extern bool g_bStartMenuFlag;
extern SMSaveLoadManager* g_pSMSaveLoadManager;
extern SMMenuQueue g_kSMMenuQueue;
extern SMMenu* g_pStartMenu;

// Loads start_menu.xml, validates the start menu by ID, sets it as g_pStartMenu, initializes it, and returns whether it succeeded.
// @fnv 0x007cb7d0
bool __cdecl InitStartMenu(bool abNewGame, bool abFlag)
{
    SMMemContext kMemContext((MEM_CONTEXT)0xd, true,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Menus\\StartMenu.cpp", 0x151);
    g_uiStartMenuTime = SMGetTickCount();
    if (abNewGame)
        g_uiStartMenuTime2 = SMGetTickCount();
    if (!abNewGame && !g_bStartMenuFlag)
        SMUnk0078d280(true);
    if (g_pSMSaveLoadManager)
    {
        g_pSMSaveLoadManager->SetCallback(SMOnSaveLoad);
        g_pSMSaveLoadManager->SetCallback2(SMOnSaveLoad);
    }
    if (g_kSMMenuQueue.HasPending())
        SMUnk007cc6e0();

    SMTile* pRootX = SMInterfaceManager::GetSingleton()->GetMenuRoot();
    void* pPos = pRootX->kChildren.GetHeadPos();
    while (pPos)
    {
        SMTile* pChild5 = pRootX->kChildren.GetNext(pPos);
        SMMenu* pOpenMenu = pChild5 ? pChild5->GetMenu() : 0;
        if (pOpenMenu && pOpenMenu->IsVisible())
        {
            int iMode = pOpenMenu->GetMenuMode();
            if ((iMode == 8 || iMode == 2) && pChild5->GetFloat(0xfa7) != 6008.0)
                return false;
        }
    }

    SMMenu* pOldMenu3 = SMGetMenuByType(0x3f5);
    if (pOldMenu3)
        delete pOldMenu3;

    float fDepth2 = SMGetMenuDepth();
    SMBeginLoad();
    SMTile* pTileA =
        SMInterfaceManager::GetSingleton()->GetMenuRoot()->ReadFile("Data\\Menus\\Options\\start_menu.xml");
    SMMenu* pMenu2 = pTileA->GetMenu();
    if (pMenu2 && pMenu2->GetID() == SMGetStartMenuID())
    {
        pMenu2->SetTile(pTileA, false);
        g_pStartMenu = pMenu2;
        if (pTileA->GetFloat(0xfa7) == 6006.0 || pTileA->GetFloat(0xfa7) == 102.0)
            pTileA->SetFloat(0xfad, fDepth2, true);
        g_pStartMenu->Init(abNewGame, abFlag);
        SMEndLoad();
        return true;
    }
    else if (pMenu2 && pMenu2->IsVisible())
    {
        delete pMenu2;
    }
    SMEndLoad();
    return false;
}

namespace fnv_007ce9b0 {
struct Opt
{
    void* vt;
    const char* pText;
    void(__cdecl* pfChoose)();
    unsigned int m_uiModes;
};
struct UserOpt
{
    void* vt;
    const char* pText;
    void(__cdecl* pfChoose)();
    unsigned int m_uiModes;
    const char* pTemplate;
    int iVal;
    int iDefault;
    int eType;
    unsigned int iEntryIndex;
    unsigned int iSpacing;
    const char** pStrs;
    void* pfChange;
};
struct SaveEnt
{
    bool FUN_00846b30();
};
struct ChainB
{
    void FUN_00af28f0();
};
struct ChainA
{
    ChainB* FUN_005dfa10();
};
ChainA* __stdcall FUN_00af2640(void*);
struct SaveUI
{
    void* FUN_008d8520();
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
unsigned int __cdecl FUN_00457fe0();
void __cdecl HandleBackAction();
void __cdecl FUN_007d0700();
void __cdecl FUN_007d6d70();
void __cdecl ShowMessageBox(const char*, const char*, const char*, void(__cdecl*)(), int, int, float, float, const char*,
                          const char*, int);
void __cdecl FUN_007d3a30();
void __cdecl ApplyConfigEntry();
void __cdecl FUN_007ce970();
void __cdecl FUN_007d0c50();
extern unsigned int DAT_011daab4;
extern int DAT_011a0960;
extern int DAT_011a0980;
struct SettingT_GameSettingCollection_
{
    const char* String();
};
extern SettingT_GameSettingCollection_ DAT_011d34f8;
extern SettingT_GameSettingCollection_ DAT_011d3684;
extern SettingT_GameSettingCollection_ DAT_011d4930;
extern SettingString DAT_011d29dc;
struct TileF;
struct MenuObj
{
    float FUN_00a011b0(int, int);
};
struct TileX
{
    TileX* FUN_0045cd60();
    void FUN_00a01350(int, const char*, int);
    void FUN_00a012d0(int, float);
    void FUN_00700320(int, int);
};
struct LBOpt
{
    virtual bool Highlight(TileX*);
    StartMenu::Option* FindItemData(TileX*);
    bool ContainsKey(TileX*);
    void FUN_007d74f0(int);
    void ForEachEntry(int);
    void FUN_007d7a80(TileX*);
    void FUN_007314c0(void(__cdecl*)(), int, int);
    bool FUN_007d7630();
    char rest[0x2c];
};
struct LBInt
{
    virtual bool Highlight(TileX*);
    int FindItemData(TileX*);
    bool ContainsKey(TileX*);
    bool FUN_00764e40();
    void FUN_007d7bd0(int);
    char rest[0x2c];
};
struct LBSave
{
    virtual bool Highlight(TileX*);
    SaveEnt* FindItemData(TileX*);
    bool ContainsKey(TileX*);
    bool FUN_007d88a0();
    void FUN_007d8810(int);
    unsigned int GetRaceCount();
    void FUN_007d8d60(TileX*);
    char rest[0x2c];
};
struct TargetSM
{
    void* m_vt;
    MenuObj* pMenu;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    TileX* m_pTiles[23];
    LBOpt m_kFirstOptionListBox;
    LBOpt m_kSecondOptionListBox;
    LBOpt m_kThirdOptionListBox;
    LBOpt m_kDownloadOptions;
    LBInt m_kOptionIndexList;
    LBSave m_kOptionHelper;
    StartMenu::UserOption* pDirty;
    unsigned int uiFlags;
    float fThresh;
    SaveEnt* pEntry;

    void UpdateLayout();
    void FUN_007d6160();
    void BuildMenuList();
    void FUN_007d5f80();
    void FadeTile(int, int, unsigned int, float);
    void FUN_007ce9b0(int, TileX*);
};

void __fastcall UpdateTargetInfo(TargetSM*);

// @fnv 0x007ce9b0
void TargetSM::FUN_007ce9b0(int reason, TileX* tile)
{
    if (reason == 5)
        HandleBackAction();
    if (((StartMenu*)this)->IsFlagSet((StartMenu::Flag)0x400))
        return;
    else if (reason == 4)
    {
        if (m_kOptionHelper.FUN_007d88a0())
        {
            ((StartMenu_Wrap*)this)->FUN_0075f6f0((StartMenu::Flag)0x2000, true);
            UpdateLayout();
            ((StartMenu_Wrap*)this)->FUN_0075f6f0((StartMenu::Flag)0x2000, false);
        }
        else
        {
            if (((StartMenu*)this)->IsFlagSet((StartMenu::Flag)0x1000))
            {
                ShowMessageBox(DAT_011d29dc.GetString(), (const char*)0, (const char*)0, FUN_007d3a30, 0, 0x12, 0.0f,
                             0.0f, DAT_011d3684.String(), DAT_011d34f8.String(), 0);
            }
            else
            {
                m_kDownloadOptions.FUN_007314c0(ApplyConfigEntry, 0, 0x7fffffff);
            }
        }
    }
    else if (reason == 15)
    {
        if (m_kDownloadOptions.FUN_007d7630())
        {
            m_kDownloadOptions.FUN_007314c0(FUN_007ce970, 0, 0x7fffffff);
            FUN_007d6160();
            BuildMenuList();
        }
    }
    else if (reason == 1)
    {
        FUN_007d5f80();
        FUN_007d0700();
    }
    else if (reason == 0)
    {
        if (!((StartMenu*)this)->IsFlagSet((StartMenu::Flag)0x100000))
        {
            FUN_007d5f80();
            if (((TargetSM*)DAT_011daac0)->m_kOptionIndexList.FUN_00764e40())
            {
                ((TargetSM*)DAT_011daac0)->FadeTile(14, 0, 0x80000000, -1.0f);
                ((TargetSM*)DAT_011daac0)->m_kOptionIndexList.FUN_007d7bd0(0);
            }
            FadeTile(1, 0, 0x80000000, -1.0f);
            m_kSecondOptionListBox.FUN_007d74f0(0);
            m_kSecondOptionListBox.ForEachEntry(1);
            m_kOptionHelper.FUN_007d8810(1);
            m_kOptionHelper.Highlight((TileX*)0);
            ((StartMenu_Wrap*)this)->FUN_0075f6f0((StartMenu::Flag)0x40000, false);
            UpdateTargetInfo(this);
            m_kOptionHelper.FUN_007d8810(0);
            FadeTile(6, 0, 0x80000000, -1.0f);
            m_kThirdOptionListBox.FUN_007d74f0(0);
            FadeTile(7, 0, 0x80000000, -1.0f);
            m_kFirstOptionListBox.FUN_007d74f0(1);
            m_kFirstOptionListBox.ForEachEntry(1);
            FadeTile(5, 0, 0x80000000, -1.0f);
            if (((StartMenu*)this)->IsFlagSet((StartMenu::Flag)2))
            {
                FUN_007d6d70();
                ((StartMenu_Wrap*)this)->FUN_0075f6f0((StartMenu::Flag)2, false);
            }
        }
    }
    if (tile)
    {
        if ((unsigned int)(FUN_00457fe0() - DAT_011daab4) > 0x1f4)
        {
            LBOpt* arr5[4];
            arr5[0] = &m_kFirstOptionListBox;
            arr5[1] = &m_kSecondOptionListBox;
            arr5[2] = &m_kThirdOptionListBox;
            arr5[3] = &m_kDownloadOptions;
            unsigned int i;
            for (i = 0; i < 4; i++)
            {
                StartMenu::Option* hit2 = arr5[i]->FindItemData(tile);
                if (hit2 && hit2->m_pActionCallback)
                {
                    if (hit2->m_pActionCallback != FUN_007d0c50)
                        arr5[i]->FUN_007d7a80(tile);
                    if (arr5[i] != &m_kThirdOptionListBox && hit2->m_pActionCallback != HandleBackAction)
                        arr5[i]->FUN_007d74f0(0);
                    hit2->m_pActionCallback();
                    DAT_011daab4 = FUN_00457fe0();
                    return;
                }
            }
            pEntry = m_kOptionHelper.FindItemData(tile);
            if (pEntry && (((StartMenu*)this)->IsFlagSet((StartMenu::Flag)8) || !pEntry->FUN_00846b30()))
            {
                UpdateLayout();
            }
            else
            {
                if (m_kOptionHelper.ContainsKey(tile) && ((StartMenu*)this)->IsFlagSet((StartMenu::Flag)8))
                {
                    if (m_kOptionHelper.GetRaceCount() > 1000 && m_kOptionHelper.GetRaceCount() > 0)
                        return;
                    tile->FUN_00a01350(0xfc4, DAT_011d4930.String(), 1);
                    m_kOptionHelper.FUN_007d8d60(tile);
                    m_pTiles[6]->FUN_00700320(0x1004, 0);
                    ((StartMenu_Wrap*)DAT_011daac0)->FUN_0075f6f0((StartMenu::Flag)0x4000, true);
                }
                else
                {
                    if (m_kOptionIndexList.ContainsKey(tile) && m_kOptionIndexList.FindItemData(tile) == -1)
                    {
                        void* tmp = ((SaveUI*)FUN_00a25920())->FUN_008d8520();
                        FUN_00af2640(tmp)->FUN_005dfa10()->FUN_00af28f0();
                    }
                }
            }
            StartMenu::UserOption* aSel =
                dynamic_cast<StartMenu::UserOption*>(m_kDownloadOptions.FindItemData(tile->FUN_0045cd60()));
            if (aSel)
            {
                if (reason == 100 || reason == 101 || aSel->eType == 0 ||
                    (aSel->eType == 1 && aSel->iVal < aSel->m_uiValueCount - 1))
                {
                    aSel->iVal = (aSel->iVal + aSel->m_uiValueCount + (reason != 100 ? 1 : -1)) % aSel->m_uiValueCount;
                    pDirty = aSel;
                    tile->FUN_00a012d0(0xff5, pMenu->FUN_00a011b0(0xff5, 1));
                }
            }
        }
    }
}
}  // namespace fnv_007ce9b0

struct KeyTile
{
    bool IsAllChildrenFlag0();
    bool IsTraitNonZero(int);
    float FUN_00a011b0(int);
    void FUN_00a0b110(int);
    KeyTile* FUN_00a03eb0(int);
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
};
struct MenuDispatch151
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Click(int, KeyTile*);
};
struct Input151
{
    bool BindInputKey();
};
struct Controls151
{
    Input151* FUN_00877720(int, int, unsigned char);
};
struct Settings151
{
    const char* FUN_004c69f0();
};

extern GlobalObject_0040c150 g_011d3108;

bool __cdecl FUN_00702450(int);
int __cdecl FUN_007189c0(int);
void __cdecl FUN_00717280(int);
int __cdecl FUN_00a09030(int);
void __cdecl ShowMessageBox(const char*, int, int, int, int, int, float, float, const char*, int);
float __cdecl FUN_004bd510(float, float);
void FUN_007d0c50();
struct OptionList151 : StartMenu::OptionListBox
{
    StartMenu::Option* FUN_007a1910();
    void FUN_007d74f0(int);
    void ForEachEntry(int);
    void FUN_007314c0(void (*)(), int, int);
};
struct PauseMenu151
{
    bool UpdateLoadingScreen();
};

struct OtherMenu151
{
    void Reset();
};
OtherMenu151* FUN_007cb710();
struct Candidate151 : StartMenu
{
    int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4;
    int mode;
    bool FUN_007ce8f0();
    void UpdatePanelState();
    void FUN_0075f6f0(int, bool);
    bool HandleButtonInput(int button, int unused);
};
// Handles a menu button press: checks flags and the current mode, then dispatches clicks, option changes and key-tile actions, returning true when handled.
// @fnv 0x007cefc0
bool Candidate151::HandleButtonInput(int button, int unused)
{
    if (FUN_00702450(0x3f5))
    {
        if (IsFlagSet((Flag)0x400))
            return true;
        if (IsFlagSet((Flag)0x8000) && IsFlagSet((Flag)8))
            return true;
        if (button > 0)
        {
            if (IsFlagSet((Flag)0x80000) && BSSystemUtility::s_iUpdateEnabled)
            {
                return ((PauseMenu151*)BSSystemUtility::s_iUpdateEnabled)->UpdateLoadingScreen();
            }
            else if (((Candidate151*)DAT_011daac0)->mode == 3 && FUN_007ce8f0())
            {
                int action = ((OptionList151*)&m_kDownloadOptions)->FUN_007a1910()->m_uiModes;
                int key = FUN_007189c0(button);
                if (((Controls151*)g_osGlobals)->FUN_00877720(action, 3, (unsigned char)key)->BindInputKey())
                {
                    if (FUN_004b71d0())
                        ((KeyTile*)m_pTiles[16])->FUN_00700320(0xfa3, 0);
                    else
                        ((KeyTile*)m_pTiles[16])->FUN_00a01350(0xfc4, DAT_011d5730[mode]->FUN_00403df0(), true);
                    ((OptionList151*)&m_kDownloadOptions)->FUN_007d74f0(1);
                    ((OptionList151*)&m_kDownloadOptions)->ForEachEntry(1);
                    ((OptionList151*)&m_kDownloadOptions)->FUN_007314c0(UpdateBindingText, 0, 0x7fffffff);
                    FUN_0075f6f0(2, true);
                    FUN_0075f6f0(0x4000000, true);
                    ((KeyTile*)m_pTiles[5])->FUN_00700320(0xfaf, 1);
                }
                else if (!FUN_00a09030(0x3e9))
                {
                    FUN_00717280(10);
                    ShowMessageBox(((MenuSetting*)&g_011d3108)->FUN_00403df0(), 0, 0, 0, 1, 0x12, 0.0f, 0.0f,
                                 ((Settings151*)&g_011d38b8)->FUN_004c69f0(), 0);
                }
                return true;
            }
        }
        switch (button)
        {
        case 5:
        case 9:
            if (!IsFlagSet((Flag)1) && ((KeyTile*)m_pTiles[9])->IsTraitNonZero(0xfa3) &&
                ((KeyTile*)m_pTiles[9])->FUN_00a011b0(0xfa9) != 0.0)
            {
                UpdatePanelState();
                FUN_007cb710()->Reset();
                return true;
            }
            break;
        case 12:
            if (((KeyTile*)m_pTiles[4])->IsAllChildrenFlag0() && ((KeyTile*)m_pTiles[4])->IsTraitNonZero(0xfaf))
            {
                ((KeyTile*)m_pTiles[4])->FUN_00a0b110(0xfcb);
                ((MenuDispatch151*)this)->Click(4, (KeyTile*)m_pTiles[4]);
                return true;
            }
            break;
        case 11:
            if (((KeyTile*)m_pTiles[15])->IsAllChildrenFlag0() && ((KeyTile*)m_pTiles[15])->IsTraitNonZero(0xfaf))
            {
                ((KeyTile*)m_pTiles[15])->FUN_00a0b110(0xfcb);
                ((MenuDispatch151*)this)->Click(15, (KeyTile*)m_pTiles[15]);
                return true;
            }
            break;
        case 3:
        case 4:
            if (m_kDownloadOptions.FUN_007d7580() && m_kDownloadOptions.GetHighlightedItem())
            {
                int id = button == 4 ? 100 : 101;
                KeyTile* tile = ((KeyTile*)m_kDownloadOptions.GetHighlightedItem())->FUN_00a03eb0(id);
                if (tile && tile->IsAllChildrenFlag0() && tile->IsTraitNonZero(0xfaf))
                {
                    ((MenuDispatch151*)this)->Click(id, tile);
                    tile->FUN_00a0b110(0xfcb);
                    return true;
                }
                else if (id == 101 && ((OptionList151*)&m_kDownloadOptions)->FUN_007a1910() &&
                         ((OptionList151*)&m_kDownloadOptions)->FUN_007a1910()->m_pActionCallback == FUN_007d0c50)
                {
                    ((MenuDispatch151*)this)->Click(-1, (KeyTile*)m_kDownloadOptions.GetHighlightedItem());
                    tile->FUN_00a0b110(0xfcb);
                    return true;
                }
            }
            break;
        case 15:
        case 16:
            if (m_kDownloadOptions.FUN_007d7580())
            {
                UserOption* option = dynamic_cast<UserOption*>(((OptionList151*)&m_kDownloadOptions)->FUN_007a1910());
                if (option && option->eType == 2)
                {
                    int iDelta = (int)FUN_004bd510(
                        ((KeyTile*)m_kDownloadOptions.GetHighlightedItem())->FUN_00a011b0(0x1005), 1.0f);
                    int iTileId = 101;
                    if (button == 15)
                    {
                        iDelta *= -1;
                        iTileId = 100;
                    }
                    option->iVal += iDelta;
                    if (option->iVal < 0)
                        option->iVal = 0;
                    else if ((unsigned)option->iVal >= option->m_uiValueCount)
                        option->iVal = option->m_uiValueCount - 1;
                    m_pUserOption = option;
                    ((KeyTile*)m_kDownloadOptions.GetHighlightedItem())->FUN_00a03eb0(iTileId)->FUN_00a0b110(0xfcb);
                    return true;
                }
            }
            break;
        }
    }
    return false;
}

struct TileSI
{
    TileSI* GetParent();
    float GetFloat(int aiID);
    float GetAbsoluteX();
};
class InterfaceManager
{
  public:
    int GetPickCursorX();
};
InterfaceManager* __cdecl FUN_004b7210(void);
float __cdecl FUN_004e4430(float afValue);

struct StartMenuSI : public StartMenu
{
    void HandleSliderTileInput(int aiID, Tile* apTile);
};

// @fnv 0x007cf6a0
void StartMenuSI::HandleSliderTileInput(int aiID, Tile* apTile)
{
    if (aiID == 0x66)
    {
        StartMenu::UserOption* pOption = dynamic_cast<StartMenu::UserOption*>(m_kDownloadOptions.GetHighlightedData());
        if (pOption && (Tile*)((TileSI*)apTile)->GetParent() == m_kDownloadOptions.GetHighlightedItem())
        {
            int iPreviousValue = pOption->iVal;
            pOption->iVal = FUN_004e4430(((TileSI*)apTile)->GetParent()->GetFloat(0x1007) *
                                         (FUN_004b7210()->GetPickCursorX() - ((TileSI*)apTile)->GetAbsoluteX()) /
                                         ((TileSI*)apTile)->GetFloat(0xfb1));
            if (pOption->iVal < 0)
            {
                pOption->iVal = 0;
            }
            else if (pOption->iVal > pOption->m_uiValueCount - 1)
            {
                pOption->iVal = pOption->m_uiValueCount - 1;
            }
            if (iPreviousValue != pOption->iVal)
            {
                m_pUserOption = pOption;
            }
        }
    }
}

namespace fnv_007cf9a0 {
struct FUN_007cfd00_cls
{
    bool FUN_007cfd00();
};
extern FUN_007cfd00_cls* DAT_011da0c4;

struct FUN_007e6760_cls
{
    virtual ~FUN_007e6760_cls();
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
    bool FUN_007e6760();
};
extern FUN_007e6760_cls* DAT_011daac8;

struct FUN_00789820_shell
{
    void FUN_00789820();
    bool FUN_00458110(int);
    void UpdateLoadingScreens();
};
extern FUN_00789820_shell* DAT_011da0c0;

struct FUN_0059bb30_Menu
{
    int FUN_0059bb30();
};
struct FUN_00a03c90_shell
{
    FUN_0059bb30_Menu* FUN_00a03c90();
    bool FUN_00a07fc0(int);
};
FUN_00a03c90_shell* __cdecl FUN_00a09030(int iMenuType);

struct FUN_005dfa10_cls
{
    void FUN_00af2b10();
};
struct FUN_00af2640_cls
{
    FUN_005dfa10_cls* FUN_005dfa10();
};
FUN_00af2640_cls* __stdcall FUN_00af2640(int a, void (*pfn)());
void FUN_007d4c50();

void FUN_0078d020();
void FUN_0075f2a0();
void FUN_007d6d70();
unsigned int GetCurrentArrayElement();
extern unsigned int DAT_011dac60;

struct FUN_007cf9a0_shell : public StartMenu
{
    void FUN_0075f6f0(int iFlag, bool bSet);
    void FUN_007d5830();
    bool HandleBindingInput();
    bool FUN_007d5af0();
    void FUN_007d4ce0(StartMenu::UserOption* pkOption, int a2);
    void FUN_007cf9a0();
};

// @fnv 0x007cf9a0
void FUN_007cf9a0_shell::FUN_007cf9a0()
{
    if (!DAT_011da0c4->FUN_007cfd00())
        return;

    if (DAT_011daac8)
    {
        DAT_011daac8->v0b();
        if (DAT_011daac8->FUN_007e6760())
        {
            delete DAT_011daac8;
            DAT_011daac8 = 0;
        }
    }

    if (DAT_011da0c0)
    {
        DAT_011da0c0->FUN_00789820();
        if (IsFlagSet(FLAG_IIS_PREFADE) && DAT_011da0c0->FUN_00458110(0))
        {
            DAT_011da0c0->UpdateLoadingScreens();
            FUN_0075f6f0(FLAG_IIS_PREFADE, false);
            FUN_0075f6f0(FLAG_FADE_IN, true);
        }
    }

    FUN_007d5830();
    if (HandleBindingInput())
        return;

    if (IsFlagSet(FLAG_SHOWING_CREDITS))
    {
        if (((FUN_00a03c90_shell*)m_pTiles[3])->FUN_00a07fc0(0xfa9) && m_pTiles[3]->GetFloat(0xfa9) == 0.0 &&
            !FUN_00a09030(0x417))
        {
            FUN_0078d020();
            FUN_0075f2a0();
        }
        return;
    }

    bool bBusy = FUN_007d5af0();
    if (!bBusy && IsFlagSet((Flag)(FLAG_SAVE_WAIT_MESSAGE | FLAG_SAVE_WAIT_SAVING)))
    {
        if (IsFlagSet(FLAG_SAVE_WAIT_MESSAGE))
        {
            FUN_00a03c90_shell* pkMessage = FUN_00a09030(0x3e9);
            if (pkMessage && pkMessage->FUN_00a03c90()->FUN_0059bb30() == 1)
            {
                FUN_0075f6f0(FLAG_SAVE_WAIT_MESSAGE, false);
                FUN_0075f6f0(FLAG_SAVE_WAIT_SAVING, true);
                DAT_011dac60 = gm_GetTickCount() + 3000;
                FUN_007d6d70();
            }
            else if (!GetCurrentArrayElement())
            {
                FUN_007d6d70();
                FUN_0075f6f0(FLAG_SAVE_WAIT_MESSAGE, false);
                FUN_0075f6f0(FLAG_OPTIONS_DIRTY, false);
            }
        }
        else if (gm_GetTickCount() >= DAT_011dac60)
        {
            FUN_00704000();
            FUN_0075f6f0(FLAG_SAVE_WAIT_SAVING, false);
            FUN_0075f6f0(FLAG_OPTIONS_DIRTY, false);
        }
    }

    if (m_pUserOption)
    {
        FUN_007d4ce0(m_pUserOption, 0);
        if (m_pUserOption->m_pChangeCallback)
        {
            m_pUserOption->m_pChangeCallback(m_pUserOption);
            FUN_0075f6f0(FLAG_OPTIONS_DIRTY, true);
        }
        m_pUserOption = 0;
    }

    if (IsFlagSet(FLAG_MOUNT_DLC))
    {
        FUN_00a03c90_shell* pkDLCTile = FUN_00a09030(0x3e9);
        FUN_0059bb30_Menu* pkDLCMenu = pkDLCTile ? pkDLCTile->FUN_00a03c90() : 0;
        if (pkDLCMenu && pkDLCMenu->FUN_0059bb30() == 1)
        {
            ((FUN_007cf9a0_shell*)DAT_011daac0)->FUN_0075f6f0(FLAG_MOUNT_DLC, false);
            int iZero = 0;
            FUN_00af2640(iZero, FUN_007d4c50)->FUN_005dfa10()->FUN_00af2b10();
        }
    }
}
}  // namespace fnv_007cf9a0

struct BindingInput
{
    unsigned char GetByteAt(int action, int device);
    int FUN_00a236b0(int device);
};
extern MenuSetting* DAT_011d52f0[];
extern MenuSetting* DAT_011d5240[];
extern MenuSetting* DAT_011d5130[];
extern MenuSetting g_011d2e14;
int __cdecl FUN_00406f60(BSStringT<char>*, const char*, ...);

// Resolves the binding key for the item's action and mode, formats it into a label string, and sets it on the tile.
// @fnv 0x007cfe40
void UpdateBindingText(MenuTile* tile, MenuItem* item)
{
    if (!DAT_011daac0)
        return;
    BSStringT<char> text;
    tile->FUN_00700320(0x1004, 1);
    unsigned char key =
        ((BindingInput*)g_osGlobals->FUN_00877720())->GetByteAt(item->unk0c, ((MenuWork*)DAT_011daac0)->mode);
    if (key == 255)
    {
        text.Set("--", 0);
    }
    else if (((MenuWork*)DAT_011daac0)->mode == 0 && key < 238U && DAT_011d52f0[key])
    {
        FUN_00406f60(&text, "%s", DAT_011d52f0[key]->FUN_00403df0());
    }
    else if (((MenuWork*)DAT_011daac0)->mode == 1 && key < 9U && DAT_011d5240[key])
    {
        FUN_00406f60(&text, "%s", DAT_011d5240[key]->FUN_00403df0());
    }
    else if (((MenuWork*)DAT_011daac0)->mode == 2)
    {
        if (key < ((BindingInput*)g_osGlobals->FUN_00877720())->FUN_00a236b0(0))
        {
            FUN_00406f60(&text, "%s %d", g_011d2e14.FUN_00403df0(), key + 1);
        }
        else if (key >= 32 && key < 40 && DAT_011d5130[key])
        {
            FUN_00406f60(&text, "%s", DAT_011d5130[key]->FUN_00403df0());
        }
        else
        {
            text.Set("--", 0);
        }
    }
    else if (((MenuWork*)DAT_011daac0)->mode == 3)
    {
        const char* button = 0;
        switch (key)
        {
        case 16:
            if (!button)
                button = "lt";
        case 17:
            if (!button)
                button = "rt";
        case 15:
            if (!button)
                button = "lb";
        case 14:
            if (!button)
                button = "rb";
        case 8:
            if (!button)
                button = "ls";
        case 9:
            if (!button)
                button = "rs";
        case 10:
            if (!button)
                button = "a";
        case 11:
            if (!button)
                button = "b";
        case 12:
            if (!button)
                button = "x";
        case 13:
            if (!button)
                button = "y";
        case 7:
            if (!button)
                button = "back";
            FUN_00406f60(&text, "Interface\\Shared\\Button\\glow_general_button_%s.dds", button);
            tile->FUN_00700320(0x1004, 2);
            break;
        default:
            FUN_00406f60(&text, "%d", key);
            break;
        }
    }
    else
    {
        FUN_00406f60(&text, "%d", key);
    }
    tile->FUN_00a01350(0x1005, text.String(), true);
}

struct SM7d06c0_tile
{
    void FUN_00700320(unsigned int auiFlags, int aiValue);
};

struct SM7d06c0_menu : public StartMenu
{
    void FUN_0075f6f0(int aeFlag, bool abSet);
    void FUN_007d3b60();
};

// @fnv 0x007d06c0
void __cdecl FUN_007d06c0()
{
    if (DAT_011daac0 != 0)
    {
        ((SM7d06c0_tile*)DAT_011daac0->m_pTiles[15])->FUN_00700320(0x1004, 0);
        ((SM7d06c0_menu*)DAT_011daac0)->FUN_0075f6f0(8, true);
        ((SM7d06c0_menu*)DAT_011daac0)->FUN_007d3b60();
    }
}

struct SelectionMap
{
    int Find(int);
};
struct MenuManagerView
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
    SelectionMap selection;
    int MenuAt(int);
};
struct StartView
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
    Tile* tile;
};
class BGSMessage : public TESForm
{
};
class BGSListForm : public TESForm
{
  public:
    BSSimpleList<TESForm*>* Items();
};
int FUN_0070ede0();
bool FUN_00702680(int, unsigned int);
void ShowSelected(BGSMessage*, int);
// @fnv 0x007d0770
void ShowSelectedMenuMessage()
{
    ((StartView*)DAT_011daac0)->tile->Set(0xfa3, 1);
    BGSMessage* kSelected = 0;
    for (int index = 0; !kSelected && index < 10; ++index)
    {
        int menu = ((MenuManagerView*)FUN_004b7210())->MenuAt(index);
        if (menu == FUN_0070ede0())
        {
            break;
        }
        else
        {
            int entry5 = 41;
            if (menu == 1)
            {
                if (FUN_00702680(1003, 0))
                    entry5 = ((MenuManagerView*)FUN_004b7210())->selection.Find(1003);
                else if (FUN_00702680(1035, 0))
                    entry5 = ((MenuManagerView*)FUN_004b7210())->selection.Find(1035);
                else if (FUN_00702680(1002, 0))
                    entry5 = ((MenuManagerView*)FUN_004b7210())->selection.Find(1002);
                else if (FUN_00702680(1023, 0))
                    entry5 = ((MenuManagerView*)FUN_004b7210())->selection.Find(1023);
            }
            else
                entry5 = ((MenuManagerView*)FUN_004b7210())->selection.Find(menu);
            if (entry5 < 41)
            {
                BGSMessage* message = dynamic_cast<BGSMessage*>(TESForm::GetFormByID(entry5 + 0x168));
                if (message)
                {
                    int formIDB = FUN_004b71d0() ? 0x165 : 0x163;
                    BGSListForm* list2 = dynamic_cast<BGSListForm*>(TESForm::GetFormByID(formIDB));
                    if (list2)
                    {
                        bool found5 = false;
                        BSSimpleList<TESForm*>* node = list2->Items();
                        while (node && node->GetItem())
                        {
                            if (node->GetItem() == message)
                            {
                                found5 = true;
                                break;
                            }
                            node = node->GetNext();
                        }
                        if (!found5)
                            continue;
                    }
                }
                kSelected = message;
            }
        }
    }
    ShowSelected(kSelected, 1);
}

struct BackListActions
{
    bool FUN_007d7630();
    bool FUN_007d7580();
    bool FUN_007d88a0();
    void FUN_007d74f0(bool enabled);
    void ForEachEntry(bool highlight);
    void FUN_007d8810(bool enabled);
};
struct BackMenuActions
{
    void FUN_007d5f80();
    void SetTileValues();
};
extern InventoryMenuSetting g_011d2b14;
void FUN_007d0700();
void FUN_007d6d70();

// Handles the back action on the start menu: checks the back list state and flags, then triggers the matching menu transition or returns early.
// @fnv 0x007d0e40
void HandleBackAction()
{
    if (DAT_011daac0 && ((BackListActions*)&DAT_011daac0->m_kFirstOptionListBox)->FUN_007d7630())
    {
        if (DAT_011daac0->IsFlagSet(StartMenu::FLAG_DONT_FORCE_BACK))
        {
            Interface::ShowButtonDialog(g_011d2b14.FUN_00403df0(), 0, 0, 0, 0, 0x12, 0.0f, 0.0f,
                                        g_011d38b8.FUN_00403df0(), 0);
        }
        ((StartMenu_Wrap*)DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_DONT_FORCE_BACK, false);
        ((StartMenu_Wrap*)DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_LIVE_MENU, false);
        ((MenuTile*)DAT_011daac0->m_pTiles[10])->FUN_00700320(0xfa3, 0);
        if (((BackListActions*)&DAT_011daac0->m_kDownloadOptions)->FUN_007d7580() ||
            DAT_011daac0->IsFlagSet(StartMenu::FLAG_ACTION_MAPPING))
        {
            ((BackMenuActions*)DAT_011daac0)->FUN_007d5f80();
            FUN_007d0700();
            return;
        }
        else if (((BackListActions*)&DAT_011daac0->m_kThirdOptionListBox)->FUN_007d7580())
        {
            ((BackListActions*)&DAT_011daac0->m_kThirdOptionListBox)->FUN_007d74f0(false);
            ((MenuSI*)DAT_011daac0)->FadeTile(7, 0, 0x80000000, -1.0f);
            if (DAT_011daac0->m_kOptionHelper.IsEnabled())
            {
                ((StartMenu_Wrap*)DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_SAVELOAD_BACKOUT, true);
                return;
            }
        }
        else if (((BackListActions*)&DAT_011daac0->m_kSecondOptionListBox)->FUN_007d7580())
        {
            ((MenuSI*)DAT_011daac0)->FadeTile(1, 0, 0x80000000, -1.0f);
            ((BackListActions*)&DAT_011daac0->m_kSecondOptionListBox)->FUN_007d74f0(false);
        }
        else if (DAT_011daac0->m_kOptionIndexList.IsEnabled())
        {
            ((MenuSI*)DAT_011daac0)->FadeTile(14, 0, 0x80000000, -1.0f);
            DAT_011daac0->m_kOptionIndexList.SetEnabled(false);
        }
        else if (((BackListActions*)&DAT_011daac0->m_kOptionHelper)->FUN_007d88a0())
        {
            ((BackMenuActions*)DAT_011daac0)->SetTileValues();
            DAT_011daac0->m_kOptionHelper.Highlight(0);
            UpdateTargetInfo(DAT_011daac0);
            ((BackListActions*)&DAT_011daac0->m_kOptionHelper)->FUN_007d8810(false);
            ((MenuSI*)DAT_011daac0)->FadeTile(6, 0, 0x80000000, -1.0f);
            DAT_011daac0->m_kOptionHelper.RemoveAll();
        }
        else if (((BackListActions*)&DAT_011daac0->m_kFirstOptionListBox)->FUN_007d7580())
        {
            if (StartMenu::IsInGame() && !DAT_011daac0->IsFlagSet(StartMenu::FLAG_FORCE_RELOAD))
            {
                CloseStartMenu(1);
            }
            return;
        }
        else if (DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVELOAD_BACKOUT))
        {
            return;
        }
        ((BackListActions*)&DAT_011daac0->m_kFirstOptionListBox)->FUN_007d74f0(true);
        ((BackListActions*)&DAT_011daac0->m_kFirstOptionListBox)->ForEachEntry(true);
        ((MenuSI*)DAT_011daac0)->FadeTile(5, 0, 0x80000000, -1.0f);
        if (DAT_011daac0->IsFlagSet(StartMenu::FLAG_OPTIONS_DIRTY))
        {
            FUN_007d6d70();
            ((StartMenu_Wrap*)DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_OPTIONS_DIRTY, false);
        }
    }
}

struct EntryOps
{
    void DispatchEvent();
    bool IsLegacyAutosaveFileName();
    bool FUN_00846b10();
};
struct TileOpsLocal
{
    float FUN_00a011b0(int);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00a07530(int);
};
struct SaveListOps
{
    virtual void v0();
    virtual Tile* selected();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* tileAt(unsigned, bool);
    EntryOps* FUN_007a1910();
    bool RemoveByKey(Tile*);
    unsigned GetFilteredItemCount();
    unsigned FUN_007d87b0();
    TileOpsLocal* FUN_00825c00();
    void FUN_007314c0(void (*)(Tile*, EntryOps*), int, int);
    unsigned GetRaceCount();
    EntryOps* FUN_007d86c0(unsigned, bool);
    void FUN_007d80f0(unsigned, bool);
    TileOpsLocal* CallVirtualZero();
};
struct MenuOpsLocal
{
    void EnableAndRemoveHighlightedItem();
    void FUN_0075f6f0(int, bool);
};
struct SettingOpsLocal
{
    const char* FUN_00403df0();
};
extern SettingOpsLocal g_011d25d4, g_011d2c4c;
extern StartMenu* DAT_011daac0;
void HandleBackAction();
int TraitNameToIDAdd(const char*, int);
void InitSaveLoadTile(Tile*, EntryOps*);
int FUN_00406d00(char*, unsigned, const char*, ...);
// @fnv 0x007d3620
void UpdateSaveListSelection()
{
    if (DAT_011daac0 && ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->selected())
    {
        SaveListOps* list3 = (SaveListOps*)&DAT_011daac0->m_kOptionHelper;
        list3->FUN_007a1910()->DispatchEvent();
        list3->RemoveByKey(list3->selected());
        HandleBackAction();
        int count = -1;
        unsigned current = list3->GetFilteredItemCount();
        unsigned total2 = list3->FUN_007d87b0();
        if (current == 0)
        {
            ((MenuOpsLocal*)DAT_011daac0)->EnableAndRemoveHighlightedItem();
            ((MenuOpsLocal*)DAT_011daac0)->FUN_0075f6f0(0x40000, false);
            HandleBackAction();
        }
        else if (current >= total2 &&
                 DAT_011daac0->m_fMenuTimer == list3->FUN_00825c00()->FUN_00a011b0(TraitNameToIDAdd("_current_value", -1)))
        {
            int index = (int)(total2 + DAT_011daac0->m_fMenuTimer - 1.0);
            list3->FUN_007314c0(InitSaveLoadTile, index, index + 1);
            count = ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->GetRaceCount();
            if (DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_MODE))
            {
                for (unsigned first7 = 0; first7 < ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->GetRaceCount();
                     first7++)
                {
                    Tile* tile3 = ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->tileAt(first7, false);
                    EntryOps* entry5 = ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->FUN_007d86c0(first7, false);
                    if (tile3 && entry5)
                    {
                        if (entry5->IsLegacyAutosaveFileName())
                        {
                            ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->FUN_007d80f0(first7, false);
                            count--;
                        }
                        else if (entry5->FUN_00846b10())
                        {
                            ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->FUN_007d80f0(first7, false);
                            count--;
                        }
                    }
                }
            }
        }
        else if (DAT_011daac0->m_fMenuTimer != 0.0)
            DAT_011daac0->m_fMenuTimer = DAT_011daac0->m_fMenuTimer - 1.0;
        if (DAT_011daac0->IsFlagSet(StartMenu::FLAG_SAVE_MODE) &&
            ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->GetRaceCount() > 0)
        {
            if (count == -1)
            {
                count = ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->GetRaceCount();
                for (unsigned second3 = 0; second3 < ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->GetRaceCount();
                     second3++)
                {
                    Tile* entry2 = ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->tileAt(second3, false);
                    EntryOps* tile2 = ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->FUN_007d86c0(second3, false);
                    if (entry2 && tile2)
                    {
                        if (tile2->IsLegacyAutosaveFileName())
                            count--;
                        else if (tile2->FUN_00846b10())
                            count--;
                    }
                }
            }
            count--;
            char text_2[64];
            FUN_00406d00(text_2, 64, "%s %u/%i %s", g_011d2c4c.FUN_00403df0(), count, 1000, g_011d25d4.FUN_00403df0());
            ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->CallVirtualZero()->FUN_00a01350(0xfc4, text_2, true);
            ((SaveListOps*)&DAT_011daac0->m_kOptionHelper)->CallVirtualZero()->FUN_00a07530(8);
        }
    }
}

signed char __cdecl ConsumeByteAtE4();
struct OSGlobalsKeyed
{
    void* FUN_00877720(int key);
};
struct WheelAction
{
    void FUN_00a24b70();
};
struct OptionsListSort
{
    void FUN_007314c0(void (*comparator)(), int begin, int end);
};
void __cdecl UpdateBindingText();
// If the menu exists and ConsumeByteAtE4 returns 1, invokes the wheel action for the stored key, marks the options dirty and re-sorts the options list.
// @fnv 0x007d3a30
void __cdecl FUN_007d3a30()
{
    if (DAT_011daac0)
    {
        if (ConsumeByteAtE4() == 1)
        {
            reinterpret_cast<WheelAction*>(
                reinterpret_cast<OSGlobalsKeyed*>(g_osGlobals)
                    ->FUN_00877720(*reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_011daac0) + 0x1c8)))
                ->FUN_00a24b70();
            reinterpret_cast<StartMenu_Wrap*>(DAT_011daac0)->FUN_0075f6f0(StartMenu::FLAG_OPTIONS_DIRTY, true);
            reinterpret_cast<OptionsListSort*>(&DAT_011daac0->m_kDownloadOptions)
                ->FUN_007314c0(&UpdateBindingText, 0, 0x7fffffff);
        }
    }
}

namespace fnv_007d3c70 {
struct SaveRecord
{
    bool IsAuto();
    bool IsQuick();
};
struct SaveTile
{
    void Int(int, int);
    void Text(int, const char*, bool);
    void Float(int, float, bool);
    void Value(int, float);
    void Action(int);
};
struct SaveList
{
    virtual void Replace(SaveTile*);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Refresh();
    virtual SaveTile* At(unsigned int, bool);
    unsigned int Count();
    SaveTile* Parent();
    SaveRecord* Data(unsigned int, bool);
    void Remove(unsigned int, bool);
    void Enable(bool);
    void Restore(bool);
    void Filter(bool(__cdecl*)(int));
    SaveTile* Selected();
    int Index();
    void Traverse(void(__cdecl*)(SaveTile*, int), int, int);
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
};
struct SaveSetting
{
    const char* String();
};
extern SaveSetting g_011d25d4, g_011d2c4c, g_011d39f0, g_011d29e8;
int __cdecl SaveFormat(char*, unsigned int, const char*, ...);
static const char currentTrait[] = "_current_value";
int __cdecl Trait(const char*, int);
bool __cdecl FUN_004b71d0();
bool __cdecl FUN_007d4040(int);
void __cdecl SaveVisit(SaveTile*, int);
struct SaveInterface
{
    void Highlight(SaveTile*, int, int);
};
SaveInterface* __cdecl SaveManager();
struct SaveMenu
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
    SaveTile* tile38;
    SaveTile* tile3c;
    SaveTile* tile40;
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
    SaveList saves;
    float threshold;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    bool Flag(int);
    void Button(int, int, unsigned int, float);
    void UpdateSaveList();
};
// @fnv 0x007d3c70
void SaveMenu::UpdateSaveList()
{
    char text[64];
    if (Flag(8))
    {
        unsigned int count = saves.Count();
        if (count > 0)
            saves.Parent()->Int(unk1d0, 1);
        for (int index = saves.Count() - 1; index >= 0; index--)
        {
            SaveTile* tile = saves.At(index, false);
            SaveRecord* data = saves.Data(index, false);
            if (tile && data)
            {
                if (data->IsAuto())
                {
                    saves.Remove(index, false);
                    count--;
                }
                else if (data->IsQuick())
                {
                    saves.Remove(index, false);
                    count--;
                }
            }
        }
        if (count >= 1000)
        {
            saves.Parent()->Action(8);
            saves.Replace(saves.At(1, false));
            saves.Refresh();
        }
        if (count > 0)
        {
            SaveFormat(text, 64, "%s %u/%i %s", g_011d2c4c.String(), count - 1, 1000, g_011d25d4.String());
            saves.Parent()->Text(0xfc4, text, true);
        }
    }
    else if (saves.Parent())
    {
        saves.Parent()->Text(0xfc4, g_011d39f0.String(), true);
        saves.Parent()->Int(unk1d0, 0);
    }
    saves.Enable(true);
    saves.Restore(true);
    saves.Filter(FUN_007d4040);
    if (FUN_004b71d0())
    {
        SaveManager()->Highlight(saves.Parent(), 0xfc3, 1);
        saves.Selected()->Float(Trait(currentTrait, -1), 0.0f, false);
        saves.Selected()->Value(Trait("_SetInCode ", -1), 1.0f);
    }
    threshold = 0.0f;
    saves.Traverse(SaveVisit, 0, saves.Index());
    tile40->Int(0x1004, 1);
    if (Flag(0x100000))
        tile3c->Int(0xfaf, 1);
    else
    {
        Button(6, 1, 0x80000000, -1.0f);
        Button(5, 1, 0x80000000, -1.0f);
        tile38->Text(0xfc4, g_011d29e8.String(), true);
    }
}
}  // namespace fnv_007d3c70

struct SaveLoadTile : Tile
{
    void FUN_00a01350(int, const char*, bool);
    void FUN_00a04640(int);
    float GetAccumulatedFloat();
    float FUN_00a011b0(int);
    float GetTotalFloat();
};
struct SaveLoadList : ListBox<BGSSaveLoadFileEntry*>
{
    bool FUN_007d8d60(Tile*);
    void FUN_007d8810(bool);
    Tile* FUN_00825c00();
};
extern InventoryMenuSetting DAT_011d4fb4;
extern InventoryMenuSetting DAT_011d3294;
extern InventoryMenuSetting DAT_011d3f28;
extern char DAT_01076fdc[];
int __cdecl TraitNameToIDAdd(const char*, int);
struct SaveLoadMenu : StartMenu
{
    void FUN_007d4950(int, int, int, unsigned char);
    void UpdateLayout();
};
// @fnv 0x007d40a0
void SaveLoadMenu::UpdateLayout()
{
    unsigned char text = 0;
    int mode;
    const char* flags;
    if (IsFlagSet(FLAG_DELETE_MODE))
    {
        mode = 0x800;
        flags = DAT_011d4fb4.FUN_00403df0();
    }
    else if (IsFlagSet(FLAG_SAVE_MODE))
    {
        mode = 0x400;
        flags = DAT_011d3294.FUN_00403df0();
    }
    else
    {
        mode = 0x200;
        flags = DAT_011d3f28.FUN_00403df0();
        if (IsFlagSet(FLAG_INGAME))
            text = 2;
    }
    if (m_kOptionHelper.GetHighlightedItem())
    {
        ((SaveLoadList*)&m_kOptionHelper)->FUN_007d8d60(m_kOptionHelper.GetHighlightedItem());
        ((SaveLoadList*)&m_kOptionHelper)->FUN_007d8810(false);
        m_pTiles[6]->Set(0x1004, 0);
        ((SaveLoadTile*)m_pTiles[8])->FUN_00a01350(0xfc4, flags, true);
        ((SaveLoadTile*)m_pTiles[8])->FUN_00a04640(0);
        FUN_007d4950(
            mode,
            (int)(((SaveLoadTile*)m_pTiles[6])->GetTotalFloat() - ((SaveLoadTile*)m_pTiles[8])->FUN_00a011b0(0xfa1) +
                  ((SaveLoadTile*)m_pTiles[8])->FUN_00a011b0(0xfb1) +
                  ((SaveLoadTile*)((SaveLoadList*)&m_kOptionHelper)->FUN_00825c00())->FUN_00a011b0(0xfb1) +
                  ((SaveLoadTile*)m_pTiles[6])->FUN_00a011b0(TraitNameToIDAdd(DAT_01076fdc, -1))),
            (int)(((SaveLoadTile*)m_kOptionHelper.GetHighlightedItem())->GetAccumulatedFloat() +
                  ((text & 2) ? 2 : 1) * ((SaveLoadTile*)m_kOptionHelper.GetHighlightedItem())->FUN_00a011b0(0xfb0)),
            text);
    }
}

struct TileX;
struct OptSI
{
    void* vt;
    const char* GetValueText;
    int f08;
    int f0c;
    const char* pTemplate;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    bool FUN_007cc5d0(int flags);
};
struct ListObj
{
    void* FUN_00559450();
    int* FUN_0073ac90();
    TileX** AddEight(void* node);
    void* DereferenceIfNotNull(void* node);
};
struct TV30
{
    int RemoveFromReactions();
    void FUN_00a0a270(float v, bool b);
};
struct TV38
{
    TV30* FindTraitValue(int id);
    TV30* FUN_00a00f30(int id);
};
struct TileX
{
    int f00;
    ListObj list;
    void FUN_00700320(int a, int b);
    void FUN_00715c60(int a, unsigned int b);
    void FUN_00707e10(const char* name);
    void FUN_00a01350(int a, const char* s, bool b);
    TV38* FUN_00a03eb0(int id);
    float FUN_00a011b0(int id);
    void FUN_00a012d0(int a, float f, bool b);
};
struct LbT : ListBox<OptSI*>
{
    void FUN_007d74f0(int a);
    TileX* CreateListItem(OptSI* o, int a, int b, int c);
};
struct ArrT
{
    unsigned int FUN_0044ddc0();
    OptSI** FUN_00877a30(int idx);
};
struct SetObj
{
    const char* FUN_00403df0();
};
struct PlayerT
{
    bool FUN_005a03f0(unsigned int a);
};
struct SMGlob
{
    char p[0x1d0];
    int f1d0;
};
struct Scratch
{
    int s0;
    int s1;
    int s2;
    int s3;
};
extern ArrT DAT_011dab50;
extern ArrT DAT_011dab88;
extern SetObj DAT_011d42f4;
extern PlayerT* DAT_011dea3c;

bool __cdecl FUN_004b71d0();
bool __cdecl FUN_0070edf0();
int __stdcall FUN_009f996e(int a, Scratch* s);
float __cdecl FUN_00404010(float a, float b);
int __cdecl TraitNameToIDAdd(const char* s, int a);
void __cdecl UpdateSaveOption();
void __cdecl FUN_007d13a0();

struct ThisT
{
    int f00;
    TileX* m04;
    char p08[0x38 - 0x08];
    TileX* m38;
    char p3c[0x114 - 0x3c];
    LbT lb;
    char p144[0x1cc - 0x144];
    int m1cc;
    void FadeTile(int a, int b, unsigned int c, float d);
    void FUN_007d4ce0(OptSI* o, TileX* t);
    void PopulateList(int flags);
};

// @fnv 0x007d42b0
void ThisT::PopulateList(int flags)
{
    float cnt;
    {
        int p;
        bool node;
        ListObj* val;
        TileX* res;
        Scratch v30;
        void* flag;
        {
            TV38* pM;
            unsigned int kIter;
            TileX* j;
            TV30* q;
            TV30* pForm;

            lb.RemoveAll();
            lb.FUN_007d74f0(1);
            FadeTile(2, 1, 0x80000000, -1.0f);
            m38->FUN_00a01350(0xfc4, DAT_011d42f4.FUN_00403df0(), true);

            for (p = 0; (unsigned int)p < DAT_011dab50.FUN_0044ddc0(); p++)
            {
                if ((*DAT_011dab50.FUN_00877a30(p))->FUN_007cc5d0(flags))
                {
                    if ((*DAT_011dab50.FUN_00877a30(p))->f2c == (int)UpdateSaveOption ||
                        (*DAT_011dab50.FUN_00877a30(p))->f2c == (int)FUN_007d30e0)
                    {
                        if (FUN_009f996e(0, &v30))
                        {
                            m1cc = 0;
                            continue;
                        }
                    }
                    res = lb.CreateListItem(*DAT_011dab50.FUN_00877a30(p),
                                            (int)(*DAT_011dab50.FUN_00877a30(p))->GetValueText, 0,
                                            (int)(*DAT_011dab50.FUN_00877a30(p))->pTemplate);
                    if ((*DAT_011dab50.FUN_00877a30(p))->f2c == (int)FUN_007d30e0)
                    {
                        m1cc = (int)res;
                        res->FUN_00700320(((SMGlob*)DAT_011daac0)->f1d0, FUN_004b71d0());
                    }
                    if ((*DAT_011dab50.FUN_00877a30(p))->f2c == (int)FUN_007d13a0)
                    {
                        node = !FUN_0070edf0() && 0 != DAT_011dea3c && !DAT_011dea3c->FUN_005a03f0(4);
                        res->FUN_00700320(0xfaf, node);
                        res->FUN_00700320(((SMGlob*)DAT_011daac0)->f1d0, node);
                        flag = res->list.FUN_00559450();
                        val = &res->list;
                        while (flag != 0 && val != 0 && *val->FUN_0073ac90() != 0)
                        {
                            (*val->AddEight(flag))->FUN_00700320(((SMGlob*)DAT_011daac0)->f1d0, node);
                            (*val->AddEight(flag))->FUN_00700320(0xfaf, node);
                            flag = val->DereferenceIfNotNull(flag);
                        }
                    }
                    if ((*DAT_011dab50.FUN_00877a30(p))->f1c == 2)
                    {
                        res->FUN_00715c60(0x1007, (*DAT_011dab50.FUN_00877a30(p))->f20 - 1);
                    }
                    if ((*DAT_011dab50.FUN_00877a30(p))->f24 != 0)
                    {
                        res->FUN_00715c60(0x1008, (*DAT_011dab50.FUN_00877a30(p))->f24);
                    }
                    FUN_007d4ce0(*DAT_011dab50.FUN_00877a30(p), res);
                }
            }

            for (kIter = 0; (unsigned int)kIter < DAT_011dab88.FUN_0044ddc0(); kIter++)
            {
                if ((*DAT_011dab88.FUN_00877a30(kIter))->FUN_007cc5d0(flags))
                {
                    j = lb.CreateListItem(*DAT_011dab88.FUN_00877a30(kIter),
                                          (int)(*DAT_011dab88.FUN_00877a30(kIter))->GetValueText, 0,
                                          (int)"lb_meter_template");
                    j->FUN_00707e10((*DAT_011dab88.FUN_00877a30(kIter))->GetValueText);
                    j->FUN_00700320(0x1007, 0x10);
                    pM = j->FUN_00a03eb0(0x64);
                    q = pM->FindTraitValue(0xfa3);
                    q->RemoveFromReactions();
                    q->FUN_00a0a270(0.0f, true);
                    pForm = pM->FUN_00a00f30(0xfaf);
                    pForm->RemoveFromReactions();
                    pForm->FUN_00a0a270(0.0f, true);
                    pM = j->FUN_00a03eb0(0x66);
                    q = pM->FindTraitValue(0xfa3);
                    q->RemoveFromReactions();
                    q->FUN_00a0a270(0.0f, true);
                    pForm = pM->FUN_00a00f30(0xfaf);
                    pForm->RemoveFromReactions();
                    pForm->FUN_00a0a270(0.0f, true);
                    pM = j->FUN_00a03eb0(0x65);
                    q = pM->FindTraitValue(0xfa3);
                    q->RemoveFromReactions();
                    q->FUN_00a0a270(1.0f, true);
                    pForm = pM->FUN_00a00f30(0xfaf);
                    pForm->RemoveFromReactions();
                    pForm->FUN_00a0a270(0.0f, true);
                }
            }
        }
    }

    cnt = 0.0f;
    if (8 & flags)
    {
        cnt = FUN_00404010(cnt, m04->FUN_00a011b0(0x1005));
    }
    if (flags & 0x10)
    {
        cnt = FUN_00404010(cnt, m04->FUN_00a011b0(0x1006));
    }
    if (flags & 0x20)
    {
        cnt = FUN_00404010(cnt, m04->FUN_00a011b0(0x1007));
    }
    if (flags & 0x40)
    {
        cnt = FUN_00404010(cnt, m04->FUN_00a011b0(0x1008));
    }
    m04->FUN_00a012d0(TraitNameToIDAdd("_center_x", -1), cnt, true);
}

namespace fnv_007d52a0 {
extern "C" const char str_0107702c[];

extern double DAT_01012060;

extern float DAT_0105559c;

extern unsigned int DAT_011dac64;

extern bool __cdecl FUN_00703d50();

extern void __cdecl FUN_00717280(int);

extern unsigned int __cdecl FUN_00457fe0();

extern int __cdecl FUN_0072fa60(int);

extern "C" int __cdecl TraitNameToIDAdd(const char*, int);

extern void __cdecl ShowMessageBox(const char*, int, int, int, int, int, float, float, const char*, int);

extern void __cdecl UpdateBindingText();

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct InputDevice_7d
{

    int FUN_00a24180(unsigned int, int);

    bool BindInputKey(unsigned int, int, unsigned char);

    int GetField1B08();

    int FUN_00a23a50(unsigned int, int);

    int FUN_00a236b0(int);

    int FUN_00a234c0(int, unsigned int, int);

    int FUN_00a236d0(int);

    unsigned int FUN_00a235f0(int, int);

    int FUN_00a24660(int, int);

    void FUN_00a25180(unsigned int, int, unsigned char);

    int GetAxisState(int, int);
};

struct MenuTile_7d
{

    bool FUN_00a07fc0(int);

    double FUN_00a011b0(int);

    void FUN_00700320(int, int);

    void FUN_00a01350(int, const char*);
};

struct ActionEntry_7d
{

    int first;

    int second;

    int third;

    unsigned int actionCode;
};

struct ActionList_7d
{

    ActionEntry_7d* FUN_007a1910();

    void FUN_007d74f0(bool);

    void ForEachEntry(bool);

    void FUN_007314c0(void(__cdecl*)(), int, int);
};

struct DialogSetting_7d
{

    const char* FUN_004c69f0();

    const char* FUN_00403df0();
    const char* FUN_00403df0(int);
};

extern DialogSetting_7d g_011d4750;

extern DialogSetting_7d g_011d3108;

extern DialogSetting_7d* g_011d5730[];

struct StartMenuInput_7d : StartMenu
{

    bool FUN_004a4080(unsigned int flag);

    void BuildMenuList();

    void FadeTile(int index, int value, unsigned int trait, float delay);

    bool FUN_007ce8f0();

    void FUN_0075f6f0(int index, bool enable);

    bool HandleBindingInput();
};

static InputDevice_7d* GetInputDevice_7d()

{

    return reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720());
}

static void ShowInvalidBindingMessage_7d()

{

    const char* details = reinterpret_cast<DialogSetting_7d*>(&g_011d38b8)->FUN_004c69f0();

    const char* label = g_011d4750.FUN_00403df0();

    ShowMessageBox(label, 0, 0, 0, 1, 0x12, 0.0f, 0.0f, details, 0);
}

// @fnv 0x007d52a0
bool StartMenuInput_7d::HandleBindingInput()

{

    if (FUN_004a4080(0x1000))
    {

        if (reinterpret_cast<MenuTile_7d*>(m_pTiles[2])->FUN_00a07fc0(TraitNameToIDAdd(str_0107702c, -1)))
        {

            if (reinterpret_cast<MenuTile_7d*>(m_pTiles[2])->FUN_00a011b0(TraitNameToIDAdd(str_0107702c, -1)) ==
                DAT_01012060)
            {

                BuildMenuList();

                FadeTile(2, 1, TraitNameToIDAdd(str_0107702c, -1), DAT_0105559c);

                reinterpret_cast<MenuTile_7d*>(m_pTiles[15])->FUN_00700320(0x1004, !static_cast<int>(FUN_004b71d0()));
            }
            else if (FUN_007ce8f0() && !FUN_00703d50())
            {

                bool mapped = false;

                const unsigned int action =
                    reinterpret_cast<ActionList_7d*>(&m_kDownloadOptions)->FUN_007a1910()->actionCode;

                switch ((*reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 0x1c8)))
                {
                case 0: {

                    unsigned int key = 0;
                    while ((key & 0x100) == 0)
                    {

                        if ((reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a24180(key, 1))
                        {

                            mapped = (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))
                                         ->BindInputKey(action, 0, static_cast<unsigned char>(key)) ||
                                     key == 1;

                            FUN_00717280(10);

                            if (!mapped)

                            {

                                ShowMessageBox(g_011d4750.FUN_00403df0(), 0, 0, 0, 1, 0x12, 0.0f, 0.0f,
                                             reinterpret_cast<DialogSetting_7d*>(&g_011d38b8)->FUN_004c69f0(), 0);
                            }

                            break;
                        }
                        ++key;
                    }
                }
                break;
                case 1: {

                    for (int key = 0;
                         !mapped &&
                         key < (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->GetField1B08();
                         ++key)
                    {

                        if ((reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a23a50(key, 1))
                        {

                            FUN_00717280(10);

                            mapped = (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))
                                         ->BindInputKey(action, 1, static_cast<unsigned char>(key));
                        }
                    }

                    if ((reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a24660(0x1c, 1))
                    {

                        mapped = true;

                        (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a25180(action, 1, 0xff);

                        FUN_00717280(10);
                    }
                }
                break;
                case 2: {

                    for (int key = 0;
                         !mapped &&
                         key < (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a236b0(0);
                         ++key)
                    {

                        if ((reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a234c0(0, key, 1))
                        {

                            mapped = (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))
                                         ->BindInputKey(action, 2, static_cast<unsigned char>(key));

                            FUN_00717280(10);
                        }
                    }

                    for (int key = 0;
                         !mapped &&
                         key < (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a236d0(0);
                         ++key)
                    {

                        unsigned int mappedKey =
                            (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a235f0(0, key);

                        mapped = mappedKey != 0xffffffff &&

                                 FUN_00457fe0() >= DAT_011dac64 &&

                                 (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))
                                     ->BindInputKey(action, 2, static_cast<unsigned char>(mappedKey));

                        FUN_00717280(10);

                        if (mapped)

                            DAT_011dac64 = GetTickCount() + 100;
                    }

                    if ((reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a24660(0x1c, 1))
                    {

                        mapped = true;

                        (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->FUN_00a25180(action, 2, 0xff);

                        FUN_00717280(10);
                    }
                }
                break;
                }

                if (mapped)
                {

                    reinterpret_cast<ActionList_7d*>(&m_kDownloadOptions)->FUN_007d74f0(true);

                    reinterpret_cast<ActionList_7d*>(&m_kDownloadOptions)->ForEachEntry(true);

                    reinterpret_cast<ActionList_7d*>(&m_kDownloadOptions)
                        ->FUN_007314c0(&UpdateBindingText, 0, 0x7fffffff);

                    reinterpret_cast<MenuTile_7d*>(m_pTiles[16])
                        ->FUN_00a01350(
                            0xfc4,
                            g_011d5730[*reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 0x1c8)]
                                ->FUN_00403df0(1));

                    FUN_0075f6f0(2, true);
                }
            }

            if (FUN_004b71d0() && FUN_007ce8f0())
            {

                int b;
                int a;
                b = (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->GetAxisState(0, 9);
                a = (reinterpret_cast<InputDevice_7d*>(g_osGlobals->FUN_00877720()))->GetAxisState(0, 10);

                if (FUN_0072fa60(b) > 0x21f1 || FUN_0072fa60(a) > 0x21f1)
                {

                    FUN_00717280(10);

                    {

                        ShowMessageBox(g_011d3108.FUN_00403df0(), 0, 0, 0, 1, 0x12, 0.0f, 0.0f,
                                     reinterpret_cast<DialogSetting_7d*>(&g_011d38b8)->FUN_004c69f0(), 0);
                    }
                }
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_007d52a0

struct FUN_007d62e0_shell : public StartMenu
{
    void EnableAndRemoveHighlightedItem();
};

// @fnv 0x007d62e0
void FUN_007d62e0_shell::EnableAndRemoveHighlightedItem()
{
    this->m_kOptionHelper.SetEnabled(true);
    this->m_kOptionHelper.RemoveItem(this->m_kOptionHelper.GetHighlightedItem());
    this->m_pTiles[6]->Set(0x1004, 1);
    if (!FUN_004b71d0())
    {
        ((FUN_0075f6f0_shell*)this)->FUN_0075f6f0(0x40000, false);
    }
}

extern int DAT_0107704c;

void __cdecl FormHeap_Free(int value);

struct FUN_007d64d0_cls
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_28;

    void Initialize();
};

// Sets the vtable pointer, passes m_28 to FormHeap_Free, then calls InitPointer on this object.
// @fnv 0x007d64d0
void FUN_007d64d0_cls::Initialize()
{
    m_vptr = (int)&DAT_0107704c;
    int value = m_28;
    FormHeap_Free(value);
    ((FUN_007ce690_cls*)this)->InitPointer();
}

struct FlagOwner
{
    bool FUN_009373f0();
};
struct Manager
{
    FlagOwner* FUN_007d6720();
};
Manager* __cdecl FUN_00af2640();
struct TimerProxy
{
    float FUN_00526ac0();
};
extern TimerProxy* DAT_011c3f3c;
extern bool DAT_011daacd, DAT_011daace;
extern const float DAT_01012054;
extern const double DAT_01012060;
struct PanelProxy
{
    unsigned int value;
    void FUN_007d74f0(bool);
    void ForEachEntry(bool);
};
struct ItemListProxy
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Refresh();
};
struct Context
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
    PanelProxy panel;
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
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    ItemListProxy list;
    bool FUN_004a4080(unsigned int);
    void FUN_0075f6f0(unsigned int, bool);
    void ProcessSaveLoadList();
    void SetTileValues();
    void ApplyUserOptions();
    void FadeTile(int, int, unsigned int, float);
    void UpdatePanelState();
};
// Refreshes the list and toggles panel flags based on FUN_004a4080 checks, timer comparison against DAT_01012060, and DAT_011daac0 state.
// @fnv 0x007d6550
void Context::UpdatePanelState()
{
    if (!FUN_004a4080(0x10000))
    {
        list.Refresh();
        if (!FUN_004a4080(0x80000))
            ProcessSaveLoadList();
        if (!FUN_004a4080(1))
        {
            bool j = FUN_00af2640()->FUN_007d6720()->FUN_009373f0();
            bool a = j;
            if (a && DAT_011daac0 && !reinterpret_cast<Context*>(DAT_011daac0)->FUN_004a4080(0x400) && true)
            {
                reinterpret_cast<Context*>(DAT_011daac0)->FUN_0075f6f0(0x400, true);
                DAT_011daace = true;
            }
            FUN_0075f6f0(0x80, true);
            SetTileValues();
        }
        ApplyUserOptions();
        FUN_0075f6f0(2, false);
    }
    if (FUN_004a4080(0x20000))
    {
        FUN_0075f6f0(0x20000, false);
    }
    else
    {
        if (!DAT_011c3f3c || !(DAT_011c3f3c->FUN_00526ac0() > DAT_01012060))
        {
            DAT_011daacd = false;
            FadeTile(0, 1, 0x80000000, DAT_01012054);
            panel.FUN_007d74f0(true);
        }
        if (FUN_004a4080(0x10000))
        {
            if (!DAT_011c3f3c || !(DAT_011c3f3c->FUN_00526ac0() > DAT_01012060))
            {
                panel.ForEachEntry(true);
                FUN_0075f6f0(0x10000, false);
            }
        }
    }
}

namespace fnv_007d7b50 {
struct X
{
    void* f0;
    int f4;
    unsigned char b8;
};

struct Ctx
{
    X* f0;
};

struct Iter
{
    Ctx* __thiscall FUN_006815c0();
    Iter* __thiscall FUN_00726070();
};

struct FUN_007d8fe0_shell
{
    void __thiscall FUN_007d8fe0(int v);
};

struct FUN_007d7b50_shell
{
    void __thiscall ForEachEntry(unsigned char arg);
};

// Iterates the list at this+4 and calls FUN_007d8fe0 with each entry's f0 when arg is 0 or the entry's b8 is 0.
// @fnv 0x007d7b50
void __thiscall FUN_007d7b50_shell::ForEachEntry(unsigned char arg)
{
    Iter* it = this ? (Iter*)((char*)this + 4) : 0;
    for (; it != 0 && it->FUN_006815c0()->f0 != 0; it = it->FUN_00726070())
    {
        if (arg == 0 || ((X*)it->FUN_006815c0()->f0)->b8 == 0)
            ((FUN_007d8fe0_shell*)this)->FUN_007d8fe0((int)((X*)it->FUN_006815c0()->f0)->f0);
    }
}
}  // namespace fnv_007d7b50

// 0x0084ff30 CreateScriptMessageDirectory (claim clm_c35ffe5e4677479fb2aa)
// BOOL __thiscall(void* this, char* lpPathName): builds path in caller buffer and creates it.
// v1 = v0 with extern "C" __declspec(dllimport) CreateDirectoryA (fix ff15 import call form).

struct FUN_0084ff30_shell
{
    int CreateScriptMessageDirectory(char* lpPathName);
};

char* __cdecl FUN_004dc110(void);
int __cdecl strcpy_s(char* Destination, unsigned int SizeInBytes, const char* Source);
int __cdecl strcat_s(char* Destination, unsigned int SizeInBytes, const char* Source);
const char* __cdecl PrepareScriptMessage(const char*, bool);
struct GlobalObject2_0045cfe0;
extern GlobalObject2_0045cfe0 g_011c3f74;
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* lpPathName, void* lpSecurityAttributes);

// Builds a path from FUN_004dc110 and a prepared script message, then calls CreateDirectoryA on it and returns the result.
// @fnv 0x0084ff30
int FUN_0084ff30_shell::CreateScriptMessageDirectory(char* pcPathBuffer)
{
    strcpy_s(pcPathBuffer, 0x104u, FUN_004dc110());
    strcat_s(pcPathBuffer, 0x104u, PrepareScriptMessage(((InventoryMenuSetting*)&g_011c3f74)->FUN_00403df0(), false));
    return CreateDirectoryA(pcPathBuffer, 0);
}

namespace fnv_007d69f0 {
struct Item_007d69f0
{
    void* FUN_00b008d0();
};

struct Node_007d69f0
{
    Item_007d69f0** B006815c0();
    Node_007d69f0* FUN_00726070();
};

struct List_007d69f0
{
    bool FUN_008256d0();
};

struct ListBox_007d69f0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    void FUN_00764430(int a, char* b, int c, int d);
};

struct DLC_007d69f0
{
    void AddInstalledDlcPackages(int a, int b);
    void FUN_00af2b10(int a, int b);
    List_007d69f0* FUN_007d6bb0();
    Node_007d69f0* GetOffsetC();
};

struct Holder_007d69f0
{
    DLC_007d69f0* FUN_005dfa10();
};

Holder_007d69f0* __cdecl FUN_00af2640();

struct DH_007d69f0
{
    int GetZero();
    void LoadDataFiles(int a);
    void InitAllScripts();
    void FUN_004614e0();
};

struct SLG_007d69f0
{
    bool FUN_007d6bd0(bool b);
};

struct PL_007d69f0
{
    void FUN_00970d50();
};

struct TIM_007d69f0
{
    void FUN_006003c0();
};

struct InvSetting_007d69f0
{
    char* FUN_00403df0();
};

struct Menu_007d69f0
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
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    ListBox_007d69f0 m_kOptionIndexList;
    void FUN_0075f6f0(int a, int b);
};

extern DH_007d69f0* DAT_011c3f2c;
extern SLG_007d69f0* DAT_011ddf38;
extern PL_007d69f0 DAT_011e0e80;
extern TIM_007d69f0* DAT_011cb6a0;
extern Menu_007d69f0* DAT_011daac0;
extern InvSetting_007d69f0 DAT_011d3ad4;
extern int DAT_01000000;

void __cdecl ClearAllElements();
void __cdecl FUN_00704000();
void __cdecl FUN_00ecacb2(char* dst, void* src, unsigned int size);

// @fnv 0x007d69f0
void __cdecl FUN_007d69f0()
{
    int zero = 0;
    FUN_00af2640()->FUN_005dfa10()->AddInstalledDlcPackages(zero, -1);
    FUN_00af2640()->FUN_005dfa10()->FUN_00af2b10(zero, 0);
    if (DAT_011c3f2c->GetZero())
    {
        bool bOld4 = DAT_011ddf38->FUN_007d6bd0(false);
        DAT_011c3f2c->LoadDataFiles(1);
        DAT_011c3f2c->InitAllScripts();
        DAT_011ddf38->FUN_007d6bd0(bOld4);
        DAT_011e0e80.FUN_00970d50();
        DAT_011c3f2c->FUN_004614e0();
    }
    DAT_011cb6a0->FUN_006003c0();
    ClearAllElements();
    FUN_00704000();
    DLC_007d69f0* kPDLC = FUN_00af2640()->FUN_005dfa10();
    if (!kPDLC->FUN_007d6bb0()->FUN_008256d0())
    {
        DAT_011daac0->FUN_0075f6f0((int)&DAT_01000000, 1);
    }
    DAT_011daac0->m_kOptionIndexList.v07();
    DAT_011daac0->m_kOptionIndexList.FUN_00764430(-1, DAT_011d3ad4.FUN_00403df0(), 0, 0);
    char* p;
    Item_007d69f0* pItem2 = 0;
    Node_007d69f0* pNode = kPDLC->GetOffsetC();
    while (pNode != 0)
    {
        pItem2 = *pNode->B006815c0();
        if (pItem2 != 0)
        {
            void* e = pItem2->FUN_00b008d0();
            char j[0x104];
            FUN_00ecacb2(j, e, 0x104);
            p = j;
            DAT_011daac0->m_kOptionIndexList.FUN_00764430(0, p, 0, 0);
        }
        pNode = pNode->FUN_00726070();
    }
}
}  // namespace fnv_007d69f0

namespace fnv_007d4df0 {
struct StrX
{
    char* p;
    unsigned short a, b;
    StrX();
    ~StrX();
    const char* FUN_00559450();
    void FUN_00406f60(const char* fmt, ...);
};
struct SettingX
{
    const char* FUN_00403df0();
};
extern SettingX DAT_011dabb0x;
extern SettingX DAT_011d1f14, DAT_011c3cb4, DAT_011d3b2c, DAT_011d3954, DAT_011d21b4;
struct GlobX
{
    bool GetBoolValue();
};
extern GlobX DAT_011dabb0;
struct TileX
{
    void FUN_00a012d0(int m_uiSoundID, float f, bool b);
    void FUN_00a01350(int m_uiSoundID, const char* s, bool b);
    void FUN_00700320(int m_uiSoundID, int iVal);
};
struct ItemX
{
    bool FUN_00846b30();
    char* FUN_0075f8c0();
    int FUN_007d5160();
    char* FUN_007d5140();
    char* FUN_007d5180();
    char* FUN_005a8080();
};
struct ListX
{
    ItemX* FUN_007a1910();
};
struct HudX
{
    void FUN_007d5120();
    void Reset();
};
HudX* FUN_007cb710();
bool FUN_004b71d0();
int __cdecl FUN_00408b20(const char* a, const char* b);
int __cdecl TraitNameToIDAdd(const char* s, int i);
struct MenuX
{
    char pad0[0x38];
    TileX* m38;
    char pad3c[0x18];
    TileX* m54;
    TileX* m58;
    char pad5c[0x14];
    TileX* m70;
    TileX* m74;
    char pad78[8];
    TileX* m80;
    char pad84[0x174 - 0x84];
    ListX kList;
    bool FUN_004a4080(int i);
    void FUN_0075f6f0(int i, int j);
    bool FUN_007d51a0(ItemX* p);
    void UpdateTargetInfo();
};
// Updates menu tiles using the selected item, setting text and values and toggling visibility states.
// @fnv 0x007d4df0
void MenuX::UpdateTargetInfo()
{
    if (FUN_004a4080(0x40000))
    {
        FUN_0075f6f0(0x40000, 0);
        return;
    }
    bool bA = false;
    bool abShow8[4];
    abShow8[0] = false;
    abShow8[1] = false;
    abShow8[2] = false;
    abShow8[3] = false;
    ItemX* pkItem9 = kList.FUN_007a1910();
    if (pkItem9)
    {
        if (FUN_004b71d0() && DAT_011dabb0.GetBoolValue())
        {
            FUN_007cb710()->FUN_007d5120();
            bA = true;
            m54->FUN_00a012d0(0xfa9, 0.0f, true);
        }
        else
        {
            bA = FUN_007d51a0(pkItem9);
        }
        if (pkItem9->FUN_00846b30())
        {
            m58->FUN_00a01350(0xfc4, DAT_011d1f14.FUN_00403df0(), true);
            abShow8[0] = true;
            abShow8[1] = false;
            abShow8[2] = false;
            abShow8[3] = false;
        }
        else
        {
            char* pcName8 = pkItem9->FUN_0075f8c0();
            char acSpace2[2];
            acSpace2[0] = 0;
            acSpace2[1] = 0;
            if (!FUN_00408b20(DAT_011c3cb4.FUN_00403df0(), "FRENCH"))
                acSpace2[0] = ' ';
            m58->FUN_00a01350(0xfc4, pcName8, true);
            abShow8[0] = pcName8 != 0;
            StrX kStr6;
            kStr6.FUN_00406f60("%s %d%s: %s", DAT_011d3b2c.FUN_00403df0(), pkItem9->FUN_007d5160(), acSpace2,
                               pkItem9->FUN_007d5140());
            m70->FUN_00a01350(0xfc4, kStr6.FUN_00559450(), true);
            abShow8[1] = true;
            kStr6.FUN_00406f60("%s%s: %s", DAT_011d3954.FUN_00403df0(), acSpace2, pkItem9->FUN_007d5180());
            m74->FUN_00a01350(0xfc4, kStr6.FUN_00559450(), true);
            abShow8[2] = true;
            kStr6.FUN_00406f60("%s%s: %s", DAT_011d21b4.FUN_00403df0(), acSpace2, pkItem9->FUN_005a8080());
            m80->FUN_00a01350(0xfc4, kStr6.FUN_00559450(), true);
            abShow8[3] = true;
        }
    }
    else if (FUN_004b71d0())
    {
        FUN_007cb710()->Reset();
    }
    m38->FUN_00700320(TraitNameToIDAdd("_target", -1), pkItem9 != 0);
    m54->FUN_00700320(0xfa3, bA);
    m58->FUN_00700320(0xfa3, abShow8[0]);
    m70->FUN_00700320(0xfa3, abShow8[1]);
    m74->FUN_00700320(0xfa3, abShow8[2]);
    m80->FUN_00700320(0xfa3, abShow8[3]);
}
}  // namespace fnv_007d4df0

namespace fnv_007d5830 {
// StartMenu per-frame update: pre-fade input wait, fade-in completion, DLC wait/corrupt messages.
struct SMInputManager
{
    int FUN_00a23a50(int aiDevice, int aiKey);
};
struct SMOSGlobals
{
    SMInputManager* FUN_00877720();
};
struct SMUpdater
{
    void UpdateLoadingScreen();
};
struct SMTile
{
    bool FUN_00a07ed0(int aiTrait);
    float FUN_00a011b0(int aiTrait);
};
struct SMGlobalValue
{
    float GetValue();
};
struct SMDataHandler
{
    int FUN_0046fe10();
};
struct SMIntSetting
{
    int* Int();
};
struct SMStringSetting
{
    const char* GetString();
};
struct SMTextSetting
{
    const char* FUN_00403df0();
};
struct SMMessageMenu
{
    int FUN_0059bb30();
};
struct SMMessageTile
{
    SMMessageMenu* FUN_00a03c90();
};

extern SMOSGlobals* g_pkSMOSGlobals;
extern SMUpdater* g_pkSMUpdater;
extern SMGlobalValue* g_pkSMFadeGlobal;
extern SMDataHandler* g_pkSMDataHandler;
extern SMIntSetting g_kSMHudOpacity;
extern SMStringSetting g_kSMDLCWaitText;
extern SMTextSetting g_kSMDLCCorruptText;
extern SMTextSetting g_kSMDLCCorruptButton;
extern bool g_bSMFlag;
extern const char DAT_01011584[];  // ""
SMMessageTile* __cdecl FUN_00a09030(int aiMenuID);
int __cdecl FUN_00647b70(int aiA, int aiB);
int __cdecl MinInt(int aiA, int aiB);
void __cdecl FUN_0078d2d0(int aiValue);
void __cdecl ShowMessageBox(const char* apText, int a1, int a2, int a3, int a4, int aiType, float afA, float afB,
                          const char* apButton, ...);
void __cdecl ProcessArcList();
void __cdecl FUN_007d69f0();

struct SMStartMenu : StartMenu
{
    void SetFlag(Flag aFlag, bool abSet);
    void FadeTile(int aiA, int aiB, int aiTrait, float afValue);
    void UpdatePanelState();
    bool FUN_007d5830();
};
extern SMStartMenu* g_pkSMStartMenu;

// Updates start menu fade-in, HUD opacity, and DLC wait/corrupt message flags, returning false only when in-game.
// @fnv 0x007d5830
bool SMStartMenu::FUN_007d5830()
{
    if (IsFlagSet(FLAG_INGAME))
        return false;
    if (IsFlagSet(FLAG_IIS_PREFADE) && g_pkSMUpdater && g_pkSMOSGlobals->FUN_00877720()->FUN_00a23a50(0, 2))
        g_pkSMUpdater->UpdateLoadingScreen();
    if (IsFlagSet(FLAG_FADE_IN) && !((SMTile*)m_pTiles[3])->FUN_00a07ed0(0xfa9) &&
        (!g_pkSMFadeGlobal || !(g_pkSMFadeGlobal->GetValue() > 0.0)))
    {
        float fTileAlpha = ((SMTile*)m_pTiles[3])->FUN_00a011b0(0xfa9);
        if (fTileAlpha == 0.0)
        {
            FadeTile(3, 1, 0xfa9, 1.0f);
            FUN_0078d2d0(1);
        }
        else if (fTileAlpha == 255.0)
        {
            UpdatePanelState();
            int iMinOpacity;
            int iValue = *g_kSMHudOpacity.Int();
            iMinOpacity = 30;
            iValue += g_pkSMDataHandler->FUN_0046fe10() * 5;
            iValue = MinInt(FUN_00647b70(iValue, iMinOpacity), 50);
            *g_kSMHudOpacity.Int() = iValue;
            g_bSMFlag = false;
            SetFlag(FLAG_FADE_IN, false);
        }
    }
    if (IsFlagSet(FLAG_DLC_WAIT_MESSAGE))
    {
        SMMessageTile* pkMessage = FUN_00a09030(1001);
        if (!pkMessage)
        {
            ShowMessageBox(g_kSMDLCWaitText.GetString(), 0, 0, 0, 0, 18, 0.0f, 0.0f, DAT_01011584);
        }
        else if (pkMessage->FUN_00a03c90()->FUN_0059bb30() == 1)
        {
            SetFlag(FLAG_DLC_WAIT_MESSAGE, false);
            ProcessArcList();
            FUN_007d69f0();
        }
    }
    if (IsFlagSet(FLAG_NEW_DLC_INSTALLED))
    {
        g_pkSMStartMenu->SetFlag(FLAG_DLC_WAIT_MESSAGE, true);
        g_pkSMStartMenu->SetFlag(FLAG_NEW_DLC_INSTALLED, false);
    }
    if (IsFlagSet(FLAG_DLC_CORRUPT_MESSAGE) && !FUN_00a09030(1001))
    {
        SetFlag(FLAG_DLC_CORRUPT_MESSAGE, false);
        ShowMessageBox(g_kSMDLCCorruptText.FUN_00403df0(), 0, 0, 0, 0, 18, 0.0f, 0.0f,
                     g_kSMDLCCorruptButton.FUN_00403df0(), 0);
    }
    return true;
}
}  // namespace fnv_007d5830

namespace fnv_007d5af0 {
struct EntryOps
{
    bool FUN_00846710();
};
struct TileOpsLocal
{
    float FUN_00a011b0(int);
    bool FUN_00a07ed0(int);
};
struct SaveListOps
{
    bool FUN_007d88a0();
    unsigned FUN_007d87b0();
    TileOpsLocal* FUN_00825c00();
    void FUN_007314c0(void (*)(Tile*, EntryOps*), int, int);
    EntryOps* FUN_007a1910();
};
struct SettingOpsLocal
{
    const char* FUN_00403df0();
};
extern SettingOpsLocal g_011d38b8, g_011d4420;
struct SaveManagerOps
{
    bool FUN_008503b0(const char*, int, bool);
};
extern SaveManagerOps* DAT_011de134;
extern unsigned DAT_011dac68;
struct InputOps
{
    int FUN_00a23a50(int, int);
};
struct GlobalInputOps
{
    InputOps* FUN_00877720();
};
extern GlobalInputOps* g_osGlobals;
struct InterfaceOps
{
    unsigned FUN_007d5eb0();
    void Reset();
};
InterfaceOps* FUN_007cb710();
unsigned gm_GetTickCount();
int TraitNameToIDAdd(const char*, int);
void InitSaveLoadTile(Tile*, EntryOps*);
void FUN_007d5f50();
void ShowMessageBox(const char*, int, int, void (*)(), int, int, float, float, const char*, int);
void CloseStartMenu(bool);
bool FUN_004b71d0();
struct MenuVirtualOps
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Activate(int, int);
};
struct StartSaveMenu : StartMenu
{
    EntryOps* operation;
    void FUN_0075f6f0(int, bool);
    void FUN_007d4b40();
    void UpdateSaveList();
    void EnableAndRemoveHighlightedItem();
    bool FUN_007d51a0(bool);
    void FadeTile(int, int, unsigned, float);
    bool FUN_007d5af0();
};

// Processes save/load flags, updates the save list, may activate an entry, and may fade tile 11 after the interface timer reaches 500.
// @fnv 0x007d5af0
bool StartSaveMenu::FUN_007d5af0()
{
    if (m_kOptionHelper.IsEnabled())
    {
        if (IsFlagSet(FLAG_SAVE_WAIT_MESSAGE))
        {
            DAT_011dac68 = gm_GetTickCount() + 3000;
            FUN_0075f6f0(0x4000, false);
            FUN_0075f6f0(0x8000, true);
        }
        else if (IsFlagSet(FLAG_SAVE_WAIT_SAVING))
        {
            if (!IsFlagSet(FLAG_SAVE_SAVING) &&
                ((operation && operation->FUN_00846710()) || (!operation && DAT_011de134->FUN_008503b0(0, -1, false))))
            {
                FUN_0075f6f0(0x10000000, true);
            }
            else if (!IsFlagSet(FLAG_SAVE_SAVING))
            {
                ShowMessageBox(g_011d4420.FUN_00403df0(), 0, 0, FUN_007d5f50, 1, 0, 0.0f, 0.0f, g_011d38b8.FUN_00403df0(),
                             0);
                FUN_0075f6f0(0x8000000, true);
                FUN_0075f6f0(0x8000, false);
                FUN_0075f6f0(0x10000000, false);
            }
            unsigned ticks = gm_GetTickCount();
            if (ticks >= DAT_011dac68 && ticks - DAT_011dac68 >= 1000)
                DAT_011dac68 = gm_GetTickCount() + 1000;
            if (ticks >= DAT_011dac68)
            {
                CloseStartMenu(true);
                FUN_0075f6f0(0x8000, false);
                FUN_0075f6f0(0x10000000, false);
            }
        }
        else if (IsFlagSet(FLAG_LOADING_SAVEGAMES) &&
                 !((TileOpsLocal*)m_pTiles[6])->FUN_00a07ed0(TraitNameToIDAdd("_alpha", -1)))
        {
            FUN_007d4b40();
            UpdateSaveList();
            FUN_0075f6f0(0x100000, false);
        }
        else if (IsFlagSet(FLAG_SAVELOAD_BACKOUT) && !m_kThirdOptionListBox.IsEnabled())
        {
            EnableAndRemoveHighlightedItem();
        }
        else
        {
            if (((SaveListOps*)&m_kOptionHelper)->FUN_007d88a0())
            {
                float value =
                    ((SaveListOps*)&m_kOptionHelper)->FUN_00825c00()->FUN_00a011b0(TraitNameToIDAdd("_current_value", -1));
                if (value > m_fMenuTimer)
                {
                    int first = ((SaveListOps*)&m_kOptionHelper)->FUN_007d87b0() + m_fMenuTimer;
                    int last = first + (int)(value - m_fMenuTimer);
                    ((SaveListOps*)&m_kOptionHelper)->FUN_007314c0(InitSaveLoadTile, first, last);
                    m_fMenuTimer = value;
                }
                if (g_osGlobals->FUN_00877720()->FUN_00a23a50(1, 2) && ((SaveListOps*)&m_kOptionHelper)->FUN_007a1910())
                {
                    ((MenuVirtualOps*)this)->Activate(4, 0);
                }
            }
            if (FUN_004b71d0() && FUN_007cb710()->FUN_007d5eb0() >= 500)
            {
                if (FUN_007d51a0(false))
                    FadeTile(11, 1, 0xfa9, -1.0f);
                FUN_007cb710()->Reset();
            }
        }
        return true;
    }
    return false;
}
}  // namespace fnv_007d5af0

namespace fnv_007d1b30 {
GlobalObject_004de370 g_011c71ac;

// @fnv 0x007d1b30
void FUN_007d1b30()
{
    g_011c71ac.FUN_00450410();
}
}  // namespace fnv_007d1b30

namespace fnv_007d30d0 {
// @fnv 0x007d30d0
void FUN_007d30d0()
{
    g_011d8c4c.GetBoolValue();
}
}  // namespace fnv_007d30d0

struct TESFullName
{
    const char* GetFullName();
};
struct P01ObjA
{
    TESBoundObject* GetNext();
};
struct FUN_008467b0_shell
{
    bool LoadSaveEntry();
};
class TES
{
  public:
    void RefreshWorldState(int, int, int);
};
struct PlayerCharacterQ
{
    static bool UpdatePlayerStatus();
};
struct PC7d;
extern PC7d* g_thePlayer;
extern TES* g_TES;
extern StartMenu* DAT_011daac0;
int __cdecl FUN_00408b20(const char*, const char*);
void __cdecl FUN_00af59e0();
void __cdecl CloseStartMenu(bool);
void HandleBackAction();

// Loads a save game from the start menu, refreshes world state if the player name matches, and closes the menu or handles back action based on the result.
// @fnv 0x007d3470
void FUN_007d3470()
{
    BGSSaveLoadFileEntry* psavegame;
    bool bresult;
    if (DAT_011daac0 && *(BGSSaveLoadFileEntry**)((char*)DAT_011daac0 + 0x1b0))
    {
        FUN_00af59e0();
        psavegame = *(BGSSaveLoadFileEntry**)((char*)DAT_011daac0 + 0x1b0);
        if (g_thePlayer && PlayerCharacterQ::UpdatePlayerStatus())
        {
            TESNPC* tempPlayer = dynamic_cast<TESNPC*>(((P01ObjA*)g_thePlayer)->GetNext());
            if (tempPlayer && ((TESFullName*)((char*)tempPlayer + 0xd0))->GetFullName() &&
                ((FUN_0075f8c0_shell*)psavegame)->FUN_0075f8c0() &&
                FUN_00408b20(((TESFullName*)((char*)tempPlayer + 0xd0))->GetFullName(),
                             ((FUN_0075f8c0_shell*)psavegame)->FUN_0075f8c0()))
                g_TES->RefreshWorldState(1, 0, 0);
        }
        bresult = ((FUN_008467b0_shell*)psavegame)->LoadSaveEntry();
        if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_INGAME) && bresult)
            CloseStartMenu(true);
        else if (bresult || (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_MISSING_CONTENT)))
            HandleBackAction();
        else
            HandleBackAction();
    }
}

struct BSStrHelper7d5
{
    operator const char*() const;
};
// @fnv 0x007d5280
const char* __fastcall FUN_007d5280(void* p)
{
    return *(BSStrHelper7d5*)((char*)p + 0x40);
}

namespace fnv_007d6eb0 {
// Constructor (no arguments): calls the base constructor, constructs the
// sub-object at +4, stores the vtable-like pointer, zeroes integer and word
// fields, zeroes three float fields, runs a two-argument setup on the object
// and then hands the object to a registration routine.

struct NodeBase
{
    unsigned int unk00;
    NodeBase();
    void Setup(int a, int b);
};

struct SubObjA
{
    SubObjA();
    ~SubObjA();
    unsigned int unk00;
    unsigned int unk04;
};

void RegisterNode(void* node);

struct FUN_007d6eb0_cls : NodeBase
{
    SubObjA m_sub;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned short m_1c;
    unsigned short unk1E;
    float m_20;
    float m_24;
    float m_28;
    unsigned short m_2c;

    FUN_007d6eb0_cls();
};

// Sets several scalar members to zero, calls Setup(0, 1), and registers this node.
// @fnv 0x007d6eb0
FUN_007d6eb0_cls::FUN_007d6eb0_cls() : NodeBase(), m_sub()
{
    *(const char**)this = "pv}";
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;
    Setup(0, 1);
    RegisterNode(this);
}
}  // namespace fnv_007d6eb0

namespace fnv_007cbaf0 {
#include <windows.h>
#include <stdio.h>
#include <string.h>

class AutoMemContext
{
    unsigned int previousContext;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
class NiSourceTexture;
struct TES
{
    void CreateTextureImage(const char*, NiPointer<NiSourceTexture>&, bool, bool);
};
extern TES* g_TES;
struct NiAVObject;
struct TileAccess
{
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
    void FUN_00715c60(int, int);
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    NiAVObject* FUN_0056c7f0();
    Menu* FUN_00a03c90();
};
struct NiAVObject
{
    void FUN_00440490(float);
};
struct OptionAccess : StartMenu::Option
{
    bool FUN_007cc5d0(unsigned int);
};
struct OptionArray
{
    unsigned int FUN_0044ddc0();
    OptionAccess*& FUN_00877a30(unsigned int);
};
struct OptionListAccess
{
    void FUN_0075a0d0(Tile*, const char*);
    Tile* CreateListItem(StartMenu::Option*, const char*, int, const char*);
    unsigned int GetRaceCount();
    void FUN_007d74f0(int);
};
struct SaveManagerAccess
{
    void CreateScriptMessageDirectory(char*);
    bool FUN_00850fe0(bool);
};
struct InterfaceAccess
{
    int FUN_00714f70(int);
};
struct MenuAccess
{
    int FUN_0059bb30();
};
struct HiddenTileList
{
    void FUN_004ed8c0(TileAccess**);
};
extern HiddenTileList g_011dabd8;
struct OSAccess
{
    void FUN_00871dc0();
};
struct VATSAccess
{
    void FUN_009c6c30(int, bool);
};
extern VATSAccess DAT_011f2250;
struct TESGlobalValueReader
{
    float GetValue();
};
extern TESGlobalValueReader* DAT_011c3f3c;
struct CallbackAccess
{
    void FUN_00af2d70(void(__cdecl*)(int));
};
struct SaveGameAccess
{
    void SetFlag80(bool);
};
extern SaveGameAccess* g_BGSSaveLoadGame;
struct SettingOpsLocal;
extern SettingOpsLocal g_011c3f74, g_011d2eec, g_011d48a0, g_011d2070, g_011d1fec;
char* FUN_004dc110();
const char* PrepareScriptMessage(const char*, bool);
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
void FUN_007d06c0();
void FUN_007d0440();
void FUN_007d0680();
void ShowSelectedMenuMessage();
void PopulateFileList();
int FUN_007cc6d0();
TileAccess* FUN_00a09030(int);
int TraitNameToIDAdd(const char*, int);
double FUN_00706e50();
double FUN_00706e70();
int FUN_0070ede0();
bool FUN_007cc5f0(int);
bool FUN_007079b0();
bool FUN_00702450(int);
bool FUN_0070edf0();
void FUN_00703fe0(bool);
void FUN_007aaf20(bool);
bool FUN_007050d0();
void SetDialogMenuActive(bool);
void PlayAudioMedia(int, const char*, int, bool, bool, float, int);
void FUN_008304c0();
CallbackAccess* FUN_00af2c90();

struct MenuOpsLocal
{
    void FUN_0075f6f0(int, bool);
    void FadeTile(int, int, unsigned int, float);
};
struct SettingOpsLocal
{
    const char* FUN_00403df0();
};
extern OptionArray g_011dab88;
extern StartMenu* DAT_011daac0;
extern SaveManagerAccess* DAT_011de134;
extern OSGlobals* g_osGlobals;
InterfaceAccess* FUN_004b7210();
void FUN_007d6990(int);
void FUN_005b5e40(int, const char*);

struct StartMenuInit : StartMenu
{
    unsigned int unk1b0;
    unsigned int unk1b4;
    NiPointer<NiSourceTexture> screenshotFrame;
    Tile* downloadsTile;
    Tile* continueTile;
    Tile* loadTile;
    int unk1c8;
    int unk1cc;
    int disabledTrait;
    void FUN_007cbaf0(bool inGame, bool forceReload);
    void ApplyUserOptions();
    void FUN_00a1dc20(int);
};
// Initializes the start menu by creating the screenshot frame, configuring option lists, populating tiles, and handling in-game versus out-of-game state.
// @fnv 0x007cbaf0
void StartMenuInit::FUN_007cbaf0(bool inGame, bool forceReload)
{
    AutoMemContext f((MEM_CONTEXT)13, true,
                     "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Menus\\StartMenu.cpp", 426);
    g_TES->CreateTextureImage("Textures\\Interface\\Main\\screenshot_alpha_frame.dds", screenshotFrame, false, false);
    ((MenuOpsLocal*)this)->FUN_0075f6f0(1, inGame);
    ((MenuOpsLocal*)this)->FUN_0075f6f0(4, forceReload);
    ((MenuOpsLocal*)this)->FUN_0075f6f0(DAT_011a0294 && !inGame ? 0x80000 : 16, true);
    ((OptionListAccess*)&m_kFirstOptionListBox)->FUN_0075a0d0(m_pTiles[0], "lb_item_template");
    ((OptionListAccess*)&m_kSecondOptionListBox)->FUN_0075a0d0(m_pTiles[1], "lb_item_template");
    ((OptionListAccess*)&m_kThirdOptionListBox)->FUN_0075a0d0(m_pTiles[7], "lb_item_template");
    ((OptionListAccess*)&m_kDownloadOptions)->FUN_0075a0d0(m_pTiles[2], 0);
    ((OptionListAccess*)&m_kOptionHelper)->FUN_0075a0d0(m_pTiles[6], "lb_saveload_template");
    ((OptionListAccess*)&m_kOptionIndexList)->FUN_0075a0d0(m_pTiles[14], "lb_item_template");
    ((MenuOpsLocal*)this)->FUN_0075f6f0(128, !inGame);
    char s[260];
    if (DAT_011de134)
        ((SaveManagerAccess*)DAT_011de134)->CreateScriptMessageDirectory(s);
    else
    {
        FUN_00406d30(s, 260, FUN_004dc110());
        FUN_00406d50(s, 260, PrepareScriptMessage(g_011c3f74.FUN_00403df0(), false));
    }
    FUN_00406d50(s, 260, "*");
    FUN_00406d50(s, 260, ".fos");
    WIN32_FIND_DATAA cf;
    HANDLE q = FindFirstFileA(s, &cf);
    bool eb = q != INVALID_HANDLE_VALUE;
    FindClose(q);
    for (unsigned int i = 0; i < g_011dab88.FUN_0044ddc0(); ++i)
    {
        Tile* tile = 0;
        bool disabled = (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == FUN_007d06c0 &&
                         !((SaveManagerAccess*)DAT_011de134)->FUN_00850fe0(false)) ||
                        (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == FUN_007d0440 &&
                         ((inGame && forceReload) || (!inGame && !eb))) ||
                        (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == FUN_007d0680 && !eb) ||
                        (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == ShowSelectedMenuMessage &&
                         FUN_00a09030(FUN_007cc6d0()));
        if ((inGame && ((OptionArray*)&g_011dab88)->FUN_00877a30(i)->FUN_007cc5d0(2)) ||
            (!inGame && ((OptionArray*)&g_011dab88)->FUN_00877a30(i)->FUN_007cc5d0(1)))
            tile = ((OptionListAccess*)&m_kFirstOptionListBox)
                       ->CreateListItem(((OptionArray*)&g_011dab88)->FUN_00877a30(i), 0, 0, 0);
        else if (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->FUN_007cc5d0(4))
            tile = ((OptionListAccess*)&m_kSecondOptionListBox)
                       ->CreateListItem(((OptionArray*)&g_011dab88)->FUN_00877a30(i), 0, 0, 0);
        if (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == PopulateFileList)
            downloadsTile = tile;
        else if (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == FUN_007d0440)
            loadTile = tile;
        else if (((OptionArray*)&g_011dab88)->FUN_00877a30(i)->m_pActionCallback == FUN_007d0680)
            continueTile = tile;
        if (tile)
        {
            ((TileAccess*)tile)->FUN_00a01350(0xfc4, ((OptionArray*)&g_011dab88)->FUN_00877a30(i)->GetValueText, true);
            if (disabled)
                ((TileAccess*)tile)->FUN_00700320(disabledTrait, 0);
        }
    }
    ((TileAccess*)m_pTiles[0])
        ->FUN_00715c60(TraitNameToIDAdd("_number_of_visible_items", -1),
                       ((OptionListAccess*)&m_kFirstOptionListBox)->GetRaceCount());
    ((TileAccess*)m_pTiles[1])
        ->FUN_00715c60(TraitNameToIDAdd("_number_of_visible_items", -1),
                       ((OptionListAccess*)&m_kSecondOptionListBox)->GetRaceCount());
    ((TileAccess*)m_pTiles[10])->FUN_00a01350(0xfc4, "1.4.0.525", true);
    ((TileAccess*)m_pTiles[9])->FUN_00a01350(0xfc4, g_011d2eec.FUN_00403df0(), true);
    ((TileAccess*)m_pTiles[20])->FUN_00a01350(0xfc4, g_011d48a0.FUN_00403df0(), true);
    ((TileAccess*)m_pTiles[15])->FUN_00a01350(0xfc4, g_011d2070.FUN_00403df0(), true);
    ((TileAccess*)m_pTiles[5])->FUN_00a01350(0xfc4, g_011d1fec.FUN_00403df0(), true);
    ((TileAccess*)m_pTiles[21])->FUN_00700320(0xfa3, 0);
    bool p = FUN_00706e50() <= 640.0 ? 1 : 0;
    if (p && m_pTiles[3])
        ((TileAccess*)m_pTiles[3])
            ->FUN_00a012d0(0xfa2, (float)(((TileAccess*)m_pTiles[3])->FUN_00a011b0(0xfa2) + 25.0), true);
    ((TileAccess*)pMenu)->FUN_00700320(0x1004, FUN_00706e70() > 1.333299994468689 ? 1 : 0);
    if (inGame)
    {
        ((TileAccess*)m_pTiles[3])->FUN_00700320(0xfa3, 0);
        ((TileAccess*)pMenu)->FUN_00700320(0xfa9, 64);
        ((MenuOpsLocal*)this)->FadeTile(0, 1, 0x80000000, -1.0f);
        ((OptionListAccess*)&m_kFirstOptionListBox)->FUN_007d74f0(1);
        ApplyUserOptions();
        if (((TileAccess*)m_pTiles[13])->FUN_0056c7f0())
            ((TileAccess*)m_pTiles[13])->FUN_0056c7f0()->FUN_00440490(1.333299994468689f);
        else
            FUN_005b5e40(18, "Pause Menu: Background tile's model was NULL");
        for (int j = 0; j < 10; ++j)
        {
            int menuID = ((InterfaceAccess*)FUN_004b7210())->FUN_00714f70(j);
            if (FUN_0070ede0() == menuID)
                break;
            else if (FUN_007cc5f0(menuID))
            {
                TileAccess* menuTile = FUN_00a09030(menuID);
                if (menuTile && menuTile->FUN_00a03c90() &&
                    ((MenuAccess*)menuTile->FUN_00a03c90())->FUN_0059bb30() == 1)
                {
                    menuTile->FUN_00700320(0xfa3, 0);
                    g_011dabd8.FUN_004ed8c0(&menuTile);
                }
            }
        }
        if (FUN_007079b0())
            ((OSAccess*)g_osGlobals)->FUN_00871dc0();
    }
    else
    {
        DAT_011f2250.FUN_009c6c30(0, false);
        ((TileAccess*)m_pTiles[3])->FUN_00700320(0xfa3, 1);
        if (FUN_00702450(0x3f5))
            ((TileAccess*)m_pTiles[3])->FUN_00a012d0(0xfa9, 0.0f, true);
        else
            ((TileAccess*)m_pTiles[3])->FUN_00a012d0(0xfa9, 255.0f, true);
        ((MenuOpsLocal*)this)->FUN_0075f6f0(32, true);
    }
    if (IsFlagSet(FLAG_FORCE_RELOAD))
        FUN_007d0680();
    if (FUN_0070edf0())
        FUN_00703fe0(false);
    else
        FUN_007aaf20(true);
    if (FUN_007050d0())
        SetDialogMenuActive(true);
    if (DAT_011c3f3c && DAT_011c3f3c->GetValue() != 0.0)
    {
        ((MenuOpsLocal*)DAT_011daac0)->FUN_0075f6f0(0x10000, true);
        ((MenuOpsLocal*)DAT_011daac0)->FUN_0075f6f0(0x40000000, true);
        char musicPath[64];
        memset(musicPath, 0, 64);
        sprintf_s(musicPath, 64, "Data\\Music\\Special\\EndCredits.mp3");
        PlayAudioMedia(8, musicPath, 2000, true, true, 0.0f, 0);
        FUN_008304c0();
    }
    if (!DAT_011daac0->IsFlagSet(FLAG_INGAME))
        ((TileAccess*)m_pTiles[0])->FUN_00700320(TraitNameToIDAdd("_xbox_extra", -1), 25);
    FUN_00a1dc20(0);
    FUN_00af2c90()->FUN_00af2d70(FUN_007d6990);
    if (g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->SetFlag80(false);
}
}  // namespace fnv_007cbaf0

struct _WIN32_FIND_DATAA;
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*, _WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void*, _WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindClose(void*);

struct SaveEnumerationTime
{
    unsigned long low;
    unsigned long high;
};

struct SaveEnumerationData
{
    unsigned long attributes;
    SaveEnumerationTime creationTime;
    SaveEnumerationTime lastAccessTime;
    SaveEnumerationTime lastWriteTime;
    unsigned long fileSizeHigh;
    unsigned long fileSizeLow;
    unsigned long reserved0;
    unsigned long reserved1;
    char fileName[260];
    char alternateFileName[14];
};

class FileEntry
{

  public:
    unsigned int FUN_007d6950();

    bool FUN_00846ad0();

    bool IsLegacyAutosaveFileName();

    bool FUN_00846b10();
};

int __cdecl CompareU64Values(FileEntry*, FileEntry*);

int __cdecl FUN_00406d50(char*, unsigned int, const char*);

class FileEnumerator
{

  public:
    BSSimpleList<FileEntry*>* entries;

    unsigned int unk04;

    unsigned int currentIndex;

    void FUN_00851540();

    void CreateScriptMessageDirectory(char*);

    void AddFileToList(const char*, int, bool);

    void FUN_00851330();
};

// Scans matching files, adds entries with nonzero low file size, sorts them, then initializes currentIndex from the first entry and may increment it.
// @fnv 0x00851330
void FileEnumerator::FUN_00851330()

{

    if (entries)
    {

        FUN_00851540();
    }

    entries = new BSSimpleList<FileEntry*>;

    currentIndex = 1;

    SaveEnumerationData findData;

    char szPath[260];

    CreateScriptMessageDirectory(szPath);

    FUN_00406d50(szPath, 260, "*");

    FUN_00406d50(szPath, 260, ".fos");

    void* hFind = FindFirstFileA(szPath, reinterpret_cast<_WIN32_FIND_DATAA*>(&findData));

    if (hFind == reinterpret_cast<void*>(-1))
    {

        return;
    }

    do
    {

        if (findData.fileSizeLow == 0)
        {

            continue;
        }

        AddFileToList(findData.fileName, -1, false);

    } while (FindNextFileA(hFind, reinterpret_cast<_WIN32_FIND_DATAA*>(&findData)));

    FindClose(hFind);

    entries->Sort(CompareU64Values);

    FileEntry* first = entries->GetItem();

    if (first && currentIndex <= 1)
    {

        currentIndex = first->FUN_007d6950();

        if (!first->FUN_00846ad0() &&

            !first->IsLegacyAutosaveFileName() &&

            !first->FUN_00846b10())
        {

            ++currentIndex;
        }
    }
}

struct UserActionTileOps
{
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
};
struct UserActionSettingOps
{
    const char* FUN_00403df0();
};
extern UserActionSettingOps g_011d4b1c;
extern StartMenu* DAT_011daac0;
bool __cdecl FUN_004b71d0();

struct UserActionMenu : StartMenu
{
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int inputDevice;
};

// When action mapping is set, updates tile 16; if FUN_004b71d0() and inputDevice is 3, clears tile 5's 0xfaf value.
// @fnv 0x007d0cb0
void FUN_007d0cb0()
{
    if (DAT_011daac0 && DAT_011daac0->IsFlagSet(StartMenu::FLAG_ACTION_MAPPING))
    {
        ((UserActionTileOps*)DAT_011daac0->m_pTiles[16])->FUN_00a01350(0xfc4, g_011d4b1c.FUN_00403df0(), true);
        ((UserActionTileOps*)DAT_011daac0->m_pTiles[16])->FUN_00700320(0xfa3, 1);
        if (FUN_004b71d0() && ((UserActionMenu*)DAT_011daac0)->inputDevice == 3)
        {
            ((UserActionTileOps*)DAT_011daac0->m_pTiles[5])->FUN_00700320(0xfaf, 0);
        }
    }
}

struct PrepSaveMenu : public StartMenu
{
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int uiSaveLoadTrait;
    void FUN_007d3b60();
};

class BGSSaveLoadFileEntry;
struct SaveLoadListBox
{
    bool CallOnMemberAtOffset4();
    Tile* FUN_007d7da0(BGSSaveLoadFileEntry*, int, int, const char*);
    void ApplyFilter(bool);
    void FUN_007d8810(bool);
};
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TileHelper
{
    void Set(int, const char*, bool);
};
struct PrepSaveSettingOps
{
    const char* FUN_00403df0();
};

struct FUN_007d3c70_shell
{
    void UpdateSaveList();
};
struct GlobalObject_0040c150;
extern GlobalObject_0040c150 g_011d29e8;
extern GlobalObject_0040c150 g_011d39c0;

// Updates save/load tiles and the list box; one branch sets labels and flags, while the other calls two methods.
// @fnv 0x007d3b60
void PrepSaveMenu::FUN_007d3b60()
{
    Tile* pNewTile;
    if (((SaveLoadListBox*)&m_kOptionHelper)->CallOnMemberAtOffset4())
    {
        pNewTile = ((SaveLoadListBox*)&m_kOptionHelper)->FUN_007d7da0(0, 0, 0, "lb_newsave_template");
        ((TileHelper*)pNewTile)->Set(4036, ((PrepSaveSettingOps*)&g_011d39c0)->FUN_00403df0(), true);
        ((Tile_Set_Helper*)pNewTile)->Set(uiSaveLoadTrait, 0);
        ((SaveLoadListBox*)&m_kOptionHelper)->FUN_007d8810(true);
        ((MenuSI*)this)->FadeTile(6, 1, 0x80000000, -1.0f);
        ((MenuSI*)this)->FadeTile(5, 1, 0x80000000, -1.0f);
        ((TileHelper*)m_pTiles[4])->Set(4036, ((PrepSaveSettingOps*)&g_011d29e8)->FUN_00403df0(), true);
        ((Tile_Set_Helper*)m_pTiles[5])->Set(4015, 0);
        ((StartMenu_Wrap*)this)->FUN_0075f6f0(FLAG_LOADING_SAVEGAMES, true);
    }
    else
    {
        ((SaveLoadListBox*)&m_kOptionHelper)->ApplyFilter(false);
        ((FUN_007d3c70_shell*)this)->UpdateSaveList();
    }
}

struct ListBoxItem_4bc0;
struct Tile_4bc0;

struct ListBox4bc0
{
    Tile_4bc0* AddItem(int aiValue, const char* apcText, int(__cdecl* apfnSort)(ListBoxItem_4bc0*, ListBoxItem_4bc0*),
                       const char* apcTileName);
    void FUN_007d7bd0(bool abVal);
};

struct SM4bc0
{
    char pad[0x144];
    ListBox4bc0 m_kOptionIndexList;
    void FadeTile(int aiIndex, int aiValue, unsigned int auiTrait, float afTime);
    void FUN_007d4bc0();
};

int __fastcall GetRaceCount(ListBox4bc0* apList);

// Adds an item using the menu title when the list check is false, then calls the list and option methods with fixed arguments.
// @fnv 0x007d4bc0
void SM4bc0::FUN_007d4bc0()
{
    if (!GetRaceCount(&m_kOptionIndexList))
        m_kOptionIndexList.AddItem(-1, g_011d3ad4.GetMenuTitle(), 0, 0);
    m_kOptionIndexList.FUN_007d7bd0(true);
    FadeTile(14, 1, 0x80000000, -1.0f);
    FadeTile(5, 1, 0x80000000, -1.0f);
}

namespace fnv_007d4c50 {
void __cdecl FUN_00704000();
char* __cdecl FUN_00ecacb2(char* dest, const char* src, unsigned int count);
struct DLCEntry
{
    const char* FUN_00b008d0();
};
struct StartMenuDLC : StartMenu
{
    void FUN_007d4bc0();
};
extern StartMenuDLC* DAT_011daac0;
// For the (-1, -1) case, calls two functions; otherwise copies the entry name into a buffer and adds it to the option list.
// @fnv 0x007d4c50
void __cdecl FUN_007d4c50(int index, int count, int unused, DLCEntry* entry)
{
    if (index == -1 && count == -1)
    {
        FUN_00704000();
        DAT_011daac0->FUN_007d4bc0();
    }
    else
    {
        const char* name = entry->FUN_00b008d0();
        char buffer[128];
        FUN_00ecacb2(buffer, name, 128);
        char* text = buffer;
        DAT_011daac0->m_kOptionIndexList.AddItem(0, text, 0, 0);
    }
}
}  // namespace fnv_007d4c50

// Stand-in for the two Tile value setters this function calls (Tile is only forward-declared here).
struct StartMenuOptionTile
{
    void Set(int aeValue, int aiNew);                            // 0x00700320
    void Set(int aeValue, const char* apNew, bool abPropagate);  // 0x00a01350
};
struct StartMenuOptionUpdater : StartMenu
{
    void FUN_007d4ce0(StartMenu::UserOption* apOption, Tile* apTile);
};

// Refreshes a user option's tile: its value text and which arrows are shown.
// Updates the tile’s traits from the option value and type, looking up its tile when none is supplied.
// @fnv 0x007d4ce0
void StartMenuOptionUpdater::FUN_007d4ce0(StartMenu::UserOption* apOption, Tile* apTile)
{
    if (apOption && !apTile)
        apTile = m_kDownloadOptions.GetTileForData(apOption);
    if (!apOption || !apTile)
        return;
    if (apOption->eType == 2)
    {
        ((StartMenuOptionTile*)apTile)->Set(0x1004, apOption->iVal);
    }
    else if (apOption->m_ppOptionValues && apOption->iVal >= 0 && apOption->iVal <= apOption->m_uiValueCount - 1)
    {
        ((StartMenuOptionTile*)apTile)->Set(0x1004, apOption->m_ppOptionValues[apOption->iVal], true);
    }
    if (apOption->eType == 0)
        ((StartMenuOptionTile*)apTile)->Set(0x1006, 1);
    else if (apOption->iVal == 0)
        ((StartMenuOptionTile*)apTile)->Set(0x1006, 2);
    else if (apOption->iVal == apOption->m_uiValueCount - 1)
        ((StartMenuOptionTile*)apTile)->Set(0x1006, 0);
    else
        ((StartMenuOptionTile*)apTile)->Set(0x1006, 1);
}

namespace fnv_007d5f80 {
class Tile
{
  public:
    void Set(int, int);
};
class TESObjectREFR;
struct LBTraverseV
{
    void Traverse(void(__cdecl*)(Tile*, TESObjectREFR*), int, int);
};
struct VObj
{
    void FUN_007d74f0(int);
};
void __cdecl FUN_007ce970(Tile*, TESObjectREFR*);
struct StartMenu_Wrap : StartMenu
{
    void FUN_0075f6f0(StartMenu::Flag, bool);
    void FadeTile(int, int, unsigned int, float);
    void FUN_007d5f80();
};

// Sets traits on two tiles and calls methods on download options; when FLAG_ACTION_MAPPING is set, it traverses options and clears the flag.
// @fnv 0x007d5f80
void StartMenu_Wrap::FUN_007d5f80()
{
    m_pTiles[10]->Set(0xfa3, 0);
    ((VObj*)&m_kDownloadOptions)->FUN_007d74f0(0);
    FadeTile(2, 0, 0x80000000, -1.0f);
    if (IsFlagSet(FLAG_ACTION_MAPPING))
    {
        ((LBTraverseV*)&m_kDownloadOptions)->Traverse(FUN_007ce970, 0, 0x7fffffff);
        FUN_0075f6f0(FLAG_ACTION_MAPPING, false);
        m_pTiles[15]->Set(0x1004, 0);
        m_pTiles[16]->Set(0xfa3, 0);
    }
}
}  // namespace fnv_007d5f80

struct EnterTileOps
{
    ::Tile* FUN_0045cd60();
    float GetAccumulatedFloat();
    void FUN_00700320(int, int);
};
struct EnterListOps
{
    bool ContainsKey(::Tile*);
    ::StartMenu::UserOption* FUN_007a1910();
};
struct EnterInterfaceOps
{
    int FUN_0073b020();
};

struct EnterMenuView : public ::StartMenu
{
    int unk1b0;
    ::StartMenu::UserOption* pHoveredOption;
    void FUN_007cf7e0(int aiID, ::Tile* apTile);
};

// May highlight a tile in the download options list, invoke a function, and set a trait on tile 17 based on option comparisons.
// @fnv 0x007cf7e0
void EnterMenuView::FUN_007cf7e0(int aiID, ::Tile* apTile)
{
    if (apTile && ((EnterTileOps*)apTile)->FUN_0045cd60())
    {
        if (((EnterListOps*)&m_kDownloadOptions)->ContainsKey(((EnterTileOps*)apTile)->FUN_0045cd60()))
            m_kDownloadOptions.Highlight(((EnterTileOps*)apTile)->FUN_0045cd60());
    }
    if (((EnterListOps*)&m_kOptionHelper)->ContainsKey(apTile))
    {
        if (::FUN_004b71d0() || (double)((EnterInterfaceOps*)::FUN_004b7210())->FUN_0073b020() >=
                                    ((EnterTileOps*)m_pTiles[6])->GetAccumulatedFloat())
            ::UpdateTargetInfo(this);
    }
    if (((::ListBox< ::BGSSaveLoadFileEntry*>*)&m_kDownloadOptions)->FUN_007d7580())
    {
        if (((EnterListOps*)&m_kDownloadOptions)->FUN_007a1910() == pHoveredOption)
            ((EnterTileOps*)m_pTiles[17])->FUN_00700320(0xfa3, 1);
    }
}

unsigned int __cdecl gm_GetTickCount(void);
extern unsigned int DAT_011daab4;
void __cdecl HandleBackAction(void);
struct StartMenuGamepadRelease : ::StartMenu
{
    struct TileMethods
    {
        bool IsTraitNonZero(int trait);
    };
    struct InterfaceMethods
    {
        static void __cdecl FUN_00717de0(int button);
    };
    void FUN_0075f6f0(Flag aFlag, bool abSet);
    bool FUN_007cf5e0(int aiButton, float afValue);
};
// For button 10, clears the action-mapping flag or, after a trait check and 500 ms cooldown, calls two functions.
// @fnv 0x007cf5e0
bool StartMenuGamepadRelease::FUN_007cf5e0(int aiButton, float afValue)
{
    if (aiButton == 10)
    {
        if (IsFlagSet(FLAG_USER_IS_ACTION_MAPPING))
        {
            FUN_0075f6f0(FLAG_USER_IS_ACTION_MAPPING, false);
            return true;
        }
        if (((TileMethods*)m_pTiles[5])->IsTraitNonZero(0xfaf) && gm_GetTickCount() - DAT_011daab4 > 500)
        {
            ((InterfaceMethods*)::FUN_004b7210())->FUN_00717de0(10);
            HandleBackAction();
            DAT_011daab4 = gm_GetTickCount();
            return true;
        }
    }
    return false;
}
