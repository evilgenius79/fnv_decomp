
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
// @fnv 0x00c8c390
bool S_00c8c390::FUN_00c8c390(NiStream* arStream)
{
    if (this)
    {
        Mid14* v1 = p8;
        if (v1)
        {
            Mid8* v2 = v1->p14;
            if (v2)
            {
                VirtCls* v3 = v2->p8;
                if (v3)
                    v3->Target(arStream);
            }
        }
    }
    return ((HC1Base*)this)->FUN_00aa0ad0(arStream);
}

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
// @fnv 0x00c8c810
void __thiscall H_00c8c810::FUN_00c8c810(bool b)
{
    if (b)
    {
        if (this && p && p->p && p->p->p)
        {
            InterlockedIncrement(&p->p->p->_ref);
            FUN_00c84e50(b);
            return;
        }
    }
    else
    {
        FUN_00c8c770();
    }
    FUN_00c84e50(b);
}

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
// @fnv 0x00cb7750
void __thiscall S00cb7750::FUN_00cb7750()
{
    if (m_10 && m_10->m_08)
    {
        Buf00cb7750 b;
        m_10->FUN_00c9ec60(&b);
        f46(&b);
    }
}

void* __fastcall FUN_00c6b910(void*);
extern int DAT_01066b94;
struct BSFadeNode
{
    void* vf;
    char pad[16];
    static void* __cdecl operator new(unsigned int);
    BSFadeNode()
    {
        FUN_00c6b910(this);
        vf = (void*)&DAT_01066b94;
    }
};
// @fnv 0x00c87fc0
BSFadeNode* FUN_00c87fc0()
{
    return new BSFadeNode;
}

namespace fnv_00cb7640 {
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
void* __fastcall FUN_00c6b910(void*);
extern int DAT_01066acc;
struct NewObjA : BSFadeNode
{
    int a;
    int b;
    int c;
    int d;
    int e;
    NewObjA()
    {
        FUN_00c6b910(this);
        *(void**)this = &DAT_01066acc;
    }
};
// @fnv 0x00cb7640
void* FUN_00cb7640()
{
    return new NewObjA;
}
}  // namespace fnv_00cb7640

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
// @fnv 0x00c84e20
void This::FUN_00c84e20(unsigned int* output)
{
    *output = (this != 0 && middle != 0) ? middle->value : 0;
}

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
// @fnv 0x00c87f80
void LegacyLinker::FUN_00c87f80(NiStream* stream)
{
    if (stream->version >= 0x15)
        FUN_00c6bb70(stream);
    else
        NiCollisionObject::LinkObject(*stream);
}

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

// @fnv 0x00c8c330
void C8C330Owner::FUN_00c8c330(C8C330Node* pkNode)
{
    bool bCreated;
    C8C330Child* pkChild = GetOrCreateChild(&bCreated);
    C8C330Source* pkSource = pkNode->FUN_00a63430();
    pkChild->m_uiFilterValue = pkSource ? pkSource->m_uiFilterValue : 0;
    FUN_00c84cc0(pkNode);
}

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

// @fnv 0x00c8ca60
C8CA60Child* C8CA60Owner::FUN_00c8ca60(bool* pbCreated)
{
    C8CA60AllocTagScope kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (*pbCreated)
    {
        m_pkChild = new (C8CA60AlignedAlloc(0x60)) C8CA60Child();
        if (m_pParentNode)
            FUN_00c8c410(m_pkChild);
    }
    return m_pkChild;
}

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
// @fnv 0x00c8cb20
void Object::FUN_00c8cb20(StrArr* output)
{
    AutoMemContext task;
    FUN_00c851c0(output);
    output->append(FUN_00a7d330(*(void**)&g_012681b4));
    const NativeTransform* world = this && state ? &state->world : &DAT_01268370;
    NiTransform transform;
    FUN_00624b10(&transform, (NiPoint3*)world);
    FUN_00458620(&transform.translate, world->translation);
    output->append(transform.translate.FUN_00a59af0("Trans"));
    output->append(transform.ToString("Rot"));
    Component* component = getComponent();
    if (component)
        component->serialize(output);
}

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

