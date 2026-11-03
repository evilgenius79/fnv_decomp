
// src/staging/blk_00d20000_o2_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d20000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void* __cdecl fopen(const char*, const char*);
struct FUN_00d2be30
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void SetFile(const char* a, const char* b);
};
extern "C" void __stdcall FUN_00d2f980(int);
extern int DAT_010ce930;
struct FUN_00d2f220_class
{
    int* p;
    int __thiscall InitializeWithGlobal(int a);
};
void __cdecl FUN_00d365d0();
void __cdecl FUN_00da6fd0(int);
void __cdecl FUN_00d367b0(int param_1);
extern "C" void __cdecl FUN_00d36b70();
extern "C" void __cdecl FUN_00d34790();
extern "C" void __cdecl QueryClosestPoints();
extern "C" void __cdecl FUN_00d34810();
void __cdecl FUN_00d36bb0(void** p);
extern "C" void __cdecl FUN_00d36be0();
extern "C" void __cdecl FUN_00d43dc0();
extern "C" void __cdecl GetClosestPointsShapeCollection();
extern "C" void __cdecl FUN_00d43b90();
void __cdecl FUN_00d36c30(void* p);
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void __cdecl FUN_00d3dbe0(void* p);
void __cdecl CreateTargetAgent(void);
void __cdecl QueryD3DCollector(void);
void __cdecl FUN_00d3e110(void);
void __cdecl FUN_00d3ac80(void);
void FUN_00d3dc10(void* p);
struct FUN_00db0920 {
    void Init();
};
void* __cdecl InitAndGetOffset(void* a, void* b, void* c);
struct CollisionAgentFunctionTable {
    void* a;
    void* b;
    void* c;
    void* d;
    char e;
    char f;
};
struct Agent {
    void FUN_00cfbbe0(CollisionAgentFunctionTable*, int, int);
};
void __cdecl FUN_00d2e680();
void __cdecl FUN_00d2e970();
void __cdecl FUN_00d2e9b0();
void __cdecl FUN_00d2daf0();
void __cdecl FUN_00d2df50();
void __cdecl FUN_00d312f0();
void __cdecl FUN_00d31110();
void __cdecl FUN_00d2f0d0();
void __cdecl CreateAgentForBodyPair();
void __cdecl FUN_00d2dc70(Agent* a);
void ReplaceEntry(int param_1, int param_2, int param_3, unsigned short param_4);
struct FUN_00d27f50_Obj {
    void __thiscall Insert(int a, int b, int c);
    void __thiscall FUN_00d27f50(int param_1, int param_2);
};
struct FUN_00d27f70 {
    int** m_ppIndices;
    int m_iIndexCount;

    FUN_00d27f70(int** indices, int numIndices);
};
struct FUN_00d27ff0_class {int** values; void __thiscall UnionFindMerge(int first, int second);};
struct D28030FixedArray {
    int* m_data;
    int m_iElementCount;

    int& operator[](int i) { return m_data[i]; }
};
struct D28030UnionFind {
    D28030FixedArray& m_pParentArray;

    __forceinline int _findRootOfNode(int i)
    {
        int root = i;
        while (m_pParentArray[root] >= 0)
            root = m_pParentArray[root];
        while (m_pParentArray[i] >= 0) {
            int j = m_pParentArray[i];
            m_pParentArray[i] = root;
            i = j;
        }
        return i;
    }

    void Union(int i, int j);
};
struct LinkedIndexArray { int** entries; int count; void FUN_00d280e0(); };
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct IndexBuffer { int* data; int size; unsigned capacityFlags; };
struct IndexStorage { int* data; };
struct AllocationManager { int unk00; int unk04; int unk08; int unk0C; void* allocator; };
AllocationManager* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, IndexBuffer*, int);
struct IndexRemapper { IndexStorage* entries; int length; void FUN_00d280e0(); void RemapIndices(IndexBuffer*); };
struct hkMemAllocStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& sizeInOut);
    virtual void ReturnMemory(void* p, int size);

    int* bufAllocInts(int& n)
    {
        int s = n * 4;
        void* p = AllocateBufferWithSize(s);
        n = s / 4;
        return (int*)p;
    }
};
struct hkMemCtxStub
{
    int unk00;
    int unk04;
    int unk08;
    hkMemAllocStub* alloc;
    void* mem;

