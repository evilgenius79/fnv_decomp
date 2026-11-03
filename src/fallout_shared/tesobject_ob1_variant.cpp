
// src/fallout_shared/tesobject_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/tesobject.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "tesobject_decls.h"

extern "C" unsigned __cdecl FUN_00ec6130(const char*);
extern "C" void __cdecl ReportAssertionViolation(const char*, int);
extern unsigned DAT_010173f0;
inline void DeadX()
{
    const char* d_dmji;
    const char* d1;
    const char* d2;
    const char* d_t;
    const char* d4;
    const char* d5;
    const char* d_wovsp;
    const char* d7;
    const char* d8;
    const char* d_yji;
}
inline void Dead4()
{
    const char* e_mwhkwl;
    const char* e1;
    const char* e2;
    const char* e_hei;
}
struct StrX
{
    void* al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned size;
    unsigned res;
    unsigned FUN_00a0c300(const char* p, unsigned off, unsigned n) const;
    StrX Substr(unsigned off, unsigned n) const;
    StrX& AssignSubstring(const StrX& rR_igxcnj, unsigned off, unsigned n);
    void FUN_0044a730(bool b, unsigned n);
    ~StrX()
    {
        FUN_0044a730(true, 0);
    }
    StrX& assign(const StrX& rR_igxcnj)
    {
        return AssignSubstring(rR_igxcnj, 0, DAT_010173f0);
    }
    StrX& operator=(const StrX& rR_igxcnj)
    {
        return assign(rR_igxcnj);
    }
    unsigned rfind(const char* p, unsigned off = DAT_010173f0) const
    {
        return FUN_00a0c300(p, off, LenX(p));
    }
    static unsigned LenX(const char* p)
    {
        return FUN_00ec6130(p);
    }
};
StrX SubX(const StrX& s, unsigned off, unsigned n);
inline const unsigned& GetMaxX(const unsigned& a, const unsigned& b)
{
    return a < b ? b : a;
}
// @fnv 0x00ac6a30
bool __cdecl FUN_00ac6a30(StrX s, StrX* pA, StrX* pB, StrX* pC)
{
    unsigned uiLen_da = s.size;
    unsigned i1 = s.rfind("\\");
    unsigned i_wuftt = s.rfind("/");
    unsigned i3 = s.rfind(":");
    if (i1 == DAT_010173f0)
        i1 = 0;
    else
        i1++;
    if (i_wuftt == DAT_010173f0)
        i_wuftt = 0;
    else
        i_wuftt++;
    if (i3 == DAT_010173f0)
        i3 = 0;
    else
        i3++;
    unsigned uiStart_pgdky = GetMaxX(i1, i_wuftt);
    if (uiStart_pgdky > 0 && i3 > uiStart_pgdky)
        return false;
    uiStart_pgdky = GetMaxX(uiStart_pgdky, i3);
    if (uiStart_pgdky == uiLen_da)
        return false;
    unsigned uiDot_hda = s.rfind(".");
    unsigned uiExt_tt;
    if (uiDot_hda == DAT_010173f0)
    {
        uiDot_hda = uiLen_da;
        uiExt_tt = uiLen_da;
    }
    else
        uiExt_tt = uiDot_hda + 1;
    if (uiDot_hda == uiStart_pgdky)
        return false;
    if (uiDot_hda < uiStart_pgdky)
        uiDot_hda = uiLen_da;
    if (uiStart_pgdky < uiDot_hda)
    {
    }
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0xaa);
    Dead4();
    *pA = s.Substr(0, uiStart_pgdky);
    DeadX();
    *pB = s.Substr(uiStart_pgdky, uiDot_hda - uiStart_pgdky);
    DeadX();
    *pC = s.Substr(uiExt_tt, uiLen_da - uiExt_tt);
    DeadX();
    return true;
}

namespace fnv_00ad3aa0 {
struct G16
{
    int a, b, c, d;
};
extern "C" G16 FUN_00ec38a9();
inline G16 GetG()
{
    return FUN_00ec38a9();
}
void* FormHeap_Allocate(unsigned n);
struct StrX
{
    char buf[0x1c];
    void FUN_0044a730(bool b, unsigned n);
    ~StrX()
    {
        FUN_0044a730(true, 0);
    }
};
struct SrcX
{
    StrX FUN_00ad3e60();
};
struct FUN_00ad3ca0
{
    char buf[0x74];
    FUN_00ad3ca0(const StrX& s);
    ~FUN_00ad3ca0();
};
struct B0
{
    virtual void V0();
    int m4;
    B0()
    {
        m4 = 0;
    }
};
struct B1 : B0
{
    virtual void V0();
    B1()
    {}
};
inline void DeadA()
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
}
inline void DeadB()
{
    int b0;
    int b1;
    int b2;
    int b3;
    int b4;
    int b5;
    int b6;
    int b7;
    int b8;
    int b9;
    int b10;
    int b11;
    int b12;
    int b13;
    int b14;
}
struct ObjX : B1
{
    G16 m8;
    static void* operator new(unsigned n)
    {
        return FormHeap_Allocate(n);
    }
    static void operator delete(void* p)
    {}
    virtual void V0();
    ObjX(const FUN_00ad3ca0& a)
    {
        G16 g = FUN_00ec38a9();
        m8 = g;
    }
};
// @fnv 0x00ad3aa0
int FUN_00ad3aa0(B0** out, SrcX* src)
{
    if (out && !*out)
    {
        DeadA();
        *out = new ObjX(FUN_00ad3ca0(src->FUN_00ad3e60()));
    }
    DeadB();
    return 2;
}
}  // namespace fnv_00ad3aa0

extern unsigned int DAT_010173f0;

struct S00aaec10_Sub
{
    void FUN_0044a730(bool, unsigned int);
    void AssignSubstring(const void*, int, unsigned int);
};

struct S00aaec10_Guard
{
    __forceinline S00aaec10_Guard()
    {}
    __forceinline ~S00aaec10_Guard()
    {}
};

struct S00aaec10_Obj
{
    void FUN_00658f30(const void*);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S00aaec10_Sub sub;
    S00aaec10_Obj* FUN_00aaec10(const void* src);
};

// @fnv 0x00aaec10
S00aaec10_Obj* S00aaec10_Obj::FUN_00aaec10(const void* src)
{
    unsigned int u00;
    unsigned int u01;
    unsigned int u02;
    unsigned int u03;
    unsigned int u04;
    unsigned int u05;
    unsigned int u06;
    unsigned int u07;
    unsigned int u08;
    unsigned int u09;
    unsigned int u10;
    unsigned int u11;
    unsigned int u12;
    unsigned int u13;
    unsigned int u14;
    unsigned int u15;
    unsigned int u16;
    unsigned int u17;
    unsigned int u18;
    unsigned int u19;
    unsigned int u20;
    unsigned int u21;
    unsigned int u22;
    unsigned int u23;
    unsigned int u24;
    unsigned int u25;
    unsigned int u26;
    unsigned int u27;
    FUN_00658f30(src);
    {
        S00aaec10_Guard g;
        S00aaec10_Sub* p5 = &sub;
        p5->FUN_0044a730(false, 0);
        p5->AssignSubstring((const char*)src + 0x20, 0, DAT_010173f0);
    }
    return this;
}

extern unsigned int DAT_010173f0;
static __forceinline void D23()
{
    int a[23];
}
static __forceinline void D18()
{
    int a[18];
}
struct FileString
{
    int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    FileString(const char*);
    FileString(const FileString& other)
    {
        int aiD[23];
        FUN_0044a730(false, 0);
        AssignSubstring(other, 0, DAT_010173f0);
    }
    void Tail()
    {}
    ~FileString();
    void FUN_0044a730(bool, unsigned int);
    FileString& AssignSubstring(const FileString&, unsigned int, unsigned int);
};
struct FileReader
{
    int vtable;
    FileString fileName, signature;
    int fileSize;
    FileReader(FileString);
    ~FileReader();
    bool FUN_00ac4910(FileString);
};
bool FUN_00ab7f40(FileReader*, void*);
// @fnv 0x00ab7e30
bool FUN_00ab7e30(const FileString& fileName, void* output)
{
    FileReader reader(FileString("FRTRI003"));
    if (!reader.FUN_00ac4910(fileName))
        return false;
    D18();
    return FUN_00ab7f40(&reader, output);
}

void __cdecl FUN_00ec7c56();
extern "C" int __cdecl memcpy_s(void*, unsigned int, const void*, unsigned int);
void __cdecl operator delete(void*);
namespace std {
template <class E> struct char_traits
{
    static void assign(E& dest, const E& value)
    {
        dest = value;
    }
    static E* _Copy_s(E* dest, unsigned int size, const E* source, unsigned int count)
    {
        memcpy_s(dest, size, source, count);
        return dest;
    }
};
template <class E> class allocator
{
  public:
    void deallocate(E* ptr, unsigned int)
    {
        operator delete(ptr);
    }
};
struct SecureTraitsTag
{
};
template <class T> inline SecureTraitsTag charTraitsCat()
{
    SecureTraitsTag tag;
    return tag;
}
namespace _Traits_helper {
template <class T>
inline char* copy_s(char* dest, unsigned int size, const char* source, unsigned int count, SecureTraitsTag)
{
    return T::_Copy_s(dest, size, source, count);
}
template <class T> inline char* copy_s(char* dest, unsigned int size, const char* source, unsigned int count)
{
    return copy_s<T>(dest, size, source, count, charTraitsCat<T>());
}
}
template <class E, class T, class A> class basic_string
{
  public:
    A alloc;
    union Buffer
    {
        E chars[16];
        E* pointer;
    } buffer;
    unsigned int length, capacity;
    E* _Myptr()
    {
        return 16 <= capacity ? buffer.pointer : buffer.chars;
    }
    void _Eos(unsigned int size)
    {
        T::assign(_Myptr()[length = size], E());
    }
    void _Tidy(bool built, unsigned int size)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            E* ptr = buffer.pointer;
            if (0 < size)
                _Traits_helper::copy_s<T>(buffer.chars, 16, ptr, size);
            alloc.deallocate(ptr, capacity + 1);
        }
        capacity = 15;
        _Eos(size);
    }
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
    basic_string& operator=(const basic_string& other)
    {
        return assign(other, 0, ~0u);
    }
    ~basic_string()
    {
        _Tidy(true, 0);
    }
};
}
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > GameString;
struct Vector3
{
    float x, y, z;
};
struct GameRecord
{
    int id;
    Vector3 position;
    GameString name;
};
struct GameAllocator
{
    void destroy(GameRecord* ptr)
    {
        ptr->~GameRecord();
    }
};
struct GameVector;
struct GameAux
{
    const GameVector* container;
    const GameVector* GetShapeContainer() const
    {
        return container;
    }
};
struct GameConstIterator
{
    GameAux* owner;
    GameRecord* current;
    GameConstIterator(GameRecord*, GameVector*);
    GameConstIterator& func_0x00ac0c40(int);
    const GameVector* GetShapeContainer() const
    {
        return owner ? owner->GetShapeContainer() : 0;
    }
    bool hasContainer() const
    {
        return owner != 0;
    }
    bool sameContainer(const GameConstIterator& other) const
    {
        return owner == other.owner;
    }
    bool operator==(const GameConstIterator& other) const
    {
        if (!(hasContainer() && sameContainer(other)))
            FUN_00ec7c56();
        return current == other.current;
    }
    bool operator!=(const GameConstIterator& other) const
    {
        return !(*this == other);
    }
};
struct GameIterator : GameConstIterator
{
    GameIterator(GameRecord* p, GameVector* v) : GameConstIterator(p, v)
    {}
    GameIterator& operator+=(int count)
    {
        func_0x00ac0c40(count);
        return *this;
    }
    GameIterator operator+(int count) const
    {
        GameIterator tmp = *this;
        return tmp += count;
    }
};
struct GameVector
{
    GameAux* iteratorOwner;
    int unk04;
    GameAllocator allocator;
    GameRecord *first, *last, *limit;
    unsigned int size() const
    {
        return last - first;
    }
    GameIterator makeIter(GameConstIterator it)
    {
        return GameIterator(it.current, this);
    }
    void destroy(GameRecord*, GameRecord*);
    GameIterator begin()
    {
        return GameIterator(first, this);
    }
    GameIterator end()
    {
        return GameIterator(last, this);
    }
    void func_0x00abeb00(GameConstIterator, unsigned int, const GameRecord&);
    GameIterator func_0x00abb5f0(GameConstIterator, GameConstIterator);
    void FUN_00abb3c0(unsigned int count, GameRecord value);
};
inline GameConstIterator& GameConstIterator::func_0x00ac0c40(int count)
{
    if (!hasContainer())
        FUN_00ec7c56();
    if (!(current + count <= GetShapeContainer()->last && current + count >= GetShapeContainer()->first))
        FUN_00ec7c56();
    current += count;
    return *this;
}
inline GameConstIterator::GameConstIterator(GameRecord* ptr, GameVector* container) : owner(0)
{
    if (!container || container->first > ptr || ptr > container->last)
        FUN_00ec7c56();
    owner = container->iteratorOwner;
    current = ptr;
}
struct ForwardTag
{
};
struct BidirectionalTag : ForwardTag
{
};
struct RandomTag : BidirectionalTag
{
};
struct NonScalarTag
{
};
struct RangeTag
{
};
inline RandomTag iterRandom(GameRecord* const&, GameRecord* const&)
{
    RandomTag cat;
    return cat;
}
inline NonScalarTag ptrCat(GameRecord* const&, GameRecord* const&)
{
    NonScalarTag cat;
    return cat;
}
struct UnchangedTag
{
};
inline GameRecord* checkedBase(GameRecord*& ptr, UnchangedTag)
{
    return ptr;
}
inline GameRecord* checkedBase(GameRecord*& ptr)
{
    UnchangedTag tag;
    return checkedBase(ptr, tag);
}
inline GameRecord* copyOpt(GameRecord* first, GameRecord* last, GameRecord* dest, ForwardTag, NonScalarTag, RangeTag)
{
    for (; first != last; ++dest, ++first)
        *dest = *first;
    return dest;
}
inline GameRecord* copyOpt(GameRecord* first, GameRecord* last, GameRecord* dest, RandomTag, NonScalarTag, RangeTag)
{
    GameRecord* result = dest + (last - first);
    copyOpt(first, last, checkedBase(dest), ForwardTag(), NonScalarTag(), RangeTag());
    return result;
}
inline GameRecord* uncheckedCopy(GameRecord* first, GameRecord* last, GameRecord* dest)
{
    return copyOpt(checkedBase(first), checkedBase(last), dest, iterRandom(first, dest), ptrCat(first, dest),
                   RangeTag());
}
void destroyRange(GameRecord* first, GameRecord* last, GameAllocator& alloc, NonScalarTag)
{
    for (; first != last; ++first)
        alloc.destroy(first);
}
inline void destroyRange(GameRecord* first, GameRecord* last, GameAllocator& alloc)
{
    destroyRange(first, last, alloc, ptrCat(first, last));
}
inline void GameVector::destroy(GameRecord* first, GameRecord* last)
{
    destroyRange(first, last, allocator);
}
inline GameIterator GameVector::func_0x00abb5f0(GameConstIterator firstArg, GameConstIterator lastArg)
{
    GameIterator firstIt = makeIter(firstArg);
    GameIterator lastIt = makeIter(lastArg);
    if (firstIt != lastIt)
    {
        GameRecord* rangeStart = firstIt.current;
        GameRecord* ptr = uncheckedCopy(lastIt.current, last, rangeStart);
        destroy(ptr, last);
        last = ptr;
    }
    return firstIt;
}
// @fnv 0x00abb3c0
void GameVector::FUN_00abb3c0(unsigned int count, GameRecord value)
{
    if (size() < count)
        func_0x00abeb00(end(), count - size(), value);
    else if (count < size())
        func_0x00abb5f0(begin() + count, end());
}

