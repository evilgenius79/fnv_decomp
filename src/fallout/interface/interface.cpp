// fallout/interface/interface.cpp: Interface, ConsoleManager, FileFinder, TESCreature and more (216 functions)

#include "interface_rebase_packet.h"

class TESWorldSpace;
class Menu;
class TESForm;
class TESObjectREFR;
class NiControllerSequence;

class BSSystemUtility
{
  public:
    static int s_iUpdateEnabled;
};

class Interface
{
  public:
    static const char* GetInterfaceName();
    static float GetFirstInterfaceFloat();
    static float UpdateInterfaceState();
    static float GetThirdInterfaceFloat();
    static float GetFourthInterfaceFloat();
    static bool IsInterfaceOpen();
    static float GetInterfaceFloat();
    static Tile* GetPrimaryInterfaceTile();
    static Tile* GetSecondaryInterfaceTile();
    static NiNode* GetInterfaceNode();
    static bool IsAnyMenuOpen();

    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
    static bool IsInterfaceActive();

    enum enumMenus
    {
        eNoMenu = 0,
        eMainFour = 1,
        eOtherRoot = 2,
        eConsoleMenu = 3,
        eFirstMenu = 1001,
        eMessageMenu = 1001,
        eInventoryMenu = 1002,
        eStatsMenu = 1003,
        eHUDMainMenu = 1004,
        eLoadingMenu = 1007,
        eContainerMenu = 1008,
        eDialogMenu = 1009,
        eSleepWaitMenu = 1012,
        eStartMenu = 1013,
        eLockPickMenu = 1014,
        eQuantityMenu = 1016,
        eAudioMenu = 1017,
        eVideoMenu = 1018,
        eGameplayMenu = 1020,
        eMapMenu = 1023,
        eBookMenu = 1026,
        eLevelUpMenu = 1027,
        eBirthSignMenu = 1029,
        eRepairMenu = 1035,
        eRaceSexMenu = 1036,
        eCreditsMenu = 1047,
        eCharGenMenu = 1048,
        eTextEditMenu = 1051,
        eBarterMenu = 1053,
        eSurgeryMenu = 1054,
        eHackingMenu = 1055,
        eVATSMenu = 1056,
        eComputersMenu = 1057,
        eRepairServicesMenu = 1058,
        eTutorialMenu = 1059,
        eSPECIALBookMenu = 1060,
        eItemModMenu = 1061,
        eLoveTesterMenu = 1074,
        eCompanionWheelMenu = 1075,
        eTraitSelectMenu = 1076,
        eRecipeMenu = 1077,
        eSlotMachineMenu = 1080,
        eBlackJackMenu = 1081,
        eRouletteMenu = 1082,
        eCaravanMenu = 1083,
        eTraitMenu = 1084,
        eLastMenu = 1084
    };
    static void Init(bool);
    static void RefreshInterfaceState();
    static void SetQuestTarget(TESForm*, bool);
    static bool IsPipBoyOpen();
    static bool GetStatsMenuVisible();
    static bool IsGamePaused();
    static bool ContainerIsRecipe();
    static bool ContainerIsBarter();
    static void SetLookAtReference(TESObjectREFR*);
    static bool PlayNifSounds(NiControllerSequence*);
    static Menu* GetMenuById(int);
    static void SetHUDVisible(bool);
    static void SetTileFormattedText(Tile*, int, const char*, ...);
};

#include "interface_rebase_closure.h"

const char kMeshesFolder[] = "Meshes";

// @fnv 0x00707860
const char* Interface::GetInterfaceName()
{
    return kMeshesFolder;
}

// @fnv 0x007043c0
bool Interface::IsWorldSpaceEnabled(TESWorldSpace* apSpace)
{
    (void)apSpace;
    return false;
}

// @fnv 0x00705ea0
bool Interface::IsInterfaceActive()
{
    return BSSystemUtility::s_iUpdateEnabled != 0;
}

// @fnv 0x00706df0
float Interface::GetFirstInterfaceFloat()
{
    return FUN_00715da0();
}

// @fnv 0x00706e00
float Interface::UpdateInterfaceState()
{
    return InterfaceManager::UpdateInterfaceState();
}

// @fnv 0x00706e10
float Interface::GetThirdInterfaceFloat()
{
    return FUN_00706e20();
}

// @fnv 0x00706e40
float Interface::GetFourthInterfaceFloat()
{
    return FUN_00706e50();
}

// @fnv 0x00707b40
bool Interface::IsInterfaceOpen()
{
    return FUN_00707b50();
}

// @fnv 0x00706e70
float Interface::GetInterfaceFloat()
{
    return FUN_004b7210()->screenAspectRatio;
}

// @fnv 0x00706cd0
Tile* Interface::GetPrimaryInterfaceTile()
{
    return FUN_004b7210()->FUN_00586150();
}

// @fnv 0x00706cf0
Tile* Interface::GetSecondaryInterfaceTile()
{
    return FUN_004b7210()->FUN_004fd400();
}

// @fnv 0x00706d30
NiNode* Interface::GetInterfaceNode()
{
    return reinterpret_cast<NiNode*>(reinterpret_cast<EffectSetting*>(FUN_004b7210())->GetCastSound());
}

// @fnv 0x00706d70
bool Interface::IsAnyMenuOpen()
{
    return FUN_004b7210()->FUN_00706d90();
}

// @fnv 0x00702440
unsigned int FUN_00702440()
{
    return 10;
}

// @fnv 0x00705100
bool FUN_00705100()
{
    return DAT_011d9514;
}

// @fnv 0x00706f20
unsigned int FUN_00706f20()
{
    return 1004;
}

// @fnv 0x00707b50
bool FUN_00707b50()
{
    return DAT_011c70eb;
}

// Fresh-claim additions verified against the supplied PC spans.

// Creates an AutoMemContext for the interface and calls InterfaceManager::Initialize with 1 and initializeRender.
// @fnv 0x00702250
void Interface::Init(bool initializeRender)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_INTERFACE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Interface.cpp", 176u);
    InterfaceManager::Initialize(1u, initializeRender);
}

// Creates an AutoMemContext for the interface and calls InterfaceManager::Initialize with 2 and true.
// @fnv 0x007022c0
void Interface::RefreshInterfaceState()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_INTERFACE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Interface.cpp", 189u);
    InterfaceManager::Initialize(2u, true);
}

// @fnv 0x00705e00
void Interface::SetQuestTarget(TESForm* location, bool flag)
{
    MessageMenu::SetMessageMenuActive(true);
    LoadingMenu::Create(location, true, flag);
}

// @fnv 0x00704ad0
bool Interface::IsPipBoyOpen()
{
    return Menu::IsMenuVisible(eInventoryMenu);
}

// @fnv 0x00704df0
bool Interface::GetStatsMenuVisible()
{
    return Menu::IsMenuVisible(eStatsMenu);
}

// @fnv 0x00705e80
bool Interface::IsGamePaused()
{
    return Menu::IsMenuVisible(eLoadingMenu);
}

// @fnv 0x00705000
bool Interface::ContainerIsRecipe()
{
    return Tile::FindMenuById(eRecipeMenu) != 0;
}

// @fnv 0x00705020
bool Interface::ContainerIsBarter()
{
    return Tile::FindMenuById(eBarterMenu) != 0;
}

// If the player and its NiNode exist, forwards the target reference to HUDMainMenu with a false flag.
// @fnv 0x00703860
void Interface::SetLookAtReference(TESObjectREFR* target)
{
    if (g_thePlayer && g_thePlayer->GetNiNode())
        HUDMainMenu::SetCrosshairTarget(target, false);
}

// @fnv 0x0059f3a0
signed char TESCreature::GetCreatureType() const
{
    return Data.eType;
}

// @fnv 0x007037c0
void TESRecipe::SetRequiredSkill(ActorValue::Index skill)
{
    kData.eReqSkill = skill;
}

// @fnv 0x00705cf0
bool ActiveEffect::IsDone() const
{
    return bPickResultFound;
}

// @fnv 0x007058c0
LOD_MULT_TYPE BSFadeNode::GetLODMultType() const
{
    return eLODMultType;
}

// If initialized, culls the first three button objects and un-culls the object at index button - 1 when button is greater than zero.
// @fnv 0x007fa010
void FOPipboyManager::ActivateButton(const unsigned int button)
{
    if (!GetInitialized())
        return;

    if (m_pButtonGlowObjects[0])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[0])->SetAppCulled(true);
    if (m_pButtonGlowObjects[1])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[1])->SetAppCulled(true);
    if (m_pButtonGlowObjects[2])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[2])->SetAppCulled(true);

    if (button > 0 && m_pButtonGlowObjects[button - 1])
        static_cast<NiAVObject*>(m_pButtonGlowObjects[button - 1])->SetAppCulled(false);
}

// Returns p1stPersonAnimation when firstPerson is set, otherwise delegates to Actor::GetAnimation().
// @fnv 0x00950a60
Animation* PlayerCharacter::GetAnimation(bool firstPerson) const
{
    if (firstPerson)
        return p1stPersonAnimation;
    return Actor::GetAnimation();
}

// Creates a TabButtonTemplate tile per label from the varargs list, sets its string/name/indices, then positions each tab by accumulated width.
// @fnv 0x00707be0
void Interface::SetTileFormattedText(Tile* parent, int firstID, const char* firstLabel, ...)
{
    BSStringT<char> buttonLabel;
    int count = 0;
    int iTotalWidth = 0;
    va_list labels;
    va_start(labels, firstLabel);
    buttonLabel.Set(firstLabel, 0);

    for (count = 0; buttonLabel.GetLength() > 0; ++count)
    {
        Tile* pTab = parent->GetMenu()->CreateTileFromTemplate(parent, "TabButtonTemplate", 0);
        pTab->SetString(0xfc4, buttonLabel.GetString(), true);
        pTab->SetName(buttonLabel.GetString());
        pTab->SetInt(0xfac, count);
        pTab->SetInt(0xfaa, firstID + count);
        Tile::UpdateAll(false);
        iTotalWidth += static_cast<int>(pTab->GetFloat(0xfb1));
        buttonLabel = va_arg(labels, const char*);
    }
    va_end(labels);

    // Initial button position also supplies the uniform inter-button gap.
    int iPosition = static_cast<int>((parent->GetFloat(0xfb1) - iTotalWidth) / (count + 1));
    // Accumulated left spacing is the current button coordinate.
    int iSpacing = iPosition;
    parent->SetInt(Tile::GetTraitID("_LeftLineLength"), iPosition);
    parent->SetInt(Tile::GetTraitID("_ButtonCount"), count);

    va_start(labels, firstLabel);
    buttonLabel.Set(firstLabel, 0);
    while (buttonLabel.GetLength() > 0)
    {
        Tile* pTab = parent->GetNamedChild(buttonLabel.GetString());
        pTab->SetInt(Tile::GetTraitID("_x"), iSpacing);
        iSpacing = static_cast<int>(pTab->GetFloat(0xfb1)) + iPosition + iSpacing;
        buttonLabel = va_arg(labels, const char*);
    }
    va_end(labels);
}

// @fnv 0x00707e10
void Tile::SetName(const char* name)
{
    StringProvider = name;
}

// @fnv 0x00707970
bool Interface::PlayNifSounds(NiControllerSequence* sequence)
{
    return BSAnimGroupSequence::PlayAnimSounds(sequence, 0);
}

// @fnv 0x00707990
Menu* Interface::GetMenuById(int menuClass)
{
    return MenuSystem::Instance(true)->GetMenuById(menuClass);
}

// @fnv 0x00709c40
void Interface::SetHUDVisible(bool visible)
{
    HUDMainMenu::SetHUDVisible(visible);
}

struct FUN_00424940_shell : public InterfaceManager
{
    char FUN_00424940();
};

// @fnv 0x00424940
char FUN_00424940_shell::FUN_00424940()
{
    return *((char*)this + 0xc);
}

extern bool DAT_011c70ed;
extern bool DAT_011c70ee;

// Returns true only when both DAT_011c70ed and DAT_011c70ee are set.
// @fnv 0x004de080
bool __cdecl FUN_004de080()
{
    return DAT_011c70ed && DAT_011c70ee;
}

struct ListStandIn
{
    int* FUN_0057cbe0(int** pos);
};
// @fnv 0x0057cbe0
int* ListStandIn::FUN_0057cbe0(int** pos)
{
    int* element = reinterpret_cast<int*>(*pos) + 2;
    *pos = reinterpret_cast<int*>(**pos);
    return element;
}

struct FUN_00644640_shell : public InterfaceManager
{
    bool FUN_00644640();
};

// @fnv 0x00644640
bool FUN_00644640_shell::FUN_00644640()
{
    return *((bool*)((char*)this + 0x7c));
}

class Modifier
{
  public:
    char GetKey(void);
};

bool __fastcall FUN_00644640(void*);

// Returns true when FUN_004b7210 yields a Modifier whose GetKey is nonzero and FUN_00644640 accepts that same object; otherwise false.
// @fnv 0x00702360
bool FUN_00702360()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        return FUN_00644640(FUN_004b7210());
    return false;
}

struct FUN_007023a0_shell : public InterfaceManager
{
    bool FUN_007023a0();
};

// @fnv 0x007023a0
bool FUN_007023a0_shell::FUN_007023a0()
{
    return *(int*)((char*)this + 0xc) != 1;
}

namespace fnv_007023c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class InterfaceManager_GetEnterStackTop_Helper
{
  public:
    int GetTopEnterStackEntry();
};

// @fnv 0x007023c0
int FUN_007023c0()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<InterfaceManager_GetEnterStackTop_Helper*>(FUN_004b7210())->GetTopEnterStackEntry();
    return 0;
}
}  // namespace fnv_007023c0

namespace fnv_00702400 {
struct Modifier
{
    bool GetKey();
    int GetMenuStackEntry(int);
};
// @fnv 0x00702400
int FUN_00702400(int a)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<Modifier*>(FUN_004b7210())->GetMenuStackEntry(a);
    return 0;
}
}  // namespace fnv_00702400

namespace fnv_00702450 {
class Modifier
{
  public:
    char GetKey();
};

struct InterfaceManager_EnterStackTop : InterfaceManager
{
    int GetTopEnterStackEntry();
};

struct Interface_Ext : Interface
{
    static bool IsMenuActive(Interface::enumMenus, unsigned int);
};

// @fnv 0x00702450
bool __cdecl FUN_00702450(Interface::enumMenus aeMenuID)
{
    if (FUN_004b7210() && (unsigned char)((Modifier*)FUN_004b7210())->GetKey())
    {
        int topid = ((InterfaceManager_EnterStackTop*)FUN_004b7210())->GetTopEnterStackEntry();
        if (topid == Interface::eMainFour &&
            (aeMenuID == Interface::eStatsMenu || aeMenuID == Interface::eInventoryMenu ||
             aeMenuID == Interface::eRepairMenu || aeMenuID == Interface::eMapMenu ||
             aeMenuID == Interface::eItemModMenu))
        {
            return Interface_Ext::IsMenuActive(aeMenuID, 0);
        }
        else
        {
            return topid == aeMenuID;
        }
    }
    return false;
}
}  // namespace fnv_00702450

namespace fnv_00702640 {
class Modifier
{
  public:
    unsigned char GetKey();
};

struct InterfaceManager_GetEnterStack_shell : public InterfaceManager
{
    int GetMenuStackEntry(int);
};

// @fnv 0x00702640
int FUN_00702640()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return static_cast<InterfaceManager_GetEnterStack_shell*>(FUN_004b7210())->GetMenuStackEntry(0);
    return 0;
}
}  // namespace fnv_00702640

extern bool DAT_011f308f[];

// @fnv 0x007027b0
bool __cdecl FUN_007027b0(int aiMenuID)
{
    if (aiMenuID >= Interface::eFirstMenu && aiMenuID <= Interface::eLastMenu)
    {
        return DAT_011f308f[aiMenuID];
    }
    else
    {
        return false;
    }
}

namespace fnv_007027e0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

void __fastcall UpdateStartMenuState(InterfaceManager*);

// If FUN_004b7210 returns a Modifier with a nonzero key, calls UpdateStartMenuState with that manager.
// @fnv 0x007027e0
void FUN_007027e0()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        UpdateStartMenuState(FUN_004b7210());
}
}  // namespace fnv_007027e0

namespace fnv_00702810 {
class Modifier
{
  public:
    char GetKey();
};

void __fastcall UpdateInterface(InterfaceManager*);

// If FUN_004b7210() returns a non-null object whose GetKey() is nonzero, calls UpdateInterface with that object.
// @fnv 0x00702810
void FUN_00702810()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        UpdateInterface(FUN_004b7210());
}
}  // namespace fnv_00702810

namespace fnv_00702840 {
class Modifier
{
  public:
    unsigned char GetKey();
};

void __fastcall UpdateMenuSelection(InterfaceManager* pThis);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls UpdateMenuSelection with that object.
// @fnv 0x00702840
void FUN_00702840()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        UpdateMenuSelection(FUN_004b7210());
}
}  // namespace fnv_00702840

namespace fnv_00702870 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class BGSMoviePlayer
{
  public:
    bool FUN_00ec17c0();
};

extern BGSMoviePlayer* DAT_0126fac4;
void __fastcall FUN_00713f00(InterfaceManager*);

// @fnv 0x00702870
void FUN_00702870()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey() && !DAT_0126fac4->FUN_00ec17c0())
        FUN_00713f00(FUN_004b7210());
}
}  // namespace fnv_00702870

namespace fnv_007028b0 {
class Modifier
{
  public:
    bool GetKey();
};

class BGSMoviePlayer
{
  public:
    bool FUN_00ec17c0();
};

class TaskThreadManager
{
  public:
    static TaskThreadManager* __cdecl GetSingleton();
    void FUN_00ba30f0(int, int);
    void FUN_00ba3130(int, int);
};

struct IM_Stub
{
    void RenderMenu(int, int);
    void SetField148(int);
};

extern BGSMoviePlayer* DAT_0126fac4;

// @fnv 0x007028b0
void __cdecl RenderOrFallback(int aiArg1, int aiArg2)
{
    bool bRendered = false;
    if (FUN_004b7210() && ((Modifier*)FUN_004b7210())->GetKey() && !DAT_0126fac4->FUN_00ec17c0())
    {
        ((IM_Stub*)FUN_004b7210())->RenderMenu(aiArg1, aiArg2);
        bRendered = true;
    }
    if (!bRendered)
    {
        TaskThreadManager::GetSingleton()->FUN_00ba30f0(0, 0x17);
        TaskThreadManager::GetSingleton()->FUN_00ba3130(1, 0x17);
    }
    ((IM_Stub*)FUN_004b7210())->SetField148(0);
}
}  // namespace fnv_007028b0

struct FUN_00702940_cls
{
    char pad[0x148];
    char field_148;
    void SetField148(char val);
};

// @fnv 0x00702940
void FUN_00702940_cls::SetField148(char acValue)
{
    field_148 = acValue;
}

struct FUN_00703060_shell : public InterfaceManager
{
    void FUN_00703060(bool);
};

// @fnv 0x00703060
void FUN_00703060_shell::FUN_00703060(bool abVisible)
{
    reinterpret_cast<unsigned char*>(this)[0x7C] = abVisible;
}

namespace fnv_00703180 {
struct Modifier
{
    bool GetKey();
    TESObjectREFR* FUN_007031c0();
};
// Gets the InterfaceManager and, if it exists and its key check passes, returns the reference from the modifier; otherwise returns 0.
// @fnv 0x00703180
TESObjectREFR* FUN_00703180()
{
    InterfaceManager* pim = FUN_004b7210();
    if (pim && reinterpret_cast<Modifier*>(pim)->GetKey())
        return reinterpret_cast<Modifier*>(pim)->FUN_007031c0();
    return 0;
}
}  // namespace fnv_00703180

namespace fnv_00703d50 {
struct Modifier
{
    bool GetKey();
};
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
};
// @fnv 0x00703d50
bool FUN_00703d50()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey() && ConsoleManager::Instance(false))
        return ConsoleManager::Instance(true)->IsConsoleActive();
    return false;
}
}  // namespace fnv_00703d50

namespace fnv_00703da0 {
struct Modifier
{
    bool GetKey();
    int AddMenuStackEntry(int, bool);
};
struct ConsoleManager
{
    static ConsoleManager* Instance(bool);
    bool IsConsoleActive();
    void FUN_0071d580();
};
// @fnv 0x00703da0
void FUN_00703da0()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey() && ConsoleManager::Instance(false) &&
        ConsoleManager::Instance(true)->IsConsoleActive())
    {
        ConsoleManager::Instance(true)->FUN_0071d580();
        reinterpret_cast<Modifier*>(FUN_004b7210())->AddMenuStackEntry(3, false);
    }
}
}  // namespace fnv_00703da0

// Reads the char at offset 0xE4 of the object returned by FUN_004b7210, sets that byte to -1, and returns the original value.
// @fnv 0x00703fa0
char ConsumeByteAtE4()
{
    char cresult = *reinterpret_cast<char*>(reinterpret_cast<char*>(FUN_004b7210()) + 0xE4);
    *reinterpret_cast<char*>(reinterpret_cast<char*>(FUN_004b7210()) + 0xE4) = -1;
    return cresult;
}

namespace fnv_00704140 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl FUN_00796b90();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, returns FUN_00796b90(); otherwise returns 0.
// @fnv 0x00704140
int FUN_00704140()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return FUN_00796b90();
    return 0;
}
}  // namespace fnv_00704140

namespace fnv_00704490 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl FUN_00796b90();

// If FUN_004b7210() returns non-null and its GetKey() is nonzero, returns FUN_00796b90(); otherwise returns 0.
// @fnv 0x00704490
int FUN_00704490()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return FUN_00796b90();
    return 0;
}
}  // namespace fnv_00704490

namespace fnv_007046c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

int __cdecl FUN_00796b90();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, returns FUN_00796b90(); otherwise returns 0.
// @fnv 0x007046c0
int FUN_007046c0()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return FUN_00796b90();
    return 0;
}
}  // namespace fnv_007046c0

namespace fnv_007048c0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class InventoryMenu
{
  public:
    static Tile* Create();
};

// Returns InventoryMenu::Create() when FUN_004b7210() is non-null and its GetKey() is nonzero, otherwise returns 0.
// @fnv 0x007048c0
Tile* CreateInventoryMenuIfModifierKey()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return InventoryMenu::Create();
    return 0;
}
}  // namespace fnv_007048c0

namespace fnv_00704be0 {
class Modifier
{
  public:
    char GetKey(void);
};

int __cdecl FUN_007da2c0();

// If FUN_004b7210 returns a non-null Modifier whose GetKey is nonzero, returns FUN_007da2c0(); otherwise returns 0.
// @fnv 0x00704be0
int FUN_00704be0()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        return FUN_007da2c0();
    return 0;
}
}  // namespace fnv_00704be0

