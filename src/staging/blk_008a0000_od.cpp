
// src/staging/blk_008a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_008a0250_class
{
    void FUN_008a0250();
};

// @fnv 0x008a0250
void FUN_008a0250_class::FUN_008a0250()
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0xc4) = true;
}

struct FUN_008a08c0_Class
{
    char GetByteAt7C4();
};

// @fnv 0x008a08c0
char FUN_008a08c0_Class::GetByteAt7C4()
{
    return ((char*)this)[0x7c4];
}

struct Actor
{
    void ProcessQueuedActorUpdate();
};
struct FUN_008a1a40_shell : Actor
{
    void FUN_008a1a40(Actor* p);
};
// @fnv 0x008a1a40
void FUN_008a1a40_shell::FUN_008a1a40(Actor* apActor)
{
    ((int*)this)[0x10c / 4] = (int)apActor;
    ProcessQueuedActorUpdate();
}

struct FUN_008ae480_Class
{
    float GetField1A8();
};

// @fnv 0x008ae480
float FUN_008ae480_Class::GetField1A8()
{
    return *(float*)((char*)this + 0x1a8);
}

struct FUN_008ae4a0_Class
{
    float __thiscall GetField1B8();
};

// @fnv 0x008ae4a0
float __thiscall FUN_008ae4a0_Class::GetField1B8()
{
    return *(float*)((char*)this + 0x1b8);
}

struct FUN_008b3b10_Class
{
    void FUN_008b3b10();
};

struct FUN_008b3af0_Class
{
    void* m_000;
    void* m_004;
    void* m_008;
    void* m_00c;
    void* m_010;
    void* m_014;
    void* m_018;
    void* m_01c;
    void* m_020;
    void* m_024;
    void* m_028;
    void* m_02c;
    void* m_030;
    void* m_034;
    void* m_038;
    void* m_03c;
    void* m_040;
    void* m_044;
    void* m_048;
    void* m_04c;
    void* m_050;
    void* m_054;
    void* m_058;
    void* m_05c;
    void* m_060;
    void* m_064;
    void* m_068;
    void* m_06c;
    void* m_070;
    void* m_074;
    void* m_078;
    void* m_07c;
    void* m_080;
    void* m_084;
    void* m_088;
    void* m_08c;
    void* m_090;
    void* m_094;
    void* m_098;
    void* m_09c;
    void* m_0a0;
    void* m_0a4;
    void* m_0a8;
    void* m_0ac;
    void* m_0b0;
    void* m_0b4;
    void* m_0b8;
    void* m_0bc;
    void* m_0c0;
    void* m_0c4;
    void* m_0c8;
    void* m_0cc;
    void* m_0d0;
    void* m_0d4;
    void* m_0d8;
    void* m_0dc;
    void* m_0e0;
    void* m_0e4;
    void* m_0e8;
    void* m_0ec;
    void* m_0f0;
    void* m_0f4;
    void* m_0f8;
    void* m_0fc;
    void* m_100;
    void* m_104;
    void* m_108;
    void* m_10c;
    void* m_110;
    void* m_114;
    void* m_118;
    void* m_11c;
    void* m_120;
    void* m_124;
    void* m_128;
    void* m_12c;
    void* m_130;
    void* m_134;
    void* m_138;
    void* m_13c;
    void* m_140;
    void* m_144;
    void* m_148;
    void* m_14c;
    void* m_150;
    void* m_154;
    void* m_158;
    void* m_15c;
    void* m_160;
    void* m_164;
    void* m_168;
    void* m_16c;
    void* m_170;
    void* m_174;
    void* m_178;
    void* m_17c;
    void* m_180;
    void* m_184;
    void* m_188;
    void* m_18c;
    void* m_190;

    void FUN_008b3af0();
};

// @fnv 0x008b3af0
void FUN_008b3af0_Class::FUN_008b3af0()
{
    ((FUN_008b3b10_Class*)m_190)->FUN_008b3b10();
}

struct FUN_008b3b10_class
{
    void FUN_008b3b10();
};

// @fnv 0x008b3b10
void FUN_008b3b10_class::FUN_008b3b10()
{
    *(char*)((char*)this + 0x72) = 0;
}

