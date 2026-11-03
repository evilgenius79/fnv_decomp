
// src/staging/blk_00460000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm). The skeleton of src/staging/blk_00460000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/staging/blk_00460000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FUN_004600f0_class
{
    unsigned char GetByteAt618();
};
struct FUN_00460fb0_class
{
    void* FUN_00460fb0();
};
struct FUN_00460fd0_class
{
    void* FUN_00460fd0();
};
struct FUN_004610f0_Class
{
    void* GetOffset70Ptr();
};
struct FUN_00462e60_Class
{
    void SetByteAt428(unsigned char value);
};
struct FUN_00464f40_class
{
    void __thiscall FUN_00470110();
    void __thiscall FUN_00464f40();
};
struct NavMesh
{
    void FUN_0042fd70(int);
    NavMesh* FUN_00464ff0(int);
};
struct FUN_0046dcc0_class
{
    void __thiscall SetByteAtOffsetF4(unsigned char param);
};
struct FUN_0046dce0_class
{
    void FUN_0046dce0(float value);
};
void __cdecl FUN_00ec825b(char* p, unsigned int a, char const* b, char const* c, char const* d, char const* e);
void __cdecl FUN_0046e850(char* p, unsigned int a, char const* b, char const* c, char const* d, char const* e);
struct FUN_0046e880_Class
{
    void __thiscall SetByteField(int value);
};
struct FUN_0046e8c0_class
{
    bool FUN_0046e8c0();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_0046eb00_Class
{
    unsigned int GetSecondElement();
};
struct FUN_0046ebf0_Class
{
    unsigned short GetMaskedShifted(unsigned short a, unsigned short b);
};
struct FUN_0046fdf0_class
{
    int __thiscall GetZero();
};
struct FUN_0046fe90_Class
{
    bool HasFlag(signed char flag);
};
extern int DAT_01019a1c;
struct FUN_00470040_class
{
    int m_vft;
    void FUN_004704e0(int a, int b);
    FUN_00470040_class(int a, int b);
};
extern int DAT_01019a2c;
struct FUN_004700a0
{
    void* vtbl;
    void __thiscall FUN_00470550(int a, int b);
    FUN_004700a0(int a, int b);
};
void* __fastcall FUN_006f99e0(void*);
struct FUN_004705c0_cls
{
    void* __fastcall FUN_004705c0();
};
struct FUN_00471110_Class
{
    void SetField3DC(float value);
};
struct FUN_00471de0_class
{
    bool FUN_00471de0();
};
struct P03MM
{
    void* Allocate(unsigned int);
};
P03MM* __cdecl FUN_00401020();
void* __cdecl AllocateProduct(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
struct ActorCombatGroup;
struct NiTMallocInterface_StandIn
{
    static void __cdecl Deallocate(ActorCombatGroup*);
};
struct FUN_00474760_This
{
    const char* p;
    ActorCombatGroup* q;
    void __thiscall FUN_00474760();
};
extern "C" void* DAT_0101a3b8;
struct BFC_s
{
    BFC_s();
};
struct FUN_008c6060_shell
{
    void FUN_008c6060();
};
struct FUN_004748f0 : BFC_s
{
    void* vtbl;
    FUN_004748f0();
};
struct FUN_00475a90_cls
{
    bool IsFlag2Set();
};
struct FUN_00476a00_cls
{
    bool FUN_00476a00();
};
struct FUN_00476a20_Class
{
    bool IsFlag4Set();
};
struct FUN_00476ae0_class
{
    void SetTaskFlag(bool a);
    void FUN_00476ae0(bool a);
};
struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool enabled, unsigned int flag);
    void SetTaskFlag(bool enabled);
};
struct MersenneTwister
{
    unsigned int GetRandomUInt(unsigned int);
};
struct FUN_00476be0_Class
{
    unsigned int FUN_00476be0();
};
struct FUN_00476c70_Class
{
    void FUN_00476c70(int value);
};
struct FUN_00476c90_Class
{
    unsigned int __thiscall FUN_00476c90();
};
struct FUN_004791f0_holder
{
    void __thiscall InitArrayHolder(int a);
};
extern int DAT_0101a8fc;
struct FUN_00479190_holder
{
    int m_iWordAt00;
    FUN_00479190_holder* __thiscall Construct(int a);
};
struct FUN_00573eb0_Class
{
    int FUN_0047b4d0(int);
    int FUN_0047b4b0();
};
struct FUN_0047b4d0_Class
{
    bool __thiscall FUN_0047b4d0(unsigned short flags);
};
struct S47
{
    void __thiscall FUN_0047e2a0(int);
    void __thiscall FUN_0047dea0(short);
};
struct FUN_0047ebb0_Class
{
    void FUN_005fc970(int, char);
    void FUN_0047ebb0(int value);
};
struct FUN_0047ebd0_Class
{
    void __thiscall FUN_005fc970(int b, int a);
    void __thiscall FUN_0047ebd0(bool value);
};
struct FUN_0047ff50_class
{
    void FUN_0047ff50(unsigned short value);
};
extern "C" void __cdecl NiFreeAlias(void*);
extern void* DAT_0101a364;
struct FUN_00474630 : public NiTPointerMap<int, int>
{
    void FUN_00474631();
};
extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_0101a91c;
struct FUN_004792c0_Class : NiTPointerMap<int, int>
{
    void __thiscall FUN_004792c0();
};
struct FUN_0045d930_class
{
    void __thiscall FUN_0046ffd0();
    void* __thiscall FUN_00470320(unsigned int flags);
};
struct FUN_0045d950_Class
{
    void __thiscall FUN_00470070();
    void* __thiscall FUN_00470380(unsigned int flags);
};
struct FUN_004703e0_class : public FUN_00464f40_class
{
    void* __thiscall FUN_004703e0(unsigned int flags);
};
void __cdecl operator delete(void* p)
{
    _NiFreeAlias(p);
}
struct FUN_00470410_class : public FUN_00464f40_class
{
    void* __thiscall FUN_00470410(unsigned int flags);
};
struct FUN_004746d0_Class
{
    void __thiscall FUN_004746d0();
    void* __thiscall FUN_00474530(unsigned int flags);
};
struct FUN_004747c0_Class : public FUN_00474630
{
    void* __thiscall FUN_004747c0(unsigned int flags);
};
void __cdecl Deallocate(void*);
void FUN_00474730();
struct FUN_004747f0_class
{
    void FUN_00474730();
    void* FUN_004747f0(unsigned int flags);
};
struct FUN_00473f00_class
{
    void __thiscall ForwardToHolder();
};
void __cdecl Deallocate(void*);
struct FUN_00474850_class : public FUN_00473f00_class
{
    void* __thiscall FUN_00474850(unsigned int flags);
};
struct FUN_004752e0_Class
{
    void* __thiscall FUN_004752e0(unsigned int flags);
    void __thiscall FUN_00475310();
};
void __cdecl Deallocate(void*);
struct FUN_00479140_class
{
    void __thiscall FUN_00479140();
};
struct FUN_00479160_class
{
    void* __thiscall FUN_00479160(unsigned int flags);
};
struct FUN_004792f0_Class : FUN_004792c0_Class
{
    void* __thiscall FUN_004792f0(unsigned int flags);
};
struct BGSImpactDataSet
{
    static BGSImpactDataSet* ms_pImpactDataSet;
};
BGSImpactDataSet* BGSImpactDataSet::ms_pImpactDataSet;
void FUN_00460160();
struct BGSEncounterZone
{
    static BGSEncounterZone* ms_pDefaultEncounterZone;
};
void __cdecl FUN_00460190();
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned int*, EndianSizeTag<3>);
struct S_00462230
{
    void __thiscall FUN_00462230();
};
struct TlsBlock462480
{
    unsigned char pad[0x294];
    int flag;
};
__declspec(thread) TlsBlock462480 g_tls462480;
extern int __tls_index;
struct FUN_00462480_Class
{
    unsigned char __thiscall FUN_00462480();
};
__declspec(thread) unsigned int TLS_PAD[166];
struct S69570
{
    unsigned char FUN_00469570();
};
struct KFModel
{
    void* GetControllerSequence();
};
void* __cdecl DynamicCastByRTTI(void const*, void*);
extern char const g_011f4454_arg1[];
struct FUN_0046e8e0_This
{
    void __thiscall FUN_0046e8e0(KFModel* a, int b, int c, int d, int e);
};
extern int DAT_01019a14;
// @fnv 0x0046ffd0
template <> struct NiTMallocInterface<void*>
{
    static void __cdecl Deallocate(void**);
};
void __thiscall FUN_0045d930_class::FUN_0046ffd0()
{
    *(void**)this = (void*)&DAT_01019a14;
    NiTMallocInterface<void*>::Deallocate(*(void***)((char*)this + 4));
}
struct FUN_004700d0_class : FUN_004705c0_cls
{
    void __thiscall FUN_0049fa20(void* p);
    void __thiscall FUN_004700d0(int* p);
};
struct FUN_00471d90_class
{
    char m_auiShapeKeys[0x3e8];
    int m_flags;
    void __thiscall FUN_00471d90(bool enabled);
};
struct FUN_00471e10_class
{
    void __thiscall SetFlag40(bool set);
};
void* memset(void*, int, unsigned int);
extern int DAT_010a2480;
extern unsigned int DAT_01187014;
struct BSFile
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Seek(int, int);
    unsigned int Read(void*, unsigned int);
};
struct MyForm
{
    unsigned int uiID;
    char _rest[0x14];
    void FUN_00470650();
};
struct Twin_008d0360
{
    bool GetBooleanValue();
};
Twin_008d0360* FUN_00471f70();
struct FUN_00471e60_shell
{
    char _pad0[0x10];
    BSFile* pFile;
    char _pad14[0x22c];
    MyForm kForm;
    char _pad258[0x41];
    bool bFlag;
    void SetFlag40(bool);
    void LoadFormAndUpdateFlag();
};
void __cdecl _Deallocate(void*);
struct FUN_00474500_Class
{
    void __thiscall FUN_004745d0();
    void* __thiscall FUN_00474500(unsigned int flags);
};
extern int DAT_0101a384;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_00474660_class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00474660_class(int n);
};
struct FUN_00474880_Helper
{
    void __thiscall FUN_00474880(unsigned int a, unsigned int b);
};
struct FUN_00474790_Class
{
    const char* m0;
    FUN_00474790_Class* __thiscall FUN_00474790(unsigned int a, unsigned int b);
};
void __cdecl _Deallocate(void*);
struct FUN_00474820_Class
{
    void* __thiscall FUN_00474820(unsigned int);
};
struct TESForm
{
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
    unsigned int GetFormType();
};
struct FUN_00474a00_shell
{
    void* p;
    void* q;
    void* GetAmmoForm();
};
struct QueueObj
{
    QueueObj(int);
};
struct S751
{
    S751* __thiscall Initialize();
};
struct FUN_00476a40_Data
{
    int _00;
    unsigned char count;
    unsigned char _pad[3];
    void** items;
};
struct FUN_00476a40_Holder
{
    int _00;
    FUN_00476a40_Data* data;
    void* __thiscall FUN_00476a40(unsigned int index);
};
struct FUN_004781b0_This
{
    int field0;
    unsigned char field4;
    unsigned char field5;
    FUN_004781b0_This* __thiscall FUN_004781b0();
};
struct FUN_00478f70_s
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
    unsigned int d10;
    unsigned int d14;
    FUN_00478f70_s* FUN_00478f70();
};
struct AX
{
    void __thiscall FUN_006b3eb0(unsigned int, unsigned int);
};
extern int vftable__ShadowSceneArray;
struct S
{
    void* vf;
    S* __thiscall ConstructShadowSceneArray();
};
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void* p, int v, unsigned int n);
struct FUN_004791f0_holder2
{
    void* __thiscall InitArrayHolder(int a);
};
struct FUN_0047b470_This
{
    bool __thiscall FUN_0047b470();
};
struct Actor;
struct LH
{
    bool IsInList(Actor*&);
};
struct ScriptS
{
    LH* GetHeader();
};
struct FUN_0047ba80_This
{
    int _0;
    ScriptS* m4;
    bool __thiscall IsActorInList(Actor* actor);
};
struct FUN_0046fe10_Class
{
    int FUN_0046fe10();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
    BSSimpleList<TESForm*>* GetNext();
};
struct TESObject
{
    unsigned int GetNext();
};
struct FUN_00474a00
{
    TESForm* GetForm();
};
struct FUN_00474a40
{
    ScriptS* GetScript();
};
struct FUN_00474920_shell
{
    TESForm* GetFormOrScriptForm();
};
struct GlobalObject_00a7b610;
struct NiAVObject;
struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};
struct FUN_00476ec0_Class
{
    void FUN_00c455a0(unsigned char);
};
struct NiObject
{
    virtual ~NiObject();
    virtual void v1();
    virtual void v2();
    virtual NiNode* GetAsNode();
};
bool __cdecl FUN_0043b300(GlobalObject_00a7b610*, NiAVObject*);
extern GlobalObject_00a7b610 g_01202e8c;
void __cdecl FUN_00476ec0(NiAVObject*, int);
void __cdecl FUN_00476ec0(NiAVObject* object, int flag);
struct FUN_00478130_class
{
    void __thiscall FUN_00478130();
};
struct FUN_00462e10_Class
{
    signed char m_flags;
    void SetFlags(signed char mask, bool set);
};
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_004704e0
{
    void* vtbl;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short c;
    unsigned short d;
    unsigned short f;
    FUN_004704e0(unsigned short x, unsigned short y);
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    char d[0x20];
};
struct FUN_00478570_holder
{
    char m_iWordAt00[0x14];
    B2_4fe* m_cByteAtOffset1;
    void EnsureB2_4fe();
};
struct FUN_0047bac0_NPC : TESForm
{
    unsigned char m_npc[0x15c];
    void* biped;
};
struct FUN_0047bac0_ARMO : TESForm
{
    unsigned char m_armor[0xbc];
    void* biped;
};
void* GetBipedPointer(TESForm* form);
struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct TESAttackDamageForm : public BaseFormComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned short GetDamage();
    void FUN_0047ff50(unsigned short value);
    void FUN_0047fe30(BaseFormComponent* apCopyFC);
};
struct FUN_0046eb20_Class
{
    unsigned int GetElementAt2();
};
struct FUN_0046ebd0_Class
{
    unsigned int FUN_0046ebd0();
};
struct FUN_0046fdd0_Class
{
    char m_iWordAt00[0x38];
    int m_38;
    char IsFieldEqual(int param_2);
};
extern int DAT_01019a24;
extern int DAT_0101a644;
struct Date
{
    virtual ~Date();
    virtual int v0();
};
struct FUN_004750e0 : Date
{
    ~FUN_004750e0();
};
struct BSSimpleArrayActor
{
    void __thiscall Clear(bool);
};
struct FUN_0047bcf0_class
{
    bool IsFlag80Clear();
};
struct FUN_0047eb90_Class
{
    void FUN_005fc970(int, char);
    void FUN_0047eb90(int value);
};
class FUN_00462dc0_cls
{
  public:
    int m_00;
    int m_04;
    int(__cdecl* m_08)(FUN_00462dc0_cls* self, int a, int b, int c, int d);
    int InvokeAndAccumulate(int a1, int a2, int a3, int a4);
};
int __cdecl FUN_00464f30(int a);
extern int DAT_01019a34;
extern void* __cdecl FUN_0096afc0(unsigned int count);
struct ResourceDescriptor
{
    void* vtable;
    void* resource;
    unsigned int count;
    unsigned int capacity;
    void* manager;
    unsigned int options;

