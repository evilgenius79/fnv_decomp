
// src/speedtree/frondengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/frondengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b1ada0_class
{
    float a;
    float b;
    float c;
    FUN_00b1ada0_class* FUN_00b1ada0(float x, float y, float z);
};

// Stores x, y and z into the object's a, b and c fields and returns this.
// @fnv 0x00b1ada0
FUN_00b1ada0_class* FUN_00b1ada0_class::FUN_00b1ada0(float x, float y, float z)
{
    a = x;
    b = y;
    c = z;
    return this;
}

struct FUN_00b1add0
{
    float f0;
    float f4;
    float f8;
    void Set(float a, float b, float c);
};

// Stores the three float arguments into the object's f0, f4 and f8 fields.
// @fnv 0x00b1add0
void FUN_00b1add0::Set(float a, float b, float c)
{
    f0 = a;
    f4 = b;
    f8 = c;
}

struct FUN_00b39460_class
{
    void __thiscall FUN_00b39460();
};

// Frees the pointer stored at the start of this object via operator delete.
// @fnv 0x00b39460
void __thiscall FUN_00b39460_class::FUN_00b39460()
{
    void* v = *(void**)this;
    operator delete(v);
}

struct FUN_0064df10_helper
{
    void* p;
    void __thiscall deallocate(void* a, unsigned int b);
};
struct Date
{
    void* p;
    ~Date();
};
struct FUN_0065d6e0_class : Date
{
    ~FUN_0065d6e0_class();
};
// Destructor that calls deallocate on the helper at offset 4 with the stored pointer and size 1.
// @fnv 0x0065d6e0
FUN_0065d6e0_class::~FUN_0065d6e0_class()
{
    ((FUN_0064df10_helper*)((char*)this + 4))->deallocate(p, 1);
}

unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_00b1db00_class
{
    int i0;
    int i4;
    int i8;
    int ic;
    int i10;
    unsigned int __thiscall FUN_00b1db00(unsigned int a);
};
// Bounds-checks index a against (i10 - ic) / 56, calls FUN_00ec7c56 if out of range, and returns ic + a * 56.
// @fnv 0x00b1db00
unsigned int __thiscall FUN_00b1db00_class::FUN_00b1db00(unsigned int uiIndex)
{
    if (uiIndex >= (unsigned int)((i10 - ic) / 56))
        FUN_00ec7c56();
    return uiIndex * 56 + (unsigned int)ic;
}

namespace fnv_00b1ff00 {
extern "C" unsigned int __cdecl FUN_00ec7c56(void);

struct FUN_00b1ff00_class
{
    int x;
    int y;
    int FUN_00b1ff00(FUN_00b1ff00_class* other);
};

// Calls FUN_00ec7c56 unless this->x is nonzero and equal to other->x, then returns (this->y - other->y) / 0x38.
// @fnv 0x00b1ff00
int FUN_00b1ff00_class::FUN_00b1ff00(FUN_00b1ff00_class* other)
{
    if (!static_cast<bool>(static_cast<int>(this->x != 0)) || !static_cast<bool>(static_cast<int>(this->x == other->x)))
        FUN_00ec7c56();
    return (this->y - other->y) / 0x38;
}
}  // namespace fnv_00b1ff00

unsigned int __cdecl FUN_00ec7c56(void);

struct FUN_00b30fd0_class
{
    unsigned int FUN_00b30fd0(unsigned int n);
};

// Doubles n, bounds-checks it against the element count in the array at this+0x100, and returns the address of the element at that index.
// @fnv 0x00b30fd0
unsigned int FUN_00b30fd0_class::FUN_00b30fd0(unsigned int uiIndex)
{
    unsigned int count = uiIndex << 1;
    char* p = (char*)this + 0x100;
    if (count >= (*(int*)(p + 0x10) - *(int*)(p + 0xc)) >> 2)
        FUN_00ec7c56();
    return *(unsigned int*)(p + 0xc) + count * 4;
}

struct FUN_00b319a0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int __thiscall FUN_00b319a0(int n);
};
unsigned int __cdecl FUN_00ec7c56();
// @fnv 0x00b319a0
int __thiscall FUN_00b319a0_class::FUN_00b319a0(int uiIndex)
{
    if (uiIndex >= (unsigned int)((m_10 - m_iThirdValue) / 24))
        FUN_00ec7c56();
    return uiIndex * 24 + m_iThirdValue;
}

