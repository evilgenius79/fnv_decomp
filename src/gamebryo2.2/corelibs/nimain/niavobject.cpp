
// src/gamebryo2.2/corelibs/nimain/niavobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niavobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];

struct NiAVObject
{
    void __thiscall UpdateTimeControllers(NiUpdateData&, bool);
};

struct FUN_00a5a030_shell : NiAVObject
{
    void __thiscall FUN_00a5a030(NiUpdateData& data);
};

// @fnv 0x00a5a030
void __thiscall FUN_00a5a030_shell::FUN_00a5a030(NiUpdateData& data)
{
    NiAVObject::UpdateTimeControllers(data, true);
}

extern char const* const g_011f4428_arg1;

// @fnv 0x00a5a420
char const* const* __cdecl FUN_00a5a420()
{
    return &g_011f4428_arg1;
}

extern const void* DAT_011f9140;

// @fnv 0x00b4e1d0
const void* __cdecl FUN_00b4e1d0()
{
    return &DAT_011f9140;
}

struct MemoryManager
{
    void* __thiscall Deallocate(void*);
};

extern MemoryManager g_memoryManager;

struct FUN_00a59dc0_shell
{
    void __thiscall SetBoundObject(void* apBound);
};

// @fnv 0x00a59dc0
void __thiscall FUN_00a59dc0_shell::SetBoundObject(void* apBound)
{
    unsigned char* pThis = reinterpret_cast<unsigned char*>(this);
    if (*(void**)(pThis + 0x20))
    {
        g_memoryManager.Deallocate(*(void**)(pThis + 0x20));
    }
    *(void**)(pThis + 0x20) = apBound;
    if (apBound)
    {
        *(unsigned int*)(pThis + 0x30) |= 0x80000;
    }
    else
    {
        *(unsigned int*)(pThis + 0x30) &= 0xfff7ffff;
    }
}

struct FUN_00a59c90_shell
{
    void __thiscall FUN_00a59c90(NiUpdateData&);
};
// Calls the object's vtable slot 42 with the update data, then, if the object at offset 0x18 exists, calls its vtable slot 63.
// @fnv 0x00a59c90
void __thiscall FUN_00a59c90_shell::FUN_00a59c90(NiUpdateData& aUpdateData)
{
    ((void(__thiscall*)(void*, void*, int))(*(int**)this)[42])(this, &aUpdateData, 0);
    if (*(int**)((char*)this + 0x18))
        ((void(__thiscall*)(void*))(*(int**)(*(int**)((char*)this + 0x18)))[63])(*(int**)((char*)this + 0x18));
}

struct NiNode;
struct FUN_00a59d00_shell
{
    void __thiscall SetParent(NiNode* pkParent);
};
typedef void(__thiscall* FUN_00a59d00_Fn)(NiNode*, void*);
// @fnv 0x00a59d00
void __thiscall FUN_00a59d00_shell::SetParent(NiNode* pkParent)
{
    NiNode* pkOldParent = *(NiNode**)((char*)this + 0x18);
    if (pkOldParent)
    {
        (*(FUN_00a59d00_Fn*)((char*)*(void**)pkOldParent + 0xe8))(pkOldParent, this);
        *(NiNode**)((char*)this + 0x18) = pkParent;
    }
    else
    {
        *(NiNode**)((char*)this + 0x18) = pkParent;
    }
}

struct Prop
{
};
struct NiRenderer
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
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
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61(Prop*) = 0;
};
struct PropHelper
{
    Prop* GetProperty(unsigned int);
    void __thiscall FUN_00a59e50(NiRenderer*);
};
// Retrieves property 2 and, if present, passes it to the renderer's v61 method.
// @fnv 0x00a59e50
void __thiscall PropHelper::FUN_00a59e50(NiRenderer* apkRenderer)
{
    Prop* pkProperty = GetProperty(2);
    if (pkProperty)
        apkRenderer->v61(pkProperty);
}

namespace fnv_00a59ec0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
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

struct NiObjectNET
{
    virtual void __thiscall _v00();
    virtual void __thiscall _v01();
    virtual void __thiscall _v02();
    virtual void __thiscall _v03();
    virtual void __thiscall _v04();
    virtual void __thiscall _v05();
    virtual void __thiscall _v06();
    virtual void __thiscall _v07();
    virtual void __thiscall _v08();
    virtual void __thiscall _v09();
    virtual void __thiscall _v10();
    virtual void __thiscall _v11();
    virtual void __thiscall _v12();
    virtual void __thiscall _v13();
    virtual void __thiscall _v14();
    virtual void __thiscall _v15();
    virtual void __thiscall _v16();
    virtual void __thiscall _v17();
    virtual void __thiscall _v18();
    virtual void __thiscall _v19();
    virtual void __thiscall _v20();
    virtual void __thiscall _v21();
    virtual void __thiscall _v22();
    virtual void __thiscall _v23();
    virtual void __thiscall _v24();
    virtual void __thiscall _v25();
    virtual void ProcessClone(CloningProcess&);
};
struct S59ec0
{
    char _p0[0x1c];
    NiObjectNET* m_spCollision;
    char _p1[0x4];
    int m_kNode[3];
    void __thiscall FUN_00a59e70(void* a, CloningProcess& b);
    void __thiscall FUN_00a59ec0(CloningProcess& b);
};
// @fnv 0x00a59ec0
void __thiscall S59ec0::FUN_00a59ec0(CloningProcess& kCloning)
{
    ((NiObjectNET*)(void*)this)->NiObjectNET::ProcessClone(kCloning);
    if (m_kNode[2])
        FUN_00a59e70(m_kNode, kCloning);
    NiObjectNET* pkCollision = m_spCollision;
    if (pkCollision)
        pkCollision->ProcessClone(kCloning);
}
}  // namespace fnv_00a59ec0

struct GO
{
    void* ptr;
    GO& operator=(void*);
};
struct Param
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
    virtual int Get();
};
struct Owner
{
    GO arr[8];
    void __thiscall SetSlot(Param* p);
};
// If p is non-null and p->Get() is at most 7, stores p into arr at index p->Get().
// @fnv 0x00a59f50
void __thiscall Owner::SetSlot(Param* pParam)
{
    if (pParam && pParam->Get() <= 7)
        arr[pParam->Get()] = pParam;
}