    ResourceDescriptor* __thiscall FUN_004705e0(unsigned int initialCount, unsigned int initialOptions);
};
extern Twin_008d0360* g_011f6078;
Twin_008d0360* __cdecl FUN_00471f70();
class Base_b9207
{
  public:
    virtual ~Base_b9207();
    unsigned int unk04;
    unsigned int unk08;
};
class FUN_004745d0 : public Base_b9207
{
  public:
    virtual ~FUN_004745d0();
    void DoCleanup();
};
struct FUN_00475220_member
{
    ~FUN_00475220_member();
};
struct FUN_00475220
{
    int unk00;
    unsigned char ucCount;
    FUN_004752e0_Class** ppItems;
    int unk0C;
    FUN_00475220_member member;
    ~FUN_00475220();
};
class FUN_00475310_obj
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual int vSlot10(int arg);
};
class FUN_00475310_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00475310_obj* m_14;

    void FUN_00475310();
};
struct InstanceData36
{
    unsigned int values[9];
};
struct InstanceData12
{
    unsigned int values[3];
};
struct OutputRenderer
{
    unsigned int FUN_008d6f30();
};
struct ChildRange;
struct CollectionItem
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual ChildRange* GetChildren();
    bool FUN_00c455a0(unsigned char);
    InstanceData36* FUN_00461130();
    InstanceData12* FUN_0045bb80();
};
struct ChildRange
{
    unsigned int FUN_0043b480();
    CollectionItem* FUN_0043b4a0(unsigned int);
};
extern unsigned char DAT_01202e7c;
bool __cdecl FUN_0043b300(const void*, CollectionItem*);
void __cdecl CreateProjectileRef(int, OutputRenderer*, OutputRenderer*, unsigned int, InstanceData12, InstanceData36);
struct ActorProcessor
{
    int ProcessCollectionTree(CollectionItem*, int, unsigned int, OutputRenderer*);
};
extern unsigned char DAT_01202e84;
struct NodeChildren;
struct Node
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual NodeChildren* GetChildren();
    unsigned char FUN_00c455a0(unsigned char mode);
    int FUN_0045bb80(void* extra, float value);
};
struct NodeChildren
{
    unsigned int FUN_0043b480();
    Node* FUN_0043b4a0(unsigned int index);
};
struct Context
{
    float FUN_00567400();
    int FUN_008d6f30(int value);
};
struct Receiver
{
    void FUN_004fa6f0(int value);
};
extern unsigned char __cdecl FUN_0043b300(const void* descriptor, Node* node);
struct Walk
{
    int WalkTree(Node* node, Receiver* receiver, unsigned int mode, Context* context, void* extra);
};
struct FUN_00477090_Sound;
struct FUN_00477090_Space;
struct FUN_00477090_Handle
{
    float GetLevel();
    void SetLevel(float level);
    void PlayAt(FUN_00477090_Sound* sound, FUN_00477090_Space* space);
};
struct FUN_00477090_Ref
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
    virtual void v100();
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
    virtual void RefreshSound(int a, int b);
    FUN_00477090_Handle* GetHandle();
    FUN_00477090_Space* GetReferenceSpace();
};
struct FUN_00477090_Stage
{
    unsigned char unk00;
    unsigned char percent;
    unsigned char unk02;
    unsigned char unk03;
    int value;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00477090_Sound* sound;
};
struct FUN_00477090_Data
{
    unsigned int total;
    unsigned char count;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    FUN_00477090_Stage** stages;
};
float __cdecl FUN_00476b20(float value);
struct FUN_00477090_Owner
{
    int unk00;
    FUN_00477090_Data* data;
    void UpdateRef(FUN_00477090_Ref* ref, int flag);
    void UpdateSoundLevel(FUN_00477090_Ref* ref);
};
struct FUN_00477230_owner
{
    int IsFlagged();
};
struct FUN_00477230_item
{
    FUN_00477230_owner* GetOwner();
    unsigned int GetCount();
    struct FUN_00477230_node* GetChild(unsigned int index);
};
struct FUN_00477230_arg
{
    void Update(FUN_00477230_item** out);
};
struct FUN_00477230_node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual FUN_00477230_item* v0c();
};
struct FUN_00477230_cls
{
    void FUN_00477230(FUN_00477230_node* node, FUN_00477230_arg* arg);
};
FUN_00477230_owner* SceneHelperA();
bool __cdecl SceneHelperB(FUN_00477230_owner* a, FUN_00477230_owner* b);
extern "C" NiFixedString* DAT_011c61d8;
NiFixedString* __cdecl FUN_004772e0();
extern const double kFnvListDivisor;
extern const float kFnvListDefault;
class FnvShapeObject
{
  public:
    float unk_Measure();
    float unk_Weight();
};
struct FnvShapeEntry
{
    unsigned char unk00;
    unsigned char m_b01;
    unsigned short unk02;
    unsigned int unk04;
    FnvShapeObject* m_obj08;
};
struct FnvShapeList
{
    unsigned int unk00;
    unsigned char m_count04;
    unsigned char unk05;
    unsigned short unk06;
    FnvShapeEntry** m_entries08;
};
class FUN_00477970_cls
{
  public:
    unsigned int unk00;
    FnvShapeList* m_list04;
    float FindShapeByThresholds(unsigned char a1, float a2, float a3, FnvShapeObject** out);
};
struct ManagedSceneEntry
{
    unsigned int state;
    unsigned int identifier;
    unsigned int priority;
    unsigned int flags;
    unsigned int timestamp;