void __cdecl operator delete(void*);
struct FUN_00b1ec70_class
{
    int i0;
    int i4;
    int i8;
    int* p;
    int* q;
    int* r;
    void __thiscall FUN_00b1ebc0(int* a, int* b);
    void __thiscall FUN_00b1ec70();
};
// Frees the buffer at p after calling FUN_00b1ebc0 on p and q, then resets p, q and r to null.
// @fnv 0x00b1ec70
void __thiscall FUN_00b1ec70_class::FUN_00b1ec70()
{
    int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
    if (p)
    {
        FUN_00b1ebc0(p, q);
        int n = (int)((char*)r - (char*)p) / 0x38;
        int* pBuffer = p;
        operator delete(pBuffer);
    }
    p = 0;
    q = 0;
    r = 0;
}

struct FUN_00b1ff50
{
    char b0[0x18];
    float f18;
    float f1c;
    unsigned char c20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
    FUN_00b1ff50();
    void FUN_00b200f0(FUN_00b1ff50*);
    FUN_00b1ff50(const FUN_00b1ff50&);
};

// @fnv 0x00b1ff50
FUN_00b1ff50::FUN_00b1ff50(const FUN_00b1ff50& src)
{
    FUN_00b200f0(const_cast<FUN_00b1ff50*>(&src));
    f18 = src.f18;
    f1c = src.f1c;
    c20 = src.c20;
    f24 = src.f24;
    f28 = src.f28;
    f2c = src.f2c;
    i30 = src.i30;
    i34 = src.i34;
}

struct FUN_00b12af0_shell
{
    void FUN_00b12af0();
};
struct FUN_00b18b20
{
    float f0;
    float f4;
    float f8;
    FUN_00b12af0_shell sub;
    float f30;
    int i34;
    FUN_00b18b20();
};
// @fnv 0x00b18b20
FUN_00b18b20::FUN_00b18b20()
{
    f8 = 0.0f;
    f4 = 0.0f;
    f0 = 0.0f;
    sub.FUN_00b12af0();
    *(float*)((char*)this + 0x30) = 0.0f;
    *(int*)((char*)this + 0x34) = 0;
}

struct FUN_00b1fe80_helper
{
    int m0;
    int m4;
    int m8;
    int* mC;
    int* m10;
    int* m14;
    void __thiscall FUN_00b22650(int* a, int* b);
    void __thiscall FUN_00b1fe80();
};
// Frees the array at mC after calling FUN_00b22650 on it, then nulls mC, m10 and m14.
// @fnv 0x00b1fe80
void FUN_00b1fe80_helper::FUN_00b1fe80()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
    if (mC)
    {
        FUN_00b22650(mC, m10);
        int count = ((char*)m14 - (char*)mC) / 0x18;
        int* p = mC;
        operator delete(p);
    }
    mC = 0;
    m10 = 0;
    m14 = 0;
}

void __cdecl operator delete(void*);

struct FUN_00b20c30_class
{
    void __thiscall FUN_00b20c30(void* a, void* b);
};

struct FUN_00b1f650_class
{
    int i0;
    int i4;
    int i8;
    void* pc;
    void* pe;
    void* pp;
    void __thiscall FUN_00b1f650();
};

// Frees the pc buffer via FUN_00b20c30 and operator delete, then resets pc, pe and pp to null.
// @fnv 0x00b1f650
void FUN_00b1f650_class::FUN_00b1f650()
{
    char buf[0x50];
    {
        int count;
        void* oldp;
        if (pc)
        {
            ((FUN_00b20c30_class*)this)->FUN_00b20c30(pc, pe);
            count = (int)((char*)pp - (char*)pc) / 0x18;
            oldp = pc;
            operator delete(oldp);
        }
    }
    pc = 0;
    pe = 0;
    pp = 0;
}

struct FUN_00b249d0_local
{
    double f0;
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double f7;
    double f8;
    double f9;
    double f10;
    double f11;
    double f12;
    double f13;
    double f14;
    double f15;
    double f16;
    double f17;
    double f18;
    double f19;
    double f20;
    double f21;
    double f22;
    double f23;
    double f24;
    double f25;
    double f26;
    double f27;
    double f28;
    double f29;
    double f30;
    double f31;
    double f32;
    double f33;
    double f34;
    double f35;
    double f36;
    double f37;
    double f38;
    double f39;
    double f40;
    double f41;
    double f42;
};

struct CopyableStateBlock
{
    char b0[0x18];
    float f18;
    float f1c;
    unsigned char c20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;

    void __thiscall FUN_00b24ae0(const CopyableStateBlock* that);
    CopyableStateBlock* __thiscall CopyFrom(const CopyableStateBlock& that);
};

// @fnv 0x00b249d0
CopyableStateBlock* __thiscall CopyableStateBlock::CopyFrom(const CopyableStateBlock& aOther)
{
    FUN_00b249d0_local local;

    FUN_00b24ae0(&aOther);

    f18 = aOther.f18;
    f1c = aOther.f1c;
    c20 = aOther.c20;
    f24 = aOther.f24;
    f28 = aOther.f28;
    f2c = aOther.f2c;
    i30 = aOther.i30;
    i34 = aOther.i34;

    return this;
}

