
// src/fallout/magic/summoncreatureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/summoncreatureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SummonCreatureEffect
{
    virtual ~SummonCreatureEffect();
    void FUN_00828590();
    void* FUN_00828560(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// Calls FUN_00828590, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00828560
void* SummonCreatureEffect::FUN_00828560(unsigned int flags)
{
    FUN_00828590();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00828da0_shell
{
    int __thiscall GetZero(int a, int b, int c);
};

// Returns 0; the local variables are initialized to 0 and never used.
// @fnv 0x00828da0
int __thiscall FUN_00828da0_shell::GetZero(int a, int b, int c)
{
    int v1 = 0;
    int v2 = 0;
    return v1;
}

struct Actor;
struct FUN_00806da0_shell
{
    unsigned short __thiscall FUN_00806da0(Actor*);
};
struct FUN_00829720_shell : public SummonCreatureEffect
{
    unsigned short __thiscall FUN_00829720(Actor* actor);
};
// @fnv 0x00829720
unsigned short __thiscall FUN_00829720_shell::FUN_00829720(Actor* actor)
{
    unsigned short isize = 0;
    isize += ((FUN_00806da0_shell*)this)->FUN_00806da0(actor);
    isize += 4;
    isize += 1;
    if (!*(Actor**)((char*)this + 0x4c))
    {
        isize += 4;
        isize += 0xc;
        isize += 0xc;
    }
    return isize;
}

struct Actor;
struct AssociatedItemEffect
{
    void FUN_00806e30(Actor* actor);
};
struct TESSaveLoadGame
{
    void ReadTypedData(void* p, unsigned int size);
    unsigned char FUN_00857aa0(unsigned int* p, int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_00829850_shell : AssociatedItemEffect
{
    Actor* m_pActor;
    bool m_bAssociatedItemLoaded;
    void LoadAssociatedItemEffect(Actor* actor);
};
// Calls the base loader, reads a 4-byte id and a byte from the save stream, stores them, and reads further fields when the id is zero and not forced.
// @fnv 0x00829850
void FUN_00829850_shell::LoadAssociatedItemEffect(Actor* actor)
{
    unsigned int id;
    unsigned char bforcedToZero;
    FUN_00806e30(actor);
    bforcedToZero = g_TESSaveLoadGame->FUN_00857aa0(&id, 4);
    *(Actor**)((char*)this + 0x4c) = (Actor*)id;
    g_TESSaveLoadGame->ReadTypedData((char*)this + 0x50, 1);
    if (!id && !bforcedToZero)
    {
        g_TESSaveLoadGame->ReadTypedData((char*)this + 0x54, 4);
        g_TESSaveLoadGame->ReadTypedData((char*)this + 0x58, 0xc);
        g_TESSaveLoadGame->ReadTypedData((char*)this + 0x64, 0xc);
        *(char*)((char*)this + 0x70) = 0;
    }
    else
    {
        *(char*)((char*)this + 0x70) = 1;
    }
}

struct FUN_0040b800_shell
{
    void FUN_0040b800(bool);
};
struct FUN_0080d930
{
    virtual void placeholder();
    ~FUN_0080d930();
};
struct FUN_00828590 : FUN_0080d930
{
    virtual ~FUN_00828590();
    FUN_0040b800_shell* FUN_0044ddc0();
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
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned char unk70;
    unsigned char unk71;
};
// Destructor: if unk71 is set and FUN_0044ddc0() returns non-null, calls FUN_0040b800(true) on the returned shell object.
// @fnv 0x00828590
FUN_00828590::~FUN_00828590()
{
    if (unk71 && FUN_0044ddc0())
        FUN_0044ddc0()->FUN_0040b800(true);
}

struct SelectedRecord
{
    int x;
    int y;
    int z;
};
extern void* selectionContext;
int __cdecl FUN_00828b20(const void*, const void*);
void __cdecl FUN_00ec6f20(int, int, int, int);
struct SelectionPredicate
{
    bool FUN_00828f00(int, SelectedRecord*);
};
struct RecordSelector
{
    bool SelectRecord(void* context, int flags, SelectedRecord* output);
};
// Collects records via GetZero, sorts them with FUN_00ec6f20, finds the first matching FUN_00828f00, copies it to output and frees the array.
// @fnv 0x00828cb0
bool RecordSelector::SelectRecord(void* context, int flags, SelectedRecord* output)
{
    SelectedRecord* entries = 0;
    int count = ((FUN_00828da0_shell*)this)->GetZero((int)&entries, (int)context, flags);
    if (count <= 0 || entries == 0)
        return false;
    int index = 0;
    selectionContext = context;
    FUN_00ec6f20((int)entries, count, sizeof(SelectedRecord), (int)&FUN_00828b20);
    index = 0;
    while (index < count && !((SelectionPredicate*)this)->FUN_00828f00(flags, &entries[index]))
    {
        ++index;
    }
    if (index < count)
    {
        *output = entries[index];
        SelectedRecord* selected = entries;
        _Deallocate(selected);
        return true;
    }
    else
    {
        SelectedRecord* discarded = entries;
        _Deallocate(discarded);
        return false;
    }
}

struct Actor;
struct ListNode
{
    void* value;
    ListNode* _ref_00726070();
    bool _ref_008256d0() const;
    struct ActiveEffect** _ref_006815c0();
};
struct PlayerEffects
{
    virtual void slot0();
    virtual void slot1();
    virtual ListNode* GetFirst();
};
struct Actor
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
    PlayerEffects effects;
};
extern Actor* g_thePlayer;
struct ActiveEffect;
struct EffectSetting
{
    bool IsAssociatedFormUsed();
    bool IsFlagSet(unsigned int flag);
};
struct ActiveEffect
{
    EffectSetting* GetEffectSetting();
    float GetAge();
    void Dispel(bool immediate);
};
struct GlobalObject2_0040c150
{
    int* FUN_0043d4d0();
};
extern GlobalObject2_0040c150 g_011d171c;
extern float DAT_01015f5c;

struct FUN_00829970_Class
{
    void DispelOldestQualifyingEffect();
};
// @fnv 0x00829970
void FUN_00829970_Class::DispelOldestQualifyingEffect()
{
    ListNode* node = g_thePlayer->effects.GetFirst();
    int bestAge;
    ActiveEffect* bestEffect;
    float validCount;
    bestEffect = 0;
    validCount = DAT_01015f5c;
    bestAge = 0;
    while (node && !node->_ref_008256d0())
    {
        ActiveEffect* effect = *node->_ref_006815c0();
        EffectSetting* setting = effect->GetEffectSetting();
        if (setting->IsAssociatedFormUsed() && setting->IsFlagSet(0x40000))
        {
            ++bestAge;
            if (effect->GetAge() > validCount)
            {
                bestEffect = effect;
                validCount = effect->GetAge();
            }
        }
        node = node->_ref_00726070();
    }
    if (bestEffect && bestAge > *g_011d171c.FUN_0043d4d0())
        bestEffect->Dispel(false);
}

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3();
    NiPoint3(float fX, float fY, float fZ);
};

NiPoint3 operator*(float fScalar, const NiPoint3& kPt);

float FUN_005b9e80(float f);
float FUN_005c53d0(float f);
void* FUN_006890b0(void* pCell, float fScale, const char* m_kModelObjectsItem, NiPoint3 point, NiPoint3 vel, float fScale2,
                   int iFlags, int iUnk);
float GetAnimValueByPrefix(void* pA, const char* m_pIdleForm, const char* pEvent);

struct S_008287e0_Cell;

struct S_008287e0_Actor
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0A();
    virtual void vfn0B();
    virtual void vfn0C();
    virtual void vfn0D();
    virtual void vfn0E();
    virtual void vfn0F();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1A();
    virtual void vfn1B();
    virtual void vfn1C();
    virtual void vfn1D();
    virtual void vfn1E();
    virtual void vfn1F();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2A();
    virtual void vfn2B();
    virtual void vfn2C();
    virtual void vfn2D();
    virtual void vfn2E();
    virtual void vfn2F();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn3A();
    virtual void vfn3B();
    virtual void vfn3C();
    virtual void vfn3D();
    virtual void vfn3E();
    virtual void vfn3F();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn4A();
    virtual void vfn4B();
    virtual void vfn4C();
    virtual void vfn4D();
    virtual void vfn4E();
    virtual void vfn4F();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn5A();
    virtual void vfn5B();
    virtual void vfn5C();
    virtual void vfn5D();
    virtual void vfn5E();
    virtual void vfn5F();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn6A();
    virtual void vfn6B();
    virtual void vfn6C();
    virtual void vfn6D();
    virtual void vfn6E();
    virtual void vfn6F();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn7A();
    virtual void vfn7B();
    virtual void vfn7C();
    virtual const NiPoint3& vfn7D();
    const NiPoint3& FUN_00430830();
    S_008287e0_Cell* FUN_008d6f30();
};

struct S_008287e0_Caster
{
    S_008287e0_Actor* FUN_00822b40();
};

struct S_008287e0_Model
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual const char* vfn05();
};

struct S_008287e0_Base
{
    virtual void vfn00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S_008287e0_Setting : S_008287e0_Base, S_008287e0_Model
{
};

struct S_008287e0_Item
{
    S_008287e0_Setting* FUN_00825c00();
};

struct S_008287e0_Temp
{
    void FUN_00689920(const char* m_pIdleForm);
    void* FUN_00490e40();
};

struct S_008287e0_Magic
{
    void FUN_0040a420(bool b);
};

struct S_008287e0
{
    void* vtbl;
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
    float unk54;
    NiPoint3 unk58;
    NiPoint3 unk64;
    char unk70;
    bool unk71;

    S_008287e0_Caster* FUN_0059bb30();
    S_008287e0_Item* FUN_0084e3a0();
    S_008287e0_Magic* FUN_0044ddc0();
    bool SelectRecord(S_008287e0_Actor* ref, int iUnk, NiPoint3* pPos);
    void FUN_008287e0();
};

// @fnv 0x008287e0
void S_008287e0::FUN_008287e0()
{
    S_008287e0_Actor* ref = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!ref)
        return;

    unk64 = ref->FUN_00430830();
    unk58 = ref->vfn7D();
    NiPoint3 point;
    if (SelectRecord(ref, unk4C, &point))
        unk58 = point;

    const char* m_pIdleForm = "SpecialIdle_SummonEffect";
    NiPoint3 vel = 64.0f * NiPoint3(-FUN_005c53d0(-unk64.z), FUN_005b9e80(-unk64.z), 0.0f);
    void* m_kModelObjectsItem =
        FUN_006890b0(ref->FUN_008d6f30(), 1.0f, FUN_0084e3a0()->FUN_00825c00()->vfn05(), vel, unk58, 1.0f, 7, 0);
    ((S_008287e0_Temp*)m_kModelObjectsItem)->FUN_00689920(m_pIdleForm);
    void* pAVObject = ((S_008287e0_Temp*)m_kModelObjectsItem)->FUN_00490e40();
    unk54 = GetAnimValueByPrefix(pAVObject, m_pIdleForm, "Hit");

    if (!unk71 && FUN_0044ddc0())
    {
        FUN_0044ddc0()->FUN_0040a420(false);
        unk71 = true;
    }
}

extern char DAT_0107c2ac;
extern unsigned int DAT_011f426c;
extern unsigned int DAT_011f4270;
extern unsigned int DAT_011f4274;

struct FUN_00828470_helper1
{
    void* unk00;
};

struct FUN_00828470_base
{
    FUN_00828470_base(void* a1, void* a2, FUN_00828470_helper1* a3);
    ~FUN_00828470_base();
};

struct FUN_00828470_sub
{
    void FUN_006815c0();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00828470_cls : FUN_00828470_base
{
    void* m_vptr;
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
    int m_4c;
    unsigned char m_50;
    float m_54;
    FUN_00828470_sub m_58;
    FUN_00828470_sub m_64;
    unsigned char m_70;
    unsigned char m_71;
    FUN_00828470_cls(void* a1, void* a2, FUN_00828470_helper1* a3);
};

// Constructor: sets the vtable, initialises the two sub-objects, and zeroes m_4c, m_50, m_54, m_70 and m_71.
// @fnv 0x00828470
FUN_00828470_cls::FUN_00828470_cls(void* a1, void* a2, FUN_00828470_helper1* a3) : FUN_00828470_base(a1, a2, a3)
{
    m_vptr = &DAT_0107c2ac;
    m_58.FUN_006815c0();
    m_64.FUN_006815c0();
    m_4c = 0;
    m_50 = 0;
    m_54 = 0.0f;
    m_58 = *(FUN_00828470_sub*)&DAT_011f426c;
    m_64 = *(FUN_00828470_sub*)&DAT_011f426c;
    m_70 = 0;
    m_71 = 0;
}

namespace fnv_00828610 {
struct FUN_00828610_sub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00828470_cls
{
    FUN_00828470_cls(void* a1, void* a2, void* a3);
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    int m_4c;
    unsigned char m_50;
    float m_54;
    FUN_00828610_sub m_58;
    FUN_00828610_sub m_64;
    unsigned char m_70;
    unsigned char m_71;
};

struct FUN_0044ddc0_ret
{
    void FUN_0040a420(int a1);
};

struct FUN_00828610_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int m_28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    int m_4c;
    unsigned char m_50;
    float m_54;
    FUN_00828610_sub m_58;
    FUN_00828610_sub m_64;
    unsigned char m_70;
    unsigned char m_71;

    FUN_00828470_cls* CloneObject();
    void FUN_00806d50(FUN_00828470_cls* apObj);
    FUN_0044ddc0_ret* FUN_0044ddc0();
};

// @fnv 0x00828610
FUN_00828470_cls* FUN_00828610_cls::CloneObject()
{
    FUN_00828470_cls* obj = new FUN_00828470_cls((void*)m_28, (void*)m_08, (void*)m_0c);
    FUN_00806d50(obj);
    obj->m_4c = m_4c;
    obj->m_50 = m_50;
    obj->m_54 = m_54;
    obj->m_58 = m_58;
    obj->m_64 = m_64;
    obj->m_70 = m_70;
    if (m_71 != 0 && obj->m_71 == 0 && FUN_0044ddc0())
    {
        FUN_0044ddc0()->FUN_0040a420(0);
    }
    obj->m_71 = m_71;
    return obj;
}
}  // namespace fnv_00828610

class B828760Task
{
  public:
    B828760Task(void* pvOwner, void* pvTarget, int iType);

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
};

// Allocates and constructs a B828760Task from an owner, a target and a type, returning the new task.
// @fnv 0x00828760
B828760Task* __cdecl FUN_00828760(void* pvOwner, void* pvTarget, int iType)
{
    return new B828760Task(pvOwner, pvTarget, iType);
}

struct FxnNode;

struct FxnObj
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
    virtual void v49(int a);
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
    virtual bool v139(int a);
    FxnNode* FUN_008d8520();
    void FUN_0089d900(int a, float f);
};

