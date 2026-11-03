
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

// @fnv 0x00d2be30
void FUN_00d2be30::SetFile(const char* acPath, const char* acMode)
{
    m_8 = fopen(acPath, acMode);
}

extern "C" void __stdcall FUN_00d2f980(int);
extern int DAT_010ce930;

struct FUN_00d2f220_class
{
    int* p;
    int __thiscall InitializeWithGlobal(int a);
};

// @fnv 0x00d2f220
int __thiscall FUN_00d2f220_class::InitializeWithGlobal(int aiValue)
{
    FUN_00d2f980(aiValue);
    p = &DAT_010ce930;
    return (int)this;
}

void __cdecl FUN_00d365d0();
void __cdecl FUN_00da6fd0(int);

// @fnv 0x00d367b0
void __cdecl FUN_00d367b0(int pObject)
{
    FUN_00da6fd0(pObject);
    *(void (**)(void))(pObject + 0x2c) = &FUN_00d365d0;
}

extern "C" void __cdecl FUN_00d36b70();
extern "C" void __cdecl FUN_00d34790();
extern "C" void __cdecl QueryClosestPoints();
extern "C" void __cdecl FUN_00d34810();

// Fills the four function pointers at p[0..3] and sets the bytes at offsets 0x10 and 0x11 to 0 and 1.
// @fnv 0x00d36bb0
void __cdecl FUN_00d36bb0(void** p)
{
    p[0] = (void*)&FUN_00d36b70;
    p[1] = (void*)&FUN_00d34790;
    p[2] = (void*)&QueryClosestPoints;
    p[3] = (void*)&FUN_00d34810;
    ((char*)p)[0x10] = 0;
    ((char*)p)[0x11] = 1;
}

extern "C" void __cdecl FUN_00d36be0();
extern "C" void __cdecl FUN_00d43dc0();
extern "C" void __cdecl GetClosestPointsShapeCollection();
extern "C" void __cdecl FUN_00d43b90();

// Writes four function pointers into the object at offsets 0, 4, 8 and 12, then sets the bytes at offsets 16 and 17 to 1.
// @fnv 0x00d36c30
void __cdecl FUN_00d36c30(void* apObject)
{
    *(void**)apObject = &FUN_00d36be0;
    *(void**)((char*)apObject + 4) = &FUN_00d43dc0;
    *(void**)((char*)apObject + 8) = &GetClosestPointsShapeCollection;
    *(void**)((char*)apObject + 12) = &FUN_00d43b90;
    *(unsigned char*)((char*)apObject + 16) = 1;
    *(unsigned char*)((char*)apObject + 17) = 1;
}

void CreateRetObj();
void FUN_00d3d3e0();
void FUN_00d3d8c0();
void FUN_00daf8e0();

// Fills the first four pointer slots of p with function addresses and clears the two bytes at offsets 0x10 and 0x11.
// @fnv 0x00d3dbe0
void __cdecl FUN_00d3dbe0(void* apObject)
{
    ((void**)apObject)[0] = (void*)&CreateRetObj;
    ((void**)apObject)[1] = (void*)&FUN_00d3d3e0;
    ((void**)apObject)[2] = (void*)&FUN_00d3d8c0;
    ((void**)apObject)[3] = (void*)&FUN_00daf8e0;
    ((unsigned char*)apObject)[0x10] = 0;
    ((unsigned char*)apObject)[0x11] = 0;
}

void __cdecl CreateTargetAgent(void);
void __cdecl QueryD3DCollector(void);
void __cdecl FUN_00d3e110(void);
void __cdecl FUN_00d3ac80(void);

// Fills the first four pointer slots of p with four function pointers and sets the bytes at offsets 0x10 and 0x11 to 1 and 0.
// @fnv 0x00d3dc10
void FUN_00d3dc10(void* apObject)
{
    ((void**)apObject)[0] = (void*)CreateTargetAgent;
    ((void**)apObject)[1] = (void*)QueryD3DCollector;
    ((void**)apObject)[2] = (void*)FUN_00d3e110;
    ((void**)apObject)[3] = (void*)FUN_00d3ac80;
    ((unsigned char*)apObject)[0x10] = 1;
    ((unsigned char*)apObject)[0x11] = 0;
}

namespace fnv_00d3fce0 {
extern "C" void __cdecl FUN_00d3f620();
extern "C" void __cdecl FUN_00d3f6a0();
extern "C" void __cdecl FUN_00d3fb20();
extern "C" void __cdecl FUN_00daf8e0();

// Stores four function pointers (FUN_00d3f620, FUN_00d3f6a0, FUN_00d3fb20, FUN_00daf8e0) into the first four slots of the object at p.
// @fnv 0x00d3fce0
void __cdecl FUN_00d3fce0(void* apObject)
{
    void** a = (void**)apObject;
    a[0] = (void*)FUN_00d3f620;
    a[1] = (void*)FUN_00d3f6a0;
    a[2] = (void*)FUN_00d3fb20;
    a[3] = (void*)FUN_00daf8e0;
}
}  // namespace fnv_00d3fce0

struct FUN_00db0920 {
    void Init();
};

// @fnv 0x00d3fdf0
void* __cdecl InitAndGetOffset(void* apUnused1, void* apUnused2, void* apObject)
{
    if (apObject)
        ((FUN_00db0920*)apObject)->Init();
    return (char*)apObject + 0x40;
}

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
// @fnv 0x00d2dc70
void __cdecl FUN_00d2dc70(Agent* pAgent)
{
    CollisionAgentFunctionTable f;
    f.a = (void*)&FUN_00d2e680;
    f.b = (void*)&FUN_00d2e970;
    f.c = (void*)&FUN_00d2e9b0;
    f.d = (void*)&FUN_00d2daf0;
    f.e = 1;
    f.f = 1;
    pAgent->FUN_00cfbbe0(&f, 10, 18);
    f.a = (void*)&FUN_00d2df50;
    f.b = (void*)&FUN_00d312f0;
    f.c = (void*)&FUN_00d31110;
    f.d = (void*)&FUN_00d2f0d0;
    f.e = 0;
    f.f = 1;
    pAgent->FUN_00cfbbe0(&f, 18, 10);
    f.a = (void*)&CreateAgentForBodyPair;
    f.b = (void*)&FUN_00d312f0;
    f.c = (void*)&FUN_00d31110;
    f.d = (void*)&FUN_00d2f0d0;
    f.e = 0;
    f.f = 1;
    pAgent->FUN_00cfbbe0(&f, 10, 10);
}

// @fnv 0x00d275a0
void ReplaceEntry(int pList, int pOldEntry, int pNewEntry, unsigned short usValue)
{
    int iVar1 = *(int*)(pList + 0x10);
    int pCached = *(int*)(pList + 0x30);
    if (iVar1 == 0)
    {
        if (pCached != 0)
        {
            *(int*)(pCached + 0xc) = pNewEntry;
            *(unsigned short*)(pCached + 0x10) = usValue;
        }
        return;
    }
    if (iVar1 == pOldEntry)
    {
        *(int*)(pList + 0x10) = pNewEntry;
        if (pCached != 0)
        {
            *(int*)(pCached + 0xc) = pNewEntry;
            *(unsigned short*)(pCached + 0x10) = usValue;
        }
        return;
    }
    int pCur = *(int*)(iVar1 + 0x14);
    while (pCur != pOldEntry)
    {
        iVar1 = pCur;
        pCur = *(int*)(pCur + 0x14);
    }
    *(int*)(iVar1 + 0x14) = pNewEntry;
    *(unsigned short*)(iVar1 + 0x12) = usValue;
}

struct FUN_00d27f50_Obj {
    void __thiscall Insert(int a, int b, int c);
    void __thiscall FUN_00d27f50(int param_1, int param_2);
};

// @fnv 0x00d27f50
void __thiscall FUN_00d27f50_Obj::FUN_00d27f50(int aFirst, int aSecond) {
    this->Insert(aFirst, aSecond, 1);
}

struct FUN_00d27f70 {
    int** m_ppIndices;
    int m_iIndexCount;

    FUN_00d27f70(int** indices, int numIndices);
};

// Stores the index array and its count, then fills the array with -1.
// @fnv 0x00d27f70
FUN_00d27f70::FUN_00d27f70(int** indices, int numIndices)
{
    m_ppIndices = indices;
    m_iIndexCount = numIndices;
    for (int i = 0; i < numIndices; i++)
        (*m_ppIndices)[i] = -1;
}

struct FUN_00d27ff0_class {int** values; void __thiscall UnionFindMerge(int first, int second);};
// @fnv 0x00d27ff0
void FUN_00d27ff0_class::UnionFindMerge(int first, int second)
{
    int* data = *values;
    int value = data[first];
    if (first < second) {
        ((volatile int*)data)[first] += data[second];
        (*values)[second] = first;
    } else {
        data[second] += value;
        (*values)[first] = second;
    }
}

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

// @fnv 0x00d28030
void D28030UnionFind::Union(int aiNodeA, int aiNodeB)
{
    int iRootA = _findRootOfNode(aiNodeA);
    int iRootB = _findRootOfNode(aiNodeB);
    if (iRootA != iRootB) {
        int iSizeA = m_pParentArray[iRootA];
        if (iRootA < iRootB) {
            m_pParentArray[iRootA] += m_pParentArray[iRootB];
            m_pParentArray[iRootB] = iRootA;
        } else {
            m_pParentArray[iRootB] += iSizeA;
            m_pParentArray[iRootA] = iRootB;
        }
    }
}

