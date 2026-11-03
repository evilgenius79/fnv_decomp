// gamebryo2.2/corelibs/nianimation/nicontrollermanager.cpp: Item, NiControllerManager, TargetStandIn, NiTFixedStringMap_NiAVObject___ and more (40 functions)

#include "nicontrollermanager.h"

// @fnv 0x00a2e220
void NiControllerManager::Update(NiUpdateData& kData)
{
    if ((static_cast<unsigned char>(m_uiObjectFlags >> 3) & 1) != 0)
    {
        for (unsigned int i = 0; i < m_kPlayingSequences.m_uiAllocatedCapacity; ++i)
        {
            NiControllerSequence* pkSequence = m_kPlayingSequences.m_pBase[i];
            pkSequence->Update(kData.fTime, true);
            if (pkSequence->m_eAnimationState == NiControllerSequence::INACTIVE)
            {
                --m_kPlayingSequences.m_uiAllocatedCapacity;
                m_kPlayingSequences.m_pBase[i] = m_kPlayingSequences.m_pBase[m_kPlayingSequences.m_uiAllocatedCapacity];
                --i;
            }
        }
    }
}

extern bool DAT_011f369b;
extern unsigned char DAT_011f3763;
extern void* DAT_011f3ddc;
extern void* DAT_011f3a7c;
extern void* DAT_011f39ec;
extern void* DAT_011f395c;
extern void* DAT_011f38cc;

void __cdecl CreateVertexRecords();
void __cdecl FUN_00a2d470();
void __cdecl FUN_00a2a7b0();
void __cdecl AllocateTempArray();
void __cdecl FUN_00a2a600();
void __cdecl FUN_00a2d5b0(int, int);

// If not already initialized, marks it initialized, stores five function pointers into globals, sets a byte to 0x10, calls FUN_00a2d5b0(1, 5), and returns 1.
// @fnv 0x00a2d610
int __cdecl FUN_00a2d610()
{
    if (DAT_011f369b)
        return 0;
    DAT_011f369b = true;
    DAT_011f3ddc = (void*)&CreateVertexRecords;
    DAT_011f3a7c = (void*)&FUN_00a2d470;
    DAT_011f39ec = (void*)&FUN_00a2a7b0;
    DAT_011f395c = (void*)&AllocateTempArray;
    DAT_011f38cc = (void*)&FUN_00a2a600;
    DAT_011f3763 = 0x10;
    FUN_00a2d5b0(1, 5);
    return 1;
}

extern int DAT_01096114;
extern int DAT_0109618c;
extern int DAT_01096284;

void __fastcall _Call_a5d3a0(void*);
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
void __fastcall FUN_00a6e960(void*);

__forceinline void init_map(int* map, int size)
{
    map[0] = reinterpret_cast<int>(&DAT_01096114);
    map[1] = size;
    map[3] = 0;
    void* mem = _NiMalloc(size * 4);
    map[2] = reinterpret_cast<int>(mem);
    _fnv_zlib_memset(mem, 0, map[1] * 4);
    map[0] = reinterpret_cast<int>(&DAT_0109618c);
}

// @fnv 0x00a2ed80
int* __fastcall FUN_00a2ed80(int* this_ptr, int, int arg1, int arg2)
{
    _Call_a5d3a0(this_ptr);
    this_ptr[0] = reinterpret_cast<int>(&DAT_01096284);
    init_map(this_ptr + 2, arg2);
    this_ptr[6] = arg1;
    FUN_00a6e960(this_ptr);
    return this_ptr;
}

struct HashItem
{
    HashItem* m_pkNext;
    unsigned int m_kControlPoint;
    void* m_val;
};

struct HashObj
{
    char pad[0xc];
    unsigned int m_uiHashSize;
    HashItem** m_ppkHashTable;
};

// Looks up a key in the hash table by key modulo hash size, walking the bucket chain and returning the matching item's value or 0.
// @fnv 0x00a2ee00
void* __fastcall FUN_00a2ee00(HashObj* pThis, int, const unsigned int* pKey)
{
    unsigned int key = *pKey;
    if (key)
    {
        HashItem* item = pThis->m_ppkHashTable[key % pThis->m_uiHashSize];
        while (item)
        {
            if (key == item->m_kControlPoint)
                return item->m_val;
            item = item->m_pkNext;
        }
    }
    return 0;
}

extern int DAT_0109607c;
extern int DAT_01096114;
extern int DAT_0109618c;
extern int DAT_01096284;

void __cdecl _NiFreeAlias(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

class NiTFixedStringMap_NiAVObject___
{
  public:
    void RemoveAll();
};

struct NiObject_Helper
{
    void FUN_00a5d3d0();
};

// @fnv 0x00a2ee70
void* __fastcall FUN_00a2ee70(int* pThis, int, unsigned int flags)
{
    int* pMap = pThis + 2;
    *pThis = (int)&DAT_01096284;
    *pMap = (int)&DAT_0109618c;
    reinterpret_cast<NiTFixedStringMap_NiAVObject___*>(pMap)->RemoveAll();
    *pMap = (int)&DAT_01096114;
    reinterpret_cast<NiTFixedStringMap_NiAVObject___*>(pMap)->RemoveAll();
    _NiFreeAlias(reinterpret_cast<void*>(pMap[2]));
    *pThis = (int)&DAT_0109607c;
    reinterpret_cast<NiObject_Helper*>(pThis)->FUN_00a5d3d0();
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x1c);
    }
    return pThis;
}

void __fastcall FUN_00a2ebb0(void* pThis);
void __cdecl FUN_00aa1460(void* p, size_t size);

// @fnv 0x00a2ef80
void* __fastcall FUN_00a2ef80(void* pThis, int, unsigned int flags)
{
    FUN_00a2ebb0(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x7c);
    }
    return pThis;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a2f380_shell : public NiControllerManager
{
    void CloneControllerManager(NiControllerManager*, CloningProcess*);
};

extern int DAT_011f49e0;

struct CloneableObj
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual CloneableObj* MakeClone(CloningProcess* kCloning);
    volatile long m_uiRefCount;

    void FUN_00a6cfe0(NiControllerManager* pkDest, CloningProcess* kCloning);
    bool AttachSeqToOwner(void* pkSequence, void* kName, int bStoreTargets);
};

// Clones the controller manager into pkDest: copies the flag at 0x68, clones each sequence and the palette, and updates reference counts.
// @fnv 0x00a2f380
void FUN_00a2f380_shell::CloneControllerManager(NiControllerManager* pkDest, CloningProcess* kCloning)
{
    ((CloneableObj*)this)->FUN_00a6cfe0(pkDest, kCloning);
    *(bool*)((char*)pkDest + 0x68) = *(bool*)((char*)this + 0x68);

    for (unsigned int ui = 0; ui < *(unsigned short*)((char*)this + 0x3e); ui++)
    {
        CloneableObj* pkSequence = (*(CloneableObj***)((char*)this + 0x38))[ui];
        if (pkSequence)
        {
            CloneableObj* pkNewSequence = pkSequence->MakeClone(kCloning);
            ((CloneableObj*)pkDest)->AttachSeqToOwner(pkNewSequence, &DAT_011f49e0, 0);
        }
    }

    CloneableObj* pkPalette = *(CloneableObj**)((char*)this + 0x78);
    if (pkPalette)
    {
        CloneableObj* pkNewPalette = pkPalette->MakeClone(kCloning);
        CloneableObj* pkOldPalette = *(CloneableObj**)((char*)pkDest + 0x78);
        if (pkOldPalette != pkNewPalette)
        {
            if (pkOldPalette)
            {
                if (InterlockedDecrement(&pkOldPalette->m_uiRefCount) == 0)
                    pkOldPalette->DeleteThis();
            }
            *(CloneableObj**)((char*)pkDest + 0x78) = pkNewPalette;
            if (pkNewPalette)
                InterlockedIncrement(&pkNewPalette->m_uiRefCount);
        }
    }
}

