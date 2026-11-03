
// src/speedtree/libspline_source/idvspline_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/speedtree/libspline_source/idvspline.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "idvspline_decls.h"
extern "C" int __cdecl _strlen(const char*);
extern "C" int __cdecl _sscanf(const char*, const char*, ...);
int __cdecl FUN_00ec8965(int);
extern const char* const DAT_01019f08;
const char* __cdecl FUN_00b37f50(const char* pInput, char* pToken);
unsigned int __cdecl FUN_00ec7c56(void);
struct Host00b3b050
{
    int m0;
    int m1;
    Host00b3b050* FUN_00b3b050(int a, int* b);
};
struct FUN_00b3c500
{
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    int i14;
    FUN_00b3c500(float a, float b);
};
struct Node0394
{
    Node0394* f0;
    Node0394* f1;
    Node0394* f2;
};
struct Holder0394
{
    char _pad[0x18];
    Node0394* f18;
    int f1c;
    void FUN_00b3a050(Node0394*);
    void ResetList();
};
struct NodeB
{
    NodeB* f0;
    NodeB* f4;
    NodeB* f8;
    unsigned char f2d;
};
struct FUN_00b3b810_shell
{
    char _pad[0x18];
    NodeB* f18;
    int f1c;
    NodeB* FUN_00b3b880();
    void InitNode();
};
struct FUN_00b3b1d0_shell
{
    char _pad[0x18];
    NodeB* f18;
    int f1c;
    void FUN_00b3b1d0(NodeB*);
};
struct FUN_00b3b280_owner : FUN_00b3b810_shell
{
    void FUN_00b3b280(NodeB* pArg);
};
void __cdecl FUN_00b3b540(int, int);
struct FUN_00b3b9d0_shell
{
    void FUN_00b3b9d0(int);
};
extern "C" char DAT_010a57e8;
int __cdecl FUN_00ec6da0(const char*, const char*);
long __cdecl FUN_00eca6d3(const char*);
struct InputB37
{
    int pad;
    union
    {
        char text[16];
        char* ptr;
    } data;
    unsigned int length;
    unsigned int capacity;
};
struct VecB37
{
    float x, y;
};
struct HostB37
{
    float x, y, z;
    void FUN_00b380e0(VecB37*, VecB37*, float);
    void FUN_00b37cc0(InputB37*);
};

unsigned int __cdecl FUN_00ec7c56(void);

namespace std {
template <class _Ty> __forceinline const _Ty& max(const _Ty& _Left, const _Ty& _Right)
{
    return (_Left < _Right ? _Right : _Left);
}
template <class _Ty> __forceinline const _Ty& min(const _Ty& _Left, const _Ty& _Right)
{
    return (_Left < _Right ? _Left : _Right);
}
}

struct FUN_00b3c4b0_class
{
    float f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    int i14;

    FUN_00b3c4b0_class* FUN_00b3c4b0(int);
    __forceinline FUN_00b3c4b0_class(int a)
    {
        FUN_00b3c4b0(a);
    }
    ~FUN_00b3c4b0_class();
};

struct SplinePointVector
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00b3c4b0_class* m_pHeadNode;
    FUN_00b3c4b0_class* m_last;
    FUN_00b3c4b0_class* m_kRayEnd;

    __forceinline int size() const
    {
        return m_last - m_pHeadNode;
    }
    __forceinline FUN_00b3c4b0_class& at(unsigned int i)
    {
        if (i >= (unsigned int)size())
        {
            FUN_00ec7c56();
        }
        return m_pHeadNode[i];
    }
};

class IdvSpline
{
  public:
    int unk00;
    int unk04;
    int unk08;
    SplinePointVector m_kPoints;  // 0x0c
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
    SplinePointVector m_tangents;  // 0x6c

    FUN_00b3c4b0_class FUN_00b38f40(FUN_00b3c4b0_class* p0, FUN_00b3c4b0_class* p1, FUN_00b3c4b0_class* p2,
                                    FUN_00b3c4b0_class* p3, float t);

    FUN_00b3c4b0_class FUN_00b38b50(float t);
};

// @fnv 0x00b38b50
FUN_00b3c4b0_class IdvSpline::FUN_00b38b50(float t)
{
    FUN_00b3c4b0_class result(2);

    int count = m_kPoints.size();
    if (count > 1)
    {
        t = (std::max)(0.0f, t);
        t = (std::min)(t, 1.0f);
        t *= (float)(count - 1);
        float fract = t - (float)(int)t;
        bool bFound = false;
        for (int i = 0; i < count && !bFound; ++i)
        {
            if (i == count - 1)
            {
                result = m_kPoints.at(i);
                bFound = true;
            }
            else if (t >= (float)i && (float)(i + 1) > t)
            {
                result = FUN_00b38f40(&m_tangents.at(i * 3), &m_tangents.at(i * 3 + 1), &m_tangents.at(i * 3 + 2),
                                      &m_tangents.at(i * 3 + 3), fract);
                bFound = true;
            }
        }
    }

    return result;
}

unsigned int __cdecl FUN_00ec7c56(void);

struct TreeB3B;

struct NodeT
{
    NodeT* f0;
    NodeT* f1;
    NodeT* f2;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    char color;
    char isnil;
};

struct TreeIterBaseB3B
{
    int aux;
    TreeIterBaseB3B() : aux(0)
    {}
    bool IsContainerSet() const
    {
        return aux != 0;
    }
    bool SameContainer(const TreeIterBaseB3B& right) const
    {
        return aux == right.aux;
    }
    void SetContainer(const TreeB3B* cont);
};

struct TreeConstIterB3B : TreeIterBaseB3B
{
    NodeT* ptr;
    TreeConstIterB3B(NodeT* p, const TreeB3B* cont) : ptr(p)
    {
        SetContainer(cont);
    }
    bool operator==(const TreeConstIterB3B& right) const
    {
        if (!(IsContainerSet() && SameContainer(right)))
            FUN_00ec7c56();
        return ptr == right.ptr;
    }
    bool operator!=(const TreeConstIterB3B& right) const
    {
        return !(*this == right);
    }
    TreeConstIterB3B& Increment();
    TreeConstIterB3B operator++(int)
    {
        TreeConstIterB3B tmp = *this;
        Increment();
        return tmp;
    }
};

struct TreeIterB3B : TreeConstIterB3B
{
    TreeIterB3B(NodeT* p, const TreeB3B* cont) : TreeConstIterB3B(p, cont)
    {}
    TreeIterB3B(const TreeConstIterB3B& r) : TreeConstIterB3B(r)
    {}
};

struct TreeB3B
{
    int aux;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NodeT* head;
    int count;
    static NodeT*& Left(NodeT* p)
    {
        return ((NodeT*&)(*p).f0);
    }
    static NodeT*& Parent(NodeT* p)
    {
        return ((NodeT*&)(*p).f1);
    }
    static NodeT*& Right(NodeT* p)
    {
        return ((NodeT*&)(*p).f2);
    }
    NodeT*& Lmost() const
    {
        return Left(head);
    }
    NodeT*& Root() const
    {
        return Parent(head);
    }
    NodeT*& Rmost() const
    {
        return Right(head);
    }
    static char& IsNil(NodeT* p)
    {
        return ((char&)(*p).isnil);
    }
    void DestroyVal(int* v);
    static void FreeNode(void* p);
    void DestroyNode(NodeT* p)
    {
        int* v = &p->unk0C;
        DestroyVal(v);
        FreeNode(p);
    }
    void FUN_00b3a050(NodeT* rootnode)
    {
        for (NodeT* pnode = rootnode; !IsNil(pnode); rootnode = pnode)
        {
            FUN_00b3a050(Right(pnode));
            pnode = Left(pnode);
            DestroyNode(rootnode);
        }
    }
    void ResetList()
    {
        FUN_00b3a050(Root());
        Root() = head, count = 0;
        Lmost() = head, Rmost() = head;
    }
    TreeIterB3B begin()
    {
        return TreeIterB3B(Lmost(), this);
    }
    TreeIterB3B end()
    {
        return TreeIterB3B(head, this);
    }
    TreeIterB3B MakeIter(TreeConstIterB3B where) const
    {
        return TreeConstIterB3B(where.ptr, this);
    }
    TreeIterB3B EraseOne(TreeConstIterB3B where);
    TreeIterB3B FUN_00b3bb90(TreeConstIterB3B first, TreeConstIterB3B last);
};

inline void TreeIterBaseB3B::SetContainer(const TreeB3B* cont)
{
    if (cont == 0)
        FUN_00ec7c56();
    aux = cont->aux;
}

// @fnv 0x00b3bb90
TreeIterB3B TreeB3B::FUN_00b3bb90(TreeConstIterB3B first, TreeConstIterB3B last)
{
    if (first == begin() && last == end())
    {
        ResetList();
        return begin();
    }
    else
    {
        while (first != last)
            EraseOne(first++);
        return MakeIter(first);
    }
}