    __forceinline ManagedSceneEntry()
    {
        reinterpret_cast<S751*>(this)->Initialize();
    }
};
struct ManagedSceneHolder
{
    unsigned int mode;
    ManagedSceneEntry* current;
    void EnsureCurrentEntry();
};
void* __cdecl FormHeap_Allocate(unsigned int size);
struct SpawnedItem_b10003
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SpawnedItem_b10003();
    static void* operator new(unsigned int size) throw()
    {
        return FormHeap_Allocate(size);
    }
};
struct FUN_00478e90_This
{
    int unk00;
    SpawnedItem_b10003** __thiscall AllocateSpawnedItemArray(unsigned char count);
};
void* __cdecl operator new(unsigned int size);
struct FUN_0048a3d0;
typedef void(__thiscall* CopyMethod)(FUN_0048a3d0*, const FUN_0048a3d0*);
typedef void*(__thiscall* ReleaseMethod)(FUN_0048a3d0*, int);
struct EffectMethods
{
    void* unk00;
    void* unk04;
    CopyMethod copy08;
    void* unk0c;
    ReleaseMethod release10;
};
struct FUN_0048a3d0
{
    EffectMethods* methods;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_0048a3d0();
};
struct CopyInterface
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void CopyFrom(const FUN_0048a3d0* other);
};
struct EffectData
{
    unsigned char flags00;
    unsigned char flags01;
    unsigned char flags02;
    int count04;
    int count08;
    int count0c;
    int count10;
    FUN_0048a3d0* effect14;
    void FUN_00478fd0(const EffectData* source);
};
class B479260MapBase
{
  public:
    virtual ~B479260MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};
