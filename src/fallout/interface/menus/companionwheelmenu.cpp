// fallout/interface/menus/companionwheelmenu.cpp: CompanionWheelMenu, Foo, WheelHost, InteractionMenu and more (30 functions)

#include "companionwheelmenu_decls.h"
// Constructor: sets the menu state of FUN_004b7210() to 255 and initializes state to 0.
// @fnv 0x007a8a10
CompanionWheelMenu::CompanionWheelMenu()
{
    FUN_004b7210()->menuState = 255;
    state = 0;
}

struct FUN_00754bf0_shell
{
    int __thiscall GetClass();
};

// @fnv 0x00754bf0
int __thiscall FUN_00754bf0_shell::GetClass()
{
    return 0x433;
}

struct FUN_00884480_shell
{
    bool __thiscall FUN_00884480(void);
};
struct Actor
{
    bool __thiscall IsHostileToActor(Actor*, int, int*, bool);
};
extern Actor* g_thePlayer;

// @fnv 0x00754d90
bool FUN_00754d90(Actor* apActor)
{
    if (!apActor)
        return false;
    if (!static_cast<FUN_00884480_shell*>(static_cast<void*>(apActor))->FUN_00884480())
        return false;
    int tmp;
    if (apActor->IsHostileToActor(g_thePlayer, 0, &tmp, false))
        return false;
    return true;
}

// @fnv 0x00755260
int __cdecl FUN_00755260()
{
    return 0x433;
}

extern "C" float __cdecl LogFloat(float);

// @fnv 0x00755660
float FUN_00755660(float value)
{
    return LogFloat(value);
}

extern "C" void __cdecl CloseMenuAndRefresh(int);

// @fnv 0x00756960
void __fastcall FUN_00756960(int thisPtr)
{
    *(char*)(thisPtr + 0x74) = 1;
    CloseMenuAndRefresh(1);
}

extern bool __cdecl _FUN_004b71d0();

struct FUN_00755680_shell
{
    bool __thiscall FUN_00755680();
};

// Returns true if _FUN_004b71d0 is false or the byte at offset 0x7d equals 1; otherwise returns false.
// @fnv 0x00755680
bool __thiscall FUN_00755680_shell::FUN_00755680()
{
    if (!_FUN_004b71d0() || ((unsigned char*)this)[0x7d] == 1)
        return true;
    return false;
}

struct MyStandin754c30
{
    void __thiscall FUN_00754c60();
    void* __thiscall FUN_00754c30(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00754c60, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00754c30
void* __thiscall MyStandin754c30::FUN_00754c30(unsigned int flags)
{
    this->FUN_00754c60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Tile
{
    void __thiscall Set(int, char const*, bool);
};
struct Unk00755d90
{
    char _pad[0x4C];
    Tile* _tile;
    void __thiscall SetTileText(char const*);
};
// If _tile is set, calls _tile->Set with id 0xFC4, the given string and true.
// @fnv 0x00755d90
void __thiscall Unk00755d90::SetTileText(char const* acText)
{
    if (_tile != 0)
        _tile->Set(0xFC4, acText, true);
}

struct FUN_008a7760_holder
{
    void __thiscall OpenDialogMenu();
};
struct FUN_00756930_shell
{
    char _pad[0x68];
    Actor* m_pDialogueActor;
    void __thiscall FUN_00756930();
};
// @fnv 0x00756930
void __thiscall FUN_00756930_shell::FUN_00756930()
{
    if (m_pDialogueActor)
        ((FUN_008a7760_holder*)m_pDialogueActor)->OpenDialogMenu();
    CloseMenuAndRefresh(1);
}

struct TESForm
{
    virtual void v0();
    static TESForm* __cdecl LookupFormByEditorID(const char*);
};
struct TESTopic
{
    virtual void v0();
};
struct Tile2
{
    void __thiscall Set(int, int);
};
struct FUN_007560c0_shell
{
    void __thiscall PlayTopicResponse(TESTopic*);
    void __thiscall RunTopicResultScripts(TESTopic*);
    void __thiscall ToggleFollowersTacticsDistance();
};
// @fnv 0x007560c0
void __thiscall FUN_007560c0_shell::ToggleFollowersTacticsDistance()
{
    bool bSuccess;
    *((bool*)((char*)this + 0x6c)) = !*((bool*)((char*)this + 0x6c));
    bSuccess = false;
    if (*((bool*)((char*)this + 0x6c)))
    {
        TESTopic* pRelatedTopic =
            dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID("FollowersTacticsDistanceLong"));
        PlayTopicResponse(pRelatedTopic);
        RunTopicResultScripts(pRelatedTopic);
        bSuccess = true;
    }
    else
    {
        TESTopic* pRelatedTopic =
            dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID("FollowersTacticsDistanceDefault"));
        PlayTopicResponse(pRelatedTopic);
        RunTopicResultScripts(pRelatedTopic);
        bSuccess = true;
    }
    if (bSuccess && *((Tile2**)((char*)this + 0x3c)))
    {
        ((Tile2**)((char*)this + 0x3c))[0]->Set(0x100f, *((bool*)((char*)this + 0x6c)));
    }
}

namespace fnv_007575b0 {
struct Actor;
struct ScriptLocals;
struct Script
{
    bool __thiscall Run(Actor*, ScriptLocals*, bool, bool);
};
struct ScriptS
{
    void* __thiscall GetHeader();
};
struct ExtraDataList
{
    ScriptLocals* __thiscall GetScriptLocalData();
};
struct XActor
{
    ExtraDataList* __thiscall GetExtra() const;
};
struct MobileObject;
struct PlayerCharacter;
struct TESTopicInfo
{
    Script* __thiscall GetResultScript(unsigned int);
};
struct TESTopic
{
    TESTopicInfo* __thiscall FindMatchingTopicInfo(MobileObject*, PlayerCharacter*);
};
struct FUN_007575b0_shell
{
    char _pad[0x68];
    Actor* m_pDialogueActor;
    void __thiscall RunTopicResultScripts(TESTopic* aRelatedTopic);
};
// @fnv 0x007575b0
void FUN_007575b0_shell::RunTopicResultScripts(TESTopic* aRelatedTopic)
{
    TESTopicInfo* pInfo = 0;
    Actor* pactor;
    PlayerCharacter* pActionActor;
    Script* pInfoScript;
    pActionActor = (PlayerCharacter*)g_thePlayer;
    pactor = m_pDialogueActor;
    if (aRelatedTopic)
        pInfo = aRelatedTopic->FindMatchingTopicInfo((MobileObject*)pactor, pActionActor);
    if (pInfo)
    {
        pInfoScript = pInfo->GetResultScript(0);
        if (pInfoScript && *(int*)((char*)((ScriptS*)pInfoScript)->GetHeader() + 8))
            pInfoScript->Run(m_pDialogueActor, ((XActor*)m_pDialogueActor)->GetExtra()->GetScriptLocalData(), false,
                             true);
        pInfoScript = pInfo->GetResultScript(1);
        if (pInfoScript && *(int*)((char*)((ScriptS*)pInfoScript)->GetHeader() + 8))
            pInfoScript->Run(m_pDialogueActor, ((XActor*)m_pDialogueActor)->GetExtra()->GetScriptLocalData(), false,
                             true);
    }
}
}  // namespace fnv_007575b0

struct MagicCaster
{
    void __thiscall SetSelectedMagicItem(int);
};

struct Date
{
    virtual ~Date();
};

struct Menu_007a8b10
{
    char _pad[0x70];
    virtual ~Menu_007a8b10();
};

MagicCaster* __cdecl _FUN_004b7210();
extern int DAT_011d92b8;

struct FUN_00754c60 : Menu_007a8b10
{
    bool _flag;
    char _pad[7];
    Date _date;

    void __thiscall UpdateCompanionInteraction();

    ~FUN_00754c60();
};

// @fnv 0x00754c60
FUN_00754c60::~FUN_00754c60()
{
    if (_flag)
    {
        _FUN_004b7210()->SetSelectedMagicItem(1);
        UpdateCompanionInteraction();
    }

    DAT_011d92b8 = 0;
}

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};

void __cdecl FUN_00717280(int);

struct FUN_007552e0_shell
{
    void __thiscall FUN_007552e0(int, Tile*);
    void __thiscall SelectTile(int, bool);
    void __thiscall ToggleAggressive();
    void __thiscall ToggleRelatedTopic();
    void __thiscall ToggleFollowerWait();
    void __thiscall HealCompanion();
    void __thiscall FUN_007568d0();

    unsigned char _pad[0x28];
    Tile* m_pTiles[64];
};