namespace fnv_00704f50 {
class Modifier
{
  public:
    char GetKey();
};

class ContainerMenu
{
  public:
    static void __cdecl Close();
};

// If FUN_004b7210 returns an object whose GetKey() is nonzero, calls ContainerMenu::Close().
// @fnv 0x00704f50
void FUN_00704f50()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        ContainerMenu::Close();
}
}  // namespace fnv_00704f50

namespace fnv_00705070 {
struct Modifier
{
    bool GetKey();
};
struct TimeGlobal
{
    void SetGlobalTimeMultiplier(float, bool);
};
extern TimeGlobal g_timeGlobal;
struct DialogMenu
{
    static void* Create(void*, void*, void*);
};
// @fnv 0x00705070
void* FUN_00705070(void* apArg1, void* apArg2, void* apArg3)
{
    void* r;
    g_timeGlobal.SetGlobalTimeMultiplier(1.0f, true);
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
    {
        r = DialogMenu::Create(apArg1, apArg2, apArg3);
        return r;
    }
    return 0;
}
}  // namespace fnv_00705070

namespace fnv_007050d0 {
class Modifier
{
  public:
    char GetKey(void);
};

// @fnv 0x007050d0
bool FUN_007050d0()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        return FUN_00705100();
    return false;
}
}  // namespace fnv_007050d0

namespace fnv_007053f0 {
class Modifier
{
  public:
    char GetKey(void);
};

class StartMenu
{
  public:
    static bool __cdecl Create(bool, bool);
};

// If FUN_004b7210() returns a non-null Modifier whose GetKey() is nonzero, calls StartMenu::Create(false, false).
// @fnv 0x007053f0
void FUN_007053f0()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        StartMenu::Create(false, false);
}
}  // namespace fnv_007053f0

namespace fnv_007058e0 {
class Modifier
{
  public:
    char GetKey(void);
};

void __fastcall FUN_00713c70(InterfaceManager*);

// If FUN_004b7210() returns a Modifier whose GetKey() is nonzero, calls FUN_00713c70 with the InterfaceManager from FUN_004b7210().
// @fnv 0x007058e0
void FUN_007058e0()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        FUN_00713c70(FUN_004b7210());
}
}  // namespace fnv_007058e0

namespace fnv_00705910 {
struct Modifier
{
    bool GetKey();
};
struct TESNPC
{
    int FUN_00602170();
};
// If FUN_004b7210() returns a Modifier whose GetKey() is true, returns the TESNPC result of FUN_00602170(); otherwise returns 0.
// @fnv 0x00705910
int FUN_00705910()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
    {
        return reinterpret_cast<TESNPC*>(FUN_004b7210())->FUN_00602170();
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00705910

namespace fnv_00705990 {
struct Modifier
{
    bool GetKey();
};
struct TESNPC
{
    int FUN_00602170();
};
// If FUN_004b7210() returns a Modifier whose GetKey() is true, returns its FUN_00602170() result; otherwise returns 0.
// @fnv 0x00705990
int FUN_00705990()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
    {
        return reinterpret_cast<TESNPC*>(FUN_004b7210())->FUN_00602170();
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00705990

namespace fnv_007059d0 {
class Modifier
{
  public:
    char GetKey(void);
};
void __fastcall ResetWidget(InterfaceManager*);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls ResetWidget with that InterfaceManager.
// @fnv 0x007059d0
void FUN_007059d0()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        ResetWidget(FUN_004b7210());
}
}  // namespace fnv_007059d0

namespace fnv_00705a00 {
class Modifier
{
  public:
    char GetKey();
};

bool __cdecl FUN_00709bc0();
bool __cdecl FUN_00709c00();

// @fnv 0x00705a00
bool __cdecl FUN_00705a00()
{
    if (FUN_004b7210() && (unsigned char)((Modifier*)FUN_004b7210())->GetKey())
    {
        return FUN_00709bc0() || FUN_00709c00();
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00705a00

namespace fnv_00705a90 {
class Modifier
{
  public:
    char GetKey();
};

// Returns the LOD mult type of the fade node from FUN_004b7210 when it exists and its key is nonzero, otherwise 0.
// @fnv 0x00705a90
int GetLODMultTypeIfKeySet()
{
    if (FUN_004b7210() && static_cast<unsigned char>(reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey()))
        return reinterpret_cast<BSFadeNode*>(FUN_004b7210())->GetLODMultType();
    else
        return 0;
}
}  // namespace fnv_00705a90

struct FUN_00705b10_Dummy
{
    char pad[0xc4];
    int val;
    void Set(int a);
};

// @fnv 0x00705b10
void FUN_00705b10_Dummy::Set(int aiValue)
{
    val = aiValue;
}

namespace fnv_00705b30 {
struct Modifier
{
    bool GetKey();
};
struct IMStandIn
{
    void FUN_00716010(int a);
};
// If FUN_004b7210() returns an object whose GetKey() is true, forwards a to its FUN_00716010 method.
// @fnv 0x00705b30
void __cdecl FUN_00705b30(int a)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<IMStandIn*>(FUN_004b7210())->FUN_00716010(a);
}
}  // namespace fnv_00705b30

// Returns the larger of the two integer arguments.
// @fnv 0x00705c40
int FUN_00705c40(int aiValue1, char aiValue2)
{
    return (aiValue1 > aiValue2) ? aiValue1 : aiValue2;
}

struct DummyVtable_00705e30
{
    virtual ~DummyVtable_00705e30();
};

// @fnv 0x00705e30
void FUN_00705e30()
{
    delete (DummyVtable_00705e30*)BSSystemUtility::s_iUpdateEnabled;
    MessageMenu::SetMessageMenuActive(false);
}

class MapMenu
{
  public:
    void FUN_007069f0(unsigned char);
};
extern MapMenu* DAT_011da368;

// @fnv 0x007069d0
void FUN_007069d0(unsigned char acPage)
{
    if (DAT_011da368)
        DAT_011da368->FUN_007069f0(acPage);
}

struct Dummy_007069f0
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3(int, int) = 0;
    void FUN_007069f0(int a1);
};

// Calls the virtual v3 with the argument offset by 0x20 and zero.
// @fnv 0x007069f0
void Dummy_007069f0::FUN_007069f0(int aiValue)
{
    this->v3(aiValue + 0x20, 0);
}

void __cdecl SetInventoryTab(unsigned char);

// @fnv 0x00706a20
void __cdecl FUN_00706a20(unsigned char acPage)
{
    SetInventoryTab(acPage);
}

int __cdecl MinInt(int, int);

class InventoryMenu
{
  public:
    char pad00[0x5c];
    Tile* pTile5C;
    char pad60[0x24];
    int iTab84;
    static InventoryMenu* ms_pInventoryMenu;
    static int ms_iCurrentTabTileID;
};

struct Tile_Set_Helper : public Tile
{
    void Set(int, int);
};

// @fnv 0x00706a40
void __cdecl SetInventoryTab(int aiTab)
{
    if (InventoryMenu::ms_pInventoryMenu)
    {
        aiTab = MinInt(aiTab, 4);
        ((Tile_Set_Helper*)InventoryMenu::ms_pInventoryMenu->pTile5C)->Set(InventoryMenu::ms_iCurrentTabTileID, aiTab);
        InventoryMenu::ms_pInventoryMenu->iTab84 = aiTab;
    }
}

namespace fnv_00706a90 {
class StatsMenu
{
  public:
    static void __cdecl UpdateStatusEffects();
};
class MapMenu
{
  public:
    static void __cdecl SetMapPositionToPlayer();
    static void __cdecl UpdateMapPosition();
};
class SurgeryMenu
{
  public:
    static void __cdecl UpdatePerkEntries();
};

void __cdecl FUN_007dd710();
void __cdecl UpdateStatsMenuLevelText();
void __cdecl ClearMapMenuNote();

// @fnv 0x00706a90
void __cdecl FUN_00706a90()
{
    FUN_007dd710();
    UpdateStatsMenuLevelText();
    StatsMenu::UpdateStatusEffects();
    MapMenu::SetMapPositionToPlayer();
    ClearMapMenuNote();
    MapMenu::UpdateMapPosition();
    SurgeryMenu::UpdatePerkEntries();
}
}  // namespace fnv_00706a90

struct BGSNote;
struct BGSQuestObjective;
struct TESChallenge;
struct TESQuest;
struct RegionObjectEntry;
struct TESWorldSpace;
struct PathingPath;
struct blob12
{
    char b[12];
};

class MapMenu;
extern MapMenu* DAT_011da368;

// @fnv 0x00706ac0
void ClearMapMenuNote()
{
    if (DAT_011da368 != 0)
    {
        *(BGSNote**)((char*)DAT_011da368 + 0x90) = 0;
    }
}

struct TutorialManagerLayout
{
    struct Entry
    {
        unsigned int b0 : 1;
        unsigned int b1 : 1;
        unsigned int pad : 6;
        unsigned int rest : 24;
    };
    Entry entries[0x29];
    unsigned int unkA4;
    unsigned int unkA8;
};

// @fnv 0x00706b90
void __fastcall ResetEntries(TutorialManagerLayout* pThis)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        pThis->entries[i].b0 = 0;
        pThis->entries[i].b1 = 0;
        pThis->entries[i].rest = 0;
    }
    pThis->unkA8 = 0;
    pThis->unkA4 = 0x29;
}

struct FUN_00706cb0_shell : public InterfaceManager
{
    void ResetFieldBC();
};

// @fnv 0x00706cb0
void FUN_00706cb0_shell::ResetFieldBC()
{
    *(int*)((char*)this + 0xbc) = 0;
}

class BSFaceGenAnimationData;
class BSFaceGenNiNode
{
  public:
    BSFaceGenAnimationData* GetAnimationData();
};

class NiAVObject_Attach : public NiAVObject
{
  public:
    void AttachProperty(NiObject*);
};

// @fnv 0x00706d50
void AttachFaceGenAnimationData(NiAVObject* apObject)
{
    reinterpret_cast<NiAVObject_Attach*>(apObject)->AttachProperty(
        reinterpret_cast<NiObject*>(reinterpret_cast<BSFaceGenNiNode*>(FUN_004b7210())->GetAnimationData()));
}

struct FUN_00706d90_shell : public InterfaceManager
{
    bool FUN_00706d90();
};

// @fnv 0x00706d90
bool FUN_00706d90_shell::FUN_00706d90()
{
    return *((bool*)((char*)this + 0xEC));
}

// @fnv 0x00706dd0
void __cdecl SetFlagAtOffsetDC(bool abValue)
{
    *((bool*)FUN_004b7210() + 0xdc) = abValue;
}

int __cdecl FUN_004dc200();

// @fnv 0x00706e20
float FUN_00706e20()
{
    return (float)FUN_004dc200();
}

int __cdecl FUN_004dc1f0();

// @fnv 0x00706e50
float __cdecl FUN_00706e50()
{
    return (float)FUN_004dc1f0();
}

NiRenderer* __cdecl FUN_0043c4b0();
float __cdecl FUN_00706e80();

struct DummyRTG_00706e90
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
    virtual unsigned int GetWidth(unsigned int);
    virtual unsigned int GetHeight(unsigned int);
};

struct DummyRenderer_00706e90
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
    virtual DummyRTG_00706e90* GetDefaultRenderTargetGroup();
};

// Returns FUN_00706e80() multiplied by the default render target group's height divided by its width.
// @fnv 0x00706e90
float __cdecl FUN_00706e90()
{
    DummyRenderer_00706e90* apRenderer = (DummyRenderer_00706e90*)FUN_0043c4b0();
    return FUN_00706e80() * ((double)apRenderer->GetDefaultRenderTargetGroup()->GetHeight(0) /
                             (double)apRenderer->GetDefaultRenderTargetGroup()->GetWidth(0));
}

void __cdecl FUN_007164c0(void*, float);

// @fnv 0x00706f50
void __cdecl FUN_00706f50(void* apPointer, float afLength)
{
    FUN_007164c0(apPointer, afLength);
}

void __fastcall UpdateNodeTimers(InterfaceManager*);

// @fnv 0x00706f70
void FUN_00706f70()
{
    UpdateNodeTimers(FUN_004b7210());
}

struct FUN_00714d90_struct
{
    void PushMenuStackEntry(int);
};

// @fnv 0x00706fb0
void FUN_00706fb0(int aiID)
{
    ((FUN_00714d90_struct*)FUN_004b7210())->PushMenuStackEntry(aiID);
}

struct InterfaceManager_PopFromEnterStack_helper
{
    int AddMenuStackEntry(int, bool);
};

// @fnv 0x00706fd0
int __cdecl FUN_00706fd0(int aiID, bool abForceRemoval)
{
    return reinterpret_cast<InterfaceManager_PopFromEnterStack_helper*>(FUN_004b7210())
        ->AddMenuStackEntry(aiID, abForceRemoval);
}

struct IMStandIn
{
    void FUN_00715860(int a, int b, int c);
};
// @fnv 0x00706ff0
void __cdecl FUN_00706ff0(int a)
{
    reinterpret_cast<IMStandIn*>(FUN_004b7210())->FUN_00715860(a, 0xfc3, 1);
}

// @fnv 0x00707040
Tile* FUN_00707040()
{
    return *(Tile**)((char*)FUN_004b7210() + 0xcc);
}

// @fnv 0x00707050
void FUN_00707050(Tile* apTile)
{
    *(Tile**)((char*)FUN_004b7210() + 0xcc) = apTile;
}

// @fnv 0x00707070
int __cdecl GetFieldD0()
{
    return *(int*)((char*)FUN_004b7210() + 0xd0);
}

// @fnv 0x00707080
void FUN_00707080(Menu* apMenu)
{
    *(Menu**)((char*)FUN_004b7210() + 0xd0) = apMenu;
}

class TESResponse
{
  public:
    TESResponse* GetNext();
};

// @fnv 0x007070a0
Tile* GetNextTile()
{
    return (Tile*)((TESResponse*)FUN_004b7210())->GetNext();
}

class ModelLoader
{
  public:
    void FUN_0045a5e0(const char*);
};
extern ModelLoader* g_modelLoader;

// @fnv 0x00707640
void FUN_00707640(const char* apPath)
{
    if (g_modelLoader)
        g_modelLoader->FUN_0045a5e0(apPath);
}

struct S_004431f0
{
    void* FUN_004431f0(unsigned int);
};
extern S_004431f0* DAT_011d890c;

// Calls FUN_004431f0(1) on DAT_011d890c if it is non-null, then sets DAT_011d890c to null.
// @fnv 0x00707820
void FUN_00707820()
{
    S_004431f0* p0;
    S_004431f0* p1 = DAT_011d890c;
    p0 = p1;
    p0 ? p0->FUN_004431f0(1) : 0;
    DAT_011d890c = 0;
}

namespace fnv_00707930 {
struct Modifier
{
    void SetNeed(bool);
};
// @fnv 0x00707930
void FUN_00707930(bool a)
{
    reinterpret_cast<Modifier*>(FUN_004b7210())->SetNeed(a);
}
}  // namespace fnv_00707930

struct FUN_00707950_shell : public InterfaceManager
{
    void SetNeed(bool);
};

// @fnv 0x00707950
void FUN_00707950_shell::SetNeed(bool abNeed)
{
    *((bool*)((char*)this + 0xb0)) = abNeed;
}

bool __cdecl FUN_00705a00();
FORenderedMenu* __cdecl FUN_00705990();
bool __fastcall FUN_007079f0(InterfaceManager*);

// Returns false if FUN_00705a00() is true and the rendered menu is not initialized; otherwise returns FUN_007079f0(FUN_004b7210()).
// @fnv 0x007079b0
bool FUN_007079b0()
{
    if (FUN_00705a00() && !FUN_00705990()->GetInitialized())
        return false;
    return FUN_007079f0(FUN_004b7210());
}

struct FUN_007079f0_shell : public InterfaceManager
{
    bool FUN_007079f0();
};

bool __cdecl FUN_007178a0();

// Returns true if the byte at offset 0x168 of this InterfaceManager is set, otherwise returns the result of FUN_007178a0.
// @fnv 0x007079f0
bool FUN_007079f0_shell::FUN_007079f0()
{
    return *((bool*)this + 0x168) || FUN_007178a0();
}

class FORenderedMenu;
FORenderedMenu* __fastcall FUN_00707af0(InterfaceManager*);

// @fnv 0x00707ad0
FORenderedMenu* FUN_00707ad0()
{
    return FUN_00707af0(FUN_004b7210());
}

int __cdecl FUN_004dc200();

// @fnv 0x00707b60
float FUN_00707b60()
{
    static float s_val = Interface::GetFirstInterfaceFloat() / FUN_004dc200();
    return s_val;
}

extern int g_011d8950;
extern int DAT_011d8954;
extern int DAT_011d8958;
extern int DAT_011d895c;
extern int DAT_011d8964;
extern int g_011d8998;
extern int DAT_011d899c;
extern int DAT_011d89a0;
extern int DAT_011d89a4;
extern int DAT_011d89ac;

bool __cdecl IsConditionMet();
void __cdecl FUN_007094f0();
void __cdecl FUN_00709a90();

// @fnv 0x00709470
void __cdecl FUN_00709470(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    if (param_1 != 7)
    {
        g_011d8950 = param_1;
        DAT_011d8954 = param_2;
        DAT_011d8958 = param_3;
        DAT_011d895c = param_4;
        DAT_011d8964 = param_5;
    }
    else
    {
        g_011d8998 = param_1;
        DAT_011d899c = param_2;
        DAT_011d89a0 = param_3;
        DAT_011d89a4 = param_4;
        DAT_011d89ac = param_5;
    }
    if (!IsConditionMet())
    {
        FUN_007094f0();
        FUN_00709a90();
    }
}

// @fnv 0x00709bc0
bool FUN_00709bc0()
{
    return *(int*)((char*)FUN_004b7210() + 0x4bc) == 2;
}

// @fnv 0x00709c00
bool __cdecl FUN_00709c00()
{
    return *(int*)((char*)FUN_004b7210() + 0x4bc) == 3;
}

class TESRace;
template <> class BSSimpleList<TESRace*>
{
  public:
    int GetSize();
};

// @fnv 0x00726c40
int __fastcall GetRaceCount(char* pThis)
{
    return ((BSSimpleList<TESRace*>*)(pThis + 4))->GetSize();
}

struct StrHelper
{
    operator const char*() const;
};
struct StrOwner
{
    int pad;
    StrHelper s;
    const char* FUN_007fa950();
};
// @fnv 0x007fa950
const char* StrOwner::FUN_007fa950()
{
    return s;
}

struct FUN_009373f0_shell : public InterfaceManager
{
    bool FUN_009373f0();
};

// @fnv 0x009373f0
bool FUN_009373f0_shell::FUN_009373f0()
{
    return *reinterpret_cast<bool*>(this);
}

namespace fnv_00703e80 {
struct InterfaceManager;
struct Modifier
{
    unsigned char GetKey();
};
InterfaceManager* FUN_004b7210();
bool QueueMessage(const char*, const char*, const char*, int, void*, int, int, const char*, char**, int, int, int,
                  float, float, float);
// Shows a warning message via QueueMessage when the interface manager's modifier key is held, returning the result; otherwise returns false.
// @fnv 0x00703e80
bool ShowMessageBox(const char* aText, const char* apcIconFilename, const char* apcTitle, void* afpResult,
                  int aiFirstButtonResult, int aiWarningContext, float afBackgroundTextureOpacityOverride,
                  float afMenuWidthOverride, const char* axFirst, ...)
{
    if (FUN_004b7210() && ((Modifier*)FUN_004b7210())->GetKey())
    {
        char* xlist = (char*)&axFirst + 4;
        bool bresult =
            QueueMessage(aText, apcIconFilename, apcTitle, 0, afpResult, aiFirstButtonResult, aiWarningContext, axFirst,
                         &xlist, 1, -1, -1, 0.0f, afBackgroundTextureOpacityOverride, afMenuWidthOverride);
        xlist = 0;
        return bresult;
    }
    return false;
}
}  // namespace fnv_00703e80

namespace fnv_007053b0 {
struct InterfaceManager;
struct Modifier
{
    unsigned char GetKey();
};
struct HUDHelper
{
    void FUN_00775920();
};
extern HUDMainMenu* g_pHudMainMenuInstance;
InterfaceManager* FUN_004b7210();
// @fnv 0x007053b0
void FUN_007053b0()
{
    if (FUN_004b7210() && ((Modifier*)FUN_004b7210())->GetKey() && g_pHudMainMenuInstance)
        ((HUDHelper*)g_pHudMainMenuInstance)->FUN_00775920();
}
}  // namespace fnv_007053b0

namespace fnv_00705b70 {
struct InterfaceManager;
struct Modifier
{
    unsigned char GetKey();
};
struct FUN_0070b790_shell
{
    void FUN_0070b790(char);
};
namespace fnv_0070b810 {
struct FUN_0070b810_shell
{
    void FUN_0070b810(char);
};
}
namespace fnv_0070b870 {
struct S0b870
{
    void FUN_0070b870(char);
};
}
struct FUN_0070b8d0_shell
{
    void FUN_0070b8d0(int);
};
InterfaceManager* FUN_004b7210();
int MinInt(int, int);
int FUN_00705c40(int, char);
// If the interface manager exists and a key is pressed, updates the stats, inventory and map tab states and selects the given menu, defaulting to 0x3eb.
// @fnv 0x00705b70
void FUN_00705b70(char aiStatsTab, char aiInventoryTab, char aiMapTab, int aiWhichMenu)
{
    if (FUN_004b7210() && ((Modifier*)FUN_004b7210())->GetKey())
    {
        ((FUN_0070b790_shell*)FUN_004b7210())->FUN_0070b790(MinInt(4, FUN_00705c40(0, aiStatsTab)));
        ((fnv_0070b810::FUN_0070b810_shell*)FUN_004b7210())->FUN_0070b810(MinInt(4, FUN_00705c40(0, aiInventoryTab)));
        ((fnv_0070b870::S0b870*)FUN_004b7210())->FUN_0070b870(MinInt(4, FUN_00705c40(0, aiMapTab)));
        if (aiWhichMenu != 0x3eb && aiWhichMenu != 0x3ea && aiWhichMenu != 0x3ff)
            aiWhichMenu = 0x3eb;
        ((FUN_0070b8d0_shell*)FUN_004b7210())->FUN_0070b8d0(aiWhichMenu);
    }
}
}  // namespace fnv_00705b70

