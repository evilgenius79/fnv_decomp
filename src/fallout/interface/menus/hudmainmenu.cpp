// fallout/interface/menus/hudmainmenu.cpp: HUDMainMenu, HUDMainMenuS, Interface, TESSound and more (82 functions)

#include "HUDMainMenu.h"

static const int kGetClassValue = 1004;

// m_pTiles is addressed by 1-based tile ID; slot 0 is the menu root.
enum
{
    kTileIDMax = 86
};

// @fnv 0x0076bdc0
int HUDMainMenu::GetClass()
{
    return kGetClassValue;
}

// Stores apTile in the tile array at index aTileID when aTileID is in the range 1..kTileIDMax.
// @fnv 0x0076bdd0
void HUDMainMenu::AssignTileByID(int aTileID, Tile* apTile)
{
    if (aTileID > 0 && aTileID <= kTileIDMax)
    {
        m_pTiles[aTileID] = apTile;
    }
}

class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
};
struct NodeArg
{
    NiNode* n;
};
// @fnv 0x007700b0
void __fastcall FUN_007700b0(char* self, NodeArg aNodeArg)
{
    ((NiPointer<NiNode>*)(self + 0x64))->operator=(aNodeArg.n);
}

struct FUN_007700d0_cls
{
    char pad[0x91];
    bool val;
    void set(bool b);
};

// @fnv 0x007700d0
void FUN_007700d0_cls::set(bool abValue)
{
    val = abValue;
}

struct FUN_00771540_shell : public HUDMainMenu
{
    void UpdateActorValueMeter(int);
};

struct AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetCurrent(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float GetBase(int);
};

struct PlayerDummy
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
    virtual bool v139(int);
    char pad[0xa0];
    AVOwner avOwner;
};

class PlayerCharacter;
extern PlayerCharacter* pPlayer;
extern double _gModifierZero;

float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
void __cdecl UpdateMeterTile(Tile*, float, int, int, int);

struct HUDMainMenu_WithPme : public HUDMainMenu
{
    static HUDMainMenu* g_pHudMainMenuInstance;
};

// @fnv 0x00771540
void FUN_00771540_shell::UpdateActorValueMeter(int aeActorValue)
{
    switch (aeActorValue)
    {
    case 16: {
        float fbase = ((PlayerDummy*)pPlayer)->avOwner.GetBase(16);
        if (fbase != _gModifierZero)
        {
            fbase = FUN_00404010(0.0f, ((PlayerDummy*)pPlayer)->avOwner.GetCurrent(16)) / fbase;
        }
        if (fbase > 1.0)
        {
            fbase = 1.0f;
        }
        if (!((PlayerDummy*)pPlayer)->v139(0))
        {
            UpdateMeterTile(HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[1], fbase, 0, 1, 0);
        }
        else
        {
            UpdateMeterTile(HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[1], fbase, 0, 0, 0);
        }
        break;
    }
    case 12: {
        float fbase = FUN_00404010(0.0f, ((PlayerDummy*)pPlayer)->avOwner.GetBase(12));
        if (fbase != _gModifierZero)
        {
            fbase = FUN_00404010(0.0f, ((PlayerDummy*)pPlayer)->avOwner.GetCurrent(12)) / fbase;
        }
        UpdateMeterTile(m_pTiles[7], FUN_0040ebd0(fbase, 1.0f), 1, 0, 0);
        break;
    }
    }
}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct ActorValueOwner;
struct ActorCombatEntry;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct MusicMarkerReference;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSNote;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSQuestObjective;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct BipedActor;
struct CombatGroupCollection;
struct CellMopp;
struct NiNodeBooleanState;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialoguePackage;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct FurnitureRelatedType;
struct BooleanFloatQuery;
struct IDebugText;
struct ImageSpaceModifierInstanceDOF;
struct ImageSpaceModifierInstanceDRB;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicShaderHitEffect;
struct MagicTarget;
struct MapMarkerData;
struct MediaLocationController;
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
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct PlayerTargetLocation;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct IntegerPairPointerRecord;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESCaravanCard;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCLOT;
struct TESObjectDOOR;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESQuest;
struct PlayerQuestData;
struct TESRace;
struct TESRegion;
struct TESRegionList;
struct TESReputation;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct PathingPath;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkMouseSpringAction;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
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

// @fnv 0x007721a0
NiAVObject* __fastcall FUN_007721a0(char* thisPtr)
{
    return *(NiAVObject**)(thisPtr + 0xe34);
}

namespace fnv_007735d0 {
struct Tile
{
    bool ContainsTrait(int);
};
struct StrOp
{
    operator void*() const;
};
struct Lst
{
    void** GetNext(void*&);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
// @fnv 0x007735d0
bool __fastcall FUN_007735d0(unsigned char* self)
{
    if (!self[0x260])
        return false;
    void* xelem = (void*)(*(StrOp*)((char*)*(void**)((char*)g_pHudMainMenuInstance + 0x60) + 4));
    Tile* pq = 0;
    while (xelem)
    {
        pq = (Tile*)*((Lst*)((char*)*(void**)((char*)g_pHudMainMenuInstance + 0x60) + 4))->GetNext(xelem);
        if (pq->ContainsTrait(0xfa3))
            return true;
    }
    self[0x260] = 0;
    return false;
}
}  // namespace fnv_007735d0

namespace fnv_00773650 {
struct Tile
{
    bool ContainsTrait(int);
};
struct StrOp
{
    operator void*() const;
};
struct Lst
{
    void** GetNext(void*&);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
// @fnv 0x00773650
bool __fastcall FUN_00773650(unsigned char* self)
{
    if (!self[0x261])
        return false;
    void* xelem = (void*)(*(StrOp*)((char*)*(void**)((char*)g_pHudMainMenuInstance + 0x5c) + 4));
    Tile* pq = 0;
    while (xelem)
    {
        pq = (Tile*)*((Lst*)((char*)*(void**)((char*)g_pHudMainMenuInstance + 0x5c) + 4))->GetNext(xelem);
        if (pq->ContainsTrait(0xfa3))
            return true;
    }
    self[0x261] = 0;
    return false;
}
}  // namespace fnv_00773650

struct BGSQuestObjective
{
    bool HasFlag();
    const char* GetDisplayText();
};
struct Node
{
    bool _ref_008256d0();
    BGSQuestObjective** _ref_006815c0(int);
    Node* _ref_00726070();
    BGSQuestObjective** _ref_006815c0();
};
struct Script
{
    Node* GetVariableList();
};
struct PM
{
    bool FUN_00773650();
};
extern HUDMainMenu* g_pHudMainMenuInstance;
void __cdecl FUN_0077a5b0(const char*, int, int);
// @fnv 0x007736d0
void __cdecl FUN_007736d0(Script* script)
{
    if (!g_pHudMainMenuInstance)
        return;
    if (script && !((PM*)g_pHudMainMenuInstance)->FUN_00773650() && ((Node*)((char*)g_pHudMainMenuInstance + 0x258))->_ref_008256d0())
    {
        Node* pNode = script->GetVariableList();
        while (pNode && !pNode->_ref_008256d0())
        {
            if ((*pNode->_ref_006815c0(1))->HasFlag() && !(*pNode->_ref_006815c0(2))->HasFlag())
                FUN_0077a5b0((*pNode->_ref_006815c0())->GetDisplayText(), 0, 1);
            pNode = pNode->_ref_00726070();
        }
    }
}

namespace fnv_00774800 {
struct Tile
{
    void Set(int, int);
};

// Calls Tile::Set with a fixed first argument and a second argument chosen by the brightness value.
// @fnv 0x00774800
void __cdecl FUN_00774800(Tile* apTile, int aeBrightness)
{
    switch (aeBrightness)
    {
    case 2:
        apTile->Set(0xff5, 0xff);
        break;
    case 1:
    case 3:
        apTile->Set(0xff5, 0xaf);
        break;
    case 4:
        apTile->Set(0xff5, 0x2c);
    case 5:
        apTile->Set(0xff5, 100);
        break;
    default:
        bool bhighDef = true;
        apTile->Set(0xff5, bhighDef ? 0xff : 0xaf);
        break;
    }
}
}  // namespace fnv_00774800

namespace fnv_007748b0 {
struct Tile
{
    float GetFloat(int);
    void Set(int, int);
};

int __cdecl GetTileValueID(char const*, int);
extern HUDMainMenu* DAT_011d96c0;

// @fnv 0x007748b0
void __cdecl UpdateMeterTile(Tile* apTile, float afMeterPercent, int aeJustify, int aiMinTicks, int iNumPixelShift)
{
    static int s_iTotalWidth = GetTileValueID("_TotalWidth", -1);
    static int s_iImageWidth = GetTileValueID("_ImageWidth", -1);
    static int s_iOriginalX = GetTileValueID("_OriginalX", -1);

    if (apTile && DAT_011d96c0)
    {
        if (afMeterPercent > 1.0)
            afMeterPercent = 1.0f;
        else if (afMeterPercent < 0.0)
            afMeterPercent = 0.0f;

        int imeterWidth = static_cast<int>(apTile->GetFloat(s_iTotalWidth));
        int iimageWidth = static_cast<int>(apTile->GetFloat(s_iImageWidth));
        int inewX;
        int inewWidth;

        if (aeJustify == 2)
            inewWidth =
                static_cast<int>((imeterWidth * (afMeterPercent >= 0.0 ? afMeterPercent : 0.0f)) / (iimageWidth * 2)) *
                (iimageWidth * 2);
        else
            inewWidth =
                static_cast<int>((imeterWidth * (afMeterPercent >= 0.0 ? afMeterPercent : 0.0f)) / iimageWidth) *
                iimageWidth;

        if (inewWidth < iimageWidth * aiMinTicks)
            inewWidth = iimageWidth * aiMinTicks;

        inewX = static_cast<int>(apTile->GetFloat(s_iOriginalX));
        if (aeJustify == 1)
            inewX -= inewWidth;
        else if (aeJustify == 2)
            inewX -= inewWidth / 2;

        inewX += iNumPixelShift;

        apTile->Set(0xfb1, inewWidth);
        apTile->Set(0xfa1, inewX);
    }
}
}  // namespace fnv_007748b0

struct FUN_00775670_shell : public HUDMainMenu
{
    void FUN_00775670();
};

class Tile
{
  public:
    void Set(int, int);
    void Set(int, char const*, bool);
};

class Interface
{
  public:
    enum enumMenus
    {
        kMenu_0 = 0
    };
    static bool __cdecl IsMenuActive(enumMenus, unsigned int);
};

extern char const g_011d31e0_arg1[];
extern HUDMainMenu* HUDMainMenu_pme;

// @fnv 0x00775670
void FUN_00775670_shell::FUN_00775670()
{
    if (!Interface::IsMenuActive((Interface::enumMenus)0x3f5, 0))
    {
        HUDMainMenu_pme->m_pTiles[28]->Set(0xfc4, g_011d31e0_arg1, true);
    }
    HUDMainMenu_pme->m_pTiles[28]->Set(0xfa3, 0);
    m_pCurrentSubtitle = 0;
}

struct TESObjectREFR
{
    const ExtraDataList* GetExtra() const;
};

short __fastcall FUN_00418770(const ExtraDataList* pExtra);

// @fnv 0x00778930
int __fastcall GetExtraDataShort(const TESObjectREFR* pThis)
{
    return FUN_00418770(pThis->GetExtra());
}

namespace fnv_00778b80 {
struct NiStream;
struct blob12
{
    char b[12];
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

struct NiPoint3_helper : NiPoint3
{
    NiPoint3 FUN_00439ef0(NiPoint3 const&) const;
};

struct PlayerCharacter
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
    virtual float GetLookingZAngle(int);
};

extern PlayerCharacter* pPlayer;
float __cdecl GetAngleFromVector(NiPoint3 const&);
extern double DAT_0101ff58;
extern double DAT_0102f248;
extern double DAT_010734f8;

// @fnv 0x00778b80
float __cdecl ComputeObjectAngleDelta(NiPoint3 apObjectLoc, NiPoint3 apPlayerLoc)
{
    float fangledelta;
    NiPoint3 movedir = ((NiPoint3_helper&)apObjectLoc).FUN_00439ef0(apPlayerLoc);
    float ftargetangle = GetAngleFromVector(movedir);
    fangledelta = 0.0f;
    fangledelta = ftargetangle - pPlayer->GetLookingZAngle(0);
    if (fangledelta <= DAT_0101ff58)
    {
        fangledelta += 6.2831854820251465;
    }
    else if (fangledelta > 3.1415927410125732)
    {
        fangledelta = 6.2831854820251465 - fangledelta;
    }
    fangledelta *= DAT_0102f248;
    fangledelta *= DAT_010734f8;
    return fangledelta;
}
}  // namespace fnv_00778b80

void* __cdecl operator new(unsigned int);
extern int DAT_011d96ac;

class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

class AnimIdle
{
  public:
    int GetSection(void);
};

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

extern ActorTaskManager g_011d9730;
extern AnimIdle g_timeGlobal;

struct HUDMainMenu_pme_access : public HUDMainMenu
{
    static HUDMainMenu* g_pHudMainMenuInstance;
};

struct QuestObjective_local
{
    char m_kName[0x104];
    bool m_bCompleted;
    bool m_bDisplayed;
};

// @fnv 0x0077a5b0
void __cdecl FUN_0077a5b0(const char* apObjectiveName, bool abCompleted, bool abReminder)
{
    if (HUDMainMenu_pme_access::g_pHudMainMenuInstance && apObjectiveName)
    {
        g_011d9730.QueryPerformanceCounter(0);
        DAT_011d96ac = g_timeGlobal.GetSection();
        QuestObjective_local* pObjective = new QuestObjective_local;
        TaskQueueInterface::CopyStringToBuffer(pObjective->m_kName, 0x104, apObjectiveName);
        pObjective->m_bCompleted = abCompleted;
        pObjective->m_bDisplayed = abReminder;
        ((BSSimpleList<const char*>*)HUDMainMenu_pme_access::g_pHudMainMenuInstance->m_kQuestObjectives)
            ->AddHead((const char*&)pObjective);
        g_011d9730.WaitForTasksDuringRendering();
    }
}

struct QuestUpdateManager
{
    static void SetCustomQuestText(char*, char*, int, int, int, int, char*);
    void* GetQuestNamesItem();
    bool IsQuestNamesEmpty();
    static void AddQuestNamesHead(void*);
    static void AddQuestNamesTail(void*);
    void RemoveQuestNamesHead();
    void RemoveQuestNamesAll();
    static int SortQuestNamesByPriorityFunction(void*, void*);
    char _pad_0[1];
};
typedef char _sizecheck_QuestUpdateManager[sizeof(QuestUpdateManager) == 1 ? 1 : -1];
struct FUN_0077b2a0_shell : public QuestUpdateManager
{
    void* GetQuestNamesHead();
};

void** __fastcall _ref_006815c0(void*);
extern int g_011d970c;

// @fnv 0x0077b2a0
void* FUN_0077b2a0_shell::GetQuestNamesHead()
{
    return *_ref_006815c0(&g_011d970c);
}

namespace fnv_0077b2c0 {
struct QuestUpdateManager
{
    static void SetCustomQuestText(char*, char*, int, int, int, int, char*);
    void* GetQuestNamesItem();
    bool IsQuestNamesEmpty();
    static void AddQuestNamesHead(void*);
    static void AddQuestNamesTail(void*);
    void RemoveQuestNamesHead();
    void RemoveQuestNamesAll();
    static int SortQuestNamesByPriorityFunction(void*, void*);
    char _pad_0[1];
};
typedef char _sizecheck_QuestUpdateManager[sizeof(QuestUpdateManager) == 1 ? 1 : -1];
struct FUN_0077b2c0_shell : public QuestUpdateManager
{
    bool FUN_0077b2c0();
};

extern int g_011d970c;
bool __fastcall _ref_008256d0(void* pThis);

// @fnv 0x0077b2c0
bool FUN_0077b2c0_shell::FUN_0077b2c0()
{
    return _ref_008256d0(&g_011d970c);
}
}  // namespace fnv_0077b2c0

namespace fnv_0077f3c0 {
struct NiAVObject
{
    void SetAppCulled(bool);
};
struct NiNode
{
    NiAVObject* FUN_0045bc00(unsigned int);
};
struct StrOp
{
    operator const char*() const;
};
extern HUDMainMenu* g_pHudMainMenuInstance;
extern StrOp g_011d9770;
// If the HUD menu and node exist, stores visible in the menu and sets the node's app-culled flag to its inverse.
// @fnv 0x0077f3c0
void __cdecl SetHudVisible(bool visible)
{
    if (g_pHudMainMenuInstance && (const char*)g_011d9770)
    {
        if (((NiNode*)(const char*)g_011d9770)->FUN_0045bc00(0))
        {
            g_pHudMainMenuInstance->m_bHudModeActive = visible;
            ((NiAVObject*)(const char*)g_011d9770)->SetAppCulled(!visible);
        }
    }
}
}  // namespace fnv_0077f3c0

namespace fnv_0077f500 {
struct Tile
{
    void Set(int, int);
};
struct TList
{
    void* GetBegin() const;
    Tile** GetNext(void*&);
};
struct StrOp
{
    operator void*() const;
};
struct Lst
{
    void** GetNext(void*&);
};
struct Q
{
    void* GetQuestNamesHead();
    void FUN_0077b2e0();
    void ClearGlobalList();
};
extern HUDMainMenu* g_pHudMainMenuInstance;
extern Q* DAT_011d96bc;
void __cdecl Deallocate(void*);
// Clears each tile in the HUD list via Set(0xfa3, 0), then, unless the menu state is 5, drains and deallocates queued items and calls ClearGlobalList.
// @fnv 0x0077f500
void __fastcall ResetHudTiles(void* self)
{
    Tile* tile;
    void* pIter = (void*)(*(StrOp*)((char*)*(void**)((char*)g_pHudMainMenuInstance + 0x60) + 4));
    tile = 0;
    while (pIter)
    {
        tile = (Tile*)*((Lst*)((char*)*(void**)((char*)g_pHudMainMenuInstance + 0x60) + 4))->GetNext(pIter);
        if (tile)
            tile->Set(0xfa3, 0);
    }
    if (*(int*)((char*)g_pHudMainMenuInstance + 0x1c4) != 5)
    {
        while (DAT_011d96bc->GetQuestNamesHead())
        {
            void* item = DAT_011d96bc->GetQuestNamesHead();
            {
                void* pItemCopy = item;
                Deallocate(pItemCopy);
            }
            DAT_011d96bc->FUN_0077b2e0();
        }
        DAT_011d96bc->ClearGlobalList();
    }
}
}  // namespace fnv_0077f500

namespace fnv_00773050 {
struct Tile
{
    void Set(int, int);
    Menu* GetMenu();
};

unsigned int __cdecl FUN_00706f20(void);
Menu* __cdecl FindMenuById(int);
extern int DAT_011a010c;
extern HUDMainMenu* DAT_011d96c0;

// @fnv 0x00773050
void __cdecl ResetHUDMainMenu()
{
    Tile* ptile;
    HUDMainMenu* pmenu;

    ptile = reinterpret_cast<Tile*>(FindMenuById(FUN_00706f20()));
    if (!ptile || !ptile->GetMenu())
        return;

    pmenu = reinterpret_cast<HUDMainMenu*>(ptile->GetMenu());
    pmenu->m_pTargetActor = 0;
    pmenu->m_uiHudValueSecondAfterActor = 0;
    pmenu->m_iHudValueFirstAfterUnsignedValues = -1;
    pmenu->m_iHudValueSecondAfterUnsignedValues = -1;
    pmenu->m_bHudAnimationActive = false;
    pmenu->m_pTiles[50]->Set(0xfa3, 0);
    pmenu->m_bSequenceActive = false;
    DAT_011d96c0->m_pTiles[44]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[45]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[46]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[47]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[48]->Set(0xfa3, 0);
    DAT_011d96c0->m_pTiles[49]->Set(0xfa3, 0);
    DAT_011a010c = 1;
    DAT_011d96c0->m_bQuestObjectiveUpdatesEnabled = true;
}
}  // namespace fnv_00773050

struct FUN_00525430_Class
{
    int mField0;
    int mField4;
    int mMode;
    bool FUN_00525430();
};

// @fnv 0x00525430
bool FUN_00525430_Class::FUN_00525430()
{
    return mMode != 0;
}

struct Flt
{
    operator unsigned int(void) const;
};

struct FUN_00772820
{
    unsigned int Get();
};

// @fnv 0x00772820
unsigned int FUN_00772820::Get()
{
    return *reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xcc);
}

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& pt) const;
};
extern double _gModifierZero;
extern const double DAT_0102f248;
float __cdecl _logf(float);
float __cdecl WrapAngle(float);

// Computes the angle from aStart to aDest using the direction vector, wraps it, and scales it by DAT_0102f248.
// @fnv 0x00772840
float __cdecl GetAngleBetweenPoints(const NiPoint3& aStart, const NiPoint3& aDest)
{
    float fretangle = 0.0f;
    NiPoint3 direction = aDest - aStart;
    if (direction.y != _gModifierZero)
    {
        float ftan = direction.x / direction.y;
        fretangle = _logf(ftan);
        if (direction.y < _gModifierZero)
            fretangle += (double)3.1415927f;
    }
    else if (direction.x < _gModifierZero)
    {
        fretangle = 3.1415927f;
    }
    fretangle = WrapAngle(fretangle);
    return fretangle * DAT_0102f248;
}

namespace fnv_00772c30 {
class Tile
{
  public:
    static int __cdecl GetTraitID(const char* text);
    float GetFloat(int trait);
    bool FUN_00a07fc0(int trait);
    void Set(int trait, int value);
    void Set(int trait, const char* value, bool propagate);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
extern double _gModifierZero;

// @fnv 0x00772c30
void __cdecl SetHoldText(const char* pText)
{
    static int iHoldTrait = Tile::GetTraitID("_Hold");
    if (pText && (*(Tile**)((char*)g_pHudMainMenuInstance + 0x68))->GetFloat(4009) == _gModifierZero &&
        (*(Tile**)((char*)g_pHudMainMenuInstance + 0x68))->FUN_00a07fc0(4009))
    {
        (*(Tile**)((char*)g_pHudMainMenuInstance + 0x64))->Set(4036, pText, true);
        (*(Tile**)((char*)g_pHudMainMenuInstance + 0x64))->Set(Tile::GetTraitID("_Hold"), 1);
    }
}
}  // namespace fnv_00772c30

static HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x007732b0
int __cdecl GetHUDMainMenuValue()
{
    if (!g_pHudMainMenuInstance)
        return 0;
    return *(int*)((char*)g_pHudMainMenuInstance + 0x21c);
}

struct FUN_007735b0_class
{
    unsigned char GetByteAt5F8();
};

// @fnv 0x007735b0
unsigned char FUN_007735b0_class::GetByteAt5F8()
{
    return *(unsigned char*)((char*)this + 0x5f8);
}

class SoundPlaybackHandle
{
  public:
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& rhs);
    ~SoundPlaybackHandle();
    bool IsValid();
    bool Play(bool bUnk);
    bool StopWithFade(unsigned int uiMilliseconds);
};
class BSAudio
{
  public:
    static BSAudio* __cdecl GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* pEditorID, unsigned int uiFlags);
};
struct HUDMainMenuS
{
    void FUN_007737c0(float afDrinkinRads, float afStandinRads);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
extern double _gModifierZero;

// @fnv 0x007738c0
void __cdecl UpdateRadiationHUD(float afDrinkinRads, float afStandinRads)
{
    float ftotalRads = afDrinkinRads + afStandinRads;
    if (g_pHudMainMenuInstance)
    {
        if (ftotalRads > _gModifierZero)
        {
            if (!((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->IsValid() && afStandinRads > _gModifierZero)
            {
                *(SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac) =
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPipBoyRadiationTestLP", 0x11);
                ((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->Play(false);
            }
            ((HUDMainMenuS*)g_pHudMainMenuInstance)->FUN_007737c0(afDrinkinRads, afStandinRads);
        }
        else if (((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->IsValid())
        {
            ((SoundPlaybackHandle*)((char*)g_pHudMainMenuInstance + 0x1ac))->StopWithFade(500);
        }
    }
}

namespace fnv_00773e90 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_00773e90_shell : public HUDMainMenu
{
    void FUN_00773e90(Tile*, float, bool);
};

struct Tile
{
    void Set(int trait, int value);
    void Set(int trait, float value, bool propagate);
};
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting808;
extern Setting_S originalRuntimeFloatSetting809;
extern Setting_S originalRuntimeFloatSetting810;
extern Setting_S originalRuntimeFloatSetting811;
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
extern bool DAT_011d9afc;
extern unsigned int DAT_011d9b00;
extern float DAT_011d9b04;
void __cdecl FUN_005330e0(float& value, float fMin, float fScaledValue);

// Sets the tile's trait 4084 and alpha 4009 from afCurrValue thresholds, and when bResetValues advances DAT_011d9b04 by a fade step clamped to 128..255.
// @fnv 0x00773e90
void FUN_00773e90_shell::FUN_00773e90(Tile* apTile, float afCurrValue, bool bResetValues)
{
    float fAlphaFadeSpeed = 0.5f;
    if (afCurrValue >= *originalRuntimeFloatSetting808.Float())
    {
        apTile->Set(4084, 2);
        apTile->Set(4009, DAT_011d9b04, true);
    }
    else if (afCurrValue >= *originalRuntimeFloatSetting809.Float())
    {
        apTile->Set(4084, 2);
        apTile->Set(4009, 255);
    }
    else if (afCurrValue >= *originalRuntimeFloatSetting810.Float())
    {
        apTile->Set(4084, 1);
        apTile->Set(4009, 255);
    }
    else if (afCurrValue >= *originalRuntimeFloatSetting811.Float())
    {
        apTile->Set(4084, 1);
        apTile->Set(4009, 124);
    }
    else
    {
        apTile->Set(4084, 1);
        apTile->Set(4009, 0);
    }
    if (bResetValues)
    {
        unsigned int iLastHardcoreFadeTimeLocal = g_timeGlobal.GetSection();
        unsigned int iCurrTimeDiff = iLastHardcoreFadeTimeLocal - DAT_011d9b00;
        DAT_011d9b00 = iLastHardcoreFadeTimeLocal;
        if (DAT_011d9afc)
            DAT_011d9b04 -= iCurrTimeDiff * fAlphaFadeSpeed;
        else
            DAT_011d9b04 += iCurrTimeDiff * fAlphaFadeSpeed;
        if (DAT_011d9b04 >= 255.0)
            DAT_011d9afc = true;
        if (DAT_011d9b04 <= 128.0)
            DAT_011d9afc = false;
        FUN_005330e0(DAT_011d9b04, 128.0f, 255.0f);
    }
}
}  // namespace fnv_00773e90

void** __fastcall _ref_006815c0(void*);

struct FUN_00775210_cls
{
    FUN_00775210_cls* FUN_00775210();
};

// @fnv 0x00775210
FUN_00775210_cls* FUN_00775210_cls::FUN_00775210()
{
    _ref_006815c0((void*)((char*)this + 0x10c));
    return this;
}

namespace fnv_00778990 {
class Tile
{
  public:
    void Set(int trait, const char* value, bool propagate);
};
struct Actor
{
    float FUN_008c4330();
};
struct PC7d : Actor
{
};
extern PC7d* g_thePlayer;
struct StartMenu
{
    const char* GetMenuTitle();
};
extern StartMenu g_011d30c0;
extern HUDMainMenu* g_pHudMainMenuInstance;
extern double _gModifierZero;
void __cdecl ApplyPerkModifiers(int eEntryPoint, Actor* pActor, ...);
int __cdecl _sprintf(char* buffer, const char* format, ...);

// Computes radiation magnitude from the player's resistance and perk modifiers, formats it, and sets the info label and value tiles.
// @fnv 0x00778990
void __cdecl UpdateRadiationInfo(int aiRadiationAmount, int aiInfoLabel, int aiInfoValue)
{
    char str[260];
    float fmodifiedMagnitude;
    float fresistance = g_thePlayer->FUN_008c4330();
    float feffectivenessMult = 1.0f;
    ApplyPerkModifiers(0x1a, g_thePlayer, &feffectivenessMult);
    fresistance *= feffectivenessMult;
    fmodifiedMagnitude = aiRadiationAmount * fresistance;
    _sprintf(str, "%i",
             (fmodifiedMagnitude > _gModifierZero && fmodifiedMagnitude < 1.0) ? 1 : (int)fmodifiedMagnitude);
    g_pHudMainMenuInstance->m_pTiles[aiInfoLabel]->Set(4036, str, true);
    g_pHudMainMenuInstance->m_pTiles[aiInfoValue]->Set(4036, g_011d30c0.GetMenuTitle(), true);
}
}  // namespace fnv_00778990

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011d0c60;
struct Actor
{
    unsigned short GetLevel();
};
struct PC7d : Actor
{
};
extern PC7d* g_thePlayer;
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValueInt(int eAV);
    virtual float GetBaseActorValue(int eAV);
    virtual int GetActorValueInt(int eAV);
    virtual float GetActorValue(int eAV);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
struct LevelUpEntry
{
    int iLevel;
    int iXP;
    int iParam;
};
struct G2
{
    void AddHead(LevelUpEntry*& item);
};

// If the player's level is below the threshold and the HUD flag is unset, allocates a LevelUpEntry with the level, XP and param and adds it to the HUD list.
// @fnv 0x0077c440
void QueueLevelUpNotification(int param)
{
    int level = g_thePlayer->GetLevel();
    if (level < *g_011d0c60.Int() && !*((bool*)g_pHudMainMenuInstance + 0x204))
    {
        LevelUpEntry* entry = new LevelUpEntry;
        entry->iParam = param;
        entry->iLevel = level;
        entry->iXP = (int)((ActorValueOwner*)((char*)g_thePlayer + 0xa4))->GetActorValue(0x18);
        ((G2*)((char*)g_pHudMainMenuInstance + 0x264))->AddHead(entry);
    }
}

namespace fnv_0077da30 {
static HUDMainMenu* g_pHudMainMenuInstance;
extern int DAT_011a010c;

// @fnv 0x0077da30
void __cdecl FUN_0077da30()
{
    if (g_pHudMainMenuInstance)
        g_pHudMainMenuInstance->m_bSequenceActive = 0;
    DAT_011a010c = 1;
}
}  // namespace fnv_0077da30

struct TESSound
{
    unsigned int Deallocate();
    bool FUN_0077eac0();
};

struct DataHandler
{
    bool FormIDExists(unsigned int);
};

extern DataHandler* g_dataHandler;

// @fnv 0x0077eac0
bool TESSound::FUN_0077eac0()
{
    return !g_dataHandler->FormIDExists(Deallocate());
}

namespace fnv_0077f5e0 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_0077f5e0_shell : public HUDMainMenu
{
    void ResetWaitTiles();
};

struct Tile
{
    void Set(int, int);
    void Set(int, float, bool);
    static int __cdecl GetTraitID(const char*);
};
template <class T> struct NiTListItem;
template <class T> struct NiTPointerList
{
    T& GetPrev(NiTListItem<T>*& rkPos);
};
void* __fastcall _ref_00726070(void*);
void __fastcall FUN_00470470(void*);
struct TileReference
{
    Tile* pTile;
};
bool __fastcall _ref_008256d0(void* pThis);
void** __fastcall _ref_006815c0(void*);
extern HUDMainMenu* g_pHudMainMenuInstance;

// @fnv 0x0077f5e0
void FUN_0077f5e0_shell::ResetWaitTiles()
{
    void* xchildIter = _ref_00726070((char*)g_pHudMainMenuInstance->m_pTiles[13] + 4);
    Tile* ptile = 0;
    while (xchildIter)
    {
        ptile = ((NiTPointerList<Tile*>*)((char*)g_pHudMainMenuInstance->m_pTiles[13] + 4))->GetPrev((NiTListItem<Tile*>*&)xchildIter);
        if (ptile)
        {
            ptile->Set(0xfa3, 0);
            ptile->Set(0xfa9, 0.0f, true);
            ptile->Set(Tile::GetTraitID("_WaitComplete"), 0.0f, true);
            ptile->Set(Tile::GetTraitID("_HoldTime"), 0.0f, true);
        }
    }
    if (g_pHudMainMenuInstance->m_eHudMenuMode != 5)
    {
        void* pCurrentElementNext = &g_pHudMainMenuInstance->m_kQuestObjectives;
        while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
        {
            delete (TileReference*)*_ref_006815c0(pCurrentElementNext);
            pCurrentElementNext = _ref_00726070(pCurrentElementNext);
        }
        FUN_00470470(&g_pHudMainMenuInstance->m_kQuestObjectives);
    }
}
}  // namespace fnv_0077f5e0

namespace fnv_0077f890 {
class Tile
{
  public:
    float GetFloat(int trait);
    void Set(int trait, float value, bool propagate);
};
extern HUDMainMenu* g_pHudMainMenuInstance;
struct HUDMainMenuS
{
    void ShiftTileValues(int aishift);
};

// Adds aishift to trait 4001 of four Tile objects at offsets 0x50, 0x54, 0x4c and 0x180 and sets the results with propagation.
// @fnv 0x0077f890
void HUDMainMenuS::ShiftTileValues(int aishift)
{
    (*(Tile**)((char*)this + 0x50))->Set(4001, (*(Tile**)((char*)g_pHudMainMenuInstance + 0x50))->GetFloat(4001) + aishift, true);
    (*(Tile**)((char*)this + 0x54))->Set(4001, (*(Tile**)((char*)g_pHudMainMenuInstance + 0x54))->GetFloat(4001) + aishift, true);
    (*(Tile**)((char*)this + 0x4c))->Set(4001, (*(Tile**)((char*)g_pHudMainMenuInstance + 0x4c))->GetFloat(4001) + aishift, true);
    (*(Tile**)((char*)this + 0x180))->Set(4001, (*(Tile**)((char*)g_pHudMainMenuInstance + 0x180))->GetFloat(4001) + aishift, true);
}
}  // namespace fnv_0077f890

struct GameTimerRecord
{
    void Update();
    void Update(unsigned int);
    float GetSeconds();
    float GetUnmodifiedSeconds();
    unsigned int GetTime();
    unsigned int GetStartTime();
    void ClampAt(unsigned int);
    bool QEnabled();
    bool GetSecondsIsZero();
    void SetGlobalTimeMultiplier(float, bool);
    static void SetGlobalTimeMultiplierCache();
    void RestoreGlobalTimeMultiplierCache();
    static float QGlobalTimeMultiplier();
    static float QGlobalTimeMultiplierTarget();
    static void UpdateGlobalTimeMultiplier();
    void SetUseGlobalTimeMultiplierTarget(bool);
    bool QUseGlobalTimeMultiplierTarget();
    float GetRealTimeSeconds();
    void Enable();
    void Disable();
    void Init(unsigned int);
    unsigned char m_ucFirstTimerByte;
    char _pad_1[3];
    float m_fFirstTimerValue;
    float m_fSecondTimerValue;
    float fTimeSinceScaleStart;
    float m_fFourthTimerValue;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;
    bool m_bFirstTimerFlag;
    bool m_bSecondTimerFlag;
    char _pad_1e[2];
};
typedef char _sizecheck_BSTimer[sizeof(GameTimerRecord) == 32 ? 1 : -1];
struct FUN_00aa4ee0_shell : public GameTimerRecord
{
    void FUN_00aa4ee0();
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
extern double _gModifierZero;
extern float DAT_011ac3a0;
struct FUN_00aa4ee0_t : public GameTimerRecord
{
    void FUN_00aa4ee0(unsigned int aiTime);
};

// @fnv 0x00aa4ee0
void FUN_00aa4ee0_t::FUN_00aa4ee0(unsigned int aiTime)
{
    unsigned int iscaleTime = aiTime - m_uiSecondTimerValue;
    if ((bool)(m_ucFirstTimerByte ? 0 : 1))
    {
        if (m_fFirstTimerValue != _gModifierZero)
        {
            m_fSecondTimerValue += m_fFirstTimerValue;
            unsigned int iclampTicks = (unsigned int)m_fSecondTimerValue;
            m_fSecondTimerValue -= iclampTicks;
            iscaleTime = m_uiFirstTimerValue + iclampTicks;
            fTimeSinceScaleStart = m_fFirstTimerValue * (double)0.001f;
        }
        else
        {
            unsigned int uiDelta;
            if (!(uiDelta = iscaleTime - m_uiFirstTimerValue))
            {
                m_bSecondTimerFlag = true;
                uiDelta = 1;
            }
            else
            {
                m_bSecondTimerFlag = false;
                if (uiDelta > 166)
                    uiDelta = 166;
            }
            if (uiDelta < 10)
            {
                unsigned int uiSleep = 10 - uiDelta;
                Sleep(uiSleep);
                uiDelta = 10;
            }
            fTimeSinceScaleStart = uiDelta * (double)0.001f;
        }
        m_uiFirstTimerValue = iscaleTime;
        m_fFourthTimerValue = fTimeSinceScaleStart;
        fTimeSinceScaleStart *= DAT_011ac3a0;
    }
    else
    {
        fTimeSinceScaleStart = 0.0f;
    }
}

struct FUN_00770070_Class
{
    int m_kPointA[11];
    int m_kPointB[82];
    bool HasAllTiles();
};

// @fnv 0x00770070
bool FUN_00770070_Class::HasAllTiles()
{
    for (int i = 1; i < 86; ++i)
    {
        if (m_kPointB[i - 1] == 0)
            return false;
    }
    return true;
}

struct FUN_007737a0_Class
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
    bool HasFlag(unsigned int mask);
};

// @fnv 0x007737a0
bool FUN_007737a0_Class::HasFlag(unsigned int mask)
{
    return (m_20 & mask) ? true : false;
}

extern int g_011d970c;

struct FUN_009ca410_shell_base
{
    void FUN_0063f7b0();
};

struct FUN_0077b2e0_shell : public FUN_009ca410_shell_base
{
    void FUN_0077b2e0();
};

// @fnv 0x0077b2e0
void FUN_0077b2e0_shell::FUN_0077b2e0()
{
    reinterpret_cast<FUN_009ca410_shell_base*>(&g_011d970c)->FUN_0063f7b0();
}

struct List_009e03e0
{
    void RemoveAll();
};
extern int g_011d970c;

struct FUN_0077f5c0_Class
{
    void ClearGlobalList();
};

// @fnv 0x0077f5c0
void FUN_0077f5c0_Class::ClearGlobalList()
{
    ((List_009e03e0*)&g_011d970c)->RemoveAll();
}

extern "C" void __cdecl _Deallocate(void*);
void __cdecl FUN_0076be30();

struct FUN_0076be00_Class
{
    void __thiscall FUN_0076be30();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_0076be30, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x0076be00
void* __thiscall FUN_0076be00_Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_0076be30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_007728f0 {
struct TileValues_007728f0
{
    enum TILE_FADE_CONTROL_TYPE
    {
        FADE_TYPE_0
    };
    float GetFloat(int trait);
    const char* GetString(int trait);
    bool FUN_00a07fc0(int trait);
    static int __cdecl GetTraitID(const char* text);
    void Set(int trait, int value);
    void Set(int trait, unsigned int value);
    void Set(int trait, const char* value, bool propagate);
    void SetTraitFade(int trait, float fStart, float m_fEndValue, float fDuration, TILE_FADE_CONTROL_TYPE eType);
};
struct Setting_S
{
    float* Float();
};
extern Setting_S g_011d9774;
struct RegionDisplayInfo
{
    unsigned int uiRegionID;
    char m_kName[260];
    bool bShowOnce;
};
extern unsigned int DAT_011d9aec;
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
extern HUDMainMenu* g_pHudMainMenuInstance;
extern double _gModifierZero;
int __cdecl FUN_00408b20(const char* a, const char* b);

// @fnv 0x007728f0
void __cdecl ShowRegionData(const RegionDisplayInfo* aRegionData)
{
    if (!g_pHudMainMenuInstance)
        return;
    if (g_pHudMainMenuInstance && (!aRegionData->bShowOnce || aRegionData->uiRegionID != DAT_011d9aec))
    {
        if (aRegionData->bShowOnce)
            DAT_011d9aec = aRegionData->uiRegionID;
        bool bshowRegion =
            reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])->GetFloat(4009) == _gModifierZero ||
            !FUN_00408b20(aRegionData->m_kName,
                          reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])->GetString(4036));
        if (aRegionData->m_kName[0] &&
            reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[16])->GetFloat(4009) == _gModifierZero &&
            reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[16])->FUN_00a07fc0(4009))
        {
            reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])->Set(TileValues_007728f0::GetTraitID("_Hold"), 0);
            reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])->Set(4036, aRegionData->m_kName, true);
            if (!bshowRegion)
            {
                reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])
                    ->SetTraitFade(4009, 0.0f, *g_011d9774.Float() * 255.0, 2.0f, TileValues_007728f0::FADE_TYPE_0);
                reinterpret_cast<TileValues_007728f0*>(g_pHudMainMenuInstance->m_pTiles[15])
                    ->Set(4100, (unsigned int)g_timeGlobal.GetSection());
            }
        }
    }
}
}  // namespace fnv_007728f0

