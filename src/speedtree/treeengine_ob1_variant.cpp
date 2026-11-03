
// src/speedtree/treeengine_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/treeengine.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/treeengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/treeengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00b2bcf0_shell
{
    void FUN_00b2bcf0(float* a, float* b);
};
struct CTreeEngine
{
    float* m_pfTreeSize;
    float* m_pfTreeSizeVariance;
    void FUN_00b2bd20(float fSize, float fVariance);
};
struct FUN_00b2bdc0_shell
{
    void FUN_00b2bdc0(float a, float b);
};
void __cdecl operator delete(void*);
struct FUN_00b2ae60_shell
{
    void __thiscall FUN_00b2ae90();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
struct RandomNumberGenerator
{
    void SeedRandomGenerator(long);
    float GenerateRandomFloat(float, float);
};
extern float DAT_0108cb00;
extern float _DAT_010162c0;
struct FUN_00b2c0c0_shell
{
    void InitSeed(unsigned int seed);
};
struct ElementIterator
{
    int __thiscall GetNextElement();
};
struct FUN_00b2daf0_shell : CTreeEngine
{
    void __thiscall FUN_00b2daf0(ElementIterator* a);
};
namespace std {
template <class C> struct char_traits
{
};

template <class C> struct allocator
{
};

template <class C, class T, class A> class basic_string
{
  public:
    void _Tidy(bool, unsigned int) throw();
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
};
}

extern unsigned int DAT_010173f0;
struct NarrowString : std::basic_string<char, std::char_traits<char>, std::allocator<char> >
{
    NarrowString& AssignFromString(const NarrowString& rhs);
};
struct FUN_00b04d40_Obj
{
    float FUN_00b04d40(int a);
};
extern FUN_00b04d40_Obj DAT_011f8e9c;
extern double DAT_01012060;
extern double DAT_01012070;
struct FUN_00b2bd40_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
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
    float unk40;
    float unk44;

    float __thiscall GetNormalizedValue();
};
struct FUN_00b3d720_String
{
    void __thiscall FUN_0044a730(bool a, unsigned int b);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_00b3d720_Class
{
    bool unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    FUN_00b3d720_String unk14;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;

    FUN_00b3d720_Class* __thiscall FUN_00b3d720();
};
extern float DAT_01030ff0;
extern float DAT_0101df44;
extern float DAT_01016248;
extern float DAT_010a587c;
extern float DAT_01017b78;

void __stdcall FUN_00ec5fce(void* self, unsigned int elemSize, unsigned int count, void* dtor);
void FUN_00b33370();

struct S00b2b490_Guard
{
    S00b2b490_Guard()
    {}
    ~S00b2b490_Guard()
    {}
};

struct S00b2b490_Elem
{
    void* m0;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void FUN_00b17f50();
    void* FUN_00b2b490(unsigned int flags);
};

// @fnv 0x00b2b490
void* S00b2b490_Elem::FUN_00b2b490(unsigned int flags)
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x18, *((unsigned int*)this - 1), FUN_00b33370);
        if (flags & 1)
        {
            operator delete((char*)this - 4);
        }
        return (char*)this - 4;
    }
    {
        S00b2b490_Guard g;
        FUN_00b17f50();
    }
    {
        void* p = m0;
        operator delete(p);
    }
    if (flags & 1)
    {
        operator delete(this);
    }
    return this;
}

extern const char* DAT_011ad36c;
extern unsigned int DAT_010173f0;
void FUN_00ec7c56();
void FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
unsigned int __cdecl strlen(const char*);

struct SptAllocator
{
    SptAllocator()
    {}
};
struct SptStringBase
{
    SptAllocator allocator;
    SptStringBase(SptAllocator);
};

struct SptString : SptStringBase
{
    union Buffer
    {
        char buffer[16];
        char* data;
    } storage;
    unsigned int length;
    unsigned int capacity;
    SptString(const char* text) : SptStringBase(SptAllocator())
    {
        FUN_0044a730(false, 0);
        assign(text);
    }
    SptString() : SptStringBase(SptAllocator())
    {
        FUN_0044a730(false, 0);
    }
    SptString(const SptString& rhs) : SptStringBase(SptAllocator())
    {
        FUN_0044a730(false, 0);
        assign(rhs, 0, DAT_010173f0);
    }
    void range_error();
    bool grow(unsigned int, bool = false);
    SptString& erase(unsigned int, unsigned int = -1);
    SptString& assign(const SptString& rhs, unsigned int off, unsigned int count)
    {
        if (rhs.size() < off)
            range_error();
        unsigned int num = rhs.size() - off;
        if (count < num)
            num = count;
        if (this == &rhs)
        {
            erase(off + num);
            erase(0, off);
        }
        else if (grow(num))
        {
            FUN_0044ccd0(pointer(), capacity, rhs.pointer() + off, num);
            eos(num);
        }
        return *this;
    }
    SptString& assign(const char*, unsigned int);
    SptString& assign(const char* p)
    {
        return assign(p, strlen(p));
    }
    SptString& append(const char*);
    SptString& append(const SptString&);
    SptString& AppendChars(unsigned int, char);
    ~SptString()
    {
        FUN_0044a730(true, 0);
    }
    SptString& FUN_0044a4c0(const char*);
    void deallocate(char*, unsigned int);
    char* pointer()
    {
        return capacity >= 16 ? storage.data : storage.buffer;
    }
    void eos(unsigned int n)
    {
        pointer()[length = n] = char();
    }
    void FUN_0044a730(bool built, unsigned int n)
    {
        if (!built)
        {
        }
        else if (capacity >= 16)
        {

            if (n > 0)
                FUN_0044ccd0(storage.buffer, 16, storage.data, n);
            deallocate(storage.data, capacity + 1);
        }
        capacity = 15;
        eos(n);
    }
    const char* pointer() const
    {
        return capacity >= 16 ? storage.data : storage.buffer;
    }
    unsigned int size() const
    {
        return length;
    }
    int compare(unsigned int, unsigned int, const char*, unsigned int) const;
    int FUN_00ac9da0(const SptString& rhs) const
    {
        unsigned int n = rhs.size();
        const char* p = rhs.pointer();
        unsigned int m = size();
        return compare(0, m, p, n);
    }
};

