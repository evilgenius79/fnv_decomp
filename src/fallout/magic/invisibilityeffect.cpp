
// src/fallout/magic/invisibilityeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/invisibilityeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ValueModifierEffect
{
    ValueModifierEffect(void*, void*, void*);
};
extern int DAT_0107a21c;
struct FUN_0080e030 : ValueModifierEffect
{
    FUN_0080e030(void*, void*, void*);
};
// Constructs the object by calling the ValueModifierEffect base constructor and installing the DAT_0107a21c vtable pointer.
// @fnv 0x0080e030
FUN_0080e030::FUN_0080e030(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    *(int*)this = (int)&DAT_0107a21c;
}

extern float DAT_0107a214;
struct Actor
{
    void UpdateActorPresentation(void);
    virtual void vfn_0x000();
    virtual void vfn_0x004();
    virtual void vfn_0x008();
    virtual void vfn_0x00c();
    virtual void vfn_0x010();
    virtual void vfn_0x014();
    virtual void vfn_0x018();
    virtual void vfn_0x01c();
    virtual void vfn_0x020();
    virtual void vfn_0x024();
    virtual void vfn_0x028();
    virtual void vfn_0x02c();
    virtual void vfn_0x030();
    virtual void vfn_0x034();
    virtual void vfn_0x038();
    virtual void vfn_0x03c();
    virtual void vfn_0x040();
    virtual void vfn_0x044();
    virtual void vfn_0x048();
    virtual void vfn_0x04c();
    virtual void vfn_0x050();
    virtual void vfn_0x054();
    virtual void vfn_0x058();
    virtual void vfn_0x05c();
    virtual void vfn_0x060();
    virtual void vfn_0x064();
    virtual void vfn_0x068();
    virtual void vfn_0x06c();
    virtual void vfn_0x070();
    virtual void vfn_0x074();
    virtual void vfn_0x078();
    virtual void vfn_0x07c();
    virtual void vfn_0x080();
    virtual void vfn_0x084();
    virtual void vfn_0x088();
    virtual void vfn_0x08c();
    virtual void vfn_0x090();
    virtual void vfn_0x094();
    virtual void vfn_0x098();
    virtual void vfn_0x09c();
    virtual void vfn_0x0a0();
    virtual void vfn_0x0a4();
    virtual void vfn_0x0a8();
    virtual void vfn_0x0ac();
    virtual void vfn_0x0b0();
    virtual void vfn_0x0b4();
    virtual void vfn_0x0b8();
    virtual void vfn_0x0bc();
    virtual void vfn_0x0c0();
    virtual void vfn_0x0c4();
    virtual void vfn_0x0c8();
    virtual void vfn_0x0cc();
    virtual void vfn_0x0d0();
    virtual void vfn_0x0d4();
    virtual void vfn_0x0d8();
    virtual void vfn_0x0dc();
    virtual void vfn_0x0e0();
    virtual void vfn_0x0e4();
    virtual void vfn_0x0e8();
    virtual void vfn_0x0ec();
    virtual void vfn_0x0f0();
    virtual void vfn_0x0f4();
    virtual void vfn_0x0f8();
    virtual void vfn_0x0fc();
    virtual void vfn_0x100();
    virtual void vfn_0x104();
    virtual void vfn_0x108();
    virtual void vfn_0x10c();
    virtual void vfn_0x110();
    virtual void vfn_0x114();
    virtual void vfn_0x118();
    virtual void vfn_0x11c();
    virtual void vfn_0x120();
    virtual void vfn_0x124();
    virtual void vfn_0x128();
    virtual void vfn_0x12c();
    virtual void vfn_0x130();
    virtual void vfn_0x134();
    virtual void vfn_0x138();
    virtual void vfn_0x13c();
    virtual void vfn_0x140();
    virtual void vfn_0x144();
    virtual void vfn_0x148();
    virtual void vfn_0x14c();
    virtual void vfn_0x150();
    virtual void vfn_0x154();
    virtual void vfn_0x158();
    virtual void vfn_0x15c();
    virtual void vfn_0x160();
    virtual void vfn_0x164();
    virtual void vfn_0x168();
    virtual void vfn_0x16c();
    virtual void vfn_0x170();
    virtual void vfn_0x174();
    virtual void vfn_0x178();
    virtual void vfn_0x17c();
    virtual void vfn_0x180();
    virtual void vfn_0x184();
    virtual void vfn_0x188();
    virtual void vfn_0x18c();
    virtual void vfn_0x190();
    virtual void vfn_0x194();
    virtual void vfn_0x198();
    virtual void vfn_0x19c();
    virtual void vfn_0x1a0();
    virtual void vfn_0x1a4();
    virtual void vfn_0x1a8();
    virtual void vfn_0x1ac();
    virtual void vfn_0x1b0();
    virtual void vfn_0x1b4();
    virtual void vfn_0x1b8();
    virtual void vfn_0x1bc();
    virtual void vfn_0x1c0();
    virtual void vfn_0x1c4();
    virtual void vfn_0x1c8();
    virtual void vfn_0x1cc();
    virtual void vfn_0x1d0();
    virtual void vfn_0x1d4();
    virtual void vfn_0x1d8();
    virtual void vfn_0x1dc();
    virtual void vfn_0x1e0();
    virtual void vfn_0x1e4();
    virtual void vfn_0x1e8();
    virtual void vfn_0x1ec();
    virtual void vfn_0x1f0();
    virtual void vfn_0x1f4();
    virtual void vfn_0x1f8();
    virtual void vfn_0x1fc();
    virtual void vfn_0x200();
    virtual void vfn_0x204();
    virtual void vfn_0x208();
    virtual void vfn_0x20c();
    virtual void vfn_0x210();
    virtual void vfn_0x214();
    virtual void vfn_0x218();
    virtual void vfn_0x21c();
    virtual void vfn_0x220();
    virtual void vfn_0x224();
    virtual void vfn_0x228();
    virtual void vfn_0x22c();
    virtual void vfn_0x230();
    virtual void vfn_0x234();
    virtual void vfn_0x238();
    virtual void vfn_0x23c();
    virtual void vfn_0x240();
    virtual void vfn_0x244();
    virtual void vfn_0x248();
    virtual void vfn_0x24c();
    virtual void vfn_0x250();
    virtual void vfn_0x254();
    virtual void vfn_0x258();
    virtual void vfn_0x25c();
    virtual void vfn_0x260();
    virtual void vfn_0x264();
    virtual void vfn_0x268();
    virtual void vfn_0x26c();
    virtual void vfn_0x270();
    virtual void vfn_0x274();
    virtual void vfn_0x278();
    virtual void vfn_0x27c();
    virtual void vfn_0x280();
    virtual void vfn_0x284();
    virtual void vfn_0x288();
    virtual void vfn_0x28c();
    virtual void vfn_0x290();
    virtual void vfn_0x294();
    virtual void vfn_0x298();
    virtual void vfn_0x29c();
    virtual void vfn_0x2a0();
    virtual void vfn_0x2a4();
    virtual void vfn_0x2a8();
    virtual void vfn_0x2ac();
    virtual void vfn_0x2b0();
    virtual void vfn_0x2b4();
    virtual void vfn_0x2b8();
    virtual void vfn_0x2bc();
    virtual void vfn_0x2c0();
    virtual void vfn_0x2c4();
    virtual void vfn_0x2c8();
    virtual void vfn_0x2cc();
    virtual void vfn_0x2d0();
    virtual void vfn_0x2d4();
    virtual void vfn_0x2d8();
    virtual void vfn_0x2dc();
    virtual void vfn_0x2e0();
    virtual void vfn_0x2e4();
    virtual void vfn_0x2e8();
    virtual void vfn_0x2ec();
    virtual void vfn_0x2f0();
    virtual void vfn_0x2f4();
    virtual void vfn_0x2f8();
    virtual void vfn_0x2fc();
    virtual void vfn_0x300();
    virtual void vfn_0x304();
    virtual void vfn_0x308();
    virtual void vfn_0x30c();
    virtual void vfn_0x310();
    virtual void vfn_0x314();
    virtual void vfn_0x318();
    virtual void vfn_0x31c();
    virtual void vfn_0x320();
    virtual void vfn_0x324();
    virtual void vfn_0x328();
    virtual void vfn_0x32c();
    virtual void vfn_0x330();
    virtual void vfn_0x334();
    virtual void vfn_0x338();
    virtual void vfn_0x33c();
    virtual void vfn_0x340();
    virtual void vfn_0x344();
    virtual void vfn_0x348();
    virtual void vfn_0x34c();
    virtual void vfn_0x350();
    virtual void vfn_0x354();
    virtual void vfn_0x358();
    virtual void vfn_0x35c();
    virtual void vfn_0console();
    virtual void vfn_0x364();
    virtual void vfn_0x368();
    virtual void vfn_0x36c();
    virtual void vfn_0x370();
    virtual void vfn_0x374();
    virtual void vfn_0x378();
    virtual void vfn_0x37c();
    virtual void vfn_0x380();
    virtual void vfn_0x384(int, float);
    virtual void vfn_0x388();
    virtual void vfn_0x38c();
    virtual void vfn_0x390();
    virtual void vfn_0x394();
    virtual void vfn_0x398();
    virtual void vfn_0x39c();
    virtual void vfn_0x3a0();
    virtual void vfn_0x3a4();
    virtual void vfn_0x3a8();
    virtual void vfn_0x3ac();
    virtual void vfn_0x3b0();
    virtual void vfn_0x3b4();
    virtual void vfn_0x3b8();
    virtual void vfn_0x3bc();
    virtual void vfn_0x3c0();
    virtual void vfn_0x3c4();
    virtual void vfn_0x3c8();
    virtual void vfn_0x3cc();
    virtual void vfn_0x3d0();
    virtual void vfn_0x3d4();
    virtual void vfn_0x3d8();
    virtual void vfn_0x3dc();
    virtual void vfn_0x3e0();
    virtual void vfn_0x3e4();
    virtual void vfn_0x3e8();
    virtual void vfn_0x3ec();
    virtual void vfn_0x3f0();
    virtual void vfn_0x3f4();
    virtual void vfn_0x3f8();
    virtual void vfn_0x3fc();
    virtual void vfn_0x400();
    virtual void vfn_0x404();
    virtual void vfn_0x408();
    virtual void vfn_0x40c();
    virtual void vfn_0x410();
    virtual void vfn_0x414();
    virtual void vfn_0x418();
    virtual void vfn_0x41c(float);
};
extern Actor* g_thePlayer;
bool __cdecl FUN_005b9b00(void);
struct InvisibilityEffect
{
    void __thiscall FUN_0082cd10(Actor*);
    void __thiscall ApplyInvisibility(Actor* actor);
};
// @fnv 0x0080e540
void __thiscall InvisibilityEffect::ApplyInvisibility(Actor* actor)
{
    FUN_0082cd10(actor);
    if (FUN_005b9b00() && actor == g_thePlayer)
    {
        actor->vfn_0x41c(1.0f);
        actor->vfn_0x384(1, DAT_0107a214);
    }
    else
    {
        actor->UpdateActorPresentation();
    }
}

