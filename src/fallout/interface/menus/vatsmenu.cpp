// fallout/interface/menus/vatsmenu.cpp: VATSMenuX, VATSMenu, Vec2Tmp, StandIn and more (58 functions)

#include "vatsmenu_decls.h"
// Returns the difference between the result of the called function and the tile's float value at numFiltered.
// @fnv 0x00726660
unsigned int VATSMenu::Create()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return GetSelectedTargetIndex() - (unsigned int)tile->GetFloat(numFiltered);
}

struct ItemListElement;
struct ItemList
{
    ItemListElement** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ItemListContainer
{
    char pad[8];
    ItemList items;
    ~ItemListContainer();
};
struct TargetList
{
    ItemListContainer** FUN_006815c0();
    void FUN_0063f7b0();
};
struct GlobalObject2_0096a2d0
{
    int x;
};
extern GlobalObject2_0096a2d0 g_011db150;

// Deletes every item in each target's item list, then deletes each target, until the global target list is empty.
// @fnv 0x007f6920
void FUN_007f6920()
{
    ItemListElement* pitem;
    ItemListContainer* ptarg;
    while (*((TargetList*)&g_011db150)->FUN_006815c0())
    {
        ptarg = *((TargetList*)&g_011db150)->FUN_006815c0();
        while (*((ItemList*)((char*)ptarg + 8))->FUN_006815c0())
        {
            pitem = *((ItemList*)((char*)ptarg + 8))->FUN_006815c0();
            delete pitem;
            ((ItemList*)((char*)ptarg + 8))->FUN_0063f7b0();
        }
        delete ptarg;
        ((TargetList*)&g_011db150)->FUN_0063f7b0();
    }
}

struct FUN_007ebd30_This
{
    char pad[0x374];
    float fValue;
    float __thiscall FUN_007ebd30();
};

// @fnv 0x007ebd30
float __thiscall FUN_007ebd30_This::FUN_007ebd30()
{
    return fValue;
}

extern int DAT_011db0d4;

// @fnv 0x007f3bd0
void __cdecl FUN_007f3bd0(int aiValue)
{
    if (DAT_011db0d4)
    {
        *(char*)(*(int*)(&DAT_011db0d4) + 0xf8) = (char)aiValue;
    }
}

namespace fnv_007f5280 {
extern int* DAT_011db0d4;

// Returns a pointer to the object at offset 0x11C of DAT_011db0d4 if it is non-null and its byte at 0x118 is set, otherwise null.
// @fnv 0x007f5280
void* __cdecl FUN_007f5280()
{
    void* v0;
    if (DAT_011db0d4 != 0 && *(reinterpret_cast<unsigned char*>(DAT_011db0d4) + 0x118) != 0)
    {
        v0 = reinterpret_cast<int*>(reinterpret_cast<char*>(DAT_011db0d4) + 0x11C);
    }
    else
    {
        v0 = 0;
    }
    return v0;
}
}  // namespace fnv_007f5280

struct ArrSI
{
    unsigned int GetFlags();
};
extern int DAT_011f2250;
struct Caller007efa10
{
    void __thiscall UpdateQueueEntry(int a1, int a2, int a3);
};
struct FUN_007ef710_This
{
    char _pad[0xF8];
    bool m_bFirstFlag;
    bool __thiscall HandleKey(int aiKey);
};
// @fnv 0x007ef710
bool __thiscall FUN_007ef710_This::HandleKey(int aiKey)
{
    if (aiKey == 0x42 || aiKey == 0x62)
    {
        if (((ArrSI*)&DAT_011f2250)->GetFlags() == 2 && m_bFirstFlag)
            ((Caller007efa10*)this)->UpdateQueueEntry(0, 0, 0);
        return true;
    }
    return false;
}

struct Tile;
struct FUN_0070ec70_This
{
    int __thiscall FUN_0070ec70();
};
void* __cdecl FUN_004b7210();
struct FUN_007ef760_Owner
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int, int);
    void __thiscall FUN_007ef760(int aiID, Tile* apTarget);
};
// Calls FUN_0070ec70 on the object from FUN_004b7210 and invokes vf3 with 2 if that value divided by -120 equals 1, otherwise 3.
// @fnv 0x007ef760
void __thiscall FUN_007ef760_Owner::FUN_007ef760(int aiID, Tile* apTarget)
{
    if (((FUN_0070ec70_This*)FUN_004b7210())->FUN_0070ec70() / -120 == 1)
        vf3(2, 0);
    else
        vf3(3, 0);
}

struct Vec2Tmp
{
    float x;
    float y;
    Vec2Tmp DivideBy(float) const;
};
// Returns a copy of this vector with x and y divided by scale.
// @fnv 0x007f2890
Vec2Tmp Vec2Tmp::DivideBy(float scale) const
{
    Vec2Tmp result = *this;
    result.x /= scale;
    result.y /= scale;
    return result;
}

struct TESObjectREFR
{
};
struct BSSimpleList
{
    bool FUN_008256d0();
    ItemListContainer** FUN_006815c0();
    BSSimpleList* FUN_00726070();
};
struct StandIn
{
    BSSimpleList* FindListEntryForTarget(TESObjectREFR* apTarget);
};
// Scans the g_011db150 list for the entry whose stored TESObjectREFR matches apTarget and returns it, or null if none matches.
// @fnv 0x007f3c90
BSSimpleList* StandIn::FindListEntryForTarget(TESObjectREFR* apTarget)
{
    BSSimpleList* piter;
    if (!apTarget)
        return 0;
    piter = (BSSimpleList*)&g_011db150;
    while (piter && !piter->FUN_008256d0())
    {
        if (*(TESObjectREFR**)(*piter->FUN_006815c0()) == apTarget)
            return piter;
        piter = piter->FUN_00726070();
    }
    return 0;
}

struct Tile;
struct Menu
{
    Tile* CreateTileFromTemplate(Tile*, char const*, Tile*);
};
void __cdecl _FNV_Warning(char const*);
void __cdecl _FUN_007037e0();
void __cdecl ShutdownVats();
// @fnv 0x007f4830
Tile* FUN_007f4830(Tile* apParent, char const* axName)
{
    Tile* ptile;
    if (DAT_011db0d4 == 0)
        return 0;
    ptile = ((Menu*)DAT_011db0d4)->CreateTileFromTemplate(apParent, axName, 0);
    if (ptile)
        return ptile;
    else
    {
        _FNV_Warning(
            "MENUS: VATS Menu Creation Failed... This likely means that the archives were not built and the xml doesn't match the code.");
        _FUN_007037e0();
        ShutdownVats();
    }
    return 0;
}

struct Tile;
Tile* __cdecl FindNamedTile(Tile*, char const*);
void __cdecl _FNV_Warning(char const*);
void __cdecl _FUN_007037e0();
void __cdecl ShutdownVats();
// @fnv 0x007f4890
Tile* __cdecl FUN_007f4890(Tile* a1, char const* a2)
{
    Tile* result = FindNamedTile(a1, a2);
    if (result != 0)
        return result;
    else
    {
        _FNV_Warning(
            "MENUS: VATS Menu Creation Failed... This likely means that the archives were not built and the xml doesn't match the code.");
        _FUN_007037e0();
        ShutdownVats();
    }
    return 0;
}

struct AnimIdle
{
    int GetSection();
};
class GameTimerRecord
{
    char _d;
};
extern GameTimerRecord g_timeGlobal;
struct DAT_Pointee_7f4bb0
{
    char pad[0x10F];
    unsigned char flag;
    char pad2[4];
    int t;
};
// Returns true when DAT_011db0d4 is set, its flag is set, and GetSection() minus its t field exceeds 500.
// @fnv 0x007f4bb0
bool FUN_007f4bb0()
{
    if (DAT_011db0d4 == 0)
        return false;
    if (((DAT_Pointee_7f4bb0*)DAT_011db0d4)->flag)
    {
        if ((unsigned int)(((AnimIdle*)&g_timeGlobal)->GetSection() - ((DAT_Pointee_7f4bb0*)DAT_011db0d4)->t) > 0x1F4)
            return true;
    }
    return false;
}

namespace fnv_007f4c00 {
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
struct DAT_Obj
{
    char pad[0x110];
    unsigned char b;
    char pad2[3];
    int v;
};
// Returns true when DAT_011db0d4 is set, its byte flag is nonzero, and the section from g_timeGlobal minus its v field exceeds 0x1f4.
// @fnv 0x007f4c00
bool FUN_007f4c00()
{
    if (DAT_011db0d4 == 0)
        return false;
    if (((DAT_Obj*)DAT_011db0d4)->b && (unsigned int)(g_timeGlobal.GetSection() - ((DAT_Obj*)DAT_011db0d4)->v) > 0x1f4)
        return true;
    return false;
}
}  // namespace fnv_007f4c00

struct Tile;
struct ListBox
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* v5(int);
    int GetFilteredCount(int);
    Tile* FUN_007f6fb0();
};
// @fnv 0x007f6fb0
Tile* ListBox::FUN_007f6fb0()
{
    return v5(GetFilteredCount(0) - 1);
}

struct FUN_007ebd10_This
{
    char pad[0x37c];
    float fValue;
    float FUN_007ebd10();
};

// @fnv 0x007ebd10
float FUN_007ebd10_This::FUN_007ebd10()
{
    return fValue;
}

struct FUN_007ef8b0_This
{
    char pad[0x10f];
    unsigned char flag;
    unsigned char pad2[4];
    int t;
    void __thiscall FUN_007ef8b0(int aiID, Tile* apTarget);
};
// For IDs 2 and 3, if the corresponding flag is unset, stores the current AnimIdle section into t and sets that flag.
// @fnv 0x007ef8b0
void __thiscall FUN_007ef8b0_This::FUN_007ef8b0(int aiID, Tile* apTarget)
{
    switch (aiID)
    {
    case 2:
        if (!flag)
        {
            t = ((AnimIdle*)&g_timeGlobal)->GetSection();
            flag = 1;
        }
        break;
    case 3:
        if (!pad2[0])
        {
            t = ((AnimIdle*)&g_timeGlobal)->GetSection();
            pad2[0] = 1;
        }
        break;
    }
}

struct FUN_007f4810_shell
{
    char pad[0x2b4];
    char byte_0x2b4;
    char __thiscall GetByteAtOffset();
};

// @fnv 0x007f4810
char __thiscall FUN_007f4810_shell::GetByteAtOffset()
{
    return byte_0x2b4;
}

struct FUN_007f5190_shell
{
    char pad[0x12c];
    unsigned int flags;
    bool IsFlag800Set() const;
};

// @fnv 0x007f5190
bool FUN_007f5190_shell::IsFlag800Set() const
{
    return (flags & 0x800) ? true : false;
}

struct SL
{
    SL();
};

struct FUN_007f6900_shell
{
    char pad[8];
    SL sl;
    FUN_007f6900_shell();
};

// @fnv 0x007f6900
FUN_007f6900_shell::FUN_007f6900_shell()
{}

struct GO
{
    void* p;
    GO& operator=(void*);
};
struct FUN_00800ed0_This
{
    char _pad[12];
    int cnt;
    int sel;
    struct Entry
    {
        int v;
        GO g;
    } arr[32];
    void FUN_00800ed0();
};
// Resets each of the cnt entries' value and pointer to zero, then sets cnt to 0 and sel to -1.
// @fnv 0x00800ed0
void FUN_00800ed0_This::FUN_00800ed0()
{
    for (int i = 0; i < cnt; ++i)
    {
        arr[i].v = 0;
        arr[i].g = 0;
    }
    cnt = 0;
    sel = -1;
}

void* __cdecl _FUN_004b7210();
bool __cdecl _FUN_004b71d0();
int __cdecl FUN_00717a40(int, int);
struct OSGlobals
{
    void* FUN_00877720();
};
struct InputManager
{
    int FUN_00a23a50(int, int);
};
struct HotkeyWheelDisplay
{
    int HandleHotkeyInput(int, int);
};
extern bool DAT_011db0b2;
extern bool DAT_011db0b3;
extern OSGlobals* g_osGlobals;

// @fnv 0x007eeb50
bool __cdecl FUN_007eeb50(int aiKey, bool abHeld, int aiEnabled)
{
    _FUN_004b7210();
    if (!_FUN_004b71d0())
    {
        void* pInput = g_osGlobals->FUN_00877720();
        {
            int iState = !abHeld;
            switch (aiKey)
            {
            case 1:
                return ((InputManager*)pInput)->FUN_00a23a50(0, iState) && aiEnabled;
            case 2:
                return ((HotkeyWheelDisplay*)pInput)->HandleHotkeyInput(0x13, iState) || DAT_011db0b2;
            case 3:
                return ((HotkeyWheelDisplay*)pInput)->HandleHotkeyInput(0x21, iState) || DAT_011db0b3;
            }
        }
        return false;
    }
    int iButton = 0xe;
    switch (aiKey)
    {
    case 2:
        iButton = 0xc;
        break;
    case 3:
        iButton = 0xb;
        break;
    }
    if (abHeld)
        return !FUN_00717a40(iButton, 1);
    else
        return FUN_00717a40(iButton, 1) == 2;
}

struct Actor;
extern Actor* DAT_011f21cc;
struct FUN_007f3cf0_This : StandIn
{
    char pad[0x100 - sizeof(Menu)];
    TESObjectREFR* m_pTargetChance;
    BSSimpleList* FindEntryForRef();
};
// @fnv 0x007f3cf0
BSSimpleList* FUN_007f3cf0_This::FindEntryForRef()
{
    BSSimpleList* ptarget = FindListEntryForTarget((TESObjectREFR*)DAT_011f21cc);
    BSSimpleList* piter = (BSSimpleList*)(void*)*(char**)(char*)ptarget->FUN_006815c0() + 8;
    while (piter && !piter->FUN_008256d0())
    {
        if ((TESObjectREFR*)piter->FUN_006815c0()[0] == m_pTargetChance)
            return piter;
        piter = piter->FUN_00726070();
    }
    return 0;
}

struct StartMenu
{
    char const* GetMenuTitle();
};

extern StartMenu* DAT_01183aa0[];

// @fnv 0x007f0360
char const* FUN_007f0360(int aiIndex)
{
    return DAT_01183aa0[aiIndex]->GetMenuTitle();
}

struct NiPoint3
{
    float x;
    float y;
    float z;

    void __thiscall _ref_006815c0();
};

struct NiAVObject
{
    NiPoint3 GetWorldTranslation();
};

struct BSFaceGenNiNode : public NiAVObject
{
    NiAVObject* GetAnimationData();
};

BSFaceGenNiNode* __cdecl FUN_0045c670();

struct FUN_005df510_shell
{
    void __thiscall FUN_005df510(unsigned int, float*);
};

struct FUN_007f51b0_shell
{
    void __thiscall FUN_007f51b0(FUN_005df510_shell*);
};

// @fnv 0x007f51b0
void __thiscall FUN_007f51b0_shell::FUN_007f51b0(FUN_005df510_shell* a1)
{
    NiPoint3 direction = FUN_0045c670()->GetAnimationData()->GetWorldTranslation();

    NiPoint3 result;
    result._ref_006815c0();

    result.x = direction.y * direction.y + direction.z * direction.z;
    result.y = -direction.x * direction.y;
    result.z = -direction.x * direction.z;
    a1->FUN_005df510(0, &result.x);

    result.x = -direction.x * direction.y;
    result.y = direction.x * direction.x + direction.z * direction.z;
    result.z = -direction.y * direction.z;
    a1->FUN_005df510(1, &result.x);

    result.x = -direction.x * direction.z;
    result.y = -direction.y * direction.z;
    result.z = direction.x * direction.x + direction.y * direction.y;
    a1->FUN_005df510(2, &result.x);
}

struct Pt
{
    float x;
    float y;
    float z;
    float Length() const;
};

struct P3 : Pt
{
    P3 operator-(P3 const&) const;
};

struct TESObjectWEAP
{
    int GetWeaponType();
};

struct A69C0Weapon
{
};

bool __fastcall A69C0IsMeleeWeapon(A69C0Weapon*);

struct Setting_S
{
    float* Float();
};

struct GameSettingCollection
{
};

template <class T> struct SettingT : Setting_S
{
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting546;

struct G2
{
    void AddHead(int*);
};

extern GlobalObject2_0096a2d0 g_011db124;

struct ActH2
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

    virtual P3* FUN_007f4f30_position();

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

    // Always returns true.
// @fnv 0x007f4f30
    virtual bool FUN_007f4f30_check()
    {
        return true;
    }

    void* GetActiveWeapon();
};

struct Sky : public ActH2
{
    TESObjectWEAP* FUN_00476c90();
};

struct FUN_00452370_shell : public Sky
{
    bool FUN_00452370() const;
};

struct Actor : public ActH2
{
};

extern Actor* _g_thePlayer;

int __fastcall FUN_00874480(char*);

bool __cdecl FUN_007f4f30(FUN_00452370_shell* apTarget)
{
    float fDistance = (*_g_thePlayer->FUN_007f4f30_position() - *apTarget->FUN_007f4f30_position()).Length();

    if (_g_thePlayer->GetActiveWeapon() &&
        A69C0IsMeleeWeapon(reinterpret_cast<A69C0Weapon*>(_g_thePlayer->GetActiveWeapon())) &&
        fDistance > *originalRuntimeFloatSetting546.Float())
    {
        return false;
    }

    if (apTarget->FUN_00452370() && apTarget->FUN_007f4f30_check())
    {
        {
            FUN_00452370_shell* target = apTarget;

            if (target->FUN_00476c90() &&
                (target->FUN_00476c90()->GetWeaponType() == 11 || target->FUN_00476c90()->GetWeaponType() == 12))
            {
                return false;
            }

            if (FUN_00874480(reinterpret_cast<char*>(target)) != reinterpret_cast<int>(_g_thePlayer))
            {
                reinterpret_cast<G2*>(&g_011db124)->AddHead(reinterpret_cast<int*>(&apTarget));
            }
        }
    }

    return false;
}

namespace fnv_007f5050 {
struct TESCreature
{
    float FUN_00821640();
};

struct TESObjectWEAP
{
    bool GetIsAutomaticWeapon();
    unsigned char GetAmmoPerShot();
};

struct InventoryStackRecord : ArrSI
{
    bool SetEquipmentState(int);
};

struct FUN_00646020_shell
{
    float FUN_00646020(bool);
};

struct TES
{
    void* GetLogDate();
};

struct LogDateOwner
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
    virtual InventoryStackRecord* v82();
};

extern TES* _g_thePlayer;

struct ActionPoints
{
    enum Action
    {
        Action_Invalid = 0
    };
};

struct Setting_S
{
    float* Float();
};

struct GameSettingCollection
{
};

template <class T> struct SettingT : Setting_S
{
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting539;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting538;

// Computes the number of shots per burst from the equipped weapon's ammo per shot, automatic flag and burst time settings, returning at least 1.
// @fnv 0x007f5050
unsigned char __cdecl GetBurstShotCount(ActionPoints::Action aeAction, bool abAllowLongBurst)
{
    int iNumAmmoPerShot;
    TESObjectWEAP* pweapon;
    float fburstTime;
    InventoryStackRecord* pweaponItem;
    unsigned char cshots;

    pweaponItem = static_cast<LogDateOwner*>(_g_thePlayer->GetLogDate())->v82();
    pweapon = reinterpret_cast<TESObjectWEAP*>(pweaponItem ? pweaponItem->GetFlags() : 0);
    iNumAmmoPerShot = pweapon ? pweapon->GetAmmoPerShot() : 0;

    cshots = 1;
    if (iNumAmmoPerShot > 0)
        cshots *= iNumAmmoPerShot;

    if (aeAction == 0 || (pweapon && !pweapon->GetIsAutomaticWeapon()))
        return cshots;

    fburstTime = abAllowLongBurst && pweapon && reinterpret_cast<FUN_007f5190_shell*>(pweapon)->IsFlag800Set()
                     ? *originalRuntimeFloatSetting539.Float()
                     : *originalRuntimeFloatSetting538.Float();

    cshots = static_cast<unsigned char>(
        reinterpret_cast<TESCreature*>(pweapon)->FUN_00821640() * fburstTime *
        reinterpret_cast<FUN_00646020_shell*>(pweapon)->FUN_00646020(pweaponItem->SetEquipmentState(8)));

    if (!cshots)
        cshots = 1;

    return cshots;
}
}  // namespace fnv_007f5050

struct RaceX;
struct FormX;
struct AmmoListX;
struct DetectX;
struct WeaponX;

struct ElemX
{
    char GetByte63();
};
struct RaceX
{
    void* FUN_005e5130(int aiIndex);
    ElemX** FUN_006a9540();
};
struct FormX
{
    WeaponX* FUN_0044ddc0();
};
struct AmmoListX
{
    int FUN_00726070();
};
struct DetectX
{
    int iLevel;
    bool bDetected;
};

struct ActorValueOwnerX
{
    virtual void v000();
    virtual void v004();
    virtual int GetActorValue(int aeAV);
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual int GetBaseActorValue(int aeAV);
};
struct ActorBaseX
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
    virtual RaceX* GetRace();
};
struct ProcessX
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
    virtual FormX* GetEquippedWeapon();
    virtual AmmoListX* GetAmmoList();
};
struct ActorX
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
    virtual bool IsActor();
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
    virtual int IsAlive();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void* GetAnimation();
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
    virtual bool IsDead(bool abArg);
    virtual bool IsCreature();
    char _pad04[0xa0];
    ActorValueOwnerX kAVOwner;
    const char* GetFullName();
    ActorBaseX* GetActorBase();
    ProcessX* FUN_008d8520();
    DetectX* FUN_00967090(ActorX* apTarget);
    void FUN_009445b0(float afDelta, int a2, int a3, int a4);
    void UpdateFaceAnimation(float afDelta);
    void UpdateAnimationMovement(void* apAnim, float afDelta);
    void UpdateCamera(bool a1, bool a2);
    void UpdateCameraMode();
};

struct ModListX
{
    bool FUN_00474a80();
};
struct WeaponX
{
    char _pad00[0xa4];
    ModListX kMods;
    int GetWeaponType() const;
    void* GetCurrentAmmo(ActorX* apActor);
    int GetFlaggedValue(int aiArg);
    unsigned char GetAmmoPerShot();
    float FUN_007ebd10();
};

struct TileX;
struct TileChildrenX
{
    TileX** FUN_0073ac90();
};
struct TileX
{
    char _pad00[4];
    TileChildrenX kChildren;
    void RemoveFadeItemsForTile(unsigned int auiFlags);
    void Set(int aeID, const char* apValue, bool abPropagate);
    void SetInt(int aeID, int aiValue);
    bool IsVisible();
};

template <class T> struct ListX
{
    T item;
    ListX* next;
    T& GetItem();
    bool IsEmpty();
    ListX* GetNext();
};

struct ChanceX
{
    char _pad00[0x20];
    int m_iActionValue;
    char _pad24[4];
    float fHitChance;
    char _pad2c;
    bool bCrippled;
    char _pad2e[2];
    int iHitCount;
};
struct TargetX
{
    char _pad00[8];
    ListX<ChanceX*> kLimbs;
};

struct CommandX
{
    int eAction;
    bool bFlag4;
    char _pad5[2];
    bool bFlag7;
    unsigned char ucShots;
    unsigned char ucExtra;
    char _padA[2];
    ActorX* pTarget;
    int m_iActionValue;
    char _pad14[0xc];
    float fAPCost;
    char _pad24[4];
    CommandX();
};

struct QueueX
{
    unsigned int GetSize();
};
struct VATSX
{
    int GetFlags();
    QueueX* _ref_006815c0();
    void FUN_009c6c30(int aiMode, bool abArg);
    bool IsValidCommand(CommandX* apCmd);
    void AddCommand(CommandX* apCmd);
};

struct InputX
{
    int GetAxisState(int a1, int a2);
    int FUN_00a24f10(int a1);
    int FUN_00a24660(int a1, int a2);
    int FUN_00a23a50(int a1, int a2);
    int FUN_00a24180(int a1, int a2);
};
struct OSGlobalsX
{
    InputX* FUN_00877720();
};
struct InterfaceManagerX
{
    static bool FUN_004b71d0();
    int FUN_00747d00();
    int FUN_0073b020();
};
InterfaceManagerX* xFUN_004b7210();

struct EffectX
{
    void FUN_00800ac0(int a1, int a2, int a3);
};
EffectX* xGetVATSEffect();

struct TimerX
{
    int FUN_00825c00();
    float FUN_0084d030();
};

struct SettingX
{
    const char* String();
    float* Float();
    int* Int();
    bool* Bool();
};

struct BSSoundHandleX
{
    unsigned int uiSoundID;
    bool m_bLooping;
    int eState;
    BSSoundHandleX();
    ~BSSoundHandleX();
    BSSoundHandleX& operator=(const BSSoundHandleX& arHandle);
    bool Play(bool abUnk);
};
struct AudioX
{
    static AudioX* GetSingleton();
    BSSoundHandleX GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};
struct AudioMgrX
{
    BSSoundHandleX ResolveAudioHandle(const char* apEditorID, unsigned int auiFlags);
};
AudioMgrX* xFUN_00ad9060();

struct UIMessageX
{
    void AddMessage(const char* apMessage, int aeType, int a3, int a4, float afTime, int a6);
};

struct VATSMenuX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void HandleClick(int aiID, int aiArg);
    char _pad04[0x24];
    TileX* m_pTiles[32];
    char _padA8[0x38];
    float m_fOverrideActionPoints;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
    float m_fValue5;
    bool m_bFirstFlag;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    float m_fHitChance;
    ChanceX* m_pTargetChance;
    bool m_bStateFlag4;
    char _pad105[3];
    ChanceX* m_pSelectedChance;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    char _pad111[3];
    unsigned int m_uiTargetCount;

    ListX<TargetX*>* FindListEntryForTarget(ActorX* apTarget);
    void AssignActionTiles(ListX<TargetX*>* apNode);
    void UpdateLimbHighlight();
    void UpdateQueueEntry(CommandX* apCmd, bool abArg2, bool abArg3);
    float FUN_007f48e0();
    void UpdateHitChanceDisplay();
    bool UpdateVatsTargeting();
    void FUN_007f3070();
    bool FUN_007f28d0();
    bool FUN_007f6af0();
    ListX<ChanceX*>* FindEntryForRef();
    int FUN_007f3bf0(int aiLimb);
    int GetConsecutiveMatchCount();
    void UpdateLimbTiles();
    void Update();
};