class FUN_00479260_Map : public B479260MapBase
{
  public:
    virtual ~FUN_00479260_Map();
    void RemoveAll();
};
class BGSChangeFlags47E
{
  public:
    BGSChangeFlags47E(unsigned int uiFlags);
    bool Test(unsigned int uiMask);

    unsigned int m_uiValue1;
};
class BGSLoadFormBuffer47E
{
  public:
    BGSChangeFlags47E GetChangeFlags();
    void ReadTypedData(void* pvData, unsigned int uiSize);
};
class TESActorBaseData47E
{
  public:
    bool GetFlagBit(int iBit);
    void SetFlagBits(int iUnk, bool bValue, int iUnk2);
    void FUN_0047ea70(BGSLoadFormBuffer47E* pkBuffer);

    int unk00;
    int m_iFlags;
};
struct FUN_0047ead0_cls
{
    FUN_0047ead0_cls* FUN_005d8a70();
    FUN_0047ead0_cls** FUN_006815c0();
    FUN_0047ead0_cls* FUN_004181e0(FUN_0047ead0_cls* a, int b);
    int GetFactionRank();
    FUN_0047ead0_cls* FUN_00726070();
    void FUN_0047ebd0(int v);
    void FUN_0047ebb0(int v);
    void FUN_0047eb90(int v);
    void FUN_0047ead0(int mode);
};
extern FUN_0047ead0_cls* DAT_011dea3c;
struct FUN_0047fe80_class : BaseFormComponent
{
    virtual void FUN_0047fe80_v1();
    virtual void FUN_0047fe80_v2();
    virtual void FUN_0047fe80_v3();
    virtual unsigned short GetAttackDamage();
    bool __thiscall IsAttackDamageDifferent(BaseFormComponent* other);
};
extern double DAT_01017a40;
extern const float DAT_01012054;
struct Standin77900
{
    float FUN_00477900();
};
class PathingRequest
{
  public:
    float FUN_006a78f0() const;
};
struct FUN_00477a50_Entry
{
    char cType;
    unsigned char ucHour;
    char pad02[2];
    unsigned int ItemUpdateArray;
    Standin77900* pData;
};
struct FUN_00477a50_Table
{
    unsigned int uiTotal;
    unsigned char ucEntries;
    char pad05[3];
    FUN_00477a50_Entry** ppEntries;
};
struct FUN_00477a50_shell
{
    void* vtbl;
    FUN_00477a50_Table* pSearchEntries;
    float GetHourlyWeightedTime(unsigned char aucHour, float afMin, float afMinB, Standin77900** appData);
};
struct CopyStage
{
    ~CopyStage();
    void FUN_00478fd0(const CopyStage*);
};
struct DestructionData
{
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short unk06;
    CopyStage** stages;
    unsigned int unk0c;
    unsigned int unk10;
    DestructionData();
    ~DestructionData();
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    DestructionData* data;
    DestructionData* FUN_00726070();
    CopyStage** AllocateSpawnedItemArray(unsigned int count);
    void FUN_004786e0(BaseFormComponent* source);
};
struct NiFixedString_47ab40
{
    operator const char*() const;
};
struct NamedObject_47ab40
{
    NiFixedString_47ab40& GetName();
};
union SETTING_VALUE_47ab40
{
    bool b;
    int i;
};
struct Setting_47ab40
{
    SETTING_VALUE_47ab40* Bool();
};
extern Setting_47ab40 g_011c4c64;
int FUN_00ec6da0(const char*, const char*);
bool FUN_008c7aa0();
struct NiNode_47ab40;
struct World_47ab40
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
    virtual void AddObject(NiNode_47ab40* node, bool a, bool b, int c, int d);
};
struct Cell_47ab40;
World_47ab40* __fastcall FUN_004543c0(Cell_47ab40* cell);
struct TaskQueue_47ab40
{
    static TaskQueue_47ab40* GetInstance();
    void HandlerRegistration(NiNode_47ab40* node);
};
struct Ref_47ab40
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual NiNode_47ab40* Get3D();
    Cell_47ab40* GetParentCell();
};
bool FUN_0047ab40(Ref_47ab40* ref, NamedObject_47ab40* obj);
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    bool multithread;
    NiUpdateData(float, bool, bool);
};
class NN_00605d70
{
  public:
    void Update(const NiUpdateData&);
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer(NiNode* object);
    ~NiPointer();
    operator NiNode*() const;
};
FUN_0047b470_This* __cdecl FUN_00c802d0(NiNode*);
void __cdecl SetFlagRecursive(int, void*);
struct RefWithGetNiNode
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
    virtual NiNode* GetNiNode();
};
void __cdecl FUN_0047b360(RefWithGetNiNode* apRef);
struct ItemForm
{
    unsigned int FNV_GetFormType();
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
    virtual bool IsQuestItem();
};
struct ActorStub;
struct ScriptOwnerStub
{
    bool IsActorInList(ActorStub* actor);
};
ScriptOwnerStub* GetBipedPointer(ItemForm* form);
struct WeapStub : ItemForm
{
    bool HasModsCheck();
    int GetModsValue();
    int GetWeaponType();
};
struct BipedFlagsStub
{
    int flags;
    bool IsPowerArmorCheck();
};
struct ListStub
{
    void* item;
    ListStub* next;
    void* GetHead();
};
struct ArmorStub : ItemForm
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    BipedFlagsStub bipedModel;
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
    ListStub list154;
    bool GetHeavyFlag();
};
struct PlayerStub;
extern PlayerStub* g_thePlayer;
void __cdecl ApplyPerkModifiers(int id, PlayerStub* actor, ...);
extern double _gModifierZero;
bool __cdecl IsItemEquivalent(ItemForm* a, ItemForm* b);