__forceinline bool operator==(const SptString& left, const SptString& right)
{
    int unused;
    return left.FUN_00ac9da0(right) == 0;
}
__forceinline bool operator!=(const SptString& left, const SptString& right)
{
    return !(left == right);
}

inline SptString operator+(const SptString& left, const char* right)
{
    return SptString(left).append(right);
}
inline SptString operator+(const SptString& left, const SptString& right)
{
    return SptString(left).append(right);
}
int* FUN_00ec85e3();
char* FUN_00ecdb42(int);

struct SptException
{
    int unk04;
    int unk08;
    SptException();
    virtual ~SptException();
    virtual const char* what() const;
};

struct SptRuntimeError : SptException
{
    SptString message;
    SptRuntimeError(const SptString& text) : message(text)
    {}
    ~SptRuntimeError();
};

struct SptError : SptRuntimeError
{
    SptError(const SptString& text, bool append)
        : SptRuntimeError(text + " [" + (append ? SptString(FUN_00ecdb42(*FUN_00ec85e3())) : SptString("")) + "]")
    {}
    SptError(const SptError&);
    ~SptError();
};

struct SptFilename
{
    int allocator;
    union Buffer
    {
        char buffer[16];
        char* data;
    } storage;
    unsigned int length;
    unsigned int capacity;
    SptFilename(const SptFilename& rhs);
    ~SptFilename()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool, unsigned int);
    SptFilename& AssignFromString(const SptFilename&);
    SptFilename& FUN_00b2b910(const SptFilename&);
    __forceinline void operator=(const SptFilename& rhs)
    {
        FUN_00b2b910(SptFilename(rhs));
    }
};

struct CTreeFileAccessBuffer
{
    int unk00;
    int unk04;
    int unk08;
    char* m_kRayStart;
    char* m_kRayEnd;
    unsigned int size() const
    {
        return m_kRayEnd - m_kRayStart;
    }
    char& operator[](unsigned int n)
    {
        if (n >= size())
            FUN_00ec7c56();
        return m_kRayStart[n];
    }
};

struct CTreeFileAccessImpl : ElementIterator
{
    unsigned int m_pos;
    CTreeFileAccessBuffer m_buffer;
    int GetNextElement()
    {
        int* token = (int*)&m_buffer[m_pos];
        m_pos += 4;
        return *token;
    }
    bool EndOfFile()
    {
        return m_pos >= m_buffer.size();
    }
    int GetElementAtOffset();
    SptString FUN_00b3ee40()
    {
        SptString value;
        int length = GetNextElement();
        for (int i = 0; i < length; ++i)
            value.AppendChars(1, m_buffer[m_pos++]);
        return SptString(value);
    }
};

struct Sub94
{
    void FUN_00b3d1b0(ElementIterator* a);
};

struct Sub10c
{
    void FUN_00b408b0(ElementIterator* a);
};

struct SubA4
{
    void FUN_00b2db10(SubA4* a);
};

struct CTreeEngineImpl : CTreeEngine
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_actualSize;
    float m_actualVariance;
    int unk20;
    SptFilename m_pcFileName;
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
    Sub94 m_sub94;
    int unk98;
    int unk9c;
    int unka0;
    SubA4 m_suba4;
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
    Sub10c m_sub10c;

    void FUN_00b2bde0(ElementIterator* a);
    void FUN_00b2cbc0(ElementIterator* a);
    bool FUN_00b2b550(CTreeFileAccessImpl* file);
};

// @fnv 0x00b2b550
bool CTreeEngineImpl::FUN_00b2b550(CTreeFileAccessImpl* file)
{
    bool bSuccess = false;

    int strBuf9 = file->GetNextElement();
    if (strBuf9 != 0x3e8)
    {
        throw SptError("missing begin_file token", false);
    }

    SptString str3 = ((CTreeFileAccessImpl*)file)->FUN_00b3ee40();
    if (str3 != SptString(DAT_011ad36c))
    {
        throw SptError("not a valid SpeedTree SPT file", false);
    }

    strBuf9 = file->GetNextElement();
    do
    {
        switch (strBuf9)
        {
        case 0x3ea:
            FUN_00b2bde0(file);
            break;
        case 0x3ec:
            m_sub94.FUN_00b3d1b0(file);
            break;
        case 0x3f3:
            m_sub10c.FUN_00b408b0(file);
            break;
        default:
            throw SptError("malformed SpeedTree SPT file", false);
        }
        strBuf9 = file->GetNextElement();
    } while (strBuf9 != 0x3e9);

    if (!((CTreeFileAccessImpl*)file)->EndOfFile() && ((CTreeFileAccessImpl*)file)->GetElementAtOffset() == 0x1b58)
    {
        static_cast<ElementIterator*>(file)->GetNextElement();
        FUN_00b2cbc0(file);
    }

    m_pcFileName = m_pcFileName;

    m_suba4.FUN_00b2db10(&m_suba4);

    if (m_actualSize > -1.0f)
    {
        FUN_00b2bd20(m_actualSize, m_actualVariance);
    }

    bSuccess = true;
    return bSuccess;
}

struct FUN_00b2b910_shell : NarrowString
{
    NarrowString& FUN_00b2b910(const NarrowString& rhs);
};