extern ActorX* xDAT_011f21cc;
extern ActorX* xDAT_011dea3c;
extern VATSMenuX* xDAT_011db0d4;
extern VATSX xDAT_011f2250;
extern OSGlobalsX* xDAT_011dea0c;
extern TimerX xDAT_011f6394;
extern UIMessageX* xDAT_011d96c0;
extern bool xDAT_011a0b68;
extern int xDAT_011dea34;
extern int xDAT_011a59f0;
extern int xDAT_011db180;
extern bool xDAT_011db0b2;
extern bool xDAT_011db0b3;
extern float xDAT_011db0b8;
extern float xDAT_011db0c0;
extern bool xDAT_011db0b0;
extern SettingX xDAT_011d396c;
extern SettingX xDAT_011d50b0;
extern SettingX xDAT_011d3894;
extern SettingX xDAT_011d28c8;
extern SettingX xDAT_011ce8dc;
extern SettingX xDAT_011d4210;
extern SettingX xDAT_011db114;

int xFUN_00a09030(int aiID);
void xFUN_007ebd50();
bool xFUN_00702450(int aiID);
void xFUN_007ec3a0(int abArg);
bool xFUN_00703d50();
bool xFUN_007f4c00();
bool xFUN_007f4bb0();
extern "C" int FUN_00ec7d40(int aiValue);
void xFUN_00774b00(TileX* apTile1, TileX* apTile2, float afValue1, float afValue2, int a5, int a6);
float xFUN_007700f0(ActorX* apAttacker, ActorX* apTarget);
void xFUN_005e58f0(int aeEntryPoint, ActorX* apActor, float* apValue);
int xFUN_00647b70(int a1, int a2);
void xFUN_007748b0(TileX* apTile, float afValue, int a3, int a4, int a5);
void xFUN_00779070(TileX* apTile1, TileX* apTile2, TileX* apTile3, TileX* apTile4);
bool xFUN_00709d40();
int xFUN_00717a40(int a1, int a2);
void xFUN_00705780();
bool xFUN_007eeb50(int aiKey, bool abHeld, int aiArg);
void __fastcall xFUN_00964260(void* apPlayer);
float xFUN_00715d40();
float xFUN_00715da0();
float xFUN_007177c0();
float xFUN_00717820();
int xFUN_00a00940(const char* apName, int aiArg);
float xFUN_0066dce0(WeaponX* apWeapon, int a2, int a3);
bool xFUN_009526b0();
int xFUN_0066dba0(int aiType);
unsigned char xFUN_007f5050(int aiAction, int a2);
float xFUN_0066dca0(int a1, bool a2, float a3, int a4);
bool __fastcall xFUN_006450c0(WeaponX* apWeapon);
float xRandomFloat(float afMin, float afMax);
float xFUN_00404010(float a1, float a2);
bool xFUN_004dff00(float afChance);
int sprintf(char* apBuffer, const char* apFormat, ...);

// @fnv 0x007ec810
void VATSMenuX::Update()
{
    if (m_bStateFlag3)
    {
        return;
    }
    if (xFUN_00a09030(0x423))
    {
        return;
    }
    if (!xDAT_011f21cc || !xDAT_011f21cc->IsAlive() || xDAT_011f21cc->IsDead(0) || xDAT_011dea3c->IsDead(0))
    {
        xFUN_007ebd50();
        return;
    }
    if (!xDAT_011db0d4 || !xDAT_011f2250.GetFlags() || xDAT_011f2250.GetFlags() == 4 || !xFUN_00702450(0x420))
    {
        if (!xFUN_00702450(0x420) && xDAT_011a0b68)
        {
            xDAT_011a0b68 = 0;
            xGetVATSEffect()->FUN_00800ac0(0, -1, 0);
        }
        m_pTiles[28]->RemoveFadeItemsForTile(0x80000000);
        (*m_pTiles[28]->kChildren.FUN_0073ac90())->RemoveFadeItemsForTile(0x80000000);
        m_pTiles[10]->RemoveFadeItemsForTile(0x80000000);
        return;
    }
    if (FindListEntryForTarget(xDAT_011f21cc)->GetItem()->kLimbs.GetItem()->iHitCount == 0)
    {
        AssignActionTiles(FindListEntryForTarget(xDAT_011f21cc));
    }
    if (!xDAT_011a0b68)
    {
        xFUN_007ec3a0(1);
    }
    xDAT_011a0b68 = 1;
    if (xFUN_00703d50())
    {
        return;
    }
    UpdateLimbHighlight();
    InputX* pInputA = xDAT_011dea0c->FUN_00877720();
    if (xFUN_004b7210()->FUN_004b71d0())
    {
        int iDeadZoneCur = xDAT_011f2250.GetFlags() == 1 ? 0x1ea9 : 0x21f1;
        int iLeftXTwo54 = pInputA->GetAxisState(0, 7);
        int iLeftYZ = pInputA->GetAxisState(0, 8);
        int iRightXNum = pInputA->GetAxisState(0, 9);
        int iRightYTmp = pInputA->GetAxisState(0, 10);
        iLeftYZ = -iLeftYZ;
        iRightYTmp = -iRightYTmp;
        if (iRightXNum > 0x21f1)
        {
            if (!m_bStateFlag6)
            {
                m_uiTargetCount = xDAT_011f6394.FUN_00825c00();
                m_bStateFlag6 = 1;
            }
        }
        else if (iRightXNum < -0x21f1)
        {
            if (!m_bStateFlag10)
            {
                m_uiTargetCount = xDAT_011f6394.FUN_00825c00();
                m_bStateFlag10 = 1;
            }
        }
        else if (FUN_00ec7d40(iRightXNum) < 0x21f1 && FUN_00ec7d40(iRightYTmp) < 0x21f1)
        {
            if (xFUN_007f4c00())
            {
                xDAT_011db0d4->m_bStateFlag6 = 0;
                HandleClick(3, 0);
            }
            else if (m_bStateFlag6)
            {
                HandleClick(3, 0);
            }
            else if (xFUN_007f4bb0())
            {
                xDAT_011db0d4->m_bStateFlag10 = 0;
                HandleClick(2, 0);
            }
            else if (m_bStateFlag10)
            {
                HandleClick(2, 0);
            }
            m_bStateFlag9 = 1;
        }
    }
    if (xDAT_011f21cc && xDAT_011f21cc->IsActor())
    {
        float fBaseHealthA68 = xDAT_011f21cc->kAVOwner.GetBaseActorValue(0x10);
        float fHealthOut44 = xDAT_011f21cc->kAVOwner.GetActorValue(0x10);
        float fRatioB = 0.0f;
        char acBufferOut70[256];
        if (fBaseHealthA68 > 0)
        {
            fRatioB = fHealthOut44 / fBaseHealthA68;
        }
        if (!xDAT_011f21cc->IsDead(0))
        {
            xFUN_00774b00(m_pTiles[26], m_pTiles[28], fRatioB - m_fHitChance, fRatioB, 2, 2);
        }
        else
        {
            xFUN_00774b00(m_pTiles[26], m_pTiles[28], fRatioB - m_fHitChance, fRatioB, 2, 0);
        }
        m_pTiles[29]->Set(0xfc4, xDAT_011f21cc->GetFullName(), 1);
        m_pTiles[25]->SetInt(0xfa3, 1);
        m_pTiles[26]->SetInt(0xfa3, 1);
        m_pTiles[28]->SetInt(0xfa3, 1);
        m_pTiles[27]->SetInt(0xfa3, 1);
        m_pTiles[29]->SetInt(0xfa3, 1);
        float fChanceX73 = xFUN_007700f0(xDAT_011dea3c, xDAT_011f21cc);
        float fPerkB = 0.0f;
        xFUN_005e58f0(0x2f, xDAT_011dea3c, &fPerkB);
        if (fPerkB > 0)
        {
            sprintf(acBufferOut70, "%s\n %s:%d %s:%.2f", xDAT_011f21cc->GetFullName(), xDAT_011d50b0.String(),
                    (int)fHealthOut44, xDAT_011d396c.String(), fChanceX73);
            m_pTiles[29]->Set(0xfc4, acBufferOut70, 1);
        }
        else
        {
            m_pTiles[29]->Set(0xfc4, xDAT_011f21cc->GetFullName(), 1);
        }
        if (xDAT_011dea3c->FUN_00967090(xDAT_011f21cc) && xDAT_011dea3c->FUN_00967090(xDAT_011f21cc)->bDetected)
        {
            m_pTiles[29]->SetInt(0xff4, 2);
            m_pTiles[25]->SetInt(0xff4, 2);
            m_pTiles[26]->SetInt(0xff4, 2);
            m_pTiles[28]->SetInt(0xff4, 2);
            m_pTiles[27]->SetInt(0xff4, 2);
        }
        else
        {
            m_pTiles[29]->SetInt(0xff4, 1);
            m_pTiles[25]->SetInt(0xff4, 1);
            m_pTiles[26]->SetInt(0xff4, 1);
            m_pTiles[28]->SetInt(0xff4, 1);
            m_pTiles[27]->SetInt(0xff4, 1);
        }
    }
    else
    {
        m_pTiles[25]->SetInt(0xfa3, 0);
        m_pTiles[26]->SetInt(0xfa3, 0);
        m_pTiles[28]->SetInt(0xfa3, 0);
        m_pTiles[27]->SetInt(0xfa3, 0);
        m_pTiles[29]->SetInt(0xfa3, 0);
    }
    float fAPRatioPtr = xFUN_00647b70(0, xDAT_011dea3c->kAVOwner.GetBaseActorValue(0x10));
    if (fAPRatioPtr != 0)
    {
        fAPRatioPtr = xFUN_00647b70(0, xDAT_011dea3c->kAVOwner.GetActorValue(0x10)) / fAPRatioPtr;
    }
    xFUN_007748b0(m_pTiles[18], fAPRatioPtr, 0, 0, 0);
    xFUN_00779070(m_pTiles[23], m_pTiles[20], m_pTiles[21], m_pTiles[22]);
    int iRawB = pInputA->FUN_00a24f10(0x10);
    int iKeyTwo = iRawB >> 16;
    int iMidRes = (iRawB & 0xff00) >> 8;
    int iLowTwo = iRawB & 0xff;
    if (xDAT_011f2250.GetFlags() != 4)
    {
        if (pInputA->FUN_00a24660(0x10, 1) && xDAT_011f2250.GetFlags() != 1)
        {
            if (!InterfaceManagerX::FUN_004b71d0() || (iLowTwo != 10 && iLowTwo != 11 && iLowTwo != 0x11))
            {
                xDAT_011f2250.FUN_009c6c30(1, 0);
                m_bStateFlag2 = 0;
            }
        }
        else if (!pInputA->FUN_00a24660(0x10, 0) && xDAT_011f2250.GetFlags() == 1)
        {
            xDAT_011f2250.FUN_009c6c30(2, 0);
            m_bStateFlag2 = 1;
        }
    }
    xDAT_011dea3c->FUN_009445b0(xDAT_011f6394.FUN_0084d030(), 0, 0, 0);
    if ((xFUN_00709d40() && (xFUN_00717a40(10, 1) == 1 || xFUN_00717a40(6, 1) == 1)) ||
        (pInputA->FUN_00a23a50(1, 1) && iMidRes != 1))
    {
        if ((!xFUN_004b7210()->FUN_004b71d0() && !m_bAdditionalStateFlag) ||
            (xFUN_004b7210()->FUN_004b71d0() && xFUN_00717a40(10, 1) == 1))
        {
            if (xDAT_011f2250.GetFlags() == 2 && m_bFirstFlag)
            {
                UpdateQueueEntry(0, 0, 0);
                xDAT_011db0d4->m_fHitChance = xDAT_011db0d4->FUN_007f48e0();
            }
            UpdateHitChanceDisplay();
        }
    }
    if (!UpdateVatsTargeting())
    {
        return;
    }
    FormX* pEquippedNew = xDAT_011dea3c->FUN_008d8520()->GetEquippedWeapon();
    WeaponX* pWeaponOld = pEquippedNew ? pEquippedNew->FUN_0044ddc0() : 0;
    bool bHasModsM = pWeaponOld ? pWeaponOld->kMods.FUN_00474a80() : 0;
    FUN_007f3070();
    if (xDAT_011f2250.GetFlags() != 4)
    {
        xDAT_011dea34 = 0;
        xFUN_00964260(xDAT_011dea3c);
        xDAT_011dea3c->UpdateFaceAnimation(xDAT_011f6394.FUN_0084d030());
        xDAT_011dea3c->UpdateAnimationMovement(xDAT_011dea3c->GetAnimation(), 0.0f);
        xDAT_011dea3c->UpdateCamera(0, 0);
        xDAT_011dea3c->UpdateCameraMode();
        xFUN_007ec3a0(0);
        {
            InterfaceManagerX* pInterfaceTwo31 = xFUN_004b7210();
            int iMenuDepthZ = pInterfaceTwo31->FUN_00747d00();
            int iMenuModeIn = pInterfaceTwo31->FUN_0073b020();
        }
        static int s_iScreenWidth = xFUN_00715d40();
        static int s_iScreenHeight = xFUN_00715da0();
        static int s_iSafeWidth = xFUN_007177c0();
        static int s_iSafeHeight = xFUN_00717820();
        if ((pInputA->FUN_00a24180(0x12, 0) && iKeyTwo != 0x12) ||
            (xFUN_004b7210()->FUN_004b71d0() && xFUN_00717a40(9, 1) == 2 &&
             xDAT_011f2250._ref_006815c0()->GetSize() > 0 && xDAT_011f2250.GetFlags() == 2))
        {
            xFUN_00705780();
            return;
        }
        {
            int iModeNum76 = 0;
            if (xDAT_011f21cc)
            {
                if (xFUN_007eeb50(1, 0, iMidRes))
                {
                    xDAT_011db180 = iModeNum76 = 1;
                }
                else if (xFUN_007eeb50(2, 0, iMidRes))
                {
                    xDAT_011db180 = iModeNum76 = 2;
                }
                else if (xFUN_007eeb50(3, 0, iMidRes))
                {
                    xDAT_011db180 = iModeNum76 = 3;
                }
                else if (xDAT_011db180 && !xFUN_007eeb50(xDAT_011db180, 1, iMidRes))
                {
                    xDAT_011db180 = 0;
                }
            }
            else
            {
                xDAT_011db180 = 0;
            }
            xDAT_011db0b2 = 0;
            xDAT_011db0b3 = 0;
            if (m_pTiles[30]->IsVisible())
            {
                if (xDAT_011db0b8 > m_fOverrideActionPoints)
                {
                    m_pTiles[30]->SetInt(0xfaf, 0);
                }
                else
                {
                    m_pTiles[30]->SetInt(0xfaf, 1);
                }
            }
            else if (iModeNum76 == 2)
            {
                iModeNum76 = 0;
            }
            if (m_pTiles[31]->IsVisible())
            {
                if (xDAT_011db0c0 > m_fOverrideActionPoints)
                {
                    m_pTiles[31]->SetInt(0xfaf, 0);
                }
                else
                {
                    m_pTiles[31]->SetInt(0xfaf, 1);
                }
            }
            else if (iModeNum76 == 3)
            {
                iModeNum76 = 0;
            }
            float fCostX = xFUN_0066dce0(pWeaponOld, 1, 0);
            float fShownCostOut = fCostX;
            switch (iModeNum76)
            {
            case 2:
                fCostX = xDAT_011db0b8;
                break;
            case 3:
                fCostX = xDAT_011db0c0;
                break;
            }
            switch (xDAT_011db180)
            {
            case 2:
                fShownCostOut = xDAT_011db0b8;
                break;
            case 3:
                fShownCostOut = xDAT_011db0c0;
                break;
            }
            if (xFUN_009526b0())
            {
                fCostX = 0.0f;
                fShownCostOut = 0.0f;
            }
            FUN_007f28d0();
            static int s_iBrightness = xFUN_00a00940("_Brightness", -1);
            if (xDAT_011f21cc && fShownCostOut > m_fOverrideActionPoints && xDAT_011db180)
            {
                xFUN_00774b00(m_pTiles[9], m_pTiles[10], fShownCostOut / m_fValue1, 0.0f, 1, 0);
            }
            else
            {
                xFUN_00774b00(m_pTiles[9], m_pTiles[10], (m_fOverrideActionPoints - fShownCostOut) / m_fValue1,
                              m_fOverrideActionPoints / m_fValue1, 1, 0);
                m_pTiles[12]->SetInt(0xfa3, 0);
            }
            if (xDAT_011f21cc && iModeNum76)
            {
                bool bBusy = !InterfaceManagerX::FUN_004b71d0() && FUN_007f6af0();
                if (!bBusy && m_pTargetChance->fHitChance > 0)
                {
                    if ((xFUN_004b7210()->FUN_004b71d0() && xDAT_011f2250.GetFlags() == 2) ||
                        (!xFUN_004b7210()->FUN_004b71d0() && xDAT_011f2250.GetFlags() == 2 &&
                         (!m_bAdditionalStateFlag || iModeNum76 != 1)))
                    {
                        int iActionZ = xFUN_0066dba0(pWeaponOld ? pWeaponOld->GetWeaponType() : 0);
                        unsigned char ucShotsA39 = xFUN_007f5050(iActionZ, 0);
                        if (ucShotsA39 >= m_fValue4 && pWeaponOld && pWeaponOld->GetCurrentAmmo(xDAT_011dea3c) &&
                            pWeaponOld->GetFlaggedValue(0) > 1)
                        {
                            fCostX += xFUN_0066dca0(9, 1, 0.0f, 0);
                        }
                        AmmoListX* pAmmoListOne = xDAT_011dea3c->FUN_008d8520()->GetAmmoList();
                        bool bCanFireZ95 =
                            !pWeaponOld ? false
                                        : ((pWeaponOld->GetWeaponType() != 10 && pWeaponOld->GetWeaponType() != 13) ||
                                           (pAmmoListOne && (unsigned int)pAmmoListOne->FUN_00726070() >
                                                                xDAT_011f2250._ref_006815c0()->GetSize()));
                        if ((!pWeaponOld || (pWeaponOld->GetWeaponType() != 10 && pWeaponOld->GetWeaponType() != 13) ||
                             bCanFireZ95) &&
                            (!bHasModsM || m_fValue5 + m_fValue4 > 0) && iActionZ != 0x16 &&
                            m_fOverrideActionPoints >= fCostX &&
                            (!pWeaponOld || !pWeaponOld->GetCurrentAmmo(xDAT_011dea3c) || m_fValue5 + m_fValue4 > 0) &&
                            (!pWeaponOld || !pWeaponOld->GetCurrentAmmo(xDAT_011dea3c) ||
                             (pAmmoListOne && pAmmoListOne->FUN_00726070() > 0)) &&
                            (!FindEntryForRef() || (int)(FindEntryForRef()->GetItem()->fHitChance * 100.0) > 0))
                        {
                            CommandX* pCommandA55 = new CommandX;
                            void* pRaceItemNum =
                                xDAT_011f21cc->IsActor()
                                    ? xDAT_011f21cc->GetActorBase()->GetRace()->FUN_005e5130(xDAT_011a59f0)
                                    : 0;
                            FormX* pTargetEquippedQ96 =
                                xDAT_011f21cc->IsActor() ? xDAT_011f21cc->FUN_008d8520()->GetEquippedWeapon() : 0;
                            WeaponX* pTargetWeaponX4 = pTargetEquippedQ96 ? pTargetEquippedQ96->FUN_0044ddc0() : 0;
                            if (FindEntryForRef())
                            {
                                m_pSelectedChance = FindEntryForRef()->GetItem();
                            }
                            bool bLimbSetNum = false;
                            if (!pWeaponOld || xFUN_006450c0(pWeaponOld))
                            {
                                float fRandIn = xRandomFloat(0.0f, 100.0f);
                                int iCountB = 0;
                                int iLimbOld = -1;
                                ListX<ChanceX*>* pNodeIn = &FindListEntryForTarget(xDAT_011f21cc)->GetItem()->kLimbs;
                                while (pNodeIn && !pNodeIn->IsEmpty())
                                {
                                    switch (pNodeIn->GetItem()->m_iActionValue)
                                    {
                                    case 1:
                                    case 2:
                                        iLimbOld = pNodeIn->GetItem()->m_iActionValue;
                                        iCountB++;
                                        break;
                                    case 0:
                                    case 3:
                                    case 4:
                                    case 5:
                                    case 6:
                                        iCountB++;
                                        break;
                                    }
                                    pNodeIn = pNodeIn->GetNext();
                                }
                                if (!pWeaponOld && iModeNum76 == 2 && iLimbOld != -1)
                                {
                                    pCommandA55->m_iActionValue = FUN_007f3bf0(iLimbOld);
                                    bLimbSetNum = true;
                                }
                                else if (iCountB > 0)
                                {
                                    float fStepX = 100.0 / iCountB;
                                    int iPickM99 = xFUN_00404010(fRandIn, 1.0f) / fStepX;
                                    iCountB = 0;
                                    pNodeIn = &FindListEntryForTarget(xDAT_011f21cc)->GetItem()->kLimbs;
                                    while (pNodeIn && !pNodeIn->IsEmpty())
                                    {
                                        switch (pNodeIn->GetItem()->m_iActionValue)
                                        {
                                        case 0:
                                        case 1:
                                        case 2:
                                        case 3:
                                        case 4:
                                        case 5:
                                        case 6:
                                            if (iCountB == iPickM99)
                                            {
                                                pCommandA55->m_iActionValue =
                                                    FUN_007f3bf0(pNodeIn->GetItem()->m_iActionValue);
                                                bLimbSetNum = true;
                                            }
                                            iCountB++;
                                            break;
                                        }
                                        pNodeIn = pNodeIn->GetNext();
                                    }
                                }
                            }
                            if (!bLimbSetNum)
                            {
                                pCommandA55->m_iActionValue = FUN_007f3bf0(m_pTargetChance->m_iActionValue);
                            }
                            pCommandA55->ucShots = xFUN_007f5050(iActionZ, 0);
                            pCommandA55->ucExtra = xFUN_00647b70(xFUN_007f5050(iActionZ, 1) - pCommandA55->ucShots, 0);
                            if (iModeNum76 == 2)
                            {
                                if (pWeaponOld && pWeaponOld->FUN_007ebd10() > 0)
                                {
                                    pCommandA55->eAction = 0x10;
                                }
                                else if (xDAT_011f21cc->IsCreature())
                                {
                                    pCommandA55->eAction = 0x15;
                                }
                                else
                                {
                                    pCommandA55->eAction = 0x11;
                                }
                            }
                            else if (iModeNum76 == 3)
                            {
                                pCommandA55->eAction = 0x14;
                            }
                            else
                            {
                                pCommandA55->eAction = iActionZ;
                            }
                            pCommandA55->pTarget = xDAT_011f21cc;
                            pCommandA55->fAPCost = fCostX;
                            float fThresholdA52 = *xDAT_011ce8dc.Float() * 100.0;
                            float fRollQ96 = xRandomFloat(0.0f, 100.0f);
                            if (xDAT_011db0b0 && iActionZ == 0 && fRollQ96 <= fThresholdA52)
                            {
                                pCommandA55->bFlag7 = 1;
                            }
                            if (xDAT_011f2250.IsValidCommand(pCommandA55) && xDAT_011f21cc->IsActor() && !bLimbSetNum)
                            {
                                RaceX* pRaceB70 = xDAT_011f21cc->GetActorBase()->GetRace();
                                void* pElement = pRaceB70->FUN_005e5130(0x19);
                                if (pElement)
                                {
                                    pCommandA55->m_iActionValue = 0x19;
                                }
                                else
                                {
                                    pElement = pRaceB70->FUN_005e5130(0x1a);
                                    if (pElement)
                                    {
                                        pCommandA55->m_iActionValue = 0x1a;
                                    }
                                    else
                                    {
                                        ElemX** ppElemsB2 = pRaceB70->FUN_006a9540();
                                        bool bFound96 = false;
                                        for (int iNew = 0; iNew < 15 && !bFound96; iNew++)
                                        {
                                            if (ppElemsB2[iNew])
                                            {
                                                pCommandA55->m_iActionValue = ppElemsB2[iNew]->GetByte63();
                                                bFound96 = true;
                                            }
                                        }
                                    }
                                }
                            }
                            xDAT_011f2250.AddCommand(pCommandA55);
                            ListX<ChanceX*>* pLimbNodeRes38 = FindEntryForRef();
                            float fLimbChanceZ = pLimbNodeRes38 ? FindEntryForRef()->GetItem()->fHitChance : 0.0f;
                            if (m_bStateFlag4)
                            {
                                int iShotsAtLimb = GetConsecutiveMatchCount();
                                fLimbChanceZ += (*xDAT_011d4210.Int() * iShotsAtLimb) / 100.0;
                            }
                            pCommandA55->bFlag4 =
                                (*xDAT_011db114.Bool() && FindEntryForRef()) ? true : xFUN_004dff00(fLimbChanceZ);
                            UpdateLimbTiles();
                            if (FUN_007f28d0() && pWeaponOld && pWeaponOld->GetWeaponType() != 10 &&
                                pWeaponOld->GetWeaponType() != 13 &&
                                pWeaponOld->GetFlaggedValue(0) != pWeaponOld->GetAmmoPerShot() &&
                                m_fValue5 + m_fValue4 > 0)
                            {
                                UpdateQueueEntry(pCommandA55, 1, iModeNum76 != 1);
                            }
                            else
                            {
                                UpdateQueueEntry(pCommandA55, 0, iModeNum76 != 1);
                            }
                            if (m_fOverrideActionPoints < fCostX)
                            {
                                m_pTiles[7]->SetInt(0xfaf, 0);
                            }
                            UpdateHitChanceDisplay();
                        }
                        else if (FindEntryForRef() && (int)(FindEntryForRef()->GetItem()->fHitChance * 100.0) <= 0 &&
                                 xDAT_011f2250.GetFlags() == 2 && m_bFirstFlag)
                        {
                            BSSoundHandleX kSoundIn;
                            kSoundIn = AudioX::GetSingleton()->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121);
                            kSoundIn.Play(0);
                            xDAT_011d96c0->AddMessage(xDAT_011d3894.String(), 2, 0, 0, 2.0f, 0);
                        }
                        else if (m_fOverrideActionPoints < fCostX)
                        {
                            AudioMgrX* pAudioMgrK = xFUN_00ad9060();
                            BSSoundHandleX kSoundIn;
                            kSoundIn = pAudioMgrK->ResolveAudioHandle("UIVATSInsufficientAP", 0x121);
                            kSoundIn.Play(0);
                            m_pTiles[12]->SetInt(0xfa3, 1);
                        }
                        else if (m_fValue5 + m_fValue4 == 0)
                        {
                            xDAT_011d96c0->AddMessage(xDAT_011d28c8.String(), 2, 0, 0, 2.0f, 0);
                            BSSoundHandleX kSoundIn;
                            kSoundIn = AudioX::GetSingleton()->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121);
                            kSoundIn.Play(0);
                        }
                        xDAT_011db0d4->m_fHitChance = xDAT_011db0d4->FUN_007f48e0();
                    }
                    else if (!xFUN_004b7210()->FUN_004b71d0() && xDAT_011f2250.GetFlags() == 1 &&
                             !m_bAdditionalStateFlag)
                    {
                        FUN_007f6af0();
                    }
                }
                else if (!bBusy && m_pTargetChance->bCrippled && xDAT_011f2250.GetFlags() == 2 && m_bFirstFlag)
                {
                    AudioMgrX* pAudioMgrK = xFUN_00ad9060();
                    BSSoundHandleX kSoundIn;
                    kSoundIn = pAudioMgrK->ResolveAudioHandle("UIVATSInsufficientAP", 0x121);
                    kSoundIn.Play(0);
                    if (m_pTargetChance->fHitChance == 0)
                    {
                        xDAT_011d96c0->AddMessage(xDAT_011d3894.String(), 2, 0, 0, 2.0f, 0);
                    }
                }
            }
            else if (!xFUN_004b7210()->FUN_004b71d0() && pInputA->FUN_00a24180(0x1e, 1) &&
                     pInputA->FUN_00a24180(0x1e, 3) && iKeyTwo != 0x1e)
            {
                HandleClick(2, 0);
            }
            else if (!xFUN_004b7210()->FUN_004b71d0() && pInputA->FUN_00a24180(0x20, 1) &&
                     pInputA->FUN_00a24180(0x20, 3) && iKeyTwo != 0x20)
            {
                HandleClick(3, 0);
            }
        }
    }
}