// @fnv 0x00cb7800
void CB7800Object::FUN_00cb7800(CB7800StringArray* pkStrings)
{
    CB7800AllocTagScope kScope(0x10);
    CB7800Base::GetViewerStrings(pkStrings);
    char* pcString = FUN_00a7d330(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
}

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

// @fnv 0x00cb78b0
FUN_00cb78b0::~FUN_00cb78b0()
{
    FUN_00c876a0();
    --ms_count;
}

void FUN_00c876f0();
void FUN_00c87700();

extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_012683dc;

struct S_00cb79d0_Base
{
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
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

// @fnv 0x00cb79d0
S_00cb79d0_C* S_00cb79d0::FUN_00cb79d0(int arg)
{
    FUN_00c876f0();
    S_00cb79d0_C* obj = new S_00cb79d0_C;
    v049(obj, arg);
    FUN_00c87700();
    return obj;
}

void SwapByteQuadWords(void* buffer, int words);
struct Vector3
{
    float x;
    float y;
    float z;
};
// @fnv 0x00cf0930
void __cdecl FUN_00cf0930(void* buffer, int bytes, Vector3* vector)
{
    int words = bytes / 4;
    SwapByteQuadWords(buffer, words);
    char savedBytes[sizeof(Vector3)];
    Vector3* saved = reinterpret_cast<Vector3*>(savedBytes);
    *saved = *vector;
    SwapByteQuadWords(buffer, words);
    *vector = *saved;
}

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

// @fnv 0x00c88210
BSFadeNode* FUN_00c88210_cls::FUN_00c88210(unsigned int flags)
{
    TlsGuard_t guard;
    BSFadeNode* node = new BSFadeNode;
    this->FUN_00c6ba30(node, flags);
    return node;
}

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

// @fnv 0x00c882c0
void FUN_00c882c0_cls::FUN_00c882c0(BC882C0StringArray* pkArray)
{
    BC882C0AllocTagScope kScope(0x10);
    C882C0BaseGetViewerStrings(pkArray);
    char* pcName = FUN_00a7d330(g_pcC882C0Name);
    pkArray->Add(pcName);
}

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
// @fnv 0x00caaea0
void FUN_00caaea0_shell::FUN_00caaea0(void* context, SourceObject* source)
{
    bool flag;
    ScaleMatrix* matrix = getMatrix(&flag);
    float scale = source->scale;
    if (scale != 1.0f)
    {
        matrix->m10 *= scale;
        matrix->m14 *= scale;
        matrix->m18 *= scale;
        matrix->m1c *= scale;
        matrix->m20 *= scale;
        matrix->m24 *= scale;
        matrix->m28 *= scale;
        matrix->m2c *= scale;
        matrix->m04 *= scale;
    }
    FUN_00c84df0(context, source);
}

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

// @fnv 0x00caaf40
S_00caaf40_Obj* S_00caaf40::FUN_00caaf40(int a)
{
    S_00caaf40_Ctx ctx(0x10);
    FUN_00c876f0();
    S_00caaf40_Obj* o = new S_00caaf40_Obj;
    vfn_c4(o, a);
    FUN_00c87700();
    return o;
}

namespace fnv_00cab000 {
// FUN_00cab000 - bhkCapsuleShape::FUN_00cab000 (vtable slot 46 of .?AVbhkCapsuleShape@@)
//
// The function is a __thiscall member with one 4-byte stack argument (a bool* out flag).
// It runs under the per-thread recursion guard that lives in the thread-local block at
// offset +0x2b4, allocates a 0x30 byte object from the memory manager on first use,
// fills in the object's matrix area and then hands the object to FUN_00caade0.

// ---------------------------------------------------------------------------
// The thread-local block.  Only the guard word at +0x2b4 is touched; the rest of
// the block is padding so that the guard word sits at its original offset.
// ---------------------------------------------------------------------------
struct TlsBlock_t
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
    int unk2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

// The recursion guard: remember the old guard word, then mark the slot busy.
// The compiler keeps the guard word in a frame slot and restores it in the
// destructor, which is also what produces the exception-handling frame.
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.unk2b4;
        g_tlsBlock.unk2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.unk2b4 = m_saved;
    }
};

// ---------------------------------------------------------------------------
// The memory manager that hands out the object's memory.
// ---------------------------------------------------------------------------
struct MemoryManager
{
    void* Allocate(unsigned int size);
};

extern MemoryManager g_memoryManager;

// The game's default radius (0.1f) lives in this float table.
extern float DAT_010c72bc[];

// ---------------------------------------------------------------------------
// The 0x30 byte object that is allocated on first use.
// The eight matrix floats at +0x10 are volatile because the original initialiser
// writes the whole matrix area and then rewrites part of it: a plain store that
// is overwritten later is deleted by the optimiser, a volatile one is kept.
// ---------------------------------------------------------------------------
struct BhkAllocObj
{
    int unk00;
    float unk04;
    int unk08;
    int unk0c;
    volatile float unk10;
    volatile float unk14;
    volatile float unk18;
    volatile float unk1c;
    volatile float unk20;
    volatile float unk24;
    volatile float unk28;
    volatile float unk2c;
};

// ---------------------------------------------------------------------------
// The shape itself.
// ---------------------------------------------------------------------------
struct BhkCap_00cab000
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00caade0(BhkAllocObj* p);
    int FUN_00cab000(bool* out);
};

