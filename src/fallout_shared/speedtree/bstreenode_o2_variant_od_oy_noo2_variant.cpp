
// src/fallout_shared/speedtree/bstreenode_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout_shared/speedtree/bstreenode_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/speedtree/bstreenode_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/speedtree/bstreenode.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00622430_shell
{
    unsigned int __thiscall FUN_00622430();
};
struct NiRTTI;
extern NiRTTI g_011d5e70;
struct FUN_0066b5b0_shell
{
    const NiRTTI* __thiscall GetNiRTTI();
};
struct NiAVObject;
struct NiNode
{
    NiAVObject* __thiscall GetAt(unsigned int);
};
struct BSTreeNode : NiNode
{
    NiAVObject* __thiscall GetFirstChild();
};
struct NiCullingProcess;
extern "C" unsigned char __cdecl FUN_0054ee20();
struct DummyNode
{
    void __thiscall FUN_00a5dbe0(NiCullingProcess* arCuller);
    void __thiscall FUN_0066bf50(NiCullingProcess* arCuller);
};
struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};
struct FUN_0066d410_shell : public FUN_00c6c290_holder
{
    void FUN_0066d410();
};
struct NiRTTI
{
};
extern const NiRTTI g_012683d0;
struct FUN_0066d430_shell
{
    const NiRTTI* GetRTTI() const;
};
void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct FUN_0066d440_shell
{
    void FUN_0066d470();
    void* FUN_0066d440(unsigned int flags);
};
struct FUN_0066d470_shell
{
    void FUN_0066d410();
    void FUN_0066d470();
};
struct FUN_0066d510_shell
{
    const void* FUN_0066d510();
};
extern const void* g_012683e0;
struct FUN_0066d520_shell
{
    void FUN_00cb78b0();
    void* FUN_0066d520(unsigned int flags);
};
void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610 g_012681b4;
struct FUN_0066d610_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};
struct bhkCapsuleShape
{
    unsigned int __thiscall FUN_0066d730() const;
};
struct FUN_0066da50_t
{
    void FUN_0066da50();
};
struct FUN_0066d7a0_shell
{
    int m0;
    FUN_0066da50_t m1;
    void RunInner();
};
struct Flt
{
    operator unsigned int() const;
};
struct NiTriBasedGeom;
struct FUN_0066b620_shell
{
    NiTriBasedGeom* __thiscall GetTriBasedGeom();
};
extern const char* const g_012683d0_arg1;
struct FUN_0066d400_shell
{
    const char* const* GetArg1Ptr();
};
struct NiStream;
struct HC1Base
{
    bool FUN_00aa0ad0(NiStream*);
};
struct VirtCls
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void Target(NiStream*);
};
struct Mid8
{
    char _0[8];
    VirtCls* p8;
};
struct Mid14
{
    char _0[20];
    Mid8* p14;
};
struct S_00c8c390
{
    char _0[8];
    Mid14* p8;
    bool FUN_00c8c390(NiStream*);
};
struct S_00c8c810_A
{
    int _0;
    volatile long _ref;
};
struct S_00c8c810_B
{
    char _p[8];
    S_00c8c810_A* p;
};
struct S_00c8c810_C
{
    char _p[20];
    S_00c8c810_B* p;
};
struct H_00c8c810
{
    char _p[8];
    S_00c8c810_C* p;
    void __thiscall FUN_00c84e50(bool);
    void __thiscall FUN_00c8c770();
    void __thiscall FUN_00c8c810(bool);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct Buf00cb7750
{
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
};
struct Inner00cb7750
{
    int _00;
    int _04;
    int m_08;
    void __thiscall FUN_00c9ec60(Buf00cb7750*);
};
struct S00cb7750
{
    virtual void a00()
    {}
    virtual void a01()
    {}
    virtual void a02()
    {}
    virtual void a03()
    {}
    virtual void a04()
    {}
    virtual void a05()
    {}
    virtual void a06()
    {}
    virtual void a07()
    {}
    virtual void a08()
    {}
    virtual void a09()
    {}
    virtual void a10()
    {}
    virtual void a11()
    {}
    virtual void a12()
    {}
    virtual void a13()
    {}
    virtual void a14()
    {}
    virtual void a15()
    {}
    virtual void a16()
    {}
    virtual void a17()
    {}
    virtual void a18()
    {}
    virtual void a19()
    {}
    virtual void a20()
    {}
    virtual void a21()
    {}
    virtual void a22()
    {}
    virtual void a23()
    {}
    virtual void a24()
    {}
    virtual void a25()
    {}
    virtual void a26()
    {}
    virtual void a27()
    {}
    virtual void a28()
    {}
    virtual void a29()
    {}
    virtual void a30()
    {}
    virtual void a31()
    {}
    virtual void a32()
    {}
    virtual void a33()
    {}
    virtual void a34()
    {}
    virtual void a35()
    {}
    virtual void a36()
    {}
    virtual void a37()
    {}
    virtual void a38()
    {}
    virtual void a39()
    {}
    virtual void a40()
    {}
    virtual void a41()
    {}
    virtual void a42()
    {}
    virtual void a43()
    {}
    virtual void a44()
    {}
    virtual void a45()
    {}
    virtual void f46(Buf00cb7750*)
    {}
    int _04;
    int _08;
    int _0C;
    Inner00cb7750* m_10;
    void __thiscall FUN_00cb7750();
};
void* __fastcall FUN_00c6b910(void*);
extern int DAT_01066b94;
struct BSFadeNode
{
    void* vf;
    char pad[16];
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    BSFadeNode()
    {
        FUN_00c6b910(this);
        vf = (void*)&DAT_01066b94;
    }
};
BSFadeNode* FUN_00c87fc0();
struct Middle
{
    int unk00;
    int unk04;
    unsigned int value;
};
struct This
{
    int unk00;
    int unk04;
    Middle* middle;
    void FUN_00c84e20(unsigned int* output);
};
struct NiStream
{
    int unk00;
    unsigned int version;
};
struct NiCollisionObject
{
    void LinkObject(NiStream&);
};
struct LegacyLinker : NiCollisionObject
{
    void FUN_00c6bb70(NiStream*);
    void FUN_00c87f80(NiStream*);
};
struct C8C330Source
{
    int unk00;
    int unk04;
    int m_uiFilterValue;
};
struct C8C330Node
{
    C8C330Source* FUN_00a63430();
};
struct C8C330Child
{
    int unk00;
    int m_uiFilterValue;
};
struct C8C330Owner
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual C8C330Child* GetOrCreateChild(bool* pbCreated);

