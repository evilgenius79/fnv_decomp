// src/staging/blk_00b20000_od_ob1_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00b20000_od.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Ob1 /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


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
unsigned int FUN_00ec7c56();
struct FUN_00b2ac30_t
{
    int* m_00;
    int m_04;
    bool FUN_00b2ac30(FUN_00b2ac30_t* other);
};
extern const double DAT_010a4d90;
double __cdecl FUN_00ec9f30(double value);
double __cdecl FUN_00eca060(double value);
struct Mat
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    void __thiscall FUN_00b12af0();
    Mat* __thiscall Multiply(Mat* out, Mat* rhs);
    void __thiscall FUN_00b273d0(float angle);
};
struct ElemAlloc
{
    char c;
};
void __cdecl FUN_00b35ca0(int* pFirst, unsigned int ItemUpdateArray, const int& kVal, ElemAlloc& kAl);
class IntVector
{
  public:
    int m_00;
    int m_04;
    ElemAlloc m_kAl;
    int* m_pFirst;
    int* m_pLast;
    int* m_pRecordEnd;

    bool ResizeArray(unsigned int ItemUpdateArray);
    void FUN_00b17f50();
    void FUN_00b32600(unsigned int ItemUpdateArray, const int& kVal);
};
struct S_00b3db50
{
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    void FUN_00b3db50();
};
struct Item32780
{
    int m_00, m_04, m_08, m_0c, m_10, m_14;
};
struct Tag32780
{
    unsigned char v;
};
struct Vec32780
{
    int m_00, m_04, m_08;
    Item32780* m_0c;
    Item32780* m_10;
    bool FUN_00b1f590(int n);
    void FUN_00b32c60();
    void FUN_00b32780(int n, const Item32780* value);
};
extern void __cdecl FUN_00b360a0(Item32780*, int, const Item32780*, void*, unsigned char, unsigned char);
extern "C" void* __cdecl FUN_00b35b60(unsigned int, unsigned int, unsigned int);
struct S_B33030
{
    int unk00[3];
    unsigned int m_pHeadNode;
    unsigned int m_last;
    unsigned int m_kRayEnd;

    void __thiscall FUN_00b33110(unsigned int, unsigned int);

    ProbePair FUN_00b33030(ProbePair first, ProbePair last);
};
struct CheckedTag
{
    bool value;
};
struct ScalarTag
{
    bool value;
};
struct RandomTag
{
    bool value;
};
void FUN_00b36b80(unsigned short* dst, unsigned int count, const unsigned short* src);
#include <string.h>
struct FUN_00b29fd0_Params
{
    float f00;
    float f04;
    float f08;
    float f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
};
struct FUN_00b29fd0_cls
{
    int unk00;
    FUN_00b29fd0_Params m_04;
    int unk38;
    FUN_00b29fd0_Params m_3c;
    float unk70;
    int unk74;
    int unk78;
    FUN_00b29fd0_Params m_7c;
    FUN_00b29fd0_cls* FUN_00b29fd0();
};
struct FUN_00b3f070 : FUN_00b3f0a0_Class
{
    void FUN_00b3f0a0();
    virtual ~FUN_00b3f070();
};

namespace eraseb2d {
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
typedef AsObj* AsElem;
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
    AsIterator FUN_00b2def0(AsConstIterator _Where);
};
inline AsConstIterator::AsConstIterator(AsElem* _Ptr, const AsContainer* _Pvector)
{
    if (!(_Pvector != 0 && ((AsVector*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((AsVector*)_Pvector)->_Mylast))
        FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
}
using namespace eraseb2d;

// @fnv 0x00b2def0
AsIterator AsVector::FUN_00b2def0(AsConstIterator _Where)
{
    AsUncheckedCopy(_Where._Myptr + 1, _Mylast, _Where._Myptr);
    _Destroy(_Mylast - 1, _Mylast);
    --_Mylast;
    return AsIterator(_Where._Myptr, this);
}

#include <vector>
#include <stdexcept>

struct PointerVectorStorage : ::std::_Container_base_aux_alloc_real< ::std::allocator<void*> >
{
    typedef ::std::_Container_base_aux_alloc_real< ::std::allocator<void*> > StorageBase;
    typedef ::std::vector<void*>::const_iterator ReadIterator;
    ::std::allocator<void*> _Alval;
    PointerVectorStorage(::std::allocator<void*> source) : StorageBase(source), _Alval(source)
    {}
    void** first;
    void** last;
    void** limit;

    unsigned int size() const
    {
        return last - first;
    }
    ReadIterator begin() const
    {
        return ReadIterator(first, this);
    }
    ReadIterator end() const
    {
        return ReadIterator(last, this);
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    static void tooLong()
    {
        throw ::std::length_error("vector<T> too long");
    }
    bool ResizeArray(unsigned int count)
    {
        first = 0, last = 0, limit = 0;
        if (count == 0)
            return false;
        else if (max_size() < count)
            tooLong();
        else
        {
            first = _Alval.allocate(count);
            last = first;
            limit = first + count;
        }
        return true;
    }
    void destroy(void** start, void** finish)
    {
        ::std::_Destroy_range(start, finish, _Alval);
    }
    void FUN_00b17f50()
    {
        if (first)
        {
            destroy(first, last);
            _Alval.deallocate(first, limit - first);
        }
        first = 0, last = 0, limit = 0;
    }

    void** copyInto(ReadIterator start, ReadIterator finish, void** output)
    {
        return ::stdext::unchecked_uninitialized_copy(start, finish, output, _Alval);
    }
};

struct FUN_00b355d0 : PointerVectorStorage
{
    FUN_00b355d0(const FUN_00b355d0& source);
};

// @fnv 0x00b355d0
FUN_00b355d0::FUN_00b355d0(const FUN_00b355d0& source) : PointerVectorStorage(source._Alval)
{
    if (ResizeArray(source.size()))
    {
        try
        {
            last = copyInto(source.begin(), source.end(), first);
        }
        catch (...)
        {
            FUN_00b17f50();
            throw;
        }
    }
}