struct VATSMenu007ef830 : VATSMenu
{
    void FUN_007ef830(int aiID, int aiOther);
};

// @fnv 0x007ef830
void VATSMenu007ef830::FUN_007ef830(int aiID, int aiOther)
{
    _FUN_004b7210();
    if (_FUN_004b71d0())
    {
        return;
    }

    switch (aiID)
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 30:
    case 31:
        m_bAdditionalStateFlag = false;
        break;
    }
}

class C7F0500Ref
{
  public:
    virtual void vfunc000();
    virtual void vfunc001();
    virtual void vfunc002();
    virtual void vfunc003();
    virtual void vfunc004();
    virtual void vfunc005();
    virtual void vfunc006();
    virtual void vfunc007();
    virtual void vfunc008();
    virtual void vfunc009();
    virtual void vfunc00A();
    virtual void vfunc00B();
    virtual void vfunc00C();
    virtual void vfunc00D();
    virtual void vfunc00E();
    virtual void vfunc00F();
    virtual void vfunc010();
    virtual void vfunc011();
    virtual void vfunc012();
    virtual void vfunc013();
    virtual void vfunc014();
    virtual void vfunc015();
    virtual void vfunc016();
    virtual void vfunc017();
    virtual void vfunc018();
    virtual void vfunc019();
    virtual void vfunc01A();
    virtual void vfunc01B();
    virtual void vfunc01C();
    virtual void vfunc01D();
    virtual void vfunc01E();
    virtual void vfunc01F();
    virtual void vfunc020();
    virtual void vfunc021();
    virtual void vfunc022();
    virtual void vfunc023();
    virtual void vfunc024();
    virtual void vfunc025();
    virtual void vfunc026();
    virtual void vfunc027();
    virtual void vfunc028();
    virtual void vfunc029();
    virtual void vfunc02A();
    virtual void vfunc02B();
    virtual void vfunc02C();
    virtual void vfunc02D();
    virtual void vfunc02E();
    virtual void vfunc02F();
    virtual void vfunc030();
    virtual void vfunc031();
    virtual void vfunc032();
    virtual void vfunc033();
    virtual void vfunc034();
    virtual void vfunc035();
    virtual void vfunc036();
    virtual void vfunc037();
    virtual void vfunc038();
    virtual void vfunc039();
    virtual void vfunc03A();
    virtual void vfunc03B();
    virtual void vfunc03C();
    virtual void vfunc03D();
    virtual void vfunc03E();
    virtual void vfunc03F();
    virtual void vfunc040();
    virtual void vfunc041();
    virtual void vfunc042();
    virtual void vfunc043();
    virtual void vfunc044();
    virtual void vfunc045();
    virtual void vfunc046();
    virtual void vfunc047();
    virtual void vfunc048();
    virtual void vfunc049();
    virtual void vfunc04A();
    virtual void vfunc04B();
    virtual void vfunc04C();
    virtual void vfunc04D();
    virtual void vfunc04E();
    virtual void vfunc04F();
    virtual void vfunc050();
    virtual void vfunc051();
    virtual void vfunc052();
    virtual void vfunc053();
    virtual void vfunc054();
    virtual void vfunc055();
    virtual void vfunc056();
    virtual void vfunc057();
    virtual void vfunc058();
    virtual void vfunc059();
    virtual void vfunc05A();
    virtual void vfunc05B();
    virtual void vfunc05C();
    virtual void vfunc05D();
    virtual void vfunc05E();
    virtual void vfunc05F();
    virtual void vfunc060();
    virtual void vfunc061();
    virtual void vfunc062();
    virtual void vfunc063();
    virtual void vfunc064();
    virtual void vfunc065();
    virtual void vfunc066();
    virtual void vfunc067();
    virtual void vfunc068();
    virtual void vfunc069();
    virtual void vfunc06A();
    virtual void vfunc06B();
    virtual void vfunc06C();
    virtual void vfunc06D();
    virtual void vfunc06E();
    virtual void vfunc06F();
    virtual void vfunc070();
    virtual void vfunc071();
    virtual void vfunc072();
    virtual void vfunc073();
    virtual void vfunc074();
    virtual void vfunc075();
    virtual void vfunc076();
    virtual void vfunc077();
    virtual void vfunc078();
    virtual void vfunc079();
    virtual void vfunc07A();
    virtual void vfunc07B();
    virtual void vfunc07C();
    virtual NiPoint3* GetPos();
};

extern "C" C7F0500Ref* g_thePlayer;

float GetAngleBetweenPoints(const NiPoint3& kA, const NiPoint3& kB);

// Compares the player's distance to the objects referenced by pvA and pvB, returning -1, 1 or 0.
// @fnv 0x007f0500
int __cdecl FUN_007f0500(const void* pvA, const void* pvB)
{
    NiPoint3 kPlayerPos = *g_thePlayer->GetPos();
    float fLeftDist = GetAngleBetweenPoints(kPlayerPos, *(*(C7F0500Ref**)pvA)->GetPos());
    float fSecondDist = GetAngleBetweenPoints(kPlayerPos, *(*(C7F0500Ref**)pvB)->GetPos());
    if (fLeftDist < fSecondDist)
        return -1;
    else if (fSecondDist < fLeftDist)
        return 1;
    else
        return 0;
}

struct FUN_007f06d0_Tri
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct FUN_007f06d0_Src
{
    char pad[0x14];
    FUN_007f06d0_Tri tri;
    char pad2[0x2c - 0x20];
    unsigned char flag;
};

struct FUN_007f06d0_Node
{
    FUN_007f06d0_Node* FUN_006629f0();
    void ProjectToScreen();
};

extern float DAT_010718c0;
extern double DAT_01012060;
extern double DAT_01012070;
void* __stdcall FUN_0045c670(FUN_007f06d0_Tri* t, float* f0, float* f6, float r);

struct FUN_007f06d0_cls
{
    bool __thiscall FUN_007f06d0(FUN_007f06d0_Src* a1);
};

// @fnv 0x007f06d0
bool FUN_007f06d0_cls::FUN_007f06d0(FUN_007f06d0_Src* pSrc)
{
    FUN_007f06d0_Tri t = pSrc->tri;
    float f0 = 0.0f;
    float f6 = 0.0f;
    ((FUN_007f06d0_Node*)FUN_0045c670(&t, &f0, &f6, DAT_010718c0))->FUN_006629f0()->ProjectToScreen();
    bool ok8 = (!(f0 <= DAT_01012060) && !(f6 <= DAT_01012060) && !(f0 >= DAT_01012070) && !(f6 >= DAT_01012070))
                   ? true
                   : false;
    if (ok8)
    {
        pSrc->flag = 1;
        return true;
    }
    pSrc->flag = 0;
    return false;
}

// @fnv 0x007f3b40
void __cdecl FUN_007f3b40(int a1)
{
    if (DAT_011db0d4 == 0)
    {
        return;
    }
    {
        BSSimpleList* cur = (BSSimpleList*)((char*)*((StandIn*)DAT_011db0d4)
                                                ->FindListEntryForTarget((TESObjectREFR*)DAT_011f21cc)
                                                ->FUN_006815c0() +
                                            8);
        while (cur != 0 && !cur->FUN_008256d0())
        {
            if (*((TargetList*)cur)->FUN_006815c0() != 0)
            {
                if (*(int*)((char*)*((TargetList*)cur)->FUN_006815c0() + 0x20) == a1)
                {
                    *(ItemListContainer**)((char*)DAT_011db0d4 + 0x100) = *((TargetList*)cur)->FUN_006815c0();
                    break;
                }
            }
            cur = cur->FUN_00726070();
        }
    }
done:
    return;
}

struct ItemListElement
{
    float __thiscall FUN_00a011b0();
};
struct VATSLookupList
{
    bool __thiscall FUN_008256d0();
    ItemListElement*** __thiscall FUN_006815c0(int id);
    VATSLookupList* __thiscall FUN_00726070();
};
struct VATSLookup
{
    int unk00;
    VATSLookupList items;
    bool __thiscall FUN_007f7280(unsigned int index, bool byPosition);
    bool __thiscall RemoveNodeFromList(VATSLookupList* found, VATSLookupList* previous);
};
// @fnv 0x007f7280
bool VATSLookup::FUN_007f7280(unsigned int index, bool byPosition)
{
    if (items.FUN_008256d0())
    {
        return false;
    }
    VATSLookupList* previous;
    VATSLookupList* current = this ? &items : 0;
    previous = this ? &items : 0;
    if (byPosition)
    {
        unsigned int counter = 0;
        while (current && counter++ != index)
        {
            previous = current;
            current = current->FUN_00726070();
        }
    }
    else
    {
        while (current && (**current->FUN_006815c0(0xfac))->FUN_00a011b0() != index)
        {
            previous = current;
            current = current->FUN_00726070();
        }
    }
    return RemoveNodeFromList(current, previous);
}

void __cdecl FUN_0040fbe0(const char*, ...);
extern const char DAT_01078e44[], DAT_01078e10[];
struct PtrHolder
{
    void* ptr;
    operator void*() const;
    PtrHolder& operator=(void*);
};
class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011db750, g_011db6d8;
struct FUN_004a4410_Class
{
    void* FUN_004a4410(unsigned int);
};
struct TargetActor
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
    virtual void* getNode();
};
struct Target
{
    unsigned int unk00;
    TargetActor* current;
    PtrHolder node;
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
    bool active;
    bool pending[16];
    bool enabled;
    unsigned short unk12a;
    FUN_004a4410_Class* firstObjects[16];
    FUN_004a4410_Class* secondObjects[16];
    bool secondPending[16];
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    int index;
    int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    bool flag2b4, flag2b5;
    void FUN_00800650(float, float, bool);
    void FUN_00800ac0(TargetActor*, int, bool);
};
// @fnv 0x00800ac0
void Target::FUN_00800ac0(TargetActor* actor, int slot, bool state)
{
    if (!actor)
        FUN_0040fbe0(DAT_01078e44);
    else if (state)
        FUN_0040fbe0(DAT_01078e10, actor, slot);
    void* newNode = actor ? actor->getNode() : 0;
    unk240 = 0;
    if (newNode != (void*)node && flag2b4)
    {
        flag2b4 = false;
        flag2b5 = false;
    }
    if (enabled && !flag2b4 && actor && actor->getNode() == (void*)node)
        FUN_00800650(*g_011db6d8.Float(), *g_011db750.Float(), true);
    active = state;
    if (active)
        pending[slot] = true;
    index = slot;
    current = actor;
    node = actor ? actor->getNode() : 0;
    pending[slot] = false;
    secondPending[slot] = false;
    if (slot != -1)
    {
        if (secondObjects[slot])
        {
            FUN_004a4410_Class* tmpA = secondObjects[slot];
            FUN_004a4410_Class* oldA = tmpA;
            oldA ? oldA->FUN_004a4410(1) : 0;
            secondObjects[slot] = 0;
        }
        if (firstObjects[slot])
        {
            FUN_004a4410_Class* oldB = firstObjects[slot];
            FUN_004a4410_Class* tmpB = oldB;
            tmpB ? tmpB->FUN_004a4410(1) : 0;
            firstObjects[slot] = 0;
        }
    }
}

struct WeaponPrompt
{
    float FUN_007ebd10();
    float FUN_007ebd30();
    int GetUnk15C();
    const char* FUN_00522be0();
    float GetField378();
};
struct AVPrompt
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerPrompt
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
    AVPrompt values;
};
struct TargetPrompt
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
    virtual bool IsActor();
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
    virtual bool IsCreature();
    bool FUN_00437bd0();
};
struct PromptTile
{
    void Set(int, const char*, bool);
    void SetInt(int, int);
};
struct PromptMenu
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
    PromptTile* primary;
    PromptTile* secondary;
};
struct PromptSetting
{
    float* Float();
    const char* String();
};
extern PlayerPrompt* DAT_011dea3c;

extern WeaponPrompt* DAT_011ca278;
extern bool DAT_011db0cf, DAT_011db0d8;
extern float DAT_011db0bc, DAT_011db0b8, DAT_011db0c4, DAT_011db0c0;
extern PromptSetting originalRuntimeFloatSetting1077, originalRuntimeFloatSetting1078, originalRuntimeFloatSetting1081,
    originalRuntimeFloatSetting1084;
extern PromptSetting g_011d2754, g_011d46c0, g_011d46d8;
void ApplyPerkModifiers(int, PlayerPrompt*, ...);
// @fnv 0x007eb920
void __cdecl FUN_007eb920(WeaponPrompt* weapon)
{
    if (weapon && weapon->FUN_007ebd10() > 0.0 &&
        weapon->FUN_007ebd30() <= DAT_011dea3c->values.Get(weapon->GetUnk15C()))
    {
        ((PromptMenu*)DAT_011db0d4)->primary->Set(0xfc4, weapon->FUN_00522be0(), true);
        ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 1);
        DAT_011db0cf = true;
        ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 0);
        DAT_011db0d8 = false;
        DAT_011db0bc = weapon->GetField378();
        DAT_011db0b8 = weapon->FUN_007ebd10();
        ApplyPerkModifiers(0x28, DAT_011dea3c, weapon ? weapon : DAT_011ca278, &DAT_011db0b8);
    }
    else if ((!weapon || (weapon && weapon->GetUnk15C() == 0x2d)) &&
             DAT_011dea3c->values.Get(0x2d) >= *originalRuntimeFloatSetting1077.Float())
    {
        bool creature = false;
        if (DAT_011f21cc &&
            (((TargetPrompt*)DAT_011f21cc)->IsCreature() ||
             (((TargetPrompt*)DAT_011f21cc)->IsActor() && ((TargetPrompt*)DAT_011f21cc)->FUN_00437bd0())))
        {
            creature = true;
            ((PromptMenu*)DAT_011db0d4)->primary->Set(0xfc4, g_011d2754.String(), true);
            ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 1);
        }
        else
        {
            ((PromptMenu*)DAT_011db0d4)->primary->Set(0xfc4, g_011d46c0.String(), true);
            ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 1);
        }
        DAT_011db0cf = true;
        DAT_011db0bc = 1.0f;
        DAT_011db0b8 = *originalRuntimeFloatSetting1078.Float();
        ApplyPerkModifiers(0x28, DAT_011dea3c, weapon ? weapon : DAT_011ca278, &DAT_011db0b8);
        if (!creature && DAT_011dea3c->values.Get(0x2d) >= *originalRuntimeFloatSetting1081.Float())
        {
            ((PromptMenu*)DAT_011db0d4)->secondary->Set(0xfc4, g_011d46d8.String(), true);
            ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 1);
            DAT_011db0d8 = true;
            DAT_011db0c4 = 1.0f;
            DAT_011db0c0 = *originalRuntimeFloatSetting1084.Float();
            ApplyPerkModifiers(0x28, DAT_011dea3c, weapon ? weapon : DAT_011ca278, &DAT_011db0c0);
        }
        else
        {
            ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 0);
            DAT_011db0d8 = false;
        }
    }
    else
    {
        ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 0);
        DAT_011db0cf = false;
        ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 0);
        DAT_011db0cf = false;
    }
}

namespace VatsShutdown {
struct Actor;
struct Request;
struct Menu
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
    unsigned char unkf8, unkf9, unkfa, closed;
    int FUN_0059bb30();
    void FUN_00a1d910();
};
struct Input
{
    void FUN_007ec380();
    void FUN_00ad8780(int);
};
Input* FUN_00453a70();
struct Tile
{
    void FUN_00700320(int, int);
};
void* FUN_007eb8c0();
Tile* FUN_00a09030(void*);
struct List
{
    bool FUN_008256d0();
    void FUN_00470470();
};
struct Interface
{
    void UpdateActivatePick();
};
Interface* FUN_004b7210();
struct State
{
    bool FUN_0042ce10();
};
struct Sound
{
    unsigned int unk0, unk4, unk8;
    Sound();
    ~Sound();
    Sound& FUN_00418900(const Sound&);
    void Play(int);
};
struct Audio
{
    Sound ResolveAudioHandle(const char*, int);
};
Audio* FUN_00ad9060();
struct Setting
{
    float* FUN_00403e20();
};
struct Request
{
    unsigned int type;
    unsigned char flag4, flag5, flag6, flag7;
    unsigned char mode, unk9, unka, unkb;
    Actor* actor;
    unsigned int action, unk14, unk18, unk1c, unk20;
    unsigned char flag24, unk25, unk26, unk27;
    Request();
};
struct Queue
{
    void FUN_009c6c30(int, int);
    int FUN_005ae380();
    void AddCommand(Request*);
};
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual ~Actor();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool Ready();
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
    virtual void Act(Actor*, int, int, int, int, int, int, int);
    bool FUN_0087f3d0();
    bool FUN_008b8e90(void*);
};
struct Wheel
{
    void FUN_00800ac0(int, int, int);
    void FUN_00800ed0();
};
Wheel* FUN_00705910();
void FUN_005e58f0(int, void*, float*);
float FUN_00476b70(float, float);
void* FUN_0058db10(int);
extern Menu* DAT_011db0d4;
extern Queue DAT_011f2250;
extern unsigned char DAT_011a3b31, DAT_011db0cd;
extern List DAT_011db124, DAT_011db150;
extern State* DAT_011ddf38;
extern const char DAT_01077d84[], DAT_01077d78[], DAT_01077d6c[];
extern Setting DAT_011ce32c, DAT_011ce738;
extern void* DAT_011dea3c;
extern Actor* DAT_011f21e8;
extern Actor* DAT_011f21ec;
extern Actor* DAT_011f21cc;
}
// Closes the VATS menu, plays sounds, queues action requests for the actors and resets the VATS queue and wheel state.
// @fnv 0x007ebd50
void ShutdownVats()
{
    namespace V = VatsShutdown;
    if (!V::DAT_011db0d4 || V::DAT_011db0d4->FUN_0059bb30() != 1)
        return;
    if (!V::DAT_011db0d4->closed)
        V::FUN_00453a70()->FUN_007ec380();
    V::DAT_011db0d4->closed = 1;
    V::Tile* tile = V::FUN_00a09030(V::FUN_007eb8c0());
    if (!tile)
    {
        V::DAT_011f2250.FUN_009c6c30(0, 0);
        V::DAT_011a3b31 = 0;
        return;
    }
    if (V::DAT_011db0d4)
    {
        if (!V::DAT_011db124.FUN_008256d0())
            V::DAT_011db124.FUN_00470470();
        V::FUN_004b7210()->UpdateActivatePick();
        V::FUN_00453a70()->FUN_00ad8780(256);
        if (!V::DAT_011ddf38->FUN_0042ce10())
        {
            V::Audio* audioSlot0 = V::FUN_00ad9060();
            V::Sound soundSlot0;
            if (V::DAT_011db150.FUN_008256d0())
                soundSlot0.FUN_00418900(audioSlot0->ResolveAudioHandle(V::DAT_01077d84, 289));
            else
                soundSlot0.FUN_00418900(audioSlot0->ResolveAudioHandle(V::DAT_01077d78, 289));
            soundSlot0.Play(0);
        }
        tile->FUN_00700320(6002, 1);
        V::DAT_011db0d4->FUN_00a1d910();
    }
    if (V::DAT_011f2250.FUN_005ae380())
    {
        V::Audio* audioSlot0 = V::FUN_00ad9060();
        V::Sound soundSlot0;
        soundSlot0.FUN_00418900(audioSlot0->ResolveAudioHandle(V::DAT_01077d6c, 289));
        soundSlot0.Play(0);
        float chanceASlot14 = *V::DAT_011ce32c.FUN_00403e20();
        float chanceBSlot0 = *V::DAT_011ce738.FUN_00403e20();
        V::FUN_005e58f0(67, V::DAT_011dea3c, &chanceASlot14);
        V::FUN_005e58f0(67, V::DAT_011dea3c, &chanceBSlot0);
        if (V::DAT_011f21e8 && V::DAT_011f21cc && V::DAT_011f21cc->Ready() && !V::DAT_011f21cc->FUN_0087f3d0() &&
            chanceBSlot0 >= V::FUN_00476b70(0.0f, 1.0f))
        {
            void* perk = V::FUN_0058db10(8);
            if (perk && !V::DAT_011f21cc->FUN_008b8e90(perk))
            {
                V::Request* action = new V::Request();
                action->action = 25;
                action->mode = 5;
                action->type = 3;
                action->flag6 = 1;
                action->actor = V::DAT_011f21cc;
                action->flag4 = 1;
                V::DAT_011f2250.AddCommand(action);
                V::DAT_011f21e8->Act(V::DAT_011f21cc, 0, 1, 1, 0, 0, 1, 0);
            }
        }
        if (V::DAT_011f21ec && V::DAT_011f21cc && V::DAT_011f21cc->Ready() && !V::DAT_011f21cc->FUN_0087f3d0() &&
            chanceASlot14 >= V::FUN_00476b70(0.0f, 1.0f))
        {
            V::Request* action = new V::Request();
            action->action = 25;
            action->mode = 5;
            action->type = 3;
            action->flag24 = 1;
            action->actor = V::DAT_011f21cc;
            action->flag4 = 1;
            V::DAT_011f2250.AddCommand(action);
            V::DAT_011f21ec->Act(V::DAT_011f21cc, 0, 1, 1, 0, 0, 1, 0);
        }
        V::DAT_011f2250.FUN_009c6c30(4, 0);
    }
    else
    {
        V::DAT_011f2250.FUN_009c6c30(0, 0);
        V::DAT_011a3b31 = 0;
        if (V::DAT_011f21e8)
        {
            delete V::DAT_011f21e8;
            V::DAT_011f21e8 = 0;
        }
        if (V::DAT_011f21ec)
        {
            delete V::DAT_011f21ec;
            V::DAT_011f21ec = 0;
        }
    }
    V::FUN_00705910()->FUN_00800ac0(0, -1, 0);
    V::FUN_00705910()->FUN_00800ed0();
    V::DAT_011db0cd = 0;
}

