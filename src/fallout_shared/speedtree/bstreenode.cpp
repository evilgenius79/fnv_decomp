
// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00622430_shell
{
    unsigned int __thiscall FUN_00622430();
};

// @fnv 0x00622430
unsigned int __thiscall FUN_00622430_shell::FUN_00622430()
{
    return 0x50;
}

struct NiRTTI;

extern NiRTTI g_011d5e70;

struct FUN_0066b5b0_shell
{
    const NiRTTI* __thiscall GetNiRTTI();
};

// @fnv 0x0066b5b0
const NiRTTI* __thiscall FUN_0066b5b0_shell::GetNiRTTI()
{
    return &g_011d5e70;
}

struct NiAVObject;

struct NiNode
{
    NiAVObject* __thiscall GetAt(unsigned int);
};

struct BSTreeNode : NiNode
{
    NiAVObject* __thiscall GetFirstChild();
};

// @fnv 0x0066b5c0
NiAVObject* BSTreeNode::GetFirstChild()
{
    return GetAt(0);
}

namespace fnv_0066b5e0 {
struct NiAVObject;

struct NiNode
{
    NiAVObject* __thiscall GetAt(unsigned int);
};

struct BSTreeNode
{
    NiAVObject* __thiscall FUN_0066b5e0();
};

// @fnv 0x0066b5e0
NiAVObject* BSTreeNode::FUN_0066b5e0()
{
    return ((NiNode*)this)->GetAt(1);
}
}  // namespace fnv_0066b5e0

namespace fnv_0066b600 {
struct NiAVObject;

struct NiNode
{
    NiAVObject* GetAt(unsigned int);
};

struct BSTreeNode : NiNode
{
    NiAVObject* FUN_0066b600();
};

// @fnv 0x0066b600
NiAVObject* BSTreeNode::FUN_0066b600()
{
    return GetAt(2);
}
}  // namespace fnv_0066b600

namespace fnv_0066b680 {
struct BSTreeNode
{
    void __thiscall FUN_0066b6c0();
    void* __thiscall FUN_0066b680(unsigned int);
};

void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x0066b680
void* BSTreeNode::FUN_0066b680(unsigned int flags)
{
    this->FUN_0066b6c0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 248);
    return this;
}
}  // namespace fnv_0066b680

namespace fnv_0066be30 {
struct NiProperty
{
    virtual ~NiProperty();
};

struct NiAlphaProperty : NiProperty
{
    void FUN_0094db80(unsigned char);
};

struct NiAVObject
{
    void SetAppCulled(bool);
};

struct Flt
{
    operator unsigned int() const;
};

struct PropHelper
{
    void* GetProperty(unsigned int);
};

struct BSTreeNode
{
    BSTreeNode();
    ~BSTreeNode();
    bool FUN_0066be30(unsigned char acTest);
};

// @fnv 0x0066be30
bool BSTreeNode::FUN_0066be30(unsigned char acTest)
{
    if (!reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xf0)->operator unsigned int())
    {
        return false;
    }
    if (acTest == 0xff)
    {
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xf0)->operator unsigned int()))
            ->SetAppCulled(true);
    }
    else
    {
        reinterpret_cast<NiAVObject*>(
            reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xf0)->operator unsigned int()))
            ->SetAppCulled(false);
        NiAlphaProperty* pprop = reinterpret_cast<NiAlphaProperty*>(
            reinterpret_cast<PropHelper*>(
                reinterpret_cast<char*>(
                    reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xf0)->operator unsigned int()))
                ->GetProperty(0));
        if (pprop)
        {
            pprop->FUN_0094db80(acTest);
        }
    }
    return true;
}
}  // namespace fnv_0066be30

struct NiCullingProcess;
extern "C" unsigned char __cdecl FUN_0054ee20();
struct DummyNode
{
    void __thiscall FUN_00a5dbe0(NiCullingProcess* arCuller);
    void __thiscall FUN_0066bf50(NiCullingProcess* arCuller);
};

// If FUN_0054ee20() returns nonzero, forwards the culling call to FUN_00a5dbe0 with arCuller.
// @fnv 0x0066bf50
void __thiscall DummyNode::FUN_0066bf50(NiCullingProcess* arCuller)
{
    if (FUN_0054ee20())
    {
        this->FUN_00a5dbe0(arCuller);
    }
}

struct FUN_00c6c290_holder
{
    void FUN_00c6c290();
};

struct FUN_0066d410_shell : public FUN_00c6c290_holder
{
    void FUN_0066d410();
};