struct FUN_008b4cd0_class
{
    bool IsFlag40Set();
};

// @fnv 0x008b4cd0
bool FUN_008b4cd0_class::IsFlag40Set()
{
    return ((unsigned char*)this)[0x60] & 0x40;
}

struct FUN_008b4cf0_class
{
    unsigned char GetByte65();
};

// @fnv 0x008b4cf0
unsigned char FUN_008b4cf0_class::GetByte65()
{
    return ((const unsigned char*)this)[0x65];
}

struct FUN_00884920_holder
{
    bool FUN_00884920();
    void FUN_008beb50(void*);
};
struct FUN_008beae0_vt
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
};
struct FUN_008beae0 : FUN_008beae0_vt
{
    void ProcessCoverLOSResult();
};
// @fnv 0x008beae0
void FUN_008beae0::ProcessCoverLOSResult()
{
    if (*(FUN_00884920_holder**)((char*)this + 0x68) && (*(FUN_00884920_holder**)((char*)this + 0x68))->FUN_00884920())
        (*(FUN_00884920_holder**)((char*)this + 0x68))->FUN_008beb50(this ? (char*)this + 0xa8 : 0);
    else
        ((FUN_008beae0_vt*)((char*)this + 0xa8))->v13();
}

struct FUN_008a88b0_ListBase
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

    virtual BSSimpleList<int>* GetNextListItem();
};

struct FUN_008a88b0_class
{
    unsigned char m_000[0x68];
    FUN_008a88b0_ListBase* m_068;

    BSSimpleList<int>* GetNextListItem();
};

// Returns the next node of the list obtained from m_068, or -1 if that list is null.
// @fnv 0x008a88b0
BSSimpleList<int>* FUN_008a88b0_class::GetNextListItem()
{
    BSSimpleList<int>* result = m_068->GetNextListItem();
    if (result)
        return result->GetNext();
    return reinterpret_cast<BSSimpleList<int>*>(-1);
}

struct FUN_008b3a80_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void*);
};
struct FUN_008b3a80_Class
{
    void ForwardToVtSlot(void* arg);
};
// Calls virtual method v2 on the object stored at this+0x190, passing arg through.
// @fnv 0x008b3a80
void FUN_008b3a80_Class::ForwardToVtSlot(void* arg)
{
    ((FUN_008b3a80_vt*)*(void**)((char*)this + 0x190))->v2(arg);
}

struct FUN_008b5190_Class
{
    bool FUN_008b5190();
};

// @fnv 0x008b5190
bool FUN_008b5190_Class::FUN_008b5190()
{
    return ((unsigned char*)((char*)this + 0x60))[0] & 1 ? true : false;
}

struct FUN_008a81e0_Result
{
    int unk00;
    int unk04;
};

struct FUN_008a81e0_FieldBase
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

    virtual FUN_008a81e0_Result* FUN_008a81e0_FieldCall(int, int);
};

struct FUN_008a81e0_Class
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    FUN_008a81e0_FieldBase* unk068;

    int FUN_008a81e0(int);
};

// If unk068 is set, calls its FUN_008a81e0_FieldCall with param and 0 and returns unk04 of the result, otherwise returns 0.
// @fnv 0x008a81e0
int FUN_008a81e0_Class::FUN_008a81e0(int param)
{
    int result = 0;

    if (unk068 != 0)
    {
        FUN_008a81e0_Result* value = unk068->FUN_008a81e0_FieldCall(param, 0);
        if (value != 0)
        {
            result = value->unk04;
        }
    }

    return result;
}

class B9565Sub
{
  public:
    void Call0(void* p, int v);
    void Call1(void* p, int v);
    void Call2(void* p, float f);
};
class B9565Obj
{
  public:
    void* Get0();
    int Get1();
    float Get2();
};
class B9565Outer
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
    B9565Sub* m_ac;
};

// @fnv 0x008bc270
void FUN_008bc270(B9565Outer* pOuter, B9565Obj* pObj)
{
    B9565Outer* a = pOuter;
    B9565Obj* b5 = pObj;
    void* p2;
    if (a->m_ac != 0)
    {
        p2 = b5->Get0();
        if (b5->Get1() == 1)
        {
            a->m_ac->Call0(p2, 1);
        }
        if (b5->Get1() == 2)
        {
            a->m_ac->Call1(p2, 1);
        }
        a->m_ac->Call2(p2, b5->Get2());
    }
}