    hkMemAllocStub& temp() { return *alloc; }
    void* heap() { return mem; }
};
hkMemCtxStub* GetMemCtx();
void ArrayReserveImpl(void* mem, void* arr, int numElem, int elemSize);
struct IntArrayStub
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void reserveWith(void* mem, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            ArrayReserveImpl(mem, this, n < cap2 ? cap2 : n, 4);
        }
    }
    void setSizeWith(void* mem, int n)
    {
        reserveWith(mem, n);
        m_iElementCount = n;
    }
};
struct KeyArrayStub
{
    IntArrayStub* m_keys;
    int m_iElementCount;

    void BuildKeyOffsets(IntArrayStub* counts, IntArrayStub* out);
};
typedef void (__cdecl *D2F2C0Func)();
struct D2F2C0AgentFuncs {
    D2F2C0Func m_pCreateFunc;
    D2F2C0Func m_pQueryPenetrationsFunc;
    D2F2C0Func m_getClosestPointsFunc;
    D2F2C0Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
class D2F2C0Dispatcher {
public:
    void registerCollisionAgent(D2F2C0AgentFuncs& f, int typeA, int typeB);
};
void __cdecl FUN_00d2fa00();
void __cdecl FUN_00d2e970();
void __cdecl FUN_00d2e9b0();
void __cdecl FUN_00d2daf0();
void __cdecl FUN_00d2f9d0();
void __cdecl FUN_00d312f0();
void __cdecl FUN_00d31110();
void __cdecl FUN_00d2f0d0();
void __cdecl CreateAgentForBodyPair();
void __cdecl FUN_00d2f2c0(D2F2C0Dispatcher* dispatcher);
struct CallTarget_00d2f760 { int FUN_00d2f760(int, int, int, int); };
struct SearchObject {
    int FUN_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
struct FnvCpu_FUN_00d31730_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d31730_CpuObject {
    void FUN_00d315d0(void*, void*, unsigned int, FnvCpu_FUN_00d31730_CpuCallData*);
    void FUN_00d31730(void*, void*, unsigned int, unsigned int);
};
extern "C" void __cdecl InitBlockPool(void* p);
extern int DAT_010ced34;
struct FUN_00d36b20_Class {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    FUN_00d36b20_Class* __thiscall FUN_00d36b20(int param1, int param2, int* param3, int param4);
};
struct FUN_00d36cc0_Obj {
    void __thiscall FUN_00d368c0(int a1, int a2, int a3, int a4);
    void __thiscall FUN_00d36cc0(int param_1, int param_2, int param_3, int param_4);
};
struct FnvCpu_FUN_00d36ce0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d36ce0_CpuObject {
    void FUN_00d36940(void*, void*, unsigned int, FnvCpu_FUN_00d36ce0_CpuCallData*);
    void FUN_00d36ce0(void*, void*, unsigned int, unsigned int);
};
extern float DAT_0104da48;
class D37B90Collector {
public:
    D37B90Collector(int iFilter) : m_fEarlyOutDistance(DAT_0104da48), m_iFilter(iFilter) {}
    virtual void AddCdPoint(const void* pkEvent);

