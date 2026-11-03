// fallout/ai/movement/virtualactorpathhandler.cpp: VirtualActorPathHandler, VirtualActorPathHandlerS, DoorPathHandler (16 functions)

#include "virtualactorpathhandler_decls.h"
#include "LowProcess.h"
#include "virtualactorpathhandler_types_PathingSolution.h"
#include "virtualactorpathhandler_types_NiPlane.h"
#include "virtualactorpathhandler_types_PackageLocation.h"
#include "virtualactorpathhandler_types_PathingRequest.h"
#include "virtualactorpathhandler_types_VirtualActorPathHandler.h"

// Resets two members to 0 and clears a third member by setting it to 0.
// @fnv 0x009eb040
void VirtualActorPathHandler::SetInitialPathState()
{
    pCurrentPathingSolution.Reset(0);
    m_pPathingRequest.Reset(0);
    m_uiPathPointIndex = 0;
}

// @fnv 0x009eb3e0
void VirtualActorPathHandler::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(&m_uiPathPointIndex, 4);
    buffer->ReadTypedData(&m_fPathValue16, 4);
    buffer->ReadTypedData(&m_fPathValue2, 4);
}

// @fnv 0x009ea770
VirtualActorPathHandler::VirtualActorPathHandler(Actor* actor, ActorMover* mover, NiPointer<PathingSolution>& path,
                                                 PathingRequest* request)
{
    ActorPathHandler::FUN_009dfe40(actor, mover, &path, request);
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&VirtualActorPathHandler_vtbl);
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = 0.0f;
}

// @fnv 0x009ea820
int VirtualActorPathHandler::Init(float startIndex, float amount)
{
    m_uiPathPointIndex = (unsigned int)startIndex;
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = pCurrentPathingSolution.operator PathingSolution*()->CalculatePathLength();
    if (startIndex == 0.0)
        return ((VirtualActorPathHandlerVtableCaller*)this)->Slot3(amount);
    else
        return 0;
}

class NiPoint3_ext : public NiPoint3
{
  public:
    NiPoint3_ext();
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3_ext& operator*=(float);
    NiPoint3_ext& operator+=(const NiPoint3&);
    float Length() const;
};
class PathingLocationS
{
  public:
    NiPoint3_ext GetPosition() const;
};
class VirtualPathingNodeS
{
  public:
    PathingLocationS& GetLocation();
    bool IsTransitionNode();
};
class PathingSolutionS
{
  public:
    VirtualPathingNodeS* GetVirtualNode(unsigned int);
};
class PathingRequestS
{
  public:
    float GetCenterRadius() const;
};
class BaseProcessS
{
  public:
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual void V216();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void V233();
    virtual void V234();
    virtual void V235();
    virtual void V236();
    virtual void V237();
    virtual void V238();
    virtual void V239();
    virtual void V240();
    virtual void V241();
    virtual void V242();
    virtual void V243();
    virtual void V244();
    virtual void V245();
    virtual void V246();
    virtual void V247();
    virtual void V248();
    virtual void V249();
    virtual void V250();
    virtual void V251();
    virtual void V252();
    virtual void V253();
    virtual void V254();
    virtual void V255();
    virtual void V256();
    virtual void V257();
    virtual void V258();
    virtual void V259();
    virtual void V260();
    virtual void V261();
    virtual void V262();
    virtual void V263();
    virtual void V264();
    virtual void V265();
    virtual void V266();
    virtual void V267();
    virtual void V268();
    virtual void V269();
    virtual void V270();
    virtual void V271();
    virtual void V272();
    virtual void V273();
    virtual void V274();
    virtual void V275();
    virtual void V276();
    virtual void V277();
    virtual void V278();
    virtual void V279();
    virtual void V280();
    virtual void V281();
    virtual void V282();
    virtual void V283();
    virtual void V284();
    virtual void V285();
    virtual void V286();
    virtual void V287();
    virtual void V288();
    virtual void V289();
    virtual void V290();
    virtual void V291();
    virtual void V292();
    virtual void V293();
    virtual void V294();
    virtual void V295();
    virtual void V296();
    virtual void V297();
    virtual void V298();
    virtual void V299();
    virtual void V300();
    virtual void V301();
    virtual void V302();
    virtual int IsInDialogue();
    float GetLastUpdateHour() const;
};
class ActorS
{
  public:
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual const NiPoint3* GetPos() const;
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void SetFurnitureHeading(float);
    BaseProcess* GetCurrentProcess() const;
    bool FUN_008bc7f0(PlayerCharacter*);
    bool HasCombatState();
    float GetCurrentMovementSpeed();
    TESWorldSpace* GetParentWorldSpace();
    TESObjectCELL* GetParentCell();
    void FUN_008ad1c0(NiPoint3&, float, TESObjectCELL*, TESWorldSpace*, unsigned char, unsigned char);
    int GetProcessTier();
};
class PlayerS
{
  public:
    bool IsSleepingOrResting();
};
class Calendar
{
  public:
    float GetGameTimeScale();
};
extern Calendar g_calendar;
extern double _gModifierZero;
extern const double _DAT_01012640;
extern const double DAT_010848d0;
extern float DAT_011e0358;
extern const NiPoint3 NiPoint3_ZERO;
float __cdecl GetDirectionAngle(const NiPoint3&);
struct FUN_009ea8a0_cls : public VirtualActorPathHandler
{
    int UpdatePathMovement(float);
};