namespace fnv_00778a90 {
extern "C" int __cdecl sprintf(char*, const char*, ...);
struct Tile
{
    void Set(int, const char*, bool);
};
struct StartMenu
{
    const char* GetMenuTitle();
};
struct GlobalObject_011d300c
{
    const char* GetMenuTitle();
};
extern GlobalObject_011d300c g_011d300c;
extern Tile** _pme;
extern char $SG7674[];
// @fnv 0x00778a90
void __cdecl UpdateHealthInfoTiles(int aiHealth, int aiInfoLabel, int aiInfoValue)
{
    char str[260];
    sprintf(str, $SG7674, aiHealth);
    ((Tile**)((char*)_pme + 0x28))[aiInfoLabel]->Set(0xfc4, str, true);
    ((Tile**)((char*)_pme + 0x28))[aiInfoValue]->Set(0xfc4, g_011d300c.GetMenuTitle(), true);
}
}  // namespace fnv_00778a90

namespace fnv_0077f420 {
struct Tile
{
    void Set(int, int);
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
extern GameTimerRecord g_timeGlobal;
extern Tile* _pme;

// Stores the global time at offset 0x24c and, if the flag at 0x1bc is set, calls Set(0xfa3, 1) on the tile at 0x170 or 0x154 depending on bFlag.
// @fnv 0x0077f420
void __cdecl FUN_0077f420(bool bFlag)
{
    *(unsigned int*)((char*)_pme + 0x24c) = g_timeGlobal.GetTime();
    if (*(unsigned int*)((char*)_pme + 0x1bc) & 1)
    {
        if (bFlag)
            (*(Tile**)((char*)_pme + 0x170))->Set(0xfa3, 1);
        else
            (*(Tile**)((char*)_pme + 0x154))->Set(0xfa3, 1);
    }
}
}  // namespace fnv_0077f420

namespace fnv_0077f490 {
struct Tile
{
    void Set(int, int);
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
extern GameTimerRecord g_timeGlobal;
extern char* _pme;

// Stores the current time at _pme+0x250 and, when bit 8 of _pme+0x1bc is set, calls Set(0xfa3, 1) on the tile at _pme+0x174 or _pme+0x158 depending on bFlag.
// @fnv 0x0077f490
void __cdecl UpdateTileOnFlag(bool abUseFirstTile)
{
    *(unsigned int*)(_pme + 0x250) = g_timeGlobal.GetTime();
    if (*(unsigned int*)(_pme + 0x1bc) & 8)
    {
        if (abUseFirstTile)
            ((Tile*)(*(unsigned int*)(_pme + 0x174)))->Set(0xfa3, 1);
        else
            ((Tile*)(*(unsigned int*)(_pme + 0x158)))->Set(0xfa3, 1);
    }
}
}  // namespace fnv_0077f490

struct GetModHelper_4bcf00
{
    unsigned char padding[0x1a0];
    float GetModdedWeaponValue(int, int);
};

struct TESObjectWEAP : public GetModHelper_4bcf00
{
    unsigned char padding[4];
    float ammoRegenRate;
    float FUN_00709430(bool bModValue);
};

// @fnv 0x00709430
float TESObjectWEAP::FUN_00709430(bool bModValue)
{
    if (bModValue)
    {
        return GetModdedWeaponValue(6, 0) + ammoRegenRate;
    }
    else
    {
        return ammoRegenRate;
    }
}

struct MarkerVector
{
    float x, y, z;
    MarkerVector operator-(const MarkerVector& other) const;
    float SquaredLength() const;
};
struct TargetMarker
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
    MarkerVector position;
    int priority;
};
struct MarkerArray
{
    unsigned int GetSize();
    TargetMarker*& GetAt(unsigned int index);
};
struct MarkerPlayer
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const MarkerVector& GetPosition();
};
extern MarkerPlayer* DAT_011dea3c;
extern float DAT_01016970;
extern float DAT_01013d84;
float __cdecl ForwardFloatAndInt(float base, int exponent);
struct HUDTargetSelector : HUDMainMenu
{
    TargetMarker* FindTargetMarker();
};
// @fnv 0x00775230
TargetMarker* HUDTargetSelector::FindTargetMarker()
{
    TargetMarker* selected3 = 0;
    float best3 = DAT_01016970;
    MarkerVector player = DAT_011dea3c->GetPosition();
    for (unsigned int index = 0; index < reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetSize(); ++index)
    {
        float distance =
            (reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index)->position - player).SquaredLength();
        if ((!selected3 && distance <= ForwardFloatAndInt(DAT_01013d84, 2)) ||
            (selected3 && distance < best3 &&
             reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index)->priority >= selected3->priority) ||
            reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index)->priority == 0x7fffffff)
        {
            selected3 = reinterpret_cast<MarkerArray*>(m_kSubtitleArray)->GetAt(index);
            best3 = distance;
        }
    }
    return selected3;
}

struct PointX
{
    float x, y, z;
};

struct TileX
{

    void Set(int aeID, int aiValue);

    void Set(int aeID, const char* apValue, bool abPropagate);

    void Set(int aeID, float afValue, bool abPropagate);

    const char* GetString(int aeID);

    float GetFloat(int aeID);

    void Refresh(int aiArg);
};

struct SettingX
{

    const char* Get();

    float* Float();
};

struct StringX
{

    char* pString;

    unsigned short usLen, usMax;

    StringX();

    StringX(const char* apString);

    ~StringX();

    StringX& operator=(const StringX& arString);

    unsigned int Length();

    const char* c_str();
};

class TESForm
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

    virtual struct ModelListX* GetModelList();

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

    virtual struct PointX* GetPos();

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

    virtual bool IsCreature();

    virtual void v228();

    virtual bool IsDead(bool abArg);

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

    virtual bool IsInCombat(bool abArg);

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

    virtual float GetDistanceScale(int aiArg);

    int GetFormType();

    bool IsTerminalUsable(class RefX* apRef);

    bool IsPlayable();

    bool GetFlag() const;

    bool IsQuestItem();

    int GetTerminalLevel(class RefX* apRef);

    TESForm* GetTemplate(int aiArg);

    TESForm* GetLeveled();
};

class TESBoundObject : public TESForm
{
};

class TESObjectACTI : public TESBoundObject
{

  public:
    StringX GetActivateText();
};

struct FormTypeX
{
    int GetFormType();
};

struct AmmoX : public TESForm
{
    char _pad04[0x7c];
    FormTypeX kSub;
};

struct AIFormX
{

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();

    virtual bool IsEssential();
};

struct ActorBaseX : public TESForm
{
    char _pad04[0x2c];
    AIFormX kAI;
    float GetHealth() const;
};

struct ModelListX
{
    int GetCount();
};

struct WeaponX : public TESForm
{
    float GetWeight(unsigned char acMod);
};

struct KeyX;

struct LockX
{

    int iLevel;

    KeyX* pKey;

    bool IsLocked();

    bool MeetsMinimumLockLevel();
};

struct DetectX
{
    int iLevel;
    bool bDetected;
};

struct ExtraListX;

struct ExtraListListX
{

    ExtraListX* pItem;

    ExtraListListX* pNext;

    ExtraListListX();

    void AddHead(ExtraListX* const& arItem);
};

struct EntryX
{

    ExtraListListX* pList;

    int iCount;

    TESForm* pType;

    EntryX(TESForm* apType, int aiCount);

    EntryX(const EntryX& arEntry);

    ~EntryX();

    TESForm* GetType();

    float GetValue();

    unsigned char HasMod(int aiMod);
};

struct NameHolderX
{
    void GetName(StringX& arName);
};

struct ExtraNameX
{
    char _pad[0x18];
    StringX kName;
};

struct PerceivedX
{
    class RefX* pActor;
    bool bVisible;
};

struct PerceivedListX
{

    bool IsEmpty();

    PerceivedX*& GetItem();

    PerceivedListX* GetNext();
};

struct InputX
{
    unsigned char GetButton(int aiControl, int aiType);
};

struct OSX
{
    InputX* GetInput();
};

struct SoundX
{
    void Play();
};

struct FontX
{

    static FontX* __cdecl Instance();

    PointX GetSize(const char* apText, int aiFont, float afWidth, int aiArg);
};

class RefX : public TESForm
{

  public:
    TESBoundObject* GetBaseObject();

    bool IsHostileTo(RefX* apActor);

    bool IsSneaking();

    bool IsPlayerTeammate();

    LockX* GetLock();

    TESForm* GetOwner();

    int GetItemCount(int aiArg1, int aiArg2);

    bool IsDisabled();

    int GetActivateType();

    bool CanActivate(PointX* apPos, int aiArg1, int aiArg2, struct ActivateDataX* apData, int* apResult, int aiArg3);

    DetectX* GetDetection(RefX* apActor);

    bool IsTalkable();

    bool IsCommandable();

    EntryX* GetEquippedEntry();

    NameHolderX* GetNameHolder();

    bool IsOff();

    int GetLockLevel();

    ExtraListX* GetExtraList() const;

    const char* GetFullName();

    int GetSkillPoints();

    PerceivedListX* GetPerceivedActors();

    bool IsUnconscious();

    ExtraNameX* GetExtraData(unsigned char aeType);

    ActorBaseX* GetActorBase();

    bool CanBeUsed(RefX* apActor, bool abArg);

    bool IsRestrained();

    bool HasRefFlag(int aiFlag);

    TESForm* GetLoadedForm();

    void ShowCrime(int aiType, float afTime, int aiArg);

    void ClearCrime(int aiType, int aiArg);

    int GetColorKeyCount(KeyX* apKey);

    bool HasKey(KeyX* apKey, int aiArg1, int aiArg2, int aiArg3, int* apCount);

    int GetLOS(RefX* apRef);
};

struct ActivateDataX
{
    int a, b, c, d;
    ActivateDataX(unsigned char acFlags);
};

struct ExtraListX
{

    RefX* GetOwnerRef();

    RefX* GetLinkedRef();

    short GetCount();
};

struct HUDX
{

    char _pad00[0x28];

    TileX* m_pTiles[87];

    char _pad184[0x34];

    RefX* m_pCrosshairReference;

    char _pad1bc[0x60];

    RefX* m_pTargetActor;
};

extern HUDX* xpHUD;

extern RefX* xpPlayer;

extern OSX* xpOS;

extern SoundX xkSound;

extern bool xbFlagBA, xbFlagB9, xbFlagBB, xbFlagC5;

extern char xszName[0x104];

extern char xszLock[0x104];

extern char xszValue[8];

extern char xszWeight[8];

extern const char xszSpace[];

extern TESForm* xpActiA;

extern TESForm* xpActiB;

extern SettingX xsLockBroken, xsLockAlpha, xsLockReq, xsLockLevel, xsOwnerName, xsActTake, xsActTalk, xsActBlocked,
    xsActOpen, xsActSearch, xsActLocked, xsActClose, xsWG, xsVAL, xsHaveKey;

extern SettingX* xsLockLevels[];

extern SettingX* xsActions[];

extern SettingX* xsButtons[];

int __cdecl xGetHUDMode();

bool __cdecl xIsAllowed(RefX* apRef, RefX* apActor, int aiArg1, int aiArg2);

int __cdecl xGetLockLevel(int aiLevel);

int __cdecl xMax(int a, int b);

int __cdecl xMin(int a, int b);

float __cdecl xGetDistance(const PointX& arA, const PointX& arB);

const char* __cdecl xGetFullName(TESForm* apForm);

void* __fastcall xGetContainer(RefX* apRef);

int __fastcall xGetAmmoCount(RefX* apRef);

int __cdecl xGetOpenState(RefX* apRef);

int __cdecl xTraitID(const char* apName);

bool __cdecl xIsGamepad();

bool __fastcall xIsWeapon(TESForm* apForm);

void __cdecl xApplyPerkModifiers(int aeEntry, RefX* apActor, float* apValue);

float __cdecl xGetWeight(TESForm* apForm, bool abHardcore);

bool __fastcall xIsHardcore(RefX* apPlayer);

TileX* __cdecl xGetChild(TileX* apTile, const char* apName);

int __fastcall xGetModelIndex(ModelListX* apList);

void __cdecl xModelA(int a, int b, int c);

void __cdecl xModelB(int a, int b, int c);

int __cdecl xsprintf_s(char* apBuf, unsigned int auiSize, const char* apFormat, ...);

int __cdecl xstrcpy_s(char* apBuf, unsigned int auiSize, const char* apSrc);

int __cdecl xstrcat_s(char* apBuf, unsigned int auiSize, const char* apSrc);

static const char s_szConsoleButton[] = "_xbox_button";
static const char s_lit0[] = "[%s - %s]";
static const char s_lit1[] = "[";
static const char s_lit2[] = "]";
static const char s_lit3[] = "%s %s %s";
static const char s_lit4[] = "%s (%d)";
static const char s_lit5[] = "";
static const char s_lit6[] = "_line_alpha";
static const char s_lit7[] = ")";
static const char s_lit8[] = "_PCButtonText";
static const char s_lit9[] = "%.0f";
static const char s_lit10[] = "%.1f";
static const char s_lit11[] = "--";
static const char s_lit12[] = "button_text";
static const char s_lit13[] = "_y";
extern const char s_litEnd[] = "";

// Updates the HUD activate prompt for apRef: sets name, action, lock, weight/value and button text, and toggles the related tiles.
// @fnv 0x00775a00
bool UpdateActivatePrompt(RefX* apRef, int aiUnused, bool abForce)
{
    NameHolderX* qrUCJDN;
    int qBLsiu;
    RefX* qAXSCg;
    float qbfQdhM;
    float qXMUYT;
    TESForm* qpia;
    TESForm* qJDuOZ;
    int qxQHW;
    TESForm* qfTOqo;
    float qRZyE;
    RefX* qydrGv;
    bool qbdXUOW;
    bool qzYzlc;
    float qYvToq;
    bool qODE;
    float qkPflib;
    int qjThF;
    TESForm* qrBzVM;
    bool qZgNzZy;
    TESForm* qnEqwa;
    ModelListX* qyFp;
    bool qGTHx;
    int qYdAnhh;
    bool qxDeKK;
    TESForm* qidnYUK;
    bool qIpA;
    float qZWI;
    bool qQMZREG;
    TESForm* qAhbO;
    int qOPw;
    LockX* qYvz;
    int qYePyBl;
    RefX* qtOMjSX;
    RefX* qqtISP;
    bool qQGWBE;
    TESForm* qxWmVch;
    bool qArxcFu;
    if (!xpHUD || !xpPlayer)
        return false;
    if (apRef == xpPlayer)
        apRef = 0;
    if (!abForce && apRef == xpHUD->m_pCrosshairReference)
    {
        if (xbFlagBA && xbFlagB9)
        {
            xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
            xpHUD->m_pTiles[51]->Set(0xff4, 2);
        }
        else if (!apRef || (apRef->IsActor() && !apRef->IsHostileTo(xpPlayer)))
        {
            if (!apRef)
            {
                xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
                xpHUD->m_pTiles[51]->Set(0xff4, 1);
            }
            xbFlagBB = false;
            if (xGetHUDMode() == 2)
                xpHUD->m_pTiles[62]->Set(0xfa3, 1);
        }
        return false;
    }
    qydrGv = apRef;
    qGTHx = apRef ? apRef->IsActor() : false;
    qidnYUK = apRef ? apRef->GetBaseObject() : 0;
    qIpA = apRef ? apRef->GetBaseObject()->GetFormType() == 0x17 : false;
    if (apRef && apRef != xpHUD->m_pCrosshairReference)
    {
        if (qGTHx && xpPlayer->IsSneaking())
        {
            if (!qydrGv->IsPlayerTeammate())
            {
                xpPlayer->ShowCrime(0xc, 10.0f, 0);
                xkSound.Play();
            }
        }
        else if (!qGTHx)
        {
            LockX* pLockInner = apRef->GetLock();
            if (qIpA)
            {
                if (!qidnYUK->IsTerminalUsable(apRef) && apRef->GetOwner())
                {
                    xpPlayer->ShowCrime(0xb, 10.0f, 0);
                    xkSound.Play();
                }
            }
            else if (apRef->GetBaseObject()->GetFormType() == 0x1b && apRef->GetOwner())
            {
                int qSVM = apRef->GetItemCount(0, 1);
                if (qSVM > 0 && pLockInner && pLockInner->IsLocked())
                {
                    if (!pLockInner->pKey || xpPlayer->GetColorKeyCount(pLockInner->pKey) <= 0)
                    {
                        xpPlayer->ShowCrime(0xb, 10.0f, 0);
                        xkSound.Play();
                    }
                }
            }
            else if (pLockInner && pLockInner->IsLocked() && apRef->GetOwner())
            {
                if (!pLockInner->pKey || xpPlayer->GetColorKeyCount(pLockInner->pKey) <= 0)
                {
                    xpPlayer->ShowCrime(0xb, 10.0f, 0);
                    xkSound.Play();
                }
            }
        }
        else
        {
            xpPlayer->ClearCrime(0xc, 0);
            xpPlayer->ClearCrime(0xb, 0);
        }
    }
    else
    {
        xpPlayer->ClearCrime(0xc, 0);
        xpPlayer->ClearCrime(0xb, 0);
    }
    if (!apRef || !abForce)
        xpHUD->m_pCrosshairReference = apRef;
    if ((!abForce && !apRef) || !apRef || (apRef->IsDisabled() && !qGTHx))
    {
        xpHUD->m_pTiles[29]->Set(0xfa3, 0);
        xpHUD->m_pTiles[32]->Set(0xfa3, 0);
        xpHUD->m_pTiles[33]->Set(0xfa3, 0);
        xpHUD->m_pTiles[34]->Set(0xfa3, 0);
        xpHUD->m_pTiles[35]->Set(0xfa3, 0);
        xpHUD->m_pTiles[36]->Set(0xfa3, 0);
        xpHUD->m_pTiles[37]->Set(0xfa3, 0);
        xpHUD->m_pTiles[38]->Set(0xfa3, 0);
        xpHUD->m_pTiles[39]->Set(0xfa3, 0);
        if (!xbFlagBA)
            xpHUD->m_pTiles[51]->Set(0xff4, 1);
        xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
        xbFlagBB = false;
        if (xGetHUDMode() == 2)
            xpHUD->m_pTiles[62]->Set(0xfa3, 1);
        return true;
    }
    qYdAnhh = 0;
    qjThF = apRef->GetActivateType();
    if ((apRef && qjThF == 5) || qjThF == 3)
    {
        int iResult = 0;
        ActivateDataX kData(0xff);
        if (!apRef->CanActivate(xpPlayer->GetPos(), 1, 1, &kData, &iResult, 1))
            return false;
    }
    qxWmVch = 0;
    qfTOqo = 0;
    qrBzVM = 0;
    qbdXUOW = qydrGv && xpPlayer->GetDetection(qydrGv) && xpPlayer->GetDetection(qydrGv)->bDetected;
    if (qjThF || qbdXUOW)
    {
        if (apRef->IsTalkable() && (!qGTHx || !apRef->IsPlayerTeammate()))
        {
            xpHUD->m_pTiles[51]->Set(0xff4, 2);
            xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1005), true);
        }
        else if (qbdXUOW)
        {
            xpHUD->m_pTiles[51]->Set(0xff4, 2);
            xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
        }
        else if (!qGTHx || !apRef->IsCommandable())
        {
            xpHUD->m_pTiles[51]->Set(0xff4, 1);
            xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1005), true);
        }
        else
        {
            xpHUD->m_pTiles[51]->Set(0xff4, 1);
            xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
        }
    }
    else
    {
        xpHUD->m_pTiles[51]->Set(0xff4, 1);
        xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
    }
    qOPw = apRef->GetBaseObject()->GetFormType();
    switch (qOPw)
    {
    case 0x20:
    case 0x21:
    case 0x25:
        xpHUD->m_pTiles[51]->Set(0xff4, 1);
        xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
        xpHUD->m_pTiles[32]->Set(0xfa3, 0);
        xpHUD->m_pTiles[29]->Set(0xfa3, 0);
        xpHUD->m_pTiles[21]->Set(0xfa3, 0);
        xpHUD->m_pTiles[22]->Set(0xfa3, 0);
        xpHUD->m_pTiles[23]->Set(0xfa3, 0);
        xpHUD->m_pTiles[33]->Set(0xfa3, 0);
        xpHUD->m_pTiles[34]->Set(0xfa3, 0);
        xpHUD->m_pTiles[35]->Set(0xfa3, 0);
        xpHUD->m_pTiles[36]->Set(0xfa3, 0);
        xpHUD->m_pTiles[37]->Set(0xfa3, 0);
        xpHUD->m_pTiles[38]->Set(0xfa3, 0);
        xpHUD->m_pTiles[39]->Set(0xfa3, 0);
        return true;
        break;
    case 0x33:
        if (apRef->GetEquippedEntry() && apRef->GetEquippedEntry()->GetType()->GetFormType() != 0x1f)
            break;
        if (apRef->GetFormType() == 0x3d)
        {
            xpHUD->m_pTiles[51]->Set(0xff4, 1);
            xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
            xpHUD->m_pTiles[32]->Set(0xfa3, 0);
            xpHUD->m_pTiles[29]->Set(0xfa3, 0);
            xpHUD->m_pTiles[21]->Set(0xfa3, 0);
            xpHUD->m_pTiles[22]->Set(0xfa3, 0);
            xpHUD->m_pTiles[23]->Set(0xfa3, 0);
            xpHUD->m_pTiles[33]->Set(0xfa3, 0);
            xpHUD->m_pTiles[34]->Set(0xfa3, 0);
            xpHUD->m_pTiles[35]->Set(0xfa3, 0);
            xpHUD->m_pTiles[36]->Set(0xfa3, 0);
            xpHUD->m_pTiles[37]->Set(0xfa3, 0);
            xpHUD->m_pTiles[38]->Set(0xfa3, 0);
            xpHUD->m_pTiles[39]->Set(0xfa3, 0);
            return true;
            break;
        }
    case 0x1f:
    case 0x23:
    case 0x2f:
    case 0x67:
        qYdAnhh |= 0xfc;
        break;
    case 0x28:
        qxWmVch = apRef->GetBaseObject();
        if (qxWmVch->IsPlayable())
            qYdAnhh |= 0xfc;
        break;
    case 0x18:
        qfTOqo = apRef->GetBaseObject();
        qYdAnhh |= 0xfc;
        break;
    case 0x29:
        qrBzVM = apRef->GetBaseObject();
        if (qrBzVM->GetFlag())
            qYdAnhh |= 0xfc;
        break;
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1b:
    case 0x1c:
    case 0x27:
    case 0x2a:
    case 0x2b:
        break;
    case 0x1e:
        xpHUD->m_pTiles[51]->Set(0xff4, 1);
        xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1004), true);
        if (!apRef->GetBaseObject()->IsQuestItem())
            return true;
        qYdAnhh |= 0xfc;
        break;
    default:
        xpHUD->m_pTiles[51]->Set(0xff4, 1);
    }
    qrUCJDN = apRef->GetNameHolder();
    qYvz = apRef->GetLock();
    qpia = apRef->GetBaseObject();
    qJDuOZ = apRef->GetBaseObject();
    qxQHW = 0;
    qZgNzZy = false;
    if (qOPw != 0x1c && qOPw != 0x1b)
    {
        qZgNzZy = true;
    }
    else if (qOPw == 0x1c && xIsAllowed(apRef, xpPlayer, 0, 1))
    {
        qZgNzZy = true;
    }
    else if (qOPw == 0x1b)
    {
        if (!qYvz || !qYvz->IsLocked() || (qYvz->pKey && xpPlayer->HasKey(qYvz->pKey, 0, 1, 0, &qxQHW)))
            qZgNzZy = true;
    }
    qYePyBl = qIpA ? qidnYUK->GetTerminalLevel(apRef) : 0;
    qzYzlc = xpPlayer->GetLOS(apRef) == 2 || xpPlayer->GetLOS(apRef) == 3 || xpPlayer->GetLOS(apRef) == 4;
    if ((qIpA && qzYzlc) || apRef->IsOff() || (qYvz && qYvz->IsLocked()))
    {
        int qpydTG = 0;
        if (qIpA)
            qpydTG = qYePyBl;
        else
            qpydTG = xGetLockLevel(apRef->GetLockLevel());
        qpydTG = xMin(xMax(qpydTG, 0), 5);
        int qOHwfb = qpydTG;
        int qQZbH;
        bool qpqRa = qYvz && qYvz->pKey && xpPlayer->HasKey(qYvz->pKey, 0, 1, 0, &qQZbH);
        if (qYvz && qYvz->MeetsMinimumLockLevel())
        {
            xpHUD->m_pTiles[33]->Set(0xfc4, xsLockBroken.Get(), true);
            xpHUD->m_pTiles[33]->Set(0xfa9, *xsLockAlpha.Float() * 255.0, true);
        }
        else if (apRef->IsOff())
        {
            xpHUD->m_pTiles[33]->Set(0xfc4, xsLockReq.Get(), true);
            xpHUD->m_pTiles[33]->Set(0xfa9, *xsLockAlpha.Float() * 255.0, true);
        }
        else if (((qOPw == 0x1c || qOPw == 0x1b) && (!qZgNzZy || qpqRa)) || qOPw == 0x17)
        {
            if (qpqRa)
            {
                xsprintf_s(xszLock, 0x104, s_lit0, xsLockLevel.Get(), xsHaveKey.Get());
                xpHUD->m_pTiles[33]->Set(0xfc4, xszLock, true);
            }
            else if (qOHwfb == 5)
            {
                xstrcpy_s(xszLock, 0x104, s_lit1);
                xstrcat_s(xszLock, 0x104, xsLockLevels[qOHwfb]->Get());
                xstrcat_s(xszLock, 0x104, s_lit2);
                xpHUD->m_pTiles[33]->Set(0xfc4, xszLock, true);
            }
            else
            {
                xsprintf_s(xszLock, 0x104, s_lit0, xsLockLevel.Get(), xsLockLevels[qOHwfb]->Get());
                xpHUD->m_pTiles[33]->Set(0xfc4, xszLock, true);
            }
            xpHUD->m_pTiles[33]->Set(0xfa9, *xsLockAlpha.Float() * 255.0, true);
        }
        else
        {
            xpHUD->m_pTiles[33]->Set(0xfa9, 0);
        }
    }
    else
    {
        xpHUD->m_pTiles[33]->Set(0xfa9, 0);
    }
    qArxcFu = false;
    qtOMjSX = apRef->GetExtraList()->GetOwnerRef();
    if (qtOMjSX && xGetContainer(qtOMjSX) && qtOMjSX->GetItemCount(0, 0) <= 0)
        qArxcFu = true;
    qAXSCg = apRef->GetExtraList()->GetLinkedRef();
    if (!qAXSCg && ((xGetContainer(apRef) && apRef->GetItemCount(0, 0) <= 0) || qArxcFu) &&
        (!qGTHx || apRef->IsDead(true)))
    {
        xpHUD->m_pTiles[34]->Set(0xfa9, *xsLockAlpha.Float() * 255.0, true);
    }
    else
    {
        xpHUD->m_pTiles[34]->Set(0xfa9, 0);
    }
    qYvToq = xpPlayer->GetDistanceScale(0) * 57.2957763671875;
    qZWI = 0.0f;
    if (xpHUD->m_pTargetActor)
        qZWI = xGetDistance(*xpPlayer->GetPos(), *xpHUD->m_pTargetActor->GetPos());
    qQMZREG = xpHUD->m_pTargetActor && !xpHUD->m_pTargetActor->IsDead(false) && !xpHUD->m_pTargetActor->IsDisabled() &&
              xbFlagC5 && xpHUD->m_pTargetActor == qydrGv;
    if (apRef)
    {
        RefX* pCreature = apRef->IsCreature() ? apRef : 0;
        if (pCreature && pCreature->GetEquippedEntry())
        {
            xstrcpy_s(xszName, 0x104, xGetFullName(pCreature->GetEquippedEntry()->GetType()));
        }
        else if (pCreature && pCreature->GetLoadedForm())
        {
            TESForm* pWeapon = pCreature->GetLoadedForm();
            if (pWeapon->GetTemplate(0) && pWeapon->GetTemplate(0)->GetLeveled())
                pWeapon = pWeapon->GetTemplate(0)->GetLeveled();
            xstrcpy_s(xszName, 0x104, xGetFullName(pWeapon));
        }
        else
        {
            xstrcpy_s(xszName, 0x104, apRef->GetFullName());
        }
    }
    else
    {
        xszName[0] = 0;
    }
    qQGWBE = xpPlayer->GetSkillPoints() > 0;
    if (xszName[0])
    {
        if (qrUCJDN)
        {
            StringX qhQRuW;
            qrUCJDN->GetName(qhQRuW);
            char qWHpEvQ[0x104];
            xsprintf_s(qWHpEvQ, 0x104, s_lit3, xszName, xsOwnerName.Get(), qhQRuW.c_str());
            xpHUD->m_pTiles[32]->Set(0xfc4, qWHpEvQ, true);
            qYdAnhh |= 4;
        }
        else if ((!qGTHx || !(qydrGv == xpHUD->m_pTargetActor || qydrGv->IsHostileTo(xpPlayer)) || !qQGWBE ||
                  qydrGv->IsDead(false)) &&
                 !qQMZREG)
        {
            bool bShow = true;
            if (apRef->GetExtraList()->GetCount() == 1)
            {
                if (qGTHx)
                {
                    xpHUD->m_pTiles[32]->Set(0xfc4, xszName, true);
                }
                else if ((qrBzVM && qrBzVM->GetFlag()) || (qxWmVch && qxWmVch->IsPlayable()) || (!qxWmVch && !qrBzVM))
                {
                    if (apRef->GetBaseObject()->GetFormType() == 0x29 &&
                        ((AmmoX*)apRef->GetBaseObject())->kSub.GetFormType() > 1)
                    {
                        char szCount[0x104];
                        xsprintf_s(szCount, 0x104, s_lit4, xszName, xGetAmmoCount(apRef));
                        xpHUD->m_pTiles[32]->Set(0xfc4, szCount, true);
                    }
                    else
                    {
                        xpHUD->m_pTiles[32]->Set(0xfc4, xszName, true);
                    }
                }
                else
                {
                    bShow = false;
                }
            }
            else
            {
                char szCount[0x104];
                xsprintf_s(szCount, 0x104, s_lit4, xszName, apRef->GetExtraList()->GetCount());
                xpHUD->m_pTiles[32]->Set(0xfc4, szCount, true);
            }
            xpHUD->m_pTiles[21]->Set(0xfa3, 0);
            xpHUD->m_pTiles[22]->Set(0xfa3, 0);
            xpHUD->m_pTiles[23]->Set(0xfa3, 0);
            if (bShow)
                qYdAnhh |= 4;
        }
    }
    else
    {
        xpHUD->m_pTiles[32]->Set(0xfc4, xszSpace, true);
    }
    qBLsiu = apRef->GetActivateType();
    qxDeKK = false;
    if (qGTHx)
    {
        PerceivedListX* pNode = xpPlayer->GetPerceivedActors();
        while (pNode && !pNode->IsEmpty())
        {
            PerceivedX* pData = pNode->GetItem();
            if (pData->pActor == qydrGv && pData->bVisible)
            {
                qxDeKK = true;
                break;
            }
            pNode = pNode->GetNext();
        }
    }
    if (apRef && !qQMZREG)
    {
        if (!(qBLsiu == 7 && qGTHx && (qxDeKK || qydrGv == xpHUD->m_pTargetActor || qydrGv->IsHostileTo(xpPlayer)) &&
              (qydrGv->IsInCombat(false) || qydrGv->IsUnconscious() || qxDeKK)) &&
            !apRef->IsDisabled())
        {
            ExtraNameX* pExtraName = apRef->GetExtraData(0x53);
            StringX kName(s_lit5);
            if (pExtraName)
                kName = pExtraName->kName;
            if (kName.Length() == 0)
            {
                TESObjectACTI* pActi = dynamic_cast<TESObjectACTI*>(apRef->GetBaseObject());
                if (pActi)
                    kName = pActi->GetActivateText();
            }
            if (kName.Length() > 0)
            {
                xpHUD->m_pTiles[29]->Set(0xfc4, kName.c_str(), true);
                xpHUD->m_pTiles[32]->Set(0xfc4, s_lit5, true);
                qYdAnhh |= 2;
            }
            else if (qBLsiu == 1 && apRef->IsTalkable())
            {
                if (qGTHx && qydrGv->IsPlayerTeammate())
                {
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActions[7]->Get(), true);
                }
                else if (qOPw == 0x2a)
                {
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActTalk.Get(), true);
                }
                else if (qOPw == 0x2b)
                {
                    if (qydrGv->GetActorBase()->kAI.IsEssential())
                        xpHUD->m_pTiles[29]->Set(0xfc4, xsActTalk.Get(), true);
                    else
                        xpHUD->m_pTiles[29]->Set(0xfc4, xsActBlocked.Get(), true);
                }
                else
                {
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActBlocked.Get(), true);
                }
                qYdAnhh |= 2;
            }
            else if (apRef->GetBaseObject() == xpActiA || apRef->GetBaseObject() == xpActiB ||
                     (qBLsiu == 2 && (qOPw == 0x2a || qOPw == 0x2b)))
            {
                xpHUD->m_pTiles[29]->Set(0xfc4, xsActOpen.Get(), true);
                qYdAnhh |= 2;
            }
            else if (qBLsiu == 8 && qOPw == 0x1c && !apRef->IsOff())
            {
                bool bOpen = xGetOpenState(apRef) == 1 || xGetOpenState(apRef) == 2;
                if (qYvz && qYvz->IsLocked() && !apRef->CanBeUsed(xpPlayer, true) && !qZgNzZy)
                {
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActLocked.Get(), true);
                }
                else
                {
                    xpHUD->m_pTiles[29]->Set(0xfc4, bOpen ? xsActClose.Get() : xsActions[qBLsiu]->Get(), true);
                }
                qYdAnhh |= 2;
            }
            else if (qBLsiu == 4 && qOPw == 0x2b)
            {
                qYdAnhh &= ~3;
            }
            else if (qBLsiu == 6)
            {
                xpHUD->m_pTiles[29]->Set(0xfc4, xsActions[1]->Get(), true);
                qYdAnhh |= 2;
            }
            else if (qBLsiu != 0 && qBLsiu < 0x14 && !apRef->IsOff())
            {
                if (!(qBLsiu == 1 && qGTHx && xpPlayer->IsSneaking() && qydrGv->IsRestrained()))
                {
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActions[qBLsiu]->Get(), true);
                    qYdAnhh |= 2;
                }
            }
            else if (apRef->IsCreature() && apRef->GetActorBase()->GetHealth() != 0.0)
            {
                if (!apRef->HasRefFlag(0x200))
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActSearch.Get(), true);
                else
                    xpHUD->m_pTiles[29]->Set(0xfc4, xsActions[1]->Get(), true);
                qYdAnhh |= 2;
                xpHUD->m_pTiles[51]->Set(0xff4, 1);
                xpHUD->m_pTiles[51]->Set(0xfcc, xpHUD->m_pTiles[51]->GetString(0x1005), true);
            }
            xpHUD->m_pTiles[29]->Set(xTraitID(s_lit6), *xsLockAlpha.Float() * 255.0, true);
            if (!xIsGamepad())
            {
                unsigned char cButton = xpOS->GetInput()->GetButton(5, 0);
                if (cButton < 0xeeu && xsButtons[cButton])
                {
                    char szButton[0x20];
                    xstrcpy_s(szButton, 0x20, xsButtons[cButton]->Get());
                    xstrcat_s(szButton, 0x20, s_lit7);
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_lit8), szButton, true);
                }
                else
                {
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_lit8), s_lit5, true);
                }
            }
            else
            {
                unsigned char cPadButton = xpOS->GetInput()->GetButton(5, 3);
                switch (cPadButton)
                {
                case 0x10:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0xd);
                    break;
                case 0x11:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0xe);
                    break;
                case 0xf:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0xf);
                    break;
                case 0xe:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0x10);
                    break;
                case 8:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0x11);
                    break;
                case 9:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0x12);
                    break;
                case 0xa:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 9);
                    break;
                case 0xb:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0xa);
                    break;
                case 0xc:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0xb);
                    break;
                case 0xd:
                    xpHUD->m_pTiles[29]->Set(xTraitID(s_szConsoleButton), 0xc);
                    break;
                }
            }
        }
    }
    qqtISP = apRef->IsCreature() ? apRef : 0;
    qODE = qqtISP && qqtISP->GetEquippedEntry();
    qnEqwa = qqtISP ? qqtISP->GetLoadedForm() : 0;
    qAhbO = qnEqwa && xIsWeapon(qnEqwa) ? qnEqwa : 0;
    EntryX qsSDDgz(qODE ? *qqtISP->GetEquippedEntry() : EntryX(qAhbO ? qAhbO : apRef->GetBaseObject(), 0));
    if (!qsSDDgz.pList)
        qsSDDgz.pList = new ExtraListListX();
    qsSDDgz.pList->AddHead(apRef->GetExtraList());
    qyFp = 0;
    switch (apRef->GetBaseObject()->GetFormType())
    {
    case 0x15:
        qyFp = apRef->GetBaseObject()->GetModelList();
        break;
    case 0x23:
        qyFp = apRef->GetBaseObject()->GetModelList();
        break;
    }
    if (qyFp)
    {
        int qSVM = qyFp->GetCount();
        int qOFvKuu = xGetModelIndex(qyFp);
        int qmgeiw = 0;
        int qeJKl = 0x23;
        int qGfbX = 0x24;
        xModelA(qOFvKuu, qeJKl, qGfbX);
        qeJKl = qeJKl == 0x23 ? 0x25 : qeJKl;
        qGfbX = qGfbX == 0x24 ? 0x26 : qGfbX;
        qmgeiw++;
        xModelB(qSVM, qeJKl, qGfbX);
        qeJKl = qeJKl == 0x23 ? 0x25 : qeJKl;
        qGfbX = qGfbX == 0x24 ? 0x26 : qGfbX;
        qmgeiw++;
        qYdAnhh |= 0xfc;
    }
    else
    {
        float fValue = qsSDDgz.GetValue();
        if (fValue > 0.0)
        {
            if (fValue >= 1.0)
                xsprintf_s(xszValue, 8, s_lit9, fValue);
            else
                xsprintf_s(xszValue, 8, s_lit10, fValue);
        }
        else
        {
            xstrcpy_s(xszValue, 8, s_lit11);
        }
        float fWeight = 0.0f;
        if (qsSDDgz.GetType()->GetFormType() == 0x28)
        {
            WeaponX* pType = (WeaponX*)qsSDDgz.GetType();
            fWeight = pType->GetWeight(qsSDDgz.HasMod(4));
            if (fWeight >= 10.0)
            {
                float fMult = 1.0f;
                xApplyPerkModifiers(0x49, xpPlayer, &fMult);
                fWeight = fWeight * fMult;
            }
        }
        else
        {
            fWeight = xGetWeight(qsSDDgz.GetType(), xIsHardcore(xpPlayer));
        }
        if (fWeight > 0.0)
            xsprintf_s(xszWeight, 8, s_lit10, fWeight);
        else
            xstrcpy_s(xszWeight, 8, s_lit11);
        xpHUD->m_pTiles[35]->Set(0xfc4, xszWeight, true);
        xpHUD->m_pTiles[36]->Set(0xfc4, xsWG.Get(), true);
        xpHUD->m_pTiles[37]->Set(0xfc4, xszValue, true);
        xpHUD->m_pTiles[38]->Set(0xfc4, xsVAL.Get(), true);
    }
    static TileX* s_pButtonText = xGetChild(xpHUD->m_pTiles[68], s_lit12);
    if ((apRef->IsTalkable() && (!qGTHx || !apRef->IsPlayerTeammate())) ||
        (qGTHx && (apRef->IsHostileTo(xpPlayer) || qxDeKK)))
    {
        xpHUD->m_pTiles[29]->Set(0xff4, 2);
        xpHUD->m_pTiles[30]->Set(0xff4, 2);
        xpHUD->m_pTiles[31]->Set(0xff4, 2);
        xpHUD->m_pTiles[32]->Set(0xff4, 2);
        xpHUD->m_pTiles[33]->Set(0xff4, 2);
        xpHUD->m_pTiles[34]->Set(0xff4, 2);
        xpHUD->m_pTiles[35]->Set(0xff4, 2);
        xpHUD->m_pTiles[36]->Set(0xff4, 2);
        xpHUD->m_pTiles[37]->Set(0xff4, 2);
        xpHUD->m_pTiles[38]->Set(0xff4, 2);
        xpHUD->m_pTiles[39]->Set(0xff4, 2);
    }
    else
    {
        xpHUD->m_pTiles[29]->Set(0xff4, 1);
        xpHUD->m_pTiles[30]->Set(0xff4, 1);
        xpHUD->m_pTiles[31]->Set(0xff4, 1);
        xpHUD->m_pTiles[32]->Set(0xff4, 1);
        xpHUD->m_pTiles[33]->Set(0xff4, 1);
        xpHUD->m_pTiles[34]->Set(0xff4, 1);
        xpHUD->m_pTiles[35]->Set(0xff4, 1);
        xpHUD->m_pTiles[36]->Set(0xff4, 1);
        xpHUD->m_pTiles[37]->Set(0xff4, 1);
        xpHUD->m_pTiles[38]->Set(0xff4, 1);
        xpHUD->m_pTiles[39]->Set(0xff4, 1);
    }
    s_pButtonText->Refresh(8);
    qbfQdhM = xpHUD->m_pTiles[32]->GetFloat(0x100c);
    PointX qrEZrs =
        FontX::Instance()->GetSize(xpHUD->m_pTiles[32]->GetString(0xfc4), (int)xpHUD->m_pTiles[32]->GetFloat(0xfb9),
                                   xpHUD->m_pTiles[32]->GetFloat(0xfba), 0);
    qRZyE = qrEZrs.y;
    qXMUYT = xpHUD->m_pTiles[29]->GetFloat(0x1004);
    qkPflib = qXMUYT - (qRZyE - qbfQdhM);
    xpHUD->m_pTiles[29]->Set(xTraitID(s_lit13), qkPflib, true);
    xpHUD->m_pTiles[32]->Set(0xfa2, xpHUD->m_pTiles[29]->GetFloat(0xfb0) + qkPflib, true);
    xpHUD->m_pTiles[69]->Set(
        0xfa2, xpHUD->m_pTiles[68]->GetFloat(0xfa2) + qkPflib - xpHUD->m_pTiles[69]->GetFloat(0xfb0) - 50.0, true);
    xpHUD->m_pTiles[29]->Set(0xfa3, qYdAnhh & 2);
    xpHUD->m_pTiles[32]->Set(0xfa3, (qYdAnhh & 4) > 0);
    if (qYdAnhh & 6)
    {
        xpHUD->m_pTiles[21]->Set(0xfa3, 0);
        xpHUD->m_pTiles[22]->Set(0xfa3, 0);
        xpHUD->m_pTiles[23]->Set(0xfa3, 0);
    }
    xpHUD->m_pTiles[33]->Set(0xfa3, (qYdAnhh & 4) > 0);
    xpHUD->m_pTiles[34]->Set(0xfa3, (qYdAnhh & 4) > 0 && xpHUD->m_pTiles[33]->GetFloat(0xfa9) == 0.0);
    xpHUD->m_pTiles[35]->Set(0xfa3, (qYdAnhh & 8) > 0);
    xpHUD->m_pTiles[36]->Set(0xfa3, (qYdAnhh & 0x10) > 0);
    xpHUD->m_pTiles[37]->Set(0xfa3, (qYdAnhh & 0x20) > 0);
    xpHUD->m_pTiles[38]->Set(0xfa3, (qYdAnhh & 0x40) > 0);
    xpHUD->m_pTiles[39]->Set(0xfa3, (qYdAnhh & 0x80) > 0);
    return true;
}

