
// src/fallout/interface/menus/traitmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/traitmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TraitMenu
{
    int FUN_007e68a0();
};

// @fnv 0x007e68a0
int TraitMenu::FUN_007e68a0()
{
    return 0x43c;
}

// @fnv 0x007e6dc0
int FUN_007e6dc0()
{
    return 0x43c;
}

struct FUN_007e6dd0_shell
{
    void* m_kPointA[9];
    void* m_kPointB[9];
    void* m_iThirdValue[9];
    void* m_iFourthElementInteger[9];
    void* m_usTrailingValue[9];
    void* m_f[9];
    void* m_g[9];
    void* m_h[9];
    void* m_i[9];
    bool FUN_007e6dd0();
};

// @fnv 0x007e6dd0
bool FUN_007e6dd0_shell::FUN_007e6dd0()
{
    for (int i = 0; i < 9; ++i)
    {
        if (((void**)((char*)this + 0x28))[i] == 0)
            return false;
    }
    return true;
}

namespace fnv_007e73c0 {
struct Menu
{
    void SetMenuVisibility(bool);
};

struct HUDMainMenu
{
    bool RefreshTargetDisplay(void);
};

struct TraitMenu : Menu
{
    void FUN_007e73c0();
};

extern HUDMainMenu DAT_011f2250;

// @fnv 0x007e73c0
void TraitMenu::FUN_007e73c0()
{
    if (*(int*)((char*)this + 0x24) == 4)
    {
        if (!DAT_011f2250.RefreshTargetDisplay())
        {
            SetMenuVisibility(false);
        }
    }
}
}  // namespace fnv_007e73c0

struct FUN_007e6910_shell
{
    void FUN_007e6910();
};
void _Deallocate(void*);
struct FUN_007e68e0_shell
{
    void* FUN_007e68e0(unsigned int);
};
// Calls FUN_007e6910 on this, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x007e68e0
void* FUN_007e68e0_shell::FUN_007e68e0(unsigned int flags)
{
    ((FUN_007e6910_shell*)this)->FUN_007e6910();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_011daf5c;
extern int DAT_011daf74;
struct Tile
{
    bool ContainsTrait(int);
    void Set(int, int);
    void __thiscall UpdateEffectChanges(Tile*);
};
// @fnv 0x007e7630
void FUN_007e7630(Tile* apTile)
{
    if (apTile->ContainsTrait(DAT_011daf5c))
    {
        apTile->Set(DAT_011daf5c, 0);
        ((Tile*)DAT_011daf74)->UpdateEffectChanges(apTile);
    }
}

struct Tile;
struct FUN_007e68b0_shell
{
    unsigned char _pad[0x28];
    Tile* m_pTiles[36];
    void SetTileById(int id, Tile* tile);
};

// Stores tile in the slot at index id when id is between 0 and 8.
// @fnv 0x007e68b0
void FUN_007e68b0_shell::SetTileById(int id, Tile* tile)
{
    if (id >= 0 && id < 9)
    {
        m_pTiles[id] = tile;
    }
}

namespace fnv_007e75d0 {
struct Tile
{
    bool ContainsTrait(int);
};
struct Interface
{
    static void __cdecl PlayUISound(int);
};
struct FUN_007e75d0_shell
{
    virtual void _v0();
    virtual void _v1();
    virtual void _v2();
    virtual void _v3(int, int);
    char _pad[0x3C];
    Tile* m_40;
    bool HandleButton(int aiButton, float afValue);
};
// @fnv 0x007e75d0
bool FUN_007e75d0_shell::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 11:
        if (m_40->ContainsTrait(0xFAF))
        {
            Interface::PlayUISound(1);
            _v3(6, 0);
            bhandled = true;
        }
    }
    return bhandled;
}
}  // namespace fnv_007e75d0

namespace fnv_007e76e0 {
struct Tile
{
    bool ContainsTrait(int);
};
struct BGSPerk
{
};
struct PC7d
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
    virtual void F498(BGSPerk*, int);
    virtual void vfill();
    virtual bool F4A0(BGSPerk*, int, int);
};
extern int DAT_011daf5c;
extern PC7d* g_thePlayer;
// @fnv 0x007e76e0
void FUN_007e76e0(Tile* apTile, BGSPerk* apPerk)
{
    if (apTile->ContainsTrait(DAT_011daf5c))
        g_thePlayer->F498(apPerk, g_thePlayer->F4A0(apPerk, 0, 0) + 1);
}
}  // namespace fnv_007e76e0