// @fnv 0x007552e0
void FUN_007552e0_shell::FUN_007552e0(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 16)
        apTarget = m_pTiles[aiID];

    if (!InterfaceH::GetSelectedTargetIndex(0x433))
        return;

    switch (aiID)
    {
    case 11:
        FUN_00717280(1);
        CloseMenuAndRefresh(1);
        break;

    case 3:
        FUN_00756960(reinterpret_cast<int>(this));
        FUN_00717280(1);
        break;

    case 2:
        this->ToggleFollowerWait();
        this->SelectTile(aiID, true);
        FUN_00717280(1);
        break;

    case 4:
        reinterpret_cast<FUN_00756930_shell*>(this)->FUN_00756930();
        FUN_00717280(1);
        break;

    case 0:
        this->ToggleAggressive();
        this->SelectTile(aiID, true);
        FUN_00717280(1);
        break;

    case 1:
        this->HealCompanion();
        this->SelectTile(aiID, true);
        FUN_00717280(1);
        break;

    case 7:
        this->ToggleRelatedTopic();
        this->SelectTile(aiID, true);
        FUN_00717280(1);
        break;

    case 6:
        this->FUN_007568d0();
        FUN_00717280(1);
        break;

    case 5:
        reinterpret_cast<FUN_007560c0_shell*>(this)->ToggleFollowersTacticsDistance();
        this->SelectTile(aiID, true);
        FUN_00717280(1);
        break;
    }
}

namespace fnv_007562b0 {
struct FUN_007562b0_shell
{
    char _pad00[0x44];
    Tile2* m_pPromptTile;
    char _pad48[0x20];
    Actor* m_pDialogueActor;
    char _pad6C[2];
    bool m_bRelatedTopicVisible;

    void __thiscall ToggleRelatedTopic();
};

extern FUN_007562b0_shell* DAT_011d92b8;
extern char str_01071f24[];
extern char str_01071f40[];

// @fnv 0x007562b0
void __thiscall FUN_007562b0_shell::ToggleRelatedTopic()
{
    bool bSuccess = false;

    if (m_pDialogueActor)
    {
        m_bRelatedTopicVisible = !m_bRelatedTopicVisible;

        if (m_bRelatedTopicVisible)
        {
            TESTopic* pRelatedTopic = dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID(str_01071f40));

            ((FUN_007560c0_shell*)this)->PlayTopicResponse(pRelatedTopic);
            ((FUN_007560c0_shell*)this)->RunTopicResultScripts(pRelatedTopic);
            bSuccess = true;
        }
        else
        {
            TESTopic* pRelatedTopic = dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID(str_01071f24));

            ((FUN_007560c0_shell*)this)->PlayTopicResponse(pRelatedTopic);
            ((FUN_007560c0_shell*)this)->RunTopicResultScripts(pRelatedTopic);
            bSuccess = true;
        }

        if (bSuccess)
        {
            if (m_pPromptTile)
                m_pPromptTile->Set(0x100f, DAT_011d92b8->m_bRelatedTopicVisible);
        }
    }
}
}  // namespace fnv_007562b0

unsigned int __cdecl gm_GetTickCount(void);
float __cdecl FUN_00755660(float value);
int __cdecl _FUN_00ec7d40(int value);

extern char $SG3295[];
extern double _DAT_01012060;
extern double DAT_01071e20;
extern float DAT_01071e28;
extern float DAT_01071e2c;
extern double _DAT_0104eea0;
extern short DAT_011d8a5c;
extern short DAT_011d8a5e;
extern short DAT_011d8a74;

struct FUN_00755480_shell
{
    char _pad[0x58];
    Tile* pTile;
    char _pad2[0x1C];
    unsigned int m_uiCurrentItemIndex;

    void __thiscall FUN_00755c50(float value);
    void __thiscall UpdateTileTimerAndInputAngle();
};

// @fnv 0x00755480
void FUN_00755480_shell::UpdateTileTimerAndInputAngle()
{
    float fInputVectorY;
    float fInputAngle;
    bool bSufficientMagnitude;
    float fInputVectorX;

    bSufficientMagnitude = false;
    fInputVectorX = 0.0f;
    fInputVectorY = 0.0f;
    fInputAngle = 0.0f;

    if (m_uiCurrentItemIndex != 0 && gm_GetTickCount() > m_uiCurrentItemIndex)
    {
        m_uiCurrentItemIndex = 0;
        if (pTile != 0)
            pTile->Set(0xFC4, $SG3295, true);
    }

    if (!InterfaceH::GetSelectedTargetIndex(0x433))
        return;

    _FUN_004b7210();
    if (_FUN_004b71d0())
    {
        if (!((FUN_00755680_shell*)_FUN_004b7210())->FUN_00755680())
        {
            _FUN_004b7210();
            if (_FUN_004b71d0())
            {
                if (!((FUN_00755680_shell*)_FUN_004b7210())->FUN_00755680())
                {
                    if (_FUN_00ec7d40(DAT_011d8a5e) > 0x1EA9 || _FUN_00ec7d40(DAT_011d8a74) > 0x1EA9)
                    {
                        bSufficientMagnitude = true;
                        fInputVectorX = DAT_011d8a5c;
                        fInputVectorY = DAT_011d8a5e;
                    }
                }
            }
        }
    }

    if (bSufficientMagnitude)
    {
        fInputVectorY = -fInputVectorY;

        if (fInputVectorY != 0.0f)
        {
            fInputAngle = FUN_00755660(-fInputVectorX / fInputVectorY);
        }
        else if (fInputVectorX > 0.0f)
        {
            fInputAngle = DAT_01071e2c;
        }
        else
        {
            fInputAngle = DAT_01071e28;
        }

        if (fInputVectorY > 0.0f)
            fInputAngle = fInputAngle + DAT_01071e20;

        if (fInputVectorX < 0.0f && fInputVectorY < 0.0f)
            fInputAngle = fInputAngle + _DAT_0104eea0;

        FUN_00755c50(fInputAngle);
    }
}

struct MenuFactory
{
    Menu* FUN_00a03c90();
};
MenuFactory* __cdecl FUN_00a09030(int id);
int __cdecl OpenCompanionMenu(int value);

// Looks up the menu factory for id 0x433, deletes its CompanionWheelMenu if present, then returns the result of OpenCompanionMenu(value).
// @fnv 0x00754cf0
bool __cdecl DestroyCompanionWheelMenu(int value)
{
    MenuFactory* factory = FUN_00a09030(0x433);
    CompanionWheelMenu* menu = factory ? dynamic_cast<CompanionWheelMenu*>(factory->FUN_00a03c90()) : 0;
    if (menu)
        delete menu;
    if (OpenCompanionMenu(value))
        return true;
    return false;
}