namespace fnv_00ac0530 {
struct FUN_00ac0640_cls
{
    void FUN_00ac0640(int a);
};

struct AcFrameGuard
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
    __forceinline ~AcFrameGuard()
    {}
};

struct FUN_00ac0530_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00ac0640_cls m_1c;
    void FUN_0044a730(int a, int b);
    void AssignSubstring(int a, int b, int c);
    FUN_00ac0530_cls* FUN_00ac0530(int a);
};

extern int DAT_010173f0;

// @fnv 0x00ac0530
FUN_00ac0530_cls* FUN_00ac0530_cls::FUN_00ac0530(int a)
{
    this->FUN_0044a730(0, 0);
    this->AssignSubstring(a, 0, DAT_010173f0);
    {
        AcFrameGuard guard;
        m_1c.FUN_00ac0640(a + 0x1c);
    }
    return this;
}
}  // namespace fnv_00ac0530

extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
void __cdecl FUN_00ec7c56();
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
extern unsigned int DAT_010173f0;
const unsigned int String::npos = (unsigned int)(-1);

struct S_00ac05b0_Sub
{
    S_00ac05b0_Sub(const S_00ac05b0_Sub& kOther);
};

class FUN_00ac05b0 : public String
{
  public:
    FUN_00ac05b0(const FUN_00ac05b0& kOther);
    int m_iValue;
    S_00ac05b0_Sub m_kSub;
};

// @fnv 0x00ac05b0
FUN_00ac05b0::FUN_00ac05b0(const FUN_00ac05b0& kOther)
    : String(kOther), m_iValue(kOther.m_iValue), m_kSub(kOther.m_kSub)
{}

namespace fnv_00ac3df0 {
extern unsigned int DAT_010173f0;
namespace binac3 {
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

void ReportAssertionViolation(const char* file, int line);
}
using namespace binac3;

struct FUN_00ac3df0
{
    BxString kPath;
    BxString kName;
    int unk3c;
    FUN_00ac3df0(BxString name);
    virtual void v00();
};

// @fnv 0x00ac3df0
FUN_00ac3df0::FUN_00ac3df0(BxString name)
{
    kName = name;
    if (kName.size() == 8)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\binaryFile.cpp", 0x22);
    }
    unk3c = 0;
    kName[5] = '0';
}
}  // namespace fnv_00ac3df0

extern "C" int DAT_011f6238;
void __cdecl operator delete(void* _Ptr) throw();
inline void* operator new(unsigned int, void* _Where) throw()
{
    return _Where;
}
inline void operator delete(void*, void*) throw()
{}
namespace wrac52 {
void FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char* _Str);
extern "C" int __cdecl memcmp(const void* _Buf1, const void* _Buf2, unsigned int _Size);
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
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
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
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
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

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&DAT_011f6238)->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(_Ptr);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
struct GvFileHandle;
extern "C" unsigned int __cdecl fwrite(const void* _Str, unsigned int _Size, unsigned int _Count, GvFileHandle* _File);
void FUN_00ac6430(int code, BxString message);
}
using namespace wrac52;

struct GvBinaryFile
{
    BxString kPath;
    BxString kMagic;
    GvFileHandle* pFile;
    virtual void v00();
    void FUN_00ac5430();
    bool FUN_00ac5220(const void* data, unsigned int size, unsigned int count);
};

// @fnv 0x00ac5220
bool GvBinaryFile::FUN_00ac5220(const void* data, unsigned int size, unsigned int count)
{
    if (pFile == 0)
    {
        return false;
    }
    if (fwrite(data, size, count, pFile) != count)
    {
        FUN_00ac6430(6, kPath);
        FUN_00ac5430();
        return false;
    }
    return true;
}

