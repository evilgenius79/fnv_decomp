
// src/fallout/magic/absorbeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/absorbeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Actor;

struct ActiveEffect
{
    void SaveGame(Actor* apActor);
};

struct ValueModifierEffect : ActiveEffect
{
    void FUN_00802db0(Actor* apActor);
};

// @fnv 0x00802db0
void ValueModifierEffect::FUN_00802db0(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
}

struct FUN_00803a50_shell
{
    unsigned char bFlag;  // +0x177
    void FUN_00803a50(unsigned char flag);
};

// @fnv 0x00803a50
void FUN_00803a50_shell::FUN_00803a50(unsigned char flag)
{
    ((unsigned char*)this)[0x177] = flag;
}

struct FUN_00803a90_shell
{
    void SetBoltGrowWidth(float afBoltGrowWidth);
};

// @fnv 0x00803a90
void FUN_00803a90_shell::SetBoltGrowWidth(float afBoltGrowWidth)
{
    *(float*)((char*)this + 0x13c) = afBoltGrowWidth;
}

struct FUN_00803b10_shell
{
    void SetByteAtOffset175(unsigned char value);
};

// @fnv 0x00803b10
void FUN_00803b10_shell::SetByteAtOffset175(unsigned char value)
{
    reinterpret_cast<unsigned char*>(this)[0x175] = value;
}

struct FUN_00803b50_shell
{
    void FUN_00803b50(float value);
};
// @fnv 0x00803b50
void FUN_00803b50_shell::FUN_00803b50(float value)
{
    *(float*)((char*)this + 0x150) = value;
}

namespace fnv_00803d00 {
struct Actor;

struct ValueModifierEffect
{
    void __thiscall FUN_0082cd10(Actor* apActor);
};

struct AbsorbEffect : ValueModifierEffect
{
    void __thiscall InitBoltEffect();
    void __thiscall FUN_00803d00(Actor* apActor);
};

// @fnv 0x00803d00
void __thiscall AbsorbEffect::FUN_00803d00(Actor* apActor)
{
    FUN_0082cd10(apActor);
    InitBoltEffect();
}
}  // namespace fnv_00803d00

namespace fnv_0082a650 {
struct ActiveEffect
{
};
struct ValueModifierEffect
{
    void CopyData(ActiveEffect*);
};
struct AbsorbEffect : ValueModifierEffect
{
    void FUN_0082a650(ActiveEffect*);
};

// @fnv 0x0082a650
void AbsorbEffect::FUN_0082a650(ActiveEffect* apDestination)
{
    ValueModifierEffect::CopyData(apDestination);
}
}  // namespace fnv_0082a650

struct ActiveEffect_LoadGame_Helper
{
    void LoadGame(Actor* apActor);
};

struct ValueModifierEffect_LoadGame_Helper : ActiveEffect_LoadGame_Helper
{
    void FUN_00802dd0(Actor* apActor);
};

// @fnv 0x00802dd0
void ValueModifierEffect_LoadGame_Helper::FUN_00802dd0(Actor* apActor)
{
    ActiveEffect_LoadGame_Helper::LoadGame(apActor);
}

struct AbsorbEffect
{
    void FUN_00802e20();
    void* __thiscall Destroy(unsigned int flags);
};

void __cdecl _Deallocate(void* p);