struct CamRect
{
    float l, r, t, b;
    CamRect(float al, float ar, float at, float ab);
};
struct CamFrustum
{
    float l, r, t, b, n, f;
    bool ortho;
    CamFrustum(bool abOrtho);
};
struct CamPoint3
{
    float x, y, z;
    CamPoint3(float ax, float ay, float az);
};
struct CamUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    int unk08;
    CamUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct CamObj
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
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    CamObj();
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
    void SetViewPort(const CamRect& rect);
    void SetLODAdjust(float f);
    void UpdateViewFrustum(const CamFrustum& frustum);
    void LookAt(const CamPoint3& a, const CamPoint3& b);
    void SetScale(float f);
    void Update(CamUpdateData& data);
};
struct FovSource
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
    virtual float GetFov();
};
struct FloatSetting
{
    float* Float();
};
FovSource* FUN_0045c670();
int FUN_004dc200();
int FUN_004dc1f0();
float FUN_0057dd70(float);
extern bool g_011f9426;
extern int g_011f9434;
extern CamRect g_011ad840;
extern FloatSetting g_01203144;
extern FloatSetting g_01203150;

struct CamBuilder
{
    CamObj* FUN_0077ee50();
};

// Allocates a CamObj, sets its viewport, FOV-derived frustum, LOD adjust, look-at, scale and updates it, then returns it.
// @fnv 0x0077ee50
CamObj* CamBuilder::FUN_0077ee50()
{
    CamObj* pCamera = new CamObj;
    CamRect port2(0.0f, 1.0f, 1.0f, 0.0f);
    if (g_011f9426)
    {
        port2 = g_011ad840;
    }
    pCamera->SetViewPort(port2);
    CamFrustum _frustum(false);
    _frustum.f = FUN_0045c670()->GetFov();
    _frustum.n = *g_01203144.Float();
    pCamera->SetLODAdjust(_frustum.f / _frustum.n);
    float fAspect2 = (double)(g_011f9426 ? g_011f9434 : FUN_004dc200()) / (double)FUN_004dc1f0();
    float fScale = 0.75f;
    float fAngle2 = *g_01203150.Float() * 0.01745329238474369 * 0.15000000596046448;
    _frustum.l = -FUN_0057dd70(fAngle2) * fScale;
    _frustum.r = FUN_0057dd70(fAngle2) * fScale;
    _frustum.b = -FUN_0057dd70(fAngle2) * fAspect2 * fScale;
    _frustum.t = FUN_0057dd70(fAngle2) * fAspect2 * fScale;
    _frustum.ortho = false;
    pCamera->UpdateViewFrustum(_frustum);
    pCamera->LookAt(CamPoint3(0.0f, 0.0f, 1.0f), CamPoint3(0.0f, 0.0f, 1.0f));
    pCamera->SetScale(1.0f);
    CamUpdateData updateData3(0.0f, false, false);
    pCamera->Update(updateData3);
    return pCamera;
}

struct FUN_0077f2f0_vt55
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
    virtual void v55(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    void F450f90(int a);
    void FA59c60(struct FUN_0077f2f0_loc* loc);
};

struct FUN_0077f2f0_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    unsigned int F48cee0();
};

struct FUN_0077f2f0_loc
{
    int m_00;
    int m_04;
    int m_08;
    void Init(float f, int a, int b);
};

struct FUN_0077f2f0_mgr
{
    FUN_0077f2f0_vt55* GetA();
    int GetB();
};

extern int DAT_011d96c0;
extern char DAT_011d9770;
extern void* DAT_011c3b3c;

void FUN_0077f270();

// @fnv 0x0077f2f0
void FUN_0077f2f0(FUN_0077f2f0_obj* pObject)
{
    FUN_0077f2f0_vt55* vt;
    FUN_0077f2f0_loc loc;
    if (DAT_011d96c0 != 0)
    {
        if (((FUN_0077f2f0_mgr*)&DAT_011d9770)->GetA() != 0)
        {
            FUN_0077f270();
            if (pObject != 0)
            {
                if (pObject->F48cee0() > 0)
                {
                    vt = ((FUN_0077f2f0_mgr*)&DAT_011d9770)->GetA();
                    vt->v55(((FUN_0077f2f0_mgr*)DAT_011c3b3c)->GetB(), pObject->v5(), 0, 1, 0, 0, 0, 1);
                    ((FUN_0077f2f0_mgr*)&DAT_011d9770)->GetA()->F450f90(1);
                    loc.Init(0.0f, 0, 0);
                    ((FUN_0077f2f0_mgr*)&DAT_011d9770)->GetA()->FA59c60(&loc);
                }
            }
        }
    }
}

struct NiNode_st;
struct GlobalObject_00633c90
{
    void* m_p;
    operator NiNode_st*() const;
    GlobalObject_00633c90& operator=(NiNode_st* p);
};
extern GlobalObject_00633c90 g_011d9770;
extern GlobalObject_00633c90 g_011d975c;
extern int g_011d96bc;

class ShadowSceneNode
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
    virtual void SetNode(NiNode_st* p);
};
ShadowSceneNode* __cdecl FUN_00450b80(int);

struct OwnedObj
{
    virtual ~OwnedObj();
};
struct PmeAccess
{
    OwnedObj* GetOwned();
};

struct MsgItem
{
    int unk00;
};
struct HudList
{
    MsgItem* m_item;
    HudList* m_pkNext;
    ~HudList();
    MsgItem*& GetItem();
    void RemoveHead();
};
struct HudSubtitles
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~HudSubtitles();
};
struct HudSound
{
    int unk00;
    int unk04;
    int unk08;
    ~HudSound();
};
struct HudWheel
{
    int unk00;
    ~HudWheel();
};

struct HudMenuBase
{
    virtual ~HudMenuBase();
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

struct FUN_0076be30 : public HudMenuBase
{
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
    HudList m_kMessageList;
    int unk194;
    HudSubtitles m_kSubtitleArray;
    int unk1A8;
    HudSound m_kTargetDisplayData;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    HudWheel m_kMenuData;
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
    HudList m_kQuestObjectives;
    int unk260;
    HudList m_kXPUpdates;
    HudList m_kRadiationUpdates;
    int unk274;
    virtual ~FUN_0076be30();
};

// Releases the owned HUD object, resets the node and HUD globals, deletes all queued message items, and clears HUDMainMenu_pme.
// @fnv 0x0076be30
FUN_0076be30::~FUN_0076be30()
{
    delete ((PmeAccess*)HUDMainMenu_pme)->GetOwned();
    FUN_00450b80(1)->SetNode(g_011d9770);
    g_011d9770 = 0;
    g_011d975c = 0;
    g_011d96bc = 0;
    while (m_kMessageList.GetItem())
    {
        MsgItem* pItem = m_kMessageList.GetItem();
        delete pItem;
        m_kMessageList.RemoveHead();
    }
    HUDMainMenu_pme = 0;
}

struct ActorStand
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
    ActorValueOwner avOwner;
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct BaseProcess
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual void vfunc56();
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc60();
    virtual void vfunc61();
    virtual void vfunc62();
    virtual void vfunc63();
    virtual void vfunc64();
    virtual void vfunc65();
    virtual void vfunc66();
    virtual void vfunc67();
    virtual void vfunc68();
    virtual void vfunc69();
    virtual void vfunc70();
    virtual void vfunc71();
    virtual void vfunc72();
    virtual void vfunc73();
    virtual void vfunc74();
    virtual void vfunc75();
    virtual void vfunc76();
    virtual void vfunc77();
    virtual void vfunc78();
    virtual void vfunc79();
    virtual void vfunc80();
    virtual void vfunc81();
    virtual TESObjectREFR_GetFlags_Helper* GetRef();
};
struct MobileObject
{
    BaseProcess* GetCurrentAIProcess() const;
};
extern unsigned int DAT_011ca278;
float __cdecl FUN_00404010(float, float);
void __cdecl ApplyPerkModifiers(int, Actor*, ...);
// Returns the actor's value 76 clamped to at least zero, adjusted by perk modifiers 58 and 56, or 0.0 if either argument is null.
// @fnv 0x007700f0
float __cdecl GetActorValueWithPerkModifiers(MobileObject* pMobileObject, Actor* pActor)
{
    if (pMobileObject == 0 || pActor == 0)
    {
        return 0.0f;
    }
    float baseValue = FUN_00404010(((ActorStand*)pActor)->avOwner.GetActorValue(76), 0.0f);
    BaseProcess* proc = pMobileObject->GetCurrentAIProcess();
    TESObjectREFR_GetFlags_Helper* target = proc->GetRef();
    unsigned int result;
    if (target != 0)
    {
        result = target->CallGetFlags();
    }
    else
    {
        result = DAT_011ca278;
    }
    unsigned int modFlags = result;
    float fPenalty = 0.0f;
    ApplyPerkModifiers(58, (Actor*)pMobileObject, modFlags, pActor, &fPenalty);
    float fAdd = 0.0f;
    ApplyPerkModifiers(56, pActor, (Actor*)pMobileObject, modFlags, &fAdd);
    baseValue = baseValue - fPenalty + fAdd;
    baseValue = FUN_00404010(0.0f, baseValue);
    return baseValue;
}

class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};
extern GlobalObject_0040c150 g_011d396c;
extern GlobalObject_0040c150 g_011d50b0;

struct HMValueOwner
{
    virtual int GetBaseActorValueInt(int eAV);
    virtual float GetBaseActorValue(int eAV);
    virtual int GetActorValueInt(int eAV);
};

struct HMTarget
{
    bool FUN_00477ba0();
    const char* FUN_0055d520();
};

struct HMTimer
{
    unsigned int FUN_00825c00();
};

int __cdecl sprintf(char*, const char*, ...);
float __cdecl GetActorValueWithPerkModifiers(void* apPlayer, void* apTarget);
void __cdecl ApplyPerkModifiers(int, void*, ...);

struct FUN_007701e0_shell : public HUDMainMenu
{
    void UpdateTargetInfo(HMTarget* apTarget);
};

// @fnv 0x007701e0
void FUN_007701e0_shell::UpdateTargetInfo(HMTarget* apTarget)
{
    float fCurrentAmountNext;
    float fPlayerDist;
    float ratio;
    float fShowInfo;
    {
        char acBuffer[256];
        float maxHealth = (float)((HMValueOwner*)((char*)apTarget + 0xa4))->GetBaseActorValueInt(0x10);
        fCurrentAmountNext = (float)((HMValueOwner*)((char*)apTarget + 0xa4))->GetActorValueInt(0x10);
        fPlayerDist = GetActorValueWithPerkModifiers(pPlayer, apTarget);
        ratio = 0.0f;
        if (maxHealth > 0.0)
        {
            ratio = fCurrentAmountNext / maxHealth;
        }
        static float fLastRatio = ratio;
        if (fLastRatio != ratio)
        {
            m_uiHudValueFirstAfterActor = ((HMTimer*)m_cBuffer)->FUN_00825c00();
            fLastRatio = ratio;
        }
        if (apTarget->FUN_00477ba0())
        {
            UpdateMeterTile(m_pTiles[22], 0.0f, 2, 0, 0);
        }
        else if (!((PlayerDummy*)apTarget)->v139(0))
        {
            UpdateMeterTile(m_pTiles[22], ratio, 2, 1, 0);
        }
        else
        {
            UpdateMeterTile(m_pTiles[22], ratio, 2, 0, 0);
        }
        fShowInfo = 0.0f;
        ApplyPerkModifiers(0x2f, pPlayer, &fShowInfo);
        if (fShowInfo > 0.0)
        {
            sprintf(acBuffer, "%s\n %s:%d %s:%.2f", apTarget->FUN_0055d520(), g_011d50b0.FUN_00403df0(), (int)fCurrentAmountNext,
                    g_011d396c.FUN_00403df0(), fPlayerDist);
            HUDMainMenu_pme->m_pTiles[23]->Set(0xfc4, acBuffer, true);
        }
        else
        {
            HUDMainMenu_pme->m_pTiles[23]->Set(0xfc4, apTarget->FUN_0055d520(), true);
        }
    }
}