namespace fnv_00ac6430 {
namespace errac6 {
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
    char& operator[](unsigned int _Off)
    {
        if (!(_Off <= _Mysize))
        {
            FUN_00ec7c56();
        }
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

void ReportAssertionViolation(const char* file, int line);
void* FUN_00ec44d0(void* dst, const void* src, unsigned int count);
}
using namespace errac6;
extern int DAT_011f6c88;
extern char DAT_011f6c8c[256];

// @fnv 0x00ac6430
void FUN_00ac6430(int code, BxString message)
{
    if (DAT_011f6c88 == 0)
    {
        unsigned int uiLength = message.size();
        DAT_011f6c88 = code;
        if (uiLength < 0x100)
        {
        }
        else
        {
            ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\lastError.cpp", 0x41);
        }
        uiLength = uiLength < 0x100 ? uiLength : 0xff;
        FUN_00ec44d0(DAT_011f6c8c, &message[0], uiLength);
        DAT_011f6c8c[uiLength] = 0;
    }
}
}  // namespace fnv_00ac6430

namespace fnv_00ac9790 {
extern "C" int __cdecl fclose(void*);

void __cdecl FUN_00ec7c56();
namespace std {
template <class C> struct char_traits;
template <class C> class allocator;
template <class C, class Traits, class Alloc> class basic_string
{
  public:
    unsigned int allocatorState;
    union Storage
    {
        C local[16];
        C* heap;
    } storage;
    unsigned int length, capacity;
    basic_string(const C*);
    basic_string(const basic_string& other)
    {
        _Tidy(false, 0);
        assign(other, 0, npos);
    }
    ~basic_string();
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
    static const unsigned int npos;
    const C* c_str() const
    {
        return capacity >= 16 ? storage.heap : storage.local;
    }

  protected:
    void _Tidy(bool, unsigned int);
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
template <class T> class vector
{
  public:
    unsigned int unk00, unk04, unk08;
    T* first;
    T* last;
    T* capacity;
    unsigned int size() const
    {
        return last - first;
    }
    const T& operator[](unsigned int index) const
    {
        {
            if (!(index < size()))
            {
                {
                    FUN_00ec7c56();
                }
            }
        }
        return first[index];
    }
};
class ios_base
{
  public:
    virtual ~ios_base();
    unsigned int standardStream;
    int state, exceptions, format, precision, width;
    void* values;
    void* callbacks;
    void* locale;
    int rdstate() const
    {
        return state;
    }
    bool fail() const
    {
        return (rdstate() & 6) != 0;
    }
};
template <class C, class Traits> class basic_streambuf
{
  public:
    virtual ~basic_streambuf();
    unsigned int lock;
    C *readBegin, *writeBegin;
    C **readBeginRef, **writeBeginRef;
    C *readNext, *writeNext;
    C **readNextRef, **writeNextRef;
    int readCount, writeCount;
    int *readCountRef, *writeCountRef;
    void* locale;
};
template <class C, class Traits> class basic_ostream;
template <class C, class Traits> class basic_ios : public ios_base
{
  public:
    virtual ~basic_ios();
    basic_streambuf<C, Traits>* buffer;
    basic_ostream<C, Traits>* tiedStream;
    C fill;
    void setstate(int, bool = false);
};
template <class C, class Traits> class basic_ostream : virtual public basic_ios<C, Traits>
{
  public:
    virtual ~basic_ostream();
    basic_ostream(basic_streambuf<C, Traits>*, bool = false);
    basic_ostream& put(C);
    basic_ostream& flush();
};
typedef basic_ostream<char, char_traits<char> > ostream;
template <class C, class Traits> class basic_filebuf : public basic_streambuf<C, Traits>
{
  public:
    void* codec;
    C putback;
    bool wrote;
    int conversionState;
    bool ownsFile;
    void* file;
    basic_filebuf();
    basic_filebuf* open(const char*, int, int);
    bool _Endwrite();
    void _Init(void*, int);
    basic_filebuf* close()
    {
        basic_filebuf* answer = this;
        void* stream = file;
        if (stream == 0)
            answer = 0;
        else
        {
            if (!_Endwrite())
                answer = 0;
            if (fclose(stream) != 0)
                answer = 0;
        }
        _Init(0, 2);
        return answer;
    }
};
template <class C, class Traits = char_traits<C> > class basic_ofstream : public basic_ostream<C, Traits>
{
  public:
    basic_ofstream(const char* name, int mode, int prot) : basic_ostream<C, Traits>(&fileBuffer)
    {
        const char* filename = name;
        int openMode = mode | 2;
        int protection = prot;
        basic_filebuf<C, Traits>* buffer = &fileBuffer;
        if (buffer->open(filename, openMode, protection) == 0)
            this->setstate(2);
    }
    virtual ~basic_ofstream();
    basic_filebuf<C, Traits> fileBuffer;
    void close()
    {
        if (fileBuffer.close() == 0)
            this->setstate(2);
    }
};
typedef basic_ofstream<char> ofstream;
}
void __cdecl FUN_00ac6430(int, std::string);
std::ostream& __cdecl FUN_00ad47f0(std::ostream&, const char*);
std::ostream& __cdecl FUN_00ad4ba0(std::ostream&, const std::string&);
extern "C" char DAT_010a3028;
extern "C" char DAT_01021184;
extern "C" char DAT_01063cd8;
// @fnv 0x00ac9790
bool __cdecl FUN_00ac9790(const std::string& path, const std::vector<std::vector<std::string> >& sections)
{
    if (sections.size() == 0)
    {
        FUN_00ac6430(11, std::string(&DAT_010a3028));
        return false;
    }
    std::ofstream output(path.c_str(), 2, 64);
    if (output.fail())
    {
        FUN_00ac6430(5, path);
        return false;
    }
    for (unsigned int i = 0; i < sections.size(); ++i)
    {
        unsigned int childCount = sections[i].size();
        for (unsigned int j = 0; j < childCount; ++j)
        {
            FUN_00ad47f0(FUN_00ad4ba0(FUN_00ad47f0(output, &DAT_01021184), sections[i][j]), &DAT_01021184);
            if (j == childCount - 1)
            {
                output.put(10);
                output.flush();
                output.flush();
            }
            else
            {
                FUN_00ad47f0(output, &DAT_01063cd8);
            }
        }
        if (output.fail())
        {
            FUN_00ac6430(6, path);
            output.close();
            return false;
        }
    }
    output.close();
    return true;
}
}  // namespace fnv_00ac9790

extern unsigned int DAT_010173f0;

class StrFld
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    __declspec(noinline) void FUN_0044a730(bool, unsigned int);
    __declspec(noinline) void AssignSubstring(const StrFld&, unsigned int, unsigned int);
    StrFld(const StrFld& r)
    {
        FUN_0044a730(false, 0);
        AssignSubstring(r, 0, DAT_010173f0);
    }
    ~StrFld()
    {
        FUN_0044a730(true, 0);
    }
};

void StrFld::FUN_0044a730(bool, unsigned int)
{}

void StrFld::AssignSubstring(const StrFld&, unsigned int, unsigned int)
{}

class FUN_00acb310
{
  public:
    StrFld m_00;
    StrFld m_1c;
    FUN_00acb310(const StrFld& a1, const StrFld& a2);
};

// @fnv 0x00acb310
FUN_00acb310::FUN_00acb310(const StrFld& a1, const StrFld& a2) : m_00(a1), m_1c(a2)
{
    unsigned int u00;
    unsigned int u01;
    unsigned int u02;
    unsigned int u03;
    unsigned int u04;
    unsigned int u05;
    unsigned int u06;
    unsigned int u07;
    unsigned int u08;
    unsigned int u09;
    unsigned int u10;
    unsigned int u11;
    unsigned int u12;
    unsigned int u13;
    unsigned int u14;
    unsigned int u15;
    unsigned int u16;
    unsigned int u17;
    unsigned int u18;
    unsigned int u19;
    unsigned int u20;
    unsigned int u21;
    unsigned int u22;
    unsigned int u23;
    unsigned int u24;
    unsigned int u25;
    unsigned int u26;
    unsigned int u27;
    unsigned int u28;
    unsigned int u29;
    unsigned int u30;
    unsigned int u31;
    unsigned int u32;
    unsigned int u33;
    unsigned int u34;
    unsigned int u35;
    unsigned int u36;
    unsigned int u37;
    unsigned int u38;
}

struct _iobuf
{
    char* _ptr;
    int _cnt;
    char* _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char* _tmpfname;
};
extern "C" int __cdecl fclose(struct _iobuf* _File);
void __cdecl operator delete(void* pv);

template <class _Ty> class allocatorDEB0
{
  public:
    void deallocate(_Ty* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};

class _LockitDEB0
{
  public:
    explicit _LockitDEB0(int _Kind);
    ~_LockitDEB0();
    int _Locktype;
};

class facetDEB0
{
  public:
    virtual ~facetDEB0();
    facetDEB0* _Decref()
    {
        {
            _LockitDEB0 _Lock(0);
            if (0 < _Refs && _Refs != (unsigned int)(-1))
                --_Refs;
            return (_Refs == 0 ? this : 0);
        }
    }
    unsigned int _Refs;
};

class localeDEB0
{
  public:
    ~localeDEB0()
    {
        if (_Ptr != 0)
            delete _Ptr->_Decref();
    }
    facetDEB0* _Ptr;
};

class _MutexDEB0
{
  public:
    ~_MutexDEB0();
    void* _Mtx;
};

class basic_streambufDEB0
{
  public:
    typedef char _Elem;
    virtual ~basic_streambufDEB0()
    {
        delete _Plocale;
    }

    _Elem* eback() const
    {
        return (*_IGfirst);
    }
    _Elem* gptr() const
    {
        return (*_IGnext);
    }
    _Elem* egptr() const
    {
        return (*_IGnext + *_IGcount);
    }
    _Elem* pptr() const
    {
        return (*_IPnext);
    }
    _Elem* epptr() const
    {
        return (*_IPnext + *_IPcount);
    }
    void setg(_Elem* _First, _Elem* _Next, _Elem* _Last)
    {
        *_IGfirst = _First;
        *_IGnext = _Next;
        *_IGcount = (int)(_Last - _Next);
    }
    void _InitSB()
    {
        _IGfirst = &_Gfirst;
        _IPfirst = &_Pfirst;
        _IGnext = &_Gnext;
        _IPnext = &_Pnext;
        _IGcount = &_Gcount;
        _IPcount = &_Pcount;
        setp(0, 0);
        setg(0, 0, 0);
    }
    void _InitSB(_Elem** _Gf, _Elem** _Gn, int* _Gc, _Elem** _Pf, _Elem** _Pn, int* _Pc)
    {
        _IGfirst = _Gf;
        _IPfirst = _Pf;
        _IGnext = _Gn;
        _IPnext = _Pn;
        _IGcount = _Gc;
        _IPcount = _Pc;
    }
    void setp(_Elem* _First, _Elem* _Last)
    {
        *_IPfirst = _First;
        *_IPnext = _First;
        *_IPcount = (int)(_Last - _First);
    }

    _MutexDEB0 _Mylock;
    _Elem* _Gfirst;
    _Elem* _Pfirst;
    _Elem** _IGfirst;
    _Elem** _IPfirst;
    _Elem* _Gnext;
    _Elem* _Pnext;
    _Elem** _IGnext;
    _Elem** _IPnext;
    int _Gcount;
    int _Pcount;
    int* _IGcount;
    int* _IPcount;
    localeDEB0* _Plocale;
};

class basic_filebufDEB0 : public basic_streambufDEB0
{
  public:
    virtual ~basic_filebufDEB0()
    {
        if (_Closef)
            close();
    }
    enum _Initfl
    {
        _Newfl,
        _Openfl,
        _Closefl
    };
    bool _Endwrite()
    {
        if (_Pcvt == 0 || !_Wrotesome)
            return (true);
        return (false);
    }
    void _Init(struct _iobuf* _File, _Initfl _Which)
    {
        static int _Stinit;
        _Closef = _Which == _Openfl;
        _Wrotesome = false;
        _InitSB();
        if (_File != 0 && sizeof(char) == 1)
        {
            char** _Pb = (char**)&_File->_base;
            char** _Pn = (char**)&_File->_ptr;
            int* _Nr = (int*)&_File->_cnt;
            _InitSB(_Pb, _Pn, _Nr, _Pb, _Pn, _Nr);
        }
        _Myfile = _File;
        _State = _Stinit;
        _Pcvt = 0;
    }
    basic_filebufDEB0* close()
    {
        basic_filebufDEB0* _Ans = this;
        if (_Myfile == 0)
            _Ans = 0;
        else
        {
            if (!_Endwrite())
                _Ans = 0;
            if (fclose(_Myfile) != 0)
                _Ans = 0;
        }
        _Init(0, _Closefl);
        return (_Ans);
    }
    void* _Pcvt;
    char _Mychar;
    bool _Wrotesome;
    int _State;
    bool _Closef;
    struct _iobuf* _Myfile;
};

class ios_baseDEB0
{
  public:
    virtual ~ios_baseDEB0();
    int unk04;
};

class basic_iosDEB0 : public ios_baseDEB0
{
  public:
    virtual ~basic_iosDEB0();
};

class basic_istreamDEB0 : virtual public basic_iosDEB0
{
  public:
    virtual ~basic_istreamDEB0()
    {}
    int _Chcount;
};

// std::basic_ifstream<char>::~basic_ifstream (vbase-adjusted this)
class FUN_00acc8c0 : public basic_istreamDEB0
{
  public:
    virtual ~FUN_00acc8c0();
    basic_filebufDEB0 _Filebuffer;
};

// @fnv 0x00acc8c0
FUN_00acc8c0::~FUN_00acc8c0()
{}

namespace fnv_00ad3000 {
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
struct FUN_00ad3000
{
    String first;
    String second;
    FUN_00ad3000(const FUN_00ad3000& kRight);
};

// @fnv 0x00ad3000
FUN_00ad3000::FUN_00ad3000(const FUN_00ad3000& kRight) : first(kRight.first), second(kRight.second)
{}
}  // namespace fnv_00ad3000

namespace fnv_00ad3e60 {
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
struct Named_ad3e
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    String m_kName;
};

struct NameHolder_ad3e
{
    Named_ad3e* m_pkNamed;
    String FUN_00ad3e60() const;
};

// @fnv 0x00ad3e60
String NameHolder_ad3e::FUN_00ad3e60() const
{
    return m_pkNamed->m_kName;
}
}  // namespace fnv_00ad3e60

extern unsigned int DAT_010173f0;
union BxQ_ad6bb0
{
    char _Buf[16];
    char* _Ptr;
};
struct AlQ_ad6bb0
{
};
inline bool operator==(const AlQ_ad6bb0&, const AlQ_ad6bb0&)
{
    return true;
}
template <class T> inline void Swap_ad6bb0(T& _Left, T& _Right)
{
    T _Tmp = _Left;
    _Left = _Right;
    _Right = _Tmp;
}
struct StrQ_ad6bb0
{
    AlQ_ad6bb0 _Alval;
    BxQ_ad6bb0 _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    void _Tidy(bool _Built, unsigned int _Newsize);
    StrQ_ad6bb0& assign(const StrQ_ad6bb0& _Right, unsigned int _Roff, unsigned int _Count);
    StrQ_ad6bb0(const StrQ_ad6bb0& _Right)
    {
        int _D0;
        int _D1;
        int _D2;
        int _D3;
        int _D4;
        int _D5;
        int _D6;
        int _D7;
        int _D8;
        int _D9;
        int _D10;
        int _D11;
        int _D12;
        int _D13;
        int _D14;
        int _D15;
        int _D16;
        int _D17;
        int _D18;
        int _D19;
        int _D20;
        int _D21;
        int _D22;
        int _D23;
        int _D24;
        int _D25;
        int _D26;
        int _D27;
        _Tidy(false, 0);
        assign(_Right, 0, DAT_010173f0);
    }
    StrQ_ad6bb0& operator=(const StrQ_ad6bb0& _Right)
    {
        return assign(_Right, 0, DAT_010173f0);
    }
    ~StrQ_ad6bb0()
    {
        _Tidy(true, 0);
    }
    void FUN_00ad6bb0(StrQ_ad6bb0& _Right);
};
// @fnv 0x00ad6bb0
void StrQ_ad6bb0::FUN_00ad6bb0(StrQ_ad6bb0& _Right)
{
    if (this == &_Right)
        ;
    else if (_Alval == _Right._Alval)
    {
        BxQ_ad6bb0 _Tbx = _Bx;
        _Bx = _Right._Bx, _Right._Bx = _Tbx;
        unsigned int _Tsize = _Mysize;
        _Mysize = _Right._Mysize, _Right._Mysize = _Tsize;
        unsigned int _Tres = _Myres;
        _Myres = _Right._Myres, _Right._Myres = _Tres;
    }
    else
    {
        StrQ_ad6bb0 _Tmp = *this;
        *this = _Right;
        _Right = _Tmp;
    }
}

extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
namespace std {}
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
struct IdName_ac34
{
    int m_iId;
    String m_kName;
};
// @fnv 0x00ac34c0
void __cdecl FUN_00ac34c0(IdName_ac34* pPtr, const IdName_ac34& kVal)
{
    void* pvPtr = pPtr;
    ::new (pvPtr) IdName_ac34(kVal);
}

extern "C" unsigned int __cdecl strlen(const char* pcString);
extern "C" int __cdecl memcpy_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
extern "C" int __cdecl memmove_s(void* pvDst, unsigned int uiDstSize, const void* pvSrc, unsigned int ItemUpdateArray);
void* __cdecl operator new(unsigned int uiSize);
namespace std {}
extern "C" char* __cdecl strcpy(char* pcDst, const char* pcSrc);
struct Point3_b2e7
{
    float x;
    float y;
    float z;
};
struct FUN_00b2e740
{
    bool m_bEnableState;
    Point3_b2e7 m_kPathOffset;
    float m_fBoundRadius;
    String m_kName;
    Point3_b2e7 m_kPoint1;
    Point3_b2e7 m_kPoint2;
    Point3_b2e7 m_kPoint3;