// Calls FUN_00802e20 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00802df0
void* __thiscall AbsorbEffect::Destroy(unsigned int flags)
{
    this->FUN_00802e20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00803a70_shell
{
    void FUN_00803a70(unsigned int value);
};

// @fnv 0x00803a70
void FUN_00803a70_shell::FUN_00803a70(unsigned int value)
{
    *(unsigned int*)((char*)this + 0x128) = value;
}

struct FUN_00803b30_shell
{
    void FUN_00803b30(float value);
};

// @fnv 0x00803b30
void FUN_00803b30_shell::FUN_00803b30(float value)
{
    *(float*)((char*)this + 0x144) = value;
}

struct ActiveEffect_GetSaveSize_Helper
{
    unsigned short GetSaveSize(Actor* apActor);
};
struct FUN_00802d90_shell : ValueModifierEffect
{
    unsigned short __thiscall FUN_00802d90(Actor* apActor);
};
// @fnv 0x00802d90
unsigned short __thiscall FUN_00802d90_shell::FUN_00802d90(Actor* apActor)
{
    return ((ActiveEffect_GetSaveSize_Helper*)this)->GetSaveSize(apActor);
}

struct FUN_00803ab0_arg
{
    int a;
    int b;
    int c;
    int d;
};
struct FUN_00803ab0_shell
{
    void SetArg(FUN_00803ab0_arg p);
};
// Copies the four-int argument struct into the object at offset 0x154.
// @fnv 0x00803ab0
void FUN_00803ab0_shell::SetArg(FUN_00803ab0_arg aArg)
{
    *(FUN_00803ab0_arg*)((char*)this + 0x154) = aArg;
}

struct FUN_00803ae0_Data
{
    int a0;
    int a1;
    int a2;
    int a3;
};
struct FUN_00803ae0_shell
{
    void SetData(FUN_00803ae0_Data aVal);
};
// Stores the four-int value aVal into the object at offset 0x164.
// @fnv 0x00803ae0
void FUN_00803ae0_shell::SetData(FUN_00803ae0_Data aVal)
{
    *reinterpret_cast<FUN_00803ae0_Data*>((char*)this + 0x164) = aVal;
}

class NiNode;
class NiAVObject
{
  public:
    NiNode* GetParent() const;
};
class NiNode : public NiAVObject
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
    virtual void DetachChildAlt(NiAVObject* apChild);
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T* apObject);
};
void __cdecl FUN_00bc1470(NiAVObject* apSource, NiAVObject* apTarget);
struct FUN_0080d930
{
    virtual ~FUN_0080d930();
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
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
};
struct FUN_00802e20 : FUN_0080d930
{
    NiPointer<NiAVObject> spBolt;
    NiPointer<NiAVObject> spNode50;
    NiPointer<NiAVObject> spNode54;
    NiPointer<NiAVObject> m_spTargetObject;
    virtual ~FUN_00802e20();
};
// @fnv 0x00802e20
FUN_00802e20::~FUN_00802e20()
{
    FUN_00bc1470(spBolt, m_spTargetObject);
    m_spTargetObject = 0;
    if (spBolt)
    {
        NiNode* pParent = ((NiAVObject*)spBolt)->GetParent();
        if (pParent)
            pParent->DetachChildAlt(spBolt);
        spBolt = 0;
    }
}

struct FUN_00802cb0_base
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float unk1c;
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
    void* unk48;
    FUN_00802cb0_base(int a, int b, int c);
    ~FUN_00802cb0_base();
};

struct FUN_00802cb0_sub
{
    FUN_00802cb0_sub(int flag);
    ~FUN_00802cb0_sub();
    void Set(int flag);
    void* unk00;
};

struct FUN_00802cb0_absorb : public FUN_00802cb0_base
{
    ~FUN_00802cb0_absorb();
    FUN_00802cb0_sub m_4c;
    FUN_00802cb0_sub m_50;
    FUN_00802cb0_sub m_54;
    FUN_00802cb0_sub m_58;
    FUN_00802cb0_absorb(int a, int b, int c);
};

