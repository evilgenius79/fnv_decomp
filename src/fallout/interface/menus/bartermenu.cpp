
// src/fallout/interface/menus/bartermenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/bartermenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0072d030_shell
{
    int __thiscall FUN_0072d030();
};

// @fnv 0x0072d030
int __thiscall FUN_0072d030_shell::FUN_0072d030()
{
    return 0x41d;
}

// @fnv 0x0072d6c0
int __cdecl FUN_0072d6c0()
{
    return 0x41d;
}

char __cdecl ConsumeByteAtE4();
void __cdecl UpdateTopicMenu();

// @fnv 0x0072db40
void __cdecl FUN_0072db40()
{
    if (!ConsumeByteAtE4())
        UpdateTopicMenu();
}

struct FUN_0072dc30_shell
{
    void __thiscall RebuildInventoryLists(int);
};

extern int DAT_011d8fa4;
extern unsigned char DAT_011d8fc0;

// If abNow is set, calls RebuildInventoryLists(0) on DAT_011d8fa4 when non-null and clears DAT_011d8fc0; otherwise sets DAT_011d8fc0 to 1.
// @fnv 0x00730690
void __cdecl FUN_00730690(bool abNow)
{
    if (abNow)
    {
        if (DAT_011d8fa4 != 0)
        {
            reinterpret_cast<FUN_0072dc30_shell*>(DAT_011d8fa4)->RebuildInventoryLists(0);
        }
        DAT_011d8fc0 = 0;
    }
    else
    {
        DAT_011d8fc0 = 1;
    }
}

struct BarterMenu
{
    void* __thiscall FUN_0072d070(unsigned int flags);
    void __thiscall FUN_0072d0a0();
};
void __cdecl _Deallocate(void*);

// Calls FUN_0072d0a0, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0072d070
void* BarterMenu::FUN_0072d070(unsigned int flags)
{
    FUN_0072d0a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0072e530 {
struct Tile
{
    void __thiscall Set(int, int);
};
struct BarterMenu
{
    void __thiscall FUN_0072e530(int, Tile*);
};
// Calls Set(0xfa3, 0) on the Tile objects at offsets 0x7c and 0x78 of this BarterMenu.
// @fnv 0x0072e530
void BarterMenu::FUN_0072e530(int aiID, Tile* apTarget)
{
    ((Tile*)*(int**)((char*)this + 0x7c))->Set(0xfa3, 0);
    ((Tile*)*(int**)((char*)this + 0x78))->Set(0xfa3, 0);
}
}  // namespace fnv_0072e530

struct WeatherEntry
{
};
struct BSSimpleList_WeatherEntry
{
    void Sort(int(__cdecl* fn)(WeatherEntry*, WeatherEntry*));
};

struct FUN_0071a670_shell
{
    void UpdateItems();
};

struct FUN_00730b80_shell
{
    char pad[4];
    BSSimpleList_WeatherEntry list;
    void SortWeatherEntries(int(__cdecl* fn)(WeatherEntry*, WeatherEntry*));
};

// Sorts the weather entry list with the given comparison function, then calls UpdateItems on this object.
// @fnv 0x00730b80
void FUN_00730b80_shell::SortWeatherEntries(int(__cdecl* fn)(WeatherEntry*, WeatherEntry*))
{
    list.Sort(fn);
    reinterpret_cast<FUN_0071a670_shell*>(this)->UpdateItems();
}

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
    virtual bool v285(int a);
};
struct PlayerCharacter
{
    BaseProcess* GetCurrentAIProcess() const;
    void FUN_00950030();
};
extern PlayerCharacter* g_thePlayer;
struct Tile
{
    void SetInt(int aiID, int aiValue);
};
struct TopicMenu
{
    char pad0[4];
    Tile* pTile;
    char pad8[0x11c - 8];
    unsigned char bFlag;
    void FUN_00a1d910();
};
int __cdecl GetTopicSubTypeName(int a, int b);
void __cdecl StartDialogueForTopic(int a);

// @fnv 0x0072d6d0
void __cdecl UpdateTopicMenu()
{
    if (DAT_011d8fa4 != 0)
    {
        BaseProcess* pAIProcess = g_thePlayer->GetCurrentAIProcess();
        if (pAIProcess->v285(1))
            g_thePlayer->FUN_00950030();
        int iTopic = 0;
        if (((TopicMenu*)DAT_011d8fa4)->bFlag)
            iTopic = GetTopicSubTypeName(5, 4);
        StartDialogueForTopic(iTopic);
        ((TopicMenu*)DAT_011d8fa4)->pTile->SetInt(0x1772, 1);
        ((TopicMenu*)DAT_011d8fa4)->FUN_00a1d910();
    }
}

class TESBoundObject
{
  public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual bool CannotSell();
    int FUN_00401170();
};
class TESFullName
{
  public:
    virtual void method0();
    unsigned int GetModelLength() const;
};
class TESObjectARMO : public TESBoundObject
{
  public:
    bool IsFlag80Clear();
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    bool FUN_004c94d0();
};
class TESBipedModelForm
{
  public:
    static TESBipedModelForm* GetFormAsBipedModel(TESBoundObject*);
    bool FUN_00480d90();
};
class InventoryEntry
{
  public:
    TESBoundObject* FUN_0044ddc0();
};
bool FUN_00481f10(TESBoundObject*);
// @fnv 0x0072e570
bool FUN_0072e570(InventoryEntry* entry)
{
    bool unavailable = false;
    {
        TESBoundObject* form;
        {
            TESFullName* name;
            {
                TESObjectWEAP* weapon;
                {
                    TESBipedModelForm* biped;
                    {
                        TESObjectARMO* armor;

                        form = entry ? entry->FUN_0044ddc0() : 0;
                        biped = TESBipedModelForm::GetFormAsBipedModel(form);
                        name = dynamic_cast<TESFullName*>(form);
                        armor = entry->FUN_0044ddc0()->FUN_00401170() == 0x28
                                    ? static_cast<TESObjectARMO*>(entry->FUN_0044ddc0())
                                    : 0;
                        weapon = entry->FUN_0044ddc0()->FUN_00401170() == 0x29
                                     ? static_cast<TESObjectWEAP*>(entry->FUN_0044ddc0())
                                     : 0;
                        if (!form || (biped && !biped->FUN_00480d90()) || form->CannotSell() || FUN_00481f10(form) ||
                            !name || !name->GetModelLength() || (armor && !armor->IsFlag80Clear()) ||
                            (weapon && !weapon->FUN_004c94d0()) || form->FUN_00401170() == 0x2e)
                            unavailable = true;
                    }
                }
            }
        }
    }
    return unavailable;
}

void* __cdecl FUN_004b7210();

struct FUN_0070ec70_This
{
    int FUN_0070ec70();
};

struct FUN_0072f680_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Notify(int aiCode, int aiFlag);
    void FUN_0072f680(int aiType, int aiUnused);
};

// For type 3 or 8, checks FUN_0070ec70() and calls Notify with 2/7 when negative, otherwise 4/9.
// @fnv 0x0072f680
void FUN_0072f680_cls::FUN_0072f680(int aiType, int aiUnused)
{
    if (aiType == 3 || aiType == 8)
    {
        if (((FUN_0070ec70_This*)FUN_004b7210())->FUN_0070ec70() < 0)
            Notify(aiType == 3 ? 2 : 7, 0);
        else
            Notify(aiType == 3 ? 4 : 9, 0);
    }
}

struct S_Node
{
    int unk00, unk04;
    S_Node* FUN_00726070();
    struct S_Item** FUN_006815c0();
    void FUN_00470470();
};
struct S_Item
{
    int FUN_004459e0(int);
};
struct S_Holder
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
    int unk100;
    int unk104;
    int unk108;
    S_Node list1;
    S_Node list2;
};
struct S_Mgr
{
    void FUN_0046faf0();
};
struct S_ListA
{
    int unk00, unk04;
    ~S_ListA();
};
struct S_ListB
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
    ~S_ListB();
};
struct S_Base
{
    virtual ~S_Base();
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
};
extern S_Mgr* DAT_011c3f2c;

struct FUN_0072d0a0 : S_Base
{
    S_ListB m_a8;
    S_ListB m_d8;
    int unk108;
    S_ListA m_10c;
    S_ListA m_114;
    ~FUN_0072d0a0();
};

// @fnv 0x0072d0a0
FUN_0072d0a0::~FUN_0072d0a0()
{
    S_Node* cur;
    S_Node* cur2;
    if (DAT_011d8fa4 != 0)
    {
        for (cur = &((S_Holder*)DAT_011d8fa4)->list1; cur != 0 && *cur->FUN_006815c0() != 0; cur = cur->FUN_00726070())
        {
            S_Item* item = *cur->FUN_006815c0();
            S_Item* obj = item;
            obj != 0 ? obj->FUN_004459e0(1) : 0;
        }
        for (cur2 = &((S_Holder*)DAT_011d8fa4)->list2; cur2 != 0 && *cur2->FUN_006815c0() != 0;
             cur2 = cur2->FUN_00726070())
        {
            S_Item* item2 = *cur2->FUN_006815c0();
            S_Item* obj2 = item2;
            obj2 != 0 ? obj2->FUN_004459e0(1) : 0;
        }
        ((S_Holder*)DAT_011d8fa4)->list1.FUN_00470470();
        ((S_Holder*)DAT_011d8fa4)->list2.FUN_00470470();
    }
    DAT_011c3f2c->FUN_0046faf0();
    DAT_011d8fa4 = 0;
}

extern const char str_010707d0[];
extern const char str_010707b4[];
extern const char str_01070760[];
extern const char str_010704d4[];
extern const char str_0107074c[];
extern const char str_01070740[];
extern const char str_01070734[];
extern const char str_0106ed20[];
extern double DAT_010704f0;
extern double DAT_010704e8;

struct Obj135
{
    void FUN_00a01350(int a, const char* b, bool c);
};

struct SubA0
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
    void FUN_0075a0d0(Obj135* a, const char* b);
};

struct BigObj
{
    virtual int v00(int a);
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
    virtual int v13();
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
    Obj135* m_34;
    int m_38;
    int m_3c;
    Obj135* m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    Obj135* m_54;
    int m_58;
    Obj135* m_5c;
    Obj135* m_60;
    Obj135* m_64;
    Obj135* m_68;
    Obj135* m_6c;
    Obj135* m_70;
    Obj135* m_74;
    int m_78;
    int m_7c;
    int m_80;
    float m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    SubA0 m_a8;
    SubA0 m_d8;
    void FUN_00a1dc70(void* a, int b);
    unsigned char HasNoZeroEntries();
    void FUN_00a1dc20(int a);
    void RebuildInventoryLists(int a);
    int FUN_00726070();
};
extern int DAT_011d8fa4;