// Advances the actor along its path solution by the distance it can travel this frame, updating position, angle and path index, and returns a status code.
// @fnv 0x009ea8a0
int FUN_009ea8a0_cls::UpdatePathMovement(float afDeltaT)
{
    float fdelta = afDeltaT;
    BaseProcess* pprocess = ((ActorS*)pActor)->GetCurrentProcess();
    if (pprocess && ((BaseProcessS*)pprocess)->IsInDialogue())
        return 0;
    if (((PlayerS*)g_thePlayer)->IsSleepingOrResting() || ((ActorS*)pActor)->FUN_008bc7f0(g_thePlayer))
    {
        fdelta = _DAT_01012640 / g_calendar.GetGameTimeScale();
    }
    else if (!((ActorS*)pActor)->HasCombatState())
    {
        fdelta = DAT_010848d0 / g_calendar.GetGameTimeScale();
        BaseProcess* pactorProcess = ((ActorS*)pActor)->GetCurrentProcess();
        if (pactorProcess)
            fdelta = (DAT_011e0358 - ((BaseProcessS*)pactorProcess)->GetLastUpdateHour()) * _DAT_01012640 /
                     g_calendar.GetGameTimeScale();
    }
    if (m_uiPathPointIndex >= ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320())
        return 5;
    NiPoint3 currentLoc = *((ActorS*)pActor)->GetPos();
    NiPoint3 deltaToNode = NiPoint3_ZERO;
    NiPoint3_ext nextLoc;
    float fdistCanTravel = ((ActorS*)pActor)->GetCurrentMovementSpeed() * fdelta;
    float fdistToNode = 0;
    while (fdistCanTravel >= _gModifierZero)
    {
        nextLoc = ((PathingSolutionS*)(PathingSolution*)pCurrentPathingSolution)
                      ->GetVirtualNode(m_uiPathPointIndex)
                      ->GetLocation()
                      .GetPosition();
        deltaToNode = nextLoc - currentLoc;
        fdistToNode = static_cast<NiPoint3_ext&>(deltaToNode).Length();
        if (fdistCanTravel >= fdistToNode)
        {
            m_fPathValue16 += fdistToNode;
            fdistCanTravel -= fdistToNode;
            currentLoc = nextLoc;
            float fangle = GetDirectionAngle(deltaToNode);
            ((ActorS*)pActor)->SetFurnitureHeading(fangle);
            if (((PathingSolutionS*)(PathingSolution*)pCurrentPathingSolution)
                    ->GetVirtualNode(m_uiPathPointIndex)
                    ->IsTransitionNode())
            {
                switch (GetVirtualNodeIndexAtPosition(currentLoc))
                {
                case -2:
                case -1:
                    return 3;
                case 1:
                    ((ActorS*)pActor)
                        ->FUN_008ad1c0(currentLoc, fangle, ((ActorS*)pActor)->GetParentCell(),
                                       ((ActorS*)pActor)->GetParentWorldSpace(), 1, 0);
                    return 0;
                }
            }
            else
            {
                ((ActorS*)pActor)
                    ->FUN_008ad1c0(currentLoc, fangle, ((ActorS*)pActor)->GetParentCell(),
                                   ((ActorS*)pActor)->GetParentWorldSpace(), 1, 0);
                if (((ActorS*)pActor)->GetProcessTier() == 0 && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
                    return 0;
                m_uiPathPointIndex++;
            }
            if (m_uiPathPointIndex >= ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320())
                return 5;
        }
        else
        {
            break;
        }
    }
    float fscale = fdistToNode != _gModifierZero ? 1.0 - (fdistToNode - fdistCanTravel) / fdistToNode : 0.0;
    static_cast<NiPoint3_ext&>(deltaToNode) *= fscale;
    static_cast<NiPoint3_ext&>(currentLoc) += deltaToNode;
    m_fPathValue16 += static_cast<NiPoint3_ext&>(deltaToNode).Length();
    float fangle = GetDirectionAngle(deltaToNode);
    ((ActorS*)pActor)->SetFurnitureHeading(fangle);
    ((ActorS*)pActor)
        ->FUN_008ad1c0(currentLoc, fangle, ((ActorS*)pActor)->GetParentCell(), ((ActorS*)pActor)->GetParentWorldSpace(), 1,
                       0);
    if (((ActorS*)pActor)->GetProcessTier() == 0 && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
        return 0;
    if (pCurrentPathingSolution &&
        m_uiPathPointIndex + 1 == ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320() &&
        ((PathingRequestS*)(PathingRequest*)m_pPathingRequest)->GetCenterRadius() + fdistCanTravel >= fdistToNode)
    {
        m_uiPathPointIndex++;
        return 5;
    }
    return 0;
}

extern "C" float __cdecl FUN_00404010(float, float);

struct FUN_009eb070_shell : VirtualActorPathHandler
{
    float FUN_009eb070();
};

// @fnv 0x009eb070
float FUN_009eb070_shell::FUN_009eb070()
{
    float flength = ((float*)this)[7] - ((float*)this)[6];
    flength = FUN_00404010(flength, 0.0f);
    return flength;
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct VirtualActorPathHandlerS
{
    void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Saves three 4-byte values at offsets 0x14, 0x18 and 0x1c of this object into the save buffer.
// @fnv 0x009eb390
void VirtualActorPathHandlerS::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((char*)this + 0x14, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x18, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x1c, 4, 0);
}

void __cdecl _Deallocate(void*);
struct FUN_009ea7c0_host
{
    void FUN_009ea7c0();
};
struct FUN_009ea740_shell
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_009ea7c0 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009ea740
void* FUN_009ea740_shell::DestroyIfFlagged(unsigned int flags)
{
    ((FUN_009ea7c0_host*)this)->FUN_009ea7c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Base_009e03e0
{
    virtual ~Base_009e03e0();
};
struct FUN_009ea7c0 : Base_009e03e0
{
    virtual ~FUN_009ea7c0();
};
// @fnv 0x009ea7c0
FUN_009ea7c0::~FUN_009ea7c0()
{
    ((VirtualActorPathHandler*)this)->SetInitialPathState();
}

struct FUN_009ead60_This
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual int V003(float);
    int FUN_009ead60(float afDeltaT);
};
// Forwards the delta time to the virtual method V003 and returns its result.
// @fnv 0x009ead60
int FUN_009ead60_This::FUN_009ead60(float afDeltaT)
{
    return V003(afDeltaT);
}

struct Flt
{
    operator unsigned int();
};
extern unsigned int __fastcall FUN_005a4320(char*);
extern double gModifierZero;
struct FUN_009eb0b0_shell
{
    char b[0x14];
    unsigned int m_uiPathPointIndex;
    float m_fPathValue16;
    float m_fPathValue2;
    Flt mFlt;
    float FUN_009eb0b0();
};
// @fnv 0x009eb0b0
float FUN_009eb0b0_shell::FUN_009eb0b0()
{
    if (!reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int())
        return 0.0f;
    if (m_uiPathPointIndex >=
            FUN_005a4320(reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int())) ||
        m_fPathValue2 <= gModifierZero)
        return 1.0f;
    return m_fPathValue16 / m_fPathValue2;
}

struct Helper009eb120
{
    virtual void V0();
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
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual void V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual const NiPoint3& GetPt();
};
struct Holder009eb120
{
    int _pad;
    Helper009eb120* m;
    NiPoint3 GetPoint(float f);
};
// Returns the NiPoint3 obtained from the helper object's GetPt().
// @fnv 0x009eb120
NiPoint3 Holder009eb120::GetPoint(float afUnused)
{
    return m->GetPt();
}

struct PathingLocation_helper
{
    NiPoint3 GetLocation() const;
};

struct PathingNode_helper
{
    PathingLocation_helper& GetLocation();
};

struct FUN_009ddb30Class
{
    PathingNode_helper* FUN_009ddb30();
};

struct PathingSolution_helper : FUN_009ddb30Class
{
    unsigned int GetNodeCount();
    PathingNode_helper* GetVirtualNode(unsigned int);
};

struct RefWithPos
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual const NiPoint3* GetStartingPos();
};

struct FUN_009eb160_shell
{
    NiPoint3 GetNextPathPoint() const;
};

// Returns the position of the next path node, the virtual node, or the starting position when the solution has no nodes.
// @fnv 0x009eb160
NiPoint3 FUN_009eb160_shell::GetNextPathPoint() const
{
    if (((PathingSolution_helper*)(PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))->GetNodeCount() >
        0)
    {
        if (*(unsigned int*)((char*)this + 0x14) + 1 <
            (*(NiPointer<PathingSolution>*)((char*)this + 0xc))->FUN_005a4320())
        {
            return ((PathingSolution_helper*)(PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
                ->GetVirtualNode(*(unsigned int*)((char*)this + 0x14) + 1)
                ->GetLocation()
                .GetLocation();
        }
        else
        {
            return ((FUN_009ddb30Class*)(PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
                ->FUN_009ddb30()
                ->GetLocation()
                .GetLocation();
        }
    }
    else
    {
        return *((RefWithPos*)*(void**)((char*)this + 4))->GetStartingPos();
    }
}

namespace fnv_009eb2b0 {
typedef int DEBUGTEXT_LOCATION;
typedef int DEBUGTEXT_JUSTIFY;

struct IDebugText
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Print(DEBUGTEXT_LOCATION aLoc, DEBUGTEXT_JUSTIFY aJust, const char* fmt, ...);
};

struct RefWithPos
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual const NiPoint3* GetStartingPos();
};

struct FUN_009eb2b0_shell
{
    void PrintPathDebugInfo(IDebugText* apDebugText, DEBUGTEXT_LOCATION aLoc, DEBUGTEXT_JUSTIFY aJust);
};

// Prints the actor's starting position and, if a pathing solution exists, the current path node index and count; otherwise prints "No path".
// @fnv 0x009eb2b0
void FUN_009eb2b0_shell::PrintPathDebugInfo(IDebugText* apDebugText, DEBUGTEXT_LOCATION aLoc, DEBUGTEXT_JUSTIFY aJust)
{
    NiPoint3 loc = *((RefWithPos*)*(void**)((char*)this + 4))->GetStartingPos();
    apDebugText->Print(aLoc, aJust, "VirtualPathHandler: Actor's Positon %1.f %1.f %1.f", loc.x, loc.y, loc.z);

    if ((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
    {
        apDebugText->Print(aLoc, aJust, "Current path node %u of %u", *(unsigned int*)((char*)this + 0x14),
                           (*(NiPointer<PathingSolution>*)((char*)this + 0xc))->FUN_005a4320());
    }
    else
    {
        apDebugText->Print(aLoc, aJust, "No path");
    }
}
}  // namespace fnv_009eb2b0

struct FUN_006e78b0_shell
{
    void* FUN_006e78b0(unsigned int index, NiPoint3* tmp);
};
struct FUN_005c3420_shell
{
    void* FUN_005c3420() const;
};
unsigned int __fastcall FUN_005a4320(void* p);
void* __fastcall FUN_00559450(void* p);
void* __fastcall FUN_00717e50(void* p);

struct FUN_009eb230_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool GetPointAtIndex(unsigned int index, NiPoint3* out);
};

// If the container at unk0c is valid and index is in range, copies the NiPoint3 at that index into out and returns true; otherwise returns false.
// @fnv 0x009eb230
bool FUN_009eb230_class::GetPointAtIndex(unsigned int index, NiPoint3* out)
{
    if (FUN_00559450(&unk0c) != 0)
    {
        if (index < FUN_005a4320(FUN_00559450(&unk0c)))
        {
            NiPoint3 tmp;
            *out = *(NiPoint3*)((FUN_005c3420_shell*)FUN_00717e50(
                                    ((FUN_006e78b0_shell*)FUN_00559450(&unk0c))->FUN_006e78b0(index, &tmp)))
                        ->FUN_005c3420();
            return true;
        }
    }
    return false;
}

bool __cdecl FUN_008c7aa0();
struct DoorReference : TESObjectREFR
{
    void FUN_00575830(const NiPoint3&);
    bool Activate(Actor*, bool, TESBoundObject*, int);
    int FUN_00474cb0();
    const char* FUN_0055d520();
    int GetCellLoadState();
};
struct DoorPathNode
{
    DoorReference* FUN_0055b980();
};
struct CellNameView : TESForm
{
    FullNameCall fullName;
    int FUN_00474cb0();
};
struct PointComparison : NiPoint3
{
    bool FUN_00439090(const NiPoint3&);
};
struct PointMagnitude : NiPoint3
{
    float GetSquaredXYLength();
};
struct DoorPathHandler : VirtualActorPathHandler
{
    int UpdateDoorPath(NiPoint3& position);
};
// Advances the door path node, moves the actor through the door, and returns -1, -2, 1 or 0 depending on the next node and actor position checks.
// @fnv 0x009ead90
int DoorPathHandler::UpdateDoorPath(NiPoint3& position)
{
    if (FUN_008c7aa0())
    {
        ((UseDoorCalls*)FUN_004537b0(pActor, position))->QueueActorLocationTask();
        ((UseDoorCalls*)FUN_004537b0(pActor))->QueueActorTask();
    }
    else
    {
        ((DoorReference*)pActor)->FUN_00575830(position);
    }
    DoorReference* pPathNodeDoor =
        ((DoorPathNode*)((PathingSolution*)pCurrentPathingSolution)->FUN_006e78b0(m_uiPathPointIndex))->FUN_0055b980();
    ++m_uiPathPointIndex;
    if (pPathNodeDoor && !pPathNodeDoor->Activate(pActor, false, 0, 1))
        return -1;
    if ((PathingSolution*)pCurrentPathingSolution &&
        m_uiPathPointIndex < ((PathingSolution*)pCurrentPathingSolution)->FUN_005a4320())
    {
        NiPoint3 actorPosition = *pActor->GetPos();
        float distance =
            ((PointMagnitude&)(actorPosition - ((PathingSolutionS*)(PathingSolution*)pCurrentPathingSolution)
                                                   ->GetVirtualNode(m_uiPathPointIndex)
                                                   ->GetLocation()
                                                   .GetPosition()))
                .GetSquaredXYLength();
        if (distance > DAT_0102f078)
        {
            if (((PointComparison&)position).FUN_00439090(actorPosition))
            {
                Warning(
                    "PATHFINDING: Actor %s used teleport door %s in cell %s and was not moved to the expected pathing location, check teleport marker",
                    ((DoorReference*)pActor)->FUN_00474cb0() ? pActor->GetName()
                                                             : ((DoorReference*)pActor)->FUN_0055d520(),
                    pPathNodeDoor->GetName(),
                    pPathNodeDoor->GetParentCell() ? (((CellNameView*)pPathNodeDoor->GetParentCell())->FUN_00474cb0()
                                                  ? ((CellNameView*)pPathNodeDoor->GetParentCell())->fullName.GetFullName()
                                                  : ((TESForm*)pPathNodeDoor->GetParentCell())->GetName())
                                           : "");
            }
            return -2;
        }
    }
    position = *pActor->GetPos();
    if (!((DoorReference*)pActor)->GetCellLoadState() && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
    {
        ++m_uiPathPointIndex;
        m_fPathValue16 = 0.0f;
        return 1;
    }
    return 0;
}