// @fnv 0x00cab000
int BhkCap_00cab000::FUN_00cab000(bool* out)
{
    TlsGuard_t guard;

    bool b = (unk0c == 0);
    *out = b;
    if (b)
    {
        BhkAllocObj* p = (BhkAllocObj*)g_memoryManager.Allocate(0x30);
        if (p)
        {
            p->unk00 = 0;
            p->unk04 = DAT_010c72bc[0];
            p->unk10 = 0.0f;
            p->unk14 = 0.0f;
            p->unk18 = 0.0f;
            p->unk1c = 0.0f;
            p->unk20 = 0.0f;
            p->unk24 = 0.0f;
            p->unk28 = 0.0f;
            p->unk2c = 0.0f;
            p->unk20 = 1.0f;
            p->unk24 = 0.0f;
            p->unk28 = 0.0f;
            p->unk2c = 0.0f;
        }
        else
        {
            p = 0;
        }
        unk0c = (int)p;
        if (unk08 != 0)
        {
            FUN_00caade0(p);
        }
    }
    return unk0c;
}
}  // namespace fnv_00cab000

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
    static void operator delete(void* p);
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

// @fnv 0x00cab0e0
void Owner::FUN_00cab0e0(int a, int b, float c)
{
    ScopedContext scope(0x10);
    FUN_00d22590* e = new FUN_00d22590(a, b, c);
    AddElement(e);
    e->FUN_00c905b0();
}

namespace fnv_00cab8c0 {
struct S_00cab8c0_Tls
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
__declspec(thread) S_00cab8c0_Tls DAT_tls;

struct S_00cab8c0_Ctx
{
    int saved;
    __forceinline S_00cab8c0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00cab8c0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};
struct S_00cab8c0_Arr
{
    int unk00;
    int unk04;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short unk0c;
    unsigned short m_grow;
    void SetSize(unsigned n);
    void SetAt(unsigned i, char* const& e);
};
extern int DAT_0126832c;
char* FUN_00a7d330(int s);
struct S_00cab8c0_Owner
{
    void FUN_00c9fc50(S_00cab8c0_Arr* a);
    void FUN_00cab8c0(S_00cab8c0_Arr* a);
};
// @fnv 0x00cab8c0
void S_00cab8c0_Owner::FUN_00cab8c0(S_00cab8c0_Arr* a)
{
    S_00cab8c0_Ctx guard(0x10);
    FUN_00c9fc50(a);
    char* s = FUN_00a7d330(DAT_0126832c);
    unsigned idx = a->m_uiItemCount;
    if (idx >= a->m_iElementCount)
        a->SetSize(idx + a->m_grow);
    a->SetAt(idx, s);
}
}  // namespace fnv_00cab8c0

namespace fnv_00cb76a0 {
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

extern int DAT_01066acc;

struct SpawnedFade
{
    void* vf;
    char pad[16];