    FUN_00b2e740(const FUN_00b2e740& kOther);
};
// @fnv 0x00b2e740
FUN_00b2e740::FUN_00b2e740(const FUN_00b2e740& kOther)
    : m_bEnableState(kOther.m_bEnableState), m_kPathOffset(kOther.m_kPathOffset), m_fBoundRadius(kOther.m_fBoundRadius),
      m_kName(kOther.m_kName), m_kPoint1(kOther.m_kPoint1), m_kPoint2(kOther.m_kPoint2), m_kPoint3(kOther.m_kPoint3)
{}

void* __cdecl FUN_00ad5370(int count, int flags);
void __cdecl FormHeap_Free(void* p);

struct SubObj0C
{
    void __thiscall FUN_00ad3000(int v);
};

static __forceinline void Dead9()
{
    int aiD[9];
}
struct Entry48
{
    int unk00;
    int unk04;
    int unk08;
    SubObj0C unk0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    bool unk44;
    bool unk45;
    inline Entry48(int a, int b, int c, int d, bool e)
    {
        unk00 = a;
        unk04 = b;
        unk08 = c;
        unk0C.FUN_00ad3000(d);
        unk44 = e;
        unk45 = false;
        Dead9();
    }
};

struct Owner
{
    Entry48* __thiscall FUN_00ad1960(int a, int b, int c, int d, bool e);
};

// @fnv 0x00ad1960
Entry48* Owner::FUN_00ad1960(int a, int b, int c, int d, bool e)
{
    void* mem = FUN_00ad5370(1, 0);

    try
    {
        new (mem) Entry48(a, b, c, d, e);
    }
    catch (...)
    {
        FormHeap_Free(mem);
        throw;
    }
    return (Entry48*)mem;
}

extern "C" void* __cdecl FUN_00ec9a47(const char* name, const char* mode);
struct PadStr : StrFld
{
    PadStr(const PadStr& r) : StrFld(r)
    {
        int dqb[4];
    }
};
void __cdecl FUN_00ac6430(int iLevel, PadStr kMsg);
inline FileString::~FileString()
{
    FUN_0044a730(true, 0);
}
static inline const char* FsC(const FileString& s)
{
    return s.capacity >= 16 ? s.storage.pointer : s.storage.buffer;
}
static inline unsigned FsLen(const FileString& s)
{
    return s.length;
    int dql[4];
}
static __forceinline void Pad()
{
    int dq[17];
}
// @fnv 0x00ac4910
bool FileReader::FUN_00ac4910(FileString kPath)
{
    ((GvBinaryFile*)this)->FUN_00ac5430();
    ((GvBinaryFile*)this)->pFile =
        (GvFileHandle*)FUN_00ec9a47(kPath.capacity >= 16 ? kPath.storage.pointer : kPath.storage.buffer, "wb");
    if (!((GvBinaryFile*)this)->pFile)
    {
        FUN_00ac6430(5, *(PadStr*)&kPath);
        return false;
    }
    if (!((GvBinaryFile*)this)->FUN_00ac5220(FsC(signature), FsLen(signature), true))
    {
        FUN_00ac6430(5, *(PadStr*)&kPath);
        ((GvBinaryFile*)this)->FUN_00ac5430();
        return false;
        Pad();
    }
    fileName.AssignSubstring(kPath, 0, DAT_010173f0);
    return true;
}

struct CopyStr
{
    void* al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned size;
    unsigned res;
    void FUN_0044a730(bool b, unsigned n);
    CopyStr& AssignSubstring(const CopyStr& r, unsigned off, unsigned n);
    CopyStr(const CopyStr& r)
    {
        int aiD[26];
        FUN_0044a730(false, 0);
        AssignSubstring(r, 0, DAT_010173f0);
    }
};

// @fnv 0x00ad6990
void FUN_00ad6990(CopyStr* ptr, const CopyStr& val)
{
    void* vptr = ptr;
    ::new (vptr) CopyStr(val);
}

struct StringAssignmentOps
{
    bool FUN_0044a8d0(unsigned int, bool);
    char* FUN_0044a970();
    void ResizeString(unsigned int);
    GameString& EraseRange(unsigned int, unsigned int);
};
extern void __cdecl FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
struct InsertText : BxStringVal
{
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    InsertText(const InsertText& rhs) : BxStringVal(rhs)
    {
        FUN_0044a730(false, 0);
        assign(rhs, 0, ~0u);
    }
    ~InsertText()
    {
        FUN_0044a730(true, 0);
    }
    InsertText& operator=(const InsertText& rhs)
    {
        return assign(rhs, 0, ~0u);
    }
    unsigned int size() const
    {
        return length;
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int newSize)
    {
        std::char_traits<char>::assign(data()[length = newSize], char());
    }
    void FUN_0044a730(bool built, unsigned int newSize)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* ptr = storage._Ptr;
            if (0 < newSize)
                std::_Traits_helper::copy_s<std::char_traits<char> >(storage._Buf, 16, ptr, newSize);
            BxCharAlloc& al = _Alval;
            al.deallocate(ptr, capacity + 1);
        }
        capacity = 15;
        eos(newSize);
    }
    InsertText& assign(const InsertText& right, unsigned int off, unsigned int count)
    {
        unsigned int sourceSize = right.size();
        if (sourceSize < off)
            StringBase::_Xran();
        unsigned int num = sourceSize - off;
        if (count < num)
            num = count;
        if (this == &right)
        {
            reinterpret_cast<StringAssignmentOps*>(this)->EraseRange(off + num, ~0u);
            reinterpret_cast<StringAssignmentOps*>(this)->EraseRange(0, off);
        }
        else if (reinterpret_cast<StringAssignmentOps*>(this)->FUN_0044a8d0(num, false))
        {
            char* destination = reinterpret_cast<StringAssignmentOps*>(this)->FUN_0044a970();
            const char* source =
                reinterpret_cast<StringAssignmentOps*>(const_cast<InsertText*>(&right))->FUN_0044a970() + off;
            unsigned int destinationCapacity = capacity;
            FUN_0044ccd0(destination, destinationCapacity, source, num);
            reinterpret_cast<StringAssignmentOps*>(this)->ResizeString(num);
        }
        return *this;
    }
};
struct MM
{
    void Deallocate(void*);
};
extern MM _g_memoryManager;
extern "C" void* __cdecl FUN_0065e4c0(unsigned int, int);
extern const char DAT_010173c4[];
struct ErrorText
{
    unsigned char allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    explicit ErrorText(const char*);
    ~ErrorText();
};
struct InsertionLengthError
{
    virtual ~InsertionLengthError();
    const char* message;
    bool ownsMessage;
    ErrorText detail;
    explicit InsertionLengthError(const ErrorText&);
};
inline void __cdecl ThrowVectorTooLong()
{
    throw InsertionLengthError(ErrorText(DAT_010173c4));
}
struct InsertItem;
struct InsertionSource
{
    const InsertItem* value;
};
struct InsertItem
{
    unsigned int kind;
    struct Coordinates
    {
        unsigned int x, y, z;
    } coordinates;
    InsertText text;
    InsertItem(InsertionSource rhs) : text(rhs.value->text)
    {
        const Coordinates& source = rhs.value->coordinates;
        Coordinates& destination = coordinates;
        unsigned int copiedKind = rhs.value->kind;
        unsigned int copiedX = source.x;
        unsigned int copiedY = source.y;
        unsigned int copiedZ = source.z;
        kind = copiedKind;
        destination.x = copiedX;
        destination.y = copiedY;
        destination.z = copiedZ;
    }
    static void operator delete(void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};
namespace wrac52 {
template <> struct GvAlloc<InsertItem>
{
  public:
    typedef InsertItem value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef unsigned int size_type;
    typedef int difference_type;
    template <class U> struct rebind
    {
        typedef GvAlloc<U> other;
    };
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc&) throw()
    {}
    template <class U> GvAlloc(const GvAlloc<U>&) throw()
    {}
    pointer address(reference x) const
    {
        return &x;
    }
    const_pointer address(const_reference x) const
    {
        return &x;
    }
    pointer allocate(size_type n, const void* = 0)
    {
        return (pointer)FUN_0065e4c0(n, 0);
    }
    void deallocate(pointer p, size_type)
    {
        _g_memoryManager.Deallocate(p);
    }
    void construct(pointer p, const InsertItem& v)
    {
        GvConstruct(p, v);
    }
    void destroy(pointer p)
    {
        GvDestroyOne(p);
    }
    size_type max_size() const throw()
    {
        size_type c = (size_type)(-1) / sizeof(InsertItem);
        return 0 < c ? c : 1;
    }
};
}
struct InsertMoveTag
{
};
template <class I> inline InsertMoveTag InsertMoveCat(const I&)
{
    InsertMoveTag tag;
    return tag;
}
inline void FillInsertRange(InsertItem* first, InsertItem* last, const InsertItem& value)
{
    for (; first != last; ++first)
        *first = value;
}
inline void FUN_00ac1600(InsertItem* first, InsertItem* last, const InsertItem& value)
{
    FillInsertRange(GvCheckedBase(first), GvCheckedBase(last), value);
}
extern InsertItem* __cdecl FUN_00ac1e20(InsertItem*, InsertItem*, InsertItem*, GvAlloc<InsertItem>&);
extern InsertItem* __cdecl FUN_00ac3730(InsertItem*, InsertItem*, InsertItem*, GvAlloc<InsertItem>&);
__forceinline InsertItem* DispatchInsertMove(InsertItem* f, InsertItem* l, InsertItem* d, GvAlloc<InsertItem>& a,
                                             InsertMoveTag, GvRangeCheckedTag)
{
    return FUN_00ac3730(f, l, d, a);
}
__forceinline InsertItem* PrepareInsertMove(InsertItem* f, InsertItem* l, InsertItem* d, GvAlloc<InsertItem>& a)
{
    return DispatchInsertMove(GvCheckedBase(f), GvCheckedBase(l), d, a, InsertMoveCat(d), GvRangeCheckedTag());
}
extern InsertItem* __cdecl FUN_00ac1ea0(InsertItem*, InsertItem*, InsertItem*, GvRandomTag, InsertMoveTag,
                                        GvRangeCheckedTag);
