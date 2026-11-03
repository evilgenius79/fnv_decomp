
// src/staging/blk_005a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_005a3740_cls
{
    unsigned char GetByteAt14C();
};

// @fnv 0x005a3740
unsigned char FUN_005a3740_cls::GetByteAt14C()
{
    return *(unsigned char*)((char*)this + 0x14c);
}

struct FUN_005a3790Class
{
    bool FUN_005a3790();
};

// Sets result to 0.0, then to 1.0 if the reference's FUN_005a3790 check succeeds, and returns true.
// @fnv 0x005a3760
bool __cdecl FUN_005a3760(void* reference, void* b, void* c, double& result)
{
    result = 0.0;
    if (((FUN_005a3790Class*)reference)->FUN_005a3790())
        result = 1.0;
    return true;
}

struct FUN_005a7840_Class
{
    void ClearFlag(unsigned char bFlag);
};

// Clears the bit(s) of bFlag in the byte at offset 0x24 of this object.
// @fnv 0x005a7840
void FUN_005a7840_Class::ClearFlag(unsigned char bFlag)
{
    *(unsigned char*)((char*)this + 0x24) &= ~bFlag;
}

struct FUN_005a8040_class
{
    void SetField54(int param_2);
};

// @fnv 0x005a8040
void FUN_005a8040_class::SetField54(int aiValue)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x54) = aiValue;
}

struct FUN_005a8080
{
    void* GetField();
};

// @fnv 0x005a8080
void* FUN_005a8080::GetField()
{
    return (void*)((char*)this + 0x3c);
}

extern unsigned char DAT_0118c684;
extern int DAT_011cac64;

// @fnv 0x005b4940
void FUN_005b4940()
{
    DAT_0118c684 = 0xff;
    DAT_011cac64 = 0;
}

extern int g_TES;

struct FUN_00456a60_class
{
    void __thiscall FUN_00456a60();
};

// @fnv 0x005b9220
bool FUN_005b9220()
{
    ((FUN_00456a60_class*)g_TES)->FUN_00456a60();
    return true;
}

extern int g_TES;
extern char DAT_012680fc;
struct FUN_00456a60_Class
{
    void __thiscall FUN_00456a60();
};
// Sets DAT_012680fc to 1, calls FUN_00456a60 on g_TES, resets DAT_012680fc to 0 and returns 1.
// @fnv 0x005b9240
char __cdecl FUN_005b9240()
{
    DAT_012680fc = 1;
    ((FUN_00456a60_Class*)(int)g_TES)->FUN_00456a60();
    DAT_012680fc = 0;
    return 1;
}

struct FUN_005b92e0_class
{
    int __thiscall GetField59C();
};

// @fnv 0x005b92e0
int __thiscall FUN_005b92e0_class::GetField59C()
{
    return *(int*)((char*)this + 0x59c);
}

struct FUN_005a7220_class
{
    void Initialize();
};
struct FUN_005a71d0_class
{
    void* __thiscall FUN_005a71d0();
};
// Calls Initialize on the sub-objects at offsets 4 and 0x2c, then sets the fields at 0, 0x50 and 0x54 and returns this.
// @fnv 0x005a71d0
void* __thiscall FUN_005a71d0_class::FUN_005a71d0()
{
    ((FUN_005a7220_class*)((char*)this + 4))->Initialize();
    ((FUN_005a7220_class*)((char*)this + 0x2c))->Initialize();
    *(int*)this = 0;
    *(int*)((char*)this + 0x50) = 4;
    *(int*)((char*)this + 0x54) = 3;
    return this;
}

struct FUN_005a7220_cls
{
    int __thiscall Initialize();
};
// @fnv 0x005a7220
int __thiscall FUN_005a7220_cls::Initialize()
{
    *(int*)this = 0;
    *(int*)(this + 4) = 0;
    *(int*)(this + 8) = 0;
    *(int*)(this + 12) = 0;
    *(float*)(this + 16) = 0.0f;
    *(int*)(this + 20) = 6;
    *(float*)(this + 24) = 255.0f;
    *(float*)(this + 28) = 255.0f;
    *(float*)(this + 32) = 255.0f;
    *(int*)(this + 36) = 1;
    return (int)this;
}

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