struct InterfaceManager;
class PlayerCharacter;
struct MobileObject;
struct DialogH
{
    static bool IsInDialog();
};
struct MapMenuH
{
    static void StopMapMenuSounds();
};
struct StatsMenuH
{
    static void ClearPerks();
};
struct fnv_007aa480
{
    static void ClearAllElements();
};
struct FocusH
{
    void FocusOnActor(MobileObject*, float, bool);
};
struct Im7181
{
    void SetRenderedMenu(int);
};
extern PlayerCharacter* g_thePlayer;
extern unsigned char DAT_011d8a85;
InterfaceManager* FUN_004b7210();
MobileObject* GetDialogCastSound();
void FUN_007053b0();
void FUN_00705780();
void FUN_00706320(int);
void ClearMapMenuNote();
void __fastcall ResetEntries(void*);
void FUN_00706fd0(int, int);
void FUN_007f6920();
void FUN_0083e510();
void ResetHUDMainMenu();
MobileObject* GetDialogCastSound();
// @fnv 0x00706ae0
void ResetInterfaceState()
{
    DAT_011d8a85 = 1;
    FUN_007053b0();
    ResetHUDMainMenu();
    if (DialogH::IsInDialog())
    {
        ((FocusH*)g_thePlayer)->FocusOnActor(GetDialogCastSound(), 0.0f, true);
        FUN_0083e510();
    }
    FUN_00705780();
    FUN_007f6920();
    FUN_00706320(0);
    fnv_007aa480::ClearAllElements();
    StatsMenuH::ClearPerks();
    ClearMapMenuNote();
    MapMenuH::StopMapMenuSounds();
    FUN_00706fd0(1, 1);
    ((Im7181*)FUN_004b7210())->SetRenderedMenu(0);
    *(int*)((char*)FUN_004b7210() + 0x4bc) = 0;
    ResetEntries((char*)FUN_004b7210() + 0x4d4);
}

struct InterfaceManager;
struct NavMesh;
struct S3de0
{
    void FUN_00713de0(NavMesh*);
};
struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};
struct FUN_00706cb0_shell2
{
    void ResetFieldBC();
};
InterfaceManager* FUN_004b7210();
// @fnv 0x00706c20
void ClearInterfaceRefs(unsigned int a)
{
    InterfaceManager* im = FUN_004b7210();
    if (*(unsigned int*)((char*)im + 0xcc) == a)
    {
        *(unsigned int*)((char*)im + 0xcc) = 0;
        *(unsigned int*)((char*)im + 0xd0) = 0;
    }
    if (*(unsigned int*)((char*)im + 0xd4) == a)
    {
        *(unsigned int*)((char*)im + 0xd4) = 0;
        *(unsigned int*)((char*)im + 0xd8) = 0;
    }
    if (((TESAmmoInitCalls*)im)->GetFieldBC() == a)
        ((FUN_00706cb0_shell2*)im)->ResetFieldBC();
    ((S3de0*)im)->FUN_00713de0((NavMesh*)a);
}

struct QuantityData
{
    Tile* GetItem();
};

// @fnv 0x00707a30
bool FUN_00707a30(QuantityData* apComponent)
{
    Tile* pTile = apComponent ? apComponent->GetItem() : 0;
    if (!pTile)
        return false;
    int iFilter = (int)pTile->GetFloat(0xfaa);
    int m_uiSoundID = (int)pTile->GetFloat(0xfa4);
    return iFilter == 0x70 || m_uiSoundID == 0x421 || m_uiSoundID == 0x41f || m_uiSoundID == 0x40c;
}

namespace fnv_00704af0 {
struct Modifier
{
    unsigned char GetKey();
};
bool __cdecl FUN_00702680(int, unsigned int);
struct InventoryMenuHelper
{
    static void UpdateItemList();
};
struct MenuHelper
{
    void UpdateOption(int);
};
void __cdecl FUN_00730690(int);
void __cdecl FUN_00728a30(int);
void __cdecl FUN_00704bc0();

// @fnv 0x00704af0
void FUN_00704af0()
{
    if (FUN_004b7210())
    {
        if (reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        {
            if (Interface::IsPipBoyOpen())
            {
                InventoryMenuHelper::UpdateItemList();
            }
            else if (Interface::GetStatsMenuVisible())
            {
                reinterpret_cast<MenuHelper*>(reinterpret_cast<Tile*>(Tile::FindMenuById(0x3eb))->GetMenu())
                    ->UpdateOption(4);
            }
            else if (FUN_00702680(0x41d, 0))
            {
                FUN_00730690(1);
            }
            else if (FUN_00702680(0x435, 0))
            {
                FUN_00728a30(1);
            }
            else if (FUN_00702680(0x3f0, 0))
            {
                FUN_00704bc0();
            }
        }
    }
}
}  // namespace fnv_00704af0

namespace fnv_00705420 {
struct Modifier
{
    unsigned char GetKey();
};
struct BSS
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    ~BSS();
    operator const char*() const;
};
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct AttachMsg
{
    int a;
    char name[260];
    char flag;
};
void __cdecl ShowRegionData(AttachMsg*);

// @fnv 0x00705420
void __cdecl FUN_00705420(int a, BSS name, bool flag)
{
    if (FUN_004b7210())
    {
        if (reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        {
            AttachMsg msg;
            msg.flag = flag;
            msg.a = a;
            if ((const char*)name)
                TaskQueueInterface::CopyStringToBuffer(msg.name, 260, (const char*)name);
            else
                msg.name[0] = 0;
            ShowRegionData(&msg);
        }
    }
}
}  // namespace fnv_00705420

namespace fnv_00702330 {
class Modifier
{
  public:
    unsigned char GetKey(void);
};

extern "C" void __cdecl FUN_0070a0b0(void);

// Calls FUN_004b7210, and if it returns non-null and its GetKey result is nonzero, calls FUN_0070a0b0.
// @fnv 0x00702330
void FUN_00702330()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        FUN_0070a0b0();
}
}  // namespace fnv_00702330

class MenuFade : public Menu
{
  public:
    unsigned int GetCurrentFadeState();
};
Tile* __cdecl FindMenuById(int);
bool __cdecl FUN_00709c00();
class InterfaceManagerPC
{
  public:
    bool GetKey();
};

// @fnv 0x00702680
bool __cdecl FUN_00702680(Interface::enumMenus aeMenuID, unsigned int abFadeStatesThatCountAsVisible)
{
    Tile* ptile;

    if (FUN_004b7210() && ((InterfaceManagerPC*)FUN_004b7210())->GetKey())
    {
        if (aeMenuID == Interface::eMainFour)
            return FUN_00709c00() && (FUN_00702680(Interface::eStatsMenu, abFadeStatesThatCountAsVisible) ||
                                      FUN_00702680(Interface::eInventoryMenu, abFadeStatesThatCountAsVisible) ||
                                      FUN_00702680(Interface::eRepairMenu, abFadeStatesThatCountAsVisible) ||
                                      FUN_00702680(Interface::eItemModMenu, abFadeStatesThatCountAsVisible) ||
                                      FUN_00702680(Interface::eMapMenu, abFadeStatesThatCountAsVisible));
        if (abFadeStatesThatCountAsVisible)
        {
            ptile = FindMenuById(aeMenuID);
            if (ptile && ptile->GetMenu() &&
                !(((MenuFade*)ptile->GetMenu())->GetCurrentFadeState() & abFadeStatesThatCountAsVisible))
                return false;
        }
        return Menu::IsMenuVisible(aeMenuID);
    }
    return false;
}

namespace fnv_00702960 {
struct Modifier
{
    unsigned char GetKey();
};
struct BGSMoviePlayer
{
    bool FUN_00ec17c0();
};
extern BGSMoviePlayer* DAT_0126fac4;

// If FUN_004b7210() returns non-null and its GetKey() is nonzero, calls FUN_00ec17c0() on DAT_0126fac4.
// @fnv 0x00702960
void FUN_00702960()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        DAT_0126fac4->FUN_00ec17c0();
}
}  // namespace fnv_00702960

namespace fnv_00703000 {
struct Modifier
{
    unsigned char GetKey();
    void FUN_00703030();
};

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls FUN_00703030 on it.
// @fnv 0x00703000
void FUN_00703000()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<Modifier*>(FUN_004b7210())->FUN_00703030();
}
}  // namespace fnv_00703000

namespace fnv_007030c0 {
struct Modifier
{
    unsigned char GetKey();
    void SetTileValues(int, int);
};

// If FUN_004b7210() returns a Modifier whose GetKey() is nonzero, forwards a1 and a2 to its SetTileValues.
// @fnv 0x007030c0
void FUN_007030c0(int aiArg1, int aiArg2)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<Modifier*>(FUN_004b7210())->SetTileValues(aiArg1, aiArg2);
}
}  // namespace fnv_007030c0

namespace fnv_00703390 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class InterfaceManager;

struct FUN_009b4440_holder
{
    void* FUN_009b4440();
};

// If FUN_004b7210() returns a Modifier with a nonzero key, returns its FUN_009b4440() result; otherwise returns 0.
// @fnv 0x00703390
void* FUN_00703390()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<FUN_009b4440_holder*>(FUN_004b7210())->FUN_009b4440();
    return 0;
}
}  // namespace fnv_00703390

char __cdecl ConsumeByteAtE4();
extern char DAT_0119f349;

// @fnv 0x00704130
void __cdecl FUN_00704130()
{
    DAT_0119f349 = ConsumeByteAtE4();
}

namespace fnv_007043d0 {
struct Modifier
{
    unsigned char GetKey();
};

bool FUN_00704400();

// @fnv 0x007043d0
bool FUN_007043d0()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return FUN_00704400();
    return 0;
}
}  // namespace fnv_007043d0

namespace fnv_00704420 {
struct Modifier
{
    unsigned char GetKey();
};

bool FUN_00704450(bool);

// If FUN_004b7210 returns a non-null object whose GetKey is nonzero, forwards abSetTo to FUN_00704450.
// @fnv 0x00704420
void FUN_00704420(bool abSetTo)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        FUN_00704450(abSetTo);
}
}  // namespace fnv_00704420

class MapMenu;
extern MapMenu* DAT_011da368;

// @fnv 0x00704450
void FUN_00704450(char bShow)
{
    if (DAT_011da368)
        ((char*)DAT_011da368)[0x12c] = bShow;
}

extern "C" void __cdecl FUN_0079b430(int);

// @fnv 0x00704470
void __cdecl FUN_00704470(int arg)
{
    if (arg)
    {
        FUN_0079b430(arg);
    }
}

namespace fnv_00704690 {
class Modifier
{
  public:
    unsigned char GetKey();
};
void CreateRepairServicesMenu(unsigned int);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, forwards arg to CreateRepairServicesMenu.
// @fnv 0x00704690
void FUN_00704690(unsigned int arg)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        CreateRepairServicesMenu(arg);
}
}  // namespace fnv_00704690

class ContainerMenu
{
  public:
    void FUN_0075c280(int);
};
extern ContainerMenu* DAT_011d93f8;

// @fnv 0x00704bc0
void FUN_00704bc0()
{
    if (DAT_011d93f8)
        DAT_011d93f8->FUN_0075c280(0);
}

namespace fnv_00704f80 {
struct Modifier
{
    bool GetKey();
};

extern "C" void __cdecl InitInventoryMenu(unsigned int, unsigned int);

// @fnv 0x00704f80
void FUN_00704f80(unsigned int a1, unsigned int a2)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        InitInventoryMenu(a1, a2);
}
}  // namespace fnv_00704f80

namespace fnv_00704fc0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

extern "C" void __cdecl CreateRecipeMenu(int, int);

// @fnv 0x00704fc0
void FUN_00704fc0(int a1, int a2)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        CreateRecipeMenu(a1, a2);
}
}  // namespace fnv_00704fc0

void FUN_00705050();

// @fnv 0x00705040
void FUN_00705040()
{
    FUN_00705050();
}

namespace fnv_00705050 {
class ContainerMenu;
extern ContainerMenu* DAT_011d93f8;

// @fnv 0x00705050
void* FUN_00705050()
{
    if (DAT_011d93f8)
    {
        return *(void**)((char*)DAT_011d93f8 + 0x80);
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_00705050

// @fnv 0x00705770
unsigned int FUN_00705770()
{
    return 0x3f4;
}

namespace fnv_00705800 {
class Modifier
{
  public:
    unsigned char GetKey();
};
class StartMenu
{
  public:
    static bool Create(bool, bool);
};

// @fnv 0x00705800
void FUN_00705800()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        StartMenu::Create(true, true);
}
}  // namespace fnv_00705800

namespace fnv_00705830 {
struct Modifier
{
    unsigned char GetKey();
};

void CreateLockpickMenu(int, int, unsigned char);

// @fnv 0x00705830
void FUN_00705830(int a1, int a2, unsigned char a3)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        CreateLockpickMenu(a1, a2, a3);
}
}  // namespace fnv_00705830

struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011c3ea4;
extern int g_011d8950;
extern int DAT_011d8960;

void FUN_00763ff0();
void GetOrCreateMenuTile(int);

// @fnv 0x00705870
void FUN_00705870(int arg)
{
    if (FUN_00705100())
        FUN_00763ff0();

    if (*g_011c3ea4.Int() > 1 && g_011d8950 == 0)
    {
        g_011d8950 = 5;
        DAT_011d8960 = arg;
    }
    else
    {
        GetOrCreateMenuTile(arg);
    }
}

namespace fnv_00705a60 {
struct Modifier
{
    unsigned char GetKey();
    void FUN_00717e30();
};

// @fnv 0x00705a60
void FUN_00705a60()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<Modifier*>(FUN_004b7210())->FUN_00717e30();
}
}  // namespace fnv_00705a60

namespace fnv_00705ad0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

struct FUN_00705b10_Dummy
{
    void Set(int);
};

// @fnv 0x00705ad0
void FUN_00705ad0(int arg)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<FUN_00705b10_Dummy*>(FUN_004b7210())->Set(arg);
}
}  // namespace fnv_00705ad0

namespace fnv_00705d90 {
struct Modifier
{
    unsigned char GetKey();
    int FUN_00705dd0();
};

// @fnv 0x00705d90
int FUN_00705d90()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<Modifier*>(FUN_004b7210())->FUN_00705dd0();
    return -1;
}
}  // namespace fnv_00705d90

namespace fnv_00706230 {
struct Modifier
{
    unsigned char GetKey();
};

extern "C" void __cdecl FUN_007e41f0(int, int);

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, forwards a and b to FUN_007e41f0.
// @fnv 0x00706230
void FUN_00706230(int aiArg1, int aiArg2)
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        FUN_007e41f0(aiArg1, aiArg2);
}
}  // namespace fnv_00706230

namespace fnv_00706270 {
class Modifier
{
  public:
    unsigned char GetKey();
};

void FUN_00784c80();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls FUN_00784c80.
// @fnv 0x00706270
void FUN_00706270()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        FUN_00784c80();
}
}  // namespace fnv_00706270

class MapMenu;
extern MapMenu* DAT_011da368;

// Returns the value at offset 0x80 of DAT_011da368 minus 0x20, or 4 when DAT_011da368 is null.
// @fnv 0x00706830
char FUN_00706830()
{
    int v;
    if (DAT_011da368)
        v = ((int*)DAT_011da368)[0x80 / 4] - 0x20;
    else
        v = 4;
    return (char)v;
}

struct FUN_005e3fc0_shell
{
    unsigned int Get();
};
// @fnv 0x00706d10
unsigned int FUN_00706d10()
{
    return ((FUN_005e3fc0_shell*)FUN_004b7210())->Get();
}

void __cdecl FUN_00717280(int aiSoundIndex);

// @fnv 0x00706f30
void FUN_00706f30(int aiSoundIndex)
{
    FUN_00717280(aiSoundIndex);
}

void __cdecl RemoveNodeById(int);
// @fnv 0x00706f90
void __cdecl FUN_00706f90(int aiValue)
{
    FUN_004b7210();
    RemoveNodeById(aiValue);
}

struct FUN_00709920_Class
{
    const char* FUN_00709920();
};

// @fnv 0x00709920
const char* FUN_00709920_Class::FUN_00709920()
{
    return "TILE";
}

class Tile;
class TileRect
{
  public:
    const char* FUN_00709970();
};

// @fnv 0x00709970
const char* TileRect::FUN_00709970()
{
    return "RECT";
}

class TileMenu
{
  public:
    const char* FUN_00709a50();
};

// @fnv 0x00709a50
const char* TileMenu::FUN_00709a50()
{
    return "MENU";
}

// @fnv 0x00709be0
bool IsSomethingZero()
{
    return *(int*)((char*)FUN_004b7210() + 0x4bc) == 0;
}

void FUN_0077f2f0(int a1);

// @fnv 0x00709c20
void FUN_00709c20(int a1)
{
    FUN_0077f2f0(a1);
}

extern int DAT_011da204;

// @fnv 0x0078e0d0
void FUN_0078e0d0()
{
    if (DAT_011da204)
        *(int*)((char*)DAT_011da204 + 0x28) = 7;
}

namespace fnv_00703150 {
struct Modifier
{
    unsigned char GetKey();
};
extern "C" unsigned char __cdecl FUN_00703150();

// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, returns the byte at offset 0xdd of that object; otherwise returns 0.
// @fnv 0x00703150
unsigned char FUN_00703150()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(FUN_004b7210()) + 0xdd);
    return 0;
}
}  // namespace fnv_00703150

namespace fnv_00703e10 {
class ConsoleManager
{
  public:
    static ConsoleManager* __cdecl Instance(bool);
    bool IsConsoleActive(void);
    void FUN_0071d580();
};

class Modifier
{
  public:
    unsigned char GetKey(void);
};

class FUN_00714d90_struct
{
  public:
    void PushMenuStackEntry(int);
};

// @fnv 0x00703e10
void __cdecl FUN_00703e10()
{
    if (FUN_004b7210() != 0 && ((Modifier*)FUN_004b7210())->GetKey() != 0 && ConsoleManager::Instance(0) != 0 &&
        !ConsoleManager::Instance(1)->IsConsoleActive())
    {
        ConsoleManager::Instance(1)->FUN_0071d580();
        ((FUN_00714d90_struct*)FUN_004b7210())->PushMenuStackEntry(3);
    }
}
}  // namespace fnv_00703e10

extern int _DAT_011da368;

// @fnv 0x00704400
char __cdecl FUN_00704400()
{
    if (_DAT_011da368 != 0)
    {
        return *(char*)(_DAT_011da368 + 0x12C);
    }
    else
    {
        return 1;
    }
}

namespace fnv_00705cb0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

// If FUN_004b7210() returns a modifier whose GetKey() is nonzero, returns its IsDone() result; otherwise returns -1.
// @fnv 0x00705cb0
char FUN_00705cb0()
{
    if (FUN_004b7210() && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<ActiveEffect*>(FUN_004b7210())->IsDone();
    return -1;
}
}  // namespace fnv_00705cb0

extern "C" char __cdecl GetInterfaceManagerResult();
extern "C" char __cdecl FUN_00705cb0();
extern "C" char __cdecl FUN_00705d10();
extern "C" char __cdecl FUN_00705d50();
extern "C" int __cdecl FUN_00705d90();

