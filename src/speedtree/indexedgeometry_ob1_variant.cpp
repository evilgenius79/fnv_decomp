
// src/speedtree/indexedgeometry_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/indexedgeometry.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/indexedgeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/indexedgeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00b30060_shell
{
    int FUN_00b30060(float* p);
};
struct FloatVec
{
    void PushBack(const float&);
};
struct FUN_00b30190_shell
{
    char m_ucUnknownByte[0xb8];
    void FUN_00b30190(const float* p);
};
unsigned int __cdecl FUN_00ec7c56(void);
struct Vec28
{
    char _pad[12];
    unsigned int* _first;
    unsigned int* _last;
};
struct Cls
{
    char _pad[36];
    unsigned short m1;
    unsigned short m2;
    Vec28 mVec;
    void FUN_00b306d0(unsigned short);
};
struct SubA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    SubA();
    ~SubA();
};
struct SubB
{
    int unk00;
    int unk04;
    int unk08;

    SubB();
};
struct FUN_00b10dc0
{
    int unk00;
    float unk04;
    SubA unk08;
    int unk20;
    int unk24;
    unsigned short unk28;
    int unk2c;
    float unk30;
    float unk34;
    SubB unk38;

    FUN_00b10dc0(int param);
};
struct FUN_00b300c0_cls
{
    char m_pad00[8];
    unsigned char m_flag08;
    char m_pad09[0xb];
    int m_14;
    char m_pad18[0x70];
    FloatVec m_vec88;
    char m_pad89[0x17];
    FloatVec m_veca0;

    void FUN_00b300c0(const float* p);
};
struct FrameBuf
{
    unsigned char unk00[0x1d0];
};
struct FUN_00b304f0_cls
{
    int unk00;
    float m_04;
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
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    FloatVec m_148;

    void FUN_00b304f0(const float& v);
};
bool __cdecl FUN_00b0d7a0(void);
void __cdecl FreeBlock(void* p);
class FUN_00b32c60_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_pHeadNode;
    int m_last;
    int m_kRayEnd;
    void DestroyRange(int first, int last);
    void FUN_00b32c60();
};
struct K
{
    char pad0[12];
    int fC;
    int f10;
    int f14;
    int __thiscall FUN_00b33110(int, int);
    void __thiscall FUN_00b331c0();
};
void __cdecl FormHeap_Free(void*);
unsigned int __cdecl FUN_00ec7c56(void);
void __cdecl FormHeap_Free(void*);
struct InnerVec
{
    int unk00;
    int unk04;
    int unk08;
    void** _first;
    void** _last;
    void** _end;
};
struct OuterVec
{
    int unk00;
    int unk04;
    int unk08;
    InnerVec* _first;
    InnerVec* _last;
    InnerVec* _end;
};
struct FUN_00b32350_shell
{
    void FUN_00b32350();
};
struct FUN_00b32120_shell
{
    void FUN_00b32120();
};
struct ScratchFrame
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
    int unk98;
    int unk9C;
    int unkA0;
};
struct TargetClass
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
    OuterVec m_outer;
    void ClearOuter();
};

// Based on another contributor's triangle-strip reconstruction supplied in packet.json.

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
namespace StripJoin {

struct AllocationFailure
{
    const char* message;
    AllocationFailure(const char* p = 0) : message(p)
    {}
    virtual ~AllocationFailure();
};
template <class T> inline T* allocateElements(unsigned int n, T*)
{
    if (n <= 0)
        n = 0;
    else if (0xffffffffu / n < sizeof(T))
        throw AllocationFailure();
    return (T*)::operator new(n * sizeof(T));
}
struct Aux;
template <class T> struct Allocator
{
    Allocator()
    {}
    Allocator(const Allocator&)
    {}
    template <class U> Allocator(const Allocator<U>&)
    {}
    T* allocate(unsigned int n)
    {
        return allocateElements(n, (T*)0);
    }
    void deallocate(T* p, unsigned int)
    {
        ::operator delete(p);
    }
};
struct Aux
{
    const void* owner;
    Aux(const void* p) : owner(p)
    {}
};
struct FUN_00b39460
{
    Aux* aux;
    Allocator<Aux> alloc;
    template <class T> FUN_00b39460(Allocator<T> al) : alloc(al)
    {
        aux = new (alloc.allocate(1)) Aux(this);
    }
    ~FUN_00b39460();
};

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

void* __cdecl operator new[](unsigned int);

template <class T> struct ValueBase : FUN_00b39460
{
    Allocator<T> valueAlloc;
    ValueBase(Allocator<T> al = Allocator<T>()) : FUN_00b39460(al), valueAlloc(al)
    {}
};
template <class T> struct Vector : ValueBase<T>
{

    T* first;

    T* last;

    T* capacity;
    Vector() : ValueBase<T>()
    {
        buy(0);
    }
    ~Vector()
    {
        tidy();
    }
    bool buy(unsigned int n)
    {
        first = 0;
        last = 0;
        capacity = 0;
        if (n == 0)
            return false;
        else if (0xffffffffu / sizeof(T) < n)
            ::FUN_00ec7c56();
        else
        {
            first = valueAlloc.allocate(n);
            last = first;
            capacity = first + n;
        }
        return true;
    }
    void tidy();
    struct ConstIterator
    {
        Aux* aux;
        T* ptr;
        ConstIterator() : aux(0)
        {}
        ConstIterator(T* p, const Vector* v) : aux(0)
        {
            aux = v->aux;
            ptr = p;
        }
        int operator-(const ConstIterator& other) const
        {
            if (aux != other.aux)
                ::FUN_00ec7c56();
            return ptr - other.ptr;
        }
    };
    struct Iterator : ConstIterator
    {
        Iterator()
        {}
        Iterator(T* p, const Vector* v) : ConstIterator(p, v)
        {}
        Iterator operator+(int n) const
        {
            Iterator tmp = *this;
            tmp += n;
            return tmp;
        }
        Iterator& operator+=(int n)
        {
            if (!aux)
                ::FUN_00ec7c56();
            ptr += n;
            return *this;
        }
    };
    Iterator begin()
    {
        return Iterator(first, this);
    }
    Iterator end()
    {
        return Iterator(last, this);
    }
    unsigned int capacitySize() const
    {
        return capacity - first;
    }
    T* fill(T*, unsigned int, const T&);
    void insert_n(ConstIterator, unsigned int, const T&);
    __declspec(noinline) Iterator insert(ConstIterator where, const T& value)
    {
        unsigned int off = size() == 0 ? 0 : where - begin();
        insert_n(where, 1, value);
        return begin() + off;
    }
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline T& operator[](unsigned int index)
    {
        if (index >= (unsigned int)(last - first))
            ::FUN_00ec7c56();
        return first[index];
    }
};

struct Lengths : Vector<unsigned short>
{

    void FUN_00b32410(const unsigned short& value)
    {
        if (size() < capacitySize())
            last = fill(last, 1, value);
        else
            insert(end(), value);
    }

    void FUN_00b32540();
};

struct Strips : Vector<unsigned short*>
{

    void FUN_00b15390(unsigned short* const& value)
    {
        if (size() < capacitySize())
            last = fill(last, 1, value);
        else
            insert(end(), value);
    }

    void FUN_00b32350();
};

struct FUN_00b31350 : ValueBase<Lengths>
{
    unsigned int unkc, unk10, unk14;

    FUN_00b31350(unsigned int n)
    {
        construct(n, Lengths());
    }
    void construct(unsigned int n, const Lengths& val)
    {
        if (buy(n))
        {
            try
            {
                unk10 = (unsigned int)fill((Lengths*)unkc, n, val);
            }
            catch (...)
            {
                clear();
                throw;
            }
        }
    }
    bool buy(unsigned int n)
    {
        unkc = 0;
        unk10 = 0;
        unk14 = 0;
        if (n == 0)
            return false;
        else if (0xffffffffu / sizeof(Lengths) < n)
            ::FUN_00ec7c56();
        else
        {
            unkc = (unsigned int)valueAlloc.allocate(n);
            unk10 = unkc;
            unk14 = unkc + n * sizeof(Lengths);
        }
        return true;
    }
    Lengths* fill(Lengths*, unsigned int, const Lengths&);
    void clear();

    ~FUN_00b31350()
    {
        FUN_00b32c60();
    }

    void FUN_00b32c60();

    Lengths* FUN_00b319a0(unsigned int);
    __forceinline Lengths& operator[](unsigned int index)
    {
        if (index >= (unsigned int)((Lengths*)unk10 - (Lengths*)unkc))
            ::FUN_00ec7c56();
        return ((Lengths*)unkc)[index];
    }

    void FUN_00b314f0(const FUN_00b31350&);
};

struct FUN_00b31ad0 : ValueBase<Strips>
{
    unsigned int unkc, unk10, unk14;

    FUN_00b31ad0(unsigned int n)
    {
        construct(n, Strips());
    }
    void construct(unsigned int n, const Strips& val)
    {
        if (buy(n))
        {
            try
            {
                unk10 = (unsigned int)fill((Strips*)unkc, n, val);
            }
            catch (...)
            {
                clear();
                throw;
            }
        }
    }
    bool buy(unsigned int n)
    {
        unkc = 0;
        unk10 = 0;
        unk14 = 0;
        if (n == 0)
            return false;
        else if (0xffffffffu / sizeof(Strips) < n)
            ::FUN_00ec7c56();
        else
        {
            unkc = (unsigned int)valueAlloc.allocate(n);
            unk10 = unkc;
            unk14 = unkc + n * sizeof(Strips);
        }
        return true;
    }
    Strips* fill(Strips*, unsigned int, const Strips&);
    void clear();

    ~FUN_00b31ad0()
    {
        FUN_00b331c0();
    }

    void FUN_00b331c0();

    Strips* FUN_00b319a0(unsigned int);
    __forceinline Strips& operator[](unsigned int index)
    {
        if (index >= (unsigned int)((Strips*)unk10 - (Strips*)unkc))
            ::FUN_00ec7c56();
        return ((Strips*)unkc)[index];
    }

    void FUN_00b31c70(const FUN_00b31ad0&);
};

struct FUN_00b311b0 : ValueBase<unsigned int>
{
    unsigned int unkc, unk10, unk14;

    FUN_00b311b0(unsigned int n)
    {
        construct(n, unsigned int());
    }
    void construct(unsigned int n, const unsigned int& val)
    {
        if (buy(n))
        {
            try
            {
                unk10 = (unsigned int)fill((unsigned int*)unkc, n, val);
            }
            catch (...)
            {
                clear();
                throw;
            }
        }
    }
    bool buy(unsigned int n)
    {
        unkc = 0;
        unk10 = 0;
        unk14 = 0;
        if (n == 0)
            return false;
        else if (0xffffffffu / sizeof(unsigned int) < n)
            ::FUN_00ec7c56();
        else
        {
            unkc = (unsigned int)valueAlloc.allocate(n);
            unk10 = unkc;
            unk14 = unkc + n * sizeof(unsigned int);
        }
        return true;
    }
    unsigned int* fill(unsigned int*, unsigned int, const unsigned int&);
    void clear();

    ~FUN_00b311b0()
    {
        FUN_00b17f50();
    }

    void FUN_00b17f50();

    unsigned int* FUN_00b31230(unsigned int);
    __forceinline unsigned int& operator[](unsigned int index)
    {
        if (index >= (unsigned int)((unsigned int*)unk10 - (unsigned int*)unkc))
            ::FUN_00ec7c56();
        return ((unsigned int*)unkc)[index];
    }

    void FUN_00b36330(const FUN_00b311b0&);
};

struct Mesh
{

    unsigned int unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c;

    unsigned short count, unk22;

    unsigned int unk24;

    FUN_00b311b0 counts;

    FUN_00b31350 lengths;

    FUN_00b31ad0 strips;