// FUN_00461cf0 (0x00461cf0, 1340 bytes) -- TESFile record scan.
// Vtable-free; member of the file-list holder (count at +0x218, array at +0x21c).
class TESWorldSpace;

struct TESRecordHeader
{
    unsigned int type;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
};

class TESFile
{
  public:
    bool GetOptimizedFile();
    TESRecordHeader* GetRecordHeader();
    bool FUN_00470c70(int, int);
    bool FUN_00472150(bool);
    bool FUN_00473660();
    TESFile* GetFileByIndex(unsigned int);
    unsigned char FUN_00473250();
    int FUN_004726b0();
    unsigned int GetField25C();
    bool GetChunkData(void*, unsigned int);
    bool FUN_004726f0();
    bool IsEndianConversionRequired();
    void FUN_00471130();
};

// XCLC chunk payload: two dwords swapped by the endian pass plus a trailing bool.
struct XCLC
{
    unsigned int x;
    unsigned int y;
    unsigned char z;
    XCLC();
    void FUN_00462230();
};

class AutoMemContext
{
  public:
    int m0;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};

class VoiceStr
{
  public:
    bool FUN_008256d0();
    void** FUN_006815c0();
    VoiceStr* FUN_00726070();
};

class DialogueResponse
{
  public:
    VoiceStr* GetVoiceFilePath();
};