struct HUDTime
{
    void FUN_00771520();
    unsigned GetTimeStamp();
};
extern HUDTime DAT_011f6394;
struct HUDFloatSetting
{
    float* FUN_00403e20();
};
struct HUDIntSetting
{
    int* FUN_0043d4d0();
};
extern HUDFloatSetting DAT_011d9774, DAT_011cf87c;
extern HUDIntSetting DAT_011d2220;
struct HUDMode
{
    int FUN_0044ddc0();
};
extern HUDMode DAT_011f2250;
struct HUDDetection
{
    int value;
    bool detected;
    bool ignored;
};
struct HUDDetectionList
{
    bool FUN_008256d0();
    HUDDetection** FUN_006815c0();
    HUDDetectionList* FUN_00726070();
};
struct HUDActor : RefX
{
    int FUN_008d6f30();
    bool FUN_004997b0();
    bool FUN_004d1360();
    HUDDetectionList* FUN_00595d10();
    bool FUN_00477ba0();
    HUDDetection* FUN_00967090(void*);
    bool FUN_008bc700(void*);
    bool FUN_00493bb0();
    bool FUN_00579690();
    Script* FUN_005cbb50();
};
struct HUDTile : TileX
{
    bool FUN_00a07fc0(int);
    bool IsTraitNonZero(int);
    void StartFade(int, float, float, float, int);
    void FUN_00715c60(int, unsigned);
};
struct HUDSubtitle
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
    unsigned time;
    float duration;
};
struct HUDMessage
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
    float duration;
};
struct HUDSubtitleList
{
    bool FUN_0076b610();
    unsigned FUN_0044ddc0();
    HUDSubtitle** FUN_00877a30(unsigned);
    void FUN_006bf8f0(unsigned, bool);
};
struct HUDMessageList
{
    int FUN_005ae380();
    HUDMessage** FUN_006815c0();
};
void __cdecl FUN_00779070(Tile*, Tile*, Tile*, Tile*);
float __cdecl FUN_00715da0();
float __cdecl FUN_00715d40();
float __cdecl FUN_007177c0();
float __cdecl FUN_00717820();
float __cdecl FUN_00408840(float);
void __cdecl FUN_00773190(RefX*);
void __cdecl FormHeap_Free(void*);
int __cdecl FUN_00458030();
extern bool DAT_011d96c5, DAT_011d97c0;
extern float DAT_011d979c;
extern const char DAT_01073474[];
extern RefX* DAT_011f21cc;
extern const double DAT_0101db88, DAT_01073480, DAT_0101e568, DAT_01017b70, DAT_010357e8;
extern const float DAT_010162c0, DAT_01016248, DAT_01021f44;
struct HUDUpdate : HUDMainMenu
{
    void FUN_00770430();
    void FUN_0077da60();
    void UpdateAmmoHUD();
    void UpdateCompassMarkers();
    void FUN_0077f700();
    void UpdateActorValueMeter(int);
    void FUN_0077e4f0();
    void FUN_007732d0();
    void UpdateQuestNotification();
    void FUN_0077c4e0();
    void UpdateRadMeter();
    void UpdateCrippleMeters(bool);
    void UpdateTargetInfo(void*);
    void ResetHudTiles();
    void ResetWaitTiles();
    void FUN_00775670();
    HUDSubtitle* FindTargetMarker();
    void FUN_007756e0();
};
// @fnv 0x00770430
void HUDUpdate::FUN_00770430()
{
    if (!DAT_011dea3c || !((HUDActor*)DAT_011dea3c)->FUN_008d6f30())
        return;
    ((HUDTime*)m_cBuffer)->FUN_00771520();
    FUN_00779070(m_pTiles[6], m_pTiles[3], m_pTiles[4], m_pTiles[5]);
    FUN_0077da60();
    UpdateAmmoHUD();
    UpdateCompassMarkers();
    FUN_0077f700();
    static unsigned lastUpdate = ((HUDTime*)m_cBuffer)->GetTimeStamp();
    if (((HUDTime*)m_cBuffer)->GetTimeStamp() - lastUpdate < 200)
        return;
    if (m_iHudValueFirstAfterUnsignedValues == -1 ||
        DAT_011f6394.GetTimeStamp() - m_iHudValueFirstAfterUnsignedValues > 1000)
    {
        m_iHudValueFirstAfterUnsignedValues = -1;
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[75])->Set(4003, 0);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[82])->Set(4003, 0);
    }
    if (m_iHudValueSecondAfterUnsignedValues == -1 ||
        DAT_011f6394.GetTimeStamp() - m_iHudValueSecondAfterUnsignedValues > 1000)
    {
        m_iHudValueSecondAfterUnsignedValues = -1;
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[76])->Set(4003, 0);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[83])->Set(4003, 0);
    }
    lastUpdate = ((HUDTime*)m_cBuffer)->GetTimeStamp();
    int f = (int)FUN_00715da0(), h = (int)FUN_00715d40();
    int cf = (int)FUN_007177c0(), p = (int)FUN_00717820();
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])->Set(4001, 2 * cf + 10);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])
        ->Set(4002, f - 2 * p - ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])->GetFloat(4016), true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])
        ->Set(4001, h - 2 * cf - ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])->GetFloat(4017) + DAT_0101db88, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])
        ->Set(4002, f - 2 * p - ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])->GetFloat(4016), true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[60])->Refresh(1);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[59])->Refresh(1);
    UpdateActorValueMeter(16);
    UpdateActorValueMeter(12);
    FUN_0077e4f0();
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[86])->Set(4009, DAT_011d979c, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[78])->Set(4009, DAT_011d979c, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[75])->Set(4009, DAT_011d979c, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[82])->Set(4009, DAT_011d979c, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[83])->Set(4009, DAT_011d979c, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[76])->Set(4009, DAT_011d979c, true);
    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[77])->Set(4009, DAT_011d979c, true);
    if (((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->GetFloat(4009) > 0.0 &&
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->FUN_00a07fc0(4009) &&
        DAT_011f6394.GetTimeStamp() - ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->GetFloat(4100) > DAT_01073480)
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])
            ->StartFade(4009, ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->GetFloat(4009), 0.0f, DAT_010162c0, 0);
    if (((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])->GetFloat(4009) > 0.0 &&
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])->FUN_00a07fc0(4009) &&
        DAT_011f6394.GetTimeStamp() - ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])->GetFloat(4100) > DAT_01073480)
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])
            ->StartFade(4009, *DAT_011d9774.FUN_00403e20() * DAT_0101e568, 0.0f, DAT_010162c0, 0);
    if (((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->IsTraitNonZero(xTraitID(DAT_01073474)) &&
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[64])->GetFloat(4003) != 0.0 &&
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])->GetFloat(4009) == 0.0 &&
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[16])->FUN_00a07fc0(4009))
    {
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])
            ->StartFade(4009, 0.0f, *DAT_011d9774.FUN_00403e20() * DAT_0101e568, DAT_010162c0, 0);
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->FUN_00715c60(4100, DAT_011f6394.GetTimeStamp());
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[15])->Set(xTraitID(DAT_01073474), 0);
    }
    if (((HUDActor*)DAT_011dea3c)->FUN_004997b0())
        FUN_007732d0();
    else if (((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])->GetFloat(4009) > 0.0 &&
             ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])->FUN_00a07fc0(4009))
        ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])
            ->StartFade(4009, ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[24])->GetFloat(4009), 0.0f, DAT_01016248, 0);
    if (HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 18 && HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 19)
        UpdateQuestNotification();
    FUN_0077c4e0();
    UpdateRadMeter();
    UpdateCrippleMeters(((HUDActor*)DAT_011dea3c)->FUN_004d1360());
    DAT_011d96c5 = false;
    if (m_pTargetActor)
    {
        HUDDetectionList* list = ((HUDActor*)DAT_011dea3c)->FUN_00595d10();
        while (list && !list->FUN_008256d0())
        {
            HUDDetection* detection = *list->FUN_006815c0();
            if ((void*)detection->value == m_pTargetActor && detection->detected && !detection->ignored)
            {
                DAT_011d96c5 = true;
                break;
            }
            list = list->FUN_00726070();
        }
    }
    bool a = false;
    float eb = ((HUDActor*)DAT_011dea3c)->GetDistanceScale(0) * DAT_0102f248;
    float s = 0.0f;
    if (m_pTargetActor)
        s = GetAngleBetweenPoints(*(NiPoint3*)((HUDActor*)DAT_011dea3c)->GetPos(),
                                  *(NiPoint3*)((HUDActor*)m_pTargetActor)->GetPos());
    bool i = (((HUDTime*)m_cBuffer)->GetTimeStamp() - m_uiHudValueFirstAfterActor >
                  (unsigned)(*DAT_011cf87c.FUN_00403e20() * DAT_01017b70) &&
              !(FUN_00408840(eb - s) < DAT_010357e8))
                 ? 0
                 : 1;
    if (DAT_011f2250.FUN_0044ddc0() == 4)
    {
        if (DAT_011f21cc && DAT_011f21cc->IsActor() && !DAT_011f21cc->IsDead(false))
        {
            a = true;
            FUN_00773190((RefX*)DAT_011f21cc);
        }
    }
    else if (m_pTargetActor && !((HUDActor*)m_pTargetActor)->IsDead(false) &&
             !((HUDActor*)m_pTargetActor)->FUN_00477ba0() && DAT_011d96c5 &&
             !((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[29])->IsTraitNonZero(4003) &&
             !((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[32])->IsTraitNonZero(4003) &&
             ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[62])->GetFloat(4084) == 2.0 && i)
    {
        a = true;
        UpdateActivatePrompt((RefX*)m_pCrosshairReference, 0, true);
    }
    else if (((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[62])->GetFloat(4084) == 2.0)
    {
        ((TileX*)m_pTiles[21])->Set(4003, 0);
        ((TileX*)m_pTiles[22])->Set(4003, 0);
        ((TileX*)m_pTiles[23])->Set(4003, 0);
    }
    if (a)
    {
        bool hostile = false;
        if (m_pTargetActor && ((((HUDActor*)DAT_011dea3c)->FUN_00967090(m_pTargetActor) &&
                                ((HUDActor*)DAT_011dea3c)->FUN_00967090(m_pTargetActor)->detected) ||
                               ((HUDActor*)m_pTargetActor)->FUN_008bc700(DAT_011dea3c)))
            hostile = true;
        ((TileX*)m_pTiles[21])->Set(4003, 1);
        ((TileX*)m_pTiles[22])->Set(4003, 1);
        ((TileX*)m_pTiles[23])->Set(4003, 1);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[62])->Set(4084, hostile ? 2 : 1);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[21])->Refresh(8);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[22])->Refresh(8);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[23])->Refresh(8);
        ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[23])->Refresh(8);
    }
    if (m_pTargetActor && (((HUDActor*)m_pTargetActor)->FUN_00493bb0() || DAT_011f2250.FUN_0044ddc0() == 4))
        UpdateTargetInfo(m_pTargetActor);
    if (m_pCrosshairReference && DAT_011d97c0 != ((HUDActor*)m_pCrosshairReference)->FUN_00579690())
    {
        DAT_011d97c0 = ((HUDActor*)m_pCrosshairReference)->FUN_00579690();
        UpdateActivatePrompt((RefX*)m_pCrosshairReference, 0, true);
    }
    if (m_bHudAnimationActive &&
        DAT_011f6394.GetTimeStamp() - m_uiHudValueSecondAfterActor > (unsigned)(*DAT_011d2220.FUN_0043d4d0() * 1000) &&
        HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 18 && HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_eHudMenuMode != 19)
    {
        m_uiHudValueSecondAfterActor = DAT_011f6394.GetTimeStamp();
        FUN_007736d0(((HUDActor*)DAT_011dea3c)->FUN_005cbb50());
    }
    else if (m_uiHudValueSecondAfterActor == 0 && FUN_00458030() == 2)
    {
        m_uiHudValueSecondAfterActor = DAT_011f6394.GetTimeStamp();
        FUN_007736d0(((HUDActor*)DAT_011dea3c)->FUN_005cbb50());
        m_bQuestObjectiveUpdatesEnabled = false;
    }
    {
        unsigned k;
        HUDMessage* l;
        if (m_bQuestObjectiveUpdatesEnabled)
        {
            ResetHudTiles();
            ResetWaitTiles();
            m_bQuestObjectiveUpdatesEnabled = false;
        }
        else if (!((HUDSubtitleList*)m_kSubtitleArray)->FUN_0076b610())
        {
            for (k = 0; k < ((HUDSubtitleList*)m_kSubtitleArray)->FUN_0044ddc0(); ++k)
            {
                if (((HUDTime*)m_cBuffer)->GetTimeStamp() -
                        (*((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k))->time >=
                    (*((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k))->duration * DAT_01017b70)
                {
                    if (*((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k) == m_pCurrentSubtitle)
                        FUN_00775670();
                    HUDSubtitle* j = *((HUDSubtitleList*)m_kSubtitleArray)->FUN_00877a30(k);
                    FormHeap_Free(j);
                    ((HUDSubtitleList*)m_kSubtitleArray)->FUN_006bf8f0(k, true);
                    --k;
                }
            }
            if (!m_pCurrentSubtitle)
            {
                m_pCurrentSubtitle = FindTargetMarker();
                if (m_pCurrentSubtitle)
                {
                    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[28])->Set(4036, (const char*)m_pCurrentSubtitle, true);
                    ((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[28])->Set(4003, 1);
                }
            }
        }
        if (((HUDMessageList*)m_kMessageList)->FUN_005ae380() &&
            ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[67])->IsTraitNonZero(4003))
        {
            if (((TileX*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[27])->GetFloat(4009) == 0.0)
            {
                ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[27])
                    ->StartFade(4009, 0.0f, DAT_011d979c, DAT_01021f44, 0);
                ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[25])
                    ->StartFade(4009, 0.0f, DAT_011d979c, DAT_01021f44, 0);
                ((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[26])
                    ->StartFade(4009, 0.0f, DAT_011d979c, DAT_01021f44, 0);
            }
            if (((HUDTile*)HUDMainMenu_WithPme::g_pHudMainMenuInstance->m_pTiles[27])->FUN_00a07fc0(4009))
            {
                l = *((HUDMessageList*)m_kMessageList)->FUN_006815c0();
                if (!m_uiMessageCount)
                    m_uiMessageCount = ((HUDTime*)m_cBuffer)->GetTimeStamp();
                if (((HUDTime*)m_cBuffer)->GetTimeStamp() - m_uiMessageCount >= l->duration * DAT_01017b70)
                    FUN_007756e0();
            }
        }
    }
    DAT_011d979c = *DAT_011d9774.FUN_00403e20() * DAT_0101e568;
}

struct MarkerData772
{
    const char* FUN_00438eb0();
};
struct MarkerRef772
{
    MarkerData772* GetMapMarkerData();
};
struct MarkerEvent772
{
    MarkerRef772* reference;
    bool active;
    bool force;
};
extern MarkerRef772* DAT_011d9af0;
struct Setting772
{
    float* FUN_00403e20(float, bool);
};
extern Setting772 g_011d9774;
struct Tile772
{
    bool FUN_00a07fc0(int);
    float FUN_00a011b0(int);
    void FUN_00a01350(int, const char*, bool);
    void StartFade(int, float, float);
    void FUN_00715c60(int, int);
    void RemoveFadeItemsForTile(int);
    void FUN_00a012d0(int, float, bool);
};
// @fnv 0x00772aa0
void __cdecl UpdateMapMarkerHUD(MarkerEvent772* event)
{
    if (!HUDMainMenu_pme)
        return;
    if (event->active && event->reference != DAT_011d9af0)
    {
        DAT_011d9af0 = event->reference;
        if (event->reference && event->reference->GetMapMarkerData())
        {
            if (((Tile772*)HUDMainMenu_pme->m_pTiles[16])->FUN_00a07fc0(0xfa9) &&
                ((Tile772*)HUDMainMenu_pme->m_pTiles[16])->FUN_00a011b0(0xfa9) == 0.0)
            {
                ((Tile772*)HUDMainMenu_pme->m_pTiles[16])
                    ->FUN_00a01350(0xfc4, event->reference->GetMapMarkerData()->FUN_00438eb0(), true);
                ((Tile772*)HUDMainMenu_pme->m_pTiles[16])
                    ->StartFade(0xfa9, 0.0f, (float)(*g_011d9774.FUN_00403e20(2.0f, false) * 255.0));
                ((Tile772*)HUDMainMenu_pme->m_pTiles[16])->FUN_00715c60(0x1004, g_timeGlobal.GetSection());
            }
            ((Tile772*)HUDMainMenu_pme->m_pTiles[15])->RemoveFadeItemsForTile(0xfa9);
            ((Tile772*)HUDMainMenu_pme->m_pTiles[15])->FUN_00a012d0(0xfa9, 0.0f, true);
        }
    }
    else if (!event->active && event->reference == DAT_011d9af0)
    {
        DAT_011d9af0 = 0;
    }
    else if (event->force)
    {
        DAT_011d9af0 = event->reference;
    }
}

class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
class GlobalObject_00709f00 : public GlobalObject_0045cf30
{
};
extern GlobalObject_00709f00 g_011d8a0c;
extern GlobalObject_00709f00 g_011d898c;
struct HealthActor : RefX
{
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
    ActorValueOwner actorValues;
    TESBoundObject* FUN_00579280();
    bool FUN_008bc700(Actor* other);
    DetectX* FUN_00967090(HealthActor* other);
    bool FUN_008bbc10();
};
struct FUN_00a01230_shell : Tile
{
    bool IsTraitNonZero(int trait);
};
struct FUN_00a07530_shell : Tile
{
    void FUN_00a07530(int flags);
};
struct TargetHealthTile : Tile
{
    float FUN_00a011b0(int trait);
};
struct TargetHealthHUD : HUDMainMenu
{
    void UpdateTargetInfo(HealthActor* actor);
};
void __cdecl FUN_00773190(HealthActor* actor);
extern bool DAT_011d96ba;
extern bool DAT_011d96b9;

// @fnv 0x00772d10
void __cdecl UpdateTargetHealthHUD(HealthActor* target, unsigned char enabled)
{
    bool isHostile = false;
    {
        bool isDead = true;
        if (target && HUDMainMenu_pme && !*g_011d8a0c.Bool() && enabled &&
            (!*g_011d898c.Bool() || !((HealthActor*)pPlayer)->FUN_008bbc10()))
        {
            HealthActor* actor;
            {
                TESBoundObject* baseObject = target->FUN_00579280();
                actor = target->IsActor() ? target : 0;
                isDead = actor && actor->IsDead(false);
                if (actor && ((((HealthActor*)pPlayer)->FUN_00967090(actor) &&
                               ((HealthActor*)pPlayer)->FUN_00967090(actor)->bDetected) ||
                              actor->FUN_008bc700((Actor*)pPlayer)))
                {
                    isHostile = true;
                }
                bool show = actor && !isDead && !actor->IsDead(false) &&
                            actor->actorValues.GetActorValueInt(16) < actor->actorValues.GetBaseActorValueInt(16) &&
                            !((FUN_00a01230_shell*)HUDMainMenu_pme->m_pTiles[32])->IsTraitNonZero(4003);
                if (show)
                {
                    FUN_00773190(actor);
                    HUDMainMenu_pme->m_pTiles[21]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[22]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[23]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[23]->Set(4003, 1);
                    HUDMainMenu_pme->m_pTiles[62]->Set(4084, isHostile ? 2 : 1);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[21])->FUN_00a07530(8);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[22])->FUN_00a07530(8);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[23])->FUN_00a07530(8);
                    ((FUN_00a07530_shell*)HUDMainMenu_pme->m_pTiles[23])->FUN_00a07530(8);
                    ((TargetHealthHUD*)HUDMainMenu_pme)->UpdateTargetInfo(actor);
                }
            }
        }
        else if (((TargetHealthTile*)HUDMainMenu_pme->m_pTiles[62])->FUN_00a011b0(4084) == 1.0)
        {
            HUDMainMenu_pme->m_pTiles[21]->Set(4003, 0);
            HUDMainMenu_pme->m_pTiles[22]->Set(4003, 0);
            HUDMainMenu_pme->m_pTiles[23]->Set(4003, 0);
        }
        DAT_011d96ba = !isDead && isHostile;
        DAT_011d96b9 = static_cast<int>(enabled);
    }
}

namespace fnv_00773190 {
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011e0988;
struct EnemyListCount
{
    unsigned int FUN_0044ddc0();
};
extern int DAT_011f2250;
extern Actor* DAT_011f21cc;
extern HUDMainMenu* HUDMainMenu_pme;
struct EnemyActorV
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
    virtual bool IsHostile();
};
struct EnemyRefV
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
    virtual bool IsUnseen(int iArg);
    char* FUN_0055d520();
};
struct EnemyTimer
{
    void FUN_00771520();
    unsigned int FUN_00825c00();
};
// Selects the enemy reference to show in the HUD, sets its name text, and refreshes the timer and its value.
// @fnv 0x00773190
void FUN_00773190(EnemyRefV* pkRef)
{
    if (*g_011e0988.Bool())
        return;
    if (pkRef && pkRef->IsUnseen(0))
        return;
    if (!HUDMainMenu_pme)
        return;
    if (((EnemyListCount*)&DAT_011f2250)->FUN_0044ddc0() == 4)
        HUDMainMenu_pme->m_pTargetActor =
            (DAT_011f21cc && ((EnemyActorV*)DAT_011f21cc)->IsHostile()) ? DAT_011f21cc : 0;
    else
        HUDMainMenu_pme->m_pTargetActor = pkRef;
    if (HUDMainMenu_pme->m_pTargetActor)
    {
        HUDMainMenu_pme->m_pTiles[23]->Set(0xfc4, ((EnemyRefV*)HUDMainMenu_pme->m_pTargetActor)->FUN_0055d520(), true);
        ((EnemyTimer*)HUDMainMenu_pme->m_cBuffer)->FUN_00771520();
        HUDMainMenu_pme->m_uiHudValueFirstAfterActor = ((EnemyTimer*)HUDMainMenu_pme->m_cBuffer)->FUN_00825c00();
    }
}
}  // namespace fnv_00773190

struct RadiationTile
{
    double FUN_00a011b0(int trait);
    void FUN_00a012d0(int trait, float value, int propagate);
    void FUN_00700320(int trait, int enabled);
};
struct RandomGenerator
{
    unsigned int FUN_00825c00();
};
extern RandomGenerator g_011f6394;
extern const double DAT_01073490;
// @fnv 0x007737c0
void HUDMainMenuS::FUN_007737c0(float afDrinkinRads, float afStandinRads)
{
    float totalRads = afDrinkinRads + afStandinRads;
    if (afDrinkinRads > _gModifierZero)
    {
        reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])
            ->FUN_00a012d0(0x100a, (float)((double)g_011f6394.FUN_00825c00() + DAT_01073490), 1);
        reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])->FUN_00a012d0(0x1009, totalRads, 1);
        reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])->FUN_00700320(0x100b, 1);
    }
    else if (afStandinRads > _gModifierZero)
    {
        if (reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])->FUN_00a011b0(0x100a) <=
            (double)g_011f6394.FUN_00825c00())
        {
            reinterpret_cast<RadiationTile*>(g_pHudMainMenuInstance->m_pTiles[19])->FUN_00a012d0(0x1009, totalRads, 1);
        }
    }
}

struct HudTile
{
    void SetString(int aeValue, const char* apText, bool abPropagate);
    void SetFloat(int aeValue, float afValue, bool abPropagate);
};

struct HudSetting
{
    const char* GetString();
    float* GetFloatPtr();
};

struct HudPlayerBase
{
    virtual void v0();
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

struct HudPlayer : public HudPlayerBase, public ActorValueOwner
{
};

struct HudMenuShell : public HUDMainMenu
{
    void SetMeter(Tile* apTile, float afValue, bool abFlag);
    void UpdateCrippleMeters(bool abShow);
};

extern HudSetting sHudString0;
extern HudSetting sHudString1;
extern HudSetting sHudString2;
extern HudSetting sHudString3;
extern HudSetting sHudString4;
extern HudSetting fHudCripple4;
extern HudSetting fHudCripple3;
extern HudSetting fHudCripple2;
extern HudSetting fHudCripple1;
extern HUDMainMenu* g_pHUDMainMenu;
extern HudPlayer* g_pHudPlayer;
extern const double kHudZero;
extern const double kHudOne;
float __cdecl GetActorValueScaled(ActorValueOwner* apOwner, int aeAV, int aiFlag);

// @fnv 0x007739f0
void HudMenuShell::UpdateCrippleMeters(bool abShow)
{
    ((HudTile*)g_pHUDMainMenu->m_pTiles[85])->SetString(4036, sHudString0.GetString(), true);
    ((HudTile*)g_pHUDMainMenu->m_pTiles[84])->SetString(4036, sHudString1.GetString(), true);
    ((HudTile*)g_pHUDMainMenu->m_pTiles[79])->SetString(4036, sHudString2.GetString(), true);
    ((HudTile*)g_pHUDMainMenu->m_pTiles[81])->SetString(4036, sHudString3.GetString(), true);
    ((HudTile*)g_pHUDMainMenu->m_pTiles[80])->SetString(4036, sHudString4.GetString(), true);

    int iCrippled3 = 0;
    float fHead = GetActorValueScaled(g_pHudPlayer, 0x1b, 0);
    if (fHead == kHudZero)
        iCrippled3++;
    float fTorso5 = GetActorValueScaled(g_pHudPlayer, 0x1d, 0);
    if (fTorso5 == kHudZero)
        iCrippled3++;
    float fRightArm = GetActorValueScaled(g_pHudPlayer, 0x1e, 0);
    if (fRightArm == kHudZero)
        iCrippled3++;
    float fLeftArm = GetActorValueScaled(g_pHudPlayer, 0x1c, 0);
    if (fLeftArm == kHudZero)
        iCrippled3++;
    float fPerception = GetActorValueScaled(g_pHudPlayer, 0x19, 0);
    if (fPerception == kHudZero)
        iCrippled3++;
    float fEndurance8 = GetActorValueScaled(g_pHudPlayer, 0x1a, 0);
    if (fEndurance8 == kHudZero)
        iCrippled3++;

    float _fPenalty = 0.0f;
    if (iCrippled3 >= 4)
        _fPenalty = *fHudCripple4.GetFloatPtr() + kHudOne;
    else if (iCrippled3 >= 3)
        _fPenalty = *fHudCripple3.GetFloatPtr() + kHudOne;
    else if (iCrippled3 >= 2)
        _fPenalty = *fHudCripple2.GetFloatPtr() + kHudOne;
    else if (iCrippled3 >= 1)
        _fPenalty = *fHudCripple1.GetFloatPtr() + kHudOne;

    SetMeter(g_pHUDMainMenu->m_pTiles[84], (float)g_pHudPlayer->GetActorValueInt(0x36), false);
    SetMeter(g_pHUDMainMenu->m_pTiles[85], _fPenalty, !abShow);
    if (!abShow)
    {
        ((HudTile*)g_pHUDMainMenu->m_pTiles[79])->SetFloat(4009, 0.0f, true);
        ((HudTile*)g_pHUDMainMenu->m_pTiles[80])->SetFloat(4009, 0.0f, true);
        ((HudTile*)g_pHUDMainMenu->m_pTiles[81])->SetFloat(4009, 0.0f, true);
    }
    else
    {
        SetMeter(g_pHUDMainMenu->m_pTiles[79], (float)g_pHudPlayer->GetActorValueInt(0x49), false);
        SetMeter(g_pHUDMainMenu->m_pTiles[80], (float)g_pHudPlayer->GetActorValueInt(0x4b), false);
        SetMeter(g_pHUDMainMenu->m_pTiles[81], (float)g_pHudPlayer->GetActorValueInt(0x4a), true);
    }
}

namespace fnv_00774090 {
struct RadTile
{
    float FUN_00a011b0(int);
    bool FUN_00a07fc0(int);
    bool IsTraitNonZero(int);
    void StartFade(int, float, float, float, int);
    void FUN_00a012d0(int, float, bool);
    void Set(int, int);
    void Set(int, const char*, bool);
};
struct RadTime
{
    unsigned int FUN_00825c00();
};
struct RadProcess
{
    bool IsFlagged();
};
extern RadProcess DAT_011e0e80;
extern RadTime DAT_011f6394;
extern int DAT_011a0120;
extern float DAT_011d979c;
extern char DAT_011d9b08[260];
struct RadOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetValue(int);
};
struct RadPlayer
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
    RadOwner owner;
};
float __cdecl LinearInterpolate(float, float, float, float, float);
int __cdecl FUN_00647b70(int, int);
struct RadHUD : HUDMainMenu
{
    void UpdateRadMeter();
};
// Updates the radiation meter HUD tiles: reads the player's rad level, animates the needle and angle tiles, and sets the +N rad text when low or recently changed.
// @fnv 0x00774090
void RadHUD::UpdateRadMeter()
{
    bool recent;
    bool low;
    float delta;
    delta = 0.0f;
    recent = ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->FUN_00a011b0(0x100a) > DAT_011f6394.FUN_00825c00();
    low = DAT_011e0e80.IsFlagged();
    if (!low && !recent && DAT_011a0120 == 4)
        return;
    bool previousAngle = false;
    if (((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a07fc0(0xfa9) &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a011b0(0xfa9) == 0.0 &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a07fc0(0xfa9) &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a011b0(0xfa9) == 0.0 &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->FUN_00a07fc0(0xfa9) &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->FUN_00a011b0(0xfa9) == 0.0 &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[20])->FUN_00a07fc0(0xfa9) &&
        ((RadTile*)HUDMainMenu_pme->m_pTiles[20])->FUN_00a011b0(0xfa9) == 0.0)
        DAT_011a0120 = 4;
    if ((DAT_011a0120 == 4 || DAT_011a0120 == 2) && (low || recent))
    {
        DAT_011a0120 = 8;
        previousAngle = true;
    }
    float high = 15.0f;
    float unused = 315.0f;
    float active = 0.0f;
    float currentAngle;
    bool showing;
    {
        float change = 0.0f;
        currentAngle = 0.0f;
        showing = ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->IsTraitNonZero(0x100b) || recent;
        if (low || recent || previousAngle)
        {
            float value = (float)((RadPlayer*)DAT_011dea3c)->owner.GetValue(54);
            bool updateText = false;
            if (low || previousAngle || showing)
            {
                updateText = true;
                change = ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->FUN_00a011b0(0x1009);
                active = LinearInterpolate(high, unused, 0.0f, 1000.0f,
                                           FUN_00404010(FUN_0040ebd0(value - change, 1000.0f), 0.0f));
            }
            if ((recent && previousAngle) || showing || low)
            {
                updateText = true;
                currentAngle =
                    LinearInterpolate(high, unused, 0.0f, 1000.0f, FUN_00404010(FUN_0040ebd0(value, 1000.0f), 0.0f));
            }
            if (updateText)
            {
                xsprintf_s(DAT_011d9b08, 260, "+%i", FUN_00647b70(1, (int)change));
                ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->Set(0xfc4, DAT_011d9b08, true);
            }
        }
        if (previousAngle)
        {
            DAT_011a0120 = 8;
            ((RadTile*)HUDMainMenu_pme->m_pTiles[18])
                ->FUN_00a012d0(0xfa1, FUN_0040ebd0(low ? currentAngle : active, unused), true);
            HUDMainMenu_pme->m_pTiles[61]->Set(0xfa3, 1);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[17])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a011b0(0xfa9), DAT_011d979c, 0.25f,
                            0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[18])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a011b0(0xfa9), DAT_011d979c, 0.25f,
                            0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[19])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[19])->FUN_00a011b0(0xfa9), DAT_011d979c, 0.25f,
                            0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[20])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[20])->FUN_00a011b0(0xfa9), DAT_011d979c, 0.25f,
                            0);
        }
        else if (low)
        {
            ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a012d0(0xfa1, FUN_0040ebd0(currentAngle, unused), true);
        }
        if (showing)
        {
            HUDMainMenu_pme->m_pTiles[19]->Set(0x100b, 0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a012d0(0x1004, FUN_0040ebd0(currentAngle, unused), true);
            float duration = LinearInterpolate(1.5f, 3.0f, 0.0f, 50.0f, FUN_0040ebd0(50.0f, change));
            float start = ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a011b0(0xfa1);
            float finish = FUN_00404010(((RadTile*)HUDMainMenu_pme->m_pTiles[18])->FUN_00a011b0(0x1004), high);
            if (!low)
                ((RadTile*)HUDMainMenu_pme->m_pTiles[18])->StartFade(0xfa1, start, finish, duration, 0);
        }
        if (!low && !recent)
        {
            DAT_011a0120 = 2;
            ((RadTile*)HUDMainMenu_pme->m_pTiles[17])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a011b0(0xfa9), 0.0f, 0.25f, 0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[18])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a011b0(0xfa9), 0.0f, 0.25f, 0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[19])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a011b0(0xfa9), 0.0f, 0.25f, 0);
            ((RadTile*)HUDMainMenu_pme->m_pTiles[20])
                ->StartFade(0xfa9, ((RadTile*)HUDMainMenu_pme->m_pTiles[17])->FUN_00a011b0(0xfa9), 0.0f, 0.25f, 0);
        }
    }
}
}  // namespace fnv_00774090

int LookupTrait(const char*, int);
struct BarTile;
struct BarChildren
{
    BarTile** GetFirst();
};
struct BarTile
{
    int unk00;
    BarChildren children;
    float GetValue(int);
    void SetInt(int, int);
    bool HasAnimation(int);
    void Animate(int, float, float, float, int);
};

int MinInt(int, int);
// Clamps current and target to 0..1, computes tile widths and x positions from traits, and sets width/x on both tiles, animating the right tile if needed.
// @fnv 0x00774b00
void UpdateBarWidths(BarTile* apLeftTile, BarTile* apRightTile, float current, float target, int alignment, int minimum)
{
    static int totalTrait = LookupTrait("_TotalWidth", -1);
    static int imageTrait = LookupTrait("_ImageWidth", -1);
    static int xTrait = LookupTrait("_OriginalX", -1);
    static int brightnessTrait = LookupTrait("_Brightness", -1);
    if (apLeftTile && apRightTile && HUDMainMenu_pme)
    {
        if (current > 1.0)
            current = 1.0f;
        else if (current < 0.0)
            current = 0.0f;
        if (target > 1.0)
            target = 1.0f;
        else if (target < 0.0)
            target = 0.0f;
        int total = (int)apLeftTile->GetValue(totalTrait);
        int image6 = (int)apLeftTile->GetValue(imageTrait);
        int width3;
        int targetWidthTmp;
        if (alignment == 2)
        {
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / (2 * image6)) * (2 * image6);
            targetWidthTmp = (int)(total * target / (2 * image6)) * (2 * image6);
        }
        else
        {
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / image6) * image6;
            targetWidthTmp = (int)(total * target / image6) * image6;
        }
        if (alignment == 2)
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / (2 * image6)) * (2 * image6);
        else
            width3 = (int)(total * (current >= 0.0 ? current : 0.0f) / image6) * image6;
        int xpos6 = (int)apLeftTile->GetValue(xTrait);
        if (alignment == 1)
            xpos6 -= width3;
        else if (alignment == 2)
            xpos6 -= width3 / 2;
        int remainderTmp = targetWidthTmp;
        int otherX = (int)apRightTile->GetValue(xTrait);
        if (alignment == 1)
        {
            remainderTmp -= width3;
            otherX = xpos6 - remainderTmp;
            remainderTmp = MinInt(remainderTmp, (int)apRightTile->GetValue(xTrait) - otherX);
        }
        else if (alignment == 0)
        {
            otherX += width3;
        }
        else if (alignment == 2)
        {
            otherX -= targetWidthTmp / 2;
            remainderTmp = xpos6 - otherX;
            BarTile* child2 = *apRightTile->children.GetFirst();
            child2->SetInt(0xfb1, remainderTmp);
            child2->SetInt(0xfa1, xpos6 + width3);
            if (!child2->HasAnimation(0xfa9))
                child2->Animate(0xfa9, 0.0f, 255.0f, 1.0f, 1);
        }
        if (width3 == 0 && remainderTmp < image6 * minimum)
            remainderTmp = image6 * minimum;
        apLeftTile->SetInt(0xfb1, width3);
        apLeftTile->SetInt(0xfa1, xpos6);
        apRightTile->SetInt(0xfb1, remainderTmp);
        apRightTile->SetInt(0xfa1, otherX);
        if (!apRightTile->HasAnimation(0xfa9))
            apRightTile->Animate(0xfa9, 0.0f, 255.0f, 1.0f, 1);
    }
}