struct ObjA
{
    virtual int v0(int a);
};

struct ObjB
{
    BigObj* FUN_00a03c90();
    Obj135* FUN_00a03da0(const char* a);
    double FUN_00a011b0(int a);
    void FUN_00a012d0(int a, float b);
};

struct ObjX
{
    ObjB* ReadXML();
};

struct SelfObj
{
    ObjX* FUN_00586150(const char* a);
    void FUN_00718630(int a, int b, int c);
};

struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011d4378;
extern InventoryMenuSetting DAT_011d25b0;
extern InventoryMenuSetting DAT_011d26f4;
extern InventoryMenuSetting DAT_011d33fc;
extern InventoryMenuSetting DAT_011d2aa8;
extern InventoryMenuSetting DAT_011d26a0;
extern InventoryMenuSetting DAT_011d2c7c;
extern InventoryMenuSetting DAT_011d412c;
extern InventoryMenuSetting DAT_011d330c;
extern InventoryMenuSetting DAT_011d20c4;
extern InventoryMenuSetting DAT_011d396c;
extern char* DAT_011dea3c;

struct SubEA
{
    int FUN_0066ef20(int a);
};

struct ErrLog
{
    static void __cdecl FUN_005b5e40(const char* a);
};

void* __cdecl FUN_004b7210();
int __cdecl FUN_005b5e40(int a, const char* b);
int __cdecl FUN_0072d6c0();
ObjA* __cdecl FUN_00a09030(int a);
int __cdecl TraitNameToID(const char* a);
float __stdcall FUN_00a01530(int a);
void __cdecl FUN_00763ff0();
int __cdecl FUN_00647b70(int a, int b);
int __cdecl MinInt(int a, int b);
int __cdecl FUN_00649050(int a, int* b, int* c);
void __cdecl FUN_00717280(int a);

// Validates arg0, resolves the inventory menu object, initializes its labels and settings from the config, and stores it in DAT_011d8fa4.
// @fnv 0x0072d250
int __cdecl InitInventoryMenu(int arg0, int aiValue)
{
    int aT30;
    BigObj* t2c15;
    int t28a;
    BigObj* cb8;
    BigObj* kCb2;
    ObjA* aChain1;
    ObjA* chain2j;
    int xTmp14;
    Obj135* tmp10o;
    void* selfa = FUN_004b7210();
    ObjB* bb;
    ObjA* ah;

    if (arg0 == 0)
    {
        FUN_005b5e40(0x12, str_010707d0);
        return 0;
    }
    ah = FUN_00a09030(FUN_0072d6c0());
    if (ah != 0)
    {
        aChain1 = ah;
        chain2j = aChain1;
        if (chain2j != 0)
            t28a = chain2j->v0(1);
        else
            t28a = 0;
    }
    bb = ((SelfObj*)selfa)->FUN_00586150(str_010707b4)->ReadXML();
    if (bb != 0)
        t2c15 = bb->FUN_00a03c90();
    else
        t2c15 = 0;
    DAT_011d8fa4 = (int)t2c15;
    if (DAT_011d8fa4 != 0 && ((BigObj*)DAT_011d8fa4)->v13() == FUN_0072d6c0())
    {
        ((BigObj*)DAT_011d8fa4)->FUN_00a1dc70(bb, 0);
        if (((BigObj*)DAT_011d8fa4)->HasNoZeroEntries() == 0)
        {
            ErrLog::FUN_005b5e40(str_01070760);
            return 0;
        }
        if (bb->FUN_00a011b0(0xfa7) == DAT_010704f0 || bb->FUN_00a011b0(0xfa7) == DAT_010704e8)
        {
            bb->FUN_00a012d0(0xfad, FUN_00a01530(1));
        }
        FUN_00763ff0();
        ((SelfObj*)((char*)selfa + 0x4d4))->FUN_00718630(0x17, FUN_0072d6c0(), 0x200);
        ((BigObj*)DAT_011d8fa4)->m_a8.FUN_0075a0d0(((BigObj*)DAT_011d8fa4)->m_40, str_010704d4);
        ((BigObj*)DAT_011d8fa4)->m_d8.FUN_0075a0d0(((BigObj*)DAT_011d8fa4)->m_54, str_010704d4);
        ((BigObj*)DAT_011d8fa4)->m_34->FUN_00a01350(0xfc4, DAT_011d4378.FUN_00403df0(), true);
        bb->FUN_00a03da0(str_0107074c)->FUN_00a01350(0xfc4, DAT_011d25b0.FUN_00403df0(), true);
        ((BigObj*)DAT_011d8fa4)->m_5c->FUN_00a01350(0xfc4, DAT_011d26f4.FUN_00403df0(), true);
        ((BigObj*)DAT_011d8fa4)->m_74->FUN_00a01350(0xfc4, DAT_011d33fc.FUN_00403df0(), true);
        xTmp14 = TraitNameToID(str_0106ed20);
        tmp10o = bb->FUN_00a03da0(str_01070740);
        if (tmp10o != 0)
            tmp10o->FUN_00a01350(xTmp14, DAT_011d2aa8.FUN_00403df0(), true);
        tmp10o = bb->FUN_00a03da0(str_01070734);
        if (tmp10o != 0)
            tmp10o->FUN_00a01350(xTmp14, DAT_011d26a0.FUN_00403df0(), true);
        if (((BigObj*)DAT_011d8fa4)->m_60 != 0)
            ((BigObj*)DAT_011d8fa4)->m_60->FUN_00a01350(xTmp14, DAT_011d2c7c.FUN_00403df0(), true);
        if (((BigObj*)DAT_011d8fa4)->m_64 != 0)
            ((BigObj*)DAT_011d8fa4)->m_64->FUN_00a01350(xTmp14, DAT_011d412c.FUN_00403df0(), true);
        if (((BigObj*)DAT_011d8fa4)->m_68 != 0)
            ((BigObj*)DAT_011d8fa4)->m_68->FUN_00a01350(xTmp14, DAT_011d330c.FUN_00403df0(), true);
        if (((BigObj*)DAT_011d8fa4)->m_6c != 0)
            ((BigObj*)DAT_011d8fa4)->m_6c->FUN_00a01350(xTmp14, DAT_011d20c4.FUN_00403df0(), true);
        if (((BigObj*)DAT_011d8fa4)->m_70 != 0)
            ((BigObj*)DAT_011d8fa4)->m_70->FUN_00a01350(xTmp14, DAT_011d396c.FUN_00403df0(), true);
        ((BigObj*)DAT_011d8fa4)->m_80 = arg0;
        ((BigObj*)DAT_011d8fa4)->m_88 = MinInt(FUN_00647b70(aiValue, -100), 100);
        ((BigObj*)DAT_011d8fa4)->m_84 = 0.0f;
        FUN_00649050(((SubEA*)((char*)DAT_011dea3c + 0xa4))->FUN_0066ef20(0x20), &((BigObj*)DAT_011d8fa4)->m_94,
                     &((BigObj*)DAT_011d8fa4)->m_98);
        FUN_00717280(0x24);
        ((BigObj*)DAT_011d8fa4)->FUN_00a1dc20(0);
        ((BigObj*)DAT_011d8fa4)->RebuildInventoryLists(0);
        return (int)bb;
    }
    else if (DAT_011d8fa4 != 0 && ((BigObj*)DAT_011d8fa4)->FUN_00726070() != 0)
    {
        cb8 = (BigObj*)DAT_011d8fa4;
        kCb2 = cb8;
        if (kCb2 != 0)
            aT30 = kCb2->v00(1);
        else
            aT30 = 0;
    }
    return 0;
}

struct BmTile
{
    float FUN_00a011b0(int m_uiSoundID);
};

struct BmRef
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
    virtual const char* GetEditorID();
    unsigned int FUN_0084e3a0();
};

struct BmExtraList
{
    BmRef* FUN_00418630();
};
struct BmExtraNode
{
    BmExtraList** FUN_006815c0();
};
struct BmItem
{
    int FUN_00726070();
    BmExtraNode* FUN_00559450();
};
extern BmItem* g_pkSelectedItem_011d8fa8;
extern unsigned char g_bBarterFlag_0119fdb0;

struct BmIntSetting
{
    int* FUN_0043d4d0();
};
extern BmIntSetting g_s_011d2418;
struct BmStrSetting
{
    const char* FUN_00403df0();
};
extern BmStrSetting g_s_011d1fa4;
extern BmStrSetting g_s_011d34f8;
extern BmStrSetting g_s_011d3684;

struct BmPopup
{
    virtual void Destroy(bool bFree);
    void FUN_007312e0();
};

struct BmItemList
{
    int FUN_005ae380();
};
struct BmFilteredList
{
    void ApplyFilter(int(__cdecl* pfnFilter)(void*));
    int FUN_0071ae60();
};

int __cdecl TraitNameToID(const char* pName);
int __cdecl TruncateFloatToInt(float f);
bool __cdecl FUN_00703d50();
void __cdecl FUN_00703c00(const char* pFormat, ...);
void __cdecl UpdateBarterQuantity(int iCount);
void __cdecl CreateQuantityMenu(int iCount, void(__cdecl* pfnCallback)(int), int iMax);
void __cdecl FUN_0072db40();
void __cdecl ShowMessageBox(int a1, int a2, const char* pMessage, void(__cdecl* pfnCallback)(), int a5, int a6, float f7,
                          float f8, const char* pButton1, const char* pButton2, int a11);
void __cdecl UpdateTopicMenu();
void __cdecl FUN_00706f30(void* pkTile);
int __cdecl FUN_007304b0(void* pkItem);

static const char s_szNumBartered[] = "_NumBartered";
static const char s_szOrigRef[] = "Original Container Ref: '%s' (%08x)";
static const char s_szOrigRefNone[] = "Original Container Ref: NONE";
extern const char g_szBarterClickEnd[] = "";