struct FxnNode
{
    FxnNode* FUN_00822b40();
    int FUN_0045cd60();
    void FUN_008feab0(FxnObj* obj);
    void FUN_0040b800(int a);
};

void __cdecl FUN_0080b9e0(FxnObj* obj, FxnNode* node, int flag);

struct FUN_008289e0_cls : public SummonCreatureEffect
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
    FxnObj* m_4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    unsigned char unk70;
    unsigned char m_71;
    FxnNode* FUN_0059bb30();
    FxnNode* FUN_0044ddc0();
    void CleanupSummonedCreature();
};

// @fnv 0x008289e0
void FUN_008289e0_cls::CleanupSummonedCreature()
{
    FxnNode* a = (this->FUN_0059bb30() != 0) ? this->FUN_0059bb30()->FUN_00822b40() : 0;
    if (this->m_4c != 0 && a != 0)
    {
        if (this->m_4c->FUN_008d8520() != 0 && this->m_4c->FUN_008d8520()->FUN_0045cd60() == 0)
        {
            if (!this->m_4c->v139(0))
            {
                this->m_4c->FUN_0089d900(0, 0.0f);
            }
            this->m_4c->FUN_008d8520()->FUN_008feab0(this->m_4c);
            FUN_0080b9e0(this->m_4c, a, 1);
        }
        else
        {
            FUN_0080b9e0(this->m_4c, a, 1);
            this->m_4c->v49(1);
        }
        this->m_4c = 0;
    }
    if (this->m_71 != 0 && this->FUN_0044ddc0() != 0)
    {
        this->FUN_0044ddc0()->FUN_0040b800(0);
        this->m_71 = 0;
    }
}