    float m_fEarlyOutDistance;
    int m_iFilter;
};
class D37B90Agent {
public:
    void FUN_00d37010(void* pkA, void* pkB, void* pkInput, D37B90Collector* pkCollector);
    void FUN_00d37b90(void* pkA, void* pkB, void* pkInput, int iFilter);
};
void __cdecl ReleaseHandles(int a1, int a2, int a3, int a4);
void __cdecl FUN_00d39130(int a1, int a2, int a3, int a4, int a5);
struct FnvCpu_FUN_00d3f480_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d3f480_CpuObject {
    void FUN_00d3e850(void*, void*, unsigned int, FnvCpu_FUN_00d3f480_CpuCallData*);
    void FUN_00d3f480(void*, void*, unsigned int, unsigned int);
};
extern float DAT_0104da48;
struct S_00d3f4c0_Obj {
    virtual void vfn0();
    float unk04;
    int unk08;
    S_00d3f4c0_Obj(int a) : unk04(DAT_0104da48), unk08(a) {}
};
void* __cdecl FUN_00d3ebe0(void* a, void* b, void* c, S_00d3f4c0_Obj* o);
void* __cdecl FUN_00d3f4c0(void* a, void* b, void* c, int d);
void __cdecl FUN_00d3fce0(CollisionAgentFunctionTable*);
void __cdecl FUN_00d3fd00(Agent* agent);
struct FUN_00d3fd60_cls_Entry { unsigned short m_key; unsigned short m_uiFilterValue; };
struct FUN_00d3fd60_cls
{
    unsigned char m_unk00;
    unsigned char m_unk01;
    FUN_00d3fd60_cls_Entry m_entries[7];
    unsigned short m_key7;
    unsigned char m_unk32;
    unsigned char m_uiItemCount;
    void __thiscall RemoveEntry(int index);
};
struct FUN_00d3fd60_cls_Ref
{
    unsigned char m_unk00;
    unsigned char m_unk01;
    unsigned char m_iObjectReferenceCount;
};
void* __cdecl RemoveEntryByKey(FUN_00d3fd60_cls_Ref* ref, FUN_00d3fd60_cls* table, unsigned short key);
struct FUN_00d3fda0_entry {
    unsigned short key00;
    unsigned short val02;
};
struct FUN_00d3fda0_table {
    unsigned short unk00;
    FUN_00d3fda0_entry entries[7];
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char count;
};
int __cdecl FindOrClaimEntry(int unused, FUN_00d3fda0_table* table, unsigned short value);
struct D3FE10Agent {
    unsigned short m_flags;
    unsigned short m_iOwnerObjectOffset;
};
struct D3FE10Entry {
    D3FE10Agent m_pAgents[8];
    unsigned char unk20;
    unsigned char m_numAgents;
    unsigned short unk22;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
struct D3FE10Header {
    unsigned short unk00;
    unsigned char m_iNumberOfEntries;
};
class D3FE10Manager {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void ResetAgent(unsigned short id, void* pkInfo);
};
D3FE10Entry* __cdecl ResetEntryAgents(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, void* pkInfo);
template <class T> class hkArrayD27 {
public:
    T& operator[](int i) { return m_data[i]; }
    const T& operator[](int i) const { return m_data[i]; }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class hkUnionFindD27 {
public:
    int FindRoot(int i);

    hkArrayD27<int>& m_pParentArray;
};
extern int DAT_010ce81c;
struct SpawnedBuf { void* m_iWordAt00; unsigned char m_iWordAt04; int m_8; };
struct Wrapper {
    void ForwardToFunction(int,int,int,SpawnedBuf*);
    void FUN_00d37bd0(int a,int b,int c,int d);
};
typedef void (*CallbackD3D)();
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void FUN_00d3e110();
void FUN_00d3ac80();
struct AgentFuncsD3D {
    AgentFuncsD3D() : m_bA(false), m_bB(false) {}

    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};
static __declspec(noinline) void InitFuncsB(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateRetObj;
    pkFuncs->m_pfnB = FUN_00d3d3e0;
    pkFuncs->m_pfnC = FUN_00d3d8c0;
    pkFuncs->m_pfnD = FUN_00daf8e0;
    pkFuncs->m_bA = false;
    pkFuncs->m_bB = false;
}
static __declspec(noinline) void InitFuncsA(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateTargetAgent;
    pkFuncs->m_pfnB = QueryD3DCollector;
    pkFuncs->m_pfnC = FUN_00d3e110;
    pkFuncs->m_pfnD = FUN_00d3ac80;
    pkFuncs->m_bA = true;
    pkFuncs->m_bB = false;
}
void (*g_apfnInitD3D[2])(AgentFuncsD3D*) = { InitFuncsA, InitFuncsB };
class DispatcherD3D {
public:
    void RegisterAgent(AgentFuncsD3D* pkFuncs, int iA, int iB);
};
void __cdecl RegisterD3DAgents(DispatcherD3D* pkDispatcher);
struct D27690_Atom {
    unsigned short m_type;
};
struct D27690_ConstraintInfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct D27690_Modifier {
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_usModifierAtomSize;
    unsigned short m_childResult;
    D27690_Atom* m_pChildAtom;

    void FUN_00d22090(D27690_ConstraintInfo* info, unsigned char* flags);
};
struct D27690_Entity {
    int unk000; int unk004; int unk008; int unk00C;
    int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C;
    int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C;
    int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C;
    int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C;
    int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC;
    int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC;
    unsigned short unk0D0;
    unsigned char unkD2;
};
struct D27690_Internal {
    void* m_pHavokConstraint;
    int unk04;
    int unk08;
    D27690_Atom* m_kBridgeAtoms;
    unsigned short m_childResult;
    unsigned short unk12;
    unsigned short m_stats;
};
struct D27690_Instance {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D27690_Modifier* m_pConstraintModifier;
    D27690_Entity* m_pEntityA;
    D27690_Entity* m_pEntityB;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    D27690_Internal* m_pConstraintInternal;
};
struct D27690_Owner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void checkReadOnly();

    int unk04;
    int unk08;
    int m_iElementCount;

    void FUN_00cb7480(void* unk, D27690_ConstraintInfo* info);
};
struct D27690_Allocator {
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p, int size);
};
extern unsigned short DAT_010cb7a8;
void __cdecl FUN_00d27690(D27690_Instance* instance, D27690_Owner* owner, unsigned int modifierType);
struct Base {
    int unk4;
    char m_8;
    Base(int a, int b);
    virtual void v0();
};
struct FUN_00d21930 : Base {
    FUN_00d21930(int a, int b);
    virtual void v0();
};
struct FUN_00d219e0_node
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d219e0_node* unk0C;
};
struct FUN_00d219e0_cls
{
    int unk00;
    unsigned char unk04;
    FUN_00d219e0_node* unk08;
    int unk0C;
    FUN_00d219e0_node* unk10;
    int unk14;
    void __thiscall SetLists(FUN_00d219e0_node* a, FUN_00d219e0_node* b);
};
extern int DAT_0101e594;
struct VtblStub_0101e594 { void* m_ppVirtualMethodTable; };
extern "C" void __cdecl FormHeap_Free(VtblStub_0101e594*);
struct FUN_00d26210
{
    void* m_ppVirtualMethodTable;
    FUN_00d26210(char construct);
};
struct PairEntry
{
	void* m_pCollisionAgent;
	unsigned int m_link0;
	unsigned int m_link1;
	int m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};
struct PairNode
{
	int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
	int m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
	int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
	int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
	int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c;
	int m_a0, m_a4, m_a8;
	PairEntry* m_entries;
	unsigned short m_iNumberOfEntries;
	unsigned short m_pRayCursor;
};
void* __cdecl FindSharedEntryValue(PairNode* a, PairNode* b);
struct FUN_00d277f0_node
{
    unsigned short unk00;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00d277f0_node* unk14;
};
struct FUN_00d277f0_arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d277f0_node* unk10;
};
FUN_00d277f0_node* __cdecl FUN_00d277f0(FUN_00d277f0_arg* a);
struct FUN_00d61840_class {
    int m_iWordAt00;
    int __thiscall FUN_00d61c10(int a);
    int __thiscall ReplaceChar(int a, int b, int c);
};
int __cdecl CallAndGetId(int a, FUN_00d61840_class* obj);
struct PathHelper {
    char* m_data;