struct FUN_008be220_vt
{
    virtual float v0();
};

struct FUN_008be220_obj
{
    float m_uiFilterValue;
    bool FUN_00884e90(int flag);
};

struct FUN_008be220_cls
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
    FUN_008be220_obj* m_2c;
    float FUN_008be220(FUN_008be220_vt* a1);
};

// @fnv 0x008be220
float FUN_008be220_cls::FUN_008be220(FUN_008be220_vt* apVt)
{
    return m_2c == 0 ? 0.0f : (!m_2c->FUN_00884e90(1) ? m_2c->m_uiFilterValue : apVt->v0());
}

class Fun008be490Inner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    float m_f0c;
    bool Check(int flags);
};

class Fun008be490Arg
{
  public:
    virtual void unkV00();
    virtual void unkV04();
    virtual void unkV08();
    virtual float GetValue();
};

class FUN_008be490_cls
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
    Fun008be490Inner* m_pInner;
    float FUN_008be490(Fun008be490Arg* arg);
};

// Returns 0 if m_pInner is null, m_pInner->m_f0c if its Check(0x8000) fails, otherwise arg->GetValue().
// @fnv 0x008be490
float FUN_008be490_cls::FUN_008be490(Fun008be490Arg* arg)
{
    return m_pInner == 0 ? 0.0f : (!m_pInner->Check(0x8000) ? m_pInner->m_f0c : arg->GetValue());
}

class C8BEB50Source
{
  public:
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
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual int GetValue();
};

class C8BEB50Data
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
    int m_iValue;

    bool IsFlagSet(int iFlag);
};

class C8BEB50Holder
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
    C8BEB50Data* m_pUserData;

    int FUN_008beb50(C8BEB50Source* pkSource);
};

// Returns 0 if the data pointer is null, the data's m_iValue if flag 0x800 is clear, otherwise the source's GetValue().
// @fnv 0x008beb50
int C8BEB50Holder::FUN_008beb50(C8BEB50Source* pkSource)
{
    return !m_pUserData ? 0 : (!m_pUserData->IsFlagSet(0x800) ? m_pUserData->m_iValue : pkSource->GetValue());
}

struct ActorSubObject_bebb0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct HolderBebb0
{
    bool Probe();
    void Attach(void* p);
};

struct FUN_008bebb0_cls
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
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    HolderBebb0* m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    ActorSubObject_bebb0 m_a8;
    void AttachSubObject();
};

// If m_68 exists and Probe succeeds, attaches &m_a8 to it; otherwise calls m_a8.v5().
// @fnv 0x008bebb0
void FUN_008bebb0_cls::AttachSubObject()
{
    if (m_68 != 0 && m_68->Probe())
    {
        m_68->Attach(this != 0 ? &m_a8 : 0);
    }
    else
    {
        m_a8.v5();
    }
}

class Fun008bec20Inner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float m_f14;
    bool IsSomething(int flag);
};

class Fun008bec20Arg
{
  public:
    virtual void unkV00();
    virtual void unkV04();
    virtual void unkV08();
    virtual void unkV0C();
    virtual void unkV10();
    virtual float GetValue();
};

class FUN_008bec20_cls
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
    Fun008bec20Inner* m_pInner;
    float FUN_008bec20(Fun008bec20Arg* arg);
};

// Returns 0.0f if m_pInner is null, otherwise m_pInner->m_f14 unless IsSomething(16) is set, in which case it returns arg->GetValue().
// @fnv 0x008bec20
float FUN_008bec20_cls::FUN_008bec20(Fun008bec20Arg* arg)
{
    return m_pInner == 0 ? 0.0f : (!m_pInner->IsSomething(16) ? m_pInner->m_f14 : arg->GetValue());
}

