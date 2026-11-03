// src/fallout/ai/middlehighprocess_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/middlehighprocess.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "middlehighprocess_decls.h"
bool IsValidSandboxProcedure(int aiProcedure);

// 0x00918120  /MT /Od /Oy- /GS /EHsc /Gy

struct NiP3
{
    float x;
    float y;
    float z;
};
struct TESSound;
struct Setting_S
{
    float f;
};
class PlayerS
{
  public:
    bool IsSleepingOrResting();
};
class TESPackage
{
  public:
    virtual void tq_test();
};
class TrespassPackage : public TESPackage
{
  public:
    virtual void tp_test();
    int FUN_009185e0();
    float FUN_00644790();
    void FUN_008db4c0(float);
};
class HighProcess : public BaseProcess
{
  public:
    virtual void hp_test();
};
class Character : public Actor
{
  public:
    virtual void ch_test();
};
struct EffectSetting
{
    TESSound* GetBoltSound();
};
struct TimeGlobal
{
    float FUN_0084d030();
};
struct originalRuntimeFloatSetting1295_t
{
    Setting_S* Float();
};
struct ActShell
{
    void FUN_008bb520(NiP3 p, int a);
    float FUN_005723b0(TESObjectREFR* r, int a, int b);
    bool FUN_008a61b0();
    bool FUN_008b3bb0();
};
struct ZZ1
{
    char c;
};
struct ZZ2
{
    short c;
};
struct ZZ4
{
    int c;
};
struct ZZ8
{
    int c;
    int d;
};
struct ZZ12
{
    int c;
    int d;
    int e;
};
struct TgtShell
{
    void UpdateTargetUnits(Actor* a, int b, int c);
};
struct Pl20c
{
    char pad[0x20c];
    unsigned char b;
};
struct FUN_008a08c0_Class
{
    unsigned char GetByteAt7C4();
};
struct FUN_005c1a00
{
    void Set(int a, char b);
};
struct FUN_005a03f0_obj
{
    bool FUN_005a03f0(unsigned int a);
};
struct TESObjectREFR_acc
{
    bool Activate(TESObjectREFR* a, bool b, TESBoundObject* c, int d);
};

struct MidProc
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void v035(Actor* a);
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
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
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual TESPackage* v159();
    virtual void d160();
    virtual void d161();
    virtual void v162(TESObjectREFR* a, int b);
    virtual void d163();
    virtual void d164();
    virtual void v165(Actor* a);
    virtual void v166(Actor* a, bool b, int c, bool d);
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual bool v182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void d196();
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual bool v207(Actor* a, Actor* b, bool c, bool d, void* e, bool f, bool g, bool h, char i, bool j, bool k,
                      bool l, TESPackage* m);
    char pad[0x3c];
    TESObjectREFR* pTarget;
    void FUN_00918120(Actor* a, int b, int c, int d);
};

struct V448
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
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
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void d196();
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void d225();
    virtual void d226();
    virtual void d227();
    virtual void d228();
    virtual void d229();
    virtual void d230();
    virtual void d231();
    virtual void d232();
    virtual void d233();
    virtual void d234();
    virtual void d235();
    virtual void d236();
    virtual void d237();
    virtual void d238();
    virtual void d239();
    virtual void d240();
    virtual void d241();
    virtual void d242();
    virtual void d243();
    virtual void d244();
    virtual void d245();
    virtual void d246();
    virtual void d247();
    virtual void d248();
    virtual void d249();
    virtual void d250();
    virtual void d251();
    virtual void d252();
    virtual void d253();
    virtual void d254();
    virtual void d255();
    virtual void d256();
    virtual void d257();
    virtual void d258();
    virtual void d259();
    virtual void d260();
    virtual void d261();
    virtual void d262();
    virtual void d263();
    virtual void d264();
    virtual void d265();
    virtual void d266();
    virtual void d267();
    virtual void d268();
    virtual void d269();
    virtual void d270();
    virtual void d271();
    virtual void d272();
    virtual void d273();
    virtual bool v448();
};

struct V1f4
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
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
    virtual NiP3* v1f4();
};

extern "C" Actor* g_thePlayer;
extern "C" TimeGlobal DAT_011f6394;
extern "C" originalRuntimeFloatSetting1295_t DAT_011cd2c4;
extern "C" double DAT_010179e0;