struct BarterMenuClick
{
    char pad00[0x28];
    BmTile* m_apTiles[0x16];
    char pad80[0x9c - 0x80];
    int m_iMerchantFilter;
    int m_iPlayerFilter;
    void* unka4;
    BmFilteredList m_kMerchantList;
    char pada9[0xd8 - 0xa9];
    BmFilteredList m_kPlayerList;
    char padd9[0x108 - 0xd9];
    BmPopup* unk108;
    BmItemList m_kMerchantItems;
    char pad10d[0x114 - 0x10d];
    BmItemList m_kPlayerItems;

    void CompleteBarterTransaction();
    void RebuildInventoryLists(int i);
    void UpdateTileText(int iTile);
    void HandleTileClick(int m_uiSoundID, BmTile* pkTile);
};

// @fnv 0x0072d770
void BarterMenuClick::HandleTileClick(int iTileIndex, BmTile* pkTile)
{
    if (!pkTile && iTileIndex >= 0 && iTileIndex < 0x16)
        pkTile = m_apTiles[iTileIndex];
    switch (iTileIndex)
    {
    case 23:
        if (g_pkSelectedItem_011d8fa8 && pkTile)
        {
            g_bBarterFlag_0119fdb0 = 0;
            int iCount = g_pkSelectedItem_011d8fa8->FUN_00726070() -
                         TruncateFloatToInt(pkTile->FUN_00a011b0(TraitNameToID(s_szNumBartered)));
            if (FUN_00703d50())
            {
                BmRef* pkOrig = g_pkSelectedItem_011d8fa8->FUN_00559450() &&
                                        *g_pkSelectedItem_011d8fa8->FUN_00559450()->FUN_006815c0()
                                    ? (*g_pkSelectedItem_011d8fa8->FUN_00559450()->FUN_006815c0())->FUN_00418630()
                                    : 0;
                if (pkOrig)
                    FUN_00703c00(s_szOrigRef, pkOrig->GetEditorID(), pkOrig->FUN_0084e3a0());
                else
                    FUN_00703c00(s_szOrigRefNone);
            }
            else if (iCount > *g_s_011d2418.FUN_0043d4d0())
            {
                unk108->FUN_007312e0();
                unk108->Destroy(false);
                CreateQuantityMenu(iCount, UpdateBarterQuantity, 0x7fffffff);
            }
            else
            {
                UpdateBarterQuantity(1);
            }
        }
        break;
    case 13:
        g_bBarterFlag_0119fdb0 = 0;
        CompleteBarterTransaction();
        RebuildInventoryLists(0);
        break;
    case 19:
        if (m_kMerchantItems.FUN_005ae380() || m_kPlayerItems.FUN_005ae380())
            ShowMessageBox(0, 0, g_s_011d1fa4.FUN_00403df0(), FUN_0072db40, 0, 0x17, 0.0f, 0.0f,
                         g_s_011d34f8.FUN_00403df0(), g_s_011d3684.FUN_00403df0(), 0);
        else
            UpdateTopicMenu();
        break;
    case 2:
    case 3:
    case 4:
        FUN_00706f30(unka4);
        do
        {
            m_iMerchantFilter += (iTileIndex != 2 ? 1 : -1);
            if (m_iMerchantFilter < 0)
                m_iMerchantFilter = 5;
            else if (m_iMerchantFilter > 5)
                m_iMerchantFilter = 0;
            UpdateTileText((int)m_apTiles[3]);
            m_kMerchantList.ApplyFilter(FUN_007304b0);
        } while (!m_kMerchantList.FUN_0071ae60() && m_iMerchantFilter != 0);
        break;
    case 7:
    case 8:
    case 9:
        FUN_00706f30(unka4);
        do
        {
            m_iPlayerFilter += (iTileIndex != 7 ? 1 : -1);
            if (m_iPlayerFilter < 0)
                m_iPlayerFilter = 5;
            else if (m_iPlayerFilter > 5)
                m_iPlayerFilter = 0;
            UpdateTileText((int)m_apTiles[8]);
            m_kPlayerList.ApplyFilter(FUN_007304b0);
        } while (!m_kPlayerList.FUN_0071ae60() && m_iPlayerFilter != 0);
        break;
    }
}

namespace fnv_0072db60 {
// FUN_0072db60: thiscall, /GS, two identical formatted-label blocks.
struct SysVA
{
    void* FUN_00891d70();
};
struct SysVC
{
    void* GetCountableItemCount();
};
struct SysVB
{
    SysVC* FUN_00740960();
};
struct SysStr
{
    char* FUN_00403df0();
};
struct Obj3c
{
    void FUN_00a01350(unsigned int, char*, int);
};
extern SysVA* DAT_011dea3c;
extern SysVB* DAT_011c3f2c;
extern SysStr DAT_011d25b0;
extern "C" int __cdecl FUN_00406d00(char* buf, unsigned int size, const char* fmt, ...);
extern "C" void __cdecl FUN_00ec408c();

struct FUN_0072db60_cls
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
    Obj3c* m_3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    Obj3c* m_50;
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
    int m_8c;
    int m_90;
    void FUN_0072db60();
};

// Stores two values from global subsystems into m_8c and m_90, then formats each with a string and passes it to m_3c and m_50 via FUN_00a01350.
// @fnv 0x0072db60
void FUN_0072db60_cls::FUN_0072db60()
{
    char buf[0x40];
    m_8c = (int)DAT_011dea3c->FUN_00891d70();
    m_90 = (int)DAT_011c3f2c->FUN_00740960()->GetCountableItemCount();
    FUN_00406d00(buf, 0x40, "%s   %d", DAT_011d25b0.FUN_00403df0(), m_8c);
    m_3c->FUN_00a01350(0xfc4, buf, 1);
    FUN_00406d00(buf, 0x40, "%s   %d", DAT_011d25b0.FUN_00403df0(), m_90);
    m_50->FUN_00a01350(0xfc4, buf, 1);
}
}  // namespace fnv_0072db60

struct S_0072e370_Tile : Tile
{
    void FUN_00a01350(int aiID, const char* str);
};

struct S_0072e370_Item
{
    const char* GetIconFilename(int a, int b);
};

struct S_0072e370_Sub
{
    virtual void vfn0(int);
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

    bool ContainsKey(Tile* a, int b);
    S_0072e370_Item* FUN_007a1910();
};

extern "C" int DAT_011d8fb8;
extern "C" unsigned char DAT_0119fdb0;
extern "C" S_0072e370_Item* DAT_011d8fa8;

void __cdecl FUN_00707e30(S_0072e370_Item*, Tile*);

struct S_0072e370
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10(int);
    virtual void vfn14(int, int);

    Tile* tile04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S_0072e370_Tile* tiles[22];
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
    S_0072e370_Sub subA8;
    S_0072e370_Sub subD8;
    S_0072e370_Sub* unk108;

    Tile* FUN_00726070();
    void UpdateTileState(int a1, Tile* a2);
};

// @fnv 0x0072e370
void S_0072e370::UpdateTileState(int aiIndex, Tile* pTile)
{
    if (pTile == 0)
    {
        if (aiIndex >= 0 && aiIndex < 22)
        {
            pTile = this->tiles[aiIndex];
        }
    }

    switch (aiIndex)
    {
    case 0:
        this->vfn14(0x17, 0);
        this->subD8.vfn0(0);
        this->FUN_00726070()->SetInt(DAT_011d8fb8, 0);
        this->unk108 = &this->subA8;
        break;

    case 1:
        this->vfn14(0x17, 0);
        this->subA8.vfn0(0);
        this->FUN_00726070()->SetInt(DAT_011d8fb8, 1);
        this->unk108 = &this->subD8;
        break;

    case 23:
        DAT_0119fdb0 = 1;
        if (this->unk108 == 0)
        {
            this->vfn10(this->subD8.ContainsKey(pTile, 0) ? 1 : 0);
        }
        DAT_011d8fa8 = this->unk108->FUN_007a1910();
        if (DAT_011d8fa8 != 0)
        {
            FUN_00707e30(DAT_011d8fa8, this->tiles[21]);
            this->tiles[21]->SetInt(0xfa3, 1);
            this->tiles[20]->FUN_00a01350(0xfcc, DAT_011d8fa8->GetIconFilename(0, 1));
            this->tiles[20]->SetInt(0xfa3, 1);
        }
        break;
    }
}

struct OwnExtraList
{
    void* FUN_00418660();
    void* FUN_00418690();
    void* FUN_004186c0();
    short FUN_00418770();
};

struct OwnNode
{
    OwnExtraList** FUN_006815c0();
    OwnNode* FUN_00726070();
};

struct OwnExtraContainer
{
    void FUN_00905330(OwnExtraList** ppkList);
};

struct OwnItem
{
    OwnNode* FUN_00559450();
    void* FUN_0044ddc0();
    int FUN_00726070();
    void FUN_006ecd40(int iCount);
};
struct OwnItemExtra
{
};

struct OwnList : OwnNode
{
    OwnExtraList* m_pkItem;
    OwnNode* m_pkNext;
    OwnList();
    ~OwnList();
    void FUN_005ae3d0(OwnExtraList* const& pkItem);
    void FUN_00470470();
};

struct OwnActor
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

    virtual bool IsActor();
};

struct OwnCheck
{
    char acData[0x68];
    OwnCheck();
    ~OwnCheck();
    void FUN_00567ad0(void* pkOwner);
    void FUN_00567b50(void* pkRank);
    void FUN_00567bd0(void* pkGlobal);
    void FUN_00575690(void* pkForm);
    bool FUN_005785e0(OwnActor* pkActor, int i);
};

struct OwnBarterMenu
{
    char pad00[0x80];
    OwnActor* m_pkMerchant;
};
extern OwnBarterMenu* g_pkBarterMenu_011d8fa4;

// @fnv 0x0072eac0
void __cdecl FUN_0072eac0(int iUnused, OwnItem* pkItem)
{
    OwnActor* pkMerchant_ = g_pkBarterMenu_011d8fa4->m_pkMerchant && g_pkBarterMenu_011d8fa4->m_pkMerchant->IsActor()
                                ? g_pkBarterMenu_011d8fa4->m_pkMerchant
                                : 0;
    OwnList kRemoveY;
    for (OwnNode* pkNode = pkItem->FUN_00559450(); pkNode && *pkNode->FUN_006815c0(); pkNode = pkNode->FUN_00726070())
    {
        OwnExtraList* pkExtra = *pkNode->FUN_006815c0();
        if (pkMerchant_ && pkExtra->FUN_00418660())
        {
            OwnCheck kCheck;
            kCheck.FUN_00567ad0(pkExtra->FUN_00418660());
            kCheck.FUN_00567b50(pkExtra->FUN_00418690());
            kCheck.FUN_00567bd0(pkExtra->FUN_004186c0());
            kCheck.FUN_00575690(pkItem->FUN_0044ddc0());
            if (kCheck.FUN_005785e0(pkMerchant_, 1))
                kRemoveY.FUN_005ae3d0(pkExtra);
        }
    }
    for (OwnNode* pkIter = &kRemoveY; pkIter && *pkIter->FUN_006815c0(); pkIter = pkIter->FUN_00726070())
    {
        pkItem->FUN_006ecd40(pkItem->FUN_00726070() - (*pkIter->FUN_006815c0())->FUN_00418770());
        ((OwnExtraContainer*)pkItem->FUN_00559450())->FUN_00905330(pkIter->FUN_006815c0());
    }
    kRemoveY.FUN_00470470();
}