namespace fnv_007ec3a0 {
struct Actor85;
struct Process85;
struct Weapon85
{
    bool FUN_006450c0();
};
struct Item85
{
    Weapon85* FUN_0044ddc0();
};
struct Actor85
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
    virtual bool IsActor();
    Process85* FUN_008d8520();
};
struct Process85
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
    virtual Item85* Weapon();
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
    virtual bool Busy();
};
struct Limb85
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int part;
    int unk24;
    int unk28;
    unsigned short unk2c;
    bool flag;
    unsigned char unk2f;
};
struct LimbList85
{
    Limb85* item;
    LimbList85* next;
    bool FUN_008256d0();
    Limb85** FUN_006815c0();
    LimbList85* FUN_00726070();
};
struct Target85
{
    Actor85* actor;
    int type;
    LimbList85 limbs;
};
struct TargetList85
{
    Target85** FUN_006815c0();
};
struct Mode85
{
    int FUN_0044ddc0();
};
struct Menu85
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
    float damage;
    Limb85* current;
    TargetList85* FindListEntryForTarget(Actor85*);
    int FUN_007f3bf0(int);
    float FUN_007f48e0();
};
extern Actor85* DAT_011db0d0;
extern Actor85* DAT_011dea3c;
extern int DAT_011a0b70;
struct Sound85
{
    int unk00, unk04, unk08;
    Sound85();
    ~Sound85();
    void FUN_00418900(const Sound85&);
    void Play(int);
};
struct Audio85
{
    Sound85 FUN_00ad7550(const char*, int);
};
Audio85* FUN_00453a70();
struct Highlight85
{
    void FUN_00800ac0(Actor85*, int, int);
    void AppendValue(int);
};
Highlight85* FUN_00705910();
// Refreshes the VATS target highlight and damage for the current target part, playing a select sound and updating the highlighted actor and part globals.
// @fnv 0x007ec3a0
void UpdateVatsTargetHighlight(bool force)
{
    if (((Menu85*)DAT_011db0d4))
    {
        TargetList85* target13 = ((Menu85*)DAT_011db0d4)->FindListEntryForTarget(((Actor85*)DAT_011f21cc));
        if (force || (((Mode85*)&DAT_011f2250)->FUN_0044ddc0() == 2 &&
                      (((Menu85*)DAT_011db0d4)->FUN_007f3bf0(DAT_011a0b70) !=
                           ((Menu85*)DAT_011db0d4)->FUN_007f3bf0(((Menu85*)DAT_011db0d4)->current->part) ||
                       DAT_011db0d0 != ((Actor85*)DAT_011f21cc))))
        {
            if (!force && DAT_011db0d0 == ((Actor85*)DAT_011f21cc) && !DAT_011dea3c->FUN_008d8520()->Busy())
            {
                Sound85 sound;
                sound.FUN_00418900(FUN_00453a70()->FUN_00ad7550("UIVATSSelectTargetPart", 289));
                sound.Play(0);
            }
            ((Menu85*)DAT_011db0d4)->damage = ((Menu85*)DAT_011db0d4)->FUN_007f48e0();
            Actor85* actor4 = 0;
            if (target13 && *target13->FUN_006815c0() && (*target13->FUN_006815c0())->actor->IsActor())
                actor4 = (*target13->FUN_006815c0())->actor;
            Item85* item6 = DAT_011dea3c->FUN_008d8520()->Weapon();
            Weapon85* weapon6 = item6 ? item6->FUN_0044ddc0() : 0;
            if (target13 && ((*target13->FUN_006815c0())->type == 2 || DAT_011dea3c->FUN_008d8520()->Busy() ||
                             !weapon6 || weapon6->FUN_006450c0()))
            {
                if (force ||
                    (((Mode85*)&DAT_011f2250)->FUN_0044ddc0() == 2 && DAT_011db0d0 != ((Actor85*)DAT_011f21cc)))
                {
                    if (((Mode85*)&DAT_011f2250)->FUN_0044ddc0() == 3)
                        FUN_00705910()->FUN_00800ac0((*target13->FUN_006815c0())->actor,
                                                     ((Menu85*)DAT_011db0d4)->current->part, 1);
                    else
                        FUN_00705910()->FUN_00800ac0((*target13->FUN_006815c0())->actor, 15, 0);
                    DAT_011db0d0 = (*target13->FUN_006815c0())->actor;
                }
                DAT_011a0b70 = ((Menu85*)DAT_011db0d4)->current->part;
            }
            else if (actor4 && actor4->FUN_008d8520())
            {
                if (!((Menu85*)DAT_011db0d4)->current->flag && ((Mode85*)&DAT_011f2250)->FUN_0044ddc0() == 3)
                    FUN_00705910()->FUN_00800ac0(((Actor85*)DAT_011f21cc), ((Menu85*)DAT_011db0d4)->current->part, 1);
                else
                    FUN_00705910()->FUN_00800ac0(((Actor85*)DAT_011f21cc), ((Menu85*)DAT_011db0d4)->current->part, 0);
                LimbList85* limb =
                    &(*((Menu85*)DAT_011db0d4)->FindListEntryForTarget(((Actor85*)DAT_011f21cc))->FUN_006815c0())
                         ->limbs;
                while (limb && !limb->FUN_008256d0())
                {
                    if (((Menu85*)DAT_011db0d4)->FUN_007f3bf0((*limb->FUN_006815c0())->part) ==
                            ((Menu85*)DAT_011db0d4)->FUN_007f3bf0(((Menu85*)DAT_011db0d4)->current->part) &&
                        *limb->FUN_006815c0() != ((Menu85*)DAT_011db0d4)->current)
                        FUN_00705910()->AppendValue((*limb->FUN_006815c0())->part);
                    limb = limb->FUN_00726070();
                }
                DAT_011a0b70 = ((Menu85*)DAT_011db0d4)->current->part;
                DAT_011db0d0 = ((Actor85*)DAT_011f21cc);
            }
        }
    }
}
}  // namespace fnv_007ec3a0

extern int DAT_011a59f0;
struct InputProcessX;
struct RefX
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
    virtual bool v64();
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
    virtual InputProcessX* v82();
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
    virtual int v116();
    unsigned int FUN_0044ddc0();
};
struct InputProcessX
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
    virtual RefX* v82();
};
struct PlayerX
{
    InputProcessX* GetCurrentProcess();
};
extern PlayerX* inputPlayer;
struct SoundX
{
    int id;
    int flags;
    int state;
    SoundX();
    ~SoundX();
    SoundX& operator=(const SoundX&);
    bool Play(bool);
};
struct InputAudioX
{
    static InputAudioX* GetSingleton();
    SoundX GetSoundHandleByEditorID(const char*, unsigned);
};
struct InputTileX
{
    void RemoveFadeItemsForTile(int);
    void Set(int, int);
};
struct ItemX;
struct ItemsX
{
    void* data;
    ItemsX* next;
    ItemX** FUN_006815c0();
    bool FUN_008256d0();
    ItemsX* FUN_00726070();
};
struct InputTargetX
{
    RefX* ref;
    int type;
    ItemsX items;
    unsigned char special;
};
struct TargetsX
{
    InputTargetX** FUN_006815c0();
    bool FUN_008256d0();
    TargetsX* FUN_00726070();
    unsigned GetSize();
};
struct ItemX
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
    unsigned char unk2c;
    bool selected;
    bool queued;
    unsigned char unk2f;
    InputTileX* tile;
};
extern RefX* selectedTarget;
struct MenuX
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
    bool heading;
    bool meters;
    bool lit;
    bool closing;
    float damage;
    ItemX* current;
    bool perk;
    unsigned char unk105;
    unsigned short unk106;
    ItemX* last;
    bool stick;
    bool targetStick;
    bool mouse;
    bool left;
    bool right;
    void HandleInput(int key, int held);
    void SelectTarget(bool);
    ItemsX* FindListEntryByValue(int);
    TargetsX* FindListEntryForTarget(RefX*);
    void AssignActionTiles(TargetsX*);
    void UpdateQueueEntry(int, int, int);
    float FUN_007f48e0();
    void FUN_007f3070();
};

struct VatsX
{
    unsigned int FUN_0044ddc0();
    void* FUN_005d8710();
    void FUN_009c9ae0(RefX*);
};

bool FUN_007f4bb0();
bool FUN_007f4c00();
bool _FUN_004b71d0();
void* FUN_004b7210();
void FUN_007f3bd0(int);
void FUN_00705780();
extern bool DAT_011db0b2;
extern bool DAT_011db0b3;
void FUN_007eb920(unsigned);
// Handles a VATS menu key press: updates left/right state, plays sounds, cycles the selected target and its items, and refreshes the menu.
// @fnv 0x007eecb0
void MenuX::HandleInput(int key, int held)
{
    RefX* item = inputPlayer->GetCurrentProcess()->v82();
    unsigned flags = item ? item->FUN_0044ddc0() : 0;
    if (left)
    {
        if (FUN_007f4bb0())
        {
            SelectTarget(true);
            left = false;
            return;
        }
        left = false;
    }
    if (right)
    {
        if (FUN_007f4c00())
        {
            SelectTarget(false);
            right = false;
            return;
        }
        right = false;
    }
    SoundX sound7;
    FUN_004b7210();
    if (_FUN_004b71d0() && !targetStick)
        return;
    ItemsX* weapon;
    TargetsX* target4 = reinterpret_cast<TargetsX*>(&g_011db150);
    switch (key)
    {
    case 2:
        if (reinterpret_cast<TargetsX*>(&g_011db150)->GetSize() <= 1)
        {
            sound7 = InputAudioX::GetSingleton()->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121);
            sound7.Play(false);
            return;
        }
        sound7 = InputAudioX::GetSingleton()->GetSoundHandleByEditorID("UIVATSSelectTarget", 0x121);
        sound7.Play(false);
        target4 = reinterpret_cast<TargetsX*>(&g_011db150);
        while (target4 && !target4->FUN_008256d0())
        {
            weapon = &(*target4->FUN_006815c0())->items;
            while (weapon && !weapon->FUN_008256d0() && (*weapon->FUN_006815c0())->tile)
            {
                (*weapon->FUN_006815c0())->tile->RemoveFadeItemsForTile(0xfa9);
                (*weapon->FUN_006815c0())->tile->Set(0xfa9, 0);
                weapon = weapon->FUN_00726070();
            }
            target4 = target4->FUN_00726070();
        }
        target4 = reinterpret_cast<TargetsX*>(&g_011db150);
        while (target4)
        {
            if ((*target4->FUN_006815c0())->ref && (*target4->FUN_006815c0())->ref->v116() && target4->FUN_00726070() &&
                (*target4->FUN_00726070()->FUN_006815c0())->ref == selectedTarget)
            {
                selectedTarget = (*target4->FUN_006815c0())->ref;
                ItemsX* items = &(*target4->FUN_006815c0())->items;
                ItemsX* found = FindListEntryByValue(0x1a);
                if ((*target4->FUN_006815c0())->type == 1 && found)
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *found->FUN_006815c0();
                else
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *items->FUN_006815c0();
                break;
            }
            else if (!target4->FUN_00726070())
            {
                selectedTarget = (*target4->FUN_006815c0())->ref;
                ItemsX* found = FindListEntryByValue(0x1a);
                if ((*target4->FUN_006815c0())->type == 1 && found)
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *found->FUN_006815c0();
                else
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *(*target4->FUN_006815c0())->items.FUN_006815c0();
            }
            target4 = target4->FUN_00726070();
        }
        FUN_007f3bd0(0);
        if (!(*FindListEntryForTarget(selectedTarget)->FUN_006815c0())->special)
        {
            ItemsX* weapon = &(*FindListEntryForTarget(selectedTarget)->FUN_006815c0())->items;
            while (weapon && !weapon->FUN_008256d0())
            {
                (*weapon->FUN_006815c0())->selected = false;
                (*weapon->FUN_006815c0())->queued = false;
                weapon = weapon->FUN_00726070();
            }
        }
        if (!(*(*FindListEntryForTarget(selectedTarget)->FUN_006815c0())->items.FUN_006815c0())->tile)
            AssignActionTiles(FindListEntryForTarget(selectedTarget));
        break;
    case 3:
        if (reinterpret_cast<TargetsX*>(&g_011db150)->GetSize() <= 1)
        {
            sound7 = InputAudioX::GetSingleton()->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121);
            sound7.Play(false);
            return;
        }
        sound7 = InputAudioX::GetSingleton()->GetSoundHandleByEditorID("UIVATSSelectTarget", 0x121);
        sound7.Play(false);
        target4 = reinterpret_cast<TargetsX*>(&g_011db150);
        while (target4 && !target4->FUN_008256d0())
        {
            weapon = &(*target4->FUN_006815c0())->items;
            while (weapon && !weapon->FUN_008256d0() && (*weapon->FUN_006815c0())->tile)
            {
                (*weapon->FUN_006815c0())->tile->RemoveFadeItemsForTile(0xfa9);
                (*weapon->FUN_006815c0())->tile->Set(0xfa9, 0);
                weapon = weapon->FUN_00726070();
            }
            target4 = target4->FUN_00726070();
        }
        target4 = reinterpret_cast<TargetsX*>(&g_011db150);
        while (target4)
        {
            if (selectedTarget == (*target4->FUN_006815c0())->ref)
            {
                if (target4->FUN_00726070() && (*target4->FUN_00726070()->FUN_006815c0())->ref &&
                    (*target4->FUN_00726070()->FUN_006815c0())->ref->v116())
                {
                    selectedTarget = (*target4->FUN_00726070()->FUN_006815c0())->ref;
                    ItemsX* items = &(*target4->FUN_00726070()->FUN_006815c0())->items;
                    ItemsX* found = FindListEntryByValue(0x1a);
                    if ((*target4->FUN_006815c0())->type == 1 && found)
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *found->FUN_006815c0();
                    else
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *items->FUN_006815c0();
                    break;
                }
                else
                {
                    selectedTarget = (*reinterpret_cast<TargetsX*>(&g_011db150)->FUN_006815c0())->ref;
                    ItemsX* found = FindListEntryByValue(0x1a);
                    if ((*target4->FUN_006815c0())->type == 1 && found)
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *found->FUN_006815c0();
                    else
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current =
                            *(*reinterpret_cast<TargetsX*>(&g_011db150)->FUN_006815c0())->items.FUN_006815c0();
                }
            }
            target4 = target4->FUN_00726070();
        }
        FUN_007f3bd0(0);
        if (!(*FindListEntryForTarget(selectedTarget)->FUN_006815c0())->special)
        {
            ItemsX* weapon = &(*FindListEntryForTarget(selectedTarget)->FUN_006815c0())->items;
            while (weapon && !weapon->FUN_008256d0())
            {
                (*weapon->FUN_006815c0())->selected = false;
                (*weapon->FUN_006815c0())->queued = false;
                weapon = weapon->FUN_00726070();
            }
        }
        if (!(*(*FindListEntryForTarget(selectedTarget)->FUN_006815c0())->items.FUN_006815c0())->tile)
            AssignActionTiles(FindListEntryForTarget(selectedTarget));
        break;
    case 4:
        if (!closing)
            FUN_00705780();
        break;
    case 30:
        if (!closing)
            DAT_011db0b2 = true;
        break;
    case 31:
        if (!closing)
            DAT_011db0b3 = true;
        break;
    case 5:
        if (!closing && reinterpret_cast<VatsX*>(&DAT_011f2250)->FUN_0044ddc0() == 2 && heading)
        {
            UpdateQueueEntry(0, 0, 0);
            reinterpret_cast<MenuX*>(DAT_011db0d4)->damage = reinterpret_cast<MenuX*>(DAT_011db0d4)->FUN_007f48e0();
        }
        break;
    }
    if (selectedTarget && selectedTarget->v64())
        DAT_011a59f0 = 25;
    FUN_007eb920(flags);
    FUN_007f3070();
    if (reinterpret_cast<VatsX*>(&DAT_011f2250)->FUN_005d8710() && selectedTarget)
        reinterpret_cast<VatsX*>(&DAT_011f2250)->FUN_009c9ae0(selectedTarget);
}

namespace std {
float abs(float);
}
float GetAngleBetweenPoints(const NiPoint3&, const NiPoint3&);

struct SortRef
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
    virtual NiPoint3* GetPos();
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
    virtual float GetCurrentTargetDistance(int);
};
struct Actor;
extern Actor* _g_thePlayer;

// Sorts two objects by the absolute angular difference between the player's heading and the direction from the player to each object's position.
// @fnv 0x007f0380
int __cdecl CompareByHeadingToPlayer(const void* apRefA, const void* apRefB)
{
    NiPoint3 kPlayerPosition = *((SortRef*)_g_thePlayer)->GetPos();
    float fPlayerRot = ((SortRef*)_g_thePlayer)->GetCurrentTargetDistance(0) * 57.2957763671875;
    float fHeadingToA = GetAngleBetweenPoints(kPlayerPosition, *(*(SortRef**)apRefA)->GetPos());
    float fHeadingToB = GetAngleBetweenPoints(kPlayerPosition, *(*(SortRef**)apRefB)->GetPos());
    float fDifference = std::abs(fPlayerRot - fHeadingToA);
    fHeadingToA = std::abs((float)(fDifference > 180.0 ? 360.0 - fDifference : fDifference));
    fDifference = std::abs(fPlayerRot - fHeadingToB);
    fHeadingToB = std::abs((float)(fDifference > 180.0 ? 360.0 - fDifference : fDifference));
    if (fHeadingToA < fHeadingToB)
        return -1;
    else if (fHeadingToA > fHeadingToB)
        return 1;
    else
        return 0;
}

struct VisPoint3
{
    float x;
    float y;
    float z;
};
struct VisCamera
{
    bool ProjectToScreen(const VisPoint3& kPt, float& fX, float& fY, float fZeroTolerance);
};
struct VisCameraNode
{
    VisCamera* FUN_006629f0();
};
VisCameraNode* __cdecl VisGetCameraNode();

struct VisMarker
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    VisPoint3 kPos;
    int unk20;
    int unk24;
    int unk28;
    bool bHidden;
};
struct VisMarkerHolder
{
    int unk00;
    int unk04;
    struct VisNode* pFirst;
};
struct VisNode
{
    VisMarker*& FUN_006815c0();
    bool FUN_008256d0();
    VisNode* FUN_00726070();
};
struct VisList
{
    VisMarkerHolder*& FUN_006815c0();
};
extern int g_iVisListID;

struct FUN_007f05b0_Menu
{
    VisList* FindListEntryForTarget(int aiID);
    bool HasVisibleMarkerOnScreen();
};

// Walks the marker list, projecting each non-hidden marker's position to screen space and returning true if any lands inside the viewport.
// @fnv 0x007f05b0
bool FUN_007f05b0_Menu::HasVisibleMarkerOnScreen()
{
    VisList* pList;
    VisNode* pNode5;

    pList = FindListEntryForTarget(g_iVisListID);
    pNode5 = (VisNode*)&pList->FUN_006815c0()->pFirst;
    while (pNode5 && !pNode5->FUN_008256d0())
    {
        if (!pNode5->FUN_006815c0()->bHidden)
        {
            VisPoint3 kPos2 = pNode5->FUN_006815c0()->kPos;
            float fX2 = 0.0f;
            float fY3 = 0.0f;
            VisGetCameraNode()->FUN_006629f0()->ProjectToScreen(kPos2, fX2, fY3, 1e-05f);
            bool bProjectedOnScreen = (!(fX2 <= 0.0) && !(fY3 <= 0.0) && !(fX2 >= 1.0) && !(fY3 >= 1.0)) ? true : false;
            if (bProjectedOnScreen)
                return true;
        }
        pNode5 = pNode5->FUN_00726070();
    }
    return false;
}

namespace fnv_007f07a0 {
struct FormX
{
    unsigned int FUN_0044ddc0();
    bool FUN_006450c0();
};
struct TileX
{
    float FUN_00a011b0(int);
    void RemoveFadeItemsForTile(int);
    void FUN_00a012d0(int, float, bool);
    bool FUN_00a07fc0(int);
    float GetTraitFloat(int);
    int FindValueByKey(int);
    void StartFade(int, float, float, float, int);
    void FUN_00700320(int, int);
};
struct ChanceX
{
    char pad00[0x20];
    int f20;
    char pad24[0x2c - 0x24];
    unsigned char b2c;
    unsigned char b2d;
    char pad2e;
    unsigned char b2f;
    TileX* tile;
};
struct VTarget
{
    char pad00[4];
    int f04;
    char pad08[0x10 - 8];
    unsigned char b10;
    char pad11[3];
};
struct LimbX
{
    char pad00[0x20];
    int f20;
};
struct ProcX
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
    virtual FormX* vt148();
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
    virtual bool vt1a8();
};
struct ActorX
{
    ProcX* FUN_008d8520();
};
struct InterpX
{
    void FUN_009c6c30(int, bool);
};
struct TimeG
{
    unsigned int FUN_00825c00();
};
struct Owner7
{
    char pad00[0xf8];
    unsigned char bF8;
    unsigned char bF9;
    char padFA[0x100 - 0xfa];
    LimbX* m_pTargetChance;
    BSSimpleList* FindListEntryForTarget(void*);
    bool HasVisibleMarkerOnScreen();
    void* FUN_007f3bf0(int);
    void UpdateLimbTiles();
    void UpdateLimbHighlight();
};
extern ActorX* DAT_011dea3c;
extern int DAT_011f2250;
extern TimeG DAT_011f6394;
extern unsigned char DAT_011db0ce;
extern int DAT_011db0dc;
extern const char str_01077df4[];
extern const char str_01077de8[];
extern const char str_01077dd4[];
extern const char str_010734b8[];
int __cdecl TraitNameToIDAdd(const char*, int);
// @fnv 0x007f07a0
void Owner7::UpdateLimbHighlight()
{
    static int sMeterPercent = TraitNameToIDAdd(str_01077df4, -1);
    static int sLimbName = TraitNameToIDAdd(str_01077de8, -1);
    static int sLimbNameVisible = TraitNameToIDAdd(str_01077dd4, -1);
    static int sBrightness = TraitNameToIDAdd(str_010734b8, -1);
    BSSimpleList* node7;
    BSSimpleList* list6;
    list6 = FindListEntryForTarget(DAT_011f21cc);
    node7 = (BSSimpleList*)((char*)(*list6->FUN_006815c0()) + 8);
    if (((FormX*)&DAT_011f2250)->FUN_0044ddc0() == 1 || ((FormX*)&DAT_011f2250)->FUN_0044ddc0() == 3 ||
        (((FormX*)&DAT_011f2250)->FUN_0044ddc0() == 2 && !bF8))
    {
        while (node7 != 0 && !node7->FUN_008256d0())
        {
            if (((ChanceX*)*node7->FUN_006815c0())->tile->FUN_00a011b0(0xfa9) > 0.0)
            {
                ((ChanceX*)*node7->FUN_006815c0())->tile->RemoveFadeItemsForTile(0xfa9);
                ((ChanceX*)*node7->FUN_006815c0())->tile->FUN_00a012d0(0xfa9, 0.0f, true);
            }
            node7 = node7->FUN_00726070();
        }
        bF9 = 0;
        return;
    }
    else if (bF9 == 1)
    {
        BSSimpleList* savedNodeA;
        FormX* formTmp;
        formTmp = DAT_011dea3c->FUN_008d8520()->vt148();
        unsigned int typeC5;
        typeC5 = formTmp ? formTmp->FUN_0044ddc0() : 0;
        bool flag4;
        flag4 = false;
        if (((VTarget*)*list6->FUN_006815c0())->f04 == 2 || DAT_011dea3c->FUN_008d8520()->vt1a8() || typeC5 == 0 ||
            ((FormX*)typeC5)->FUN_006450c0())
        {
            flag4 = true;
        }
        savedNodeA = 0;
        while (!flag4 && node7 != 0 && !node7->FUN_008256d0())
        {
            if (HasVisibleMarkerOnScreen() ||
                (((ChanceX*)*node7->FUN_006815c0())->b2d == 0 && ((ChanceX*)*node7->FUN_006815c0())->b2c != 0 &&
                 ((ChanceX*)*node7->FUN_006815c0())->b2f != 0))
            {
                DAT_011db0ce = 1;
                ((VTarget*)*list6->FUN_006815c0())->b10 = 0;
                if (((FormX*)&DAT_011f2250)->FUN_0044ddc0() != 3)
                {
                    ((InterpX*)&DAT_011f2250)->FUN_009c6c30(3, false);
                    DAT_011db0dc = DAT_011f6394.FUN_00825c00();
                }
                return;
            }
            if (((ChanceX*)*node7->FUN_006815c0())->f20 == 1)
                savedNodeA = node7;
            node7 = node7->FUN_00726070();
        }
        node7 = (BSSimpleList*)((char*)(*list6->FUN_006815c0()) + 8);
        while (node7 != 0 && !node7->FUN_008256d0())
        {
            float fVal8;
            fVal8 = ((ChanceX*)*node7->FUN_006815c0())->tile->FUN_00a011b0(0xfa9);
            if (((ChanceX*)*node7->FUN_006815c0())->b2c != 0)
            {
                ((ChanceX*)*node7->FUN_006815c0())->b2f = 0;
                FormX* formC3;
                formC3 = DAT_011dea3c->FUN_008d8520()->vt148();
                unsigned int typeC4;
                typeC4 = formC3 ? formC3->FUN_0044ddc0() : 0;
                if (DAT_011dea3c->FUN_008d8520()->vt1a8() || typeC4 == 0 || ((FormX*)typeC4)->FUN_006450c0())
                {
                    if ((savedNodeA != 0 && node7 == savedNodeA) || (savedNodeA == 0 && node7->FUN_00726070() == 0))
                    {
                        if (((ChanceX*)*node7->FUN_006815c0())->tile->FUN_00a07fc0(0xfa9))
                        {
                            ((ChanceX*)*node7->FUN_006815c0())->tile->StartFade(0xfa9, 0.0f, 255.0f, 1.0f, 1);
                        }
                    }
                }
                else
                {
                    if (m_pTargetChance != (LimbX*)((ChanceX*)*node7->FUN_006815c0()) &&
                        (int)FUN_007f3bf0(((ChanceX*)*node7->FUN_006815c0())->f20) !=
                            (int)FUN_007f3bf0(m_pTargetChance->f20))
                    {
                        if ((fVal8 == ((ChanceX*)*node7->FUN_006815c0())->tile->GetTraitFloat(0xfa9) &&
                             fVal8 != 255.0) ||
                            ((ChanceX*)*node7->FUN_006815c0())->tile->FindValueByKey(0xfa9) == 1)
                        {
                            ((ChanceX*)*node7->FUN_006815c0())->tile->StartFade(0xfa9, fVal8, 255.0f, 0.2f, 0);
                        }
                    }
                    else
                    {
                        if (((ChanceX*)*node7->FUN_006815c0())->tile->FUN_00a07fc0(0xfa9))
                        {
                            ((ChanceX*)*node7->FUN_006815c0())->tile->StartFade(0xfa9, 0.0f, 255.0f, 1.0f, 1);
                        }
                    }
                }
            }
            else
            {
                if (((ChanceX*)*node7->FUN_006815c0())->tile->GetTraitFloat(0xfa9) > 0.0)
                {
                    ((ChanceX*)*node7->FUN_006815c0())
                        ->tile->StartFade(0xfa9, ((ChanceX*)*node7->FUN_006815c0())->tile->FUN_00a011b0(0xfa9), 0.0f,
                                          0.5f, 0);
                }
            }
        advance:
            ((ChanceX*)*node7->FUN_006815c0())
                ->tile->FUN_00700320(
                    sLimbNameVisible,
                    (int)((Owner7*)DAT_011db0d4)->FUN_007f3bf0(((Owner7*)DAT_011db0d4)->m_pTargetChance->f20) ==
                            (int)((Owner7*)DAT_011db0d4)->FUN_007f3bf0(((ChanceX*)*node7->FUN_006815c0())->f20)
                        ? 1
                        : 0);
            node7 = node7->FUN_00726070();
        }
        return;
    }
    bF9 = 1;
    UpdateLimbTiles();
}
}  // namespace fnv_007f07a0