struct BGSPerk;
struct FNStub
{
    const char* GetFullName();
};
struct BGSPerk
{
    virtual ~BGSPerk();
    unsigned char m_ucFormType;
    unsigned char cFormTypePad05;
    unsigned short usFormTypePad06;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    void* pSourceFilesHead;
    void* pSourceFilesNext;
    FNStub fullName;
    unsigned char FUN_005d4ee0();
};
struct BSSimpleList
{
    BGSPerk** GetItem();
    BSSimpleList* GetNext();
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
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
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
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
    virtual void v11a();
    virtual void v11b();
    virtual void v11c();
    virtual void v11d();
    virtual void v11e();
    virtual void v11f();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual unsigned char GetPerkRank(BGSPerk* perk, bool team);
};
extern PlayerCharacter* g_thePlayer;
struct StartMenu
{
    const char* GetMenuTitle();
};
extern StartMenu g_011d35b8;
extern int DAT_011daf78;
int strcpy_s(char*, unsigned int, const char*);
int _sprintf_s(char*, unsigned int, const char*, ...);
unsigned int BSStringLength(const char*);
struct LBH
{
    void Initialize(Tile*, const char*);
    Tile* AddItemTile(BGSPerk* item, const char* text, int a, int b);
};
struct FUN_007e7030_shell
{
    void PopulatePerkList();
};
// Initializes the LUM_PerkTemplate list and adds a tile per perk with its name and rank, setting two tile values.
// @fnv 0x007e7030
void FUN_007e7030_shell::PopulatePerkList()
{
    int itotalSkillPoints = 0;
    int inumSkills = 0;
    ((LBH*)((char*)this + 0x54))->Initialize(*(Tile**)((char*)this + 0x2c), "LUM_PerkTemplate");
    for (BSSimpleList* pcurrentPerk = (BSSimpleList*)((char*)this + 0x84); pcurrentPerk && *pcurrentPerk->GetItem();
         pcurrentPerk = pcurrentPerk->GetNext())
    {
        Tile* pnew;
        int icurrRank;
        char strtemp[64];
        icurrRank = g_thePlayer->GetPerkRank(*pcurrentPerk->GetItem(), false);
        pnew = 0;
        strcpy_s(strtemp, 64, (*pcurrentPerk->GetItem())->fullName.GetFullName());
        if (!BSStringLength(strtemp))
            strcpy_s(strtemp, 64, g_011d35b8.GetMenuTitle());
        if ((*pcurrentPerk->GetItem())->FUN_005d4ee0() > 1 && icurrRank > 0)
            _sprintf_s(strtemp, 64, "%s (%d)", strtemp, icurrRank + 1);
        pnew = ((LBH*)((char*)this + 0x54))->AddItemTile(*pcurrentPerk->GetItem(), strtemp, 0, 0);
        pnew->Set(0xfaa, 10);
        pnew->Set(DAT_011daf78, icurrRank + 1);
    }
}

struct ListBox_TESObjectREFR
{
    void Traverse(void(__cdecl*)(Tile*, void*), int, int);
};
struct TileCenterX
{
    Tile* FUN_00726070();
};
struct NiNodeBooleanState
{
    bool GetBooleanValue();
};
struct Actor
{
    void ConfigureActorState(bool, bool);
};
struct CharacterProgressionShell
{
    NiNodeBooleanState* FUN_00464e10();
};
struct StatsMenu
{
    static void __cdecl UpdateStatusEffects();
};
struct Menu
{
    void LoadMenuData();
};
extern Actor* _g_thePlayer;
extern void __cdecl _FUN_007df4e0();
void __cdecl FUN_0077da30();
void __cdecl FUN_007e76e0(Tile*, void*);
// @fnv 0x007e6e10
void __cdecl FUN_007e6e10()
{
    FUN_0077da30();
    if (DAT_011daf74)
    {
        ((ListBox_TESObjectREFR*)((char*)DAT_011daf74 + 0x54))->Traverse(FUN_007e76e0, 0, 0x7fffffff);
        if (((CharacterProgressionShell*)_g_thePlayer)->FUN_00464e10()->GetBooleanValue())
            _g_thePlayer->ConfigureActorState(true, false);
        _FUN_007df4e0();
        StatsMenu::UpdateStatusEffects();
        ((TileCenterX*)DAT_011daf74)->FUN_00726070()->Set(0x1772, 1);
        ((Menu*)DAT_011daf74)->LoadMenuData();
        DAT_011daf74 = 0;
    }
}