// Constructs the object by initialising the base with a, b, c and resetting the four sub-objects m_4c, m_50, m_54 and m_58 to 0.
// @fnv 0x00802cb0
FUN_00802cb0_absorb::FUN_00802cb0_absorb(int aiArg1, int aiArg2, int aiArg3)
    : FUN_00802cb0_base(aiArg1, aiArg2, aiArg3), m_4c(0), m_50(0), m_54(0), m_58(0)
{
    m_58.Set(0);
    m_4c.Set(0);
    m_54.Set(0);
    m_50.Set(0);
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;

struct F40ActiveEffect
{
    static void* operator new(unsigned int size);
    static void operator delete(void* p);

    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void CopyTo(F40ActiveEffect* pkTarget);

    int unk04;
    MagicItem* pkItem;
    EffectItem* pkEffectItem;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    MagicCaster* pkCaster;

    F40ActiveEffect* CreateAbsorbEffectClone();
};

struct F40AbsorbEffect : F40ActiveEffect
{
    F40AbsorbEffect(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffectItem);

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
};

// Allocates a new F40AbsorbEffect from the caster, item and effect item, copies this effect into it, and returns the clone.
// @fnv 0x00802f40
F40ActiveEffect* F40ActiveEffect::CreateAbsorbEffectClone()
{
    F40ActiveEffect* pkClone = new F40AbsorbEffect(pkCaster, pkItem, pkEffectItem);
    CopyTo(pkClone);
    return pkClone;
}

void* __cdecl FormHeap_Allocate(unsigned int size);

struct AbsorbRecord
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
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    static void* operator new(unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
    AbsorbRecord(unsigned int a, unsigned int b, unsigned int c);
};

// Allocates and constructs an AbsorbRecord from three unsigned int arguments, returning the new object.
// @fnv 0x00802ff0
AbsorbRecord* __cdecl CreateAbsorbRecord(unsigned int uiFirst, unsigned int uiSecond, unsigned int uiThird)
{
    return new AbsorbRecord(uiFirst, uiSecond, uiThird);
}

extern double DAT_01012060;

struct FUN_00803070_Probe
{
    unsigned char FUN_00403e60();
};

struct FUN_00803070_Sub
{
    FUN_00803070_Probe* FUN_00825c00(int a);
};

struct FUN_00803070_Node
{
    void* FUN_00815410();
};

struct FUN_00803070_Owner
{
    void* FUN_0045cd60();
    float GetFloatAtOffset1C(int a);
};

struct FUN_00803070_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void vSlot19(void* a, float b);

    int unk04;
    int unk08;
    FUN_00803070_Sub* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_20;

    void FUN_0082c000();
    void* FUN_0045cd60();
    float GetFloatAtOffset1C(int a);
    void FUN_0082be10();
    void InitBoltEffect();
    void FUN_00803070();
};

// @fnv 0x00803070
void FUN_00803070_cls::FUN_00803070()
{
    FUN_0082c000();
    if (m_0c->FUN_00825c00(2)->FUN_00403e60() != 0 || (double)m_20 == DAT_01012060)
    {
        void* result = ((FUN_00803070_Owner*)this)->FUN_0045cd60() != 0
                           ? ((FUN_00803070_Node*)((FUN_00803070_Owner*)this)->FUN_0045cd60())->FUN_00815410()
                           : 0;
        vSlot19(result, -((FUN_00803070_Owner*)this)->GetFloatAtOffset1C(-1));
    }
    FUN_0082be10();
    InitBoltEffect();
}

struct BoltAVOwner
{
    virtual void v00();
    virtual void v01();
    virtual int GetActorValueInt(int iAV);
};

struct BoltProcessStandIn;
struct BoltLOSData
{
    char pad00[0x1e];
    unsigned char bHasLOS;
};

struct BoltActorStandIn
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

    virtual void* Get3D();
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
    virtual bool IsDead(bool bNotEssential);

    char pad04[0xa4 - 4];
    BoltAVOwner kAVOwner;

    float FUN_005723b0(BoltActorStandIn* pkOther, bool b1, bool b2);
    BoltProcessStandIn* FUN_008d8520();
};

struct BoltProcessStandIn
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
    virtual BoltLOSData* GetLOS(BoltActorStandIn* pkTarget, int iUnk);
};

