
// src/fallout_shared/tempeffects/bstempeffectparticle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectparticle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SndX
{
    bool IsValid();
    void Stop();
    void PausePlayback();
};

struct FUN_0068a850_shell
{
    SndX m_snd0;  // +0x5c
    SndX m_snd1;  // +0x68
    void StopSounds();
};

// @fnv 0x0068a850
void FUN_0068a850_shell::StopSounds()
{
    if (reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)->IsValid())
    {
        reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)->Stop();
        if (reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)->IsValid())
            reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)->PausePlayback();
    }
    if (reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)->IsValid())
    {
        reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)->Stop();
        if (reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)->IsValid())
            reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)->PausePlayback();
    }
}

extern int* DAT_011c61ec;

// @fnv 0x00891350
int* __cdecl FUN_00891350()
{
    return DAT_011c61ec;
}

struct NiRTTI
{
    virtual ~NiRTTI();
};
struct GlobalObject_00a7b610 : public NiRTTI
{
};
extern GlobalObject_00a7b610 g_011d6b84;

struct FUN_00688f80_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x00688f80
const NiRTTI* __thiscall FUN_00688f80_shell::GetRTTI() const
{
    return &g_011d6b84;
}

void _delete(void* ptr, unsigned int size);

struct FUN_00688f90_shell
{
    void FUN_00689720();
    void* FUN_00688f90(unsigned int flags);
};

// Calls FUN_00689720, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00688f90
void* FUN_00688f90_shell::FUN_00688f90(unsigned int flags)
{
    this->FUN_00689720();
    if (flags & 1)
        _delete(this, 0x74);
    return this;
}

struct Flt
{
    operator unsigned int() const;
};

struct BSTempEffectParticle
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    Flt m_flt;              // +0x18
    const char* pFilename;  // +0x1c
    bool FUN_00689af0();
};

// Returns true when pFilename is non-null and m_flt converts to a non-zero unsigned int, otherwise false.
// @fnv 0x00689af0
bool BSTempEffectParticle::FUN_00689af0()
{
    if (!(pFilename && (unsigned int)m_flt))
        return false;
    return true;
}

struct NiNode
{
    virtual ~NiNode();
    virtual void f1();
    virtual void f2();
    virtual NiNode* f3();
};
void __cdecl FUN_00578170(NiNode*);
struct DetachHost : BSTempEffectParticle
{
    void FUN_006896c0();
};
// Gets the node from m_flt via f3 and, if non-null, passes it to FUN_00578170.
// @fnv 0x006896c0
void DetachHost::FUN_006896c0()
{
    NiNode* pnode = m_flt ? ((NiNode*)(unsigned int)m_flt)->f3() : 0;
    if (pnode)
        FUN_00578170(pnode);
}

extern "C" void __cdecl InitLoopSounds(void*);

struct FUN_0068a8d0_shell
{
    char pad[0x58];
    void* m_58;
    void __thiscall FUN_0068a8d0(void* a);
};

// @fnv 0x0068a8d0
void __thiscall FUN_0068a8d0_shell::FUN_0068a8d0(void* pValue)
{
    m_58 = pValue;
    ((void(__thiscall*)(void*))InitLoopSounds)(this);
}

struct NiFixedString
{
    const char* m_pString;
    NiFixedString(const char*);
    ~NiFixedString();
};

struct BSFadeNode : public NiFixedString
{
    BSFadeNode(const char*);
};

struct Model
{
    NiNode* GetObject3D();
};

struct NiControllerSequence
{
    float FUN_00508100();
};

struct NiControllerManager
{
    NiControllerSequence* FindSequenceByName(const NiFixedString&);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
};

extern NiRTTI DAT_011f36ac;

NiControllerManager* _UseSaveGameBlocks(const NiRTTI*, NiNode*);

struct FUN_00689920_shell
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    float m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    Flt m_flt;

    void FUN_00689920(const char*);
};

// @fnv 0x00689920
void FUN_00689920_shell::FUN_00689920(const char* name)
{
    NiControllerManager* controllerManager =
        _UseSaveGameBlocks(&DAT_011f36ac, reinterpret_cast<Model*>(m_flt.operator unsigned int())->GetObject3D());

    if (controllerManager)
    {
        NiControllerSequence* controllerSequence = controllerManager->FindSequenceByName(BSFadeNode(name));

        if (controllerSequence)
        {
            controllerManager->ActivateControllerSequence(controllerSequence, 0, 0, 1.0f, 0.0f, 0);

            float duration = controllerSequence->FUN_00508100();
            if (duration > m_iThirdValue)
            {
                m_iThirdValue = duration;
            }
        }
    }
}