struct TGF
{
    float GetFloat(int);
};

struct FUN_006aabf0_shell
{
    signed char GetByteAt39();
};

struct FUN_007e7740_TileString
{
    char const* GetString(int);
};

template <class T> struct ListBoxItem
{
    Tile* pTile;
    FUN_006aabf0_shell* pValue;
};

extern int DAT_011daf70;

int __cdecl FUN_00408b20(char const*, char const*);

// @fnv 0x007e7740
int FUN_007e7740(ListBoxItem<BGSPerk*>* apItem1, ListBoxItem<BGSPerk*>* apItem2)
{
    int iresult;

    iresult = 0;
    if (((TGF*)apItem1->pTile)->GetFloat(DAT_011daf70) < ((TGF*)apItem2->pTile)->GetFloat(DAT_011daf70))
    {
        iresult = 1;
    }
    else if (((TGF*)apItem1->pTile)->GetFloat(DAT_011daf70) > ((TGF*)apItem2->pTile)->GetFloat(DAT_011daf70))
    {
        iresult = -1;
    }
    else if (apItem1->pValue->GetByteAt39() < apItem2->pValue->GetByteAt39())
    {
        iresult = -1;
    }
    else if (apItem1->pValue->GetByteAt39() > apItem2->pValue->GetByteAt39())
    {
        iresult = 1;
    }
    else
    {
        iresult = FUN_00408b20(((FUN_007e7740_TileString*)apItem1->pTile)->GetString(0xfc4),
                               ((FUN_007e7740_TileString*)apItem2->pTile)->GetString(0xfc4));
    }

    return iresult;
}

struct Base753230
{
    unsigned int field_04, field_08, field_0c, field_10, field_14, field_18;
    unsigned int field_1c, field_20, field_24, field_28, field_2c, field_30;
    unsigned int field_34, field_38, field_3c, field_40, field_44;
    Base753230();
    virtual ~Base753230();
};
struct Member753230
{
    Member753230();
    ~Member753230();
};
extern const char str_01071ba0[], str_01071b94[], str_01071b88[];
extern const char str_01071b7c[], str_01071b70[], str_01071b64[];
extern int DAT_011d9210, DAT_011d9214, DAT_011d9224;
extern int DAT_011d9218, DAT_011d921c, DAT_011d9220;
extern float DAT_01012054;
int __cdecl TraitNameToIDAdd(const char*, int);
struct FUN_00753230 : Base753230
{
    int field_48, field_4c;
    float field_50;
    bool field_54, field_55;
    unsigned short field_56;
    Member753230 field_58;
    FUN_00753230();
    virtual ~FUN_00753230();
};
// @fnv 0x00753230
FUN_00753230::FUN_00753230()
{
    DAT_011d9210 = TraitNameToIDAdd(str_01071ba0, -1);
    DAT_011d9214 = TraitNameToIDAdd(str_01071b94, -1);
    DAT_011d9224 = TraitNameToIDAdd(str_01071b88, -1);
    DAT_011d9218 = TraitNameToIDAdd(str_01071b7c, -1);
    DAT_011d921c = TraitNameToIDAdd(str_01071b70, -1);
    DAT_011d9220 = TraitNameToIDAdd(str_01071b64, -1);
    field_48 = 0;
    field_50 = DAT_01012054;
    field_55 = false;
    field_54 = false;
}

extern int DAT_011daf74;
struct MenuBase
{
    virtual ~MenuBase();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
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
};
struct TraitEntries
{
    ~TraitEntries();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};
struct SelectionState
{
    ~SelectionState();
};
struct FUN_007e6910 : MenuBase
{
    TraitEntries entries;
    SelectionState selection;
    virtual ~FUN_007e6910();
};
// @fnv 0x007e6910
FUN_007e6910::~FUN_007e6910()
{
    DAT_011daf74 = 0;
}