extern int g_011dcc58;
float __cdecl ComputeDirectionalFalloff(int owner, int key);

// Looks up two float values by id from g_011dcc58 and returns 0 if equal, 1 if the first is smaller, -1 otherwise.
// @fnv 0x00828b20
int __cdecl FUN_00828b20(int aiIdA, int aiIdB)
{
    int idA = aiIdA;
    int idB = aiIdB;
    float valueA = ComputeDirectionalFalloff(g_011dcc58, idA);
    float valueB = ComputeDirectionalFalloff(g_011dcc58, idB);
    if (valueA == valueB)
    {
        return 0;
    }
    else if (valueA < valueB)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

struct S_00828ba0_Actor;
struct S_00828ba0_Target
{
    virtual ~S_00828ba0_Target();
    virtual int vfn00();
    virtual int vfn01();
    virtual int vfn02();
    virtual int vfn03();
    virtual int vfn04();
    virtual int vfn05();
    virtual int vfn06();
    virtual int vfn07();
    virtual int vfn08();
    virtual int vfn09();
    virtual int vfn0a();
    virtual int vfn0b();
    virtual int vfn0c();
    virtual int vfn0d();
    virtual int vfn0e();
    virtual int vfn0f();
    virtual int vfn10();
    virtual int vfn11();
    virtual int vfn12();
    virtual int vfn13();
    virtual int vfn14();
    virtual int vfn15();
    virtual int vfn16();
    virtual int vfn17();
    virtual int vfn18();
    virtual int vfn19();
    virtual int vfn1a();
    virtual int vfn1b();
    virtual int vfn1c();
    virtual int vfn1d();
    virtual int vfn1e();
    virtual int vfn1f();
    virtual int vfn20();
    virtual int vfn21();
    virtual int vfn22();
    virtual int vfn23();
    virtual int vfn24();
    virtual int vfn25();
    virtual int vfn26();
    virtual int vfn27();
    virtual int vfn28();
    virtual int vfn29();
    virtual int vfn2a();
    virtual int vfn2b();
    virtual int vfn2c();
    virtual int vfn2d();
    virtual int vfn2e();
    virtual int vfn2f();
    virtual int vfn30();
    virtual int vfn31();
    virtual int vfn32();
    virtual int vfn33();
    virtual int vfn34();
    virtual int vfn35();
    virtual int vfn36();
    virtual int vfn37();
    virtual int vfn38();
    virtual int vfn39();
    virtual int vfn3a();
    virtual int vfn3b();
    virtual int vfn3c();
    virtual int vfn3d();
    virtual int vfn3e();
    virtual int vfn3f();
    virtual int vfn40();
    virtual int vfn41();
    virtual int vfn42();
    virtual int vfn43();
    virtual int vfn44();
    virtual int vfn45();
    virtual int vfn46();
    virtual int vfn47();
    virtual int vfn48();
    virtual int vfn49();
    virtual int vfn4a();
    virtual int vfn4b();
    virtual int vfn4c();
    virtual int vfn4d();
    virtual int vfn4e();
    virtual int vfn4f();
    virtual int vfn50();
    virtual int vfn51();
    virtual int vfn52();
    virtual int vfn53();
    virtual int vfn54();
    virtual int vfn55();
    virtual int vfn56();
    virtual int vfn57();
    virtual int vfn58();
    virtual int vfn59();
    virtual int vfn5a();
    virtual int vfn5b();
    virtual int vfn5c();
    virtual int vfn5d();
    virtual int vfn5e();
    virtual int vfn5f();
    virtual int vfn60();
    virtual int vfn61();
    virtual int vfn62();
    virtual int vfn63();
    virtual int vfn64();
    virtual int vfn65();
    virtual int vfn66();
    virtual int vfn67();
    virtual int vfn68();
    virtual int vfn69();
    virtual int vfn6a();
    virtual int vfn6b();
    virtual int vfn6c();
    virtual int vfn6d();
    virtual int vfn6e();
    virtual int vfn6f();
    virtual int vfn70();
    virtual int vfn71();
    virtual int vfn72();
    virtual int vfn73();
    virtual int vfn74();
    virtual int vfn75();
    virtual int vfn76();
    virtual int vfn77();
    virtual int vfn78();
    virtual int vfn79();
    virtual int vfn7a();
    virtual int vfn7b();
    virtual int vfn7c();
    virtual int vfn7d();
    virtual int vfn7e();
    virtual int vfn7f();
    virtual int vfn80();
    virtual int vfn81();
    virtual int vfn82();
    virtual int vfn83();
    virtual int vfn84();
    virtual int vfn85();
    virtual int vfn86();
    virtual int vfn87();
    virtual int vfn88();
    virtual int vfn89();
    virtual bool vfn8b(int a);
};

struct S_00828ba0_Owner
{
    S_00828ba0_Actor* FUN_00822b40();
};

struct S_00828ba0 : SummonCreatureEffect
{
    float m_04;
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
    S_00828ba0_Target* m_4c;
    int unk50;
    float m_54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    unsigned char m_70;
    S_00828ba0_Owner* FUN_0059bb30();
    void Remove(int a);
    void SpawnSummonedActor(S_00828ba0_Actor* actor);
    void DispelOldestQualifyingEffect();
    void FUN_00828ba0(int unused);
};
void __cdecl FUN_0080b8f0(S_00828ba0_Target* t, S_00828ba0_Actor* actor);
extern S_00828ba0_Actor* DAT_011dea3c;

// @fnv 0x00828ba0
void S_00828ba0::FUN_00828ba0(int unused)
{
    S_00828ba0_Actor* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!actor || (m_70 && (!m_4c || m_4c->vfn8b(0))))
    {
        Remove(0);
        return;
    }
    if (m_04 >= m_54 && !m_70)
    {
        SpawnSummonedActor(actor);
        if (actor == DAT_011dea3c)
            DispelOldestQualifyingEffect();
        m_70 = 1;
    }
    if (m_4c && !m_4c->vfn8b(0))
        FUN_0080b8f0(m_4c, actor);
}

