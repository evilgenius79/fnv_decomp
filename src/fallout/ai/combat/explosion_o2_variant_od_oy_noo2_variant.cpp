
// src/fallout/ai/combat/explosion_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/explosion_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/explosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/explosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct ActorCause
{
};
struct NiPointer
{
    NiPointer& operator=(ActorCause*);
};
struct FUN_009ac170_shell
{
    char m_auiShapeKeys[0xd0];
    NiPointer m_actorCause;
    void __thiscall FUN_009ac170(ActorCause* apActorCause);
};
struct Explosion
{
    virtual ~Explosion();
    void* Destroy(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct NiRTTI;
struct bhkLiquidAction
{
    const NiRTTI* __thiscall GetRTTI() const;
};
extern NiRTTI g_01268420;
struct NavMesh;
struct NavMeshPtr
{
    NavMesh* FUN_00458b50();
};
struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
struct BSOcclusionPlane
{
    int __thiscall GetCullResult() const;
    int __thiscall IsNotCulled();
};
struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
    void FUN_009afc10();
};
extern "C" void __cdecl FUN_009afbe0(void*);
struct FUN_00621100_shell
{
    void __thiscall SetVtable(void);
};
struct FUN_009afc10_shell
{
    void __thiscall FUN_009afc10();
};
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM g_memoryManager;
void __cdecl FUN_00cbc740();
struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00cbc650_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00cbc650_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual FUN_00cbc650_obj* vGet(FUN_00cbc650_obj* volatile* pp);
    void FUN_00c86790(FUN_00cbc650_obj* a);
    void FUN_00cbc650(FUN_00cbc650_obj* volatile a1);
};
struct FUN_00cbc6a0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
};
struct FUN_00cbc6a0_Class
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void FUN_00cbc6a0(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00cbc6a0_Data* vf45(int* value);
    void __thiscall FUN_00c868b0(unsigned char* arg);
};
extern __declspec(thread) int g_memoryContext;
void __cdecl FUN_00c876f0();
void __cdecl FUN_00c87700();
void* __cdecl FUN_00aa13e0(unsigned int size);
struct AutoMemContext
{
    int oldContext;
    AutoMemContext()
    {
        oldContext = g_memoryContext;
        g_memoryContext = 16;
    }
    ~AutoMemContext()
    {
        g_memoryContext = oldContext;
    }
};
struct FUN_00cbc550_class
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
    static void* __cdecl operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    FUN_00cbc550_class();
};
struct FUN_00cbca20_class
{
    void __thiscall FUN_00c86800(FUN_00cbc550_class* obj, int flags);
    FUN_00cbc550_class* __thiscall FUN_00cbca20(int flags);
};