// @fnv 0x0066d410
void FUN_0066d410_shell::FUN_0066d410()
{
    FUN_00c6c290();
}

struct NiRTTI
{
};

extern const NiRTTI g_012683d0;

struct FUN_0066d430_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x0066d430
const NiRTTI* FUN_0066d430_shell::GetRTTI() const
{
    return &g_012683d0;
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

struct FUN_0066d440_shell
{
    void FUN_0066d470();
    void* FUN_0066d440(unsigned int flags);
};

// @fnv 0x0066d440
void* FUN_0066d440_shell::FUN_0066d440(unsigned int flags)
{
    this->FUN_0066d470();
    if (flags & 1)
        __Dummy_00b6fef0(this, 20);
    return this;
}

struct FUN_0066d470_shell
{
    void FUN_0066d410();
    void FUN_0066d470();
};

// @fnv 0x0066d470
void FUN_0066d470_shell::FUN_0066d470()
{
    this->FUN_0066d410();
}

struct FUN_0066d510_shell
{
    const void* FUN_0066d510();
};

extern const void* g_012683e0;

// @fnv 0x0066d510
const void* FUN_0066d510_shell::FUN_0066d510()
{
    return &g_012683e0;
}

struct FUN_0066d520_shell
{
    void FUN_00cb78b0();
    void* FUN_0066d520(unsigned int flags);
};

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x0066d520
void* __thiscall FUN_0066d520_shell::FUN_0066d520(unsigned int flags)
{
    this->FUN_00cb78b0();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x14);
    return this;
}

struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610 g_012681b4;

struct FUN_0066d610_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

// @fnv 0x0066d610
GlobalObjectO2_00a7b610* FUN_0066d610_shell::GetGlobalObject()
{
    return &g_012681b4;
}

struct bhkCapsuleShape
{
    unsigned int __thiscall FUN_0066d730() const;
};

// @fnv 0x0066d730
unsigned int __thiscall bhkCapsuleShape::FUN_0066d730() const
{
    return 0x30;
}

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

// @fnv 0x0066d7a0
void FUN_0066d7a0_shell::RunInner()
{
    m1.FUN_0066da50();
}

struct Flt
{
    operator unsigned int() const;
};

struct NiTriBasedGeom;

struct FUN_0066b620_shell
{
    NiTriBasedGeom* __thiscall GetTriBasedGeom();
};

// @fnv 0x0066b620
NiTriBasedGeom* FUN_0066b620_shell::GetTriBasedGeom()
{
    return (NiTriBasedGeom*)((Flt*)((char*)this + 0xf0))->operator unsigned int();
}

extern const char* const g_012683d0_arg1;

struct FUN_0066d400_shell
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x0066d400
const char* const* FUN_0066d400_shell::GetArg1Ptr()
{
    return &g_012683d0_arg1;
}

struct NiAVObject
{
    void __thiscall SetAppCulled(bool);
};
struct BSTreeNodeVisibility : BSTreeNode
{
    bool __thiscall FUN_0066bc40(bool);
};
// Gets the node's NiAVObject and sets its app-culled flag to the inverse of abVisible; returns false if there is no object.
// @fnv 0x0066bc40
bool __thiscall BSTreeNodeVisibility::FUN_0066bc40(bool abVisible)
{
    NiAVObject* object =
        (NiAVObject*)((NiAVObject * (__thiscall*)(BSTreeNodeVisibility*)) * (char**)(*(char**)this + 0x104))(this);
    if (!object)
        return false;
    object->SetAppCulled(!abVisible);
    return true;
}

namespace fnv_0066bc90 {
struct NiAVObject
{
    void __thiscall SetAppCulled(bool);
};
struct StandInBC90
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual NiNode* GetLeaf();
    bool __thiscall SetLeafVisible(bool abVisible);
};
// Gets the leaf node via GetLeaf, sets its app-culled flag to the inverse of abVisible, and returns false if no leaf exists.
// @fnv 0x0066bc90
bool __thiscall StandInBC90::SetLeafVisible(bool abVisible)
{
    NiNode* pnode = GetLeaf();
    if (pnode == 0)
        return false;
    ((NiAVObject*)pnode)->SetAppCulled(!abVisible);
    return true;
}
}  // namespace fnv_0066bc90