struct S_0072ed00_Tile
{
    bool IsTraitNonZero(int a);
};
struct S_0072ed00_List
{
    int unk00;
    bool ContainsKey(S_0072ed00_Tile* a);
};
struct S_0072ed00_Settings
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
    float unk94;
    float unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    S_0072ed00_List list_d8;
};
struct S_0072ed00_Item : InventoryEntry
{
    float FUN_004bd400();
};
extern int DAT_011d8fb4;
void __cdecl FUN_005e58f0(int type, PlayerCharacter* actor, ...);
int __cdecl FUN_00ec7d40(int);
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00408860(float);
float __cdecl FUN_004bd510(float, float);

// @fnv 0x0072ed00
float __cdecl FUN_0072ed00(S_0072ed00_Tile* tile, S_0072ed00_Item* item)
{
    float amount = item->FUN_004bd400();
    float base = amount;
    bool b5 = ((S_0072ed00_Settings*)DAT_011d8fa4)->list_d8.ContainsKey(tile);
    bool b8 = tile->IsTraitNonZero(DAT_011d8fb4);
    float result = 0.0f;
    if (amount < 0.0)
    {
        result = -1.0f;
    }
    else if ((b5 && !b8) || (!b5 && b8))
    {
        bool isEquip = item->FUN_0044ddc0()->FUN_00401170() == 0x6c || item->FUN_0044ddc0()->FUN_00401170() == 0x74;
        amount *= isEquip ? 1.0f : ((S_0072ed00_Settings*)DAT_011d8fa4)->unk94;
        if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 > 0)
        {
            amount = (1.0 - FUN_00ec7d40(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0) * amount;
        }
        else if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 < 0)
        {
            amount = (FUN_00ec7d40(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0 + 1.0) * amount;
        }
        FUN_005e58f0(0x11, g_thePlayer, item->FUN_0044ddc0(), &amount);
        if (FUN_00408860(amount) > 1.0)
            amount = FUN_004bd510(amount, 1.0f);
        else
            amount = FUN_004bd510(amount, 0.1f);
        result = FUN_00404010(amount, base);
    }
    else if ((b5 && b8) || (!b5 && !b8))
    {
        bool isEquip = item->FUN_0044ddc0()->FUN_00401170() == 0x6c || item->FUN_0044ddc0()->FUN_00401170() == 0x74;
        amount *= isEquip ? 1.0f : ((S_0072ed00_Settings*)DAT_011d8fa4)->unk98;
        if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 > 0)
        {
            amount = (FUN_00ec7d40(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0 + 1.0) * amount;
        }
        else if (((S_0072ed00_Settings*)DAT_011d8fa4)->unk88 < 0)
        {
            amount = (1.0 - FUN_00ec7d40(((S_0072ed00_Settings*)DAT_011d8fa4)->unk88) / 100.0) * amount;
        }
        if (FUN_00408860(amount) > 1.0)
            amount = FUN_004bd510(amount, 1.0f);
        else
            amount = FUN_004bd510(amount, 0.1f);
        result = FUN_0040ebd0(amount, base);
    }
    return result;
}

struct SubNode
{
    void** FUN_006815c0();
};

struct EntryEx : InventoryEntry
{
    SubNode* FUN_00559450();
};

struct ListNode
{
    ListNode* FUN_00726070();
    EntryEx** FUN_006815c0();
};

struct TargetClass
{
    InventoryEntry* FindMatchingEntry(ListNode* head, EntryEx* target);
};

// Walks the linked list and returns the first entry whose FUN_0044ddc0 value and FUN_00559450 sub-node value both match the target's.
// @fnv 0x0072f120
InventoryEntry* TargetClass::FindMatchingEntry(ListNode* head, EntryEx* target)
{
    InventoryEntry* result2 = 0;
    for (ListNode* node2 = head; !result2 && node2 && *node2->FUN_006815c0(); node2 = node2->FUN_00726070())
    {
        EntryEx* item5 = *node2->FUN_006815c0();
        if (target->FUN_0044ddc0() == item5->FUN_0044ddc0())
        {
            void* local7 = target->FUN_00559450() ? *target->FUN_00559450()->FUN_006815c0() : 0;
            void* local_14 = item5->FUN_00559450() ? *item5->FUN_00559450()->FUN_006815c0() : 0;
            if (local7 == local_14)
            {
                result2 = item5;
            }
        }
    }
    return result2;
}

namespace fnv_0072f210 {
struct BarterItem
{
    int FUN_00726070();
    const char* GetTargetFullName();
    bool FUN_004bddd0(int iUnk);
};

struct BarterItemList;

struct BarterTile
{
    bool IsTraitNonZero(int m_uiSoundID);
    void FUN_00700320(int m_uiSoundID, int iValue);
    void FUN_00a01350(int m_uiSoundID, const char* pString, bool bPropagate);
    void FUN_00707e10(const char* pName);
    void FUN_00a012d0(int m_uiSoundID, float fValue, bool bPropagate);
};

struct BarterMenuStandIn
{
    char pad000[0x10c];
    int m_kMerchantItems[2];
    int m_kPlayerItems[2];

    BarterItem* FindMatchingEntry(int* pkList, BarterItem* pkItem);
};
extern BarterMenuStandIn* g_pkBarterMenu_011d8fa4;
extern int g_iTileIDEquipped_011d8fb4;
extern int g_iTileIDValue_011d8fb0;

float __cdecl FUN_0072ed00(BarterTile* pkTile, BarterItem* pkItem);
int __cdecl TraitNameToID(const char* pName);
int __cdecl TraitNameToIDAdd(const char* pName, int iDefault);
int __cdecl FUN_00406d00(char* pBuffer, unsigned int uiSize, const char* pFormat, ...);
int __cdecl FUN_00406d30(char* pBuffer, unsigned int uiSize, const char* pSrc);

static const char s_szNumBartered[] = "_NumBartered";
static const char s_szCountFormat[] = "%s (%d)";
static const char s_szIsEquipped[] = "_IsEquipped";
static const char s_szNoValue[] = "--";
static const char s_szValueFormat1[] = "%.1f";
static const char s_szValueFormat0[] = "%.0f";
extern const char g_szBarterTileEnd[] = "";

// @fnv 0x0072f210
void __cdecl UpdateBarterItemTile(BarterTile* pkTile, BarterItem* pkItem)
{
    char acBuffer[0x80];
    float fValue = FUN_0072ed00(pkTile, pkItem);
    int iCount = 0;
    if (!pkTile->IsTraitNonZero(g_iTileIDEquipped_011d8fb4))
    {
        BarterItem* pkOther =
            g_pkBarterMenu_011d8fa4->FindMatchingEntry(g_pkBarterMenu_011d8fa4->m_kMerchantItems, pkItem);
        if (!pkOther)
            pkOther = g_pkBarterMenu_011d8fa4->FindMatchingEntry(g_pkBarterMenu_011d8fa4->m_kPlayerItems, pkItem);
        iCount = pkItem->FUN_00726070() - (pkOther ? pkOther->FUN_00726070() : 0);
        pkTile->FUN_00700320(TraitNameToID(s_szNumBartered), pkOther ? pkOther->FUN_00726070() : 0);
    }
    else
    {
        iCount = pkItem->FUN_00726070();
    }
    if (iCount > 1)
    {
        FUN_00406d00(acBuffer, 0x80, s_szCountFormat, pkItem->GetTargetFullName(), iCount);
        pkTile->FUN_00a01350(0xfc4, acBuffer, true);
    }
    if (pkItem->FUN_004bddd0(0) && !pkTile->IsTraitNonZero(g_iTileIDEquipped_011d8fb4))
        pkTile->FUN_00700320(TraitNameToIDAdd(s_szIsEquipped, -1), 1);
    if (fValue <= 0.0)
        FUN_00406d30(acBuffer, 0x80, s_szNoValue);
    else if (fValue > 0.0 && fValue < 1.0)
        FUN_00406d00(acBuffer, 0x80, s_szValueFormat1, fValue);
    else
        FUN_00406d00(acBuffer, 0x80, s_szValueFormat0, fValue);
    pkTile->FUN_00a01350(g_iTileIDValue_011d8fb0, acBuffer, true);
    pkTile->FUN_00707e10(pkItem->GetTargetFullName());
    pkTile->FUN_00a012d0(0xfb0, 0.0f, true);
}
}  // namespace fnv_0072f210

// HandleAction candidate
bool __cdecl FUN_00702450(int aiId);

struct FUN_007312e0_shell
{
    void FUN_007312e0();
};
struct FUN_00731360_shell
{
    void UpdateCurrentValueTile(int aiFlag);
};
struct FUN_00730e20_shell
{
    bool FUN_00730e20();
};
struct FUN_00726c40_shell
{
    unsigned int GetRaceCount();
};

struct FUN_0072f4b0_sub
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
};

class FUN_0072f4b0_cls
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(int aiA, int aiB);
    virtual void v04(int aiA, int aiB);
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
    FUN_0072f4b0_sub m_a8;
    FUN_0072f4b0_sub m_d8;
    void* m_108;

    bool HandleAction(int a1, int a2);
};