    unsigned int unk70, unk74, unk78, unk7c, unk80, unk84;

    Vector<unsigned int> triangles;

    void FUN_00b2ed70(bool);

    void ClearOuter();
};

// @fnv 0x00b2ed70
void Mesh::FUN_00b2ed70(bool preserve)
{
    if ((unsigned short)(triangles.size() / 3) > 0)
    {
        FUN_00b31350 newLengths(count);
        FUN_00b31ad0 newStrips(count);
        FUN_00b311b0 newCounts(count);
        for (unsigned short group = 0; group < count; ++group)
        {
            int combinedLength = 0;
            for (unsigned short index = 0;
                 index <
                 ((short)group > -1 ? (unsigned short)strips.FUN_00b319a0((short)group)->size() : (unsigned short)0);
                 ++index)
                combinedLength += lengths[group][index];
            if (combinedLength > 0)
            {
                if (preserve)
                {
                    for (unsigned short join = 0;
                         join < ((short)group > -1 ? (unsigned short)strips.FUN_00b319a0((short)group)->size()
                                                   : (unsigned short)0) -
                                    1;
                         ++join)
                    {
                        unsigned short preserveLength = lengths[group][join];
                        if (preserveLength % 2 == 0)
                            combinedLength += 2;
                        else
                            combinedLength += 3;
                    }
                }
                else
                {
                    int joins = ((short)group > -1 ? (unsigned short)strips.FUN_00b319a0((short)group)->size()
                                                   : (unsigned short)0);
                    if (joins > 0)
                        joins--;
                    combinedLength += 2 * joins;
                }
                unsigned short* writer = new unsigned short[combinedLength];
                unsigned short* joined = writer;
                for (unsigned short strip = 0;
                     strip < ((short)group > -1 ? (unsigned short)strips.FUN_00b319a0((short)group)->size()
                                                : (unsigned short)0);
                     ++strip)
                {
                    unsigned short copyLength = lengths[group][strip];
                    memcpy(joined, strips[group][strip], copyLength * sizeof(unsigned short));
                    joined += copyLength;
                    if (strip < ((short)group > -1 ? (unsigned short)strips.FUN_00b319a0((short)group)->size()
                                                   : (unsigned short)0) -
                                    1)
                    {
                        if (preserve)
                        {
                            if (copyLength % 2 == 0)
                            {
                                *joined++ = strips[group][strip][copyLength - 1];
                                unsigned short evenNextVertex = strips[group][strip + 1][0];
                                *joined++ = evenNextVertex;
                            }
                            else
                            {
                                *joined++ = strips[group][strip][copyLength - 1];
                                *joined++ = strips[group][strip][copyLength - 1];
                                unsigned short oddNextVertex = strips[group][strip + 1][0];
                                *joined++ = oddNextVertex;
                            }
                        }
                        else
                        {
                            *joined++ = strips[group][strip][copyLength - 1];
                            unsigned short plainNextVertex = strips[group][strip + 1][0];
                            *joined++ = plainNextVertex;
                        }
                    }
                }
                newLengths[group].FUN_00b32410((unsigned short)combinedLength);
                newStrips[group].FUN_00b15390(writer);
                newCounts[group] = combinedLength - 2;
            }
            else
            {
                newLengths.FUN_00b319a0(group)->FUN_00b32540();
                newStrips.FUN_00b319a0(group)->FUN_00b32350();
                *newCounts.FUN_00b31230(group) = 0;
            }
        }
        ClearOuter();
        lengths.FUN_00b314f0(newLengths);
        strips.FUN_00b31c70(newStrips);
        counts.FUN_00b36330(newCounts);
    }
}
}