namespace fnv_00754de0 {
extern const char DAT_01071dfc[];
extern const char DAT_01071de0[];
extern const char DAT_01071dd0[];
extern const char DAT_01071dbc[];
extern const char DAT_01011584[];
struct TileOps;
struct ActorOps
{
    float ComputeFromNode(const char*);
};
struct MenuView
{
    virtual ~MenuView();
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
    virtual int GetMenuID();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    TileOps* tile28;
    unsigned int unk2c;
    TileOps* tile30;
    unsigned int unk34, unk38;
    TileOps* tile3c;
    unsigned int unk40;
    TileOps* tile44;
    TileOps* tile48;
    unsigned int unk4c, unk50, unk54;
    TileOps* tile58;
    TileOps* tile5c;
    TileOps* tile60;
    TileOps* tile64;
    ActorOps* companion;
    bool following, aggressive, ranged, waiting;
    void FUN_00a1dc70(TileOps*, bool);
    bool FUN_007b78a0();
    void FUN_00a1dc20(bool);
    int FUN_00726070();
};
struct TileOps
{
    TileOps* ReadFile(const char*);
    MenuView* GetMenu();
    void Set(int, int);
    void Set(int, const char*, bool);
    void Set(int, float);
    float FUN_00a011b0(int);
};
struct ResourceProvider
{
    TileOps* FUN_00586150();
};
struct SettingLite
{
    const char* FUN_00403df0();
};
extern SettingLite DAT_011d3534, DAT_011d33fc, DAT_011d3ec8, DAT_011d27d8;
extern MenuView* companionMenu;
MenuView* FUN_00a09030(int);
struct BSSoundHandleEx
{
    unsigned int id, status, flags;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
BSAudio* FUN_00453a70();
float __stdcall FUN_00a01530(bool);
void FUN_005b5e40(const char*, ...);
extern const char DAT_01071d58[];
extern const char DAT_01025cc4[];
extern const char DAT_01071db4[];
// @fnv 0x00754de0
TileOps* OpenCompanionMenu(ActorOps* actor)
{
    ResourceProvider* a = (ResourceProvider*)FUN_004b7210();
    MenuView* p = FUN_00a09030(FUN_00755260());
    if (p)
        delete p;
    TileOps* h = a->FUN_00586150()->ReadFile(DAT_01071dfc);
    companionMenu = h->GetMenu();
    if (companionMenu && companionMenu->GetMenuID() == FUN_00755260())
    {
        companionMenu->companion = actor;
        if (companionMenu->companion)
        {
            companionMenu->aggressive = companionMenu->companion->ComputeFromNode(DAT_01071de0) == 1.0;
            companionMenu->following = companionMenu->companion->ComputeFromNode(DAT_01071dd0) == 1.0;
            companionMenu->ranged = companionMenu->companion->ComputeFromNode(DAT_01071dbc) == 1.0;
            companionMenu->waiting = companionMenu->companion->ComputeFromNode(DAT_01071db4) == 0.0;
        }
        if (companionMenu->tile28)
            companionMenu->tile28->Set(0x100f, (int)companionMenu->aggressive);
        if (companionMenu->tile30)
            companionMenu->tile30->Set(0x100f, (int)!companionMenu->waiting);
        if (companionMenu->tile3c)
            companionMenu->tile3c->Set(0x100f, (int)companionMenu->following);
        if (companionMenu->tile44)
            companionMenu->tile44->Set(0x100f, (int)companionMenu->ranged);
        if (companionMenu->tile58)
            companionMenu->tile58->Set(0xfc4, DAT_01011584, true);
        if (companionMenu->tile48)
            companionMenu->tile48->Set(0xfc4, DAT_011d3534.FUN_00403df0(), true);
        if (companionMenu->tile5c)
            companionMenu->tile5c->Set(0xfc4, DAT_011d33fc.FUN_00403df0(), true);
        if (companionMenu->tile60)
            companionMenu->tile60->Set(0xfc4, DAT_011d3ec8.FUN_00403df0(), true);
        if (companionMenu->tile64)
            companionMenu->tile64->Set(0xfc4, DAT_011d27d8.FUN_00403df0(), true);
        companionMenu->FUN_00a1dc70(h, false);
        if (!companionMenu->FUN_007b78a0())
        {
            FUN_005b5e40(DAT_01071d58);
            return 0;
        }
        FUN_00453a70()->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        if (h->FUN_00a011b0(0xfa7) == 6006.0 || h->FUN_00a011b0(0xfa7) == 102.0)
            h->Set(0xfad, FUN_00a01530(true));
        companionMenu->FUN_00a1dc20(false);
        return h;
    }
    else if (companionMenu && companionMenu->FUN_00726070())
        delete companionMenu;
    return 0;
}
}  // namespace fnv_00754de0

extern "C" bool __cdecl FUN_00702450(int);

struct Foo
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf(int, Tile*);
    char _pad[0x24];
    Tile* m_pTiles[18];
    int idx;
    bool HandleTileAction(int arg, int unused);
};

// If setting 0x433 is enabled, dispatches a virtual call for arg 9 (using idx or slot 11) or arg 10 (slot 11) and returns whether it dispatched.
// @fnv 0x007556b0
bool Foo::HandleTileAction(int aiAction, int unused)
{
    bool result = false;
    if (!FUN_00702450(0x433))
    {
        return result;
    }
    if (aiAction == 9)
    {
        if (this->idx != -1)
        {
            this->vf(this->idx, this->m_pTiles[this->idx]);
            result = true;
        }
        else
        {
            this->vf(0xb, this->m_pTiles[11]);
            result = true;
        }
    }
    else if (aiAction == 10)
    {
        this->vf(0xb, this->m_pTiles[11]);
        result = true;
    }
    return result;
}

struct WheelHost
{
    char unk00[0x28];
    int m_aiIndexedValues[16];
    void __thiscall SelectTile(int, bool);
    void __thiscall FUN_00755760(int a, int b);
};

bool __cdecl FUN_00702450(int);

// @fnv 0x00755760
void __thiscall WheelHost::FUN_00755760(int aiSlot, int aiValue)
{
    if (aiValue == 0 && aiSlot >= 0 && aiSlot < 16)
    {
        aiValue = m_aiIndexedValues[aiSlot];
    }
    if (FUN_00702450(0x433) == 0)
    {
    }
    else
    {
        switch (aiSlot)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 11:
            SelectTile(aiSlot, false);
            break;
        default:
            break;
        }
    }
}