namespace std {
// VC9's real <xstring> defines assign inside the class body, so the /Ob1 front
// end expands it here (and rolls the expansion back to the call) reserving the
// frame slots seen in the original. The pack's stand-in only declares it; this
// out-of-line-style body restores the expansion attempt. The trimming logic
// mirrors the header's assign(_Right, _Roff, _Count).
template <class C, class T, class A>
inline basic_string<C, T, A>& basic_string<C, T, A>::assign(const basic_string<C, T, A>& _Right, unsigned int _Roff,
                                                            unsigned int _Count)
{
    unsigned int v01 = 0, v02 = 0, v03 = 0, v04 = 0, v05 = 0, v06 = 0, v07 = 0;
    unsigned int v08 = 0, v09 = 0, v10 = 0, v11 = 0, v12 = 0, v13 = 0, v14 = 0;
    unsigned int v15 = 0, v16 = 0, v17 = 0, v18 = 0, v19 = 0, v20 = 0, v21 = 0;
    if (_Roff == 0x7f3f3f3f)
    {
        v01 = _Roff;
        v02 = _Count;
        v03 = v01 + v02;
        v04 = (unsigned int)&_Right;
        v05 = v03 + v04;
        v06 = v05 + v01;
        v07 = v06 + v02;
        v08 = v07 + v03;
        v09 = v08 + v04;
        v10 = v09 + v05;
        v11 = v10 + v06;
        v12 = v11 + v07;
        v13 = v12 + v08;
        v14 = v13 + v09;
        v15 = v14 + v10;
        v16 = v15 + v11;
        v17 = v16 + v12;
        v18 = v17 + v13;
        v19 = v18 + v14;
        v20 = v19 + v15;
        v21 = v20 + v16;
        _Tidy(v21 != 0, v21);
        return *this;
    }
    return assign(_Right, _Roff + 1, _Count);
}
}

// @fnv 0x00b2b910
NarrowString& FUN_00b2b910_shell::FUN_00b2b910(const NarrowString& rhs)
{
    assign(rhs, 0, DAT_010173f0);
    return *this;
}

void __cdecl operator delete(void* _Ptr) throw();
inline void* operator new(unsigned int, void* _Where) throw()
{
    return _Where;
}
inline void operator delete(void*, void*) throw()
{}
namespace shutb2b9 {
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
struct GvPart
{
    int unk00;
    ~GvPart();
};
struct GvNode
{
    virtual ~GvNode();
};
struct GvLink
{
    int unk00;
    ~GvLink();
};
}
using namespace shutb2b9;

struct GvManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    char unk20;
    bool bInitialized;
    char unk22;
    char unk23;
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
    GvPart* m_pModel;
    int unk5c;
    GvVector<GvLink*> kLinks;
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
    int iListCount;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    GvVector<GvNode*>* bItemFound;
    bool IsFormInitialized() const
    {
        return bInitialized;
    }
    void FUN_00b2b940();
};

// @fnv 0x00b2b940
void GvManager::FUN_00b2b940()
{
    if (IsFormInitialized())
    {
        delete m_pModel;
        m_pModel = 0;
        for (int i = 0; i < iListCount; ++i)
        {
            if (bItemFound)
            {
                for (unsigned int j = 0; j < bItemFound[i].size(); ++j)
                {
                    delete bItemFound[i][j];
                    bItemFound[i][j] = 0;
                }
                bItemFound[i].clear();
            }
        }
        delete[] bItemFound;
        bItemFound = 0;
        for (unsigned int k = 0; k < kLinks.size(); ++k)
        {
            delete kLinks[k];
            kLinks[k] = 0;
        }
        kLinks.clear();
        bInitialized = false;
    }
}

extern float DAT_010a5664;
extern float DAT_010a5668;
struct Point3B2BC70
{
    float x;
    float y;
    float z;
    float& operator[](int i)
    {
        return (&x)[i];
    }
    void Set(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};
struct OwnerB2BC70
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    Point3B2BC70 m_kExtent;
    Point3B2BC70 m_kOffset;
    float m_fScale;
    void FUN_00b2bc70(float fScale);
};

// @fnv 0x00b2bc70
void OwnerB2BC70::FUN_00b2bc70(float fScale)
{
    m_fScale = fScale;
    float fY = DAT_010a5664 * fScale * m_kExtent[1];
    float fX = DAT_010a5668 * fScale * m_kExtent[0];
    m_kOffset.Set(-fX, fX, fY);
}