    void FUN_00c84cc0(C8C330Node* pkNode);
    void FUN_00c8c330(C8C330Node* pkNode);
};
typedef unsigned int C8CA60size_t;
struct C8CA60MemoryManager
{
    void* Allocate(unsigned int uiSize);
};
extern C8CA60MemoryManager g_C8CA60MemoryManager;
extern __declspec(thread) int g_C8CA60AllocTag;
struct C8CA60AllocTagScope
{
    int m_iSaved;

    C8CA60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_C8CA60AllocTag;
        g_C8CA60AllocTag = aiAllocationTag;
    }
    ~C8CA60AllocTagScope()
    {
        g_C8CA60AllocTag = m_iSaved;
    }
};
inline void* C8CA60AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)g_C8CA60MemoryManager.Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}
struct C8CA60Child
{
    C8CA60Child();

    static void* operator new(C8CA60size_t, void* pvMem)
    {
        return pvMem;
    }
};
struct C8CA60Owner
{
    int unk00;
    int unk04;
    void* m_pParentNode;
    C8CA60Child* m_pkChild;

    void FUN_00c8c410(C8CA60Child* pkChild);
    C8CA60Child* FUN_00c8ca60(bool* pbCreated);
};
struct StrArr
{
    void* unk00;
    char** data;
    unsigned short capacity, size, live, growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char* const&);
    void append(char* const& text)
    {
        unsigned int index = size;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, text);
    }
};
struct NiPoint3
{
    float x, y, z;
    char* FUN_00a59af0(const char*);
};
struct NiTransform
{
    float rotation[9];
    NiPoint3 translate;
    float scale;
    char* ToString(const char*);
};
struct NativeTransform
{
    float rotation[12];
    float translation[4];
};
void __cdecl FUN_00624b10(NiTransform*, NiPoint3*);
void __cdecl FUN_00458620(NiPoint3*, const float*);
extern NativeTransform DAT_01268370;
char* __cdecl FUN_00a7d330(void*);
extern unsigned int DAT_0126fd98;
extern __declspec(thread) unsigned int currentTask;
struct AutoMemContext
{
    unsigned int ePreviousContext;
    AutoMemContext()
    {
        ePreviousContext = currentTask;
        currentTask = 16;
    }
    ~AutoMemContext()
    {
        currentTask = ePreviousContext;
    }
};
struct Component
{
    virtual void v00();
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void serialize(StrArr*);
};
struct Holder
{
    unsigned int unk00, unk04;
    Component* component;
};
struct State
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Holder* holder;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    NativeTransform world;
};
struct Object
{
    unsigned int unk00, unk04;
    State* state;
    void FUN_00c851c0(StrArr*);
    void FUN_00c8cb20(StrArr*);
    Component* getComponent()
    {
        if (this)
        {
            State* current = state;
            if (current)
            {
                Holder* holder = current->holder;
                if (!holder)
                    return 0;
                return holder->component;
            }
            return 0;
        }
        return 0;
    }
};
struct CB7800RTTI
{
    const char* m_pcName;
    const CB7800RTTI* m_pBaseRTTI;