namespace fnv_0080e5b0 {
bool __cdecl FUN_005b9b00();
struct PC7d;
extern PC7d* g_thePlayer;
struct TESForm
{
    virtual void Revert(unsigned int);
};
struct Actor
{
    void UpdateActorPresentation();
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
    virtual void v225(int, float);
};
struct InvisibilityEffect : TESForm
{
    void RevertInvisibility(Actor* apActor);
};
// @fnv 0x0080e5b0
void InvisibilityEffect::RevertInvisibility(Actor* apActor)
{
    TESForm::Revert((unsigned int)apActor);
    if (FUN_005b9b00() && apActor == (Actor*)g_thePlayer)
        apActor->v225(1, 0.0f);
    else
        apActor->UpdateActorPresentation();
}
}  // namespace fnv_0080e5b0

void* __cdecl FormHeap_Allocate(unsigned int uiSize);

class B0E060Effect
{
  public:
    B0E060Effect(void* pvTarget, void* pvItem, void* pvMagnitude);

    static void* operator new(unsigned int uiSize)
    {
        return FormHeap_Allocate(uiSize);
    }
    static void operator delete(void* pvMem);

    virtual ~B0E060Effect();

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
};

class B0E060Source
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void CopyTo(B0E060Effect* pkEffect);

    B0E060Effect* CreateEffect();

    int unk04;
    void* m_pvItem;
    void* m_pvMagnitude;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* m_pvTarget;
};