struct LinkedIndexArray { int** entries; int count; void FUN_00d280e0(); };
// For each non-negative entry, follows the chain of indices in entries until a negative value is reached, then advances to the next entry.
// @fnv 0x00d280e0
void LinkedIndexArray::FUN_00d280e0(){
int* values=*entries; int* current=*entries; int* end=current+count;while(current!=end){if(*current>=0){while(values[*current]>=0){*current=values[*current];values=*entries;}}++current;}
}

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct IndexBuffer { int* data; int size; unsigned capacityFlags; };
struct IndexStorage { int* data; };
struct AllocationManager { int unk00; int unk04; int unk08; int unk0C; void* allocator; };
AllocationManager* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void*, IndexBuffer*, int);
struct IndexRemapper { IndexStorage* entries; int length; void FUN_00d280e0(); void RemapIndices(IndexBuffer*); };
// @fnv 0x00d28120
void IndexRemapper::RemapIndices(IndexBuffer* output) {
 FUN_00d280e0(); int nextIndex=0;
 for(int i=0;i<length;++i) {
  int* values=entries->data; int value=values[i];
  if(value<0) {
   value=-value;
   AllocationManager* manager=FUN_00c85750();
   if(output->size == (output->capacityFlags & 0x3fffffffU)) ResizeAudioStream(manager->allocator,output,4);
   int* slot = output->data + output->size; __assume(slot != 0); new (slot) int(value);
   ++output->size; entries->data[i]=nextIndex++;
  } else { values[i]=values[value]; }
 }
}

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

// Sizes out to the key count, builds per-key offsets from counts, then fills out with the index of each key occurrence.
// @fnv 0x00d283e0
void KeyArrayStub::BuildKeyOffsets(IntArrayStub* counts, IntArrayStub* out)
{
    int size = m_iElementCount;
    out->setSizeWith(GetMemCtx()->heap(), size);
    int n = counts->m_iElementCount;
    if (n > 0)
    {
        int c = n;
        int* offsets = GetMemCtx()->temp().bufAllocInts(c);
        int capFlags = c ? c : 0x80000000;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            offsets[i] = sum;
            sum += counts->m_data[i];
        }
        int* outData = out->m_data;
        int* keys = m_keys->m_data;
        for (int i = 0; i < m_iElementCount; i++)
        {
            int iKey = keys[i];
            int idx = offsets[iKey];
            offsets[iKey] = idx + 1;
            outData[idx] = i;
        }
        hkMemAllocStub& a = GetMemCtx()->temp();
        if ((capFlags & 0x80000000) == 0)
            a.ReturnMemory(offsets, (capFlags & 0x3fffffff) * 4);
    }
}

namespace fnv_00d2f240 {
struct D2F240Allocator {
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct D2F240MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2F240Allocator* m_pStreamAllocator;

    D2F240Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D2F240MemoryRouter& __cdecl FUN_00c85750();

struct D2F240Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_iType;
};

struct D2F240Body {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    D2F240Shape* m_pkShape;
};

struct D2F240CdBody {
    D2F240Body* m_pkBody;
};

class D2F240Agent {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    D2F240Agent(void* pvMgr) throw();
    virtual ~D2F240Agent();

    static void* operator new(unsigned int uiSize) {
        void* p = FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
        static_cast<D2F240Agent*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

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
};

class D2F240SymmetricAgent : public D2F240Agent {
public:
    D2F240SymmetricAgent(void* pvMgr) : D2F240Agent(pvMgr) {}
    virtual ~D2F240SymmetricAgent();
};

// Compares the shape types of two bodies and allocates a D2F240Agent if A's type is lower, otherwise a D2F240SymmetricAgent.
// @fnv 0x00d2f240
D2F240Agent* CreateAgentForBodyPair(const D2F240CdBody& kBodyA, const D2F240CdBody& kBodyB, const void* pvInput, void* pvMgr) {
    if (kBodyA.m_pkBody->m_pkShape->m_iType < kBodyB.m_pkBody->m_pkShape->m_iType)
        return new D2F240Agent(pvMgr);
    return new D2F240SymmetricAgent(pvMgr);
}
}  // namespace fnv_00d2f240

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

// Registers three collision agent function tables with the dispatcher for type pairs (10,-1), (-1,10) and (10,10).
// @fnv 0x00d2f2c0
void __cdecl FUN_00d2f2c0(D2F2C0Dispatcher* dispatcher)
{
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = FUN_00d2fa00;
        f.m_pQueryPenetrationsFunc = FUN_00d2e970;
        f.m_getClosestPointsFunc = FUN_00d2e9b0;
        f.m_pLinearCastFunc = FUN_00d2daf0;
        f.m_bIsFlipped = true;
        f.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(f, 10, -1);
    }
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = FUN_00d2f9d0;
        f.m_pQueryPenetrationsFunc = FUN_00d312f0;
        f.m_getClosestPointsFunc = FUN_00d31110;
        f.m_pLinearCastFunc = FUN_00d2f0d0;
        f.m_bIsFlipped = false;
        f.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(f, -1, 10);
    }
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = CreateAgentForBodyPair;
        f.m_pQueryPenetrationsFunc = FUN_00d312f0;
        f.m_getClosestPointsFunc = FUN_00d31110;
        f.m_pLinearCastFunc = FUN_00d2f0d0;
        f.m_bIsFlipped = false;
        f.m_bIsPredictive = true;
        dispatcher->registerCollisionAgent(f, 10, 10);
    }
}