extern float DAT_0101b2d0;
extern float DAT_01013d84;
extern double DAT_01011588;

struct S_00828dc0_Vec3
{
    float x, y, z;
    float FUN_00457990();
    void FUN_004a0c10();
};

struct S_00828dc0_Mat;
struct S_00828dc0_Mat
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    void FUN_004a0c90(float z);
    void FUN_004b45b0(S_00828dc0_Mat* out);
};

extern S_00828dc0_Mat DAT_011a9448;

struct S_00828dc0_Obj
{
    void FUN_00439ef0(S_00828dc0_Vec3* out, int x);
};

struct S_00828dc0_Actor
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual int vf1f4();
    S_00828dc0_Vec3* FUN_00430830();
};

void FUN_004b3ae0(S_00828dc0_Vec3* out, const S_00828dc0_Vec3* v, const S_00828dc0_Mat* m);
float FUN_00408820(float f);

// @fnv 0x00828dc0
float ComputeDirectionalFalloff(S_00828dc0_Actor* actor, S_00828dc0_Obj* obj)
{
    float low = DAT_0101b2d0;
    float high = DAT_01013d84;
    S_00828dc0_Vec3 delta;
    obj->FUN_00439ef0(&delta, actor->vf1f4());
    float dist = delta.FUN_00457990();
    float scale = 1.0f;
    if (dist < low)
        scale = dist / low;
    else if (dist < high)
        scale = (high - dist) / (high - low);
    else
        scale = 0.0f;
    S_00828dc0_Vec3 rot = *actor->FUN_00430830();
    S_00828dc0_Mat matrix = DAT_011a9448;
    matrix.FUN_004a0c90(rot.z);
    S_00828dc0_Mat mInv;
    matrix.FUN_004b45b0(&mInv);
    S_00828dc0_Vec3 localDir;
    FUN_004b3ae0(&localDir, &delta, &matrix);
    localDir.FUN_004a0c10();
    float x = 1.0f - FUN_00408820(localDir.x);
    x = x * x;
    float fy = (1.0f + localDir.y) * DAT_01011588;
    return scale * x * fy;
}