// @fnv 0x00918120
void MidProc::FUN_00918120(Actor* pActor, int a2, int a3, int a4)
{
    if (this->pTarget == 0)
        this->v035(pActor);

    if (this->pTarget == g_thePlayer && ((FUN_005a03f0_obj*)g_thePlayer)->FUN_005a03f0(8))
    {
        this->v165(pActor);
        return;
    }

    TrespassPackage* pPkg = dynamic_cast<TrespassPackage*>(this->v159());
    TESObjectREFR* pTgt = this->pTarget;

    if (pPkg && pTgt && !((V448*)pTgt)->v448())
    {
        this->v162(pTgt, 2);
        return;
    }

    if (((ActShell*)pActor)->FUN_005723b0(this->pTarget, 0, 0) > DAT_010179e0)
    {
        this->v166(pActor, false, a4, true);
        return;
    }

    if (!((ActShell*)pActor)->FUN_008b3bb0())
        this->v165(pActor);

    if (this->pTarget)
    {
        HighProcess* pHi = dynamic_cast<HighProcess*>(pActor->GetProcess());
        if (pHi && pActor->GetProcess() && !pActor->GetProcess()->GetSitSleepState())
        {
            ((ActShell*)pActor)->FUN_008bb520(*((V1f4*)this->pTarget)->v1f4(), 0);
        }
    }

    if (pPkg)
    {
        Actor* pA = dynamic_cast<Actor*>(this->pTarget);
        if (pA && !((V448*)pA)->v448())
        {
            this->v162(pActor, 2);
            return;
        }
        if (!pPkg->FUN_009185e0() ||
            ((int)((EffectSetting*)pPkg)->GetBoltSound() > pPkg->FUN_009185e0() && pPkg->FUN_00644790() <= 0.0))
        {
            if (pTgt)
            {
                ((TgtShell*)pTgt)->UpdateTargetUnits(pActor, 0, -1);
                return;
            }
        }
        if (pPkg->FUN_00644790() <= 0.0)
        {
            this->v162(pActor, 1);
            return;
        }
        pPkg->FUN_008db4c0((float)(DAT_011f6394.FUN_0084d030() * -1.0));
        if (pPkg->FUN_00644790() > *(float*)DAT_011cd2c4.Float())
            pPkg->FUN_008db4c0((float)(pPkg->FUN_00644790() * -1.0));
    }

    Character* pChr = dynamic_cast<Character*>(this->pTarget);
    Actor* pA2 = dynamic_cast<Actor*>(this->pTarget);

    if (((ActShell*)pActor)->FUN_008a61b0() && pA2)
    {
        if (pChr == g_thePlayer)
        {
            if (this->pTarget == g_thePlayer && ((PlayerS*)g_thePlayer)->IsSleepingOrResting() &&
                !((Pl20c*)g_thePlayer)->b)
            {
                ((FUN_005c1a00*)g_thePlayer)->Set(0, 1);
                return;
            }
            if (!this->v182() && !((FUN_008a08c0_Class*)g_thePlayer)->GetByteAt7C4())
            {
                if (((TESObjectREFR_acc*)g_thePlayer)->Activate(pActor, 0, 0, 1))
                    this->v162(pActor, 1);
            }
            else
            {
                if (((FUN_008a08c0_Class*)g_thePlayer)->GetByteAt7C4())
                {
                    bool bCombat = this->v207(pActor, g_thePlayer, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
                }
            }
            if (0)
            {
            }
        }
        else
        {
            this->v162(pActor, 2);
            this->v207(pActor, pA2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
        }
    }
}

struct FleeVec3
{
    float x;
    float y;
    float z;
};
struct FleeRadius
{
    int FUN_0044ddc0();
};
__if_not_exists(TESPackage::TESPackage)
{
    class TESPackage
    {
      public:
        virtual ~TESPackage();
    };
}

class FleePackageAccess
{
  public:
    virtual void p_000();
    virtual void p_001();
    virtual void p_002();
    virtual void p_003();
    virtual void p_004();
    virtual void p_005();
    virtual void p_006();
    virtual void p_007();
    virtual void p_008();
    virtual void p_009();
    virtual void p_00a();
    virtual void p_00b();
    virtual void p_00c();
    virtual void p_00d();
    virtual void p_00e();
    virtual void p_00f();
    virtual void p_010();
    virtual void p_011();
    virtual void p_012();
    virtual void p_013();
    virtual void p_014();
    virtual void p_015();
    virtual void p_016();
    virtual void p_017();
    virtual void p_018();
    virtual void p_019();
    virtual void p_01a();
    virtual void p_01b();
    virtual void p_01c();
    virtual void p_01d();
    virtual void p_01e();
    virtual void p_01f();
    virtual void p_020();
    virtual void p_021();
    virtual void p_022();
    virtual void p_023();
    virtual void p_024();
    virtual void p_025();
    virtual void p_026();
    virtual void p_027();
    virtual void p_028();
    virtual void p_029();
    virtual void p_02a();
    virtual void p_02b();
    virtual void p_02c();
    virtual void p_02d();
    virtual void p_02e();
    virtual void p_02f();
    virtual void p_030();
    virtual void p_031();
    virtual void p_032();
    virtual void p_033();
    virtual void p_034();
    virtual void p_035();
    virtual void p_036();
    virtual void p_037();
    virtual void p_038();
    virtual void p_039();
    virtual void p_03a();
    virtual void p_03b();
    virtual void p_03c();
    virtual void p_03d();
    virtual void p_03e();
    virtual void p_03f();
    virtual void p_040();
    virtual void p_041();
    virtual void p_042();
    virtual void p_043();
    virtual void p_044();
    virtual void p_045();
    virtual void p_046();
    virtual void p_047();
    virtual void p_048();
    virtual void p_049();
    virtual void p_04a();
    virtual void p_04b();
    virtual void p_04c();
    virtual void p_04d();
    virtual void p_04e();
    virtual bool Check13c(Actor* actor, int a, float b, int c);
    FleeRadius* FUN_00671d10();
    unsigned int FUN_00676280(Actor* actor);
    void* FUN_00675c20(Actor* actor);
    void FUN_00675de0(FleeVec3* pos, Actor* actor);
};
class FleePackage : public TESPackage
{
  public:
    void FUN_009f1310(Actor* target);
};
struct FleeActorView
{
    virtual void a_000();
    virtual void a_001();
    virtual void a_002();
    virtual void a_003();
    virtual void a_004();
    virtual void a_005();
    virtual void a_006();
    virtual void a_007();
    virtual void a_008();
    virtual void a_009();
    virtual void a_00a();
    virtual void a_00b();
    virtual void a_00c();
    virtual void a_00d();
    virtual void a_00e();
    virtual void a_00f();
    virtual void a_010();
    virtual void a_011();
    virtual void a_012();
    virtual void a_013();
    virtual void a_014();
    virtual void a_015();
    virtual void a_016();
    virtual void a_017();
    virtual void a_018();
    virtual void a_019();
    virtual void a_01a();
    virtual void a_01b();
    virtual void a_01c();
    virtual void a_01d();
    virtual void a_01e();
    virtual void a_01f();
    virtual void a_020();
    virtual void a_021();
    virtual void a_022();
    virtual void a_023();
    virtual void a_024();
    virtual void a_025();
    virtual void a_026();
    virtual void a_027();
    virtual void a_028();
    virtual void a_029();
    virtual void a_02a();
    virtual void a_02b();
    virtual void a_02c();
    virtual void a_02d();
    virtual void a_02e();
    virtual void a_02f();
    virtual void a_030();
    virtual void a_031();
    virtual void a_032();
    virtual void a_033();
    virtual void a_034();
    virtual void a_035();
    virtual void a_036();
    virtual void a_037();
    virtual void a_038();
    virtual void a_039();
    virtual void a_03a();
    virtual void a_03b();
    virtual void a_03c();
    virtual void a_03d();
    virtual void a_03e();
    virtual void a_03f();
    virtual void a_040();
    virtual void a_041();
    virtual void a_042();
    virtual void a_043();
    virtual void a_044();
    virtual void a_045();
    virtual void a_046();
    virtual void a_047();
    virtual void a_048();
    virtual void a_049();
    virtual void a_04a();
    virtual void a_04b();
    virtual void a_04c();
    virtual void a_04d();
    virtual void a_04e();
    virtual void a_04f();
    virtual void a_050();
    virtual void a_051();
    virtual void a_052();
    virtual void a_053();
    virtual void a_054();
    virtual void a_055();
    virtual void a_056();
    virtual void a_057();
    virtual void a_058();
    virtual void a_059();
    virtual void a_05a();
    virtual void a_05b();
    virtual void a_05c();
    virtual void a_05d();
    virtual void a_05e();
    virtual void a_05f();
    virtual void a_060();
    virtual void a_061();
    virtual void a_062();
    virtual void a_063();
    virtual void a_064();
    virtual void a_065();
    virtual void a_066();
    virtual void a_067();
    virtual void a_068();
    virtual void a_069();
    virtual void a_06a();
    virtual void a_06b();
    virtual void a_06c();
    virtual void a_06d();
    virtual void a_06e();
    virtual void a_06f();
    virtual void a_070();
    virtual void a_071();
    virtual void a_072();
    virtual void a_073();
    virtual void a_074();
    virtual void a_075();
    virtual void a_076();
    virtual void a_077();
    virtual void a_078();
    virtual void a_079();
    virtual void a_07a();
    virtual void a_07b();
    virtual void a_07c();
    virtual void a_07d();
    virtual void a_07e();
    virtual void a_07f();
    virtual void a_080();
    virtual void a_081();
    virtual void a_082();
    virtual void a_083();
    virtual void a_084();
    virtual void a_085();
    virtual void a_086();
    virtual void a_087();
    virtual void a_088();
    virtual void a_089();
    virtual void a_08a();
    virtual void a_08b();
    virtual void a_08c();
    virtual void a_08d();
    virtual void a_08e();
    virtual void a_08f();
    virtual void a_090();
    virtual void a_091();
    virtual void a_092();
    virtual void a_093();
    virtual void a_094();
    virtual void a_095();
    virtual void a_096();
    virtual void a_097();
    virtual void a_098();
    virtual void a_099();
    virtual void a_09a();
    virtual void a_09b();
    virtual void a_09c();
    virtual void a_09d();
    virtual void a_09e();
    virtual void a_09f();
    virtual void a_0a0();
    virtual void a_0a1();
    virtual void a_0a2();
    virtual void a_0a3();
    virtual void a_0a4();
    virtual void a_0a5();
    virtual void a_0a6();
    virtual void a_0a7();
    virtual void a_0a8();
    virtual void a_0a9();
    virtual void a_0aa();
    virtual void a_0ab();
    virtual void a_0ac();
    virtual void a_0ad();
    virtual void a_0ae();
    virtual void a_0af();
    virtual void a_0b0();
    virtual void a_0b1();
    virtual void a_0b2();
    virtual void a_0b3();
    virtual void a_0b4();
    virtual void a_0b5();
    virtual void a_0b6();
    virtual void a_0b7();
    virtual void a_0b8();
    virtual void a_0b9();
    virtual void a_0ba();
    virtual void a_0bb();
    virtual void a_0bc();
    virtual void a_0bd();
    virtual void a_0be();
    virtual void a_0bf();
    virtual void a_0c0();
    virtual void a_0c1();
    virtual void a_0c2();
    virtual void a_0c3();
    virtual void a_0c4();
    virtual void a_0c5();
    virtual void a_0c6();
    virtual void a_0c7();
    virtual void a_0c8();
    virtual void a_0c9();
    virtual void a_0ca();
    virtual void a_0cb();
    virtual void a_0cc();
    virtual void a_0cd();
    virtual void a_0ce();
    virtual void a_0cf();
    virtual void a_0d0();
    virtual void a_0d1();
    virtual void a_0d2();
    virtual void a_0d3();
    virtual void a_0d4();
    virtual void a_0d5();
    virtual void a_0d6();
    virtual void a_0d7();
    virtual void a_0d8();
    virtual void a_0d9();
    virtual void a_0da();
    virtual void a_0db();
    virtual void a_0dc();
    virtual void a_0dd();
    virtual void a_0de();
    virtual void a_0df();
    virtual void a_0e0();
    virtual void a_0e1();
    virtual void a_0e2();
    virtual void a_0e3();
    virtual void a_0e4();
    virtual void a_0e5();
    virtual void a_0e6();
    virtual void a_0e7();
    virtual void a_0e8();
    virtual void a_0e9();
    virtual void a_0ea();
    virtual void a_0eb();
    virtual void a_0ec();
    virtual void a_0ed();
    virtual void a_0ee();
    virtual void a_0ef();
    virtual void a_0f0();
    virtual void a_0f1();
    virtual void a_0f2();
    virtual void a_0f3();
    virtual void a_0f4();
    virtual void a_0f5();
    virtual void a_0f6();
    virtual void a_0f7();
    virtual void a_0f8();
    virtual void a_0f9();
    virtual void a_0fa();
    virtual void a_0fb();
    virtual void a_0fc();
    virtual void a_0fd();
    virtual void a_0fe();
    virtual void a_0ff();
    virtual void a_100();
    virtual void a_101();
    virtual void a_102();
    virtual void a_103();
    virtual void Set410(Actor* actor, int a, int b, int c, int d, int e, float f, float g);
    float FUN_005723b0(TESObjectREFR* target, int a, int b);
    bool FUN_008b3bb0();
    void* FUN_00575d70();
};
struct FleeProcedure
{
    virtual void s_000();
    virtual void s_001();
    virtual void s_002();
    virtual void s_003();
    virtual void s_004();
    virtual void s_005();
    virtual void s_006();
    virtual void s_007();
    virtual void s_008();
    virtual void s_009();
    virtual void s_00a();
    virtual void s_00b();
    virtual void s_00c();
    virtual void s_00d();
    virtual void s_00e();
    virtual void s_00f();
    virtual void s_010();
    virtual void s_011();
    virtual void s_012();
    virtual void s_013();
    virtual void s_014();
    virtual void s_015();
    virtual void s_016();
    virtual void s_017();
    virtual void s_018();
    virtual void s_019();
    virtual void s_01a();
    virtual void s_01b();
    virtual void s_01c();
    virtual void s_01d();
    virtual void s_01e();
    virtual void s_01f();
    virtual void s_020();
    virtual void s_021();
    virtual void s_022();
    virtual void Begin8c(Actor* actor);
    virtual void Begin90(Actor* actor, int a);
    virtual void s_025();
    virtual void s_026();
    virtual void s_027();
    virtual void s_028();
    virtual void s_029();
    virtual void s_02a();
    virtual void s_02b();
    virtual void s_02c();
    virtual void s_02d();
    virtual void s_02e();
    virtual void s_02f();
    virtual void s_030();
    virtual void s_031();
    virtual void s_032();
    virtual void s_033();
    virtual void s_034();
    virtual void s_035();
    virtual void s_036();
    virtual void s_037();
    virtual void s_038();
    virtual void s_039();
    virtual void s_03a();
    virtual void s_03b();
    virtual void s_03c();
    virtual void s_03d();
    virtual void s_03e();
    virtual void s_03f();
    virtual void s_040();
    virtual void s_041();
    virtual void s_042();
    virtual void s_043();
    virtual void s_044();
    virtual void s_045();
    virtual void s_046();
    virtual void s_047();
    virtual void s_048();
    virtual void s_049();
    virtual void s_04a();
    virtual void s_04b();
    virtual void s_04c();
    virtual void s_04d();
    virtual void s_04e();
    virtual void s_04f();
    virtual void s_050();
    virtual void s_051();
    virtual void s_052();
    virtual void s_053();
    virtual void s_054();
    virtual void s_055();
    virtual void s_056();
    virtual void s_057();
    virtual void s_058();
    virtual void s_059();
    virtual void s_05a();
    virtual void s_05b();
    virtual void s_05c();
    virtual void s_05d();
    virtual void s_05e();
    virtual void s_05f();
    virtual void s_060();
    virtual void s_061();
    virtual void s_062();
    virtual void s_063();
    virtual void s_064();
    virtual void s_065();
    virtual void s_066();
    virtual void s_067();
    virtual void s_068();
    virtual void s_069();
    virtual void s_06a();
    virtual void s_06b();
    virtual void s_06c();
    virtual void s_06d();
    virtual void s_06e();
    virtual void s_06f();
    virtual void s_070();
    virtual void s_071();
    virtual void s_072();
    virtual void s_073();
    virtual void s_074();
    virtual void s_075();
    virtual void s_076();
    virtual void s_077();
    virtual void s_078();
    virtual void s_079();
    virtual void s_07a();
    virtual void s_07b();
    virtual void s_07c();
    virtual void s_07d();
    virtual void s_07e();
    virtual void s_07f();
    virtual void s_080();
    virtual void s_081();
    virtual void s_082();
    virtual void s_083();
    virtual void s_084();
    virtual void s_085();
    virtual void s_086();
    virtual void s_087();
    virtual void s_088();
    virtual void s_089();
    virtual void s_08a();
    virtual void s_08b();
    virtual void s_08c();
    virtual void s_08d();
    virtual void s_08e();
    virtual void s_08f();
    virtual void s_090();
    virtual void s_091();
    virtual void s_092();
    virtual void s_093();
    virtual void s_094();
    virtual void s_095();
    virtual void s_096();
    virtual void s_097();
    virtual void s_098();
    virtual void s_099();
    virtual void s_09a();
    virtual void s_09b();
    virtual void s_09c();
    virtual void s_09d();
    virtual void s_09e();
    virtual TESPackage* GetAssignedPackage();
    virtual void s_0a0();
    virtual void s_0a1();
    virtual void s_0a2();
    virtual void s_0a3();
    virtual void s_0a4();
    virtual void Fail294(Actor* actor);
    virtual void s_0a6();
    virtual void s_0a7();
    virtual void s_0a8();
    virtual void s_0a9();
    virtual void s_0aa();
    virtual void s_0ab();
    virtual void s_0ac();
    virtual void s_0ad();
    virtual void s_0ae();
    virtual void s_0af();
    virtual void s_0b0();
    virtual void s_0b1();
    virtual void s_0b2();
    virtual void s_0b3();
    virtual void s_0b4();
    virtual void s_0b5();
    virtual void s_0b6();
    virtual void s_0b7();
    virtual void s_0b8();
    virtual void s_0b9();
    virtual void s_0ba();
    virtual void s_0bb();
    virtual void s_0bc();
    virtual void s_0bd();
    virtual void s_0be();
    virtual void s_0bf();
    virtual void s_0c0();
    virtual void s_0c1();
    virtual void s_0c2();
    virtual void s_0c3();
    virtual void s_0c4();
    virtual void s_0c5();
    virtual void s_0c6();
    virtual void s_0c7();
    virtual void s_0c8();
    virtual void s_0c9();
    virtual void s_0ca();
    virtual void s_0cb();
    virtual void s_0cc();
    virtual void s_0cd();
    virtual void s_0ce();
    virtual void s_0cf();
    virtual void s_0d0();
    virtual void s_0d1();
    virtual void s_0d2();
    virtual void s_0d3();
    virtual void Run350(Actor* actor, int flags, int a);
    virtual void s_0d5();
    virtual void s_0d6();
    virtual void s_0d7();
    virtual void s_0d8();
    virtual void s_0d9();
    virtual void s_0da();
    virtual void s_0db();
    virtual void s_0dc();
    virtual void s_0dd();
    virtual void s_0de();
    virtual void s_0df();
    virtual void s_0e0();
    virtual void s_0e1();
    virtual void s_0e2();
    virtual void s_0e3();
    virtual void s_0e4();
    virtual void s_0e5();
    virtual void s_0e6();
    virtual void s_0e7();
    virtual void s_0e8();
    virtual void s_0e9();
    virtual void s_0ea();
    virtual void s_0eb();
    virtual void s_0ec();
    virtual void s_0ed();
    virtual void s_0ee();
    virtual void s_0ef();
    virtual void s_0f0();
    virtual void s_0f1();
    virtual void s_0f2();
    virtual void s_0f3();
    virtual void s_0f4();
    virtual void s_0f5();
    virtual void s_0f6();
    virtual void s_0f7();
    virtual void s_0f8();
    virtual void s_0f9();
    virtual void s_0fa();
    virtual void s_0fb();
    virtual void s_0fc();
    virtual void s_0fd();
    virtual void s_0fe();
    virtual void s_0ff();
    virtual void s_100();
    virtual void s_101();
    virtual void s_102();
    virtual void s_103();
    virtual void s_104();
    virtual void s_105();
    virtual void s_106();
    virtual void s_107();
    virtual void s_108();
    virtual void s_109();
    virtual void s_10a();
    virtual void s_10b();
    virtual void s_10c();
    virtual void s_10d();
    virtual void s_10e();
    virtual void s_10f();
    virtual void s_110();
    virtual void s_111();
    virtual void s_112();
    virtual void s_113();
    virtual void s_114();
    virtual void s_115();
    virtual void s_116();
    virtual void s_117();
    virtual void s_118();
    virtual void s_119();
    virtual void s_11a();
    virtual void s_11b();
    virtual void s_11c();
    virtual void s_11d();
    virtual void s_11e();
    virtual void s_11f();
    virtual void s_120();
    virtual void s_121();
    virtual void s_122();
    virtual void s_123();
    virtual void s_124();
    virtual void s_125();
    virtual void s_126();
    virtual void s_127();
    virtual void s_128();
    virtual void s_129();
    virtual void s_12a();
    virtual void s_12b();
    virtual void s_12c();
    virtual void s_12d();
    virtual void s_12e();
    virtual void s_12f();
    virtual void s_130();
    virtual void s_131();
    virtual void s_132();
    virtual void s_133();
    virtual void s_134();
    virtual void s_135();
    virtual void s_136();
    virtual void s_137();
    virtual void s_138();
    virtual void s_139();
    virtual void s_13a();
    virtual void s_13b();
    virtual void s_13c();
    virtual void s_13d();
    virtual void s_13e();
    virtual void s_13f();
    virtual void s_140();
    virtual void s_141();
    virtual void s_142();
    virtual void s_143();
    virtual void s_144();
    virtual void s_145();
    virtual void s_146();
    virtual void s_147();
    virtual void s_148();
    virtual void s_149();
    virtual void s_14a();
    virtual void s_14b();
    virtual void s_14c();
    virtual void s_14d();
    virtual void s_14e();
    virtual void s_14f();
    virtual void s_150();
    virtual void s_151();
    virtual void s_152();
    virtual void s_153();
    virtual void s_154();
    virtual void s_155();
    virtual void s_156();
    virtual void s_157();
    virtual void s_158();
    virtual void s_159();
    virtual void s_15a();
    virtual void s_15b();
    virtual void s_15c();
    virtual void s_15d();
    virtual void s_15e();
    virtual void s_15f();
    virtual void s_160();
    virtual void s_161();
    virtual void s_162();
    virtual void s_163();
    virtual void s_164();
    virtual void s_165();
    virtual void s_166();
    virtual void s_167();
    virtual void s_168();
    virtual void s_169();
    virtual void s_16a();
    virtual void s_16b();
    virtual void s_16c();
    virtual void s_16d();
    virtual void s_16e();
    virtual void s_16f();
    virtual void s_170();
    virtual void s_171();
    virtual void s_172();
    virtual void s_173();
    virtual void s_174();
    virtual void s_175();
    virtual void s_176();
    virtual void s_177();
    virtual void s_178();
    virtual void s_179();
    virtual void s_17a();
    virtual void s_17b();
    virtual void s_17c();
    virtual void s_17d();
    virtual void s_17e();
    virtual void s_17f();
    virtual void s_180();
    virtual void s_181();
    virtual void s_182();
    virtual void s_183();
    virtual void s_184();
    virtual void s_185();
    virtual void s_186();
    virtual void s_187();
    virtual void s_188();
    virtual void s_189();
    virtual void s_18a();
    virtual void s_18b();
    virtual void s_18c();
    virtual void s_18d();
    virtual void s_18e();
    virtual void s_18f();
    virtual void s_190();
    virtual void s_191();
    virtual void s_192();
    virtual void s_193();
    virtual void s_194();
    virtual void s_195();
    virtual void s_196();
    virtual void s_197();
    virtual void s_198();
    virtual void s_199();
    virtual void s_19a();
    virtual void s_19b();
    virtual void s_19c();
    virtual void s_19d();
    virtual void s_19e();
    virtual void s_19f();
    virtual void s_1a0();
    virtual void s_1a1();
    virtual void s_1a2();
    virtual void s_1a3();
    virtual void s_1a4();
    virtual void s_1a5();
    virtual void s_1a6();
    virtual void s_1a7();
    virtual void s_1a8();
    virtual void s_1a9();
    virtual void s_1aa();
    virtual void s_1ab();
    virtual void s_1ac();
    virtual void s_1ad();
    virtual void s_1ae();
    virtual void s_1af();
    virtual void s_1b0();
    virtual void s_1b1();
    virtual void s_1b2();
    virtual void s_1b3();
    virtual void s_1b4();
    virtual void s_1b5();
    virtual void s_1b6();
    virtual void s_1b7();
    virtual void s_1b8();
    virtual void s_1b9();
    virtual void s_1ba();
    virtual void s_1bb();
    virtual void s_1bc();
    virtual void s_1bd();
    virtual void s_1be();
    virtual void s_1bf();
    virtual void s_1c0();
    virtual void s_1c1();
    virtual void s_1c2();
    virtual void s_1c3();
    virtual void s_1c4();
    virtual void s_1c5();
    virtual void s_1c6();
    virtual void s_1c7();
    virtual void s_1c8();
    virtual void s_1c9();
    virtual void s_1ca();
    virtual void s_1cb();
    virtual void s_1cc();
    virtual void s_1cd();
    virtual void s_1ce();
    virtual void s_1cf();
    virtual void s_1d0();
    virtual void s_1d1();
    virtual void s_1d2();
    virtual void s_1d3();
    virtual void s_1d4();
    virtual void s_1d5();
    virtual void s_1d6();
    virtual void s_1d7();
    virtual void s_1d8();
    virtual void s_1d9();
    virtual void s_1da();
    virtual void s_1db();
    virtual void s_1dc();
    virtual void s_1dd();
    virtual void s_1de();
    virtual void s_1df();
    virtual void s_1e0();
    virtual void s_1e1();
    virtual void s_1e2();
    virtual void s_1e3();
    virtual void s_1e4();
    virtual void s_1e5();
    virtual void s_1e6();
    virtual void s_1e7();
    virtual void s_1e8();
    virtual void s_1e9();
    virtual void s_1ea();
    virtual void s_1eb();
    virtual void s_1ec();
    virtual void s_1ed();
    virtual void s_1ee();
    virtual void s_1ef();
    virtual void s_1f0();
    virtual void s_1f1();
    virtual void s_1f2();
    virtual void s_1f3();
    virtual void s_1f4();
    virtual void s_1f5();
    virtual void s_1f6();
    virtual void s_1f7();
    virtual void s_1f8();
    virtual void s_1f9();
    virtual void s_1fa();
    virtual void s_1fb();
    virtual void s_1fc();
    virtual void s_1fd();
    virtual void s_1fe();
    virtual void s_1ff();
    virtual void s_200();
    virtual void s_201();
    virtual void s_202();
    virtual void s_203();
    virtual void s_204();
    virtual void s_205();
    virtual void s_206();
    virtual void s_207();
    virtual void s_208();
    virtual bool Move824(Actor* actor, FleeVec3 pos, void* cell, void* b);
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
    TESObjectREFR* pTarget;
    void FUN_00918600(Actor* actor);
};

// @fnv 0x00918600
void FleeProcedure::FUN_00918600(Actor* actor)
{
    float fRadius;
    TESPackage* pPackage2;
    FleePackage* pFlee2;
    {
        Actor* pTargetActor;
        void* pCell4;
        FleeVec3 kPos;

        pPackage2 = GetAssignedPackage();
        if (!pTarget)
        {
            Begin8c(actor);
        }
        Begin90(actor, 0);
        fRadius = 0.0f;
        if (((FleePackageAccess*)pPackage2)->FUN_00671d10())
        {
            fRadius = (float)((FleePackageAccess*)pPackage2)->FUN_00671d10()->FUN_0044ddc0();
        }
        else
        {
            fRadius = (float)((FleePackageAccess*)pPackage2)->FUN_00676280(actor);
        }
        if (pTarget && ((FleeActorView*)actor)->FUN_005723b0(pTarget, 0, 0) > fRadius)
        {
            ((FleeActorView*)actor)->Set410(actor, 1, 1, 1, 0, 0, -1.0f, -1.0f);
            pFlee2 = 0;
            pFlee2 = dynamic_cast<FleePackage*>(GetAssignedPackage());
            pTargetActor = dynamic_cast<Actor*>(pTarget);
            if (pFlee2 && pTargetActor)
            {
                pFlee2->FUN_009f1310(pTargetActor);
            }
            return;
        }
        else if (!pTarget && !((FleePackageAccess*)pPackage2)->Check13c(actor, 0, -1.0f, 0))
        {
            pCell4 = ((FleePackageAccess*)pPackage2)->FUN_00675c20(actor);
            ((FleePackageAccess*)pPackage2)->FUN_00675de0(&kPos, actor);
            if (((FleeActorView*)actor)->FUN_008b3bb0())
            {
                if (!Move824(actor, kPos, pCell4, ((FleeActorView*)actor)->FUN_00575d70()))
                {
                    return;
                }
            }
            else
            {
                Run350(actor, 0x201, 1);
            }
            return;
        }
        else
        {
            if (!((FleeActorView*)actor)->FUN_008b3bb0())
            {
                Fail294(actor);
            }
        }
    }
}

__if_not_exists(TESPackage::TESPackage)
{
    class TESPackage
    {
      public:
        virtual void packageVirtual();
    };
}

namespace FleeUpdate {
struct Actor;
struct Process;
struct Package;
struct Target;
struct Weapon;
struct Request;
struct Point
{
    float x, y, z;
};
struct Timer
{
    float FUN_0084d030();
    float FUN_00867da0();
};
struct Setting
{
    float* FUN_00403e20();
};
extern Timer DAT_011f6394, DAT_011de7b8;
extern Setting DAT_011cd348, DAT_011ce570, DAT_011cf998;
extern char DAT_011846a0, DAT_0118c6f4;
extern double DAT_0101a6b0, DAT_01012060, DAT_010356d8, DAT_01012640;
extern float DAT_01013974;
struct NamedType
{
    float FUN_00526ac0();
};
NamedType* __cdecl LookupFormByID(int);
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct Animation
{
    bool FUN_0040b470();
    bool FUN_0040b6b0();
    void FUN_0040b800(int);
    void FUN_0040a420(int);
};
struct AnimationOwner
{
    void FUN_00815480(Animation*, void*, int);
    int unk00;
    int unk04;
    int unk08;
};
struct Weapon
{
    bool FUN_00425fd0();
};
struct Target
{
    Weapon* FUN_00680020();
};
struct ActorData;
struct Package
{
    void RemoveInvalidAvoidedReferences(Process*);
    Target* FUN_00671d10();
    float GetField90Float();
    Actor* FindNearestRef(Actor*);
    void FUN_00810530(int);
    void FUN_00898250(float);
    Actor* FUN_005e3fc0();
    void FUN_009f1140(Actor*, Actor*);
    unsigned int FUN_00676280(Actor*);
    void* BuildAvoidNodeArray();
};
struct RaceData
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
    virtual bool v028();
};
struct ActorData
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
    RaceData race;
};
struct Actor
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
    virtual Point* v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual int v214();
    virtual void v218();
    virtual bool v21c();
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
    virtual float v2bc(int);
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
    AnimationOwner animations;
    int unk94;
    Weapon* FUN_008d6f30();
    float FUN_005723b0(Actor*, int, int);
    bool FUN_008b3bb0();
    ActorData* FUN_004181e0();
    void FUN_008bb630(Request*);
    int FUN_00575d70();
};
struct Process
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
    virtual Animation* v04c();
    virtual void v050(int);
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
    virtual TESPackage* v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288(Actor*, int);
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
    virtual void v734();
    virtual void v738();
    virtual void v73c();
    virtual void v740();
    virtual void v744();
    virtual void v748();
    virtual void v74c();
    virtual void v750();
    virtual void v754();
    virtual void v758();
    virtual void v75c();
    virtual void v760();
    virtual void v764();
    virtual void v768();
    virtual void v76c();
    virtual void v770();
    virtual void v774();
    virtual void v778();
    virtual void v77c();
    virtual void v780();
    virtual void v784();
    virtual void v788();
    virtual void v78c();
    virtual void v790();
    virtual void v794();
    virtual void v798();
    virtual void v79c();
    virtual void v7a0();
    virtual void v7a4();
    virtual void v7a8();
    virtual void v7ac();
    virtual void v7b0();
    virtual void v7b4();
    virtual void v7b8();
    virtual void v7bc();
    virtual void v7c0();
    virtual void v7c4();
    virtual void v7c8();
    virtual void v7cc();
    virtual void v7d0();
    virtual void v7d4();
    virtual void v7d8();
    virtual void v7dc();
    virtual void v7e0();
    virtual void v7e4();
    virtual void v7e8();
    virtual void v7ec();
    virtual void v7f0();
    virtual void v7f4();
    virtual void v7f8();
    virtual void v7fc();
    virtual void v800();
    virtual void v804();
    virtual void v808();
    virtual void v80c();
    virtual void v810();
    virtual void v814();
    virtual void v818();
    virtual void v81c();
    virtual void v820();
    virtual bool v824(Actor*, Point, Weapon*, int);
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
    float countdown;
    float FUN_007df1f0();
    void FUN_00918860(Actor* actor);
};
}
class PathingLocation
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
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
};
class PathingRequest
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
    ~PathingRequest();
};
class PathingRequestFlee : public PathingRequest
{
  public:
    PathingRequestFlee();
    void InitFromActor(FleeUpdate::Actor*);
    void SetInitialPathHeading(float);
    void SetCantOpenDoors(bool);
    void FUN_006d3b00(float);
    void FUN_006d61e0(void*);
    void FUN_00507610(float);
    void FUN_006d1bc0(const PathingLocation&);
    void FUN_008df000();
};
// @fnv 0x00918860
void FleeUpdate::Process::FUN_00918860(Actor* actor)
{
    Package* packageTmp = 0;
    packageTmp = (Package*)dynamic_cast<FleePackage*>(v27c());
    Weapon* targetTmp = 0;
    bool aArmed = false;
    if (v04c())
    {
        if (v04c()->FUN_0040b470())
        {
            actor->animations.FUN_00815480(v04c(), actor ? &actor->unk94 : 0, 0);
            v04c()->FUN_0040b800(0);
            v050(0);
        }
        else
        {
            if (!v04c()->FUN_0040b6b0())
                v04c()->FUN_0040a420(0);
            return;
        }
    }
    if (!packageTmp)
        return;
    packageTmp->RemoveInvalidAvoidedReferences(this);
    if (packageTmp->FUN_00671d10() && packageTmp->FUN_00671d10()->FUN_00680020())
        targetTmp = packageTmp->FUN_00671d10()->FUN_00680020();
    if (targetTmp)
    {
        float elapsed4 = packageTmp->GetField90Float();
        Actor* destinationTmp = packageTmp->FindNearestRef(actor);
        if (!destinationTmp)
        {
            packageTmp->FUN_00810530(1);
            packageTmp->FUN_00898250(DAT_011f6394.FUN_0084d030());
            if (elapsed4 >= *DAT_011cd348.FUN_00403e20())
                v288(actor, 1);
            return;
        }
        if (actor->v214() == 4 || actor->v214() == 9)
        {
            actor->v418();
            return;
        }
        Weapon* weapon6 = actor->FUN_008d6f30();
        if (weapon6)
        {
            packageTmp->FUN_00898250((float)(DAT_011f6394.FUN_0084d030() * -1.0));
            float distance = actor->FUN_005723b0(destinationTmp, 0, 0);
            float threshold = 0;
            if (weapon6->FUN_00425fd0())
            {
                threshold = *DAT_011ce570.FUN_00403e20();
                aArmed = true;
            }
            else
                threshold = *DAT_011cf998.FUN_00403e20();
            if (distance < threshold && actor->FUN_008b3bb0())
            {
                Actor* reference = packageTmp->FUN_005e3fc0();
                bool expired = false;
                if (countdown <= 0.0)
                    expired = true;
                else
                    countdown -= DAT_011f6394.FUN_0084d030();
                if (!reference)
                {
                    packageTmp->FUN_009f1140(actor, destinationTmp);
                    PathingRequestFlee request;
                    request.InitFromActor(actor);
                    request.SetInitialPathHeading(actor->v2bc(0));
                    if (actor->v21c())
                        request.SetCantOpenDoors(actor->FUN_004181e0()->race.v028());
                    request.FUN_006d3b00((float)packageTmp->FUN_00676280(actor));
                    request.FUN_006d61e0(packageTmp->BuildAvoidNodeArray());
                    request.FUN_00507610(1000.0f);
                    if (reference)
                        request.FUN_006d1bc0(PathingLocation((TESObjectREFR*)reference));
                    else
                        request.FUN_008df000();
                    actor->FUN_008bb630((Request*)&request);
                }
                else
                {
                    if (!v824(actor, *reference->v1f4(), reference->FUN_008d6f30(), reference->FUN_00575d70()))
                        return;
                }
                packageTmp->FUN_00810530(0);
                packageTmp->FUN_00898250((float)(packageTmp->GetField90Float() * -1.0));
            }
            if (!actor->FUN_008b3bb0())
            {
                NamedType* type = LookupFormByID(0x3a);
                float hour = DAT_011de7b8.FUN_00867da0();
                if (hour < FUN_007df1f0())
                    hour += 24.0;
                float duration = hour - FUN_007df1f0();
                duration *= 3600.0 / type->FUN_00526ac0();
            }
            else
            {
                packageTmp->FUN_00810530(1);
                packageTmp->FUN_00898250(DAT_011f6394.FUN_0084d030());
                if (elapsed4 >= *DAT_011cd348.FUN_00403e20())
                    v288(actor, 1);
            }
        }
    }
}