struct CallTarget_00d2f760 { int FUN_00d2f760(int, int, int, int); };
struct SearchObject {
    int FUN_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2f3d0
int SearchObject::FUN_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiResult = (unsigned int)((CallTarget_00d2f760*)this)->FUN_00d2f760((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)uiResult;
}

namespace fnv_00d2f430 {
struct FnvCpu_FUN_00d2f430_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d2f430_CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d2f430_CpuAllocator* allocator;
};
FnvCpu_FUN_00d2f430_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d2f430_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void DestroyArray();
    FnvCpu_FUN_00d2f430_CpuObject* FUN_00d2f430(unsigned int flags);
};
// @fnv 0x00d2f430
FnvCpu_FUN_00d2f430_CpuObject* FnvCpu_FUN_00d2f430_CpuObject::FUN_00d2f430(unsigned int flags)
{
    DestroyArray();
    if (flags & 1) {
        FnvCpu_FUN_00d2f430_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d2f430

struct FnvCpu_FUN_00d31730_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d31730_CpuObject {
    void FUN_00d315d0(void*, void*, unsigned int, FnvCpu_FUN_00d31730_CpuCallData*);
    void FUN_00d31730(void*, void*, unsigned int, unsigned int);
};
// Builds a call data struct from the arguments and DAT globals, then forwards it to FUN_00d315d0 with second and first swapped.
// @fnv 0x00d31730
void FnvCpu_FUN_00d31730_CpuObject::FUN_00d31730(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d31730_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d315d0(second, first, third, &data);
}

namespace fnv_00d327e0 {
extern int DAT_010ceaa8;
extern int DAT_0102e388;

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d327e0_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    void* m_pData;
    int m_10;
    int m_uiItemCount;

    FUN_00d327e0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Resets the object's vtable and data, frees the data array via the audio allocator, and frees the object itself when acFlags bit 0 is set.
// @fnv 0x00d327e0
FUN_00d327e0_cls* FUN_00d327e0_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010ceaa8;
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    m_10 = 0;
    int count = m_uiItemCount;
    if (((unsigned int)count & 0x80000000u) == 0) {
        pAllocator->FreeArray(m_pData, (count & 0x3fffffff) * 2);
    }
    m_pData = 0;
    m_uiItemCount = 0x80000000;
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1) {
        AudioHolder* pHolder2 = FUN_00c85750();
        AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
        pAllocator2->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d327e0

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

// @fnv 0x00d36b20
FUN_00d36b20_Class* FUN_00d36b20_Class::FUN_00d36b20(int aiUnused1, int aiUnused2, int* piValue, int aiValue) {
    this->unk06 = 1;
    this->unk08 = aiValue;
    this->unk00 = &DAT_010ced34;

    int* data = &this->unk10;
    data[0] = 0;
    data[1] = 0;
    data[2] = 0x80000000;

    this->unk0C = *piValue;
    InitBlockPool(data);
    return this;
}

namespace fnv_00d36be0 {
// FUN_00d36be0 : cdecl factory. Allocates a 0x1c byte block through the global
// allocator holder, stamps the 16-bit size at +4, runs the out-of-line block
// initializer with the arguments in a2, a1, a3, a4 order, stores the vtable
// pointer and returns the block.

extern "C" char DAT_010ced70[];

struct FUN_00d36be0_cls
{
    void* unk00;
    unsigned short m_04;
    void __thiscall FUN_00d36b20(int a, int b, int c, int d);
};

struct Allocator
{
    virtual void* v0();
    virtual void* v1(unsigned int nSize);
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* m_pAllocator;
};

extern "C" Holder* __cdecl FUN_00c85750();

// @fnv 0x00d36be0
void* __cdecl FUN_00d36be0(int a1, int a2, int a3, int a4)
{
    Holder* pHolder = FUN_00c85750();
    Allocator* pAlloc = pHolder->m_pAllocator;
    FUN_00d36be0_cls* pBlock = (FUN_00d36be0_cls*)pAlloc->v1(0x1c);
    pBlock->m_04 = 0x1c;
    pBlock->FUN_00d36b20(a2, a1, a3, a4);
    pBlock->unk00 = DAT_010ced70;
    return pBlock;
}
}  // namespace fnv_00d36be0

struct FUN_00d36cc0_Obj {
    void __thiscall FUN_00d368c0(int a1, int a2, int a3, int a4);
    void __thiscall FUN_00d36cc0(int param_1, int param_2, int param_3, int param_4);
};

// @fnv 0x00d36cc0
void __thiscall FUN_00d36cc0_Obj::FUN_00d36cc0(int param_1, int param_2, int param_3, int param_4) {
    this->FUN_00d368c0(param_2, param_1, param_3, param_4);
}

struct FnvCpu_FUN_00d36ce0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d36ce0_CpuObject {
    void FUN_00d36940(void*, void*, unsigned int, FnvCpu_FUN_00d36ce0_CpuCallData*);
    void FUN_00d36ce0(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data struct from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first and third to FUN_00d36940.
// @fnv 0x00d36ce0
void FnvCpu_FUN_00d36ce0_CpuObject::FUN_00d36ce0(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d36ce0_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d36940(second, first, third, &data);
}

namespace fnv_00d36f50 {
struct FUN_00d36f50_Obj;

struct FUN_00d36f50_allocator
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(FUN_00d36f50_Obj* object, unsigned int value);
    virtual void vf0C();
    virtual void Free(void* data, unsigned int size);
};

struct FUN_00d36f50_manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d36f50_allocator* unk10;
};

struct FUN_00d36f50_Obj
{
    void* unk00;
    unsigned short unk04;
    int unk08;
    int unk0C;
    void* unk10;
    int unk14;
    int unk18;

    FUN_00d36f50_Obj* __thiscall FUN_00d36f50(unsigned char flag);
};

extern int DAT_0102e388;
void* __cdecl FUN_00c85750();

// @fnv 0x00d36f50
FUN_00d36f50_Obj* __thiscall FUN_00d36f50_Obj::FUN_00d36f50(unsigned char flag)
{
    FUN_00d36f50_manager* manager = (FUN_00d36f50_manager*)FUN_00c85750();
    FUN_00d36f50_allocator* allocator = manager->unk10;
    int capacity = unk18;

    unk14 = 0;
    if ((capacity & 0x80000000) == 0)
        allocator->Free(unk10, (unsigned int)(capacity & 0x3fffffff) * 4);

    unk10 = 0;
    unk18 = 0x80000000;
    unk00 = &DAT_0102e388;

    if (flag & 1)
    {
        manager = (FUN_00d36f50_manager*)FUN_00c85750();
        allocator = manager->unk10;
        allocator->vf08(this, unk04);
    }

    return this;
}
}  // namespace fnv_00d36f50

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

// Constructs a D37B90Collector with iFilter and runs FUN_00d37010 with pkB, pkA, pkInput and the collector.
// @fnv 0x00d37b90
void D37B90Agent::FUN_00d37b90(void* pkA, void* pkB, void* pkInput, int iFilter)
{
    D37B90Collector kCollector(iFilter);
    FUN_00d37010(pkB, pkA, pkInput, &kCollector);
}

namespace fnv_00d37da0 {
struct S_00d37da0_Allocator {
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00d37da0_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d37da0_Allocator* m_pStreamAllocator;
    S_00d37da0_Allocator& heap() { return *m_pStreamAllocator; }
};

S_00d37da0_Router* FUN_00c85750();

struct S_00d37da0_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d37da0_RefObj() { m_sReferenceCount = 1; }
    virtual ~S_00d37da0_RefObj() throw() {}
    void* operator new(unsigned int nbytes)
    {
        S_00d37da0_RefObj* b = static_cast<S_00d37da0_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*) {}
};

struct S_00d37da0_Agent : S_00d37da0_RefObj {
    void* m_pContactManager;
    S_00d37da0_Agent(void* mgr) : m_pContactManager(mgr) {}
    virtual void getPenetrations();
};

struct S_00d37da0_Shape {
    int unk0[8];
};

struct S_00d37da0_CdBody {
    char* m_pCollisionShape;
};

struct S_00d37da0_Plane {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

void FUN_00cd7160(const void* verts, S_00d37da0_Plane* out) throw();

struct S_00d37da0_TriAgent : S_00d37da0_Agent {
    S_00d37da0_Plane m_kTriangleNormal;
    unsigned short m_ids[8];
    virtual void getPenetrations();
    __forceinline S_00d37da0_TriAgent(const S_00d37da0_CdBody& bodyA, void* mgr) : S_00d37da0_Agent(mgr)
    {
        for (int i = 0; i < 8; i++)
            m_ids[i] = 0xffff;
        FUN_00cd7160(bodyA.m_pCollisionShape + 0x20, &m_kTriangleNormal);
    }
};

// Allocates and constructs a TriAgent from bodyA and mgr, returning it as an Agent pointer.
// @fnv 0x00d37da0
S_00d37da0_Agent* CreateTriAgent(const void* a1, const S_00d37da0_CdBody& bodyA, const void* a3, void* mgr)
{
    return new S_00d37da0_TriAgent(bodyA, mgr);
}
}  // namespace fnv_00d37da0

void __cdecl ReleaseHandles(int a1, int a2, int a3, int a4);

// @fnv 0x00d39130
void __cdecl FUN_00d39130(int a1, int a2, int a3, int a4, int a5)
{
    ReleaseHandles(a1, a2, a3, a4);
}

namespace fnv_00d398c0 {
extern "C" void* __cdecl FUN_00c85750();
extern "C" void __cdecl ComputeInverseLengths(const void*, void*);

struct FUN_00d398c0_Vtable
{
    virtual void Method();
};

struct FUN_00d398c0_Allocator
{
    virtual void Method();
    virtual void* Allocate(unsigned int size);
};

struct FUN_00d398c0_Factory
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FUN_00d398c0_Allocator* unk10;
};

struct FUN_00d398c0_Object
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short unk10;
    unsigned short unk12;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char unk1a;
    char unk1b;
    char unk1c;
    char unk1d;
    char unk1e;
    char unk1f;
    char unk20;
    char unk21;
    char unk22;
    char unk23;
    char unk24;
    char unk25;
    char unk26;
    char unk27;
};

extern FUN_00d398c0_Vtable DAT_010ceefc;

// @fnv 0x00d398c0
extern "C" void* __cdecl CreateObjectFromFactory(
    int aiUnused,
    int* param_2,
    int aiUnused2,
    int aiValue)
{
    FUN_00d398c0_Factory* factory =
        reinterpret_cast<FUN_00d398c0_Factory*>(FUN_00c85750());

    FUN_00d398c0_Object* object =
        reinterpret_cast<FUN_00d398c0_Object*>(
            factory->unk10->Allocate(0x28));

    object->unk00 = reinterpret_cast<void*>(&DAT_010ceefc);
    object->unk04 = 0x28;
    object->unk06 = 1;
    object->unk08 = aiValue;
    object->unk0c = 0xffff;
    object->unk0e = 0xffff;
    object->unk10 = 0xffff;

    ComputeInverseLengths(
        reinterpret_cast<const void*>(
            static_cast<unsigned int>(*reinterpret_cast<int*>(param_2)) + 0x20),
        reinterpret_cast<void*>(&object->unk14));

    return object;
}
}  // namespace fnv_00d398c0

namespace fnv_00d3b380 {
extern unsigned int DAT_010cef94;

struct FUN_00d3b380_object
{
    unsigned int* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short unk10;
};

struct FUN_00d3b380_allocator
{
    virtual void Unused()
    {
    }

    virtual FUN_00d3b380_object* Allocate(unsigned int size);
};

struct FUN_00d3b380_singleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d3b380_allocator* unk10;
};

extern "C" FUN_00d3b380_singleton* __cdecl FUN_00c85750();

// Allocates a 0x14-byte object from the singleton's allocator and initializes its fields, storing param_4 and a global pointer.
// @fnv 0x00d3b380
void __cdecl FUN_00d3b380(int aiUnused1, int aiUnused2, int aiUnused3,
                         unsigned int auiValue)
{
    FUN_00d3b380_singleton* singleton = FUN_00c85750();
    FUN_00d3b380_object* object = singleton->unk10->Allocate(0x14);

    object->unk04 = 0x14;
    object->unk06 = 1;
    object->unk08 = auiValue;
    object->unk00 = &DAT_010cef94;
    object->unk0c = 0xffff;
    object->unk0e = 0xffff;
    object->unk10 = 0xffff;
}
}  // namespace fnv_00d3b380