// Compares this list node's value and next pointer against another's, returning 1 if either differs, else 0.
// @fnv 0x005a7c00
char __thiscall FUN_005a7c00_class::FUN_005a7c00(BSSimpleListBase* other)
{
    if (reinterpret_cast<Flt*>(this)->operator unsigned int() != reinterpret_cast<Flt*>(other)->operator unsigned int())
        return 1;
    if (this->GetNext() != other->GetNext())
        return 1;
    return 0;
}

struct FUN_005a8e20_cls
{
    int __thiscall FUN_005a90b0(void* param, bool flag);
    void __thiscall AttachScriptLocals(void* param);
    char __thiscall FUN_005a8ef0(int param_2, int param_3);
};
// @fnv 0x005a8ef0
char __thiscall FUN_005a8e20_cls::FUN_005a8ef0(int param_2, int param_3)
{
    int result = FUN_005a90b0((void*)param_2, false);
    if (!result)
        AttachScriptLocals((void*)param_2);
    else if (*(int*)((char*)result + 4) & param_3)
        return 1;
    return 0;
}

char __cdecl ConsumeByteAtE4();

// @fnv 0x005b4a70
void ShowMessageBox_Callback()
{
    DAT_0118c684 = ConsumeByteAtE4();
}

extern unsigned char g_bLimbConditionEffectInitialized;
// @fnv 0x005b9200
void FUN_005b9200(unsigned char value)
{
    g_bLimbConditionEffectInitialized = value;
}

namespace fnv_005bac20 {
struct Flt
{
    operator unsigned int();
};
extern Flt g_011c786c;
struct NiNode
{
    unsigned int FUN_00453470();
};
// Returns false if g_011c786c is null, otherwise returns whether its FUN_00453470 result is greater than zero.
// @fnv 0x005bac20
bool __cdecl FUN_005bac20()
{
    if ((unsigned int)g_011c786c == 0)
        return false;
    return 0 < ((NiNode*)(unsigned int)g_011c786c)->FUN_00453470();
}
}  // namespace fnv_005bac20

namespace fnv_005bac50 {
struct Flt
{
    operator unsigned int() const;
};
extern Flt g_011c786c;
// @fnv 0x005bac50
unsigned int FUN_005bac50()
{
    return g_011c786c;
}
}  // namespace fnv_005bac50

extern NiPointer<NiNode> g_011dee84;

// @fnv 0x005bac60
NiNode* FUN_005bac60()
{
    return g_011dee84.operator->();
}

struct GlobalObject_00633c90
{
    void* operator->() const;
};
extern GlobalObject_00633c90 g_011deca4;
// @fnv 0x005bac70
void* FUN_005bac70()
{
    return g_011deca4.operator->();
}

extern int DAT_011c6f18;

// @fnv 0x005bac80
void FUN_005bac80(int value)
{
    DAT_011c6f18 = value;
}

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
struct FUN_00680890
{
    unsigned int first;
    unsigned int second;
    FUN_00680890();
    ~FUN_00680890();
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
    FUN_00680890 member34;
    FUN_0096a2d0 member3c;
    FUN_0096a2d0 member44;
    FUN_0096a2d0 member4c;
    FUN_005a7c50();
    void FUN_004f15a0(unsigned int);
};
// Constructs the object and calls FUN_004f15a0 with 0x6a.
// @fnv 0x005a7c50
FUN_005a7c50::FUN_005a7c50()
{
    FUN_004f15a0(0x6a);
}

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

// @fnv 0x005bd580
float FUN_005bd580_cls::FUN_005bd580()
{
    return this->m_pIntegerData != 0 ? *this->m_pIntegerData : 0.0f;
}

struct FUN_005a77b0 : FUN_00483370, FUN_00402d00
{
    virtual void Extra();
    FUN_005a77b0();
};
// Constructor that calls FUN_004f15a0 with 0x6b and ClearFlag with 1 on this object.
// @fnv 0x005a77b0
FUN_005a77b0::FUN_005a77b0()
{
    ((FUN_005a7c50*)this)->FUN_004f15a0(0x6b);
    ((FUN_005a7840_Class*)this)->ClearFlag(1);
}

struct FUN_005a78a0 : FUN_00483370, FUN_00402d00
{
    virtual void Extra();
    virtual ~FUN_005a78a0();
};
// @fnv 0x005a78a0
FUN_005a78a0::~FUN_005a78a0()
{}

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

