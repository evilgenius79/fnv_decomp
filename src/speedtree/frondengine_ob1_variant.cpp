
// src/speedtree/frondengine_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/frondengine.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/frondengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/frondengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00b1ada0_class
{
    float a;
    float b;
    float c;
    FUN_00b1ada0_class* FUN_00b1ada0(float x, float y, float z);
};
struct FUN_00b1add0
{
    float f0;
    float f4;
    float f8;
    void Set(float a, float b, float c);
};
struct FUN_00b39460_class
{
    void __thiscall FUN_00b39460();
};
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
unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_00b30fd0_class
{
    unsigned int FUN_00b30fd0(unsigned int n);
};
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
void __cdecl FUN_00b269d0(char* a, char* b, char* c, bool d);
void __cdecl FUN_00b26160(char* a, char* b, char* c, bool d);
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
void* __cdecl FUN_00b23980(unsigned int n);
void __cdecl CopyObjects(CopyableStateBlock* dst, unsigned int n, const CopyableStateBlock* src);

struct FUN_00b37880
{
    ~FUN_00b37880();
};

struct Host
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
    FUN_00b37880* unk40;

    void FUN_00b18f60(FUN_00b37880* arg);
};

// @fnv 0x00b18f60
void Host::FUN_00b18f60(FUN_00b37880* arg)
{
    if (this->unk40 != arg)
    {
        delete this->unk40;
        this->unk40 = arg;
    }
}

extern int* FrondAllocateProxy(unsigned int, unsigned int);
extern double FUN_00ec6054(double);
extern const double DAT_010a4d90;
extern double FUN_00ec9f30(double);
extern double FUN_00eca060(double);
extern const float DAT_010a54e8;
extern const float DAT_010a54ec;
extern const float DAT_01016248;

struct FrondMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    __forceinline void set(float a, float b, float c, float d, float e, float f, float g, float h, float i)
    {
        m00 = a;
        m01 = b;
        m02 = c;
        m10 = d;
        m11 = e;
        m12 = f;
        m20 = g;
        m21 = h;
        m22 = i;
    }
    __forceinline FrondMatrix()
    {
        set(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    }
    inline FrondMatrix Multiply(const FrondMatrix& b) const
    {
        FrondMatrix r;
        r.m00 = m00 * b.m00 + m01 * b.m10 + m02 * b.m20;
        r.m01 = m00 * b.m01 + m01 * b.m11 + m02 * b.m21;
        r.m02 = m00 * b.m02 + m01 * b.m12 + m02 * b.m22;
        r.m10 = m10 * b.m00 + m11 * b.m10 + m12 * b.m20;
        r.m11 = m10 * b.m01 + m11 * b.m11 + m12 * b.m21;
        r.m12 = m10 * b.m02 + m11 * b.m12 + m12 * b.m22;
        r.m20 = m20 * b.m00 + m21 * b.m10 + m22 * b.m20;
        r.m21 = m20 * b.m01 + m21 * b.m11 + m22 * b.m21;
        r.m22 = m20 * b.m02 + m21 * b.m12 + m22 * b.m22;
        return FrondMatrix(r);
    }
    inline void FUN_00b1ae00(float angle)
    {
        FrondMatrix rotation;
        rotation.m11 = (float)FUN_00ec9f30((float)(angle / DAT_010a4d90));
        float sine = (float)FUN_00eca060((float)(angle / DAT_010a4d90));
        rotation.m00 = 1.0f;
        rotation.m01 = 0.0f;
        rotation.m02 = 0.0f;
        rotation.m10 = 0.0f;
        rotation.m12 = sine;
        rotation.m20 = 0.0f;
        rotation.m21 = -sine;
        rotation.m22 = rotation.m11;
        FrondMatrix incoming = *this;
        *this = rotation.Multiply(incoming);
    }
};
struct FrondPoint
{
    float x, y, z;
    __forceinline FrondPoint(int)
    {}
    __forceinline void zero()
    {
        z = 0.0f;
        y = 0.0f;
        x = 0.0f;
    }
    __forceinline FrondPoint()
    {
        zero();
    }
    __forceinline FrondPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    FrondPoint FUN_00b12890(const FrondMatrix&) const;
    FrondPoint FUN_00b13040(const FrondPoint&) const;
    FrondPoint AddVector(const FrondPoint&) const;
    FrondPoint ScaleSwizzled(float) const;
    FrondPoint FUN_00b12810(const FrondPoint&) const;
    inline void FUN_00b12790()
    {
        float lengthSquared = x * x + y * y + z * z;
        float reciprocal = 1.0f / (float)FUN_00ec6054(lengthSquared);
        x *= reciprocal;
        y *= reciprocal;
        z *= reciprocal;
    }
    float FastSqrt();
    inline float FastSqrt() const
    {
        float squared = z * z + (y * y + x * x);
        union FloatBits
        {
            float f;
            int i;
        } estimate;
        estimate.f = squared;
        estimate.i = (estimate.i >> 1) + 0x1fc00000;
        return estimate.f;
    }
    float FUN_00b04d40(const FrondPoint&) const;
    FrondPoint* FUN_00b1ada0(float, float, float);
    void Set(float, float, float);
};
struct FrondGuidePoint : FrondPoint
{
    FrondMatrix rotation;
    float scale;
    unsigned char material;
};
struct FrondPointStorage
{
    int a, b, c;
    FrondPoint *first, *last, *limit;
    void FUN_00b39460();
    __forceinline ~FrondPointStorage()
    {
        FUN_00b39460();
    }
};
struct FrondPointList : FrondPointStorage
{
    inline FrondPointList()
    {
        int* proxy = FrondAllocateProxy(1, 0);
        int* linked = proxy;
        if (linked)
            *linked = (int)this;
        a = (int)linked;
        b = 0;
        c = 0;
        first = 0;
        last = 0;
        limit = 0;
    }
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline FrondPoint& operator[](unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return first[i];
    }
    void FUN_00b1e4c0(const FrondPoint&);
    void FUN_00b1fca0();
    __forceinline ~FrondPointList()
    {
        FUN_00b1fca0();
    }
};
struct FrondFloatStorage
{
    int a, b, c;
    float *first, *last, *limit;
    void FUN_0065d6e0();
    __forceinline ~FrondFloatStorage()
    {
        FUN_0065d6e0();
    }
};
struct FrondFloatList : FrondFloatStorage
{
    FrondFloatList();
    void FUN_0065f240();
    void PushBack(const float&);
    float* FUN_006578b0(unsigned int);
    __forceinline ~FrondFloatList()
    {
        FUN_0065f240();
    }
};
struct FrondOutput
{
    int u00, u04;
    unsigned char enabled;
    int u0c, u10, u14, u18, u1c;
    unsigned short u20, count;
    __forceinline unsigned short getCount() const
    {
        return count;
    }
    __forceinline unsigned char isEnabled() const
    {
        return enabled;
    }
    __forceinline void advance()
    {
        ++count;
    }
    __forceinline void setCount(unsigned int n)
    {
        count = (unsigned short)n;
    }
    void FUN_00b300c0(const FrondPoint&);
    void FUN_00b301f0(const float*, unsigned short);
    void FUN_00b30020(const float*);
    void FUN_00b30190(const float*);
    void FUN_00b305f0(const FrondPoint&);
    void FUN_00b30660(const FrondPoint&);
    void FUN_00b30560(float, unsigned char);
    FrondPoint* FUN_00b30f80(unsigned int);
    float* FUN_00b30fd0(unsigned int);
};
struct FrondInput
{
    int a, b, c;
    FrondGuidePoint *first, *last, *limit;
    float u18, width;
    unsigned char layer;
    float angle, u28, u2c;
    unsigned int start, stride;
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline FrondGuidePoint& operator[](unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return first[i];
    }
    FrondGuidePoint* FUN_00b1db00(unsigned int);
};
struct FrondBuilder
{
    FrondOutput* output;
    void* required;
    int u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38;
    unsigned int slices;
    void FUN_00b19ad0(FrondInput* input);
};

// @fnv 0x00b19ad0
void FrondBuilder::FUN_00b19ad0(FrondInput* input)
{
    if (output && required)
    {
        float step = 180.0 / slices;
        input->start = output->getCount();
        input->stride = 2;
        for (unsigned int slice = 0; slice < slices; ++slice)
        {
            unsigned int begin4 = output->getCount();
            FrondPointList directionX;
            FrondPoint normalChild3;
            float colorAlloc2[4];
            for (unsigned int i = 0; i < input->size(); ++i)
            {
                FrondMatrix rotationSlot17;
                if (i < input->size() - 1)
                    rotationSlot17 = (*input)[i].rotation;
                else
                    rotationSlot17 = (*input)[i - 1].rotation;
                rotationSlot17.FUN_00b1ae00(slice * step + input->angle);
                FrondPoint direction = FrondPoint(0.0f, 1.0f, 0.0f).FUN_00b12890(rotationSlot17);
                directionX.FUN_00b1e4c0(direction);
                FrondPoint tangentVal;
                if (i == 0)
                    tangentVal = (*input)[i + 1].FUN_00b13040((*input)[0]);
                else
                    tangentVal = (*input)[i].FUN_00b13040((*input)[0]);
                tangentVal.FUN_00b12790();
                FrondPoint left2, right8;
                if (i == input->size() - 1 && input->size() > 0)
                {
                    left2 = (*input)[i].AddVector(directionX[i - 1].ScaleSwizzled(input->width));
                    right8 = (*input)[i].FUN_00b13040(directionX[i - 1].ScaleSwizzled(input->width));
                }
                else if (i > 0 && i < input->size() - 1)
                {
                    FrondPoint prior;
                    prior = (*input)[i].AddVector(directionX[i - 1].ScaleSwizzled(input->width));
                    left2 = (*input)[i].AddVector(direction.ScaleSwizzled(input->width));
                    left2 = left2.AddVector(prior).ScaleSwizzled(DAT_01016248);
                    prior = (*input)[i].FUN_00b13040(directionX[i - 1].ScaleSwizzled(input->width));
                    right8 = (*input)[i].FUN_00b13040(direction.ScaleSwizzled(input->width));
                    right8 = right8.AddVector(prior).ScaleSwizzled(DAT_01016248);
                }
                else
                {
                    left2 = (*input)[i].AddVector(direction.ScaleSwizzled(input->width));
                    right8 = (*input)[i].FUN_00b13040(direction.ScaleSwizzled(input->width));
                }
                float v3 = i / (input->size() - 1.0);
                output->FUN_00b300c0(left2);
                float uv1[2];
                uv1[0] = 1.0f;
                uv1[1] = v3;
                output->FUN_00b301f0(uv1, (unsigned short)input->layer);
                colorAlloc2[0] = colorAlloc2[1] = colorAlloc2[2] = colorAlloc2[3] = 1.0f;
                output->FUN_00b30020(colorAlloc2);
                output->FUN_00b30190(&tangentVal.x);
                output->FUN_00b305f0(direction);
                normalChild3 = direction.FUN_00b12810(tangentVal);
                if (static_cast<const FrondPoint&>(normalChild3).FastSqrt() < DAT_010a54ec)
                    normalChild3 = tangentVal;
                else
                    normalChild3.FUN_00b12790();
                output->FUN_00b30660(normalChild3);
                if (output->isEnabled())
                    output->FUN_00b30560((*input)[i].scale, (*input)[i].material);
                output->advance();
                output->FUN_00b300c0(right8);
                uv1[0] = 0.0f;
                output->FUN_00b301f0(uv1, (unsigned short)input->layer);
                colorAlloc2[0] = colorAlloc2[1] = colorAlloc2[2] = colorAlloc2[3] = 1.0f;
                output->FUN_00b30020(colorAlloc2);
                output->FUN_00b30190(&tangentVal.x);
                output->FUN_00b305f0(direction);
                normalChild3 = direction.FUN_00b12810(tangentVal);
                if (normalChild3.FastSqrt() < DAT_010a54ec)
                    normalChild3 = tangentVal;
                else
                    normalChild3.FUN_00b12790();
                output->FUN_00b30660(normalChild3);
                if (output->isEnabled())
                    output->FUN_00b30560(input->FUN_00b1db00(i)->scale, (*input)[i].material);
                output->advance();
            }
            float totalLeft6 = 0.0f, totalRight9 = 0.0f;
            FrondFloatList LeftX, rightVal;
            unsigned int count30 = input->size();
            for (unsigned int i = 0; i < count30 - 1; ++i)
            {
                FrondPoint* firstLocalVal = output->FUN_00b30f80(input->start + i * 2);
                FrondPoint* secondValue3 = output->FUN_00b30f80(input->start + i * 2 + 2);
                FrondPoint aA1(firstLocalVal->x, firstLocalVal->y, firstLocalVal->z);
                FrondPoint b111(0);
                b111.FUN_00b1ada0(secondValue3->x, secondValue3->y, secondValue3->z);
                totalLeft6 += aA1.FUN_00b04d40(b111);
                LeftX.PushBack(totalLeft6);
                firstLocalVal = output->FUN_00b30f80(input->start + i * 2 + 1);
                secondValue3 = output->FUN_00b30f80(input->start + i * 2 + 3);
                aA1.Set(firstLocalVal->x, firstLocalVal->y, firstLocalVal->z);
                b111.Set(secondValue3->x, secondValue3->y, secondValue3->z);
                totalRight9 += aA1.FUN_00b04d40(b111);
                rightVal.PushBack(totalRight9);
            }
            output->setCount(begin4 + 2);
            for (unsigned int i = 1; i < count30 - 1; ++i)
            {
                float* original4 = output->FUN_00b30fd0(input->start + i * 2);
                float uv3[2];
                uv3[0] = *original4;
                uv3[1] = *LeftX.FUN_006578b0(i - 1) / totalLeft6 * DAT_010a54e8;
                output->FUN_00b301f0(uv3, (unsigned short)input->layer);
                output->advance();
                original4 = output->FUN_00b30fd0(input->start + i * 2 + 1);
                float uvs5[2];
                uvs5[0] = *original4;
                uvs5[1] = *rightVal.FUN_006578b0(i - 1) / totalRight9 * DAT_010a54e8;
                output->FUN_00b301f0(uvs5, (unsigned short)input->layer);
                output->advance();
            }
            output->advance();
            output->advance();
        }
    }
}

unsigned int __cdecl FUN_00ec7c56(void);

class _Container_base_aux;

class _Aux_cont
{
  public:
    const _Container_base_aux* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_aux* _Mycontainer;
};

class _Container_base_aux
{
  public:
    _Aux_cont* _Myownedaux;
};

template <class _Alloc> class _Container_base_aux_alloc_real : public _Container_base_aux
{
  public:
    int _Alaux;
};

class _Iterator_base_aux
{
  public:
    const _Container_base_aux* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }

    bool _Has_container() const
    {
        return _Myaux != 0;
    }

    const _Aux_cont* _Myaux;
};

struct Element
{
    char data[12];
};

struct _Vector_val : public _Container_base_aux_alloc_real<int>
{
    int _Alval;
};

struct Vector_standin : public _Vector_val
{
    Element* _Myfirst;
    Element* _Mylast;
    Element* _Myend;
};

struct Iter : public _Iterator_base_aux
{
    Element* _Myptr;

    Iter* __thiscall FUN_00b235e0(int _Off);
};

// @fnv 0x00b235e0
Iter* __thiscall Iter::FUN_00b235e0(int _Off)
{
    if (!_Has_container())
        FUN_00ec7c56();
    if (_Myptr + _Off > ((Vector_standin*)_Getmycont())->_Mylast ||
        _Myptr + _Off < ((Vector_standin*)_Getmycont())->_Myfirst)
        FUN_00ec7c56();
    _Myptr += _Off;
    return this;
}

namespace std {
class exception
{
  public:
    exception(const char* const& _Message = 0);
    virtual ~exception();
    const char* _mWhat;
    int _mDoFree;
};
class bad_alloc : public exception
{
};
}
void* __cdecl operator new(unsigned int);

// @fnv 0x00b23b50
void* __cdecl FUN_00b23b50(unsigned int n)
{
    if (n <= 0)
    {
        n = 0;
    }
    else
    {
        if ((unsigned)-1 / n < 44)
        {
            throw std::bad_alloc();
        }
    }
    return operator new(n * 44);
}

inline void* __cdecl operator new(unsigned int, void* _Where) throw()
{
    return (_Where);
}

struct GlobalObject_00b3f100
{
    int m_kNextStreamField[6];
    ~GlobalObject_00b3f100();
};

// @fnv 0x00b25a90
GlobalObject_00b3f100* __cdecl FUN_00b25a90(GlobalObject_00b3f100* pkCurrentObject, GlobalObject_00b3f100* pkLast,
                                            GlobalObject_00b3f100* pkDest)
{
    GlobalObject_00b3f100* pkNext = pkDest;
    try
    {
        for (; pkCurrentObject != pkLast; ++pkDest, ++pkCurrentObject)
        {
            void* pvWhere = pkDest;
            ::new (pvWhere) GlobalObject_00b3f100(*pkCurrentObject);
        }
    }
    catch (...)
    {
        for (; pkNext != pkDest; ++pkNext)
            pkNext->~GlobalObject_00b3f100();
        throw;
    }
    return pkDest;
}

void __cdecl FormHeap_Free(void* p);
template <class T> inline void Swp(T& a, T& b)
{
    if (&a != &b)
    {
        T t = a;
        a = b;
        b = t;
    }
}
struct Proxy
{
    int* pCont;
};
struct VecBase
{
    inline Proxy*& PP()
    {
        return *(Proxy**)this;
    }
    inline void Dealloc(void* q)
    {
        FormHeap_Free(q);
    }
    ~VecBase()
    {
        Dealloc(PP());
    }
    inline void SwapAll(VecBase& r)
    {
        Swp(PP(), r.PP());
        Swp(*PP(), *r.PP());
    }
};
inline void DeadX()
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
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
    int d30;
    int d31;
    int d32;
    int d33;
    int d34;
    int d35;
    int d36;
    int d37;
    int d38;
    int d39;
    int d40;
    int d41;
    int d42;
    int d43;
    int d44;
    int d45;
    int d46;
    int d47;
    int d48;
    int d49;
    int d50;
    int d51;
    int d52;
    int d53;
    int d54;
    int d55;
    int d56;
    int d57;
    int d58;
    int d59;
    int d60;
    int d61;
    int d62;
    int d63;
    int d64;
    int d65;
    int d66;
    int d67;
    int d68;
    int d69;
    int d70;
    int d71;
    int d72;
    int d73;
    int d74;
    int d75;
    int d76;
    int d77;
    int d78;
    int d79;
    int d80;
}
struct Alloc
{
    inline bool operator==(const Alloc&) const
    {
        return true;
    }
};
struct FUN_0065f240
{
    Proxy* pProxy;
    int i4;
    Alloc al;
    int* pFirst;
    int* pLast;
    int* pEnd;
    ~FUN_0065f240();
};
struct FUN_00b22ff0 : VecBase
{
    FUN_0065f240 e;
    FUN_00b22ff0(const FUN_00b22ff0& r);
    ~FUN_00b22ff0()
    {}
    FUN_00b22ff0& FUN_00b1d5d0(const FUN_00b22ff0& r);
    void FUN_00b26570(FUN_00b22ff0& r);
};
// @fnv 0x00b26570
void FUN_00b22ff0::FUN_00b26570(FUN_00b22ff0& r)
{
    if (this == &r)
        ;
    else if (e.al == r.e.al)
    {
        SwapAll(r);
        Swp(e.pFirst, r.e.pFirst);
        Swp(e.pLast, r.e.pLast);
        Swp(e.pEnd, r.e.pEnd);
    }
    else
    {
        SwapAll(r);
        FUN_00b22ff0 tmp(*this);
        FUN_00b1d5d0(r);
        r.FUN_00b1d5d0(tmp);
        DeadX();
    }
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
        do
        {
        } while (0);
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
struct Elem6830
{
    int unk00;
};
class FUN_00b16830_Iterator : public _Vector_const_iteratorS<Elem6830>
{
  public:
    bool FUN_00b16830(const _Vector_const_iteratorS<Elem6830>& _Right) const;
};

// @fnv 0x00b16830
bool FUN_00b16830_Iterator::FUN_00b16830(const _Vector_const_iteratorS<Elem6830>& _Right) const
{
    return (!(*this == _Right));
}

void __cdecl InvalidParameterNoInfoX16890();
struct ContainerBaseAuxX16890
{
};
class AuxContX16890
{
  public:
    const ContainerBaseAuxX16890* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX16890* _Mycontainer;
};
class IteratorBaseAuxX16890
{
  public:
    const ContainerBaseAuxX16890* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX16890* _Myaux;
};
struct ElemX16890
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct VectorX16890 : public ContainerBaseAuxX16890
{
    AuxContX16890* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX16890* _Myfirst;
    ElemX16890* _Mylast;
    ElemX16890* _Myend;
};
class FUN_00b16890_It : public IteratorBaseAuxX16890
{
  public:
    FUN_00b16890_It& FUN_00b16890(int _Off);
    ElemX16890* _Myptr;
};

// @fnv 0x00b16890
FUN_00b16890_It& FUN_00b16890_It::FUN_00b16890(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoX16890();
    if (!(_Myptr + _Off <= ((VectorX16890*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorX16890*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoX16890();
    _Myptr += _Off;
    return *this;
}

void __cdecl operator delete(void* _Ptr) throw();
extern int DAT_010173f0;
inline void operator delete(void*, void*)
{}
namespace dtorb181 {
void FUN_00ec7c56();
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
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
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned int*, unsigned int*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
struct GvRangeCheckedTag
{
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
template <class I> inline I GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline I GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline I GvCheckedBase(const I& _It)
{
    GvUnchangedTag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline I GvCheckedBase(I& _It)
{
    GvUnchangedTag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
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
    {
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    }
    return _Result;
}
template <class T1, class T2, class A>
inline T2 GvUninitCopy(T1 _First, T1 _Last, T2 _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    T2 _Result = _Dest + _Count;
    if (_Count > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    }
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
    void _Orphan_all() const
    {}
};
struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(GvAlloc<GvAuxCont> _Al) : _Alaux(_Al)
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
    bool operator!=(const GvIterBase& _Right) const;
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
template <class T> struct GvVectorVal : GvAuxBase
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase(_Al), _Alval(_Al)
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
struct GvInner
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
};
struct GvElemV
{
    GvVector<GvInner> kList;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct GvNamed
{
    BxString kName;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
};
struct GvObj
{
    int unk00;
    ~GvObj();
};
}
using namespace dtorb181;
struct FUN_00b181b0
{
    int unk00;
    int unk04;
    GvVector<GvElemV> kElems;
    GvVector<GvVector<GvElemV> > kGroups;
    int unk38;
    int unk3c;
    GvObj* pObj;
    int unk44;
    int unk48;
    int unk4c;
    GvVector<GvNamed> kNames;
    ~FUN_00b181b0();
};
// @fnv 0x00b181b0
FUN_00b181b0::~FUN_00b181b0()
{
    delete pObj;
    pObj = 0;
}

extern int DAT_010173f0;
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0()
    {
        FUN_0044a730(false, 0);
    }
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r)
    {
        FUN_0044a730(false, 0);
        AssignSubstring(r, 0, *(unsigned*)&DAT_010173f0);
    }
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool b, unsigned n);
    FUN_0044a4c0& AssignSubstring(const FUN_0044a4c0& r, unsigned o, unsigned n);
    FUN_0044a4c0& operator=(const FUN_0044a4c0& r)
    {
        return AssignSubstring(r, 0, *(unsigned*)&DAT_010173f0);
    }
    FUN_0044a4c0 FUN_00b09f90();
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
struct RQ : FUN_0044a4c0
{
};
FUN_0044a4c0 FUN_00b18860(const char* fmt, ...);
struct RQ;
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float FUN_00b3ed20();
    int FUN_00b13970();
    bool FUN_00b06180();
    FUN_0044a4c0 FUN_00b3ee40();
};
struct PQ : FUN_0044a4c0
{
    PQ(FUN_0044a4c0 s) : FUN_0044a4c0(s)
    {}
};
struct SQ : FUN_0044a4c0
{
    SQ();
};
struct TexQ
{
    SQ strName;
    float fA, fB, fC, fD;
    TexQ()
    {
        fA = 0.5f;
        fB = 1.0f;
        fC = 0.0f;
        fD = 0.0f;
    }
};
struct TexVec
{
    int ai[4];
    void FUN_00b1e2f0();
    void FUN_00b1e1e0(const TexQ& t);
};
inline void DeadTop()
{
    int aiD[25];
    aiD[14] = 0;
}
inline void DeadEnd()
{
    int aiE[85];
}
struct Frond
{
    int ai[14];
    int i38, i3c, i40, i44, i48;
    bool b4c;
    TexVec kTex;
    int aj[2];
    int i68;
    float f6c, f70, f74, f78;
    int i7c, i80;
    void FUN_00b18f60(int);
    void FUN_00b18340(Parser* p);
};
// @fnv 0x00b18340
void Frond::FUN_00b18340(Parser* p)
{
    DeadTop();
    int iToken = p->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x32ca:
            i48 = p->GetNextElement();
            break;
        case 0x32cb:
            i38 = p->GetNextElement();
            break;
        case 0x32cc:
            i3c = p->GetNextElement();
            break;
        case 0x32cd:
            FUN_00b18f60(p->FUN_00b13970());
            break;
        case 0x32ce:
            i44 = p->GetNextElement();
            break;
        case 0x32cf:
            b4c = p->FUN_00b06180();
            break;
        case 0x32d1:
            i68 = p->GetNextElement();
            break;
        case 0x32d2:
            f6c = p->FUN_00b3ed20();
            break;
        case 0x32d3:
            f70 = p->FUN_00b3ed20();
            break;
        case 0x32d4:
            f74 = p->FUN_00b3ed20();
            break;
        case 0x32d5:
            f78 = p->FUN_00b3ed20();
            break;
        case 0x36b7:
            i7c = p->GetNextElement();
            break;
        case 0x36b8:
            i80 = p->GetNextElement();
            break;
        case 0x32d0: {
            kTex.FUN_00b1e2f0();
            int iCount = p->GetNextElement();
            for (int i = 0; i < iCount; i++)
            {
                TexQ kInfo;
                iToken = p->GetNextElement();
                iToken = p->GetNextElement();
                do
                {
                    switch (iToken)
                    {
                    case 0x36b2: {
                        PQ kName(p->FUN_00b3ee40());
                        (FUN_0044a4c0&)kInfo.strName = kName;
                    }
                        (FUN_0044a4c0&)kInfo.strName = kInfo.strName.FUN_00b09f90();
                        break;
                    case 0x36b3:
                        kInfo.fA = p->FUN_00b3ed20();
                        break;
                    case 0x36b4:
                        kInfo.fB = p->FUN_00b3ed20();
                        break;
                    case 0x36b5:
                        kInfo.fC = p->FUN_00b3ed20();
                        break;
                    case 0x36b6:
                        kInfo.fD = p->FUN_00b3ed20();
                        break;
                    default:
                        throw FUN_00b09480(FUN_00b18860("malformed frond texture information (token %d)", iToken),
                                           false);
                    }
                    iToken = p->GetNextElement();
                } while (iToken != 0x36b1);
                kTex.FUN_00b1e1e0(kInfo);
            }
            break;
        }
        default:
            throw FUN_00b09480(FUN_00b18860("malformed frond info (token %d)", iToken), false);
        }
        iToken = p->GetNextElement();
    } while (iToken != 0x32c9);
    DeadEnd();
}

struct ElemS
{
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
};
struct VecS
{
    int m_alloc0;
    int m_alloc1;
    int m_alloc2;
    ElemS* m_pBegin;
    ElemS* m_pRecordEnd;
    unsigned int size() const;
};
struct TargetS
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    unsigned char unk24;
    unsigned char unk25;
    unsigned short m_usBatches;
    void __forceinline AddBatch()
    {
        m_usBatches++;
    }
    void FUN_00b2fdc0(unsigned short usId, unsigned short* pusIdx, unsigned short usNum);
};
struct MeshS
{
    TargetS* m_pkTarget;
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
    unsigned int m_uiCount;
    void FUN_00b1aed0(unsigned short usId, int iBase, VecS* pkVec);
};
// @fnv 0x00b1aed0
void MeshS::FUN_00b1aed0(unsigned short usId, int iBase, VecS* pkVec)
{
    if (m_pkTarget)
    {
        for (unsigned int i = 0; i < m_uiCount; i++)
        {
            unsigned int k5;
            unsigned short usNum = (unsigned short)((pkVec->m_pRecordEnd - pkVec->m_pBegin) * 2);
            unsigned short* pusIdx = new unsigned short[usNum];
            k5 = 0;
            for (unsigned int j = 0; j < (unsigned int)((pkVec->m_pRecordEnd - pkVec->m_pBegin) * 2); j++)
            {
                pusIdx[k5] = (unsigned short)(i * 2 * (pkVec->m_pRecordEnd - pkVec->m_pBegin) + iBase + j);
                k5++;
            }
            m_pkTarget->FUN_00b2fdc0(usId, pusIdx, usNum);
            m_pkTarget->AddBatch();
        }
    }
}

struct FUN_00b2fdc0_obj
{
    char pad[0x26];
    unsigned short w26;
    void Inc()
    {
        w26++;
    }
    void FUN_00b2fdc0(unsigned short a, unsigned short* p, unsigned short n);
};
struct LodVert
{
    char b[0x38];
};
struct LodGrid
{
    char pad[0xc];
    LodVert* pBegin;
    LodVert* pEnd;
    char pad2[0x34 - 0x14];
    unsigned int uiCols;
};
inline unsigned int Count(const LodGrid* p)
{
    return p->pEnd - p->pBegin;
}
inline float Lerp(float t, float a, unsigned int b)
{
    return a + (b - a) * t;
}
struct FUN_00b1b960_class
{
    FUN_00b2fdc0_obj* m_pEntryObject;
    char pad[0x68 - 4];
    unsigned int m_uiNumLods;
    char pad2[0x7c - 0x6c];
    unsigned int m_uiMinRows;
    unsigned int m_uiMinCols;
    void FUN_00b1b960(unsigned int uiLod, int iOffset, LodGrid* pGrid);
};
// @fnv 0x00b1b960
void FUN_00b1b960_class::FUN_00b1b960(unsigned int uiLod, int iOffset, LodGrid* pGrid)
{
    if (m_pEntryObject)
    {
        float fDetailoef;
        if (m_uiNumLods == 1)
            fDetailoef = 1.0f;
        else
            fDetailoef = 1.0f - uiLod / (m_uiNumLods - 1.0);
        int nRows_l = (int)Lerp(fDetailoef, (float)(m_uiMinRows + 1), Count(pGrid));
        float fRowStepcg = (unsigned int)(pGrid->pEnd - pGrid->pBegin) / (float)(nRows_l - 1);
        int nCols_bqskc = (int)Lerp(fDetailoef, (float)(m_uiMinCols * 2 + 1), pGrid->uiCols);
        float fColStep_nfq = pGrid->uiCols / (float)(nCols_bqskc - 1);
        int nStrips_hanj = nRows_l - 1;
        unsigned int uiNumIndicesws = (nCols_bqskc * 2 + 1) * nStrips_hanj - 1;
        unsigned short* pIndices_gg = new unsigned short[uiNumIndicesws];
        int k_soof = 0;
        for (int i_ofo = 0; i_ofo < nRows_l - 1; i_ofo++)
        {
            int r_uz = (int)(i_ofo * fRowStepcg);
            int r_xvcvu = (int)((i_ofo + 1) * fRowStepcg);
            if (i_ofo == nRows_l - 2 || r_xvcvu > (pGrid->pEnd - pGrid->pBegin) - 1)
                r_xvcvu = (pGrid->pEnd - pGrid->pBegin) - 1;
            int dr = r_xvcvu - r_uz;
            if (i_ofo % 2 == 0)
            {
                int base_l = r_uz * pGrid->uiCols;
                for (int j_ntj = 0; j_ntj < nCols_bqskc; j_ntj++)
                {
                    unsigned int c_o = (unsigned int)(j_ntj * fColStep_nfq);
                    if (j_ntj == nCols_bqskc - 1)
                        c_o = pGrid->uiCols - 1;
                    if (c_o > pGrid->uiCols - 1)
                        c_o = pGrid->uiCols - 1;
                    pIndices_gg[k_soof] = iOffset + base_l + c_o;
                    k_soof++;
                    pIndices_gg[k_soof] = iOffset + base_l + c_o + dr * pGrid->uiCols;
                    k_soof++;
                }
                if (i_ofo < nRows_l - 2)
                {
                    pIndices_gg[k_soof] = pIndices_gg[k_soof - 1];
                    k_soof++;
                }
            }
            else
            {
                int base_uaoxm = r_uz * pGrid->uiCols;
                for (int j_evvina = nCols_bqskc - 1; j_evvina >= 0; j_evvina--)
                {
                    unsigned int c_qv = (unsigned int)(j_evvina * fColStep_nfq);
                    if (j_evvina == nCols_bqskc - 1)
                        c_qv = pGrid->uiCols - 1;
                    if (c_qv > pGrid->uiCols - 1)
                        c_qv = pGrid->uiCols - 1;
                    pIndices_gg[k_soof] = iOffset + base_uaoxm + c_qv;
                    k_soof++;
                    pIndices_gg[k_soof] = iOffset + base_uaoxm + c_qv + dr * pGrid->uiCols;
                    k_soof++;
                }
                if (i_ofo < nRows_l - 2)
                {
                    pIndices_gg[k_soof] = pIndices_gg[k_soof - 1];
                    k_soof++;
                }
            }
        }
        m_pEntryObject->FUN_00b2fdc0((unsigned short)uiLod, pIndices_gg, (unsigned short)uiNumIndicesws);
        m_pEntryObject->Inc();
    }
}

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
struct VBQ
{
    void* p;
    ~VBQ();
};
inline void FreeQ(void* p);
struct ElQ
{
    int m[6];
    ~ElQ();
};
struct AlQ
{
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    __forceinline void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b23e80(ElQ* f, ElQ* l, ElQ* d, RandQ, PtrCatQ, TagQ);
ElQ* __cdecl FUN_00b236a0(ElQ* f, ElQ* l, ElQ* d);
ElQ* __cdecl FUN_00b25a90(ElQ* f, ElQ* l, ElQ* d, AlQ& al, PtrCatQ, TagQ);
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead6()
{
    int a[6];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead12b()
{
    int a[12];
}
inline void Dead6c()
{
    int a[6];
}
inline void Dead2()
{
    int a[8];
}
inline void DC1()
{
    char a;
    char b;
}
inline void DC2()
{
    short a;
}
inline void DC3()
{
    char a[2];
}
inline void Dead6b()
{
    int a[6];
}
inline void Dead26()
{
    int a[26];
}
inline ElQ* Checked_base4(ElQ* const& it)
{
    return it;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_copy(ElQ* f, ElQ* l, ElQ* d)
{
    return FUN_00b23e80(Checked_base2(f), Checked_base2(l), d, RandQ(), Ptr_cat(f, d), TagQ());
}
inline ElQ* Unchecked_uninitialized_copy(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b25a90(Checked_base2(f), Checked_base4(l), d, al, Ptr_cat(f, d), TagQ());
}
__forceinline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    for (; f != l; ++f)
        al.destroy(f);
}
__forceinline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
{
    Destroy_range2(f, l, al, Ptr_cat(f, l));
}
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
    ElQ* _Ucopy(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_copy(f, l, p, m_al);
    }
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b1e750();
    bool FUN_00b1f590(unsigned n);
    VecQ& FUN_00b1d130(const VecQ& _Right);
};
// @fnv 0x00b1d130
VecQ& VecQ::FUN_00b1d130(const VecQ& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
        {
            Dead12();
            FUN_00b1e750();
        }
        else if (_Right.size() <= size())
        {
            ElQ* _Ptr = Unchecked_copy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            _DestroyI(_Ptr, m_last);
            m_last = m_pHeadNode + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            ElQ* _Ptr = _Right.m_pHeadNode + size();
            FUN_00b236a0(_Right.m_pHeadNode, _Ptr, m_pHeadNode);
            Dead2();
            DC1();
            m_last = _Ucopy(_Ptr, _Right.m_last, m_last);
        }
        else
        {
            if (m_pHeadNode != 0)
            {
                _DestroyI(m_pHeadNode, m_last);
                m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
            }
            if (FUN_00b1f590(_Right.size()))
            {
                Dead26();
                m_last = _Ucopy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            }
        }
    }
    return *this;
}

namespace fnv_00b1d8a0 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace vct1d8a0 {
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
struct GvRow38
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
};
}
using namespace vct1d8a0;
struct FUN_00b1d8a0 : GvVectorStore<GvRow38>
{
    FUN_00b1d8a0();
};
// @fnv 0x00b1d8a0
FUN_00b1d8a0::FUN_00b1d8a0() : GvVectorStore<GvRow38>()
{
    _Buy(0);
}
}  // namespace fnv_00b1d8a0