    static void* __cdecl operator new(unsigned int);
    SpawnedFade()
    {
        FUN_00c6b910(this);
        vf = (void*)&DAT_01066acc;
    }
};

struct FUN_00cb76a0_cls
{
    void __thiscall FUN_00c657f0(void* obj, unsigned int arg);
    void* FUN_00cb76a0(unsigned int arg);
};

// @fnv 0x00cb76a0
void* FUN_00cb76a0_cls::FUN_00cb76a0(unsigned int arg)
{
    TlsGuard_t guard;
    SpawnedFade* obj = new SpawnedFade;
    this->FUN_00c657f0(obj, arg);
    return obj;
}
}  // namespace fnv_00cb76a0

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

// @fnv 0x00cb7790
void FUN_00cb7790_class::FUN_00cb7790()
{
    FUN_00cb7790_receiver* target = receiver;
    FUN_00cb7790_node* source = node;
    if (source)
    {
        source->FUN_00a68bf0();
        if (target && target->object)
        {
            Buf00cb7750 transform = source->transform;
            DAT_01267b80.Lock(0);
            target->FUN_0056df20(&transform);
            if (--DAT_01267b80.depth == 0)
                DAT_01267b80.owner = 0;
        }
    }
}

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

// @fnv 0x00cb7920
Node* FUN_00cb7920()
{
    Node* p = (Node*)opnew(0x14);
    {
        Guard g(p);
        if (p)
        {
            p->Init();
            p->vf = (void*)&g_vtblShape;
            p->m_0c = 0;
            p->m_10 = 0;
            ++g_nShape;
            p->vf = (void*)&g_vtblSphereRep;
            ++g_nSphereRep;
            p->vf = (void*)&g_vtblMultiSphere;
            ++g_nMultiSphere;
            return p;
        }
        return 0;
    }
}

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

// @fnv 0x00cb7b20
void Shader::FUN_00cb7b20(Pass* pass)
{
    Pass* p = pass;
    FUN_00c84d00(p);
    int* data = f45(&pass);
    if (*((char*)p + 0x1e5) != 1)
    {
        int r = f42();
        FUN_00cf0930(data, r, data + 1);
    }
    FUN_00cf0f40(p, data + 1);
}

namespace fnv_00cb7b80 {
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

extern "C" void* __cdecl FUN_00c85750();

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct SpawnArgs
{
    int unk00;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
};

struct SpawnAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
};

struct SpawnHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnAllocator* m_alloc;
};

struct SpawnedNode
{
    void* m_vtbl;
    unsigned short m_iElementCount;
    unsigned short unk06;
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
    SpawnedNode(unsigned int a, unsigned int b);
    void Finish();
    static void operator delete(void* p) throw()
    {}
    static void* operator new(unsigned int size) throw()
    {
        SpawnHolder* h = (SpawnHolder*)FUN_00c85750();
        void* p = h->m_alloc->Alloc(size);
        ((SpawnedNode*)p)->m_iElementCount = (unsigned short)size;
        return p;
    }
};

struct FUN_00cb7b80_cls
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
    virtual void v35(SpawnedNode* n);
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
    virtual void v47(SpawnArgs* a);
    void FUN_00cb7b80(SpawnArgs* a);
};

// @fnv 0x00cb7b80
void FUN_00cb7b80_cls::FUN_00cb7b80(SpawnArgs* a)
{
    TlsGuard guard;
    unsigned int b, c;
    SpawnedNode* n = new SpawnedNode(c = a->m_kPointA, b = a->m_kPointB);
    this->v35(n);
    n->Finish();
    this->v47(a);
}
}  // namespace fnv_00cb7b80

namespace fnv_00cb8150 {
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();

struct CbAlloc8150
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct BSAudio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CbAlloc8150* m_pAllocator;
};

struct CbArr8150
{
    int unk00;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    CbArr8150() : unk00(0), m_pData(0), m_iArrayLength(0), m_uCapBits(0x80000000u)
    {}
    ~CbArr8150()
    {
        BSAudio* pHolder = FUN_00c85750();
        CbAlloc8150* pAllocator = pHolder->m_pAllocator;
        m_iArrayLength = 0;
        unsigned int uCapBits = m_uCapBits;
        if ((uCapBits & 0x80000000u) == 0)
        {
            pAllocator->FreeArray(m_pData, (uCapBits & 0x3fffffffu) * 16);
        }
        m_pData = 0;
        m_uCapBits = 0x80000000u;
    }
};