struct RegistrationManager
{
    void FUN_00857a10(const void*, unsigned int);
    void FUN_008579b0(void*, unsigned int);
};
extern RegistrationManager* g_registrationManager;

struct OptionalState
{
    int FUN_0084e3a0();
};

struct FUN_008297a0_shell : public SummonCreatureEffect
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
    OptionalState* unk4c;
    char unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;

    void FUN_00806de0(int);
    void FUN_008297a0(int);
};

// @fnv 0x008297a0
void FUN_008297a0_shell::FUN_008297a0(int value)
{
    FUN_00806de0(value);
    int id = 0;
    if (unk4c != 0)
        id = unk4c->FUN_0084e3a0();
    g_registrationManager->FUN_00857a10(&id, 4);
    g_registrationManager->FUN_008579b0(&unk50, 1);
    if (unk4c == 0)
    {
        g_registrationManager->FUN_008579b0(&unk54, 4);
        g_registrationManager->FUN_008579b0(&unk58, 12);
        g_registrationManager->FUN_008579b0(&unk64, 12);
    }
}

struct S_008294e0_Point
{
    float x, y, z;
};

struct S_008294e0_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    ~S_008294e0_Str();
    const char* FUN_00559450();
};

struct S_008294e0_Named
{
    S_008294e0_Str AssignFromSub();
};

struct TESForm
{
    virtual ~TESForm();
};
struct TESBoundObject : TESForm
{
};

