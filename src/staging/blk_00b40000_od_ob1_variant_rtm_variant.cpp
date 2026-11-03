// src/staging/blk_00b40000_od_ob1_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00b40000_od_ob1_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00b40000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00b40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00b40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct CIdvCamera
{
    CIdvCamera& FUN_00b3f0c0(CIdvCamera const&);
    CIdvCamera& FUN_00b402d0(CIdvCamera const& src);
};
struct FUN_00ec7c56_t
{
    static void FUN_00ec7c56();
};
struct FUN_00b42980
{
    int a;
    int b;
    FUN_00b42980& Set(unsigned int v, FUN_00b42980 const& src);
};
void* operator new(unsigned int);
struct FUN_00b40150 : CIdvCamera
{
    unsigned char data[76];
    FUN_00b40150();
};
FUN_00b40150::FUN_00b40150()
{}
struct FUN_00b403a0_t : CIdvCamera
{
    CIdvCamera& CloneCamera();
};
void FUN_00ec7c56();
struct FUN_00b40800_t
{
    int pos;
    int pad;
    char GetNextChar();
};
struct FUN_00b40070_Point
{
    float x;
    float y;
    float z;
};
extern int DAT_010a58fc;
struct FUN_00b40070_Class
{
    void* unk00;
    NiPoint3 unk04;
    unsigned char unk10;
    int unk14;
    unsigned char unk18;
    FUN_00b40070_Point unk1C;
    FUN_00b40070_Point unk28;
    FUN_00b40070_Point unk34;
    unsigned char unk40;
    float unk44;
    int unk48;

    void FUN_00b3f030();
    FUN_00b40070_Class* __thiscall FUN_00b40070(NiPoint3* position, unsigned char value18, unsigned char value10,
                                                float value, int result);
};
extern float DAT_01016248;
struct S_00b40850_P3
{
    float x;
    float y;
    float z;
};
struct FUN_00b40850
{
    float unk00;
    float unk04;
    float unk08;
    S_00b40850_P3 unk0C;
    float unk18;
    FUN_00b40850();
};
extern float DAT_0107d9a0;
extern float DAT_01016410;
extern float DAT_0101b268;
class FUN_00b40a60_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_1c;
    float m_20;
    unsigned int m_24;
    float m_28;
    float m_2c;
    unsigned int m_30;

    void InitBase(int a, int b);
    FUN_00b40a60_cls* FUN_00b40a60();
};
struct FUN_00b40a60_loc
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
};
struct FUN_00b40ad0_Frame
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
};
struct FUN_00b40ad0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_18;
    float m_1c;
    int m_20;
    float m_24;
    void FUN_00b416d0();
    FUN_00b40ad0_cls* Init(int a, float b, float c, float d);
};
// Stand-in for the class that owns ReserveEntries.
// Offsets are taken from the original code:
//   +0x0c  buffer pointer, +0x10 buffer start, +0x14 buffer end.
struct FnvCamera
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    bool ReserveEntries(unsigned int count);
};
// The original reserves 0x90 bytes of frame for one local aggregate;
// only its last dword is touched by this function.
struct FnvScratch
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
};
// The allocator the original calls with (count, 0); it hands out count * 8 bytes.
void* FUN_00b42df0(unsigned int count, void* allocator);
// The out-of-range reporter the original calls when the count is too large.
void FUN_00b0fb80();
struct FUN_00b42be0_cls
{
    unsigned int* m_00;
    unsigned int m_04;
    unsigned int m_08;

    FUN_00b42be0_cls* FUN_00b42be0(FUN_00b42be0_cls* src);
};
class FUN_00b420a0_cls
{
  public:
    FUN_00b42980 m_obj;
    int CompareAndGetDelta(FUN_00b42980 const& arg);
};
void* operator new(unsigned int);
extern char DAT_010176f8[];
extern char DAT_01140ef8[];
struct FnvThrowObj
{
    void* vptr;
    const char* what;
    bool dofree;

    void FUN_00ec78f1(int* value);
};
void* __cdecl FUN_00b42df0(unsigned int count, void* allocator);
struct Elem8StandIn
{
    unsigned int unk00;
    unsigned int unk04;
};
struct Vec8StandIn
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Elem8StandIn* m_pHeadNode;
    Elem8StandIn* m_last;
};
struct AuxCont8StandIn
{
    const Vec8StandIn* m_cont;
    const Vec8StandIn* Getcont() const
    {
        return m_cont;
    }
};
struct VecIter8StandIn
{
    AuxCont8StandIn* m_aux;
    Elem8StandIn* m_ptr;
    bool Has_container() const
    {
        return m_aux != 0;
    }
    const Vec8StandIn* Getmycont() const
    {
        return m_aux ? m_aux->Getcont() : 0;
    }
    VecIter8StandIn& FUN_00b42ce0(int off);
};
struct E8
{
    int a;
    int b;
};
struct Tag1
{
};
struct Tag2
{
};
extern "C" void FUN_00b42f40(E8* p, unsigned n, const E8& v, void* al, Tag1 c, Tag2 r);
inline Tag1 Ptr_cat(E8*&, E8*&)
{
    Tag1 c;
    return c;
}
inline void ufn(E8* f, unsigned n, const E8& v, char (&al)[4])
{
    FUN_00b42f40(f, n, v, &al, Ptr_cat(f, f), Tag2());
}
struct CIt8
{
    void* cont;
    E8* ptr;
};
struct It8 : CIt8
{
    It8(E8* p, struct V8* v);
};
struct V8
{
    void* proxy;
    int pad;
    char alval[4];
    E8* first;
    E8* last;
    E8* end_;
    unsigned size() const
    {
        return last - first;
    }
    unsigned capacity() const
    {
        return first == 0 ? 0 : end_ - first;
    }
    E8* _Ufill(E8* p, unsigned n, const E8& v)
    {
        ufn(p, n, v, alval);
        return p + n;
    }
    It8 end()
    {
        return It8(last, this);
    }
    CIt8 FUN_00b41b50(CIt8 w, const E8& v);
    void FUN_00b417b0(const E8& v);
};
inline void Pad()
{
    int u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11;
}
inline It8::It8(E8* p, V8* v)
{
    cont = 0;
    if (v == 0 || v->first > p || p > v->last)
        FUN_00ec7c56_t::FUN_00ec7c56();
    cont = v->proxy;
    ptr = p;
}
struct Sub_b40000
{
    ~Sub_b40000();
};
struct FUN_00b40000_class
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
    Sub_b40000* m_pSub;
    void FUN_00b40000(Sub_b40000* apSub);
};
// VC9 (Dinkumware, _SECURE_SCL=1) vector / vector<bool> subset, transcribed
// into namespace stl so the checker can compile it without <vector>.
extern "C" void __cdecl _invalid_parameter_noinfo(void);
inline void* operator new(unsigned int, void* _Where) throw()
{
    return _Where;
}
void __cdecl operator delete(void*) throw();
namespace stl {

struct _Length_error
{
    _Length_error(const char*);
};

template <class _Ty> inline _Ty* _Allocate(unsigned int _Count, _Ty*)
{
    if (_Count <= 0)
        _Count = 0;
    else if (((unsigned int)(-1) / _Count) < sizeof(_Ty))
        throw _Length_error("bad allocation");
    return ((_Ty*)::operator new(_Count * sizeof(_Ty)));
}

template <class _Ty> class allocator
{
  public:
    typedef _Ty value_type;
    typedef _Ty* pointer;
    typedef _Ty& reference;
    typedef const _Ty* const_pointer;
    typedef const _Ty& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class _Other> struct rebind
    {
        typedef allocator<_Other> other;
    };
    allocator() throw()
    {}
    allocator(const allocator<_Ty>&) throw()
    {}
    template <class _Other> allocator(const allocator<_Other>&) throw()
    {}
    void deallocate(pointer _Ptr, size_type)
    {
        ::operator delete(_Ptr);
    }
    pointer allocate(size_type _Count)
    {
        return (_Allocate(_Count, (pointer)0));
    }
    size_type max_size() const throw()
    {
        size_type _Count = (size_type)(-1) / sizeof(_Ty);
        return (0 < _Count ? _Count : 1);
    }
};

template <class _Ty> inline void _Destroy_range(_Ty*, _Ty*, allocator<_Ty>&)
{}

template <class _Ty> inline void _Uninit_fill_n(_Ty* _First, unsigned int _Count, const _Ty& _Val, allocator<_Ty>&)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}

class _Container_base_aux;

class _Aux_cont
{
  public:
    explicit _Aux_cont(const _Container_base_aux* const _Pcont) : _Mycontainer(_Pcont)
    {}
    const _Container_base_aux* _Getcont() const
    {
        return _Mycontainer;
    }

  private:
    const _Container_base_aux* _Mycontainer;
};

class _Container_base_aux
{
  public:
    _Container_base_aux()
    {}
    _Container_base_aux(const _Container_base_aux&)
    {}
    _Container_base_aux& operator=(const _Container_base_aux&)
    {
        return *this;
    }
    ~_Container_base_aux()
    {}

  protected:
    friend class _Iterator_base_aux;
    _Aux_cont* _Myownedaux;
};

template <class _Alloc> class _Container_base_aux_alloc_real : public _Container_base_aux
{
  protected:
    explicit _Container_base_aux_alloc_real(_Alloc _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) _Aux_cont(this);
    }
    _Container_base_aux_alloc_real(const _Container_base_aux_alloc_real& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) _Aux_cont(this);
    }
    _Container_base_aux_alloc_real& operator=(const _Container_base_aux_alloc_real&)
    {
        return *this;
    }
    ~_Container_base_aux_alloc_real()
    {
        _Myownedaux->~_Aux_cont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
    typename _Alloc::template rebind<_Aux_cont>::other _Alaux;
};