struct MessageEntry
{
    char text[260];
    char icon[260];
    char sound[260];
    float duration;
};
struct MessageList
{
    MessageEntry*& Item();
    MessageList* Next();
    bool Empty();
    void Tail(MessageEntry*&);
    void Head(MessageEntry*&);
};
struct MessageTile
{
    void Set(int, const char*, bool);
};
struct MessageHUD
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
    MessageList messages;
    bool AddMessage(const char*, unsigned int, const char*, const char*, float, bool);
};
struct SoundHandleMsg
{
    unsigned int id;
    bool success;
    unsigned int state;
    ~SoundHandleMsg();
    bool Play(bool);
};
struct AudioMsg
{
    static AudioMsg* Instance();
    SoundHandleMsg Get(const char*, unsigned int);
};
struct TilesMsg
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
    MessageTile* icon;
    MessageTile* text;
};
extern TilesMsg* messageHUD;
int copyMessage(char*, unsigned int, const char*);
int compareMessage(const char*, const char*);
// @fnv 0x00775380
bool MessageHUD::AddMessage(const char* text, unsigned int kind, const char* icon, const char* sound, float duration,
                            bool immediate)
{
    bool result = false;
    if (text)
    {
        MessageEntry* entry = new MessageEntry;
        copyMessage(entry->text, 260, text);
        entry->duration = duration;
        if (icon && *icon)
            copyMessage(entry->icon, 260, icon);
        else
        {
            switch (kind)
            {
            case 1:
                copyMessage(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds");
                break;
            case 2:
                copyMessage(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds");
                break;
            case 0:
                copyMessage(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds");
                break;
            case 3:
                copyMessage(entry->icon, 260, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_in_pain.dds");
                break;
            }
        }
        if (sound)
            copyMessage(entry->sound, 260, sound);
        else
            entry->sound[0] = 0;
        if (messages.Empty())
        {
            messages.Tail(entry);
            messageHUD->text->Set(0xfc4, messages.Item()->text, true);
            messageHUD->icon->Set(0xfcc, messages.Item()->icon, true);
            if (sound)
                AudioMsg::Instance()->Get(sound, 0x121).Play(false);
        }
        else
        {
            MessageList* tail = &messages;
            while (tail->Next())
                tail = tail->Next();
            if (compareMessage(tail->Item()->text, entry->text))
            {
                if (immediate)
                {
                    messages.Item()->duration = 0.0f;
                    messages.Head(entry);
                }
                else
                    messages.Tail(entry);
            }
            else
                delete entry;
        }
        result = true;
    }
    return result;
}

namespace fnv_007756e0 {
class HUDMainMenu__MessageData
{
  public:
    char cMessage[0x104];
    char cIconPath[0x104];
    char cSoundPath[0x104];
    float fDisplayTime;
};

class TileStub
{
  public:
    const char* GetString(int aiID);
    void Set(int aiID, const char* apValue, bool abPropagate);
    void GradualSetFloat(int aiID, float afStart, float afEnd, float afDuration, int aiMode);
};

class PlayerCharacter
{
  public:
    SoundPlaybackHandle PlayHUDSound(const char* apSound, int a2, int a3, int a4);
};

struct HUDTimerStub
{
    unsigned int GetTime();
};

int FUN_00408b20(const char* a, const char* b);
extern HUDMainMenu* HUDMainMenu_pme;
extern PlayerCharacter* _g_thePlayer;
extern float g_fHUDMessageFadeTime;
extern const float g_fHUDMessageFadeEnd;

struct HUDMainMenuMessages : public HUDMainMenu
{
    void FUN_007756e0();
};

typedef BSSimpleList<HUDMainMenu__MessageData*> MessageList;

// @fnv 0x007756e0
void HUDMainMenuMessages::FUN_007756e0()
{
    if (((MessageList*)m_kMessageList)->IsEmpty())
        return;
    MessageList* pIter = (MessageList*)m_kMessageList;
    while (pIter)
    {
        HUDMainMenu__MessageData* pMsg = pIter->GetItem();
        if (pMsg && !FUN_00408b20(pMsg->cMessage, ((TileStub*)HUDMainMenu_pme->m_pTiles[26])->GetString(0xfc4)))
        {
            HUDMainMenu__MessageData* pOld = pMsg;
            ((MessageList*)m_kMessageList)->Remove(pMsg);
            delete pOld;
            if (!((MessageList*)m_kMessageList)->IsEmpty())
            {
                if (((MessageList*)m_kMessageList)->GetItem()->cSoundPath[0])
                {
                    _g_thePlayer->PlayHUDSound(((MessageList*)m_kMessageList)->GetItem()->cSoundPath, 0, 0x121, 0);
                }
                ((TileStub*)HUDMainMenu_pme->m_pTiles[26])
                    ->Set(0xfc4, ((MessageList*)m_kMessageList)->GetItem()->cMessage, true);
                ((TileStub*)HUDMainMenu_pme->m_pTiles[25])
                    ->Set(0xfcc, ((MessageList*)m_kMessageList)->GetItem()->cIconPath, true);
                m_uiMessageCount = ((HUDTimerStub*)m_cBuffer)->GetTime();
            }
            else
            {
                ((TileStub*)HUDMainMenu_pme->m_pTiles[26])
                    ->GradualSetFloat(0xfa9, g_fHUDMessageFadeTime, 0.0f, g_fHUDMessageFadeEnd, 0);
                ((TileStub*)HUDMainMenu_pme->m_pTiles[25])
                    ->GradualSetFloat(0xfa9, g_fHUDMessageFadeTime, 0.0f, g_fHUDMessageFadeEnd, 0);
                ((TileStub*)HUDMainMenu_pme->m_pTiles[27])
                    ->GradualSetFloat(0xfa9, g_fHUDMessageFadeTime, 0.0f, g_fHUDMessageFadeEnd, 0);
                m_uiMessageCount = 0;
            }
            return;
        }
        pIter = pIter->GetNext();
    }
}
}  // namespace fnv_007756e0

namespace fnv_00778c20 {
extern const char str_01073500[];
struct IntSetting179
{
    int* FUN_0043d4d0();
};
extern IntSetting179 g_011d1d54, g_011d30d8, g_011d4d44;
extern IntSetting179 g_011d30f0, g_011d3c94, g_011d2bd4;
extern IntSetting179 g_011d3924, g_011d46cc, g_011d24f0;
struct TimeGlobal
{
    float FUN_0084d030();
    unsigned int GetTimeStamp();
};
extern TimeGlobal DAT_011f6394;
extern float DAT_011d979c;
int TraitNameToIDAdd(const char*, int);
int FUN_0077f9c0(int);
float LinearInterpolate(float, float, float, float, float);
struct Tile179
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
};
// @fnv 0x00778c20
void FUN_00778c20(Tile179* tile, float value, float limit)
{
    static int trait = TraitNameToIDAdd(str_01073500, -1);
    int actual = FUN_0077f9c0(*g_011d1d54.FUN_0043d4d0());
    int lower = FUN_0077f9c0(*g_011d30d8.FUN_0043d4d0());
    int low = FUN_0077f9c0(*g_011d4d44.FUN_0043d4d0());
    if (value > actual)
        value = (float)actual;
    else if (value < lower)
        value = (float)lower;
    float state;
    bool rate = value < low;
    float high;
    float alpha = tile->FUN_00a011b0(trait);
    state = 0.0f;
    if (rate)
        state = LinearInterpolate((float)*g_011d3c94.FUN_0043d4d0(), (float)*g_011d30f0.FUN_0043d4d0(), (float)low,
                                  (float)lower, value);
    else
        state = LinearInterpolate((float)*g_011d2bd4.FUN_0043d4d0(), (float)*g_011d3c94.FUN_0043d4d0(), (float)actual,
                                  (float)low, value);
    float middle = 0.0f;
    if (alpha == 0.0)
        middle = DAT_011d979c != 0.0
                     ? tile->FUN_00a011b0(4009) + state * limit / DAT_011d979c * DAT_011f6394.FUN_0084d030()
                     : 0.0;
    else if (alpha == 1.0)
        middle = DAT_011d979c != 0.0
                     ? tile->FUN_00a011b0(4009) - state * limit / DAT_011d979c * DAT_011f6394.FUN_0084d030()
                     : 0.0;
    else if (alpha == 3.0)
        middle = DAT_011d979c;
    tile->FUN_00a012d0(4009, middle, true);
    high = tile->FUN_00a011b0(4009);
    if (high > limit)
    {
        tile->FUN_00a012d0(4009, limit, true);
        tile->FUN_00700320(trait, 3);
    }
    else if (high < 0.0)
    {
        float delay = 0.0f;
        if (rate)
            delay = LinearInterpolate((float)*g_011d46cc.FUN_0043d4d0(), (float)*g_011d3924.FUN_0043d4d0(), (float)low,
                                      (float)lower, value);
        else
            delay = LinearInterpolate((float)*g_011d24f0.FUN_0043d4d0(), (float)*g_011d46cc.FUN_0043d4d0(),
                                      (float)actual, (float)low, value);
        tile->FUN_00a012d0(4009, 0.0f, true);
        tile->FUN_00700320(trait, 0);
        tile->FUN_00a012d0(4110, DAT_011f6394.GetTimeStamp() + delay, true);
    }
    else if (tile->FUN_00a011b0(4110) < DAT_011f6394.GetTimeStamp() && alpha == 3.0)
    {
        tile->FUN_00700320(trait, 1);
    }
}
}  // namespace fnv_00778c20

namespace fnv_0077a650 {
#include <ctype.h>

struct QSound
{
    unsigned int id;
    bool success;
    unsigned int state;
    QSound();
    ~QSound();
    QSound& operator=(const QSound&);
    bool Play(bool);
};
struct QAudio
{
    QSound FUN_00ad7550(const char*, unsigned int);
};
QAudio* FUN_00453a70();
struct QSetting
{
    const char* FUN_00403df0();
    float* FUN_00403e20();
};
extern QSetting DAT_011d282c, DAT_011d27c0, DAT_011d237c, DAT_011d4d14, DAT_011d2688;
struct QTile
{
    int value;
    struct List
    {
        QTile** FUN_0073ac90();
        QTile** FUN_0073ac90(int);
        void* FUN_00559450();
        QTile*& FUN_0057cbe0(void*&);
    } children;
    void Set(int, int);
    void Set(int, float, bool);
    void Set(int, const char*, bool);
    void FUN_00715c60(int, unsigned int);
    float FUN_00a011b0(int);
    const char* FUN_00a011f0(int);
};
struct QName
{
    const char* FUN_00408da0();
};
struct QQuest
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28, field2c;
    QName name;
};
struct QEntry
{
    QQuest* quest;
    int kind;
    char title[260];
    char text[260];
    int alignment, field214, titleFont, textFont;
    char sound[260];
};
struct QManager
{
    QEntry* GetQuestNamesHead();
    bool FUN_0077b2c0();
    void FUN_0077b2e0();
};
extern QManager* DAT_011d96bc;
struct QInterface
{
    bool FUN_007023a0();
};
QInterface* FUN_004b7210();
bool FUN_00702680(int, unsigned int);
bool FUN_00703d50();
bool FUN_00702450(int);
struct QFlags
{
    unsigned int FUN_0044ddc0();
};
extern QFlags DAT_011f2250;
struct QTime
{
    unsigned int FUN_00825c00();
};
extern QTime DAT_011f6394;
bool FUN_007178a0();
float FUN_00715d40();
float FUN_007177c0();
struct QFont
{
    static QFont* FUN_005bd5b0();
    void GetStringDimensions(PointX*, const char*, int, float, int = 0);
};
void FUN_005b5e40(int, const char*, ...);
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_0044a670(const char*);
void FUN_0040fbe0(const char*, ...);
void FUN_00774800(QTile*, int);
extern const char DAT_0106f370[], DAT_01073700[], DAT_010736b0[], DAT_01073640[], DAT_01073624[];
struct QObjectives
{
    bool FUN_008256d0();
};
struct QHud : HUDMainMenu
{
    void UpdateQuestNotification();
    bool FUN_007735d0();
    bool FUN_00773650();
    void UpdateTileAnimations(Tile*);
    void UpdateQuestMenu(Tile*);
    void ResetWaitTiles();
};
// Shows the pending quest-notification entry: picks its sound, sets title/text tiles, lays out characters, then clears the entry and refreshes the HUD tiles.
// @fnv 0x0077a650
void QHud::UpdateQuestNotification()
{
    int aProcess;
    char aPoint4[260];
    int aOwnList;
    int aOverrideFlagA;
    float aOverrideFlag3;
    QTile* aLocation;
    PointX aData7;
    int aCount1;
    int aBy;
    unsigned int aAlternate;
    int aActor;
    int a6;
    int _unused;
    bool _y;
    if (!DAT_011d96c0 || m_eHudMenuMode == 7 || m_eHudMenuMode == 9 || m_eHudMenuMode == 8 ||
        DAT_011f6394.FUN_00825c00() - (unsigned int)DAT_011d96ac < 2000)
        return;
    _y = FUN_007178a0();
    if (!FUN_007735d0() && !DAT_011d96bc->FUN_0077b2c0() &&
        !(FUN_00773650() &&
          ((QTile*)HUDMainMenu_pme->m_pTiles[13])->children.FUN_0073ac90()[0]->FUN_00a011b0(4009) != 0.0) &&
        (!FUN_004b7210()->FUN_007023a0() || FUN_00702680(1009, 0) || FUN_00703d50()) && !DAT_011f2250.FUN_0044ddc0())
    {
        m_bQuestObjectiveUpdatePending = true;
        QEntry* aShared;
        QSound aRepair;
        if (DAT_011d96bc->GetQuestNamesHead()->kind == 0)
            aRepair = FUN_00453a70()->FUN_00ad7550(DAT_0106f370, 289);
        else if (DAT_011d96bc->GetQuestNamesHead()->kind == 3)
            aRepair = FUN_00453a70()->FUN_00ad7550(DAT_011d96bc->GetQuestNamesHead()->sound, 289);
        else
            aRepair = FUN_00453a70()->FUN_00ad7550(DAT_01073700, 289);
        aRepair.Play(false);
        aBy = 0;
        aAlternate = DAT_011f6394.FUN_00825c00();
        aLocation = ((QTile*)HUDMainMenu_pme->m_pTiles[14])->children.FUN_0073ac90()[0];
        if (DAT_011d96bc->GetQuestNamesHead()->kind == 0)
            aLocation->Set(4036, DAT_011d282c.FUN_00403df0(), true);
        else if (DAT_011d96bc->GetQuestNamesHead()->kind == 2)
            aLocation->Set(4036, DAT_011d27c0.FUN_00403df0(), true);
        else if (DAT_011d96bc->GetQuestNamesHead()->kind == 1)
            aLocation->Set(4036, DAT_011d237c.FUN_00403df0(), true);
        else if (DAT_011d96bc->GetQuestNamesHead()->kind == 3)
            aLocation->Set(4036, DAT_011d96bc->GetQuestNamesHead()->title, true);
        else
            FUN_005b5e40(7, DAT_010736b0, DAT_011d96bc->GetQuestNamesHead()->kind);
        aLocation->Set(4003, 1);
        aLocation->Set(4009, 0);
        aActor = 7;
        if (DAT_011d96bc->GetQuestNamesHead()->kind == 3 && DAT_011d96bc->GetQuestNamesHead()->titleFont != -1)
            aActor = DAT_011d96bc->GetQuestNamesHead()->titleFont;
        aLocation->Set(4025, aActor);
        {
            PointX aImpact;
            QFont::FUN_005bd5b0()->GetStringDimensions(&aImpact, aLocation->FUN_00a011f0(4036),
                                                (int)aLocation->FUN_00a011b0(4025), aLocation->FUN_00a011b0(4026), 0);
            aBy = (int)aImpact.x;
            aLocation->Set(4002, (float)-(aImpact.y + 15.0), true);
            a6 = 1;
            aOverrideFlag3 = 0.0f;
            aProcess = (int)FUN_00715d40();
            aCount1 = (int)FUN_007177c0();
            _unused = aProcess - 2 * aCount1;
            if (DAT_011d96bc->GetQuestNamesHead()->kind == 3)
            {
                switch (DAT_011d96bc->GetQuestNamesHead()->alignment)
                {
                case 0:
                    a6 = 1;
                    aOverrideFlag3 = 0.0f;
                    break;
                case 1:
                    a6 = 2;
                    aOverrideFlag3 = 0.5f;
                    break;
                case 2:
                    a6 = 4;
                    aOverrideFlag3 = 1.0f;
                    break;
                default:
                    FUN_005b5e40(7, DAT_01073640, DAT_011d96bc->GetQuestNamesHead()->alignment, 0);
                    a6 = 1;
                    aOverrideFlag3 = 0.0f;
                    break;
                }
                aLocation->Set(4001, (_unused - aBy / 2) * aOverrideFlag3, true);
                aLocation->Set(4023, a6);
            }
            aLocation->FUN_00715c60(4100, aAlternate);
            aLocation->Set(4101, (float)(aAlternate + *DAT_011d4d14.FUN_00403e20() * 1000.0), true);
            FUN_00774800(aLocation, 0);
            if (DAT_011d96bc->GetQuestNamesHead()->kind == 1)
                ResetWaitTiles();

            {
                int aGy;
                void* aInv;
                if (DAT_011d96bc->GetQuestNamesHead()->kind == 3)
                    FUN_00406d30(aPoint4, 260, DAT_011d96bc->GetQuestNamesHead()->text);
                else
                    FUN_00406d30(aPoint4, 260, DAT_011d96bc->GetQuestNamesHead()->quest->name.FUN_00408da0());
                for (unsigned int i = 0; i < 260; i++)
                    aPoint4[i] = (char)toupper(aPoint4[i]);
                aGy = 32;
                aOwnList = FUN_0044a670(aPoint4);
                if (aOwnList >= 32)
                    for (int i = 32; i >= 0; i--)
                        if (aPoint4[i] == ' ')
                        {
                            aGy = i;
                            break;
                        }
                aActor = 8;
                if (DAT_011d96bc->GetQuestNamesHead()->kind == 3 && DAT_011d96bc->GetQuestNamesHead()->textFont != -1)
                    aActor = DAT_011d96bc->GetQuestNamesHead()->textFont;
                QFont::FUN_005bd5b0()->GetStringDimensions(&aData7, aPoint4, aActor, DAT_01016970, 0);
                aOverrideFlagA = (int)((_unused - (1.0f + aOverrideFlag3) * aData7.x) * aOverrideFlag3);
                aInv = ((QTile*)HUDMainMenu_pme->m_pTiles[14])->children.FUN_00559450();
                {
                    QTile* aEffect;
                    if (aInv)
                        aEffect = ((QTile*)HUDMainMenu_pme->m_pTiles[14])->children.FUN_0057cbe0(aInv);
                    for (int index = 0; aPoint4[index]; index++)
                    {
                        QTile* tile = 0;
                        {
                            if (aInv)
                                tile = ((QTile*)HUDMainMenu_pme->m_pTiles[14])->children.FUN_0057cbe0(aInv);
                            else
                                continue;
                            char character[2];
                            {
                                character[0] = aPoint4[index];
                                character[1] = 0;
                                if (aGy + 1 == index)
                                    aOverrideFlagA =
                                        (int)((_unused - (1.0f + aOverrideFlag3) * aData7.x) * aOverrideFlag3);
                                tile->Set(4025, aActor);
                                tile->Set(4036, character, true);
                                tile->Set(4003, 1);
                                tile->Set(4009, 0);
                                tile->Set(4001, aOverrideFlagA);
                                PointX size;
                                QFont::FUN_005bd5b0()->GetStringDimensions(&size, character, (int)tile->FUN_00a011b0(4025),
                                                                    tile->FUN_00a011b0(4026), 0);
                                if (index <= aGy)
                                    tile->Set(4002, 0);
                                else
                                    tile->Set(4002, (float)(size.y + 5.0), true);
                                aAlternate += (unsigned int)(*DAT_011d2688.FUN_00403e20() * 1000.0);
                                tile->FUN_00715c60(4100, aAlternate);
                                tile->Set(4101, (float)(aAlternate + *DAT_011d4d14.FUN_00403e20() * 1000.0), true);
                                FUN_0040fbe0(DAT_01073624, tile->FUN_00a011f0(4036),
                                             aAlternate + *DAT_011d4d14.FUN_00403e20() * 1000.0);
                                FUN_00774800(tile, 0);
                                aOverrideFlagA += (int)size.x;
                                if (tile->FUN_00a011b0(4001) + size.x > aBy)
                                    aBy = (int)(tile->FUN_00a011b0(4001) + size.x);
                            }
                        }
                    }
                }
            }
        }
        aShared = DAT_011d96bc->GetQuestNamesHead();
        delete aShared;
        DAT_011d96bc->FUN_0077b2e0();
        UpdateTileAnimations(HUDMainMenu_pme->m_pTiles[14]);
    }
    if (FUN_007735d0())
        UpdateTileAnimations(HUDMainMenu_pme->m_pTiles[14]);
    else if (!FUN_00702450(1048))
    {
        if ((FUN_00773650() || !((QObjectives*)m_kQuestObjectives)->FUN_008256d0()) && !FUN_007735d0())
            UpdateQuestMenu(HUDMainMenu_pme->m_pTiles[13]);
    }
}
}  // namespace fnv_0077a650

namespace fnv_0077b300 {
struct Pt3
{
    float x;
    float y;
    float z;
    Pt3 operator-(const Pt3& o) const;
    float Length() const;
};
namespace std {
float abs(float f);
}
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
    virtual Pt3* GetPos();
};

// Compares the distances from the player to the positions of two RefX objects, returning 1, -1 or 0.
// @fnv 0x0077b300
int __cdecl FUN_0077b300(RefX** apRefA, RefX** apRefB)
{
    if (apRefA && *apRefA && apRefB && *apRefB)
    {
        Pt3 playerPos4 = *((RefX*)g_thePlayer)->GetPos();
        Pt3 posA = *(*apRefA)->GetPos();
        float distA_ = std::abs((posA - playerPos4).Length());
        Pt3 posB2 = *(*apRefB)->GetPos();
        float distB7 = std::abs((posB2 - playerPos4).Length());
        if (distA_ > distB7)
            return 1;
        if (distA_ < distB7)
            return -1;
    }
    return 0;
}
}  // namespace fnv_0077b300

namespace fnv_0077c170 {
struct AnimatedTile;
struct TileList
{
    void* GetHeadPos() const;
    AnimatedTile*& GetNext(void*& position);
};
struct AnimatedTile
{
    int tileType;
    TileList children;
    float FUN_00a011b0(int id);
    const char* FUN_00a011f0(int id);
    void FUN_00a012d0(int id, float value, bool propagate);
    void FUN_00700320(int id, int value);
    void FUN_00707e10(const char* name);
    void StartFade(int id, float start, float end, float duration, int mode);
    float GetTraitFloat(int id);
};
extern SettingX DAT_011d2238;
extern SettingX DAT_011d9774;
extern SettingX DAT_011d4f30;
extern const char str_01073724[];
int __cdecl TraitNameToID(const char* name);
struct TileAnimationUpdater
{
    void UpdateTileAnimations(AnimatedTile* root);
};
// @fnv 0x0077c170
void TileAnimationUpdater::UpdateTileAnimations(AnimatedTile* pRootTile)
{
    if (pRootTile->FUN_00a011b0(0xfb6) > 0.0)
    {
        void* tile = ((AnimatedTile*)HUDMainMenu_pme->m_pTiles[13])->children.GetHeadPos();
        AnimatedTile* pChild = 0;
        while (tile)
        {
            pChild = ((AnimatedTile*)HUDMainMenu_pme->m_pTiles[13])->children.GetNext(tile);
            if (pChild)
            {
                pChild->FUN_00a012d0(0xfa9, 0.0f, true);
                pChild->FUN_00700320(TraitNameToID(str_01073724), 0);
            }
        }
        tile = pRootTile->children.GetHeadPos();
        pChild = 0;
        while (tile)
        {
            pChild = pRootTile->children.GetNext(tile);
            if (pChild && pChild->FUN_00a011b0(0x1004) > 0.0 &&
                (unsigned int)g_timeGlobal.GetSection() > pChild->FUN_00a011b0(0x1004))
            {
                pChild->FUN_00707e10(pChild->FUN_00a011f0(0xfc4));
                pChild->StartFade(0xfa9, 0.0f, (float)(255.0 * *DAT_011d9774.Float()), *DAT_011d2238.Float(), 0);
                pChild->FUN_00700320(0x1004, 0);
            }
            else if (pChild && pChild->FUN_00a011b0(0x1005) > 0.0 &&
                     (unsigned int)g_timeGlobal.GetSection() > pChild->FUN_00a011b0(0x1005))
            {
                pChild->StartFade(0xfa9, pChild->FUN_00a011b0(0xfa9) > 175.0 ? pChild->FUN_00a011b0(0xfa9) : 175.0f,
                                  0.0f, *DAT_011d4f30.Float(), 0);
                pChild->FUN_00700320(0x1005, 0);
            }
            else if (pChild && pChild->GetTraitFloat(0xfa9) == 0.0 && pChild->FUN_00a011b0(0xfa9) == 0.0 &&
                     pChild->FUN_00a011b0(0x1005) == 0.0)
            {
                pChild->FUN_00700320(0xfa3, 0);
            }
        }
    }
}
}  // namespace fnv_0077c170

struct BreathPoint
{
    float x, y, z;
};
struct BreathProcess
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
    virtual float GetBreath();
};
struct BreathPlayer
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual BreathPoint* GetPosition();
    void* GetContainingCell();
    float Calculate(float, void*);
    float GetValue();
    BreathProcess* GetProcess();
};
extern BreathPlayer* breathPlayer;
float __cdecl MaxBreath(int);
extern float DAT_011d979c;
extern const float DAT_01016248;
struct BreathUpdate
{
    float time;
    bool controllers;
    bool threaded;
    int flags;
    BreathUpdate(float, bool, bool);
};
struct BreathObject
{
    void Update(BreathUpdate&);
};
struct BreathNode
{
    BreathObject* Child(int);
};
struct BreathTile
{
    float Get(int);
    void Animate(int, float, float, float, int);
    bool IsAnimating(int);
    BreathNode* Node();
};
struct BreathSequence
{
    float Start();
    float End();
    void Set(float, bool);
};
struct BreathHUD
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
    BreathTile* tile;
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
    BreathSequence* sequence;
    void FUN_0077e4f0();
};
// @fnv 0x0077e4f0
void BreathHUD::FUN_0077e4f0()
{
    float aWater = breathPlayer->Calculate(breathPlayer->GetPosition()->z, breathPlayer->GetContainingCell());
    bool submergedA = aWater >= 0.009999999776482582;
    bool deep4 = aWater >= 0.875;
    float aMaximum = MaxBreath((int)breathPlayer->GetValue());
    float fraction = breathPlayer->GetProcess() ? breathPlayer->GetProcess()->GetBreath() / aMaximum : 100.0;
    float visible = tile->Get(4009);
    if (deep4)
    {
        if (visible == 0.0)
            tile->Animate(4009, 0.0f, DAT_011d979c, DAT_01016248, 0);
    }
    else if (visible > 0.0 && tile->IsAnimating(4009))
    {
        tile->Animate(4009, DAT_011d979c, 0.0f, DAT_01016248, 0);
    }
    if (sequence && visible > 0.0)
    {
        BreathUpdate update(0.0f, true, false);
        sequence->Set(sequence->Start() + fraction * (sequence->End() - sequence->Start()), false);
        tile->Node()->Child(0)->Update(update);
    }
}

namespace fnv_0077e750 {
struct CompassBase
{
    void* FUN_004fd3c0();
    float FUN_0045cd80();
};
struct CompassReference : TESForm
{
    bool FUN_00576d30();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_0077eac0();
    CompassBase* FUN_004181e0();
};
struct CompassArray
{
    unsigned int FUN_005de0f0();
    unsigned int FUN_005be5c0();
    CompassReference* FUN_00968670();
};
struct CompassArrayOwner
{
    CompassArray* FUN_00717e50(unsigned int);
};
extern CompassArrayOwner g_011e0e80;
extern CompassReference* g_011dea3c;
struct CompassSetting
{
    float* FUN_00403e20();
};
extern CompassSetting g_011d45dc;
extern CompassSetting g_011d9774;
struct CompassUpdate
{
    float time;
    bool updateControllers;
    bool multithreaded;
    int flags;
    void FUN_0043d410(float, bool, bool);
};
struct CompassNode
{
    void FUN_006404b0(float, float, float, float);
    void FUN_00a59c60(CompassUpdate&);
};
struct CompassTile
{
    bool FUN_00a07fc0(int);
    float FUN_00a011b0(int);
    void StartFade(int, float, float, float, bool);
    CompassNode* FUN_0056c7f0();
};
struct CompassTileList
{
    void* FUN_00559450();
    CompassTile*& FUN_0057cbe0(void*&);
};
struct CompassTileOwner
{
    int flags;
    CompassTileList tiles;
};
struct CompassPoint
{
    float x, y, z;
    CompassPoint operator-(const CompassPoint&) const;
    double FUN_00457990();
};
float __cdecl GetDirectionAngle(const CompassPoint&);
struct CompassCameraModel
{
    CompassPoint FUN_0045bba0();
};
struct CompassCamera
{
    CompassCameraModel* FUN_006629f0();
};
struct CompassHUD : HUDMainMenu
{
    void UpdateCompassMarkers();
};
// @fnv 0x0077e750
void CompassHUD::UpdateCompassMarkers()
{
    CompassReference* reference_2 = 0;
    CompassTile* h;
    void* position = ((CompassTileOwner*)m_pTiles[73])->tiles.FUN_00559450();
    for (unsigned int index = g_011e0e80.FUN_00717e50(0)->FUN_005de0f0();
         index < g_011e0e80.FUN_00717e50(0)->FUN_005be5c0(); ++index)
    {
        reference_2 = g_011e0e80.FUN_00717e50(index)->FUN_00968670();
        if (reference_2 && !reference_2->FUN_00576d30() && !reference_2->FUN_00440d80() &&
            !reference_2->FUN_00440da0() && reference_2->GetFormType() == 62 && reference_2->IsCreature())
        {
            if (reference_2 && !reference_2->FUN_0077eac0() && reference_2->FUN_004181e0()->FUN_004fd3c0() &&
                reference_2->FUN_004181e0()->FUN_0045cd80() == 0.0 &&
                (*(CompassPoint*)reference_2->GetPos() - *(CompassPoint*)g_011dea3c->GetPos()).FUN_00457990() <
                    *g_011d45dc.FUN_00403e20())
            {
                if (position)
                {
                    h = ((CompassTileOwner*)m_pTiles[73])->tiles.FUN_0057cbe0(position);
                    if (h->FUN_00a07fc0(4009) && h->FUN_00a011b0(4009) == 0.0)
                        h->StartFade(4009, 0.0f, (float)(*g_011d9774.FUN_00403e20() * 255.0), 0.5f, false);
                }
                else
                {
                    continue;
                }
                float angle2 =
                    GetDirectionAngle(*(CompassPoint*)reference_2->GetPos() - *(CompassPoint*)g_011dea3c->GetPos());
                float angle5 = GetDirectionAngle(((CompassCamera*)FUN_0045c670())->FUN_006629f0()->FUN_0045bba0());
                h->FUN_0056c7f0()->FUN_006404b0(angle5 - angle2, 0.0f, 1.0f, 0.0f);
                CompassUpdate updated5;
                updated5.FUN_0043d410(0.0f, true, false);
                h->FUN_0056c7f0()->FUN_00a59c60(updated5);
            }
        }
    }
    while (position)
    {
        CompassTile* remaining = ((CompassTileOwner*)m_pTiles[73])->tiles.FUN_0057cbe0(position);
        if (remaining->FUN_00a07fc0(4009) && remaining->FUN_00a011b0(4009) > 0.0)
            remaining->StartFade(4009, remaining->FUN_00a011b0(4009), 0.0f, 0.5f, false);
    }
}
}  // namespace fnv_0077e750

namespace fnv_0077eaf0 {
// UpdateStatsMenu v01 - full one-pass transcription from packet decode, worker8
struct Node77
{
    Node77* FUN_00726070();
};
struct ScriptObj
{
    int FUN_0055b980();
};
void** __fastcall _ref_006815c0(void*);
int __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
extern double _gModifierZero;
extern float DAT_011d979c;
extern const char* DAT_011a00c4[];
extern const char str_01073868[];
struct Tile77
{
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
    void StartFade(int, float, float, float, int);
};
struct FirstSrc
{
    virtual void firstSlot0();
    virtual void firstSlot1();
    virtual Node77* GetFirst();
};
struct AVSrc
{
    virtual void avSlot0();
    virtual void avSlot1();
    virtual void avSlot2();
    virtual float GetCurrent(int);
    virtual void avSlot4();
    virtual void avSlot5();
    virtual void avSlot6();
    virtual void avSlot7();
    virtual float GetBase(int);
};
struct PlayerC
{
    int m_00[37];
    FirstSrc m_94;
    int m_98[3];
    AVSrc m_av;
};
extern PlayerC* DAT_011dea3c;
struct MenuC
{
    int m_00[10];
    Tile77* m_tiles[52];
    Tile77* m_face;
    void UpdateStatsMenu();
};
// @fnv 0x0077eaf0
void MenuC::UpdateStatsMenu()
{
    char buf[260];
    int result = 0;
    {
        int val;
        Node77* mag;
        float condition;
        float d;
        int t;
        float state;
        for (mag = DAT_011dea3c->m_94.GetFirst(); mag && *_ref_006815c0(mag); mag = mag->FUN_00726070())
        {
            if (((ScriptObj*)*_ref_006815c0(mag))->FUN_0055b980() == 10)
                result = 10;
        }
        if (result == 0)
        {
            condition = DAT_011dea3c->m_av.GetBase(0x10);
            d = condition - DAT_011dea3c->m_av.GetCurrent(0x10);
            result = (int)((d / condition) * 5.0);
            if (result < 0)
                result = 0;
            if (result > 4)
                result = 4;
        }
        FUN_00406d00(buf, 0x104, str_01073868, result);
        m_face->FUN_00a01350(0xfcc, buf, true);
        m_face->StartFade(0xfa9, 0.0f, DAT_011d979c, 5.0f, 4);
        val = 0x35;
        for (t = 0x19; t < 0x1f; ++t, ++val)
        {
            state = DAT_011dea3c->m_av.GetCurrent(t) / 100.0;
            FUN_00406d00(buf, 0x104,
                         state > _gModifierZero ? "Interface\\Stats\\%s.dds" : "Interface\\Stats\\%s_broken.dds",
                         DAT_011a00c4[t]);
            m_tiles[val]->FUN_00a01350(0xfcc, buf, true);
            if (state == _gModifierZero)
            {
                m_tiles[val]->FUN_00700320(0xff4, 2);
                m_tiles[val]->StartFade(0xfa9, 0.0f, DAT_011d979c, 5.0f, 3);
            }
            else
            {
                m_tiles[val]->FUN_00700320(0xff4, 1);
                m_tiles[val]->StartFade(0xfa9, 0.0f, DAT_011d979c, 5.0f, 4);
            }
        }
    }
}
}  // namespace fnv_0077eaf0

namespace fnv_0077f0d0 {
extern float g_fUpdate_011a0140;

struct FaceAnimData_0077f0d0
{
    void IncRefCount();
    void DecRefCount();
};

struct SceneNode_0077f0d0
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
    virtual void AttachNode(NiNode* apNode, int aiFlag);
    int IsAttached();
};

struct Renderer_0077f0d0
{
    void SetMode(int, int);
};

struct SceneGraphRoot_0077f0d0
{
    void Begin(int);
    void SetCamera(NiNode*);
    void End();
};

struct FaceGenNode_0077f0d0
{
    SceneGraphRoot_0077f0d0* GetRoot();
    FaceAnimData_0077f0d0* GetAnimData();
};

struct IfaceMgr_0077f0d0
{
    NiNode* GetNode();
};

extern NiPointer<NiNode> g_011d9770;
extern NiPointer<FaceAnimData_0077f0d0> g_011d975c;
extern HUDMainMenu* HUDMainMenu_pme;

SceneNode_0077f0d0* __cdecl GetSceneNode_0077f0d0(int);
Renderer_0077f0d0* __cdecl GetRenderer_0077f0d0();
FaceGenNode_0077f0d0* __cdecl GetFaceGen_0077f0d0();
IfaceMgr_0077f0d0* __cdecl GetIfaceMgr_0077f0d0();
void __cdecl Update_0077f0d0(FaceAnimData_0077f0d0*, float);
void __cdecl RenderA_0077f0d0(FaceAnimData_0077f0d0*, SceneNode_0077f0d0*, SceneGraphRoot_0077f0d0*);
void __cdecl RenderB_0077f0d0(FaceAnimData_0077f0d0*, NiNode*, int);

// Attaches the face node to scene node 1 if needed, begins the face-gen scene graph, updates and renders the face animation data, then ends the scene.
// @fnv 0x0077f0d0
void RenderFaceGenScene()
{
    if (!g_011d9770 || (HUDMainMenu_pme && !HUDMainMenu_pme->m_bHudModeActive))
        return;
    if (!GetSceneNode_0077f0d0(1)->IsAttached())
        GetSceneNode_0077f0d0(1)->AttachNode(g_011d9770, 1);
    GetRenderer_0077f0d0()->SetMode(0, 4);
    FaceGenNode_0077f0d0* pFaceGen5 = GetFaceGen_0077f0d0();
    SceneGraphRoot_0077f0d0* pRoot4 = pFaceGen5->GetRoot();
    pRoot4->Begin(1);
    FaceAnimData_0077f0d0* pGlobalForm = g_011d975c;
    Update_0077f0d0(pGlobalForm, g_fUpdate_011a0140);
    NiPointer<NiNode> m_pController(GetIfaceMgr_0077f0d0()->GetNode());
    pRoot4->SetCamera(m_pController);
    FaceAnimData_0077f0d0* pData = pGlobalForm ? pGlobalForm : pFaceGen5->GetAnimData();
    RenderA_0077f0d0(pData, GetSceneNode_0077f0d0(1), pRoot4);
    RenderB_0077f0d0(pData, m_pController, 0);
    pRoot4->SetCamera(0);
    m_pController = 0;
    pRoot4->End();
}
}  // namespace fnv_0077f0d0

namespace fnv_0077f270 {
struct Node_77f270
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
    virtual void DetachChild58(void* child);
    void* FUN_0045bc00(unsigned int idx);
    void* GetAt(unsigned int idx);
};

struct Ptr_77f270
{
    Node_77f270* m_pObject;
    operator Node_77f270*() const;
    Node_77f270* operator->() const;
};

struct HUD_77f270
{
    int unk[127];
    bool b1fc;
};

extern Ptr_77f270 g_011d9770;

// If HUDMainMenu_pme and g_011d9770 exist and the node has a child at index 0, detaches that child and clears b1fc on the HUD menu.
// @fnv 0x0077f270
void __cdecl FUN_0077f270()
{
    if (HUDMainMenu_pme && (Node_77f270*)g_011d9770 && ((Node_77f270*)g_011d9770)->FUN_0045bc00(0))
    {
        ((Node_77f270*)g_011d9770)->DetachChild58(((Node_77f270*)g_011d9770)->GetAt(0));
        ((HUD_77f270*)HUDMainMenu_pme)->b1fc = false;
    }
}
}  // namespace fnv_0077f270