struct FUN_00585940_shell
{
    bool FindCellByEditorID(char*, int*, int*);
};

struct TESWorldSpace : TESForm
{
  public:
    virtual ~TESWorldSpace();
};

TESForm* LookupFormByID(unsigned int);
int FindFormEnumIndex(unsigned int);
int __cdecl FUN_00404dc0(const char*, const char*);
void __cdecl FormHeap_Free(void*);

extern "C" char DAT_010186b8[];
extern DialogueResponse* DAT_011c3f2c;
extern int DAT_01187020;
extern int DAT_011872b4;
extern int DAT_01187314;

struct TESFileArray
{
    char pad[0x218];
    unsigned int mCount;
    TESFile* mFiles[1];
    int FUN_00461cf0(char*, int*, int*);
};

// @fnv 0x00461cf0
int TESFileArray::FUN_00461cf0(char* name, int* out1, int* out2)
{
    AutoMemContext ctx(0x16, true, (char*)DAT_010186b8, 0x1041);
    int result = 0;
    *out1 = 0;
    *out2 = 0;
    if (name && *name)
    {
        bool found = false;
        for (unsigned int i = 0; i < mCount; i++)
        {
            if (mFiles[i] && mFiles[i]->GetOptimizedFile())
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            VoiceStr* p = DAT_011c3f2c->GetVoiceFilePath();
            while (p && !p->FUN_008256d0())
            {
                void* v = *p->FUN_006815c0();
                p = p->FUN_00726070();
                if (((FUN_00585940_shell*)v)->FindCellByEditorID(name, out1, out2))
                {
                    result = (int)v;
                    break;
                }
            }
        }
        else
        {
            for (unsigned int j = 0; j < mCount; j++)
            {
                TESFile* f = mFiles[j];
                if (f && f->FUN_00470c70(0, 0))
                {
                    TESRecordHeader* hdr = f->GetRecordHeader();
                    bool got = false;
                    while (hdr && !got)
                    {
                        bool read = false;
                        if (hdr->type == (unsigned int)DAT_01187020)
                        {
                            if (hdr->fC == 0 && hdr->f8 == (unsigned int)DAT_01187314)
                            {
                                got = true;
                                read = f->FUN_00472150(true);
                            }
                            else
                            {
                                read = f->FUN_00473660();
                            }
                        }
                        else
                        {
                            read = f->FUN_00472150(true);
                        }
                        if (read)
                            hdr = f->GetRecordHeader();
                        else
                            hdr = 0;
                    }
                    if (got)
                    {
                        hdr = f->GetRecordHeader();
                        got = false;
                        while (hdr && !got)
                        {
                            bool read2 = false;
                            if (hdr->type == (unsigned int)DAT_01187314)
                            {
                                unsigned int id = hdr->fC;
                                unsigned int hi = id >> 24;
                                TESFile* w = f->GetFileByIndex(hi + 1);
                                if (!w)
                                    w = f;
                                id &= 0xffffff;
                                id |= (unsigned int)(unsigned char)w->FUN_00473250() << 24;
                                result = (int)dynamic_cast<TESWorldSpace*>(LookupFormByID(id));
                                read2 = f->FUN_00472150(true);
                            }
                            else if (hdr->type == (unsigned int)DAT_011872b4)
                            {
                                int chunk = f->FUN_004726b0();
                                if (chunk == 0x44494445)
                                {
                                    unsigned int len = f->GetField25C() + 1;
                                    char* ptr = (char*)operator new(len);
                                    memset(ptr, 0, len);
                                    f->GetChunkData(ptr, 0);
                                    if (FUN_00404dc0(ptr, name) == 0)
                                    {
                                        got = true;
                                        while (chunk)
                                        {
                                            if (chunk == 0x434c4358)
                                            {
                                                XCLC v;
                                                memset(&v, 0, sizeof(v));
                                                f->GetChunkData(&v, sizeof(v));
                                                if (f->IsEndianConversionRequired())
                                                    v.FUN_00462230();
                                                *out1 = v.x;
                                                *out2 = v.y;
                                                chunk = 0;
                                            }
                                            else if (f->FUN_004726f0())
                                            {
                                                chunk = f->FUN_004726b0();
                                            }
                                            else
                                            {
                                                chunk = 0;
                                            }
                                        }
                                    }
                                    FormHeap_Free(ptr);
                                }
                                read2 = f->FUN_00472150(true);
                            }
                            else
                            {
                                bool flag = false;
                                if (hdr->type == (unsigned int)DAT_01187020)
                                {
                                    switch (hdr->fC)
                                    {
                                    case 0:
                                        if (hdr->f8 == (unsigned int)DAT_01187314)
                                        {
                                            read2 = f->FUN_00472150(true);
                                            flag = true;
                                        }
                                        else
                                        {
                                            unsigned char c = (unsigned char)FindFormEnumIndex(hdr->f8);
                                            if (c > 0x41)
                                            {
                                                read2 = false;
                                                flag = true;
                                            }
                                        }
                                        break;
                                    case 1:
                                    case 4:
                                    case 5:
                                        read2 = f->FUN_00472150(true);
                                        flag = true;
                                        break;
                                    case 6:
                                        read2 = f->FUN_00473660();
                                        flag = true;
                                        break;
                                    }
                                }
                                if (0)
                                {
                                }
                            }
                            if (read2)
                                hdr = f->GetRecordHeader();
                            else
                                hdr = 0;
                        }
                    }
                    f->FUN_00471130();
                    if (!got)
                        result = 0;
                    else
                        break;
                }
            }
        }
    }
    return result;
}