struct TileX2 : TileX
{
    float GetFloat(int aeID);
    void SetFloat(int aeID, float afValue, bool abPropagate);
};

struct VATSX2 : VATSX
{
    CommandX* FUN_009c71f0();
};

struct QueueX2 : QueueX
{
    bool IsEmpty();
};

struct ActorX2 : ActorX
{
    WeaponX* FUN_008a1710();
};

struct ActorSub30
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual bool v14();
};

struct ActorBaseStandIn : ActorBaseX
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
    ActorSub30 sub30;
};

int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);
int MinInt(int a1, int a2);

// @fnv 0x007f0ea0
void VATSMenuX::UpdateHitChanceDisplay()
{
    TargetX* target4;
    ListX<ChanceX*>* node_;
    ListX<TargetX*>* targets_2;
    ListX<ChanceX*>* nextNodeTmp;
    ChanceX* pItem;
    char buffer3[8];
    int count7;
    ChanceX* pOtherItem;

    targets_2 = this->FindListEntryForTarget(xDAT_011f21cc);
    target4 = targets_2->GetItem();
    node_ = &target4->kLimbs;
    while (node_ && !node_->IsEmpty())
    {
        pItem = node_->GetItem();
        nextNodeTmp = node_->GetNext();
        switch (pItem->m_iActionValue)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            while (nextNodeTmp && !nextNodeTmp->IsEmpty())
            {
                pOtherItem = nextNodeTmp->GetItem();
                if (this->FUN_007f3bf0(pItem->m_iActionValue) == this->FUN_007f3bf0(pOtherItem->m_iActionValue))
                {
                    if (((TileX2*)pOtherItem->iHitCount) == 0)
                    {
                        this->AssignActionTiles(this->FindListEntryForTarget(xDAT_011f21cc));
                    }
                    if (pOtherItem != pItem)
                    {
                        if (pOtherItem->m_iActionValue == 1)
                        {
                            ((TileX2*)pItem->iHitCount)->SetInt(0xfa3, 0);
                        }
                        else if (pItem->m_iActionValue == 1)
                        {
                            ((TileX2*)pOtherItem->iHitCount)->SetInt(0xfa3, 0);
                        }
                        else
                        {
                            ((TileX2*)pOtherItem->iHitCount)->SetInt(0xfa3, 0);
                        }
                    }
                    if (((TileX2*)pOtherItem->iHitCount)->GetFloat(xFUN_00a00940("_MeterPercent", -1)) <
                        ((TileX2*)pItem->iHitCount)->GetFloat(xFUN_00a00940("_MeterPercent", -1)))
                    {
                        ((TileX2*)pItem->iHitCount)
                            ->SetFloat(xFUN_00a00940("_MeterPercent", -1),
                                       ((TileX2*)pOtherItem->iHitCount)->GetFloat(xFUN_00a00940("_MeterPercent", -1)),
                                       true);
                    }
                    if (pOtherItem->fHitChance > pItem->fHitChance)
                    {
                        pItem->fHitChance = pOtherItem->fHitChance;
                    }
                }
                nextNodeTmp = nextNodeTmp->GetNext();
            }
            break;
        }

        count7 =
            (!((QueueX2*)xDAT_011f2250._ref_006815c0())->IsEmpty() &&
             ((VATSX2*)&xDAT_011f2250)->FUN_009c71f0()->m_iActionValue == this->FUN_007f3bf0(pItem->m_iActionValue))
                ? this->GetConsecutiveMatchCount() + 1
                : 0;

        if ((((ActorX2*)xDAT_011dea3c)->FUN_008a1710() == 0 ||
             xFUN_006450c0(((ActorX2*)xDAT_011dea3c)->FUN_008a1710())) &&
            xDAT_011f21cc->IsActor() && ((ActorBaseStandIn*)xDAT_011f21cc->GetActorBase())->sub30.v14())
        {
            sprintf_s(buffer3, 8, "%i%%", 0);
            pItem->fHitChance = 0.0f;
        }
        else
        {
            if (count7 > 0 && this->m_bStateFlag4)
            {
                sprintf_s(
                    buffer3, 8, "%i%%",
                    xFUN_00647b70(0, MinInt((int)(pItem->fHitChance * 100.0 + *xDAT_011d4210.Int() * count7), 95)));
            }
            else
            {
                sprintf_s(buffer3, 8, "%i%%", xFUN_00647b70(0, MinInt((int)(pItem->fHitChance * 100.0), 95)));
            }
        }

        if (((TileX2*)pItem->iHitCount) == 0)
        {
            this->AssignActionTiles(this->FindListEntryForTarget(xDAT_011f21cc));
        }
        ((TileX2*)pItem->iHitCount)->Set(0xfc4, buffer3, true);
        node_ = node_->GetNext();
    }
}

namespace fnv_007f1290 {
extern float DAT_01016970;
extern float DAT_0101e704;
extern double DAT_01012070;
extern double DAT_01012060;
extern double DAT_01017a40;
extern double DAT_01011590;
extern WeaponX* DAT_011ca278;

struct ListReader1290
{
    ChanceX** FUN_006815c0();
};
struct Actor1290
{
    ActorBaseX* FUN_004181e0();
    float FUN_00571600();
    float GetCachedSpeed(int);
};
struct Form1290
{
    float FUN_004bcdb0(int);
};
struct Weapon1290
{
    float FUN_0050ebf0();
    bool FUN_006450c0();
};
struct FUN_006dcd70
{
    float m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24;
    FUN_006dcd70(ActorX*);
    ~FUN_006dcd70();
};
struct Point1290
{
    float x, y, z;
    Point1290 FUN_00439ef0(const Point1290&);
    float FUN_00457990();
};
struct TempSound1290
{
    void FUN_00407e00(int, bool);
};
struct TemporaryCommand1290
{
    int action;
    bool active;
    char shotCount;
    char extraShot;
    bool flag7;
    unsigned char shots;
    unsigned char extra;
    unsigned short unk0a;
    ActorX* target;
    int limb;
    TempSound1290* sound;
    int weaponIndex;
    int flags;
    float apCost;
    void FUN_009ca500();
};
struct VATSMenu1290 : VATSMenuX
{
    bool hasCalculated;
    TemporaryCommand1290 activeCommand;
    float CalculateVATSChance(ListReader1290* target);
};
struct ChanceTarget1290
{
    int m00, m04, m08, m0c, m10, m14, m18, m1c;
    int limb;
    float weight;
};
struct TargetMode1290
{
    int unk00;
    unsigned int mode;
};
struct Effect1290
{
    ElemX* GetValueByIndex(int limb);
};
float __cdecl FUN_009a64d0(ActorX*, ActorX*, int);
float __cdecl GetActorReach(ActorX*, WeaponX*);
float __cdecl GetHitChance(ActorValueOwnerX*, ActorX*, WeaponX*, float, float, float, int, int, float, float, float,
                           int);
bool __cdecl FUN_006d5490(FUN_006dcd70*, FUN_006dcd70*, int, float*, int);
void __cdecl SetContextInfo(TempSound1290*, TemporaryCommand1290*);
void __cdecl FUN_005e58f0(int, ActorX*, WeaponX*, ActorX*, float*);
void __cdecl FUN_005e58f0(int, ActorX*, float*);

// Computes the VATS hit chance for the current target, updates the active command and stores the chance on the target.
// @fnv 0x007f1290
float VATSMenu1290::CalculateVATSChance(ListReader1290* targetNode)
{
    float kResult = 0.0f;  // Accumulated hit chance.
    if (targetNode == 0)
        return kResult;
    ChanceX* target = *targetNode->FUN_006815c0();
    ListX<TargetX*>* kList = FindListEntryForTarget(xDAT_011f21cc);
    TargetX* targetX = *reinterpret_cast<TargetX**>(reinterpret_cast<ListReader1290*>(kList)->FUN_006815c0());
    FormX* entryB = xDAT_011dea3c->FUN_008d8520()->GetEquippedWeapon();
    WeaponX* otherA = entryB ? entryB->FUN_0044ddc0() : 0;
    FormX* targetA = xDAT_011f21cc->IsActor() ? xDAT_011f21cc->FUN_008d8520()->GetEquippedWeapon() : 0;
    float kScale = targetA ? ((Form1290*)targetA)->FUN_004bcdb0(1) / DAT_01017a40 : 1.0;
    WeaponX* weaponA = targetA ? targetA->FUN_0044ddc0() : 0;
    Effect1290* specialReference = 0;
    ElemX* entry = 0;
    if (xDAT_011f21cc->IsActor())
    {
        specialReference = (Effect1290*)((Actor1290*)xDAT_011f21cc)->FUN_004181e0()->GetRace();
        entry = specialReference->GetValueByIndex(target->m_iActionValue);
    }
    float boundX = 0.0f;  // Effective range.
    if (otherA && !xDAT_011f21cc)
    {
        boundX = ((Weapon1290*)otherA)->FUN_0050ebf0() * 2.0f;
    }
    else
    {
        boundX = ((Actor1290*)xDAT_011f21cc)->FUN_00571600() * 2.0f;
    }
    if (boundX < DAT_01012070)
        boundX = DAT_0101e704;
    kResult = GetHitChance(
        xDAT_011dea3c ? &xDAT_011dea3c->kAVOwner : 0, xDAT_011f21cc, otherA, kScale,
        GetActorReach(xDAT_011dea3c, otherA), otherA ? ((Actor1290*)xDAT_011dea3c)->GetCachedSpeed(3) : 1.0f,
        ((TargetMode1290*)targetX)->mode != 2 ? (int)entry : 0,
        ((TargetMode1290*)targetX)->mode != 2 ? (int)weaponA : 0, ((ChanceTarget1290*)target)->weight,
        FUN_009a64d0(xDAT_011dea3c, xDAT_011f21cc, 0), boundX, 0);
    bool invalidX = false;
    if (!otherA || ((Weapon1290*)otherA)->FUN_006450c0())
    {
        FUN_006dcd70 pointB(xDAT_011dea3c);
        FUN_006dcd70 origin(xDAT_011f21cc);
        float minimum = DAT_01016970;
        if (!FUN_006d5490(&pointB, &origin, 0, &minimum, 0))
            minimum = DAT_01016970;
        float valueX = ((Point1290*)((C7F0500Ref*)xDAT_011dea3c)->GetPos())
                           ->FUN_00439ef0(*(Point1290*)((C7F0500Ref*)xDAT_011f21cc)->GetPos())
                           .FUN_00457990();
        if (valueX * DAT_01011590 < minimum)
            invalidX = true;
    }
    float maximumA = invalidX ? 0.0f : kResult;
    float effectsB = 0.0f;
    hasCalculated = true;
    activeCommand.FUN_009ca500();
    activeCommand.limb = entry ? entry->GetByte63() : -1;
    activeCommand.target = xDAT_011f21cc;
    activeCommand.active = true;
    activeCommand.sound->FUN_00407e00(0x800, true);
    SetContextInfo(activeCommand.sound, &activeCommand);
    FUN_005e58f0(8, xDAT_011dea3c, otherA ? otherA : DAT_011ca278, xDAT_011f21cc, &maximumA);
    FUN_005e58f0(0x21, xDAT_011dea3c, &effectsB);
    m_bStateFlag4 = (effectsB != DAT_01012060) ? true : false;
    if (maximumA > kResult)
        kResult = maximumA;
    if (target->fHitChance == DAT_01012060 && kResult > DAT_01012060)
        target->fHitChance = kResult;
    return kResult;
}
}  // namespace fnv_007f1290

namespace fnv_007f3d60 {
struct Actor
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
    virtual bool v64();
};
struct FUN_007f3d60_cls : StandIn
{
    unsigned int FUN_007f3bf0(int a);
    BSSimpleList* FindListEntryByValue(int a1);
};
// @fnv 0x007f3d60
BSSimpleList* FUN_007f3d60_cls::FindListEntryByValue(int aiValue)
{
    if (!((Actor*)DAT_011f21cc)->v64())
    {
        return 0;
    }
    int head = (int)*this->FindListEntryForTarget(reinterpret_cast<TESObjectREFR*>(DAT_011f21cc))->FUN_006815c0();
    if (head != 0)
    {
        BSSimpleList* cur = (BSSimpleList*)(head + 8);
        while (cur != 0 && !cur->FUN_008256d0())
        {
            if ((int)this->FUN_007f3bf0(*(int*)((int)*cur->FUN_006815c0() + 0x20)) == aiValue)
            {
                return cur;
            }
            cur = cur->FUN_00726070();
        }
    }
    return 0;
}
}  // namespace fnv_007f3d60

struct LimbM;
struct PointM
{
    float x, y, z;
    PointM operator-(const PointM&) const;
    float Length() const;
    bool operator==(const PointM&) const;
};
struct WeaponM
{
    bool FUN_006450c0();
};
struct ItemM
{
    WeaponM* FUN_0044ddc0();
};
struct ProcessM
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
    virtual ItemM* current();
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
    virtual bool special();
};
struct PosM
{
    PointM* FUN_0045bb80();
};
struct ActorM
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
    virtual bool check();
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
    virtual PosM* position();
    ProcessM* FUN_008d8520();
    void UpdateCamera(bool, bool);
    void UpdateCameraMode();
};
struct LimbM
{
    int u00, u04, u08, u0c, u10;
    PointM pos;
    int limb;
    float value24, chance;
    bool active, done, started, failed;
};
struct LimbListM
{
    int item;
    int next;
    LimbM*& FUN_006815c0();
    bool FUN_008256d0();
    LimbListM* FUN_00726070();
};
struct TargetM
{
    ActorM* actor;
    int type;
    LimbListM limbs;
    bool done;
};
struct TargetListM
{
    TargetM*& FUN_006815c0();
    bool FUN_008256d0();
    TargetListM* FUN_00726070();
};
struct StateM
{
    int FUN_0044ddc0();
    void FUN_009c6c30(int, bool);
};
struct TimerM
{
    unsigned int FUN_00825c00();
};
struct EffectM
{
    void FUN_0044ac20(const int*);
    void FUN_00800d50(ActorM*);
    void FUN_00800e50(ActorM*);
    void FUN_00800ac0(ActorM*, int, int);
    void FUN_00800ed0();
    bool GetByteAtOffset();
    void FUN_00800700();
    void FUN_008009d0();
    void FUN_00800a90();
    bool GetRatioByIndex(int, float*);
};
EffectM* FUN_00705910();
void UpdateVatsTargetHighlight(int);
extern ActorM* mTarget;
extern ActorM* mPlayer;
extern StateM mState;
extern TimerM mTimer;
extern TargetListM mTargets;
extern bool mForce;
extern unsigned int mTime;
extern TargetM* mLast;
extern int mLimb;
extern PointM mZero;
struct MenuM
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
    bool heading, meters, lit, closing;
    float damage;
    LimbM* current;
    TargetListM* FindListEntryForTarget(ActorM*);
    void FUN_007f28d0();
    void UpdateHitChanceDisplay();
    LimbListM* FindListEntryByValue(int);
    int FUN_007f3bf0(int);
    void UpdateLimbHighlight();
    void UpdateLimbTiles();
    bool FUN_007f06d0(LimbM*);
    float CalculateVATSChance(LimbListM*);
    bool UpdateVatsTargeting();
};
// Advances the VATS targeting sequence: lights/unlights targets, picks the current limb, evaluates limb hits and finishes the target when all limbs are resolved.
// @fnv 0x007f3e00
bool MenuM::UpdateVatsTargeting()
{
    int disabledVal;
    int aBIsOpen;
    LimbListM* aBFoundB;
    bool aBClose;
    LimbListM* aBBusy1;
    LimbM* limb7;
    float valueB2;
    LimbListM* prior2;
    bool refresh;
    LimbListM* header9;
    int count1;
    LimbListM* scan8;
    float aArrow;
    LimbListM* fill6;
    bool all5;
    LimbListM* iter14;
    bool aActorPos6;
    LimbListM* next4;
    LimbM* torsoVal;
    WeaponM* weaponItemA;
    ItemM* itemExtra8;
    TargetListM* a9;
    TargetM* target22;

    if (!mTarget || closing)
        return false;
    if (mState.FUN_0044ddc0() == 1)
    {
        if (!lit)
        {
            aBIsOpen = 1;
            FUN_00705910()->FUN_0044ac20(&aBIsOpen);
            a9 = &mTargets;
            while (a9 && !a9->FUN_008256d0())
            {
                FUN_00705910()->FUN_00800d50(a9->FUN_006815c0()->actor);
                a9 = a9->FUN_00726070();
            }
            lit = true;
        }
        FUN_00705910()->FUN_00800e50(mTarget);
        return true;
    }
    else if (lit)
    {
        lit = false;
        FUN_00705910()->FUN_00800ac0(0, 0, 0);
        FUN_00705910()->FUN_00800ed0();
        disabledVal = 0;
        FUN_00705910()->FUN_0044ac20(&disabledVal);
        UpdateVatsTargetHighlight(1);
        return false;
    }
    target22 = FindListEntryForTarget(mTarget)->FUN_006815c0();
    if (target22)
    {
        itemExtra8 = mPlayer->FUN_008d8520()->current();
        weaponItemA = itemExtra8 ? itemExtra8->FUN_0044ddc0() : 0;
        if (!target22->done)
        {
            if (!FUN_00705910()->GetByteAtOffset() && !mForce)
            {
                FUN_00705910()->FUN_00800700();
                if (!target22->actor->check())
                {
                    FUN_00705910()->FUN_00800ac0(target22->actor, 1, 1);
                    FUN_00705910()->FUN_008009d0();
                }
            }
            if (true)
            {
                if (mState.FUN_0044ddc0() != 3)
                {
                    mState.FUN_009c6c30(3, false);
                    mTime = mTimer.FUN_00825c00();
                }
                else if (mTimer.FUN_00825c00() - mTime > 2000)
                {
                    scan8 = &target22->limbs;
                    count1 = 0;
                    aArrow = 0;
                    while (scan8 && !scan8->FUN_008256d0())
                    {
                        if (scan8->FUN_006815c0()->done)
                        {
                            ++count1;
                            aArrow += scan8->FUN_006815c0()->chance;
                        }
                        scan8 = scan8->FUN_00726070();
                    }
                    FUN_00705910()->FUN_008009d0();
                    fill6 = &target22->limbs;
                    while (fill6 && !fill6->FUN_008256d0())
                    {
                        if (!fill6->FUN_006815c0()->done)
                        {
                            if (fill6->FUN_006815c0()->chance <= 0.0)
                                fill6->FUN_006815c0()->chance = aArrow / count1;
                            fill6->FUN_006815c0()->done = true;
                            fill6->FUN_006815c0()->started = true;
                            fill6->FUN_006815c0()->failed = false;
                        }
                        fill6 = fill6->FUN_00726070();
                    }
                    mTime = mTimer.FUN_00825c00();
                }
                FUN_007f28d0();
                next4 = &target22->limbs;
                torsoVal = 0;
                while (next4 && !next4->FUN_008256d0())
                {
                    if (next4->FUN_006815c0()->limb == 0)
                        torsoVal = next4->FUN_006815c0();
                    next4 = next4->FUN_00726070();
                }
                next4 = &target22->limbs;
                while (next4 && !next4->FUN_008256d0())
                {
                    if (!next4->FUN_006815c0()->done && !next4->FUN_006815c0()->started &&
                        (!heading || next4->FUN_006815c0()->active))
                        break;
                    next4 = next4->FUN_00726070();
                }

                {
                    all5 = true;
                    iter14 = &target22->limbs;
                    while (iter14 && !iter14->FUN_008256d0())
                    {
                        if (!iter14->FUN_006815c0()->done && iter14->FUN_006815c0()->active)
                        {
                            all5 = false;
                            break;
                        }
                        iter14 = iter14->FUN_00726070();
                    }
                    if (all5 && (!next4 || next4->FUN_008256d0()))
                    {
                        UpdateHitChanceDisplay();
                        FUN_00705910()->FUN_00800a90();
                        header9 = FindListEntryByValue(25);
                        if (header9 &&
                            (header9->FUN_006815c0()->pos - *mPlayer->position()->FUN_0045bb80()).Length() < 300.0 &&
                            target22 != mLast)
                            current = header9->FUN_006815c0();
                        else if (target22 == mLast)
                        {
                            prior2 = FindListEntryByValue(mLimb);
                            current = prior2 ? prior2->FUN_006815c0() : target22->limbs.FUN_006815c0();
                        }
                        else if (torsoVal)
                        {
                            mLimb = 26;
                            current = torsoVal;
                        }
                        else
                            mLimb = FUN_007f3bf0(current->limb);
                        mLast = target22;
                        target22->done = true;
                        mForce = false;
                        mState.FUN_009c6c30(2, false);
                        FUN_00705910()->FUN_008009d0();
                        refresh = false;
                        if (target22->type == 2 || mPlayer->FUN_008d8520()->special() || !weaponItemA ||
                            weaponItemA->FUN_006450c0())
                            refresh = true;
                        if (refresh)
                            UpdateVatsTargetHighlight(1);
                        UpdateLimbHighlight();
                        return true;
                    }
                }
                if (next4 && next4->FUN_006815c0())
                {
                    current = next4->FUN_006815c0();
                    if (!next4->FUN_006815c0()->started)
                    {
                        UpdateVatsTargetHighlight(1);
                        next4->FUN_006815c0()->started = true;
                    }
                }
                aActorPos6 = true;
                iter14 = &target22->limbs;
                while (iter14 && !iter14->FUN_008256d0())
                {
                    limb7 = iter14->FUN_006815c0();
                    valueB2 = 0;
                    if (limb7->started && FUN_00705910()->GetRatioByIndex(limb7->limb, &valueB2))
                    {
                        limb7->value24 = valueB2;
                        if (limb7->pos == mZero)
                            UpdateLimbTiles();
                        if (!FUN_007f06d0(limb7))
                        {
                            limb7->failed = true;
                            limb7->started = false;
                        }
                        else
                            limb7->done = true;
                        if (!limb7->done && limb7->active)
                            aActorPos6 = false;
                        CalculateVATSChance(iter14);
                        if (aActorPos6 && !iter14->FUN_00726070())
                        {
                            UpdateHitChanceDisplay();
                            FUN_00705910()->FUN_00800a90();
                            aBBusy1 = FindListEntryByValue(25);
                            if (aBBusy1 &&
                                (aBBusy1->FUN_006815c0()->pos - *mPlayer->position()->FUN_0045bb80()).Length() <
                                    300.0 &&
                                target22 != mLast)
                                current = aBBusy1->FUN_006815c0();
                            else if (target22 == mLast)
                            {
                                aBFoundB = FindListEntryByValue(mLimb);
                                current = aBFoundB ? aBFoundB->FUN_006815c0() : target22->limbs.FUN_006815c0();
                            }
                            else if (torsoVal)
                            {
                                mLimb = 26;
                                current = torsoVal;
                            }
                            else
                                mLimb = FUN_007f3bf0(current->limb);
                            mLast = target22;
                            mState.FUN_009c6c30(2, false);
                            FUN_00705910()->FUN_008009d0();
                            UpdateLimbHighlight();
                            aBClose = false;
                            if (target22->type == 2 || mPlayer->FUN_008d8520()->special() || !weaponItemA ||
                                weaponItemA->FUN_006450c0())
                                aBClose = true;
                            if (aBClose)
                                UpdateVatsTargetHighlight(1);
                            target22->done = true;
                            mForce = false;
                            return true;
                        }
                    }
                    iter14 = iter14->FUN_00726070();
                }
                mPlayer->UpdateCamera(false, false);
                mPlayer->UpdateCameraMode();
                return true;
            }
        }
        else if (mState.FUN_0044ddc0() == 3)
            mState.FUN_009c6c30(2, false);
    }
    else
        return false;
    return true;
}

struct VATS_COMMAND_LIST
{
    int eAction;
    bool bFlag4, bFlag5, bFlag6, bFlag7;
    unsigned char ucShots, ucExtra;
    unsigned short flags;
    ActorX* pTarget;
    int m_iActionValue;
    int unk14, unk18, unk1c;
    float fAPCost;
    int unk24;
    VATS_COMMAND_LIST();
    ~VATS_COMMAND_LIST();
};
struct AttackQueueNode
{
    CommandX** FUN_006815c0();
    bool FUN_008256d0();
    AttackQueueNode* FUN_00726070();
};
struct DamageActor : ActorX
{
    float FUN_008808a0(float damage, ActorX* attacker);
};
struct HealthValueOwner
{
    virtual int GetValue(int av);
    virtual void v004();
    virtual int GetCurrentValue(int av);
};
struct WeaponTypeCall
{
    int FUN_00446390();
};
float FUN_009b4fe0(CommandX* command);

// @fnv 0x007f48e0
float VATSMenuX::FUN_007f48e0()
{
    if (!xDAT_011f21cc || !xDAT_011f21cc->IsActor())
        return 0.0f;
    float current = 0.0f;
    AttackQueueNode* nodeA = (AttackQueueNode*)xDAT_011f2250._ref_006815c0();
    while (nodeA && !nodeA->FUN_008256d0())
    {
        if ((*nodeA->FUN_006815c0())->pTarget == xDAT_011f21cc)
        {
            float queuedDamage = FUN_009b4fe0(*nodeA->FUN_006815c0());
            current -= ((DamageActor*)xDAT_011f21cc)->FUN_008808a0(-queuedDamage, xDAT_011dea3c);
        }
        nodeA = nodeA->FUN_00726070();
    }
    FormX* objectTmp = xDAT_011dea3c->FUN_008d8520()->GetEquippedWeapon();
    WeaponX* weapon4 = objectTmp ? objectTmp->FUN_0044ddc0() : 0;
    int key = weapon4 ? ((WeaponTypeCall*)weapon4)->FUN_00446390() : 0;
    int entryVal = xFUN_0066dba0(key);
    VATS_COMMAND_LIST kItem;
    kItem.eAction = entryVal;
    kItem.bFlag4 = true;
    kItem.pTarget = xDAT_011f21cc;
    kItem.m_iActionValue = FUN_007f3bf0(m_pTargetChance->m_iActionValue);
    kItem.ucShots = xFUN_007f5050(entryVal, 0);
    float valueTmp = FUN_009b4fe0((CommandX*)&kItem);
    current -= ((DamageActor*)xDAT_011f21cc)->FUN_008808a0(-valueTmp, xDAT_011dea3c);
    if (!((HealthValueOwner*)&xDAT_011f21cc->kAVOwner)->GetCurrentValue(16))
        return 0.0f;
    if (current > ((HealthValueOwner*)&xDAT_011f21cc->kAVOwner)->GetCurrentValue(16))
    {
        return (float)((HealthValueOwner*)&xDAT_011f21cc->kAVOwner)->GetCurrentValue(16);
    }
    else
    {
        return current / ((HealthValueOwner*)&xDAT_011f21cc->kAVOwner)->GetValue(16);
    }
}