#include <xmmintrin.h>
struct Vec4810;
struct Vec810
{
    float x, y, z;
    Vec810();
    Vec810 operator-(const Vec810&) const;
    Vec810& operator=(const Vec4810&);
    double FUN_00457990();
};
Vec810 __cdecl FUN_004a3760(float, const Vec810&);
struct Color810
{
    float r, g, b, a;
    Color810(float, float, float, float);
};
struct Hit810;
struct Snapshot810;
struct Query810;
struct Hit810
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    float unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    Hit810(void*);
};
struct __declspec(align(16)) Snapshot810
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    Snapshot810();
    ~Snapshot810();
};
struct HitArray810
{
    int FUN_00726070();
    void* GetEntryAt(int);
};
struct HitContainer810
{
    HitArray810* FUN_00460140();
};
struct __declspec(align(16)) Query810
{
    __m128 m_quad000;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    Query810();
    void FUN_004a3f70(unsigned);
    void FUN_004a3da0(const Vec810&);
    void FUN_004a3eb0(const Vec810&);
    void FUN_004a3fb0(Snapshot810*);
    HitContainer810* FUN_008cdd90();
};
struct Filter810
{
    unsigned value;
    Filter810(int);
    void FUN_004a39f0(int);
    void FUN_0059ce80(void*);
};
struct Setting810
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
};
extern Setting810 DAT_011d1344, DAT_011d150c, DAT_011d0a78;
struct Position810
{
    Vec810* FUN_006815c0();
    float FUN_0084d030();
};
struct Object810
{
    bool HasAnyFlags(int);
};
struct Body810
{
    int FUN_004b2960();
    Position810* FUN_0043d450();
};
struct World810
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void vc8(Query810*);
};
struct Cell810
{
    World810* FUN_004543c0();
};
struct Process810
{
    void* FUN_00819250();
};
struct Test810
{
    bool FUN_00452370();
};
struct Actor810
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Body810* v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual int v214();
    Body810* FUN_00950bb0(int);
    Cell810* FUN_008d6f30();
    Process810* FUN_009306d0();
};
extern Actor810* pPlayer;
struct Vec4810
{
    float x, y, z;
};
struct Array810
{
    Vec4810 ApplyScaled(float);
    float* FUN_004a51b0(int);
};
struct Host810
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    Array810 array;
    Object810* FUN_004181e0();
    Test810* GetFieldC8();
    bool FUN_009b1810(Vec810, Actor810*);
};
void __cdecl FUN_00c82870(int, unsigned __int64);
void* __cdecl FUN_005dbe10();
void __cdecl FUN_005b5e40(const char*);
void* __cdecl FUN_004b3890(const Vec810&, const Color810&, const Vec810&, const Color810&, int);
struct Debug810
{
    void FUN_00458e20(void*, float);
};
extern Debug810* DAT_011dea10;
// @fnv 0x009b1810
bool Host810::FUN_009b1810(Vec810 pos, Actor810* actor)
{
    Object810* base = FUN_004181e0();
    if (base->HasAnyFlags(16))
        return true;
    Body810* body = actor ? actor->v1d0() : 0;
    if (actor == pPlayer)
        body = pPlayer->FUN_00950bb0(0);
    if (!body || !body->FUN_004b2960())
        return false;
    World810* world = actor->FUN_008d6f30() ? actor->FUN_008d6f30()->FUN_004543c0() : 0;
    if (!world)
        return false;
    unsigned mask = 0x26206;
    FUN_00c82870(39, mask);
    Vec810 points[7];
    points[0] = *body->FUN_0043d450()->FUN_006815c0();
    bool multiple = false;
    if (actor->v100())
    {
        Actor810* checkActor = actor;
        if (checkActor->v214())
        {
            multiple = true;
            points[1] = points[0];
            points[1].z += body->FUN_0043d450()->FUN_0084d030() * 2.0f;
            points[2] = points[0];
            points[2].z -= body->FUN_0043d450()->FUN_0084d030() * 2.0f;
            points[3] = points[0];
            points[3].y += body->FUN_0043d450()->FUN_0084d030() * 2.0f;
            points[4] = points[0];
            points[4].y -= body->FUN_0043d450()->FUN_0084d030() * 2.0f;
            points[5] = points[0];
            points[5].x += body->FUN_0043d450()->FUN_0084d030() * 2.0f;
            points[6] = points[0];
            points[6].x -= body->FUN_0043d450()->FUN_0084d030() * 2.0f;
        }
    }
    Query810 query;
    Filter810 filter(0);
    filter.FUN_004a39f0(39);
    Actor810* checkActor = actor->v100() ? actor : 0;
    if (checkActor && checkActor->FUN_009306d0())
        filter.FUN_0059ce80(checkActor->FUN_009306d0()->FUN_00819250());
    else
        filter.FUN_0059ce80(FUN_005dbe10());
    pos = array.ApplyScaled(*DAT_011d1344.FUN_00403e20());
    query.FUN_004a3f70(filter.value);
    query.FUN_004a3da0(pos);
    query.FUN_004a3eb0(points[0]);
    Snapshot810 snapshot;
    query.FUN_004a3fb0(&snapshot);
    bool blocked = false;
    world->vc8(&query);
    for (int i = 0; !blocked && i < query.FUN_008cdd90()->FUN_00460140()->FUN_00726070(); i++)
    {
        Hit810 hit(query.FUN_008cdd90()->FUN_00460140()->GetEntryAt(i));
        Vec810 dir = points[0] - pos;
        Vec810 delta = FUN_004a3760(hit.unk10, dir);
        if (!(*array.FUN_004a51b0(2) < -0.98) || !(delta.FUN_00457990() < *DAT_011d150c.FUN_00403e20()))
        {
            if (!GetFieldC8() || !GetFieldC8()->FUN_00452370())
            {
                if (*DAT_011d0a78.FUN_0043d4d0() > 0)
                    FUN_005b5e40("EXPLOSION BLOCKED");
                blocked = true;
            }
        }
    }
    if (*DAT_011d0a78.FUN_0043d4d0() > 0)
    {
        Color810 color = blocked ? Color810(1, 0, 0, 1) : Color810(0, 1, 0, 1);
        void* line = FUN_004b3890(pos, color, points[0], color, 1);
        DAT_011dea10->FUN_00458e20(line, 25.0f);
    }
    if (multiple && blocked)
    {
        for (int i = 1; blocked && i < 7; i++)
        {
            blocked = false;
            Snapshot810 snapshot;
            query.FUN_004a3fb0(&snapshot);
            query.FUN_004a3eb0(points[i]);
            world->vc8(&query);
            for (int j = 0; !blocked && j < query.FUN_008cdd90()->FUN_00460140()->FUN_00726070(); j++)
            {
                Hit810 hit(query.FUN_008cdd90()->FUN_00460140()->GetEntryAt(j));
                Vec810 dir = points[j] - pos;
                Vec810 delta = FUN_004a3760(hit.unk10, dir);
                if (!(*array.FUN_004a51b0(2) < -0.98) || !(delta.FUN_00457990() < *DAT_011d150c.FUN_00403e20()))
                    blocked = true;
            }
        }
    }
    return !blocked;
}

struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3 FUN_00439ef0(const Vec3& o) const;
    Vec3 FUN_00439e90(const Vec3& o) const;
    Vec3 ApplyScaled(float f) const;
    double FUN_00457990() const;
    void Subtract(const Vec3& o);
    bool FUN_004390c0(const Vec3* o) const;
    void FUN_004a0c10();
    float DotProduct(const Vec3& o) const;
};

struct Color4
{
    float r, g, b, a;
    void FUN_00414430(float r, float g, float b, float a);
};

struct Color3
{
    float r, g, b;
    Color3* FUN_00416870(float r, float g, float b);
};

struct Ptr4
{
    void* p;
    void* FUN_00559450();
};

struct Setting
{
    int* FUN_0043d4d0();
};
extern Setting g_setA;
extern Setting g_setB;
extern Vec3 g_zeroVec;
extern int g_dummy;

struct FloatSetting
{
    float* FUN_00403e20();
};
extern FloatSetting g_floatSetting;

struct __declspec(align(16)) Elem70
{
    unsigned int unk00;
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
    void* unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    Elem70* FUN_00632d40(const Elem70* o);
    Vec3* FUN_006815c0();
    Vec3* FUN_00460140();
};

struct HitInfo
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    int unk20[8];
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    Ptr4* unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    HitInfo* FUN_00696c30(const HitInfo* o);
};

struct HitArray
{
    HitArray* FUN_00460140();
    int FUN_00726070();
    HitInfo* GetEntryAt(int i);
};

struct HitHolder
{
    HitArray* FUN_00460140();
};

struct Flag1
{
    char c;
};

struct Flag1Ptr
{
    bool FUN_005609f0();
};