struct TextAssignment
{
    InsertText& AssignSubstring(const InsertText&, unsigned int, unsigned int);
};
inline InsertItem* __cdecl FUN_00ac1ea0(InsertItem* f, InsertItem* l, InsertItem* d, GvRandomTag, InsertMoveTag,
                                        GvRangeCheckedTag)
{
    const int length = l - f;
    InsertItem* result = d - length;
    const InsertItem* begin = f;
    const InsertItem* end = l;
    InsertItem* output = d;
    while (begin != end)
    {
        const InsertItem& source = *--end;
        --output;
        output->kind = source.kind;
        output->coordinates.x = source.coordinates.x;
        output->coordinates.y = source.coordinates.y;
        output->coordinates.z = source.coordinates.z;
        reinterpret_cast<TextAssignment*>(&output->text)->AssignSubstring(source.text, 0, ~0u);
    }
    return result;
}
__forceinline InsertItem* InsertMoveBackward(InsertItem* f, InsertItem* l, InsertItem* d)
{
    return FUN_00ac1ea0(GvCheckedBase(f), GvCheckedBase(l), d, GvIterRandom(f, d), InsertMoveCat(d),
                        GvRangeCheckedTag());
}
struct ItemVector : GvVector<InsertItem>
{
    typedef InsertItem* pointer;
    typedef InsertItem value_type;
    typedef unsigned int size_type;
    typedef GvConstIterator<InsertItem> const_iterator;
    void FUN_0065dd90(pointer a, pointer b)
    {
        GvDestroyRange(a, b, this->_Alval);
    }
    __forceinline pointer _Umove(pointer f, pointer l, pointer d)
    {
        return PrepareInsertMove(f, l, d, this->_Alval);
    }
    pointer MoveTail(pointer f, pointer l, pointer d)
    {
        return FUN_00ac1e20(f, l, d, this->_Alval);
    }
    void FUN_00abeb00(const_iterator _Where, size_type _Count, InsertionSource _Val);
};
// @fnv 0x00abeb00
void ItemVector::FUN_00abeb00(const_iterator _Where, size_type _Count, InsertionSource _Val)
{
    size_type _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        ThrowVectorTooLong();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(this->_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, *_Val.value);
            MoveTail(_Where._Myptr, this->_Mylast, _Ptr);
        }
        catch (...)
        {
            FUN_0065dd90(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            FUN_0065dd90(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        value_type _Tmp = *_Val.value;
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            FUN_0065dd90(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        FUN_00ac1600(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        value_type _Tmp(_Val);
        pointer _Oldend = _Mylast;
        _Mylast = MoveTail(_Oldend - _Count, _Oldend, _Mylast);
        InsertMoveBackward(_Where._Myptr, _Oldend - _Count, _Oldend);
        FUN_00ac1600(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

bool CanOpenFile(const String& path);
String FUN_00ad4210(const String&, const char*);
String FUN_00ad42e0(const String&, const String&);

inline String& updateCandidate(String& destination, const String& source)
{
    return destination.assign(source, 0, DAT_010173f0);
}

// @fnv 0x00ac6fa0
String FUN_00ac6fa0(const String& directory, const String& baseName, const String& extension)
{
    String candidateName = FUN_00ad42e0(FUN_00ad4210(baseName, "."), extension);
    int retryIndex = 0;
    while (CanOpenFile(FUN_00ad42e0(directory, candidateName)))
    {
        char number[12];
        sprintf(number, "%d", ++retryIndex);
        updateCandidate(candidateName, FUN_00ad42e0(FUN_00ad4210(FUN_00ad4210(baseName, number), "."), extension));
    }
    return candidateName;
}

class FUN_0044a4c0 : public BxStringVal
{
  public:
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    FUN_0044a4c0() : BxStringVal()
    {
        FUN_0044a730(false, 0);
    }
    explicit FUN_0044a4c0(const char* s) : BxStringVal()
    {
        FUN_0044a730(false, 0);
        reinterpret_cast<BxString*>(this)->assign(s);
    }
    FUN_0044a4c0(const FUN_0044a4c0& right) : BxStringVal(right)
    {
        FUN_0044a730(false, 0);
        reinterpret_cast<BxString*>(this)->assign(reinterpret_cast<const BxString&>(right), 0, DAT_010173f0);
    }
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void endString(unsigned int n)
    {
        BxStrTraits::assign(data()[length = n], char());
    }
    void FUN_0044a730(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* old = storage._Ptr;
            if (0 < n)
                BxTraitsHelper::copy_s<BxStrTraits>(storage._Buf, 16, old, n);
            _Alval.deallocate(old, capacity + 1);
        }
        capacity = 15;
        endString(n);
    }
    unsigned int size() const
    {
        return length;
    }
    const char* data() const
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    int FUN_00ac9da0(const FUN_0044a4c0& right) const
    {
        return FUN_00ac6100(0, length, right.data(), right.size());
    }
    int FUN_00ac6100(unsigned int off, unsigned int count, const char* text, unsigned int size) const
    {
        if (length < off)
            StringBase::_Xran();
        if (length - off < count)
            count = length - off;
        unsigned int comparison = BxStrTraits::compare(data() + off, text, count < size ? count : size);
        return comparison != 0 ? (int)comparison : count < size ? -1 : count == size ? 0 : 1;
    }
    int compare(const char* s) const
    {
        return FUN_00ac6100(0, length, s, BxStrTraits::length(s));
    }
};
inline bool operator==(const FUN_0044a4c0& a, const FUN_0044a4c0& b)
{
    return a.FUN_00ac9da0(b) == 0;
}
inline bool operator==(const FUN_0044a4c0& a, const char* b)
{
    return a.compare(b) == 0;
}
inline bool operator!=(const FUN_0044a4c0& a, const char* b)
{
    return !(a == b);
}
class ParserCtype : public facetDEB0
{
  public:
    virtual void facetSlot1();
    virtual void facetSlot2();
    virtual void facetSlot3();
    virtual void facetSlot4();
    virtual void facetSlot5();
    virtual char do_widen(char) const;
    char widen(char ch) const
    {
        return do_widen(ch);
    }
};
extern const ParserCtype& __cdecl ParserUseFacet(const localeDEB0&);
class ParserIos : public basic_iosDEB0
{
  public:
    int state;
    int rdstate() const
    {
        return state;
    }
    bool eof() const
    {
        return rdstate() & 1;
    }
    bool fail() const
    {
        return (rdstate() & 6) != 0;
    }
    localeDEB0 GetLocale() const;
    char FUN_00ad30c0(char ch) const
    {
        const ParserCtype& facet = ParserUseFacet(GetLocale());
        return facet.widen(ch);
    }
};
class ParserStream : virtual public ParserIos
{
  public:
    virtual ~ParserStream();
    int count;
    int FUN_00aca7a0();
    int FUN_00aca560();
};
extern ParserStream& __cdecl FUN_00ad43a0(ParserStream&, FUN_0044a4c0&);
extern ParserStream& __cdecl FUN_00ad5770(ParserStream&, FUN_0044a4c0&, char);
inline ParserStream& ReadParserLine(ParserStream& stream, FUN_0044a4c0& value)
{
    return FUN_00ad5770(stream, value, stream.FUN_00ad30c0('\n'));
}
namespace pairparser {
struct FUN_00acb310
{
    FUN_0044a4c0 first, second;
    FUN_00acb310(const FUN_0044a4c0& a, const FUN_0044a4c0& b) : first(a), second(b)
    {}
};
}
struct ParserPairs : GvVector<pairparser::FUN_00acb310>
{
    void FUN_00acb3c0(const pairparser::FUN_00acb310& value)
    {
        if (size() < capacity())
            _Mylast = _Ufill(_Mylast, 1, value);
        else
            insert(end(), value);
    }
};
// @fnv 0x00ac7f50
bool __cdecl FUN_00ac7f50(ParserStream* stream, ParserPairs* result, const FUN_0044a4c0* excluded, int limit)
{
    FUN_0044a4c0 key;
    int entries = 0;
    while (!stream->eof() && !stream->fail() && (!limit || entries < limit))
    {
        FUN_00ad43a0(*stream, key);
        if (stream->eof() || stream->fail())
            break;
        char next;
        while (!stream->eof() && !stream->fail())
        {
            next = stream->FUN_00aca7a0();
            if (next == '\n' || stream->eof() || stream->fail())
                break;
            else if (next == ' ' || next == '\t')
                next = stream->FUN_00aca560();
            else
                break;
        }
        FUN_0044a4c0 value("");
        if (!stream->eof() && !stream->fail())
            ReadParserLine(*stream, value);
        if (key == *excluded && *excluded != "")
            continue;
        result->FUN_00acb3c0(pairparser::FUN_00acb310(key, value));
        ++entries;
    }
    if (stream->fail() && !stream->eof())
        return false;
    else
        return true;
}

namespace ac8parse {
extern "C" unsigned strlen(const char*);
template <class T> struct char_traits
{
    static unsigned length(const T* p)
    {
        return strlen(p);
    }
    static T* _Copy_s(T*, unsigned, const T*, unsigned);
    static void assign(T&, const T&);
};
template <class T> struct _Allocator_base
{
};
template <class T> class allocator : public _Allocator_base<T>
{
  public:
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
};
class _Container_base_secure
{
};
class _String_base : public _Container_base_secure
{
};
template <class T, class A> class _String_val : public _String_base
{
  protected:
    _String_val(A al = A()) : allocatorValue(al)
    {}
    _String_val(const _String_val& other) : allocatorValue(other.allocatorValue)
    {}
    A allocatorValue;
};
template <class E, class T, class A> class basic_string : public _String_val<E, A>
{
    typedef _String_val<E, A> Base;

  public:
    union Storage
    {
        E buf[16];
        E* ptr;
    } storage;
    unsigned len, res;
    int FUN_00ac9da0(const basic_string&) const;

    basic_string(const E* p) : Base()
    {
        FUN_0044a730(false, 0);
        assign(p);
    }
    basic_string& assign(const E* p)
    {
        return assign(p, T::length(p));
    }
    basic_string& assign(const E* p, unsigned n)
    {
        if (_Inside(p))
            return AssignSubstring(*this, unsigned(p - _Myptr()), n);
        if (_Grow(n, false))
        {
            T::_Copy_s(_Myptr(), res, p, n);
            _Eos(n);
        }
        return *this;
    }
    bool _Inside(const E*);
    bool _Grow(unsigned, bool);
    E* _Myptr()
    {
        return 16 <= res ? storage.ptr : storage.buf;
    }
    void _Eos(unsigned n)
    {
        const E zero = E();
        len = n;
        T::assign(_Myptr()[n], zero);
    }
    inline basic_string() : Base()
    {
        FUN_0044a730(false, 0);
    }
    inline basic_string(const basic_string& r) : Base(r)
    {
        FUN_0044a730(false, 0);
        AssignSubstring(r, 0, DAT_010173f0);
    }
    inline ~basic_string()
    {
        FUN_0044a730(true, 0);
    }
    const E* c_str() const
    {
        return 16 <= res ? storage.ptr : storage.buf;
    }
    basic_string& AssignSubstring(const basic_string&, unsigned, unsigned);

  protected:
    void FUN_0044a730(bool, unsigned);
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
using namespace ac8parse;
namespace ac8parse {
typedef string Str;
inline bool operator==(const Str& a, const Str& b)
{
    return a.FUN_00ac9da0(b) == 0;
}
inline bool operator!=(const Str& a, const Str& b)
{
    return !(a == b);
}
void FUN_00ec7c56();  // -> 0x00ec7c56  (_invalid_parameter)

struct Tok
{
    Str a, b;
    Tok();
};
struct Vec
{
    unsigned allocatorProxy;
    unsigned iteratorProxy;
    unsigned unk08;
    Tok* first;
    Tok* last;
    Tok* end;
    void FUN_00acf580(unsigned, Tok);
    inline void resize(unsigned n)
    {
        FUN_00acf580(n, Tok());
    }
    inline Tok& operator[](unsigned i)
    {
        if (!(i < (unsigned)(last - first)))
            ac8parse::FUN_00ec7c56();
        return first[i];
    }
};
struct Big;
struct VB
{  // virtual base at Big+0x58
    VB();
    virtual ~VB();
    unsigned unk04;
    int flags;
    unsigned unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int rdstate() const
    {
        return flags;
    }
    bool fail() const
    {
        return (rdstate() & 6) != 0;
    }
    void FUN_00acc8c0();
    void FUN_00aca4b0();
};
struct FileBuf
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c;
    FileBuf();
    ~FileBuf();
    FileBuf* Open(const char*, int, int);
};
struct Input : virtual VB
{
    unsigned count;
    Input(FileBuf*);
    virtual ~Input()
    {}
};
struct Big : Input
{
    FileBuf buffer;
    void Init(FileBuf*, bool);
    void SetState(int);
    Big(const char* filename, int mode, int prot) : Input(&buffer)
    {
        if (!buffer.Open(filename, mode | 1, prot))
            SetState(2);
    }
    virtual ~Big()
    {}
};

void FUN_00ac6430(int, Str);  // -> 0x00ac6430  SetError(int, string)
bool FUN_00ac7f50(Big*, Vec*, const Str&, int);

}

// @fnv 0x00ac8c50
bool FUN_00ac8c50(const Str& name, const Str& arg2, Vec* pVec)
{
    Str msg5;
    Big kObj(name.c_str(), 1, 0x40);
    if (kObj.fail())
    {
        ac8parse::FUN_00ac6430(4, name);
        return false;
    }
    pVec->resize(0);
    if (!FUN_00ac7f50(&kObj, pVec, "//", 1))
    {
        ac8parse::FUN_00ac6430(4, name);
        return false;
    }
    if ((*pVec)[0].a != arg2)
    {
        ac8parse::FUN_00ac6430(2, name);
        return false;
    }
    pVec->resize(0);
    if (!FUN_00ac7f50(&kObj, pVec, "//", 0))
    {
        ac8parse::FUN_00ac6430(4, name);
        return false;
    }
    else
    {
        return true;
    }
}

extern bool __cdecl CanOpenFile(void*);
template <> __declspec(noinline) GvAuxBase<GvAlloc<BxString> >::~GvAuxBase()
{
    _Myownedaux->~GvAuxCont();
    _Alaux.deallocate(_Myownedaux, 1);
}
template <class T> struct CsvArray : GvVector<T>
{
};
typedef CsvArray<BxString> CsvRow;
namespace std {
class ios_base
{
  public:
    virtual ~ios_base()
    {
        FUN_00ec3205(this);
    }
    static void __cdecl FUN_00ec3205(ios_base*);
    unsigned int standardStream;
    int state, exceptions, format, precision, width;
    void* array;
    void* callbacks;
    localeDEB0* locale;
    int rdstate() const
    {
        return state;
    }
    bool eof() const
    {
        return (int)rdstate() & 1;
    }
    bool fail() const
    {
        return ((int)rdstate() & (4 | 2)) != 0;
    }
    localeDEB0 getloc() const
    {
        return *locale;
    }
    void setstate(int);
};
template <class E> struct CsvCtype
{
    E widen(char) const;
};
template <class E> const CsvCtype<E>& CsvUseFacet(const localeDEB0&);
template <class E, class Tr> class basic_ios : public ios_base
{
  public:
    virtual ~basic_ios()
    {}
    E FUN_00ad30c0(char c) const
    {
        const CsvCtype<E>& facet = CsvUseFacet<E>(getloc());
        return facet.widen(c);
    }
    void init(basic_streambufDEB0*, bool);
    basic_streambufDEB0* streambuf;
    void* tied;
    E fill;
};
template <class E, class Tr> class basic_istream : virtual public basic_ios<E, Tr>
{
  public:
    explicit basic_istream(basic_streambufDEB0* sb, bool isstd = false) : count(0)
    {
        this->init(sb, isstd);
    }
    virtual ~basic_istream()
    {}
    int count;
};
template <class E, class Tr> class basic_ifstream : public basic_istream<E, Tr>
{
  public:
    basic_ifstream(const char* name, int mode, int prot) : basic_istream<E, Tr>(&filebuf)
    {
        filebuf._Init(0, basic_filebufDEB0::_Newfl);
        if (open(name, mode | 1, prot) == 0)
            this->setstate(2);
    }
    basic_filebufDEB0* open(const char*, int, int);
    virtual ~basic_ifstream()
    {}
    basic_filebufDEB0 filebuf;
};
typedef basic_ifstream<char, char_traits<char> > ifstream;
basic_istream<char, char_traits<char> >& FUN_00ad5770(basic_istream<char, char_traits<char> >&, BxString&, char);
inline basic_istream<char, char_traits<char> >& getline(basic_istream<char, char_traits<char> >& input, BxString& line)
{
    return FUN_00ad5770(input, line, input.FUN_00ad30c0('\n'));
}
}
// @fnv 0x00ac9120
bool __cdecl FUN_00ac9120(const BxString& path, CsvArray<CsvRow>& table)
{

    table.clear();

    CsvRow row;

    if (!CanOpenFile((void*)&path))
    {
        FUN_00ac6430(3, path);
        return false;
    }

    std::ifstream input(path.c_str(), 1, 64);

    if (input.fail())
    {
        FUN_00ac6430(4, path);
        return false;
    }

    while (!input.eof() && !input.fail())
    {

        BxString line;

        std::getline(input, line);

        if (!input.fail())
        {

            char ch[2] = {0, 0};

            const char* p = line.c_str();

            bool empty = true;

            row.clear();

            while (*p != '\n' && *p != '\0')
            {

                BxString entry("");

                bool quote = false;

                if (*p == '"')
                {
                    quote = true;
                    ++p;
                }

                for (; (*p != ',' || quote) && *p != '\0' && *p != '\n'; ++p)
                {

                    if (*p == '"')
                    {
                        quote = !quote;
                        continue;
                    }

                    if (*p != ' ' && *p != '\t')
                        empty = false;

                    ch[0] = *p;

                    entry += ch;
                }

                if (*p != '\0')
                    ++p;

                row.push_back(entry);
            }

            if (!empty)
                table.push_back(row);
        }
    }

    if (!input.eof() && input.fail())
    {
        FUN_00ac6430(1, path);
        return false;
    }

    return true;
}

namespace fnv_00ac9ff0 {
namespace std {
class Str_ac9ff0 : public BxStringVal
{
  public:
    Str_ac9ff0(const char* s) : BxStringVal()
    {
        _Tidy(false, 0);
        reinterpret_cast<BxString*>(this)->assign(s);
    }
    Str_ac9ff0(const Str_ac9ff0& right) : BxStringVal(right)
    {
        _Tidy(false, 0);
        reinterpret_cast<BxString*>(this)->assign(reinterpret_cast<const BxString&>(right), 0, DAT_010173f0);
    }
    ~Str_ac9ff0()
    {
        _Tidy(true, 0);
    }
    void _Tidy(bool built, unsigned int count)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* old = storage._Ptr;
            if (0 < count)
                BxTraitsHelper::copy_s<BxStrTraits>(storage._Buf, 16, old, count);
            _Alval.deallocate(old, capacity + 1);
        }
        capacity = 15;
        eos(count);
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int n)
    {
        BxStrTraits::assign(data()[length = n], char());
    }
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
};
typedef Str_ac9ff0 string;

class exception
{
  public:
    exception();
    exception(const exception&);
    virtual ~exception();
    const char* _m_what;
    int _m_doFree;
};

class runtime_error : public exception
{
  public:
    explicit runtime_error(const string& _Message) : _Str(_Message)
    {}
    virtual ~runtime_error()
    {}
    string _Str;
};

class ios_base
{
  public:
    class failure : public runtime_error
    {
      public:
        explicit failure(const string& _Message) : runtime_error(_Message)
        {}
        virtual ~failure()
        {}
    };
    void FUN_00ac9ff0(int _State, bool _Reraise);
    int unk00;
    int unk04;
    int _Mystate;
    int _Except;
};

// @fnv 0x00ac9ff0
void ios_base::FUN_00ac9ff0(int _State, bool _Reraise)
{
    _Mystate = _State & 0x17;
    if ((_Mystate & _Except) == 0)
        ;
    else if (_Reraise)
        throw;
    else if (_Mystate & _Except & 4)
        throw failure("ios_base::badbit set");
    else if (_Mystate & _Except & 2)
        throw failure("ios_base::failbit set");
    else
        throw failure("ios_base::eofbit set");
}
}
}  // namespace fnv_00ac9ff0

inline bool InsertionEqualAlloc(const BxCharAlloc&, const BxCharAlloc&)
{
    return true;
}
class InsertionText : public BxStringVal
{
  public:
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    InsertionText(const InsertionText& right) : BxStringVal(right)
    {
        FUN_0044a730(false, 0);
        AssignSubstring(right, 0, DAT_010173f0);
    }
    ~InsertionText()
    {
        FUN_0044a730(true, 0);
    }
    InsertionText& operator=(const InsertionText& right)
    {
        return AssignSubstring(right, 0, DAT_010173f0);
    }
    unsigned int size() const
    {
        return length;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    InsertionText& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (length < _Off)
        {
            StringBase::_Xran();
        }
        if (length - _Off < _Count)
        {
            _Count = length - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(data() + _Off, capacity - _Off, data() + _Off + _Count,
                                                length - _Off - _Count);
            unsigned int _Newsize = length - _Count;
            eos(_Newsize);
        }
        return *this;
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < capacity / 2 && capacity <= max_size() - capacity / 2)
        {
            _Newres = capacity + capacity / 2;
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
                FUN_0044a730(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            std::_Traits_helper::copy_s<std::char_traits<char> >(_Ptr, _Newres + 1, data(), _Oldlen);
        }
        FUN_0044a730(true);
        storage._Ptr = _Ptr;
        capacity = _Newres;
        eos(_Oldlen);
    }
    bool grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            StringBase::_Xlen();
        }
        if (capacity < _Newsize)
        {
            _Copy(_Newsize, length);
        }
        else if (_Trim && _Newsize < 16)
        {
            FUN_0044a730(true, _Newsize < length ? _Newsize : length);
        }
        else if (_Newsize == 0)
        {
            eos(0);
        }
        return 0 < _Newsize;
    }
    const char* data() const
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    InsertionText& AssignSubstring(const InsertionText& right, unsigned int off, unsigned int count)
    {
        if (right.size() < off)
            StringBase::_Xran();
        unsigned int n = right.length - off;
        if (count < n)
            n = count;
        if (this == &right)
            erase(off + n), erase(0, off);
        else if (grow(n))
        {
            std::_Traits_helper::copy_s<std::char_traits<char> >(data(), capacity, right.data() + off, n);
            eos(n);
        }
        return *this;
    }
    void swap(InsertionText& right)
    {
        if (this == &right)
            ;
        else if (InsertionEqualAlloc(_Alval, right._Alval))
        {
            BxQ_ad6bb0 saved = storage;
            storage = right.storage;
            right.storage = saved;
            unsigned int savedLength = length;
            length = right.length;
            right.length = savedLength;
            unsigned int savedCapacity = capacity;
            capacity = right.capacity;
            right.capacity = savedCapacity;
        }
        else
        {
            InsertionText saved = *this;
            *this = right;
            right = saved;
        }
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int n)
    {
        std::char_traits<char>::assign(data()[length = n], char());
    }
    void FUN_0044a730(bool built = false, unsigned int n = 0)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* ptr = storage._Ptr;
            if (0 < n)
                std::_Traits_helper::copy_s<std::char_traits<char> >(storage._Buf, 16, ptr, n);
            _Alval.deallocate(ptr, capacity + 1);
        }
        capacity = 15;
        eos(n);
    }
};