inline void Dead2()
{
    int d0;
    int d1;
}
inline void Dead3()
{
    int d0;
    int d1;
    int d2;
}
unsigned int __cdecl FUN_00ec7c56();
void __stdcall FUN_00ec7894(void* p, void* t);
extern int DAT_010173dc;
extern int DAT_01140cb0;
struct FUN_0044a4c0
{
    int m[7];
    FUN_0044a4c0(const char* s);
    void FUN_0044a730(bool b, unsigned int n);
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
};
struct FUN_0044a310
{
    void* vt;
    int m[9];
    FUN_0044a310(const FUN_0044a4c0& s);
};
struct LenErrQ : FUN_0044a310
{
    LenErrQ(const FUN_0044a4c0& s) : FUN_0044a310(s)
    {
        vt = &DAT_010173dc;
    }
};
inline void ThrowLen(const LenErrQ& _Ex)
{
    FUN_00ec7894((void*)&_Ex, &DAT_01140cb0);
}
struct ValQ
{
    int m[14];
};
struct NodeQ
{
    NodeQ* _Left;
    NodeQ* _Parent;
    NodeQ* _Right;
    ValQ _Myval;
    char _Color;
    char _Isnil;
};
struct TreeQ;
struct IterQ
{
    void* _Myaux;
    NodeQ* _Ptr;
    IterQ(NodeQ* p, const TreeQ* t);
};
struct TreeQ
{
    void* _Myownedaux;
    int m04[5];
    NodeQ* _Myhead;
    unsigned int _Mysize;
    static NodeQ*& _Left(NodeQ* p)
    {
        return p->_Left;
    }
    static NodeQ*& _Right(NodeQ* p)
    {
        return p->_Right;
    }
    static NodeQ*& _Parent(NodeQ* p)
    {
        return p->_Parent;
    }
    static char& _Color(NodeQ* p)
    {
        return p->_Color;
    }
    NodeQ*& _Root() const
    {
        return _Parent(_Myhead);
    }
    NodeQ*& _Lmost() const
    {
        return _Left(_Myhead);
    }
    NodeQ*& _Rmost() const
    {
        return _Right(_Myhead);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = 0x4924924;
        Dead3();
        int _Pad;
        return (0 < _Count ? _Count : 1);
    }
    NodeQ* FUN_00ad1960(NodeQ* _Larg, NodeQ* _Parg, NodeQ* _Rarg, const ValQ& _Val, char _Carg);
    void FUN_00ad1800(NodeQ* _Wherenode);
    void FUN_00ad18b0(NodeQ* _Wherenode);
    IterQ FUN_00acf120(bool _Addleft, NodeQ* _Wherenode, const ValQ& _Val);
};
inline IterQ::IterQ(NodeQ* p, const TreeQ* t) : _Myaux(0), _Ptr(p)
{
    if (!(t != 0))
        FUN_00ec7c56();
    _Myaux = t->_Myownedaux;
}
// @fnv 0x00acf120
IterQ TreeQ::FUN_00acf120(bool _Addleft, NodeQ* _Wherenode, const ValQ& _Val)
{
    if (max_size() - 1 <= _Mysize)
    {
        ThrowLen(LenErrQ("map/set<T> too long"));
    }
    NodeQ* _Newnode = FUN_00ad1960(_Myhead, _Wherenode, _Myhead, _Val, 0);
    ++_Mysize;
    if (_Wherenode == _Myhead)
    {
        _Root() = _Newnode;
        _Lmost() = _Newnode;
        _Rmost() = _Newnode;
    }
    else if (_Addleft)
    {
        _Left(_Wherenode) = _Newnode;
        if (_Wherenode == _Lmost())
            _Lmost() = _Newnode;
    }
    else
    {
        _Right(_Wherenode) = _Newnode;
        if (_Wherenode == _Rmost())
            _Rmost() = _Newnode;
    }
    for (NodeQ* _Pnode = _Newnode; _Color(_Parent(_Pnode)) == 0;)
        if (_Parent(_Pnode) == _Left(_Parent(_Parent(_Pnode))))
        {
            _Wherenode = _Right(_Parent(_Parent(_Pnode)));
            if (_Color(_Wherenode) == 0)
            {
                _Color(_Parent(_Pnode)) = 1;
                _Color(_Wherenode) = 1;
                _Color(_Parent(_Parent(_Pnode))) = 0;
                _Pnode = _Parent(_Parent(_Pnode));
            }
            else
            {
                if (_Pnode == _Right(_Parent(_Pnode)))
                {
                    _Pnode = _Parent(_Pnode);
                    FUN_00ad1800(_Pnode);
                }
                _Color(_Parent(_Pnode)) = 1;
                Dead3();
                _Color(_Parent(_Parent(_Pnode))) = 0;
                FUN_00ad18b0(_Parent(_Parent(_Pnode)));
            }
        }
        else
        {
            Dead2();
            _Wherenode = _Left(_Parent(_Parent(_Pnode)));
            if (_Color(_Wherenode) == 0)
            {
                _Color(_Parent(_Pnode)) = 1;
                _Color(_Wherenode) = 1;
                _Color(_Parent(_Parent(_Pnode))) = 0;
                _Pnode = _Parent(_Parent(_Pnode));
            }
            else
            {
                if (_Pnode == _Left(_Parent(_Pnode)))
                {
                    _Pnode = _Parent(_Pnode);
                    FUN_00ad18b0(_Pnode);
                }
                _Color(_Parent(_Pnode)) = 1;
                Dead2();
                _Color(_Parent(_Parent(_Pnode))) = 0;
                FUN_00ad1800(_Parent(_Parent(_Pnode)));
            }
        }
    Dead3();
    _Color(_Root()) = 1;
    return (IterQ(_Newnode, this));
}

void* __cdecl FormHeap_Allocate(unsigned int size);
struct FUN_00b31270
{
    FUN_00b31270();
    ~FUN_00b31270();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct FUN_00449fd0
{
    FUN_00449fd0();
    ~FUN_00449fd0();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct FUN_00b37660;
struct FUN_00b377c0
{
    static void* operator new(unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
    static void operator delete(void* p)
    {}
    FUN_00b377c0(FUN_00b37660* src);
    float x, y, z;
    FUN_00b31270 unk0c;
    FUN_00b31270 unk24;
    FUN_00449fd0 unk3c;
    FUN_00b31270 unk54;
    FUN_00b31270 unk6c;
};
struct S00b37660_Cache
{
    FUN_00b377c0*& FUN_00b39210(InputB37* key);
};
extern S00b37660_Cache DAT_011f8e2c;
struct FUN_00b37660
{
    float x, y, z;
    FUN_00b31270 unk0c;
    FUN_00b31270 unk24;
    FUN_00449fd0 unk3c;
    FUN_00b31270 unk54;
    FUN_00b31270 unk6c;
    FUN_00b37660(InputB37* name);
    void FUN_00b37cc0(InputB37* name);
    void FUN_00b38430(int n);
    void FUN_00b1c7a0(FUN_00b377c0* src);
};
inline void S00b37660_Pad()
{
    int buf[65];
}
// @fnv 0x00b37660
FUN_00b37660::FUN_00b37660(InputB37* name)
{
    FUN_00b377c0* pCached = DAT_011f8e2c.FUN_00b39210(name);
    if (!pCached)
    {
        FUN_00b37cc0(name);
        FUN_00b38430(500);
        FUN_00b377c0* pNew = new FUN_00b377c0(this);
        DAT_011f8e2c.FUN_00b39210(name) = pNew;
        S00b37660_Pad();
    }
    else
    {
        FUN_00b1c7a0(pCached);
    }
}

struct ComplexValue
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ~ComplexValue();
};
struct ScalarTag
{
};
struct ComplexTag
{
};
inline ComplexTag Category(ComplexValue*&, ComplexValue*&)
{
    ComplexTag tag;
    return tag;
}
inline ScalarTag Category(float*&, float*&)
{
    ScalarTag tag;
    return tag;
}
template <class T> struct Alloc
{
    typedef T* pointer;
    void deallocate(T* ptr, unsigned int count)
    {
        ::operator delete(ptr);
    }
    void destroy(T* ptr)
    {
        ptr->~T();
    }
};
template <class A> inline void DestroyRange(typename A::pointer first, typename A::pointer last, A& alloc, ComplexTag)
{
    for (; first != last; ++first)
        alloc.destroy(first);
}
template <class A> inline void DestroyRange(typename A::pointer first, typename A::pointer last, A& alloc, ScalarTag)
{}
template <class A> inline void DestroyRange(typename A::pointer first, typename A::pointer last, A& alloc)
{
    DestroyRange(first, last, alloc, Category(first, last));
}
struct ContainerBase
{
    void* proxy;
    int unk04;
    ~ContainerBase()
    {
        delete proxy;
    }
};
class ComplexVector : public ContainerBase
{
  public:
    Alloc<ComplexValue> alloc;
    ComplexValue* first;
    ComplexValue* last;
    ComplexValue* end;
    void Destroy(ComplexValue* first, ComplexValue* last)
    {
        DestroyRange(first, last, alloc);
    }
    void FUN_00b397f0()
    {
        if (first)
        {
            Destroy(first, last);
            alloc.deallocate(first, end - first);
        }
        first = 0;
        last = 0;
        end = 0;
    }
    ~ComplexVector()
    {
        FUN_00b397f0();
    }
};
class ScalarVector : public ContainerBase
{
  public:
    Alloc<float> alloc;
    float* first;
    float* last;
    float* end;
    void Destroy(float* first, float* last)
    {
        DestroyRange(first, last, alloc);
    }
    void FUN_0065f240()
    {
        if (first)
        {
            Destroy(first, last);
            alloc.deallocate(first, end - first);
        }
        first = 0;
        last = 0;
        end = 0;
    }
    ~ScalarVector()
    {
        FUN_0065f240();
    }
};
class FUN_00b37880_class
{
  public:
    int unk00, unk04, unk08;
    ComplexVector m0c;
    ComplexVector m24;
    ScalarVector m3c;
    ComplexVector m54;
    ComplexVector m6c;
    ~FUN_00b37880_class();
};
// @fnv 0x00b37880
FUN_00b37880_class::~FUN_00b37880_class()
{}

namespace fnv_00b37a00 {
extern "C" void __cdecl FormHeap_Free(void* p);

struct Sound_b37a
{
    void FUN_00b37880();
    ~Sound_b37a()
    {
        FUN_00b37880();
    }
    static void operator delete(void* p)
    {
        FormHeap_Free(p);
    }
};

struct Key_b37a
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};

struct Pair_b37a
{
    Key_b37a first;
    Sound_b37a* second;
};

struct Node_b37a
{
    Node_b37a* _Left;
    Node_b37a* _Parent;
    Node_b37a* _Right;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    char unk2c;
    char _Isnil;
};
struct Map_b37a;

struct MapIter_b37a
{
    const Map_b37a* _Mycont;
    Node_b37a* _Ptr;

    MapIter_b37a() : _Mycont(0), _Ptr(0)
    {}
    inline MapIter_b37a(Node_b37a* _Pnode, const Map_b37a* _Plist);
    bool FUN_00b16830(const MapIter_b37a& _Right) const;
    Pair_b37a* FUN_00b3b090() const;
    MapIter_b37a& FUN_00b3b100()
    {
        if (_Mycont == 0)
            FUN_00ec7c56();
        if (_Ptr->_Isnil)
        {
            FUN_00ec7c56();
        }
        else if (!_Ptr->_Right->_Isnil)
        {
            Node_b37a* pNode = _Ptr->_Right;
            while (!pNode->_Left->_Isnil)
                pNode = pNode->_Left;
            _Ptr = pNode;
        }
        else
        {
            Node_b37a* pParent;
            while (!(pParent = _Ptr->_Parent)->_Isnil && _Ptr == pParent->_Right)
                _Ptr = pParent;
            _Ptr = pParent;
        }
        return *this;
    }
};

struct Map_b37a
{
    const Map_b37a* _Myownedproxy;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Node_b37a* _Myhead;
    int _Mysize;

    MapIter_b37a GetVtblAndValue();
    void FUN_00b3a050(Node_b37a* _Rootnode);
    MapIter_b37a end()
    {
        return MapIter_b37a(_Myhead, this);
    }
    void ResetList()
    {
        Node_b37a* pRoot = _Myhead->_Parent;
        FUN_00b3a050(pRoot);
        Node_b37a* pHead = _Myhead;
        Node_b37a*& rRoot = pHead->_Parent;
        Node_b37a*& rLeftmost = pHead->_Left;
        Node_b37a*& rRightmost = pHead->_Right;
        rRoot = pHead;
        _Mysize = 0;
        rLeftmost = pHead;
        rRightmost = pHead;
    }
};

inline MapIter_b37a::MapIter_b37a(Node_b37a* _Pnode, const Map_b37a* _Plist) : _Mycont(0), _Ptr(_Pnode)
{
    if (_Plist == 0)
        FUN_00ec7c56();
    _Mycont = _Plist->_Myownedproxy;
}

extern Map_b37a DAT_011f8e2c;

// @fnv 0x00b37a00
void __cdecl FUN_00b37a00()
{
    for (MapIter_b37a it = DAT_011f8e2c.GetVtblAndValue(); it.FUN_00b16830(DAT_011f8e2c.end()); it.FUN_00b3b100())
    {
        delete it.FUN_00b3b090()->second;
        it.FUN_00b3b090()->second = 0;
    }
    DAT_011f8e2c.ResetList();
}
}  // namespace fnv_00b37a00

struct ValueB380
{
    float m00, m04, m08, m0c, m10;
    int m14;
    ValueB380(float, float);
    ~ValueB380();
    void NormalizeData();
    ValueB380 ScaleData(float) const;
    ValueB380 FUN_00b3c660(const ValueB380&) const;
    ValueB380 Subtract(const ValueB380&) const;
};
template <class T> struct VectorB380
{
    int m00, m04, m08;
    T* m0c;
    T* m10;
    T* m14;
    bool empty() const
    {
        return m10 - m0c == 0;
    }
    unsigned size() const
    {
        return m10 - m0c;
    }
    T& at(unsigned index)
    {
        if (index >= unsigned(m10 - m0c))
            FUN_00ec7c56();
        return m0c[index];
    }
    void FUN_00b39100(const T&);
    void PushBack(const T&);
};
struct OwnerB380
{
    int m00, m04, m08;
    VectorB380<ValueB380> m0c, m24;
    VectorB380<float> m3c;
    int m54, m58, m5c, m60, m64, m68;
    VectorB380<ValueB380> m6c;
    void FUN_00b380e0(VecB37*, VecB37*, float);
};
inline void FrameB380()
{
    int unused[103];
    (void)&unused;
}
// @fnv 0x00b380e0
void OwnerB380::FUN_00b380e0(VecB37* first, VecB37* second, float scale)
{
    ValueB380 a(first->x, first->y);
    ValueB380 direction(second->x, second->y);
    direction.NormalizeData();
    if (!m0c.empty())
    {
        unsigned index = m0c.size() - 1;
        m6c.FUN_00b39100(m0c.at(index).FUN_00b3c660(m24.at(index).ScaleData(m3c.at(index))));
        m6c.FUN_00b39100(a.Subtract(direction.ScaleData(scale)));
    }
    m0c.FUN_00b39100(a);
    m6c.FUN_00b39100(a);
    m24.FUN_00b39100(direction);
    m3c.PushBack(scale);
    FrameB380();
}

inline float Lerp_b38f40(float a, float b, float t)
{
    return a + (b - a) * t;
}

struct Pt_b38f40
{
    float x;
    float y;
};

struct Pos_b38f40 : public FUN_00b3c500
{
    Pos_b38f40(float a, float b) : FUN_00b3c500(a, b)
    {}
    ~Pos_b38f40()
    {}
};

class Spl_b38f40
{
  public:
    Pos_b38f40 FUN_00b38f40(Pt_b38f40* p0, Pt_b38f40* p1, Pt_b38f40* p2, Pt_b38f40* p3, float t);
};

// @fnv 0x00b38f40
Pos_b38f40 Spl_b38f40::FUN_00b38f40(Pt_b38f40* p0, Pt_b38f40* p1, Pt_b38f40* p2, Pt_b38f40* p3, float t)
{
    float g = Lerp_b38f40(p0->x, p1->x, t);
    float bb = Lerp_b38f40(p0->y, p1->y, t);
    float m = Lerp_b38f40(p1->x, p2->x, t);
    float by = Lerp_b38f40(p1->y, p2->y, t);
    float d = Lerp_b38f40(p2->x, p3->x, t);
    float cy = Lerp_b38f40(p2->y, p3->y, t);
    float ex = Lerp_b38f40(g, m, t);
    float ax = Lerp_b38f40(bb, by, t);
    float z = Lerp_b38f40(m, d, t);
    float y4 = Lerp_b38f40(by, cy, t);
    return Pos_b38f40(Lerp_b38f40(ex, z, t), Lerp_b38f40(ax, y4, t));
}

// Reuses supplied independent string/error helper model with credit.
// Supplied other-agent vector model reused withcredit; new swap/move helpers below.
namespace asgnb36 {
extern "C" unsigned int __cdecl strlen(const char* _Str);
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxBadAlloc
{
    const char* pWhat;
    int iDoFree;
    BxBadAlloc(const char* what);
    ~BxBadAlloc();
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(count * sizeof(T));
}
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            _Tidy(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

}
struct TreeString
{
    char allocator;
    union Storage
    {
        char text[16];
        char* pointer;
    } storage;
    unsigned length, capacity;
    static int textCompare(const char*, const char*, unsigned);
    static void rangeError();
    const char* data() const
    {
        return capacity < 16 ? storage.text : storage.pointer;
    }
    unsigned size() const
    {
        return length;
    }
    int compare(unsigned offset, unsigned count, const char* text, unsigned otherCount) const
    {
        if (length < offset)
            rangeError();
        if (length - offset < count)
            count = length - offset;
        unsigned answer = textCompare(data() + offset, text, count < otherCount ? count : otherCount);
        return answer != 0 ? (int)answer : count < otherCount ? -1 : count == otherCount ? 0 : 1;
    }
    int FUN_00ac9da0(const TreeString& right) const
    {
        const TreeString* receiver = this;
        return receiver->compare(0, receiver->length, right.data(), right.size());
    }
};
inline bool operator<(const TreeString& left, const TreeString& right)
{
    return left.FUN_00ac9da0(right) < 0;
}
struct TreeValue
{
    TreeString first;
    int second;
};
struct TreeNode
{
    TreeNode *left, *parent, *right;
    TreeValue value;
    char color, nil;
};
struct HintTree;
struct FUN_00b3b050
{
    const HintTree* owner;
    TreeNode* node;
    FUN_00b3b050() : owner(0), node(0)
    {}
    FUN_00b3b050(TreeNode*, const HintTree*);
    FUN_00b3b050& FUN_00b3b440();
    FUN_00b3b050& FUN_00b3b100();