struct ResList
{
    void* p0;
    int i4;
    int i8;
    int iC;
    ResList(int v);
    ~ResList();
    void* FUN_00559450();
};

struct ProjList
{
    void* p0;
    int i4;
    int i8;
    int iC;
    int i10;
    int i14;
    ProjList(void* a, int b);
    ~ProjList();
    Flag1Ptr* FUN_009afc70(Flag1* out);
    int FUN_009afc50();
    Elem70* FUN_009afc30();
};

struct Shape
{
    void FUN_00a5a040();
    void FUN_00440460(const Vec3* p);
};

struct Drawer
{
    void FUN_00458e20(Shape* s, float t);
    int FUN_00457880(const Vec3* p);
    struct Mgr* FUN_004519d0(Vec3 p);
};
extern Drawer* g_drawer;

struct Params
{
    Vec3 unk00;
    Vec3 unk0C;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    void* unk28;
    int unk2C;
    void* unk30;
    int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    int unk48;
    float unk4C;
    int unk50;
    float unk54;
    float unk58;
    int unk5C;
    Color3 unk60;
    int unk6C;
    char unk70;
    char unk71;
    char unk72;
    char unk73;
    char unk74;
    char unk75;
    char unk76;
    char unk77;
    int unk78;
    int unk7C;
    Params();
};

struct Mgr
{
    void FUN_004a3fe0(Params* p, int a, int b);
};

struct Wrap4
{
    int v;
    Wrap4* FUN_008c71b0(void* o);
    int FUN_004a3a20();
};

struct RefObj
{
    virtual void vf00();
    void* FUN_0043b540();
    void* FUN_00559450();
};

struct Hand4
{
    void* p;
};
struct Hand8
{
    void* p;
    int i;
};

struct Sub
{
    void* FUN_00559450();
    int FUN_009611e0();
};

struct Proc
{
    virtual void vf00();
};

struct Owner
{
    virtual void vf00();
    int FUN_006205a0();
    int FUN_00c84f10(int i);
};

struct VTbl;

struct NodeRef
{
    unsigned int unk00;
    unsigned int unk04;
    RefObj* unk08;
    int unk0C;
};

struct NodeList
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    NodeList();
    ~NodeList();
    NodeList* FUN_00413f40();
    int FUN_00726070();
    NodeRef* FUN_0062e150(int i);
};

struct Query
{
    void FUN_006233c0(int a);
    void FUN_004a1a10(int a, int b);
    void FUN_006231a0(void* t);
    void FUN_00623090(const Vec3* p, NodeList* l);
};

struct NameHolder
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual char* GetName();
};

struct Weap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    NameHolder unk18;
    void* FUN_006733e0();
    float GetModifierValue();
    float FUN_004a40a0();
    float GetNestedValue();
    char FUN_004a4140();
    char CallMemberAtOffset54();
    char FUN_004a4100();
    float FUN_004a41c0();
    char FUN_004a41e0();
    float FUN_004a40e0();
    float FUN_009a9350();
    unsigned int GetNextFromSubobject();
    int FUN_005f36f0();
    float FUN_00508100();
    struct SndSrc* GetField4C();
    struct SndSrc* GetGrass();
};

struct SndSrc
{
    void* FUN_00511840(int f);
};

struct Snd
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ~Snd();
    void SetPos(float x, float y, float z);
    void Play(int a);
};

struct WeapHolder
{
    Weap* FUN_004fb7d0();
};

struct Picker
{
    virtual void vf00();
};

struct Proc2
{
    Picker* FUN_004543c0();
};

struct Big4c0
{
    unsigned int unk00;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    Big4c0();
    ~Big4c0();
};

struct __declspec(align(16)) Big570
{
    __m128 quad00;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    Big570();
    void FUN_004a3da0(const Vec3* p);
    void FUN_007f68a0(const Vec3* p);
    void FUN_004a3f70(void* p);
    void FUN_004a3fb0(Big4c0* p);
    HitHolder* FUN_008cdd90();
};

