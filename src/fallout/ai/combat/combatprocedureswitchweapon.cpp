
// src/fallout/ai/combat/combatprocedureswitchweapon.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureswitchweapon.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0(void);
};

extern int DAT_010920cc;

struct FUN_009da7a0_shell : FUN_009ca6c0_shell
{
    void FUN_009da7a0(void);
};

// @fnv 0x009da7a0
void __thiscall FUN_009da7a0_shell::FUN_009da7a0(void)
{
    *(int*)this = (int)&DAT_010920cc;
    FUN_009ca6c0_shell::FUN_009ca6c0();
}

struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
    void SaveData(void*, int, int);
};

struct CombatProcedure
{
    void SaveGame(BGSSaveFormBuffer*);
};

struct CombatProcedureSwitchWeapon
{
    CombatProcedure base;
    void* pad1;
    void* pad2;
    void* pad3;
    void* pWeapon;
    void FUN_009da970(BGSSaveFormBuffer*);
};

// Saves the base combat procedure, then writes pWeapon and the 1-byte field at offset 0x14 to the save buffer.
// @fnv 0x009da970
void CombatProcedureSwitchWeapon::FUN_009da970(BGSSaveFormBuffer* buffer)
{
    base.SaveGame(buffer);
    buffer->SerializeFormData(pWeapon, 0);
    buffer->SaveData(reinterpret_cast<char*>(this) + 0x14, 1, 0);
}

void __cdecl Deallocate(void*);
struct FUN_009da770_shell : FUN_009da7a0_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009da7a0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x009da770
void* FUN_009da770_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_009da7a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct BGSLoadGameBuffer
{
    unsigned int ReadFormIdentifier();
};
struct TESForm
{
    virtual ~TESForm();
};
struct TESObjectWEAP : TESForm
{
};
TESForm* __cdecl _ref_004839c0(unsigned int);
struct CombatProcedure_Helper
{
    void LoadGame(BGSLoadFormBuffer*);
};
struct FUN_009da9b0_shell : CombatProcedureSwitchWeapon
{
    void FUN_009da9b0(BGSLoadFormBuffer*);
};
// Loads the base combat procedure state, resolves the weapon form from the buffer, and reads one byte into the field at offset 0x14.
// @fnv 0x009da9b0
void FUN_009da9b0_shell::FUN_009da9b0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((CombatProcedure_Helper*)this)->LoadGame(apLoadGameBuffer);
    pWeapon = dynamic_cast<TESObjectWEAP*>(_ref_004839c0(((BGSLoadGameBuffer*)apLoadGameBuffer)->ReadFormIdentifier()));
    apLoadGameBuffer->ReadTypedData((char*)this + 0x14, 1);
}

struct TESObjectWEAP;
struct FUN_009ca680_holder
{
    void FUN_009ca680();
    char _pad[16];
};
struct FUN_009da720 : FUN_009ca680_holder
{
    void* pWeapon;
    unsigned char m_ucWeaponState;
    FUN_009da720(TESObjectWEAP*);
};
// Calls the base constructor, installs the vtable, stores apWeapon in pWeapon and clears the byte flag.
// @fnv 0x009da720
FUN_009da720::FUN_009da720(TESObjectWEAP* apWeapon)
{
    FUN_009ca680();
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&DAT_010920cc);
    pWeapon = apWeapon;
    m_ucWeaponState = 0;
}

struct TESForm;
struct TESObjectWEAP;
struct ExtraDataList;
struct InvEntry
{
    TESForm* FUN_0044ddc0();
    ExtraDataList* FUN_00726070();
};
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
    virtual struct InvEntry* GetWeaponEntry();
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
    virtual bool IsWeaponOut();
};
struct Actor
{
    int FUN_008a7570();
    BaseProcess* FUN_008d8520();
    void SetWantsWeaponOut(bool);
    int FUN_00575610(TESForm*);
    void EquipItem(TESForm*, int, ExtraDataList*, bool, bool, bool);
    void UnequipItem(TESForm*, ExtraDataList*, bool, bool, bool, bool);
};
struct CombatController
{
    bool FUN_00981990();
    void UpdateActorValues();
};
bool __fastcall FUN_004c0bf0(TESForm*);
bool __fastcall FUN_006450c0(TESForm*);
struct CombatProcedureSW
{
    void* vtbl;
    CombatController* controller;
    int unk08;
    int unk0C;
    TESForm* pWeapon;
    bool m_ucWeaponState;
    Actor* FUN_00996de0();
    void SetState();
    void UpdateWeaponDraw();
};

// @fnv 0x009da7c0
void CombatProcedureSW::UpdateWeaponDraw()
{
    if (controller->FUN_00981990())
    {
        SetState();
        return;
    }
    Actor* actor = FUN_00996de0();
    if (actor->FUN_008a7570() != -1)
        return;
    InvEntry* entry = actor->FUN_008d8520()->GetWeaponEntry();
    TESForm* weap = entry ? entry->FUN_0044ddc0() : 0;
    if (!m_ucWeaponState && weap != pWeapon)
    {
        if (actor->FUN_008d8520()->IsWeaponOut())
        {
            actor->SetWantsWeaponOut(false);
            return;
        }
        if (pWeapon)
        {
            int count = 1;
            if (FUN_004c0bf0(pWeapon))
                count = actor->FUN_00575610(pWeapon);
            actor->EquipItem(pWeapon, count, 0, true, false, true);
        }
        else
        {
            actor->UnequipItem(weap, entry->FUN_00726070(), false, false, false, true);
        }
        m_ucWeaponState = true;
    }
    else if (weap == pWeapon)
    {
        if (!actor->FUN_008d8520()->IsWeaponOut())
            actor->SetWantsWeaponOut(true);
        if (!weap || FUN_006450c0(weap))
            controller->UpdateActorValues();
        SetState();
    }
}