extern "C" unsigned char __stdcall FUN_00c84dc0(void* a1);
extern "C" unsigned char __cdecl FUN_00cf08c0(int* pA, void** pB);

struct FUN_00cb8150_cls
{
    int unk00;
    void FUN_00cb7c60(CbArr8150* p);

    unsigned char FUN_00cb8150(void* a1);
};

// @fnv 0x00cb8150
unsigned char FUN_00cb8150_cls::FUN_00cb8150(void* a1)
{
    FUN_00cb8150_cls* other = (FUN_00cb8150_cls*)a1;
    unsigned char r = FUN_00c84dc0(a1);
    if (r != 0)
    {
        CbArr8150 a;
        CbArr8150 b;
        this->FUN_00cb7c60(&a);
        other->FUN_00cb7c60(&b);
        r = FUN_00cf08c0((int*)&a.m_pData, (void**)&b.m_pData);
    }
    return r;
}
}  // namespace fnv_00cb8150

namespace fnv_00cb8330 {
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

struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct S_00cb8330_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int bytes) throw();
};
struct S_00cb8330_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cb8330_Heap* m_pStreamAllocator;
    S_00cb8330_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" S_00cb8330_Router* __cdecl FUN_00c85750();
struct S_00cb8330_Pool
{
    void FUN_00aa4060(void* p);
};
extern S_00cb8330_Pool DAT_011f6238;
struct S_00cb8330_Obj
{
    int unk00;
    void* m_data;
    int m_iElementCount;
    int m_cap;
};
struct S_00cb8330_cls
{
    int unk00;
    int unk04;
    int unk08;
    S_00cb8330_Obj* m_0c;
    void FUN_00cb8330(bool bFree);
};
// @fnv 0x00cb8330
void S_00cb8330_cls::FUN_00cb8330(bool bFree)
{
    TlsGuard guard;
    if (bFree)
    {
        S_00cb8330_Obj* p = m_0c;
        if (p)
        {
            S_00cb8330_Heap& h = FUN_00c85750()->heap();
            int cap = p->m_cap;
            p->m_iElementCount = 0;
            if ((cap & 0x80000000) == 0)
                h.v10(p->m_data, (cap & 0x3fffffff) * 16);
            p->m_data = 0;
            p->m_cap = 0x80000000;
            DAT_011f6238.FUN_00aa4060(p);
        }
        m_0c = 0;
    }
}
}  // namespace fnv_00cb8330

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

// @fnv 0x00cb8010
void __thiscall FUN_00cb8010_cls::FUN_00cb8010(A1Owner* a1)
{
    unsigned int flagSlot;
    OwnerB* p = this->v45((unsigned char*)&flagSlot);
    TmpGuard tmp;
    Triple* src = &p->m04;
    unsigned int s0 = src->m00;
    tmp.m0 = s0;
    src->m00 = 0;
    unsigned int t1 = tmp.m1;
    unsigned int s1 = src->m04;
    tmp.m1 = s1;
    src->m04 = t1;
    unsigned int t2 = tmp.m2;
    unsigned int s2 = src->m08;
    tmp.m2 = s2;
    src->m08 = t2;

    if (a1->m1E4 != 1)
    {
        void* r = this->v42();
        FUN_00cf0930(p, r, &p->m04);
    }
    this->FUN_00c84d50(a1);
    FUN_00cf0cf0(a1, &tmp);
    this->v41(flagSlot);
    if (*(unsigned char*)&flagSlot == 0 && a1->m1E4 != 1)
    {
        void* r = this->v42();
        FUN_00cf0930(p, r, &p->m04);
    }
}

struct CTarget
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual bool vf0D0(int value);
};

struct CLevel2
{
    int unk00;
    int unk04;
    CTarget* unk08;
};

struct CLevel1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    CLevel2* unk14;
};

struct CObj
{
    int unk00;
    int unk04;
    CLevel1* unk08;

    bool __thiscall FUN_00c8c3d0(int value);
};

bool __stdcall FUN_00c84ec0(void* value);