// @fnv 0x005a7a90
void FUN_005a7a90_shell::FUN_005a7a90()
{
    ((FUN_004855a0_shell*)this)->FUN_004855a0();
    ((FUN_00487010_shell*)((char*)this + 0x18))->FUN_00487010();
    if (FUN_00401500())
        ((FUN_00483710_shell*)((char*)this + 0x24))->FUN_00483710();
    ((FUN_00485e20_shell*)this)->FUN_00485e20((int)((char*)this + 0x24), 1);
    if (FUN_00401500())
        ((FUN_00483710_shell*)((char*)this + 0x24))->FUN_00483710();
    ((FUN_00485680_shell*)this)->FUN_00485680();
}

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
// Looks up a record by id, copies its m_24 field into this object's m_24, then calls FUN_004851b0 with the id.
// @fnv 0x005a7b00
void FUN_005a7b00_Class::InitializeFromRecord(unsigned int id)
{
    FUN_005a7b00_Record* record = FUN_00ec43fb(id, 0, &DAT_01183028, &DAT_01186490, 0);
    if (record == 0)
        return;
    FUN_00401460(&m_24, &record->m_24, 1);
    FUN_004851b0(id);
}

namespace fnv_005a8660 {
extern "C" char DAT_011864b0;
extern "C" char DAT_01183028;
struct FUN_005a7be0
{
    int data[2];
    FUN_005a7be0();
    unsigned int FUN_00559450();
    void* FUN_00726070();
    void FUN_00537e90(unsigned int);
    void FUN_006ecd40(void*);
};
struct CopyList
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    FUN_005a7be0** FUN_006815c0();
    CopyList* FUN_00726070();
    void FUN_00905820(FUN_005a7be0* const&);
};
struct CopyString
{
    void CopyConditions(CopyString*, int);
};
struct CopyForm
{
    char data[0x34];
    CopyString* FUN_006a9540();
    CopyList* FUN_005a8080();
    CopyList* FUN_005d43c0();
    void FUN_004851b0(void*);
    int FUN_0059bb30();
    int FUN_0045cd60();
    int GetField54();
    int FUN_006286d0();
    void FUN_007037c0(int);
    void FUN_0061cc40(int);
    void SetField54(int);
    void FUN_005a8060(int);
    void CopyFrom(void*);
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
void* __cdecl memcpy(void*, const void*, unsigned int);
// Copies data from the form returned by FUN_00ec43fb into this form, cloning its two node lists and copying several fields.
// @fnv 0x005a8660
void CopyForm::CopyFrom(void* apSource)
{
    CopyForm* source3 = (CopyForm*)FUN_00ec43fb(apSource, 0, &DAT_01183028, &DAT_011864b0, 0);
    if (!source3)
        return;
    FUN_006a9540()->CopyConditions(source3->FUN_006a9540(), 0);
    memcpy(data + 0x24, source3->data + 0x24, 0x10);
    FUN_004851b0(apSource);
    while (!FUN_005a8080()->FUN_008256d0())
        FUN_005a8080()->FUN_0063f7b0();
    CopyList* iter = source3->FUN_005a8080();
    while (iter && !iter->FUN_008256d0())
    {
        FUN_005a7be0* oldNode = *iter->FUN_006815c0();
        FUN_005a7be0* newNode = new FUN_005a7be0;
        newNode->FUN_00537e90(oldNode->FUN_00559450());
        newNode->FUN_006ecd40(oldNode->FUN_00726070());
        FUN_005a8080()->FUN_00905820(newNode);
        iter = iter->FUN_00726070();
    }
    while (!FUN_005d43c0()->FUN_008256d0())
        FUN_005d43c0()->FUN_0063f7b0();
    iter = source3->FUN_005d43c0();
    while (iter && !iter->FUN_008256d0())
    {
        FUN_005a7be0* oldNode = *iter->FUN_006815c0();
        FUN_005a7be0* newNode = new FUN_005a7be0;
        newNode->FUN_00537e90(oldNode->FUN_00559450());
        newNode->FUN_006ecd40(oldNode->FUN_00726070());
        FUN_005d43c0()->FUN_00905820(newNode);
        iter = iter->FUN_00726070();
    }
    FUN_007037c0(source3->FUN_0059bb30());
    FUN_0061cc40(source3->FUN_0045cd60());
    SetField54(source3->GetField54());
    FUN_005a8060(source3->FUN_006286d0());
}
}  // namespace fnv_005a8660