namespace vecdb1d2 {
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
        _Al.destroy(_First);
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
    void _Orphan_all() const
    {}
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Myownedaux->~VdAuxCont();
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
using namespace vecdb1d2;

namespace vecdb1d2 {
struct VdInner
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
};
struct VdElemV : public VdVector<VdInner>
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
};
}
struct FUN_00b1da90 : public VdVectorImpl<VdElemV>
{
    ~FUN_00b1da90();
};

// @fnv 0x00b1da90
FUN_00b1da90::~FUN_00b1da90()
{
    _Tidy();
}

extern unsigned int DAT_011c16bc;

struct S00b1df10_Guard
{
    S00b1df10_Guard()
    {}
    ~S00b1df10_Guard()
    {}
};

struct FUN_00b1df10_obj : FUN_00b1f650_class
{
    void __thiscall FUN_00b1df10();
};

// @fnv 0x00b1df10
void __thiscall FUN_00b1df10_obj::FUN_00b1df10()
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
    {
        S00b1df10_Guard g;
        FUN_00b1f650_class::FUN_00b1f650();
    }
    {
        void* p = *(void**)this;
        FormHeap_Free(p);
    }
}

namespace fnv_00b1e090 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace ctoraca {
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
}
using namespace ctoraca;
struct FUN_00b1e090 : GvVectorStore<BxString>
{
    FUN_00b1e090();
};
// @fnv 0x00b1e090
FUN_00b1e090::FUN_00b1e090() : GvVectorStore<BxString>()
{
    _Buy(0);
}
}  // namespace fnv_00b1e090

struct S00b1e170_cls
{
    void* m_pHeadNode;
    void FUN_00b1f9e0();
    void FUN_00b1e170();
};
struct S00b1e170_guard
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    S00b1e170_guard()
    {}
    ~S00b1e170_guard()
    {}
};
// @fnv 0x00b1e170
void S00b1e170_cls::FUN_00b1e170()
{
    {
        S00b1e170_guard g;
        FUN_00b1f9e0();
    }
    {
        void* p = m_pHeadNode;
        FormHeap_Free(p);
    }
}

namespace vecb1e2 {
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
    VcString kName;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
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
template <class _InIt, class _OutIt> inline _OutIt FUN_00b23830(_InIt _First, _InIt _Last, _OutIt _Dest)
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
            VcElem* _Ptr = FUN_00b23830(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void FUN_00b1e2f0();
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
using namespace vecb1e2;

// @fnv 0x00b1e2f0
void VcVector::FUN_00b1e2f0()
{
    erase(begin(), end());
}

namespace fnv_00b1e3e0 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace vct1e3e0 {
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
struct GvVec3
{
    int unk00;
    int unk04;
    int unk08;
};
}
using namespace vct1e3e0;
struct FUN_00b1e3e0 : GvVectorStore<GvVec3>
{
    FUN_00b1e3e0();
};
// @fnv 0x00b1e3e0
FUN_00b1e3e0::FUN_00b1e3e0() : GvVectorStore<GvVec3>()
{
    _Buy(0);
}
}  // namespace fnv_00b1e3e0

struct EmptyGuard
{
    ~EmptyGuard()
    {}
};

struct S00b1e5d0_Obj : FUN_00b1fe80_helper
{
    void __thiscall FUN_00b1e5d0();
};

// @fnv 0x00b1e5d0
void __thiscall S00b1e5d0_Obj::FUN_00b1e5d0()
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
    {
        EmptyGuard t;
        this->FUN_00b1fe80();
    }
    {
        int v = this->m0;
        FormHeap_Free((void*)v);
    }
}

namespace fnv_00b1e750 {
namespace vecb1e {
void FUN_00ec7c56();
struct VcElem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~VcElem();
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
template <class _InIt, class _OutIt> inline _OutIt FUN_00b236a0(_InIt _First, _InIt _Last, _OutIt _Dest)
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
            VcElem* _Ptr = FUN_00b236a0(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void FUN_00b1e750();
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
using namespace vecb1e;

// @fnv 0x00b1e750
void VcVector::FUN_00b1e750()
{
    erase(begin(), end());
}
}  // namespace fnv_00b1e750

namespace tidyb1e {
struct T1Elem
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
};
struct T1NonscalarTag
{
};
inline T1NonscalarTag T1PtrCat(T1Elem*&, T1Elem*&)
{
    T1NonscalarTag kCat;
    return kCat;
}
struct T1Alloc
{
    void destroy(T1Elem*)
    {}
    void deallocate(T1Elem* ptr, unsigned int count)
    {
        FormHeap_Free(ptr);
    }
    static void FormHeap_Free(void* ptr);
};
inline void T1DestroyRange(T1Elem* first, T1Elem* last, T1Alloc& al, T1NonscalarTag)
{
    for (; first != last; ++first)
    {
        al.destroy(first);
    }
}
inline void T1DestroyRange(T1Elem* first, T1Elem* last, T1Alloc& al)
{
    T1DestroyRange(first, last, al, T1PtrCat(first, last));
}
struct T1Vector
{
    int unk00;
    int unk04;
    T1Alloc kAlval;
    T1Elem* pFirst;
    T1Elem* pLast;
    T1Elem* pEnd;
    void Destroy(T1Elem* first, T1Elem* last)
    {
        T1DestroyRange(first, last, kAlval);
    }
    void FUN_00b1e970();
};
}
using namespace tidyb1e;

// @fnv 0x00b1e970
void T1Vector::FUN_00b1e970()
{
    if (pFirst != 0)
    {
        Destroy(pFirst, pLast);
        kAlval.deallocate(pFirst, pEnd - pFirst);
    }
    pFirst = 0;
    pLast = 0;
    pEnd = 0;
}

void __cdecl FUN_00b0fb80();
int __cdecl FUN_00b23980(unsigned int n, int hint);

inline unsigned int maxsz(unsigned int m)
{
    return m > 0 ? m : 1u;
}

struct FUN_00b1eb00_class
{
    int i0;
    int i4;
    int i8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    bool __thiscall FUN_00b1eb00(unsigned int n);
};

// @fnv 0x00b1eb00
bool FUN_00b1eb00_class::FUN_00b1eb00(unsigned int n)
{
    int CNVal;
    int CN_;
    int Diff2;
    int Diff_;
    int EndLoc_2;
    int EntryLoc;
    int EntryLocA;
    int EntryLocTmp;
    int LeftB;
    int PN4;
    int PNA;
    int StartLoc2;
    int StartLoc7;
    int _AngleYawB;
    int _Dest5;
    int _DestVal;
    int _Dest_;
    int _Diff2;
    int _Dir;
    int _DirZNew;
    int _DirZVal;
    int _DirZ_;
    int _FYaw6;
    int _FYaw9;
    int _FuturePhase6;
    int _FuturePhaseTmp;
    int _HType5;
    int _HeadingA;
    int _KindB;
    int _LastDirZ;
    int _LastZ;
    int _LastZCur;
    int _LastZZ;
    int _NewModeNext;
    int _NewModeX;
    unsigned int CNA;
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    if (n == 0)
        return false;
    else
    {
        CNA = 0x4924924u;
        if (maxsz(CNA) < n)
            FUN_00b0fb80();
        else
        {
            m_iThirdValue = FUN_00b23980(n, 0);
            m_10 = m_iThirdValue;
            m_14 = n * 0x38 + m_iThirdValue;
        }
    }
    return true;
}

namespace fnv_00b1ebc0 {
namespace vecdb1eb {
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
using namespace vecdb1eb;

namespace vecdb1eb {
struct VdInner
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
};
struct VdElemV : public VdVector<VdInner>
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
};
}
struct FUN_00b1ebc0 : public VdVectorImpl<VdElemV>
{
    void FUN_00b1ebc0_Destroy(VdElemV* _First, VdElemV* _Last);
};

// @fnv 0x00b1ebc0
void FUN_00b1ebc0::FUN_00b1ebc0_Destroy(VdElemV* _First, VdElemV* _Last)
{
    VdDestroyRange<VdAlloc<VdElemV> >(_First, _Last, _Alval);
}
}  // namespace fnv_00b1ebc0