struct BoltCasterSrc
{
    BoltActorStandIn* FUN_00815410();
};
struct BoltTargetSrc
{
    BoltActorStandIn* FUN_00822b40();
};
struct BoltFlags
{
    bool FUN_00403e60();
};
struct BoltEffectSetting
{
    BoltFlags* FUN_00825c00(int iFlag);
};
struct SettingStandIn
{
    float* FUN_00403e20();
};
extern SettingStandIn g_s_011d1aa8;
float __cdecl FUN_006463e0(float f);

struct BoltEffectUpd
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

    virtual int GetActorValue();
    virtual void ApplyDamage(BoltActorStandIn* pkCaster, float fAmount);

    int unk04;
    int unk08;
    BoltEffectSetting* unk0c;
    int unk10[4];
    float unk20;

    void FUN_0082c660(float fTimeOffset);
    BoltCasterSrc* FUN_0045cd60();
    BoltTargetSrc* FUN_0059bb30();
    void Remove(bool bForce);
    bool FUN_00705cf0();
    float GetFloatAtOffset1C(int iIndex);
    void FUN_00803b70(float fTimeOffset);
    void UpdateEffect(float fTimeOffset);
};

// @fnv 0x00803120
void BoltEffectUpd::UpdateEffect(float fTimeOffset)
{
    FUN_0082c660(fTimeOffset);
    BoltActorStandIn* pkCaster = FUN_0045cd60() ? FUN_0045cd60()->FUN_00815410() : 0;
    BoltActorStandIn* pkTarget = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!unk0c->FUN_00825c00(2)->FUN_00403e60() && unk20 > 0.0)
    {
        int iAV = GetActorValue();
        if (pkTarget && pkTarget->kAVOwner.GetActorValueInt(GetActorValue()) <= 0.0)
            Remove(false);
        if (!FUN_00705cf0())
            ApplyDamage(pkCaster, -GetFloatAtOffset1C(-1) * fTimeOffset);
    }
    if (!FUN_00705cf0() && pkTarget && pkTarget->Get3D() && !pkTarget->IsDead(false) && pkCaster && pkCaster->Get3D() &&
        !pkCaster->IsDead(false))
    {
        float fDist = pkCaster->FUN_005723b0(pkTarget, false, false);
        if (fDist > FUN_006463e0(*g_s_011d1aa8.FUN_00403e20()))
            Remove(false);
        else if (pkCaster->FUN_008d8520())
        {
            BoltLOSData* pkLOS = pkCaster->FUN_008d8520()->GetLOS(pkTarget, 0);
            if (pkLOS && !pkLOS->bHasLOS)
                Remove(false);
        }
    }
    else
    {
        Remove(false);
    }
    if (!FUN_00705cf0())
        FUN_00803b70(fTimeOffset);
}

struct S_008033b0_Obj;

struct S_008033b0_Node
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8(S_008033b0_Obj* p);
};

struct S_008033b0_Obj
{
    S_008033b0_Node* FUN_009611e0();
};

struct S_008033b0_Ptr
{
    int unk00;
    int unk04;
    int unk08;
    S_008033b0_Obj* FUN_00559450();
    void FUN_0066b0d0(int v);
};

struct S_008033b0_Q
{
    bool FUN_00403e60();
};

struct S_008033b0_Mgr
{
    S_008033b0_Q* FUN_00825c00(int v);
};

struct S_008033b0_Tgt
{
    void* FUN_00815410();
};

void __cdecl FUN_00bc1470(S_008033b0_Obj* a, S_008033b0_Obj* b);

struct S_008033b0_Fx
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    int unk04;
    int unk08;
    S_008033b0_Mgr* unk0c;
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
    S_008033b0_Ptr p4c;
    S_008033b0_Ptr p58;
    void ApplyEffect();
    S_008033b0_Tgt* FUN_0045cd60();
    float GetFloatAtOffset1C();
    float FUN_0082ce70(float v);
    void Update();
    virtual void vfn_64(void* t, float f, int n);
};