class NiPoint2
{
  public:
    NiPoint2();
    float x;
    float y;
};

class NiPoint3_ext
{
  public:
    NiPoint3_ext();
    float x;
    float y;
    float z;
};

class FUN_007f6820_cls
{
  public:
    NiPoint2 kPoint;
    NiPoint3_ext kPointCur;
    NiPoint3_ext kPointValue;
    int iUnk;
    float fUnk;
    float fUnkCur;
    bool bUnk2C;
    bool bUnk2D;
    bool bUnk2E;
    bool bUnk2F;
    int iUnkCur;
    float fUnkValue;
    bool bUnk;

    FUN_007f6820_cls();
};

// @fnv 0x007f6820
FUN_007f6820_cls::FUN_007f6820_cls()
{
    iUnk = -1;
    fUnk = 0.0f;
    fUnkCur = 0.0f;
    bUnk2C = false;
    bUnk2D = false;
    bUnk2E = true;
    bUnk2F = true;
    iUnkCur = 0;
    fUnkValue = 0.0f;
    bUnk = false;
}

struct ListItemTile;
struct ListItemValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int operation, ListItemTile* tile, int trait);
    void AppendFloatAction(int operation, float value);
    void Refresh(int mode);
};
struct ListItemMenu
{
    ListItemTile* AddTileFromTemplate(ListItemTile* parent, const char* name, int flags);
};
struct ListItemTile
{
    ListItemMenu* GetMenu();
    void* FUN_00a00f30(int trait);
    void SetInt(int trait, int value);
    void SetString(int trait, const char* value, bool propagate);
    float FUN_00a011b0(int trait);
    ListItemValue* FindTraitValue(int trait);
};
struct ListItemData
{
    ListItemTile* tile;
    void* object;
    int index;
    ListItemData(ListItemTile* tile, void** object);
};
typedef int(__cdecl* ListItemCompare)(ListItemData*, ListItemData*);
struct ListItemEntries
{
    ListItemData* item;
    ListItemEntries* next;
    void FUN_007a7eb0(ListItemData* item, ListItemCompare compare);
    void FUN_00905820(ListItemData* const& item);
};
extern const char _kListBoxNumFiltered[];
struct ListBoxInsert
{
    void* vtable;
    ListItemEntries entries;
    ListItemTile* parent;
    int selected;
    int flags;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int flag);
    void FUN_00726090();
    void AccumulateTileHeight(ListItemTile* tile);
    void FUN_00726530();
    int GetRaceCount();
    ListItemTile* AddItemTile(void* object, const char* text, ListItemCompare compare, const char* name);
};
// @fnv 0x007f6fe0
ListItemTile* ListBoxInsert::AddItemTile(void* object, const char* text, ListItemCompare compare, const char* name)
{
    if (parent && (templateName || name))
    {
        ListItemTile* tile = parent->GetMenu()->AddTileFromTemplate(parent, name ? name : templateName, 0);
        ListItemValue* value7;
        if (!tile->FUN_00a00f30(4010))
            tile->SetInt(4010, -1);
        if (text)
            tile->SetString(4036, text, true);
        if (compare)
        {
            entries.FUN_007a7eb0(new ListItemData(tile, &object), compare);
            if (FUN_007242c0(0))
                FUN_00726090();
        }
        else
        {
            entries.FUN_00905820(new ListItemData(tile, &object));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(tile);
                FUN_00726530();
            }
            tile->SetInt(4012, itemCount++);
        }
        if (GetRaceCount() == 1 && parent->FUN_00a011b0(xFUN_00a00940(_kListBoxNumFiltered, -1)) > 0.0)
        {
            value7 = parent->FindTraitValue(4016);
            value7->RemoveFromReactions();
            value7->FUN_00a09130(2000, tile, 4016);
            value7->AppendFloatAction(2003, parent->FUN_00a011b0(xFUN_00a00940(_kListBoxNumFiltered, -1)));
            value7->Refresh(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}

struct B9C88A0Item
{
    ~B9C88A0Item();

    int m_iValue;
    char unk04;
    bool m_bFlag;
};

class B9C88A0List
{
  public:
    bool IsEmpty();
    B9C88A0List* GetNext();
    B9C88A0Item** GetItem();
    void Remove(B9C88A0Item** ppkItem);

    void PopLastItem(int* piValue, bool* pbFlag);
};

// Walks the list to the last node and, if it holds an item, copies its value and flag out, deletes the item and removes it.
// @fnv 0x009c88a0
void B9C88A0List::PopLastItem(int* piOutValue, bool* pbOutFlag)
{
    B9C88A0List* pkNode = this;
    while (pkNode && !pkNode->IsEmpty())
    {
        if (!pkNode->GetNext())
        {
            B9C88A0Item* pkItem = *pkNode->GetItem();
            *piOutValue = pkItem->m_iValue;
            *pbOutFlag = pkItem->m_bFlag;
            delete pkItem;
            Remove(&pkItem);
            return;
        }
        pkNode = pkNode->GetNext();
    }
}

struct Vec392
{
    float x, y;
    Vec392();
    bool FUN_00452df0(const Vec392&) const;
    Vec392 operator-(const Vec392&) const;
    Vec392 operator+(const Vec392&) const;
    Vec392 operator*(float) const;
    float NormalizeXY() const;
    float FUN_00589850() const;
    Vec392 DivideBy(float) const;
};
struct Point392
{
    float x, y, z;
    Point392();
};
struct Matrix392
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Matrix392();
    Point392 operator*(const Point392&) const;
};
struct Tile392
{
    float FUN_00a011b0(int);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
    void RemoveFadeItemsForTile(int);
    void StartFade(int, float, float, float, int);
};
struct Scene392
{
    Point392* FUN_0045bb80();
};
struct Part392
{
    const char* FUN_006838b0();
    const char* FUN_0043b230();
};
struct Race392
{
    Part392* GetValueByIndex(int);
};
struct Actor392;
struct Process392
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
    virtual FormX* GetEquippedWeapon();
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
    virtual Scene392* GetLimb(void*);
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual bool HasMeleeWeapon();
};
struct Actor392
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
    virtual bool IsActor();
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
    virtual Scene392* GetRoot();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void* GetLimbData();
    Process392* FUN_008d8520();
    const char* FUN_0055d520();
    float FUN_00568ad0();
};
struct Name392
{
    const char* FUN_00408da0();
};
struct Weapon392
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Name392 name;
    bool FUN_006450c0();
};
struct Form392
{
    Weapon392* FUN_0044ddc0();
    float FUN_004bcdb0(int);
};
struct Limb392
{
    float x, y;
    Point392 projected;
    Point392 world;
    int limb;
    int unk24;
    float chance;
    bool visible, crippled, selected;
    Tile392* tile;
};
struct Target392
{
    Actor392* actor;
    int kind;
    ListX<Limb392*> limbs;
};
struct Menu392 : VATSMenuX
{
    bool flag118;
};
struct Base392
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
    virtual Race392* GetRace();
};
struct Ref392
{
    Base392* FUN_004181e0();
};
struct ProjectionResult392
{
    ProjectionResult392* FUN_006629f0();
    void ProjectToScreen();
};
ProjectionResult392* __stdcall FUN_0045c670(Point392*, float*, float*, float);
Scene392* FUN_004aae30(Scene392*, const char*);
unsigned int FUN_004873d0(Weapon392*);
float FUN_00408840(float);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
int MinInt(int, int);
int FUN_00647b70(int, int);
// Projects each target limb to screen space, updates its tile labels and meters, hides off-screen limbs, and separates overlapping limb tiles.
// @fnv 0x007f1840
void VATSMenuX::UpdateLimbTiles()
{
    ListX<TargetX*>* node_2 = FindListEntryForTarget(xDAT_011f21cc);
    Target392* target = reinterpret_cast<Target392*>(node_2->GetItem());
    ListX<Limb392*>* entry = &target->limbs;
    float scaleB = 0.0f;
    Scene392* object4 = 0;
    Point392 positionVal;
    int x_2 = 0;
    int y6 = 0;
    static int centerX = (int)(xFUN_00715d40() / 2.0);
    static int centerY = (int)(xFUN_00715da0() / 2.0);
    static int minX = (int)(xFUN_007177c0() * 2.0 + 100.0);
    static int minY = (int)(xFUN_00717820() * 2.0 + 100.0);
    static int maxX = (int)(xFUN_00715d40() - minX - 50.0);
    static int maxY = (int)(xFUN_00715da0() - 2.0 * xFUN_00717820() -
                            reinterpret_cast<Tile392*>(xDAT_011db0d4->m_pTiles[17])->FUN_00a011b0(0xfb0) + 50.0);
    Form392* formTmp =
        reinterpret_cast<Form392*>(reinterpret_cast<Actor392*>(xDAT_011dea3c)->FUN_008d8520()->GetEquippedWeapon());
    Weapon392* weapon7 = formTmp ? formTmp->FUN_0044ddc0() : 0;
    entry = &target->limbs;
    while (entry && !entry->IsEmpty())
    {
        Race392* form2 = 0;
        Part392* parts3 = 0;
        Limb392* item2 = entry->GetItem();
        if (target->kind == 2)
            object4 = target->actor->GetRoot();
        else if (item2->limb == 14)
        {
            Scene392* head = 0;
            if (reinterpret_cast<Actor392*>(xDAT_011f21cc)->IsActor())
                head = reinterpret_cast<Actor392*>(xDAT_011f21cc)
                           ->FUN_008d8520()
                           ->GetLimb(reinterpret_cast<Actor392*>(xDAT_011f21cc)->GetLimbData());
            object4 = head;
        }
        else
        {
            form2 = reinterpret_cast<Ref392*>(xDAT_011f21cc)->FUN_004181e0()->GetRace();
            parts3 = form2->GetValueByIndex(item2->limb);
            if (parts3)
                object4 = FUN_004aae30(reinterpret_cast<Actor392*>(xDAT_011f21cc)->GetRoot(), parts3->FUN_0043b230());
        }
        if (object4)
        {
            positionVal = *object4->FUN_0045bb80();
            item2->world = positionVal;
            FUN_0045c670(&positionVal, &item2->x, &item2->y, 0.00001f)->FUN_006629f0()->ProjectToScreen();
        }
        item2->x *= xFUN_00715d40();
        item2->y = (1.0 - item2->y) * xFUN_00715da0();
        Matrix392 matrix;
        reinterpret_cast<FUN_007f51b0_shell*>(this)->FUN_007f51b0(reinterpret_cast<FUN_005df510_shell*>(&matrix));
        item2->projected = matrix * item2->world;
        Form392* ba = reinterpret_cast<Actor392*>(xDAT_011f21cc)->IsActor()
                          ? reinterpret_cast<Form392*>(
                                reinterpret_cast<Actor392*>(xDAT_011f21cc)->FUN_008d8520()->GetEquippedWeapon())
                          : 0;
        float l = ba ? ba->FUN_004bcdb0(1) / 100.0 : 1.0;
        Weapon392* weaponVal = ba ? ba->FUN_0044ddc0() : 0;
        reinterpret_cast<Menu392*>(this)->flag118 = false;
        if (target->kind == 2 || reinterpret_cast<Actor392*>(xDAT_011dea3c)->FUN_008d8520()->HasMeleeWeapon() ||
            !weapon7 || weapon7->FUN_006450c0())
        {
            item2->tile->FUN_00a01350(xFUN_00a00940("_LimbName", -1), target->actor->FUN_0055d520(), true);
            item2->tile->FUN_00a012d0(
                xFUN_00a00940("_MeterPercent", -1),
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, (float)(target->actor->FUN_00568ad0() / 100.0))), true);
        }
        else if (parts3)
        {
            item2->tile->FUN_00a01350(xFUN_00a00940("_LimbName", -1), parts3->FUN_006838b0(), true);
            item2->tile->FUN_00a012d0(
                xFUN_00a00940("_MeterPercent", -1),
                FUN_0040ebd0(
                    1.0f, FUN_00404010(
                              0.0f, (float)(xDAT_011f21cc->kAVOwner.GetActorValue(FUN_007f3bf0(item2->limb)) / 100.0))),
                true);
        }
        else if (weaponVal)
        {
            item2->tile->FUN_00a01350(xFUN_00a00940("_LimbName", -1), weaponVal->name.FUN_00408da0(), true);
            item2->tile->FUN_00a012d0(
                xFUN_00a00940("_MeterPercent", -1),
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, ba->FUN_004bcdb0(0) / (FUN_004873d0(ba->FUN_0044ddc0())
                                                                                 ? FUN_004873d0(ba->FUN_0044ddc0())
                                                                                 : 1))),
                true);
        }
        if (item2->x < 0.0 || item2->x > xFUN_00715d40() || item2->y < 0.0 || item2->y > xFUN_00715da0())
        {
            item2->visible = false;
            item2->crippled = false;
            item2->selected = false;
            item2->tile->RemoveFadeItemsForTile(0xfa9);
            item2->tile->StartFade(0xfa9, item2->tile->FUN_00a011b0(0xfa9), 0.0f, 0.5f, 0);
        }
        else
            item2->visible = true;
        entry = entry->GetNext();
    }
    entry = &reinterpret_cast<Target392*>(node_2->GetItem())->limbs;
    while (entry && !entry->IsEmpty())
    {
        Limb392* item2 = entry->GetItem();
        if (item2->visible)
        {
            switch (item2->limb)
            {
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 14:
                x_2 = (int)(item2->x + (item2->x > centerX ? 100 : -100));
                y6 = (int)(item2->y + (item2->y > centerY ? 50 : -50));
                break;
            case 1:
            case 2:
                x_2 = (int)item2->x;
                y6 = (int)(item2->y + (item2->y > centerY ? 100 : -100));
                break;
            default:
                x_2 = (int)item2->x;
                y6 = (int)item2->y;
                break;
            }
            x_2 = FUN_00647b70(minX, MinInt(maxX, x_2));
            y6 = FUN_00647b70(minY, MinInt(maxY, y6));
            item2->tile->FUN_00700320(0xfa1, x_2);
            item2->tile->FUN_00700320(0xfa2, y6);
            switch (item2->limb)
            {
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 14:
                if (x_2 < centerX)
                    item2->tile->FUN_00700320(0xfb7, 4);
                else
                    item2->tile->FUN_00700320(0xfb7, 1);
                break;
            }
        }
        entry = entry->GetNext();
    }
    bool stateA = true;
    int j = 0;
    Vec392 v;
    Vec392 secondVal;
    Vec392 point;
    Vec392 size_2;
    size_2.x = 150.0f;
    size_2.y = 100.0f;
    while (stateA)
    {
        stateA = false;
        j++;
        entry = &reinterpret_cast<Target392*>(node_2->GetItem())->limbs;
        while (entry && !entry->IsEmpty())
        {
            Limb392* a = entry->GetItem();
            ListX<Limb392*>* next = entry->GetNext();
            while (next && !next->IsEmpty())
            {
                Limb392* b = next->GetItem();
                v.x = a->tile->FUN_00a011b0(0xfa1);
                v.y = a->tile->FUN_00a011b0(0xfa2);
                secondVal.x = b->tile->FUN_00a011b0(0xfa1);
                secondVal.y = b->tile->FUN_00a011b0(0xfa2);
                if (FUN_00408840(v.x - secondVal.x) < size_2.x && FUN_00408840(v.y - secondVal.y) < size_2.y)
                {
                    if (v.FUN_00452df0(secondVal))
                        secondVal.x += 1.0;
                    point.x = FUN_00408840(v.x - secondVal.x) / 2.0 + (v.x > secondVal.x ? secondVal.x : v.x);
                    point.y = FUN_00408840(v.y - secondVal.y) / 2.0 + (v.y > secondVal.y ? secondVal.y : v.y);
                    v = (v - point).DivideBy((v - point).NormalizeXY());
                    v = point + v * (float)(size_2.FUN_00589850() / 2.0);
                    secondVal = (secondVal - point).DivideBy((secondVal - point).NormalizeXY());
                    secondVal = point + secondVal * (float)(size_2.FUN_00589850() / 2.0);
                    v.x = FUN_00404010(minX, FUN_0040ebd0(maxX, v.x));
                    v.y = FUN_00404010(minY, FUN_0040ebd0(maxY, v.y));
                    secondVal.x = FUN_00404010(minX, FUN_0040ebd0(maxX, secondVal.x));
                    secondVal.y = FUN_00404010(minY, FUN_0040ebd0(maxY, secondVal.y));
                    a->tile->FUN_00a012d0(0xfa1, v.x, true);
                    a->tile->FUN_00a012d0(0xfa2, v.y, true);
                    b->tile->FUN_00a012d0(0xfa1, secondVal.x, true);
                    b->tile->FUN_00a012d0(0xfa2, secondVal.y, true);
                    stateA = true;
                }
                next = next->GetNext();
            }
            entry = entry->GetNext();
        }
        if (j > 30)
            stateA = false;
    }
}

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx& arHandle);
    bool Play(bool abUnk);
};

struct BSAudio
{
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

struct PlayerCharacter : public Actor
{
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
    virtual float GetAngleZ(int a1);
    ProcessX* GetCurrentAIProcess();
};

void __cdecl FUN_007eb920(unsigned int);
float __cdecl GetAngleBetweenPoints(const P3&, const P3&);

struct TargetSelectHelper
{
    void SelectTarget(bool a1);
};

// Plays the UIVATSSelectTarget sound, then scans the target list for the nearest actor in the given direction and updates the VATS menu selection.
// @fnv 0x007f4c50
void TargetSelectHelper::SelectTarget(bool abReverse)
{
    BSSoundHandleEx soundHandle2;
    soundHandle2 = BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIVATSSelectTarget", 0x121);
    soundHandle2.Play(false);

    BSSimpleList* iter = reinterpret_cast<BSSimpleList*>(&g_011db150);
    float playerAngleDeg3 = reinterpret_cast<PlayerCharacter*>(_g_thePlayer)->GetAngleZ(0) * 57.2957763671875;
    P3 playerPos7 = *reinterpret_cast<PlayerCharacter*>(_g_thePlayer)->FUN_007f4f30_position();
    float bestAngle2 = (float)(abReverse ? -360 : 360);

    FormX* pEquippedA = reinterpret_cast<PlayerCharacter*>(_g_thePlayer)->GetCurrentAIProcess()->GetEquippedWeapon();
    unsigned int flags = (pEquippedA != 0) ? reinterpret_cast<unsigned int>(pEquippedA->FUN_0044ddc0()) : 0;

    while (iter && !iter->FUN_008256d0())
    {
        float targetAngle2 = GetAngleBetweenPoints(
            playerPos7, *(*reinterpret_cast<Actor**>(*iter->FUN_006815c0()))->FUN_007f4f30_position());
        float diff2 = playerAngleDeg3 - targetAngle2;
        diff2 = (diff2 > 180.0 ? diff2 - 360.0 : diff2);

        if ((diff2 < bestAngle2 && diff2 > 0.0 && !abReverse) || (diff2 > bestAngle2 && diff2 < 0.0 && abReverse))
        {
            bestAngle2 = diff2;
            DAT_011f21cc = *reinterpret_cast<Actor**>(*iter->FUN_006815c0());
            FUN_007eb920(flags);

            BSSimpleList* itemIter2 = reinterpret_cast<BSSimpleList*>(&(*iter->FUN_006815c0())->items);
            reinterpret_cast<VATSMenu*>(DAT_011db0d4)->m_pTargetChance = *itemIter2->FUN_006815c0();

            while (itemIter2 && !itemIter2->FUN_008256d0())
            {
                if (reinterpret_cast<int*>(*iter->FUN_006815c0())[1] == 1 &&
                    reinterpret_cast<int*>(*itemIter2->FUN_006815c0())[8] == 1)
                {
                    reinterpret_cast<VATSMenu*>(DAT_011db0d4)->m_pTargetChance = *itemIter2->FUN_006815c0();
                }
                itemIter2 = itemIter2->FUN_00726070();
            }
        }

        iter = iter->FUN_00726070();
    }
}

extern int UNK_01077eac;
extern int UNK_01077e98;
void* __cdecl FUN_00a09030(unsigned int a1);
void* __cdecl FUN_00a08b20(void* a1, void* a2);
struct GlobalManager
{
    void* __thiscall AddTileFromTemplate(void* a1, void* a2, int a3);
};
struct Tile
{
    void Set(int a1, int a2);
};
struct ActionData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int type;
    int unk24;
    int unk28;
    int unk2c;
    Tile* tile;
};
struct FUN_007f6e50_This
{
    void __thiscall AssignActionTiles(TargetList* apTargets);
};
// For each entry in apTargets, creates a tile via AddTileFromTemplate and sets it to a value chosen by the action's type.
// @fnv 0x007f6e50
void __thiscall FUN_007f6e50_This::AssignActionTiles(TargetList* apTargets)
{
    void* pTileBuffer = FUN_00a08b20(FUN_00a09030(0x420), &UNK_01077eac);
    BSSimpleList* pEntry = (BSSimpleList*)((char*)*apTargets->FUN_006815c0() + 8);
    while (pEntry != 0 && !pEntry->FUN_008256d0())
    {
        ((ActionData*)*pEntry->FUN_006815c0())->tile =
            (Tile*)((GlobalManager*)DAT_011db0d4)->AddTileFromTemplate(pTileBuffer, &UNK_01077e98, 0);
        if (((ActionData*)*pEntry->FUN_006815c0())->tile != 0)
        {
            switch (((ActionData*)*pEntry->FUN_006815c0())->type)
            {
            case 0:
                ((ActionData*)*pEntry->FUN_006815c0())->tile->Set(0xfb7, 6);
                break;
            case -1:
            case 1:
            case 2:
            case 13:
                ((ActionData*)*pEntry->FUN_006815c0())->tile->Set(0xfb7, 5);
                break;
            case 3:
            case 4:
            case 7:
            case 8:
            case 9:
            case 14:
                ((ActionData*)*pEntry->FUN_006815c0())->tile->Set(0xfb7, 1);
                break;
            case 5:
            case 6:
            case 10:
            case 11:
            case 12:
                ((ActionData*)*pEntry->FUN_006815c0())->tile->Set(0xfb7, 4);
                break;
            }
        }
        pEntry = pEntry->FUN_00726070();
    }
}

struct VATSMenu_007ef7b0 : VATSMenu
{
    void __thiscall FUN_007ef7b0(int aiID, int aiArg);
};
void* __cdecl FUN_004b7210();
bool __cdecl _FUN_004b71d0();

// @fnv 0x007ef7b0
void __thiscall VATSMenu_007ef7b0::FUN_007ef7b0(int aiID, int aiArg)
{
    FUN_004b7210();
    if (_FUN_004b71d0())
        return;

    switch (aiID)
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 30:
    case 31:
        m_bAdditionalStateFlag = true;
        break;
    }
}

struct ItemQ
{
    int unk00, unk04, unk08, iA, iB;
};
struct NodeQ
{
    bool FUN_008256d0();
    ItemQ** FUN_006815c0();
    NodeQ* FUN_00726070();
};
struct ListQ
{
    NodeQ* FUN_006815c0();
};
struct OwnQ
{
    int GetConsecutiveMatchCount();
};
// Walks a linked list of ItemQ pairs and returns the count of consecutive nodes where iA and iB match the next node.
// @fnv 0x007ef930
int OwnQ::GetConsecutiveMatchCount()
{
    int iCount = 0;
    NodeQ* pNode = ((ListQ*)&DAT_011f2250)->FUN_006815c0();
    while (pNode && !pNode->FUN_008256d0())
    {
        bool bNext_pz = pNode->FUN_00726070() != 0;
        ItemQ* pNext_vvak = bNext_pz ? *pNode->FUN_00726070()->FUN_006815c0() : 0;
        ItemQ* pCur = *pNode->FUN_006815c0();
        if (bNext_pz)
        {
            if (pCur->iA == pNext_vvak->iA && pCur->iB == pNext_vvak->iB)
                iCount++;
            else
                iCount = 0;
        }
        else
            return iCount;
        pNode = pNode->FUN_00726070();
    }
    return iCount;
}

namespace VatsQueueText {

struct Sound
{
    unsigned int unk0, unk4, unk8;
    Sound();
    ~Sound();
    Sound& operator=(const Sound& arOther);
    void Play(int aiFlags);
};

struct SoundSource
{
    Sound FUN_00ad7550(const char* apEditorID, int aiFlags);
    Sound ResolveAudioHandle(const char* apEditorID, int aiFlags);
};
SoundSource* FUN_00453a70();
SoundSource* FUN_00ad9060();

struct VATSTarget
{
    const char* FUN_0055d520();
};

struct VATSAction
{
    int iType;
    char pad04[8];
    VATSTarget* pTarget;
    char pad10[0x10];
    float fAPCost;
};

struct VATSQueue
{
    VATSAction* FUN_009c71f0();
    void PopLastItem(int* apType, bool* apFlag);
    int FUN_0044ddc0();
};
extern VATSQueue DAT_011f2250;

struct Weapon
{
    bool FUN_006450c0();
    int FUN_00446390();
    int GetUnk15C();
    const char* FUN_00522be0();
};

struct WeaponHolder
{
    Weapon* FUN_0044ddc0();
};

struct ObjectName
{
    void* FUN_0043b1b0();
};

struct CombatTarget
{
    ObjectName* FUN_00413f40();
};

struct LimbInfo
{
    void* FUN_005e5130(int aiLimb);
};

struct LimbName
{
    const char* FUN_006838b0();
};

struct Process
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
    virtual WeaponHolder* FUN_vt148();
    virtual void q00();
    virtual void q01();
    virtual void q02();
    virtual void q03();
    virtual void q04();
    virtual void q05();
    virtual void q06();
    virtual void q07();
    virtual void q08();
    virtual void q09();
    virtual void q0a();
    virtual void q0b();
    virtual void q0c();
    virtual void q0d();
    virtual void q0e();
    virtual void q0f();
    virtual void q10();
    virtual CombatTarget* FUN_vt190(int aiPart);
};

