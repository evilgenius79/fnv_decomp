
// src/fallout/interface/menus/inventorymenu_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00782190: the skeleton of src/fallout/interface/menus/inventorymenu.cpp
// with declarations corrected to what the original code does (inventorymenu_decls.h: InventoryMenu += bool FUN_00782190(int input, int unused);; inventorymenu_decls.h: Tile += float FUN_00a011b0(unsigned int id);). Move the function to its real unit once
// that unit declares it this way.

#include "inventorymenu_decls_decl_inventorymenu.h"
static const int kGetClassValue = 1002;
// m_pTiles holds kNumTiles (23) entries, so out-of-range tile ids are ignored.
static const int kNumTiles = 23;
struct StatsMenu
{
    static StatsMenu* ms_pInventoryMenu;
    unsigned char m_bHealingMode;  // +0x2a0
    void __thiscall RefreshHealingOptions();
};
void __cdecl FUN_00704390();
struct FUN_00780be0_shell
{
    unsigned char m_0x00;  // +0x00
    unsigned char m_0x01;  // +0x01
    unsigned char m_0x02;  // +0x02
    unsigned char m_0x03;  // +0x03
    unsigned char m_0x04;  // +0x04
    unsigned char m_0x05;  // +0x05
    unsigned char m_0x06;  // +0x06
    unsigned char m_0x07;  // +0x07
    unsigned char m_0x08;  // +0x08
    unsigned char m_0x09;  // +0x09
    unsigned char m_0x0a;  // +0x0a
    unsigned char m_0x0b;  // +0x0b
    unsigned char m_0x0c;  // +0x0c
    unsigned char m_0x0d;  // +0x0d
    unsigned char m_0x0e;  // +0x0e
    unsigned char m_0x0f;  // +0x0f
    unsigned char m_0x10;  // +0x10
    unsigned char m_0x11;  // +0x11
    unsigned char m_0x12;  // +0x12
    unsigned char m_0x13;  // +0x13
    void __thiscall SetByte13(unsigned char value);
};
struct FUN_0077fb50_shell
{
    void __thiscall FUN_0077fb80();
    void* __thiscall Destroy(unsigned int flags);
};
extern double _gModifierZero;
struct TGF
{
    float GetFloat(int) const;
};
void __cdecl FUN_00780c00(Tile* pTile);
bool __cdecl _FUN_004b71d0();
int __cdecl FUN_007023c0();
struct FUN_00781b10_shell
{
    void __thiscall ClearActionPointSource();
};
struct FUN_00781620_shell : public InventoryMenu
{
    void __thiscall FUN_00781620(int aiID, Tile* apTarget);
};
struct ProxyPipboy
{
    void __thiscall SetValue(int, bool);
};
struct ProxyMgr
{
    ProxyPipboy* __thiscall GetPipboyManager();
};
void FUN_00782470(bool a1);
unsigned char FUN_007824b0();
unsigned int __fastcall FUN_0044ddc0(void*);
unsigned char __cdecl IsNotFormType2E(void* a1);
struct FUN_007832e0_class
{
    void FUN_007832e0(float, float);
};
struct FUN_00726070_shell
{
    Tile* FUN_00726070();
};
void __cdecl FUN_007800c0();
struct FUN_004bddd0_t
{
    bool __thiscall FUN_004bddd0(bool);
};
struct FUN_00781860_shell
{
    bool __thiscall FUN_00781860(InventoryStackRecord*);
};
struct FUN_00781680_shell : public InventoryMenu
{
    void __thiscall FUN_00781680();
};
struct GlobalObject_0040c150 : public InventoryMenuSetting
{
};
extern InventoryMenuSetting* DAT_011d5178;
extern GlobalObject_0040c150 g_011d3cdc;
extern GlobalObject_0040c150 g_011d460c;
extern GlobalObject_0040c150 g_011d478c;
struct FUN_007823d0_listbox
{
    virtual void FUN_007823d0_first() = 0;
    virtual int FUN_007823d0_second() = 0;
};
struct FUN_007823d0_shell : public InventoryMenu
{
    bool __thiscall HandleInventoryButton(int aiButton, float afValue);
};
struct XExtra
{
    short __thiscall FUN_00418770();
};
struct ExtraDataList : XExtra
{
};
struct GO
{
    operator unsigned int() const;
};
struct Ref006815c0
{
    void* __thiscall _ref_006815c0();
};
struct NiPoint3
{
    int x;
    int y;
    int z;
};
struct PlayerCharacterShell
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void DropInventoryObject(TESBoundObject*, ExtraDataList*, int, NiPoint3*, bool) = 0;
    void __thiscall FUN_009614b0(TESBoundObject*, NiPoint3*, int, int);
};
extern PlayerCharacterShell* _g_thePlayer;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
void __cdecl DropInventoryItem(int aiAmountChosen);
struct MenuBase_0077fb80
{
    virtual ~MenuBase_0077fb80();
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
struct ListBox_0077fb80
{
    ~ListBox_0077fb80();
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
struct HotKeys_0077fb80
{
    ~HotKeys_0077fb80();
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
};
struct List_0077fb80
{
    ~List_0077fb80();
    int unk00;
    int unk04;
};
extern int DAT_011d9ea4;
class FUN_0077fb80_cls : public MenuBase_0077fb80
{
  public:
    virtual ~FUN_0077fb80_cls();
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
    int m_iCurrentTab;
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
    ListBox_0077fb80 m_b8;
    HotKeys_0077fb80 m_e8;
    List_0077fb80 m_11c;
};
extern int DAT_011d9eb8;
class FUN_0077ffd0_menu
{
  public:
    Tile* FUN_00726070(int);
};
class FUN_0077ffd0_obj
{
  public:
    bool IsTraitNonZero();
    void FUN_00a011b0();
};
class FUN_0077ffd0_list
{
  public:
    void* FUN_00825c00(void*);
};
class FUN_0077ffd0_lbx
{
  public:
    virtual void vfn_00();
    virtual Tile* vfn_04(int);
};
void* __cdecl TraitNameToID(const char* s);
int __cdecl FUN_00ec62c0();
void __cdecl UpdateCurrentValue();
struct InputInterface
{
    virtual int Reserved0();
    virtual int Reserved1();
    virtual int GetFirstValue(int index);
    virtual int Reserved3();
    virtual int Reserved4();
    virtual int Reserved5();
    virtual int Reserved6();
    virtual int GetSecondValue(int index);
};
extern char* DAT_011dea3c;
bool __cdecl FUN_00780f70();
namespace InventorySelection {
struct Item;
struct Form;
struct Tile
{
    float FUN_00a011b0();
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, bool);
    const char* FUN_00a011f0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00a07530(int);
};
struct TileRef
{
    Tile** FUN_0073ac90();
};
struct TileHolder
{
    unsigned int unk0;
    TileRef tile;
};
struct List
{
    virtual void slot0();
    virtual Tile* Value(int);
    Item* FUN_007a1910();
};
struct Entry
{
    bool FUN_00701740();
};
struct Form
{
    int FUN_00401170();
    void* GetUnk15C();
    int GetField1BC();
};
struct Item
{
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(int);
    const char* GetIconFilename(int);
};
struct Player
{
    bool FUN_00967b70(Item*);
};
struct Setting
{
    float* FUN_00403e20();
    const char* FUN_00403df0();
};
struct Camera
{
    void FUN_007f8610(int, float, float, bool);
};
struct Interface
{
    Camera* FUN_00704370();
};
Interface* FUN_004b7210();
extern Setting DAT_011db2f0, DAT_011db358, DAT_011d3dcc, DAT_011d1f2c, DAT_011d33f0;
extern Setting* DAT_011d5168;
extern int DAT_011d9f34, DAT_011d9ebc;
extern Item* DAT_011d9ea8;
extern Player* DAT_011dea3c;
extern float DAT_0102f0f8, DAT_0101b268, DAT_01050280, DAT_01072e3c, DAT_01073af0, DAT_0104f754;
extern double DAT_01073ae8, DAT_01073ae0;
extern const char DAT_01020764[], DAT_0106eb24[], DAT_01073aac[];
void FUN_00707e30(Item*, Tile*);
const char* GetWeaponSkillIconPath(void*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
int FUN_00408b20(const char*, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
unsigned int FUN_0044a670(const char*);
void* FUN_00479430(Form*);
const char* GetMenuIconName(void*);
void FUN_00406d50(char*, unsigned int, const char*);
struct Menu
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    TileHolder* icon;
    Tile* button;
    unsigned int unk44;
    Tile* label;
    unsigned int unk4c;
    unsigned int unk50;
    Tile* description;
    Tile* stats;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    Tile* ammoLabel;
    unsigned int unk7c;
    Tile* ammoCount;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    List list;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    Entry entry;
    Tile* FUN_00726070();
    void FUN_00781680();
    void ClearActionPointSource();
    void UpdateItemDisplay(int, Tile*);
};
// @fnv 0x00780ff0
void Menu::UpdateItemDisplay(int action, Tile* changed)
{
    if (action == 29)
    {
        DAT_011d9ea8 = list.FUN_007a1910();
        if (DAT_011d9ea8)
        {
            int selectedSlot11 = (int)list.Value(0xfac)->FUN_00a011b0();
            if (DAT_011d9f34 != selectedSlot11)
            {
                FUN_004b7210()->FUN_00704370()->FUN_007f8610(
                    0, DAT_011d9f34 < selectedSlot11 ? *DAT_011db2f0.FUN_00403e20() : -*DAT_011db2f0.FUN_00403e20(),
                    *DAT_011db358.FUN_00403e20(), 1);
                DAT_011d9f34 = selectedSlot11;
            }
            float threshold = DAT_0102f0f8;
            if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 24)
                threshold = DAT_0101b268;
            if (DAT_011d9ea8->FUN_004bcdb0(1) >= threshold)
                label->FUN_00a01350(0xfc4, DAT_011d3dcc.FUN_00403df0(), 1);
            else
                label->FUN_00a01350(0xfc4, DAT_011d1f2c.FUN_00403df0(), 1);
            FUN_00707e30(DAT_011d9ea8, stats);
            stats->FUN_00700320(0xfa3, 1);
            FUN_00726070()->FUN_00700320(DAT_011d9ebc, DAT_011dea3c->FUN_00967b70(DAT_011d9ea8));
            description->FUN_00a01350(0xfcc, DAT_011d9ea8->GetIconFilename(0), 1);
            Form* ammo = 0;
            if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                ammo = DAT_011d9ea8->FUN_0044ddc0();
                ammoLabel->FUN_00a01350(0xfcc, GetWeaponSkillIconPath(ammo->GetUnk15C()), 1);
                char countText[128];
                FUN_00406d00(countText, 128, DAT_01020764, ammo->GetField1BC());
                if (ammoCount)
                    ammoCount->FUN_00a01350(0xfc4, countText, 1);
            }
            if (!FUN_00408b20(description->FUN_00a011f0(0xfcc), DAT_011d33f0.FUN_00403df0()))
            {
                description->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                description->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                description->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            else if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 41)
            {
                float heightSlot1 = DAT_01073af0;
                float width = DAT_0104f754;
                description->FUN_00a012d0(0xfa1, heightSlot1 + DAT_01073ae8, 1);
                description->FUN_00a012d0(0xfb1, width + DAT_01073ae0, 1);
                description->FUN_00a012d0(0xfb0, width + DAT_01073ae0, 1);
            }
            else
            {
                description->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                description->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                description->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            description->FUN_00a07530(17);
            char path[260];
            FUN_00406d30(path, 260, DAT_0106eb24);
            unsigned int prefixLengthSlot0 = FUN_0044a670(path);
            FUN_00406d50(path, 260, GetMenuIconName(FUN_00479430(DAT_011d9ea8->FUN_0044ddc0())));
            if (FUN_0044a670(path) > prefixLengthSlot0)
            {
                (*icon->tile.FUN_0073ac90())->FUN_00a01350(0xfcc, path, 1);
                (*icon->tile.FUN_0073ac90())->FUN_00700320(0xfa3, 1);
            }
            else
                (*icon->tile.FUN_0073ac90())->FUN_00700320(0xfa3, 0);
            if (!entry.FUN_00701740())
                description->FUN_00700320(0xfa3, 1);
            FUN_00781680();
        }
    }
    else if (action == 30)
    {
        ClearActionPointSource();
        description->FUN_00a01350(0xfcc, DAT_01073aac, 1);
        if (!entry.FUN_00701740())
            description->FUN_00700320(0xfa3, 1);
        button->FUN_00a01350(0xfc4, DAT_011d5168->FUN_00403df0(), 1);
        button->FUN_00700320(0xfaf, 1);
    }
}
}

struct Form
{
    int FUN_00401170();
};
struct Extra
{
    bool FUN_00418ba0();
};
struct ExtraNode
{
    Extra** FUN_006815c0();
};
struct Entry
{
    ~Entry();
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(bool);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    bool FUN_004bddd0(bool);
    void* FUN_004459e0(int);
};
struct EntryListNode
{
    Entry* item;
    EntryListNode* next;
    EntryListNode();
    ~EntryListNode();
    Entry** FUN_006815c0();
    EntryListNode* FUN_00726070();
    void FUN_0063f7b0();
};
struct Changes
{
    void FilterInventoryChanges(Form*, EntryListNode*);
};
Changes* __cdecl FUN_004bf220(void*);
extern void* player;
float __cdecl FUN_00476b20(float);
struct InventoryCheck
{
    bool FUN_00781860(Entry* entry);
};
struct ItemLabelSource : InventoryStackRecord
{
    int FUN_00726070();
    unsigned char FUN_004bd820();
    const char* GetTargetFullName();
    bool FUN_004bddd0(bool);
};
class Actor;
class TESAmmo;
struct TESObjectWEAP
{
    TESAmmo* GetCurrentAmmo(Actor*);
};
struct ItemLabelPlayer
{
    bool FUN_00967b70(InventoryStackRecord*);
    TESObjectWEAP* FUN_008a1710();
};
struct ItemLabelChildren
{
    Tile** FUN_007b5370();
    void* FUN_00559450();
    Tile** AddEight(void*);
};
struct ItemLabelTile : Tile
{
    int tileHeader;
    ItemLabelChildren children;
};
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
void __cdecl UpdateItemLabel(ItemLabelTile* tile, ItemLabelSource* item);
// 0x00780d60  unit_65921382d98c.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, no stack args (ret): menu refresh/close path.
extern "C" void* DAT_011d9ea8;
extern "C" int DAT_011d9ebc;
void* __fastcall FUN_00559450(void* obj);
void __cdecl FUN_00782a90();
void __cdecl FUN_007832a0(void* tile, int index);
struct Sh006815c0
{
    void** FUN_006815c0();
};
struct Sh00726070
{
    void* FUN_00726070();
};
struct Sh00a01230
{
    bool IsTraitNonZero(int arg);
};
struct Sh007314c0
{
    char pad[0x64];
    void FUN_007314c0(void (*fn)(void*, int), int a, int b);
};
struct Sh005ae3d0
{
    void FUN_005ae3d0(void** pp);
};
struct Sh004bddd0
{
    bool FUN_004bddd0(bool arg);
};
struct Sh0088c650
{
    void EquipItem(void* a, int b, void* c, bool d, bool e, bool f);
};
struct Sh0088c790
{
    void UnequipItem(void* a, int b, void* c, bool d, bool e, bool f);
};
unsigned __cdecl FUN_0058db10(int arg);
unsigned __cdecl LookupFormByID(int arg);
class SettingString
{
  public:
    const char* GetString();
};
extern "C" SettingString DAT_011d2af0;
struct GpEmb75
{
    virtual int v0();
    virtual int v1();
    virtual int v2(int arg);
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7(int arg);
};
struct Gp75
{
    char pad00[0xa4];
    GpEmb75 emb;
};
struct Menu75b
{
    char pad00[0xb8];
    Sh007314c0 lb;
    Sh005ae3d0 list;