struct FUN_00a59f90_holder
{
    void __thiscall FUN_00a59f90(NiUpdateData&, unsigned int);
};
// @fnv 0x00a59f90
void __thiscall FUN_00a59f90_holder::FUN_00a59f90(NiUpdateData& kData, unsigned int uiFlags)
{
    if (kData.m_bUpdateEnabled)
        ((NiAVObject*)this)->UpdateTimeControllers(kData, true);
    ((void(__thiscall*)(void*, NiUpdateData&))(*(void***)this)[46])(this, kData);
    ((void(__thiscall*)(void*))(*(void***)this)[47])(this);
}

struct T00a5a0e0
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
    virtual bool v39() = 0;
    char _p04[8];
    T00a5a0e0* m_pHeadNode;
    char _p10[32];
    T00a5a0e0* m_next;
    bool __thiscall FUN_00a5a0e0();
};
// @fnv 0x00a5a0e0
bool __thiscall T00a5a0e0::FUN_00a5a0e0()
{
    T00a5a0e0* p = m_pHeadNode;
    while (p)
    {
        if (p->v39())
            return true;
        p = p->m_next;
    }
    return false;
}

struct DataA
{
    char _pad[12];
    int v;
};
struct NodeA
{
    NodeA* next;
    int unk;
    DataA* d;
};
struct S_00a5a110
{
    char _pad[36];
    NodeA* head;
    bool __thiscall HasNodeWithNonZeroValue();
};
// Walks the linked list from head and returns true if any node's DataA has a non-zero v, otherwise false.
// @fnv 0x00a5a110
bool __thiscall S_00a5a110::HasNodeWithNonZeroValue()
{
    NodeA* pNode = head;
    while (pNode)
    {
        DataA** pp = (DataA**)((int*)pNode + 2);
        pNode = pNode->next;
        DataA* d = *pp;
        if (d && d->v)
            return true;
    }
    return false;
}

void __fastcall FUN_00a5a390(void*);
void __cdecl _delete(void*, unsigned int);
struct FUN_00a5aa90_shell
{
    void* __thiscall FUN_00a5aa90(unsigned int);
};
// Calls FUN_00a5a390 on this, frees this with _delete when bit 0 of a1 is set, and returns this.
// @fnv 0x00a5aa90
void* __thiscall FUN_00a5aa90_shell::FUN_00a5aa90(unsigned int auiFlags)
{
    FUN_00a5a390(this);
    if (auiFlags & 1)
        _delete(this, 0x9c);
    return this;
}

struct NiNode;
struct Holder00a59cc0
{
    char _pad[20];
    NiNode* m_parent;
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
    virtual void Target(NiUpdateData&, bool) = 0;
    void __thiscall UpdateWithParent(NiNode* pEventualParent, NiUpdateData& UpdateData);
};
// Sets m_parent to pEventualParent, calls Target(UpdateData, false), then clears m_parent.
// @fnv 0x00a59cc0
void __thiscall Holder00a59cc0::UpdateWithParent(NiNode* pEventualParent, NiUpdateData& UpdateData)
{
    m_parent = pEventualParent;
    Target(UpdateData, false);
    m_parent = 0;
}

struct FUN_00a59db0_shell
{
    char _pad_0[0x18];
    int _field_0x18;
    void __thiscall FUN_00a59db0(int arg);
};

// @fnv 0x00a59db0
void __thiscall FUN_00a59db0_shell::FUN_00a59db0(int arg)
{
    _field_0x18 = 0;
}

namespace fnv_00a59e20 {
extern int EmptyFS;

struct NiAVObject
{
    char _pad_0[1];
    int FUN_00a59e20(int param);
};

// @fnv 0x00a59e20
int NiAVObject::FUN_00a59e20(int param)
{
    int handle = *reinterpret_cast<int*>(param);
    if (handle == EmptyFS)
        return 0;
    int diff = *reinterpret_cast<int*>(this + 8) != handle;
    return (diff - 1) & reinterpret_cast<int>(this);
}
}  // namespace fnv_00a59e20

namespace fnv_00a5a430 {
struct NiNode;

struct NiAVObject
{
    char _pad_0[0x14];
    NiNode* m_pEventualParent;
    virtual void UpdateSceneObject(void);
    void SetEventualParent(NiNode* pEventualParent);
};

// @fnv 0x00a5a430
void NiAVObject::SetEventualParent(NiNode* pEventualParent)
{
    this->m_pEventualParent = pEventualParent;
    NiAVObject::UpdateSceneObject();
    this->m_pEventualParent = 0;
}
}  // namespace fnv_00a5a430

class A59CF0Node
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void UpdateSceneObject();
};

class A59CF0Holder
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    A59CF0Node* m_pkNode;

    void FUN_00a59cf0();
};

// @fnv 0x00a59cf0
void A59CF0Holder::FUN_00a59cf0()
{
    m_pkNode->UpdateSceneObject();
}

struct FUN_00a59d80_cls
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
    virtual void v45() = 0;
    virtual void v46(void* pArg) = 0;
    virtual void v47() = 0;
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
    unsigned int m_flags;
    void __thiscall FUN_00a59d80(void* pArg);
};

// If bit 2 of m_flags is set, calls v46 with pArg and then v47.
// @fnv 0x00a59d80
void __thiscall FUN_00a59d80_cls::FUN_00a59d80(void* pArg)
{
    unsigned char flags = (unsigned char)(m_flags >> 2);
    if (flags & 1)
    {
        v46(pArg);
        v47();
    }
}

struct S_00a59e00;
struct S_00a59e00_Arg
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1c();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2c();
    virtual int v30();
    virtual int v34();
    virtual int v38();
    virtual int v3c();
    virtual int v40();
    virtual void FUN_44(S_00a59e00* p);
};
struct S_00a59e00
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
    unsigned char flags;
    void FUN_00a59e00(S_00a59e00_Arg* a);
};
// @fnv 0x00a59e00
void S_00a59e00::FUN_00a59e00(S_00a59e00_Arg* a)
{
    if (!(flags & 1))
        a->FUN_44(this);
}

struct ItemBase
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
    virtual void v26(void* arg) = 0;
};

struct ListNode
{
    unsigned int unk00;
    ListNode* m_04;
    ItemBase* m_08;
};

struct ListOwner
{
    unsigned int unk00;
    ListNode* m_04;
};

struct Filter
{
    bool __thiscall FUN_00b63170(ItemBase* item, ListOwner*& owner);
};

struct Holder
{
    unsigned int unk00;
    Filter* m_04;
};

inline ItemBase* const& GetNext(ListNode*& pos)
{
    ItemBase* const& element = pos->m_08;
    pos = pos->m_04;
    return element;
}