struct FUN_0066d3d0_shell
{
    void __thiscall FUN_0066d3d0(void*);
};
extern int DAT_01066acc;
struct FUN_0066d3a0_shell
{
    void* __thiscall FUN_0066d3a0(void*);
};
// @fnv 0x0066d3a0
void* __thiscall FUN_0066d3a0_shell::FUN_0066d3a0(void* arg)
{
    reinterpret_cast<FUN_0066d3d0_shell*>(this)->FUN_0066d3d0(arg);
    *reinterpret_cast<void**>(this) = &DAT_01066acc;
    return this;
}

namespace fnv_0066d3d0 {
struct FUN_00c6b950_shell
{
    void* __thiscall FUN_00c6b950(unsigned int);
};
extern void* DAT_01066b94;

struct FUN_0066d3d0_shell
{
    void* m0;
    void* __thiscall FUN_0066d3d0(unsigned int a);
};

// Calls FUN_00c6b950 with a, then sets m0 to point at DAT_01066b94 and returns this.
// @fnv 0x0066d3d0
void* __thiscall FUN_0066d3d0_shell::FUN_0066d3d0(unsigned int a)
{
    ((FUN_00c6b950_shell*)this)->FUN_00c6b950(a);
    m0 = &DAT_01066b94;
    return this;
}
}  // namespace fnv_0066d3d0

extern "C" void __cdecl FUN_004b5020();
extern "C" void __cdecl FUN_0056e270();
struct FUN_0056e120_shell
{
    void __thiscall FUN_0056e120();
};
struct FUN_0066d550_shell
{
    void* Initialize();
};
// @fnv 0x0066d550
void* FUN_0066d550_shell::Initialize()
{
    ((void(__thiscall*)(void*))FUN_004b5020)(this);
    ((unsigned int*)this)[1] = 0;
    ((void(__thiscall*)(void*))FUN_0056e270)((char*)this + 0x10);
    ((FUN_0056e120_shell*)((char*)this + 0x10))->FUN_0056e120();
    return this;
}