namespace fnv_00b1ecf0 {
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
struct ElQ : VBQ
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    int pad[8];
    ElQ(const ElQ&);
    ElQ& operator=(const ElQ&);
    ~ElQ()
    {
        Tidy();
    }
    void Tidy();
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
    int pad[8];
    El2Q(const ElQ&);
    ~El2Q()
    {
        Tidy();
    }
    void Tidy();
};
struct WQ : ElQ
{
    WQ(const ElQ& v) : ElQ(v)
    {}
    ~WQ()
    {}
};
struct W2Q : El2Q
{
    W2Q(const ElQ& v) : El2Q(v)
    {}
    ~W2Q()
    {}
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
ElQ* __cdecl FUN_00b23980(unsigned n, ElQ* p);
ElQ* __cdecl FUN_00b26450(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b24030(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
inline ElQ* Uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ mc, TagQ tg)
{
    return FUN_00b26450(f, l, d, al);
}
ElQ* __cdecl FUN_00b238e0(ElQ* f, ElQ* l, ElQ* d);
void __cdecl FUN_00b24180(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
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
    return Uninitialized_move(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b24180(f, n, v, al, Ptr_cat(f, f), TagQ());
}
inline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    int aP[8];
    for (; f != l; ++f)
        al.destroy(f);
}
inline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
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
    ElQ* _Umove2(ElQ* f, ElQ* l, ElQ* p)
    {
        return FUN_00b24030(f, l, p, m_al);
    }
    ElQ* _Ufill(ElQ* p, unsigned n, const ElQ& v)
    {
        Unchecked_uninitialized_fill_n(p, n, v, m_al);
        return p + n;
    }
    void FUN_00b1ebc0(ElQ* f, ElQ* l);
    void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b1ecf0(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b1ecf0
void VecQ::FUN_00b1ecf0(CItQ _Where, unsigned _Count, const ElQ& _Val)
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
        ElQ* _Newvec = FUN_00b23980(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove2(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            FUN_00b1ebc0(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            FUN_00b1ebc0(m_pHeadNode, m_last);
            Dead12();
            m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
        }
        m_kRayEnd = _Newvec + _Capacity;
        m_last = _Newvec + _Count;
        m_pHeadNode = _Newvec;
    }
    else if ((unsigned)(m_last - _Where.m_ptr) < _Count)
    {
        WQ _Tmp(_Val);
        _Umove(_Where.m_ptr, m_last, _Where.m_ptr + _Count);
        try
        {
            _Ufill(m_last, _Count - (m_last - _Where.m_ptr), _Tmp);
        }
        catch (...)
        {
            FUN_00b1ebc0(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Dead6();
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        W2Q _Tmp(_Val);
        ElQ* _Oldend = m_last;
        Dead21();
        m_last = _Umove2(_Oldend - _Count, _Oldend, m_last);
        FUN_00b238e0(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead8c();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, *(const ElQ*)&_Tmp);
        Dead8b();
    }
}
}  // namespace fnv_00b1ecf0

namespace buyElement24 {
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

struct BxElem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
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
    bool FUN_00b1f590(unsigned int _Capacity);
};
}
using namespace buyElement24;

// @fnv 0x00b1f590
bool BxVector::FUN_00b1f590(unsigned int _Capacity)
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

namespace fnv_00b1f800 {
void __cdecl operator delete(void*);
int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
struct EraseSecureTag
{
};
struct EraseTraits
{
    static void assign(char& d, const char& s)
    {
        d = s;
    }
    static char* Copy(char* dst, unsigned int size, const char* src, unsigned int count)
    {
        memcpy_s(dst, size, src, count);
        return dst;
    }
};
inline char* CopyString(char* dst, unsigned int size, const char* src, unsigned int count, EraseSecureTag)
{
    return EraseTraits::Copy(dst, size, src, count);
}
inline char* CopyString(char* dst, unsigned int size, const char* src, unsigned int count)
{
    return CopyString(dst, size, src, count, EraseSecureTag());
}
struct EraseCharAllocator
{
    void deallocate(char* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct EraseElement
{
    EraseCharAllocator charAl;
    union Buffer
    {
        char small[16];
        char* ptr;
    } buffer;
    unsigned int length, capacity;
    float x, y, z, w;
    EraseElement& operator=(const EraseElement&);
    char* data()
    {
        return 16 <= capacity ? buffer.ptr : buffer.small;
    }
    void EndString(unsigned int size)
    {
        EraseTraits::assign(data()[length = size], char());
    }
    void FUN_0044a730(bool built, unsigned int size)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* p = buffer.ptr;
            if (0 < size)
                CopyString(buffer.small, 16, p, size);
            charAl.deallocate(p, capacity + 1);
        }
        capacity = 15;
        EndString(size);
    }
    ~EraseElement()
    {
        FUN_0044a730(true, 0);
    }
};
unsigned int __cdecl FUN_00ec7c56();
void __cdecl operator delete(void*);
EraseElement* __cdecl FUN_00b23830(EraseElement*, EraseElement*, EraseElement*);
struct EraseVector;
struct EraseIteratorBase
{
    void* cont;
    EraseIteratorBase() : cont(0)
    {}
    void SetContainer(const EraseVector*);
};
struct EraseConstIterator : EraseIteratorBase
{
    EraseElement* ptr;
    EraseConstIterator(EraseElement*, const EraseVector*);
    bool FUN_00b16830(const EraseConstIterator&) const;
};
struct EraseIterator : EraseConstIterator
{
    EraseIterator(EraseElement* p, const EraseVector* v) : EraseConstIterator(p, v)
    {}
};
inline void DestroyOne(EraseElement* p)
{
    p->~EraseElement();
}
struct EraseAllocator
{
    void destroy(EraseElement* p)
    {
        DestroyOne(p);
    }
};
struct EraseTag
{
};
inline EraseTag PointerCategory(EraseElement*&, EraseElement*&)
{
    EraseTag category;
    return category;
}
struct EraseInputTag
{
};
struct EraseForwardTag : EraseInputTag
{
};
struct EraseBidirTag : EraseForwardTag
{
};
struct EraseRandomTag : EraseBidirTag
{
};
struct EraseRangeTag
{
};
struct EraseUnchangedTag
{
};
inline EraseRandomTag IteratorCategory(EraseElement* const&, EraseElement* const&)
{
    EraseRandomTag category;
    return category;
}
inline EraseElement* CheckedBase(EraseElement*& it, EraseUnchangedTag)
{
    return it;
}
inline EraseElement* CheckedBase(EraseElement*& it)
{
    EraseUnchangedTag tag;
    return CheckedBase(it, tag);
}
inline EraseElement* CopyOpt(EraseElement* first, EraseElement* last, EraseElement* dest, EraseForwardTag, EraseTag,
                             EraseRangeTag)
{
    for (; first != last; ++dest, ++first)
        *dest = *first;
    return dest;
}
inline EraseElement* CopyOpt(EraseElement* first, EraseElement* last, EraseElement* dest, EraseRandomTag, EraseTag,
                             EraseRangeTag)
{
    EraseElement* result = dest + (last - first);
    CopyOpt(first, last, CheckedBase(dest), EraseForwardTag(), EraseTag(), EraseRangeTag());
    return result;
}
inline EraseElement* FUN_00b23830(EraseElement* first, EraseElement* last, EraseElement* dest)
{
    return CopyOpt(CheckedBase(first), CheckedBase(last), dest, IteratorCategory(first, dest),
                   PointerCategory(first, dest), EraseRangeTag());
}
inline void DestroyRange(EraseElement* first, EraseElement* last, EraseAllocator& al, EraseTag)
{
    for (; first != last; ++first)
        al.destroy(first);
}
inline void DestroyRange(EraseElement* first, EraseElement* last, EraseAllocator& al)
{
    DestroyRange(first, last, al, PointerCategory(first, last));
}
struct EraseVector
{
    void* m0;
    int m4;
    EraseAllocator al;
    EraseElement* mC;
    EraseElement* m10;
    EraseElement* m14;
    EraseIterator MakeIter(EraseConstIterator where) const
    {
        return EraseIterator(where.ptr, this);
    }
    void Destroy(EraseElement* first, EraseElement* last)
    {
        DestroyRange(first, last, al);
    }
    EraseIterator FUN_00b1f800(EraseConstIterator first_arg, EraseConstIterator last_arg);
};
inline void EraseIteratorBase::SetContainer(const EraseVector* v)
{
    cont = v->m0;
}
inline EraseConstIterator::EraseConstIterator(EraseElement* p, const EraseVector* v)
{
    if (!(v != 0 && v->mC <= p && p <= v->m10))
    {
        {
            FUN_00ec7c56();
        }
    }
    SetContainer(v);
    ptr = p;
}
// @fnv 0x00b1f800
EraseIterator EraseVector::FUN_00b1f800(EraseConstIterator first_arg, EraseConstIterator last_arg)
{
    EraseIterator first = MakeIter(first_arg);
    EraseIterator last = MakeIter(last_arg);
    if (first.FUN_00b16830(last))
    {
        EraseElement* ptr = FUN_00b23830(last.ptr, m10, first.ptr);
        Destroy(ptr, m10);
        m10 = ptr;
    }
    return first;
}
}  // namespace fnv_00b1f800

namespace fnv_00b1f9e0 {
void __cdecl operator delete(void* _Ptr) throw();
extern int DAT_010173f0;
inline void operator delete(void*, void*)
{}
namespace tidyb1f9 {
void FUN_00ec7c56();
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
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
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<unsigned int*, unsigned int*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
struct GvRangeCheckedTag
{
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
    {
        _Al.destroy(_First);
    }
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
template <class I> inline I GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline I GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline I GvCheckedBase(const I& _It)
{
    GvUnchangedTag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline I GvCheckedBase(I& _It)
{
    GvUnchangedTag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
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
    {
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    }
    return _Result;
}
template <class T1, class T2, class A>
inline T2 GvUninitCopy(T1 _First, T1 _Last, T2 _Dest, A&, GvScalarTag, GvRangeCheckedTag)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    T2 _Result = _Dest + _Count;
    if (_Count > 0)
    {
        FUN_00ec7c6b(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    }
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
    void _Orphan_all() const
    {}
};
struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(GvAlloc<GvAuxCont> _Al) : _Alaux(_Al)
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
    bool operator!=(const GvIterBase& _Right) const;
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
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            FUN_00ec7c56();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        if (!this->_Has_container())
            FUN_00ec7c56();
        if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
              _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            FUN_00ec7c56();
        _Myptr += _Off;
        return *this;
    }
    int operator-(const GvConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
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
template <class T> struct GvVectorVal : GvAuxBase
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase(_Al), _Alval(_Al)
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
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
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
struct GvInner
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
};
struct GvElemV
{
    GvVector<GvInner> kList;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct GvNamed
{
    BxString kName;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
};
struct GvObj
{
    int unk00;
    ~GvObj();
};
}
using namespace tidyb1f9;
struct FUN_00b1f9e0 : GvVector<GvNamed>
{
    void FUN_00b1f9e0_Tidy();
};
// @fnv 0x00b1f9e0
void FUN_00b1f9e0::FUN_00b1f9e0_Tidy()
{
    if (_Myfirst != 0)
    {
        _Destroy(_Myfirst, _Mylast);
        this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
    }
    _Myfirst = 0, _Mylast = 0, _Myend = 0;
}
}  // namespace fnv_00b1f9e0

namespace fnv_00b1fbe0 {
namespace buyb1f {
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

struct BxElem
{
    int unk00;
    int unk04;
    int unk08;
};
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
    bool FUN_00b1fbe0(unsigned int _Capacity);
};
}
using namespace buyb1f;

// @fnv 0x00b1fbe0
bool BxVector::FUN_00b1fbe0(unsigned int _Capacity)
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
}  // namespace fnv_00b1fbe0

namespace fnv_00b1fca0 {
namespace tidyb1f {
struct T1Elem
{
    int unk00;
    int unk04;
    int unk08;
};
struct T1NonscalarTag
{
};
inline T1NonscalarTag T1PtrCat(T1Elem*&, T1Elem*&)
{
    T1NonscalarTag kCat;
    return kCat;
}
struct T1Alloc
{
    void destroy(T1Elem*)
    {}
    void deallocate(T1Elem* ptr, unsigned int count)
    {
        FormHeap_Free(ptr);
    }
    static void FormHeap_Free(void* ptr);
};
inline void T1DestroyRange(T1Elem* first, T1Elem* last, T1Alloc& al, T1NonscalarTag)
{
    for (; first != last; ++first)
    {
        al.destroy(first);
    }
}
inline void T1DestroyRange(T1Elem* first, T1Elem* last, T1Alloc& al)
{
    T1DestroyRange(first, last, al, T1PtrCat(first, last));
}
struct T1Vector
{
    int unk00;
    int unk04;
    T1Alloc kAlval;
    T1Elem* pFirst;
    T1Elem* pLast;
    T1Elem* pEnd;
    void Destroy(T1Elem* first, T1Elem* last)
    {
        T1DestroyRange(first, last, kAlval);
    }
    void FUN_00b1fca0();
};
}
using namespace tidyb1f;

// @fnv 0x00b1fca0
void T1Vector::FUN_00b1fca0()
{
    if (pFirst != 0)
    {
        Destroy(pFirst, pLast);
        kAlval.deallocate(pFirst, pEnd - pFirst);
    }
    pFirst = 0;
    pLast = 0;
    pEnd = 0;
}
}  // namespace fnv_00b1fca0

namespace fnv_00b20360 {
struct ElQ
{
    int ai[14];
};
struct MoveCatQ
{
};
struct TagQ
{
};
struct PtrCatQ
{
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
    {}
    static void FormHeap_Free(void*);
};
ElQ* __cdecl FUN_00b23980(unsigned n, ElQ* p);
ElQ* __cdecl FUN_00b264a0(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b24690(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b23930(ElQ* f, ElQ* l, ElQ* d);
void __cdecl CopyObjects(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
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
inline void Dead3()
{
    int a[3];
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
inline ElQ* Uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ mc, TagQ tg)
{
    return FUN_00b264a0(f, l, d, al);
}
inline ElQ* Unchecked_uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return Uninitialized_move(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    CopyObjects(f, n, v, al, Ptr_cat(f, f), TagQ());
}
inline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    for (; f != l; ++f)
        al.destroy(f);
}
inline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
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
    ElQ* _Umove2(ElQ* f, ElQ* l, ElQ* p)
    {
        return FUN_00b24690(f, l, p, m_al);
    }
    void _Destroy(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b20360(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b20360
void VecQ::FUN_00b20360(CItQ _Where, unsigned _Count, const ElQ& _Val)
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
        Dead3();
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ElQ* _Newvec = FUN_00b23980(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            _Destroy(m_pHeadNode, m_last);
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
            _Destroy(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        ElQ _Tmp = _Val;
        ElQ* _Oldend = m_last;
        Dead13();
        m_last = _Umove2(_Oldend - _Count, _Oldend, m_last);
        FUN_00b23930(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead16();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, _Tmp);
    }
}
}  // namespace fnv_00b20360

namespace fnv_00b20ba0 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace auxb20b {
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
using namespace auxb20b;
struct FUN_00b20ba0 : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit FUN_00b20ba0(GvAlloc<char> _Al);
};
// @fnv 0x00b20ba0
FUN_00b20ba0::FUN_00b20ba0(GvAlloc<char> _Al) : _Alaux(_Al)
{
    _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
}
}  // namespace fnv_00b20ba0

namespace fnv_00b20c30 {
namespace vecdb20c {
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
        _Al.destroy(_First);
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
    void _Orphan_all() const
    {}
    VdAuxCont* _Myownedaux;
    VdAlloc<VdAuxCont> _Alaux;
    ~VdAuxBase()
    {
        _Myownedaux->~VdAuxCont();
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
using namespace vecdb20c;

namespace vecdb20c {
struct VdInner
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
};
struct VdElemV : public VdVector<VdInner>
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
};
struct VdElemW : public VdVector<VdElemV>
{
};
}
struct FUN_00b20c30 : public VdVectorImpl<VdElemW>
{
    void FUN_00b20c30_Destroy(VdElemW* _First, VdElemW* _Last);
};

// @fnv 0x00b20c30
void FUN_00b20c30::FUN_00b20c30_Destroy(VdElemW* _First, VdElemW* _Last)
{
    VdDestroyRange<VdAlloc<VdElemW> >(_First, _Last, _Alval);
}
}  // namespace fnv_00b20c30

namespace fnv_00b20ce0 {
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
ElQ* __cdecl FUN_00b25ca0(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ c, TagQ t);
ElQ* __cdecl FUN_00b239e0(ElQ* f, ElQ* l, ElQ* d);
void __cdecl FUN_00b24290(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
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
inline void Dead3()
{
    int a[3];
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
    return FUN_00b25ca0(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b24290(f, n, v, al, Ptr_cat(f, f), TagQ());
}
inline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    int aP[8];
    for (; f != l; ++f)
        al.destroy(f);
}
inline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
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
    void FUN_00b20c30(ElQ* f, ElQ* l);
    void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b20ce0(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b20ce0
void VecQ::FUN_00b20ce0(CItQ _Where, unsigned _Count, const ElQ& _Val)
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
            FUN_00b20c30(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            FUN_00b20c30(m_pHeadNode, m_last);
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
        Dead9();
        m_last = _Umove(_Oldend - _Count, _Oldend, m_last);
        FUN_00b239e0(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead11();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, *(const ElQ*)&_Tmp);
        Dead8b();
    }
}
}  // namespace fnv_00b20ce0

namespace fnv_00b21560 {
inline void FreeQ(void* p);
struct ElQ
{
    char ac[44];
    ElQ(const ElQ&);
    ElQ& operator=(const ElQ&);
    void FUN_0044a730(bool, int);
    ~ElQ()
    {
        FUN_0044a730(true, 0);
    }
    void DelQ(unsigned f)
    {
        FUN_0044a730(true, 0);
        if (f & 1)
            FreeQ(this);
    }
};
struct MoveCatQ
{
};
struct TagQ
{
};
struct PtrCatQ
{
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
        p->DelQ(0);
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b23b50(unsigned n, ElQ* p);
ElQ* __cdecl FUN_00b23f10(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b247b0(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b23b00(ElQ* f, ElQ* l, ElQ* d);
void __cdecl FUN_00b243a0(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
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
inline void Dead8()
{
    int a[8];
}
inline void Dead5()
{
    int a[5];
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
inline ElQ* Uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ mc, TagQ tg)
{
    return FUN_00b23f10(f, l, d, al);
}
inline ElQ* Unchecked_uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return Uninitialized_move(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b243a0(f, n, v, al, Ptr_cat(f, f), TagQ());
}
inline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    for (; f != l; ++f)
        al.destroy(f);
}
inline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
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
    ElQ* _Umove2(ElQ* f, ElQ* l, ElQ* p)
    {
        return FUN_00b247b0(f, l, p, m_al);
    }
    void _Destroy(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b21560(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b21560
void VecQ::FUN_00b21560(CItQ _Where, unsigned _Count, const ElQ& _Val)
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
        ElQ* _Newvec = FUN_00b23b50(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove2(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            _Destroy(m_pHeadNode, m_last);
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
            _Destroy(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        ElQ _Tmp = _Val;
        ElQ* _Oldend = m_last;
        Dead17();
        m_last = _Umove2(_Oldend - _Count, _Oldend, m_last);
        FUN_00b23b00(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead8();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, _Tmp);
        Dead5();
    }
}
}  // namespace fnv_00b21560

namespace fnv_00b21e00 {
struct ElQ
{
    int ai[3];
};
struct MoveCatQ
{
};
struct TagQ
{
};
struct PtrCatQ
{
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
    {}
    static void FormHeap_Free(void*);
};
ElQ* __cdecl FUN_00b23980(unsigned n, ElQ* p);
ElQ* __cdecl FUN_00b264a0(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b24690(ElQ* f, ElQ* l, ElQ* d, AlQ& al);
ElQ* __cdecl FUN_00b23930(ElQ* f, ElQ* l, ElQ* d);
void __cdecl CopyObjects(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
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
inline void Dead3()
{
    int a[3];
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
inline ElQ* Uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ mc, TagQ tg)
{
    return FUN_00b264a0(f, l, d, al);
}
inline ElQ* Unchecked_uninitialized_move(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return Uninitialized_move(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    CopyObjects(f, n, v, al, Ptr_cat(f, f), TagQ());
}
inline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    for (; f != l; ++f)
        al.destroy(f);
}
inline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
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
    ElQ* _Umove2(ElQ* f, ElQ* l, ElQ* p)
    {
        return FUN_00b24690(f, l, p, m_al);
    }
    void _Destroy(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b21e00(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b21e00
void VecQ::FUN_00b21e00(CItQ _Where, unsigned _Count, const ElQ& _Val)
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
        Dead3();
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        ElQ* _Newvec = FUN_00b23980(_Capacity, 0);
        ElQ* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(m_pHeadNode, _Where.m_ptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where.m_ptr, m_last, _Ptr);
        }
        catch (...)
        {
            _Destroy(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            _Destroy(m_pHeadNode, m_last);
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
            _Destroy(_Where.m_ptr + _Count, m_last + _Count);
            throw;
        }
        m_last += _Count;
        Unchecked_fill(_Where.m_ptr, m_last - _Count, _Tmp);
    }
    else
    {
        ElQ _Tmp = _Val;
        ElQ* _Oldend = m_last;
        Dead13();
        m_last = _Umove2(_Oldend - _Count, _Oldend, m_last);
        FUN_00b23930(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead16();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, _Tmp);
    }
}
}  // namespace fnv_00b21e00

namespace fnv_00b22650 {
namespace vecdb226 {
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
using namespace vecdb226;

namespace vecdb226 {
struct VdElemV : public VdVector<unsigned short>
{
};
}
struct FUN_00b22650 : public VdVectorImpl<VdElemV>
{
    void FUN_00b22650_Destroy(VdElemV* _First, VdElemV* _Last);
};

// @fnv 0x00b22650
void FUN_00b22650::FUN_00b22650_Destroy(VdElemV* _First, VdElemV* _Last)
{
    VdDestroyRange<VdAlloc<VdElemV> >(_First, _Last, _Alval);
}
}  // namespace fnv_00b22650

namespace fnv_00b22700 {
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
ElQ* __cdecl FUN_00b25e20(ElQ* f, ElQ* l, ElQ* d, AlQ& al, MoveCatQ c, TagQ t);
ElQ* __cdecl FUN_00b23c10(ElQ* f, ElQ* l, ElQ* d);
void __cdecl FUN_00b24580(ElQ* f, unsigned n, const ElQ& v, AlQ& al, PtrCatQ c, TagQ t);
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
    return FUN_00b25e20(Checked_base2(f), Checked_base(l), d, al, Move_cat(d), TagQ());
}
inline void Unchecked_uninitialized_fill_n(ElQ* f, unsigned n, const ElQ& v, AlQ& al)
{
    FUN_00b24580(f, n, v, al, Ptr_cat(f, f), TagQ());
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
    void FUN_00b22650(ElQ* f, ElQ* l);
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b22700(CItQ _Where, unsigned _Count, const ElQ& _Val);
};
// @fnv 0x00b22700
void VecQ::FUN_00b22700(CItQ _Where, unsigned _Count, const ElQ& _Val)
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
            FUN_00b22650(_Newvec, _Ptr);
            m_al.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (m_pHeadNode != 0)
        {
            FUN_00b22650(m_pHeadNode, m_last);
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
        FUN_00b23c10(_Where.m_ptr, _Oldend - _Count, _Oldend);
        Dead11();
        Unchecked_fill(_Where.m_ptr, _Where.m_ptr + _Count, *(const ElQ*)&_Tmp);
        Dead7();
    }
}
}  // namespace fnv_00b22700

void __cdecl InvalidParameterNoInfoX23460();
struct ContainerBaseAuxX23460
{
};
class AuxContX23460
{
  public:
    const ContainerBaseAuxX23460* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX23460* _Mycontainer;
};
class IteratorBaseAuxX23460
{
  public:
    const ContainerBaseAuxX23460* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX23460* _Myaux;
};
struct ElemX23460
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
};
struct VectorX23460 : public ContainerBaseAuxX23460
{
    AuxContX23460* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX23460* _Myfirst;
    ElemX23460* _Mylast;
    ElemX23460* _Myend;
};
class FUN_00b23460_It : public IteratorBaseAuxX23460
{
  public:
    FUN_00b23460_It& FUN_00b23460(int _Off);
    ElemX23460* _Myptr;
};

// @fnv 0x00b23460
FUN_00b23460_It& FUN_00b23460_It::FUN_00b23460(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoX23460();
    if (!(_Myptr + _Off <= ((VectorX23460*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorX23460*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoX23460();
    _Myptr += _Off;
    return *this;
}

void __cdecl InvalidParameterNoInfoX23520();
struct ContainerBaseAuxX23520
{
};
class AuxContX23520
{
  public:
    const ContainerBaseAuxX23520* _Getcont() const
    {
        return _Mycontainer;
    }
    const ContainerBaseAuxX23520* _Mycontainer;
};
class IteratorBaseAuxX23520
{
  public:
    const ContainerBaseAuxX23520* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    AuxContX23520* _Myaux;
};
struct ElemX23520
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
};
struct VectorX23520 : public ContainerBaseAuxX23520
{
    AuxContX23520* _Myownedaux;
    int _Alaux;
    int _Alval;
    ElemX23520* _Myfirst;
    ElemX23520* _Mylast;
    ElemX23520* _Myend;
};
class FUN_00b23520_It : public IteratorBaseAuxX23520
{
  public:
    FUN_00b23520_It& FUN_00b23520(int _Off);
    ElemX23520* _Myptr;
};

// @fnv 0x00b23520
FUN_00b23520_It& FUN_00b23520_It::FUN_00b23520(int _Off)
{
    if (!(this->_Has_container()))
        InvalidParameterNoInfoX23520();
    if (!(_Myptr + _Off <= ((VectorX23520*)this->_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VectorX23520*)this->_Getmycont())->_Myfirst))
        InvalidParameterNoInfoX23520();
    _Myptr += _Off;
    return *this;
}

namespace fnv_00b23760 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace cpyb237 {
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
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};
struct GvElemLess
{
    bool operator()(const GvElem& _Left, const GvElem& _Right) const
    {
        return _Left.f2c > _Right.f2c;
    }
};
}
using namespace cpyb237;
// @fnv 0x00b23760
GvElem* FUN_00b23760(GvElem* _First, GvElem* _Last, GvElem* _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
}  // namespace fnv_00b23760

struct sbuf108
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    unsigned char c104;
    unsigned char c105;
    unsigned char c106;
    unsigned char c107;
};

inline __int64 z64(void)
{
    return 0;
}

void __cdecl FUN_00b240b0(int a, int b, int c, char d, char e, char f);

// @fnv 0x00b238e0
void __cdecl FUN_00b238e0(int a, int b, int c)
{
    sbuf108 s;
    s.c107 = (unsigned int)z64();
    s.c106 = s.c104;
    s.f0fc = b;
    s.f0f4 = a;
    FUN_00b240b0(s.f0f4, s.f0fc, c, s.c105, s.c106, s.c107);
}

namespace fnv_00b23930 {
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct EUMB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00b23930
EUMB* __cdecl FUN_00b23930(EUMB* _First, EUMB* _Last, EUMB* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b23930

namespace fnv_00b239e0 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace cbkb239 {
template <class T> inline void swap(T& _Left, T& _Right)
{
    if (&_Left != &_Right)
    {
        T _Tmp = _Left;
        _Left = _Right;
        _Right = _Tmp;
    }
}
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
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
    void _Swap_aux(GvContainer& _Right)
    {
        swap(_Myownedaux, _Right._Myownedaux);
        swap(*_Myownedaux, *_Right._Myownedaux);
    }
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
    void swap(GvVector& _Right)
    {
        if (this == &_Right)
            ;
        else if (this->_Alval == _Right._Alval)
        {
            this->_Swap_aux(_Right);
            cbkb239::swap(_Myfirst, _Right._Myfirst);
            cbkb239::swap(_Mylast, _Right._Mylast);
            cbkb239::swap(_Myend, _Right._Myend);
        }
        else
        {
            this->_Swap_aux(_Right);
            GvVector _Ts = *this;
            *this = _Right;
            _Right = _Ts;
        }
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};
struct GvElemLess
{
    bool operator()(const GvElem& _Left, const GvElem& _Right) const
    {
        return _Left.f2c > _Right.f2c;
    }
};
template <class T, class O> inline bool operator==(const GvAlloc<T>&, const GvAlloc<O>&) throw()
{
    return true;
}
template <class T> inline void swap(GvVector<T>& _Left, GvVector<T>& _Right)
{
    _Left.swap(_Right);
}
template <class T> inline void GvSwapAdl(T& _Left, T& _Right)
{
    swap(_Left, _Right);
}
struct GvUndefinedMoveTag
{
};
struct GvSwapMoveTag
{
};
template <class T> struct GvMoveCatHelper
{
    typedef GvUndefinedMoveTag _Move_cat;
};
template <class T> struct GvMoveCatHelper<GvVector<T> >
{
    typedef GvSwapMoveTag _Move_cat;
};
template <class T> inline typename GvMoveCatHelper<T>::_Move_cat GvMoveCat(T* const&)
{
    typename GvMoveCatHelper<T>::_Move_cat _Cat;
    return _Cat;
}
template <class B1, class B2, class C>
inline B2 GvMoveBackwardOpt(B1 _First, B1 _Last, B2 _Dest, C, GvSwapMoveTag, GvRangeCheckedTag)
{
    while (_First != _Last)
        GvSwapAdl(*--_Dest, *--_Last);
    return _Dest;
}
template <class B1, class B2>
inline B2 GvMoveBackwardOpt(B1 _First, B1 _Last, B2 _Dest, GvRandomTag, GvSwapMoveTag _Move_cat, GvRangeCheckedTag)
{
    B2 _Result = _Dest - (_Last - _First);
    GvMoveBackwardOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), _Move_cat, GvRangeCheckedTag());
    return _Result;
}
template <class B1, class B2, class C>
inline B2 GvCopyBackwardOpt(B1 _First, B1 _Last, B2 _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
template <class I, class O>
inline O GvCopyBackwardOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest - (_Last - _First);
    GvCopyBackwardOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
}
using namespace cbkb239;
// @fnv 0x00b239e0
GvVector<GvElem>* FUN_00b239e0(GvVector<GvElem>* _First, GvVector<GvElem>* _Last, GvVector<GvElem>* _Dest)
{
    return GvMoveBackwardOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                             GvMoveCat(_Dest), GvRangeCheckedTag());
}
}  // namespace fnv_00b239e0

struct FrondPred
{
    bool operator()(const FUN_00b1ff50& a, const FUN_00b1ff50& b) const
    {
        return a.f2c < b.f2c;
    }
};
typedef FUN_00b1ff50* FrondIt;
struct S00b23cd0_Pair
{
    FrondIt first;
    FrondIt second;
    S00b23cd0_Pair()
    {}
    S00b23cd0_Pair(const FrondIt& _Val1, const FrondIt& _Val2) : first(_Val1), second(_Val2)
    {}
};
struct S00b23cd0_Unchanged_tag
{
};
inline FrondIt S00b23cd0_Checked_base(FrondIt& _It, S00b23cd0_Unchanged_tag)
{
    return _It;
}
inline FrondIt S00b23cd0_Checked_base(FrondIt& _It)
{
    S00b23cd0_Unchanged_tag _Base_tag;
    return S00b23cd0_Checked_base(_It, _Base_tag);
}
inline int* S00b23cd0_Dist_type(const FUN_00b1ff50*)
{
    return 0;
}
inline FUN_00b1ff50* S00b23cd0_Val_type(const FUN_00b1ff50*)
{
    return 0;
}

inline void S00b23cd0_Push_heap(FrondIt _First, int _Hole, int _Top, FUN_00b1ff50 _Val, FrondPred _Pred)
{
    for (int _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}
inline void S00b23cd0_Adjust_heap(FrondIt _First, int _Hole, int _Bottom, FUN_00b1ff50 _Val, FrondPred _Pred)
{
    int _Top = _Hole;
    int _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
            --_Idx;
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    S00b23cd0_Push_heap(_First, _Hole, _Top, _Val, _Pred);
}
inline void __cdecl FUN_00b26260(FrondIt _First, FrondIt _Last, FrondPred _Pred, int*, FUN_00b1ff50*)
{
    int _Bottom = _Last - _First;
    for (int _Hole = _Bottom / 2; 0 < _Hole;)
    {
        --_Hole;
        S00b23cd0_Adjust_heap(_First, _Hole, _Bottom, FUN_00b1ff50(*(_First + _Hole)), _Pred);
    }
}
FrondIt S00b23cd0_unchecked_copy_backward(FrondIt, FrondIt, FrondIt);
inline void __cdecl FUN_00b262d0(FrondIt _First, FrondIt _Last, FrondPred _Pred, FUN_00b1ff50*)
{
    if (_First != _Last)
        for (FrondIt _Next = _First; ++_Next != _Last;)
        {
            FrondIt _Next1 = _Next;
            FUN_00b1ff50 _Val = *_Next;
            if (_Pred(_Val, *_First))
            {
                S00b23cd0_unchecked_copy_backward(_First, _Next, ++_Next1);
                *_First = _Val;
            }
            else
            {
                for (FrondIt _First1 = _Next1; _Pred(_Val, *--_First1); _Next1 = _First1)
                    *_Next1 = *_First1;
                *_Next1 = _Val;
            }
        }
}
void S00b23cd0_Median(FrondIt, FrondIt, FrondIt, FrondPred);
inline void S00b23cd0_swap(FUN_00b1ff50& _Left, FUN_00b1ff50& _Right)
{
    if (&_Left != &_Right)
    {
        FUN_00b1ff50 _Tmp = _Left;
        _Left = _Right;
        _Right = _Tmp;
    }
}
inline void S00b23cd0_iter_swap(FrondIt _Left, FrondIt _Right)
{
    S00b23cd0_swap(*_Left, *_Right);
}
inline S00b23cd0_Pair __cdecl FUN_00b25680(FrondIt _First, FrondIt _Last, FrondPred _Pred)
{  // partition [_First, _Last), using _Pred
    FrondIt _Mid = _First + (_Last - _First) / 2;
    S00b23cd0_Median(_First, _Mid, _Last - 1, _Pred);
    FrondIt _Pfirst = _Mid;
    FrondIt _Plast = _Pfirst + 1;

    while (_First < _Pfirst && !_Pred(*(_Pfirst - 1), *_Pfirst) && !_Pred(*_Pfirst, *(_Pfirst - 1)))
        --_Pfirst;
    while (_Plast < _Last && !_Pred(*_Plast, *_Pfirst) && !_Pred(*_Pfirst, *_Plast))
        ++_Plast;

    FrondIt _Gfirst = _Plast;
    FrondIt _Glast = _Pfirst;

    for (;;)
    {  // partition
        for (; _Gfirst < _Last; ++_Gfirst)
            if (_Pred(*_Pfirst, *_Gfirst))
                ;
            else if (_Pred(*_Gfirst, *_Pfirst))
                break;
            else
                S00b23cd0_iter_swap(_Plast++, _Gfirst);
        for (; _First < _Glast; --_Glast)
            if (_Pred(*(_Glast - 1), *_Pfirst))
                ;
            else if (_Pred(*_Pfirst, *(_Glast - 1)))
                break;
            else
                S00b23cd0_iter_swap(--_Pfirst, _Glast - 1);
        if (_Glast == _First && _Gfirst == _Last)
            return (S00b23cd0_Pair(_Pfirst, _Plast));

        if (_Glast == _First)
        {  // no room at bottom, rotate pivot upward
            if (_Plast != _Gfirst)
                S00b23cd0_iter_swap(_Pfirst, _Plast);
            ++_Plast;
            S00b23cd0_iter_swap(_Pfirst++, _Gfirst++);
        }
        else if (_Gfirst == _Last)
        {  // no room at top, rotate pivot downward
            if (--_Glast != --_Pfirst)
                S00b23cd0_iter_swap(_Glast, _Pfirst);
            S00b23cd0_iter_swap(_Pfirst, --_Plast);
        }
        else
            S00b23cd0_iter_swap(_Gfirst++, --_Glast);
    }
}

void S00b23cd0_Med3(FrondIt, FrondIt, FrondIt, FrondPred);
void S00b23cd0_Median_decl_dummy();
inline void S00b23cd0_Median(FrondIt _First, FrondIt _Mid, FrondIt _Last, FrondPred _Pred)
{
    if (40 < _Last - _First)
    {
        unsigned int _Step = (_Last - _First + 1) / 8;
        S00b23cd0_Med3(_First, _First + _Step, _First + 2 * _Step, _Pred);
        S00b23cd0_Med3(_Mid - _Step, _Mid, _Mid + _Step, _Pred);
        S00b23cd0_Med3(_Last - 2 * _Step, _Last - _Step, _Last, _Pred);
        S00b23cd0_Med3(_First + _Step, _Mid, _Last - _Step, _Pred);
    }
    else
        S00b23cd0_Med3(_First, _Mid, _Last, _Pred);
}

inline void S00b23cd0_Med3(FrondIt _First, FrondIt _Mid, FrondIt _Last, FrondPred _Pred)
{
    if (_Pred(*_Mid, *_First))
        S00b23cd0_iter_swap(_Mid, _First);
    if (_Pred(*_Last, *_Mid))
        S00b23cd0_iter_swap(_Last, _Mid);
    if (_Pred(*_Mid, *_First))
        S00b23cd0_iter_swap(_Mid, _First);
}

inline void S00b23cd0_Pop_heap(FrondIt _First, FrondIt _Last, FrondIt _Dest, FUN_00b1ff50 _Val, FrondPred _Pred, int*)
{
    *_Dest = *_First;
    S00b23cd0_Adjust_heap(_First, int(0), int(_Last - _First), _Val, _Pred);
}
inline void S00b23cd0_Pop_heap_0(FrondIt _First, FrondIt _Last, FrondPred _Pred, FUN_00b1ff50*)
{
    S00b23cd0_Pop_heap(_First, _Last - 1, _Last - 1, FUN_00b1ff50(*(_Last - 1)), _Pred, S00b23cd0_Dist_type(_First));
}
inline void __cdecl FUN_00b26ca0(FrondIt _First, FrondIt _Last, FrondPred _Pred)
{
    if (1 < _Last - _First)
        S00b23cd0_Pop_heap_0(S00b23cd0_Checked_base(_First), S00b23cd0_Checked_base(_Last), _Pred,
                             S00b23cd0_Val_type(_First));
}
inline void S00b23cd0_make_heap(FrondIt _First, FrondIt _Last, FrondPred _Pred)
{
    if (1 < _Last - _First)
        FUN_00b26260(S00b23cd0_Checked_base(_First), S00b23cd0_Checked_base(_Last), _Pred, S00b23cd0_Dist_type(_First),
                     S00b23cd0_Val_type(_First));
}

inline void S00b23cd0_Sort_heap(FrondIt _First, FrondIt _Last, FrondPred _Pred)
{
    for (; 1 < _Last - _First; --_Last)
        FUN_00b26ca0(_First, _Last, _Pred);
}

inline void S00b23cd0_sort_heap(FrondIt _First, FrondIt _Last, FrondPred _Pred)
{
    S00b23cd0_Sort_heap(S00b23cd0_Checked_base(_First), S00b23cd0_Checked_base(_Last), _Pred);
}

inline void S00b23cd0_Insertion_sort(FrondIt _First, FrondIt _Last, FrondPred _Pred)
{
    FUN_00b262d0(_First, _Last, _Pred, S00b23cd0_Val_type(_First));
}

// @fnv 0x00b23cd0
void __cdecl FUN_00b23cd0(FrondIt _First, FrondIt _Last, int _Ideal, FrondPred _Pred)
{
    int _Count;
    for (; 32 < (_Count = _Last - _First) && 0 < _Ideal;)
    {
        S00b23cd0_Pair _Mid = FUN_00b25680(_First, _Last, _Pred);
        _Ideal /= 2, _Ideal += _Ideal / 2;
        if (_Mid.first - _First < _Last - _Mid.second)
        {
            FUN_00b23cd0(_First, _Mid.first, _Ideal, _Pred);
            _First = _Mid.second;
        }
        else
        {
            FUN_00b23cd0(_Mid.second, _Last, _Ideal, _Pred);
            _Last = _Mid.first;
        }
    }
    if (32 < _Count)
    {
        S00b23cd0_make_heap(_First, _Last, _Pred);
        S00b23cd0_sort_heap(_First, _Last, _Pred);
    }
    else if (1 < _Count)
        S00b23cd0_Insertion_sort(_First, _Last, _Pred);
}

struct S00b23e80_G
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
};
struct S00b23e80_T1
{
};
struct S00b23e80_T2
{
};
inline void S00b23e80_Copy(S00b23e80_G* first, S00b23e80_G* last, S00b23e80_G* dest, S00b23e80_T1, S00b23e80_T2)
{
    S00b23e80_G* d = dest;
    S00b23e80_G* s = first;
    for (; s != last; ++d, ++s)
        *d = *s;
}
// @fnv 0x00b23e80
S00b23e80_G* FUN_00b23e80(S00b23e80_G* first, S00b23e80_G* last, S00b23e80_G* dest)
{
    S00b23e80_G* result = dest + (last - first);
    S00b23e80_Copy(first, last, dest, S00b23e80_T1(), S00b23e80_T2());
    return result;
}

namespace fnv_00b23f10 {
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
struct Elem3f10
{
    int unk00;
    int unk04;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);

// @fnv 0x00b23f10
Elem3f10* __cdecl FUN_00b23f10(Elem3f10* _First, Elem3f10* _Last, Elem3f10* _Dest, allocatorS<Elem3f10>& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b23f10

namespace fnv_00b24030 {
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
// @fnv 0x00b24030
ElemMOVE* __cdecl FUN_00b24030(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b24030

namespace fnv_00b24690 {
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
// @fnv 0x00b24690
ElemMOVE* __cdecl FUN_00b24690(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b24690

namespace fnv_00b247b0 {
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
// @fnv 0x00b247b0
ElemMOVE* __cdecl FUN_00b247b0(ElemMOVE* _First, ElemMOVE* _Last, ElemMOVE* _Dest, allocatorS<ElemMOVE>& _Al)
{
    return (_Uninit_moveS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Move_catS(_Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b247b0

namespace fnv_00b24960 {
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
struct _Different_checked_iterator_base_type_tagS
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
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Different_checked_iterator_base_type_tagS)
{
    return _It._Checked_iterator_base();
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
    typedef const _Ty* _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return _Myptr;
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
template <class _Ty> struct _Checked_iterator_base_helperS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Different_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef const _Ty* _Checked_iterator_base_type;
};
template <class _Ty, class _T2> struct _Ptr_cat_helperS<_Vector_const_iteratorS<_Ty>, _T2>
{
    typedef typename _Ptr_cat_helperS<_Ty*, _T2>::_Ptr_cat _Ptr_cat;
};
template <class _Ty> struct _Iter_valueS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Vector_const_iteratorS<_Ty> >
{
    typedef random_access_iterator_tagS iterator_category;
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
// @fnv 0x00b24960
int* __cdecl FUN_00b24960(_Vector_const_iteratorS<int> _First, _Vector_const_iteratorS<int> _Last, int* _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b24960

namespace fnv_00b24ae0 {
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
struct VBQ
{
    void* p;
    ~VBQ();
};
inline void FreeQ(void* p);
struct ElQ
{
    int m[14];
};
struct AlQ
{
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    __forceinline void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b264f0(ElQ* f, ElQ* l, ElQ* d, RandQ, PtrCatQ, TagQ);
ElQ* __cdecl FUN_00b260c0(ElQ* f, ElQ* l, ElQ* d);
ElQ* __cdecl FUN_00b26db0(ElQ* f, ElQ* l, ElQ* d, AlQ& al, PtrCatQ, TagQ);
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead6()
{
    int a[6];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead12b()
{
    int a[12];
}
inline void Dead6c()
{
    int a[6];
}
inline void Dead2()
{
    int a[8];
}
inline void DC1()
{
    char a;
    char b;
}
inline void DC2()
{
    short a;
}
inline void DC3()
{
    char a[2];
}
inline void Dead6b()
{
    int a[6];
}
inline void Dead26()
{
    int a[26];
}
inline ElQ* Checked_base4(ElQ* const& it)
{
    return it;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_copy(ElQ* f, ElQ* l, ElQ* d)
{
    return FUN_00b264f0(Checked_base2(f), Checked_base2(l), d, RandQ(), Ptr_cat(f, d), TagQ());
}
inline ElQ* Unchecked_uninitialized_copy(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b26db0(Checked_base2(f), Checked_base4(l), d, al, Ptr_cat(f, d), TagQ());
}
__forceinline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    for (; f != l; ++f)
        al.destroy(f);
}
__forceinline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
{
    Destroy_range2(f, l, al, Ptr_cat(f, l));
}
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
    ElQ* _Ucopy(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_copy(f, l, p, m_al);
    }
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b25490();
    bool FUN_00b1eb00(unsigned n);
    VecQ& FUN_00b24ae0(const VecQ& _Right);
};
// @fnv 0x00b24ae0
VecQ& VecQ::FUN_00b24ae0(const VecQ& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
        {
            Dead12();
            FUN_00b25490();
        }
        else if (_Right.size() <= size())
        {
            ElQ* _Ptr = Unchecked_copy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            _DestroyI(_Ptr, m_last);
            m_last = m_pHeadNode + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            ElQ* _Ptr = _Right.m_pHeadNode + size();
            FUN_00b260c0(_Right.m_pHeadNode, _Ptr, m_pHeadNode);
            Dead2();
            DC1();
            m_last = _Ucopy(_Ptr, _Right.m_last, m_last);
        }
        else
        {
            if (m_pHeadNode != 0)
            {
                _DestroyI(m_pHeadNode, m_last);
                m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
            }
            if (FUN_00b1eb00(_Right.size()))
            {
                Dead26();
                m_last = _Ucopy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            }
        }
    }
    return *this;
}
}  // namespace fnv_00b24ae0

namespace fnv_00b24f40 {
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
    int pad[8];
    ElQ(const ElQ&);
    ElQ& operator=(const ElQ&);
    ~ElQ()
    {
        Tidy();
    }
    void Tidy();
    __forceinline void DelQ(unsigned f)
    {
        this->~ElQ();
        if (f & 1)
            FreeQ(this);
    }
};
struct AlQ
{
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    __forceinline void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b253f0(ElQ* f, ElQ* l, ElQ* d, RandQ, PtrCatQ, TagQ);
ElQ* __cdecl FUN_00b23760(ElQ* f, ElQ* l, ElQ* d);
ElQ* __cdecl FUN_00b25fa0(ElQ* f, ElQ* l, ElQ* d, AlQ& al, PtrCatQ, TagQ);
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead6()
{
    int a[6];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead12b()
{
    int a[12];
}
inline void Dead6c()
{
    int a[6];
}
inline void Dead2()
{
    int a[8];
}
inline void Dead1()
{
    int a[1];
}
inline void DC1()
{
    char a;
    char b;
}
inline void DC2()
{
    short a;
}
inline void DC3()
{
    char a[2];
}
inline void Dead6b()
{
    int a[6];
}
inline void Dead26()
{
    int a[26];
}
inline ElQ* Checked_base4(ElQ* const& it)
{
    return it;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_copy(ElQ* f, ElQ* l, ElQ* d)
{
    return FUN_00b253f0(Checked_base2(f), Checked_base2(l), d, RandQ(), Ptr_cat(f, d), TagQ());
}
inline ElQ* Unchecked_uninitialized_copy(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b25fa0(Checked_base2(f), Checked_base4(l), d, al, Ptr_cat(f, d), TagQ());
}
__forceinline void Destroy_range2(ElQ* f, ElQ* l, AlQ& al, PtrCatQ)
{
    int aP[7];
    for (; f != l; ++f)
        al.destroy(f);
}
__forceinline void Destroy_range(ElQ* f, ElQ* l, AlQ& al)
{
    Destroy_range2(f, l, al, Ptr_cat(f, l));
}
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
    ElQ* _Ucopy(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_copy(f, l, p, m_al);
    }
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b1de20();
    void FUN_00b1ebc0(ElQ* f, ElQ* l);
    bool FUN_00b1eb00(unsigned n);
    VecQ& FUN_00b24f40(const VecQ& _Right);
};
// @fnv 0x00b24f40
VecQ& VecQ::FUN_00b24f40(const VecQ& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
        {
            Dead12();
            FUN_00b1de20();
        }
        else if (_Right.size() <= size())
        {
            ElQ* _Ptr = Unchecked_copy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            FUN_00b1ebc0(_Ptr, m_last);
            m_last = m_pHeadNode + _Right.size();
            Dead6c();
        }
        else if (_Right.size() <= capacity())
        {
            ElQ* _Ptr = _Right.m_pHeadNode + size();
            FUN_00b23760(_Right.m_pHeadNode, _Ptr, m_pHeadNode);
            Dead2();
            DC1();
            m_last = _Ucopy(_Ptr, _Right.m_last, m_last);
        }
        else
        {
            if (m_pHeadNode != 0)
            {
                _DestroyI(m_pHeadNode, m_last);
                m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
            }
            if (FUN_00b1eb00(_Right.size()))
            {
                Dead26();
                m_last = _Ucopy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            }
        }
    }
    return *this;
}
}  // namespace fnv_00b24f40

struct S00b253f0_T1
{
};
struct S00b253f0_T2
{
};
inline CopyableStateBlock* S00b253f0_Copy(CopyableStateBlock* first, CopyableStateBlock* const& last,
                                          CopyableStateBlock* dest, S00b253f0_T1, S00b253f0_T2)
{
    double u00;
    double u01;
    double u02;
    double u03;
    double u04;
    double u05;
    double u06;
    double u07;
    double u08;
    double u09;
    double u10;
    double u11;
    double u12;
    double u13;
    double u14;
    double u15;
    double u16;
    double u17;
    double u18;
    double u19;
    double u20;
    double u21;
    double u22;
    double u23;
    double u24;
    double u25;
    double u26;
    double u27;
    double u28;
    double u29;
    double u30;
    double u31;
    double u32;
    double u33;
    double u34;
    double u35;
    double u36;
    int v0;
    int v1;
    for (; first != last; ++dest, ++first)
        dest->CopyFrom(*first);
    return dest;
}
// @fnv 0x00b253f0
CopyableStateBlock* __cdecl FUN_00b253f0(CopyableStateBlock* first, CopyableStateBlock* last, CopyableStateBlock* dest)
{
    CopyableStateBlock* result = dest + (last - first);
    S00b253f0_Copy(first, last, dest, S00b253f0_T1(), S00b253f0_T2());
    return result;
}

namespace fnv_00b25490 {
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
struct Elem5490
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
};
class FUN_00b25490_Vector : public vectorS<Elem5490>
{
  public:
    void FUN_00b25490();
};

// @fnv 0x00b25490
void FUN_00b25490_Vector::FUN_00b25490()
{
    erase(begin(), end());
}
}  // namespace fnv_00b25490

namespace fnv_00b25580 {
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
struct Elem5580
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
};
class FUN_00b25580_Vector : public vectorS<Elem5580>
{
  public:
    iterator FUN_00b25580(const_iterator _First_arg, const_iterator _Last_arg);
};

// @fnv 0x00b25580
FUN_00b25580_Vector::iterator FUN_00b25580_Vector::FUN_00b25580(const_iterator _First_arg, const_iterator _Last_arg)
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
}  // namespace fnv_00b25580

namespace fnv_00b260c0 {
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
template <class _InIt, class _OutIt, class _InOutItCat, class _MoveCatTy>
inline _OutIt _Move_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat _First_dest_cat, _MoveCatTy,
                         _Range_checked_iterator_tagS)
{
    return _Copy_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS());
}
struct E60C0
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
};
// @fnv 0x00b260c0
E60C0* __cdecl FUN_00b260c0(E60C0* _First, E60C0* _Last, E60C0* _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b260c0

namespace fnv_00b264a0 {
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
struct Elem64a0
{
    int unk00;
    int unk04;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);

// @fnv 0x00b264a0
Elem64a0* __cdecl FUN_00b264a0(Elem64a0* _First, Elem64a0* _Last, Elem64a0* _Dest, allocatorS<Elem64a0>& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b264a0

namespace fnv_00b26ab0 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace swapb26a {
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
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};
struct GvElemLess
{
    bool operator()(const GvElem& _Left, const GvElem& _Right) const
    {
        return _Left.f2c > _Right.f2c;
    }
};
}
using namespace swapb26a;
// @fnv 0x00b26ab0
void FUN_00b26ab0(GvElem& _Left, GvElem& _Right)
{
    if (&_Left != &_Right)
    {
        GvElem _Tmp = _Left;
        _Left = _Right;
        _Right = _Tmp;
    }
}
}  // namespace fnv_00b26ab0

struct SFrondGuidePoint
{
    float x;
    float y;
    float z;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
};

struct SFrondGuideAuxAlloc
{
    void deallocate(void* p, unsigned int)
    {
        operator delete(p);
    }
};

inline void DestroyPoint(SFrondGuidePoint* p)
{
    p->~SFrondGuidePoint();
}

struct SFrondGuidePointAlloc
{
    void deallocate(SFrondGuidePoint* p, unsigned int)
    {
        operator delete(p);
    }
    void destroy(SFrondGuidePoint* p)
    {
        DestroyPoint(p);
    }
};

struct SFrondGuideNonscalarTag
{
};

template <class T1, class T2> inline SFrondGuideNonscalarTag PtrCat(T1&, T2&)
{
    SFrondGuideNonscalarTag cat;
    return cat;
}

inline void DestroyRange(SFrondGuidePoint* f, SFrondGuidePoint* l, SFrondGuidePointAlloc& al, SFrondGuideNonscalarTag)
{
    for (; f != l; ++f)
        al.destroy(f);
}

inline void DestroyRange(SFrondGuidePoint* f, SFrondGuidePoint* l, SFrondGuidePointAlloc& al)
{
    DestroyRange(f, l, al, PtrCat(f, l));
}

struct SFrondGuidePointsBase
{
    void* ownedAux;
    SFrondGuideAuxAlloc auxAlloc;

    ~SFrondGuidePointsBase()
    {
        auxAlloc.deallocate(ownedAux, 1);
    }
};

struct SFrondGuidePoints : SFrondGuidePointsBase
{
    SFrondGuidePointAlloc alloc;
    SFrondGuidePoint* first;
    SFrondGuidePoint* last;
    SFrondGuidePoint* end;

    ~SFrondGuidePoints()
    {
        FUN_00b1e970();
    }
    void Destroy(SFrondGuidePoint* f, SFrondGuidePoint* l)
    {
        DestroyRange(f, l, alloc);
    }
    void FUN_00b1e970()
    {
        SFrondGuidePoints* self = this;
        if (self->first != 0)
        {
            self->Destroy(self->first, self->last);
            self->alloc.deallocate(self->first, self->end - self->first);
        }
        self->first = 0;
        self->last = 0;
        self->end = 0;
    }
};

struct SFrondGuideEntry
{
    SFrondGuidePoints points;
    float f18;
    float f1c;
    unsigned char c20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;

    SFrondGuideEntry(const SFrondGuideEntry& that);
    SFrondGuideEntry& operator=(const SFrondGuideEntry& that);
};

struct SFrondGuideGreater
{
    bool operator()(const SFrondGuideEntry& a, const SFrondGuideEntry& b) const
    {
        return a.f2c > b.f2c;
    }
};

void __cdecl FUN_00b26e80(SFrondGuideEntry* first, int hole, int top, SFrondGuideEntry val, SFrondGuideGreater pred);

// @fnv 0x00b26b50
void __cdecl FUN_00b26b50(SFrondGuideEntry* first, int hole, int bottom, SFrondGuideEntry val, SFrondGuideGreater pred)
{
    int top2 = hole;
    int idx = 2 * hole + 2;
    for (; idx < bottom; idx = 2 * idx + 2)
    {
        if (pred(first[idx], first[idx - 1]))
            --idx;
        first[hole] = first[idx], hole = idx;
    }
    if (idx == bottom)
    {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    FUN_00b26e80(first, hole, top2, val, pred);
}

namespace fnv_00b26ce0 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace cbkb26c {
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
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};
struct GvElemLess
{
    bool operator()(const GvElem& _Left, const GvElem& _Right) const
    {
        return _Left.f2c > _Right.f2c;
    }
};
template <class B1, class B2, class C>
inline B2 GvCopyBackwardOpt(B1 _First, B1 _Last, B2 _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return _Dest;
}
template <class I, class O>
inline O GvCopyBackwardOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest - (_Last - _First);
    GvCopyBackwardOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
}
using namespace cbkb26c;
// @fnv 0x00b26ce0
GvElem* FUN_00b26ce0(GvElem* _First, GvElem* _Last, GvElem* _Dest)
{
    return GvCopyBackwardOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                             GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
}  // namespace fnv_00b26ce0

namespace fnv_00b26db0 {
inline void operator delete(void*, void*)
{}
struct ElQ
{
    int m[14];
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
// @fnv 0x00b26db0
ElQ* FUN_00b26db0(ElQ* first, ElQ* last, ElQ* dest)
{
    ElQ* next = dest;
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
}  // namespace fnv_00b26db0

namespace fnv_00b26e80 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace pushb26e {
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
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};
struct GvElemLess
{
    bool operator()(const GvElem& _Left, const GvElem& _Right) const
    {
        return _Left.f2c > _Right.f2c;
    }
};
}
using namespace pushb26e;
// @fnv 0x00b26e80
void FUN_00b26e80(GvElem* _First, int _Hole, int _Top, GvElem _Val, GvElemLess _Pred)
{
    for (int _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}
}  // namespace fnv_00b26e80

namespace fnv_00b26f90 {
void __cdecl operator delete(void* _Ptr) throw();
inline void operator delete(void*, void*) throw()
{}
namespace popb26f {
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
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
    {
        _Al.destroy(_First);
    }
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
template <class I> inline I GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline I GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline I GvCheckedBase(const I& _It)
{
    GvUnchangedTag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline I GvCheckedBase(I& _It)
{
    GvUnchangedTag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
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
struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(GvAlloc<GvAuxCont> _Al) : _Alaux(_Al)
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
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            FUN_00ec7c56();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        if (!this->_Has_container())
            FUN_00ec7c56();
        if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
              _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            FUN_00ec7c56();
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
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
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
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
template <class T> struct GvVectorVal : GvAuxBase
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase(_Al), _Alval(_Al)
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
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};
struct GvElemLess
{
    bool operator()(const GvElem& _Left, const GvElem& _Right) const;
};
template <class T> inline int* GvDistType(const T*)
{
    return 0;
}
template <class I, class D, class T, class P> inline void GvPushHeap(I _First, D _Hole, D _Top, T _Val, P _Pred)
{
    for (D _Idx = (_Hole - 1) / 2; _Top < _Hole && _Pred(*(_First + _Idx), _Val); _Idx = (_Hole - 1) / 2)
    {
        *(_First + _Hole) = *(_First + _Idx);
        _Hole = _Idx;
    }
    *(_First + _Hole) = _Val;
}
template <class I, class D, class T, class P> inline void GvAdjustHeap(I _First, D _Hole, D _Bottom, T _Val, P _Pred)
{
    D _Top = _Hole;
    D _Idx = 2 * _Hole + 2;
    for (; _Idx < _Bottom; _Idx = 2 * _Idx + 2)
    {
        if (_Pred(*(_First + _Idx), *(_First + (_Idx - 1))))
        {
            --_Idx;
        }
        *(_First + _Hole) = *(_First + _Idx), _Hole = _Idx;
    }
    if (_Idx == _Bottom)
    {
        *(_First + _Hole) = *(_First + (_Bottom - 1));
        _Hole = _Bottom - 1;
    }
    GvPushHeap(_First, _Hole, _Top, _Val, _Pred);
}
inline void GvPopHeap(GvElem* _First, GvElem* _Last, GvElem* _Dest, GvElem _Val, GvElemLess _Pred, int*)
{
    *_Dest = *_First;
    GvAdjustHeap(_First, int(0), int(_Last - _First), _Val, _Pred);
}
}
using namespace popb26f;
// @fnv 0x00b26f90
void FUN_00b26f90(GvElem* _First, GvElem* _Last, GvElemLess _Pred)
{
    GvPopHeap(_First, _Last - 1, _Last - 1, GvElem(*(_Last - 1)), _Pred, GvDistType(_First));
}
}  // namespace fnv_00b26f90

namespace fnv_00b314f0 {
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
    __forceinline void DelQ(unsigned f)
    {
        this->~ElQ();
        if (f & 1)
            FreeQ(this);
    }
};
struct AlQ
{
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    __forceinline void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b35f60(ElQ* f, ElQ* l, ElQ* d, RandQ, PtrCatQ, TagQ);
ElQ* __cdecl FUN_00b35a90(ElQ* f, ElQ* l, ElQ* d);
ElQ* __cdecl FUN_00b368d0(ElQ* f, ElQ* l, ElQ* d, AlQ& al, PtrCatQ, TagQ);
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead6()
{
    int a[6];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead12b()
{
    int a[12];
}
inline void Dead6c()
{
    int a[6];
}
inline void Dead2()
{
    int a[8];
}
inline void DC1()
{
    char a;
    char b;
}
inline void DC2()
{
    short a;
}
inline void DC3()
{
    char a[2];
}
inline void Dead6b()
{
    int a[6];
}
inline void Dead26()
{
    int a[26];
}
inline ElQ* Checked_base4(ElQ* const& it)
{
    return it;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_copy(ElQ* f, ElQ* l, ElQ* d)
{
    return FUN_00b35f60(Checked_base2(f), Checked_base2(l), d, RandQ(), Ptr_cat(f, d), TagQ());
}
inline ElQ* Unchecked_uninitialized_copy(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b368d0(Checked_base2(f), Checked_base4(l), d, al, Ptr_cat(f, d), TagQ());
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
    ElQ* _Ucopy(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_copy(f, l, p, m_al);
    }
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b319e0();
    void FUN_00b32bb0(ElQ* f, ElQ* l);
    bool FUN_00b1f590(unsigned n);
    VecQ& FUN_00b314f0(const VecQ& _Right);
};
// @fnv 0x00b314f0
VecQ& VecQ::FUN_00b314f0(const VecQ& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
        {
            Dead12();
            FUN_00b319e0();
        }
        else if (_Right.size() <= size())
        {
            ElQ* _Ptr = Unchecked_copy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            FUN_00b32bb0(_Ptr, m_last);
            m_last = m_pHeadNode + _Right.size();
            Dead6c();
        }
        else if (_Right.size() <= capacity())
        {
            ElQ* _Ptr = _Right.m_pHeadNode + size();
            FUN_00b35a90(_Right.m_pHeadNode, _Ptr, m_pHeadNode);
            Dead2();
            DC1();
            m_last = _Ucopy(_Ptr, _Right.m_last, m_last);
        }
        else
        {
            if (m_pHeadNode != 0)
            {
                _DestroyI(m_pHeadNode, m_last);
                m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
            }
            if (FUN_00b1f590(_Right.size()))
            {
                Dead26();
                m_last = _Ucopy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            }
        }
    }
    return *this;
}
}  // namespace fnv_00b314f0

namespace fnv_00b31c70 {
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
    __forceinline void DelQ(unsigned f)
    {
        this->~ElQ();
        if (f & 1)
            FreeQ(this);
    }
};
struct AlQ
{
    void deallocate(ElQ* p, unsigned)
    {
        FormHeap_Free(p);
    }
    __forceinline void destroy(ElQ* p)
    {
        p->~ElQ();
    }
    static void FormHeap_Free(void*);
};
inline void FreeQ(void* p)
{
    AlQ::FormHeap_Free(p);
}
ElQ* __cdecl FUN_00b36000(ElQ* f, ElQ* l, ElQ* d, RandQ, PtrCatQ, TagQ);
ElQ* __cdecl FUN_00b35b60(ElQ* f, ElQ* l, ElQ* d);
ElQ* __cdecl FUN_00b369f0(ElQ* f, ElQ* l, ElQ* d, AlQ& al, PtrCatQ, TagQ);
inline ElQ* Checked_base(ElQ* const& it)
{
    return it;
}
inline ElQ* Checked_base2(ElQ* const& it)
{
    int iActionIndex;
    return it;
}
inline void Dead6()
{
    int a[6];
}
inline void Dead12()
{
    int a[12];
}
inline void Dead12b()
{
    int a[12];
}
inline void Dead6c()
{
    int a[6];
}
inline void Dead2()
{
    int a[8];
}
inline void DC1()
{
    char a;
    char b;
}
inline void DC2()
{
    short a;
}
inline void DC3()
{
    char a[2];
}
inline void Dead6b()
{
    int a[6];
}
inline void Dead26()
{
    int a[26];
}
inline ElQ* Checked_base4(ElQ* const& it)
{
    return it;
}
inline PtrCatQ Ptr_cat(ElQ*&, ElQ*&)
{
    PtrCatQ c;
    return c;
}
inline ElQ* Unchecked_copy(ElQ* f, ElQ* l, ElQ* d)
{
    return FUN_00b36000(Checked_base2(f), Checked_base2(l), d, RandQ(), Ptr_cat(f, d), TagQ());
}
inline ElQ* Unchecked_uninitialized_copy(ElQ* f, ElQ* l, ElQ* d, AlQ& al)
{
    return FUN_00b369f0(Checked_base2(f), Checked_base4(l), d, al, Ptr_cat(f, d), TagQ());
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
    ElQ* _Ucopy(ElQ* f, ElQ* l, ElQ* p)
    {
        return Unchecked_uninitialized_copy(f, l, p, m_al);
    }
    __forceinline void _DestroyI(ElQ* f, ElQ* l)
    {
        Destroy_range(f, l, m_al);
    }
    void FUN_00b32120();
    void FUN_00b33110(ElQ* f, ElQ* l);
    bool FUN_00b1f590(unsigned n);
    VecQ& FUN_00b31c70(const VecQ& _Right);
};
// @fnv 0x00b31c70
VecQ& VecQ::FUN_00b31c70(const VecQ& _Right)
{
    if (this != &_Right)
    {
        if (_Right.size() == 0)
        {
            Dead12();
            FUN_00b32120();
        }
        else if (_Right.size() <= size())
        {
            ElQ* _Ptr = Unchecked_copy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            FUN_00b33110(_Ptr, m_last);
            m_last = m_pHeadNode + _Right.size();
            Dead6c();
        }
        else if (_Right.size() <= capacity())
        {
            ElQ* _Ptr = _Right.m_pHeadNode + size();
            FUN_00b35b60(_Right.m_pHeadNode, _Ptr, m_pHeadNode);
            Dead2();
            DC1();
            m_last = _Ucopy(_Ptr, _Right.m_last, m_last);
        }
        else
        {
            if (m_pHeadNode != 0)
            {
                _DestroyI(m_pHeadNode, m_last);
                m_al.deallocate(m_pHeadNode, m_kRayEnd - m_pHeadNode);
            }
            if (FUN_00b1f590(_Right.size()))
            {
                Dead26();
                m_last = _Ucopy(_Right.m_pHeadNode, _Right.m_last, m_pHeadNode);
            }
        }
    }
    return *this;
}
}  // namespace fnv_00b31c70

namespace addb18 {
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
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> inline GvNonscalarTag GvPtrCat(T1&, T2&)
{
    GvNonscalarTag _Cat;
    return _Cat;
}
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
    {
        _Al.destroy(_First);
    }
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
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
    void _Orphan_all() const
    {}
};
struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(GvAlloc<GvAuxCont> _Al) : _Alaux(_Al)
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
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            FUN_00ec7c56();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        if (!this->_Has_container())
            FUN_00ec7c56();
        if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
              _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            FUN_00ec7c56();
        _Myptr += _Off;
        return *this;
    }
    int operator-(const GvConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            FUN_00ec7c56();
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
template <class T> struct GvVectorVal : GvAuxBase
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase(_Al), _Alval(_Al)
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
            this->_Orphan_all();
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
struct GvInner
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
};
struct GvElem
{
    GvVector<GvInner> kList;
    float f18;
    float f1c;
    bool b20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
    GvElem()
    {
        f18 = 0.0f;
        f1c = 0.0f;
        b20 = false;
        f24 = 0.0f;
        f28 = 0.0f;
        f2c = 0.0f;
        i30 = 0;
        i34 = 0;
    }
};
struct GvOwner
{
    int unk00;
    int unk04;
    GvVector<GvElem> kElems;
    void FUN_00b188d0();
};
}
using namespace addb18;
// @fnv 0x00b188d0
void GvOwner::FUN_00b188d0()
{
    GvElem kElem;
    kElems.push_back(kElem);
}

namespace fnv_00b236a0 {
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
template <class _InIt, class _OutIt, class _InOutItCat, class _MoveCatTy>
inline _OutIt _Move_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat _First_dest_cat, _MoveCatTy,
                         _Range_checked_iterator_tagS)
{
    return _Copy_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS());
}
struct E36A0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
// @fnv 0x00b236a0
E36A0* __cdecl FUN_00b236a0(E36A0* _First, E36A0* _Last, E36A0* _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b236a0

struct S00b24290_Base
{
    void* storage;
    void* storageEnd;
    void* storageLimit;
    void* elements;
    void* elementsEnd;
    void* elementsLimit;
    void Release(void* p)
    {
        operator delete(p);
    }
    ~S00b24290_Base()
    {
        Release(storage);
    }
};
struct S00b24290_Arg
{
    int v;
};
class FUN_00b231f0 : public S00b24290_Base
{
  public:
    FUN_00b231f0(const S00b24290_Arg&);
    ~FUN_00b231f0()
    {
        int u00;
        int u01;
        int u02;
        int u03;
        int u04;
        int u05;
        int u06;
        int u07;
        int u08;
        int u09;
        int u10;
        int u11;
        int u12;
        int u13;
        int u14;
        ((FUN_00b1ec70_class*)this)->FUN_00b1ec70();
    }
};
inline void S00b24290_Construct(FUN_00b231f0* p, const S00b24290_Arg& v)
{
    void* vp = p;
    ::new (vp) FUN_00b231f0(v);
}
// @fnv 0x00b24290
void __cdecl FUN_00b24290(FUN_00b231f0* first, unsigned int count, const S00b24290_Arg& param)
{
    FUN_00b231f0* constructed = first;
    try
    {
        for (; count > 0; --count, ++first)
            S00b24290_Construct(first, param);
    }
    catch (...)
    {
        for (; constructed != first; ++constructed)
            constructed->~FUN_00b231f0();
        FUN_00ec7894(0, 0);
    }
}

struct S00b26260_E
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    S00b26260_E(const S00b26260_E& src)
    {
        int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
        a0 = src.u00;
        a1 = src.u04;
        a2 = src.u08;
        a3 = src.u0c;
        a4 = src.u10;
        a5 = src.u14;
        a6 = src.u18;
        a7 = src.u1c;
        a8 = src.u20;
        a9 = src.u24;
        a10 = src.u28;
        a11 = src.u2c;
        a12 = src.u30;
        a1 = a0;
        a2 = a1;
        a3 = a2;
        a4 = a3;
        a5 = a4;
        a6 = a5;
        a7 = a6;
        a8 = a7;
        a9 = a8;
        a10 = a9;
        a11 = a10;
        a12 = a11;
        u00 = a12;
    }
    S00b26260_E();
    ~S00b26260_E();
};

void __cdecl FUN_00b26b50(S00b26260_E* first, int hole, int bottom, S00b26260_E val, bool pred);

// @fnv 0x00b26260
void __cdecl FUN_00b26260(S00b26260_E* first, S00b26260_E* last, bool pred)
{
    int bottom = last - first;
    int hole = bottom / 2;
    while (0 < hole)
    {
        --hole;
        FUN_00b26b50(first, hole, bottom, first[hole], pred);
    }
}

namespace spt {

struct Aux
{
    void* owned;
    int al;
    void dealloc(void* p)
    {
        ::operator delete(p);
    }
    ~Aux()
    {
        dealloc(owned);
    }
};

struct Vec : Aux
{
    int alval;
    int* first;
    int* last;
    int* end;
    void FUN_00b1e970();
    ~Vec()
    {
        FUN_00b1e970();
    }
};

struct FUN_00b1ff50
{
    Vec v;
    float f18;
    float f1c;
    unsigned char c20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
    FUN_00b1ff50(const FUN_00b1ff50& that);
    FUN_00b1ff50* CopyFrom(const FUN_00b1ff50& that);
    bool operator<(const FUN_00b1ff50& o) const
    {
        return f2c > o.f2c;
    }
};

inline FUN_00b1ff50::FUN_00b1ff50(const FUN_00b1ff50& that)
{
    int n = 0;
    if (n)
    {
        FUN_00b1ff50 tmp(that);
        (void)tmp;
    }
    v = that.v;
}

inline FUN_00b1ff50* FUN_00b1ff50::CopyFrom(const FUN_00b1ff50& that)
{
    int n = 0;
    if (n)
        return CopyFrom(that);
    v = that.v;
    f18 = that.f18;
    f1c = that.f1c;
    c20 = that.c20;
    f24 = that.f24;
    f28 = that.f28;
    f2c = that.f2c;
    i30 = that.i30;
    i34 = that.i34;
    return this;
}

}

typedef spt::FUN_00b1ff50 Guide;

void __cdecl FUN_00b26ce0(Guide* a, Guide* b, Guide* c);

// @fnv 0x00b262d0
void __cdecl FUN_00b262d0(Guide* _First, Guide* _Last)
{
    if (_First != _Last)
        for (Guide* _Next = _First; ++_Next != _Last;)
        {
            Guide* _Next1 = _Next;
            Guide _Val = *_Next;
            if (_Val < *_First)
            {
                FUN_00b26ce0(_First, _Next, ++_Next1);
                _First->CopyFrom(_Val);
            }
            else
            {
                for (Guide* _First1 = _Next1; _Val < *--_First1; _Next1 = _First1)
                    _Next1->CopyFrom(*_First1);
                _Next1->CopyFrom(_Val);
            }
        }
}

struct SG
{
    int f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, fa, fb, fc, fd;
    SG();
    SG(const SG& that);
    void assign(const SG* that);
    ~SG();
};
void __cdecl REAL(char* first, int zero, int count, SG pivot, bool flag);
inline void FUN_00b26f90(char* first, char* last, bool flag, int ideal)
{
    SG tmp(*(const SG*)last);
    SG buf;
    ((SG*)last)->assign((const SG*)first);
    REAL(first, 0, (int)((last - first) / 56), tmp, flag);
}
// @fnv 0x00b26ca0
void __cdecl FUN_00b26ca0(char* first, char* last, bool flag)
{
    char* dead;
    if ((last - first) / 0x38 > 1)
    {
        char* t = last;
        FUN_00b26f90(first, t, flag, 0);
    }
}

double __cdecl FUN_00ec9f30(double);
double __cdecl FUN_00eca060(double);
struct RotMat
{
    float m_fComponents[3][3];
    void FUN_00b12af0();
    RotMat Multiply(const RotMat& b) const;
};
inline void Unused()
{
    RotMat kResult;
}
struct FUN_00b1ae00_class : RotMat
{
    void __thiscall FUN_00b1ae00(float angle);
};
// @fnv 0x00b1ae00
void FUN_00b1ae00_class::FUN_00b1ae00(float fAngleDifference)
{
    RotMat cRotMatrix;
    cRotMatrix.FUN_00b12af0();
    float fCosine = (float)(double)(float)FUN_00ec9f30((float)(fAngleDifference / DAT_010a4d90));
    float fSine = (float)(double)(float)FUN_00eca060((float)(fAngleDifference / DAT_010a4d90));
    cRotMatrix.m_fComponents[0][0] = 1.0f;
    cRotMatrix.m_fComponents[0][1] = 0.0f;
    cRotMatrix.m_fComponents[0][2] = 0.0f;
    cRotMatrix.m_fComponents[1][0] = 0.0f;
    cRotMatrix.m_fComponents[1][1] = fCosine;
    cRotMatrix.m_fComponents[1][2] = fSine;
    cRotMatrix.m_fComponents[2][0] = 0.0f;
    cRotMatrix.m_fComponents[2][1] = -fSine;
    cRotMatrix.m_fComponents[2][2] = fCosine;
    *(RotMat*)this = cRotMatrix.Multiply(*this);
    Unused();
}

namespace fg {
struct input_iterator_tag
{
};
struct forward_iterator_tag : public input_iterator_tag
{
};
struct bidirectional_iterator_tag : public forward_iterator_tag
{
};
struct random_access_iterator_tag : public bidirectional_iterator_tag
{
};
struct _Nonscalar_ptr_iterator_tag
{
};
struct _Range_checked_iterator_tag
{
};
template <class _T1, class _T2> inline _Nonscalar_ptr_iterator_tag _Ptr_cat(_T1&, _T2&)
{
    _Nonscalar_ptr_iterator_tag _Cat;
    return (_Cat);
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_inner(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                    _Nonscalar_ptr_iterator_tag, _Range_checked_iterator_tag)
{
    int dead[76];
    while (_First != _Last)
    {
        --_Last;
        --_Dest;
        _Dest->CopyFrom(*_Last);
    }
    return (_Dest);
}
template <class _InIt, class _OutIt>
__forceinline _OutIt _Copy_backward_opt(_InIt _First, _InIt _Last, _OutIt _Dest, _Nonscalar_ptr_iterator_tag,
                                        _Range_checked_iterator_tag)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_inner(_First, _Last, _Dest, forward_iterator_tag(), _Nonscalar_ptr_iterator_tag(),
                         _Range_checked_iterator_tag());
    return _Result;
}
}
// @fnv 0x00b240b0
CopyableStateBlock* __cdecl FUN_00b240b0(CopyableStateBlock* _First, CopyableStateBlock* _Last,
                                         CopyableStateBlock* _Dest)
{
    return fg::_Copy_backward_opt(_First, _Last, _Dest, fg::_Ptr_cat(_First, _Dest), fg::_Range_checked_iterator_tag());
}

#include <math.h>
namespace fnv_00b1be50 {
extern "C" void __cdecl _invalid_parameter_noinfo();
extern "C" double __cdecl atan2(double, double);
double __cdecl FUN_00ec9f30(double x);
extern "C" double __cdecl FUN_00eca060(double x);
extern float DAT_011f8c9c;

inline void padQ()
{
    char p[0x28];
}
inline float atan2Q(float y, float x)
{
    return (float)(double)(float)atan2((double)y, (double)x);
}
inline float sinQ(float x)
{
    return (float)(double)(float)FUN_00eca060((double)x);
}
inline float cosQ(float x)
{
    return (float)(double)(float)FUN_00ec9f30((double)x);
}

struct PointQ
{
    float v[3];
    PointQ()
    {
        v[0] = v[1] = v[2] = 0.0f;
    }
    PointQ(float x, float y, float z)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
    float& operator[](int i)
    {
        return v[i];
    }
    void FUN_00b12790();
};
struct PointVecQ
{
    int unk00;
    int unk04;
    int unk08;
    PointQ* m_pHeadNode;
    PointQ* m_last;
    PointQ* m_kRayEnd;
    unsigned size() const
    {
        return m_last - m_pHeadNode;
    }
    PointQ& operator[](unsigned pos)
    {
        if (!(pos < size()))
            _invalid_parameter_noinfo();
        return *(m_pHeadNode + pos);
    }
    void FUN_00b1e4c0(const PointQ& p);
};
struct CurveQ
{
    float FUN_00b37ad0(float t);
};
struct ScaleQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_height;
};
struct FUN_00b1be50_Owner
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
    CurveQ* m_profile;
    unsigned m_uiItemCount;
    void FUN_00b1be50(ScaleQ* scale, PointVecQ& points, PointVecQ& normals);
};

// @fnv 0x00b1be50
void FUN_00b1be50_Owner::FUN_00b1be50(ScaleQ* scale, PointVecQ& points, PointVecQ& normals)
{
    float base = m_profile->FUN_00b37ad0(0.0f) * scale->m_height;
    for (unsigned i = 0; i < m_uiItemCount; i++)
    {
        float t = 1.0 - i / (m_uiItemCount - 1.0);
        PointQ p;
        p[0] = 0.0f;
        p[1] = -t * scale->m_height;
        p[2] = m_profile->FUN_00b37ad0(t) * scale->m_height - base;
        points.FUN_00b1e4c0(p);
    }
    for (int j = m_uiItemCount - 2; j >= 0; j--)
    {
        PointQ p = points[j];
        p[1] *= -1.0;
        points.FUN_00b1e4c0(p);
    }
    for (unsigned k = 0; k < points.size(); k++)
    {
        float angle;
        if (k == m_uiItemCount - 1)
            angle = DAT_011f8c9c;
        else if (k == 0)
        {
            float a = atan2Q(points[k + 1][2] - points[k][2], points[k + 1][1] - points[k][1]);
            angle = a + DAT_011f8c9c;
        }
        else if (k == points.size() - 1)
        {
            float a = atan2Q(points[k][2] - points[k - 1][2], points[k][1] - points[k - 1][1]);
            angle = a + DAT_011f8c9c;
        }
        else
        {
            float a1 = atan2Q(points[k + 1][2] - points[k][2], points[k + 1][1] - points[k][1]);
            float a2 = atan2Q(points[k][2] - points[k - 1][2], points[k][1] - points[k - 1][1]);
            angle = (a2 + a1) * 0.5 + DAT_011f8c9c;
        }
        {
            char pad[0x3c];
        }
        PointQ n(0.0f, cosQ(angle), sinQ(angle));
        padQ();
        n.FUN_00b12790();
        normals.FUN_00b1e4c0(n);
    }
}
}  // namespace fnv_00b1be50

namespace fnv_00b23b00 {
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
struct _Different_checked_iterator_base_type_tagS
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
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Different_checked_iterator_base_type_tagS)
{
    return _It._Checked_iterator_base();
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
    typedef const _Ty* _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return _Myptr;
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
template <class _Ty> struct _Checked_iterator_base_helperS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Different_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef const _Ty* _Checked_iterator_base_type;
};
template <class _Ty, class _T2> struct _Ptr_cat_helperS<_Vector_const_iteratorS<_Ty>, _T2>
{
    typedef typename _Ptr_cat_helperS<_Ty*, _T2>::_Ptr_cat _Ptr_cat;
};
template <class _Ty> struct _Iter_valueS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Vector_const_iteratorS<_Ty> >
{
    typedef random_access_iterator_tagS iterator_category;
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
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
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
    CharAllocator(const CharAllocator&)
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
    String(const String& kRight) : StringVal()
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& operator=(const String& _Right)
    {
        return (assign(_Right));
    }
    String& assign(const String& _Right)
    {
        return (assign(_Right, 0, npos));
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
    String& operator+=(const String& kRight)
    {
        return append(kRight);
    }
    String& operator+=(const char* pcPtr)
    {
        return append(pcPtr);
    }
    String& append(const String& kRight)
    {
        return append(kRight, 0, npos);
    }
    String& append(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (uiElementCount < ItemUpdateArray)
            ItemUpdateArray = uiElementCount;
        if (npos - m_uiSize <= ItemUpdateArray || m_uiSize + ItemUpdateArray < m_uiSize)
            _Xlen();
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, kRight._Myptr() + uiRoff, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return append(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (npos - m_uiSize <= ItemUpdateArray)
            _Xlen();
        unsigned int uiElementCount;
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, pcPtr, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr)
    {
        return append(pcPtr, CharTraits::length(pcPtr));
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
            InvalidParameterNoInfoS();
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
        CharTraits::assign((16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf)[m_uiSize = uiNewsize], char());
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
inline String operator+(const String& kLeft, const char* pcRight)
{
    return String(kLeft) += pcRight;
}
inline String operator+(const String& kLeft, const String& kRight)
{
    return String(kLeft) += kRight;
}
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    int _Reserve1;
    int _Reserve2;
    int _Reserve3;
    int _Reserve4;
    int _Reserve5;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    _First = _Last;
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
template <class _InIt, class _OutIt, class _InOutItCat, class _MoveCatTy>
inline _OutIt _Move_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat _First_dest_cat, _MoveCatTy,
                         _Range_checked_iterator_tagS)
{
    return _Copy_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS());
}
struct SA4830
{
    String m_kName;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
// @fnv 0x00b23b00
SA4830* __cdecl FUN_00b23b00(SA4830* _First, SA4830* _Last, SA4830* _Dest)
{
    return (_Move_backward_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                                _Move_catS(_Dest), _Range_checked_iterator_tagS()));
}
}  // namespace fnv_00b23b00

namespace fnv_00b24180 {
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
    char b[0x38];
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
    int x[8];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b24180
void FUN_00b24180(ElemQ* first, unsigned int n, const ElemQ& val)
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
}  // namespace fnv_00b24180

namespace fnv_00b243a0 {
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
struct FUN_00b22f80
{
    StrY s;
    char b[0x10];
    FUN_00b22f80(const FUN_00b22f80& o);
};
inline void Del(FUN_00b22f80* p, unsigned int f)
{
    p->s.FUN_0044a730(true, 0);
    if (f & 1)
        FormHeap_Free(p);
}
inline void DeadX()
{
    int x[10];
}
inline void Construct(FUN_00b22f80* p, const FUN_00b22f80& v)
{
    void* vp = p;
    ::new (vp) FUN_00b22f80(v);
    DeadX();
}
// @fnv 0x00b243a0
void FUN_00b243a0(FUN_00b22f80* first, unsigned int n, const FUN_00b22f80& val)
{
    FUN_00b22f80* next = first;
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
}  // namespace fnv_00b243a0

namespace fnv_00b24580 {
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
// @fnv 0x00b24580
void FUN_00b24580(ElemQ* first, unsigned int n, const ElemQ& val)
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
}  // namespace fnv_00b24580

namespace fnv_00b24830 {
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
struct _Different_checked_iterator_base_type_tagS
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
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Different_checked_iterator_base_type_tagS)
{
    return _It._Checked_iterator_base();
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
    typedef const _Ty* _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return _Myptr;
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
template <class _Ty> struct _Checked_iterator_base_helperS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Different_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef const _Ty* _Checked_iterator_base_type;
};
template <class _Ty, class _T2> struct _Ptr_cat_helperS<_Vector_const_iteratorS<_Ty>, _T2>
{
    typedef typename _Ptr_cat_helperS<_Ty*, _T2>::_Ptr_cat _Ptr_cat;
};
template <class _Ty> struct _Iter_valueS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Vector_const_iteratorS<_Ty> >
{
    typedef random_access_iterator_tagS iterator_category;
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
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
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
    CharAllocator(const CharAllocator&)
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
    String(const String& kRight) : StringVal()
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& operator=(const String& _Right)
    {
        return (assign(_Right));
    }
    String& assign(const String& _Right)
    {
        return (assign(_Right, 0, npos));
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
    String& operator+=(const String& kRight)
    {
        return append(kRight);
    }
    String& operator+=(const char* pcPtr)
    {
        return append(pcPtr);
    }
    String& append(const String& kRight)
    {
        return append(kRight, 0, npos);
    }
    String& append(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (uiElementCount < ItemUpdateArray)
            ItemUpdateArray = uiElementCount;
        if (npos - m_uiSize <= ItemUpdateArray || m_uiSize + ItemUpdateArray < m_uiSize)
            _Xlen();
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, kRight._Myptr() + uiRoff, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return append(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (npos - m_uiSize <= ItemUpdateArray)
            _Xlen();
        unsigned int uiElementCount;
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, pcPtr, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr)
    {
        return append(pcPtr, CharTraits::length(pcPtr));
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
            InvalidParameterNoInfoS();
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
        CharTraits::assign((16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf)[m_uiSize = uiNewsize], char());
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
inline String operator+(const String& kLeft, const char* pcRight)
{
    return String(kLeft) += pcRight;
}
inline String operator+(const String& kLeft, const String& kRight)
{
    return String(kLeft) += kRight;
}
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
template <class _InIt, class _OutIt, class _InOutItCat, class _MoveCatTy>
inline _OutIt _Move_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat _First_dest_cat, _MoveCatTy,
                         _Range_checked_iterator_tagS)
{
    return _Copy_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS());
}
struct SA4830
{
    String m_kName;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
// @fnv 0x00b24830
SA4830* __cdecl FUN_00b24830(SA4830* _First, SA4830* _Last, SA4830* _Dest, random_access_iterator_tagS _First_dest_cat,
                             _Undefined_move_tagS, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
}  // namespace fnv_00b24830

namespace fnv_00b248c0 {
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
struct _Different_checked_iterator_base_type_tagS
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
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Different_checked_iterator_base_type_tagS)
{
    return _It._Checked_iterator_base();
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
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
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
    typedef const _Ty* _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return _Myptr;
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
template <class _Ty> struct _Checked_iterator_base_helperS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Different_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef const _Ty* _Checked_iterator_base_type;
};
template <class _Ty, class _T2> struct _Ptr_cat_helperS<_Vector_const_iteratorS<_Ty>, _T2>
{
    typedef typename _Ptr_cat_helperS<_Ty*, _T2>::_Ptr_cat _Ptr_cat;
};
template <class _Ty> struct _Iter_valueS<_Vector_const_iteratorS<_Ty> >
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Vector_const_iteratorS<_Ty> >
{
    typedef random_access_iterator_tagS iterator_category;
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
extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
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
    CharAllocator(const CharAllocator&)
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
    String(const String& kRight) : StringVal()
    {
        _Tidy();
        assign(kRight, 0, npos);
    }
    ~String()
    {
        _Tidy(true);
    }
    String& operator=(const String& _Right)
    {
        return (assign(_Right));
    }
    String& assign(const String& _Right)
    {
        return (assign(_Right, 0, npos));
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
    String& operator+=(const String& kRight)
    {
        return append(kRight);
    }
    String& operator+=(const char* pcPtr)
    {
        return append(pcPtr);
    }
    String& append(const String& kRight)
    {
        return append(kRight, 0, npos);
    }
    String& append(const String& kRight, unsigned int uiRoff, unsigned int ItemUpdateArray)
    {
        if (kRight.size() < uiRoff)
            _Xran();
        unsigned int uiElementCount = kRight.size() - uiRoff;
        if (uiElementCount < ItemUpdateArray)
            ItemUpdateArray = uiElementCount;
        if (npos - m_uiSize <= ItemUpdateArray || m_uiSize + ItemUpdateArray < m_uiSize)
            _Xlen();
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, kRight._Myptr() + uiRoff, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr, unsigned int ItemUpdateArray)
    {
        if (_Inside(pcPtr))
            return append(*this, pcPtr - _Myptr(), ItemUpdateArray);
        if (npos - m_uiSize <= ItemUpdateArray)
            _Xlen();
        unsigned int uiElementCount;
        if (0 < ItemUpdateArray && _Grow(uiElementCount = m_uiSize + ItemUpdateArray))
        {
            TraitsHelper::CopyS(_Myptr() + m_uiSize, m_uiRes - m_uiSize, pcPtr, ItemUpdateArray);
            _Eos(uiElementCount);
        }
        return *this;
    }
    String& append(const char* pcPtr)
    {
        return append(pcPtr, CharTraits::length(pcPtr));
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
            InvalidParameterNoInfoS();
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
        CharTraits::assign((16 <= m_uiRes ? m_kBx.m_pcPtr : m_kBx.m_acBuf)[m_uiSize = uiNewsize], char());
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
inline String operator+(const String& kLeft, const char* pcRight)
{
    return String(kLeft) += pcRight;
}
inline String operator+(const String& kLeft, const String& kRight)
{
    return String(kLeft) += kRight;
}
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
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
template <class _InIt, class _OutIt, class _InOutItCat, class _MoveCatTy>
inline _OutIt _Move_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat _First_dest_cat, _MoveCatTy,
                         _Range_checked_iterator_tagS)
{
    return _Copy_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS());
}
struct E48C0
{
    int unk00;
    int unk04;
    int unk08;
};
// @fnv 0x00b248c0
E48C0* __cdecl FUN_00b248c0(E48C0* _First, E48C0* _Last, E48C0* _Dest, random_access_iterator_tagS _First_dest_cat,
                            _Undefined_move_tagS, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
}  // namespace fnv_00b248c0

namespace fnv_00b25ba0 {
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
struct FUN_00b22f80
{
    StrY s;
    char b[0x10];
    FUN_00b22f80(const FUN_00b22f80& o);
};
inline void Del(FUN_00b22f80* p, unsigned int f)
{
    p->s.FUN_0044a730(true, 0);
    if (f & 1)
        FormHeap_Free(p);
}
inline void DeadX()
{
    int x[10];
}
inline void Construct(FUN_00b22f80* p, const FUN_00b22f80& v)
{
    void* vp = p;
    ::new (vp) FUN_00b22f80(v);
    DeadX();
}
// @fnv 0x00b25ba0
FUN_00b22f80* FUN_00b25ba0(FUN_00b22f80* first, FUN_00b22f80* last, FUN_00b22f80* dest)
{
    FUN_00b22f80* next = dest;
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
}  // namespace fnv_00b25ba0

namespace fnv_00b25ca0 {
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
struct MQ
{
    int b[6];
    ~MQ();
};
struct ElemQ : VBQ
{
    MQ m;
    ElemQ();
    ElemQ(const ElemQ& o);
    void FUN_00b267a0(ElemQ& o);
};
__forceinline void Del(ElemQ* p, unsigned int f)
{
    p->~ElemQ();
}
inline void DeadX()
{
    int x[26];
}
inline void DeadY()
{
    int y[16];
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
// @fnv 0x00b25ca0
ElemQ* FUN_00b25ca0(ElemQ* first, ElemQ* last, ElemQ* dest)
{
    ElemQ* next = dest;
    ElemQ _Val;
    DeadT();
    try
    {
        for (; first != last; ++dest, ++first)
        {
            Construct(dest, _Val);
            dest->FUN_00b267a0(*first);
        }
    }
    catch (...)
    {
        for (; next != dest; ++next)
            Del(next, 0);
        DeadY();
        throw;
    }
    return dest;
}
}  // namespace fnv_00b25ca0

namespace fnv_00b25e20 {
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
struct MQ
{
    int b[6];
    ~MQ();
};
struct ElemQ : VBQ
{
    MQ m;
    ElemQ();
    ElemQ(const ElemQ& o);
    void FUN_00b26570(ElemQ& o);
};
__forceinline void Del(ElemQ* p, unsigned int f)
{
    p->~ElemQ();
}
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
// @fnv 0x00b25e20
ElemQ* FUN_00b25e20(ElemQ* first, ElemQ* last, ElemQ* dest)
{
    ElemQ* next = dest;
    ElemQ _Val;
    DeadT();
    try
    {
        for (; first != last; ++dest, ++first)
        {
            Construct(dest, _Val);
            dest->FUN_00b26570(*first);
        }
    }
    catch (...)
    {
        for (; next != dest; ++next)
            Del(next, 0);
        DeadY();
        throw;
    }
    return dest;
}
}  // namespace fnv_00b25e20

namespace fnv_00b25fa0 {
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
    char b[0x38];
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
    int x[8];
}
inline void Construct(ElemQ* p, const ElemQ& v)
{
    void* vp = p;
    ::new (vp) ElemQ(v);
    DeadX();
}
// @fnv 0x00b25fa0
ElemQ* FUN_00b25fa0(ElemQ* first, ElemQ* last, ElemQ* dest)
{
    ElemQ* next = dest;
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
}  // namespace fnv_00b25fa0

namespace fnv_00b267a0 {
void __cdecl FormHeap_Free(void* p);
template <class T> inline void Swp(T& a, T& b)
{
    if (&a != &b)
    {
        T t = a;
        a = b;
        b = t;
    }
}
struct Proxy
{
    int* pCont;
};
struct VecBase
{
    inline Proxy*& PP()
    {
        return *(Proxy**)this;
    }
    inline void Dealloc(void* q)
    {
        FormHeap_Free(q);
    }
    ~VecBase()
    {
        Dealloc(PP());
    }
    inline void SwapAll(VecBase& r)
    {
        Swp(PP(), r.PP());
        Swp(*PP(), *r.PP());
    }
};
inline void DeadX()
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
    int d21;
    int d22;
    int d23;
    int d24;
    int d25;
    int d26;
    int d27;
    int d28;
    int d29;
    int d30;
    int d31;
    int d32;
    int d33;
    int d34;
    int d35;
    int d36;
    int d37;
    int d38;
    int d39;
    int d40;
    int d41;
    int d42;
    int d43;
    int d44;
    int d45;
    int d46;
    int d47;
    int d48;
    int d49;
    int d50;
    int d51;
    int d52;
    int d53;
    int d54;
    int d55;
    int d56;
    int d57;
    int d58;
    int d59;
    int d60;
    int d61;
    int d62;
    int d63;
    int d64;
    int d65;
    int d66;
    int d67;
    int d68;
    int d69;
    int d70;
    int d71;
    int d72;
    int d73;
    int d74;
    int d75;
    int d76;
    int d77;
    int d78;
    int d79;
    int d80;
    int d81;
    int d82;
    int d83;
    int d84;
    int d85;
    int d86;
    int d87;
    int d88;
    int d89;
    int d90;
}
struct Alloc
{
    inline bool operator==(const Alloc&) const
    {
        return true;
    }
};
struct FUN_00b1ec70
{
    Proxy* pProxy;
    int i4;
    Alloc al;
    int* pFirst;
    int* pLast;
    int* pEnd;
    ~FUN_00b1ec70();
};
struct FUN_00b231f0 : VecBase
{
    FUN_00b1ec70 e;
    FUN_00b231f0(const FUN_00b231f0& r);
    ~FUN_00b231f0()
    {}
    FUN_00b231f0& FUN_00b24f40(const FUN_00b231f0& r);
    void FUN_00b267a0(FUN_00b231f0& r);
};
// @fnv 0x00b267a0
void FUN_00b231f0::FUN_00b267a0(FUN_00b231f0& r)
{
    if (this == &r)
        ;
    else if (e.al == r.e.al)
    {
        SwapAll(r);
        Swp(e.pFirst, r.e.pFirst);
        Swp(e.pLast, r.e.pLast);
        Swp(e.pEnd, r.e.pEnd);
    }
    else
    {
        SwapAll(r);
        FUN_00b231f0 tmp(*this);
        FUN_00b24f40(r);
        r.FUN_00b24f40(tmp);
        DeadX();
    }
}
}  // namespace fnv_00b267a0

struct SBranchSub
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
};
struct BranchPoint
{
    int f0;
    int f4;
    int f8;
    SBranchSub sub;
    float f30;
    int i34;
    void FUN_00b18b20();
};
struct SBranchList : addb18::GvVector<BranchPoint>
{
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    void FUN_00b1d980(const BranchPoint& e)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, e);
        }
        else
        {
            insert(end(), e);
        }
    }
};

struct SBranchVec
{
    int unk00;
    int unk04;
    int unk08;
    SBranchList* m_pHeadNode;
    SBranchList* m_last;
    SBranchList* m_kRayEnd;
    unsigned int size() const
    {
        return m_last - m_pHeadNode;
    }
    SBranchList& operator[](unsigned int n)
    {
        if (n >= size())
            ::FUN_00ec7c56();
        return m_pHeadNode[n];
    }
};

struct SBranchOwner
{
    int unk00;
    int unk04;
    SBranchVec m_vec;
    void FUN_00b18a60(BranchPoint e);
};
// @fnv 0x00b18a60
void SBranchOwner::FUN_00b18a60(BranchPoint e)
{
    BranchPoint local;
    local.FUN_00b18b20();
    local.f0 = e.f0;
    local.f4 = e.f4;
    local.f8 = e.f8;
    local.sub = e.sub;
    local.f30 = e.f30;
    local.i34 = e.i34;
    m_vec[m_vec.size() - 1].FUN_00b1d980(local);
}

typedef addb18::GvElem AppendGuide;
typedef addb18::GvAlloc<AppendGuide> AppendAllocator;
typedef addb18::GvConstIterator<AppendGuide> AppendConstIterator;
typedef addb18::GvIterator<AppendGuide> AppendIterator;

void __cdecl FUN_00b24180(AppendGuide* first, unsigned int count, const AppendGuide& value, AppendAllocator& allocator,
                          addb18::GvNonscalarTag, addb18::GvRangeCheckedTag);

inline void FillAppendGuides(AppendGuide* first, unsigned int count, const AppendGuide& value,
                             AppendAllocator& allocator)
{
    FUN_00b24180(first, count, value, allocator, addb18::GvPtrCat(first, first), addb18::GvRangeCheckedTag());
}

struct AppendGuideVector : addb18::GvVector<AppendGuide>
{
    AppendGuide* FillEnd(AppendGuide* first, unsigned int count, const AppendGuide& value)
    {
        FillAppendGuides(first, count, value, this->_Alval);
        return first + count;
    }

    AppendIterator FUN_00b1dc50(AppendConstIterator where, const AppendGuide& value)
    {
        unsigned int offset = size() == 0 ? 0 : where - begin();
        _Insert_n(where, 1, value);
        return begin() + offset;
    }

    void FUN_00b1db40(const AppendGuide& value);
};

// @fnv 0x00b1db40
void AppendGuideVector::FUN_00b1db40(const AppendGuide& value)
{
    if (size() < capacity())
    {
        _Mylast = FillEnd(_Mylast, 1, value);
    }
    else
    {
        FUN_00b1dc50(end(), value);
    }
}

typedef dtorb181::GvVector<dtorb181::GvElemV> FrondGroupValue;
typedef dtorb181::GvConstIterator<FrondGroupValue> FrondGroupConstIterator;
typedef dtorb181::GvIterator<FrondGroupValue> FrondGroupIterator;
void __cdecl FUN_00b24290(FrondGroupValue*, unsigned int, const FrondGroupValue&, dtorb181::GvAlloc<FrondGroupValue>&,
                          dtorb181::GvNonscalarTag, dtorb181::GvRangeCheckedTag);
inline void FrondGroupFill(FrondGroupValue* first, unsigned int count, const FrondGroupValue& value,
                           dtorb181::GvAlloc<FrondGroupValue>& allocator)
{
    FUN_00b24290(first, count, value, allocator, dtorb181::GvPtrCat(first, first), dtorb181::GvRangeCheckedTag());
}
struct FrondGroupList : dtorb181::GvVector<FrondGroupValue>
{
    FrondGroupValue* Fill(FrondGroupValue* ptr, unsigned int count, const FrondGroupValue& value)
    {
        FrondGroupFill(ptr, count, value, _Alval);
        return ptr + count;
    }
    FrondGroupIterator FUN_00b1f460(FrondGroupConstIterator where, const FrondGroupValue& value)
    {
        unsigned int offset = size() == 0 ? 0 : where - begin();
        _Insert_n(where, 1, value);
        return begin() + offset;
    }
    void FUN_00b1df80(const FrondGroupValue& value);
};
// @fnv 0x00b1df80
void FrondGroupList::FUN_00b1df80(const FrondGroupValue& value)
{
    if (size() < capacity())
        _Mylast = Fill(_Mylast, 1, value);
    else
        FUN_00b1f460(end(), value);
}

void __cdecl FUN_00b244a0(FrondPoint*, unsigned int, const FrondPoint&, dtorb181::GvAlloc<FrondPoint>&,
                          dtorb181::GvNonscalarTag, dtorb181::GvRangeCheckedTag);

inline void FillPointRange(FrondPoint* destination, unsigned int count, const FrondPoint& value,
                           dtorb181::GvAlloc<FrondPoint>& allocator)
{
    FUN_00b244a0(destination, count, value, allocator, dtorb181::GvPtrCat(destination, destination),
                 dtorb181::GvRangeCheckedTag());
}

struct FrondPointAppend : dtorb181::GvVector<FrondPoint>
{
    FrondPoint* fillTail(FrondPoint* destination, unsigned int count, const FrondPoint& value)
    {
        FillPointRange(destination, count, value, this->_Alval);
        return destination + count;
    }
    dtorb181::GvIterator<FrondPoint> FUN_00b1fab0(dtorb181::GvConstIterator<FrondPoint> where, const FrondPoint& value)
    {
        unsigned int offset = size() == 0 ? 0 : where - begin();
        _Insert_n(where, 1, value);
        return begin() + offset;
    }
    void FUN_00b1e4c0(const FrondPoint& value);
};

// @fnv 0x00b1e4c0
void FrondPointAppend::FUN_00b1e4c0(const FrondPoint& value)
{
    if (size() < capacity())
        _Mylast = fillTail(_Mylast, 1, value);
    else
        FUN_00b1fab0(end(), value);
}

struct ElQ_acf7d0
{
    int m[14];
};
struct AlQ_acf7d0
{
};
struct CatQ_acf7d0
{
};
struct TagQ_acf7d0
{
};
struct ElQ_acf7d0;
inline CatQ_acf7d0 PtrCat_acf7d0(ElQ_acf7d0*&, ElQ_acf7d0*&)
{
    CatQ_acf7d0 c;
    return c;
}
void __cdecl FUN_00ac20d0(ElQ_acf7d0* _First, unsigned int _Count, const ElQ_acf7d0& _Val, AlQ_acf7d0& _Al, CatQ_acf7d0,
                          TagQ_acf7d0);
inline void UFillN_acf7d0(ElQ_acf7d0* _First, unsigned int _Count, const ElQ_acf7d0& _Val, AlQ_acf7d0& _Al)
{
    FUN_00ac20d0(_First, _Count, _Val, _Al, PtrCat_acf7d0(_First, _First), TagQ_acf7d0());
}
struct VecQ_acf7d0;
inline void Dead2_q()
{
    int a[2];
}
struct CItQ_acf7d0
{
    void* _Myaux;
    ElQ_acf7d0* _Myptr;
    CItQ_acf7d0()
    {}
    CItQ_acf7d0(ElQ_acf7d0* _Ptr, const VecQ_acf7d0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_acf7d0& r) const
    {
        return _Myaux == r._Myaux;
    }
    CItQ_acf7d0& FUN_00b23460(int _Off);
    int operator-(const CItQ_acf7d0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            ::FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct ItQ_acf7d0 : CItQ_acf7d0
{
    ItQ_acf7d0()
    {}
    ItQ_acf7d0(ElQ_acf7d0* _Ptr, const VecQ_acf7d0* _Pvector) : CItQ_acf7d0(_Ptr, _Pvector)
    {}
    ItQ_acf7d0& operator+=(int _Off)
    {
        FUN_00b23460(_Off);
        return *this;
    }
    ItQ_acf7d0 operator+(int _Off) const
    {
        ItQ_acf7d0 _Tmp = *this;
        Dead2_q();
        return (_Tmp += _Off);
    }
};
struct VecQ_acf7d0
{
    void* _Myownedaux;
    int m04;
    AlQ_acf7d0 _Alval;
    char p09[3];
    ElQ_acf7d0* _Myfirst;
    ElQ_acf7d0* _Mylast;
    ElQ_acf7d0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_acf7d0 begin()
    {
        return ItQ_acf7d0(_Myfirst, this);
    }
    void FUN_00b20360(CItQ_acf7d0 _Where, unsigned int _Count, const ElQ_acf7d0& _Val);
    ItQ_acf7d0 end()
    {
        return ItQ_acf7d0(_Mylast, this);
    }
    ElQ_acf7d0* _Ufill(ElQ_acf7d0* _Ptr, unsigned int _Count, const ElQ_acf7d0& _Val)
    {
        UFillN_acf7d0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_acf7d0 FUN_00b1e840(CItQ_acf7d0 _Where, const ElQ_acf7d0& _Val);
};
inline CItQ_acf7d0::CItQ_acf7d0(ElQ_acf7d0* _Ptr, const VecQ_acf7d0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        ::FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b1e840
ItQ_acf7d0 VecQ_acf7d0::FUN_00b1e840(CItQ_acf7d0 _Where, const ElQ_acf7d0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b20360(_Where, 1, _Val);
    return begin() + _Off;
}

typedef ElemX23520 ElQ_ab9bc0;
struct VecQ_ab9bc0;
struct CItQ_ab9bc0 : IteratorBaseAuxX23520
{
    ElQ_ab9bc0* _Myptr;
    CItQ_ab9bc0()
    {}
    CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const CItQ_ab9bc0& r) const
    {
        return _Myaux == r._Myaux;
    }
    CItQ_ab9bc0& FUN_00b23520(int _Off);
    int operator-(const CItQ_ab9bc0& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            ::FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct ItQ_ab9bc0 : CItQ_ab9bc0
{
    ItQ_ab9bc0()
    {}
    ItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : CItQ_ab9bc0(_Ptr, _Pvector)
    {}
    ItQ_ab9bc0& operator+=(int _Off)
    {
        FUN_00b23520(_Off);
        return *this;
    }
    ItQ_ab9bc0 operator+(int _Off) const
    {
        ItQ_ab9bc0 _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct VecQ_ab9bc0 : VectorX23520
{
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_ab9bc0 begin()
    {
        return ItQ_ab9bc0(_Myfirst, this);
    }
    void FUN_00b21560(CItQ_ab9bc0 _Where, unsigned int _Count, const ElQ_ab9bc0& _Val);
    ItQ_ab9bc0 end()
    {
        return ItQ_ab9bc0(_Mylast, this);
    }
    ItQ_ab9bc0 FUN_00b1f6d0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val);
};
inline CItQ_ab9bc0::CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector)
{
    _Myaux = 0;
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        ::FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
inline CItQ_ab9bc0& CItQ_ab9bc0::FUN_00b23520(int _Off)
{
    if (!_Has())
        ::FUN_00ec7c56();
    if (!(_Myptr + _Off <= ((VecQ_ab9bc0*)_Getmycont())->_Mylast &&
          _Myptr + _Off >= ((VecQ_ab9bc0*)_Getmycont())->_Myfirst))
        ::FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}
// @fnv 0x00b1f6d0
ItQ_ab9bc0 VecQ_ab9bc0::FUN_00b1f6d0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b21560(_Where, 1, _Val);
    return begin() + _Off;
}

struct PointInsertVector;
struct PointInsertConstIterator : dtorb181::GvIterBase
{
    FrondPoint* _Myptr;
    PointInsertConstIterator()
    {}
    PointInsertConstIterator(FrondPoint* _Ptr, const PointInsertVector* _Pvector);
    bool _Has() const
    {
        return _Myaux != 0;
    }
    bool _Same(const PointInsertConstIterator& r) const
    {
        return _Myaux == r._Myaux;
    }
    inline PointInsertConstIterator& FUN_00b235e0(int _Off);
    const PointInsertVector* _Container() const;
    int operator-(const PointInsertConstIterator& _Right) const
    {
        if (!(_Has() && _Same(_Right)))
            ::FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct PointInsertIterator : PointInsertConstIterator
{
    PointInsertIterator()
    {}
    PointInsertIterator(FrondPoint* _Ptr, const PointInsertVector* _Pvector) : PointInsertConstIterator(_Ptr, _Pvector)
    {}
    inline PointInsertIterator& operator+=(int _Off);
    PointInsertIterator operator+(int _Off) const
    {
        PointInsertIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct PointInsertVector : dtorb181::GvVectorVal<FrondPoint>
{
    FrondPoint* _Myfirst;
    FrondPoint* _Mylast;
    FrondPoint* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    PointInsertIterator begin()
    {
        return PointInsertIterator(_Myfirst, this);
    }
    void FUN_00b21e00(PointInsertConstIterator _Where, unsigned int _Count, const FrondPoint& _Val);
    PointInsertIterator FUN_00b1fab0(PointInsertConstIterator _Where, const FrondPoint& _Val);
};
inline PointInsertConstIterator::PointInsertConstIterator(FrondPoint* _Ptr, const PointInsertVector* _Pvector)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        ::FUN_00ec7c56();
    _Set_container(_Pvector);
    _Myptr = _Ptr;
}

inline const PointInsertVector* PointInsertConstIterator::_Container() const
{
    return (const PointInsertVector*)_Getmycont();
}
inline PointInsertConstIterator& PointInsertConstIterator::FUN_00b235e0(int _Off)
{
    if (!_Has())
        ::FUN_00ec7c56();
    if (!(_Myptr + _Off <= _Container()->_Mylast && _Myptr + _Off >= _Container()->_Myfirst))
        ::FUN_00ec7c56();
    _Myptr += _Off;
    return *this;
}

inline PointInsertIterator& PointInsertIterator::operator+=(int _Off)
{
    (*(PointInsertConstIterator*)this).FUN_00b235e0(_Off);
    return *this;
}
// @fnv 0x00b1fab0
PointInsertIterator PointInsertVector::FUN_00b1fab0(PointInsertConstIterator _Where, const FrondPoint& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b21e00(_Where, 1, _Val);
    return begin() + _Off;
}

struct Allocator
{
    typedef GlobalObject_00b3f100* pointer;
    inline void destroy(pointer _Ptr)
    {
        _Ptr->~GlobalObject_00b3f100();
    }
};
struct NonscalarTag
{
};
template <class T> inline NonscalarTag ptr_cat(T&, T&)
{
    NonscalarTag _Cat;
    return _Cat;
}
template <class A>
inline void destroy_range(typename A::pointer _First, typename A::pointer _Last, A& _Al, NonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void destroy_range(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    destroy_range(_First, _Last, _Al, ptr_cat(_First, _Last));
}

struct Vector;

struct IterBase
{
    void* m_pContainerProxy;
    IterBase() : m_pContainerProxy(0)
    {}
    bool _Has_container() const
    {
        return m_pContainerProxy != 0;
    }
    bool _Same_container(const IterBase& _Other) const
    {
        return m_pContainerProxy == _Other.m_pContainerProxy;
    }
    void _Set_container(const Vector* _Cont);
};
struct Ranit : IterBase
{
};
struct ConstIterator : Ranit
{
    GlobalObject_00b3f100* _Myptr;
    ConstIterator()
    {
        _Myptr = 0;
    }
    ConstIterator(GlobalObject_00b3f100* _Ptr, const Vector* _Cont);
    bool operator==(const ConstIterator& _Right) const
    {
        {
            if (!(_Has_container() && _Same_container(_Right)))
            {
                {
                    ::FUN_00ec7c56();
                }
            }
        }
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const ConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
};
struct Iterator : ConstIterator
{
    Iterator()
    {}
    Iterator(GlobalObject_00b3f100* _Ptr, const Vector* _Cont) : ConstIterator(_Ptr, _Cont)
    {}
};

struct Vector
{
    void* m_pContainerProxy;
    int unk04;
    int unk08;
    GlobalObject_00b3f100* _Myfirst;
    GlobalObject_00b3f100* _Mylast;
    GlobalObject_00b3f100* _Myend;

    Iterator _Make_iter(ConstIterator _Where) const
    {
        return Iterator(_Where._Myptr, this);
    }
    void _Destroy(GlobalObject_00b3f100* _First, GlobalObject_00b3f100* _Last)
    {
        destroy_range(_First, _Last, _Alval);
    }
    Allocator _Alval;
    Iterator FUN_00b1ffd0(ConstIterator _First_arg, ConstIterator _Last_arg);
};

inline void IterBase::_Set_container(const Vector* _Cont)
{
    m_pContainerProxy = _Cont->m_pContainerProxy;
}
inline ConstIterator::ConstIterator(GlobalObject_00b3f100* _Ptr, const Vector* _Cont)
{
    {
        if (!(_Cont != 0 && _Cont->_Myfirst <= _Ptr && _Ptr <= _Cont->_Mylast))
        {
            {
                ::FUN_00ec7c56();
            }
        }
    }
    _Set_container(_Cont);
    _Myptr = _Ptr;
}

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
struct CheckedTag
{
};
struct UnchangedTag
{
};
template <class T> inline T checked_base(T& _It, UnchangedTag)
{
    return _It;
}
template <class T> inline T checked_base(T& _It)
{
    UnchangedTag _Base_tag;
    return checked_base(_It, _Base_tag);
}
template <class T> inline RandomTag iter_random(const T&, const T&)
{
    RandomTag _Cat;
    return _Cat;
}
template <class In, class Out, class Cat>
inline Out copy_opt(In _First, In _Last, Out _Dest, Cat, NonscalarTag, CheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return _Dest;
}
template <class In, class Out> inline Out copy_opt(In _First, In _Last, Out _Dest, RandomTag, NonscalarTag, CheckedTag)
{
    Out _Result = _Dest + (_Last - _First);
    copy_opt(_First, _Last, checked_base(_Dest), ForwardTag(), NonscalarTag(), CheckedTag());
    return _Result;
}
template <class In, class Out> inline Out __cdecl FUN_00b236a0(In _First, In _Last, Out _Dest)
{
    return copy_opt(checked_base(_First), checked_base(_Last), _Dest, iter_random(_First, _Dest),
                    ptr_cat(_First, _Dest), CheckedTag());
}

// @fnv 0x00b1ffd0
Iterator Vector::FUN_00b1ffd0(ConstIterator _First_arg, ConstIterator _Last_arg)
{
    Iterator _First = _Make_iter(_First_arg);
    Iterator _Last = _Make_iter(_Last_arg);
    if (_First != _Last)
    {
        GlobalObject_00b3f100* _Ptr = FUN_00b236a0(_Last._Myptr, _Mylast, _First._Myptr);
        _Destroy(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return _First;
}

void __cdecl FormHeap_Free(void* p);

struct AuxCont_b189f0
{
    const void* _Mycont;
};

struct AllocQ_b189f0
{
    void destroy(AuxCont_b189f0* p)
    {
        p->~AuxCont_b189f0();
    }
    void deallocate(AuxCont_b189f0* p, unsigned int)
    {
        FormHeap_Free(p);
    }
};

struct AuxAlloc_b189f0
{  // VC9 _Container_base_aux_alloc_real
    AuxCont_b189f0* _Myownedaux;
    AllocQ_b189f0 _Alaux;
    ~AuxAlloc_b189f0()
    {
        int unused[8];
        _Alaux.destroy(_Myownedaux);
        _Alaux.deallocate(_Myownedaux, 1);
    }
};

struct FUN_00b189f0 : AuxAlloc_b189f0
{  // the list itself
    void* _Myhead;
    unsigned int _Mysize;
    void FUN_00b1e970();  // _Tidy
    ~FUN_00b189f0();
};

// @fnv 0x00b189f0
FUN_00b189f0::~FUN_00b189f0()
{
    FUN_00b1e970();
}

extern "C" void* __cdecl FUN_0044d670(unsigned int, int);

extern double FUN_00ec9f30(double);
extern double FUN_00eca060(double);
struct FloatMatrix3;
struct Vector3
{
    float x, y, z;
    Vector3 FUN_00b12890(const FloatMatrix3&) const;
    Vector3 AddVector(const Vector3&) const;
    Vector3 ScaleSwizzled(float) const;
    Vector3 FUN_00b12810(const Vector3&) const;
    void FUN_00b12790();
};
struct FloatMatrix3
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void FUN_00b12af0();
    FloatMatrix3 Multiply(const FloatMatrix3&) const;
    void FUN_00b1ae00(float angle)
    {
        FloatMatrix3 rotation;
        rotation.FUN_00b12af0();
        float cosine = (float)FUN_00ec9f30(angle / DAT_010a4d90);
        float sine = (float)FUN_00eca060(angle / DAT_010a4d90);
        rotation.xx = 1.0f;
        rotation.xy = 0.0f;
        rotation.xz = 0.0f;
        rotation.yx = 0.0f;
        rotation.yy = cosine;
        rotation.yz = sine;
        rotation.zx = 0.0f;
        rotation.zy = -sine;
        rotation.zz = cosine;
        *this = rotation.Multiply(*this);
    }
};
struct FUN_00b39460
{
    ~FUN_00b39460();
};
struct FUN_00b1fca0
{
    int allocator, allocationFlags, growth;
    Vector3* first;
    Vector3* last;
    Vector3* limit;
    ~FUN_00b1fca0();
    unsigned int size() const
    {
        return last - first;
    }
    Vector3& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                {
                    ::FUN_00ec7c56();
                }
            }
        }
        return first[_Pos];
    }
};
struct FUN_00b1e3e0 : FUN_00b39460, FUN_00b1fca0
{
    void FUN_00b1fbe0(unsigned int);
    FUN_00b1e3e0()
    {
        void** allocated = (void**)FUN_0044d670(1, 0);
        void** proxy = allocated;
        allocator = (int)(proxy ? (*proxy = this, proxy) : 0);
        FUN_00b1fbe0(0);
    }
};
struct FUN_00449fd0 : FrondFloatStorage
{
    FUN_00449fd0();
    ~FUN_00449fd0()
    {
        ((FrondFloatList*)this)->FUN_0065f240();
    }
    void PushBack(const float&);
    float* FUN_006578b0(unsigned int);
};
struct FUN_00b1fe80
{
    int allocator, allocationFlags, growth;
    FUN_00449fd0* first;
    FUN_00449fd0* last;
    FUN_00449fd0* limit;
    ~FUN_00b1fe80();
};
struct FUN_00b31270 : FUN_00b39460, FUN_00b1fe80
{
    FUN_00b31270();
    void FUN_00b1e640(const FUN_00449fd0&);
    FUN_00449fd0& FUN_00b319a0(unsigned int);
};
struct Color4
{
    float r, g, b, a;
};
struct TexCoord
{
    float u, v;
};
struct PackedColors
{
    int allocator, allocationFlags, growth;
    unsigned int* first;
    unsigned int* last;
    unsigned int* limit;
    void FUN_00b32210(const unsigned int&);
};
struct Geometry
{
    int vertexData, vertexFlags;
    unsigned char hasWind;
    unsigned char renderFlags;
    unsigned short material;
    int indexData, normalData, colorData, textureData, windData;
    unsigned short indexCount, vertex;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    PackedColors colors;
    FUN_00449fd0 positions;
    FUN_00449fd0 windPositions;
    void FUN_00b300c0(const Vector3& point)
    {
        float px = point.x;
        float py = point.y;
        float pz = point.z;
        positions.PushBack(px);
        positions.PushBack(py);
        positions.PushBack(pz);
        if (hasWind && colorData == 1)
        {
            windPositions.PushBack(px);
            windPositions.PushBack(py);
            windPositions.PushBack(pz);
        }
    }
    void FUN_00b301f0(const TexCoord&, unsigned short);
    unsigned int FUN_00b30060(const Color4& color)
    {
        return (unsigned int)(color.r * 255.0) + ((unsigned int)(color.g * 255.0) << 8) +
               ((unsigned int)(color.b * 255.0) << 16) - 0x1000000;
    }
    void FUN_00b30020(const Color4& color)
    {
        unsigned int packed = FUN_00b30060(color);
        colors.FUN_00b32210(packed);
    }
    void FUN_00b30190(const Vector3&);
    void FUN_00b305f0(const Vector3&);
    void FUN_00b30660(const Vector3&);
    void FUN_00b30560(float, unsigned char);
    float* FUN_00b30f80(unsigned int);
    float* FUN_00b30fd0(unsigned int);
    unsigned short GetVertex() const
    {
        return vertex;
    }
    unsigned char HasWind() const
    {
        return hasWind;
    }
    void AdvanceVertex()
    {
        ++vertex;
    }
    void SelectVertex(unsigned short selected)
    {
        vertex = selected;
    }
};
struct DistancePoint : FUN_00b1ada0_class
{
    float FUN_00b04d40(const DistancePoint&) const;
};
struct B1FrondBuilder
{
    Geometry* geometry;
    void* configuration;
    void FUN_00b1be50(FrondInput*, FUN_00b1e3e0&, FUN_00b1e3e0&);
    void FUN_00b1b000(FrondInput* frond);
};
// @fnv 0x00b1b000
void B1FrondBuilder::FUN_00b1b000(FrondInput* frond)
{
    if (geometry && configuration)
    {
        FUN_00b1e3e0 positions3;
        FUN_00b1e3e0 normals;
        FUN_00b1be50(frond, positions3, normals);
        frond->stride = positions3.size();
        frond->start = geometry->GetVertex();
        for (unsigned int guide = 0; guide < frond->size(); ++guide)
        {
            float along = guide / (frond->size() - 1.0);
            for (unsigned int vertex = 0; vertex < frond->stride; ++vertex)
            {
                float across_2 = vertex / (frond->stride - 1.0);
                FloatMatrix3 current2X = (*(FloatMatrix3*)&(*frond)[guide].rotation);
                FloatMatrix3 previousA = guide ? (*(FloatMatrix3*)&(*frond)[guide - 1].rotation) : current2X;
                current2X.FUN_00b1ae00(frond->angle);
                previousA.FUN_00b1ae00(frond->angle);
                Vector3 point7 = positions3[vertex].FUN_00b12890(current2X);
                Vector3 priority_2 = positions3[vertex].FUN_00b12890(previousA);
                Vector3 midPoint =
                    (*(Vector3*)&(*frond)[guide]).AddVector(point7.AddVector(priority_2).ScaleSwizzled(0.5f));
                Vector3 tangentsB = point7.AddVector(priority_2);
                tangentsB.FUN_00b12790();
                geometry->FUN_00b300c0(midPoint);
                TexCoord uvB;
                uvB.u = across_2;
                uvB.v = along;
                geometry->FUN_00b301f0(uvB, (unsigned short)frond->layer);
                Vector3 normal_0 = normals[vertex].FUN_00b12890(current2X);
                Vector3 priorNormal = normals[vertex].FUN_00b12890(previousA);
                Vector3 localA = normal_0.AddVector(priorNormal).ScaleSwizzled(0.5f);
                localA.FUN_00b12790();
                Color4 colorSlot5;
                colorSlot5.r = colorSlot5.g = colorSlot5.b = colorSlot5.a = 1.0f;
                geometry->FUN_00b30020(colorSlot5);
                geometry->FUN_00b30190(localA);
                geometry->FUN_00b305f0(tangentsB);
                Vector3 binormalVal = localA.FUN_00b12810(tangentsB);
                binormalVal.FUN_00b12790();
                geometry->FUN_00b30660(binormalVal);
                if (geometry->HasWind())
                    geometry->FUN_00b30560(frond->FUN_00b1db00(guide)->scale, frond->FUN_00b1db00(guide)->material);
                geometry->AdvanceVertex();
            }
        }
        FUN_00449fd0 local2;
        FUN_00b31270 cumulativeLengths;
        for (unsigned int column = 0; column < frond->stride; ++column)
        {
            float total = 0.0f;
            FUN_00449fd0 cumulative;
            cumulative.PushBack(0.0f);
            for (unsigned int row = 1; row < frond->size(); ++row)
            {
                unsigned int indexA6 = frond->start + row * frond->stride + column;
                unsigned int priorIndex8 = frond->start + (row - 1) * frond->stride + column;
                float* coordinates = geometry->FUN_00b30f80(indexA6);
                float* local7 = geometry->FUN_00b30f80(priorIndex8);
                DistancePoint point21;
                point21.FUN_00b1ada0(coordinates[0], coordinates[1], coordinates[2]);
                DistancePoint priorVal;
                priorVal.FUN_00b1ada0(local7[0], local7[1], local7[2]);
                total += point21.FUN_00b04d40(priorVal);
                cumulative.PushBack(total);
            }
            cumulativeLengths.FUN_00b1e640(cumulative);
            local2.PushBack(total);
        }
        for (unsigned int column = 0; column < frond->stride; ++column)
        {
            for (unsigned int row = 1; row < frond->size(); ++row)
            {
                unsigned short index4 = frond->start + row * frond->stride + column;
                geometry->SelectVertex(index4);
                float* original4 = geometry->FUN_00b30fd0(index4);
                TexCoord uv3;
                uv3.u = original4[0];
                static const float textureScale = 0.999f;
                uv3.v = *cumulativeLengths.FUN_00b319a0(column).FUN_006578b0(row) / *local2.FUN_006578b0(column) *
                        textureScale;
                geometry->FUN_00b301f0(uv3, (unsigned short)frond->layer);
                geometry->AdvanceVertex();
            }
        }
    }
}

struct TreeElemQ
{
    int a, b, c, d, e, f;
};
struct VecTE_00b1d130
{
    int x0, x1, x2, x3, x4, x5;
    VecTE_00b1d130& FUN_00b1d130(const VecTE_00b1d130& that);
};
struct VecPI_00b1d5d0
{
    int x0, x1, x2, x3, x4, x5;
    VecPI_00b1d5d0& FUN_00b1d5d0(const VecPI_00b1d5d0& that);
};
static __forceinline void DeadN()
{
    int aiD[102];
}
struct FUN_00b1c7a0_cls
{
    float f00;
    float f04;
    float f08;
    VecTE_00b1d130 m0c;
    VecTE_00b1d130 m24;
    VecPI_00b1d5d0 m3c;
    VecTE_00b1d130 m54;
    VecTE_00b1d130 m6c;
    FUN_00b1c7a0_cls& FUN_00b1c7a0(const FUN_00b1c7a0_cls& that);
};

// @fnv 0x00b1c7a0
FUN_00b1c7a0_cls& FUN_00b1c7a0_cls::FUN_00b1c7a0(const FUN_00b1c7a0_cls& that)
{
    DeadN();
    f00 = that.f00;
    f04 = that.f04;
    f08 = that.f08;
    m0c.FUN_00b1d130(that.m0c);
    m24.FUN_00b1d130(that.m24);
    m3c.FUN_00b1d5d0(that.m3c);
    m54.FUN_00b1d130(that.m54);
    m6c.FUN_00b1d130(that.m6c);
    return *this;
}

namespace frondlod {
struct GlobalObject_00b3f100
{
    GlobalObject_00b3f100();
    ~GlobalObject_00b3f100();
    float FUN_00b3f130(float, float);
};
typedef SFrondGuideEntry Entry;
template <class T> struct LodIterator : dtorb181::GvConstIterator<T>
{
    typedef dtorb181::GvConstIterator<T> Base;
    LodIterator(T* ptr, const dtorb181::GvContainer* cont) : Base(ptr, cont)
    {}
    LodIterator& operator+=(int n)
    {
        (*(Base*)this) += n;
        return *this;
    }
    LodIterator operator+(int n) const
    {
        LodIterator tmp = *this;
        return tmp += n;
    }
    int operator-(const Base& right) const
    {
        return *(Base*)this - right;
    }
    T* raw() const
    {
        return this->_Myptr;
    }
};
typedef LodIterator<Entry> Iter;
typedef dtorb181::GvConstIterator<Entry> ConstIter;
template <class T> struct LodAuxBase : dtorb181::GvContainer
{
    dtorb181::GvAlloc<dtorb181::GvAuxCont> _Alaux;
    explicit LodAuxBase(dtorb181::GvAlloc<T> al) : _Alaux(al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) dtorb181::GvAuxCont(this);
    }
    __declspec(noinline) ~LodAuxBase()
    {
        dtorb181::GvAuxCont* owned = _Myownedaux;
        owned->~GvAuxCont();
        _Alaux.deallocate(owned, 1);
    }
};
template <class T> struct LodVectorVal : LodAuxBase<T>
{
    dtorb181::GvAlloc<T> _Alval;
    LodVectorVal(dtorb181::GvAlloc<T> al = dtorb181::GvAlloc<T>()) : LodAuxBase<T>(al), _Alval(al)
    {}
};
template <class T> struct LodVector : LodVectorVal<T>
{
    typedef LodIterator<T> iterator;
    typedef dtorb181::GvConstIterator<T> const_iterator;
    T *_Myfirst, *_Mylast, *_Myend;
    LodVector() : LodVectorVal<T>()
    {
        _Buy(0);
    }
    ~LodVector()
    {
        _Tidy();
    }
    unsigned size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned max_size() const
    {
        return this->_Alval.max_size();
    }
    T& operator[](unsigned pos)
    {
        if (!(pos < size()))
            ::FUN_00ec7c56();
        return _Myfirst[pos];
    }
    iterator begin()
    {
        return iterator(_Myfirst, this);
    }
    iterator end()
    {
        return iterator(_Mylast, this);
    }
    iterator _Make_iter(const_iterator where) const
    {
        return iterator(where._Myptr, this);
    }
    bool _Buy(unsigned n)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (n == 0)
            return false;
        else if (max_size() < n)
            _Xlen();
        else
        {
            _Myfirst = this->_Alval.allocate(n);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + n;
        }
        return true;
    }
    static void _Xlen();
    void _Destroy(T* first, T* last)
    {
        dtorb181::GvDestroyRange(first, last, this->_Alval);
    }
    void _Tidy()
    {
        T* last = _Mylast;
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, last);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* ptr, unsigned n, const T& val)
    {
        dtorb181::GvUncheckedFillN(ptr, n, val, this->_Alval);
        return ptr + n;
    }
    void _Insert_n(const_iterator where, unsigned n, const T& val);
    iterator insert(const_iterator where, const T& val)
    {
        unsigned off = size() == 0 ? 0 : where - begin();
        _Insert_n(where, 1, val);
        return begin() + off;
    }
    void push_back(const T& val)
    {
        if (size() < capacity())
            _Mylast = _Ufill(_Mylast, 1, val);
        else
            insert(end(), val);
    }
    iterator erase(const_iterator where)
    {
        T* first = where._Myptr;
        dtorb181::GvUncheckedCopy(first + 1, _Mylast, first);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return _Make_iter(where);
    }
};
typedef LodVector<Entry> Vector;
typedef LodVector<Vector> OutputVector;
struct Compare
{
    bool operator()(const Entry& a, const Entry& b) const
    {
        return a.f2c > b.f2c;
    }
};
struct BaseTag
{
};
__forceinline Entry* checkedBase(Iter& it, BaseTag)
{
    return it.raw();
}
__forceinline Entry* checkedBase(Iter& it)
{
    BaseTag tag;
    return checkedBase(it, tag);
}
void __cdecl FUN_00b23cd0(Entry*, Entry*, int, Compare);
__forceinline void sortRange(Iter first, Iter last, Compare comp)
{
    FUN_00b23cd0(checkedBase(first), checkedBase(last), last - first, comp);
}
__forceinline float interpolate(float start, float end, float ratio)
{
    return start + (end - start) * ratio;
}
struct Processor
{
    int i0, i4;
    Vector entries;
    OutputVector output;
    int i38, i3c, i40, i44, i48, i4c, i50, i54, i58, i5c, i60, i64;
    unsigned count;
    float low, high, randomness, cutoff;
    void FUN_00b1c850();
};

// @fnv 0x00b1c850
void Processor::FUN_00b1c850()
{
    float sum;
    sum = 0.0f;
    float fraction;
    fraction = 0.0f;
    for (unsigned i = 0; i < entries.size(); ++i)
    {
        sum += entries[i].f28;
        if (entries[i].f28 > fraction)
            fraction = entries[i].f28;
    }
    float kIter;
    kIter = fraction * fraction;
    GlobalObject_00b3f100 threshold;
    float maximum;
    maximum = 1.0f - cutoff;
    Vector tmp;
    for (unsigned j = 0; j < entries.size(); ++j)
    {
        float s;
        s = entries[j].f28;
        if (s > fraction * maximum)
        {
            tmp.push_back(entries[j]);
            entries.erase(entries.begin() + j);
            --j;
        }
        else
        {
            float removed;
            removed = threshold.FUN_00b3f130(0.0f, randomness);
            float v;
            v = 1.0f - removed;
            s = v * s + removed * kIter;
            entries[j].f2c = s;
        }
    }
    sortRange(entries.begin(), entries.end(), Compare());
    sortRange(tmp.begin(), tmp.end(), Compare());
    for (unsigned k = 0; k < tmp.size(); ++k)
        entries.insert(entries.begin(), tmp[k]);
    for (unsigned level = 0; level < count; ++level)
    {
        float rng;
        if (count == 1)
            rng = low;
        else
            rng = interpolate(low, high, (float)level / (float)(count - 1));
        float inverse;
        inverse = rng * sum;
        float n;
        n = 0.0f;
        Vector square;
        if (inverse > 0.0)
        {
            for (unsigned m = 0; m < entries.size() && n <= inverse; ++m)
            {
                n += entries[m].f28;
                square.push_back(entries[m]);
            }
        }
        output.push_back(square);
    }
}

}

namespace fnv_00b1d980 {
typedef dtorb181::GvElemV AppendGuide;
typedef dtorb181::GvConstIterator<AppendGuide> AppendConstIterator;
typedef dtorb181::GvIterator<AppendGuide> AppendIterator;
typedef dtorb181::GvAlloc<AppendGuide> AppendAllocator;
void __cdecl CopyObjects(AppendGuide*, unsigned int, const AppendGuide&, AppendAllocator&, dtorb181::GvNonscalarTag,
                          dtorb181::GvRangeCheckedTag);
inline void AppendFill(AppendGuide* first, unsigned int count, const AppendGuide& value, AppendAllocator& allocator)
{
    CopyObjects(first, count, value, allocator, dtorb181::GvPtrCat(first, first), dtorb181::GvRangeCheckedTag());
}
struct AppendGuideVector : dtorb181::GvVector<AppendGuide>
{
    AppendGuide* _Ufill(AppendGuide* ptr, unsigned int count, const AppendGuide& value)
    {
        AppendFill(ptr, count, value, this->_Alval);
        return ptr + count;
    }
    AppendIterator FUN_00b1e840(AppendConstIterator where, const AppendGuide& value)
    {
        unsigned int offset = size() == 0 ? 0 : where - begin();
        _Insert_n(where, 1, value);
        return begin() + offset;
    }
    void FUN_00b1d980(const AppendGuide& value);
};
// @fnv 0x00b1d980
void AppendGuideVector::FUN_00b1d980(const AppendGuide& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        FUN_00b1e840(end(), value);
}
}  // namespace fnv_00b1d980

struct FrondInsertIterator : dtorb181::GvConstIterator<ElemX23460>
{
    FrondInsertIterator(ElemX23460* ptr, const dtorb181::GvContainer* container)
        : dtorb181::GvConstIterator<ElemX23460>(ptr, container)
    {}

    FrondInsertIterator& FUN_00b23460(int offset)
    {
        if (!this->_Has_container())
            ::FUN_00ec7c56();
        if (!(_Myptr + offset <= ((dtorb181::GvVector<ElemX23460>*)this->_Getmycont())->_Mylast &&
              _Myptr + offset >= ((dtorb181::GvVector<ElemX23460>*)this->_Getmycont())->_Myfirst))
            ::FUN_00ec7c56();
        _Myptr += offset;
        return *this;
    }

    FrondInsertIterator& operator+=(int offset)
    {
        FUN_00b23460(offset);
        return *this;
    }

    FrondInsertIterator operator+(int offset) const
    {
        FrondInsertIterator result = *this;
        return result += offset;
    }
};

struct FrondInsertVector : dtorb181::GvVector<ElemX23460>
{
    FrondInsertIterator begin()
    {
        return FrondInsertIterator(_Myfirst, this);
    }
    void FUN_00b1ecf0(dtorb181::GvConstIterator<ElemX23460> where, unsigned int count, const ElemX23460& value);
    FrondInsertIterator FUN_00b1dc50(dtorb181::GvConstIterator<ElemX23460> where, const ElemX23460& value);
};

// @fnv 0x00b1dc50
FrondInsertIterator FrondInsertVector::FUN_00b1dc50(dtorb181::GvConstIterator<ElemX23460> where,
                                                    const ElemX23460& value)
{
    unsigned int offset = size() == 0 ? 0 : where - begin();
    FUN_00b1ecf0(where, 1, value);
    return begin() + offset;
}

struct Item_b1de20;

struct PxB1de20;
struct CtB1de20
{
    PxB1de20* _Myownedaux;
};
struct PxB1de20
{
    const CtB1de20* _Mycontainer;
    const CtB1de20* _Getmycont() const
    {
        return _Mycontainer;
    }
};
struct VecB1de20;
struct ItBaseB1de20
{
    PxB1de20* _Myaux;
    ItBaseB1de20() : _Myaux(0)
    {}
    void _Set_container(const CtB1de20* _Pvector)
    {
        _Myaux = _Pvector->_Myownedaux;
    }
};
struct ItCB1de20 : ItBaseB1de20
{
    Item_b1de20** _Myptr;
    inline ItCB1de20(Item_b1de20** _Ptr, const CtB1de20* _Pvector);
};
struct ItB1de20 : ItCB1de20
{
    ItB1de20(Item_b1de20** _Ptr, const CtB1de20* _Pvector) : ItCB1de20(_Ptr, _Pvector)
    {}
};
struct VecB1de20 : CtB1de20
{
    int _Alaux;
    int _Alval;
    Item_b1de20** _Myfirst;
    Item_b1de20** _Mylast;
    Item_b1de20** _Myend;
    ItB1de20 begin()
    {
        return ItB1de20(_Myfirst, this);
    }
    ItB1de20 end()
    {
        return ItB1de20(_Mylast, this);
    }
    ItB1de20 FUN_00b1ea20(ItCB1de20 _First, ItCB1de20 _Last);
    void FUN_00b1de20();
};
inline ItCB1de20::ItCB1de20(Item_b1de20** _Ptr, const CtB1de20* _Pvector)
{
    if (!(_Pvector != 0 && ((VecB1de20*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((VecB1de20*)_Pvector)->_Mylast))
        ::FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}

inline void ScratchFrame_b1de20()
{
    int unused[30];
}

// @fnv 0x00b1de20
void VecB1de20::FUN_00b1de20()
{
    FUN_00b1ea20(begin(), end());
    ScratchFrame_b1de20();
}

namespace fnv_00b1e1e0 {
struct ElQ_ab9bc0
{
    int m[11];
};
struct AlQ_ab9bc0
{
};
struct CatQ_ab9bc0
{
};
struct TagQ_ab9bc0
{
};
struct ElQ_ab9bc0;
inline CatQ_ab9bc0 PtrCat_ab9bc0(ElQ_ab9bc0*&, ElQ_ab9bc0*&)
{
    CatQ_ab9bc0 c;
    return c;
}
void __cdecl FUN_00b243a0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al, CatQ_ab9bc0,
                          TagQ_ab9bc0);
inline void UFillN_ab9bc0(ElQ_ab9bc0* _First, unsigned int _Count, const ElQ_ab9bc0& _Val, AlQ_ab9bc0& _Al)
{
    FUN_00b243a0(_First, _Count, _Val, _Al, PtrCat_ab9bc0(_First, _First), TagQ_ab9bc0());
}
struct VecQ_ab9bc0;
struct CItQ_ab9bc0
{
    void* _Myaux;
    ElQ_ab9bc0* _Myptr;
    CItQ_ab9bc0()
    {}
    CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector);
};
struct ItQ_ab9bc0 : CItQ_ab9bc0
{
    ItQ_ab9bc0()
    {}
    ItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : CItQ_ab9bc0(_Ptr, _Pvector)
    {}
};
struct VecQ_ab9bc0
{
    void* _Myownedaux;
    int m04;
    AlQ_ab9bc0 _Alval;
    char p09[3];
    ElQ_ab9bc0* _Myfirst;
    ElQ_ab9bc0* _Mylast;
    ElQ_ab9bc0* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_ab9bc0 end()
    {
        return ItQ_ab9bc0(_Mylast, this);
    }
    ElQ_ab9bc0* _Ufill(ElQ_ab9bc0* _Ptr, unsigned int _Count, const ElQ_ab9bc0& _Val)
    {
        UFillN_ab9bc0(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_ab9bc0 FUN_00b1f6d0(CItQ_ab9bc0 _Where, const ElQ_ab9bc0& _Val);
    void FUN_00b1e1e0(const ElQ_ab9bc0& _Val);
};
inline CItQ_ab9bc0::CItQ_ab9bc0(ElQ_ab9bc0* _Ptr, const VecQ_ab9bc0* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        ::FUN_00ec7c56();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
inline void Dead12_ab9bc0()
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
}
// @fnv 0x00b1e1e0
void VecQ_ab9bc0::FUN_00b1e1e0(const ElQ_ab9bc0& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        FUN_00b1f6d0(end(), _Val);
        Dead12_ab9bc0();
    }
}
}  // namespace fnv_00b1e1e0

struct AppendElement
{
    int value00, value04, value08, value0c, value10, value14;
};
void __cdecl FUN_00b24580(AppendElement*, unsigned int, const AppendElement&, dtorb181::GvAlloc<AppendElement>&,
                          dtorb181::GvNonscalarTag, dtorb181::GvRangeCheckedTag);
inline void AppendFill(AppendElement* first, unsigned int count, const AppendElement& value,
                       dtorb181::GvAlloc<AppendElement>& allocator)
{
    FUN_00b24580(first, count, value, allocator, dtorb181::GvPtrCat(first, first), dtorb181::GvRangeCheckedTag());
}
struct AppendVector : dtorb181::GvVector<AppendElement>
{
    AppendElement* _Ufill(AppendElement* first, unsigned int count, const AppendElement& value)
    {
        AppendFill(first, count, value, _Alval);
        return first + count;
    }
    dtorb181::GvIterator<AppendElement> FUN_00b1fd50(dtorb181::GvConstIterator<AppendElement> where,
                                                     const AppendElement& value)
    {
        unsigned int offset = size() == 0 ? 0 : where - begin();
        _Insert_n(where, 1, value);
        return begin() + offset;
    }
    void FUN_00b1e640(const AppendElement& value);
};
// @fnv 0x00b1e640
void AppendVector::FUN_00b1e640(const AppendElement& value)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, value);
    else
        FUN_00b1fd50(end(), value);
}

SFrondGuideEntry* __cdecl FUN_00b23760(SFrondGuideEntry* _First, SFrondGuideEntry* _Last, SFrondGuideEntry* _Dest);

class IterQ_b16830 : public _Vector_iteratorS<SFrondGuideEntry>
{
  public:
    bool FUN_00b16830(const _Vector_const_iteratorS<SFrondGuideEntry>& _Right) const;
};

static __forceinline void DeadQ()
{
    int aiD[25];
}

struct Vector_b1ea20 : vectorS<SFrondGuideEntry>
{
    iterator FUN_00b1ea20(const_iterator _First_arg, const_iterator _Last_arg);
    void __thiscall FUN_00b1ebc0(SFrondGuideEntry* a, SFrondGuideEntry* b);
};

// @fnv 0x00b1ea20
Vector_b1ea20::iterator Vector_b1ea20::FUN_00b1ea20(const_iterator _First_arg, const_iterator _Last_arg)
{
    iterator _First = _Make_iter(_First_arg);
    DeadQ();
    iterator _Last = _Make_iter(_Last_arg);

    if (((IterQ_b16830*)&_First)->FUN_00b16830(_Last))
    {
        pointer _Ptr = FUN_00b23760(_Last._Myptr, _Mylast, _First._Myptr);
        FUN_00b1ebc0(_Ptr, _Mylast);
        _Mylast = _Ptr;
    }
    return (_First);
}

namespace fnv_00b1f460 {
struct FrondInsertVector;
struct FrondInsertConstIterator : dtorb181::GvIterBase
{
    ElemX16890* _Myptr;
    FrondInsertConstIterator()
    {}
    FrondInsertConstIterator(ElemX16890* _Ptr, const FrondInsertVector* _Pvector);
    FrondInsertConstIterator& FUN_00b16890(int _Off)
    {
        if (!this->_Has_container())
            ::FUN_00ec7c56();
        if (!(_Myptr + _Off <= ((const dtorb181::GvVector<ElemX16890>*)this->_Getmycont())->_Mylast &&
              _Myptr + _Off >= ((const dtorb181::GvVector<ElemX16890>*)this->_Getmycont())->_Myfirst))
            ::FUN_00ec7c56();
        _Myptr += _Off;
        return *this;
    }
    int operator-(const FrondInsertConstIterator& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            ::FUN_00ec7c56();
        return _Myptr - _Right._Myptr;
    }
};
struct FrondInsertIterator : FrondInsertConstIterator
{
    FrondInsertIterator()
    {}
    FrondInsertIterator(ElemX16890* _Ptr, const FrondInsertVector* _Pvector) : FrondInsertConstIterator(_Ptr, _Pvector)
    {}
    FrondInsertIterator& operator+=(int _Off)
    {
        FUN_00b16890(_Off);
        return *this;
    }
    FrondInsertIterator operator+(int _Off) const
    {
        FrondInsertIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
struct FrondInsertVector : dtorb181::GvVector<ElemX16890>
{
    FrondInsertIterator begin()
    {
        return FrondInsertIterator(_Myfirst, this);
    }
    void FUN_00b20ce0(FrondInsertConstIterator _Where, unsigned int _Count, const ElemX16890& _Val);
    FrondInsertIterator FUN_00b1f460(FrondInsertConstIterator _Where, const ElemX16890& _Val);
};
inline FrondInsertConstIterator::FrondInsertConstIterator(ElemX16890* _Ptr, const FrondInsertVector* _Pvector)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        ::FUN_00ec7c56();
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}
// @fnv 0x00b1f460
FrondInsertIterator FrondInsertVector::FUN_00b1f460(FrondInsertConstIterator _Where, const ElemX16890& _Val)
{
    unsigned int _Off = size() == 0 ? 0 : _Where - begin();
    FUN_00b20ce0(_Where, 1, _Val);
    return begin() + _Off;
}
}  // namespace fnv_00b1f460

struct InsertConstIterator24 : dtorb181::GvIterBase
{
    ElemX16890* _Myptr;
    InsertConstIterator24(ElemX16890* pointer, const dtorb181::GvContainer* container)
    {
        if (!(container != 0 && ((dtorb181::GvVector<ElemX16890>*)container)->_Myfirst <= pointer &&
              pointer <= ((dtorb181::GvVector<ElemX16890>*)container)->_Mylast))
            ::FUN_00ec7c56();
        _Set_container(container);
        _Myptr = pointer;
    }
    int operator-(const InsertConstIterator24& other) const
    {
        if (!(_Has_container() && _Same_container(other)))
            ::FUN_00ec7c56();
        return _Myptr - other._Myptr;
    }
    InsertConstIterator24& FUN_00b16890(int offset)
    {
        if (!_Has_container())
            ::FUN_00ec7c56();
        if (!(_Myptr + offset <= ((dtorb181::GvVector<ElemX16890>*)_Getmycont())->_Mylast &&
              _Myptr + offset >= ((dtorb181::GvVector<ElemX16890>*)_Getmycont())->_Myfirst))
            ::FUN_00ec7c56();
        _Myptr += offset;
        return *this;
    }
};
struct InsertIterator24 : InsertConstIterator24
{
    InsertIterator24(ElemX16890* pointer, const dtorb181::GvContainer* container)
        : InsertConstIterator24(pointer, container)
    {}
    InsertIterator24& operator+=(int offset)
    {
        (*(InsertConstIterator24*)this).FUN_00b16890(offset);
        return *this;
    }
    InsertIterator24 operator+(int offset) const
    {
        InsertIterator24 result = *this;
        return result += offset;
    }
};
struct InsertVector24 : dtorb181::GvVector<ElemX16890>
{
    InsertIterator24 begin()
    {
        return InsertIterator24(_Myfirst, this);
    }
    void FUN_00b22700(InsertConstIterator24 where, unsigned int count, const ElemX16890& value);
    InsertIterator24 FUN_00b1fd50(InsertConstIterator24 where, const ElemX16890& value);
};
// @fnv 0x00b1fd50
InsertIterator24 InsertVector24::FUN_00b1fd50(InsertConstIterator24 where, const ElemX16890& value)
{
    unsigned int offset = size() == 0 ? 0 : where - begin();
    FUN_00b22700(where, 1, value);
    return begin() + offset;
}

namespace rework_b200f0 {
void FUN_00ec7c56();
void __stdcall FUN_00ec7894(void*, void*);
struct ElQ_b200
{
    char b[0x38];
};
struct AlQ_b2002_b200
{
    AlQ_b2002_b200()
    {}
};
struct AlQ_b200
{
    AlQ_b200()
    {}
    AlQ_b200(const AlQ_b200&)
    {}
    AlQ_b200(const AlQ_b2002_b200& o)
    {
        const AlQ_b2002_b200* p = &o;
    }
};
inline AlQ_b200 MkAl_b200(const AlQ_b200& a)
{
    return a;
}
inline const AlQ_b200& Cp_b200(const AlQ_b200& a)
{
    return a;
}
struct TagQ_b200
{
};
struct CatQ_b200
{
};
struct FUN_00b200f0;
struct FUN_00b20ba0
{
    int m_iWordAt00;
    int m_iWordAt04;
    AlQ_b200 m_al;
    ElQ_b200* m_pHeadNode;
    ElQ_b200* m_last;
    ElQ_b200* m_kRayEnd;
    FUN_00b20ba0(AlQ_b200 al);
    ~FUN_00b20ba0();
};
struct ProxQ_b200
{
    FUN_00b200f0* p;
};
struct CItQ_b200
{
    ProxQ_b200* m_cont;
    ElQ_b200* m_ptr;
    CItQ_b200(ElQ_b200* p, const FUN_00b200f0* c);
};
ElQ_b200* __cdecl FUN_00b26db0(ElQ_b200* f, ElQ_b200* l, ElQ_b200* d, AlQ_b200& al, CatQ_b200 c, TagQ_b200 b);
inline void DeadA_b200()
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
    int a12;
    int a13;
    int a14;
    int a15;
    int a16;
    int a17;
    int a18;
    int a19;
    int a20;
}
inline void DeadB_b200()
{
    int b0;
    int b1;
    int b2;
    int b3;
    int b4;
    int b5;
    int b6;
    int b7;
}
inline void DeadM_b200()
{
    int m0;
}
inline CatQ_b200 PtrCat_b200(CItQ_b200&, ElQ_b200*&)
{
    CatQ_b200 c;
    return c;
}
inline ElQ_b200* CBase_b200(CItQ_b200& i)
{
    return i.m_ptr;
}
inline ElQ_b200* CBase_b200F_b200(CItQ_b200& i)
{
    int m0;
    return i.m_ptr;
}
struct MidQ_b200 : FUN_00b20ba0
{
    MidQ_b200(AlQ_b200 a) : FUN_00b20ba0(a)
    {}
};
struct FUN_00b200f0 : MidQ_b200
{
    FUN_00b200f0(const FUN_00b200f0& r);
    bool FUN_00b1eb00(unsigned int n);
    void FUN_00b1e970();
    unsigned int size() const
    {
        return m_last - m_pHeadNode;
    }
    CItQ_b200 begin() const
    {
        return CItQ_b200(m_pHeadNode, this);
    }
    CItQ_b200 end() const
    {
        return CItQ_b200(m_last, this);
    }
    ElQ_b200* UCopy_b200(CItQ_b200 f, CItQ_b200 l, ElQ_b200* d)
    {
        return UninitCopy_b200(f, l, d, m_al);
    }
    ElQ_b200* UninitCopy_b200(CItQ_b200 f, CItQ_b200 l, ElQ_b200* d, AlQ_b200& al)
    {
        return FUN_00b26db0(CBase_b200F_b200(f), CBase_b200(l), d, al, PtrCat_b200(f, d), TagQ_b200());
    }
};
inline CItQ_b200::CItQ_b200(ElQ_b200* p, const FUN_00b200f0* c)
{
    m_cont = 0;
    if (c == 0 || c->m_pHeadNode > p || p > c->m_last)
        FUN_00ec7c56();
    m_cont = *(ProxQ_b200**)c;
    m_ptr = p;
}
// @fnv 0x00b200f0
FUN_00b200f0::FUN_00b200f0(const FUN_00b200f0& r) : MidQ_b200(AlQ_b200())
{
    if (FUN_00b1eb00(r.size()))
    {
        DeadA_b200();
        try
        {
            m_last = UCopy_b200(r.begin(), r.end(), m_pHeadNode);
            DeadB_b200();
        }
        catch (...)
        {
            FUN_00b1e970();
            FUN_00ec7894(0, 0);
        }
    }
}

}

struct TagR
{
};
struct PtrCatR
{
};
struct VBR
{
    void* p;
    ~VBR();
};
struct ElR : VBR
{
    int i4;
    int i8;
    int* a;
    int* b;
    int* c;
    int pad[8];
    ElR(const ElR&);
    ~ElR();
};
struct AlR
{
    AlR()
    {}
    AlR(const AlR&)
    {}
};
ElR* __cdecl FUN_00b25fa0(ElR* f, ElR* l, ElR* d, AlR& al, PtrCatR, TagR);
struct AuxQ;
struct FUN_00b20ba0
{
    AuxQ* m_iWordAt00;
    int m_iWordAt04;
    AlR m_al;
    FUN_00b20ba0(AlR al);
    ~FUN_00b20ba0();
};
struct CItQ
{
    AuxQ* m_cont;
    const ElR* m_ptr;
    CItQ(const ElR* p, const FUN_00b20ba0* c)
    {
        m_cont = 0;
        if (c == 0 || ((ElR**)c)[3] > p || p > ((ElR**)c)[4])
            ::FUN_00ec7c56();
        m_cont = c->m_iWordAt00;
        m_ptr = p;
    }
};
inline const ElR* Checked_base(const CItQ& it)
{
    return it.m_ptr;
}
inline const ElR* Checked_base2(const CItQ& it)
{
    int iActionIndex;
    return it.m_ptr;
}
inline void Dead21Q()
{
    int a[21];
}
inline void Dead15Q()
{
    int a[15];
}
inline PtrCatR Ptr_cat(const CItQ&, ElR*&)
{
    PtrCatR c;
    return c;
}
inline ElR* Unchecked_uninitialized_copy(CItQ f, CItQ l, ElR* d, AlR& al)
{
    return FUN_00b25fa0((ElR*)Checked_base2(f), (ElR*)Checked_base(l), d, al, Ptr_cat(f, d), TagR());
}
struct MidQ : FUN_00b20ba0
{
    ElR* m_pHeadNode;
    ElR* m_last;
    ElR* m_kRayEnd;
    MidQ(AlR al) : FUN_00b20ba0(al)
    {}
    unsigned size() const
    {
        return m_last - m_pHeadNode;
    }
    CItQ begin() const
    {
        return CItQ(m_pHeadNode, this);
    }
    CItQ end() const
    {
        return CItQ(m_last, this);
    }
    ElR* _Ucopy(CItQ f, CItQ l, ElR* p)
    {
        return Unchecked_uninitialized_copy(f, l, p, m_al);
    }
    bool FUN_00b1eb00(unsigned n);
    void FUN_00b1ec70();
};
struct VecCopyR : MidQ
{
    VecCopyR(const VecCopyR& r);
};
// @fnv 0x00b231f0
VecCopyR::VecCopyR(const VecCopyR& r) : MidQ(AlR())
{
    if (FUN_00b1eb00(r.size()))
    {
        try
        {
            Dead21Q();
            m_last = _Ucopy(r.begin(), r.end(), m_pHeadNode);
            Dead15Q();
        }
        catch (...)
        {
            FUN_00b1ec70();
            throw;
        }
    }
}

struct VcElemQ
{
    void FUN_00b24a80(const VcElem* src);
};
__forceinline void P1Q()
{
    int a[1];
}
__forceinline void P2Q()
{
    int a[21];
}
__forceinline VcElem* CopyFwdQ(VcElem* _First, VcElem* _Last, VcElem* _Dest, VcForwardTag, VcNonscalarTag,
                               VcRangeCheckedTag)
{
    P2Q();
    for (; _First != _Last; ++_Dest, ++_First)
    {
        ((VcElemQ*)_Dest)->FUN_00b24a80(_First);
    }
    return _Dest;
}
__forceinline VcElem* CopyRandQ(VcElem* _First, VcElem* _Last, VcElem* _Dest, VcRandomTag, VcNonscalarTag,
                                VcRangeCheckedTag)
{
    VcElem* _Result = _Dest + (_Last - _First);
    CopyFwdQ(_First, _Last, _Dest, VcForwardTag(), VcNonscalarTag(), VcRangeCheckedTag());
    return _Result;
}
__forceinline VcElem* CbFirstQ(VcElem* const& _It)
{
    VcElem* _Base = _It;
    P1Q();
    return _Base;
}
// @fnv 0x00b23830
VcElem* FUN_00b23830(VcElem* _First, VcElem* _Last, VcElem* _Dest)
{
    return CopyRandQ(VcCheckedBase(_First), CbFirstQ(_Last), _Dest, VcIterRandom(_First, _Dest),
                     VcPtrCatC(_First, _Dest), VcRangeCheckedTag());
}

struct E93Q
{
    int m[6];
    void FUN_00b26570(E93Q& o);
};
struct NsTag93
{
};
struct FwdTag93
{
};
struct RandTag93 : FwdTag93
{
};
struct RcTag93
{
};
template <class I1, class I2> inline RandTag93 IterRandom93(const I1&, const I2&)
{
    RandTag93 c;
    return c;
}
template <class T1, class T2> inline NsTag93 PtrCat93(T1&, T2&)
{
    NsTag93 c;
    return c;
}
template <class I> inline I CheckedBase93(const I& it)
{
    I b = it;
    return b;
}
__forceinline void Dead64Q()
{
    int aiD[64];
}
__forceinline void Swap93(E93Q& a, E93Q& b)
{
    a.FUN_00b26570(b);
    Dead64Q();
}
__forceinline E93Q* MbFwd93(E93Q* F, E93Q* L, E93Q* D, FwdTag93)
{
    while (F != L)
    {
        --L;
        --D;
        Swap93(*D, *L);
    }
    return D;
}
__forceinline E93Q* MbRand93(E93Q* F, E93Q* L, E93Q* D, RandTag93, NsTag93, RcTag93)
{
    E93Q* R = D - (L - F);
    MbFwd93(F, L, D, FwdTag93());
    return R;
}
__forceinline void P1Q93()
{
    int a[1];
}
__forceinline E93Q* CbLast93(E93Q* const& it)
{
    E93Q* b = it;
    P1Q93();
    return b;
}
// @fnv 0x00b23c10
E93Q* FUN_00b23c10(E93Q* F, E93Q* L, E93Q* D)
{
    return MbRand93(CheckedBase93(F), CbLast93(L), D, IterRandom93(F, D), PtrCat93(F, D), RcTag93());
}

template <typename T> struct MyVector
{
    int unk00;
    int unk04;
    int unk08;
    T* m_pHeadNode;
    T* m_last;
    T* m_kRayEnd;

    __forceinline unsigned int size() const
    {
        return (m_last - m_pHeadNode);
    }

    __forceinline T& operator[](unsigned int idx)
    {
        if (idx >= size())
        {
            ::FUN_00ec7c56();
        }
        return m_pHeadNode[idx];
    }
};

struct FinalizerGuidePoint : FrondGuidePoint
{
    inline float FUN_00b04d40(const FrondPoint& other) const
    {
        union FloatBits
        {
            float f;
            int i;
        } squared, root;
        squared.f = (other.z - z) * (other.z - z) + ((other.y - y) * (other.y - y) + (other.x - x) * (other.x - x));
        root.i = (squared.i >> 1) + 0x1fc00000;
        return root.f;
    }
};

struct MyFrondGuide
{
    MyVector<FinalizerGuidePoint> m_kPoints;
    float f18;
    float f1c;
    unsigned char c20;
    float f24;
    float f28;
    float f2c;
    int i30;
    int i34;
};

struct Field50Item
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
};

struct FUN_00aa7830
{
    ~FUN_00aa7830();
};

struct FUN_00b3f100 : FUN_00aa7830
{
    FUN_00b3f100();
    float FUN_00b3f130(float a, float b);
    inline ~FUN_00b3f100()
    {}
};

struct FrondGuideFinalizer
{
    int unk00;
    int unk04;
    MyVector<MyFrondGuide> m_guides;
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
    MyVector<Field50Item> m_field50;

    void FUN_00b18b70(float a1);
};

// @fnv 0x00b18b70
void FrondGuideFinalizer::FUN_00b18b70(float a1)
{
    MyFrondGuide* guide = &m_guides[m_guides.size() - 1];
    unsigned int i;
    for (i = 0; i < guide->m_kPoints.size() - 1; ++i)
    {
        guide->f18 += guide->m_kPoints[i].FUN_00b04d40(guide->m_kPoints[i + 1]);
    }
    FUN_00b3f100 rng;
    if (m_field50.size() == 0)
    {
        m_guides[i].c20 = 0;
        guide->f1c = guide->f18 * 0.5;
        guide->f24 = 0.0f;
    }
    else
    {
        guide->c20 = (unsigned char)((unsigned int)rng.FUN_00b3f130(0.0f, 100000.0f) % m_field50.size());
        guide->f1c = guide->f18 * m_field50[guide->c20].f1c * 0.5;
        guide->f1c = guide->f1c * m_field50[guide->c20].f20;
        guide->f24 = rng.FUN_00b3f130(m_field50[guide->c20].f24, m_field50[guide->c20].f28);
        if (m_guides.size() % 2 == 1)
        {
            guide->f24 = guide->f24 * -1.0;
        }
    }
    guide->f28 = guide->f18 * a1;
}

namespace dtorb181 {
template <> struct GvPtrCatHelper<int*, int*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<GvConstIterator<int>, int*>
{
    typedef GvScalarTag _Ptr_cat;
};
struct CopyCheckedTag
{
};
inline const int* GvCheckedBase(GvConstIterator<int>& _It, CopyCheckedTag)
{
    return _It._Myptr;
}
inline const int* GvCheckedBase(GvConstIterator<int>& _It)
{
    CopyCheckedTag tag;
    return GvCheckedBase(_It, tag);
}

}
namespace VectorCopyRework {
struct AllocationError : std::exception
{
    explicit AllocationError(const char* message = 0) : std::exception(message)
    {}
    virtual ~AllocationError()
    {}
};
template <class T> inline T* AllocateElements(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(T))
        throw AllocationError(0);
    return (T*)operator new(count * sizeof(T));
}
template <class T> struct ValueAllocator
{
    typedef T* pointer;
    ValueAllocator() throw()
    {}
    ValueAllocator(const ValueAllocator&) throw()
    {}
    template <class O> ValueAllocator(const ValueAllocator<O>&) throw()
    {}
    pointer allocate(unsigned int count)
    {
        return AllocateElements(count, (pointer)0);
    }
    void deallocate(pointer ptr, unsigned int)
    {
        operator delete(ptr);
    }
    void construct(pointer ptr, const T& value)
    {
        dtorb181::GvConstruct(ptr, value);
    }
    void destroy(pointer ptr)
    {
        dtorb181::GvDestroyOne(ptr);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};

struct FUN_0065dc90 : dtorb181::GvContainer
{
    ValueAllocator<dtorb181::GvAuxCont> _Alaux;
    explicit FUN_0065dc90(ValueAllocator<int> _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) dtorb181::GvAuxCont(this);
    }
    ~FUN_0065dc90()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
inline int* __cdecl FUN_00b24960(dtorb181::GvConstIterator<int> _First, dtorb181::GvConstIterator<int> _Last,
                                 int* _Dest, ValueAllocator<int>& _Al)
{
    return dtorb181::GvUninitCopy(dtorb181::GvCheckedBase(_First), dtorb181::GvCheckedBase(_Last), _Dest, _Al,
                                  dtorb181::GvPtrCat(_First, _Dest), dtorb181::GvRangeCheckedTag());
}
struct VectorOperations : FUN_0065dc90
{
    ValueAllocator<int> _Alval;
    VectorOperations(ValueAllocator<int> _Al = ValueAllocator<int>()) : FUN_0065dc90(_Al), _Alval(_Al)
    {}
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int max_size() const
    {
        return _Alval.max_size();
    }
    static void _Xlen()
    {
        throw dtorb181::BxLengthError("vector<T> too long");
    }
    bool FUN_0044a240(unsigned int _Capacity)
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
    dtorb181::GvConstIterator<int> begin() const
    {
        return dtorb181::GvConstIterator<int>(_Myfirst, this);
    }
    dtorb181::GvConstIterator<int> end() const
    {
        return dtorb181::GvConstIterator<int>(_Mylast, this);
    }
    template <class I> int* _Ucopy(I _First, I _Last, int* _Ptr)
    {
        return FUN_00b24960(_First, _Last, _Ptr, _Alval);
    }
    void _Destroy(int* _First, int* _Last)
    {
        dtorb181::GvDestroyRange(_First, _Last, _Alval);
    }
    void FUN_0065f240()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            _Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
};
struct FUN_00b22ff0 : VectorOperations
{
    FUN_00b22ff0(const FUN_00b22ff0& _Right);
};
// @fnv 0x00b22ff0
FUN_00b22ff0::FUN_00b22ff0(const FUN_00b22ff0& _Right) : VectorOperations(_Right._Alval)
{
    if (FUN_0044a240(_Right.size()))
        try
        {
            _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
        }
        catch (...)
        {
            FUN_0065f240();
            throw;
        }
}
}

namespace FrondComputeCrt {
extern "C" unsigned __cdecl strlen(const char*);
}
void __cdecl operator delete(void*);
void* __cdecl operator new(unsigned);
namespace std {
template <class T> struct char_traits
{
    static unsigned length(const T* text)
    {
        return FrondComputeCrt::strlen(text);
    }
    static void assign(T& dest, const T& value)
    {
        dest = value;
    }
    static T* _Copy_s(T*, unsigned, const T*, unsigned);
    static T* _Move_s(T*, unsigned, const T*, unsigned);
};
template <class T> class allocator
{
  public:
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    void deallocate(T* ptr, unsigned)
    {
        ::operator delete(ptr);
    }
    T* allocate(unsigned count)
    {
        return (T*)::operator new(count * sizeof(T));
    }
    unsigned max_size() const throw()
    {
        unsigned count = unsigned(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
class StringErrorBase
{
  public:
    static void _Xlen();
    static void _Xran();
};
template <class T, class Alloc> class StringValue : public StringErrorBase
{
  protected:
    StringValue(Alloc al = Alloc()) : _Alval(al)
    {}

  public:
    StringValue(const StringValue& other) : _Alval(other._Alval)
    {}

  protected:
    Alloc _Alval;
};
template <class T, class Traits = char_traits<T>, class Alloc = allocator<T> >
class basic_string : public StringValue<T, Alloc>
{
    typedef StringValue<T, Alloc> Base;
    typedef basic_string<T, Traits, Alloc> Self;
    enum
    {
        BufferSize = 16 / sizeof(T) < 1 ? 1 : 16 / sizeof(T),
        AllocMask = sizeof(T) <= 1 ? 15 : sizeof(T) <= 2 ? 7 : sizeof(T) <= 4 ? 3 : sizeof(T) <= 8 ? 1 : 0
    };

  public:
    basic_string(const T* text) : Base()
    {
        _Tidy();
        assign(text);
    }
    basic_string(const Self& other) : Base(other)
    {
        _Tidy();
        assign(other, 0, unsigned(-1));
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    Self& assign(const T* text)
    {
        return assign(text, Traits::length(text));
    }
    Self& assign(const T* text, unsigned count)
    {
        if (_Inside(text))
            return assign(*this, text - _Myptr(), count);
        if (_Grow(count))
        {
            Traits::_Copy_s(_Myptr(), _Myres, text, count);
            _Eos(count);
        }
        return *this;
    }
    Self& assign(const Self& other, unsigned off, unsigned count)
    {
        if (other.size() < off)
            StringErrorBase::_Xran();
        unsigned num = other.size() - off;
        if (count < num)
            num = count;
        if (this == &other)
            erase(off + num), erase(0, off);
        else if (_Grow(num))
        {
            Traits::_Copy_s(_Myptr(), _Myres, other._Myptr() + off, num);
            _Eos(num);
        }
        return *this;
    }
    Self& erase(unsigned off = 0, unsigned count = unsigned(-1))
    {
        if (_Mysize < off)
            StringErrorBase::_Xran();
        if (_Mysize - off < count)
            count = _Mysize - off;
        if (0 < count)
        {
            Traits::_Move_s(_Myptr() + off, _Myres - off, _Myptr() + off + count, _Mysize - off - count);
            unsigned newsize = _Mysize - count;
            _Eos(newsize);
        }
        return *this;
    }
    Self& operator+=(const Self& other)
    {
        return append(other);
    }
    Self& operator+=(const T* text)
    {
        return append(text);
    }
    Self& append(const Self& other)
    {
        return append(other, 0, unsigned(-1));
    }
    Self& append(const Self& other, unsigned off, unsigned count)
    {
        if (other.size() < off)
            StringErrorBase::_Xran();
        unsigned num = other.size() - off;
        if (num < count)
            count = num;
        if (unsigned(-1) - _Mysize <= count || _Mysize + count < _Mysize)
            StringErrorBase::_Xlen();
        if (0 < count && _Grow(num = _Mysize + count))
        {
            Traits::_Copy_s(_Myptr() + _Mysize, _Myres - _Mysize, other._Myptr() + off, count);
            _Eos(num);
        }
        return *this;
    }
    Self& append(const T* text, unsigned count)
    {
        if (_Inside(text))
            return append(*this, text - _Myptr(), count);
        if (unsigned(-1) - _Mysize <= count || _Mysize + count < _Mysize)
            StringErrorBase::_Xlen();
        unsigned num;
        if (0 < count && _Grow(num = _Mysize + count))
        {
            Traits::_Copy_s(_Myptr() + _Mysize, _Myres - _Mysize, text, count);
            _Eos(num);
        }
        return *this;
    }
    Self& append(const T* text)
    {
        return append(text, Traits::length(text));
    }
    unsigned size() const
    {
        return _Mysize;
    }
    unsigned max_size() const
    {
        unsigned num = Base::_Alval.max_size();
        return num <= 1 ? 1 : num - 1;
    }
    void _Tidy(bool built = false, unsigned newsize = 0)
    {
        if (!built)
            ;
        else if (BufferSize <= _Myres)
        {
            T* ptr = _Bx.pointer;
            if (0 < newsize)
                Traits::_Copy_s(_Bx.buffer, BufferSize, ptr, newsize);
            Base::_Alval.deallocate(ptr, _Myres + 1);
        }
        _Myres = BufferSize - 1;
        _Eos(newsize);
    }

  private:
    void _Copy(unsigned newsize, unsigned oldlen)
    {
        unsigned newres = newsize | AllocMask;
        if (max_size() < newres)
            newres = newsize;
        else if (newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
            newres = _Myres + _Myres / 2;
        T* ptr = 0;
        try
        {
            ptr = Base::_Alval.allocate(newres + 1);
        }
        catch (...)
        {
            newres = newsize;
            try
            {
                ptr = Base::_Alval.allocate(newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < oldlen)
            Traits::_Copy_s(ptr, newres + 1, _Myptr(), oldlen);
        _Tidy(true);
        _Bx.pointer = ptr;
        _Myres = newres;
        _Eos(oldlen);
    }
    void _Eos(unsigned newsize)
    {
        Traits::assign(_Myptr()[_Mysize = newsize], T());
    }
    bool _Grow(unsigned newsize, bool trim = false)
    {
        if (max_size() < newsize)
            StringErrorBase::_Xlen();
        if (_Myres < newsize)
            _Copy(newsize, _Mysize);
        else if (trim && newsize < BufferSize)
            _Tidy(true, newsize < _Mysize ? newsize : _Mysize);
        else if (newsize == 0)
            _Eos(0);
        return 0 < newsize;
    }
    bool _Inside(const T* ptr)
    {
        if (ptr == 0 || ptr < _Myptr() || _Myptr() + _Mysize <= ptr)
            return false;
        else
            return true;
    }
    T* _Myptr()
    {
        return BufferSize <= _Myres ? _Bx.pointer : _Bx.buffer;
    }
    const T* _Myptr() const
    {
        return BufferSize <= _Myres ? _Bx.pointer : _Bx.buffer;
    }
    union Storage
    {
        T buffer[BufferSize];
        T* pointer;
    } _Bx;
    unsigned _Mysize, _Myres;
};
typedef basic_string<char> string;
class runtime_error : public ::dtorb181::BxException
{
    string _Str;

  public:
    runtime_error(const string& message) : _Str(message)
    {}
    runtime_error(const FUN_0044a4c0& message) : _Str(*(const string*)&message)
    {}
    virtual ~runtime_error()
    {}
    virtual const char* what() const;
};
}
int* __cdecl GetErrorNumber();
char* __cdecl GetErrorText(int);
namespace std {
template <class T, class Traits, class Alloc>
inline basic_string<T, Traits, Alloc> operator+(const basic_string<T, Traits, Alloc>& left, const T* right)
{
    return basic_string<T, Traits, Alloc>(left) += right;
}
template <class T, class Traits, class Alloc>
inline basic_string<T, Traits, Alloc> operator+(const basic_string<T, Traits, Alloc>& left,
                                                const basic_string<T, Traits, Alloc>& right)
{
    return basic_string<T, Traits, Alloc>(left) += right;
}
}
class IdvFileError : public std::runtime_error
{
  public:
    IdvFileError(const std::string& message, bool systemError)
        : std::runtime_error(message + " [" +
                             (systemError ? std::string(GetErrorText(*GetErrorNumber())) : std::string("")) + "]")
    {}
};
FUN_0044a4c0 __cdecl FUN_00b18860(const char*, ...);
struct FrondGuide;
template <class T> struct FrondVector
{
    int allocatorState;
    int growth;
    int reserved;
    T* begin;
    T* end;
    T* capacity;
    inline unsigned size() const
    {
        return unsigned(end - begin);
    }
    inline T& operator[](unsigned i)
    {
        if (i >= unsigned(end - begin))
            ::FUN_00ec7c56();
        return begin[i];
    }
    inline const T& operator[](unsigned i) const
    {
        if (i >= unsigned(end - begin))
            ::FUN_00ec7c56();
        return begin[i];
    }
};
struct FrondGuide
{
    FrondVector<FrondGuide> vertices;
    float f18, f1c;
    unsigned char c20;
    float f24, f28, f2c;
    int i30, i34;
};
struct FrondGeometry
{
    void FUN_00b2fb30(unsigned short);
    void FUN_00b306d0(unsigned short);
};
struct FrondEngine
{
    FrondGeometry* geometry;
    void* auxiliary;
    int state08, state0c, state10, state14, state18, state1c;
    FrondVector<FrondVector<FrondGuide> > guides;
    int mode;
    int bladeCount;
    int state40;
    int extrusionCount;
    int state48, state4c, state50, state54, state58, state5c, state60, state64;
    unsigned short geometryType;
    void FUN_00b1c850();
    void FUN_00b19ad0(FrondGuide&);
    void FUN_00b1aed0(unsigned short, int, FrondGuide&);
    void FUN_00b1b000(FrondGuide&);
    void FUN_00b1b960(unsigned short, int, FrondGuide&);
    void FUN_00b18fd0(FrondGeometry*, void*);
};
static const char vertexLimitMessage[] = "frond vertices exceed %d";
static const char invalidModeMessage[] = "default reached in CFrondEngine::Compute()";
// @fnv 0x00b18fd0
void FrondEngine::FUN_00b18fd0(FrondGeometry* output, void* context)
{
    geometry = output;
    auxiliary = context;
    int vertexCount = 0;
    FUN_00b1c850();
    for (unsigned i = 0; i < guides[0].size(); ++i)
    {
        switch (mode)
        {
        case 0: {
            vertexCount += guides[0][i].vertices.size() * 2 * bladeCount;
            break;
        }
        case 1: {
            vertexCount += guides[0][i].vertices.size() * (extrusionCount * 2 - 1);
            break;
        }
        default:
            throw IdvFileError(invalidModeMessage, false);
        }
    }
    if (vertexCount > 65535)
        throw std::runtime_error(FUN_00b18860(vertexLimitMessage, 65535));
    geometry->FUN_00b2fb30(geometryType);
    switch (mode)
    {
    case 0: {
        for (unsigned i = 0; i < guides[0].size(); ++i)
        {
            FUN_00b19ad0(guides[0][i]);
        }
        for (unsigned short level = 0; level < guides.size(); ++level)
        {
            geometry->FUN_00b306d0(level);
            for (unsigned j = 0; j < guides[level].size(); ++j)
            {
                FUN_00b1aed0(level, guides[0][j].i30, guides[level][j]);
            }
        }
        break;
    }
    case 1: {
        for (unsigned i = 0; i < guides[0].size(); ++i)
        {
            FUN_00b1b000(guides[0][i]);
        }
        for (unsigned short level = 0; level < guides.size(); ++level)
        {
            geometry->FUN_00b306d0(level);
            for (unsigned j = 0; j < guides[level].size(); ++j)
            {
                guides[level][j].i34 = guides[0][j].i34;
                FUN_00b1b960(level, guides[0][j].i30, guides[level][j]);
            }
        }
        break;
    }
    default:
        throw IdvFileError(invalidModeMessage, false);
    }
}