// @fnv 0x0072f4b0
bool FUN_0072f4b0_cls::HandleAction(int aiAction, int aiUnused)
{
    bool bHandled = false;
    if (FUN_00702450(0x41d))
    {
        switch (aiAction)
        {
        case 13:
            if (!reinterpret_cast<FUN_00730e20_shell*>(&m_a8)->FUN_00730e20())
            {
                if (reinterpret_cast<FUN_00726c40_shell*>(&m_a8)->GetRaceCount() > 0)
                {
                    reinterpret_cast<FUN_007312e0_shell*>(&m_d8)->FUN_007312e0();
                    v04(0, 0);
                    reinterpret_cast<FUN_00731360_shell*>(&m_a8)->UpdateCurrentValueTile(1);
                    bHandled = true;
                }
            }
            break;
        case 14:
            if (!reinterpret_cast<FUN_00730e20_shell*>(&m_d8)->FUN_00730e20())
            {
                if (reinterpret_cast<FUN_00726c40_shell*>(&m_d8)->GetRaceCount() > 0)
                {
                    reinterpret_cast<FUN_007312e0_shell*>(&m_a8)->FUN_007312e0();
                    v04(1, 0);
                    reinterpret_cast<FUN_00731360_shell*>(&m_d8)->UpdateCurrentValueTile(1);
                    bHandled = true;
                }
            }
            break;
        case 3:
        case 4:
            if (m_108 == &m_a8)
            {
                reinterpret_cast<FUN_007312e0_shell*>(&m_a8)->FUN_007312e0();
                v03((aiAction != 4) ? 4 : 2, 0);
                reinterpret_cast<FUN_00731360_shell*>(&m_a8)->UpdateCurrentValueTile(0);
            }
            else
            {
                reinterpret_cast<FUN_007312e0_shell*>(&m_d8)->FUN_007312e0();
                v03((aiAction != 4) ? 9 : 7, 0);
                reinterpret_cast<FUN_00731360_shell*>(&m_d8)->UpdateCurrentValueTile(0);
            }
            bHandled = true;
            break;
        }
    }
    return bHandled;
}

namespace fnv_0072f6f0 {
struct QtyTile
{
    bool IsTraitNonZero(int m_uiSoundID);
    void FUN_00700320(int m_uiSoundID, int iValue);
    void FUN_00a01350(int m_uiSoundID, const char* pString, bool bPropagate);
    void FUN_00a012d0(int m_uiSoundID, float fValue, bool bPropagate);
};

struct QtyForm;
struct QtyItem
{
    QtyForm* FUN_0044ddc0();
};
extern QtyItem* g_pkSelectedItem_011d8fa8;

struct QtyItemList
{
    QtyTile* FindItemData(QtyItem** ppkItem);
};
struct QtyChangeList
{
    bool FUN_008256d0();
};

struct QtyPlayer
{
    void PlayActorSound(QtyForm* pkForm, bool bMerchant, int iUnk);
};
extern QtyPlayer* g_thePlayer_011dea3c;

struct QtyBarterMenu
{
    int unk00;
    QtyTile* unk04;
    char pad08[0x58 - 8];
    QtyTile* unk58;
    QtyTile* unk5c;
    char pad60[0x84 - 0x60];
    float m_fBarterTotal;
    int unk88;
    int m_iMerchantCaps;
    int unk90;
    char pad94[0xa8 - 0x94];
    QtyItemList m_kMerchantList;
    char pada9[0xd8 - 0xa9];
    QtyItemList m_kPlayerList;
    char padd9[0x108 - 0xd9];
    QtyItemList* m_pkActiveList;
    QtyChangeList m_kMerchantItems;
    char pad10d[0x114 - 0x10d];
    QtyChangeList m_kPlayerItems;

    QtyTile* FUN_00726070();
    void DecrementEntryCount(int iCount);
    void AddOrUpdateEntryCount(int iCount);
    void RebuildInventoryLists(QtyForm* pkForm);
};
extern QtyBarterMenu* g_pkBarterMenu_011d8fa4;
extern int g_iTileIDEquipped_011d8fb4;
extern int g_iTileIDValue_011d8fb0;
extern int g_iTileIDState_011d8fbc;

float __cdecl FUN_0072ed00(QtyTile* pkTile, QtyItem* pkItem);
float __cdecl FUN_00406ce0(float f);
int __cdecl TruncateFloatToInt(float f);
int __cdecl MinInt(int a, int b);
int __cdecl FUN_0072fa60(int i);
int __cdecl FUN_00406d00(char* pBuffer, unsigned int uiSize, const char* pFormat, ...);

static const char s_szIntFormat[] = "%d";
extern const char g_szBarterQtyEnd[] = "";

// @fnv 0x0072f6f0
void __cdecl UpdateBarterQuantity(int iCount)
{
    QtyTile* pkTile = g_pkBarterMenu_011d8fa4->m_pkActiveList->FindItemData(&g_pkSelectedItem_011d8fa8);
    if (!iCount || !g_pkSelectedItem_011d8fa8 || !pkTile)
        return;
    g_pkBarterMenu_011d8fa4->m_fBarterTotal +=
        FUN_0072ed00(pkTile, g_pkSelectedItem_011d8fa8) *
        (g_pkBarterMenu_011d8fa4->m_pkActiveList == &g_pkBarterMenu_011d8fa4->m_kMerchantList ? 1 : -1) * iCount;
    g_thePlayer_011dea3c->PlayActorSound(
        g_pkSelectedItem_011d8fa8->FUN_0044ddc0(),
        g_pkBarterMenu_011d8fa4->m_pkActiveList == &g_pkBarterMenu_011d8fa4->m_kPlayerList, 0);
    if (pkTile->IsTraitNonZero(g_iTileIDEquipped_011d8fb4))
        g_pkBarterMenu_011d8fa4->DecrementEntryCount(iCount);
    else
        g_pkBarterMenu_011d8fa4->AddOrUpdateEntryCount(iCount);
    g_pkBarterMenu_011d8fa4->RebuildInventoryLists(g_pkSelectedItem_011d8fa8->FUN_0044ddc0());
    if (!g_pkBarterMenu_011d8fa4->m_kMerchantItems.FUN_008256d0() ||
        !g_pkBarterMenu_011d8fa4->m_kPlayerItems.FUN_008256d0())
    {
        char acBufferTmp[0x10];
        int iCaps_2 = TruncateFloatToInt(FUN_00406ce0(g_pkBarterMenu_011d8fa4->m_fBarterTotal));
        g_pkBarterMenu_011d8fa4->FUN_00726070()->FUN_00700320(g_iTileIDState_011d8fbc,
                                                              g_pkBarterMenu_011d8fa4->m_fBarterTotal > 0.0 ? 2 : 1);
        FUN_00406d00(acBufferTmp, 0x10, s_szIntFormat, FUN_0072fa60(MinInt(iCaps_2, g_pkBarterMenu_011d8fa4->unk90)));
        g_pkBarterMenu_011d8fa4->unk58->FUN_00a01350(g_iTileIDValue_011d8fb0, acBufferTmp, true);
        g_pkBarterMenu_011d8fa4->unk58->FUN_00700320(0xfa3, 1);
        if (g_pkBarterMenu_011d8fa4->m_fBarterTotal > 0.0 ||
            (g_pkBarterMenu_011d8fa4->m_fBarterTotal <= 0.0 &&
             g_pkBarterMenu_011d8fa4->m_iMerchantCaps >= -g_pkBarterMenu_011d8fa4->m_fBarterTotal))
        {
            g_pkBarterMenu_011d8fa4->unk5c->FUN_00700320(0xfaf, 1);
            if (g_pkBarterMenu_011d8fa4->m_fBarterTotal > 0.0 &&
                g_pkBarterMenu_011d8fa4->m_fBarterTotal > g_pkBarterMenu_011d8fa4->unk90)
                g_pkBarterMenu_011d8fa4->unk58->FUN_00a012d0(0xfa9, 64.0f, true);
            else
                g_pkBarterMenu_011d8fa4->unk58->FUN_00a012d0(0xfa9, 255.0f, true);
        }
        else
        {
            g_pkBarterMenu_011d8fa4->unk5c->FUN_00700320(0xfaf, 0);
            g_pkBarterMenu_011d8fa4->unk58->FUN_00a012d0(0xfa9, 64.0f, true);
        }
    }
    else
    {
        g_pkBarterMenu_011d8fa4->unk5c->FUN_00700320(0xfaf, 0);
        g_pkBarterMenu_011d8fa4->unk58->FUN_00700320(0xfa3, 0);
    }
}
}  // namespace fnv_0072f6f0

struct FC30Data
{
    int* GetValuePtr();
};

struct FC30Entry
{
    ~FC30Entry();

    FC30Data* GetData();
    int GetCount();
    void SetCount(int iCount);
};

struct FC30List
{
    int m_pHead;
    int m_pTail;

    void Remove(FC30Entry* const& pkEntry);
};

struct FC30State
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
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
};

extern void* g_FC30Key;

struct FC30Container
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
    int unk0A4;
    FC30State m_kState;
    FC30State* m_pkState;
    FC30List m_kListA;
    FC30List m_kListB;

    FC30Entry* FindEntry(FC30List* pkList, void* pKey);
    void DecrementEntryCount(int iCount);
};

// @fnv 0x0072fc30
void FC30Container::DecrementEntryCount(int iCount)
{
    int iValue;
    FC30List* pkListA = (m_pkState == &m_kState) ? &m_kListA : &m_kListB;
    FC30Entry* pkEntry = FindEntry(pkListA, g_FC30Key);
    iValue = pkEntry->GetData() ? *pkEntry->GetData()->GetValuePtr() : 0;
    if (pkEntry->GetCount() - iCount <= 0)
    {
        pkListA->Remove(pkEntry);
        delete pkEntry;
    }
    else
    {
        pkEntry->SetCount(pkEntry->GetCount() - iCount);
    }
}

struct LbTile
{
    float FUN_00a011b0(int m_uiSoundID);
    void FUN_00700320(int m_uiSoundID, int iValue);
    void FUN_00715c60(int m_uiSoundID, int iValue);
};
int __cdecl TraitNameToIDAdd(const char* pcName, int iDefault);

struct LbItem
{
    LbTile* m_pkTile;
    void* m_pPointer;
    bool m_bFiltered;
};

struct LbNode
{
    LbItem** FUN_006815c0();
    LbNode* FUN_00726070();
};

struct LbMenuBase
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual LbTile* GetTileAt(int iIndex, int i);
};

struct LbList : LbNode
{
    LbItem* m_pkItem;
    LbNode* m_pkNext;
};

static const char s_szNumFiltered[] = "_num_filtered";
extern const char g_szListBoxEnd[] = "";

struct ListBoxImpl : LbMenuBase, LbList
{
    LbTile* m_pkParentTile;
    LbTile* m_pkSelected;
    int unk14;
    int unk18;
    unsigned short m_usElementCount;
    float m_fScroll;