// @fnv 0x008033b0
void S_008033b0_Fx::Update()
{
    ApplyEffect();
    if (unk0c->FUN_00825c00(2)->FUN_00403e60())
    {
        void* t = FUN_0045cd60() ? FUN_0045cd60()->FUN_00815410() : 0;
        float f = FUN_0082ce70(GetFloatAtOffset1C());
        vfn_64(t, f, -1);
    }
    FUN_00bc1470(p4c.FUN_00559450(), p58.FUN_00559450());
    if (p4c.FUN_00559450())
    {
        S_008033b0_Node* n = p4c.FUN_00559450()->FUN_009611e0();
        if (n)
            n->vfn_e8(p4c.FUN_00559450());
        p4c.FUN_0066b0d0(0);
    }
}

namespace fnv_008034c0 {
void* __cdecl FUN_00aa13e0(unsigned int uiSize);
void __cdecl BoltFree(void* pvMem);

struct NiFixedStringStandIn
{
    const char* m_kHandle;
    NiFixedStringStandIn(const char* pString);
    ~NiFixedStringStandIn();
};

struct NiColorAStandIn
{
    float r, g, b, a;
    NiColorAStandIn(float fR, float fG, float fB, float fA);
};

struct NiAVObjectStandIn;

struct BoltExtraData
{
    int unk00, unk04, unk08, unk0c;
    BoltExtraData();
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        BoltFree(pvMem);
    }
    void FUN_00519230(int a1, int a2);
};

struct BoltNode
{
    int unk00[0xac / 4];
    BoltNode(int iChildren);
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        BoltFree(pvMem);
    }
    BoltExtraData* FUN_00a5bdd0(const char* pName);
    void FUN_00a5bc40(const char* pName, BoltExtraData* pkData);
};

struct BoltGeometry
{
    void FUN_00821620(float f);
    void FUN_00507780(float f);
    void FUN_00803b30(float f);
    void FUN_005077a0(float f);
    void FUN_00803b50(float f);
    void SetBoltSmallWidth(float f);
    void SetBoltGrowWidth(float f);
    void FUN_00803a70(unsigned int ui);
    void SetArg(NiColorAStandIn kColor);
    void SetData(NiColorAStandIn kColor);
    void SetByteAtOffset175(unsigned char uc);
    void FUN_00803a50(unsigned char uc);
    void FUN_00bc2360();
};

template <class T> struct BoltPtr
{
    T* m_pObject;
    BoltPtr& FUN_0066b0d0(T* pObject);
    T* FUN_00559450() const;
    bool FUN_00822510(T* pObject) const;
};

const char* __cdecl FUN_00448a80();
BoltGeometry* __cdecl FUN_00bc18d0(BoltNode* pkNode, int iFlag);

struct SettingStandIn
{
    float* FUN_00403e20();
    unsigned int* FUN_0043d4d0();
};
extern SettingStandIn g_s_011d1710;
extern SettingStandIn g_s_011d1c88;
extern SettingStandIn g_s_011d1af0;
extern SettingStandIn g_s_011d1d3c;
extern SettingStandIn g_s_011d1ac0;
extern SettingStandIn g_s_011d1ab4;
extern SettingStandIn g_s_011d1680;
extern SettingStandIn g_s_011d1c64;
extern SettingStandIn g_s_011d18b4;
extern SettingStandIn g_s_011d1570;
extern SettingStandIn g_s_011d1c94;
extern SettingStandIn g_s_011d1818;
extern SettingStandIn g_s_011d1830;
extern SettingStandIn g_s_011d16a4;

struct BoltNodeLookup
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
    virtual NiAVObjectStandIn* GetObjectByName(const NiFixedStringStandIn& kName);
};

struct BoltModelInfo
{
    BoltNodeLookup* GetStringAtOffset();
};
struct BoltRoot
{
    BoltModelInfo* FUN_00496940();
};

struct BoltAttachTarget
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
    virtual void AttachChildInAvailableSlot(BoltNode* pkNode, int iFlag);
};
struct BoltAttachSource
{
    BoltAttachTarget* FUN_005497a0();
};
struct BoltProcess
{
    BoltAttachSource* FUN_008d6f30();
};