// Allocates a B0E060Effect from m_pvTarget, m_pvItem and m_pvMagnitude, copies this source into it, and returns it.
// @fnv 0x0080e060
B0E060Effect* B0E060Source::CreateEffect()
{
    B0E060Effect* pkEffect = new B0E060Effect(m_pvTarget, m_pvItem, m_pvMagnitude);
    CopyTo(pkEffect);
    return pkEffect;
}

class BaseProcess
{
  public:
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
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual void vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual int vfn_610();
};
class HighProcess : public BaseProcess
{
  public:
    void FUN_008fe960(Actor*, int, int);
};
struct AVInterface
{
    virtual void slot0();
    virtual void slot4();
    virtual int slot8(int);
};
struct ActorData : Actor
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
    AVInterface values;
    BaseProcess* GetProcess();
};
struct Target
{
    ActorData* FUN_00822b40();
};
struct Effect
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
    Target* FUN_0059bb30();
    void FUN_0082c000();
    void FUN_0080e110();
};
// @fnv 0x0080e110
void Effect::FUN_0080e110()
{
    ActorData* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    FUN_0082c000();
    if (actor && actor->values.slot8(unk48) > 0.0)
    {
        if (FUN_005b9b00() && actor == g_thePlayer)
        {
            actor->vfn_0x41c(1.0f);
            actor->vfn_0x384(1, DAT_0107a214);
        }
        else
        {
            HighProcess* pHighProcess = dynamic_cast<HighProcess*>(actor->GetProcess());
            if (pHighProcess && pHighProcess->vfn_610() != 4)
                pHighProcess->FUN_008fe960(actor, 0, 0);
        }
    }
}