    void AccumulateTileHeight(LbTile* pkTile);
    void UpdateScrollPages();
    LbTile* FUN_007315b0();
    void FUN_0071a740();
    void ApplyFilter(bool(__cdecl* pfnFilter)(void* pkObject));
};

// Marks each item as filtered by pfnFilter, renumbers the visible tiles, updates the filtered count, and restores the selection.
// @fnv 0x00730bb0
void ListBoxImpl::ApplyFilter(bool(__cdecl* pfnFilter)(void* pkObject))
{
    int iFilteredCount = 0;
    int iSelectedIndex = -1;
    static int s_iNumFilteredID = TraitNameToIDAdd(s_szNumFiltered, -1);
    m_usElementCount = 0;
    m_fScroll = 0.0f;
    for (LbNode* pkNode = this; pkNode && *pkNode->FUN_006815c0(); pkNode = pkNode->FUN_00726070())
    {
        (*pkNode->FUN_006815c0())->m_bFiltered = pfnFilter && pfnFilter((*pkNode->FUN_006815c0())->m_pPointer) ? 1 : 0;
        if ((*pkNode->FUN_006815c0())->m_bFiltered)
        {
            if ((*pkNode->FUN_006815c0())->m_pkTile == m_pkSelected)
            {
                iSelectedIndex = (int)(*pkNode->FUN_006815c0())->m_pkTile->FUN_00a011b0(0xfac);
                m_pkSelected = 0;
            }
            (*pkNode->FUN_006815c0())->m_pkTile->FUN_00700320(0xfac, -1);
            iFilteredCount++;
        }
        else
        {
            if (iSelectedIndex >= 0 && m_usElementCount == iSelectedIndex)
                m_pkSelected = (*pkNode->FUN_006815c0())->m_pkTile;
            (*pkNode->FUN_006815c0())->m_pkTile->FUN_00700320(0xfac, m_usElementCount++);
            AccumulateTileHeight((*pkNode->FUN_006815c0())->m_pkTile);
        }
    }
    m_pkParentTile->FUN_00715c60(s_iNumFilteredID, iFilteredCount);
    UpdateScrollPages();
    if (!m_pkSelected && iSelectedIndex >= 0)
        m_pkSelected = GetTileAt(iSelectedIndex, 0);
    if (!m_pkSelected && iSelectedIndex >= 0)
        m_pkSelected = FUN_007315b0();
    FUN_0071a740();
}

class C72CEB0Menu
{
  public:
    C72CEB0Menu();
    virtual ~C72CEB0Menu();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class C72CEB0ListBox
{
  public:
    C72CEB0ListBox();
    ~C72CEB0ListBox();

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
};

class C72CEB0StringList
{
  public:
    C72CEB0StringList();
    ~C72CEB0StringList();

    void* m_pvHead;
    void* m_pvTail;
};

int __cdecl C72CEB0GetTraitID(const char* pcName);

extern const char g_ac72CEB0Trait0[];
extern const char g_ac72CEB0Trait1[];
extern const char g_ac72CEB0Trait2[];
extern const char g_ac72CEB0Trait3[];
extern const char g_ac72CEB0Trait4[];

extern int g_i72CEB0Trait0;
extern int g_i72CEB0Trait1;
extern int g_i72CEB0Trait2;
extern int g_i72CEB0Trait3;
extern int g_i72CEB0Trait4;
extern int g_i72CEB0Selected;

class FUN_0072ceb0 : public C72CEB0Menu
{
  public:
    FUN_0072ceb0();
    virtual ~FUN_0072ceb0();

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
    int m_i8C;
    int m_i90;
    float m_f94;
    float m_f98;
    int m_i9C;
    int m_iA0;
    int m_iA4;
    C72CEB0ListBox m_kFirstList;
    C72CEB0ListBox m_kSecondList;
    int m_i108;
    C72CEB0StringList m_kFirstStrings;
    C72CEB0StringList m_kSecondStrings;
    bool m_b11C;
};

// @fnv 0x0072ceb0
FUN_0072ceb0::FUN_0072ceb0()
{
    g_i72CEB0Trait0 = C72CEB0GetTraitID(g_ac72CEB0Trait0);
    g_i72CEB0Trait1 = C72CEB0GetTraitID(g_ac72CEB0Trait1);
    g_i72CEB0Trait2 = C72CEB0GetTraitID(g_ac72CEB0Trait2);
    g_i72CEB0Trait3 = C72CEB0GetTraitID(g_ac72CEB0Trait3);
    g_i72CEB0Trait4 = C72CEB0GetTraitID(g_ac72CEB0Trait4);
    g_i72CEB0Selected = 0;
    m_i108 = 0;
    m_i8C = 0;
    m_i90 = 0;
    m_f94 = 1.0f;
    m_f98 = 1.0f;
    m_b11C = false;
    m_i9C = 0;
    m_iA0 = 0;
    m_iA4 = 3;
}

struct ListObj;
struct NodeS;
struct PtrObj
{
    PtrObj* FUN_00559450();
    void** FUN_006815c0();
    void FUN_005ae3d0(void** pp);
};
struct EntryObj
{
    ~EntryObj();
    void* FUN_0044ddc0();
    const char* GetTargetFullName();
    int FUN_004459e0(int a);
    PtrObj* FUN_00559450();
    void* FUN_00726070();
};
struct NodeS
{
    void* m_00;
    void* m_04;
    NodeS* FUN_00726070();
    EntryObj** FUN_006815c0();
};
struct ListObj
{
    virtual void vtbl000();
    virtual int PredHead();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void Virt20(void* fn);
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void FUN_0071a200(int a);
    int FUN_0071a320(void* e, const char* s, int a, int b);
    void PopulateInventoryList(void* a, void* fn, int b, int c, int d, int e);
    void FUN_007314c0(void* fn, int a, int b);
    void ApplyFilter(void* fn);
    unsigned int FUN_0071ae60();
    void UpdateCurrentValueTile(int a);
    void FUN_007312e0();
    void* CallVirtualZero(int a, int b);
};
struct LocalList
{
    void* m_00;
    void* m_04;
    LocalList();
    ~LocalList();
    void FUN_00470470();
};
struct NewObj
{
    void* m_00;
    int m_04;
    void* m_08;
    NewObj(void* a, int b);
    PtrObj* FUN_00559450();
    const char* GetTargetFullName();
};
struct DataSource
{
    void FindEntriesByType(int arg, LocalList* out);
};
struct DataHandler
{
    void* FUN_00740960();
    void UpdateInventoryForReference(void* a);
};
struct TileLike
{
    void FUN_00700320(int a, int b);
};
extern DataHandler* g_dataHandler;
struct PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
extern int DAT_011d8fb4;
void* __cdecl FUN_004bf220(void* a);
class InventoryEntry;
bool __cdecl IsFilteredFromBarter(EntryObj* e);
unsigned char __cdecl FUN_004b71d0();
void* __cdecl FUN_004b7210();
void __cdecl AddHeadImpl(void* list, void** pp);
void __cdecl UpdateBarterItemTile();
void __cdecl CompareF070Entries();
struct IMObj
{
    void FUN_00715860(void* a);
};

struct Self72
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void Virt0c(int a, int b);
    virtual void Virt10(int a, int b);
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
    void* m_80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int m_a4;
    ListObj m_a8;
    ListObj m_d8;
    ListObj* m_108;
    NodeS m_10c;
    NodeS m_114;
    void FUN_0072db60();
    void __thiscall RebuildInventoryLists(int arg);
};