void __cdecl FUN_00b269d0(char* a, char* b, char* c, bool d);

// @fnv 0x00b26160
void __cdecl FUN_00b26160(char* pBegin, char* pMiddle, char* pEnd, bool bFlag)
{
    int i;
    int j;
    volatile float afUnused[168];

    if ((pEnd - pBegin) / 56 > 40)
    {
        i = ((pEnd - pBegin) / 56 + 1) / 8;

        FUN_00b269d0(pBegin, pBegin + i * 56, pBegin + 2 * i * 56, bFlag);
        FUN_00b269d0(pMiddle - i * 56, pMiddle, pMiddle + i * 56, bFlag);
        FUN_00b269d0(pEnd - 2 * i * 56, pEnd - i * 56, pEnd, bFlag);
        FUN_00b269d0(pBegin + i * 56, pMiddle, pEnd - i * 56, bFlag);
    }
    else
    {
        FUN_00b269d0(pBegin, pMiddle, pEnd, bFlag);
    }
}

extern int* __cdecl FUN_0044d600(int*, int*, int*);
extern int* __cdecl UninitCopyChecked(int*, int*, int*, void*);
extern void __cdecl FormHeap_Free(void*);
struct C00b1d5d0
{
    int a, b, alloc;
    int *first, *last, *limit;
    void FUN_0044a0a0();
    bool FUN_0044a240(unsigned);
    C00b1d5d0& FUN_00b1d5d0(const C00b1d5d0& rhs);
};
struct Frame00b1d5d0
{
    int* p170;
    int* p16c;
    int* p168;
    int x164, x160, x15c, x158, x154, x150, x14c, x148, x144, x140;
    int x13c, x138, x134, x130, x12c, x128, x124, x120;
    int x11c, x118, x114, x110, x10c, x108, x104, x100;
    int xfc, xf8, xf4, xf0, xec, xe8, xe4, xe0;
    unsigned ndc;
    int* pd8;
    int* pd4;
    int* pd0;
    int* pcc;
    int* pc8;
    int* pc4;
    char bc0, bbf, bbe, bbd;
    int* pbc;
    int* pb8;
    int xb4, xb0, xac, xa8, xa4, xa0, x9c, x98, x94, x90;
    int x8c, x88, x84, x80, x7c, x78, x74;
    unsigned n70;
    int* p6c;
    int* p68;
    int* p64;
    char b60, b5f, b5e, b5d;
    int x5c, x58, x54, x50, x4c, x48, x44, x40;
    unsigned n3c;
    int x38, x34, x30, x2c, x28, x24, x20, x1c, x18, x14, x10, xc;
    int* p8;
    int* p4;
};
// Copy-assigns rhs into this, reusing existing storage when it is large enough and otherwise reallocating and copying the elements.
// @fnv 0x00b1d5d0
C00b1d5d0& C00b1d5d0::FUN_00b1d5d0(const C00b1d5d0& rhs)
{
    Frame00b1d5d0 f;
    if (this != &rhs)
    {
        if (rhs.last - rhs.first == 0)
        {
            FUN_0044a0a0();
        }
        else
        {
            f.n3c = rhs.last - rhs.first;
            if (f.n3c <= (unsigned)(last - first))
            {
                f.p4 = FUN_0044d600(rhs.first, rhs.last, first);
                f.p6c = last;
                f.p68 = f.p6c;
                f.p64 = f.p4;
                f.b5f = f.b60;
                last = first + (rhs.last - rhs.first);
            }
            else
            {
                f.n70 = rhs.last - rhs.first;
                if (f.n70 <= (first == 0 ? 0 : (unsigned)(limit - first)))
                {
                    f.p8 = rhs.first + (last - first);
                    FUN_0044d600(rhs.first, f.p8, first);
                    f.pbc = last;
                    f.pb8 = rhs.last;
                    last = UninitCopyChecked(f.p8, f.pb8, f.pbc, &alloc);
                }
                else
                {
                    if (first != 0)
                    {
                        f.pd0 = last;
                        f.pcc = first;
                        f.pc8 = f.pd0;
                        f.pc4 = f.pcc;
                        f.bbd = f.bbe;
                        f.pd8 = (int*)(limit - first);
                        f.pd4 = first;
                        FormHeap_Free(f.pd4);
                    }
                    f.ndc = rhs.last - rhs.first;
                    if (FUN_0044a240(f.ndc))
                    {
                        f.p170 = first;
                        f.p16c = rhs.last;
                        f.p168 = rhs.first;
                        last = UninitCopyChecked(f.p168, f.p16c, f.p170, &alloc);
                    }
                }
            }
        }
    }
    return *this;
}