struct Tgt;
struct Yv
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
    virtual void v3a(Tgt*);
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
};
struct Tgt;
struct Sub18
{
    int m0;
    Tgt* m1;
    ~Sub18();
    Tgt* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Sub5c
{
    char p[12];
    ~Sub5c();
};
struct Mgr
{
    void FUN_00445300(Tgt*, int, int);
};
extern Mgr* DAT_011c3b3c;
struct Fn
{
    Yv* FUN_009611e0();
};
struct Base
{
    int b4, b8, bc, b10, b14;
    virtual ~Base();
};
struct FUN_00689720 : Base
{
    Sub18 a;
    Sub18 b;
    char pad[0x5c - 0x28];
    Sub5c c;
    Sub5c d;
    void StopSounds();
    virtual ~FUN_00689720();
};
// @fnv 0x00689720
FUN_00689720::~FUN_00689720()
{
    StopSounds();
    if (a.m1)
        DAT_011c3b3c->FUN_00445300(a.m1, 0, 1);
    if (a.FUN_00559450())
    {
        if (((Fn*)a.FUN_00559450())->FUN_009611e0())
        {
            ((Fn*)a.FUN_00559450())->FUN_009611e0()->v3a(a.FUN_00559450());
        }
    }
    a.FUN_0066b0d0(0);
}

extern const float DAT_01012054;
float __cdecl FUN_00404010(float lhs, float rhs);

struct TrailEntry
{
    double FUN_004a7bd0();
    double FUN_0047c860();
    TrailEntry* FUN_004a8a90();
};

struct TraversalItem
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TraversalItem* v3();
    TrailEntry* FUN_0043b230();
    int FUN_00453470();
    TraversalItem* FUN_0043b4a0(int index);
};

struct FUN_00689840_Class
{
    float ComputeTraversalValue(TraversalItem* entry);
};

// @fnv 0x00689840
float FUN_00689840_Class::ComputeTraversalValue(TraversalItem* entry)
{
    float accumulator = DAT_01012054;
    TrailEntry* pTrail = entry->FUN_0043b230();
    while (pTrail != 0)
    {
        accumulator = FUN_00404010(accumulator, static_cast<float>(pTrail->FUN_004a7bd0() - pTrail->FUN_0047c860()));
        pTrail = pTrail->FUN_004a8a90();
    }

    TraversalItem* children = entry->v3();
    if (children != 0)
    {
        int iChildCount = children->FUN_00453470();
        for (int i = 0; i < iChildCount; ++i)
        {
            TraversalItem* child = children->FUN_0043b4a0(i);
            if (child != 0)
                accumulator = FUN_00404010(accumulator, ComputeTraversalValue(child));
        }
    }
    return accumulator;
}

struct DataModel
{
    void* __thiscall FUN_0043b230();
};
struct DataHandle
{
    DataModel* __thiscall FUN_00559450();
};
struct GlobalState
{
    bool __thiscall FUN_00862110();
    void* __thiscall FUN_004fd3e0();
};
struct LoggingFlag
{
    unsigned char* __thiscall FUN_00408d60();
};
struct LoggingObject
{
    void** vtable;
};
struct ParticleEffect
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    DataHandle handle;
    char const* filename;
    unsigned short __thiscall FUN_006828e0();
    unsigned short __thiscall FUN_00689b20();
};
extern GlobalState* DAT_011de45c;
extern LoggingFlag DAT_011de4e8;
extern char DAT_01012c78[];
extern char DAT_01012cb0[];
extern char DAT_01069d20[];
extern "C" int __cdecl FUN_0044a670(char const*);
extern "C" void* __cdecl FUN_00653270(void*, void*);
extern "C" unsigned short __cdecl FUN_0055fdb0(void*);
extern "C" LoggingObject* __cdecl LookupFormByID(void*);
extern "C" void __cdecl FUN_0040fbe0(char const*, ...);
typedef void*(__thiscall* LogMethod)(LoggingObject*);
// @fnv 0x00689b20
unsigned short ParticleEffect::FUN_00689b20()
{
    unsigned short previous = 0;
    unsigned short total = previous;
    if (DAT_011de45c->FUN_00862110())
    {
        previous += 4;
        previous += 2;
    }
    previous += FUN_006828e0();
    previous += 1;
    previous += FUN_0044a670(filename);
    previous += 0x10;
    previous += 0xc;
    previous += 4;
    previous += 2;
    void* active = FUN_00653270(&DAT_011f36ac, handle.FUN_00559450()->FUN_0043b230());
    if (active != 0)
    {
        previous += FUN_0055fdb0(active);
    }
    if (*DAT_011de4e8.FUN_00408d60())
    {
        void* entry = DAT_011de45c->FUN_004fd3e0();
        if (entry)
        {
            LoggingObject* writer = LookupFormByID(*(void**)entry);
            FUN_0040fbe0(DAT_01012cb0, previous - total, *(void**)entry, ((LogMethod*)writer->vtable)[76](writer),
                         *(void**)((char*)entry + 5), 0x174, DAT_01069d20);
        }
        else
        {
            FUN_0040fbe0(DAT_01012c78, previous - total, 0x174, DAT_01069d20);
        }
    }
    return previous;
}