    void __thiscall FUN_00d61c10(const char* s);
    void __thiscall ReplaceChar(char from, char to, int all);
    void __thiscall FUN_00d62190(const char* from, const char* to, int all);
    int __thiscall FUN_00d61560(const char* s);
    void __thiscall RemoveFront(int count);
};
const char* __cdecl FUN_00d2b360(const char* path, PathHelper* str);
struct FnvCpu_FUN_00d2c7d0_CpuInterface {
    virtual void Invoke(int value);
};
void __cdecl FUN_00d2c7d0(FnvCpu_FUN_00d2c7d0_CpuInterface* object);
class FUN_00d2c7e0 {
public:
    virtual ~FUN_00d2c7e0();
    FUN_00d2c7e0(int count);
};
class ObjD2C840 : public FUN_00d2c7e0 {
public:
    virtual ~ObjD2C840();
    ObjD2C840(int count) : FUN_00d2c7e0(count) {}
    static void* operator new(unsigned int, void* p) throw() { return p; }
    static void operator delete(void*, void*) throw() {}
};
void __cdecl ConstructObjD2C840(void* storage, int count);
struct FUN_00d04350_Obj
{
    void __thiscall Create(int a, int b);
};
struct FUN_00d2cd80_Obj
{
    int unk00;
    FUN_00d04350_Obj unk04;