struct S_008bec80_Base;
struct S_008bec80_Tgt
{
    bool FUN_00884920();
    void FUN_008becf0(S_008bec80_Base* p);
};
struct S_008bec80_Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
struct S_008bec80_Head
{
    virtual void h0();
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
    S_008bec80_Tgt* unk68;
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
};
struct S_008bec80 : S_008bec80_Head, S_008bec80_Base
{
    void FUN_008bec80();
};
// If unk68 exists and its FUN_00884920 returns true, calls unk68->FUN_008becf0(this); otherwise calls v6().
// @fnv 0x008bec80
void S_008bec80::FUN_008bec80()
{
    if (unk68 && unk68->FUN_00884920())
    {
        unk68->FUN_008becf0(this);
    }
    else
    {
        v6();
    }
}

struct FUN_008becf0_ParamObj_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
};

struct FUN_008becf0_ParamObj : FUN_008becf0_ParamObj_vt
{
    unsigned int unk04;
};

struct FUN_008becf0_Shape
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    float m_18;
    unsigned int unk1C;
    bool FUN_00884e90(unsigned int flags);
};

struct FUN_008becf0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_008becf0_Shape* m_2c;

    float FUN_008becf0(FUN_008becf0_ParamObj* param);
};

// @fnv 0x008becf0
float FUN_008becf0_cls::FUN_008becf0(FUN_008becf0_ParamObj* param)
{
    return (m_2c == 0) ? 0.0f : ((!m_2c->FUN_00884e90(0x80000000)) ? m_2c->m_18 : param->v6());
}

struct PkgData
{
    void FUN_006800b0(int);
    void FUN_00680110(void*);
    void FUN_00403550(unsigned int);
};
struct CurPkg
{
    bool FUN_00441b00();
    bool FUN_00678610();
};
struct PkgLoc
{
    PkgLoc();
    ~PkgLoc();
    void FUN_0067f3c0(void*);
    int unk00;
    int unk04;
    int unk08;
};
struct PkgTarget
{
    PkgTarget();
    ~PkgTarget();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct Pkg
{
    void SetPackageType(int);
    void SetMustReachLocation(bool);
    void SetMustComplete(bool);
    void FUN_00671d30(PkgLoc*);
    void FUN_00672fc0(PkgTarget*);
    void FUN_00984f60(unsigned int);
    PkgData* GetData();
    void SetFlag200000(bool);
};
Pkg* CreatePackageStandIn(int);
struct Me;
struct Proc
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
    virtual CurPkg* v139();
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
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401(int);
    virtual void v402();
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
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void v437();
    virtual void v438();
    virtual void v439();
    virtual void v440();
    virtual void v441();
    virtual void v442();
    virtual void v443();
    virtual void v444();
    virtual void v445();
    virtual void v446();
    virtual void v447();
    virtual void v448();
    virtual void v449();
    virtual void v450();
    virtual void v451();
    virtual void v452(Me*);
};
struct Sub68
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
};
struct MeBase
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
    virtual void v189(Pkg*, int, int);
};
struct Player
{
    void FUN_00966e50();
};
extern Player* g_thePlayer;
struct Me : MeBase
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
    Sub68* unk68;
    bool FUN_00493bb0();
    Proc* FUN_008d8520();
    CurPkg* GetCurrentPackage();
    void FUN_008bf500(void* arg);
};

// @fnv 0x008bf500
void Me::FUN_008bf500(void* arg)
{
    if (FUN_00493bb0())
        return;
    unk68->v133();
    FUN_008d8520()->v401(1);
    CurPkg* pCurPkg = FUN_008d8520()->v139();
    if (GetCurrentPackage() && GetCurrentPackage()->FUN_00678610())
        v162();
    Pkg* pNewPkg = CreatePackageStandIn(0x23);
    pNewPkg->SetPackageType(0x23);
    pNewPkg->SetMustReachLocation(true);
    pNewPkg->SetMustComplete(true);
    PkgLoc* pLocation = new PkgLoc;
    pLocation->FUN_0067f3c0(arg);
    pNewPkg->FUN_00671d30(pLocation);
    delete pLocation;
    PkgTarget* target = new PkgTarget;
    pNewPkg->FUN_00672fc0(target);
    delete target;
    pNewPkg->FUN_00984f60(0x2b);
    pNewPkg->GetData()->FUN_006800b0(0);
    pNewPkg->GetData()->FUN_00680110(arg);
    pNewPkg->GetData()->FUN_00403550(0);
    if (pCurPkg)
        pNewPkg->SetFlag200000(pCurPkg->FUN_00441b00());
    FUN_008d8520()->v10();
    FUN_008d8520()->v452(this);
    v189(pNewPkg, 0, 1);
    g_thePlayer->FUN_00966e50();
}

