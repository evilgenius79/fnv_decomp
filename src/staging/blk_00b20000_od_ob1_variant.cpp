
// src/staging/blk_00b20000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00b20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00b20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
extern "C" void __cdecl FUN_00b02c90();
struct FUN_00b274a0_class
{
    void __thiscall FUN_00b02c90();
    FUN_00b274a0_class* __thiscall ResetState();
};
extern "C" void FUN_0044a450(int);
extern int DAT_010a57fc;
struct FUN_00b3c440_class
{
    int* vtbl;
    int FUN_00b3c440(int a);
};
extern int DAT_010a31fc;
struct FUN_00b3c910_class
{
    void InitVTable();
};
extern int DAT_010a5890;
struct FUN_00b3f0a0_Class
{
    void __thiscall FUN_00b3f0a0();
};
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3& __thiscall FUN_00b2a1c0(const NiPoint3& other);
};
unsigned int __cdecl FUN_00ec7c56();
struct FUN_00b393b0_Class
{
    int* vtbl;
    int __thiscall GetVtblAndValue(int a);
};
struct FUN_00b3c4b0_class
{
    FUN_00b3c4b0_class* __thiscall FUN_00b3c4b0(int a);
};
double __cdecl FUN_00ec6054(double);
struct FUN_00b3c5a0_class
{
    float data[0x14 / 4];
    int count;
    float FUN_00b3c5a0();
};
struct FUN_00b3c600_class
{
    float* pData;
    int* pCount;
    double __thiscall FUN_00b3c5a0();
    void NormalizeData();
};
struct FUN_00b27660_class
{
    unsigned char b0;
    unsigned char b1;
    int i4;
    unsigned short w8;
    int c0c;
    int c10;
    int c14;
    int c18;
    unsigned short w1c;
    int c20;
    int c24;
    unsigned short w28;
    int c2c;
    FUN_00b27660_class(int a);
};
struct FUN_00b373c0_class
{
    float f0;
    float f4;
    int i8;
    int iC;
    int i10;
    char b14;
    float f18;
    float f1C;
    float f20;
    float f24;
    int i28;
    int i2C;
    int i30;
    int i34;
    int i38;
    float f3C;
    float f40;
    FUN_00b373c0_class();
};
struct FUN_00b3c550_class
{
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    int i14;
    FUN_00b3c550_class(float a, float b, float c, float d, float e);
};
struct FUN_00b2e1b0_class
{
    unsigned char _unused[0x0c];
    unsigned char* m_data;
    unsigned char* m_kRayEnd;
    int m_pRayCursor;

    void __thiscall FreeBuffer();
};
void _Deallocate(void*);
void _Deallocate(void*);
struct FUN_00b34d90_class
{
    unsigned char padding[0x0c];
    char* begin;
    int value;
    char* end;

    void __thiscall FUN_00b34d90();
};
struct FUN_00b3c470_class
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    int i14;
    FUN_00b3c470_class();
};
struct FUN_00b3f030_Class
{
    int* vtbl;
    FUN_00b3f030_Class();
};
struct Random
{
    void* vtbl;
    void* __thiscall DestroyRandom(unsigned int flags);
};
extern const int vftable_Random[];
void _Deallocate(void*);
struct FUN_00b27060_cls
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
    unsigned char unk30;
    FUN_00b27060_cls* FUN_00b27060();
};
struct ResourceBufferOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char* buffer10;
    unsigned char* buffer14;
    unsigned char* buffer18;
    unsigned char* buffer1c;
    unsigned char* buffer20;
    unsigned char* buffer24;
    unsigned char* buffer28;
    unsigned char* buffer2c;
    unsigned char* buffer30;
    unsigned char* buffer34;
    unsigned char* buffer38;
    int unk3c;
    unsigned char* buffer40;

    void ClearFields();
    void FreeBuffers();
};
class FUN_00b276f0_sub
{
  public:
    void* Destroy(int kind);
};
class FUN_00b276f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int unk1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int m_2c;

    void Reset();
};
extern void __cdecl FormHeap_Free(void* p);
// InitBuffer
extern "C" int __cdecl FUN_00b2e4a0(unsigned int count, int flag);
extern "C" void __cdecl FUN_00b0fb80();
struct FnvB2e080
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    bool __thiscall InitBuffer(unsigned int count);
};
struct SpanPair
{
    int a;
    int b;
    bool Compare(SpanPair& other);
};
struct FUN_00b2e250_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    void Update(int newValue, int oldValue);
    SpanPair* FUN_00b2e250(SpanPair* out, int unk04, unsigned int idx1, int unk14, unsigned int idx2);
};
extern "C" int __cdecl FUN_00b2e3f0(int, int, int);
struct ProbePair
{
    unsigned int m_00;
    unsigned int m_04;
    bool FUN_00b16830(const ProbePair* key);
};
struct FUN_00b335c0_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};
unsigned int __cdecl FUN_00b42e50(unsigned int a, unsigned int b, unsigned int c);
struct FUN_00b335c0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int m_10;
    ProbePair FUN_00b335c0(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);
};
struct FUN_00b33af0_pair
{
    unsigned int a;
    unsigned int b;
    bool CompareTo(FUN_00b33af0_pair* other);
};
struct FUN_00b33af0_iter
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned short unk0e;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};
struct FUN_00b33af0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    FUN_00b33af0_pair* FUN_00b33af0(FUN_00b33af0_pair* out, unsigned int unk0c, unsigned int a, unsigned int unk14,
                                    unsigned int b);
};
extern "C" unsigned int __cdecl FUN_00b35c30(unsigned int, unsigned int, unsigned int);
struct Hldr0044
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void Init(unsigned int* p);
};
extern "C" void __stdcall FUN_00ec7894(Hldr0044* p, void* dat);
extern "C" void __cdecl FormHeap_Allocate(unsigned int scaled);
extern "C" int DAT_01140ef8;
extern "C" int DAT_010176f8;
// @fnv 0x00b35f00
extern "C" void __cdecl FUN_00b35f00(unsigned int n)
{
    Hldr0044 h;
    unsigned int tmp;

    if (n <= 0)
    {
        n = 0;
    }
    else
    {
        if (0xFFFFFFFFu / n < 2)
        {
            tmp = 0;
            h.Init(&tmp);
            h.m_iWordAt00 = (int)&DAT_010176f8;
            FUN_00ec7894(&h, &DAT_01140ef8);
        }
    }

    FormHeap_Allocate(n * 2);
}

struct FUN_00b31270
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00b31270();
    ~FUN_00b31270();
};
struct FUN_00449fd0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00449fd0();
    ~FUN_00449fd0();
};
struct FUN_00b37590
{
    float m_00;
    float m_04;
    float m_08;
    FUN_00b31270 m_0c;
    FUN_00b31270 m_24;
    FUN_00449fd0 m_3c;
    FUN_00b31270 m_54;
    FUN_00b31270 m_6c;
    FUN_00b37590();
};
struct LocalScratch
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
};
FUN_00b31270::FUN_00b31270()
{}
FUN_00b31270::~FUN_00b31270()
{}
FUN_00449fd0::FUN_00449fd0()
{}
FUN_00449fd0::~FUN_00449fd0()
{}
struct FUN_00b3c660_cls
{
    float data[5];
    int count;
    FUN_00b3c660_cls(int n);
    ~FUN_00b3c660_cls();
    FUN_00b3c660_cls FUN_00b3c660(FUN_00b3c660_cls* other);
};
struct FUN_00aa7830_cls
{
    float data[5];
    int count;
    FUN_00aa7830_cls(int n);
    ~FUN_00aa7830_cls();
};
struct FUN_00b3c750_cls
{
    float data[5];
    int count;
    FUN_00aa7830_cls __thiscall Subtract(const FUN_00b3c5a0_class* other);
};
struct FUN_00aa7830_holder
{
    void FUN_00aa7830();
};
struct ScaledVec6
{
    float m_v[6];
    ScaledVec6(int n)
    {
        FUN_00b3c4b0_class* p = reinterpret_cast<FUN_00b3c4b0_class*>(this);
        p->FUN_00b3c4b0(n);
    }
    ~ScaledVec6()
    {
        reinterpret_cast<FUN_00aa7830_holder*>(this)->FUN_00aa7830();
    }
};
struct FUN_00b3c840_cls
{
    float m_data[5];
    int m_uiItemCount;
    ScaledVec6 ScaleData(float scale);
};
// Stand-in for the game object behind FUN_00b3c930.
//
// The original is an /Od constructor:
//   * it has an EH frame - the scope-state variable is the ExceptionState
//     field at [ebp-4] and it walks  -1 -> 0 -> 1 -> -1,
//   * it has a /GS cookie (the value lives at [ebp-0x14]),
//   * it calls the constructor of a sub-object at +0x00 and of a second
//     sub-object at +0x18 (both through the same constructor),
//   * it then calls one more member function on `this`.
// The `this` home is at [ebp-0x10] and the saved fs:[0] at [ebp-0xc].
struct FNV_00b3c930_Member
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    int i14;
    FNV_00b3c930_Member();
    ~FNV_00b3c930_Member();
};
struct FUN_00b3c930_Obj
{
    FNV_00b3c930_Member m00;  // +0x00
    FNV_00b3c930_Member m18;  // +0x18
    void FNV_00b3cc30();
    FUN_00b3c930_Obj();
    ~FUN_00b3c930_Obj();
};
struct SubB3
{
    int unk[6];
    SubB3();
};
struct FUN_00b3cd60
{
    bool m_b00;
    float m_f04;
    int m_i08;
    int m_i0c;
    SubB3 m_sub;
    float m_f28;
    float m_f2c;
    float m_f30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;

    FUN_00b3cd60();
};
// ClearString : forwards to a string-like member stored at +0x14 and resets it.
struct StringLike
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void __thiscall Clear(bool flag, unsigned int count);
};
struct FUN_00b3d800_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    StringLike m_str;
    void ClearString();
};
// Stand-in for the game object behind GetElementAtOffset.
//
// The original reads a 32-bit offset from +0x00 of the object, a byte range
// (base/end) out of the sub-structure at +0x04, and returns the 32-bit word
// that lives at (base + offset).
struct FNV_00b3efe0_Buffer
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;  // base address
    unsigned int unk10;  // end address
};
struct FNV_00b3efe0_Obj
{
    unsigned int unk00;  // current byte offset
    FNV_00b3efe0_Buffer unk04;
    unsigned int GetElementAtOffset();
};
void __cdecl _Deallocate(void*);
struct FUN_00b37880_class
{
    void __thiscall FUN_00b37880();
};
struct FUN_00b3fdd0_class
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
    FUN_00b37880_class* unk5c;
    void __thiscall FUN_00b3fdd0(FUN_00b37880_class* value);
};
extern int DAT_010173e8;
struct FUN_00b3c3b0_Sub
{
    void __thiscall FUN_0044a730(int a, int b);
};
struct FUN_00b3c3b0_Class
{
    int* unk00;
    int unk04;
    int unk08;
    FUN_00b3c3b0_Sub unk0c;

    void __thiscall FUN_00ec79a1();
    void __thiscall Initialize();
};
struct PtrVector
{
    int unk00[3];
    void** m_ppFirst;  // +0x0c
    void** m_ppLast;   // +0x10
    void** m_ppEnd;    // +0x14

    void*& FUN_00b31230(unsigned int uiPos);
};

template <class T> struct VecStandIn
{
    int m_00;
    int m_04;
    int m_08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;

    unsigned int size() const
    {
        return (unsigned int)(_Mylast - _Myfirst);
    }
    T& operator[](unsigned int _Pos)
    {
        if (size() <= _Pos)
        {
            FUN_00ec7c56();
        }
        return *(_Myfirst + _Pos);
    }
};

struct PointOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    VecStandIn<float> m_kPoints;

    float* FUN_00b31020(int index);
};

// @fnv 0x00b31020
float* PointOwner::FUN_00b31020(int index)
{
    return &m_kPoints[0] + index * 3;
}

struct SubObj_b3f
{
    int unk00;
    ~SubObj_b3f();
};
struct ClsB3FCF0
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50;
    SubObj_b3f* unk54;
    void FUN_00b3fcf0(SubObj_b3f* value);
};
// @fnv 0x00b3fcf0
void ClsB3FCF0::FUN_00b3fcf0(SubObj_b3f* value)
{
    if (unk54 != value)
    {
        delete unk54;
        unk54 = value;
    }
}

extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
struct B2ESecureTag
{
};
struct B2ETraits
{
    typedef char char_type;
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
    static char* _Copy_s(char* _First1, unsigned int _Size_in_bytes, const char* _First2, unsigned int _Count)
    {
        memcpy_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
};
template <class _Traits> inline B2ESecureTag B2ECharTraitsCat()
{
    B2ESecureTag _Secure;
    return (_Secure);
}
template <class _Traits>
inline char* B2ECopyS(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, B2ESecureTag)
{
    return _Traits::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class _Traits>
inline char* B2ECopyS(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
{
    return B2ECopyS<_Traits>(_First1, _Size, _First2, _Count, B2ECharTraitsCat<_Traits>());
}
void __cdecl B2EOpDelete(void*);
struct B2ETag
{
};
template <class T> inline void B2EDestroy(T* p)
{
    p->~T();
}
template <class E> struct B2EAlloc
{
    void deallocate(E* p, unsigned int)
    {
        B2EOpDelete(p);
    }
    void destroy(E* p)
    {
        B2EDestroy(p);
    }
};
template <class T1, class T2> inline B2ETag B2EPtrCat(T1&, T2&)
{
    B2ETag t;
    return t;
}
template <class P, class A> inline void B2EDestroyRange(P first, P last, A& al, B2ETag)
{
    for (; first != last; ++first)
        al.destroy(first);
}
template <class P, class A> inline void B2EDestroyRange(P first, P last, A& al)
{
    B2EDestroyRange(first, last, al, B2EPtrCat(first, last));
}
struct B2EString
{
    B2EAlloc<char> m_alval;
    union
    {
        char m_buf[16];
        char* m_ptr;
    } m_bx;
    unsigned int m_iElementCount;
    unsigned int m_res;
    char* _Myptr()
    {
        return (16 <= m_res ? m_bx.m_ptr : m_bx.m_buf);
    }
    void _Eos(unsigned int _Newsize)
    {
        B2ETraits::assign(_Myptr()[m_iElementCount = _Newsize], char());
    }
    void FUN_0044a730(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (16 <= m_res)
        {
            char* _Ptr = m_bx.m_ptr;
            if (0 < _Newsize)
                B2ECopyS<B2ETraits>(m_bx.m_buf, 16, _Ptr, _Newsize);
            m_alval.deallocate(_Ptr, m_res + 1);
        }
        m_res = 16 - 1;
        _Eos(_Newsize);
    }
    ~B2EString()
    {
        FUN_0044a730(true);
    }
};
struct B2ESub
{
    B2EString m_str;
};
struct B2EElem
{
    int unk00, unk04, unk08, unk0c, unk10;
    B2ESub m_sub;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
};
struct B2EVector
{
    B2EAlloc<B2EElem> m_alval;
    void FUN_00b2e140(B2EElem* first, B2EElem* last);
};
// @fnv 0x00b2e140
void B2EVector::FUN_00b2e140(B2EElem* first, B2EElem* last)
{
    B2EDestroyRange(first, last, m_alval);
}

struct LengthErrorBaseB9718
{
    virtual void v0();
    int m_iWordAt04;
    int m_8;
    LengthErrorBaseB9718(const int& msg);
};
struct LengthErrorB9718 : LengthErrorBaseB9718
{
    virtual void v1();
    LengthErrorB9718(const int& msg) : LengthErrorBaseB9718(msg)
    {}
    ~LengthErrorB9718() throw();
};
// @fnv 0x00b2e4a0
void* __cdecl FUN_00b2e4a0(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xFFFFFFFFu / count < 0x54)
        {
            throw LengthErrorB9718(0);
        }
    }
    return operator new(count * 0x54);
}

template <class T> struct B30Vec
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    T& operator[](unsigned int _Pos)
    {
        if (_Pos >= (unsigned int)(_Mylast - _Myfirst))
            FUN_00ec7c56();
        return *(_Myfirst + _Pos);
    }
};
struct B30Owner
{
    char pad00[0x58];
    B30Vec<B30Vec<void*> > m_kLists;
    unsigned short FUN_00b0a9a0(unsigned short usType);
    void FUN_00b30c80(unsigned short usType);
};
// @fnv 0x00b30c80
void B30Owner::FUN_00b30c80(unsigned short usType)
{
    int p;
    void* a;
    int iA;
    int iB;
    int a1;
    for (p = 0; p < FUN_00b0a9a0(usType); p++)
    {
        a = m_kLists[usType][p];
        FormHeap_Free(a);
        m_kLists[usType][p] = 0;
    }
}

unsigned int __cdecl FUN_00ec7c56();
struct ScalarTag
{
};
struct NonScalarTag
{
};
inline ScalarTag ptr_cat(int*&, int*&)
{
    ScalarTag cat;
    return cat;
}
struct Value;
inline NonScalarTag ptr_cat(Value*&, Value*&)
{
    return NonScalarTag();
}
template <class T> inline void destroy_object(T* p)
{
    p->~T();
}

struct ForwardTag
{
};
struct RandomTag : ForwardTag
{
};
struct CheckedTag
{
};
inline RandomTag iter_random(Value* const&, Value* const&)
{
    RandomTag cat;
    return cat;
}
struct Proxy
{
    void* unk00;
};
template <class T> struct Alloc
{
    void deallocate(T* p, unsigned n)
    {
        operator delete(p);
    }
    void destroy(T* p)
    {
        destroy_object(p);
    }
};
struct Container
{
    Proxy* unk00;
};
struct ContainerAlloc : Container
{
    Alloc<Proxy> unk04;
    ~ContainerAlloc()
    {
        unk00->~Proxy();
        unk04.deallocate(unk00, 1);
    }
};
struct ValueBase : ContainerAlloc
{
    Alloc<int> unk08;
    int* unk0c;
    int* unk10;
    int* unk14;
};
struct Value : ValueBase
{
    void destroy(int* first, int* last)
    {
        destroy_range(first, last, unk08);
    }
    static void destroy_range(int* first, int* last, Alloc<int>& al)
    {
        destroy_scalar(first, last, al, ptr_cat(first, last));
    }
    static void destroy_scalar(int* first, int* last, Alloc<int>& al, ScalarTag)
    {}
    void FUN_00b17f50()
    {
        if (unk0c)
        {
            destroy(unk0c, unk10);
            unk08.deallocate(unk0c, unk14 - unk0c);
        }
        unk0c = 0;
        unk10 = 0;
        unk14 = 0;
    }
    ~Value()
    {
        FUN_00b17f50();
    }
};
struct ObjFields
{
    ObjFields** unk00;
    int unk04;
    Alloc<Value> allocator;
    Value* unk0c;
    Value* unk10;
    Value* unk14;
};
struct Obj;
struct Universal
{
};
struct BaseIter : Universal
{
    ObjFields** unk00;
    __forceinline BaseIter() : unk00(0)
    {}
    __forceinline void set(ObjFields* c)
    {
        unk00 = c->unk00;
    }
};
struct IteratorWithBase : BaseIter
{
};
struct Ranit : IteratorWithBase
{
};
struct ConstIter : Ranit
{
    Value* unk04;
    __forceinline ConstIter(Value* p, ObjFields* c)
    {
        if (!c || c->unk0c > p || p > c->unk10)
            FUN_00ec7c56();
        set(c);
        unk04 = p;
    }
    bool equal(const ConstIter& b) const
    {
        if (!unk00 || unk00 != b.unk00)
            FUN_00ec7c56();
        return unk04 == b.unk04;
    }
    bool FUN_00b16830(const ConstIter& b) const
    {
        return !equal(b);
    }
    ConstIter& FUN_00b16890(int n);
};
struct Iter : ConstIter
{
    __forceinline Iter(Value* p, ObjFields* c) : ConstIter(p, c)
    {}
    __forceinline Iter& operator+=(int n)
    {
        ((ConstIter*)this)->FUN_00b16890(n);
        return *this;
    }
    __forceinline Iter operator+(int n) const
    {
        Iter tmp = *this;
        return (tmp += n);
    }
};
struct Obj : ObjFields
{
    __forceinline unsigned size() const
    {
        return unk10 - unk0c;
    }
    __forceinline Iter begin()
    {
        return Iter(unk0c, this);
    }
    __forceinline Iter end()
    {
        return Iter(unk10, this);
    }
    unsigned capacity() const
    {
        return unk0c == 0 ? 0 : unk14 - unk0c;
    }
    unsigned max_size() const
    {
        return 0xffffffffU / sizeof(Value);
    }
    void xlen();
    Value* allocate(unsigned);
    void deallocate(Value*, unsigned);
    void destroy(Value* first, Value* last)
    {
        destroy_range(first, last, allocator);
    }
    static void destroy_range(Value* first, Value* last, Alloc<Value>& al)
    {
        destroy_nonscalar(first, last, al, ptr_cat(first, last));
    }
    static void destroy_nonscalar(Value* first, Value* last, Alloc<Value>& al, NonScalarTag)
    {
        for (; first != last; ++first)
            al.destroy(first);
    }

    Value* umove(Value*, Value*, Value*);
    void ufill(Value*, unsigned, const Value&);
    void fill(Value*, Value*, const Value&);
    void move_backward(Value*, Value*, Value*);
    void FUN_00b34450(ConstIter where, unsigned count, const Value& val)
    {
        unsigned cap = capacity();
        if (count == 0)
            ;
        else if (max_size() - size() < count)
            xlen();
        else if (cap < size() + count)
        {
            cap = max_size() - cap / 2 < cap ? 0 : cap + cap / 2;
            if (cap < size() + count)
                cap = size() + count;
            Value* newvec = allocate(cap);
            unsigned off = where.unk04 - unk0c;
            int copied = 0;
            try
            {
                ufill(newvec + off, count, val);
                ++copied;
                umove(unk0c, where.unk04, newvec);
                ++copied;
                umove(where.unk04, unk10, newvec + off + count);
            }
            catch (...)
            {
                if (1 < copied)
                    destroy(newvec, newvec + off);
                if (0 < copied)
                    destroy(newvec + off, newvec + off + count);
                deallocate(newvec, cap);
                throw;
            }
            count += size();
            if (unk0c)
            {
                destroy(unk0c, unk10);
                deallocate(unk0c, unk14 - unk0c);
            }
            unk14 = newvec + cap;
            unk10 = newvec + count;
            unk0c = newvec;
        }
        else if ((unsigned)(unk10 - where.unk04) < count)
        {
            Value tmp = val;
            umove(where.unk04, unk10, where.unk04 + count);
            try
            {
                ufill(unk10, count - (unk10 - where.unk04), tmp);
            }
            catch (...)
            {
                destroy(where.unk04 + count, unk10 + count);
                throw;
            }
            unk10 += count;
            fill(where.unk04, unk10 - count, tmp);
        }
        else
        {
            Value tmp = val;
            Value* oldend = unk10;
            unk10 = umove(oldend - count, oldend, unk10);
            move_backward(where.unk04, oldend - count, oldend);
            fill(where.unk04, where.unk04 + count, tmp);
        }
    }
    __forceinline Iter make_iter(ConstIter where)
    {
        return Iter(where.unk04, this);
    }
    static Value* copy_random(Value*, Value*, Value*, RandomTag, NonScalarTag, CheckedTag);
    static Value* unchecked_copy(Value* first, Value* last, Value* dest)
    {
        return copy_random(first, last, dest, iter_random(first, dest), ptr_cat(first, dest), CheckedTag());
    }
    bool iter_ne(const Iter& a, const Iter& b)
    {
        return a.FUN_00b16830(b);
    }
    __forceinline bool iter_lt(const Iter& a, const Iter& b)
    {
        if (a.unk00 != b.unk00)
            FUN_00ec7c56();
        return a.unk04 < b.unk04;
    }
    void orphan_range(Value*, Value*);
    Iter FUN_00b33030(ConstIter first_arg, ConstIter last_arg)
    {
        Iter first = make_iter(first_arg);
        Iter last = make_iter(last_arg);
        if (iter_ne(first, last))
        {

            Value* ptr = unchecked_copy(last.unk04, unk10, first.unk04);

            destroy(ptr, unk10);
            unk10 = ptr;
        }
        return first;
    }
    void FUN_00b32de0(unsigned n, Value val);
};
// @fnv 0x00b32de0
void Obj::FUN_00b32de0(unsigned n, Value val)
{
    if (size() < n)
        FUN_00b34450(end(), n - size(), val);
    else if (n < size())
        FUN_00b33030(begin() + n, end());
}

struct Vector342;
struct Aux342
{
    const Vector342* container;
    const Vector342* GetContainer() const
    {
        return container;
    }
};
struct IteratorOwner342
{
    const Aux342* owner;
    IteratorOwner342() : owner(0)
    {}
};
struct ConstIterator342 : IteratorOwner342
{
    int* pointer;
    const Vector342* GetContainer() const
    {
        return owner ? owner->GetContainer() : 0;
    }
    ConstIterator342& FUN_00ac1000(int offset);
    ConstIterator342(int*, const Vector342*);
    bool IsContainerSet() const
    {
        return owner != 0;
    }
    bool SameContainer(const ConstIterator342& other) const
    {
        return owner == other.owner;
    }
    int operator-(const ConstIterator342& other) const
    {
        if (!IsContainerSet() || !SameContainer(other))
            FUN_00ec7c56();
        return pointer - other.pointer;
    }
};
struct Iterator342 : ConstIterator342
{
    Iterator342(int* pointer, const Vector342* vector) : ConstIterator342(pointer, vector)
    {}
    Iterator342& operator+=(int offset)
    {
        ConstIterator342::FUN_00ac1000(offset);
        return *this;
    }
    Iterator342 operator+(int offset) const
    {
        Iterator342 temporary = *this;
        return temporary += offset;
    }
};
struct Vector342
{
    const Aux342* owner;
    int unk04, unk08;
    int* first;
    int* last;
    int* end;
    unsigned int Size() const
    {
        return last - first;
    }
    Iterator342 Begin()
    {
        return Iterator342(first, this);
    }
    void FUN_00abc320(ConstIterator342 where, unsigned int count, const int& value);
    Iterator342 FUN_00b33240(ConstIterator342 where, const int& value);
};
inline ConstIterator342::ConstIterator342(int* value, const Vector342* vector)
{
    if (!vector || vector->first > value || value > vector->last)
        FUN_00ec7c56();
    owner = vector->owner;
    pointer = value;
}
inline ConstIterator342& ConstIterator342::FUN_00ac1000(int offset)
{
    if (!IsContainerSet())
        FUN_00ec7c56();
    if (!(pointer + offset <= GetContainer()->last && pointer + offset >= GetContainer()->first))
        FUN_00ec7c56();
    pointer += offset;
    return *this;
}
// @fnv 0x00b33240
Iterator342 Vector342::FUN_00b33240(ConstIterator342 where, const int& value)
{
    unsigned int offset = Size() == 0 ? 0 : where - Begin();
    FUN_00abc320(where, 1, value);
    return Begin() + offset;
}