    TreeNode* _Mynode() const
    {
        return node;
    }
    bool hasContainer() const
    {
        return owner != 0;
    }
    bool sameContainer(const FUN_00b3b050& other) const
    {
        return owner == other.owner;
    }
    bool equal(const FUN_00b3b050& other) const
    {
        if (!(hasContainer() && sameContainer(other)))
            FUN_00ec7c56();
        return node == other.node;
    }
};
struct TreeIterator : FUN_00b3b050
{
    TreeIterator()
    {}
    bool FUN_00b2ac30(const TreeIterator&) const;
    TreeIterator& FUN_00b3b440()
    {
        FUN_00b3b050::FUN_00b3b440();
        return *this;
    }
    TreeIterator& FUN_00b3b100()
    {
        FUN_00b3b050::FUN_00b3b100();
        return *this;
    }
    TreeIterator(TreeNode* p, const HintTree* tree) : FUN_00b3b050(p, tree)
    {}
};
struct TreeInsertResult
{
    TreeIterator first;
    bool second;
};
struct KeyLess
{
    bool operator()(const TreeString& left, const TreeString& right) const
    {
        return left < right;
    }
};
struct HintTree
{
    KeyLess compare;
    int state04, state08, state0c, state10, state14;
    TreeNode* head;
    unsigned int count;
    unsigned int size() const
    {
        return count;
    }
    static TreeNode*& _Parent(TreeNode* p)
    {
        return p->parent;
    }
    static char& _Color(TreeNode* p)
    {
        return p->color;
    }
    TreeNode*& _Root() const
    {
        return _Parent(head);
    }
    static TreeNode*& _Left(TreeNode* p)
    {
        return p->left;
    }
    static TreeNode*& _Right(TreeNode* p)
    {
        return p->right;
    }
    static char& _Isnil(TreeNode* p)
    {
        return p->nil;
    }
    static TreeValue& _Myval(TreeNode* p)
    {
        return p->value;
    }
    static const TreeString& _Kfn(const TreeValue& value)
    {
        return value.first;
    }
    static const TreeString& _Key(TreeNode* p)
    {
        return _Kfn(_Myval(p));
    }
    TreeNode*& _Lmost() const
    {
        return _Left(head);
    }
    TreeNode*& _Rmost() const
    {
        return _Right(head);
    }
    TreeIterator begin()
    {
        return TreeIterator(_Lmost(), this);
    }
    TreeIterator end()
    {
        return TreeIterator(head, this);
    }
    unsigned max_size() const
    {
        unsigned maximum = (unsigned)-1 / sizeof(TreeValue);
        return maximum > 0 ? maximum : 1;
    }
    TreeNode* FUN_00b3b330(TreeNode*, TreeNode*, TreeNode*, const TreeValue&, char);
    void FUN_00b3b1d0(TreeNode*);
    void FUN_00b3b280(TreeNode*);
    TreeIterator FUN_00b3ac00(bool, TreeNode*, const TreeValue&);
    TreeInsertResult FUN_00b3a9b0(const TreeValue&);
    TreeIterator FUN_00b398c0(TreeIterator where, const TreeValue& value);
};
// @fnv 0x00b398c0
TreeIterator HintTree::FUN_00b398c0(TreeIterator where, const TreeValue& value)
{
    TreeIterator next;
    if (size() == 0)
        return FUN_00b3ac00(true, head, value);
    else if (false)
    {
        if (where.equal(begin()))
        {
            if (!(compare(_Key(where._Mynode()), _Kfn(value))))
                return FUN_00b3ac00(true, where._Mynode(), value);
        }
        else if (where.equal(end()))
        {
            if (!(compare(_Kfn(value), _Key(_Rmost()))))
                return FUN_00b3ac00(false, _Rmost(), value);
        }
        else if (!(compare(_Key(where._Mynode()), _Kfn(value))) &&
                 !(compare(_Kfn(value), _Key((next = where).FUN_00b3b440()._Mynode()))))
        {
            if (_Isnil(_Right(next._Mynode())))
                return FUN_00b3ac00(false, next._Mynode(), value);
            else
                return FUN_00b3ac00(true, where._Mynode(), value);
        }
        else if (!(compare(_Kfn(value), _Key(where._Mynode()))) &&
                 ((next = where).FUN_00b3b100().equal(end()) || !(compare(_Key(next._Mynode()), _Kfn(value)))))
        {
            if (_Isnil(_Right(where._Mynode())))
                return FUN_00b3ac00(false, where._Mynode(), value);
            else
                return FUN_00b3ac00(true, next._Mynode(), value);
        }
    }
    else
    {
        if (where.FUN_00b2ac30(begin()))
        {
            if (compare(_Kfn(value), _Key(where._Mynode())))
                return FUN_00b3ac00(true, where._Mynode(), value);
        }
        else if (where.FUN_00b2ac30(end()))
        {
            if (compare(_Key(_Rmost()), _Kfn(value)))
                return FUN_00b3ac00(false, _Rmost(), value);
        }
        else if (compare(_Kfn(value), _Key(where._Mynode())) &&
                 compare(_Key((next = where).FUN_00b3b440()._Mynode()), _Kfn(value)))
        {
            if (_Isnil(_Right(next._Mynode())))
                return FUN_00b3ac00(false, next._Mynode(), value);
            else
                return FUN_00b3ac00(true, where._Mynode(), value);
        }
        else if (compare(_Key(where._Mynode()), _Kfn(value)) &&
                 ((next = where).FUN_00b3b100().FUN_00b2ac30(end()) || compare(_Kfn(value), _Key(next._Mynode()))))
        {
            if (_Isnil(_Right(where._Mynode())))
                return FUN_00b3ac00(false, where._Mynode(), value);
            else
                return FUN_00b3ac00(true, next._Mynode(), value);
        }
    }
    return FUN_00b3a9b0(value).first;
}

inline TreeIterator HintTree::FUN_00b3ac00(bool addLeft, TreeNode* parent, const TreeValue& value)
{
    if (max_size() - 1 <= count)
        throw asgnb36::BxLengthError("map/set<T> too long");
    TreeNode* added = FUN_00b3b330(head, parent, head, value, 0);
    ++count;
    if (parent == head)
    {
        _Root() = added;
        _Lmost() = added;
        _Rmost() = added;
    }
    else if (addLeft)
    {
        _Left(parent) = added;
        if (parent == _Lmost())
            _Lmost() = added;
    }
    else
    {
        _Right(parent) = added;
        if (parent == _Rmost())
            _Rmost() = added;
    }
    for (TreeNode* node = added; _Color(_Parent(node)) == 0;)
    {
        if (_Parent(node) == _Left(_Parent(_Parent(node))))
        {
            parent = _Right(_Parent(_Parent(node)));
            if (_Color(parent) == 0)
            {
                _Color(_Parent(node)) = 1;
                _Color(parent) = 1;
                _Color(_Parent(_Parent(node))) = 0;
                node = _Parent(_Parent(node));
            }
            else
            {
                if (node == _Right(_Parent(node)))
                {
                    node = _Parent(node);
                    FUN_00b3b1d0(node);
                }
                _Color(_Parent(node)) = 1;
                _Color(_Parent(_Parent(node))) = 0;
                FUN_00b3b280(_Parent(_Parent(node)));
            }
        }
        else
        {
            parent = _Left(_Parent(_Parent(node)));
            if (_Color(parent) == 0)
            {
                _Color(_Parent(node)) = 1;
                _Color(parent) = 1;
                _Color(_Parent(_Parent(node))) = 0;
                node = _Parent(_Parent(node));
            }
            else
            {
                if (node == _Left(_Parent(node)))
                {
                    node = _Parent(node);
                    FUN_00b3b280(node);
                }
                _Color(_Parent(node)) = 1;
                _Color(_Parent(_Parent(node))) = 0;
                FUN_00b3b1d0(_Parent(_Parent(node)));
            }
        }
    }
    _Color(_Root()) = 1;
    return TreeIterator(added, this);
}

namespace fnv_00b3a9b0 {
inline void Dead1()
{
    int d0;
}
inline void Dead20()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
}
inline void Dead21()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
}

unsigned int __cdecl FUN_00ec7c56();
struct StrQ
{
    int m[7];
    int FUN_00ac9da0(const StrQ& r) const;
};
inline bool operator<(const StrQ& l, const StrQ& r)
{
    return l.FUN_00ac9da0(r) < 0;
}
struct ValQ
{
    StrQ first;
    int second;
};
struct NodeQ
{
    NodeQ* _Left;
    NodeQ* _Parent;
    NodeQ* _Right;
    ValQ _Myval;
    char _Color;
    char _Isnil;
};
struct TreeQ;
struct FUN_00b3b050
{
    TreeQ* _Mycont;
    NodeQ* _Ptr;
    FUN_00b3b050()
    {}
    FUN_00b3b050(NodeQ* p, TreeQ* c);
    FUN_00b3b050& FUN_00b3b440();
    NodeQ* _Mynode() const
    {
        return _Ptr;
    }
    bool _Has_container() const
    {
        return _Mycont != 0;
    }
    bool _Same_container(const FUN_00b3b050& r) const
    {
        return _Mycont == r._Mycont;
    }
    bool operator==(const FUN_00b3b050& r) const
    {
        if (!(_Has_container() && _Same_container(r)))
            FUN_00ec7c56();
        return _Ptr == r._Ptr;
    }
};
struct PairQ
{
    FUN_00b3b050 first;
    bool second;
    PairQ(const FUN_00b3b050& a, const bool& b) : first(a), second(b)
    {}
};
struct TreeQ
{
    enum
    {
        _Multi = 0
    };
    int m00[6];
    NodeQ* _Myhead;
    static char& _Isnil(NodeQ* p)
    {
        return p->_Isnil;
    }
    static NodeQ*& _Left(NodeQ* p)
    {
        return p->_Left;
    }
    static NodeQ*& _Right(NodeQ* p)
    {
        return p->_Right;
    }
    static NodeQ*& _Parent(NodeQ* p)
    {
        return p->_Parent;
    }
    static const StrQ& _Key(NodeQ* p)
    {
        return p->_Myval.first;
    }
    static const StrQ& _Kfn(const ValQ& v)
    {
        return v.first;
    }
    NodeQ*& _Root() const
    {
        return _Parent(_Myhead);
    }
    NodeQ* _Lmost() const
    {
        return _Left(_Myhead);
    }
    FUN_00b3b050 begin()
    {
        return FUN_00b3b050(_Lmost(), this);
    }
    FUN_00b3b050 FUN_00b3ac00(bool _Addleft, NodeQ* _Wherenode, const ValQ& _Val);
    PairQ FUN_00b3a9b0(const ValQ& _Val);
};
// @fnv 0x00b3a9b0
PairQ TreeQ::FUN_00b3a9b0(const ValQ& _Val)
{
    NodeQ* _Trynode = _Root();
    NodeQ* _Wherenode = _Myhead;
    bool _Addleft = true;
    while (!_Isnil(_Trynode))
    {
        _Wherenode = _Trynode;
        _Addleft = _Kfn(_Val) < _Key(_Trynode);
        _Trynode = _Addleft ? _Left(_Trynode) : _Right(_Trynode);
    }
    if (_Multi)
    {
        Dead20();
        return PairQ(FUN_00b3ac00(_Addleft, _Wherenode, _Val), true);
    }
    else
    {
        FUN_00b3b050 _Where = FUN_00b3b050(_Wherenode, this);
        if (!_Addleft)
            ;
        else if (_Where == begin())
            return PairQ(FUN_00b3ac00(true, _Wherenode, _Val), true);
        else
            _Where.FUN_00b3b440();
        if (_Key(_Where._Mynode()) < _Kfn(_Val))
        {
            Dead1();
            return PairQ(FUN_00b3ac00(_Addleft, _Wherenode, _Val), true);
        }
        else
            return PairQ(_Where, false);
    }
}
}  // namespace fnv_00b3a9b0