unsigned int g_010173f0;
struct StringLike
{
    void __thiscall Clear(bool, unsigned int);
};
struct SpawnEntry : StringLike
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    int __thiscall Init(SpawnEntry*, int, int);
    SpawnEntry* __thiscall FUN_00b22f80(SpawnEntry* that);
};
// Clears the entry, initialises it with g_010173f0, copies the f1c/f20/f24/f28 fields from the passed entry, and returns this.
// @fnv 0x00b22f80
SpawnEntry* SpawnEntry::FUN_00b22f80(SpawnEntry* apSource)
{
    char buf[0x60];
    Clear(false, 0);
    Init(apSource, 0, g_010173f0);
    f1c = apSource->f1c;
    f20 = apSource->f20;
    f24 = apSource->f24;
    f28 = apSource->f28;
    return this;
}

struct FUN_00ec78f1_t
{
    int m0;
    int m4;
    void* __thiscall FUN_00ec78f1(int* out);
};
void __stdcall FUN_00ec7894(FUN_00ec78f1_t* info, const char* fmt);
void* __cdecl operator new(unsigned int);
extern int DAT_010176f8;
extern int DAT_01140ef8;

// Clamps n to 0 when not positive, reports an error if n exceeds the max element count, then allocates n*0x38 bytes.
// @fnv 0x00b23980
void* __cdecl FUN_00b23980(unsigned int n)
{
    int pad;
    if (!(n > 0))
        n = 0;
    else
    {
        if (-1u / n < 0x38)
        {
            FUN_00ec78f1_t o;
            {
                int zero = 0;
                o.FUN_00ec78f1(&zero);
            }
            o.m0 = (unsigned int)&DAT_010176f8;
            FUN_00ec7894(&o, (const char*)&DAT_01140ef8);
        }
    }
    return ::operator new(n * 0x38);
}

// Copies n objects from src into dst one by one, rethrowing after advancing first to dst if an exception occurs.
// @fnv 0x00b23f60
void __cdecl CopyObjects(CopyableStateBlock* apDest, unsigned int auiCount, const CopyableStateBlock* apSource)
{
    CopyableStateBlock* first = apDest;
    try
    {
        for (; auiCount > 0; --auiCount, ++apDest)
        {
            CopyableStateBlock* where = apDest;
            CopyableStateBlock* placed = where;
            CopyableStateBlock* result;
            if (placed)
            {
                *placed = *apSource;
                result = placed;
            }
            else
            {
                result = 0;
            }
        }
    }
    catch (...)
    {
        for (; first != apDest; ++first)
        {
        }
        throw;
    }
}

void* FormHeap_Allocate(unsigned int);
__declspec(noreturn) void __stdcall FUN_00ec7894(void*, void*);
struct BadAlloc
{
    int vt;
    const char* w;
    int f;
    BadAlloc* FUN_0044d6c0(const char*);
};
// Clamps n to zero, throws BadAlloc if n*4 overflows, and returns a 4-byte-per-element allocation of n*4 bytes.
// @fnv 0x0044d670
int* FUN_0044d670(unsigned int n)
{
    if (n <= 0)
        n = 0;
    else if ((unsigned int)-1 / n < 4)
    {
        BadAlloc e;
        e.FUN_0044d6c0(0);
        FUN_00ec7894(&e, &DAT_01140ef8);
    }
    return (int*)FormHeap_Allocate(n * 4);
}

// Sets the nine floats at instance to the 3x3 identity matrix and returns instance.
// @fnv 0x00b12af0
FUN_00b12af0_shell* __fastcall FUN_00b12af0(FUN_00b12af0_shell* apMatrix)
{
    *(float*)apMatrix = 1.0f;
    *(float*)((char*)apMatrix + 4) = 0.0f;
    *(float*)((char*)apMatrix + 8) = 0.0f;
    *(float*)((char*)apMatrix + 12) = 0.0f;
    *(float*)((char*)apMatrix + 16) = 1.0f;
    *(float*)((char*)apMatrix + 20) = 0.0f;
    *(float*)((char*)apMatrix + 24) = 0.0f;
    *(float*)((char*)apMatrix + 28) = 0.0f;
    *(float*)((char*)apMatrix + 32) = 1.0f;
    return apMatrix;
}

int __cdecl FUN_00ec6cc4(char* dst, char const* fmt, char* args);

struct FmtCtx
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned flags;
};

struct FUN_0044a4c0_Str
{
    void FUN_0044a4c0(char const* s);
};