struct Vec3
{
    float x, y, z;
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_004a0c90(float);
    void FUN_0043f8d0(Matrix&, const Matrix&);
};
struct NiPoint3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3();
    void FUN_004a0c90(float);
};
float __cdecl FUN_004a4240();
struct Rotation
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Rotation();
    void FUN_0043f8d0(Matrix&, const NiPoint3&);
};
Rotation __cdecl FUN_00c4b8a0(Vec3);
struct World
{
    void* FUN_00456fc0(int);
};
struct Effect
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Effect(World*, float, int, int);
    void AttachModel(void*, Matrix, Vec3, float, int);
};
struct Manager
{
    void FUN_00973fd0(Effect*);
};
extern Manager DAT_011e0e80;
// @fnv 0x006890b0
Effect* __cdecl FUN_006890b0(World* world, float duration, int kind, Vec3 rotation, Vec3 position, float scale,
                             int flags, int extra)
{
    Effect* pEffect = 0;
    if (world)
    {
        pEffect = new Effect(world, duration, kind, extra);
        float node = FUN_004a4240();
        NiPoint3 matrix2;
        matrix2.FUN_004a0c90(node);
        Matrix a;
        FUN_00c4b8a0(rotation).FUN_0043f8d0(a, matrix2);
        void* transform = world->FUN_00456fc0(4);
        pEffect->AttachModel(transform, a, position, scale, flags);
        DAT_011e0e80.FUN_00973fd0(pEffect);
    }
    return pEffect;
}

struct Block9
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
};
struct Block3
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct FUN_00c335d0
{
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};
struct FUN_00456fc0_cls
{
    void* FUN_00456fc0(unsigned int a);
};
struct FUN_00688fc0 : FUN_00c335d0
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
    FUN_00688fc0(void* a, float b, unsigned int c, unsigned int d);
    void AttachModel(void* a, Block9 b, Block3 c, float d, unsigned int f);
};
struct GlobalObject_0096d020
{
    void FUN_00973fd0(void* a);
};
extern GlobalObject_0096d020 g_011e0e80;

// @fnv 0x00689210
void* __cdecl FUN_00689210(void* a, float fValue, unsigned int uiFlags, Block9 d, Block3 e, float fParam,
                           unsigned int uiParam, unsigned int uiExtra)
{
    FUN_00688fc0* pNewObject = 0;
    if (a != 0)
    {
        pNewObject = new FUN_00688fc0(a, fValue, uiFlags, uiExtra);
        void* pArgument = ((FUN_00456fc0_cls*)a)->FUN_00456fc0(4);
        pNewObject->AttachModel(pArgument, d, e, fParam, uiParam);
        g_011e0e80.FUN_00973fd0(pNewObject);
    }
    return pNewObject;
}