struct xSize
{
    float x, y, z;
};
struct xTile
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
    bool IsTraitNonZero(int);
    void FUN_00707e10(const char*);
    const char* FUN_00a011f0(int);
    void StartFade(int, float, float, float, int);
    bool FUN_00a07fc0(int);
};
struct xTileList
{
    void* FUN_00559450();
    xTile*& FUN_0057cbe0(void*&);
    void* FUN_00726070();
    xTile*& FUN_00683520(void*&);
    xTile*& FUN_0073ac90();
};
struct xHolder
{
    int m_iWordAt00;
    xTileList m_iWordAt04;
};
struct xPME
{
    int m_auiShapeKeys[0x5c / 4];
    xHolder* m_5c;
};
extern xPME* xg_pme_11d96c0;
struct xQObj
{
    char m_pText[0x104];
    bool m_104;
    bool m_105;
};
struct xQNode
{
    bool FUN_008256d0();
    xQObj** FUN_006815c0();
    xQNode* FUN_00726070();
    void FUN_00905330(xQObj**);
    void* m_iWordAt00;
    void* m_iWordAt04;
};
struct xFontMgr
{
    static xFontMgr* FUN_005bd5b0();
    xSize GetStringDimensions(const char*, int, float, int);
};
struct xSound
{
    ~xSound();
    bool Play(bool);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xAudio
{
    static xAudio* FUN_00453a70();
    xSound FUN_00ad7550(const char*, unsigned int);
};
struct xStrSetting
{
    const char* FUN_00403df0();
};
struct xFltSetting
{
    float* FUN_00403e20();
};
extern xStrSetting xg_s_11d1d60;
extern xFltSetting xg_f_11d4cc0, xg_f_11d3b68, xg_f_11d2b5c, xg_f_11d2724, xg_f_11d2c94;
extern float xg_f_11d979c;
double xF715d40();
int xFa01860(const char*);
void xF774800(xTile*, int);
int xFa00940(const char*, int);
int xStrcpy(char*, unsigned int, const char*);
int xStrcat(char*, unsigned int, const char*);
int xSprintf(char*, unsigned int, const char*, ...);

static const char s_szIsReminder[] = "_IsReminder";
static const char s_szFilled[] = "Interface\\Shared\\Marker\\glow_square_filled_small.dds";
static const char s_szSquare[] = "Interface\\Shared\\Marker\\glow_square_small.dds";
static const char s_szObjFmt[] = "obj_%d";
static const char s_szQuestUpdate[] = "UIQuestUpdate";
static const char s_szWaitComplete[] = "_WaitComplete";
static const char s_szHoldTime[] = "_HoldTime";
extern const char s_litEnd77b430[] = "";

struct xQuestMenu
{
    int m_auiShapeKeys[0x258 / 4];
    xQNode m_258;
    char m_260;
    bool m_261;
    bool FUN_00773650();
    void UpdateQuestMenu(xHolder*);
};

// Populates quest menu tiles from the quest node list, positions them, and drives their fade-in/out animations.
// @fnv 0x0077b430
void xQuestMenu::UpdateQuestMenu(xHolder* HOLDER)
{
    int qrEZrs = (int)xF715d40();
    bool qfTOqo = false;
    if (!FUN_00773650())
    {
        xQNode* qArxcFu = &m_258;
        void* qAhbO = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00559450();
        for (int SKIPA = 0; SKIPA < 0x1f; SKIPA++)
            xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_0057cbe0(qAhbO);
        void* qxQHW = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00726070();
        while (qArxcFu && !qArxcFu->FUN_008256d0() && qAhbO)
        {
            bool qHVMR = !FUN_00773650();
            bool qxWmVch =
                qHVMR ? false
                      : xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_0073ac90()->IsTraitNonZero(xFa01860(s_szIsReminder));
            bool qJDuOZ = (*qArxcFu->FUN_006815c0())->m_105;
            if (!qHVMR && qxWmVch && !qJDuOZ)
            {
                qArxcFu = qArxcFu->FUN_00726070();
                continue;
            }
            if (!qHVMR && !qxWmVch && qJDuOZ)
            {
                qArxcFu = qArxcFu->FUN_00726070();
                continue;
            }
            m_261 = true;
            qfTOqo = true;
            xTile* qQMZREG = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qAhbO);
            xTile* qDdzMIp = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qxQHW);
            if ((*qArxcFu->FUN_006815c0())->m_104)
            {
                char LINE[0x104];
                xStrcpy(LINE, 0x104, xg_s_11d1d60.FUN_00403df0());
                xStrcat(LINE, 0x104, (*qArxcFu->FUN_006815c0())->m_pText);
                qQMZREG->FUN_00a01350(0xfc4, LINE, true);
                qQMZREG->FUN_00700320(xFa01860(s_szIsReminder), qJDuOZ);
                qQMZREG->FUN_00700320(0x1007, 1);
                qDdzMIp->FUN_00a01350(0xfcc, s_szFilled, true);
            }
            else
            {
                qQMZREG->FUN_00a01350(0xfc4, (*qArxcFu->FUN_006815c0())->m_pText, true);
                qQMZREG->FUN_00700320(0x1007, 0);
                qQMZREG->FUN_00700320(xFa01860(s_szIsReminder), qJDuOZ);
                qDdzMIp->FUN_00a01350(0xfcc, s_szSquare, true);
            }
            qDdzMIp->FUN_00a012d0(0xfa1, qQMZREG->FUN_00a011b0(0xfa1) - 20.0, true);
            qDdzMIp->FUN_00700320(0xfa3, 1);
            qQMZREG->FUN_00700320(0xfb9, 7);
            qQMZREG->FUN_00700320(0xfa3, 1);
            qQMZREG->FUN_00700320(0xfa9, 0);
            qQMZREG->FUN_00700320(0xfba, qrEZrs / 3);
            int qaGEwZ = 0;
            char NAME[0x104];
            xSprintf(NAME, 0x104, s_szObjFmt, qaGEwZ++);
            qQMZREG->FUN_00707e10(NAME);
            xF774800(qQMZREG, 0);
            xAudio::FUN_00453a70()->FUN_00ad7550(s_szQuestUpdate, 0x121).Play(false);
            qArxcFu->FUN_00905330(qArxcFu->FUN_006815c0());
        }
    }
    if (qfTOqo)
    {
        void* qQGWBE = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00559450();
        void* qZWI = xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00726070();
        for (int SKIPB = 0; SKIPB < 0x1f; SKIPB++)
            xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qZWI);
        int qkJsUdT = 0;
        int qpia = 0;
        while (qQGWBE && qpia < 0x20)
        {
            qpia++;
            xTile* qXMUYT = HOLDER->m_iWordAt04.FUN_0057cbe0(qQGWBE);
            xTile* qIpA = HOLDER->m_iWordAt04.FUN_0057cbe0(qZWI);
            if (qXMUYT && qXMUYT->IsTraitNonZero(0xfa3))
            {
                qXMUYT->FUN_00700320(0xfa2, qkJsUdT);
                qIpA->FUN_00700320(0xfa2, qkJsUdT + 3);
                xSize SZ = xFontMgr::FUN_005bd5b0()->GetStringDimensions(
                    qXMUYT->FUN_00a011f0(0xfc4), (int)qXMUYT->FUN_00a011b0(0xfb9), qXMUYT->FUN_00a011b0(0xfba), 0);
                qkJsUdT += (int)SZ.y;
            }
        }
    }
    static int s_iWait = xFa00940(s_szWaitComplete, -1);
    void* qSVM = HOLDER->m_iWordAt04.FUN_00559450();
    void* qdqWL = HOLDER->m_iWordAt04.FUN_00726070();
    for (int SKIPC = 0; SKIPC < 0x1f; SKIPC++)
        xg_pme_11d96c0->m_5c->m_iWordAt04.FUN_00683520(qdqWL);
    int qpTd = 0;
    xTile* qpqRa[4];
    xTile* qsSDDgz[4];
    qpqRa[0] = 0;
    qpqRa[1] = 0;
    qpqRa[2] = 0;
    qpqRa[3] = 0;
    qsSDDgz[0] = 0;
    qsSDDgz[1] = 0;
    qsSDDgz[2] = 0;
    qsSDDgz[3] = 0;
    int qvyWyw = 0;
    while (qSVM && qpTd < 4 && qvyWyw < 0x20)
    {
        qvyWyw++;
        xTile* qbfQdhM = HOLDER->m_iWordAt04.FUN_0057cbe0(qSVM);
        xTile* qidnYUK = HOLDER->m_iWordAt04.FUN_0057cbe0(qdqWL);
        if (qbfQdhM->IsTraitNonZero(0xfa3))
        {
            if (qpTd > 0 && qpqRa[qpTd] == qsSDDgz[qpTd - 1])
                break;
            qsSDDgz[qpTd] = qidnYUK;
            qpqRa[qpTd] = qbfQdhM;
            qpTd++;
        }
    }
    if (qpqRa[0])
    {
        if (qpqRa[0]->FUN_00a011b0(s_iWait) == 0.0)
        {
            qpqRa[0]->FUN_00700320(s_iWait, 0);
            qpqRa[0]->StartFade(0xfa9, 0.0f, xg_f_11d979c, 0.5f, 0);
            qpqRa[0]->StartFade(s_iWait, 0.0f, 1.0f, *xg_f_11d4cc0.FUN_00403e20() * 3.0, 0);
            qsSDDgz[0]->StartFade(0xfa9, 0.0f, xg_f_11d979c, 0.5f, 0);
            if (qpqRa[1])
            {
                qpqRa[1]->StartFade(s_iWait, 0.0f, 1.0f, 1.0 * *xg_f_11d4cc0.FUN_00403e20(), 0);
                if (qpqRa[2])
                    qpqRa[2]->StartFade(s_iWait, 0.0f, 1.0f, 2.0 * *xg_f_11d4cc0.FUN_00403e20(), 0);
            }
        }
        else if (qpqRa[0]->FUN_00a011b0(s_iWait) == 1.0)
        {
            static int s_iHold = xFa00940(s_szHoldTime, -1);
            if (qpqRa[0]->FUN_00a011b0(s_iHold) == 0.0)
            {
                qpqRa[0]->FUN_00700320(s_iHold, 0);
                qpqRa[0]->StartFade(s_iHold, 0.0f, 1.0f, *xg_f_11d3b68.FUN_00403e20(), 0);
            }
            else if (qpqRa[0]->FUN_00a011b0(s_iHold) == 1.0)
            {
                qpqRa[0]->StartFade(0xfa9, xg_f_11d979c, 0.0f, *xg_f_11d2b5c.FUN_00403e20(), 0);
                qpqRa[0]->FUN_00700320(s_iWait, 2);
                qsSDDgz[0]->StartFade(0xfa9, xg_f_11d979c, 0.0f, *xg_f_11d2b5c.FUN_00403e20(), 0);
            }
        }
        else if (qpqRa[0]->FUN_00a07fc0(0xfa9) && qpqRa[0]->FUN_00a011b0(0xfa9) == 0.0)
        {
            if (qpqRa[1])
            {
                int qxDeKK = (int)(qpqRa[1]->FUN_00a011b0(0xfa2) - qpqRa[0]->FUN_00a011b0(0xfa2));
                qSVM = HOLDER->m_iWordAt04.FUN_00559450();
                xTile* qAXSCg = 0;
                if (qSVM)
                    qAXSCg = HOLDER->m_iWordAt04.FUN_0057cbe0(qSVM);
                while (qSVM)
                {
                    qAXSCg = HOLDER->m_iWordAt04.FUN_0057cbe0(qSVM);
                    qAXSCg->StartFade(0xfa2, qAXSCg->FUN_00a011b0(0xfa2), qAXSCg->FUN_00a011b0(0xfa2) - qxDeKK,
                                      *xg_f_11d2724.FUN_00403e20(), 0);
                }
            }
            if (qpqRa[3])
                qpqRa[3]->FUN_00700320(s_iWait, 1);
            qpqRa[0]->FUN_00700320(0xfa3, 0);
            qsSDDgz[0]->FUN_00700320(0xfa3, 0);
            qpqRa[0]->FUN_00700320(s_iWait, 0);
            qpqRa[0] = 0;
        }
        if (qpqRa[1] && qpqRa[1]->FUN_00a011b0(s_iWait) == 1.0 && qpqRa[1]->FUN_00a011b0(0xfa9) == 0.0)
        {
            qpqRa[1]->StartFade(0xfa9, 0.0f, xg_f_11d979c, *xg_f_11d2c94.FUN_00403e20(), 0);
            qsSDDgz[1]->StartFade(0xfa9, 0.0f, xg_f_11d979c, *xg_f_11d2c94.FUN_00403e20(), 0);
        }
        if (qpqRa[2] && qpqRa[2]->FUN_00a011b0(s_iWait) == 1.0 && qpqRa[2]->FUN_00a011b0(0xfa9) == 0.0)
        {
            qpqRa[2]->StartFade(0xfa9, 0.0f, xg_f_11d979c, *xg_f_11d2c94.FUN_00403e20(), 0);
            qsSDDgz[2]->StartFade(0xfa9, 0.0f, xg_f_11d979c, *xg_f_11d2c94.FUN_00403e20(), 0);
        }
    }
}

#include <float.h>
struct TESAmmo : TESBoundObject
{
    const char* FUN_00772820();
};
struct AmmoPlayer;
struct AmmoWeapon;
struct AmmoInventory
{
    int FUN_004c8f30(TESBoundObject*);
};
AmmoInventory* AmmoGetInventory(AmmoPlayer*);
struct AmmoFlags
{
    bool FUN_00474a80();
};
struct AmmoWeapon
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
    AmmoFlags flags;
    int FUN_00446390();
    unsigned char GetByteAt102();
    float FUN_00709430(bool);
    int GetFlaggedValue(bool);
    TESBoundObject* FUN_00525980(AmmoPlayer*);
    bool FUN_006450c0();
    int GetModdedValue(bool);
};
struct AmmoExtra
{
    AmmoWeapon* FUN_0044ddc0();
    bool HasEffect(int);
    float FUN_004bcdb0(int);
};
struct AmmoData
{
    TESBoundObject* FUN_0044ddc0();
    int FUN_00726070();
};
struct AmmoProvider
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
    virtual AmmoExtra* GetLoadedForm();
    virtual AmmoData* GetAmmo();
};
struct AmmoPlayer
{
    AmmoProvider* FUN_008d8520();
    int FUN_00969040();
};
struct AmmoSetting
{
    float* FUN_00403e20();
};
extern AmmoSetting ammoSetting;
extern AmmoPlayer* ammoPlayer;
struct AmmoTile
{
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, bool);
};
struct AmmoHUD
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
    AmmoTile* tiles[87];
    void ShiftTileValues(int);
    void UpdateAmmoHUD();
};
extern AmmoHUD* ammoHUD;
extern bool ammoNameShowing, ammoFlashDirection;
extern float ammoLastCurrent, ammoLastTotal, ammoLastCondition;
extern AmmoWeapon* ammoLastWeapon;
extern char ammoName[260], ammoSpecialName[260], ammoCountText[260];
extern const char ammoStringFormat[], ammoCountFormat[], ammoEmptyString[];
int AmmoFormat(char*, unsigned, const char*, ...);
void AmmoClamp(float*, float, float);
float AmmoMax(float, float);
float AmmoMin(float, float);
void AmmoAnimate(AmmoTile*, float, int, int, int);
// Updates ammo HUD tiles with ammo text, counts, and a condition bar animation using the current weapon and ammo data.
// @fnv 0x007721c0
void AmmoHUD::UpdateAmmoHUD()
{
    if (ammoPlayer && ammoPlayer->FUN_008d8520())
    {
        float flashTime_ = *ammoSetting.FUN_00403e20() * 255.0;
        AmmoExtra* extra9 = ammoPlayer->FUN_008d8520()->GetLoadedForm();
        static float timer = flashTime_;
        AmmoFormat(ammoName, 260, ammoStringFormat, ammoEmptyString);
        tiles[77]->FUN_00a01350(4036, ammoName, true);
        if (extra9)
        {
            AmmoWeapon* weapon5 = extra9->FUN_0044ddc0();
            float current4 = 0.0f;
            float total2 = 0.0f;
            switch (weapon5->FUN_00446390())
            {
            case 10:
            case 11:
            case 12:
            case 13:
                current4 = weapon5->GetByteAt102();
                total2 =
                    AmmoGetInventory(ammoPlayer)->FUN_004c8f30(reinterpret_cast<TESBoundObject*>(weapon5)) - current4;
                break;
            default: {
                AmmoData* data3 = ammoPlayer->FUN_008d8520()->GetAmmo();
                TESAmmo* ammo_ = 0;
                if (data3 && data3->FUN_0044ddc0())
                    ammo_ = dynamic_cast<TESAmmo*>(data3->FUN_0044ddc0());
                if (ammo_)
                {
                    const char* name = ammo_->FUN_00772820();
                    AmmoFormat(ammoSpecialName, 260, ammoStringFormat, name ? name : ammoEmptyString);
                    tiles[77]->FUN_00a01350(4036, ammoSpecialName, true);
                    if (name)
                    {
                        if (!ammoNameShowing)
                        {
                            ShiftTileValues(-50);
                            ammoNameShowing = true;
                        }
                    }
                    else if (ammoNameShowing)
                    {
                        ShiftTileValues(50);
                        ammoNameShowing = false;
                    }
                }
                bool useInventory5 = true;
                if (weapon5->FUN_00709430(extra9->HasEffect(6)) > 0.0)
                {
                    total2 = weapon5->GetFlaggedValue(extra9->HasEffect(2));
                    useInventory5 = false;
                }
                if (weapon5->FUN_00525980(ammoPlayer) && data3)
                {
                    current4 = data3->FUN_00726070();
                    if (useInventory5)
                        total2 =
                            AmmoGetInventory(ammoPlayer)->FUN_004c8f30(weapon5->FUN_00525980(ammoPlayer)) - current4;
                }
                else if (weapon5->flags.FUN_00474a80())
                {
                    current4 = ammoPlayer->FUN_00969040();
                    total2 = current4;
                }
            }
            break;
            }
            if (weapon5->FUN_006450c0())
                tiles[12]->FUN_00700320(4003, 0);
            else if (ammoLastCurrent != current4 || ammoLastTotal != total2 || ammoLastWeapon != weapon5)
            {
                AmmoFormat(ammoCountText, 260, ammoCountFormat, (int)current4, (int)total2);
                tiles[12]->FUN_00a01350(4036, ammoCountText, true);
                tiles[12]->FUN_00700320(4003, 1);
                ammoLastCurrent = current4;
                ammoLastTotal = total2;
            }
            if (ammoLastWeapon != weapon5)
            {
                tiles[9]->FUN_00700320(4003, 1);
                tiles[10]->FUN_00700320(4003, 1);
                tiles[11]->FUN_00700320(4003, 1);
                tiles[86]->FUN_00700320(4003, 1);
                ammoLastWeapon = weapon5;
                if (ammoNameShowing)
                    ShiftTileValues(50);
                ammoNameShowing = false;
            }
            float ammoValue2 = extra9->FUN_004bcdb0(0);
            float conditionA = extra9->FUN_004bcdb0(1);
            if (conditionA < 25.0)
            {
                AmmoClamp(&timer, 0.0f, flashTime_);
                if (timer == 0.0 || timer == flashTime_)
                    ammoFlashDirection = !ammoFlashDirection;
                if (ammoFlashDirection)
                    timer -= flashTime_ / 255.0 * 10.0;
                else
                    timer += flashTime_ / 255.0 * 10.0;
            }
            else
                timer = flashTime_;
            tiles[10]->FUN_00a012d0(4009, timer, true);
            if (ammoLastCondition != conditionA)
            {
                float value5 = extra9->FUN_004bcdb0(0);
                float base2 = weapon5->GetModdedValue(extra9->HasEffect(10));
                AmmoAnimate(tiles[10], AmmoMin(1.0f, AmmoMax(0.0f, value5 / base2)), 0, 0, ammoNameShowing ? -50 : 0);
                ammoLastCondition = conditionA;
            }
        }
        else
        {
            ammoLastCurrent = FLT_MIN;
            ammoLastTotal = FLT_MIN;
            ammoLastWeapon = 0;
            ammoLastCondition = FLT_MIN;
            ammoHUD->tiles[12]->FUN_00700320(4003, 0);
            tiles[10]->FUN_00700320(4003, 0);
            tiles[11]->FUN_00700320(4003, 0);
            ammoHUD->tiles[9]->FUN_00700320(4003, 0);
            tiles[86]->FUN_00700320(4003, 0);
        }
    }
}

#include <math.h>
namespace fnv_00779070 {
extern "C" float __cdecl fabsf(float);
struct CompassPoint
{
    float x, y, z;
    CompassPoint operator-(const CompassPoint& arPt) const;
    float Length() const;
};
struct CompassTile;
struct CompassInfo
{
    bool IsVisible();
    bool IsDiscovered();
    void SetDiscovered(bool abVal);
    void SetVisible(bool abVal);
    const char* GetName();
};
struct CompassProcess
{
    float GetAngleOffset();
    bool IsSneaking();
    bool IsActive();
};
struct CompassAV
{
    virtual void v0();
    virtual void v1();
    virtual int GetValue(int aiAV);
};
struct CompassList;
struct CompassRef
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
    virtual void SetFlag(unsigned int aFlag);
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
    virtual void* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const CompassPoint* GetPos();
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
    virtual bool IsDead(bool abCheck);
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
    virtual float GetAngleZ(int aiUnk);
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
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void RewardXP(int aiXP);
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
    CompassAV kAV;
    CompassProcess* GetProcess();
    CompassList* GetMapMarkers();
    CompassList* GetQuestTargets();
    CompassList* GetActorMarkers();
    CompassRef* GetPlacedMarker();
    bool IsDisabled();
    float GetMarkerRadius();
    int GetFormType();
};
struct CompassMarker
{
    CompassInfo* pInfo;
    CompassRef* pRef;
};
struct CompassQuestTarget
{
    CompassRef* GetTarget();
};
struct CompassActor
{
    CompassRef* pActor;
    bool m_bIsEnemy;
    bool bHidden;
};
struct CompassEvent
{
    CompassRef* pRef;
    bool bSkip;
    bool bNew;
};
struct CompassList
{
    void** Item();
    CompassList* Next();
    bool IsEmpty();
    unsigned int Count();
    void Sort(int(__cdecl* apFunc)(void*, void*));
};
struct CompassNode;
struct CompassTiles
{
    CompassNode* Head();
    CompassNode* QuestHead();
    TileX** NextTile(CompassNode** appIter);
    TileX** NextQuestTile(CompassNode** appIter);
};
struct CompassTileList
{
    int unk00;
    CompassTiles kTiles;
};
struct CompassArrow
{
    void SetRotation(float afRot, float afUnk);
};
struct CompassMode
{
    int GetMode();
};
struct CompassMovie
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual CompassArrow* GetArrow();
    CompassMode* GetModeObj();
};
struct CompassSetting
{
    float* Float();
    int* Int();
    bool* Bool();
    const char* String();
};
struct CompassFlags
{
    unsigned int Get();
};
extern CompassFlags DAT_011f2250;
extern CompassSetting DAT_011d9774, DAT_011d12cc, DAT_011d2208, DAT_011d0364, DAT_011d0bd8, DAT_011e07f0, DAT_011cd7d8,
    DAT_011cdcbc, DAT_011d32d0;
extern float DAT_011d979c;
extern bool DAT_011d96c4;
int __cdecl TraitNameToIDAdd(const char* apName, int aiUnk);
float __cdecl LinearInterpolate(float afMin, float afMax, float afFrom, float afTo, float afVal);
double __cdecl CompassMin(float afA, float afB);
float __cdecl ComputeObjectAngleDelta(CompassPoint aPos, CompassPoint aOrigin);
void __cdecl FUN_00778c20(TileX* apTile, float afDistance, float afAlpha);
void __cdecl UpdateMapMarkerHUD(CompassEvent* apEvent);
void __cdecl FUN_0076b960(const char*, const char*, int, int, int, int, const char*);
void __cdecl FUN_005f5950(int, int, CompassRef*, CompassRef*, int, int, int);
void __cdecl FUN_004d5c60(bool abVal);
int __cdecl FUN_0077b300(void*, void*);
void __cdecl FUN_005e58f0(int aiPerk, CompassRef* apRef, float* apValue);

// Updates compass tile positions, visibility, and fade for map markers, quest targets, the player marker, and nearby actors.
// @fnv 0x00779070
void __cdecl FUN_00779070(CompassMovie* apMovie, CompassTileList* apMapTiles, CompassTileList* apQuestTiles,
                          CompassTileList* apActorTiles)
{
    static int iDistanceID = TraitNameToIDAdd("_Distance", -1);
    static int iHeadingID = TraitNameToIDAdd("_Heading", -1);
    static int iAlphaDownID = TraitNameToIDAdd("_AlphaDown", -1);
    float fAngleDeg =
        (((CompassRef*)DAT_011dea3c)->GetAngleZ(0) + ((CompassRef*)DAT_011dea3c)->GetProcess()->GetAngleOffset()) *
        57.2957763671875;
    float fRatio = LinearInterpolate(0, 1, 0, 360, fAngleDeg - (int)(fabsf(fAngleDeg) / 360.0) * 360);
    float fPathHeading = fRatio - 0.15000000596046448;
    if (apMovie->GetArrow())
        apMovie->GetArrow()->SetRotation(fPathHeading < 0.0 ? fPathHeading + 1.0 : fPathHeading, 0);
    CompassList* pEntryList = ((CompassRef*)DAT_011dea3c)->GetMapMarkers();
    CompassPoint kPt = *((CompassRef*)DAT_011dea3c)->GetPos();
    TileX* pTileElem = 0;
    float fFadeStart = HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList * 0.800000011920929 * 2.0;
    float m_fGlyphWidthInPixels = HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList * 2.0;
    float fAlpha = (!DAT_011f2250.Get() ? *DAT_011d9774.Float() : 1.0f) * 255.0;
    int iFlag = 1;
    CompassNode* pWalk = apMapTiles->kTiles.Head();
    CompassList* pLandmarkIterator = pEntryList;
    bool bOnce = true;
    bool bCompassReferenceDead = ((CompassRef*)DAT_011dea3c)->IsDead(false);
    int iFarDst = *DAT_011d12cc.Int();
    iFarDst = iFarDst * iFarDst;
    while (pLandmarkIterator && *pLandmarkIterator->Item())
    {
        CompassMarker* pCompassMarker = (CompassMarker*)*pLandmarkIterator->Item();
        pLandmarkIterator = pLandmarkIterator->Next();
        if (pCompassMarker->pRef->IsDisabled())
            continue;
        CompassPoint kPosition = *pCompassMarker->pRef->GetPos();
        float fLen = fabsf((kPosition - kPt).Length());
        if (fLen > iFarDst)
            continue;
        bool bDiscovered = false;
        bool bVisible = pCompassMarker->pInfo->IsVisible();
        float fRadius = pCompassMarker->pRef->GetMarkerRadius();
        fRadius = fRadius * fRadius;
        if (fLen < fRadius)
        {
            if (!pCompassMarker->pInfo->IsDiscovered())
            {
                bDiscovered = true;
                pCompassMarker->pInfo->SetDiscovered(true);
                pCompassMarker->pRef->SetFlag(0x80000000);
            }
            if (!bVisible)
            {
                bDiscovered = true;
                pCompassMarker->pInfo->SetVisible(true);
                pCompassMarker->pRef->SetFlag(0x80000000);
            }
        }
        if (!bCompassReferenceDead)
        {
            CompassEvent kEvent;
            kEvent.pRef = pCompassMarker->pRef;
            kEvent.bSkip = false;
            if (bDiscovered)
            {
                FUN_0076b960(DAT_011d2208.String(), pCompassMarker->pInfo->GetName(), 1, 0, -1, -1, "UIPopUpQuestNew");
                FUN_005f5950(4, 1, pCompassMarker->pRef, pCompassMarker->pRef, 0, 0, 0);
                FUN_004d5c60(true);
                ((CompassRef*)DAT_011dea3c)->RewardXP(*DAT_011d0364.Int());
                kEvent.bSkip = false;
                kEvent.bNew = true;
            }
            else if (bVisible)
            {
                kEvent.bSkip = fLen < fRadius;
                kEvent.bNew = false;
            }
            if (!kEvent.bSkip)
                UpdateMapMarkerHUD(&kEvent);
            else if (bOnce && bDiscovered)
            {
                UpdateMapMarkerHUD(&kEvent);
                bOnce = false;
            }
        }
        if (pWalk)
        {
            pTileElem = *apMapTiles->kTiles.NextTile(&pWalk);
            if (bVisible)
                pTileElem->Set(4044, "Interface\\HUD\\glow_hud_compass_landmark_discovered.dds", true);
            else
                pTileElem->Set(4044, "Interface\\HUD\\glow_hud_compass_landmark.dds", true);
        }
        else
            continue;
        if (pTileElem)
        {
            float fMapAngle = ComputeObjectAngleDelta(kPosition, kPt);
            if (fabsf(fMapAngle) < HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
            {
                float fMapX = LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                                -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                                HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fMapAngle);
                pTileElem->Set(iHeadingID, fMapX, true);
                pTileElem->Set(iDistanceID, fLen, true);
                pTileElem->Set(4003, 1);
                if (fMapX > fFadeStart)
                    pTileElem->Set(4009, LinearInterpolate(1, 0, fFadeStart, m_fGlyphWidthInPixels, fMapX) * fAlpha, true);
                else if (fLen < 10000.0)
                    FUN_00778c20(pTileElem, fLen, DAT_011d979c);
                else
                    pTileElem->Set(4009, fAlpha, true);
            }
            else
                pTileElem->Set(4003, 0);
        }
    }
    while (pWalk)
    {
        TileX* pMapRest = *apMapTiles->kTiles.NextTile(&pWalk);
        pMapRest->Set(4003, 0);
    }
    HUDMainMenu_pme->m_pRegionObjectListObj = ((CompassRef*)DAT_011dea3c)->GetQuestTargets();
    pWalk = apQuestTiles->kTiles.QuestHead();
    CompassList* pQuestIt = (CompassList*)HUDMainMenu_pme->m_pRegionObjectListObj;
    float fObjRad = *DAT_011d0bd8.Int();
    fObjRad = fObjRad * fObjRad;
    while (pQuestIt && *pQuestIt->Item())
    {
        bool bSpecial = false;
        CompassQuestTarget* pTarget = (CompassQuestTarget*)*pQuestIt->Item();
        pQuestIt = pQuestIt->Next();
        CompassRef* pRef = pTarget->GetTarget();
        if (pRef && pRef->GetFormType() == 28)
            bSpecial = true;
        if (pRef && *DAT_011e07f0.Bool())
        {
            CompassPoint kQuestPos = *pRef->GetPos();
            float fTgtDst = fabsf((kQuestPos - kPt).Length());
            float fQuestOpacity = fAlpha;
            if (fTgtDst != 0.0)
                fQuestOpacity =
                    LinearInterpolate(fAlpha / 2.0, fAlpha, CompassMin(fTgtDst, fObjRad) / fObjRad, 0, fTgtDst);
            if (pWalk)
            {
                pTileElem = *apQuestTiles->kTiles.NextQuestTile(&pWalk);
                pTileElem->Set(4044, "Interface\\HUD\\glow_hud_compass_objective_marker.dds", true);
            }
            else
                continue;
            if (pTileElem)
            {
                float fQuestAngle = ComputeObjectAngleDelta(kQuestPos, kPt);
                if (fQuestAngle > HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
                    fQuestAngle = HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList;
                else if (fQuestAngle < -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
                    fQuestAngle = -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList;
                float fX = LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                             -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                             HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fQuestAngle);
                if (fFadeStart + 70.0 < fX)
                    fX = fFadeStart + 70.0;
                pTileElem->Set(iHeadingID, fX, true);
                pTileElem->Set(iDistanceID, fTgtDst, true);
                pTileElem->Set(4003, 1);
                if (apMovie->GetModeObj()->GetMode() == 1)
                {
                    if (!bSpecial)
                        FUN_00778c20(pTileElem, fTgtDst, DAT_011d979c);
                    else
                        pTileElem->Set(4009, fAlpha, true);
                }
            }
        }
    }
    if (((CompassRef*)DAT_011dea3c)->GetPlacedMarker() && pWalk)
    {
        pTileElem = *apQuestTiles->kTiles.NextQuestTile(&pWalk);
        pTileElem->Set(4044, "Interface\\HUD\\glow_hud_compass_pc_marker.dds", true);
        if (pTileElem)
        {
            CompassPoint kPCPos = *((CompassRef*)DAT_011dea3c)->GetPlacedMarker()->GetPos();
            kPCPos.z = kPt.z;
            float fPCDist = fabsf((kPCPos - kPt).Length());
            float fPCAngle = ComputeObjectAngleDelta(kPCPos, kPt);
            if (fabsf(fPCAngle) < HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
            {
                float fPCX = LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                               -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                               HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fPCAngle);
                pTileElem->Set(iHeadingID, fPCX, true);
                pTileElem->Set(4003, 1);
                if (fPCX > fFadeStart)
                {
                    float fPCOpacity = LinearInterpolate(fAlpha, 0, fFadeStart, m_fGlyphWidthInPixels, fPCX);
                    FUN_00778c20(pTileElem, fPCDist, fPCOpacity);
                }
                else
                    FUN_00778c20(pTileElem, fPCDist, DAT_011d979c);
            }
            else
                pTileElem->Set(4003, 0);
        }
    }
    while (pWalk)
    {
        TileX* pQuestRest = *apQuestTiles->kTiles.NextQuestTile(&pWalk);
        pQuestRest->Set(4003, 0);
    }
    DAT_011d96c4 = false;
    pWalk = apActorTiles->kTiles.Head();
    CompassList* pActors = ((CompassRef*)DAT_011dea3c)->GetActorMarkers();
    bool bSneakOn = ((CompassRef*)DAT_011dea3c)->GetProcess()->IsSneaking();
    float fStealthDst = *DAT_011cd7d8.Float();
    fStealthDst = fStealthDst * fStealthDst;
    float fWalkDst = *DAT_011cdcbc.Float() * *DAT_011cd7d8.Int();
    fWalkDst = fWalkDst * fWalkDst;
    unsigned int uiShown = pActors->Count();
    if (pActors->Count() > (unsigned int)*DAT_011d32d0.Int())
    {
        pActors->Sort(FUN_0077b300);
        uiShown = *DAT_011d32d0.Int();
    }
    while (pActors && !pActors->IsEmpty() && uiShown)
    {
        uiShown = uiShown - 1;
        CompassActor* pActor = (CompassActor*)*pActors->Item();
        if (!pActor || pActor->bHidden || !pActor->pActor->Get3D() || !pActor->pActor->GetProcess() ||
            !pActor->pActor->GetProcess()->IsActive())
        {
            pActors = pActors->Next();
            continue;
        }
        if (pActor->pActor->kAV.GetValue(49) || pActor->pActor->kAV.GetValue(48))
        {
            float fPerk = 0;
            FUN_005e58f0(69, (CompassRef*)DAT_011dea3c, &fPerk);
            if (fPerk <= 0.0)
            {
                pActors = pActors->Next();
                continue;
            }
        }
        CompassPoint kActorPt = *pActor->pActor->GetPos();
        float fActorDist = fabsf((kActorPt - kPt).Length());
        if ((bSneakOn && fActorDist > fStealthDst) || (!bSneakOn && fActorDist > fWalkDst))
        {
            pActors = pActors->Next();
            continue;
        }
        if (fActorDist < iFarDst)
        {
            if (pWalk)
            {
                pTileElem = *apActorTiles->kTiles.NextTile(&pWalk);
                pTileElem->Set(4044, "Interface\\HUD\\glow_hud_tick_mark.dds", true);
            }
            else
                continue;
            if (pTileElem)
            {
                float fActorAngle = ComputeObjectAngleDelta(kActorPt, kPt);
                if (fabsf(fActorAngle) < HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList)
                {
                    float fActorX = LinearInterpolate(0, HUDMainMenu_pme->m_iHudValueSecondAfterUpdateList << 1,
                                                      -HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList,
                                                      HUDMainMenu_pme->m_iHudValueThirdAfterUpdateList, fActorAngle);
                    pTileElem->Set(iHeadingID, fActorX + 2.0, true);
                    pTileElem->Set(4003, 1);
                    if (pActor->m_bIsEnemy)
                    {
                        pTileElem->Set(4084, 2);
                        DAT_011d96c4 = true;
                    }
                    else
                        pTileElem->Set(4084, 1);
                    if (fActorX > fFadeStart)
                        pTileElem->Set(4009, LinearInterpolate(fAlpha, 0, fFadeStart, m_fGlyphWidthInPixels, fActorX), true);
                    else
                        pTileElem->Set(4009, fAlpha, true);
                }
                else
                    pTileElem->Set(4003, 0);
            }
        }
        pActors = pActors->Next();
    }
    while (pWalk)
    {
        TileX* pActorRest = *apActorTiles->kTiles.NextTile(&pWalk);
        pActorRest->Set(4003, 0);
    }
}
}  // namespace fnv_00779070

