
// src/staging/blk_00b20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void __cdecl FUN_00b02c90();

struct FUN_00b274a0_class
{
    void __thiscall FUN_00b02c90();
    FUN_00b274a0_class* __thiscall ResetState();
};

// Calls FUN_00b02c90, clears the byte at offset 0x3c and the int at offset 0x40, and returns this.
// @fnv 0x00b274a0
FUN_00b274a0_class* __thiscall FUN_00b274a0_class::ResetState()
{
    FUN_00b02c90();
    *reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x3c) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x40) = 0;
    return this;
}

extern "C" void FUN_0044a450(int);
extern int DAT_010a57fc;

struct FUN_00b3c440_class
{
    int* vtbl;
    int FUN_00b3c440(int a);
};

// Calls FUN_0044a450 on this and a, installs the DAT_010a57fc vtable pointer, and returns this.
// @fnv 0x00b3c440
int FUN_00b3c440_class::FUN_00b3c440(int aiValue)
{
    int pad[24];
    reinterpret_cast<void(__thiscall*)(FUN_00b3c440_class*, int)>(FUN_0044a450)(this, aiValue);
    *reinterpret_cast<int**>(this) = &DAT_010a57fc;
    return reinterpret_cast<int>(this);
}

extern int DAT_010a31fc;

struct FUN_00b3c910_class
{
    void InitVTable();
};

// @fnv 0x00b3c910
void FUN_00b3c910_class::InitVTable()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010a31fc);
}

extern int DAT_010a5890;

struct FUN_00b3f0a0_Class
{
    void __thiscall FUN_00b3f0a0();
};

// @fnv 0x00b3f0a0
void __thiscall FUN_00b3f0a0_Class::FUN_00b3f0a0()
{
    *(int*)this = (int)&DAT_010a5890;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3& __thiscall FUN_00b2a1c0(const NiPoint3& other);
};