    const char* GetName() const
    {
        return m_pcName;
    }
};
struct CB7800StringArray
{
    virtual ~CB7800StringArray();

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);

    unsigned int SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }

    unsigned int Add(char*& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
extern "C" char* __cdecl FUN_00a7d330(const char* pcText);
extern __declspec(thread) int g_CB7800AllocTag;
struct CB7800AllocTagScope
{
    int m_iSaved;

    CB7800AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CB7800AllocTag;
        g_CB7800AllocTag = aiAllocationTag;
    }
    ~CB7800AllocTagScope()
    {
        g_CB7800AllocTag = m_iSaved;
    }
};
struct CB7800Base
{
    void GetViewerStrings(CB7800StringArray* pkStrings);
};
struct CB7800Object : CB7800Base
{
    static CB7800RTTI ms_kRTTI;

    void FUN_00cb7800(CB7800StringArray* pkStrings);
};
struct S_00cb78b0_Base
{
    virtual ~S_00cb78b0_Base();
};
struct FUN_00cb78b0 : S_00cb78b0_Base
{
    static int ms_count;
    void FUN_00c876a0();
    virtual ~FUN_00cb78b0();
};
void FUN_00c876f0();
void FUN_00c87700();
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_012683dc;
struct S_00cb79d0_Base
{
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
    S_00cb79d0_Base();
    virtual void v00();
    int unk04;
    int unk08;
};
struct S_00cb79d0_A : S_00cb79d0_Base
{
    int unk0C;
    int unk10;
    S_00cb79d0_A()
    {
        unk0C = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
    virtual void v00();
};
struct S_00cb79d0_B : S_00cb79d0_A
{
    S_00cb79d0_B()
    {
        DAT_01268274++;
    }
    virtual void v00();
};
struct S_00cb79d0_C : S_00cb79d0_B
{
    S_00cb79d0_C()
    {
        DAT_012683dc++;
    }
    virtual void v00();
};
struct S_00cb79d0
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
    virtual void v049(S_00cb79d0_Base* obj, int arg);
    S_00cb79d0_C* FUN_00cb79d0(int arg);
};
void SwapByteQuadWords(void* buffer, int words);
struct Vector3
{
    float x;
    float y;
    float z;
};
void __cdecl FUN_00cf0930(void* buffer, int bytes, Vector3* vector);
struct TlsBlock_t
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
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
struct FUN_00c88210_cls
{
    void __thiscall FUN_00c6ba30(BSFadeNode* node, unsigned int flags);
    BSFadeNode* FUN_00c88210(unsigned int flags);
};
extern __declspec(thread) int g_iC882C0AllocTag;
struct BC882C0AllocTagScope
{
    int m_iSaved;