// Formats variadic arguments into a local buffer using fmt, then assigns the result to out and returns out.
// @fnv 0x00b18860
FUN_0044a4c0_Str* __cdecl FUN_00b18860(FUN_0044a4c0_Str* out, char const* fmt, ...)
{
    FmtCtx ctx;
    char buf2[0x400];
    char* ap4;
    ctx.flags = 0;
    ap4 = reinterpret_cast<char*>(&fmt) + sizeof(fmt);
    FUN_00ec6cc4(buf2, fmt, ap4);
    out->FUN_0044a4c0(buf2);
    ctx.flags |= 1;
    return out;
}

void __cdecl _memmove(void*, const void*, unsigned int);

struct Vec_00b1c6d0
{
    void* _pad[3];
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
    __forceinline unsigned int size() const
    {
        return (unsigned int)(_Mylast - _Myfirst);
    }
};

struct Geo_00b1c6d0
{
    char pad00[0x22];
    unsigned short m_usTriCount;
    char pad24[0x64];
    Vec_00b1c6d0 m_ppIndices;

    void FUN_00b31070(char cTex, const float* afCoords);
};

struct Class_00b1c6d0
{
    void FUN_00b1c6d0(Geo_00b1c6d0* geo, char cTex, const float* pTexCoords, bool bFlip);
};

// Copies pTexCoords into afCoords, negates odd-indexed values when bFlip is set, then calls FUN_00b31070 once per triangle in m_ppIndices.
// @fnv 0x00b1c6d0
void Class_00b1c6d0::FUN_00b1c6d0(Geo_00b1c6d0* geo, char cTex, const float* pTexCoords, bool bFlip)
{
    float afCoords[8];
    _memmove(afCoords, pTexCoords, 32);
    if (bFlip)
    {
        for (int i = 1; i < 8; i += 2)
        {
            afCoords[i] = -afCoords[i];
        }
    }
    char chIndex = cTex;
    geo->m_usTriCount = 0;
    {
        int j_;
        const Vec_00b1c6d0* p2;
        for (j_ = 0; j_ < (unsigned short)(((unsigned int)((p2 = &geo->m_ppIndices)->_Mylast - p2->_Myfirst)) / 3);
             ++j_)
        {
            geo->FUN_00b31070(chIndex, afCoords);
            geo->m_usTriCount++;
        }
    }
}

namespace std {
template <class _Elem> struct char_traits
{
};
template <class _Ty> class allocator
{
};
template <class _Elem, class _Traits, class _Ax> class basic_string
{
  protected:
    void _Tidy(bool _Newsize, unsigned int _Newcap);
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Ctx
{
    int a, b, c, d, e;
    char q, w, x2, r;
};

struct StringHolder : std::string
{
    StringHolder* __thiscall FUN_00b1d100();
};

// Calls _Tidy(false, 0) to release the string's internal buffer and returns this.
// @fnv 0x00b1d100
StringHolder* __thiscall StringHolder::FUN_00b1d100()
{
    Ctx obj;
    char* p = &obj.r;
    int aa;
    _Tidy(false, 0);
    return this;
}

void __cdecl FUN_00b23760(unsigned int a, unsigned int b, unsigned int c);

struct S00b1dd80_Obj
{
    unsigned int i0;
    unsigned int i4;
    unsigned int i8;
    unsigned int ic;
    unsigned int p10;

    void __thiscall FUN_00b1ebc0(int* a, int* b);
    int* __thiscall FUN_00b1dd80(int* out, int* p, unsigned int q);
};

// Shifts the 0x38-byte elements after q down, drops the last one (p10 -= 0x38), and returns out holding i0 and q; calls FUN_00ec7c56 if q is out of range.
// @fnv 0x00b1dd80
int* __thiscall S00b1dd80_Obj::FUN_00b1dd80(int* out, int* p, unsigned int q)
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int u23;
    int u24;

    FUN_00b23760(q + 0x38, p10, q);
    FUN_00b1ebc0((int*)(p10 - 0x38), (int*)p10);
    p10 -= 0x38;

    *out = 0;

    if (this == 0 || ic > q || q > p10)
    {
        FUN_00ec7c56();
    }

    *out = i0;
    out[1] = q;

    return out;
}

// 0x00b1f920 candidate

struct E44_00b1f920
{
    char b[0x2c];
};
struct Big_00b1f920
{
    char b[0x84];
};

struct Pool_00b1f920
{
    int a0;
    int a4;
    int a8;
    E44_00b1f920* m_pHeadNode;  // 0x0c
    E44_00b1f920* m_last;       // 0x10
    E44_00b1f920* m_pFreeList;  // 0x14