struct FUN_00c8bed0_holder
{
    void __thiscall FUN_00c8bed0();
};
void __cdecl _delete(void*, unsigned int);
struct bhkTransformShape
{
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x0066d620
void* bhkTransformShape::Destroy(unsigned int flags)
{
    ((FUN_00c8bed0_holder*)this)->FUN_00c8bed0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_0066d740_owner
{
    void __thiscall FUN_00caacf0();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
void __cdecl _delete(void* p, unsigned int size);
// @fnv 0x0066d740
void* __thiscall FUN_0066d740_owner::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_00caacf0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_0056e900_shell
{
    void __thiscall StepAndReturnThis();
};
struct FUN_006299a0_shell
{
    void __thiscall FUN_006299a0();
};
struct FUN_0066d770_shell
{
    void* __thiscall FUN_0066d770();
};
// Calls StepAndReturnThis on this and FUN_006299a0 on the object at this+4, then returns this.
// @fnv 0x0066d770
void* __thiscall FUN_0066d770_shell::FUN_0066d770()
{
    ((FUN_0056e900_shell*)this)->StepAndReturnThis();
    ((FUN_006299a0_shell*)((char*)this + 4))->FUN_006299a0();
    return this;
}

namespace fnv_0066bce0 {
struct NiAVObject
{
    void __thiscall SetAppCulled(bool);
};
struct FUN_0066bce0_holder
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
    virtual NiNode* GetNode();
    bool __thiscall SetNodeVisible(bool abVisible);
};
// Gets the node and, if present, sets its app-culled flag to the inverse of abVisible; returns whether a node was found.
// @fnv 0x0066bce0
bool __thiscall FUN_0066bce0_holder::SetNodeVisible(bool abVisible)
{
    NiNode* pnode;
    pnode = GetNode();
    if (pnode == 0)
        return false;
    ((NiAVObject*)pnode)->SetAppCulled(!abVisible);
    return true;
}
}  // namespace fnv_0066bce0

struct NiObject
{
    virtual ~NiObject();
};
struct NiTexturingProperty : NiObject
{
    virtual ~NiTexturingProperty();
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct NiAVObjectProp
{
    void AttachProperty(NiObject*);
    void RemoveProperty(unsigned int);
};
struct FUN_0066bec0_shell
{
    bool AttachTexturingProperty(NiTexturingProperty* apProp);
};
// If this object has a property container and apProp is non-null, replaces any existing property slot 5 with apProp and returns whether it attached.
// @fnv 0x0066bec0
bool FUN_0066bec0_shell::AttachTexturingProperty(NiTexturingProperty* apProp)
{
    NiTexturingProperty* pprop = 0;
    if (!(unsigned int)(*(Flt*)((char*)this + 0xf0)) || !apProp)
        return false;
    pprop = (NiTexturingProperty*)((PropHelper*)(unsigned int)(*(Flt*)((char*)this + 0xf0)))->GetProperty(5);
    if (pprop)
    {
        if (pprop == apProp)
            return false;
        ((NiAVObjectProp*)(unsigned int)(*(Flt*)((char*)this + 0xf0)))->RemoveProperty(5);
    }
    ((NiAVObjectProp*)(unsigned int)(*(Flt*)((char*)this + 0xf0)))->AttachProperty(apProp);
    return true;
}

struct FUN_0094db80_shell
{
    void FUN_0094db80(unsigned char);
};
struct BSTreeNodeVisibilityWork : BSTreeNodeVisibility
{
    bool SetVisibilityByType(unsigned short type, unsigned char mode);
};
// Looks up the node for a type; if mode is 0xff it culls the node, otherwise it unculls it and passes mode to the node's property 0.
// @fnv 0x0066bdb0
bool BSTreeNodeVisibilityWork::SetVisibilityByType(unsigned short type, unsigned char mode)
{
    typedef NiAVObject*(__thiscall * GetAtFn)(void*, unsigned int);
    NiAVObject* node = ((GetAtFn)(*(void***)this)[0x45])(this, type);
    if (node == 0)
        return false;
    if (mode == 0xff)
    {
        node->SetAppCulled(true);
    }
    else
    {
        node->SetAppCulled(false);
        NiObject* property = (NiObject*)((PropHelper*)node)->GetProperty(0);
        if (property != 0)
            ((FUN_0094db80_shell*)property)->FUN_0094db80(mode);
    }
    return true;
}

struct FUN_0066bf80_vftable
{
    void* slot000;
    void* slot004;
    void* slot008;
    void* slot00C;
    void* slot010;
    void* slot014;
    void* slot018;
    void* slot01C;
    void* slot020;
    void* slot024;
    void* slot028;
    void* slot02C;
    void* slot030;
    void* slot034;
    void* slot038;
    void* slot03C;
    void* slot040;
    void* slot044;
    void* slot048;
    void* slot04C;
    void* slot050;
    void* slot054;
    void* slot058;
    void* slot05C;
    void* slot060;
    void* slot064;
    void* slot068;
    void* slot06C;
    void* slot070;
    void* slot074;
    void* slot078;
    void* slot07C;
    void* slot080;
    void* slot084;
    void* slot088;
    void* slot08C;
    void* slot090;
    void* slot094;
    void* slot098;
    void* slot09C;
    void* slot0A0;
    void* slot0A4;
    void* slot0A8;
    void* slot0AC;
    void* slot0B0;
    void* slot0B4;
    void* slot0B8;
    void* slot0BC;
    void* slot0C0;
    void* slot0C4;
    void* slot0C8;
    void* slot0CC;
    void* slot0D0;
    void* slot0D4;
    void* slot0D8;
    void* slot0DC;
    void* slot0E0;
    void* slot0E4;
    void* slot0E8;
    void* slot0EC;
    void* slot0F0;
    void* slot0F4;
    void* slot0F8;
    void* slot0FC;
    void* slot100;
    void* slot104;
    void* slot108;
    void* slot10C;
    void* slot110;
    void* slot114;
    void* slot118;
    void* slot11C;
    void* slot120;
    void* slot124;
    void* slot128;
    void* slot12C;
    void* slot130;
    void* slot134;
    void* slot138;
    void* slot13C;
    void* slot140;
    void(__thiscall* process)(void*, float);
};
struct FUN_0066bf80_owner
{
    FUN_0066bf80_vftable* vtable;
    void __thiscall FUN_0066bf80(struct FUN_0066bf80_data*, unsigned int);
};
struct FUN_0066bf80_data
{
    float time;
};
struct NiCamera;
extern double gModifierZero;
struct FUN_00a5dd70_shell
{
    void __thiscall FUN_00a5dd70(FUN_0066bf80_data&, unsigned int);
};
extern "C" unsigned int __cdecl FUN_00552380();
extern bool __cdecl FUN_004b5fc0(NiAVObject*, NiCamera*);
enum MEM_CONTEXT
{
    MEM_CONTEXT_SCENE = 0x1e
};
struct AutoMemContext
{
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
    int state;
};
// @fnv 0x0066bf80
void FUN_0066bf80_owner::FUN_0066bf80(FUN_0066bf80_data* data, unsigned int flags)
{
    AutoMemContext context(MEM_CONTEXT_SCENE, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeNode.cpp", 0x20d);
    if (!FUN_0054ee20())
        return;
    if (data->time > gModifierZero)
    {
        if (!FUN_004b5fc0((NiAVObject*)this, (NiCamera*)FUN_00552380()))
            return;
    }
    vtable->process(this, data->time);
    ((FUN_00a5dd70_shell*)this)->FUN_00a5dd70(*data, flags);
}

class NiTexture;

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* apObject);
    ~NiPointer();
    operator T*() const;
};

struct BGSBodyPart
{
    const char* GetPartName();
};

struct bhkWorldObject;

struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};

extern char g_01268444_arg1;
NiObject* __cdecl FUN_00653270(const NiRTTI* apRTTI, NiObject* apObject);

struct FUN_0066d7c0_cls
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
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual BGSBodyPart* GetPart();
    NiObject* FUN_0066d7c0();
};