struct PlayerX
{
    Vec3* FUN_0045bb80();
};

struct Cell
{
    void FUN_00c9f1e0(ProjList* l);
    Hand4* FUN_0043b4f0(Hand4* out);
};

struct CellPtr
{
    void* p;
    Cell* FUN_00559450();
};

extern "C" void __cdecl FUN_00cbd960();
extern "C" void __cdecl FUN_009b2e00(void* a, int b);
extern "C" void __cdecl FUN_00458620(Vec3* out, const Vec3* in);
extern "C" void __cdecl FUN_004a3970(Vec3* out, const Vec3* in);
extern "C" Shape* __cdecl CreateOctahedron(float r, const Color4* c, int a);
extern "C" Shape* __cdecl FUN_004b3890(const Vec3* a, const Color4* c, const Vec3* b, const Color4* c2, int f);
Vec3 __cdecl FUN_004a3760(float f, const Vec3& v);
extern "C" void* __cdecl FUN_004b5820(void* p);
extern "C" Proc* __cdecl FUN_0056f930(void* p);
extern "C" Owner* __cdecl FUN_004a3a40(void* p);
extern "C" PlayerX* __cdecl FUN_00524c90();
extern "C" bool __cdecl FUN_00525420();
extern "C" bool __cdecl FUN_004b61d0(Vec3 p, PlayerX* pl, float f);
extern "C" float __cdecl FUN_00476b70(float a, float b);
extern "C" Query* __cdecl FUN_00622a70(float a, int b);
extern "C" float __cdecl FUN_004a4240();
extern "C" float __cdecl FUN_00406cc0(float a);
extern "C" void* __cdecl FUN_004b59f0(RefObj* r);
extern "C" Sub* __cdecl FUN_00c85ef0(Hand8* out, void* a, void* b);
extern "C" Sub* __cdecl FUN_00c7fa90(RefObj* r);
extern "C" bool __cdecl IsAcousticSpaceFormTypeAllowed(Proc* p, int a);
extern "C" void __cdecl FUN_006890b0(void* a, float f, char* name, Vec3 d, Vec3 p, float s, int b, int c);
struct AudioMgr
{
    Snd FUN_00ad7480(void* a, SndSrc* b);
};
extern "C" AudioMgr* __cdecl FUN_00453a70();
extern double g_maxLen;
extern float g_f1;
extern float g_f2;
extern float g_f3;
extern float g_f4;
extern float g_f5;
extern float g_f6;
extern float g_f7;
extern float g_f8;
extern float g_f9;
extern double g_d255;
extern double g_dmul;
extern int g_rtti;

struct ProjCls
{
    virtual void vf00();
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    CellPtr unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    bool unkD4;
    bool unkD5;
    bool unkD6;
    bool unkD7;
    bool unkD8;
    bool unkD9;
    unsigned short unkDA;
    unsigned int unkDC;
    unsigned int unkE0;
    int unkE4;
    Vec3 unkE8;
    Vec3 unkF4;
    void FUN_009ae6e0();
    void FUN_009afef0();
    void ProcessHits();
    Proc2* FUN_008d6f30();
    WeapHolder* FUN_004181e0(int id);
};

struct ProjVt
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsDead();
};

struct PickVt
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual bool Pick(Big570* p);
    virtual Owner* GetOwner();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int GetId(int i);
};

struct SelfVt
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual Vec3* GetPos();
};