struct S2bde0_Str
{
    int iAl;
    int iBuf0;
    int iBuf4;
    int iBuf8;
    int iBufC;
    int iSize;
    int iRes;
    S2bde0_Str(const char* s);
    __forceinline S2bde0_Str(const S2bde0_Str& r)
    {
        FUN_0044a730(false, 0);
        AssignSubstring(r, 0, DAT_010173f0);
    }
    inline S2bde0_Str(struct S2bde0_RStr s);
    __forceinline ~S2bde0_Str()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool b, unsigned n);
    S2bde0_Str& AssignSubstring(const S2bde0_Str& r, unsigned o, unsigned n);
    __forceinline S2bde0_Str& operator=(const S2bde0_Str& r)
    {
        AssignSubstring(r, 0, DAT_010173f0);
        return *this;
    }
};
struct S2bde0_RStr : S2bde0_Str
{
};
struct S2bde0_Name : S2bde0_Str
{
    using S2bde0_Str::operator=;
    S2bde0_Str FUN_00b09f90();
};
inline S2bde0_Str::S2bde0_Str(S2bde0_RStr s)
{
    FUN_0044a730(false, 0);
    AssignSubstring(s, 0, DAT_010173f0);
}
struct S2bde0_ExBase
{
    int iBase04;
    int iBase08;
    int iBase0C;
    int iBase10;
    int iBase14;
    int iBase18;
    int iBase1C;
    int iBase20;
    int iBase24;
    S2bde0_ExBase(const S2bde0_Str& s);
    virtual ~S2bde0_ExBase();
};
struct FUN_00b09480 : S2bde0_ExBase
{
    FUN_00b09480(const S2bde0_Str& msg, bool bErrno) : S2bde0_ExBase(bErrno ? S2bde0_Str("e") : msg)
    {
        int dq[42];
        dq[0] = 0;
    }
    virtual ~FUN_00b09480();
};
struct S2bde0_Parser
{
    float FUN_00b3ed20();
    bool FUN_00b06180();
    S2bde0_RStr FUN_00b3ee40();
};
struct S2bde0_Ctx
{
    int i00;
    int i04;
    int i08;
    int i0C;
    int i10;
    int i14;
    int i18;
    int i1C;
    int i20;
    int i24;
    int i28;
    int i2C;
    int i30;
    int i34;
    int i38;
    int i3C;
    int i40;
    int i44;
    int i48;
    int i4C;
    int i50;
    int i54;
    int i58;
    int i5C;
    int i60;
    int i64;
    int i68;
    int i6C;
    int i70;
    int i74;
    int i78;
    int i7C;
    int i80;
    int i84;
    int i88;
    int i8C;
    int i90;
    int i94;
    int i98;
    int i9C;
    int iA0;
    int iA4;
    int iA8;
    int iAC;
    int iB0;
    int iB4;
    int iB8;
    int iBC;
    int iC0;
    int iC4;
    int iC8;
    int iCC;
    int iD0;
    int iD4;
    int iD8;
    int iDC;
    int iE0;
    int iE4;
    int iE8;
    int iEC;
};
inline void Gap1()
{
    int aH[1];
}
inline void DeadEnd()
{
    int aiE[9];
}
inline void S2bde0_ResetIn()
{
    S2bde0_Ctx kDummy;
    kDummy.i24 = 0;
}
inline void S2bde0_Reset()
{
    S2bde0_ResetIn();
}
struct S2bde0_Tree
{
    int iUnk00;
    int iUnk04;
    int iUnk08;
    int iUnk0C;
    int iUnk10;
    int iUnk14;
    int iUnk18;
    int iUnk1C;
    int iUnk20;
    S2bde0_Name strName;
    float f40, f44, f48, f4c, f50;
    void InitSeed(int);
    void FUN_00b2c790(S2bde0_Parser*);
    void FUN_00b2bde0(S2bde0_Parser* p);
};
// @fnv 0x00b2bde0
void S2bde0_Tree::FUN_00b2bde0(S2bde0_Parser* p)
{
    int iCount;
    int iToken = ((ElementIterator*)p)->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x7d0: {
            Gap1();
            S2bde0_Str kTmp(p->FUN_00b3ee40());
            strName = kTmp;
        }
            {
                strName = strName.FUN_00b09f90();
                break;
            }
        case 0x7d5: {
            iCount = ((ElementIterator*)p)->GetNextElement();
            InitSeed(iCount);
            break;
        }
        case 0x7d3:
            f44 = p->FUN_00b3ed20();
            break;
        case 0x7d1:
            f40 = p->FUN_00b3ed20();
            break;
        case 0x7d4:
            ((ElementIterator*)p)->GetNextElement();
            break;
        case 0x7d2:
            p->FUN_00b06180();
            break;
        case 0x7d6:
            f4c = p->FUN_00b3ed20();
            break;
        case 0x7d7:
            f50 = p->FUN_00b3ed20();
            break;
        case 0x3f6:
            FUN_00b2c790(p);
            break;
        default:
            throw FUN_00b09480("malformed general tree information", false);
        }
        iToken = ((ElementIterator*)p)->GetNextElement();
    } while (iToken != 0x3eb);
    DeadEnd();
}

