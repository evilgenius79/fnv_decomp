// src/staging/blk_00d20000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
void __cdecl FUN_00d367b0(int pObject);
extern "C" void __cdecl FUN_00d36b70();
extern "C" void __cdecl FUN_00d34790();
extern "C" void __cdecl QueryClosestPoints();
extern "C" void __cdecl FUN_00d34810();
void __cdecl FUN_00d36bb0(void** p);
extern "C" void __cdecl FUN_00d36be0();
extern "C" void __cdecl FUN_00d43dc0();
extern "C" void __cdecl GetClosestPointsShapeCollection();
extern "C" void __cdecl FUN_00d43b90();
void __cdecl FUN_00d36c30(void* apObject);
void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();
void __cdecl FUN_00d3dbe0(void* apObject);
void __cdecl CreateTargetAgent(void);
void __cdecl QueryD3DCollector(void);
void __cdecl FUN_00d3e110(void);
void __cdecl FUN_00d3ac80(void);
void FUN_00d3dc10(void* apObject);
struct FUN_00db0920 {
    void Init();
};
void* __cdecl InitAndGetOffset(void* apUnused1, void* apUnused2, void* apObject);
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
void __cdecl FUN_00d2dc70(Agent* pAgent);
void ReplaceEntry(int pList, int pOldEntry, int pNewEntry, unsigned short usValue);
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
void* __cdecl FUN_00d3f4c0(void* a, void* b, void* c, int iValue);
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
void* __cdecl FindSharedEntryValue(PairNode* pNodeA, PairNode* pNodeB);
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
const char* __cdecl FUN_00d2b360(const char* path, PathHelper* aPathHelper);
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
extern float DAT_01011d78;
extern float DAT_01016248;
extern float DAT_01017718;
struct D212D0Seg {
    __m128 a;
    __m128 b;
};
struct D212D0Obj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(char* hitOut, D212D0Seg* seg, void* p3);

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
    __m128 row70;

    unsigned char* FUN_00d212d0(unsigned char* out, D212D0Seg* seg, void* p3);
};
namespace sd21cc0 {

class Target {
public:
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
    virtual int Dispatch(int iArg0, int iArg1);
};

// @fnv 0x00d21cc0
int FUN_00d21cc0(Target* pkTarget, int iArg0, int iArg1)
{
    return pkTarget->Dispatch(iArg0, iArg1);
}

}
struct __declspec(align(16)) Vector4D22DC0 {
    float x;
    float y;
    float z;
    float w;
    void setZero4() { *reinterpret_cast<__m128*>(this) = _mm_setzero_ps(); }
    void operator=(const Vector4D22DC0& kOther) { *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&kOther); }
};
struct RotationD22DC0 {
    Vector4D22DC0 m_kColumn0;
    Vector4D22DC0 m_kColumn1;
    Vector4D22DC0 m_kColumn2;
    float& operator()(int iRow, int iCol) { return reinterpret_cast<float*>(&m_kColumn0 + iCol)[iRow]; }
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};
struct TransformD22DC0 {
    RotationD22DC0 m_rotation;
    Vector4D22DC0 m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};
struct ReferencedD22DC0 {
    ReferencedD22DC0() throw() { m_sReferenceCount = 1; }
    virtual ~ReferencedD22DC0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeD22DC0 : public ReferencedD22DC0 {
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType) { m_kMotionTransform.setIdentity(); }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    TransformD22DC0 m_kMotionTransform;
    int m_type;
};
struct FUN_00d22dc0 : public ShapeD22DC0 {
    FUN_00d22dc0(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float fRadius, int iA, int iB) throw();
    virtual ~FUN_00d22dc0() throw();
    Vector4D22DC0 m_kA;
    Vector4D22DC0 m_kB;
    float m_fBoundRadius;
    int m_iA;
    int m_iB;
};
struct E48 { int a[12]; };
extern "C" void __cdecl FUN_00d06c30(void* self, int newCap, int elemSize);
extern "C" void __cdecl CopyMemoryBackward(void* dst, const void* src, int size);
struct hkSmallArrayE {
    E48* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void reserve(int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00d06c30(this, newSize, sizeof(E48));
        }
    }
    void Insert(int i, const E48* a, int numtoinsert);
};
struct S00d281b0_Alloc {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <typename T>
    __forceinline void _bufFree(T* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};
struct S00d281b0_Router {
    unsigned int unk00, unk04, unk08;
    S00d281b0_Alloc* allocator;
    S00d281b0_Alloc& heap() { return *allocator; }
};
struct S00d281b0_IntArray {
    int* data;
    int count;
};
struct S00d281b0_Target {
    S00d281b0_IntArray* indices;
    int count;
    int MoveLargestToFirst(S00d281b0_IntArray* values);
};
struct FUN_00d2acf0_base
{
    void** vtbl;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d2acf0_base(void* a1, int a2);
};
struct FUN_00d2acf0 : FUN_00d2acf0_base
{
    __m128 unk20;
    __m128 unk30;
    __m128 unk40;
    float unk50;
    float unk54;
    int unk58;
    unsigned char unk5c;