// @fnv 0x00a59e70
void __stdcall FUN_00a59e70(ListOwner* owner, Holder* holder)
{
    ListNode* node = owner->m_04;
    while (node != 0)
    {
        ItemBase* item = GetNext(node);
        if (holder->m_04->FUN_00b63170(item, owner) == false)
        {
            item->v26(holder);
        }
    }
}

struct FUN_00a59f00_obj
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
    virtual void v21(void* p)
    {}
};

struct FUN_00a59f00_node
{
    FUN_00a59f00_node* m_next;
    int m_04;
    FUN_00a59f00_obj* m_obj;
};

struct FUN_00a59f00_cls
{
    char _pad_00[0x1c];
    FUN_00a59f00_obj* m_1c;
    int m_20;
    FUN_00a59f00_node* m_24;
    bool __thiscall FUN_00a5c180(void* p);
    bool __thiscall FUN_00a59f00(void* p);
};

// Calls FUN_00a5c180(p); if it succeeds, invokes v21(p) on each node's m_obj and on m_1c, then returns true.
// @fnv 0x00a59f00
bool FUN_00a59f00_cls::FUN_00a59f00(void* apArg)
{
    if (!FUN_00a5c180(apArg))
    {
        return false;
    }
    FUN_00a59f00_node* node = m_24;
    while (node != 0)
    {
        FUN_00a59f00_obj*& pObj = node->m_obj;
        node = node->m_next;
        if (pObj != 0)
        {
            pObj->v21(apArg);
        }
    }
    FUN_00a59f00_obj* pLastObj = m_1c;
    if (pLastObj != 0)
    {
        pLastObj->v21(apArg);
    }
    return true;
}

struct FUN_00a5a140_cls
{
    char _pad_00[0x24];
    NodeA* m_pFirstNode;
    char _pad_28[0x8];
    unsigned int m_flags;
    void __thiscall FUN_00a5a140(int unused);
};

inline DataA* const& GetNextData(NodeA*& pos)
{
    DataA* const& element = pos->d;
    pos = pos->next;
    return element;
}

// @fnv 0x00a5a140
void __thiscall FUN_00a5a140_cls::FUN_00a5a140(int unused)
{
    NodeA* pos = m_pFirstNode;
    while (pos != 0)
    {
        DataA* d = GetNextData(pos);
        if (d != 0 && d->v != 0)
        {
            m_flags |= 0x40000;
            return;
        }
    }
    m_flags &= 0xfffbffff;
}

namespace fnv_00a5a900 {
void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFree(void*);

struct NiBinaryStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int Write(const void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        unsigned int uiWritten = m_pfnWrite(this, pv, uiBytes, &uiComponentSize, 1);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};

struct NiObject;

struct NiStream
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
    virtual void SaveLinkID(NiObject*);
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
    NiBinaryStream* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    kStream.m_pBackingStream->Write(&value, sizeof(T));
}

struct NiColor
{
    float r, g, b;
    void SaveBinary(NiStream&);
};

struct Sub34
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
    void ReadMatrixFromStream(NiStream&);
};

struct ListNode
{
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    NiObject* m_element;
};

struct Base00a5c5b0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiObject* unk1c;
    int unk20;
    ListNode* m_pkHead;
    ListNode* m_pkTail;
    int m_uiCount;
    void SaveNiObjectLinks(NiStream&);
};

struct Obj00a5a900 : Base00a5c5b0
{
    int unk30;
    Sub34 unk34;
    NiColor unk58;
    int unk64;
    void FUN_00a5a900(NiStream& kStream);
};

// Writes the base data, unk30, unk58, unk34, unk64, the object count and each linked object's link ID, then saves the link ID of unk1c.
// @fnv 0x00a5a900
void Obj00a5a900::FUN_00a5a900(NiStream& kStream)
{
    SaveNiObjectLinks(kStream);
    SerializeValue(kStream, unk30);
    unk58.SaveBinary(kStream);
    unk34.ReadMatrixFromStream(kStream);
    SerializeValue(kStream, unk64);
    long iNumObjects = m_uiCount;
    SerializeValue(kStream, iNumObjects);
    if (0 < iNumObjects)
    {
        NiObject** ppkObjects = (NiObject**)NiMalloc(iNumObjects * 4);
        ListNode* pos = m_pkHead;
        NiObject** pp = ppkObjects;
        while (pos)
        {
            NiObject*& tmp = pos->m_element;
            pos = pos->m_pkNext;
            *pp++ = tmp;
        }
        for (int i = iNumObjects - 1; i >= 0; i--)
            kStream.SaveLinkID(ppkObjects[i]);
        NiFree(ppkObjects);
    }
    kStream.SaveLinkID(unk1c);
}
}  // namespace fnv_00a5a900

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* p);

struct ObjBase
{
    virtual void v00();
    ObjBase();
};

struct Child
{
    virtual void v00();
    virtual void v01();
    int m_04;
};

struct Sub34
{
    int s00, s04, s08, s0c, s10, s14, s18, s1c, s20, s24, s28, s2c, s30;
    void Reset();
};

struct FUN_00a5aa20_cls : ObjBase
{
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    Child* volatile m_1c;
    int m_20;
    volatile int m_24;
    volatile int m_28;
    volatile int m_2c;
    int m_30;
    Sub34 m_34;
    Sub34 m_68;

    FUN_00a5aa20_cls();
};

// @fnv 0x00a5aa20
FUN_00a5aa20_cls::FUN_00a5aa20_cls()
{
    m_1c = 0;
    Sub34* sub = &m_34;
    m_2c = 0;
    m_24 = 0;
    m_28 = 0;
    m_18 = 0;
    m_30 = 0;
    sub->Reset();
    m_68.Reset();
    int flags = m_30;
    m_20 = 0;
    *(volatile int*)&m_30 = (flags & 0xffffffef) | 0x8000e;

    Child* p = m_1c;
    if (p != 0)
    {
        if (!IsBadCodePtr(&p->m_04))
            p->v01();
        m_1c = 0;
    }
}

struct FUN_00a71b70_cls
{
    char _pad_00[0x18];
    unsigned char m_18;
    FUN_00a71b70_cls* FUN_00a71b70(unsigned char v);
};

// @fnv 0x00a71b70
FUN_00a71b70_cls* FUN_00a71b70_cls::FUN_00a71b70(unsigned char v)
{
    m_18 = v;
    return this;
}

class B4E150SortAdjustNode
{
  public:
    B4E150SortAdjustNode(unsigned int uiChildren);
    virtual ~B4E150SortAdjustNode();

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
    unsigned int m_uiValue1;
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
};

