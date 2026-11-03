
// tesscriptfunctions_ctx_variant.cpp: context variant of src/fallout_shared/tesscriptfunctions.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesscriptfunctions_layout_support.h"
class ScriptParameter;
class ScriptHeaderData;
class TESForm
{
  public:
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
    virtual void SetAltered(bool);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    ENUM_FORM_ID GetFormType() const;
    void SetDestroyed(bool);
};
enum OBJECT_ACTION
{
    OBJECT_ACTION_ONE = 1,
    OBJECT_ACTION_TWO = 2
};
class TESObjectREFR : public TESForm
{
  public:
    void SetScale(float);
    bool GetAction(OBJECT_ACTION);
    void CloseReference(OBJECT_ACTION);
};
class BGSMusicType;
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
    static void Update();
};
class ScriptLocals;
class TESQuest
{
  public:
    bool IsStageComplete(unsigned char);
    void SetEnabled(bool);
};
class Script;
class Script
{
  public:
    static bool OnHitWithFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    ScriptHeaderData* GetHeader();
    static bool StopQuestFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool ScriptEffectUpdateFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                           Script*, ScriptLocals*, double&, unsigned int&);
    static bool SetAllyFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool SetDestroyedFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetCurrentTimeFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool SetScriptCondition(TESObjectREFR*, void*, void*, double&);
    static bool GetSecondsPassedFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                         ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptResult(TESObjectREFR*, void*, void*, double&);
    static bool GetDead(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                        double&, unsigned int&);
    static bool ResetScript(TESObjectREFR*, void*, void*, double&);
    static bool GetItemCount(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool HandleScriptLocals(TESObjectREFR*, void*, void*, double&);
    static bool GetSitting(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                           double&, unsigned int&);
    static bool ReadScriptArguments(TESObjectREFR*, void*, void*, double&);
    static bool GetTalkedToPC(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool FindScriptVariable(TESObjectREFR*, void*, void*, double&);
    static bool GetIsRaining(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool EvaluateWeatherCondition(TESObjectREFR*, void*, void*, double&);
    static bool GetInCell(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                          double&, unsigned int&);
    static bool EvaluateCellMembership(TESObjectREFR*, void*, void*, double&);
    static bool GetInFaction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool GetScriptOperand(TESObjectREFR*, void*, void*, double&);
    static bool GetRandomPercent(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                 ScriptLocals*, double&, unsigned int&);
    static bool EvaluateRandomPercentage(TESObjectREFR*, void*, void*, double&);
    static bool GetLevel(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                         double&, unsigned int&);
    static bool EvaluateReferenceLevel(TESObjectREFR*, void*, void*, double&);
    static void CheckFlagFunction(unsigned int, TESObjectREFR*, TESForm*, ScriptLocals*, double&);
    static bool OnAddFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool OnSellFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnEquipFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnUnequipFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool OnFireFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnOpenFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnCloseFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnGrabFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnReleaseFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool OnDestructionStageChangeFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                                 Script*, ScriptLocals*, double&, unsigned int&);
    static bool OnHitFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool OnDeathFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnStartCombatFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                      ScriptLocals*, double&, unsigned int&);
    static bool OnCombatEndFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                    ScriptLocals*, double&, unsigned int&);
    static bool OnSayToDoneFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                    ScriptLocals*, double&, unsigned int&);
    static bool OnPackageStartFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool OnPackageEndFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool OnPackageChangeFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                        ScriptLocals*, double&, unsigned int&);
    static bool OnLoadFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnResetFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnMagicEffectHitFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                         ScriptLocals*, double&, unsigned int&);
    static bool OnTriggerFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool OnTriggerEnterFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool OnTriggerLeaveFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);

    // Insert these declaration-only additions in the existing Script public section.
    static bool IsIdlePlayingFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                      ScriptLocals*, double&, unsigned int&);
    static bool CheckIdlePlaying(TESObjectREFR*, void*, void*, double&);
    static bool IsTalkingFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool CheckTalkingState(TESObjectREFR*, void*, void*, double&);
    static bool GetDayOfWeekFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool ParseScript(TESObjectREFR*, void*, void*, double&);
    static bool IsPCSleepingFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool IsPlayerAsleep(TESObjectREFR*, void*, void*, double&);
    static bool GetDestroyedFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool HandleScriptOperation(TESObjectREFR*, void*, void*, double&);
    static bool HasBeenEatenFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetScriptObject(TESObjectREFR*, void*, void*, double&);
    static bool GetUnconsciousFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool ResolveScriptValue(TESObjectREFR*, void*, void*, double&);
    static bool IsInCombatFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                   ScriptLocals*, double&, unsigned int&);
    static bool GetScriptFunctionValue(TESObjectREFR*, void*, void*, double&);
    static bool IsInInteriorFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool EvaluateReferenceQuery(TESObjectREFR*, void*, void*, double&);

    static bool EvaluateReferenceCondition(TESObjectREFR*, void*, void*, double&);
    static bool CheckActorCondition(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateReferenceFlag(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateFirstReferenceOperand(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateSecondReferenceOperand(TESObjectREFR*, void*, void*, double&);
    static bool ReadScriptOperand(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateReferenceScriptValue(TESObjectREFR*, void*, void*, double&);
    static bool ResolveScriptReference(TESObjectREFR*, void*, void*, double&);
    static bool CheckScriptCondition(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateSeventhReferenceOperand(TESObjectREFR*, void*, void*, double&);
    static bool GetScriptParameter(TESObjectREFR*, void*, void*, double&);
    static bool HandleScriptExpression(TESObjectREFR*, void*, void*, double&);
    static bool GetScriptResult(TESObjectREFR*, void*, void*, double&);
    static bool AdvanceScriptInstruction(TESObjectREFR*, void*, void*, double&);
    static bool HandleScriptReference(TESObjectREFR*, void*, void*, double&);
    static bool ExecuteScriptCommand(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateReferencePredicate(TESObjectREFR*, void*, void*, double&);
    static bool HandleScriptEvent(TESObjectREFR*, void*, void*, double&);
    static bool WriteScriptValue(TESObjectREFR*, void*, void*, double&);
    static bool EvaluateReferenceProperty(TESObjectREFR*, void*, void*, double&);
    static void SetReferenceScale(TESObjectREFR*, float);

    static bool GetQuestCompleted(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool GetQuestRunning(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool GetStage(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                         double&, unsigned int&);
    static bool GetDeadCount(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool GetQuestCompletedStatus(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                        ScriptLocals*, double&, unsigned int&);
    static bool InvokeScriptFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetQuestCompletionState(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                        ScriptLocals*, double&, unsigned int&);
    static bool GetStageDone(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool ConvertScriptValue(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                   ScriptLocals*, double&, unsigned int&);
    static bool GetInWorldspace(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool GetInSameCell(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool GetDetected(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                            ScriptLocals*, double&, unsigned int&);
    static bool GetGlobalValue(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool IsCurrentFurnitureRef(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                      ScriptLocals*, double&, unsigned int&);
    static bool GetIsID(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                        double&, unsigned int&);
    static bool EvaluateScriptExpression(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                         ScriptLocals*, double&, unsigned int&);
    static bool GetPCMiscStat(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool HandleScriptVariable(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool ReadScriptReference(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                    ScriptLocals*, double&, unsigned int&);
    static bool EvaluateParsedScriptFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                             Script*, ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptFunctionCall(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                           Script*, ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptCall(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                   ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptCallback(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
};
extern bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                        ScriptLocals*, ...);
#include "tesscriptfunctions_TESActorBaseData.h"
#include "tesscriptfunctions_SCRIPT_HEADER.h"
struct _FightReaction
{
    enum Type
    {
        NEUTRAL = 0,
        ENEMY = 1,
        ALLY = 2,
        FRIEND = 3,
        COUNT
    };
};
typedef _FightReaction::Type FIGHT_REACTION;
class TESFaction
{
  public:
    void SetFactionFightReaction(TESFaction*, FIGHT_REACTION);
};
class BGSListForm : public TESForm
{
  public:
    BSSimpleList<TESForm*>* GetList();
};

class TESForm;
class TESObjectREFR;
class Actor;
class BaseProcess;
class InventoryChanges;
class ExtraDataList;
class Script;
class ScriptLocals;
class ScriptParameter;
class StrListT;
class YHolder;

struct BaseProcess
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
    virtual void v352(int, int, int);
};

class Actor : public TESObjectREFR
{
  public:
    void FUN_00950030();
    BaseProcess* GetProcess();
    void UnequipItem(TESForm*, int, int, int, bool, int);
};

class ExtraDataList
{
  public:
    ExtraDataList();
    ~ExtraDataList();
    void FUN_0041ab70(bool);
    int m_auiShapeKeys[8];
};

class YHolder
{
  public:
    BSSimpleList<const char*>* m_pEntries;
    BSSimpleList<ExtraDataList*>* FUN_00559450();
    ~YHolder();
};

class InventoryChanges
{
  public:
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
    ExtraDataList* FUN_004bfda0(TESForm*, int);
    YHolder* FUN_004d0650(TESForm*, int);
};

class TESFullName
{
  public:
    static const char* GetFullName(TESForm*);
};

struct SettingObj
{
    const char* String();
};

struct Interface
{
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};

extern char DAT_011d424c;
extern Actor* g_thePlayer;

int FUN_00406f60(BSStringT<char>* str, const char* fmt, ...);
void FUN_00704af0();

// @fnv 0x005d0300
bool Cmd_UnequipItem_Execute(const ScriptParameter* param, const char* desc, TESObjectREFR* obj, TESObjectREFR* obj2,
                  Script* script, ScriptLocals* locals, double& result, unsigned int& opcode)
{
    TESForm* pForm = 0;
    int iCount = 0;
    int iFlag = 0;

    if (!ExtractArgs(param, desc, &opcode, obj, obj2, script, locals, &pForm, &iCount, &iFlag))
        return false;

    if (obj)
    {
        Actor* pActor = dynamic_cast<Actor*>(obj);
        bool bSet = false;
        if (iCount > 0)
            bSet = true;

        if (pForm)
        {
            if (pActor)
            {
                InventoryChanges* pChanges = InventoryChanges::GetOrAddInventoryChanges(obj);
                if (pChanges)
                {
                    ExtraDataList* pExtra = 0;
                    pExtra = pChanges->FUN_004bfda0(pForm, 0);
                    if (pExtra)
                    {
                        pExtra->FUN_0041ab70(false);
                        pActor->UnequipItem(pForm, 1, 0, 1, bSet, 1);
                        if (pActor == g_thePlayer && iFlag == 0)
                        {
                            BSStringT<char> str;
                            FUN_00406f60(&str, "%s %s.", TESFullName::GetFullName(pForm),
                                         ((SettingObj*)&DAT_011d424c)->String());
                            Interface::ShowMessage(str.String(), 0,
                                                   "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                                   0, 2.0f, false);
                            g_thePlayer->FUN_00950030();
                            g_thePlayer->GetProcess()->v352(1, 0, 0);
                            FUN_00704af0();
                        }
                    }
                }
            }
        }
        else
        {
            InventoryChanges* pChanges2 = InventoryChanges::GetOrAddInventoryChanges(obj);
            if (pChanges2)
            {
                YHolder* pHolder = pChanges2->FUN_004d0650(pForm, 0);
                if (pHolder)
                {
                    if (pHolder->FUN_00559450())
                    {
                        if (pHolder->FUN_00559450()->GetItem())
                        {
                            pHolder->FUN_00559450()->GetItem()->FUN_0041ab70(bSet);
                        }
                        else
                        {
                            ExtraDataList* pNew = new ExtraDataList();
                            pNew->FUN_0041ab70(bSet);
                            pHolder->FUN_00559450()->AddHead(pNew);
                        }
                    }
                    else
                    {
                        pHolder->m_pEntries = new BSSimpleList<const char*>();
                        ExtraDataList* pNew2 = new ExtraDataList();
                        pNew2->FUN_0041ab70(bSet);
                        pHolder->FUN_00559450()->AddHead(pNew2);
                    }
                    delete pHolder;
                }
            }
        }
    }

    return true;
}