struct PartSource
{
    virtual void c00();
    virtual void c01();
    virtual void c02();
    virtual void c03();
    virtual void c04();
    virtual void c05();
    virtual void c06();
    virtual void c07();
    virtual void c08();
    virtual void c09();
    virtual void c0a();
    virtual void c0b();
    virtual void c0c();
    virtual void c0d();
    virtual void c0e();
    virtual void c0f();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c1a();
    virtual void c1b();
    virtual void c1c();
    virtual void c1d();
    virtual void c1e();
    virtual void c1f();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c2a();
    virtual void c2b();
    virtual void c2c();
    virtual void c2d();
    virtual void c2e();
    virtual void c2f();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c3a();
    virtual void c3b();
    virtual void c3c();
    virtual void c3d();
    virtual void c3e();
    virtual void c3f();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c4a();
    virtual void c4b();
    virtual void c4c();
    virtual void c4d();
    virtual void c4e();
    virtual void c4f();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void c56();
    virtual void c57();
    virtual void c58();
    virtual void c59();
    virtual void c5a();
    virtual void c5b();
    virtual void c5c();
    virtual void c5d();
    virtual void c5e();
    virtual void c5f();
    virtual LimbInfo* FUN_vt180();
};

struct VATSActor
{
    virtual void a00();
    virtual void a01();
    virtual void a02();
    virtual void a03();
    virtual void a04();
    virtual void a05();
    virtual void a06();
    virtual void a07();
    virtual void a08();
    virtual void a09();
    virtual void a0a();
    virtual void a0b();
    virtual void a0c();
    virtual void a0d();
    virtual void a0e();
    virtual void a0f();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a1a();
    virtual void a1b();
    virtual void a1c();
    virtual void a1d();
    virtual void a1e();
    virtual void a1f();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a2a();
    virtual void a2b();
    virtual void a2c();
    virtual void a2d();
    virtual void a2e();
    virtual void a2f();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a3a();
    virtual void a3b();
    virtual void a3c();
    virtual void a3d();
    virtual void a3e();
    virtual void a3f();
    virtual bool IsActor();
    virtual void b00();
    virtual void b01();
    virtual void b02();
    virtual void b03();
    virtual void b04();
    virtual void b05();
    virtual void b06();
    virtual void b07();
    virtual void b08();
    virtual void b09();
    virtual void b0a();
    virtual void b0b();
    virtual void b0c();
    virtual void b0d();
    virtual void b0e();
    virtual void b0f();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b1a();
    virtual void b1b();
    virtual void b1c();
    virtual void b1d();
    virtual void b1e();
    virtual void b1f();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b2a();
    virtual void b2b();
    virtual void b2c();
    virtual void b2d();
    virtual void b2e();
    virtual void b2f();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual int FUN_vt1e8();
    Process* FUN_008d8520();
    PartSource* FUN_004181e0();
};
extern VATSActor* DAT_011f21cc;

struct PlayerLink
{
    Process* FUN_008d8520();
};
extern PlayerLink* DAT_011dea3c;

struct QueueTarget
{
    char pad00[4];
    int iKind;
};

struct TargetList
{
    QueueTarget** FUN_006815c0();
};

struct VATSTargets
{
    TargetList* FindListEntryForTarget(VATSActor* apActor);
};
extern VATSTargets* DAT_011db0d4;

struct GameText
{
    const char* FUN_00403df0();
};
extern GameText DAT_011d46c0;
extern GameText DAT_011d2754;
extern GameText DAT_011d46d8;

extern int DAT_011db198;
extern int DAT_011a59f0;

struct Tile
{
    void FUN_00700320(int aiID, int aiValue);
    const char* FUN_00a011f0(int aiID);
    void FUN_00a01350(int aiID, const char* apText, bool abPropagate);
};

struct QueueList
{
    char data[0x30];
    Tile* FUN_007f6fb0();
    bool FUN_007f7280(unsigned int auiIndex, bool abByPosition);
    int GetRaceCount();
    Tile* AddItemTile(int aiIndex, int a2, int a3, int a4);
};

struct LimbSelection
{
    char pad00[0x20];
    int m_iLimbIndex;
};

void FUN_00705780();
bool FUN_009526b0();
const char* __cdecl FUN_0066ddc0(int aiType);
bool __cdecl FUN_0066dde0(int aiType);
int __cdecl FUN_00408b20(const char* apA, const char* apB);
int __cdecl FUN_00406d30(char* apDest, unsigned int auiSize, const char* apSrc);
int __cdecl FUN_00406d50(char* apDest, unsigned int auiSize, const char* apSrc);
const char* __cdecl FUN_007f0360(int aiIndex);

struct VATSMenuQueue
{
    char pad00[0x38];
    Tile* pAPTile;
    char pad3c[8];
    Tile* pQueueTile;
    char pad48[0x68];
    QueueList kQueue;
    float fCurrentAP;
    float fMaxAP;
    char pade8[0x18];
    LimbSelection* pLimbs;
    char pad104[4];
    int iSelected;

    void UpdateLimbTiles();
    int FUN_007f3bf0(int aiLimb);
    void UpdateQueueEntry(VATSAction* apAction, bool abAddEntry, bool abShowDetail);
};

// Adds an entry for apAction or removes the last queued item, updates AP, and refreshes queue tile text.
// @fnv 0x007efa10
void VATSMenuQueue::UpdateQueueEntry(VATSAction* apAction, bool abAddEntry, bool abShowDetail)
{
    if (apAction == 0)
    {
        iSelected = 0;
        float m_fPathingCostCur = DAT_011f2250.FUN_009c71f0() ? DAT_011f2250.FUN_009c71f0()->fAPCost : 0.0f;
        int iType = 0x16;
        bool bFlag = false;
        DAT_011f2250.PopLastItem(&iType, &bFlag);
        UpdateLimbTiles();
        if (iType == 0x16 && DAT_011f2250.FUN_0044ddc0() == 2)
            FUN_00705780();
        if (!FUN_009526b0())
        {
            WeaponHolder* pHolder = DAT_011dea3c->FUN_008d8520()->FUN_vt148();
            Weapon* pWeapon = pHolder ? pHolder->FUN_0044ddc0() : 0;
            fCurrentAP = fCurrentAP + m_fPathingCostCur;
        }
        if (fCurrentAP > fMaxAP)
            fCurrentAP = fMaxAP;
        pQueueTile->FUN_00700320(0xfaf, 1);
        if (iType != 9)
        {
            Tile* pLast = kQueue.FUN_007f6fb0();
            if (pLast && !FUN_00408b20(FUN_0066ddc0(9), pLast->FUN_00a011f0(0xfc4)))
                kQueue.FUN_007f7280(kQueue.GetRaceCount() - 1, false);
        }
        kQueue.FUN_007f7280(kQueue.GetRaceCount() - 1, false);
        Sound kSoundCur;
        kSoundCur = FUN_00453a70()->FUN_00ad7550("UIMenuCancel", 0x121);
        kSoundCur.Play(0);
    }
    else
    {
        SoundSource* pAudio = FUN_00ad9060();
        Sound kMoveSound;
        kMoveSound = pAudio->ResolveAudioHandle("UIVATSMove", 0x121);
        kMoveSound.Play(0);
        TargetList* pTargetsCur = DAT_011db0d4->FindListEntryForTarget(DAT_011f21cc);
        WeaponHolder* pOwnerOut = DAT_011dea3c->FUN_008d8520()->FUN_vt148();
        Weapon* pQueueWeaponTmp = pOwnerOut ? pOwnerOut->FUN_0044ddc0() : 0;
        Tile* pEntry;
        fCurrentAP = fCurrentAP - apAction->fAPCost;
        char acTextBase[260];
        if (FUN_0066dde0(apAction->iType))
        {
            DAT_011db198++;
            if (DAT_011a59f0 != -1 && DAT_011f21cc->IsActor() && pQueueWeaponTmp && !pQueueWeaponTmp->FUN_006450c0() &&
                pQueueWeaponTmp->FUN_00446390() != 10)
            {
                LimbInfo* pLimbInfoTmp = DAT_011f21cc->FUN_004181e0()->FUN_vt180();
                LimbName* pLimb = (LimbName*)pLimbInfoTmp->FUN_005e5130(FUN_007f3bf0(pLimbs->m_iLimbIndex));
                if (pLimb)
                {
                    FUN_00406d30(acTextBase, 260, apAction->pTarget->FUN_0055d520());
                    FUN_00406d50(acTextBase, 260, ": ");
                    if (pLimb->FUN_006838b0())
                        FUN_00406d50(acTextBase, 260, pLimb->FUN_006838b0());
                    else
                        FUN_00406d50(acTextBase, 260, "---");
                }
                else
                {
                    return;
                }
            }
            else if ((*pTargetsCur->FUN_006815c0())->iKind != 2)
            {
                CombatTarget* pTarget = DAT_011f21cc->FUN_008d8520()->FUN_vt190(DAT_011f21cc->FUN_vt1e8());
                if (pTarget && pQueueWeaponTmp && !pQueueWeaponTmp->FUN_006450c0() &&
                    pQueueWeaponTmp->FUN_00446390() != 10)
                {
                    FUN_00406d30(acTextBase, 260, apAction->pTarget->FUN_0055d520());
                    FUN_00406d50(acTextBase, 260, ": ");
                    if (pTarget->FUN_00413f40()->FUN_0043b1b0())
                        FUN_00406d50(acTextBase, 260, FUN_007f0360(2));
                    else
                        FUN_00406d50(acTextBase, 260, "---");
                }
                else
                {
                    FUN_00406d30(acTextBase, 260, apAction->pTarget->FUN_0055d520());
                }
            }
            else
            {
                FUN_00406d30(acTextBase, 260, apAction->pTarget->FUN_0055d520());
            }
            if (abShowDetail)
            {
                if (pQueueWeaponTmp && pQueueWeaponTmp->GetUnk15C() == 0x26)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, pQueueWeaponTmp->FUN_00522be0());
                }
                else if (apAction->iType == 0x11)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, DAT_011d46c0.FUN_00403df0());
                }
                else if (apAction->iType == 0x15)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, DAT_011d2754.FUN_00403df0());
                }
                else if (apAction->iType == 0x14)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, DAT_011d46d8.FUN_00403df0());
                }
            }
            if (abAddEntry)
            {
                char acEntry[260];
                FUN_00406d30(acEntry, 260, acTextBase);
                pEntry = kQueue.AddItemTile(DAT_011db198, 0, 0, 0);
                pEntry->FUN_00a01350(0xfc4, acEntry, true);
                DAT_011db198++;
                FUN_00406d30(acTextBase, 260, FUN_0066ddc0(9));
            }
        }
        else
        {
            DAT_011db198++;
            FUN_00406d30(acTextBase, 260, FUN_0066ddc0(apAction->iType));
        }
        char acLineTmp[260];
        FUN_00406d30(acLineTmp, 260, acTextBase);
        pEntry = kQueue.AddItemTile(DAT_011db198, 0, 0, 0);
        pEntry->FUN_00a01350(0xfc4, acLineTmp, true);
    }
    if (kQueue.GetRaceCount() == 0)
        pAPTile->FUN_00700320(0xfaf, 0);
    else
        pAPTile->FUN_00700320(0xfaf, 1);
}

}

struct AmmoPlayer
{
    int FUN_00969040();
};
struct AmmoEntry
{
    WeaponX* FUN_0044ddc0();
    unsigned char HasEffect(int);
    float FUN_004bcdb0(int);
};
struct AmmoWeapon
{
    float FUN_00709430(int);
};
struct AmmoInventory
{
    int FUN_004c8f30(void*);
};
struct AmmoCommand
{
    int action;
    int unk04;
    unsigned char shots;
};
struct AmmoCommandNode
{
    AmmoCommand** FUN_006815c0();
    bool FUN_008256d0();
    AmmoCommandNode* FUN_00726070();
};
struct AmmoQueue
{
    AmmoCommandNode* FUN_006815c0();
};
AmmoInventory* FUN_004bf220(ActorX*);
void UpdateMeterTile(TileX*, float, int, int, int);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);

unsigned int FUN_004873d0(WeaponX*);

// Updates VATS ammo meter tiles and returns whether a reload is needed based on the equipped weapon and queued commands.
// @fnv 0x007f28d0
bool VATSMenuX::FUN_007f28d0()
{
    FormX* equipped5 = xDAT_011dea3c->FUN_008d8520()->GetEquippedWeapon();
    AmmoListX* ammoList2 = xDAT_011dea3c->FUN_008d8520()->GetAmmoList();
    float clip3 = 0.0f;
    float reserve2 = 0.0f;
    m_fValue3 = 0.0f;
    m_fValue2 = 0.0f;
    bool _reload = false;
    if (equipped5)
    {
        WeaponX* weapon3 = equipped5->FUN_0044ddc0();
        bool infinite5 = weapon3->kMods.FUN_00474a80();
        float maxAmmo4 = (float)reinterpret_cast<AmmoPlayer*>(xDAT_011dea3c)->FUN_00969040();
        bool subtractClip4 = true;
        switch (weapon3->GetWeaponType())
        {
        case 10:
        case 11:
        case 13: {
            clip3 = (float)weapon3->GetAmmoPerShot();
            AmmoInventory* invThrown3 = FUN_004bf220(xDAT_011dea3c);
            int countThrown = invThrown3->FUN_004c8f30(weapon3);
            reserve2 = countThrown - clip3;
            break;
        }
        default:
            if (infinite5)
            {
                reserve2 = 0.0f;
                clip3 = maxAmmo4;
            }
            else
            {
                AmmoInventory* inventory = FUN_004bf220(xDAT_011dea3c);
                int count9 = inventory->FUN_004c8f30(weapon3->GetCurrentAmmo(xDAT_011dea3c));
                if (reinterpret_cast<AmmoWeapon*>(weapon3)->FUN_00709430(
                        reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(6)) > 0.0)
                {
                    reserve2 = (float)weapon3->GetFlaggedValue(reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2));
                    subtractClip4 = false;
                }
                clip3 =
                    (float)(ammoList2
                                ? ammoList2->FUN_00726070()
                                : (count9 > weapon3->GetFlaggedValue(
                                                reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2))
                                       ? weapon3->GetFlaggedValue(reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2))
                                       : count9));
                if (subtractClip4)
                    reserve2 = count9 - clip3;
            }
            break;
        }
        m_fValue2 = clip3;
        m_fValue4 = clip3;
        m_fValue3 = reserve2;
        m_fValue5 = reserve2;
        AmmoCommandNode* node2 = reinterpret_cast<AmmoQueue*>(&xDAT_011f2250)->FUN_006815c0();
        while (node2 && !node2->FUN_008256d0())
        {
            switch ((*node2->FUN_006815c0())->action)
            {
            case 9:
                m_fValue4 = FUN_0040ebd0(
                    m_fValue3,
                    infinite5 ? maxAmmo4
                              : (float)weapon3->GetFlaggedValue(reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2)));
                m_fValue5 -= FUN_0040ebd0(
                    m_fValue3,
                    infinite5 ? maxAmmo4
                              : (float)weapon3->GetFlaggedValue(reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2)));
                break;
            case 3:
            case 4:
            case 5:
            case 6:
                m_fValue4 = FUN_00404010(0.0f, (float)(m_fValue4 - (*node2->FUN_006815c0())->shots));
                if (m_fValue4 == 0.0)
                {
                    m_fValue4 =
                        FUN_0040ebd0(m_fValue5, infinite5 ? maxAmmo4
                                                          : (float)weapon3->GetFlaggedValue(
                                                                reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2)));
                    m_fValue5 -=
                        FUN_0040ebd0(m_fValue3, infinite5 ? maxAmmo4
                                                          : (float)weapon3->GetFlaggedValue(
                                                                reinterpret_cast<AmmoEntry*>(equipped5)->HasEffect(2)));
                    m_fValue5 = FUN_00404010(0.0f, m_fValue5);
                    _reload = true;
                }
                else
                    _reload = false;
                break;
            case 7:
            case 8:
                m_fValue4 = FUN_00404010(0.0f, (float)(m_fValue4 - 1.0));
                break;
            }
            node2 = node2->FUN_00726070();
        }
        if (weapon3->GetCurrentAmmo(xDAT_011dea3c))
        {
            m_pTiles[14]->SetInt(0xfa3, 1);
            m_pTiles[15]->SetInt(0xfc4, 1);
            m_pTiles[16]->SetInt(0xfc4, 1);
            m_pTiles[16]->SetInt(0xfa3, 1);
            UpdateMeterTile(
                m_pTiles[15],
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, (float)(reinterpret_cast<AmmoEntry*>(equipped5)->FUN_004bcdb0(0) /
                                                              (FUN_004873d0(equipped5->FUN_0044ddc0())
                                                                   ? FUN_004873d0(equipped5->FUN_0044ddc0())
                                                                   : 1)))),
                0, 0, 0);
            m_pTiles[13]->SetInt(0xfa3, 1);
        }
        else
        {
            m_pTiles[14]->SetInt(0xfa3, 0);
            m_pTiles[15]->SetInt(0xfa3, 0);
            m_pTiles[16]->SetInt(0xfc4, 0);
            m_pTiles[16]->SetInt(0xfa3, 0);
            m_pTiles[13]->SetInt(0xfa3, 0);
            if (weapon3->GetWeaponType() == 10 || weapon3->GetWeaponType() == 11 || weapon3->GetWeaponType() == 13)
                m_pTiles[13]->SetInt(0xfa3, 1);
        }
    }
    else
    {
        m_pTiles[14]->SetInt(0xfa3, 0);
        m_pTiles[15]->SetInt(0xfa3, 0);
        m_pTiles[16]->SetInt(0xfc4, 0);
        m_pTiles[16]->SetInt(0xfa3, 0);
        m_pTiles[13]->SetInt(0xfa3, 0);
        m_fValue4 = 0.0f;
        m_fValue5 = 0.0f;
    }
    char text[16];
    sprintf_s(text, 16, "%i/%i", (int)m_fValue4, (int)m_fValue5);
    m_pTiles[13]->Set(0xfc4, text, true);
    return _reload;
}