// @fnv 0x009ae6e0
void ProjCls::FUN_009ae6e0()
{
    if (unkA0.FUN_00559450() == 0)
        return;
    if (unkE4 > 0 && unkD6 && !unkD7)
        FUN_009afef0();
    if (unkD5 && !unkD4)
    {
        unkD4 = 1;
        ResList res(*g_setA.FUN_0043d4d0());
        ProjList list(res.FUN_00559450(), *g_setA.FUN_0043d4d0());
        FUN_00cbd960();
        unkA0.FUN_00559450()->FUN_00c9f1e0(&list);
        Flag1 fl;
        if (list.FUN_009afc70(&fl)->FUN_005609f0())
            FUN_009b2e00(res.FUN_00559450(), list.FUN_009afc50());
        if (*g_setB.FUN_0043d4d0() > 1)
        {
            for (int i = 0; i < list.FUN_009afc50(); i++)
            {
                Elem70 e;
                e.FUN_00632d40(list.FUN_009afc30() + i);
                Vec3 a;
                FUN_00458620(&a, e.FUN_006815c0());
                Vec3 b;
                FUN_004a3970(&b, e.FUN_00460140());
                Color4 c;
                c.FUN_00414430(1.0f, 0.0f, 0.0f, g_f1);
                Shape* s = CreateOctahedron(g_f2, &c, 1);
                s->FUN_00a5a040();
                s->FUN_00440460(&a);
                g_drawer->FUN_00458e20(s, g_f3);
                s = FUN_004b3890(&a, &c, &a.FUN_00439e90(b.ApplyScaled(g_f3)), &c, 1);
                g_drawer->FUN_00458e20(s, g_f3);
            }
        }
        bool done = false;
        for (int j = 0; !done && j < list.FUN_009afc50(); j++)
        {
            Elem70 e;
            e.FUN_00632d40(list.FUN_009afc30() + j);
            if (e.unk48)
            {
                void* r = FUN_004b5820(e.unk48);
                Proc* u = FUN_0056f930(r);
                if (!u || !((ProjVt*)u)->IsDead())
                {
                    Vec3 pos;
                    FUN_00458620(&pos, e.FUN_006815c0());
                    Vec3 dir;
                    FUN_004a3970(&dir, e.FUN_00460140());
                    Big4c0 q;
                    Big570 p;
                    Vec3 v = *((SelfVt*)this)->GetPos();
                    Vec3 w = FUN_004a3760(g_f4, pos.FUN_00439ef0(v));
                    if (w.FUN_00457990() < g_maxLen)
                    {
                        v.Subtract(dir.ApplyScaled(g_f5));
                        w = dir.ApplyScaled(g_f6);
                    }
                    p.FUN_004a3da0(&v);
                    p.FUN_007f68a0(&w);
                    Hand4 h4;
                    p.FUN_004a3f70(unkA0.FUN_00559450()->FUN_0043b4f0(&h4)->p);
                    p.FUN_004a3fb0(&q);
                    int target = 0x24;
                    bool found = false;
                    if (FUN_008d6f30()->FUN_004543c0())
                    {
                        Picker* pk = FUN_008d6f30()->FUN_004543c0();
                        if (((PickVt*)pk)->Pick(&p))
                        {
                            bool stop = false;
                            for (int k = 0; !found && !stop && k < p.FUN_008cdd90()->FUN_00460140()->FUN_00726070();
                                 k++)
                            {
                                HitInfo h;
                                h.FUN_00696c30(p.FUN_008cdd90()->FUN_00460140()->GetEntryAt(k));
                                void* r2 = FUN_004b5820(h.unk50);
                                Proc* u2 = FUN_0056f930(r2);
                                if (r == r2)
                                {
                                    found = true;
                                    int last = -1;
                                    for (int m = 0; m < 8 && h.unk20[m] != -1; m++)
                                        last = h.unk20[m];
                                    Wrap4 wr;
                                    bool isActor =
                                        wr.FUN_008c71b0(((RefObj*)h.unk50)->FUN_0043b540())->FUN_004a3a20() == 1;
                                    if (isActor)
                                    {
                                        target = g_drawer->FUN_00457880(&pos);
                                    }
                                    else
                                    {
                                        Owner* ow = FUN_004a3a40(h.unk50->FUN_00559450());
                                        if (ow)
                                            target = ow->FUN_00c84f10(last);
                                    }
                                }
                                else if (!u2 || !((ProjVt*)u2)->IsDead())
                                {
                                    stop = true;
                                }
                            }
                        }
                    }
                    if (found)
                    {
                        unkE8 = pos;
                        if (unkF4.FUN_004390c0(&g_zeroVec))
                            unkF4 = dir;
                        if (*g_setB.FUN_0043d4d0() > 1)
                        {
                            Color4 c;
                            c.FUN_00414430(0.0f, 1.0f, 0.0f, g_f1);
                            Shape* s = CreateOctahedron(g_f7, &c, 1);
                            s->FUN_00a5a040();
                            s->FUN_00440460(&unkE8);
                            g_drawer->FUN_00458e20(s, g_f3);
                            s = FUN_004b3890(&unkE8, &c, &unkE8.FUN_00439e90(unkF4.ApplyScaled(g_f8)), &c, 1);
                            g_drawer->FUN_00458e20(s, g_f3);
                        }
                        done = true;
                        Weap* wt = FUN_004181e0(target)->FUN_004fb7d0();
                        if (wt)
                        {
                            bool flag = true;
                            Vec3 dd = pos.FUN_00439ef0(*FUN_00524c90()->FUN_0045bb80());
                            if (FUN_00525420() || dd.FUN_00457990() > *g_floatSetting.FUN_00403e20() ||
                                !FUN_004b61d0(pos, FUN_00524c90(), g_f6))
                                flag = false;
                            void* proj = wt->FUN_006733e0();
                            if (proj)
                            {
                                float spd = FUN_00476b70(wt->FUN_004a40a0(), wt->GetModifierValue());
                                Query* qq = FUN_00622a70(spd, 1);
                                qq->FUN_006233c0(0);
                                qq->FUN_004a1a10(8, 0);
                                qq->FUN_004a1a10(0x1d, 0);
                                Proc2* p2 = FUN_008d6f30();
                                Picker* t = p2 ? p2->FUN_004543c0() : 0;
                                if (t)
                                {
                                    qq->FUN_006231a0(t);
                                    NodeList nl;
                                    qq->FUN_00623090(&pos, &nl);
                                    int n = nl.FUN_00413f40()->FUN_00726070();
                                    float fade = FUN_004a4240();
                                    char cc = (char)FUN_00406cc0(FUN_00476b70(0.0f, g_f9));
                                    for (int k = 0; k < n; k++)
                                    {
                                        RefObj* ref = nl.FUN_00413f40()->FUN_0062e150(k)->unk08;
                                        if (ref)
                                        {
                                            int id = target;
                                            int idx = nl.FUN_00413f40()->FUN_0062e150(k)->unk0C;
                                            if (idx != -1)
                                            {
                                                Owner* ow = FUN_004a3a40(ref->FUN_00559450());
                                                if (!ow)
                                                    continue;
                                                Owner* o2 = ((PickVt*)ow)->GetOwner();
                                                if (o2)
                                                    id = ((PickVt*)o2)->GetId(idx);
                                            }
                                            else
                                            {
                                                Owner* ow = FUN_004a3a40(ref->FUN_00559450());
                                                if (!ow)
                                                    continue;
                                                id = ow->FUN_006205a0();
                                            }
                                            if (id == target)
                                            {
                                                Wrap4 wr;
                                                bool isActor =
                                                    wr.FUN_008c71b0(ref->FUN_0043b540())->FUN_004a3a20() == 1;
                                                Sub* node = 0;
                                                if (isActor)
                                                {
                                                    void* a = FUN_004b59f0(ref);
                                                    if (a)
                                                    {
                                                        Hand8 hh;
                                                        node = (Sub*)FUN_00c85ef0(&hh, a, &g_rtti)->FUN_00559450();
                                                        if (node && node->FUN_009611e0())
                                                            node = (Sub*)node->FUN_009611e0();
                                                    }
                                                }
                                                else
                                                {
                                                    node = FUN_00c7fa90(ref);
                                                }
                                                Proc* u3 = FUN_0056f930(node);
                                                if (!isActor && (!u3 || !IsAcousticSpaceFormTypeAllowed(u3, 1)))
                                                    continue;
                                                Mgr* mg = g_drawer->FUN_004519d0(pos);
                                                Params prm;
                                                prm.unk00 = unkE8;
                                                prm.unk0C = unkF4;
                                                prm.unk38 = spd;
                                                prm.unk3C = spd;
                                                prm.unk40 = wt->GetNestedValue();
                                                prm.unk28 = node;
                                                prm.unk30 = proj;
                                                prm.unk44 = fade;
                                                prm.unk70 = cc;
                                                prm.unk75 = wt->FUN_004a4140();
                                                prm.unk74 = wt->CallMemberAtOffset54();
                                                prm.unk73 = wt->FUN_004a4100();
                                                prm.unk4C = wt->FUN_004a41c0();
                                                prm.unk76 = wt->FUN_004a41e0();
                                                prm.unk54 = wt->FUN_004a40e0();
                                                prm.unk58 = wt->FUN_009a9350();
                                                Color3 col;
                                                prm.unk60 = *col.FUN_00416870(
                                                    (float)(((unsigned char)((wt->GetNextFromSubobject()) & 0xff)) / g_d255),
                                                    (float)(((unsigned char)((((unsigned short)(wt->GetNextFromSubobject())) >>
                                                                              8) &
                                                                             0xff)) /
                                                            g_d255),
                                                    (float)(((unsigned char)(((wt->GetNextFromSubobject()) >> 16) & 0xff)) /
                                                            g_d255));
                                                mg->FUN_004a3fe0(&prm, 1, 0);
                                            }
                                        }
                                    }
                                    qq = 0;
                                }
                            }
                            if (flag && !unkD9)
                            {
                                char* name = wt->unk18.GetName();
                                if (name && *name)
                                {
                                    Vec3 dv;
                                    switch (wt->FUN_005f36f0())
                                    {
                                    case 0:
                                        dv = dir;
                                        dv.FUN_004a0c10();
                                        break;
                                    case 1:
                                        dv = ((SelfVt*)this)->GetPos()->FUN_00439ef0(pos);
                                        dv.FUN_004a0c10();
                                        break;
                                    case 2: {
                                        Vec3 a = ((SelfVt*)this)->GetPos()->FUN_00439ef0(pos);
                                        a.FUN_004a0c10();
                                        Vec3 b = dir;
                                        b.FUN_004a0c10();
                                        dv = FUN_004a3760((float)(b.DotProduct(a) * g_dmul), b).FUN_00439ef0(a);
                                        break;
                                    }
                                    default:
                                        dv = dir;
                                        dv.FUN_004a0c10();
                                        break;
                                    }
                                    FUN_006890b0(FUN_008d6f30(), wt->FUN_00508100(), name, dv, pos, 1.0f, 7, 0);
                                }
                            }
                            SndSrc* s1 = wt->GetField4C();
                            if (s1)
                            {
                                Snd snd = FUN_00453a70()->FUN_00ad7480(s1->FUN_00511840(0x4102), s1);
                                snd.SetPos(pos.x, pos.y, pos.z);
                                snd.Play(0);
                            }
                            SndSrc* s2 = wt->GetGrass();
                            if (s2)
                            {
                                Snd snd = FUN_00453a70()->FUN_00ad7480(s2->FUN_00511840(0x4102), s2);
                                snd.SetPos(pos.x, pos.y, pos.z);
                                snd.Play(0);
                            }
                        }
                    }
                }
            }
        }
        if (unkD5 && !unkD6)
            ProcessHits();
    }
}