struct BoltActor
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
    virtual NiAVObjectStandIn* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual BoltRoot* GetRoot();

    BoltAttachSource* FUN_008d6f30();
};

struct BoltCasterSource
{
    virtual void v00();
    virtual BoltActor* GetActor();
};
struct BoltTargetSource
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
    virtual BoltActor* GetActor();
};

static const char s_szSpine1[] = "Bip01 Spine1";
extern const char g_szBoltEnd[] = "";

struct BoltEffectImpl
{
    char pad00[0x4c];
    BoltPtr<BoltNode> m_spNode;
    BoltPtr<NiAVObjectStandIn> m_spSource;
    BoltPtr<NiAVObjectStandIn> m_spReferencedObject;
    BoltPtr<BoltGeometry> m_spBolt;

    BoltCasterSource* FUN_0059bb30();
    BoltTargetSource* FUN_0045cd60();
    void InitBoltEffect();
};

// Creates the effect's node, attaches it to the caster, builds the bolt geometry and sets its parameters from the global settings.
// @fnv 0x008034c0
void BoltEffectImpl::InitBoltEffect()
{
    m_spNode.FUN_0066b0d0(new BoltNode(0));
    BoltExtraData* pkDataZ = m_spNode.FUN_00559450()->FUN_00a5bdd0(FUN_00448a80());
    if (!pkDataZ)
    {
        pkDataZ = new BoltExtraData;
        m_spNode.FUN_00559450()->FUN_00a5bc40(FUN_00448a80(), pkDataZ);
    }
    pkDataZ->FUN_00519230(1, 1);

    BoltActor* pkAY = FUN_0059bb30() ? FUN_0059bb30()->GetActor() : 0;
    BoltActor* pkBOut = FUN_0045cd60() ? FUN_0045cd60()->GetActor() : 0;
    BoltAttachTarget* pkAttachTmp;
    BoltRoot* pkRootRes;
    if (pkAY && pkBOut)
    {
        pkAttachTmp = pkAY->FUN_008d6f30()->FUN_005497a0();
        pkAttachTmp->AttachChildInAvailableSlot(m_spNode.FUN_00559450(), 1);
        m_spBolt.FUN_0066b0d0(0);
        m_spBolt.FUN_0066b0d0(FUN_00bc18d0(m_spNode.FUN_00559450(), 1));

        pkRootRes = pkBOut->GetRoot();
        if (pkRootRes)
        {
            m_spSource.FUN_0066b0d0(
                pkRootRes->FUN_00496940()->GetStringAtOffset()->GetObjectByName(NiFixedStringStandIn(s_szSpine1)));
            if (m_spSource.FUN_00822510(0))
                m_spSource.FUN_0066b0d0(pkAY->Get3D());
        }
        pkRootRes = pkAY->GetRoot();
        if (pkRootRes)
        {
            m_spReferencedObject.FUN_0066b0d0(
                pkRootRes->FUN_00496940()->GetStringAtOffset()->GetObjectByName(NiFixedStringStandIn(s_szSpine1)));
            if (m_spReferencedObject.FUN_00822510(0))
                m_spReferencedObject.FUN_0066b0d0(pkBOut->Get3D());
        }

        if (m_spBolt.FUN_00559450())
        {
            m_spBolt.FUN_00559450()->FUN_00821620(*g_s_011d1710.FUN_00403e20());
            m_spBolt.FUN_00559450()->FUN_00507780(*g_s_011d1c88.FUN_00403e20());
            m_spBolt.FUN_00559450()->FUN_00803b30(*g_s_011d1af0.FUN_00403e20());
            m_spBolt.FUN_00559450()->FUN_005077a0(*g_s_011d1d3c.FUN_00403e20());
            m_spBolt.FUN_00559450()->FUN_00803b50(*g_s_011d1ac0.FUN_00403e20());
            m_spBolt.FUN_00559450()->SetBoltSmallWidth(*g_s_011d1ab4.FUN_00403e20());
            m_spBolt.FUN_00559450()->SetBoltGrowWidth(*g_s_011d1680.FUN_00403e20());
            m_spBolt.FUN_00559450()->FUN_00803a70(*g_s_011d1c64.FUN_0043d4d0());
            m_spBolt.FUN_00559450()->SetArg(NiColorAStandIn(*g_s_011d1c94.FUN_00403e20(), *g_s_011d1570.FUN_00403e20(),
                                                            *g_s_011d18b4.FUN_00403e20(), 1.0f));
            m_spBolt.FUN_00559450()->SetData(NiColorAStandIn(*g_s_011d16a4.FUN_00403e20(), *g_s_011d1830.FUN_00403e20(),
                                                             *g_s_011d1818.FUN_00403e20(), 1.0f));
            m_spBolt.FUN_00559450()->SetByteAtOffset175(0);
            m_spBolt.FUN_00559450()->FUN_00803a50(1);
            m_spBolt.FUN_00559450()->FUN_00bc2360();
        }
    }
}
}  // namespace fnv_008034c0