    FUN_00d2cd80_Obj* __thiscall FUN_00d2cd80();
};
struct SubA { void FUN_00d87910(); };
struct SubB { void Create(int a, int b); };
struct C_d2cda0 {
    int m_iWordAt00;
    int unk04;
    SubA a8;
    int unk0C, unk10, unk14;
    int m_18;
    int unk1C;
    char m_20;
    char pad21[3];
    SubB b24;
    int m_28;
    int m_2c;
    C_d2cda0* FUN_00d2cda0();
};
struct FnvCpu_FUN_00d329b0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d329b0_CpuObject {
    void FUN_00d32170(void*, void*, unsigned int, FnvCpu_FUN_00d329b0_CpuCallData*);
    void DispatchWithBound(void*, void*, unsigned int, unsigned int);
};
int __cdecl FUN_00d32ac0(int param_1, int param_2);
void* __cdecl FUN_00d32ad0(int unused, char* p);
extern int DAT_010ce81c;
void __cdecl FUN_00d33b90(int b, int a, int c, SpawnedBuf* buffer);
void __cdecl InitSpawnedBuffer(int a, int b, int c, int d);
struct FUN_00d34aa0_Obj {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();

    void __thiscall FUN_00d338e0(int a, int b, int c, int d);
    virtual void __thiscall FUN_00d34aa0(int a, int b, int c, int d);
};
struct FnvCpu_FUN_00d34b00_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d34b00_CpuObject {
    void FUN_00d33b70(void*, void*, unsigned int, FnvCpu_FUN_00d34b00_CpuCallData*);
    void DispatchCpuCall(void*, void*, unsigned int, unsigned int);
};
void RemoveKeyFromTable(int, unsigned short* table, unsigned short key);
void __cdecl InsertIntoSlotArray(void* unused, unsigned short* slots, unsigned short value);
void FUN_00d39090();
typedef void (*CallbackD3D)();
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void FUN_00d3e110();
void FUN_00d3ac80();
struct FUN_00d390a0_Leaf {
    char unk00[0x20];
};
struct FUN_00d390a0_Mid {
    FUN_00d390a0_Leaf* m_pLeafNode;
};
struct FUN_00d390a0_Owner {
    int unk00;
    FUN_00d390a0_Mid* m_mid;
};
struct FUN_00d390a0_Flags {
    char unk00;
    char unk01;
    unsigned char unk02;
};
struct FUN_00d390a0_Out {
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
void __cdecl ComputeInverseLengths(void* a, void* b);
char* __cdecl InitOutputDefaults(FUN_00d390a0_Owner* owner, FUN_00d390a0_Flags* flags, FUN_00d390a0_Out* out);
struct D390Callback {
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(unsigned int key, void* context);
};
struct D390HandleTable {
    unsigned short handles[3];
    unsigned short state06;
    unsigned short state08;
    unsigned short state0a;
    unsigned short state0c;
    unsigned short state0e;
    unsigned short state10;
    unsigned short state12;
    unsigned short state14;
    unsigned short state16;
    unsigned short state18;
    unsigned short state1a;
    unsigned short state1c;
    unsigned short state1e;
    unsigned short state20;
};
unsigned short* __cdecl ReleaseHandles(void* unused, D390HandleTable* handles, D390Callback* callback, void* context);
struct D3FD30Funcs {
    D3FD30Funcs() : m_bA(false), m_bB(false) {}
    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};
void __cdecl FUN_00d3fce0(D3FD30Funcs* pkFuncs);
class D3FD30Dispatcher {
public:
    void AddSpawnEntry(D3FD30Funcs* pkFuncs, int iA, int iB);
};
void __cdecl DispatchFuncs(D3FD30Dispatcher* pkDispatcher);
void FUN_00d3fde0();
extern int DAT_0102e388;
struct Foo00d24660 {
    void FUN_00d24660();
};
class hkMemoryAllocatorD262 {
public:
    virtual ~hkMemoryAllocatorD262() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD262 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD262* m_pStreamAllocator;
    hkMemoryAllocatorD262& heap() { return *m_pStreamAllocator; }
};
namespace hkRouterD262 {
    extern "C" hkMemoryRouterD262& __cdecl FUN_00c85750() throw();
}
class FUN_00d496d0 {
public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00d24660() throw();