namespace fnv_00b337f0 {
unsigned int __cdecl FUN_00ec7c56();
struct ScalarTag
{
};
template <class T> struct ValueAllocator
{
};
template <class T> inline ScalarTag pointerCategory(T*, T*)
{
    return ScalarTag();
}
template <class T> inline void destroyRange(T*, T*, ValueAllocator<T>&, ScalarTag)
{}
template <class T> inline void destroyRange(T* a, T* b, ValueAllocator<T>& al)
{
    destroyRange(a, b, al, pointerCategory(a, b));
}
struct ContainerBase
{
    void* proxy;
};
struct UniversalIter
{
};
struct IterBase : UniversalIter
{
    void* cont;
    IterBase() : cont(0)
    {}
    void setContainer(const ContainerBase* owner)
    {
        cont = owner->proxy;
    }
};
template <class T> struct RanIter : IterBase
{
};
template <class T> struct ShortVec;
template <class T> struct ConstIter : RanIter<T>
{
    T* ptr;
    ConstIter(T* p, const ContainerBase* owner)
    {
        if (owner == 0 || ((ShortVec<T>*)owner)->first > p || p > ((ShortVec<T>*)owner)->last)
            FUN_00ec7c56();
        this->setContainer(owner);
        ptr = p;
    }
    bool hasContainer() const
    {
        return this->cont != 0;
    }
    bool sameContainer(const ConstIter& rhs) const
    {
        return this->cont == rhs.cont;
    }
    bool operator==(const ConstIter& rhs) const
    {
        if (!(hasContainer() && sameContainer(rhs)))
            FUN_00ec7c56();
        return ptr == rhs.ptr;
    }
    bool operator!=(const ConstIter& rhs) const
    {
        return !(*this == rhs);
    }
    ConstIter& __thiscall FUN_00b359d0(int offset);
};
template <class T> struct VecIter : ConstIter<T>
{
    VecIter(T* p, const ContainerBase* owner) : ConstIter<T>(p, owner)
    {}
    VecIter& operator+=(int offset)
    {
        ConstIter<T>::FUN_00b359d0(offset);
        return *this;
    }
    VecIter operator+(int offset) const
    {
        VecIter tmp = *this;
        return (tmp += offset);
    }
};
template <class T> struct ShortVec : ContainerBase
{
    int unk04;
    ValueAllocator<T> allocator;
    T* first;
    T* last;
    T* endOfStorage;
    VecIter<T> begin()
    {
        return VecIter<T>(first, this);
    }
    VecIter<T> end()
    {
        return VecIter<T>(last, this);
    }
    unsigned int size() const
    {
        return last - first;
    }

    unsigned int capacity() const
    {
        return endOfStorage - first;
    }
    unsigned int max_size() const
    {
        return 0x7fffffff;
    }
    T* allocate(unsigned int count);
    void deallocate(T* ptr, unsigned int count);
    void destroy(T* a, T* b)
    {
        destroyRange(a, b, allocator);
    }
    T* move(T* a, T* b, T* c);
    void fill(T* a, T* b, const T& val);
    T* fillNew(T* a, unsigned int n, const T& val);
    void moveBackward(T* a, T* b, T* c);
    void tooLong();
    void __thiscall FUN_00b34e10(ConstIter<T> where, unsigned int count, const T& val)
    {
        unsigned int cap = capacity();
        if (count == 0)
            ;
        else if (max_size() - size() < count)
            tooLong();
        else if (cap < size() + count)
        {
            cap = max_size() - cap / 2 < cap ? 0 : cap + cap / 2;
            if (cap < size() + count)
                cap = size() + count;
            T* newvec = allocate(cap);
            unsigned int whereoff = where.ptr - first;
            int copied = 0;
            try
            {
                fillNew(newvec + whereoff, count, val);
                ++copied;
                move(first, where.ptr, newvec);
                ++copied;
                move(where.ptr, last, newvec + (whereoff + count));
            }
            catch (...)
            {
                if (1 < copied)
                    destroy(newvec, newvec + whereoff);
                if (0 < copied)
                    destroy(newvec + whereoff, newvec + whereoff + count);
                deallocate(newvec, cap);
                throw;
            }
            count += size();
            if (first != 0)
            {
                destroy(first, last);
                deallocate(first, endOfStorage - first);
            }
            endOfStorage = newvec + cap;
            last = newvec + count;
            first = newvec;
        }
        else if ((unsigned int)(last - where.ptr) < count)
        {
            T tmp = val;
            move(where.ptr, last, where.ptr + count);
            try
            {
                fillNew(last, count - (last - where.ptr), tmp);
            }
            catch (...)
            {
                destroy(where.ptr + count, last + count);
                throw;
            }
            last += count;
            fill(where.ptr, last - count, tmp);
        }
        else
        {
            T tmp = val;
            T* oldend = last;
            last = move(oldend - count, oldend, last);
            moveBackward(where.ptr, oldend - count, oldend);
            fill(where.ptr, where.ptr + count, tmp);
        }
    }
    VecIter<T> makeIter(ConstIter<T> where) const
    {
        return VecIter<T>(where.ptr, this);
    }
    T* copy(T* a, T* b, T* c);
    VecIter<T> __thiscall FUN_00b33af0(ConstIter<T> a, ConstIter<T> b)
    {
        ConstIter<T> firstArgument = a;
        T* firstPointer = firstArgument.ptr;
        VecIter<T> firstResult(firstPointer, this);
        VecIter<T> start = firstResult;
        ConstIter<T> lastArgument = b;
        T* lastPointer = lastArgument.ptr;
        VecIter<T> lastResult(lastPointer, this);
        VecIter<T> finish = lastResult;
        if (start != finish)
        {
            T* ptr = copy(finish.ptr, last, start.ptr);
            T* destroyFirst = ptr;
            T* destroyLast = last;
            ScalarTag category = pointerCategory(destroyFirst, destroyLast);
            destroyRange(destroyFirst, destroyLast, allocator, category);
            last = ptr;
        }
        return start;
    }

// @fnv 0x00b337f0
    void FUN_00b337f0(unsigned int newSize, T val)
    {
        if (size() < newSize)
            FUN_00b34e10(end(), newSize - size(), val);
        else if (newSize < size())
            FUN_00b33af0(begin() + newSize, end());
    }
};
template void ShortVec<unsigned short>::FUN_00b337f0(unsigned int, unsigned short);
}  // namespace fnv_00b337f0

// Genuine VC9 secure iterator/auxiliary-container accessors. No scalar
// uninitialized-read tricks from the historical near match are retained.
struct Container445;
struct Aux445
{
    const Container445* container;
    const Container445* GetContainer() const
    {
        return container;
    }
};
struct Container445
{
    Aux445* proxy;
};
struct Vector445 : Container445
{
    unsigned allocator04, allocator08;
    unsigned short* first;
    unsigned short* last;
};
struct IteratorBase445
{
    const Aux445* aux;
    bool IsContainerSet() const
    {
        return aux != 0;
    }
    const Container445* GetContainer() const
    {
        return aux ? aux->GetContainer() : 0;
    }
};
struct Iterator445 : IteratorBase445
{
    const unsigned short* pointer;
    Iterator445& FUN_00b359d0(int offset);
};
// @fnv 0x00b359d0
Iterator445& Iterator445::FUN_00b359d0(int offset)
{
    if (!IsContainerSet())
        FUN_00ec7c56();
    if (!(pointer + offset <= static_cast<const Vector445*>(GetContainer())->last &&
          pointer + offset >= static_cast<const Vector445*>(GetContainer())->first))
        FUN_00ec7c56();
    pointer += offset;
    return *this;
}

struct FUN_00b3ff20_Base
{
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
    int f64;
};

class FUN_00b37880
{
  public:
    ~FUN_00b37880();
};

struct FUN_00b3ff20_Class : public FUN_00b3ff20_Base
{
    FUN_00b37880* unk68;
    void FUN_00b3ff20(FUN_00b37880* arg);
};

// @fnv 0x00b3ff20
void FUN_00b3ff20_Class::FUN_00b3ff20(FUN_00b37880* arg)
{
    if (this->unk68 != arg)
    {
        delete this->unk68;
        this->unk68 = arg;
    }
}

struct BufferGroup
{
    int unk00, unk04, unk08;
    unsigned short count;
    unsigned char* kinds;
    unsigned char* indices;
    float* positions;
    void** auxiliary;
    float** transforms;
    unsigned int* values;
    float* normals;
    float* bitangents;
    float* tangents;
    float* weights;
    unsigned char* selectors;
    int unk3c;
    float* originalPositions;
    BufferGroup();
    ~BufferGroup();
};
struct PointRecord
{
    int unk00;
    struct Vec3
    {
        float x, y, z;
        __forceinline Vec3& operator=(const Vec3& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            return *this;
        }
    } position;
    unsigned char index;
    unsigned int value;
    int unk18;
    Vec3 normal, tangent, bitangent;
    unsigned char kind;
    float weight;
    unsigned char selector;
    __forceinline int getKind() const
    {
        return kind;
    }
    __forceinline unsigned char getIndex() const
    {
        return index;
    }
    __forceinline float getWeight() const
    {
        return weight;
    }
    __forceinline unsigned getValue() const
    {
        return value;
    }
    __forceinline unsigned char getSelector() const
    {
        return selector;
    }
};
struct PointVector
{
    int unk00, unk04, unk08;
    PointRecord** begin;
    PointRecord** end;
    PointRecord** capacity;
    __forceinline unsigned size() const
    {
        return end - begin;
    }
    __forceinline PointRecord*& operator[](unsigned i)
    {
        PointVector* self = this;
        {
            if (!(i < self->size()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        PointRecord*& selected = self->begin[i];
        return selected;
    }
};
struct SelectorRange
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int base, count;
    __forceinline void getRange(unsigned& b, unsigned& n) const
    {
        b = base;
        n = count;
    }
};
struct GroupBuilder
{
    unsigned char compact, dynamic;
    SelectorRange* range;
    unsigned short width;
    int unk0c;
    float** matrices;
    float* auxiliary;
    int unk18, unk1c, unk20, unk24;
    unsigned short groupCount;
    BufferGroup* groups;
    void FUN_00b29380(unsigned short count, PointVector* input);
};
// @fnv 0x00b29380
void GroupBuilder::FUN_00b29380(unsigned short count, PointVector* input)
{
    if (input && matrices && range && auxiliary)
    {
        groupCount = count;
        groups = new BufferGroup[count];
        for (unsigned short i = 0; i < count; i++)
        {
            BufferGroup* group = &groups[i];
            group->count = (unsigned short)input[i].size();
            group->transforms = new float*[group->count];
            for (int j = 0; j < group->count; j++)
            {

                group->transforms[j] = matrices[i] + width * 16 * input[i][j]->getKind() + 16 * input[i][j]->index;
            }
            if (dynamic)
            {
                group->originalPositions = new float[group->count * 3];
                for (int k = 0; k < group->count; k++)
                {
                    *((PointRecord::Vec3*)&group->originalPositions[k * 3]) = input[i][k]->position;
                }
                group->weights = new float[group->count];
                for (int l = 0; l < group->count; l++)
                {

                    group->weights[l] = 1.0f - input[i][l]->getWeight();
                }
                group->selectors = new unsigned char[group->count];
                for (int m = 0; m < group->count; m++)
                {
                    unsigned char selector = input[i][m]->selector;
                    unsigned int remapBase = 0;
                    unsigned int remapCount = 1;
                    range->getRange(remapBase, remapCount);
                    selector = (unsigned char)remapBase + selector % (unsigned char)remapCount;
                    group->selectors[m] = selector;
                }
            }
            group->positions = new float[group->count * 3];
            for (unsigned int n = 0; n < group->count; n++)
            {
                *((PointRecord::Vec3*)&group->positions[n * 3]) = input[i][n]->position;
            }
            group->kinds = new unsigned char[group->count];
            for (unsigned int o = 0; o < group->count; o++)
            {
                group->kinds[o] = input[i][o]->getKind();
            }
            group->indices = new unsigned char[group->count];
            for (unsigned int p = 0; p < group->count; p++)
            {

                group->indices[p] = width * input[i][p]->getKind() + input[i][p]->index;
            }
            group->auxiliary = new void*[group->count];
            for (unsigned int q = 0; q < group->count; q++)
            {
                group->auxiliary[q] = auxiliary + 8 * input[i][q]->kind;
            }
            group->values = new unsigned int[group->count];
            for (unsigned int r = 0; r < group->count; r++)
            {

                group->values[r] = input[i][r]->getValue();
            }
            if (!compact)
            {
                group->normals = new float[group->count * 3];
                for (unsigned int s = 0; s < group->count; s++)
                {
                    *((PointRecord::Vec3*)&group->normals[s * 3]) = input[i][s]->normal;
                }
            }
            if (!compact)
            {
                group->tangents = new float[group->count * 3];
                group->bitangents = new float[group->count * 3];
                for (unsigned int t = 0; t < group->count; t++)
                {
                    *((PointRecord::Vec3*)&group->tangents[t * 3]) = input[i][t]->tangent;
                    *((PointRecord::Vec3*)&group->bitangents[t * 3]) = input[i][t]->bitangent;
                }
            }
        }
    }
}

struct FnvContBase
{
    int unk00;
};

struct FnvContAux
{
    FnvContBase* m_pContainer;
    FnvContBase* GetCont() const
    {
        return m_pContainer;
    }
};

struct FnvCont : public FnvContBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_iElementCount;
};

class FnvVecIter
{
  public:
    FnvContAux* m_pAux;
    unsigned int m_uiEdgeIndex;
    bool IsContainerSet() const
    {
        return m_pAux != 0;
    }
    FnvContBase* GetMyCont() const
    {
        return m_pAux ? m_pAux->GetCont() : 0;
    }
    unsigned int FUN_00b2ab50();
};

// @fnv 0x00b2ab50
unsigned int FnvVecIter::FUN_00b2ab50()
{
    if (!(IsContainerSet()))
        FUN_00ec7c56();
    if (!(m_uiEdgeIndex < ((FnvCont*)GetMyCont())->m_iElementCount))
        FUN_00ec7c56();
    return m_uiEdgeIndex;
}

void __cdecl InvalidParameterNoInfoC2();
struct ContainerBaseAuxB9F1
{
};
class AuxContB9F1
{
  public:
    const ContainerBaseAuxB9F1* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxB9F1* _Mycontainer;
};
class IteratorBaseAuxB9F1
{
  public:
    const ContainerBaseAuxB9F1* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContB9F1* _Myaux;
};
struct ElemB9F1
{
    int unk00;
};
struct VectorB9F1 : public ContainerBaseAuxB9F1
{
    AuxContB9F1* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemB9F1* _Myfirst;
    ElemB9F1* _Mylast;
    ElemB9F1* _Myend;
};
class FUN_00b2abc0_It : public IteratorBaseAuxB9F1
{
  public:
    FUN_00b2abc0_It& FUN_00b2abc0();
    ElemB9F1* _Myptr;
};

// @fnv 0x00b2abc0
FUN_00b2abc0_It& FUN_00b2abc0_It::FUN_00b2abc0()
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoC2();
    if (!(_Myptr < ((VectorB9F1*)this->_Getmycont())->_Mylast))
        InvalidParameterNoInfoC2();
    ++_Myptr;
    return *this;
}