namespace fnv_005a8910 {
extern "C" char DAT_011864b0;
extern "C" char DAT_01183028;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct SubItem
{
    unsigned char FUN_005a7c00(SubItem*);
};
struct SubList
{
    unsigned int FUN_005ae380();
    bool FUN_008256d0();
    SubItem** FUN_006815c0();
    SubList* FUN_00726070();
};
struct SubString
{
    bool FUN_00680b70(SubString&);
};
struct SubChallenge
{
    int GetField54();
    int FUN_006286d0();
    unsigned int FUN_0059bb30();
    int FUN_0045cd60();
    bool FUN_00485270(SubChallenge*);
    SubString& FUN_006a9540();
    SubList* FUN_005a8080();
    SubList* FUN_005d43c0();
    bool IsNotEqual(void*);
};
// Resolves input to a SubChallenge and returns true if any field, string, list size or list element differs from this object's, false if all match.
// @fnv 0x005a8910
bool SubChallenge::IsNotEqual(void* input)
{
    SubChallenge* other = (SubChallenge*)FUN_00ec43fb(input, 0, &DAT_01183028, &DAT_011864b0, 0);
    if (!other)
        return true;
    if (GetField54() != other->GetField54())
        return true;
    if (FUN_006286d0() != other->FUN_006286d0())
        return true;
    if (FUN_0059bb30() != other->FUN_0059bb30())
        return true;
    if (FUN_0045cd60() != other->FUN_0045cd60())
        return true;
    if (FUN_00485270(other))
        return true;
    if (FUN_006a9540().FUN_00680b70(other->FUN_006a9540()))
        return true;
    if (FUN_005a8080()->FUN_005ae380() != other->FUN_005a8080()->FUN_005ae380())
        return true;
    if (FUN_005d43c0()->FUN_005ae380() != other->FUN_005d43c0()->FUN_005ae380())
        return true;
    SubList* a = FUN_005a8080();
    SubList* b5 = other->FUN_005a8080();
    while (b5 && !b5->FUN_008256d0())
    {
        if (!a || a->FUN_008256d0())
            return true;
        SubItem* x = *a->FUN_006815c0();
        SubItem* y = *b5->FUN_006815c0();
        if (x->FUN_005a7c00(y))
            return true;
        b5 = b5->FUN_00726070();
        a = a->FUN_00726070();
    }
    SubList* c3 = FUN_005d43c0();
    SubList* d2 = other->FUN_005d43c0();
    while (d2 && !d2->FUN_008256d0())
    {
        if (!c3 || c3->FUN_008256d0())
            return true;
        SubItem* x = *c3->FUN_006815c0();
        SubItem* y = *d2->FUN_006815c0();
        if (x->FUN_005a7c00(y))
            return true;
        d2 = d2->FUN_00726070();
        c3 = c3->FUN_00726070();
    }
    return false;
}
}  // namespace fnv_005a8910

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

// Returns true if pkForm is not a TESRecipeCategory, its first data byte differs from m_data, or FUN_00485270 returns true; otherwise false.
// @fnv 0x005a7b60
bool FUN_005a7b60_cls::FUN_005a7b60(TESForm* pkForm)
{
    TESRecipeCategory* pkCategory = dynamic_cast<TESRecipeCategory*>(pkForm);
    if (!pkCategory)
        return true;
    if (memcmp(&m_data, reinterpret_cast<FUN_008ad910_ref*>(pkCategory)->GetData(), 1))
        return true;
    if (reinterpret_cast<FUN_005e79a0_t*>(this)->FUN_00485270(pkCategory))
        return true;
    return false;
}