struct B4E150Array
{
    void* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;

    B4E150Array() : m_pBase(0), m_uiMaxSize(0), m_uiSize(0), m_uiGrowBy(0)
    {}
};

class FUN_00b4e150 : public B4E150SortAdjustNode
{
  public:
    float m_fNearPlane;
    float m_fFarPlane;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
    int m_iE;
    int unkC8;
    int m_iF;
    int m_iG;
    B4E150Array m_kUnsortedGeometryList;

    FUN_00b4e150();
    virtual ~FUN_00b4e150();
};

// @fnv 0x00b4e150
FUN_00b4e150::FUN_00b4e150() : B4E150SortAdjustNode(0)
{
    m_fNearPlane = 3.402823466e+38f;
    m_fFarPlane = 3.402823466e+38f;
    m_uiValue1 &= ~0x2c000;
    m_iG = 0;
    m_fCoefficientA = 0.0f;
    m_fB = 0.0f;
    m_fC = 0.0f;
    m_fD = 0.0f;
    m_iE = 0;
    m_iF = 0;
}

struct NiPropertyState
{
    void ReleaseAllRefs();
};

struct FUN_0040fbf0_shell
{
    void Lock(char* name);
};

struct FUN_00a5e3a0_Helper
{
    void FUN_00a5e3a0(NiPropertyState*& ps);
    NiPropertyState* FUN_00a89ab0();
    void* FUN_00aa3e40(unsigned int size);
};

extern unsigned int DAT_011f42a0;
extern unsigned int DAT_011f42a4;
extern unsigned int DAT_011f6238;

struct FUN_00a5a040_Class
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
    virtual void v44(NiPropertyState* ps);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00a5e3a0_Helper* m18;
    void FUN_00a5a040();
};

// @fnv 0x00a5a040
void FUN_00a5a040_Class::FUN_00a5a040()
{
    NiPropertyState* ps = 0;
    ((FUN_0040fbf0_shell*)&DAT_011f42a0)->Lock(0);
    if (m18 != 0)
    {
        m18->FUN_00a5e3a0(ps);
    }
    else
    {
        void* pAlloc = ((FUN_00a5e3a0_Helper*)&DAT_011f6238)->FUN_00aa3e40(28);
        if (pAlloc != 0)
        {
            ps = ((FUN_00a5e3a0_Helper*)pAlloc)->FUN_00a89ab0();
        }
        else
        {
            ps = 0;
        }
    }
    v44(ps);
    NiPropertyState* p = ps;
    if (p != 0)
    {
        p->ReleaseAllRefs();
        ((MemoryManager*)&DAT_011f6238)->Deallocate(p);
    }
    DAT_011f42a4--;
    if (DAT_011f42a4 == 0)
    {
        DAT_011f42a0 = 0;
    }
}

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct LoadedRef
{
    virtual ~LoadedRef();
    virtual void DeleteThis() throw();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void ReadVersion(unsigned int, int);
    volatile long count;
};
struct LoadedPtr
{
    LoadedRef* pointer;
    LoadedPtr(LoadedRef* value) throw() : pointer(value)
    {
        if (value)
            InterlockedIncrement(&value->count);
    }

    void FUN_0066b0d0(LoadedRef*);
};
struct LoadedArray
{
    void FUN_00a5a310(const LoadedPtr&) throw();
    void FUN_00439fd0(const LoadedPtr&) throw();
};
struct LoadedStream
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
    unsigned int version;
    unsigned int FUN_00a63460();
    LoadedRef* FUN_00a63430();
};
struct LoadedNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    LoadedPtr controller;
    int unk20;
    LoadedArray children;
    void FUN_00a5c0e0(LoadedStream*);
    void ReadFromStream(LoadedStream*);
};
// Reads a child count from the stream and loads each child into children, then loads the controller for newer versions.
// @fnv 0x00a5a7f0
void LoadedNode::ReadFromStream(LoadedStream* stream)
{
    FUN_00a5c0e0(stream);
    unsigned int count = stream->FUN_00a63460();
    if (stream->version < 0x04010008)
    {
        while (count)
        {
            count--;
            LoadedRef* raw = stream->FUN_00a63430();
            LoadedPtr child = raw;
            children.FUN_00a5a310(child);
            if (raw && !InterlockedDecrement(&raw->count))
                raw->DeleteThis();
        }
    }
    else
    {
        while (count)
        {
            count--;
            LoadedRef* raw = stream->FUN_00a63430();
            LoadedPtr child = raw;
            children.FUN_00439fd0(child);
            if (raw && !InterlockedDecrement(&raw->count))
                raw->DeleteThis();
        }
        if (stream->version >= 0x05000013)
        {
            controller.FUN_0066b0d0(stream->FUN_00a63430());
            LoadedRef* pController = controller.pointer;
            if (pController)
                pController->ReadVersion(stream->version, 0);
        }
    }
}