    bool FUN_00b1f920(unsigned int n);
};

void __cdecl FUN_00b0fb80();
void* __cdecl FUN_00b23b50(unsigned int n, int b);

// Clears the three pointers; returns false if n is 0, else allocates n E44_00b1f920 nodes into them (or calls FUN_00b0fb80 if n is too large) and returns true.
// @fnv 0x00b1f920
bool Pool_00b1f920::FUN_00b1f920(unsigned int aiNodeCount)
{
    m_pHeadNode = 0;
    m_last = 0;
    m_pFreeList = 0;
    if (aiNodeCount == 0)
        return false;
    else
    {
        unsigned int cap = 0x5D1745D;
        Big_00b1f920 big;
        if ((cap > 0 ? cap : 1) < aiNodeCount)
            FUN_00b0fb80();
        else
        {
            m_pHeadNode = (E44_00b1f920*)FUN_00b23b50(aiNodeCount, 0);
            m_last = m_pHeadNode;
            m_pFreeList = m_pHeadNode + aiNodeCount;
        }
    }
    return true;
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
__declspec(noreturn) void __cdecl __CxxThrowException(void* a, unsigned int b);
struct FUN_0044d6c0_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* FUN_00ec78f1(void*** a);
};
// Returns operator new(n * 0x18), throwing if n * 0x18 would overflow; n of 0 allocates 0 bytes.
// @fnv 0x00b23aa0
void* __cdecl FUN_00b23aa0(unsigned int n)
{
    if (n <= 0)
        n = 0;
    else
    {
        if (-1 / n < 24)
        {
            void** z0;
            FUN_0044d6c0_class e2;
            z0 = 0;
            e2.FUN_00ec78f1(&z0);
            e2.m_iWordAt00 = &DAT_010176f8;
            __CxxThrowException(&e2, (unsigned int)&DAT_01140ef8);
        }
    }
    return operator new(n * 0x18);
}

struct B1c
{
    char v;
};

// Copies [first, last) backward element by element so the copy ends at dst, and returns dst - (last - first).
// @fnv 0x00b24710
CopyableStateBlock* FUN_00b24710(CopyableStateBlock* first, CopyableStateBlock* last, CopyableStateBlock* dst)
{
    B1c a;
    B1c aa = {};
    B1c b_2 = a;
    B1c ai = aa;
    CopyableStateBlock* m = dst;
    CopyableStateBlock* o = first;
    CopyableStateBlock* begin2 = m - (last - o);
    B1c a8 = {};
    B1c b2 = {};
    B1c c = a8;
    B1c oo = b2;
    CopyableStateBlock* kOut = m;
    CopyableStateBlock* q = last;
    while (o != q)
    {
        --q;
        --kOut;
        *kOut = *q;
    }
    return begin2;
}

extern unsigned long DAT_010173f0;

struct S00b24a80_Obj;

struct S00b24a80_Spawn
{
    void __thiscall AssignSubstring(S00b24a80_Obj* a, int b, unsigned int c);
};

struct S00b24a80_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float f1c;
    float f20;
    float f24;
    float f28;
    S00b24a80_Obj* __thiscall FUN_00b24a80(S00b24a80_Obj* src);
};

void S00b24a80_Spawn::AssignSubstring(S00b24a80_Obj* a, int b, unsigned int c)
{}

// Copies the substring reference and the four float fields from src into this object, then returns this.
// @fnv 0x00b24a80
S00b24a80_Obj* S00b24a80_Obj::FUN_00b24a80(S00b24a80_Obj* src)
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    ((S00b24a80_Spawn*)this)->AssignSubstring(src, 0, DAT_010173f0);
    f1c = src->f1c;
    f20 = src->f20;
    f24 = src->f24;
    f28 = src->f28;
    return this;
}