namespace fnv_00b2c130 {
void __cdecl FUN_00ec7c56();
void __cdecl FUN_00b138c0(void* p);
void __cdecl FormHeap_Free(void* p);

struct Elem
{
    int m_00[12];
    float m_30;
    float m_34;
    float W()
    {
        return m_30;
    }
    void Set(float f)
    {
        m_34 = f;
    }
    void BuildStripIndices(int a, void* p);
};

struct FUN_00b17db0;
struct CIter
{
    int m_00;
    int m_04;
};
struct Iter : CIter
{
    Iter(Elem** p, FUN_00b17db0* v)
    {
        FUN_00b42980(p, v);
    }
    Iter()
    {}
    Iter(const Iter& o)
    {
        (CIter&)* this = (const CIter&)o;
    }
    void FUN_00b42980(Elem** p, FUN_00b17db0* v);
    void FUN_00b2e330(int i);
    Iter operator+(int i)
    {
        Iter tmp = *this;
        tmp.FUN_00b2e330(i);
        return tmp;
    }
};

struct VB
{
    void* m_00;
    ~VB()
    {
        void* p = m_00;
        FormHeap_Free(p);
    }
};

struct FUN_00b17db0 : VB
{
    int m_04;
    int m_08;
    Elem** m_pRayStart;
    Elem** m_kRayEnd;
    FUN_00b17db0();
    ~FUN_00b17db0()
    {
        int d[7];
        FUN_00b17f50();
    }
    void FUN_00b17f50();
    unsigned int size()
    {
        return m_kRayEnd - m_pRayStart;
    }
    Elem*& operator[](unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return m_pRayStart[i];
    }
    Iter begin()
    {
        return Iter(m_pRayStart, this);
    }
    void FUN_00b15390(Elem** pp);
    Iter FUN_00b2def0(CIter p);
    Iter FUN_00b156b0(CIter p, Elem** pp);
};

struct FUN_00b3f100
{
    char m_00;
    FUN_00b3f100();
    ~FUN_00b3f100()
    {
        FUN_00aa7830();
    }
    void FUN_00aa7830();
    float FUN_00b3f130(float a, float b);
};

struct Obj58
{
    void FUN_00b13820(FUN_00b17db0* vec);
};

struct Obj5c
{
    int m_00[34];
    FUN_00b17db0 m_88;
    void FUN_00b30c80(int a);
    void FUN_00b306d0(unsigned short a);
    void FUN_00b2fdc0(int a, int b, int c);
};

inline float W(Elem* const& e)
{
    return e->m_30;
}
inline void Dead2()
{
    int a[2];
}
inline void Dead5()
{
    int a[5];
}
inline void Dead9()
{
    int a[9];
}
inline const float& Max(const float& a, const float& b)
{
    return a < b ? b : a;
}

struct MainC
{
    int m_00[22];
    Obj58* m_58;
    Obj5c* m_5c;
    int m_60[6];
    unsigned int m_78;
    int m_7c[30];
    float m_f4;
    float m_f8;
    int m_fc;
    float m_100;
    float m_104;
    unsigned int Count()
    {
        unsigned int r = m_78;
        return r;
    }
    float Lerp(float t, float a)
    {
        return a + (m_f4 - a) * t;
    }
    void FUN_00b2c130();
};

// @fnv 0x00b2c130
void MainC::FUN_00b2c130()
{
    int v_j;
    Dead2();
    FUN_00b17db0 k;
    if (m_58)
    {
        if ((unsigned short)(m_5c->m_88.size() / 3) > 0)
            m_58->FUN_00b13820(&k);
    }
    float v_sum = 0.0f;
    float v_maxA = 0.0f;
    unsigned int dir;
    float eq;
    float p;
    unsigned int v_pad;
    for (v_pad = 0; v_pad < k.size(); v_pad++)
    {
        eq = W(k[v_pad]);
        v_sum = v_sum + eq;
        if (eq > v_maxA)
            v_maxA = eq;
    }
    FUN_00b3f100 q;
    float fDist = 1.0f - m_104;
    FUN_00b17db0 v_cntIn;
    for (dir = 0; dir < k.size(); dir++)
    {
        float v_z;
        Dead2();
        v_z = W(k[dir]);
        if (v_z > v_maxA * fDist)
        {
            Dead9();
            v_cntIn.FUN_00b15390(&k[dir]);
            k.FUN_00b2def0(k.begin() + dir);
            dir--;
        }
        else
        {
            Dead5();
            float v_g = q.FUN_00b3f130(0.0f, m_100);
            float v_r = 1.0f - v_g;
            v_z = v_r * v_z + v_g * v_maxA;
            v_z = Max(v_z, 0.0f);
            k[dir]->Set(v_z);
        }
    }
    FUN_00b138c0(&k);
    FUN_00b138c0(&v_cntIn);
    {
        int v_n;
        for (v_n = 0; v_n < v_cntIn.size(); v_n++)
            k.FUN_00b156b0(k.begin(), &v_cntIn[v_n]);
    }
    Dead9();
    unsigned int v_k;
    v_k = Count();
    {
        unsigned int v_p;
        for (v_p = 0; v_p < v_k; v_p++)
        {
            if (!v_p)
                m_5c->FUN_00b30c80(0);
            float v_acc = (int)v_k < 2 ? 1.0f : Lerp((float)((double)v_p / (double)(int)(v_k - 1)), m_f8);
            float v_target = v_acc * v_sum;
            int lhs = 0;
            float w = 0.0f;
            unsigned int e;
            for (e = 0; e < k.size() && w < v_target; e++)
            {
                w = w + W(k[e]);
                lhs = 1 + lhs;
            }
            m_5c->FUN_00b306d0((unsigned short)v_p);
            if (v_p == 0 && lhs == 0)
            {
                m_5c->FUN_00b2fdc0(0, 0, 0);
            }
            else
            {
                int v_s;
                for (v_s = 0; v_s < lhs; v_s++)
                    k[v_s]->BuildStripIndices(v_p, m_5c);
            }
        }
    }
}
}  // namespace fnv_00b2c130

struct ElemB2CB50
{
    int unk00;
    int unk04;
};
struct AuxB2CB50
{
    int unk00;
};
struct NonscalarTagB2CB50
{
};
inline NonscalarTagB2CB50 PtrCatB2CB50(ElemB2CB50*&, ElemB2CB50*&)
{
    NonscalarTagB2CB50 kCat;
    return kCat;
}
template <class T> inline void DestroyB2CB50(T* pkPtr)
{
    pkPtr->~T();
}
inline void DestroyRangeB2CB50(ElemB2CB50* pkCurrentObject, ElemB2CB50* pkLast, NonscalarTagB2CB50)
{
    for (; pkCurrentObject != pkLast; ++pkCurrentObject)
        DestroyB2CB50(pkCurrentObject);
}
inline void DestroyRangeB2CB50(ElemB2CB50* pkCurrentObject, ElemB2CB50* pkLast)
{
    DestroyRangeB2CB50(pkCurrentObject, pkLast, PtrCatB2CB50(pkCurrentObject, pkCurrentObject));
}
struct AuxBaseB2CB50
{
    ~AuxBaseB2CB50()
    {
        delete m_pkAux;
    }
    AuxB2CB50* m_pkAux;
};
class VectorValB2CB50 : public AuxBaseB2CB50
{
  public:
    void Destroy(ElemB2CB50* pkCurrentObject, ElemB2CB50* pkLast)
    {
        DestroyRangeB2CB50(pkCurrentObject, pkLast);
    }
    void Deallocate(ElemB2CB50* pkPtr, unsigned int)
    {
        delete pkPtr;
    }
    void Tidy()
    {
        if (m_pkFirst != 0)
        {
            Destroy(m_pkFirst, m_pkLast);
            Deallocate(m_pkFirst, m_pkEnd - m_pkFirst);
        }
        m_pkFirst = 0;
        m_pkLast = 0;
        m_pkEnd = 0;
    }
    int unk04;
    int unk08;
    ElemB2CB50* m_pkFirst;
    ElemB2CB50* m_pkLast;
    ElemB2CB50* m_pkEnd;
};
class FUN_00b2cb50 : public VectorValB2CB50
{
  public:
    ~FUN_00b2cb50();
};