struct ThreeByThreeMatrix
{
    float m[9];
};
struct NiPoint3
{
    float x, y, z;
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    NiTransform();
    NiTransform operator*(const NiTransform& o) const;
    void InvertTransform();
};
struct X38
{
    float m_00[7];
    X38(float);
    ~X38();
};
struct A3
{
    int m_00[9];
    NiPoint3 m_24;
};
struct A2
{
    NiTransform* FUN_00461130();
};
struct RObj
{
    NiTransform* FUN_00461130();
};
struct ResObj
{
    void FUN_00440460(const NiPoint3& p);
    void FUN_0043fa80(void* p);
    void FUN_00440490(float f);
};
struct NodeObj
{
    ResObj* FUN_00a5d2c0(X38* p);
};
struct Glob
{
    NodeObj* LoadModel(const char* n, int a, bool b, bool c, bool d, bool e);
    void FUN_0045a5e0(const char* n);
};
extern Glob* DAT_011c3b3c;
struct NameObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* GetNameV5();
    unsigned int FUN_0048cee0();
};
struct MidObj
{
    void FUN_004fa6f0(int a, NiPoint3* p, unsigned char c, float f);
};
struct P2
{
    bool FUN_008b4360();
    int FUN_005e3fa0();
    MidObj* FUN_008d8520();
    unsigned char GetUnk66();
    double FUN_009b0bd0();
    NameObj* FUN_005d8a70();
    float FUN_009b88c0();
};
struct P
{
    P2* GetValueByIndex(void* a);
};
void CreateProjectileRef(int a, int b, int c, int d, NiPoint3 pt, ThreeByThreeMatrix mat);
struct BaseObj
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
    virtual P* GetP96();
};
struct ThisC
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
    virtual RObj* GetR116(NiTransform* t);
    BaseObj* FUN_004181e0();
    int FUN_008d6f30();
    double FUN_00567400();
    ResObj* CreateNodeFromTransform(void* a1, A2* a2, A3* a3, unsigned char a4);
};

// @fnv 0x008b3fe0
ResObj* ThisC::CreateNodeFromTransform(void* pLookupKey, A2* pTransformSource, A3* pPlacement,
                                       unsigned char bApplyTransform)
{
    ResObj* retValA;
    retValA = 0;
    P* p9;
    p9 = FUN_004181e0()->GetP96();
    if (p9 != 0)
    {
        if (FUN_008d6f30() != 0)
        {
            P2* p4;
            p4 = p9->GetValueByIndex(pLookupKey);
            if (p4 != 0)
            {
                if (p4->FUN_008b4360())
                {
                    if (bApplyTransform != 0)
                    {
                        if (p4->FUN_005e3fa0() != 0)
                        {
                            CreateProjectileRef(p4->FUN_005e3fa0(), 0, 0, FUN_008d6f30(), pPlacement->m_24,
                                                pTransformSource->FUN_00461130()->m_kOrientation);
                        }
                        if (p4->FUN_008d8520() != 0)
                        {
                            if (p4->GetUnk66() > 0)
                            {
                                p4->FUN_008d8520()->FUN_004fa6f0(FUN_008d6f30(), &pPlacement->m_24, p4->GetUnk66(),
                                                                 (float)(FUN_00567400() * p4->FUN_009b0bd0()));
                            }
                        }
                    }
                    if (p4->FUN_005d8a70()->FUN_0048cee0() > 0)
                    {
                        if (pTransformSource != 0)
                        {
                            NodeObj* u;
                            u = DAT_011c3b3c->LoadModel(p4->FUN_005d8a70()->GetNameV5(), 0, 1, 0, 0, 0);
                            if (u != 0)
                            {
                                X38 x_(1.0f);
                                retValA = u->FUN_00a5d2c0(&x_);
                                NiTransform t1;
                                NiTransform t2;
                                GetR116(&t1)->FUN_00461130()->InvertTransform();
                                t2 = t1 * *pTransformSource->FUN_00461130();
                                retValA->FUN_00440460(t2.m_kTranslation);
                                retValA->FUN_0043fa80(&t2);
                                retValA->FUN_00440490(p4->FUN_009b88c0());
                            }
                            DAT_011c3b3c->FUN_0045a5e0(p4->FUN_005d8a70()->GetNameV5());
                        }
                    }
                }
            }
        }
    }
    return retValA;
}