struct TESSaveLoadGame
{
    void FUN_008579b0(void*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

// Reads the inventory, stats, map and magic tab values plus the current main menu, clamps each tab to at least 1, and writes them to the save/load game.
// @fnv 0x00706610
void __cdecl SaveMenuTabStates()
{
    char acInventoryTab;
    char acStatsTab4;
    char acMagicTab;
    char acMapTab9;
    int icurrentMainMenu;

    acInventoryTab = GetInterfaceManagerResult();
    acStatsTab4 = FUN_00705cb0();
    acMapTab9 = FUN_00705d10();
    acMagicTab = FUN_00705d50();
    icurrentMainMenu = FUN_00705d90();

    if (acInventoryTab < 1)
        acInventoryTab = 1;
    if (acStatsTab4 < 1)
        acStatsTab4 = 1;
    if (acMapTab9 < 1)
        acMapTab9 = 1;
    if (acMagicTab < 1)
        acMagicTab = 1;

    g_TESSaveLoadGame->FUN_008579b0(&acInventoryTab, 1);
    g_TESSaveLoadGame->FUN_008579b0(&acStatsTab4, 1);
    g_TESSaveLoadGame->FUN_008579b0(&acMapTab9, 1);
    g_TESSaveLoadGame->FUN_008579b0(&acMagicTab, 1);
    g_TESSaveLoadGame->FUN_008579b0(&icurrentMainMenu, 4);
}

struct FUN_00406f90_this
{
    int FUN_00406f90(char const*, char*);
};
// Calls the object's FUN_00406f90 with apFormat and the address just past it, then returns its result.
// @fnv 0x00406f60
int __cdecl FUN_00406f60(FUN_00406f90_this* p, char const* apFormat, ...)
{
    int ires;
    char* marker;
    marker = (char*)(&apFormat + 1);
    ires = p->FUN_00406f90(apFormat, marker);
    marker = 0;
    return ires;
}

namespace fnv_00703030 {
struct FUN_00703060_shell
{
    char _pad[0x7c];
    bool b7c;
    void FUN_00703060(bool);
    void FUN_00703030();
};
// Calls FUN_00703060 with 0 when b7c is set, otherwise with 1.
// @fnv 0x00703030
void FUN_00703060_shell::FUN_00703030()
{
    if (b7c)
        FUN_00703060(0);
    else
        FUN_00703060(1);
}
}  // namespace fnv_00703030

namespace fnv_00703080 {
struct Modifier
{
    char GetKey();
};
struct Holder
{
    void UpdateTilePosition(float, float);
};
// If FUN_004b7210() returns a non-null object whose GetKey() is nonzero, calls UpdateTilePosition(a1, a2) on it.
// @fnv 0x00703080
void FUN_00703080(float afValue1, float afValue2)
{
    if (FUN_004b7210() && (unsigned char)reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<Holder*>(FUN_004b7210())->UpdateTilePosition(afValue1, afValue2);
}
}  // namespace fnv_00703080

namespace fnv_007037e0 {
class Modifier
{
  public:
    char GetKey();
    void ClearMenuIDs();
};
// If FUN_004b7210 returns a Modifier whose GetKey is nonzero, calls ClearMenuIDs on it.
// @fnv 0x007037e0
void FUN_007037e0()
{
    if (FUN_004b7210() && (unsigned char)reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        reinterpret_cast<Modifier*>(FUN_004b7210())->ClearMenuIDs();
}
}  // namespace fnv_007037e0

namespace fnv_00703810 {
struct Modifier
{
    char GetKey();
};
InterfaceManager* FUN_004b7210();
struct FakeTile
{
    NiNode* FUN_0056c7f0();
};
// If the interface manager exists and its modifier key is set, culls or unculls the tile's scene node according to abVisible.
// @fnv 0x00703810
void FUN_00703810(bool abVisible)
{
    if (FUN_004b7210() && (unsigned char)((Modifier*)FUN_004b7210())->GetKey())
    {
        ((FakeTile*)FUN_004b7210()->FUN_00586150())->FUN_0056c7f0()->SetAppCulled(!abVisible);
    }
}
}  // namespace fnv_00703810

namespace fnv_00705d10 {
struct Modifier
{
    char GetKey();
};
struct IdleAnimationManager
{
    bool FUN_00843150();
};
// Returns FUN_00843150's result when FUN_004b7210 is non-null and GetKey is nonzero; otherwise returns -1.
// @fnv 0x00705d10
char FUN_00705d10()
{
    if (FUN_004b7210() && (unsigned char)reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<IdleAnimationManager*>(FUN_004b7210())->FUN_00843150();
    return -1;
}
}  // namespace fnv_00705d10

namespace fnv_00705d50 {
struct Modifier
{
    char GetKey();
};
struct Byte15Accessor
{
    char GetByte15();
};
// If FUN_004b7210() returns a non-null object whose GetKey() is nonzero, returns the result of GetByte15() on it; otherwise returns -1.
// @fnv 0x00705d50
char FUN_00705d50()
{
    if (FUN_004b7210() && (unsigned char)reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey())
        return reinterpret_cast<Byte15Accessor*>(FUN_004b7210())->GetByte15();
    return -1;
}
}  // namespace fnv_00705d50

struct UnnamedClass_00705dd0
{
    char _pad[0x9c];
    Tile* m_9c;
    int FUN_00705dd0();
};
// @fnv 0x00705dd0
int UnnamedClass_00705dd0::FUN_00705dd0()
{
    return (int)m_9c->GetFloat(0x1771);
}

struct FORenderedTerminal
{
    void FUN_007060d0();
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x007060a0
void* FORenderedTerminal::DestroyIfFlagged(unsigned int flags)
{
    FUN_007060d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

int __cdecl MinInt(int, int);

struct FUN_00706810_Class
{
    int __thiscall FUN_00706810();
};

// @fnv 0x00706810
int __thiscall FUN_00706810_Class::FUN_00706810()
{
    return MinInt(1, 1) + 5;
}

struct Dummy00712450
{
    int SetNodeAlpha();
};
Dummy00712450* __stdcall _FUN_004b7210(int, float, float);
// Calls _FUN_004b7210 with a, b and c, then returns the result of SetNodeAlpha on the returned object.
// @fnv 0x00707010
int FUN_00707010(int aiArg, float afArg1, float afArg2)
{
    return _FUN_004b7210(aiArg, afArg1, afArg2)->SetNodeAlpha();
}

namespace fnv_00706860 {
struct SaveLoadFile;
struct NiQuaternion;
struct hkVector4;
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];

InterfaceManager* FUN_004b7210();
struct Tile_Set_Helper
{
    void Set(int, int);
};
class StatsMenu
{
  public:
    static void SetStatsPage(unsigned char);
};
void FUN_00706a20(unsigned char);
void FUN_007069d0(unsigned char);
void FUN_007a1820(float);
void FUN_007a1850(float);
struct TutorialState
{
    void LoadTutorialSeenFlags(char*);
};
void* memset(void*, int, unsigned int);
// Reads menu page indices and map magnifications from the load buffer, applies them to the UI, and reads a settings blob when the version is at least 12.
// @fnv 0x00706860
void LoadMenuState(BGSLoadGameBuffer* apLoadGameBuffer)
{
    unsigned char cstatsPage;
    int ifrontMostMenu;
    unsigned char cinventoryPage;
    float fworldMapMagnification;
    unsigned char cmapPage;
    float flocalMapMagnification;
    ifrontMostMenu = 0;
    cstatsPage = 0;
    cinventoryPage = 0;
    cmapPage = 0;
    apLoadGameBuffer->ReadDataBlock(&ifrontMostMenu, 4);
    apLoadGameBuffer->ReadDataBlock(&cstatsPage, 1);
    apLoadGameBuffer->ReadDataBlock(&cinventoryPage, 1);
    apLoadGameBuffer->ReadDataBlock(&cmapPage, 1);
    reinterpret_cast<Tile_Set_Helper*>(FUN_004b7210()->FUN_00586150())->Set(0x1771, ifrontMostMenu);
    StatsMenu::SetStatsPage(cstatsPage);
    FUN_00706a20(cinventoryPage);
    FUN_007069d0(cmapPage);
    flocalMapMagnification = 0;
    fworldMapMagnification = 0;
    apLoadGameBuffer->ReadDataBlock(&flocalMapMagnification, 4);
    apLoadGameBuffer->ReadDataBlock(&fworldMapMagnification, 4);
    FUN_007a1820(flocalMapMagnification);
    FUN_007a1850(fworldMapMagnification);
    if (apLoadGameBuffer->GetVersion() >= 12)
    {
        unsigned int isettingsSize;
        char psettings[100];
        memset(psettings, 0, 100);
        isettingsSize = 0;
        apLoadGameBuffer->ReadDataBlock(&isettingsSize, 4);
        apLoadGameBuffer->ReadDataBlock(psettings, isettingsSize);
        reinterpret_cast<TutorialState*>((char*)FUN_004b7210() + 0x4d4)->LoadTutorialSeenFlags(psettings);
    }
    else
    {
        char ptempString[260];
        apLoadGameBuffer->LoadString(ptempString);
    }
}
}  // namespace fnv_00706860

namespace fnv_00703610 {
struct Tile_Set_Helper
{
    void Set(int, int);
};
class MenuPC : public Menu
{
  public:
    void SetFadeState(int);
    Tile* GetTile();
};
class InterfaceManagerPC
{
  public:
    bool GetKey();
};
struct PlayerCharacterPC
{
    static bool UpdatePlayerStatus();
};
struct Im7181
{
    void SetRenderedMenu(int);
};
Tile* __cdecl FindMenuById(int);
void __cdecl FUN_00704f50();
void __cdecl CloseStartMenu(bool);

// @fnv 0x00703610
void __cdecl FUN_00703610()
{
    Tile* pinv;
    Tile* prepair;
    Tile* pstat;
    InterfaceManager* pim;
    Tile* pmap;
    Tile* pitemmod;

    if (FUN_004b7210() && ((InterfaceManagerPC*)FUN_004b7210())->GetKey())
    {
        pim = FUN_004b7210();
        pstat = (FindMenuById)(Interface::eStatsMenu);
        pinv = (FindMenuById)(Interface::eInventoryMenu);
        prepair = (FindMenuById)(Interface::eRepairMenu);
        pitemmod = (FindMenuById)(Interface::eItemModMenu);
        pmap = (FindMenuById)(Interface::eMapMenu);
        if (pstat)
        {
            ((MenuPC*)pstat->GetMenu())->SetFadeState(4);
            ((Tile_Set_Helper*)((MenuPC*)pstat->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (pinv)
        {
            ((MenuPC*)pinv->GetMenu())->SetFadeState(4);
            ((Tile_Set_Helper*)((MenuPC*)pinv->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (prepair)
        {
            ((MenuPC*)prepair->GetMenu())->SetFadeState(4);
            ((Tile_Set_Helper*)((MenuPC*)prepair->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (pitemmod)
        {
            ((MenuPC*)pitemmod->GetMenu())->SetFadeState(4);
            ((Tile_Set_Helper*)((MenuPC*)pitemmod->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        if (pmap)
        {
            ((MenuPC*)pmap->GetMenu())->SetFadeState(4);
            ((Tile_Set_Helper*)((MenuPC*)pmap->GetMenu())->GetTile())->Set(0xfa3, 0);
        }
        FUN_00704f50();
        if (PlayerCharacterPC::UpdatePlayerStatus())
            CloseStartMenu(true);
        ((Im7181*)pim)->SetRenderedMenu(0);
    }
}
}  // namespace fnv_00703610

namespace fnv_007024e0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class BSThread
{
  public:
    unsigned int GetThreadID();
};

struct InterfaceManagerStandIn
{
    int GetTopEnterStackEntry();
};

struct InterfaceStandIn
{
    static bool IsMenuActive(Interface::enumMenus, unsigned int);
};

void* __cdecl _FUN_004b7210();
Menu* __cdecl FindMenuById(int);

// Checks the current modifier and interface menu, resolves a tile for the active menu, and returns whether its menu's thread ID equals 1.
// @fnv 0x007024e0
bool FUN_007024e0()
{
    Tile* ptile;
    int topid;

    if (_FUN_004b7210())
    {
        if (reinterpret_cast<Modifier*>(_FUN_004b7210())->GetKey())
        {
            ptile = 0;
            topid = reinterpret_cast<InterfaceManagerStandIn*>(_FUN_004b7210())->GetTopEnterStackEntry();

            if (topid == 1)
            {
                if (InterfaceStandIn::IsMenuActive(static_cast<Interface::enumMenus>(0x3eb), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x3eb));
                else if (InterfaceStandIn::IsMenuActive(static_cast<Interface::enumMenus>(0x3ea), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x3ea));
                else if (InterfaceStandIn::IsMenuActive(static_cast<Interface::enumMenus>(0x40b), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x40b));
                else if (InterfaceStandIn::IsMenuActive(static_cast<Interface::enumMenus>(0x425), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x425));
                else if (InterfaceStandIn::IsMenuActive(static_cast<Interface::enumMenus>(0x3ff), 0))
                    ptile = reinterpret_cast<Tile*>(FindMenuById(0x3ff));
            }
            else
            {
                ptile = reinterpret_cast<Tile*>(FindMenuById(topid));
            }

            if (ptile && ptile->GetMenu())
            {
                return reinterpret_cast<BSThread*>(ptile->GetMenu())->GetThreadID() == 1;
            }
        }
    }

    return false;
}
}  // namespace fnv_007024e0

namespace fnv_00704170 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class ProxyPipboy : public FOPipboyManager
{
};

class ProxyMgr
{
  public:
    ProxyPipboy* GetPipboyManager();
};

class MapMenu
{
  public:
    static void MenuDepthController();
};

struct InterfaceAccess
{
    static bool IsMenuActive(Interface::enumMenus menuID, unsigned int flags);
};

struct TileAccess
{
    void Set(int x, int y);
};

struct MenuAccess
{
    void LoadMenuData();
    void UnloadMenuData();
};

struct PipboyAccess
{
    void FUN_007f8a80();
};

struct MenuVirtualAccess
{
    virtual void FUN_00();
    virtual void FUN_01();
    virtual void FUN_02();
    virtual void FUN_03();
    virtual void FUN_04();
    virtual void FUN_05(int, int);
};

Menu* __cdecl FindMenuById(int);
Tile* __cdecl FUN_00704140();
void __cdecl FUN_00704390();
void __cdecl ResetItemModMenu();
void __cdecl ResetRepairMenu();
void __cdecl FUN_0079c340(bool);

// @fnv 0x00704170
void __cdecl UpdatePipboyMapVisibility(bool abVisibility, bool abAnyVisibleState)
{
    if (FUN_004b7210() != 0 && reinterpret_cast<Modifier*>(FUN_004b7210())->GetKey() != 0)
    {
        Tile* pinv;
        Tile* prepair;
        bool bMapVisible;
        Tile* pstat;
        Tile* pmap;
        Tile* pitemmod;

        pstat = reinterpret_cast<Tile*>(FindMenuById(1003));
        pinv = reinterpret_cast<Tile*>(FindMenuById(1002));
        prepair = reinterpret_cast<Tile*>(FindMenuById(1035));
        pitemmod = reinterpret_cast<Tile*>(FindMenuById(1061));
        pmap = reinterpret_cast<Tile*>(FindMenuById(1023));

        bMapVisible =
            InterfaceAccess::IsMenuActive(static_cast<Interface::enumMenus>(1023), abAnyVisibleState ? 11 : 0);

        if (abVisibility && !bMapVisible)
        {
            if (pstat != 0)
            {
                reinterpret_cast<MenuAccess*>(pstat->GetMenu())->LoadMenuData();
                FUN_00704390();
            }

            if (prepair != 0)
            {
                reinterpret_cast<MenuAccess*>(prepair->GetMenu())->LoadMenuData();
                ResetRepairMenu();
            }

            if (pitemmod != 0)
            {
                reinterpret_cast<MenuAccess*>(pitemmod->GetMenu())->LoadMenuData();
                ResetItemModMenu();
            }

            if (pinv != 0)
                reinterpret_cast<MenuAccess*>(pinv->GetMenu())->LoadMenuData();

            if (pmap == 0)
                pmap = FUN_00704140();

            if (pmap != 0)
            {
                reinterpret_cast<TileAccess*>(FUN_004b7210()->FUN_00586150())->Set(6001, 1023);
            }

            if (pmap != 0)
                reinterpret_cast<MenuAccess*>(pmap->GetMenu())->UnloadMenuData();

            MapMenu::MenuDepthController();
        }
        else if (!abVisibility && bMapVisible)
        {
            if (pmap != 0)
            {
                reinterpret_cast<MenuAccess*>(pmap->GetMenu())->LoadMenuData();
                reinterpret_cast<MenuVirtualAccess*>(pmap->GetMenu())->FUN_05(0, 0);
            }
        }

        if (abVisibility)
        {
            reinterpret_cast<PipboyAccess*>(reinterpret_cast<ProxyMgr*>(FUN_004b7210())->GetPipboyManager())
                ->FUN_007f8a80();

            reinterpret_cast<ProxyMgr*>(FUN_004b7210())->GetPipboyManager()->ActivateButton(3);

            if (reinterpret_cast<ProxyMgr*>(FUN_004b7210())->GetPipboyManager()->GetInitialized())
            {
                FUN_0079c340(false);
            }
        }
    }
}
}  // namespace fnv_00704170

namespace fnv_007056f0 {
class Modifier
{
  public:
    unsigned char GetKey();
};

class SleepWaitMenu : public Menu
{
  public:
    bool FUN_007c0580();
};

unsigned int __cdecl FUN_00705770();
Menu* __cdecl FindMenuById(int);
Modifier* __cdecl _FUN_004b7210();

// @fnv 0x007056f0
bool FUN_007056f0()
{
    SleepWaitMenu* pSleepWaitMenu;
    Tile* ptile;

    ptile = reinterpret_cast<Tile*>(FindMenuById(FUN_00705770()));
    pSleepWaitMenu = ptile ? static_cast<SleepWaitMenu*>(ptile->GetMenu()) : 0;

    return _FUN_004b7210() && _FUN_004b7210()->GetKey() && pSleepWaitMenu && pSleepWaitMenu->FUN_007c0580();
}
}  // namespace fnv_007056f0

class FUN_004b7210_class;

extern FUN_004b7210_class* __cdecl _FUN_004b7210();

class FUN_004b7210_class
{
  public:
    unsigned char GetKey();
    BSSimpleList<BGSPerk*>* GetBGSPerkList();
};

// Returns the perk list from the object obtained via _FUN_004b7210 when its key is nonzero, otherwise returns null.
// @fnv 0x00705950
BSSimpleList<BGSPerk*>* FUN_00705950()
{
    if (_FUN_004b7210() && _FUN_004b7210()->GetKey())
    {
        return _FUN_004b7210()->GetBGSPerkList();
    }
    else
    {
        return 0;
    }
}

namespace fnv_007073d0 {
struct Setting
{
};

struct StartMenu : Setting
{
    const char* GetMenuTitle();
};

struct Setting_S : Setting
{
    float* Float();
};

struct GlobalObject_0045cf30 : Setting
{
    unsigned char* Bool();
};

struct GlobalObject_0045cfe0 : Setting
{
    int* Int();
};

struct GameSettingCollection
{
    static GameSettingCollection* Instance();
    Setting* FUN_004f8a30(const char*);
};

template <class T> struct SettingCollectionList
{
    T* GetPtr(const char*);
};

struct INISettingCollection : SettingCollectionList<Setting>
{
};

template <class T> struct SettingT
{
    static INISettingCollection* GetCollection();
};

struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};

void ___insecure_strcpy(char*, const char*);
int strcat_s(char*, unsigned int, const char*);
int _BSStringLength(const char*);
int _sprintf(char*, const char*, ...);
void __fastcall _ref_00ec408c(unsigned int);

extern unsigned int __security_cookie;

// Looks up a game or INI setting by name (stripping a leading '&' or '-') and writes its string, int, float or bool value into axStringOut.
// @fnv 0x007073d0
bool ResolveSettingString(const char* apString, char* apValueOut)
{
    Setting* psetting;
    int istartIndex;
    char xstr[260];

    if (!apString || !apString[0])
        return false;

    istartIndex = 0;
    if (apString[istartIndex] == '&')
        ++istartIndex;
    if (apString[istartIndex] == '-')
        ++istartIndex;

    TaskQueueInterface::CopyStringToBuffer(xstr, 0x104, apString + istartIndex);

    if (xstr[_BSStringLength(xstr) - 1] == ';')
        xstr[_BSStringLength(xstr) - 1] = 0;

    psetting = GameSettingCollection::Instance()->FUN_004f8a30(xstr);
    if (!psetting)
    {
        strcat_s(xstr, 0x104, ":LANGUAGE");
        psetting = SettingT<INISettingCollection>::GetCollection()->GetPtr(xstr);
    }

    if (psetting)
    {
        if (xstr[0] == 's' || xstr[0] == 'S')
        {
            ___insecure_strcpy(apValueOut, static_cast<StartMenu*>(psetting)->GetMenuTitle());
        }
        else if (xstr[0] == 'i' || xstr[0] == 'I')
        {
            _sprintf(xstr, "%i", *static_cast<GlobalObject_0045cfe0*>(psetting)->Int());
            ___insecure_strcpy(apValueOut, xstr);
        }
        else if (xstr[0] == 'f' || xstr[0] == 'F')
        {
            _sprintf(xstr, "%i", *static_cast<Setting_S*>(psetting)->Float());
            ___insecure_strcpy(apValueOut, xstr);
        }
        else if (xstr[0] == 'b' || xstr[0] == 'B')
        {
            if (*static_cast<GlobalObject_0045cf30*>(psetting)->Bool() == 1)
                ___insecure_strcpy(apValueOut, "&true;");
            else
                ___insecure_strcpy(apValueOut, "&false;");
        }

        return true;
    }

    return false;
}
}  // namespace fnv_007073d0

namespace fnv_00702c80 {
class List_009e03e0
{
  public:
    void RemoveAll();
};

class Modifier
{
  public:
    unsigned char GetKey();
};

class GO
{
  public:
    operator unsigned int() const;
};

class TL
{
  public:
    void* GetNext(void*&);
};

class FUN_005e3fc0_shell
{
  public:
    unsigned int Get();
};

class EffectSettingStub
{
  public:
    void* GetBoltSound();
};

void* _FUN_004b7210();
void UpdateVisibility(void*, bool, bool, bool);

// @fnv 0x00702c80
void FUN_00702c80(bool abFlag1, bool abFlag2)
{
    if (_FUN_004b7210())
    {
        if (reinterpret_cast<Modifier*>(_FUN_004b7210())->GetKey())
        {
            void* current = _FUN_004b7210();
            if (abFlag1 && !abFlag2)
            {
                reinterpret_cast<List_009e03e0*>(reinterpret_cast<char*>(current) + 0x4c4)->RemoveAll();
            }

            Tile* p2 = reinterpret_cast<InterfaceManager*>(_FUN_004b7210())->FUN_00586150();
            void* tile = reinterpret_cast<void*>(
                reinterpret_cast<GO*>(reinterpret_cast<char*>(p2) + 4)->operator unsigned int());

            while (tile)
            {
                void* item =
                    *reinterpret_cast<void**>(reinterpret_cast<TL*>(reinterpret_cast<char*>(p2) + 4)->GetNext(tile));

                UpdateVisibility(item, abFlag1, abFlag2, true);
            }

            if (!abFlag1 && !abFlag2)
            {
                if (reinterpret_cast<FUN_005e3fc0_shell*>(_FUN_004b7210())->Get())
                {
                    reinterpret_cast<NiAVObject*>(reinterpret_cast<FUN_005e3fc0_shell*>(_FUN_004b7210())->Get())
                        ->SetAppCulled(false);
                }

                if (reinterpret_cast<EffectSettingStub*>(_FUN_004b7210())->GetBoltSound())
                {
                    reinterpret_cast<NiAVObject*>(reinterpret_cast<EffectSettingStub*>(_FUN_004b7210())->GetBoltSound())
                        ->SetAppCulled(false);
                }
            }
            else
            {
                if (reinterpret_cast<FUN_005e3fc0_shell*>(_FUN_004b7210())->Get())
                {
                    reinterpret_cast<NiAVObject*>(reinterpret_cast<FUN_005e3fc0_shell*>(_FUN_004b7210())->Get())
                        ->SetAppCulled(true);
                }

                if (reinterpret_cast<EffectSettingStub*>(_FUN_004b7210())->GetBoltSound())
                {
                    reinterpret_cast<NiAVObject*>(reinterpret_cast<EffectSettingStub*>(_FUN_004b7210())->GetBoltSound())
                        ->SetAppCulled(true);
                }
            }
        }
    }
}
}  // namespace fnv_00702c80

struct StubMenu
{
    void CloseA();
    void CloseB();
};
struct StubTile
{
    StubMenu* GetMenuX();
    void SetX(int trait, int value);
};
struct StubPipboy
{
    void DoA();
    void ActivateBtn(unsigned int button);
    bool IsInit();
};
struct StubIM
{
    bool KeyX();
    StubTile* RootX();
    StubPipboy* PipboyX();
};
StubIM* GetIM();
StubTile* __cdecl MenuByClass(int aiClass);
bool __cdecl MenuVisible(int aiID, unsigned int auFade);
StubTile* __cdecl CreateMenuX();
void __cdecl AfterCloseX();
void __cdecl SetPipboyX(bool ab);

// @fnv 0x007044c0
void FUN_007044c0(bool abShow, bool abInstant, bool abActivate)
{
    if (GetIM() && GetIM()->KeyX())
    {
        StubTile* pA = MenuByClass(0x3eb);
        StubTile* pB = MenuByClass(0x3ea);
        StubTile* pCA = MenuByClass(0x40b);
        StubTile* pD = MenuByClass(0x425);
        StubTile* pE2 = MenuByClass(0x3ff);
        bool bVisible = MenuVisible(0x40b, abInstant ? 0xb : 0);
        if (abShow)
        {
            if (!pCA)
                pCA = CreateMenuX();
            if (!bVisible)
            {
                if (pA)
                {
                    pA->GetMenuX()->CloseA();
                    AfterCloseX();
                }
                if (pE2)
                    pE2->GetMenuX()->CloseA();
                if (pD)
                    pD->GetMenuX()->CloseA();
                if (pCA)
                    pCA->GetMenuX()->CloseB();
                if (pB)
                    pB->GetMenuX()->CloseA();
            }
            if (pCA)
                GetIM()->RootX()->SetX(0x1771, 0x40b);
            if (abActivate)
            {
                GetIM()->PipboyX()->DoA();
                GetIM()->PipboyX()->ActivateBtn(2);
            }
            if (GetIM()->PipboyX()->IsInit())
                SetPipboyX(false);
        }
        else if (!abShow && bVisible && pCA)
        {
            pCA->GetMenuX()->CloseA();
        }
    }
}

struct TerminalBase
{
    int unk00;
    ~TerminalBase();
};

struct TerminalMember
{
    ~TerminalMember();
};

struct FUN_007060d0_cls : TerminalBase
{
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
    TerminalMember m_kMemberDescriptor;
    ~FUN_007060d0_cls();
};

// Destructor for the class; destroys the embedded member and the base, with no other work.
// @fnv 0x007060d0
FUN_007060d0_cls::~FUN_007060d0_cls()
{}

class B706130Node;

class B706130Tile
{
  public:
    B706130Node* FUN_0056c7f0();
};

class B706130Pick
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    B706130Pick();

    void SetTile(B706130Tile* pkTile);
    void FUN_00705fc0(B706130Node* pkNode);

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
    int unkE4;
    int unkE8;
    int unkEC;
};

class B706130Manager
{
  public:
    bool GetKey();
    void SetRenderedMenu(B706130Pick* pkPick);
};

class B706130Setting
{
  public:
    unsigned char* Bool();
};

B706130Manager* __cdecl B706130GetManager();
B706130Tile* __cdecl CreateComputerMenu(int m_uiSoundID);
void __cdecl B706130UpdateAllTiles(bool bForce);

extern B706130Setting g_kB706130Setting;

// @fnv 0x00706130
bool __cdecl FUN_00706130(int m_uiSoundID)
{
    if (B706130GetManager() && B706130GetManager()->GetKey())
    {
        B706130Tile* pkTile = CreateComputerMenu(m_uiSoundID);
        B706130UpdateAllTiles(false);
        if (*g_kB706130Setting.Bool())
        {
            B706130Pick* pkPick = new B706130Pick;
            pkPick->SetTile(pkTile);
            pkPick->FUN_00705fc0(pkTile->FUN_0056c7f0());
            B706130GetManager()->SetRenderedMenu(pkPick);
        }
        return true;
    }
    else
    {
        return false;
    }
}

class FUN_00707870_Temp
{
  public:
    float m_v;
    FUN_00707870_Temp(float f);
    ~FUN_00707870_Temp();
};

struct FUN_00707870_Owner
{
    int FUN_00457ba0(unsigned int a, FUN_00707870_Temp* b);
};

struct FUN_00707870_Target
{
    int FUN_00a5d2c0(FUN_00707870_Temp* b);
};

extern FUN_00707870_Owner* DAT_011dea10;
bool __cdecl FUN_004b5bf0(unsigned int a);

// Constructs a temporary with value 1.0 and dispatches it to DAT_011dea10 or to the object at a1 depending on FUN_004b5bf0(a1).
// @fnv 0x00707870
unsigned int __cdecl FUN_00707870(unsigned int a1)
{
    unsigned int pad[6];
    FUN_00707870_Temp t(1.0f);
    if (FUN_004b5bf0(a1) != 0)
    {
        return DAT_011dea10->FUN_00457ba0(a1, &t);
    }
    else
    {
        return reinterpret_cast<FUN_00707870_Target*>(a1)->FUN_00a5d2c0(&t);
    }
}

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int uExitCode);
extern "C" void __debugbreak();

char ConsumeByteAtE4();
void FUN_00703fd0();
void FUN_0040fbe0(const char* pcMessage);

// Switches on ConsumeByteAtE4: for 1 or 3 warns and exits the process, for 2 calls FUN_00703fd0.
// @fnv 0x0086a530
void FUN_0086a530()
{
    switch (ConsumeByteAtE4())
    {
        break;
    case 1:
    case 3:
        FUN_0040fbe0("Warning Response was to Exit the Process");
        if (IsDebuggerPresent())
            __debugbreak();
        ExitProcess(0);
    case 2:
        FUN_00703fd0();
        break;
    }
}

struct Player;
struct Helper;
struct ActiveObject
{
    int FUN_0041ca90();
};
struct InterfaceObject
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Release();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual ActiveObject* CurrentObject();
};
struct DialogObject
{
    void FUN_009ed0d0(Player*, int);
};
struct Helper
{
    void SetPackageType(int);
    void FUN_00826b40(int);
    void FUN_00826b90(int);
    void FUN_00984f60(int);
};
extern Helper* __cdecl CreatePackageByType(int);
extern DialogObject* __cdecl FUN_00ec43fb(Helper*, int, void*, void*, int);
extern int DAT_011846a0;
extern int DAT_011a32e0;
extern int DAT_011dea3c;
struct Player
{
    virtual void Unknown000();
    virtual void Unknown001();
    virtual void Unknown002();
    virtual void Unknown003();
    virtual void Unknown004();
    virtual void Unknown005();
    virtual void Unknown006();
    virtual void Unknown007();
    virtual void Unknown008();
    virtual void Unknown009();
    virtual void Unknown010();
    virtual void Unknown011();
    virtual void Unknown012();
    virtual void Unknown013();
    virtual void Unknown014();
    virtual void Unknown015();
    virtual void Unknown016();
    virtual void Unknown017();
    virtual void Unknown018();
    virtual void Unknown019();
    virtual void Unknown020();
    virtual void Unknown021();
    virtual void Unknown022();
    virtual void Unknown023();
    virtual void Unknown024();
    virtual void Unknown025();
    virtual void Unknown026();
    virtual void Unknown027();
    virtual void Unknown028();
    virtual void Unknown029();
    virtual void Unknown030();
    virtual void Unknown031();
    virtual void Unknown032();
    virtual void Unknown033();
    virtual void Unknown034();
    virtual void Unknown035();
    virtual void Unknown036();
    virtual void Unknown037();
    virtual void Unknown038();
    virtual void Unknown039();
    virtual void Unknown040();
    virtual void Unknown041();
    virtual void Unknown042();
    virtual void Unknown043();
    virtual void Unknown044();
    virtual void Unknown045();
    virtual void Unknown046();
    virtual void Unknown047();
    virtual void Unknown048();
    virtual void Unknown049();
    virtual void Unknown050();
    virtual void Unknown051();
    virtual void Unknown052();
    virtual void Unknown053();
    virtual void Unknown054();
    virtual void Unknown055();
    virtual void Unknown056();
    virtual void Unknown057();
    virtual void Unknown058();
    virtual void Unknown059();
    virtual void Unknown060();
    virtual void Unknown061();
    virtual void Unknown062();
    virtual void Unknown063();
    virtual void Unknown064();
    virtual void Unknown065();
    virtual void Unknown066();
    virtual void Unknown067();
    virtual void Unknown068();
    virtual void Unknown069();
    virtual void Unknown070();
    virtual void Unknown071();
    virtual void Unknown072();
    virtual void Unknown073();
    virtual void Unknown074();
    virtual void Unknown075();
    virtual void Unknown076();
    virtual void Unknown077();
    virtual void Unknown078();
    virtual void Unknown079();
    virtual void Unknown080();
    virtual void Unknown081();
    virtual void Unknown082();
    virtual void Unknown083();
    virtual void Unknown084();
    virtual void Unknown085();
    virtual void Unknown086();
    virtual void Unknown087();
    virtual void Unknown088();
    virtual void Unknown089();
    virtual void Unknown090();
    virtual void Unknown091();
    virtual void Unknown092();
    virtual void Unknown093();
    virtual void Unknown094();
    virtual void Unknown095();
    virtual void Unknown096();
    virtual void Unknown097();
    virtual void Unknown098();
    virtual void Unknown099();
    virtual void Unknown100();
    virtual void Unknown101();
    virtual void Unknown102();
    virtual void Unknown103();
    virtual void Unknown104();
    virtual void Unknown105();
    virtual void Unknown106();
    virtual void Unknown107();
    virtual void Unknown108();
    virtual void Unknown109();
    virtual void Unknown110();
    virtual void Unknown111();
    virtual void Unknown112();
    virtual void Unknown113();
    virtual void Unknown114();
    virtual void Unknown115();
    virtual void Unknown116();
    virtual void Unknown117();
    virtual void Unknown118();
    virtual void Unknown119();
    virtual void Unknown120();
    virtual void Unknown121();
    virtual void Unknown122();
    virtual void Unknown123();
    virtual void Unknown124();
    virtual void Unknown125();
    virtual void Unknown126();
    virtual void Unknown127();
    virtual void Unknown128();
    virtual void Unknown129();
    virtual void Unknown130();
    virtual void Unknown131();
    virtual void Unknown132();
    virtual void Unknown133();
    virtual void Unknown134();
    virtual void Unknown135();
    virtual void Unknown136();
    virtual void Unknown137();
    virtual void Unknown138();
    virtual void Unknown139();
    virtual void Unknown140();
    virtual void Unknown141();
    virtual void Unknown142();
    virtual void Unknown143();
    virtual void Unknown144();
    virtual void Unknown145();
    virtual void Unknown146();
    virtual void Unknown147();
    virtual void Unknown148();
    virtual void Unknown149();
    virtual void Unknown150();
    virtual void Unknown151();
    virtual void Unknown152();
    virtual void Unknown153();
    virtual void Unknown154();
    virtual void Unknown155();
    virtual void Unknown156();
    virtual void Unknown157();
    virtual void Unknown158();
    virtual void Unknown159();
    virtual void Unknown160();
    virtual void Unknown161();
    virtual void Unknown162();
    virtual void Unknown163();
    virtual void Unknown164();
    virtual void Unknown165();
    virtual void Unknown166();
    virtual void Unknown167();
    virtual void Unknown168();
    virtual void Unknown169();
    virtual void Unknown170();
    virtual void Unknown171();
    virtual void Unknown172();
    virtual void Unknown173();
    virtual void Unknown174();
    virtual void Unknown175();
    virtual void Unknown176();
    virtual void Unknown177();
    virtual void Unknown178();
    virtual void Unknown179();
    virtual void Unknown180();
    virtual void Unknown181();
    virtual void Unknown182();
    virtual void Unknown183();
    virtual void Unknown184();
    virtual void Unknown185();
    virtual void Unknown186();
    virtual void Unknown187();
    virtual void Unknown188();
    virtual void ActivateInterface(Helper*, int, int);
    InterfaceObject* FUN_008d8520();
    bool FUN_00437bf0();
    bool FUN_00437bd0();
    int FUN_008d6f30(int);
    void OpenDialogMenu();
};
// Returns early if the player is busy or the active object is type 26; otherwise builds a menu context, opens a dialog, and activates the interface.
// @fnv 0x008a7760
void Player::OpenDialogMenu()
{
    ActiveObject* active = FUN_008d8520()->CurrentObject();
    if (FUN_00437bf0() || FUN_00437bd0() || (active && active->FUN_0041ca90() == 26))
    {
        return;
    }
    Helper* menuContext = CreatePackageByType(39);
    menuContext->SetPackageType(39);
    menuContext->FUN_00826b40(0);
    menuContext->FUN_00826b90(1);
    DialogObject* dialog = FUN_00ec43fb(menuContext, 0, &DAT_011846a0, &DAT_011a32e0, 0);
    if (dialog)
    {
        dialog->FUN_009ed0d0(this, FUN_008d6f30(DAT_011dea3c));
    }
    menuContext->FUN_00984f60(48);
    FUN_008d8520()->Release();
    ActivateInterface(menuContext, 1, 1);
}

struct TileListAccess
{
    void* GetHeadPos() const;
    Tile*& GetNext(void*& _n);
};
struct VisibilityTile : Tile
{
    float FUN_00a011b0(int trait);
    NiNode* FUN_0056c7f0();
};
struct VisibilityManager
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    BSSimpleList<Tile*> visibilityQueue;
};

// @fnv 0x00702990
void UpdateVisibility(VisibilityTile* tile, bool show, bool alternate, bool queue)
{
    if (!tile)
        return;
    Tile* _node = FUN_004b7210()->FUN_00586150();
    InterfaceManager* current = FUN_004b7210();
    bool _unused = false;
    bool _found = false;
    bool _visible = tile->FUN_00a011b0(0xfaa) == 112.0;
    if ((alternate && !_visible) || (!alternate && _visible))
        tile->SetInt(0x1779, 0);
    else
        tile->SetInt(0x1779, 1);

    void* _n = ((TileListAccess*)&tile->m_kChildTileList)->GetHeadPos();
    while (_n)
    {
        VisibilityTile* _first = (VisibilityTile*)((TileListAccess*)&_node->m_kChildTileList)->GetNext(_n);
        Tile* _child = _first->FUN_00a011b0(0xfaa) == 110.0 ? _first : 0;
        Tile* _second = _first->FUN_00a011b0(0xfaa) == 111.0 ? _first : 0;
        if (_child)
        {
            _unused = true;
            if (show)
            {
                _child->SetInt(0x1779, 1);
                if (queue && !alternate && !_visible)
                    ((VisibilityManager*)current)->visibilityQueue.AddTail(_child);
            }
            else
            {
                _child->SetInt(0x1779, 0);
            }
        }
        if (_second)
        {
            _found = true;
            if (!show)
                _second->SetInt(0x1779, 1);
            else
                _second->SetInt(0x1779, 0);
        }
        if (_child && ((VisibilityTile*)_child)->FUN_0056c7f0())
            ((VisibilityTile*)_child)
                ->FUN_0056c7f0()
                ->SetAppCulled(((VisibilityTile*)_child)->FUN_00a011b0(0xfa3) == 0.0 ||
                               ((VisibilityTile*)_child)->FUN_00a011b0(0x1779) == 0.0);
        if (_second && ((VisibilityTile*)_second)->FUN_0056c7f0())
            ((VisibilityTile*)_second)
                ->FUN_0056c7f0()
                ->SetAppCulled(show || ((VisibilityTile*)_second)->FUN_00a011b0(0xfa3) == 0.0 ||
                               ((VisibilityTile*)_second)->FUN_00a011b0(0x1779) == 0.0);
    }
    if (tile->FUN_0056c7f0())
        tile->FUN_0056c7f0()->SetAppCulled(tile->FUN_00a011b0(0xfa3) == 0.0 || tile->FUN_00a011b0(0x1779) == 0.0);
}

struct NiNodeCull
{
    void SetAppCulled(bool abCulled);
};

struct TileChildList : NiTPointerList_Tile___
{
    void* GetHeadPos();
    Tile*& GetNext(void*& rkPos);
};

struct TileEx : Tile
{
    Tile* GetChildById(int aiID);
    NiNodeCull* GetNode();
};

struct IMMenuOpen : InterfaceManager
{
    bool FUN_009373f0();
};

// If the menu is open, walks the root tile's children and culls each tile's node when its float at 0xfa3 or 0x1779 is zero.
// @fnv 0x00702dd0
void UpdateMenuTileVisibility()
{
    if (FUN_004b7210() && static_cast<IMMenuOpen*>(FUN_004b7210())->FUN_009373f0())
    {
        Tile* pRoot4 = FUN_004b7210()->FUN_00586150();
        void* pPosVal = static_cast<TileChildList*>(&pRoot4->m_kChildTileList)->GetHeadPos();
        while (pPosVal)
        {
            TileEx* pTile2 =
                static_cast<TileEx*>(static_cast<TileChildList*>(&pRoot4->m_kChildTileList)->GetNext(pPosVal));
            TileEx* pChildA2 = static_cast<TileEx*>(pTile2->GetChildById(0x6e));
            TileEx* pChildB5 = static_cast<TileEx*>(pTile2->GetChildById(0x6f));
            pTile2->SetInt(0x1779, 1);
            if (pChildA2)
                pChildA2->SetInt(0x1779, 1);
            if (pChildB5)
                pChildB5->SetInt(0x1779, 1);
            if (pTile2->GetNode())
                pTile2->GetNode()->SetAppCulled(pTile2->GetFloat(0xfa3) == 0.0 || pTile2->GetFloat(0x1779) == 0.0);
            if (pChildA2 && pChildA2->GetNode())
                pChildA2->GetNode()->SetAppCulled(pChildA2->GetFloat(0xfa3) == 0.0 ||
                                                  pChildA2->GetFloat(0x1779) == 0.0);
            if (pChildB5 && pChildB5->GetNode())
                pChildB5->GetNode()->SetAppCulled(pChildB5->GetFloat(0xfa3) == 0.0 ||
                                                  pChildB5->GetFloat(0x1779) == 0.0);
        }
    }
}

// If FUN_004b7210 returns non-null and its FUN_009373f0 check passes, flips the byte at offset 0xdd of its padding field between 0 and 1.
// @fnv 0x00703100
void __cdecl FUN_00703100()
{
    if (FUN_004b7210() != 0)
    {
        if (((FUN_009373f0_shell*)FUN_004b7210())->FUN_009373f0())
        {
            ((unsigned char*)FUN_004b7210()->padding)[0xdd] = ((unsigned char*)FUN_004b7210()->padding)[0xdd] ? 0 : 1;
        }
    }
}

extern "C" void __fastcall FUN_00717600(InterfaceManager*);
extern "C" void __cdecl UpdatePipboyMapVisibility(int, int);
extern "C" void __cdecl FUN_007048f0(int, int, int);
extern "C" void __cdecl ShowStatsMenu(int, int);

// @fnv 0x00703500
void __cdecl HandleMenuKeyInput(void)
{
    if (FUN_004b7210() != 0)
    {
        if (((InterfaceManagerPC*)FUN_004b7210())->GetKey())
        {
            InterfaceManager* iMenu = FUN_004b7210();
            int pManager = (int)iMenu->FUN_00586150()->GetFloat(0x1771);
            if (pManager == 0)
            {
                FUN_00717600(FUN_004b7210());
                pManager = 0x3eb;
            }
            switch (pManager)
            {
            case 0x3ff:
                UpdatePipboyMapVisibility(1, 0);
                break;
            case 0x3ea:
            case 0x40b:
            case 0x425:
                FUN_007048f0(1, 0, 1);
                break;
            case 0x3eb:
                ShowStatsMenu(1, 0);
                break;
            }
        }
    }
}

bool __cdecl QueueMessage(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a10, va_list* args, int enabled,
                          int left, int right, float zero, float x, float y);

// @fnv 0x00703f10
bool __cdecl FUN_00703f10(int a1, int a2, int a3, int a4, int a5, int a6, int a7, float x, float y, int a10, ...)
{
    if (FUN_004b7210() && ((FUN_009373f0_shell*)FUN_004b7210())->FUN_009373f0())
    {
        bool result5;
        va_list args;
        va_start(args, a10);
        result5 = QueueMessage(a1, a2, a3, a4, a5, a6, a7, a10, &args, 1, -1, -1, 0.0f, x, y);
        va_end(args);
        return result5;
    }
    return false;
}

#include <stdarg.h>
struct HWND__;
struct WinPoint
{
    long x, y;
};
struct WinMessage
{
    HWND__* hwnd;
    unsigned int message, wParam;
    long lParam;
    unsigned int time;
    WinPoint pt;
};
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(WinMessage*, HWND__*, unsigned int, unsigned int,
                                                            unsigned int);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const WinMessage*);
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const WinMessage*);

struct InterfaceControl
{
    void FUN_007010e0(bool, bool);
};
extern Interface* DAT_011d8804;
bool __cdecl QueueMessage(const char*, int, int, int, void (*)(), int, int, int, va_list*, bool, int, int, float, float,
                          float);
void __cdecl FUN_00403d30(void*, int, unsigned int);
class InputManager
{
  public:
    void FUN_00a23010();
};
class OSGlobals
{
  public:
    InputManager* FUN_00877720();
};
extern OSGlobals* g_osGlobals;
void FUN_007027e0();
void FUN_00702810();
void FUN_00702840();
void RenderOrFallback(int, int);
void FUN_00702960();
// @fnv 0x00704010
char __cdecl FUN_00704010(const char* text, int aiArg1, int aiArg2, int aiArg3, ...)
{
    DAT_0119f349 = -1;
    bool success = false;
    ((InterfaceControl*)DAT_011d8804)->FUN_007010e0(true, true);
    if (FUN_004b7210() && ((FUN_009373f0_shell*)FUN_004b7210())->FUN_009373f0())
    {
        va_list args;
        va_start(args, aiArg3);
        success =
            QueueMessage(text, 0, 0, 0, FUN_00704130, aiArg1, aiArg2, aiArg3, &args, true, -1, -1, 0.0f, 0.0f, 0.0f);
        va_end(args);
    }
    if (success)
    {
        while (DAT_0119f349 == -1)
        {
            WinMessage message;
            FUN_00403d30(&message, 0, sizeof(message));
            while (PeekMessageA(&message, 0, 0, 0, 1))
            {
                TranslateMessage(&message);
                DispatchMessageA(&message);
            }
            g_osGlobals->FUN_00877720()->FUN_00a23010();
            FUN_007027e0();
            FUN_00702810();
            FUN_00702840();
            RenderOrFallback(0, 0);
            FUN_00702960();
        }
        return DAT_0119f349;
    }
    return 0;
}

struct MenuProxy
{
    void FUN_00a1d910();
    void InitializeStatsMenu();
    void FUN_00a1db20();
};
struct TileProxy
{
    MenuProxy* FUN_00a03c90();
};
TileProxy* FUN_00a09030(int);
TileProxy* FUN_00704be0();
void ResetRepairMenu();
void ResetItemModMenu();
void PlayPipboyPageSound(bool);
struct PipProxy
{
    void FUN_007f8a80();
    void FUN_007fa010(unsigned int);
    bool IsUnk28Set();
};
struct InterfaceProxy
{
    PipProxy* FUN_00704370();
};
// Shows or hides the stats menu and its related tiles, updating the Pip-Boy interface when shown.
// @fnv 0x00704c10
void ShowStatsMenu(bool show, bool fades)
{
    if (FUN_004b7210() && ((FUN_009373f0_shell*)FUN_004b7210())->FUN_009373f0())
    {
        TileProxy* stats = FUN_00a09030(1003);
        TileProxy* inv = FUN_00a09030(1002);
        TileProxy* repair2 = FUN_00a09030(1035);
        TileProxy* barterX = FUN_00a09030(1061);
        TileProxy* map3 = FUN_00a09030(1023);
        bool visible2 = FUN_00702680(Interface::eStatsMenu, fades ? 11 : 0);
        if (show && !visible2)
        {
            if (inv)
                inv->FUN_00a03c90()->FUN_00a1d910();
            if (repair2)
            {
                repair2->FUN_00a03c90()->FUN_00a1d910();
                ResetRepairMenu();
            }
            if (barterX)
            {
                barterX->FUN_00a03c90()->FUN_00a1d910();
                ResetItemModMenu();
            }
            if (map3)
                map3->FUN_00a03c90()->FUN_00a1d910();
            if (!stats)
                stats = FUN_00704be0();
            if (stats)
            {
                FUN_004b7210()->FUN_00586150()->SetInt(6001, 1003);
                stats->FUN_00a03c90()->InitializeStatsMenu();
                stats->FUN_00a03c90()->FUN_00a1db20();
            }
        }
        else if (!show && visible2)
        {
            if (stats)
                stats->FUN_00a03c90()->FUN_00a1d910();
        }
        if (show)
        {
            ((InterfaceProxy*)FUN_004b7210())->FUN_00704370()->FUN_007f8a80();
            ((InterfaceProxy*)FUN_004b7210())->FUN_00704370()->FUN_007fa010(1);
            if (((InterfaceProxy*)FUN_004b7210())->FUN_00704370()->IsUnk28Set())
                PlayPipboyPageSound(false);
        }
    }
}

struct DecompScopeGuard
{
    int m_00;
    DecompScopeGuard(int a, int b, const char* file, int line);
    ~DecompScopeGuard();
};

struct DecompArg12
{
    int m_00;
    int m_04;
    int m_08;
    DecompArg12(const DecompArg12& src);
    ~DecompArg12();
};

struct DecompVec3
{
    int m_00;
    int m_04;
    int m_08;
};

struct DecompTarget
{
    void FUN_00774fd0(int a1, DecompArg12 a2, DecompVec3 a3, int a4, bool a5);
};

extern unsigned int DAT_011d96c0;

// If the interface manager and its shell are available and DAT_011d96c0 is set, forwards the arguments to FUN_00774fd0 on DAT_011d96c0; always returns false.
// @fnv 0x00705210
bool __cdecl FUN_00705210(int aiArg1, DecompArg12 aArg12, DecompVec3 aVec3, int aiArg4, bool a5)
{
    DecompScopeGuard guard(13, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Interface.cpp", 0x8ec);
    if (FUN_004b7210() && ((FUN_009373f0_shell*)FUN_004b7210())->FUN_009373f0() && DAT_011d96c0)
    {
        ((DecompTarget*)DAT_011d96c0)->FUN_00774fd0(aiArg1, aArg12, aVec3, aiArg4, a5);
    }
    return false;
}

struct FUN_0047ee30_shell : public InterfaceManager
{
    char GetAssistance();
};

// If FUN_004b7210 returns a non-null object whose FUN_009373f0 is true, returns its GetAssistance result; otherwise returns -1.
// @fnv 0x00705c70
extern "C" char __cdecl GetInterfaceManagerResult()
{
    if (FUN_004b7210() && reinterpret_cast<FUN_009373f0_shell*>(FUN_004b7210())->FUN_009373f0())
    {
        return reinterpret_cast<FUN_0047ee30_shell*>(FUN_004b7210())->GetAssistance();
    }
    return -1;
}

struct FloatValue
{
    float GetFloat();
};
struct Data
{
    int GetLength();
    void GetData(char*);
};
struct Root : InterfaceManager
{
    Data data;
    FloatValue* GetValue(int);
};
struct Buffer
{
    void SaveData(void*, unsigned, int);
};
char GetStatsMenuPage();
unsigned char FUN_007824b0();
float GetMapMenuFloatSetting();
float GetTileFloatOrDefault();
void FUN_00403d30(void*, int, unsigned);
// @fnv 0x007066d0
void FUN_007066d0(Buffer* buffer)
{
    char y[100];
    float text;
    int length = (int)((Root*)FUN_004b7210())->GetValue(0x1771)->GetFloat();
    char third = GetStatsMenuPage();
    unsigned char x = FUN_007824b0();
    char value = FUN_00706830();
    buffer->SaveData(&length, 4, 0);
    buffer->SaveData(&third, 1, 0);
    buffer->SaveData(&x, 1, 0);
    buffer->SaveData(&value, 1, 0);
    float first = GetMapMenuFloatSetting();
    text = GetTileFloatOrDefault();
    buffer->SaveData(&first, 4, 0);
    buffer->SaveData(&text, 4, 0);
    FUN_00403d30(y, 0, 100);
    int second = ((Root*)FUN_004b7210())->data.GetLength();
    ((Root*)FUN_004b7210())->data.GetData(y);
    buffer->SaveData(&second, 4, 0);
    buffer->SaveData(y, second, 0);
}

struct FUN_00703960_Class
{
    void __thiscall SetByteAtOffsetEC(char param);
};

// @fnv 0x00706db0
void FUN_00706db0(unsigned char ucValue)
{
    ((FUN_00703960_Class*)FUN_004b7210())->SetByteAtOffsetEC((char)ucValue);
}

class TESForm;
class TESGlobal;
class Setting;

struct FUN_00401170_s
{
    int FUN_00401170();
};

class TESGlobal : public TESForm
{
  public:
    char FUN_00529ea0();
    float GetValue();
};

class Setting
{
  public:
    const char* String();
};

extern Setting* DAT_0119b354[];
extern Setting* DAT_0119b35c[];
extern Setting* DAT_0119b364[];

struct Player_StandIn : public PlayerCharacter
{
    const char* GetFullName();
    const char* FUN_0087f6c0();
    int GetSex();
};

int __cdecl FindSettingIndex(const char* apName);
void __cdecl GetControlLabel(int a1, char* a2, bool a3);
bool __cdecl ResolveSettingString(const char* a1, char* a2);
TESForm* __cdecl FUN_00483a00(const char* apName);

int __cdecl sprintf_s(char* apBuffer, unsigned int auiBufferSize, const char* apFormat, ...);
int __cdecl strcpy_s(char* apDest, unsigned int auiDestSize, const char* apSrc);
int __cdecl _stricmp(const char* apStr1, const char* apStr2);

// @fnv 0x007070c0
bool __cdecl FUN_007070c0(const char* apName, char* apBuffer, unsigned int auiBufferSize, bool abArg4)
{
    bool bFound = false;
    if (apName && *apName && apBuffer && auiBufferSize)
    {
        int iSettingIndex = FindSettingIndex(apName);
        if (iSettingIndex < 28)
        {
            GetControlLabel(iSettingIndex, apBuffer, abArg4);
            bFound = true;
        }
        if (!bFound)
        {
            TESForm* pForm = FUN_00483a00(apName);
            if (pForm && ((FUN_00401170_s*)pForm)->FUN_00401170() == 6)
            {
                TESGlobal* pGlobalForm = (TESGlobal*)pForm;
                if (pGlobalForm->FUN_00529ea0() == 'f')
                {
                    sprintf_s(apBuffer, auiBufferSize, "%.2f", pGlobalForm->GetValue());
                }
                else
                {
                    sprintf_s(apBuffer, auiBufferSize, "%i", (int)pGlobalForm->GetValue());
                }
                bFound = true;
            }
        }
        if (!bFound && _stricmp(apName, "PCName") == 0)
        {
            strcpy_s(apBuffer, auiBufferSize, ((Player_StandIn*)g_thePlayer)->GetFullName());
            bFound = true;
        }
        if (!bFound && _stricmp(apName, "PCRace") == 0)
        {
            strcpy_s(apBuffer, auiBufferSize, ((Player_StandIn*)g_thePlayer)->FUN_0087f6c0());
            bFound = true;
        }
        if (!bFound && _stricmp(apName, "PCSex") == 0)
        {
            strcpy_s(apBuffer, auiBufferSize, DAT_0119b354[((Player_StandIn*)g_thePlayer)->GetSex()]->String());
            bFound = true;
        }
        if (!bFound && _stricmp(apName, "PCSexPronoun") == 0)
        {
            strcpy_s(apBuffer, auiBufferSize, DAT_0119b364[((Player_StandIn*)g_thePlayer)->GetSex()]->String());
            bFound = true;
        }
        if (!bFound && _stricmp(apName, "PCSexPossessive") == 0)
        {
            strcpy_s(apBuffer, auiBufferSize, DAT_0119b35c[((Player_StandIn*)g_thePlayer)->GetSex()]->String());
            bFound = true;
        }
        if (!bFound)
        {
            bFound = ResolveSettingString(apName, apBuffer);
        }
    }
    return bFound;
}

class NiStream
{
  public:
    virtual ~NiStream();
    char fileName[260];
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    bool FUN_00c3a8a0(const char*, bool);
};
class BSStream : public NiStream
{
  public:
    BSStream();
    virtual ~BSStream();
};
class Model
{
  public:
    unsigned int unk00, unk04, unk08, unk0C;
    Model(const char*, BSStream*, bool, bool);
    NiNode* GetObject3D();
};
struct Loader_S
{
    NiNode* LoadModel(const char*, int, bool, bool, bool, bool);
};
extern bool DAT_011d8908;
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
// Clears the flag, then loads a model from path via the model loader or a BSStream and returns its NiNode, or null on failure.
// @fnv 0x00707660
NiNode* FUN_00707660(const char* path, bool* flag)
{
    *flag = false;
    if (g_modelLoader && !DAT_011d8908)
    {
        *flag = true;
        return ((Loader_S*)g_modelLoader)->LoadModel(path, 0, true, false, false, false);
    }
    else if (FileFinder::Exist(path, 0, 0, -1))
    {
        BSStream stream;
        if (stream.FUN_00c3a8a0(path, false))
        {
            S_004431f0* previous = DAT_011d890c;
            S_004431f0* old = previous;
            old ? old->FUN_004431f0(1) : 0;
            DAT_011d890c = (S_004431f0*)new Model(path, &stream, true, false);
            return ((Model*)DAT_011d890c)->GetObject3D();
        }
    }
    return 0;
}

class B7AB690FullName
{
  public:
    const char* GetName() const;
};

class TESNPC : public TESBoundObject
{
  public:
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
    B7AB690FullName m_kFullName;
};

class B7AB690Player
{
  public:
    TESBoundObject* GetObjectReference();
};

class B7AB690SettingString
{
  public:
    const char* GetString();
};

extern B7AB690Player* g_pkB7AB690Player;
extern B7AB690SettingString g_kB7AB690NamePrompt;

void __cdecl FUN_007ab7c0();
void __cdecl B7AB690ShowTextEntry(const char* pcPrompt, const char* pcDefault, void(__cdecl* pfnCallback)(const char*));
void __cdecl B7AB690OnNameEntered(const char* pcName);

class B7AB690Menu
{
  public:
    B7AB690Menu();
    virtual ~B7AB690Menu();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class FUN_007ab690_cls : public B7AB690Menu
{
  public:
    FUN_007ab690_cls();
    virtual ~FUN_007ab690_cls();

    void Finish(const char* pcName);

    TESNPC* m_pkNPC;
};

// Stores the player's TESNPC reference, then shows the name text entry prompt with the NPC's current full name, or calls Finish(0) if there is no NPC.
// @fnv 0x007ab690
FUN_007ab690_cls::FUN_007ab690_cls()
{
    m_pkNPC = g_pkB7AB690Player ? dynamic_cast<TESNPC*>(g_pkB7AB690Player->GetObjectReference()) : 0;
    if (m_pkNPC)
    {
        FUN_007ab7c0();
        B7AB690ShowTextEntry(g_kB7AB690NamePrompt.GetString(), m_pkNPC->m_kFullName.GetName(), B7AB690OnNameEntered);
    }
    else
    {
        Finish(0);
    }
}

namespace fnv_008d66b0 {
#include <string.h>
#include <stdio.h>

struct WobbleName : NiFixedString
{
    WobbleName(const char*);
    ~WobbleName();
    operator const char*() const;
};
struct WobbleNode : NiNode
{
    WobbleName& GetName();
    void SetName(const WobbleName&);
};
struct WobbleLoader : ModelLoader
{
    WobbleNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
struct FileFinder
{
    static int Exist(const char*, char*, unsigned int, unsigned int);
};
extern WobbleNode* DAT_011e0110[];
extern char* DAT_011e00e0[];
extern bool DAT_01185520;
extern const char* DAT_011977a4[];
unsigned int BSStringLength(const char*);
int FUN_00406d30(char*, unsigned int, const char*);
// Loads up to 12 weapon wobble NIF models from Meshes\Characters\WeaponWobbles, storing each node and a copy of its name, then sets DAT_01185520 to true.
// @fnv 0x008d66b0
void LoadWeaponWobbleModels()
{
    memset(DAT_011e0110, 0, 12);
    memset(DAT_011e00e0, 0, 12);
    DAT_01185520 = false;
    char path[260];
    for (int i = 0; i < 12; i++)
    {
        if (i == 0)
            sprintf_s(path, 260, "%s\\Characters\\WeaponWobbles\\ScopeWobble.nif", "Meshes");
        else
            sprintf_s(path, 260, "%s\\Characters\\WeaponWobbles\\%s.nif", "Meshes", DAT_011977a4[i]);
        if (FileFinder::Exist(path, 0, 6, 1))
        {
            DAT_011e0110[i] = static_cast<WobbleLoader*>(g_modelLoader)->LoadFile(path, 0, true, false, false, false);
            unsigned int length = BSStringLength(DAT_011e0110[i]->GetName()) + 1;
            DAT_011e00e0[i] = new char[length];
            FUN_00406d30(DAT_011e00e0[i], length, DAT_011e0110[i]->GetName());
            DAT_011e0110[i]->SetName(WobbleName(path));
        }
    }
    DAT_01185520 = true;
}
}  // namespace fnv_008d66b0

struct InterfaceManagerPCMine : InterfaceManager
{
    bool GetKey();
};

struct TESObjectREFRMine : TESObjectREFR
{
    TESForm* GetOwner();
    bool CanBeUsed(Actor* apActor, bool abUnk);
};

int FUN_0075b310(TESObjectREFR* apRef, int aType);

// If the interface manager key is held, adjusts aType to 2 for owned non-actor refs that cannot be used, then calls FUN_0075b310; otherwise returns 0.
// @fnv 0x00704ed0
int FUN_00704ed0(TESObjectREFR* apRef, int aType)
{
    if (FUN_004b7210() && ((InterfaceManagerPCMine*)FUN_004b7210())->GetKey())
    {
        if (aType == 1)
        {
            if (!((TESObjectREFRMine*)apRef)->IsActor() && ((TESObjectREFRMine*)apRef)->GetOwner() &&
                !((TESObjectREFRMine*)apRef)->CanBeUsed(g_thePlayer, true))
            {
                aType = 2;
            }
        }
        return FUN_0075b310(apRef, aType);
    }
    return 0;
}

// @fnv 0x0040fbe0
void __cdecl FUN_0040fbe0()
{}

struct MgrQ
{
    bool FUN_009373f0();
    bool FUN_00644640();
};
// Returns the result of MgrQ::FUN_00644640 when FUN_004b7210 is non-null and MgrQ::FUN_009373f0 is true, otherwise false.
// @fnv 0x00702fc0
bool FUN_00702fc0()
{
    if (FUN_004b7210() && ((MgrQ*)FUN_004b7210())->FUN_009373f0())
        return ((MgrQ*)FUN_004b7210())->FUN_00644640();
    return false;
}

namespace sleep704 {
struct M70Tile
{
    void FUN_00a1d910();
    void FUN_00a1db20();
};
struct M70Menu
{
    M70Tile* FUN_00a03c90();
};
struct M70Trait
{
    void FUN_00700320(int id, int value);
};
struct M70Hud
{
    void FUN_007f8a80();
    void FUN_007fa010(int a);
    bool IsUnk28Set();
};
struct M70Player
{
    bool FUN_009373f0();
    M70Trait* FUN_00586150();
    M70Hud* FUN_00704370();
};
M70Player* FUN_004b7210();
M70Menu* FUN_00a09030(int id);
bool FUN_00702680(int id, int a);
M70Menu* CreateInventoryMenuIfModifierKey();
void FUN_00704390();
void ResetRepairMenu();
void ResetItemModMenu();
void FUN_00782a90();
void FUN_00782470(int a);
void UpdateCurrentValue();

// Shows or hides the inventory menu, closing related menus and resetting HUD state as needed.
// @fnv 0x007048f0
void FUN_007048f0(bool show, bool fade, bool reset)
{
    M70Menu* pMenu3eb;
    M70Menu* pMenu3ea;
    M70Menu* pMenu40bB;
    M70Menu* aPMenu425;
    M70Menu* pMenu3ff8;
    bool bOpen;

    if (FUN_004b7210() && FUN_004b7210()->FUN_009373f0())
    {
        pMenu3eb = FUN_00a09030(0x3eb);
        pMenu3ea = FUN_00a09030(0x3ea);
        pMenu40bB = FUN_00a09030(0x40b);
        aPMenu425 = FUN_00a09030(0x425);
        pMenu3ff8 = FUN_00a09030(0x3ff);
        bOpen = FUN_00702680(0x3ea, fade ? 0xb : 0);
        if (show)
        {
            if (!pMenu3ea)
            {
                pMenu3ea = CreateInventoryMenuIfModifierKey();
            }
            if (!bOpen)
            {
                if (pMenu3eb)
                {
                    pMenu3eb->FUN_00a03c90()->FUN_00a1d910();
                    FUN_00704390();
                }
                if (pMenu3ff8)
                {
                    pMenu3ff8->FUN_00a03c90()->FUN_00a1d910();
                }
                if (pMenu40bB)
                {
                    pMenu40bB->FUN_00a03c90()->FUN_00a1d910();
                    ResetRepairMenu();
                }
                if (aPMenu425)
                {
                    aPMenu425->FUN_00a03c90()->FUN_00a1d910();
                    ResetItemModMenu();
                }
                if (pMenu3ea)
                {
                    pMenu3ea->FUN_00a03c90()->FUN_00a1db20();
                }
            }
            if (pMenu3ea)
            {
                FUN_00782a90();
                FUN_004b7210()->FUN_00586150()->FUN_00700320(0x1771, 0x3ea);
            }
            if (reset)
            {
                FUN_004b7210()->FUN_00704370()->FUN_007f8a80();
                FUN_004b7210()->FUN_00704370()->FUN_007fa010(2);
            }
            if (FUN_004b7210()->FUN_00704370()->IsUnk28Set())
            {
                FUN_00782470(0);
            }
        }
        else if (!show && bOpen && pMenu3ea)
        {
            pMenu3ea->FUN_00a03c90()->FUN_00a1d910();
            UpdateCurrentValue();
        }
    }
}
}

struct BaseMenu
{
    BaseMenu();
    ~BaseMenu();
    virtual void vfunc();
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
};

struct RenderedPoint
{
    RenderedPoint();
    float x;
    float y;
    float z;
};

struct NodeHandle
{
    NodeHandle(int);
};

struct FUN_00705fe0 : BaseMenu
{
    RenderedPoint pt;
    NodeHandle node;

    FUN_00705fe0();
};

// Constructs a FUN_00705fe0 object, initializing its node member to 0.
// @fnv 0x00705fe0
FUN_00705fe0::FUN_00705fe0() : node(0)
{}

struct FUN_00709930
{
    virtual ~FUN_00709930();
};
// Destructor for FUN_00709930; performs no additional cleanup beyond the default body.
// @fnv 0x00709930
FUN_00709930::~FUN_00709930()
{}

// Candidate for FUN_0079ffb0 (claim clm_f5183b6336444303ae13, 0x0079ffb0, 5190 bytes)
// World-map tile mesh build / screenshot dump; param_1 != 0 selects the dump path.
// Builds on the packet's best prior attempt; corrected constructors, calls and local layout.
// Packet flags: /MT /Od /Oy- /GS /EHsc /Gy /GF. Entry ABI: __cdecl, caller pops.

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);

namespace points {
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
    FUN_006815c0(float, float, float);
    void FUN_0063c8a0(const FUN_006815c0*);
};
}
typedef points::FUN_006815c0 NiPt3;
namespace uvs {
struct FUN_006815c0
{
    float u, v;
    FUN_006815c0();
    FUN_006815c0(float, float);
};
}
typedef uvs::FUN_006815c0 NiPt2;
struct FUN_004a7800
{
    float r, g, b, a;
    FUN_004a7800();
    FUN_004a7800(float, float, float, float);
};
typedef FUN_004a7800 NiCol;

// object reached from DAT_011dea3c through virtual slot 0x1f4 (index 125, __thiscall)
struct C125
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
    virtual void* v125();
};

// object with virtual name accessor at slot 0x130 (index 76, __thiscall)
struct C76a
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
    virtual unsigned int v076();
};
struct C76b
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
    virtual unsigned int v076(int, int);
};
struct C76c
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
    virtual unsigned int v076(int);
};

// object with virtual slot 0xdc (index 55, __thiscall, callee pops 8)
struct C55
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
    virtual void v055(void*, int);
};

// object with virtual slot 0x9c (index 39, __thiscall, callee pops 4)
struct C39
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
    virtual unsigned int v039(int);
};

// chain objects reached through DAT_011dea3c members
struct Local12;
struct Mesh34;
struct V3Maker;
struct ChainObj
{
    void FUN_00a59c60(V3Maker*);
    ChainObj* FUN_00586170();
    ChainObj* FUN_0043b230();
    bool FUN_00456610();
    void FUN_00450f90(bool);
    void* FUN_005875a0(int, int);
    void FUN_00555bc0();
    void FUN_004a0370();
    void FUN_004a03c0();
    void FUN_00555b10(NiPt3*, NiPt3*, int);
    void FUN_00556ef0(int, int, int);
    void FUN_0054e640(Local12*);
    void FUN_0054e750(int, int, Local12*);
    void CollectCellReferences(unsigned int*);
    unsigned int FUN_0059bb30();
};
struct Mesh34
{
    void FUN_00439410(void*);
    void FUN_00a5a040();
    void FUN_004bc1f0(float, float, float);
};
struct ObjD_11dea3c
{
    bool FUN_00575d10();
    void* FUN_00575d70();
    void* FUN_008d6f30();
};

// path-name providers on the object at DAT_011dea10
struct PathSrc
{
    void* FUN_005f36f0();
    void* FUN_004fd3e0();
};

// object at [[DAT_011da368]+0x30]
struct Tile30
{
    unsigned int FUN_0056c7f0();
    void FUN_007a1400(int);
    void FUN_00a07530(int);
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, int);
};

// small local-object stand-ins (methods invoked with ecx = local)
struct V3Maker
{
    float x, y, z;
    NiPt3& FUN_00416870(float x, float y, float z);
    NiPt2& FUN_00452dc0(float u, float v);
    NiCol& FUN_00414430(float a, float b, float c, float d);
    void FUN_0043d410(float a, int b, int c);
    void FUN_0063c8a0(NiPt3* p);
};
struct ColorMaker
{
    float r, g, b, a;
    NiCol& FUN_00414430(float, float, float, float);
};
struct UvMaker
{
    float u, v;
    NiPt2& FUN_00452dc0(float, float);
};
struct Obj16
{
    struct FloatColor
    {
        float r, g, b, a;
    } c;
    Obj16(float, float, float, float);
};
struct Local12
{
    unsigned int value;
    Local12(int);
    ~Local12();
    unsigned int FUN_00559450();
    void FUN_0066b0d0(int);
};

// mesh/material stand-ins
struct ObjD4
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjD4(unsigned short, void*, void*, void*, void*, int, int, unsigned int, void*, int, int, int, int);
};
struct ObjB0
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    ObjB0(bool);
    void FUN_00bb7a10(unsigned int);
    void FUN_008cc6d0(int);
    void SetNavMeshInfo(Obj16*);
    void SetFlag(int);
};
struct Obj1C
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Obj1C();
    void FUN_00439340(int);
    void FUN_00439390(int);
    void FUN_0049ed90(int);
};