void* __cdecl _memmove(void*, const void*, unsigned int);
struct Matrix366
{
    float m[4][4];
};
struct Point366
{
    float x, y, z;
    void Set(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    Point366()
    {}
    Point366(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    Point366 operator*(const Matrix366& m) const
    {
        float a = m.m[0][0] * x + m.m[1][0] * y + m.m[2][0] * z + m.m[3][0];
        float b = m.m[0][1] * x + m.m[1][1] * y + m.m[2][1] * z + m.m[3][1];
        float c = m.m[0][2] * x + m.m[1][2] * y + m.m[2][2] * z + m.m[3][2];
        return Point366(a, b, c);
    }
};
struct Vector366
{
    int unk00, unk04, unk08;
    float *first, *last;
    int unk14;
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline bool empty() const
    {
        return size() == 0;
    }
};
struct Geometry366
{
    int unk00, unk04;
    unsigned char normals;
    unsigned char unk09, unk0a, unk0b;
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
    Vector366 vertices;
    Vector366 normalData;
    float* GetVertex(int);
    float* GetPlaneNormal(int);
    void FUN_00b2fc50(const Matrix366&);
};
// @fnv 0x00b2fc50
void Geometry366::FUN_00b2fc50(const Matrix366& matrix)
{
    unsigned short count;
    int i;
    float* vertex2;
    Point366 point2;
    float* normal;
    count = vertices.size() / 3;
    for (i = 0; i < count; i++)
    {
        vertex2 = GetVertex(i);
        point2.Set(vertex2[0], vertex2[1], vertex2[2]);
        point2 = point2 * matrix;
        _memmove(vertex2, &point2, 12);
        if (normals)
        {
            if (!normalData.empty())
            {
                normal = GetPlaneNormal(i);
                point2.Set(normal[0], normal[1], normal[2]);
                point2 = point2 * matrix;
                _memmove(normal, &point2, 12);
            }
        }
    }
}

template <class T> struct VecConstIterator
{
    void* owner;
    T* ptr;
    VecConstIterator(T* p, void* o) : owner(o), ptr(p)
    {}
    VecConstIterator& operator+=(int n)
    {
        ptr += n;
        return *this;
    }
};
template <class T> struct VecIterator : VecConstIterator<T>
{
    VecIterator(T* p, void* o) : VecConstIterator<T>(p, o)
    {}
    VecIterator& operator+=(int n)
    {
        VecConstIterator<T>::operator+=(n);
        return *this;
    }
    VecIterator operator+(int n) const
    {
        VecIterator result = *this;
        return result += n;
    }
};
struct S_0060b3f0
{
    int owner, allocator, proxy;
    float *first, *last, *end;
    typedef VecIterator<float> iterator;
    inline iterator begin()
    {
        return iterator(first, this);
    }
    inline iterator finish()
    {
        return iterator(last, this);
    }
    void insert_n(VecConstIterator<float> where, unsigned count, const float& value);
    iterator erase(VecConstIterator<float> first, VecConstIterator<float> last);
    void FUN_0060b410(unsigned count, float value);

    inline void resize(unsigned count)
    {
        FUN_0060b410(count, float());
    }
    __forceinline unsigned size() const
    {
        return last - first;
    }
    __forceinline float& operator[](unsigned n)
    {
        if (!(n < size()))
            FUN_00ec7c56();
        return first[n];
    }
};
struct AuxFloatArray
{
    int owner, allocator, proxy;
    float *first, *last, *end;
    typedef VecIterator<float> iterator;
    inline iterator begin()
    {
        return iterator(first, this);
    }
    inline iterator finish()
    {
        return iterator(last, this);
    }
    void insert_n(VecConstIterator<float> where, unsigned count, const float& value);
    iterator erase(VecConstIterator<float> first, VecConstIterator<float> last);
    void FUN_0060b410(unsigned count, float value)
    {
        if (size() < count)
            insert_n(finish(), count - size(), value);
        else if (count < size())
            erase(begin() + count, finish());
    }

    inline void resize(unsigned count)
    {
        FUN_0060b410(count, float());
    }
    __forceinline unsigned size() const
    {
        return last - first;
    }
    __forceinline float& operator[](unsigned n)
    {
        if (!(n < size()))
            FUN_00ec7c56();
        return first[n];
    }
};
struct ByteArray
{
    int owner, allocator, proxy;
    unsigned char *first, *last, *end;
    typedef VecIterator<unsigned char> iterator;
    inline iterator begin()
    {
        return iterator(first, this);
    }
    inline iterator finish()
    {
        return iterator(last, this);
    }
    void insert_n(iterator where, unsigned count, const unsigned char& value);
    iterator erase(iterator first, iterator last);
    void FUN_00b0e200(unsigned count, unsigned char value);

    inline void resize(unsigned count)
    {
        FUN_00b0e200(count, (unsigned char)0);
    }
    __forceinline unsigned size() const
    {
        return last - first;
    }
    __forceinline unsigned char& operator[](unsigned n)
    {
        if (!(n < size()))
            FUN_00ec7c56();
        return first[n];
    }
};
struct CoordinateWriter
{
    unsigned char enabled;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned short unk20;
    unsigned short count;
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
    S_0060b3f0 mainCoordinates;
    AuxFloatArray auxiliaryCoordinates;
    ByteArray indices;
    void FUN_00b301f0(const float* point, short index);
};
// @fnv 0x00b301f0
void CoordinateWriter::FUN_00b301f0(const float* point, short index)
{
    if (count == mainCoordinates.size() / 2)
    {
        mainCoordinates.resize(mainCoordinates.size() + 2);
        if (index > -1 && enabled)
        {
            indices.resize(indices.size() + 1);
            auxiliaryCoordinates.resize(auxiliaryCoordinates.size() + 2);
        }
    }
    if (index > -1 && enabled)
    {
        indices[count] = (unsigned char)index;
        auxiliaryCoordinates[2 * count] = point[0];
        auxiliaryCoordinates[2 * count + 1] = point[1];
    }
    mainCoordinates[2 * count] = point[0];
    mainCoordinates[2 * count + 1] = FUN_00b0d7a0() ? -point[1] : point[1];
}

struct ScalarTag
{
};
struct UIntAllocator
{
    unsigned int* allocate(unsigned int);
    void deallocate(unsigned int*, unsigned int);
};
template <class T> inline ScalarTag PtrCategory(T*&, T*&)
{
    ScalarTag cat;
    return cat;
}
template <class A> inline void DestroyRange(unsigned int* first, unsigned int* last, A& alloc, ScalarTag tag)
{}
template <class A> inline void DestroyRange(unsigned int* first, unsigned int* last, A& alloc)
{
    DestroyRange(first, last, alloc, PtrCategory(first, last));
}
struct UnchangedTag
{
};
template <class I> inline I CheckedBase(const I& iter, UnchangedTag)
{
    return iter;
}
template <class I> inline I CheckedBase(const I& iter)
{
    UnchangedTag tag;
    return CheckedBase(iter, tag);
}
struct RandomTag
{
};
struct CheckedTag
{
};
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
template <class I, class O> inline RandomTag IterRandom(const I&, const O&)
{
    RandomTag cat;
    return cat;
}
template <class I, class O, class C> inline O CopyOpt(I first, I last, O dest, C, ScalarTag, CheckedTag)
{
    int off = last - first;
    O result = dest + off;
    if (off > 0)
        memmove(dest, first, off * sizeof(*first));
    return result;
}
template <class I, class O> inline O CopyUnchecked(I first, I last, O dest)
{
    return CopyOpt(CheckedBase(first), CheckedBase(last), dest, IterRandom(first, dest), PtrCategory(first, dest),
                   CheckedTag());
}
struct VectorContainer;
struct VectorAux
{
    const VectorContainer* owner;
    const VectorContainer* GetCont() const
    {
        return owner;
    }
};
struct VectorContainer
{
    const VectorAux* aux;
};
struct IteratorUniversal
{
};
struct IteratorBase : IteratorUniversal
{
    const VectorAux* cont;
    IteratorBase() : cont(0)
    {}
    void SetContainer(const VectorContainer* const c)
    {
        cont = c->aux;
    }
};
template <class T> struct UIntVecT;
template <class T> struct IteratorWithBase : IteratorBase
{
};
template <class T> struct RandomIterator : IteratorWithBase<T>
{
};
template <class T> struct ConstIterT : RandomIterator<T>
{
    unsigned int* ptr;
    ConstIterT<T>& FUN_00b2e330(int n)
    {
        if (!this->IsContainerSet())
            FUN_00ec7c56();
        if (!(ptr + n <= GetContainer()->last && ptr + n >= GetContainer()->first))
            FUN_00ec7c56();
        ptr += n;
        return *this;
    }
    bool IsContainerSet() const
    {
        return cont != 0;
    }
    const UIntVecT<T>* GetContainer() const;
    bool Equal(const ConstIterT<T>& r) const
    {
        if (!(this->cont == r.cont))
            FUN_00ec7c56();
        return ptr == r.ptr;
    }
    bool FUN_00b16830(const ConstIterT<T>& r) const
    {
        return !Equal(r);
    }
    ConstIterT(unsigned int* p, const VectorContainer* c)
    {
        if (!(c != 0 && ((UIntVecT<T>*)c)->first <= p && p <= ((UIntVecT<T>*)c)->last))
            FUN_00ec7c56();
        this->SetContainer(c);
        this->ptr = p;
    }
};
template <class T> struct VecIterT : ConstIterT<T>
{
    VecIterT(unsigned int* p, const VectorContainer* c) : ConstIterT<T>(p, c)
    {}
    VecIterT<T>& operator+=(int n)
    {
        ((ConstIterT<T>*)this)->FUN_00b2e330(n);
        return *this;
    }
    VecIterT<T> operator+(int n) const
    {
        VecIterT<T> tmp = *this;
        return tmp += n;
    }
};
template <class T> struct UIntVecT : VectorContainer
{
    int unk04;
    UIntAllocator allocator;
    unsigned int* first;
    unsigned int* last;
    unsigned int* limit;
    unsigned int size() const
    {
        return last - first;
    }
    VecIterT<T> begin()
    {
        return VecIterT<T>(first, this);
    }
    VecIterT<T> end()
    {
        return VecIterT<T>(last, this);
    }
    unsigned int capacity() const
    {
        return limit - first;
    }
    unsigned int max_size() const
    {
        return 0x3fffffff;
    }
    void Xlen();
    void Fill(unsigned int*, unsigned int*, const unsigned int&);
    unsigned int* Ufill(unsigned int*, unsigned int, const unsigned int&);
    unsigned int* Umove(unsigned int*, unsigned int*, unsigned int*);
    void MoveBackward(unsigned int*, unsigned int*, unsigned int*);
    void FUN_00b16070(ConstIterT<T> where, unsigned int n, const unsigned int& val)
    {
        unsigned int cap = capacity();
        if (n == 0)
            ;
        else if (max_size() - size() < n)
            Xlen();
        else if (cap < size() + n)
        {
            cap = max_size() - cap / 2 < cap ? 0 : cap + cap / 2;
            if (cap < size() + n)
                cap = size() + n;
            unsigned int* newvec = allocator.allocate(cap);
            unsigned int off = where.ptr - first;
            int copied = 0;
            try
            {
                Ufill(newvec + off, n, val);
                ++copied;
                Umove(first, where.ptr, newvec);
                ++copied;
                Umove(where.ptr, last, newvec + off + n);
            }
            catch (...)
            {
                if (1 < copied)
                    Destroy(newvec, newvec + off);
                if (0 < copied)
                    Destroy(newvec + off, newvec + off + n);
                allocator.deallocate(newvec, cap);
                throw;
            }
            n += size();
            if (first)
            {
                Destroy(first, last);
                allocator.deallocate(first, limit - first);
            }
            limit = newvec + cap;
            last = newvec + n;
            first = newvec;
        }
        else if ((unsigned int)(last - where.ptr) < n)
        {
            unsigned int temp = val;
            Umove(where.ptr, last, where.ptr + n);
            try
            {
                Ufill(last, n - (last - where.ptr), temp);
            }
            catch (...)
            {
                Destroy(where.ptr + n, last + n);
                throw;
            }
            last += n;
            Fill(where.ptr, last - n, temp);
        }
        else
        {
            unsigned int temp = val;
            unsigned int* oldend = last;
            last = Umove(oldend - n, oldend, last);
            MoveBackward(where.ptr, oldend - n, oldend);
            Fill(where.ptr, where.ptr + n, temp);
        }
    }
    void Destroy(unsigned int* first, unsigned int* last)
    {
        DestroyRange(first, last, allocator);
    }
    VecIterT<T> MakeIter(ConstIterT<T> where) const
    {
        return VecIterT<T>(where.ptr, this);
    }
    VecIterT<T> FUN_00b335c0(ConstIterT<T> a, ConstIterT<T> b)
    {
        VecIterT<T> f = MakeIter(a);
        VecIterT<T> l = MakeIter(b);
        if (f.FUN_00b16830(l))
        {
            unsigned int* result = CopyUnchecked(l.ptr, last, f.ptr);
            Destroy(result, last);
            last = result;
        }
        return f;
    }
    void FUN_00b333e0(unsigned int n, unsigned int val);
};

template <class T> inline const UIntVecT<T>* ConstIterT<T>::GetContainer() const
{
    return this->cont ? (const UIntVecT<T>*)this->cont->GetCont() : 0;
}

// @fnv 0x00b333e0
template <> void UIntVecT<unsigned int>::FUN_00b333e0(unsigned int n, unsigned int val)
{
    if (size() < n)
        FUN_00b16070(end(), n - size(), val);
    else if (n < size())
        FUN_00b335c0(begin() + n, end());
}

inline void Dead8_acad60()
{
    int a[8];
}
inline void Dead11_acad60()
{
    int a[11];
}
struct AlQ_acad60
{
};
struct CatQ_acad60
{
};
struct TagQ_acad60
{
};
inline CatQ_acad60 PtrCat_acad60(char*&, char*&)
{
    CatQ_acad60 c;
    return c;
}
void __cdecl FUN_00b10cf0(char* _First, unsigned int _Count, const char& _Val);
inline void UFill2_acad60(char* _First, unsigned int _Count, const char& _Val, AlQ_acad60& _Al, CatQ_acad60,
                          TagQ_acad60)
{
    Dead8_acad60();
    FUN_00b10cf0(_First, _Count, _Val);
}
inline void UFillN_acad60(char* _First, unsigned int _Count, const char& _Val, AlQ_acad60& _Al)
{
    UFill2_acad60(_First, _Count, _Val, _Al, PtrCat_acad60(_First, _First), TagQ_acad60());
}
struct VecQ_acad60;
struct CItQ_acad60
{
    void* _Myaux;
    char* _Myptr;
    CItQ_acad60()
    {}
    CItQ_acad60(char* _Ptr, const VecQ_acad60* _Pvector);
};
struct ItQ_acad60 : CItQ_acad60
{
    ItQ_acad60()
    {}
    ItQ_acad60(char* _Ptr, const VecQ_acad60* _Pvector) : CItQ_acad60(_Ptr, _Pvector)
    {}
};
struct VecQ_acad60
{
    void* _Myownedaux;
    int m04;
    AlQ_acad60 _Alval;
    char p09[3];
    char* _Myfirst;
    char* _Mylast;
    char* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_acad60 end()
    {
        return ItQ_acad60(_Mylast, this);
    }
    char* _Ufill(char* _Ptr, unsigned int _Count, const char& _Val)
    {
        UFillN_acad60(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_acad60 FUN_00b0e3e0(CItQ_acad60 _Where, const char& _Val);
    void FUN_00b0dae0(const char& _Val);
};
inline CItQ_acad60::CItQ_acad60(char* _Ptr, const VecQ_acad60* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        FUN_00ec7c56();
    do
    {
    } while (0);
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b0dae0
void VecQ_acad60::FUN_00b0dae0(const char& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        FUN_00b0e3e0(end(), _Val);
        Dead11_acad60();
    }
}

void __cdecl FormHeap_Free(void* p);
struct VB9
{
    inline void*& PP()
    {
        return *(void**)this;
    }
    inline void Dealloc(void* q)
    {
        FormHeap_Free(q);
    }
    ~VB9()
    {
        Dealloc(PP());
    }
};
struct FUN_0065f240
{
    int a[6];
    ~FUN_0065f240();
};
struct FUN_00657f60
{
    int a[6];
    ~FUN_00657f60();
};
struct FUN_00b331c0
{
    int a[6];
    ~FUN_00b331c0();
};
struct FUN_00b32c60
{
    int a[6];
    ~FUN_00b32c60();
};
struct FUN_00b17f50
{
    int a[6];
    ~FUN_00b17f50();
};
struct FUN_00b39460
{
    ~FUN_00b39460();
};
inline void DeadE()
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
}
inline void DeadF()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
}
struct VA9 : VB9
{
    FUN_0065f240 e;
    ~VA9()
    {}
};
struct VC9 : VB9
{
    FUN_00657f60 e;
    ~VC9()
    {}
};
struct VD9 : VB9
{
    FUN_00b331c0 e;
    ~VD9()
    {}
};
struct VE9 : FUN_00b39460
{
    FUN_00b32c60 e;
    ~VE9()
    {
        DeadE();
    }
};
struct VF9 : FUN_00b39460
{
    FUN_00b17f50 e;
    ~VF9()
    {
        DeadF();
    }
};
struct FUN_00b2e9c0
{
    int i0, i4, i8;
    void* pBuf;
    int pad10[6];
    VF9 v28;
    VE9 v40;
    VD9 v58;
    VA9 v70, v88, va0, vb8, vd0, ve8, v100, v118;
    VC9 v130;
    VA9 v148, v160;
    VC9 v178;
    inline void Free(void* p)
    {
        FormHeap_Free(p);
    }
    void ClearOuter();
    ~FUN_00b2e9c0();
};
// @fnv 0x00b2e9c0
FUN_00b2e9c0::~FUN_00b2e9c0()
{
    Free(pBuf);
    pBuf = 0;
    ClearOuter();
}

struct Vec3f
{
    float x;
    float y;
    float z;
};

struct GlobalObject_00b3f100
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    ~GlobalObject_00b3f100();
};

struct BoundsBox
{
    GlobalObject_00b3f100 minObj;
    GlobalObject_00b3f100 maxObj;
    BoundsBox FUN_00b3caa0(Vec3f* point);
};

struct ShapeHost
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
    Vec28 mVec;
    __forceinline unsigned short getCount()
    {
        Vec28* v7 = &mVec;
        return (unsigned short)((unsigned int)(v7->_last - v7->_first) / 3u);
    }
    __forceinline void fill(Vec3f* p, Vec3f* b)
    {
        Vec3f a2;
        a2.x = p->x;
        a2.y = p->y;
        a2.z = p->z;
        b->x = a2.x;
        b->y = a2.y;
        b->z = a2.z;
    }
    Vec3f* FUN_00b30f80(int index);
    void FUN_00b2fa30(BoundsBox* out);
};

// @fnv 0x00b2fa30
void ShapeHost::FUN_00b2fa30(BoundsBox* out)
{
    unsigned short count = getCount();
    for (int i = 0; i < count; ++i)
    {
        Vec3f* pX = FUN_00b30f80(i);
        Vec3f b;
        fill(pX, &b);
        *out = out->FUN_00b3caa0(&b);
    }
}