struct ExtraHealth
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
    static void* __cdecl operator new(unsigned int size);
    ExtraHealth(void* a, void* b, void* c);
};
// Allocates and constructs an ExtraHealth object from the three given arguments.
// @fnv 0x0080e4c0
void* __cdecl CreateExtraHealth(void* apArg1, void* apArg2, void* apArg3)
{
    return new ExtraHealth(apArg1, apArg2, apArg3);
}

struct MVActorValueOwner
{
    virtual void v00();
    virtual void v04();
    virtual int GetActorValueInt(int aiActorValue);
};

struct MVActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void SetFloat384(int aiFlag, float afValue);
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
    MVActorValueOwner kAVOwner;

    BaseProcess* GetCurrentProcess();
    void FUN_008c4640();
};

struct MVHighProcess : HighProcess
{
    void SetContentCount(MVActor* apActor, int aiUnk);
};

struct MVMagicTarget
{
    MVActor* GetActor();
};

struct MVFullName
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int GetValue(float afValue);

    unsigned int GetLength();
};

struct MVEffectSetting
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    MVFullName kFullName;
};

struct MVActiveEffect
{
    virtual ~MVActiveEffect();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual bool IsValid();
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

    static void* __cdecl operator new(unsigned int auiSize);
    MVActiveEffect(MVActor* apTarget, int aiValue);
};

struct MVProcessLists
{
    void FUN_00973fd0(MVActiveEffect* apEffect);
};

extern MVActor* g_pMVPlayer;
extern MVProcessLists g_kMVProcessLists;
extern const float g_fMVEffectArg;
bool __cdecl FUN_005b9b00();
float __cdecl FUN_0040df50();
float __cdecl GetOriginalRuntimeFloatSetting9();
float __cdecl LinearInterpolate(float a1, float a2, float a3, float a4, float a5);

struct MVEffect
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
    int m_eAssociatedActorValue;

    void ApplyEffect();
    MVMagicTarget* GetTarget();
    MVEffectSetting* GetEffectSetting();
    void FUN_0080e230();
};

// @fnv 0x0080e230
void MVEffect::FUN_0080e230()
{
    ApplyEffect();
    MVActor* pTarget = GetTarget() ? GetTarget()->GetActor() : 0;
    if (pTarget && pTarget->kAVOwner.GetActorValueInt(m_eAssociatedActorValue) == 0.0)
    {
        if (FUN_005b9b00() && pTarget == g_pMVPlayer)
        {
            pTarget->SetFloat384(1, 0.0f);
        }
        else
        {
            HighProcess* pProcess = dynamic_cast<HighProcess*>(pTarget->GetCurrentProcess());
            if (pProcess && pProcess->vfn_610() != 4)
                static_cast<MVHighProcess*>(pProcess)->SetContentCount(pTarget, 0);
        }

        float m_fElapsedTime = 0.0f;
        if (m_fElapsedTime > 0.0)
        {
            if (FUN_005b9b00())
            {
                float fValue = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), FUN_0040df50(), 0.0f, 1.0f,
                                                 1.0f - m_fElapsedTime);
                pTarget->SetFloat384(1, fValue);
            }
            else
                pTarget->FUN_008c4640();
        }
        else
            pTarget->FUN_008c4640();

        MVActiveEffect* pEffect5 = 0;
        if (GetEffectSetting()->kFullName.GetLength() > 0)
            pEffect5 = new MVActiveEffect(pTarget, GetEffectSetting()->kFullName.GetValue(g_fMVEffectArg));
        if (pEffect5 && pEffect5->IsValid())
            g_kMVProcessLists.FUN_00973fd0(pEffect5);
        else
            delete pEffect5;
    }
}