// Rebuilds the m_a8/m_d8 lists from the player and data handler for the given form, then selects and activates m_108 and calls FUN_0072db60.
// @fnv 0x0072dc30
void __thiscall Self72::RebuildInventoryLists(int arg)
{
    long i = 0;
    if (m_108 != 0)
    {
        if (m_108->PredHead())
        {
            m_108->FUN_007312e0();
        }
    }
    if (arg != 0)
    {
        LocalList b;
        void* n;
        n = FUN_004bf220((void*)g_thePlayer);
        void* res = g_dataHandler->FUN_00740960();
        if (n != 0)
        {
            ((DataSource*)n)->FindEntriesByType(arg, &b);
            m_a8.FUN_0071a200(arg);
            NodeS* kZero = (NodeS*)&b;
            for (; kZero != 0 && *kZero->FUN_006815c0() != 0; kZero = kZero->FUN_00726070())
            {
                if (!(bool)FUN_0072e570((InventoryEntry*)*kZero->FUN_006815c0()))
                {
                    m_a8.FUN_0071a320(*kZero->FUN_006815c0(), (*kZero->FUN_006815c0())->GetTargetFullName(), 0, 0);
                }
                else
                {
                    delete *kZero->FUN_006815c0();
                }
            }
            b.FUN_00470470();
        }
        if (res != 0)
        {
            ((DataSource*)res)->FindEntriesByType(arg, &b);
            m_d8.FUN_0071a200(arg);
            NodeS* kZero;
            kZero = (NodeS*)&b;
            for (; kZero != 0 && *kZero->FUN_006815c0() != 0; kZero = kZero->FUN_00726070())
            {
                if (!(bool)IsFilteredFromBarter(*kZero->FUN_006815c0()))
                {
                    m_d8.FUN_0071a320(*kZero->FUN_006815c0(), (*kZero->FUN_006815c0())->GetTargetFullName(), 0, 0);
                }
                else
                {
                    delete *kZero->FUN_006815c0();
                }
            }
            b.FUN_00470470();
        }
    }
    else
    {
        g_dataHandler->UpdateInventoryForReference(m_80);
        m_a8.PopulateInventoryList((void*)g_thePlayer, (void*)::FUN_0072e570, 0, 0, 0, 0);
        m_d8.PopulateInventoryList(m_80, (void*)IsFilteredFromBarter, 0, 0, 0, 1);
    }
    {
        NodeS* kZero;
        kZero = &m_10c;
        for (; kZero != 0 && *kZero->FUN_006815c0() != 0; kZero = kZero->FUN_00726070())
        {
            if (arg == 0 || (*kZero->FUN_006815c0())->FUN_0044ddc0() == (void*)arg)
            {
                int tmp;
                NewObj* r =
                    new NewObj((*kZero->FUN_006815c0())->FUN_0044ddc0(), (int)(*kZero->FUN_006815c0())->FUN_00726070());
                void* _tempExtra;
                _tempExtra = (*kZero->FUN_006815c0())->FUN_00559450()
                                 ? *(void**)(*kZero->FUN_006815c0())->FUN_00559450()->FUN_006815c0()
                                 : 0;
                tmp = 0;
                if (0 != _tempExtra)
                {
                    r->FUN_00559450()->FUN_005ae3d0(&_tempExtra);
                }
                tmp = m_a8.FUN_0071a320(r, r->GetTargetFullName(), 0, 0);
                ((TileLike*)tmp)->FUN_00700320(DAT_011d8fb4, 1);
            }
        }
    }
    {
        NodeS* kZero;
        kZero = &m_114;
        for (; kZero != 0 && *kZero->FUN_006815c0() != 0; kZero = kZero->FUN_00726070())
        {
            if (arg == 0 || (*kZero->FUN_006815c0())->FUN_0044ddc0() == (void*)arg)
            {
                long tmp;
                NewObj* r;
                void* _tempExtra;
                r = new NewObj((*kZero->FUN_006815c0())->FUN_0044ddc0(), (int)(*kZero->FUN_006815c0())->FUN_00726070());
                _tempExtra = (*kZero->FUN_006815c0())->FUN_00559450()
                                 ? *(void**)(*kZero->FUN_006815c0())->FUN_00559450()->FUN_006815c0()
                                 : 0;
                tmp = 0;
                if (_tempExtra != 0)
                {
                    r->FUN_00559450()->FUN_005ae3d0(&_tempExtra);
                }
                tmp = m_d8.FUN_0071a320(r, r->GetTargetFullName(), 0, 0);
                ((TileLike*)tmp)->FUN_00700320(DAT_011d8fb4, 1);
            }
        }
    }
    m_a8.FUN_007314c0((void*)FUN_0072eac0, 0, 0x7fffffff);
    m_a8.FUN_007314c0((void*)UpdateBarterItemTile, 0, 0x7fffffff);
    m_a8.ApplyFilter((void*)FUN_007304b0);
    m_a8.Virt20((void*)CompareF070Entries);
    m_d8.FUN_007314c0((void*)UpdateBarterItemTile, 0, 0x7fffffff);
    m_d8.ApplyFilter((void*)FUN_007304b0);
    m_d8.Virt20((void*)CompareF070Entries);
    if (0 == m_108)
    {
        if (FUN_004b71d0())
        {
            m_108 = &m_d8;
        }
    }
    if (0 != m_108)
    {
        if (m_108->FUN_0071ae60() > 0)
        {
            m_108->UpdateCurrentValueTile(1);
        }
        else
        {
            m_a4 = -1;
            Virt0c((m_108 == &m_a8) ? 4 : 9, 0);
            m_a4 = 3;
            if (m_108->FUN_0071ae60() > 0)
            {
                m_108->UpdateCurrentValueTile(1);
            }
            else
            {
                Virt10((m_108 == &m_a8) ? 1 : 0, 0);
                if (FUN_004b71d0())
                {
                    ((IMObj*)FUN_004b7210())->FUN_00715860(m_108->CallVirtualZero(0xfc3, 1));
                }
            }
        }
    }
    FUN_0072db60();
}

// List sort comparator: entries whose tile has the highlight trait come first, then order by tile text.

int __cdecl _mbscmp(const unsigned char* pucA, const unsigned char* pucB);

extern int g_iF070HighlightTrait;

class F070Tile
{
  public:
    bool GetBool(int m_iValueId);
    const char* GetString(int m_iValueId);
};

struct F070Entry
{
    F070Tile* m_pkTile;
    void* m_pvItem;
};

// Compares two entries by the highlight trait first, then by the string from trait 0xfc4, returning -1, 1 or the string comparison result.
// @fnv 0x0072f070
int CompareF070Entries(F070Entry* pkA, F070Entry* pkB)
{
    void* pvItemA = pkA->m_pvItem;
    void* pvDataB = pkB->m_pvItem;
    int iResult = 0;
    bool bHighlightA = pkA->m_pkTile->GetBool(g_iF070HighlightTrait);
    bool bB = pkB->m_pkTile->GetBool(g_iF070HighlightTrait);
    if (bHighlightA && !bB)
        iResult = -1;
    else if (!bHighlightA && bB)
        iResult = 1;
    else
        iResult = _mbscmp((const unsigned char*)pkA->m_pkTile->GetString(0xfc4),
                          (const unsigned char*)pkB->m_pkTile->GetString(0xfc4));
    return iResult;
}

namespace fnv_0072fd10 {
struct ExtraDataList;
struct TESObjectREFR;
struct InventoryStackRecord;

struct ExtraDataListNode
{
    ExtraDataList** FUN_006815c0();
};

struct InventoryStackRecord
{
    ExtraDataListNode* m_extendData;
    int m_countDelta;
    TESBoundObject* m_type;

    InventoryStackRecord(TESBoundObject* apType, int aiCount);
    ~InventoryStackRecord();
    ExtraDataListNode* FUN_00559450();
    int FUN_00726070();
    TESBoundObject* FUN_0044ddc0();
};

struct ItemChangeNode
{
    InventoryStackRecord* m_item;
    ItemChangeNode* m_next;
    InventoryStackRecord** FUN_006815c0();
    ItemChangeNode* FUN_00726070();
    void FUN_00470470();
};

struct InventoryChangesStandIn
{
    static InventoryChangesStandIn* GetOrAddInventoryChanges(TESObjectREFR* apRef);
    int GetObjectCount(TESBoundObject* apForm);
    void FUN_004cb4b0(TESObjectREFR* apRef, int aiCount, TESObjectREFR* apTarget);
};

struct ProcessStandIn
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
    virtual InventoryStackRecord* GetActiveWeapon();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void SetCurrentArmor(InventoryStackRecord* apWeapon);
};

struct ActorStandIn
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
    virtual void AddItem(TESBoundObject* apItem, ExtraDataList* apExtraList, int aiCount, int a3, int a4,
                         TESObjectREFR* apOther, int a6, int a7, int a8, int a9);
    ProcessStandIn* GetProcess();
};

extern ActorStandIn* g_player_011dea3c;

struct TESQuestStageList
{
    TESObjectREFR* FUN_00421400();
};

struct TESObjectREFR
{
    TESQuestStageList* FUN_005d43c0();
};

struct ItemTransferManager
{
    void ProcessInventoryRecords(InventoryStackRecord* apItem, int aiCount, TESObjectREFR* apRef);
};
extern ItemTransferManager* g_transferMgr_011c3f2c;

bool __cdecl FUN_005ac750(TESObjectREFR* apRef, ExtraDataList* apExtraList, unsigned int auiFlags);
float __cdecl FUN_00406ce0(float afValue);
int __cdecl TruncateFloatToInt(float afValue);
extern "C" const char* __cdecl FUN_00ec7d40(int aiValue);
void __cdecl FUN_004d5e10(int aiID, const char* apText);
extern "C" TESBoundObject* __cdecl LookupFormByID(unsigned int auiFormID);
int __cdecl MinInt(int aiValue, int aiValue2);

struct SoundPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    ~SoundPlaybackHandle();
    bool Play();
};

struct BSAudioStandIn
{
    static BSAudioStandIn* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* apName, unsigned int auiFlags, int aiUnk);
};

struct BarterMenuGlobals
{
    char pad00[0x58];
    Tile* unk58;
    Tile* unk5c;
    char pad60[0x24];
    float unk84;
};

struct BarterMenuImpl
{
    char pad00[0x80];
    TESObjectREFR* m_merchant;
    float m_barterTotal;
    char pad88[8];
    int unk90;
    char pad94[0x10c - 0x94];
    ItemChangeNode m_merchantItems;
    ItemChangeNode m_playerItems;
    unsigned char unk11c;

    void CompleteBarterTransaction();
};

// Transfers merchant and player barter items, adjusts caps based on m_barterTotal, plays a sound, resets totals and clears the equipped weapon if it was sold.
// @fnv 0x0072fd10
void BarterMenuImpl::CompleteBarterTransaction()
{
    TESObjectREFR* pTarget3 =
        m_merchant->FUN_005d43c0()->FUN_00421400() ? m_merchant->FUN_005d43c0()->FUN_00421400() : m_merchant;
    InventoryStackRecord* pWeapon3 = g_player_011dea3c->GetProcess()->GetActiveWeapon();

    for (ItemChangeNode* pNode6 = &m_merchantItems; pNode6 && *pNode6->FUN_006815c0(); pNode6 = pNode6->FUN_00726070())
    {
        InventoryStackRecord* pItem = *pNode6->FUN_006815c0();
        ExtraDataList* pExtraList = pItem->FUN_00559450() ? *pItem->FUN_00559450()->FUN_006815c0() : 0;
        if (pExtraList)
            FUN_005ac750(m_merchant, pExtraList, 0x4000);
        g_transferMgr_011c3f2c->ProcessInventoryRecords(pItem, pItem->FUN_00726070(), m_merchant);
        delete pItem;
    }

    for (ItemChangeNode* pNode3 = &m_playerItems; pNode3 && *pNode3->FUN_006815c0(); pNode3 = pNode3->FUN_00726070())
    {
        InventoryStackRecord* pItem3 = *pNode3->FUN_006815c0();
        ExtraDataList* pExtraList5 = pItem3->FUN_00559450() ? *pItem3->FUN_00559450()->FUN_006815c0() : 0;
        if (pExtraList5)
            FUN_005ac750((TESObjectREFR*)g_player_011dea3c, pExtraList5, 0x4000);
        g_player_011dea3c->AddItem(pItem3->FUN_0044ddc0(), pExtraList5, pItem3->FUN_00726070(), 0, 0, pTarget3, 0, 0, 1,
                                   0);
        delete pItem3;
    }

    ((BarterMenuGlobals*)DAT_011d8fa4)->unk5c->SetInt(0xfaf, 0);
    ((BarterMenuGlobals*)DAT_011d8fa4)->unk58->SetInt(0xfa3, 0);

    InventoryChangesStandIn* pChanges = 0;
    int iAmount5 = TruncateFloatToInt(FUN_00406ce0(((BarterMenuGlobals*)DAT_011d8fa4)->unk84));
    FUN_004d5e10(0x27, FUN_00ec7d40(iAmount5));

    if (m_barterTotal > 0.0)
    {
        InventoryStackRecord kCaps9(LookupFormByID(0xf), 0);
        pChanges = InventoryChangesStandIn::GetOrAddInventoryChanges(pTarget3);
        if (pChanges)
            g_transferMgr_011c3f2c->ProcessInventoryRecords(&kCaps9, MinInt(iAmount5, unk90), m_merchant);
        BSAudioStandIn::GetSingleton()->GetSoundHandleByEditorID("ITMBottlecapsUp", 0x101, 0).Play();
    }
    else if (m_barterTotal < 0.0)
    {
        pChanges = InventoryChangesStandIn::GetOrAddInventoryChanges((TESObjectREFR*)g_player_011dea3c);
        if (pChanges)
            pChanges->FUN_004cb4b0((TESObjectREFR*)g_player_011dea3c, -iAmount5, pTarget3);
        BSAudioStandIn::GetSingleton()->GetSoundHandleByEditorID("ITMBottlecapsDown", 0x101, 0).Play();
    }

    m_barterTotal = 0.0f;
    m_merchantItems.FUN_00470470();
    m_playerItems.FUN_00470470();
    unk11c = 1;

    if (pWeapon3 && !InventoryChangesStandIn::GetOrAddInventoryChanges((TESObjectREFR*)g_player_011dea3c)
                         ->GetObjectCount(pWeapon3->FUN_0044ddc0()))
        g_player_011dea3c->GetProcess()->SetCurrentArmor(0);
}
}  // namespace fnv_0072fd10