namespace fnv_00689310 {
struct Vec
{
    float x, y, z;
};
struct Mat
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
};
struct Transform
{
    Mat rotation;
    Vec position;
    float scale;
    Transform();
    void Invert(Transform*);
    Transform operator*(const Transform&) const;
};
struct CloneData
{
    int a, b, c, d, e, f, g;
    CloneData(float);
    ~CloneData();
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Obj* asNode();
    unsigned int Kind();
    Obj* Clone(CloneData*);
    void SetPosition(const Vec&);
    void SetRotation(const Mat*);
    void SetScale(float);
    void Update();
    Transform& World();
};
struct Parent
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(Obj*, bool);
};
struct Ptr
{
    Obj* p;
    Ptr(Obj*);
    ~Ptr();
    operator Obj*() const;
    Ptr& operator=(Obj*);
    Ptr& operator=(const Ptr&);
};
struct Loader
{
    Obj* LoadFile(const char*, int, bool, bool, bool, bool);
};
struct WorldMgr
{
    int TryLoad(Obj*, Ptr*);
};
extern WorldMgr* g_TES;
struct Queue
{
    static Queue* GetInstance();
    void Attach(Obj*, Parent*, bool, bool);
};
bool FUN_008c7aa0();
void FUN_00578060(Obj*);
void Post(Obj*);
struct Effect
{
    int unk00, unk04;
    float scale;
    int unk0c, unk10, unk14;
    Ptr model;
    const char* filename;
    Ptr parent;
    Transform relative;
    float Calc(Obj*);
    void Setup(Obj*);
    void AttachModel(Parent*, Mat, Vec, float, unsigned int);
};
// Loads the model file, resolves or clones it, applies position/rotation/scale, attaches it to dest or the queue, then computes the relative transform to parent.
// @fnv 0x00689310
void Effect::AttachModel(Parent* apParent, Mat rotation, Vec position, float afScale, unsigned int flags)
{
    Ptr loaded6(((Loader*)DAT_011c3b3c)->LoadFile(filename, 0, true, false, false, true));
    if (!(Obj*)loaded6)
        return;
    model = (Obj*)0;
    int success = 0;
    if ((flags & 1) && g_TES)
        success = g_TES->TryLoad(loaded6, &model);
    if (!success)
    {
        if (((Obj*)loaded6)->Kind() <= 2)
            model = loaded6;
        else if (flags & 2)
        {
            CloneData clone2(1.0f);
            model = ((Obj*)loaded6)->Clone(&clone2);
        }
    }
    if (!(Obj*)model)
        return;
    if (flags & 4)
    {
        float value5 = Calc(model);
        if (value5 != -1.0)
        {
            if (value5 < 0.1f)
                value5 = 0.1f;
            scale = value5;
        }
    }
    Obj* node_ = ((Obj*)model)->asNode();
    if (node_)
        FUN_00578060(node_);
    ((Obj*)model)->SetPosition(position);
    ((Obj*)model)->SetRotation(&rotation);
    ((Obj*)model)->SetScale(afScale);
    if (FUN_008c7aa0())
        Queue::GetInstance()->Attach(model, apParent, true, true);
    else
    {
        apParent->Attach(model, true);
        ((Obj*)model)->Update();
    }
    Setup(model);
    Post(model);
    if ((Obj*)parent)
    {
        Transform local;
        local.scale = afScale;
        local.rotation = rotation;
        local.position = position;
        Transform world3 = ((Obj*)parent)->World();
        Transform inverseTmp;
        world3.Invert(&inverseTmp);
        relative = inverseTmp * local;
    }
}
}  // namespace fnv_00689310

extern NiRTTI DAT_012024e0;
extern NiRTTI DAT_01202548;
struct NodeX
{
    unsigned int FUN_0043b480();
    NiNode* FUN_0043b4a0(int);
};
struct ArrP
{
    unsigned int FUN_004d7d50();
    void* GetByIndex(int);
};
struct ObjQ
{
    int FUN_009611e0();
};
struct ArrQ
{
    int* FUN_00877a30(int);
    void FUN_0096ae90(unsigned int, const int&);
};
struct ThisT
{
    void __thiscall CollectUniqueChildValues(NiNode* a0, ArrQ* a1, int* a2);
};