void __cdecl FUN_00b26ab0(CopyableStateBlock* a, CopyableStateBlock* b);
struct PairQ
{
    CopyableStateBlock* first;
    CopyableStateBlock* second;
};
struct InlQ
{
    int p0[15];
    CopyableStateBlock* s6r;
    CopyableStateBlock* s6l;
    int p1[15];
    CopyableStateBlock* s5;
    int p2[14];
    CopyableStateBlock* s4r;
    CopyableStateBlock* s4l;
    int p3[22];
    CopyableStateBlock* s3r;
    CopyableStateBlock* s3l;
    int p4[15];
    CopyableStateBlock* s2;
    int p5[14];
    CopyableStateBlock* s1;
};
// Three-way partitions [_First, _Last) around a median pivot by f2c and returns in pRet the range of elements equal to the pivot.
// @fnv 0x00b25680
PairQ* __cdecl FUN_00b25680(PairQ* pRet, CopyableStateBlock* _First, CopyableStateBlock* _Last, bool _Pred)
{
    InlQ t_kvalxz;
    CopyableStateBlock* s_v;
    int p_kqlvt[14];
    int pMid_yn;
    CopyableStateBlock* iD_roiodc = _First + (_Last - _First) / 2;
    FUN_00b26160((char*)_First, (char*)iD_roiodc, (char*)(_Last - 1), _Pred);
    CopyableStateBlock* pPf_zm = iD_roiodc;
    CopyableStateBlock* pPl_mxtma = pPf_zm + 1;
    while (_First < pPf_zm && !((unsigned char)((pPf_zm[-1]).f2c > (*pPf_zm).f2c ? 1 : 0)) &&
           !((unsigned char)((*pPf_zm).f2c > (pPf_zm[-1]).f2c ? 1 : 0)))
        --pPf_zm;
    while (pPl_mxtma < _Last && !((unsigned char)((*pPl_mxtma).f2c > (*pPf_zm).f2c ? 1 : 0)) &&
           !((unsigned char)((*pPf_zm).f2c > (*pPl_mxtma).f2c ? 1 : 0)))
        ++pPl_mxtma;
    CopyableStateBlock* pGf_rbjuzd = pPl_mxtma;
    CopyableStateBlock* pGl_sm = pPf_zm;
    for (;;)
    {
        for (; pGf_rbjuzd < _Last; ++pGf_rbjuzd)
            if (((unsigned char)((*pPf_zm).f2c > (*pGf_rbjuzd).f2c ? 1 : 0)))
                ;
            else if (((unsigned char)((*pGf_rbjuzd).f2c > (*pPf_zm).f2c ? 1 : 0)))
                break;
            else
            {
                t_kvalxz.s1 = pPl_mxtma++;
                FUN_00b26ab0(t_kvalxz.s1, pGf_rbjuzd);
            }
        for (; _First < pGl_sm; --pGl_sm)
            if (((unsigned char)((pGl_sm[-1]).f2c > (*pPf_zm).f2c ? 1 : 0)))
                ;
            else if (((unsigned char)((*pPf_zm).f2c > (pGl_sm[-1]).f2c ? 1 : 0)))
                break;
            else
            {
                t_kvalxz.s2 = --pPf_zm;
                FUN_00b26ab0(t_kvalxz.s2, pGl_sm - 1);
            }
        if (pGl_sm == _First && pGf_rbjuzd == _Last)
        {
            pRet->first = pPf_zm;
            pRet->second = pPl_mxtma;
            return pRet;
        }
        if (pGl_sm == _First)
        {
            if (pPl_mxtma != pGf_rbjuzd)
            {
                t_kvalxz.s3r = pPl_mxtma;
                t_kvalxz.s3l = pPf_zm;
                FUN_00b26ab0(t_kvalxz.s3l, t_kvalxz.s3r);
            }
            ++pPl_mxtma;
            t_kvalxz.s4r = pGf_rbjuzd;
            t_kvalxz.s4l = pPf_zm++;
            pGf_rbjuzd++;
            FUN_00b26ab0(t_kvalxz.s4l, t_kvalxz.s4r);
        }
        else if (pGf_rbjuzd == _Last)
        {
            if (--pGl_sm != --pPf_zm)
            {
                t_kvalxz.s5 = pPf_zm;
                FUN_00b26ab0(pGl_sm, t_kvalxz.s5);
            }
            --pPl_mxtma;
            t_kvalxz.s6r = pPl_mxtma;
            t_kvalxz.s6l = pPf_zm;
            FUN_00b26ab0(t_kvalxz.s6l, t_kvalxz.s6r);
        }
        else
        {
            --pGl_sm;
            s_v = pGf_rbjuzd;
            FUN_00b26ab0(s_v, pGl_sm);
            ++pGf_rbjuzd;
        }
    }
}

struct TagByte
{
    char v;
};
struct RangePtr
{
    int entry;
    int scratch;
};
extern "C" void __cdecl FUN_00b25fa0(int first, int last, int dest, int count, TagByte mode, TagByte zero);

// Calls FUN_00b25fa0(a, b, c, d) with two one-byte tag arguments.
// @fnv 0x00b26450
void __cdecl FUN_00b26450(int a, int b, int aiDest, int d)
{
    TagByte tag = {};
    TagByte end;
    TagByte flags = end;
    int t = b;
    RangePtr pos;
    pos.entry = a;
    FUN_00b25fa0(pos.entry, t, aiDest, d, flags, tag);
}

namespace fnv_00b264f0 {
struct B1c
{
    char v;
};

// Copies the range of CopyableStateBlock elements from first to last into dst and returns a pointer past the last copied element.
// @fnv 0x00b264f0
CopyableStateBlock* FUN_00b264f0(CopyableStateBlock* first, CopyableStateBlock* last, CopyableStateBlock* dst)
{
    CopyableStateBlock* pDstEnd = dst + (last - first);
    B1c a8 = {};
    B1c b2 = {};
    B1c c = a8;
    B1c d = b2;
    CopyableStateBlock* p3 = dst;
    CopyableStateBlock* q = first;
    for (; q != last; ++p3, ++q)
        *p3 = *q;
    return pDstEnd;
}
}  // namespace fnv_00b264f0