struct Key
{
    char allocator;
    union Storage
    {
        char text[16];
        char* pointer;
    } storage;
    unsigned length, capacity;
    static int textCompare(const char*, const char*, unsigned);
    static void rangeError();
    const char* data() const
    {
        return capacity < 16 ? storage.text : storage.pointer;
    }
    unsigned size() const
    {
        return length;
    }
    int compare(unsigned offset, unsigned count, const char* text, unsigned otherCount) const
    {
        if (length < offset)
            rangeError();
        if (length - offset < count)
            count = length - offset;
        unsigned answer = textCompare(data() + offset, text, count < otherCount ? count : otherCount);
        return answer != 0 ? (int)answer : count < otherCount ? -1 : count == otherCount ? 0 : 1;
    }
    int FUN_00ac9da0(const Key& right) const
    {
        const Key* receiver = this;
        return receiver->compare(0, receiver->length, right.data(), right.size());
    }
};
struct Node
{
    Node *left, *parent, *right;
    Key key;
    unsigned mapped;
    signed char color, isNil;
};
inline bool operator<(const Key& left, const Key& right)
{
    return left.FUN_00ac9da0(right) < 0;
}
struct Less
{
    bool operator()(const Key& left, const Key& right) const
    {
        return left < right;
    }
};
struct Tree
{
    Less compare;
    unsigned unk04, unk08, unk0c, unk10, unk14;
    Node* head;
    Node* FUN_00b3afe0(const Key& key);
};
// @fnv 0x00b3afe0
Node* Tree::FUN_00b3afe0(const Key& key)
{
    Node* node = head->parent;
    Node* lowerBound = head;
    while (!node->isNil)
    {
        if (compare(node->key, key))
            node = node->right;
        else
        {
            lowerBound = node;
            node = node->left;
        }
    }
    return lowerBound;
}

struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct ValT
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
template <class _Ty> struct _Tree_nodeS
{
    _Tree_nodeS* _Left;
    _Tree_nodeS* _Parent;
    _Tree_nodeS* _Right;
    _Ty _Myval;
    char _Color;
    char _Isnil;
};
struct lessS
{
};
template <class _Ty> class _Tmap_traitsS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    lessS comp;
};
template <class _Ty> class _Tree_nodS : public _Tmap_traitsS<_Ty>
{
  public:
    allocatorS<_Tree_nodeS<_Ty> > _Alnod;
};
template <class _Ty> class _Tree_ptrS : public _Tree_nodS<_Ty>
{
  public:
    allocatorS<_Tree_nodeS<_Ty>*> _Alptr;
};
template <class _Ty> class _Tree_valS : public _Tree_ptrS<_Ty>
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class _TreeS : public _Tree_valS<_Ty>
{
  public:
    typedef _Tree_nodeS<_Ty>* _Nodeptr;
    static _Nodeptr& _Left(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Left);
    }
    static _Nodeptr& _Parent(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Parent);
    }
    static _Nodeptr& _Right(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Right);
    }
    static char& _Isnil(_Nodeptr _Pnode)
    {
        return ((char&)(*_Pnode)._Isnil);
    }
    static _Nodeptr _Max(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Right(_Pnode)))
            _Pnode = _Right(_Pnode);
        return (_Pnode);
    }
    static _Nodeptr _Min(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Left(_Pnode)))
            _Pnode = _Left(_Pnode);
        return (_Pnode);
    }
    _Nodeptr _Myhead;
    unsigned int _Mysize;
};
template <class _Ty> class _BiditS : public _Iterator_base_auxS
{
};
template <class _Ty> class _Tree_const_iteratorS : public _BiditS<_Ty>
{
  public:
    typedef _TreeS<_Ty> _Myt;
    typedef typename _Myt::_Nodeptr _Nodeptr;
    _Nodeptr _Ptr;
};
class FUN_00b3b090_Iterator : public _Tree_const_iteratorS<ValT>
{
  public:
    const ValT& FUN_00b3b090() const;
};

// @fnv 0x00b3b090
const ValT& FUN_00b3b090_Iterator::FUN_00b3b090() const
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoS();
    if (!(_Ptr != ((_Myt*)(this->_Getmycont()))->_Myhead))
        InvalidParameterNoInfoS();
    return (_Ptr->_Myval);
}

namespace fnv_00b3b440 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct ValT
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
template <class _Ty> struct _Tree_nodeS
{
    _Tree_nodeS* _Left;
    _Tree_nodeS* _Parent;
    _Tree_nodeS* _Right;
    _Ty _Myval;
    char _Color;
    char _Isnil;
};
struct lessS
{
};
template <class _Ty> class _TreeS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    typedef _Tree_nodeS<_Ty>* _Nodeptr;
    static _Nodeptr& _Left(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Left);
    }
    static _Nodeptr& _Parent(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Parent);
    }
    static _Nodeptr& _Right(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Right);
    }
    static char& _Isnil(_Nodeptr _Pnode)
    {
        return ((char&)(*_Pnode)._Isnil);
    }
    static _Nodeptr _Max(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Right(_Pnode)))
            _Pnode = _Right(_Pnode);
        return (_Pnode);
    }
    static _Nodeptr _Min(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Left(_Pnode)))
            _Pnode = _Left(_Pnode);
        return (_Pnode);
    }
    lessS comp;
    allocatorS<_Tree_nodeS<_Ty> > _Alnod;
    allocatorS<_Nodeptr> _Alptr;
    allocatorS<_Ty> _Alval;
    _Nodeptr _Myhead;
    unsigned int _Mysize;
};
template <class _Ty> class _BiditS : public _Iterator_base_auxS
{
};
template <class _Ty> class _Tree_const_iteratorS : public _BiditS<_Ty>
{
  public:
    typedef _TreeS<_Ty> _Myt;
    typedef typename _Myt::_Nodeptr _Nodeptr;
    _Nodeptr _Ptr;
};
class FUN_00b3b440_Iterator : public _Tree_const_iteratorS<ValT>
{
  public:
    void FUN_00b3b440();
};