// @fnv 0x0068a8f0
void __thiscall ThisT::CollectUniqueChildValues(NiNode* apNode, ArrQ* apValues, int* apiCount)
{
    if (apNode)
    {
        ArrP* p = (ArrP*)FUN_00653270(&DAT_012024e0, apNode);
        if (p)
        {
            unsigned int i;
            for (i = 0; i < p->FUN_004d7d50(); ++i)
            {
                ObjQ* pObj = (ObjQ*)FUN_00653270(&DAT_01202548, p->GetByIndex(i));
                if (pObj)
                {
                    bool bUnique = true;
                    int iExisting;
                    for (iExisting = *apiCount - 1; bUnique && iExisting >= 0; --iExisting)
                    {
                        if (*apValues->FUN_00877a30(iExisting) == pObj->FUN_009611e0())
                            bUnique = false;
                    }
                    if (bUnique)
                    {
                        apValues->FUN_0096ae90(*apiCount, pObj->FUN_009611e0());
                        ++*apiCount;
                    }
                }
            }
        }
        NiNode* pChild = apNode->f3();
        if (pChild)
        {
            unsigned int uiChildIndex;
            for (uiChildIndex = 0; uiChildIndex < ((NodeX*)pChild)->FUN_0043b480(); ++uiChildIndex)
            {
                CollectUniqueChildValues(((NodeX*)pChild)->FUN_0043b4a0(uiChildIndex), apValues, apiCount);
            }
        }
    }
}

struct R01Diagnostic
{
    int m_formID;
    unsigned char m_type;
    unsigned char m_payload0, m_payload1, m_payload2, m_payload3;
    unsigned char m_grade;
};

struct R01SaveReader
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    unsigned int FUN_00825c00();
    R01Diagnostic* FUN_004fd3c0();
    unsigned char FUN_008df040();
    void FUN_00857bd0(unsigned short);
};

struct R01Matrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    void Init();
};

struct R01Point3
{
    float x, y, z;
    void Init();
};

struct R01ParticleTransform
{
    float x, y, z, w;
    void Init();
    void FUN_004f0180(R01Matrix3*);
};

struct NiUpdateData
{
    float m_uiCommandId;
    int m_unk04;
    int m_unk08;
    NiUpdateData(float);
};

struct R01Node
{
    R01Node* FUN_00559450();
    void FUN_00440460(R01Point3*);
    void FUN_0043fa80(R01Matrix3*);
    void FUN_00440490(float);
    void FUN_00a5a040();
    void* FUN_0043b230();
    void FUN_00a59c60(NiUpdateData*);
};

struct R01NodeRef
{
    void FUN_0066b0d0(R01Node*);
    R01Node* FUN_00559450();
};

struct R01SceneRoot
{
    R01Node* FUN_00a5d680();
};

struct R01SceneLink
{
    void* m_ptr;
    R01SceneLink(int);
    ~R01SceneLink();
    R01Node* FUN_00559450();
};

struct R01Scene
{
    R01SceneRoot* LoadModel(char*, int, int, int, int, int);
    void FUN_004472a0(char*, R01SceneLink*);
};

struct R01CellDynamicNode
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual unsigned int AttachChildInAvailableSlot(R01Node*, int);
};

struct R01Cell
{
    R01CellDynamicNode* FUN_005497a0();
};

struct R01Form
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
    virtual void v49();
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
    virtual const char* GetDebugName();
};

struct R01Rand
{
    unsigned int FUN_00825c00(int, int);
};

extern R01Rand DAT_011f6394;
extern const double DAT_01017b70;
extern const float DAT_01012054;
extern void __cdecl FUN_005b5e40(const char*, ...);
extern R01Form* __cdecl LookupFormByID(int);
extern void __cdecl FUN_0055ffa0(void*, R01Node*, float);
extern void __cdecl FUN_00a6d2d0(R01Node*);
extern void* __cdecl memset(void*, int, unsigned int);

struct R01FxPlayer
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    R01Cell* m_cell;
    int m_flags;
    int m_iValueAfterFlags;
    R01NodeRef m_nodeRef;
    R01Node* m_node;

    bool FUN_00682990();
    bool LoadFromSave();
};