struct S_008294e0_Proc
{
    virtual void vp_000();
    virtual void vp_004();
    virtual void vp_008();
    virtual void vp_00C();
    virtual void vp_010();
    virtual void vp_014();
    virtual void vp_018();
    virtual void vp_01C();
    virtual void vp_020();
    virtual void vp_024();
    virtual void vp_028();
    virtual void vp_02C();
    virtual void vp_030();
    virtual void vp_034();
    virtual void vp_038();
    virtual void vp_03C();
    virtual void vp_040();
    virtual void vp_044();
    virtual void vp_048();
    virtual void vp_04C();
    virtual void vp_050();
    virtual void vp_054();
    virtual void vp_058();
    virtual void vp_05C();
    virtual void vp_060();
    virtual void vp_064();
    virtual void vp_068();
    virtual void vp_06C();
    virtual void vp_070();
    virtual void vp_074();
    virtual void vp_078();
    virtual void vp_07C();
    virtual void vp_080();
    virtual void vp_084();
    virtual void vp_088();
    virtual void vp_08C();
    virtual void vp_090();
    virtual void vp_094();
    virtual void vp_098();
    virtual void vp_09C();
    virtual void vp_0A0();
    virtual void vp_0A4();
    virtual void vp_0A8();
    virtual void vp_0AC();
    virtual void vp_0B0();
    virtual void vp_0B4();
    virtual void vp_0B8();
    virtual void vp_0BC();
    virtual void vp_0C0();
    virtual void vp_0C4();
    virtual void vp_0C8();
    virtual void vp_0CC();
    virtual void vp_0D0();
    virtual void vp_0D4();
    virtual void vp_0D8();
    virtual void vp_0DC();
    virtual void vp_0E0();
    virtual void vp_0E4();
    virtual void vp_0E8();
    virtual void vp_0EC();
    virtual void vp_0F0();
    virtual void vp_0F4();
    virtual void vp_0F8();
    virtual void vp_0FC();
    virtual void vp_100();
    virtual void vp_104();
    virtual void vp_108();
    virtual void vp_10C();
    virtual void vp_110();
    virtual void vp_114();
    virtual void vp_118();
    virtual void vp_11C();
    virtual void vp_120();
    virtual void vp_124();
    virtual void vp_128();
    virtual void vp_12C();
    virtual void vp_130();
    virtual void vp_134();
    virtual void vp_138();
    virtual void vp_13C();
    virtual void vp_140();
    virtual void vp_144();
    virtual void vp_148();
    virtual void vp_14C();
    virtual void vp_150();
    virtual void vp_154();
    virtual void vp_158();
    virtual void vp_15C();
    virtual void vp_160();
    virtual void vp_164();
    virtual void vp_168();
    virtual void vp_16C();
    virtual void vp_170();
    virtual void vp_174();
    virtual void vp_178();
    virtual void vp_17C();
    virtual void vp_180();
    virtual void vp_184();
    virtual void vp_188();
    virtual void vp_18C();
    virtual void vp_190();
    virtual void vp_194();
    virtual void vp_198();
    virtual void vp_19C();
    virtual void vp_1A0();
    virtual void vp_1A4();
    virtual void vp_1A8();
    virtual void vp_1AC();
    virtual void vp_1B0();
    virtual void vp_1B4();
    virtual void vp_1B8();
    virtual void vp_1BC();
    virtual void vp_1C0();
    virtual void vp_1C4();
    virtual void vp_1C8();
    virtual void vp_1CC();
    virtual void vp_1D0();
    virtual void vp_1D4();
    virtual void vp_1D8();
    virtual void vp_1DC();
    virtual void vp_1E0();
    virtual void vp_1E4();
    virtual void vp_1E8();
    virtual void vp_1EC();
    virtual void vp_1F0();
    virtual void vp_1F4();
    virtual void vp_1F8();
    virtual void vp_1FC();
    virtual void vp_200();
    virtual void vp_204();
    virtual void vp_208();
    virtual void vp_20C();
    virtual void vp_210();
    virtual void vp_214();
    virtual void vp_218();
    virtual void vp_21C();
    virtual void vp_220();
    virtual void vp_224();
    virtual void vp_228();
    virtual void vp_22C();
    virtual void vp_230();
    virtual void vp_234();
    virtual void vp_238();
    virtual void vp_23C();
    virtual void vp_240();
    virtual void vp_244();
    virtual void vp_248();
    virtual void vp_24C();
    virtual void vp_250();
    virtual void vp_254();
    virtual void vp_258();
    virtual void vp_25C();
    virtual void vp_260();
    virtual void vp_264();
    virtual void vp_268();
    virtual void vp_26C();
    virtual void vp_270();
    virtual void vp_274();
    virtual void vp_278();
    virtual void vp_27C();
    virtual void vp_280();
    virtual void vp_284();
    virtual void vp_288();
    virtual void vp_28C();
    virtual void vp_290();
    virtual void vp_294();
    virtual void vp_298();
    virtual void vp_29C();
    virtual void vp_2A0();
    virtual void vp_2A4();
    virtual void vp_2A8();
    virtual void vp_2AC();
    virtual void vp_2B0();
    virtual void vp_2B4();
    virtual void vp_2B8();
    virtual void vp_2BC();
    virtual void vp_2C0();
    virtual void vp_2C4();
    virtual void vp_2C8();
    virtual void vp_2CC();
    virtual void vp_2D0();
    virtual void vp_2D4();
    virtual void vp_2D8();
    virtual void vp_2DC();
    virtual void vp_2E0();
    virtual void vp_2E4();
    virtual void vp_2E8();
    virtual void vp_2EC();
    virtual void vp_2F0();
    virtual void vp_2F4();
    virtual void vp_2F8();
    virtual void vp_2FC();
    virtual void vp_300();
    virtual void vp_304();
    virtual void vp_308();
    virtual void vp_30C();
    virtual void vp_310();
    virtual void vp_314();
    virtual void vp_318();
    virtual void vp_31C();
    virtual void vp_320();
    virtual void vp_324();
    virtual void vp_328();
    virtual void vp_32C();
    virtual void vp_330();
    virtual void vp_334();
    virtual void vp_338();
    virtual void vp_33C();
    virtual void vp_340();
    virtual void vp_344();
    virtual void vp_348();
    virtual void vp_34C();
    virtual void vp_350();
    virtual void vp_354();
    virtual void vp_358();
    virtual void vp_35C();
    virtual void vp_360();
    virtual void vp_364();
    virtual void vp_368();
    virtual void vp_36C();
    virtual void vp_370();
    virtual void vp_374();
    virtual void vp_378();
    virtual void vp_37C();
    virtual void vp_380();
    virtual void vp_384();
    virtual void vp_388();
    virtual void vp_38C();
    virtual void vp_390();
    virtual void vp_394();
    virtual void vp_398();
    virtual void vp_39C();
    virtual void vp_3A0();
    virtual void vp_3A4();
    virtual void vp_3A8();
    virtual void vp_3AC();
    virtual void vp_3B0();
    virtual void vp_3B4();
    virtual void vp_3B8();
    virtual void vp_3BC();
    virtual void vp_3C0();
    virtual void vp_3C4();
    virtual void vp_3C8();
    virtual void vp_3CC();
    virtual void vp_3D0();
    virtual void vp_3D4();
    virtual void vp_3D8();
    virtual void vp_3DC();
    virtual void vp_3E0();
    virtual void vp_3E4();
    virtual void vp_3E8();
    virtual void vp_3EC();
    virtual void vp_3F0();
    virtual void vp_3F4();
    virtual void vp_3F8();
    virtual void vp_3FC();
    virtual void vp_400();
    virtual void vp_404();
    virtual void vp_408();
    virtual void vp_40C();
    virtual void vp_410();
    virtual void vp_414();
    virtual void vp_418();
    virtual void vp_41C();
    virtual void vp_420();
    virtual void vp_424();
    virtual void vp_428();
    virtual void vp_42C();
    virtual void vp_430();
    virtual void vp_434();
    virtual void vp_438();
    virtual void vp_43C();
    virtual void vp_440();
    virtual void vp_444();
    virtual void vp_448();
    virtual void vp_44C();
    virtual void vp_450();
    virtual void vp_454();
    virtual void vp_458();
    virtual void vp_45C();
    virtual void vp_460();
    virtual void vp_464();
    virtual void vp_468();
    virtual void vp_46C();
    virtual void vp_470();
    virtual void vp_474();
    virtual void vp_478();
    virtual void vp_47C();
    virtual void vp_480();
    virtual void vp_484();
    virtual void vp_488();
    virtual void vp_48C();
    virtual void vp_490();
    virtual void vp_494();
    virtual void vp_498();
    virtual void vp_49C();
    virtual void vp_4A0();
    virtual void vp_4A4();
    virtual void vp_4A8();
    virtual void vp_4AC();
    virtual void vp_4B0();
    virtual void vp_4B4();
    virtual void vp_4B8();
    virtual void vp_4BC();
    virtual void vp_4C0();
    virtual void vp_4C4();
    virtual void vp_4C8();
    virtual void vp_4CC();
    virtual void vp_4D0();
    virtual void vp_4D4();
    virtual void vp_4D8();
    virtual void vp_4DC();
    virtual void vp_4E0();
    virtual void vp_4E4();
    virtual void vp_4E8();
    virtual void vp_4EC();
    virtual void vp_4F0();
    virtual void vp_4F4();
    virtual void vp_4F8();
    virtual void vp_4FC();
    virtual void vp_500();
    virtual void vp_504();
    virtual void vp_508();
    virtual void vp_50C();
    virtual void vp_510();
    virtual void vp_514();
    virtual void vp_518();
    virtual void vp_51C();
    virtual void vp_520();
    virtual void vp_524();
    virtual void vp_528();
    virtual void vp_52C();
    virtual void vp_530();
    virtual void vp_534();
    virtual void vp_538();
    virtual void vp_53C();
    virtual void vp_540();
    virtual void vp_544();
    virtual void vp_548();
    virtual void vp_54C();
    virtual void vp_550();
    virtual void vp_554();
    virtual void vp_558();
    virtual void vp_55C();
    virtual void vp_560();
    virtual void vp_564();
    virtual void vp_568();
    virtual void vp_56C();
    virtual void vp_570();
    virtual void vp_574();
    virtual void vp_578();
    virtual void vp_57C();
    virtual void vp_580();
    virtual void vp_584();
    virtual void vp_588();
    virtual void vp_58C();
    virtual void vp_590();
    virtual void vp_594();
    virtual void vp_598();
    virtual void vp_59C();
    virtual void vp_5A0();
    virtual void vp_5A4();
    virtual void vp_5A8();
    virtual void vp_5AC();
    virtual void vp_5B0();
    virtual void vp_5B4();
    virtual void vp_5B8();
    virtual void vp_5BC();
    virtual void vp_5C0();
    virtual void vp_5C4();
    virtual void vp_5C8();
    virtual void vp_5CC();
    virtual void vp_5D0();
    virtual void vp_5D4();
    virtual void vp_5D8();
    virtual void vp_5DC();
    virtual void vp_5E0();
    virtual void vp_5E4();
    virtual void vp_5E8();
    virtual void vp_5EC();
    virtual void vp_5F0();
    virtual void vp_5F4();
    virtual void vp_5F8();
    virtual void vp_5FC();
    virtual void vp_600();
    virtual void vp_604();
    virtual void vp_608();
    virtual void vp_60C();
    virtual void vp_610();
    virtual void vp_614();
    virtual void vp_618();
    virtual void vp_61C();
    virtual void vp_620();
    virtual void vp_624();
    virtual void vp_628();
    virtual void vp_62C();
    virtual void vp_630();
    virtual void vp_634();
    virtual void vp_638();
    virtual void vp_63C();
    virtual void vp_640();
    virtual void vp_644();
    virtual void vp_648();
    virtual void vp_64C();
    virtual void vp_650();
    virtual void vp_654();
    virtual void vp_658();
    virtual void vp_65C();
    virtual void vp_660();
    virtual void vp_664();
    virtual void vp_668();
    virtual void vp_66C();
    virtual void vp_670();
    virtual void vp_674();
    virtual void vp_678();
    virtual void vp_67C();
    virtual void vp_680();
    virtual void vp_684();
    virtual void vp_688();
    virtual void vp_68C();
    virtual void vp_690();
    virtual void SetSomething(int a);
};