inline bool Walk(CObj* o, int v, bool r)
{
    if (o)
    {
        CLevel1* l = o->unk08;
        if (l)
        {
            CLevel2* l2 = l->unk14;
            if (l2)
            {
                CTarget* t = l2->unk08;
                if (t)
                    r = t->vf0D0(v);
            }
        }
    }
    return r;
}
// @fnv 0x00c8c3d0
bool __thiscall CObj::FUN_00c8c3d0(int value)
{
    bool r = FUN_00c84ec0((void*)value);
    if (r)
        r = Walk(this, value, r);
    return r;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
// @fnv 0x00c8c020
void __cdecl FUN_00c8c020(unsigned int* apData)
{
    *(volatile unsigned int*)&apData[0] = _byteswap_ulong(*(volatile unsigned int*)&apData[0]);
    *(volatile unsigned int*)&apData[1] = _byteswap_ulong(*(volatile unsigned int*)&apData[1]);
    *(volatile unsigned int*)&apData[2] = _byteswap_ulong(*(volatile unsigned int*)&apData[2]);
    *(volatile unsigned int*)&apData[3] = _byteswap_ulong(*(volatile unsigned int*)&apData[3]);
    *(volatile unsigned int*)&apData[4] = _byteswap_ulong(*(volatile unsigned int*)&apData[4]);
    *(volatile unsigned int*)&apData[5] = _byteswap_ulong(*(volatile unsigned int*)&apData[5]);
    *(volatile unsigned int*)&apData[6] = _byteswap_ulong(*(volatile unsigned int*)&apData[6]);
    *(volatile unsigned int*)&apData[7] = _byteswap_ulong(*(volatile unsigned int*)&apData[7]);
    *(volatile unsigned int*)&apData[8] = _byteswap_ulong(*(volatile unsigned int*)&apData[8]);
    *(volatile unsigned int*)&apData[9] = _byteswap_ulong(*(volatile unsigned int*)&apData[9]);
    *(volatile unsigned int*)&apData[10] = _byteswap_ulong(*(volatile unsigned int*)&apData[10]);
    *(volatile unsigned int*)&apData[11] = _byteswap_ulong(*(volatile unsigned int*)&apData[11]);
}

struct FUN_00c8c1e0_arg
{
    int unk00;
    unsigned int m04;
    void FUN_00a645b0();
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};

struct FUN_00c8c1e0_sub
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
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
    void Flush();
};

struct FUN_00c8c1e0_rec
{
    int unk00;
    unsigned int m04;
    int unk08;
    int unk0C;
    FUN_00c8c1e0_sub sub;
};

extern "C" void __cdecl FUN_00c8c020(void* p);

struct FUN_00c8c1e0_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual FUN_00c8c1e0_rec* GetRec(FUN_00c8c1e0_arg*& a);
    void FUN_00c84d00(FUN_00c8c1e0_arg* a);
    void FUN_00c8c1e0(FUN_00c8c1e0_arg* a1);
};

// @fnv 0x00c8c1e0
void FUN_00c8c1e0_cls::FUN_00c8c1e0(FUN_00c8c1e0_arg* a1)
{
    FUN_00c8c1e0_rec* r;
    FUN_00c8c1e0_arg* volatile* pa = &a1;
    FUN_00c8c1e0_arg* a = *pa;
    a->FUN_00a645b0();
    FUN_00c84d00(a);
    r = GetRec(a1);
    r->m04 = 0;
    if (a->m1E5 != 1)
    {
        FUN_00c8c1e0_sub* s = &r->sub;
        volatile unsigned int* w = &s->m30;
        w[0] = _byteswap_ulong(w[0]);
        w[1] = _byteswap_ulong(w[1]);
        w[2] = _byteswap_ulong(w[2]);
        w[3] = _byteswap_ulong(w[3]);
        FUN_00c8c020(s);
    }
    if (a->m04 < 0x32)
    {
        r->sub.Flush();
    }
}

struct C8C260Block
{
    int unk00;
    int m_flags;
    int unk08;
    int unk0C;
    int m_kHeader[12];
    unsigned int m_iSlotIds[4];
};

void __cdecl FUN_00c8c020(int* header);