extern "C" void __cdecl FUN_00b26ab0(char* a, char* b);

// Calls FUN_00b26ab0 on (b, a), (c, b), then (b, a) whenever the float at offset 0x2C of the first exceeds that of the second.
// @fnv 0x00b269d0
void __cdecl FUN_00b269d0(char* a, char* b, char* c)
{
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    int pad5;
    int pad6;
    int pad7;
    int pad8;
    int pad9;
    int pad10;
    int pad11;
    int pad12;
    int pad13;
    int pad14;
    int pad15;
    int pad16;
    int pad17;
    int pad18;
    int pad19;
    int pad20;
    int pad21;
    int pad22;
    int pad23;
    int pad24;
    int pad25;
    int pad26;
    int pad27;
    int pad28;
    int pad29;
    int pad30;
    int pad31;
    int pad32;
    int pad33;
    int pad34;
    int pad35;
    int pad36;
    int pad37;
    int pad38;
    int pad39;
    int pad40;
    int pad41;
    int pad42;
    int pad43;
    int pad44;
    int pad45;
    int pad46;
    int pad47;
    int pad48;
    int pad49;
    int pad50;
    int pad51;
    if ((bool)((*(float*)(b + 0x2C) > *(float*)(a + 0x2C)) ? 1 : 0))
    {
        FUN_00b26ab0(b, a);
    }
    if ((bool)((*(float*)(c + 0x2C) > *(float*)(b + 0x2C)) ? 1 : 0))
    {
        FUN_00b26ab0(c, b);
    }
    if ((bool)((*(float*)(b + 0x2C) > *(float*)(a + 0x2C)) ? 1 : 0))
    {
        FUN_00b26ab0(b, a);
    }
}

struct V3b244a0
{
    float x;
    float y;
    float z;
};

void __stdcall FUN_00ec7894(int a, int b);

// Stores *src into each of count V3b244a0 elements starting at dest; the catch handler calls FUN_00ec7894(0, 0).
// @fnv 0x00b244a0
void __cdecl FUN_00b244a0(V3b244a0* dest, unsigned int count, const V3b244a0* src)
{
    V3b244a0* first = dest;

    try
    {
        for (; count > 0; --count, ++dest)
        {
            V3b244a0* p = dest;
            V3b244a0* q = p;
            V3b244a0* r;

            if (q)
            {
                *q = *src;
                r = q;
            }
            else
            {
                r = 0;
            }

            (void)r;
        }
    }
    catch (...)
    {
        for (; first != dest; ++first)
        {
        }

        FUN_00ec7894(0, 0);
    }
}

namespace fnv_00b18970 {
struct Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Base();
};

struct FUN_00b18970_local
{
    double f0;
    double f1;
    double f2;
    double f3;
    double f4;
    double f5;
    double f6;
    double f7;
    double f8;
    double f9;
    double f10;
    double f11;
    double f12;
    double f13;
    double f14;
    double f15;
    double f16;
    double f17;
    double f18;
};

struct FUN_00b18970 : Base
{
    float f18;
    float f1c;
    unsigned char c20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;

    FUN_00b18970();
};

// Default constructor: zeroes f18, f1c, c20, f24, f28, f2c, i30 and i34 after the Base constructor.
// @fnv 0x00b18970
FUN_00b18970::FUN_00b18970()
{
    FUN_00b18970_local local;
    f18 = 0.0f;
    f1c = 0.0f;
    c20 = 0;
    f24 = 0.0f;
    f28 = 0.0f;
    f2c = 0.0f;
    i30 = 0;
    i34 = 0;
}
}  // namespace fnv_00b18970

namespace fnv_00b23bb0 {
struct AllocationException
{
    unsigned int vtable;
    unsigned int reserved1;
    unsigned int reserved2;
    void __thiscall FUN_00ec78f1(unsigned int* value);
};
extern unsigned int DAT_010176f8;
extern unsigned int DAT_01140ef8;
void __stdcall FUN_00ec7894(void* exception, void* info);
void* __cdecl FormHeap_Allocate(unsigned int bytes);

// Allocates a 12-byte-per-element array of count items, throwing AllocationException on overflow.
// @fnv 0x00b23bb0
void* __cdecl FUN_00b23bb0(unsigned int count)
{
    if (count <= 0u)
        count = 0;
    else if (0xffffffffu / count < 12)
    {
        unsigned int empty = 0;
        AllocationException exception;
        exception.FUN_00ec78f1(&empty);
        exception.vtable = (unsigned int)&DAT_010176f8;
        FUN_00ec7894(&exception, &DAT_01140ef8);
    }
    return FormHeap_Allocate(count * 12);
}
}  // namespace fnv_00b23bb0