// Reads a particle temp effect from the save buffer, rebuilds its scene node and transform, and reports block header or buffer size errors.
// @fnv 0x00689f80
bool R01FxPlayer::LoadFromSave()
{
    bool aA4 = true;
    unsigned char aAF8;
    R01Matrix3 aAccuracy5;
    float aAction2;
    unsigned short a3_2;
    R01ParticleTransform a1c4_2;
    R01Point3 aAPGeom;
    {
        unsigned short aA2 = 0;
        unsigned int a1c2 = 0;
        if (reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00862110())
        {
            unsigned int aA1c4;
            reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&aA1c4, 4);
            if (aA1c4 != 0x424c4f4b)
            {
                R01Diagnostic* diag = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_004fd3c0();
                if (diag)
                {
                    R01Form* form = LookupFormByID(diag->m_formID);
                    FUN_005b5e40(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1a4, diag->m_formID, form->GetDebugName(), diag->m_grade,
                        *reinterpret_cast<unsigned int*>(&diag->m_payload0));
                }
                else
                {
                    FUN_005b5e40(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1a4, reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008df040());
                }
            }
            a1c2 = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00825c00();
            reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&aA2, 2);
        }
        aA4 = FUN_00682990();
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&aAF8, 1);
        char aActive8[0x104];
        memset(aActive8, 0, sizeof(aActive8));
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(aActive8, aAF8);
        a1c4_2.Init();
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&a1c4_2, 0x10);
        aAccuracy5.Init();
        a1c4_2.FUN_004f0180(&aAccuracy5);
        aAPGeom.Init();
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&aAPGeom, 0xc);
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&aAction2, 4);
        reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008579e0(&a3_2, 2);
        if (aA4)
        {
            R01SceneRoot* a4_2 = reinterpret_cast<R01Scene*>(DAT_011c3b3c)->LoadModel(aActive8, 0, 1, 0, 0, 0);
            if (a4_2)
            {
                m_nodeRef.FUN_0066b0d0(a4_2->FUN_00a5d680());
                if (m_nodeRef.FUN_00559450())
                {
                    R01SceneLink aActorPos6(0);
                    reinterpret_cast<R01Scene*>(DAT_011c3b3c)->FUN_004472a0(aActive8, &aActorPos6);
                    m_node = aActorPos6.FUN_00559450()->FUN_00559450();
                    m_nodeRef.FUN_00559450()->FUN_00440460(&aAPGeom);
                    m_nodeRef.FUN_00559450()->FUN_0043fa80(&aAccuracy5);
                    m_nodeRef.FUN_00559450()->FUN_00440490(aAction2);
                    R01CellDynamicNode* aAFlags = m_cell->FUN_005497a0();
                    aAFlags->AttachChildInAvailableSlot(m_nodeRef.FUN_00559450(), 1);
                    m_nodeRef.FUN_00559450()->FUN_00a5a040();
                    NiUpdateData aA148((float)((double)DAT_011f6394.FUN_00825c00(1, 0) / DAT_01017b70));
                    m_nodeRef.FUN_00559450()->FUN_00a59c60(&aA148);
                    FUN_00a6d2d0(m_nodeRef.FUN_00559450());
                    if (a3_2)
                    {
                        void* a1c4 = FUN_00653270(&DAT_011f36ac, m_nodeRef.FUN_00559450()->FUN_0043b230());
                        if (a1c4)
                        {
                            FUN_0055ffa0(a1c4, m_nodeRef.FUN_00559450(), DAT_01012054);
                        }
                        else
                        {
                            aA4 = false;
                        }
                    }
                }
                else
                {
                    aA4 = false;
                }
            }
            else
            {
                aA4 = false;
            }
        }
        if (!aA4 && a3_2)
        {
            reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00857bd0(a3_2);
        }
        if (reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00862110())
        {
            unsigned int a1cTmp = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_00825c00();
            R01Diagnostic* diag = reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_004fd3c0();
            if (diag)
            {
                R01Form* form = LookupFormByID(diag->m_formID);
                if (a1cTmp > a1c2 + (unsigned int)aA2)
                {
                    FUN_005b5e40(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        a1cTmp - (a1c2 + (unsigned int)aA2),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, diag->m_formID, form->GetDebugName(), diag->m_grade,
                        *reinterpret_cast<unsigned int*>(&diag->m_payload0));
                }
                else if (a1cTmp < a1c2 + (unsigned int)aA2)
                {
                    FUN_005b5e40(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        (a1c2 + (unsigned int)aA2) - a1cTmp,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, diag->m_formID, form->GetDebugName(), diag->m_grade,
                        *reinterpret_cast<unsigned int*>(&diag->m_payload0));
                }
            }
            else
            {
                if (a1cTmp > a1c2 + (unsigned int)aA2)
                {
                    FUN_005b5e40(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        a1cTmp - (a1c2 + (unsigned int)aA2),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008df040());
                }
                else if (a1cTmp < a1c2 + (unsigned int)aA2)
                {
                    FUN_005b5e40(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        (a1c2 + (unsigned int)aA2) - a1cTmp,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp",
                        0x1ec, reinterpret_cast<R01SaveReader*>(DAT_011de45c)->FUN_008df040());
                }
            }
        }
    }
    return aA4;
}

