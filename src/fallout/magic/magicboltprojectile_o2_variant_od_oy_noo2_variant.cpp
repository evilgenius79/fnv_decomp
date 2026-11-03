
// src/fallout/magic/magicboltprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/magicboltprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magicboltprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicboltprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/magicboltprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicboltprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct RefH
{
    bool IsDeleted() const;
};
struct FUN_00811930_shell : RefH
{
    bool IsNotDeleted() const;
};
extern int DAT_011ae61c;
void FUN_00811e00(int value);
struct FUN_008133d0_shell
{
    void FUN_008133d0(int value);
};

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    bool FUN_00ad8ce0();
    void FUN_00ad8d10();
    bool SetPos(float, float, float);
    void SetNiNode(void*);
    bool Play(bool);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
    float* FUN_00403e20();
};
extern xFltSetting xg_11d16f8;
extern xFltSetting xg_11d1c28;
extern const float xg_107a8b0;
extern xFltSetting xg_11d1ae4;
extern xFltSetting xg_11d1758;
struct xIntSetting
{
    int* FUN_0043d4d0();
};
extern xIntSetting xg_11d16ec;
void xFUN_00811e00(int);
struct xPtr
{
    xPtr(int);
    ~xPtr();
    void FUN_0066b0d0(void*);
    void* FUN_00559450();
    void* m_p;
};
int xFUN_0081e440(void*);
struct xNodeA
{
    bool FUN_00456610();
};
struct xPC
{
    xNodeA* FUN_00950bb0(bool);
};
extern xPC* xg_pc_11dea3c;
struct xAudio
{
    static xAudio* FUN_00453a70();
    struct xSound FUN_00ad73b0(void*, unsigned int);
};
struct xRefList
{
    void FUN_005ae3d0(void* const&);
};
struct xDH
{
    xRefList* GetOffset70Ptr();
};
extern xDH xg_11e0e80;
void xFUN_0080fae0(float);
struct xRadius
{
    float FUN_009b0bd0();
};
struct xSndForm
{
    void* FUN_0084e3a0();
};
struct xEffect
{
    xSndForm* FUN_004fd3c0();
};
struct xCtl
{
    void FUN_0080fb00(xVec4*);
};
struct xCell
{
    void FUN_00548230(void*, bool);
};
struct xOwner
{
    void FUN_0081c4a0(void*);
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(int, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
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
    virtual void* FUN_2c();
};

extern void* xg_player_11dea3c;
struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    xPtr m_a8;
    int m_ac;
    int m_b0;
    xPtr m_b4;
    xPtr m_b8;
    xPtr m_bc;
    xPtr m_c0;
    int m_c4;
    xSound m_c8;
    float m_d4;
    xProj(xActorV* apA, int b, int c, int d, xP3 kP1, xP3 kP2);
    xEffect* FUN_004fd400();
    void FUN_008133d0(int);
    xP3* FUN_00436aa0();
    void FUN_00575830(const xP3&);
    void InitEffect();
    void FUN_00570f70(void*);
    void FUN_00813f30();
    xCtl* FUN_009306d0();
    xCell* FUN_008d6f30();
    void FUN_0081eba0();
    xActorV* FUN_009185e0();
};
// @fnv 0x00811980
xProj::xProj(xActorV* apA, int b, int c, int d, xP3 kP1, xP3 kP2)
    : xBase((int)apA, b, c, d, kP1, kP2), m_a8(0), m_b4(0), m_b8(0), m_bc(0), m_c0(0)
{
    xFUN_00811e00(*xg_11d16ec.FUN_0043d4d0());
    FUN_008133d0(0);
    m_88 = ((xRadius*)FUN_004fd400())->FUN_009b0bd0() * *xg_11d16f8.FUN_00403e20();
    m_b0 = 0;
    m_c4 = 0;
    m_d4 = 0.0f;
    if (apA->FUN_2c() == xg_player_11dea3c && xg_pc_11dea3c->FUN_00950bb0(true) &&
        !xg_pc_11dea3c->FUN_00950bb0(true)->FUN_00456610())
    {
        xP3 POS = *FUN_00436aa0();
        POS.z = POS.z + *xg_11d1ae4.FUN_00403e20();
        FUN_00575830(POS);
    }
    xPtr OLD(xFUN_0081e440(FUN_004fd400()));
    OLD.FUN_0066b0d0(0);
    InitEffect();
    FUN_00570f70(m_b4.FUN_00559450());
    FUN_00813f30();
    xVec4 V(-xg_107a8b0, 0.0f, 0.0f, 0.0f);
    FUN_009306d0()->FUN_0080fb00(&V);
    FUN_008d6f30()->FUN_00548230(this, false);
    FUN_008133d0(0);
    if (FUN_004fd400()->FUN_004fd3c0())
    {
        void* NAME = FUN_004fd400()->FUN_004fd3c0()->FUN_0084e3a0();
        if (m_c8.FUN_00ad8ce0())
            m_c8.FUN_00ad8d10();
        if (m_c0.FUN_00559450())
        {
            m_c8 = xAudio::FUN_00453a70()->FUN_00ad73b0(NAME, 0x102);
            xP3 POS2 = *FUN_00436aa0();
            m_c8.SetPos(POS2.x, POS2.y, POS2.z);
            m_c8.SetNiNode(m_c0.FUN_00559450());
            m_c8.Play(true);
        }
    }
    FUN_0081eba0();
    void* SHOOTER = FUN_009185e0() ? FUN_009185e0()->FUN_2c() : 0;
    if (SHOOTER != xg_player_11dea3c)
        xFUN_0080fae0(*xg_11d1758.FUN_00403e20());
    else
    {
        xRefList* LIST = xg_11e0e80.GetOffset70Ptr();
        if (LIST)
            LIST->FUN_005ae3d0(this);
    }
}