// map-menu state global, fields at their offsets
struct MapMenuR6
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
    void* tile_30;
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
    unsigned int field_84;
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
    unsigned int field_e0;
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
    unsigned int field_128;
    unsigned char field_12c;
    void UpdateLocalMap();
};

int __cdecl FUN_00556870(V3Maker*);
// free helpers; conventions read from add esp evidence
extern "C" void* __cdecl FormHeap_Allocate(unsigned int);
extern "C" void __stdcall FUN_00401050(void*, unsigned int, unsigned int, void*);
extern "C" void* __cdecl FUN_00aa1070(unsigned int);
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern "C" void __cdecl FUN_006815c0();
extern "C" void __cdecl FUN_004a7800();
extern "C" int __cdecl FUN_00406d90(float);
extern "C" void __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
extern "C" void __stdcall FUN_00ee6dc2(char*, int, unsigned int);
extern "C" bool __cdecl FUN_007a1750();
extern "C" void* __cdecl FUN_007a1480();
extern "C" void* __cdecl FUN_00653270(unsigned int, unsigned int);
extern "C" void __cdecl FUN_00b57e30(void*, int, int);
extern "C" float __cdecl ScreenWidth();
extern "C" float __cdecl ScreenHeight();
extern "C" void* __cdecl FUN_00ec62c0();
extern "C" float __cdecl FUN_00879d90();
struct ColorSource
{
    void ReadColor(int, Obj16*);
};
extern "C" ColorSource* __cdecl ColorSingleton();
extern "C" void __fastcall FUN_00719060(void*); /* ecx = FUN_00718b60 result */
extern "C" void __fastcall FUN_00a59c60(void*); /* ecx = FUN_0056c7f0 result */
struct GObj
{
    int* FUN_0043d4d0();
};
extern GObj DAT_011c63cc; /* object at 0x11c63cc */