void __cdecl operator delete(void*);
struct DeletingObject
{
    void FUN_005a7d40();
    void* Destroy(unsigned int flags);
};
// Calls FUN_005a7d40, then frees this via operator delete when the low bit of flags is set, and returns this.
// @fnv 0x005a7d10
void* DeletingObject::Destroy(unsigned int flags)
{
    FUN_005a7d40();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

namespace fnv_005a8490 {
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class TESForm : public BaseFormComponent
{
  public:
    unsigned char formType;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int flags;
    unsigned int formID;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int GetFormID();
    void FUN_004855a0();
    void FUN_00485680();
    void FUN_00485e20(void*, int);
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> fullName;
    void FUN_00487010();
};
struct RecipeItem
{
    unsigned int quantity;
    TESForm* form;
    TESForm* FUN_00726070();
    unsigned int FUN_00559450();
};
struct RecipeItemProcessor
{
    unsigned int unk00;
    unsigned int unk04;
    void ProcessItems();
};
struct RecipeData
{
    unsigned int skill;
    unsigned int level;
    TESForm* category;
    TESForm* subcategory;
    void FUN_00414220();
};
void FUN_00485910(unsigned int type, unsigned int value);
class TESRecipe : public TESForm, public TESFullName
{
  public:
    RecipeData data;
    RecipeItemProcessor conditions;
    BSSimpleList<RecipeItem*> ingredients;
    BSSimpleList<RecipeItem*> outputs;
    BSSimpleList<RecipeItem*> unk4c;
    RecipeItemProcessor* FUN_006a9540();
    TESForm* GetField54();
    TESForm* FUN_006286d0();
    RecipeData* FUN_00430830();
    BSSimpleList<RecipeItem*>* FUN_005a8080();
    BSSimpleList<RecipeItem*>* FUN_005d43c0();
    void FUN_005a8490();
};
// Stores category and subcategory form IDs, then calls FUN_00485910 with the form ID and count of each ingredient and each output item.
// @fnv 0x005a8490
void TESRecipe::FUN_005a8490()
{
    FUN_004855a0();
    TESFullName::FUN_00487010();
    FUN_006a9540()->ProcessItems();
    FUN_00430830()->category = reinterpret_cast<TESForm*>(GetField54() ? GetField54()->GetFormID() : 0);
    FUN_00430830()->subcategory = reinterpret_cast<TESForm*>(FUN_006286d0() ? FUN_006286d0()->GetFormID() : 0);
    if (FUN_00401500())
        data.FUN_00414220();
    FUN_00485e20(&data, 16);
    if (FUN_00401500())
        data.FUN_00414220();
    BSSimpleList<RecipeItem*>* iter = FUN_005a8080();
    RecipeItem* item = 0;
    while (iter && iter->GetItem())
    {
        item = iter->GetItem();
        iter = iter->GetNext();
        FUN_00485910(0x4c494352, item->FUN_00726070()->GetFormID());
        FUN_00485910(0x59514352, item->FUN_00559450());
    }
    iter = FUN_005d43c0();
    item = 0;
    while (iter && iter->GetItem())
    {
        item = iter->GetItem();
        iter = iter->GetNext();
        FUN_00485910(0x444f4352, item->FUN_00726070()->GetFormID());
        FUN_00485910(0x59514352, item->FUN_00559450());
    }
    FUN_00485680();
}
}  // namespace fnv_005a8490

struct FUN_005a7870_cls
{
    virtual ~FUN_005a7870_cls();
};

// @fnv 0x005a7870
FUN_005a7870_cls::~FUN_005a7870_cls()
{}

struct ScriptLocals;

struct Script
{
    static bool __cdecl GetValue(double& result, char const* format, unsigned int& value, TESObjectREFR* reference1,
                                 TESObjectREFR* reference2, Script* script, ScriptLocals* locals, bool evaluate);
};

void* memset(void* destination, int value, unsigned int size);

// Reads a short count and that many values from data via Script::GetValue, then formats them into string using format; returns false if any read fails.
// @fnv 0x005b4960
bool __cdecl FUN_005b4960(int unused, char const* data, TESObjectREFR* reference1, TESObjectREFR* reference2,
                          Script* script, ScriptLocals* locals, int unused2, unsigned int& value, char const* format,
                          BSStringT<char>* string)
{
    double values[10];

    {
        short count = *reinterpret_cast<short const*>(data + value);
        short i;

        value += 2;
        memset(values, 0, sizeof(values));

        for (i = 0; i < count; ++i)
        {
            values[i] = 0.0;
            if (!Script::GetValue(values[i], data, value, reference1, reference2, script, locals, true))
            {
                return false;
            }
        }
    }

    string->PrintfString(format, values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7],
                    values[8], values[9]);
    return true;
}