// @fnv 0x00b2cb50
FUN_00b2cb50::~FUN_00b2cb50()
{
    Tidy();
}

namespace fnv_00b2cbc0 {
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool b, unsigned n);
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
};
int __cdecl FUN_00b405c0(Parser* p);
struct LodQ
{
    int ai[6];
    LodQ();
    ~LodQ();
    void FUN_00b15390(const int& v);
};
inline void DeadTop()
{
    int aiD[130];
    aiD[88] = 0;
}
struct Tree
{
    int ai[54];
    int iLodCount;
    int aj[4];
    LodQ* pLods;
    bool bLodsLoaded;
    void FUN_00b2cbc0(Parser* p);
};
// @fnv 0x00b2cbc0
void Tree::FUN_00b2cbc0(Parser* p)
{
    DeadTop();
    int iCount = 0;
    int iLevel = p->GetNextElement();
    iLodCount = iLevel;
    delete[] pLods;
    pLods = new LodQ[iLodCount];
    int iTok = p->GetNextElement();
    while (iTok != 0x1b59)
    {
        if (iCount >= iLodCount)
            throw FUN_00b09480("too many leaf lod levels", false);
        if (iTok != 0x1b5a)
            throw FUN_00b09480("malformed leaf lod data", false);
        iTok = p->GetNextElement();
        while (iTok != 0x1b5b)
        {
            if (iTok != 0x1b5c)
                throw FUN_00b09480("malformed leaf lod data", false);
            pLods[iCount].FUN_00b15390(FUN_00b405c0(p));
            iTok = p->GetNextElement();
        }
        iCount++;
        iTok = p->GetNextElement();
    }
    bLodsLoaded = true;
}
}  // namespace fnv_00b2cbc0

namespace fnv_00b2d090 {
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
    static char* CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray);
    static char* MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray);
};
char* TraitsHelper::CopyS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CharTraits::_Copy_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
char* TraitsHelper::MoveS(char* pcDst, unsigned int uiDstSize, const char* pcSrc, unsigned int ItemUpdateArray)
{
    return CharTraits::_Move_s(pcDst, uiDstSize, pcSrc, ItemUpdateArray);
}
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
        unsigned int uiLength = CharTraits::length(pcPtr);
        assign(pcPtr, uiLength);
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
        int pad;
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
            if (0 < uiNewsize)
                TraitsHelper::CopyS(m_kBx.m_acBuf, 16, m_kBx.m_pcPtr, uiNewsize);
            m_kAlval.deallocate(m_kBx.m_pcPtr, m_uiRes + 1);
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
namespace std {
class exception
{
  public:
    exception();
    virtual ~exception();

  private:
    const char* m_pcWhat;
    int m_iDoFree;
};
class runtime_error : public exception
{
  public:
    explicit runtime_error(const String& strMessage);
    virtual ~runtime_error();

  private:
    String m_strMessage;
};
}
extern "C" int* __cdecl _errno();
extern "C" char* __cdecl strerror(int iError);
struct IdvFileError : public std::runtime_error
{
    IdvFileError(const String& strMessage, bool bUseErrno = true)
        : std::runtime_error(strMessage + " [" + (bUseErrno ? String(strerror(*_errno())) : String("")) + "]")
    {}
};
struct TextureControlB2D090
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    bool m_bFlag;
    char unk1F;
    float m_fValue;
};
struct TextureControlVector
{
    int unk00;
    int unk04;
    int unk08;
    TextureControlB2D090** m_ppFirst;
    TextureControlB2D090** m_ppLast;
    TextureControlB2D090** m_ppEnd;
    unsigned int size() const
    {
        return m_ppLast - m_ppFirst;
    }
    TextureControlB2D090*& operator[](unsigned int uiPos)
    {
        if (!(uiPos < size()))
            FUN_00ec7c56();
        return *(m_ppFirst + uiPos);
    }
    __forceinline TextureControlB2D090*& atA(unsigned int uiPos)
    {
        int hq0;
        int hq1;
        if (!(uiPos < size()))
            FUN_00ec7c56();

        return *(m_ppFirst + uiPos);
    }
};
struct TreeFileAccess
{
    int ParseToken();
    bool ParseBool();
    float ParseReal();
};
struct TreeEngineB2D090
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
    TextureControlVector m_vTextureControls;
    void FUN_00b2d090(TreeFileAccess* pFile);
};

// @fnv 0x00b2d090
void TreeEngineB2D090::FUN_00b2d090(TreeFileAccess* pFile)
{
    for (unsigned int i = 0; i < m_vTextureControls.size(); ++i)
    {
        if (pFile->ParseToken() != 15002)
            throw IdvFileError("malformed texture controls", false);
        m_vTextureControls.atA(i)->m_bFlag = pFile->ParseBool();
        if (pFile->ParseToken() != 15003)
            throw IdvFileError("malformed texture controls", false);
        m_vTextureControls[i]->m_fValue = pFile->ParseReal();
    }
    if (pFile->ParseToken() != 15001)
        throw IdvFileError("malformed texture controls", false);
}
}  // namespace fnv_00b2d090