    BC882C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC882C0AllocTag;
        g_iC882C0AllocTag = aiAllocationTag;
    }
    ~BC882C0AllocTagScope()
    {
        g_iC882C0AllocTag = m_iSaved;
    }
};
class BC882C0StringArray
{
  public:
    virtual ~BC882C0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
extern const char* g_pcC882C0Name;
char* __cdecl FUN_00a7d330(const char* pcString);
class FUN_00c882c0_cls
{
  public:
    void C882C0BaseGetViewerStrings(BC882C0StringArray* pkArray);
    void FUN_00c882c0(BC882C0StringArray* pkArray);
};
struct ScaleMatrix
{
    float m00;
    float m04;
    float m08;
    float m0c;
    float m10;
    float m14;
    float m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    float m2c;
};
struct SourceObject
{
    int m00;
    int m04;
    int m08;
    int m0c;
    float scale;
};
struct FUN_00caaea0_shell
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
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
    virtual ScaleMatrix* getMatrix(bool* outFlag) = 0;
    void FUN_00c84df0(void* context, SourceObject* source);
    void FUN_00caaea0(void* context, SourceObject* source);
};
struct S_00caaf40_Tls
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00caaf40_Tls DAT_tls;
struct S_00caaf40_Ctx
{
    int saved;
    __forceinline S_00caaf40_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00caaf40_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
void FUN_00c876f0();
void FUN_00c87700();
struct S_00caaf40_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    S_00caaf40_Obj();
};
struct S_00caaf40
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4(S_00caaf40_Obj* o, int a);
    S_00caaf40_Obj* FUN_00caaf40(int a);
};
struct AudioTlsState
{
    char* GetBlock();
};
struct MemoryContext
{
    int unk2b4;
};
extern __declspec(thread) int g_memoryContext;
struct ScopedContext
{
    int old;
    ScopedContext(int value)
    {
        old = g_memoryContext;
        g_memoryContext = value;
    }
    ~ScopedContext()
    {
        g_memoryContext = old;
    }
};
struct Pool
{
    virtual void f00();
    virtual void* Alloc(unsigned int size);
};
struct Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Pool* unk10;
    void* Alloc(unsigned int size)
    {
        return unk10->Alloc(size);
    }
};
Heap* FUN_00c85750();
struct FUN_00d22590
{
    int unk00;
    short unk04;
    short unk06;
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
    FUN_00d22590(int a, int b, float c);
    void FUN_00c905b0();
    static void* operator new(unsigned int size)
    {
        FUN_00d22590* p = (FUN_00d22590*)FUN_00c85750()->Alloc(size);
        p->unk04 = (short)size;
        return p;
    }
    static void operator delete(void* p, unsigned int);
};
struct Owner
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void AddElement(FUN_00d22590* e);
    void FUN_00cab0e0(int a, int b, float c);
};
struct FUN_00cb7790_node
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
    Buf00cb7750 transform;
    void __thiscall FUN_00a68bf0();
};
struct FUN_00cb7790_receiver
{
    unsigned int unk00;
    unsigned int unk04;
    void* object;
    void __thiscall FUN_0056df20(Buf00cb7750*);
};
struct FUN_00cb7790_state
{
    unsigned int owner;
    unsigned int depth;
    void __thiscall Lock(int);
};
extern FUN_00cb7790_state DAT_01267b80;
struct FUN_00cb7790_class
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cb7790_node* node;
    unsigned int unk0C;
    FUN_00cb7790_receiver* receiver;
    void __thiscall FUN_00cb7790();
};
// FUN_00cb7920 - factory for a bhkMultiSphereShape.
//
// The shape is allocated with the class' own operator new, the base
// constructor is run on it and the vtable pointer of the object is moved
// through the vtables of the whole class chain while the per class instance
// counters are bumped.  A guard object keeps the raw pointer alive so that
// the memory is released again if the construction throws.
struct VTable
{
    void* entries[1];
};
static void g_vtblDummy()
{}
// The vtables of the three class levels the shape is built from.
static const VTable g_vtblShape = {{(void*)&g_vtblDummy}};
static const VTable g_vtblSphereRep = {{(void*)&g_vtblDummy}};
static const VTable g_vtblMultiSphere = {{(void*)&g_vtblDummy}};
// Live instance counters of the three class levels.
static volatile int g_nShape;
static volatile int g_nSphereRep;
static volatile int g_nMultiSphere;
struct Node
{
    void* vf;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void Init();
};
// Releases the raw shape again when the construction throws.
struct Guard
{
    void* p;
    Guard(void* q) : p(q)
    {}
    ~Guard()
    {
        p = 0;
    }
};
void* __cdecl opnew(unsigned int);
void __cdecl opdelete(void*);
Node* FUN_00cb7920();
struct Shader
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual int f42();
    virtual void f43();
    virtual void f44();
    virtual int* f45(struct Pass** pass);
    void FUN_00c84d00(struct Pass* pass);
    void FUN_00cb7b20(struct Pass* pass);
};
struct Pass
{
    int unk000;
    char unk004;
};
void FUN_00cf0930(int* a, int b, int* c);
void FUN_00cf0f40(Pass* pass, int* b);
struct A1Owner
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
    unsigned char m1E4;
};
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
struct Triple
{
    unsigned int m00;
    unsigned int m04;
    unsigned int m08;
};
struct OwnerB
{
    unsigned int unk00;
    Triple m04;
};
void __cdecl FUN_00cf0930(void* a, void* b, void* c);
void __cdecl FUN_00cf0cf0(void* a, void* b);
struct TmpGuard
{
    unsigned int m0;
    unsigned int m1;
    unsigned int m2;