struct S_008294e0_Actor;
struct S_008294e0_Ref
{
    virtual void vr_000();
    virtual void vr_004();
    virtual void vr_008();
    virtual void vr_00C();
    virtual void vr_010();
    virtual void vr_014();
    virtual void vr_018();
    virtual void vr_01C();
    virtual void vr_020();
    virtual void vr_024();
    virtual void vr_028();
    virtual void vr_02C();
    virtual void vr_030();
    virtual void vr_034();
    virtual void vr_038();
    virtual void vr_03C();
    virtual void vr_040();
    virtual void vr_044();
    virtual void vr_048();
    virtual void vr_04C();
    virtual void vr_050();
    virtual void vr_054();
    virtual void vr_058();
    virtual void vr_05C();
    virtual void vr_060();
    virtual void vr_064();
    virtual void vr_068();
    virtual void vr_06C();
    virtual void vr_070();
    virtual void vr_074();
    virtual void vr_078();
    virtual void vr_07C();
    virtual void vr_080();
    virtual void vr_084();
    virtual void vr_088();
    virtual void vr_08C();
    virtual void vr_090();
    virtual void vr_094();
    virtual void vr_098();
    virtual void vr_09C();
    virtual void vr_0A0();
    virtual void vr_0A4();
    virtual void vr_0A8();
    virtual void vr_0AC();
    virtual void vr_0B0();
    virtual void vr_0B4();
    virtual void vr_0B8();
    virtual void vr_0BC();
    virtual void vr_0C0();
    virtual void vr_0C4();
    virtual void vr_0C8();
    virtual void vr_0CC();
    virtual void vr_0D0();
    virtual void vr_0D4();
    virtual void vr_0D8();
    virtual void vr_0DC();
    virtual void vr_0E0();
    virtual void vr_0E4();
    virtual void vr_0E8();
    virtual void vr_0EC();
    virtual void vr_0F0();
    virtual void vr_0F4();
    virtual void vr_0F8();
    virtual void vr_0FC();
    virtual bool IsActor();
    virtual void vr_104();
    virtual void vr_108();
    virtual void vr_10C();
    virtual void vr_110();
    virtual void vr_114();
    virtual void vr_118();
    virtual void vr_11C();
    virtual void vr_120();
    virtual void vr_124();
    virtual void vr_128();
    virtual void vr_12C();
    virtual void vr_130();
    virtual void vr_134();
    virtual void vr_138();
    virtual void vr_13C();
    virtual void vr_140();
    virtual void vr_144();
    virtual void vr_148();
    virtual void vr_14C();
    virtual void vr_150();
    virtual void vr_154();
    virtual void vr_158();
    virtual void vr_15C();
    virtual void vr_160();
    virtual void vr_164();
    virtual void vr_168();
    virtual void vr_16C();
    virtual void vr_170();
    virtual void vr_174();
    virtual void vr_178();
    virtual void vr_17C();
    virtual void vr_180();
    virtual void vr_184();
    virtual void vr_188();
    virtual void vr_18C();
    virtual void vr_190();
    virtual void vr_194();
    virtual void vr_198();
    virtual void vr_19C();
    virtual void vr_1A0();
    virtual void vr_1A4();
    virtual void vr_1A8();
    virtual void vr_1AC();
    virtual void vr_1B0();
    virtual void vr_1B4();
    virtual void vr_1B8();
    virtual void vr_1BC();
    virtual void vr_1C0();
    virtual void vr_1C4();
    virtual void vr_1C8();
    virtual void vr_1CC();
    virtual void vr_1D0();
    virtual void vr_1D4();
    virtual void vr_1D8();
    virtual void vr_1DC();
    virtual void vr_1E0();
    virtual void vr_1E4();
    virtual void vr_1E8();
    virtual void vr_1EC();
    virtual void vr_1F0();
    virtual void vr_1F4();
    virtual void vr_1F8();
    virtual void vr_1FC(int a);
    virtual void vr_200();
    virtual void vr_204();
    virtual void vr_208();
    virtual void vr_20C();
    virtual void vr_210();
    virtual void vr_214();
    virtual void vr_218();
    virtual void vr_21C();
    virtual void vr_220();
    virtual void vr_224();
    virtual void vr_228();
    virtual void vr_22C();
    virtual void vr_230();
    virtual void vr_234();
    virtual void vr_238();
    virtual void vr_23C();
    virtual void vr_240();
    virtual void vr_244();
    virtual void vr_248();
    virtual void vr_24C();
    virtual void vr_250();
    virtual void vr_254();
    virtual void vr_258();
    virtual void vr_25C();
    virtual void vr_260();
    bool FUN_00564930(int a);
    void FUN_00575830(S_008294e0_Point* pos);
    S_008294e0_Proc* FUN_008d8520();
};