// @fnv 0x00b3b440
void FUN_00b3b440_Iterator::FUN_00b3b440()
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoS();
    if (_Myt::_Isnil(_Ptr))
    {
        _Ptr = _Myt::_Right(_Ptr);
        if (_Myt::_Isnil(_Ptr))
        {
            InvalidParameterNoInfoS();
        }
    }
    else if (!_Myt::_Isnil(_Myt::_Left(_Ptr)))
        _Ptr = _Myt::_Max(_Myt::_Left(_Ptr));
    else
    {
        _Nodeptr _Pnode;
        while (!_Myt::_Isnil(_Pnode = _Myt::_Parent(_Ptr)) && _Ptr == _Myt::_Left(_Pnode))
            _Ptr = _Pnode;
        if (_Myt::_Isnil(_Ptr))
        {
            InvalidParameterNoInfoS();
        }
        else
            _Ptr = _Pnode;
    }
}
}  // namespace fnv_00b3b440

namespace fnv_00b3b5a0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct ElemB5A0
{
    int unk00;
    int unk04;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);

// @fnv 0x00b3b5a0
ElemB5A0* __cdecl FUN_00b3b5a0(ElemB5A0* _First, ElemB5A0* _Last, ElemB5A0* _Dest, allocatorS<ElemB5A0>& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b3b5a0

void FormHeap_Free(void* p);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
struct ElQ
{
    int m[6];
    ~ElQ();
};
__forceinline void Del(ElQ* p, unsigned int f)
{
    p->~ElQ();
}
inline void Construct(ElQ* p, const ElQ& v)
{
    void* vp = p;
    ::new (vp) ElQ(v);
}
// @fnv 0x00b3b5f0
void FUN_00b3b5f0(ElQ* first, unsigned int n, const ElQ& val)
{
    ElQ* next = first;
    try
    {
        for (; n > 0; --n, ++first)
            Construct(first, val);
    }
    catch (...)
    {
        for (; next != first; ++next)
            Del(next, 0);
        throw;
    }
}

namespace fnv_00b3b6f0 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
struct ElemMOVE
{
    int unk00;
    int unk04;
};
// @fnv 0x00b3b6f0
ElemMOVE* __cdecl FUN_00b3b6f0(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b3b6f0

namespace fnv_00b3b880 {
inline void* __cdecl operator new(unsigned int, void* where)
{
    return where;
}

namespace std {

class exception
{
  public:
    exception(const char* const& msg);
    virtual ~exception();
    int u4;
    int u8;
};

class bad_alloc : public exception
{
  public:
    bad_alloc(const char* const& msg) : exception(msg)
    {}
};

template <class _Ty> inline _Ty* _Allocate(unsigned int _Count, _Ty*)
{
    if (_Count <= 0)
        _Count = 0;
    else if (((unsigned int)(-1) / _Count) < sizeof(_Ty))
        throw bad_alloc(0);
    return (_Ty*)::operator new(_Count * sizeof(_Ty));
}

template <class _T1, class _T2> inline void _Construct(_T1* _Ptr, const _T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) _T1(_Val);
}

template <class _Ty> inline void _Destroy(_Ty* _Ptr)
{
    _Ptr->~_Ty();
}

template <class _Ty> class allocator
{
  public:
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    pointer allocate(size_type _Count)
    {
        unsigned int x = _Count;
        unsigned int s1, s2, s3, s4;
        s1 = x;
        s2 = s1;
        s3 = s2;
        s4 = s3;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        x = x + 1;
        return _Allocate(x, (pointer)0);
    }
    void deallocate(pointer _Ptr, size_type)
    {
        ::operator delete(_Ptr);
    }
    void construct(pointer _Ptr, const _Ty& _Val)
    {
        _Construct(_Ptr, _Val);
    }
    void destroy(pointer _Ptr)
    {
        _Destroy(_Ptr);
    }
};

}

struct NodeX
{
    NodeX* _Left;
    NodeX* _Parent;
    NodeX* _Right;
    int v0c, v10, v14, v18, v1c, v20, v24, v28;
    char _Color;
    char _Isnil;
};

struct Tree
{
    int unk00;
    int unk04;
    int unk08;
    std::allocator<NodeX> _Alnod;
    std::allocator<NodeX*> _Alptr;

    static NodeX*& _Left(NodeX* _Pnode)
    {
        return _Pnode->_Left;
    }
    static NodeX*& _Parent(NodeX* _Pnode)
    {
        return _Pnode->_Parent;
    }
    static NodeX*& _Right(NodeX* _Pnode)
    {
        return _Pnode->_Right;
    }
    static char& _Color(NodeX* _Pnode)
    {
        return _Pnode->_Color;
    }
    static char& _Isnil(NodeX* _Pnode)
    {
        return _Pnode->_Isnil;
    }

    NodeX* FUN_00b3b880();
};

// @fnv 0x00b3b880
NodeX* Tree::FUN_00b3b880()
{
    NodeX* _Wherenode = this->_Alnod.allocate(1);
    int _Linkcnt = 0;
    try
    {
        this->_Alptr.construct(&_Left(_Wherenode), 0);
        ++_Linkcnt;
        this->_Alptr.construct(&_Parent(_Wherenode), 0);
        ++_Linkcnt;
        this->_Alptr.construct(&_Right(_Wherenode), 0);
    }
    catch (...)
    {
        if (1 < _Linkcnt)
            this->_Alptr.destroy(&_Parent(_Wherenode));
        if (0 < _Linkcnt)
            this->_Alptr.destroy(&_Left(_Wherenode));
        this->_Alnod.deallocate(_Wherenode, 1);
        throw;
    }
    _Color(_Wherenode) = 1;
    _Isnil(_Wherenode) = 0;
    return _Wherenode;
}
}  // namespace fnv_00b3b880

void __cdecl operator delete(void*);
void CopyStringStorage(char*, unsigned int, const char*, unsigned int);
namespace std {
template <class T> struct char_traits;
template <class T> class allocator
{
  public:
    unsigned int state;
    void deallocate(T* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
template <class C, class T, class A> class basic_string;
template <> class basic_string<char, char_traits<char>, allocator<char> >
{
  public:
    allocator<char> allocatorState;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize, _Myres;
    basic_string(const char*);
    basic_string(const basic_string&);
    ~basic_string()
    {
        _Tidy(true, 0);
    }

  protected:
    void _Eos(unsigned int _Newsize)
    {
        _Mysize = _Newsize;
        _Bx._Buf[_Newsize] = 0;
    }
    void _Tidy(bool _Built, unsigned int _Newsize)
    {
        if (!_Built)
            ;
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                CopyStringStorage(_Bx._Buf, 16, _Ptr, _Newsize);
            allocatorState.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 15;
        _Eos(_Newsize);
    }

  public:
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
class exception
{
  public:
    virtual ~exception();
    virtual const char* what() const;
    const char* _m_what;
    int _m_doFree;
};
class logic_error : public exception
{
  public:
    logic_error(const string&);
    virtual ~logic_error();
    virtual const char* what() const;
    string _Str;
};
class out_of_range : public logic_error
{
  public:
    out_of_range(const string& _Message) : logic_error(_Message)
    {}
    virtual ~out_of_range()
    {}
};
}
void __cdecl operator delete(void*);
namespace std {
template <class A, class B> struct pair
{
    A first;
    B second;
};
}
struct EraseNode
{
    EraseNode* _Left;
    EraseNode* _Parent;
    EraseNode* _Right;
    std::pair<const std::string, float> _Myval;
    char _Color;
    char _Isnil;
};
struct EraseIteratorBase
{
    void* _Myaux;
    EraseIteratorBase() : _Myaux(0)
    {}
    template <class C> void _Set_container(const C* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
};
template <class V> inline void DestroyValue(V* _Ptr)
{
    _Ptr->~V();
}
template <class V> struct NodeAllocatorT
{
    unsigned int state;
    void destroy(V* _Ptr)
    {
        DestroyValue(_Ptr);
    }
    void deallocate(V* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
template <class T> inline void SwapValue(T& _Left, T& _Right)
{
    if (&_Left != &_Right)
    {
        T _Tmp = _Left;
        _Left = _Right;
        _Right = _Tmp;
    }
}
template <class Value> struct EraseTree
{
    typedef EraseNode* _Nodeptr;
    void* _Myownedaux;
    unsigned int comparatorState;
    unsigned int auxiliaryAllocatorState;
    NodeAllocatorT<EraseNode> _Alnod;
    unsigned int pointerAllocatorState;
    unsigned int valueAllocatorState;
    EraseNode* _Myhead;
    unsigned int _Mysize;
    enum
    {
        _Red,
        _Black
    };
    static char& _Color(_Nodeptr _Pnode)
    {
        return _Pnode->_Color;
    }
    static char& _Isnil(_Nodeptr _Pnode)
    {
        return _Pnode->_Isnil;
    }
    static _Nodeptr& _Left(_Nodeptr _Pnode)
    {
        return _Pnode->_Left;
    }
    static _Nodeptr& _Right(_Nodeptr _Pnode)
    {
        return _Pnode->_Right;
    }
    static _Nodeptr& _Parent(_Nodeptr _Pnode)
    {
        return _Pnode->_Parent;
    }
    static _Nodeptr _Min(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Left(_Pnode)))
            _Pnode = _Left(_Pnode);
        return _Pnode;
    }
    static _Nodeptr _Max(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Right(_Pnode)))
            _Pnode = _Right(_Pnode);
        return _Pnode;
    }
    _Nodeptr& _Root() const
    {
        return _Parent(_Myhead);
    }
    _Nodeptr& _Lmost() const
    {
        return _Left(_Myhead);
    }
    _Nodeptr& _Rmost() const
    {
        return _Right(_Myhead);
    }
    struct const_iterator : EraseIteratorBase
    {
        _Nodeptr _Ptr;
        const_iterator() : _Ptr(0)
        {}
        const_iterator(_Nodeptr _Pnode, const EraseTree* _Plist) : _Ptr(_Pnode)
        {
            if (_Plist == 0)
                FUN_00ec7c56();
            this->_Set_container(_Plist);
        }
        _Nodeptr _Mynode() const
        {
            return _Ptr;
        }
        void Increment()
        {
            if (!_Has_container())
                FUN_00ec7c56();
            _Nodeptr _Node = _Ptr;
            if (_Isnil(_Node))
            {
                FUN_00ec7c56();
            }
            else if (!_Isnil(_Right(_Ptr)))
            {
                _Ptr = _Min(_Right(_Ptr));
            }
            else
            {
                EraseNode* _Pnode;
                while (!_Isnil(_Pnode = _Parent(_Ptr)) && _Ptr == _Right(_Pnode))
                    _Ptr = _Pnode;
                _Ptr = _Pnode;
            }
        }

        const_iterator& operator++()
        {
            Increment();
            return *this;
        }
    };
    struct iterator : const_iterator
    {
        iterator()
        {}
        iterator(_Nodeptr _Pnode, const EraseTree* _Plist) : const_iterator(_Pnode, _Plist)
        {}
    };
    iterator _Make_iter(const_iterator _Where) const
    {
        return iterator(iterator(_Where._Ptr, this));
    }

    void _Lrotate(_Nodeptr _Wherenode)
    {  // promote right node to root of subtree
        _Nodeptr _Pnode = _Right(_Wherenode);
        _Nodeptr _Parentnode = _Parent(_Wherenode);
        _Right(_Wherenode) = _Left(_Pnode);

        if (!_Isnil(_Left(_Pnode)))
            _Parent(_Left(_Pnode)) = _Wherenode;
        _Parent(_Pnode) = _Parentnode;

        if (_Wherenode == _Root())
            _Root() = _Pnode;
        else if (_Wherenode == _Left(_Parent(_Wherenode)))
            _Left(_Parent(_Wherenode)) = _Pnode;
        else
            _Right(_Parent(_Wherenode)) = _Pnode;

        _Left(_Pnode) = _Wherenode;
        _Parent(_Wherenode) = _Pnode;
    }

    void _Rrotate(_Nodeptr _Wherenode)
    {  // promote left node to root of subtree
        _Nodeptr _Pnode = _Left(_Wherenode);
        _Left(_Wherenode) = _Right(_Pnode);

        if (!_Isnil(_Right(_Pnode)))
            _Parent(_Right(_Pnode)) = _Wherenode;
        _Parent(_Pnode) = _Parent(_Wherenode);

        if (_Wherenode == _Root())
            _Root() = _Pnode;
        else if (_Wherenode == _Right(_Parent(_Wherenode)))
            _Right(_Parent(_Wherenode)) = _Pnode;
        else
            _Left(_Parent(_Wherenode)) = _Pnode;

        _Right(_Pnode) = _Wherenode;
        _Parent(_Wherenode) = _Pnode;
    }

    iterator FUN_00b3bd80(const_iterator _Where);
};
// @fnv 0x00b3bd80
template <class Value> typename EraseTree<Value>::iterator EraseTree<Value>::FUN_00b3bd80(const_iterator _Where)

{  // erase element at _Where

    if (_Isnil(_Where._Mynode()))
        throw std::out_of_range("invalid map/set<T> iterator");
    _Nodeptr _Erasednode = _Where._Mynode();  // node to erase
    _Where.Increment();                       // save successor iterator for return

    _Nodeptr _Fixnode;        // the node to recolor as needed
    _Nodeptr _Fixnodeparent;  // parent of _Fixnode (which may be nil)
    _Nodeptr _Pnode = _Erasednode;

    if (_Isnil(_Left(_Pnode)))
        _Fixnode = _Right(_Pnode);  // must stitch up right subtree
    else if (_Isnil(_Right(_Pnode)))
        _Fixnode = _Left(_Pnode);  // must stitch up left subtree
    else
    {                               // two subtrees, must lift successor node to replace erased
        _Pnode = _Where._Mynode();  // _Pnode is successor node
        _Fixnode = _Right(_Pnode);  // _Fixnode is its only subtree
    }

    if (_Pnode == _Erasednode)
    {  // at most one subtree, relink it
        _Fixnodeparent = _Parent(_Erasednode);
        if (!_Isnil(_Fixnode))
            _Parent(_Fixnode) = _Fixnodeparent;  // link up

        if (_Root() == _Erasednode)
            _Root() = _Fixnode;  // link down from root
        else if (_Left(_Fixnodeparent) == _Erasednode)
            _Left(_Fixnodeparent) = _Fixnode;  // link down to left
        else
            _Right(_Fixnodeparent) = _Fixnode;  // link down to right

        if (_Lmost() == _Erasednode)
            _Lmost() = _Isnil(_Fixnode) ? _Fixnodeparent   // smallest is parent of erased node
                                        : _Min(_Fixnode);  // smallest in relinked subtree

        if (_Rmost() == _Erasednode)
            _Rmost() = _Isnil(_Fixnode) ? _Fixnodeparent   // largest is parent of erased node
                                        : _Max(_Fixnode);  // largest in relinked subtree
    }
    else
    {                                          // erased has two subtrees, _Pnode is successor to erased
        _Parent(_Left(_Erasednode)) = _Pnode;  // link left up
        _Left(_Pnode) = _Left(_Erasednode);    // link successor down

        if (_Pnode == _Right(_Erasednode))
            _Fixnodeparent = _Pnode;  // successor is next to erased
        else
        {                                      // successor further down, link in place of erased
            _Fixnodeparent = _Parent(_Pnode);  // parent is successor's
            if (!_Isnil(_Fixnode))
                _Parent(_Fixnode) = _Fixnodeparent;  // link fix up
            _Left(_Fixnodeparent) = _Fixnode;        // link fix down
            _Right(_Pnode) = _Right(_Erasednode);    // link successor down
            _Parent(_Right(_Erasednode)) = _Pnode;   // link right up
        }

        if (_Root() == _Erasednode)
            _Root() = _Pnode;  // link down from root
        else if (_Left(_Parent(_Erasednode)) == _Erasednode)
            _Left(_Parent(_Erasednode)) = _Pnode;  // link down to left
        else
            _Right(_Parent(_Erasednode)) = _Pnode;  // link down to right

        _Parent(_Pnode) = _Parent(_Erasednode);          // link successor up
        SwapValue(_Color(_Pnode), _Color(_Erasednode));  // recolor it
    }

    if (_Color(_Erasednode) == _Black)
    {  // erasing black link, must recolor/rebalance tree
        for (; _Fixnode != _Root() && _Color(_Fixnode) == _Black; _Fixnodeparent = _Parent(_Fixnode))
            if (_Fixnode == _Left(_Fixnodeparent))
            {  // fixup left subtree
                _Pnode = _Right(_Fixnodeparent);
                if (_Color(_Pnode) == _Red)
                {  // rotate red up from right subtree
                    _Color(_Pnode) = _Black;
                    _Color(_Fixnodeparent) = _Red;
                    _Lrotate(_Fixnodeparent);
                    _Pnode = _Right(_Fixnodeparent);
                }

                if (_Isnil(_Pnode))
                    _Fixnode = _Fixnodeparent;  // shouldn't happen
                else if (_Color(_Left(_Pnode)) == _Black && _Color(_Right(_Pnode)) == _Black)
                {  // redden right subtree with black children
                    _Color(_Pnode) = _Red;
                    _Fixnode = _Fixnodeparent;
                }
                else
                {  // must rearrange right subtree
                    if (_Color(_Right(_Pnode)) == _Black)
                    {  // rotate red up from left sub-subtree
                        _Color(_Left(_Pnode)) = _Black;
                        _Color(_Pnode) = _Red;
                        _Rrotate(_Pnode);
                        _Pnode = _Right(_Fixnodeparent);
                    }

                    _Color(_Pnode) = _Color(_Fixnodeparent);
                    _Color(_Fixnodeparent) = _Black;
                    _Color(_Right(_Pnode)) = _Black;
                    _Lrotate(_Fixnodeparent);
                    break;  // tree now recolored/rebalanced
                }
            }
            else
            {  // fixup right subtree
                _Pnode = _Left(_Fixnodeparent);
                if (_Color(_Pnode) == _Red)
                {  // rotate red up from left subtree
                    _Color(_Pnode) = _Black;
                    _Color(_Fixnodeparent) = _Red;
                    _Rrotate(_Fixnodeparent);
                    _Pnode = _Left(_Fixnodeparent);
                }
                if (_Isnil(_Pnode))
                    _Fixnode = _Fixnodeparent;  // shouldn't happen
                else if (_Color(_Right(_Pnode)) == _Black && _Color(_Left(_Pnode)) == _Black)
                {  // redden left subtree with black children
                    _Color(_Pnode) = _Red;
                    _Fixnode = _Fixnodeparent;
                }
                else
                {  // must rearrange left subtree
                    if (_Color(_Left(_Pnode)) == _Black)
                    {  // rotate red up from right sub-subtree
                        _Color(_Right(_Pnode)) = _Black;
                        _Color(_Pnode) = _Red;
                        _Lrotate(_Pnode);
                        _Pnode = _Left(_Fixnodeparent);
                    }

                    _Color(_Pnode) = _Color(_Fixnodeparent);
                    _Color(_Fixnodeparent) = _Black;
                    _Color(_Left(_Pnode)) = _Black;
                    _Rrotate(_Fixnodeparent);
                    break;  // tree now recolored/rebalanced
                }
            }

        _Color(_Fixnode) = _Black;  // ensure stopping node is black
    }

    this->_Alnod.destroy(_Erasednode);  // destroy, free erased node
    this->_Alnod.deallocate(_Erasednode, 1);

    if (0 < _Mysize)
        --_Mysize;

    return (_Make_iter(_Where));  // return successor iterator
}

template EraseTree<int>::iterator EraseTree<int>::FUN_00b3bd80(EraseTree<int>::const_iterator);

unsigned int __cdecl FUN_00ec7c56(void);

static const float kStep = 1.0f / 499.0f;

struct SplineVec
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00b3c500* m_kRayStart;
    FUN_00b3c500* m_kRayEnd;
    FUN_00b3c500* m_eos;
};

struct GlobalObject_00b3f100
{
    GlobalObject_00b3f100();
    ~GlobalObject_00b3f100();
    float FUN_00b3f130(float, float);
};

inline float LerpF(float a, float b, float t)
{
    return a + (b - a) * t;
}

struct FUN_00b37ad0_class
{
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    float m_noise;
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
    SplineVec m_vec;

    float FUN_00b37ad0(float a2);
};

// @fnv 0x00b37ad0
float FUN_00b37ad0_class::FUN_00b37ad0(float a2)
{
    float pItem;
    pItem = 0.0f;
    {
        int idx;
        float fraction;
        SplineVec* curve;
        curve = &m_vec;
        if (curve->m_kRayEnd - curve->m_kRayStart == 500)
        {
            idx = (int)(a2 * 499.0);
            if (idx == 499)
            {
                SplineVec* samples;
                samples = &m_vec;
                if ((unsigned int)idx >= (unsigned int)(samples->m_kRayEnd - samples->m_kRayStart))
                    FUN_00ec7c56();
                FUN_00b3c500* next;
                next = &samples->m_kRayStart[idx];
                pItem = next->f04;
            }
            else
            {
                fraction = (a2 - (float)idx * kStep) / kStep;
                unsigned long pCurr = 1 + idx;
                SplineVec* index = &m_vec;
                if ((unsigned int)pCurr >= (unsigned int)(index->m_kRayEnd - index->m_kRayStart))
                    FUN_00ec7c56();
                FUN_00b3c500* nextIndex = &index->m_kRayStart[pCurr];
                SplineVec* pVec4;
                pVec4 = &m_vec;
                if ((unsigned int)idx >= (unsigned int)(pVec4->m_kRayEnd - pVec4->m_kRayStart))
                    FUN_00ec7c56();
                FUN_00b3c500* v0 = &pVec4->m_kRayStart[idx];
                pItem = LerpF(v0->f04, nextIndex->f04, fraction);
            }
            pItem = (m_kMaximumCorner - m_kMinimumCorner) * pItem + m_kMinimumCorner;
            static GlobalObject_00b3f100 s_noise;
            pItem += s_noise.FUN_00b3f130(-m_noise, m_noise);
        }
    }
    return pItem;
}

namespace fnv_00b397f0 {
void operator delete(void*);

class GlobalObject_00b3f100
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~GlobalObject_00b3f100();
};

class Cont_00b397f0
{
  public:
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_00b3f100* myFirst;
    GlobalObject_00b3f100* myLast;
    GlobalObject_00b3f100* myEnd;
    void FUN_00b397f0();
};

// @fnv 0x00b397f0
void Cont_00b397f0::FUN_00b397f0()
{
    if (this->myFirst != 0)
    {
        GlobalObject_00b3f100* rangeLast5 = this->myLast;
        GlobalObject_00b3f100* rangeFirst4 = this->myFirst;
        GlobalObject_00b3f100* last2 = rangeLast5;
        GlobalObject_00b3f100* first4 = rangeFirst4;
        bool _tagSrc;
        bool tag = _tagSrc;
        GlobalObject_00b3f100* lastIt2 = last2;
        GlobalObject_00b3f100* it3 = first4;
        for (; it3 != lastIt2; it3 = it3 + 1)
        {
            it3->~GlobalObject_00b3f100();
        }
        int kCount = this->myEnd - this->myFirst;
        GlobalObject_00b3f100* delPtr4 = this->myFirst;
        operator delete(delPtr4);
    }
    this->myFirst = 0;
    this->myLast = 0;
    this->myEnd = 0;
}
}  // namespace fnv_00b397f0

namespace fnv_00b3ac00 {
inline void Dead2()
{
    int d0;
    int d1;
}
inline void Dead3()
{
    int d0;
    int d1;
    int d2;
}
unsigned int __cdecl FUN_00ec7c56();
void __stdcall FUN_00ec7894(void* p, void* t);
extern int DAT_010173dc;
extern int DAT_01140cb0;
struct FUN_0044a4c0
{
    int m[7];
    FUN_0044a4c0(const char* s);
    void FUN_0044a730(bool b, unsigned int n);
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
};
struct FUN_0044a310
{
    void* vt;
    int m[9];
    FUN_0044a310(const FUN_0044a4c0& s);
};
struct LenErrQ : FUN_0044a310
{
    LenErrQ(const FUN_0044a4c0& s) : FUN_0044a310(s)
    {
        vt = &DAT_010173dc;
    }
};
inline void ThrowLen(const LenErrQ& _Ex)
{
    FUN_00ec7894((void*)&_Ex, &DAT_01140cb0);
}
struct ValQ
{
    int m[8];
};
struct NodeQ
{
    NodeQ* _Left;
    NodeQ* _Parent;
    NodeQ* _Right;
    ValQ _Myval;
    char _Color;
    char _Isnil;
};
struct TreeQ;
struct IterQ
{
    void* _Myaux;
    NodeQ* _Ptr;
    IterQ(NodeQ* p, const TreeQ* t);
};
struct TreeQ
{
    void* _Myownedaux;
    int m04[5];
    NodeQ* _Myhead;
    unsigned int _Mysize;
    static NodeQ*& _Left(NodeQ* p)
    {
        return p->_Left;
    }
    static NodeQ*& _Right(NodeQ* p)
    {
        return p->_Right;
    }
    static NodeQ*& _Parent(NodeQ* p)
    {
        return p->_Parent;
    }
    static char& _Color(NodeQ* p)
    {
        return p->_Color;
    }
    NodeQ*& _Root() const
    {
        return _Parent(_Myhead);
    }
    NodeQ*& _Lmost() const
    {
        return _Left(_Myhead);
    }
    NodeQ*& _Rmost() const
    {
        return _Right(_Myhead);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = 0x7ffffff;
        Dead3();
        int _Pad;
        return (0 < _Count ? _Count : 1);
    }
    NodeQ* FUN_00ad1960(NodeQ* _Larg, NodeQ* _Parg, NodeQ* _Rarg, const ValQ& _Val, char _Carg);
    void FUN_00ad1800(NodeQ* _Wherenode);
    void FUN_00ad18b0(NodeQ* _Wherenode);
    IterQ FUN_00b3ac00(bool _Addleft, NodeQ* _Wherenode, const ValQ& _Val);
};
inline IterQ::IterQ(NodeQ* p, const TreeQ* t) : _Myaux(0), _Ptr(p)
{
    if (!(t != 0))
        FUN_00ec7c56();
    _Myaux = t->_Myownedaux;
}
// @fnv 0x00b3ac00
IterQ TreeQ::FUN_00b3ac00(bool _Addleft, NodeQ* _Wherenode, const ValQ& _Val)
{
    if (max_size() - 1 <= _Mysize)
    {
        ThrowLen(LenErrQ("map/set<T> too long"));
    }
    NodeQ* _Newnode = FUN_00ad1960(_Myhead, _Wherenode, _Myhead, _Val, 0);
    ++_Mysize;
    if (_Wherenode == _Myhead)
    {
        _Root() = _Newnode;
        _Lmost() = _Newnode;
        _Rmost() = _Newnode;
    }
    else if (_Addleft)
    {
        _Left(_Wherenode) = _Newnode;
        if (_Wherenode == _Lmost())
            _Lmost() = _Newnode;
    }
    else
    {
        _Right(_Wherenode) = _Newnode;
        if (_Wherenode == _Rmost())
            _Rmost() = _Newnode;
    }
    for (NodeQ* _Pnode = _Newnode; _Color(_Parent(_Pnode)) == 0;)
        if (_Parent(_Pnode) == _Left(_Parent(_Parent(_Pnode))))
        {
            _Wherenode = _Right(_Parent(_Parent(_Pnode)));
            if (_Color(_Wherenode) == 0)
            {
                _Color(_Parent(_Pnode)) = 1;
                _Color(_Wherenode) = 1;
                _Color(_Parent(_Parent(_Pnode))) = 0;
                _Pnode = _Parent(_Parent(_Pnode));
            }
            else
            {
                if (_Pnode == _Right(_Parent(_Pnode)))
                {
                    _Pnode = _Parent(_Pnode);
                    FUN_00ad1800(_Pnode);
                }
                _Color(_Parent(_Pnode)) = 1;
                Dead3();
                _Color(_Parent(_Parent(_Pnode))) = 0;
                FUN_00ad18b0(_Parent(_Parent(_Pnode)));
            }
        }
        else
        {
            Dead2();
            _Wherenode = _Left(_Parent(_Parent(_Pnode)));
            if (_Color(_Wherenode) == 0)
            {
                _Color(_Parent(_Pnode)) = 1;
                _Color(_Wherenode) = 1;
                _Color(_Parent(_Parent(_Pnode))) = 0;
                _Pnode = _Parent(_Parent(_Pnode));
            }
            else
            {
                if (_Pnode == _Left(_Parent(_Pnode)))
                {
                    _Pnode = _Parent(_Pnode);
                    FUN_00ad18b0(_Pnode);
                }
                _Color(_Parent(_Pnode)) = 1;
                Dead2();
                _Color(_Parent(_Parent(_Pnode))) = 0;
                FUN_00ad1800(_Parent(_Parent(_Pnode)));
            }
        }
    Dead3();
    _Color(_Root()) = 1;
    return (IterQ(_Newnode, this));
}
}  // namespace fnv_00b3ac00

namespace fnv_00b3b100 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
struct ValB100
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
template <class _Ty> struct _Tree_nodeS
{
    _Tree_nodeS* _Left;
    _Tree_nodeS* _Parent;
    _Tree_nodeS* _Right;
    _Ty _Myval;
    char _Color;
    char _Isnil;
};
struct lessS
{
};
template <class _Ty> class _TreeS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    typedef _Tree_nodeS<_Ty>* _Nodeptr;
    static _Nodeptr& _Left(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Left);
    }
    static _Nodeptr& _Parent(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Parent);
    }
    static _Nodeptr& _Right(_Nodeptr _Pnode)
    {
        return ((_Nodeptr&)(*_Pnode)._Right);
    }
    static char& _Isnil(_Nodeptr _Pnode)
    {
        return ((char&)(*_Pnode)._Isnil);
    }
    static _Nodeptr _Max(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Right(_Pnode)))
            _Pnode = _Right(_Pnode);
        return (_Pnode);
    }
    static _Nodeptr _Min(_Nodeptr _Pnode)
    {
        while (!_Isnil(_Left(_Pnode)))
            _Pnode = _Left(_Pnode);
        return (_Pnode);
    }
    lessS comp;
    allocatorS<_Tree_nodeS<_Ty> > _Alnod;
    allocatorS<_Nodeptr> _Alptr;
    allocatorS<_Ty> _Alval;
    _Nodeptr _Myhead;
    unsigned int _Mysize;
};
template <class _Ty> class _BiditS : public _Iterator_base_auxS
{
};
template <class _Ty> class _Tree_const_iteratorS : public _BiditS<_Ty>
{
  public:
    typedef _TreeS<_Ty> _Myt;
    typedef typename _Myt::_Nodeptr _Nodeptr;
    _Nodeptr _Ptr;
};
class FUN_00b3b100_Iterator : public _Tree_const_iteratorS<ValB100>
{
  public:
    void FUN_00b3b100();
};