    TmpGuard()
    {
        m0 = 0;
        m1 = 0;
        m2 = 0x80000000;
    }
    ~TmpGuard()
    {
        AudioHolder* pHolder = reinterpret_cast<AudioHolder*>(FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        m1 = 0;
        if ((m2 & 0x80000000u) == 0)
        {
            pAllocator->Free((void*)m0, (m2 & 0x3fffffffu) * 16u);
        }
    }
};
struct FUN_00cb8010_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void v41(unsigned int a);
    virtual void* v42();
    virtual void vAC();
    virtual void vB0();
    virtual OwnerB* v45(unsigned char* pFlag);

    void __thiscall FUN_00c84d50(A1Owner* a1);
    void __thiscall FUN_00cb8010(A1Owner* a1);
};

#include <xmmintrin.h>
class hkVector4_66C
{
  public:
    hkVector4_66C(float fX, float fY, float fZ, float fW);
    void Assign(const hkVector4_66C& kOther);
    void Set(float fX, float fY, float fZ, float fW);
    __m128 m_vComponents;
};

class Filter66C
{
  public:
    Filter66C(int iLayer, int iSystem, int iPart);
    unsigned int GetValue();
    unsigned int m_uiBits;
};

class MotionType66C
{
  public:
    void Set(int iType);
    unsigned int m_uiType;
};

class BodyCinfo66C
{
  public:
    BodyCinfo66C();
    ~BodyCinfo66C();
    unsigned int m_uiFilterInfo;
    void* m_pvShape;
    MotionType66C m_kMotion;
    int unk0c;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
};

class TransformShapeInfo66C
{
  public:
    TransformShapeInfo66C();
    int unk00;
    void* m_pvChild;
    int unk08;
    int unk0c;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    hkVector4_66C m_kTranslation;
};

class CapsuleInfo66C
{
  public:
    CapsuleInfo66C();
    int unk00;
    float m_fBoundRadius;
    int unk08;
    int unk0c;
    hkVector4_66C m_kVertexA;
    hkVector4_66C m_kVertexB;
};

class SphereArray66C
{
  public:
    void PushBack(const hkVector4_66C& kSphere);
    void* m_pResource;
    int m_uiLogicalSize;
    int m_iCapacity;
};

class MultiSphereInfo66C
{
  public:
    MultiSphereInfo66C();
    ~MultiSphereInfo66C();
    int unk00;
    SphereArray66C m_kSpheres;
};

class Shape66C
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    void* GetShape();
    void* m_pvVtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class SphereShape66C : public Shape66C
{
  public:
    SphereShape66C(float fRadius, int iFlags);
};

class BoxShape66C : public Shape66C
{
  public:
    BoxShape66C(const hkVector4_66C& m_kPoint2);
};

class TransformShape66C : public Shape66C
{
  public:
    TransformShape66C(TransformShapeInfo66C& kInfo);
};

class CapsuleShape66C : public Shape66C
{
  public:
    CapsuleShape66C(CapsuleInfo66C& kInfo);
};

class MultiSphereShape66C : public Shape66C
{
  public:
    MultiSphereShape66C(MultiSphereInfo66C& kInfo);
};

class Body66C
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    Body66C(BodyCinfo66C& kInfo);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};

class Object66C
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
    Object66C(void* pvOwner);
    void SetBody(Body66C* pkBody);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
};

class Bounds66C
{
  public:
    unsigned int GetCount();
    void GetBound(unsigned int uiIndex, int* piType, float* pfCenter, float* pfSize);
};

class Havok66C
{
  public:
    bool IsEnabled(int iFlag);
};
extern Havok66C g_kHavok66C;

float __cdecl FUN_0066b0b0();
float __cdecl FUN_004a3e90(float fValue);
void __cdecl FUN_005b5e40(const char* pcMessage);

class Tree66C
{
  public:
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
    virtual void v100();
    virtual void v104();
    virtual void* GetOwner();
    void FUN_0066cb40(Bounds66C* pkBounds, float fScale);
};