struct Stream
{
    void* vtable;
    unsigned int* values;
    unsigned short capacity;
    unsigned short length;
    unsigned short active;
    unsigned short growth;
    void FUN_0096ad30(unsigned int required);
    void FUN_0096ae90(unsigned int index, unsigned int* value);
    __forceinline void Add(unsigned int value)
    {
        unsigned int index = length;
        if (index >= capacity)
            FUN_0096ad30(index + growth);
        FUN_0096ae90(index, &value);
    }
};
struct SerializedField
{
    unsigned int state0;
    unsigned int state4;
    unsigned int state8;
    unsigned int stateC;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1C;
    unsigned int state20;
    unsigned int FUN_00a59af0(const char* name);
    unsigned int ToString(const char* name);
};
struct SmallField
{
    unsigned int state0;
    unsigned int state4;
    unsigned int state8;
    unsigned int FUN_00a59af0(const char* name);
    unsigned int ToString(const char* name);
};
struct IndexedElement
{
    virtual void f0();
    virtual void f1();
    virtual unsigned int* GetValue();
};
struct IndexedNode
{
    IndexedNode* next;
    unsigned int state;
    IndexedElement* element;
};
inline IndexedElement* const& GetNextIndexed(IndexedNode*& pos)
{
    IndexedElement* const& element = pos->element;
    pos = pos->next;
    return element;
}
void __stdcall FUN_00a5ca80(Stream* stream);
unsigned int __cdecl FUN_00a7d330(unsigned int source);
unsigned int __cdecl FUN_00a7d370(const char* name, unsigned int value);
unsigned int __cdecl FUN_00a7d550(const char* name, float value);
unsigned int __cdecl FUN_00a7d5a0(unsigned int value, IndexedElement* element);
struct TextSource
{
    unsigned int FUN_00a7fb20(const char* name);
};
extern unsigned int DAT_011f4280;
extern char DAT_011f4288;
extern char DAT_0109b204, DAT_0109b1f8, DAT_0109b1e4, DAT_0109b1d4, DAT_0109b1c4, DAT_0109b1b0;
extern char DAT_0109b1a0, DAT_0109b190, DAT_0109b184, DAT_0109b178, DAT_0109b164, DAT_0109b154;
extern char DAT_0109b138, DAT_0109b124, DAT_0109b118, DAT_0109b10c;
struct FUN_00a5ad00_shell
{
    unsigned int unknown00, unknown04, unknown08, unknown0C, unknown10, unknown14, unknown18;
    void* propertyObject;
    TextSource* textSource;
    IndexedNode* elements;
    unsigned int elementListState;
    unsigned int elementCount;
    unsigned int flags;
    SerializedField field34;
    SmallField field58;
    float field64;
    SerializedField field68;
    SmallField field8C;
    float field98;
    void FUN_00a5ad00(Stream* stream);
};
// @fnv 0x00a5ad00
void FUN_00a5ad00_shell::FUN_00a5ad00(Stream* stream)
{
    FUN_00a5ca80(stream);
    stream->Add(FUN_00a7d330(DAT_011f4280));
    union FlagWord
    {
        unsigned int word;
        unsigned char byte;
    } firstFlag;
    firstFlag.byte = static_cast<unsigned char>(flags) & 1;
    stream->Add(FUN_00a7d370(&DAT_0109b204, firstFlag.word));
    unsigned char bFlag11 = static_cast<unsigned char>(flags >> 11) & 1;
    if (bFlag11)
    {
        union FlagWord
        {
            unsigned int word;
            unsigned char byte;
        } flag11;
        flag11.byte = bFlag11;
        stream->Add(FUN_00a7d370(&DAT_0109b1f8, flag11.word));
    }
    stream->Add(field58.FUN_00a59af0(&DAT_0109b1e4));
    stream->Add(field34.ToString(&DAT_0109b1d4));
    stream->Add(FUN_00a7d550(&DAT_0109b1c4, field64));
    stream->Add(field8C.FUN_00a59af0(&DAT_0109b1b0));
    stream->Add(field68.ToString(&DAT_0109b1a0));
    stream->Add(FUN_00a7d550(&DAT_0109b190, field98));
    stream->Add((textSource ? textSource : reinterpret_cast<TextSource*>(&DAT_011f4288))->FUN_00a7fb20(&DAT_0109b184));
    union FlagWord1
    {
        unsigned int word;
        unsigned char byte;
    } flag1;
    flag1.byte = static_cast<unsigned char>(flags >> 1) & 1;
    stream->Add(FUN_00a7d370(&DAT_0109b178, flag1.word));
    union FlagWord2
    {
        unsigned int word;
        unsigned char byte;
    } flag2;
    flag2.byte = static_cast<unsigned char>(flags >> 2) & 1;
    stream->Add(FUN_00a7d370(&DAT_0109b164, flag2.word));
    union FlagWord4
    {
        unsigned int word;
        unsigned char byte;
    } flag4;
    flag4.byte = static_cast<unsigned char>(flags >> 4) & 1;
    stream->Add(FUN_00a7d370(&DAT_0109b154, flag4.word));
    union FlagWord3
    {
        unsigned int word;
        unsigned char byte;
    } flag3;
    flag3.byte = static_cast<unsigned char>(flags >> 3) & 1;
    stream->Add(FUN_00a7d370(&DAT_0109b138, flag3.word));
    if (elementCount)
    {
        IndexedNode* node = elements;
        while (node != 0)
        {
            IndexedElement* element = GetNextIndexed(node);
            unsigned int key = *element->GetValue();
            unsigned int next = FUN_00a7d5a0(key, element);
            unsigned int index = stream->length;
            if (index >= stream->capacity)
                stream->FUN_0096ad30(index + stream->growth);
            if (index >= stream->length)
            {
                stream->length = index + 1;
                if (next != 0)
                    ++stream->active;
            }
            else if (next != 0)
            {
                if (stream->values[index] == 0)
                    ++stream->active;
            }
            else if (stream->values[index] != 0)
            {
                --stream->active;
            }
            stream->values[index] = next;
        }
    }
    if (propertyObject)
        stream->Add(FUN_00a7d5a0((unsigned int)&DAT_0109b124, reinterpret_cast<IndexedElement*>(propertyObject)));
    unsigned char bFlag10 = static_cast<unsigned char>(flags >> 10) & 1;
    if (bFlag10)
    {
        union FlagWord10
        {
            unsigned int word;
            unsigned char byte;
        } flag10;
        flag10.byte = bFlag10;
        stream->Add(FUN_00a7d370(&DAT_0109b118, flag10.word));
    }
    unsigned char bit13 = static_cast<unsigned char>(flags >> 13) & 1;
    if (bit13)
    {
        union FlagWord13
        {
            unsigned int word;
            unsigned char byte;
        } flag13;
        flag13.byte = bit13;
        stream->Add(FUN_00a7d370(&DAT_0109b10c, flag13.word));
    }
}

class AV59f
{
  public:
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
    virtual void UpdateDownwardPass(NiUpdateData& kData);
    virtual void UpdateWorldBound();

    char _pad_04[0x2c];
    unsigned int m_uiValue1;
    bool GetSelectiveUpdate() const
    {
        return ((m_uiValue1 >> 2) & 1) != 0;
    }
    bool GetSelectiveUpdateTransforms() const
    {
        return ((m_uiValue1 >> 3) & 1) != 0;
    }

    void UpdateDownwardPassIfSelective(NiUpdateData& kData, unsigned int uiUnused);
};

// @fnv 0x00a59fd0
void AV59f::UpdateDownwardPassIfSelective(NiUpdateData& kData, unsigned int uiUnused)
{
    bool m_bUpdateEnabled = kData.m_bUpdateEnabled;
    kData.m_bUpdateEnabled = GetSelectiveUpdateTransforms();
    ((NiAVObject*)this)->UpdateTimeControllers(kData, true);
    kData.m_bUpdateEnabled = m_bUpdateEnabled;

    if (GetSelectiveUpdate() && !kData.m_bRender)
    {
        UpdateDownwardPass(kData);
        UpdateWorldBound();
    }
}