namespace fnv_007f3070 {
struct AimVector
{
    float x, y, z;
    AimVector();
    AimVector(float, float, float);
    AimVector FUN_00439ef0(const AimVector&) const;
    float FUN_00457990();
    void FUN_004a0c10();
    float DotProduct(const AimVector&);
};
struct AimMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    AimVector FUN_004b4500(const AimVector&);
};
struct AimTransform
{
    const AimMatrix& FUN_00461130();
};
struct AimCamera
{
    AimTransform* FUN_006629f0();
};
struct AimTile
{
    void RemoveFadeItemsForTile(int);
    float FUN_00a011b0(int);
    void StartFade(int, float, float, float, int);
    bool IsTraitNonZero(int);
};
struct AimLimb
{
    int unk00, unk04;
    AimVector position;
    int unk14, unk18, unk1c;
    int id;
    int unk24, unk28, unk2c;
    AimTile* tile;
    float angle;
};
struct AimLimbs
{
    AimLimb* data;
    AimLimbs* next;
    bool FUN_008256d0();
    AimLimb** FUN_006815c0();
    AimLimbs* FUN_00726070();
};
struct AimWeapon
{
    bool FUN_006450c0();
};
struct AimEntry
{
    AimWeapon* FUN_0044ddc0();
};
struct AimProcess
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
    virtual AimEntry* GetLoadedForm();
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
    virtual bool IsMelee();
};
struct AimBodyData
{
    int unk00;
    int flags;
};
struct AimBody
{
    AimBodyData* FUN_006a9540();
};
struct AimActor
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
    virtual AimBody* GetBody();
    AimProcess* FUN_008d8520();
    AimActor* FUN_004181e0();
};
struct AimTarget
{
    AimActor* actor;
    int type;
    AimLimbs limbs;
};
struct AimTargets
{
    AimTarget** FUN_006815c0();
};
struct AimInput
{
    int GetAxisState(int, int);
    int FUN_00a24180(int, int);
};
struct AimInputOwner
{
    AimInput* FUN_00877720();
};
struct AimManager
{
    int FUN_0070ec70();
};
struct AimMode
{
    int FUN_0044ddc0();
};
struct AimMenu
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
    AimLimb* current;
    int unk104, unk108;
    bool stickReset;
    AimTargets* FindListEntryForTarget(void*);
    int FUN_007f3bf0(int);
    void FUN_007f3070();
};
extern AimInputOwner* DAT_011dea0c;
extern AimActor* DAT_011dea3c;
extern Actor* DAT_011f21cc;
extern int DAT_011f2250;
extern int DAT_011a59f0;
extern const float DAT_0106b158, DAT_01016970, DAT_0101df44, DAT_01023cd8;
extern const double DAT_0102f248, DAT_010357e8, DAT_01012060;
void* FUN_004b7210();
bool FUN_004b71d0();
BSFaceGenNiNode* FUN_0045c670();
int FUN_00ec7d40(int);
float FUN_004f6e40(float);
void UpdateVatsTargetHighlight(int);
// Updates the current aim limb selection based on aim mode, input stick state, and target body data, cycling through limbs on key input.
// @fnv 0x007f3070
void AimMenu::FUN_007f3070()
{
    AimInput* input5 = DAT_011dea0c->FUN_00877720();
    AimEntry* entry1 = DAT_011dea3c->FUN_008d8520()->GetLoadedForm();
    AimWeapon* weapon1 = entry1 ? entry1->FUN_0044ddc0() : 0;
    AimTargets* target20 = FindListEntryForTarget(DAT_011f21cc);
    if (((AimMode*)&DAT_011f2250)->FUN_0044ddc0() != 3 &&
        (DAT_011dea3c->FUN_008d8520()->IsMelee() || (*target20->FUN_006815c0())->type == 2 || !weapon1 ||
         weapon1->FUN_006450c0()))
    {
        if ((*target20->FUN_006815c0())->type == 2)
            DAT_011a59f0 = -1;
        else
        {
            AimBody* body8 = (*target20->FUN_006815c0())->actor->FUN_004181e0()->GetBody();
            AimBodyData* data15 = body8->FUN_006a9540();
            if (data15->flags)
                DAT_011a59f0 = 25;
            else
                DAT_011a59f0 = -1;
        }
    }
    else if ((FUN_004b7210(), FUN_004b71d0()))
    {
        int horizontal8 = 0, vertical3 = 0;
        horizontal8 = input5->GetAxisState(0, 7);
        vertical3 = input5->GetAxisState(0, 8);
        int maximum26 = 32767;
        if (FUN_00ec7d40(vertical3) < maximum26 / 4 && FUN_00ec7d40(horizontal8) < maximum26 / 4)
            stickReset = true;
        bool left9 = true;
        if (horizontal8 > 0)
            left9 = false;
        AimMatrix rotation18 = ((AimCamera*)FUN_0045c670())->FUN_006629f0()->FUN_00461130();
        AimVector direction19(0.0f, (float)-vertical3, (float)-horizontal8);
        direction19 = rotation18.FUN_004b4500(direction19);
        direction19.FUN_004a0c10();
        if (stickReset &&
            (FUN_00ec7d40(vertical3) > maximum26 * 3 / 4 || FUN_00ec7d40(horizontal8) > maximum26 * 3 / 4))
        {
            float bestAngle50 = DAT_0106b158;
            float bestDistance11 = DAT_01016970;
            int selection8 = DAT_011a59f0;
            AimLimbs* limb9 = &(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs;
            AimLimb* original31 = current;
            bool found2 = false;
            while (limb9 && !limb9->FUN_008256d0())
            {
                AimVector delta14;
                delta14 = original31->position.FUN_00439ef0((*limb9->FUN_006815c0())->position);
                float distance9 = delta14.FUN_00457990();
                delta14.FUN_004a0c10();
                float angle3 = FUN_004f6e40(direction19.DotProduct(delta14));
                angle3 *= DAT_0102f248;
                AimLimbs* duplicate12 = 0;
                AimLimbs* scan5 = &(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs;
                while (scan5 && !scan5->FUN_008256d0())
                {
                    if (FUN_007f3bf0((*scan5->FUN_006815c0())->id) == FUN_007f3bf0((*limb9->FUN_006815c0())->id))
                        duplicate12 = scan5;
                    scan5 = scan5->FUN_00726070();
                }
                (*limb9->FUN_006815c0())->angle = angle3;
                if (angle3 < DAT_010357e8 && distance9 != DAT_01012060 && distance9 < bestDistance11 && duplicate12 &&
                    *duplicate12->FUN_006815c0() == *limb9->FUN_006815c0())
                {
                    found2 = true;
                    bestDistance11 = distance9;
                    bestAngle50 = angle3;
                    selection8 = FUN_007f3bf0((*limb9->FUN_006815c0())->id);
                    stickReset = false;
                    current->tile->RemoveFadeItemsForTile(4009);
                    current->tile->StartFade(4009, current->tile->FUN_00a011b0(4009), DAT_01023cd8, DAT_0101df44, 0);
                    current = *limb9->FUN_006815c0();
                }
                limb9 = limb9->FUN_00726070();
            }
            if (!found2)
            {
                bestAngle50 = DAT_0106b158;
                limb9 = &(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs;
                while (limb9 && !limb9->FUN_008256d0())
                {
                    AimLimbs* duplicateB53 = 0;
                    AimLimbs* scanB15 = &(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs;
                    while (scanB15 && !scanB15->FUN_008256d0())
                    {
                        if (FUN_007f3bf0((*scanB15->FUN_006815c0())->id) == FUN_007f3bf0((*limb9->FUN_006815c0())->id))
                            duplicateB53 = scanB15;
                        scanB15 = scanB15->FUN_00726070();
                    }
                    if ((*limb9->FUN_006815c0())->angle < bestAngle50 && original31 != *limb9->FUN_006815c0() &&
                        duplicateB53 && *duplicateB53->FUN_006815c0() == *limb9->FUN_006815c0())
                    {
                        bestAngle50 = (*limb9->FUN_006815c0())->angle;
                        selection8 = FUN_007f3bf0((*limb9->FUN_006815c0())->id);
                        stickReset = false;
                        current->tile->RemoveFadeItemsForTile(4009);
                        current->tile->StartFade(4009, current->tile->FUN_00a011b0(4009), DAT_01023cd8, DAT_0101df44,
                                                    0);
                        current = *limb9->FUN_006815c0();
                    }
                    limb9 = limb9->FUN_00726070();
                }
            }
            DAT_011a59f0 = selection8;
        }
    }
    else if (input5->FUN_00a24180(17, 1) || ((AimManager*)FUN_004b7210())->FUN_0070ec70() > DAT_01012060)
    {
        while (true)
        {
            AimLimbs* cursor = &(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs;
            while (cursor && !cursor->FUN_008256d0())
            {
                if (cursor->FUN_00726070() && *cursor->FUN_006815c0() == current)
                {
                    current = *cursor->FUN_00726070()->FUN_006815c0();
                    break;
                }
                else if (!cursor->FUN_00726070())
                    current = *(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs.FUN_006815c0();
                cursor = cursor->FUN_00726070();
            }
            DAT_011a59f0 = FUN_007f3bf0(current->id);
            if (current->tile->IsTraitNonZero(4003))
                break;
        }
        UpdateVatsTargetHighlight(0);
    }
    else if (input5->FUN_00a24180(31, 1) || ((AimManager*)FUN_004b7210())->FUN_0070ec70() < DAT_01012060)
    {
        while (true)
        {
            AimLimbs* cursorB = &(*FindListEntryForTarget(DAT_011f21cc)->FUN_006815c0())->limbs;
            while (cursorB && !cursorB->FUN_008256d0())
            {
                if (cursorB->FUN_00726070() && *cursorB->FUN_00726070()->FUN_006815c0() == current)
                {
                    current = *cursorB->FUN_006815c0();
                    break;
                }
                else if (!cursorB->FUN_00726070())
                    current = *cursorB->FUN_006815c0();
                cursorB = cursorB->FUN_00726070();
            }
            DAT_011a59f0 = FUN_007f3bf0(current->id);
            if (current->tile->IsTraitNonZero(4003))
                break;
        }
        UpdateVatsTargetHighlight(0);
    }
}
}  // namespace fnv_007f3070

struct Obj548;
struct StepObj;
struct MidObj;
class NiPoint2;
struct Vec3
{
    float x;
    float y;
    float z;
    void FUN_006815c0();
    Vec3 ApplyScaled(float scale) const;
};
struct NodeC
{
    void* ApplyScaled(Vec3* a1, Vec3* a2, float a3);
};
struct NodeB
{
    void UpdateWorldToCamera();
    void ProjectToScreen(Vec3* a1, float* a2, float* a3, float a4);
    Vec3* FUN_0045bb80();
    Vec3 FUN_0045bba0();
};

struct GlobD
{
    bool FUN_00425fd0();
    void FUN_0054da20(int a1, float a2, int a3, float a4);
    Obj548* FUN_004543c0();
};
struct GlobC
{
    BSSimpleList* FUN_00595d10();
    GlobD* FUN_008d6f30();
    bool FUN_0088b880(int a1, void* a2, int a3, int a4, int a5);
    void* FUN_00575d70();
    MidObj* FUN_00931ed0(void* a);
};

struct TargetListResetCalls
{
    void FUN_00470470();
};

struct Chain43
{
    int FUN_0043b230();
};
struct Obj54
{
    int** FUN_006a9540();
    Chain43* GetValueByIndex(int a);
};
struct Obj6c
{
    Vec3* FUN_0045bb80();
};
Obj6c* __cdecl FUN_004aae30(int a1, int a2);
struct Refr
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool V100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual struct Node148* V148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual Obj54* V180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual int V190(int a);
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual bool V1a0(int a);
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual struct PosObj* V1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual int V1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual int V1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual bool V220();
    virtual bool V224();
    virtual void vf228();
    virtual bool V22c(int a);
    int FUN_007af430();
    Refr* FUN_004181e0();
    Refr* FUN_008d8520();
    bool FUN_00576070();
    bool FUN_00477ba0();
    bool FUN_00440da0();
    bool FUN_00440d80();
    void* FUN_00874480();
    int FUN_00931850();
    float FUN_005723b0(void* a1, int a2, int a3);
};
struct FUN_004759a0_First
{
    BSSimpleList* FUN_00726070();
};
FUN_004759a0_First* __cdecl FUN_00475400(void* a1);
struct PosObj
{
    Vec3* FUN_0045bb80();
    StepObj* FUN_0043d450();
};
struct NodeB8
{
    bool FUN_0046e8c0();
};
struct Node148
{
    NodeB8* FUN_0044ddc0();
};
struct Mgr
{
    float* FUN_00403e20();
    float* FUN_00403e20(void* a1, void* a2);
};
struct WS
{
    void ProcessCellsInRadius(int a1, float a2, int a3, float a4);
};

extern Mgr DAT_011d45b8;
extern Mgr DAT_011cdcbc;
extern Mgr DAT_011cd7d8;
extern double DAT_0102e430;
extern double DAT_01011590;
extern double DAT_01012060;
extern double DAT_01012070;
extern float DAT_010718c0;

void* __cdecl FormHeap_Allocate(unsigned int a1);
extern Vec3 DAT_011f426c;
struct ListHead
{
    void* item;
    ListHead* next;
    void FUN_005ae3d0(void* a1);
    bool FUN_008256d0();
};
struct TargetChildren
{
    void* item;
    TargetChildren* next;
    void FUN_005ae3d0(void* a1);
    bool FUN_008256d0();
};
struct FUN_007f6900_Record
{
    int f0;
    int f4;
    TargetChildren sub;
    bool f10;
    int f14;
    int f18;
    int f1c;
    char f20;
    char b21;
    char b22;
    char b23;
    FUN_007f6900_Record();
};
struct Obj60
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    Vec3 pos;
    int idx;
    int f24;
    float f28;
    char b2c;
    char b2d;
    char b2e;
    char b2f;
    int f30;
    int f34;
    int f38;
    Obj60* FUN_007f6820();
};

struct StepObj
{
    StepObj* FUN_006815c0();
    void* FUN_00439ef0(Vec3* out, Vec3* origin);
};
struct MidObj
{
    void* FUN_004a3a20();
};
struct CountMid
{
    int FUN_00726070();
    void* GetEntryAt(int a);
};
struct CountNode
{
    CountMid* FUN_00460140();
};
struct BigSubA
{
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
};
struct BigSubB
{
    int b00;
    int b04;
    int b08;
    int b0c;
    int b10;
    int b14;
    int b18;
    int b1c;
    int b20;
    int b24;
    int b28;
    int b2c;
    int b30;
    int b34;
    int b38;
    int b3c;
    int b40;
    int b44;
    int b48;
    int b4c;
    int b50;
    int b54;
    int b58;
    int b5c;
};
struct BigSubC
{
    int c00;
    int c04;
    int c08;
    int c0c;
};
struct BigList
{
    __declspec(align(16)) BigSubA sub00;
    BigSubB sub30;
    BigSubC sub90;
    int fA0;
    int fA4;
    int fA8;
    char fAC;
    void FUN_004a3c20();
    void FUN_004a3f70(int a);
    void FUN_004a3fb0(void* a);
    void FUN_004a3da0(void* a);
    void FUN_004a3eb0(void* a);
    void FUN_004a3eb0(const Vec3& a);
    void FUN_007f68a0(void* a);
    void FUN_007f68a0(const Vec3& a);
    CountNode* FUN_008cdd90();
};
struct Obj20c
{
    int f0;
    void FUN_008c71b0(int a);
    void FUN_004a39f0(int a);
    void FUN_0059ce80(void* a);
};
struct Obj5b0
{
    __declspec(align(16)) float normalX;
    float normalY, normalZ, normalW;
    float fraction;
    unsigned int m_uiExtraInfo;
    unsigned int shapeKeys[8];
    int keyIndex;
    int unk3c, unk40, unk44, unk48, unk4c;
    int f50;
    void FUN_00696c30(void* a);
};
struct HitArray
{
    Obj5b0* data;
    int size;
    int capacityAndFlags;
    int storageAlignment;
    unsigned char localHitStorage[sizeof(Obj5b0) * 8];
};
struct hkpAllRayHitCollector
{
    float earlyOutHitFraction;
    int unk08, unk0c;
    HitArray hits;
    hkpAllRayHitCollector();
    virtual ~hkpAllRayHitCollector();
};
int __cdecl FUN_004b5820(int a);
struct Refr;
Refr* __cdecl FUN_0056f930(int a);
bool __cdecl FUN_004753d0(void* a);
void __cdecl FUN_007f6920();
struct Obj548
{
    virtual void x00();
    virtual void x04();
    virtual void x08();
    virtual void x0c();
    virtual void x10();
    virtual void x14();
    virtual void x18();
    virtual void x1c();
    virtual void x20();
    virtual void x24();
    virtual void x28();
    virtual void x2c();
    virtual void x30();
    virtual void x34();
    virtual void x38();
    virtual void x3c();
    virtual void x40();
    virtual void x44();
    virtual void x48();
    virtual void x4c();
    virtual void x50();
    virtual void x54();
    virtual void x58();
    virtual void x5c();
    virtual void x60();
    virtual void x64();
    virtual void x68();
    virtual void x6c();
    virtual void x70();
    virtual void x74();
    virtual void x78();
    virtual void x7c();
    virtual void x80();
    virtual void x84();
    virtual void x88();
    virtual void x8c();
    virtual void x90();
    virtual void x94();
    virtual void x98();
    virtual void x9c();
    virtual void xa0();
    virtual void xa4();
    virtual void xa8();
    virtual void xac();
    virtual void xb0();
    virtual void xb4();
    virtual void xb8();
    virtual void xbc();
    virtual void xc0();
    virtual void xc4();
    virtual bool V0c8(void* a);
};

struct TargetEntry
{
    Refr* reference;
    bool selected;
};
typedef NiPoint2 ScreenPoint;
// Filters references by probability and screen bounds, adds target-list records, and uses physics raycasts when visibility checks fail.
// @fnv 0x007f52c0
bool FUN_007f52c0()
{
    if (!((BSSimpleList*)&g_011db150)->FUN_008256d0())
        return true;
    bool result = false;
    ((NodeB*)FUN_0045c670()->GetAnimationData())->UpdateWorldToCamera();
    BSSimpleList* cur = ((GlobC*)DAT_011dea3c)->FUN_00595d10();
    float fBestProb = 0.0f;
    bool flag21 = ((GlobC*)DAT_011dea3c)->FUN_008d6f30()->FUN_00425fd0();
    reinterpret_cast<TargetListResetCalls*>(&g_011db124)->FUN_00470470();
    while (cur && !cur->FUN_008256d0())
    {
        TargetEntry* target = (TargetEntry*)*cur->FUN_006815c0();
        bool flag29 = true;
        if (target)
            flag29 = (FUN_00475400((void*)target->reference->FUN_007af430())->FUN_00726070() &&
                      !target->reference->FUN_00576070())
                         ? 1
                         : 0;
        if (!target || (target && target->reference->V22c(0)) || !target->reference->V1d0() ||
            target->reference->FUN_00931850() || target->reference->V1a0(0) || flag29)
        {
            cur = cur->FUN_00726070();
            continue;
        }
        float prob = target->reference->FUN_005723b0(DAT_011dea3c, 0, 0);
        if (prob < DAT_01011590 || prob > *DAT_011d45b8.FUN_00403e20() ||
            !((GlobC*)DAT_011dea3c)->FUN_0088b880(1, target->reference, 1, 0, 1))
        {
            cur = cur->FUN_00726070();
            continue;
        }
        if (prob > fBestProb)
            fBestProb = prob;
        Vec3 vec = *target->reference->V1d0()->FUN_0045bb80();
        float fScreenX = 0.0f;
        float fScreenY = 0.0f;
        ((NodeB*)FUN_0045c670()->GetAnimationData())->ProjectToScreen(&vec, &fScreenX, &fScreenY, DAT_010718c0);
        bool bVisible = !(fScreenX <= DAT_01012060 || fScreenY <= DAT_01012060 || fScreenX >= DAT_01012070 ||
                          fScreenY >= DAT_01012070)
                            ? true
                            : false;
        if (!bVisible)
        {
            Refr* base = target->reference->FUN_004181e0();
            Obj54* pObj54 = base->V180();
            int** arr = pObj54->FUN_006a9540();
            for (int i = 0; i < 15; ++i)
            {
                if (arr[i])
                {
                    ScreenPoint vScreen;
                    Refr* actor = ((TargetEntry*)*cur->FUN_006815c0())->reference;
                    Obj6c* pObj6c = FUN_004aae30((int)actor->V1d0(), pObj54->GetValueByIndex(i)->FUN_0043b230());
                    if (pObj6c)
                    {
                        ((NodeB*)FUN_0045c670()->GetAnimationData())
                            ->ProjectToScreen(pObj6c->FUN_0045bb80(), &vScreen.x, &vScreen.y, DAT_010718c0);
                        if (vScreen.x > DAT_01012060 && vScreen.y > DAT_01012060 && vScreen.x < DAT_01012070 &&
                            vScreen.y < DAT_01012070)
                        {
                            bVisible = true;
                            result = true;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            result = true;
        }
        if (((flag21 && prob > *DAT_011cd7d8.FUN_00403e20()) ||
             (!flag21 && prob > *DAT_011cdcbc.FUN_00403e20() * *DAT_011cd7d8.FUN_00403e20())) &&
            !bVisible)
        {
            cur = cur->FUN_00726070();
            continue;
        }
        if (target->reference->V1d0())
        {
            FUN_007f6900_Record* obj = new FUN_007f6900_Record;
            obj->f4 = 1;
            obj->f0 = (int)target->reference;
            obj->f10 = false;
            obj->f20 = ((TargetEntry*)*cur->FUN_006815c0())->selected;
            Refr* base2 = ((Refr*)obj->f0)->FUN_004181e0();
            Obj54* pObj54b = base2->V180();
            int** ppArrb = pObj54b->FUN_006a9540();
            for (int j = 0; j < 15; ++j)
            {
                if (ppArrb[j])
                {
                    Obj60* child = (Obj60*)new FUN_007f6820_cls;
                    child->b2c = false;
                    child->b2d = false;
                    child->b2e = false;
                    child->b2f = true;
                    child->pos = DAT_011f426c;
                    child->f28 = 0.0f;
                    child->idx = j;
                    obj->sub.FUN_005ae3d0(&child);
                }
            }
            int res190 = 0;
            if (((Refr*)obj->f0)->V100())
            {
                res190 = ((Refr*)obj->f0)->FUN_008d8520()->V190(((Refr*)obj->f0)->V1e8());
            }
            Node148* pNode148 = ((Refr*)obj->f0)->V100() ? ((Refr*)obj->f0)->FUN_008d8520()->V148() : 0;
            NodeB8* pNodeB8 = pNode148 ? pNode148->FUN_0044ddc0() : 0;
            if (res190 && pNodeB8 && !pNodeB8->FUN_0046e8c0())
            {
                Obj60* child2 = (Obj60*)new FUN_007f6820_cls;
                child2->b2c = false;
                child2->b2d = false;
                child2->b2e = false;
                child2->b2f = true;
                child2->pos = DAT_011f426c;
                child2->idx = 14;
                obj->sub.FUN_005ae3d0(&child2);
            }
            if (obj->sub.FUN_008256d0())
            {
                obj->f4 = 2;
                Obj60* child3 = (Obj60*)new FUN_007f6820_cls;
                child3->idx = -1;
                child3->b2c = false;
                child3->b2d = false;
                child3->b2e = false;
                child3->b2f = true;
                child3->pos = DAT_011f426c;
                obj->sub.FUN_005ae3d0(&child3);
            }
            ((ListHead*)&g_011db150)->FUN_005ae3d0(&obj);
        }
        cur = cur->FUN_00726070();
    }
    if (fBestProb != DAT_01012060)
        fBestProb = fBestProb + DAT_0102e430;
    if (((GlobC*)DAT_011dea3c)->FUN_00575d70())
    {
        ((WS*)((GlobC*)DAT_011dea3c)->FUN_00575d70())
            ->ProcessCellsInRadius(
                ((Refr*)DAT_011dea3c)->V1f4(), *DAT_011cdcbc.FUN_00403e20() * *DAT_011cd7d8.FUN_00403e20(),
                ((Refr*)DAT_011dea3c)->V1f4(),
                *DAT_011cdcbc.FUN_00403e20((void*)(bool(__cdecl*)(FUN_00452370_shell*)) & FUN_007f4f30, DAT_011dea3c) *
                    *DAT_011cd7d8.FUN_00403e20());
    }
    else
    {
        ((GlobC*)DAT_011dea3c)
            ->FUN_008d6f30()
            ->FUN_0054da20(
                ((Refr*)DAT_011dea3c)->V1f4(), *DAT_011cdcbc.FUN_00403e20() * *DAT_011cd7d8.FUN_00403e20(),
                ((Refr*)DAT_011dea3c)->V1f4(),
                *DAT_011cdcbc.FUN_00403e20((void*)(bool(__cdecl*)(FUN_00452370_shell*)) & FUN_007f4f30, DAT_011dea3c) *
                    *DAT_011cd7d8.FUN_00403e20());
    }
    BSSimpleList* pCurNode2 = (BSSimpleList*)&g_011db124;
    while (pCurNode2 && !pCurNode2->FUN_008256d0())
    {
        float prob2 = ((Refr*)*pCurNode2->FUN_006815c0())->FUN_005723b0(DAT_011dea3c, 0, 0);
        Refr* refr2 = (Refr*)*pCurNode2->FUN_006815c0();
        {
            if (refr2->V100() || ((Refr*)*pCurNode2->FUN_006815c0())->V220() ||
                (fBestProb > DAT_01012060 &&
                 fBestProb < ((Refr*)*pCurNode2->FUN_006815c0())->FUN_005723b0(DAT_011dea3c, 0, 0)) ||
                ((Refr*)*pCurNode2->FUN_006815c0())->FUN_00477ba0() ||
                ((Refr*)*pCurNode2->FUN_006815c0())->FUN_00440da0() ||
                ((Refr*)*pCurNode2->FUN_006815c0())->FUN_00440d80() ||
                (flag21 && prob2 > *DAT_011cd7d8.FUN_00403e20()) ||
                (!flag21 && prob2 > *DAT_011cdcbc.FUN_00403e20() * *DAT_011cd7d8.FUN_00403e20()) ||
                !((Refr*)*pCurNode2->FUN_006815c0())->FUN_00576070())
            {
                pCurNode2 = pCurNode2->FUN_00726070();
                continue;
            }
        }
        {
            Refr* refr4 = (Refr*)*pCurNode2->FUN_006815c0();
            if (refr4->V224())
            {
                Refr* refr5 = (Refr*)*pCurNode2->FUN_006815c0();
                if (refr5->FUN_00874480() == (void*)DAT_011dea3c)
                {
                    pCurNode2 = pCurNode2->FUN_00726070();
                    continue;
                }
            }
        }
        if (!((Refr*)*pCurNode2->FUN_006815c0())->FUN_00477ba0())
        {
            FUN_007f6900_Record* obj2 = new FUN_007f6900_Record;
            obj2->f4 = 2;
            obj2->f0 = (int)*pCurNode2->FUN_006815c0();
            obj2->f10 = false;
            obj2->f20 = 0;
            Obj60* child4 = (Obj60*)new FUN_007f6820_cls;
            child4->idx = -1;
            child4->b2c = false;
            child4->b2d = false;
            child4->b2e = false;
            child4->b2f = true;
            child4->pos = DAT_011f426c;
            obj2->sub.FUN_005ae3d0(&child4);
            if (!result)
            {
                Refr* refr6 = (Refr*)*pCurNode2->FUN_006815c0();
                Vec3 vPos2 = *refr6->V1d0()->FUN_0045bb80();
                float fScreenX2 = 0.0f;
                float fScreenY2 = 0.0f;
                ((NodeB*)FUN_0045c670()->GetAnimationData())
                    ->ProjectToScreen(&vPos2, &fScreenX2, &fScreenY2, DAT_010718c0);
                bool visible = !(fScreenX2 <= DAT_01012060 || fScreenY2 <= DAT_01012060 || fScreenX2 >= DAT_01012070 ||
                                 fScreenY2 >= DAT_01012070)
                                   ? true
                                   : false;
                if (visible)
                {
                    BigList oBigList;
                    oBigList.FUN_004a3c20();
                    Vec3 vOrigin;
                    Vec3 vUnused;
                    vOrigin.FUN_006815c0();
                    vUnused.FUN_006815c0();
                    vOrigin = *((NodeB*)FUN_0045c670()->GetAnimationData())->FUN_0045bb80();
                    Obj20c oFilter;
                    oFilter.FUN_008c71b0(0);
                    oFilter.FUN_004a39f0(0x25);
                    int material;
                    oFilter.FUN_0059ce80(((GlobC*)DAT_011dea3c)->FUN_00931ed0(&material)->FUN_004a3a20());
                    oBigList.FUN_004a3f70(oFilter.f0);
                    hkpAllRayHitCollector oCollector;
                    oBigList.FUN_004a3fb0(&oCollector);
                    oBigList.FUN_004a3da0(&vOrigin);
                    Refr* rayTarget = (Refr*)*pCurNode2->FUN_006815c0();
                    oBigList.FUN_004a3eb0(rayTarget->V1d0()->FUN_0043d450()->FUN_006815c0());
                    Refr* rayTarget2 = (Refr*)*pCurNode2->FUN_006815c0();
                    Vec3 direction;
                    oBigList.FUN_007f68a0(
                        rayTarget2->V1d0()->FUN_0043d450()->FUN_006815c0()->FUN_00439ef0(&direction, &vOrigin));
                    Obj548* physics = ((GlobC*)DAT_011dea3c)->FUN_008d6f30()->FUN_004543c0();
                    bool hit = physics->V0c8(&oBigList);
                    if (hit && oBigList.FUN_008cdd90())
                    {
                        for (int count = 0; !result && count < oBigList.FUN_008cdd90()->FUN_00460140()->FUN_00726070();
                             ++count)
                        {
                            Obj5b0 oContact;
                            oContact.FUN_00696c30(oBigList.FUN_008cdd90()->FUN_00460140()->GetEntryAt(count));
                            int id = FUN_004b5820(oContact.f50);
                            if (id)
                            {
                                Refr* rayTarget3 = (Refr*)*pCurNode2->FUN_006815c0();
                                if (id == (int)rayTarget3->V1d0())
                                    result = true;
                            }
                        }
                    }
                }
            }
            ((ListHead*)&g_011db150)->FUN_005ae3d0(&obj2);
        }
        pCurNode2 = pCurNode2->FUN_00726070();
    }
    if (!result)
    {
        BigList oBigList2;
        oBigList2.FUN_004a3c20();
        Vec3 vStart;
        Vec3 vUnused2;
        vStart.FUN_006815c0();
        vUnused2.FUN_006815c0();
        vStart = *((NodeB*)FUN_0045c670()->GetAnimationData())->FUN_0045bb80();
        Obj20c oFilter2;
        oFilter2.FUN_008c71b0(0);
        oFilter2.FUN_004a39f0(0x25);
        int material2;
        oFilter2.FUN_0059ce80(((GlobC*)DAT_011dea3c)->FUN_00931ed0(&material2)->FUN_004a3a20());
        oBigList2.FUN_004a3f70(oFilter2.f0);
        hkpAllRayHitCollector oCollector2;
        oBigList2.FUN_004a3fb0(&oCollector2);
        oBigList2.FUN_004a3da0(&vStart);
        oBigList2.FUN_004a3eb0(((NodeB*)FUN_0045c670()->GetAnimationData())->FUN_0045bba0());
        oBigList2.FUN_007f68a0(
            ((NodeB*)FUN_0045c670()->GetAnimationData())
                ->FUN_0045bba0()
                .ApplyScaled((flag21 ? *DAT_011cd7d8.FUN_00403e20()
                                      : *DAT_011cdcbc.FUN_00403e20() * *DAT_011cd7d8.FUN_00403e20())));
        Obj548* physics2 = ((GlobC*)DAT_011dea3c)->FUN_008d6f30()->FUN_004543c0();
        bool hit2 = physics2->V0c8(&oBigList2);
        if (hit2 && oBigList2.FUN_008cdd90())
        {
            for (int count2 = 0; !result && count2 < oBigList2.FUN_008cdd90()->FUN_00460140()->FUN_00726070(); ++count2)
            {
                Obj5b0 oContact2;
                oContact2.FUN_00696c30(oBigList2.FUN_008cdd90()->FUN_00460140()->GetEntryAt(count2));
                int id2 = FUN_004b5820(oContact2.f50);
                if (id2)
                {
                    Refr* found = FUN_0056f930(id2);
                    if (found && FUN_004753d0((void*)found->FUN_007af430()) && found->V224())
                        result = true;
                }
            }
        }
    }
    if (!result)
        FUN_007f6920();
    return result;
}

struct Comp2
{
    char GetByte63();
};
struct Comp
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual Comp* GetComp();
    Comp2* GetValueByIndex(int a1);
};
struct ActorView7
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual bool IsReady();
    Comp* FUN_004181e0();
};
struct FUN_007f3bf0_cls
{
    int __thiscall FUN_007f3bf0(int a1);
};
// Returns the value from the actor view's component for a1, or 0x1a if unavailable, or -1 when a1 is 0xe.
// @fnv 0x007f3bf0
int FUN_007f3bf0_cls::FUN_007f3bf0(int a1)
{
    if (DAT_011f21cc == 0 || !((ActorView7*)DAT_011f21cc)->IsReady())
    {
        return 0x1a;
    }
    Comp* pComp = ((ActorView7*)DAT_011f21cc)->FUN_004181e0()->GetComp();
    if (pComp != 0)
    {
        Comp2* r = pComp->GetValueByIndex(a1);
        if (r != 0)
            return r->GetByte63();
    }
    if (a1 == 0xe)
        return -1;
    return 0x1a;
}