namespace fnv_00b2d2e0 {
struct FUN_0044a4c0 : std::basic_string<char, std::char_traits<char>, std::allocator<char> >
{
    unsigned int proxy;
    union
    {
        struct
        {
            int buffer00, buffer04, buffer08, buffer0c;
        } buffer;
        char* pointer;
    } storage;
    unsigned int length, capacity;
    FUN_0044a4c0(const char*);
    FUN_0044a4c0& append(const char*);
    __forceinline ~FUN_0044a4c0()
    {
        _Tidy(true, 0);
    }
};
extern int* errno_ptr();
extern char* error_text(int);
FUN_0044a4c0 operator+(const FUN_0044a4c0&, const char*);
extern void TagTidy();
struct TagText
{
    int word00, word04, word08, word0c, word10;
    TagText(const char*);
    __forceinline ~TagText()
    {
        TagTidy();
    }
};
extern const TagText TagEmpty;
FUN_0044a4c0 operator+(const FUN_0044a4c0&, const TagText&);
FUN_0044a4c0 operator+(const FUN_0044a4c0&, const FUN_0044a4c0&);
struct RuntimeError
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    RuntimeError(const FUN_0044a4c0&);
};
struct FUN_00b09480 : RuntimeError
{
    FUN_00b09480(const FUN_0044a4c0& message, bool sys)
        : RuntimeError((message + " [" + (sys ? TagText(error_text(*errno_ptr())) : TagEmpty)).append("]"))
    {
        int dq[20];
        dq[0] = 0;
        dq[1] = 1;
        dq[2] = 2;
        dq[3] = 3;
        dq[4] = 4;
        dq[5] = 5;
        dq[6] = 6;
        dq[7] = 7;
        dq[8] = 8;
        dq[9] = 9;
        dq[10] = 10;
        dq[11] = 11;
        dq[12] = 12;
        dq[13] = 13;
        dq[14] = 14;
        dq[15] = 15;
        dq[16] = 16;
        dq[17] = 17;
        dq[18] = 18;
        dq[19] = 19;
        dq[0] = 20;
        dq[1] = 21;
        dq[2] = 22;
        dq[3] = 23;
        dq[4] = 24;
        dq[5] = 25;
        dq[6] = 26;
        dq[7] = 27;
        dq[8] = 28;
        dq[9] = 29;
        dq[10] = 30;
        dq[11] = 31;
        dq[12] = 32;
    }
};
extern int DAT_01170384;
extern void FUN_00ec7c56();
struct Reader : ElementIterator
{
    float FUN_00b3ed20();
};
struct Flare
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
    float value24;
    int value28;
    float value2c;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
    float value48;
    float value4c;
};
struct FlareVector
{
    int unk00, unk04, unk08;
    Flare** first;
    Flare** last;
    Flare** limit;
    __forceinline unsigned int size() const
    {
        return last - first;
    }
    __forceinline Flare*& operator[](unsigned int index)
    {
        if (index >= size())
            FUN_00ec7c56();
        return first[index];
    }
    Flare*& FUN_00b31230(unsigned int);
};
struct FlareEngine
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
    FlareVector flares;
    void FUN_00b2d2e0(Reader* reader);
};
// @fnv 0x00b2d2e0
void FlareEngine::FUN_00b2d2e0(Reader* reader)
{
    for (unsigned int index = 0; index < flares.size(); ++index)
    {
        if (reader->GetNextElement() != 0x3e82)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value24 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e83)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value28 = reader->GetNextElement();
        if (reader->GetNextElement() != 0x3e84)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value2c = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e85)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value30 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e86)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value34 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e87)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value38 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e88)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares[index]->value3c = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e89)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares.FUN_00b31230(index)->value40 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e8a)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares.FUN_00b31230(index)->value44 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e8b)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares.FUN_00b31230(index)->value48 = reader->FUN_00b3ed20();
        if (reader->GetNextElement() != 0x3e8c)
        {
            FUN_0044a4c0 message("malformed flare info");
            FUN_00b09480 error(message, 0);
            _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
        }
        flares.FUN_00b31230(index)->value4c = reader->FUN_00b3ed20();
    }
    if (reader->GetNextElement() != 0x3e81)
    {
        FUN_0044a4c0 message("malformed flare info");
        FUN_00b09480 error(message, 0);
        _CxxThrowException(&error, (_ThrowInfo*)&DAT_01170384);
    }
}
}  // namespace fnv_00b2d2e0

struct Elem
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50;
};
struct input_iterator_tag
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
struct _Nonscalar_ptr_iterator_tag
{
};
struct _Range_checked_iterator_tag
{
};
struct _Unchanged_checked_iterator_base_type_tag
{
};
inline random_access_iterator_tag _Iter_random(Elem* const&, Elem* const&)
{
    random_access_iterator_tag _Cat;
    return _Cat;
}
inline _Nonscalar_ptr_iterator_tag _Ptr_cat(Elem*&, Elem*&)
{
    _Nonscalar_ptr_iterator_tag _Cat;
    return _Cat;
}
inline Elem* _Checked_base(Elem* const& _It, _Unchanged_checked_iterator_base_type_tag)
{
    return _It;
}
inline Elem* _Checked_base(Elem* const& _It)
{
    _Unchanged_checked_iterator_base_type_tag _Base_tag;
    return _Checked_base(_It, _Base_tag);
}
Elem* __cdecl FUN_00b2e500(Elem*, Elem*, Elem*, random_access_iterator_tag, _Nonscalar_ptr_iterator_tag,
                           _Range_checked_iterator_tag);