struct FnvCpu_FUN_00d3f480_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d3f480_CpuObject {
    void FUN_00d3e850(void*, void*, unsigned int, FnvCpu_FUN_00d3f480_CpuCallData*);
    void FUN_00d3f480(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data record from the fourth argument, a global float and a global byte, then forwards it with the other arguments to FUN_00d3e850.
// @fnv 0x00d3f480
void FnvCpu_FUN_00d3f480_CpuObject::FUN_00d3f480(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d3f480_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d3e850(second, first, third, &data);
}

extern float DAT_0104da48;

struct S_00d3f4c0_Obj {
    virtual void vfn0();
    float unk04;
    int unk08;
    S_00d3f4c0_Obj(int a) : unk04(DAT_0104da48), unk08(a) {}
};

void* __cdecl FUN_00d3ebe0(void* a, void* b, void* c, S_00d3f4c0_Obj* o);

// Constructs an S_00d3f4c0_Obj from d and DAT_0104da48, then calls FUN_00d3ebe0 with b, a, c and the object.
// @fnv 0x00d3f4c0
void* __cdecl FUN_00d3f4c0(void* a, void* b, void* c, int iValue)
{
    S_00d3f4c0_Obj obj(iValue);
    return FUN_00d3ebe0(b, a, c, &obj);
}

namespace fnv_00d3f620 {
struct S_00d3f620_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00d3f620_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00d3f620_Alloc* unk10;
    S_00d3f620_Alloc& heap() { return *unk10; }
};
S_00d3f620_Router* FUN_00c85750() throw();
struct S_00d3f620_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d3f620_RefObj() throw() { m_sReferenceCount = 1; }
    virtual ~S_00d3f620_RefObj() throw();
    void* operator new(unsigned int n) {
        S_00d3f620_RefObj* b = static_cast<S_00d3f620_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
};
struct S_00d3f620_Mid : S_00d3f620_RefObj {
    int unk08;
    S_00d3f620_Mid(int a) throw() { unk08 = a; }
};
struct S_00d3f620_Obj : S_00d3f620_Mid {
    unsigned short unk0c;
    S_00d3f620_Obj(int a) throw() : S_00d3f620_Mid(a) { unk0c = 0xffff; }
    virtual ~S_00d3f620_Obj() throw();
};
// Allocates and constructs an S_00d3f620_Obj with a4, returning the new object.
// @fnv 0x00d3f620
S_00d3f620_Obj* __cdecl FUN_00d3f620(int a1, int a2, int a3, int aiValue) {
    return new S_00d3f620_Obj(aiValue);
}
}  // namespace fnv_00d3f620

void __cdecl FUN_00d3fce0(CollisionAgentFunctionTable*);
// @fnv 0x00d3fd00
void __cdecl FUN_00d3fd00(Agent* agent) {
    CollisionAgentFunctionTable funcs;
    funcs.e = 0;
    funcs.f = 0;
    FUN_00d3fce0(&funcs);
    agent->FUN_00cfbbe0(&funcs, 1, 1);
}

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

// @fnv 0x00d3fd60
void* __cdecl RemoveEntryByKey(FUN_00d3fd60_cls_Ref* ref, FUN_00d3fd60_cls* table, unsigned short key)
{
    int count = table->m_uiItemCount;
    if (count > 0)
    {
        int i = 0;
        FUN_00d3fd60_cls_Entry* e = (FUN_00d3fd60_cls_Entry*)((char*)table + 2);
        do
        {
            if (e->m_key == key)
            {
                table->RemoveEntry(i);
                ref->m_iObjectReferenceCount--;
                return ref;
            }
            i++;
            e++;
        } while (i < count);
        return (void*)i;
    }
    return 0;
}

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

// @fnv 0x00d3fda0
int __cdecl FindOrClaimEntry(int unused, FUN_00d3fda0_table* table, unsigned short value) {
    int i = 0;
    int n = table->count;
    if (n > 0) {
        FUN_00d3fda0_entry* e = &table->entries[0];
        do {
            if (e->key00 == 0xffff) {
                table->entries[i].key00 = value;
                goto found;
            }
            ++i;
            ++e;
        } while (i < n);
    }
found:
    return i;
}

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

// @fnv 0x00d3fe10
D3FE10Entry* __cdecl ResetEntryAgents(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, void* pkInfo)
{
    for (int i = 0; i < pkEntry->m_numAgents; i++) {
        unsigned short id = pkEntry->m_pAgents[i].m_iOwnerObjectOffset;
        if (id != 0xffff)
            pkManager->ResetAgent(id, pkInfo);
    }
    pkEntry->m_numAgents = 0;
    pkHeader->m_iNumberOfEntries = 0;
    return pkEntry + 1;
}

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

// Walks the parent array to the root of element i, then path-compresses the chain so every visited element points at the root, and returns the last element index.
// @fnv 0x00d27fb0
int hkUnionFindD27::FindRoot(int aiIndex)
{
    int root = aiIndex;
    while (m_pParentArray[root] >= 0)
        root = m_pParentArray[root];

    while (m_pParentArray[aiIndex] >= 0) {
        int j = m_pParentArray[aiIndex];
        m_pParentArray[aiIndex] = root;
        aiIndex = j;
    }
    return aiIndex;
}

extern int DAT_010ce81c;
struct SpawnedBuf { void* m_iWordAt00; unsigned char m_iWordAt04; int m_8; };
struct Wrapper {
    void ForwardToFunction(int,int,int,SpawnedBuf*);
    void FUN_00d37bd0(int a,int b,int c,int d);
};
// Builds a SpawnedBuf pointing at DAT_010ce81c with the given value and passes it to ForwardToFunction along with b, a and c.
// @fnv 0x00d37bd0
void Wrapper::FUN_00d37bd0(int a,int b,int c,int d) {
    SpawnedBuf s;
    s.m_8=d; s.m_iWordAt04=0; s.m_iWordAt00=&DAT_010ce81c;
    ForwardToFunction(b,a,c,&s);
}

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

// Registers two D3D agent function sets with the dispatcher: one initialized by InitFuncsA with (3,1) and one by InitFuncsB with (1,3).
// @fnv 0x00d3dc40
void __cdecl RegisterD3DAgents(DispatcherD3D* pkDispatcher)
{
    {
        AgentFuncsD3D kFuncs;
        InitFuncsA(&kFuncs);
        pkDispatcher->RegisterAgent(&kFuncs, 3, 1);
    }
    {
        AgentFuncsD3D kFuncs;
        InitFuncsB(&kFuncs);
        pkDispatcher->RegisterAgent(&kFuncs, 1, 3);
    }
}

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

// Removes the modifier of the given type from the instance's chain, updates internal child result and stats, then frees the modifier.
// @fnv 0x00d27690
void __cdecl FUN_00d27690(D27690_Instance* instance, D27690_Owner* owner, unsigned int modifierType)
{
    owner->checkReadOnly();

    D27690_Modifier* curr = instance->m_pConstraintModifier;
    if (!curr)
        return;

    D27690_Internal* internal = instance->m_pConstraintInternal;

    if (curr->m_type == modifierType)
    {
        D27690_Atom* child = curr->m_pChildAtom;
        if (internal)
        {
            internal->m_kBridgeAtoms = child;
            internal->m_childResult = curr->m_childResult;
        }
        instance->m_pConstraintModifier = (child->m_type >= 0x17) ? (D27690_Modifier*)child : 0;
    }
    else
    {
        D27690_Modifier* prev = curr;
        for (D27690_Atom* child = curr->m_pChildAtom; child->m_type >= 0x17; child = curr->m_pChildAtom)
        {
            curr = (D27690_Modifier*)child;
            if (curr->m_type == modifierType)
            {
                prev->m_pChildAtom = curr->m_pChildAtom;
                prev->m_childResult = curr->m_childResult;
                goto FOUND;
            }
            prev = curr;
        }
        return;
    }

FOUND:
    if (internal)
    {
        D27690_ConstraintInfo info;
        info.unk00 = 0;
        info.unk04 = 0;
        info.unk08 = 0;
        info.unk0C = 0;
        unsigned char flags = 0;

        curr->FUN_00d22090(&info, &flags);

        flags &= (instance->m_pEntityA->unkD2 | instance->m_pEntityB->unkD2);
        unsigned short delta = (&DAT_010cb7a8)[flags & 7];
        owner->m_iElementCount += delta;
        instance->m_pConstraintInternal->m_stats += delta;

        owner->FUN_00cb7480(internal->m_pHavokConstraint, &info);
    }

    int size = curr->m_usModifierAtomSize;
    AllocationManager* mgr = FUN_00c85750();
    ((D27690_Allocator*)mgr->allocator)->ReleaseBlock(curr, size);
}

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
// Constructs the object by forwarding a and b to the Base constructor and setting m_8 to 6.
// @fnv 0x00d21930
FUN_00d21930::FUN_00d21930(int a, int b) : Base(a, b) { m_8 = 6; }

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
// Walks both linked lists to their tails, stores each tail and the head's unk04 in the object, and sets unk04 to 1.
// @fnv 0x00d219e0
void __thiscall FUN_00d219e0_cls::SetLists(FUN_00d219e0_node* pFirstList, FUN_00d219e0_node* pSecondList)
{
    FUN_00d219e0_node* pTail = pFirstList;
    while (pTail->unk0C)
        pTail = pTail->unk0C;
    unk08 = pTail;
    unk0C = pFirstList->unk04;
    pTail = pSecondList;
    while (pTail->unk0C)
        pTail = pTail->unk0C;
    unk10 = pTail;
    unk14 = pSecondList->unk04;
    unk04 = 1;
}

extern int DAT_0101e594;
struct VtblStub_0101e594 { void* m_ppVirtualMethodTable; };
extern "C" void __cdecl FormHeap_Free(VtblStub_0101e594*);
struct FUN_00d26210
{
    void* m_ppVirtualMethodTable;
    FUN_00d26210(char construct);
};
// @fnv 0x00d26210
FUN_00d26210::FUN_00d26210(char construct)
{
    m_ppVirtualMethodTable = &DAT_0101e594;
    if (construct & 1)
        FormHeap_Free((VtblStub_0101e594*)this);
}

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

// Scans both nodes' entry arrays for an entry whose XOR-linked node equals the other node and returns that entry's value, else 0.
// @fnv 0x00d27610
void* __cdecl FindSharedEntryValue(PairNode* pNodeA, PairNode* pNodeB)
{
	PairNode* pNodePair[2];
	pNodePair[0] = pNodeA;
	pNodePair[1] = pNodeB;
	for (int i = 0; i < 2; i++)
	{
		PairNode* self = pNodePair[i];
		PairNode* other = pNodePair[1 - i];
		for (int j = 0; j < self->m_iNumberOfEntries; j++)
		{
			PairEntry* e = &self->m_entries[j];
			if ((PairNode*)(e->m_link1 ^ e->m_link0 ^ (unsigned int)self) == other)
			{
				return self->m_entries[j].m_pCollisionAgent;
			}
		}
	}
	return 0;
}

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
// Walks the linked list from a->unk10 while node unk00 is at least 0x17 and returns the last node visited.
// @fnv 0x00d277f0
FUN_00d277f0_node* __cdecl FUN_00d277f0(FUN_00d277f0_arg* a)
{
    FUN_00d277f0_node* p = a->unk10;
    if (!p) {
        return p;
    }
    FUN_00d277f0_node* n = p->unk14;
    if (n->unk00 < 0x17) {
        return p;
    }
    do {
        p = n;
        n = n->unk14;
    } while (n->unk00 >= 0x17);
    return p;
}

struct FUN_00d61840_class {
    int m_iWordAt00;
    int __thiscall FUN_00d61c10(int a);
    int __thiscall ReplaceChar(int a, int b, int c);
};
// @fnv 0x00d2b330
int __cdecl CallAndGetId(int a, FUN_00d61840_class* obj)
{
    obj->FUN_00d61c10(a);
    obj->ReplaceChar(0x2f, 0x5c, 1);
    return obj->m_iWordAt00;
}

struct PathHelper {
    char* m_data;