inline void C8C260Swap32(unsigned int* p)
{
    *p = _byteswap_ulong(*p);
}

struct C8C260Renderer
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void SetTarget(void* target);

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
    unsigned char m_ucLittleEndian;
};

inline void C8C260Prepare(C8C260Block* block, C8C260Renderer* pkRenderer)
{
    block->m_flags = 0;
    if (pkRenderer->m_ucLittleEndian != 1)
    {
        int* header = block->m_kHeader;
        C8C260Swap32((unsigned int*)(header + 12));
        C8C260Swap32((unsigned int*)(header + 13));
        C8C260Swap32((unsigned int*)(header + 14));
        C8C260Swap32((unsigned int*)(header + 15));
        FUN_00c8c020(header);
    }
}

struct C8C260Inner
{
    int unk00;
    int unk04;
    void* m_target;
};

struct C8C260Link
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C8C260Inner* m_inner;
};

struct C8C260Shader
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
    virtual C8C260Block* GetBlock(bool* pbCreated);

    int unk04;
    C8C260Link* m_link;

    void FUN_00c84d50(C8C260Renderer* pkRenderer);
    void FUN_00c8c260(C8C260Renderer* pkRenderer);
};

inline void* C8C260GetTarget(C8C260Shader* p)
{
    return (p && p->m_link && p->m_link->m_inner) ? p->m_link->m_inner->m_target : 0;
}

// @fnv 0x00c8c260
void C8C260Shader::FUN_00c8c260(C8C260Renderer* pkRenderer)
{
    pkRenderer->SetTarget(C8C260GetTarget(this));
    bool bCreated;
    C8C260Block* pkBlock = GetBlock(&bCreated);
    C8C260Prepare(pkBlock, pkRenderer);
    FUN_00c84d50(pkRenderer);
    C8C260Prepare(pkBlock, pkRenderer);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

typedef void(__thiscall* ReleaseFn_t)(S_00c8c810_A* apObj);

// @fnv 0x00c8c770
void H_00c8c810::FUN_00c8c770()
{
    TlsGuard_t guard;
    if (this != 0)
    {
        S_00c8c810_C* pC = this->p;
        if (pC != 0)
        {
            S_00c8c810_B* pB = pC->p;
            if (pB != 0)
            {
                S_00c8c810_A* pA = pB->p;
                if (pA != 0)
                {
                    if (InterlockedDecrement(&pA->_ref) == 0)
                    {
                        void** vt = *(void***)pA;
                        ReleaseFn_t fn = (ReleaseFn_t)vt[1];
                        fn(pA);
                    }
                }
            }
        }
    }
}

namespace fnv_00c8c130 {
struct RenderArg
{
    unsigned int unknown0, unknown4, unknown8, unknownC;
    float alpha;
};
struct Holder;
struct HolderResult;
struct RenderResult;
struct RenderNode
{
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
    virtual HolderResult* Fetch(RenderArg*);
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
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual bool NeedsRefresh(RenderArg*);
};
struct Holder
{
    unsigned int value00, value04;
    RenderNode* node08;
};
struct HolderResult
{
    unsigned int value00, value04;
    Holder* link08;
};
struct RenderResult
{
    unsigned int unknown00;
    Holder* holder04;
    unsigned int unused8;
    unsigned int unused12;
    unsigned int unused16;
    unsigned int unused20;
    unsigned int unused24;
    unsigned int unused28;
    unsigned int unused32;
    unsigned int unused36;
    unsigned int unused40;
    unsigned int unused44;
    unsigned int unused48;
    unsigned int unused52;
    unsigned int unused56;
    unsigned int unused60;
    volatile float colour40;
    float colour44;
    volatile float colour48;
    float colour4C;
};
struct RenderProcessor
{
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
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual RenderResult* GetRendered(unsigned char*);
    void FUN_00c84df0(void* input, RenderArg* arg);
    void FUN_00c8c130(void* input, RenderArg* arg);
};
// @fnv 0x00c8c130
void RenderProcessor::FUN_00c8c130(void* input, RenderArg* arg)
{
    unsigned char ignored;
    RenderResult* result = GetRendered(&ignored);
    RenderNode* node = result->holder04 ? result->holder04->node08 : 0;
    float alpha = arg->alpha;
    if (alpha != 1.0f)
    {
        result->colour40 = result->colour40 * alpha;
        result->colour44 *= alpha;
        result->colour48 *= alpha;
        result->colour4C *= alpha;
    }
    else
    {
        if (node == 0)
            goto complete;
        if (node->NeedsRefresh(arg))
            goto complete;
    }
    {
        HolderResult* replacement = node->Fetch(arg);
        result->holder04 = replacement ? replacement->link08 : 0;
    }
complete:
    FUN_00c84df0(input, arg);
}
}  // namespace fnv_00c8c130

namespace fnv_00c8c4d0 {
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

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern "C" void __cdecl FUN_00c876f0();
extern "C" void __cdecl FUN_00c87700();
extern "C" char DAT_01030bf4[];
extern "C" char DAT_01066d44[];
extern "C" int DAT_012680f8;
extern "C" int DAT_012681b0;

struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void ctorBase();
    SpawnedObject()
    {
        ctorBase();
        m_vtbl = (void*)DAT_01030bf4;
        unk0C = 0;
        unk10 = 0;
        DAT_012680f8++;
        m_vtbl = (void*)DAT_01066d44;
        DAT_012681b0++;
    }
    void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
};

struct FUN_00c8c4d0_cls
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
    virtual void v49(SpawnedObject* obj, int a1);
    SpawnedObject* FUN_00c8c4d0(int a1);
};