// @fnv 0x00b3b100
void FUN_00b3b100_Iterator::FUN_00b3b100()
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoS();
    if (_Myt::_Isnil(_Ptr))
    {
        InvalidParameterNoInfoS();
    }
    else if (!_Myt::_Isnil(_Myt::_Right(_Ptr)))
        _Ptr = _Myt::_Min(_Myt::_Right(_Ptr));
    else
    {
        _Nodeptr _Pnode;
        while (!_Myt::_Isnil(_Pnode = _Myt::_Parent(_Ptr)) && _Ptr == _Myt::_Right(_Pnode))
            _Ptr = _Pnode;
        _Ptr = _Pnode;
    }
}
}  // namespace fnv_00b3b100

namespace fnv_00b3b330 {
extern const unsigned int DAT_010173f0;
extern void __cdecl operator delete(void*) throw();
void __cdecl CopyChars(char*, unsigned int, const char*, unsigned int);
void __cdecl MoveChars(char*, unsigned int, const char*, unsigned int);
void __cdecl RangeError();
void __cdecl LengthError();
namespace std {
struct CharTraits
{
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
struct CharAllocator
{
    void deallocate(char* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    unsigned int max_size() const
    {
        return (unsigned int)(-1);
    }
};
struct string
{
    CharAllocator _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    ~string();
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        CharTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    void FUN_0044a730(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                CopyChars(_Bx._Buf, 16, _Ptr, _Newsize);
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 15;
        _Eos(_Newsize);
    }
    unsigned int size() const
    {
        return _Mysize;
    }
    string& erase(unsigned int _Off, unsigned int _Count = DAT_010173f0)
    {
        if (_Mysize < _Off)
            RangeError();
        if (_Mysize - _Off < _Count)
            _Count = _Mysize - _Off;
        if (0 < _Count)
        {
            MoveChars(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count, _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    void _Copy(unsigned int, unsigned int);
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
            LengthError();
        if (_Myres < _Newsize)
            _Copy(_Newsize, _Mysize);
        else if (_Trim && _Newsize < 16)
            FUN_0044a730(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        else if (_Newsize == 0)
            _Eos(0);
        return 0 < _Newsize;
    }
    string& AssignSubstring(const string& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
            RangeError();
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
            _Num = _Count;
        if (this == &_Right)
            erase(_Roff + _Num), erase(0, _Roff);
        else if (_Grow(_Num))
        {
            CopyChars(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    string(const string& _Right)
    {
        FUN_0044a730();
        AssignSubstring(_Right, 0, DAT_010173f0);
    }
};
template <class T1, class T2> struct pair
{
    T1 first;
    T2 second;
    pair(const pair& _Right) : first(_Right.first), second(_Right.second)
    {}
};
}

struct TreeNode
{
    TreeNode* _Left;
    TreeNode* _Parent;
    TreeNode* _Right;
    std::pair<const std::string, int> _Myval;
    char _Color;
    char _Isnil;

    TreeNode(TreeNode* _Larg, TreeNode* _Parg, TreeNode* _Rarg, const std::pair<const std::string, int>& _Val,
             char _Carg)
        : _Left(_Larg), _Parent(_Parg), _Right(_Rarg), _Myval(_Val), _Color(_Carg), _Isnil(0)
    {}
};

inline void* __cdecl operator new(size_t, void* _Where) throw()
{
    return _Where;
}
inline void __cdecl operator delete(void*, void*) throw()
{}
extern void __cdecl operator delete(void*) throw();
extern void* __cdecl operator new(size_t);
namespace std {
class exception
{
    const char* _What;
    int _DoFree;

  public:
    exception(const char* const&);
    virtual ~exception();
};
class bad_alloc : public exception
{
  public:
    bad_alloc(const char* _Message = 0) : exception(_Message)
    {}
};
}
inline TreeNode* __cdecl AllocateNode(unsigned int _Count, const void*)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned int)(-1) / _Count < sizeof(TreeNode))
        throw std::bad_alloc(0);
    return (TreeNode*)operator new(_Count * sizeof(TreeNode));
}

struct TreeClass
{
    TreeNode* FUN_00b3b330(TreeNode* _Larg, TreeNode* _Parg, TreeNode* _Rarg,
                           const std::pair<const std::string, int>& _Val, char _Carg);
};

// @fnv 0x00b3b330
TreeNode* TreeClass::FUN_00b3b330(TreeNode* _Larg, TreeNode* _Parg, TreeNode* _Rarg,
                                  const std::pair<const std::string, int>& _Val, char _Carg)
{
    TreeNode* _Warg = AllocateNode(1, 0);
    try
    {
        new (_Warg) TreeNode(_Larg, _Parg, _Rarg, _Val, _Carg);
    }
    catch (...)
    {
        operator delete(_Warg);
        throw;
    }
    return _Warg;
}
}  // namespace fnv_00b3b330

namespace fnv_00b38430 {
struct SplinePoint
{
    float x, y, z, w, weight;
    int dimensions;
    SplinePoint();
    SplinePoint(float, float, float, float, float);
    ~SplinePoint();
    __forceinline float& operator[](unsigned int component)
    {
        return (&x)[component];
    }
};
void __cdecl operator delete(void*);
__forceinline void DeallocQ(void* p)
{
    operator delete(p);
}
struct SplineVecBase
{
    void* proxy;
    __forceinline ~SplineVecBase()
    {
        void* pq = proxy;
        DeallocQ(pq);
    }
};
struct SplinePointVector : SplineVecBase
{
    int allocatorState;
    int iteratorState;
    SplinePoint* first;
    SplinePoint* last;
    SplinePoint* capacity;
    SplinePointVector();
    __forceinline ~SplinePointVector()
    {
        FUN_00b397f0();
    }
    void FUN_00b397f0();
    void FUN_00b39490(unsigned int, SplinePoint);
    __forceinline void resizeA(unsigned int n)
    {
        int ha0;
        int ha1;
        FUN_00b39490(n, SplinePoint());
    }
    __forceinline void resizeB(unsigned int n)
    {
        int hb0;
        int hb1;
        int hb2;
        int hb3;
        int hb4;
        int hb5;
        int hb6;
        int hb7;
        int hb8;
        int hb9;
        int hb10;
        int hb11;
        FUN_00b39490(n, SplinePoint());
    }
    void FUN_00b1e750();
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline SplinePoint& operator[](unsigned int index) throw()
    {
        if (!(index < size()))
            FUN_00ec7c56();
        return first[index];
    }
};
__forceinline float Interpolate(float start, float end, float fraction)
{
    return start + (end - start) * fraction;
}
struct SampledVector : SplinePointVector
{
    __forceinline SplinePoint& operator[](unsigned int index) throw()
    {
        if (!(index < size()))
            FUN_00ec7c56();
        return first[index];
    }
};
struct SplinePath
{
    float minimum, maximum, scale;
    SplinePointVector controlPoints;
    SplinePointVector tangents;
    SplinePointVector scratch;
    SplinePointVector samples;
    SplinePoint FUN_00b38b50(float);
    void FUN_00b38430(unsigned int count);
};
__forceinline void padQ()
{
    int pq0;
    int pq1;
    int pq2;
    int pq3;
    int pq4;
    int pq5;
    int pq6;
    int pq7;
    int pq8;
}
// @fnv 0x00b38430
void SplinePath::FUN_00b38430(unsigned int count)
{
    SplinePointVector sampled;
    sampled.resizeA(count);
    for (unsigned int i = 0; i < count; ++i)
        sampled[i] = FUN_00b38b50(float(i) / count);
    samples.FUN_00b1e750();
    samples.resizeB(count);
    unsigned int segment = 0;
    samples[0] = controlPoints[0];
    for (unsigned int j = 1; j < count - 1; ++j)
    {
        float position = float(j) / count;
        for (unsigned int k = segment; k < count - 1; ++k)
        {
            if (position >= sampled[k][0] && position < sampled[k + 1][0])
            {
                segment = k;
                break;
            }
        }
        SplinePoint point(position, 0.0f, 0.0f, 0.0f, 0.0f);
        position = (position - sampled[segment][0]) / (sampled[segment + 1][0] - sampled[segment][0]);
        point[1] = Interpolate(sampled[segment][1], sampled[segment + 1][1], position);
        samples[j] = point;
    }
    samples[count - 1] = controlPoints[controlPoints.size() - 1];
    padQ();
}
}  // namespace fnv_00b38430

inline NodeB*& TreeLeftmost(FUN_00b3b810_shell* tree)
{
    return tree->f18->f0;
}
inline void FUN_00b3b810_shell::InitNode()
{
    f18 = FUN_00b3b880();
    reinterpret_cast<NodeT*>(f18)->isnil = true;
    f18->f4 = f18;
    TreeLeftmost(this) = f18, f18->f8 = f18;
    f1c = 0;
}
template <class T> struct TreeAllocatorBase
{
};
template <class T> class TreeAllocator : public TreeAllocatorBase<T>
{
  public:
    TreeAllocator() throw()
    {}
    TreeAllocator(const TreeAllocator&) throw()
    {}
    template <class U> TreeAllocator(const TreeAllocator<U>&) throw()
    {}
};

struct FUN_00b3b9f0 : _Tmap_traitsS<ValT>
{
    FUN_00b3b9f0(lessS compare, TreeAllocator<ValT> allocator);
    ~FUN_00b3b9f0();
};

struct TreeNodeStorage : FUN_00b3b9f0
{
    TreeAllocator<_Tree_nodeS<ValT> > nodeAllocator;
    TreeNodeStorage(const lessS& compare, TreeAllocator<ValT> allocator)
        : FUN_00b3b9f0(compare, allocator), nodeAllocator(allocator)
    {}
};

struct TreePointerStorage : TreeNodeStorage
{
    TreeAllocator<_Tree_nodeS<ValT>*> pointerAllocator;
    TreePointerStorage(const lessS& compare, TreeAllocator<ValT> allocator)
        : TreeNodeStorage(compare, allocator), pointerAllocator(allocator)
    {}
};

struct TreeValueStorage : TreePointerStorage
{
    TreeAllocator<ValT> valueAllocator;
    TreeValueStorage(const lessS& compare, TreeAllocator<ValT> allocator)
        : TreePointerStorage(compare, allocator), valueAllocator(allocator)
    {}
};

struct FUN_00b3b770 : TreeValueStorage
{
    _Tree_nodeS<ValT>* head;
    unsigned int count;
    FUN_00b3b770(const lessS& compare, const TreeAllocator<ValT>& allocator);
};

// @fnv 0x00b3b770
FUN_00b3b770::FUN_00b3b770(const lessS& compare, const TreeAllocator<ValT>& allocator)
    : TreeValueStorage(compare, allocator)
{
    reinterpret_cast<FUN_00b3b810_shell*>(this)->InitNode();
}

namespace fnv_00b3b9f0 {
struct AuxContQ
{
    const void* _Mycontainer;
    AuxContQ(const void* c) : _Mycontainer(c)
    {}
    ~AuxContQ()
    {}
};
template <class T> struct AllocQ
{
    AllocQ() throw()
    {}
    AllocQ(const AllocQ<T>&) throw()
    {}
    template <class U> AllocQ(const U&) throw()
    {}
    T* allocate(unsigned int n)
    {
        return asgnb36::BxAllocate(n, (T*)0);
    }
    void deallocate(T*, unsigned int)
    {}
};
struct AuxBaseQ
{
    AuxBaseQ()
    {}
    ~AuxBaseQ()
    {}
    AuxContQ* _Myownedaux;
};
template <class A> class AuxAllocRealQ : public AuxBaseQ
{
  protected:
    explicit AuxAllocRealQ(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) AuxContQ(this);
    }
    ~AuxAllocRealQ()
    {
        _Myownedaux->~AuxContQ();
        _Alaux.deallocate(_Myownedaux, 1);
    }
    AllocQ<AuxContQ> _Alaux;
};
struct FUN_00b3b9f0 : public AuxAllocRealQ<asgnb36::BxAllocT<std::pair<const int, int> > >
{
    lessS comp;
    FUN_00b3b9f0(lessS _Parg, asgnb36::BxAllocT<std::pair<const int, int> > _Al);
};
// @fnv 0x00b3b9f0
FUN_00b3b9f0::FUN_00b3b9f0(lessS _Parg, asgnb36::BxAllocT<std::pair<const int, int> > _Al)
    : AuxAllocRealQ<asgnb36::BxAllocT<std::pair<const int, int> > >(_Al), comp(_Parg)
{}
}  // namespace fnv_00b3b9f0

struct CleanupCursor : TreeConstIterB3B
{
    void FUN_00b3b100();
    TreeConstIterB3B operator++(int)
    {
        TreeConstIterB3B old = *this;
        FUN_00b3b100();
        return old;
    }
};

struct TreeCleanup : TreeB3B
{
    TreeIterB3B FUN_00b3bb90(TreeConstIterB3B first, TreeConstIterB3B last);
    void FUN_00b3ba90();
};

inline TreeIterB3B TreeCleanup::FUN_00b3bb90(TreeConstIterB3B first, TreeConstIterB3B last)
{
    TreeConstIterB3B& cursor = first;
    if (cursor == begin() && last == end())
    {
        ResetList();
        return begin();
    }
    else
    {
        while (cursor != last)
            EraseOne(((CleanupCursor&)cursor)++);
        return MakeIter(first);
    }
}

// @fnv 0x00b3ba90
void TreeCleanup::FUN_00b3ba90()
{
    FUN_00b3bb90(begin(), end());
    ((allocatorS<NodeT*>*)&unk10)->destroy(&Left(head));
    ((allocatorS<NodeT*>*)&unk10)->destroy(&Parent(head));
    ((allocatorS<NodeT*>*)&unk10)->destroy(&Right(head));
    ((Alloc<NodeT>*)&unk0C)->deallocate(head, 1);
    head = 0, count = 0;
}
