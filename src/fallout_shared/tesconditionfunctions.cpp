// fallout_shared/tesconditionfunctions.cpp: BGSQuestObjective, Script, IdleAnimationManager, TESQuest and more (272 functions)

#include "tesconditionfunctions_conditionfn_MobileObject.h"
#include "tesconditionfunctions_conditionfn_low_Script.h"
#include "tesconditionfunctions_conditionfn_class_faction.h"
#include "tesconditionfunctions_conditionfn_dep_TESQuest.h"
#include "tesconditionfunctions_conditionfn_BGSQuestObjective.h"
#include "tesconditionfunctions_packet.h"
#include "tesconditionfunctions_conditionfn_dep_TESObjectREFR.h"

class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;

struct PlayerCharacterMovingStateView
{
    unsigned char padding[0x20c];
    unsigned char movingIntoNewSpace;
};

class Actor
{
  public:
    bool IsEssentialActor();
    unsigned int GetActorStateFlags() const;
    BooleanFloatQuery* RefreshActorRuntimeData();
};

// Sets result to 1.0 when the reference is an actor that is essential, otherwise leaves it at 0.0, and returns true.
// @fnv 0x005a3980
bool __cdecl GetEssentialConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference->IsActor())
    {
        Actor* actor = (Actor*)reference;
        if (actor->IsEssentialActor())
            result = 1.0;
    }
    return true;
}

// Sets result to 1.0 if the player is moving into a new space, otherwise leaves it at 0.0, and returns true.
// @fnv 0x005a3a00
bool __cdecl IsPlayerEnteringSpaceConditionFunction(TESObjectREFR* reference, void* apUnused1, void* apUnused2,
                                                    double& result)
{
    result = 0.0;
    if (((PlayerCharacterMovingStateView*)g_thePlayer)->movingIntoNewSpace)
        result = 1.0;
    return true;
}

// @fnv 0x005a3c30
bool GetLastHitLocationConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = -1.0;
    if (reference && reference->IsActor())
    {
        Actor* actor = (Actor*)reference;
        if (actor->RefreshActorRuntimeData())
            result = actor->RefreshActorRuntimeData()->location;
    }
    return true;
}

// @fnv 0x0059e300
ScriptLocals* TESQuest::GetScriptLocalData()
{
    return m_pScriptLocals;
}

// @fnv 0x005a5dc0
bool BGSQuestObjective::GetCompleted() const
{
    return (eState > _State::DISPLAYED) ? true : false;
}

// @fnv 0x005a5e70
bool BGSQuestObjective::GetDisplayed() const
{
    return eState & _State::DISPLAYED;
}

// @fnv 0x0059f770
bool __cdecl Script::GetPCIsSexConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    return IsSexConditionFunction((TESObjectREFR*)g_thePlayer, arg1, arg2, result);
}

// @fnv 0x005a2270
bool TESFaction::GetPCAnEnemy() const
{
    return (factionFlags & 16) ? true : false;
}

// Returns true if aeSkill equals any of the four tagSkills entries.
// @fnv 0x005a5f40
bool TESClass::IsTagSkill(ActorValue::Index aeSkill) const
{
    return tagSkills[0] == aeSkill || tagSkills[1] == aeSkill || tagSkills[2] == aeSkill || tagSkills[3] == aeSkill;
}

// @fnv 0x005a40d0
bool __cdecl Script::GetActorSexConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        unsigned int mode = ((Actor*)reference)->GetActorStateFlags() & 15;
        if (mode & 1)
            result = 1.0;
        else if (mode & 2)
            result = 2.0;
        else if (mode & 4)
            result = 3.0;
        else if (mode & 8)
            result = 4.0;
    }
    return true;
}

// @fnv 0x005a4520
bool MobileObject::GetShouldUseEmotionAnimation() const
{
    return m_bTenthFlag;
}

struct FUN_004fd380_shell : public MobileObject
{
    MobileObject* FUN_004fd380();
};

// @fnv 0x004fd380
MobileObject* FUN_004fd380_shell::FUN_004fd380()
{
    return *(MobileObject**)((char*)this + 0x70);
}

void __cdecl DebugLog(char const*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
struct Pos3
{
    float x, y, z;
};
struct VtblRef
{
    void* pad[0x1f4 / 4];
    Pos3*(__thiscall* GetPos)(void*);
};
struct ObjRef
{
    VtblRef* vtbl;
};
}

__declspec(thread) unsigned char g_bConsoleOutput[0x269];

// Reads the reference's position via its vtable and writes the X, Y or Z component into afReturnValue, logging it when console output is enabled.
// @fnv 0x0059c0c0
bool __cdecl GetPositionComponent(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int iAxis = (int)apParam1;
    if (apRefObject)
    {
        Pos3 pos = *((ObjRef*)apRefObject)->vtbl->GetPos(apRefObject);
        switch (iAxis)
        {
        case 'X':
            afReturnValue = pos.x;
            break;
        case 'Y':
            afReturnValue = pos.y;
            break;
        case 'Z':
            afReturnValue = pos.z;
            break;
        }
        if (g_bConsoleOutput[0x268])
        {
            DebugLog("GetPos: %c >> %0.2f", iAxis, afReturnValue);
        }
    }
    return true;
}

void __cdecl DebugLog(char const*, ...);
extern const double DAT_0102f248;

struct AngleVec3
{
    float x;
    float y;
    float z;
};

struct RecipeCraftingInfo;
class TESRecipe
{
  public:
    RecipeCraftingInfo* GetData();
};

__declspec(thread) extern unsigned char tls_pad_0059c170[0x268];
__declspec(thread) extern bool bConsoleOutput_0059c170;

// @fnv 0x0059c170
bool __cdecl FUN_0059c170(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int iAxis = (int)apParam1;
    if (apRefObject)
    {
        AngleVec3 pos = *(AngleVec3*)((TESRecipe*)apRefObject)->GetData();
        switch (iAxis)
        {
        case 'X':
            afReturnValue = pos.x * DAT_0102f248;
            break;
        case 'Y':
            afReturnValue = pos.y * DAT_0102f248;
            break;
        case 'Z':
            afReturnValue = pos.z * DAT_0102f248;
            break;
        }
        if (bConsoleOutput_0059c170)
        {
            DebugLog("GetAngle: %c >> %0.2f", iAxis, afReturnValue);
        }
    }
    return true;
}

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct TESObjectREFRScaleView : TESObjectREFR
{
    float GetScale();
};

void __cdecl DebugLog(const char*, ...);
extern Twin_0084d030 g_timeGlobal;
extern __declspec(thread) bool bEchoConsole;

// @fnv 0x0059c430
bool __cdecl FUN_0059c430(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Script* pscript = static_cast<Script*>(apParam1);
    if (pscript && pscript->GetHeader()->m_bQuest &&
        reinterpret_cast<TESObjectREFRScaleView*>(pscript)->GetScale() > 0.0)
    {
        afReturnValue = reinterpret_cast<TESObjectREFRScaleView*>(pscript)->GetScale();
    }
    else
    {
        afReturnValue = g_timeGlobal.GetStoredFloatValue();
    }
    if (bEchoConsole)
    {
        DebugLog("GetSecondsPassed >> %0.2f", afReturnValue);
    }
    return true;
}

const char* __cdecl GetActorValueName(unsigned int);
void __cdecl DebugLog(const char*, ...);

struct ActorValueOwner_vtable
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual float GetActorValueF(unsigned int);
};

struct ActorView : public Actor
{
    TESActorBase* GetActorBase();
    bool GetDisabled();
};

__declspec(thread) extern unsigned char tls_pad[0x269];

// Reads an actor value from the reference (or its actor base if disabled) into result and logs it when the TLS flag is set; returns true.
// @fnv 0x0059c4f0
bool __cdecl FUN_0059c4f0(TESObjectREFR* reference, void* uiAvCode, void* pUnused, double& result)
{
    unsigned int avCode = (unsigned int)uiAvCode;
    ActorView* actor = 0;
    if (reference && reference->IsActor())
    {
        actor = (ActorView*)reference;
    }
    if (actor)
    {
        if (!actor->GetDisabled())
        {
            result = ((ActorValueOwner_vtable*)((char*)actor + 0xa4))->GetActorValueF(avCode);
        }
        else
        {
            ActorValueOwner_vtable* pActorValueOwner = (ActorValueOwner_vtable*)((char*)actor->GetActorBase() + 0x100);
            result = pActorValueOwner->GetActorValueF(avCode);
        }
        if (tls_pad[0x268])
        {
            DebugLog("GetActorValue: %s >> %0.2f", GetActorValueName(avCode), result);
        }
    }
    return true;
}

float __fastcall GetHealthFraction(Actor* pActor);
void __cdecl DebugLog(char const*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
__declspec(thread) unsigned char tls_padding[0x268];
__declspec(thread) bool bVerboseMode;
}

// If the reference is an Actor, stores its health percentage in afReturnValue and logs it when verbose mode is on; always returns true.
// @fnv 0x0059c7e0
bool __cdecl FUN_0059c7e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pActor = 0;
    if (apRefObject && apRefObject->IsActor())
    {
        pActor = (Actor*)apRefObject;
    }
    if (pActor)
    {
        afReturnValue = GetHealthFraction(pActor);
        if (bVerboseMode)
        {
            DebugLog("GetHealthPercentage >> %0.2f", afReturnValue);
        }
    }
    return true;
}

class Calendar
{
  public:
    float GetGameTime();
};
extern Calendar g_calendar;
void __cdecl DebugLog(char const*, ...);

struct TLSData_0059c8e0
{
    unsigned char pad[0x268];
    bool consoleEcho;
};

__declspec(thread) TLSData_0059c8e0 g_tlsData_0059c8e0;

// Stores the calendar's current time into afReturnValue, logs it when console echo is enabled, and returns true.
// @fnv 0x0059c8e0
bool __cdecl FUN_0059c8e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = g_calendar.GetGameTime();
    if (g_tlsData_0059c8e0.consoleEcho)
    {
        DebugLog("GetCurrentTime >> %0.2f", afReturnValue);
    }
    return true;
}

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
struct FUN_0059ce80_shell : public CFilter
{
    void FUN_0059ce80(unsigned int);
};

// Clears the high 16 bits of iFilter and stores aiGroup shifted into them.
// @fnv 0x0059ce80
void FUN_0059ce80_shell::FUN_0059ce80(unsigned int aiGroup)
{
    iFilter &= 0xFFFF;
    iFilter |= (aiGroup << 16);
}

struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
typedef char _sizecheck_hkpWorldRayCastInput[sizeof(WorldRayCastInput) == 48 ? 1 : -1];
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
typedef char _sizecheck_hkpShapeRayCastCollectorOutput[sizeof(RayCastHitResult) == 32 ? 1 : -1];
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
typedef char _sizecheck_hkpShapeRayCastOutput[sizeof(ShapeRayCastOutput) == 80 ? 1 : -1];
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
typedef char _sizecheck_hkpWorldRayCastOutput[sizeof(WorldRayCastOutput) == 96 ? 1 : -1];
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
typedef char _sizecheck_bhkPickData[sizeof(BhkPickData) == 176 ? 1 : -1];
struct FUN_0059ceb0_shell : public BhkPickData
{
    void FUN_0059ceb0(hkpClosestRayHitCollector*);
};

// Stores apCollector as the closest-hit collector and clears the all-hit collector pointer.
// @fnv 0x0059ceb0
void FUN_0059ceb0_shell::FUN_0059ceb0(hkpClosestRayHitCollector* apCollector)
{
    m_pClosestCollector = apCollector;
    m_pAllCollector = 0;
}

void __fastcall FUN_0059cf00(void* this_ptr);

// @fnv 0x0059cee0
void __fastcall FUN_0059cee0(void* this_ptr)
{
    FUN_0059cf00(this_ptr);
}

extern int DAT_01034ec4;
void __fastcall FUN_004a3ae0(void*);

// @fnv 0x0059cf00
void __fastcall FUN_0059cf00(void** pThis)
{
    *pThis = &DAT_01034ec4;
    FUN_004a3ae0(pThis);
}

void __cdecl DebugLog(char const*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
struct VCallRef
{
    bool(__thiscall** vtable)(void*);
};
struct VCallActor
{
    bool(__thiscall** vtable)(void*, bool);
};
__declspec(thread) char tls_pad[0x268];
__declspec(thread) bool bConsoleEcho;
}

// Sets afReturnValue to 1.0 if apRefObject is an Actor whose vtable call at 0x22c returns true, else 0.0, and logs it when console echo is on.
// @fnv 0x0059d840
bool __cdecl FUN_0059d840(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pactor = 0;
    if (apRefObject && ((VCallRef*)apRefObject)->vtable[0x100 / 4](apRefObject))
    {
        pactor = (Actor*)apRefObject;
    }
    if (pactor)
    {
        if (((VCallActor*)pactor)->vtable[0x22c / 4](pactor, true))
        {
            afReturnValue = 1.0;
        }
    }
    if (bConsoleEcho)
    {
        DebugLog("GetDead >> %0.2f", afReturnValue);
    }
    return true;
}

void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern unsigned char g_bConditionTlsPad[0x268];
__declspec(thread) extern bool g_bConditionConsoleEcho;

// Accumulates a score from the actor's state via a virtual call and logs it when console echo is enabled; always returns true.
// @fnv 0x0059dc90
bool __cdecl FUN_0059dc90(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    Actor* pactor = 0;
    if (reference && reference->IsActor())
        pactor = (Actor*)reference;
    if (pactor)
    {
        switch ((*(unsigned int(__thiscall**)(Actor*))(*(unsigned int*)pactor + 0x214))(pactor))
        {
        case 10:
            result += 1.0;
        case 9:
            result += 1.0;
        case 7:
        case 8:
            result += 1.0;
        case 6:
            result += 1.0;
        }
    }
    if (g_bConditionConsoleEcho)
        DebugLog("GetSleeping >> %0.2f", result);
    return true;
}

void __cdecl DebugLog(const char*, ...);
struct SitTls
{
    char pad[0x268];
    unsigned char flag;
};
__declspec(thread) SitTls g_sitTls;
struct SitRef
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
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
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual bool IsActor();
};
struct SitActor
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
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
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual void b57();
    virtual void b58();
    virtual void b59();
    virtual void b60();
    virtual void b61();
    virtual void b62();
    virtual void b63();
    virtual void b64();
    virtual void b65();
    virtual void b66();
    virtual void b67();
    virtual void b68();
    virtual void b69();
    virtual void b70();
    virtual void b71();
    virtual void b72();
    virtual void b73();
    virtual void b74();
    virtual void b75();
    virtual void b76();
    virtual void b77();
    virtual void b78();
    virtual void b79();
    virtual void b80();
    virtual void b81();
    virtual void b82();
    virtual void b83();
    virtual void b84();
    virtual void b85();
    virtual void b86();
    virtual void b87();
    virtual void b88();
    virtual void b89();
    virtual void b90();
    virtual void b91();
    virtual void b92();
    virtual void b93();
    virtual void b94();
    virtual void b95();
    virtual void b96();
    virtual void b97();
    virtual void b98();
    virtual void b99();
    virtual void b100();
    virtual void b101();
    virtual void b102();
    virtual void b103();
    virtual void b104();
    virtual void b105();
    virtual void b106();
    virtual void b107();
    virtual void b108();
    virtual void b109();
    virtual void b110();
    virtual void b111();
    virtual void b112();
    virtual void b113();
    virtual void b114();
    virtual void b115();
    virtual void b116();
    virtual void b117();
    virtual void b118();
    virtual void b119();
    virtual void b120();
    virtual void b121();
    virtual void b122();
    virtual void b123();
    virtual void b124();
    virtual void b125();
    virtual void b126();
    virtual void b127();
    virtual void b128();
    virtual void b129();
    virtual void b130();
    virtual void b131();
    virtual void b132();
    virtual unsigned int GetActorStateFlags();
};
// @fnv 0x0059dd90
bool __cdecl FUN_0059dd90(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    SitActor* pactor = 0;
    if (reference && ((SitRef*)reference)->IsActor())
        pactor = (SitActor*)reference;
    if (pactor)
    {
        switch (pactor->GetActorStateFlags())
        {
        case 5:
            result += 1.0;
        case 4:
            result += 1.0;
        case 2:
        case 3:
            result += 1.0;
        case 1:
            result += 1.0;
        }
    }
    if (g_sitTls.flag)
        DebugLog("GetSitting >> %0.2f", result);
    return true;
}

void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern bool bEcho;

class Sky;
class TES
{
  public:
    Sky* GetLogDate(void);
};

struct VTable_100
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual bool IsActor();
};

struct VTable_4C4
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119();
    virtual void vfn_120();
    virtual void vfn_121();
    virtual void vfn_122();
    virtual void vfn_123();
    virtual void vfn_124();
    virtual void vfn_125();
    virtual void vfn_126();
    virtual void vfn_127();
    virtual void vfn_128();
    virtual void vfn_129();
    virtual void vfn_130();
    virtual void vfn_131();
    virtual void vfn_132();
    virtual void vfn_133();
    virtual void vfn_134();
    virtual void vfn_135();
    virtual void vfn_136();
    virtual void vfn_137();
    virtual void vfn_138();
    virtual void vfn_139();
    virtual void vfn_140();
    virtual void vfn_141();
    virtual void vfn_142();
    virtual void vfn_143();
    virtual void vfn_144();
    virtual void vfn_145();
    virtual void vfn_146();
    virtual void vfn_147();
    virtual void vfn_148();
    virtual void vfn_149();
    virtual void vfn_150();
    virtual void vfn_151();
    virtual void vfn_152();
    virtual void vfn_153();
    virtual void vfn_154();
    virtual void vfn_155();
    virtual void vfn_156();
    virtual void vfn_157();
    virtual void vfn_158();
    virtual void vfn_159();
    virtual void vfn_160();
    virtual void vfn_161();
    virtual void vfn_162();
    virtual void vfn_163();
    virtual void vfn_164();
    virtual void vfn_165();
    virtual void vfn_166();
    virtual void vfn_167();
    virtual void vfn_168();
    virtual void vfn_169();
    virtual void vfn_170();
    virtual void vfn_171();
    virtual void vfn_172();
    virtual void vfn_173();
    virtual void vfn_174();
    virtual void vfn_175();
    virtual void vfn_176();
    virtual void vfn_177();
    virtual void vfn_178();
    virtual void vfn_179();
    virtual void vfn_180();
    virtual void vfn_181();
    virtual void vfn_182();
    virtual void vfn_183();
    virtual void vfn_184();
    virtual void vfn_185();
    virtual void vfn_186();
    virtual void vfn_187();
    virtual void vfn_188();
    virtual void vfn_189();
    virtual void vfn_190();
    virtual void vfn_191();
    virtual void vfn_192();
    virtual void vfn_193();
    virtual void vfn_194();
    virtual void vfn_195();
    virtual void vfn_196();
    virtual void vfn_197();
    virtual void vfn_198();
    virtual void vfn_199();
    virtual void vfn_200();
    virtual void vfn_201();
    virtual void vfn_202();
    virtual void vfn_203();
    virtual void vfn_204();
    virtual void vfn_205();
    virtual void vfn_206();
    virtual void vfn_207();
    virtual void vfn_208();
    virtual void vfn_209();
    virtual void vfn_210();
    virtual void vfn_211();
    virtual void vfn_212();
    virtual void vfn_213();
    virtual void vfn_214();
    virtual void vfn_215();
    virtual void vfn_216();
    virtual void vfn_217();
    virtual void vfn_218();
    virtual void vfn_219();
    virtual void vfn_220();
    virtual void vfn_221();
    virtual void vfn_222();
    virtual void vfn_223();
    virtual void vfn_224();
    virtual void vfn_225();
    virtual void vfn_226();
    virtual void vfn_227();
    virtual void vfn_228();
    virtual void vfn_229();
    virtual void vfn_230();
    virtual void vfn_231();
    virtual void vfn_232();
    virtual void vfn_233();
    virtual void vfn_234();
    virtual void vfn_235();
    virtual void vfn_236();
    virtual void vfn_237();
    virtual void vfn_238();
    virtual void vfn_239();
    virtual void vfn_240();
    virtual void vfn_241();
    virtual void vfn_242();
    virtual void vfn_243();
    virtual void vfn_244();
    virtual void vfn_245();
    virtual void vfn_246();
    virtual void vfn_247();
    virtual void vfn_248();
    virtual void vfn_249();
    virtual void vfn_250();
    virtual void vfn_251();
    virtual void vfn_252();
    virtual void vfn_253();
    virtual void vfn_254();
    virtual void vfn_255();
    virtual void vfn_256();
    virtual void vfn_257();
    virtual void vfn_258();
    virtual void vfn_259();
    virtual void vfn_260();
    virtual void vfn_261();
    virtual void vfn_262();
    virtual void vfn_263();
    virtual void vfn_264();
    virtual void vfn_265();
    virtual void vfn_266();
    virtual void vfn_267();
    virtual void vfn_268();
    virtual void vfn_269();
    virtual void vfn_270();
    virtual void vfn_271();
    virtual void vfn_272();
    virtual void vfn_273();
    virtual void vfn_274();
    virtual void vfn_275();
    virtual void vfn_276();
    virtual void vfn_277();
    virtual void vfn_278();
    virtual void vfn_279();
    virtual void vfn_280();
    virtual void vfn_281();
    virtual void vfn_282();
    virtual void vfn_283();
    virtual void vfn_284();
    virtual void vfn_285();
    virtual void vfn_286();
    virtual void vfn_287();
    virtual void vfn_288();
    virtual void vfn_289();
    virtual void vfn_290();
    virtual void vfn_291();
    virtual void vfn_292();
    virtual void vfn_293();
    virtual void vfn_294();
    virtual void vfn_295();
    virtual void vfn_296();
    virtual void vfn_297();
    virtual void vfn_298();
    virtual void vfn_299();
    virtual void vfn_300();
    virtual void vfn_301();
    virtual void vfn_302();
    virtual void vfn_303();
    virtual void vfn_304();
    virtual unsigned int GetFurnitureMarkerID();
};

// If apRefObject is an actor, stores its furniture marker ID into afReturnValue, logs it when bEcho is set, and returns true.
// @fnv 0x0059de90
bool __cdecl FUN_0059de90(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TES* pactor = 0;
    if (apRefObject && ((VTable_100*)apRefObject)->IsActor())
        pactor = (TES*)apRefObject;
    if (pactor)
        afReturnValue = ((VTable_4C4*)pactor->GetLogDate())->GetFurnitureMarkerID();
    if (bEcho)
        DebugLog("GetFurnitureMarkerID >> %0.2f", afReturnValue);
    return true;
}

namespace fnv_0059df40 {
void __cdecl DebugLog(char const*, ...);

class Sky;
class TES
{
  public:
    Sky* GetLogDate(void);
};

struct VTable0x4c8
{
    void* pad[0x4c8 / 4];
    void*(__thiscall* fn4c8)(void*);
};

__declspec(thread) unsigned char tls_pad[0x268];
__declspec(thread) bool tls_bEcho;

// @fnv 0x0059df40
bool __cdecl FUN_0059df40(TESObjectREFR* reference, void* pMatchValue, void* pUnused, double& result)
{
    result = 0.0;
    Actor* pactor = 0;
    if (reference && reference->IsActor())
    {
        pactor = (Actor*)reference;
    }
    if (pactor)
    {
        Sky* p = ((TES*)pactor)->GetLogDate();
        if ((*(VTable0x4c8**)p)->fn4c8(p) == pMatchValue)
        {
            result = 1.0;
        }
    }
    if (tls_bEcho)
    {
        DebugLog("IsCurrentFurnitureRef>> %0.2f", result);
    }
    return true;
}
}  // namespace fnv_0059df40

namespace fnv_0059dfe0 {
class Sky;
class TES
{
  public:
    Sky* GetLogDate();
};

class TESObject
{
  public:
    TESObject* GetNext();
};

template <> class BSSimpleList<Actor*>
{
  public:
    bool IsInList(Actor* const&) const;
};

int __fastcall _FNV_GetFormType(TESForm*);
void __cdecl DebugLog(char const*, ...);

__declspec(thread) extern char g_bConsoleOutput_pad[0x268];
__declspec(thread) extern bool g_bConsoleOutput_flag;

struct ProcessView_0059dfe0
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
    virtual TESObject* GetFurnitureReference();
};

// @fnv 0x0059dfe0
bool __cdecl FUN_0059dfe0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    TESForm* pform;
    Actor* pactor;

    afReturnValue = 0.0;
    pactor = 0;
    if (apRefObject && ((TESForm*)apRefObject)->IsActor())
    {
        pactor = (Actor*)apRefObject;
    }
    pform = (TESForm*)apParam1;
    if (pactor && pform)
    {
        TESObject* pref = ((ProcessView_0059dfe0*)((TES*)pactor)->GetLogDate())->GetFurnitureReference();
        if (pref)
        {
            if (_FNV_GetFormType(pform) == 0x27)
            {
                if (pref->GetNext() == apParam1)
                {
                    afReturnValue = 1.0;
                }
            }
            else if (_FNV_GetFormType(pform) == 0x55)
            {
                Script* plistform = (Script*)pform;
                if (((BSSimpleList<Actor*>*)plistform->GetHeader())->IsInList((Actor*)pref->GetNext()))
                {
                    afReturnValue = 1.0;
                }
            }
        }
    }
    if (g_bConsoleOutput_flag)
    {
        DebugLog("IsCurrentFurnitureObj>> %0.2f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_0059dfe0

void __cdecl DebugLog(char const*, ...);

struct VTableStub_0059e0f0
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual bool GetTalkedToPC();  // 38 (0x98)
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual bool IsActor();  // 64 (0x100)
};

struct TLSData_0059e0f0
{
    char pad[0x268];
    bool bConsoleOutput;
};

__declspec(thread) TLSData_0059e0f0 g_tlsData_0059e0f0;

// @fnv 0x0059e0f0
bool __cdecl FUN_0059e0f0(VTableStub_0059e0f0* apRefObject, VTableStub_0059e0f0* apParam1, void* apParam2,
                          double& afReturnValue)
{
    afReturnValue = 0.0;
    VTableStub_0059e0f0* pActor = 0;
    if (apRefObject)
    {
        if (apRefObject->IsActor())
            pActor = apRefObject;
        else
            pActor = 0;
    }
    else
    {
        pActor = apParam1;
    }

    if (pActor && pActor->GetTalkedToPC())
    {
        afReturnValue = 1.0;
    }

    if (g_tlsData_0059e0f0.bConsoleOutput)
    {
        DebugLog("GetTalkedToPC >> %0.2f", afReturnValue);
    }

    return true;
}

namespace fnv_0059e390 {
void __cdecl DebugLog(const char*, ...);

struct TESQuest_GetCompleted_Helper : public TESQuest
{
    bool GetCompleted();
};

__declspec(thread) extern char tls_pad[0x268];
__declspec(thread) extern bool bConsoleEcho;

// Sets afReturnValue to 1.0 if apParam1 is a completed TESQuest, otherwise 0.0, logs it when console echo is on, and returns true.
// @fnv 0x0059e390
bool __cdecl FUN_0059e390(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESQuest* pQuest = apParam1 ? static_cast<TESQuest*>(apParam1) : 0;
    if (pQuest && static_cast<TESQuest_GetCompleted_Helper*>(pQuest)->GetCompleted())
    {
        afReturnValue = 1.0;
    }
    if ((&bConsoleEcho)[0])
    {
        DebugLog("GetQuestCompleted >> %0.2f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_0059e390

struct FUN_0059e400_shell : public TESQuest
{
    bool FUN_0059e400();
};

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
};

// @fnv 0x0059e400
bool FUN_0059e400_shell::FUN_0059e400()
{
    return (*reinterpret_cast<TESFaction_RankDataView*>(this)->GetRankDataList() & 2) != 0;
}

void __cdecl DebugLog(const char*, ...);

namespace TESQuestNamespace {
class TESQuest
{
  public:
    unsigned int GetStageMask();
};
}

struct TLSData
{
    unsigned char pad[0x268];
    bool bConsoleEcho;
};

__declspec(thread) TLSData g_tlsData;

// Sets afReturnValue to the quest's stage (or 0 if no quest), logs it when console echo is on, and returns true.
// @fnv 0x0059e420
bool __cdecl GetQuestStage(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (TESQuest* pQuest = apParam1 ? static_cast<TESQuest*>(apParam1) : 0)
    {
        afReturnValue = reinterpret_cast<TESQuestNamespace::TESQuest*>(pQuest)->GetStageMask();
    }
    if (g_tlsData.bConsoleEcho)
    {
        DebugLog("GetStage >> %0.2f", afReturnValue);
    }
    return true;
}

namespace fnv_0059e8e0 {
struct Sky
{
    static Sky* __cdecl GetInstance();
    bool IsRaining();
};

void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern char g_tlspad[0x268];
__declspec(thread) extern bool g_consoleEcho;

// Writes 1.0 or 0.0 to result depending on whether Sky::GetInstance()->IsRaining() is true, logs it when console echo is on, and returns true.
// @fnv 0x0059e8e0
bool __cdecl FUN_0059e8e0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    Sky* pWeatherSky = Sky::GetInstance();
    result = pWeatherSky->IsRaining() ? 1.0f : 0.0f;
    if (g_consoleEcho)
        DebugLog("GetIsRaining >> %0.2f", result);
    return true;
}
}  // namespace fnv_0059e8e0

int __fastcall _FNV_GetFormType(void*);
void __cdecl DebugLog(const char*, ...);

struct TESObjectREFR_WorldSpace : TESObjectREFR
{
    TESWorldSpace* GetParentWorldSpace();
};

__declspec(thread) extern char tls_pad_0059f0c0[0x268];
__declspec(thread) extern bool tls_bEchoConsole;

// Sets the return value to 1.0 if the reference (or apParam2 if it is a reference) is in the world space given by apParam1, and logs the result.
// @fnv 0x0059f0c0
bool __cdecl FUN_0059f0c0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;

    TESWorldSpace* pworld = 0;
    if (apParam1 != 0 && _FNV_GetFormType(apParam1) == 0x41)
    {
        pworld = static_cast<TESWorldSpace*>(apParam1);
    }

    TESObjectREFR* pref = 0;
    if (apParam2 != 0)
    {
        switch (_FNV_GetFormType(apParam2))
        {
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x69:
            pref = static_cast<TESObjectREFR*>(apParam2);
            break;
        }
    }

    if (pref == 0)
    {
        pref = apRefObject;
    }

    if (pworld != 0 && static_cast<TESObjectREFR_WorldSpace*>(pref)->GetParentWorldSpace() == pworld)
    {
        *afReturnValue = 1.0;
    }

    if (tls_bEchoConsole)
    {
        DebugLog("GetInWorldspace >> %0.2f", *afReturnValue);
    }

    return true;
}

namespace fnv_0059f3c0 {
int __fastcall _FNV_GetFormType(void* form);
void __cdecl DebugLog(char const* format, ...);
__declspec(thread) extern bool bConsoleOutput;

struct TESObject
{
    TESObject* GetNext(void);
};

enum SEX
{
};

struct TESActorBase
{
    SEX GetSex(void);
};

// Sets afReturnValue to 1.0 when apRefObject's next form is an actor base whose sex matches apParam1, logs the result, and returns true.
// @fnv 0x0059f3c0
bool __cdecl FUN_0059f3c0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESActorBase* pnpc = 0;
    if (apRefObject && _FNV_GetFormType(reinterpret_cast<TESObject*>(apRefObject)->GetNext()) == 0x2a)
    {
        pnpc = reinterpret_cast<TESActorBase*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext());
    }
    if (pnpc && pnpc->GetSex() == reinterpret_cast<int>(apParam1))
    {
        afReturnValue = 1.0;
    }
    if ((&bConsoleOutput)[0x268])
    {
        DebugLog("GetIsSex >> %0.2f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_0059f3c0

extern TESObjectREFR* DAT_011cab10;
extern TESBoundObject* DAT_011cab0c;
TESBoundObject* __fastcall FUN_004216f0(ExtraDataList*);
void __cdecl DebugLog(char const*, ...);

struct TESObject
{
    TESObject* GetNext();
};

struct TLSData_0059f7b0
{
    char pad[0x268];
    bool bConsoleOutput;
};
__declspec(thread) extern TLSData_0059f7b0 tls_0059f7b0;

// Sets afReturnValue to 1.0 if the reference's bound object matches apParam1, otherwise 0.0, and logs the result when console output is enabled.
// @fnv 0x0059f7b0
bool __cdecl FUN_0059f7b0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESBoundObject* pobject = 0;
    if (apParam1 && static_cast<TESForm*>(apParam1)->IsActor_InEditor())
    {
        pobject = static_cast<TESBoundObject*>(apParam1);
    }
    if (apRefObject && pobject)
    {
        TESBoundObject* pcompobj = 0;
        if (apRefObject == DAT_011cab10)
        {
            pcompobj = DAT_011cab0c;
        }
        else
        {
            pcompobj = FUN_004216f0(apRefObject->GetExtraData());
            if (!pcompobj)
            {
                pcompobj = reinterpret_cast<TESBoundObject*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext());
            }
            DAT_011cab10 = apRefObject;
            DAT_011cab0c = pcompobj;
        }
        if (pcompobj == pobject)
        {
            afReturnValue = 1.0;
        }
    }
    if (tls_0059f7b0.bConsoleOutput)
    {
        DebugLog("GetIsID >> %0.2f", afReturnValue);
    }
    return true;
}

void __cdecl DebugLog(const char* fmt, ...);

struct TESObjectREFR_VTable_0059f940
{
    void* pad[0x1a0 / 4];
    bool(__thiscall* IsChild)(void*, bool);
};

struct TESObjectREFR_View_0059f940
{
    TESObjectREFR_VTable_0059f940* vtable;
};

__declspec(thread) extern unsigned char tls_pad_0059f940[0x269];

// Sets afReturnValue to 1.0 if apRefObject's vtable IsChild returns true, otherwise 0.0, logs it when TLS flag is set, and returns true.
// @fnv 0x0059f940
bool __cdecl FUN_0059f940(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject != 0)
    {
        if (((TESObjectREFR_View_0059f940*)apRefObject)->vtable->IsChild(apRefObject, false))
        {
            afReturnValue = 1.0;
        }
    }
    if (tls_pad_0059f940[0x268])
    {
        DebugLog("IsChild >> %0.2f", afReturnValue);
    }
    return true;
}

class IdleAnimationManager
{
  public:
    static TESObject* __cdecl GetCurrentUsedItem(void);
};

void __cdecl DebugLog(char const*, ...);
int __fastcall _FNV_GetFormType(TESObject*);

struct ConsoleEchoTLS
{
    char pad[0x268];
    bool bConsoleEcho;
};

__declspec(thread) extern ConsoleEchoTLS tls_consoleEcho;

// @fnv 0x0059fa90
bool __cdecl FUN_0059fa90(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    int formtype = (int)apParam1;
    if (formtype && IdleAnimationManager::GetCurrentUsedItem() &&
        _FNV_GetFormType(IdleAnimationManager::GetCurrentUsedItem()) == formtype)
    {
        afReturnValue = 1.0;
    }
    if (tls_consoleEcho.bConsoleEcho)
    {
        DebugLog("GetIsUsedItemType >> %0.2f", afReturnValue);
    }
    return true;
}

namespace fnv_0059fb50 {
class IdleAnimationManager
{
  public:
    static bool __cdecl GetUsedItemActivate();
};

void __cdecl DebugLog(char const*, ...);

struct TLSData268
{
    char pad[0x268];
    bool trace;
};

__declspec(thread) TLSData268 g_tlsData268;

// Sets afReturnValue to 1.0 when GetUsedItemActivate is true (else 0.0), logs it if tracing, and returns true.
// @fnv 0x0059fb50
bool __cdecl FUN_0059fb50(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (IdleAnimationManager::GetUsedItemActivate())
    {
        afReturnValue = 1.0;
    }
    if (g_tlsData268.trace)
    {
        DebugLog("GetIsUsedItemActivate >> %0.2f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_0059fb50

int __fastcall _FNV_GetFormType(void* form);
void __cdecl DebugLog(char const*, ...);
extern __declspec(thread) bool bVerboseMode_tls[0x269];

// @fnv 0x0059fbb0
bool __cdecl FUN_0059fbb0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESObjectREFR* pobjRef = 0;
    if (apParam1)
    {
        switch (_FNV_GetFormType(apParam1))
        {
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x69:
            pobjRef = (TESObjectREFR*)apParam1;
            break;
        }
    }
    if (apRefObject && pobjRef && apRefObject == pobjRef)
    {
        afReturnValue = 1.0;
    }
    if (bVerboseMode_tls[0x268])
    {
        DebugLog("GetIsRef >> %0.2f", afReturnValue);
    }
    return true;
}

struct TESGlobalValueReader
{
    float GetValue();
};

int __fastcall _FNV_GetFormType(void* form);
void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern unsigned char g_bConditionTrace[0x269];

// @fnv 0x0059fd30
bool __cdecl FUN_0059fd30(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = -1.0;
    TESGlobalValueReader* pglobal = 0;
    if (apParam1 && _FNV_GetFormType(apParam1) == 6)
        pglobal = (TESGlobalValueReader*)apParam1;
    if (pglobal)
        afReturnValue = pglobal->GetValue();
    if (g_bConditionTrace[0x268])
        DebugLog("GetGlobalValue >> %0.2f", afReturnValue);
    return true;
}

void __cdecl DebugLog(char const*, ...);

struct Actor_Shell : public Actor
{
    bool FUN_00437bd0();
};

struct MobileObject_Shell : public MobileObject
{
    char const* GetFullName();
};

extern __declspec(thread) char g_tlspad[0x268];
extern __declspec(thread) bool g_bEchoConsole;

// Sets result to 1.0 if the reference is an actor that is unconscious, logs the state when console echo is on, and returns true.
// @fnv 0x0059fee0
bool __cdecl FUN_0059fee0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    Actor* pactor = 0;
    if (reference && reference->IsActor())
    {
        pactor = reinterpret_cast<Actor*>(reference);
    }

    if (pactor)
    {
        if (reinterpret_cast<Actor_Shell*>(pactor)->FUN_00437bd0())
        {
            result = 1.0;
        }

        if (g_bEchoConsole)
        {
            if (result != 0.0)
            {
                DebugLog("%s is unconscious", reinterpret_cast<MobileObject_Shell*>(pactor)->GetFullName());
            }
            else
            {
                DebugLog("%s is not unconscious", reinterpret_cast<MobileObject_Shell*>(pactor)->GetFullName());
            }
        }
    }

    return true;
}

unsigned int __cdecl FUN_005a00a0(unsigned int);
void __cdecl DebugLog(char const*, ...);
extern __declspec(thread) struct
{
    char pad[0x268];
    unsigned char dbg;
} tlsData;
// Stores a random percentage from FUN_005a00a0(100) into result, logs it when tlsData.dbg is set, and returns true.
// @fnv 0x005a0040
bool __cdecl FUN_005a0040(TESObjectREFR* ref, void* apUnused1, void* apUnused2, double& result)
{
    result = (double)FUN_005a00a0(100);
    if (tlsData.dbg)
        DebugLog("GetRandomPercent >> %0.2f", result);
    return true;
}

class MersenneTwister
{
  public:
    static MersenneTwister* __cdecl GetRandomGenerator(void);
    unsigned int GetRandomUInt(unsigned int);
};

// @fnv 0x005a00a0
unsigned int FUN_005a00a0(unsigned int aiMax)
{
    return MersenneTwister::GetRandomGenerator()->GetRandomUInt(aiMax);
}

void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern bool tls_conditionEcho;

struct ActorLevelHelper : Actor
{
    unsigned short GetLevel();
};

// Sets result to the reference's actor level (0 if not an actor) and logs it when tls_conditionEcho is set; returns true.
// @fnv 0x005a00c0
bool __cdecl FUN_005a00c0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    ActorLevelHelper* pactor = 0;
    if (reference && reference->IsActor())
    {
        pactor = (ActorLevelHelper*)reference;
    }
    if (pactor)
    {
        result = (double)pactor->GetLevel();
    }
    if (tls_conditionEcho)
    {
        DebugLog("GetLevel >> %0.2f", result);
    }
    return true;
}

struct TES;
extern TES* g_TES;
short __fastcall FindActorBaseValue(TES*, int, TESActorBase*);
void __cdecl DebugLog(char const*, ...);

struct TLSDataView
{
    char pad[0x268];
    bool bShowConditionTrace;
};
__declspec(thread) extern TLSDataView g_tlsView;

// Sets afReturnValue to 0, then if apParam1 is non-null stores the result of FindActorBaseValue on g_TES and logs it when condition tracing is on; returns true.
// @fnv 0x005a01f0
bool __cdecl FUN_005a01f0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESActorBase* ptarget = static_cast<TESActorBase*>(apParam1);
    if (ptarget)
    {
        afReturnValue = ((short(__thiscall*)(TES*, TESActorBase*))FindActorBaseValue)(g_TES, ptarget);
        if (g_tlsView.bShowConditionTrace)
        {
            DebugLog("Dead Count: %0.2f", afReturnValue);
        }
    }
    return true;
}

struct FUN_005a03f0_obj
{
    unsigned char pad[0x680];
    unsigned char f680;
    bool FUN_005a03f0(unsigned int mask);
};
// @fnv 0x005a03f0
bool FUN_005a03f0_obj::FUN_005a03f0(unsigned int mask)
{
    return f680 & mask;
}

void __cdecl DebugLog(char const*, ...);
bool __fastcall FUN_008a16d0(Actor*);
__declspec(thread) extern unsigned char g_bConditionTrace[0x269];

// Sets afReturnValue to 1.0 when apRefObject is an actor for which FUN_008a16d0 is true, otherwise 0.0, and logs the result when g_bConditionTrace[0x268] is set.
// @fnv 0x005a0550
bool __cdecl FUN_005a0550(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pactor = 0;
    if (apRefObject && apRefObject->IsActor())
        pactor = (Actor*)apRefObject;
    if (pactor && FUN_008a16d0(pactor))
        afReturnValue = 1.0;
    if (g_bConditionTrace[0x268])
        DebugLog("Is Weapon Out >> %0.2f", afReturnValue);
    return true;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct TESAnimGroup;
struct TESIdleForm;
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
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
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

void __cdecl DebugLog(char const*, ...);

struct TLSData_005a0f10
{
    unsigned char pad[0x268];
    bool bEcho;
};
__declspec(thread) TLSData_005a0f10 g_tlsData_005a0f10;

struct TESObjectREFR_View_005a0f10
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
    virtual Animation* GetAnimation();
};

// @fnv 0x005a0f10
bool __cdecl FUN_005a0f10(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (apRefObject)
    {
        Animation* panim = ((TESObjectREFR_View_005a0f10*)apRefObject)->GetAnimation();
        if (panim)
        {
            if (!panim->IsSequenceActive())
            {
                *afReturnValue = 1.0;
            }
        }
    }
    if (g_tlsData_005a0f10.bEcho)
    {
        DebugLog("Is Idle Playing >> %0.2f", *afReturnValue);
    }
    return true;
}

void __cdecl DebugLog(char const*, ...);
bool __fastcall FUN_008a67f0(Actor*);
MobileObject* __fastcall FUN_00578970(TESObjectREFR*);
bool __fastcall FUN_0092f160(MobileObject*);

struct TLSData_005a1150
{
    char pad[0x268];
    bool bConsoleEcho;
};
__declspec(thread) TLSData_005a1150 g_tls_005a1150;

// @fnv 0x005a1150
bool __cdecl GetTalkingValue(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pactor = 0;
    if (apRefObject && apRefObject->IsActor())
        pactor = (Actor*)apRefObject;
    if (pactor)
    {
        if (FUN_008a67f0(pactor))
            afReturnValue = 1.0;
    }
    else
    {
        MobileObject* pmob = FUN_00578970(apRefObject);
        if (pmob && FUN_0092f160(pmob))
            afReturnValue = 1.0;
    }
    if (g_tls_005a1150.bConsoleEcho)
        DebugLog("Talking >> %0.2f", afReturnValue);
    return true;
}

namespace fnv_005a1c90 {
int __fastcall _FNV_GetFormType(void* form);
void __cdecl DebugLog(const char*, ...);

struct TESPackage
{
    bool IsMustComplete();
};

namespace FNV_Helpers {
struct ExtraDataList
{
    TESPackage* GetPackageOverride();
};
struct Actor
{
    TESPackage* GetCurrentAIPackage();
};
}

__declspec(thread) extern char tls_pad[0x268];
__declspec(thread) extern bool tls_bEcho;

// Returns 1.0 in afReturnValue when the actor's current package matches the given package form, else 0.0; logs the result if tls_bEcho is set.
// @fnv 0x005a1c90
bool __cdecl FUN_005a1c90(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pactor = 0;
    if (apRefObject && apRefObject->IsActor())
    {
        pactor = reinterpret_cast<Actor*>(apRefObject);
    }

    TESPackage* ppackage = 0;
    if (apParam1 && _FNV_GetFormType(apParam1) == 0x49)
    {
        ppackage = reinterpret_cast<TESPackage*>(apParam1);
    }

    if (pactor && ppackage)
    {
        TESPackage* pActorPackage = reinterpret_cast<FNV_Helpers::Actor*>(pactor)->GetCurrentAIPackage();
        if (pActorPackage && pActorPackage->IsMustComplete() &&
            reinterpret_cast<FNV_Helpers::ExtraDataList*>(reinterpret_cast<TESObjectREFR*>(pactor)->GetExtraData())
                ->GetPackageOverride())
        {
            pActorPackage =
                reinterpret_cast<FNV_Helpers::ExtraDataList*>(reinterpret_cast<TESObjectREFR*>(pactor)->GetExtraData())
                    ->GetPackageOverride();
        }
        if (pActorPackage == ppackage)
        {
            afReturnValue = 1.0;
        }
    }

    if (tls_bEcho)
    {
        DebugLog("GetIsCurrentPackage >> %0.2f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_005a1c90

namespace fnv_005a1d80 {
class Calendar
{
  public:
    int GetGameDayOfWeek();
};
extern Calendar g_calendar;
void __cdecl DebugLog(const char*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
struct TLSData
{
    char pad[0x268];
    bool bEcho;
};
}
extern __declspec(thread) TLSData g_tlsData;

// Sets result to the calendar's day-of-week value, logs it when TLS echo is enabled, and returns true.
// @fnv 0x005a1d80
bool __cdecl FUN_005a1d80(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    result = g_calendar.GetGameDayOfWeek();
    if (g_tlsData.bEcho)
    {
        DebugLog("GetDayOfWeek >> %0.2f", result);
    }
    return true;
}
}  // namespace fnv_005a1d80

namespace fnv_005a1de0 {
struct FUN_005a1de0_player
{
    bool FUN_005a1e50();
};
struct FUN_005a1de0_tls
{
    char pad[0x268];
    unsigned char dbg;
};
extern FUN_005a1de0_player* pPlayer;
extern __declspec(thread) FUN_005a1de0_tls tlsData;
void __cdecl DebugLog(char const*, ...);
// Sets result to 1.0 if the player is sleeping, otherwise 0.0, logs it when tlsData.dbg is set, and returns true.
// @fnv 0x005a1de0
bool __cdecl FUN_005a1de0(TESObjectREFR* ref, void* a1, void* a2, double& result)
{
    result = 0.0;
    float fValue;
    if (pPlayer->FUN_005a1e50())
        fValue = 1.0f;
    else
        fValue = 0.0f;
    result = fValue;
    if (tlsData.dbg)
        DebugLog("IsPlayerSleeping >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a1de0

// @fnv 0x005a1e50
bool __fastcall FUN_005a1e50(const bool* self)
{
    return self[0x658];
}

struct FUN_005a2030_shell : public Actor
{
    bool FUN_005a2030();
};

// @fnv 0x005a2030
bool FUN_005a2030_shell::FUN_005a2030()
{
    return *((bool*)this + 0x14d);
}

void __cdecl DebugLog(char const*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
struct ConditionPacketTlsLayout
{
    unsigned char padding[0x268];
    bool verbose;
};

__declspec(thread) ConditionPacketTlsLayout g_conditionPacketTls;
}

// Sets afReturnValue to 1.0 if the given faction considers the player an enemy, otherwise 0.0, and logs the result when verbose.
// @fnv 0x005a21f0
bool __cdecl GetPCIsEnemyOfFaction(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESFaction* pFaction = static_cast<TESFaction*>(apParam1);
    if (pFaction && pFaction->GetPCAnEnemy())
        afReturnValue = 1.0;

    if (g_conditionPacketTls.verbose)
    {
        if (afReturnValue != 0.0)
            DebugLog("PC Is an Enemy of the faction.");
        else
            DebugLog("PC is not an enemy of this faction.");
    }
    return true;
}

namespace fnv_005a2330 {
struct TESObjectREFR_standin
{
    bool FUN_00477ba0();
};
void __cdecl DebugLog(char const*, ...);
extern __declspec(thread) struct
{
    char pad[0x268];
    unsigned char dbg;
} tlsData;
// Sets result to 1.0 if ref is valid and FUN_00477ba0 returns true, otherwise 0.0, logs it when tlsData.dbg is set, and returns true.
// @fnv 0x005a2330
bool __cdecl FUN_005a2330(TESObjectREFR_standin* ref, void* a1, void* a2, double& result)
{
    result = 0.0;
    if (ref && ref->FUN_00477ba0())
        result = 1.0;
    if (tlsData.dbg)
        DebugLog("GetDestroyed >> %.0f", result);
    return true;
}
}  // namespace fnv_005a2330

void __cdecl DebugLog(char const*, ...);

class MagicTarget
{
  public:
    bool HasEffect(EffectSetting const*);
};

struct TLSData_005a2390
{
    char pad[0x268];
    bool conditionTrace;
};

__declspec(thread) TLSData_005a2390 g_tls_005a2390;

struct VTableStub_005a2390
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
    virtual bool IsActor();  // 0x100
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
    virtual MagicTarget* GetMagicTarget();  // 0x19c
};

// @fnv 0x005a2390
bool __cdecl HasMagicEffect(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    VTableStub_005a2390* pactor = 0;
    if (apRefObject && ((VTableStub_005a2390*)apRefObject)->IsActor())
    {
        pactor = (VTableStub_005a2390*)apRefObject;
    }
    EffectSetting* peffectSetting = (EffectSetting*)apParam1;
    if (pactor && peffectSetting)
    {
        if (pactor->GetMagicTarget()->HasEffect(peffectSetting))
        {
            afReturnValue = 1.0;
        }
    }
    if (g_tls_005a2390.conditionTrace)
    {
        DebugLog("Has Magic Effect >> %0.2f", afReturnValue);
    }
    return true;
}

extern PlayerCharacter* pPlayer;
void __cdecl DebugLog(const char*, ...);

struct TlsBlock_005a2890
{
    char pad[0x268];
    bool bConsoleEcho;
};

__declspec(thread) TlsBlock_005a2890 tls_005a2890;

// Zeroes afReturnValue, sets it from a PlayerCharacter virtual call when apRefObject is the player, logs it if console echo is on, and returns true.
// @fnv 0x005a2890
bool __cdecl FUN_005a2890(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject == reinterpret_cast<TESObjectREFR*>(pPlayer))
    {
        afReturnValue = (*reinterpret_cast<bool(__thiscall***)(PlayerCharacter*)>(pPlayer))[0x364 / 4](pPlayer);
    }
    if (tls_005a2890.bConsoleEcho)
    {
        DebugLog("Player is in Cannibal action >> %0.2f", afReturnValue);
    }
    return true;
}

void __cdecl DebugLog(char const*, ...);
bool __fastcall GetExtraDataVersion(Actor*);
__declspec(thread) bool bConsoleEcho_tls_dummy[0x269];

// Sets afReturnValue to 1.0 if apRefObject is an Actor for which GetExtraDataVersion returns true, otherwise 0.0, and logs the result when console echo is enabled.
// @fnv 0x005a29d0
bool __cdecl CheckActorEaten(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject->IsActor())
    {
        Actor* pact = (Actor*)apRefObject;
        if (GetExtraDataVersion(pact))
        {
            afReturnValue = 1.0;
        }
    }
    if (bConsoleEcho_tls_dummy[0x268])
    {
        DebugLog("Actor has been eaten >> %0.2f", afReturnValue);
    }
    return true;
}

namespace fnv_005a2e20 {
class TESObject : public TESForm
{
  public:
    TESObject* GetNext();
};

extern PlayerCharacter* pPlayer;
void __cdecl DebugLog(char const*, ...);
extern __declspec(thread) bool bConditionPrint;

struct ExtraDataListOwnerView : public ExtraDataList
{
    TESForm* GetOwner();
};

struct TESFullNameHelper : public TESFullName
{
    static char const* __cdecl GetFullName(TESForm*);
};

// @fnv 0x005a2e20
bool __cdecl FUN_005a2e20(TESObjectREFR* reference, void* pOwner, void* pUnused, double& result)
{
    TESForm* owner = static_cast<TESForm*>(pOwner);
    if (!owner)
    {
        owner = reinterpret_cast<TESObject*>(pPlayer)->GetNext();
    }
    if (reference && owner && static_cast<ExtraDataListOwnerView*>(reference->GetExtraData())->GetOwner() == owner)
    {
        result = 1.0;
    }
    if (bConditionPrint)
    {
        if (result != 0.0)
        {
            DebugLog("%s is the owner", TESFullNameHelper::GetFullName(owner));
        }
        else
        {
            DebugLog("%s is not the owner", TESFullNameHelper::GetFullName(owner));
        }
    }
    return true;
}
}  // namespace fnv_005a2e20

void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern unsigned char g_bConsoleEcho_0268[0x269];

extern bool (__thiscall Actor::*volatile pfn_Actor_IsSneaking)();
extern char const*(__cdecl* volatile pfn_TESFullName_GetFullName)(TESForm*);

struct Actor_IsSneaking_Helper : public Actor
{
    bool IsSneaking();
};

struct TESFullName_Helper : public TESFullName
{
    static char const* __cdecl GetFullName(TESForm*);
};

// @fnv 0x005a2f60
bool __cdecl FUN_005a2f60(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pact = 0;
    if (apRefObject != 0)
    {
        if (apRefObject->IsActor())
        {
            pact = reinterpret_cast<Actor*>(apRefObject);
        }
    }
    if (reinterpret_cast<Actor_IsSneaking_Helper*>(pact)->IsSneaking())
    {
        afReturnValue = 1.0;
    }
    if (g_bConsoleEcho_0268[0x268])
    {
        if (afReturnValue != 0.0)
        {
            DebugLog("%s is sneaking", TESFullName_Helper::GetFullName(reinterpret_cast<TESForm*>(pact)));
        }
        else
        {
            DebugLog("%s is not sneaking", TESFullName_Helper::GetFullName(reinterpret_cast<TESForm*>(pact)));
        }
    }
    return true;
}

bool __fastcall FUN_00884730(Actor* actor);
void __cdecl DebugLog(const char*, ...);

namespace TESFullName_ns {
class TESFullName
{
  public:
    static const char* __cdecl GetFullName(TESForm*);
};
}

__declspec(thread) extern bool bConsoleOutput;

// Sets afReturnValue to 1.0 if the reference is an actor that is running, logs the result when console output is enabled, and returns true.
// @fnv 0x005a3010
bool __cdecl FUN_005a3010(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pact = 0;
    if (apRefObject != 0 && apRefObject->IsActor())
    {
        pact = reinterpret_cast<Actor*>(apRefObject);
    }
    if (FUN_00884730(pact))
    {
        afReturnValue = 1.0;
    }
    if ((&bConsoleOutput)[0x268])
    {
        if (afReturnValue != 0.0)
        {
            DebugLog("%s is running", TESFullName_ns::TESFullName::GetFullName(reinterpret_cast<TESForm*>(pact)));
        }
        else
        {
            DebugLog("%s is not running", TESFullName_ns::TESFullName::GetFullName(reinterpret_cast<TESForm*>(pact)));
        }
    }
    return true;
}

namespace fnv_005a3270 {
void __cdecl DebugLog(char const*, ...);
bool __fastcall FUN_00425fd0(TESObjectCELL* apCell);
char const* __cdecl FUN_00482720(TESForm* apForm);

struct TLSData
{
    char pad[0x268];
    bool verbose;
};
static __declspec(thread) TLSData s_tlsData;

// Sets afReturnValue to 1.0 if apRefObject's parent cell passes FUN_00425fd0, else 0.0, logs the result when verbose, and returns true.
// @fnv 0x005a3270
bool __cdecl IsInInterior(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject && apRefObject->GetParentCell() && FUN_00425fd0(apRefObject->GetParentCell()))
    {
        afReturnValue = 1.0;
    }
    if (s_tlsData.verbose)
    {
        if (afReturnValue != 0.0)
        {
            DebugLog("%s is in an Interior", FUN_00482720(apRefObject));
        }
        else
        {
            DebugLog("%s is not an Interior", FUN_00482720(apRefObject));
        }
    }
    return true;
}
}  // namespace fnv_005a3270

namespace fnv_005a3310 {
struct TLSData
{
    unsigned char padding[0x268];
    bool consoleOutput;
};

extern __declspec(thread) TLSData g_tlsData;

int __cdecl FUN_005a3370(int);
void __cdecl DebugLog(const char*, ...);

// Computes a player misc stat value from arg1 into result, logs it when console output is enabled, and returns true.
// @fnv 0x005a3310
bool __cdecl GetPlayerMiscStatValue(TESObjectREFR* reference, void* aiStat, void* apUnused, double& result)
{
    int stat = (int)aiStat;
    result = FUN_005a3370(stat);
    if (g_tlsData.consoleOutput)
    {
        DebugLog("Player misc stat value %.02f", result);
    }
    return true;
}
}  // namespace fnv_005a3310

extern int* DAT_011c6d50[];

// @fnv 0x005a3370
int __cdecl FUN_005a3370(int aeID)
{
    return DAT_011c6d50[aeID][1];
}

namespace fnv_005a38e0 {
extern int DAT_011caae8;
extern int DAT_011caaec;
extern float DAT_011caaf0;
extern int DAT_011caaf4;
extern int DAT_011caaf8;
extern float DAT_011caafc;
extern int DAT_011cab00;
extern int DAT_011cab04;
extern float DAT_011cab08;
extern int DAT_011cab0c;
extern int DAT_011cab10;
extern int DAT_011cab14;
extern int DAT_011cab18;
extern int DAT_011cab1c;
extern float DAT_011cab20;

// Sets a block of global ints and floats to zero.
// @fnv 0x005a38e0
void __cdecl FUN_005a38e0()
{
    DAT_011caae8 = 0;
    DAT_011caaec = 0;
    DAT_011caaf0 = 0.0f;
    DAT_011caaf4 = 0;
    DAT_011caaf8 = 0;
    DAT_011caafc = 0.0f;
    DAT_011cab00 = 0;
    DAT_011cab04 = 0;
    DAT_011cab08 = 0.0f;
    DAT_011cab0c = 0;
    DAT_011cab10 = 0;
    DAT_011cab14 = 0;
    DAT_011cab18 = 0;
    DAT_011cab1c = 0;
    DAT_011cab20 = 0.0f;
}
}  // namespace fnv_005a38e0

class BGSNote;
class PlayerCharacter
{
  public:
    bool HasNote(BGSNote*);
};
extern PlayerCharacter* pPlayer;

// Sets result to 1.0 if pPlayer has the BGSNote passed in arg1, otherwise leaves it at 0.0, and returns true.
// @fnv 0x005a3bf0
bool __cdecl FUN_005a3bf0(TESObjectREFR* reference, void* pNote, void* pUnused, double& result)
{
    result = 0.0;
    BGSNote* note = (BGSNote*)pNote;
    if (pPlayer->HasNote(note))
        result = 1.0;
    return true;
}

int __fastcall FUN_005730d0(Actor* actor);
void __cdecl DebugLog(char const*, ...);
extern __declspec(thread) bool bEchoConsole;

// Sets result to -1.0, or to FUN_005730d0 of the reference when it is an Actor, logs it if bEchoConsole, and returns true.
// @fnv 0x005a3d30
bool __cdecl FUN_005a3d30(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = -1.0;
    if (reference->IsActor())
    {
        Actor* pactor = reinterpret_cast<Actor*>(reference);
        result = static_cast<double>(FUN_005730d0(pactor));
    }
    if (bEchoConsole)
    {
        DebugLog("Cause of death is >> %0.2f", result);
    }
    return true;
}

struct TESObjectREFR_GetFlags_Helper : public TESObjectREFR
{
    unsigned int GetFlags()
    {
        return 0;
    }
};
// @fnv 0x005a4320
unsigned int __fastcall FUN_005a4320(char* this_ptr)
{
    return ((TESObjectREFR_GetFlags_Helper*)(this_ptr + 8))->GetFlags();
}

namespace fnv_005a4340 {
class Sky;
class TES
{
  public:
    Sky* GetLogDate();
};

struct Vtable388
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
    virtual bool v226();
};

// Sets result to 0.0, then if reference is an actor with a non-null GetLogDate, stores the result of v226() from that object; always returns true.
// @fnv 0x005a4340
bool __cdecl FUN_005a4340(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference != 0 && reference->IsActor())
    {
        TES* actor = reinterpret_cast<TES*>(reference);
        if (actor->GetLogDate() != 0)
        {
            result = reinterpret_cast<Vtable388*>(actor->GetLogDate())->v226();
        }
    }
    return true;
}
}  // namespace fnv_005a4340

class ProcessLists
{
  public:
    bool IsActorTalkingThroughActivator(Actor*);
};

extern ProcessLists DAT_011e0e80;

// Sets result to 0.0, then if reference is an actor stores whether it is talking through an activator; always returns true.
// @fnv 0x005a43b0
bool __cdecl FUN_005a43b0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        Actor* actor = (Actor*)reference;
        result = DAT_011e0e80.IsActorTalkingThroughActivator(actor);
    }
    return true;
}

namespace fnv_005a4480 {
void __cdecl DebugLog(char const*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
__declspec(thread) char tls_pad[0x268];
__declspec(thread) bool tls_showDebug;
}

struct MobileObjectEmotionView
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
    virtual int GetDialogueEmotion();
};

// Writes the reference's dialogue emotion into afReturnValue (or -1.0 if emotion animation is disabled) and logs it when debug is enabled; always returns true.
// @fnv 0x005a4480
bool __cdecl FUN_005a4480(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (apRefObject->IsMobileObject())
    {
        MobileObject* pmob = static_cast<MobileObject*>(apRefObject);
        *afReturnValue = reinterpret_cast<MobileObjectEmotionView*>(pmob)->GetDialogueEmotion();
        if (!pmob->GetShouldUseEmotionAnimation())
        {
            *afReturnValue = -1.0;
        }
    }
    if (tls_showDebug)
    {
        DebugLog("GetEmotion >> %0.2f", *afReturnValue);
    }
    return true;
}
}  // namespace fnv_005a4480

namespace fnv_005a4780 {
void __cdecl DebugLog(char const*, ...);

class Sky;
class TES
{
  public:
    Sky* GetLogDate(void);
};

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
struct VTableCall_38c
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
    virtual TESIdleForm* GetLastPlayedIdle();
};
}

__declspec(thread) extern unsigned char tls_pad_268[0x269];

// @fnv 0x005a4780
bool __cdecl CheckLastPlayedIdle(TESObjectREFR* reference, void* arg1, void* pUnused, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        Actor* pactor = (Actor*)reference;
        TESIdleForm* pidle = (TESIdleForm*)arg1;
        if (((VTableCall_38c*)((TES*)pactor)->GetLogDate())->GetLastPlayedIdle() == pidle)
        {
            result = 1.0;
        }
        if (tls_pad_268[0x268])
        {
            DebugLog("The last idle played was  >> %d", result);
        }
    }
    return true;
}
}  // namespace fnv_005a4780

void __cdecl DebugLog(char const*, ...);
extern PlayerCharacter* pPlayer;

struct Actor_005a49f0
{
    int GetReactionToActor(Actor*, bool*);
};

struct TLSData_005a49f0
{
    unsigned char pad[0x268];
    bool bConsoleEcho;
};

__declspec(thread) TLSData_005a49f0 tls_005a49f0;

// Sets afReturnValue to 1.0 if the actor's faction is hostile to the player due to crime, and logs the result when console echo is enabled.
// @fnv 0x005a49f0
bool __cdecl FUN_005a49f0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject && apRefObject->IsActor())
    {
        Actor_005a49f0* pactor = reinterpret_cast<Actor_005a49f0*>(apRefObject);
        Actor* ptarg = reinterpret_cast<Actor*>(apParam1);
        bool bcrime = false;
        pactor->GetReactionToActor(reinterpret_cast<Actor*>(pPlayer), &bcrime);
        if (bcrime)
            afReturnValue = 1.0;
        if (tls_005a49f0.bConsoleEcho)
        {
            if (afReturnValue != 0.0)
                DebugLog("This actor's faction is an enemy of player because of crime");
            else
                DebugLog("This actor is not an enemy of player because of  a faction crime");
        }
    }
    return true;
}

namespace fnv_005a51e0 {
struct MapMarkerData
{
    bool GetVisible();
    bool IsTravelLocation();
};

MapMarkerData* __fastcall FUN_00569060(TESObjectREFR* ref);
void __cdecl DebugLog(char const*, ...);

namespace fnv_anon_tesconditionfunctions {}
using namespace fnv_anon_tesconditionfunctions;
namespace fnv_anon_tesconditionfunctions {
__declspec(thread) unsigned char tls_padding[0x268];
__declspec(thread) bool bVerboseMode;
}

// @fnv 0x005a51e0
bool __cdecl FUN_005a51e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject)
    {
        MapMarkerData* pmarkerdata = FUN_00569060(apRefObject);
        if (pmarkerdata && pmarkerdata->GetVisible())
        {
            afReturnValue = 1.0;
            if (pmarkerdata->IsTravelLocation())
            {
                afReturnValue = 2.0;
            }
        }
    }
    if (bVerboseMode)
    {
        DebugLog("marker state = %.0f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_005a51e0

namespace fnv_005a5330 {
void __cdecl DebugLog(char const*, ...);
extern PlayerCharacter* pPlayer;
__declspec(thread) extern bool tls_0268;

class Sky;
class TES
{
  public:
    Sky* GetLogDate();
};

class TESObjectLIGH;
class EffectSetting
{
  public:
    TESObjectLIGH* GetLight();
};

struct Process005a5330
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
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
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual bool vfn_30c();
};

// Sets afReturnValue to 1.0 if apRefObject is an actor whose GetLogDate() passes vfn_30c() and whose GetLight() equals pPlayer, then logs the result.
// @fnv 0x005a5330
bool __cdecl FUN_005a5330(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject && apRefObject->IsActor())
    {
        Actor* pact = (Actor*)apRefObject;
        if (((TES*)pact)->GetLogDate() && ((Process005a5330*)((TES*)pact)->GetLogDate())->vfn_30c() &&
            (PlayerCharacter*)((EffectSetting*)pact)->GetLight() == pPlayer)
        {
            afReturnValue = 1.0;
        }
    }
    if (tls_0268)
    {
        DebugLog("IsGreeting the player >> %.2f", afReturnValue);
    }
    return true;
}
}  // namespace fnv_005a5330

void __cdecl DebugLog(const char*, ...);
__declspec(thread) extern bool bEchoConsole;

struct TESQuest_GetObjective_View : public TESQuest
{
    BGSQuestObjective* GetObjective(unsigned int index);
};

// @fnv 0x005a5d30
bool __cdecl FUN_005a5d30(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    TESQuest_GetObjective_View* pquest = (TESQuest_GetObjective_View*)apParam1;
    int iElementIndex = (int)apParam2;

    if (pquest)
    {
        BGSQuestObjective* pobjective = pquest->GetObjective(iElementIndex);
        if (pobjective)
        {
            afReturnValue = pobjective->GetCompleted() ? 1.0 : 0.0;
            if (bEchoConsole)
            {
                DebugLog("GetObjectiveCompleted >> %0.2f", afReturnValue);
            }
        }
    }
    return true;
}

void __cdecl DebugLog(const char*, ...);

struct TESQuest_GetObjective : public TESQuest
{
    BGSQuestObjective* GetObjective(unsigned int);
};

__declspec(thread) extern unsigned char tls_padding_005a5de0[0x269];

// Looks up the quest objective by index and writes 1.0 or 0.0 to afReturnValue depending on whether it is displayed, logging the result when enabled.
// @fnv 0x005a5de0
bool __cdecl GetQuestObjectiveDisplayed(TESObjectREFR* apRefObject, void* apParam1, void* apParam2,
                                        double& afReturnValue)
{
    TESQuest* pquest = (TESQuest*)apParam1;
    int iElementIndex = (int)apParam2;
    if (pquest)
    {
        BGSQuestObjective* pobjective = ((TESQuest_GetObjective*)pquest)->GetObjective(iElementIndex);
        if (pobjective)
        {
            afReturnValue = pobjective->GetDisplayed() ? 1.0 : 0.0;
            if (tls_padding_005a5de0[0x268])
            {
                DebugLog("GetObjectiveDisplayed >> %0.2f", afReturnValue);
            }
        }
    }
    return true;
}

extern PlayerCharacter* pPlayer;
void __cdecl DebugLog(char const*, ...);
bool __fastcall FUN_004d1360(PlayerCharacter* pThis);
__declspec(thread) extern bool g_bShowConsoleOutput;

struct TLSDataPad
{
    unsigned char pad[0x267];
    bool bShowConsoleOutput;
};

// Stores whether the player is in hardcore mode into afReturnValue and logs it when console output is enabled; always returns true.
// @fnv 0x005a5f90
bool __cdecl FUN_005a5f90(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    if (pPlayer != 0)
    {
        afReturnValue = FUN_004d1360(pPlayer);
    }
    if ((&g_bShowConsoleOutput)[0x268])
    {
        DebugLog("IsHardcore? >> %f", afReturnValue);
    }
    return true;
}

// @fnv 0x005a60d0
unsigned int __fastcall FUN_005a60d0(const char* pThis)
{
    return *(const unsigned int*)(pThis + 0x70) & 1;
}

// @fnv 0x005a6150
unsigned int __fastcall FUN_005a6150(const unsigned char* self)
{
    return *(const unsigned int*)(self + 0x70) & 2;
}

// @fnv 0x005a6260
unsigned int __fastcall FUN_005a6260(char* thisPtr)
{
    return *reinterpret_cast<unsigned int*>(thisPtr + 0x610);
}

struct TESObjectCELL;
class TESObjectREFR;
int __fastcall _FNV_GetFormType(void*);
void DebugLog(const char*, ...);
extern __declspec(thread) unsigned char g_tlsFlag;
// Sets afReturnValue to 1.0 if apRefObject and apParam1 (when a reference form) share the same parent cell, otherwise 0.0, and returns true.
// @fnv 0x0059ee80
bool FUN_0059ee80(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    TESObjectREFR* ptestref = 0;
    TESObjectCELL* prefcell;
    TESObjectCELL* ptestcell;
    if (apParam1)
    {
        switch (_FNV_GetFormType(apParam1))
        {
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x69:
            ptestref = (TESObjectREFR*)apParam1;
            break;
        }
    }
    prefcell = apRefObject ? apRefObject->GetParentCell() : 0;
    ptestcell = ptestref ? ptestref->GetParentCell() : 0;
    if (prefcell && ptestcell && prefcell == ptestcell)
        *afReturnValue = 1.0;
    if (g_tlsFlag)
        DebugLog("GetInSameCell >> %0.2f", *afReturnValue);
    return true;
}

struct TESObjectREFR;
struct TESFaction;
struct XActor
{
    void* GetActorBase();
};
struct FUN_008b8290_shell
{
    int FUN_008b8290(TESFaction*, bool);
};
int __fastcall _FNV_GetFormType(void*);
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
void DebugLog(const char*, ...);
extern __declspec(thread) unsigned char g_tlsFlag;
// @fnv 0x0059fc50
bool FUN_0059fc50(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = -1.0;
    TESObjectREFR* pact = 0;
    if (apRefObject && ((unsigned char(__thiscall*)(void*))(*(void***)apRefObject)[0x40])(apRefObject))
        pact = apRefObject;
    if (!pact)
        return true;
    void* pactorbase = ((XActor*)pact)->GetActorBase();
    TESFaction* pfac = 0;
    if (apParam1 && _FNV_GetFormType(apParam1) == 8)
        pfac = (TESFaction*)apParam1;
    if (pact && pfac)
        *afReturnValue = (double)((FUN_008b8290_shell*)pact)->FUN_008b8290(pfac, (void*)pact == (void*)g_thePlayer);
    if (g_tlsFlag)
        DebugLog("GetFactionRank >> %0.2f", *afReturnValue);
    return true;
}

struct TESObjectREFR;
void DebugLog(const char*, ...);
extern __declspec(thread) unsigned char g_tlsFlag;
// Sets the return value to 0, then if the reference is valid and passes a check, queries its perk rank and sets the return value to 1 when the rank is nonzero.
// @fnv 0x005a4630
bool FUN_005a4630(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (apRefObject && ((unsigned char(__thiscall*)(void*))(*(void***)apRefObject)[0x40])(apRefObject))
    {
        int irank;
        void* pactor = apRefObject;
        bool bAlt = (apParam2 != 0) ? true : false;
        irank = ((unsigned char(__thiscall*)(void*, void*, bool))(*(void***)pactor)[0x128])(pactor, apParam1, bAlt);
        if (g_tlsFlag)
            DebugLog("Perk Rank >> %d", irank);
        if (irank)
            *afReturnValue = 1.0;
    }
    return true;
}

struct TESObjectREFR;
struct ActorH
{
    int GetReactionToActor(void*, bool*);
};
void DebugLog(const char*, ...);
extern __declspec(thread) unsigned char g_tlsFlag;
// @fnv 0x005a46d0
bool GetFactionRelation(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (apRefObject && ((unsigned char(__thiscall*)(void*))(*(void***)apRefObject)[0x40])(apRefObject))
    {
        void* ptarg;
        bool bcrime;
        ActorH* pactor;
        pactor = (ActorH*)apRefObject;
        ptarg = apParam1;
        bcrime = false;
        *afReturnValue = (double)pactor->GetReactionToActor(ptarg, &bcrime);
        if (g_tlsFlag)
            DebugLog("Faction Relation  >> %d", (unsigned int)*afReturnValue);
    }
    return true;
}

struct TESObjectREFR;
struct TESH
{
    void* GetLogDate();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct IC
{
    float GetConditionPercent(bool);
};
extern unsigned int DAT_011ca278;
extern double g_d100;
void DebugLog(const char*, ...);
extern __declspec(thread) unsigned char g_tlsFlag;
// @fnv 0x005a5270
bool FUN_005a5270(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    if (apRefObject && ((unsigned char(__thiscall*)(void*))(*(void***)apRefObject)[0x40])(apRefObject))
    {
        TESObjectREFR* pactor = apRefObject;
        IC* pweapon;
        if (((TESH*)pactor)->GetLogDate())
        {
            void* pprocess = ((TESH*)pactor)->GetLogDate();
            pweapon = ((IC * (__thiscall*)(void*))(*(void***)pprocess)[0x52])(pprocess);
            if (pweapon && ((ArrSI*)pweapon)->GetFlags() != DAT_011ca278)
                *afReturnValue = pweapon->GetConditionPercent(true);
            else
                *afReturnValue = g_d100;
        }
    }
    if (g_tlsFlag)
        DebugLog("GetWeaponHealthPerc >> %0.2f", *afReturnValue);
    return true;
}

namespace fnv_0059cf50 {
struct FormFlagRecord;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ScriptDefinition;
struct ScriptLocals
{
    void ClearActionFlags();
    bool GetLocalData(TESForm*, unsigned int);
    void ClearActionFlagsForForm(TESForm*);
    bool CheckActionFlag(TESForm*, unsigned int);
    FormFlagRecord* GetActionEntry(TESForm*, bool);
    void Save(ScriptHeaderData*);
    void ClearActionList();
    void InitializeActionList();
    void CopyActionListFrom(ScriptLocals*);
    void* GetActionList();
    void ResetFormData(Script*);
    void SetVariable(unsigned int, double);
    double GetVariable(unsigned int, Script*);
    void* GetLocalList();
    bool IsReferenceVariable(unsigned int);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void Revert(BGSLoadFormBuffer*);
    void Revert();
    static void ProcessPendingTasks();
    void* __vecDelDtor(unsigned int);
    Script* m_pOwnerScript;
    char m_cActionFlags;
    char _pad_5[3];
    void* m_pLocalVariableList;
    void* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;
};
typedef char _sizecheck_ScriptLocals[sizeof(ScriptLocals) == 20 ? 1 : -1];

void __cdecl DebugLog(char const*, ...);
struct RefH
{
    bool GetDisabled();
};
struct fnv_005aa630
{
    static bool __cdecl FUN_005aa630(Actor*);
};
bool __cdecl FUN_005aa680(int);

extern __declspec(thread) bool DAT_01272268;

// @fnv 0x0059cf50
bool __cdecl FUN_0059cf50(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    ScriptLocals* m_pScriptLocals = (ScriptLocals*)apParam1;
    if (apRefObject)
    {
        *afReturnValue = 0.0;
        if ((((RefH*)apRefObject)->GetDisabled() && !FUN_005aa680((int)apRefObject)) ||
            fnv_005aa630::FUN_005aa630((Actor*)apRefObject))
            *afReturnValue = 1.0;
    }
    else if (m_pScriptLocals)
    {
        *afReturnValue = (m_pScriptLocals->m_cActionFlags & 1) ? true : false;
    }
    if (DAT_01272268)
        DebugLog("GetDisabled >> %0.f", *afReturnValue);
    return true;
}
}  // namespace fnv_0059cf50

struct BGSDebris;
struct BGSExplosion;
struct BGSTextureSet;
struct BipedAnim;
struct CollisionComponent;
struct DestructionStageData;
struct IDebugText;
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct TESBoundObject;
struct TESFile;
struct TESKey;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct LockExtraData
{
    int GetLockLevel(TESObjectREFR*);
    void SetLockLevel(int);
    int GetLevel(TESObjectREFR*);
    bool IsLocked();
    void SetLocked(bool);
    bool MeetsMinimumLockLevel();
    static int ConvertLockLevel(int);
    static int EnumToNumericValue(int);
    void Endian();
    unsigned char m_uiLockState;
    char _pad_1[3];
    TESKey* pKey;
    char cFlags;
    char _pad_9[3];
    unsigned int m_uiLockDifficulty;
    unsigned int m_uiLockValue;
};
typedef char _sizecheck_REFR_LOCK[sizeof(LockExtraData) == 20 ? 1 : -1];
struct TESMagicTargetForm
{
    static bool CanBeMagicTarget(TESForm*);
    char _pad_0[1];
};
typedef char _sizecheck_TESMagicTargetForm[sizeof(TESMagicTargetForm) == 1 ? 1 : -1];
struct BGSDestructibleObjectForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    CollisionComponent* GetData();
    DestructionStageData* GetStage(unsigned int);
    unsigned char GetStageCount();
    DestructionStageData** AllocateStageArray(unsigned char);
    void SortStages();
    void SetDestructibleData(DestructionStageData*);
    void ClearStageData(unsigned int);
    static bool HasDestructibleData(TESForm*);
    static unsigned int GetDestructionStageCount(TESForm*);
    static BGSDestructibleObjectForm* GetDestructibleObjectForm(TESForm*);
    static int GetModelSwapIndex(TESForm*, TESModel*);
    static TESModel* GetModelSwap(TESForm*, int);
    bool HasValidStages();
    bool GetTargetableInVATS();
    void SetTargetableInVATS(bool);
    unsigned int GetMaxHealth(TESObjectREFR*);
    void DamageObject(TESObjectREFR*, float, bool);
    unsigned int SpawnExplosionsAtBlastNodes(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*);
    void SpawnExplosionAtBlastNode(NiAVObject*, unsigned int, void*);
    unsigned int SpawnDebrisAtDebrisNodes(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int);
    void FindDebrisNodes(NiAVObject*, unsigned int, void*);
    static void UpdateDamageStageNodes(NiAVObject*, unsigned int);
    void FindDamageStageNodes(NiAVObject*, unsigned int, void*);
    bool UpdateCurrentDamageStage(TESObjectREFR*, bool);
    void ApplyTerminalDamage(TESObjectREFR*);
    void FindModelSwapNodes(NiAVObject*, void*);
    static void UpdateDestructionMap();
    static void UpdateTargetHealthBar(TESObjectREFR*);
    static int GetDestructionStageIndex(TESObjectREFR*);
    static bool IsDestructionStageNode(NiAVObject*);
    void QueueResourceLoad(TESBoundObject*, int, QueuedFile*);
    void PreloadReplacementModels(TESBoundObject*);
    void UnloadReplacementModels();
    static bool IsDangerousObject(TESForm*);
    float CalculateDangerousExplosionHealth(unsigned char, float, float, BGSExplosion**);
    static float CalculateDangerousExplosionHealth(TESObjectREFR*, float, float, BGSExplosion**);
    float CalculateDangerousExplosionTerminalTime(unsigned char, float, float, BGSExplosion**);
    void DrawDebugText(IDebugText*, TESObjectREFR*);
    void DisplayNodeDebugText(IDebugText*, TESObjectREFR*);
    static unsigned int GetSelfDamage(TESObjectREFR*, float);
    static void SetDestructionStage(TESObjectREFR*, unsigned int);
    static void ClearDestruction(TESObjectREFR*);
    static void* GetDestructibleObjectMap();
    static float GetLastUpdateTime();
    static void SetLastUpdateTime(float);
    void ClearStages();
    void CreateData();
    void RemoveData();
    void* __vecDelDtor(unsigned int);
    CollisionComponent* pData;
};
typedef char _sizecheck_BGSDestructibleObjectForm[sizeof(BGSDestructibleObjectForm) == 8 ? 1 : -1];
struct BGSOpenCloseForm
{
    virtual void HandleOpenAnimationFinish(TESObjectREFR*, TESObjectREFR*);
    virtual void HandleCloseFinish(TESObjectREFR*, TESObjectREFR*);
    virtual bool GetBlockActivatesWhileOpening();
    static BGSOpenCloseForm* GetOpenCloseComponent(TESForm*);
    static bool HasOpenCloseComponent(TESForm*);
    static bool HasOpenCloseAnims(NiNode*);
    static void HandleOpenCloseActivation(TESObjectREFR*, TESObjectREFR*, BGSOpenCloseForm*);
    static void HandleAnimStartHavok(TESObjectREFR*, NiControllerSequence*);
    static bool HandleAnimEndHavok(TESObjectREFR*, NiControllerSequence*);
    static bool SetOpenState(TESObjectREFR*, bool, bool);
    static int GetOpenState(TESObjectREFR*);
    static void SnapHavokTo3D(TESObjectREFR*);
};
typedef char _sizecheck_BGSOpenCloseForm[sizeof(BGSOpenCloseForm) == 4 ? 1 : -1];

void __cdecl DebugLog(char const*, ...);
int __fastcall _FNV_GetFormType(TESForm*);
extern __declspec(thread) bool bPrintConditionDebug;
struct P01RefA
{
    LockExtraData* GetLock();
};
struct P01ObjA
{
    TESForm* GetNext();
};
struct P01PlayerA
{
    int GetTerminalAccessResult(TESObjectREFR*);
};
struct P01TermA
{
    bool FUN_00501ae0(TESObjectREFR*);
};
// @fnv 0x0059d010
bool FUN_0059d010(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (apRefObject)
    {
        LockExtraData* pLock = ((P01RefA*)apRefObject)->GetLock();
        if (pLock)
        {
            if (pLock->MeetsMinimumLockLevel())
                *afReturnValue = 2.0;
            else if (pLock->IsLocked())
                *afReturnValue = 1.0;
        }
        else if (_FNV_GetFormType(((P01ObjA*)apRefObject)->GetNext()) == 0x17)
        {
            if (((P01PlayerA*)g_thePlayer)->GetTerminalAccessResult(apRefObject) == 2)
            {
                *afReturnValue = 2.0;
            }
            else
            {
                P01TermA* pNextTerm = (P01TermA*)((P01ObjA*)apRefObject)->GetNext();
                if (!pNextTerm->FUN_00501ae0(apRefObject))
                    *afReturnValue = 1.0;
            }
        }
    }
    if (bPrintConditionDebug)
        DebugLog("GetLocked >> %0.f", *afReturnValue);
    return true;
}

void __cdecl DebugLog(char const*, ...);
extern __declspec(thread) bool bPrintConditionDebug;
// Sets the return value to 1.0 if the quest passed in apParam1 is enabled, otherwise 0.0, and logs it when condition debug printing is on.
// @fnv 0x0059e320
bool FUN_0059e320(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    TESQuest* pQuest = apParam1 ? (TESQuest*)apParam1 : 0;
    if (pQuest && pQuest->GetEnabled())
        *afReturnValue = 1.0;
    if (bPrintConditionDebug)
        DebugLog("GetQuestRunning >> %0.2f", *afReturnValue);
    return true;
}

void __cdecl DebugLog(char const*, ...);
enum ReputationType
{
};
struct TESReputation
{
    float GetUnsignedIntegerPointer(ReputationType type);
};
struct FNStub
{
    const char* GetFullName();
};
struct TLSDebugData
{
    unsigned char pad[0x268];
    bool bLog;
};
extern __declspec(thread) TLSDebugData g_tlsDebugData;
// Reads a reputation value for the given type from arg1 into result and logs it when TLS debug logging is enabled; returns true.
// @fnv 0x005a5bd0
bool __cdecl FUN_005a5bd0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    TESReputation* pReputationData = (TESReputation*)arg1;
    {
        ReputationType eReputationType = (ReputationType)(int)arg2;
        if (pReputationData)
        {
            result = pReputationData->GetUnsignedIntegerPointer(eReputationType);
            if (g_tlsDebugData.bLog)
                DebugLog("GetReputation: %s >> %0.2f", ((FNStub*)((char*)pReputationData + 0x18))->GetFullName(),
                         result);
        }
    }
    return true;
}

namespace fnv_005a5cb0 {
extern __declspec(thread) bool g_bReputationDebugLog;
struct FNStub
{
    const char* GetFullName();
};
struct ReputationStub
{
    char FUN_00616a90(unsigned char);
};
void __cdecl DebugLog(const char*, ...);

// @fnv 0x005a5cb0
bool __cdecl FUN_005a5cb0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    ReputationStub* pRep = (ReputationStub*)arg1;
    unsigned int bHigh = (unsigned int)arg2;
    if (pRep)
    {
        result = pRep->FUN_00616a90(bHigh);
        if (g_bReputationDebugLog)
            DebugLog("GetReputation: %s >> %0.2f", ((FNStub*)((char*)pRep + 0x18))->GetFullName(), result);
    }
    return true;
}
}  // namespace fnv_005a5cb0

struct Interface
{
    enum enumMenus
    {
        kMenuNone = 0
    };
    static bool __cdecl IsSaveLoadActive();
    static bool __cdecl GetSelectedTargetIndex(enumMenus id);
    static bool __cdecl IsMenuActive(enumMenus id, unsigned int flag);
};
extern unsigned char DAT_011cab24;
void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern unsigned char g_tlsDebugFlags[0x300];

// @fnv 0x0059c380
bool __cdecl GetMenuModeValue(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    Interface::enumMenus eMenuId = (Interface::enumMenus)(int)apParam1;
    if (eMenuId == 0)
    {
        *afReturnValue = (double)Interface::IsSaveLoadActive();
    }
    else if (DAT_011cab24)
    {
        if (Interface::GetSelectedTargetIndex(eMenuId))
            *afReturnValue = 1.0;
    }
    else
    {
        if (Interface::IsMenuActive(eMenuId, 0))
            *afReturnValue = 1.0;
    }
    if (g_tlsDebugFlags[0x268])
        DebugLog("MenuMode %d >> %0.2f", eMenuId, *afReturnValue);
    return true;
}

namespace fnv_005a3180 {
struct TESFullName_Helper
{
    static const char* __cdecl GetFullName(TESForm*);
};
void __cdecl DebugLog(char const*, ...);
__declspec(thread) extern unsigned char g_tlsDebugFlags[0x300];
struct PCH
{
    bool HasCombatState();
};
struct PlayerCharacterHelper_00953c50
{
    bool FUN_00953c50(bool*);
};
extern PlayerCharacter* g_thePlayer;

// Sets the return value to 1.0 if the reference is an actor in combat, or to the player's combat check result, and logs the state when debug flags are set.
// @fnv 0x005a3180
bool __cdecl GetActorInCombat(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    Actor* pact = 0;
    if (apRefObject && apRefObject->IsActor())
        pact = (Actor*)apRefObject;
    if (pact && ((PCH*)pact)->HasCombatState())
        *afReturnValue = 1.0;
    bool bsearch = false;
    if ((PlayerCharacter*)pact == g_thePlayer)
        *afReturnValue = (double)((PlayerCharacterHelper_00953c50*)g_thePlayer)->FUN_00953c50(&bsearch);
    if (g_tlsDebugFlags[0x268])
    {
        if (*afReturnValue != 0.0)
            DebugLog("%s is in combat", TESFullName_Helper::GetFullName((TESForm*)pact));
        else
            DebugLog("%s is not in combat", TESFullName_Helper::GetFullName((TESForm*)pact));
    }
    return true;
}
}  // namespace fnv_005a3180

bool __cdecl FUN_0059d400(TESObjectREFR* reference, void* arg1, void* arg2, double& result);

// @fnv 0x0059d3a0
bool __cdecl FUN_0059d3a0(void* apReference, void* apUnused, void* apUnused2, double* result)
{
    return FUN_0059d400((TESObjectREFR*)apReference, g_thePlayer, 0, *result);
}

struct FUN_0059eb40
{
    bool GetFlag();
};

// @fnv 0x0059eb40
bool __thiscall FUN_0059eb40::GetFlag()
{
    return (reinterpret_cast<unsigned char*>(this)[0xeb] & 8) != 0;
}

extern bool __cdecl FUN_0059f180(PlayerCharacter* reference, void* arg1, void* arg2, double& result);

// @fnv 0x0059f730
bool __cdecl FUN_0059f730(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    return FUN_0059f180(g_thePlayer, arg1, arg2, result);
}

bool __cdecl FUN_0059f240(PlayerCharacter* reference, void* arg1, void* arg2, double& result);
// @fnv 0x0059f750
bool __cdecl FUN_0059f750(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    return FUN_0059f240(g_thePlayer, arg1, arg2, result);
}

extern NiFixedString* DAT_011c61b4;

// @fnv 0x005a07f0
NiFixedString* FUN_005a07f0()
{
    return DAT_011c61b4;
}

struct FUN_005a2310_This
{
    int mFlags;
};

struct FUN_005a2310_Class
{
    bool IsFlag20Set() const;
};

// @fnv 0x005a2310
bool FUN_005a2310_Class::IsFlag20Set() const
{
    return ((int*)this)[0x34 / 4] & 0x20 ? true : false;
}

// @fnv 0x005a2a50
bool __cdecl FUN_005a2a50(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    return true;
}

struct PlayerS
{
    bool IsSleepingOrResting();
};

__declspec(thread) unsigned char g_DebugTimePassingFlag;

void __cdecl DebugLog(char const*, ...);

// Sets afReturnValue to 1.0 when the player is sleeping or resting, logs whether time is passing if the debug flag is set, and returns true.
// @fnv 0x005a2c70
bool __cdecl FUN_005a2c70(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    if (((PlayerS*)g_thePlayer)->IsSleepingOrResting())
    {
        afReturnValue = 1.0;
    }

    if (g_DebugTimePassingFlag)
    {
        if (afReturnValue != 0.0)
        {
            DebugLog("Time is passing");
        }
        else
        {
            DebugLog("Time is not passing");
        }
    }

    return true;
}

extern int DAT_0119f344;

// @fnv 0x005a3650
bool __cdecl FUN_005a3650(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = -1.0;
    afReturnValue = *(int*)&DAT_0119f344;
    return true;
}

struct PC_00605d70
{
    bool __thiscall FUN_004eaf60();
};

// Sets afReturnValue to 1.0 when the player fails the check FUN_004eaf60, otherwise leaves it at 0.0, and returns true.
// @fnv 0x005a3d00
bool __cdecl FUN_005a3d00(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (!((PC_00605d70*)g_thePlayer)->FUN_004eaf60())
        afReturnValue = 1.0;
    return 1;
}

struct FUN_005a4910_Class
{
    unsigned int GetFieldD68() const;
};

// @fnv 0x005a4910
unsigned int FUN_005a4910_Class::GetFieldD68() const
{
    return *(unsigned int*)((const unsigned char*)this + 0xd68);
}

extern bool DAT_011dbe50;

// @fnv 0x005a50e0
bool __cdecl FUN_005a50e0()
{
    return DAT_011dbe50;
}

struct FUN_005a5b10_Class
{
    unsigned int* GetFieldPointer();
};

// @fnv 0x005a5b10
unsigned int* FUN_005a5b10_Class::GetFieldPointer()
{
    return *(unsigned int**)((char*)this + 0x103b0);
}

struct FUN_005a6050
{
    unsigned char __thiscall GetField();
};

// @fnv 0x005a6050
unsigned char __thiscall FUN_005a6050::GetField()
{
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0xe38);
}

extern bool __cdecl FUN_0059d540(void* ref, void* arg1, void* arg2, void* arg3);

// @fnv 0x0059d3c0
bool __cdecl FUN_0059d3c0(void* ref, void* arg1, void* arg2, double& result)
{
    return FUN_0059d540(ref, g_thePlayer, 0, &result);
}

// Sets afReturnValue to 1.0 if apRefObject is an actor, otherwise 0.0, and returns true.
// @fnv 0x005a39d0
bool __cdecl FUN_005a39d0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    if (apRefObject->IsActor())
        afReturnValue = 1.0;
    return true;
}

namespace fnv_005a3b90 {
struct BGSTalkingActivator
{
    TESObjectREFR* GetTempRef() const;
};
class TESObject
{
  public:
    TESObject* GetNext();
    unsigned int GetFormType();
};
// Sets *result to 1.0 if object's next form is a talking activator whose temp ref equals reference, otherwise 0.0; always returns true.
// @fnv 0x005a3b90
bool __cdecl FUN_005a3b90(TESObject* object, TESObjectREFR* reference, TESObjectREFR* pUnused, double* pfResult)
{
    *pfResult = 0.0;
    TESObjectREFR* pRef = reference;
    if (object && object->GetNext()->GetFormType() == 0x16)
    {
        TESObjectREFR* next = reinterpret_cast<TESObjectREFR*>(object->GetNext());
        if (reinterpret_cast<BGSTalkingActivator*>(next)->GetTempRef() == pRef)
            *pfResult = 1.0;
    }
    return true;
}
}  // namespace fnv_005a3b90

// Sets *result to 0.0 if arg0 is null or equals arg1, otherwise 1.0, and returns true.
// @fnv 0x005a4210
bool __cdecl FUN_005a4210(void* apFirst, void* apSecond, void* apUnused, double* apfResult)
{
    void* tmp = apSecond;
    if (apFirst == 0 || apFirst == tmp)
    {
        *apfResult = 0.0;
    }
    else
    {
        *apfResult = 1.0;
    }
    return true;
}

struct FUN_0059e7d0_Class
{
    bool __thiscall FUN_0059e7d0();
};

// @fnv 0x0059e7d0
bool __thiscall FUN_0059e7d0_Class::FUN_0059e7d0()
{
    return (((unsigned char*)((char*)this + 0xeb))[0] & 1) != 0;
}

struct FUN_0059e8c0_Class
{
    unsigned char padding[0xeb];
    unsigned char flag;
    bool __thiscall IsFlag2Set();
};

// @fnv 0x0059e8c0
bool __thiscall FUN_0059e8c0_Class::IsFlag2Set()
{
    return (flag & 2) != 0;
}

struct FUN_0059f610Class
{
    unsigned char padding[0x70];
    unsigned int m_flag;
    bool FUN_0059f610();
};

// @fnv 0x0059f610
bool FUN_0059f610Class::FUN_0059f610()
{
    return (m_flag & 1) ? true : false;
}

struct FUN_005a03d0Class
{
    unsigned char padding[0x680];
    unsigned char flag;
    unsigned char __thiscall FUN_005a03d0();
};

// @fnv 0x005a03d0
unsigned char __thiscall FUN_005a03d0Class::FUN_005a03d0()
{
    return flag;
}

struct FUN_005a20b0_Standin
{
    unsigned char padding[0x6dc];
    unsigned int field6dc;
    unsigned int GetField6dc();
};

// @fnv 0x005a20b0
unsigned int FUN_005a20b0_Standin::GetField6dc()
{
    return field6dc;
}

struct FUN_005a21d0_Class
{
    unsigned char padding[0x34];
    unsigned int flags;
    bool IsFlag40Set();
};

// @fnv 0x005a21d0
bool FUN_005a21d0_Class::IsFlag40Set()
{
    return (flags & 0x40) ? true : false;
}

struct PlayerCharacterStub
{
    int __thiscall GetActionObjectItemId();
};

// Sets result to zero, then stores the player's value from GetActionObjectItemId into result and returns true.
// @fnv 0x005a3af0
bool __cdecl FUN_005a3af0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    result = ((PlayerCharacterStub*)g_thePlayer)->GetActionObjectItemId();
    return true;
}

struct FUN_005a4b40Class
{
    unsigned char padding[0x13c];
    unsigned int m_val;
    unsigned int FUN_005a4b40();
};

// @fnv 0x005a4b40
unsigned int FUN_005a4b40Class::FUN_005a4b40()
{
    return m_val;
}

struct ActorState
{
    unsigned char padding[0x140];
    unsigned int state;
    unsigned int GetMaskedState() const;
};

// @fnv 0x005a4c00
unsigned int ActorState::GetMaskedState() const
{
    return state & 0x3fffffff;
}

struct FUN_005a5bb0Class
{
    unsigned char padding[0x1b1];
    unsigned char flag;
    unsigned char __thiscall FUN_005a5bb0();
};

// @fnv 0x005a5bb0
unsigned char __thiscall FUN_005a5bb0Class::FUN_005a5bb0()
{
    return flag;
}

namespace fnv_0059d8e0 {
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct InventoryIterator;
struct InventoryStackRecord;
struct NiAVObject;
struct IndexedPointerCollection;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESLevItem;
struct TESObject;
struct TESFormList;
struct TESObjectWEAP;
struct TESWaterForm;
struct blob12
{
    char b[12];
};
struct InventoryChanges
{
    void ForceWeightRecalculation();
    static void KillTempRef();
    void AddItemToEntry(TESBoundObject*, int, Actor*, ExtraDataList*, InventoryStackRecord*);
    bool IsEmpty();
    void AddItem(TESBoundObject*, ExtraDataList*, int);
    void AddItem(TESObjectREFR*, int, bool, bool);
    void AddChangeEntry(InventoryStackRecord*, bool);
    void RemoveChangeItem(TESBoundObject*);
    TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int, ExtraDataList*, bool, TESObjectREFR*, void*,
                              void*, bool, bool, InventoryStackRecord*);
    void UpdateItemCount(int, bool, int);
    TESObjectREFR* DropItem(TESObjectREFR*, TESBoundObject*, int, TESObjectREFR*, void*, void*);
    void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*, ExtraDataList*);
    void DamageItem(TESBoundObject*, float);
    void RepairBatch(TESBoundObject*, float);
    void AddOwnership(TESBoundObject*, TESForm*);
    void RemoveOwnership(TESBoundObject*);
    TESContainer* GetOriginalContainer();
    void RemoveBoundItem(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
    bool RemoveInventoryItem(bool*, TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
    void ResetInventoryChanges();
    bool RunScripts(TESObjectREFR*);
    void ResetInventoryState();
    void CleanUpBoundItems(Actor*);
    TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
    void ModifyCharge(float);
    InventoryStackRecord* GetOrCreateInventoryEntry(TESBoundObject*, bool, unsigned int);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    ExtraDataList* GetExtraDataListForObject(TESBoundObject*, bool);
    bool WearingWeapon(TESBoundObject**);
    bool WearingAmmo(TESBoundObject**);
    bool WearingTorch(TESBoundObject**);
    InventoryStackRecord* WearingRing(bool);
    bool WearingVoiceModulateItem();
    bool HasItemOfType(unsigned int);
    bool FindItemInInventory(TESBoundObject*, int, int, int*, unsigned int, TESObjectREFR*);
    bool HasQuestObject();
    bool HasScript();
    TESBoundObject* GetObjectAtIndex(int, int*);
    TESBoundObject* GetBoundObjectByIndex(int, int*);
    InventoryStackRecord* GetPotion(void*);
    InventoryStackRecord* GetBestAmmoForActor(TESActorBase*, bool);
    TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool*);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    void* GetListBestArmor(TESActorBase*);
    InventoryStackRecord* GetBestClothing(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestLight(TESActorBase*, bool);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* GetEquippedItemForSlot(int);
    InventoryStackRecord** GetEntryPointerByIndices(int, int);
    void SetHotKeyItem(InventoryStackRecord*, ExtraDataList*, int);
    void SetInventoryEntryCount(InventoryStackRecord*, int);
    void RemoveAllObjectsWorn(bool, TESObjectREFR*);
    bool RechargeAll();
    void RemoveAllHealth();
    int GetCount(bool);
    InventoryStackRecord* GetInventoryEntryAtIndex(int);
    IndexedPointerCollection* GetFirstItem();
    InventoryStackRecord* GetEntryForListNode(IndexedPointerCollection*);
    void RemoveItemChangeEntry(TESBoundObject*, void*);
    void RefreshItemChange(TESBoundObject*, void*);
    void UpdateItemChangeEntry(TESBoundObject*, void*);
    int GetObjectCount(int);
    int GetObjectCount(TESBoundObject*);
    InventoryStackRecord* GetFirstInventoryEntry();
    int GetInventoryEntryCount();
    void TransferItemToReference(TESObjectREFR*, int, TESObjectREFR*);
    float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
    void MoveItemsOfType(TESObjectREFR*, TESObjectREFR*, TESForm*);
    void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
    float GetInventoryWeight(bool);
    unsigned int GetTotalItemCount(bool, bool);
    void AddAmountToItemChange(TESBoundObject*, int);
    float GetArmorValueForActor(Actor*);
    void UpdateArmorWeight();
    void UpdateWeight();
    void RemoveDefaultLeveledItems();
    bool IsLevelItemInited(int);
    InventoryStackRecord* FindEntryForObject(TESBoundObject*, unsigned int);
    void SetItemsBacktoDefaultState();
    void CopyInventoryChanges(InventoryChanges*, TESObjectREFR*, bool);
    void ResetEntryList();
    void ResetCachedWeights();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
    ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
    unsigned int FindItemEntryData(int*, void*, unsigned int);
    bool GetNextItem(InventoryIterator*, InventoryStackRecord**, unsigned int);
    TESObjectREFR* GetRef();
    static TESObjectREFR* GetTempRef();
    void RemoveExtraFromObject(TESObject*, ExtraDataList*);
    void DeleteExtraData(TESBoundObject*, ExtraDataList*);
    void* __vecDelDtor(unsigned int);
    void* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    char _pad_11[3];
};
typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];

struct TLSConsoleData
{
    char pad[0x268];
    bool bConsoleOutput;
};
extern __declspec(thread) TLSConsoleData g_tlsData;

void DebugLog(const char*, ...);
int FUN_00ec7d40(int);
TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
int __fastcall FNV_GetFormType(TESForm*);

struct FUN_008256d0_list
{
    bool FUN_008256d0();
    TESForm** FUN_006815c0();
    FUN_008256d0_list* FUN_00726070();
};

// @fnv 0x0059d8e0
bool FUN_0059d8e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    TESForm* pobject;
    TESObjectREFR* ptarget = apRefObject;
    TESForm* pform = (TESForm*)apParam1;
    if (!FUN_0055d310(ptarget))
    {
        if (g_tlsData.bConsoleOutput)
            DebugLog("Calling Reference is not a Container Object");
        return true;
    }
    pobject = 0;
    if (pform && pform->IsActor_InEditor())
        pobject = (TESForm*)apParam1;
    InventoryChanges* pchange = ptarget ? InventoryChanges::CreateForReference(ptarget) : 0;
    if (pchange)
    {
        if (pobject)
        {
            *afReturnValue = FUN_00ec7d40(pchange->GetObjectCount((int)pobject));
        }
        else if (pform && FNV_GetFormType(pform) == 0x55)
        {
            TESForm* pformlist = pform;
            FUN_008256d0_list* pCurrentElementNext = (FUN_008256d0_list*)((Script*)pformlist)->GetHeader();
            while (pCurrentElementNext && !pCurrentElementNext->FUN_008256d0())
            {
                TESForm* pEntryForm = *pCurrentElementNext->FUN_006815c0();
                pCurrentElementNext = pCurrentElementNext->FUN_00726070();
                if (pEntryForm->IsActor_InEditor())
                    *afReturnValue += FUN_00ec7d40(pchange->GetObjectCount((int)pEntryForm));
            }
        }
    }
    if (g_tlsData.bConsoleOutput)
        DebugLog("GetItemCount >> %0.2f", *afReturnValue);
    return true;
}
}  // namespace fnv_0059d8e0

struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct InventoryIterator;
struct InventoryStackRecord;
struct IndexedPointerCollection;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESLevItem;
struct TESObject;
struct TESObjectWEAP;
struct InventoryChanges
{
    void ForceWeightRecalculation();
    static void KillTempRef();
    void AddItemToEntry(TESBoundObject*, int, Actor*, ExtraDataList*, InventoryStackRecord*);
    bool IsEmpty();
    void AddItem(TESBoundObject*, ExtraDataList*, int);
    void AddItem(TESObjectREFR*, int, bool, bool);
    void AddChangeEntry(InventoryStackRecord*, bool);
    void RemoveChangeItem(TESBoundObject*);
    TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int, ExtraDataList*, bool, TESObjectREFR*, void*,
                              void*, bool, bool, InventoryStackRecord*);
    void UpdateItemCount(int, bool, int);
    TESObjectREFR* DropItem(TESObjectREFR*, TESBoundObject*, int, TESObjectREFR*, void*, void*);
    void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*, ExtraDataList*);
    void DamageItem(TESBoundObject*, float);
    void RepairBatch(TESBoundObject*, float);
    void AddOwnership(TESBoundObject*, TESForm*);
    void RemoveOwnership(TESBoundObject*);
    TESContainer* GetOriginalContainer();
    void RemoveBoundItem(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
    bool RemoveInventoryItem(bool*, TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
    void ResetInventoryChanges();
    bool RunScripts(TESObjectREFR*);
    void ResetInventoryState();
    void CleanUpBoundItems(Actor*);
    TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
    void ModifyCharge(float);
    InventoryStackRecord* GetOrCreateInventoryEntry(TESBoundObject*, bool, unsigned int);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    ExtraDataList* GetExtraDataListForObject(TESBoundObject*, bool);
    bool WearingWeapon(TESBoundObject**);
    bool WearingAmmo(TESBoundObject**);
    bool WearingTorch(TESBoundObject**);
    InventoryStackRecord* WearingRing(bool);
    bool WearingVoiceModulateItem();
    bool HasItemOfType(unsigned int);
    bool FindItemInInventory(TESBoundObject*, int, int, int*, unsigned int, TESObjectREFR*);
    bool HasQuestObject();
    bool HasScript();
    TESBoundObject* GetObjectAtIndex(int, int*);
    TESBoundObject* GetBoundObjectByIndex(int, int*);
    InventoryStackRecord* GetPotion(void*);
    InventoryStackRecord* GetBestAmmoForActor(TESActorBase*, bool);
    TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool*);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    void* GetListBestArmor(TESActorBase*);
    InventoryStackRecord* GetBestClothing(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestLight(TESActorBase*, bool);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* GetEquippedItemForSlot(int);
    InventoryStackRecord** GetEntryPointerByIndices(int, int);
    void SetHotKeyItem(InventoryStackRecord*, ExtraDataList*, int);
    void SetInventoryEntryCount(InventoryStackRecord*, int);
    void RemoveAllObjectsWorn(bool, TESObjectREFR*);
    bool RechargeAll();
    void RemoveAllHealth();
    int GetCount(bool);
    InventoryStackRecord* GetInventoryEntryAtIndex(int);
    IndexedPointerCollection* GetFirstItem();
    InventoryStackRecord* GetEntryForListNode(IndexedPointerCollection*);
    void RemoveItemChangeEntry(TESBoundObject*, void*);
    void RefreshItemChange(TESBoundObject*, void*);
    void UpdateItemChangeEntry(TESBoundObject*, void*);
    int GetObjectCount(int);
    int GetObjectCount(TESBoundObject*);
    InventoryStackRecord* GetFirstInventoryEntry();
    int GetInventoryEntryCount();
    void TransferItemToReference(TESObjectREFR*, int, TESObjectREFR*);
    float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
    void MoveItemsOfType(TESObjectREFR*, TESObjectREFR*, TESForm*);
    void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
    float GetInventoryWeight(bool);
    unsigned int GetTotalItemCount(bool, bool);
    void AddAmountToItemChange(TESBoundObject*, int);
    float GetArmorValueForActor(Actor*);
    void UpdateArmorWeight();
    void UpdateWeight();
    void RemoveDefaultLeveledItems();
    bool IsLevelItemInited(int);
    InventoryStackRecord* FindEntryForObject(TESBoundObject*, unsigned int);
    void SetItemsBacktoDefaultState();
    void CopyInventoryChanges(InventoryChanges*, TESObjectREFR*, bool);
    void ResetEntryList();
    void ResetCachedWeights();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
    ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
    unsigned int FindItemEntryData(int*, void*, unsigned int);
    bool GetNextItem(InventoryIterator*, InventoryStackRecord**, unsigned int);
    TESObjectREFR* GetRef();
    static TESObjectREFR* GetTempRef();
    void RemoveExtraFromObject(TESObject*, ExtraDataList*);
    void DeleteExtraData(TESBoundObject*, ExtraDataList*);
    void* __vecDelDtor(unsigned int);
    void* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    char _pad_11[3];
};
typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];

struct FUN_0059da90_FT
{
    int _FNV_GetFormType();
};
struct FUN_0059da90_List
{
    FUN_0059da90_List* GetNext();
    TESForm** _ref_006815c0();
};
struct FUN_0059da90_IC
{
    void* GetExtraDataListForObject(TESBoundObject*, bool);
};
void DebugLog(const char*, ...);
extern __declspec(thread) unsigned char FUN_0059da90_tls[0x269];
// @fnv 0x0059da90
bool __cdecl FUN_0059da90(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* ptarget;
    TESForm* pform;
    FUN_0059da90_List* pCurrentElementNext;
    afReturnValue = 0;
    ptarget = 0;
    if (apRefObject && apRefObject->IsActor())
        ptarget = (Actor*)apRefObject;
    pform = (TESForm*)apParam1;
    if (ptarget && pform)
    {
        pCurrentElementNext = 0;
        if (((FUN_0059da90_FT*)pform)->_FNV_GetFormType() == 0x55)
        {
            BGSListForm* plistform = (BGSListForm*)pform;
            pCurrentElementNext = (FUN_0059da90_List*)((Script*)plistform)->GetHeader();
            pform = *pCurrentElementNext->_ref_006815c0();
        }
        while (pform)
        {
            if (pform->IsActor_InEditor())
            {
                InventoryChanges* pchange = InventoryChanges::CreateForReference((TESObjectREFR*)ptarget);
                if (pchange)
                {
                    TESBoundObject* pobject = (TESBoundObject*)pform;
                    if (((FUN_0059da90_IC*)pchange)->GetExtraDataListForObject(pobject, false))
                    {
                        afReturnValue = 1;
                        break;
                    }
                }
            }
            if (pCurrentElementNext)
                pCurrentElementNext = pCurrentElementNext->GetNext();
            if (pCurrentElementNext)
                pform = *pCurrentElementNext->_ref_006815c0();
            else
                pform = 0;
        }
    }
    if (FUN_0059da90_tls[0x268])
        DebugLog("GetEquipped >> %0.2f", afReturnValue);
    return true;
}

struct FUN_00401170_s
{
    int FUN_00401170();
};
struct PCH
{
    bool HasCombatState();
};
struct ActorShell
{
    bool IsHostileToActor(Actor*, int, int*, bool);
};
struct FUN_00992640_s
{
    bool FUN_00992640(Actor*, Actor*);
};
extern void* BGSSaveLoadGlobalDataWorldspacePtr;
void DebugLog(const char*, ...);
extern __declspec(thread) bool g_bShowConditionDebug;
enum FIGHT_REACTION
{
    FIGHT_REACTION_NEUTRAL = 0
};
struct ActorVStand
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
    virtual FIGHT_REACTION GetFightReaction(Actor*, int);
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
    virtual void* GetCombatController();
};
// @fnv 0x0059ed30
bool FUN_0059ed30(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    int ainumber = 0;
    Actor* pactor = 0;
    if (apParam1)
    {
        switch (((FUN_00401170_s*)apParam1)->FUN_00401170())
        {
        case 0x3b:
        case 0x3c:
            pactor = (Actor*)apParam1;
        }
    }
    Actor* pact9 = 0;
    if (apRefObject && ((ActorVStand*)apRefObject)->IsActor())
        pact9 = (Actor*)apRefObject;
    if (pact9 && pactor)
    {
        bool m_bCombatState = ((PCH*)pactor)->HasCombatState();
        FIGHT_REACTION ereaction;
        int kIreaction;
        int aidisp8 = 0;
        ereaction = ((ActorVStand*)pact9)->GetFightReaction(pactor, 0);
        bool bcrime = false;
        if (m_bCombatState && ((ActorVStand*)pactor)->GetCombatController() &&
            ((FUN_00992640_s*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00992640(pact9, pactor))
            return true;
        int idispcombat = 0;
        kIreaction = 0;
        if (((ActorShell*)pact9)->IsHostileToActor(pactor, 0, &kIreaction, false))
            ainumber = 100;
        *afReturnValue = ainumber;
    }
    if (g_bShowConditionDebug)
        DebugLog("GetShouldAttack >> %i", ainumber);
    return true;
}

struct FUN_0059ef60_FormTypeShell
{
    int _FNV_GetFormType();
};
struct BGSCameraPath
{
    int HasNameForWarning();
};
int _strnicmp(const char*, const char*, unsigned int);
void DebugLog(const char*, ...);
extern TESObjectREFR* DAT_011caaf4;
extern TESObjectCELL* DAT_011caaf8;
extern float DAT_011caafc;
struct FUN_0059ef60_TLS
{
    char pad[0x268];
    bool bDebugOutput;
};
extern __declspec(thread) FUN_0059ef60_TLS g_FUN_0059ef60_TLS;

// @fnv 0x0059ef60
bool FUN_0059ef60(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    TESObjectCELL* pcell = 0;
    if (apParam1 && ((FUN_0059ef60_FormTypeShell*)apParam1)->_FNV_GetFormType() == 0x39)
        pcell = (TESObjectCELL*)apParam1;
    TESObjectREFR* pref = 0;
    if (apParam2)
    {
        switch (((FUN_0059ef60_FormTypeShell*)apParam2)->_FNV_GetFormType())
        {
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x69:
            pref = (TESObjectREFR*)apParam2;
            break;
        }
    }
    if (!pref)
        pref = apRefObject;
    if (pref)
    {
        if (pref == DAT_011caaf4 && DAT_011caaf8 == pcell)
        {
            *afReturnValue = DAT_011caafc;
        }
        else
        {
            TESObjectCELL* prefcell = pref ? pref->GetParentCell() : 0;
            if (prefcell && pcell)
            {
                if (!_strnicmp(((TESForm*)prefcell)->GetName(), ((TESForm*)pcell)->GetName(),
                               ((BGSCameraPath*)pcell)->HasNameForWarning()))
                    *afReturnValue = 1.0;
            }
            DAT_011caaf4 = pref;
            DAT_011caaf8 = pcell;
            DAT_011caafc = (float)*afReturnValue;
        }
    }
    if (g_FUN_0059ef60_TLS.bDebugOutput)
        DebugLog("GetInCell >> %0.2f", *afReturnValue);
    return true;
}

struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex operator-(const NiPoint3&) const;
};
float GetDirectionAngle(const NiPoint3&);
void DebugLog(const char*, ...);
extern double DAT_0101ff58;
extern const double DAT_0102f248;
struct FUN_005a0410_TLS
{
    char padding[0x268];
    bool bShowDebug;
};
__declspec(thread) FUN_005a0410_TLS g_tls_005a0410;

// Computes the angle from the reference to the target reference, normalizes it into range, scales it, and optionally logs it.
// @fnv 0x005a0410
bool FUN_005a0410(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0;
    MobileObject* pmobile = 0;
    if (apRefObject && apRefObject->IsMobileObject())
        pmobile = (MobileObject*)apRefObject;
    TESObjectREFR* ptarget = (TESObjectREFR*)apParam1;
    if (pmobile && ptarget)
    {
        NiPoint3Ex headingToTarget = *(NiPoint3Ex*)ptarget->GetPos() - *pmobile->GetPos();
        float ftargetAngle = GetDirectionAngle(*(NiPoint3*)&headingToTarget);
        *afReturnValue = ftargetAngle - pmobile->AdjustRot(0);
        while (*afReturnValue < DAT_0101ff58)
            *afReturnValue += (double)6.2831855f;
        while (*afReturnValue > (double)3.1415927f)
            *afReturnValue -= (double)6.2831855f;
        *afReturnValue *= DAT_0102f248;
    }
    if (g_tls_005a0410.bShowDebug)
        DebugLog("Heading Angle: %0.2f", *afReturnValue);
    return true;
}

namespace fnv_0059d400 {
class NiColor;
class TESFaction;
class PlayerCharacter;
struct FactionReaction
{
    TESFaction* pFaction;
    char m_ucRank;
};
struct ContNode
{
    FactionReaction* m_item;
    ContNode* m_next;
    FactionReaction** _ref_006815c0();
};
bool __fastcall FUN_008256d0(ContNode*);
ContNode* __fastcall FUN_00726070(ContNode*);
struct TESRegion
{
    NiColor* GetDiffuseColor();
};
struct TESActorBaseData
{
    int GetFactionRank(TESFaction*, bool);
};
struct XActor
{
    void* GetActorBase();
};
struct SF_Ref
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
};
void DebugLog(const char*, ...);
extern __declspec(thread) bool g_bConditionDebugOutput;

// @fnv 0x0059d400
bool FUN_0059d400(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    XActor* pact = 0;
    if (apRefObject && ((SF_Ref*)apRefObject)->IsActor())
        pact = (XActor*)apRefObject;
    XActor* pacttar = (XActor*)apParam1;
    if (!pact || !pacttar)
        return true;
    void* pactorbase1 = pact->GetActorBase();
    void* pactorbase2 = pacttar->GetActorBase();
    if (pactorbase1 && pactorbase2)
    {
        TESFaction* pfac1 = 0;
        ContNode* pCurrentElementNext = (ContNode*)((TESRegion*)((char*)pactorbase1 + 0x30))->GetDiffuseColor();
        while (pCurrentElementNext && !FUN_008256d0(pCurrentElementNext) && afReturnValue != 1.0)
        {
            pfac1 = (*pCurrentElementNext->_ref_006815c0())->pFaction;
            if (pfac1 && ((TESActorBaseData*)((char*)pactorbase2 + 0x30))
                                 ->GetFactionRank(pfac1, pacttar == (XActor*)g_thePlayer) != -1)
                afReturnValue = 1.0;
            pCurrentElementNext = FUN_00726070(pCurrentElementNext);
        }
    }
    if (g_bConditionDebugOutput)
        DebugLog("SameFaction >> %0.2f", afReturnValue);
    return true;
}
}  // namespace fnv_0059d400

namespace fnv_0059d610 {
struct TESObject
{
    unsigned int GetNext();
};
struct TESActorBase
{
    int GetSex();
};
struct TESNPC : TESActorBase
{
};
struct FNV_GetFormTypeHelper
{
    int _FNV_GetFormType();
};
void __cdecl _DebugLog(const char*, ...);
__declspec(thread) bool g_bDebugLogEnabled;
// Sets result to 1.0 if reference and actor1 are both NPCs of form type 0x2a with equal sex, logs the value, and returns true.
// @fnv 0x0059d610
bool __cdecl FUN_0059d610(TESObject* reference, TESObject* actor1, TESObject* actor2, double& result)
{
    TESNPC* pnpc1;
    TESNPC* pnpc2;
    result = 0.0;
    pnpc1 = 0;
    if (reference)
    {
        if (((FNV_GetFormTypeHelper*)reference->GetNext())->_FNV_GetFormType() == 0x2a)
        {
            pnpc1 = (TESNPC*)reference->GetNext();
        }
    }
    pnpc2 = 0;
    if (actor1)
    {
        if (((FNV_GetFormTypeHelper*)actor1->GetNext())->_FNV_GetFormType() == 0x2a)
        {
            pnpc2 = (TESNPC*)actor1->GetNext();
        }
    }
    if (pnpc1 && pnpc2 && pnpc1->GetSex() == pnpc2->GetSex())
    {
        result = 1.0;
    }
    if (g_bDebugLogEnabled)
    {
        _DebugLog("SameSex >> %0.2f", result);
    }
    return true;
}
}  // namespace fnv_0059d610

namespace fnv_0059d6e0 {
struct DetRefV
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
};
struct DetProcV
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
    virtual void v2bc();
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
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4();
    virtual void v6e8();
    virtual void v6ec();
    virtual void v6f0();
    virtual void v6f4();
    virtual void v6f8();
    virtual void v6fc();
    virtual void v700();
    virtual void v704();
    virtual void v708();
    virtual void v70c();
    virtual void v710();
    virtual void v714();
    virtual void v718();
    virtual void v71c();
    virtual void v720();
    virtual void v724();
    virtual void v728();
    virtual void v72c();
    virtual void v730();
    virtual float GetLight();
};
class TES
{
  public:
    void* GetLogDate();
};
class PCH
{
  public:
    bool HasCombatState();
};
struct PlayerOps_59d6e0
{
    bool FUN_00953c50(bool*);
};
struct DetActorHelper
{
    int CalculateDetectionLevel(int, Actor*, bool*, bool, int, bool, bool*);
};
void DebugLog(const char*, ...);
extern __declspec(thread) bool g_bDebugLogDetect;

// Checks whether apRefObject (an actor) detects apParam1, sets afReturnValue to 1 when detection succeeds, and logs the result and light level.
// @fnv 0x0059d6e0
bool FUN_0059d6e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int iCount;
    int ilight;
    Actor* pactor;
    Actor* pdetector;
    afReturnValue = 0;
    iCount = 0;
    ilight = -1;
    pactor = 0;
    if (apRefObject && ((DetRefV*)apRefObject)->IsActor())
        pactor = (Actor*)apRefObject;
    pdetector = 0;
    if (apParam1 && ((DetRefV*)apParam1)->IsActor())
        pdetector = (Actor*)apParam1;
    if (pactor && pdetector && ((TES*)pactor)->GetLogDate() && ((TES*)pdetector)->GetLogDate())
    {
        bool blinesight;
        bool bincombat;
        bool bsearch;
        bincombat = false;
        bsearch = false;
        if (pdetector == (Actor*)g_thePlayer)
            bincombat = ((PlayerOps_59d6e0*)g_thePlayer)->FUN_00953c50(&bsearch);
        else
            bincombat = ((PCH*)pdetector)->HasCombatState();
        iCount =
            ((DetActorHelper*)pactor)->CalculateDetectionLevel(0, pdetector, &blinesight, false, bincombat, false, 0);
        if (iCount > 0)
            afReturnValue = 1;
        ilight = (int)((DetProcV*)((TES*)pdetector)->GetLogDate())->GetLight();
    }
    if (g_bDebugLogDetect)
        DebugLog("GetDetected >> %i and light %i", iCount, ilight);
    return true;
}
}  // namespace fnv_0059d6e0

namespace fnv_0059e1a0 {
struct FormFlagRecord;
struct ActorValueOwner;
struct AlchemyItem;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ExtraLeveledItem;
struct InventoryChanges;
struct ScriptDefinition;
struct TESBoundObject;
struct TESObjectWEAP;
struct ScriptLocals
{
    void ClearActionFlags();
    bool GetLocalData(TESForm*, unsigned int);
    void ClearActionFlagsForForm(TESForm*);
    bool CheckActionFlag(TESForm*, unsigned int);
    FormFlagRecord* GetActionEntry(TESForm*, bool);
    void Save(ScriptHeaderData*);
    void ClearActionList();
    void InitializeActionList();
    void CopyActionListFrom(ScriptLocals*);
    void* GetActionList();
    void ResetFormData(Script*);
    void SetVariable(unsigned int, double);
    double GetVariable(unsigned int, Script*);
    void* GetLocalList();
    bool IsReferenceVariable(unsigned int);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void Revert(BGSLoadFormBuffer*);
    void Revert();
    static void ProcessPendingTasks();
    void* __vecDelDtor(unsigned int);
    Script* m_pOwnerScript;
    char m_cActionFlags;
    char _pad_5[3];
    void* m_pLocalVariableList;
    void* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;
};
typedef char _sizecheck_ScriptLocals[sizeof(ScriptLocals) == 20 ? 1 : -1];
struct InventoryStackRecord
{
    void Copy(InventoryStackRecord*);
    void MergeEntryData(InventoryStackRecord*);
    void ClearEntryData();
    TESBoundObject* GetContainerObject();
    void* GetExtraDataList();
    float GetConditionPercent(bool);
    int GetItemUses();
    float GetItemCharge();
    TESForm* GetInventoryObject();
    float GetItemValue();
    int GetHotKey();
    void SetHotKey(int);
    AlchemyItem* GetPoison();
    void RemovePoison();
    bool IsWorn(bool);
    bool IsWornDefault(bool);
    int GetCount();
    Script* GetScript();
    ScriptLocals* GetScriptLocalData();
    ExtraLeveledItem* RemoveLeveledItemExtra();
    bool HasPerkEntry();
    int NumberLeveledExtra();
    bool HasApplicablePerkEntry();
    int NumberStolenData();
    void RemoveOriginalChanges();
    bool IsWornStolen();
    unsigned char GetWeaponCategory();
    void SetModSlot(unsigned char);
    unsigned char GetModEffect(unsigned char);
    bool SetEquipmentState(unsigned char);
    bool SetEquipmentState(unsigned char, float*);
    void RoundToNearestStep();
    void GetPayloadAddress();
    static float GetModifiedAttackDamage(TESObjectWEAP*, ActorValueOwner*, float);
    float GetModifiedAttackDamage(ActorValueOwner*, float, bool);
    float GetDamageResistance(ActorValueOwner*);
    float GetArmorDamageThreshold(ActorValueOwner*);
    int GetTypeforMenu();
    char* GetDisplayNameForReference(TESObjectREFR*);
    char* GetFullName();
    float GetValueforMenuCol1(bool, Actor*, bool);
    float GetValueforMenuCol2(bool, Actor*, bool);
    float GetValueforMenuCol3(bool, Actor*, bool);
    float GetValueforMenuCol4(bool, bool, Actor*, bool);
    char* GetValueforMenu(int, bool, bool, Actor*, bool);
    void SetItemHealth(float, InventoryChanges*, ExtraDataList*, bool);
    void SetItemUses(int);
    void SetItemCharge(float, InventoryChanges*, ExtraDataList*);
    void SetItemOwner(TESForm*);
    void SetPoison(AlchemyItem*);
    void SetEquippedState(bool, bool, bool);
    void SetCount(int);
    bool ShouldDisplayItem(Actor*, bool, int, bool, bool);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetStatusFlags();
    char* GetStatusIcon(int);
    TESBoundObject* GetItemChangeObject();
    void SetItemChangeObject(TESBoundObject*);
    int GetCountWithExtras(bool);
    int GetTotalCount();
    int GetAmountDefaultExtra();
    int GetExtraDataCount();
    void* __vecDelDtor(unsigned int);
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
};
typedef char _sizecheck_ItemChange[sizeof(InventoryStackRecord) == 12 ? 1 : -1];

class TESObject
{
  public:
    TESObject* GetNext();
};

unsigned int __fastcall _FNV_GetFormType(TESForm* form);
::ScriptLocals* __fastcall FUN_004bdea0(InventoryStackRecord* item);

struct TESObjectREFR_Helper
{
    InventoryStackRecord* call_576260(TESObject* obj, unsigned int formID);
};
static InventoryStackRecord* (__thiscall TESObjectREFR_Helper::*volatile _force_576260)(TESObject*, unsigned int) =
    &TESObjectREFR_Helper::call_576260;

struct ScriptLocals_Helper
{
    double call_5a9140(void* arg2, Script* script);
};
static double (__thiscall ScriptLocals_Helper::*volatile _force_5a9140)(void*,
                                                                        Script*) = &ScriptLocals_Helper::call_5a9140;

struct ExtraDataList_Access : public ExtraDataList
{
    TESObjectREFR* GetReplacementReference();
};
static TESObjectREFR* (__thiscall ExtraDataList_Access::*volatile _force_GetReferencePointer)() =
    &ExtraDataList_Access::GetReplacementReference;

struct ItemChange_WithDtor : public InventoryStackRecord
{
    ~ItemChange_WithDtor();
};

// @fnv 0x0059e1a0
bool __cdecl FUN_0059e1a0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESForm* pForm = apParam1 ? static_cast<TESForm*>(apParam1) : 0;
    if (pForm)
    {
        ::ScriptLocals* m_pScriptLocals = 0;
        switch ((_FNV_GetFormType)(pForm))
        {
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
        case 0x40:
        case 0x69: {
            TESObjectREFR* pRef = static_cast<TESObjectREFR*>(pForm);
            if (static_cast<ExtraDataList_Access*>(pRef->GetExtraData())->GetReplacementReference())
            {
                TESObjectREFR* m_pContainer =
                    static_cast<ExtraDataList_Access*>(pRef->GetExtraData())->GetReplacementReference();
                InventoryStackRecord* pItemChange =
                    reinterpret_cast<TESObjectREFR_Helper*>(m_pContainer)
                        ->call_576260(reinterpret_cast<TESObject*>(pRef)->GetNext(), pRef->GetFormID());
                if (pItemChange)
                {
                    m_pScriptLocals = FUN_004bdea0(pItemChange);
                }
                delete static_cast<ItemChange_WithDtor*>(pItemChange);
            }
            else
            {
                m_pScriptLocals = pRef->GetReferenceLocals();
            }
            break;
        }
        case 0x47: {
            TESQuest* pQuest = static_cast<TESQuest*>(pForm);
            if (pQuest)
            {
                m_pScriptLocals = pQuest->GetScriptLocalData();
            }
            break;
        }
        }
        if (m_pScriptLocals && ((ScriptLocals*)m_pScriptLocals)->m_pOwnerScript)
        {
            afReturnValue = reinterpret_cast<ScriptLocals_Helper*>(m_pScriptLocals)->call_5a9140(apParam2, 0);
        }
    }
    return true;
}
}  // namespace fnv_0059e1a0

namespace fnv_0059e700 {
struct BSAudio
{
    void* GetAudioBackendData();
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
struct FUN_0059e7d0_Class
{
    bool FUN_0059e7d0();
};
struct Sky : BSAudio
{
    static Sky* GetInstance();
    float FUN_006447d0();
    unsigned int GetTime() const;
};
void _DebugLog(const char* fmt, ...);
__declspec(thread) bool _DebugLogEnabled;
// @fnv 0x0059e700
bool FUN_0059e700(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Sky* pWeatherSky = Sky::GetInstance();
    afReturnValue =
        pWeatherSky->GetAudioBackendData() && ((FUN_0059e7d0_Class*)pWeatherSky->GetAudioBackendData())->FUN_0059e7d0()
            ? pWeatherSky->FUN_006447d0()
            : 0.0;
    afReturnValue += pWeatherSky->GetTime() && ((FUN_0059e7d0_Class*)pWeatherSky->GetTime())->FUN_0059e7d0()
                         ? 1.0 - pWeatherSky->FUN_006447d0()
                         : 0.0;
    if (_DebugLogEnabled)
        _DebugLog("GetIsPleasant >> %0.2f", afReturnValue);
    return true;
}
}  // namespace fnv_0059e700

namespace fnv_0059e7f0 {
struct Sky
{
    static Sky* GetInstance();
    void* GetAudioBackendData();
    unsigned int GetTime() const;
    float FUN_006447d0();
};
struct FUN_0059e8c0_Class
{
    bool IsFlag2Set();
};
void _DebugLog(const char*, ...);
__declspec(thread) bool g_pLogDebug;
// @fnv 0x0059e7f0
bool __cdecl FUN_0059e7f0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Sky* pWeatherSky = Sky::GetInstance();
    afReturnValue =
        pWeatherSky->GetAudioBackendData() && ((FUN_0059e8c0_Class*)pWeatherSky->GetAudioBackendData())->IsFlag2Set()
            ? pWeatherSky->FUN_006447d0()
            : 0.0;
    afReturnValue += pWeatherSky->GetTime() && ((FUN_0059e8c0_Class*)pWeatherSky->GetTime())->IsFlag2Set()
                         ? 1.0 - pWeatherSky->FUN_006447d0()
                         : 0.0;
    if (g_pLogDebug)
        _DebugLog("GetIsCloudy >> %0.2f", afReturnValue);
    return true;
}
}  // namespace fnv_0059e7f0

struct ActorX
{
    bool FUN_00437bf0();
};
struct MobileObjectShell
{
    const char* GetFullName();
};
void __cdecl _DebugLog(const char* fmt, ...);
__declspec(thread) unsigned char g_theDebugLevel;

// Sets result to 1.0 if the reference is an actor that is restrained, logs the state when debug logging is enabled, and returns true.
// @fnv 0x0059ff90
bool __cdecl FUN_0059ff90(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    ActorX* actor = 0;
    if (reference && reference->IsActor())
        actor = (ActorX*)reference;
    if (actor)
    {
        if (actor->FUN_00437bf0())
            result = 1.0;
        if (g_theDebugLevel)
        {
            if (result != 0.0)
                _DebugLog("%s is restrained", ((MobileObjectShell*)actor)->GetFullName());
            else
                _DebugLog("%s is not restrained", ((MobileObjectShell*)actor)->GetFullName());
        }
    }
    return true;
}

namespace fnv_005a02f0 {
struct FUN_005a03d0Class
{
    unsigned char FUN_005a03d0();
};
struct FUN_005a03f0_obj
{
    bool FUN_005a03f0(unsigned int);
};
void __cdecl _DebugLog(const char* fmt, ...);
extern PlayerCharacter* _g_thePlayer;
extern int DAT_0118c608[7];
__declspec(thread) unsigned char pDebugLog;

// Sets afReturnValue to 1.0 if the player's control bit for apParam1 is disabled, else 0.0, and logs each control's state when pDebugLog is set.
// @fnv 0x005a02f0
bool __cdecl FUN_005a02f0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    unsigned int ibit = (unsigned int)apParam1;
    if (((FUN_005a03f0_obj*)_g_thePlayer)->FUN_005a03f0(ibit))
        afReturnValue = 1.0;
    if (pDebugLog)
    {
        _DebugLog("GetPlayerControlsDisabled: %0.2f", afReturnValue);
        signed char cDisabledFlags = ((FUN_005a03d0Class*)_g_thePlayer)->FUN_005a03d0();
        for (int iIndex = 0; iIndex < 7; ++iIndex)
        {
            if (cDisabledFlags & 1)
                _DebugLog("     %s - Disabled", DAT_0118c608[iIndex]);
            else
                _DebugLog("     %s - Enabled", DAT_0118c608[iIndex]);
            cDisabledFlags = (signed char)(cDisabledFlags >> 1);
        }
    }
    return true;
}
}  // namespace fnv_005a02f0

namespace fnv_005a05e0 {
struct TESObjectWEAP;
struct BGSListForm;
struct InventoryStackRecord;
struct TES
{
    void* GetLogDate();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct LH
{
    bool IsInList(int&);
};
class BaseProcess
{
  public:
    virtual ~BaseProcess();
    virtual void Copy();
    virtual void SetReferenceTarget();
    virtual void Update(MobileObject*);
    virtual void Update(MobileObject*, float);
    virtual void SetMobileObjectState();
    virtual void GetActorWorldPosition();
    virtual void GetActorNodePosition();
    virtual void GetActorValueAtIndex();
    virtual void CanProcessActor();
    virtual void ResetPackageState();
    virtual void IsLowProcessStateValid();
    virtual void GetPackedStateBits0To8();
    virtual void GetPackedStateBits9To12();
    virtual void GetPackedStateBits13To26();
    virtual void SetProcessInteger();
    virtual void GetProcessInteger();
    virtual void StartIdleAnimation();
    virtual void ClearIdleAnimation();
    virtual void GetCurrentMagicItem();
    virtual void SetCurrentMagicItem();
    virtual void SetActorMagicItem();
    virtual void InitializeProcessState();
    virtual void UpdateHealthBar();
    virtual void GetIdleDoneOnce();
    virtual void MarkIdleDoneOnce();
    virtual void ShouldProcessActor();
    virtual void ProcessActorGroupState();
    virtual void CanUsePlayerAction();
    virtual void CanPerformActorAction();
    virtual void IsAsleep();
    virtual void ProcessSandman();
    virtual void ProcessCannibal();
    virtual void ProcessFurniture();
    virtual void SetCombatEnabled();
    virtual void FindPackageTarget();
    virtual void GetPackageLocationReference();
    virtual void GetActorTargetReference();
    virtual void GetActorTargetPosition();
    virtual void GetTargetCell();
    virtual void GetTargetWorldSpace();
    virtual void GetTargetDistance();
    virtual void GetMobileObject();
    virtual void AdvanceProcess();
    virtual void EvaluateActorPackage();
    virtual void FindPackageToEvaluate();
    virtual void GetFirstProcessFloat();
    virtual void SetCurrentSpeed();
    virtual void EvaluateCurrentPackage();
    virtual void SelectPackage();
    virtual void SetPackageForActor();
    virtual void HasInterruptPackage();
    virtual void SetEssentialFlag();
    virtual void PlayRandomIdle();
    virtual void ProcessActorIdle();
    virtual void PlayIdleAnimation();
    virtual void ClearAnimationState();
    virtual void GetEssentialDownTimer();
    virtual void SetEssentialDownTimer();
    virtual void ResetEssentialDownTimer();
    virtual void FindDetectionRecord();
    virtual void GetDetectionRecords();
    virtual void FindDetectionEventForActor();
    virtual void AddDetectionEvent();
    virtual void RemoveDetectionEvent();
    virtual void ClearDetectionEvents();
    virtual void GetWeaponScore();
    virtual void SetWeaponScore();
    virtual void HasCaughtPlayerPickpocketing();
    virtual void SetIsWeaponReady();
    virtual void SetAnimationComplete();
    virtual void IsMovementComplete();
    virtual void SetCurrentMovementComplete();
    virtual void GetCurrentMovementComplete();
    virtual void GetTarget();
    virtual void SetTarget();
    virtual void GetDoor();
    virtual void SetDoor();
    virtual void AddDeferredHideLimb();
    virtual void GetObjectToAcquire();
    virtual void SetFaceAnimationData();
    virtual void GetActorFaceGenData();
    virtual InventoryStackRecord* GetActiveWeapon();
};
int __fastcall _FNV_GetFormType(unsigned int);
extern unsigned int g_uiConditionFunctionState;
void _DebugLog(const char*, ...);
extern __declspec(thread) bool bLogConditionFunctions;

// @fnv 0x005a05e0
bool __cdecl FUN_005a05e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    BGSListForm* pformlist = (BGSListForm*)apParam1;
    Actor* pactor = 0;
    if (apRefObject && apRefObject->IsActor())
        pactor = (Actor*)apRefObject;
    if (pactor && ((TES*)pactor)->GetLogDate() && pformlist)
    {
        InventoryStackRecord* pweapdata = ((BaseProcess*)((TES*)pactor)->GetLogDate())->GetActiveWeapon();
        TESObjectWEAP* pweap = 0;
        if (pweapdata && ((ArrSI*)pweapdata)->GetFlags() && _FNV_GetFormType(((ArrSI*)pweapdata)->GetFlags()) == 0x28)
            pweap = (TESObjectWEAP*)((ArrSI*)pweapdata)->GetFlags();
        if (!pweap)
            pweap = (TESObjectWEAP*)g_uiConditionFunctionState;
        if (pweap)
        {
            int key = (int)pweap;
            if (((LH*)((Script*)pformlist)->GetHeader())->IsInList(key))
                afReturnValue = 1.0;
        }
    }
    if (bLogConditionFunctions)
        _DebugLog("IsWeaponInList >> %0.2f", afReturnValue);
    return true;
}
}  // namespace fnv_005a05e0

void __cdecl _DebugLog(const char* format, ...);
struct OwnedCellOwner
{
    bool FUN_00546ca0(TESObjectREFR* reference);
};
__declspec(thread) unsigned char g_DebugLogFlag;
// Sets result to 1.0 when reference is an actor whose parent cell reports it as owned, otherwise 0.0, and logs the value when debug logging is enabled.
// @fnv 0x005a19a0
bool __cdecl FUN_005a19a0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    TESObjectREFR* owner = 0;
    if (reference && reference->IsActor())
        owner = reference;
    if (owner && owner->GetParentCell() &&
        reinterpret_cast<OwnedCellOwner*>(owner->GetParentCell())->FUN_00546ca0(owner))
        result = 1.0;
    if (g_DebugLogFlag)
        _DebugLog("Is in owned cell value %0.2f", result);
    return true;
}

struct GhostH
{
    bool GetGhost() const;
};
void __cdecl _DebugLog(const char* fmt, ...);
struct TESObjectREFR_VTable
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual bool vfn_100();
};
__declspec(thread) bool g_bConditionFunctionFlags[57];
// @fnv 0x005a2a60
bool __cdecl FUN_005a2a60(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    TESObjectREFR* actor = 0;
    if (reference && ((TESObjectREFR_VTable*)reference)->vfn_100())
        actor = reference;
    if (actor && ((GhostH*)actor)->GetGhost())
        result = 1.0;
    if (g_bConditionFunctionFlags[56])
        _DebugLog("GetGhost >> %0.2f", result);
    return true;
}

struct TESWaterForm
{
    bool FUN_00580060();
};
struct FUN_005a3740_cls
{
    unsigned char GetByteAt14C();
};
struct FUN_005a3740_shell
{
    unsigned char GetByteAt14C();
};
struct FUN_00547770_shell
{
    TESWaterForm* FUN_00547770();
};
// Sets result to 1.0 when reference is an actor in a parent cell whose water form reports true, otherwise leaves result at 0.0, and returns true.
// @fnv 0x005a36b0
bool __cdecl FUN_005a36b0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        TESObjectREFR* actor = reference;
        if (actor && ((FUN_005a3740_cls*)actor)->GetByteAt14C() && actor->GetParentCell() &&
            ((FUN_00547770_shell*)actor->GetParentCell())->FUN_00547770() &&
            ((FUN_00547770_shell*)actor->GetParentCell())->FUN_00547770()->FUN_00580060())
            result = 1.0;
    }
    return true;
}

namespace fnv_0059c930 {
struct TESObjectREFRScaleView
{
    float GetScale();
};
struct ActorV_S
{
    float GetScale();
};
extern "C" void __cdecl _DebugLog(const char*, ...);
struct ThreadLocalFlags
{
    unsigned char bDebugLogging;
};
__declspec(thread) ThreadLocalFlags g_threadLocalFlags;
// If apRefObject is non-null, stores its GetScale result in afReturnValue and, when debug logging is on, logs it with the base scale; returns true.
// @fnv 0x0059c930
bool __cdecl GetObjectScale(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    if (apRefObject)
    {
        afReturnValue = ((TESObjectREFRScaleView*)apRefObject)->GetScale();
        if (g_threadLocalFlags.bDebugLogging)
            _DebugLog("GetScale >> %0.2f (with base %0.2f)", afReturnValue, ((ActorV_S*)apRefObject)->GetScale());
    }
    return true;
}
}  // namespace fnv_0059c930

namespace fnv_0059d1d0 {
struct LockExtraData
{
    bool MeetsMinimumLockLevel();
};
struct P01RefA
{
    LockExtraData* GetLock();
};
void __cdecl _DebugLog(const char*, ...);
__declspec(thread) bool g_debugLog;
// Sets result to 0, or to the lock's broken flag if the reference has a lock, logs it, and returns true.
// @fnv 0x0059d1d0
bool __cdecl FUN_0059d1d0(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (reference)
    {
        LockExtraData* lock = ((P01RefA*)reference)->GetLock();
        if (lock)
        {
            int broken = lock->MeetsMinimumLockLevel();
            result = broken;
        }
    }
    if (g_debugLog)
        _DebugLog("GetIsLockBroken >> %0.f", result);
    return true;
}
}  // namespace fnv_0059d1d0

namespace fnv_0059fb00 {
int __cdecl FUN_00600910();
__declspec(thread) unsigned char g_tlsDebugFlag;
extern "C" int __cdecl _DebugLog(const char*, ...);
// Stores the value returned by FUN_00600910 in afReturnValue, logs it when g_tlsDebugFlag is set, and returns true.
// @fnv 0x0059fb00
bool __cdecl FUN_0059fb00(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = FUN_00600910();
    if (g_tlsDebugFlag)
        _DebugLog("GetIsUsedItemLevel >> %0.2f", afReturnValue);
    return true;
}
}  // namespace fnv_0059fb00

namespace fnv_005a1880 {
class TES
{
  public:
    void* GetLogDate();
};
class Sky
{
  public:
    float GetFieldCC();
};
extern int g_TES;
extern "C" int __cdecl _DebugLog(const char*, ...);
extern __declspec(thread) unsigned char g_DebugLogFlag;
// Sets result to the sky's wind speed and returns true when the TES log date is available, otherwise returns false; logs the value if debug logging is enabled.
// @fnv 0x005a1880
bool __cdecl FUN_005a1880(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (!(g_TES && ((TES*)g_TES)->GetLogDate()))
        return false;
    result = ((Sky*)((TES*)g_TES)->GetLogDate())->GetFieldCC();
    if (g_DebugLogFlag)
        _DebugLog("GetWindSpeed >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a1880

namespace fnv_005a1c30 {
struct BGSOpenCloseForm
{
    static int __cdecl GetOpenState(TESObjectREFR*);
};
extern "C" void __cdecl _DebugLog(const char*, ...);
__declspec(thread) bool g_bDebugLogging;
// Zeroes result, stores GetOpenState(reference) when reference is non-null, logs it if debug logging is on, and returns true.
// @fnv 0x005a1c30
bool __cdecl FUN_005a1c30(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (reference)
        result = BGSOpenCloseForm::GetOpenState(reference);
    if (g_bDebugLogging)
        _DebugLog("GetOpenState >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a1c30

namespace fnv_005a20d0 {
struct FUN_0047d720Class
{
    bool HasFactionFlag8() const;
};
void _DebugLog(const char*);
__declspec(thread) unsigned char g_tlsDebugFlag;

// Sets afReturnValue to 1.0 if the faction in apParam1 reports the PC is expelled, otherwise 0.0, and logs the result when debug logging is enabled.
// @fnv 0x005a20d0
bool __cdecl FUN_005a20d0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    FUN_0047d720Class* pFaction = reinterpret_cast<FUN_0047d720Class*>(apParam1);
    if (pFaction && pFaction->HasFactionFlag8())
        afReturnValue = 1.0;
    if (g_tlsDebugFlag)
    {
        if (afReturnValue != 0.0)
            _DebugLog("PC is expelled.");
        else
            _DebugLog("PC is not expelled.");
    }
    return true;
}
}  // namespace fnv_005a20d0

namespace fnv_005a2150 {
struct FUN_005a21d0_Class
{
    bool IsFlag40Set();
};
void _DebugLog(const char*);
__declspec(thread) unsigned char g_tlsFlag;
// Sets result to 1.0 if the faction object reports a murder, otherwise 0.0, and logs the outcome when the TLS flag is set; always returns true.
// @fnv 0x005a2150
bool FUN_005a2150(TESObjectREFR* ref, void* apFaction, void* apUnused, double& result)
{
    result = 0.0;
    FUN_005a21d0_Class* faction = (FUN_005a21d0_Class*)apFaction;
    if (faction && faction->IsFlag40Set())
        result = 1.0;
    if (g_tlsFlag)
    {
        if (result != 0.0)
            _DebugLog("PC murdered a faction member.");
        else
            _DebugLog("PC did not Murder a faction member.");
    }
    return true;
}
}  // namespace fnv_005a2150

namespace fnv_005a2290 {
struct FUN_005a2310_Class
{
    bool IsFlag20Set() const;
};
void __cdecl _DebugLog(const char*);
struct PlayerCharacter
{
    bool bDebugLogging;
};
__declspec(thread) bool g_tlsDebugLogging;
// Sets afReturnValue to 1.0 if apParam1 is a faction that passes IsFlag20Set, logs the result when debug logging is on, and returns true.
// @fnv 0x005a2290
bool __cdecl FUN_005a2290(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESFaction* pFaction = static_cast<TESFaction*>(apParam1);
    if (pFaction && reinterpret_cast<FUN_005a2310_Class*>(pFaction)->IsFlag20Set())
        afReturnValue = 1.0;
    if (g_tlsDebugLogging)
    {
        if (afReturnValue != 0.0)
            _DebugLog("PC attacked a faction member.");
        else
            _DebugLog("PC did not attack a faction member.");
    }
    return true;
}
}  // namespace fnv_005a2290

namespace fnv_005a2590 {
struct ArrSI
{
    unsigned int GetFlags();
};
extern ArrSI DAT_011f2250;
extern "C" void __cdecl _DebugLog(const char*, ...);
__declspec(thread) unsigned char g_tlsFlag;
// Sets result to the flags of DAT_011f2250 as a double, logs it when g_tlsFlag is set, and returns true.
// @fnv 0x005a2590
bool __cdecl FUN_005a2590(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    result = (double)(int)DAT_011f2250.GetFlags();
    if (g_tlsFlag)
        _DebugLog("VATS Mode >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a2590

namespace fnv_005a3570 {
struct TES
{
    void* GetLogDate(void);
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
    virtual bool v104();
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
};

struct LogDate
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
    virtual bool v060();
};

// Sets result to 0.0, then to 1.0 if reference is an actor whose log date passes v060; always returns true.
// @fnv 0x005a3570
bool __cdecl FUN_005a3570(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    TES* log = 0;
    if (reference && reference->IsActor())
        log = (TES*)reference;
    if (log && log->GetLogDate())
    {
        LogDate* pLogDate = (LogDate*)log->GetLogDate();
        if (pLogDate->v060())
            result = 1.0;
    }
    return true;
}
}  // namespace fnv_005a3570

struct ActorProxy
{
    bool HasNoRumors();
};
// Sets result to 1.0 if reference is an actor whose HasNoRumors returns true, otherwise 0.0, and returns true.
// @fnv 0x005a35f0
bool __cdecl FUN_005a35f0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    ActorProxy* actor = 0;
    if (reference && reference->IsActor())
        actor = reinterpret_cast<ActorProxy*>(reference);
    if (actor && actor->HasNoRumors())
        result = 1.0;
    return true;
}

namespace fnv_005a3820 {
struct DebugLogStandIn
{
    static void __cdecl _DebugLog(const char* format, ...);
};
struct DebugLogFlag
{
    unsigned char padding[0x268];
    unsigned char flag;
};
__declspec(thread) DebugLogFlag g_DebugLogFlag;
// Sets the return value to 0.0, optionally logs it when the debug log flag is set, and returns true.
// @fnv 0x005a3820
bool __cdecl FUN_005a3820(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (g_DebugLogFlag.flag)
        DebugLogStandIn::_DebugLog("IsPS3 >> %1.0f", *afReturnValue);
    return true;
}
}  // namespace fnv_005a3820

struct TESObjectREFR_Dismembered : TESObjectREFR
{
    bool IsLimbMissing(int limb);
};

// Sets result to 1.0 if reference is an actor whose limb is dismembered, otherwise 0.0, and returns true.
// @fnv 0x005a3db0
bool __cdecl FUN_005a3db0(TESObjectREFR* reference, void* aiLimb, void* apUnused, double& result)
{
    result = 0.0;
    int limb = reinterpret_cast<int>(aiLimb);
    if (reference && reference->IsActor())
    {
        TESObjectREFR_Dismembered* actor = static_cast<TESObjectREFR_Dismembered*>(reference);
        if (actor->IsLimbMissing(limb))
            result = 1.0;
    }
    return true;
}

struct FUN_005a4160_shell
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
    virtual bool v100();
    unsigned int GetActorStateFlags() const;
};

// @fnv 0x005a4160
bool FUN_005a4160(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference && ((FUN_005a4160_shell*)reference)->v100())
    {
        unsigned int mode = ((FUN_005a4160_shell*)reference)->GetActorStateFlags() & 0x30;
        if (mode & 0x10)
            result = 1.0;
        else if (mode & 0x20)
            result = 2.0;
    }
    return true;
}

struct AnimActionVirtual
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
    virtual bool IsMoving();
};

struct AnimActionObject
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
    virtual bool IsMoving();
    int GetAnimAction();
};

// Sets result to -1.0, then if reference is non-null and IsMoving() is true, stores GetAnimAction() into result; returns true.
// @fnv 0x005a41c0
bool __cdecl FUN_005a41c0(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = -1.0;
    if (reference && reinterpret_cast<AnimActionObject*>(reference)->IsMoving())
    {
        result = reinterpret_cast<AnimActionObject*>(reference)->GetAnimAction();
    }
    return true;
}

namespace fnv_005a48a0 {
extern "C" void _DebugLog(const char*, ...);
struct PlayerCharacterStandIn
{
    unsigned int GetFieldD68() const;
};
extern PlayerCharacterStandIn* _g_thePlayer;

__declspec(thread) bool g_bDebugLoggingEnabled = false;

// Stores the player's teammate count into result, optionally logs it, and returns true.
// @fnv 0x005a48a0
bool FUN_005a48a0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    result = _g_thePlayer->GetFieldD68();
    if (g_bDebugLoggingEnabled)
        _DebugLog("Player teammate count  >> %d", (int)result);
    return true;
}
}  // namespace fnv_005a48a0

struct FUN_00477430
{
    static int GetDestructionStageIndex(TESObjectREFR*);
};
void __cdecl _DebugLog(const char* fmt, ...);
__declspec(thread) bool g_DebugFlag;
// @fnv 0x005a4c60
bool __cdecl FUN_005a4c60(TESObjectREFR* ref, void* apUnused1, void* apUnused2, double& afDestructionStage)
{
    afDestructionStage = -1.0;
    if (ref)
        afDestructionStage = (double)FUN_00477430::GetDestructionStageIndex(ref);
    if (g_DebugFlag)
        _DebugLog("GetDestructionStage >> %.2f", afDestructionStage);
    return true;
}

namespace fnv_005a57b0 {
extern "C" void __cdecl _DebugLog(const char* apFormat, ...);

struct FUN_008bdbd0
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
    double GetAngleToReference(TESObjectREFR* apRef, float afAngle);
};

__declspec(thread) unsigned char g_tlsFlag;

struct ActorStandIn
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
    virtual bool IsEssentialActor();
};

// @fnv 0x005a57b0
bool __cdecl FUN_005a57b0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESObjectREFR* ptargetRef = (TESObjectREFR*)apParam1;
    if (apRefObject && ((ActorStandIn*)apRefObject)->IsEssentialActor())
    {
        afReturnValue = ((FUN_008bdbd0*)apRefObject)->GetAngleToReference(ptargetRef, 3.1415927410125732f);
    }
    if (g_tlsFlag)
        _DebugLog("VATSBackTargetVisible >> %.2f", afReturnValue);
    return true;
}
}  // namespace fnv_005a57b0

namespace fnv_005a5840 {
extern "C" void __cdecl _DebugLog(const char* fmt, ...);
struct VATSActor
{
    double __thiscall FUN_008bdbd0(TESObjectREFR* ref, float value);
    virtual bool v000();
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
    virtual bool v100();
};
__declspec(thread) bool g_debugFlag = false;
// Resets result to 0, computes it from ref's VATS visibility check against arg1 when ref is valid, logs it if g_debugFlag is set, and returns true.
// @fnv 0x005a5840
bool __cdecl FUN_005a5840(TESObjectREFR* ref, void* pTarget, void* pUnused, double& result)
{
    result = 0.0;
    TESObjectREFR* target = (TESObjectREFR*)pTarget;
    if (ref && ((VATSActor*)ref)->v100())
        result = ((VATSActor*)ref)->FUN_008bdbd0(target, 0.0f);
    if (g_debugFlag)
        _DebugLog("VATSFrontTargetVisible >> %.2f", result);
    return true;
}
}  // namespace fnv_005a5840

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011df7f8;
void __cdecl _DebugLog(const char* format, ...);
extern __declspec(thread) bool _tlsDebugLogEnabled;
// Sets result to 1.0 when the global bool is 1, logs it if debug logging is enabled, and returns true.
// @fnv 0x005a5a50
bool __cdecl FUN_005a5a50(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (*g_011df7f8.Bool() == 1)
        result = 1.0;
    if (_tlsDebugLogEnabled)
        _DebugLog("IsGoreDisabled >> %0.2f", result);
    return true;
}

namespace fnv_005a5b30 {
struct FUN_005a5bb0Class
{
    unsigned char FUN_005a5bb0();
};
struct MobileObjectShell
{
    const char* GetFullName();
};
void _DebugLog(const char* fmt, ...);
__declspec(thread) unsigned char g_tlsDebugLogEnabled;
// If apRefObject is an actor, stores its force-hit-reaction value in afReturnValue and optionally logs the actor's full name and value; returns true.
// @fnv 0x005a5b30
bool __cdecl GetForceHitReactionCondition(TESObjectREFR* apRefObject, void* apParam1, void* apParam2,
                                          double& afReturnValue)
{
    if (apRefObject && apRefObject->IsActor())
    {
        afReturnValue = (double)((FUN_005a5bb0Class*)apRefObject)->FUN_005a5bb0();
        if (g_tlsDebugLogEnabled)
            _DebugLog("GetForceHitReactionConditionFunction: %s >> %0.2f",
                      ((MobileObjectShell*)apRefObject)->GetFullName(), afReturnValue);
    }
    return true;
}
}  // namespace fnv_005a5b30

namespace fnv_005a5ff0 {
struct FUN_005a6050
{
    unsigned char GetField();
};
extern FUN_005a6050* _g_thePlayer;
void _DebugLog(const char*, ...);
__declspec(thread) unsigned char g_tlsFlag;

// Stores the player's field value into result, logs it when the TLS flag is set, and returns true.
// @fnv 0x005a5ff0
bool __cdecl FUN_005a5ff0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    if (_g_thePlayer)
        result = _g_thePlayer->GetField();
    if (g_tlsFlag)
        _DebugLog("GetAlwaysHardcore? >> %f", result);
    return true;
}
}  // namespace fnv_005a5ff0

struct TESChallenge
{
    int GetUnlocked();
};
void __cdecl DebugLog(const char*, ...);
__declspec(thread) bool g_bDebugLoggingEnabled;
// Reads the unlocked value from the TESChallenge in arg1 into result, logs it when debug logging is enabled, and returns true.
// @fnv 0x005a6070
bool __cdecl GetChallengeUnlockedValue(TESObjectREFR* reference, void* pChallenge, void* pUnused, double& result)
{
    TESChallenge* challenge = static_cast<TESChallenge*>(pChallenge);
    if (challenge)
    {
        int value = challenge->GetUnlocked();
        result = value;
    }
    if (g_bDebugLoggingEnabled)
        DebugLog("ChallengeLocked? >> %f", result);
    return true;
}

namespace fnv_005a60f0 {
struct TESChallenge
{
    unsigned int GetCompleted();
};

__declspec(thread) unsigned char g_tlsFlag[0x269];

extern "C" void _DebugLog(const char* fmt, ...);

// Reads the challenge's completed count into result when a challenge is given, logs it if the TLS flag is set, and returns true.
// @fnv 0x005a60f0
bool __cdecl FUN_005a60f0(TESObjectREFR* reference, void* pChallenge, void* pUnused, double& result)
{
    TESChallenge* challenge = static_cast<TESChallenge*>(pChallenge);
    if (challenge)
    {
        int completed = challenge->GetCompleted();
        result = completed;
    }
    if (g_tlsFlag[0x268])
    {
        _DebugLog("ChallengeComplete? >> %f", result);
    }
    return true;
}
}  // namespace fnv_005a60f0

namespace fnv_0059dbe0 {
extern "C" void __cdecl _DebugLog(const char*, ...);
extern "C" void* __cdecl _ref_004839c0(int);
struct InventoryChanges
{
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    int GetObjectCount(TESForm*);
};
struct TESContainer;
TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
__declspec(thread) unsigned char g_sDebugLogState[0x268 + 1];
// Sets result to the reference's inventory count of form 15 (gold), logs it when debug logging is on, and returns true.
// @fnv 0x0059dbe0
bool FUN_0059dbe0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    TESObjectREFR* ptarget = reference;
    TESForm* pform = (TESForm*)_ref_004839c0(15);
    if (ptarget && pform)
    {
        TESForm* pobject = pform;
        TESContainer* pCont = FUN_0055d310(ptarget);
        if (pCont)
        {
            InventoryChanges* pchange = InventoryChanges::CreateForReference(ptarget);
            if (pchange)
            {
                result = (double)pchange->GetObjectCount(pobject);
            }
        }
    }
    if (g_sDebugLogState[0x268])
        _DebugLog("GetGold >> %0.2f", result);
    return true;
}
}  // namespace fnv_0059dbe0

namespace fnv_005a2af0 {
struct ActorServiceStandIn
{
    bool FUN_008ac680();
};

struct MobileObjectShell : public TESObjectREFR
{
    const char* GetFullName();
};

void __cdecl _DebugLog(const char*, ...);
extern __declspec(thread) bool g_bDebugLogEnabled;

// Sets result to 1.0 if reference is an actor that is offering services, logs the outcome when debug logging is enabled, and returns true.
// @fnv 0x005a2af0
bool __cdecl FUN_005a2af0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    ActorServiceStandIn* actor = 0;
    if (reference && reference->IsActor())
        actor = reinterpret_cast<ActorServiceStandIn*>(reference);
    if (actor && actor->FUN_008ac680())
        result = 1.0;
    if (g_bDebugLogEnabled)
    {
        if (result != 0.0)
            _DebugLog("%s  is offering services", reinterpret_cast<MobileObjectShell*>(actor)->GetFullName());
        else
            _DebugLog("%s is not offering services", reinterpret_cast<MobileObjectShell*>(actor)->GetFullName());
    }
    return true;
}
}  // namespace fnv_005a2af0

namespace fnv_005a30c0 {
struct FUN_00422640Class
{
    int FUN_00422640();
};

struct FUN_005a30c0_tls
{
    unsigned char padding[0x268];
    unsigned char bDebug;
};

extern __declspec(thread) FUN_005a30c0_tls FUN_005a30c0_tlsVar;
extern "C" void __cdecl _DebugLog(const char*, ...);
const char* __cdecl GetFullName(void* form);

// Stores the actor's hit count from its extra data into result and, in debug mode, logs the player, actor and count.
// @fnv 0x005a30c0
bool __cdecl FUN_005a30c0(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& adHitCount)
{
    adHitCount = 0.0;
    Actor* actor = 0;
    if (reference && reference->IsActor())
        actor = (Actor*)reference;
    if (!actor)
        return true;
    adHitCount = (double)((FUN_00422640Class*)((TESObjectREFR*)actor)->GetExtraData())->FUN_00422640();
    if (FUN_005a30c0_tlsVar.bDebug)
        _DebugLog("%s has hit %s %0.2f times", GetFullName(g_thePlayer), GetFullName(actor), adHitCount);
    return true;
}
}  // namespace fnv_005a30c0

struct FUN_0059c4c0_VTable
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual void f76() = 0;
    virtual void f77() = 0;
    virtual void f78() = 0;
    virtual void f79() = 0;
    virtual void f80() = 0;
    virtual void f81() = 0;
    virtual void f82() = 0;
    virtual void f83() = 0;
    virtual void f84() = 0;
    virtual void f85() = 0;
    virtual void f86() = 0;
    virtual void f87() = 0;
    virtual void f88() = 0;
    virtual void f89() = 0;
    virtual void f90() = 0;
    virtual void f91() = 0;
    virtual void f92() = 0;
    virtual void f93() = 0;
    virtual void f94() = 0;
    virtual void f95() = 0;
    virtual void f96() = 0;
    virtual void f97() = 0;
    virtual void f98() = 0;
    virtual void f99() = 0;
    virtual void f100() = 0;
    virtual void f101() = 0;
    virtual void f102() = 0;
    virtual void f103() = 0;
    virtual void f104() = 0;
    virtual void f105() = 0;
    virtual void f106() = 0;
    virtual void f107() = 0;
    virtual void f108() = 0;
    virtual void f109() = 0;
    virtual void f110() = 0;
    virtual void f111() = 0;
    virtual void f112() = 0;
    virtual void f113() = 0;
    virtual void f114() = 0;
    virtual void f115() = 0;
    virtual int f116() = 0;
};

// Sets result to 0.0, then to 1.0 if reference is non-null and its virtual f116 returns nonzero; always returns true.
// @fnv 0x0059c4c0
bool __cdecl FUN_0059c4c0(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (reference && reinterpret_cast<FUN_0059c4c0_VTable*>(reference)->f116())
        result = 1.0;
    return true;
}

extern int __tls_index;
extern char const* __cdecl GetActorValueName(unsigned int);
extern void __cdecl _DebugLog(char const*, ...);

struct FUN_0059c5d0_RefInterface
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual bool f64() = 0;
};

struct FUN_0059c5d0_ActorValueInterface
{
    virtual int GetBaseActorValue(int) = 0;
};

struct FUN_0059c5d0_TLSData
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

extern __declspec(thread) FUN_0059c5d0_TLSData FUN_0059c5d0_TLSData;

// If apRefObject is an actor, stores its base actor value for the given index in afReturnValue and logs it when TLS logging is enabled; returns true.
// @fnv 0x0059c5d0
bool __cdecl FUN_0059c5d0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int iActorValueIndex = reinterpret_cast<unsigned int>(apParam1);
    Actor* pActor = 0;

    if (apRefObject && reinterpret_cast<FUN_0059c5d0_RefInterface*>(apRefObject)->f64())
        pActor = reinterpret_cast<Actor*>(apRefObject);

    if (pActor)
    {
        afReturnValue =
            reinterpret_cast<FUN_0059c5d0_ActorValueInterface*>(reinterpret_cast<unsigned char*>(pActor) + 0xa4)
                ->GetBaseActorValue(iActorValueIndex);

        if (FUN_0059c5d0_TLSData.enabled)
            _DebugLog("GetBaseActorValue: %s >> %0.2f", GetActorValueName(iActorValueIndex), afReturnValue);
    }

    return true;
}

struct FUN_0059c760_proxy
{
    virtual void FUN_00()
    {}
    virtual void FUN_01()
    {}
    virtual void FUN_02()
    {}
    virtual void FUN_03()
    {}
    virtual void FUN_04()
    {}
    virtual void FUN_05()
    {}
    virtual void FUN_06()
    {}
    virtual void FUN_07()
    {}
    virtual void FUN_08()
    {}
    virtual void FUN_09()
    {}
    virtual void FUN_0a()
    {}
    virtual void FUN_0b()
    {}
    virtual void FUN_0c()
    {}
    virtual void FUN_0d()
    {}
    virtual void FUN_0e()
    {}
    virtual void FUN_0f()
    {}
    virtual void FUN_10()
    {}
    virtual void FUN_11()
    {}
    virtual void FUN_12()
    {}
    virtual void FUN_13()
    {}
    virtual void FUN_14()
    {}
    virtual void FUN_15()
    {}
    virtual void FUN_16()
    {}
    virtual void FUN_17()
    {}
    virtual void FUN_18()
    {}
    virtual void FUN_19()
    {}
    virtual void FUN_1a()
    {}
    virtual void FUN_1b()
    {}
    virtual void FUN_1c()
    {}
    virtual void FUN_1d()
    {}
    virtual void FUN_1e()
    {}
    virtual void FUN_1f()
    {}
    virtual void FUN_20()
    {}
    virtual void FUN_21()
    {}
    virtual void FUN_22()
    {}
    virtual void FUN_23()
    {}
    virtual void FUN_24()
    {}
    virtual void FUN_25()
    {}
    virtual void FUN_26()
    {}
    virtual void FUN_27()
    {}
    virtual void FUN_28()
    {}
    virtual void FUN_29()
    {}
    virtual void FUN_2a()
    {}
    virtual void FUN_2b()
    {}
    virtual void FUN_2c()
    {}
    virtual void FUN_2d()
    {}
    virtual void FUN_2e()
    {}
    virtual void FUN_2f()
    {}
    virtual void FUN_30()
    {}
    virtual void FUN_31()
    {}
    virtual void FUN_32()
    {}
    virtual void FUN_33()
    {}
    virtual void FUN_34()
    {}
    virtual void FUN_35()
    {}
    virtual void FUN_36()
    {}
    virtual void FUN_37()
    {}
    virtual void FUN_38()
    {}
    virtual void FUN_39()
    {}
    virtual void FUN_3a()
    {}
    virtual void FUN_3b()
    {}
    virtual void FUN_3c()
    {}
    virtual void FUN_3d()
    {}
    virtual void FUN_3e()
    {}
    virtual void FUN_3f()
    {}
    virtual bool FUN_40()
    {
        return false;
    }
};

struct FUN_00893530_shell
{
    float GetFatigueRatio();
};

struct FUN_0059c760_tls
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

void __cdecl _DebugLog(const char* format, ...);
extern int __tls_index;
__declspec(thread) FUN_0059c760_tls DAT_0059c760_tls;

// If apRefObject is an Actor, stores its fatigue percentage in afReturnValue and logs it when TLS logging is enabled; returns true.
// @fnv 0x0059c760
bool __cdecl FUN_0059c760(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pActor;

    pActor = 0;
    if (apRefObject && ((FUN_0059c760_proxy*)apRefObject)->FUN_40())
        pActor = (Actor*)apRefObject;

    if (pActor)
    {
        afReturnValue = ((FUN_00893530_shell*)pActor)->GetFatigueRatio();
        if (DAT_0059c760_tls.enabled)
            _DebugLog("GetFatiguePercentage >> %0.2f", afReturnValue);
    }

    return true;
}

namespace fnv_0059c860 {
extern unsigned int __tls_index;

void __cdecl _DebugLog(const char* format, ...);

struct FUN_0059c860_VirtualHelper
{
    virtual bool f000()
    {
        return false;
    }
    virtual bool f001()
    {
        return false;
    }
    virtual bool f002()
    {
        return false;
    }
    virtual bool f003()
    {
        return false;
    }
    virtual bool f004()
    {
        return false;
    }
    virtual bool f005()
    {
        return false;
    }
    virtual bool f006()
    {
        return false;
    }
    virtual bool f007()
    {
        return false;
    }
    virtual bool f008()
    {
        return false;
    }
    virtual bool f009()
    {
        return false;
    }
    virtual bool f010()
    {
        return false;
    }
    virtual bool f011()
    {
        return false;
    }
    virtual bool f012()
    {
        return false;
    }
    virtual bool f013()
    {
        return false;
    }
    virtual bool f014()
    {
        return false;
    }
    virtual bool f015()
    {
        return false;
    }
    virtual bool f016()
    {
        return false;
    }
    virtual bool f017()
    {
        return false;
    }
    virtual bool f018()
    {
        return false;
    }
    virtual bool f019()
    {
        return false;
    }
    virtual bool f020()
    {
        return false;
    }
    virtual bool f021()
    {
        return false;
    }
    virtual bool f022()
    {
        return false;
    }
    virtual bool f023()
    {
        return false;
    }
    virtual bool f024()
    {
        return false;
    }
    virtual bool f025()
    {
        return false;
    }
    virtual bool f026()
    {
        return false;
    }
    virtual bool f027()
    {
        return false;
    }
    virtual bool f028()
    {
        return false;
    }
    virtual bool f029()
    {
        return false;
    }
    virtual bool f030()
    {
        return false;
    }
    virtual bool f031()
    {
        return false;
    }
    virtual bool f032()
    {
        return false;
    }
    virtual bool f033()
    {
        return false;
    }
    virtual bool f034()
    {
        return false;
    }
    virtual bool f035()
    {
        return false;
    }
    virtual bool f036()
    {
        return false;
    }
    virtual bool f037()
    {
        return false;
    }
    virtual bool f038()
    {
        return false;
    }
    virtual bool f039()
    {
        return false;
    }
    virtual bool f040()
    {
        return false;
    }
    virtual bool f041()
    {
        return false;
    }
    virtual bool f042()
    {
        return false;
    }
    virtual bool f043()
    {
        return false;
    }
    virtual bool f044()
    {
        return false;
    }
    virtual bool f045()
    {
        return false;
    }
    virtual bool f046()
    {
        return false;
    }
    virtual bool f047()
    {
        return false;
    }
    virtual bool f048()
    {
        return false;
    }
    virtual bool f049()
    {
        return false;
    }
    virtual bool f050()
    {
        return false;
    }
    virtual bool f051()
    {
        return false;
    }
    virtual bool f052()
    {
        return false;
    }
    virtual bool f053()
    {
        return false;
    }
    virtual bool f054()
    {
        return false;
    }
    virtual bool f055()
    {
        return false;
    }
    virtual bool f056()
    {
        return false;
    }
    virtual bool f057()
    {
        return false;
    }
    virtual bool f058()
    {
        return false;
    }
    virtual bool f059()
    {
        return false;
    }
    virtual bool f060()
    {
        return false;
    }
    virtual bool f061()
    {
        return false;
    }
    virtual bool f062()
    {
        return false;
    }
    virtual bool f063()
    {
        return false;
    }
    virtual bool f064()
    {
        return true;
    }
};

struct FUN_0059c860_ActorHelper
{
    float FUN_00884dc0();
};

struct FUN_0059c860_TLSData
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

static __declspec(thread) FUN_0059c860_TLSData DAT_0059c864;

// If reference is an Actor, stores its walk speed in result and optionally logs it via _DebugLog; always returns true.
// @fnv 0x0059c860
bool __cdecl FUN_0059c860(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    Actor* pActor = 0;

    if (reference)
    {
        if (reinterpret_cast<FUN_0059c860_VirtualHelper*>(reference)->f064())
        {
            pActor = reinterpret_cast<Actor*>(reference);
        }
    }

    if (pActor)
    {
        result = reinterpret_cast<FUN_0059c860_ActorHelper*>(pActor)->FUN_00884dc0();

        if (DAT_0059c864.enabled)
        {
            _DebugLog("GetWalkSpeed >> %0.2f", result);
        }
    }

    return true;
}
}  // namespace fnv_0059c860

namespace fnv_0059d100 {
struct TESObject
{
    unsigned int GetNext();
    unsigned int _FNV_GetFormType();
};

struct LockExtraData
{
    int GetLevel(TESObjectREFR* reference);
};

struct FUN_00501270_shell
{
    int FUN_005011a0(TESObjectREFR* reference);
};

struct P01TermA : public FUN_00501270_shell
{
    bool FUN_00501ae0(TESObjectREFR* reference);
};

typedef P01TermA BGSTerminal;

struct P01RefA
{
    LockExtraData* GetLock();
};

void __cdecl _DebugLog(const char* format, ...);

extern unsigned int __tls_index;

// Declares the thread-local data block for this function, with a byte flag at offset 0x268.
// @fnv 0x0059d100
__declspec(thread) struct FUN_0059d100_TLS_DATA
{
    unsigned char padding[0x268];
    unsigned char enabled;
} FUN_0059d100_tls_data;

bool __cdecl FUN_0059d100(TESObjectREFR* reference, void* param1, void* param2, double& result)
{
    LockExtraData* pLock;

    result = 0.0;

    if (reference != 0)
    {
        pLock = reinterpret_cast<P01RefA*>(reference)->GetLock();
        if (pLock != 0)
        {
            result = pLock->GetLevel(reference);
        }
        else
        {
            BGSTerminal* pterminal;

            if (reinterpret_cast<TESObject*>(reinterpret_cast<TESObject*>(reference)->GetNext())->_FNV_GetFormType() ==
                0x17)
            {
                pterminal = reinterpret_cast<BGSTerminal*>(reinterpret_cast<TESObject*>(reference)->GetNext());

                if (pterminal->FUN_00501ae0(reference))
                {
                    result = -1.0;
                }
                else
                {
                    result = pterminal->FUN_005011a0(reference);
                }
            }
        }
    }

    if (FUN_0059d100_tls_data.enabled)
    {
        _DebugLog("GetLockLevel >> %0.f", result);
    }

    return true;
}
}  // namespace fnv_0059d100

extern PlayerCharacter* _g_thePlayer;
bool __cdecl FUN_0059d610(TESObjectREFR*, void*, void*, double&);

// @fnv 0x0059d3e0
bool __cdecl FUN_0059d3e0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    return FUN_0059d610(reference, _g_thePlayer, 0, result);
}

namespace fnv_0059d540 {
extern unsigned int __tls_index;

class TESObject;
class TESNPC;
class TESRace;

unsigned int __fastcall _FNV_GetFormType(TESObject* object);
void _DebugLog(const char* format, double value);

class TESObject
{
  public:
    TESObject* GetNext();
};

struct FUN_004ac110_shell
{
    TESRace* FUN_004ac110();
};

struct TESNPC : public FUN_004ac110_shell
{
};

__declspec(thread) bool bDebug;

// Sets afReturnValue to 1.0 when both references resolve to TESNPCs sharing the same race, otherwise 0.0, and logs the result if bDebug is set.
// @fnv 0x0059d540
bool __cdecl FUN_0059d540(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;

    TESNPC* pnpc1 = 0;
    if (apRefObject && _FNV_GetFormType(reinterpret_cast<TESObject*>(apRefObject)->GetNext()) == 0x2a)
    {
        pnpc1 = reinterpret_cast<TESNPC*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext());
    }

    TESNPC* pnpc2 = 0;
    if (apParam1 && _FNV_GetFormType(reinterpret_cast<TESObject*>(apParam1)->GetNext()) == 0x2a)
    {
        pnpc2 = reinterpret_cast<TESNPC*>(reinterpret_cast<TESObject*>(apParam1)->GetNext());
    }

    if (pnpc1 && pnpc2 && pnpc1->FUN_004ac110() == pnpc2->FUN_004ac110())
    {
        afReturnValue = 1.0;
    }

    if (bDebug)
    {
        _DebugLog("SameRace >> %0.2f", afReturnValue);
    }

    return true;
}
}  // namespace fnv_0059d540

namespace fnv_0059e510 {
class TESFaction;

class TESActorBaseData
{
  public:
    int GetFactionRank(TESFaction* faction, bool isPlayer);
};

class TESActorBasePrefix
{
  public:
    unsigned char padding[0x30];
};

class TESActorBase : public TESActorBasePrefix, public TESActorBaseData
{
};

class XActor
{
  public:
    virtual bool V00();
    virtual bool V01();
    virtual bool V02();
    virtual bool V03();
    virtual bool V04();
    virtual bool V05();
    virtual bool V06();
    virtual bool V07();
    virtual bool V08();
    virtual bool V09();
    virtual bool V10();
    virtual bool V11();
    virtual bool V12();
    virtual bool V13();
    virtual bool V14();
    virtual bool V15();
    virtual bool V16();
    virtual bool V17();
    virtual bool V18();
    virtual bool V19();
    virtual bool V20();
    virtual bool V21();
    virtual bool V22();
    virtual bool V23();
    virtual bool V24();
    virtual bool V25();
    virtual bool V26();
    virtual bool V27();
    virtual bool V28();
    virtual bool V29();
    virtual bool V30();
    virtual bool V31();
    virtual bool V32();
    virtual bool V33();
    virtual bool V34();
    virtual bool V35();
    virtual bool V36();
    virtual bool V37();
    virtual bool V38();
    virtual bool V39();
    virtual bool V40();
    virtual bool V41();
    virtual bool V42();
    virtual bool V43();
    virtual bool V44();
    virtual bool V45();
    virtual bool V46();
    virtual bool V47();
    virtual bool V48();
    virtual bool V49();
    virtual bool V50();
    virtual bool V51();
    virtual bool V52();
    virtual bool V53();
    virtual bool V54();
    virtual bool V55();
    virtual bool V56();
    virtual bool V57();
    virtual bool V58();
    virtual bool V59();
    virtual bool V60();
    virtual bool V61();
    virtual bool V62();
    virtual bool V63();
    virtual bool V64();

    void* GetActorBase();
};

struct FNV_GetFormType
{
    int _FNV_GetFormType();
};

void __cdecl _DebugLog(const char* format, ...);
extern unsigned int __tls_index;
extern __declspec(thread) unsigned char FUN_0059e510_tls[0x269];

// @fnv 0x0059e510
bool __cdecl FUN_0059e510(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int pactorbase1;
    Actor* pact;
    Actor* pactorbase2;
    TESFaction* pfac;
    Actor* pacttar;
    int irank1;
    TESActorBase* irank2;

    afReturnValue = 0.0;
    pactorbase2 = 0;

    if (apRefObject)
    {
        if (((XActor*)apRefObject)->V64())
            pactorbase2 = (Actor*)apRefObject;
    }

    pacttar = (Actor*)apParam2;

    if (!pactorbase2 || !pacttar)
        return true;

    pact = (Actor*)((XActor*)pactorbase2)->GetActorBase();
    irank2 = (TESActorBase*)((XActor*)pacttar)->GetActorBase();

    pfac = 0;
    if (apParam1 && ((FNV_GetFormType*)apParam1)->_FNV_GetFormType() == 8)
        pfac = (TESFaction*)apParam1;

    if (pact && irank2 && pfac)
    {
        irank1 = ((TESActorBase*)pact)->GetFactionRank(pfac, pactorbase2 == (Actor*)g_thePlayer);
        pactorbase1 = ((TESActorBase*)irank2)->GetFactionRank(pfac, pacttar == (Actor*)g_thePlayer);

        if (irank1 != -1 && pactorbase1 != -1)
            afReturnValue = (double)(irank1 - pactorbase1);
    }

    if (FUN_0059e510_tls[0x268])
        _DebugLog("GetFactionRankDifference >> %0.2f", afReturnValue);

    return true;
}
}  // namespace fnv_0059e510

namespace fnv_0059e650 {
extern unsigned int __tls_index;

extern int __cdecl _stricmp(const char* string1, const char* string2);

void __cdecl _DebugLog(const char* format, double value);

__declspec(thread) unsigned char FUN_0059e650_tls[0x269];

struct FUN_0059e650_VTableBase
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v0a() = 0;
    virtual void v0b() = 0;
    virtual void v0c() = 0;
    virtual void v0d() = 0;
    virtual void v0e() = 0;
    virtual void v0f() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v1a() = 0;
    virtual void v1b() = 0;
    virtual void v1c() = 0;
    virtual void v1d() = 0;
    virtual void v1e() = 0;
    virtual void v1f() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v2a() = 0;
    virtual void v2b() = 0;
    virtual void v2c() = 0;
    virtual void v2d() = 0;
    virtual void v2e() = 0;
    virtual void v2f() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v3a() = 0;
    virtual void v3b() = 0;
    virtual void v3c() = 0;
    virtual void v3d() = 0;
    virtual void v3e() = 0;
    virtual void v3f() = 0;
};

struct FUN_0059e650_Actor : FUN_0059e650_VTableBase
{
    virtual bool IsEssentialActor()
    {
        return true;
    }

    const char* __thiscall GetPackageTypeName();
};

// @fnv 0x0059e650
bool __cdecl FUN_0059e650(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pactor;

    afReturnValue = 0.0;
    pactor = 0;

    if (apRefObject && reinterpret_cast<FUN_0059e650_Actor*>(apRefObject)->IsEssentialActor())
    {
        pactor = reinterpret_cast<Actor*>(apRefObject);
    }

    if (pactor && reinterpret_cast<FUN_0059e650_Actor*>(pactor)->GetPackageTypeName() &&
        _stricmp(reinterpret_cast<FUN_0059e650_Actor*>(pactor)->GetPackageTypeName(), "Alarm") == 0)
    {
        afReturnValue = 1.0;
    }

    if (FUN_0059e650_tls[0x268])
    {
        _DebugLog("GetAlarmed >> %0.2f", afReturnValue);
    }

    return true;
}
}  // namespace fnv_0059e650

namespace fnv_0059ebb0 {
struct TESWeather
{
};

struct FUN_0059ebb0_TLS
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

__declspec(thread) FUN_0059ebb0_TLS FUN_0059ebb0_tls;

extern unsigned int __tls_index;

int __fastcall _FNV_GetFormType(TESObjectREFR* reference);
void __cdecl _DebugLog(const char* format, ...);

class BSAudio
{
  public:
    int GetAudioBackendData();
};

class Sky : public BSAudio
{
  public:
    static Sky* __cdecl GetInstance();
};

// Returns 1.0 in afReturnValue if apRefObject is a TESWeather matching the Sky instance's current weather, otherwise 0.0; logs the result when enabled.
// @fnv 0x0059ebb0
bool __cdecl FUN_0059ebb0(void* apParam1, TESObjectREFR* apRefObject, void* apParam2, double& afReturnValue)
{
    TESWeather* pweather;

    afReturnValue = 0.0;
    pweather = 0;

    if (apRefObject != 0 && _FNV_GetFormType(apRefObject) == 0x35)
    {
        pweather = reinterpret_cast<TESWeather*>(apRefObject);
    }

    if (pweather == reinterpret_cast<TESWeather*>(Sky::GetInstance()->GetAudioBackendData()))
    {
        afReturnValue = 1.0;
    }

    if (FUN_0059ebb0_tls.enabled)
    {
        _DebugLog("GetIsCurrentWeather >> %0.2f", afReturnValue);
    }

    return true;
}
}  // namespace fnv_0059ebb0

extern int __tls_index;
extern __declspec(thread) unsigned char DAT_0059ec30_tls[0x269];

void __cdecl _DebugLog(const char* format, ...);

struct FUN_0059ec30Base
{
    virtual bool b0()
    {
        return false;
    }
    virtual bool b1()
    {
        return false;
    }
    virtual bool b2()
    {
        return false;
    }
    virtual bool b3()
    {
        return false;
    }
    virtual bool b4()
    {
        return false;
    }
    virtual bool b5()
    {
        return false;
    }
    virtual bool b6()
    {
        return false;
    }
    virtual bool b7()
    {
        return false;
    }
    virtual bool b8()
    {
        return false;
    }
    virtual bool b9()
    {
        return false;
    }
    virtual bool b10()
    {
        return false;
    }
    virtual bool b11()
    {
        return false;
    }
    virtual bool b12()
    {
        return false;
    }
    virtual bool b13()
    {
        return false;
    }
    virtual bool b14()
    {
        return false;
    }
    virtual bool b15()
    {
        return false;
    }
    virtual bool b16()
    {
        return false;
    }
    virtual bool b17()
    {
        return false;
    }
    virtual bool b18()
    {
        return false;
    }
    virtual bool b19()
    {
        return false;
    }
    virtual bool b20()
    {
        return false;
    }
    virtual bool b21()
    {
        return false;
    }
    virtual bool b22()
    {
        return false;
    }
    virtual bool b23()
    {
        return false;
    }
    virtual bool b24()
    {
        return false;
    }
    virtual bool b25()
    {
        return false;
    }
    virtual bool b26()
    {
        return false;
    }
    virtual bool b27()
    {
        return false;
    }
    virtual bool b28()
    {
        return false;
    }
    virtual bool b29()
    {
        return false;
    }
    virtual bool b30()
    {
        return false;
    }
    virtual bool b31()
    {
        return false;
    }
    virtual bool b32()
    {
        return false;
    }
    virtual bool b33()
    {
        return false;
    }
    virtual bool b34()
    {
        return false;
    }
    virtual bool b35()
    {
        return false;
    }
    virtual bool b36()
    {
        return false;
    }
    virtual bool b37()
    {
        return false;
    }
    virtual bool b38()
    {
        return false;
    }
    virtual bool b39()
    {
        return false;
    }
    virtual bool b40()
    {
        return false;
    }
    virtual bool b41()
    {
        return false;
    }
    virtual bool b42()
    {
        return false;
    }
    virtual bool b43()
    {
        return false;
    }
    virtual bool b44()
    {
        return false;
    }
    virtual bool b45()
    {
        return false;
    }
    virtual bool b46()
    {
        return false;
    }
    virtual bool b47()
    {
        return false;
    }
    virtual bool b48()
    {
        return false;
    }
    virtual bool b49()
    {
        return false;
    }
    virtual bool b50()
    {
        return false;
    }
    virtual bool b51()
    {
        return false;
    }
    virtual bool b52()
    {
        return false;
    }
    virtual bool b53()
    {
        return false;
    }
    virtual bool b54()
    {
        return false;
    }
    virtual bool b55()
    {
        return false;
    }
    virtual bool b56()
    {
        return false;
    }
    virtual bool b57()
    {
        return false;
    }
    virtual bool b58()
    {
        return false;
    }
    virtual bool b59()
    {
        return false;
    }
    virtual bool b60()
    {
        return false;
    }
    virtual bool b61()
    {
        return false;
    }
    virtual bool b62()
    {
        return false;
    }
    virtual bool b63()
    {
        return false;
    }
};

struct FUN_0059ec30Actor : public FUN_0059ec30Base
{
    virtual bool d0()
    {
        return false;
    }
    virtual bool d1()
    {
        return false;
    }
    virtual bool d2()
    {
        return false;
    }
    virtual bool d3()
    {
        return false;
    }
    virtual bool d4()
    {
        return false;
    }
    virtual bool d5()
    {
        return false;
    }
    virtual bool d6()
    {
        return false;
    }
    virtual bool d7()
    {
        return false;
    }
    virtual bool d8()
    {
        return false;
    }
    virtual bool d9()
    {
        return false;
    }
    virtual bool d10()
    {
        return false;
    }
    virtual bool d11()
    {
        return false;
    }
    virtual bool d12()
    {
        return false;
    }
    virtual bool d13()
    {
        return false;
    }
    virtual bool d14()
    {
        return false;
    }
    virtual bool d15()
    {
        return false;
    }
    virtual bool d16()
    {
        return false;
    }
    virtual bool d17()
    {
        return false;
    }
    virtual bool d18()
    {
        return false;
    }
    virtual bool d19()
    {
        return false;
    }
    virtual bool d20()
    {
        return false;
    }
    virtual bool d21()
    {
        return false;
    }
    virtual bool d22()
    {
        return false;
    }
    virtual bool d23()
    {
        return false;
    }
    virtual bool d24()
    {
        return false;
    }
    virtual bool d25()
    {
        return false;
    }
    virtual bool d26()
    {
        return false;
    }
    virtual bool d27()
    {
        return false;
    }
    virtual bool d28()
    {
        return false;
    }
    virtual bool d29()
    {
        return false;
    }
    virtual bool d30()
    {
        return false;
    }
    virtual bool d31()
    {
        return false;
    }
    virtual bool d32()
    {
        return false;
    }
    virtual bool d33()
    {
        return false;
    }
    virtual bool d34()
    {
        return false;
    }
    virtual bool d35()
    {
        return false;
    }
    virtual bool d36()
    {
        return false;
    }
    virtual bool d37()
    {
        return false;
    }
    virtual bool d38()
    {
        return false;
    }
    virtual bool d39()
    {
        return false;
    }
    virtual bool d40()
    {
        return false;
    }
    virtual bool d41()
    {
        return false;
    }
    virtual bool d42()
    {
        return false;
    }
    virtual bool d43()
    {
        return false;
    }
    virtual bool d44()
    {
        return false;
    }
    virtual bool d45()
    {
        return false;
    }
    virtual bool d46()
    {
        return false;
    }
    virtual bool d47()
    {
        return false;
    }
    virtual bool d48()
    {
        return false;
    }
    virtual bool d49()
    {
        return false;
    }
    virtual bool d50()
    {
        return false;
    }
    virtual bool d51()
    {
        return false;
    }
    virtual bool d52()
    {
        return false;
    }
    virtual bool d53()
    {
        return false;
    }
    virtual bool d54()
    {
        return false;
    }
    virtual bool d55()
    {
        return false;
    }
    virtual bool d56()
    {
        return false;
    }
    virtual bool d57()
    {
        return false;
    }
    virtual bool d58()
    {
        return false;
    }
    virtual bool d59()
    {
        return false;
    }
    virtual bool d60()
    {
        return false;
    }
    virtual bool d61()
    {
        return false;
    }
    virtual bool d62()
    {
        return false;
    }
    virtual bool d63()
    {
        return false;
    }
    virtual bool d64()
    {
        return false;
    }
    virtual bool d65()
    {
        return false;
    }
    virtual bool d66()
    {
        return false;
    }
    virtual bool d67()
    {
        return false;
    }
    virtual bool d68()
    {
        return false;
    }
    virtual bool d69()
    {
        return false;
    }
    virtual bool d70()
    {
        return false;
    }
    virtual bool d71()
    {
        return false;
    }
    virtual bool d72()
    {
        return false;
    }
    virtual bool d73()
    {
        return false;
    }
    virtual bool d74()
    {
        return false;
    }
    virtual bool d75()
    {
        return false;
    }
    virtual bool d76()
    {
        return false;
    }
    virtual bool d77()
    {
        return false;
    }
    virtual bool d78()
    {
        return false;
    }
    virtual bool d79()
    {
        return false;
    }
    virtual bool d80()
    {
        return false;
    }
    virtual bool d81()
    {
        return false;
    }
    virtual bool d82()
    {
        return false;
    }
    virtual bool d83()
    {
        return false;
    }
    virtual bool d84()
    {
        return false;
    }
    virtual bool d85()
    {
        return false;
    }
    virtual bool d86()
    {
        return false;
    }
    virtual bool d87()
    {
        return false;
    }
    virtual bool d88()
    {
        return false;
    }
    virtual bool d89()
    {
        return false;
    }
    virtual bool d90()
    {
        return false;
    }
    virtual bool d91()
    {
        return false;
    }
    virtual bool d92()
    {
        return false;
    }
    virtual bool d93()
    {
        return false;
    }
    virtual bool d94()
    {
        return false;
    }
    virtual bool d95()
    {
        return false;
    }
    virtual bool d96()
    {
        return false;
    }
    virtual bool d97()
    {
        return false;
    }
    virtual bool d98()
    {
        return false;
    }
    virtual bool d99()
    {
        return false;
    }
    virtual bool d100()
    {
        return false;
    }
    virtual bool d101()
    {
        return false;
    }
    virtual bool d102()
    {
        return false;
    }
    virtual bool d103()
    {
        return false;
    }
    virtual bool d104()
    {
        return false;
    }
    virtual bool d105()
    {
        return false;
    }
    virtual bool d106()
    {
        return false;
    }
    virtual bool d107()
    {
        return false;
    }
    virtual bool d108()
    {
        return false;
    }
    virtual bool d109()
    {
        return false;
    }
    virtual bool d110()
    {
        return false;
    }
    virtual bool d111()
    {
        return false;
    }
    virtual bool d112()
    {
        return false;
    }
    virtual bool d113()
    {
        return false;
    }
    virtual bool d114()
    {
        return false;
    }
    virtual bool d115()
    {
        return false;
    }
    virtual bool d116()
    {
        return false;
    }
    virtual bool d117()
    {
        return false;
    }
    virtual bool d118()
    {
        return false;
    }
    virtual bool d119()
    {
        return false;
    }
    virtual bool d120()
    {
        return false;
    }
    virtual bool d121()
    {
        return false;
    }
    virtual bool d122()
    {
        return false;
    }
    virtual bool d123()
    {
        return false;
    }
    virtual bool d124()
    {
        return false;
    }
    virtual bool d125()
    {
        return false;
    }
    virtual bool d126()
    {
        return false;
    }
    virtual bool d127()
    {
        return false;
    }
    virtual bool d128()
    {
        return false;
    }
    virtual bool d129()
    {
        return false;
    }
    virtual bool d130()
    {
        return false;
    }
    virtual bool d131()
    {
        return false;
    }
    virtual bool d132()
    {
        return false;
    }
    virtual bool d133()
    {
        return false;
    }
    virtual bool d134()
    {
        return false;
    }
    virtual bool d135()
    {
        return false;
    }
    virtual bool d136()
    {
        return false;
    }
    virtual bool d137()
    {
        return false;
    }
    virtual bool d138()
    {
        return false;
    }
    virtual bool d139()
    {
        return false;
    }
    virtual bool d140()
    {
        return false;
    }
    virtual bool d141()
    {
        return false;
    }
    virtual bool d142()
    {
        return false;
    }
    virtual bool d143()
    {
        return false;
    }
    virtual bool d144()
    {
        return false;
    }
    virtual bool d145()
    {
        return false;
    }
    virtual bool d146()
    {
        return false;
    }
    virtual bool d147()
    {
        return false;
    }
    virtual bool d148()
    {
        return false;
    }
    virtual bool d149()
    {
        return false;
    }
    virtual bool d150()
    {
        return false;
    }
    virtual bool d151()
    {
        return false;
    }
    virtual bool d152()
    {
        return false;
    }
    virtual bool d153()
    {
        return false;
    }
    virtual bool d154()
    {
        return false;
    }
    virtual bool d155()
    {
        return false;
    }
    virtual bool d156()
    {
        return false;
    }
    virtual bool d157()
    {
        return false;
    }
    virtual bool d158()
    {
        return false;
    }
    virtual bool d159()
    {
        return false;
    }
    virtual bool d160()
    {
        return false;
    }
    virtual bool d161()
    {
        return false;
    }
    virtual bool d162()
    {
        return false;
    }
    virtual bool d163()
    {
        return false;
    }
    virtual bool d164()
    {
        return false;
    }
    virtual bool d165()
    {
        return false;
    }
    virtual bool d166()
    {
        return false;
    }
    virtual bool d167()
    {
        return false;
    }
    virtual bool d168()
    {
        return false;
    }
    virtual bool d169()
    {
        return false;
    }
    virtual bool d170()
    {
        return false;
    }
    virtual bool d171()
    {
        return false;
    }
    virtual bool d172()
    {
        return false;
    }
    virtual bool d173()
    {
        return false;
    }
    virtual bool d174()
    {
        return false;
    }
    virtual bool d175()
    {
        return false;
    }
    virtual bool d176()
    {
        return false;
    }
    virtual bool d177()
    {
        return false;
    }
    virtual bool d178()
    {
        return false;
    }
    virtual bool d179()
    {
        return false;
    }
    virtual bool d180()
    {
        return false;
    }
    virtual bool d181()
    {
        return false;
    }
    virtual bool d182()
    {
        return false;
    }
    virtual bool d183()
    {
        return false;
    }
    virtual bool d184()
    {
        return false;
    }
    virtual bool d185()
    {
        return false;
    }
    virtual bool d186()
    {
        return false;
    }
    virtual bool d187()
    {
        return false;
    }
    virtual bool d188()
    {
        return false;
    }
    virtual bool d189()
    {
        return false;
    }
    virtual bool d190()
    {
        return false;
    }
    virtual bool d191()
    {
        return false;
    }
    virtual bool d192()
    {
        return false;
    }
    virtual bool d193()
    {
        return false;
    }
    virtual bool d194()
    {
        return false;
    }
    virtual bool d195()
    {
        return false;
    }
    virtual bool d196()
    {
        return false;
    }
    virtual bool d197()
    {
        return false;
    }
    virtual bool d198()
    {
        return false;
    }
    virtual bool d199()
    {
        return false;
    }
    virtual bool d200()
    {
        return false;
    }
    virtual bool d201()
    {
        return false;
    }
    virtual bool d202()
    {
        return false;
    }
    virtual bool d203()
    {
        return false;
    }
    virtual bool d204()
    {
        return false;
    }
    virtual bool d205()
    {
        return false;
    }
    virtual bool d206()
    {
        return false;
    }
    virtual bool d207()
    {
        return false;
    }
    virtual bool d208()
    {
        return false;
    }
    virtual bool d209()
    {
        return false;
    }
    virtual bool d210()
    {
        return false;
    }
    virtual bool d211()
    {
        return false;
    }
    virtual bool d212()
    {
        return false;
    }
    virtual bool d213()
    {
        return false;
    }
    virtual bool d214()
    {
        return false;
    }
    virtual bool d215()
    {
        return false;
    }
    virtual bool d216()
    {
        return false;
    }
    virtual bool d217()
    {
        return false;
    }
    virtual bool d218()
    {
        return false;
    }
    virtual bool d219()
    {
        return false;
    }
    virtual bool d220()
    {
        return false;
    }
};

// If apRefObject is an actor, stores its d220() value into afReturnValue, optionally debug-logs it, and returns true.
// @fnv 0x0059ec30
bool __cdecl FUN_0059ec30(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pactor = 0;

    if (apRefObject && reinterpret_cast<FUN_0059ec30Actor*>(apRefObject)->d0())
    {
        pactor = reinterpret_cast<Actor*>(apRefObject);
    }

    if (pactor)
    {
        afReturnValue = reinterpret_cast<FUN_0059ec30Actor*>(pactor)->d220();
    }

    if (DAT_0059ec30_tls[0x268])
    {
        _DebugLog("GetAttacked >> %0.2f", afReturnValue);
    }

    return true;
}

namespace fnv_0059f180 {
extern unsigned int __tls_index;

__declspec(thread) unsigned char FUN_0059f180_tls[0x269];

class TESObject
{
  public:
    unsigned int __thiscall GetNext();
};

class TESActorBase
{
  public:
    TESClass* GetClass();
};

class TESNPC : public TESActorBase
{
};

unsigned int __fastcall _FNV_GetFormType(void* object);
void __cdecl _DebugLog(const char* format, double value);

// Sets afReturnValue to 1.0 when apRefObject's TESNPC has the same TESClass as apParam1, logs the result if TLS flag 0x268 is set, and returns true.
// @fnv 0x0059f180
bool __cdecl FUN_0059f180(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;

    TESNPC* pnpc = 0;
    if (apRefObject)
    {
        if (_FNV_GetFormType(reinterpret_cast<void*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext())) == 0x2a)
            pnpc = reinterpret_cast<TESNPC*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext());
    }

    TESClass* pclass = 0;
    if (apParam1)
    {
        if (_FNV_GetFormType(apParam1) == 7)
            pclass = reinterpret_cast<TESClass*>(apParam1);
    }

    if (pnpc && pclass && pnpc->GetClass() == pclass)
        afReturnValue = 1.0;

    if (FUN_0059f180_tls[0x268])
        _DebugLog("GetIsClass >> %0.2f", afReturnValue);

    return true;
}
}  // namespace fnv_0059f180

namespace fnv_0059f240 {
class TESRace
{
};

struct FUN_004ac110_shell
{
    TESRace* FUN_004ac110();
};

struct TESNPC : public FUN_004ac110_shell
{
};

class TESObject
{
  public:
    unsigned int GetNext();
};

unsigned int __fastcall _FNV_GetFormType(unsigned int formID);
void __cdecl _DebugLog(const char* format, ...);

struct FUN_0059f240_ThreadLocal
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

__declspec(thread) FUN_0059f240_ThreadLocal FUN_0059f240_ThreadLocalData;

// Sets afReturnValue to 1.0 if apRefObject's TESNPC race matches apParam1's TESRace, else 0.0, and logs the result when thread-local logging is enabled.
// @fnv 0x0059f240
bool __cdecl FUN_0059f240(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;

    TESNPC* pnpc = 0;
    if (apRefObject)
    {
        if (_FNV_GetFormType(reinterpret_cast<TESObject*>(apRefObject)->GetNext()) == 42)
            pnpc = reinterpret_cast<TESNPC*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext());
    }

    TESRace* prace = 0;
    if (apParam1)
    {
        if (_FNV_GetFormType(reinterpret_cast<unsigned int>(apParam1)) == 12)
            prace = static_cast<TESRace*>(apParam1);
    }

    if (pnpc)
    {
        if (prace)
        {
            if (pnpc->FUN_004ac110() == prace)
                afReturnValue = 1.0;
        }
    }

    if (FUN_0059f240_ThreadLocalData.enabled)
        _DebugLog("GetIsRace >> %0.2f", afReturnValue);

    return true;
}
}  // namespace fnv_0059f240

namespace fnv_0059f300 {
extern unsigned int __tls_index;
extern int __fastcall _FNV_GetFormType(unsigned int form);
extern void __cdecl _DebugLog(const char* format, double value);

struct TESObject
{
    unsigned int GetNext();
};

struct TESCreature
{
    signed char GetCreatureType() const;
};

extern __declspec(thread) unsigned char g_bDebugLog;

// Sets afReturnValue to 1.0 if apRefObject's next form is a creature whose creature type equals apParam1, else 0.0, and logs the result when g_bDebugLog is set.
// @fnv 0x0059f300
bool __cdecl FUN_0059f300(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    TESCreature* pcreature;
    int iCreatureType;

    afReturnValue = 0.0;
    pcreature = 0;

    if (apRefObject)
    {
        if (_FNV_GetFormType(((TESObject*)apRefObject)->GetNext()) == 0x2b)
        {
            pcreature = (TESCreature*)((TESObject*)apRefObject)->GetNext();
        }
    }

    iCreatureType = (int)apParam1;

    if (pcreature && pcreature->GetCreatureType() == iCreatureType)
    {
        afReturnValue = 1.0;
    }

    if (g_bDebugLog)
    {
        _DebugLog("GetIsCreatureType >> %0.2f", afReturnValue);
    }

    return true;
}
}  // namespace fnv_0059f300

extern int __tls_index;
extern __declspec(thread) unsigned char FUN_tls_debug[0x269];

struct ActorGetAlertHelper
{
    bool IsCurrentlyAlerted();
};

struct TESObjectREFRVirtualHelper
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual bool GetBlockPostAnim() = 0;
};

void __cdecl _DebugLog(const char* format, double value);

// @fnv 0x005a0260
bool __cdecl FUN_005a0260(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;

    Actor* pactor = 0;

    if (apRefObject && ((TESObjectREFRVirtualHelper*)apRefObject)->GetBlockPostAnim())
    {
        pactor = (Actor*)apRefObject;
    }

    if (pactor)
    {
        afReturnValue = ((ActorGetAlertHelper*)pactor)->IsCurrentlyAlerted();

        if (FUN_tls_debug[0x268])
        {
            _DebugLog("GetIsAlerted: %0.2f", afReturnValue);
        }
    }

    return true;
}

namespace fnv_005a0710 {
class NiNode
{
  public:
    virtual ~NiNode();
};

class NiAVObject : public NiNode
{
  public:
    virtual ~NiAVObject();
};

class NiFixedString
{
};

class Model : public NiAVObject
{
};

class P09H
{
  public:
    NiAVObject* GetReferenceType();
};

struct FUN_00571550_shell
{
    Model* FUN_00571530(NiAVObject* object, NiFixedString* string);
};

struct TESObjectREFR_AnimationExt
{
    NiAVObject* FUN_00490310(NiNode* node, char const* string);
};

struct TLSData
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

__declspec(thread) TLSData g_tlsData;

NiFixedString* __cdecl FUN_005a07f0(void);
bool __cdecl FUN_00c6b7b0(NiAVObject* object, int unused);
void __cdecl _DebugLog(char const* format, double value);

// Sets result to 1.0 when the reference is an actor whose spine node is missing or passes FUN_00c6b7b0, logs it if TLS enabled, and returns true.
// @fnv 0x005a0710
bool FUN_005a0710(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    Actor* pactor;

    result = 0.0;
    pactor = 0;

    if (reference)
    {
        if (reference->IsActor())
            pactor = reinterpret_cast<Actor*>(reference);
    }

    if (pactor)
    {
        NiAVObject* proot;
        NiAVObject* p3d4;

        proot = reinterpret_cast<P09H*>(pactor)->GetReferenceType();
        p3d4 = reinterpret_cast<FUN_00571550_shell*>(pactor)->FUN_00571530(proot, FUN_005a07f0());

        if (!p3d4)
            p3d4 = reinterpret_cast<TESObjectREFR_AnimationExt*>(pactor)->FUN_00490310(proot, "Bip01 Spine01");

        if (!p3d4 || FUN_00c6b7b0(p3d4, 0))
            result = 1.0;
    }

    if (g_tlsData.enabled)
        _DebugLog("Is Facing Up >> %0.2f", result);

    return true;
}
}  // namespace fnv_005a0710

namespace fnv_005a0800 {
struct NiAVObject
{
};

struct Model : NiAVObject
{
};

struct NiFixedString
{
};

struct ActorVirtual
{
    virtual bool f00() = 0;
    virtual bool f01() = 0;
    virtual bool f02() = 0;
    virtual bool f03() = 0;
    virtual bool f04() = 0;
    virtual bool f05() = 0;
    virtual bool f06() = 0;
    virtual bool f07() = 0;
    virtual bool f08() = 0;
    virtual bool f09() = 0;
    virtual bool f10() = 0;
    virtual bool f11() = 0;
    virtual bool f12() = 0;
    virtual bool f13() = 0;
    virtual bool f14() = 0;
    virtual bool f15() = 0;
    virtual bool f16() = 0;
    virtual bool f17() = 0;
    virtual bool f18() = 0;
    virtual bool f19() = 0;
    virtual bool f20() = 0;
    virtual bool f21() = 0;
    virtual bool f22() = 0;
    virtual bool f23() = 0;
    virtual bool f24() = 0;
    virtual bool f25() = 0;
    virtual bool f26() = 0;
    virtual bool f27() = 0;
    virtual bool f28() = 0;
    virtual bool f29() = 0;
    virtual bool f30() = 0;
    virtual bool f31() = 0;
    virtual bool f32() = 0;
    virtual bool f33() = 0;
    virtual bool f34() = 0;
    virtual bool f35() = 0;
    virtual bool f36() = 0;
    virtual bool f37() = 0;
    virtual bool f38() = 0;
    virtual bool f39() = 0;
    virtual bool f40() = 0;
    virtual bool f41() = 0;
    virtual bool f42() = 0;
    virtual bool f43() = 0;
    virtual bool f44() = 0;
    virtual bool f45() = 0;
    virtual bool f46() = 0;
    virtual bool f47() = 0;
    virtual bool f48() = 0;
    virtual bool f49() = 0;
    virtual bool f50() = 0;
    virtual bool f51() = 0;
    virtual bool f52() = 0;
    virtual bool f53() = 0;
    virtual bool f54() = 0;
    virtual bool f55() = 0;
    virtual bool f56() = 0;
    virtual bool f57() = 0;
    virtual bool f58() = 0;
    virtual bool f59() = 0;
    virtual bool f60() = 0;
    virtual bool f61() = 0;
    virtual bool f62() = 0;
    virtual bool f63() = 0;
    virtual bool GetBlockPostAnim() = 0;
};

struct P09H : Actor
{
    int GetReferenceType();
};

struct FUN_00571550_shell : Actor
{
    Model* FUN_00571530(int, int);
};

NiFixedString* __cdecl FUN_005a07f0();
bool __cdecl FUN_00c6b860(Model*, int);
void __cdecl _DebugLog(const char*, ...);
extern int __tls_index;
extern __declspec(thread) bool g_bIsLeftUp;

// @fnv 0x005a0800
bool __cdecl FUN_005a0800(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int pactor;
    NiAVObject* proot;
    Actor* p3d;

    afReturnValue = 0.0;

    p3d = 0;
    if (apRefObject)
    {
        if (reinterpret_cast<ActorVirtual*>(apRefObject)->GetBlockPostAnim())
            p3d = reinterpret_cast<Actor*>(apRefObject);
    }

    if (p3d)
    {
        pactor = reinterpret_cast<P09H*>(p3d)->GetReferenceType();

        proot = reinterpret_cast<NiAVObject*>(
            reinterpret_cast<FUN_00571550_shell*>(p3d)->FUN_00571530(pactor, reinterpret_cast<int>(FUN_005a07f0())));

        if (!proot || FUN_00c6b860(reinterpret_cast<Model*>(proot), 0))
            afReturnValue = 1.0;
    }

    if (g_bIsLeftUp)
        _DebugLog("Is Left Up >> %0.2f", afReturnValue);

    return true;
}
}  // namespace fnv_005a0800

namespace fnv_005a09b0 {
class TESObjectWEAP
{
  public:
    int GetWeaponType(void);
};

class ArrSI
{
  public:
    TESObjectWEAP* GetFlags(void);
};

class InventoryStackRecord : public ArrSI
{
};

class TES
{
  public:
    virtual bool f00()
    {
        return false;
    }
    virtual bool f01()
    {
        return false;
    }
    virtual bool f02()
    {
        return false;
    }
    virtual bool f03()
    {
        return false;
    }
    virtual bool f04()
    {
        return false;
    }
    virtual bool f05()
    {
        return false;
    }
    virtual bool f06()
    {
        return false;
    }
    virtual bool f07()
    {
        return false;
    }
    virtual bool f08()
    {
        return false;
    }
    virtual bool f09()
    {
        return false;
    }
    virtual bool f10()
    {
        return false;
    }
    virtual bool f11()
    {
        return false;
    }
    virtual bool f12()
    {
        return false;
    }
    virtual bool f13()
    {
        return false;
    }
    virtual bool f14()
    {
        return false;
    }
    virtual bool f15()
    {
        return false;
    }
    virtual bool f16()
    {
        return false;
    }
    virtual bool f17()
    {
        return false;
    }
    virtual bool f18()
    {
        return false;
    }
    virtual bool f19()
    {
        return false;
    }
    virtual bool f20()
    {
        return false;
    }
    virtual bool f21()
    {
        return false;
    }
    virtual bool f22()
    {
        return false;
    }
    virtual bool f23()
    {
        return false;
    }
    virtual bool f24()
    {
        return false;
    }
    virtual bool f25()
    {
        return false;
    }
    virtual bool f26()
    {
        return false;
    }
    virtual bool f27()
    {
        return false;
    }
    virtual bool f28()
    {
        return false;
    }
    virtual bool f29()
    {
        return false;
    }
    virtual bool f30()
    {
        return false;
    }
    virtual bool f31()
    {
        return false;
    }
    virtual bool f32()
    {
        return false;
    }
    virtual bool f33()
    {
        return false;
    }
    virtual bool f34()
    {
        return false;
    }
    virtual bool f35()
    {
        return false;
    }
    virtual bool f36()
    {
        return false;
    }
    virtual bool f37()
    {
        return false;
    }
    virtual bool f38()
    {
        return false;
    }
    virtual bool f39()
    {
        return false;
    }
    virtual bool f40()
    {
        return false;
    }
    virtual bool f41()
    {
        return false;
    }
    virtual bool f42()
    {
        return false;
    }
    virtual bool f43()
    {
        return false;
    }
    virtual bool f44()
    {
        return false;
    }
    virtual bool f45()
    {
        return false;
    }
    virtual bool f46()
    {
        return false;
    }
    virtual bool f47()
    {
        return false;
    }
    virtual bool f48()
    {
        return false;
    }
    virtual bool f49()
    {
        return false;
    }
    virtual bool f50()
    {
        return false;
    }
    virtual bool f51()
    {
        return false;
    }
    virtual bool f52()
    {
        return false;
    }
    virtual bool f53()
    {
        return false;
    }
    virtual bool f54()
    {
        return false;
    }
    virtual bool f55()
    {
        return false;
    }
    virtual bool f56()
    {
        return false;
    }
    virtual bool f57()
    {
        return false;
    }
    virtual bool f58()
    {
        return false;
    }
    virtual bool f59()
    {
        return false;
    }
    virtual bool f60()
    {
        return false;
    }
    virtual bool f61()
    {
        return false;
    }
    virtual bool f62()
    {
        return false;
    }
    virtual bool f63()
    {
        return false;
    }
    virtual bool m_bFlagBeforeTwoBooleans()
    {
        return false;
    }

    void* GetLogDate(void);
};

class LogDate
{
  public:
    virtual int f00()
    {
        return 0;
    }
    virtual int f01()
    {
        return 0;
    }
    virtual int f02()
    {
        return 0;
    }
    virtual int f03()
    {
        return 0;
    }
    virtual int f04()
    {
        return 0;
    }
    virtual int f05()
    {
        return 0;
    }
    virtual int f06()
    {
        return 0;
    }
    virtual int f07()
    {
        return 0;
    }
    virtual int f08()
    {
        return 0;
    }
    virtual int f09()
    {
        return 0;
    }
    virtual int f10()
    {
        return 0;
    }
    virtual int f11()
    {
        return 0;
    }
    virtual int f12()
    {
        return 0;
    }
    virtual int f13()
    {
        return 0;
    }
    virtual int f14()
    {
        return 0;
    }
    virtual int f15()
    {
        return 0;
    }
    virtual int f16()
    {
        return 0;
    }
    virtual int f17()
    {
        return 0;
    }
    virtual int f18()
    {
        return 0;
    }
    virtual int f19()
    {
        return 0;
    }
    virtual int f20()
    {
        return 0;
    }
    virtual int f21()
    {
        return 0;
    }
    virtual int f22()
    {
        return 0;
    }
    virtual int f23()
    {
        return 0;
    }
    virtual int f24()
    {
        return 0;
    }
    virtual int f25()
    {
        return 0;
    }
    virtual int f26()
    {
        return 0;
    }
    virtual int f27()
    {
        return 0;
    }
    virtual int f28()
    {
        return 0;
    }
    virtual int f29()
    {
        return 0;
    }
    virtual int f30()
    {
        return 0;
    }
    virtual int f31()
    {
        return 0;
    }
    virtual int f32()
    {
        return 0;
    }
    virtual int f33()
    {
        return 0;
    }
    virtual int f34()
    {
        return 0;
    }
    virtual int f35()
    {
        return 0;
    }
    virtual int f36()
    {
        return 0;
    }
    virtual int f37()
    {
        return 0;
    }
    virtual int f38()
    {
        return 0;
    }
    virtual int f39()
    {
        return 0;
    }
    virtual int f40()
    {
        return 0;
    }
    virtual int f41()
    {
        return 0;
    }
    virtual int f42()
    {
        return 0;
    }
    virtual int f43()
    {
        return 0;
    }
    virtual int f44()
    {
        return 0;
    }
    virtual int f45()
    {
        return 0;
    }
    virtual int f46()
    {
        return 0;
    }
    virtual int f47()
    {
        return 0;
    }
    virtual int f48()
    {
        return 0;
    }
    virtual int f49()
    {
        return 0;
    }
    virtual int f50()
    {
        return 0;
    }
    virtual int f51()
    {
        return 0;
    }
    virtual int f52()
    {
        return 0;
    }
    virtual int f53()
    {
        return 0;
    }
    virtual int f54()
    {
        return 0;
    }
    virtual int f55()
    {
        return 0;
    }
    virtual int f56()
    {
        return 0;
    }
    virtual int f57()
    {
        return 0;
    }
    virtual int f58()
    {
        return 0;
    }
    virtual int f59()
    {
        return 0;
    }
    virtual int f60()
    {
        return 0;
    }
    virtual int f61()
    {
        return 0;
    }
    virtual int f62()
    {
        return 0;
    }
    virtual int f63()
    {
        return 0;
    }
    virtual int f64()
    {
        return 0;
    }
    virtual int f65()
    {
        return 0;
    }
    virtual int f66()
    {
        return 0;
    }
    virtual int f67()
    {
        return 0;
    }
    virtual int f68()
    {
        return 0;
    }
    virtual int f69()
    {
        return 0;
    }
    virtual int f70()
    {
        return 0;
    }
    virtual int f71()
    {
        return 0;
    }
    virtual int f72()
    {
        return 0;
    }
    virtual int f73()
    {
        return 0;
    }
    virtual int f74()
    {
        return 0;
    }
    virtual int f75()
    {
        return 0;
    }
    virtual int f76()
    {
        return 0;
    }
    virtual int f77()
    {
        return 0;
    }
    virtual int f78()
    {
        return 0;
    }
    virtual int f79()
    {
        return 0;
    }
    virtual int f80()
    {
        return 0;
    }
    virtual int f81()
    {
        return 0;
    }
    virtual ArrSI* GetItemChange()
    {
        return 0;
    }
};

int __fastcall _FNV_GetFormType(TESObjectWEAP* object);
void __cdecl _DebugLog(const char* format, ...);

extern int DAT_0118a838[];
extern int __tls_index;
extern __declspec(thread) unsigned char DAT_tls_data[0x269];

// @fnv 0x005a09b0
bool __cdecl FUN_005a09b0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pactor;
    InventoryStackRecord* pweapdata;
    TESObjectWEAP* pweap;

    afReturnValue = 0.0;
    pactor = 0;

    if (apRefObject && reinterpret_cast<TES*>(apRefObject)->m_bFlagBeforeTwoBooleans())
    {
        pactor = reinterpret_cast<Actor*>(apRefObject);
    }

    if (pactor && reinterpret_cast<TES*>(pactor)->GetLogDate())
    {
        pweapdata = reinterpret_cast<InventoryStackRecord*>(
            reinterpret_cast<LogDate*>(reinterpret_cast<TES*>(pactor)->GetLogDate())->GetItemChange());

        pweap = 0;
        if (pweapdata && pweapdata->GetFlags() && _FNV_GetFormType(pweapdata->GetFlags()) == 0x28)
        {
            pweap = pweapdata->GetFlags();
        }

        if (pweap)
        {
            afReturnValue = DAT_0118a838[pweap->GetWeaponType()];
        }
        else
        {
            afReturnValue = 1.0;
        }
    }

    if (DAT_tls_data[0x268])
    {
        _DebugLog("Get Weapon Anim >> %0.2f", afReturnValue);
    }

    return true;
}
}  // namespace fnv_005a09b0

extern __declspec(thread) unsigned char FUN_005a1900_tls[0x269];
extern void __cdecl _DebugLog(const char* format, double value);

struct FUN_005a1900_VTable
{
    virtual bool Probe00();
    virtual bool Probe01();
    virtual bool Probe02();
    virtual bool Probe03();
    virtual bool Probe04();
    virtual bool Probe05();
    virtual bool Probe06();
    virtual bool Probe07();
    virtual bool Probe08();
    virtual bool Probe09();
    virtual bool Probe10();
    virtual bool Probe11();
    virtual bool Probe12();
    virtual bool Probe13();
    virtual bool Probe14();
    virtual bool Probe15();
    virtual bool Probe16();
    virtual bool Probe17();
    virtual bool Probe18();
    virtual bool Probe19();
    virtual bool Probe20();
    virtual bool Probe21();
    virtual bool Probe22();
    virtual bool Probe23();
    virtual bool Probe24();
    virtual bool Probe25();
    virtual bool Probe26();
    virtual bool Probe27();
    virtual bool Probe28();
    virtual bool Probe29();
    virtual bool Probe30();
    virtual bool Probe31();
    virtual bool Probe32();
    virtual bool Probe33();
    virtual bool Probe34();
    virtual bool Probe35();
    virtual bool Probe36();
    virtual bool Probe37();
    virtual bool Probe38();
    virtual bool Probe39();
    virtual bool Probe40();
    virtual bool Probe41();
    virtual bool Probe42();
    virtual bool Probe43();
    virtual bool Probe44();
    virtual bool Probe45();
    virtual bool Probe46();
    virtual bool Probe47();
    virtual bool Probe48();
    virtual bool Probe49();
    virtual bool Probe50();
    virtual bool Probe51();
    virtual bool Probe52();
    virtual bool Probe53();
    virtual bool Probe54();
    virtual bool Probe55();
    virtual bool Probe56();
    virtual bool Probe57();
    virtual bool Probe58();
    virtual bool Probe59();
    virtual bool Probe60();
    virtual bool Probe61();
    virtual bool Probe62();
    virtual bool Probe63();
    virtual bool Probe64();
    virtual bool Probe65();
    virtual bool Probe66();
    virtual bool Probe67();
    virtual bool Probe68();
    virtual bool Probe69();
    virtual bool Probe70();
    virtual bool Probe71();
    virtual bool Probe72();
    virtual bool Probe73();
    virtual bool Probe74();
    virtual bool Probe75();
    virtual bool Probe76();
    virtual bool Probe77();
    virtual bool Probe78();
    virtual bool Probe79();
    virtual bool Probe80();
    virtual bool Probe81();
    virtual bool Probe82();
    virtual bool Probe83();
    virtual bool Probe84();
    virtual bool Probe85();
    virtual bool Probe86();
    virtual bool Probe87();
    virtual bool Probe88();
    virtual bool Probe89();
    virtual bool Probe90();
    virtual bool Probe91();
    virtual bool Probe92();
    virtual bool Probe93();
    virtual bool Probe94();
    virtual bool Probe95();
    virtual bool Probe96();
    virtual bool Probe97();
    virtual bool Probe98();
    virtual bool Probe99();
    virtual bool Probe100();
    virtual bool Probe101();
    virtual bool Probe102();
    virtual bool Probe103();
    virtual bool Probe104();
    virtual bool Probe105();
    virtual bool Probe106();
    virtual bool Probe107();
    virtual bool Probe108();
    virtual bool Probe109();
    virtual bool Probe110();
    virtual bool Probe111();
    virtual bool Probe112();
    virtual bool Probe113();
    virtual bool Probe114();
    virtual bool Probe115();
    virtual bool Probe116();
    virtual bool Probe117();
    virtual bool Probe118();
    virtual bool Probe119();
    virtual bool Probe120();
    virtual bool Probe121();
    virtual bool Probe122();
    virtual bool Probe123();
    virtual bool Probe124();
    virtual bool Probe125();
    virtual bool Probe126();
    virtual bool Probe127();
    virtual bool Probe128();
    virtual bool Probe129();
    virtual bool Probe130();
    virtual bool Probe131();
    virtual bool Probe132();
    virtual bool Probe133();
    virtual bool Probe134();
    virtual bool Probe135();
    virtual bool Probe136();
    virtual bool Probe137();
    virtual bool Probe138();
    virtual bool Probe139();
    virtual bool Probe140();
    virtual bool Probe141();
    virtual bool Probe142();
    virtual bool Probe143();
    virtual bool Probe144();
    virtual bool Probe145();
    virtual bool Probe146();
    virtual bool Probe147();
    virtual bool Probe148();
    virtual bool Probe149();
    virtual bool Probe150();
    virtual bool Probe151();
    virtual bool Probe152();
    virtual bool Probe153();
    virtual bool Probe154();
    virtual bool Probe155();
    virtual bool Probe156();
    virtual bool Probe157();
    virtual bool Probe158();
    virtual bool Probe159();
    virtual bool Probe160();
    virtual bool Probe161();
    virtual bool Probe162();
    virtual bool Probe163();
    virtual bool Probe164();
    virtual bool Probe165();
    virtual bool Probe166();
    virtual bool Probe167();
    virtual bool Probe168();
    virtual bool Probe169();
    virtual bool Probe170();
    virtual bool Probe171();
    virtual bool Probe172();
    virtual bool Probe173();
    virtual bool Probe174();
    virtual bool Probe175();
    virtual bool Probe176();
    virtual bool Probe177();
    virtual bool Probe178();
    virtual bool Probe179();
    virtual bool Probe180();
    virtual bool Probe181();
    virtual bool Probe182();
    virtual bool Probe183();
    virtual bool Probe184();
    virtual bool Probe185();
    virtual bool Probe186();
    virtual bool Probe187();
    virtual bool Probe188();
    virtual bool Probe189();
    virtual bool Probe190();
    virtual bool Probe191();
    virtual bool Probe192();
    virtual bool Probe193();
    virtual bool Probe194();
    virtual bool Probe195();
    virtual bool Probe196();
    virtual bool Probe197();
    virtual bool Probe198();
    virtual bool Probe199();
    virtual bool Probe200();
    virtual bool Probe201();
    virtual bool Probe202();
    virtual bool Probe203();
    virtual bool Probe204();
    virtual bool Probe205();
    virtual bool Probe206();
    virtual bool Probe207();
    virtual bool Probe208();
    virtual bool Probe209();
    virtual bool Probe210();
    virtual bool Probe211();
    virtual bool Probe212();
    virtual bool Probe213();
    virtual bool Probe214();
    virtual bool Probe215();
    virtual bool Probe216();
    virtual bool Probe217();
    virtual bool Probe218();
    virtual bool Probe219();
    virtual bool Probe220();
    virtual bool Probe221();
    virtual bool Probe222();
    virtual bool Probe223();
    virtual bool Probe224();
    virtual bool Probe225();
    virtual bool Probe226();
    virtual bool Probe227();
    virtual bool Probe228();
    virtual bool Probe229();
    virtual bool Probe230();
    virtual bool Probe231();
    virtual bool Probe232();
    virtual bool Probe233();
    virtual bool Probe234();
    virtual bool Probe235();
    virtual bool Probe236();
    virtual bool Probe237();
    virtual bool Probe238();
    virtual bool Probe239();
    virtual bool Probe240();
    virtual bool Probe241();
    virtual bool Probe242();
    virtual bool Probe243();
    virtual bool Probe244();
    virtual bool Probe245();
    virtual bool Probe246();
    virtual bool Probe247();
    virtual bool Probe248();
    virtual bool Probe249();
    virtual bool Probe250();
    virtual bool Probe251();
    virtual bool Probe252();
    virtual bool Probe253();
    virtual bool Probe254();
    virtual bool Probe255();
    virtual bool Probe256();
    virtual bool Probe257();
    virtual bool Probe258();
    virtual bool Probe259();
    virtual bool Probe260();
    virtual bool Probe261();
    virtual bool Probe262();
    virtual bool Probe263();
    virtual bool Probe264();
    virtual bool Probe265();
    virtual bool Probe266();
    virtual bool Probe267();
    virtual bool Probe268();
    virtual bool Probe269();
    virtual bool Probe270();
    virtual bool Probe271();
    virtual bool Probe272();
    virtual bool Probe273();
    virtual bool Probe274();
};

// Sets result to 1.0 if the reference is an Actor whose Probe274 check passes, otherwise 0.0, and logs the value when the TLS debug flag is set.
// @fnv 0x005a1900
bool __cdecl FUN_005a1900(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;

    Actor* pactor = 0;

    if (reference != 0)
    {
        if (reinterpret_cast<FUN_005a1900_VTable*>(reference)->Probe64())
        {
            pactor = reinterpret_cast<Actor*>(reference);
        }
    }

    if (pactor != 0)
    {
        if (reinterpret_cast<FUN_005a1900_VTable*>(pactor)->Probe274())
        {
            result = 1.0;
        }
    }

    if (FUN_005a1900_tls[0x268] != 0)
    {
        _DebugLog("Is Trespassing Value %0.2f", result);
    }

    return true;
}

struct V0
{
    virtual bool v00();
};
struct V1 : V0
{
    virtual bool v01();
};
struct V2 : V1
{
    virtual bool v02();
};
struct V3 : V2
{
    virtual bool v03();
};
struct V4 : V3
{
    virtual bool v04();
};
struct V5 : V4
{
    virtual bool v05();
};
struct V6 : V5
{
    virtual bool v06();
};
struct V7 : V6
{
    virtual bool v07();
};
struct V8 : V7
{
    virtual bool v08();
};
struct V9 : V8
{
    virtual bool v09();
};
struct V10 : V9
{
    virtual bool v10();
};
struct V11 : V10
{
    virtual bool v11();
};
struct V12 : V11
{
    virtual bool v12();
};
struct V13 : V12
{
    virtual bool v13();
};
struct V14 : V13
{
    virtual bool v14();
};
struct V15 : V14
{
    virtual bool v15();
};
struct V16 : V15
{
    virtual bool v16();
};
struct V17 : V16
{
    virtual bool v17();
};
struct V18 : V17
{
    virtual bool v18();
};
struct V19 : V18
{
    virtual bool v19();
};
struct V20 : V19
{
    virtual bool v20();
};
struct V21 : V20
{
    virtual bool v21();
};
struct V22 : V21
{
    virtual bool v22();
};
struct V23 : V22
{
    virtual bool v23();
};
struct V24 : V23
{
    virtual bool v24();
};
struct V25 : V24
{
    virtual bool v25();
};
struct V26 : V25
{
    virtual bool v26();
};
struct V27 : V26
{
    virtual bool v27();
};
struct V28 : V27
{
    virtual bool v28();
};
struct V29 : V28
{
    virtual bool v29();
};
struct V30 : V29
{
    virtual bool v30();
};
struct V31 : V30
{
    virtual bool v31();
};
struct V32 : V31
{
    virtual bool v32();
};
struct V33 : V32
{
    virtual bool v33();
};
struct V34 : V33
{
    virtual bool v34();
};
struct V35 : V34
{
    virtual bool v35();
};
struct V36 : V35
{
    virtual bool v36();
};
struct V37 : V36
{
    virtual bool v37();
};
struct V38 : V37
{
    virtual bool v38();
};
struct V39 : V38
{
    virtual bool v39();
};
struct V40 : V39
{
    virtual bool v40();
};
struct V41 : V40
{
    virtual bool v41();
};
struct V42 : V41
{
    virtual bool v42();
};
struct V43 : V42
{
    virtual bool v43();
};
struct V44 : V43
{
    virtual bool v44();
};
struct V45 : V44
{
    virtual bool v45();
};
struct V46 : V45
{
    virtual bool v46();
};
struct V47 : V46
{
    virtual bool v47();
};
struct V48 : V47
{
    virtual bool v48();
};
struct V49 : V48
{
    virtual bool v49();
};
struct V50 : V49
{
    virtual bool v50();
};
struct V51 : V50
{
    virtual bool v51();
};
struct V52 : V51
{
    virtual bool v52();
};
struct V53 : V52
{
    virtual bool v53();
};
struct V54 : V53
{
    virtual bool v54();
};
struct V55 : V54
{
    virtual bool v55();
};
struct V56 : V55
{
    virtual bool v56();
};
struct V57 : V56
{
    virtual bool v57();
};
struct V58 : V57
{
    virtual bool v58();
};
struct V59 : V58
{
    virtual bool v59();
};
struct V60 : V59
{
    virtual bool v60();
};
struct V61 : V60
{
    virtual bool v61();
};
struct V62 : V61
{
    virtual bool v62();
};
struct V63 : V62
{
    virtual bool v63();
};
struct V64 : V63
{
    virtual bool v64();
};

struct S008a69d0
{
    bool FUN_008a69d0();
};

void __cdecl _DebugLog(const char* format, ...);
__declspec(thread) bool bConditionFunctionDebug;

// @fnv 0x005a1a40
bool __cdecl FUN_005a1a40(TESObjectREFR* apRefObject, void*, void*, double& afReturnValue)
{
    afReturnValue = 0.0;

    Actor* pactor = 0;
    if (apRefObject && reinterpret_cast<V64*>(apRefObject)->v64())
        pactor = reinterpret_cast<Actor*>(apRefObject);

    if (pactor)
        afReturnValue = reinterpret_cast<S008a69d0*>(pactor)->FUN_008a69d0();

    if (bConditionFunctionDebug)
        _DebugLog("is continuing package near PC value %0.2f", afReturnValue);

    return true;
}

namespace fnv_005a1ad0 {
struct NiFixedString
{
};

struct NiExtraData
{
};

struct NiAVObjectX
{
    NiExtraData* GetExtraData(NiFixedString const& name);
};

struct BSXFlags
{
    bool GetAddon() const;
};

struct FUN_005a1ad0_Dispatch
{
    virtual void f000() = 0;
    virtual void f001() = 0;
    virtual void f002() = 0;
    virtual void f003() = 0;
    virtual void f004() = 0;
    virtual void f005() = 0;
    virtual void f006() = 0;
    virtual void f007() = 0;
    virtual void f008() = 0;
    virtual void f009() = 0;
    virtual void f010() = 0;
    virtual void f011() = 0;
    virtual void f012() = 0;
    virtual void f013() = 0;
    virtual void f014() = 0;
    virtual void f015() = 0;
    virtual void f016() = 0;
    virtual void f017() = 0;
    virtual void f018() = 0;
    virtual void f019() = 0;
    virtual void f020() = 0;
    virtual void f021() = 0;
    virtual void f022() = 0;
    virtual void f023() = 0;
    virtual void f024() = 0;
    virtual void f025() = 0;
    virtual void f026() = 0;
    virtual void f027() = 0;
    virtual void f028() = 0;
    virtual void f029() = 0;
    virtual void f030() = 0;
    virtual void f031() = 0;
    virtual void f032() = 0;
    virtual void f033() = 0;
    virtual void f034() = 0;
    virtual void f035() = 0;
    virtual void f036() = 0;
    virtual void f037() = 0;
    virtual void f038() = 0;
    virtual void f039() = 0;
    virtual void f040() = 0;
    virtual void f041() = 0;
    virtual void f042() = 0;
    virtual void f043() = 0;
    virtual void f044() = 0;
    virtual void f045() = 0;
    virtual void f046() = 0;
    virtual void f047() = 0;
    virtual void f048() = 0;
    virtual void f049() = 0;
    virtual void f050() = 0;
    virtual void f051() = 0;
    virtual void f052() = 0;
    virtual void f053() = 0;
    virtual void f054() = 0;
    virtual void f055() = 0;
    virtual void f056() = 0;
    virtual void f057() = 0;
    virtual void f058() = 0;
    virtual void f059() = 0;
    virtual void f060() = 0;
    virtual void f061() = 0;
    virtual void f062() = 0;
    virtual void f063() = 0;
    virtual void f064() = 0;
    virtual void f065() = 0;
    virtual void f066() = 0;
    virtual void f067() = 0;
    virtual void f068() = 0;
    virtual void f069() = 0;
    virtual void f070() = 0;
    virtual void f071() = 0;
    virtual void f072() = 0;
    virtual void f073() = 0;
    virtual void f074() = 0;
    virtual void f075() = 0;
    virtual void f076() = 0;
    virtual void f077() = 0;
    virtual void f078() = 0;
    virtual void f079() = 0;
    virtual void f080() = 0;
    virtual void f081() = 0;
    virtual void f082() = 0;
    virtual void f083() = 0;
    virtual void f084() = 0;
    virtual void f085() = 0;
    virtual void f086() = 0;
    virtual void f087() = 0;
    virtual void f088() = 0;
    virtual void f089() = 0;
    virtual void f090() = 0;
    virtual void f091() = 0;
    virtual void f092() = 0;
    virtual void f093() = 0;
    virtual void f094() = 0;
    virtual void f095() = 0;
    virtual void f096() = 0;
    virtual void f097() = 0;
    virtual void f098() = 0;
    virtual void f099() = 0;
    virtual void f100() = 0;
    virtual void f101() = 0;
    virtual void f102() = 0;
    virtual void f103() = 0;
    virtual void f104() = 0;
    virtual void f105() = 0;
    virtual void f106() = 0;
    virtual void f107() = 0;
    virtual void f108() = 0;
    virtual void f109() = 0;
    virtual void f110() = 0;
    virtual void f111() = 0;
    virtual void f112() = 0;
    virtual void f113() = 0;
    virtual void f114() = 0;
    virtual void f115() = 0;
    virtual NiAVObjectX* f116() = 0;
};

NiFixedString const& __cdecl FUN_00448a80(void);
BSXFlags* __cdecl _UseSaveGameBlocks(BSXFlags* blocks, NiExtraData* extra);
void __cdecl _DebugLog(char const* format, double value);

extern BSXFlags _g_01202de0;

struct FUN_005a1ad0_ThreadData
{
    unsigned char padding[0x268];
    unsigned char debugLogEnabled;
};

__declspec(thread) FUN_005a1ad0_ThreadData g_FUN_005a1ad0_ThreadData;

// @fnv 0x005a1ad0
bool __cdecl FUN_005a1ad0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    NiExtraData* pExtraData;

    afReturnValue = 0.0;

    if (apRefObject)
    {
        pExtraData = reinterpret_cast<FUN_005a1ad0_Dispatch*>(apRefObject)->f116()->GetExtraData(FUN_00448a80());

        if (pExtraData)
        {
            BSXFlags* pBSXFlags = _UseSaveGameBlocks(&_g_01202de0, pExtraData);
            afReturnValue = pBSXFlags->GetAddon() ? 1.0f : 0.0f;
        }
    }

    if (g_FUN_005a1ad0_ThreadData.debugLogEnabled)
        _DebugLog("CanHaveFlames >> %0.2f", afReturnValue);

    return true;
}
}  // namespace fnv_005a1ad0

struct FUN_008a81e0_shell
{
    int FUN_008a81e0(Actor* target);
};

int FUN_008a81e0_shell::FUN_008a81e0(Actor* target)
{
    return 0;
}

struct FUN_0055d520_shell
{
    char* FUN_0055d520();
};

char* FUN_0055d520_shell::FUN_0055d520()
{
    return 0;
}

void __cdecl _DebugLog(char const* format, ...)
{}

extern int __tls_index;
__declspec(thread) unsigned char g_tlsDebugEnabled[0x269];

// @fnv 0x005a1ee0
bool __cdecl FUN_005a1ee0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;

    if (apRefObject)
    {
        afReturnValue = 0.0;

        Actor* pActor = 0;
        if (apRefObject && apRefObject->IsActor())
        {
            pActor = reinterpret_cast<Actor*>(apRefObject);
        }

        Actor* pTarget = reinterpret_cast<Actor*>(apParam1);
        if (pActor && pTarget)
        {
            afReturnValue = reinterpret_cast<FUN_008a81e0_shell*>(pActor)->FUN_008a81e0(pTarget);

            if (g_tlsDebugEnabled[0x268])
            {
                _DebugLog("%s detects %s at level %.02f", reinterpret_cast<FUN_0055d520_shell*>(pActor)->FUN_0055d520(),
                          reinterpret_cast<FUN_0055d520_shell*>(pTarget)->FUN_0055d520(), afReturnValue);
            }
        }
    }

    return true;
}

namespace fnv_005a1fa0 {
extern unsigned int __tls_index;
extern __declspec(thread) unsigned char FUN_tls_context[0x269];
extern void __cdecl _DebugLog(char const*, ...);

struct FUN_005a2030_shell
{
    bool FUN_005a2030() const;
};

// Sets afReturnValue to 1.0 when apRefObject is an actor whose FUN_005a2030 returns true, logs the result if the TLS flag is set, and returns true.
// @fnv 0x005a1fa0
bool __cdecl FUN_005a1fa0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pact = 0;

    if (apRefObject && apRefObject->IsActor())
        pact = reinterpret_cast<Actor*>(apRefObject);

    if (pact && reinterpret_cast<FUN_005a2030_shell*>(pact)->FUN_005a2030())
        afReturnValue = 1.0;

    if (FUN_tls_context[0x268])
        _DebugLog("Is Swimming >> %0.2f", afReturnValue);

    return true;
}
}  // namespace fnv_005a1fa0

namespace fnv_005a2440 {
extern int __tls_index;

class MagicItem;

class MagicTarget
{
  public:
    bool HasSpell(MagicItem*, bool);
};

struct MagicItemBase
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
};

class MagicItem : public MagicItemBase
{
  public:
    virtual bool CanBeSpellTarget();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual MagicTarget* GetMagicTarget();
};

struct TLSData
{
    unsigned char padding[0x268];
    unsigned char debugEnabled;
};

extern __declspec(thread) TLSData tlsData;

void __cdecl _DebugLog(const char*, ...);

// @fnv 0x005a2440
bool __cdecl FUN_005a2440(TESObjectREFR* reference, void* apActor, void* apUnused, double& result)
{
    MagicItem* pmagicItem;

    result = 0.0;
    pmagicItem = 0;

    if (reference && reinterpret_cast<MagicItem*>(reference)->CanBeSpellTarget())
    {
        pmagicItem = reinterpret_cast<MagicItem*>(reference);
    }

    {
        Actor* pactor = reinterpret_cast<Actor*>(apActor);

        if (pmagicItem && pactor && pmagicItem->GetMagicTarget()->HasSpell(reinterpret_cast<MagicItem*>(pactor), true))
        {
            result = 1.0;
        }
    }

    if (tlsData.debugEnabled)
    {
        _DebugLog("Is Spell Target >> %0.2f", result);
    }

    return true;
}
}  // namespace fnv_005a2440

struct VirtualActor
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsEssentialActor();
};

struct FUN_00822eb0_shell
{
    float FUN_00822eb0(MagicItem*);
};

__declspec(thread) unsigned char tlsDebugData[0x269];

extern int __tls_index;
extern void __cdecl _DebugLog(const char*, ...);

// @fnv 0x005a24f0
bool __cdecl FUN_005a24f0(TESObjectREFR* reference, void* pMagicItem, void* pUnused, double& result)
{
    Actor* pactor;

    result = 0.0;

    pactor = 0;
    if (reference && reinterpret_cast<VirtualActor*>(reference)->IsEssentialActor())
        pactor = (Actor*)reference;

    {
        MagicItem* pmagicItem;

        pmagicItem = (MagicItem*)pMagicItem;
        if (pactor && pmagicItem)
            result = reinterpret_cast<FUN_00822eb0_shell*>(reinterpret_cast<unsigned char*>(pactor) + 0x94)
                         ->FUN_00822eb0(pmagicItem);
    }

    if (tlsDebugData[0x268])
        _DebugLog("GetSpellUsageNum >> %0.2f", result);

    return true;
}

struct TESObjectREFR_GetAction : TESObjectREFR
{
    bool GetAction(int action);
};

bool TESObjectREFR_GetAction::GetAction(int action)
{
    return false;
}

// Returns false if apRefObject is null; otherwise sets afReturnValue to 1.0 when GetAction(8) succeeds, else 0.0, and returns true.
// @fnv 0x005a27e0
bool __cdecl FUN_005a27e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    if (apRefObject == 0)
        return false;

    afReturnValue = 0.0;
    if (reinterpret_cast<TESObjectREFR_GetAction*>(apRefObject)->GetAction(8))
        afReturnValue = 1.0;

    return true;
}

// If reference is non-null and passes the virtual check at vtable offset 0x40, stores it in actor; sets result to 0.0 and returns true.
// @fnv 0x005a2c30
bool __cdecl FUN_005a2c30(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    TESObjectREFR* actor = 0;
    if (reference &&
        reinterpret_cast<bool(__thiscall*)(TESObjectREFR*)>(reinterpret_cast<void***>(reference)[0][0x40])(reference))
    {
        actor = reference;
    }
    result = 0.0;
    return true;
}

struct DoorCell
{
    TESForm* GetOwner();
};

char const* __cdecl FUN_00482720(TESForm* form);
void __cdecl _DebugLog(char const* format, ...);

struct FUN_005a2ed0_TLSData
{
    unsigned char padding[0x268];
    unsigned char value;
};

extern __declspec(thread) FUN_005a2ed0_TLSData FUN_005a2ed0_TLSData;

// @fnv 0x005a2ed0
bool __cdecl FUN_005a2ed0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    DoorCell* m_pSourceCell = static_cast<DoorCell*>(arg1);
    TESForm* pOwner = static_cast<TESForm*>(arg2);

    if (m_pSourceCell->GetOwner() == pOwner)
        result = 1.0;

    if (FUN_005a2ed0_TLSData.value)
    {
        if (result != 0.0)
            _DebugLog("%s is the owner", FUN_00482720(pOwner));
        else
            _DebugLog("%s is not the owner", FUN_00482720(pOwner));
    }

    return true;
}

struct FUN_005a3670_ProbeBase
{
    virtual bool V00() = 0;
    virtual bool V01() = 0;
    virtual bool V02() = 0;
    virtual bool V03() = 0;
    virtual bool V04() = 0;
    virtual bool V05() = 0;
    virtual bool V06() = 0;
    virtual bool V07() = 0;
    virtual bool V08() = 0;
    virtual bool V09() = 0;
    virtual bool V10() = 0;
    virtual bool V11() = 0;
    virtual bool V12() = 0;
    virtual bool V13() = 0;
    virtual bool V14() = 0;
    virtual bool V15() = 0;
    virtual bool V16() = 0;
    virtual bool V17() = 0;
    virtual bool V18() = 0;
    virtual bool V19() = 0;
    virtual bool V20() = 0;
    virtual bool V21() = 0;
    virtual bool V22() = 0;
    virtual bool V23() = 0;
    virtual bool V24() = 0;
    virtual bool V25() = 0;
    virtual bool V26() = 0;
    virtual bool V27() = 0;
    virtual bool V28() = 0;
    virtual bool V29() = 0;
    virtual bool V30() = 0;
    virtual bool V31() = 0;
    virtual bool V32() = 0;
    virtual bool V33() = 0;
    virtual bool V34() = 0;
    virtual bool V35() = 0;
    virtual bool V36() = 0;
    virtual bool V37() = 0;
    virtual bool V38() = 0;
    virtual bool V39() = 0;
    virtual bool V40() = 0;
    virtual bool V41() = 0;
    virtual bool V42() = 0;
    virtual bool V43() = 0;
    virtual bool V44() = 0;
    virtual bool V45() = 0;
    virtual bool V46() = 0;
    virtual bool V47() = 0;
    virtual bool V48() = 0;
    virtual bool V49() = 0;
    virtual bool V50() = 0;
    virtual bool V51() = 0;
    virtual bool V52() = 0;
    virtual bool V53() = 0;
    virtual bool V54() = 0;
    virtual bool V55() = 0;
    virtual bool V56() = 0;
    virtual bool V57() = 0;
    virtual bool V58() = 0;
    virtual bool V59() = 0;
    virtual bool V60() = 0;
    virtual bool V61() = 0;
    virtual bool V62() = 0;
    virtual bool V63() = 0;
};

struct FUN_005a3670_Probe : public FUN_005a3670_ProbeBase
{
    virtual bool V64()
    {
        return true;
    }
};

// Zeroes afReturnValue, then sets pactor to apRefObject if it is non-null and its V64() check passes; always returns true.
// @fnv 0x005a3670
bool FUN_005a3670(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    Actor* pactor = 0;

    if (apRefObject)
    {
        if (reinterpret_cast<FUN_005a3670_Probe*>(apRefObject)->V64())
        {
            pactor = reinterpret_cast<Actor*>(apRefObject);
        }
    }

    return true;
}

namespace fnv_005a3a30 {
class Calendar
{
  public:
    unsigned int GetGameHoursPassed(void);
};

class Time : public Calendar
{
};

extern Time DAT_011de7b8;
extern double _DAT_01012060;

class TES
{
  public:
    void* GetLogDate(void);
};

class FUN_005a3a30_ObjectBase
{
  public:
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
};

class FUN_005a3a30_Object : public FUN_005a3a30_ObjectBase
{
  public:
    virtual bool v064() = 0;

    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;

    virtual bool v139(int) = 0;
};

class FUN_005a3a30_LogBase
{
  public:
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
};

class FUN_005a3a30_Log1 : public FUN_005a3a30_LogBase
{
  public:
    virtual void v064() = 0;
    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
};

class FUN_005a3a30_Log2 : public FUN_005a3a30_Log1
{
  public:
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
};

class FUN_005a3a30_Log3 : public FUN_005a3a30_Log2
{
  public:
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void v243() = 0;
    virtual void v244() = 0;
    virtual void v245() = 0;
    virtual void v246() = 0;
    virtual void v247() = 0;
    virtual void v248() = 0;
    virtual void v249() = 0;
    virtual void v250() = 0;
    virtual void v251() = 0;
    virtual void v252() = 0;
    virtual void v253() = 0;
    virtual void v254() = 0;
    virtual void v255() = 0;
};

class FUN_005a3a30_Log4 : public FUN_005a3a30_Log3
{
  public:
    virtual void v256() = 0;
    virtual void v257() = 0;
    virtual void v258() = 0;
    virtual void v259() = 0;
    virtual void v260() = 0;
    virtual void v261() = 0;
    virtual void v262() = 0;
    virtual void v263() = 0;
    virtual void v264() = 0;
    virtual void v265() = 0;
    virtual void v266() = 0;
    virtual void v267() = 0;
    virtual void v268() = 0;
    virtual void v269() = 0;
    virtual void v270() = 0;
    virtual void v271() = 0;
    virtual void v272() = 0;
    virtual void v273() = 0;
    virtual void v274() = 0;
    virtual void v275() = 0;
    virtual void v276() = 0;
    virtual void v277() = 0;
    virtual void v278() = 0;
    virtual void v279() = 0;
    virtual void v280() = 0;
    virtual void v281() = 0;
    virtual void v282() = 0;
    virtual void v283() = 0;
    virtual void v284() = 0;
    virtual void v285() = 0;
    virtual void v286() = 0;
    virtual void v287() = 0;
    virtual void v288() = 0;
    virtual void v289() = 0;
    virtual void v290() = 0;
    virtual void v291() = 0;
    virtual void v292() = 0;
    virtual void v293() = 0;
    virtual void v294() = 0;
    virtual void v295() = 0;
    virtual void v296() = 0;
    virtual void v297() = 0;
    virtual void v298() = 0;
    virtual void v299() = 0;
    virtual void v300() = 0;
    virtual void v301() = 0;
    virtual void v302() = 0;
    virtual void v303() = 0;
    virtual void v304() = 0;
    virtual void v305() = 0;
    virtual void v306() = 0;
    virtual void v307() = 0;
    virtual void v308() = 0;
    virtual void v309() = 0;
    virtual void v310() = 0;
    virtual void v311() = 0;
    virtual void v312() = 0;
    virtual void v313() = 0;
    virtual void v314() = 0;
    virtual void v315() = 0;
    virtual void v316() = 0;
    virtual void v317() = 0;
    virtual void v318() = 0;
    virtual void v319() = 0;
};

class FUN_005a3a30_Log5 : public FUN_005a3a30_Log4
{
  public:
    virtual void v320() = 0;
    virtual void v321() = 0;
    virtual void v322() = 0;
    virtual void v323() = 0;
    virtual void v324() = 0;
    virtual void v325() = 0;
    virtual void v326() = 0;
    virtual void v327() = 0;
    virtual void v328() = 0;
    virtual void v329() = 0;
    virtual void v330() = 0;
    virtual void v331() = 0;
    virtual void v332() = 0;
    virtual void v333() = 0;
    virtual void v334() = 0;
    virtual void v335() = 0;
    virtual void v336() = 0;
    virtual void v337() = 0;
    virtual void v338() = 0;
    virtual void v339() = 0;
    virtual void v340() = 0;
    virtual void v341() = 0;
    virtual void v342() = 0;
    virtual void v343() = 0;
    virtual void v344() = 0;
    virtual void v345() = 0;
    virtual void v346() = 0;
    virtual void v347() = 0;
    virtual void v348() = 0;
    virtual void v349() = 0;
    virtual void v350() = 0;
    virtual void v351() = 0;
    virtual void v352() = 0;
    virtual void v353() = 0;
    virtual void v354() = 0;
    virtual void v355() = 0;
    virtual void v356() = 0;
    virtual void v357() = 0;
    virtual void v358() = 0;
    virtual void v359() = 0;
    virtual void v360() = 0;
    virtual void v361() = 0;
    virtual void v362() = 0;
    virtual void v363() = 0;
    virtual void v364() = 0;
    virtual void v365() = 0;
    virtual void v366() = 0;
    virtual void v367() = 0;
    virtual void v368() = 0;
    virtual void v369() = 0;
    virtual void v370() = 0;
    virtual void v371() = 0;
};

class FUN_005a3a30_Log6 : public FUN_005a3a30_Log5
{
  public:
    virtual void v380() = 0;
    virtual void v381() = 0;
    virtual void v382() = 0;
    virtual void v383() = 0;
    virtual void v384() = 0;
    virtual void v385() = 0;
    virtual void v386() = 0;
    virtual void v387() = 0;
    virtual void v388() = 0;
    virtual void v389() = 0;
    virtual void v390() = 0;
    virtual void v391() = 0;
    virtual void v392() = 0;
    virtual void v393() = 0;
    virtual void v394() = 0;
    virtual void v395() = 0;
    virtual void v396() = 0;
    virtual void v397() = 0;
    virtual void v398() = 0;
    virtual void v399() = 0;
    virtual void v400() = 0;
    virtual void v401() = 0;
    virtual void v402() = 0;
    virtual void v403() = 0;
    virtual void v404() = 0;
    virtual void v405() = 0;
    virtual void v406() = 0;
    virtual void v407() = 0;
    virtual void v408() = 0;
    virtual void v409() = 0;
    virtual void v410() = 0;
    virtual void v411() = 0;
    virtual void v412() = 0;
    virtual void v413() = 0;
    virtual void v414() = 0;
    virtual void v415() = 0;
    virtual void v416() = 0;
    virtual void v417() = 0;
    virtual void v418() = 0;
    virtual void v419() = 0;
    virtual void v420() = 0;
    virtual void v421() = 0;
    virtual void v422() = 0;
    virtual void v423() = 0;
    virtual void v424() = 0;
    virtual void v425() = 0;
    virtual void v426() = 0;
    virtual void v427() = 0;
    virtual void v428() = 0;
    virtual void v429() = 0;
    virtual void v430() = 0;

    virtual float v431() = 0;
};

// @fnv 0x005a3a30
bool FUN_005a3a30(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    Actor* pactor;
    float fdeadtime;
    float fcurrtime;

    *afReturnValue = 0.0;

    if (apRefObject && ((FUN_005a3a30_Object*)apRefObject)->v139(0) && ((FUN_005a3a30_Object*)apRefObject)->v064())
    {
        pactor = (Actor*)apRefObject;

        if (((TES*)pactor)->GetLogDate() &&
            (fdeadtime = ((FUN_005a3a30_Log6*)((TES*)pactor)->GetLogDate())->v431()) > 0.0)
        {
            fcurrtime = DAT_011de7b8.GetGameHoursPassed();
            *afReturnValue = fcurrtime - fdeadtime;
        }
    }

    return true;
}
}  // namespace fnv_005a3a30

namespace fnv_005a3e10 {
struct FUN_005a3e10_TLSData
{
    unsigned char padding[0x268];
    bool debugLogEnabled;
};

extern __declspec(thread) FUN_005a3e10_TLSData g_tlsData;
extern int __tls_index;

void __cdecl _DebugLog(const char* format, double value);
int __fastcall FUN_00573110(int thisPointer);

struct FUN_005a3e10_VirtualActor
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsEssentialActor();
};

// @fnv 0x005a3e10
bool __cdecl FUN_005a3e10(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = -1.0;

    if (reinterpret_cast<FUN_005a3e10_VirtualActor*>(apRefObject)->IsEssentialActor())
    {
        Actor* pactor = reinterpret_cast<Actor*>(apRefObject);
        afReturnValue = static_cast<double>(FUN_00573110(reinterpret_cast<int>(pactor)));
    }

    if (g_tlsData.debugLogEnabled)
        _DebugLog("Last hit limb is >> %0.0f", afReturnValue);

    return true;
}
}  // namespace fnv_005a3e10

void __cdecl _DebugLog(const char* format, ...);

__declspec(thread) unsigned char FUN_005a3f00_tlsData[0x269];

struct FUN_005a3f00_Proxy
{
    virtual bool M000() = 0;
    virtual bool M001() = 0;
    virtual bool M002() = 0;
    virtual bool M003() = 0;
    virtual bool M004() = 0;
    virtual bool M005() = 0;
    virtual bool M006() = 0;
    virtual bool M007() = 0;
    virtual bool M008() = 0;
    virtual bool M009() = 0;
    virtual bool M010() = 0;
    virtual bool M011() = 0;
    virtual bool M012() = 0;
    virtual bool M013() = 0;
    virtual bool M014() = 0;
    virtual bool M015() = 0;
    virtual bool M016() = 0;
    virtual bool M017() = 0;
    virtual bool M018() = 0;
    virtual bool M019() = 0;
    virtual bool M020() = 0;
    virtual bool M021() = 0;
    virtual bool M022() = 0;
    virtual bool M023() = 0;
    virtual bool M024() = 0;
    virtual bool M025() = 0;
    virtual bool M026() = 0;
    virtual bool M027() = 0;
    virtual bool M028() = 0;
    virtual bool M029() = 0;
    virtual bool M030() = 0;
    virtual bool M031() = 0;
    virtual bool M032() = 0;
    virtual bool M033() = 0;
    virtual bool M034() = 0;
    virtual bool M035() = 0;
    virtual bool M036() = 0;
    virtual bool M037() = 0;
    virtual bool M038() = 0;
    virtual bool M039() = 0;
    virtual bool M040() = 0;
    virtual bool M041() = 0;
    virtual bool M042() = 0;
    virtual bool M043() = 0;
    virtual bool M044() = 0;
    virtual bool M045() = 0;
    virtual bool M046() = 0;
    virtual bool M047() = 0;
    virtual bool M048() = 0;
    virtual bool M049() = 0;
    virtual bool M050() = 0;
    virtual bool M051() = 0;
    virtual bool M052() = 0;
    virtual bool M053() = 0;
    virtual bool M054() = 0;
    virtual bool M055() = 0;
    virtual bool M056() = 0;
    virtual bool M057() = 0;
    virtual bool M058() = 0;
    virtual bool M059() = 0;
    virtual bool M060() = 0;
    virtual bool M061() = 0;
    virtual bool M062() = 0;
    virtual bool M063() = 0;
    virtual bool M064() = 0;
    virtual bool M065() = 0;
    virtual bool M066() = 0;
    virtual bool M067() = 0;
    virtual bool M068() = 0;
    virtual bool M069() = 0;
    virtual bool M070() = 0;
    virtual bool M071() = 0;
    virtual bool M072() = 0;
    virtual bool M073() = 0;
    virtual bool M074() = 0;
    virtual bool M075() = 0;
    virtual bool M076() = 0;
    virtual bool M077() = 0;
    virtual bool M078() = 0;
    virtual bool M079() = 0;
    virtual bool M080() = 0;
    virtual bool M081() = 0;
    virtual bool M082() = 0;
    virtual bool M083() = 0;
    virtual bool M084() = 0;
    virtual bool M085() = 0;
    virtual bool M086() = 0;
    virtual bool M087() = 0;
    virtual bool M088() = 0;
    virtual bool M089() = 0;
    virtual bool M090() = 0;
    virtual bool M091() = 0;
    virtual bool M092() = 0;
    virtual bool M093() = 0;
    virtual bool M094() = 0;
    virtual bool M095() = 0;
    virtual bool M096() = 0;
    virtual bool M097() = 0;
    virtual bool M098() = 0;
    virtual bool M099() = 0;
    virtual bool M100() = 0;
    virtual bool M101() = 0;
    virtual bool M102() = 0;
    virtual bool M103() = 0;
    virtual bool M104() = 0;
    virtual bool M105() = 0;
    virtual bool M106() = 0;
    virtual bool M107() = 0;
    virtual bool M108() = 0;
    virtual bool M109() = 0;
    virtual bool M110() = 0;
    virtual bool M111() = 0;
    virtual bool M112() = 0;
    virtual bool M113() = 0;
    virtual bool M114() = 0;
    virtual bool M115() = 0;
    virtual bool M116() = 0;
    virtual bool M117() = 0;
    virtual bool M118() = 0;
    virtual bool M119() = 0;
    virtual bool M120() = 0;
    virtual bool M121() = 0;
    virtual bool M122() = 0;
    virtual bool M123() = 0;
    virtual bool M124() = 0;
    virtual bool M125() = 0;
    virtual bool M126() = 0;
    virtual bool M127() = 0;
    virtual bool M128() = 0;
    virtual bool M129() = 0;
    virtual bool M130() = 0;
    virtual bool M131() = 0;
    virtual bool M132() = 0;
    virtual bool M133() = 0;
    virtual bool M134() = 0;
    virtual bool M135() = 0;
    virtual bool M136() = 0;
    virtual bool M137() = 0;
    virtual bool M138() = 0;
    virtual bool M139(int) = 0;
};

// @fnv 0x005a3f00
bool __cdecl FUN_005a3f00(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    Actor* pactor;
    Actor* pact;

    *afReturnValue = 0.0;

    if (apRefObject)
    {
        if (reinterpret_cast<FUN_005a3f00_Proxy*>(apRefObject)->M064())
        {
            pactor = reinterpret_cast<Actor*>(apRefObject);

            if (reinterpret_cast<FUN_005a3f00_Proxy*>(pactor)->M139(0))
            {
                pact = reinterpret_cast<Actor*>(apParam1);

                if (reinterpret_cast<void*>(pact) ==
                    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(pactor) + 0xc0))
                {
                    *afReturnValue = 1.0;
                }
            }

            if (FUN_005a3f00_tlsData[0x268])
            {
                _DebugLog("IsKiller >> %0.2f", *afReturnValue);
            }
        }
    }

    return true;
}

struct _FactionSub
{
    int FUN_0048c1b0(TESForm* form);
};

struct ScriptFactionSubAccess
{
    unsigned char padding[0x24];
    _FactionSub factionSub;
};

// If both the script and faction are non-null, stores the faction's combat reaction value into result and returns true.
// @fnv 0x005a4090
bool __cdecl FUN_005a4090(TESObjectREFR* reference, void* pScript, void* pFaction, double& result)
{
    ScriptFactionSubAccess* script = reinterpret_cast<ScriptFactionSubAccess*>(pScript);
    TESForm* faction = reinterpret_cast<TESForm*>(pFaction);

    if (faction && script)
    {
        int combatReaction = script->factionSub.FUN_0048c1b0(faction);
        result = combatReaction;
    }

    return true;
}

namespace fnv_005a4b60 {
struct ActorState
{
    unsigned int GetMaskedState(void) const;
};

struct VirtualActor
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24()
    {}
    virtual void f25()
    {}
    virtual void f26()
    {}
    virtual void f27()
    {}
    virtual void f28()
    {}
    virtual void f29()
    {}
    virtual void f30()
    {}
    virtual void f31()
    {}
    virtual void f32()
    {}
    virtual void f33()
    {}
    virtual void f34()
    {}
    virtual void f35()
    {}
    virtual void f36()
    {}
    virtual void f37()
    {}
    virtual void f38()
    {}
    virtual void f39()
    {}
    virtual void f40()
    {}
    virtual void f41()
    {}
    virtual void f42()
    {}
    virtual void f43()
    {}
    virtual void f44()
    {}
    virtual void f45()
    {}
    virtual void f46()
    {}
    virtual void f47()
    {}
    virtual void f48()
    {}
    virtual void f49()
    {}
    virtual void f50()
    {}
    virtual void f51()
    {}
    virtual void f52()
    {}
    virtual void f53()
    {}
    virtual void f54()
    {}
    virtual void f55()
    {}
    virtual void f56()
    {}
    virtual void f57()
    {}
    virtual void f58()
    {}
    virtual void f59()
    {}
    virtual void f60()
    {}
    virtual void f61()
    {}
    virtual void f62()
    {}
    virtual void f63()
    {}
    virtual bool IsEssentialActor()
    {
        return true;
    }
};

struct ThreadLocalData
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

__declspec(thread) ThreadLocalData g_threadLocalData;

extern int FUN_008b7f00();

void __cdecl _DebugLog(const char* format, ...);

// Sets afReturnValue to the major crime count of apRefObject (via the player's own state or FUN_008b7f00) and logs it when debug logging is enabled; returns true.
// @fnv 0x005a4b60
bool __cdecl FUN_005a4b60(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pactor;

    afReturnValue = 0.0;

    if (apRefObject && ((VirtualActor*)apRefObject)->IsEssentialActor())
    {
        pactor = (Actor*)apRefObject;

        if (pactor == (Actor*)g_thePlayer)
        {
            {
                int majorCrimeCount = (int)((ActorState*)pactor)->GetMaskedState();
                afReturnValue = majorCrimeCount;
            }
        }
        else
        {
            {
                int majorCrimeCount = ((int(__thiscall*)(Actor*))FUN_008b7f00)(pactor);
                afReturnValue = majorCrimeCount;
            }
        }

        if (g_threadLocalData.enabled)
        {
            _DebugLog("The number of major crimes is %.2f", afReturnValue);
        }
    }

    return true;
}
}  // namespace fnv_005a4b60

namespace fnv_005a4c20 {
struct FUN_0089f4e0_shell
{
    TESObjectREFR* FUN_0089f4e0(void);
};

extern FUN_0089f4e0_shell* _g_thePlayer;

// Sets result to 1.0 when arg1 equals the player reference, otherwise leaves it at 0.0, and returns true.
// @fnv 0x005a4c20
bool IsPlayerReference(TESObjectREFR* reference, void* apReference, void* apUnused, double& result)
{
    TESObjectREFR* ref;
    result = 0.0;
    ref = (TESObjectREFR*)apReference;
    if (ref != 0)
    {
        if (_g_thePlayer->FUN_0089f4e0() == ref)
            result = 1.0;
    }
    return true;
}
}  // namespace fnv_005a4c20

namespace fnv_005a53e0 {
extern void __cdecl _DebugLog(const char* format, ...);
extern unsigned int __tls_index;

struct FUN_005a53e0_virtual_helper
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual bool GetBlockPostAnim()
    {
        return false;
    }
};

struct FUN_008bc700_shell
{
    bool FUN_008bc700(Actor* actor);
};

struct FUN_005a53e0_tls_data
{
    unsigned char padding[0x268];
    unsigned char debugEnabled;
};

static __declspec(thread) FUN_005a53e0_tls_data FUN_005a53e0_tls;

// Sets afReturnValue to 1.0 if apRefObject blocks post-anim and its check against apParam1 succeeds, logs the result, and returns true.
// @fnv 0x005a53e0
bool FUN_005a53e0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;

    if (apRefObject && reinterpret_cast<FUN_005a53e0_virtual_helper*>(apRefObject)->GetBlockPostAnim())
    {
        Actor* pact = reinterpret_cast<Actor*>(apRefObject);
        if (reinterpret_cast<FUN_008bc700_shell*>(pact)->FUN_008bc700(reinterpret_cast<Actor*>(apParam1)))
        {
            afReturnValue = 1.0;
        }
    }

    if (FUN_005a53e0_tls.debugEnabled)
    {
        _DebugLog("IsCombatTarget >> %.2f", afReturnValue);
    }

    return true;
}
}  // namespace fnv_005a53e0

extern void __cdecl _DebugLog(const char* format, double value);
extern int __tls_index;

__declspec(thread) unsigned char FUN_005a5460_tlsData[0x269];

struct FUN_005a5460_StandIn
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual bool IsEssentialActor()
    {
        return false;
    }

    float FUN_008bd830(TESObjectREFR* target, float value);
};

// Computes a value from apRefObject against apParam1, stores it in afReturnValue, logs it when the TLS flag is set, and returns true.
// @fnv 0x005a5460
bool __cdecl FUN_005a5460(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    TESObjectREFR* ptargetRef;

    afReturnValue = 0.0;
    ptargetRef = (TESObjectREFR*)apParam1;

    if (apRefObject && ((FUN_005a5460_StandIn*)apRefObject)->IsEssentialActor())
    {
        afReturnValue = ((FUN_005a5460_StandIn*)apRefObject)->FUN_008bd830(ptargetRef, 1.5707963705062866f);
    }

    if (FUN_005a5460_tlsData[0x268])
        _DebugLog("VATSRightAreaFree >> %.2f", afReturnValue);

    return true;
}

extern int __tls_index;
extern __declspec(thread) unsigned char FUN_005a54f0_debug;

struct FUN_005a54f0_Object
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool FUN_005a54f0_check();
};

struct FUN_008bd830_Caller
{
    float FUN_008bd830(TESObjectREFR* target, float value);
};

void __cdecl _DebugLog(const char* format, double value);

// Computes the left-area-free value for the reference via FUN_008bd830 with 4.71238899f, stores it in afReturnValue, optionally logs it, and returns true.
// @fnv 0x005a54f0
bool __cdecl FUN_005a54f0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    TESObjectREFR* ptargetRef;

    afReturnValue = 0.0;
    ptargetRef = (TESObjectREFR*)apParam1;

    if (apRefObject && ((FUN_005a54f0_Object*)apRefObject)->FUN_005a54f0_check())
    {
        afReturnValue = ((FUN_008bd830_Caller*)apRefObject)->FUN_008bd830(ptargetRef, 4.71238899f);
    }

    if (FUN_005a54f0_debug)
    {
        _DebugLog("VATSLeftAreaFree >> %.2f", afReturnValue);
    }

    return true;
}

namespace fnv_005a5610 {
extern int __tls_index;
extern __declspec(thread) unsigned char FUN_005a5610_tls[0x269];

void __cdecl _DebugLog(const char*, double, ...);

struct VirtualActor
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();

    virtual bool IsEssentialActor();

    double FUN_008bd830(TESObjectREFR*, float);
};

// Computes the front-area-free value for apRefObject against ptargetRef, stores it in afReturnValue, optionally logs it, and returns true.
// @fnv 0x005a5610
bool __cdecl FUN_005a5610(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    TESObjectREFR* ptargetRef;

    afReturnValue = 0.0;
    ptargetRef = static_cast<TESObjectREFR*>(apParam1);

    if (apRefObject && reinterpret_cast<VirtualActor*>(apRefObject)->IsEssentialActor())
        afReturnValue = reinterpret_cast<VirtualActor*>(apRefObject)->FUN_008bd830(ptargetRef, 0.0f);

    if (FUN_005a5610_tls[0x268])
        _DebugLog("VATSFrontAreaFree >> %.2f", afReturnValue);

    return true;
}
}  // namespace fnv_005a5610

extern int __tls_index;

void __cdecl _DebugLog(const char* format, ...);

struct FUN_005a5720_TLS
{
    unsigned char padding[0x268];
    unsigned char enabled;
};

static __declspec(thread) FUN_005a5720_TLS FUN_005a5720_tls;

struct FUN_005a5720_StandIn
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual bool v64() = 0;

    double FUN_008bdbd0(TESObjectREFR* target, float value);
};

// Computes a value for apRefObject against apParam1 at 4.712389 radians, stores it in afReturnValue, logs it when TLS enabled, and returns true.
// @fnv 0x005a5720
bool __cdecl FUN_005a5720(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    afReturnValue = 0.0;
    TESObjectREFR* ptargetRef = static_cast<TESObjectREFR*>(apParam1);

    if (apRefObject && reinterpret_cast<FUN_005a5720_StandIn*>(apRefObject)->v64())
    {
        afReturnValue =
            reinterpret_cast<FUN_005a5720_StandIn*>(apRefObject)->FUN_008bdbd0(ptargetRef, 4.71238899230957f);
    }

    if (FUN_005a5720_tls.enabled)
        _DebugLog("VATSLeftTargetVisible >> %.2f", afReturnValue);

    return true;
}

namespace fnv_005a58c0 {
struct GlobalObject_0045cfe0
{
    int* Int();
};

struct ActorValueUtility
{
    static int __cdecl ConvertActorValue(int level);
};

struct ActorLevelAccess
{
    unsigned short GetLevel();
};

struct PlayerStatAccess
{
    virtual ~PlayerStatAccess();
    virtual int GetFirstStat();
    virtual int GetStat(int stat);
};

void __cdecl _DebugLog(const char* format, ...);

extern Actor* _g_thePlayer;
extern GlobalObject_0045cfe0 g_011d0c60;
extern int __tls_index;
extern __declspec(thread) unsigned char g_005a58c0_tlsFlag;

unsigned short ActorLevelAccess::GetLevel()
{
    return 0;
}

// Returns true and sets afReturnValue to the XP still needed for the next level, or 0 when the player is already at max level.
// @fnv 0x005a58c0
bool __cdecl FUN_005a58c0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    int iplayerLevel;
    int inextThreshold;
    int icurrentXP;

    afReturnValue = 0.0;

    iplayerLevel = reinterpret_cast<ActorLevelAccess*>(_g_thePlayer)->GetLevel();

    if (iplayerLevel >= *g_011d0c60.Int())
    {
        if (g_005a58c0_tlsFlag)
            _DebugLog("Player already at maximum level.");

        return true;
    }

    icurrentXP =
        reinterpret_cast<PlayerStatAccess*>(reinterpret_cast<unsigned char*>(_g_thePlayer) + 0xa4)->GetStat(0x18);
    inextThreshold = ActorValueUtility::ConvertActorValue(iplayerLevel + 1);
    afReturnValue = inextThreshold - icurrentXP;

    if (g_005a58c0_tlsFlag)
        _DebugLog("GetXPForNextLevel >> %.2f", afReturnValue);

    return true;
}
}  // namespace fnv_005a58c0

namespace fnv_005a59a0 {
struct FUN_0055d520_shell
{
    char* FUN_0055d520();
};

struct FUN_005a59a0_tls
{
    unsigned char padding[0x268];
    unsigned char value;
};

extern __declspec(thread) FUN_005a59a0_tls FUN_005a59a0_tls_data;

void __cdecl _DebugLog(const char* format, const char* value);

struct FUN_005a59a0_actor_view
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual bool GetIgnoreCrime() = 0;
};

// Sets afReturnValue to 1.0 if apRefObject is an Actor whose GetIgnoreCrime is true, logs the result, and returns true.
// @fnv 0x005a59a0
bool __cdecl FUN_005a59a0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pactor;

    afReturnValue = 0.0;

    if (apRefObject != 0 && apRefObject->IsActor())
    {
        pactor = reinterpret_cast<Actor*>(apRefObject);
        if (reinterpret_cast<FUN_005a59a0_actor_view*>(pactor)->GetIgnoreCrime())
            afReturnValue = 1.0;
    }

    if (FUN_005a59a0_tls_data.value)
    {
        if (afReturnValue > 0.0)
            _DebugLog("%s is ignoring crime", reinterpret_cast<FUN_0055d520_shell*>(apRefObject)->FUN_0055d520());
        else
            _DebugLog("%s is not ignoring crime", reinterpret_cast<FUN_0055d520_shell*>(apRefObject)->FUN_0055d520());
    }

    return true;
}
}  // namespace fnv_005a59a0

struct FNVPosition3
{
    float x;
    float y;
    float z;
};
struct FNVPositionReference
{
    void** virtualFunctions;
};
typedef void(__thiscall* FNVReadPosition)(FNVPositionReference*, FNVPosition3*);
extern __declspec(thread) unsigned char gTracePositionConditions;
extern void __cdecl LogPositionCondition(const char* message, ...);

// @fnv 0x0059c230
bool __cdecl FUN_0059c230(FNVPositionReference* reference, int coordinate, void* unused, double& result)
{
    int iCoordinate = coordinate;
    if (reference != 0)
    {
        FNVPosition3 position;
        (reinterpret_cast<FNVReadPosition>(reference->virtualFunctions[92]))(reference, &position);
        switch (iCoordinate)
        {
        case 'X':
            result = position.x;
            break;
        case 'Y':
            result = position.y;
            break;
        case 'Z':
            result = position.z;
            break;
        }
        if (gTracePositionConditions)
            LogPositionCondition("GetStartingPos: %c >> %0.2f", iCoordinate, result);
    }
    return true;
}

void DebugLog(const char* fmt, ...);

struct AudioTlsState
{
    int unk000, unk001, unk002, unk003, unk004, unk005, unk006, unk007;
    int unk008, unk009, unk010, unk011, unk012, unk013, unk014, unk015;
    int unk016, unk017, unk018, unk019, unk020, unk021, unk022, unk023;
    int unk024, unk025, unk026, unk027, unk028, unk029, unk030, unk031;
    int unk032, unk033, unk034, unk035, unk036, unk037, unk038, unk039;
    int unk040, unk041, unk042, unk043, unk044, unk045, unk046, unk047;
    int unk048, unk049, unk050, unk051, unk052, unk053, unk054, unk055;
    int unk056, unk057, unk058, unk059, unk060, unk061, unk062, unk063;
    int unk064, unk065, unk066, unk067, unk068, unk069, unk070, unk071;
    int unk072, unk073, unk074, unk075, unk076, unk077, unk078, unk079;
    int unk080, unk081, unk082, unk083, unk084, unk085, unk086, unk087;
    int unk088, unk089, unk090, unk091, unk092, unk093, unk094, unk095;
    int unk096, unk097, unk098, unk099, unk100, unk101, unk102, unk103;
    int unk104, unk105, unk106, unk107, unk108, unk109, unk110, unk111;
    int unk112, unk113, unk114, unk115, unk116, unk117, unk118, unk119;
    int unk120, unk121, unk122, unk123, unk124, unk125, unk126, unk127;
    int unk128, unk129, unk130, unk131, unk132, unk133, unk134, unk135;
    int unk136, unk137, unk138, unk139, unk140, unk141, unk142, unk143;
    int unk144, unk145, unk146, unk147, unk148, unk149, unk150, unk151;
    int unk152, unk153;
    bool bDebugOutput;
};

extern __declspec(thread) AudioTlsState g_threadData;

// Sets result to 0.0, logs an unimplemented GetDisease message when thread debug output is enabled, and returns true.
// @fnv 0x0059d250
bool __cdecl FUN_0059d250(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (g_threadData.bDebugOutput)
    {
        DebugLog("UNIMPLEMENTED: GetDisease >> %0.2f", result);
    }
    return true;
}

extern __declspec(thread) bool g_bShowConditionDebug;
void __cdecl DebugLog(char const*, ...);
struct TESBipedModelForm
{
    bool FUN_0047c850(void);
};

// @fnv 0x0059d2a0
bool __cdecl FUN_0059d2a0(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor() && reinterpret_cast<TESBipedModelForm*>(reference)->FUN_0047c850())
    {
        result = 1.0;
    }
    if (g_bShowConditionDebug)
    {
        DebugLog("GetVampire >> %0.2f", result);
    }
    return true;
}

struct SkyState
{
    bool FUN_0059ea80();
};
SkyState* __cdecl FUN_0046dd00();
extern __declspec(thread) unsigned char tlsBytes[];
extern const char str_010351ec[];
void __cdecl FUN_00703c00(const char*, double);
// Reads the sky state, writes 1.0 or 0.0 to output depending on FUN_0059ea80, logs it when tlsBytes[0x268] is set, and returns true.
// @fnv 0x0059ea10
bool __cdecl FUN_0059ea10(int first, int second, int third, double* output)
{
    SkyState* sky = FUN_0046dd00();
    *output = sky->FUN_0059ea80() ? 1.0f : 0.0f;
    if (tlsBytes[0x268])
        FUN_00703c00(str_010351ec, *output);
    return true;
}

struct FUN_00401170_Mode
{
    unsigned int __thiscall FUN_00401170();
};
struct FUN_0059ecc0_Ref
{
    FUN_00401170_Mode* __thiscall FUN_007af430();
};
extern __declspec(thread) unsigned char traceState[];
extern const char DAT_01035260[];
void __cdecl FUN_00703c00(const char* text, double result);
// Sets result to 1.0 when reference's mode equals 0x2b, logs the result if traceState[0x268] is set, and returns true.
// @fnv 0x0059ecc0
bool __cdecl FUN_0059ecc0(FUN_0059ecc0_Ref* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference != 0)
    {
        if (reference->FUN_007af430()->FUN_00401170() == 0x2b)
        {
            result = 1.0;
        }
    }
    if (traceState[0x268] != 0)
    {
        FUN_00703c00(DAT_01035260, result);
    }
    return true;
}

class DispositionActor : public MobileObject
{
  public:
    virtual void Unk_C1(void);
    virtual void Unk_C2(void);
    virtual void Unk_C3(void);
    virtual void Unk_C4(void);
    virtual void Unk_C5(void);
    virtual void Unk_C6(void);
    virtual void Unk_C7(void);
    virtual void Unk_C8(void);
    virtual void Unk_C9(void);
    virtual void Unk_CA(void);
    virtual void Unk_CB(void);
    virtual void Unk_CC(void);
    virtual void Unk_CD(void);
    virtual void Unk_CE(void);
    virtual void Unk_CF(void);
    virtual void Unk_D0(void);
    virtual int GetDisposition(DispositionActor* target, int unk);
    const char* GetFullName();
};

void DebugLog(const char* fmt, ...);

extern __declspec(thread) bool bDebugConditions;

DispositionActor* pLastDispositionActor;
DispositionActor* pLastDispositionTarget;
float fLastDisposition;

// Computes the disposition of reference toward arg1 when both are actors, caching the last actor/target pair, and logs it when bDebugConditions is set.
// @fnv 0x0059fdb0
bool __cdecl FUN_0059fdb0(TESObjectREFR* reference, void* apTargetRef, void* apUnused, double& result)
{
    result = 0.0;
    DispositionActor* actor = 0;
    if (reference && reference->IsActor())
        actor = (DispositionActor*)reference;
    TESObjectREFR* targetRef7 = (TESObjectREFR*)apTargetRef;
    DispositionActor* target = 0;
    if (targetRef7 && targetRef7->IsActor())
        target = (DispositionActor*)targetRef7;
    if (actor && target)
    {
        if (actor == pLastDispositionActor && target == pLastDispositionTarget)
        {
            result = fLastDisposition;
        }
        else
        {
            result = actor->GetDisposition(target, 0);
            pLastDispositionTarget = target;
            pLastDispositionActor = actor;
            fLastDisposition = result;
        }
        if (bDebugConditions)
            DebugLog("%.20s disposition to %.20s is %.1f", actor->GetFullName(), target->GetFullName(), result);
    }
    return true;
}

namespace fnv_005a0ab0 {
extern __declspec(thread) bool tls_conditionEcho;

struct P01ObjA
{
    TESForm* GetNext();
};

struct FUN_008d85e0_Obj
{
    int GetUnk15C();
};

int __fastcall FNV_GetFormType(TESForm* form);
void __cdecl DebugLog(char const* fmt, ...);

// @fnv 0x005a0ab0
bool __cdecl IsWeaponSkillType(TESObjectREFR* reference, void* aiSkillType, void* apUnused, double& result)
{
    TESForm* weapon = 0;
    result = 0.0;
    if (FNV_GetFormType(reinterpret_cast<P01ObjA*>(reference)->GetNext()) == 40)
    {
        weapon = reinterpret_cast<P01ObjA*>(reference)->GetNext();
    }
    if (weapon == 0 && reinterpret_cast<int>(aiSkillType) == 45)
    {
        result = 1.0;
    }
    else if (weapon == 0)
    {
        return false;
    }
    if (weapon != 0 && reinterpret_cast<int>(aiSkillType) == reinterpret_cast<FUN_008d85e0_Obj*>(weapon)->GetUnk15C())
    {
        result = 1.0;
    }
    if (tls_conditionEcho)
    {
        DebugLog("Is Weapon Skill Type >> %0.2f", result);
    }
    return true;
}
}  // namespace fnv_005a0ab0

struct RefOps
{
    TESForm* __thiscall FUN_007af430();
};
struct FormOps
{
    unsigned int __thiscall FUN_00401170();
};
struct ActorOps
{
    TESClass* __thiscall FUN_00502430();
};
struct ClassOps
{
    bool __thiscall FUN_005f6e60();
};
extern __declspec(thread) bool tls_conditionEcho;
void __cdecl FUN_00703c00(const char* format, ...);
// Sets result to 1.0 when the reference's base form is type 42 and its class passes a check, then optionally logs the value and returns true.
// @fnv 0x005a10b0
bool __cdecl FUN_005a10b0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference)
    {
        TESForm* actorBase = 0;
        if (((FormOps*)((RefOps*)reference)->FUN_007af430())->FUN_00401170() == 42)
            actorBase = ((RefOps*)reference)->FUN_007af430();
        if (actorBase)
        {
            if (((ActorOps*)actorBase)->FUN_00502430() &&
                ((ClassOps*)((ActorOps*)actorBase)->FUN_00502430())->FUN_005f6e60())
                result = 1.0;
        }
    }
    if (tls_conditionEcho)
        FUN_00703c00("Is Guard >> %0.2f", result);
    return true;
}

extern __declspec(thread) bool bPrintConditionDebug;
void __cdecl DebugLog(char const* fmt, ...);
bool __cdecl FUN_00578400(int state);

class FlameObjectLocal
{
  public:
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual int GetFlameState()
    {
        return 0;
    }
};

class SourceBaseLocal
{
  public:
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}
    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}
    virtual void vfB0()
    {}
    virtual void vfB4()
    {}
    virtual void vfB8()
    {}
    virtual void vfBC()
    {}
    virtual void vfC0()
    {}
    virtual void vfC4()
    {}
    virtual void vfC8()
    {}
    virtual void vfCC()
    {}
    virtual void vfD0()
    {}
    virtual void vfD4()
    {}
    virtual void vfD8()
    {}
    virtual void vfDC()
    {}
    virtual void vfE0()
    {}
    virtual void vfE4()
    {}
    virtual void vfE8()
    {}
    virtual void vfEC()
    {}
    virtual void vfF0()
    {}
    virtual void vfF4()
    {}
    virtual void vfF8()
    {}
    virtual void vfFC()
    {}
    virtual void vf100()
    {}
    virtual void vf104()
    {}
    virtual void vf108()
    {}
    virtual void vf10C()
    {}
    virtual void vf110()
    {}
    virtual void vf114()
    {}
    virtual void vf118()
    {}
    virtual void vf11C()
    {}
    virtual void vf120()
    {}
    virtual void vf124()
    {}
    virtual void vf128()
    {}
    virtual void vf12C()
    {}
    virtual void vf130()
    {}
    virtual void vf134()
    {}
    virtual void vf138()
    {}
    virtual void vf13C()
    {}
    virtual void vf140()
    {}
    virtual void vf144()
    {}
    virtual void vf148()
    {}
    virtual void vf14C()
    {}
    virtual void vf150()
    {}
    virtual void vf154()
    {}
    virtual void vf158()
    {}
    virtual void vf15C()
    {}
    virtual void vf160()
    {}
    virtual void vf164()
    {}
    virtual void vf168()
    {}
    virtual void vf16C()
    {}
    virtual void vf170()
    {}
    virtual void vf174()
    {}
    virtual void vf178()
    {}
    virtual void vf17C()
    {}
    virtual void vf180()
    {}
    virtual void vf184()
    {}
    virtual void vf188()
    {}
    virtual void vf18C()
    {}
    virtual void vf190()
    {}
    virtual void vf194()
    {}
    virtual void vf198()
    {}
    virtual void vf19C()
    {}
    virtual void vf1A0()
    {}
    virtual void vf1A4()
    {}
    virtual void vf1A8()
    {}
    virtual void vf1AC()
    {}
    virtual void vf1B0()
    {}
    virtual void vf1B4()
    {}
    virtual void vf1B8()
    {}
    virtual void vf1BC()
    {}
    virtual void vf1C0()
    {}
    virtual void vf1C4()
    {}
    virtual void vf1C8()
    {}
    virtual void vf1CC()
    {}
};

class SourceLocal : public SourceBaseLocal
{
  public:
    virtual FlameObjectLocal* GetFlameObject();
};

FlameObjectLocal* SourceLocal::GetFlameObject()
{
    return 0;
}

// Sets *result to 1.0 if source has a flame object whose state passes FUN_00578400, else 0.0, logs it when debug printing is on, and returns true.
// @fnv 0x005a1b80
bool __cdecl FUN_005a1b80(SourceLocal* source, unsigned int arg1, unsigned int arg2, double* result)
{
    *result = 0.0;
    if (source != 0)
    {
        if (source->GetFlameObject() != 0)
        {
            FlameObjectLocal* flame = source->GetFlameObject();
            if (flame != 0)
            {
                float value;
                if (FUN_00578400(flame->GetFlameState()))
                {
                    value = 1.0f;
                }
                else
                {
                    value = 0.0f;
                }
                *result = value;
            }
        }
    }
    if (bPrintConditionDebug)
    {
        DebugLog("HasFlames >> %0.2f", *result);
    }
    return true;
}

namespace fnv_005a1e70 {
struct PlayerCharacter
{
    bool FUN_00953f60();
};
void __cdecl _DebugLog(const char* format, ...);
__declspec(thread) bool g_DebugLogFlag;
// Sets result to 1.0 if the player is a murderer, otherwise 0.0, logs it when debug logging is enabled, and returns true.
// @fnv 0x005a1e70
bool FUN_005a1e70(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    result = ((PlayerCharacter*)g_thePlayer)->FUN_00953f60() ? 1.0f : 0.0f;
    if (g_DebugLogFlag)
        _DebugLog("IsPlayerAMurderer >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a1e70

namespace fnv_005a2050 {
struct FUN_005a20b0_Standin
{
    int GetField6dc();
};
extern "C" void __cdecl FUN_00703c00(const char*, ...);
extern const char str_010359b4[];
__declspec(thread) unsigned char g_tlsFlag;

// Sets result to the value returned by the player's GetField6dc and logs it when g_tlsFlag is set, then returns true.
// @fnv 0x005a2050
bool __cdecl FUN_005a2050(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    result = (double)((FUN_005a20b0_Standin*)g_thePlayer)->GetField6dc();
    if (g_tlsFlag)
        FUN_00703c00(str_010359b4, result);
    return true;
}
}  // namespace fnv_005a2050

bool __cdecl HotkeyWheelProbeA();
void __cdecl _DebugLog(const char* apFormat, ...);
__declspec(thread) unsigned char g_tlsFlags[0x269];
// Sets result to 1.0 if HotkeyWheelProbeA() is true, otherwise 0.0, logs it when g_tlsFlags[0x268] is set, and returns true.
// @fnv 0x005a37b0
bool __cdecl FUN_005a37b0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    result = HotkeyWheelProbeA() ? 1.0f : 0.0f;
    if (g_tlsFlags[0x268])
        _DebugLog("IsXBox >> %1.0f", result);
    return true;
}

namespace fnv_005a3b20 {
class BGSAction;

class PlayerCharacter
{
  public:
    bool HasAction(void* action);
};

extern PlayerCharacter* g_thePlayer;
extern __declspec(thread) bool tls_conditionEcho;

void DebugLog(const char* fmt, ...);

// Sets result to 0.0, then stores g_thePlayer->HasAction(action) into result, logs it if tls_conditionEcho is set, and returns true.
// @fnv 0x005a3b20
bool __cdecl FUN_005a3b20(TESObjectREFR* reference, void* pAction, void* pUnused, double& result)
{
    result = 0.0;
    void* action = pAction;
    result = g_thePlayer->HasAction(action);
    if (tls_conditionEcho)
    {
        DebugLog("IsActionInList >> %0.2f", result);
    }
    return true;
}
}  // namespace fnv_005a3b20

struct HitDataBoolFlag : BooleanFloatQuery
{
    bool Flag(unsigned int);
};

struct EssentialVirtualActor
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
    virtual bool IsEssentialActor();
};

// @fnv 0x005a3c90
bool __cdecl FUN_005a3c90(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference)
    {
        if (reinterpret_cast<EssentialVirtualActor*>(reference)->IsEssentialActor())
        {
            Actor* actor = reinterpret_cast<Actor*>(reference);
            if (actor->RefreshActorRuntimeData())
            {
                result = reinterpret_cast<HitDataBoolFlag*>(actor->RefreshActorRuntimeData())->Flag(4) ? 1.0f : 0.0f;
            }
        }
    }
    return true;
}

struct MeasuredValue
{
    unsigned int FUN_005a4320();
};
typedef bool(__thiscall* EligibilityMethod)(void*);
typedef MeasuredValue*(__thiscall* ValueMethod)(void*);
union ExtendedValue
{
    __int64 signedValue;
    struct
    {
        unsigned int low;
        unsigned int high;
    };
};
// Writes 0.0 to result, then if object passes its eligibility check and returns a value, stores that value's count as a double in result; always returns true.
// @fnv 0x005a42b0
bool __cdecl FUN_005a42b0(void* object, void* unusedContext, void* unusedTarget, double* result)
{
    *result = 0.0;
    if (object && ((EligibilityMethod)(*(void***)object)[64])(object))
    {
        void* reference = object;
        MeasuredValue* item = ((ValueMethod)(*(void***)reference)[254])(reference);
        if (item)
        {
            ExtendedValue extCount;
            extCount.low = item->FUN_005a4320();
            extCount.high = 0;
            *result = static_cast<double>(extCount.signedValue);
        }
    }
    return true;
}

namespace fnv_005a4540 {
extern __declspec(thread) unsigned char DAT_tls_0268[0x269];
extern "C" void __cdecl FUN_00703c00(const char* format, ...);
extern char str_01035ee4[];

// Sets result to 0.0, calls Unk_B6 on the reference if it is a mobile object, and logs result when the TLS flag is set; returns true.
// @fnv 0x005a4540
bool __cdecl FUN_005a4540(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    if (reference->IsMobileObject())
    {
        MobileObject* mobile = static_cast<MobileObject*>(reference);
        mobile->Unk_B6();
    }
    if (DAT_tls_0268[0x268])
    {
        FUN_00703c00(str_01035ee4, result);
    }
    return true;
}
}  // namespace fnv_005a4540

extern "C" void __cdecl FUN_00703c00(const char*, int);
extern "C" const char DAT_01035f64[];
struct RuntimeState
{
    unsigned char flag;
};
extern __declspec(thread) RuntimeState gRuntimeState;
struct Actor005a4820
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
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
    virtual unsigned char CheckActivity();
    unsigned char FUN_00566950();
};
// Sets *out to 0.0, then to 1.0 if the actor is active and FUN_00566950 returns true; logs *out when gRuntimeState flag is set; returns 1.
// @fnv 0x005a4820
unsigned char __cdecl FUN_005a4820(Actor005a4820* actor, unsigned int action, unsigned int flags, double* out)
{
    *out = 0.0;
    if (actor && actor->CheckActivity())
    {
        Actor005a4820* p = actor;
        if (p->FUN_00566950())
            *out = 1.0;
        if (*((unsigned char*)&gRuntimeState + 0x268))
            FUN_00703c00(DAT_01035f64, (int)*out);
    }
    return 1;
}

class FUN_0041cf00_shell
{
  public:
    void* FUN_0041cf00();
};

extern bool __fastcall _ref_008256d0(void*);
void DebugLog(const char*, ...);
extern __declspec(thread) bool g_bShowConditionDebug;

// Sets result to 1.0 when the reference is an actor whose extra data passes FUN_0041cf00 and fails _ref_008256d0, logging the outcome when condition debug is on.
// @fnv 0x005a4930
bool __cdecl FUN_005a4930(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        TESObjectREFR* actor = reference;
        if (((FUN_0041cf00_shell*)actor->GetExtraData())->FUN_0041cf00() &&
            !_ref_008256d0(((FUN_0041cf00_shell*)actor->GetExtraData())->FUN_0041cf00()))
        {
            result = 1.0;
        }

        if (g_bShowConditionDebug)
        {
            if (result != 0.0)
            {
                DebugLog("This actor is an enemy of player because of crime");
            }
            else
            {
                DebugLog("This actor is not an enemy of player because of crime");
            }
        }
    }

    return true;
}

namespace fnv_005a50f0 {
struct TlsData
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
    unsigned char debugLogging;
};
extern __declspec(thread) TlsData g_tls;

class BaseProcess
{
  public:
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
    virtual void Unk_00A();
    virtual void Unk_00B();
    virtual void Unk_00C();
    virtual void Unk_00D();
    virtual void Unk_00E();
    virtual void Unk_00F();
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
    virtual void Unk_01A();
    virtual void Unk_01B();
    virtual void Unk_01C();
    virtual void Unk_01D();
    virtual void Unk_01E();
    virtual void Unk_01F();
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
    virtual void Unk_02A();
    virtual void Unk_02B();
    virtual void Unk_02C();
    virtual void Unk_02D();
    virtual void Unk_02E();
    virtual void Unk_02F();
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
    virtual void Unk_03A();
    virtual void Unk_03B();
    virtual void Unk_03C();
    virtual void Unk_03D();
    virtual void Unk_03E();
    virtual void Unk_03F();
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
    virtual void Unk_04A();
    virtual void Unk_04B();
    virtual void Unk_04C();
    virtual void Unk_04D();
    virtual void Unk_04E();
    virtual void Unk_04F();
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
    virtual void Unk_05A();
    virtual void Unk_05B();
    virtual void Unk_05C();
    virtual void Unk_05D();
    virtual void Unk_05E();
    virtual void Unk_05F();
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
    virtual void Unk_06A();
    virtual void Unk_06B();
    virtual void Unk_06C();
    virtual void Unk_06D();
    virtual void Unk_06E();
    virtual void Unk_06F();
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
    virtual void Unk_07A();
    virtual void Unk_07B();
    virtual void Unk_07C();
    virtual void Unk_07D();
    virtual void Unk_07E();
    virtual void Unk_07F();
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
    virtual void Unk_08A();
    virtual void Unk_08B();
    virtual void Unk_08C();
    virtual void Unk_08D();
    virtual void Unk_08E();
    virtual void Unk_08F();
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
    virtual void Unk_09A();
    virtual void Unk_09B();
    virtual void Unk_09C();
    virtual void Unk_09D();
    virtual void Unk_09E();
    virtual void Unk_09F();
    virtual void Unk_0A0();
    virtual void Unk_0A1();
    virtual void Unk_0A2();
    virtual void Unk_0A3();
    virtual void Unk_0A4();
    virtual void Unk_0A5();
    virtual void Unk_0A6();
    virtual void Unk_0A7();
    virtual void Unk_0A8();
    virtual void Unk_0A9();
    virtual void Unk_0AA();
    virtual void Unk_0AB();
    virtual void Unk_0AC();
    virtual void Unk_0AD();
    virtual void Unk_0AE();
    virtual void Unk_0AF();
    virtual void Unk_0B0();
    virtual void Unk_0B1();
    virtual void Unk_0B2();
    virtual void Unk_0B3();
    virtual void Unk_0B4();
    virtual void Unk_0B5();
    virtual void Unk_0B6();
    virtual void Unk_0B7();
    virtual void Unk_0B8();
    virtual void Unk_0B9();
    virtual void Unk_0BA();
    virtual void Unk_0BB();
    virtual void Unk_0BC();
    virtual void Unk_0BD();
    virtual void Unk_0BE();
    virtual void Unk_0BF();
    virtual void Unk_0C0();
    virtual void Unk_0C1();
    virtual void Unk_0C2();
    virtual void Unk_0C3();
    virtual void Unk_0C4();
    virtual void Unk_0C5();
    virtual void Unk_0C6();
    virtual void Unk_0C7();
    virtual void Unk_0C8();
    virtual void Unk_0C9();
    virtual void Unk_0CA();
    virtual void Unk_0CB();
    virtual void Unk_0CC();
    virtual void Unk_0CD();
    virtual void Unk_0CE();
    virtual void Unk_0CF();
    virtual void Unk_0D0();
    virtual void Unk_0D1();
    virtual void Unk_0D2();
    virtual void Unk_0D3();
    virtual void Unk_0D4();
    virtual void Unk_0D5();
    virtual void Unk_0D6();
    virtual void Unk_0D7();
    virtual void Unk_0D8();
    virtual void Unk_0D9();
    virtual void Unk_0DA();
    virtual void Unk_0DB();
    virtual void Unk_0DC();
    virtual void Unk_0DD();
    virtual void Unk_0DE();
    virtual void Unk_0DF();
    virtual void Unk_0E0();
    virtual void Unk_0E1();
    virtual void Unk_0E2();
    virtual void Unk_0E3();
    virtual void Unk_0E4();
    virtual void Unk_0E5();
    virtual void Unk_0E6();
    virtual void Unk_0E7();
    virtual void Unk_0E8();
    virtual void Unk_0E9();
    virtual void Unk_0EA();
    virtual void Unk_0EB();
    virtual void Unk_0EC();
    virtual void Unk_0ED();
    virtual void Unk_0EE();
    virtual void Unk_0EF();
    virtual void Unk_0F0();
    virtual void Unk_0F1();
    virtual void Unk_0F2();
    virtual void Unk_0F3();
    virtual void Unk_0F4();
    virtual void Unk_0F5();
    virtual void Unk_0F6();
    virtual void Unk_0F7();
    virtual void Unk_0F8();
    virtual void Unk_0F9();
    virtual void Unk_0FA();
    virtual void Unk_0FB();
    virtual void Unk_0FC();
    virtual void Unk_0FD();
    virtual void Unk_0FE();
    virtual void Unk_0FF();
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
    virtual void Unk_10A();
    virtual void Unk_10B();
    virtual void Unk_10C();
    virtual void Unk_10D();
    virtual void Unk_10E();
    virtual void Unk_10F();
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
    virtual void Unk_11A();
    virtual void Unk_11B();
    virtual void Unk_11C();
    virtual void Unk_11D();
    virtual void Unk_11E();
    virtual void Unk_11F();
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
    virtual void Unk_12A();
    virtual void Unk_12B();
    virtual void Unk_12C();
    virtual void Unk_12D();
    virtual void Unk_12E();
    virtual void Unk_12F();
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
    virtual void Unk_13A();
    virtual void Unk_13B();
    virtual void Unk_13C();
    virtual void Unk_13D();
    virtual void Unk_13E();
    virtual void Unk_13F();
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
    virtual void Unk_14A();
    virtual void Unk_14B();
    virtual void Unk_14C();
    virtual void Unk_14D();
    virtual void Unk_14E();
    virtual void Unk_14F();
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
    virtual void Unk_15A();
    virtual void Unk_15B();
    virtual void Unk_15C();
    virtual void Unk_15D();
    virtual void Unk_15E();
    virtual void Unk_15F();
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
    virtual void Unk_16A();
    virtual void Unk_16B();
    virtual void Unk_16C();
    virtual void Unk_16D();
    virtual void Unk_16E();
    virtual void Unk_16F();
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
    virtual void Unk_17A();
    virtual void Unk_17B();
    virtual void Unk_17C();
    virtual void Unk_17D();
    virtual void Unk_17E();
    virtual void Unk_17F();
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
    virtual void Unk_18A();
    virtual void Unk_18B();
    virtual void Unk_18C();
    virtual void Unk_18D();
    virtual void Unk_18E();
    virtual void Unk_18F();
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
    virtual void Unk_19A();
    virtual void Unk_19B();
    virtual void Unk_19C();
    virtual void Unk_19D();
    virtual void Unk_19E();
    virtual void Unk_19F();
    virtual void Unk_1A0();
    virtual void Unk_1A1();
    virtual void Unk_1A2();
    virtual void Unk_1A3();
    virtual void Unk_1A4();
    virtual void Unk_1A5();
    virtual void Unk_1A6();
    virtual void Unk_1A7();
    virtual void Unk_1A8();
    virtual void Unk_1A9();
    virtual void Unk_1AA();
    virtual void Unk_1AB();
    virtual void Unk_1AC();
    virtual void Unk_1AD();
    virtual void Unk_1AE();
    virtual void Unk_1AF();
    virtual void Unk_1B0();
    virtual void Unk_1B1();
    virtual void Unk_1B2();
    virtual void Unk_1B3();
    virtual void Unk_1B4();
    virtual void Unk_1B5();
    virtual void Unk_1B6();
    virtual void Unk_1B7();
    virtual void Unk_1B8();
    virtual void Unk_1B9();
    virtual void Unk_1BA();
    virtual void Unk_1BB();
    virtual void Unk_1BC();
    virtual void Unk_1BD();
    virtual void Unk_1BE();
    virtual void Unk_1BF();
    virtual void Unk_1C0();
    virtual void Unk_1C1();
    virtual void Unk_1C2();
    virtual void Unk_1C3();
    virtual void Unk_1C4();
    virtual void Unk_1C5();
    virtual void Unk_1C6();
    virtual void Unk_1C7();
    virtual void Unk_1C8();
    virtual void Unk_1C9();
    virtual void Unk_1CA();
    virtual void Unk_1CB();
    virtual void Unk_1CC();
    virtual void Unk_1CD();
    virtual void Unk_1CE();
    virtual void Unk_1CF();
    virtual void Unk_1D0();
    virtual void Unk_1D1();
    virtual void Unk_1D2();
    virtual void Unk_1D3();
    virtual void Unk_1D4();
    virtual void Unk_1D5();
    virtual void Unk_1D6();
    virtual double Unk_75C();
    virtual void Unk_760();
    virtual double Unk_764();
    virtual void Unk_768();
    virtual double Unk_76C();
};

class ActorS : public MobileObject
{
  public:
    BaseProcess* GetCurrentProcess() const;
};

class MobileObject_Shell
{
  public:
    const char* GetFullName();
};

void __cdecl DebugLog(const char* fmt, ...);

// @fnv 0x005a50f0
bool __cdecl FUN_005a50f0(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        ActorS* actor = (ActorS*)reference;
        result = 0.0;
        if (actor->GetCurrentProcess())
        {
            result = actor->GetCurrentProcess()->Unk_76C() + actor->GetCurrentProcess()->Unk_75C() +
                     actor->GetCurrentProcess()->Unk_764();
        }
        if (g_tls.debugLogging)
        {
            DebugLog("%s radiation level is %.2f", ((MobileObject_Shell*)reference)->GetFullName(), result);
        }
    }
    return true;
}
}  // namespace fnv_005a50f0

extern PlayerCharacter* g_thePlayer;
extern __declspec(thread) bool tls_conditionEcho;

namespace ActorValue {
bool __cdecl IsSkill(Index aeSkill);
}
void __cdecl DebugLog(char const* fmt, ...);

class PC7d
{
  public:
    TESClass* GetClass();
};

// Sets result to 1.0 when reference is an actor and the given skill is one of the player's tag skills, then logs the result if tls_conditionEcho is set.
// @fnv 0x005a5e90
bool __cdecl FUN_005a5e90(TESObjectREFR* reference, void* pSkillArg, void* pUnused, double& result)
{
    result = 0.0;
    if (reference && reference->IsActor())
    {
        void* skillArg = pSkillArg;
        TESObjectREFR* ref = reference;
        ActorValue::Index skill = static_cast<ActorValue::Index>(reinterpret_cast<int>(skillArg));
        if (ActorValue::IsSkill(skill) && reinterpret_cast<PC7d*>(g_thePlayer)->GetClass()->IsTagSkill(skill))
        {
            result = 1.0;
        }
    }
    if (tls_conditionEcho)
    {
        DebugLog("IsPlayerTagSkill >> %.0f", result);
    }
    return true;
}

extern char* DAT_011dea3c;
extern double DAT_010290b0;
unsigned int __fastcall FUN_005a6260(char*);
extern "C" void* __fastcall FUN_006815c0(void*);
extern "C" unsigned int __fastcall FUN_0084e3a0(void*);
extern "C" void* __fastcall FUN_00504e60(void*);
extern "C" void* __fastcall FUN_00726070(void*);
struct Record
{
    unsigned int formId;
    int threshold;
};
struct EntryHolder
{
    Record* record;
};
struct SpellData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, multiplier;
};
// Walks the entry list, matches the subject's form ID, and stores the highest tier whose scaled multiplier stays within the record threshold.
// @fnv 0x005a6170
bool __cdecl FUN_005a6170(int unused, void* subject, int unused2, double* result)
{
    void* target = subject;
    if (target != 0)
    {
        void* current = (void*)FUN_005a6260(DAT_011dea3c);
        while (current != 0 && ((EntryHolder*)FUN_006815c0(current))->record != 0)
        {
            if (((EntryHolder*)FUN_006815c0(current))->record->formId == FUN_0084e3a0(target))
            {
                int limit;
                {
                    int multiplier = ((SpellData*)FUN_00504e60(target))->multiplier;
                    limit = ((EntryHolder*)FUN_006815c0(current))->record->threshold;
                    *result = 0.0;
                    for (int i = 0; i < 4; i++)
                    {
                        if ((double)multiplier * ((double)(i + 1) * DAT_010290b0) <= (double)limit)
                        {
                            *result = (double)(i + 1);
                        }
                    }
                }
            }
            current = FUN_00726070(current);
        }
    }
    else
    {
        return false;
    }
    return true;
}

struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
struct Pt3
{
    float x, y, z;
};
class RefA
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
    virtual void GetStartingAngle(Pt3*);
};
// Converts the starting angle of a reference on the given axis from radians to degrees and stores it in result.
// @fnv 0x0059c2d0
bool FUN_0059c2d0(RefA* reference, void* acAxis, void* apUnused, double& afAngle)
{
    int iAxis = (int)acAxis;
    if (reference)
    {
        Pt3 kAngle;
        reference->GetStartingAngle(&kAngle);
        switch (iAxis)
        {
        case 'X':
            afAngle = kAngle.x * 57.2957763671875;
            break;
        case 'Y':
            afAngle = kAngle.y * 57.2957763671875;
            break;
        case 'Z':
            afAngle = kAngle.z * 57.2957763671875;
            break;
        }
        if (DAT_0126fd98.bDebug)
            FUN_00703c00("GetStartingAngle: %c >> %0.2f", iAxis, afAngle);
    }
    return true;
}

namespace fnv_0059c680 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class AVOwner
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
    virtual float GetActorValue(int);
};
class BaseV
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
    AVOwner kOwner;
};
const char* GetActorValueName(int);
class ActorV
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
    virtual bool IsActor();
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
    AVOwner kAVOwner;
    bool FUN_00440da0();
    BaseV* FUN_004181e0();
};
// Gets the selected actor value from the actor or returned owner, stores it in result, and logs it when bDebug is set.
// @fnv 0x0059c680
bool FUN_0059c680(ActorV* apActor, void* aiActorValue, void* apUnused, double& afValue)
{
    int eAV = (int)aiActorValue;
    ActorV* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    if (pActor)
    {
        if (!pActor->FUN_00440da0())
            afValue = pActor->kAVOwner.GetActorValue(eAV);
        else
        {
            AVOwner* pOwner = &pActor->FUN_004181e0()->kOwner;
            afValue = pOwner->GetActorValue(eAV);
        }
        if (DAT_0126fd98.bDebug)
            FUN_00703c00("GetActorValue: %s >> %0.2f", GetActorValueName(eAV), afValue);
    }
    return true;
}
}  // namespace fnv_0059c680

namespace fnv_0059d320 {
struct TESObject
{
    TESObject* GetNext();
    int FNV_GetFormType();
};
struct Character
{
    double FUN_008d3110();
};
__declspec(thread) bool g_DebugLogEnabled;
void __cdecl _DebugLog(const char* fmt, ...);

// Returns the clothing value of a Character via FUN_008d3110 when the TESObjectREFR is a form type 0x2a, otherwise leaves afReturnValue unchanged.
// @fnv 0x0059d320
bool __cdecl FUN_0059d320(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Character* pactor = 0;
    if (apRefObject)
    {
        if (reinterpret_cast<TESObject*>(reinterpret_cast<TESObject*>(apRefObject)->GetNext())->FNV_GetFormType() ==
            0x2a)
            pactor = reinterpret_cast<Character*>(apRefObject);
    }
    if (pactor)
        afReturnValue = pactor->FUN_008d3110();
    if (g_DebugLogEnabled)
        _DebugLog("GetClothingValue >> %0.2f", afReturnValue);
    return true;
}
}  // namespace fnv_0059d320

namespace fnv_0059ea80 {
struct FUN_0059eb40
{
    bool GetFlag();
};
struct TESWeatherEx
{
    float GetWeatherData(int a1, float a2, float a3);
};
extern float DAT_01017d00;
struct FUN_0059ea80_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_0059eb40* m_kPointA;
    FUN_0059eb40* m_kPointB;
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
    float unkF4;
    bool FUN_0059ea80();
};
// @fnv 0x0059ea80
bool FUN_0059ea80_class::FUN_0059ea80()
{
    return (m_kPointA != 0 && m_kPointA->GetFlag() &&
            unkF4 > reinterpret_cast<TESWeatherEx*>(m_kPointA)->GetWeatherData(6, 0.999000013f, 0.0f)) ||
           (m_kPointB != 0 && m_kPointB->GetFlag() &&
            unkF4 < reinterpret_cast<TESWeatherEx*>(m_kPointB)->GetWeatherData(7, 1.0f, DAT_01017d00));
}
}  // namespace fnv_0059ea80

namespace fnv_0059eb60 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class Sky
{
  public:
    float FUN_006447d0();
};
Sky* FUN_0046dd00();
// Reads the current weather percent from the Sky object, logs it when bDebug is set, and returns true.
// @fnv 0x0059eb60
bool FUN_0059eb60(void* reference, void* arg1, void* arg2, double& afPercent)
{
    afPercent = FUN_0046dd00()->FUN_006447d0();
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetCurrentWeatherPercent >> %0.2f", afPercent);
    return true;
}
}  // namespace fnv_0059eb60

namespace fnv_0059f540 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class RaceP
{
  public:
    bool FUN_0059f610();
};
class FormP
{
  public:
    int FUN_00401170();
    RaceP* FUN_004ac110();
};
class RefP
{
  public:
    FormP* FUN_007af430();
};
extern RefP* DAT_011cab1c;
extern float DAT_011cab20;
// Caches the playable-race result by reference pointer, logs it when bDebug is set, and always returns true.
// @fnv 0x0059f540
bool FUN_0059f540(RefP* reference, void* apUnused1, void* apUnused2, double& result)
{
    if (DAT_011cab1c == reference)
        result = DAT_011cab20;
    else
    {
        result = 0;
        FormP* pForm = 0;
        if (reference && reference->FUN_007af430()->FUN_00401170() == 0x2a)
            pForm = reference->FUN_007af430();
        if (pForm)
        {
            RaceP* pRace = pForm->FUN_004ac110();
            if (pRace && pRace->FUN_0059f610())
                result = 1;
        }
        DAT_011cab1c = reference;
        DAT_011cab20 = result;
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetIsPlayableRace >> %0.2f", result);
    return true;
}
}  // namespace fnv_0059f540

namespace fnv_0059f9b0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ListRes
{
  public:
    bool FUN_005f65d0();
};
class FormU
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
    virtual bool IsItem();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual const char* GetName();
    int FUN_00401170();
    ListRes* FUN_00500940(FormU**);
};
FormU* FUN_006008f0();
// Sets result to 1 if the form is the current item or the two calls on it and the current item return true; logs the result.
// @fnv 0x0059f9b0
bool FUN_0059f9b0(void* reference, void* apForm, void* apUnused, double& result)
{
    result = 0;
    FormU* pForm = (FormU*)apForm;
    if (pForm)
    {
        if (pForm->IsItem() && FUN_006008f0() == pForm)
            result = 1;
        else if (pForm->FUN_00401170() == 0x55)
        {
            FormU* pList = pForm;
            FormU* pUsed = FUN_006008f0();
            if (pList->FUN_00500940(&pUsed)->FUN_005f65d0())
                result = 1;
        }
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetIsUsedItem '%s' >> %0.2f", pForm ? pForm->GetName() : "UNKNOWN", result);
    return true;
}
}  // namespace fnv_0059f9b0

namespace fnv_005a0150 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class AVOwner
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};
class ActorV
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
    virtual bool IsActor();
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
    AVOwner kAVOwner;
};
// Stores actor value 0x12 in result for an actor and logs it when debug is enabled.
// @fnv 0x005a0150
bool FUN_005a0150(ActorV* apActor, void* aUnused1, void* aUnused2, double& result)
{
    result = 0;
    ActorV* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    if (pActor)
    {
        result = pActor->kAVOwner.GetActorValue(0x12);
        if (DAT_0126fd98.bDebug)
            FUN_00703c00("Armor Rating: %0.2f", result);
    }
    return true;
}
}  // namespace fnv_005a0150

namespace fnv_005a0e80 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ActorW
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
    virtual bool IsActor();
    bool FUN_008a6210();
};
// Checks if the given ActorW is waiting and stores the result in the output parameter, logging it in debug mode.
// @fnv 0x005a0e80
bool FUN_005a0e80(ActorW* apActor, void* pUnused1, void* pUnused2, double& result)
{
    result = 0;
    ActorW* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    if (pActor && pActor->FUN_008a6210())
        result = 1;
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("Is Waiting >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a0e80

namespace fnv_005a0f90 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class FormC
{
  public:
    int FUN_00401170();
};
class ActorC
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
    virtual bool IsActor();
};
class CrimeC
{
  public:
    bool HasMatchingCrime(ActorC*, FormC*, ActorC*, int, int, int);
};
extern CrimeC DAT_011e0e80;
// Checks if a crime exists between the actor and victim using the crime type index, storing the result in the output parameter.
// @fnv 0x005a0f90
bool FUN_005a0f90(ActorC* apActor, FormC* apVictim, void* aiCrimeType, double& result)
{
    result = 0;
    int e = (int)aiCrimeType;
    FormC* pVictim = 0;
    if (apVictim)
    {
        switch (apVictim->FUN_00401170())
        {
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x69:
            pVictim = apVictim;
        }
    }
    ActorC* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    if (pActor && pVictim)
    {
        if (e > -1 && e < 5)
        {
            if (DAT_011e0e80.HasMatchingCrime(pActor, pVictim, pActor, e, 0, -1))
                result = 1;
        }
        else
        {
            if (DAT_011e0e80.HasMatchingCrime(pActor, pVictim, pActor, -1, 0, -1))
                result = 1;
        }
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetCrime >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a0f90

namespace fnv_005a1770 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class FormY
{
  public:
    int FUN_0084e3a0();
};
class ProcY
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
    virtual FormY* GetY();
};
class ItemZ
{
  public:
    int FUN_0041ca90();
    int FUN_004fd3c0();
};
class ActorX
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
    virtual bool IsActor();
    ItemZ* FUN_009344a0();
    ProcY* FUN_008d8520();
};
// Reads a numeric value from the actor's item or procedure-related form into result and logs it when debug is enabled.
// @fnv 0x005a1770
bool FUN_005a1770(ActorX* apActor, void* apUnused1, void* apUnused2, double& result)
{
    result = -1.0;
    ActorX* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    if (pActor)
    {
        ItemZ* pItem = pActor->FUN_009344a0();
        if (pItem)
        {
            switch (pItem->FUN_0041ca90())
            {
            case 0x17: {
                ItemZ* pZ = pItem;
                result = pZ->FUN_004fd3c0();
                break;
            }
            case 0xe: {
                ProcY* pProc = pActor->FUN_008d8520();
                if (pProc)
                {
                    FormY* pForm = pProc->GetY();
                    if (pForm)
                    {
                        FormY* pF = pForm;
                        result = pF->FUN_0084e3a0();
                    }
                }
                break;
            }
            }
        }
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("Procedure >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a1770

namespace fnv_005a25f0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
struct Pt
{
    float x, y, z;
    Pt& FUN_006815c0();
};
class NodeH
{
  public:
    Pt* FUN_0043d450();
};
class LimbH
{
  public:
    Pt* FUN_0045bb80();
};
class BodyPartH
{
  public:
    int FUN_0043b230();
};
class BPDataH
{
  public:
    BodyPartH* FUN_005e5130(int);
};
class BaseH
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
    virtual BPDataH* GetBPData();
};
class RefH
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
    virtual bool IsActor();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual NodeH* Get3D();
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual Pt* GetPos();
    BaseH* FUN_004181e0();
};
LimbH* FUN_004aae30(NodeH*, int);
struct TgtH
{
    int m0;
    int m4;
    int m8;
    RefH* dst;
    int fB;
};
class VatsH
{
  public:
    int FUN_0044ddc0();
    TgtH* FUN_009c71c0();
};
extern VatsH DAT_011f2250;
extern RefH* DAT_011dea3c;
bool FUN_0066dde0(int);
// Returns the vertical height difference between the current VATS target's position and the player, using limb position when available.
// @fnv 0x005a25f0
bool FUN_005a25f0(void* reference, void* arg1, void* arg2, double& afHeight)
{
    afHeight = 0;
    if (DAT_011f2250.FUN_0044ddc0() == 4)
    {
        TgtH* pTarget = DAT_011f2250.FUN_009c71c0();
        if (pTarget && FUN_0066dde0(pTarget->m0))
        {
            bool f;
            Pt kPos;
            RefH* dst = pTarget->dst;
            int fB = pTarget->fB;
            if (dst)
            {
                NodeH* p3D = dst->Get3D();
                kPos.FUN_006815c0();
                f = false;
                if (fB != -1 && dst->IsActor())
                {
                    RefH* a = dst;
                    BPDataH* pBPData = a->FUN_004181e0()->GetBPData();
                    if (pBPData)
                    {
                        BodyPartH* pBodyPart = pBPData->FUN_005e5130(fB);
                        if (pBodyPart)
                        {
                            LimbH* pLimb = FUN_004aae30(a->Get3D(), pBodyPart->FUN_0043b230());
                            if (pLimb)
                            {
                                kPos = *pLimb->FUN_0045bb80();
                                f = true;
                            }
                        }
                    }
                }
                if (!f)
                {
                    if (p3D)
                        kPos = p3D->FUN_0043d450()->FUN_006815c0();
                    else
                        kPos = *dst->GetPos();
                }
                afHeight = kPos.z - DAT_011dea3c->GetPos()->z;
            }
        }
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("VATS Target Height >> %0.2f", afHeight);
    return true;
}
}  // namespace fnv_005a25f0

namespace fnv_005a2810 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class PlayerS
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
    virtual bool IsInSandman();
};
extern PlayerS* DAT_011dea3c;
// Checks if the given PlayerS is the global player and in Sandman, logs the result in debug mode, and always returns true.
// @fnv 0x005a2810
bool FUN_005a2810(PlayerS* apPlayer, void* apUnused1, void* apUnused2, double& result)
{
    result = 0;
    if (apPlayer == DAT_011dea3c)
        result = DAT_011dea3c->IsInSandman();
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("Player is in Sandman action >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a2810

namespace fnv_005a2910 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ActorS
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
    virtual bool IsActor();
    int FUN_005a29b0();
};
extern const char* DAT_0119bbb0[];
// Checks if the actor is in the given stage and logs the result when debug is enabled.
// @fnv 0x005a2910
bool FUN_005a2910(ActorS* apActor, void* aiStage, void* apUnused, double& result)
{
    result = 0;
    int iStage = (int)aiStage;
    if (apActor->IsActor())
    {
        ActorS* pActor = apActor;
        if (pActor->FUN_005a29b0() == iStage)
            result = 1;
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("Actor %s in stage %s.", result == 1 ? "IS" : "IS NOT", DAT_0119bbb0[iStage]);
    return true;
}
}  // namespace fnv_005a2910

namespace fnv_005a2ce0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class FormB
{
  public:
    int FUN_00401170();
};
class ArmorB
{
  public:
    bool FUN_00514410();
};
struct FUN_004459e0
{
    int a, b;
    FormB* FUN_0044ddc0();
    ~FUN_004459e0();
};
class InvB
{
  public:
    FUN_004459e0* FUN_004c8c10(int, int);
};
class ActorX
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
    virtual bool IsActor();
};
InvB* FUN_004bf220(ActorX*);
// Sets result to 1.0 for non-heavy armor or 2.0 for heavy armor when a type 0x18 entry is found; otherwise it remains 0.
// @fnv 0x005a2ce0
bool FUN_005a2ce0(ActorX* apActor, void* apUnused1, void* apUnused2, double& afRating)
{
    ActorX* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    afRating = 0;
    if (pActor)
    {
        InvB* pInv = FUN_004bf220(apActor);
        if (pInv)
        {
            FUN_004459e0* pInventoryEntry = pInv->FUN_004c8c10(2, 0);
            if (pInventoryEntry)
            {
                ArmorB* pArmor = 0;
                if (pInventoryEntry->FUN_0044ddc0() && pInventoryEntry->FUN_0044ddc0()->FUN_00401170() == 0x18)
                    pArmor = (ArmorB*)pInventoryEntry->FUN_0044ddc0();
                if (pArmor)
                {
                    bool bHeavy = pArmor->FUN_00514410();
                    if (!bHeavy)
                        afRating = 1;
                    else
                        afRating = 2.0;
                }
                delete pInventoryEntry;
            }
        }
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("Armor Rating upper body is %0.2f", afRating);
    return true;
}
}  // namespace fnv_005a2ce0

namespace fnv_005a3390 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ActorE
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
    virtual bool IsActor();
    bool FUN_005678a0();
    const char* FUN_0055d520();
};
// Checks if the reference is an actor and sets result to 1 if it is evil, logging the actor name when debug is enabled.
// @fnv 0x005a3390
bool FUN_005a3390(ActorE* apActor, void* apUnused1, void* apUnused2, double& result)
{
    ActorE* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    result = 0;
    if (pActor)
    {
        if (pActor->FUN_005678a0())
            result = 1;
        if (DAT_0126fd98.bDebug && result != 0)
            FUN_00703c00("%s  is evil ", pActor->FUN_0055d520());
        else if (DAT_0126fd98.bDebug)
            FUN_00703c00("%s  is not evil ", pActor->FUN_0055d520());
    }
    return true;
}
}  // namespace fnv_005a3390

namespace fnv_005a3460 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;

void FUN_00703c00(const char*, ...);
class ActorX
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
    virtual bool IsActor();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual bool IsX();
    void* FUN_007af430();
    const char* FUN_0055d520();
};
// Checks if the reference actor is the current crime victim target and sets result to 1 or 0, logging the outcome in debug mode.
// @fnv 0x005a3460
bool FUN_005a3460(ActorX* apActor, void* apUnused1, void* apUnused2, double& result)
{
    ActorX* pActor = 0;
    if (apActor && apActor->IsActor())
        pActor = apActor;
    result = 0;
    if (pActor && pActor->IsX())
    {
        void* pTarget = pActor->FUN_007af430();
        if (pTarget && pTarget == DAT_0126fd98.pTarget)
            result = 1;
        if (DAT_0126fd98.bDebug && result != 0)
            FUN_00703c00("%s  crime victim ", pActor->FUN_0055d520());
        else if (DAT_0126fd98.bDebug)
            FUN_00703c00("%s  is not a crime victim ", pActor->FUN_0055d520());
    }
    return true;
}
}  // namespace fnv_005a3460

namespace fnv_005a3870 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
bool FUN_00709d40();
// Stores a 0.0 or 1.0 value into result based on FUN_00709d40, logs it when bDebug is set, and returns true.
// @fnv 0x005a3870
bool FUN_005a3870(void* reference, void* arg1, void* arg2, double& result)
{
    result = 1;
    result = FUN_00709d40() ? 0.0f : 1.0f;
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("IsPC >> %1.0f", result);
    return true;
}
}  // namespace fnv_005a3870

union SETTING_VALUE
{
    int i;
    float f;
};

struct SettingT_GameSettingCollection_
{
    SETTING_VALUE* Int();
};
extern SettingT_GameSettingCollection_ DAT_011d0844;

class TESObjectREFR5A3E
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02C();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03C();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04C();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05C();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06C();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07C();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08C();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09C();
    virtual void vfn_0A0();
    virtual void vfn_0A4();
    virtual void vfn_0A8();
    virtual void vfn_0AC();
    virtual void vfn_0B0();
    virtual void vfn_0B4();
    virtual void vfn_0B8();
    virtual void vfn_0BC();
    virtual void vfn_0C0();
    virtual void vfn_0C4();
    virtual void vfn_0C8();
    virtual void vfn_0CC();
    virtual void vfn_0D0();
    virtual void vfn_0D4();
    virtual void vfn_0D8();
    virtual void vfn_0DC();
    virtual void vfn_0E0();
    virtual void vfn_0E4();
    virtual void vfn_0E8();
    virtual void vfn_0EC();
    virtual void vfn_0F0();
    virtual void vfn_0F4();
    virtual void vfn_0F8();
    virtual void vfn_0FC();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10C();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11C();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12C();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13C();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14C();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15C();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16C();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17C();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18C();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19C();
    virtual void vfn_1A0();
    virtual void vfn_1A4();
    virtual void vfn_1A8();
    virtual void vfn_1AC();
    virtual void vfn_1B0();
    virtual void vfn_1B4();
    virtual void vfn_1B8();
    virtual void vfn_1BC();
    virtual void vfn_1C0();
    virtual void vfn_1C4();
    virtual void vfn_1C8();
    virtual void vfn_1CC();
    virtual void vfn_1D0();
    virtual void vfn_1D4();
    virtual void vfn_1D8();
    virtual void vfn_1DC();
    virtual void vfn_1E0();
    virtual void vfn_1E4();
    virtual void vfn_1E8();
    virtual void vfn_1EC();
    virtual void vfn_1F0();
    virtual void vfn_1F4();
    virtual void vfn_1F8();
    virtual void vfn_1FC();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20C();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21C();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22C();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23C();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24C();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25C();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26C();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27C();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28C();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29C();
    virtual void vfn_2A0();
    virtual void vfn_2A4();
    virtual void vfn_2A8();
    virtual void vfn_2AC();
    virtual void vfn_2B0();
    virtual void vfn_2B4();
    virtual void vfn_2B8();
    virtual void vfn_2BC();
    virtual void vfn_2C0();
    virtual void vfn_2C4();
    virtual void vfn_2C8();
    virtual void vfn_2CC();
    virtual void vfn_2D0();
    virtual void vfn_2D4();
    virtual void vfn_2D8();
    virtual void vfn_2DC();
    virtual void vfn_2E0();
    virtual void vfn_2E4();
    virtual void vfn_2E8();
    virtual void vfn_2EC();
    virtual void vfn_2F0();
    virtual void vfn_2F4();
    virtual void vfn_2F8();
    virtual void vfn_2FC();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30C();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31C();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32C();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33C();
    virtual void vfn_340();
    virtual int vfn_344(PlayerCharacter* target, int flag);
};

// Sets result to 1 when the actor's vfn_344 value against g_thePlayer is at least the DAT_011d0844 setting; otherwise it remains 0.
// @fnv 0x005a3e90
bool __cdecl FUN_005a3e90(TESObjectREFR5A3E* apActor, void* paramInfo, void* scriptData, double& result)
{
    result = 0;
    if (apActor && apActor->IsActor())
    {
        TESObjectREFR5A3E* actor = apActor;
        int value = actor->vfn_344(g_thePlayer, 0);
        if (value >= DAT_011d0844.Int()->i)
            result = 1;
    }
    return true;
}

namespace fnv_005a3fa0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class KillerK
{
  public:
};
class ListRes
{
  public:
    bool FUN_005f65d0();
};
class FormK
{
  public:
    ListRes* FUN_00500940(KillerK**);
};
class CombatK
{
  public:
    KillerK* FUN_00825c00();
};
class HolderK
{
  public:
    CombatK* FUN_0042e8c0();
};
class ActorK
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
    virtual bool IsActor();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual bool IsDead(int);
    void* FUN_008d8520();
    HolderK* FUN_005d43c0();
};
// Sets result to 1 when the actor checks pass and the list call's returned object passes its boolean check.
// @fnv 0x005a3fa0
bool FUN_005a3fa0(ActorK* reference, void* apFormList, void* apUnused, double& result)
{
    FormK* pList = (FormK*)apFormList;
    ActorK* pActor = 0;
    if (reference && reference->IsActor())
        pActor = reference;
    if (pActor && pActor->FUN_008d8520() && pActor->IsDead(0) && pList)
    {
        CombatK* pCombat = pActor->FUN_005d43c0()->FUN_0042e8c0();
        KillerK* pKillerEntry = pCombat->FUN_00825c00();
        if (pKillerEntry && pList->FUN_00500940(&pKillerEntry)->FUN_005f65d0())
            result = 1;
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("IsKillerObject >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a3fa0

struct FUN_00990890_shell
{
    unsigned int FUN_00990890();
};

class ActorA5 : public MobileObject
{
  public:
    virtual void vfn_c1();
    virtual void vfn_c2();
    virtual void vfn_c3();
    virtual void vfn_c4();
    virtual void vfn_c5();
    virtual void vfn_c6();
    virtual void vfn_c7();
    virtual void vfn_c8();
    virtual void vfn_c9();
    virtual void vfn_ca();
    virtual void vfn_cb();
    virtual void vfn_cc();
    virtual void vfn_cd();
    virtual void vfn_ce();
    virtual void vfn_cf();
    virtual void vfn_d0();
    virtual void vfn_d1();
    virtual void vfn_d2();
    virtual void vfn_d3();
    virtual void vfn_d4();
    virtual void vfn_d5();
    virtual void vfn_d6();
    virtual void vfn_d7();
    virtual void vfn_d8();
    virtual void vfn_d9();
    virtual void vfn_da();
    virtual void vfn_db();
    virtual void vfn_dc();
    virtual void vfn_dd();
    virtual void vfn_de();
    virtual void vfn_df();
    virtual void vfn_e0();
    virtual void vfn_e1();
    virtual void vfn_e2();
    virtual void vfn_e3();
    virtual void vfn_e4();
    virtual void vfn_e5();
    virtual void vfn_e6();
    virtual void vfn_e7();
    virtual void vfn_e8();
    virtual void vfn_e9();
    virtual void vfn_ea();
    virtual void vfn_eb();
    virtual void vfn_ec();
    virtual void vfn_ed();
    virtual void vfn_ee();
    virtual void vfn_ef();
    virtual void vfn_f0();
    virtual void vfn_f1();
    virtual void vfn_f2();
    virtual void vfn_f3();
    virtual void vfn_f4();
    virtual void vfn_f5();
    virtual void vfn_f6();
    virtual void vfn_f7();
    virtual void vfn_f8();
    virtual void vfn_f9();
    virtual void vfn_fa();
    virtual void vfn_fb();
    virtual void vfn_fc();
    virtual void vfn_fd();
    virtual FUN_00990890_shell* vfn_fe();
};

// Returns the value from the shell object obtained via vfn_fe on the actor reference, or 0 if the reference is null, not an actor, or has no shell.
// @fnv 0x005a4240
bool __cdecl FUN_005a4240(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0;
    if (reference && reference->IsActor())
    {
        ActorA5* actor = (ActorA5*)reference;
        if (FUN_00990890_shell* p = actor->vfn_fe())
            result = p->FUN_00990890();
    }
    return true;
}

namespace fnv_005a4410 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class FormT
{
  public:
    int FUN_00401170();
};
class RefT
{
  public:
    FormT* FUN_007af430();
};
// Compares the reference's form type against arg1, stores 1 or 0 in result, and logs the value when bDebug is set.
// @fnv 0x005a4410
bool FUN_005a4410(RefT* reference, void* aiType, void* apUnused, double& result)
{
    result = 0;
    int iType = (int)aiType;
    if (reference->FUN_007af430()->FUN_00401170() == iType)
        result = 1;
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetIsObjectType is  >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a4410

namespace fnv_005a45c0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class FormW
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
    virtual void* GetWater();
};
FormW* FUN_006008f0();
// Sets result to 1 when FUN_006008f0 returns a form with nonnull GetWater(), logs result when bDebug is set, and returns true.
// @fnv 0x005a45c0
bool FUN_005a45c0(void* reference, void* arg1, void* arg2, double& result)
{
    result = 0;
    FormW* pForm = FUN_006008f0();
    if (pForm && pForm->GetWater())
        result = 1;
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("IsWaterActivator >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a45c0

namespace fnv_005a4aa0 {
extern unsigned int DAT_0126fd98;
extern void __cdecl DebugLog(char const* fmt, ...);
extern PlayerCharacter* _g_thePlayer;

__declspec(thread) unsigned char tlsCrimeFlags[0x269];

static const char kMinorCrimesMsg[] = "The number of minor crimes is %.2f";

class FUN_005a4b40Class
{
  public:
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}
    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}
    virtual void vfB0()
    {}
    virtual void vfB4()
    {}
    virtual void vfB8()
    {}
    virtual void vfBC()
    {}
    virtual void vfC0()
    {}
    virtual void vfC4()
    {}
    virtual void vfC8()
    {}
    virtual void vfCC()
    {}
    virtual void vfD0()
    {}
    virtual void vfD4()
    {}
    virtual void vfD8()
    {}
    virtual void vfDC()
    {}
    virtual void vfE0()
    {}
    virtual void vfE4()
    {}
    virtual void vfE8()
    {}
    virtual void vfEC()
    {}
    virtual void vfF0()
    {}
    virtual void vfF4()
    {}
    virtual void vfF8()
    {}
    virtual void vfFC()
    {}
    virtual bool vf100();

    unsigned int FUN_005a4b40();
    int GetFactionRankSum();
};

bool FUN_005a4b40Class::vf100()
{
    return false;
}

unsigned int FUN_005a4b40Class::FUN_005a4b40()
{
    return 0;
}

int FUN_005a4b40Class::GetFactionRankSum()
{
    return 0;
}

// Returns a true/false flag and sets result to the faction rank sum (or player value) of the actor, logging minor crimes when the crime flag is set.
// @fnv 0x005a4aa0
bool __cdecl FUN_005a4aa0(int actor, unsigned int arg2, unsigned int arg3, double& result)
{
    result = 0.0;

    if (actor != 0 && ((FUN_005a4b40Class*)actor)->vf100())
    {
        FUN_005a4b40Class* object = (FUN_005a4b40Class*)actor;

        if (object == (FUN_005a4b40Class*)_g_thePlayer)
        {
            int value = (int)object->FUN_005a4b40();
            result = (double)value;
        }
        else
        {
            int value = object->GetFactionRankSum();
            result = (double)value;
        }

        if (tlsCrimeFlags[0x268] != 0)
        {
            DebugLog(kMinorCrimesMsg, result);
        }
    }

    return true;
}
}  // namespace fnv_005a4aa0

namespace fnv_005a4cd0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ActorX
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
    virtual bool IsActor();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual const char* GetName();
    float GetModifiedDamagePerSecond(float);
};
// Computes the ratio of reference's modified damage per second to arg1's, storing it in result and logging the outcome in debug mode.
// @fnv 0x005a4cd0
bool FUN_005a4cd0(ActorX* reference, void* apTarget, void* apUnused, double& afRatio)
{
    afRatio = 0;
    ActorX* pTarget = (ActorX*)apTarget;
    if (reference && reference->IsActor() && pTarget)
    {
        ActorX* pActor = reference;
        afRatio = pActor->GetModifiedDamagePerSecond(-1.0f) / pTarget->GetModifiedDamagePerSecond(-1.0f);
        if (DAT_0126fd98.bDebug)
            FUN_00703c00("GetThreatRatio: '%s' to '%s' >> %.2f", pActor->GetName(), pTarget->GetName(), afRatio);
    }
    else if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetThreatRatio >> FAILED");
    return true;
}
}  // namespace fnv_005a4cd0

namespace fnv_005a4dd0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class AVOwner
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int);
};
class ActorV
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
    virtual bool IsActor();
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
    AVOwner kAVOwner;
};
int FUN_0047e040(float);
extern const char* DAT_01186cf4[];
// Checks if the actor's alignment actor value matches the requested alignment index and logs the result in debug mode.
// @fnv 0x005a4dd0
bool FUN_005a4dd0(ActorV* apActor, void* aiAlignment, void* apUnused, double& result)
{
    result = 0;
    int iAlignment = (int)aiAlignment;
    if (apActor && apActor->IsActor())
    {
        ActorV* pActor = apActor;
        if (FUN_0047e040(pActor->kAVOwner.GetActorValue(0x17)) == iAlignment)
            result = 1;
    }
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetIsAlignment '%s' >> %s", DAT_01186cf4[iAlignment], result > 0 ? "true" : "false");
    return true;
}
}  // namespace fnv_005a4dd0

namespace fnv_005a4ea0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
void* FUN_006008f0();
int FUN_00479430(void*);
extern const char* DAT_011869bc[];
// Compares FUN_00479430(FUN_006008f0()) with arg1, stores 1 or 0 in result, and logs the indexed label in debug mode.
// @fnv 0x005a4ea0
bool FUN_005a4ea0(void* reference, void* aiEquipType, void* apUnused, double& result)
{
    result = 0;
    int iType = (int)aiEquipType;
    if (FUN_006008f0() && FUN_00479430(FUN_006008f0()) == iType)
        result = 1;
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetIsUsedItemEquipType '%s' >> %s", DAT_011869bc[iType], result > 0 ? "true" : "false");
    return true;
}
}  // namespace fnv_005a4ea0

namespace fnv_005a4f30 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class Pkg
{
  public:
    int FUN_0041ca90();
};
class Proc
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
    virtual Pkg* GetPkg();
};
class ActorX
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
    virtual bool IsActor();
    Proc* FUN_008d8520();
    const char* FUN_0055d520();
};
// Sets result when the actor's package chain exists and the package method returns 0xe; logs a message when bDebug is set.
// @fnv 0x005a4f30
bool FUN_005a4f30(ActorX* apActor, void* apUnused1, void* apUnused2, double& result)
{
    result = 0;
    if (apActor && apActor->IsActor())
    {
        ActorX* pActor = apActor;
        if (pActor->FUN_008d8520() && pActor->FUN_008d8520()->GetPkg() &&
            pActor->FUN_008d8520()->GetPkg()->FUN_0041ca90() == 0xe)
            result = 1;
        if (DAT_0126fd98.bDebug)
        {
            if (result > 0)
                FUN_00703c00("%s has his aggro radius violated ", apActor->FUN_0055d520());
            else
                FUN_00703c00("%s does not have his aggro radius violated ", apActor->FUN_0055d520());
        }
    }
    return true;
}
}  // namespace fnv_005a4f30

namespace fnv_005a5020 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ProcC
{
  public:
    bool HasActiveEffectOfArchetype(int, int);
};
class ActorC
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
    virtual bool IsActor();
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
    ProcC kProc;
    const char* FUN_0055d520();
};
bool FUN_005a50e0();
// When the reference passes the checks, tests for active effect archetype 0x21, stores 1 if present, and logs when bDebug is set.
// @fnv 0x005a5020
bool FUN_005a5020(ActorC* apActor, void* apUnused1, void* apUnused2, double& afIsConcussed)
{
    afIsConcussed = 0;
    if (apActor && apActor->IsActor() && FUN_005a50e0())
    {
        ActorC* pActor = apActor;
        if (pActor->kProc.HasActiveEffectOfArchetype(0x21, 0))
            afIsConcussed = 1;
        if (DAT_0126fd98.bDebug)
        {
            if (afIsConcussed > 0)
                FUN_00703c00("%s is concussed", apActor->FUN_0055d520());
            else
                FUN_00703c00("%s is not concussed ", apActor->FUN_0055d520());
        }
    }
    return true;
}
}  // namespace fnv_005a5020

class refv_a5580
{
  public:
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(void);
    virtual void v07(void);
    virtual void v08(void);
    virtual void v09(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(void);
    virtual void v58(void);
    virtual void v59(void);
    virtual void v60(void);
    virtual void v61(void);
    virtual void v62(void);
    virtual void v63(void);
    virtual bool BackAreaFree(void);
    double FUN_008bd830(unsigned int arg, float angle);
};

struct tls_a5580
{
    unsigned int f000;
    unsigned char f004;
};

extern __declspec(thread) tls_a5580 tlsdata_a5580;
void __cdecl DebugLog(const char* fmt, ...);

// If reference is non-null and BackAreaFree succeeds, writes FUN_008bd830's result; logs result when the TLS flag is set, then returns true.
// @fnv 0x005a5580
bool __cdecl FUN_005a5580(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    result = 0.0;
    unsigned int arg = (unsigned int)arg1;
    if (reference != 0)
    {
        if (((refv_a5580*)reference)->BackAreaFree())
        {
            result = ((refv_a5580*)reference)->FUN_008bd830(arg, 3.14159274f);
        }
    }
    if (tlsdata_a5580.f004)
    {
        DebugLog("VATSBackAreaFree >> %.2f", result);
    }
    return true;
}

namespace fnv_005a5690 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ActorQ
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
    virtual bool IsActor();
    float FUN_008bdbd0(ActorQ*, float);
};
// Calls FUN_008bdbd0 on reference with arg1 and 1.5707964f, stores its return value, and logs it.
// @fnv 0x005a5690
bool FUN_005a5690(ActorQ* reference, void* apTarget, void* apUnused, double& afVisibility)
{
    afVisibility = 0;
    ActorQ* pTarget = (ActorQ*)apTarget;
    if (reference && reference->IsActor())
        afVisibility = reference->FUN_008bdbd0(pTarget, 1.5707964f);
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("VATSRightTargetVisible >> %.2f", afVisibility);
    return true;
}
}  // namespace fnv_005a5690

namespace fnv_005a5ab0 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class ProcMgr
{
  public:
    int GetFieldPointer();
};
extern ProcMgr DAT_011e0e80;
// Stores the value returned by DAT_011e0e80.GetFieldPointer into result and logs it when bDebug is set.
// @fnv 0x005a5ab0
bool FUN_005a5ab0(void* reference, void* arg1, void* arg2, double& result)
{
    result = 0;
    result = DAT_011e0e80.GetFieldPointer();
    if (DAT_0126fd98.bDebug)
        FUN_00703c00("GetActorsInHigh >> %0.2f", result);
    return true;
}
}  // namespace fnv_005a5ab0

namespace fnv_005a5c40 {
struct TlsData
{
    char pad[0x268];
    bool bDebug;
    char p2[3];
    void* pTarget;
};
extern __declspec(thread) TlsData DAT_0126fd98;
void FUN_00703c00(const char*, ...);
class NameR
{
  public:
    const char* FUN_00408da0();
};
class RepR
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    NameR kName;
    float FUN_00616a60(int);
};
// When pRep is non-null, stores FUN_00616a60(iType) in result and logs it if bDebug is set.
// @fnv 0x005a5c40
bool FUN_005a5c40(void* reference, void* apRep, void* aiType, double& afReputation)
{
    RepR* pRep = (RepR*)apRep;
    int iType = (int)aiType;
    if (pRep)
    {
        afReputation = pRep->FUN_00616a60(iType);
        if (DAT_0126fd98.bDebug)
            FUN_00703c00("GetReputation: %s >> %0.2f", pRep->kName.FUN_00408da0(), afReputation);
    }
    return true;
}
}  // namespace fnv_005a5c40

#include <xmmintrin.h>
namespace fnv_0059c990 {
struct SceneObject
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual SceneObject* GetSceneObject();
    NiPoint3& FUN_0043c490();
};
struct CameraView
{
};
struct CameraRoot
{
    SceneObject* FUN_00558310();
    CameraView* FUN_006629f0();
};
extern CameraRoot* __cdecl FUN_0045c670();
struct VisibilityRef
{
    virtual void Slot000();
    virtual void Slot004();
    virtual void Slot008();
    virtual void Slot00c();
    virtual void Slot010();
    virtual void Slot014();
    virtual void Slot018();
    virtual void Slot01c();
    virtual void Slot020();
    virtual void Slot024();
    virtual void Slot028();
    virtual void Slot02c();
    virtual void Slot030();
    virtual void Slot034();
    virtual void Slot038();
    virtual void Slot03c();
    virtual void Slot040();
    virtual void Slot044();
    virtual void Slot048();
    virtual void Slot04c();
    virtual void Slot050();
    virtual void Slot054();
    virtual void Slot058();
    virtual void Slot05c();
    virtual void Slot060();
    virtual void Slot064();
    virtual void Slot068();
    virtual void Slot06c();
    virtual void Slot070();
    virtual void Slot074();
    virtual void Slot078();
    virtual void Slot07c();
    virtual void Slot080();
    virtual void Slot084();
    virtual void Slot088();
    virtual void Slot08c();
    virtual void Slot090();
    virtual void Slot094();
    virtual void Slot098();
    virtual void Slot09c();
    virtual void Slot0a0();
    virtual void Slot0a4();
    virtual void Slot0a8();
    virtual void Slot0ac();
    virtual void Slot0b0();
    virtual void Slot0b4();
    virtual void Slot0b8();
    virtual void Slot0bc();
    virtual void Slot0c0();
    virtual void Slot0c4();
    virtual void Slot0c8();
    virtual void Slot0cc();
    virtual void Slot0d0();
    virtual void Slot0d4();
    virtual void Slot0d8();
    virtual void Slot0dc();
    virtual void Slot0e0();
    virtual void Slot0e4();
    virtual void Slot0e8();
    virtual void Slot0ec();
    virtual void Slot0f0();
    virtual void Slot0f4();
    virtual void Slot0f8();
    virtual bool IsNPC();
    virtual bool IsActor();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12c();
    virtual void Slot130();
    virtual void Slot134();
    virtual void Slot138();
    virtual void Slot13c();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14c();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15c();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16c();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17c();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18c();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19c();
    virtual void Slot1a0();
    virtual void Slot1a4();
    virtual void Slot1a8();
    virtual void Slot1ac();
    virtual void Slot1b0();
    virtual void Slot1b4();
    virtual void Slot1b8();
    virtual void Slot1bc();
    virtual void Slot1c0();
    virtual void Slot1c4();
    virtual void Slot1c8();
    virtual void Slot1cc();
    virtual SceneObject* GetNiNode();
    virtual void Slot1d4();
    virtual NiPoint3* GetBoundsMinimum(NiPoint3*);
    virtual NiPoint3* GetBoundsMaximum(NiPoint3*);
    virtual void Slot1e0();
    virtual void Slot1e4();
    virtual void Slot1e8();
    virtual void Slot1ec();
    virtual void Slot1f0();
    virtual NiPoint3* GetPos();
    bool FUN_00444ed0();
    bool FUN_0088b880(int, VisibilityRef*, int, int, int);
    char* FUN_0055d520();
    void FUN_00931ed0(unsigned int*);
};
struct SphereBound
{
    NiPoint3 center;
    float radius;
    void FUN_006240d0();
    void FUN_0098ddd0(NiPoint3*);
    void FUN_0063f790(float);
};
extern bool __cdecl FUN_004b5fc0(SceneObject*, CameraView*);
extern bool __cdecl IsBoundVisible(SphereBound*, CameraView*);
struct __declspec(align(16)) RayQuery
{
    __m128 from;
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
    void FUN_004a3c20();
    void FUN_0059ceb0(void*);
    void FUN_004a3da0(NiPoint3*);
    void FUN_004a3f70(unsigned int);
    void FUN_004a3eb0(NiPoint3*);
};
struct __declspec(align(16)) FUN_0062a190
{
    __m128 from;
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
    FUN_0062a190(int, VisibilityRef*);
    ~FUN_0062a190();
};
struct Filter
{
    unsigned int bits;
    void FUN_008c71b0(int);
    void FUN_004a39f0(int);
    unsigned int FUN_004a3a20();
    void FUN_0059ce80(unsigned int);
};
struct World
{
    void* FUN_00458420(RayQuery*);
};
extern World* g_TES;
extern VisibilityRef* __cdecl FUN_0056f930(void*);
extern __declspec(thread) unsigned char visibilityTls[];
extern void __cdecl DebugLog(const char*, ...);
static const char str_01034eb4[] = "%s sees %s";
static const char str_01034ea4[] = "%s can't see %s";
// Determines whether reference can see target, using a camera raycast for the player or a visibility check for other actors, and stores the result in result.
// @fnv 0x0059c990
bool __cdecl FUN_0059c990(TESObjectREFR* reference, void* target, void*, double& result)
{
    result = 0.0;
    if (reference)
    {
        VisibilityRef* actor = 0;
        if (reference && reference->IsActor())
            actor = reinterpret_cast<VisibilityRef*>(reference);
        VisibilityRef* other = static_cast<VisibilityRef*>(target);
        bool visible = false;
        if (actor && other)
        {
            if (actor == reinterpret_cast<VisibilityRef*>(g_thePlayer))
            {
                bool inView = false;
                SceneObject* cameraNode = FUN_0045c670()->FUN_00558310();
                CameraView* camera = FUN_0045c670()->FUN_006629f0();
                SceneObject* scene = other->GetNiNode() ? other->GetNiNode()->GetSceneObject() : 0;
                if (scene && FUN_004b5fc0(scene, camera))
                {
                    inView = true;
                }
                else if (other->FUN_00444ed0())
                {
                    SphereBound sphereBound;
                    sphereBound.FUN_006240d0();
                    sphereBound.FUN_0098ddd0(other->GetPos());
                    sphereBound.FUN_0063f790(1.0f);
                    if (IsBoundVisible(&sphereBound, camera))
                        inView = true;
                }
                if (inView)
                {
                    NiPoint3 origin = cameraNode->FUN_0043c490();
                    RayQuery rayQuery;
                    rayQuery.FUN_004a3c20();
                    VisibilityRef* targetActor = 0;
                    if (other && other->IsNPC())
                        targetActor = other;
                    FUN_0062a190 rayCollector(0x25, targetActor);
                    rayQuery.FUN_0059ceb0(&rayCollector);
                    NiPoint3 destination = *other->GetPos();
                    rayQuery.FUN_004a3da0(&origin);
                    unsigned int playerFilter;
                    reinterpret_cast<VisibilityRef*>(g_thePlayer)->FUN_00931ed0(&playerFilter);
                    Filter rayFilter;
                    rayFilter.FUN_008c71b0(0);
                    rayFilter.FUN_004a39f0(0x25);
                    rayFilter.FUN_0059ce80(reinterpret_cast<Filter*>(&playerFilter)->FUN_004a3a20());
                    rayQuery.FUN_004a3f70(rayFilter.bits);
                    NiPoint3 maxBounds;
                    NiPoint3 minBounds;
                    float height = other->GetBoundsMaximum(&maxBounds)->z - other->GetBoundsMinimum(&minBounds)->z;
                    float heights[3] = {height * 0.75 + destination.z, height * 0.5 + destination.z,
                                        height * 0.25 + destination.z};
                    for (int i = 0; i < 3; i++)
                    {
                        destination.z = heights[i];
                        rayQuery.FUN_004a3eb0(&destination);
                        void* hit = g_TES->FUN_00458420(&rayQuery);
                        VisibilityRef* hitRef = hit ? FUN_0056f930(hit) : 0;
                        if (!hit || hitRef == other)
                        {
                            visible = true;
                            break;
                        }
                    }
                    if (visible)
                        result = 1.0;
                    else
                        result = actor->FUN_0088b880(0, other, 1, 0, 0);
                }
            }
            else
            {
                result = actor->FUN_0088b880(0, other, 1, 0, 0);
            }
            if (visibilityTls[0x268])
            {
                if (result != 0.0)
                    DebugLog(str_01034eb4, actor->FUN_0055d520(), other->FUN_0055d520());
                else
                    DebugLog(str_01034ea4, actor->FUN_0055d520(), other->FUN_0055d520());
            }
        }
    }
    return true;
}
}  // namespace fnv_0059c990

namespace s59f890 {

extern __declspec(thread) bool tls_bEchoConsole;

void FUN_00703c00(const char* pcFormat, ...);

struct Form
{
    int unk00;
};

struct BoundObject : Form
{
};

struct FormList
{
    bool FUN_005f65d0(Form* const& pkForm);
};

struct ListForm
{
    FormList* FUN_00500940();
};

struct Process
{
    BoundObject* FUN_004216f0();
};

struct Actor
{
    Process* FUN_005d43c0();
    BoundObject* FUN_007af430();
};

static const char s_szIsInListFormat[] = "IsInList >> %0.2f";

// Checks if the actor's bound object is in the given form list, writing 1.0 or 0.0 to pdResult and echoing the result to the console when enabled.
// @fnv 0x0059f890
bool FUN_0059f890(Actor* pkActor, ListForm* pkListArg, void* pvUnused, double* pdResult)
{
    *pdResult = 0.0;
    ListForm* pkList = pkListArg;
    if (pkActor && pkList)
    {
        BoundObject* pkObject = pkActor->FUN_005d43c0()->FUN_004216f0();
        if (!pkObject)
            pkObject = pkActor->FUN_007af430();
        if (pkObject && pkList->FUN_00500940()->FUN_005f65d0(pkObject))
            *pdResult = 1.0;
    }
    if (tls_bEchoConsole)
        FUN_00703c00(s_szIsInListFormat, *pdResult);
    return true;
}

}

class TESPackage
{
  public:
    int GetProcedureType();
    int GetPackType();
};
struct S981990
{
    bool FUN_00981990();
};
struct ProcedureTarget
{
    unsigned int flags;
    int type;
    unsigned int GetFlags();
};
class BaseProcess
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual ProcedureTarget* GetProcedureTarget();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual int GetProcedureIndex();
};
class ActorS : public TESObjectREFR
{
  public:
    BaseProcess* GetCurrentProcess() const;
    TESPackage* GetCurrentPackage();
};
extern int* DAT_011a3ff0[];
extern __declspec(thread) bool bPrintConditionDebug;
void DebugLog(const char*, ...);
static const float targetTypeResults[4] = {45.0f, 21.0f, 0.0f, -1.0f};
static const float flagResults[7] = {45.0f, 48.0f, 8.0f, 10.0f, 7.0f, 46.0f, 4.0f};

// Maps the actor's current procedure code to a result value via a switch, adjusting for target type and flags when the procedure is 42.
// @fnv 0x005a1210
bool __cdecl FUN_005a1210(TESObjectREFR* reference, void* apUnused1, void* apUnused2, double& result)
{
    result = 0.0;
    ActorS* actor = 0;
    if (reference && reference->IsActor())
        actor = (ActorS*)reference;
    {
        TESPackage* package;
        {
            int procedureType;
            {
                int procedure;
                {
                    BaseProcess* process;
                    {
                        int procedureIndex;
                        if (actor && actor->GetCurrentProcess() && actor->GetCurrentPackage())
                        {
                            package = actor->GetCurrentPackage();
                            process = actor->GetCurrentProcess();
                            procedureType = package->GetProcedureType();
                            procedureIndex = process->GetProcedureIndex();
                            procedure = DAT_011a3ff0[procedureType][procedureIndex];
                            if (package->GetPackType() == 18)
                            {
                                S981990* specialPackage = (S981990*)package;
                                if (specialPackage->FUN_00981990())
                                    procedure = 10;
                            }
                            switch (procedure)
                            {
                            case 0:
                                result = 0.0;
                                break;
                            case 2:
                                result = 1.0;
                                break;
                            case 3:
                                result = 2.0;
                                break;
                            case 13:
                                result = 3.0;
                                break;
                            case 12:
                                result = 4.0;
                                break;
                            case 16:
                                result = 5.0;
                                break;
                            case 20:
                                result = 6.0;
                                break;
                            case 1:
                                result = 7.0;
                                break;
                            case 4:
                                result = 8.0;
                                break;
                            case 18:
                                result = 9.0;
                                break;
                            case 5:
                                result = 10.0;
                                break;
                            case 6:
                                result = 11.0;
                                break;
                            case 7:
                                result = 12.0;
                                break;
                            case 9:
                                result = 13.0;
                                break;
                            case 8:
                                result = 14.0;
                                break;
                            case 15:
                                result = 15.0;
                                break;
                            case 10:
                                result = 16.0;
                                break;
                            case 54:
                                result = 17.0;
                                break;
                            case 11:
                                result = 18.0;
                                break;
                            case 14:
                                result = 19.0;
                                break;
                            case 17:
                                result = 20.0;
                                break;
                            case 22:
                                result = 21.0;
                                break;
                            case 23:
                                result = 22.0;
                                break;
                            case 24:
                                result = 23.0;
                                break;
                            case 25:
                                result = 24.0;
                                break;
                            case 27:
                                result = 27.0;
                                break;
                            case 28:
                                result = 28.0;
                                break;
                            case 29:
                                result = 29.0;
                                break;
                            case 30:
                                result = 30.0;
                                break;
                            case 31:
                                result = 31.0;
                                break;
                            case 32:
                                result = 32.0;
                                break;
                            case 33:
                                result = 33.0;
                                break;
                            case 34:
                                result = 34.0;
                                break;
                            case 35:
                                result = 35.0;
                                break;
                            case 36:
                                result = 36.0;
                                break;
                            case 37:
                                result = 37.0;
                                break;
                            case 38:
                                result = 38.0;
                                break;
                            case 39:
                                result = 39.0;
                                break;
                            case 40:
                                result = 40.0;
                                break;
                            case 44:
                                result = 41.0;
                                break;
                            case 50:
                                result = 42.0;
                                break;
                            case 49:
                                result = 43.0;
                                break;
                            case 47:
                                result = 44.0;
                                break;
                            case 42: {
                                ProcedureTarget* target = process->GetProcedureTarget();
                                result = 45.0;
                                if (target)
                                {
                                    int targetType = target->type;
                                    if (targetType == 3)
                                    {
                                        unsigned int flagIndex = target->GetFlags() + 1;
                                        if (flagIndex < 7)
                                            result = flagResults[flagIndex];
                                    }
                                    else if (targetType >= 0 && (unsigned int)targetType < 4)
                                    {
                                        result = targetTypeResults[targetType];
                                    }
                                }
                                break;
                            }
                            case 43:
                                result = 46.0;
                                break;
                            case 41:
                                result = 47.0;
                                break;
                            case 51:
                                result = 49.0;
                                break;
                            case 52:
                                result = 50.0;
                                break;
                            default:
                                result = -1.0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if (bPrintConditionDebug)
        DebugLog("Procedure >> %0.2f", result);
    return true;
}

namespace fnv_005a0b60 {
struct Sub
{
    int Index();
};

struct Obj
{
    int Pred();
    Sub* GetSub();
};

struct AudioTlsState
{
    char unk0000[0x268];
    unsigned char logEnabled;
};

extern __declspec(thread) AudioTlsState g_threadData;

void Log(const char* fmt, ...);

// Maps sel->GetSub()->Index() to a numeric value in out when the object checks pass, then logs out when enabled.
// @fnv 0x005a0b60
bool FUN_005a0b60(Obj* obj, int aiUnused1, int aiUnused2, double* out)
{
    *out = 0.0;
    Obj* sel = 0;
    typedef unsigned char(__thiscall * VFn)(Obj*);
    if (obj != 0 && ((VFn)((void**)(*(void**)obj))[64])(obj))
    {
        sel = obj;
    }
    if (sel != 0)
    {
        if (sel->Pred() != 0)
        {
            if (sel->GetSub() != 0)
            {
                switch (sel->GetSub()->Index())
                {
                case 0:
                    *out = 0.0;
                    break;
                case 1:
                    *out = 1.0;
                    break;
                case 2:
                    *out = 2.0;
                    break;
                case 3:
                    *out = 3.0;
                    break;
                case 4:
                    *out = 4.0;
                    break;
                case 18:
                    *out = 5.0;
                    break;
                case 28:
                    *out = 6.0;
                    break;
                case 20:
                    *out = 7.0;
                    break;
                case 21:
                    *out = 8.0;
                    break;
                case 24:
                    *out = 9.0;
                    break;
                case 22:
                    *out = 10.0;
                    break;
                case 23:
                    *out = 11.0;
                    break;
                case 25:
                    *out = 12.0;
                    break;
                case 5:
                    *out = 13.0;
                    break;
                case 6:
                    *out = 14.0;
                    break;
                case 7:
                    *out = 15.0;
                    break;
                case 8:
                    *out = 16.0;
                    break;
                case 9:
                    *out = 17.0;
                    break;
                case 10:
                    *out = 18.0;
                    break;
                case 11:
                    *out = 19.0;
                    break;
                case 19:
                    *out = 20.0;
                    break;
                case 26:
                    *out = 21.0;
                    break;
                case 27:
                    *out = 24.0;
                    break;
                case 29:
                    *out = 28.0;
                    break;
                case 30:
                    *out = 29.0;
                    break;
                case 31:
                    *out = 32.0;
                    break;
                case 16:
                    *out = 33.0;
                    break;
                case 15:
                    *out = 34.0;
                    break;
                case 14:
                    *out = 35.0;
                    break;
                case 12:
                    *out = 36.0;
                    break;
                case 13:
                    *out = 37.0;
                    break;
                default:
                    *out = -1.0;
                    break;
                }
            }
        }
    }
    if (g_threadData.logEnabled)
    {
        Log("Current Process >> %0.2f", *out);
    }
    return true;
}
}  // namespace fnv_005a0b60

void __cdecl DebugLog(char const*, ...);
int __fastcall _FNV_GetFormType(TESForm*);
extern __declspec(thread) bool bPrintConditionDebug;
struct GetInFactionCache_0059f630
{
    static int DAT_011cab00;
    static int DAT_011cab04;
    static float DAT_011cab08;
};
struct GetInFactionActor_0059f630
{
    bool HasFaction(TESForm*);
};
// Checks if apRefObject is in the faction apParam1, using a static cache to avoid repeated HasFaction calls, and writes the result to afReturnValue.
// @fnv 0x0059f630
bool FUN_0059f630(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    TESForm* pfac = 0;
    if (apParam1 && _FNV_GetFormType((TESForm*)apParam1) == 8)
        pfac = (TESForm*)apParam1;
    if ((int)apRefObject == GetInFactionCache_0059f630::DAT_011cab04 &&
        (int)pfac == GetInFactionCache_0059f630::DAT_011cab00)
    {
        *afReturnValue = GetInFactionCache_0059f630::DAT_011cab08;
    }
    else
    {
        GetInFactionActor_0059f630* pact = 0;
        if (apRefObject && apRefObject->IsActor())
            pact = (GetInFactionActor_0059f630*)apRefObject;
        if (!pact)
            return true;
        if (pact->HasFaction(pfac))
            *afReturnValue = 1.0;
        GetInFactionCache_0059f630::DAT_011cab04 = (int)apRefObject;
        GetInFactionCache_0059f630::DAT_011cab00 = (int)pfac;
        GetInFactionCache_0059f630::DAT_011cab08 = *afReturnValue;
    }
    if (bPrintConditionDebug)
        DebugLog("GetInFaction >> %0.2f", *afReturnValue);
    return true;
}

static bool __cdecl InFactionConditionForPlayerCallee(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    return false;
}

// @fnv 0x0059f790
bool __cdecl FUN_0059f790(TESObjectREFR* reference, void* arg1, void* arg2, double& result)
{
    return InFactionConditionForPlayerCallee((TESObjectREFR*)g_thePlayer, arg1, arg2, result);
}

class ActorBarterGoldEntry5A : public Actor
{
  public:
    unsigned int FUN_00884320();
};

extern void __cdecl _DebugLog(const char* format, ...);
extern int __tls_index;

static __declspec(thread) unsigned char tlsBuffer[0x269];

// Stores FUN_00884320() in afReturnValue for an actor and logs the value when tlsBuffer[0x268] is set.
// @fnv 0x005a2ba0
bool FUN_005a2ba0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double& afReturnValue)
{
    Actor* pactor = 0;

    if (apRefObject)
    {
        if (apRefObject->IsActor())
        {
            pactor = reinterpret_cast<Actor*>(apRefObject);
        }
    }

    if (pactor)
    {
        afReturnValue = reinterpret_cast<ActorBarterGoldEntry5A*>(pactor)->FUN_00884320();

        if (tlsBuffer[0x268])
        {
            _DebugLog("%s  has %d barter gold currently", pactor,
                      reinterpret_cast<ActorBarterGoldEntry5A*>(pactor)->FUN_00884320());
        }
    }

    return true;
}

struct BGSVoiceType;
struct TESFormList;
struct VoiceCondition59f450Data : BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
};

struct VoiceCondition59f450Actor : TESForm
{
    TESFormList* m_pBoundObjectList;
    TESBoundObject* m_pPreviousBlock;
    TESBoundObject* pNext;
    short minX;
    short minY;
    short minZ;
    short maxX;
    short maxY;
    short maxZ;
    VoiceCondition59f450Data data;
};
struct VoiceCondition59f450Activator
{
    BGSVoiceType* FUN_009185e0();
};
struct VoiceCondition59f450Thread
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
    bool bLog;
};
extern __declspec(thread) VoiceCondition59f450Thread voiceCondition59f450Thread;

// Compares the selected voice type with apParam1 and stores the reference and voice type in two globals for reuse.
// @fnv 0x0059f450
bool __cdecl FUN_0059f450(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    if (apRefObject)
    {
        BGSVoiceType* pcompvoice = 0;
        if (apRefObject == reinterpret_cast<TESObjectREFR*>(::fnv_005a38e0::DAT_011cab18))
        {
            pcompvoice = reinterpret_cast<BGSVoiceType*>(::fnv_005a38e0::DAT_011cab14);
        }
        else
        {
            switch (::_FNV_GetFormType(reinterpret_cast< ::TESForm*>(apRefObject->GetObjectReference())))
            {
            case 0x2a:
            case 0x2b: {
                VoiceCondition59f450Actor* pab =
                    reinterpret_cast<VoiceCondition59f450Actor*>(apRefObject->GetObjectReference());
                pcompvoice = pab->data.GetVoiceType();
            }
            break;
            case 0x16: {
                VoiceCondition59f450Activator* pta =
                    reinterpret_cast<VoiceCondition59f450Activator*>(apRefObject->GetObjectReference());
                pcompvoice = pta->FUN_009185e0();
            }
            break;
            }
            ::fnv_005a38e0::DAT_011cab18 = reinterpret_cast<int>(apRefObject);
            ::fnv_005a38e0::DAT_011cab14 = reinterpret_cast<int>(pcompvoice);
        }
        if (pcompvoice == apParam1)
            *afReturnValue = 1.0;
    }
    if (voiceCondition59f450Thread.bLog)
        ::DebugLog("GetIsVoiceType >> %0.2f", *afReturnValue);
    return true;
}

class MiddleHighProcess : public BaseProcess
{
};
extern __declspec(thread) bool bPrintConditionDebug;

struct P01Proc
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
    virtual int StopIdleAnimation();
};
// Returns 1.0 if the actor's process reports an idle-animation stop state of 3 or 4, otherwise 0.0.
// @fnv 0x005a08c0
bool FUN_005a08c0(TESObjectREFR* apRefObject, void* apParam1, void* apParam2, double* afReturnValue)
{
    *afReturnValue = 0.0;
    Actor* pactor = 0;
    if (apRefObject && apRefObject->IsActor())
        pactor = (Actor*)apRefObject;
    if (pactor)
    {
        MiddleHighProcess* pprocess = dynamic_cast<MiddleHighProcess*>((BaseProcess*)((TES*)pactor)->GetLogDate());
        if (pprocess)
        {
            switch (((P01Proc*)pprocess)->StopIdleAnimation())
            {
            case 0:
            case 5:
            case 6:
                *afReturnValue = 0.0;
                break;
            case 3:
            case 4:
                *afReturnValue = 1.0;
                break;
            }
        }
    }
    if (bPrintConditionDebug)
        DebugLog("Get Knocked State >> %0.2f", *afReturnValue);
    return true;
}