struct InteractionActor;
struct PackageNode
{
    PackageNode* FUN_00726070();
};
struct TESPackage
{
    virtual ~TESPackage();
    int FUN_0041ca90();
    bool FUN_00678610();
    PackageNode* FUN_0041d8a0();
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
};
struct DialoguePackage : TESPackage
{
    unsigned int topic;
};
struct ActorLevelInfo
{
    unsigned int unk00, unk04, unk08;
    unsigned short unk0c;
    unsigned char level;
};
struct DialoguePolicy
{
    bool FUN_00619df0();
};
struct DialogueItem
{
    DialoguePolicy* FUN_0084e3a0();
    bool FUN_0083c7b0();
    bool FUN_0083c7e0();
    ~DialogueItem();
    static void operator delete(void*);
};
struct DialogueManager
{
    DialogueItem* FUN_0061b320(InteractionActor*, InteractionActor*, int, int, int);
};
DialogueManager* GetTopicSubTypeName(int, int);
struct ActorPosition
{
    float x, y, z;
};
struct ActorExtraData
{
    void FUN_00815b00();
};
struct ActorLock
{
    bool FUN_0047c850();
};
struct InteractionActor
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
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
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
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual ActorPosition* GetPosition(int);
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int GetState();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsUnavailable(int);
    virtual bool CanInteract();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual TESPackage* GetAssignedPackage();
    virtual void slot160();
    virtual void slot161();
    virtual void SetPackage(InteractionActor*, int);
    virtual void slot163();
    virtual void slot164();
    virtual void Prepare(InteractionActor*);
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual InteractionActor* GetRelated();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual bool IsDead();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual bool AllowTarget(InteractionActor*);
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void ResetDialogue();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual ActorLock* GetLock();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void slot288();
    virtual void slot289();
    virtual void slot290();
    virtual void slot291();
    virtual void slot292();
    virtual void slot293();
    virtual void slot294();
    virtual void slot295();
    virtual void slot296();
    virtual void slot297();
    virtual void slot298();
    virtual void slot299();
    virtual void slot300();
    virtual void slot301();
    virtual void slot302();
    virtual void slot303();
    virtual void slot304();
    virtual void slot305();
    virtual void slot306();
    virtual void slot307();
    virtual void slot308();
    virtual ActorLevelInfo* GetLevelInfo();
    virtual void slot310();
    virtual void slot311();
    virtual void slot312();
    virtual void slot313();
    virtual void slot314();
    virtual void slot315();
    virtual void slot316();
    virtual void slot317();
    virtual void slot318();
    virtual void slot319();
    virtual void slot320();
    virtual void slot321();
    virtual void slot322();
    virtual void slot323();
    virtual void slot324();
    virtual void slot325();
    virtual void slot326();
    virtual void slot327();
    virtual void slot328();
    virtual void slot329();
    virtual void slot330();
    virtual int IsRestricted();
    virtual void slot332();
    virtual void slot333();
    virtual void slot334();
    virtual void slot335();
    virtual void slot336();
    virtual void slot337();
    virtual void slot338();
    virtual void slot339();
    virtual void slot340();
    virtual void slot341();
    virtual void slot342();
    virtual void slot343();
    virtual void slot344();
    virtual void slot345();
    virtual void slot346();
    virtual void slot347();
    virtual void slot348();
    virtual void slot349();
    virtual void slot350();
    virtual void slot351();
    virtual void slot352();
    virtual void slot353();
    virtual void slot354();
    virtual void slot355();
    virtual void slot356();
    virtual void slot357();
    virtual void slot358();
    virtual void slot359();
    virtual void slot360();
    virtual void slot361();
    virtual void slot362();
    virtual void slot363();
    virtual void slot364();
    virtual void slot365();
    virtual void slot366();
    virtual void slot367();
    virtual void slot368();
    virtual void slot369();
    virtual void slot370();
    virtual void slot371();
    virtual void slot372();
    virtual void slot373();
    virtual void slot374();
    virtual void slot375();
    virtual void slot376();
    virtual void slot377();
    virtual void slot378();
    virtual void slot379();
    virtual void slot380();
    virtual void slot381();
    virtual void slot382();
    virtual void slot383();
    virtual void SetDialogue(bool);
    virtual bool CanDialogue();
    virtual void slot386();
    virtual void slot387();
    virtual int IsBusy();
    virtual void SetFlags(int);
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
    ActorExtraData extras;
    InteractionActor* FUN_008d8520();
    bool FUN_00493bb0();
    bool FUN_00566950();
    bool FUN_00608d80();
    bool FUN_0087f3d0();
    TESPackage* FUN_009344a0();
    bool FUN_004997b0();
    bool FUN_008ace90();
    void StartDialog(DialogueManager*, int, int);
    void FUN_008bb520(ActorPosition);
    bool FUN_008b3bb0();
    bool FUN_008b3c30();
    void FUN_008a8e50();
    void FUN_008a7a90();
    const char* FUN_0055d520();
};
extern InteractionActor* interactionPlayer;
struct DialogueDisplay
{
    void FUN_009c8950(int, int);
};
extern DialogueDisplay dialogueDisplay;
void FUN_00709470(int, InteractionActor*, unsigned int, int, int, int);
struct InputState
{
    void FUN_00ad8780();
};
InputState* __stdcall FUN_00453a70(int);
int FUN_00702640();
struct MessageSetting
{
    const char* FUN_00403df0();
};
extern MessageSetting lockedMessage;
int sprintf(char*, const char*, ...);
extern float messageDuration;
void DispatchMessageToSink(const char*, int, int, int, float, int);
struct InteractionMenu
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
    InteractionActor* companion;
    void UpdateCompanionInteraction();
};
// Checks the companion's state and packages, then starts or resets dialogue with the player or another actor, or shows a locked message.
// @fnv 0x00756980
void InteractionMenu::UpdateCompanionInteraction()
{
    InteractionActor* player2 = interactionPlayer;
    InteractionActor* aTarget = companion;
    if (!aTarget || aTarget->IsDead())
        return;
    InteractionActor* actor2 = aTarget->FUN_008d8520();
    if (!actor2)
        return;
    if (actor2 && actor2->IsRestricted() && !aTarget->IsUnavailable(0))
        return;
    if (actor2 && actor2->IsBusy())
        return;
    TESPackage* playerPackage8 = player2->FUN_008d8520()->GetAssignedPackage();
    TESPackage* targetPackageB = actor2->GetAssignedPackage();
    if (player2)
    {
        if (aTarget->FUN_00493bb0() && player2 == interactionPlayer && aTarget->FUN_00566950())
        {
            dialogueDisplay.FUN_009c8950(0, 0);
            FUN_00709470(4, aTarget, 0, 0, 1, 0);
            return;
        }
        if (aTarget && (!aTarget->FUN_00493bb0() || aTarget->CanInteract()) &&
            (player2 != interactionPlayer || !aTarget->GetState() || aTarget->GetState() == 9 ||
             aTarget->GetState() == 4 ||
             (aTarget->FUN_008d8520()->GetLevelInfo() && aTarget->FUN_008d8520()->GetLevelInfo()->level > 19)))
        {
            if (aTarget->FUN_00608d80())
                return;
            if (!aTarget->IsUnavailable(0))
            {
                if (player2 == interactionPlayer && aTarget->CanInteract() && aTarget->FUN_0087f3d0())
                {
                    return;
                }
                else if (player2 == interactionPlayer ||
                         (aTarget == interactionPlayer &&
                          (player2->FUN_009344a0()->FUN_00678610() || !player2->FUN_009344a0()->FUN_0041ca90() ||
                           player2->FUN_009344a0()->FUN_0041ca90() == 9)))
                {
                    if (player2 == interactionPlayer &&
                        (aTarget->CanInteract() || (interactionPlayer->FUN_004997b0() && !aTarget->FUN_00566950())) &&
                        !aTarget->FUN_008ace90())
                    {
                    }
                    else
                    {
                        DialogueManager* manager = 0;
                        if (player2 == interactionPlayer || player2->FUN_008d8520()->CanDialogue())
                            manager = GetTopicSubTypeName(0, 0);
                        DialogueItem* item3 = 0;
                        if (manager)
                        {
                            if (player2 == interactionPlayer)
                                item3 = manager->FUN_0061b320(aTarget, interactionPlayer, 0, 0, 0);
                            else if (player2->FUN_008d8520()->CanDialogue())
                                item3 = manager->FUN_0061b320(player2, interactionPlayer, 0, 0, 0);
                        }
                        if (item3 && item3->FUN_0084e3a0()->FUN_00619df0() && item3->FUN_0083c7b0() &&
                            !item3->FUN_0083c7e0())
                        {
                            if (aTarget->GetState() == 9)
                            {
                                aTarget->FUN_008d8520()->SetDialogue(true);
                                aTarget->ResetDialogue();
                                return;
                            }
                            else
                            {
                                if (aTarget == interactionPlayer)
                                    player2->StartDialog(manager, 0, 0);
                                else
                                    aTarget->StartDialog(manager, 0, 0);
                            }
                        }
                        else
                        {
                            if (aTarget->FUN_008d8520()->GetLevelInfo() &&
                                aTarget->FUN_008d8520()->GetLevelInfo()->level > 19)
                                aTarget->FUN_008d8520()->SetFlags(512);
                            if (!aTarget->GetState())
                                aTarget->FUN_008bb520(*player2->GetPosition(0));
                            unsigned int topic = 0;
                            InteractionActor* participant = 0;
                            if (player2 == interactionPlayer)
                            {
                                if (!aTarget->FUN_008b3bb0() && !aTarget->FUN_008b3c30())
                                    aTarget->FUN_008d8520()->Prepare(aTarget);
                                player2->FUN_008a8e50();
                                aTarget->FUN_008a8e50();
                                DialoguePackage* package = dynamic_cast<DialoguePackage*>(player2->FUN_009344a0());
                                if (package)
                                    topic = package->topic;
                                participant = companion;
                                if (aTarget->GetRelated() == interactionPlayer && targetPackageB &&
                                    !targetPackageB->FUN_0041ca90())
                                {
                                    if (targetPackageB->FUN_0041d8a0() &&
                                        !targetPackageB->FUN_0041d8a0()->FUN_00726070())
                                        actor2->SetPackage(player2, 2);
                                    else
                                        actor2->SetPackage(aTarget, 1);
                                }
                                FUN_00453a70(4)->FUN_00ad8780();
                                aTarget->extras.FUN_00815b00();
                                if (aTarget->GetState() != 9)
                                {
                                    InteractionActor* speaker = player2;
                                    if (speaker == interactionPlayer)
                                        speaker = aTarget;
                                    dialogueDisplay.FUN_009c8950(0, 0);
                                    FUN_00709470(4, speaker, topic, 0, 1, 0);
                                }
                                else
                                {
                                    aTarget->FUN_008d8520()->SetDialogue(true);
                                    aTarget->ResetDialogue();
                                }
                            }
                            else if (FUN_00702640() != 1009)
                            {
                                if (!interactionPlayer->FUN_008d8520()->AllowTarget(player2))
                                    return;
                                FUN_00453a70(4)->FUN_00ad8780();
                                player2->FUN_008a8e50();
                                aTarget->FUN_008a8e50();
                                participant = player2;
                                if (!player2->FUN_00493bb0())
                                {
                                    DialoguePackage* package = dynamic_cast<DialoguePackage*>(player2->FUN_009344a0());
                                    if (package)
                                        topic = package->topic;
                                }
                                if (playerPackage8->FUN_0041d8a0() && !playerPackage8->FUN_0041d8a0()->FUN_00726070())
                                    player2->FUN_008d8520()->SetPackage(player2, 2);
                                else
                                    player2->FUN_008d8520()->SetPackage(player2, 1);
                                aTarget->extras.FUN_00815b00();
                                if (aTarget == interactionPlayer)
                                    aTarget->FUN_008a7a90();
                                else
                                    aTarget->FUN_008d8520()->SetFlags(1024);
                                if (player2 == interactionPlayer)
                                    player2->FUN_008a7a90();
                                else
                                    player2->FUN_008d8520()->SetFlags(1024);
                                dialogueDisplay.FUN_009c8950(0, 0);
                                InteractionActor* speaker = player2;
                                if (speaker == interactionPlayer)
                                    speaker = aTarget;
                                FUN_00709470(4, speaker, topic, 0, 1, 0);
                            }
                        }
                        delete item3;
                    }
                }
            }
        }
        else if (aTarget && aTarget->GetLock() && player2 == interactionPlayer && aTarget->GetLock()->FUN_0047c850())
        {
            char message[200];
            sprintf(message, "%s %s", aTarget->FUN_0055d520(), lockedMessage.FUN_00403df0());
            DispatchMessageToSink(message, 0, 0, 0, messageDuration, 0);
        }
    }
}

struct BSStringT
{
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    BSStringT(const BSStringT& src);
    ~BSStringT();
    unsigned int GetLength();
    const char* CStr();
};

