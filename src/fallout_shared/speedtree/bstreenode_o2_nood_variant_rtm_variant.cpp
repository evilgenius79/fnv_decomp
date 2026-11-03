// src/fallout_shared/speedtree/bstreenode_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/speedtree/bstreenode_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/fallout_shared/speedtree/bstreenode_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /GF (unit src/fallout_shared/speedtree/bstreenode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
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
struct NiAVObject
{
    void __thiscall SetAppCulled(bool);
};
struct BSTreeNodeVisibility : BSTreeNode
{
    bool __thiscall FUN_0066bc40(bool);
};
struct FUN_0066d3d0_shell
{
    void __thiscall FUN_0066d3d0(void*);
};
extern int DAT_01066acc;
struct FUN_0066d3a0_shell
{
    void* __thiscall FUN_0066d3a0(void*);
};
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
struct FUN_00c8bed0_holder
{
    void __thiscall FUN_00c8bed0();
};
void __cdecl _delete(void*, unsigned int);
struct bhkTransformShape
{
    void* __thiscall Destroy(unsigned int);
};
struct FUN_0066d740_owner
{
    void __thiscall FUN_00caacf0();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
void __cdecl _delete(void* p, unsigned int size);
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
struct FUN_0094db80_shell
{
    void FUN_0094db80(unsigned char);
};
struct BSTreeNodeVisibilityWork : BSTreeNodeVisibility
{
    bool SetVisibilityByType(unsigned short type, unsigned char mode);
};
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
#include <xmmintrin.h>
struct bhkLimitedHingeVector
{
    void __thiscall FUN_004b4db0(const float*);
    unsigned char vecData[16];
};
struct Inner
{
    unsigned char unk00[0x14];
    void* m14;
    unsigned char unk18[0x18];
    __m128 rows[4];
};
struct Param
{
    unsigned char unk00[4];
    void* m4;
    unsigned char unk08[8];
    bhkLimitedHingeVector vecs[4];
};
extern const __m128 g_01268370[4];
struct MyObj
{
    unsigned char unk00[8];
    Inner* m8;
    void __thiscall FUN_00c84e20(void*);
    void __thiscall FUN_00c8c410(void*);
};
struct Alloc
{
    virtual void v0();
    virtual void* Alloc_(unsigned int);
};
struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Alloc* unk10;
};
struct AudioTlsState
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
struct Data8
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float unk20[4], unk30[4];
};
struct Vec
{
    float x, y, z, w;
    void FUN_004b4db0(const float*);
};
struct Output
{
    int unk00;
    float unk04;
    int unk08, unk0c;
    Vec unk10, unk20;
    int unk30;
    int unk34;
    int unk38;
};
struct FUN_00d22dc0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int unk04;
    void* unk08;
    FUN_00d22dc0(const __m128&, const __m128&, float, int, int);
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
    static void* operator new(unsigned int n);
    static void operator delete(void*);
};
struct Obj
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
    virtual void Call(void*, void*, void*, const char*);
    int unk04;
    Data8* unk08;
    void FUN_00c9fb70(Output*);
    void FUN_00cab1b0(void*, void*);
};
extern unsigned int DAT_0126fd98;
extern float DAT_010c72bc;
extern float DAT_01267e30[];
Holder* __cdecl FUN_00c85750();
void* FUN_00d22dc0::operator new(unsigned int n)
{
    Holder* h = FUN_00c85750();
    Alloc* allocator = h->unk10;
    void* p = allocator->Alloc_(n);
    *(short*)((char*)p + 4) = (short)n;
    return p;
}
extern __declspec(thread) AudioTlsState tls;
struct TlsRestore
{
    int old;
    TlsRestore()
    {
        AudioTlsState* td = &tls;
        old = td->unk2b4;
        td->unk2b4 = 0x10;
    }
    ~TlsRestore()
    {
        tls.unk2b4 = old;
    }
};
struct SpawnedSource
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};
struct SpawnedSourceOwner
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
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void Apply(SpawnedSource* apSource);

    void FUN_00cab0e0(__m128* apA, __m128* apB, float afT);
    void FUN_00cab820(SpawnedSource* apSource);
};
#include <xmmintrin.h>
#include <xmmintrin.h>
extern "C" unsigned long __readfsdword(unsigned long);

extern float DAT_01268170;
extern float DAT_01016248;
extern float DAT_01012054;
extern int DAT_01267b80;
extern int DAT_01267b84;
struct S00c880f0_Point3
{
    float x, y, z;
};
struct FloatMatrix3
{
    float values[9];
};
struct Pose
{
    FloatMatrix3 rotation;
    S00c880f0_Point3 translation;
    float scale;
};
struct S00c880f0_ScalarC880
{
    __m128 r;
    S00c880f0_ScalarC880(float f) : r(_mm_load_ss(&f))
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(r, r, 0);
    }
};
union S00c880f0_VecC880
{
    S00c880f0_VecC880& operator=(const S00c880f0_VecC880& o)
    {
        v = o.v;
        return *this;
    }
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
    void sub(const S00c880f0_VecC880& o)
    {
        v = _mm_sub_ps(v, o.v);
    }
    void scale(const S00c880f0_ScalarC880& f)
    {
        v = _mm_mul_ps(f.splat(), v);
    }
    void plus(const S00c880f0_VecC880& o)
    {
        v = _mm_add_ps(v, o.v);
    }
};
inline void makePosition(S00c880f0_VecC880& result, const S00c880f0_Point3& p)
{
    result.x = p.x * DAT_01268170;
    result.y = p.y * DAT_01268170;
    result.z = p.z * DAT_01268170;
    result.w = 0.0f;
}

struct S00c880f0_Bounds
{
    S00c880f0_VecC880 min, max;
};
struct S00c880f0_Ifc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(S00c880f0_Bounds* out);
    void FUN_00cf24a0(S00c880f0_Bounds* out);
};
struct S00c880f0_HolderA
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
    Pose world;
    void FUN_00a68bf0();
};
struct S00c880f0_Node
{
    int unk00, unk04;
    S00c880f0_Ifc* m_08;
    void FUN_00a29680();
};
struct S00c880f0_Cls
{
    int unk00, unk04;
    S00c880f0_HolderA* m_08;
    unsigned int m_0c;
    S00c880f0_Node* m_10;
    void FUN_00c880f0();
};
struct S00c880f0_LockObj
{
    void Lock(int);
};
// @fnv 0x00c880f0
void S00c880f0_Cls::FUN_00c880f0()
{
    S00c880f0_HolderA* a = m_08;
    S00c880f0_Node* b = m_10;
    if (a)
    {
        a->FUN_00a68bf0();
        if (b)
        {
            S00c880f0_Ifc* c = b->m_08;
            if (c)
            {
                Pose pose = a->world;
                S00c880f0_VecC880 position;
                S00c880f0_Bounds out;
                c->v18(&out);
                out.max.sub(out.min);
                out.max.scale(S00c880f0_ScalarC880(0.5f));
                out.min = out.max;
                out.min.scale(S00c880f0_ScalarC880(-1.0f));
                makePosition(position, pose.translation);
                out.min.plus(position);
                out.max.plus(position);
                reinterpret_cast<S00c880f0_LockObj*>(&DAT_01267b80)->Lock(0);
                S00c880f0_Ifc* item = b->m_08;
                if (item)
                {
                    b->FUN_00a29680();
                    item->FUN_00cf24a0(&out);
                    b->FUN_00a29680();
                }
                if (--DAT_01267b84 == 0)
                    DAT_01267b80 = 0;
            }
        }
    }
}