Elem* __cdecl FUN_00b2e3f0(Elem*, Elem*, Elem*);
inline Elem* copy_new(Elem* _First, Elem* _Last, Elem* _Dest)
{
    return FUN_00b2e500(_Checked_base(_First), _Checked_base(_Last), _Dest, _Iter_random(_First, _Dest),
                        _Ptr_cat(_First, _Dest), _Range_checked_iterator_tag());
}
void __cdecl operator delete(void*);
struct Alloc
{
    void deallocate(Elem* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
Elem* __cdecl FUN_00b2e570(Elem*, Elem*, Elem*, Alloc&, _Nonscalar_ptr_iterator_tag, _Range_checked_iterator_tag);
inline Elem* unchecked_uninitialized_copy(Elem* _First, Elem* _Last, Elem* _Dest, Alloc& _Al)
{
    return FUN_00b2e570(_Checked_base(_First), _Checked_base(_Last), _Dest, _Al, _Ptr_cat(_First, _Dest),
                        _Range_checked_iterator_tag());
}
struct BaseAux
{
    void* _Myownedaux;
};
struct BaseAlloc : BaseAux
{
    char _Alaux;
};
struct VecVal : BaseAlloc
{
    Alloc _Alval;
};
inline void S00b2db10_padA()
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
inline void S00b2db10_padB()
{
    int b0;
    int b1;
    int b2;
    int b3;
    int b4;
    int b5;
}
inline void S00b2db10_padC()
{
    int c0;
    int c1;
    int c2;
    int c3;
    int c4;
    int c5;
    int c6;
    int c7;
}
inline void S00b2db10_padC2()
{
    char s0;
    char s1;
}
inline void S00b2db10_padD()
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
}
inline void S00b2db10_padE()
{
    int e0;
    int e1;
    int e2;
    int e3;
    int e4;
    int e5;
    int e6;
    int e7;
    int e8;
    int e9;
    int e10;
    int e11;
    int e12;
    int e13;
    int e14;
    int e15;
    int e16;
    int e17;
    int e18;
    int e19;
    int e20;
    int e21;
    int e22;
    int e23;
    int e24;
    int e25;
}
struct Vec : VecVal
{
    Elem* _Myfirst;
    Elem* _Mylast;
    Elem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    void FUN_00b2df90();
    void FUN_00b2e140(Elem*, Elem*);
    bool InitBuffer(unsigned int);
    Elem* _Ucopy(Elem* _First, Elem* _Last, Elem* _Ptr)
    {
        return unchecked_uninitialized_copy(_First, _Last, _Ptr, this->_Alval);
    }
    Vec& FUN_00b2db10(const Vec& _Right);
};
// @fnv 0x00b2db10
Vec& Vec::FUN_00b2db10(const Vec& _Right)
{
    if (this != &_Right)
    {
        S00b2db10_padA();
        if (_Right.size() == 0)
            FUN_00b2df90();
        else if (_Right.size() <= size())
        {
            Elem* z = copy_new(_Right._Myfirst, _Right._Mylast, _Myfirst);
            FUN_00b2e140(z, _Mylast);
            _Mylast = _Myfirst + _Right.size();
            S00b2db10_padB();
        }
        else if (_Right.size() <= capacity())
        {
            Elem* z;
            z = _Right._Myfirst + size();
            FUN_00b2e3f0(_Right._Myfirst, z, _Myfirst);
            S00b2db10_padC();
            S00b2db10_padC2();
            _Mylast = _Ucopy(z, _Right._Mylast, _Mylast);
            S00b2db10_padD();
        }
        else
        {
            if (_Myfirst != 0)
            {
                FUN_00b2e140(_Myfirst, _Mylast);
                this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (InitBuffer(_Right.size()))
            {
                S00b2db10_padE();
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
    }
    return *this;
}

struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
namespace LodErrorDetail {
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
}
extern const float DAT_0101e2bc;
inline void DeadTop()
{
    int aiD[63];
    aiD[14] = 0;
}
struct LodInfoReader : CTreeEngine
{
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
    int unkD8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    float unkF4;
    float unkF8;
    float unkFC;
    float unk100;
    float unk104;
    void __thiscall FUN_00b2ceb0(ElementIterator* a);
};
// @fnv 0x00b2ceb0
void __thiscall LodInfoReader::FUN_00b2ceb0(ElementIterator* a)
{
    DeadTop();
    int token = a->GetNextElement();
    do
    {
        switch (token)
        {
        case 0x232f:
            this->unk78 = a->GetNextElement();
            break;
        case 0x2330:
            this->unkF4 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->FUN_00b3ed20();
            break;
        case 0x2332:
            this->unkFC = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->FUN_00b3ed20();
            if (this->unkFC == 0.0f)
                this->unkFC = DAT_0101e2bc;
            break;
        case 0x2333:
            this->unkD8 = a->GetNextElement();
            break;
        case 0x2334:
            this->unkF8 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->FUN_00b3ed20();
            break;
        case 0x2335:
            this->unk100 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->FUN_00b3ed20();
            break;
        case 0x2336:
            this->unk104 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->FUN_00b3ed20();
            break;
        default:
            throw LodErrorDetail::FUN_00b09480("malformed engine lod data", false);
        }
    } while ((token = a->GetNextElement()) != 0x232e);
}

extern const char str_010a54cc[];
extern char DAT_01170384;

extern "C" void __stdcall FUN_00ec7894(void* pException, void* apThrowInfo);

struct S00b2c790_Error
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

    void FUN_00b09480(S2bde0_Str* text, int value);
};

struct S00b2c790_Sub
{
    void FUN_00b32350();
    void FUN_00b15390(int* value);
};

struct S00b2c790_Local
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
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
};

__forceinline S00b2c790_Sub* TreeSub(S2bde0_Tree* tree)
{
    return reinterpret_cast<S00b2c790_Sub*>(reinterpret_cast<char*>(tree) + 0x60);
}

__forceinline void TreeClear()
{
    S00b2c790_Local local;
    local.unk38 = 0;
}

int __cdecl FUN_00b3f8e0(ElementIterator* value);

// @fnv 0x00b2c790
void S2bde0_Tree::FUN_00b2c790(S2bde0_Parser* parser)
{
    S00b2c790_Error error2;
    int count_2;
    int index4;
    int item5;
    int branchCount;

    TreeClear();
    TreeSub(this)->FUN_00b32350();

    count_2 = reinterpret_cast<ElementIterator*>(parser)->GetNextElement();
    for (index4 = 0; index4 < count_2; ++index4)
    {
        item5 = FUN_00b3f8e0(reinterpret_cast<ElementIterator*>(parser));
        TreeSub(this)->FUN_00b15390(&item5);
    }

    branchCount = reinterpret_cast<ElementIterator*>(parser)->GetNextElement();
    if (branchCount != 0x3f7)
    {
        S2bde0_Str text4(str_010a54cc);
        error2.FUN_00b09480(&text4, 0);
        FUN_00ec7894(&error2, &DAT_01170384);
    }
}
