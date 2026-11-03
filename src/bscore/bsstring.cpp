// bscore/bsstring.cpp: free functions (15 functions)

#include "layout_support.h"
#include "original_string.h"
#include <limits.h>
#include <string.h>

// Reusable definitions from the original bscore/bsstring.h. The char
// instantiation selects the PC string bodies used by the opening scenario.
namespace {
enum
{
    kMaximumStoredStringLength = USHRT_MAX
};
}

// Copies text into the string buffer, resizing it to at least minimumCapacity when needed, and returns whether the result is non-empty.
// @fnv 0x004037f0
template <class T> bool BSStringT<T>::Set(const T* text, unsigned int minimumCapacity)
{
    unsigned int length = text ? BSStringLength(text) : 0;
    unsigned int capacity = BSStringCapacityMaximum(length, minimumCapacity);
    if (capacity <= MaxLength())
    {
        if (capacity)
        {
            if (text)
                memcpy(pString, text, (length + 1) * sizeof(T));
            else
                pString[0] = 0;
        }
        else
        {
            if (pString)
                delete[] pString;
            pString = 0;
            capacity = 0;
            SetMaxLength(capacity);
        }
    }
    else
    {
        T* previous = pString;
        pString = new T[capacity + 1];
        if (text)
            memcpy(pString, text, (length + 1) * sizeof(T));
        else
            pString[0] = 0;
        if (previous)
            delete[] previous;
        SetMaxLength(capacity);
    }
    SetLength(length);
    return length != 0;
}

// @fnv 0x004037b0
template <class T> BSStringT<T>::BSStringT()
{
    Init();
}

// @fnv 0x004037d0
template <class T> BSStringT<T>::~BSStringT()
{
    Set(0, 0);
}

// Resets the string by nulling pString and setting length and max length to zero.
// @fnv 0x00403970
template <class T> void BSStringT<T>::Init()
{
    pString = 0;
    SetLength(0);
    SetMaxLength(0);
}

// @fnv 0x004039a0
template <class T> unsigned int BSStringT<T>::MaxLength()
{
    return sMaxLen;
}

// @fnv 0x004039c0
template <class T> void BSStringT<T>::SetLength(unsigned int length)
{
    sLen = length <= kMaximumStoredStringLength ? static_cast<unsigned short>(length) : kMaximumStoredStringLength;
}

// @fnv 0x00403a00
template <class T> void BSStringT<T>::SetMaxLength(unsigned int length)
{
    sMaxLen = length <= kMaximumStoredStringLength ? static_cast<unsigned short>(length) : kMaximumStoredStringLength;
}

// @fnv 0x00438390
template <class T> BSStringT<T>& BSStringT<T>::operator=(const T* text)
{
    Set(text, 0);
    return *this;
}

template BSStringT<char>::BSStringT();
template BSStringT<char>::~BSStringT();
template bool BSStringT<char>::Set(const char* text, unsigned int minimumCapacity);
template void BSStringT<char>::Init();
template unsigned int BSStringT<char>::MaxLength();
template void BSStringT<char>::SetLength(unsigned int length);
template void BSStringT<char>::SetMaxLength(unsigned int length);
template BSStringT<char>& BSStringT<char>::operator=(const char* text);

// Returns the larger of the two unsigned integers a and b.
// @fnv 0x00403940
unsigned int __cdecl FUN_00403940(unsigned int auiFirst, unsigned int auiSecond)
{
    unsigned int result;
    if (auiFirst > auiSecond)
        result = auiFirst;
    else
        result = auiSecond;
    return result;
}

struct FUN_00403a00_class
{
    unsigned short m0;
    unsigned short m1;
    unsigned short m2;
    unsigned short m3;
    unsigned short m4;
    void FUN_00403a00(unsigned int length);
};

// Stores the given length in m3, clamping values above 0xffff to 0xffff.
// @fnv 0x00403a00
void FUN_00403a00_class::FUN_00403a00(unsigned int length)
{
    m3 = length <= 0xffff ? static_cast<unsigned short>(length) : 0xffff;
}

struct FUN_004046b0_arg
{
    void AssignFromString(unsigned int value);
};

struct FUN_004046b0_sub
{
    unsigned int FUN_00717e50();
};

struct FUN_004046b0_cls
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
    FUN_004046b0_sub m_38;
    FUN_004046b0_arg* AssignFromSub(FUN_004046b0_arg* a1);
};

// Calls AssignFromString on a1 with the result of m_38.FUN_00717e50, sets flag to 1, and returns a1.
// @fnv 0x004046b0
FUN_004046b0_arg* FUN_004046b0_cls::AssignFromSub(FUN_004046b0_arg* apArg)
{
    unsigned int flag = 0;
    apArg->AssignFromString(m_38.FUN_00717e50());
    flag |= 1;
    return apArg;
}

int _strlen(const char* text);
int _tolower(int character);

// Returns a pointer to the first case-insensitive occurrence of apString2 within apString1, or 0 if not found.
// @fnv 0x004b75a0
const char* FUN_004b75a0(const char* apString1, const char* apString2)
{
    int j;
    int ilen2;
    int ilen1;
    int i;

    ilen1 = _strlen(apString1);
    ilen2 = _strlen(apString2);

    for (i = 0; i < ilen1 - ilen2 + 1; ++i)
    {
        for (j = 0; j < ilen2; ++j)
        {
            if (_tolower(apString1[i + j]) != _tolower(apString2[j]))
                break;
        }

        if (j == ilen2)
            return apString1 + i;
    }

    return 0;
}

struct FUN_00634830_cls
{
    unsigned int __thiscall GetOffset58();
};

// @fnv 0x00634830
unsigned int __thiscall FUN_00634830_cls::GetOffset58()
{
    return *(unsigned short*)((char*)this + 0x58);
}

#include <stdarg.h>
struct ScopeLock
{
    void* m_p;
    ScopeLock();
    ~ScopeLock();
};

struct Outer
{
    void Print(const char* fmt, va_list args);
};

// Locks a scope, forwards the format string and variadic arguments to obj->Print, then releases the lock.
// @fnv 0x0071d030
void __cdecl FUN_0071d030(Outer* apOuter, const char* fmt, ...)
{
    ScopeLock lock;
    int x;
    {
        va_list args;
        va_start(args, fmt);
        apOuter->Print(fmt, args);
        va_end(args);
    }
}

class TimeoutTimer
{
  public:
    float m_fStartTime;
    float m_fTimeout;
    float FUN_006b9130();
};

// @fnv 0x006b9130
float TimeoutTimer::FUN_006b9130()
{
    return m_fTimeout;
}