namespace fnv_00771700 {
class VisibilityTile
{
  public:
    void FUN_00700320(int trait, int value);
    void FUN_00a012d0(int trait, float value, bool propagate);
    float FUN_00a011b0(int trait);
};
class NiNode
{
  public:
    NiNode* FUN_0045bc00(unsigned int);
    void IncRefCount();
    void DecRefCount();
};
class VisibilityPlayer
{
  public:
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
    virtual void vf100();
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
    virtual void vf148();
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
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
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
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual int GetMode();
    bool FUN_005a03f0(unsigned int);
    bool FUN_008bbc10();
    bool FUN_008a16d0();
    NiNode* FUN_007721a0();
    bool FUN_00524d10();
};

class VisibilityHUD : public HUDMainMenu
{
  public:
    int FUN_0059bb30();
    void FUN_00a1db20();
    void FUN_00775670();
};
struct VisibilityMode
{
    int FUN_0044ddc0();
};
class InterfaceManager
{
  public:
    bool FUN_00719ae0();
};
struct SndX
{
    bool IsValid();
    bool Play(bool);
    bool FUN_00ad88b0();
};
extern HUDMainMenu* HUDMainMenu_pme;
extern VisibilityPlayer* _g_thePlayer;
extern VisibilityMode DAT_011f2250;
extern NiPointer<NiNode> DAT_011d9770;
extern bool DAT_011d96bb;
extern const double DAT_01073488;
int __cdecl FUN_007023c0();
InterfaceManager* __cdecl FUN_004b7210();
void __cdecl FUN_00778b10();
void __cdecl SetHudVisible(bool);

// Selects a HUD mode from the requested value and player state, then updates HUD flags, tile traits, and a sound handle.
// @fnv 0x00771700
void __cdecl UpdateVisibilityState(int aiMenuMode)
{
    if (!HUDMainMenu_pme)
        return;
    int state = aiMenuMode;
    if (((VisibilityHUD*)HUDMainMenu_pme)->FUN_0059bb30() != 1)
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00a1db20();
    if (state == 1)
    {
        int iMenuId = FUN_007023c0();
        switch (iMenuId)
        {
        case 1002:
        case 1003:
        case 1014:
        case 1023:
        case 1035:
        case 1061:
            state = 3;
            break;
        case 1013:
            state = 4;
            break;
        case 1007:
            state = 5;
            break;
        case 0:
        case 1004:
            if (_g_thePlayer->GetMode() == 4 || _g_thePlayer->GetMode() == 9)
                state = 11;
            else if (_g_thePlayer->GetMode())
                state = 10;
            else if (DAT_011f2250.FUN_0044ddc0() == 4)
                state = 8;
            else if (_g_thePlayer->FUN_005a03f0(1))
                UpdateVisibilityState(12);
            else if (_g_thePlayer->FUN_008bbc10())
                state = 22;
            else
                state = 2;
            break;
        case 1009:
            state = 6;
            break;
        case 1056:
            state = 7;
            break;
        case 1008:
            state = 9;
            break;
        case 1012:
            state = 11;
            break;
        case 1055:
            state = 15;
        case 1057:
            state = 16;
        }
    }
    if (state == 22 && DAT_011d9770 && DAT_011d9770->FUN_0045bc00(0) && _g_thePlayer->FUN_008a16d0())
        state = 23;
    if (state != 24 && state != 4 && state != 5 && _g_thePlayer->FUN_005a03f0(1))
    {
        if (FUN_004b7210()->FUN_00719ae0())
            state = 2;
        else if (state == 6)
            state = 6;
        else
            state = 12;
    }
    switch (state)
    {
    case 2:
    case 13:
    case 20:
    case 22:
        if (_g_thePlayer->FUN_005a03f0(32))
            HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1fdff;
        else
            HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1ffff;
        FUN_00778b10();
        break;
    case 3:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x100;
        break;
    case 4:
    case 5:
    case 14:
    case 17:
    case 18:
    case 21:
    case 24:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0;
        break;
    case 19:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0;
        break;
    case 25:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0;
        break;
    case 9:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1000;
        break;
    case 12:
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1514;
        break;
    case 6:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1110;
        break;
    case 7:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x100;
        break;
    case 8:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x108;
        break;
    case 23:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 8;
        break;
    case 11:
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x11fff;
        break;
    case 10:
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x11dbf;
        break;
    case 15:
    case 16:
        ((VisibilityHUD*)HUDMainMenu_pme)->FUN_00775670();
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode = 0x1010;
    }
    HUDMainMenu_pme->m_iHudValueFirstBeforeMode &= HUDMainMenu_pme->m_iHudValueSecondBeforeMode;
    if (DAT_011d96bb)
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode &= ~8;
    if (_g_thePlayer && _g_thePlayer->FUN_007721a0() && !_g_thePlayer->FUN_00524d10())
        HUDMainMenu_pme->m_iHudValueFirstBeforeMode &= ~64;
    if (state == 6)
    {
        float scopeY = ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])->FUN_00a011b0(4103);
        ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])->FUN_00a012d0(4002, scopeY - DAT_01073488, true);
    }
    else
    {
        float normalY = ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])->FUN_00a011b0(4103);
        ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])->FUN_00a012d0(4002, normalY, true);
    }
    if (HUDMainMenu_pme->m_eHudMenuMode != 23 && state == 23)
        SetHudVisible(true);
    else if (HUDMainMenu_pme->m_eHudMenuMode == 23 && state != 23)
        SetHudVisible(false);
    HUDMainMenu_pme->m_eHudMenuMode = state;
    if (HUDMainMenu_pme->m_eHudMenuMode != 20 && HUDMainMenu_pme->m_eHudMenuMode != 6 &&
        HUDMainMenu_pme->m_eHudMenuMode != 2 && HUDMainMenu_pme->m_eHudMenuMode != 5 &&
        HUDMainMenu_pme->m_eHudMenuMode != 14 && HUDMainMenu_pme->m_eHudMenuMode != 17 &&
        HUDMainMenu_pme->m_eHudMenuMode != 9 && HUDMainMenu_pme->m_eHudMenuMode != 11 &&
        HUDMainMenu_pme->m_eHudMenuMode != 18 && HUDMainMenu_pme->m_eHudMenuMode != 19 &&
        HUDMainMenu_pme->m_eHudMenuMode != 25)
        HUDMainMenu_pme->m_bQuestObjectiveUpdatesEnabled = true;
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[59])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[60])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x2);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[61])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x4);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[62])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x8);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[63])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x10);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[64])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x20);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[65])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x40);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[66])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x80);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[67])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x100);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[68])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x200);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[69])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x400);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[70])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x800);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[71])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1000);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[72])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x2000);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[73])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x4000);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[74])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x8000);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[77])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[78])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x10000);
    ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[86])
        ->FUN_00700320(4003, HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 0x1);

    if (!(HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 1))
    {
        ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[75])->FUN_00700320(4003, 0);
        ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[82])->FUN_00700320(4003, 0);
    }
    if (!(HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 8))
    {
        ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[76])->FUN_00700320(4003, 0);
        ((VisibilityTile*)HUDMainMenu_pme->m_pTiles[83])->FUN_00700320(4003, 0);
    }
    if (((SndX*)HUDMainMenu_pme->m_kTargetDisplayData)->IsValid())
    {
        if (HUDMainMenu_pme->m_iHudValueFirstBeforeMode & 4)
            ((SndX*)HUDMainMenu_pme->m_kTargetDisplayData)->Play(false);
        else
            ((SndX*)HUDMainMenu_pme->m_kTargetDisplayData)->FUN_00ad88b0();
    }
}
}  // namespace fnv_00771700

namespace fnv_0077da60 {
class HotkeyTile
{
  public:
    void FUN_00700320(int aiID, int aiValue);
    void FUN_00a01350(int aiID, const char* apText, bool abPropagate);
};

struct HotkeyWheel
{
    int FUN_00701bd0(int aiIndex);
    void FUN_007017b0();
    bool FUN_00701740();
    void FUN_00701760(bool abVisible);
    void FUN_00701e80();
    int FUN_006e4ba0();
    void FUN_0061cc40(int aiIndex);
};

struct HotkeyItem
{
    ~HotkeyItem();
    const char* GetIconFilename(int aiIndex);
    int FUN_00726070();
    const char* GetTargetFullName();
};

struct HotkeyList
{
    HotkeyItem* FindEntryWithExtraListType(int aiIndex);
};

struct HUDPlayer
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
    virtual bool FUN_vt22c(int aiMode);
    bool FUN_005a03f0(int aiFlag);
};
extern HUDPlayer* DAT_011dea3c;

struct HUDInterface
{
    bool FUN_007023a0();
};

struct HUDInput
{
    int FUN_00a24660(int aiControl, int aiState);
};

struct HUDGlobals
{
    HUDInput* FUN_00877720();
};
extern HUDGlobals* DAT_011dea0c;

struct HUDTimer
{
    unsigned int FUN_00825c00();
};
extern HUDTimer DAT_011f6394;

struct HUDSetting
{
    float* FUN_00403e20();
};
extern HUDSetting DAT_011d2d84;
extern HUDSetting DAT_011d279c;

extern bool DAT_011d9e90;
extern int DAT_011d9e8c;
extern int DAT_011a0124;

class InterfaceManager;
InterfaceManager* FUN_004b7210();
bool FUN_004b71d0();
HotkeyList* __cdecl FUN_004bf220(HUDPlayer* apPlayer);
int __cdecl TraitNameToID(const char* apTrait);
int __cdecl FUN_00406d00(char* apDest, unsigned int auiSize, const char* apFormat, ...);
int __cdecl FUN_00406d30(char* apDest, unsigned int auiSize, const char* apSrc);

static const char s_szNameCount[] = "%s (%d)";
static const char s_szIconVisible[] = "_IconVisible";
static const char s_szIconFilename[] = "_IconFilename";
static const char s_szBlank[] = " ";

struct HUDHotkeys : HUDMainMenu
{
    void FUN_0077da60();
};

// Updates hotkey wheel selection, tile labels, and icon visibility based on input state and timer thresholds.
// @fnv 0x0077da60
void HUDHotkeys::FUN_0077da60()
{
    if (!((HUDInterface*)FUN_004b7210())->FUN_007023a0() && !DAT_011dea3c->FUN_vt22c(0) &&
        !DAT_011dea3c->FUN_005a03f0(4))
    {
        if (FUN_004b71d0())
        {
            int iSelected = ((HotkeyWheel*)m_kMenuData)->FUN_00701bd0(-1);
            if (!DAT_011d9e90 && iSelected >= 0)
            {
                ((HotkeyWheel*)m_kMenuData)->FUN_007017b0();
                DAT_011d9e90 = true;
                DAT_011d9e8c = DAT_011f6394.FUN_00825c00();
            }
            if (DAT_011d9e90)
            {
                if (iSelected >= 0)
                {
                    if (DAT_011d9e8c > 0 &&
                        DAT_011f6394.FUN_00825c00() - DAT_011d9e8c > *DAT_011d2d84.FUN_00403e20() * 1000.0 &&
                        !((HotkeyWheel*)m_kMenuData)->FUN_00701740())
                    {
                        ((HotkeyWheel*)m_kMenuData)->FUN_00701760(true);
                        ((HotkeyTile*)m_pTiles[44])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[45])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[46])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[47])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[48])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[49])->FUN_00700320(0xfa3, 0);
                    }
                    if (((HotkeyWheel*)m_kMenuData)->FUN_00701740() && iSelected != DAT_011a0124)
                    {
                        HotkeyList* pListOld = FUN_004bf220(DAT_011dea3c);
                        HotkeyItem* pFinalItem = pListOld ? pListOld->FindEntryWithExtraListType(iSelected) : 0;
                        bool bHasIcon = false;
                        const char* pIcon = 0;
                        char acNameVal[260];
                        if (pFinalItem)
                        {
                            pIcon = pFinalItem->GetIconFilename(0);
                            if (pIcon)
                                bHasIcon = true;
                            if (pFinalItem->FUN_00726070() > 1)
                                FUN_00406d00(acNameVal, 260, s_szNameCount, pFinalItem->GetTargetFullName(),
                                             pFinalItem->FUN_00726070());
                            else
                                FUN_00406d30(acNameVal, 260, pFinalItem->GetTargetFullName());
                            ((HotkeyTile*)m_pTiles[41])->FUN_00a01350(0xfc4, acNameVal, true);
                            ((HotkeyTile*)m_pTiles[41])->FUN_00700320(0xfa3, 1);
                        }
                        else
                        {
                            ((HotkeyTile*)m_pTiles[41])->FUN_00700320(0xfa3, 0);
                        }
                        if (!bHasIcon)
                        {
                            ((HotkeyTile*)m_pTiles[40])->FUN_00700320(TraitNameToID(s_szIconVisible), 0);
                        }
                        else
                        {
                            ((HotkeyTile*)m_pTiles[40])->FUN_00a01350(TraitNameToID(s_szIconFilename), pIcon, true);
                            ((HotkeyTile*)m_pTiles[40])->FUN_00700320(TraitNameToID(s_szIconVisible), 1);
                        }
                        DAT_011a0124 = iSelected;
                        delete pFinalItem;
                    }
                }
                else
                {
                    ((HotkeyWheel*)m_kMenuData)->FUN_00701e80();
                    ((HotkeyWheel*)m_kMenuData)->FUN_00701760(false);
                    ((HotkeyTile*)m_pTiles[41])->FUN_00700320(0xfa3, 0);
                    DAT_011d9e8c = 0;
                    DAT_011d9e90 = false;
                    DAT_011a0124 = -1;
                }
            }
        }
        else
        {
            for (int i = 0; i < ((HotkeyWheel*)m_kMenuData)->FUN_006e4ba0(); i++)
            {
                if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(i + 0x11, 1))
                {
                    if (i == 1)
                    {
                        ((HotkeyWheel*)m_kMenuData)->FUN_0061cc40(i);
                        continue;
                    }
                    HotkeyList* pHotkeys = FUN_004bf220(DAT_011dea3c);
                    HotkeyItem* pEntry = 0;
                    bool bIconTmp = false;
                    DAT_011d9e8c = DAT_011f6394.FUN_00825c00();
                    ((HotkeyWheel*)m_kMenuData)->FUN_00701bd0(i);
                    pEntry = pHotkeys ? pHotkeys->FindEntryWithExtraListType(i) : 0;
                    const char* pIconPathOld = 0;
                    char acLabel[260];
                    if (pEntry)
                    {
                        pIconPathOld = pEntry->GetIconFilename(0);
                        if (pIconPathOld)
                            bIconTmp = true;
                        if (pEntry->FUN_00726070() > 1)
                            FUN_00406d00(acLabel, 260, s_szNameCount, pEntry->GetTargetFullName(), pEntry->FUN_00726070());
                        else
                            FUN_00406d30(acLabel, 260, pEntry->GetTargetFullName());
                        ((HotkeyTile*)m_pTiles[41])->FUN_00a01350(0xfc4, acLabel, true);
                    }
                    else
                    {
                        ((HotkeyTile*)m_pTiles[41])->FUN_00a01350(0xfc4, s_szBlank, true);
                    }
                    if (!bIconTmp)
                    {
                        ((HotkeyTile*)m_pTiles[40])->FUN_00700320(TraitNameToID(s_szIconVisible), 0);
                    }
                    else
                    {
                        ((HotkeyTile*)m_pTiles[40])->FUN_00a01350(TraitNameToID(s_szIconFilename), pIconPathOld, true);
                        ((HotkeyTile*)m_pTiles[40])->FUN_00700320(TraitNameToID(s_szIconVisible), 1);
                    }
                    delete pEntry;
                }
                else if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(i + 0x11, 0))
                {
                    if (!((HotkeyWheel*)m_kMenuData)->FUN_00701740() && DAT_011d9e8c > 0 &&
                        DAT_011f6394.FUN_00825c00() - DAT_011d9e8c > *DAT_011d2d84.FUN_00403e20() * 1000.0 && i != 1)
                    {
                        ((HotkeyWheel*)m_kMenuData)->FUN_00701760(true);
                        ((HotkeyTile*)m_pTiles[41])->FUN_00700320(0xfa3, 1);
                        ((HotkeyTile*)m_pTiles[44])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[45])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[46])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[47])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[48])->FUN_00700320(0xfa3, 0);
                        ((HotkeyTile*)m_pTiles[49])->FUN_00700320(0xfa3, 0);
                    }
                    if (((HotkeyWheel*)m_kMenuData)->FUN_00701740())
                        DAT_011d9e8c = DAT_011f6394.FUN_00825c00();
                }
                else if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(i + 0x11, 2))
                {
                    ((HotkeyWheel*)m_kMenuData)->FUN_00701e80();
                    if (!((HotkeyWheel*)m_kMenuData)->FUN_00701740())
                        DAT_011d9e8c = 0;
                }
            }
            if (((HotkeyWheel*)m_kMenuData)->FUN_00701740() && DAT_011d9e8c > 0 &&
                DAT_011f6394.FUN_00825c00() - DAT_011d9e8c > *DAT_011d279c.FUN_00403e20() * 1000.0)
            {
                ((HotkeyTile*)m_pTiles[41])->FUN_00700320(0xfa3, 0);
                ((HotkeyWheel*)m_kMenuData)->FUN_00701760(false);
                DAT_011d9e8c = 0;
            }
        }
    }
    else
    {
        DAT_011d9e8c = 0;
        ((HotkeyWheel*)m_kMenuData)->FUN_00701760(false);
        ((HotkeyTile*)m_pTiles[41])->FUN_00700320(0xfa3, 0);
    }
}
}  // namespace fnv_0077da60

class Tile_traitSetter
{
  public:
    void FUN_00a012d0(int aiTrait, float afValue, bool abPropagate);
};

struct HUDMainMenuEx : public HUDMainMenu
{
    void FUN_00775920();
};

extern HUDMainMenuEx* HUDMainMenu_pSingleton;

// Sets trait 4009 to afScale * 255.0 on HUD main menu tiles with indices outside the listed exclusions.
// @fnv 0x0077e430
void __cdecl FUN_0077e430(float afScale)
{
    if (HUDMainMenu_pSingleton)
    {
        HUDMainMenu_pSingleton->FUN_00775920();
        for (int i = 1; i < 59; i++)
        {
            switch (i)
            {
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 24:
            case 25:
            case 26:
            case 27:
            case 44:
            case 50:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
            case 58:
                break;
            default:
                ((Tile_traitSetter*)HUDMainMenu_pSingleton->m_pTiles[i])->FUN_00a012d0(4009, afScale * 255.0, true);
                break;
            }
        }
    }
}

struct VATSCreatePointX
{
    float x, y, z;
    VATSCreatePointX& operator*=(float afScale);
    VATSCreatePointX& operator+=(const VATSCreatePointX& arPoint);
    VATSCreatePointX operator-(const VATSCreatePointX& arPoint) const;
};
struct VATSCreateMatrixX
{
    float m[9];
    float GetEntry(int aiRow, int aiCol) const;
};
struct VATSCreateNodeArgX;
struct VATSCreateTexX;
struct VATSCreateTileX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual VATSCreateNodeArgX* GetNode();
    struct VATSCreateMenuX* GetMenu();
    void Set(int aeID, float afValue, bool abPropagate);
    void SetInt(int aeID, int aiValue);
    void Set(int aeID, const char* apValue, bool abPropagate);
    float GetFloat(int aeID);
    VATSCreateTileX* FUN_00a03da0(const char* apName);
};
struct VATSCreateTileMenuX : public VATSCreateTileX
{
};
struct VATSCreateLoaderX
{
    VATSCreateTileX* ReadFile(const char* apPath);
};
struct VATSCreateMenuX
{
    virtual ~VATSCreateMenuX();
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
    virtual int GetID();
    void FUN_00a1dc70(VATSCreateTileMenuX* apTile, bool abArg);
    VATSCreateTileX* AddTileFromTemplate(VATSCreateTileX* apParent, const char* apTemplate, int aiArg);
    VATSCreateTileX* FUN_00726070();
    void FUN_00a1dc20(int aiArg);
};
struct VATSCreateActionListX
{
    void Initialize(VATSCreateTileX* apTile, const char* apTemplate);
};
struct VATSCreateLimbX
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    int m_iLimbIndex;
};
template <class T> struct VATSCreateListX
{
    T item;
    VATSCreateListX* next;
    bool IsEmpty();
    T& GetItem();
    VATSCreateListX* GetNext();
    void FUN_00905330(T const& arItem);
    void Sort(int (*apCompare)(void*, void*));
    void RemoveAll();
};
struct VATSCreateRefX;
struct VATSCreateVATSTargetX
{
    VATSCreateRefX* pRef;
    int iType;
    VATSCreateListX<VATSCreateLimbX*> kLimbs;
    int iPad10;
    float m_fTargetAngle;
    float fAngleDifference;
    float fDistance;
    bool bVisible;
};
struct VATSCreateVATSMenuX : public VATSCreateMenuX
{
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
    VATSCreateTileX* m_pTiles[29];
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    bool bDebounce;
    unsigned char unk0ad;
    unsigned char unk0ae;
    unsigned char unk0af;
    VATSCreateActionListX kActions;
    unsigned char unk0b1;
    unsigned char unk0b2;
    unsigned char unk0b3;
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
    unsigned char unk0dc;
    float m_fOverrideActionPoints;
    float m_fValue1;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned char unk0f8;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    unsigned int unk0fc;
    VATSCreateLimbX* m_pTargetChance;
    unsigned int unk104;
    unsigned int unk108;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned int m_uiTargetCount;
    bool b118;
    bool HasAllSlotsSet(void* apOut);
};
struct VATSCreateBaseFormX
{
    int iDummy;
};
struct VATSCreateFormX : public VATSCreateBaseFormX
{
    struct VATSCreateWeaponX* FUN_0044ddc0();
};
struct VATSCreateWeaponX : public VATSCreateBaseFormX
{
    int GetWeaponType() const;
};
struct VATSCreateFormListHeadX
{
    bool IsInList(VATSCreateBaseFormX* const& arForm);
};
struct VATSCreateFormListX
{
    VATSCreateFormListHeadX* GetHeader();
};
struct VATSCreateNodeArgX
{
    void FUN_007700b0(VATSCreateTexX* apTexture);
    void FUN_007700d0(bool abArg);
};
struct VATSCreateNode3DX
{
    const VATSCreateMatrixX& GetRotate() const;
    const VATSCreatePointX& GetTranslate();
};
struct VATSCreateProcX
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
    virtual VATSCreateFormX* GetEquippedWeapon();
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
    virtual bool IsInDialogue();
    void FUN_008ff030(VATSCreateRefX* apRef);
};
struct VATSCreateAVOwnerX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float GetActorValue(int aeAV);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual float GetBaseActorValue(int aeAV);
};
struct VATSCreateRefX
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
    virtual void* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const VATSCreatePointX& GetPos();
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
    virtual bool IsMobile();
    virtual void v228();
    virtual bool IsDead(int aiArg);
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
    virtual float GetRange(int aiArg);
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
    virtual int GetMobileType();
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
    VATSCreateAVOwnerX kAVOwner;
    VATSCreateFormX* GetObjectReference();
    VATSCreateProcX* GetProcess();
    bool FUN_005a2030() const;
    void ToggleFirstPerson(int aiArg);
    void SetWantsWeaponOut(int aiArg);
    void SetProcessValue(float afArg);
    void SetActiveState(int a1, int a2, int a3);
};
struct VATSCreateEffectFormX
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
    virtual bool IsValid();
};
struct VATSCreateDataHandlerX
{
    VATSCreateRefX* PlaceObjectReference(VATSCreateEffectFormX* apForm, VATSCreatePointX& arPos, const VATSCreatePointX& arRot,
                                 int a4, void* a5, int a6, int a7, int a8);
};
struct VATSCreateTESX
{
    int FUN_005f36f0();
    void* FUN_004fd3e0();
};
struct VATSCreateVATSX
{
    void FUN_009c6c30(int aiMode, bool abArg);
};
struct VATSCreateSettingX
{
    const char* String();
    int* Int();
};
struct VATSCreateHUDManagerX
{
    void FUN_00718630(int a1, int a2, int a3);
};
struct VATSCreateInterfaceMgrX
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
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
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
    unsigned int unk23c;
    unsigned int unk240;
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
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    VATSCreateHUDManagerX kHUD;
    VATSCreateLoaderX* FUN_00586150();
};
struct VATSCreateAudioX
{
    static VATSCreateAudioX* GetSingleton();
    void FUN_007eb8a0();
};
struct VATSCreateCalendarX
{
    float FUN_00867da0();
};
struct VATSCreateTimerX
{
    int FUN_00825c00();
};
struct VATSCreateFixedStringX
{
    char* m_kHandle;
    VATSCreateFixedStringX(const char* apString);
    ~VATSCreateFixedStringX();
};
struct VATSCreateFormatPrefsX
{
    int a, b, c;
};
struct VATSCreateSourceTextureX
{
    static VATSCreateTexX* Create(const VATSCreateFixedStringX& arName, VATSCreateFormatPrefsX& arPrefs, bool abLoad,
                                  bool abSRGB);
};
template <class T> struct VATSCreatePtrX
{
    T* m_pObject;
    VATSCreatePtrX(int aiNull);
    ~VATSCreatePtrX();
    VATSCreatePtrX& operator=(T* apObject);
    operator T*() const;
};
struct VATSCreateStringX
{
    char* pData;
    unsigned short usLen;
    unsigned short usMax;
    VATSCreateStringX();
    ~VATSCreateStringX();
};
struct VATSCreateBSSoundHandleX
{
    unsigned int uiSoundID;
    bool m_bLooping;
    int eState;
    VATSCreateBSSoundHandleX();
    ~VATSCreateBSSoundHandleX();
    VATSCreateBSSoundHandleX& operator=(const VATSCreateBSSoundHandleX& arHandle);
    bool Play(bool abUnk);
};
struct VATSCreateAudioMgrX
{
    VATSCreateBSSoundHandleX ResolveAudioHandle(const char* apEditorID, unsigned int auiFlags);
};

extern bool VATSCreateDAT_011db0b2, VATSCreateDAT_011db0b3, VATSCreateDAT_011db0b1, VATSCreateDAT_011f21d1,
    VATSCreateDAT_011db0b0, VATSCreateDAT_011db0cc;
extern VATSCreateVATSMenuX* VATSCreateDAT_011db0d4;
extern VATSCreateRefX* VATSCreateDAT_011dea3c;
extern VATSCreateRefX* VATSCreateDAT_011f21cc;
extern VATSCreateEffectFormX* VATSCreateDAT_011db0ac;
extern VATSCreateEffectFormX* VATSCreateDAT_011db0b4;
extern VATSCreateRefX* VATSCreateDAT_011f21e8;
extern VATSCreateRefX* VATSCreateDAT_011f21ec;
extern int VATSCreateDAT_011a0b70, VATSCreateDAT_011a59f0;
extern VATSCreateListX<VATSCreateVATSTargetX*> VATSCreateDAT_011db150;
extern const VATSCreatePointX VATSCreateDAT_011f426c;
extern const float VATSCreateDAT_0104fca0;
extern const double VATSCreateDAT_01011588, VATSCreateDAT_0102f248, VATSCreateDAT_01035810, VATSCreateDAT_0103c348,
    VATSCreateDAT_0101db88, VATSCreateDAT_01020998, VATSCreateDAT_010704f0, VATSCreateDAT_010704e8,
    VATSCreateDAT_01012638;
extern VATSCreateDataHandlerX* VATSCreateDAT_011c3f2c;
extern VATSCreateTESX* VATSCreateDAT_011dea10;
extern VATSCreateVATSX VATSCreateDAT_011f2250;
extern VATSCreateSettingX VATSCreateDAT_011d3e8c, VATSCreateDAT_011d1d90, VATSCreateDAT_011d4da4,
    VATSCreateDAT_011d300c, VATSCreateDAT_011d32d0, VATSCreateDAT_011cfec4, VATSCreateDAT_011c3cb4,
    VATSCreateDAT_011d5080, VATSCreateDAT_011d26f4, VATSCreateDAT_011d21c0, VATSCreateDAT_011d2b74,
    VATSCreateDAT_011d4d38;
extern VATSCreateCalendarX VATSCreateDAT_011de7b8;
extern VATSCreateTimerX VATSCreateDAT_011f6394;
extern VATSCreateFormatPrefsX VATSCreateDAT_011a9598;
extern const char VATSCreateDAT_01018348[];

VATSCreateTileX* VATSCreateFUN_00a09030(int aiMenu);
int VATSCreateFUN_007eb8c0();
bool VATSCreateFUN_00702450(int aiMenu);
void VATSCreateFUN_007f52c0();
VATSCreateFormListX* VATSCreateFUN_004839c0(int aiFormID);
int __fastcall VATSCreateFUN_00472380(VATSCreateRefX* apRef);
float VATSCreateFUN_00a01530();
VATSCreateInterfaceMgrX* VATSCreateFUN_004b7210();
void VATSCreateFUN_005e58f0(int aeEntryPoint, VATSCreateRefX* apActor, float* apValue);
float VATSCreateFUN_00476b70(float afMin, float afMax);
VATSCreateEffectFormX* VATSCreateFUN_0058db10(int aiIndex);
void VATSCreateFUN_00a04200(bool abArg);
int VATSCreateFUN_007f0380(void* a, void* b);
int VATSCreateFUN_007f0500(void* a, void* b);
float VATSCreateFUN_00772840(const VATSCreatePointX& arA, const VATSCreatePointX& arB);
float VATSCreateFUN_00408840(float afValue);
float VATSCreateFUN_007eb7f0(const VATSCreatePointX& arVector);
float VATSCreateFUN_00715d40();
float VATSCreateFUN_00715da0();
float VATSCreateFUN_007177c0();
float VATSCreateFUN_00717820();
int VATSCreateFUN_00a00940(const char* apName, int aiArg);
VATSCreateTileX* VATSCreateFUN_007f4890(VATSCreateTileX* apParent, const char* apName);
VATSCreateTileX* VATSCreateFUN_007f4830(VATSCreateTileX* apParent, const char* apName);
void VATSCreateFUN_00774800(VATSCreateTileX* apTile, int aiArg);
void VATSCreateFUN_007748b0(VATSCreateTileX* apTile, float afValue, int a3, int a4, int a5);
float VATSCreateFUN_00404010(float a1, float a2);
void VATSCreateFUN_0040fbe0(const char* apMessage);
void VATSCreateFUN_007037e0();
VATSCreateAudioMgrX* VATSCreateFUN_00ad9060();
bool __fastcall VATSCreateFUN_006450c0(VATSCreateWeaponX* apWeapon);
float VATSCreateFUN_0066dce0(VATSCreateWeaponX* apWeapon, int a2, int a3);
bool VATSCreateFUN_00709d40();
int VATSCreateFUN_00408b20(const char* a1, const char* a2);
int VATSCreateFUN_00a01860(const char* apName);
void VATSCreateFUN_007eb920(VATSCreateWeaponX* apWeapon);

extern "C" void* __cdecl xRTDynamicCast(void* apObject, long alVfDelta, void* apSrcType, void* apDstType,
                                        int aiIsReference);
extern char xRTTI_Tile[], xRTTI_TileMenu[], xRTTI_Menu[], xRTTI_VATSMenu[];