struct SoundPlaybackHandle
{
    unsigned int soundID;
    bool assumeSuccess;
    unsigned int state;
    SoundPlaybackHandle(const SoundPlaybackHandle& src);
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& src);
    ~SoundPlaybackHandle();
};

struct TESQuest;
struct TESTopicInfo;
struct TESObjectREFR;
struct TESTopic;

struct SoundFile
{
    unsigned int GetSoundID();
};

struct SoundPath
{
    const char* CStr();
};

struct DialogueResponse
{
    SoundFile* GetSoundByEditorID();
    unsigned int GetSoundID();
    BSStringT& GetText();
    int GetEmotionValue();
    int GetEmotionType();
    unsigned int GetFlags();
    SoundPath* GetVoicePath(SoundPlaybackHandle* snd);
};

struct CompActor
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
    virtual float Speak(const char* voicePath, unsigned int flags, unsigned int soundID, unsigned int textLen,
                        int emotionType, int emotionValue, CompActor* target, bool a8, bool a9, bool a10, bool a11,
                        bool a12);

    SoundPlaybackHandle PlaySound(unsigned int soundID, int a2, int flags, int a4);
};

struct TopicInfoStandin
{
    TESTopicInfo* GetTopicInfo(CompActor* speaker, CompActor* target);
};

struct TopicInfoQ
{
    TESQuest* GetQuest();
};

struct DialogueItemStandin
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    DialogueItemStandin(TESQuest* quest, TopicInfoStandin* topic, TopicInfoQ* info, CompActor* speaker);
    ~DialogueItemStandin();
    void Init();
    DialogueResponse* GetCurrentItem();
};

struct CompanionWheelStandin
{
    char unk00;
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
    CompActor* companion;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    SoundPlaybackHandle sound;

    void PlayTopicResponse(TopicInfoStandin* topic);
    void PlayResponse(BSStringT text, SoundPlaybackHandle snd);
};

// @fnv 0x007573d0
void CompanionWheelStandin::PlayTopicResponse(TopicInfoStandin* topic)
{
    TopicInfoQ* info6 = 0;
    CompActor* playerB = (CompActor*)g_thePlayer;
    CompActor* speaker = companion;
    if (topic)
        info6 = (TopicInfoQ*)topic->GetTopicInfo(speaker, playerB);
    if (info6)
    {
        DialogueItemStandin itemB(info6->GetQuest(), topic, info6, speaker);
        itemB.Init();
        DialogueResponse* response2 = itemB.GetCurrentItem();
        if (response2)
        {
            if (response2->GetSoundByEditorID())
            {
                unsigned int soundID3 = response2->GetSoundByEditorID()->GetSoundID();
                sound = speaker->PlaySound(soundID3, 0, 0x102, 1);
            }
            else
            {
                float duration = speaker->Speak(response2->GetVoicePath(&sound)->CStr(), response2->GetFlags(),
                                                response2->GetSoundID(), response2->GetText().GetLength(),
                                                response2->GetEmotionType(), response2->GetEmotionValue(),
                                                (CompActor*)g_thePlayer, 1, 1, 0, 0, 1);
            }
            PlayResponse(response2->GetText(), sound);
        }
    }
}

struct CStringArg_757690
{
    unsigned data;
    unsigned length;
    ~CStringArg_757690();
    unsigned __thiscall FUN_004048e0();
    int __thiscall FUN_00559450();
    int __thiscall FUN_00559450(int);
};
struct CValueArg_757690
{
    unsigned value;
    unsigned kind;
    unsigned other;
    ~CValueArg_757690();
    int __thiscall FUN_00ad8b30();
};
struct CWheelItem_757690
{
    void __thiscall FUN_00a01350(int id, int value);
};
struct CRelatedActor_757690
{
    bool __thiscall FUN_008c1bc0();
};
struct CInterface_757690
{
    unsigned char* __thiscall FUN_00408d60();
};
struct CRandom_757690
{
    float* __thiscall FUN_00403e20();
};
extern CInterface_757690 DAT_011d8928;
extern CRandom_757690 DAT_011d2178;
extern double DAT_01012060;
extern double DAT_01017b70;
unsigned __cdecl FUN_00ec6130(int);
unsigned __cdecl FUN_00457fe0();
struct CWheelMenu_757690
{
    void __thiscall SetItemTextAndValue(CStringArg_757690 text, CValueArg_757690 value);
};
// @fnv 0x00757690
void __thiscall CWheelMenu_757690::SetItemTextAndValue(CStringArg_757690 text, CValueArg_757690 value)
{
    float shift = 0.0f;
    if (text.FUN_004048e0() > 0)
    {
        if (*DAT_011d8928.FUN_00408d60() || (*(CRelatedActor_757690**)((char*)this + 0x68) != 0 &&
                                             (*(CRelatedActor_757690**)((char*)this + 0x68))->FUN_008c1bc0()))
        {
            if (*(CWheelItem_757690**)((char*)this + 0x58))
            {
                (*(CWheelItem_757690**)((char*)this + 0x58))->FUN_00a01350(0xfc4, text.FUN_00559450(1));
            }
            shift = (float)value.FUN_00ad8b30();
            if (shift == DAT_01012060)
            {
                shift =
                    (float)((double)FUN_00ec6130(text.FUN_00559450()) * (*DAT_011d2178.FUN_00403e20()) * DAT_01017b70);
            }
            *(unsigned*)((char*)this + 0x78) = (unsigned)((double)FUN_00457fe0() + shift);
        }
    }
}