// @fnv 0x0066d7c0
NiObject* FUN_0066d7c0_cls::FUN_0066d7c0()
{
    NiObject* pResult4 = 0;
    BGSBodyPart* pPart8 = GetPart();
    if (pPart8)
    {
        NiPointer<NiTexture> spRetainedObject((NiTexture*)pPart8->GetPartName());
        if (spRetainedObject)
        {
            bhkWorldObject* pWorld5 = ((bhkCollisionObject*)(NiTexture*)spRetainedObject)->FUN_006fa820();
            pResult4 = FUN_00653270((const NiRTTI*)&g_01268444_arg1, (NiObject*)pWorld5);
        }
    }
    return pResult4;
}

struct S_0066b6c0_Base
{
    virtual ~S_0066b6c0_Base();
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
};

struct FUN_0066b6c0 : S_0066b6c0_Base
{
    NiPointer<NiNode> spTree0;
    NiPointer<NiNode>* pArr1;
    NiPointer<NiNode>* pArr2;
    NiPointer<NiNode> spTree1;

    virtual ~FUN_0066b6c0();
};

// Frees the two NiPointer<NiNode> arrays owned by the object and nulls their pointers.
// @fnv 0x0066b6c0
FUN_0066b6c0::~FUN_0066b6c0()
{
    if (pArr1)
    {
        delete[] pArr1;
        pArr1 = 0;
    }
    if (pArr2)
    {
        delete[] pArr2;
        pArr2 = 0;
    }
}

struct ItemList
{
    unsigned short GetCount();
};

struct SmartPtr
{
    void* m_pObject;
    void* Get();
};

struct FUN_0066b840_cls
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
    SmartPtr m_kNode;
    int unkE8;
    SmartPtr* m_entries;
    void* GetEntry(unsigned short index);
};

// Returns the entry at index from m_entries if the list pointer and entries are valid and index is in range, otherwise returns 0.
// @fnv 0x0066b840
void* FUN_0066b840_cls::GetEntry(unsigned short index)
{
    if (m_kNode.Get() == 0 || m_entries == 0 || index >= ((ItemList*)m_kNode.Get())->GetCount())
        return 0;
    return m_entries[index].Get();
}

struct S_0066ba30_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    S_0066ba30_Str();
    ~S_0066ba30_Str();
};
struct S_0066ba30_Model
{
    unsigned short FUN_006699d0();
};
struct S_0066ba30_Obj;
template <class T> struct S_0066ba30_Ptr
{
    T* m_pObject;
    operator T*() const;
    T* operator->() const;
    S_0066ba30_Ptr& operator=(T* p);
};
struct S_0066ba30_Node
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
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void SetObj(S_0066ba30_Obj* apObj, bool abFlag);
    virtual void ve0();
    virtual void ve4();
    virtual void ClearObj(S_0066ba30_Obj* apObj);
};
struct S_0066ba30
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
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual S_0066ba30_Node* GetNode();
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
    S_0066ba30_Ptr<S_0066ba30_Model> m_spModel;
    int unkE8;
    S_0066ba30_Ptr<S_0066ba30_Obj>* m_pObjects;
    bool SetObjectAtIndex(unsigned short index, S_0066ba30_Obj* apObj);
};

// Validates the model, object array and object, then clears the node's old object, sets the new one and stores it at index.
// @fnv 0x0066ba30
bool S_0066ba30::SetObjectAtIndex(unsigned short index, S_0066ba30_Obj* apObj)
{
    S_0066ba30_Str name5;
    if (!m_spModel || !m_pObjects || !apObj)
        return false;
    unsigned short count = m_spModel->FUN_006699d0();
    if (index >= count)
        return false;
    S_0066ba30_Node* pNode2 = GetNode();
    if (!pNode2)
        return false;
    if (m_pObjects[index])
        pNode2->ClearObj(m_pObjects[index]);
    pNode2->SetObj(apObj, true);
    m_pObjects[index] = apObj;
    return true;
}