// 0x00c6c760  ret 0xc
// @fnv 0x00c6c760
void __stdcall FUN_00c6c760(int, int, int)
{}

class ItemA59D
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual int GetType();
};

template <class T> struct NiTListItemA59D
{
    NiTListItemA59D* m_pkNext;
    NiTListItemA59D* m_pkPrev;
    T m_element;
};

typedef void* NiTListIterator;

template <class T> class NiTListA59D
{
  public:
    void* m_vtbl;
    NiTListItemA59D<T>* m_pkHead;
    NiTListItemA59D<T>* m_pkTail;

    NiTListIterator GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListIterator& kPos) const
    {
        const T& element = ((NiTListItemA59D<T>*)kPos)->m_element;
        kPos = ((NiTListItemA59D<T>*)kPos)->m_pkNext;
        return element;
    }
};

class FUN_00a59d30_C
{
  public:
    char unk00[0x20];
    NiTListA59D<ItemA59D*> m_kList;

    ItemA59D* FUN_00a59d30(int iType);
};

// Iterates m_kList and returns the first item whose GetType matches iType, or null if iType is 7 or greater or no match is found.
// @fnv 0x00a59d30
ItemA59D* FUN_00a59d30_C::FUN_00a59d30(int iType)
{
    if (iType >= 7)
        return 0;
    NiTListIterator kPos = m_kList.GetHeadPos();
    while (kPos)
    {
        ItemA59D* pkItem = m_kList.GetNext(kPos);
        if (pkItem && pkItem->GetType() == iType)
            return pkItem;
    }
    return 0;
}

class TimeCtrlA5A4
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual bool IsTransformController() const;

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    TimeCtrlA5A4* m_spNextController;
};

class PropertyA5A4
{
  public:
    int unk00, unk04, unk08;
    TimeCtrlA5A4* m_pControllers;
};

struct ListItemA5A4
{
    ListItemA5A4* m_pkNext;
    ListItemA5A4* m_pkPrev;
    PropertyA5A4* m_element;
};

class PropertyListA5A4
{
  public:
    ListItemA5A4* m_pkHead;
    ListItemA5A4* m_pkTail;
    unsigned int m_uiCount;

    ListItemA5A4* GetHeadPos() const
    {
        return m_pkHead;
    }
    PropertyA5A4*& GetNext(ListItemA5A4*& pos) const
    {
        PropertyA5A4*& element = pos->m_element;
        pos = pos->m_pkNext;
        return element;
    }
};

class AVObjectA5A4
{
  public:
    int unk00, unk04, unk08;
    TimeCtrlA5A4* m_pControllers;
    int unk10, unk14, unk18, unk1C, unk20;
    PropertyListA5A4 SceneGraphObject;
    unsigned int m_uiObjectFlags;

    void SetBit(bool bVal, unsigned int uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
    bool GetBit(unsigned int uMask, unsigned int uPos) const
    {
        return ((m_uiObjectFlags & uMask) >> uPos) != 0;
    }

    bool HasTransformController() const
    {
        for (TimeCtrlA5A4* pkCtrl = m_pControllers; pkCtrl; pkCtrl = pkCtrl->m_spNextController)
        {
            if (pkCtrl->IsTransformController())
                return true;
        }
        return false;
    }
    bool HasPropertyController() const
    {
        ListItemA5A4* kPos = SceneGraphObject.GetHeadPos();
        while (kPos)
        {
            PropertyA5A4* pkProperty = SceneGraphObject.GetNext(kPos);
            if (pkProperty && pkProperty->m_pControllers)
                return true;
        }
        return false;
    }

    void FUN_00a5a450(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid);
};

// @fnv 0x00a5a450
void AVObjectA5A4::FUN_00a5a450(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid)
{
    bRigid = !HasTransformController() && !GetBit(0x80, 7);
    if (!bSelectiveUpdateTransforms)
        bSelectiveUpdateTransforms = !bRigid;
    bool bSelectiveUpdatePropertyControllers = HasPropertyController();
    if (bSelectiveUpdatePropertyControllers || bSelectiveUpdateTransforms || m_pControllers)
        bSelectiveUpdate = true;
    else
        bSelectiveUpdate = false;
    SetBit(bSelectiveUpdate, 2);
    SetBit(bSelectiveUpdateTransforms, 4);
    SetBit(bSelectiveUpdatePropertyControllers, 8);
    SetBit(true, 0x10);
}

struct A5a260CompareBase
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
    virtual bool FUN_00a5a260(A5a260CompareBase*) = 0;
};

struct A5a260CompareField
{
    bool __thiscall FUN_00a86c30(A5a260CompareField*);
};

struct A5a260ListNode;
inline A5a260CompareBase*& GetNext_a5a(A5a260ListNode*& pos);
struct A5a260ListNode
{
    A5a260ListNode* next;
    int unk04;
    A5a260CompareBase* property;
};

inline A5a260CompareBase*& GetNext_a5a(A5a260ListNode*& pos)
{
    A5a260CompareBase*& element = pos->property;
    pos = pos->next;
    return element;
}

struct A5a260Object : A5a260CompareBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    A5a260CompareBase* unk1C;
    int unk20;
    A5a260ListNode* unk24;
    int unk28;
    unsigned int unk2C;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    A5a260CompareField unk34;

    bool __thiscall FUN_00a5c820(A5a260CompareBase*);
    bool __thiscall FUN_00a5a260(A5a260CompareBase*);
};

// Returns false when the flag bit, field comparison, property list, or collision comparison does not match.
// @fnv 0x00a5a260
bool __thiscall A5a260Object::FUN_00a5a260(A5a260CompareBase* pkObject)
{
    A5a260Object* other = (A5a260Object*)pkObject;

    if (!FUN_00a5c820(pkObject))
        return false;

    if ((other->unk30 ^ unk30) & 1)
        return false;

    if (unk34.FUN_00a86c30(&other->unk34))
        return false;

    unsigned int count = unk2C;
    if (count != other->unk2C)
        return false;

    if (count > 0)
    {
        A5a260ListNode* node0 = unk24;
        A5a260ListNode* node1 = other->unk24;
        while (node0)
        {
            A5a260CompareBase* property0 = GetNext_a5a(node0);
            A5a260CompareBase* property1 = GetNext_a5a(node1);
            if (property0 && !property1)
                return false;
            if (!property0 && property1)
                return false;
            if (property0 && !property0->FUN_00a5a260(property1))
                return false;
        }
    }

    A5a260CompareBase* collision0 = unk1C;
    A5a260CompareBase* collision1 = other->unk1C;
    if (collision0 && collision1)
    {
        if (!collision0->FUN_00a5a260(collision1))
            return false;
    }
    else if (collision0 != collision1)
    {
        return false;
    }
    return true;
}

