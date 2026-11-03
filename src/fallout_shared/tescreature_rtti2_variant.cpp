// src/fallout_shared/tescreature_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (BGSBodyPartData, TESForm). The skeleton of src/fallout_shared/tescreature.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tescreature_decls_rtti2_tescreature.h"

class TESForm;
class TESCreature;
class BGSBodyPartData;
class TESCombatStyle;
class BGSImpactDataSet;
class BGSListForm;
struct FormObj_CreatureInit;
struct Host_CreatureInit;

struct FormObj_CreatureInit
{
    unsigned int FUN_0084e3a0();
};

struct Sub30_CreatureInit
{
    void FUN_0047d8b0(void*);
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
    bool FUN_00461580(unsigned int) const;
    unsigned int FUN_0059bb30();
};

struct Sub64_CreatureInit
{
    void FUN_00481bb0(void*);
    int u00, u04, u08;
};

struct Sub70_CreatureInit
{
    void FUN_0047beb0(void*);
    int u00, u04, u08;
};

struct Sub7c_CreatureInit
{
    void FUN_0048d400(void*);
    int u00, u04, u08, u0c, u10;
};

struct AIList_CreatureInit
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int Size();
    int u04;
};

struct Sub90_CreatureInit
{
    void FUN_0047f4c0(void*);
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    AIList_CreatureInit packages;
    int u28, u2c, u30;
    int u34, u38, u3c;
};

struct Subd0_CreatureInit
{
    int u00, u04, u08;
};

struct Subdc_CreatureInit
{
    int u00, u04, u08, u0c, u10, u14;
    struct ScriptInit
    {
        int u00, u04, u08;
        void FUN_0048cd90(void*);
    } script;
    int u24;
};

struct Sub104_CreatureInit
{
    void FUN_00478be0(void*);
    int u00, u04;
    int u08, u0c;
};

struct Sub114_CreatureInit
{
    int u00, u04, u08, u0c, u10;
};

struct Sub12c_CreatureInit
{
    int u00;
};

struct Host_CreatureInit
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
    virtual const char* v76();
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
    virtual struct FormObj_CreatureInit* v96();
    virtual void v97();
    virtual TESCombatStyle* v98();
    virtual void v99(TESCombatStyle*);

    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    Sub30_CreatureInit m_30;
    Sub64_CreatureInit m_64;
    Sub70_CreatureInit m_70;
    Sub7c_CreatureInit m_7c;
    Sub90_CreatureInit m_90;
    Subd0_CreatureInit m_d0;
    Subdc_CreatureInit m_dc;
    Sub104_CreatureInit m_104;
    Sub114_CreatureInit m_114;
    struct Host_CreatureInit* m_128;
    Sub12c_CreatureInit m_12c;
    unsigned char m_130;
    unsigned char m_131;
    unsigned char m_132;
    unsigned char m_133;
    float m_134;
    float m_138;
    float m_13c;
    TESCombatStyle* m_140;
    BGSBodyPartData* m_144;
    int m_148;
    BGSImpactDataSet* m_14c;
    int m_150;
    int m_154;
    BGSListForm* m_158;

    bool FUN_004013e0() const;
    void* FUN_00484e60(int);
    unsigned int FUN_0084e3a0();
    void FUN_00565210(bool);
    void FUN_00484ab0(int);
    void FUN_005f9340();
};

class TESCreature;
class BGSBodyPartData;
extern "C" void __cdecl FUN_00485d50(unsigned int*, void*);
extern "C" class TESForm* __cdecl LookupFormByID(unsigned int);
void __cdecl FUN_005b5e40(const char*, ...);
TESCombatStyle* __cdecl FUN_00505000();
extern "C" const char DAT_010495e0[], DAT_01049598[], DAT_01049548[], DAT_010494f8[], DAT_0102c740[], DAT_010494bc[];
class TESCombatStyle
{
};
class BGSImpactDataSet
{
};
class BGSListForm
{
};