InsertionText* __cdecl FUN_00ad5310(unsigned int, InsertionText*);
namespace wrac52 {
template <> inline InsertionText* BxAllocT<InsertionText>::allocate(unsigned int count)
{
    return FUN_00ad5310(count, (InsertionText*)0);
}
}
struct InsertAlloc : BxAllocT<InsertionText>
{
    void destroy(InsertionText* p)
    {
        GvDestroyOne(p);
    }
};
void __cdecl FUN_00ad5b00(InsertionText*, unsigned int, const InsertionText&, InsertAlloc&, GvNonscalarTag,
                          GvRangeCheckedTag);
namespace wrac52 {
template <>
inline void GvUncheckedFillN<InsertionText, InsertAlloc>(InsertionText* first, unsigned int count,
                                                         const InsertionText& value, InsertAlloc& al)
{
    FUN_00ad5b00(first, count, value, al, GvPtrCat(first, first), GvRangeCheckedTag());
}
}
InsertionText* __cdecl FUN_00ad66e0(InsertionText*, InsertionText*, InsertionText*, InsertAlloc&, InsertMoveTag,
                                    GvRangeCheckedTag);
InsertionText* __cdecl FUN_00ad5dd0(InsertionText*, InsertionText*, InsertionText*, InsertAlloc&);
inline InsertionText* InsertMove(InsertionText* first, InsertionText* last, InsertionText* dest, InsertAlloc& al)
{
    return FUN_00ad66e0(GvCheckedBase(first), GvCheckedBase(last), dest, al, InsertMoveCat(dest), GvRangeCheckedTag());
}
inline void __cdecl InsertionSwap(InsertionText& left, InsertionText& right)
{
    left.swap(right);
}
template <class T> inline void InsertionSwapAdl(T& left, T& right)
{
    InsertionSwap(left, right);
}
template <class I, class O, class C> inline O BackwardOpt(I first, I last, O dest, C, InsertMoveTag, GvRangeCheckedTag)
{
    while (first != last)
        InsertionSwapAdl(*--dest, *--last);
    return dest;
}
template <class I, class O>
inline O BackwardOpt(I first, I last, O dest, GvRandomTag, InsertMoveTag cat, GvRangeCheckedTag)
{
    O result = dest - (last - first);
    BackwardOpt(first, last, GvCheckedBase(dest), GvForwardTag(), cat, GvRangeCheckedTag());
    return result;
}
inline InsertionText* __cdecl FUN_00ad5250(InsertionText* first, InsertionText* last, InsertionText* dest)
{
    return BackwardOpt(GvCheckedBase(first), GvCheckedBase(last), dest, GvIterRandom(first, dest), InsertMoveCat(dest),
                       GvRangeCheckedTag());
}
template <class I, class T> inline void InsertFillInner(I first, I last, const T& value)
{
    for (; first != last; ++first)
        *first = value;
}
template <class I, class T> inline void InsertFill(I first, I last, const T& value)
{
    InsertFillInner(GvCheckedBase(first), GvCheckedBase(last), value);
}

struct InsertStrings : GvAuxBase<InsertAlloc>
{
    typedef unsigned int size_type;
    typedef InsertionText value_type;
    typedef InsertionText* pointer;
    typedef GvConstIterator<InsertionText> const_iterator;
    InsertAlloc _Alval;
    pointer _Myfirst, _Mylast, _Myend;
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type max_size() const
    {
        return _Alval.max_size();
    }
    void _Destroy(pointer first, pointer last)
    {
        GvDestroyRange(first, last, _Alval);
    }
    pointer _MoveSuffix(pointer first, pointer last, pointer dest)
    {
        return FUN_00ad5dd0(first, last, dest, _Alval);
    }
    pointer _Umove(pointer first, pointer last, pointer dest)
    {
        return InsertMove(first, last, dest, _Alval);
    }
    pointer _Ufill(pointer ptr, size_type count, const InsertionText& value)
    {
        GvUncheckedFillN(ptr, count, value, _Alval);
        return ptr + count;
    }
    static void FUN_00ac0b00()
    {
        throw BxLengthError("vector<T> too long");
    }
    void FUN_00ad07c0(const_iterator, size_type, const InsertionText&);
};
// @fnv 0x00ad07c0
void InsertStrings::FUN_00ad07c0(const_iterator _Where, size_type _Count, const InsertionText& _Val)
{
    size_type _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        FUN_00ac0b00();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(this->_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _MoveSuffix(_Where._Myptr, this->_Mylast, _Ptr);
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
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        value_type _Tmp = _Val;
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        InsertFill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        value_type _Tmp = _Val;
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00ad5250(_Where._Myptr, _Oldend - _Count, _Oldend);
        InsertFill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

struct PairAssignView
{
    void* al;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned size;
    unsigned res;
    PairAssignView& AssignSubstring(const PairAssignView& other, unsigned int offset, unsigned int count)
    {
        BxString* dest = (BxString*)this;
        if (other.size < offset)
            BxString::_Xran();
        unsigned int copied = other.size - offset;
        if (count < copied)
            copied = count;
        if (this == &other)
            dest->erase(offset + copied), dest->erase(0, offset);
        else if (dest->_Grow(copied))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(dest->_Myptr(), res, ((const BxString&)other)._Myptr() + offset,
                                                copied);
            dest->_Eos(copied);
        }
        return *this;
    }
};

template <class K, class V> struct PairRecord
{
    K first;
    V second;
    static void operator delete(void* p)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(p);
    }
    PairRecord() : first(), second()
    {}
    PairRecord(const K& key, const V& value) : first(key), second(value)
    {}
    template <class A, class B> PairRecord(const PairRecord<A, B>& other) : first(other.first), second(other.second)
    {}
};
typedef PairRecord<unsigned int, BxString> PointPair;

void ThrowVectorTooLong();
extern "C" PointPair* __cdecl FUN_0065e430(unsigned int, PointPair*);
PointPair* CallWithIterators(PointPair*, PointPair*, PointPair*, GvAlloc<PointPair>&);
PointPair* FUN_00ac1da0(PointPair*, PointPair*, PointPair*, GvAlloc<PointPair>&);
PointPair* FUN_00ac1580(PointPair*, PointPair*, PointPair*);

template <class T> struct PairAllocator : GvAlloc<T>
{
    T* allocate(unsigned int count)
    {
        return FUN_0065e430(count, (T*)0);
    }
};
template <class T> struct PairVectorVal : GvAuxBase<PairAllocator<T> >
{
    PairAllocator<T> _Alval;
};

struct PairMoveTag
{
};
template <class I> inline PairMoveTag PairMoveCategory(I&)
{
    PairMoveTag tag;
    return tag;
}

template <class I, class O, class A, class M>
__forceinline O PairUninitMove(I first, I last, O dest, A& alloc, M, GvRangeCheckedTag)
{
    return CallWithIterators(first, last, dest, alloc);
}
template <class I, class O, class A> __forceinline O PairUncheckedMove(I first, I last, O dest, A& alloc)
{
    return PairUninitMove(GvCheckedBase(first), GvCheckedBase(last), dest, alloc, PairMoveCategory(dest),
                          GvRangeCheckedTag());
}
template <class I, class V> inline void PairFillRange(I first, I last, const V& _Val)
{
    for (; first != last; ++first)
        *first = _Val;
}
template <class I, class V> inline void PairFill(I first, I last, const V& _Val)
{
    PairFillRange(GvCheckedBase(first), GvCheckedBase(last), _Val);
}