// @fnv 0x0066cb40
void Tree66C::FUN_0066cb40(Bounds66C* pkBounds, float fScale)
{
    if (g_kHavok66C.IsEnabled(1))
    {
        unsigned int ItemUpdateArray = pkBounds->GetCount();
        if (!ItemUpdateArray)
            return;
        float fHavokScale = FUN_0066b0b0() * fScale;
        void* pvOwner = GetOwner();
        BodyCinfo66C kInfo;
        if (ItemUpdateArray == 1)
        {
            float afSize[3];
            float afCenter[3];
            int iType;
            pkBounds->GetBound(0, &iType, afCenter, afSize);
            afCenter[0] = FUN_004a3e90(afCenter[0]) * fHavokScale;
            afCenter[1] = FUN_004a3e90(afCenter[1]) * fHavokScale;
            afCenter[2] = FUN_004a3e90(afCenter[2]) * fHavokScale;
            afSize[0] = FUN_004a3e90(afSize[0]) * fHavokScale;
            afSize[1] = FUN_004a3e90(afSize[1]) * fHavokScale;
            afSize[2] = FUN_004a3e90(afSize[2]) * fHavokScale;
            switch (iType)
            {
            case 0: {
                TransformShapeInfo66C kTransform;
                hkVector4_66C kIntersectionOffset(afCenter[0], afCenter[1], afCenter[2], 0.0f);
                kTransform.m_kTranslation.Assign(kIntersectionOffset);
                SphereShape66C* pkSphere = new SphereShape66C(afSize[0], 0);
                kTransform.m_pvChild = pkSphere->GetShape();
                TransformShape66C* pkShape = new TransformShape66C(kTransform);
                kInfo.m_pvShape = pkShape->GetShape();
            }
            break;
            case 1: {
                CapsuleInfo66C kCapsule;
                kCapsule.m_kVertexA.Set(afCenter[0], afCenter[1], afCenter[2] + afSize[0], 0.0f);
                kCapsule.m_kVertexB.Set(afCenter[0], afCenter[1], afCenter[2] + afSize[1] - afSize[0], 0.0f);
                kCapsule.m_fBoundRadius = afSize[0];
                CapsuleShape66C* pkShape = new CapsuleShape66C(kCapsule);
                kInfo.m_pvShape = pkShape->GetShape();
            }
            break;
            case 2: {
                TransformShapeInfo66C kTransform;
                for (int i = 0; i < 3; i++)
                    afSize[i] *= 0.5;
                hkVector4_66C kIntersectionOffset(afCenter[0], afCenter[1], afCenter[2] + afSize[2], 0.0f);
                hkVector4_66C m_kPoint2(afSize[0], afSize[1], afSize[2], 0.0f);
                kTransform.m_kTranslation.Assign(kIntersectionOffset);
                BoxShape66C* pkBox = new BoxShape66C(m_kPoint2);
                kTransform.m_pvChild = pkBox->GetShape();
                TransformShape66C* pkShape = new TransformShape66C(kTransform);
                kInfo.m_pvShape = pkShape->GetShape();
            }
            break;
            }
        }
        else
        {
            MultiSphereInfo66C kSpheres;
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                float afSize[3];
                float afCenter[3];
                int iType;
                pkBounds->GetBound(i, &iType, afCenter, afSize);
                if (iType == 0)
                {
                    afCenter[0] = FUN_004a3e90(afCenter[0]) * fHavokScale;
                    afCenter[1] = FUN_004a3e90(afCenter[1]) * fHavokScale;
                    afCenter[2] = FUN_004a3e90(afCenter[2]) * fHavokScale;
                    afSize[0] = FUN_004a3e90(afSize[0]) * fHavokScale;
                    hkVector4_66C kSphere(afCenter[0], afCenter[1], afCenter[2], afSize[0]);
                    kSpheres.m_kSpheres.PushBack(kSphere);
                }
                else
                {
                    FUN_005b5e40("HAVOK: Multiple bounding volumes around a tree must all be spheres.");
                }
            }
            MultiSphereShape66C* pkShape = new MultiSphereShape66C(kSpheres);
            kInfo.m_pvShape = pkShape->GetShape();
        }
        Filter66C kFilter(9, 4, 0);
        kInfo.m_uiFilterInfo = kFilter.GetValue();
        Body66C* pkBody = new Body66C(kInfo);
        Object66C* pkObject = new Object66C(pvOwner);
        pkObject->SetBody(pkBody);
    }
}