class NiPoint3Value
{
  public:
    float x, y, z;
};
class NiMatrix3Value
{
  public:
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
};
class NiTransform
{
  public:
    NiMatrix3Value rotate;
    NiPoint3Value translate;
    float scale;
    NiTransform operator*(const NiTransform&) const;
};
class NiAVObject
{
  public:
    unsigned int GetRefCount() const;
    const NiTransform& FUN_00461130() const;
    void FUN_00440460(const NiPoint3Value&);
    void FUN_0043fa80(const NiMatrix3Value&);
    void FUN_00440490(float);
};
template <class T> class NiPointer
{
  public:
    T* pointer;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
class ParticleUpdate
{
  public:
    int unk00, unk04;
    float duration;
    int unk0c;
    float elapsed;
    int unk14;
    NiPointer<NiAVObject> object;
    const char* filename;
    NiPointer<NiAVObject> parent;
    NiTransform localTransform;
    bool FUN_006828a0(float);
    bool UpdateTransform(float);
};
// Calls FUN_006828a0, clears parent when its refcount is 1, and applies the parent's transform multiplied by localTransform to object.
// @fnv 0x00689a10
bool ParticleUpdate::UpdateTransform(float time)
{
    bool result = FUN_006828a0(time);
    if (parent && parent->GetRefCount() == 1)
        parent = 0;
    if (object && parent)
    {
        NiTransform transform = parent->FUN_00461130() * localTransform;
        object->FUN_00440460(transform.translate);
        object->FUN_0043fa80(transform.rotate);
        object->FUN_00440490(transform.scale);
    }
    return result;
}

namespace fnv_00688fc0 {
struct TESObjectCELL;

extern int DAT_01069c5c;

struct SoundPlaybackHandle
{
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    unsigned char m_auiShapeKeys[0x0c];
};

struct NiTransform
{
    NiTransform();
    void ResetToIdentity();
    unsigned char m_auiShapeKeys[0x34];
};

struct GO
{
    GO(int value);
    ~GO();
    void operator=(void* value);
    void* m_ptr;
};

struct BSTempEffect
{
    BSTempEffect(TESObjectCELL* cell, float radius);
    ~BSTempEffect();
    unsigned int m_kPointA;
    unsigned char m_auiShapeKeys[0x14];
};

struct FUN_00688fc0_shell : public BSTempEffect
{
    FUN_00688fc0_shell(TESObjectCELL* cell, float radius, const char* filename, void* node);
    ~FUN_00688fc0_shell();

    GO m_18;
    const char* pFilename;
    GO m_20;
    NiTransform m_kMotionTransform;
    void* m_58;
    SoundPlaybackHandle m_5c;
    SoundPlaybackHandle m_68;
};

// Constructs a temporary effect that stores a node pointer, a filename, and an identity motion transform.
// @fnv 0x00688fc0
FUN_00688fc0_shell::FUN_00688fc0_shell(TESObjectCELL* cell, float radius, const char* filename, void* node)
    : BSTempEffect(cell, radius), m_18((m_kPointA = (unsigned int)&DAT_01069c5c, 0)), m_20(0), m_kMotionTransform(), m_5c(),
      m_68()
{
    m_18 = 0;
    m_20 = node;
    m_kMotionTransform.ResetToIdentity();
    pFilename = filename;
    m_58 = 0;
}
}  // namespace fnv_00688fc0

namespace fnv_00689cb0 {
struct SGBaseFormComponent
{
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(SGBaseFormComponent* component);
    virtual bool CompareWithBase(SGBaseFormComponent* component);
};

struct SGForm : public SGBaseFormComponent
{
    virtual ~SGForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool Load(void* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(void* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(void* modInfo);
    virtual void WriteFormInfo(void* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(void* form);
    virtual void* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(void* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(void* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(void* form);
    virtual bool Compare(void* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
};

struct SGChangeRecord
{
    unsigned int auiFormId;
    unsigned char cType;
    unsigned char ucChangeFlags[4];
};

struct SGSaveLoadGame
{
    char* FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void* apData, unsigned int auiSize);
    SGChangeRecord* FUN_004fd3e0();
};
extern SGSaveLoadGame* DAT_011de45c;

struct SGSettingBool
{
    unsigned char* FUN_00408d60();
};
extern SGSettingBool DAT_011de4e8;

struct SGPoint3
{
    float x;
    float y;
    float z;
};

struct SGMatrix3;

struct SGQuaternion
{
    float w;
    float x;
    float y;
    float z;
    SGQuaternion();
    void FUN_00a6df40(const SGMatrix3& arRotate);
};

struct SGObject
{
};
struct SGControllerManager;

struct SGAVObject
{
    const SGMatrix3& FUN_006a9540();
    SGPoint3& FUN_0043c490();
    float GetFloatAt64();
    SGObject* FUN_0043b230();
};

struct SGNodePtr
{
    operator SGAVObject*() const;
};

SGControllerManager* __cdecl FUN_00653270(const NiRTTI* apRTTI, SGObject* apObject);
unsigned short __cdecl FUN_0055fdb0(SGControllerManager* apManager);
void __cdecl FUN_0055fe70(SGControllerManager* apManager, float afTime);
extern const float DAT_01012054;
SGForm* __cdecl LookupFormByID(unsigned int auiFormID);
void __cdecl FUN_0040fbe0(const char* apFormat, ...);
void __cdecl FUN_005b5e40(const char* apFormat, ...);
unsigned int __cdecl FUN_0044a670(const char* apString);

static const char s_szParticleFile[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp";

struct SGTempEffectParticle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SGNodePtr spParticle;
    const char* pFilename;
    void FUN_00682920();
    void FUN_00689cb0();
};

// Writes particle effect state (filename, transform, controller sequence) to the save stream and logs the block size.
// @fnv 0x00689cb0
void SGTempEffectParticle::FUN_00689cb0()
{
    unsigned short usBlockLen = 0;
    unsigned short* pSizeLoc = 0;
    char* pBeginPos = DAT_011de45c->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
    {
        pBeginPos = DAT_011de45c->FUN_00825c00();
    }
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int uiMarker = 'BLOK';
        DAT_011de45c->FUN_008579b0(&uiMarker, 4);
        pSizeLoc = (unsigned short*)DAT_011de45c->FUN_00825c00();
        DAT_011de45c->FUN_008579b0(&usBlockLen, 2);
    }

    FUN_00682920();
    unsigned char ucLength = (unsigned char)FUN_0044a670(pFilename);
    DAT_011de45c->FUN_008579b0(&ucLength, 1);
    DAT_011de45c->FUN_008579b0((void*)pFilename, ucLength);

    SGQuaternion kQuaternion;
    kQuaternion.FUN_00a6df40(((SGAVObject*)spParticle)->FUN_006a9540());
    DAT_011de45c->FUN_008579b0(&kQuaternion, 16);
    SGPoint3 kLocalTranslate = ((SGAVObject*)spParticle)->FUN_0043c490();
    DAT_011de45c->FUN_008579b0(&kLocalTranslate, 12);
    float fLocScale = ((SGAVObject*)spParticle)->GetFloatAt64();
    DAT_011de45c->FUN_008579b0(&fLocScale, 4);

    unsigned short usSequence = 0;
    SGControllerManager* pController = FUN_00653270(&DAT_011f36ac, ((SGAVObject*)spParticle)->FUN_0043b230());
    if (pController)
    {
        usSequence = FUN_0055fdb0(pController);
    }
    DAT_011de45c->FUN_008579b0(&usSequence, 2);
    if (usSequence)
    {
        FUN_0055fe70(pController, DAT_01012054);
    }

    if (*DAT_011de4e8.FUN_00408d60())
    {
        char* pDebugEnd = DAT_011de45c->FUN_00825c00();
        SGChangeRecord* pChange = DAT_011de45c->FUN_004fd3e0();
        if (pChange)
        {
            SGForm* pForm = LookupFormByID(pChange->auiFormId);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         pDebugEnd - pBeginPos, pChange->auiFormId, pForm->GetName(),
                         *(unsigned int*)pChange->ucChangeFlags, 411, s_szParticleFile);
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", pDebugEnd - pBeginPos, 411, s_szParticleFile);
        }
    }
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int uiEnd = (unsigned int)DAT_011de45c->FUN_00825c00();
        unsigned int uiStart = (unsigned int)pSizeLoc;
        if (uiEnd > uiStart + 0xFFFF)
        {
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         s_szParticleFile, 411);
        }
        *pSizeLoc = (unsigned short)(uiEnd - uiStart);
    }
}
}  // namespace fnv_00689cb0
