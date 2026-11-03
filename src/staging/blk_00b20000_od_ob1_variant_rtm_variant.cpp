// src/staging/blk_00b20000_od_ob1_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00b20000_od_ob1_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
void* __cdecl FUN_00b2e4a0(unsigned int count);
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
FUN_00b2e740* FUN_00b2e570(FUN_00b2e740* first, FUN_00b2e740* last, FUN_00b2e740* dest);
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
unsigned short* __cdecl FUN_00b35c30(unsigned short* first, unsigned short* last, unsigned short* end);
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
void __cdecl FUN_00b35ca0(unsigned int* first, unsigned count, const unsigned int& value, void* allocator);
struct BoundsB3
{
    FUN_00aa7830_cls lower;
    FUN_00aa7830_cls upper;
    BoundsB3 FUN_00b3c9a0(const BoundsB3& other);
};
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
V24* FUN_00b35b60(V24* _First, V24* _Last, V24* _Dest);
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
CopyValue* __cdecl FUN_00b36000(CopyValue* first, CopyValue* last, CopyValue* dest);
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

namespace UShortRawCopyDetail {
struct ScalarTag
{
};
struct RangeTag
{
};
struct BaseTag
{
};

template <class I, class O> inline ScalarTag category(const I&, const O&)
{
    ScalarTag tag;
    return tag;
}

inline unsigned short* pointer(const _Vector_const_iteratorS<unsigned short>* it)
{
    return it->_Myptr;
}

inline unsigned short* base(const _Vector_const_iteratorS<unsigned short>& it, BaseTag)
{
    return pointer(&it);
}

inline unsigned short* base(const _Vector_const_iteratorS<unsigned short>& it)
{
    BaseTag tag;
    return base(it, tag);
}

template <class I, class O, class A> inline O copy(I first, I last, O dest, A&, ScalarTag, RangeTag)
{
    unsigned int count = (unsigned int)(last - first);
    O result = dest + count;
    if (count > 0)
        FUN_00ec7ce3(dest, count * sizeof(*first), first, count * sizeof(*first));
    return result;
}
}

// @fnv 0x00b362c0
unsigned short* __cdecl FUN_00b362c0(_Vector_const_iteratorS<unsigned short> first,
                                     _Vector_const_iteratorS<unsigned short> last, unsigned short* dest,
                                     allocatorS<unsigned short>& alloc)
{
    return UShortRawCopyDetail::copy(UShortRawCopyDetail::base(first), UShortRawCopyDetail::base(last), dest, alloc,
                                     UShortRawCopyDetail::category(first._Myptr, dest),
                                     UShortRawCopyDetail::RangeTag());
}

namespace scalar_copy_detail {
struct ScalarPointer
{
};
struct CheckedRange
{
};
struct UnchangedBase
{
};

template <class T> inline T checkedBase(T& iterator, UnchangedBase)
{
    return iterator;
}
template <class T> inline T checkedBase(T& iterator)
{
    UnchangedBase tag;
    return checkedBase(iterator, tag);
}
template <class T, class U> inline ScalarPointer pointerCategory(T&, U&)
{
    ScalarPointer tag;
    return tag;
}
template <class Input, class Output>
inline Output initialize(Input first, Input last, Output dest, ScalarPointer, CheckedRange)
{
    unsigned int count = unsigned(last - first);
    Output result = dest + count;
    if (count > 0)
        memmove_s(&*dest, count * sizeof(*first), &*first, count * sizeof(*first));
    return result;
}
}

// @fnv 0x00b36ef0
unsigned short* __cdecl FUN_00b36ef0(unsigned short* first, unsigned short* last, unsigned short* dest)
{
    return scalar_copy_detail::initialize(scalar_copy_detail::checkedBase(first), scalar_copy_detail::checkedBase(last),
                                          dest, scalar_copy_detail::pointerCategory(first, dest),
                                          scalar_copy_detail::CheckedRange());
}