struct MenuDisplay
{
    void FUN_00a01350(unsigned, const char*, int);
    void FUN_00700320(unsigned, int);
};
struct MessageTemplate
{
    const char* FUN_00403df0();
};
extern MessageTemplate DAT_011d4558, DAT_011d2c10;
int _sprintf_s(char*, unsigned, const char*, ...);
struct TraitMenu_007e71b0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    MenuDisplay* tile38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    int firstValue;
    int lastValue;
    void UpdateValueDifferenceMessage();
};
// Computes lastValue - firstValue, formats it into a message via one of two templates, and passes it to tile38 with a fixed id.
// @fnv 0x007e71b0
void TraitMenu_007e71b0::UpdateValueDifferenceMessage()
{
    char message[64];
    {
        int difference = lastValue - firstValue;
        if (difference == 1)
        {
            _sprintf_s(message, 64, DAT_011d4558.FUN_00403df0(), difference);
            tile38->FUN_00a01350(0xfc4, message, 1);
            tile38->FUN_00700320(0xfa3, 1);
        }
        else
        {
            _sprintf_s(message, 64, DAT_011d2c10.FUN_00403df0(), difference);
            tile38->FUN_00a01350(0xfc4, message, 1);
            tile38->FUN_00700320(0xfa3, 1);
        }
    }
}

struct InputManager
{
    int GetAxisState();
};
struct OSGlobals
{
    InputManager* FUN_00877720(int, int);
};
extern OSGlobals* DAT_011dea0c;
extern unsigned int DAT_011db004;
bool FUN_00709d40();
float FUN_00408820(float);
unsigned int gm_GetTickCount();
int TraitNameToID(const char*);
struct ChoiceTile
{
    void FUN_00a0b110(int);
};
struct ScrollTile
{
    bool IsTraitNonZero(int);
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void SetTraitAndReset(int, float);
};
struct SelectionList
{
    virtual void unused();
    virtual ChoiceTile* Selected();
};
struct ProgressMenu
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Handle(int, ChoiceTile*);
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
    ScrollTile* scroll;
    int unk4c;
    int unk50;
    SelectionList list;
    bool HandleKey(int, int);
};
// @fnv 0x007e73f0
bool ProgressMenu::HandleKey(int key, int unused)
{
    bool handled = false;
    switch (key)
    {
    case 9:
        if (list.Selected())
        {
            list.Selected()->FUN_00a0b110(0xfcb);
            Handle(10, list.Selected());
            handled = true;
        }
        break;
    }
    if (FUN_00709d40() && scroll->IsTraitNonZero(0xfa3))
    {
        int delta = 0;
        int step = 0;
        delta = DAT_011dea0c->FUN_00877720(0, 10)->GetAxisState();
        if (FUN_00408820((float)delta) <= 8689.0)
            delta = 0;
        if (delta != 0)
            step = delta < 0 ? 1 : -1;
        if (step != 0 && gm_GetTickCount() > DAT_011db004)
        {
            ScrollTile* trait = scroll;
            int iValueId = TraitNameToID("_current_value");
            int tile = (int)trait->FUN_00a011b0(iValueId);
            trait->FUN_00a012d0(iValueId, (float)(tile + step), false);
            if (tile != trait->FUN_00a011b0(iValueId))
            {
                trait->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
            }
            DAT_011db004 = gm_GetTickCount() + (DAT_011db004 ? 50 : 500);
        }
        else if (step == 0)
            DAT_011db004 = 0;
    }
    return handled;
}

struct S_007e7670_Player
{
    bool FUN_00785150(void* p);
    char GetByteAt39();
};
struct S_007e7670_Dest
{
    void FUN_00a012d0(int a, float b, int c);
};
struct S_007e7670_Ref
{
    unsigned short FUN_0087f9f0();
};
extern S_007e7670_Ref* DAT_011dea3c;
extern int DAT_011daf70;
extern float DAT_01023cd8;
extern float DAT_0101e704;
// @fnv 0x007e7670
void FUN_007e7670(S_007e7670_Dest* pDest, S_007e7670_Player* pPlayer)
{
    float fValue;
    if (pPlayer->FUN_00785150(DAT_011dea3c) && pPlayer->GetByteAt39() <= DAT_011dea3c->FUN_0087f9f0())
        fValue = DAT_01023cd8;
    else
        fValue = DAT_0101e704;
    pDest->FUN_00a012d0(DAT_011daf70, fValue, 1);
}