struct S_00803b70_Pt
{
    float x;
    float y;
    float z;
    float FUN_00457990();
    S_00803b70_Pt FUN_00439ef0(const S_00803b70_Pt& o);
};

struct FUN_006815c0
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    FUN_006815c0();
    void FUN_00a59780(float a, float b, float c);
};

struct S_00803b70_O4c
{
    void FUN_00440460(S_00803b70_Pt* p);
    void FUN_0043fa80(FUN_006815c0* m);
};
struct S_00803b70_O50
{
    S_00803b70_Pt* FUN_0045bb80();
};
struct S_00803b70_O54
{
    S_00803b70_Pt* FUN_0045bb80();
};
struct S_00803b70_O58
{
    void AddValue(float a, float b, float c);
};

struct S_00803b70_H4c
{
    int unk00;
    S_00803b70_O4c* FUN_00559450();
};
struct S_00803b70_H50
{
    int unk00;
    S_00803b70_O50* FUN_00559450();
};
struct S_00803b70_H54
{
    int unk00;
    S_00803b70_O54* FUN_00559450();
};
struct S_00803b70_H58
{
    int unk00;
    S_00803b70_O58* FUN_00559450();
};

struct S_00803b70_Setting
{
    float* FUN_00403e20(int i);
};
extern S_00803b70_Setting DAT_011d1c10;
extern S_00803b70_Pt DAT_011f426c;
extern unsigned char DAT_011db9f4;
float __cdecl FUN_004b5550(float a, float b);

struct S_00803b70_Main
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
    S_00803b70_H4c m_4c;
    S_00803b70_H50 m_50;
    S_00803b70_H54 m_54;
    S_00803b70_H58 m_58;
    void FUN_00803b70(float value);
};

// @fnv 0x00803b70
void S_00803b70_Main::FUN_00803b70(float value)
{
    if (m_50.FUN_00559450() && m_54.FUN_00559450() && m_4c.FUN_00559450() && m_58.FUN_00559450() && !DAT_011db9f4)
    {
        S_00803b70_Pt v7 = DAT_011f426c;
        v7 = *m_50.FUN_00559450()->FUN_0045bb80();
        m_4c.FUN_00559450()->FUN_00440460(&v7);
        S_00803b70_Pt r = m_54.FUN_00559450()->FUN_0045bb80()->FUN_00439ef0(v7);
        FUN_006815c0 mat;
        float t = r.z;
        r.z = 0.0f;
        float fPlanarLen = r.FUN_00457990();
        mat.FUN_00a59780(FUN_004b5550(r.x, r.y), 0.0f, -FUN_004b5550(t, fPlanarLen));
        m_4c.FUN_00559450()->FUN_0043fa80(&mat);
        m_58.FUN_00559450()->AddValue(value, r.FUN_00457990(), *DAT_011d1c10.FUN_00403e20(0));
    }
}