    void __thiscall FUN_00d61c10(const char* s);
    void __thiscall ReplaceChar(char from, char to, int all);
    void __thiscall FUN_00d62190(const char* from, const char* to, int all);
    int __thiscall FUN_00d61560(const char* s);
    void __thiscall RemoveFront(int count);
};

// @fnv 0x00d2b360
const char* __cdecl FUN_00d2b360(const char* path, PathHelper* aPathHelper)
{
    aPathHelper->FUN_00d61c10(path);
    aPathHelper->ReplaceChar('\\', '/', 1);
    aPathHelper->FUN_00d62190("/./", "/", 1);
    if (aPathHelper->FUN_00d61560("./"))
        aPathHelper->RemoveFront(2);
    return aPathHelper->m_data;
}

struct FnvCpu_FUN_00d2c7d0_CpuInterface {
    virtual void Invoke(int value);
};
// @fnv 0x00d2c7d0
void __cdecl FUN_00d2c7d0(FnvCpu_FUN_00d2c7d0_CpuInterface* object)
{
    object->Invoke(0);
}

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
// Placement-constructs an ObjD2C840 with the given count into the provided storage.
// @fnv 0x00d2c840
void __cdecl ConstructObjD2C840(void* storage, int count)
{
    new(storage) ObjD2C840(count);
}

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
// @fnv 0x00d2cd80
FUN_00d2cd80_Obj* __thiscall FUN_00d2cd80_Obj::FUN_00d2cd80()
{
    FUN_00d2cd80_Obj* self = this;
    self->unk04.Create(0, 6);
    return self;
}

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
// @fnv 0x00d2cda0
C_d2cda0* C_d2cda0::FUN_00d2cda0()
{
    a8.FUN_00d87910();
    b24.Create(0, 1);
    m_28 = 0;
    m_2c = 0;
    m_20 = 0;
    m_18 = -1;
    m_iWordAt00 = 0;
    return this;
}

struct FnvCpu_FUN_00d329b0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d329b0_CpuObject {
    void FUN_00d32170(void*, void*, unsigned int, FnvCpu_FUN_00d329b0_CpuCallData*);
    void DispatchWithBound(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data record from the fourth argument, DAT_0104da48 and DAT_010ce7fc, then forwards it to FUN_00d32170 with the first two arguments swapped.
// @fnv 0x00d329b0
void FnvCpu_FUN_00d329b0_CpuObject::DispatchWithBound(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d329b0_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d32170(second, first, third, &data);
}

// @fnv 0x00d32ac0
int __cdecl FUN_00d32ac0(int param_1, int param_2)
{
    return param_2 + 0x10;
}

// @fnv 0x00d32ad0
void* __cdecl FUN_00d32ad0(int unused, char* p) {
    return p + 16;
}

extern int DAT_010ce81c;
void __cdecl FUN_00d33b90(int b, int a, int c, SpawnedBuf* buffer);
// Initializes a SpawnedBuf with zero, a global pointer and d, then calls FUN_00d33b90 with b, a, c and the buffer.
// @fnv 0x00d34930
void __cdecl InitSpawnedBuffer(int a, int b, int c, int d)
{
    SpawnedBuf buffer;
    buffer.m_iWordAt04 = 0;
    buffer.m_iWordAt00 = &DAT_010ce81c;
    buffer.m_8 = d;
    FUN_00d33b90(b, a, c, &buffer);
}

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
// @fnv 0x00d34aa0
void __thiscall FUN_00d34aa0_Obj::FUN_00d34aa0(int param_1, int param_2, int param_3, int param_4)
{
    FUN_00d338e0(param_2, param_1, param_3, param_4);
}

struct FnvCpu_FUN_00d34b00_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d34b00_CpuObject {
    void FUN_00d33b70(void*, void*, unsigned int, FnvCpu_FUN_00d34b00_CpuCallData*);
    void DispatchCpuCall(void*, void*, unsigned int, unsigned int);
};
// @fnv 0x00d34b00
void FnvCpu_FUN_00d34b00_CpuObject::DispatchCpuCall(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d34b00_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d33b70(second, first, third, &data);
}

// Scans the first three entries of table for key and, if found, replaces it with 0xffff and returns.
// @fnv 0x00d39030
void RemoveKeyFromTable(int, unsigned short* table, unsigned short key)
{
    for (int i = 0; i < 3; ++i) {
        if (table[i] == key) {
            table[i] = 0xffff;
            return;
        }
    }
}

// Scans the first three slots for the 0xffff empty marker and writes value into the first free one, then returns.
// @fnv 0x00d39060
void __cdecl InsertIntoSlotArray(void* unused, unsigned short* slots, unsigned short value) {
    for (int i = 0; i < 3; ++i) {
        if (slots[i] == 0xffff) {
            slots[i] = value;
            return;
        }
    }
}

// @fnv 0x00d39090
void FUN_00d39090()
{
}

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
// @fnv 0x00d390a0
char* __cdecl InitOutputDefaults(FUN_00d390a0_Owner* owner, FUN_00d390a0_Flags* flags, FUN_00d390a0_Out* out) {
    FUN_00d390a0_Leaf* leaf = owner->m_mid->m_pLeafNode;
    flags->unk02 = 0;
    out->unk00 = 0xffff;
    out->unk02 = 0xffff;
    out->unk04 = 0xffff;
    ComputeInverseLengths((char*)leaf + 0x20, &out->unk08);
    return (char*)out + 0x20;
}

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

// Calls callback->method14 for each non-0xffff handle in handles, marks them 0xffff, and returns &handles->state20.
// @fnv 0x00d390e0
unsigned short* __cdecl ReleaseHandles(void* unused, D390HandleTable* handles, D390Callback* callback, void* context)
{
    for (int index = 0; index < 3; ++index) {
        unsigned int handle = handles->handles[index];
        if ((unsigned short)handle != 0xffff) {
            callback->method14(handle, context);
            handles->handles[index] = 0xffff;
        }
    }
    return &handles->state20;
}

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

// Builds a D3FD30Funcs via FUN_00d3fce0, then passes it to pkDispatcher->AddSpawnEntry with 1 and 1.
// @fnv 0x00d3fd30
void __cdecl DispatchFuncs(D3FD30Dispatcher* pkDispatcher)
{
    D3FD30Funcs kFuncs;
    FUN_00d3fce0(&kFuncs);
    pkDispatcher->AddSpawnEntry(&kFuncs, 1, 1);
}

// @fnv 0x00d3fde0
void FUN_00d3fde0()
{
}

extern int DAT_0102e388;

struct Foo00d24660 {
    void FUN_00d24660();
};

// @fnv 0x00d24660
void Foo00d24660::FUN_00d24660()
{
    *(int*)this = (int)&DAT_0102e388;
}

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

// Calls FUN_00d24660, then if uiFlags & 1 frees this via operator delete, and returns this.
// @fnv 0x00d262e0
FUN_00d496d0* FUN_00d496d0::FUN_00d262e0(unsigned int uiFlags) throw()
{
    FUN_00d24660();
    if (uiFlags & 1)
        FUN_00d496d0::operator delete(this);
    return this;
}

void FUN_00da3510(void*, void*);

// @fnv 0x00d2d460
void FUN_00d2d460(int, void* b, void* c)
{
    FUN_00da3510(b, c);
}

extern unsigned char DAT_011b4284;
// @fnv 0x00d2f530
void __cdecl FUN_00d2f530(unsigned char* p)
{
    *p = DAT_011b4284;
}

extern unsigned char DAT_011b4284;

// @fnv 0x00d2f540
void __cdecl FUN_00d2f540(unsigned char value)
{
    DAT_011b4284 = value;
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern "C" void __cdecl GetClosestPointsShapeCollection();

struct D347D0Query {
    const unsigned char* descriptor;
    float bound;
    unsigned int filter;
};

// Builds a D347D0Query from DAT_010ce7fc, DAT_0104da48 and filter, then calls GetClosestPointsShapeCollection with b, a, c and the query.
// @fnv 0x00d347d0
void __cdecl QueryClosestPoints(void* a, void* b, void* c, unsigned int filter)
{
    D347D0Query query = { &DAT_010ce7fc, DAT_0104da48, filter };
    typedef void (__cdecl *Dispatch)(void*, void*, void*, D347D0Query*);
    ((Dispatch)GetClosestPointsShapeCollection)(b, a, c, &query);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct D34970Context {
    void* pointer;
    float maxDistance;
    int option;
};
extern "C" void __cdecl FUN_00d339d0(int first, int second, int third, D34970Context* context);
// Builds a D34970Context from DAT_010ce7fc, DAT_0104da48, and arg3, then calls FUN_00d339d0 with arg1, arg0, arg2, and the context.
// @fnv 0x00d34970
void __cdecl FUN_00d34970(int arg0, int arg1, int arg2, int aiOption) {
    D34970Context context;
    context.pointer = &DAT_010ce7fc;
    context.maxDistance = DAT_0104da48;
    context.option = aiOption;
    FUN_00d339d0(arg1, arg0, arg2, &context);
}

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

// Builds a local struct holding &DAT_010ce81c, 0 and d, then calls FUN_00d33c80 with b, a, c and a pointer to the struct.
// @fnv 0x00d34ac0
void FUN_00d33c80_class::FUN_00d34ac0(void* a, void* b, void* c, void* d)
{
    D34ac0Struct s;
    s.g = d;
    s.f = 0;
    s.e = &DAT_010ce81c;
    FUN_00d33c80(b, a, c, &s);
}

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

// Allocates a 0x10-byte D3C380_Obj via the global AllocationManager, initializes its fields, and returns the pointer.
// @fnv 0x00d3c380
D3C380_Obj* __cdecl CreateD3C380Obj(int aiUnused1, int aiUnused2, int aiUnused3, int aiValue)
{
    AllocationManager* mgr = FUN_00c85750();
    D3C380_Obj* o = (D3C380_Obj*)((D3C380_Allocator*)mgr->allocator)->alloc(0x10);
    o->w4 = 0x10;
    o->w6 = 1;
    o->i8 = aiValue;
    o->vt = (void**)&DAT_010cefdc;
    o->wC = 0xFFFF;
    return o;
}

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

// Allocates a 0x20-byte object, sets its header fields and vtable pointer, and passes *a2 + 0x20 and its m10 block to FUN_00cd7160.
// @fnv 0x00d3d1a0
void* __cdecl CreateRetObj(int a1, char** a2, int a3, int aiValue)
{
    AllocMgr* o;
    o = (AllocMgr*)FUN_00c85750();
    RetObj* mgr = (RetObj*)o->allocator->Alloc(0x20);
    mgr->f04 = 0x20;
    mgr->f06 = 1;
    mgr->f08 = aiValue;
    mgr->f0c = 0xffff;
    mgr->vtbl = (void*)&DAT_010cf060;
    FUN_00cd7160(*a2 + 0x20, &mgr->m10);
    return mgr;
}

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

// Allocates a 0x10-byte D3E270_obj via the manager's allocator, sets its size, count and vtable fields, and stores a4 in f08.
// @fnv 0x00d3e270
D3E270_obj* __cdecl FUN_00d3e270(int aiUnused1, int aiUnused2, int aiUnused3, int aiValue)
{
    D3E270_mgr* mgr = (D3E270_mgr*)FUN_00c85750();
    D3E270_obj* o = mgr->r10->alloc(0x10);
    o->f04 = 0x10;
    o->f06 = 1;
    o->f08 = aiValue;
    o->vt = (D3E270_alloc*)&DAT_010cf0e4;
    o->f0c = 0xffff;
    return o;
}

struct D3FE70Info {
    void* pkInfo;
};
// @fnv 0x00d3fe70
D3FE10Entry* __cdecl FUN_00d3fe70(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, D3FE70Info kInfo)
{
    return ResetEntryAgents(pkHeader, pkEntry, pkManager, kInfo.pkInfo);
}

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

// Normalizes the segment direction and dots it with row70; if negative calls v20, and stores in *out whether a hit was reported, else 0.
// @fnv 0x00d212d0
unsigned char* D212D0Obj::FUN_00d212d0(unsigned char* apHit, D212D0Seg* apSegment, void* p3)
{
    __m128 a = apSegment->a;
    __m128 b = apSegment->b;
    __m128 delta = _mm_sub_ps(b, a);
    __m128 t = _mm_mul_ps(delta, delta);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(t, t, 0xAA), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
    __m128 r = _mm_rsqrt_ss(sum);
    __m128 eq = _mm_cmpeq_ss(sum, _mm_set_ss(DAT_01011d78));
    __m128 rr = _mm_mul_ss(_mm_mul_ss(sum, r), r);
    __m128 e = _mm_sub_ss(_mm_set_ss(DAT_01017718), rr);
    __m128 f = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), e);
    __m128 fm = _mm_andnot_ps(eq, f);
    __m128 vBroadcast = _mm_shuffle_ps(fm, fm, 0);
    __m128 pd = _mm_mul_ps(vBroadcast, delta);
    __m128 pr = _mm_mul_ps(pd, row70);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(pr, pr, 0xAA), _mm_add_ss(_mm_shuffle_ps(pr, pr, 0x55), pr)));
    char hit;
    unsigned char bResult;