struct EffectSetting
{
    bool IsDetrimentalToActorValue(int);
};
struct EffectItem
{
    int FUN_00403ea0();
    int GetMagnitude();
    EffectSetting* GetEffectSetting();
};
struct EffectNode
{
    EffectItem** GetItem();
    EffectNode* GetNext();
};
struct EffectList
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
    EffectNode list;
};
struct PerkEntry
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int GetType();
    EffectList* GetEffects();
};
struct PerkRankList
{
    PerkEntry* GetRank(int);
};
struct ValueTile
{
    float GetValue(int);
    bool GetBool(int);
};
struct LBList
{
    PerkRankList* FindItemData(ValueTile*);
};
struct EffectChange
{
    int magnitude;
    int unk04;
    int unk08;
    int unk0C;
    EffectChange();
};
struct EffectChangeList
{
    void Clear(bool);
    void Add(EffectChange*);
};
extern EffectChangeList g_011daff0;
extern int DAT_011daf78;
extern int DAT_011daf5c;

struct PerkMenuX
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
    LBList list54;
    void UpdateEffectChanges(ValueTile* tile);
};

// @fnv 0x007e7850
void PerkMenuX::UpdateEffectChanges(ValueTile* tile)
{
    PerkRankList* item7 = list54.FindItemData(tile);
    unsigned char rank4 = (unsigned char)tile->GetValue(DAT_011daf78);
    PerkEntry* cur = item7->GetRank(rank4);
    PerkEntry* prev6 = rank4 > 1 ? item7->GetRank(rank4 - 1) : 0;
    if (cur && cur->GetType() == 1)
    {
        EffectList* curEffects = cur->GetEffects();
        EffectList* prevEffects = prev6 ? prev6->GetEffects() : 0;
        g_011daff0.Clear(true);
        for (EffectNode* node3 = curEffects ? &curEffects->list : 0; node3 && *node3->GetItem();
             node3 = node3->GetNext())
        {
            EffectChange changeVal;
            int id9 = (*node3->GetItem())->FUN_00403ea0();
            changeVal.magnitude = (*node3->GetItem())->GetMagnitude();
            if (id9 == -1)
                continue;
            for (EffectNode* prevNodeTmp = prevEffects ? &prevEffects->list : 0; prevNodeTmp && *prevNodeTmp->GetItem();
                 prevNodeTmp = prevNodeTmp->GetNext())
            {
                if ((*prevNodeTmp->GetItem())->FUN_00403ea0() == id9)
                    changeVal.magnitude -= (*prevNodeTmp->GetItem())->GetMagnitude();
            }
            if (!tile->GetBool(DAT_011daf5c))
                changeVal.magnitude *= -1;
            if ((*node3->GetItem())->GetEffectSetting()->IsDetrimentalToActorValue(id9))
                changeVal.magnitude *= -1;
            g_011daff0.Add(&changeVal);
        }
    }
}