namespace ScriptAnimation {
struct Reference;
struct Actor;
struct Idle;
struct Process;
struct Sequence;
struct ResultList
{
    int head, tail, count;
    ~ResultList();
    void FUN_00ad8e60(void (*)(unsigned int), unsigned int);
};
void FUN_005790f0(unsigned int);
struct Sequence
{
    unsigned int FUN_0084e3a0();
    void FUN_0083c7b0();
    int FUN_0083c820();
    void FUN_0083c850(int);
    ~Sequence();
};
struct Idle
{
    Sequence* FUN_0061b320(Reference*, int, int, int, int);
};
struct Reference
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~Reference();
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
    virtual bool IsSpecial();
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
    virtual ResultList Play(Idle*, Reference*, bool, bool, int, int, bool);
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
    virtual void* GetNode();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void* GetParent();
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
    virtual bool IsDead(int);
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
    virtual ResultList PlayActor(Idle*, Actor*, bool, bool, int, int);
    void FUN_0057ad20(Idle*);
    unsigned int FUN_0084e3a0();
    void FUN_0057ace0(unsigned int);
    Reference* FUN_005e3fa0();
    void FUN_00484490();
    void FUN_00575690(void*);
    void FUN_00575830(void*);
};
struct Process
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
    virtual void Clear(int);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void Reset();
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
    virtual void Update();
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
    virtual void Play(Actor*, Idle*, bool, int, int, int);
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
    virtual void SetAlert(int);
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
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void RestoreState(int);
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void SetState(int);
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual int GetState(int);
    int FUN_0045cd60();
};
struct Actor : Reference
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
    float animationTime;
    Process* FUN_008d8520();
    int FUN_00931850();
    bool FUN_0094df60();
    bool FUN_0087f3d0();
    int FUN_004f8960();
    unsigned int FUN_005d43c0();
};
extern Actor* DAT_011dea3c;
struct Setting
{
    const int* FUN_0043d4d0();
    void FUN_0045ce80(int);
};
extern Setting DAT_011cd378;
extern const float DAT_01012054;
extern const char DAT_011846d4, DAT_011841cc;
Actor* FUN_00ec43fb(Reference*, int, const void*, const void*, int);
void FUN_005ac750(Idle*, unsigned int, int);
Reference* FUN_00564480(int, int);
bool ExtractArgs(void*, void*, void*, Reference*, void*, void*, void*, Idle**, int*, void**, int*, int*);
// Plays an idle animation on the source actor or reference, choosing the sequence and dispatching play events, then restores the previous setting value.
// @fnv 0x005c8a50
bool FUN_005c8a50(void* paramInfo, void* scriptData, Reference* source, void* containing, void* script, void* locals,
                  double* result, void* offset)
{
    *result = 0.0;
    Idle* idleVal = 0;
    int force = 0;
    void* object4 = 0;
    int immediateA = 0;
    int _usePriority = 0;
    if (!ExtractArgs(paramInfo, scriptData, offset, source, containing, script, locals, &idleVal, &force, &object4,
                      &immediateA, &_usePriority))
        return false;
    bool forceFlag4 = false;
    bool immediateFlag4 = false;
    bool priorityFlag = false;
    if (immediateA)
        immediateFlag4 = true;
    if (force > 0)
        forceFlag4 = true;
    if (_usePriority > 0)
        priorityFlag = true;
    Actor* actor = FUN_00ec43fb(source, 0, &DAT_011841cc, &DAT_011846d4, 0);
    int previous = *DAT_011cd378.FUN_0043d4d0();
    DAT_011cd378.FUN_0045ce80(0x7fffffff);
    if (idleVal)
    {
        if (actor)
        {
            if (actor->FUN_008d8520() && !actor->IsDead(1))
            {
                actor->animationTime = DAT_01012054;
                actor->FUN_008d8520()->SetAlert(0);
                actor->FUN_008d8520()->Reset();
                if (!actor->FUN_00931850())
                {
                    int state = actor->FUN_008d8520()->GetState(2);
                    actor->FUN_008d8520()->SetState(0);
                    actor->FUN_008d8520()->RestoreState(state);
                    actor->FUN_008d8520()->Update();
                }
                else if (immediateA)
                {
                    actor->FUN_0057ad20(idleVal);
                    Sequence* chosen = idleVal->FUN_0061b320(actor, 0, 0, 0, 0);
                    if (chosen)
                        source->FUN_0057ace0(chosen->FUN_0084e3a0());
                    ResultList events = actor->PlayActor(idleVal, actor, immediateFlag4, priorityFlag, 0, 0);
                    events.FUN_00ad8e60(FUN_005790f0, source->FUN_0084e3a0());
                    return true;
                }
                if (DAT_011dea3c->FUN_0094df60() || actor->FUN_008d8520()->FUN_0045cd60() != 0 ||
                    (actor->FUN_0087f3d0() && actor->FUN_004f8960() == 6))
                {
                    Sequence* selected = idleVal->FUN_0061b320(actor, 0, 0, 0, 1);
                    if (selected)
                    {
                        selected->FUN_0083c7b0();
                        int unused = selected->FUN_0083c820();
                        selected->FUN_0083c850(0);
                        selected->FUN_0083c850(1);
                        FUN_005ac750(idleVal, actor->FUN_005d43c0(), 0x40000);
                        delete selected;
                    }
                }
                else
                    actor->FUN_008d8520()->Play(actor, idleVal, forceFlag4, 0, 1, 1);
            }
            else if (actor->FUN_008d8520())
            {
                FUN_005ac750(idleVal, actor->FUN_005d43c0(), 0x40000);
                actor->FUN_008d8520()->Clear(0);
            }
        }
        else if (source && object4)
        {
            Reference* created = FUN_00564480(59, 0);
            created->FUN_00484490();
            created->FUN_00575690(object4);
            created->FUN_00575830(source->GetParent());
            source->FUN_0057ad20(idleVal);
            Sequence* chosen2 = idleVal->FUN_0061b320(created, 0, 0, 0, 0);
            if (chosen2)
                source->FUN_0057ace0(chosen2->FUN_0084e3a0());
            ResultList events7 = created->Play(idleVal, created, immediateFlag4, priorityFlag, 0, 0, forceFlag4);
            events7.FUN_00ad8e60(FUN_005790f0, source->FUN_0084e3a0());
            delete created;
        }
        else if (source->GetNode() || (source->IsSpecial() && source->FUN_005e3fa0()->GetNode()))
        {
            source->FUN_0057ad20(idleVal);
            Sequence* chosen3 = idleVal->FUN_0061b320(source, 0, 0, 0, 0);
            if (chosen3)
                source->FUN_0057ace0(chosen3->FUN_0084e3a0());
            ResultList events3 = source->Play(idleVal, 0, immediateFlag4, priorityFlag, 0, 0, forceFlag4);
            events3.FUN_00ad8e60(FUN_005790f0, source->FUN_0084e3a0());
        }
    }
    DAT_011cd378.FUN_0045ce80(previous);
    return true;
}
}

class Tile755
{
  public:
    void SetInt(int m_iValueId, int iValue);
};

class Fader755
{
  public:
    void Start(int m_iPayloadInteger);
};

class Menu755
{
  public:
    Tile755* GetTile();
    void Close();

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
    Fader755 m_kFader;
};

class SaveLoad755
{
  public:
    bool IsLoading();
};

class Manager755
{
  public:
    void Refresh();
};

extern Menu755* g_pkMenu755;
extern SaveLoad755* g_pkSaveLoad755;
extern Manager755 g_kManager755;

// If the menu exists, optionally starts its fader, refreshes the manager when not loading, sets tile 0x1772 to 1 and closes the menu.
// @fnv 0x00755270
void __cdecl CloseMenuAndRefresh(bool bFade)
{
    if (g_pkMenu755)
    {
        if (bFade)
            g_pkMenu755->m_kFader.Start(0x64);
        if (!g_pkSaveLoad755->IsLoading())
            g_kManager755.Refresh();
        g_pkMenu755->GetTile()->SetInt(0x1772, 1);
        g_pkMenu755->Close();
    }
}

struct Tile_Set_Helper
{
    void Set(int, int);
};
struct ScriptTile256
{
    void Set(const char*, double);
};
struct MenuGlobal256
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
    ScriptTile256* script;
};
struct Wheel256
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
    Tile_Set_Helper* tile;
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
    unsigned char unk6c;
    bool aggressive;
    void PlayTopicResponse(TESTopic*);
    void RunTopicResultScripts(TESTopic*);
    void ToggleAggressive();
};
// Flips the aggressive flag, applies the matching FollowersTacticsCombat topic, updates the FollowerSwitchAggressive script value and sets tile 0x100f.
// @fnv 0x007561b0
void Wheel256::ToggleAggressive()
{
    aggressive = !aggressive;
    if (aggressive)
    {
        TESTopic* pAggressiveTopic =
            dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID("FollowersTacticsCombatAggressive"));
        PlayTopicResponse(pAggressiveTopic);
        RunTopicResultScripts(pAggressiveTopic);
    }
    else
    {
        TESTopic* pPassiveTopic =
            dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID("FollowersTacticsCombatPassive"));
        PlayTopicResponse(pPassiveTopic);
        RunTopicResultScripts(pPassiveTopic);
    }
    reinterpret_cast<MenuGlobal256*>(DAT_011d92b8)->script->Set("FollowerSwitchAggressive", aggressive ? 1.0f : 0.0f);
    if (tile)
        tile->Set(0x100f, aggressive);
}

class TESBoundObject : public TESForm
{
};
class AlchemyItem : public TESBoundObject
{
};
struct HealingExtra
{
    int unk00;
};
struct HealingExtraList
{
    HealingExtra*& FUN_006815c0();
};
struct HealingInventoryEntry
{
    HealingExtraList* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
    void* FUN_004459e0(unsigned int);
};
struct HealingActorBase
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
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void RemoveItem(void*, HealingExtra*, int, int, int, int, int, int, int, int);
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
};
struct HealingActorValues
{
    int unk00;
};
struct HealingActor : HealingActorBase, HealingActorValues
{
    float GetHealthFraction();
    HealingInventoryEntry* FUN_00576260(void*, int);
    void EquipItemWithCaster(void*, HealingExtra*, int);
    void FUN_008c3c40(int, int);
    void FUN_0088b740(int, float);
};
extern HealingActor* DAT_011dea3c;
extern char DAT_01183108, DAT_01183028, DAT_011830cc;
extern double DAT_01012060, DAT_01012070;
extern float DAT_01013974;
TESForm* FUN_0058db10(int);
void* FUN_00ec43fb(void*, int, void*, void*, int);
float FUN_00646800(HealingActorValues*, int, int);
void* FUN_008d5910(int);
struct CompanionHealingMenu
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
    HealingActor* companion;
    void PlayTopicResponse(void*);
    void HealCompanion();
};
// @fnv 0x00756490
void CompanionHealingMenu::HealCompanion()
{
    if (companion && DAT_011dea3c)
    {
        TESBoundObject* item = dynamic_cast<TESBoundObject*>(FUN_0058db10(0));
        if (item)
        {
            HealingInventoryEntry* entry = DAT_011dea3c->FUN_00576260(item, 0);
            if (entry)
            {
                float healthX = companion->GetHealthFraction();
                int crippled = 0;
                float leftArm = FUN_00646800(companion, 27, 0);
                if (leftArm == DAT_01012060)
                    ++crippled;
                float _leftLeg = FUN_00646800(companion, 29, 0);
                if (_leftLeg == DAT_01012060)
                    ++crippled;
                float rightLeg = FUN_00646800(companion, 30, 0);
                if (rightLeg == DAT_01012060)
                    ++crippled;
                float rightArmX = FUN_00646800(companion, 28, 0);
                if (rightArmX == DAT_01012060)
                    ++crippled;
                float head_3 = FUN_00646800(companion, 25, 0);
                if (head_3 == DAT_01012060)
                    ++crippled;
                float torso = FUN_00646800(companion, 26, 0);
                if (torso == DAT_01012060)
                    ++crippled;
                if (healthX < DAT_01012070 || crippled > 0)
                {
                    if (healthX < DAT_01012070)
                        companion->EquipItemWithCaster(
                            dynamic_cast<AlchemyItem*>(entry->FUN_0044ddc0()),
                            entry->FUN_00559450() ? entry->FUN_00559450()->FUN_006815c0() : 0, 1);
                    DAT_011dea3c->RemoveItem(entry->FUN_0044ddc0(),
                                             entry->FUN_00559450() ? entry->FUN_00559450()->FUN_006815c0() : 0, 1, 0, 0,
                                             0, 0, 0, 1, 0);
                    companion->FUN_008c3c40(0, 1);
                    companion->FUN_0088b740(31, DAT_01013974);
                    companion->FUN_0088b740(29, DAT_01013974);
                    companion->FUN_0088b740(30, DAT_01013974);
                    companion->FUN_0088b740(27, DAT_01013974);
                    companion->FUN_0088b740(28, DAT_01013974);
                    companion->FUN_0088b740(26, DAT_01013974);
                    companion->FUN_0088b740(25, DAT_01013974);
                    void* topic = FUN_008d5910(13);
                    PlayTopicResponse(topic);
                }
                {
                    HealingInventoryEntry* deleteEntry = entry;
                    HealingInventoryEntry* deleting2 = deleteEntry;
                    deleting2 ? deleting2->FUN_004459e0(1) : 0;
                }
            }
        }
    }
}