    if (!(dot < 0.0f)) {
        bResult = 0;
    } else {
        v20(&hit, apSegment, p3);
        bResult = hit != 0;
    }
    *apHit = bResult;
    return apHit;
}

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

// Calls Dispatch on pkTarget with iArg0 and iArg1 and returns the result.
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

// Constructs a shape of type 8 and stores two vectors, a float, and two integers.
// @fnv 0x00d22dc0
FUN_00d22dc0::FUN_00d22dc0(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float afBoundRadius, int iA, int iB) throw()
    : ShapeD22DC0(8), m_iA(iA), m_iB(iB)
{
    m_kA = kA;
    m_kB = kB;
    m_fBoundRadius = afBoundRadius;
}

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

// Inserts numtoinsert elements from a at index i, moving existing elements back and updating the size.
// @fnv 0x00d27ec0
void hkSmallArrayE::Insert(int iIndex, const E48* apElements, int numtoinsert)
{
    const int newsize = m_iElementCount + numtoinsert;
    const int numtomove = m_iElementCount - iIndex;
    if (newsize > getCapacity()) reserve(newsize);
    CopyMemoryBackward(m_data + iIndex + numtoinsert, m_data + iIndex, numtomove * sizeof(E48));
    CopyMemoryBackward(m_data + iIndex, apElements, numtoinsert * sizeof(E48));
    m_iElementCount = (unsigned short)newsize;
}

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

// Finds the index of the largest value in values, swaps it with the first element, and remaps this->indices through the swap permutation.
// @fnv 0x00d281b0
int S00d281b0_Target::MoveLargestToFirst(S00d281b0_IntArray* values)
{
    int largest = 0;
    int size = values->count;
    int max = values->data[0];
    for (int i = 1; i < size; ++i) {
        if (values->data[i] > max) {
            max = values->data[i];
            largest = i;
        }
    }
    if (!largest) return 0;

    int* mapping;
    volatile int capacity;
    S00d281b0_Alloc& a = ((S00d281b0_Router*)FUN_00c85750())->heap();
    int n;
    if (size) {
        n = size;
        mapping = a._bufAlloc<int>(n);
        capacity = n;
    } else {
        mapping = 0;
        n = 0;
    }
    if (!n) capacity = 0x80000000;
    for (int i = 0; i < size; ++i) mapping[i] = i;
    mapping[0] = largest;
    mapping[largest] = 0;

    int first = values->data[0];
    int other = values->data[largest];
    values->data[largest] = first;
    values->data[0] = other;

    for (int i = 0; i < this->count; ++i) {
        int& r = this->indices->data[i];
        r = mapping[r];
    }
    S00d281b0_Alloc& b = ((S00d281b0_Router*)FUN_00c85750())->heap();
    int c = capacity;
    if ((c & 0x80000000) == 0)
        b._bufFree<int>(mapping, c & 0x3fffffff);
    return largest;
}

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

// @fnv 0x00d2acf0
FUN_00d2acf0::FUN_00d2acf0(void* a1, __m128* a2, __m128* a3, float a4, float a5, int a6)
    : FUN_00d2acf0_base(a1, a6)
{
    unk50 = a4;
    unk54 = a5;
    vtbl = (void**)0x10ce504;
    unk5c = 0;
    unk20 = *a2;
    unk30 = *a3;
    unk40 = _mm_setzero_ps();
}

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

// Creates an AgentB110 from pA's collision body shape when pA is type 2 and pB is type 0, otherwise returns null.
// @fnv 0x00d2b110
AgentB110* AgentFactoryB110::FUN_00d2b110(const InputB110* apInputA, const InputB110* apInputB)
{
    AutoMemContextB110 kContext(0x10);
    if (apInputA->m_type != 2)
        return 0;
    if (apInputB->m_type != 0)
        return 0;
    AgentB110* pAgent = new AgentB110(apInputA->m_kCollisionBody->getShape(), m_kA, m_kB, m_fCoefficientA, m_fB, m_pAgentData);
    pAgent->m_offset = m_offset;
    return pAgent;
}

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

// Creates an AgentD2C9 when the request kind is 2 and the count is zero, copying m_v20 from the factory.
// @fnv 0x00d2c9d0
AgentD2C9* FactoryD2C9::FUN_00d2c9d0(RequestD2C9* apRequest, CountD2C9* apCount)
{
    AutoMemContextD2C9 kContext(0x10);
    if (apRequest->m_iKind != 2)
        return 0;
    if (apCount->m_iArrayLength != 0)
        return 0;
    AgentD2C9* agent = new AgentD2C9(apRequest->GetName(), m_iOwner);
    agent->m_v20 = m_v20;
    return agent;
}

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
// XORs c->v with DAT_010c44d0 into a copy of c, builds one or two Q structs from c->v, d and e, and calls FUN_00d2f0d0 with b, a, the copy and the Qs.
// @fnv 0x00d2daf0
void __cdecl FUN_00d2daf0(int a, int b, Src* apSrc, int d, int e)
{
    __m128 vv = _mm_load_ps((float*)&apSrc->v);
    __m128 n = _mm_xor_ps(vv, DAT_010c44d0);
    Src copy = *apSrc;
    _mm_store_ps((float*)&copy.v, n);
    Q qa;
    qa.d = DAT_0104da48;
    qa.vt = &DAT_010ce80c;
    qa.v = apSrc->v;
    qa.x = d;
    if (e) {
        Q qb;
        qb.vt = &DAT_010ce80c;
        qb.d = DAT_0104da48;
        qb.v = apSrc->v;
        qb.x = e;
        ((Fn)FUN_00d2f0d0)(b, a, &copy, &qa, &qb);
    } else {
        ((Fn)FUN_00d2f0d0)(b, a, &copy, &qa, 0);
    }
}

struct CallbackState {
    const int* m_pIntegerValue;
    char m_cFlag;
    int m_iValue;
};
struct Holder {
    void FUN_00d315f0(int a, int b, int c, CallbackState* s);
    void FUN_00d2f3f0(int a, int b, int c, int d);
};
// Fills a CallbackState with d, a zero flag, and a pointer to DAT_010ce81c, then calls FUN_00d315f0 with b, a, c, and the state.
// @fnv 0x00d2f3f0
void Holder::FUN_00d2f3f0(int a, int b, int c, int aiValue)
{
    CallbackState s;
    s.m_iValue = aiValue;
    s.m_cFlag = 0;
    s.m_pIntegerValue = (const int*)&DAT_010ce81c;
    FUN_00d315f0(b, a, c, &s);
}

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

// Looks up the agent type pair in the dispatcher's type matrix and calls the corresponding penetration query function with the given bodies and input.
// @fnv 0x00d2f630
void __cdecl FUN_00d2f630(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector)
{
    DispatcherD2F630* pkDispatcher = kInput.m_pCollisionDispatcher;
    int iTypeA = kA.m_pCollisionShape->m_type;
    int iTypeB = kB.m_pCollisionShape->m_type;
    const unsigned char (*pTypes)[32] = kInput.m_createPredictive ? pkDispatcher->m_agentTypesPred : pkDispatcher->m_agentTypes;
    int iType = pTypes[iTypeA][iTypeB];
    AgentFuncD2F630 fn = (*(AgentFuncD2F630 volatile*)&pkDispatcher->m_agentFuncs[iType].m_pQueryPenetrationsFunc);
    _ReadWriteBarrier();
    fn(kA, kB, kInput, kCollector);
}

struct FUN_00d32970_Collector {
    void* vtable;
    unsigned char flag;
    unsigned int value;
};

struct FUN_00d32970_Agent {
    void FUN_00d32150(void* a, void* b, void* c, FUN_00d32970_Collector* collector);
    void FUN_00d32970(void* a1, void* a2, void* a3, unsigned int a4);
};

// Initialises a Collector with a4 and passes it to FUN_00d32150 with a2, a1 and a3.
// @fnv 0x00d32970
void FUN_00d32970_Agent::FUN_00d32970(void* a1, void* a2, void* a3, unsigned int uiValue)
{
    FUN_00d32970_Collector collector;
    collector.value = uiValue;
    collector.flag = 0;
    collector.vtable = &DAT_010ce81c;
    FUN_00d32150(a2, a1, a3, &collector);
}

namespace fnv_00d329f0 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d329 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d329 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d329 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d329 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d329 m_key;
    int m_uiFilterValue;
};