struct TraitView;
struct TileView
{
    TileView* ReadFile();
    TraitView* GetMenu();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float);
    void Set(int, const char*, bool);
};
struct ResourceProvider
{
    TileView* FUN_00586150(const char*);
};
ResourceProvider* __cdecl FUN_004b7210();
TraitView* __cdecl FUN_00a09030(int);
void __cdecl FNV_Warning(const char*);
float __stdcall FUN_00a01530(int);
int __cdecl TraitNameToID(const char*);
struct SettingView
{
    int* Int();
    unsigned char* Bool();
    const char* String();
};
extern SettingView DAT_011d2f94, DAT_011d351c, DAT_011d2310, DAT_011d33d8, DAT_011d35c4, DAT_011da034;
struct PerkView : BGSPerk
{
    signed char Level();
    bool GetByteAtOffset56();
    bool FUN_005eba00(PlayerCharacter*);
    bool CheckPlayerConditions();
    bool FUN_00785150(PlayerCharacter*);
};
struct PlayerLevel
{
    unsigned short GetLevel();
};
struct PerkNode
{
    PerkView** FUN_006815c0();
    PerkNode* FUN_00726070();
};
struct DataHandlerView
{
    PerkNode* FUN_00460fb0();
};
extern DataHandlerView* DAT_011c3f2c;
struct PerkList
{
    void AddTail(PerkView*&);
};
struct PerkListBox
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Sort(int(__cdecl*)(ListBoxItem<BGSPerk*>*, ListBoxItem<BGSPerk*>*));
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    void Traverse(void(__cdecl*)(Tile*, void*), int, int);
    void UpdateScrollTile(bool);
};
struct TraitView
{
    virtual ~TraitView();
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
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    TileView* tile28;
    int unk2c, unk30, unk34, unk38;
    TileView* tile3c;
    TileView* tile40;
    int unk44, unk48;
    int selected;
    int count;
    PerkListBox box;
    PerkList perks;
    void FUN_00a1dc70(TileView*, bool);
    bool FUN_007e6dd0();
    Tile* FUN_00726070();
    void PopulatePerkList();
    void UpdateValueDifferenceMessage();
};
extern int DAT_011daf64, DAT_011daf68;
void __cdecl FUN_007e7670(Tile*, void*);
// Loads trait_menu.xml, builds the trait menu, fills its perk list with eligible perks, sets its labels and counts, and returns the menu tile or 0 on failure.
// @fnv 0x007e6990
TileView* __cdecl FUN_007e6990()
{
    TraitView* oldMenu = FUN_00a09030(1084);
    ResourceProvider* root = FUN_004b7210();
    if (oldMenu)
        delete oldMenu;
    TileView* manager = root->FUN_00586150("Data\\Menus\\trait_menu.xml")->ReadFile();
    DAT_011daf74 = (int)manager->GetMenu();
    if (DAT_011daf74 && ((TraitView*)DAT_011daf74)->GetID() == FUN_007e6dc0())
    {
        ((TraitView*)DAT_011daf74)->FUN_00a1dc70(manager, false);
        if (!((TraitView*)DAT_011daf74)->FUN_007e6dd0())
        {
            FNV_Warning("MENUS: Trait Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (manager->FUN_00a011b0(4007) == 6006.0 || manager->FUN_00a011b0(4007) == 102.0)
            manager->FUN_00a012d0(4013, FUN_00a01530(1));
        int count = *DAT_011d2f94.Int();
        ((TraitView*)DAT_011daf74)->selected = 0;
        ((TraitView*)DAT_011daf74)->count = count;
        char text[64];
        if (count == 1)
            _sprintf_s(text, 64, DAT_011d351c.String(), count);
        else
            _sprintf_s(text, 64, DAT_011d2310.String(), count);
        ((TraitView*)DAT_011daf74)->tile28->Set(4036, text, true);
        ((TraitView*)DAT_011daf74)->tile3c->Set(4036, DAT_011d33d8.String(), true);
        ((TraitView*)DAT_011daf74)->tile40->Set(TraitNameToID("_Title"), DAT_011d35c4.String(), true);
        for (PerkNode* node = DAT_011c3f2c->FUN_00460fb0(); node && *node->FUN_006815c0(); node = node->FUN_00726070())
        {
            PerkView* perk = *node->FUN_006815c0();
            if (perk->Level() > 0 && g_thePlayer->GetPerkRank(perk, false) < perk->FUN_005d4ee0() &&
                perk->GetByteAtOffset56() && perk->FUN_005eba00(g_thePlayer) && perk->CheckPlayerConditions())
            {
                bool valid = true;
                if (*DAT_011da034.Bool())
                {
                    if (!perk->FUN_00785150(g_thePlayer) || perk->Level() > ((PlayerLevel*)g_thePlayer)->GetLevel())
                        valid = false;
                }
                if (valid)
                    ((TraitView*)DAT_011daf74)->perks.AddTail(perk);
            }
        }
        ((TraitView*)DAT_011daf74)->PopulatePerkList();
        ((TraitView*)DAT_011daf74)->FUN_00726070()->Set(DAT_011daf64, ((TraitView*)DAT_011daf74)->selected);
        ((TraitView*)DAT_011daf74)->FUN_00726070()->Set(DAT_011daf68, ((TraitView*)DAT_011daf74)->count);
        ((TraitView*)DAT_011daf74)->UpdateValueDifferenceMessage();
        ((TraitView*)DAT_011daf74)->box.Traverse(FUN_007e7670, 0, 0x7fffffff);
        ((TraitView*)DAT_011daf74)->box.Sort(FUN_007e7740);
        ((TraitView*)DAT_011daf74)->box.UpdateScrollTile(true);
        return manager;
    }
    else
    {
        if (DAT_011daf74 && ((TraitView*)DAT_011daf74)->FUN_00726070())
            delete (TraitView*)DAT_011daf74;
    }
    return 0;
}

struct PerkItem_7e6ea0
{
    int unk00[11];
    struct Icon_7e6ea0
    {
        const char* GetIconPath();
    } icon2C;
    void GetDescription(char* buf, unsigned int size);
};

struct PerkList_7e6ea0
{
    PerkItem_7e6ea0* GetItemForTile(Tile* tile);
};

struct Tile_7e6ea0
{
    void Set(int trait, int val);
    void SetString(int trait, const char* str, bool b);
    const char* GetString(int trait);
};

void __cdecl FUN_00706f30(int);

struct TraitMenu_7e6ea0
{
    int unk00[12];
    Tile_7e6ea0* tile30;
    Tile_7e6ea0* tile34;
    Tile_7e6ea0* tile38;
    Tile_7e6ea0* tile3C;
    Tile_7e6ea0* tile40;
    Tile_7e6ea0* tile44;
    ScrollTile* tile48;
    int unk4C;
    int unk50;
    PerkList_7e6ea0 list54;

    void UpdatePerkTile(int id, Tile* tile);
};

// For id 10, fills the icon and description tiles from the perk list item, toggles their visibility, and updates the scroll tile's current value.
// @fnv 0x007e6ea0
void TraitMenu_7e6ea0::UpdatePerkTile(int id, Tile* tile)
{
    switch (id)
    {
    case 10:
        this->tile30->SetString(0xFCC, this->list54.GetItemForTile(tile)->icon2C.GetIconPath(), true);
        char buf[0x200];
        this->list54.GetItemForTile(tile)->GetDescription(buf, 0x200);
        this->tile34->SetString(0xFC4, buf, true);
        if (BSStringLength(this->tile30->GetString(0xFCC)) > 1)
        {
            this->tile30->Set(0xFA3, 1);
        }
        else
        {
            this->tile30->Set(0xFA3, 0);
        }
        this->tile34->Set(0xFA3, 1);
        this->tile44->Set(0xFA3, 0);
        FUN_00706f30(4);
        ScrollTile* scroll2 = this->tile48;
        int traitVal = TraitNameToID("_current_value");
        scroll2->FUN_00a012d0(traitVal, 0.0f, false);
        scroll2->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
        break;
    }
}

namespace fnv_007e7280 {
struct Tile;
struct TileValues
{
    float GetFloat(int);
    void Set(int, int);
};

struct PerkListBox
{
    bool IsSelected(Tile* apTile);
    void Deselect(Tile* apTile);
    void Select(Tile* apTile);
    int GetSelectedCount();
    void Traverse(void(__cdecl* apFunc)(Tile*), int aiStart, int aiEnd);
};

struct MenuTileHolder
{
    TileValues* GetTile();
};

extern int DAT_011daf70;
extern int DAT_011daf64;
void __cdecl FUN_00706f30(int);
void __cdecl FUN_007e6e10();
void __cdecl FUN_007e7630(Tile* apTile);

struct PerkSelectMenu : MenuTileHolder
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
    int iNumSelected;
    int iMaxSelected;
    PerkListBox kList;

    void RefreshTile(Tile* apTile);
    void UpdatePerkList();
    void HandleTileAction(int aiTileID, Tile* apTile);
};

// Handles tile actions by ID: toggles perk selection and refreshes the tile, or resets the selection and traverses the list.
// @fnv 0x007e7280
void PerkSelectMenu::HandleTileAction(int aiTileID, Tile* apTile)
{
    switch (aiTileID)
    {
    case 10:
        if (kList.IsSelected(apTile))
        {
            kList.Deselect(apTile);
            RefreshTile(apTile);
        }
        else if (((TileValues*)apTile)->GetFloat(DAT_011daf70) == 255.0 && iNumSelected < iMaxSelected)
        {
            kList.Select(apTile);
            RefreshTile(apTile);
        }
        iNumSelected = kList.GetSelectedCount();
        GetTile()->Set(DAT_011daf64, iNumSelected);
        UpdatePerkList();
        break;
    case 6:
        FUN_007e6e10();
        break;
    case 5:
        FUN_00706f30(1);
        iNumSelected = 0;
        GetTile()->Set(DAT_011daf64, iNumSelected);
        kList.Traverse(FUN_007e7630, 0, 0x7fffffff);
        UpdatePerkList();
        break;
    }
}
}  // namespace fnv_007e7280