namespace fnv_0066c160 {
struct __declspec(align(16)) xVec4
{
    float m_q[4];
    xVec4(float, float, float, float);
    xVec4(const xVec4&);
    void FUN_0066c930();
    void FUN_00627920(const struct xL&);
    xVec4 FUN_00630100() const;
    xVec4 FUN_00630b40() const;
    float FUN_004586d0() const;
};
struct __declspec(align(16)) xL
{
    xL(float);
    float m_q[4];
};
struct xP3
{
    xP3();
    float x, y, z;
    float FUN_00457990() const;
};
struct xBound
{
    xBound();
    xP3 m_pos;
    float m_iThirdValue;
    float m_10;
    unsigned char m_14;
    unsigned char m_15;
    int m_18;
    int m_1c;
    int m_20;
};
struct xEvent
{
    xEvent();
    void FUN_0066c9c0(xVec4&, xVec4&, float);
    int m_iWordAt00[8];
    int m_20;
    int m_24;
    int m_28[8];
    void* m_48;
    int m_4c;
    int m_50[10];
};
struct xForm
{
    int m_iWordAt00, m_iWordAt04;
    struct xNode* m_8;
};
struct xNode
{
    void* FUN_0044ddc0();
    unsigned int FUN_00559450();
};
struct xArr
{
    int FUN_00726070();
    xForm* FUN_0062e150(int);
};
struct __declspec(align(16)) xList
{
    xList();
    ~xList();
    xArr* FUN_00413f40();
    int m_iWordAt00;
    char m_buf[0x10c];
};
struct xHasPos
{
    xVec4* FUN_00436aa0();
};
struct xTarget;
struct xSink
{
    virtual void v0();
    virtual void v1();
    virtual void FUN_08(int, xEvent*);
};
struct xTarget
{
    char m_auiShapeKeys[0x410];
    xSink m_410;
    void FUN_0066ca00(xP3*);
};
struct xCreated
{
    xTarget* FUN_009306d0();
};
xCreated* xFUN_00c6dec0(int, void*);
void* xFUN_004b5950(void*);
struct xB
{
    xVec4* FUN_00560e50();
    void OnTrigger(xVec4*);
    void FUN_00561800(xVec4*);
};
xB* xFUN_004b59f0(void*);
xVec4* __fastcall xFUN_00560dc0(xB*);
void* __fastcall xFUN_004b4f00(xB*);
void* xFUN_004b5a80(xB*);
xP3* xFUN_00458620(xP3*, xVec4*);
void xFUN_00837550(xBound*);
float xFUN_005c5420();
float xFUN_004dfea0();
int xFUN_00944460(int, int);
float xFUN_004587d0(float);
void* xFUN_004a3a40(unsigned int);
struct xShapeX
{
    int FUN_006205a0();
};
const char* xFUN_00ec7750(const char*, const char*);
struct xIntSetting
{
    int* FUN_0043d4d0();
};
struct xFltSetting
{
    float* FUN_00403e20();
};
extern xIntSetting xg_11d5ea0;
extern xIntSetting xg_11d5e94;
extern xIntSetting xg_11d5e58;
extern xFltSetting xg_11d5e64;
struct StringProvider
{
    const char* GetUnk68();
};
struct xObj3D;
struct xObj3D
{
    virtual void v0();
    virtual void v1();
    virtual void FUN_08(void*);
    StringProvider* FUN_0084e3a0();
};

struct xObjPtr
{
    unsigned int FUN_00559450();
    xObj3D* operator->();
};
struct xRef
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
    virtual int FUN_94();
    void FUN_00623150(xList*);
    int GetSourceFilesFromObject();
};