// @fnv 0x00c8c4d0
SpawnedObject* FUN_00c8c4d0_cls::FUN_00c8c4d0(int a1)
{
    TlsGuard_t guard;
    FUN_00c876f0();
    SpawnedObject* p = new SpawnedObject();
    this->v49(p, a1);
    FUN_00c87700();
    return p;
}
}  // namespace fnv_00c8c4d0

namespace fnv_00cb8270 {
extern __declspec(thread) int g_tlsMemContext;

struct S_00cb8270_MM
{
    void* FUN_00aa3e40(unsigned int);
};
extern S_00cb8270_MM DAT_011f6238;

struct S_00cb8270_Array
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;

    void* operator new(unsigned int sz)
    {
        return DAT_011f6238.FUN_00aa3e40(sz);
    }
    void operator delete(void*)
    {}

    S_00cb8270_Array() : unk00(0), unk04(0), unk08(0), unk0C(0x80000000)
    {}
};

struct AutoMemContext
{
    int m_oldContext;
    AutoMemContext(int newContext)
    {
        m_oldContext = g_tlsMemContext;
        g_tlsMemContext = newContext;
    }
    ~AutoMemContext()
    {
        g_tlsMemContext = m_oldContext;
    }
};

struct S_00cb8270
{
    int unk00;
    int unk04;
    int unk08;
    S_00cb8270_Array* unk0C;

    void FUN_00cb7c60(S_00cb8270_Array*);

    S_00cb8270_Array* FUN_00cb8270(bool& outCreated);
};

// @fnv 0x00cb8270
S_00cb8270_Array* S_00cb8270::FUN_00cb8270(bool& outCreated)
{
    AutoMemContext memContext(0x10);

    bool created = (unk0C == 0);
    outCreated = created;
    if (created)
    {
        S_00cb8270_Array* arr = new S_00cb8270_Array();
        unk0C = arr;
        if (unk08 != 0)
        {
            FUN_00cb7c60(arr);
        }
    }
    return unk0C;
}
}  // namespace fnv_00cb8270

struct CollisionStreamLoader : NiCollisionObject
{
    void __thiscall FUN_00c6c330(NiStream& stream);
    void __thiscall FUN_00a80fd0(NiStream& stream);
};

struct LegacyCollisionLoader : CollisionStreamLoader
{
    void __thiscall FUN_00c87f60(NiStream& stream);
};

// @fnv 0x00c87f60
void __thiscall LegacyCollisionLoader::FUN_00c87f60(NiStream& stream)
{
    if (stream.version >= 0x15)
    {
        FUN_00c6c330(stream);
    }
    else
    {
        FUN_00a80fd0(stream);
    }
}