extern const char str_01019f08[];
// 0x00755dc0  unit_929b7ab49562.cpp  /MT /Od /Oy- /GS /EHsc /Gy
extern "C" int sprintf_s(char* buf, unsigned int size, const char* fmt, ...);

struct Setting755d
{
    const char* String();
};
extern Setting755d DAT_011d300c;
extern Setting755d DAT_011d2568;
extern Setting755d DAT_011d1e60;

struct TileStr755d
{
    void SetString(int id, const char* text, bool flag);
};

struct Cast755d
{
    const char* GetTargetFullName();
};

struct AVO755d
{
    virtual int v0(int);
    virtual float v1(int);
    virtual float v2(int);
    virtual float v3(int);
};

struct ActorBase755d
{
    virtual void* v0(int);
    virtual void* v1(int);
    virtual void* v2(int);
    virtual void* v3(int);
    virtual void* v4(int);
    virtual void* v5(int);
    virtual void* v6(int);
    virtual void* v7(int);
    virtual void* v8(int);
    virtual void* v9(int);
    virtual void* v10(int);
    virtual void* v11(int);
    virtual void* v12(int);
    virtual void* v13(int);
    virtual void* v14(int);
    virtual void* v15(int);
    virtual void* v16(int);
    virtual void* v17(int);
    virtual void* v18(int);
    virtual void* v19(int);
    virtual void* v20(int);
    virtual void* v21(int);
    virtual void* v22(int);
    virtual void* v23(int);
    virtual void* v24(int);
    virtual void* v25(int);
    virtual void* v26(int);
    virtual void* v27(int);
    virtual void* v28(int);
    virtual void* v29(int);
    virtual void* v30(int);
    virtual void* v31(int);
    virtual void* v32(int);
    virtual void* v33(int);
    virtual void* v34(int);
    virtual void* v35(int);
    virtual void* v36(int);
    virtual void* v37(int);
    virtual void* v38(int);
    virtual void* v39(int);
    virtual void* v40(int);
    virtual void* v41(int);
    virtual void* v42(int);
    virtual void* v43(int);
    virtual void* v44(int);
    virtual void* v45(int);
    virtual void* v46(int);
    virtual void* v47(int);
    virtual void* v48(int);
    virtual void* v49(int);
    virtual void* v50(int);
    virtual void* v51(int);
    virtual void* v52(int);
    virtual void* v53(int);
    virtual void* v54(int);
    virtual void* v55(int);
    virtual void* v56(int);
    virtual void* v57(int);
    virtual void* v58(int);
    virtual void* v59(int);
    virtual void* v60(int);
    virtual void* v61(int);
    virtual void* v62(int);
    virtual void* v63(int);
    virtual void* v64(int);
    virtual void* v65(int);
    virtual void* v66(int);
    virtual void* v67(int);
    virtual void* v68(int);
    virtual void* v69(int);
    virtual void* v70(int);
    virtual void* v71(int);
    virtual void* v72(int);
    virtual void* v73(int);
    virtual void* v74(int);
    virtual void* v75(int);
    virtual void* v76(int);
    virtual void* v77(int);
    virtual void* v78(int);
    virtual void* v79(int);
    virtual void* v80(int);
    virtual void* v81(int);
    virtual void* v82(int);
    virtual void* v83(int);
    virtual void* v84(int);
    virtual void* v85(int);
    virtual void* v86(int);
    virtual void* v87(int);
    virtual void* v88(int);
    virtual void* v89(int);
    virtual void* v90(int);
    virtual void* v91(int);
    virtual void* v92(int);
    virtual void* v93(int);
    virtual void* v94(int);
    virtual void* v95(int);
    virtual void* v96(int);
    virtual void* v97(int);
    virtual void* v98(int);
    virtual void* v99(int);
    virtual void* v100(int);
    virtual void* v101(int);
    virtual void* v102(int);
    virtual void* v103(int);
    virtual void* v104(int);
    virtual void* v105(int);
    virtual void* v106(int);
    virtual void* v107(int);
    virtual void* v108(int);
    virtual void* v109(int);
    virtual void* v110(int);
    virtual void* v111(int);
    virtual void* v112(int);
    virtual void* v113(int);
    virtual void* v114(int);
    virtual void* v115(int);
    virtual void* v116(int);
    virtual void* v117(int);
    virtual void* v118(int);
    virtual void* v119(int);
    virtual void* v120(int);
    virtual void* v121(int);
    virtual void* v122(int);
    virtual void* v123(int);
    virtual void* v124(int);
    virtual void* v125(int);
    virtual void* v126(int);
    virtual void* v127(int);
    virtual void* v128(int);
    virtual void* v129(int);
    virtual void* v130(int);
    virtual void* v131(int);
    virtual void* v132(int);
    virtual void* v133(int);
    virtual void* v134(int);
    virtual void* v135(int);
    virtual void* v136(int);
    virtual void* v137(int);
    virtual void* v138(int);
    virtual void* v139(int);
    virtual void* v140(int);
    virtual void* v141(int);
    virtual void* v142(int);
    virtual void* v143(int);
    virtual void* v144(int);
    virtual void* v145(int);
    virtual void* v146(int);
    virtual void* v147(int);
    virtual void* v148(int);
    virtual void* v149(int);
    virtual void* v150(int);
    virtual void* v151(int);
    virtual void* v152(int);
    virtual void* v153(int);
    virtual void* v154(int);
    virtual void* v155(int);
    virtual void* v156(int);
    virtual void* v157(int);
    virtual void* v158(int);
    virtual void* v159(int);
    virtual void* v160(int);
    virtual void* v161(int);
    virtual void* v162(int);
    virtual void* v163(int);
    virtual void* v164(int);
    virtual void* v165(int);
    virtual void* v166(int);
    virtual void* v167(int);
    virtual void* v168(int);
    virtual void* v169(int);
    virtual void* v170(int);
    virtual void* v171(int);
    virtual void* v172(int);
    virtual void* v173(int);
    virtual void* v174(int);
    virtual void* v175(int);
    virtual void* v176(int);
    virtual void* v177(int);
    virtual void* v178(int);
    virtual void* v179(int);
    virtual void* v180(int);
    virtual void* v181(int);
    virtual void* v182(int);
    virtual void* v183(int);
    virtual void* v184(int);
    virtual void* v185(int);
    virtual void* v186(int);
    virtual void* v187(int);
    virtual void* v188(int);
    virtual void* v189(int);
    virtual void* v190(int);
    virtual void* v191(int);
    virtual void* v192(int);
    virtual void* v193(int);
    virtual void* v194(int);
    virtual void* v195(int);
    virtual void* v196(int);
    virtual void* v197(int);
    virtual void* v198(int);
    virtual void* v199(int);
    virtual void* v200(int);
    virtual void* v201(int);
    virtual void* v202(int);
    virtual void* v203(int);
    virtual void* v204(int);
    virtual void* v205(int);
    virtual void* v206(int);
    virtual void* v207(int);
    virtual void* v208(int);
    virtual void* v209(int);
    virtual void* v210(int);
    virtual void* v211(int);
    virtual void* v212(int);
    virtual void* v213(int);
    virtual void* v214(int);
    virtual void* v215(int);
    virtual void* v216(int);
    virtual void* v217(int);
    virtual void* v218(int);
    virtual void* v219(int);
    virtual void* v220(int);
    virtual void* v221(int);
    virtual void* v222(int);
    virtual void* v223(int);
    virtual void* v224(int);
    virtual void* v225(int);
    virtual void* v226(int);
    virtual void* v227(int);
    virtual void* v228(int);
    virtual void* v229(int);
    virtual void* v230(int);
    virtual void* v231(int);
    virtual void* v232(int);
    virtual void* v233(int);
    virtual void* v234(int);
    virtual void* v235(int);
    virtual void* v236(int);
    virtual void* v237(int);
    virtual void* v238(int);
    virtual void* v239(int);
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
};