    void FUN_00780d60();
};

bool FUN_00702450(int);
FOPipboyManager* FUN_00705990();
bool FUN_00709d40();
bool FUN_00702140();
void FUN_00717280(int);
void ShowStatsMenu(int, int);
void UpdatePipboyMapVisibility(int, int);

// @fnv 0x00782190
bool InventoryMenu::FUN_00782190(int input, int unused)
{
    if (!FUN_00702450(1002) || !FUN_00705990()->IsUnk28Set())
        return false;
    bool consumed = false;
    if (FUN_00709d40() && m_kMenuData.GetVisible())
    {
        switch (input)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            if (FUN_00702140())
                consumed = true;
            break;
        }
    }
    if (!consumed && FUN_00702450(1002))
    {
        switch (input)
        {
        case 13:
            FUN_00717280(36);
            ShowStatsMenu(1, 0);
            consumed = true;
            break;
        case 14:
            FUN_00717280(36);
            UpdatePipboyMapVisibility(1, 0);
            consumed = true;
            break;
        case 15:
            HandleClick(19, 0);
            consumed = true;
            break;
        case 16:
            if (m_pTiles[9]->FUN_00a011b0(0xfaf) != 0.0)
            {
                m_kMenuData.SetVisible(true);
                m_pTiles[11]->Set(0xfa3, 0);
            }
            consumed = true;
            break;
        case 3:
        case 4: {
            int tab = m_iCurrentTab;
            bool visible = m_kMenuData.GetVisible();
            HandleMouseoverTileAlt(29, 0);
            tab += input == 4 ? -1 : 1;
            tab = tab > 4 ? 0 : tab;
            tab = tab < 0 ? 4 : tab;
            HandleClick(tab + 24, 0);
            if (visible)
                m_kMenuData.SetVisible(true);
            consumed = true;
        }
        break;
        }
    }
    return consumed;
}