typedef unsigned int size_t;
typedef int ptrdiff_t;
unsigned int FUN_00ec7c56();
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
inline void __cdecl operator delete(void*, void*)
{}
extern "C" int __cdecl memmove_s(void*, size_t, const void*, size_t);
namespace std {
template <class T> void swap(T&, T&);
template <class T> void _Swap_adl(T&, T&);
template <class T> T* _Allocate(size_t, T*);
template <class T, class U> void _Construct(T*, const U&);
template <class T> void _Destroy(T*);
struct _Unchecked_iterator_tag
{
};
struct _Unchanged_checked_iterator_base_type_tag
{
};
struct _Undefined_inner_type_tag
{
};
struct _Range_checked_iterator_tag
{
};
class _Iterator_base_universal
{
  public:
    typedef _Unchecked_iterator_tag _Checked_iterator_category;
    typedef _Unchanged_checked_iterator_base_type_tag _Checked_iterator_base_type;
    typedef _Undefined_inner_type_tag _Inner_type;
};
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
    void _Swap_aux(_Container_base_aux& _Right)
    {
        ::std::swap(_Myownedaux, _Right._Myownedaux);
        ::std::swap(*_Myownedaux, *_Right._Myownedaux);
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
class _Iterator_base_aux : public _Iterator_base_universal
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

struct input_iterator_tag
{
};
struct output_iterator_tag
{
};
struct forward_iterator_tag : input_iterator_tag
{
};
struct bidirectional_iterator_tag : forward_iterator_tag
{
};
struct random_access_iterator_tag : bidirectional_iterator_tag
{
};
struct _Int_iterator_tag
{
};
template <class T> random_access_iterator_tag _Iter_cat(const T&);
template <class T> T* _Val_type(const T&);
template <class C, class T, class D, class P, class R> struct iterator : _Iterator_base
{
    typedef C iterator_category;
    typedef T value_type;
    typedef D difference_type;
    typedef P pointer;
    typedef R reference;
};
template <class T, class D, class P, class R> struct _Ranit : iterator<random_access_iterator_tag, T, D, P, R>
{
};
template <class I> struct reverse_iterator
{
};

template <class _Ty> struct _Allocator_base
{
    typedef _Ty value_type;
};
template <class _Ty> struct _Allocator_base<const _Ty>
{
    typedef _Ty value_type;
};
template <class _Ty> class allocator : public _Allocator_base<_Ty>
{
  public:
    typedef _Allocator_base<_Ty> _Mybase;
    typedef typename _Mybase::value_type value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef const value_type* const_pointer;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    template <class _Other> struct rebind
    {
        typedef allocator<_Other> other;
    };
    pointer address(reference _Val) const
    {
        return (&_Val);
    }
    const_pointer address(const_reference _Val) const
    {
        return (&_Val);
    }
    allocator() throw()
    {}
    allocator(const allocator<_Ty>&) throw()
    {}
    template <class _Other> allocator(const allocator<_Other>&) throw()
    {}
    template <class _Other> allocator<_Ty>& operator=(const allocator<_Other>&)
    {
        return (*this);
    }
    void deallocate(pointer _Ptr, size_type)
    {
        ::operator delete(_Ptr);
    }
    pointer allocate(size_type _Count)
    {
        return (_Allocate(_Count, (pointer)0));
    }
    pointer allocate(size_type _Count, const void*)
    {
        return (allocate(_Count));
    }
    void construct(pointer _Ptr, const _Ty& _Val)
    {
        _Construct(_Ptr, _Val);
    }
    void destroy(pointer _Ptr)
    {
        _Destroy(_Ptr);
    }
    size_t max_size() const throw()
    {
        size_t _Count = (size_t)(-1) / sizeof(_Ty);
        return (0 < _Count ? _Count : 1);
    }
};

struct _Scalar_ptr_iterator_tag
{
};
struct _Nonscalar_ptr_iterator_tag
{
};
template <class I, class O> struct PointerCategory
{
    typedef _Nonscalar_ptr_iterator_tag type;
};
template <> struct PointerCategory<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tag type;
};
template <class I, class O> inline typename PointerCategory<I, O>::type _Ptr_cat(I&, O&)
{
    typename PointerCategory<I, O>::type _Cat;
    return _Cat;
}
template <class I, class O> inline random_access_iterator_tag _Iter_random(const I&, const O&)
{
    random_access_iterator_tag _Cat;
    return _Cat;
}
template <class I> inline I _Checked_base(I& it, _Unchanged_checked_iterator_base_type_tag)
{
    return it;
}
template <class I> inline I _Checked_base(I& it)
{
    _Unchanged_checked_iterator_base_type_tag _Base_tag;
    return _Checked_base(it, _Base_tag);
}
template <class I, class O, class C>
inline O _Copy_opt(I first, I last, O dest, C, _Nonscalar_ptr_iterator_tag, _Range_checked_iterator_tag)
{
    for (; first != last; ++dest, ++first)
        *dest = *first;
    return dest;
}
template <class I, class O>
inline O _Copy_opt(I first, I last, O dest, random_access_iterator_tag, _Nonscalar_ptr_iterator_tag,
                   _Range_checked_iterator_tag)
{
    O _Result = dest + (last - first);
    _Copy_opt(first, last, _Checked_base(dest), forward_iterator_tag(), _Nonscalar_ptr_iterator_tag(),
              _Range_checked_iterator_tag());
    return _Result;
}
template <class I, class O, class C>
inline O _Copy_opt(I first, I last, O dest, C, _Scalar_ptr_iterator_tag, _Range_checked_iterator_tag)
{
    ptrdiff_t _Off = last - first;
    O _Result = dest + _Off;
    if (_Off > 0)
        ::memmove_s(&*dest, _Off * sizeof(*first), &*first, _Off * sizeof(*first));
    return _Result;
}
template <class I, class O> inline O unchecked_copy(I first, I last, O dest)
{
    return _Copy_opt(_Checked_base(first), _Checked_base(last), dest, _Iter_random(first, dest), _Ptr_cat(first, dest),
                     _Range_checked_iterator_tag());
}
template <class I, class O> void unchecked_copy_backward(I, I, O);
template <class A>
inline void _Destroy_range(typename A::pointer first, typename A::pointer last, A& a, _Nonscalar_ptr_iterator_tag)
{
    for (; first != last; ++first)
        a.destroy(first);
}
template <class A> inline void _Destroy_range(typename A::pointer, typename A::pointer, A&, _Scalar_ptr_iterator_tag)
{}
template <class A> inline void _Destroy_range(typename A::pointer first, typename A::pointer last, A& a)
{
    _Destroy_range(first, last, a, _Ptr_cat(first, last));
}
template <class I, class O, class A> O _Uninitialized_copy(I, I, O, A&);
template <class I, class S, class T, class A> I _Uninitialized_fill_n(I, S, const T&, A&);
template <class I, class T> void fill(I, I, const T&);
}
namespace stdext {
using std::unchecked_copy;
using std::unchecked_copy_backward;
template <class I, class O, class A> O _Unchecked_uninitialized_move(I, I, O, A&);
template <class I, class S, class T, class A> void unchecked_uninitialized_fill_n(I, S, const T&, A&);
template <class I, class O> O _Unchecked_move(I, I, O);
template <class I, class O> void _Unchecked_move_backward(I, I, O);
template <class I, class O, class A> O unchecked_uninitialized_copy(I, I, O, A&);
}
namespace std {
template <class _Ty, class _Ax = allocator<_Ty> > class vector;
template <class _Ty, class _Alloc>
class _Vector_const_iterator : public _Ranit<_Ty, typename _Alloc::difference_type, typename _Alloc::const_pointer,
                                             typename _Alloc::const_reference>
{
  public:
    typedef _Vector_const_iterator<_Ty, _Alloc> _Myt;
    typedef vector<_Ty, _Alloc> _Myvec;
    typedef typename _Alloc::pointer _Tptr;
    typedef random_access_iterator_tag iterator_category;
    typedef _Ty value_type;
    typedef typename _Alloc::difference_type difference_type;
    typedef typename _Alloc::const_pointer pointer;
    typedef typename _Alloc::const_reference reference;
    typedef _Range_checked_iterator_tag _Checked_iterator_category;
    typedef pointer _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return _Myptr;
    }
    void _Checked_iterator_assign_from_base(_Checked_iterator_base_type _Base)
    {
        this->_Myptr = const_cast<_Tptr>(_Base);
    }
    typedef _Tptr _Inner_type;
    _Vector_const_iterator()
    {
        _Myptr = 0;
    }
    _Vector_const_iterator(_Tptr _Ptr, const _Container_base* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    reference operator*() const
    {
        {
            if (!(this->_Has_container()))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        {
            if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        return (*_Myptr);
    }
    pointer operator->() const
    {
        return (&**this);
    }
    _Myt& operator++()
    {
        {
            if (!(this->_Has_container()))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        {
            if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        ++_Myptr;
        return (*this);
    }
    _Myt operator++(int)
    {
        _Myt _Tmp = *this;
        ++*this;
        return (_Tmp);
    }
    _Myt& operator--()
    {
        {
            if (!(this->_Has_container()))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        {
            if (!(_Myptr > ((_Myvec*)(this->_Getmycont()))->_Myfirst))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        --_Myptr;
        return (*this);
    }
    _Myt operator--(int)
    {
        _Myt _Tmp = *this;
        --*this;
        return (_Tmp);
    }
    _Myt& operator+=(difference_type _Off)
    {
        {
            if (!(this->_Has_container()))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        {
            if (!(_Myptr + _Off <= ((_Myvec*)(this->_Getmycont()))->_Mylast &&
                  _Myptr + _Off >= ((_Myvec*)(this->_Getmycont()))->_Myfirst))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        _Myptr += _Off;
        return (*this);
    }
    _Myt operator+(difference_type _Off) const
    {
        _Myt _Tmp = *this;
        return (_Tmp += _Off);
    }
    _Myt& operator-=(difference_type _Off)
    {
        return (*this += -_Off);
    }
    _Myt operator-(difference_type _Off) const
    {
        _Myt _Tmp = *this;
        return (_Tmp -= _Off);
    }
    difference_type operator-(const _Myt& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        return (_Myptr - _Right._Myptr);
    }
    reference operator[](difference_type _Off) const
    {
        return (*(*this + _Off));
    }
    bool operator==(const _Myt& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    bool operator<(const _Myt& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        return (_Myptr < _Right._Myptr);
    }
    bool operator>(const _Myt& _Right) const
    {
        return (_Right < *this);
    }
    bool operator<=(const _Myt& _Right) const
    {
        return (!(_Right < *this));
    }
    bool operator>=(const _Myt& _Right) const
    {
        return (!(*this < _Right));
    }
    static void _Xlen();
    static void _Xran();
    static void _Xinvarg();
    _Tptr _Myptr;
};
template <class _Ty, class _Alloc>
inline _Vector_const_iterator<_Ty, _Alloc> operator+(typename _Vector_const_iterator<_Ty, _Alloc>::difference_type _Off,
                                                     _Vector_const_iterator<_Ty, _Alloc> _Next)
{
    return (_Next += _Off);
}
template <class _Ty, class _Alloc> class _Vector_iterator : public _Vector_const_iterator<_Ty, _Alloc>
{
  public:
    typedef _Vector_iterator<_Ty, _Alloc> _Myt;
    typedef _Vector_const_iterator<_Ty, _Alloc> _Mybase;
    typedef random_access_iterator_tag iterator_category;
    typedef _Ty value_type;
    typedef typename _Alloc::difference_type difference_type;
    typedef typename _Alloc::pointer pointer;
    typedef typename _Alloc::reference reference;
    typedef pointer _Checked_iterator_base_type;
    _Checked_iterator_base_type _Checked_iterator_base() const
    {
        return (this->_Myptr);
    }
    void _Checked_iterator_assign_from_base(_Checked_iterator_base_type _Base)
    {
        this->_Myptr = _Base;
    }
    _Vector_iterator()
    {}
    _Vector_iterator(pointer _Ptr, const _Container_base* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
    reference operator*() const
    {
        return ((reference) * *(_Mybase*)this);
    }
    pointer operator->() const
    {
        return (&**this);
    }
    _Myt& operator++()
    {
        ++(*(_Mybase*)this);
        return (*this);
    }
    _Myt operator++(int)
    {
        _Myt _Tmp = *this;
        ++*this;
        return (_Tmp);
    }
    _Myt& operator--()
    {
        --(*(_Mybase*)this);
        return (*this);
    }
    _Myt operator--(int)
    {
        _Myt _Tmp = *this;
        --*this;
        return (_Tmp);
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
    _Myt& operator-=(difference_type _Off)
    {
        return (*this += -_Off);
    }
    _Myt operator-(difference_type _Off) const
    {
        _Myt _Tmp = *this;
        return (_Tmp -= _Off);
    }
    difference_type operator-(const _Mybase& _Right) const
    {
        return (*(_Mybase*)this - _Right);
    }
    reference operator[](difference_type _Off) const
    {
        return (*(*this + _Off));
    }
};
template <class _Ty, class _Alloc>
inline _Vector_iterator<_Ty, _Alloc> operator+(typename _Vector_iterator<_Ty, _Alloc>::difference_type _Off,
                                               _Vector_iterator<_Ty, _Alloc> _Next)
{
    return (_Next += _Off);
}
template <class _Ty, class _Alloc> class _Vector_val : public _Container_base_aux_alloc_real<_Alloc>
{
  protected:
    _Vector_val(_Alloc _Al = _Alloc()) : _Container_base_aux_alloc_real<_Alloc>(_Al), _Alval(_Al)
    {}
    typedef typename _Alloc::template rebind<_Ty>::other _Alty;
    _Alty _Alval;
};
template <class _Ty, class _Ax> class vector : public _Vector_val<_Ty, _Ax>
{
  public:
    typedef vector<_Ty, _Ax> _Myt;
    typedef _Vector_val<_Ty, _Ax> _Mybase;
    typedef typename _Mybase::_Alty _Alloc;
    typedef _Alloc allocator_type;
    typedef typename _Alloc::size_type size_type;
    typedef typename _Alloc::difference_type _Dift;
    typedef _Dift difference_type;
    typedef typename _Alloc::pointer _Tptr;
    typedef typename _Alloc::const_pointer _Ctptr;
    typedef _Tptr pointer;
    typedef _Ctptr const_pointer;
    typedef typename _Alloc::reference _Reft;
    typedef _Reft reference;
    typedef typename _Alloc::const_reference const_reference;
    typedef typename _Alloc::value_type value_type;
    typedef _Vector_iterator<_Ty, _Alloc> iterator;
    typedef _Vector_const_iterator<_Ty, _Alloc> const_iterator;
    friend class _Vector_const_iterator<_Ty, _Alloc>;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    vector() : _Mybase()
    {
        _Buy(0);
    }
    explicit vector(const _Alloc& _Al) : _Mybase(_Al)
    {
        _Buy(0);
    }
    explicit vector(size_type _Count) : _Mybase()
    {
        _Construct_n(_Count, _Ty());
    }
    vector(size_type _Count, const _Ty& _Val) : _Mybase()
    {
        _Construct_n(_Count, _Val);
    }
    vector(size_type _Count, const _Ty& _Val, const _Alloc& _Al) : _Mybase(_Al)
    {
        _Construct_n(_Count, _Val);
    }
    vector(const _Myt& _Right) : _Mybase(_Right._Alval)
    {
        if (_Buy(_Right.size()))
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
    template <class _Iter> vector(_Iter _First, _Iter _Last) : _Mybase()
    {
        _Construct(_First, _Last, _Iter_cat(_First));
    }
    template <class _Iter> vector(_Iter _First, _Iter _Last, const _Alloc& _Al) : _Mybase(_Al)
    {
        _Construct(_First, _Last, _Iter_cat(_First));
    }
    template <class _Iter> void _Construct(_Iter _Count, _Iter _Val, _Int_iterator_tag)
    {
        size_type _Size = (size_type)_Count;
        _Construct_n(_Size, (_Ty)_Val);
    }
    template <class _Iter> void _Construct(_Iter _First, _Iter _Last, input_iterator_tag)
    {
        _Buy(0);
        try
        {
            insert(begin(), _First, _Last);
        }
        catch (...)
        {
            _Tidy();
            throw;
        }
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
    _Myt& operator=(const _Myt& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
                clear();
            else if (_Right.size() <= size())
            {
                pointer _Ptr = ::stdext::unchecked_copy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                pointer _Ptr = _Right._Myfirst + size();
                ::stdext::unchecked_copy(_Right._Myfirst, _Ptr, _Myfirst);
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
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
        return (*this);
    }
    void reserve(size_type _Count)
    {
        if (max_size() < _Count)
            _Xlen();
        else if (capacity() < _Count)
        {
            pointer _Ptr = this->_Alval.allocate(_Count);
            try
            {
                _Umove(begin(), end(), _Ptr);
            }
            catch (...)
            {
                this->_Alval.deallocate(_Ptr, _Count);
                throw;
            }
            size_type _Size = size();
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            _Myend = _Ptr + _Count;
            _Mylast = _Ptr + _Size;
            _Myfirst = _Ptr;
        }
    }
    size_type capacity() const
    {
        return (_Myfirst == 0 ? 0 : _Myend - _Myfirst);
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
    const_iterator end() const
    {
        return (const_iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    reverse_iterator rbegin()
    {
        return (reverse_iterator(end()));
    }
    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(end()));
    }
    reverse_iterator rend()
    {
        return (reverse_iterator(begin()));
    }
    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(begin()));
    }
    void resize(size_type _Newsize)
    {
        resize(_Newsize, _Ty());
    }
    void resize(size_type _Newsize, _Ty _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    size_type max_size() const
    {
        return (this->_Alval.max_size());
    }
    bool empty() const
    {
        return (size() == 0);
    }
    _Alloc get_allocator() const
    {
        return (this->_Alval);
    }
    const_reference at(size_type _Pos) const
    {
        if (size() <= _Pos)
            _Xran();
        return (*(begin() + _Pos));
    }
    reference at(size_type _Pos)
    {
        if (size() <= _Pos)
            _Xran();
        return (*(begin() + _Pos));
    }
    const_reference operator[](size_type _Pos) const
    {
        {
            if (!(_Pos < size()))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        return (*(_Myfirst + _Pos));
    }
    reference operator[](size_type _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                ((void)0);
                ::FUN_00ec7c56();
            };
        };
        return (*(_Myfirst + _Pos));
    }
    reference front()
    {
        return (*begin());
    }
    const_reference front() const
    {
        return (*begin());
    }
    reference back()
    {
        return (*(end() - 1));
    }
    const_reference back() const
    {
        return (*(end() - 1));
    }
    void push_back(const _Ty& _Val)
    {
        if (size() < capacity())
            _Mylast = _Ufill(_Mylast, 1, _Val);
        else
            insert(end(), _Val);
    }
    void pop_back()
    {
        if (!empty())
        {
            _Destroy(_Mylast - 1, _Mylast);
            --_Mylast;
        }
    }
    template <class _Iter> void assign(_Iter _First, _Iter _Last)
    {
        _Assign(_First, _Last, _Iter_cat(_First));
    }
    template <class _Iter> void _Assign(_Iter _Count, _Iter _Val, _Int_iterator_tag)
    {
        _Assign_n((size_type)_Count, (_Ty)_Val);
    }
    template <class _Iter> void _Assign(_Iter _First, _Iter _Last, input_iterator_tag)
    {
        erase(begin(), end());
        insert(begin(), _First, _Last);
    }
    void assign(size_type _Count, const _Ty& _Val)
    {
        _Assign_n(_Count, _Val);
    }
    iterator insert(const_iterator _Where, const _Ty& _Val)
    {
        size_type _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, (size_type)1, _Val);
        return (begin() + _Off);
    }
    void insert(const_iterator _Where, size_type _Count, const _Ty& _Val)
    {
        _Insert_n(_Where, _Count, _Val);
    }
    template <class _Iter> void insert(const_iterator _Where, _Iter _First, _Iter _Last)
    {
        _Insert(_Where, _First, _Last, _Iter_cat(_First));
    }
    template <class _Iter> void _Insert(const_iterator _Where, _Iter _First, _Iter _Last, _Int_iterator_tag)
    {
        _Insert_n(_Where, (size_type)_First, (_Ty)_Last);
    }
    template <class _Iter> void _Insert(const_iterator _Where, _Iter _First, _Iter _Last, input_iterator_tag)
    {
        if (_First != _Last)
        {
            size_type _Oldsize = size();
            size_type _Whereoff = _Where._Myptr - _Myfirst;
            for (; _First != _Last; ++_First)
                _Insert_n(end(), (size_type)1, (value_type)*_First);
            _Reverse(_Myfirst + _Whereoff, _Myfirst + _Oldsize);
            _Reverse(_Myfirst + _Oldsize, _Mylast);
            _Reverse(_Myfirst + _Whereoff, _Mylast);
        }
    }
    template <class _Iter> void _Insert(const_iterator _Where, _Iter _First, _Iter _Last, forward_iterator_tag)
    {
        size_type _Count = 0;
        _Distance(_First, _Last, _Count);
        size_type _Capacity = capacity();
        if (_Count == 0)
            ;
        else if (max_size() - size() < _Count)
            _Xlen();
        else if (_Capacity < size() + _Count)
        {
            _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
            if (_Capacity < size() + _Count)
                _Capacity = size() + _Count;
            pointer _Newvec = this->_Alval.allocate(_Capacity);
            pointer _Ptr = _Newvec;
            try
            {
                _Ptr = _Umove(_Myfirst, (_Where)._Myptr, _Newvec);
                _Ptr = _Ucopy(_First, _Last, _Ptr);
                _Umove((_Where)._Myptr, _Mylast, _Ptr);
            }
            catch (...)
            {
                _Destroy(_Newvec, _Ptr);
                this->_Alval.deallocate(_Newvec, _Capacity);
                throw;
            }
            _Count += size();
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            _Myend = _Newvec + _Capacity;
            _Mylast = _Newvec + _Count;
            _Myfirst = _Newvec;
        }
        else
        {
            _Ucopy(_First, _Last, _Mylast);
            _Reverse(_Where._Myptr, _Mylast);
            _Reverse(_Mylast, _Mylast + _Count);
            _Reverse(_Where._Myptr, _Mylast + _Count);
            _Mylast += _Count;
        }
    }
    void _Reverse(pointer _First, pointer _Last)
    {
        for (; _First != _Last && _First != --_Last; ++_First)
            ::std::_Swap_adl(*_First, *_Last);
    }
    iterator erase(const_iterator _Where)
    {
        ::stdext::unchecked_copy((_Where)._Myptr + 1, _Mylast, (_Where)._Myptr);
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
            pointer _Ptr = ::stdext::unchecked_copy((_Last)._Myptr, _Mylast, (_First)._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void swap(_Myt& _Right)
    {
        if (this == &_Right)
            ;
        else if (this->_Alval == _Right._Alval)
        {
            this->_Swap_aux(_Right);
            ::std::swap(_Myfirst, _Right._Myfirst);
            ::std::swap(_Mylast, _Right._Mylast);
            ::std::swap(_Myend, _Right._Myend);
        }
        else
        {
            this->_Swap_aux(_Right);
            _Myt _Ts = *this;
            *this = _Right;
            _Right = _Ts;
        }
    }

  protected:
    void _Assign_n(size_type _Count, const _Ty& _Val)
    {
        _Ty _Tmp = _Val;
        erase(begin(), end());
        insert(begin(), _Count, _Tmp);
    }
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
    template <class _Iter> pointer _Ucopy(_Iter _First, _Iter _Last, pointer _Ptr)
    {
        return (::stdext::unchecked_uninitialized_copy(_First, _Last, _Ptr, this->_Alval));
    }
    template <class _Iter> pointer _Umove(_Iter _First, _Iter _Last, pointer _Ptr)
    {
        return (::stdext::_Unchecked_uninitialized_move(_First, _Last, _Ptr, this->_Alval));
    }
    void _Insert_n(const_iterator _Where, size_type _Count, const _Ty& _Val)
    {
        size_type _Capacity = capacity();
        if (_Count == 0)
            ;
        else if (max_size() - size() < _Count)
            _Xlen();
        else if (_Capacity < size() + _Count)
        {
            _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
            if (_Capacity < size() + _Count)
                _Capacity = size() + _Count;
            pointer _Newvec = this->_Alval.allocate(_Capacity);
            size_type _Whereoff = (_Where)._Myptr - _Myfirst;
            int _Ncopied = 0;
            try
            {
                _Ufill(_Newvec + _Whereoff, _Count, _Val);
                ++_Ncopied;
                _Umove(this->_Myfirst, (_Where)._Myptr, _Newvec);
                ++_Ncopied;
                _Umove((_Where)._Myptr, this->_Mylast, _Newvec + (_Whereoff + _Count));
            }
            catch (...)
            {
                if (1 < _Ncopied)
                    _Destroy(_Newvec, _Newvec + _Whereoff);
                if (0 < _Ncopied)
                    _Destroy(_Newvec + _Whereoff, _Newvec + _Whereoff + _Count);
                this->_Alval.deallocate(_Newvec, _Capacity);
                throw;
            }
            _Count += size();
            if (_Myfirst != 0)
            {
                _Destroy(_Myfirst, _Mylast);
                this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            _Myend = _Newvec + _Capacity;
            _Mylast = _Newvec + _Count;
            _Myfirst = _Newvec;
        }
        else if ((size_type)(_Mylast - (_Where)._Myptr) < _Count)
        {
            _Ty _Tmp = _Val;
            _Umove((_Where)._Myptr, _Mylast, (_Where)._Myptr + _Count);
            try
            {
                _Ufill(_Mylast, _Count - (_Mylast - (_Where)._Myptr), _Tmp);
            }
            catch (...)
            {
                _Destroy((_Where)._Myptr + _Count, _Mylast + _Count);
                throw;
            }
            _Mylast += _Count;
            std::fill((_Where)._Myptr, _Mylast - _Count, _Tmp);
        }
        else
        {
            _Ty _Tmp = _Val;
            pointer _Oldend = _Mylast;
            _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
            ::stdext::_Unchecked_move_backward((_Where)._Myptr, _Oldend - _Count, _Oldend);
            std::fill((_Where)._Myptr, (_Where)._Myptr + _Count, _Tmp);
        }
    }
    pointer _Ufill(pointer _Ptr, size_type _Count, const _Ty& _Val)
    {
        ::stdext::unchecked_uninitialized_fill_n(_Ptr, _Count, _Val, this->_Alval);
        return (_Ptr + _Count);
    }
    static void _Xlen();
    static void _Xran();
    static void _Xinvarg();
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};

}
struct VectorSet
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short count, unk22;
    int unk24;
    std::vector<unsigned int> values;
    std::vector<std::vector<unsigned short> > first;
    std::vector<std::vector<unsigned int> > second;
    void FUN_00b2fb30(unsigned short size);
};
// @fnv 0x00b2fb30
void VectorSet::FUN_00b2fb30(unsigned short size)
{
    first.clear();
    second.clear();
    values.clear();
    count = size;
    first.resize(size);
    second.resize(size);
    values.resize(size);
    for (int i = 0; i < size; ++i)
        values[i] = 0;
}

template <class T> struct CheckedVector
{
    void* proxy;
    unsigned int allocator;
    unsigned int state;
    T* first;
    T* last;
    T* limit;
};
struct CheckedUnsignedShortVector : CheckedVector<unsigned short>
{
    void FUN_00b337f0(unsigned int count, unsigned short value);
};
struct IntVector : CheckedVector<unsigned int>
{
    void FUN_00b333e0(unsigned int count, unsigned int value);
};
struct Target
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
    unsigned short rows;
    unsigned short columns;
    CheckedVector<unsigned int> counts;
    CheckedVector<CheckedUnsignedShortVector> shorts;
    CheckedVector<IntVector> values;
    void FUN_00b2fdc0(unsigned short index, unsigned int value, unsigned short amount);
};
__forceinline unsigned int& SlotRef(unsigned int& r)
{
    return r;
}
// @fnv 0x00b2fdc0
void Target::FUN_00b2fdc0(unsigned short index, unsigned int value, unsigned short amount)
{
    {
        unsigned int position = index;
        CheckedVector<CheckedUnsignedShortVector>* count = &shorts;
        if (position >= (unsigned int)(count->last - count->first))
            FUN_00ec7c56();
        unsigned int row = columns + 1;
        CheckedUnsignedShortVector* vector = &count->first[position];
        vector->FUN_00b337f0(row, 0);
    }
    {
        unsigned int position = index;
        CheckedVector<CheckedUnsignedShortVector>* count = &shorts;
        if (position >= (unsigned int)(count->last - count->first))
            FUN_00ec7c56();
        CheckedUnsignedShortVector* vector = &count->first[position];
        unsigned int row = columns;
        if (row >= (unsigned int)(vector->last - vector->first))
            FUN_00ec7c56();
        vector->first[row] = amount;
    }
    {
        unsigned int position = index;
        CheckedVector<IntVector>* count = &values;
        if (position >= (unsigned int)(count->last - count->first))
            FUN_00ec7c56();
        {
            unsigned int cache0;
            unsigned int cache1;
            unsigned int cache2;
            unsigned int cache3;
            unsigned int cache4;
            unsigned int cache5;
            unsigned int cache6;
            unsigned int cache7;
            unsigned int cache8;
            unsigned int cache9;
            unsigned int cache10;
            unsigned int cache11;
            unsigned int cache12;
            unsigned int cache13;
            unsigned int cache14;
            unsigned int cache15;
            unsigned int cache16;
            unsigned int cache17;
            unsigned int cache18;
            unsigned int cache19;
            unsigned int cache20;
            {
                unsigned int row = columns + 1;
                IntVector* vector = &count->first[position];
                vector->FUN_00b333e0(row, 0);
            }
        }
    }
    {
        unsigned int position = index;
        CheckedVector<IntVector>* count = &values;
        if (position >= (unsigned int)(count->last - count->first))
            FUN_00ec7c56();
        IntVector* vector = &count->first[position];
        unsigned int row = columns;
        if (row >= (unsigned int)(vector->last - vector->first))
            FUN_00ec7c56();
        vector->first[row] = value;
    }
    {
        unsigned int position = index;
        CheckedVector<unsigned int>* count = &counts;
        if (position >= (unsigned int)(count->last - count->first))
            FUN_00ec7c56();
        SlotRef(count->first[position]) += amount - 2;
    }
}

struct S00b30660_Obj
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
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FloatVec m_vec;

    void FUN_00b30660(const float* p);
};

inline void S00b30660_Push(FloatVec& v, const float& x)
{
    int t00;
    int t01;
    int t02;
    int t03;
    int t04;
    int t05;
    int t06;
    int t07;
    int t08;
    int t09;
    int t10;
    int t11;
    int t12;
    int t13;
    int t14;
    int t15;
    int t16;
    int t17;
    int t18;
    int t19;
    int t20;
    int t21;
    int t22;
    int t23;
    int t24;
    int t25;
    v.PushBack(x);
}

// @fnv 0x00b30660
void S00b30660_Obj::FUN_00b30660(const float* p)
{
    float f7 = p[0];
    float f1 = p[1];
    float f2 = p[2];

    S00b30660_Push(m_vec, f7);
    S00b30660_Push(m_vec, f1);
    S00b30660_Push(m_vec, f2);
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
class FUN_00b30730_Tree
{
  public:
    int* FUN_00b30730(unsigned short usIndex);
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
    vectorS<vectorS<int> > m_kLists;
};

// @fnv 0x00b30730
int* FUN_00b30730_Tree::FUN_00b30730(unsigned short usIndex)
{
    return m_kLists[usIndex].size() ? &m_kLists[usIndex][0] : 0;
}

typedef unsigned short U16;
typedef unsigned int U32;
void* __cdecl operator new[](U32 bytes);
unsigned int __cdecl FUN_00ec7c56();
void* __cdecl FUN_00ec44d0(void* dest, const void* src, U32 length);
extern unsigned char* DAT_011f8d88;
template <class T> struct DataVector
{
    U32 metadata00;
    U32 metadata04;
    U32 metadata08;
    T* first;
    T* last;
    T* reserved;
    __forceinline U32 size() const
    {
        return (U32)(last - first);
    }
    __forceinline T& operator[](U32 i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return first[i];
    }
};
struct Matrix4
{
    float m[4][4];
};
struct Vec3
{
    float x, y, z;
    __forceinline Vec3()
    {
        x = y = z = 0.0f;
    }
    __forceinline Vec3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    __forceinline void Set(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    __forceinline float& operator[](int i)
    {
        return (&x)[i];
    }
    inline Vec3 FUN_00b05000(const Matrix4* matrix)
    {
        float ax = matrix->m[0][0] * x + matrix->m[1][0] * y + matrix->m[2][0] * z + matrix->m[3][0];
        float ay = matrix->m[0][1] * x + matrix->m[1][1] * y + matrix->m[2][1] * z + matrix->m[3][1];
        float az = matrix->m[0][2] * x + matrix->m[1][2] * y + matrix->m[2][2] * z + matrix->m[3][2];
        return Vec3(ax, ay, az);
    }
};
struct VertexCountRow
{
    DataVector<U16> counts;
};
struct VertexIndexRow
{
    DataVector<U16*> indices;
};
struct GeometryProcessor
{
    U32 unk00, unk04, unk08;
    unsigned char* processedVertices;
    U16 unk10;
    unsigned char initialized;
    unsigned char unk13;
    U32 unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    DataVector<VertexCountRow> vertexCounts;
    DataVector<VertexIndexRow> vertexIndices;
    DataVector<U32> extra70;
    DataVector<float> outputPositions;
    DataVector<float> originalPositions;
    DataVector<U32> extraB8, extraD0, extraE8, extra100, extra118, extra130, extra148;
    DataVector<float> blendFactors;
    DataVector<unsigned char> transformIndices;
    inline U16 FUN_00b0a9a0(short index)
    {
        return index > -1 ? (U16)vertexIndices[index].indices.size() : 0;
    }
    __forceinline unsigned char GetInitialized() const
    {
        return initialized;
    }
    unsigned char FUN_00b30800(U16 index);
};
__forceinline Matrix4* Matrix(U16 pose)
{
    return (Matrix4*)(DAT_011f8d88 + (U32)pose * 64);
}
__forceinline float Blend(float original, float target, float factor)
{
    return original + (target - original) * factor;
}
// @fnv 0x00b30800
unsigned char GeometryProcessor::FUN_00b30800(U16 index)
{
    unsigned char changed = 0;
    if (!GetInitialized())
    {
        U16 vertexCountVal = (U16)(outputPositions.size() / 3);
        if (!processedVertices)
            processedVertices = new unsigned char[vertexCountVal];
        for (int vertex8 = 0; vertex8 < vertexCountVal; ++vertex8)
            processedVertices[vertex8] = 0;
        Vec3 transformed;
        Vec3 _interpolatedPosition;
        for (int group4 = 0; group4 < FUN_00b0a9a0(index); ++group4)
        {
            for (int kEntry = 0; kEntry < vertexCounts[index].counts[group4]; ++kEntry)
            {
                U16 vertexId = vertexIndices[index].indices[group4][kEntry];
                if (!processedVertices[vertexId])
                {
                    float factor5 = blendFactors[vertexId];
                    Vec3* original = (Vec3*)(&originalPositions[0] + vertexId * 3);
                    transformed.Set(original->x, original->y, original->z);
                    U16 pose3 = transformIndices[vertexId];
                    transformed = transformed.FUN_00b05000(Matrix(pose3));
                    _interpolatedPosition.Set(Blend(original->x, transformed[0], factor5),
                                              Blend(original->y, transformed[1], factor5),
                                              Blend(original->z, transformed[2], factor5));
                    FUN_00ec44d0((Vec3*)(&outputPositions[0] + vertexId * 3), &_interpolatedPosition, 12);
                    processedVertices[vertexId] = 1;
                }
            }
        }
        initialized = 1;
        changed = 1;
    }
    return changed;
}

unsigned int __cdecl FUN_00ec7c56(void);

struct Al
{
};

struct BaseAux
{
    void* aux;
};

struct BaseAlloc : BaseAux
{
    Al alaux;
};

struct VecVal : BaseAlloc
{
    Al alval;
};

struct Vec;

struct IterBase
{
    void* aux;
    IterBase() : aux(0)
    {}
    void SetContainer(const BaseAux* c)
    {
        aux = c->aux;
    }
};

struct CIter : IterBase
{
    int* ptr;
    CIter(int* p, const Vec* v);
};

struct Iter : CIter
{
    Iter(int* p, const Vec* v);
};

struct Vec : VecVal
{
    int* first;
    int* last;
    int* fin;
    Iter begin();
    Iter end();
    inline CIter FUN_00b33030(CIter a, CIter b);
    void FUN_00b32120();
};

inline CIter::CIter(int* p, const Vec* v)
{
    {
        if (!(v != 0 && v->first <= p && p <= v->last))
        {
            FUN_00ec7c56();
        }
    }
    SetContainer(v);
    ptr = p;
}

inline Iter::Iter(int* p, const Vec* v) : CIter(p, v)
{}

inline Iter Vec::begin()
{
    return Iter(first, this);
}

inline Iter Vec::end()
{
    return Iter(last, this);
}

inline CIter Vec::FUN_00b33030(CIter a, CIter b)
{
    int s0, s1, s2, s3, s4, s5, s6, s7;
    int t0, t1, t2, t3, t4, t5, t6, t7;
    int u0, u1, u2, u3, u4, u5, u6, u7;
    int v0, v1, v2, v3, v4;
    s0 = (int)a.ptr;
    s1 = (int)b.ptr;
    s2 = s0 + s1;
    s3 = s2 + 1;
    s4 = s3 + 2;
    s5 = s4 + 3;
    s6 = s5 + 4;
    s7 = s6 + 5;
    t0 = s7 + 6;
    t1 = t0 + 7;
    t2 = t1 + 8;
    t3 = t2 + 9;
    t4 = t3 + 1;
    t5 = t4 + 1;
    t6 = t5 + 1;
    t7 = t6 + 1;
    u0 = t7 + 1;
    u1 = u0 + 1;
    u2 = u1 + 1;
    u3 = u2 + 1;
    u4 = u3 + 1;
    u5 = u4 + 1;
    u6 = u5 + 1;
    u7 = u6 + 1;
    v0 = u7 + 1;
    v1 = v0 + 1;
    v2 = v1 + 1;
    v3 = v2 + 1;
    v4 = v3 + 1;
    if (a.ptr != b.ptr)
    {
        fin = (int*)(s0 + t0 + u0 + v4);
    }
    return a;
}

// @fnv 0x00b32120
void Vec::FUN_00b32120()
{
    FUN_00b33030(begin(), end());
}

struct ScalarAllocator
{
    __forceinline void deallocate(unsigned int* _Ptr, unsigned int)
    {
        FormHeap_Free(_Ptr);
    }
};

unsigned int* __cdecl FUN_00b42e50(unsigned int*, unsigned int*, unsigned int*);
unsigned int* __cdecl FUN_00b177e0(unsigned int*, unsigned int*, unsigned int*, ScalarAllocator&);
__forceinline ScalarTag PtrCatQ(unsigned int*&, unsigned int*&)
{
    ScalarTag _Cat;
    return (_Cat);
}
__forceinline void DestroyRange4Q(unsigned int*, unsigned int*, ScalarAllocator&, ScalarTag)
{}
__forceinline void DestroyRangeQ(unsigned int* _First, unsigned int* _Last, ScalarAllocator& _Al)
{
    DestroyRange4Q(_First, _Last, _Al, PtrCatQ(_First, _Last));
}
struct VectorStorage
{
    int unk00;
    int unk04;
    ScalarAllocator allocator;
    unsigned int* first;
    unsigned int* last;
    unsigned int* end;
    bool ResizeArray(unsigned int);
    void FUN_00b32350();
    __forceinline unsigned int size() const
    {
        return (last - first);
    }
    __forceinline unsigned int capacity() const
    {
        return (first == 0 ? 0 : end - first);
    }
    __forceinline void DestroyQ(unsigned int* _First, unsigned int* _Last)
    {
        DestroyRangeQ(_First, _Last, allocator);
    }
    __forceinline unsigned int* UcopyQ(unsigned int* _First, unsigned int* _Last, unsigned int* _Ptr)
    {
        return FUN_00b177e0(_First, _Last, _Ptr, allocator);
    }
    VectorStorage& FUN_00b36330(const VectorStorage& _Right);
};
__forceinline void HA()
{
    int HA_0;
    int HA_1;
    int HA_2;
    int HA_3;
    int HA_4;
    int HA_5;
    int HA_6;
    int HA_7;
    int HA_8;
    int HA_9;
    int HA_10;
    int HA_11;
}
__forceinline void HB()
{
    int HB_0;
    int HB_1;
    int HB_2;
    int HB_3;
    int HB_4;
    int HB_5;
    int HB_6;
    int HB_7;
    char HBc0;
}
__forceinline void HB2()
{
    char HB2c;
}
__forceinline void HC()
{
    int HC_0;
    int HC_1;
    int HC_2;
    int HC_3;
    int HC_4;
    int HC_5;
    int HC_6;
    int HC_7;
    int HC_8;
    int HC_9;
    int HC_10;
    int HC_11;
    int HC_12;
    int HC_13;
    int HC_14;
    int HC_15;
    int HC_16;
}
__forceinline void HD()
{
    int HD_0;
    int HD_1;
    int HD_2;
    int HD_3;
    int HD_4;
    int HD_5;
    int HD_6;
    int HD_7;
    int HD_8;
    int HD_9;
    int HD_10;
    int HD_11;
    int HD_12;
    int HD_13;
    int HD_14;
    int HD_15;
    int HD_16;
    int HD_17;
    int HD_18;
    int HD_19;
    int HD_20;
    int HD_21;
    int HD_22;
    int HD_23;
    int HD_24;
    int HD_25;
    int HD_26;
    int HD_27;
    int HD_28;
    int HD_29;
    int HD_30;
    int HD_31;
    int HD_32;
    int HD_33;
}
// @fnv 0x00b36330
VectorStorage& VectorStorage::FUN_00b36330(const VectorStorage& _Right)
{
    if (this != &_Right)
    {
        HA();
        if (_Right.size() == 0)
            FUN_00b32350();
        else if (_Right.size() <= size())
        {
            HB();
            HB2();
            unsigned int* _Ptr = FUN_00b42e50(_Right.first, _Right.last, first);
            DestroyQ(_Ptr, last);
            last = first + _Right.size();
        }
        else if (_Right.size() <= capacity())
        {
            HC();
            unsigned int* _Ptr = _Right.first + size();
            FUN_00b42e50(_Right.first, _Ptr, first);
            last = UcopyQ(_Ptr, _Right.last, last);
        }
        else
        {
            if (first != 0)
            {
                DestroyQ(first, last);
                allocator.deallocate(first, end - first);
            }
            if (ResizeArray(_Right.size()))
            {
                HD();
                last = UcopyQ(_Right.first, _Right.last, first);
            }
        }
    }
    return (*this);
}

#include <stdlib.h>
namespace fnv_00b2af80 {
extern "C" __int64 __cdecl _time64(__int64*);
struct ArrayElement
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ArrayElement();
    ~ArrayElement();
};
struct Components
{
    float data[3];
    __forceinline float& operator[](unsigned n)
    {
        return data[n];
    }
    __forceinline float operator[](unsigned n) const
    {
        return data[n];
    }
};
struct Record
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    Components original;
    Components scaled;
};
enum Component
{
    X = 0,
    Y = 1,
    Z = 2
};
template <class T> struct LocalVector
{
    int unk00, unk04, unk08;
    T* first;
    T* last;
    T* end;
    __forceinline unsigned size() const
    {
        return last - first;
    }
    __forceinline T& operator[](unsigned n)
    {
        if (n >= unsigned(last - first))
            FUN_00ec7c56();
        return first[n];
    }
};
struct Float3
{
    float x, y, z;
    Float3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix(float a, float b, float c, float d, float e, float f, float g, float h, float i)
        : m00(a), m01(b), m02(c), m10(d), m11(e), m12(f), m20(g), m21(h), m22(i)
    {}
};
struct RandomState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    void FUN_00b3f160(int);
    float FUN_00b3f130(float, float);
};
struct RenderObject
{
    void FUN_00b2fb30(unsigned short);
    void FUN_00b306d0(unsigned short);
};
struct StateVector;
struct StateIterator
{
    void* owner;
    int* current;
    inline StateIterator(int*, StateVector*);
    inline StateIterator(const StateIterator& i) : owner(i.owner), current(i.current)
    {}
};
struct StateVector
{
    void* proxy;
    int unk04, unk08;
    int* first;
    int* last;
    int* end;
    inline StateIterator begin()
    {
        StateIterator it(first, this);
        return it;
    }
    inline StateIterator finish()
    {
        StateIterator it(last, this);
        return it;
    }
    StateIterator FUN_00b335c0(StateIterator, StateIterator);
    inline void FUN_00b32350()
    {
        StateIterator stop = finish();
        StateIterator start = begin();
        FUN_00b335c0(start, stop);
    }
    void FUN_00b15390(const int&);
};
inline StateIterator::StateIterator(int* p, StateVector* v) : owner(0)
{
    if (!v || p < v->first || p > v->last)
        FUN_00ec7c56();
    owner = v->proxy;
    current = p;
}
extern unsigned char DAT_011ad148;
extern int DAT_011ad14c;
extern StateVector DAT_011f8c50;
extern void* DAT_011f8bf4;
extern int DAT_011f8bfc;
inline void SetEnabled(unsigned char enabled)
{
    DAT_011ad148 = enabled;
}
inline void SetMode(int mode)
{
    DAT_011ad14c = mode;
}
inline void SetRandomSeed(int seed)
{
    DAT_011f8bfc = seed;
}
inline void AddValue(int item)
{
    DAT_011f8c50.FUN_00b15390(item);
}
inline int ShortCount(int count)
{
    return count;
}
struct Renderer
{
    int unk00;
    float unk04;
    int unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24;
    unsigned short unk28;
    int unk2c;
    float unk30, unk34;
    int unk38, unk3c, unk40;
    int unk44, unk48, unk4c;
    Renderer(int);
    void FUN_00b11050(int, float, int, void*, float, float, const Matrix&, const Float3&, RenderObject*, void*, float,
                      int, float);
};
struct Target
{
    int unk00;
    Float3 position;
    int unk10, unk14, unk18, unk1c;
    RandomState random;
    int seed;
    float center, range;
    unsigned randomSeed;
    Renderer* renderer;
    RenderObject* object;
    LocalVector<int> values;
    int count;
    Float3 offset;
    int unk88, unk8c, unk90;
    int unk94, unk98, unk9c, unkA0;
    LocalVector<Record> records;
    int unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    unsigned capacity;
    int unkdc, unke0, unke4, unke8;
    ArrayElement* elements;
    bool flag;
    int unkf4, unkf8, unkfc, unk100, unk104;
    int mode;
    void FUN_00b2c130();
    void FUN_00b2c890(float);
    void FUN_00b2af80(float);
};
// @fnv 0x00b2af80
void Target::FUN_00b2af80(float elapsed)
{
    SetEnabled(flag == 0);
    renderer = new Renderer(0);
    if (!flag)
        elements = new ArrayElement[capacity];
    SetMode(mode);
    DAT_011f8c50.FUN_00b32350();
    DAT_011f8bf4 = &unk94;
    for (unsigned i = 0; i < values.size(); ++i)
    {
        AddValue(values[i]);
    }
    random.FUN_00b3f160(seed);
    float value = random.FUN_00b3f130(center - range, center + range);
    srand(randomSeed);
    if (center > 0.0)
    {
        for (unsigned j_ = 0; j_ < records.size(); ++j_)
        {
            Record& record = records[j_];
            record.scaled[X] = (float)(center * record.original[X]);
            record.scaled[Y] = (float)(center * record.original[Y]);
        }
    }
    random.FUN_00b3f160(seed);
    object->FUN_00b2fb30((unsigned short)ShortCount(count));
    object->FUN_00b306d0(0);
    SetRandomSeed(seed);
    {
        renderer->FUN_00b11050(seed, value, 0, &position, 0.0f, 0.0f,
                               Matrix(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f), Float3(0.0f, 0.0f, 1.0f),
                               object, &offset, 1.0f, seed, -1.0f);
    }
    FUN_00b2c130();
    if (!flag)
        FUN_00b2c890(elapsed);
    srand((unsigned)_time64(0));
}
}  // namespace fnv_00b2af80

namespace fnv_00b2c890 {
#include <string.h>

void* operator new(unsigned int);
void FormHeap_Free(void*);
namespace std {
class exception
{
  public:
    exception(const char* const&);
    exception(const exception&);
    virtual ~exception();
    virtual const char* what() const;

  private:
    const char* message;
    int ownsMessage;
};
class bad_alloc : public exception
{
  public:
    bad_alloc(const char* message) throw() : exception(message)
    {}
    virtual ~bad_alloc() throw()
    {}
};
}
template <class T> inline T* AllocateCount(unsigned int count, T*)
{
    if (count <= 0)
        count = 0;
    else if (((unsigned int)(-1) / count) < sizeof(T))
        throw std::bad_alloc(0);
    return (T*)::operator new(count * sizeof(T));
}
template <class T> inline void DestroyElement(T* ptr)
{
    ptr->~T();
}
struct ScalarTag
{
};
struct NonScalarTag
{
};
struct CheckedTag
{
};
struct UnchangedTag
{
};
inline float* CheckedBase(float*& it, UnchangedTag)
{
    return it;
}
inline float* CheckedBase(float*& it)
{
    UnchangedTag tag;
    return CheckedBase(it, tag);
}
struct RandomTag
{
};
inline ScalarTag PtrCat(float*&, float*&)
{
    ScalarTag cat;
    return cat;
}
inline RandomTag IterRandom(float* const&, float* const&)
{
    RandomTag cat;
    return cat;
}
template <class T> struct NativeAllocator
{
    void deallocate(T* ptr, unsigned int)
    {
        FormHeap_Free(ptr);
    }
    T* allocate(unsigned int count)
    {
        return AllocateCount(count, (T*)0);
    }
    unsigned int max_size() const
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return count > 0 ? count : 1;
    }
    void destroy(T* ptr)
    {
        DestroyElement(ptr);
    }
};
template <class T> inline void DestroyRange(T*, T*, NativeAllocator<T>&, ScalarTag)
{}
template <class T> inline void DestroyRange(T* first, T* last, NativeAllocator<T>& al, NonScalarTag)
{
    for (; first != last; ++first)
        al.destroy(first);
}
inline void DestroyRange(float* first, float* last, NativeAllocator<float>& al)
{
    DestroyRange(first, last, al, PtrCat(first, last));
}
inline float* CopyOpt(float* first, float* last, float* dest, RandomTag, ScalarTag, CheckedTag)
{
    int off = last - first;
    float* result = dest + off;
    if (off > 0)
        memmove(dest, first, off * sizeof(float));
    return result;
}
inline float* CopyFloatRange(float* first, float* last, float* dest)
{
    return CopyOpt(CheckedBase(first), CheckedBase(last), dest, IterRandom(first, dest), PtrCat(first, dest),
                   CheckedTag());
}
inline float* UninitCopy(float* first, float* last, float* dest, NativeAllocator<float>&, ScalarTag, CheckedTag)
{
    unsigned int count = last - first;
    float* result = dest + count;
    if (count > 0)
        memmove(dest, first, count * sizeof(float));
    return result;
}
inline float* UncheckedUninitCopy(float* first, float* last, float* dest, NativeAllocator<float>& al)
{
    return UninitCopy(CheckedBase(first), CheckedBase(last), dest, al, PtrCat(first, dest), CheckedTag());
}
struct ContainerAux;
struct AuxCont
{
    const ContainerAux* owner;
};
struct ContainerAux
{
    AuxCont* proxy;
    NativeAllocator<AuxCont> auxAllocator;
    ~ContainerAux()
    {
        proxy->~AuxCont();
        auxAllocator.deallocate(proxy, 1);
    }
};
struct IteratorBase
{
    void* proxy;
    IteratorBase() : proxy(0)
    {}
    void setContainer(const ContainerAux* container)
    {
        proxy = container->proxy;
    }
};
struct ConstFloatIterator : IteratorBase
{
    float* ptr;
    ConstFloatIterator(float*, const ContainerAux*);
};
struct FloatIterator : ConstFloatIterator
{
    FloatIterator(float* ptr, const ContainerAux* owner) : ConstFloatIterator(ptr, owner)
    {}
};
struct FUN_00b355d0 : ContainerAux
{
    NativeAllocator<float> allocator;
    float* first;
    float* last;
    float* end;
    FUN_00b355d0(const FUN_00b355d0&);
    unsigned int size() const
    {
        return last - first;
    }
    unsigned int capacity() const
    {
        return first == 0 ? 0 : end - first;
    }
    FloatIterator begin()
    {
        return FloatIterator(first, this);
    }
    FloatIterator endIterator()
    {
        return FloatIterator(last, this);
    }
    FloatIterator makeIterator(ConstFloatIterator it) const
    {
        return FloatIterator(it.ptr, this);
    }
    FloatIterator erase(ConstFloatIterator firstArgument, ConstFloatIterator lastArgument)
    {
        FloatIterator rangeFirst = makeIterator(firstArgument);
        FloatIterator rangeLast = makeIterator(lastArgument);
        if (rangeFirst.proxy != rangeLast.proxy || rangeFirst.ptr > rangeLast.ptr)
            FUN_00ec7c56();
        if (rangeFirst.ptr != rangeLast.ptr)
        {
            float* ptr = CopyFloatRange(rangeLast.ptr, last, rangeFirst.ptr);
            _Destroy(ptr, last);
            last = ptr;
        }
        return rangeFirst;
    }
    void clear()
    {
        erase(begin(), endIterator());
    }
    void _Destroy(float* start, float* finish)
    {
        DestroyRange(start, finish, allocator);
    }
    void deallocate(float* ptr, unsigned int count)
    {
        allocator.deallocate(ptr, count);
    }
    unsigned int max_size() const
    {
        return allocator.max_size();
    }
    void _Xlen();
    bool _Buy(unsigned int capacity)
    {
        first = 0, last = 0, end = 0;
        if (capacity == 0)
            return false;
        else if (max_size() < capacity)
            _Xlen();
        else
        {
            first = allocator.allocate(capacity);
            last = first;
            end = first + capacity;
        }
        return true;
    }
    float* _Ucopy(float* start, float* finish, float* dest)
    {
        return UncheckedUninitCopy(start, finish, dest, allocator);
    }
    FUN_00b355d0& FUN_00b36330(const FUN_00b355d0& src)
    {
        if (this != &src)
        {
            if (src.size() == 0)
                clear();
            else if (src.size() <= size())
            {
                float* ptr = CopyFloatRange(src.first, src.last, first);
                _Destroy(ptr, last);
                last = first + src.size();
            }
            else if (src.size() <= capacity())
            {
                float* ptr = src.first + size();
                CopyFloatRange(src.first, ptr, first);
                last = _Ucopy(ptr, src.last, last);
            }
            else
            {
                if (first != 0)
                {
                    _Destroy(first, last);
                    allocator.deallocate(first, end - first);
                }
                if (_Buy(src.size()))
                    last = _Ucopy(src.first, src.last, first);
            }
        }
        return *this;
    }
    void FUN_00b17f50()
    {
        if (first != 0)
        {
            _Destroy(first, last);
            allocator.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
    ~FUN_00b355d0()
    {
        FUN_00b17f50();
    }
};
inline ConstFloatIterator::ConstFloatIterator(float* position, const ContainerAux* owner)
{
    const FUN_00b355d0* vector = static_cast<const FUN_00b355d0*>(owner);
    if (owner == 0 || position < vector->first || vector->last < position)
        FUN_00ec7c56();
    setContainer(owner);
    ptr = position;
}
struct Pair
{
    float x;
    float y;
};
inline NonScalarTag PtrCat(Pair*&, Pair*&)
{
    NonScalarTag cat;
    return cat;
}
inline void DestroyRange(Pair* first, Pair* last, NativeAllocator<Pair>& al)
{
    DestroyRange(first, last, al, PtrCat(first, last));
}
struct PairArray : ContainerAux
{
    NativeAllocator<Pair> allocator;
    Pair* first;
    Pair* last;
    Pair* end;
    void _Destroy(Pair* start, Pair* finish)
    {
        DestroyRange(start, finish, allocator);
    }
    void FreeBuffer()
    {
        if (first != 0)
        {
            _Destroy(first, last);
            allocator.deallocate(first, end - first);
        }
        first = 0, last = 0, end = 0;
    }
    ~PairArray()
    {
        FreeBuffer();
    }
};
struct Init : PairArray
{
    float maximum;
    float parameter;
    void* source;
    float stepFactor;
    Init(void*, float, float, float);
    FUN_00b355d0 FUN_00b40b30(FUN_00b355d0);
};
struct Record
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
    float x;
    float y;
    int unk50;
};
struct RecordArray
{
    int unk00;
    int unk04;
    int unk08;
    Record* first;
    Record* last;
    Record* end;
    unsigned int size() const
    {
        return last - first;
    }
    Record& operator[](unsigned int index)
    {
        if (index >= size())
            FUN_00ec7c56();
        return first[index];
    }
};
struct Target
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
    FUN_00b355d0 initial;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    RecordArray records;
    float scale;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int count;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    FUN_00b355d0* values;
    int unkf0;
    int unkf4;
    int unkf8;
    float parameter;
    void FUN_00b2c890(float step);
};
// @fnv 0x00b2c890
void Target::FUN_00b2c890(float step)
{
    float maximum = -1.0f;
    {
        float stepFactor;
        int iteration;
        float dimension;
        Record* currentRecord;
        unsigned int i;
        for (i = 0; i < records.size(); i++)
        {
            currentRecord = &records[i];
            dimension = currentRecord->x > currentRecord->y ? currentRecord->x : currentRecord->y;
            if (maximum < dimension * scale)
                maximum = dimension * scale;
        }
        if (maximum == -1.0)
            maximum = 10.0f;
        if (values)
        {
            values[0].FUN_00b36330(initial);
            for (iteration = 1; iteration < count; iteration++)
            {
                stepFactor = 1.0f + iteration * step;
                Init operation(&unk94, (float)(maximum * 10.0), parameter, stepFactor);
                values[iteration].FUN_00b36330(operation.FUN_00b40b30(values[iteration - 1]));
            }
        }
    }
}
}  // namespace fnv_00b2c890
