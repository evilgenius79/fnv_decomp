
// src/fallout_shared/speedtree/bstreenode_o2_nood_nogf_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/speedtree/bstreenode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
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

#include <xmmintrin.h>
extern __declspec(thread) unsigned int t_uiMemContextC8C;

inline unsigned int GetMemContextC8C()
{
    return t_uiMemContextC8C;
}
inline void SetMemContextC8C(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC8C = m_uiGeometryShaderFlags;
}

class AutoMemContextC8C
{
  public:
    AutoMemContextC8C(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextC8C();
        SetMemContextC8C(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextC8C()
    {
        SetMemContextC8C(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

struct __declspec(align(16)) hkVector4C8C
{
    __m128 m_vComponents;
    inline hkVector4C8C& operator=(const hkVector4C8C& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct hkRotationC8C
{
    hkVector4C8C m_kColumn0;
    hkVector4C8C m_kColumn1;
    hkVector4C8C m_kColumn2;
};

struct hkTransformC8C
{
    hkRotationC8C m_rotation;
    hkVector4C8C m_vTranslation;
};

extern hkTransformC8C g_kIdentityTransformC8C;

struct NiMatrix3C8C
{
    float m_afEntries[3][3];
};
struct NiPoint3C8C
{
    float x, y, z;
};
struct NiTransformC8C
{
    NiMatrix3C8C m_kOrientation;
    NiPoint3C8C m_kTranslation;
    float m_fScale;
};

extern "C" void __cdecl FUN_00624b10(NiMatrix3C8C* pOut, const hkRotationC8C* pIn);
extern "C" void __cdecl FUN_00458620(NiPoint3C8C* pOut, const hkVector4C8C* pIn);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* pAddend);

extern char* g_pNullStringC8C;
char* __cdecl FUN_00a5b690(const char* pcString);

class NiFixedStringC8C
{
  public:
    NiFixedStringC8C(const char* pcString)
    {
        m_kHandle = FUN_00a5b690(pcString);
    }
    ~NiFixedStringC8C()
    {
        if (m_kHandle != g_pNullStringC8C)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

__declspec(restrict) void* __cdecl FUN_00aa13e0(unsigned int uiSize);
void __cdecl FUN_00aa1460(void* p);

struct ArgC8C;
class NiNodeC8C
{
  public:
    virtual void v00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    NiTransformC8C m_kLocalTransform;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;

    NiNodeC8C(int iInitial);
    void AssignFixedString(const NiFixedStringC8C& kName);
    __declspec(restrict) static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* p)
    {
        FUN_00aa1460(p);
    }
};

class ParentC8C
{
  public:
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
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void OnAttached(NiNodeC8C* pkNode, ArgC8C* iValue);
    virtual void vD8();
    virtual void AttachChildInAvailableSlot(NiNodeC8C* pkChild, bool abFirstAvailableSlot);
};

struct LinkC8C
{
    int unk00, unk04;
    ParentC8C* m_pkOwnerManager;
};

struct BodyC8C
{
    int unk00, unk04, unk08, unk0C, unk10;
    LinkC8C* m_pkLink;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkTransformC8C m_kTransform;
};

class SceneObjectC8C
{
  public:
    int unk00, unk04;
    BodyC8C* m_pkBody;

    void FUN_00c8c860(ParentC8C* pkParent, ArgC8C* iValue);
};

// @fnv 0x00c8c860
void SceneObjectC8C::FUN_00c8c860(ParentC8C* pkParent, ArgC8C* iValue)
{
    AutoMemContextC8C kContext(0x10);

    hkTransformC8C kXform;
    kXform = (this && m_pkBody) ? m_pkBody->m_kTransform : g_kIdentityTransformC8C;

    NiTransformC8C kLocal;
    FUN_00624b10(&kLocal.m_kOrientation, &kXform.m_rotation);
    FUN_00458620(&kLocal.m_kTranslation, &kXform.m_vTranslation);

    NiNodeC8C* __restrict pkNode = new NiNodeC8C(0);
    pkNode->AssignFixedString(NiFixedStringC8C("bhkTransformShape"));
    pkParent->AttachChildInAvailableSlot(pkNode, true);
    pkNode->m_kLocalTransform.m_kTranslation = kLocal.m_kTranslation;
    pkNode->m_kLocalTransform.m_kOrientation = kLocal.m_kOrientation;

    if (this)
    {
        BodyC8C* pkBody = m_pkBody;
        if (pkBody)
        {
            LinkC8C* pkLink = pkBody->m_pkLink;
            if (pkLink)
            {
                ParentC8C* pkOwner = pkLink->m_pkOwnerManager;
                if (pkOwner)
                    pkOwner->OnAttached(pkNode, iValue);
            }
        }
    }
}