// globals read/written here
struct Position
{
    float x, y, z;
};
extern Position DAT_011f426c;
struct RenderColor
{
    unsigned int r, g, b, a;
};
extern RenderColor DAT_011ff3a8;
extern RenderColor DAT_011a9bd0;
extern unsigned char DAT_011ff103;
extern double DBL_01020758;
extern double DBL_01011590;
extern double DBL_0101db80;
extern double DBL_0101e568;
extern float FLT_0101e570;
extern char DAT_01075520[];
extern char DAT_01075508[];
extern char DAT_010754f0[];
extern char DAT_010754d4[];
extern char DAT_010754ac[];
extern char DAT_01075490[];
extern char DAT_01075468[];
extern unsigned int DAT_011f4418;

// Builds and attaches a map mesh; when param_1 is set, it builds a path and passes it with collected references to another function.
// @fnv 0x0079ffb0
void __cdecl FUN_0079ffb0(char param_1)
{
    RenderColor savedColor1;
    int size27;
    int totalSize40;
    bool bWide9;
    Position base9c33;
    short* pIdx11;
    V3Maker mk8c26;
    int step17;
    int m23;
    int m10;
    bool cFlag7151;
    void* pvT32;
    void* pvC52;
    Position pos15;
    void* pSub10;
    ChainObj* pMenu25;
    bool cMenuOk4;
    ObjB0* pFx44;
    Obj1C* pFx221;
    int gridSize13;
    int cellY10;
    void* pvV17;
    int totalCells21;
    int idx19;
    Mesh34* pMesh14;
    unsigned char svByte10316;
    float fStep27;
    int n25;
    int j17;
    int i17;
    int n2;
    int cellX17;

    if (DAT_011da368 == 0 ||
        static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_0056c7f0() == 0 ||
        !FUN_007a1750())
        return;

    pos15 = *static_cast<Position*>(reinterpret_cast<C125*>(DAT_011dea3c)->v125());
    pos15.z += DBL_01020758;

    /* world size: 0x800 when flagged, else 0x400 */
    bWide9 = reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d10() != 0;
    size27 = bWide9 ? 0x800 : 0x400;

    n2 = 0x10;
    n25 = n2 * n2;
    step17 = size27 / n2;
    m10 = 0x11;
    m23 = m10 * m10;

    gridSize13 = *DAT_011c63cc.FUN_0043d4d0();
    totalCells21 = gridSize13 * gridSize13;
    totalSize40 = size27 * gridSize13;
    fStep27 = FUN_00879d90();

    /* save render state, install defaults */
    savedColor1 = DAT_011ff3a8;
    DAT_011ff3a8 = DAT_011a9bd0;
    svByte10316 = DAT_011ff103;
    DAT_011ff103 = 1;

    Obj16 objB83(0.0f, 0.0f, 0.0f, 0.0f);
    ColorSingleton()->ReadColor(4, &objB83);
    cFlag7151 = 1;
    if (reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70() != 0)
    {
        if (static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70())
                ->FUN_00586170()
                ->FUN_0043b230() != 0)
        {
            cFlag7151 = static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70())
                            ->FUN_00586170()
                            ->FUN_0043b230()
                            ->FUN_00456610();
            static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70())
                ->FUN_00586170()
                ->FUN_0043b230()
                ->FUN_00450f90(1);
        }
    }

    pMenu25 = static_cast<ChainObj*>(FUN_007a1480());
    cMenuOk4 = pMenu25->FUN_00456610();
    if (cMenuOk4 == '\0')
        pMenu25->FUN_00450f90(1);

    cellX17 = reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_128 % *DAT_011c63cc.FUN_0043d4d0();
    cellY10 = reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_128 / *DAT_011c63cc.FUN_0043d4d0();

    Local12 local1415(0);
    pSub10 = 0;
    base9c33 = DAT_011f426c;

    if (reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d10())
    {
        pSub10 = reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_008d6f30();
        if (pSub10 != 0)
        {
            int insideTileX1;
            int ex62;
            int ey21;
            Position adj31 = pos15;
            static_cast<ChainObj*>(pSub10)->FUN_00555b10(reinterpret_cast<NiPt3*>(&pos15),
                                                         reinterpret_cast<NiPt3*>(&adj31), 1);
            ex62 = (FUN_00406d90(adj31.x) - 0x800) >> 0xc;
            ey21 = (FUN_00406d90(adj31.y) - 0x800) >> 0xc;
            insideTileX1 = ex62 + cellX17 - (gridSize13 >> 1);
            int insideTileY1 = ey21 + cellY10 - (gridSize13 >> 1);
            base9c33 =
                reinterpret_cast<const Position&>(NiPt3(static_cast<float>((insideTileX1 << 0xc) + 0x800),
                                                        static_cast<float>((insideTileY1 << 0xc) + 0x800), 0.0f));
            static_cast<ChainObj*>(pSub10)->FUN_00556ef0(insideTileX1, insideTileY1, 0);
            static_cast<ChainObj*>(static_cast<void*>(FUN_0043c4b0()))->FUN_004a0370();
            static_cast<ChainObj*>(pSub10)->FUN_0054e750(insideTileX1, insideTileY1, &local1415);
            static_cast<ChainObj*>(static_cast<void*>(FUN_0043c4b0()))->FUN_004a03c0();
            if (cellX17 == 0 && cellY10 == 0)
                static_cast<ChainObj*>(pSub10)->CollectCellReferences(
                    &reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_e0);
        }
    }
    else
    {
        int wx5;
        int outsideTileY1;
        int outsideTileX2;
        int wy1;
        void* pReg8 = reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70();
        wx5 = FUN_00406d90(pos15.x) >> 0xc;
        wy1 = FUN_00406d90(pos15.y) >> 0xc;
        outsideTileX2 = wx5 + cellX17 - (gridSize13 >> 1);
        outsideTileY1 = wy1 + cellY10 - (gridSize13 >> 1);
        base9c33 = reinterpret_cast<const Position&>(
            NiPt3(static_cast<float>(outsideTileX2 << 0xc), static_cast<float>(outsideTileY1 << 0xc), 0.0f));
        if (pReg8 != 0)
            pSub10 = static_cast<ChainObj*>(pReg8)->FUN_005875a0(outsideTileX2, outsideTileY1);
        if (pSub10 != 0)
        {
            static_cast<ChainObj*>(pSub10)->FUN_00555bc0();
            static_cast<ChainObj*>(static_cast<void*>(FUN_0043c4b0()))->FUN_004a0370();
            static_cast<ChainObj*>(pSub10)->FUN_0054e640(&local1415);
            static_cast<ChainObj*>(static_cast<void*>(FUN_0043c4b0()))->FUN_004a03c0();
            static_cast<ChainObj*>(pSub10)->CollectCellReferences(
                &reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_e0);
        }
    }

    if (static_cast<unsigned char>(param_1) != 0)
    {
        char pathB41[0x104];
        C39* p3925;
        char pathA25[0x104];
        /* dump current view into per-cell screenshot folders */
        CreateDirectoryA(DAT_01075520, 0);
        CreateDirectoryA(DAT_01075508, 0);
        CreateDirectoryA(DAT_010754f0, 0);
        if (reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0() != 0)
        {
            FUN_00406d00(pathA25, 0x104, DAT_010754d4,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0())->v076());
            CreateDirectoryA(pathA25, 0);
            FUN_00406d00(pathB41, 0x104, DAT_010754ac,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0())->v076(),
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_005f36f0())->v076(), cellX17,
                         cellY10);
        }
        else
        {
            FUN_00406d00(pathA25, 0x104, DAT_01075490,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_004fd3e0())->v076());
            CreateDirectoryA(pathA25, 0);
            FUN_00406d00(pathB41, 0x104, DAT_01075468,
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_004fd3e0())->v076(),
                         static_cast<C76a*>(reinterpret_cast<PathSrc*>(DAT_011dea10)->FUN_004fd3e0())->v076(),
                         (FUN_00406d90(pos15.x) >> 0xc) + cellX17, (FUN_00406d90(pos15.y) >> 0xc) + cellY10);
        }
        p3925 = static_cast<C39*>(FUN_00653270(reinterpret_cast<unsigned int>(&DAT_011f4418),
                                               reinterpret_cast<ChainObj*>(local1415.FUN_00559450())->FUN_0059bb30()));
        FUN_00ee6dc2(pathB41, 3, p3925->v039(0));
        reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_128 =
            reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_128 + 1;
        return;
    }

    /* build the tile mesh: vertices, normals, uvs, colours, indices */
    pvV17 = new NiPt3[m23];
    void* pvN31 = new NiPt3[m23];
    pvT32 = new NiPt2[m23];
    pvC52 = new NiCol[m23];
    pIdx11 = static_cast<short*>(FUN_00aa1070((n25 * 2) * 3 * 2));

    idx19 = 0;
    for (i17 = 0; i17 < m10; i17++)
    {
        for (j17 = 0; j17 < m10; j17++)
        {
            static_cast<NiPt3*>(pvV17)[idx19] =
                NiPt3(static_cast<float>(j17 * step17) - static_cast<float>(size27) / DBL_01011590, 0.0f,
                      static_cast<float>(i17 * step17) - static_cast<float>(size27) / DBL_01011590);
            idx19++;
        }
    }
    idx19 = 0;
    for (i17 = 0; i17 < m10; i17++)
    {
        for (j17 = 0; j17 < m10; j17++)
        {
            static_cast<NiPt3*>(pvN31)[idx19] = NiPt3(0.0f, 1.0f, 0.0f);
            static_cast<NiPt2*>(pvT32)[idx19] =
                NiPt2(static_cast<float>(j17) / m10, 1.0f - static_cast<float>(i17) / m10);
            NiPt3 mk324(static_cast<float>(j17) * fStep27, static_cast<float>(i17) * fStep27, 0.0f);
            mk324.FUN_0063c8a0(reinterpret_cast<NiPt3*>(&base9c33));
            float hgt = FLT_0101e570;
            if (reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_12c != 0)
                hgt = static_cast<float>(FUN_00556870(reinterpret_cast<V3Maker*>(&mk324)));
            static_cast<NiCol*>(pvC52)[idx19] = NiCol(1.0f, 1.0f, 1.0f, hgt / DBL_0101db80);
            idx19++;
        }
    }
    idx19 = 0;
    for (i17 = 0; i17 < n2; i17++)
    {
        for (j17 = 0; j17 < n2; j17++)
        {
            if ((i17 % 2) ^ (j17 % 2))
            {
                short sVertexIndex;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
            }
            else
            {
                short sVertexIndex;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>(i17 * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
                sVertexIndex = static_cast<short>((i17 + 1) * m10 + j17 + 1);
                pIdx11[idx19] = sVertexIndex;
                idx19++;
            }
        }
    }

    /* create mesh + fx objects, submit to renderer */
    pMesh14 = reinterpret_cast<Mesh34*>(new ObjD4(static_cast<unsigned short>(m23), pvV17, pvN31, pvC52, pvT32, 1, 0,
                                                  n25 << 1, pIdx11, 0, 0, (int)ScreenWidth(), (int)ScreenHeight()));
    pFx44 = new ObjB0(false);

    static_cast<ObjB0*>(pFx44)->FUN_00bb7a10(local1415.FUN_00559450());
    static_cast<ObjB0*>(pFx44)->FUN_008cc6d0(0);
    static_cast<ObjB0*>(pFx44)->SetNavMeshInfo(&objB83);
    static_cast<ObjB0*>(pFx44)->SetFlag(1);
    local1415.FUN_0066b0d0(0);
    pMesh14->FUN_00439410(pFx44);

    pFx221 = new Obj1C();
    static_cast<Obj1C*>(pFx221)->FUN_00439340(6);
    static_cast<Obj1C*>(pFx221)->FUN_00439390(0);
    static_cast<Obj1C*>(pFx221)->FUN_0049ed90(1);
    pMesh14->FUN_00439410(pFx221);
    FUN_00b57e30(pMesh14, 0, 0);
    pMesh14->FUN_004bc1f0(static_cast<float>(size27 * cellX17) + static_cast<float>(size27) / DBL_01011590, 0.0f,
                          static_cast<float>(size27 * cellY10) + static_cast<float>(size27) / DBL_01011590 -
                              totalSize40);
    pMesh14->FUN_00a5a040();

    static_cast<C55*>(reinterpret_cast<void*>(
                          static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_0056c7f0()))
        ->v055(pMesh14, 1);
    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_007a1400(0x20);

    DAT_011ff3a8 = savedColor1;
    DAT_011ff103 = svByte10316;

    if (cFlag7151 == '\0')
    {
        if (reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70() != 0)
            static_cast<ChainObj*>(reinterpret_cast<ObjD_11dea3c*>(DAT_011dea3c)->FUN_00575d70())
                ->FUN_00586170()
                ->FUN_0043b230()
                ->FUN_00450f90(cFlag7151);
    }
    if (cMenuOk4 == '\0')
        pMenu25->FUN_00450f90(0);

    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_00a07530(0x108);
    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_00700320(0xfcd, size27 * gridSize13);
    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_00700320(0xfce, size27 * gridSize13);
    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)
        ->FUN_00a012d0(0xfb2, objB83.c.r * DBL_0101e568, 1);
    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)
        ->FUN_00a012d0(0xfb3, objB83.c.g * DBL_0101e568, 1);
    static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)
        ->FUN_00a012d0(0xfb4, objB83.c.b * DBL_0101e568, 1);
    mk8c26.FUN_0043d410(0.0f, 0, 0);
    static_cast<ChainObj*>(
        reinterpret_cast<void*>(
            static_cast<Tile30*>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30)->FUN_0056c7f0()))
        ->FUN_00a59c60(&mk8c26);
    reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_128 = reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_128 + 1;
    if (FUN_007a1750() == 0)
    {
        if (reinterpret_cast<MapMenuR6*>(DAT_011da368)->field_84 ==
            reinterpret_cast<unsigned int>(reinterpret_cast<MapMenuR6*>(DAT_011da368)->tile_30))
            reinterpret_cast<MapMenuR6*>(DAT_011da368)->UpdateLocalMap();
    }
}