class _Iterator_base_aux
{
  public:
    _Iterator_base_aux() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_aux* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_aux* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_aux& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }

  private:
    const _Aux_cont* _Myaux;
};

typedef _Container_base_aux _Container_base;
typedef _Iterator_base_aux _Iterator_base;

struct _Unchanged_checked_iterator_base_type_tag
{
};

template <class _Iter> inline _Iter __cdecl _Checked_base(_Iter& _It, _Unchanged_checked_iterator_base_type_tag)
{
    return _It;
}

template <class _Iter> inline _Iter __cdecl _Checked_base(_Iter& _It)
{
    _Unchanged_checked_iterator_base_type_tag _Base_tag;
    return _Checked_base(_It, _Base_tag);
}

template <class _FwdIt, class _Ty> inline void __cdecl _Fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}

template <class _FwdIt, class _Ty> inline void __cdecl fill(_FwdIt _First, _FwdIt _Last, const _Ty& _Val)
{
    _Fill(_Checked_base(_First), _Checked_base(_Last), _Val);
}

template <class _Ty, class _Ax> class vector;

template <class _Ty, class _Alloc> class _Vector_const_iterator : public _Iterator_base
{
  public:
    typedef _Vector_const_iterator<_Ty, _Alloc> _Myt;
    typedef vector<_Ty, _Alloc> _Myvec;
    typedef typename _Alloc::pointer _Tptr;
    typedef typename _Alloc::difference_type difference_type;
    typedef typename _Alloc::const_reference reference;

    _Vector_const_iterator()
    {
        _Myptr = 0;
    }
    _Vector_const_iterator(_Tptr _Ptr, const _Container_base* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
        {
            _invalid_parameter_noinfo();
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    reference operator*() const
    {
        if (!(this->_Has_container()))
        {
            _invalid_parameter_noinfo();
        }
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
        {
            _invalid_parameter_noinfo();
        }
        return (*_Myptr);
    }
    _Myt& operator++()
    {
        if (!(this->_Has_container()))
        {
            _invalid_parameter_noinfo();
        }
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
        {
            _invalid_parameter_noinfo();
        }
        ++_Myptr;
        return (*this);
    }
    _Myt& operator+=(difference_type _Off)
    {
        if (!(this->_Has_container()))
        {
            _invalid_parameter_noinfo();
        }
        if (!(_Myptr + _Off <= ((_Myvec*)(this->_Getmycont()))->_Mylast &&
              _Myptr + _Off >= ((_Myvec*)(this->_Getmycont()))->_Myfirst))
        {
            _invalid_parameter_noinfo();
        }
        _Myptr += _Off;
        return (*this);
    }
    _Myt operator+(difference_type _Off) const
    {
        _Myt _Tmp = *this;
        return (_Tmp += _Off);
    }
    difference_type operator-(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
        {
            _invalid_parameter_noinfo();
        }
        return (_Myptr - _Right._Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
        {
            _invalid_parameter_noinfo();
        }
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }

    _Tptr _Myptr;
};

template <class _Ty, class _Alloc> class _Vector_iterator : public _Vector_const_iterator<_Ty, _Alloc>
{
  public:
    typedef _Vector_iterator<_Ty, _Alloc> _Myt;
    typedef _Vector_const_iterator<_Ty, _Alloc> _Mybase;
    typedef typename _Alloc::difference_type difference_type;
    typedef typename _Alloc::pointer pointer;
    typedef typename _Alloc::reference reference;

    _Vector_iterator()
    {}
    _Vector_iterator(pointer _Ptr, const _Container_base* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
    reference operator*() const
    {
        return ((reference) * *(_Mybase*)this);
    }
    _Myt& operator++()
    {
        ++(*(_Mybase*)this);
        return (*this);
    }
    _Myt& operator+=(difference_type _Off)
    {
        (*(_Mybase*)this) += _Off;
        return (*this);
    }
    _Myt operator+(difference_type _Off) const
    {
        _Myt _Tmp = *this;
        return (_Tmp += _Off);
    }
    difference_type operator-(const _Mybase& _Right) const
    {
        return (*(_Mybase*)this - _Right);
    }
};

template <class _Ty, class _Alloc> class _Vector_val : public _Container_base_aux_alloc_real<_Alloc>
{
  protected:
    _Vector_val(_Alloc _Al = _Alloc()) : _Container_base_aux_alloc_real<_Alloc>(_Al), _Alval(_Al)
    {}
    typedef typename _Alloc::template rebind<_Ty>::other _Alty;
    _Alty _Alval;
};

template <class _Ty, class _Ax = allocator<_Ty> > class vector : public _Vector_val<_Ty, _Ax>
{
  public:
    typedef vector<_Ty, _Ax> _Myt;
    typedef _Vector_val<_Ty, _Ax> _Mybase;
    typedef typename _Mybase::_Alty _Alloc;
    typedef typename _Alloc::size_type size_type;
    typedef typename _Alloc::pointer pointer;
    typedef _Vector_iterator<_Ty, _Alloc> iterator;
    typedef _Vector_const_iterator<_Ty, _Alloc> const_iterator;
    friend class _Vector_const_iterator<_Ty, _Alloc>;

    vector() : _Mybase()
    {
        _Buy(0);
    }
    vector(size_type _Count, const _Ty& _Val) : _Mybase()
    {
        _Construct_n(_Count, _Val);
    }
    void _Construct_n(size_type _Count, const _Ty& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~vector()
    {
        _Tidy();
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    const_iterator begin() const
    {
        return (const_iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    size_type max_size() const
    {
        return (this->_Alval.max_size());
    }
    size_type capacity() const
    {
        return (_Myfirst == 0 ? 0 : _Myend - _Myfirst);
    }
    void push_back(const _Ty& _Val)
    {
        if (size() < capacity())
            _Mylast = _Ufill(_Mylast, 1, _Val);
        else
            insert(end(), _Val);
    }
    iterator insert(const_iterator _Where, const _Ty& _Val)
    {
        size_type _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, (size_type)1, _Val);
        return (begin() + _Off);
    }
    void _Insert_n(const_iterator _Where, size_type _Count, const _Ty& _Val);
    _Ty& operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
        {
            _invalid_parameter_noinfo();
        }
        return (*(_Myfirst + _Pos));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First(_First_arg._Myptr, this);
        iterator _Last(_Last_arg._Myptr, this);
        if (_First != _Last)
        {
            pointer _Ptr = _First._Myptr;
            for (pointer _Src = _Last._Myptr; _Src != _Mylast; ++_Src, ++_Ptr)
                *_Ptr = *_Src;
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }

  protected:
    bool _Buy(size_type _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return (false);
        else if (max_size() < _Capacity)
            _Xlen();
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return (true);
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_range(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    pointer _Ufill(pointer _Ptr, size_type _Count, const _Ty& _Val)
    {
        _Uninit_fill_n(_Ptr, _Count, _Val, this->_Alval);
        return (_Ptr + _Count);
    }
    static void _Xlen()
    {
        throw _Length_error("vector<T> too long");
    }

  public:
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};

typedef unsigned _Vbase;
const int _VBITS = 8 * sizeof(_Vbase);

template <class _Sizet, class _Difft, class _MycontTy> class _Vb_iter_base : public _Iterator_base
{
  public:
    _Vb_iter_base() : _Myptr(0), _Myoff(0)
    {}
    _Vb_iter_base(_Vbase* _Ptr, _Sizet _Off, const _Container_base* _Mypvbool) : _Myptr(_Ptr), _Myoff(_Off)
    {
        if (!(_Mypvbool != 0))
        {
            _invalid_parameter_noinfo();
        }
        this->_Set_container(_Mypvbool);
    }
    _Vbase* _Myptr;
    _Sizet _Myoff;

    _Vbase* _My_cont_begin() const
    {
        return ((((_MycontTy*)this->_Getmycont())->_Myvec.begin())._Myptr);
    }
    _Sizet _My_actual_offset() const
    {
        _Sizet _Off = this->_Myoff;
        _Off += _VBITS * (this->_Myptr - _My_cont_begin());
        return (_Off);
    }
};

template <class _Sizet, class _Difft, class _MycontTy>
class _Vb_reference : public _Vb_iter_base<_Sizet, _Difft, _MycontTy>
{
  public:
    typedef _Vb_iter_base<_Sizet, _Difft, _MycontTy> _Mybase;
    typedef _Vb_reference<_Sizet, _Difft, _MycontTy> _Mytype;

    _Vb_reference(const _Mybase& _Right) : _Mybase(_Right._Myptr, _Right._Myoff, _Right._Getmycont())
    {}
    _Mytype& operator=(bool _Val)
    {
        int hq0;
        int hq1;
        if (_Val)
            *_Getptr() |= _Mask();
        else
            *_Getptr() &= ~_Mask();
        return (*this);
    }
    operator bool() const
    {
        return ((*_Getptr() & _Mask()) != 0);
    }
    _Vbase* _Getptr() const
    {
        if (!(this->_Has_container() && this->_Myptr != 0))
        {
            _invalid_parameter_noinfo();
        }
        if (!(this->_My_actual_offset() < ((_MycontTy*)this->_Getmycont())->_Mysize))
        {
            _invalid_parameter_noinfo();
        }
        return (this->_Myptr);
    }

  protected:
    _Vbase _Mask() const
    {
        return ((_Vbase)(1 << this->_Myoff));
    }
};

template <class _Sizet, class _Difft, class _MycontTy>
class _Vb_const_iterator : public _Vb_iter_base<_Sizet, _Difft, _MycontTy>
{
  public:
    typedef _Vb_iter_base<_Sizet, _Difft, _MycontTy> _Mybase;
    typedef _Vb_const_iterator<_Sizet, _Difft, _MycontTy> _Mytype;
    typedef _Vb_reference<_Sizet, _Difft, _MycontTy> _Reft;
    typedef _Sizet size_type;
    typedef _Difft difference_type;

    _Vb_const_iterator()
    {}
    _Vb_const_iterator(const _Vbase* _Ptr, const _Container_base* _Mypvbool)
        : _Mybase((_Vbase*)_Ptr, 0, (_Container_base*)_Mypvbool)
    {}
    _Mytype& operator++()
    {
        _Inc();
        return (*this);
    }
    _Mytype& operator+=(difference_type _Off)
    {
        if (_Off == 0)
            return (*this);
        if (!(this->_Has_container() && this->_Myptr != 0))
        {
            _invalid_parameter_noinfo();
        }
        if (_Off < 0)
        {
            if (!(this->_My_actual_offset() >= ((size_type)-_Off)))
            {
                _invalid_parameter_noinfo();
            }
        }
        else
        {
            if (!((this->_My_actual_offset() + _Off) <= ((_MycontTy*)this->_Getmycont())->_Mysize))
            {
                _invalid_parameter_noinfo();
            }
        }
        if (_Off < 0 && this->_Myoff < 0 - (size_type)_Off)
        {
            this->_Myoff += _Off;
            this->_Myptr -= 1 + ((size_type)(-1) - this->_Myoff) / _VBITS;
            this->_Myoff %= _VBITS;
        }
        else
        {
            this->_Myoff += _Off;
            this->_Myptr += this->_Myoff / _VBITS;
            this->_Myoff %= _VBITS;
        }
        return (*this);
    }
    bool operator==(const _Mytype& _Right) const
    {
        return (this->_Myptr == _Right._Myptr && this->_Myoff == _Right._Myoff);
    }
    bool operator!=(const _Mytype& _Right) const
    {
        return (!(*this == _Right));
    }

  protected:
    void _Inc()
    {
        if (!(this->_Has_container() && this->_Myptr != 0))
        {
            _invalid_parameter_noinfo();
        }
        if (!((this->_My_actual_offset() + 1) <= ((_MycontTy*)this->_Getmycont())->_Mysize))
        {
            _invalid_parameter_noinfo();
        }
        if (this->_Myoff < _VBITS - 1)
            ++this->_Myoff;
        else
            this->_Myoff = 0, ++this->_Myptr;
    }
};

template <class _Sizet, class _Difft, class _MycontTy>
class _Vb_iterator : public _Vb_const_iterator<_Sizet, _Difft, _MycontTy>
{
  public:
    typedef _Vb_const_iterator<_Sizet, _Difft, _MycontTy> _Mybase;
    typedef _Vb_iterator<_Sizet, _Difft, _MycontTy> _Mytype;
    typedef _Vb_reference<_Sizet, _Difft, _MycontTy> _Reft;
    typedef _Difft difference_type;
    typedef _Reft reference;

    _Vb_iterator()
    {}
    _Vb_iterator(_Vbase* _Ptr, _Container_base* _Mypvbool) : _Mybase(_Ptr, _Mypvbool)
    {}
    reference operator*() const
    {
        return (_Reft(*this));
    }
    _Mytype& operator++()
    {
        ++*(_Mybase*)this;
        return (*this);
    }
    _Mytype& operator+=(difference_type _Off)
    {
        *(_Mybase*)this += _Off;
        return (*this);
    }
    _Mytype operator+(difference_type _Off) const
    {
        _Mytype _Tmp = *this;
        return (_Tmp += _Off);
    }
};

template <class _Alloc> class vector<bool, _Alloc> : public _Container_base_aux_alloc_real<_Alloc>
{
  public:
    typedef typename _Alloc::size_type size_type;
    typedef typename _Alloc::difference_type difference_type;
    typedef vector<_Vbase, typename _Alloc::template rebind<_Vbase>::other> _Vbtype;
    typedef vector<bool, _Alloc> _Myt;
    typedef _Vb_reference<size_type, difference_type, _Myt> reference;
    typedef _Vb_iterator<size_type, difference_type, _Myt> iterator;

    explicit vector(size_type _Count, bool _Val = false)
        : _Container_base_aux_alloc_real<_Alloc>(_Alloc()), _Mysize(0), _Myvec(_Nw(_Count), (_Vbase)(_Val ? -1 : 0))
    {
        _Trim(_Count);
    }
    ~vector()
    {
        _Mysize = 0;
    }
    iterator begin()
    {
        return (iterator((_Myvec.begin())._Myptr, this));
    }
    iterator end()
    {
        iterator _Tmp = begin();
        if (0 < _Mysize)
            _Tmp += _Mysize;
        return (_Tmp);
    }
    size_type size() const
    {
        return (_Mysize);
    }
    reference operator[](size_type _Off)
    {
        return (*(begin() + _Off));
    }
    void _Trim(size_type _Size)
    {
        if (max_size() < _Size)
            _Xlen();
        size_type _Words = _Nw(_Size);
        if (_Words < _Myvec.size())
            _Myvec.erase(_Myvec.begin() + _Words, _Myvec.end());
        _Mysize = _Size;
        _Size %= _VBITS;
        if (0 < _Size)
            _Myvec[_Words - 1] &= (_Vbase)((1 << _Size) - 1);
    }
    size_type max_size() const
    {
        const size_type _Maxsize = _Myvec.max_size();
        return (_Maxsize < (size_type)(-1) / _VBITS ? _Maxsize * _VBITS : (size_type)(-1));
    }
    static size_type _Nw(size_type _Count)
    {
        return ((_Count + _VBITS - 1) / _VBITS);
    }
    static void _Xlen()
    {
        throw _Length_error("vector<bool> too long");
    }

    size_type _Mysize;
    _Vbtype _Myvec;
};

}
struct MatchPoint
{
    float x;
    float y;
    float z;
    float FUN_00b04d40(const MatchPoint& other) const;
};
struct MatchNode
{
    int unk00;
    MatchPoint position;
    const MatchPoint& GetPosition() const
    {
        return position;
    }
};
struct MatchPair
{
    MatchNode* first;
    MatchNode* second;
    MatchPair()
    {}
    MatchPair(MatchNode* a, MatchNode* b) : first(a), second(b)
    {}
};
__forceinline void hole4()
{
    int hq;
}
__forceinline void hole8()
{
    int hq;
    int hq2;
}
struct Matcher
{
    stl::vector<MatchPair> m_pairs;
    float limit;
    void FUN_00b41110(stl::vector<MatchNode*> nodes);
};
void __cdecl operator delete(void*) throw();
struct VbAux
{
    const void* container;
    explicit VbAux(const void* p) : container(p)
    {}
};
struct VbBase
{
    VbAux* owned;
    VbBase()
    {}
    VbBase(const VbBase&)
    {}
    VbBase& operator=(const VbBase&)
    {
        return *this;
    }
    ~VbBase()
    {}
};
template <class T> struct VbAlloc
{
    typedef T* pointer;
    typedef unsigned int size_type;
    template <class U> struct rebind
    {
        typedef VbAlloc<U> other;
    };
    VbAlloc() throw()
    {}
    VbAlloc(const VbAlloc&) throw()
    {}
    template <class U> VbAlloc(const VbAlloc<U>&) throw()
    {}
    void deallocate(pointer p, size_type)
    {
        ::operator delete(p);
    }
};
template <class Al> struct VbBaseAlloc : VbBase
{
    typename Al::template rebind<VbAux>::other alaux;
    explicit VbBaseAlloc(Al a) : alaux(a)
    {}
    ~VbBaseAlloc()
    {
        owned->~VbAux();
        alaux.deallocate(owned, 1);
    }
};
template <class T, class Al> struct VbVal : VbBaseAlloc<Al>
{
    typename Al::template rebind<T>::other alval;
    VbVal(Al a = Al()) : VbBaseAlloc<Al>(a), alval(a)
    {}
};
struct ScalarTag
{
};
template <class T> inline ScalarTag PtrCat(T*&, T*&)
{
    ScalarTag cat;
    return cat;
}
template <class Al> inline void DestroyRange(typename Al::pointer, typename Al::pointer, Al&, ScalarTag)
{}
template <class Al> inline void DestroyRange(typename Al::pointer first, typename Al::pointer last, Al& al)
{
    DestroyRange(first, last, al, PtrCat(first, last));
}
struct VbWords : VbVal<unsigned int, VbAlloc<unsigned int> >
{
    unsigned int* first;
    unsigned int* last;
    unsigned int* end;
    void Destroy(unsigned int* a, unsigned int* b)
    {
        DestroyRange(a, b, this->alval);
    }
    void FUN_00b17f50()
    {
        if (first != 0)
        {
            Destroy(first, last);
            this->alval.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
    ~VbWords()
    {
        FUN_00b17f50();
    }
};
struct FUN_00b419c0 : VbBaseAlloc<VbAlloc<bool> >
{
    unsigned int size;
    VbWords vec;
    ~FUN_00b419c0();
};
struct ElQ_aceeb0
{
    int a[2];
};
struct AlQ_aceeb0
{
};
struct CatQ_aceeb0
{
};
struct TagQ_aceeb0
{
};
inline CatQ_aceeb0 PtrCat_aceeb0(ElQ_aceeb0*&, ElQ_aceeb0*&)
{
    CatQ_aceeb0 c;
    return c;
}
void __cdecl FUN_00ac20d0(ElQ_aceeb0* _First, unsigned int _Count, const ElQ_aceeb0& _Val, AlQ_aceeb0& _Al, CatQ_aceeb0,
                          TagQ_aceeb0);
inline void UFillN_aceeb0(ElQ_aceeb0* _First, unsigned int _Count, const ElQ_aceeb0& _Val, AlQ_aceeb0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_aceeb0(_First, _First), TagQ_aceeb0());
}
struct VecQ_aceeb0;
inline void Dead2_q()
{
    int a[2];
}
struct CItQ_aceeb0
{
    void* _Myaux;
    ElQ_aceeb0* _Myptr;
    CItQ_aceeb0()
    {}
    CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_aceeb0& r) const
    {
        return _Myaux == r._Myaux;
    }
    CItQ_aceeb0& FUN_00b42ce0(int _Off);
    int operator-(const CItQ_aceeb0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct ItQ_aceeb0 : CItQ_aceeb0
{
    ItQ_aceeb0()
    {}
    ItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : CItQ_aceeb0(_Ptr, _Pvector)
    {}
    ItQ_aceeb0& operator+=(int _Off)
    {
        FUN_00b42ce0(_Off);
        return *this;
    }
    ItQ_aceeb0 operator+(int _Off) const
    {
        ItQ_aceeb0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};
struct VecQ_aceeb0
{
    void* _Myownedaux;
    int m04;
    AlQ_aceeb0 _Alval;
    char p09[3];
    ElQ_aceeb0* _Myfirst;
    ElQ_aceeb0* _Mylast;
    ElQ_aceeb0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_aceeb0 begin()
    {
        return ItQ_aceeb0(_Myfirst, this);
    }
    void FUN_00b42180(CItQ_aceeb0 _Where, unsigned int _Count, const ElQ_aceeb0& _Val);
    ItQ_aceeb0 end()
    {
        return ItQ_aceeb0(_Mylast, this);
    }
    ElQ_aceeb0* _Ufill(ElQ_aceeb0* _Ptr, unsigned int _Count, const ElQ_aceeb0& _Val)
    {
        UFillN_aceeb0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_aceeb0 FUN_00b41b50(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val);
};
inline CItQ_aceeb0::CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
void __cdecl InvalidParameterNoInfoX41D40();
struct ContainerBaseAuxX41D40
{
};
class AuxContX41D40
{
  public:
    const ContainerBaseAuxX41D40* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX41D40* _Mycontainer;
};
class IteratorBaseAuxX41D40
{
  public:
    const ContainerBaseAuxX41D40* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX41D40* _Myaux;
};
struct ElemX41D40
{
    int unk00;
    int unk04;
};
struct VectorX41D40 : public ContainerBaseAuxX41D40
{
    AuxContX41D40* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX41D40* _Myfirst;
    ElemX41D40* _Mylast;
    ElemX41D40* _Myend;
};
class FUN_00b41d40_It : public IteratorBaseAuxX41D40
{
  public:
    FUN_00b41d40_It& FUN_00b41d40();
    ElemX41D40* _Myptr;
};
struct E
{
    int x;
};
struct Alloc
{
    Alloc() throw()
    {}
    Alloc(const Alloc&) throw()
    {}
};
struct Base
{
    void* unk00;
    Base(Alloc al = Alloc());
    ~Base();
};
inline Base::Base(Alloc)
{
    unsigned a0, a1, a2, a3, a4, a5, a6, a7;
    if (unk00 == 0)
        Base extra;
    a0 = a1 = a2 = a3 = a4 = a5 = a6 = a7 = 0;
}
struct FUN_00b42030 : Base
{
    void FUN_00b32600(unsigned int count, const E& val);
    FUN_00b42030(unsigned int count, const E& val);
};
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
template <class _MycontTy> class _Vb_iter_baseS : public _RanitS<bool>
{
  public:
    unsigned int* _My_cont_begin() const
    {
        return (((_MycontTy*)this->_Getmycont())->_Myvec.begin()._Myptr);
    }
    unsigned int _My_actual_offset() const
    {
        unsigned int _Off = this->_Myoff;
        _Off += 32 * (this->_Myptr - _My_cont_begin());
        return (_Off);
    }
    unsigned int* _Myptr;
    unsigned int _Myoff;
};
class vector_boolS : public _Container_base_aux_alloc_realS<allocatorS<unsigned int> >
{
  public:
    unsigned int _Mysize;
    vectorS<unsigned int> _Myvec;
};
class FUN_00b420f0_Reference : public _Vb_iter_baseS<vector_boolS>
{
  public:
    unsigned int* FUN_00b420f0() const;
};
struct MessageString
{
    int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned length;
    unsigned capacity;
    MessageString(const char*);
    ~MessageString();
};
struct ExceptionBase
{
    virtual ~ExceptionBase();
    const char* message;
    bool dofree;
};
struct VectorLengthError : ExceptionBase
{
    MessageString text;
    VectorLengthError(const MessageString& _Message) : text(_Message)
    {}
};
inline void FUN_00b0fb80()
{
    throw VectorLengthError(MessageString("vector<T> too long"));
}
struct AllocationError : ExceptionBase
{
    AllocationError(const char*);
};
inline void* FUN_00b42df0(unsigned _Count, void*)
{
    if (_Count <= 0)
        _Count = 0;
    else if ((unsigned(-1) / _Count) < sizeof(FUN_00b42980))
        throw AllocationError(0);
    return ::operator new(_Count * sizeof(FUN_00b42980));
}
struct RangeTag
{
};
struct ValueTag
{
};
struct MoveTag
{
};
struct BaseTag
{
};
template <class I> inline I checked_base2(I& _It, BaseTag)
{
    return _It;
}
template <class I> inline I checked_base(I& _It)
{
    BaseTag _Base_tag;
    return checked_base2(_It, _Base_tag);
}
// VC-style vector insertion, with scalar record destruction and exception rollback.
void __cdecl FormHeap_Free(void*);
FUN_00b42980* __cdecl FUN_00b431e0(const FUN_00b42980*, const FUN_00b42980*, FUN_00b42980*, void*);
void __cdecl FUN_00b42f40(FUN_00b42980*, unsigned, const FUN_00b42980*, void*, ValueTag, RangeTag);
FUN_00b42980* __cdecl FUN_00b43010(const FUN_00b42980*, const FUN_00b42980*, FUN_00b42980*, void*);
template <class T, class U> inline ValueTag value_tag(const T&, const U&)
{
    ValueTag _Ans;
    return _Ans;
}
template <class T> inline MoveTag move_tag(const T&)
{
    MoveTag _Cat;
    return _Cat;
}
template <class I, class D, class A> inline D uninit_move(I _First, I _Last, D _Dest, A& _Al, MoveTag, RangeTag)
{
    return FUN_00b431e0(_First, _Last, _Dest, &_Al);
}
template <class I, class A> inline I unchecked_move(I _First, I _Last, I _Dest, A& _Al)
{
    return uninit_move(checked_base(_First), checked_base(_Last), _Dest, _Al, move_tag(_Dest), RangeTag());
}
template <class I, class A> inline void unchecked_fill(I _First, unsigned _Count, const FUN_00b42980& _Val, A& _Al)
{
    FUN_00b42f40(_First, _Count, &_Val, &_Al, value_tag(_First, _First), RangeTag());
}
struct RecordAllocator
{
    int state;
    inline void destroy(FUN_00b42980* _Ptr)
    {
        _Ptr->~FUN_00b42980();
    }
    inline void deallocate(FUN_00b42980* _Ptr, unsigned)
    {
        FormHeap_Free(_Ptr);
    }
};
template <class A> inline void destroy_range(FUN_00b42980* _First, FUN_00b42980* _Last, A& _Al, ValueTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void destroy_range(FUN_00b42980* _First, FUN_00b42980* _Last, A& _Al)
{
    destroy_range(_First, _Last, _Al, value_tag(_First, _Last));
}
template <class I> inline void fill_range(I _First, I _Last, const FUN_00b42980& _Val)
{
    for (; _First != _Last; ++_First)
        *_First = _Val;
}
template <class I> inline void fill_outer(I _First, I _Last, const FUN_00b42980& _Val)
{
    fill_range(checked_base(_First), checked_base(_Last), _Val);
}
FUN_00b42980* __cdecl FUN_00b43230(const FUN_00b42980*, const FUN_00b42980*, FUN_00b42980*, void*, ValueTag, RangeTag);
__declspec(noinline) inline FUN_00b42980* __cdecl FUN_00b431e0(const FUN_00b42980* _First, const FUN_00b42980* _Last,
                                                               FUN_00b42980* _Dest, void* _Al)
{
    return FUN_00b43230(checked_base(_First), checked_base(_Last), _Dest, _Al, value_tag(_First, _Dest), RangeTag());
}
template <class I, class D, class A> inline D copy_tail(I _First, I _Last, D _Dest, A& _Al)
{
    return FUN_00b43230(checked_base(_First), checked_base(_Last), _Dest, &_Al, value_tag(_First, _Dest), RangeTag());
}
template <class I, class D, class A> inline D uninit_tail(I _First, I _Last, D _Dest, A& _Al, MoveTag, RangeTag)
{
    return copy_tail(_First, _Last, _Dest, _Al);
}
inline FUN_00b42980* FUN_00b43010(const FUN_00b42980* _First, const FUN_00b42980* _Last, FUN_00b42980* _Dest, void* _Al)
{
    return uninit_tail(checked_base(_First), checked_base(_Last), _Dest, *static_cast<RecordAllocator*>(_Al),
                       move_tag(_Dest), RangeTag());
}
struct ForwardTag
{
};
struct RandomTag : ForwardTag
{
};
template <class I, class O> inline RandomTag random_tag(const I&, const O&)
{
    RandomTag _Cat;
    return _Cat;
}
template <class I> inline I copy_backward_loop(I _First, I _Last, I _Dest, ForwardTag, ValueTag, RangeTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
template <class I> inline I copy_backward_random(I _First, I _Last, I _Dest, RandomTag, ValueTag, RangeTag)
{
    FUN_00b42980* _Result = _Dest - (_Last - _First);
    copy_backward_loop(_First, _Last, checked_base(_Dest), ForwardTag(), ValueTag(), RangeTag());
    return _Result;
}
template <class I> inline I MoveBackwardOpt(I _First, I _Last, I _Dest, RandomTag _First_dest_cat, MoveTag, RangeTag)
{
    I _Firstbase = _First;
    I _Destbase = _Dest;
    int _Off = _Last - _Firstbase;
    I _Result = _Destbase - _Off;
    copy_backward_loop(_Firstbase, _Last, checked_base(_Destbase), ForwardTag(), value_tag(_Firstbase, _Destbase),
                       RangeTag());
    return _Result;
}
template <class I> inline I __cdecl FUN_00b42da0(I _First, I _Last, I _Dest)
{
    return MoveBackwardOpt(checked_base(_First), checked_base(_Last), _Dest, random_tag(_First, _Dest), move_tag(_Dest),
                           RangeTag());
}
struct RecordVector
{
    int unk00;
    int unk04;
    RecordAllocator allocator;
    FUN_00b42980* _Myfirst;
    FUN_00b42980* _Mylast;
    FUN_00b42980* _Myend;
    inline unsigned capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    inline unsigned size() const
    {
        return _Mylast - _Myfirst;
    }
    inline unsigned max_size() const
    {
        unsigned _Count = 0x1fffffff;
        return 0 < _Count ? _Count : 1;
    }
    template <class _Iter> inline FUN_00b42980* move(_Iter _First, _Iter _Last, FUN_00b42980* _Dest)
    {
        return unchecked_move(_First, _Last, _Dest, allocator);
    }
    inline FUN_00b42980* fill_uninitialized(FUN_00b42980* _Ptr, unsigned _Count, const FUN_00b42980& _Val)
    {
        unchecked_fill(_Ptr, _Count, _Val, allocator);
        return _Ptr + _Count;
    }
    inline FUN_00b42980* move_tail(FUN_00b42980* _First, FUN_00b42980* _Last, FUN_00b42980* _Ptr)
    {
        return FUN_00b43010(_First, _Last, _Ptr, &allocator);
    }
    inline void destroy(FUN_00b42980* _First, FUN_00b42980* _Last)
    {
        destroy_range(_First, _Last, allocator);
    }
    inline void fill(FUN_00b42980* _First, FUN_00b42980* _Last, const FUN_00b42980& _Val)
    {
        fill_outer(_First, _Last, _Val);
    }
    void FUN_00b42180(void* iteratorState, FUN_00b42980* _Where, unsigned _Count, const FUN_00b42980& _Val);
};
extern char str_010a5950[];
extern int DAT_010173dc;
namespace std {
template <class T> struct char_traits
{
};
template <class T> class allocator
{
};
template <class E, class Tr = char_traits<E>, class A = allocator<E> > class basic_string
{
  public:
    unsigned raw0, raw1, raw2, raw3, raw4, raw5, raw6;
    basic_string(const char* p);
    ~basic_string()
    {
        _Tidy(true, 0);
    }
    basic_string(const basic_string& r);

  protected:
    void _Tidy(bool built, unsigned int n);
};
class exception
{
  public:
    void* vptr;
    int a;
    int b;
};
class logic_error : public exception
{
  public:
    explicit logic_error(const basic_string<char>& m) : _Str(m)
    {
        unsigned k0 = 0;
        unsigned k1 = 1;
        unsigned k2 = 2;
        unsigned k3 = 3;
        unsigned k4 = 4;
        unsigned k5 = 5;
        unsigned k6 = 6;
        unsigned k7 = 7;
        unsigned k8 = 8;
        unsigned k9 = 9;
        unsigned k10 = 10;
        unsigned k11 = 11;
        unsigned k12 = 12;
        unsigned k13 = 13;
        unsigned k14 = 14;
        unsigned k15 = 15;
        unsigned k16 = 16;
        unsigned k17 = 17;
        unsigned k18 = 18;
        unsigned k19 = 19;
        unsigned k20 = 20;
        unsigned k21 = 21;
        unsigned k22 = 22;
        unsigned k23 = 23;
        unsigned k24 = 24;
        unsigned k25 = 25;
        unsigned k26 = 26;
        unsigned k27 = 27;
        unsigned k28 = 28;
        k0 = k1 + 0;
        k1 = k2 + 1;
        k2 = k3 + 2;
        k3 = k4 + 3;
        k4 = k5 + 4;
        k5 = k6 + 5;
        k6 = k7 + 6;
        k7 = k8 + 7;
        k8 = k9 + 8;
        k9 = k10 + 9;
        k10 = k11 + 10;
        k11 = k12 + 11;
        k12 = k13 + 12;
        k13 = k14 + 13;
        k14 = k15 + 14;
        k15 = k16 + 15;
        k16 = k17 + 16;
        k17 = k18 + 17;
        k18 = k19 + 18;
        k19 = k20 + 19;
        k20 = k21 + 20;
        k21 = k22 + 21;
        k22 = k23 + 22;
        k23 = k24 + 23;
        k24 = k25 + 24;
        k25 = k26 + 25;
        k26 = k27 + 26;
        k27 = k28 + 27;
        (void)k0;
    }
    ~logic_error()
    {}

  private:
    basic_string<char> _Str;
};
class length_error : public logic_error
{
  public:
    explicit length_error(const basic_string<char>& m) : logic_error(m)
    {
        vptr = &DAT_010173dc;
    }
    ~length_error()
    {}
};
}
struct VbXlen
{
    void FUN_00b429d0() const;
};
void __cdecl FUN_00ec7c56();
struct ContainerBaseAuxB42
{
};
class AuxContB42
{
  public:
    const ContainerBaseAuxB42* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxB42* _Mycontainer;
};
class IteratorBaseAuxB42
{
  public:
    const ContainerBaseAuxB42* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContB42* _Myaux;
};
struct WordVectorB42;
struct WordIteratorB42
{
    WordIteratorB42(unsigned int* _Ptr, const WordVectorB42* _Pvector);
    AuxContB42* _Myaux;
    unsigned int* _Myptr;
};
struct WordVectorB42
{
    AuxContB42* _Myownedaux;
    int _Alaux;
    int _Alval;
    unsigned int* _Myfirst;
    unsigned int* _Mylast;
    unsigned int* _Myend;
    WordIteratorB42 begin()
    {
        return WordIteratorB42(_Myfirst, this);
    }
};
inline WordIteratorB42::WordIteratorB42(unsigned int* _Ptr, const WordVectorB42* _Pvector)
{
    _Myaux = 0;
    if (_Pvector == 0 || _Pvector->_Myfirst > _Ptr || _Ptr > _Pvector->_Mylast)
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
struct BoolVectorB42 : public ContainerBaseAuxB42
{
    AuxContB42* _Myownedaux;
    int _Alaux;
    unsigned int _Mysize;
    WordVectorB42 _Myvec;
};
class BoolIteratorB42 : public IteratorBaseAuxB42
{
  public:
    unsigned int _My_actual_offset() const
    {
        int _Off = this->_Myoff;
        _Off += 32 * (this->_Myptr - _My_cont_begin());
        return (unsigned int)_Off;
    }
    unsigned int* _My_cont_begin() const
    {
        return ((BoolVectorB42*)this->_Getmycont())->_Myvec.begin()._Myptr;
    }
    BoolIteratorB42& FUN_00b42a60(int _Off);
    unsigned int* _Myptr;
    unsigned int _Myoff;
};
void operator delete(void*) throw();
void* operator new(unsigned int);
inline void operator delete(void*, void*) throw()
{}
void* __cdecl FUN_0044d670(unsigned int count, void* hint);
struct VecAux
{
    const void* container;
    explicit VecAux(const void* p) : container(p)
    {}
};
struct VecContainerBase
{
    VecAux* _Myownedaux;
    VecContainerBase()
    {}
    VecContainerBase(const VecContainerBase&)
    {}
    VecContainerBase& operator=(const VecContainerBase&)
    {
        return *this;
    }
    ~VecContainerBase()
    {}
};
template <class T> struct VecAlloc
{
    VecAlloc() throw()
    {}
    VecAlloc(const VecAlloc&) throw()
    {}
    template <class U> VecAlloc(const VecAlloc<U>&) throw()
    {}
    T* allocate(unsigned int count)
    {
        return (T*)FUN_0044d670(count, (T*)0);
    }
    void deallocate(T* ptr, unsigned int)
    {
        ::operator delete(ptr);
    }
};
template <class T> struct VecContainerAlloc : VecContainerBase
{
    VecAlloc<VecAux> _Alaux;
    explicit VecContainerAlloc(VecAlloc<T> al) : _Alaux(al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) VecAux(this);
    }
    ~VecContainerAlloc()
    {
        _Myownedaux->~VecAux();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct Elem
{
    int a;
    int b;
};
template <class T> struct VecValue : VecContainerAlloc<T>
{
    VecAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    VecValue(VecAlloc<T> al = VecAlloc<T>()) : VecContainerAlloc<T>(al), _Alval(al)
    {}
    bool ReserveEntries(unsigned int count);
};
struct FUN_00b416d0 : VecValue<Elem>
{
    FUN_00b416d0();
};
inline bool VecValue<Elem>::ReserveEntries(unsigned int count)
{
    int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23,
        v24, v25, v26, v27, v28, v29, v30;
    v0 = (int)count;
    v1 = v0 + 1;
    v2 = v1 + 2;
    v3 = v2 + 3;
    v4 = v3 + 4;
    v5 = v4 + 5;
    v6 = v5 + 6;
    v7 = v6 + 7;
    v8 = v7 + 8;
    v9 = v8 + 9;
    v10 = v9 + 10;
    v11 = v10 + 11;
    v12 = v11 + 12;
    v13 = v12 + 13;
    v14 = v13 + 14;
    v15 = v14 + 15;
    v16 = v15 + 16;
    v17 = v16 + 17;
    v18 = v17 + 18;
    v19 = v18 + 19;
    v20 = v19 + 20;
    v21 = v20 + 21;
    v22 = v21 + 22;
    v23 = v22 + 23;
    v24 = v23 + 24;
    v25 = v24 + 25;
    v26 = v25 + 26;
    v27 = v26 + 27;
    v28 = v27 + 28;
    v29 = v28 + 29;
    v30 = v29 + 30;
    v0 = v30 + 31;
    v1 = v0 + 32;
    v2 = v1 + 33;
    v3 = v2 + 34;
    v4 = v3 + 35;
    v5 = v4 + 36;
    v6 = v5 + 37;
    v7 = v6 + 38;
    v8 = v7 + 39;
    v9 = v8 + 40;
    _Myfirst = (Elem*)v0;
    return v0 != 0;
}
int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
int __cdecl memmove_s(void*, unsigned int, const void*, unsigned int);
struct VectorException_Z
{
    const char* _m_what;
    int _m_doFree;
    VectorException_Z();
    VectorException_Z(const char* const&);
    VectorException_Z(const VectorException_Z&);
    virtual ~VectorException_Z();
    virtual const char* what() const;
};
struct AllocationFailure_Z : VectorException_Z
{
    AllocationFailure_Z(const char* _Message) throw() : VectorException_Z(_Message)
    {}
    virtual ~AllocationFailure_Z() throw()
    {}
};
template <class T> inline T* AllocateWords_Z(unsigned int _Count, T*)
{
    if (_Count <= 0)
        _Count = 0;
    else if (0xffffffffu / _Count < sizeof(T))
        throw AllocationFailure_Z(0);
    return (T*)::operator new(_Count * sizeof(T));
}
template <class T> struct VecAlloc_Z
{
    VecAlloc_Z() throw()
    {}
    VecAlloc_Z(const VecAlloc_Z&) throw()
    {}
    template <class U> VecAlloc_Z(const VecAlloc_Z<U>&) throw()
    {}
    T* allocate(unsigned int _Count)
    {
        return AllocateWords_Z(_Count, (T*)0);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = 0xffffffffu / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
    void deallocate(T* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
struct VecAux_Z
{
    const void* container;
    explicit VecAux_Z(const void* p) : container(p)
    {}
};
struct VectorStringValue_Z
{
    VecAlloc_Z<char> allocator;
    VectorStringValue_Z(VecAlloc_Z<char> _Al = VecAlloc_Z<char>()) : allocator(_Al)
    {}
};
struct VectorString_Z : VectorStringValue_Z
{
    union Storage
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
    VectorString_Z(const char* _Ptr)
    {
        Tidy(false, 0);
        assign(_Ptr);
    }
    VectorString_Z& assign(const char*);
    VectorString_Z(const VectorString_Z&);
    char* Myptr()
    {
        return 16 <= capacity ? storage.pointer : storage.buffer;
    }
    void Eos(unsigned int _Newsize)
    {
        length = _Newsize;
        Myptr()[_Newsize] = 0;
    }
    void Tidy(bool _Built, unsigned int _Newsize)
    {
        if (!_Built)
            ;
        else if (16 <= capacity)
        {
            char* _Ptr = storage.pointer;
            if (0 < _Newsize)
                memcpy_s(storage.buffer, 16, _Ptr, _Newsize);
            allocator.deallocate(_Ptr, capacity + 1);
        }
        capacity = 15;
        Eos(_Newsize);
    }
    ~VectorString_Z()
    {
        Tidy(true, 0);
    }
    const char* c_str() const;
};
struct VectorLogicError_Z : VectorException_Z
{
    VectorString_Z message;
    VectorLogicError_Z(const VectorString_Z& _Message) : message(_Message)
    {}
    virtual ~VectorLogicError_Z() throw()
    {}
    virtual const char* what() const throw()
    {
        return message.c_str();
    }
};
struct VectorLengthError_Z : VectorLogicError_Z
{
    VectorLengthError_Z(const VectorString_Z& _Message) : VectorLogicError_Z(_Message)
    {}
    virtual ~VectorLengthError_Z() throw()
    {}
};
extern char DAT_010a5950[];
struct BitVectorOps_Z
{
    static unsigned int Nw(unsigned int _Count)
    {
        return (_Count + 31) / 32;
    }
    unsigned int max_size() const;
    void Xlen() const
    {
        throw VectorLengthError_Z(VectorString_Z(DAT_010a5950));
    }
    void Trim(unsigned int _Size);
};
struct VecContainerBase_Z : BitVectorOps_Z
{
    VecAux_Z* _Myownedaux;
    VecContainerBase_Z()
    {}
    VecContainerBase_Z(const VecContainerBase_Z&)
    {}
    VecContainerBase_Z& operator=(const VecContainerBase_Z&)
    {
        return *this;
    }
    ~VecContainerBase_Z()
    {}
};
template <class T> struct VecContainerAlloc_Z : VecContainerBase_Z
{
    VecAlloc_Z<VecAux_Z> _Alaux;
    explicit VecContainerAlloc_Z(VecAlloc_Z<T> _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) VecAux_Z(this);
    }
    ~VecContainerAlloc_Z()
    {
        _Myownedaux->~VecAux_Z();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
template <class T> struct VecValue_Z : VecContainerAlloc_Z<T>
{
    VecAlloc_Z<T> _Alval;
    VecValue_Z(VecAlloc_Z<T> _Al = VecAlloc_Z<T>()) : VecContainerAlloc_Z<T>(_Al), _Alval(_Al)
    {}
};
void VecInvalidRange_Z();
struct ScalarTag_Z
{
};
struct InputTag_Z
{
};
struct ForwardTag_Z : InputTag_Z
{
};
struct BidirectionalTag_Z : ForwardTag_Z
{
};
struct RandomTag_Z : BidirectionalTag_Z
{
};
struct RangeTag_Z
{
};
struct UnchangedTag_Z
{
};
inline unsigned int* CheckedBase_Z(unsigned int*& _It, UnchangedTag_Z)
{
    return _It;
}
inline unsigned int* CheckedBase_Z(unsigned int*& _It)
{
    UnchangedTag_Z _Base_tag;
    return CheckedBase_Z(_It, _Base_tag);
}
inline RandomTag_Z IterRandom_Z(unsigned int* const&, unsigned int* const&)
{
    RandomTag_Z _Cat;
    return _Cat;
}
inline ScalarTag_Z PtrCategory_Z(unsigned int*&, unsigned int*&)
{
    ScalarTag_Z _Cat;
    return _Cat;
}
inline unsigned int* CopyOpt_Z(unsigned int* _First, unsigned int* _Last, unsigned int* _Dest, RandomTag_Z, ScalarTag_Z,
                               RangeTag_Z)
{
    int _Off = _Last - _First;
    unsigned int* _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
inline void DestroyRange_Z(unsigned int*, unsigned int*, VecAlloc_Z<unsigned int>&, ScalarTag_Z)
{}
inline void DestroyRange_Z(unsigned int* _First, unsigned int* _Last, VecAlloc_Z<unsigned int>& _Al)
{
    DestroyRange_Z(_First, _Last, _Al, PtrCategory_Z(_First, _Last));
}
struct VbWordVec_Z : VecValue_Z<unsigned int>
{
    unsigned int* _Myfirst;
    unsigned int* _Mylast;
    unsigned int* _Myend;
    VbWordVec_Z(unsigned int _Count, const unsigned int& _Val) : VecValue_Z<unsigned int>()
    {
        _Construct_n(_Count, _Val);
    }
    void _Construct_n(unsigned int _Count, const unsigned int& _Val)
    {
        if (_Buy(_Count))
        {
            try
            {
                _Mylast = _Ufill(_Myfirst, _Count, _Val);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    void WordXlen() const;
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return false;
        else if (max_size() < _Capacity)
            WordXlen();
        else
        {
            _Myfirst = _Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    unsigned int* _Ufill(unsigned int*, unsigned int, const unsigned int&);
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    struct IteratorBase
    {
        VecAux_Z* aux;
        IteratorBase() : aux(0)
        {}
        bool IsContainerSet() const
        {
            return aux != 0;
        }
        const void* GetContainer() const
        {
            return aux ? aux->container : 0;
        }
    };
    struct ConstIterator : IteratorBase
    {
        unsigned int* ptr;
        ConstIterator(unsigned int*, const VbWordVec_Z*);
        ConstIterator& operator+=(int);
        bool SameContainer(const ConstIterator& _Right) const
        {
            return aux == _Right.aux;
        }
        bool operator==(const ConstIterator& _Right) const
        {
            {
                if (!(IsContainerSet() && SameContainer(_Right)))
                {
                    {
                        VecInvalidRange_Z();
                    }
                }
            }
            return ptr == _Right.ptr;
        }
        bool operator!=(const ConstIterator& _Right) const
        {
            return !(*this == _Right);
        }
    };
    struct Iterator : ConstIterator
    {
        Iterator(unsigned int* p, const VbWordVec_Z* c) : ConstIterator(p, c)
        {}
        Iterator& operator+=(int _Off)
        {
            (*(ConstIterator*)this) += _Off;
            return *this;
        }
        Iterator operator+(int _Off) const
        {
            Iterator _Tmp = *this;
            return _Tmp += _Off;
        }
    };
    Iterator begin()
    {
        return Iterator(_Myfirst, this);
    }
    Iterator end()
    {
        return Iterator(_Mylast, this);
    }
    Iterator MakeIter(ConstIterator _Where)
    {
        return Iterator(_Where.ptr, this);
    }
    Iterator erase(ConstIterator _First_arg, ConstIterator _Last_arg)
    {
        Iterator _First = MakeIter(_First_arg);
        Iterator _Last = MakeIter(_Last_arg);
        if (_First != _Last)
        {
            unsigned int* _Ptr = Copy(_Last.ptr, _Mylast, _First.ptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    static unsigned int* Copy(unsigned int*, unsigned int*, unsigned int*);
    void _Destroy(unsigned int* _First, unsigned int* _Last)
    {
        DestroyRange_Z(_First, _Last, _Alval);
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    unsigned int& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                {
                    VecInvalidRange_Z();
                }
            }
        }
        return *(_Myfirst + _Pos);
    }
    ~VbWordVec_Z()
    {
        _Tidy();
    }
};
inline VbWordVec_Z::ConstIterator::ConstIterator(unsigned int* _Ptr, const VbWordVec_Z* _Pvector)
{
    {
        if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        {
            {
                VecInvalidRange_Z();
            }
        }
    }
    aux = _Pvector->_Myownedaux;
    ptr = _Ptr;
}
inline VbWordVec_Z::ConstIterator& VbWordVec_Z::ConstIterator::operator+=(int _Off)
{
    {
        if (!(IsContainerSet()))
        {
            {
                VecInvalidRange_Z();
            }
        }
    }
    {
        if (!(ptr + _Off <= ((const VbWordVec_Z*)GetContainer())->_Mylast &&
              ptr + _Off >= ((const VbWordVec_Z*)GetContainer())->_Myfirst))
        {
            {
                VecInvalidRange_Z();
            }
        }
    }
    ptr += _Off;
    return *this;
}
struct FUN_00b418b0 : VecContainerAlloc_Z<bool>
{
    unsigned int size;
    VbWordVec_Z vec;
    FUN_00b418b0(unsigned int n, bool val);
};
struct P133Pair;
struct P133Point
{
    float x, y, z;
    P133Point()
    {}
    P133Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    P133Point operator+(P133Point const& other) const
    {
        return P133Point(x + other.x, y + other.y, z + other.z);
    }
    P133Point operator*(float scale) const
    {
        return P133Point(x * scale, y * scale, z * scale);
    }
    float& operator[](int index)
    {
        return (&x)[index];
    }
};
struct P133Camera
{
    int unk00;
    P133Point position;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned char kind;
    int unk44, unk48;
    P133Camera* CloneCamera();
    P133Point const& GetPos() const
    {
        return position;
    }
    int GetKindHalf() const
    {
        return kind / 2;
    }
    P133Point FUN_00b40430();
    void FUN_00b404c0(P133Point const&, bool);
    void SetPos(P133Point const& p)
    {
        position = p;
    }
};
struct FUN_00b3f100
{
    int state;
    FUN_00b3f100();
    ~FUN_00b3f100()
    {}
    float FUN_00b3f130(float, float);
};
struct P133Frame
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    float height;
    int unk38, unk3c, unk40, unk44, unk48;
    float scale;
    int unk50;
};
struct P133Pair
{
    P133Camera* first;
    P133Camera* second;
};
struct P133Pairs;
struct P133ConstIter : IteratorBaseAuxB42
{
    P133Pair* ptr;
    void FUN_00b42980(P133Pair*, P133Pairs const*);
    P133ConstIter(P133Pair* p, P133Pairs const* v)
    {
        FUN_00b42980(p, v);
    }
    P133ConstIter& FUN_00b41d40();
    bool FUN_00b2ac30(P133ConstIter const&) const;
    P133Pair const& FUN_00b2ab50() const;
    P133Pair const& operator*() const
    {
        return FUN_00b2ab50();
    }
    bool operator!=(P133ConstIter const& rhs) const
    {
        return !FUN_00b2ac30(rhs);
    }
};
struct P133Iter : P133ConstIter
{
    P133Iter(P133Pair* p, P133Pairs const* v) : P133ConstIter(p, v)
    {}
    P133Pair& operator*() const
    {
        return (P133Pair&)**(P133ConstIter*)this;
    }
    P133Pair* operator->() const
    {
        return &**this;
    }
    P133Iter& operator++()
    {
        FUN_00b41d40();
        return *this;
    }
};
struct P133Pairs
{
    typedef P133Iter iterator;
    void* aux;
    int alaux, alval;
    P133Pair* first;
    P133Pair* last;
    P133Pair* end;
    iterator begin()
    {
        return iterator(first, this);
    }
    iterator end_iter()
    {
        return iterator(last, this);
    }
};
inline P133Pair const& P133ConstIter::FUN_00b2ab50() const
{
    if (!(this->_Has_container()))
    {
        _invalid_parameter_noinfo();
    }
    if (!(ptr < ((P133Pairs*)this->_Getmycont())->last))
    {
        _invalid_parameter_noinfo();
    }
    return *ptr;
}
struct P133ScalarTag
{
};
template <class T> inline P133ScalarTag p133_cat(T const&, T const&)
{
    P133ScalarTag tag;
    return tag;
}
template <class T, class A> inline void p133_destroy(T* a, T* b, A& al, P133ScalarTag)
{}
template <class T, class A> inline void p133_destroy(T* a, T* b, A& al)
{
    p133_destroy(a, b, al, p133_cat(a, b));
}
struct P133Scene
{
    int unk00, unk04, unk08, unk0c;
    stl::vector<P133Frame> frames;
};
struct P133List : stl::_Container_base_aux_alloc_real<stl::allocator<P133Camera*> >
{
    stl::allocator<P133Camera*> alval;
    P133Camera** first;
    P133Camera** last;
    P133Camera** end;
    P133List() : stl::_Container_base_aux_alloc_real<stl::allocator<P133Camera*> >(stl::allocator<P133Camera*>())
    {
        _Buy(0);
    }
    bool _Buy(unsigned int);
    ~P133List()
    {
        FUN_00b17f50();
    }
    void _Destroy(P133Camera** a, P133Camera** b)
    {
        p133_destroy(a, b, alval);
    }
    void FUN_00b17f50()
    {
        if (first != 0)
        {
            _Destroy(first, last);
            alval.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
    unsigned size() const
    {
        return last - first;
    }
    unsigned capacity() const
    {
        return first == 0 ? 0 : end - first;
    }
    P133Camera** _Ufill(P133Camera** p, unsigned count, P133Camera* const& val)
    {
        stl::_Uninit_fill_n(p, count, val, alval);
        return p + count;
    }
    struct OutIter
    {
        void* owner;
        P133Camera** ptr;
        OutIter(P133Camera**, P133List const*);
    };
    OutIter end_iter()
    {
        return OutIter(last, this);
    }
    void InsertAt(OutIter, P133Camera* const&);
    void FUN_00b15390(P133Camera* const& val)
    {
        if (size() < capacity())
            last = _Ufill(last, 1, val);
        else
            InsertAt(end_iter(), val);
    }
};
struct P133Owner
{
    P133Pairs pairs;
    float unk18, probability;
    P133Scene* scene;
    float scale;
    P133List FUN_00b40c80();
};

struct VBeginQ_00b41a50 : stl::vector<bool>
{
    iterator FUN_00b41a50();
};
// @fnv 0x00b41a50
VBeginQ_00b41a50::iterator VBeginQ_00b41a50::FUN_00b41a50()
{
    return (iterator((_Myvec.begin())._Myptr, this));
}

extern "C" unsigned int __cdecl strlen(const char*);
struct TrimCharAllocatorBase
{
};
struct TrimCharAllocator : TrimCharAllocatorBase
{
    TrimCharAllocator() throw()
    {}
    TrimCharAllocator(const TrimCharAllocator&) throw()
    {}
    void deallocate(char* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
struct TrimStringRoot
{
};
struct TrimStringReporter : TrimStringRoot
{
};
struct TrimStringBase : TrimStringReporter
{
    TrimCharAllocator _Alval;
    TrimStringBase(TrimCharAllocator _Al = TrimCharAllocator()) : _Alval(_Al)
    {}
    TrimStringBase(const TrimStringBase& _Right) : _Alval(_Right._Alval)
    {}
};
struct TrimString : TrimStringBase
{
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
    TrimString(const char* text) : TrimStringBase()
    {
        Tidy();
        assign(text);
    }
    static unsigned int StringLength(const char* _First)
    {
        return strlen(_First);
    }
    TrimString& assign(const char* _Ptr)
    {
        return assign(_Ptr, StringLength(_Ptr));
    }
    TrimString& assign(const char* _Ptr, unsigned int _Count);
    TrimString(const TrimString& other) : TrimStringBase(other)
    {
        Tidy();
        assign(other, 0, (unsigned int)-1);
    }
    void assign(const TrimString& other, unsigned int offset, unsigned int count);
    ~TrimString()
    {
        Tidy(true, 0);
    }
    static void copy_s(char*, unsigned int, const char*, unsigned int);
    static void deallocate(char*, unsigned int);
    char* _Myptr()
    {
        return 16 <= capacity ? storage.pointer : storage.buffer;
    }
    static void AssignChar(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
    void _Eos(unsigned int _Newsize)
    {
        length = _Newsize;
        AssignChar(_Myptr()[_Newsize], char());
    }
    void Tidy(bool release = false, unsigned int newsize = 0)
    {
        if (!release)
            ;
        else if (16 <= capacity)
        {
            char* _Ptr = storage.pointer;
            if (0 < newsize)
                copy_s(storage.buffer, 16, _Ptr, newsize);
            _Alval.deallocate(_Ptr, capacity + 1);
        }
        capacity = 15;
        _Eos(newsize);
    }
};
struct TrimException
{
    const char* message;
    bool owns;
    TrimException();
    TrimException(const TrimException& other);
    virtual ~TrimException() throw();
    virtual const char* what() const throw();
};
struct TrimLogicError : TrimException
{
    TrimString text;
    explicit TrimLogicError(const TrimString& value) : text(value)
    {}
    virtual ~TrimLogicError() throw()
    {}
    virtual const char* what() const throw()
    {
        return text.capacity < 16 ? text.storage.buffer : text.storage.pointer;
    }
};
struct TrimLengthError : TrimLogicError
{
    explicit TrimLengthError(const TrimString& value) : TrimLogicError(value)
    {}
    virtual ~TrimLengthError() throw()
    {}
};
struct TrimWords;
struct TrimContainer;
struct TrimAux : VecAux
{
    const TrimContainer* _Getcont() const
    {
        return static_cast<const TrimContainer*>(container);
    }
};
struct TrimContainer
{
    const TrimAux* _Myownedaux;
};
struct TrimAllocator
{
    unsigned int state;
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(unsigned int);
        return (0 < _Count ? _Count : 1);
    }
};
struct TrimIteratorBase
{
    const TrimAux* _Myaux;
    TrimIteratorBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const TrimContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    void _Set_container(const TrimContainer* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
};
struct TrimConstIterator : TrimIteratorBase
{
    unsigned int* _Myptr;
    TrimConstIterator(unsigned int* _Ptr, const TrimContainer* _Pvector);
    TrimConstIterator& FUN_00b2e330(int _Off);
    bool operator==(const TrimConstIterator& _Right) const
    {
        if (!(_Has_container() && _Myaux == _Right._Myaux))
            FUN_00ec7c56();
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const TrimConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
};
struct TrimIterator : TrimConstIterator
{
    TrimIterator(unsigned int* _Ptr, const TrimContainer* _Pvector) : TrimConstIterator(_Ptr, _Pvector)
    {}
    TrimIterator& operator+=(int _Off)
    {
        (*(TrimConstIterator*)this).FUN_00b2e330(_Off);
        return *this;
    }
    TrimIterator operator+(int _Off) const
    {
        TrimIterator _Tmp = *this;
        return _Tmp += _Off;
    }
};
struct TrimWords : TrimContainer
{
    unsigned int _Alaux;
    TrimAllocator _Alval;
    unsigned int* _Myfirst;
    unsigned int* _Mylast;
    unsigned int* _Myend;
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    TrimIterator begin()
    {
        return TrimIterator(_Myfirst, this);
    }
    TrimIterator end()
    {
        return TrimIterator(_Mylast, this);
    }
    TrimIterator _Make_iter(TrimConstIterator _Where) const
    {
        return TrimIterator(_Where._Myptr, this);
    }
    TrimIterator FUN_00b335c0(TrimConstIterator _First_arg, TrimConstIterator _Last_arg);
    void _Destroy(unsigned int* _First, unsigned int* _Last);
    unsigned int& operator[](unsigned int _Pos)
    {
        if (!(_Pos < size()))
            FUN_00ec7c56();
        return *(_Myfirst + _Pos);
    }
};
inline TrimConstIterator::TrimConstIterator(unsigned int* _Ptr, const TrimContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((TrimWords*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((TrimWords*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    _Set_container(_Pvector);
    _Myptr = _Ptr;
}
inline TrimConstIterator& TrimConstIterator::FUN_00b2e330(int _Off)
{
    if (!_Has_container())
        FUN_00ec7c56();
    if (!(_Myptr + _Off <= ((TrimWords*)_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((TrimWords*)_Getmycont())->_Myfirst))
        FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}
struct TrimScalarTag
{
};
struct TrimInputTag
{
};
struct TrimForwardTag : TrimInputTag
{
};
struct TrimBidirectionalTag : TrimForwardTag
{
};
struct TrimRandomTag : TrimBidirectionalTag
{
};
struct TrimCheckedTag
{
};
inline TrimScalarTag TrimPtrCat(unsigned int*&, unsigned int*&)
{
    TrimScalarTag _Cat;
    return _Cat;
}
inline TrimRandomTag TrimIterRandom(unsigned int*&, unsigned int*&)
{
    TrimRandomTag _Cat;
    return _Cat;
}
inline unsigned int* TrimCopyOpt(unsigned int* _First, unsigned int* _Last, unsigned int* _Dest, TrimRandomTag,
                                 TrimScalarTag, TrimCheckedTag)
{
    int _Off = _Last - _First;
    unsigned int* _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
struct TrimUnchangedTag
{
};
template <class Iter> inline Iter TrimCheckedBase(Iter& _It, TrimUnchangedTag)
{
    return _It;
}
template <class Iter> inline Iter TrimCheckedBase(Iter& _It)
{
    TrimUnchangedTag _Base_tag;
    return TrimCheckedBase(_It, _Base_tag);
}
inline unsigned int* TrimCopy(unsigned int* _First, unsigned int* _Last, unsigned int* _Dest)
{
    return TrimCopyOpt(TrimCheckedBase(_First), TrimCheckedBase(_Last), _Dest, TrimIterRandom(_First, _Dest),
                       TrimPtrCat(_First, _Dest), TrimCheckedTag());
}
inline void TrimDestroyRange(unsigned int*, unsigned int*, TrimAllocator&, TrimScalarTag)
{}
inline void TrimDestroyRange(unsigned int* _First, unsigned int* _Last, TrimAllocator& _Al)
{
    TrimDestroyRange(_First, _Last, _Al, TrimPtrCat(_First, _Last));
}
inline void TrimWords::_Destroy(unsigned int* _First, unsigned int* _Last)
{
    TrimDestroyRange(_First, _Last, _Alval);
}
inline TrimIterator TrimWords::FUN_00b335c0(TrimConstIterator _First_arg, TrimConstIterator _Last_arg)
{
    TrimIterator _First = _Make_iter(_First_arg);
    TrimIterator _Last = _Make_iter(_Last_arg);
    if (_First != _Last)
    {
        unsigned int* _Ptr = TrimCopy(_Last._Myptr, _Mylast, _First._Myptr);
        _Destroy(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}
struct BitTrim : TrimContainer
{
    unsigned int _Alaux;
    unsigned int _Mysize;
    TrimWords _Myvec;
    unsigned int max_size() const
    {
        const unsigned int _Maxsize = _Myvec.max_size();
        return _Maxsize < (unsigned int)(-1) / 32 ? _Maxsize * 32 : (unsigned int)(-1);
    }
    static unsigned int _Nw(unsigned int _Count)
    {
        return (_Count + 31) / 32;
    }
    void FUN_00b429d0() const
    {
        throw TrimLengthError("vector<bool> too long");
    }
    void FUN_00b41db0(unsigned int _Size);
};
// @fnv 0x00b41db0
void BitTrim::FUN_00b41db0(unsigned int _Size)
{
    if (max_size() < _Size)
        FUN_00b429d0();
    unsigned int _Words = _Nw(_Size);
    if (_Words < _Myvec.size())
        _Myvec.FUN_00b335c0(_Myvec.begin() + _Words, _Myvec.end());
    _Mysize = _Size;
    _Size %= 32;
    if (0 < _Size)
        _Myvec[_Words - 1] &= (unsigned int)((1 << _Size) - 1);
}

struct VbIterBaseQ_00b42c60 : stl::_Vb_iter_base<unsigned int, int, stl::vector<bool> >
{
    unsigned* FUN_00b42c60() const;
};
// @fnv 0x00b42c60
unsigned* VbIterBaseQ_00b42c60::FUN_00b42c60() const
{
    return ((((stl::vector<bool>*)this->_Getmycont())->_Myvec.begin())._Myptr);
}