typedef unsigned int size_t_;

struct ActorX;
struct TESForm;
struct RefObj;

extern "C" ActorX* DAT_011dea3c;
extern "C" char DAT_011cd6fc;
extern "C" char DAT_011cdf84;
extern "C" char DAT_011cde20;
extern "C" char DAT_011de7b8;
extern "C" char DAT_011e0e80;
extern "C" double DAT_01012060;

struct SettingValue
{
    int i;
};
struct SettingColl
{
    SettingValue* Int();
};
struct FloatVal
{
    float f;
};
struct FloatSetting
{
    FloatVal* Float();
};
struct ProcV;
struct ExtraList
{
    void AddOrCreateExtraItem(void* p, float f);
};
struct Sub4
{
    virtual void s0();
    virtual void s1();
    virtual int s2(int);
    virtual float s3(int);
};
struct TESForm
{
    char pad[0x100];
    Sub4 m100;
};
struct Faction
{
    bool FUN_0047d7c0();
};
struct RefObj
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
    virtual bool r64();
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
    virtual bool r134();
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
    virtual bool r200();
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
    virtual void r265(void*, int, int, int, int, int, int, int);
    TESForm* GetOwner();
    ExtraList* GetExtraData();
    int FUN_008a0d10(int, ActorX*, char*, int, int, int, int);
    void FUN_008bff50();
    void FUN_008b7c00(int, int);
    void FUN_008bf7b0(ActorX*, TESForm*);
    ProcV* GetProcess();
};
struct ProcV
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
    virtual void p169(RefObj*, int, int, int, int, int);
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
    virtual void p297(float);
};
struct NewObj
{
    char pad[0x3c];
    static void* operator new(size_t_ n);
    NewObj(int, RefObj*, ActorX*, int, int, TESForm*);
    void FUN_008bff50();
    void FUN_008b7c00(int, int);
    void FUN_008bf7b0(ActorX*, TESForm*);
    int FUN_008a0d10(int, ActorX*, char*, int, int, int, int);
    void* FUN_0084e3a0();
    void AddActor(RefObj*);
};
struct G67
{
    float FUN_00867da0();
    unsigned int FUN_00867d20();
    char FUN_00867d60();
    unsigned int FUN_00867c60();
};
struct Z
{
    RefObj* FUN_00970b30(Faction*, int, int);
    RefObj* FUN_00970a20(TESForm*, int);
    void AddObjectToList(NewObj*);
};
struct ActorX
{
    char pad0[0xa4];
    Sub4 m_a4;
    char pad2[0x134 - 0xa4 - sizeof(Sub4)];
    unsigned char m134;
    int m138;
    int GetField228();
    void AddToField(int, int);
    void FUN_0094fd30(int);
    void* FUN_00964100(int);
    ProcV* GetProcess();
    void SetLight(void* p);
    void FUN_008bfa40(RefObj* pSrc, int a2, int a3, int a4, TESForm* p5);
};

int __fastcall FNV_GetFormType(TESForm* p);
float __cdecl FUN_0048ebc0(int, bool);
bool __fastcall FUN_004d1360(void* p);
unsigned int __cdecl FUN_0047e040(float f);
int __cdecl GetTopicSubTypeName(int, int);
void __cdecl SetTlsInt(int);