    static void operator delete(void* p) throw()
    {
        hkRouterD262::FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d496d0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d496d0* FUN_00d262e0(unsigned int uiFlags) throw();
};
void FUN_00da3510(void*, void*);
void FUN_00d2d460(int, void* b, void* c);
extern unsigned char DAT_011b4284;
void __cdecl FUN_00d2f530(unsigned char* p);
extern unsigned char DAT_011b4284;
void __cdecl FUN_00d2f540(unsigned char value);
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern "C" void __cdecl GetClosestPointsShapeCollection();
struct D347D0Query {
    const unsigned char* descriptor;
    float bound;
    unsigned int filter;
};
void __cdecl QueryClosestPoints(void* a, void* b, void* c, unsigned int filter);
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct D34970Context {
    void* pointer;
    float maxDistance;
    int option;
};
extern "C" void __cdecl FUN_00d339d0(int first, int second, int third, D34970Context* context);
void __cdecl FUN_00d34970(int arg0, int arg1, int arg2, int arg3);
extern int DAT_010ce81c;
struct D34ac0Struct {
    void* e;
    unsigned char f;
    void* g;
};
struct FUN_00d33c80_class {
    void FUN_00d33c80(void* a, void* b, void* c, void* d);
    void FUN_00d34ac0(void* a, void* b, void* c, void* d);
};
struct D3C380_Allocator {
    virtual void v0();
    virtual void* alloc(int size);
};
struct D3C380_Obj {
    void** vt;
    unsigned short w4;
    unsigned short w6;
    int i8;
    unsigned short wC;
};
extern unsigned int DAT_010cefdc;
D3C380_Obj* __cdecl CreateD3C380Obj(int a1, int a2, int a3, int a4);
// CreateRetObj: builds a 0x20-byte record from the audio allocation pool.
struct IAlloc
{
    virtual void* unk00();
    virtual void* Alloc(int size);
};
struct SubBlock
{
    int d0, d1, d2, d3;
};
struct RetObj
{
    void* vtbl;             // 0x00
    unsigned short f04;     // 0x20
    unsigned short f06;     // 1
    int f08;                // param 4
    unsigned short f0c;     // 0xffff
    unsigned short f0e;
    SubBlock m10;
};
struct AllocMgr
{
    int unk00, unk04, unk08, unk0c;
    IAlloc* allocator;
};
extern int DAT_010cf060;
extern void __cdecl FUN_00cd7160(void* src, void* dst);
void* __cdecl CreateRetObj(int a1, char** a2, int a3, int a4);
extern int DAT_010cf0e4;
struct D3E270_obj;
struct D3E270_alloc {
    virtual void v00();
    virtual D3E270_obj* alloc(int size);
};
struct D3E270_obj {
    D3E270_alloc* vt;
    unsigned short f04;
    unsigned short f06;
    int f08;
    unsigned short f0c;
};
struct D3E270_mgr {
    int r00;
    int r04;
    int r08;
    int r0c;
    D3E270_alloc* r10;
};
D3E270_obj* __cdecl FUN_00d3e270(int a1, int a2, int a3, int a4);
struct D3FE70Info {
    void* pkInfo;
};
D3FE10Entry* __cdecl FUN_00d3fe70(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, D3FE70Info kInfo);

#include <xmmintrin.h>
struct Obj_d284f0 {
    float unk00[52];
    __m128 m_kFirstVector;   // +0xd0
    __m128 m_kTrailingVector;   // +0xe0
};

// @fnv 0x00d284f0
static __declspec(noinline) float FUN_00d284f0(float t, Obj_d284f0* obj)
{
    __m128 sqA = _mm_mul_ps(obj->m_kFirstVector, obj->m_kFirstVector);
    float a;
    _mm_store_ss(&a, _mm_add_ss(_mm_shuffle_ps(sqA, sqA, 0xAA), _mm_add_ss(_mm_shuffle_ps(sqA, sqA, 0x55), sqA)));
    __m128 sqB = _mm_mul_ps(obj->m_kTrailingVector, obj->m_kTrailingVector);
    float b;
    _mm_store_ss(&b, _mm_add_ss(_mm_shuffle_ps(sqB, sqB, 0xAA), _mm_add_ss(_mm_shuffle_ps(sqB, sqB, 0x55), sqB)));
    return t * t * b + a;
}

volatile int g_in_d284f0;
volatile float g_t_d284f0;
volatile float g_out_d284f0;
void caller_d284f0()
{
    g_out_d284f0 = FUN_00d284f0(g_t_d284f0, (Obj_d284f0*)g_in_d284f0);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct FourFloatVector { __m128 value; };
struct Transform { FourFloatVector x,y,z,translation; };
struct Contact { FourFloatVector position,normal; unsigned int id,unk24,unk28,unk2c; };
struct Shape;
struct Body { Shape* shape; void* unk04; Transform* transform; __forceinline Shape* GetShape() const {return shape;} __forceinline const Transform& GetTransform() const {return *transform;} };
struct Header { unsigned short flags; unsigned char count; };
struct Context;
struct Threshold;
struct ContactPair;
struct Manager {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual unsigned short Add(const Body&,const Body&,const Threshold&,Context&,void*,const ContactPair&);
 virtual int Reserve(int);
 virtual void Remove(unsigned short,void*);
};
struct ShapeBase {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();
 virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();
 virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();
 virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();
 virtual int Process(unsigned short*,unsigned char&,FourFloatVector&,const Transform&,const Shape*,const Transform&,FourFloatVector&);
 unsigned int unk04,unk08,unk0c; float radius; unsigned int unk14,unk18,unk1c;
};
struct Shape : ShapeBase {
 FourFloatVector vertices[3];
};
struct Threshold {float unk00,unk04,distance;};
struct Pair {Body* a;Body* b;void* unk08;Threshold* threshold;Manager* manager;};
struct DeferredEntry {Contact* contact; Header* header;unsigned short* ids;};
struct Deferred { DeferredEntry* next; Contact** references; DeferredEntry* begin;DeferredEntry* end;};
struct Context {
 Contact* next; void* owner;
 unsigned int unk08,unk0c;
 Contact storage[256];
 unsigned int unk3010;
 unsigned int unk3014;
 unsigned int unk3018;
 unsigned int unk301c;
 unsigned int unk3020;
 unsigned int unk3024;
 unsigned int unk3028;
 unsigned int unk302c;
 unsigned int unk3030;
 unsigned int unk3034;
 unsigned int unk3038;
 unsigned int unk303c;
 unsigned int unk3040;
 unsigned int unk3044;
 unsigned int unk3048;
 unsigned int unk304c;
 unsigned int unk3050;
 unsigned int unk3054;
 unsigned int unk3058;
 unsigned int unk305c;
 unsigned int unk3060;
 unsigned int unk3064;
 unsigned int unk3068;
 unsigned int unk306c;
 unsigned int unk3070;
 unsigned int unk3074;
 unsigned int unk3078;
 unsigned int unk307c;
 Deferred* deferred;
};
struct ProfileSample { const char* name;unsigned int ticks,unk08;};
struct ProfileState {ProfileSample* begin;ProfileSample* next;ProfileSample* unk08;ProfileSample* end;};
extern unsigned int DAT_0126835c;
extern char DAT_010ceeec[];
extern char DAT_010c41f8[];
extern float DAT_0104da48;
struct ContactTag {unsigned char count,unk01,metadata,unk03;unsigned int unk04;};
struct ContactPair {FourFloatVector position,normal;};
void FUN_00cd6520(FourFloatVector*,float,FourFloatVector*,float,void*,float,int,ContactPair*,ContactTag*);
__forceinline void TransformPoints(const Transform& matrix, const FourFloatVector* in, int n, FourFloatVector* out) {
 FourFloatVector c0=matrix.x, c1=matrix.y, c2=matrix.z, c3=matrix.translation;
 for(int i=n-1;i>=0;--i) {
  __m128 v=in[i].value;
  __m128 sy=_mm_shuffle_ps(v,v,0x55);
  __m128 sx=_mm_shuffle_ps(v,v,0);
  __m128 sz=_mm_shuffle_ps(v,v,0xaa);
  out[i].value=_mm_add_ps(_mm_add_ps(_mm_mul_ps(sy,c1.value),_mm_mul_ps(sx,c0.value)),_mm_add_ps(_mm_mul_ps(sz,c2.value),c3.value));
 }
}
__forceinline unsigned short AddContact(Manager* m,Body* a,Body* b,Threshold* in,Context* out,ContactPair* cp){return m->Add(*a,*b,*in,*out,0,*cp);}
struct ContactWorkspace {FourFloatVector pointsA[2];FourFloatVector pointsB[3];ContactPair contacts[3];};
// @fnv 0x00d39390
unsigned short* FUN_00d39390(Pair* pair,Header* header,unsigned short* ids,FourFloatVector* normal,Context* context) {
 unsigned int count;
 ProfileState* profile=(ProfileState*)TlsGetValue(DAT_0126835c);
 ProfileSample* event=profile->next;
 if(event<profile->end) {
  event->name=DAT_010ceeec;
  unsigned int ticks;
  __asm {
   rdtsc
   mov dword ptr[ticks], eax
  }
  event->ticks=ticks;
  profile->next=event+1;
 }
 count=0;
 Shape* shapeA=pair->a->GetShape();
 Shape* shapeB=pair->b->GetShape();
 FourFloatVector endPoints[2];
 FourFloatVector triVertices[3];
 ContactPair points[3];
 TransformPoints(pair->a->GetTransform(),shapeA->vertices,2,endPoints);
 
 TransformPoints(pair->b->GetTransform(),shapeB->vertices,3,triVertices);
 
 ContactTag tags[3];
 FUN_00cd6520(endPoints,shapeA->radius,triVertices,shapeB->radius,ids+4,3.40282e+38f,1,points,tags);
 int closest=points[0].normal.value.m128_f32[3] < points[1].normal.value.m128_f32[3] ? 0 : 1;
 int k=0; FourFloatVector* cp=&points[0].normal;
 for(;k<3;++k, cp+=2) {
   unsigned short id=ids[k];
   if((*cp).value.m128_f32[3] < pair->threshold->distance) {
     if(id==0xffff) {
       if(context->deferred) {
         if(pair->manager->Reserve(1)) goto store_id;
         DeferredEntry* entry=context->deferred->next++;
         entry->contact=context->next; entry->ids=ids; entry->header=header;
       } else {
         id=AddContact(pair->manager,pair->a,pair->b,pair->threshold,context,(ContactPair*)(cp-1));
         if(id==0xffff) goto store_id;
       }
     }
     unsigned char quality=tags[k].count;
     if(quality>0) {
       FourFloatVector scratch=(*cp);
       int result=shapeB->Process((unsigned short*)&tags[k].metadata,quality,*(cp-1),pair->b->GetTransform(),shapeA,pair->a->GetTransform(),scratch);
       if(!result) {
         if(id!=0xffff) {
           pair->manager->Remove(id,context->owner);
           ids[k]=0xffff;
         }
         continue;
       }
       if(result==1) {
         (*cp).value=_mm_shuffle_ps(scratch.value,_mm_unpackhi_ps(scratch.value,(*cp).value),0xc4);
       }
     }
     Contact* contact=context->next++;
     ++count;
     contact->position.value=(*(cp-1)).value;
     contact->normal.value=(*cp).value;
     contact->id=id;
     if(k==closest && context->deferred) {
       Deferred* deferred=context->deferred;
       *deferred->references=contact;
       ++deferred->references;
     }
   } else if(id!=0xffff) {
      pair->manager->Remove(id,context->owner);
      id=0xffff;
   }
   store_id:
   ids[k]=id;
 }
 normal->value=points[closest].normal.value;
 header->count=(unsigned char)count;
 profile=(ProfileState*)TlsGetValue(DAT_0126835c);
 event=profile->next;
 if(event<profile->end) {
   event->name=DAT_010c41f8;
   unsigned int ticks;
   __asm {
    rdtsc
    mov dword ptr[ticks], eax
   }
  event->ticks=ticks;
   profile->next=event+1;
 }
 return ids+16;
}