extern const char g_011f4a04_arg1[];
// @fnv 0x00a2e1e0
const char* __cdecl FUN_00a2e1e0()
{
    return g_011f4a04_arg1;
}

struct FUN_00a2e420_shell
{
    unsigned char __thiscall FUN_00a2e420(float f);
};

// @fnv 0x00a2e420
unsigned char __thiscall FUN_00a2e420_shell::FUN_00a2e420(float f)
{
    unsigned int i = 0;
    while (i < *(unsigned int*)((char*)this + 0x4c))
    {
        void* p = *(void**)((char*)*(void**)((char*)this + 0x44) + i * 4);
        if (*(unsigned int*)((char*)p + 0x44) == 4)
        {
            void** vtbl = (void**)p;
            void* obj = *vtbl;
            void** v2 = (void**)((char*)obj + 0x8c);
            (*(void(__thiscall**)(void*, float, unsigned int))v2)(p, f, 0);
        }
        ++i;
    }
    return 0;
}

struct MemoryManager
{
    void _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
struct S460
{
    void DestroyHashTable();
};
// @fnv 0x00a2e550
void* __fastcall FUN_00a2e550(S460* self, int edx, unsigned int flags)
{
    self->DestroyHashTable();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(self);
    return self;
}

namespace fnv_00a2ebb0 {
extern int DAT_0109619c;
extern int DAT_01096184;
void __cdecl NiFree(void*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RC
{
    virtual void V0();
    virtual void Del();
    long refs;
};
struct MemoryManager
{
    void _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
void __cdecl ReleaseObjectArray(void*);
struct S620
{
    void FUN_00a2e620();
};
struct S450
{
    void ClearAndDestroy();
};
struct S460
{
    void DestroyHashTable();
};
struct S290
{
    void FUN_00a6d290();
};

// @fnv 0x00a2ebb0
void __fastcall FUN_00a2ebb0(char* self)
{
    char* b = self + 0x34;
    *(void**)self = &DAT_0109619c;
    ((S620*)b)->FUN_00a2e620();
    S450* p = *(S450**)(self + 0x64);
    *(int*)(self + 0x74) = 0;
    if (p)
    {
        p->ClearAndDestroy();
        g_memoryManager._DeallocateAlias(p);
    }
    RC* o = *(RC**)(self + 0x78);
    if (o)
        if (InterlockedDecrement(&o->refs) == 0)
            o->Del();
    ReleaseObjectArray(*(void**)(self + 0x6c));
    ((S460*)(self + 0x50))->DestroyHashTable();
    NiFree(*(void**)(self + 0x44));
    *(void**)b = &DAT_01096184;
    ReleaseObjectArray(*(void**)(b + 4));
    ((S290*)self)->FUN_00a6d290();
}
}  // namespace fnv_00a2ebb0

struct NiRTTI
{
    int x;
};
extern NiRTTI DAT_011f36ac;
// @fnv 0x00a2ec40
const NiRTTI* __cdecl FUN_00a2ec40()
{
    return &DAT_011f36ac;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f4a04;
// @fnv 0x00a2ede0
GlobalObjectO2_00a7b610* __cdecl FUN_00a2ede0()
{
    return &g_011f4a04;
}

// @fnv 0x00a2edf0
void __fastcall FUN_00a2edf0(char* self, int edx, void* scene)
{
    *(void**)(self + 0x18) = scene;
}

struct NiFixedString;
template <class K, class V> struct NiTMapItem;
template <class T> struct DFALL;
template <class T, class V> struct NiTFixedStringMapBase
{
    void SetAt(NiFixedString&, const char*);
};
struct Stub
{
    void FUN_00aa0250(NiFixedString&);
};
typedef NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, const char*> >, const char*> Map;

// @fnv 0x00a2ee40
void __fastcall FUN_00a2ee40(char* self, int edx, NiFixedString& name, const char* obj)
{
    if (!obj)
    {
        ((Stub*)(self + 8))->FUN_00aa0250(name);
        return;
    }
    ((Map*)(self + 8))->SetAt(name, obj);
}

class NiShader;
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern int EmptyFS;
struct Mgr;
struct Seq
{
    virtual void V0();
    virtual void Del();
    long refs;
    const char* name;
    char pad[0x34];
    Mgr* mgr;
    char pad2[0x18];
    int f5c;
    bool FUN_004eeae0(int);
    void FUN_0043b9f0(int*);
    bool FUN_00a32c70(int);
};
struct Owner
{
    int pad[0xb];
    int f2c;
};
struct Mgr2
{
    void FUN_00a2ec90(Seq**);
};
template <class A, class B> struct NiTStringTemplateMap
{
    void SetAt(const char*, B);
};
template <class K, class V> class NiTPointerMap;
typedef NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*> SMap;

// @fnv 0x00a2f0c0
bool __fastcall AttachSeqToOwner(Owner* pOwner, int edx, Seq* s, int* name, Seq* flag)
{
    if (pOwner && *(Owner**)((char*)s + 0x40))
        return false;
    *(Owner**)((char*)s + 0x40) = pOwner;
    if (s->f5c == 0)
        s->FUN_004eeae0(pOwner->f2c + 8);
    if ((char)(int)flag && !s->FUN_00a32c70(pOwner->f2c))
    {
        *(Owner**)((char*)s + 0x40) = 0;
        return false;
    }
    if (*name != EmptyFS)
        s->FUN_0043b9f0(name);
    flag = s;
    InterlockedIncrement(&s->refs);
    ((Mgr2*)((char*)pOwner + 0x34))->FUN_00a2ec90(&flag);
    if (InterlockedDecrement(&s->refs) == 0)
        s->Del();
    ((SMap*)((char*)pOwner + 0x50))->SetAt(s->name, (NiShader*)s);
    return true;
}

namespace fnv_00a2f850 {
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a2f850_shell : public NiControllerManager
{
    NiObject* FUN_00a2f850(CloningProcess*);
};

struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct FUN_00a2eed0_tgt
{
    FUN_00a2eed0_tgt* FUN_00a2eed0();
};
struct FUN_00a2f380_shell
{
    void CloneControllerManager(void*, CloningProcess*);
};

// @fnv 0x00a2f850
NiObject* FUN_00a2f850_shell::FUN_00a2f850(CloningProcess* kCloning)
{
    FUN_00a2eed0_tgt* mem = (FUN_00a2eed0_tgt*)BSFadeNode::operator new(0x7c);
    NiObject* pkObject;
    if (mem)
    {
        pkObject = (NiObject*)mem->FUN_00a2eed0();
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00a2f380_shell*)this)->CloneControllerManager(pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00a2f850

namespace fnv_00a2e2e0 {
struct FourComponentFloatVector;
struct NiAVObject;
struct NiBinaryStream;
struct CloningProcess;
struct NiCollisionObject;
struct NiCullingProcess;
struct NiDynamicEffectState;
struct NiExtraData;
struct NiNode;
struct NiObjectGroup;
struct NiObjectNET;
struct NiProperty;
struct NiPropertyState;
struct NiQuaternion;
struct NiRenderer;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a2e2e0_shell : public NiControllerManager
{
    void FUN_00a2e2e0(NiStream*);
};

struct Seq
{
    bool FUN_00a32c70(int);
};
struct LinkHack
{
    void LinkObject(NiStream&);
};
// @fnv 0x00a2e2e0
void FUN_00a2e2e0_shell::FUN_00a2e2e0(NiStream* kStream)
{
    ((LinkHack*)this)->LinkHack::LinkObject(*kStream);
    NiAVObject* pkRoot;
    unsigned int ui;
    NiControllerSequence* pkSequence;
    pkRoot = *(NiAVObject**)((char*)this + 0x2c);
    for (ui = 0; ui < *(unsigned short*)((char*)this + 0x3e); ui++)
    {
        pkSequence = (*(NiControllerSequence***)((char*)this + 0x38))[ui];
        if (pkSequence)
            ((Seq*)pkSequence)->FUN_00a32c70((int)pkRoot);
    }
}
}  // namespace fnv_00a2e2e0

namespace fnv_00a2e4d0 {
struct NiTMapBaseStub
{
    void __thiscall RemoveAll();
};
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_01096124;
struct TargetStandIn
{
    int _00;
    int _04;
    void* _08;
    void* __thiscall FUN_00a2e4d0(unsigned int);
};
// Resets the vtable, removes all map entries, frees the _08 pointer, and optionally deallocates the object when aFlag has bit 0 set.
// @fnv 0x00a2e4d0
void* __thiscall TargetStandIn::FUN_00a2e4d0(unsigned int aFlag)
{
    *(void**)this = (void*)&DAT_01096124;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(_08);
    if (aFlag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a2e4d0

namespace fnv_00a2e510 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_01096124;
extern int DAT_01096144;
struct FUN_00a2e510_Stub
{
    void* DestroyNiTMapBase(unsigned int);
};
// Resets two vtable pointers, calls RemoveAll on each, frees the pointer at offset 8, and deallocates this when a2 has bit 0 set.
// @fnv 0x00a2e510
void* FUN_00a2e510_Stub::DestroyNiTMapBase(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_01096144;
    ((NiTMapBaseStub*)this)->RemoveAll();
    *(void**)this = (void*)&DAT_01096124;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a2e510

struct BSFadeNode
{
    void* operator new(unsigned int);
    void* FUN_00a2eed0();
};
// @fnv 0x00a2f6c0
void* __cdecl FUN_00a2f6c0()
{
    BSFadeNode* p = (BSFadeNode*)BSFadeNode::operator new(0x7c);
    if (p)
        return p->FUN_00a2eed0();
    return 0;
}

namespace fnv_00a2eb40 {
void _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_01096114;
extern int DAT_0109618c;
struct NiTFixedStringMap_NiAVObject___
{
    void RemoveAll();
    void* FUN_00a2eb40(unsigned int);
};
// @fnv 0x00a2eb40
void* NiTFixedStringMap_NiAVObject___::FUN_00a2eb40(unsigned int auiFlags)
{
    *(void**)this = &DAT_0109618c;
    RemoveAll();
    *(void**)this = &DAT_01096114;
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a2eb40

namespace fnv_00a2efa0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
void __fastcall FUN_00a6d220(void*);
extern void* DAT_0109619c;
extern void* DAT_01096258;
extern void* DAT_01096124;
extern void* DAT_01096260;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct NiTimeCtlrStandin
{
    void SetTarget(NiObjectNET*);
};
struct CtrlRefObj
{
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    CtrlRefObj* FUN_00a2ed80(NiObjectNET*, int);
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct S00a414f0
{
    S00a414f0* FUN_00a414f0();
};
struct CtrlPtr
{
    CtrlRefObj* m_pObject;
    CtrlPtr& operator=(CtrlRefObj* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
struct NiTArrayStandin
{
    void** m_ppVirtualMethodTable;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void Construct(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usGrowBy == 0)
            m_usGrowBy = 1;
        if (m_usMaxSize > 0)
            m_pBase = _NiMalloc(m_usMaxSize * 4);
        else
            m_pBase = 0;
        m_ppVirtualMethodTable = (void**)&DAT_01096258;
    }
};
struct NiTMapStandin
{
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppHashTable;
    unsigned int m_uiCount;
    unsigned char m_kItemCount;
    void Construct(unsigned int uiHashSize)
    {
        m_ppVirtualMethodTable = (void**)&DAT_01096124;
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        m_ppHashTable = _NiMalloc(uiHashSize * 4);
        fnv_zlib_memset(m_ppHashTable, 0, m_uiHashSize * 4);
        m_kItemCount = 0;
        m_ppVirtualMethodTable = (void**)&DAT_01096260;
    }
};
struct NiListStandin
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void Construct()
    {
        m_pkHead = 0;
        m_pkTail = 0;
        m_uiCount = 0;
    }
};
struct S00a2efa0
{
    void** m_ppVirtualMethodTable;
    char pad04[0x30];
    NiTArrayStandin m_kSeqArray;
    unsigned int m_u44;
    unsigned int m_u48;
    unsigned int m_u4c;
    NiTMapStandin m_kFormatEntries;
    S00a414f0* m_pkLookup;
    bool m_bUseCumulativeAnimation;
    char pad69[3];
    NiListStandin m_kList;
    CtrlPtr m_spControllerManager;
    S00a2efa0* FUN_00a2efa0(NiObjectNET* pkTarget, bool bCumulative);
};

// @fnv 0x00a2efa0
S00a2efa0* S00a2efa0::FUN_00a2efa0(NiObjectNET* pkTarget, bool bCumulative)
{
    FUN_00a6d220(this);
    m_ppVirtualMethodTable = (void**)&DAT_0109619c;
    m_kSeqArray.Construct(0, 10);
    m_u44 = 0;
    m_u48 = 0;
    m_u4c = 0;
    m_kFormatEntries.Construct(0x25);
    m_bUseCumulativeAnimation = bCumulative;
    m_kList.Construct();
    m_spControllerManager.m_pObject = 0;
    ((NiTimeCtlrStandin*)this)->SetTarget(pkTarget);
    void* pControllerMem = BSFadeNode::operator new(0x1c);
    m_spControllerManager = pControllerMem ? ((CtrlRefObj*)pControllerMem)->FUN_00a2ed80(pkTarget, 0x4f) : 0;
    void* pLookupMem = g_memoryManager.Allocate(0x10);
    m_pkLookup = pLookupMem ? ((S00a414f0*)pLookupMem)->FUN_00a414f0() : 0;
    return this;
}
}  // namespace fnv_00a2efa0

namespace fnv_00a2f6e0 {
struct NiAVObject;
struct NiBinaryStream;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a2f6e0_shell : public NiControllerManager
{
    void FUN_00a2f6e0(NiStream*);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* EmptyFS;

struct FS543
{
    char* m_kHandle;
    FS543& operator=(const FS543& o)
    {
        if (m_kHandle != o.m_kHandle)
        {
            char* h = o.m_kHandle;
            if (h != EmptyFS)
                InterlockedIncrement((long*)(h - 8));
            if (m_kHandle != EmptyFS)
                InterlockedDecrement((long*)(m_kHandle - 8));
            m_kHandle = h;
        }
        return *this;
    }
};
extern FS543 DAT_011f49e0;

struct NiStream
{
    void* GetLoadedObject();
    unsigned int GetLinkID();
};
struct CtrlHelper543
{
    void LinkObject(NiStream&);
};
struct Obj543
{
    char pad00[8];
    FS543 m_kName;
};
struct Mgr543;
struct Seq543
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    FS543 m_kName;
    char pad0c[0x34];
    Mgr543* m_pkOwnerManager;
    char pad44[0x18];
    FS543 m_kAccumulationRootName;
};
struct SP543
{
    Seq543* m_pObject;
    SP543(Seq543* p) : m_pObject(p)
    {
        InterlockedIncrement(&p->m_uiRefCount);
    }
    ~SP543()
    {
        if (InterlockedDecrement(&m_pObject->m_uiRefCount) == 0)
            m_pObject->DeleteThis();
    }
};
struct Mgr2
{
    void FUN_00a2ec90(Seq543**) throw();
    void SetSize(unsigned int);
};
struct Map543
{
    void SetAt(const char*, Seq543*);
};
struct Mgr543
{
    char pad00[0x2c];
    Obj543* m_pkTarget;
    char pad30[4];
    Mgr2 m_kSequences;
    char pad35[0x1b];
    Map543 m_kObjectMap;
};

// @fnv 0x00a2f6e0
void FUN_00a2f6e0_shell::FUN_00a2f6e0(NiStream* kStream)
{
    Mgr543* pkThis = (Mgr543*)this;
    ((CtrlHelper543*)this)->LinkObject(*kStream);
    unsigned int uiNumSequences = kStream->GetLinkID();
    pkThis->m_kSequences.SetSize(uiNumSequences);
    for (unsigned int ui = 0; ui < uiNumSequences; ui++)
    {
        Seq543* pkSequence = (Seq543*)kStream->GetLoadedObject();
        if (pkThis && pkSequence->m_pkOwnerManager)
            continue;
        pkSequence->m_pkOwnerManager = pkThis;
        if (!pkSequence->m_kAccumulationRootName.m_kHandle)
            pkSequence->m_kAccumulationRootName = pkThis->m_pkTarget->m_kName;
        if (DAT_011f49e0.m_kHandle != EmptyFS)
            pkSequence->m_kName = DAT_011f49e0;
        Seq543* pSequenceRef = pkSequence;
        InterlockedIncrement(&pkSequence->m_uiRefCount);
        pkThis->m_kSequences.FUN_00a2ec90(&pSequenceRef);
        if (InterlockedDecrement(&pkSequence->m_uiRefCount) == 0)
            pkSequence->DeleteThis();
        pkThis->m_kObjectMap.SetAt(pkSequence->m_kName.m_kHandle, pkSequence);
    }
}
}  // namespace fnv_00a2f6e0

extern int DAT_01096164;
extern int DAT_01096144;
extern int DAT_01096124;

void __cdecl FUN_00aa10f0(void* p);
void __fastcall FUN_00b601a0(void* self);

struct FUN_00a2e460_node
{
    FUN_00a2e460_node* m_pkNext;
    void* m_pvVal;
};

struct FUN_00a2e460_cls
{
    int* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    FUN_00a2e460_node** m_ppkHashTable;
    unsigned int unk0c;
    unsigned char m_bOwnsNodes;
    void DestroyHashTable();
};

// Frees each stored value in the hash table when nodes are owned, then releases the table and resets the vtable pointers.
// @fnv 0x00a2e460
void FUN_00a2e460_cls::DestroyHashTable()
{
    m_ppVirtualMethodTable = &DAT_01096164;
    if (m_bOwnsNodes != 0)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            FUN_00a2e460_node* node = m_ppkHashTable[i];
            while (node != 0)
            {
                FUN_00a2e460_node* cur = node;
                void* val = cur->m_pvVal;
                node = cur->m_pkNext;
                FUN_00aa10f0(val);
            }
        }
    }
    m_ppVirtualMethodTable = &DAT_01096144;
    FUN_00b601a0(this);
    m_ppVirtualMethodTable = &DAT_01096124;
    FUN_00b601a0(this);
    FUN_00aa10f0(m_ppkHashTable);
}

struct ItemBinding
{
    int m_iId;
    int unk04;
    int unk08;
    int unk0c;
};

struct Item
{
    virtual ~Item();
    virtual void DeleteThis();

    volatile long m_uiRefCount;
    int unk08;
    unsigned int m_uiBindingCount;
    int unk10;
    ItemBinding* m_pBindings;
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
    int m_iFlag;
};

class Registry
{
  public:
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
    Item** m_ppItems;
    unsigned short unk3c;
    unsigned short m_usItemCount;

    Item* __thiscall FindItemByBindingId(int aiSoundId, bool bFlag);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

Item::~Item()
{}

void Item::DeleteThis()
{}

// @fnv 0x00a2e570
Item* __thiscall Registry::FindItemByBindingId(int aiBindingId, bool abRequireFlag)
{
    unsigned int uiIndex = 0;

    while (uiIndex < m_usItemCount)
    {
        Item* pItem = m_ppItems[uiIndex];

        if (pItem != 0)
        {
            InterlockedIncrement(&pItem->m_uiRefCount);

            if (!abRequireFlag || pItem->m_iFlag != 0)
            {
                unsigned int uiBindingIndex = 0;

                while (uiBindingIndex < pItem->m_uiBindingCount)
                {
                    ItemBinding* pBinding = pItem->m_pBindings + uiBindingIndex;
                    int iBindingId = pBinding->m_iId;

                    if (iBindingId != 0 && iBindingId == aiBindingId)
                    {
                        if (InterlockedDecrement(&pItem->m_uiRefCount) == 0)
                        {
                            pItem->DeleteThis();
                        }

                        return pItem;
                    }

                    ++uiBindingIndex;
                }
            }

            if (InterlockedDecrement(&pItem->m_uiRefCount) == 0)
            {
                pItem->DeleteThis();
            }
        }

        ++uiIndex;
    }

    return 0;
}

struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};

struct NiStreamImpl
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
    virtual void SaveLinkID(void* pkObject);
    char pad004[0x250 - 4];
    NiBinaryStreamStandIn* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiStreamImpl& stream, const T& value)
{
    stream.m_pBackingStream->Write(&value);
}

class FUN_00a2e9f0_cls
{
  public:
    char unk00[0x38];
    void** m_ppArray;
    char unk3c[2];
    unsigned short m_usArraySize;
    char unk40[0x68 - 0x40];
    bool m_bFlag;
    char unk69[0x78 - 0x69];
    void* m_pkLast;
    void FUN_00a6d730(NiStreamImpl& stream);
    void FUN_00a2e9f0(NiStreamImpl& stream);
};

// Calls FUN_00a6d730, writes m_bFlag and m_usArraySize, saves link IDs for each non-null m_ppArray entry and for m_pkLast.
// @fnv 0x00a2e9f0
void FUN_00a2e9f0_cls::FUN_00a2e9f0(NiStreamImpl& stream)
{
    FUN_00a6d730(stream);
    bool bFlag = m_bFlag;
    SerializeValue(stream, bFlag);
    unsigned int uiSize = m_usArraySize;
    SerializeValue(stream, uiSize);
    for (unsigned int i = 0; i < uiSize; i++)
    {
        void* pkObj = m_ppArray[i];
        if (pkObj)
            stream.SaveLinkID(pkObj);
    }
    stream.SaveLinkID(m_pkLast);
}

struct NiAVObject
{
    void FUN_00a64670();
    NiAVObjectPalette* FUN_00a64620();
};
void __stdcall FUN_00a6d5e0(NiAVObject*);
struct SequenceNotifier
{
    void* unk00;
    int m_uiPending;
    int(__cdecl* m_pfnNotify)(SequenceNotifier*, unsigned char*, int, int*, int);
};
struct NiControllerManagerFacade : NiControllerManager
{
    void FUN_00a2eaa0(NiAVObject* source);
};
// @fnv 0x00a2eaa0
void NiControllerManagerFacade::FUN_00a2eaa0(NiAVObject* source)
{
    FUN_00a6d5e0(source);
    SequenceNotifier* notifier = *reinterpret_cast<SequenceNotifier**>(reinterpret_cast<char*>(source) + 0x24c);
    {
        int isActive = 1;
        unsigned char firstOutput;
        notifier->m_uiPending += notifier->m_pfnNotify(notifier, &firstOutput, 1, &isActive, 1);
        m_bUseCumulativeAnimation = firstOutput != 0;
    }
    source->FUN_00a64670();
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(source) + 0xd8) >= 0x0a010068u)
    {
        NiAVObjectPalette* replacement = source->FUN_00a64620();
        NiAVObjectPalette* old = m_spControllerManager.m_pObject;
        if (old != replacement)
        {
            if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(old) + 4)) == 0)
                reinterpret_cast<NiRefObject*>(old)->DeleteThis();
            m_spControllerManager.m_pObject = replacement;
            if (replacement)
                InterlockedIncrement(reinterpret_cast<volatile long*>(reinterpret_cast<char*>(replacement) + 4));
        }
    }
}

struct NiCtrlVt
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
    virtual void v21(int);
};

struct FnvStandInA
{
    bool FUN_00a6d0f0(int arg);
};

struct FnvStandInB
{
    int* FUN_00a2ed80(int arg1, int arg2);
};

void* __cdecl FUN_00aa13e0(unsigned int size);

struct FUN_00a2f610_cls : public NiControllerManager
{
    bool FUN_00a2f610(int arg);
};

// @fnv 0x00a2f610
bool FUN_00a2f610_cls::FUN_00a2f610(int arg)
{
    if (!((FnvStandInA*)this)->FUN_00a6d0f0(arg))
    {
        return false;
    }
    for (unsigned int i = 0; i < m_kSequences.m_usSize; i++)
    {
        NiCtrlVt* seq = (NiCtrlVt*)m_kSequences.m_pBase[i].m_pObject;
        if (seq)
        {
            seq->v21(arg);
        }
    }
    NiCtrlVt* pPalette = (NiCtrlVt*)m_spControllerManager.m_pObject;
    if (pPalette)
    {
        pPalette->v21(arg);
        return true;
    }

    NiRefObject* pNewPalette;
    void* mem = FUN_00aa13e0(0x1c);
    if (mem != 0)
    {
        int owner = (int)m_pkTarget;
        pNewPalette = (NiRefObject*)((FnvStandInB*)mem)->FUN_00a2ed80(owner, 0x25);
    }
    else
    {
        pNewPalette = 0;
    }
    NiRefObject* old = (NiRefObject*)m_spControllerManager.m_pObject;
    if (old != pNewPalette)
    {
        if (old)
        {
            if (InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
            {
                old->DeleteThis();
            }
        }
        m_spControllerManager.m_pObject = (NiAVObjectPalette*)pNewPalette;
        if (pNewPalette)
        {
            InterlockedIncrement((volatile long*)&pNewPalette->m_uiRefCount);
        }
    }
    return true;
}

// FUN_00a414f0
//
// NiTPrimitiveArray<BSAnimNoteListener*>::NiTPrimitiveArray()
//
// The constructor of the derived array class.  Its body is empty: the whole
// work is done by the (inlined) NiTArray<T, Allocator> base constructor, which
// resets the array bookkeeping members
//
//     +0x04  T*            m_pBase       (cleared)
//     +0x08  unsigned short m_usMaxSize (cleared)
//     +0x0a  unsigned short m_usSize    (cleared)
//     +0x0c  unsigned short m_usESize   (cleared)
//     +0x0e  unsigned short m_usGrowBy  (set to 1)
//
// and the derived constructor then installs the derived vtable pointer in the
// freshly created object (slot +0x00).
//
// The two classes below are stand-ins for
//     NiTArray<BSAnimNoteListener*, NiTMallocInterface<BSAnimNoteListener*> >
//     NiTPrimitiveArray<BSAnimNoteListener*>
// only the member layout matters here, the base constructor is inlined into the
// derived one and the derived vtable pointer is written through the returned
// object pointer (EAX).

class NiTArrayStandIn
{
  public:
    virtual ~NiTArrayStandIn();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    NiTArrayStandIn();
};

NiTArrayStandIn::NiTArrayStandIn()
{
    m_usMaxSize = 0;
    m_usGrowBy = 1;
    m_usSize = 0;
    m_usESize = 0;
    m_pBase = 0;
}

class FUN_00a414f0_NiTPrimitiveArray : public NiTArrayStandIn
{
  public:
    virtual ~FUN_00a414f0_NiTPrimitiveArray();
    FUN_00a414f0_NiTPrimitiveArray();
};

// Default constructor for the primitive array; the base NiTArray constructor initializes the array fields.
// @fnv 0x00a414f0
FUN_00a414f0_NiTPrimitiveArray::FUN_00a414f0_NiTPrimitiveArray()
{}

struct FNV_MapItem
{
    FNV_MapItem* m_pkNext;
    const char* m_pcKey;
    void* m_pkValue;
};
struct FNV_MapView
{
    void* m_pVtable;
    unsigned int m_uiHashSize;
    FNV_MapItem** m_ppkHashTable;
    __forceinline FNV_MapItem* GetFirstPos()
    {
        const unsigned int count = m_uiHashSize;
        unsigned int i = 0;
        if (count > 0)
        {
            FNV_MapItem** buckets = m_ppkHashTable;
            FNV_MapItem** current = buckets;
            do
            {
                if (*current != 0)
                    return buckets[i];
                ++i;
                ++current;
            } while (i < count);
        }
        return 0;
    }
    void AdvanceToNextEntry(FNV_MapItem** position, const char** key, void** value);
    bool GetAt(const char* key, void** value);
};
struct FNV_Comparable
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
    virtual bool FUN_00a6cc80(FNV_Comparable* rhs);
};
struct FNV_EqualBase
{
    bool FUN_00a6cc80(FNV_EqualBase* rhs);
};
struct FUN_00a2e320_shell : NiControllerManager
{
    bool FUN_00a2e320(FUN_00a2e320_shell* rhs);
};

// Compares this controller manager with rhs: base equality, map entries by key, then each object pointer pair, returning false on any mismatch.
// @fnv 0x00a2e320
bool FUN_00a2e320_shell::FUN_00a2e320(FUN_00a2e320_shell* apOther)
{
    FUN_00a2e320_shell* other = apOther;
    if (!reinterpret_cast<FNV_EqualBase*>(this)->FUN_00a6cc80(reinterpret_cast<FNV_EqualBase*>(other)))
        return false;
    if (m_kSequences.m_usSize != other->m_kSequences.m_usSize)
        return false;

    FNV_MapView* map = reinterpret_cast<FNV_MapView*>(&m_kObjectMap);
    FNV_MapItem* position = map->GetFirstPos();
    while (position != 0)
    {
        const char* key;
        FNV_Comparable* item;
        FNV_Comparable* matchedItem;
        FNV_MapView* otherMap = reinterpret_cast<FNV_MapView*>(&other->m_kObjectMap);
        map->AdvanceToNextEntry(&position, &key, reinterpret_cast<void**>(&item));
        if (!otherMap->GetAt(key, reinterpret_cast<void**>(&matchedItem)))
            return false;
        if (!item->FUN_00a6cc80(matchedItem))
            return false;
    }

    for (unsigned int j = 0; j < m_kSequences.m_usSize; ++j)
    {
        FNV_Comparable* left = reinterpret_cast<FNV_Comparable*>(m_kSequences.m_pBase[j].m_pObject);
        FNV_Comparable* right = reinterpret_cast<FNV_Comparable*>(other->m_kSequences.m_pBase[j].m_pObject);
        if (left != 0 && right != 0)
        {
            if (!left->FUN_00a6cc80(right))
                return false;
        }
        else if (left != right)
        {
            return false;
        }
    }
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct CloneProc;

struct CObj
{
    virtual void v00();
    virtual void DeleteThis() throw();
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
    virtual void ProcessClone(CloneProc& kCloning);
    volatile long m_uiRefCount;
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct SPtr
{
    T* m_pObject;
    SPtr(T* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    SPtr& operator=(const SPtr& o)
    {
        if (m_pObject != o.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = o.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

template <class T> struct CSet
{
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    __declspec(nothrow) void Realloc(unsigned int uiNewSize);
    __forceinline unsigned int Add(const T& element) throw()
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            Realloc(m_uiElementCount > 0 ? (2 * m_uiElementCount) : 1);
        m_pBase[m_uiAllocatedCapacity++] = element;
        return m_uiAllocatedCapacity - 1;
    }
};

struct CMapItem
{
    CMapItem* m_pkNext;
    CObj* m_key;
    CObj* m_val;
};

struct CMap
{
    virtual void v00();
    virtual unsigned int KeyToHashIndex(CObj* key) const;
    virtual bool IsKeysEqual(CObj* key1, CObj* key2) const;
    unsigned int m_uiHashSize;
    CMapItem** m_ppkHashTable;
    bool GetAt(CObj* const key, CObj*& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        CMapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};

struct CloneProc
{
    CMap* m_pCloneMap;
};

struct CSeq : CObj
{
    bool FUN_00a32c70(int);
};

struct CTimeCtrlBase : CObj
{
    void ProcessCloneBase(CloneProc& kCloning);
};

struct CArrayHdr
{
    void* vtbl;
    SPtr<CSeq>* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
};

struct CCtrlMgr : CTimeCtrlBase
{
    unsigned short m_uiObjectFlags;
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    int m_pkTarget;
    int m_spNextController;
    CArrayHdr m_kSequences;
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
    CSet<SPtr<CSeq> > m_kSequenceSet;
    SPtr<CObj> m_spControllerManager;
    void FUN_00a2f420(CloneProc& kCloning);
};

// @fnv 0x00a2f420
void CCtrlMgr::FUN_00a2f420(CloneProc& kCloning)
{
    ProcessCloneBase(kCloning);
    for (unsigned int ui = 0; ui < m_kSequences.GetSize(); ui++)
    {
        CSeq* pkSeq = m_kSequences.m_pBase[ui];
        if (pkSeq)
        {
            pkSeq->ProcessClone(kCloning);
            pkSeq->FUN_00a32c70(m_pkTarget);
        }
    }

    CCtrlMgr* pkDest;
    {
        CObj* pkClone = 0;
        kCloning.m_pCloneMap->GetAt(this, pkClone);
        pkDest = (CCtrlMgr*)pkClone;
    }

    for (unsigned int ui = 0; ui < m_kSequenceSet.m_uiAllocatedCapacity; ui++)
    {
        CObj* pkSeqClone;
        CSeq* pkSeq = m_kSequenceSet.m_pBase[ui];
        if (kCloning.m_pCloneMap->GetAt(pkSeq, pkSeqClone))
            pkDest->m_kSequenceSet.Add((CSeq*)pkSeqClone);
        else
            pkDest->m_kSequenceSet.Add(m_kSequenceSet.m_pBase[ui]);
    }

    if (m_spControllerManager)
        m_spControllerManager->ProcessClone(kCloning);
}

struct CtrlSeqOwner
{
    void FUN_00a2e7d0(NiRefObject* pkObject, NiRefObject** ppkOut);
    void ReleaseObject(NiRefObject* pkObject);
};

// Looks up pkObject via FUN_00a2e7d0 and releases the returned NiRefObject, calling DeleteThis when its ref count reaches zero.
// @fnv 0x00a2ec50
void CtrlSeqOwner::ReleaseObject(NiRefObject* pkObject)
{
    NiRefObject* pkFound = 0;
    FUN_00a2e7d0(pkObject, &pkFound);
    NiRefObject* pkRef = *(NiRefObject* volatile*)&pkFound;
    if (pkRef)
    {
        if (InterlockedDecrement((volatile long*)&pkRef->m_uiRefCount) == 0)
            pkRef->DeleteThis();
    }
}

namespace sa2e280 {

class Sequence
{
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
    virtual void Deactivate(float fTime, int iFlags);

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
    int m_iActive;

    bool StartSequence(int iArg0, int iArg1, float fDuration, float fTime, int iArg2, int iArg3);
};

// Deactivates pkSource and starts pkDest with the given arguments when pkSource is active and pkDest is not.
// @fnv 0x00a2e280
bool __stdcall FUN_00a2e280(Sequence* pkSource, Sequence* pkDest, float fTime, int iArg0, int iArg1, float fDuration,
                            int iArg2)
{
    if (!pkSource->m_iActive || pkDest->m_iActive)
        return false;
    pkSource->Deactivate(fTime, 0);
    return pkDest->StartSequence(iArg0, iArg1, fDuration, fTime, iArg2, 0);
}

}

namespace fnv_00a2ec90 {
typedef NiControllerSequence Seq;

inline void AcquireReference(NiRefObject* o)
{
    InterlockedIncrement((volatile long*)&o->m_uiRefCount);
}
inline void DecRef(NiRefObject* o)
{
    if (InterlockedDecrement((volatile long*)&o->m_uiRefCount) == 0)
        o->DeleteThis();
}

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    NiPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            AcquireReference(m_pObject);
    }
    ~NiPtr()
    {
        if (m_pObject)
            DecRef(m_pObject);
    }
    bool operator==(const NiPtr& p) const
    {
        return m_pObject == p.m_pObject;
    }
    bool operator!=(T* p) const
    {
        return m_pObject != p;
    }
    NiPtr& operator=(const NiPtr& o)
    {
        if (m_pObject != o.m_pObject)
        {
            if (m_pObject)
                DecRef(m_pObject);
            m_pObject = o.m_pObject;
            if (m_pObject)
                AcquireReference(m_pObject);
        }
        return *this;
    }
};

class SeqArr
{
  public:
    virtual ~SeqArr();
    NiPtr<Seq>* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, const NiPtr<Seq>&);
    unsigned int FUN_00a2ec90(const NiPtr<Seq>& element);
};

// @fnv 0x00a2ec90
unsigned int SeqArr::FUN_00a2ec90(const NiPtr<Seq>& element)
{
    if (element == 0)
        return 0xffffffff;

    if (m_usESize < m_usSize)
    {
        unsigned short uiIndex = m_usSize;
        for (short i = (short)(m_usSize - 1); i >= 0; i--)
        {
            if (m_pBase[i] == 0)
                uiIndex = i;
            else if ((short)uiIndex != m_usSize)
                break;
        }
        int iSlot = (short)uiIndex;
        if (iSlot != m_usSize)
        {
            m_pBase[iSlot] = element;
            m_usESize++;
            return iSlot;
        }
    }

    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
}  // namespace fnv_00a2ec90

namespace fnv_00a2f170 {
class S00a2f170_Seq;
extern const char* __cdecl FUN_00a5b690(const char*);

class S00a2f170_FS;
extern S00a2f170_FS DAT_0109b220;
class S00a2f170_FS
{
  public:
    const char* m_pString;
    S00a2f170_FS() throw()
    {}
    S00a2f170_FS& Make(const char* text) throw()
    {
        m_pString = FUN_00a5b690(text);
        return *this;
    }
    S00a2f170_FS(const S00a2f170_FS&) throw();
    ~S00a2f170_FS() throw();
    S00a2f170_FS& operator=(const S00a2f170_FS&) throw();
    S00a2f170_FS& operator=(const char*) throw();
    bool Exists() const
    {
        return m_pString != DAT_0109b220.m_pString;
    }
};
extern S00a2f170_FS DAT_0109b220;
extern S00a2f170_FS DAT_011f49e0;

inline S00a2f170_FS::S00a2f170_FS(const S00a2f170_FS& other) throw() : m_pString(other.m_pString)
{
    if (m_pString != DAT_0109b220.m_pString)
        InterlockedIncrement((volatile long*)(m_pString - 8));
}
inline S00a2f170_FS::~S00a2f170_FS() throw()
{
    if (m_pString != DAT_0109b220.m_pString)
        InterlockedDecrement((volatile long*)(m_pString - 8));
}
inline S00a2f170_FS& S00a2f170_FS::operator=(const S00a2f170_FS& other) throw()
{
    if (m_pString != other.m_pString)
    {
        const char* incoming = other.m_pString;
        if (incoming != DAT_0109b220.m_pString)
            InterlockedIncrement((volatile long*)(incoming - 8));
        if (m_pString != DAT_0109b220.m_pString)
            InterlockedDecrement((volatile long*)(m_pString - 8));
        m_pString = incoming;
    }
    return *this;
}
inline S00a2f170_FS& S00a2f170_FS::operator=(const char* incoming) throw()
{
    if (m_pString != incoming)
    {
        if (incoming != DAT_0109b220.m_pString)
            InterlockedIncrement((volatile long*)(incoming - 8));
        if (m_pString != DAT_0109b220.m_pString)
            InterlockedDecrement((volatile long*)(m_pString - 8));
        m_pString = incoming;
    }
    return *this;
}

class S00a2f170_NET : public NiObject
{
  public:
    S00a2f170_FS m_kName;
};

template <class T> class S00a2f170_Ptr
{
  public:
    T* m_pObject;
    S00a2f170_Ptr(T*) throw();
    ~S00a2f170_Ptr() throw();
    S00a2f170_Ptr& operator=(const S00a2f170_Ptr&) throw();
    bool operator!() const
    {
        return m_pObject == 0;
    }
};

class S00a2f170_Seq : public NiObject
{
  public:
    S00a2f170_FS m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    void* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    S00a2f170_Seq* m_pkTimeSyncSequence;
    S00a2f170_FS m_kAccumulationRootName;
    void* m_pkAccumulationRoot;
    void* m_spStringPalette;
    short m_sAnimNotesExtraDataIndex;
    void* m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    bool m_bHasAnimNotes;

    static void* FUN_00aa13e0(unsigned int);
    static void* operator new(unsigned int n) throw()
    {
        return FUN_00aa13e0(n);
    }
    void ReleaseItems();
    void FUN_00a32fa0(S00a2f170_Seq*, unsigned int, unsigned int, bool);
};

class FUN_00a32a10 : public S00a2f170_Seq
{
  public:
    FUN_00a32a10(const S00a2f170_FS&, unsigned int, unsigned int) throw();
};

class S00a2f170_SeqArray
{
  public:
    virtual ~S00a2f170_SeqArray();
    S00a2f170_Ptr<S00a2f170_Seq>* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    unsigned FUN_00a2ec90(const S00a2f170_Ptr<S00a2f170_Seq>&) throw();
    void FUN_00a47770(unsigned) throw();
    void FUN_00a2e680(unsigned, const S00a2f170_Ptr<S00a2f170_Seq>&) throw();
};
class S00a2f170_ActSet
{
  public:
    S00a2f170_Seq** m_pBase;
    unsigned m_uiElementCount, m_uiAllocatedCapacity;
};
class S00a2f170_TmpSet
{
  public:
    S00a2f170_Ptr<S00a2f170_Seq>* m_pBase;
    unsigned m_uiElementCount, m_uiAllocatedCapacity;
    void FUN_00e8ea60(const S00a2f170_Ptr<S00a2f170_Seq>&) throw();
    void FUN_00e8e3a0(unsigned) throw();
};
class S00a2f170_Map
{
  public:
    virtual ~S00a2f170_Map();
    unsigned m_uiHashSize;
    void* m_ppkHashTable;
    unsigned m_uiCount;
    unsigned unk10;
    void FUN_00a642a0(const char*, S00a2f170_Seq*);
};

class S00a2f170_Mgr : public NiObject
{
  public:
    unsigned short m_uiObjectFlags;
    float m_fFrequency, m_fPhase, m_fLoKeyTime, m_fHiKeyTime;
    float m_fStartTime, m_fLastTime, m_fWeightAdjustedLastTime, m_fControllerTime;
    S00a2f170_NET* m_pkTarget;
    void* m_spNextController;
    S00a2f170_SeqArray m_kSequences;
    S00a2f170_ActSet m_kPlayingSequences;
    S00a2f170_Map m_kObjectMap;
    void* m_pAudioListener;
    bool m_bUseCumulativeAnimation;
    S00a2f170_TmpSet m_kSequenceSet;
    void* m_spControllerManager;
    S00a2f170_Seq* GetTempBlendSequence(S00a2f170_Seq* source, unsigned int option);
};

template <class T> inline S00a2f170_Ptr<T>::S00a2f170_Ptr(T* object) throw() : m_pObject(object)
{
    if (m_pObject)
        InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
}
template <class T> inline S00a2f170_Ptr<T>::~S00a2f170_Ptr() throw()
{
    T* object = m_pObject;
    if (object && InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

template <class T> inline S00a2f170_Ptr<T>& S00a2f170_Ptr<T>::operator=(const S00a2f170_Ptr& other) throw()
{
    if (m_pObject != other.m_pObject)
    {
        T* old = m_pObject;
        if (old && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
            old->DeleteThis();
        m_pObject = other.m_pObject;
        if (m_pObject)
            InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
    }
    return *this;
}

inline void S00a2f170_TmpSet::FUN_00e8ea60(const S00a2f170_Ptr<S00a2f170_Seq>& value) throw()
{
    if (m_uiAllocatedCapacity == m_uiElementCount)
        FUN_00e8e3a0(m_uiElementCount ? m_uiElementCount * 2 : 1);
    m_pBase[m_uiAllocatedCapacity++] = value;
}

inline void S00a2f170_SeqArray::FUN_00a2e680(unsigned index, const S00a2f170_Ptr<S00a2f170_Seq>& value) throw()
{
    if (index >= m_usMaxSize)
        return;
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (!!value)
            ++m_usESize;
    }
    else
    {
        if (!!value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else
        {
            if (!!m_pBase[index])
                --m_usESize;
        }
    }
    m_pBase[index] = value;
}

inline unsigned S00a2f170_SeqArray::FUN_00a2ec90(const S00a2f170_Ptr<S00a2f170_Seq>& value) throw()
{
    if (!value)
        return (unsigned)-1;
    if (m_usESize < m_usSize)
    {
        short empty = (short)m_usSize;
        for (short i = (short)(m_usSize - 1); i >= 0; --i)
        {
            if (!m_pBase[i])
                empty = i;
            else if (empty != (short)m_usSize)
                break;
        }
        if (empty != (short)m_usSize)
        {
            m_pBase[empty] = value;
            ++m_usESize;
            return empty;
        }
    }
    unsigned index = m_usSize;
    if (index >= m_usMaxSize)
        FUN_00a47770(index + m_usGrowBy);
    FUN_00a2e680(index, value);
    return index;
}

// Finds or creates an inactive sequence, associates it with this manager, and passes it to a method on source.
// @fnv 0x00a2f170
S00a2f170_Seq* S00a2f170_Mgr::GetTempBlendSequence(S00a2f170_Seq* apSourceSequence, unsigned int option)
{
    S00a2f170_Seq* sequence = 0;
    unsigned int arraySize = apSourceSequence->m_uiNumControlledBlocks;
    for (unsigned int i = 0; i < m_kSequenceSet.m_uiAllocatedCapacity; ++i)
    {
        S00a2f170_Seq* item = m_kSequenceSet.m_pBase[i].m_pObject;
        if (item->m_eAnimationState == 0)
        {
            sequence = item;
            break;
        }
    }
    bool reused = false;
    if (!sequence)
    {
        sequence = new FUN_00a32a10(S00a2f170_FS().Make("__TempBlendSequence__"), arraySize, 12);
        m_kSequenceSet.FUN_00e8ea60(sequence);
        if (!sequence->m_pkOwnerManager)
        {
            sequence->m_pkOwnerManager = this;
            if (!sequence->m_kAccumulationRootName.m_pString)
                sequence->m_kAccumulationRootName = m_pkTarget->m_kName;
            if (DAT_011f49e0.Exists())
                sequence->m_kName = DAT_011f49e0;
            m_kSequences.FUN_00a2ec90(sequence);
            m_kObjectMap.FUN_00a642a0(sequence->m_kName.m_pString, sequence);
        }
    }
    else
    {
        sequence->ReleaseItems();
        if (!sequence->m_pkOwnerManager)
            sequence->m_pkOwnerManager = this;
        sequence->m_kAccumulationRootName = m_pkTarget->m_kName;
        reused = true;
    }
    apSourceSequence->FUN_00a32fa0(sequence, arraySize, option, reused);
    return sequence;
}
}  // namespace fnv_00a2f170

struct SeqTarget
{
    bool FUN_00a350d0(NiControllerSequence* seq, float a, float b, int c, float d, float e, int f);
};

SeqTarget* __stdcall GetTempBlendSequence(NiControllerSequence* seq, int key);

// If the sequence is inactive, look up the target by key and call its FUN_00a350d0 with the given parameters, returning the result.
// @fnv 0x00a2f800
bool __stdcall FUN_00a2f800(NiControllerSequence* seq, float a, float b, int c, int key)
{
    if (seq->m_eAnimationState != NiControllerSequence::INACTIVE)
    {
        return false;
    }
    SeqTarget* pTarget = GetTempBlendSequence(seq, key);
    return pTarget->FUN_00a350d0(seq, b, a, c, 1.0f, 1.0f, 0);
}

struct FUN_00a2e1f0 : NiRefObject
{
    virtual ~FUN_00a2e1f0();
    static void operator delete(void*, unsigned int);
};
// The destructor body is empty.
// @fnv 0x00a2e1f0
FUN_00a2e1f0::~FUN_00a2e1f0()
{}

namespace fnv_00a2eb80 {
void __cdecl ReleaseObjectArray(void*);
struct MemoryManager
{
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
struct FUN_00a2eb80
{
    void* m_04;
    virtual ~FUN_00a2eb80();
    static void operator delete(void* p);
};
// @fnv 0x00a2eb80
FUN_00a2eb80::~FUN_00a2eb80()
{
    ReleaseObjectArray(m_04);
}
void FUN_00a2eb80::operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}
}  // namespace fnv_00a2eb80

extern "C" void _ReadWriteBarrier(void);
void* __cdecl FUN_00aa1070(unsigned int size) throw();
void* __cdecl FUN_00ec61c0(void* p, int value, unsigned int size) throw();

struct MgrPoolStub
{
    void* Alloc(unsigned int size) throw();
};
extern MgrPoolStub DAT_011f6238;

struct MgrListenerStub
{
    void* Construct() throw();
};

struct MgrTimeBase
{
    MgrTimeBase() throw();
    virtual void v00();
    unsigned int m_unk04, m_unk08, m_unk0c, m_unk10, m_unk14, m_unk18;
    unsigned int m_unk1c, m_unk20, m_unk24, m_unk28, m_unk2c, m_unk30;
};

struct MgrBlendSet
{
    void* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    void* m_pObjectPalette;
};

struct MgrSetBase
{
    void* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

struct MgrArrayHead
{
    MgrArrayHead() throw()
    {
        m_pBase = 0;
    }
    void* m_pBase;
};

struct MgrArrayTail
{
    MgrArrayTail() throw()
    {
        m_usMaxSize = 0;
        m_usGrowBy = 10;
        m_usSize = 0;
        m_usESize = 0;
        m_kActive.m_pBase = 0;
        m_kActive.m_uiElementCount = 0;
        m_kActive.m_uiAllocatedCapacity = 0;
    }
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    volatile MgrSetBase m_kActive;
};

struct MgrTArrayView : MgrArrayHead
{
    virtual void v00();
    MgrArrayTail m_pTail;
};

struct MgrStrMapBase
{
    virtual void v00();
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    unsigned char m_ucPad60;
    unsigned char m_ucPad61, m_ucPad62, m_ucPad63;
    MgrStrMapBase() throw()
    {
        m_uiHashSize = 0x25;
        m_uiCount = 0;
        m_ppkHashTable = FUN_00aa1070(m_uiHashSize * 4);
        FUN_00ec61c0(m_ppkHashTable, 0, m_uiHashSize * 4);
        m_ucPad60 = 0;
    }
};

struct MgrStrMap : MgrStrMapBase
{
    virtual void v00();
};

struct DAT_0109619c : MgrTimeBase
{
    virtual void v00();
    DAT_0109619c() throw();
    MgrTArrayView m_aiIndexedValues;
    MgrStrMap m_map;
    void* m_pListener;
    volatile unsigned char m_bUseCumulativeAnimation;
    volatile MgrBlendSet m_kSequenceSet;
};

// Initializes the DAT_0109619c object by zeroing m_bUseCumulativeAnimation and m_kSequenceSet, then allocates and constructs m_pListener via DAT_011f6238.
// @fnv 0x00a2eed0
DAT_0109619c::DAT_0109619c() throw()
{
    m_bUseCumulativeAnimation = 0;
    _ReadWriteBarrier();
    m_kSequenceSet.m_pBase = 0;
    m_kSequenceSet.m_uiElementCount = 0;
    m_kSequenceSet.m_uiAllocatedCapacity = 0;
    m_kSequenceSet.m_pObjectPalette = 0;
    void* i = DAT_011f6238.Alloc(0x10);
    if (i != 0)
    {
        m_pListener = ((MgrListenerStub*)i)->Construct();
    }
    else
    {
        m_pListener = 0;
    }
}