    FUN_00d2acf0(void* a1, __m128* a2, __m128* a3, float a4, float a5, int a6);
};
extern __declspec(thread) unsigned int t_uiMemContextB110;
inline unsigned int GetMemContextB110()
{
    return t_uiMemContextB110;
}
inline void SetMemContextB110(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextB110 = m_uiGeometryShaderFlags;
}
class AutoMemContextB110 {
public:
    AutoMemContextB110(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextB110();
        SetMemContextB110(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextB110() { SetMemContextB110(m_uiPrevious); }
    unsigned int m_uiPrevious;
};
struct hkVector4B110 {
    inline hkVector4B110& operator=(const hkVector4B110& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __m128 m_vComponents;
};
class hkMemoryAllocatorB110 {
public:
    virtual ~hkMemoryAllocatorB110();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterB110 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorB110& heap() { return *m_pStreamAllocator; }
    hkMemoryAllocatorB110* m_pStreamAllocator;
};
hkMemoryRouterB110* __cdecl GetMemoryRouterB110();
class hkReferencedObjectB110 {
public:
    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectB110* b = static_cast<hkReferencedObjectB110*>(GetMemoryRouterB110()->heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkReferencedObjectB110* b = static_cast<hkReferencedObjectB110*>(p);
        GetMemoryRouterB110()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
    virtual ~hkReferencedObjectB110();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct ShapeB110;
struct BodyB110 {
    ShapeB110* getShape() const { return m_pCollisionShape; }
    ShapeB110* m_pCollisionShape;
};
struct InputB110 {
    BodyB110* m_kCollisionBody;
    int m_type;
};
class AgentB110 : public hkReferencedObjectB110 {
public:
    AgentB110(ShapeB110* pShape, const hkVector4B110& kA, const hkVector4B110& kB, float fA, float fB, void* pUser);
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
    hkVector4B110 m_offset;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};
class AgentFactoryB110 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAgentData;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4B110 m_kA;
    hkVector4B110 m_kB;
    hkVector4B110 m_offset;
    float m_fCoefficientA;
    float m_fB;

    AgentB110* FUN_00d2b110(const InputB110* pA, const InputB110* pB);
};
extern __declspec(thread) unsigned int t_uiMemContextD2C9;
inline unsigned int GetMemContextD2C9()
{
    return t_uiMemContextD2C9;
}
inline void SetMemContextD2C9(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextD2C9 = m_uiGeometryShaderFlags;
}
class AutoMemContextD2C9 {
public:
    AutoMemContextD2C9(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextD2C9();
        SetMemContextD2C9(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextD2C9() { SetMemContextD2C9(m_uiPrevious); }
    unsigned int m_uiPrevious;
};
struct hkMemoryAllocatorD2C9 {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterD2C9 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD2C9* m_pStreamAllocator;

    hkMemoryAllocatorD2C9& heap() { return *m_pStreamAllocator; }
};
struct RouterD2C9 {
    static hkMemoryRouterD2C9& __cdecl FUN_00c85750() throw();
};
struct __declspec(align(16)) hkVector4D2C9 {
    __m128 m_vComponents;
    inline hkVector4D2C9& operator=(const hkVector4D2C9& v) { m_vComponents = v.m_vComponents; return *this; }
};
class hkReferencedObjectD2C9 {
public:
    virtual ~hkReferencedObjectD2C9();

    void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectD2C9* b = static_cast<hkReferencedObjectD2C9*>(RouterD2C9::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    void operator delete(void* p, unsigned int nbytes)
    {
        RouterD2C9::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class AgentD2C9 : public hkReferencedObjectD2C9 {
public:
    AgentD2C9(int aiAgentType, int iOwner); // FUN_00d2c910

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4D2C9 m_v20;
};
struct RequestD2C9 {
    int* m_pName;
    int m_iKind;
    int GetName() const { return *m_pName; }
    int* GetNamePtr() const { return m_pName; }
};
struct CountD2C9 {
    int unk00;
    int m_iArrayLength;
};
class FactoryD2C9 {
public:
    AgentD2C9* FUN_00d2c9d0(RequestD2C9* req, CountD2C9* cnt);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iOwner;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4D2C9 m_v20;
};
extern float DAT_0104da48;
extern int DAT_010ce80c;
extern __m128 DAT_010c44d0;
struct Vec { int x, y, z, w; };
struct Src {
    int u[20];
    Vec v;
    int t0, t1, t2, t3;
};
struct Q {
    int* vt;
    float d;
    int p1, p2;
    Vec v;
    int x;
    int t1, t2, t3;
};
void __cdecl FUN_00d2f0d0();
typedef void (__cdecl *Fn)(int, int, Src*, Q*, Q*);
void __cdecl FUN_00d2daf0(int a, int b, Src* c, int d, int e);
struct CallbackState {
    const int* m_pIntegerValue;
    char m_cFlag;
    int m_iValue;
};
struct Holder {
    void FUN_00d315f0(int a, int b, int c, CallbackState* s);
    void FUN_00d2f3f0(int a, int b, int c, int d);
};
extern "C" void _ReadWriteBarrier();
struct ShapeD2F630 {
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct CdBodyD2F630 {
    ShapeD2F630* m_pCollisionShape;
};
struct InputD2F630;
struct CollectorD2F630;
typedef void (__cdecl *AgentFuncD2F630)(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector);
struct AgentFuncsD2F630 {
    AgentFuncD2F630 m_pQueryPenetrationsFunc;
    void* m_func04;
    void* m_func08;
    void* m_func0C;
    void* m_func10;
};
struct DispatcherD2F630 {
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
    unsigned char m_agentTypes[32][32];
    unsigned char m_agentTypesPred[32][32];
    AgentFuncsD2F630 m_agentFuncs[32];
};
struct InputD2F630 {
    DispatcherD2F630* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_createPredictive;
};
void __cdecl FUN_00d2f630(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector);
struct FUN_00d32970_Collector {
    void* vtable;
    unsigned char flag;
    unsigned int value;
};
struct FUN_00d32970_Agent {
    void FUN_00d32150(void* a, void* b, void* c, FUN_00d32970_Collector* collector);
    void FUN_00d32970(void* a1, void* a2, void* a3, unsigned int a4);
};
extern "C" __m128 DAT_010c4c00;
extern "C" void _ReadWriteBarrier(void);
class hkVector4 {
public:
    __m128 m_vComponents;

    __forceinline hkVector4 getSimdAt3() const {
        hkVector4 r;
        r.m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
    __forceinline void addMul4(const hkVector4& a, const hkVector4& b) {
        m_vComponents = _mm_add_ps(_mm_mul_ps(a.m_vComponents, b.m_vComponents), m_vComponents);
    }
    __forceinline static void setNeg4(hkVector4& dst, const hkVector4& a, const __m128& neg) {
        dst.m_vComponents = _mm_xor_ps(a.m_vComponents, neg);
    }
};
struct Point {
    hkVector4 m_pos;
    hkVector4 m_vHitNormal;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    __forceinline void flip() {
        m_pos.addMul4(m_vHitNormal.getSimdAt3(), m_vHitNormal);
        hkVector4::setNeg4(m_vHitNormal, m_vHitNormal, DAT_010c4c00);
    }
};
struct SubShapeId {
    unsigned char m_kPointA : 4;
    unsigned char m_kPointB : 4;
};
struct CastCollector {
    Point* m_currentPoint;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Point m_point000; Point m_point001; Point m_point002; Point m_point003;
    Point m_point004; Point m_point005; Point m_point006; Point m_point007;
    Point m_point008; Point m_point009; Point m_point010; Point m_point011;
    Point m_point012; Point m_point013; Point m_point014; Point m_point015;
    Point m_point016; Point m_point017; Point m_point018; Point m_point019;
    Point m_point020; Point m_point021; Point m_point022; Point m_point023;
    Point m_point024; Point m_point025; Point m_point026; Point m_point027;
    Point m_point028; Point m_point029; Point m_point030; Point m_point031;
    Point m_point032; Point m_point033; Point m_point034; Point m_point035;
    Point m_point036; Point m_point037; Point m_point038; Point m_point039;
    Point m_point040; Point m_point041; Point m_point042; Point m_point043;
    Point m_point044; Point m_point045; Point m_point046; Point m_point047;
    Point m_point048; Point m_point049; Point m_point050; Point m_point051;
    Point m_point052; Point m_point053; Point m_point054; Point m_point055;
    Point m_point056; Point m_point057; Point m_point058; Point m_point059;
    Point m_point060; Point m_point061; Point m_point062; Point m_point063;
    Point m_point064; Point m_point065; Point m_point066; Point m_point067;
    Point m_point068; Point m_point069; Point m_point070; Point m_point071;
    Point m_point072; Point m_point073; Point m_point074; Point m_point075;
    Point m_point076; Point m_point077; Point m_point078; Point m_point079;
    Point m_point080; Point m_point081; Point m_point082; Point m_point083;
    Point m_point084; Point m_point085; Point m_point086; Point m_point087;
    Point m_point088; Point m_point089; Point m_point090; Point m_point091;
    Point m_point092; Point m_point093; Point m_point094; Point m_point095;
    Point m_point096; Point m_point097; Point m_point098; Point m_point099;
    Point m_point100; Point m_point101; Point m_point102; Point m_point103;
    Point m_point104; Point m_point105; Point m_point106; Point m_point107;
    Point m_point108; Point m_point109; Point m_point110; Point m_point111;
    Point m_point112; Point m_point113; Point m_point114; Point m_point115;
    Point m_point116; Point m_point117; Point m_point118; Point m_point119;
    Point m_point120; Point m_point121; Point m_point122; Point m_point123;
    Point m_point124; Point m_point125; Point m_point126; Point m_point127;
    Point m_point128; Point m_point129; Point m_point130; Point m_point131;
    Point m_point132; Point m_point133; Point m_point134; Point m_point135;
    Point m_point136; Point m_point137; Point m_point138; Point m_point139;
    Point m_point140; Point m_point141; Point m_point142; Point m_point143;
    Point m_point144; Point m_point145; Point m_point146; Point m_point147;
    Point m_point148; Point m_point149; Point m_point150; Point m_point151;
    Point m_point152; Point m_point153; Point m_point154; Point m_point155;
    Point m_point156; Point m_point157; Point m_point158; Point m_point159;
    Point m_point160; Point m_point161; Point m_point162; Point m_point163;
    Point m_point164; Point m_point165; Point m_point166; Point m_point167;
    Point m_point168; Point m_point169; Point m_point170; Point m_point171;
    Point m_point172; Point m_point173; Point m_point174; Point m_point175;
    Point m_point176; Point m_point177; Point m_point178; Point m_point179;
    Point m_point180; Point m_point181; Point m_point182; Point m_point183;
    Point m_point184; Point m_point185; Point m_point186; Point m_point187;
    Point m_point188; Point m_point189; Point m_point190; Point m_point191;
    Point m_point192; Point m_point193; Point m_point194; Point m_point195;
    Point m_point196; Point m_point197; Point m_point198; Point m_point199;
    Point m_point200; Point m_point201; Point m_point202; Point m_point203;
    Point m_point204; Point m_point205; Point m_point206; Point m_point207;
    Point m_point208; Point m_point209; Point m_point210; Point m_point211;
    Point m_point212; Point m_point213; Point m_point214; Point m_point215;
    Point m_point216; Point m_point217; Point m_point218; Point m_point219;
    Point m_point220; Point m_point221; Point m_point222; Point m_point223;
    Point m_point224; Point m_point225; Point m_point226; Point m_point227;
    Point m_point228; Point m_point229; Point m_point230; Point m_point231;
    Point m_point232; Point m_point233; Point m_point234; Point m_point235;
    Point m_point236; Point m_point237; Point m_point238; Point m_point239;
    Point m_point240; Point m_point241; Point m_point242; Point m_point243;
    Point m_point244; Point m_point245; Point m_point246; Point m_point247;
    Point m_point248; Point m_point249; Point m_point250; Point m_point251;
    Point m_point252; Point m_point253; Point m_point254; Point m_point255;
    hkVector4 m_normal3020;
    float m_dist3030;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_uiShapeKeys[4];
    unsigned char m_byte3048;
    unsigned char m_byte3049;
    SubShapeId m_byte304a;
};
class LinearCastAgent {
public:
    void FUN_00d33f40(int bodyB, int bodyA, int input, int collector);
    void FUN_00d34c10(int bodyA, int bodyB, int input, int collector);
};
extern "C" void __cdecl FUN_00da3510(int, int);
void __cdecl ForwardCall(int a1, int a2, int a3);
struct D36B70_Heap
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct FUN_00d36b20
{
    void* unk00;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    static __forceinline void* operator new(unsigned int size) throw()
    {
        AllocationManager* manager = FUN_00c85750();
        FUN_00d36b20* object = static_cast<FUN_00d36b20*>(static_cast<D36B70_Heap*>(manager->allocator)->AllocateMemoryBlock(size));
        object->m_usMemSizeAndFlags = (unsigned short)size;
        return object;
    }
    FUN_00d36b20(int param1, int param2, int* param3, int param4) throw();
};
FUN_00d36b20* FUN_00d36b70(int param1, int param2, int* param3, int param4);
#include <xmmintrin.h>
void __stdcall FUN_00d24650(int _param);
class hkpCdBody;
class CollisionAgentContext;
// Explicit layout of the audited collector objects; table objects stay external.
struct hkpCdBodyPairCollector {
    const void* unk00;
    unsigned char unk04;
};
struct hkpSymmetricAgentFlipBodyCollector : hkpCdBodyPairCollector {
    hkpCdBodyPairCollector* unk08;
};
class hkpListAgent {
public:
    void FUN_00d36b00(const hkpCdBody&, const hkpCdBody&,
                     const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
template<class Agent> class hkpSymmetricAgent : public Agent {
public:
    void FUN_00d36d20(const hkpCdBody&, const hkpCdBody&,
                     const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned int DAT_0126835c;
extern char DAT_010ced28[];
extern char DAT_010c41f8[];
extern volatile float DAT_01012054;
struct Body11
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
};
class __declspec(align(16)) FUN_00d01a60
{
public:
    Body11 m_kCollisionBody;
    float m_unk2C;
    FUN_00d01a60();
};
struct __declspec(align(16)) V4q
{
    int m0;
    int m1;
    int m2;
    int m3;
};
struct A1Rec
{
    void* unk00;
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
    V4q unk70;
};
struct PRec
{
    int unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Body11 unk20;
};
struct BroadPhaseHandle
{
    int unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
    int unk1C;
    __forceinline void SetOwnerPointer(void* owner)
    {
        unk19 = (unsigned char)((unsigned int)owner - (unsigned int)this);
    }
};
struct __declspec(align(16)) ZT
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned short unk12;
    BroadPhaseHandle handle;
    __forceinline ZT()
    {
        unk00 = 0;
        unk08 = 0;
        unk0C = 0;
        unk04 = -1;
        unk10 = 0;
        handle.unk14 = 0;
        handle.unk18 = 0;
        handle.unk1C = 0;
        handle.unk1A = 0xff;
        handle.unk19 = 0x7f;
    }
};
struct CollidableBuffer
{
    ZT z;
    FUN_00d01a60 o40;
    __forceinline CollidableBuffer()
    {
        o40.m_unk2C = DAT_01012054;
        z.handle.SetOwnerPointer(&z);
        z.unk11 = 0;
        z.unk12 = 0;
    }
};
struct __declspec(align(16)) O1T
{
    void* FUN_00d33260(A1Rec* a1);
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
struct __declspec(align(16)) CF56Obj
{
    void* FUN_00cf5640(int* c, int b, void* a);
    void* unk00;
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
};
class FUN_00cf5640
{
public:
    FUN_00cf5640(int* name, int count, void* extra);
    virtual ~FUN_00cf5640();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int r18_00;
    int r18_04;
    int r18_08;
};
struct CF56Ret
{
    virtual void vfunc0(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int r18_00;
    int r18_04;
    int r18_08;
};
struct C85Ret
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
void FUN_00c908c0(void* a, void* b, int c, int d);
int FUN_00d35770(O1T* o1, int a2, int a3, int a4, int a5);
static __forceinline int maxSize(int minimum, int value) {
    _ReadWriteBarrier();
    return value <= minimum ? minimum : value;
}
int FUN_00d365d0(A1Rec* a1, int a2, int a3, int a4, int a5);
__declspec(noinline) void __cdecl FUN_00d36c30(void* apObject);
__declspec(noinline) void __cdecl FUN_00d36bb0(CollisionAgentFunctionTable* f)
{
    f->a = (void*)(void (__cdecl*)())&FUN_00d36b70;
    f->b = (void*)&FUN_00d34790;
    f->c = (void*)(void (__cdecl*)())&QueryClosestPoints;
    f->d = (void*)&FUN_00d34810;
    f->e = 0;
    f->f = 1;
}
void __cdecl FUN_00d36c60(void* p);

#include <xmmintrin.h>

extern const __m128 DAT_010c71e0;
extern const __m128 DAT_01017d10;

extern "C" float __cdecl ClampedAcos(float x);

struct hkStepInfo {
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct SimdScalar {
    __m128 value;
    __forceinline SimdScalar(__m128 v) : value(v) {}
    __forceinline operator float() const { float f; _mm_store_ss(&f, value); return f; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(value, value, 0); }
};

struct hkVecQ {
    __m128 data;
    __forceinline __m128& getQuad() { return data; }
    __forceinline const __m128& getQuad() const { return data; }

    __forceinline float& operator()(int a) { return getQuad().m128_f32[a]; }
    __forceinline const float& operator()(int a) const { return getQuad().m128_f32[a]; }

    static __forceinline __m128 rotated(const hkVecQ& q, const hkVecQ& v)
    {
        __m128 w = _mm_shuffle_ps(q.getQuad(), q.getQuad(), 0xff);
        __m128 w2 = _mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0);
        __m128 t1 = _mm_mul_ps(w2, v.getQuad());
        __m128 qv = _mm_mul_ps(v.getQuad(), q.getQuad());
        __m128 s1 = _mm_add_ss(_mm_shuffle_ps(qv, qv, 0x55), qv);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(qv, qv, 0xaa), s1);
        __m128 q2 = _mm_shuffle_ps(q.getQuad(), q.getQuad(), 0xd2);
        __m128 q1 = _mm_shuffle_ps(q.getQuad(), q.getQuad(), 0xc9);
        __m128 c2 = _mm_mul_ps(_mm_shuffle_ps(v.getQuad(), v.getQuad(), 0xc9), q2);
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v.getQuad(), v.getQuad(), 0xd2), q1);
        __m128 cross = _mm_sub_ps(c1, c2);
        __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q.getQuad());
        __m128 sum = _mm_add_ps(_mm_mul_ps(cross, w), _mm_add_ps(t1, t2));
        return _mm_add_ps(sum, sum);
    }

    static __forceinline SimdScalar dot(__m128 a, __m128 b)
    {
        __m128 p = _mm_mul_ps(a, b);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return SimdScalar(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    }

    __forceinline void setAddMul4(const hkVecQ& a, __m128 b, float r)
    {
        __m128 s = _mm_load_ss(&r);
        getQuad() = _mm_add_ps(a.getQuad(), _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b));
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(getQuad(), getQuad());
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        __m128 lenSq = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        __m128 r = _mm_rsqrt_ss(lenSq);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 half = _mm_set_ss(DAT_01016248);
        __m128 nr = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(lenSq, r), r));
        __m128 sc = _mm_mul_ss(_mm_mul_ss(half, r), nr);
        __m128 sel = _mm_andnot_ps(_mm_cmpeq_ss(lenSq, zero), sc);
        getQuad() = _mm_mul_ps(_mm_shuffle_ps(sel, sel, 0), getQuad());
    }

    __forceinline void setCross(const hkVecQ& a, const hkVecQ& b)
    {
        __m128 c2 = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xc9), _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xd2), _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xc9));
        getQuad() = _mm_sub_ps(c1, c2);
    }

    __forceinline void setAbs4(const hkVecQ& a)
    {
        getQuad() = _mm_and_ps(a.getQuad(), DAT_01017d10);
    }

    __forceinline int getMajorAxis(hkVecQ& tmp) const
    {
        tmp.setAbs4(*this);
        return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
    }

    __forceinline void setMul4(float r, const hkVecQ& a)
    {
        __m128 s = _mm_load_ss(&r);
        getQuad() = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), a.getQuad());
    }
};

struct hkpMotionStub {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50();
    virtual void ApplyAngularImpulseToBodies(const hkVecQ& imp);

    int unk04, unk08, unk0c;
    hkVecQ unk10, unk20, unk30, unk40, unk50, unk60;
    hkVecQ m_rotation;
    hkVecQ unk90, unka0, unkb0, unkc0, unkd0;
    hkVecQ m_kAngularVelocity;
};

struct hkpRigidBodyStub {
    hkVecQ unk00, unk10, unk20, unk30, unk40, unk50, unk60;
    hkVecQ unk70, unk80, unk90, unka0, unkb0, unkc0, unkd0;
    hkpMotionStub m_pMotionState;

    void __thiscall FUN_00c9c1d0();

    __forceinline void ApplyAngularImpulseToBodies(const hkVecQ& imp)
    {
        FUN_00c9c1d0();
        m_pMotionState.ApplyAngularImpulseToBodies(imp);
    }
};

struct hkOrientHingedBodyAction {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpRigidBodyStub* m_pEntity;
    int unk1c;
    hkVecQ m_vHingeAxisLS;
    hkVecQ m_forwardAxisLS;
    hkVecQ m_targetForwardWS;
    float m_fSpringStrength;
    float m_fMotorDamping;
    float m_fConeAngle;
    bool m_bSlotEnabled;

    void __thiscall FUN_00d2ad50(const hkStepInfo& stepInfo);
};

// @fnv 0x00d2ad50
void hkOrientHingedBodyAction::FUN_00d2ad50(const hkStepInfo& stepInfo)
{
    if (m_bSlotEnabled)
    {
        hkpRigidBodyStub* rb = m_pEntity;

        hkVecQ forwardWS;
        __m128 forwardQuad = hkVecQ::rotated(rb->m_pMotionState.m_rotation, m_forwardAxisLS);
        forwardWS.getQuad() = forwardQuad;

        hkVecQ hingeWS;
        __m128 hingeQuad = hkVecQ::rotated(rb->m_pMotionState.m_rotation, m_vHingeAxisLS);
        _mm_store_ps(reinterpret_cast<float*>(&hingeWS), hingeQuad);

        hkVecQ targetProj;
        targetProj.setAddMul4(m_targetForwardWS, hingeQuad, -hkVecQ::dot(_mm_load_ps(reinterpret_cast<const float*>(&hingeQuad)), m_targetForwardWS.getQuad()));
        targetProj.normalize3();

        m_fConeAngle = ClampedAcos(hkVecQ::dot(targetProj.getQuad(), forwardQuad));

        forwardWS.setCross(targetProj, forwardWS);

        float rotMaj = forwardWS(forwardWS.getMajorAxis(targetProj));
        float hingeMaj = hingeWS(hingeWS.getMajorAxis(targetProj));

        if ((rotMaj < 0.0f) != (hingeMaj < 0.0f))
        {
            m_fConeAngle = -m_fConeAngle;
        }

        float dampFactor = m_fMotorDamping * stepInfo.m_fInverseDeltaTime;
        __m128 dampS = _mm_load_ss(&dampFactor);
        hkVecQ damping;
        damping.getQuad() = rb->m_pMotionState.m_kAngularVelocity.getQuad();
        damping.getQuad() = _mm_mul_ps(_mm_shuffle_ps(dampS, dampS, 0), damping.getQuad());

        float strengthFactor = m_fSpringStrength * m_fConeAngle * stepInfo.m_fInverseDeltaTime;
        __m128 strengthS = _mm_load_ss(&strengthFactor);
        forwardWS = hingeWS;
        forwardWS.getQuad() = _mm_mul_ps(_mm_shuffle_ps(strengthS, strengthS, 0), forwardWS.getQuad());

        forwardWS.getQuad() = _mm_sub_ps(forwardWS.getQuad(), damping.getQuad());

        rb->ApplyAngularImpulseToBodies(forwardWS);
    }
}

namespace S00d386c0_N {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; };
extern "C" {
__m128 _mm_load_ss(const float*);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
}
}
typedef S00d386c0_N::__m128 S00d386c0_Quad;

extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}

extern const char str_010ceed4[];
extern const char str_010c41f8[];

struct S00d386c0_TimerCommand
{
    const char* m_kStringBuffer;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};

struct S00d386c0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static S00d386c0_MonitorStream& GetMonitorStream() { return *(S00d386c0_MonitorStream*)TlsGetValue(DAT_0126835c); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    char* GetStreamEnd() { return m_kRayEnd; }
    void setEnd(char* e) { m_kRayEnd = e; }
};

static __forceinline void S00d386c0_timer(const char* name)
{
    S00d386c0_MonitorStream& mStream = S00d386c0_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S00d386c0_TimerCommand* h = (S00d386c0_TimerCommand*)mStream.GetStreamEnd();
        h->m_kStringBuffer = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}

struct S00d386c0_SimdReal
{
    S00d386c0_Quad m_vValue;
    __forceinline S00d386c0_SimdReal(float x) { m_vValue = S00d386c0_N::_mm_load_ss(&x); }
    __forceinline S00d386c0_Quad broadcast() const { return S00d386c0_N::_mm_shuffle_ps(m_vValue, m_vValue, 0); }
};

struct S00d386c0_Transform;

struct __declspec(align(16)) S00d386c0_Vector4
{
    S00d386c0_Quad m_vComponents;