// Validates VATS targets, loads the VATS menu XML, builds HUD tiles, and initializes the VATS menu state.
// @fnv 0x007e9200
bool FUN_007e9200()
{
    float qfTOqo;
    VATSCreateFormListX* qsSDDgz;
    VATSCreateTileX* qrEZrs;
    VATSCreateFormListX* qpqRa;
    VATSCreateMenuX* qSVM;
    VATSCreateWeaponX* qdqWL;
    VATSCreateInterfaceMgrX* qpTd;
    VATSCreateDAT_011db0b2 = 0;
    VATSCreateDAT_011db0b3 = 0;
    VATSCreateDAT_011db0b1 = 0;
    qrEZrs = VATSCreateFUN_00a09030(VATSCreateFUN_007eb8c0());
    VATSCreateDAT_011db0d4 = (VATSCreateVATSMenuX*)qrEZrs->GetMenu();
    if (VATSCreateDAT_011db0d4 || VATSCreateFUN_00702450(0x3f4))
    {
        return false;
    }
    VATSCreateDAT_011db150.RemoveAll();
    VATSCreateFUN_007f52c0();
    qsSDDgz = VATSCreateFUN_004839c0(0x1770bc);
    {
        VATSCreateListX<VATSCreateVATSTargetX*>* qxQHW = &VATSCreateDAT_011db150;
        while (qxQHW && !qxQHW->IsEmpty())
        {
            VATSCreateFormX* qArxcFu = 0;
            if (qxQHW->GetItem()->pRef->IsActor())
            {
                qArxcFu = qxQHW->GetItem()->pRef->GetObjectReference();
            }
            VATSCreateRefX* qGfbX = qxQHW->GetItem()->pRef->IsActor() ? qxQHW->GetItem()->pRef : 0;
            VATSCreateRefX* qJDuOZ = qxQHW->GetItem()->pRef->IsMobile() ? qxQHW->GetItem()->pRef : 0;
            bool qAhbO = false;
            if (qJDuOZ && qJDuOZ->GetMobileType() == 4)
            {
                VATSCreateRefX* qpia = qJDuOZ;
                if (VATSCreateFUN_00472380(qpia) == 3 || VATSCreateFUN_00472380(qpia) == 4)
                {
                    qAhbO = true;
                }
            }
            if ((qxQHW->GetItem()->pRef->IsActor() && qxQHW->GetItem()->pRef->IsDead(0)) ||
                (qsSDDgz && qArxcFu && qsSDDgz->GetHeader()->IsInList(qArxcFu)) || (qGfbX && qGfbX->FUN_005a2030()) ||
                qAhbO)
            {
                if (VATSCreateDAT_011f21cc == qxQHW->GetItem()->pRef)
                {
                    VATSCreateDAT_011f21cc = 0;
                }
                qxQHW->FUN_00905330(qxQHW->GetItem());
            }
            qxQHW = qxQHW->GetNext();
        }
    }
    if (VATSCreateDAT_011db150.IsEmpty())
    {
        if (VATSCreateDAT_011f21d1)
        {
            VATSCreateDAT_011dea3c->ToggleFirstPerson(1);
        }
        return false;
    }
    qdqWL = 0;
    if (VATSCreateDAT_011dea3c && VATSCreateDAT_011dea3c->GetProcess())
    {
        qdqWL = VATSCreateDAT_011dea3c->GetProcess()->GetEquippedWeapon()
                    ? VATSCreateDAT_011dea3c->GetProcess()->GetEquippedWeapon()->FUN_0044ddc0()
                    : 0;
        if (VATSCreateDAT_011dea3c->GetProcess()->IsInDialogue())
        {
            return false;
        }
    }
    qpqRa = VATSCreateFUN_004839c0(0x174256);
    if (qdqWL && qpqRa && qpqRa->GetHeader()->IsInList(qdqWL))
    {
        return false;
    }
    if (!VATSCreateDAT_011f21cc)
    {
        VATSCreateDAT_011f21cc = VATSCreateDAT_011db150.GetItem()->pRef;
    }
    qpTd = VATSCreateFUN_004b7210();
    qfTOqo = VATSCreateFUN_00a01530();
    qrEZrs = qpTd->FUN_00586150()->ReadFile("Data\\Menus\\VATS_menu.xml");
    qSVM = qrEZrs->GetMenu();
    if (qSVM && qSVM->GetID() == VATSCreateFUN_007eb8c0())
    {
        char qbfQdhM;
        VATSCreateAudioMgrX* qXMUYT;
        float qzYzlc;
        float qYvToq;
        float qODE;
        VATSCreatePointX qkPflib;
        int qjThF;
        int qrBzVM;
        char qZgNzZy;
        VATSCreateTileX* qnEqwa;
        float qyFp;
        VATSCreateListX<VATSCreateVATSTargetX*>* qGTHx;
        int qYdAnhh;
        int qxDeKK;
        int qidnYUK;
        VATSCreateTileX* qIpA;
        float qZWI;
        VATSCreateListX<VATSCreateVATSTargetX*>* qOHwfb;
        int qOPw;
        VATSCreateWeaponX* qYvz;
        float qYePyBl;
        bool qtOMjSX;
        int qqtISP;
        VATSCreateTileX* qQGWBE;
        VATSCreateTileX* qLCwQ;
        char qRFOo;
        float qOSGSW;
        float qsCroYH;
        float qOqnE;
        VATSCreateTileX* qoPB;
        VATSCreateFormX* qMBds;
        int qkJsUdT;
        qSVM->FUN_00a1dc70((VATSCreateTileMenuX*)xRTDynamicCast(qrEZrs, 0, xRTTI_Tile, xRTTI_TileMenu, 0), 0);
        VATSCreateDAT_011db0d4 = (VATSCreateVATSMenuX*)xRTDynamicCast(qSVM, 0, xRTTI_Menu, xRTTI_VATSMenu, 0);
        qOSGSW = 0.0f;
        VATSCreateFUN_005e58f0(0x1c, VATSCreateDAT_011dea3c, &qOSGSW);
        qZWI = 0.0f;
        VATSCreateFUN_005e58f0(0x29, VATSCreateDAT_011dea3c, &qZWI);
        qsCroYH = VATSCreateFUN_00476b70(0.0f, 1.0f);
        qOqnE = 1.0 - qZWI * VATSCreateDAT_01011588;
        if (qOSGSW > 0 && qsCroYH <= qOqnE)
        {
            if (!VATSCreateDAT_011db0ac)
            {
                VATSCreateEffectFormX* qAXSCg = VATSCreateFUN_0058db10(7);
                if (qAXSCg && qAXSCg->IsValid())
                {
                    VATSCreateDAT_011db0ac = qAXSCg;
                }
            }
            if (qOSGSW != 0 && VATSCreateDAT_011db0ac)
            {
                VATSCreateNode3DX* qbdXUOW = (VATSCreateNode3DX*)VATSCreateDAT_011dea3c->Get3D();
                VATSCreatePointX qmgeiw = VATSCreateDAT_011f426c;
                VATSCreateMatrixX qBLsiu = qbdXUOW->GetRotate();
                VATSCreatePointX qCTa = qbdXUOW->GetTranslate();
                qmgeiw.x = qBLsiu.GetEntry(0, 1);
                qmgeiw.y = qBLsiu.GetEntry(1, 1);
                qmgeiw.z = qBLsiu.GetEntry(2, 1);
                qmgeiw *= VATSCreateDAT_0104fca0;
                qCTa += qmgeiw;
                VATSCreateDAT_011f21e8 = VATSCreateDAT_011c3f2c->PlaceObjectReference(
                    VATSCreateDAT_011db0ac, qCTa, VATSCreateDAT_011f426c, VATSCreateDAT_011dea10->FUN_005f36f0(),
                    VATSCreateDAT_011dea10->FUN_004fd3e0(), 0, 0, 0);
                VATSCreateDAT_011f21e8->SetWantsWeaponOut(1);
                VATSCreateDAT_011f21e8->GetProcess()->FUN_008ff030(VATSCreateDAT_011f21e8);
                VATSCreateDAT_011f21e8->SetProcessValue(0.0f);
            }
        }
        else if (qZWI > 0)
        {
            if (!VATSCreateDAT_011db0b4)
            {
                VATSCreateEffectFormX* qrUCJDN = VATSCreateFUN_0058db10(0x16);
                if (qrUCJDN && qrUCJDN->IsValid())
                {
                    VATSCreateDAT_011db0b4 = qrUCJDN;
                }
            }
            if (qZWI != 0 && VATSCreateDAT_011db0b4)
            {
                VATSCreateNode3DX* qydrGv = (VATSCreateNode3DX*)VATSCreateDAT_011dea3c->Get3D();
                VATSCreatePointX qISe = VATSCreateDAT_011f426c;
                VATSCreateMatrixX qpydTG = qydrGv->GetRotate();
                VATSCreatePointX qXUDve = qydrGv->GetTranslate();
                qISe.x = qpydTG.GetEntry(0, 1);
                qISe.y = qpydTG.GetEntry(1, 1);
                qISe.z = qpydTG.GetEntry(2, 1);
                qISe *= VATSCreateDAT_0104fca0;
                qXUDve += qISe;
                VATSCreateDAT_011f21ec = VATSCreateDAT_011c3f2c->PlaceObjectReference(
                    VATSCreateDAT_011db0b4, qXUDve, VATSCreateDAT_011f426c, VATSCreateDAT_011dea10->FUN_005f36f0(),
                    VATSCreateDAT_011dea10->FUN_004fd3e0(), 0, 0, 0);
                VATSCreateDAT_011f21ec->SetWantsWeaponOut(1);
                VATSCreateDAT_011f21ec->GetProcess()->FUN_008ff030(VATSCreateDAT_011f21ec);
                VATSCreateDAT_011f21ec->SetProcessValue(0.0f);
            }
        }
        qODE = 0.0f;
        VATSCreateFUN_005e58f0(0x1d, VATSCreateDAT_011dea3c, &qODE);
        if (qODE > 0)
        {
            VATSCreateDAT_011db0b0 = 1;
        }
        else
        {
            VATSCreateDAT_011db0b0 = 0;
        }
        VATSCreateDAT_011db0d4->m_pTargetChance = 0;
        VATSCreateDAT_011db0d4->FUN_00726070();
        VATSCreateFUN_00a04200(0);
        VATSCreateDAT_011db150.Sort(VATSCreateFUN_007f0380);
        qOHwfb = &VATSCreateDAT_011db150;
        qYePyBl = VATSCreateDAT_011dea3c->GetRange(0) * VATSCreateDAT_0102f248;
        qkPflib = VATSCreateDAT_011dea3c->GetPos();
        if (qOHwfb && !qOHwfb->IsEmpty())
        {
            VATSCreateDAT_011f21cc = qOHwfb->GetItem()->pRef;
        }
        while (qOHwfb && !qOHwfb->IsEmpty())
        {
            float qhQRuW;
            float qRZyE;
            float qQUDQ;
            if (!qOHwfb->GetItem()->pRef || !qOHwfb->GetItem()->pRef->Get3D())
            {
                VATSCreateListX<VATSCreateVATSTargetX*>* qOFvKuu = qOHwfb->GetNext();
                VATSCreateDAT_011db150.FUN_00905330(qOHwfb->GetItem());
                qOHwfb = qOFvKuu;
                continue;
            }
            {
                qRZyE = VATSCreateFUN_00772840(qkPflib, qOHwfb->GetItem()->pRef->GetPos());
                qhQRuW = VATSCreateFUN_00408840(qYePyBl - qRZyE);
                qQUDQ = VATSCreateFUN_007eb7f0(qkPflib - qOHwfb->GetItem()->pRef->GetPos());
                qOHwfb->GetItem()->m_fTargetAngle =
                    (float)(VATSCreateDAT_01035810 / (qQUDQ > 0 ? qQUDQ : 0.001) +
                            (180.0 - (qhQRuW > 180.0 ? VATSCreateDAT_0103c348 - qhQRuW : qhQRuW)) / 180.0);
                qhQRuW = VATSCreateFUN_00408840((float)(qhQRuW > 180.0 ? VATSCreateDAT_0103c348 - qhQRuW : qhQRuW));
                qOHwfb->GetItem()->fAngleDifference = qhQRuW;
                qOHwfb->GetItem()->fDistance = qQUDQ;
                qOHwfb = qOHwfb->GetNext();
            }
        }
        qOHwfb = &VATSCreateDAT_011db150;
        qyFp = 0.0f;
        qGTHx = 0;
        qtOMjSX = false;
        while (qOHwfb && !qOHwfb->IsEmpty())
        {
            if ((qOHwfb->GetItem()->m_fTargetAngle > qyFp && !qtOMjSX) ||
                (qOHwfb->GetItem()->fAngleDifference < *VATSCreateDAT_011cfec4.Int() && qOHwfb->GetItem()->bVisible &&
                 (!qGTHx || qOHwfb->GetItem()->fDistance < qGTHx->GetItem()->fDistance)))
            {
                if (qOHwfb->GetItem()->fAngleDifference < *VATSCreateDAT_011cfec4.Int())
                {
                    qtOMjSX = true;
                }
                qyFp = qOHwfb->GetItem()->m_fTargetAngle;
                qGTHx = qOHwfb;
                VATSCreateDAT_011f21cc = qOHwfb->GetItem()->pRef;
                VATSCreateListX<VATSCreateLimbX*>* qZNIZJV = &qOHwfb->GetItem()->kLimbs;
                VATSCreateDAT_011db0d4->m_pTargetChance = qZNIZJV->GetItem();
                while (qZNIZJV && !qZNIZJV->IsEmpty())
                {
                    if (qOHwfb->GetItem()->iType == 1 && qZNIZJV->GetItem()->m_iLimbIndex == 1)
                    {
                        VATSCreateDAT_011db0d4->m_pTargetChance = qZNIZJV->GetItem();
                    }
                    qZNIZJV = qZNIZJV->GetNext();
                }
            }
            qOHwfb = qOHwfb->GetNext();
        }
        VATSCreateDAT_011db0d4->b118 = 0;
        VATSCreateDAT_011db150.Sort(VATSCreateFUN_007f0500);
        VATSCreateDAT_011db0d4->bDebounce = 1;
        VATSCreateDAT_011f2250.FUN_009c6c30(1, 0);
        qYdAnhh = VATSCreateFUN_00715d40();
        qjThF = VATSCreateFUN_00715da0();
        qqtISP = VATSCreateFUN_007177c0();
        qxDeKK = VATSCreateFUN_00717820();
        qOPw = VATSCreateFUN_00a00940("_OriginalX", -1);
        qkJsUdT = VATSCreateFUN_00a00940("_TotalWidth", -1);
        qrBzVM = VATSCreateFUN_00a00940("_ImageWidth", -1);
        VATSCreateAudioX::GetSingleton()->FUN_007eb8a0();
        qnEqwa = VATSCreateFUN_007f4890(VATSCreateFUN_00a09030(0x420), "ActionPoints");
        if (!qnEqwa)
        {
            return false;
        }
        qnEqwa->Set(0xfa1, (float)((qYdAnhh - qqtISP * 2) - qnEqwa->GetFloat(0xfb1) + VATSCreateDAT_0101db88), 1);
        qnEqwa->Set(0xfa2, (float)((qjThF - qxDeKK * 2) - qnEqwa->GetFloat(0xfb0)), 1);
        qnEqwa->SetInt(0xfa8, 1);
        VATSCreateDAT_011db0d4->m_pTiles[7] = VATSCreateFUN_007f4830(qnEqwa, "template_right_bracket");
        if (!VATSCreateDAT_011db0d4->m_pTiles[7])
        {
            return false;
        }
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[7], 2);
        VATSCreateDAT_011db0d4->m_pTiles[7]->SetInt(0xfa1, -0x25);
        VATSCreateDAT_011db0d4->m_pTiles[8] = VATSCreateFUN_007f4830(qnEqwa, "template_meter");
        if (!VATSCreateDAT_011db0d4->m_pTiles[8])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[8]->SetInt(qOPw, 0x146);
        VATSCreateDAT_011db0d4->m_pTiles[8]->SetInt(0xfa2, 0x29);
        VATSCreateDAT_011db0d4->m_pTiles[8]->SetInt(0xfad, 5);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[8], 3);
        VATSCreateDAT_011db0d4->m_pTiles[9] = VATSCreateFUN_007f4830(qnEqwa, "template_meter");
        if (!VATSCreateDAT_011db0d4->m_pTiles[9])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[9]->SetInt(qOPw, 0x146);
        VATSCreateDAT_011db0d4->m_pTiles[9]->SetInt(0xfa2, 0x29);
        VATSCreateDAT_011db0d4->m_pTiles[9]->SetInt(0xfa9, 0x80);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[9], 3);
        VATSCreateDAT_011db0d4->m_pTiles[10] = VATSCreateFUN_007f4830(qnEqwa, "template_justify_right_text");
        if (!VATSCreateDAT_011db0d4->m_pTiles[10])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[10]->SetInt(0xfa1, 0x13b);
        VATSCreateDAT_011db0d4->m_pTiles[10]->SetInt(0xfa2, 8);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[10], 0);
        VATSCreateDAT_011db0d4->m_pTiles[10]->Set(0xfc4, VATSCreateDAT_011d3e8c.String(), 1);
        VATSCreateDAT_011db0d4->m_pTiles[11] = VATSCreateFUN_007f4830(qnEqwa, "template_justify_right_text");
        if (!VATSCreateDAT_011db0d4->m_pTiles[11])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[11]->SetInt(0xfa1, 0x10e);
        VATSCreateDAT_011db0d4->m_pTiles[11]->SetInt(0xfa2, 8);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[11], 0);
        VATSCreateDAT_011db0d4->m_pTiles[11]->Set(0xfc4, VATSCreateDAT_011d1d90.String(), 1);
        VATSCreateDAT_011db0d4->m_pTiles[11]->SetInt(0xfa3, 0);
        VATSCreateDAT_011db0d4->m_pTiles[12] = VATSCreateFUN_007f4830(qnEqwa, "template_justify_right_text");
        if (!VATSCreateDAT_011db0d4->m_pTiles[12])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[12]->SetInt(0xfa1, 0x13b);
        VATSCreateDAT_011db0d4->m_pTiles[12]->SetInt(0xfa2, 0x50);
        VATSCreateDAT_011db0d4->m_pTiles[12]->SetInt(0xfb9, 7);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[12], 0);
        VATSCreateDAT_011db0d4->m_pTiles[13] = VATSCreateFUN_007f4830(qnEqwa, "template_justify_right_text");
        if (!VATSCreateDAT_011db0d4->m_pTiles[13])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[13]->SetInt(0xfa1, 0x50);
        VATSCreateDAT_011db0d4->m_pTiles[13]->Set(0xfa2, VATSCreateDAT_011db0d4->m_pTiles[12]->GetFloat(0xfa2), 1);
        VATSCreateDAT_011db0d4->m_pTiles[13]->SetInt(0xfb9, 7);
        VATSCreateDAT_011db0d4->m_pTiles[13]->Set(0xfc4, VATSCreateDAT_011d4da4.String(), 1);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[13], 0);
        VATSCreateDAT_011db0d4->m_pTiles[14] = qSVM->AddTileFromTemplate(qnEqwa, "template_meter", 0);
        VATSCreateDAT_011db0d4->m_pTiles[14]->SetInt(qOPw, 0x5a);
        VATSCreateDAT_011db0d4->m_pTiles[14]->Set(
            0xfa2, (float)(VATSCreateDAT_011db0d4->m_pTiles[12]->GetFloat(0xfa2) + 3.0), 1);
        VATSCreateDAT_011db0d4->m_pTiles[14]->Set(0xfcc, "Interface\\VATS\\vats_bar.dds", 1);
        VATSCreateDAT_011db0d4->m_pTiles[14]->SetInt(qkJsUdT, 0x3c);
        VATSCreateDAT_011db0d4->m_pTiles[14]->SetInt(qrBzVM, 1);
        VATSCreateDAT_011db0d4->m_pTiles[14]->SetInt(0xfb8, 0xc8);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[14], 3);
        VATSCreateDAT_011db0d4->m_pTiles[15] = qSVM->AddTileFromTemplate(qnEqwa, "template_meter_background", 0);
        VATSCreateDAT_011db0d4->m_pTiles[15]->Set(
            0xfa2, (float)(VATSCreateDAT_011db0d4->m_pTiles[12]->GetFloat(0xfa2) + 3.0), 1);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[15], 4);
        VATSCreateDAT_011db0d4->m_fValue1 =
            VATSCreateFUN_00404010(0.0f, VATSCreateFUN_00404010(VATSCreateDAT_011dea3c->kAVOwner.GetBaseActorValue(0xc),
                                                                VATSCreateDAT_011dea3c->kAVOwner.GetActorValue(0xc)));
        VATSCreateDAT_011db0d4->m_fOverrideActionPoints =
            VATSCreateFUN_00404010(0.0f, VATSCreateDAT_011dea3c->kAVOwner.GetActorValue(0xc));
        VATSCreateFUN_007748b0(VATSCreateDAT_011db0d4->m_pTiles[8],
                               VATSCreateDAT_011db0d4->m_fOverrideActionPoints / VATSCreateDAT_011db0d4->m_fValue1, 1,
                               0, 0);
        VATSCreateFUN_007748b0(VATSCreateDAT_011db0d4->m_pTiles[9],
                               VATSCreateDAT_011db0d4->m_fOverrideActionPoints / VATSCreateDAT_011db0d4->m_fValue1, 1,
                               0, 0);
        qLCwQ = VATSCreateFUN_007f4890(VATSCreateFUN_00a09030(0x420), "HitPoints");
        if (!qLCwQ)
        {
            return false;
        }
        qLCwQ->SetInt(0xfa1, qqtISP * 2 + 10);
        qLCwQ->Set(0xfa2, (float)((qjThF - qxDeKK * 2) - qLCwQ->GetFloat(0xfb0)), 1);
        qLCwQ->SetInt(0xfa8, 1);
        VATSCreateDAT_011db0d4->m_pTiles[16] = VATSCreateFUN_007f4830(qLCwQ, "template_left_bracket");
        if (!VATSCreateDAT_011db0d4->m_pTiles[16])
        {
            return false;
        }
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[16], 2);
        VATSCreateDAT_011db0d4->m_pTiles[17] = VATSCreateFUN_007f4830(qLCwQ, "template_meter");
        if (!VATSCreateDAT_011db0d4->m_pTiles[17])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[17]->SetInt(qOPw, 0x14);
        VATSCreateDAT_011db0d4->m_pTiles[17]->SetInt(0xfa2, 0x29);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[17], 3);
        VATSCreateDAT_011db0d4->m_pTiles[18] = VATSCreateFUN_007f4830(qLCwQ, "template_justify_right_text");
        if (!VATSCreateDAT_011db0d4->m_pTiles[18])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[18]->SetInt(0xfa1, 0x35);
        VATSCreateDAT_011db0d4->m_pTiles[18]->SetInt(0xfa2, 8);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[18], 0);
        VATSCreateDAT_011db0d4->m_pTiles[18]->Set(0xfc4, VATSCreateDAT_011d300c.String(), 1);
        VATSCreateDAT_011db0d4->m_pTiles[22] = VATSCreateFUN_007f4830(qLCwQ, "template_compass_window");
        if (!VATSCreateDAT_011db0d4->m_pTiles[22])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[19] =
            VATSCreateFUN_007f4830(VATSCreateDAT_011db0d4->m_pTiles[22], "template_compass_icon_group");
        if (!VATSCreateDAT_011db0d4->m_pTiles[19])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[19]->SetInt(0xfa2, 0x1e);
        VATSCreateDAT_011db0d4->m_pTiles[20] =
            VATSCreateFUN_007f4830(VATSCreateDAT_011db0d4->m_pTiles[22], "template_compass_icon_group");
        if (!VATSCreateDAT_011db0d4->m_pTiles[20])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[20]->SetInt(0xfa2, 0x1e);
        VATSCreateDAT_011db0d4->m_pTiles[21] =
            VATSCreateFUN_007f4830(VATSCreateDAT_011db0d4->m_pTiles[22], "template_compass_icon_group");
        if (!VATSCreateDAT_011db0d4->m_pTiles[21])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[21]->SetInt(0xfa2, 10);
        for (int qfpzU = 0; qfpzU < *VATSCreateDAT_011d32d0.Int(); qfpzU++)
        {
            VATSCreateTileX* qXSF =
                VATSCreateDAT_011db0d4->AddTileFromTemplate(VATSCreateDAT_011db0d4->m_pTiles[21], "compass_npc_icon", 0);
        }
        for (int qgqKr = 0; qgqKr < 10; qgqKr++)
        {
            VATSCreateTileX* qBMjHz = VATSCreateDAT_011db0d4->AddTileFromTemplate(VATSCreateDAT_011db0d4->m_pTiles[20],
                                                                           "template_compass_icon_quest", 0);
        }
        qQGWBE = VATSCreateDAT_011db0d4->AddTileFromTemplate(VATSCreateDAT_011db0d4->m_pTiles[20],
                                                      "template_compass_icon_player", 0);
        for (int qoqcoe = 0; qoqcoe < 10; qoqcoe++)
        {
            VATSCreateTileX* qVCM = VATSCreateDAT_011db0d4->AddTileFromTemplate(VATSCreateDAT_011db0d4->m_pTiles[19],
                                                                         "template_compass_icon_marker", 0);
        }
        qoPB = VATSCreateFUN_007f4890(VATSCreateFUN_00a09030(0x420), "EnemyHealth");
        if (!qoPB)
        {
            return false;
        }
        qoPB->Set(0xfa1, (float)(qYdAnhh / 2 - qoPB->GetFloat(0xfb1) / 2.0), 1);
        qoPB->SetInt(0xfa2, qjThF - qxDeKK * 2 - 0x58);
        qoPB->SetInt(0xff4, 2);
        VATSCreateDAT_011db0d4->m_pTiles[23] = VATSCreateFUN_007f4830(qoPB, "template_warning_background");
        if (!VATSCreateDAT_011db0d4->m_pTiles[23])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[23]->Set(0xfb1, qoPB->GetFloat(0xfb1), 1);
        VATSCreateDAT_011db0d4->m_pTiles[23]->Set(0xfb0, (float)(qoPB->GetFloat(0xfb0) + VATSCreateDAT_01020998), 1);
        VATSCreateDAT_011db0d4->FUN_00726070();
        VATSCreateFUN_00a04200(0);
        VATSCreateDAT_011db0d4->m_pTiles[24] = VATSCreateFUN_007f4830(qoPB, "template_enemy_health_bracket");
        if (!VATSCreateDAT_011db0d4->m_pTiles[24])
        {
            return false;
        }
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[24], 1);
        VATSCreateDAT_011db0d4->m_pTiles[24]->SetInt(0xfa3, 1);
        VATSCreateDAT_011db0d4->m_pTiles[25] = VATSCreateFUN_007f4830(qoPB, "template_meter");
        if (!VATSCreateDAT_011db0d4->m_pTiles[25])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[25]->SetInt(qOPw, 0xab);
        VATSCreateDAT_011db0d4->m_pTiles[25]->SetInt(qkJsUdT, 0xf0);
        VATSCreateDAT_011db0d4->m_pTiles[25]->SetInt(0xfa2, 3);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[25], 3);
        VATSCreateDAT_011db0d4->m_pTiles[25]->SetInt(0xfa3, 1);
        VATSCreateDAT_011db0d4->m_pTiles[27] = VATSCreateFUN_007f4830(qoPB, "template_meter");
        if (!VATSCreateDAT_011db0d4->m_pTiles[27])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[27]->SetInt(qOPw, 0xab);
        VATSCreateDAT_011db0d4->m_pTiles[27]->SetInt(qkJsUdT, 0xf0);
        VATSCreateDAT_011db0d4->m_pTiles[27]->SetInt(0xfa2, 3);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[27], 3);
        VATSCreateDAT_011db0d4->m_pTiles[27]->SetInt(0xfa3, 0);
        VATSCreateDAT_011db0d4->m_pTiles[26] =
            VATSCreateFUN_007f4830(VATSCreateDAT_011db0d4->m_pTiles[27], "template_meter");
        if (!VATSCreateDAT_011db0d4->m_pTiles[26])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[26]->SetInt(qOPw, 0xaf);
        VATSCreateDAT_011db0d4->m_pTiles[26]->SetInt(qkJsUdT, 0xf0);
        VATSCreateDAT_011db0d4->m_pTiles[26]->SetInt(0xfa2, 3);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[26], 3);
        VATSCreateDAT_011db0d4->m_pTiles[26]->SetInt(0xfa3, 0);
        VATSCreateDAT_011db0d4->m_pTiles[28] = VATSCreateFUN_007f4830(qoPB, "template_justify_center_text");
        if (!VATSCreateDAT_011db0d4->m_pTiles[28])
        {
            return false;
        }
        VATSCreateDAT_011db0d4->m_pTiles[28]->SetInt(0xfa1, 0xaa);
        VATSCreateDAT_011db0d4->m_pTiles[28]->SetInt(0xfa2, 0x23);
        VATSCreateDAT_011db0d4->m_pTiles[28]->SetInt(0xfba, 0x15e);
        VATSCreateFUN_00774800(VATSCreateDAT_011db0d4->m_pTiles[28], 0);
        VATSCreatePtrX<VATSCreateTexX> qxWmVch(0);
        qxWmVch = VATSCreateSourceTextureX::Create(
            VATSCreateFixedStringX("Textures\\Interface\\HUD\\hud_compass_alphamap.dds"), VATSCreateDAT_011a9598, 1, 0);
        VATSCreateDAT_011db0d4->m_pTiles[22]->GetNode()->FUN_007700b0(qxWmVch);
        VATSCreateDAT_011db0d4->m_pTiles[22]->GetNode()->FUN_007700d0(1);
        if (!VATSCreateDAT_011db0d4->HasAllSlotsSet(&qidnYUK))
        {
            VATSCreateFUN_0040fbe0(
                "VATS Menu Creation Failed... This likely means that the archives were not built and the xml doesn't match the code.");
            VATSCreateFUN_007037e0();
            return false;
        }
        if (qrEZrs->GetFloat(0xfa7) == VATSCreateDAT_010704f0 || qrEZrs->GetFloat(0xfa7) == VATSCreateDAT_010704e8)
        {
            qrEZrs->Set(0xfad, qfTOqo, 1);
        }
        VATSCreateStringX qQMZREG;
        qzYzlc = VATSCreateDAT_011de7b8.FUN_00867da0();
        qRFOo = qzYzlc;
        qZgNzZy = (qzYzlc - qRFOo) * VATSCreateDAT_01012638;
        qbfQdhM = qRFOo < 1.0 ? 12.0 : (qRFOo > 12.0 ? qRFOo - 12.0 : qRFOo);
        VATSCreateDAT_011a0b70 = -1;
        VATSCreateDAT_011a59f0 = 0x19;
        VATSCreateDAT_011dea3c->SetActiveState(0, 0, 0);
        VATSCreateDAT_011db0cc = 0;
        VATSCreateDAT_011db0d4->kActions.Initialize(VATSCreateDAT_011db0d4->m_pTiles[0], "queued_action");
        qXMUYT = VATSCreateFUN_00ad9060();
        VATSCreateBSSoundHandleX qDdzMIp;
        qDdzMIp = qXMUYT->ResolveAudioHandle("UIVATSEnter", 0x121);
        qDdzMIp.Play(0);
        VATSCreateDAT_011db0d4->m_bStateFlag5 = 0;
        VATSCreateDAT_011db0d4->m_bStateFlag9 = 0;
        VATSCreateDAT_011db0d4->m_bAdditionalStateFlag = 0;
        VATSCreateDAT_011db0d4->m_bStateFlag1 = 0;
        VATSCreateDAT_011db0d4->m_bStateFlag2 = 0;
        VATSCreateDAT_011db0d4->m_bStateFlag10 = 0;
        VATSCreateDAT_011db0d4->m_bStateFlag6 = 0;
        VATSCreateDAT_011db0d4->m_bStateFlag3 = 0;
        VATSCreateDAT_011db0d4->m_uiTargetCount = VATSCreateDAT_011f6394.FUN_00825c00();
        qMBds = VATSCreateDAT_011dea3c->GetProcess()->GetEquippedWeapon();
        qYvz = qMBds ? qMBds->FUN_0044ddc0() : 0;
        if (!qYvz || VATSCreateFUN_006450c0(qYvz) || qYvz->GetWeaponType() == 10)
        {
            VATSCreateDAT_011db0d4->m_pTiles[5]->SetInt(0xfa3, 0);
        }
        VATSCreateFUN_004b7210()->kHUD.FUN_00718630(VATSCreateFUN_00709d40() ? 0x1b : 0x15, VATSCreateFUN_007eb8c0(),
                                                    0x200);
        qYvToq = VATSCreateFUN_0066dce0(qYvz, 1, 0);
        if (VATSCreateDAT_011db0d4->m_fOverrideActionPoints < qYvToq)
        {
            VATSCreateDAT_011db0d4->m_pTiles[6]->SetInt(0xfaf, 0);
        }
        if (VATSCreateFUN_00408b20(VATSCreateDAT_011c3cb4.String(), VATSCreateDAT_01018348))
        {
            VATSCreateDAT_011db0d4->m_pTiles[6]->Set(0xfc4, VATSCreateDAT_011d5080.String(), 1);
            VATSCreateDAT_011db0d4->m_pTiles[3]->Set(0xfc4, VATSCreateDAT_011d26f4.String(), 1);
            VATSCreateDAT_011db0d4->m_pTiles[4]->Set(0xfc4, VATSCreateDAT_011d21c0.String(), 1);
            VATSCreateDAT_011db0d4->m_pTiles[5]->Set(0xfc4, VATSCreateDAT_011d2b74.String(), 1);
            VATSCreateDAT_011db0d4->FUN_00726070()
                ->FUN_00a03da0("Target_button")
                ->Set(0xfc4, VATSCreateDAT_011d4d38.String(), 1);
        }
        qIpA = VATSCreateDAT_011db0d4->FUN_00726070()->FUN_00a03da0("BodyPart_button");
        if (qIpA)
        {
            qIpA->Set(VATSCreateFUN_00a01860("_xbox_button"), "&xbuttonls;", 1);
            qIpA->SetInt(VATSCreateFUN_00a01860("_xbox_button"), 0x11);
        }
        qIpA = VATSCreateDAT_011db0d4->FUN_00726070()->FUN_00a03da0("Target_button");
        if (qIpA)
        {
            qIpA->Set(VATSCreateFUN_00a01860("_xbox_button"), "&xbuttonrs;", 1);
            qIpA->SetInt(VATSCreateFUN_00a01860("_xbox_button"), 0x12);
        }
        VATSCreateFUN_007eb920(qYvz);
        qSVM->FUN_00a1dc20(0);
        return true;
    }
    else if (qSVM && qSVM->FUN_00726070())
    {
        delete qSVM;
    }
    return false;
}

struct SneakPlayer
{
    bool FUN_00953c50(bool*);
    unsigned char GetByteAt5F8();
};
struct SneakStringSetting
{
    const char* FUN_00403df0();
};
struct SneakFloatSetting
{
    float* FUN_00403e20();
};
__if_not_exists(GlobalObject_0040c150::GlobalObject_0040c150)
{
    class GlobalObject_0040c150
    {
      public:
        const char* FUN_00403df0();
    };
}
__if_not_exists(GlobalObject_004de370::GlobalObject_004de370)
{
    class GlobalObject_004de370
    {
      public:
        float* FUN_00403e20();
    };
}
__if_not_exists(g_011d4804)
{
    extern GlobalObject_0040c150 g_011d4804;
}
__if_not_exists(g_011d4eb8)
{
    extern GlobalObject_0040c150 g_011d4eb8;
}
__if_not_exists(g_011d2490)
{
    extern GlobalObject_0040c150 g_011d2490;
}
__if_not_exists(g_011d27b4)
{
    extern GlobalObject_0040c150 g_011d27b4;
}
__if_not_exists(g_011d9774)
{
    extern GlobalObject_004de370 g_011d9774;
}
__if_not_exists(_g_thePlayer)
{
    extern PlayerCharacter* _g_thePlayer;
}
__if_not_exists(HUDMainMenu_pme)
{
    extern HUDMainMenu* HUDMainMenu_pme;
}
struct SneakProcess
{
    int GetHighestDetectionValue(PlayerCharacter*, int);
};
__if_not_exists(ProcessLists::ProcessLists)
{
    class ProcessLists
    {
      public:
        int GetHighestDetectionValue(PlayerCharacter*, int);
    };
}
__if_not_exists(DAT_011e0e80)
{
    extern ProcessLists DAT_011e0e80;
}
struct InteractionTile
{
    void FUN_00700320(int, int);
    void FUN_00a01350(int, const char*, bool);
    bool IsTraitNonZero(int);
    void StartFade(int, float, float, float, int);
    int FindValueByKey(int);
    bool FUN_00a07fc0(int);
    float FUN_00a011b0(int);
};
struct HUDInteraction : HUDMainMenu
{
    void FUN_007732d0();
};
// Updates HUD tile 24 using player state, a process count, and string and float settings.
// @fnv 0x007732d0
void HUDInteraction::FUN_007732d0()
{
    bool blocked = false;
    {
        bool active = false;
        if (((SneakPlayer*)_g_thePlayer)->FUN_00953c50(&blocked) || blocked)
        {
            ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00700320(0xff4, 2);
            if (blocked)
            {
                ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                    ->FUN_00a01350(0xfc4, ((SneakStringSetting*)&g_011d4804)->FUN_00403df0(), true);
            }
            else
            {
                active = true;
                ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                    ->FUN_00a01350(0xfc4, ((SneakStringSetting*)&g_011d4eb8)->FUN_00403df0(), true);
            }
        }
        else if (((SneakPlayer*)_g_thePlayer)->GetByteAt5F8())
        {
            ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00700320(0xff4, 2);
            ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                ->FUN_00a01350(0xfc4, ((SneakStringSetting*)&g_011d4804)->FUN_00403df0(), true);
        }
        else
        {
            int count = ((SneakProcess*)&DAT_011e0e80)->GetHighestDetectionValue(_g_thePlayer, 0);
            ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00700320(0xff4, 1);
            active = false;
            if (count > 0)
            {
                if (!((SneakPlayer*)_g_thePlayer)->GetByteAt5F8())
                    ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                        ->FUN_00a01350(0xfc4, ((SneakStringSetting*)&g_011d2490)->FUN_00403df0(), true);
            }
            else
            {
                ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                    ->FUN_00a01350(0xfc4, ((SneakStringSetting*)&g_011d27b4)->FUN_00403df0(), true);
            }
        }
        if (active && !((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->IsTraitNonZero(0x1004))
        {
            ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                ->StartFade(0xfa9, 0.0f, *((SneakFloatSetting*)&g_011d9774)->FUN_00403e20() * 255.0, 0.5f, 2);
        }
        else if ((!active && ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FindValueByKey(0xfa9) == 2) ||
                 (((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00a07fc0(0xfa9) &&
                  ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00a011b0(0xfa9) !=
                      *((SneakFloatSetting*)&g_011d9774)->FUN_00403e20() * 255.0))
        {
            ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])
                ->StartFade(0xfa9, ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00a011b0(0xfa9),
                               *((SneakFloatSetting*)&g_011d9774)->FUN_00403e20() * 255.0, 0.5f, 0);
        }
        ((InteractionTile*)HUDMainMenu_pme->m_pTiles[24])->FUN_00700320(0x1004, active);
    }
}

class ClearMessagesTile
{
  public:
    void FUN_00a012d0(int trait, float value, bool propagate);
    void FUN_00a01350(int trait, const char* text, bool propagate);
};
struct ClearMessagesList
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    ClearMessagesList* FUN_00726070();
    void FUN_00470470();
};
void __cdecl FormHeap_Free(void*);
extern HUDMainMenu* HUDMainMenu_pme;
struct HUDClearMessages : HUDMainMenu
{
    void FUN_00775920();
    void FUN_00775670();
};

// @fnv 0x00775920
void HUDClearMessages::FUN_00775920()
{
    ClearMessagesList* list = (ClearMessagesList*)m_kMessageList;
    while (list && !list->FUN_008256d0())
    {
        void* message = *list->FUN_006815c0();
        FormHeap_Free(message);
        list = list->FUN_00726070();
    }
    ((ClearMessagesList*)m_kMessageList)->FUN_00470470();
    ((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[27])->FUN_00a012d0(4009, 0.0f, true);
    ((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[26])->FUN_00a01350(4036, g_011d31e0_arg1, true);
    ((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[26])->FUN_00a012d0(4009, 0.0f, true);
    ((ClearMessagesTile*)HUDMainMenu_pme->m_pTiles[25])->FUN_00a012d0(4009, 0.0f, true);
    FUN_00775670();
}

int __cdecl FUN_00408b20(const char* a, const char* b);
struct VisibilityController
{
    static bool __cdecl FUN_004b71d0();
};
VisibilityController* __cdecl FUN_004b7210();
int __cdecl TraitNameToID(const char* text);
struct VisibilityTile;
struct VisibilityChildren
{
    void* FUN_00559450() const;
    VisibilityTile*& FUN_0057cbe0(void*& pos);
};
struct VisibilityTile
{
    void* vtable;
    VisibilityChildren children;
    const char* FUN_00700300();
    void FUN_00700320(int trait, int value);
    void FUN_00a074d0(int flags);
};

// Recursively visits child tiles, then conditionally sets a trait derived from `_360Controller` and applies flag value 4.
// @fnv 0x00719580
void __cdecl FUN_00719580(VisibilityTile* pTile)
{
    VisibilityTile* pChild = 0;
    void* pos = pTile->children.FUN_00559450();
    while (pos)
    {
        pChild = pTile->children.FUN_0057cbe0(pos);
        FUN_00719580(pChild);
    }
    if (!FUN_00408b20(pTile->FUN_00700300(), "xbox_button") || !FUN_00408b20(pTile->FUN_00700300(), "PCShortcutLabel"))
    {
        pTile->FUN_00700320(TraitNameToID("_360Controller"), FUN_004b7210()->FUN_004b71d0());
        pTile->FUN_00a074d0(4);
    }
}