namespace fnv_00b2df90 {
namespace vecb2d {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct VcSecureTag
{
};
struct VcStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline VcSecureTag VcCharTraitsCat()
{
    VcSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct VcTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, VcSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, VcCharTraitsCat());
    }
};
struct VcCharAlloc
{
    void deallocate(char* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
};
struct VcString
{
    VcCharAlloc _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    ~VcString()
    {
        _Tidy(true, 0);
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        VcStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    void _Tidy(bool _Built, unsigned int _Newsize)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                VcTraitsHelper::copy_s<VcStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
};
struct VcElem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    VcString kName;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
};
struct VcContainer;
struct VcProxy
{
    const VcContainer* _Mycontainer;
    const VcContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct VcContainer
{
    VcProxy* _Myownedaux;
};
struct VcIterBase
{
    VcProxy* _Myaux;
    VcIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool operator!=(const VcIterBase& _Right) const;
    bool _Same_container(const VcIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    const VcContainer* _Getmycont() const
    {
        return _Myaux == 0 ? 0 : _Myaux->_Getmycont();
    }
    void _Set_container(const VcContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
struct VcVector;
struct VcConstIterator : VcIterBase
{
    VcElem* _Myptr;
    VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector);
    VcConstIterator& operator+=(int _Off);
    int operator-(const VcConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct VcIterator : VcConstIterator
{
    VcIterator(VcElem* _Ptr, const VcContainer* _Pvector) : VcConstIterator(_Ptr, _Pvector)
    {}
    VcIterator& operator+=(int _Off)
    {
        (*(VcConstIterator*)this) += _Off;
        return *this;
    }
    VcIterator operator+(int _Off) const
    {
        VcIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VcNonscalarTag
{
};
inline VcNonscalarTag VcPtrCat(VcElem*&, VcElem*&)
{
    VcNonscalarTag _Cat;
    return _Cat;
}
struct VcInputTag
{
};
struct VcForwardTag : VcInputTag
{
};
struct VcBidiTag : VcForwardTag
{
};
struct VcRandomTag : VcBidiTag
{
};
struct VcRangeCheckedTag
{
};
template <class I1, class I2> inline VcRandomTag VcIterRandom(const I1&, const I2&)
{
    VcRandomTag _Cat;
    return _Cat;
}
template <class T1, class T2> inline VcNonscalarTag VcPtrCatC(T1&, T2&)
{
    VcNonscalarTag _Cat;
    return _Cat;
}
template <class I> inline I VcCheckedBase(const I& _It)
{
    I _Base = _It;
    return _Base;
}
inline VcElem* VcCopyOpt(VcElem* _First, VcElem* _Last, VcElem* _Dest, VcForwardTag, VcNonscalarTag, VcRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
inline VcElem* VcCopyOpt(VcElem* _First, VcElem* _Last, VcElem* _Dest, VcRandomTag, VcNonscalarTag, VcRangeCheckedTag)
{
    VcElem* _Result = _Dest + (_Last - _First);
    VcCopyOpt(_First, _Last, VcCheckedBase(_Dest), VcForwardTag(), VcNonscalarTag(), VcRangeCheckedTag());
    return _Result;
}
template <class _InIt, class _OutIt> inline _OutIt FUN_00b2e3f0(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return VcCopyOpt(VcCheckedBase(_First), VcCheckedBase(_Last), _Dest, VcIterRandom(_First, _Dest),
                     VcPtrCatC(_First, _Dest), VcRangeCheckedTag());
}
struct VcAlloc
{
    int unk00;
    void destroy(VcElem* _Ptr)
    {
        _Ptr->~VcElem();
    }
};
inline void VcDestroyRange(VcElem* _First, VcElem* _Last, VcAlloc& _Al, VcNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
inline void VcDestroyRange(VcElem* _First, VcElem* _Last, VcAlloc& _Al)
{
    VcDestroyRange(_First, _Last, _Al, VcPtrCat(_First, _Last));
}
struct VcVector : VcContainer
{
    int _Alaux;
    VcAlloc _Alval;
    VcElem* _Myfirst;
    VcElem* _Mylast;
    VcElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    VcIterator begin()
    {
        return VcIterator(_Myfirst, this);
    }
    VcIterator end()
    {
        return VcIterator(_Mylast, this);
    }
    VcIterator _Make_iter(VcConstIterator _Where) const
    {
        return VcIterator(_Where._Myptr, this);
    }
    void _Destroy(VcElem* _First, VcElem* _Last)
    {
        VcDestroyRange(_First, _Last, _Alval);
    }
    VcIterator erase(VcConstIterator _First_arg, VcConstIterator _Last_arg)
    {
        VcIterator _First = _Make_iter(_First_arg);
        VcIterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            VcElem* _Ptr = FUN_00b2e3f0(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void FUN_00b2df90();
};
inline VcConstIterator::VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((VcVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((VcVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
inline VcConstIterator& VcConstIterator::operator+=(int _Off)
{
    if (!this->_Has_container())
        FUN_00ec7c56();
    if (!(_Myptr + _Off <= ((VcVector*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VcVector*)this->_Getmycont())->_Myfirst))
        FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}
}
using namespace vecb2d;

// @fnv 0x00b2df90
void VcVector::FUN_00b2df90()
{
    erase(begin(), end());
}
}  // namespace fnv_00b2df90

void __cdecl InvalidParameterNoInfoXC1000();
struct ContainerBaseAuxXC1000
{
};
class AuxContXC1000
{
  public:
    const ContainerBaseAuxXC1000* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxXC1000* _Mycontainer;
};
class IteratorBaseAuxXC1000
{
  public:
    const ContainerBaseAuxXC1000* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContXC1000* _Myaux;
};
struct ElemXC1000
{
    int unk00;
};
struct VectorXC1000 : public ContainerBaseAuxXC1000
{
    AuxContXC1000* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemXC1000* _Myfirst;
    ElemXC1000* _Mylast;
    ElemXC1000* _Myend;
};
class FUN_00b2e330_It : public IteratorBaseAuxXC1000
{
  public:
    FUN_00b2e330_It& FUN_00b2e330(int _Off);
    ElemXC1000* _Myptr;
};

// @fnv 0x00b2e330
FUN_00b2e330_It& FUN_00b2e330_It::FUN_00b2e330(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoXC1000();
    if (!(_Myptr + _Off <= ((VectorXC1000*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorXC1000*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoXC1000();
    _Myptr += _Off;
    return *this;
}

// Supplied other-agent string helper model reused with credit; new record copy below.
namespace record_model {
extern const unsigned int DAT_010173f0;
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
        AssignSubstring(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    BxString& assign(const BxString& other)
    {
        return AssignSubstring(other, 0, DAT_010173f0);
    }
    BxString& operator=(const BxString& other)
    {
        BxString* receiver = this;
        return receiver->assign(other);
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
    BxString& AssignSubstring(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
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
            return AssignSubstring(*this, _Ptr - _Myptr(), _Count);
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

struct Point3
{
    float x, y, z;
};
struct FUN_00b2e680
{
    unsigned char flag;
    Point3 position;
    float value;
    BxString name;
    Point3 first, second, third;
};
typedef char FUN_00b2e680SizeCheck[(sizeof(FUN_00b2e680) == 0x54) ? 1 : -1];
struct CheckedRange
{
};
struct NonScalar
{
};
struct InputCategory
{
};
struct ForwardCategory : InputCategory
{
};
struct Unchanged
{
};
template <class I> inline I base(I& iterator, Unchanged)
{
    return iterator;
}
template <class I> inline I base(I& iterator)
{
    Unchanged tag;
    return base(iterator, tag);
}
template <class I, class O, class C> inline O copyLoop(I _First, I _Last, O _Dest, C, NonScalar, CheckedRange)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return _Dest;
}
}
// @fnv 0x00b2e500
record_model::FUN_00b2e680* __cdecl FUN_00b2e500(record_model::FUN_00b2e680* _First, record_model::FUN_00b2e680* _Last,
                                                 record_model::FUN_00b2e680* _Dest)
{
    record_model::FUN_00b2e680* _Result = _Dest + (_Last - _First);
    record_model::copyLoop(_First, _Last, record_model::base(_Dest), record_model::ForwardCategory(),
                           record_model::NonScalar(), record_model::CheckedRange());
    return _Result;
}

void FormHeap_Free(void* p);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
struct StrY
{
    char b[0x1c];
    void FUN_0044a730(bool b, unsigned n);
};
struct FUN_00b2e740
{
    char a[0x14];
    StrY s;
    char b[0x24];
    FUN_00b2e740(const FUN_00b2e740& o);
};
inline void Del(FUN_00b2e740* p, unsigned int f)
{
    StrY* q = &p->s;
    q->FUN_0044a730(true, 0);
    if (f & 1)
        FormHeap_Free(p);
}
inline void DeadX()
{
    int x[11];
}
inline void Construct(FUN_00b2e740* p, const FUN_00b2e740& v)
{
    void* vp = p;
    ::new (vp) FUN_00b2e740(v);
    DeadX();
}
// @fnv 0x00b2e570
FUN_00b2e740* FUN_00b2e570(FUN_00b2e740* first, FUN_00b2e740* last, FUN_00b2e740* dest)
{
    FUN_00b2e740* next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            Construct(dest, *first);
    }
    catch (...)
    {
        for (; next != dest; ++next)
            Del(next, 0);
        throw;
    }
    return dest;
}

namespace fnv_00b30f80 {
namespace ptb30 {
void FUN_00ec7c56();
struct PtVector
{
    int unk00;
    int unk04;
    int unk08;
    float* _Myfirst;
    float* _Mylast;
    float* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    float& operator[](unsigned int _Pos)
    {
        if (!(_Pos < size()))
        {
            FUN_00ec7c56();
        }
        return *(_Myfirst + _Pos);
    }
};
struct PtOwner
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
    PtVector kPoints;
    float* FUN_00b30f80(int index);
};
}
using namespace ptb30;

// @fnv 0x00b30f80
float* PtOwner::FUN_00b30f80(int index)
{
    return &kPoints[0] + index * 3;
}
}  // namespace fnv_00b30f80

namespace vecdb314 {
struct VdNonscalarTag
{
};
struct VdScalarTag
{
};
template <class T> inline VdNonscalarTag VdPtrCat(T*&, T*&)
{
    VdNonscalarTag _Cat;
    return _Cat;
}
inline VdScalarTag VdPtrCat(unsigned short*&, unsigned short*&)
{
    VdScalarTag _Cat;
    return _Cat;
}
template <class T> inline void VdDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct VdAlloc
{
    typedef T* pointer;
    void deallocate(T* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(T* _Ptr)
    {
        VdDestroyOne(_Ptr);
    }
};
template <class A>
inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, VdNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
template <class A> inline void VdDestroyRange(typename A::pointer, typename A::pointer, A&, VdScalarTag)
{}
template <class A> inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    VdDestroyRange<A>(_First, _Last, _Al, VdPtrCat(_First, _Last));
}
struct VdAuxCont
{
    int unk00;
};
struct VdAuxBase
{
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
template <class T> struct VdVector : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    ~VdVector()
    {
        _Tidy();
    }
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
template <class T> struct VdVectorImpl : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
}
using namespace vecdb314;

namespace vecdb314 {
struct VdElemV : public VdVector<unsigned short>
{
};
}
struct FUN_00b31480 : public VdVectorImpl<VdElemV>
{
    ~FUN_00b31480();
};

// @fnv 0x00b31480
FUN_00b31480::~FUN_00b31480()
{
    _Tidy();
}

namespace fnv_00b319e0 {
namespace vecb319 {
void FUN_00ec7c56();
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);

struct VdNonscalarTag
{
};
template <class T> inline VdNonscalarTag VdPtrCat(T*&, T*&)
{
    VdNonscalarTag _Cat;
    return _Cat;
}
template <class T> inline void VdDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct VdAlloc
{
    typedef T* pointer;
    void deallocate(T* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(T* _Ptr)
    {
        VdDestroyOne(_Ptr);
    }
};
template <class A>
inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, VdNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
struct VdScalarTag
{
};
inline VdScalarTag VdPtrCat(unsigned short*&, unsigned short*&)
{
    VdScalarTag _Cat;
    return _Cat;
}
template <class A> inline void VdDestroyRange(typename A::pointer, typename A::pointer, A&, VdScalarTag)
{}
template <class A> inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    VdDestroyRange<A>(_First, _Last, _Al, VdPtrCat(_First, _Last));
}
struct VdAuxCont
{
    int unk00;
};
struct VdAuxBase
{
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
template <class T> struct VdVector : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    ~VdVector()
    {
        _Tidy();
    }
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct VsSecureTag
{
};
struct VsStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline VsSecureTag VsCharTraitsCat()
{
    VsSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct VsTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, VsSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, VsCharTraitsCat());
    }
};
struct VsCharAlloc
{
    void deallocate(char* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
};
struct VsString
{
    VsCharAlloc _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    ~VsString()
    {
        _Tidy(true, 0);
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        VsStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    void _Tidy(bool _Built, unsigned int _Newsize)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                VsTraitsHelper::copy_s<VsStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
};

struct VcElem : public VdVector<unsigned short>
{
};
struct VcContainer;
struct VcProxy
{
    const VcContainer* _Mycontainer;
    const VcContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct VcContainer
{
    VcProxy* _Myownedaux;
};
struct VcIterBase
{
    VcProxy* _Myaux;
    VcIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool operator!=(const VcIterBase& _Right) const;
    bool _Same_container(const VcIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    const VcContainer* _Getmycont() const
    {
        return _Myaux == 0 ? 0 : _Myaux->_Getmycont();
    }
    void _Set_container(const VcContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
struct VcVector;
struct VcConstIterator : VcIterBase
{
    VcElem* _Myptr;
    VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector);
    VcConstIterator& operator+=(int _Off);
    int operator-(const VcConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct VcIterator : VcConstIterator
{
    VcIterator(VcElem* _Ptr, const VcContainer* _Pvector) : VcConstIterator(_Ptr, _Pvector)
    {}
    VcIterator& operator+=(int _Off)
    {
        (*(VcConstIterator*)this) += _Off;
        return *this;
    }
    VcIterator operator+(int _Off) const
    {
        VcIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VcNonscalarTag
{
};
inline VcNonscalarTag VcPtrCat(VcElem*&, VcElem*&)
{
    VcNonscalarTag _Cat;
    return _Cat;
}
struct VcInputTag
{
};
struct VcForwardTag : VcInputTag
{
};
struct VcBidiTag : VcForwardTag
{
};
struct VcRandomTag : VcBidiTag
{
};
struct VcRangeCheckedTag
{
};
template <class I1, class I2> inline VcRandomTag VcIterRandom(const I1&, const I2&)
{
    VcRandomTag _Cat;
    return _Cat;
}
template <class T1, class T2> inline VcNonscalarTag VcPtrCatC(T1&, T2&)
{
    VcNonscalarTag _Cat;
    return _Cat;
}
template <class I> inline I VcCheckedBase(const I& _It)
{
    I _Base = _It;
    return _Base;
}
inline VcElem* VcCopyOpt(VcElem* _First, VcElem* _Last, VcElem* _Dest, VcForwardTag, VcNonscalarTag, VcRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
inline VcElem* VcCopyOpt(VcElem* _First, VcElem* _Last, VcElem* _Dest, VcRandomTag, VcNonscalarTag, VcRangeCheckedTag)
{
    VcElem* _Result = _Dest + (_Last - _First);
    VcCopyOpt(_First, _Last, VcCheckedBase(_Dest), VcForwardTag(), VcNonscalarTag(), VcRangeCheckedTag());
    return _Result;
}
template <class _InIt, class _OutIt> inline _OutIt FUN_00b35a90(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return VcCopyOpt(VcCheckedBase(_First), VcCheckedBase(_Last), _Dest, VcIterRandom(_First, _Dest),
                     VcPtrCatC(_First, _Dest), VcRangeCheckedTag());
}
struct VcAlloc
{
    int unk00;
    void destroy(VcElem* _Ptr)
    {
        _Ptr->~VcElem();
    }
};
inline void VcDestroyRange(VcElem* _First, VcElem* _Last, VcAlloc& _Al, VcNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
inline void VcDestroyRange(VcElem* _First, VcElem* _Last, VcAlloc& _Al)
{
    VcDestroyRange(_First, _Last, _Al, VcPtrCat(_First, _Last));
}
struct VcVector : VcContainer
{
    int _Alaux;
    VcAlloc _Alval;
    VcElem* _Myfirst;
    VcElem* _Mylast;
    VcElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    VcIterator begin()
    {
        return VcIterator(_Myfirst, this);
    }
    VcIterator end()
    {
        return VcIterator(_Mylast, this);
    }
    VcIterator _Make_iter(VcConstIterator _Where) const
    {
        return VcIterator(_Where._Myptr, this);
    }
    void _Destroy(VcElem* _First, VcElem* _Last)
    {
        VcDestroyRange(_First, _Last, _Alval);
    }
    VcIterator erase(VcConstIterator _First_arg, VcConstIterator _Last_arg)
    {
        VcIterator _First = _Make_iter(_First_arg);
        VcIterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            VcElem* _Ptr = FUN_00b35a90(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void FUN_00b319e0();
};
inline VcConstIterator::VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((VcVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((VcVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
inline VcConstIterator& VcConstIterator::operator+=(int _Off)
{
    if (!this->_Has_container())
        FUN_00ec7c56();
    if (!(_Myptr + _Off <= ((VcVector*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VcVector*)this->_Getmycont())->_Myfirst))
        FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}
}
using namespace vecb319;

// @fnv 0x00b319e0
void VcVector::FUN_00b319e0()
{
    erase(begin(), end());
}
}  // namespace fnv_00b319e0

void __cdecl FormHeap_Free(void* p);

struct BufferPtr
{
    void* m_pData;
    __forceinline ~BufferPtr()
    {
        void* pData = m_pData;
        FormHeap_Free(pData);
    }
};

struct FUN_00b31c00
{
    BufferPtr m_buf;
    void FUN_00b331c0();
    ~FUN_00b31c00();
};

// @fnv 0x00b31c00
FUN_00b31c00::~FUN_00b31c00()
{
    int aiUnused[14];
    FUN_00b331c0();
}

inline void DA()
{
    int a[8];
}
inline void DB()
{}
inline void DC()
{
    int c[11];
}
typedef int T;
struct ScalarTagQ
{
};
struct RangeTagQ
{
};
struct AlQ
{
    int x;
};
void __cdecl FUN_00ac3450(T* f, unsigned n, const T& v);
inline ScalarTagQ Ptr_cat(T*&, T*&)
{
    ScalarTagQ c;
    return c;
}
inline void Uninit_fill_n(T* f, unsigned n, const T& v, AlQ& al, ScalarTagQ, RangeTagQ)
{
    FUN_00ac3450(f, n, v);
    DA();
}
inline void Unchecked_uninitialized_fill_n(T* f, unsigned n, const T& v, AlQ& al)
{
    Uninit_fill_n(f, n, v, al, Ptr_cat(f, f), RangeTagQ());
    DB();
}
struct PbContainer;
struct PbCIterator
{
    void* owner;
    T* position;
    PbCIterator()
    {}
    PbCIterator(T* p, const PbContainer* c);
};
struct PbIterator : PbCIterator
{
    PbIterator()
    {}
    PbIterator(T* p, const PbContainer* c) : PbCIterator(p, c)
    {}
};
struct PbContainer
{
    void* owner;
    unsigned int unk04;
    AlQ al;
    T* first;
    T* last;
    T* capacity_;
    unsigned int size() const
    {
        return last - first;
    }
    unsigned int capacity() const
    {
        return first == 0 ? 0 : capacity_ - first;
    }
    PbIterator end()
    {
        return PbIterator(last, this);
    }
    T* _Ufill(T* p, unsigned n, const T& v)
    {
        Unchecked_uninitialized_fill_n(p, n, v, al);
        return p + n;
    }
    PbIterator FUN_00b33240(PbCIterator where, const T& v);
    void FUN_00b32210(const T& v);
};
inline PbCIterator::PbCIterator(T* p, const PbContainer* c)
{
    owner = 0;
    if (c == 0 || c->first > p || p > c->last)
        FUN_00ec7c56();
    owner = c->owner;
    position = p;
}
// @fnv 0x00b32210
void PbContainer::FUN_00b32210(const T& v)
{
    if (size() < capacity())
    {
        last = _Ufill(last, 1, v);
    }
    else
        FUN_00b33240(end(), v);
    DC();
}

namespace fnv_00b32410 {
inline void DA()
{
    int a[8];
}
inline void DB()
{}
inline void DC()
{
    int c[11];
}
typedef short T;
struct ScalarTagQ
{
};
struct RangeTagQ
{
};
struct AlQ
{
    int x;
};
void __cdecl FUN_00b36b80(T* f, unsigned n, const T& v);
inline ScalarTagQ Ptr_cat(T*&, T*&)
{
    ScalarTagQ c;
    return c;
}
inline void Uninit_fill_n(T* f, unsigned n, const T& v, AlQ& al, ScalarTagQ, RangeTagQ)
{
    FUN_00b36b80(f, n, v);
    DA();
}
inline void Unchecked_uninitialized_fill_n(T* f, unsigned n, const T& v, AlQ& al)
{
    Uninit_fill_n(f, n, v, al, Ptr_cat(f, f), RangeTagQ());
    DB();
}
struct PbContainer;
struct PbCIterator
{
    void* owner;
    T* position;
    PbCIterator()
    {}
    PbCIterator(T* p, const PbContainer* c);
};
struct PbIterator : PbCIterator
{
    PbIterator()
    {}
    PbIterator(T* p, const PbContainer* c) : PbCIterator(p, c)
    {}
};
struct PbContainer
{
    void* owner;
    unsigned int unk04;
    AlQ al;
    T* first;
    T* last;
    T* capacity_;
    unsigned int size() const
    {
        return last - first;
    }
    unsigned int capacity() const
    {
        return first == 0 ? 0 : capacity_ - first;
    }
    PbIterator end()
    {
        return PbIterator(last, this);
    }
    T* _Ufill(T* p, unsigned n, const T& v)
    {
        Unchecked_uninitialized_fill_n(p, n, v, al);
        return p + n;
    }
    PbIterator FUN_00b339d0(PbCIterator where, const T& v);
    void FUN_00b32410(const T& v);
};
inline PbCIterator::PbCIterator(T* p, const PbContainer* c)
{
    owner = 0;
    if (c == 0 || c->first > p || p > c->last)
        FUN_00ec7c56();
    owner = c->owner;
    position = p;
}
// @fnv 0x00b32410
void PbContainer::FUN_00b32410(const T& v)
{
    if (size() < capacity())
    {
        last = _Ufill(last, 1, v);
    }
    else
        FUN_00b339d0(end(), v);
    DC();
}
}  // namespace fnv_00b32410

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
class FUN_00b32540_Vector : public vectorS<int>
{
  public:
    void FUN_00b32540();
};

// @fnv 0x00b32540
void FUN_00b32540_Vector::FUN_00b32540()
{
    erase(begin(), end());
}

namespace fnv_00b32880 {
inline void FreeQ(void* p)
{
    FormHeap_Free(p);
}
struct VB2Q
{
    void* p;
    ~VB2Q()
    {
        FreeQ(p);
    }
};
struct ElQ : VB2Q
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    ElQ(const ElQ&);
    ~ElQ()
    {
        FUN_00b34d90();
    }
    void FUN_00b34d90();
};
typedef ElQ T;
struct ResizeContainer;
struct ResizeCIterator
{
    void* owner;
    T* position;
    ResizeCIterator()
    {}
    ResizeCIterator(T* p, const ResizeContainer* c);
    ResizeCIterator& __thiscall FUN_00b16890(unsigned int count);
};
struct ResizeIterator : ResizeCIterator
{
    ResizeIterator()
    {}
    ResizeIterator(T* p, const ResizeContainer* c) : ResizeCIterator(p, c)
    {}
    ResizeIterator& operator+=(unsigned int n)
    {
        (*(ResizeCIterator*)this).FUN_00b16890(n);
        return *this;
    }
    ResizeIterator operator+(unsigned int n) const
    {
        ResizeIterator tmp = *this;
        return (tmp += n);
    }
};
struct ResizeContainer
{
    void* owner;
    unsigned int unk04;
    unsigned int unk08;
    T* first;
    T* last;
    T* capacity;
    unsigned int size() const
    {
        return last - first;
    }
    ResizeIterator begin()
    {
        return ResizeIterator(first, this);
    }
    ResizeIterator end()
    {
        return ResizeIterator(last, this);
    }
    void FUN_00b33bd0(ResizeCIterator where, unsigned int count, const T& value);
    ResizeIterator FUN_00b32ad0(ResizeCIterator first, ResizeCIterator last);
    void FUN_00b32880(unsigned int count, T value);
};
inline ResizeCIterator::ResizeCIterator(T* p, const ResizeContainer* c)
{
    owner = 0;
    if (c == 0 || c->first > p || p > c->last)
        FUN_00ec7c56();
    owner = c->owner;
    position = p;
}
inline void Pad24()
{
    int dq[28];
}
// @fnv 0x00b32880
void ResizeContainer::FUN_00b32880(unsigned int count, T value)
{
    if (size() < count)
        FUN_00b33bd0(end(), count - size(), value);
    else if (count < size())
        FUN_00b32ad0(begin() + count, end());
    Pad24();
}
}  // namespace fnv_00b32880

// FUN_00b32ad0: vector<T(0x18 bytes), game allocator>::erase(first, last), checked iterators (VC9 _SECURE_SCL)
struct Elem18
{
    int f00, f04, f08, f0c, f10, f14;
};

struct Vec18;

static __forceinline void Dead12()
{
    int aiD[12];
}

struct VecIterBase
{
    void* m_proxy;
    VecIterBase() : m_proxy(0)
    {}
    inline void SetContainer(const Vec18* cont);
};

struct VecConstIter18 : VecIterBase
{
    Elem18* m_ptr;
    VecConstIter18()
    {}
    inline VecConstIter18(Elem18* p, const Vec18* v);
    bool FUN_00b16830(const VecConstIter18& other) const;
};

struct VecIter18 : VecConstIter18
{
    VecIter18()
    {}
    VecIter18(Elem18* p, const Vec18* v) : VecConstIter18(p, v)
    {}
};

extern "C" Elem18* __cdecl FUN_00b35a90(Elem18* first, Elem18* last, Elem18* dest);

struct Vec18
{
    void* m_proxy;
    int m_04;
    int m_08;
    Elem18* m_pHeadNode;
    Elem18* m_last;
    void FUN_00b32bb0(Elem18* first, Elem18* last);
    VecIter18 MakeIter(VecConstIter18 where) const
    {
        Dead12();
        return VecIter18(where.m_ptr, this);
    }
    VecIter18 FUN_00b32ad0(VecConstIter18 firstArg, VecConstIter18 lastArg);
};

inline void VecIterBase::SetContainer(const Vec18* cont)
{
    m_proxy = cont->m_proxy;
}

inline VecConstIter18::VecConstIter18(Elem18* p, const Vec18* v)
{
    if (v == 0 || v->m_pHeadNode > p || p > v->m_last)
    {
        FUN_00ec7c56();
    }
    SetContainer(v);
    m_ptr = p;
}

// @fnv 0x00b32ad0
VecIter18 Vec18::FUN_00b32ad0(VecConstIter18 firstArg, VecConstIter18 lastArg)
{
    VecIter18 first = MakeIter(firstArg);
    VecIter18 last = MakeIter(lastArg);
    if (first.FUN_00b16830(last))
    {
        Elem18* ptr = FUN_00b35a90(last.m_ptr, m_last, first.m_ptr);
        FUN_00b32bb0(ptr, m_last);
        m_last = ptr;
    }
    return first;
}

namespace fnv_00b33370 {
namespace vecdb333 {
struct VdNonscalarTag
{
};
struct VdScalarTag
{
};
template <class T> inline VdNonscalarTag VdPtrCat(T*&, T*&)
{
    VdNonscalarTag _Cat;
    return _Cat;
}
inline VdScalarTag VdPtrCat(unsigned int*&, unsigned int*&)
{
    VdScalarTag _Cat;
    return _Cat;
}
template <class T> inline void VdDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct VdAlloc
{
    typedef T* pointer;
    void deallocate(T* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(T* _Ptr)
    {
        VdDestroyOne(_Ptr);
    }
};
template <class A>
inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, VdNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
template <class A> inline void VdDestroyRange(typename A::pointer, typename A::pointer, A&, VdScalarTag)
{}
template <class A> inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    VdDestroyRange<A>(_First, _Last, _Al, VdPtrCat(_First, _Last));
}
struct VdAuxCont
{
    int unk00;
};
struct VdAuxBase
{
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
template <class T> struct VdVector : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    ~VdVector()
    {
        _Tidy();
    }
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
template <class T> struct VdVectorImpl : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
}
using namespace vecdb333;

struct FUN_00b33370 : public VdVectorImpl<unsigned int>
{
    ~FUN_00b33370();
};

// @fnv 0x00b33370
FUN_00b33370::~FUN_00b33370()
{
    _Tidy();
}
}  // namespace fnv_00b33370

namespace fnv_00b33780 {
namespace vecdb337 {
struct VdNonscalarTag
{
};
struct VdScalarTag
{
};
template <class T> inline VdNonscalarTag VdPtrCat(T*&, T*&)
{
    VdNonscalarTag _Cat;
    return _Cat;
}
inline VdScalarTag VdPtrCat(unsigned short*&, unsigned short*&)
{
    VdScalarTag _Cat;
    return _Cat;
}
template <class T> inline void VdDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct VdAlloc
{
    typedef T* pointer;
    void deallocate(T* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(T* _Ptr)
    {
        VdDestroyOne(_Ptr);
    }
};
template <class A>
inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, VdNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
template <class A> inline void VdDestroyRange(typename A::pointer, typename A::pointer, A&, VdScalarTag)
{}
template <class A> inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    VdDestroyRange<A>(_First, _Last, _Al, VdPtrCat(_First, _Last));
}
struct VdAuxCont
{
    int unk00;
};
struct VdAuxBase
{
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
template <class T> struct VdVector : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    ~VdVector()
    {
        _Tidy();
    }
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
template <class T> struct VdVectorImpl : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
}
using namespace vecdb337;

struct FUN_00b33780 : public VdVectorImpl<unsigned short>
{
    ~FUN_00b33780();
};

// @fnv 0x00b33780
FUN_00b33780::~FUN_00b33780()
{
    _Tidy();
}
}  // namespace fnv_00b33780

typedef short ElQ_aceeb0;
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
    CItQ_aceeb0& FUN_00b359d0(int _Off);
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
        FUN_00b359d0(_Off);
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
    void FUN_00b34e10(CItQ_aceeb0 _Where, unsigned int _Count, const ElQ_aceeb0& _Val);
    ItQ_aceeb0 end()
    {
        return ItQ_aceeb0(_Mylast, this);
    }
    ElQ_aceeb0* _Ufill(ElQ_aceeb0* _Ptr, unsigned int _Count, const ElQ_aceeb0& _Val)
    {
        UFillN_aceeb0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_aceeb0 FUN_00b339d0(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val);
};
inline CItQ_aceeb0::CItQ_aceeb0(ElQ_aceeb0* _Ptr, const VecQ_aceeb0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b339d0
ItQ_aceeb0 VecQ_aceeb0::FUN_00b339d0(CItQ_aceeb0 _Where, const ElQ_aceeb0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b34e10(_Where, 1, _Val);
    return begin() + _Off;
}

namespace fnv_00b33bd0 {
struct MoveCatQ
{
};
struct TagQ
{
};
struct PtrCatQ
{
};
struct VBQ
{
    void* p;
    ~VBQ();
};
inline void FreeQ(void* p);
struct ElQ : VBQ
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    ElQ(const ElQ&);
    ElQ& operator=(const ElQ&);
    ~ElQ()
    {
        Tidy();
    }
    void Tidy();
    void DelQ(unsigned f)
    {
        this->~ElQ();
        if (f & 1)
            FreeQ(this);
    }
};
inline void FreeQ(void* p);
struct VB2Q
{
    void* p;
    ~VB2Q()
    {
        FreeQ(p);
    }
};
struct El2Q : VB2Q
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    El2Q(const ElQ&);
    ~El2Q()
    {
        Tidy();
    }
    void Tidy();
};
struct AlQ
{
    unsigned max_size() const
    {
        unsigned _Count = (unsigned)(-1) / sizeof(ElQ);
        return (0 < _Count ? _Count : 1);
    }
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b23aa0(unsigned n, ElQ* p);
ElQ* __cdecl FUN_00b36bf0(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ c, TagQ t);
ElQ* __cdecl FUN_00b35ce0(ElQ* f, ElQ* l, ElQ* d);
void __cdecl FUN_00b360a0(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
void __cdecl FUN_00b0fb80();
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead17()
{
    int a[17];
}
inline void Dead7()
{
    int a[7];
}
inline void Dead10()
{
    int a[10];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead8()
{
    int a[8];
}
inline void Dead9()
{
    int a[9];
}
inline void Dead11()
{
    int a[11];
}
inline void Dead8b()
{
    int a[8];
}
inline void Dead13()
{
    int a[13];
}
inline void Dead16()
{
    int a[16];
}
inline MoveCatQ Move_cat(ElQ*&)
{
    MoveCatQ c;
    return c;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b36bf0(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b360a0(f, n, v, al, Ptr_cat(f, f), TagQ());
}
__forceinline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    int aP[6];
    for (; f != l; ++f)
        al.destroy(f);
}
__forceinline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
{
    Destroy_range2(f, l, al, Ptr_cat(f, l));
}
inline void Fill(ElQ* f, ElQ* l, const ElQ& v)
{
    for (; f != l; ++f)
        *f = v;
}
inline void Unchecked_fill(ElQ* f, ElQ* l, const ElQ& v)
{
    Fill(Checked_base2(f), Checked_base2(l), v);
}
struct CItQ
{
    void* m_cont;
    ElQ* m_ptr;
};
struct VecQ
{
    int m_iWordAt00;
    int m_iWordAt04;
    AlQ m_al;
    ElQ* m_pHeadNode;
    ElQ* m_last;
    ElQ* m_kRayEnd;
    unsigned capacity() const
    {
        return m_pHeadNode == 0 ? 0 : m_kRayEnd - m_pHeadNode;
    }
    unsigned size() const
    {
        return m_last - m_pHeadNode;
    }
    unsigned max_size() const
    {
        return m_al.max_size();
    }
    ElQ* _Umove(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_move(f, l, p, m_al);
    }
    ElQ* _Ufill(ElQ* p, unsigned n, const ElQ& v)
    {
        Unchecked_uninitialized_fill_n(p, n, v, m_al);
        return p + n;
    }
    void FUN_00b32bb0(ElQ* f, ElQ* l);
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b33bd0(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b33bd0
void VecQ::FUN_00b33bd0(CItQ _Where, unsigned _Count, const ElQ& _Val)
{
    unsigned _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        Dead17();
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ElQ* _Newvec = FUN_00b23aa0(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            FUN_00b32bb0(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            FUN_00b32bb0(m_pHeadNode, m_last);
            Dead12();
            m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
        }
        m_kRayEnd = _Newvec + _Capacity;
        m_last = _Newvec + _Count;
        m_pHeadNode = _Newvec;
    }
    else if ((unsigned)(m_last - _Where.m_ptr) < _Count)
    {
        ElQ _Tmp = _Val;
        _Umove(_Where.m_ptr, m_last, _Where.m_ptr + _Count);
        try
        {
            _Ufill(m_last, _Count - (m_last - _Where.m_ptr), _Tmp);
        }
        catch (...)
        {
            _DestroyI(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        El2Q _Tmp = _Val;
        ElQ* _Oldend = m_last;
        Dead7();
        m_last = _Umove(_Oldend - _Count, _Oldend, m_last);
        FUN_00b35ce0(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead11();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, *(const ElQ*)&_Tmp);
        Dead7();
    }
}
}  // namespace fnv_00b33bd0

namespace buyUShort {
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

typedef unsigned short BxElem;
struct BxAlloc
{
    BxElem* allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (BxElem*)0);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(BxElem);
        return 0 < _Count ? _Count : 1;
    }
};
struct BxVector
{
    int unk00;
    int unk04;
    BxAlloc _Alval;
    BxElem* _Myfirst;
    BxElem* _Mylast;
    BxElem* _Myend;
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool FUN_00b34cd0(unsigned int _Capacity);
};
}
using namespace buyUShort;

// @fnv 0x00b34cd0
bool BxVector::FUN_00b34cd0(unsigned int _Capacity)
{
    _Myfirst = 0, _Mylast = 0, _Myend = 0;
    if (_Capacity == 0)
    {
        return false;
    }
    else if (max_size() < _Capacity)
    {
        _Xlen();
    }
    else
    {
        _Myfirst = _Alval.allocate(_Capacity);
        _Mylast = _Myfirst;
        _Myend = _Myfirst + _Capacity;
    }
    return true;
}

// Independent helper model informed by the supplied VC9 matching notes.
extern "C" int __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);
namespace backward_model {
struct CheckedRange
{
};
struct ScalarPointer
{
};
struct CopyMove
{
};
struct SameBase
{
};
struct InputCategory
{
};
struct ForwardCategory : InputCategory
{
};
struct BidirectionalCategory : ForwardCategory
{
};
struct RandomCategory : BidirectionalCategory
{
};
template <class I> inline I base(I& iterator, SameBase)
{
    return iterator;
}
template <class I> inline I base(const I& iterator, SameBase)
{
    return iterator;
}
template <class I> inline I base(I& iterator)
{
    SameBase tag;
    return base(iterator, tag);
}
template <class I> inline I base(const I& iterator)
{
    SameBase tag;
    return base(iterator, tag);
}
template <class I, class O> inline RandomCategory category(const I&, const O&)
{
    RandomCategory tag;
    return tag;
}
template <class I> inline CopyMove movement(const I&)
{
    CopyMove tag;
    return tag;
}
template <class I, class O> inline ScalarPointer pointers(I&, O&)
{
    ScalarPointer tag;
    return tag;
}
template <class I, class O, class C> inline O copyForward(I first, I last, O end, C, ScalarPointer, CheckedRange)
{
    int _Off = last - first;
    O _Result = end + _Off;
    if (_Off > 0)
        FUN_00ec7ce3(end, _Off * sizeof(*first), first, _Off * sizeof(*first));
    return _Result;
}
template <class I, class O, class C, class M> inline O moveBack(I first, I last, O end, C order, M, CheckedRange)
{
    return copyForward(first, last, end, order, pointers(first, end), CheckedRange());
}
}
// @fnv 0x00b35c30
unsigned short* __cdecl FUN_00b35c30(unsigned short* first, unsigned short* last, unsigned short* end)
{
    using namespace backward_model;
    return copyForward(base(first), base(last), end, category(first, end), pointers(first, end), CheckedRange());
}

namespace fill_model {
struct RangeTag
{
};
struct ScalarTag
{
};
struct SameTag
{
};
struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
template <class I> inline ScalarTag pointers(const I&, const I&)
{
    ScalarTag tag;
    return tag;
}
template <class I> inline RandomTag category(const I&)
{
    RandomTag tag;
    return tag;
}
template <class I> inline I base(I& it, SameTag)
{
    return it;
}
template <class I> inline I base(I& it)
{
    SameTag tag;
    return base(it, tag);
}
template <class I, class N, class V> inline void fillLoop(I first, N count, const V& value, RangeTag)
{
    for (; 0 < count; --count, ++first)
        *first = value;
}
template <class I, class N, class V> inline void fillChecked(I first, N count, const V& value, RandomTag, RangeTag)
{
    I last = first + count;
    fillLoop(base(first), count, value, RangeTag());
}
template <class I, class N, class V> inline void FUN_00b36b10(I first, N count, const V& value)
{
    fillChecked(first, count, value, category(first), RangeTag());
}
template <class I, class N, class V, class A>
inline void initFill(I first, N count, const V& value, A&, ScalarTag, RangeTag)
{
    FUN_00b36b10(first, count, value);
}
}
// @fnv 0x00b35ca0
void __cdecl FUN_00b35ca0(unsigned int* first, unsigned count, const unsigned int& value, void* allocator)
{
    using namespace fill_model;
    initFill(first, count, value, allocator, pointers(first, first), RangeTag());
}

namespace fnv_00b35ce0 {
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

struct AsObj;
struct AsHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
void FUN_00ec7c56();
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct AsNonscalarTag
{
};
struct AsScalarTag
{
};
struct AsRangeCheckedTag
{
};
struct AsInputTag
{
};
struct AsForwardTag : AsInputTag
{
};
struct AsBidiTag : AsForwardTag
{
};
struct AsRandomTag : AsBidiTag
{
};
template <class T1, class T2> struct AsPtrCatHelper
{
    typedef AsNonscalarTag _Ptr_cat;
};
template <class T> struct AsPtrCatHelper<T**, T**>
{
    typedef AsScalarTag _Ptr_cat;
};
template <> struct AsPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef AsScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename AsPtrCatHelper<T1, T2>::_Ptr_cat AsPtrCat(T1&, T2&)
{
    typename AsPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class I1, class I2> inline AsRandomTag AsIterRandom(const I1&, const I2&)
{
    AsRandomTag _Cat;
    return _Cat;
}
struct AsUnchangedTag
{
};
template <class I> inline I AsCheckedBase(const I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(const I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I> inline I AsCheckedBase(I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I, class O, class C> inline O AsCopyOpt(I _First, I _Last, O _Dest, C, AsScalarTag, AsRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    }
    return _Result;
}
template <class I, class O> inline O AsUncheckedCopy(I _First, I _Last, O _Dest)
{
    return AsCopyOpt(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsIterRandom(_First, _Dest),
                     AsPtrCat(_First, _Dest), AsRangeCheckedTag());
}
template <class T1, class T2> inline T2 AsUninitCopy(T1 _First, T1 _Last, T2 _Dest, AsScalarTag, AsRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    T2 _Result = _Dest + _Count;
    if (_Count > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    }
    return _Result;
}
template <class I, class F, class A> inline F AsUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return AsUninitCopy(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsPtrCat(_First, _Dest),
                        AsRangeCheckedTag());
}
template <class A> inline void AsDestroyRange(typename A::pointer, typename A::pointer, A&, AsScalarTag)
{}
template <class A> inline void AsDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    AsDestroyRange(_First, _Last, _Al, AsPtrCat(_First, _Last));
}
template <class T> inline T* AsHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(_Count * sizeof(T));
}
template <class T> struct AsAlloc
{
    typedef T* pointer;
    AsAlloc() throw()
    {}
    AsAlloc(const AsAlloc<T>&) throw()
    {}
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    pointer allocate(unsigned int _Count)
    {
        return AsHeapAllocate(_Count, (pointer)0);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
template <class T> inline bool operator==(const AsAlloc<T>&, const AsAlloc<T>&)
{
    return true;
}
struct AsContainer;
struct AsProxy
{
    const AsContainer* _Mycontainer;
    const AsContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
template <class T> inline void ModelSwap(T& _Left, T& _Right)
{
    if (&_Left != &_Right)
    {
        T _Tmp = _Left;
        _Left = _Right;
        _Right = _Tmp;
    }
}
struct AsContainer
{
    AsProxy* _Myownedaux;
    void _Orphan_all() const
    {}
    void _Swap_aux(AsContainer& _Right)
    {
        ModelSwap(_Myownedaux, _Right._Myownedaux);
        ModelSwap(*_Myownedaux, *_Right._Myownedaux);
    }
};
struct AsIterBase
{
    AsProxy* _Myaux;
    AsIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const AsIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool operator!=(const AsIterBase& _Right) const;
    void _Set_container(const AsContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
typedef unsigned short AsElem;
struct AsVector;
struct AsConstIterator : AsIterBase
{
    AsElem* _Myptr;
    AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector);
};
struct AsIterator : AsConstIterator
{
    AsIterator(AsElem* _Ptr, const AsContainer* _Pvector) : AsConstIterator(_Ptr, _Pvector)
    {}
};
struct AsUnwrapTag
{
};
inline AsElem* AsCheckedBase(AsConstIterator& iterator, AsUnwrapTag)
{
    return iterator._Myptr;
}
inline AsElem* AsCheckedBase(const AsConstIterator& iterator, AsUnwrapTag)
{
    return iterator._Myptr;
}
inline AsElem* AsCheckedBase(AsConstIterator& iterator)
{
    AsUnwrapTag tag;
    return AsCheckedBase(iterator, tag);
}
inline AsElem* AsCheckedBase(const AsConstIterator& iterator)
{
    AsUnwrapTag tag;
    return AsCheckedBase(iterator, tag);
}
template <> struct AsPtrCatHelper<AsConstIterator, AsElem*>
{
    typedef AsScalarTag _Ptr_cat;
};
struct AsVector : AsContainer
{
    int _Alaux;
    AsAlloc<AsElem> _Alval;
    AsElem* _Myfirst;
    AsElem* _Mylast;
    AsElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    AsIterator begin()
    {
        return AsIterator(_Myfirst, this);
    }
    AsIterator end()
    {
        return AsIterator(_Mylast, this);
    }
    AsConstIterator begin() const
    {
        return AsConstIterator(_Myfirst, this);
    }
    AsConstIterator end() const
    {
        return AsConstIterator(_Mylast, this);
    }
    AsIterator _Make_iter(AsConstIterator _Where) const
    {
        return AsIterator(_Where._Myptr, this);
    }
    void _Destroy(AsElem* _First, AsElem* _Last)
    {
        AsDestroyRange(_First, _Last, _Alval);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    AsIterator erase(AsConstIterator _First_arg, AsConstIterator _Last_arg)
    {
        AsIterator _First = _Make_iter(_First_arg);
        AsIterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            AsElem* _Ptr = AsUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = _Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    template <class I> AsElem* _Ucopy(I _First, I _Last, AsElem* _Ptr)
    {
        return AsUncheckedUninitCopy(_First, _Last, _Ptr, _Alval);
    }
    AsVector& FUN_00b36600(const AsVector& _Right);
    AsVector(const AsVector&);
    ~AsVector();
    void _Tidy();
    void FUN_00b37190(AsVector&);
};
inline AsConstIterator::AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((AsVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((AsVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
}
using namespace asgnb36;

inline AsVector& AsVector::FUN_00b36600(const AsVector& _Right)
{
    if (this != &_Right)
    {
        this->_Orphan_all();
        if (_Right.size() == 0)
        {
            clear();
        }
        else if (_Right.size() <= size())
        {
            AsElem* _Ptr = AsUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Myfirst + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            AsElem* _Ptr = _Right._Myfirst + size();
            AsUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
            _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (_Buy(_Right.size()))
            {
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
    }
    return *this;
}

namespace asgnb36 {
inline AsVector::AsVector(const AsVector& _Right) : AsContainer(_Right), _Alaux(_Right._Alaux), _Alval(_Right._Alval)
{
    if (_Buy(_Right.size()))
    {
        try
        {
            _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
        }
        catch (...)
        {
            _Tidy();
            throw;
        }
    }
}
inline AsVector::~AsVector()
{
    _Tidy();
}
inline void AsVector::_Tidy()
{
    if (_Myfirst)
    {
        _Destroy(_Myfirst, _Mylast);
        _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
    }
    _Myfirst = 0;
    _Mylast = 0;
    _Myend = 0;
}
inline void AsVector::FUN_00b37190(AsVector& _Right)
{
    AsVector* receiver = this;
    if (receiver == &_Right)
    {
    }
    else if (receiver->_Alval == _Right._Alval)
    {
        receiver->_Swap_aux(_Right);
        ModelSwap(receiver->_Myfirst, _Right._Myfirst);
        ModelSwap(receiver->_Mylast, _Right._Mylast);
        ModelSwap(receiver->_Myend, _Right._Myend);
    }
    else
    {
        receiver->_Swap_aux(_Right);
        AsVector saved(*receiver);
        receiver->FUN_00b36600(_Right);
        _Right.FUN_00b36600(saved);
    }
}
}
namespace backward24 {
struct SwapMove
{
};
template <class I> inline SwapMove movement(const I&)
{
    SwapMove tag;
    return tag;
}
inline void exchange(asgnb36::AsVector& left, asgnb36::AsVector& right)
{
    left.FUN_00b37190(right);
}
template <class T> inline void exchangeAdl(T& left, T& right)
{
    exchange(left, right);
}
template <class I, class O, class C>
inline O moveLoop(I _First, I _Last, O _Dest, C, SwapMove, asgnb36::AsRangeCheckedTag)
{
    while (_First != _Last)
        exchangeAdl(*--_Dest, *--_Last);
    return _Dest;
}
template <class I, class O>
inline O moveChecked(I _First, I _Last, O _Dest, asgnb36::AsRandomTag, SwapMove mode, asgnb36::AsRangeCheckedTag)
{
    O _Result = _Dest - (_Last - _First);
    moveLoop(_First, _Last, asgnb36::AsCheckedBase(_Dest), asgnb36::AsForwardTag(), mode, asgnb36::AsRangeCheckedTag());
    return _Result;
}
}
// @fnv 0x00b35ce0
asgnb36::AsVector* __cdecl FUN_00b35ce0(asgnb36::AsVector* _First, asgnb36::AsVector* _Last, asgnb36::AsVector* _Dest)
{
    return backward24::moveChecked(asgnb36::AsCheckedBase(_First), asgnb36::AsCheckedBase(_Last), _Dest,
                                   asgnb36::AsIterRandom(_First, _Dest), backward24::movement(_Dest),
                                   asgnb36::AsRangeCheckedTag());
}
}  // namespace fnv_00b35ce0

namespace fnv_00b35da0 {
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

struct AsObj;
struct AsHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
void FUN_00ec7c56();
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct AsNonscalarTag
{
};
struct AsScalarTag
{
};
struct AsRangeCheckedTag
{
};
struct AsInputTag
{
};
struct AsForwardTag : AsInputTag
{
};
struct AsBidiTag : AsForwardTag
{
};
struct AsRandomTag : AsBidiTag
{
};
template <class T1, class T2> struct AsPtrCatHelper
{
    typedef AsNonscalarTag _Ptr_cat;
};
template <class T> struct AsPtrCatHelper<T**, T**>
{
    typedef AsScalarTag _Ptr_cat;
};
template <> struct AsPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef AsScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename AsPtrCatHelper<T1, T2>::_Ptr_cat AsPtrCat(T1&, T2&)
{
    typename AsPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class I1, class I2> inline AsRandomTag AsIterRandom(const I1&, const I2&)
{
    AsRandomTag _Cat;
    return _Cat;
}
struct AsUnchangedTag
{
};
template <class I> inline I AsCheckedBase(const I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(const I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I> inline I AsCheckedBase(I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I, class O, class C> inline O AsCopyOpt(I _First, I _Last, O _Dest, C, AsScalarTag, AsRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    }
    return _Result;
}
template <class I, class O> inline O AsUncheckedCopy(I _First, I _Last, O _Dest)
{
    return AsCopyOpt(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsIterRandom(_First, _Dest),
                     AsPtrCat(_First, _Dest), AsRangeCheckedTag());
}
template <class T1, class T2> inline T2 AsUninitCopy(T1 _First, T1 _Last, T2 _Dest, AsScalarTag, AsRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    T2 _Result = _Dest + _Count;
    if (_Count > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    }
    return _Result;
}
template <class I, class F, class A> inline F AsUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return AsUninitCopy(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsPtrCat(_First, _Dest),
                        AsRangeCheckedTag());
}
template <class A> inline void AsDestroyRange(typename A::pointer, typename A::pointer, A&, AsScalarTag)
{}
template <class A> inline void AsDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    AsDestroyRange(_First, _Last, _Al, AsPtrCat(_First, _Last));
}
template <class T> inline T* AsHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(_Count * sizeof(T));
}
template <class T> struct AsAlloc
{
    typedef T* pointer;
    AsAlloc() throw()
    {}
    AsAlloc(const AsAlloc<T>&) throw()
    {}
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    pointer allocate(unsigned int _Count)
    {
        return AsHeapAllocate(_Count, (pointer)0);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
template <class T> inline bool operator==(const AsAlloc<T>&, const AsAlloc<T>&)
{
    return true;
}
struct AsContainer;
struct AsProxy
{
    const AsContainer* _Mycontainer;
    const AsContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
template <class T> inline void ModelSwap(T& _Left, T& _Right)
{
    if (&_Left != &_Right)
    {
        T _Tmp = _Left;
        _Left = _Right;
        _Right = _Tmp;
    }
}
struct AsContainer
{
    AsProxy* _Myownedaux;
    void _Orphan_all() const
    {}
    void _Swap_aux(AsContainer& _Right)
    {
        ModelSwap(_Myownedaux, _Right._Myownedaux);
        ModelSwap(*_Myownedaux, *_Right._Myownedaux);
    }
};
struct AsIterBase
{
    AsProxy* _Myaux;
    AsIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const AsIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool operator!=(const AsIterBase& _Right) const;
    void _Set_container(const AsContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
typedef unsigned short AsElem;
struct AsVector;
struct AsConstIterator : AsIterBase
{
    AsElem* _Myptr;
    AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector);
};
struct AsIterator : AsConstIterator
{
    AsIterator(AsElem* _Ptr, const AsContainer* _Pvector) : AsConstIterator(_Ptr, _Pvector)
    {}
};
struct AsUnwrapTag
{
};
inline AsElem* AsCheckedBase(AsConstIterator& iterator, AsUnwrapTag)
{
    return iterator._Myptr;
}
inline AsElem* AsCheckedBase(const AsConstIterator& iterator, AsUnwrapTag)
{
    return iterator._Myptr;
}
inline AsElem* AsCheckedBase(AsConstIterator& iterator)
{
    AsUnwrapTag tag;
    return AsCheckedBase(iterator, tag);
}
inline AsElem* AsCheckedBase(const AsConstIterator& iterator)
{
    AsUnwrapTag tag;
    return AsCheckedBase(iterator, tag);
}
template <> struct AsPtrCatHelper<AsConstIterator, AsElem*>
{
    typedef AsScalarTag _Ptr_cat;
};
struct AsVector : AsContainer
{
    int _Alaux;
    AsAlloc<AsElem> _Alval;
    AsElem* _Myfirst;
    AsElem* _Mylast;
    AsElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    AsIterator begin()
    {
        return AsIterator(_Myfirst, this);
    }
    AsIterator end()
    {
        return AsIterator(_Mylast, this);
    }
    AsConstIterator begin() const
    {
        return AsConstIterator(_Myfirst, this);
    }
    AsConstIterator end() const
    {
        return AsConstIterator(_Mylast, this);
    }
    AsIterator _Make_iter(AsConstIterator _Where) const
    {
        return AsIterator(_Where._Myptr, this);
    }
    void _Destroy(AsElem* _First, AsElem* _Last)
    {
        AsDestroyRange(_First, _Last, _Alval);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    AsIterator erase(AsConstIterator _First_arg, AsConstIterator _Last_arg)
    {
        AsIterator _First = _Make_iter(_First_arg);
        AsIterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            AsElem* _Ptr = AsUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = _Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    template <class I> AsElem* _Ucopy(I _First, I _Last, AsElem* _Ptr)
    {
        return AsUncheckedUninitCopy(_First, _Last, _Ptr, _Alval);
    }
    AsVector& FUN_00b36600(const AsVector& _Right);
    AsVector(const AsVector&);
    ~AsVector();
    void _Tidy();
    void FUN_00b36f60(AsVector&);
};
inline AsConstIterator::AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((AsVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((AsVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
}
using namespace asgnb36;

inline AsVector& AsVector::FUN_00b36600(const AsVector& _Right)
{
    if (this != &_Right)
    {
        this->_Orphan_all();
        if (_Right.size() == 0)
        {
            clear();
        }
        else if (_Right.size() <= size())
        {
            AsElem* _Ptr = AsUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Myfirst + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            AsElem* _Ptr = _Right._Myfirst + size();
            AsUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
            _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (_Buy(_Right.size()))
            {
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
    }
    return *this;
}

namespace asgnb36 {
inline AsVector::AsVector(const AsVector& _Right) : AsContainer(_Right), _Alaux(_Right._Alaux), _Alval(_Right._Alval)
{
    if (_Buy(_Right.size()))
    {
        try
        {
            _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
        }
        catch (...)
        {
            _Tidy();
            throw;
        }
    }
}
inline AsVector::~AsVector()
{
    _Tidy();
}
inline void AsVector::_Tidy()
{
    if (_Myfirst)
    {
        _Destroy(_Myfirst, _Mylast);
        _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
    }
    _Myfirst = 0;
    _Mylast = 0;
    _Myend = 0;
}
inline void AsVector::FUN_00b36f60(AsVector& _Right)
{
    AsVector* receiver = this;
    if (receiver == &_Right)
    {
    }
    else if (receiver->_Alval == _Right._Alval)
    {
        receiver->_Swap_aux(_Right);
        ModelSwap(receiver->_Myfirst, _Right._Myfirst);
        ModelSwap(receiver->_Mylast, _Right._Mylast);
        ModelSwap(receiver->_Myend, _Right._Myend);
    }
    else
    {
        receiver->_Swap_aux(_Right);
        AsVector saved(*receiver);
        receiver->FUN_00b36600(_Right);
        _Right.FUN_00b36600(saved);
    }
}
}
namespace backward24 {
struct SwapMove
{
};
template <class I> inline SwapMove movement(const I&)
{
    SwapMove tag;
    return tag;
}
inline void exchange(asgnb36::AsVector& left, asgnb36::AsVector& right)
{
    left.FUN_00b36f60(right);
}
template <class T> inline void exchangeAdl(T& left, T& right)
{
    exchange(left, right);
}
template <class I, class O, class C>
inline O moveLoop(I _First, I _Last, O _Dest, C, SwapMove, asgnb36::AsRangeCheckedTag)
{
    while (_First != _Last)
        exchangeAdl(*--_Dest, *--_Last);
    return _Dest;
}
template <class I, class O>
inline O moveChecked(I _First, I _Last, O _Dest, asgnb36::AsRandomTag, SwapMove mode, asgnb36::AsRangeCheckedTag)
{
    O _Result = _Dest - (_Last - _First);
    moveLoop(_First, _Last, asgnb36::AsCheckedBase(_Dest), asgnb36::AsForwardTag(), mode, asgnb36::AsRangeCheckedTag());
    return _Result;
}
}
// @fnv 0x00b35da0
asgnb36::AsVector* __cdecl FUN_00b35da0(asgnb36::AsVector* _First, asgnb36::AsVector* _Last, asgnb36::AsVector* _Dest)
{
    return backward24::moveChecked(asgnb36::AsCheckedBase(_First), asgnb36::AsCheckedBase(_Last), _Dest,
                                   asgnb36::AsIterRandom(_First, _Dest), backward24::movement(_Dest),
                                   asgnb36::AsRangeCheckedTag());
}
}  // namespace fnv_00b35da0

namespace fnv_00b35e60 {
// Independent helper model informed by the supplied VC9 matching notes.
extern "C" int __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);
namespace backward_model {
struct CheckedRange
{
};
struct ScalarPointer
{
};
struct CopyMove
{
};
struct SameBase
{
};
struct InputCategory
{
};
struct ForwardCategory : InputCategory
{
};
struct BidirectionalCategory : ForwardCategory
{
};
struct RandomCategory : BidirectionalCategory
{
};
template <class I> inline I base(I& iterator, SameBase)
{
    return iterator;
}
template <class I> inline I base(const I& iterator, SameBase)
{
    return iterator;
}
template <class I> inline I base(I& iterator)
{
    SameBase tag;
    return base(iterator, tag);
}
template <class I> inline I base(const I& iterator)
{
    SameBase tag;
    return base(iterator, tag);
}
template <class I, class O> inline RandomCategory category(const I&, const O&)
{
    RandomCategory tag;
    return tag;
}
template <class I> inline CopyMove movement(const I&)
{
    CopyMove tag;
    return tag;
}
template <class I, class O> inline ScalarPointer pointers(I&, O&)
{
    ScalarPointer tag;
    return tag;
}
template <class I, class O, class C> inline O copyBack(I first, I last, O end, C, ScalarPointer, CheckedRange)
{
    int _Off = last - first;
    O _Result = end - _Off;
    if (_Off > 0)
        FUN_00ec7ce3(_Result, _Off * sizeof(*first), first, _Off * sizeof(*first));
    return _Result;
}
template <class I, class O, class C, class M> inline O moveBack(I first, I last, O end, C order, M, CheckedRange)
{
    return copyBack(first, last, end, order, pointers(first, end), CheckedRange());
}
}
// @fnv 0x00b35e60
unsigned short* __cdecl FUN_00b35e60(unsigned short* first, unsigned short* last, unsigned short* end)
{
    using namespace backward_model;
    return moveBack(base(first), base(last), end, category(first, end), movement(end), CheckedRange());
}
}  // namespace fnv_00b35e60

namespace fnv_00b35f60 {
// Reuses the supplied other-agent vector helper model with credit; new copy wrapper below.
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

struct AsObj;
struct AsHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
void FUN_00ec7c56();
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct AsNonscalarTag
{
};
struct AsScalarTag
{
};
struct AsRangeCheckedTag
{
};
struct AsInputTag
{
};
struct AsForwardTag : AsInputTag
{
};
struct AsBidiTag : AsForwardTag
{
};
struct AsRandomTag : AsBidiTag
{
};
template <class T1, class T2> struct AsPtrCatHelper
{
    typedef AsNonscalarTag _Ptr_cat;
};
template <class T> struct AsPtrCatHelper<T**, T**>
{
    typedef AsScalarTag _Ptr_cat;
};
template <> struct AsPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef AsScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename AsPtrCatHelper<T1, T2>::_Ptr_cat AsPtrCat(T1&, T2&)
{
    typename AsPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class I1, class I2> inline AsRandomTag AsIterRandom(const I1&, const I2&)
{
    AsRandomTag _Cat;
    return _Cat;
}
struct AsUnchangedTag
{
};
template <class I> inline I AsCheckedBase(const I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(const I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I> inline I AsCheckedBase(I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I, class O, class C> inline O AsCopyOpt(I _First, I _Last, O _Dest, C, AsScalarTag, AsRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    }
    return _Result;
}
template <class I, class O> inline O AsUncheckedCopy(I _First, I _Last, O _Dest)
{
    return AsCopyOpt(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsIterRandom(_First, _Dest),
                     AsPtrCat(_First, _Dest), AsRangeCheckedTag());
}
template <class T1, class T2> inline T2 AsUninitCopy(T1 _First, T1 _Last, T2 _Dest, AsScalarTag, AsRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    T2 _Result = _Dest + _Count;
    if (_Count > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    }
    return _Result;
}
template <class I, class F, class A> inline F AsUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return AsUninitCopy(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsPtrCat(_First, _Dest),
                        AsRangeCheckedTag());
}
template <class A> inline void AsDestroyRange(typename A::pointer, typename A::pointer, A&, AsScalarTag)
{}
template <class A> inline void AsDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    AsDestroyRange(_First, _Last, _Al, AsPtrCat(_First, _Last));
}
template <class T> inline T* AsHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(_Count * sizeof(T));
}
template <class T> struct AsAlloc
{
    typedef T* pointer;
    AsAlloc() throw()
    {}
    AsAlloc(const AsAlloc<T>&) throw()
    {}
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    pointer allocate(unsigned int _Count)
    {
        return AsHeapAllocate(_Count, (pointer)0);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct AsContainer;
struct AsProxy
{
    const AsContainer* _Mycontainer;
    const AsContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct AsContainer
{
    AsProxy* _Myownedaux;
    void _Orphan_all() const
    {}
};
struct AsIterBase
{
    AsProxy* _Myaux;
    AsIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const AsIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool operator!=(const AsIterBase& _Right) const;
    void _Set_container(const AsContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
typedef unsigned short AsElem;
struct AsVector;
struct AsConstIterator : AsIterBase
{
    AsElem* _Myptr;
    AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector);
};
struct AsIterator : AsConstIterator
{
    AsIterator(AsElem* _Ptr, const AsContainer* _Pvector) : AsConstIterator(_Ptr, _Pvector)
    {}
};
struct AsVector : AsContainer
{
    int _Alaux;
    AsAlloc<AsElem> _Alval;
    AsElem* _Myfirst;
    AsElem* _Mylast;
    AsElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    AsIterator begin()
    {
        return AsIterator(_Myfirst, this);
    }
    AsIterator end()
    {
        return AsIterator(_Mylast, this);
    }
    AsIterator _Make_iter(AsConstIterator _Where) const
    {
        return AsIterator(_Where._Myptr, this);
    }
    void _Destroy(AsElem* _First, AsElem* _Last)
    {
        AsDestroyRange(_First, _Last, _Alval);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    AsIterator erase(AsConstIterator _First_arg, AsConstIterator _Last_arg)
    {
        AsIterator _First = _Make_iter(_First_arg);
        AsIterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            AsElem* _Ptr = AsUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = _Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    template <class I> AsElem* _Ucopy(I _First, I _Last, AsElem* _Ptr)
    {
        return AsUncheckedUninitCopy(_First, _Last, _Ptr, _Alval);
    }
    AsVector& FUN_00b36600(const AsVector& _Right);
};
inline AsConstIterator::AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((AsVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((AsVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
}
using namespace asgnb36;

inline AsVector& AsVector::FUN_00b36600(const AsVector& _Right)
{
    if (this != &_Right)
    {
        this->_Orphan_all();
        if (_Right.size() == 0)
        {
            clear();
        }
        else if (_Right.size() <= size())
        {
            AsElem* _Ptr = AsUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Myfirst + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            AsElem* _Ptr = _Right._Myfirst + size();
            AsUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
            _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (_Buy(_Right.size()))
            {
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
    }
    return *this;
}

namespace copy24_model {
template <class I, class O, class C>
inline O copyElements(I _First, I _Last, O _Dest, C, asgnb36::AsNonscalarTag, asgnb36::AsRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
        _Dest->FUN_00b36600(*_First);
    return _Dest;
}
}
// @fnv 0x00b35f60
asgnb36::AsVector* __cdecl FUN_00b35f60(asgnb36::AsVector* _First, asgnb36::AsVector* _Last, asgnb36::AsVector* _Dest)
{
    asgnb36::AsVector* _Result = _Dest + (_Last - _First);
    copy24_model::copyElements(_First, _Last, asgnb36::AsCheckedBase(_Dest), asgnb36::AsForwardTag(),
                               asgnb36::AsNonscalarTag(), asgnb36::AsRangeCheckedTag());
    return _Result;
}
}  // namespace fnv_00b35f60

namespace fnv_00b361b0 {
void FormHeap_Free(void* p);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
inline void FreeQ(void* p)
{
    FormHeap_Free(p);
}
struct VBQ
{
    ~VBQ()
    {
        FreeQ(*(void**)this);
    }
};
struct FUN_00b1e970
{
    char b[0x18];
    ~FUN_00b1e970();
};
struct ElemQ : VBQ
{
    FUN_00b1e970 m;
    ElemQ(const ElemQ& o);
};

__forceinline void Del(ElemQ* p, unsigned int f)
{
    p->~ElemQ();
}
inline void DeadX()
{
    int x[7];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b361b0
void FUN_00b361b0(ElemQ* first, unsigned int n, const ElemQ& val)
{
    ElemQ* next = first;
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
}  // namespace fnv_00b361b0

namespace fnv_00b368d0 {
inline void* __cdecl operator new(size_t, void* p) throw()
{
    return p;
}
inline void __cdecl operator delete(void*, void*) throw()
{}
void __cdecl FormHeap_Free(void* p);
struct S00b368d0_Buf
{
    void* p;
    ~S00b368d0_Buf()
    {
        void* tmp = p;
        FormHeap_Free(tmp);
    }
};
struct S00b368d0_Elem : S00b368d0_Buf
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00b368d0_Elem(const S00b368d0_Elem& o);
    ~S00b368d0_Elem()
    {
        int pad[7];
        Release();
    }
    void Release();
};

inline void S00b368d0_Construct(S00b368d0_Elem* p, const S00b368d0_Elem& v)
{
    void* vp = p;
    ::new (vp) S00b368d0_Elem(v);
}

inline void S00b368d0_Destroy(S00b368d0_Elem* p)
{
    p->~S00b368d0_Elem();
}

struct S00b368d0_Alloc
{
    void construct(S00b368d0_Elem* p, const S00b368d0_Elem& v)
    {
        S00b368d0_Construct(p, v);
    }
    void destroy(S00b368d0_Elem* p)
    {
        S00b368d0_Destroy(p);
    }
};

// @fnv 0x00b368d0
S00b368d0_Elem* __cdecl FUN_00b368d0(S00b368d0_Elem* first, S00b368d0_Elem* last, S00b368d0_Elem* dest,
                                     S00b368d0_Alloc& al)
{
    S00b368d0_Elem* next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            al.construct(dest, *first);
    }
    catch (...)
    {
        for (; next != dest; ++next)
            al.destroy(next);
        throw;
    }
    return dest;
}
}  // namespace fnv_00b368d0

namespace fnv_00b369f0 {
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
inline void FreeQ(void* p)
{
    FormHeap_Free(p);
}
struct VBQ
{
    ~VBQ()
    {
        FreeQ(*(void**)this);
    }
};
struct ElemQ : VBQ
{
    int i0;
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    ElemQ();
    ElemQ(const ElemQ& o);
    ~ElemQ()
    {
        FUN_00b17f50();
    }
    void FUN_00b17f50();
    void FUN_00b36f60(ElemQ& o);
    __forceinline void DelQ(unsigned f)
    {
        this->~ElemQ();
    }
};
struct AlQ
{
    int x;
};
struct SwapTagQ
{
};
struct RngTagQ
{
};
inline void DeadX()
{
    int x[6];
}
inline void DeadY()
{
    int y[1];
}
inline void DeadT()
{
    int t[5];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b369f0
ElemQ* __cdecl FUN_00b369f0(ElemQ* first, ElemQ* last, ElemQ* dest, AlQ& al, SwapTagQ, RngTagQ)
{
    ElemQ* next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            Construct(dest, *first);
    }
    catch (...)
    {
        DeadY();
        for (; next != dest; ++next)
            next->DelQ(0);
        throw;
    }
    return dest;
}
}  // namespace fnv_00b369f0

namespace fnv_00b36bf0 {
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
inline void FreeQ(void* p)
{
    FormHeap_Free(p);
}
struct VBQ
{
    ~VBQ()
    {
        FreeQ(*(void**)this);
    }
};
struct ElemQ : VBQ
{
    int i0;
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    ElemQ();
    ElemQ(const ElemQ& o);
    ~ElemQ()
    {
        FUN_00b34d90();
    }
    void FUN_00b34d90();
    void FUN_00b37190(ElemQ& o);
    __forceinline void DelQ(unsigned f)
    {
        this->~ElemQ();
    }
};
struct AlQ
{
    int x;
};
struct SwapTagQ
{
};
struct RngTagQ
{
};
inline void DeadX()
{
    int x[24];
}
inline void DeadY()
{
    int y[7];
}
inline void DeadT()
{
    int t[5];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b36bf0
ElemQ* __cdecl FUN_00b36bf0(ElemQ* first, ElemQ* last, ElemQ* dest, AlQ& al, SwapTagQ, RngTagQ)
{
    ElemQ* next = dest;
    ElemQ _Val;
    DeadT();
    try
    {
        for (; first != last; ++dest, ++first)
        {
            Construct(dest, _Val);
            dest->FUN_00b37190(*first);
        }
    }
    catch (...)
    {
        for (; next != dest; ++next)
            next->DelQ(0);
        DeadY();
        throw;
    }
    return dest;
}
}  // namespace fnv_00b36bf0

namespace fnv_00b36d70 {
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
inline void FreeQ(void* p)
{
    FormHeap_Free(p);
}
struct VBQ
{
    ~VBQ()
    {
        FreeQ(*(void**)this);
    }
};
struct ElemQ : VBQ
{
    int i0;
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    ElemQ();
    ElemQ(const ElemQ& o);
    ~ElemQ()
    {
        FUN_00b17f50();
    }
    void FUN_00b17f50();
    void FUN_00b36f60(ElemQ& o);
    __forceinline void DelQ(unsigned f)
    {
        this->~ElemQ();
    }
};
struct AlQ
{
    int x;
};
struct SwapTagQ
{
};
struct RngTagQ
{
};
inline void DeadX()
{
    int x[24];
}
inline void DeadY()
{
    int y[7];
}
inline void DeadT()
{
    int t[5];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b36d70
ElemQ* __cdecl FUN_00b36d70(ElemQ* first, ElemQ* last, ElemQ* dest, AlQ& al, SwapTagQ, RngTagQ)
{
    ElemQ* next = dest;
    ElemQ _Val;
    DeadT();
    try
    {
        for (; first != last; ++dest, ++first)
        {
            Construct(dest, _Val);
            dest->FUN_00b36f60(*first);
        }
    }
    catch (...)
    {
        for (; next != dest; ++next)
            next->DelQ(0);
        DeadY();
        throw;
    }
    return dest;
}
}  // namespace fnv_00b36d70

namespace fnv_00b39090 {
namespace vecdb390 {
struct VdNonscalarTag
{
};
struct VdScalarTag
{
};
template <class T> inline VdNonscalarTag VdPtrCat(T*&, T*&)
{
    VdNonscalarTag _Cat;
    return _Cat;
}
template <class T> inline void VdDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
template <class T> struct VdAlloc
{
    typedef T* pointer;
    void deallocate(T* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(T* _Ptr)
    {
        VdDestroyOne(_Ptr);
    }
};
template <class A>
inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, VdNonscalarTag)
{
    for (; _First != _Last; ++_First)
    {
        _Al.destroy(_First);
    }
}
template <class A> inline void VdDestroyRange(typename A::pointer, typename A::pointer, A&, VdScalarTag)
{}
template <class A> inline void VdDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    VdDestroyRange<A>(_First, _Last, _Al, VdPtrCat(_First, _Last));
}
struct VdAuxCont
{
    int unk00;
};
struct VdAuxBase
{
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
template <class T> struct VdVector : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    ~VdVector()
    {
        _Tidy();
    }
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
template <class T> struct VdVectorImpl : VdAuxBase
{
    VdAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    void _Destroy(T* _First, T* _Last)
    {
        VdDestroyRange<VdAlloc<T> >(_First, _Last, _Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0;
        _Mylast = 0;
        _Myend = 0;
    }
};
}
using namespace vecdb390;

namespace vecdb390 {
struct VdElem18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~VdElem18();
};
}
struct FUN_00b39090 : public VdVectorImpl<VdElem18>
{
    ~FUN_00b39090();
};

// @fnv 0x00b39090
FUN_00b39090::~FUN_00b39090()
{
    _Tidy();
}
}  // namespace fnv_00b39090

namespace fnv_00b39100 {
namespace vecb391 {
void FUN_00ec7c56();
struct VcElem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct VcContainer;
struct VcProxy
{
    const VcContainer* _Mycontainer;
    const VcContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct VcContainer
{
    VcProxy* _Myownedaux;
};
struct VcIterBase
{
    VcProxy* _Myaux;
    VcIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const VcIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    const VcContainer* _Getmycont() const
    {
        return _Myaux == 0 ? 0 : _Myaux->_Getmycont();
    }
    void _Set_container(const VcContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
struct VcVector;
struct VcConstIterator : VcIterBase
{
    VcElem* _Myptr;
    VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector);
    VcConstIterator& operator+=(int _Off);
    int operator-(const VcConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct VcIterator : VcConstIterator
{
    VcIterator(VcElem* _Ptr, const VcContainer* _Pvector) : VcConstIterator(_Ptr, _Pvector)
    {}
    VcIterator& operator+=(int _Off)
    {
        (*(VcConstIterator*)this) += _Off;
        return *this;
    }
    VcIterator operator+(int _Off) const
    {
        VcIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VcNonscalarTag
{
};
struct VcRangeCheckedTag
{
};
inline VcNonscalarTag VcPtrCat(VcElem*&, VcElem*&)
{
    VcNonscalarTag _Cat;
    return _Cat;
}
struct VcAlloc
{
    int unk00;
};
void FUN_00b3b5f0(VcElem* _First, unsigned int _Count, const VcElem& _Val, VcAlloc& _Al, VcNonscalarTag,
                  VcRangeCheckedTag);
inline void VcUncheckedFillN(VcElem* _First, unsigned int _Count, const VcElem& _Val, VcAlloc& _Al)
{
    FUN_00b3b5f0(_First, _Count, _Val, _Al, VcPtrCat(_First, _First), VcRangeCheckedTag());
}
struct VcVector : VcContainer
{
    int _Alaux;
    VcAlloc _Alval;
    VcElem* _Myfirst;
    VcElem* _Mylast;
    VcElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    VcIterator end()
    {
        return VcIterator(_Mylast, this);
    }
    VcElem* _Ufill(VcElem* _Ptr, unsigned int _Count, const VcElem& _Val)
    {
        VcUncheckedFillN(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    VcIterator begin()
    {
        return VcIterator(_Myfirst, this);
    }
    void FUN_00b3a0d0(VcConstIterator _Where, unsigned int _Count, const VcElem& _Val);
    VcIterator insert(VcConstIterator _Where, const VcElem& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        FUN_00b3a0d0(_Where, 1, _Val);
        return begin() + _Off;
    }
    void FUN_00b39100(const VcElem& _Val);
};
inline VcConstIterator::VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((VcVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((VcVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
inline VcConstIterator& VcConstIterator::operator+=(int _Off)
{
    if (!this->_Has_container())
        FUN_00ec7c56();
    if (!(_Myptr + _Off <= ((VcVector*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VcVector*)this->_Getmycont())->_Myfirst))
        FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}
}
using namespace vecb391;

// @fnv 0x00b39100
void VcVector::FUN_00b39100(const VcElem& _Val)
{
    if (size() < capacity())
    {
        _Mylast = _Ufill(_Mylast, 1, _Val);
    }
    else
    {
        insert(end(), _Val);
    }
}
}  // namespace fnv_00b39100

namespace fnv_00b39490 {
typedef FUN_00aa7830_cls T;
struct ResizeContainer;
struct ResizeCIterator
{
    void* owner;
    T* position;
    ResizeCIterator()
    {}
    ResizeCIterator(T* p, const ResizeContainer* c);
    ResizeCIterator& __thiscall FUN_00b16890(unsigned int count);
};
struct ResizeIterator : ResizeCIterator
{
    ResizeIterator()
    {}
    ResizeIterator(T* p, const ResizeContainer* c) : ResizeCIterator(p, c)
    {}
    ResizeIterator& operator+=(unsigned int n)
    {
        (*(ResizeCIterator*)this).FUN_00b16890(n);
        return *this;
    }
    ResizeIterator operator+(unsigned int n) const
    {
        ResizeIterator tmp = *this;
        return (tmp += n);
    }
};
struct ResizeContainer
{
    void* owner;
    unsigned int unk04;
    unsigned int unk08;
    T* first;
    T* last;
    T* capacity;
    unsigned int size() const
    {
        return last - first;
    }
    ResizeIterator begin()
    {
        return ResizeIterator(first, this);
    }
    ResizeIterator end()
    {
        return ResizeIterator(last, this);
    }
    void FUN_00b3a0d0(ResizeCIterator where, unsigned int count, const T& value);
    ResizeIterator FUN_00b1ffd0(ResizeCIterator first, ResizeCIterator last);
    void FUN_00b39490(unsigned int count, T value);
};
inline ResizeCIterator::ResizeCIterator(T* p, const ResizeContainer* c)
{
    owner = 0;
    if (c == 0 || c->first > p || p > c->last)
        FUN_00ec7c56();
    owner = c->owner;
    position = p;
}
inline void Pad24()
{
    int dq[24];
}
// @fnv 0x00b39490
void ResizeContainer::FUN_00b39490(unsigned int count, T value)
{
    if (size() < count)
        FUN_00b3a0d0(end(), count - size(), value);
    else if (count < size())
        FUN_00b1ffd0(begin() + count, end());
    Pad24();
}
}  // namespace fnv_00b39490

namespace fnv_00b396c0 {
namespace vecb39 {
void FUN_00ec7c56();
struct VcElem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct VcContainer;
struct VcProxy
{
    const VcContainer* _Mycontainer;
    const VcContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct VcContainer
{
    VcProxy* _Myownedaux;
};
struct VcIterBase
{
    VcProxy* _Myaux;
    VcIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const VcIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    const VcContainer* _Getmycont() const
    {
        return _Myaux == 0 ? 0 : _Myaux->_Getmycont();
    }
    void _Set_container(const VcContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
struct VcVector;
struct VcConstIterator : VcIterBase
{
    VcElem* _Myptr;
    VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector);
    VcConstIterator& operator+=(int _Off);
    int operator-(const VcConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct VcIterator : VcConstIterator
{
    VcIterator(VcElem* _Ptr, const VcContainer* _Pvector) : VcConstIterator(_Ptr, _Pvector)
    {}
    VcIterator& operator+=(int _Off)
    {
        (*(VcConstIterator*)this) += _Off;
        return *this;
    }
    VcIterator operator+(int _Off) const
    {
        VcIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VcVector : VcContainer
{
    int _Alaux;
    int _Alval;
    VcElem* _Myfirst;
    VcElem* _Mylast;
    VcElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    VcIterator begin()
    {
        return VcIterator(_Myfirst, this);
    }
    void FUN_00b3a0d0(VcConstIterator _Where, unsigned int _Count, const VcElem& _Val);
    VcIterator FUN_00b396c0(VcConstIterator _Where, const VcElem& _Val);
};
inline VcConstIterator::VcConstIterator(VcElem* _Ptr, const VcContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((VcVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((VcVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
inline VcConstIterator& VcConstIterator::operator+=(int _Off)
{
    if (!this->_Has_container())
        FUN_00ec7c56();
    if (!(_Myptr + _Off <= ((VcVector*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VcVector*)this->_Getmycont())->_Myfirst))
        FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}
}
using namespace vecb39;

// @fnv 0x00b396c0
VcIterator VcVector::FUN_00b396c0(VcConstIterator _Where, const VcElem& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b3a0d0(_Where, 1, _Val);
    return begin() + _Off;
}
}  // namespace fnv_00b396c0

struct BoundsB3
{
    FUN_00aa7830_cls lower;
    FUN_00aa7830_cls upper;
    BoundsB3 FUN_00b3c9a0(const BoundsB3& other);
};
// @fnv 0x00b3c9a0
BoundsB3 BoundsB3::FUN_00b3c9a0(const BoundsB3& other)
{
    BoundsB3 result(*this);
    for (int i = 0; i < 3; ++i)
    {
        if (other.lower.data[i] < lower.data[i])
            result.lower.data[i] = other.lower.data[i];
        if (other.upper.data[i] > upper.data[i])
            result.upper.data[i] = other.upper.data[i];
    }
    return result;
}

extern const float DAT_01016970;
extern const float DAT_01015f5c;
struct Vector3
{
    float values[3];
    float& operator[](int index)
    {
        return values[index];
    }
};
struct RangeInitializer
{
    Vector3 first;
    float unk0c, unk10, unk14;
    Vector3 second;
    void FUN_00b3cc30();
};
// @fnv 0x00b3cc30
void RangeInitializer::FUN_00b3cc30()
{
    first[2] = DAT_01016970;
    first[1] = DAT_01016970;
    first[0] = DAT_01016970;
    second[2] = DAT_01015f5c;
    second[1] = DAT_01015f5c;
    second[0] = DAT_01015f5c;
}

void FUN_00b2e140();

struct EntryB3CE30
{
    int unk00;
};

struct BufferB3CE30
{
    ~BufferB3CE30()
    {
        delete m_pUserData;
    }
    EntryB3CE30* m_pUserData;
};

struct ListB3CE30
{
    ~ListB3CE30()
    {
        FUN_00b3db50();
    }
    void FUN_00b3db50();
    BufferB3CE30 m_kBuffer;
    int unk04;
    int unk08;
    EntryB3CE30* m_pHeadNode;
    EntryB3CE30* m_last;
    EntryB3CE30* m_kRayEnd;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};

// Declined /Ob1 inline of vector::_Tidy (0xb3db50, frame 0x38). The 11 counters are the
// slots that tidy itself reserves for the destroy-range inline it also declines; the caller
// keeps those slots even though the call stays out of line.
inline void ListB3CE30::FUN_00b3db50()
{
    unsigned step, kept, mark, span, head, tail, aux0, aux1, aux2, aux3, aux4;
    step = kept = mark = span = head = tail = aux0 = aux1 = aux2 = aux3 = aux4 = 0;
    if (m_pHeadNode)
    {
        FUN_00b2e140();
        unsigned count = (unsigned)(m_kRayEnd - m_pHeadNode);
        delete m_pHeadNode;
        step = count;
        (void)kept;
        (void)mark;
        (void)span;
        (void)head;
        (void)tail;
        (void)aux0;
        (void)aux1;
        (void)aux2;
        (void)aux3;
        (void)aux4;
    }
    m_pHeadNode = 0;
    m_last = 0;
    m_kRayEnd = 0;
}

class OwnerB3CE30
{
  public:
    void FUN_00b3ce30();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ListB3CE30 m_kList;
    int m_iArrayLength;
    int unk48;
    EntryB3CE30** m_ppkEntries;
    EntryB3CE30* m_pkData50;
    EntryB3CE30* m_pkData54;
};

// @fnv 0x00b3ce30
void OwnerB3CE30::FUN_00b3ce30()
{
    delete m_pkData54;
    m_pkData54 = 0;
    if (m_ppkEntries)
    {
        for (int i = 0; i < m_iArrayLength; i++)
            delete m_ppkEntries[i];
        delete m_ppkEntries;
        m_ppkEntries = 0;
    }
    delete m_pkData50;
    m_pkData50 = 0;
    m_kList.ListB3CE30::~ListB3CE30();
}

namespace fnv_00b3d910 {
struct StrQ
{
    void* p;
    char buf[16];
    unsigned sz;
    unsigned res;
    ~StrQ()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool, unsigned);
};
struct Str2Q : StrQ
{
};
struct ElQ
{
    int h[5];
    Str2Q s;
    int t[9];
    ElQ(const ElQ&);
};
typedef ElQ T;
struct ResizeContainer;
struct ResizeCIterator
{
    void* owner;
    T* position;
    ResizeCIterator()
    {}
    ResizeCIterator(T* p, const ResizeContainer* c);
    ResizeCIterator& __thiscall FUN_00b3e390(unsigned int count);
};
struct ResizeIterator : ResizeCIterator
{
    ResizeIterator()
    {}
    ResizeIterator(T* p, const ResizeContainer* c) : ResizeCIterator(p, c)
    {}
    ResizeIterator& operator+=(unsigned int n)
    {
        (*(ResizeCIterator*)this).FUN_00b3e390(n);
        return *this;
    }
    ResizeIterator operator+(unsigned int n) const
    {
        ResizeIterator tmp = *this;
        return (tmp += n);
    }
};
struct ResizeContainer
{
    void* owner;
    unsigned int unk04;
    unsigned int unk08;
    T* first;
    T* last;
    T* capacity;
    unsigned int size() const
    {
        return last - first;
    }
    ResizeIterator begin()
    {
        return ResizeIterator(first, this);
    }
    ResizeIterator end()
    {
        return ResizeIterator(last, this);
    }
    void FUN_00b3dbd0(ResizeCIterator where, unsigned int count, const T& value);
    ResizeIterator FUN_00b2e250(ResizeCIterator first, ResizeCIterator last);
    void FUN_00b3d910(unsigned int count, T value);
};
inline ResizeCIterator::ResizeCIterator(T* p, const ResizeContainer* c)
{
    owner = 0;
    if (c == 0 || c->first > p || p > c->last)
        FUN_00ec7c56();
    owner = c->owner;
    position = p;
}
inline void Pad24()
{
    int dq[26];
}
// @fnv 0x00b3d910
void ResizeContainer::FUN_00b3d910(unsigned int count, T value)
{
    if (size() < count)
        FUN_00b3dbd0(end(), count - size(), value);
    else if (count < size())
        FUN_00b2e250(begin() + count, end());
    Pad24();
}
}  // namespace fnv_00b3d910

namespace fnv_00b3dbd0 {
struct MoveCatQ
{
};
struct TagQ
{
};
struct PtrCatQ
{
};
struct RandQ
{
    RandQ()
    {}
};
struct StrQ
{
    void* p;
    char buf[16];
    unsigned sz;
    unsigned res;
    ~StrQ()
    {
        Tidy(true, 0);
    }
    void Tidy(bool, unsigned);
};
struct Str2Q : StrQ
{
};
struct ElQ
{
    int h[5];
    Str2Q s;
    int t[9];
    ElQ(const ElQ&);
    ElQ& operator=(const ElQ&);
};
struct AlQ
{
    unsigned max_size() const
    {
        unsigned _Count = (unsigned)(-1) / sizeof(ElQ);
        return (0 < _Count ? _Count : 1);
    }
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    static void FormHeap_Free(void*);
};
ElQ* __cdecl FUN_00b3e450(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b3e4a0(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
inline ElQ* Uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ mc, TagQ tg)
{
    return FUN_00b3e450(f, l, d, al);
}
ElQ* __cdecl FUN_00b3e520(ElQ* f, ElQ* l, ElQ* d, RandQ, PtrCatQ, TagQ);
void __cdecl FUN_00b3e5b0(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
void __cdecl FUN_00b0fb80();
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead17()
{
    int a[17];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead6()
{
    int a[6];
}
inline void Dead21()
{
    int a[21];
}
inline void Dead8c()
{
    int a[8];
}
inline void Dead8b()
{
    int a[8];
}
inline void Dead1()
{
    int a[1];
}
inline void Dead14()
{
    int a[14];
}
inline void Dead5()
{
    int a[5];
}
inline ElQ* Checked_base3(ElQ* const& it)
{
    int iActionIndex[2];
    return it;
}
inline ElQ* Checked_base5(ElQ* const& it)
{
    int iActionIndex;
    ElQ* r = it;
    Dead6();
    return r;
}
inline MoveCatQ Move_cat(ElQ*&)
{
    MoveCatQ c;
    return c;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline RandQ Iter_random(ElQ*&, ElQ*&)
{
    RandQ c;
    return c;
}
inline ElQ* Unchecked_uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return Uninitialized_move(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b3e5b0(f, n, v, al, Ptr_cat(f, f), TagQ());
}
inline ElQ* Copy_backward(ElQ* f, ElQ* l, ElQ* d)
{
    return FUN_00b3e520(Checked_base5(f), Checked_base2(l), d, RandQ(), Ptr_cat(f, d), TagQ());
}
inline void Fill(ElQ* f, ElQ* l, const ElQ& v)
{
    for (; f != l; ++f)
        *f = v;
}
inline void Unchecked_fill3(ElQ* f, ElQ* l, const ElQ& v)
{
    Fill(Checked_base3(f), Checked_base2(l), v);
}
inline void Unchecked_fill(ElQ* f, ElQ* l, const ElQ& v)
{
    Fill(Checked_base2(f), Checked_base2(l), v);
}
struct CItQ
{
    void* m_cont;
    ElQ* m_ptr;
};
struct VecQ
{
    int m_iWordAt00;
    int m_iWordAt04;
    AlQ m_al;
    ElQ* m_pHeadNode;
    ElQ* m_last;
    ElQ* m_kRayEnd;
    unsigned capacity() const
    {
        return m_pHeadNode == 0 ? 0 : m_kRayEnd - m_pHeadNode;
    }
    unsigned size() const
    {
        return m_last - m_pHeadNode;
    }
    unsigned max_size() const
    {
        return m_al.max_size();
    }
    ElQ* _Umove(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_move(f, l, p, m_al);
    }
    ElQ* _Umove2(ElQ* f, ElQ* l, ElQ* p)
    {
        return FUN_00b3e4a0(f, l, p, m_al);
    }
    ElQ* _Ufill(ElQ* p, unsigned n, const ElQ& v)
    {
        Unchecked_uninitialized_fill_n(p, n, v, m_al);
        return p + n;
    }
    void FUN_00b2e140(ElQ* f, ElQ* l);
    void FUN_00b3dbd0(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b3dbd0
void VecQ::FUN_00b3dbd0(CItQ _Where, unsigned _Count, const ElQ& _Val)
{
    unsigned _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        Dead17();
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ElQ* _Newvec = (ElQ*)FUN_00b2e4a0(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove2(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            FUN_00b2e140(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            FUN_00b2e140(m_pHeadNode, m_last);
            Dead12();
            m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
        }
        m_kRayEnd = _Newvec + _Capacity;
        m_last = _Newvec + _Count;
        m_pHeadNode = _Newvec;
    }
    else if ((unsigned)(m_last - _Where.m_ptr) < _Count)
    {
        ElQ _Tmp(_Val);
        Dead1();
        _Umove(_Where.m_ptr, m_last, _Where.m_ptr + _Count);
        try
        {
            _Ufill(m_last, _Count - (m_last - _Where.m_ptr), _Tmp);
        }
        catch (...)
        {
            FUN_00b2e140(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Dead6();
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        ElQ* _Oldend;
        ElQ _Tmp(_Val);
        _Oldend = m_last;
        Dead14();
        m_last = _Umove2(_Oldend - _Count, _Oldend, m_last);
        Copy_backward(_Where.m_ptr, _Oldend - _Count, _Oldend);

        Unchecked_fill3(_Where.m_ptr, _Where.m_ptr + _Count, _Tmp);
        Dead5();
    }
}
}  // namespace fnv_00b3dbd0

struct VecElem54
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
};
struct VecCont54
{
    int unk00;
    int unk04;
    int unk08;
    VecElem54* _Myfirst;
    VecElem54* _Mylast;
};
struct VecAux54
{
    VecCont54* _Mycont;
    __forceinline VecCont54* _Getcont() const
    {
        return _Mycont;
    }
};
struct VecIter54
{
    VecAux54* _Myaux;
    VecElem54* _Myptr;
    __forceinline bool _Has_container() const
    {
        return _Myaux != 0;
    }
    __forceinline VecCont54* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    VecIter54& __thiscall FUN_00b3e390(int _Off);
};
// @fnv 0x00b3e390
VecIter54& VecIter54::FUN_00b3e390(int _Off)
{
    if (!(this->_Has_container()))
        FUN_00ec7c56();
    if (!(_Myptr + _Off <= _Getmycont()->_Mylast && _Myptr + _Off >= _Getmycont()->_Myfirst))
        FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}

namespace fnv_00b3e450 {
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
struct Elem3730
{
    int unk00;
    int unk04;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);

// @fnv 0x00b3e450
Elem3730* __cdecl FUN_00b3e450(Elem3730* _First, Elem3730* _Last, Elem3730* _Dest, allocatorS<Elem3730>& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b3e450

namespace fnv_00b3e4a0 {
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
// @fnv 0x00b3e4a0
ElemMOVE* __cdecl FUN_00b3e4a0(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b3e4a0

namespace fnv_00b3e520 {
// Supplied other-agent string helper model reused with credit; new record copy below.
namespace record_model {
extern const unsigned int DAT_010173f0;
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
        AssignSubstring(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    BxString& assign(const BxString& other)
    {
        return AssignSubstring(other, 0, DAT_010173f0);
    }
    BxString& operator=(const BxString& other)
    {
        BxString* receiver = this;
        return receiver->assign(other);
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
    BxString& AssignSubstring(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
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
            return AssignSubstring(*this, _Ptr - _Myptr(), _Count);
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

struct Point3
{
    float x, y, z;
};
struct FUN_00b2e680
{
    unsigned char flag;
    Point3 position;
    float value;
    BxString name;
    Point3 first, second, third;
};
typedef char FUN_00b2e680SizeCheck[(sizeof(FUN_00b2e680) == 0x54) ? 1 : -1];
struct CheckedRange
{
};
struct NonScalar
{
};
struct InputCategory
{
};
struct ForwardCategory : InputCategory
{
};
struct Unchanged
{
};
template <class I> inline I base(I& iterator, Unchanged)
{
    return iterator;
}
template <class I> inline I base(I& iterator)
{
    Unchanged tag;
    return base(iterator, tag);
}
template <class I, class O, class C> inline O copyLoop(I _First, I _Last, O _Dest, C, NonScalar, CheckedRange)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
}

namespace record_model {
struct BidirectionalCategory : ForwardCategory
{
};
struct RandomCategory : BidirectionalCategory
{
};
template <class I, class O> inline RandomCategory category(const I&, const O&)
{
    RandomCategory tag;
    return tag;
}
template <class I, class O> inline O copyBack(I _First, I _Last, O _Dest, RandomCategory, NonScalar, CheckedRange)
{
    O _Result = _Dest - (_Last - _First);
    copyLoop(_First, _Last, base(_Dest), ForwardCategory(), NonScalar(), CheckedRange());
    return _Result;
}
}

namespace record_model {
struct CopyMove
{
};
template <class I, class O> inline NonScalar pointers(const I&, const O&)
{
    NonScalar tag;
    return tag;
}
}
// @fnv 0x00b3e520
record_model::FUN_00b2e680* __cdecl FUN_00b3e520(record_model::FUN_00b2e680* _First, record_model::FUN_00b2e680* _Last,
                                                 record_model::FUN_00b2e680* _Dest, record_model::RandomCategory order,
                                                 record_model::CopyMove, record_model::CheckedRange)
{
    using namespace record_model;
    return copyBack(_First, _Last, _Dest, order, pointers(_First, _Dest), CheckedRange());
}
}  // namespace fnv_00b3e520

namespace fnv_00b3e5b0 {
inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}
struct StrQ
{
    void* p;
    char buf[16];
    unsigned sz;
    unsigned res;
    ~StrQ()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool, unsigned);
};
struct Str2Q : StrQ
{
};
struct ElemQ
{
    int h[5];
    Str2Q s;
    int t[9];
    ElemQ(const ElemQ&);
    __forceinline void DelQ(unsigned f)
    {
        this->~ElemQ();
    }
};
struct AlQ
{
    int x;
};
struct PtrTagQ
{
};
struct RngTagQ
{
};
inline void DeadX()
{
    int x[10];
}
inline void DeadY()
{
    int y[1];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b3e5b0
void __cdecl FUN_00b3e5b0(ElemQ* first, unsigned n, const ElemQ& v, AlQ& al, PtrTagQ, RngTagQ)
{
    ElemQ* next = first;
    try
    {
        for (; 0 < n; --n, ++first)
            Construct(first, v);
    }
    catch (...)
    {
        DeadY();
        for (; next != first; ++next)
            next->DelQ(0);
        throw;
    }
}
}  // namespace fnv_00b3e5b0

namespace setb3f {
struct SxObj
{
    int unk00;
    ~SxObj();
};
struct SxOwner
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
    SxObj* pObj;
    void FUN_00b3fc80(SxObj* obj);
};
}
using namespace setb3f;

// @fnv 0x00b3fc80
void SxOwner::FUN_00b3fc80(SxObj* obj)
{
    if (pObj != obj)
    {
        delete pObj;
        pObj = obj;
    }
}

namespace fnv_00b3fd60 {
namespace set00b3fd60 {
struct SxObj
{
    int unk00;
    ~SxObj();
};
struct SxOwner
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
    SxObj* pObj;
    void FUN_00b3fd60(SxObj* obj);
};
}
using namespace set00b3fd60;

// @fnv 0x00b3fd60
void SxOwner::FUN_00b3fd60(SxObj* obj)
{
    if (pObj != obj)
    {
        delete pObj;
        pObj = obj;
    }
}
}  // namespace fnv_00b3fd60

namespace fnv_00b3fe40 {
namespace set00b3fe40 {
struct SxObj
{
    int unk00;
    ~SxObj();
};
struct SxOwner
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
    SxObj* pObj;
    void FUN_00b3fe40(SxObj* obj);
};
}
using namespace set00b3fe40;

// @fnv 0x00b3fe40
void SxOwner::FUN_00b3fe40(SxObj* obj)
{
    if (pObj != obj)
    {
        delete pObj;
        pObj = obj;
    }
}
}  // namespace fnv_00b3fe40

namespace fnv_00b3feb0 {
namespace set00b3feb0 {
struct SxObj
{
    int unk00;
    ~SxObj();
};
struct SxOwner
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
    SxObj* pObj;
    void FUN_00b3feb0(SxObj* obj);
};
}
using namespace set00b3feb0;

// @fnv 0x00b3feb0
void SxOwner::FUN_00b3feb0(SxObj* obj)
{
    if (pObj != obj)
    {
        delete pObj;
        pObj = obj;
    }
}
}  // namespace fnv_00b3feb0

void __cdecl FormHeap_Free(void* p);
struct FUN_00b3f0a0
{
    int m_base[8];
    ~FUN_00b3f0a0();
};
struct FUN_00aa7830
{
    int m_00;
    ~FUN_00aa7830();
};
struct B2AE90_NameBase
{
    int m_pHeadNode;
    ~B2AE90_NameBase()
    {}
};
struct B2AE90_Name : B2AE90_NameBase
{
    int m_data[14];
    void FUN_0044a730(bool a, bool b) throw();
    ~B2AE90_Name()
    {
        int unused[5];
        (void)unused;
        FUN_0044a730(true, false);
    }
};
struct B2AE90_Allocator
{
    void deallocate(void* p)
    {
        FormHeap_Free(p);
    }
};
struct B2AE90_ArrayBase
{
    void* m_data;
    int m_iElementCount;
    int m_pRayCursor;
    B2AE90_Allocator m_alloc;
    ~B2AE90_ArrayBase()
    {
        m_alloc.deallocate(m_data);
    }
};
struct B2AE90_Array : B2AE90_ArrayBase
{
    int m_extra[2];
    void FUN_00b17f50();
    ~B2AE90_Array()
    {
        int unused[7];
        (void)unused;
        FUN_00b17f50();
    }
};
struct FUN_00b3ce30
{
    int m_00;
    ~FUN_00b3ce30();
};
struct B2AE90_Object : FUN_00b3f0a0
{
    FUN_00aa7830 m_20;
    B2AE90_Name m_24;
    B2AE90_Array m_60;
    int m_78;
    B2AE90_Array m_7c;
    FUN_00b3ce30 m_94;
    ~B2AE90_Object();
};
// @fnv 0x00b2ae90
B2AE90_Object::~B2AE90_Object()
{}

namespace fnv_00b2e3f0 {
// Supplied other-agent string helper model reused with credit; new record copy below.
namespace record_model {
extern const unsigned int DAT_010173f0;
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
        AssignSubstring(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    BxString& assign(const BxString& other)
    {
        return AssignSubstring(other, 0, DAT_010173f0);
    }
    BxString& operator=(const BxString& other)
    {
        BxString* receiver = this;
        return receiver->assign(other);
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
    BxString& AssignSubstring(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
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
            return AssignSubstring(*this, _Ptr - _Myptr(), _Count);
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

struct Point3
{
    float x, y, z;
};
struct FUN_00b2e680
{
    unsigned char flag;
    Point3 position;
    float value;
    BxString name;
    Point3 first, second, third;
};
typedef char FUN_00b2e680SizeCheck[(sizeof(FUN_00b2e680) == 0x54) ? 1 : -1];
struct CheckedRange
{
};
struct NonScalar
{
};
struct InputCategory
{
};
struct ForwardCategory : InputCategory
{
};
struct Unchanged
{
};
template <class I> inline I base(I& iterator, Unchanged)
{
    return iterator;
}
template <class I> inline I base(I& iterator)
{
    Unchanged tag;
    return base(iterator, tag);
}
template <class I, class O, class C> inline O copyLoop(I _First, I _Last, O _Dest, C, NonScalar, CheckedRange)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return _Dest;
}
}

namespace record_model {
struct BidirectionalCategory : ForwardCategory
{
};
struct RandomCategory : BidirectionalCategory
{
};
struct CopyMovement
{
};
template <class I, class O> inline RandomCategory category(const I&, const O&)
{
    RandomCategory tag;
    return tag;
}
template <class I> inline CopyMovement movement(const I&)
{
    CopyMovement tag;
    return tag;
}
template <class I, class O> inline NonScalar pointers(I&, O&)
{
    NonScalar tag;
    return tag;
}
template <class I, class O> inline O copyLoop(I _First, I _Last, O _Dest, RandomCategory, NonScalar, CheckedRange)
{
    O _Result = _Dest + (_Last - _First);
    copyLoop(_First, _Last, base(_Dest), ForwardCategory(), NonScalar(), CheckedRange());
    return _Result;
}
template <class I, class O, class C, class M> inline O moveForward(I _First, I _Last, O _Dest, C order, M, CheckedRange)
{
    return copyLoop(_First, _Last, _Dest, order, pointers(_First, _Dest), CheckedRange());
}
}

// @fnv 0x00b2e3f0
record_model::FUN_00b2e680* __cdecl FUN_00b2e3f0(record_model::FUN_00b2e680* _First, record_model::FUN_00b2e680* _Last,
                                                 record_model::FUN_00b2e680* _Dest)
{
    using namespace record_model;
    return copyLoop(base(_First), base(_Last), _Dest, category(_First, _Dest), pointers(_First, _Dest), CheckedRange());
}
}  // namespace fnv_00b2e3f0

namespace fnv_00b34450 {
struct MoveCatQ
{
};
struct TagQ
{
};
struct PtrCatQ
{
};
struct VBQ
{
    void* p;
    ~VBQ();
};
inline void FreeQ(void* p);
struct ElQ : VBQ
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    ElQ(const ElQ&);
    ElQ& operator=(const ElQ&);
    ~ElQ()
    {
        Tidy();
    }
    void Tidy();
    void DelQ(unsigned f)
    {
        this->~ElQ();
        if (f & 1)
            FreeQ(this);
    }
};
inline void FreeQ(void* p);
struct VB2Q
{
    void* p;
    ~VB2Q()
    {
        FreeQ(p);
    }
};
struct El2Q : VB2Q
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    El2Q(const ElQ&);
    ~El2Q()
    {
        Tidy();
    }
    void Tidy();
};
struct AlQ
{
    unsigned max_size() const
    {
        unsigned _Count = (unsigned)(-1) / sizeof(ElQ);
        return (0 < _Count ? _Count : 1);
    }
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b23aa0(unsigned n, ElQ* p);
ElQ* __cdecl FUN_00b36d70(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ c, TagQ t);
ElQ* __cdecl FUN_00b35da0(ElQ* f, ElQ* l, ElQ* d);
void __cdecl FUN_00b361b0(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
void __cdecl FUN_00b0fb80();
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead17()
{
    int a[17];
}
inline void Dead7()
{
    int a[7];
}
inline void Dead10()
{
    int a[10];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead8()
{
    int a[8];
}
inline void Dead9()
{
    int a[9];
}
inline void Dead11()
{
    int a[11];
}
inline void Dead8b()
{
    int a[8];
}
inline void Dead13()
{
    int a[13];
}
inline void Dead16()
{
    int a[16];
}
inline MoveCatQ Move_cat(ElQ*&)
{
    MoveCatQ c;
    return c;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b36d70(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b361b0(f, n, v, al, Ptr_cat(f, f), TagQ());
}
__forceinline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    int aP[6];
    for (; f != l; ++f)
        al.destroy(f);
}
__forceinline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
{
    Destroy_range2(f, l, al, Ptr_cat(f, l));
}
inline void Fill(ElQ* f, ElQ* l, const ElQ& v)
{
    for (; f != l; ++f)
        *f = v;
}
inline void Unchecked_fill(ElQ* f, ElQ* l, const ElQ& v)
{
    Fill(Checked_base2(f), Checked_base2(l), v);
}
struct CItQ
{
    void* m_cont;
    ElQ* m_ptr;
};
struct VecQ
{
    int m_iWordAt00;
    int m_iWordAt04;
    AlQ m_al;
    ElQ* m_pHeadNode;
    ElQ* m_last;
    ElQ* m_kRayEnd;
    unsigned capacity() const
    {
        return m_pHeadNode == 0 ? 0 : m_kRayEnd - m_pHeadNode;
    }
    unsigned size() const
    {
        return m_last - m_pHeadNode;
    }
    unsigned max_size() const
    {
        return m_al.max_size();
    }
    ElQ* _Umove(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_move(f, l, p, m_al);
    }
    ElQ* _Ufill(ElQ* p, unsigned n, const ElQ& v)
    {
        Unchecked_uninitialized_fill_n(p, n, v, m_al);
        return p + n;
    }
    void FUN_00b33110(ElQ* f, ElQ* l);
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b34450(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b34450
void VecQ::FUN_00b34450(CItQ _Where, unsigned _Count, const ElQ& _Val)
{
    unsigned _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        Dead17();
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ElQ* _Newvec = FUN_00b23aa0(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            FUN_00b33110(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            FUN_00b33110(m_pHeadNode, m_last);
            Dead12();
            m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
        }
        m_kRayEnd = _Newvec + _Capacity;
        m_last = _Newvec + _Count;
        m_pHeadNode = _Newvec;
    }
    else if ((unsigned)(m_last - _Where.m_ptr) < _Count)
    {
        ElQ _Tmp = _Val;
        _Umove(_Where.m_ptr, m_last, _Where.m_ptr + _Count);
        try
        {
            _Ufill(m_last, _Count - (m_last - _Where.m_ptr), _Tmp);
        }
        catch (...)
        {
            _DestroyI(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        El2Q _Tmp = _Val;
        ElQ* _Oldend = m_last;
        Dead7();
        m_last = _Umove(_Oldend - _Count, _Oldend, m_last);
        FUN_00b35da0(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead11();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, *(const ElQ*)&_Tmp);
        Dead7();
    }
}
}  // namespace fnv_00b34450

namespace fnv_00b36600 {
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

struct AsObj;
struct AsHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
void FUN_00ec7c56();
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct AsNonscalarTag
{
};
struct AsScalarTag
{
};
struct AsRangeCheckedTag
{
};
struct AsInputTag
{
};
struct AsForwardTag : AsInputTag
{
};
struct AsBidiTag : AsForwardTag
{
};
struct AsRandomTag : AsBidiTag
{
};
template <class T1, class T2> struct AsPtrCatHelper
{
    typedef AsNonscalarTag _Ptr_cat;
};
template <class T> struct AsPtrCatHelper<T**, T**>
{
    typedef AsScalarTag _Ptr_cat;
};
template <> struct AsPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef AsScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename AsPtrCatHelper<T1, T2>::_Ptr_cat AsPtrCat(T1&, T2&)
{
    typename AsPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class I1, class I2> inline AsRandomTag AsIterRandom(const I1&, const I2&)
{
    AsRandomTag _Cat;
    return _Cat;
}
struct AsUnchangedTag
{
};
template <class I> inline I AsCheckedBase(const I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(I& _It, AsUnchangedTag)
{
    return _It;
}
template <class I> inline I AsCheckedBase(const I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I> inline I AsCheckedBase(I& _It)
{
    AsUnchangedTag _Base_tag;
    return AsCheckedBase(_It, _Base_tag);
}
template <class I, class O, class C> inline O AsCopyOpt(I _First, I _Last, O _Dest, C, AsScalarTag, AsRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    }
    return _Result;
}
template <class I, class O> inline O AsUncheckedCopy(I _First, I _Last, O _Dest)
{
    return AsCopyOpt(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsIterRandom(_First, _Dest),
                     AsPtrCat(_First, _Dest), AsRangeCheckedTag());
}
template <class T1, class T2> inline T2 AsUninitCopy(T1 _First, T1 _Last, T2 _Dest, AsScalarTag, AsRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    T2 _Result = _Dest + _Count;
    if (_Count > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    }
    return _Result;
}
template <class I, class F, class A> inline F AsUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return AsUninitCopy(AsCheckedBase(_First), AsCheckedBase(_Last), _Dest, AsPtrCat(_First, _Dest),
                        AsRangeCheckedTag());
}
template <class A> inline void AsDestroyRange(typename A::pointer, typename A::pointer, A&, AsScalarTag)
{}
template <class A> inline void AsDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    AsDestroyRange(_First, _Last, _Al, AsPtrCat(_First, _Last));
}
template <class T> inline T* AsHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(_Count * sizeof(T));
}
template <class T> struct AsAlloc
{
    typedef T* pointer;
    AsAlloc() throw()
    {}
    AsAlloc(const AsAlloc<T>&) throw()
    {}
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    pointer allocate(unsigned int _Count)
    {
        return AsHeapAllocate(_Count, (pointer)0);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct AsContainer;
struct AsProxy
{
    const AsContainer* _Mycontainer;
    const AsContainer* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct AsContainer
{
    AsProxy* _Myownedaux;
    void _Orphan_all() const
    {}
};
struct AsIterBase
{
    AsProxy* _Myaux;
    AsIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const AsIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool operator!=(const AsIterBase& _Right) const;
    void _Set_container(const AsContainer* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
typedef unsigned short AsElem;
struct AsVector;
struct AsConstIterator : AsIterBase
{
    AsElem* _Myptr;
    AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector);
};
struct AsIterator : AsConstIterator
{
    AsIterator(AsElem* _Ptr, const AsContainer* _Pvector) : AsConstIterator(_Ptr, _Pvector)
    {}
};
struct AsVector : AsContainer
{
    int _Alaux;
    AsAlloc<AsElem> _Alval;
    AsElem* _Myfirst;
    AsElem* _Mylast;
    AsElem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    AsIterator begin()
    {
        return AsIterator(_Myfirst, this);
    }
    AsIterator end()
    {
        return AsIterator(_Mylast, this);
    }
    AsIterator _Make_iter(AsConstIterator _Where) const
    {
        return AsIterator(_Where._Myptr, this);
    }
    void _Destroy(AsElem* _First, AsElem* _Last)
    {
        AsDestroyRange(_First, _Last, _Alval);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    AsIterator erase(AsConstIterator _First_arg, AsConstIterator _Last_arg)
    {
        AsIterator _First = _Make_iter(_First_arg);
        AsIterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            AsElem* _Ptr = AsUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = _Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    template <class I> AsElem* _Ucopy(I _First, I _Last, AsElem* _Ptr)
    {
        return AsUncheckedUninitCopy(_First, _Last, _Ptr, _Alval);
    }
    AsVector& FUN_00b36600(const AsVector& _Right);
};
inline AsConstIterator::AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((AsVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((AsVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
}
using namespace asgnb36;

// @fnv 0x00b36600
AsVector& AsVector::FUN_00b36600(const AsVector& _Right)
{
    if (this != &_Right)
    {
        this->_Orphan_all();
        if (_Right.size() == 0)
        {
            clear();
        }
        else if (_Right.size() <= size())
        {
            AsElem* _Ptr = AsUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Myfirst + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            AsElem* _Ptr = _Right._Myfirst + size();
            AsUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
            _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
        }
        else
        {
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (_Buy(_Right.size()))
            {
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
    }
    return *this;
}
}  // namespace fnv_00b36600

namespace fnv_00b36b10 {
namespace fill_model {
struct RangeTag
{
};
struct ScalarTag
{
};
struct SameTag
{
};
struct InputTag
{
};
struct ForwardTag : InputTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
template <class I> inline ScalarTag pointers(const I&, const I&)
{
    ScalarTag tag;
    return tag;
}
template <class I> inline RandomTag category(const I&)
{
    RandomTag tag;
    return tag;
}
template <class I> inline I base(I& it, SameTag)
{
    return it;
}
template <class I> inline I base(I& it)
{
    SameTag tag;
    return base(it, tag);
}
template <class I, class N, class V> inline void fillLoop(I first, N count, const V& value, RangeTag)
{
    for (; 0 < count; --count, ++first)
        *first = value;
}
template <class I, class N, class V> inline void fillChecked(I first, N count, const V& value, RandomTag, RangeTag)
{
    I last = first + count;
    fillLoop(base(first), count, value, RangeTag());
}
template <class I, class N, class V> inline void fillN(I first, N count, const V& value)
{
    fillChecked(first, count, value, category(first), RangeTag());
}
template <class I, class N, class V, class A>
inline void initFill(I first, N count, const V& value, A&, ScalarTag, RangeTag)
{
    fillN(first, count, value);
}
}
// @fnv 0x00b36b10
void __cdecl FUN_00b36b10(unsigned int* first, unsigned count, const unsigned int& value)
{
    using namespace fill_model;
    fillChecked(first, count, value, category(first), RangeTag());
}
}  // namespace fnv_00b36b10

extern void __cdecl FormHeap_Free(void* p);
template <class T> inline void swapq(T& l, T& r)
{
    if (&l != &r)
    {
        T t = l;
        l = r;
        r = t;
    }
}
struct AuxQ
{
    void* cont;
};
struct AuxBaseQ
{
    AuxQ* m0;
    static void Dealloc(void* p)
    {
        FormHeap_Free(p);
    }
    ~AuxBaseQ()
    {
        Dealloc(m0);
    }
    void SwapAux(AuxBaseQ& r)
    {
        swapq(m0, r.m0);
        swapq(*m0, *r.m0);
    }
};
struct ValQ : AuxBaseQ
{
    int u4;
    int u8;
    ~ValQ()
    {}
};
struct FUN_00b357d0 : ValQ
{
    int mc;
    int m10;
    int m14;
    FUN_00b357d0(const FUN_00b357d0& other);
    ~FUN_00b357d0()
    {
        FUN_00b34d90();
    }
    FUN_00b357d0& __thiscall FUN_00b36600(const FUN_00b357d0& o);
    void __thiscall FUN_00b34d90();
    void __thiscall FUN_00b36f60(FUN_00b357d0& o);
};
inline void PadQ()
{
    int dq[81];
}
// @fnv 0x00b36f60
void __thiscall FUN_00b357d0::FUN_00b36f60(FUN_00b357d0& o)
{
    if (this == &o)
        ;
    else if (1)
    {
        SwapAux(o);
        swapq(mc, o.mc);
        swapq(m10, o.m10);
        swapq(m14, o.m14);
    }
    else
    {
        SwapAux(o);
        FUN_00b357d0 ts = *this;
        FUN_00b36600(o);
        o.FUN_00b36600(ts);
        PadQ();
    }
}

namespace fnv_00b37190 {
extern void __cdecl FormHeap_Free(void* p);
template <class T> inline void swapq(T& l, T& r)
{
    if (&l != &r)
    {
        T t = l;
        l = r;
        r = t;
    }
}
struct AuxQ
{
    void* cont;
};
struct AuxBaseQ
{
    AuxQ* m0;
    static void Dealloc(void* p)
    {
        FormHeap_Free(p);
    }
    ~AuxBaseQ()
    {
        Dealloc(m0);
    }
    void SwapAux(AuxBaseQ& r)
    {
        swapq(m0, r.m0);
        swapq(*m0, *r.m0);
    }
};
struct ValQ : AuxBaseQ
{
    int u4;
    int u8;
    ~ValQ()
    {}
};
struct FUN_00b357d0 : ValQ
{
    int mc;
    int m10;
    int m14;
    FUN_00b357d0(const FUN_00b357d0& other);
    ~FUN_00b357d0()
    {
        FUN_00b34d90();
    }
    FUN_00b357d0& __thiscall FUN_00b36600(const FUN_00b357d0& o);
    void __thiscall FUN_00b34d90();
    void __thiscall FUN_00b37190(FUN_00b357d0& o);
};
inline void PadQ()
{
    int dq[81];
}
// @fnv 0x00b37190
void __thiscall FUN_00b357d0::FUN_00b37190(FUN_00b357d0& o)
{
    if (this == &o)
        ;
    else if (1)
    {
        SwapAux(o);
        swapq(mc, o.mc);
        swapq(m10, o.m10);
        swapq(m14, o.m14);
    }
    else
    {
        SwapAux(o);
        FUN_00b357d0 ts = *this;
        FUN_00b36600(o);
        o.FUN_00b36600(ts);
        PadQ();
    }
}
}  // namespace fnv_00b37190

namespace fnv_00b3c3f0 {
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
unsigned int __cdecl FUN_00ec7c56();
namespace std {
class bad_alloc
{
  public:
    bad_alloc(const char* pcMessage = "bad allocation") throw();
    virtual ~bad_alloc() throw();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
}
struct SecureCharTag
{
};
struct CharTraits
{
    static unsigned int length(const char* pcFirst)
    {
        return strlen(pcFirst);
    }
    static char* _Copy_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memcpy_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static char* _Move_s(char* pcFirst1, unsigned int uiSizeInBytes, const char* pcFirst2, unsigned int ItemUpdateArray)
    {
        memmove_s(pcFirst1, uiSizeInBytes, pcFirst2, ItemUpdateArray);
        return pcFirst1;
    }
    static void assign(char& cLeft, const char& cRight)
    {
        cLeft = cRight;
    }
};
struct TraitsHelper
{
    static SecureCharTag CharTraitsCat()
    {
        SecureCharTag kTag;
        return kTag;
    }
    static char* CopySHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return CopySHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
    static char* MoveSHelper(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray,
                             SecureCharTag)
    {
        return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
    }
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
    {
        return MoveSHelper(pcDst, uiDstSize, pcSrc, ItemUpdateArray, CharTraitsCat());
    }
};
inline char* AllocateChars(unsigned int ItemUpdateArray, char*)
{
    if (ItemUpdateArray <= 0)
        ItemUpdateArray = 0;
    else if (((unsigned int)(-1) / ItemUpdateArray) < sizeof(char))
        throw std::bad_alloc(0);
    return (char*)::operator new(ItemUpdateArray * sizeof(char));
}
struct CharAllocator
{
    CharAllocator()
    {}
    void deallocate(char* pcPtr, unsigned int)
    {
        ::operator delete(pcPtr);
    }
    char* allocate(unsigned int ItemUpdateArray)
    {
        return AllocateChars(ItemUpdateArray, (char*)0);
    }
    unsigned int max_size() const
    {
        unsigned int ItemUpdateArray = (unsigned int)(-1) / sizeof(char);
        return 0 < ItemUpdateArray ? ItemUpdateArray : 1;
    }
};
struct StringBase
{
    static void _Xlen();
    static void _Xran();
};
struct StringVal : public StringBase
{
    StringVal(CharAllocator kAl = CharAllocator()) : m_kAlval(kAl)
    {}
    CharAllocator m_kAlval;
};
struct String : public StringVal
{
    static const unsigned int npos;
    String(const char* pcPtr) : StringVal()
    {
        _Tidy();
        assign(pcPtr);
    }
    String(const String& kRight) : StringVal(kRight.m_kAlval)
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& assign(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (ItemUpdateArray < uiElementCount)
            uiElementCount = ItemUpdateArray;
        if (this == &kRight)
            erase((unsigned int)(uiRoff + uiElementCount)), erase(0, uiRoff);
        else if (_Grow(uiElementCount))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, kRight._Myptr() + uiRoff, uiElementCount);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& assign(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return assign(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (_Grow(ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr(), m_uiRes, pcPtr, ItemUpdateArray);
            _Eos(ItemUpdateArray);
        }
        return *this;
    }
    String& assign(const char* pcPtr)
    {
        return assign(pcPtr, CharTraits::length(pcPtr));
    }
    String& erase(unsigned int uiOff = 0, unsigned int ItemUpdateArray = npos)
    {
        if (m_uiSize < uiOff)
            _Xran();
        if (m_uiSize - uiOff < ItemUpdateArray)
            ItemUpdateArray = m_uiSize - uiOff;
        if (0 < ItemUpdateArray)
        {
            TraitsHelper::MoveS(_Myptr() + uiOff, m_uiRes - uiOff, _Myptr() + uiOff + ItemUpdateArray,
                                m_uiSize - uiOff - ItemUpdateArray);
            unsigned int uiNewsize = m_uiSize - ItemUpdateArray;
            _Eos(uiNewsize);
        }
        return *this;
    }
    const char* c_str() const
    {
        if (16 <= m_uiRes)
            return m_kBx.m_pcPtr;
        return m_kBx.m_acBuf;
    }
    unsigned int size() const
    {
        return m_uiSize;
    }
    unsigned int length() const
    {
        return m_uiSize;
    }
    unsigned int max_size() const
    {
        unsigned int uiElementCount = m_kAlval.max_size();
        return uiElementCount <= 1 ? 1 : uiElementCount - 1;
    }
    const char& operator[](unsigned int uiOff) const
    {
        if (!(uiOff <= m_uiSize))
            FUN_00ec7c56();
        do
        {
        } while (0);
        return _Myptr()[uiOff];
    }
    void _Copy(unsigned int uiNewsize, unsigned int uiOldlen)
    {
        unsigned int uiNewres = uiNewsize | 15;
        if (max_size() < uiNewres)
            uiNewres = uiNewsize;
        else if (uiNewres / 3 < m_uiRes / 2 && m_uiRes <= max_size() - m_uiRes / 2)
            uiNewres = m_uiRes + m_uiRes / 2;
        char* pcPtr = 0;
        try
        {
            pcPtr = m_kAlval.allocate(uiNewres + 1);
        }
        catch (...)
        {
            uiNewres = uiNewsize;
            try
            {
                pcPtr = m_kAlval.allocate(uiNewres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < uiOldlen)
            TraitsHelper::CopyS(pcPtr, uiNewres + 1, _Myptr(), uiOldlen);
        _Tidy(true);
        m_kBx.m_pcPtr = pcPtr;
        m_uiRes = uiNewres;
        _Eos(uiOldlen);
    }
    void _Eos(unsigned int uiNewsize)
    {
        CharTraits::assign(_Myptr()[m_uiSize = uiNewsize], char());
    }
    bool _Grow(unsigned int uiNewsize, bool bTrim = false)
    {
        if (max_size() < uiNewsize)
            _Xlen();
        if (m_uiRes < uiNewsize)
            _Copy(uiNewsize, m_uiSize);
        else if (bTrim && uiNewsize < 16)
            _Tidy(true, uiNewsize < m_uiSize ? uiNewsize : m_uiSize);
        else if (uiNewsize == 0)
            _Eos(0);
        return 0 < uiNewsize;
    }
    bool _Inside(const char* pcPtr)
    {
        if (pcPtr == 0 || pcPtr < _Myptr() || _Myptr() + m_uiSize <= pcPtr)
            return false;
        else
            return true;
    }
    char* _Myptr()
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    const char* _Myptr() const
    {
        return 16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf;
    }
    void _Tidy(bool bBuilt = false, unsigned int uiNewsize = 0)
    {
        if (!bBuilt)
            ;
        else if (16 <= m_uiRes)
        {
            char* pcPtr = m_kBx.m_pcPtr;
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, pcPtr, uiNewsize);
            m_kAlval.deallocate(pcPtr, m_uiRes + 1);
        }
        m_uiRes = 15;
        _Eos(uiNewsize);
    }
    union
    {
        char m_acBuf[16];
        char* m_pcPtr;
    } m_kBx;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
};
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
class Exception_b3c3
{
  public:
    Exception_b3c3() : m_pcWhat(0), m_iDoFree(0)
    {}
    virtual ~Exception_b3c3() throw();
    const char* m_pcWhat;
    int m_iDoFree;
};

class RuntimeError_b3c3 : public Exception_b3c3
{
  public:
    RuntimeError_b3c3(const String& kMessage) : m_kStr(kMessage)
    {}
    virtual ~RuntimeError_b3c3() throw()
    {}
    String m_kStr;
};

class FUN_00b3c3f0 : public RuntimeError_b3c3
{
// @fnv 0x00b3c3f0
  public:
    FUN_00b3c3f0(const String& kMessage) : RuntimeError_b3c3(kMessage)
    {}
    virtual ~FUN_00b3c3f0() throw()
    {}
};

void* MakeError_b3c3()
{
    return new FUN_00b3c3f0(String(""));
}
}  // namespace fnv_00b3c3f0

namespace fnv_00b326e0 {
void __cdecl operator delete(void* _Ptr) throw();
namespace valb326 {
void FUN_00ec7c56();
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
struct BxException;
struct BxBadAlloc;
template <class T> inline T* BxAllocate(unsigned int count, T*);
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
    BxException(const char* const& _What);
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxBadAlloc : public BxException
{
    BxBadAlloc(const char* _Message = "bad allocation") throw() : BxException(_Message)
    {}
    virtual ~BxBadAlloc() throw()
    {}
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

template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
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
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
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
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
}
using namespace valb326;
struct FUN_00b326e0 : GvAuxBase<GvAlloc<unsigned short> >
{
    GvAlloc<unsigned short> _Alval;
    FUN_00b326e0(GvAlloc<unsigned short> _Al);
};
// @fnv 0x00b326e0
FUN_00b326e0::FUN_00b326e0(GvAlloc<unsigned short> _Al) : GvAuxBase<GvAlloc<unsigned short> >(_Al), _Alval(_Al)
{}
}  // namespace fnv_00b326e0

namespace fnv_00b35a90 {
void __cdecl operator delete(void* _Ptr) throw();
namespace cpyb35a {
void FUN_00ec7c56();
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
struct BxException;
struct BxBadAlloc;
template <class T> inline T* BxAllocate(unsigned int count, T*);
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
    BxException(const char* const& _What);
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxBadAlloc : public BxException
{
    BxBadAlloc(const char* _Message = "bad allocation") throw() : BxException(_Message)
    {}
    virtual ~BxBadAlloc() throw()
    {}
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

template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
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
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
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
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
struct GvItem;
}
using namespace cpyb35a;
// @fnv 0x00b35a90
GvVector<unsigned short>* FUN_00b35a90(GvVector<unsigned short>* _First, GvVector<unsigned short>* _Last,
                                       GvVector<unsigned short>* _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
}  // namespace fnv_00b35a90

// @fnv 0x00b32bb0
void Vec18::FUN_00b32bb0(Elem18* first, Elem18* last)
{
    VdDestroyRange((VdVector<unsigned short>*)first, (VdVector<unsigned short>*)last,
                   *(VdAlloc<VdVector<unsigned short> >*)this);
}

inline NonScalarTag PtrCat_b33110(Value*&, Value*&)
{
    NonScalarTag _Cat;
    return _Cat;
}
inline void DRange2_b33110(Value* _First, Value* _Last, NonScalarTag)
{
    for (; _First != _Last; ++_First)
        _First->~Value();
}
__forceinline void DRange1_b33110(Value* _First, Value* _Last)
{
    DRange2_b33110(_First, _Last, PtrCat_b33110(_First, _Last));
}
struct Outer_b33110
{
    void FUN_00b33110(Value* _First, Value* _Last);
};

// @fnv 0x00b33110
void Outer_b33110::FUN_00b33110(Value* _First, Value* _Last)
{
    DRange1_b33110(_First, _Last);
}

struct AllocQ
{
    AllocQ()
    {}
    AllocQ(const AllocQ&)
    {}
};
static __forceinline void PadF()
{
    int aiD[11];
}
struct FUN_00b326e0
{
    int first, last, end;
    FUN_00b326e0(AllocQ a);
    ~FUN_00b326e0();
};
struct FUN_00b311b0 : FUN_00b326e0
{
    void FUN_00b32600(unsigned int n, void* const& v);
    explicit FUN_00b311b0(unsigned int n);
};
// @fnv 0x00b311b0
FUN_00b311b0::FUN_00b311b0(unsigned int n) : FUN_00b326e0(AllocQ())
{
    PadF();
    FUN_00b32600(n, (void*)0);
}

void __cdecl operator delete(void*) throw();

struct ScalarTag31
{
};
struct ErrorString
{
    int allocator;
    union
    {
        char buffer[16];
        char* data;
    } storage;
    unsigned length;
    unsigned capacity;
    ErrorString(const char*);
    void Tidy(bool, unsigned);
    ~ErrorString()
    {
        Tidy(true, 0);
    }
};
struct ExceptionBase
{
    const char* message;
    int owned;
    ExceptionBase(const char* const&);
    virtual ~ExceptionBase();
};
struct BadAlloc : ExceptionBase
{
    BadAlloc(const char* text) throw() : ExceptionBase(text)
    {}
    virtual ~BadAlloc() throw()
    {}
};
struct LogicError : ExceptionBase
{
    ErrorString messageText;
    LogicError(const ErrorString&);
    virtual ~LogicError()
    {}
};
struct LengthError : LogicError
{
    LengthError(const ErrorString& text) : LogicError(text)
    {}
    virtual ~LengthError()
    {}
};
template <class T> inline ScalarTag31 ptr_cat31(T*&, T*&)
{
    ScalarTag31 cat;
    return cat;
}
template <class T> struct Alloc31;
template <class T> inline void destroy_range31(T* first, T* last, Alloc31<T>& al, ScalarTag31)
{}
template <class T> inline void destroy_range31(T* first, T* last, Alloc31<T>& al)
{
    destroy_range31(first, last, al, ptr_cat31(first, last));
}
struct Container31;
struct Proxy31
{
    const Container31* owner;
    explicit Proxy31(const Container31* p) : owner(p)
    {}
};
Proxy31* __cdecl FUN_0044d670(unsigned count, Proxy31* hint);
template <class T> inline T* allocate_storage(unsigned count, T* hint)
{
    if (count <= 0)
        count = 0;
    else if (0xffffffffU / count < sizeof(T))
        throw BadAlloc(0);
    return (T*)operator new(count * sizeof(T));
}
inline Proxy31* allocate_storage(unsigned count, Proxy31* hint)
{
    return FUN_0044d670(count, hint);
}
template <class T> struct Alloc31
{
    Alloc31() throw()
    {}
    Alloc31(const Alloc31&) throw()
    {}
    template <class U> Alloc31(const Alloc31<U>&) throw()
    {}
    T* allocate(unsigned count)
    {
        return allocate_storage(count, (T*)0);
    }
    void deallocate(T* p, unsigned n)
    {
        operator delete(p);
    }
    unsigned max_size() const throw()
    {
        unsigned count = 0xffffffffU / sizeof(T);
        return 0 < count ? count : 1;
    }
};
struct Container31
{
    Proxy31* unk00;
    Container31()
    {}
    ~Container31()
    {}
};
template <class A> struct ContainerAlloc31 : Container31
{
    Alloc31<Proxy31> unk04;
    explicit ContainerAlloc31(A al) : unk04(al)
    {
        unk00 = new (unk04.allocate(1)) Proxy31(this);
    }
    ~ContainerAlloc31()
    {
        unk00->~Proxy31();
        unk04.deallocate(unk00, 1);
    }
};
template <class T> struct VectorVal31 : ContainerAlloc31<Alloc31<T> >
{
    Alloc31<T> unk08;
    VectorVal31(Alloc31<T> al = Alloc31<T>()) : ContainerAlloc31<Alloc31<T> >(al), unk08(al)
    {}
};
struct Value31 : VectorVal31<int>
{
    int* unk0c;
    int* unk10;
    int* unk14;
    Value31() : VectorVal31<int>()
    {
        Buy(0);
    }
    bool Buy(unsigned count)
    {
        unk0c = 0;
        unk10 = 0;
        unk14 = 0;
        if (count == 0)
            return false;
        else if (max_size() < count)
            xlen();
        else
        {
            unk0c = unk08.allocate(count);
            unk10 = unk0c;
            unk14 = unk0c + count;
        }
        return true;
    }
    unsigned max_size() const
    {
        return unk08.max_size();
    }
    static void xlen()
    {
        throw LengthError(ErrorString("vector<T> too long"));
    }
    void destroy(int* first, int* last)
    {
        destroy_range31(first, last, unk08);
    }
    void FUN_00b17f50()
    {
        if (unk0c)
        {
            destroy(unk0c, unk10);
            unk08.deallocate(unk0c, unk14 - unk0c);
        }
        unk0c = 0;
        unk10 = 0;
        unk14 = 0;
    }
    ~Value31()
    {
        FUN_00b17f50();
    }
};
struct FUN_00b31ad0 : VectorVal31<Value31>
{
    Value31* unk0c;
    Value31* unk10;
    Value31* unk14;
    void FUN_00b32ce0(unsigned count, const Value31& value);
    explicit FUN_00b31ad0(unsigned count);
};
// @fnv 0x00b31ad0
FUN_00b31ad0::FUN_00b31ad0(unsigned count) : VectorVal31<Value31>()
{
    FUN_00b32ce0(count, Value31());
}

struct Elem24Q
{
    int a[6];
};
struct NonScalarTagQ
{
};
struct AlQ134
{
    int x;
};
void __cdecl FUN_00b361b0(Elem24Q* f, unsigned int n, const Elem24Q& v, AlQ134& al, NonScalarTagQ, RangeTagQ);
void __stdcall FUN_00ec7894(int, int);
inline void PadAQ()
{
    int a[26];
}
inline void PadBQ()
{
    int a[14];
}
inline NonScalarTagQ PtrCatQ(Elem24Q*&, Elem24Q*&)
{
    NonScalarTagQ c;
    return c;
}
inline void UfillInnerQ(Elem24Q* f, unsigned int n, const Elem24Q& v, AlQ134& al)
{
    FUN_00b361b0(f, n, v, al, PtrCatQ(f, f), RangeTagQ());
}
struct Vec134Q
{
    int unk00, unk04;
    AlQ134 al;
    Elem24Q* first;
    Elem24Q* last;
    Elem24Q* end;
    bool FUN_00b1f590(unsigned int n);
    void FUN_00b331c0();
    Elem24Q* UfillQ(Elem24Q* p, unsigned int n, const Elem24Q& v)
    {
        PadAQ();
        UfillInnerQ(p, n, v, al);
        return p + n;
    }
    void FUN_00b32ce0(unsigned int n, const Elem24Q& v);
};
// @fnv 0x00b32ce0
void Vec134Q::FUN_00b32ce0(unsigned int n, const Elem24Q& v)
{
    if (FUN_00b1f590(n))
    {
        try
        {
            last = UfillQ(first, n, v);
            PadBQ();
        }
        catch (...)
        {
            FUN_00b331c0();
            FUN_00ec7894(0, 0);
        }
    }
}

struct V24
{
    int m00, m04, m08, m0c, m10, m14;
    V24& FUN_00b36330(const V24& r);
    V24& operator=(const V24& r)
    {
        return FUN_00b36330(r);
    }
};
static __forceinline void Dead75Q()
{
    int aiD[75];
}
template <class _InIt, class _OutIt, class _InOutItCat>
__forceinline _OutIt CopyOptF(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                              _Range_checked_iterator_tagS)
{
    Dead75Q();
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
__forceinline _OutIt CopyOptF(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                              _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    CopyOptF(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
             _Range_checked_iterator_tagS());
    return _Result;
}
// @fnv 0x00b35b60
V24* FUN_00b35b60(V24* _First, V24* _Last, V24* _Dest)
{
    return CopyOptF(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                    _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS());
}

struct CopyValue
{
    char m_data[0x18];
    CopyValue& FUN_00b36330(const CopyValue& other);
    CopyValue& operator=(const CopyValue& other)
    {
        return FUN_00b36330(other);
    }
};
static __forceinline void Dead82()
{
    int aiD[82];
}
// @fnv 0x00b36000
CopyValue* __cdecl FUN_00b36000(CopyValue* first, CopyValue* last, CopyValue* dest)
{
    CopyValue* result = dest + (last - first);
    Dead82();
    _Copy_optS(first, last, dest, forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return result;
}

namespace vector_ctor_model {
template <class T> struct ValueBase : ContainerAlloc31<Alloc31<T> >
{
    typedef Alloc31<T> Allocator;
    ValueBase(Allocator al = Allocator()) : ContainerAlloc31<Allocator>(al), allocator(al)
    {}
    Allocator allocator;
    T* first;
    T* last;
    T* limit;
    unsigned max_size() const
    {
        return allocator.max_size();
    }
    static void too_long()
    {
        throw buyUShort::BxLengthError("vector<T> too long");
    }
    bool FUN_00b34cd0(unsigned capacity)
    {
        first = 0, last = 0, limit = 0;
        if (capacity == 0)
            return false;
        else if (max_size() < capacity)
            too_long();
        else
        {
            first = allocator.allocate(capacity);
            last = first;
            limit = first + capacity;
        }
        return true;
    }
};
}
struct FUN_00b336a0 : vector_ctor_model::ValueBase<unsigned short>
{
    FUN_00b336a0();
};
// @fnv 0x00b336a0
FUN_00b336a0::FUN_00b336a0() : vector_ctor_model::ValueBase<unsigned short>()
{
    FUN_00b34cd0(0);
}

namespace copy_short {
template <class T> inline T* allocateStorage(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if ((unsigned int)(-1) / count < sizeof(T))
        throw BadAlloc(0);
    return (T*)operator new(count * sizeof(T));
}
template <class T> struct CopyAllocator : record_model::BxAllocT<T>
{
    T* allocate(unsigned int count)
    {
        return allocateStorage(count, (T*)0);
    }
};
typedef CopyAllocator<unsigned short> Allocator;
struct Container
{
    void* proxy;
};
struct FUN_00b20ba0 : Container
{
    record_model::BxAllocT<Container> auxiliaryAllocator;
    FUN_00b20ba0(Allocator allocator);
    ~FUN_00b20ba0()
    {
        auxiliaryAllocator.deallocate((Container*)proxy, 1);
    }
};
template <class T> struct Vector;
struct Universal
{
};
struct IteratorBase : Universal
{
    void* proxy;
    IteratorBase() : proxy(0)
    {}
    void setContainer(const Container* container)
    {
        proxy = container->proxy;
    }
};
struct RandomIterator : IteratorBase
{
};
struct Iterator : RandomIterator
{
    unsigned short* pointer;
    Iterator(unsigned short* position, const Container* owner);
};
struct ScalarPointer
{
};
struct CheckedRange
{
};
struct DifferentBase
{
};
inline const unsigned short* checkedBase(Iterator& it, DifferentBase)
{
    return it.pointer;
}
inline const unsigned short* checkedBase(Iterator& it)
{
    DifferentBase tag;
    return checkedBase(it, tag);
}
inline ScalarPointer pointerCategory(Iterator&, unsigned short*&)
{
    ScalarPointer tag;
    return tag;
}
inline unsigned short* initializeCopy(const unsigned short* first, const unsigned short* last, unsigned short* dest,
                                      Allocator&, ScalarPointer, CheckedRange)
{
    unsigned int count = last - first;
    unsigned short* result = dest + count;
    if (count > 0)
        memmove_s(dest, count * sizeof(*first), first, count * sizeof(*first));
    return result;
}
inline unsigned short* __cdecl FUN_00b362c0(Iterator first, Iterator last, unsigned short* dest, Allocator& allocator)
{
    return initializeCopy(checkedBase(first), checkedBase(last), dest, allocator, pointerCategory(first, dest),
                          CheckedRange());
}
template <class T> struct Vector : FUN_00b20ba0
{
    Allocator allocator;
    unsigned short* first;
    unsigned short* last;
    unsigned short* limit;
    Vector(Allocator source) : FUN_00b20ba0(source), allocator(source)
    {}
    unsigned int size() const
    {
        return last - first;
    }
    Iterator begin() const
    {
        return Iterator(first, this);
    }
    Iterator end() const
    {
        return Iterator(last, this);
    }
    unsigned int max_size() const
    {
        return allocator.max_size();
    }
    bool FUN_00b34cd0(unsigned int _Capacity)
    {
        first = 0, last = 0, limit = 0;
        if (_Capacity == 0)
            return false;
        else if (max_size() < _Capacity)
            tooLong();
        else
        {
            first = allocator.allocate(_Capacity);
            last = first;
            limit = first + _Capacity;
        }
        return true;
    }
    static void tooLong()
    {
        throw record_model::BxLengthError("vector<T> too long");
    }
    void destroy(unsigned short* begin, unsigned short* end)
    {
        VdAlloc<unsigned short> al;
        VdDestroyRange<VdAlloc<unsigned short> >(begin, end, al);
    }
    void FUN_00b34d90()
    {
        if (first)
        {
            destroy(first, last);
            allocator.deallocate(first, limit - first);
        }
        first = 0, last = 0, limit = 0;
    }
    unsigned short* copy(Iterator first, Iterator last, unsigned short* dest)
    {
        return FUN_00b362c0(first, last, dest, allocator);
    }
};
inline Iterator::Iterator(unsigned short* position, const Container* owner)
{
    if (!owner || ((const Vector<unsigned short>*)owner)->first > position ||
        position > ((const Vector<unsigned short>*)owner)->last)
        FUN_00ec7c56();
    setContainer(owner);
    pointer = position;
}
struct FUN_00b357d0 : Vector<unsigned short>
{
    FUN_00b357d0(const FUN_00b357d0& other);
};
// @fnv 0x00b357d0
FUN_00b357d0::FUN_00b357d0(const FUN_00b357d0& other) : Vector<unsigned short>(other.allocator)
{
    if (FUN_00b34cd0(other.size()))
    {
        try
        {
            last = copy(other.begin(), other.end(), first);
        }
        catch (...)
        {
            FUN_00b34d90();
            throw;
        }
    }
}
}

namespace MapLookupDetail {
struct Allocator
{
    void deallocate(char* p, unsigned)
    {
        operator delete(p);
    }
};
template <class C, class Traits, class A> class basic_string
{
    A allocation;
    union Storage
    {
        C buffer[16];
        C* pointer;
    } storage;
    unsigned length, capacity;

  public:
    basic_string(const basic_string& rhs)
    {
        FUN_0044a730(false, 0);
        AssignSubstring(rhs, 0, record_model::DAT_010173f0);
    }
    ~basic_string()
    {
        FUN_0044a730(true, 0);
    }

  protected:
    void FUN_0044a730(bool built, unsigned count)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            C* _Ptr = storage.pointer;
            if (0 < count)
                record_model::BxTraitsHelper::copy_s<record_model::BxStrTraits>(storage.buffer, 16, _Ptr, count);
            allocation.deallocate(_Ptr, capacity + 1);
        }
        capacity = 15;
        eos(count);
    }
    C* data()
    {
        return 16 <= capacity ? storage.pointer : storage.buffer;
    }
    const C* data() const
    {
        return 16 <= capacity ? storage.pointer : storage.buffer;
    }
    void eos(unsigned count)
    {
        data()[length = count] = C();
    }

  public:
    basic_string& AssignSubstring(const basic_string&, unsigned, unsigned);
    int FUN_00ac9da0(const basic_string&) const;
};
typedef basic_string<char, record_model::BxStrTraits, Allocator> MapKey;
struct MapValue
{
    const MapKey first;
    int second;
    MapValue(const MapKey& key, const int& value) : first(key), second(value)
    {}
};
struct ContainerBase;
struct Aux
{
    const ContainerBase* container;
    const ContainerBase* get() const
    {
        return container;
    }
};
struct ContainerBase
{
    Aux* proxy;
};
struct Universal
{
};
struct IteratorBase : Universal
{
    const Aux* proxy;
    IteratorBase() : proxy(0)
    {}
    void _Set_container(const ContainerBase* owner)
    {
        proxy = owner->proxy;
    }
    const ContainerBase* _Getmycont() const
    {
        return proxy ? proxy->get() : 0;
    }
    bool _Has_container() const
    {
        return proxy != 0;
    }
    bool _Same_container(const IteratorBase& rhs) const
    {
        return proxy == rhs.proxy;
    }
};
struct IteratorWithBase : IteratorBase
{
};
struct Bidit : IteratorWithBase
{
};
struct LookupNode
{
    LookupNode *left, *parent, *right;
    MapValue value;
    char color, nil;
};
struct LookupMap;
struct LookupConstIter : Bidit
{
    LookupNode* node;
    LookupConstIter(LookupNode* p, const ContainerBase* owner) : node(p)
    {
        if (!owner)
            FUN_00ec7c56();
        this->_Set_container(owner);
    }
    bool operator==(const LookupConstIter& rhs) const
    {
        if (!(this->_Has_container() && this->_Same_container(rhs)))
            FUN_00ec7c56();
        return node == rhs.node;
    }
    const MapValue& FUN_00b3b090() const;
    LookupNode* getNode() const
    {
        return node;
    }
};
struct LookupIter : LookupConstIter
{
    LookupIter(LookupNode* p, const ContainerBase* owner) : LookupConstIter(p, owner)
    {}
    MapValue& dereference() const
    {
        return const_cast<MapValue&>(LookupConstIter::FUN_00b3b090());
    }
};
struct LookupCompare
{
    bool operator()(const MapKey& a, const MapKey& b) const
    {
        return a.FUN_00ac9da0(b) < 0;
    }
};
struct LookupMap : ContainerBase
{
    int auxAllocator;
    LookupCompare comp;
    int nodeAllocator, pointerAllocator, valueAllocator;
    LookupNode* head;
    unsigned size;
    LookupNode* FUN_00b3afe0(const MapKey&);
    LookupIter FUN_00b398c0(LookupConstIter, const MapValue&);
    LookupIter lower(const MapKey& key)
    {
        return LookupIter(FUN_00b3afe0(key), this);
    }
    LookupIter end()
    {
        return LookupIter(head, this);
    }
    static MapValue& value(LookupNode* p)
    {
        return p->value;
    }
    static const MapKey& key(LookupNode* p)
    {
        return value(p).first;
    }
    int& FUN_00b39210(const MapKey& sought);
};

inline const MapValue& LookupConstIter::FUN_00b3b090() const
{
    if (!this->_Has_container())
        FUN_00ec7c56();
    if (!(node != static_cast<const LookupMap*>(this->_Getmycont())->head))
        FUN_00ec7c56();
    return LookupMap::value(node);
}
// @fnv 0x00b39210
int& LookupMap::FUN_00b39210(const MapKey& sought)
{
    LookupIter where = lower(sought);
    if (where == end() || comp(sought, key(where.getNode())))
        where = FUN_00b398c0(where, MapValue(sought, int()));
    return where.dereference().second;
}

}

namespace spill_edge {
extern "C" ElQ_aceeb0* __cdecl FUN_00b36ef0(ElQ_aceeb0*, ElQ_aceeb0*, ElQ_aceeb0*, AlQ_aceeb0&);
}
namespace insert16_detail {
typedef ElQ_aceeb0 E;

struct _Scalar_ptr_iterator_tag
{
};
struct _Range_checked_iterator_tag
{
};
struct _Unchanged_checked_iterator_base_type_tag
{
};
struct _Undefined_move_tag
{
};
struct _Forward_iterator_tag
{
};
struct _Bidirectional_iterator_tag : _Forward_iterator_tag
{
};
struct _Random_access_iterator_tag : _Bidirectional_iterator_tag
{
};
template <class I> inline I _Checked_base(I& it, _Unchanged_checked_iterator_base_type_tag)
{
    return it;
}
template <class I> inline I _Checked_base(I& it)
{
    _Unchanged_checked_iterator_base_type_tag tag;
    return _Checked_base(it, tag);
}
template <class I> inline _Undefined_move_tag _Move_cat(const I&)
{
    _Undefined_move_tag cat;
    return cat;
}
template <class I, class O> inline _Scalar_ptr_iterator_tag _Ptr_cat(I&, O&)
{
    _Scalar_ptr_iterator_tag cat;
    return cat;
}
template <class I> inline _Random_access_iterator_tag iterCat(const I&)
{
    _Random_access_iterator_tag cat;
    return cat;
}
template <class I, class T> inline void scalarFill(I first, I last, const T& value)
{
    for (; first != last; ++first)
        *first = value;
}
template <class I, class T> inline void fill(I first, I last, const T& value)
{
    scalarFill(_Checked_base(first), _Checked_base(last), value);
}
template <class I, class N, class T>
inline void fillCount(I first, N count, const T& value, _Range_checked_iterator_tag)
{
    for (; 0 < count; --count, ++first)
        *first = value;
}
template <class I, class N, class T>
inline void fillCount(I first, N count, const T& value, _Random_access_iterator_tag, _Range_checked_iterator_tag)
{
    I last = first + count;
    (last);
    fillCount(_Checked_base(first), count, value, _Range_checked_iterator_tag());
}
template <class I, class N, class T> inline void unchecked_fill_n(I first, N count, const T& value)
{
    fillCount(first, count, value, iterCat(first), _Range_checked_iterator_tag());
}
template <class I, class O, class C>
inline O copyBackward(I first, I last, O dest, C, _Scalar_ptr_iterator_tag, _Range_checked_iterator_tag)
{
    int count = last - first;
    O result = dest - count;
    if (count > 0)
        memmove_s(&*result, count * sizeof(*first), &*first, count * sizeof(*first));
    return result;
}
template <class I, class O, class C>
inline O moveBackward(I first, I last, O dest, C cat, _Undefined_move_tag, _Range_checked_iterator_tag)
{
    return copyBackward(first, last, dest, cat, _Ptr_cat(first, dest), _Range_checked_iterator_tag());
}
template <class I, class O> inline _Random_access_iterator_tag iterRandom(const I&, const O&)
{
    _Random_access_iterator_tag cat;
    return cat;
}
template <class I, class O> inline O FUN_00b35e60(I first, I last, O dest)
{
    return moveBackward(_Checked_base(first), _Checked_base(last), dest, iterRandom(first, dest), _Move_cat(dest),
                        _Range_checked_iterator_tag());
}

template <class T> inline T* FUN_00b35f00(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if ((unsigned int)(-1) / count < sizeof(T))
        throw BadAlloc(0);
    return (T*)operator new(count * sizeof(T));
}

template <class I, class O, class A>
inline O copyScalar(I first, I last, O dest, A&, insert16_detail::_Scalar_ptr_iterator_tag,
                    insert16_detail::_Range_checked_iterator_tag)
{
    unsigned int count = last - first;
    O result = dest + count;
    if (count > 0)
        memmove_s(&*dest, count * sizeof(*first), &*first, count * sizeof(*first));
    return result;
}
template <class I, class O, class A> inline O FUN_00b36ef0(I first, I last, O dest, A& al)
{
    return copyScalar(insert16_detail::_Checked_base(first), insert16_detail::_Checked_base(last), dest, al,
                      insert16_detail::_Ptr_cat(first, dest), insert16_detail::_Range_checked_iterator_tag());
}

void __cdecl FUN_00b36b80(E*, unsigned int, const E&);

template <class I, class O, class A> inline O copyRaw(I first, I last, O dest, A& al)
{
    return FUN_00b36ef0(first, last, dest, al);
}
template <class I, class O, class A, class M>
inline O moveRaw(I first, I last, O dest, A& al, M, insert16_detail::_Range_checked_iterator_tag)
{
    return FUN_00b36ef0(first, last, dest, al);
}

template <class I, class O, class A, class M>
inline O moveSpillRaw(I first, I last, O dest, A& al, M, insert16_detail::_Range_checked_iterator_tag)
{
    return spill_edge::FUN_00b36ef0(first, last, dest, al);
}
template <class I, class O, class A> inline O moveUnchecked(I first, I last, O dest, A& al)
{
    return moveRaw(insert16_detail::_Checked_base(first), insert16_detail::_Checked_base(last), dest, al,
                   insert16_detail::_Move_cat(dest), insert16_detail::_Range_checked_iterator_tag());
}
template <class I, class O, class A> __forceinline O moveSpillUnchecked(I first, I last, O dest, A& al)
{
    return moveSpillRaw(insert16_detail::_Checked_base(first), insert16_detail::_Checked_base(last), dest, al,
                        insert16_detail::_Move_cat(dest), insert16_detail::_Range_checked_iterator_tag());
}
template <class I, class N, class T>
inline void fillRaw(I first, N count, const T& value, insert16_detail::_Scalar_ptr_iterator_tag,
                    insert16_detail::_Range_checked_iterator_tag)
{
    FUN_00b36b80(first, count, value);
}
template <class I, class N, class T, class A>
inline void fillRaw(I first, N count, const T& value, A&, insert16_detail::_Scalar_ptr_iterator_tag,
                    insert16_detail::_Range_checked_iterator_tag)
{
    insert16_detail::unchecked_fill_n(first, count, value);
}
template <class I, class N, class T, class A> inline void fillUnchecked(I first, N count, const T& value, A& al)
{
    fillRaw(first, count, value, al, insert16_detail::_Ptr_cat(first, first),
            insert16_detail::_Range_checked_iterator_tag());
}
template <class A> inline void destroyRaw(E*, E*, A&, insert16_detail::_Scalar_ptr_iterator_tag)
{}
template <class A> inline void destroyRaw(E* first, E* last, A& al)
{
    destroyRaw(first, last, al, insert16_detail::_Ptr_cat(first, last));
}
}

inline unsigned int Insert16Max()
{
    unsigned int count = 0x7fffffff;
    return 0 < count ? count : 1;
}
inline ElQ_aceeb0* Insert16Allocate(unsigned int count)
{
    return insert16_detail::FUN_00b35f00(count, (ElQ_aceeb0*)0);
}
inline void Insert16Deallocate(ElQ_aceeb0* ptr, unsigned int)
{
    operator delete(ptr);
}
struct Insert16Ops : VecQ_aceeb0
{
    static void FUN_00b0fb80()
    {
        throw buyUShort::BxLengthError("vector<T> too long");
    }
    template <class I> ElQ_aceeb0* move(I first, I last, ElQ_aceeb0* ptr)
    {
        return insert16_detail::moveUnchecked(first, last, ptr, _Alval);
    }
    template <class I> __forceinline ElQ_aceeb0* moveSpill(I first, I last, ElQ_aceeb0* ptr)
    {
        return insert16_detail::moveSpillUnchecked(first, last, ptr, _Alval);
    }
    ElQ_aceeb0* FUN_00b35580(ElQ_aceeb0* ptr, unsigned int count, const ElQ_aceeb0& value)
    {
        insert16_detail::fillUnchecked(ptr, count, value, _Alval);
        return ptr + count;
    }
    void destroy(ElQ_aceeb0* first, ElQ_aceeb0* last)
    {
        insert16_detail::destroyRaw(first, last, _Alval);
    }
};
// @fnv 0x00b34e10
void VecQ_aceeb0::FUN_00b34e10(CItQ_aceeb0 _Where, unsigned int _Count, const ElQ_aceeb0& _Val)
{

    unsigned int _Capacity = capacity();

    if (_Count == 0)
        ;
    else if (Insert16Max() - size() < _Count)
        Insert16Ops::FUN_00b0fb80();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = Insert16Max() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ElQ_aceeb0* _Newvec = Insert16Allocate(_Capacity);
        ElQ_aceeb0* _Ptr = _Newvec;

        try
        {
            _Ptr = static_cast<Insert16Ops*>(this)->move(this->_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = static_cast<Insert16Ops*>(this)->FUN_00b35580(_Ptr, _Count, _Val);
            static_cast<Insert16Ops*>(this)->move(_Where._Myptr, this->_Mylast, _Ptr);
        }
        catch (...)
        {
            static_cast<Insert16Ops*>(this)->destroy(_Newvec, _Ptr);
            Insert16Deallocate(_Newvec, _Capacity);
            throw;
        }

        _Count += size();
        if (_Myfirst != 0)
        {
            static_cast<Insert16Ops*>(this)->destroy(_Myfirst, _Mylast);
            Insert16Deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where._Myptr) < _Count)
    {
        ElQ_aceeb0 _Tmp = _Val;

        static_cast<Insert16Ops*>(this)->moveSpill(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try
        {
            static_cast<Insert16Ops*>(this)->FUN_00b35580(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            static_cast<Insert16Ops*>(this)->destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        insert16_detail::fill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        ElQ_aceeb0 _Tmp = _Val;

        ElQ_aceeb0* _Oldend = _Mylast;
        _Mylast = static_cast<Insert16Ops*>(this)->move(_Oldend - _Count, _Oldend, _Mylast);

        insert16_detail::FUN_00b35e60((unsigned short*)_Where._Myptr, (unsigned short*)(_Oldend - _Count),
                                      (unsigned short*)_Oldend);
        insert16_detail::fill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

namespace ShortFill {
struct ScalarCategory
{
};
struct CheckedCategory
{
};
struct IdentityCategory
{
};
struct InputCategory
{
};
struct ForwardCategory : InputCategory
{
};
struct BidirectionalCategory : ForwardCategory
{
};
struct RandomCategory : BidirectionalCategory
{
};

template <class P> inline ScalarCategory ClassifyPointer(P&, P&)
{
    ScalarCategory result;
    return result;
}

template <class P> inline RandomCategory ClassifyIterator(const P&)
{
    RandomCategory result;
    return result;
}

template <class P> inline P Base(P& first, IdentityCategory)
{
    return first;
}

template <class P> inline P Base(P& first)
{
    IdentityCategory category;
    return Base(first, category);
}

template <class P, class N, class V> inline void AssignLoop(P first, N count, const V& value, CheckedCategory)
{
    for (; count > 0; --count, ++first)
        *first = value;
}

template <class P, class N, class V>
inline void AssignRange(P first, N count, const V& value, RandomCategory, CheckedCategory)
{
    P end = first + count;
    (void)end;
    AssignLoop(Base(first), count, value, CheckedCategory());
}

extern "C" inline void __cdecl FUN_00b36b80(unsigned short* first, unsigned count, const unsigned short& value)
{
    AssignRange(first, count, value, ClassifyIterator(first), CheckedCategory());
}

template <class P, class N, class V, class A>
inline void InitializeScalar(P first, N count, const V& value, A&, ScalarCategory, CheckedCategory)
{
    FUN_00b36b80(first, count, value);
}

template <class P, class N, class V, class A> inline void Initialize(P first, N count, const V& value, A& allocator)
{
    InitializeScalar(first, count, value, allocator, ClassifyPointer(first, first), CheckedCategory());
}

struct Receiver : VecQ_aceeb0
{
    unsigned short* Fill(unsigned short* first, unsigned count, const unsigned short& value)
    {
        Initialize(first, count, value, _Alval);
        return first + count;
    }
    unsigned short* FUN_00b35580(unsigned short* first, unsigned count, const unsigned short& value);
};

// @fnv 0x00b35580
unsigned short* Receiver::FUN_00b35580(unsigned short* first, unsigned count, const unsigned short& value)
{
    return Fill(first, count, value);
}
}

struct Scalar313
{
};
template <class T> inline Scalar313 scalarCategory313(T*&, T*&)
{
    Scalar313 tag;
    return tag;
}
template <class T> struct Value313 : ContainerAlloc31<Alloc31<T> >
{
    Alloc31<T> al;
    Value313(Alloc31<T> a = Alloc31<T>()) : ContainerAlloc31<Alloc31<T> >(a), al(a)
    {}
};
template <class T, class A> inline void destroyRange313(T* a, T* b, A& al, Scalar313)
{}
template <class T, class A> inline void destroyRange313(T* a, T* b, A& al)
{
    destroyRange313(a, b, al, scalarCategory313(a, b));
}
struct Elem313 : Value313<unsigned short>
{
    unsigned short* first;
    unsigned short* last;
    unsigned short* end;
    Elem313()
    {
        buy(0);
    }
    unsigned max_size() const
    {
        return al.max_size();
    }
    static void tooLong()
    {
        throw buyUShort::BxLengthError("vector<T> too long");
    }
    bool buy(unsigned n)
    {
        first = 0, last = 0, end = 0;
        if (n == 0)
            return false;
        else if (max_size() < n)
            tooLong();
        else
        {
            first = al.allocate(n);
            last = first;
            end = first + n;
        }
        return true;
    }
    void destroy(unsigned short* a, unsigned short* b)
    {
        destroyRange313(a, b, al);
    }
    void FUN_00b34d90()
    {
        if (first != 0)
        {
            destroy(first, last);
            al.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
    ~Elem313()
    {
        FUN_00b34d90();
    }
};
template <class T> struct Vector313 : ContainerAlloc31<Alloc31<T> >
{
    Alloc31<T> al;
    Vector313(Alloc31<T> a = Alloc31<T>()) : ContainerAlloc31<Alloc31<T> >(a), al(a)
    {}
    T* first;
    T* last;
    T* end;
    unsigned max_size() const
    {
        return al.max_size();
    }
    static void tooLong()
    {
        throw buyUShort::BxLengthError("vector<T> too long");
    }
    bool buy(unsigned n)
    {
        first = 0, last = 0, end = 0;
        if (n == 0)
            return false;
        else if (max_size() < n)
            tooLong();
        else
        {
            first = al.allocate(n);
            last = first;
            end = first + n;
        }
        return true;
    }
    T* fillNew(T*, unsigned, const T&);
    void tidy();
    void FUN_00b32780(unsigned n, const T& v)
    {
        if (buy(n))
        {
            try
            {
                last = fillNew(first, n, v);
            }
            catch (...)
            {
                tidy();
                throw;
            }
        }
    }
};
struct FUN_00b31350 : Vector313<Elem313>
{
    explicit FUN_00b31350(unsigned n);
};
// @fnv 0x00b31350
FUN_00b31350::FUN_00b31350(unsigned n)
{
    FUN_00b32780(n, Elem313());
}

struct S00b360a0_Base
{
    void* allocation;
    ~S00b360a0_Base()
    {
        void* p = allocation;
        FormHeap_Free(p);
    }
};
struct S00b360a0_Vec : S00b360a0_Base
{
    int unk04;
    int unk08;
    short* begin;
    short* end;
    short* capacity;
    S00b360a0_Vec(const S00b360a0_Vec&);
    void FUN_00b34d90();
    ~S00b360a0_Vec()
    {
        FUN_00b34d90();
    }
};
inline void S00b360a0_Reserve()
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
}
// @fnv 0x00b360a0
void FUN_00b360a0(S00b360a0_Vec* current, unsigned int count, const S00b360a0_Vec& value)
{
    S00b360a0_Vec* first = current;
    try
    {
        for (; count > 0; --count, ++current)
        {
            S00b360a0_Vec* destination = current;
            new (destination) S00b360a0_Vec(value);
            S00b360a0_Reserve();
        }
    }
    catch (...)
    {
        for (; first != current; ++first)
            first->~S00b360a0_Vec();
        throw;
    }
}

namespace fnv_00b3a050 {
extern unsigned int DAT_010173f0;
namespace treeb3a {
void FUN_00ec7c56();
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
    BxString() : BxStringVal()
    {
        _Tidy();
    }
    BxString& operator=(const BxString& _Right)
    {
        return assign(_Right);
    }
    BxString& assign(const BxString& _Right)
    {
        return assign(_Right, 0, DAT_010173f0);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, DAT_010173f0);
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
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        do
        {
        } while (0);
        return _Myptr()[_Off];
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
    const char& operator[](unsigned int _Off) const
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
        return _Myptr()[_Off];
    }
    BxString& append(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Num < _Count)
        {
            _Count = _Num;
        }
        if (DAT_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        {
            _Xlen();
        }
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return append(*this, _Ptr - _Myptr(), _Count);
        }
        if (DAT_010173f0 - _Mysize <= _Count)
        {
            _Xlen();
        }
        unsigned int _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& append(const char* _Ptr)
    {
        return append(_Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& operator+=(const char* _Ptr)
    {
        return append(_Ptr);
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
template <class T> inline void TrDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
struct TrPair
{
    BxString first;
    int second;
};
struct TrValAlloc
{
    void destroy(TrPair* _Ptr)
    {
        TrDestroyOne(_Ptr);
    }
};
struct TrNode
{
    TrNode* _Left;
    TrNode* _Parent;
    TrNode* _Right;
    TrPair _Myval;
    char _Color;
    char _Isnil;
};
struct TrNodeAlloc
{
    void destroy(TrNode* _Ptr)
    {
        TrDestroyOne(_Ptr);
    }
    void deallocate(TrNode* _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
};
struct TrTree
{
    int unk00;
    TrValAlloc _Alval;
    TrNodeAlloc _Alnod;
    static char& _Isnil(TrNode* _Pnode)
    {
        return (char&)(*_Pnode)._Isnil;
    }
    static TrNode*& _Left(TrNode* _Pnode)
    {
        return (TrNode*&)(*_Pnode)._Left;
    }
    static TrNode*& _Right(TrNode* _Pnode)
    {
        return (TrNode*&)(*_Pnode)._Right;
    }
    static TrPair& _Myval(TrNode* _Pnode)
    {
        return (TrPair&)(*_Pnode)._Myval;
    }
    void FUN_00b3a050(TrNode* _Rootnode);
};
}
using namespace treeb3a;

// @fnv 0x00b3a050
void TrTree::FUN_00b3a050(TrNode* _Rootnode)
{
    for (TrNode* _Pnode = _Rootnode; !_Isnil(_Pnode); _Rootnode = _Pnode)
    {
        FUN_00b3a050(_Right(_Pnode));
        _Pnode = _Left(_Pnode);
        this->_Alnod.destroy(_Rootnode);
        this->_Alnod.deallocate(_Rootnode, 1);
    }
}
}  // namespace fnv_00b3a050

namespace fnv_00b3d830 {
void __cdecl operator delete(void* _Ptr) throw();
namespace vct3d830 {
void FUN_00ec7c56();
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
struct BxException;
struct BxBadAlloc;
template <class T> inline T* BxAllocate(unsigned int count, T*);
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
    BxException(const char* const& _What);
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxBadAlloc : public BxException
{
    BxBadAlloc(const char* _Message = "bad allocation") throw() : BxException(_Message)
    {}
    virtual ~BxBadAlloc() throw()
    {}
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

template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned short*, unsigned short*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class O, class D, class T> inline void GvFillN(O _First, D _Count, const T& _Val, GvRangeCheckedTag)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class O, class D, class T, class C>
inline void GvFillN(O _First, D _Count, const T& _Val, C, GvRangeCheckedTag)
{
    GvFillN(_First, _Count, _Val, GvRangeCheckedTag());
}
template <class O, class D, class T>
inline void GvFillN(O _First, D _Count, const T& _Val, GvRandomTag, GvRangeCheckedTag)
{
    O _Last = _First + _Count;
    (void)_Last;
    GvFillN(GvCheckedBase(_First), _Count, _Val, GvRangeCheckedTag());
}
template <class I> inline GvRandomTag GvIterCat(const I&)
{
    GvRandomTag _Cat;
    return _Cat;
}
template <class O, class D, class T> inline void GvUncheckedFillValues(O _First, D _Count, const T& _Val)
{
    GvFillN(_First, _Count, _Val, GvIterCat(_First), GvRangeCheckedTag());
}
template <class T, class A>
inline void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A&, GvScalarTag, GvRangeCheckedTag)
{
    GvUncheckedFillValues(_First, _Count, _Val);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    F _Result = _Dest + _Count;
    if (_Count > 0)
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return _Result;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    explicit GvVector(unsigned int _Count) : GvVectorVal<T>()
    {
        _Construct_n(_Count, T());
    }
    void _Construct_n(unsigned int _Count, const T& _Val)
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
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return false;
        else if (max_size() < _Capacity)
            _Xlen();
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
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
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
struct GvItem;
template <class T> struct GvVectorStore : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVectorStore(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
            return false;
        else if (max_size() < _Capacity)
            _Xlen();
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
};
struct GvRow54
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
};
}
using namespace vct3d830;
struct FUN_00b3d830 : GvVectorStore<GvRow54>
{
    FUN_00b3d830();
};
// @fnv 0x00b3d830
FUN_00b3d830::FUN_00b3d830() : GvVectorStore<GvRow54>()
{
    _Buy(0);
}
}  // namespace fnv_00b3d830

namespace vector_count_release {
typedef FUN_00aa7830_cls Element;
struct Checked
{
};
struct Unchanged
{
};
struct NonScalar
{
};
struct UndefinedMove
{
};
struct Input
{
};
struct Forward : Input
{
};
struct Bidirectional : Forward
{
};
struct Random : Bidirectional
{
};

template <class I> inline I checkedBase(I& it, Unchanged)
{
    return it;
}
template <class I> inline I checkedBase(I& it)
{
    Unchanged tag;
    return checkedBase(it, tag);
}
template <class I> inline UndefinedMove moveCategory(const I&)
{
    UndefinedMove tag;
    return tag;
}
template <class I, class O> inline NonScalar pointerCategory(I&, O&)
{
    NonScalar tag;
    return tag;
}
template <class I, class O> inline Random iteratorCategory(const I&, const O&)
{
    Random tag;
    return tag;
}

struct AllocationError
{
    const char* message;
    bool owned;
    AllocationError(const char*);
    virtual ~AllocationError();
};
struct Text
{
    unsigned int allocator;
    union Buffer
    {
        char local[16];
        char* pointer;
    } buffer;
    unsigned int length;
    unsigned int capacity;
    Text(const char*);
    Text(const Text&);
    ~Text();
};
struct LogicError : AllocationError
{
    Text text;
    LogicError(const Text&);
};
struct LengthError : LogicError
{
    LengthError(const Text& message) : LogicError(message)
    {}
    virtual ~LengthError()
    {}
};
template <class T> inline T* FUN_00b23aa0(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if (0xffffffffU / count < sizeof(T))
        throw AllocationError(0);
    return (T*)operator new(count * sizeof(T));
}
template <class T> struct Constructed
{
    T value;
    Constructed(const T& source) : value(source)
    {}
    static void* operator new(unsigned int, void* storage)
    {
        return storage;
    }
    static void operator delete(void*, void*)
    {}
};
template <class T, class V> inline void constructOne(T* dest, const V& value)
{
    void* storage = dest;
    new (storage) Constructed<T>(value);
}
template <class T> inline void destroyOne(T* value)
{
    value->~T();
}
template <class T> struct Allocator
{
    typedef T* pointer;
    T* allocate(unsigned int count)
    {
        return FUN_00b23aa0(count, (T*)0);
    }
    void deallocate(T* storage, unsigned int)
    {
        operator delete(storage);
    }
    void construct(T* dest, const T& value)
    {
        constructOne(dest, value);
    }
    void destroy(T* value)
    {
        destroyOne(value);
    }
    unsigned int max_size() const
    {
        unsigned int count = 0xffffffffU / sizeof(T);
        return 0 < count ? count : 1;
    }
};
template <class A>
inline void destroyRange(typename A::pointer first, typename A::pointer last, A& allocator, NonScalar)
{
    for (; first != last; ++first)
        allocator.destroy(first);
}
template <class A> inline void destroyRange(typename A::pointer first, typename A::pointer last, A& allocator)
{
    destroyRange(first, last, allocator, pointerCategory(first, last));
}
template <class I, class O, class A> inline O copyRaw(I first, I last, O dest, A& allocator, NonScalar, Checked)
{
    O next = dest;
    try
    {
        for (; first != last; ++dest, ++first)
            allocator.construct(dest, *first);
    }
    catch (...)
    {
        for (; next != dest; ++next)
            allocator.destroy(next);
        throw;
    }
    return dest;
}
template <class I, class O, class A> inline O FUN_00b3b5a0(I first, I last, O dest, A& allocator)
{
    return copyRaw(checkedBase(first), checkedBase(last), dest, allocator, pointerCategory(first, dest), Checked());
}
template <class I, class O, class A, class M> inline O moveRaw(I first, I last, O dest, A& allocator, M, Checked)
{
    return FUN_00b3b5a0(first, last, dest, allocator);
}
template <class I, class O, class A> inline O FUN_00b3b6f0(I first, I last, O dest, A& allocator)
{
    return moveRaw(checkedBase(first), checkedBase(last), dest, allocator, moveCategory(dest), Checked());
}
template <class O, class N, class V, class A>
inline void FUN_00b3b5f0(O first, N count, const V& value, A& allocator, NonScalar, Checked)
{
    O next = first;
    try
    {
        for (; 0 < count; --count, ++first)
            allocator.construct(first, value);
    }
    catch (...)
    {
        for (; next != first; ++next)
            allocator.destroy(next);
        throw;
    }
}
template <class O, class N, class V, class A> inline void fillRaw(O first, N count, const V& value, A& allocator)
{
    FUN_00b3b5f0(first, count, value, allocator, pointerCategory(first, first), Checked());
}
template <class I, class O, class C> inline O copyBackward(I first, I last, O dest, C, NonScalar, Checked)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
template <class I, class O> inline O copyBackward(I first, I last, O dest, Random, NonScalar, Checked)
{
    O result = dest - (last - first);
    copyBackward(first, last, checkedBase(dest), Forward(), NonScalar(), Checked());
    return result;
}
template <class I, class O, class C, class M> inline O moveBackward(I first, I last, O dest, C category, M, Checked)
{
    return copyBackward(first, last, dest, category, pointerCategory(first, dest), Checked());
}
template <class I, class O> inline O FUN_00b16a10(I first, I last, O dest)
{
    return moveBackward(checkedBase(first), checkedBase(last), dest, iteratorCategory(first, dest), moveCategory(dest),
                        Checked());
}
template <class I, class V> inline void fillLoop(I first, I last, const V& value)
{
    for (; first != last; ++first)
        *first = value;
}
template <class I, class V> inline void fill(I first, I last, const V& value)
{
    fillLoop(checkedBase(first), checkedBase(last), value);
}
struct IteratorOwner
{
    void* proxy;
};
struct Iterator : IteratorOwner
{
    Element* _Myptr;
};
struct ProxyStorage
{
    void* proxy;
    unsigned int proxyAllocator;
};
struct InsertCountVector : ProxyStorage
{
    typedef unsigned int size_type;
    typedef Element value_type;
    typedef Element* pointer;
    typedef Iterator const_iterator;
    Allocator<Element> _Alval;
    Element* _Myfirst;
    Element* _Mylast;
    Element* _Myend;
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type max_size() const
    {
        return _Alval.max_size();
    }
    static void FUN_00b0fb80()
    {
        throw LengthError("vector<T> too long");
    }
    void _Destroy(pointer first, pointer last)
    {
        destroyRange(first, last, _Alval);
    }
    template <class I> pointer _Umove(I first, I last, pointer dest)
    {
        return FUN_00b3b6f0(first, last, dest, _Alval);
    }
    pointer _Ufill(pointer dest, size_type count, const value_type& value)
    {
        fillRaw(dest, count, value, _Alval);
        return dest + count;
    }
    void FUN_00b3a0d0(const_iterator, size_type, const value_type&);
};

// @fnv 0x00b3a0d0
void InsertCountVector::FUN_00b3a0d0(const_iterator position, size_type insertCount, const value_type& insertValue)
{

    size_type capacityLimit = capacity();

    if (insertCount == 0)
        ;
    else if (max_size() - size() < insertCount)
        FUN_00b0fb80();
    else if (capacityLimit < size() + insertCount)
    {
        capacityLimit = max_size() - capacityLimit / 2 < capacityLimit ? 0 : capacityLimit + capacityLimit / 2;
        if (capacityLimit < size() + insertCount)
            capacityLimit = size() + insertCount;
        pointer newStorage = this->_Alval.allocate(capacityLimit);
        pointer constructedEnd = newStorage;

        try
        {
            constructedEnd = _Umove(this->_Myfirst, position._Myptr, newStorage);
            constructedEnd = _Ufill(constructedEnd, insertCount, insertValue);
            _Umove(position._Myptr, this->_Mylast, constructedEnd);
        }
        catch (...)
        {
            _Destroy(newStorage, constructedEnd);
            this->_Alval.deallocate(newStorage, capacityLimit);
            throw;
        }

        insertCount += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }

        _Myend = newStorage + capacityLimit;
        _Mylast = newStorage + insertCount;
        _Myfirst = newStorage;
    }
    else if ((size_type)(_Mylast - position._Myptr) < insertCount)
    {
        value_type savedValue = insertValue;

        _Umove(position._Myptr, _Mylast, position._Myptr + insertCount);

        try
        {
            _Ufill(_Mylast, insertCount - (_Mylast - position._Myptr), savedValue);
        }
        catch (...)
        {
            _Destroy(position._Myptr + insertCount, _Mylast + insertCount);
            throw;
        }

        _Mylast += insertCount;

        fill(position._Myptr, _Mylast - insertCount, savedValue);
    }
    else
    {
        value_type savedValue = insertValue;

        pointer oldEnd = _Mylast;
        _Mylast = _Umove(oldEnd - insertCount, oldEnd, _Mylast);

        FUN_00b16a10(position._Myptr, oldEnd - insertCount, oldEnd);
        fill(position._Myptr, position._Myptr + insertCount, savedValue);
    }
}

}

struct ByteVector18
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char* begin;
    unsigned char* end;
    unsigned char* cap;
    __forceinline unsigned char& at(unsigned int index)
    {
        if (index >= (unsigned int)(end - begin))
            FUN_00ec7c56();
        return begin[index];
    }
};
struct FloatVector18
{
    int unk00;
    int unk04;
    int unk08;
    float* begin;
    float* end;
    float* cap;
    __forceinline float& at(unsigned int index)
    {
        if (index >= (unsigned int)(end - begin))
            FUN_00ec7c56();
        return begin[index];
    }
};
bool __cdecl FUN_00b0d7a0();
struct Params18
{
    float x;
    float y;
    float z;
    float unk0c;
    float unk10;
    float w;
};
struct Target18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    unsigned short index;
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
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    FloatVector18 values;
    ByteVector18 types;
    void __thiscall FUN_00b301f0(float* values, int flags);
    void __thiscall FUN_00b31070(unsigned char type, Params18* params);
};
static __forceinline float Lerp18(const float& t, float a, float b)
{
    return a + (b - a) * t;
}
// @fnv 0x00b31070
void Target18::FUN_00b31070(unsigned char type, Params18* params)
{
    float result[2];
    if (type == types.at(index))
    {
        result[0] = Lerp18(values.at(2 * index), params->z, params->x);
        result[1] = Lerp18(values.at(2 * index + 1), params->w, params->y);
        if (FUN_00b0d7a0())
            result[1] = -result[1];
        FUN_00b301f0(result, -1);
    }
}