extern double DAT_01012060;
void __cdecl UpdateAnimationTileFade(int a0, int a1, int a2, S_0072e370_Item* a3, int a4);

struct TESBoundObjectExt
{
    double FUN_004be180();
    double FUN_004be060();
};

struct FUN_007306d0_cls
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
    int unk54;
    int unk58;
    int unk5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;

    void FUN_007306d0();
};

// @fnv 0x007306d0
void FUN_007306d0_cls::FUN_007306d0()
{
    if (DAT_011d8fc0 == 1)
    {
        FUN_00730690(true);
    }
    if (DAT_0119fdb0 != 0)
    {
        if (DAT_011d8fa8 != 0)
        {
            if (((InventoryEntry*)DAT_011d8fa8)->FUN_0044ddc0()->FUN_00401170() == 0x28)
            {
                UpdateAnimationTileFade(m_60, m_64, m_68, DAT_011d8fa8, 0);
                return;
            }
        }
        if (DAT_011d8fa8 != 0)
        {
            if (((InventoryEntry*)DAT_011d8fa8)->FUN_0044ddc0()->FUN_00401170() == 0x18)
            {

                UpdateAnimationTileFade(
                    (DAT_011d8fa8 != 0 &&
                     DAT_01012060 !=
                         ((TESBoundObjectExt*)((InventoryEntry*)DAT_011d8fa8)->FUN_0044ddc0())->FUN_004be060())
                        ? m_6c
                        : 0,
                    (DAT_011d8fa8 != 0 &&
                     DAT_01012060 !=
                         ((TESBoundObjectExt*)((InventoryEntry*)DAT_011d8fa8)->FUN_0044ddc0())->FUN_004be180())
                        ? m_70
                        : 0,
                    0, DAT_011d8fa8, 0);
            }
        }
    }
}

struct Tile7313
{
    float FUN_00a011b0(int m_uiSoundID);
};
struct Menu7313
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void SetValue7313(int iValue, Tile7313* pTile);
};
struct Holder7313
{
    Holder7313* FUN_00a03d40();
    Menu7313* FUN_00a03c90();
};
struct Traits7313
{
    void FUN_00a012d0(int m_uiSoundID, float fValue, bool bFlag);
    void SetTraitAndReset(int m_uiSoundID, float fValue);
};
struct IM7313
{
    void FUN_00715860(Tile7313* pTile, int m_uiSoundID, bool bFlag);
};
struct List7313
{
    virtual void SetSelected7313(Tile7313* pTile);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual Tile7313* GetTile7313(unsigned int uiIndex);
    void* pad[2];
    Holder7313* m_0c;
    void* padCur;
    Traits7313* m_14;
    void* kad[3];
    float m_24;
    float m_28;
    unsigned int FUN_0071ae60(int a);
    void UpdateCurrentValueTile(bool abFlag);
};

// @fnv 0x00731360
void List7313::UpdateCurrentValueTile(bool abFlag)
{
    Tile7313* pTile = 0;
    if (m_0c && m_14)
    {
        m_14->FUN_00a012d0(TraitNameToID("_current_value"), m_28, false);
        m_14->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
        pTile = GetTile7313((unsigned int)FUN_0040ebd0(m_24, (float)(FUN_0071ae60(0) - 1.0)));
        ((IM7313*)FUN_004b7210())->FUN_00715860(pTile, 0xfc3, abFlag);
        SetSelected7313(pTile);
        if (!FUN_004b71d0())
        {
            if (pTile)
                m_0c->FUN_00a03d40()->FUN_00a03c90()->SetValue7313((int)pTile->FUN_00a011b0(0xfaa), pTile);
            SetSelected7313(0);
        }
    }
}

struct MerchantServices
{
    bool HasFlags(int mask);
};
struct MerchantBase
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
    MerchantServices services;
};
struct MerchantActor : OwnActor
{
    MerchantBase* FUN_004181e0();
};
int __cdecl FUN_0048e8a0(TESBoundObject*);
int __cdecl FUN_00479430(TESBoundObject*);

// Checks if an inventory entry should be hidden from the barter menu based on merchant service flags and form validity.
// @fnv 0x0072e6c0
bool __cdecl IsFilteredFromBarter(EntryObj* apEntry)
{
    MerchantActor* merchant4;
    bool filteredVal = false;
    TESBoundObject* formTmp;
    TESFullName* name;
    TESObjectWEAP* weapon_;
    TESBipedModelForm* bipedVal;
    TESObjectARMO* armor;
    merchant4 =
        (((OwnBarterMenu*)DAT_011d8fa4)->m_pkMerchant && ((OwnBarterMenu*)DAT_011d8fa4)->m_pkMerchant->IsActor())
            ? (MerchantActor*)((OwnBarterMenu*)DAT_011d8fa4)->m_pkMerchant
            : 0;
    formTmp = apEntry ? ((InventoryEntry*)apEntry)->FUN_0044ddc0() : 0;
    if (merchant4)
    {
        switch (((InventoryEntry*)apEntry)->FUN_0044ddc0()->FUN_00401170())
        {
        case 40:
        case 41:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(1) == false;
            break;
        case 24:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(2) == false;
            break;
        case 31:
        case 50:
        case 103:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x400) == false;
            break;
        case 46:
            filteredVal = true;
            break;
        case 49:
            filteredVal = (formTmp && FUN_0048e8a0(formTmp) > 0)
                              ? (merchant4->FUN_004181e0()->services.HasFlags(0x400) == false)
                              : true;
            break;
        case 25:
            filteredVal = merchant4->FUN_004181e0()->services.HasFlags(8) == false;
            break;
        case 47:
            switch (FUN_00479430(((InventoryEntry*)apEntry)->FUN_0044ddc0()))
            {
            case 10:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x20) == false;
                break;
            case 11:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x40) == false;
                break;
            case 12:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(0x10) == false;
                break;
            case 13:
                filteredVal = merchant4->FUN_004181e0()->services.HasFlags(4) == false;
                break;
            }
            break;
        }
    }
    bipedVal = TESBipedModelForm::GetFormAsBipedModel(formTmp);
    name = dynamic_cast<TESFullName*>(formTmp);
    armor = ((InventoryEntry*)apEntry)->FUN_0044ddc0()->FUN_00401170() == 40
                ? (TESObjectARMO*)((InventoryEntry*)apEntry)->FUN_0044ddc0()
                : 0;
    weapon_ = ((InventoryEntry*)apEntry)->FUN_0044ddc0()->FUN_00401170() == 41
                  ? (TESObjectWEAP*)((InventoryEntry*)apEntry)->FUN_0044ddc0()
                  : 0;
    if (!formTmp || (bipedVal && !bipedVal->FUN_00480d90()) || FUN_00481f10(formTmp) || !name ||
        !name->GetModelLength() || (armor && !armor->IsFlag80Clear()) || (weapon_ && !weapon_->FUN_004c94d0()))
    {
        filteredVal = true;
    }
    return filteredVal;
}

struct Fr7304Form
{
    int FUN_00401170();
};
struct Fr7304Entry
{
    Fr7304Form* FUN_0044ddc0();
    int FUN_00726070();
};
struct Fr7304Tile
{
    float FUN_00a011b0(int m_uiSoundID);
};
struct Fr7304List
{
    Fr7304Tile* FindItemData(Fr7304Entry** ppkEntry);
};
struct Fr7304Menu
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
    Fr7304List kListA8;
    char cA9;
    char cAA;
    char cAB;
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
    Fr7304List kListD8;
};

// Evaluates the item type against a filter and, when a tile exists, combines the result with a comparison to _num_bartered.
// @fnv 0x007304b0
bool __cdecl FUN_007304b0(Fr7304Entry* pkItem)
{
    bool bResult = false;
    int iType = pkItem->FUN_0044ddc0()->FUN_00401170();
    Fr7304Tile* pkTile = ((Fr7304Menu*)DAT_011d8fa4)->kListA8.FindItemData(&pkItem);
    int iFilter_2 = 0;
    if (pkTile)
    {
        iFilter_2 = ((Fr7304Menu*)DAT_011d8fa4)->unk9C;
    }
    else
    {
        pkTile = ((Fr7304Menu*)DAT_011d8fa4)->kListD8.FindItemData(&pkItem);
        iFilter_2 = ((Fr7304Menu*)DAT_011d8fa4)->unkA0;
    }
    switch (iFilter_2)
    {
        break;
    case 1:
        bResult = iType != 0x28;
        break;
    case 2:
        bResult = iType != 0x18 && iType != 0x1a;
        break;
    case 3:
        bResult = iType != 0x1d && iType != 0x2f && iType != 0x19;
        break;
    case 4:
        bResult = iType == 0x28 || iType == 0x18 || iType == 0x1a || iType == 0x1d || iType == 0x2f || iType == 0x29 ||
                  iType == 0x19 || iType == 0x6c || iType == 0x73 || iType == 0x74;
        break;
    case 5:
        bResult = iType != 0x29;
        break;
    }
    if (pkTile)
    {
        bResult =
            bResult || (double)pkItem->FUN_00726070() - pkTile->FUN_00a011b0(TraitNameToID(s_szNumBartered)) <= 0.0;
    }
    return bResult;
}