struct Agent_d329 {
    void FUN_00d32030(int a1, int a2, Input_d329* input, Record_d329* rec, Record_d329* optRec);
    void FUN_00d329f0(int a1, int a2, const Input_d329* input, int a4, int a5);
};
// Copies input, XORs its vector with DAT_010c44d0, builds a Record_d329 with a4, and calls FUN_00d32030 with an optional second record when a5 is non-zero.
// @fnv 0x00d329f0
void Agent_d329::FUN_00d329f0(int a1, int a2, const Input_d329* input, int a4, int a5)
{
    Input_d329 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d329 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = a4;

    if (a5 != 0) {
        Record_d329 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = a5;
        FUN_00d32030(a2, a1, &local, &rec, &rec2);
    } else {
        FUN_00d32030(a2, a1, &local, &rec, 0);
    }
}
}  // namespace fnv_00d329f0

namespace fnv_00d34810 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl FUN_00d43b90(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// XORs the input vector with DAT_010c44d0, builds a Record_d2e9 with the key and a4, and calls FUN_00d43b90 with an optional second record for a5.
// @fnv 0x00d34810
void __cdecl FUN_00d34810(int a2, int a1, const Input_d2e9* input, int aiValue, int aiOptionalValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        FUN_00d43b90(a1, a2, &local, &rec, &rec2);
    } else {
        FUN_00d43b90(a1, a2, &local, &rec, 0);
    }
}
}  // namespace fnv_00d34810

namespace fnv_00d349b0 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl FUN_00d33ca0(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// XORs input vector with DAT_010c44d0, builds a Record_d2e9 with a4, and calls FUN_00d33ca0 with an optional second record when a5 is non-zero.
// @fnv 0x00d349b0
void __cdecl FUN_00d349b0(int a2, int a1, const Input_d2e9* input, int aiValue, int aiOptionalValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        FUN_00d33ca0(a1, a2, &local, &rec, &rec2);
    } else {
        FUN_00d33ca0(a1, a2, &local, &rec, 0);
    }
}
}  // namespace fnv_00d349b0

namespace fnv_00d34b40 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d34b {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d34b {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d34b m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d34b {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d34b m_key;
    int m_uiFilterValue;
};

struct Agent_d34b {
    void FUN_00d33da0(int a1, int a2, Input_d34b* input, Record_d34b* rec, Record_d34b* optRec);
    void FUN_00d34b40(int a1, int a2, const Input_d34b* input, int a4, int a5);
};
// XORs the input key with a constant, builds a Record_d34b with the key and a4, and calls FUN_00d33da0 with an optional second record for a5.
// @fnv 0x00d34b40
void Agent_d34b::FUN_00d34b40(int a1, int a2, const Input_d34b* input, int aiValue, int aiOptionalValue)
{
    Input_d34b local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d34b rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d34b rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        FUN_00d33da0(a2, a1, &local, &rec, &rec2);
    } else {
        FUN_00d33da0(a2, a1, &local, &rec, 0);
    }
}
}  // namespace fnv_00d34b40

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

// Calls FUN_00d33f40 with swapped bodies, flips collected points, and if the distance changed, negates the normal and swaps shape-key entries in the collector.
// @fnv 0x00d34c10
void LinearCastAgent::FUN_00d34c10(int bodyA, int bodyB, int input, int collectorRaw) {
    CastCollector& collector = *(CastCollector*)collectorRaw;
    float saved_dist = collector.m_dist3030;
    Point* y = collector.m_currentPoint;

    FUN_00d33f40(bodyB, bodyA, input, collectorRaw);

    for (; y < collector.m_currentPoint; ++y) {
        y->flip();
    }

    if (saved_dist != collector.m_dist3030) {
        hkVector4* pNormal = &collector.m_normal3020;
        pNormal->m_vComponents = _mm_xor_ps(pNormal->m_vComponents, DAT_010c4c00);
        _ReadWriteBarrier();

        unsigned char p = collector.m_byte304a.m_kPointB;
        unsigned char low = collector.m_byte304a.m_kPointA;
        collector.m_byte304a.m_kPointA = p;
        collector.m_byte304a.m_kPointB = low;

        unsigned char cByte48 = collector.m_byte3048;
        unsigned char old49 = collector.m_byte3049;
        collector.m_byte3049 = cByte48;
        unsigned int idx = cByte48;
        idx += old49;
        idx -= 1;
        collector.m_byte3048 = old49;
        unsigned short (&shapeKeys)[4] = collector.m_uiShapeKeys;
        unsigned short old48 = shapeKeys[0];
        shapeKeys[0] = shapeKeys[idx];
        shapeKeys[idx] = old48;

        unsigned char* p48 = &collector.m_byte3048;
        if ((*p48 & collector.m_byte3049) == 2) {
            unsigned short t = collector.m_uiShapeKeys[1];
            collector.m_uiShapeKeys[1] = collector.m_uiShapeKeys[2];
            collector.m_uiShapeKeys[2] = t;
        }
    }
}