struct VisNode70
{
    void Method00450f90(int aFlag);
    VisNode70* Method00a59d30(int aFlag);
};

struct VisNodeAlpha70
{
    void Method0094db80(unsigned char aAlpha);
};

struct FUN_0066bd30_cls
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
    virtual VisNode70* v44(unsigned short aType);

    bool FUN_0066bd30(unsigned short aType, unsigned char aMode);
};

// @fnv 0x0066bd30
bool FUN_0066bd30_cls::FUN_0066bd30(unsigned short aType, unsigned char aMode)
{
    VisNode70* node = v44(aType);
    if (node == 0)
        return false;
    if (aMode == 0xff)
    {
        node->Method00450f90(1);
    }
    else
    {
        node->Method00450f90(0);
        VisNodeAlpha70* alpha = (VisNodeAlpha70*)node->Method00a59d30(0);
        if (alpha)
            alpha->Method0094db80(aMode);
    }
    return true;
}

struct C070Node
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
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void UpdateTime(float fTime);

    void UpdateSelectedDownwardPass(FUN_0066bf80_data& kUpdate, unsigned int uiFlags);
};

struct C070TreeNode : C070Node
{
    void FUN_0066c070(FUN_0066bf80_data& kUpdate, unsigned int uiFlags);
};

// @fnv 0x0066c070
void C070TreeNode::FUN_0066c070(FUN_0066bf80_data& kUpdate, unsigned int uiFlags)
{
    AutoMemContext kMemContext(MEM_CONTEXT_SCENE, true,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeNode.cpp",
                               0x223);
    if (!FUN_0054ee20())
        return;
    if (kUpdate.time > gModifierZero)
    {
        if (!FUN_004b5fc0((NiAVObject*)this, (NiCamera*)FUN_00552380()))
            return;
    }
    UpdateTime(kUpdate.time);
    C070Node::UpdateSelectedDownwardPass(kUpdate, uiFlags);
}

extern char DAT_01066c5c;
extern unsigned int DAT_012683dc;

struct FUN_0066d490_base
{
    FUN_0066d490_base();
    ~FUN_0066d490_base();
};

struct FUN_0066d490_cls : FUN_0066d490_base
{
    void* m_vptr;
    void FUN_00cb7b80(unsigned int a1);
    FUN_0066d490_cls(unsigned int a1);
};

// Sets the vtable pointer, calls FUN_00cb7b80 with a1, and increments DAT_012683dc.
// @fnv 0x0066d490
FUN_0066d490_cls::FUN_0066d490_cls(unsigned int a1)
{
    *(void* volatile*)&m_vptr = &DAT_01066c5c;
    this->FUN_00cb7b80(a1);
    DAT_012683dc = DAT_012683dc + 1;
}

extern char DAT_01066d44;
extern unsigned int DAT_012681b0;

struct FUN_0066d590_base
{
    FUN_0066d590_base();
    ~FUN_0066d590_base();
};

struct FUN_0066d590_cls : FUN_0066d590_base
{
    void* m_vptr;
    void FUN_00c8c5b0(unsigned int a1);
    FUN_0066d590_cls(unsigned int a1);
};

// Sets the vtable pointer, calls FUN_00c8c5b0 with the given id, and increments DAT_012681b0.
// @fnv 0x0066d590
FUN_0066d590_cls::FUN_0066d590_cls(unsigned int a1)
{
    *(void* volatile*)&m_vptr = &DAT_01066d44;
    this->FUN_00c8c5b0(a1);
    DAT_012681b0 = DAT_012681b0 + 1;
}

extern "C" int __cdecl FUN_00406d00(char* text, unsigned size, const char* fmt, ...);
extern "C" char* __cdecl FUN_00a7d330(const char* s);

struct S_0066d880_List
{
    void FUN_0096a610(char** item);
};
struct S_0066d880_Obj
{
    unsigned char FUN_00666f00();
    int FUN_008d6f30();
};
struct S_0066d880_Holder
{
    S_0066d880_Obj* FUN_00559450();
};
struct S_0066d880_Base
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    void FUN_00a5ea70(S_0066d880_List* list);
};
struct S_0066d880 : S_0066d880_Base
{
    S_0066d880_Holder m_e4;
    void FUN_0066d880(S_0066d880_List* list);
};