// @fnv 0x005f9340
void Host_CreatureInit::FUN_005f9340()
{
    unsigned int formId;
    if (FUN_004013e0())
        return;
    m_dc.script.FUN_0048cd90(this);
    m_64.FUN_00481bb0(this);
    m_7c.FUN_0048d400(this);
    m_70.FUN_0047beb0(this);
    m_90.FUN_0047f4c0(this);
    m_30.FUN_0047d8b0(this);
    m_104.FUN_00478be0(this);
    if (m_30.u04 & 1)
    {
        m_30.u04 &= ~0x40;
        m_30.u04 &= ~0x10;
        m_30.u04 &= ~0x20;
        m_30.u04 &= ~0x40000;
        m_30.u04 &= ~0x800000;
    }
    if (!m_30.FUN_00461580(0x100))
    {
        unsigned int soundId = (unsigned int)m_128;
        if (soundId)
        {
            FUN_00485d50(&soundId, FUN_00484e60(-1));
            m_128 = (struct Host_CreatureInit*)dynamic_cast<TESCreature*>(LookupFormByID(soundId));
            if (!m_128)
            {
                FUN_005b5e40(DAT_010495e0, soundId, FUN_0084e3a0(), v76());
            }
            else if (m_128 == this || m_128->m_30.FUN_0059bb30())
            {
                FUN_005b5e40(DAT_01049598, m_128->v76(), m_128->FUN_0084e3a0(), v76(), FUN_0084e3a0());
                m_128 = 0;
            }
        }
    }
    if (m_140)
    {
        unsigned int combatId = (unsigned int)v98();
        if (combatId)
        {
            FUN_00485d50(&combatId, FUN_00484e60(-1));
            m_140 = dynamic_cast<TESCombatStyle*>(LookupFormByID(combatId));
            if (!m_140)
            {
                FUN_005b5e40(DAT_01049548, combatId, FUN_0084e3a0(), v76());
            }
        }
    }
    if (!v98())
        v99(FUN_00505000());
    if (m_144)
    {
        unsigned int bodyId = (unsigned int)m_144;
        if (bodyId)
        {
            FUN_00485d50(&bodyId, FUN_00484e60(-1));
            m_144 = dynamic_cast<BGSBodyPartData*>(LookupFormByID(bodyId));
            if (!m_144)
            {
                FUN_005b5e40(DAT_010494f8, bodyId, FUN_0084e3a0(), v76());
            }
        }
    }
    formId = (unsigned int)m_14c;
    if (formId)
    {
        FUN_00485d50(&formId, FUN_00484e60(-1));
        m_14c = dynamic_cast<BGSImpactDataSet*>(LookupFormByID(formId));
        if (!m_14c)
            FUN_005b5e40(DAT_0102c740, formId, v76(), FUN_0084e3a0());
    }
    formId = (unsigned int)m_158;
    if (formId)
    {
        FUN_00485d50(&formId, FUN_00484e60(-1));
        m_158 = dynamic_cast<BGSListForm*>(LookupFormByID(formId));
        if (!m_158)
            FUN_005b5e40(DAT_010494bc, formId, v76(), FUN_0084e3a0());
    }
    if (m_90.packages.Size() <= 0)
        FUN_00565210(true);
    FUN_00484ab0(1);
}

namespace fnv_005fb270 {
__if_not_exists(::TESCombatStyle::SetFormType)
{
    class TESCombatStyle : public ::TESForm
    {
    };
}

::TESForm* __cdecl LookupFormByID(unsigned int formId);

struct TESCreatureCall_1b30
{
    void FUN_005f1b30(int a1, int a2);
};

struct TESCreatureCall_0d00
{
    void FUN_00484d00(void* p, int v);
    void FUN_00484d40(unsigned int* p, int n);
};

__if_exists(::TESCreature::m_ucField00)
{
    struct TESCreatureLoad : ::TESCreature
    {
        void FUN_005fb270(int a1, int a2);
    };
}

// @fnv 0x005fb270
void TESCreatureLoad::FUN_005fb270(int a1, int a2)
{
    ((TESCreatureCall_1b30*)this)->FUN_005f1b30(a1, a2);
    if (a1 & 0x200)
    {
        ((TESCreatureCall_0d00*)this)->FUN_00484d00(&m_ucField00, 1);
        ((TESCreatureCall_0d00*)this)->FUN_00484d00(&m_ucField01, 1);
        ((TESCreatureCall_0d00*)this)->FUN_00484d00(&m_ucField02, 1);
    }
    if (a1 & 0)
    {
        unsigned int formId;
        ((TESCreatureCall_0d00*)this)->FUN_00484d40(&formId, 4);
        ::TESCombatStyle* style = dynamic_cast< ::TESCombatStyle*>(LookupFormByID(formId));
        if (style)
        {
            m_pCombatStyle = style;
        }
    }
}
}  // namespace fnv_005fb270
