
// src/fallout/magic/dispeleffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/dispeleffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ActiveEffect
{
    void CopyData(ActiveEffect*);
};

struct DispelEffect : ActiveEffect
{
    void FUN_00829b90(ActiveEffect*);
};

// @fnv 0x00829b90
void DispelEffect::FUN_00829b90(ActiveEffect* apDestination)
{
    ActiveEffect::CopyData(apDestination);
}

struct MagicTarget
{
    virtual ~MagicTarget()
    {}
};
struct Character : MagicTarget
{
};
struct FUN_0082d060_shell
{
    bool IsCharacter(MagicTarget* apTarget);
};
// Returns true if apTarget is a Character, using a dynamic_cast.
// @fnv 0x0082d060
bool FUN_0082d060_shell::IsCharacter(MagicTarget* apTarget)
{
    return dynamic_cast<Character*>(apTarget) != 0;
}

void* operator new(unsigned int size) throw();

struct SpawnedEffect
{
    unsigned int unk00[18];
    SpawnedEffect(int a, int b, int c);
};

struct FUN_0080d950_cls
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
    virtual ActiveEffect* HookEffect(ActiveEffect* e);

    int unk04;
    int m_08;
    int m_0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;

    ActiveEffect* CreateAndHookEffect();
};

// Allocates a SpawnedEffect from m_28, m_08 and m_0C, hooks it via HookEffect, and returns it as an ActiveEffect.
// @fnv 0x0080d950
ActiveEffect* FUN_0080d950_cls::CreateAndHookEffect()
{
    ActiveEffect* e = (ActiveEffect*)new SpawnedEffect(m_28, m_08, m_0C);
    HookEffect(e);
    return e;
}

struct FUN_0080da00_cls;
struct ItemObj;

struct SubObj
{
    virtual void s0();
    virtual void s1();
    virtual float s2(void* p);
};

struct HolderObj
{
    virtual void h0();
    virtual void h1();
    virtual ItemObj* h2();
};

struct ItemObj
{
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6();
    int m_04;
    int m_08;
    SubObj m_0c;

    bool FUN_008256d0();
    ItemObj** FUN_006815c0();
    ItemObj* FUN_00726070();
    ItemObj* FUN_0044ddc0();
    void Remove(int arg);
    ItemObj* FUN_00815410();
};

struct DatObj
{
    float* FUN_00403e20();
};
extern DatObj DAT_011d1b20;

struct FUN_0080da00_cls
{
    HolderObj* FUN_0059bb30();
    FUN_0080da00_cls* FUN_0084e3a0();
    ItemObj* FUN_0045cd60();
    float GetFloatAtOffset1C();

    void UpdateItems();
};

// @fnv 0x0080da00
void FUN_0080da00_cls::UpdateItems()
{
    ItemObj* cur = FUN_0059bb30()->h2();
    bool b9 = FUN_0084e3a0()->FUN_0084e3a0() == 0;
    ItemObj* x = FUN_0045cd60() ? FUN_0045cd60()->FUN_00815410() : 0;
    while (cur != 0 && !cur->FUN_008256d0())
    {
        ItemObj* t5 = *cur->FUN_006815c0();
        ItemObj* nextItem = cur->FUN_00726070();
        if (t5 != 0 && (void*)t5 != (void*)this)
        {
            ItemObj* u2 = t5->FUN_0044ddc0();
            if (u2->i6() == 0)
            {
                if (u2->m_0c.s2(b9 ? x : 0) <= GetFloatAtOffset1C() * *DAT_011d1b20.FUN_00403e20())
                    t5->Remove(0);
            }
        }
        cur = nextItem;
    }
}