#include <string.h>
struct BinaryStream
{
    unsigned int unknown00;
    unsigned int position;
    unsigned int(__cdecl* read)(BinaryStream*, void*, unsigned int, const unsigned int*, unsigned int);
    unsigned int Read(void* destination, unsigned int bytes)
    {
        const unsigned int size = bytes;
        unsigned int transferred = read(this, destination, bytes, &size, 1);
        position += transferred;
        return transferred;
    }
};
struct LoadStream
{
    unsigned int unknown000;
    unsigned int format;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int version;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    unsigned int unknown1b0;
    unsigned int unknown1b4;
    unsigned int unknown1b8;
    unsigned int unknown1bc;
    unsigned int unknown1c0;
    unsigned int unknown1c4;
    unsigned int unknown1c8;
    unsigned int unknown1cc;
    unsigned int unknown1d0;
    unsigned int unknown1d4;
    unsigned int unknown1d8;
    unsigned int unknown1dc;
    unsigned int unknown1e0;
    unsigned int unknown1e4;
    unsigned int unknown1e8;
    unsigned int unknown1ec;
    unsigned int unknown1f0;
    unsigned int unknown1f4;
    unsigned int unknown1f8;
    unsigned int unknown1fc;
    unsigned int unknown200;
    unsigned int unknown204;
    unsigned int unknown208;
    unsigned int unknown20c;
    unsigned int unknown210;
    unsigned int unknown214;
    unsigned int unknown218;
    unsigned int unknown21c;
    unsigned int unknown220;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int unknown230;
    unsigned int unknown234;
    unsigned int unknown238;
    unsigned int unknown23c;
    unsigned int unknown240;
    unsigned int unknown244;
    unsigned int unknown248;
    BinaryStream* input;
    unsigned int unknown250;
    unsigned int unknown254;
    unsigned int unknown258;
    unsigned int unknown25c;
    unsigned int unknown260;
    unsigned int unknown264;
    unsigned int unknown268;
    unsigned int unknown26c;
    unsigned int unknown270;
    unsigned int unknown274;
    unsigned int unknown278;
    unsigned int unknown27c;
    unsigned int unknown280;
    unsigned short legacyFlags;
    unsigned short unknown286;
    unsigned int unknown288;
    unsigned int unknown28c;
    unsigned int unknown290;
    unsigned int unknown294;
    unsigned int unknown298;
    unsigned int unknown29c;
    unsigned int unknown2a0;
    unsigned int unknown2a4;
    unsigned int unknown2a8;
    unsigned int unknown2ac;
    unsigned int unknown2b0;
    unsigned int unknown2b4;
    unsigned int unknown2b8;
    unsigned int unknown2bc;
    unsigned int unknown2c0;
    unsigned int unknown2c4;
    unsigned int unknown2c8;
    unsigned int unknown2cc;
    unsigned int unknown2d0;
    unsigned int unknown2d4;
    unsigned int unknown2d8;
    unsigned int unknown2dc;
    unsigned int unknown2e0;
    unsigned int unknown2e4;
    unsigned int unknown2e8;
    unsigned int unknown2ec;
    unsigned int unknown2f0;
    unsigned int unknown2f4;
    unsigned int unknown2f8;
    unsigned int unknown2fc;
    unsigned int unknown300;
    unsigned int unknown304;
    unsigned int unknown308;
    unsigned int unknown30c;
    unsigned int unknown310;
    unsigned int unknown314;
    unsigned int unknown318;
    unsigned int unknown31c;
    unsigned int unknown320;
    unsigned int unknown324;
    unsigned int unknown328;
    unsigned int unknown32c;
    unsigned int unknown330;
    unsigned int unknown334;
    unsigned int unknown338;
    unsigned int unknown33c;
    unsigned int unknown340;
    unsigned int unknown344;
    unsigned int unknown348;
    unsigned int unknown34c;
    unsigned int unknown350;
    unsigned int unknown354;
    unsigned int unknown358;
    unsigned int unknown35c;
    unsigned int unknown360;
    unsigned int unknown364;
    unsigned int unknown368;
    unsigned int unknown36c;
    unsigned int unknown370;
    unsigned int unknown374;
    unsigned int unknown378;
    unsigned int unknown37c;
    unsigned int unknown380;
    unsigned int unknown384;
    unsigned int unknown388;
    unsigned int unknown38c;
    unsigned int unknown390;
    unsigned int unknown394;
    unsigned int unknown398;
    unsigned int unknown39c;
    unsigned int unknown3a0;
    unsigned int unknown3a4;
    unsigned int unknown3a8;
    unsigned int unknown3ac;
    unsigned int unknown3b0;
    unsigned int unknown3b4;
    unsigned int unknown3b8;
    char typeName[128];
    void FUN_00a64670();
    void FUN_00a645b0();
};
struct LoadBase
{
    void FUN_00a5c080(LoadStream&);
};
extern const float DAT_011f426c;
struct LoadVector
{
    float x, y, z;
    void FUN_00a59be0(LoadStream&);
    bool _Call_439090(const void*);
};
struct Matrix3x3
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void LoadFromStream(LoadStream&);
};
struct LegacyData;
struct LoadObject;
struct LoadContext
{
    LoadObject* object;
    LoadStream* stream;
    bool enabled;
    unsigned short mode;
};
struct LegacyData
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
    virtual void LoadLegacy(LoadContext*);
    virtual void Convert(unsigned int, int);
};
LegacyData* __cdecl InvokeNamedFunction(const char*);
struct LoadObject : LoadBase
{
    unsigned int unknown00, unknown04, unknown08, unknown0c, unknown10, unknown14, unknown18;
    GO collision;
    unsigned int unknown20, unknown24, unknown28, unknown2c;
    union
    {
        unsigned int flags;
        struct
        {
            unsigned char flagsByte;
            unsigned char flagsByte1;
            unsigned short flagsWord1;
        };
    };
    Matrix3x3 rotation;
    LoadVector translation;
    float scale;
    void FUN_00a5a510(LoadStream& stream);
};
// Reads flags, translation, rotation, and scale, then handles legacy collision data and version-dependent flag updates.
// @fnv 0x00a5a510
void LoadObject::FUN_00a5a510(LoadStream& stream)
{
    FUN_00a5c080(stream);
    if (stream.format < 28)
    {
        unsigned short oldFlags;
        stream.input->Read(&oldFlags, 2);
        flags = oldFlags;
    }
    else
    {
        stream.input->Read(&flags, 4);
    }
    if (stream.version < 0x0401000b)
    {
        unsigned short low = (unsigned short)flags;
        flags = (flags & ~7u) << 1;
        flags |= low & 7;
    }
    if (stream.version < 0x0401000c)
    {
        unsigned short low = (unsigned short)flags;
        flags <<= 4;
        flagsByte = 0;
        flags &= ~0x80u;
        flags |= low & 15;
        flags |= 0x70;
    }
    if (stream.version < 0x05000001)
    {
        unsigned short low = (unsigned short)flags;
        flags = (flags & ~255u) << 1;
        flags |= (unsigned char)low;
    }
    translation.FUN_00a59be0(stream);
    rotation.LoadFromStream(stream);
    stream.input->Read(&scale, 4);
    if (stream.version < 0x05000013)
    {
        unsigned int mode = (flags >> 1) & 7;
        unsigned short low = (unsigned short)flags;
        flags = (flags >> 3) & 0xfffe;
        flags |= low & 1;
        LoadVector oldTranslation = {0.0f, 0.0f, 0.0f};
        oldTranslation.FUN_00a59be0(stream);
        stream.FUN_00a64670();
        unsigned char enabled;
        unsigned int oldEnabled;
        if (stream.version < 0x04010000)
        {
            stream.input->Read(&oldEnabled, 4);
            enabled = oldEnabled != 0;
        }
        else
        {
            stream.input->Read(&enabled, 1);
        }
        if (strcmp(stream.typeName, "NiCollisionSwitch") == 0 && !((unsigned char)(flags >> 3) & 1))
            mode = 4;
        if (enabled || oldTranslation._Call_439090(&DAT_011f426c) || (unsigned short)mode != 2)
        {
            LegacyData* data = InvokeNamedFunction("NiCollisionData");
            if (data)
            {
                collision = data;
                LoadContext context;
                context.mode = (unsigned short)mode;
                context.enabled = enabled != 0;
                context.object = this;
                context.stream = &stream;
                ((LegacyData*)collision.ptr)->LoadLegacy(&context);
            }
        }
    }
    else
    {
        stream.FUN_00a64670();
        stream.FUN_00a645b0();
    }
    if (stream.version < 0x0a000102)
    {
        stream.legacyFlags = (unsigned short)flags;
        flags &= 0x3f;
    }
    if (stream.version < 0x0a000106 && collision.ptr)
        ((LegacyData*)collision.ptr)->Convert(stream.version, 0);
    if (stream.version < 0x14000004)
        flags &= ~0x40u;
    flags = (flags & ~0x10u) | 0x8000e;
}