extern "C" void __cdecl FUN_00da3510(int, int);
// Forwards a2 and a3 to FUN_00da3510, ignoring a1.
// @fnv 0x00d34d60
void __cdecl ForwardCall(int aUnused, int a2, int a3)
{
    FUN_00da3510(a2, a3);
}

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
// Allocates a FUN_00d36b20 object via the custom heap operator new and forwards the four constructor arguments to it.
// @fnv 0x00d36b70
FUN_00d36b20* FUN_00d36b70(int param1, int param2, int* param3, int param4)
{
    return new FUN_00d36b20(param1, param2, param3, param4);
}

namespace fnv_00d2dc10 {
struct D2DC10Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D2DC10MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2DC10Allocator* m_pStreamAllocator;

    D2DC10Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D2DC10MemoryRouter& __cdecl FUN_00c85750();

class D2DC10BaseObject {
public:
    virtual ~D2DC10BaseObject() {}
};

class FUN_00d2dc10 : public D2DC10BaseObject {
// Default constructor for a D2DC10 base object, inheriting from D2DC10BaseObject with no initialization.
// @fnv 0x00d2dc10
public:
    FUN_00d2dc10() {}
    virtual ~FUN_00d2dc10() {}

    static void* operator new(unsigned int, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void operator delete(void* p, unsigned int nbytes) { FUN_00c85750().heap().ReleaseBlock(p, nbytes); }

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
};

void* D2DC10Construct(void* pvMem)
{
    return new (pvMem) FUN_00d2dc10;
}
}  // namespace fnv_00d2dc10

namespace fnv_00d37d30 {
struct D37D30Allocator {
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void vfunc03();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D37D30MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D37D30Allocator* m_pStreamAllocator;

    D37D30Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D37D30MemoryRouter& __cdecl FUN_00c85750();

class D37D30ReferencedObject {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~D37D30ReferencedObject() throw() {}
};

template <class T>
class D37D30Array {
public:
    enum { CAPACITY_MASK = 0x3fffffff };
    static const unsigned int DONT_DEALLOCATE_FLAG = 0x80000000;

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~D37D30Array() throw() {
        D37D30Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & CAPACITY_MASK) * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
};

class FUN_00d37d30 : public D37D30ReferencedObject {
public:
    int unk08;
    D37D30Array<unsigned short> m_ppIndices;

    FUN_00d37d30();

    static void operator delete(void* p) {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<D37D30ReferencedObject*>(p)->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00d37d30
FUN_00d37d30::FUN_00d37d30() {
}
}  // namespace fnv_00d37d30

#include <xmmintrin.h>
namespace fnv_00d22260 {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float f[4]; };
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

struct D22260_Matrix
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
    float* m_data;
};

struct D22260_Math {
    __m128 v;
    void rotate(const float* rows, const D22260_Math& input) {
        __m128 x = _mm_shuffle_ps(input.v,input.v,0);
        __m128 ax = _mm_mul_ps(_mm_load_ps(rows),x);
        __m128 y = _mm_shuffle_ps(input.v,input.v,0x55);
        __m128 ay = _mm_mul_ps(_mm_load_ps(rows+4),y);
        __m128 z = _mm_shuffle_ps(input.v,input.v,0xaa);
        __m128 az = _mm_mul_ps(_mm_load_ps(rows+8),z);
        v = _mm_add_ps(_mm_add_ps(ax,ay),az);
    }
    void cross(const D22260_Math& a, const D22260_Math& b) {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(a.v,a.v,0xc9), _mm_shuffle_ps(b.v,b.v,0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(a.v,a.v,0xd2), _mm_shuffle_ps(b.v,b.v,0xc9));
        v = _mm_sub_ps(positive,negative);
    }
    void add(const D22260_Math& a) { v = _mm_add_ps(v,a.v); }
};

struct D22260_Vector
{
    D22260_Math m_uiFilterValue;
    D22260_Math m_secondary;
};

struct D22260_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    D22260_Math m_quaternion1;
    D22260_Math m_quaternion2;

    void __thiscall FUN_00d22260(
        int ReportDiagnostic,
        int unused1,
        D22260_Matrix* matrix1,
        D22260_Vector* vector1,
        D22260_Matrix* matrix2,
        D22260_Vector* vector2);
};

// Transforms m_quaternion1/2 by the matrices' rows, crosses each result with the vector's second field, and adds the product to its first field.
// @fnv 0x00d22260
void __thiscall D22260_Object::FUN_00d22260(
    int ReportDiagnostic,
    int unused1,
    D22260_Matrix* matrix1,
    D22260_Vector* vector1,
    D22260_Matrix* matrix2,
    D22260_Vector* vector2)
{
    D22260_Math rotated1, rotated2;
    rotated1.rotate(matrix1->m_data, m_quaternion1);
    rotated2.rotate(matrix2->m_data, m_quaternion2);
    D22260_Math cross1, cross2;
    cross1.cross(rotated1, vector1->m_secondary);
    cross2.cross(rotated2, vector2->m_secondary);
    vector1->m_uiFilterValue.add(cross1);
    vector2->m_uiFilterValue.add(cross2);
}
}  // namespace fnv_00d22260

// FUN_00d24650 - __stdcall function, callee pops 4 bytes (1 stack parameter)
// @fnv 0x00d24650
void __stdcall FUN_00d24650(int _param) {
}

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
// Swaps the two hkpCdBody arguments and forwards them to hkpListAgent::FUN_00d36b00 via a hkpSymmetricAgentFlipBodyCollector.
// @fnv 0x00d36d20
template<> void hkpSymmetricAgent<hkpListAgent>::FUN_00d36d20(
    const hkpCdBody& a, const hkpCdBody& b,
    const CollisionAgentContext& input, hkpCdBodyPairCollector& output)
{
    hkpSymmetricAgentFlipBodyCollector collector;
    collector.unk08 = &output;
    collector.unk04 = 0;
    collector.unk00 = &DAT_010ce81c;
    hkpListAgent::FUN_00d36b00(b, a, input, collector);
}

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
// @fnv 0x00d365d0
int FUN_00d365d0(A1Rec* a1, int a2, int a3, int a4, int a5)
{
    int nameid;
    unsigned int stamped;
    int result;
    O1T o1;
    CF56Obj obj;
    void* tlsblk = TlsGetValue(DAT_0126835c);
    if (*(unsigned int*)((char*)tlsblk + 4) < *(unsigned int*)((char*)tlsblk + 0xc))
    {
        unsigned char* cur = (unsigned char*)(*(unsigned int*)((char*)tlsblk + 4));
        *(const char**)cur = DAT_010ced28;
        __asm
        {
            rdtsc
            mov dword ptr[stamped], eax
        }
        *(unsigned int*)(cur + 4) = stamped;
        *(unsigned int*)((char*)tlsblk + 4) = (unsigned int)cur + 0xc;
    }

    o1.FUN_00d33260(a1);
    o1.unk60 = a1->unk60;
    *(V4q*)&o1.unk70 = a1->unk70;
    nameid = *(int*)(void*)a1->unk00;
    FUN_00cf5640* shape = new (&obj) FUN_00cf5640(&nameid, 1, 0);
    void* cfret = shape;
    CollidableBuffer cb;
    PRec* p = (PRec*)a1->unk00;
    if (p->unk0C == 0)
    {
        cb.o40.m_kCollisionBody = p->unk20;
    }
    void* t8 = p->unk08;
    void* tc = p->unk0C;
    cb.z.unk0C = tc;
    cb.z.unk08 = t8;
    o1.unk08 = p;
    o1.unk00 = &cb.z;
    cb.z.unk00 = cfret;
    cb.z.unk04 = -1;
    result = FUN_00d35770(&o1, a2, a3, a4, a5);
    int* r18 = &shape->r18_00;
    AllocationManager* q = FUN_00c85750();
    void* mgr = q->allocator;
    _ReadWriteBarrier();
    int masked = r18[2] & 0x3fffffff;
    if (masked < 0)
    {
        int sz = masked * 2;
        FUN_00c908c0(mgr, r18, maxSize(0, sz), 0x10);
    }
    r18[1] = 0;
    shape->~FUN_00cf5640();

    void* tlsblk2 = TlsGetValue(DAT_0126835c);
    if (*(unsigned int*)((char*)tlsblk2 + 4) < *(unsigned int*)((char*)tlsblk2 + 0xc))
    {
        unsigned char* cur2 = (unsigned char*)(*(unsigned int*)((char*)tlsblk2 + 4));
        *(const char**)cur2 = DAT_010c41f8;
        __asm
        {
            rdtsc
            mov dword ptr[stamped], eax
        }
        *(unsigned int*)(cur2 + 4) = stamped;
        *(unsigned int*)((char*)tlsblk2 + 4) = (unsigned int)cur2 + 0xc;
    }
    return result;
}

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

// Fills a function table via FUN_00d36c30 and passes it to agent->FUN_00cfbbe0 with (9, -1), then refills via FUN_00d36bb0 and passes it with (-1, 9).
// @fnv 0x00d36c60
void __cdecl FUN_00d36c60(void* apAgent)
{
    CollisionAgentFunctionTable funcs;
    funcs.e = 0;
    funcs.f = 0;
    FUN_00d36c30(&funcs);
    Agent* agent = (Agent*)apAgent;
    agent->FUN_00cfbbe0(&funcs, 9, -1);
    funcs.e = 0;
    funcs.f = 0;
    FUN_00d36bb0(&funcs);
    agent->FUN_00cfbbe0(&funcs, -1, 9);
}
