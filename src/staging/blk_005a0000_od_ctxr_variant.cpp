
// blk_005a0000_od_ctxr_variant.cpp: rename variant for 0x005a7d40 (integration 2026-10-30): the unit's skeleton with FUN_00680890 renamed, whose names are bound elsewhere.
// src/staging/blk_005a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FUN_005a3740_cls
{
    unsigned char GetByteAt14C();
};
struct FUN_005a3790Class
{
    bool FUN_005a3790();
};
bool __cdecl FUN_005a3760(void* reference, void* b, void* c, double& result);
struct FUN_005a7840_Class
{
    void ClearFlag(unsigned char bFlag);
};
struct FUN_005a8040_class
{
    void SetField54(int param_2);
};
struct FUN_005a8080
{
    void* GetField();
};
extern unsigned char DAT_0118c684;
extern int DAT_011cac64;
void FUN_005b4940();
extern int g_TES;
struct FUN_00456a60_class
{
    void __thiscall FUN_00456a60();
};
bool FUN_005b9220();
extern int g_TES;
extern char DAT_012680fc;
struct FUN_00456a60_Class
{
    void __thiscall FUN_00456a60();
};
char __cdecl FUN_005b9240();
struct FUN_005b92e0_class
{
    int __thiscall GetField59C();
};
struct FUN_005a7220_class
{
    void Initialize();
};
struct FUN_005a71d0_class
{
    void* __thiscall FUN_005a71d0();
};
struct FUN_005a7220_cls
{
    int __thiscall Initialize();
};
struct Flt
{
    operator unsigned int();
};
struct BSSimpleListBase
{
    BSSimpleListBase* GetNext();
};
struct FUN_005a7c00_class : public BSSimpleListBase
{
    char __thiscall FUN_005a7c00(BSSimpleListBase* other);
};
struct FUN_005a8e20_cls
{
    int __thiscall FUN_005a90b0(void* param, bool flag);
    void __thiscall AttachScriptLocals(void* param);
    char __thiscall FUN_005a8ef0(int param_2, int param_3);
};
char __cdecl ConsumeByteAtE4();
void ShowMessageBox_Callback();
extern unsigned char g_bLimbConditionEffectInitialized;
void FUN_005b9200(unsigned char value);
extern NiPointer<NiNode> g_011dee84;
NiNode* FUN_005bac60();
struct GlobalObject_00633c90
{
    void* operator->() const;
};
extern GlobalObject_00633c90 g_011deca4;
void* FUN_005bac70();
extern int DAT_011c6f18;
void FUN_005bac80(int value);
struct FUN_00483370
{
    virtual void DestructorEntry();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00483370();
    ~FUN_00483370();
};
struct FUN_00402d00
{
    virtual void DestructorEntry();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    FUN_00402d00();
    ~FUN_00402d00();
};
struct FUN_00680890_r005a7d40
{
    unsigned int first;
    unsigned int second;
    FUN_00680890_r005a7d40();
    ~FUN_00680890_r005a7d40();
};
struct FUN_0096a2d0
{
    unsigned int first;
    unsigned int second;
    FUN_0096a2d0();
    ~FUN_0096a2d0();
};
struct FUN_005a7c50 : FUN_00483370, FUN_00402d00
{
    FUN_00680890_r005a7d40 member34;
    FUN_0096a2d0 member3c;
    FUN_0096a2d0 member44;
    FUN_0096a2d0 member4c;
    FUN_005a7c50();
    void FUN_004f15a0(unsigned int);
};
// FUN_005bd580 : float member getter, returns *m_pIntegerData if present else 0.0f
struct FUN_005bd580_cls
{
    int m_i00;
    int m_i01;
    int m_i02;
    int m_i03;
    int m_i04;
    int m_i05;
    int m_i06;
    int m_i07;
    int m_i08;
    int m_i09;
    int m_i10;
    int m_i11;
    int m_i12;
    int m_i13;
    float* m_pIntegerData;
    float FUN_005bd580();
};
struct FUN_005a77b0 : FUN_00483370, FUN_00402d00
{
    virtual void Extra();
    FUN_005a77b0();
};
struct FUN_005a78a0 : FUN_00483370, FUN_00402d00
{
    virtual void Extra();
    virtual ~FUN_005a78a0();
};
struct FUN_004855a0_shell
{
    void FUN_004855a0();
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
struct FUN_00483710_shell
{
    void FUN_00483710();
};
struct FUN_00485e20_shell
{
    void FUN_00485e20(int, int);
};
struct FUN_00485680_shell
{
    void FUN_00485680();
};
unsigned char __cdecl FUN_00401500();
struct FUN_005a7a90_shell
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
    void FUN_005a7a90();
};
struct FUN_005a7b00_Record
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int m_24;
};
extern int DAT_01186490;
extern int DAT_01183028;
FUN_005a7b00_Record* __cdecl FUN_00ec43fb(unsigned int id, int unused, const int* descriptor, const int* type,
                                          int flag);
void __cdecl FUN_00401460(unsigned int* destination, unsigned int* source, int flag);
struct FUN_005a7b00_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int m_24;
    void FUN_004851b0(unsigned int id);
    void InitializeFromRecord(unsigned int id);
};
extern "C" int __cdecl memcmp(const void* a, const void* b, unsigned int n);
class TESForm
{
  public:
    virtual ~TESForm();
};
class TESRecipeCategory : public TESForm
{
  public:
};
struct FUN_008ad910_rd;
class FUN_008ad910_ref
{
  public:
    FUN_008ad910_rd* GetData();
};
class FUN_005e79a0_t
{
  public:
    bool FUN_00485270(TESForm* pkForm);
};
class FUN_005a7b60_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned char m_data;

    bool FUN_005a7b60(TESForm* pkForm);
};
void __cdecl operator delete(void*);
struct DeletingObject
{
    void FUN_005a7d40();
    void* Destroy(unsigned int flags);
};
struct FUN_005a7870_cls
{
    virtual ~FUN_005a7870_cls();
};
struct ScriptLocals;
struct Script
{
    static bool __cdecl GetValue(double& result, char const* format, unsigned int& value, TESObjectREFR* reference1,
                                 TESObjectREFR* reference2, Script* script, ScriptLocals* locals, bool evaluate);
};
void* memset(void* destination, int value, unsigned int size);
bool __cdecl FUN_005b4960(int unused, char const* data, TESObjectREFR* reference1, TESObjectREFR* reference2,
                          Script* script, ScriptLocals* locals, int unused2, unsigned int& value, char const* format,
                          BSStringT<char>* string);

// Generated address-based names identify the native TESForm base destructor
// and TESRecipe destructor to this checker; layouts/ownership follow native RTTI.
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class FUN_00483630_holder : public BaseFormComponent
{
  public:
    unsigned char formType;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int flags;
    unsigned int formID;
    unsigned int unk10;
    unsigned int unk14;
    virtual ~FUN_00483630_holder();
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> fullName;
    virtual ~TESFullName();
};
class FUN_005a7d40 : public FUN_00483630_holder, public TESFullName
{
  public:
    unsigned int skill;
    unsigned int requiredSkill;
    unsigned int category;
    unsigned int subcategory;
    FUN_00680890_r005a7d40 conditions;
    BSSimpleList<void*> ingredients;
    BSSimpleList<void*> outputs;
    BSSimpleList<void*> unk4c;
    void FUN_005a80a0();
    virtual ~FUN_005a7d40();
};
// @fnv 0x005a7d40
FUN_005a7d40::~FUN_005a7d40()
{
    FUN_005a80a0();
}