namespace fnv_00705ec0 {
class IMHelper
{
  public:
    bool FUN_009373f0();
    void SetRenderedMenu();
};
class ValueHolder
{
  public:
    void* FUN_0056c7f0();
};
class DatHolder
{
  public:
    unsigned char* FUN_00408d60();
};
extern DatHolder DAT_011db620;
class SpawnedObject
{
  public:
    SpawnedObject();
    SpawnedObject* Init();
    void Attach(ValueHolder* a);
    void Set(void* a);
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
};
InterfaceManager* FUN_004b7210();
IMHelper* __stdcall Getter2(SpawnedObject* obj);
ValueHolder* FUN_00765b80(void* a);
void FUN_00a04200(int a);
// @fnv 0x00705ec0
bool FUN_00705ec0(void* arg)
{
    if (FUN_004b7210() != 0 && ((IMHelper*)FUN_004b7210())->FUN_009373f0())
    {
        ValueHolder* v = FUN_00765b80(arg);
        if (*DAT_011db620.FUN_00408d60())
        {
            FUN_00a04200(0);
            SpawnedObject* obj = new SpawnedObject();
            obj->Attach(v);
            obj->Set(v->FUN_0056c7f0());
            Getter2(obj)->SetRenderedMenu();
        }
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00705ec0

namespace fnv_007046f0 {
struct MenuQ
{
    void FUN_00a1d910();
    void FUN_00a1db20();
};
struct TileQ
{
    MenuQ* FUN_00a03c90();
    void FUN_00700320(int, int);
};
struct PipboyQ
{
    void FUN_007f8a80();
    void FUN_007fa010(int);
    bool IsUnk28Set();
};
struct IMQ : InterfaceManager
{
    bool FUN_009373f0();
    PipboyQ* FUN_00704370();
};
TileQ* FUN_00a09030(int);
bool FUN_00702680(int, int);
TileQ* FUN_007046c0();
void FUN_00704390();
void FUN_00782470(int);

// Shows or hides a menu tile and, when showing it, hides several other menu tiles.
// @fnv 0x007046f0
void FUN_007046f0(bool abShow, bool abInstant, bool abActivate)
{
    if (FUN_004b7210() && ((IMQ*)FUN_004b7210())->FUN_009373f0())
    {
        TileQ* m_pInventoryChangesValue = FUN_00a09030(0x3eb);
        TileQ* pStats = FUN_00a09030(0x3ea);
        TileQ* pMap = FUN_00a09030(0x40b);
        TileQ* pRepair5 = FUN_00a09030(0x3ff);
        TileQ* pMenu2 = FUN_00a09030(0x425);
        bool bVisible8 = FUN_00702680(0x425, abInstant ? 0xb : 0);
        if (abShow)
        {
            if (!pMenu2)
                pMenu2 = FUN_007046c0();
            if (!bVisible8)
            {
                if (m_pInventoryChangesValue)
                {
                    m_pInventoryChangesValue->FUN_00a03c90()->FUN_00a1d910();
                    FUN_00704390();
                }
                if (pRepair5)
                    pRepair5->FUN_00a03c90()->FUN_00a1d910();
                if (pMap)
                    pMap->FUN_00a03c90()->FUN_00a1d910();
                if (pMenu2)
                    pMenu2->FUN_00a03c90()->FUN_00a1db20();
                if (pStats)
                    pStats->FUN_00a03c90()->FUN_00a1d910();
            }
            if (pMenu2)
                ((TileQ*)FUN_004b7210()->FUN_00586150())->FUN_00700320(0x1771, 0x425);
            if (abActivate)
            {
                ((IMQ*)FUN_004b7210())->FUN_00704370()->FUN_007f8a80();
                ((IMQ*)FUN_004b7210())->FUN_00704370()->FUN_007fa010(2);
            }
            if (((IMQ*)FUN_004b7210())->FUN_00704370()->IsUnk28Set())
                FUN_00782470(0);
        }
        else if (!abShow && bVisible8 && pMenu2)
        {
            pMenu2->FUN_00a03c90()->FUN_00a1d910();
        }
    }
}
}  // namespace fnv_007046f0

namespace s7094f0 {

struct SpinLock
{
    void Lock(int iArg);
    void Unlock();
};

struct InterfaceManagerView
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
    int m_iModalCount;

    bool FUN_007023a0();
    int FUN_00586150(int iArg);
};

struct NameMenu
{
    NameMenu(int iArg0, int iArg1);

    void FUN_00a087d0(int iTile);
    void FUN_00707e10(const char* pcName);
    void FUN_00409480(struct NameTile* pkTile);

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
    int unk3c;
};

struct NameTile
{
    NameTile();

    void FUN_00a1dc70(NameMenu* pkNameMenu, int iArg);

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
    int unk28;
};

extern SpinLock DAT_011d89c0;
extern int DAT_011d8950;
extern TESObjectREFR* DAT_011d8954;
extern int DAT_011d8958;
extern int DAT_011d895c;
extern int DAT_011d8960;
extern int DAT_011d8964;
extern int DAT_011d8998;
extern int DAT_011d899c;

InterfaceManagerView* FUN_004b7210();
int FUN_00704ed0(TESObjectREFR* pkRef, int iArg);
bool FUN_00705ec0(TESObjectREFR* pkRef);
bool FUN_00706130(TESObjectREFR* pkRef);
int FUN_00705070(TESObjectREFR* pkRef, int iArg0, int iArg1);
int GetOrCreateMenuTile(int iArg);
bool InitStartMenu(int iArg0, int iArg1);
void UpdateVisibilityState(int iArg);
bool FUN_007a8ba0();
bool DestroyCompanionWheelMenu(Actor* pkActor);

static const char s_szPlayerNameEntryMenu[] = "Player Name Entry Menu";

// Processes pending action requests stored in DAT_011d8950 and DAT_011d8998, executing the corresponding logic and clearing the flags on success.
// @fnv 0x007094f0
void FUN_007094f0()
{
    DAT_011d89c0.Lock(0);
    if (DAT_011d8950 && (!FUN_004b7210()->m_iModalCount || DAT_011d8950 == 6 || DAT_011d8950 == 7))
    {
        bool bPickResultFound = false;
        switch (DAT_011d8950)
        {
        case 1:
            bPickResultFound = s7094f0::FUN_00704ed0(DAT_011d8954, DAT_011d8964) ? 1 : 0;
            break;
        case 2:
            bPickResultFound = FUN_00705ec0(DAT_011d8954);
            break;
        case 3:
            bPickResultFound = FUN_00706130(DAT_011d8954);
            break;
        case 4:
            if (!FUN_004b7210()->FUN_007023a0())
                bPickResultFound = FUN_00705070(DAT_011d8954, DAT_011d8958, DAT_011d895c) ? 1 : 0;
            break;
        case 5:
            bPickResultFound = GetOrCreateMenuTile(DAT_011d8960) ? 1 : 0;
            break;
        case 6:
            bPickResultFound = InitStartMenu(1, 0);
            if (bPickResultFound)
                UpdateVisibilityState(4);
            break;
        case 7:
            bPickResultFound = FUN_007a8ba0();
            break;
        case 8:
            bPickResultFound = DestroyCompanionWheelMenu(dynamic_cast<Actor*>(DAT_011d8954));
            break;
        case 9: {
            NameMenu* pkNameMenu = new NameMenu(0, 0);
            NameTile* pkTile = new NameTile;
            pkNameMenu->FUN_00a087d0(FUN_004b7210()->FUN_00586150(0));
            pkNameMenu->FUN_00707e10(s_szPlayerNameEntryMenu);
            pkTile->FUN_00a1dc70(pkNameMenu, 1);
            pkNameMenu->FUN_00409480(pkTile);
            bPickResultFound = true;
        }
        }
        if (bPickResultFound)
        {
            DAT_011d8950 = 0;
            DAT_011d8954 = 0;
        }
    }
    if (DAT_011d8998 && (!FUN_004b7210()->m_iModalCount || DAT_011d8998 == 6 || DAT_011d8998 == 7))
    {
        bool bSuccess2 = false;
        switch (DAT_011d8998)
        {
        case 7:
            bSuccess2 = FUN_007a8ba0();
        }
        if (bSuccess2)
        {
            DAT_011d8998 = 0;
            DAT_011d899c = 0;
        }
    }
    DAT_011d89c0.Unlock();
}

}

struct DisplayTile;
struct DisplayItem;
struct DisplayForm;
struct DisplayPlayer;

struct DisplayList
{
    void* FUN_00726070();
    DisplayTile** FUN_00683520(void**);
    void** FUN_006815c0();
};

struct DisplayName
{
    const char* FUN_00408da0();
};

struct DisplayTile
{
    int unk00;
    DisplayList children;
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
};

struct DisplayEffects
{
    int unk00;
    DisplayList effects;
    void BuildDescription(char*, int);
};

struct DisplayItem
{
    DisplayForm* FUN_0044ddc0();
    DisplayForm* GetExtraForm();
    float FUN_004bd400();
    unsigned char FUN_004bd820();
    bool HasEffect(int);
    float FUN_004bcdb0(bool);
    DisplayList* FUN_00559450();
    int FUN_00726070();
};

struct DisplayForm
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

    DisplayName name;
    int FUN_00401170();
    void FUN_00503a70(char*, int);
    float FUN_004be380(bool);
    int GetField19C();
    unsigned char FUN_00525b20(bool, int, DisplayPlayer*);
    DisplayForm* FUN_00525980(DisplayPlayer*);
    const char* GetStringAtOffsetC4();
    int GetFlaggedValue(bool);
    float FUN_00709430(int);
    float FUN_004be060();
    float FUN_004be180();
    DisplayForm* FUN_004bd570(int);
    bool FUN_0040e210(int);
};

struct DisplayProcess
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