// @fnv 0x0066d880
void S_0066d880::FUN_0066d880(S_0066d880_List* list)
{
    FUN_00a5ea70(list);
    char* name = FUN_00a7d330("BSTreeNode");
    list->FUN_0096a610(&name);
    char* text;
    if (m_e4.FUN_00559450())
    {
        text = new char[0x20];
        if (m_e4.FUN_00559450()->FUN_00666f00())
            FUN_00406d00(text, 0x20, "Type = Instance");
        else
            FUN_00406d00(text, 0x20, "Type = Base");
        list->FUN_0096a610(&text);
        text = new char[0x20];
        FUN_00406d00(text, 0x20, "Seed = %d", m_e4.FUN_00559450()->FUN_008d6f30());
        list->FUN_0096a610(&text);
    }
    else
    {
        text = new char[0x20];
        FUN_00406d00(text, 0x20, "-No Model-");
        list->FUN_0096a610(&text);
    }
}

extern void* __cdecl FUN_00aa13e0(unsigned int size);
extern void* __cdecl FormHeap_Allocate(unsigned int size);
extern float DAT_01016b78;
extern void* __cdecl GetFltValueAtOffset16();

struct FUN_00b4e150
{
    virtual ~FUN_00b4e150();
    FUN_00b4e150();
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
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
    unsigned int unkb8;
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
};
struct TreePointer
{
    void* m_pObject;
    TreePointer(void* p);
    ~TreePointer();
    void FUN_0066b0d0(void* p);
    struct TreeLists* FUN_00559450();
};
struct TreeLists
{
    unsigned short FUN_00669990();
    unsigned short FUN_006699d0();
    void* ConvertFloatToUInt();
};
struct FUN_00a5ecb0
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
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
    FUN_00a5ecb0(int initial);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_0051cf00
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
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
    FUN_0051cf00();
    void FUN_0051d000(int enabled);
    void FUN_006404b0(float size, float a, float b, float c);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_006694e0
{
    void* m_pObject;
    FUN_006694e0();
    ~FUN_006694e0();
    void FUN_0066b0d0(void* p);
    static void* operator new[](unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
};
struct FUN_0066b640
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
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c(void*);
    unsigned int unk04, unk08, unk0c, unk10;
    FUN_0066b640();
    void FUN_00c6b980(void* p);
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_0066b120 : FUN_00b4e150
{
    TreePointer m_e4;
    FUN_006694e0* m_e8;
    FUN_006694e0* m_ec;
    TreePointer m_f0;
    float m_f4;
    virtual ~FUN_0066b120();
    FUN_0066b120(void* initial, void* external);

    void FUN_00b4dec0(int n);
    void FUN_004902f0(int n);
    void SetChildAt(int type, void* p);
    void SetExtraDataName(void* p);
};

// Initializes the tree controller: sets up slots, allocates arrays from the tree list counts, creates controllers and attaches the chosen object.
// @fnv 0x0066b120
FUN_0066b120::FUN_0066b120(void* initial, void* external) : m_e4(0), m_f0(0)
{
    FUN_00b4dec0(6);
    m_e4.FUN_0066b0d0(initial);
    FUN_004902f0(1);
    FUN_00a5ecb0* pkCurrentObject = new FUN_00a5ecb0(0);
    SetChildAt(0, pkCurrentObject);
    pkCurrentObject = new FUN_00a5ecb0(0);
    SetChildAt(1, pkCurrentObject);
    FUN_0066b640* pController;
    FUN_0051cf00* controller = new FUN_0051cf00();
    controller->FUN_0051d000(1);
    controller->FUN_006404b0(DAT_01016b78, 1.0f, 0.0f, 0.0f);
    SetChildAt(2, controller);

    unsigned short count;
    unsigned short i = m_e4.FUN_00559450()->FUN_00669990();
    if (i != 0)
    {
        m_e8 = new FUN_006694e0[i];
        for (count = 0; count < i; ++count)
            m_e8[count].FUN_0066b0d0(0);
    }
    else
    {
        m_e8 = 0;
    }
    i = m_e4.FUN_00559450()->FUN_006699d0();
    if (i != 0)
    {
        m_ec = new FUN_006694e0[i];
        for (count = 0; count < i; ++count)
            m_ec[count].FUN_0066b0d0(0);
    }
    else
    {
        m_ec = 0;
    }
    m_f0.FUN_0066b0d0(0);
    SetExtraDataName(GetFltValueAtOffset16());
    void* chosen = external ? external : m_e4.FUN_00559450()->ConvertFloatToUInt();
    if (chosen)
    {
        pController = new FUN_0066b640();
        pController->FUN_00c6b980(external ? external : m_e4.FUN_00559450()->ConvertFloatToUInt());
        pController->v8c(this);
    }
    m_f4 = 0.0f;
}

class B66B7D0Object;

class B66B7D0Header
{
  public:
    unsigned short GetCount();
};

class B66B7D0HeaderPtr
{
  public:
    B66B7D0Header* Get();

    B66B7D0Header* m_pkHeader;
};

class B66B7D0ObjectPtr
{
  public:
    B66B7D0Object* Get();

    B66B7D0Object* m_pPointer;
};

class B66B7D0Owner
{
  public:
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
    B66B7D0HeaderPtr m_kHeader;
    B66B7D0ObjectPtr* m_pkObjects;

    B66B7D0Object* GetObjectByIndex(unsigned short usIndex);
};

// Returns the object at usIndex from m_pkObjects if the header exists, the array exists and usIndex is below the header count; otherwise returns 0.
// @fnv 0x0066b7d0
B66B7D0Object* B66B7D0Owner::GetObjectByIndex(unsigned short usIndex)
{
    if (!m_kHeader.Get() || !m_pkObjects || usIndex >= m_kHeader.Get()->GetCount())
        return 0;
    return m_pkObjects[usIndex].Get();
}

class C66BBB0Path;

class C66BBB0PathRef
{
  public:
    C66BBB0Path* Get();
    void Reset(C66BBB0Path* pkPath);

    C66BBB0Path* m_pkPath;
};

class C66BBB0Handler
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void SetPath(C66BBB0Path* pkPath, bool bFlag);
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void ClearPath(C66BBB0Path* pkPath);
};