namespace fnv_00a89960 {
#include <windows.h>

struct WorkerProperty
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long references;
};
struct WorkerPointer
{
    WorkerProperty* object;
    WorkerPointer& operator=(WorkerProperty* value)
    {
        WorkerProperty* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->references) == 0)
                old->DeleteThis();
            object = value;
            if (object)
                InterlockedIncrement(&object->references);
        }
        return *this;
    }
};
extern WorkerProperty* DAT_011f4410;
extern WorkerProperty* DAT_011f5d28;
extern WorkerProperty* DAT_011f4a64;
extern WorkerProperty* DAT_011f5ae8;
extern WorkerProperty* DAT_011f4a14;
extern WorkerProperty* DAT_011f49ac;
struct WorkerProperties
{
    WorkerPointer alpha;
    WorkerPointer culling;
    WorkerPointer material;
    WorkerPointer shading;
    WorkerPointer stencil;
    WorkerPointer depth;
    void FUN_00a89960();
};
// Assigns six global WorkerProperty pointers to the corresponding WorkerPointer members.
// @fnv 0x00a89960
void WorkerProperties::FUN_00a89960()
{
    alpha = DAT_011f4410;
    culling = DAT_011f5d28;
    material = DAT_011f4a64;
    shading = DAT_011f5ae8;
    stencil = DAT_011f4a14;
    depth = DAT_011f49ac;
}
}  // namespace fnv_00a89960

namespace fnv_00a5a170 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class A170Obj
{
  public:
    virtual void v00();
    virtual void DeleteThis();
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
    virtual int GetIndex();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

class A170Ptr
{
  public:
    A170Obj* m_pObject;
    A170Ptr& operator=(A170Obj* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

struct A170Node
{
    A170Node* m_pNext;
    A170Node* m_pListObject;
    A170Obj* m_element;
};
inline A170Obj* const& A170GetNext(A170Node*& pos)
{
    A170Obj* const& elem = pos->m_element;
    pos = pos->m_pNext;
    return elem;
}

struct A170Lock
{
    int m_pOwnerObject;
    int m_uiItemCount;
    void __thiscall Lock(unsigned int);
    void Unlock()
    {
        if (--m_uiItemCount == 0)
            m_pOwnerObject = 0;
    }
};
extern A170Lock DAT_011f42a0;

struct A170Heap
{
    void* __thiscall FUN_00aa3e40(unsigned int);
};
extern A170Heap DAT_011f6238;

struct A170Set
{
    A170Set* __thiscall FUN_00a89810(A170Set* src);
};

struct FUN_00a5a170_cls
{
    char _p00[0x24];
    A170Node* m_24;
    char _p28[4];
    int m_2c;
    void FUN_00a5a170(A170Set* a1, bool a2, A170Set** out);
};

// Copies elements with index <= 7 from the internal list into a new or existing A170Set, optionally allocating a new set first.
// @fnv 0x00a5a170
void FUN_00a5a170_cls::FUN_00a5a170(A170Set* apSource, bool abAllocate, A170Set** apResult)
{
    if (!m_2c)
    {
        *apResult = apSource;
        return;
    }
    DAT_011f42a0.Lock(0);
    A170Set* result;
    if (abAllocate)
    {
        void* p = DAT_011f6238.FUN_00aa3e40(0x1c);
        result = p ? ((A170Set*)p)->FUN_00a89810(apSource) : 0;
    }
    else
    {
        result = apSource;
    }
    A170Ptr* slots = (A170Ptr*)result;
    A170Node* node = m_24;
    while (node)
    {
        A170Obj* pElement = A170GetNext(node);
        if (pElement && pElement->GetIndex() <= 7)
            slots[pElement->GetIndex()] = pElement;
    }
    DAT_011f42a0.Unlock();
    *apResult = result;
}
}  // namespace fnv_00a5a170