    virtual DisplayItem* Weapon();
    virtual DisplayItem* Ammo();
};

struct ActorValues
{
    int unk00;
};

struct DisplayPlayerPrefix
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
};

struct DisplayPlayer : DisplayPlayerPrefix, ActorValues
{
    bool FUN_004d1360();
    DisplayProcess* FUN_008d8520();
};

struct DisplayInventory
{
    int FUN_004c8f30(DisplayForm*);
};

struct DisplaySetting
{
    const char* FUN_00403df0();
    float* FUN_00403e20();
};

struct ArmorFlags
{
    bool FUN_004c0bd0();
    bool FUN_00514450();
};

class TESObjectARMO : public TESBoundObject
{
  public:
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

    ArmorFlags armorFlags;
};

struct DisplayDescription
{

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Text(int, int);
};

struct DescriptionForm
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

    DisplayDescription description;
};

struct EffectPrefix
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
};

struct EffectForm : EffectPrefix, DisplayEffects
{
};

struct EnchantPrefix
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
};

struct EnchantForm : EnchantPrefix, DisplayEffects
{
    bool FUN_0040e210(int);
};

extern DisplaySetting *DAT_0118a644, *DAT_0118a648, *DAT_0118a640;

extern DisplaySetting DAT_011d4024, DAT_011c6478, DAT_011c64a8, DAT_011c3cb4, DAT_011d20c4, DAT_011d412c, DAT_011d2c7c,
    DAT_011d2aa8, DAT_011d26a0, DAT_011d4da4, DAT_011d4edc, DAT_011d330c;

extern char DAT_0106ed20[], DAT_0106ed18[], DAT_0106ed0c[], DAT_0106ecfc[], DAT_01020764[], DAT_0106ecf4[],
    DAT_01019f08[], DAT_0106ece8[], DAT_01047008[], DAT_0106ece0[], DAT_0106ecd8[], DAT_0106ecd0[], DAT_0106ecc8[],
    DAT_01020768[], DAT_01030018[], DAT_01018348[];

int TraitNameToID(const char*);
float FUN_0048ebc0(DisplayForm*, bool);
DisplayTile* FUN_00a08b20(DisplayTile*, const char*);

unsigned int FUN_0044a670(const char*);
void FUN_005e58f0(int, DisplayPlayer*, ...);
float FUN_00645380(ActorValues*, DisplayForm*, float, bool, DisplayItem*, int, int, int, float, float, int, int,
                   DisplayForm*);
float GetWeaponDamage(DisplayForm*, float, DisplayItem*, DisplayForm*);

void FUN_00406d30(char*, unsigned int, const char*);
float FUN_004bd510(float, float);
float FUN_0040ebd0(float, float);
DisplayInventory* FUN_004bf220(DisplayPlayer*);
int MinInt(int, int);
float FUN_00646360(int, float);
float FUN_00476b20(float);
unsigned int FUN_004873d0(DisplayForm*);
EnchantForm* FUN_004be330(DisplayForm*);
int FUN_00408b20(const char*, const char*);

// Populates the inventory item detail panel tiles with type-specific stats, effects, and value labels.
// @fnv 0x00707e30
void FUN_00707e30(DisplayItem* item, DisplayTile* root)
{

    {

        int maskB = 0;

        int label3 = TraitNameToID(DAT_0106ed20);

        int text3 = TraitNameToID(DAT_0106ed18);

        int value = 0x1009;
        float modY4 = 0.0f;
        float aModZ = 0.0f;

        float _worth = item->FUN_004bd400();
        float weight =
            FUN_0048ebc0(item->FUN_0044ddc0(), reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_004d1360());

        DisplayTile* tiles3[13];
        char worthBufTmp[16];
        char weightBuf[32];

        if (item && root)
        {

            void* pos = root->children.FUN_00726070();
            int indexB = 0;

            while (pos && indexB < 13)
            {
                tiles3[indexB] = *root->children.FUN_00683520(&pos);
                ++indexB;
            }

            while (indexB < 13)
            {
                tiles3[indexB] = 0;
                ++indexB;
            }

            DisplayTile* position = FUN_00a08b20(root, DAT_0106ed0c);
            DisplayTile* reference8 = FUN_00a08b20(root, DAT_0106ecfc);

            position->FUN_00a012d0(0xfb0, reference8->FUN_00a011b0(0xfb0), true);

            position->FUN_00a012d0(0xfa2, reference8->FUN_00a011b0(0xfa2), true);

            bool modified3 = item->FUN_004bd820();

            char _modName[128];
            float perk;
            float width;

            switch (item->FUN_0044ddc0()->FUN_00401170())
            {

            case 0x29: {

                maskB = 12;
                DisplayForm* book = item->FUN_0044ddc0();
                char desc[256];
                book->FUN_00503a70(desc, 256);

                if (FUN_0044a670(desc) > 0)
                {
                    tiles3[6]->FUN_00a01350(text3, desc, true);
                    maskB |= 64;
                }
                else
                    maskB &= ~64;

                break;
            }

            case 0x28: {

                DisplayForm* weapon = item->FUN_0044ddc0();
                tiles3[4]->FUN_00700320(0x100a, true);

                DisplayForm* ammoForm = 0;
                DisplayPlayer* actor_11 = 0;

                if (reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520() &&
                    reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Weapon() &&
                    weapon == reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Weapon()->FUN_0044ddc0())
                {

                    ammoForm =
                        reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Ammo()
                            ? reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Ammo()->FUN_0044ddc0()
                            : 0;
                    actor_11 = reinterpret_cast<DisplayPlayer*>(g_thePlayer);
                }

                weight = weapon->FUN_004be380(item->HasEffect(4));

                if (weight >= 10.0)
                {
                    float multiplier = 1.0f;
                    FUN_005e58f0(0x49, reinterpret_cast<DisplayPlayer*>(g_thePlayer), &multiplier);
                    weight *= multiplier;
                }

                float conditionB = item->FUN_004bcdb0(true) / 100.0;
                int ap_10 = weapon->GetField19C();
                float damage3 = 0.0f;
                float kDps = 0.0f;

                kDps = FUN_00645380(reinterpret_cast<DisplayPlayer*>(g_thePlayer), weapon, conditionB, true, item, 0, 0,
                                    -1, 0.0f, 0.0f, 0, 0, ammoForm);

                if (conditionB <= 0.0)
                    damage3 = 0.0f;
                else
                    damage3 = GetWeaponDamage(weapon, conditionB, item, ammoForm);

                char weaponBuf4[128];
                FUN_00406d00(weaponBuf4, 128, DAT_01020764, (int)FUN_004bd510(kDps, 1.0f));
                tiles3[1]->FUN_00a01350(text3, weaponBuf4, true);

                unsigned int projectiles_4 = weapon->FUN_00525b20(item->HasEffect(12), 0, actor_11);

                if (projectiles_4 > 1)
                {
                    float perShot = damage3 / projectiles_4;
                    FUN_00406d00(weaponBuf4, 128, DAT_0106ecf4, perShot, projectiles_4);
                }

                else
                    FUN_00406d00(weaponBuf4, 128, DAT_01020764, (int)FUN_004bd510(damage3, 1.0f));

                tiles3[11]->FUN_00a01350(text3, weaponBuf4, true);
                tiles3[4]->FUN_00a012d0(value, FUN_0040ebd0(conditionB, 1.0f), true);

                float reduction = 0.0f;
                FUN_005e58f0(0x35, reinterpret_cast<DisplayPlayer*>(g_thePlayer), weapon, &reduction);
                unsigned int reduced = (unsigned int)reduction;
                ap_10 -= reduced;
                if (ap_10 < 0)
                    ap_10 = 0;

                FUN_00406d00(weaponBuf4, 128, DAT_01020764, ap_10);
                if (tiles3[10])
                    tiles3[10]->FUN_00a01350(text3, weaponBuf4, true);

                if (weapon->FUN_00525980(actor_11))
                {

                    DisplayItem* currentWeapon =
                        reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Weapon();
                    DisplayItem* currentAmmo2 = reinterpret_cast<DisplayPlayer*>(g_thePlayer)->FUN_008d8520()->Ammo();

                    const char* name2 = weapon->FUN_00525980(actor_11)->GetStringAtOffsetC4();
                    int total = FUN_004bf220(reinterpret_cast<DisplayPlayer*>(g_thePlayer))
                                    ->FUN_004c8f30(weapon->FUN_00525980(actor_11));
                    int loaded = 0;

                    if (!name2 || !*name2)
                        name2 = weapon->FUN_00525980(actor_11)->name.FUN_00408da0();

                    if (currentWeapon && currentWeapon->FUN_00559450() && item->FUN_00559450() &&
                        *currentWeapon->FUN_00559450()->FUN_006815c0() == *item->FUN_00559450()->FUN_006815c0())
                        loaded = currentAmmo2 ? currentAmmo2->FUN_00726070() : 0;

                    else
                        loaded = MinInt(weapon->GetFlaggedValue(item->HasEffect(2)), total);

                    bool unlimited2 = weapon->FUN_00709430(0) == 0.0 ? false : true;

                    if (unlimited2)
                        FUN_00406d00(weaponBuf4, 128, DAT_01019f08, name2);
                    else
                        FUN_00406d00(weaponBuf4, 128, DAT_0106ece8, name2, loaded, total - loaded);
                }
                else
                    FUN_00406d30(weaponBuf4, 128, DAT_01047008);

                tiles3[5]->FUN_00a01350(label3, weaponBuf4, true);
                maskB = 0xc3e;
                break;
            }

            case 0x18:
            case 0x1a: {

                tiles3[4]->FUN_00700320(0x100a, false);
                float conditionArmor = item->FUN_004bcdb0(true) / 100.0;
                maskB = 0x3c;

                char armorBuf_[128];
                FUN_00406d30(armorBuf_, 128, DAT_01047008);

                TESObjectARMO* armor =
                    dynamic_cast<TESObjectARMO*>(reinterpret_cast<TESBoundObject*>(item->FUN_0044ddc0()));

                if (armor)
                {
                    if (armor->armorFlags.FUN_004c0bd0())
                        FUN_00406d30(armorBuf_, 128, DAT_0118a644->FUN_00403df0());
                    else if (armor->armorFlags.FUN_00514450())
                        FUN_00406d30(armorBuf_, 128, DAT_0118a648->FUN_00403df0());
                    else
                        FUN_00406d30(armorBuf_, 128, DAT_0118a640->FUN_00403df0());
                }

                tiles3[5]->FUN_00a01350(label3, armorBuf_, true);

                float dt3 = FUN_00646360((int)item->FUN_0044ddc0()->FUN_004be060(), conditionArmor);
                float dr2 = FUN_00646360((int)item->FUN_0044ddc0()->FUN_004be180(), conditionArmor);

                if (dt3 == 0.0 && dr2 == 0.0)
                {
                    maskB |= 1;
                    FUN_00406d30(armorBuf_, 128, DAT_01047008);
                    tiles3[0]->FUN_00a01350(text3, armorBuf_, true);
                }

                else
                {
                    if (dt3 != 0.0)
                    {
                        FUN_00406d00(armorBuf_, 128, DAT_01020764, (int)FUN_00476b20(dt3));
                        tiles3[0]->FUN_00a01350(text3, armorBuf_, true);
                        maskB |= 1;
                    }
                    if (dr2 != 0.0)
                    {
                        FUN_00406d00(armorBuf_, 128, DAT_01020764, (int)FUN_00476b20(dr2));
                        tiles3[12]->FUN_00a01350(text3, armorBuf_, true);
                        maskB |= 0x1000;
                    }
                }

                tiles3[4]->FUN_00a012d0(
                    value,
                    FUN_0040ebd0(1.0f,
                                 item->FUN_004bcdb0(false) /
                                     (FUN_004873d0(item->FUN_0044ddc0()) ? FUN_004873d0(item->FUN_0044ddc0()) : 1)),
                    true);
                break;
            }

            default:
                maskB = 12;
            }

            DisplayEffects* effects5 = 0;

            if (item->FUN_0044ddc0()->FUN_00401170() == 0x1d)
                effects5 = static_cast<EffectForm*>(reinterpret_cast<EffectForm*>(item->GetExtraForm()));

            else if (item->FUN_0044ddc0()->FUN_00401170() == 0x2f)
                effects5 = static_cast<EffectForm*>(reinterpret_cast<EffectForm*>(item->FUN_0044ddc0()));

            else
            {
                EnchantForm* enchant = FUN_004be330(item->FUN_0044ddc0());
                if (enchant && !enchant->FUN_0040e210(4))
                    effects5 = enchant;
            }

            if (effects5 && *effects5->effects.FUN_006815c0())
            {
                char effectBuf[256];
                effects5->BuildDescription(effectBuf, 256);
                if (FUN_0044a670(effectBuf) > 0)
                {
                    tiles3[6]->FUN_00a01350(text3, effectBuf, true);
                    maskB |= 64;
                }
                else
                    maskB &= ~64;
            }

            else if (item->FUN_0044ddc0()->FUN_00401170() != 0x29)
                maskB &= ~64;

            if (item->FUN_0044ddc0()->FUN_00401170() == 0x67)
            {
                DescriptionForm* note = reinterpret_cast<DescriptionForm*>(item->FUN_0044ddc0());
                tiles3[6]->FUN_00a01350(text3, note->description.Text(0, 0x43534544), true);
                maskB |= 64;
            }

            if (modified3)
            {

                DisplayForm* modWeapon5 = item->FUN_0044ddc0();
                DisplayForm* mod_16 = 0;
                unsigned char flags = item->FUN_004bd820();
                bool labeled = false;

                if (flags & 1)
                {
                    maskB |= 0x80;
                    tiles3[7]->FUN_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);
                    labeled = true;
                    modY4 += 41.0;
                    aModZ += 41.0;
                    mod_16 = modWeapon5->FUN_004bd570(1);
                    if (mod_16)
                        FUN_00406d30(_modName, 128, mod_16->name.FUN_00408da0());
                    else
                        FUN_00406d30(_modName, 128, DAT_0106ece0);
                    tiles3[7]->FUN_00a01350(text3, _modName, true);
                }

                if (flags & 2)
                {
                    maskB |= 0x100;
                    mod_16 = modWeapon5->FUN_004bd570(2);
                    if (mod_16)
                        FUN_00406d30(_modName, 128, mod_16->name.FUN_00408da0());
                    else
                        FUN_00406d30(_modName, 16, DAT_0106ecd8);
                    tiles3[8]->FUN_00a01350(text3, _modName, true);
                    if (!labeled)
                    {
                        tiles3[8]->FUN_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);
                        labeled = true;
                    }
                    aModZ += 41.0;
                }

                if (flags & 4)
                {
                    mod_16 = modWeapon5->FUN_004bd570(4);
                    if (mod_16)
                        FUN_00406d30(_modName, 128, mod_16->name.FUN_00408da0());
                    else
                        FUN_00406d30(_modName, 16, DAT_0106ecd0);
                    tiles3[9]->FUN_00a01350(text3, _modName, true);
                    maskB |= 0x200;
                    if (!labeled)
                    {
                        tiles3[9]->FUN_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);
                        labeled = true;
                    }
                }

                maskB &= ~64;
            }
            else
                maskB &= ~0x80;

            if (_worth > 0.0)
            {
                if (_worth >= 1.0)
                    FUN_00406d00(worthBufTmp, 16, DAT_0106ecc8, _worth * item->FUN_00726070());
                else
                    FUN_00406d00(worthBufTmp, 16, DAT_01020768, _worth * item->FUN_00726070());
            }
            else
                FUN_00406d30(worthBufTmp, 16, DAT_01047008);

            tiles3[3]->FUN_00a01350(text3, worthBufTmp, true);
            perk = 0.0f;
            FUN_005e58f0(0x37, reinterpret_cast<DisplayPlayer*>(g_thePlayer), &perk);

            if (perk > 0.0 && weight <= *DAT_011c6478.FUN_00403e20())
                weight *= *DAT_011c64a8.FUN_00403e20();

            if (weight > 0.0)
                FUN_00406d00(weightBuf, 32, DAT_01030018, weight * item->FUN_00726070());
            else
                FUN_00406d30(weightBuf, 32, DAT_01047008);

            tiles3[2]->FUN_00a01350(text3, weightBuf, true);

            if (FUN_00408b20(DAT_011c3cb4.FUN_00403df0(), DAT_01018348))
            {

                tiles3[0]->FUN_00a01350(label3, DAT_011d20c4.FUN_00403df0(), true);

                tiles3[1]->FUN_00a01350(label3, DAT_011d412c.FUN_00403df0(), true);

                tiles3[11]->FUN_00a01350(label3, DAT_011d2c7c.FUN_00403df0(), true);

                tiles3[2]->FUN_00a01350(label3, DAT_011d2aa8.FUN_00403df0(), true);

                tiles3[3]->FUN_00a01350(label3, DAT_011d26a0.FUN_00403df0(), true);

                tiles3[4]->FUN_00a01350(label3, DAT_011d4da4.FUN_00403df0(), true);

                tiles3[6]->FUN_00a01350(label3, DAT_011d4edc.FUN_00403df0(), true);

                tiles3[7]->FUN_00a01350(label3, DAT_011d4024.FUN_00403df0(), true);

                tiles3[10]->FUN_00a01350(label3, DAT_011d330c.FUN_00403df0(), true);
            }

            tiles3[0]->FUN_00700320(0xfa3, (maskB & 1) != 0);

            tiles3[12]->FUN_00700320(0xfa3, (maskB & 4096) != 0);

            tiles3[1]->FUN_00700320(0xfa3, (maskB & 2) != 0);

            tiles3[11]->FUN_00700320(0xfa3, (maskB & 2048) != 0);

            tiles3[2]->FUN_00700320(0xfa3, (maskB & 4) != 0);

            tiles3[3]->FUN_00700320(0xfa3, (maskB & 8) != 0);

            tiles3[4]->FUN_00700320(0xfa3, (maskB & 16) != 0);

            tiles3[5]->FUN_00700320(0xfa3, (maskB & 32) != 0);

            tiles3[6]->FUN_00700320(0xfa3, (maskB & 64) != 0);

            tiles3[7]->FUN_00700320(0xfa3, (maskB & 128) != 0);

            tiles3[8]->FUN_00700320(0xfa3, (maskB & 256) != 0);

            tiles3[9]->FUN_00700320(0xfa3, (maskB & 512) != 0);

            if (tiles3[10])
            {
                tiles3[10]->FUN_00700320(0xfa3, (maskB & 0x400) != 0);
                tiles3[10]->FUN_00a012d0(0xfa9, 255.0f, true);
            }

            width = root->FUN_00a011b0(0xfb0) / 2.0 - 20.0;
            if ((maskB & 0x10) || (maskB & 0x20))
                width *= 2.0f;

            tiles3[6]->FUN_00a012d0(0xfa2, width, true);
            tiles3[7]->FUN_00a012d0(0xfa2, width, true);
            tiles3[8]->FUN_00a012d0(0xfa2, width + modY4, true);
            tiles3[9]->FUN_00a012d0(0xfa2, width + aModZ, true);
        }
    }
}