// Adds other's x, y and z to this point's components and returns this point.
// @fnv 0x00b2a1c0
NiPoint3& NiPoint3::FUN_00b2a1c0(const NiPoint3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

unsigned int __cdecl FUN_00ec7c56();

struct FUN_00b393b0_Class
{
    int* vtbl;
    int __thiscall GetVtblAndValue(int a);
};

// @fnv 0x00b393b0
int FUN_00b393b0_Class::GetVtblAndValue(int pOut)
{
    int* p = *(int**)((char*)this + 0x18);
    int v = *p;
    *(int*)pOut = 0;
    *(int*)((char*)pOut + 4) = v;
    if (!this)
        FUN_00ec7c56();
    *(int*)pOut = *(int*)this;
    return pOut;
}

struct FUN_00b3c4b0_class
{
    FUN_00b3c4b0_class* __thiscall FUN_00b3c4b0(int a);
};

// Zeroes five floats at offsets 0x0-0x10, clamps a to at most 5, stores it at 0x14, and returns this.
// @fnv 0x00b3c4b0
FUN_00b3c4b0_class* __thiscall FUN_00b3c4b0_class::FUN_00b3c4b0(int a)
{
    *(float*)(this + 0x10) = 0.0f;
    *(float*)(this + 0xc) = 0.0f;
    *(float*)(this + 8) = 0.0f;
    *(float*)(this + 4) = 0.0f;
    *(float*)this = 0.0f;
    if (a > 5)
        a = 5;
    *(int*)(this + 0x14) = a;
    return this;
}

double __cdecl FUN_00ec6054(double);

struct FUN_00b3c5a0_class
{
    float data[0x14 / 4];
    int count;
    float FUN_00b3c5a0();
};

// @fnv 0x00b3c5a0
float FUN_00b3c5a0_class::FUN_00b3c5a0()
{
    float fSumSquares = 0.0f;
    for (int i = 0; i < count; ++i)
        fSumSquares += data[i] * data[i];
    return FUN_00ec6054(fSumSquares);
}

struct FUN_00b3c600_class
{
    float* pData;
    int* pCount;
    double __thiscall FUN_00b3c5a0();
    void NormalizeData();
};
// @fnv 0x00b3c600
void FUN_00b3c600_class::NormalizeData()
{
    float fDivisor = FUN_00b3c5a0();
    if (fDivisor != 0.0)
    {
        for (int i = 0; i < *(int*)((char*)this + 0x14); ++i)
        {
            ((float*)((char*)this + 0))[i] = ((float*)((char*)this + 0))[i] / fDivisor;
        }
    }
}

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

// Initializes the object's fields: stores the argument in i4, sets w8 to 3, and zeroes the remaining members.
// @fnv 0x00b27660
FUN_00b27660_class::FUN_00b27660_class(int aiValue)
{
    b0 = 0;
    b1 = 0;
    i4 = aiValue;
    w8 = 3;
    c0c = 0;
    c10 = 0;
    c14 = 0;
    c18 = 0;
    w1c = 0;
    c20 = 0;
    c24 = 0;
    w28 = 0;
    c2c = 0;
}

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
// @fnv 0x00b373c0
FUN_00b373c0_class::FUN_00b373c0_class()
{
    f0 = 0.0f;
    f4 = 0.25f;
    i8 = 2;
    iC = 2;
    i10 = 2;
    b14 = 1;
    f20 = 0.0f;
    f24 = 0.0f;
    i28 = 0;
    i2C = 4;
    i30 = 0;
    i34 = 0;
    i38 = 0;
    f3C = 1.0f;
    f40 = 1.0f;
    f1C = 1.0f;
    f18 = 1.0f;
}

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

// Stores the five float arguments into f0..f10 and sets i14 to 5.
// @fnv 0x00b3c550
FUN_00b3c550_class::FUN_00b3c550_class(float af0, float af4, float af8, float afC, float af10)
{
    f0 = af0;
    f4 = af4;
    f8 = af8;
    fC = afC;
    f10 = af10;
    i14 = 5;
}

struct FUN_00b2e1b0_class
{
    unsigned char _unused[0x0c];
    unsigned char* m_data;
    unsigned char* m_kRayEnd;
    int m_pRayCursor;

    void __thiscall FreeBuffer();
};

void _Deallocate(void*);

// @fnv 0x00b2e1b0
void __thiscall FUN_00b2e1b0_class::FreeBuffer()
{
    struct State
    {
        int count;
        unsigned char* h;
        unsigned char* a;
        unsigned char* b;
        unsigned char* c;
        unsigned char* d;
        unsigned char* g;
        unsigned short unused;
        unsigned char flag0;
        unsigned char flag1;
    } state;

    if (m_data)
    {
        state.a = m_kRayEnd;
        state.b = m_data;
        state.c = state.a;
        state.d = state.b;
        state.flag1 = state.flag0;
        state.g = state.d;

        for (; state.g != state.c; state.g += 8)
        {
        }

        state.count = (m_pRayCursor - (int)m_data) >> 3;
        state.h = m_data;
        _Deallocate(state.h);
    }

    m_data = 0;
    m_kRayEnd = 0;
    m_pRayCursor = 0;
}

void _Deallocate(void*);

struct FUN_00b34d90_class
{
    unsigned char padding[0x0c];
    char* begin;
    int value;
    char* end;

    void __thiscall FUN_00b34d90();
};

// Frees the buffer at begin if set, then resets begin, value and end to zero.
// @fnv 0x00b34d90
void FUN_00b34d90_class::FUN_00b34d90()
{
    {
        bool flagCopy;
        {
            bool flag;
            {
                char* beginCopy;
                {
                    int valueCopy;
                    {
                        char* beginValue;
                        {
                            int value;
                            {
                                char* deallocatePtr;
                                {
                                    int halfRange;
                                    if (this->begin)
                                    {
                                        value = this->value;
                                        beginValue = this->begin;
                                        valueCopy = value;
                                        beginCopy = beginValue;
                                        flagCopy = flag;
                                        halfRange = (this->end - this->begin) >> 1;
                                        deallocatePtr = this->begin;
                                        _Deallocate(deallocatePtr);
                                    }
                                    this->begin = 0;
                                    this->value = 0;
                                    this->end = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

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

// Initializes the five floats f0 through f10 to 0.0 and sets i14 to 3.
// @fnv 0x00b3c470
FUN_00b3c470_class::FUN_00b3c470_class()
{
    f10 = 0.0f;
    fc = 0.0f;
    f8 = 0.0f;
    f4 = 0.0f;
    f0 = 0.0f;
    i14 = 3;
}

struct FUN_00b3f030_Class
{
    int* vtbl;
    FUN_00b3f030_Class();
};

// Constructor: sets vtbl to DAT_010a5890 and zeroes three floats stored after the object.
// @fnv 0x00b3f030
FUN_00b3f030_Class::FUN_00b3f030_Class()
{
    vtbl = &DAT_010a5890;
    float* p = (float*)(this + 1);
    p[0] = 0.0f;
    p[1] = 0.0f;
    p[2] = 0.0f;
}

struct Random
{
    void* vtbl;
    void* __thiscall DestroyRandom(unsigned int flags);
};

extern const int vftable_Random[];
void _Deallocate(void*);

// Sets the vtable pointer to vftable_Random and, if flags has bit 0 set, deallocates this; returns this.
// @fnv 0x00b3f2e0
void* __thiscall Random::DestroyRandom(unsigned int flags)
{
    this->vtbl = (void*)vftable_Random;
    if (flags & 1)
        _Deallocate(this);
    return this;
}

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

// @fnv 0x00b27060
FUN_00b27060_cls* FUN_00b27060_cls::FUN_00b27060()
{
    unk30 = 0;
    return this;
}

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

// Deletes all owned buffer arrays, nulls their pointers, then calls ClearFields.
// @fnv 0x00b274d0
void ResourceBufferOwner::FreeBuffers()
{
    delete[] buffer10;
    delete[] buffer14;
    delete[] buffer18;
    delete[] buffer24;
    delete[] buffer28;
    delete[] buffer2c;
    delete[] buffer30;
    delete[] buffer1c;
    delete[] buffer20;
    delete[] buffer34;
    delete[] buffer38;

    buffer10 = 0;
    buffer14 = 0;
    buffer18 = 0;
    buffer24 = 0;
    buffer28 = 0;
    buffer2c = 0;
    buffer30 = 0;
    buffer1c = 0;
    buffer20 = 0;
    buffer34 = 0;
    buffer38 = 0;

    delete[] buffer40;
    buffer40 = 0;
    ClearFields();
}

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

// Releases the objects held in m_20, m_24, m_2c and m_18, calls Destroy(3) on m_2c, then zeroes m_0c, m_14, m_20, m_24, m_2c and m_18.
// @fnv 0x00b276f0
void FUN_00b276f0_cls::Reset()
{
    void* a = (void*)m_20;
    FormHeap_Free(a);
    void* b = (void*)m_24;
    FormHeap_Free(b);
    void* t = (void*)m_2c;
    FUN_00b276f0_sub* c = (FUN_00b276f0_sub*)t;
    c != 0 ? c->Destroy(3) : 0;
    void* d7 = (void*)m_18;
    FormHeap_Free(d7);
    m_0c = 0;
    m_14 = 0;
    m_20 = 0;
    m_24 = 0;
    m_2c = 0;
    m_18 = 0;
}

namespace fnv_00b277b0 {
struct FUN_00b277b0_cls
{
    void FreeBuffers();
    void* Destroy(unsigned int flags);
};

extern "C" void __stdcall FUN_00ec5fce(void* object, int elementSize, int count, void (FUN_00b277b0_cls::*callback)());

extern "C" void __cdecl FormHeap_Free(void* apMemory);

// @fnv 0x00b277b0
void* FUN_00b277b0_cls::Destroy(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x44, reinterpret_cast<int*>(this)[-1], &FUN_00b277b0_cls::FreeBuffers);

        if (flags & 1)
        {
            FormHeap_Free(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    FreeBuffers();

    if (flags & 1)
    {
        FormHeap_Free(this);
    }

    return this;
}
}  // namespace fnv_00b277b0

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

// Resets the three fields to zero and, when count is non-zero and within the limit, allocates a buffer of count*0x54 bytes and stores its start and end pointers.
// @fnv 0x00b2e080
bool __thiscall FnvB2e080::InitBuffer(unsigned int count)
{
    int unused[34];
    unsigned int n;
    this->f0c = 0;
    this->f10 = 0;
    this->f14 = 0;
    if (count == 0)
    {
        return false;
    }
    else
    {
        n = 0x030C30C3;
        if ((n > 0 ? n : 1) < count)
        {
            FUN_00b0fb80();
        }
        else
        {
            this->f0c = FUN_00b2e4a0(count, 0);
            this->f10 = this->f0c;
            this->f14 = count * 0x54 + this->f0c;
        }
    }
    return true;
}

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

// @fnv 0x00b2e250
SpanPair* FUN_00b2e250_cls::FUN_00b2e250(SpanPair* out, int iUnused, unsigned int uiIndex1, int iUnused2,
                                         unsigned int uiIndex2)
{
    SpanPair a;
    SpanPair b;
    int r;
    int spare[0x16];

    a.a = 0;
    if (this == 0 || m_0c > uiIndex1 || uiIndex1 > m_10)
    {
        FUN_00ec7c56();
    }
    a.a = m_00;
    a.b = uiIndex1;
    b.a = 0;
    if (this == 0 || m_0c > uiIndex2 || uiIndex2 > m_10)
    {
        FUN_00ec7c56();
    }
    b.a = m_00;
    b.b = uiIndex2;
    if (a.Compare(b))
    {
        r = FUN_00b2e3f0(b.b, m_10, a.b);
        Update(r, m_10);
        m_10 = r;
    }
    *out = a;
    return out;
}

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

// @fnv 0x00b335c0
ProbePair FUN_00b335c0_cls::FUN_00b335c0(unsigned int auiUnused, unsigned int a3, unsigned int auiUnused2,
                                         unsigned int a5)
{
    ProbePair result;
    {
        ProbePair key;
        unsigned int r;
        result.m_00 = 0;
        if (this == 0 || this->m_0c > a3 || a3 > this->m_10)
        {
            FUN_00ec7c56();
        }
        result.m_00 = this->unk00;
        result.m_04 = a3;
        key.m_00 = 0;
        if (this == 0 || this->m_0c > a5 || a5 > this->m_10)
        {
            FUN_00ec7c56();
        }
        key.m_00 = this->unk00;
        key.m_04 = a5;
        if (result.FUN_00b16830(&key))
        {
            r = FUN_00b42e50(key.m_04, this->m_10, result.m_04);
            {
                FUN_00b335c0_tmp tmp;
                tmp.unk00 = this->m_10;
                tmp.unk04 = tmp.unk00;
                tmp.unk08 = r;
                tmp.unk0D = tmp.unk0C;
            }
            this->m_10 = r;
        }
    }
    return result;
}

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

// @fnv 0x00b33af0
FUN_00b33af0_pair* FUN_00b33af0_cls::FUN_00b33af0(FUN_00b33af0_pair* out, unsigned int unk0c, unsigned int a,
                                                  unsigned int unk14, unsigned int b)
{
    FUN_00b33af0_pair p9;
    FUN_00b33af0_pair p2;
    unsigned int r;
    FUN_00b33af0_iter it9;

    p9.a = 0;
    if (this == 0 || this->m_0c > a || a > this->m_10)
    {
        FUN_00ec7c56();
    }
    p9.a = this->m_00;
    p9.b = a;
    p2.a = 0;
    if (this == 0 || this->m_0c > b || b > this->m_10)
    {
        FUN_00ec7c56();
    }
    p2.a = this->m_00;
    p2.b = b;
    if (p9.CompareTo(&p2))
    {
        r = FUN_00b35c30(p2.b, this->m_10, p9.b);
        it9.m_00 = this->m_10;
        it9.m_04 = it9.m_00;
        it9.m_08 = r;
        it9.m_0d = it9.m_0c;
        this->m_10 = r;
    }
    *out = p9;
    return out;
}

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
// Constructs the object, initializing m_00 to 0.0f, m_04 to 1.0f, m_08 to 0.0f and default-constructing m_0c, m_24, m_3c, m_54 and m_6c.
// @fnv 0x00b37590
FUN_00b37590::FUN_00b37590() : m_00(0.0f), m_04(1.0f), m_08(0.0f), m_0c(), m_24(), m_3c(), m_54(), m_6c()
{
    LocalScratch scratch;
}
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

// @fnv 0x00b3c660
FUN_00b3c660_cls FUN_00b3c660_cls::FUN_00b3c660(FUN_00b3c660_cls* other)
{
    int n = -1;
    if (count < other->count)
    {
        n = count;
    }
    else
    {
        n = other->count;
    }
    FUN_00b3c660_cls tmp3(n);
    for (int i2 = 0; i2 < count; ++i2)
    {
        tmp3.data[i2] = data[i2] + other->data[i2];
    }
    return tmp3;
}

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

// @fnv 0x00b3c750
FUN_00aa7830_cls __thiscall FUN_00b3c750_cls::Subtract(const FUN_00b3c5a0_class* other)
{
    int n = -1;
    if (count < other->count)
    {
        n = count;
    }
    else
    {
        n = other->count;
    }
    FUN_00aa7830_cls tmp3(n);
    for (int i2 = 0; i2 < count; ++i2)
    {
        tmp3.data[i2] = data[i2] - other->data[i2];
    }
    return tmp3;
}

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

// @fnv 0x00b3c840
ScaledVec6 FUN_00b3c840_cls::ScaleData(float scale)
{
    ScaledVec6 tmp(m_uiItemCount);
    for (int i = 0; i < m_uiItemCount; i++)
    {
        tmp.m_v[i] = m_data[i] * scale;
    }
    return tmp;
}

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

// @fnv 0x00b3c930
FUN_00b3c930_Obj::FUN_00b3c930_Obj()
{
    FNV_00b3cc30();
}

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

// Constructor initializing flags, floats and integer fields to their default values.
// @fnv 0x00b3cd60
FUN_00b3cd60::FUN_00b3cd60()
    : m_b00(true), m_f04(1.0f), m_i0c(2), m_f28(0.5f), m_f2c(0.75f), m_f30(0.8f), m_i34(1), m_i40(3), m_i44(4),
      m_i48(0), m_i4c(0), m_i50(0), m_i54(0)
{
    float afUnused[38];
}

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

// Calls Clear(true, 0) on the embedded StringLike member m_str.
// @fnv 0x00b3d800
void FUN_00b3d800_cls::ClearString()
{
    int unusedA;
    int unusedB;
    int unusedC;
    int unusedD;
    int unusedE;
    {
        StringLike* p = &this->m_str;
        p->Clear(true, 0);
    }
}

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

// Reads an element at offset unk00 within the buffer, calling FUN_00ec7c56 if the offset is out of range.
// @fnv 0x00b3efe0
unsigned int FNV_00b3efe0_Obj::GetElementAtOffset()
{
    unsigned int off = unk00;
    FNV_00b3efe0_Buffer* base = &unk04;
    if (off >= (base->unk10 - base->unk0c))
    {
        FUN_00ec7c56();
    }
    unsigned int* elem = (unsigned int*)(base->unk0c + off);
    return *elem;
}

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
// @fnv 0x00b3fdd0
void __thiscall FUN_00b3fdd0_class::FUN_00b3fdd0(FUN_00b37880_class* value)
{
    if (unk5c != value)
    {
        FUN_00b37880_class* ptr = unk5c;
        FUN_00b37880_class* old = ptr;
        old ? ((((old->FUN_00b37880(), 1) & 1) ? _Deallocate(old) : (void)0), old) : 0;
        unk5c = value;
    }
}

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

// Sets unk00 to DAT_010173e8, calls FUN_0044a730(1, 0) on unk0c, then calls FUN_00ec79a1.
// @fnv 0x00b3c3b0
void FUN_00b3c3b0_Class::Initialize()
{
    int unused04;
    int unused08;
    int unused0c;
    int unused10;
    int unused14;

    this->unk00 = &DAT_010a57fc;
    this->unk00 = &DAT_010173e8;
    this->unk0c.FUN_0044a730(1, 0);
    this->FUN_00ec79a1();
}

struct PtrVector
{
    int unk00[3];
    void** m_ppFirst;  // +0x0c
    void** m_ppLast;   // +0x10
    void** m_ppEnd;    // +0x14

    void*& FUN_00b31230(unsigned int uiPos);
};

// @fnv 0x00b31230
void*& PtrVector::FUN_00b31230(unsigned int uiPos)
{
    if (uiPos >= (unsigned int)(m_ppLast - m_ppFirst))
        FUN_00ec7c56();
    return m_ppFirst[uiPos];
}

unsigned int FUN_00ec7c56();

struct FUN_00b2ac30_t
{
    int* m_00;
    int m_04;
    bool FUN_00b2ac30(FUN_00b2ac30_t* other);
};

// @fnv 0x00b2ac30
bool FUN_00b2ac30_t::FUN_00b2ac30(FUN_00b2ac30_t* other)
{
    if (!(static_cast<bool>(static_cast<int>(m_00 != 0)) && static_cast<bool>(static_cast<int>(m_00 == other->m_00))))
        FUN_00ec7c56();
    return static_cast<bool>(static_cast<int>(m_04 == other->m_04));
}

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

// Builds a 2D rotation matrix from angle and multiplies it into the current matrix.
// @fnv 0x00b273d0
void __thiscall Mat::FUN_00b273d0(float angle)
{
    Mat hold;
    Mat buf;
    Mat rot;
    float fCos;
    float fSin;
    rot.FUN_00b12af0();
    fCos = (float)(double)(float)FUN_00ec9f30((double)(float)(angle / DAT_010a4d90));
    fSin = (float)(double)(float)FUN_00eca060((double)(float)(angle / DAT_010a4d90));
    rot.m00 = fCos;
    rot.m01 = fSin;
    rot.m02 = 0.0f;
    rot.m10 = -fSin;
    rot.m11 = fCos;
    rot.m12 = 0.0f;
    rot.m20 = 0.0f;
    rot.m21 = 0.0f;
    rot.m22 = 1.0f;
    *this = *rot.Multiply(&buf, this);
}

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

// @fnv 0x00b32600
void IntVector::FUN_00b32600(unsigned int ItemUpdateArray, const int& kVal)
{
    int aiUnused[0x26];
    if (ResizeArray(ItemUpdateArray))
    {
        try
        {
            int* pPtr = m_pFirst;
            int aiMore[7];
            FUN_00b35ca0(pPtr, ItemUpdateArray, kVal, m_kAl);
            m_pLast = pPtr + ItemUpdateArray;
        }
        catch (...)
        {
            FUN_00b17f50();
            throw;
        }
    }
}

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
// Frees the mC buffer via _Deallocate after calling Update, then zeroes mC, m10, and m14.
// @fnv 0x00b3db50
void S_00b3db50::FUN_00b3db50()
{
    int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    if (mC)
    {
        ((FUN_00b2e250_cls*)this)->Update(mC, m10);
        int a = (m14 - mC) / 0x54;
        int b5 = mC;
        _Deallocate((void*)b5);
    }
    mC = 0;
    m10 = 0;
    m14 = 0;
}

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
// If FUN_00b1f590(n) succeeds, calls FUN_00b360a0 on m_0c with n and value and sets m_10 to m_0c + n; on exception calls FUN_00b32c60 and rethrows.
// @fnv 0x00b32780
void Vec32780::FUN_00b32780(int n, const Item32780* value)
{
    int filler[25];
    if (FUN_00b1f590(n))
    {
        try
        {
            unsigned char a;
            Item32780* c;
            Item32780* b;
            unsigned char h;
            c = m_0c;
            b = c;
            Tag32780 p = {};
            h = a;
            FUN_00b360a0(b, n, value, &m_08, h, p.v);
            m_10 = c + n;
            {
                int tail[14];
            }
        }
        catch (...)
        {
            FUN_00b32c60();
            throw;
        }
    }
}

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

// If _First.FUN_00b16830(&_Last) is true, calls FUN_00b35b60 and FUN_00b33110 and sets m_last to the new value; returns the first iterator.
// @fnv 0x00b33030
ProbePair S_B33030::FUN_00b33030(ProbePair first, ProbePair last)
{
    ProbePair _First;
    ProbePair _Last;
    {
        unsigned int new_last;
        int j_pad0[12];
        int e_pad1[12];

        _First.m_00 = 0;
        if (this == 0 || this->m_pHeadNode > first.m_04 || first.m_04 > this->m_last)
            FUN_00ec7c56();
        _First.m_00 = this->unk00[0];
        _First.m_04 = first.m_04;

        _Last.m_00 = 0;
        if (this == 0 || this->m_pHeadNode > last.m_04 || last.m_04 > this->m_last)
            FUN_00ec7c56();
        _Last.m_00 = this->unk00[0];
        _Last.m_04 = last.m_04;

        if (_First.FUN_00b16830(&_Last))
        {
            new_last = (unsigned int)FUN_00b35b60(_Last.m_04, this->m_last, _First.m_04);
            this->FUN_00b33110(new_last, this->m_last);
            this->m_last = new_last;
        }
    }

    return _First;
}

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
// Writes the unsigned short at src into each of the count elements of dst.
// @fnv 0x00b36b80
void FUN_00b36b80(unsigned short* dst, unsigned int count, const unsigned short* src)
{
    CheckedTag aChecked = {};
    ScalarTag categoryB;
    CheckedTag checkedCopy4 = aChecked;
    ScalarTag categoryCopy_ = categoryB;
    unsigned short* base7 = dst;
    unsigned short* last = base7 + count;
    RandomTag random = {};
    RandomTag randomCopyB = random;
    unsigned int remaining = count;
    unsigned short* first2 = base7;
    for (; remaining > 0; remaining--, first2++)
    {
        *first2 = *src;
    }
}

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

// Initializes the object's fields and copies three default parameter blocks into m_04, m_3c, and m_7c.
// @fnv 0x00b29fd0
FUN_00b29fd0_cls* FUN_00b29fd0_cls::FUN_00b29fd0()
{
    unk00 = 0;
    unk38 = 0;
    unk70 = 0.5f;
    unk74 = 0;
    unk78 = 0;

    FUN_00b29fd0_Params first;
    first.f00 = 0.8f;
    first.f04 = 0.8f;
    first.f08 = 0.8f;
    first.f0c = 0.2f;
    first.f10 = 0.2f;
    first.f14 = 0.2f;
    first.f18 = 0.0f;
    first.f1c = 0.0f;
    first.f20 = 0.0f;
    first.f24 = 0.0f;
    first.f28 = 0.0f;
    first.f2c = 0.0f;
    first.f30 = 0.0f;

    FUN_00b29fd0_Params second;
    second.f00 = 1.0f;
    second.f04 = 1.0f;
    second.f08 = 1.0f;
    second.f0c = 0.5f;
    second.f10 = 0.5f;
    second.f14 = 0.5f;
    second.f18 = 0.0f;
    second.f1c = 0.0f;
    second.f20 = 0.0f;
    second.f24 = 0.0f;
    second.f28 = 0.0f;
    second.f2c = 0.0f;
    second.f30 = 0.0f;

    FUN_00b29fd0_Params third;
    third.f00 = 1.0f;
    third.f04 = 1.0f;
    third.f08 = 1.0f;
    third.f0c = 0.5f;
    third.f10 = 0.5f;
    third.f14 = 0.5f;
    third.f18 = 0.0f;
    third.f1c = 0.0f;
    third.f20 = 0.0f;
    third.f24 = 0.0f;
    third.f28 = 0.0f;
    third.f2c = 0.0f;
    third.f30 = 0.0f;

    memcpy(&m_04, &first, sizeof(first));
    memcpy(&m_3c, &second, sizeof(second));
    memcpy(&m_7c, &third, sizeof(third));
    return this;
}

struct FUN_00b3f070 : FUN_00b3f0a0_Class
{
    void FUN_00b3f0a0();
    virtual ~FUN_00b3f070();
};

// Empty destructor for FUN_00b3f070, inheriting from FUN_00b3f0a0_Class.
// @fnv 0x00b3f070
FUN_00b3f070::~FUN_00b3f070()
{}

namespace fnv_00b2e810 {
struct MemberA
{
    int a0;
    int a4;
    int a8;
    int aC;
    int a10;
    int a14;
    MemberA();
    ~MemberA();
};
struct MemberB
{
    int b0;
    int b4;
    int b8;
    int bC;
    int b10;
    int b14;
    MemberB();
    ~MemberB();
};
struct MemberC
{
    int c0;
    int c4;
    int c8;
    int cC;
    int c10;
    int c14;
    MemberC();
    ~MemberC();
};
struct MemberD
{
    int d0;
    int d4;
    int d8;
    int dC;
    int d10;
    int d14;
    MemberD();
    ~MemberD();
};
struct MemberE
{
    int e0;
    int e4;
    int e8;
    int eC;
    int e10;
    int e14;
    MemberE();
    ~MemberE();
};

class FUN_00b2e810
{
  public:
    unsigned char flag00;
    int value04;
    bool flag08;
    bool flag09;
    int unk0C;
    unsigned short unk10;
    bool flag12;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short unk22;
    unsigned short unk24;
    unsigned short unk26;
    MemberA list28;
    MemberB list40;
    MemberB list58;
    MemberC list70;
    MemberD list88;
    MemberD listA0;
    MemberD listB8;
    MemberD listD0;
    MemberD listE8;
    MemberD list100;
    MemberD list118;
    MemberE list130;
    MemberD list148;
    MemberD list160;
    MemberE list178;

    FUN_00b2e810(int value, unsigned char flag);
};

struct Scratch60
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34,
        unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
};

// Sets flag00 and value04 from its arguments, initializes the listed scalar fields, and default-constructs the list members; the Scratch60 local is unused.
// @fnv 0x00b2e810
FUN_00b2e810::FUN_00b2e810(int value, unsigned char flag)
    : flag00(flag), value04(value), flag08(false), flag09(false), unk0C(0), unk10(0), flag12(true), unk14(2), unk20(0),
      unk22(0), unk24(0), unk26(0)
{
    Scratch60 scratch;
}
}  // namespace fnv_00b2e810

class OwnerB3ff90
{
  public:
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    FUN_00b37880_class* m_6c;
    void FUN_00b3ff90(FUN_00b37880_class* a);
};

// If a differs from m_6c, calls FUN_00b37880 then FormHeap_Free on the old m_6c, and stores a in m_6c.
// @fnv 0x00b3ff90
void OwnerB3ff90::FUN_00b3ff90(FUN_00b37880_class* a)
{
    if (m_6c != a)
    {
        FUN_00b37880_class* saved = m_6c;
        FUN_00b37880_class* old = saved;
        old ? ((((old->FUN_00b37880(), 1) & 1) ? FormHeap_Free(old) : (void)0), old) : 0;
        m_6c = a;
    }
}