class C66BBB0Owner
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual C66BBB0Handler* GetHandler();

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
    C66BBB0PathRef m_kPathRef;

    void FUN_0066bbb0(C66BBB0Path* pkPath);
};

// Clears the handler's current path if one is set, assigns pkPath to the handler, and stores it in m_kPathRef.
// @fnv 0x0066bbb0
void C66BBB0Owner::FUN_0066bbb0(C66BBB0Path* pkPath)
{
    if (!pkPath)
        return;

    C66BBB0Handler* pkHandler = GetHandler();
    if (!pkHandler)
        return;

    if (m_kPathRef.Get())
        pkHandler->ClearPath(m_kPathRef.Get());
    pkHandler->SetPath(pkPath, true);
    m_kPathRef.Reset(pkPath);
}

struct FnvScopedContext
{
    int previousContext;
    int currentContext;
    FnvScopedContext();
    ~FnvScopedContext();
};
struct FnvModelElement
{
    unsigned short __thiscall FUN_00669990();
};
struct FnvModelReference
{
    FnvModelElement* __thiscall FUN_00559450();
};
struct FnvObjectSlot
{
    void* m_object;
    void* __thiscall FUN_00559450();
    void __thiscall FUN_0066b0d0(int type);
};
struct FnvElementCollection : S_0066b6c0_Base
{
    FnvModelReference m_model;
    FnvObjectSlot* m_slots;
    bool __thiscall SetSlotObject(unsigned short index, int type);
};
typedef S_0066ba30_Node*(__thiscall* FnvNodeGetter)(FnvElementCollection*);
// Validates index and type against the model, clears the slot's existing object, sets the new object on the actor, and stores it in the slot.
// @fnv 0x0066b8b0
bool __thiscall FnvElementCollection::SetSlotObject(unsigned short index, int type)
{
    FnvScopedContext guard;
    if (!m_model.FUN_00559450() || !m_slots || !type)
        return false;
    unsigned short maxIndex = m_model.FUN_00559450()->FUN_00669990();
    if (index >= maxIndex)
        return false;
    S_0066ba30_Node* actor = reinterpret_cast<FnvNodeGetter>(
        reinterpret_cast<FUN_0066bf80_vftable*>(*reinterpret_cast<void**>(this))->slot104)(this);
    if (!actor)
        return false;
    if (m_slots[index].FUN_00559450())
    {
        actor->ClearObj(reinterpret_cast<S_0066ba30_Obj*>(m_slots[index].FUN_00559450()));
    }
    actor->SetObj(reinterpret_cast<S_0066ba30_Obj*>(type), true);
    m_slots[index].FUN_0066b0d0(type);
    return true;
}