    __forceinline S00d386c0_Vector4() {}
    __forceinline void operator=(const S00d386c0_Vector4& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }

    __forceinline void setAddMul4(const S00d386c0_Vector4& a, const S00d386c0_Vector4& b, const S00d386c0_SimdReal& r)
    {
        m_vComponents = S00d386c0_N::_mm_add_ps(a.m_vComponents, S00d386c0_N::_mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline void _setTransformedPos(const S00d386c0_Transform& t, const S00d386c0_Vector4& b);
};

struct S00d386c0_Matrix3
{
    S00d386c0_Vector4 m_kColumn0;
    S00d386c0_Vector4 m_kColumn1;
    S00d386c0_Vector4 m_kColumn2;
    __forceinline S00d386c0_Matrix3() {}
    S00d386c0_Vector4& getColumn(int x) { return (&m_kColumn0)[x]; }
    const S00d386c0_Vector4& getColumn(int x) const { return (&m_kColumn0)[x]; }
};

struct S00d386c0_Transform
{
    S00d386c0_Matrix3 m_rotation;
    S00d386c0_Vector4 m_vTranslation;

    __forceinline S00d386c0_Transform(const S00d386c0_Transform& t)
    {
        const S00d386c0_Vector4 r0 = t.m_rotation.getColumn(0);
        const S00d386c0_Vector4 r1 = t.m_rotation.getColumn(1);
        const S00d386c0_Vector4 r2 = t.m_rotation.getColumn(2);
        const S00d386c0_Vector4 r3 = t.m_rotation.getColumn(3);
        m_rotation.getColumn(0) = r0;
        m_rotation.getColumn(1) = r1;
        m_rotation.getColumn(2) = r2;
        m_rotation.getColumn(3) = r3;
    }
    const S00d386c0_Matrix3& getRotation() const { return m_rotation; }
    const S00d386c0_Vector4& getTranslation() const { return m_vTranslation; }
};

__forceinline void S00d386c0_Vector4::_setTransformedPos(const S00d386c0_Transform& t, const S00d386c0_Vector4& b)
{
    const S00d386c0_Matrix3& r = t.getRotation();
    S00d386c0_Quad b0 = S00d386c0_N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    S00d386c0_Quad r0 = S00d386c0_N::_mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    S00d386c0_Quad b1 = S00d386c0_N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    S00d386c0_Quad r1 = S00d386c0_N::_mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    S00d386c0_Quad b2 = S00d386c0_N::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    S00d386c0_Quad r2 = S00d386c0_N::_mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = S00d386c0_N::_mm_add_ps(S00d386c0_N::_mm_add_ps(r0, r1), S00d386c0_N::_mm_add_ps(r2, t.getTranslation().m_vComponents));
}

static __forceinline void S00d386c0_transformPoints(const S00d386c0_Transform& t, const S00d386c0_Vector4* vectorsIn, int numVectors, S00d386c0_Vector4* vectorsOut)
{
    S00d386c0_Transform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

template <typename T> struct S00d386c0_PadSpu
{
    T m_kStorage;
    operator T() const { return m_kStorage; }
};

struct S00d386c0_Shape
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

struct S00d386c0_ConvexShape : S00d386c0_Shape
{
    float m_fSphereRadius;
    float getRadius() const { return m_fSphereRadius; }
};

struct S00d386c0_TriangleShape : S00d386c0_ConvexShape
{
    int unk14;
    int unk18;
    int unk1c;
    S00d386c0_Vector4 m_kVertexA;
    S00d386c0_Vector4 m_kVertexB;
    S00d386c0_Vector4 m_kVertexC;
    const S00d386c0_Vector4* GetIndexedVertices() const { return &m_kVertexA; }
};

struct S00d386c0_MultiSphereShape : S00d386c0_Shape
{
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1c;
    S00d386c0_Vector4 m_kSpheres[8];
    const S00d386c0_Vector4* getSpheres() const { return m_kSpheres; }
    int getNumSpheres() const { return m_iSphereCount; }
};

struct S00d386c0_CdBody
{
    const S00d386c0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S00d386c0_CdBody* m_parent;
    const S00d386c0_Shape* getShape() const { return m_pCollisionShape; }
    const S00d386c0_Transform& getTransform() const { return *static_cast<const S00d386c0_Transform*>(m_pMotionState); }
};

struct S00d386c0_CollisionInput
{
    void* m_pCollisionDispatcher;
    int m_collisionQuality;
    S00d386c0_PadSpu<float> m_fScalar;
    float getTolerance() const { return m_fScalar; }
};

struct S00d386c0_ContactPoint
{
    S00d386c0_Vector4 m_vContactPosition;
    S00d386c0_Vector4 m_vSeparatingNormal;

    S00d386c0_Vector4& getPosition() { return m_vContactPosition; }
    void setSeparatingNormal(const S00d386c0_Vector4& normal, float dist)
    {
        m_vSeparatingNormal = normal;
        m_vSeparatingNormal(3) = dist;
    }
};

struct S00d386c0_CdPoint
{
    S00d386c0_ContactPoint m_kPoint;
    const S00d386c0_CdBody& m_pBodyA;
    const S00d386c0_CdBody& m_pBodyB;
    S00d386c0_CdPoint(const S00d386c0_CdBody& a, const S00d386c0_CdBody& b) : m_pBodyA(a), m_pBodyB(b) {}
    S00d386c0_ContactPoint& getContact() { return m_kPoint; }
};

struct S00d386c0_CdPointCollector
{
    virtual ~S00d386c0_CdPointCollector();
    virtual void AddCdPoint(const S00d386c0_CdPoint& event);
};

struct S00d386c0_TriangleCache
{
    float m_invEdgeLen0;
    float m_invEdgeLen1;
    float m_invEdgeLen2;
    float m_fSecondCacheValue;
};

struct S00d386c0_TriangleResult
{
    S00d386c0_Vector4 m_kNearestPoint;
    S00d386c0_PadSpu<float> distance;
};

int __cdecl FUN_00cd7850(const S00d386c0_Vector4& position, const S00d386c0_Vector4* vertices,
    const S00d386c0_TriangleCache& cache, S00d386c0_TriangleResult& result, void* featureOutput);

// @fnv 0x00d386c0
void __cdecl FUN_00d386c0(const S00d386c0_CdBody& bodyA, const S00d386c0_CdBody& bodyB,
    const S00d386c0_CollisionInput& input, S00d386c0_CdPointCollector& collector)
{
    S00d386c0_timer(str_010ceed4);

    const S00d386c0_MultiSphereShape* msA = static_cast<const S00d386c0_MultiSphereShape*>(bodyA.getShape());
    const S00d386c0_TriangleShape* triB = static_cast<const S00d386c0_TriangleShape*>(bodyB.getShape());

    const S00d386c0_Vector4* vertices = triB->GetIndexedVertices();
    S00d386c0_Vector4 triVertices[3];
    S00d386c0_transformPoints(bodyB.getTransform(), vertices, 3, triVertices);

    const S00d386c0_Vector4* localSpheres = msA->getSpheres();
    const int numSpheres = msA->getNumSpheres();
    S00d386c0_Vector4 worldSpheres[8];
    S00d386c0_transformPoints(bodyA.getTransform(), localSpheres, numSpheres, worldSpheres);

    S00d386c0_CdPoint event(bodyA, bodyB);
    S00d386c0_TriangleCache cache;
    {
        {
            const S00d386c0_Vector4* verts = triB->GetIndexedVertices();
            FUN_00cd7160(const_cast<S00d386c0_Vector4*>(verts), &cache);
        }

        for (int i = 0; i < numSpheres; i++)
        {
            const S00d386c0_Vector4& spherePos = worldSpheres[i];
            float radiusSum = localSpheres[i](3) + triB->getRadius();

            S00d386c0_TriangleResult cptr;
            FUN_00cd7850(spherePos, triVertices, cache, cptr, 0);

            float checkDistance = input.getTolerance() + radiusSum;
            if (cptr.distance < checkDistance)
            {
                event.getContact().getPosition().setAddMul4(spherePos, cptr.m_kNearestPoint, triB->getRadius() - cptr.distance);
                event.getContact().setSeparatingNormal(cptr.m_kNearestPoint, cptr.distance - radiusSum);
                collector.AddCdPoint(event);
            }
        }
    }

    S00d386c0_timer(str_010c41f8);
}

struct S_00d3dca0_Fns {
    void* fn0;
    void* fn4;
    void* fn8;
    void* fnC;
    char b10;
    char b11;
};
struct S_00d3dca0_Obj {
    void AddSpawnEntry(S_00d3dca0_Fns* f, int a, int b);
};
__declspec(noinline) void FUN_00d3dbe0(void* storage) {
    S_00d3dca0_Fns* f = static_cast<S_00d3dca0_Fns*>(storage);
    f->fn0 = reinterpret_cast<void*>(static_cast<void (*)()>(&CreateRetObj));
    f->fn4 = reinterpret_cast<void*>(static_cast<void (*)()>(&FUN_00d3d3e0));
    f->fn8 = reinterpret_cast<void*>(static_cast<void (*)()>(&FUN_00d3d8c0));
    f->fnC = reinterpret_cast<void*>(static_cast<void (*)()>(&FUN_00daf8e0));
    f->b10 = 0;
    f->b11 = 0;
}
// @fnv 0x00d3dca0
void FUN_00d3dca0(S_00d3dca0_Obj* o)
{
    S_00d3dca0_Fns f;
    f.b10 = 0;
    f.b11 = 0;
    FUN_00d3dc10(&f);
    o->AddSpawnEntry(&f, 3, 1);
    f.b10 = 0;
    f.b11 = 0;
    FUN_00d3dbe0(&f);
    o->AddSpawnEntry(&f, 1, 3);
}