// @fnv 0x008bfa40
void ActorX::FUN_008bfa40(RefObj* apSource, int a2, int aiArg3, int aiArg4, TESForm* apForm)
{
    bool h = false; /* -0x11  bFlag  bucket 14 */
    RefObj* p = 0;  /* -0x10  pRes   bucket 15 */
    float a;        /* -0x18  f      bucket 13 */
    RefObj* i;      /* -0x1c  pRef   bucket 12 */
    TESForm* s;     /* -0x20  pOwner bucket 11 */
    bool f;         /* -0x21  bBad   bucket 10 */
    Faction* ax;    /* -0x28  pFac   bucket  9 */
    TESForm* aj;    /* -0x2c  pThing bucket  8 */
    int q;          /* -0x30  r      bucket  7 */
    int b;          /* -0x34  n      bucket  6 */
    char ak;        /* -0x35  c35    bucket  5 */
    NewObj* k;      /* -0x3c  pNew   bucket  4 */
    int l;          /* -0x40  t40    bucket  3 */
    bool c;         /* -0x41  bOk    bucket  2 */
    int e;          /* -0x48  mask   bucket  1 */

    if (this != DAT_011dea3c)
        return;
    if (DAT_011dea3c->GetField228() < ((SettingColl*)&DAT_011cd6fc)->Int()->i)
    {
        if (this == DAT_011dea3c)
            h = true;
    }
    if (this == DAT_011dea3c)
        DAT_011dea3c->AddToField(0, aiArg3);
    else if (this->m_a4.s2(0x2a) >= 100)
        return;
    i = 0;
    f = false;
    if (apSource->r64())
        i = apSource;
    s = apForm;
    if (!s && i)
        s = i->GetOwner();
    a = FUN_0048ebc0(a2, FUN_004d1360(DAT_011dea3c));
    if (a > DAT_01012060)
    {
        a = a * ((FloatSetting*)&DAT_011cdf84)->Float()->f;
        this->GetProcess()->p297(a);
    }
    if (i && i->r134())
        p = i;
    else if (FNV_GetFormType(s) == 8)
    {
        ax = (Faction*)s;
        if (!ax->FUN_0047d7c0())
            f = true;
        p = ((Z*)&DAT_011e0e80)->FUN_00970b30(ax, 1, 0);
    }
    else
    {
        aj = s;
        if (aj)
        {
            q = FUN_0047e040(aj->m100.s3(0x17));
            if (q != 2 && q != 4)
                f = true;
            p = ((Z*)&DAT_011e0e80)->FUN_00970a20(aj, 1);
        }
    }
    if (f)
        DAT_011dea3c->FUN_0094fd30((int)((FloatSetting*)&DAT_011cde20)->Float()->f);
    if (p && !p->r200() && (b = p->FUN_008a0d10(0, this, &ak, 0, 0, 0, 0)) > 0)
    {
        k = 0;
        if (a2)
            k = new NewObj(0, apSource, this, a2, aiArg3, apForm);
        else
            k = new NewObj(0, apSource, this, a2, aiArg4, apForm);
        p->GetExtraData()->AddOrCreateExtraItem(k, ((G67*)&DAT_011de7b8)->FUN_00867da0());
        p->FUN_008bff50();
        p->FUN_008b7c00(1, 1);
        ((Z*)&DAT_011e0e80)->AddObjectToList(k);
        k->AddActor(p);
        if (this->m134)
        {
            c = true;
            if (this->m138 > 0)
            {
                e = this->m138 & 0x1ff;
                if (e != (signed char)((G67*)&DAT_011de7b8)->FUN_00867d60())
                {
                    c = false;
                    this->m134 = 0;
                }
            }
            if (c)
            {
                p->r265(DAT_011dea3c, 0, 1, 0, 0, 0, 1, 0);
                return;
            }
        }
        else
        {
            if (!DAT_011dea3c->FUN_00964100(5))
            {
                this->m134 = 1;
                this->m138 = (((G67*)&DAT_011de7b8)->FUN_00867d20() << 9) |
                             (signed char)((G67*)&DAT_011de7b8)->FUN_00867d60() |
                             (((G67*)&DAT_011de7b8)->FUN_00867c60() << 13);
            }
        }
        if (h)
        {
            p->FUN_008bf7b0(this, apForm);
            return;
        }
        SetTlsInt((int)s);
        this->SetLight(k->FUN_0084e3a0());
        l = GetTopicSubTypeName(2, 9);
        p->GetProcess()->p169(p, l, 0, 0, 1, 0);
        SetTlsInt(0);
    }
}