struct xEffect
{
    char m_auiShapeKeys[0xe4];
    xObjPtr m_e4;
    bool FUN_0066ca50(float);
    xRef* FUN_0066d7c0();
    void FUN_0066c160(float afTime);
};
// @fnv 0x0066c160
void xEffect::FUN_0066c160(float afTime)
{
    if (m_e4.FUN_00559450())
        m_e4->FUN_08(this);
    if (!FUN_0066ca50(afTime))
        return;
    xRef* PREF = FUN_0066d7c0();
    if (!PREF || !PREF->FUN_94())
        return;
    const char* PTAG = xFUN_00ec7750(m_e4->FUN_0084e3a0()->GetUnk68(), "~CF");
    int LEVEL;
    if (PTAG)
        LEVEL = PTAG[3] - '0';
    else
        LEVEL = *xg_11d5ea0.FUN_0043d4d0();
    float CHANCE = LEVEL * *xg_11d5e64.FUN_00403e20() * 100.0;
    xList LIST;
    PREF->FUN_00623150(&LIST);
    xArr* ARR = LIST.FUN_00413f40();
    for (int I = 0; I < ARR->FUN_00726070(); I++)
    {
        void* PA = xFUN_004b5950(ARR->FUN_0062e150(I)->m_8);
        xB* PB = xFUN_004b59f0(ARR->FUN_0062e150(I)->m_8);
        if (PA)
        {
            xCreated* PC = xFUN_00c6dec0(0x3e8, PA);
            if (PC)
            {
                xTarget* PD = PC->FUN_009306d0();
                if (PD)
                {
                    xEvent EV;
                    xVec4 DIR(xFUN_005c5420(), xFUN_005c5420(), xFUN_005c5420(), 0.0f);
                    DIR.FUN_0066c930();
                    xVec4 POS(*((xHasPos*)ARR->FUN_0062e150(I)->m_8->FUN_0044ddc0())->FUN_00436aa0());
                    EV.FUN_0066c9c0(POS, DIR, 0.0f);
                    EV.m_20 = PREF->GetSourceFilesFromObject();
                    EV.m_48 = ARR->FUN_0062e150(I)->m_8;
                    EV.m_24 = EV.m_4c = 0;
                    PD->m_410.FUN_08(0, &EV);
                    xBound BND;
                    xP3 PT;
                    BND.m_14 = 4;
                    BND.m_15 = 7;
                    BND.m_10 = 1.0f;
                    PD->FUN_0066ca00(&PT);
                    BND.m_iThirdValue = PT.FUN_00457990();
                    BND.m_18 = (int)PA + (int)PREF;
                    BND.m_pos = *xFUN_00458620(&PT, &POS);
                    BND.m_1c = 0;
                    BND.m_20 = 0;
                    xFUN_00837550(&BND);
                }
            }
        }
        else if (PB)
        {
            if (xFUN_00944460(0, 100) <= CHANCE)
            {
                xVec4 V1(*xFUN_00560dc0(PB));
                xVec4 V2(*PB->FUN_00560e50());
                if (V1.FUN_00630100().FUN_004586d0() > 1.0)
                {
                    float SPEED = V1.FUN_00630b40().FUN_004586d0() *
                                  (1.0 - xFUN_00944460(*xg_11d5e58.FUN_0043d4d0(), *xg_11d5e94.FUN_0043d4d0()) / 100.0);
                    float R1 = xFUN_004dfea0();
                    float R2 = xFUN_004dfea0();
                    float R3 = xFUN_004dfea0() - 0.25;
                    xVec4 D1(R1, R2, R3, 0.0f);
                    D1.FUN_0066c930();
                    xL L1(SPEED);
                    D1.FUN_00627920(L1);
                    PB->OnTrigger(&D1);
                }
                if (V2.FUN_00630100().FUN_004586d0() > 1.0)
                {
                    float SPEED2 = V2.FUN_00630b40().FUN_004586d0() * (xFUN_00944460(0, 20) / 100.0 + 90.0);
                    float R4 = xFUN_004dfea0();
                    float R5 = xFUN_004dfea0();
                    float R6 = xFUN_004dfea0() - 0.25;
                    xVec4 D2(R4, R5, R6, 0.0f);
                    D2.FUN_0066c930();
                    xL L2(SPEED2);
                    D2.FUN_00627920(L2);
                    PB->FUN_00561800(&D2);
                }
                xBound BND2;
                xP3 PT2;
                xShapeX* PS = (xShapeX*)xFUN_004a3a40(ARR->FUN_0062e150(I)->m_8->FUN_00559450());
                BND2.m_14 = 4;
                BND2.m_15 = (unsigned char)(PS ? PS->FUN_006205a0() : 0);
                BND2.m_10 = 1.0f;
                BND2.m_iThirdValue = xFUN_004587d0(V1.FUN_00630b40().FUN_004586d0());
                BND2.m_18 = (int)PB + (int)PREF;
                BND2.m_pos = *xFUN_00458620(&PT2, ((xHasPos*)xFUN_004b4f00(PB))->FUN_00436aa0());
                BND2.m_1c = (int)xFUN_004b5a80(PB);
                BND2.m_20 = 0;
                xFUN_00837550(&BND2);
            }
        }
    }
}
}  // namespace fnv_0066c160