struct Actor755d : ActorBase755d, AVO755d
{
    float FUN_008a0c20();
};

float __cdecl FUN_008a0cd0(AVO755d* owner, int value);

struct InvEntry755d
{
    int FUN_00726070();
    int FUN_004459e0(unsigned int flags);
};

struct Wheel755d
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
    TileStr755d* tile;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    Actor755d* actor;
    void FUN_00755dc0(int mode);
};

// Builds a string for selected modes and writes it to the tile's 0xfc4 string field.
// @fnv 0x00755dc0
void Wheel755d::FUN_00755dc0(int mode)
{
    char rltxt[260];
    int b;
    int rlBTmp;
    int rlV;
    TESBoundObject* rlObj;
    {
        InvEntry755d* _rlQ1;
        InvEntry755d* rlP1;
        InvEntry755d* rlQ2;
        Cast755d* rlQTmp;
        int rlA5;
        int a2;
        rltxt[0] = 0;
        switch (mode)
        {
        case 1:
            if (actor)
            {
                b = (int)(*(AVO755d*)((char*)actor + sizeof(ActorBase755d))).v3(0x10);
                rlBTmp = (*(AVO755d*)((char*)actor + sizeof(ActorBase755d))).v0(0x10);
                rlV = 0;
                rlObj = dynamic_cast<TESBoundObject*>(FUN_0058db10(0));
                if (rlObj)
                {
                    _rlQ1 = (InvEntry755d*)DAT_011dea3c->FUN_00576260(rlObj, 0);
                    if (_rlQ1)
                    {
                        rlV = _rlQ1->FUN_00726070();
                        rlP1 = _rlQ1;
                        rlQ2 = rlP1;
                        rlQ2 ? rlQ2->FUN_004459e0(1) : 0;
                    }
                }
                sprintf_s(rltxt, 260, "%s  %d/%d\n%s  %d", DAT_011d300c.String(), b, rlBTmp, DAT_011d2568.String(),
                          rlV);
            }
            break;
        case 7:
            if (actor)
            {
                rlQTmp = (Cast755d*)actor->v239(6);
                if (rlQTmp)
                {
                    sprintf_s(rltxt, 260, str_01019f08, rlQTmp->GetTargetFullName());
                }
            }
            break;
        case 6:
            if (actor)
            {
                rlA5 = (int)FUN_008a0cd0(actor, 0xd);
                a2 = (int)actor->FUN_008a0c20();
                sprintf_s(rltxt, 260, "%s  %d/%d", DAT_011d1e60.String(), rlA5, a2);
            }
            break;
        }
    }
    if (tile)
    {
        tile->SetString(0xfc4, rltxt, true);
    }
}

struct BSSoundHandleEx
{
    unsigned int soundID;
    bool assumeSuccess;
    unsigned int state;
    ~BSSoundHandleEx();
    bool Play(bool immediate);
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
extern "C" BSAudio* __cdecl FUN_00453a70();
extern MessageSetting DAT_011d33fc;
extern MessageSetting DAT_011d4288;
extern MessageSetting DAT_011d2d90;
extern MessageSetting DAT_011d4540;
extern MessageSetting DAT_011d288c;
extern MessageSetting DAT_011d40cc;
extern MessageSetting DAT_011d4fa8;
extern MessageSetting DAT_011d2268;
extern MessageSetting DAT_011d4660;
extern MessageSetting DAT_011d2c88;
extern MessageSetting DAT_011d34c8;
extern MessageSetting DAT_011d3ba4;
extern MessageSetting DAT_011d2598;
struct WheelSelection
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
    Tile_Set_Helper* tiles[16];
    CompActor* companion;
    unsigned char flag6c;
    unsigned char flag6d;
    unsigned char flag6e;
    unsigned char flag6f;
    int selected;
    void SelectTile(int next, bool force);
    void SetTileText(const char*);
    void FUN_00755dc0(int);
};

// Selects a tile in the wheel, updating highlight state, tile text, and playing a UI scroll sound.
// @fnv 0x007557d0
void WheelSelection::SelectTile(int next, bool force)
{
    if (!force && selected == next)
        return;
    FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyScroll", 0x121).Play(false);
    if (selected != -1 && tiles[selected])
        tiles[selected]->Set(0x100e, 0);
    switch (selected)
    {
    case 2:
        if (tiles[selected])
            tiles[selected]->Set(0x100f, !flag6f);
        break;
    case 0:
        if (tiles[selected])
            tiles[selected]->Set(0x100f, flag6d);
        break;
    case 7:
        if (tiles[selected])
            tiles[selected]->Set(0x100f, flag6e);
        break;
    case 5:
        if (tiles[selected])
            tiles[selected]->Set(0x100f, flag6c);
        break;
    }
    selected = next;
    if (selected != -1 && tiles[selected])
        tiles[selected]->Set(0x100e, 1);
    switch (next)
    {
    case 11:
        SetTileText(DAT_011d33fc.FUN_00403df0());
        break;
    case 3:
        SetTileText(DAT_011d4288.FUN_00403df0());
        break;
    case 2:
        if (flag6f)
            SetTileText(DAT_011d2d90.FUN_00403df0());
        else
            SetTileText(DAT_011d4540.FUN_00403df0());
        if (tiles[next])
            tiles[next]->Set(0x100f, flag6f);
        break;
    case 4:
        SetTileText(DAT_011d288c.FUN_00403df0());
        break;
    case 0:
        if (flag6d)
            SetTileText(DAT_011d40cc.FUN_00403df0());
        else
            SetTileText(DAT_011d4fa8.FUN_00403df0());
        if (tiles[next])
            tiles[next]->Set(0x100f, !flag6d);
        break;
    case 1:
        SetTileText(DAT_011d2268.FUN_00403df0());
        break;
    case 7:
        if (flag6e)
            SetTileText(DAT_011d4660.FUN_00403df0());
        else
            SetTileText(DAT_011d2c88.FUN_00403df0());
        if (tiles[next])
            tiles[next]->Set(0x100f, !flag6e);
        break;
    case 6:
        SetTileText(DAT_011d34c8.FUN_00403df0());
        break;
    case 5:
        if (flag6c)
            SetTileText(DAT_011d3ba4.FUN_00403df0());
        else
            SetTileText(DAT_011d2598.FUN_00403df0());
        if (tiles[next])
            tiles[next]->Set(0x100f, !flag6c);
        break;
    default:
        SetTileText($SG3295);
        break;
    }
    FUN_00755dc0(selected);
}

struct FUN_007563a0_shell
{
    char _pad[0x6f];
    bool m_bTopicResponsePlayed;
    void __thiscall ToggleFollowerWait();
    void __thiscall PlayTopicResponse(TESTopic*);
    void __thiscall RunTopicResultScripts(TESTopic*);
};
// Toggles m_bTopicResponsePlayed, plays the matching follower topic, and updates the tile set helper state.
// @fnv 0x007563a0
void __thiscall FUN_007563a0_shell::ToggleFollowerWait()
{
    bool bSuccess = false;
    m_bTopicResponsePlayed = !m_bTopicResponsePlayed;
    if (!m_bTopicResponsePlayed)
    {
        TESTopic* pRelatedTopic = dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID("FollowersWait"));
        PlayTopicResponse(pRelatedTopic);
        RunTopicResultScripts(pRelatedTopic);
        bSuccess = true;
    }
    else
    {
        TESTopic* pRelatedTopic = dynamic_cast<TESTopic*>(TESForm::LookupFormByEditorID("FollowersLetsGo"));
        PlayTopicResponse(pRelatedTopic);
        RunTopicResultScripts(pRelatedTopic);
        bSuccess = true;
    }
    if (bSuccess && *(Tile_Set_Helper**)((char*)this + 0x30))
        (*(Tile_Set_Helper**)((char*)this + 0x30))->Set(0x100f, !m_bTopicResponsePlayed);
}