struct S_008294e0_Actor
{
    int FUN_00575d70();
    int FUN_008d6f30(int a);
    const char* FUN_0055d520();
};

struct S_008294e0_Target
{
    S_008294e0_Actor* FUN_00822b40();
};

struct S_008294e0_Handler
{
    S_008294e0_Ref* PlaceObjectReference(TESBoundObject* obj, S_008294e0_Point* pos, S_008294e0_Point* rot, int cell,
                                         int a, int b, int c);
};
extern S_008294e0_Handler* DAT_011c3f2c;

void __cdecl FUN_005b5e40(const char* fmt, ...);
void __cdecl StartHostilityAndCombat(S_008294e0_Ref* ref, S_008294e0_Actor* actor);

struct S_008294e0_Effect
{
    S_008294e0_Target* FUN_0059bb30();
    TESForm* FUN_006733e0();
    S_008294e0_Named* FUN_007df1d0();
};

struct S_008294e0_Summon : S_008294e0_Effect
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    S_008294e0_Ref* unk4C;
    int unk50, unk54;
    S_008294e0_Point unk58;
    S_008294e0_Point unk64;
    void SpawnSummonedActor(int unused);
};

// @fnv 0x008294e0
void S_008294e0_Summon::SpawnSummonedActor(int unused)
{
    S_008294e0_Actor* actor = FUN_0059bb30() ? FUN_0059bb30()->FUN_00822b40() : 0;
    if (!actor)
        return;
    S_008294e0_Ref* ref;
    TESBoundObject* pCreatureForm = dynamic_cast<TESBoundObject*>(FUN_006733e0());
    if (!pCreatureForm)
    {
        FUN_005b5e40("GAME EFFECTS: %s effect has no associated creature.",
                     FUN_007df1d0()->AssignFromSub().FUN_00559450());
    }
    else
    {
        ref = DAT_011c3f2c->PlaceObjectReference(pCreatureForm, &unk58, &unk64,
                                                 actor->FUN_008d6f30(actor->FUN_00575d70()), 0, 0, 0);
        if (ref)
        {
            if (ref->IsActor())
            {
                unk4C = ref;
                unk4C->FUN_00575830(&unk58);
                unk4C->vr_1FC(0);
                unk4C->vr_260();
                StartHostilityAndCombat(unk4C, actor);
                unk4C->FUN_008d8520()->SetSomething(1);
            }
            else
            {
                FUN_005b5e40("GAME EFFECTS: %s summoned a non-actor.", actor->FUN_0055d520());
                ref->FUN_00564930(1);
            }
        }
        else if (!pCreatureForm)
        {
            FUN_005b5e40("DEFAULT: %s effect unable to create reference.",
                         FUN_007df1d0()->AssignFromSub().FUN_00559450());
        }
    }
}

struct DbeffectBaseCall
{
    void FUN_00806e70(void*);
};

TESForm* __cdecl LookupFormByID(unsigned int);
struct Dbeffect : SummonCreatureEffect
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
    int formId;
    void FUN_00829900(void* arg);
};
// Calls the base handler, resolves formId to an Actor via LookupFormByID, and dispels the effect if the lookup fails.
// @fnv 0x00829900
void Dbeffect::FUN_00829900(void* arg)
{
    ((DbeffectBaseCall*)this)->FUN_00806e70(arg);
    int iFormId = formId;
    if (iFormId)
    {
        formId = (int)dynamic_cast<Actor*>(LookupFormByID((unsigned int)iFormId));
        if (!formId)
            ((ActiveEffect*)this)->Dispel(true);
    }
}