template <class I, class O, class C>
__declspec(noinline) O PairCopyBackward(I first, I last, O dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
template <class I, class O>
__declspec(noinline) O PairCopyBackward(I first, I last, O dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O result = dest - (last - first);
    PairCopyBackward(first, last, GvCheckedBase(dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return result;
}
template <class I, class O, class C, class M>
inline O PairMoveBackward(I first, I last, O dest, C cat, M, GvRangeCheckedTag)
{
    return PairCopyBackward(first, last, dest, cat, GvPtrCat(first, dest), GvRangeCheckedTag());
}
inline PointPair* FUN_00ac1580(PointPair* first, PointPair* last, PointPair* dest)
{
    return PairMoveBackward(GvCheckedBase(first), GvCheckedBase(last), dest, GvIterRandom(first, dest),
                            PairMoveCategory(dest), GvRangeCheckedTag());
}

template <class I, class V> inline void LastFillRange(I first, I last, const V& value)
{
    for (; first != last; ++first)
    {
        first->first = value.first;
        ((PairAssignView&)first->second).AssignSubstring((const PairAssignView&)value.second, 0, DAT_010173f0);
    }
}
template <class I, class V> inline void LastFill(I first, I last, const V& value)
{
    LastFillRange(GvCheckedBase(first), GvCheckedBase(last), value);
}
template <class T> struct PairInsertionVector : PairVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
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
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    T* _Ufill(T* p, unsigned int n, const T& val)
    {
        GvUncheckedFillN(p, n, val, this->_Alval);
        return p + n;
    }

    void FUN_0065dc60(T*, T*);
    template <class I> T* _Umove(I first, I last, T* dest)
    {
        return PairUncheckedMove(first, last, dest, this->_Alval);
    }
    T* _UmoveSuffix(T* first, T* last, T* dest)
    {
        return FUN_00ac1da0(first, last, dest, this->_Alval);
    }
    void FUN_00abe310(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
};

template <class T> inline void PairInsertionVector<T>::FUN_0065dc60(T* first, T* last)
{
    GvDestroyRange(first, last, this->_Alval);
}

// @fnv 0x00abe310
template <class T>
void PairInsertionVector<T>::FUN_00abe310(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val)
{
    unsigned int _Capacity = capacity();
    if (_Count == 0)
    {
    }
    else if (max_size() - size() < _Count)
    {
        _Xlen();
    }
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        T* _Newvec = this->_Alval.allocate(_Capacity);
        T* _Ptr = _Newvec;
        try
        {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _UmoveSuffix(_Where._Myptr, _Mylast, _Ptr);
        }
        catch (...)
        {
            FUN_0065dc60(_Newvec, _Ptr);
            this->_Alval.deallocate(_Newvec, _Capacity);
            throw;
        }
        _Count += size();
        if (_Myfirst != 0)
        {
            FUN_0065dc60(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((unsigned int)(_Mylast - _Where._Myptr) < _Count)
    {
        T _Tmp = _Val;
        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);
        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            FUN_0065dc60(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }
        _Mylast += _Count;
        PairFill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        T _Tmp = _Val;
        T* _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        FUN_00ac1580(_Where._Myptr, _Oldend - _Count, _Oldend);
        LastFill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

template void PairInsertionVector<PointPair>::FUN_00abe310(GvConstIterator<PointPair>, unsigned int, const PointPair&);

// inline copy of the unit's StrQ_ad6bb0::FUN_00ad6bb0 (string swap): the original inlined it here
struct StrQSwap_ad6bb0 : StrQ_ad6bb0
{
    inline void Swap(StrQ_ad6bb0& other)
    {
        if (this == &other)
        {
        }
        else if (_Alval == other._Alval)
        {
            BxQ_ad6bb0 buffer = _Bx;
            _Bx = other._Bx, other._Bx = buffer;
            unsigned length = _Mysize;
            _Mysize = other._Mysize, other._Mysize = length;
            unsigned capacity = _Myres;
            _Myres = other._Myres, other._Myres = capacity;
        }
        else
        {
            BxString saved = *(BxString*)this;
            *(BxString*)this = *(BxString*)&other;
            *(BxString*)&other = saved;
        }
    }
};
inline void swap(BxString& _Left, BxString& _Right)
{
    ((StrQSwap_ad6bb0*)&_Left)->Swap(*(StrQ_ad6bb0*)&_Right);
}
// @fnv 0x00ad66e0
BxString* __cdecl FUN_00ad66e0(BxString* _First, BxString* _Last, BxString* _Dest, GvAlloc<BxString>& _Al)
{
    BxString* _Next = _Dest;
    BxString _Val;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, _Val);
            swap(*_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.destroy(_Next);
        throw;
    }
    return _Dest;
}

namespace Insert52Detail {

extern "C" void* __cdecl FUN_0065e550(unsigned int, int);
extern const char DAT_010173c4[];
struct ErrorText
{
    unsigned char allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    explicit ErrorText(const char*);
    ~ErrorText();
};
struct InsertionLengthError
{
    virtual ~InsertionLengthError();
    const char* message;
    bool ownsMessage;
    ErrorText detail;
    explicit InsertionLengthError(const ErrorText&);
};
inline void __cdecl ThrowVectorTooLong()
{
    throw InsertionLengthError(ErrorText(DAT_010173c4));
}
struct Point3
{
    float x, y, z;
};
struct Element52
{
    BxString name;
    GvVector<Point3> points;
    Element52(const Element52& other) : name(other.name), points(other.points)
    {}
    ~Element52()
    {}
    static void operator delete(void* p)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(p);
    }
};
template <class T> struct InsertAllocator
{
    typedef T* pointer;
    InsertAllocator() throw()
    {}
    InsertAllocator(const InsertAllocator&) throw()
    {}
    template <class O> InsertAllocator(const InsertAllocator<O>&) throw()
    {}
    pointer allocate(unsigned int n)
    {
        return (pointer)FUN_0065e550(n, 0);
    }
    void deallocate(pointer p, unsigned int)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(p);
    }
    void destroy(pointer p)
    {
        GvDestroyOne(p);
    }
    void construct(pointer p, const T& v)
    {
        GvConstruct(p, v);
    }
    unsigned int max_size() const throw()
    {
        unsigned int count = (unsigned int)(-1) / sizeof(T);
        return 0 < count ? count : 1;
    }
};
template <class T> struct InsertVectorVal : GvAuxBase<InsertAllocator<T> >
{
    InsertAllocator<T> _Alval;
    InsertVectorVal(InsertAllocator<T> a = InsertAllocator<T>()) : GvAuxBase<InsertAllocator<T> >(a), _Alval(a)
    {}
};
template <class T, class A>
inline void InsertUninitFillN(T* first, unsigned int count, const T& value, A& alloc, GvNonscalarTag, GvRangeCheckedTag)
{
    T* next = first;
    try
    {
        for (; 0 < count; --count, ++first)
            alloc.construct(first, value);
    }
    catch (...)
    {
        for (; next != first; ++next)
            alloc.destroy(next);
        throw;
    }
}
template <class T, class A> inline void InsertUncheckedFillN(T* first, unsigned int count, const T& value, A& alloc)
{
    InsertUninitFillN(first, count, value, alloc, GvPtrCat(first, first), GvRangeCheckedTag());
}
struct InsertMoveTag
{
};
template <class I> inline InsertMoveTag InsertMoveCategory(const I&)
{
    InsertMoveTag tag;
    return tag;
}
template <class I, class O, class A>
inline O InsertUninitMove(I first, I last, O dest, A& alloc, InsertMoveTag, GvRangeCheckedTag)
{
    return GvUncheckedUninitCopy(first, last, dest, alloc);
}
template <class I, class O, class A> inline O InsertUncheckedMove(I first, I last, O dest, A& alloc)
{
    return InsertUninitMove(GvCheckedBase(first), GvCheckedBase(last), dest, alloc, InsertMoveCategory(dest),
                            GvRangeCheckedTag());
}
template <class I, class T> inline void InsertFillLoop(I first, I last, const T& value)
{
    for (; first != last; ++first)
        *first = value;
}
template <class I, class T> inline void InsertFill(I first, I last, const T& value)
{
    InsertFillLoop(GvCheckedBase(first), GvCheckedBase(last), value);
}
template <class I, class O, class C>
inline O InsertBackwardCopy(I first, I last, O dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
template <class I, class O>
inline O InsertBackwardCopy(I first, I last, O dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O result = dest - (last - first);
    InsertBackwardCopy(first, last, GvCheckedBase(dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return result;
}
template <class I, class O, class C>
inline O InsertBackwardDispatch(I first, I last, O dest, C cat, InsertMoveTag, GvRangeCheckedTag)
{
    return InsertBackwardCopy(first, last, dest, cat, GvPtrCat(first, dest), GvRangeCheckedTag());
}
template <class I, class O> inline O InsertMoveBackward(I first, I last, O dest)
{
    return InsertBackwardDispatch(GvCheckedBase(first), GvCheckedBase(last), dest, GvIterRandom(first, dest),
                                  InsertMoveCategory(dest), GvRangeCheckedTag());
}
struct ElementVector : InsertVectorVal<Element52>
{
    typedef Element52* pointer;
    typedef unsigned int size_type;
    typedef GvConstIterator<Element52> const_iterator;
    pointer _Myfirst, _Mylast, _Myend;
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type max_size() const
    {
        return this->_Alval.max_size();
    }
    void _Destroy(pointer first, pointer last)
    {
        GvDestroyRange(first, last, this->_Alval);
    }
    pointer _Ufill(pointer dest, size_type count, const Element52& value)
    {
        InsertUncheckedFillN(dest, count, value, this->_Alval);
        return dest + count;
    }
    template <class I> pointer _Umove(I first, I last, pointer dest)
    {
        return InsertUncheckedMove(first, last, dest, this->_Alval);
    }
    static void _Xlen()
    {
        ThrowVectorTooLong();
    }
    void FUN_00abf210(const_iterator, size_type, const Element52&);
};

// @fnv 0x00abf210
void ElementVector::FUN_00abf210(const_iterator _Where, size_type _Count, const Element52& _Val)
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
        pointer _Ptr = _Newvec;

        try
        {
            _Ptr = _Umove(_Myfirst, _Where._Myptr, _Newvec);
            _Ptr = _Ufill(_Ptr, _Count, _Val);
            _Umove(_Where._Myptr, _Mylast, _Ptr);
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
    else if ((size_type)(_Mylast - _Where._Myptr) < _Count)
    {
        Element52 _Tmp = _Val;

        _Umove(_Where._Myptr, _Mylast, _Where._Myptr + _Count);

        try
        {
            _Ufill(_Mylast, _Count - (_Mylast - _Where._Myptr), _Tmp);
        }
        catch (...)
        {
            _Destroy(_Where._Myptr + _Count, _Mylast + _Count);
            throw;
        }

        _Mylast += _Count;

        InsertFill(_Where._Myptr, _Mylast - _Count, _Tmp);
    }
    else
    {
        Element52 _Tmp = _Val;

        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);

        InsertMoveBackward(_Where._Myptr, _Oldend - _Count, _Oldend);
        InsertFill(_Where._Myptr, _Where._Myptr + _Count, _Tmp);
    }
}

}

struct ResizeText : BxStringVal
{
    BxQ_ad6bb0 storage;
    unsigned int length, capacity;
    ResizeText& operator=(const ResizeText& other)
    {
        reinterpret_cast<BxString*>(this)->assign(reinterpret_cast<const BxString&>(other), 0, ~0u);
        return *this;
    }
    ~ResizeText()
    {
        FUN_0044a730(true, 0);
    }
    char* data()
    {
        return 16 <= capacity ? storage._Ptr : storage._Buf;
    }
    void eos(unsigned int n)
    {
        BxStrTraits::assign(data()[length = n], char());
    }
    void FUN_0044a730(bool built, unsigned int n)
    {
        if (!built)
            ;
        else if (16 <= capacity)
        {
            char* old = storage._Ptr;
            if (0 < n)
                BxTraitsHelper::copy_s<BxStrTraits>(storage._Buf, 16, old, n);
            BxCharAlloc& allocator = _Alval;
            allocator.deallocate(old, capacity + 1);
        }
        capacity = 15;
        eos(n);
    }
};
struct ResizeEntry
{
    unsigned int key;
    ResizeText text;
};

struct ResizeConstIterator : GvIterBase
{
    ResizeEntry* _Myptr;
    ResizeConstIterator(ResizeEntry* ptr, const GvContainer* container)
    {
        if (!(container != 0 && static_cast<const GvVector<ResizeEntry>*>(container)->_Myfirst <= ptr &&
              ptr <= static_cast<const GvVector<ResizeEntry>*>(container)->_Mylast))
            ::FUN_00ec7c56();
        _Set_container(container);
        _Myptr = ptr;
    }
    ResizeConstIterator& FUN_00ac0b80(int offset);
    bool operator==(const ResizeConstIterator& other) const
    {
        if (!(_Has_container() && _Same_container(other)))
            ::FUN_00ec7c56();
        return _Myptr == other._Myptr;
    }
    bool operator!=(const ResizeConstIterator& other) const
    {
        return !(*this == other);
    }
};
struct ResizeIterator : ResizeConstIterator
{
    ResizeIterator(ResizeEntry* ptr, const GvContainer* container) : ResizeConstIterator(ptr, container)
    {}
    ResizeIterator& operator+=(int offset)
    {
        static_cast<ResizeConstIterator&>(*this).FUN_00ac0b80(offset);
        return *this;
    }
    ResizeIterator operator+(int offset) const
    {
        ResizeIterator result = *this;
        return result += offset;
    }
};
struct ResizeEntries : GvVector<ResizeEntry>
{
    ResizeIterator begin()
    {
        return ResizeIterator(_Myfirst, this);
    }
    ResizeIterator end()
    {
        return ResizeIterator(_Mylast, this);
    }
    void FUN_00abe310(ResizeConstIterator, unsigned int, const ResizeEntry&);
    ResizeIterator makeIterator(ResizeConstIterator where) const
    {
        return ResizeIterator(where._Myptr, this);
    }
    ResizeIterator FUN_00abb280(ResizeConstIterator firstArg, ResizeConstIterator lastArg)
    {
        ResizeIterator first = makeIterator(firstArg);
        ResizeIterator last = makeIterator(lastArg);
        if (first != last)
        {
            ResizeEntry* ptr = GvUncheckedCopy(last._Myptr, _Mylast, first._Myptr);
            _Destroy(ptr, _Mylast);
            _Mylast = ptr;
        }
        return first;
    }
    void FUN_00abb060(unsigned int count, ResizeEntry value);
};

// @fnv 0x00abb060
void ResizeEntries::FUN_00abb060(unsigned int count, ResizeEntry value)
{
    if (size() < count)
        FUN_00abe310(end(), count - size(), value);
    else if (count < size())
        FUN_00abb280(begin() + count, end());
}

namespace fnv_00ad5500 {
extern int DAT_010a31fc;
extern int DAT_010a3228;
extern int DAT_010a3204;

namespace std {
template <class _Elem> struct char_traits
{
    int x;
};
template <class _Elem> class allocator
{
    int x;
};
template <class _Elem, class _Tr, class _Al> class basic_string
{
  public:
    union
    {
        _Elem _Buf[20];
        _Elem* _Ptr;
    } _Bx;
    unsigned int _Mysize, _Myres;
    basic_string()
    {
        bool _Free;
        bool* _P = &_Free;
        _Tidy(false, 0);
    }
    ~basic_string()
    {
        int _Z1;
        (void)_Z1;
        _Tidy(true, 0);
    }

  protected:
    void _Tidy(bool, unsigned int);
};
}
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > GameString;

// base init
void FUN_00ec3740(void* dst, const GameString& src);
void FUN_00ec35d7(void* p);

class TmpCls
{
  public:
    void* m_vtbl;
    GameString m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger;
    void FUN_00ec32e3(int);
    TmpCls(const GameString& s) : m_kPointA(), m_kPointB(), m_iThirdValue(), m_iFourthElementInteger()
    {
        FUN_00ec32e3(0);
        FUN_00ec3740(this, s);
    }
    ~TmpCls()
    {
        int _T1, _T2;
        (void)_T1;
        (void)_T2;
        FUN_00ec35d7(this);
        m_kPointA.~basic_string();
        m_kPointB.~basic_string();
        m_iThirdValue.~basic_string();
        m_iFourthElementInteger.~basic_string();
    }
};

class SrcCls
{
  public:
    GameString FUN_00ad3e60();
};

class ObjBase
{
  public:
    void* m_vtbl;
    int m_refs;
    ObjBase()
    {
        m_vtbl = &DAT_010a31fc;
        m_refs = 0;
    }
};
class ObjMid : public ObjBase
{
  public:
    ObjMid()
    {
        m_vtbl = &DAT_010a3228;
    }
};
class ObjNew : public ObjMid
{
  public:
    ObjNew(const TmpCls&)
    {
        m_vtbl = &DAT_010a3204;
    }
};

// @fnv 0x00ad5500
int FUN_00ad5500(ObjNew** output, SrcCls* source)
{
    if (output && !*output)
        *output = new ObjNew(TmpCls(source->FUN_00ad3e60()));
    return 2;
}
}  // namespace fnv_00ad5500

using ::DAT_010173f0;
namespace rdac5e {
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        ::FUN_0044ccd0(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
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
    return (T*)::operator new(count * sizeof(T));
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
        ::operator delete(_Ptr);
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

    __forceinline BxString(const BxString& _Right) : BxStringVal(_Right)
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
};

void FUN_00ac6430(int code, BxString message);
}

struct FaceBinaryReadReceiver
{
    rdac5e::BxString kPath;
    rdac5e::BxString kMagic;
    int unk3c;
    char* pData;
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual bool v10(void* data, unsigned int size, unsigned int count);
    void ClearHolders();
    __declspec(noinline) bool FUN_00ac5e00(void* data, unsigned int size, unsigned int count);
};

// @fnv 0x00ac5e00
bool FaceBinaryReadReceiver::FUN_00ac5e00(void* data, unsigned int size, unsigned int count)
{
    if (pData == 0)
    {
        return false;
    }
    if (!v10(data, 1, size * count))
    {
        rdac5e::FUN_00ac6430(1, kPath);
        ClearHolders();
        return false;
    }
    return true;
}

extern "C" int DAT_011f6238;
void __cdecl operator delete(void* _Ptr) throw();
namespace plusad42 {
void FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char* _Str);
extern "C" int __cdecl memcmp(const void* _Buf1, const void* _Buf2, unsigned int _Size);
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
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
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
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
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

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&DAT_011f6238)->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(_Ptr);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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

// @fnv 0x00ad4210
plusad42::BxString FUN_00ad4210(const plusad42::BxString& _Left, const char* _Right)
{
    return plusad42::BxString(_Left) += _Right;
}

extern "C" int DAT_011f6238;
void __cdecl operator delete(void* _Ptr) throw();
namespace rdac52 {
void FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char* _Str);
extern "C" int __cdecl memcmp(const void* _Buf1, const void* _Buf2, unsigned int _Size);
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
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
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
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
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

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&DAT_011f6238)->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(_Ptr);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
struct GvFileHandle;
extern "C" unsigned int __cdecl fread(void* _DstBuf, unsigned int _ElementSize, unsigned int _Count,
                                      GvFileHandle* _File);
void FUN_00ac6430(int code, BxString message);
}

struct GvBinaryFile_SV
{
    rdac52::BxString kPath;
    rdac52::BxString kMagic;
    rdac52::GvFileHandle* pFile;
    virtual void v00();
    void FUN_00ac5430();
    bool FUN_00ac52b0(void* data, unsigned int size, unsigned int count);
};

// @fnv 0x00ac52b0
bool GvBinaryFile_SV::FUN_00ac52b0(void* data, unsigned int size, unsigned int count)
{
    if (pFile == 0)
    {
        return false;
    }
    if (rdac52::fread(data, size, count, pFile) != count)
    {
        rdac52::FUN_00ac6430(1, kPath);
        FUN_00ac5430();
        return false;
    }
    return true;
}

extern "C" int DAT_011f6238;
void __cdecl operator delete(void* _Ptr) throw();
namespace plus2ad4 {
void FUN_00ec7c56();
extern "C" unsigned int __cdecl strlen(const char* _Str);
extern "C" int __cdecl memcmp(const void* _Buf1, const void* _Buf2, unsigned int _Size);
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
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
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
    BxString& append(const BxString& _Right)
    {
        return append(_Right, 0, (unsigned int)-1);
    }
    BxString& operator+=(const BxString& _Right)
    {
        return append(_Right);
    }
    const char* c_str() const
    {
        return _Myptr();
    }
    int compare(unsigned int _Off, unsigned int _N0, const char* _Ptr, unsigned int _Count) const
    {
        if (_Mysize < _Off)
            _Xran();
        if (_Mysize - _Off < _N0)
            _N0 = _Mysize - _Off;
        unsigned int _Ans = BxStrTraits::compare(_Myptr() + _Off, _Ptr, _N0 < _Count ? _N0 : _Count);
        return _Ans != 0 ? (int)_Ans : _N0 < _Count ? -1 : _N0 == _Count ? 0 : +1;
    }
    int compare(const char* _Ptr) const
    {
        return compare(0, _Mysize, _Ptr, BxStrTraits::length(_Ptr));
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
inline bool operator==(const BxString& _Left, const char* _Right)
{
    return _Left.compare(_Right) == 0;
}
inline bool operator!=(const BxString& _Left, const char* _Right)
{
    return !(_Left == _Right);
}
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

struct GvHeap
{
    void* FUN_00aa3e40(unsigned int _Size);
    void FUN_00aa4060(void* _Ptr);
};
template <class T> inline T* GvHeapAllocate(unsigned int _Count, T*)
{
    if (_Count <= 0)
    {
        _Count = 0;
    }
    else if (((unsigned int)(-1) / _Count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)((GvHeap*)&DAT_011f6238)->FUN_00aa3e40(_Count * sizeof(T));
}
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
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
        return GvHeapAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        ((GvHeap*)&DAT_011f6238)->FUN_00aa4060(_Ptr);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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
            do
            {
            } while (0);
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

// @fnv 0x00ad42e0
plus2ad4::BxString FUN_00ad42e0(const plus2ad4::BxString& _Left, const plus2ad4::BxString& _Right)
{
    return plus2ad4::BxString(_Left) += _Right;
}

namespace input_ctor {
struct DefaultLocale : localeDEB0
{
    DefaultLocale();
};
template <class C> struct InputStreambuf;
struct InputMutex : _MutexDEB0
{
    InputMutex();
};
struct Failure : BxLogicError
{
    explicit Failure(const BxString& message) : BxLogicError(message)
    {}
    virtual ~Failure()
    {}
};
struct StateOperations
{
    virtual ~StateOperations()
    {}
    unsigned int standardStream;
    int state, exceptions, format, precision, width;
    void* array;
    void* callbacks;
    localeDEB0* locale;
    StateOperations()
    {}
    int rdstate() const
    {
        return state;
    }
    void initializeBase()
    {
        locale = 0;
        standardStream = 0;
        exceptions = 0;
        format = 0x201;
        precision = 6;
        width = 0;
        array = 0;
        callbacks = 0;
        FUN_00ac9ff0(0, false);
        locale = new localeDEB0;
    }
    static void addStandard(StateOperations*);
    void FUN_00ac9ff0(int value, bool reraise)
    {
        state = value & 0x17;
        if ((state & exceptions) == 0)
        {
        }
        else if (reraise)
            throw;
        else if (state & exceptions & 4)
            throw Failure("ios_base::badbit set");
        else if (state & exceptions & 2)
            throw Failure("ios_base::failbit set");
        else
            throw Failure("ios_base::eofbit set");
    }
};
struct InputIos : StateOperations
{
    virtual ~InputIos()
    {}
    InputStreambuf<char>* streambuf;
    void* tied;
    char fill;
    InputIos()
    {}
    localeDEB0 getloc() const
    {
        return *locale;
    }
    char widen(char value) const
    {
        return ParserUseFacet(getloc()).widen(value);
    }
    void FUN_00ad0470(InputStreambuf<char>* buffer, bool standard)
    {
        initializeBase();
        streambuf = buffer;
        tied = 0;
        fill = widen(' ');
        if (streambuf == 0)
            setstate(4);
        if (standard)
            addStandard(this);
        else
            standardStream = 0;
    }
    void clear(int value = 0, bool reraise = false)
    {
        StateOperations::FUN_00ac9ff0(streambuf == 0 ? value | 4 : value, reraise);
    }
    void setstate(int value, bool reraise = false)
    {
        if (value != 0)
            clear(rdstate() | value, reraise);
    }
};
struct VersionedDataBlock : virtual InputIos
{
    VersionedDataBlock(InputStreambuf<char>* buffer, bool standard = false) : count(0)
    {
        FUN_00ad0470(buffer, standard);
    }
    virtual ~VersionedDataBlock()
    {}
    int count;
};
struct Codec : facetDEB0
{
    virtual bool do_always_noconv() const;
    bool always_noconv() const
    {
        return do_always_noconv();
    }
};
const Codec& UseCodec(const localeDEB0&);
_iobuf* OpenStream(const char*, int, int);
template <class C> struct InputStreambuf
{
    virtual ~InputStreambuf()
    {
        delete _Plocale;
    }
    InputStreambuf() : _Plocale(new localeDEB0)
    {
        _InitSB();
    }
    InputMutex lock;
    C *_Gfirst, *_Pfirst;
    C **_IGfirst, **_IPfirst;
    C *_Gnext, *_Pnext;
    C **_IGnext, **_IPnext;
    int _Gcount, _Pcount;
    int *_IGcount, *_IPcount;
    localeDEB0* _Plocale;
    localeDEB0 getloc() const
    {
        return *_Plocale;
    }
    void setp(C* first, C* last)
    {
        *_IPfirst = first;
        *_IPnext = first;
        *_IPcount = (int)(last - first);
    }
    void setg(C* first, C* next, C* last)
    {
        *_IGfirst = first;
        *_IGnext = next;
        *_IGcount = (int)(last - next);
    }
    void _InitSB()
    {
        _IGfirst = &_Gfirst;
        _IPfirst = &_Pfirst;
        _IGnext = &_Gnext;
        _IPnext = &_Pnext;
        _IGcount = &_Gcount;
        _IPcount = &_Pcount;
        setp(0, 0);
        setg(0, 0, 0);
    }
    void _InitSB(C** gf, C** gn, int* gc, C** pf, C** pn, int* pc)
    {
        _IGfirst = gf;
        _IPfirst = pf;
        _IGnext = gn;
        _IPnext = pn;
        _IGcount = gc;
        _IPcount = pc;
    }
};
template <class C> struct InputFilebuf : InputStreambuf<C>
{
    InputFilebuf(_iobuf* _File = 0) : InputStreambuf<C>()
    {
        FUN_00acfc10(_File, NewFile);
    }
    virtual ~InputFilebuf();
    void* codec;
    char putback;
    bool wrote;
    int conversionState;
    bool ownsFile;
    _iobuf* file;
    enum InitKind
    {
        NewFile,
        OpenFile,
        ClosedFile
    };
    void FUN_00acfc10(_iobuf* _File, InitKind _Which)
    {
        static int _Stinit;
        ownsFile = _Which == OpenFile;
        wrote = false;
        _InitSB();
        if (_File != 0 && sizeof(char) == 1)
        {
            char** begin = &_File->_base;
            char** next = &_File->_ptr;
            int* readCount = &_File->_cnt;
            int* writeCount = &_File->_cnt;
            _InitSB(begin, next, readCount, begin, next, writeCount);
        }
        file = _File;
        conversionState = _Stinit;
        codec = 0;
    }
    void initializeCodec(Codec* value)
    {
        if (value->always_noconv())
            codec = 0;
        else
        {
            codec = (void*)value;
            _InitSB();
        }
    }
    InputFilebuf* FUN_00acfab0(const char* name, int mode, int prot)
    {
        _iobuf* opened;
        if (file != 0 || (opened = OpenStream(name, mode, prot)) == 0)
            return 0;
        FUN_00acfc10(opened, OpenFile);
        initializeCodec((Codec*)&UseCodec(getloc()));
        return this;
    }
};
}
class FUN_00acc6c0 : public input_ctor::VersionedDataBlock
{
  public:
    FUN_00acc6c0(const char* filename, int mode, int protection);
    virtual ~FUN_00acc6c0();
    input_ctor::InputFilebuf<char> filebuf;
};
// @fnv 0x00acc6c0
FUN_00acc6c0::FUN_00acc6c0(const char* filename, int mode, int protection) : input_ctor::VersionedDataBlock(&filebuf)
{
    if (filebuf.FUN_00acfab0(filename, mode | 1, protection) == 0)
        setstate(2);
}
