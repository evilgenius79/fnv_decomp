
// src/staging/blk_00ac0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00ac5340_class
{
    void FUN_00ac5220(int a, int b, int c);
    void FUN_00ac5340(int a, int b, int c);
};

// Calls FUN_00ac5220 with the three arguments a, b and c.
// @fnv 0x00ac5340
void FUN_00ac5340_class::FUN_00ac5340(int a, int b, int c)
{
    FUN_00ac5220(a, b, c);
}

void __cdecl _fclose(void*);

struct FUN_00ac5ed0_This
{
    void* m_pFile;
    void CloseFile();
};

// Closes m_pFile with _fclose if the file handle is non-null.
// @fnv 0x00ac5ed0
void FUN_00ac5ed0_This::CloseFile()
{
    if (m_pFile)
        _fclose(m_pFile);
}

extern int DAT_011f6c88;

// @fnv 0x00ac63f0
bool FUN_00ac63f0()
{
    return DAT_011f6c88 != 0;
}

extern int DAT_011f6c88;
extern char DAT_011f6c8c;

// @fnv 0x00ac6410
void SetGlobalIfUnset(int aiValue)
{
    if (DAT_011f6c88 == 0)
    {
        DAT_011f6c88 = aiValue;
        DAT_011f6c8c = 0;
    }
}

extern char DAT_011f6c8c;
extern int DAT_011f6c88;

// @fnv 0x00ac6830
void __cdecl FUN_00ac6830()
{
    DAT_011f6c8c = 0;
    DAT_011f6c88 = 0;
}

extern "C" void __cdecl FUN_00ac6850();
extern "C" void __stdcall FUN_00eccec5(int);
extern int DAT_011f6c88;

// @fnv 0x00ac68e0
void __cdecl FUN_00ac68e0()
{
    if (DAT_011f6c88)
    {
        FUN_00ac6850();
        FUN_00eccec5(-1);
    }
}

struct FUN_00acb7d0_class
{
    int __thiscall FUN_00acb7d0(int);
};

// @fnv 0x00acb7d0
int __thiscall FUN_00acb7d0_class::FUN_00acb7d0(int)
{
    return -1;
}

struct FUN_00acbb60_Class
{
    void* __thiscall GetSelf(void*, void*);
};

// @fnv 0x00acbb60
void* __thiscall FUN_00acbb60_Class::GetSelf(void* apUnusedA, void* apUnusedB)
{
    return this;
}

extern int DAT_010a2f9c;
extern int DAT_010a2fa4;
void __cdecl Deallocate(void*);
void __cdecl FUN_00ec3205(void*);
struct FUN_00acdfa0_class
{
    void* __thiscall FUN_00acdfa0(int a);
};
// @fnv 0x00acdfa0
void* __thiscall FUN_00acdfa0_class::FUN_00acdfa0(int aiFlags)
{
    *(void**)this = &DAT_010a2fa4;
    *(void**)this = &DAT_010a2f9c;
    FUN_00ec3205(this);
    if (aiFlags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00ad4000_Class
{
    char __thiscall Identity(char a);
};

// @fnv 0x00ad4000
char __thiscall FUN_00ad4000_Class::Identity(char acValue)
{
    return acValue;
}

struct FUN_00ad4080_Class
{
    unsigned char __thiscall GetParam(unsigned char param, int extra);
};

// @fnv 0x00ad4080
unsigned char FUN_00ad4080_Class::GetParam(unsigned char aucValue, int extra)
{
    return aucValue;
}

extern int DAT_010a31f4;
extern int DAT_010a31fc;

struct FUN_00ad41a0_cls
{
    void FUN_00ad41a0();
};

// @fnv 0x00ad41a0
void FUN_00ad41a0_cls::FUN_00ad41a0()
{
    *reinterpret_cast<int**>(this) = &DAT_010a31f4;
    *reinterpret_cast<int**>(this) = &DAT_010a31fc;
}

struct BSAudioManager
{
    static BSAudioManager& GetRandomGenerator();
    void FUN_00adcd00(void* a, void* b);
    void FUN_00ad84e0(void* a, void* b);
};

// @fnv 0x00ad84e0
void BSAudioManager::FUN_00ad84e0(void* a, void* b)
{
    GetRandomGenerator().FUN_00adcd00(a, b);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_00ac10c0_Class
{
    float f0;
    float f4;
    float f8;
    NiPoint3* __thiscall AddOffset(NiPoint3* pDest, NiPoint3* pSource);
};

// Adds the object's f0/f4/f8 offsets to pSource's x/y/z and stores the result in pDest, which it returns.
// @fnv 0x00ac10c0
NiPoint3* __thiscall FUN_00ac10c0_Class::AddOffset(NiPoint3* pDest, NiPoint3* pSource)
{
    float c = pSource->x + f0;
    float b = pSource->y + f4;
    float a = pSource->z + f8;
    pDest->x = c;
    pDest->y = b;
    pDest->z = a;
    return pDest;
}

int __cdecl GetHighestSetBitIndex(int);

// Returns the result of GetHighestSetBitIndex if param_1 equals 1 shifted by that result, otherwise that result plus one.
// @fnv 0x00ac6950
int __cdecl FUN_00ac6950(int aiValue)
{
    if (aiValue == (1 << GetHighestSetBitIndex(aiValue)))
    {
        return GetHighestSetBitIndex(aiValue);
    }
    else
    {
        return GetHighestSetBitIndex(aiValue) + 1;
    }
}

extern double DAT_01094ba8;
extern double DAT_010a2f90;

// @fnv 0x00ac7990
int __cdecl FUN_00ac7990(int aiLeft, int aiRight)
{
    double v = (double)aiLeft + (double)aiRight;
    if (v < DAT_01094ba8)
        return 0x80000000;
    else if (v > DAT_010a2f90)
        return 0x7fffffff;
    return (int)v;
}

void __cdecl Deallocate(void*);
void __cdecl FUN_00ec3205(void*);
extern int DAT_010a2f9c;

struct FUN_00ac9c30_class
{
    void* m_p;
    void* __thiscall FUN_00ac9c30(int flags);
};

// @fnv 0x00ac9c30
void* __thiscall FUN_00ac9c30_class::FUN_00ac9c30(int flags)
{
    m_p = &DAT_010a2f9c;
    FUN_00ec3205(this);
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00acad30_class
{
    void* __thiscall GetElementAt(int a);
};
unsigned int __cdecl FUN_00ec7c56();
// Returns a pointer to the element at index a, calling FUN_00ec7c56 if a is out of range.
// @fnv 0x00acad30
void* __thiscall FUN_00acad30_class::GetElementAt(int aiIndex)
{
    if (aiIndex >= (unsigned int)(*(int*)((char*)this + 0x10) - *(int*)((char*)this + 0xc)))
        FUN_00ec7c56();
    return *(char**)((char*)this + 0xc) + aiIndex;
}

struct FUN_00ace030_class
{
    void* __thiscall FUN_00acb6b0();
    void* __thiscall FUN_00ace030(unsigned int flags);
};

// Calls FUN_00acb6b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00ace030
void* FUN_00ace030_class::FUN_00ace030(unsigned int flags)
{
    int pad0, pad1, pad2, pad3, pad4, pad5;
    FUN_00acb6b0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00ace9c0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    int* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    int* m_30;
    int AdvanceCounter();
};

// Decrements the counter at m_30, increments the counter at m_20, and returns the incremented value.
// @fnv 0x00ace9c0
int FUN_00ace9c0_Class::AdvanceCounter()
{
    *m_30 = *m_30 - 1;
    *m_20 = *m_20 + 1;
    return *m_20;
}

unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_00ad1a50_class
{
    FUN_00ad1a50_class* __thiscall FUN_00ad1a50(int a, int b);
};
// Stores 0 then a at offsets 0 and 4, calls FUN_00ec7c56 if b is null, then copies the int at b into offset 0 and returns this.
// @fnv 0x00ad1a50
FUN_00ad1a50_class* __thiscall FUN_00ad1a50_class::FUN_00ad1a50(int aiFirst, int piSource)
{
    *reinterpret_cast<int*>(this) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = aiFirst;
    if (piSource == 0)
        FUN_00ec7c56();
    *reinterpret_cast<int*>(this) = *reinterpret_cast<int*>(piSource);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00ad3eb0_Class
{
    int* m_p;
    FUN_00ad3eb0_Class* __thiscall FUN_00ad3eb0(unsigned int flags);
};
// Sets m_p to DAT_010a31fc and, when bit 0 of flags is set, deallocates this object before returning it.
// @fnv 0x00ad3eb0
FUN_00ad3eb0_Class* __thiscall FUN_00ad3eb0_Class::FUN_00ad3eb0(unsigned int flags)
{
    m_p = &DAT_010a31fc;
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" char __cdecl FUN_00ec379c(char, char*);

struct FUN_00ad3f50_class
{
    char* __thiscall FUN_00ad3f50(char* p, char* end);
};

// Applies FUN_00ec379c to each character from p up to end, writing the result back in place, and returns the end pointer.
// @fnv 0x00ad3f50
char* __thiscall FUN_00ad3f50_class::FUN_00ad3f50(char* pBegin, char* end)
{
    for (; pBegin != end; ++pBegin)
        *pBegin = FUN_00ec379c(*pBegin, (char*)this + 8);
    return pBegin;
}

void __cdecl Deallocate(void*);
void __cdecl free(void*);
struct FUN_00ad41c0_Class
{
    void __thiscall FUN_00ad41c0();
};
// @fnv 0x00ad41c0
void __thiscall FUN_00ad41c0_Class::FUN_00ad41c0()
{
    if (((int*)this)[5] > 0)
        free((void*)((int*)this)[4]);
    else if (((int*)this)[5] < 0)
    {
        void* p = (void*)((int*)this)[4];
        Deallocate(p);
    }
}

extern int DAT_010a3228;
extern int DAT_010a31fc;
void __cdecl Deallocate(void*);
struct FUN_00ad5670_class
{
    int* __thiscall FUN_00ad5670(int a);
};
// @fnv 0x00ad5670
int* __thiscall FUN_00ad5670_class::FUN_00ad5670(int aiFlags)
{
    *(int**)this = &DAT_010a3228;
    *(int**)this = &DAT_010a31fc;
    if (aiFlags & 1)
        Deallocate(this);
    return (int*)this;
}

extern int DAT_010a3204;
extern int DAT_010a3228;
extern int DAT_010a31fc;
void __cdecl Deallocate(void*);

struct FUN_00ad5730_Class
{
    void* __thiscall FUN_00ad5730(int flags);
};

// @fnv 0x00ad5730
void* __thiscall FUN_00ad5730_Class::FUN_00ad5730(int flags)
{
    *reinterpret_cast<void**>(this) = &DAT_010a3204;
    *reinterpret_cast<void**>(this) = &DAT_010a3228;
    *reinterpret_cast<void**>(this) = &DAT_010a31fc;
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __fastcall FUN_00adc160(void* p);

struct FUN_00ad87d0_Class
{
    void FUN_00ad87d0();
};

// Sets six consecutive floats at offsets 0x158-0x16c to 1.0 and then calls FUN_00adc160 on this.
// @fnv 0x00ad87d0
void FUN_00ad87d0_Class::FUN_00ad87d0()
{
    *(float*)((char*)this + 0x158) = 1.0f;
    *(float*)((char*)this + 0x15c) = 1.0f;
    *(float*)((char*)this + 0x160) = 1.0f;
    *(float*)((char*)this + 0x164) = 1.0f;
    *(float*)((char*)this + 0x168) = 1.0f;
    *(float*)((char*)this + 0x16c) = 1.0f;
    FUN_00adc160(this);
}

int __cdecl FUN_00ec34d4();

struct FUN_00ad3a10_Class
{
    int __thiscall GetEntryAt(int a);
};

// Returns the entry at index a from the array, falling back to FUN_00ec34d4's array when the entry is zero and the flag at offset 0x14 is clear.
// @fnv 0x00ad3a10
int __thiscall FUN_00ad3a10_Class::GetEntryAt(int aiIndex)
{
    unsigned int v;
    int r;
    v = (aiIndex < *(unsigned int*)((char*)*(void**)((char*)this + 0) + 0xc))
            ? (*(int**)((char*)*(void**)((char*)this + 0) + 8))[aiIndex]
            : 0;
    if (v || !*(unsigned char*)((char*)*(void**)((char*)this + 0) + 0x14))
        return v;
    else
    {
        r = FUN_00ec34d4();
        return (aiIndex < *(unsigned int*)((char*)r + 0xc)) ? (*(int**)((char*)r + 8))[aiIndex] : 0;
    }
}

void __cdecl ReportAssertionViolation(char const*, int);

// Asserts param_1 is greater than 0, then shifts it right until it reaches 0 and returns the number of shifts minus one.
// @fnv 0x00ac6900
int __cdecl GetHighestSetBitIndex(unsigned int uiValue)
{
    if (uiValue > 0)
        ;
    else
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 39);
    int count = 0;
    do
    {
        uiValue >>= 1;
        count++;
    } while (uiValue > 0);
    return count - 1;
}

extern "C" char __cdecl FUN_00ec3909(char, char*);

struct FUN_00ad3fc0_Class
{
    char* __thiscall FUN_00ad3fc0(char* p, char* pEnd);
};

// @fnv 0x00ad3fc0
char* __thiscall FUN_00ad3fc0_Class::FUN_00ad3fc0(char* pBegin, char* pEnd)
{
    for (; pBegin != pEnd; ++pBegin)
        *pBegin = FUN_00ec3909(*pBegin, (char*)this + 8);
    return pBegin;
}

struct FUN_00ac1120_Class
{
    float f0;
    float f4;
    float f8;
    NiPoint3* __thiscall ScaleToPoint3(NiPoint3* pDest, float scale);
};

// Multiplies f0, f4 and f8 by scale, writes the results to pDest's x, y and z, and returns pDest.
// @fnv 0x00ac1120
NiPoint3* FUN_00ac1120_Class::ScaleToPoint3(NiPoint3* pDest, float scale)
{
    float fX = scale * f0;
    float fY2 = scale * f4;
    float fZ2 = scale * f8;
    pDest->x = fX;
    pDest->y = fY2;
    pDest->z = fZ2;
    return pDest;
}

struct FUN_00ac52b0_class
{
    void FUN_00ac52b0(int a, int b, int c);
    void FUN_00ac5370(int a, int b, int c);
};
// @fnv 0x00ac5370
void FUN_00ac52b0_class::FUN_00ac5370(int a, int b, int c)
{
    FUN_00ac52b0(a, b, c);
}

unsigned __int64 __cdecl __time64(unsigned __int64*);
void __cdecl FUN_00ecada6(unsigned int);
int __cdecl GetRandomNumber();
extern double DAT_01031140;
extern unsigned char DAT_011f6c78;

// @fnv 0x00ac6220
double FUN_00ac6220()
{
    if (!DAT_011f6c78)
    {
        FUN_00ecada6(static_cast<unsigned int>(__time64(0)));
        DAT_011f6c78 = 1;
    }

    double fScale = DAT_01031140;
    double fRandom = 0.0;

    for (int i = 0; i < 4; ++i)
    {
        fRandom = fRandom * fScale + GetRandomNumber();
    }

    fRandom /= (fScale * fScale * fScale * fScale);
    return fRandom;
}

// Adds two unsigned bytes and returns the sum clamped to 255.
// @fnv 0x00ac7870
char AddSaturateBytes(unsigned char a, unsigned char b)
{
    int i = a + b;
    int aC = 255;
    char* p2 = (aC < i) ? (char*)&aC : (char*)&i;
    return *p2;
}

// Adds the two char arguments, clamps the sum to the range [-128, 127], and returns the clamped value as a char.
// @fnv 0x00ac78b0
char __cdecl ClampSumToChar(char acValue1, char acValue2)
{
    int sum_2 = acValue1 + acValue2;
    int hi2 = 0x7f;
    int* p1;
    if (hi2 < sum_2)
        p1 = &hi2;
    else
        p1 = &sum_2;
    int* aQ1 = p1;
    sum_2 = *aQ1;
    int lo_ = 0xffffff80;
    int* p5;
    if (lo_ < sum_2)
        p5 = &sum_2;
    else
        p5 = &lo_;
    int* q2 = p5;
    return *(char*)q2;
}

struct GlobalObjectO2_00ec3a75
{
    ~GlobalObjectO2_00ec3a75();
};

void __cdecl _Deallocate(void*);

struct FUN_00acdf60_class
{
    void* __thiscall DestroyAndDeallocate(int flags);
};

// Runs the destructor on the object at this-4 and, if flags has bit 0 set, deallocates it, returning that object pointer.
// @fnv 0x00acdf60
void* __thiscall FUN_00acdf60_class::DestroyAndDeallocate(int flags)
{
    {
        int unused1;
        int unused2;
    }

    reinterpret_cast<GlobalObjectO2_00ec3a75*>(reinterpret_cast<char*>(this) - 4)
        ->GlobalObjectO2_00ec3a75::~GlobalObjectO2_00ec3a75();

    if (flags & 1)
        _Deallocate(reinterpret_cast<GlobalObjectO2_00ec3a75*>(reinterpret_cast<char*>(this) - 4));

    return reinterpret_cast<GlobalObjectO2_00ec3a75*>(reinterpret_cast<char*>(this) - 4);
}

extern int DAT_010a30a8;
void FUN_00ec3205(void*);

struct FUN_00ace330_class
{
    void FUN_00ace330();
};

// @fnv 0x00ace330
void FUN_00ace330_class::FUN_00ace330()
{
    void** p = (void**)((char*)this + 8);
    *(void**)((char*)p + *(int*)(*(int*)((char*)p - 8) + 4) - 8) = &DAT_010a30a8;
    void** q = (void**)((char*)this + 8);
    *q = &DAT_010a2fa4;
    *q = &DAT_010a2f9c;
    FUN_00ec3205(q);
}

struct FUN_00ec32e3_t
{
    char b[4];
    void FUN_00ec32e3(int);
    void FUN_00ec330b();
};
struct FUN_00ace790_class
{
    int m_iWordAt00;
    unsigned int m_iWordAt04;
    void IncrementCounter();
};
// @fnv 0x00ace790
void FUN_00ace790_class::IncrementCounter()
{
    FUN_00ec32e3_t t;
    t.FUN_00ec32e3(0);
    if (m_iWordAt04 < (unsigned int)-1)
        m_iWordAt04++;
    t.FUN_00ec330b();
}

struct FUN_00ad3ee0
{
    void* m_vft;
    FUN_00ad3ee0(int a);
};
// Sets the object's vtable pointer to DAT_010a31fc and deallocates the object when bit 0 of a is set.
// @fnv 0x00ad3ee0
FUN_00ad3ee0::FUN_00ad3ee0(int aiFlags)
{
    m_vft = (void*)&DAT_010a31f4;
    m_vft = (void*)&DAT_010a31fc;
    if (aiFlags & 1)
        Deallocate(this);
}

char __cdecl FUN_00ec379c(char, char*);
struct FUN_00ad3f20_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    char __thiscall FUN_00ad3f20(char c);
};
// Calls FUN_00ec379c with c and a pointer to this object's offset 8, returning its result.
// @fnv 0x00ad3f20
char FUN_00ad3f20_Class::FUN_00ad3f20(char acChar)
{
    return FUN_00ec379c(acChar, (char*)this + 8);
}

extern "C" char __cdecl FUN_00ec3909(char, char*);

struct FUN_00ad3f90_Class
{
    char m0;
    char m1;
    char m2;
    char m3;
    char m4;
    char m5;
    char m6;
    char m7;
    char FUN_00ad3f90(char c);
};

// @fnv 0x00ad3f90
char FUN_00ad3f90_Class::FUN_00ad3f90(char acValue)
{
    return FUN_00ec3909(acValue, (char*)this + 8);
}

struct FUN_00ad56e0_class
{
    int FUN_00ad56e0(void* a, void* b, void* c, void* d);
};

// @fnv 0x00ad56e0
int FUN_00ad56e0_class::FUN_00ad56e0(void* apUnused, void* apValue, void* apUnused2, void* apOut)
{
    *reinterpret_cast<void**>(apOut) = apValue;
    return 3;
}

unsigned int __cdecl FUN_00ec7c56(void);
struct FUN_00ac0460_cls
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    int __thiscall FUN_00ac0460(FUN_00ac0460_cls* other);
};
// @fnv 0x00ac0460
int __thiscall FUN_00ac0460_cls::FUN_00ac0460(FUN_00ac0460_cls* other)
{
    if (!((unsigned char)(int)(m_iWordAt00 != 0) && (unsigned char)(int)(m_iWordAt00 == other->m_iWordAt00)))
    {
        FUN_00ec7c56();
    }
    return ((unsigned char)(int)(m_iWordAt04 == other->m_iWordAt04) ? -1 : 0) + 1;
}

void __cdecl FUN_00ac1d10(int a, int b, int c, unsigned char d, unsigned char e, unsigned char f);

struct ByteBox
{
    unsigned char v;
};

struct FUN_00ac1530_Pad
{
    unsigned int m_p0;
    unsigned int m_p1;
    unsigned int m_p2;
    unsigned int m_p3;
    unsigned int m_p4;
    unsigned int m_p5;
    unsigned int m_p6;
    unsigned int m_p7;
    unsigned int m_p8;
};

// @fnv 0x00ac1530
void __cdecl FUN_00ac1530(int p0, int p1, int p2)
{
    ByteBox z6 = {};
    ByteBox u;
    ByteBox wVal;
    ByteBox c7 = wVal;
    int unkA;
    {
        int slot0c = p1;
        int q9;
        int slot14 = p0;
        FUN_00ac1530_Pad padA;
        FUN_00ac1d10(slot14, slot0c, p2, u.v, c7.v, z6.v);
    }
}

extern int DAT_010173f0;

class SpawnSub
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void Attach(SpawnSub* other);
};

class SpawnEntry
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    SpawnSub m_sub;
    void Init(SpawnEntry* a3, int zero, int value);
};

// Initializes each SpawnEntry in [first,last) from src and attaches its sub-object to src's sub-object.
// @fnv 0x00ac1670
void InitRange(SpawnEntry* first, SpawnEntry* last, SpawnEntry* src)
{
    unsigned int buf[94];
    int tmp;
    SpawnEntry* end = last;
    for (SpawnEntry* cur = first; cur != end; cur++)
    {
        cur->Init(src, 0, DAT_010173f0);
        cur->m_sub.Attach(&src->m_sub);
    }
}

struct FUN_00ac1720_pool
{
    void* FUN_00aa3e40(unsigned int size);
};

extern "C" FUN_00ac1720_pool DAT_011f6238;
extern "C" char DAT_010176f8[];
extern "C" char DAT_01140ef8[];
extern "C" void __stdcall FUN_00ec7894(void* err2, const char* msg);

struct FUN_00ac1720_err
{
    void* m_vptr;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00ec78f1(unsigned int* out);
};

// Validates count, reports an error if count*4 would overflow, then allocates count*4 bytes from the pool.
// @fnv 0x00ac1720
void __cdecl FUN_00ac1720(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 4)
        {
            unsigned int tmp = 0;
            FUN_00ac1720_err err2;
            err2.FUN_00ec78f1(&tmp);
            err2.m_vptr = DAT_010176f8;
            FUN_00ec7894(&err2, DAT_01140ef8);
        }
    }
    DAT_011f6238.FUN_00aa3e40(count * 4);
}

struct FUN_00ac2760_Frame
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
};
struct FUN_0044a580_cls
{
    void AssignSubstring(int a, int b, int c);
};
struct FUN_00ac2ca0_cls
{
    int unk00;
    void FUN_00ac2ca0(int a);
};
struct FUN_00ac2760_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    FUN_00ac2ca0_cls m_20;
    FUN_00ac2760_cls* CopyFrom(int a);
    void AssignSubstring(int a, int b, int c);
};
extern int DAT_010173f0;
// @fnv 0x00ac2760
FUN_00ac2760_cls* FUN_00ac2760_cls::CopyFrom(int pSource)
{
    FUN_00ac2760_Frame frame;
    this->AssignSubstring(pSource, 0, DAT_010173f0);
    m_1c = ((FUN_00ac2760_cls*)pSource)->m_1c;
    m_20.FUN_00ac2ca0(pSource + 0x20);
    return this;
}

struct CopyRecord
{
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
struct IteratorTag
{
    unsigned char marker;
};
// Copies the range [first, last) into destination and returns a pointer one past the last written element.
// @fnv 0x00ac2c20
CopyRecord* __cdecl CopyRecords(CopyRecord* first, CopyRecord* last, CopyRecord* destination)
{
    CopyRecord* destEnd = destination + (last - first);
    IteratorTag destTag = {};
    IteratorTag sourceTag = {};
    CopyRecord* out;
    CopyRecord* src;
    {
        IteratorTag actualDestTag = destTag;
        IteratorTag actualSourceTag = sourceTag;
        out = destination;
        src = first;
        for (; src != last; ++out, ++src)
        {
            *out = *src;
        }
    }
    return destEnd;
}

struct ZeroFlagByte
{
    bool v;
};

// Copies len bytes from src to dst using a byte-by-byte loop.
// @fnv 0x00ac3300
void __cdecl FUN_00ac3300(char* dst, unsigned int len, char* src)
{
    ZeroFlagByte a = {};
    char b9;
    bool a2 = a.v;
    char b3 = b9;
    char* p6 = dst;
    char* end2 = p6 + len;
    ZeroFlagByte _c = {};
    bool c5 = _c.v;
    unsigned int n3 = len;
    char* q = p6;
    for (; n3 > 0; n3--, q++)
    {
        *q = *src;
    }
}

namespace fnv_00ac3580 {
extern "C" void __cdecl FUN_00ac3370(int a1, int a2, int a3, int a4, unsigned char c2, unsigned char c1);
struct ByteBox
{
    unsigned char v;
};
// @fnv 0x00ac3580
void __cdecl FUN_00ac3580(int a1, int a2, int a3, int a4)
{
    ByteBox c7 = {};
    ByteBox c3;
    ByteBox c8 = c3;
    int p2 = a2;
    int m = a1;
    int unk10;
    FUN_00ac3370(m, p2, a3, a4, c8.v, c7.v);
}
}  // namespace fnv_00ac3580

struct BAC3640Iterator
{
    int* m_piPtr;
};

struct BAC3640PtrCategory
{
    char m_cKind;
};
struct BAC3640CheckedTag
{
};

void __cdecl BAC3640UninitCopy(BAC3640Iterator kFirst, BAC3640Iterator kLast, int* piDest, void* pvAllocator,
                               BAC3640PtrCategory kCategory, BAC3640CheckedTag kChecked);

// @fnv 0x00ac3640
void __cdecl CopyIteratorRange(BAC3640Iterator kFirst, BAC3640Iterator kLast, int* piDest, void* pvAllocator)
{
    BAC3640CheckedTag kChecked = {};
    BAC3640PtrCategory kCategorySource4;
    BAC3640PtrCategory kCategory = kCategorySource4;
    BAC3640Iterator kLastBase = kLast;
    int* kDest;
    BAC3640Iterator kFirstBase3 = kFirst;
    BAC3640UninitCopy(kFirstBase3, kLastBase, piDest, pvAllocator, kCategory, kChecked);
}

struct IterPos
{
    unsigned int m_ptr;
};

struct EmptyTag
{
    char m_unk00;
};

struct IterRange
{
    IterPos m_pHeadNode;
    unsigned int unk04;
    IterPos m_last;
};

void __cdecl FUN_00ac3900(IterPos first, IterPos last, int a3, int a4, EmptyTag tagA, EmptyTag tagB);

// @fnv 0x00ac3690
void __cdecl FUN_00ac3690(IterPos a1, IterPos a2, int a3, int a4)
{
    EmptyTag zeroTag = {};
    EmptyTag srcTag;
    EmptyTag copyTag = srcTag;
    IterRange r;
    r.m_last = a2;
    r.m_pHeadNode = a1;
    FUN_00ac3900(r.m_pHeadNode, r.m_last, a3, a4, copyTag, zeroTag);
}

struct Tag1
{
    char c;
};
struct Tag1D : Tag1
{
};
struct Tag2
{
};
struct Iter
{
    int* p;
};
struct E0
{
};
struct ED : E0
{
};

void FUN_00ac39e0(Iter a, Iter b, int c, int d, Tag1 e, Tag2 f);

// Constructs temporary tag and iterator objects and forwards them with c and d to FUN_00ac39e0.
// @fnv 0x00ac36e0
void CallWithIterators(Iter a, Iter b, int c, int d)
{
    FUN_00ac39e0((ED(), Iter(a)), Iter(b), c, d, Tag1D(), Tag2());
}

struct S_00ac3f40_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S_00ac3f40_Inner
{
    int unk00;
    unsigned char* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    void __thiscall AssignSubstring(S_00ac3f40_Arg* arg, int value, int flag);
};

struct S_00ac3f40_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00ac3f40_Inner unk20;
    int unk3c;

    void __thiscall FUN_00ac3f40(S_00ac3f40_Arg* arg);
};

extern int DAT_010173f0;

// @fnv 0x00ac3f40
void __thiscall S_00ac3f40_Class::FUN_00ac3f40(S_00ac3f40_Arg* arg)
{
    S_00ac3f40_Class localCopy;
    int value = arg->unk14;

    if (value == 8)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\binaryFile.cpp", 0x30);
    }

    if (this->unk3c == 0)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\binaryFile.cpp", 0x31);
    }

    this->unk20.AssignSubstring(arg, 0, DAT_010173f0);

    S_00ac3f40_Inner* pInner = &this->unk20;

    if ((unsigned int)pInner->unk14 < 5)
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);

    ((unsigned int)pInner->unk18 >= 0x10 ? pInner->unk04 : (unsigned char*)&pInner->unk04)[5] = 0x30;
}

class Holder40_FUN_00ac5c00
{
  public:
    virtual int vDel(int flags);
};

class Holder44_FUN_00ac5c00
{
  public:
    void Reset();
};

class FUN_00ac5c00_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    Holder40_FUN_00ac5c00* m_40;
    Holder44_FUN_00ac5c00* m_44;

    void ClearHolders();
};

struct Pad_X
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};
// If m_44 is set, clears m_40, resets m_44 and nulls it; otherwise deletes m_40 via vDel(1) and nulls it.
// @fnv 0x00ac5c00
void FUN_00ac5c00_cls::ClearHolders()
{
    Holder40_FUN_00ac5c00* tmp;
    Pad_X unk;
    Holder40_FUN_00ac5c00* copy3;
    if (m_44 != 0)
    {
        m_40 = 0;
        m_44->Reset();
        m_44 = 0;
    }
    else
    {
        tmp = m_40;
        copy3 = tmp;
        copy3 != 0 ? copy3->vDel(1) : 0;
        m_40 = 0;
    }
}

class FUN_00ac5c70_target
{
  public:
    virtual void vSlot00();
    virtual void vSlot01();
    virtual void vSlot02();
    virtual void vSlot03();
    virtual void vSlot04();
    virtual void vSlot05();
    virtual void vSlot06();
    virtual void vSlot07();
    virtual void vSlot08();
    virtual void vSlot09();
    virtual void vSlot10();
    virtual void vSlot11();
    virtual void vSlot12();
    virtual void vSlot13();
    virtual void vSlot14();
    virtual void vSlot15();
    virtual void vSlot16();
    virtual unsigned int vSlot17(void* a1, unsigned int a2);
    unsigned int m_04;
};

class FUN_00ac5c70_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    FUN_00ac5c70_target* m_40;

    unsigned char FUN_00ac5c70(void* a1, unsigned int a2);
};

// If m_40 is set, calls its vSlot17 with a2*2, adds the result to m_04, and returns whether the result equals a2*2.
// @fnv 0x00ac5c70
unsigned char FUN_00ac5c70_cls::FUN_00ac5c70(void* a1, unsigned int auiValue)
{
    if (m_40 == 0)
    {
        return false;
    }
    unsigned int value = auiValue * 2;
    unsigned int ptr = 0;
    void* total = a1;
    unsigned int scale = 0;
    ptr = m_40->vSlot17(a1, value);
    FUN_00ac5c70_target* t = m_40;
    t->m_04 += ptr;
    return value == ptr;
}

void __cdecl ReportAssertionViolation(char const*, int);

struct FgBinaryStream;
typedef unsigned int(__cdecl* FgReadFunc)(FgBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

struct FgBinaryStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    FgReadFunc m_pfnRead;
};

struct FgBinaryFile
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
    FgBinaryStream* m_pBinaryStream;
    bool FUN_00ac5cf0(void* pvBuffer, unsigned int uiSize, unsigned int ItemUpdateArray);
};

// @fnv 0x00ac5cf0
bool FgBinaryFile::FUN_00ac5cf0(void* pvBuffer, unsigned int uiSize, unsigned int uiElementCount)
{
    if (m_pBinaryStream == 0)
        return false;

    unsigned int uiTotalTmp = uiSize * uiElementCount;
    unsigned int uiRead6 = 0;
    switch (uiSize)
    {
    case 1:
    case 2:
    case 4: {
        unsigned int uiBytes;
        {
            FgBinaryStream* pStream3 = m_pBinaryStream;
            uiBytes = pStream3->m_pfnRead(pStream3, pvBuffer, uiTotalTmp, &uiSize, 1);
            pStream3->m_uiStreamFlags += uiBytes;
        }
        uiRead6 = uiBytes;
    }
    break;
    default:
        if (uiSize % 4 == 0)
        {
            uiSize = 4;
        }
        else
        {
            if (0)
            {
            }
            else
            {
                ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\binaryFile.cpp", 0x1fc);
            }
            uiSize = 1;
        }
        {
            unsigned int uiBytes2;
            {
                FgBinaryStream* pStream4 = m_pBinaryStream;
                uiBytes2 = pStream4->m_pfnRead(pStream4, pvBuffer, uiTotalTmp, &uiSize, 1);
                pStream4->m_uiStreamFlags += uiBytes2;
            }
            uiRead6 = uiBytes2;
        }
        break;
    }
    return uiTotalTmp == uiRead6 ? true : false;
}

extern int DAT_010a2480;

class FUN_00ac5e90_Target
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a, int g);
};

class FUN_00ac5e90_cls
{
  public:
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
    FUN_00ac5e90_Target* m_40;

    bool CallTargetVFunc(int a);
};

// Returns false if m_40 is null; otherwise calls m_40->v5(a, DAT_010a2480) and returns true.
// @fnv 0x00ac5e90
bool FUN_00ac5e90_cls::CallTargetVFunc(int a)
{
    if (m_40 == 0)
    {
        return false;
    }
    m_40->v5(a, DAT_010a2480);
    return true;
}

struct FUN_00ac6100_cls
{
    int unk00;
    char* m_04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_14;
    unsigned int m_18;

    int FUN_00ac6100(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

int __cdecl FUN_00ec4835(char* p, int a, unsigned int n);
void __cdecl FUN_00ec30e8();

// @fnv 0x00ac6100
int FUN_00ac6100_cls::FUN_00ac6100(unsigned int a1, unsigned int uiAvailable, int a3, unsigned int a4)
{
    if (m_14 < a1)
    {
        FUN_00ec30e8();
    }
    if (m_14 - a1 < uiAvailable)
    {
        uiAvailable = m_14 - a1;
    }
    unsigned int n;
    if (uiAvailable < a4)
    {
        n = uiAvailable;
    }
    else
    {
        n = a4;
    }
    int iReadResult = FUN_00ec4835((m_18 >= 0x10 ? m_04 : (char*)&m_04) + a1, a3, n);
    return (iReadResult != 0) ? iReadResult : (uiAvailable < a4 ? -1 : (uiAvailable != a4));
}

extern double DAT_01011590;
extern double DAT_0101a6b0;
extern double DAT_0106d4c8;
double __cdecl FUN_00ac6220();
double __cdecl FUN_00eca920(double x);
double __cdecl FUN_00ec6054(double x);

class FUN_00ac62b0_cls
{
  public:
    double m_00;
    double m_08;
    double m_10;
    double SampleNormal();
};

// @fnv 0x00ac62b0
double FUN_00ac62b0_cls::SampleNormal()
{
    double u3;
    double v;
    double s;
    do
    {
        u3 = FUN_00ac6220() * DAT_01011590 + DAT_0101a6b0;
        v = FUN_00ac6220() * DAT_01011590 + DAT_0101a6b0;
        s = u3 * u3 + v * v;
    } while (s > 1.0 || s == 0.0);
    double mean = this->m_00;
    double inv = 1.0 / this->m_10;
    return (inv * v) * FUN_00ec6054(FUN_00eca920(s) * DAT_0106d4c8 / s) + mean;
}

extern double DAT_01011590;
extern double DAT_0101a6b0;
extern double DAT_0106d4c8;

double __cdecl FUN_00ac6220();
double __cdecl FUN_00eca920(double value);
double __cdecl FUN_00ec6054(double value);

// Generates a Gaussian-distributed random value via the Box-Muller transform, rejecting samples outside the unit circle or with zero sum.
// @fnv 0x00ac6360
double __cdecl GenerateGaussianRandom()
{
    double first;
    double second;
    double sum;

    do
    {
        do
        {
            second = FUN_00ac6220() * DAT_01011590 + DAT_0101a6b0;
            first = FUN_00ac6220() * DAT_01011590 + DAT_0101a6b0;
            sum = second * second + first * first;
        } while (sum > 1.0);
    } while (sum == 0.0);

    return FUN_00ec6054(FUN_00eca920(sum) * DAT_0106d4c8 / sum) * first;
}

extern "C" int __cdecl FUN_00ec6130(char* p);

struct Ac6510Target
{
    void FUN_0044a7f0(char* p, int v);
};

struct Ac6510Frame
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};

extern char DAT_011f6c8c;
extern int DAT_011f6c88;

// Calls FUN_00ec6130 on DAT_011f6c8c, passes the result to the target's FUN_0044a7f0, and returns DAT_011f6c88.
// @fnv 0x00ac6510
int __cdecl ApplyGlobalToTarget(int pTarget)
{
    Ac6510Frame frame;
    int tmp = FUN_00ec6130(&DAT_011f6c8c);
    ((Ac6510Target*)pTarget)->FUN_0044a7f0(&DAT_011f6c8c, tmp);
    return DAT_011f6c88;
}

void __cdecl ReportAssertionViolation(char const*, int);

// @fnv 0x00ac6990
void __cdecl FindPairByIndex(unsigned int count, unsigned int target, unsigned int* puiOutA, unsigned int* puiOutB)
{
    if (count > 0)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0x53);
    }
    unsigned int i = 0;
    *puiOutA = 0;
    for (; *puiOutA < count; (*puiOutA)++)
    {
        for (*puiOutB = *puiOutA + 1; *puiOutB < count; (*puiOutB)++)
        {
            if (target == i)
            {
                return;
            }
            i++;
        }
    }
    if (0 != 0)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0x60);
    }
}

// Adds a and b, clamps the sum to the signed 16-bit range, and returns the low byte of the clamped value.
// @fnv 0x00ac7920
short __cdecl ClampToShort(short asValueA, short asValueB)
{
    int sum = asValueA + asValueB;
    int hi = 0x7fff;
    int* p5 = (hi < sum) ? &hi : &sum;
    sum = *p5;
    int lo3 = (int)0xffff8000;
    int* InvokeFifthVirtualFunction = (lo3 < sum) ? &sum : &lo3;
    return *(char*)InvokeFifthVirtualFunction;
}

void __cdecl FUN_00ec3205(void*);

struct SpawnedBase
{
    unsigned int unk00;
    void Init();
};

struct SpawnedObject
{
    unsigned int unk00[0x14];
    SpawnedBase m_sub;

    void InitSub();
};

// Calls Init on m_sub, overwrites its vtable pointer twice, then passes it to FUN_00ec3205.
// @fnv 0x00ac9c70
void SpawnedObject::InitSub()
{
    unsigned int padLocal[5];
    m_sub.Init();
    {
        SpawnedBase* p = &m_sub;
        *(int*)p = (int)&DAT_010a2fa4;
        *(int*)p = (int)&DAT_010a2f9c;
        FUN_00ec3205(p);
    }
}

extern int DAT_010a2f9c;
extern int DAT_010a2fa4;
void __cdecl FUN_00ec3205(void* p);

struct Sub58
{
    void* m_vptr;
    void Init();
};

struct FUN_00ac9cb0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    Sub58 m_58;
    void InitSub58();
};

// Initializes m_58, sets its vptr to DAT_010a2fa4 then DAT_010a2f9c, and passes it to FUN_00ec3205.
// @fnv 0x00ac9cb0
void FUN_00ac9cb0_cls::InitSub58()
{
    unsigned int unkLocal[5];
    {
        Sub58* p;
        m_58.Init();
        p = &m_58;
        p->m_vptr = (void*)&DAT_010a2fa4;
        p->m_vptr = (void*)&DAT_010a2f9c;
        FUN_00ec3205(p);
    }
}

struct S_00ac9da0_string
{
    int unk00;
    void* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int unk18;
};

struct S_00ac9da0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    void __thiscall FUN_00ac6100(int a, int b, void* c, int d);
    void __thiscall FUN_00ac9da0(S_00ac9da0_string* a);
};

// @fnv 0x00ac9da0
void __thiscall S_00ac9da0_class::FUN_00ac9da0(S_00ac9da0_string* pString)
{
    int len = pString->unk14;
    unsigned int pad[2];

    this->FUN_00ac6100(0, this->unk14, (pString->unk18 >= 0x10) ? pString->unk04 : (void*)((char*)pString + 4), len);
}

struct FUN_00aca4e0_frame
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
};
struct FUN_00aca4e0_cls
{
    int unk00;
    int unk04;
    unsigned int m_08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned int m_28;
    void FUN_00ac9ff0(unsigned int flags, unsigned char mode);
    void FUN_00aca4e0(unsigned int a1, unsigned char a2);
};

// ORs a1 into m_08 and calls FUN_00ac9ff0 with the result, adding flag 4 when m_28 is zero.
// @fnv 0x00aca4e0
void FUN_00aca4e0_cls::FUN_00aca4e0(unsigned int auiFlags, unsigned char a2)
{
    unsigned int base;
    FUN_00aca4e0_frame zz;
    if (auiFlags != 0)
    {
        base = m_08;
        unsigned int flags = base | auiFlags;
        FUN_00ac9ff0((m_28 == 0) ? (flags | 4) : flags, a2);
    }
}

struct FUN_00ec3280_class
{
    void __thiscall FUN_00ec3280();
};

struct FUN_00aca9a0_base
{
    int* vtable;
};

struct FUN_00aca9a0_class
{
    FUN_00aca9a0_base* m_p;

    void __thiscall FUN_00aca9a0();
};

// Reads a pointer at m_p plus the vtable offset plus 0x28 and, if non-null, calls FUN_00ec3280 on the object at that pointer plus 4.
// @fnv 0x00aca9a0
void __thiscall FUN_00aca9a0_class::FUN_00aca9a0()
{
    unsigned int value1 = *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(m_p) +
                                                           reinterpret_cast<unsigned int*>(m_p->vtable)[1] + 0x28);

    if (value1 != 0)
    {
        unsigned int value2 = *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(m_p) +
                                                               reinterpret_cast<unsigned int*>(m_p->vtable)[1] + 0x28);

        reinterpret_cast<FUN_00ec3280_class*>(value2 + 4)->FUN_00ec3280();
    }
}

struct FUN_00aca9f0_P
{
    unsigned char* m_00;
};

struct FUN_00aca9f0_Cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    char _04[0x1c];
    FUN_00aca9f0_P* m_20;
    char _24[0xc];
    int* m_30;
    int FUN_00aca9f0();
};

// @fnv 0x00aca9f0
int FUN_00aca9f0_Cls::FUN_00aca9f0()
{
    unsigned char* ptr;
    return ((m_20->m_00 != 0 ? *m_30 : 0) > 0) ? (ptr = m_20->m_00, *ptr) : v4();
}

struct ListSentinelNode
{
    ListSentinelNode* m_00;
    ListSentinelNode* m_04;
    ListSentinelNode* m_08;
};

struct FUN_00acb1a0_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    ListSentinelNode* m_18;
    int m_1c;

    void FUN_00acf0b0(void* p);
    void ResetListSentinel();
};

// Calls FUN_00acf0b0 on the sentinel's m_04, then points m_04, m_00 and m_08 back to the sentinel and clears m_1c.
// @fnv 0x00acb1a0
void FUN_00acb1a0_cls::ResetListSentinel()
{
    ListSentinelNode* node;
    int unk_04;
    int unk_08;

    FUN_00acf0b0(m_18->m_04);
    m_18->m_04 = m_18;
    m_1c = 0;
    node = m_18;
    node->m_00 = m_18;
    m_18->m_08 = m_18;
}

extern int DAT_010a30fc;
void __cdecl FormHeap_Free(void*);

class Sub_00acb6b0
{
  public:
    unsigned int m_00;
    void FUN_00acb720();
};

class Mem_00acb6b0
{
  public:
    unsigned int m_00;
    void FUN_00ec3260();
};

class FUN_00ec3260_cls
{
  public:
    void FUN_00ec3260();
};

class FUN_00acb6b0_cls
{
  public:
    void* m_vft;
    Mem_00acb6b0 m_04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    Sub_00acb6b0* m_38;
    void FUN_00acb6b0();
};

// @fnv 0x00acb6b0
void FUN_00acb6b0_cls::FUN_00acb6b0()
{
    Sub_00acb6b0* cur;
    Sub_00acb6b0* prev;
    unsigned int arr[4];
    m_vft = &DAT_010a30fc;
    cur = m_38;
    prev = cur;
    prev != 0 ? (prev->FUN_00acb720(), (((prev, 1) & 1) ? FormHeap_Free(prev) : (void)0), prev) : 0;
    ((FUN_00ec3260_cls*)((char*)this + 4))->FUN_00ec3260();
}

class CB770Lockit
{
  public:
    explicit CB770Lockit(int iKind) throw();
    ~CB770Lockit() throw();

    int m_iLocktype;
};

class CB770Facet
{
  public:
    CB770Facet* FUN_00acb770();

    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefs;
};

// Takes a lock, decrements m_uiRefs when it is between 1 and UINT_MAX-1, and returns this if the count reached zero, otherwise null.
// @fnv 0x00acb770
CB770Facet* CB770Facet::FUN_00acb770()
{
    CB770Lockit kLock(0);
    if (0 < m_uiRefs && m_uiRefs < (unsigned int)(-1))
        --m_uiRefs;
    return m_uiRefs == 0 ? this : 0;
}

struct FUN_00acb850_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int a, int b, int c);

    void FUN_00acb850(int a, int b);
};

// Calls v07 with a, -1 and b.
// @fnv 0x00acb850
void FUN_00acb850_cls::FUN_00acb850(int a, int b)
{
    v07(a, -1, b);
}

extern "C" int __cdecl FUN_00ec7c66(void* dst, unsigned int dstSize, const void* src, unsigned int count);

struct SecureCharTraitsTag
{
    char unk00;
};

struct StreamBufStub
{
    virtual ~StreamBufStub();
    virtual int overflow(int ch);
    char** unk04;
    char** unk08;
    char** unk0C;
    char** unk10;
    char** unk14;
    char** unk18;
    char** unk1C;
    char** unk20;
    char** pPutNext;
    char** unk28;
    int* unk2C;
    int* unk30;
    int* pPutCount;
    int WriteChars(const char* ptr, int count);
};

// Copies up to count characters into the put area, flushing via overflow when full, and returns the number written.
// @fnv 0x00acb9b0
int StreamBufStub::WriteChars(const char* apChars, int count)
{
    int copied6 = 0;
    int size_2;
    int n;
    int resultB;
    int eof4;
    char* dst2;
    SecureCharTraitsTag tagCopy;
    SecureCharTraitsTag tag4;
    int ch;
    while (0 < count)
    {
        size_2 = *pPutNext ? *pPutCount : 0;
        if (0 < size_2)
        {
            n = size_2;
            if (count < n)
                n = count;
            dst2 = *pPutNext;
            tagCopy = tag4;
            FUN_00ec7c66(dst2, size_2, apChars, n);
            apChars += n;
            copied6 += n;
            count -= n;
            *pPutCount -= n;
            *pPutNext += n;
        }
        else
        {
            ch = (unsigned char)*apChars;
            resultB = overflow(ch);
            eof4 = -1;
            if ((bool)(int)(eof4 == resultB))
                break;
            else
            {
                ++apChars;
                ++copied6;
                --count;
            }
        }
    }
    return copied6;
}

class FUN_00acd930_cls;

int __cdecl Unk_ecd7e8(int a, int b, int c, int d);

class FUN_00acd930_cls
{
  public:
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40, m_44,
        m_48;
    int m_4c;
    FUN_00acd930_cls* FUN_00acd930(int a1, int a2);
    void Unk_acfc10(int a, int b);
};

// @fnv 0x00acd930
FUN_00acd930_cls* FUN_00acd930_cls::FUN_00acd930(int a1, int a2)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    if (m_4c == 0 || Unk_ecd7e8(m_4c, a1, (a1 == 0 && a2 == 0) ? 4 : 0, a2) != 0)
    {
        return 0;
    }
    else
    {
        Unk_acfc10(m_4c, 1);
        return this;
    }
}

int __cdecl FUN_00ecda70(void* resource);
struct ResourceOwner
{
    virtual void unusedVirtual();
    virtual int query(int index);
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    unsigned int m_unknown14;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    unsigned int m_unknown44;
    unsigned int m_unknown48;
    void* m_resource;
    int QueryResourceStatus();
};
// @fnv 0x00acd9a0
int ResourceOwner::QueryResourceStatus()
{
    int value;
    int invalid;
    return (m_resource != 0 && (value = query(-1), invalid = -1, ((unsigned char)(short)(invalid == value)) == 0) &&
            FUN_00ecda70(m_resource) < 0)
               ? -1
               : 0;
}

struct FUN_00acda10_Obj
{
    virtual void unk00();
    virtual bool unk04();
};

FUN_00acda10_Obj* __cdecl FUN_00ad4fd0(int a);

struct FUN_00acda10_Big
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
};

struct FUN_00acda10_cls
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
    FUN_00acda10_Obj* m_3c;

    void FUN_00ad0720();
    void SetObject(int a1);
};

// @fnv 0x00acda10
void FUN_00acda10_cls::SetObject(int a1)
{
    FUN_00acda10_Big big2;
    big2.unk04 = 0;
    {
        FUN_00acda10_Obj* p2 = FUN_00ad4fd0(a1);
        if (p2->unk04())
        {
            m_3c = 0;
        }
        else
        {
            m_3c = p2;
            FUN_00ad0720();
        }
    }
}

extern int DAT_010a318c;
struct FUN_00acde90_class
{
    void __thiscall FUN_00acde90();
};
// @fnv 0x00acde90
void FUN_00acde90_class::FUN_00acde90()
{
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) +
                              (*reinterpret_cast<int**>(reinterpret_cast<char*>(this) - 4))[1] - 4) = &DAT_010a318c;
}

void __cdecl FormHeap_Free(void* apMemory);

struct FUN_00acdff0_prim
{
    int unk00;
    int unk04;

    void BaseCleanup();
};

struct FUN_00acdff0_cls
{
    int unk00;
    int unk04;

    FUN_00acdff0_prim* FUN_00acdff0(unsigned int auiFlags);
};

// @fnv 0x00acdff0
FUN_00acdff0_prim* FUN_00acdff0_cls::FUN_00acdff0(unsigned int auiFlags)
{
    int iUnused1;
    int iUnused2;
    ((FUN_00acdff0_prim*)((char*)this - 8))->BaseCleanup();
    if (auiFlags & 1)
    {
        FormHeap_Free((char*)this - 8);
    }
    return (FUN_00acdff0_prim*)((char*)this - 8);
}

void __cdecl Deallocate(void*);
void __cdecl FUN_00ec3205(void*);
extern int DAT_010a2f9c;
extern int DAT_010a2fa4;

struct FUN_00acdeb0_cls
{
    void FUN_00acdeb0();
};

struct FUN_00ace260_cls
{
    void* m_vptr;

    FUN_00ace260_cls* DestroyAndFree(unsigned int acFlags);
};

// @fnv 0x00ace260
FUN_00ace260_cls* FUN_00ace260_cls::DestroyAndFree(unsigned int acFlags)
{
    unsigned int values[5];
    char* pOuter = (char*)this - 0x54;
    ((FUN_00acdeb0_cls*)(pOuter + 0x54))->FUN_00acdeb0();
    FUN_00ace260_cls* pSub = (FUN_00ace260_cls*)(pOuter + 0x54);
    pSub->m_vptr = (void*)&DAT_010a2fa4;
    pSub->m_vptr = (void*)&DAT_010a2f9c;
    FUN_00ec3205(pSub);
    if (acFlags & 1)
    {
        Deallocate((char*)this - 0x54);
    }
    return (FUN_00ace260_cls*)((char*)this - 0x54);
}

class FUN_00ace860_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual void vSlot10();
    virtual int vSlot14();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* m_20;
    int unk24;
    int unk28;
    int unk2C;
    int* m_30;

    unsigned char* DecrementAndPostIncrement();
    int FUN_00ace860();
};

// @fnv 0x00ace860
int FUN_00ace860_cls::FUN_00ace860()
{
    unsigned char* b;
    return ((*m_20 != 0 ? *m_30 : 0) > 0) ? (int)*(b = DecrementAndPostIncrement()) : vSlot14();
}

class AceHolder
{
  public:
    virtual void v00();
    virtual int vfn1(int value);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    int* m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    int* m_34;
    unsigned char* DecrementCounterAndPostIncrementOther();
    int FUN_00ace8c0(unsigned char b);
};

// If the value at m_34 (or 0 when *m_24 is 0) is positive, writes b through the pointer from DecrementCounterAndPostIncrementOther and returns it; otherwise calls vfn1(b).
// @fnv 0x00ace8c0
int AceHolder::FUN_00ace8c0(unsigned char ucValue)
{
    unsigned char* p;
    int t;
    return ((*m_24 != 0 ? *m_34 : 0) > 0) ? (p = DecrementCounterAndPostIncrementOther(), *p = ucValue, (int)*p)
                                          : vfn1((t = ucValue));
}

struct FUN_00ace930_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    int* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    int* m_30;

    int FUN_00ace930();
};

// Increments the counter at m_30 and returns the pre-decremented value of the counter at m_20.
// @fnv 0x00ace930
int FUN_00ace930_cls::FUN_00ace930()
{
    (*this->m_30)++;
    return --(*this->m_20);
}

struct FUN_00ace970_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    int* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    int* m_30;

    int DecrementAndPostIncrement();
};

// Decrements the counter pointed to by m_30 and returns the old value of the counter pointed to by m_20, incrementing it.
// @fnv 0x00ace970
int FUN_00ace970_Class::DecrementAndPostIncrement()
{
    --*m_30;
    return (*m_20)++;
}

struct FUN_00acea00_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    int* m_pCounter24;
    void* unk28;
    void* unk2c;
    void* unk30;
    int* m_pCounter34;

    int __thiscall DecrementCounterAndPostIncrementOther();
};

// Decrements the counter at m_pCounter34 and returns the old value of the counter at m_pCounter24, incrementing it.
// @fnv 0x00acea00
int FUN_00acea00_class::DecrementCounterAndPostIncrementOther()
{
    --(*m_pCounter34);
    return (*m_pCounter24)++;
}

class FUN_00aced20_pad
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
};

class FUN_00aced20_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* m_0c;
    void* m_10;
    void* m_14;
    bool FUN_00aced20(unsigned int count);
};

void FUN_00ac0b00();
void* FUN_00ad5310(unsigned int count, unsigned int flags);

// @fnv 0x00aced20
bool FUN_00aced20_cls::FUN_00aced20(unsigned int count)
{
    FUN_00aced20_pad pad;
    unsigned int maxCount;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (count == 0)
    {
        return false;
    }
    else
    {
        maxCount = 0x9249249;
        if ((maxCount > 0 ? maxCount : 1) < count)
        {
            FUN_00ac0b00();
        }
        else
        {
            m_0c = FUN_00ad5310(count, 0);
            m_10 = m_0c;
            m_14 = (char*)m_0c + count * 0x1c;
        }
    }
    return true;
}

struct S_00acfb90_Class
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
    void* unk4c;

    bool __thiscall FUN_00acfcd0();
    void __thiscall FUN_00acfc10(int param_1, int param_2);
    void* __thiscall FUN_00acfb90();
};

int __cdecl FUN_00ec9907(void*);

// @fnv 0x00acfb90
void* __thiscall S_00acfb90_Class::FUN_00acfb90()
{
    void* result = this;

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
        int unk88;
        int unk8c;
        int unk90;
        int unk94;
        int unk98;
        int unk9c;

        if (this->unk4c == 0)
        {
            result = 0;
        }
        else
        {
            if (!this->FUN_00acfcd0())
            {
                result = 0;
            }

            if (FUN_00ec9907(this->unk4c))
            {
                result = 0;
            }
        }
    }

    this->FUN_00acfc10(0, 2);
    return result;
}

namespace fnv_00ad0360 {
extern unsigned int DAT_010173f0;
void FUN_00ec30b0();

struct Flag4
{
    unsigned char flag;
    unsigned char unk01;
    unsigned short unk02;
};
struct FUN_00ad0360_cls
{
    unsigned int m_unk00;
    union
    {
        char* m_pHeap;
        char m_inline[16];
    } m_buf;
    unsigned int m_fRestLength;
    unsigned int m_pRayCursor;

    bool Probe(unsigned int idx, unsigned int zero);
    void Store(unsigned int zero, unsigned int idx, unsigned char v);
    FUN_00ad0360_cls* FUN_00ad0360(unsigned int idx, unsigned char v);
};

// @fnv 0x00ad0360
FUN_00ad0360_cls* FUN_00ad0360_cls::FUN_00ad0360(unsigned int idx, unsigned char v)
{
    unsigned int unk1, unk2, unk3, unk4, unk5, unk6;
    if (idx == DAT_010173f0)
    {
        FUN_00ec30b0();
    }
    if (Probe(idx, 0))
    {
        Store(0, idx, v);
        Flag4 pk;
        pk.flag = 0;
        m_fRestLength = idx;
        (m_pRayCursor >= 0x10 ? m_buf.m_pHeap : m_buf.m_inline)[idx] = pk.flag;
    }
    return this;
}
}  // namespace fnv_00ad0360

struct FNV_ad0470_class
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
    unsigned char unk30;
    void Initialize();
    unsigned char FUN_00ad30c0(int flags);
    void FUN_00ac9ff0(unsigned int value, int extra);
    void FUN_00ad0470(int n, bool flag);
};

void __cdecl FUN_00ec31b3(void* p);

// @fnv 0x00ad0470
void FNV_ad0470_class::FUN_00ad0470(int n, bool flag)
{
    int p[18];
    unsigned int h;
    int a[62];
    unsigned int i;
    this->Initialize();
    this->unk28 = n;
    this->unk2c = 0;
    this->unk30 = this->FUN_00ad30c0(0x20);
    if (this->unk28 == 0)
    {
        if (4)
        {
            h = this->unk08;
            i = h | 4;
            this->FUN_00ac9ff0(this->unk28 == 0 ? (i | 4) : i, 0);
        }
    }
    if (flag)
    {
        FUN_00ec31b3(this);
    }
    else
    {
        this->unk04 = 0;
    }
}

struct FUN_00ac9ff0_Class
{
    void FUN_00ac9ff0(int a, int b);
};

struct FUN_00ad0550_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    void* m_24;
    void Initialize();
};

void* __cdecl FormHeap_Allocate(unsigned int size);
int __cdecl FUN_00ec36a6();

// @fnv 0x00ad0550
void FUN_00ad0550_cls::Initialize()
{
    unsigned int pad[58];
    int e1;
    m_24 = 0;
    m_04 = 0;
    m_0c = 0;
    m_10 = 0x201;
    m_14 = 6;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    ((FUN_00ac9ff0_Class*)this)->FUN_00ac9ff0(0, 0);
    int* p = (int*)FormHeap_Allocate(4);
    m_24 = (p != 0) ? (*p = FUN_00ec36a6(), ((FUN_00ace790_class*)FUN_00ec34d4())->IncrementCounter(), (void*)p) : 0;
}

namespace fnv_00ad06e0 {
class SpawnedObject
{
  public:
    void IncrementCounter();
};

class FUN_00ad06e0_cls
{
  public:
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
    unsigned int* m_38;

    unsigned int* FUN_00ad06e0(unsigned int* out);
};

// Copies the pointer stored at m_38 into out, calls IncrementCounter on it, and returns out.
// @fnv 0x00ad06e0
unsigned int* FUN_00ad06e0_cls::FUN_00ad06e0(unsigned int* out)
{
    unsigned int flag = 0;
    unsigned int spare;
    {
        unsigned int* src = m_38;
        *out = *src;
    }
    ((SpawnedObject*)*out)->IncrementCounter();
    flag |= 1;
    return out;
}
}  // namespace fnv_00ad06e0

namespace fnv_00ad1740 {
struct ByteBox
{
    unsigned char v;
};

struct PadBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

extern "C" void __cdecl FUN_00ac3300(int a1, int a2, int a3);

class FUN_00ad1740_cls
{
  public:
    int CallAndSum(int a1, int a2, int a3);
};

// Calls FUN_00ac3300 with a1, a2 and a3, then returns a1 + a2.
// @fnv 0x00ad1740
int FUN_00ad1740_cls::CallAndSum(int a1, int aiAddend, int a3)
{
    int b = a1;
    ByteBox qq;
    ByteBox h = {};
    ByteBox a = qq;
    PadBlock nn;
    ByteBox ii = h;
    int dd = b;
    FUN_00ac3300(dd, aiAddend, a3);
    return a1 + aiAddend;
}
}  // namespace fnv_00ad1740

struct FUN_00ac9da0_Class
{
    int unk00;
    int FUN_00ac9da0(int a);
};

struct FUN_00ad1790_Node
{
    FUN_00ad1790_Node* m_pLeftChild;   // +0x00
    FUN_00ad1790_Node* m_pParent;      // +0x04
    FUN_00ad1790_Node* m_pRightChild;  // +0x08
    FUN_00ac9da0_Class m_key;          // +0x0c
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
    char unk44;
    signed char m_b45;  // +0x45
};

struct FUN_00ad1790_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00ad1790_Node* m_pHead;  // +0x18
    FUN_00ad1790_Node* FindLowerBound(int a1);
};

// @fnv 0x00ad1790
FUN_00ad1790_Node* FUN_00ad1790_Cls::FindLowerBound(int aiKey)
{
    unsigned int zq1;
    unsigned int zq2;
    unsigned int zq3;
    FUN_00ad1790_Node* cur = m_pHead->m_pParent;
    FUN_00ad1790_Node* res = m_pHead;
    while (cur->m_b45 == 0)
    {
        if ((bool)(int)(cur->m_key.FUN_00ac9da0(aiKey) < 0))
        {
            cur = cur->m_pRightChild;
        }
        else
        {
            res = cur;
            cur = cur->m_pLeftChild;
        }
    }
    return res;
}

struct Ad1800Node
{
    Ad1800Node* m_f0;
    Ad1800Node* m_f4;
    Ad1800Node* m_f8;
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
    unsigned char unk44;
    char m_b45;
};

struct Ad1800Head
{
    int unk00;
    Ad1800Node* m_f4;
};

struct FUN_00ad1800_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Ad1800Head* m_18;
    void FUN_00ad1800(Ad1800Node* p);
};

// @fnv 0x00ad1800
void FUN_00ad1800_cls::FUN_00ad1800(Ad1800Node* p)
{
    Ad1800Node* L = p->m_f8;
    p->m_f8 = L->m_f0;
    if (L->m_f0->m_b45 == 0)
    {
        L->m_f0->m_f4 = p;
    }
    L->m_f4 = p->m_f4;
    if (p == m_18->m_f4)
    {
        m_18->m_f4 = L;
    }
    else
    {
        Ad1800Node* pParent = p->m_f4;
        if (p == pParent->m_f0)
        {
            Ad1800Node* t = p->m_f4;
            t->m_f0 = L;
        }
        else
        {
            p->m_f4->m_f8 = L;
        }
    }
    L->m_f0 = p;
    p->m_f4 = L;
}

struct LinkNodeB4589
{
    LinkNodeB4589* m_pNext00;
    LinkNodeB4589* m_pPrev04;
    LinkNodeB4589* m_pNext08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned char unk44;
    signed char m_flag45;
};

class FUN_00ad18b0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    LinkNodeB4589* m_pHead18;
    void FUN_00ad18b0(LinkNodeB4589* a1);
};

// @fnv 0x00ad18b0
void FUN_00ad18b0_cls::FUN_00ad18b0(LinkNodeB4589* a1)
{
    LinkNodeB4589* x = a1->m_pNext00;
    a1->m_pNext00 = x->m_pNext08;
    if (x->m_pNext08->m_flag45 == 0)
    {
        x->m_pNext08->m_pPrev04 = a1;
    }
    x->m_pPrev04 = a1->m_pPrev04;
    if (a1 == this->m_pHead18->m_pPrev04)
    {
        this->m_pHead18->m_pPrev04 = x;
    }
    else if (a1 == a1->m_pPrev04->m_pNext08)
    {
        a1->m_pPrev04->m_pNext08 = x;
    }
    else
    {
        LinkNodeB4589* w = a1->m_pPrev04;
        w->m_pNext00 = x;
    }
    x->m_pNext08 = a1;
    a1->m_pPrev04 = x;
}

struct FUN_00ad2f30_Head
{
    unsigned int m_unk00;
    unsigned int m_dataPtr;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_length14;
    unsigned int m_capacity18;
};

class FUN_00ad2f30_cls
{
  public:
    FUN_00ad2f30_Head* m_pHead;
    unsigned int m_uiPos;
    unsigned int GetPosition();
};

// Returns m_uiPos after asserting the head pointer is valid and the position lies within the head's data range.
// @fnv 0x00ad2f30
unsigned int FUN_00ad2f30_cls::GetPosition()
{
    if ((int)m_pHead != -4)
    {
        if (!(unsigned char)((m_pHead != 0) ? 1 : 0))
        {
            FUN_00ec7c56();
        }
        FUN_00ad2f30_Head* h = m_pHead;
        if (m_uiPos >= (h->m_capacity18 >= 0x10 ? h->m_dataPtr : (unsigned int)&h->m_dataPtr) + m_pHead->m_length14)
        {
            FUN_00ec7c56();
        }
    }
    return m_uiPos;
}

class FUN_00ec3277_cls
{
  public:
    void FUN_00ec3277();
};

class FUN_00ad2fa0_sub
{
  public:
    int unk00;
    FUN_00ec3277_cls m_04;
};

class FUN_00ad2fa0_vbase
{
  public:
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
    FUN_00ad2fa0_sub* m_28;
};

class FUN_00ad2fa0_obj : public virtual FUN_00ad2fa0_vbase
{
  public:
};

class FUN_00ad2fa0_cls
{
  public:
    FUN_00ad2fa0_obj* m_00;

    FUN_00ad2fa0_cls* FUN_00ad2fa0(FUN_00ad2fa0_obj* obj);
};

// Stores obj in m_00, then if obj->m_28 is non-null calls FUN_00ec3277 on its m_04 member and returns this.
// @fnv 0x00ad2fa0
FUN_00ad2fa0_cls* FUN_00ad2fa0_cls::FUN_00ad2fa0(FUN_00ad2fa0_obj* obj)
{
    FUN_00ad2fa0_sub* value;
    FUN_00ad2fa0_sub* sub;

    m_00 = obj;
    value = m_00->m_28;
    if (value != 0)
    {
        sub = m_00->m_28;
        sub->m_04.FUN_00ec3277();
    }
    return this;
}

struct FNVSourceStringX
{
    unsigned int m_unk00;
    char* m_pData;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_uiCharacterCount;
    unsigned int m_uiCapacity;
};

struct FUN_00ad3550_cls
{
    FNVSourceStringX* m_pSource;
    char* m_pPos;
    FUN_00ad3550_cls* __thiscall InitFromSource(char* a1, FNVSourceStringX* a2);
};

// Validates that a1 lies within the source string's buffer, calls FUN_00ec7c56 otherwise, then stores the source and position.
// @fnv 0x00ad3550
FUN_00ad3550_cls* FUN_00ad3550_cls::InitFromSource(char* pPos, FNVSourceStringX* pSource)
{
    m_pSource = 0;
    if (pSource == 0 || pPos == 0 || (pSource->m_uiCapacity >= 0x10 ? pSource->m_pData : (char*)pSource + 4) > pPos ||
        pPos > (pSource->m_uiCapacity >= 0x10 ? pSource->m_pData : (char*)pSource + 4) + pSource->m_uiCharacterCount)
    {
        FUN_00ec7c56();
    }
    m_pSource = pSource;
    m_pPos = pPos;
    return this;
}

// ForwardToV07: thiscall member (3 stack args) that forwards to its own
// virtual slot 7 (vftable offset 0x1C) with four arguments, the last one
// being the difference between the second and the first argument.
struct FUN_00ad4010_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int a, int b, int c, int d);
    void ForwardToV07(int a, int b, int c);
};

// Calls the virtual v07 with a, b, c and the difference b - a.
// @fnv 0x00ad4010
void FUN_00ad4010_cls::ForwardToV07(int a, int b, int c)
{
    v07(a, b, c, b - a);
}

namespace fnv_00ad4040 {
unsigned int __cdecl FUN_00ec7c56();
void __cdecl FUN_00ec7c66(void* dst, unsigned int dstSize, const void* src, unsigned int count);

struct FUN_00ad4040_Class
{
    char* __thiscall CopyChecked(char* src, char* srcEnd, char* dst, unsigned int dstSize);
};

// Checks that dstSize covers the src..srcEnd range, copies that many bytes from src to dst, and returns srcEnd.
// @fnv 0x00ad4040
char* __thiscall FUN_00ad4040_Class::CopyChecked(char* pSrcBegin, char* srcEnd, char* dst, unsigned int dstSize)
{
    if (dstSize < (unsigned int)(srcEnd - pSrcBegin))
    {
        FUN_00ec7c56();
    }
    FUN_00ec7c66(dst, dstSize, pSrcBegin, srcEnd - pSrcBegin);
    return srcEnd;
}
}  // namespace fnv_00ad4040

struct S_00ad4090
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(char* a, char* b, unsigned char c, int d, int n);
    void CallWithRange(char* a, char* b, unsigned char c, int d);
};
// Calls v10 with the two pointers, the byte and int arguments, and the pointer difference as the fifth argument.
// @fnv 0x00ad4090
void S_00ad4090::CallWithRange(char* pcStart, char* pcEnd, unsigned char c, int d)
{
    v10(pcStart, pcEnd, c, d, pcEnd - pcStart);
}

namespace fnv_00ad5310 {
struct FUN_0044d6c0_class
{
    void* __thiscall FUN_00ec78f1(void*** a);
};

void* __cdecl FormHeap_Allocate(unsigned int size);
extern void* DAT_010176f8;

// Checks that n * 0x1c does not overflow, throws an exception if it would, and otherwise allocates n * 0x1c bytes via FormHeap_Allocate.
// @fnv 0x00ad5310
void* __cdecl FUN_00ad5310(unsigned int n)
{
    if (n <= 0)
    {
        n = 0;
    }
    else
    {
        if (0xFFFFFFFFu / n < 0x1c)
        {
            int o;
            void* obj;
            int p;
            int w;
            o = 0;
            ((FUN_0044d6c0_class*)&obj)->FUN_00ec78f1((void***)&o);
            obj = (void*)&DAT_010176f8;
            _CxxThrowException(&obj, (_ThrowInfo*)0x1140ef8);
        }
    }
    return FormHeap_Allocate(n * 0x1c);
}
}  // namespace fnv_00ad5310

struct AD5700State
{
    int m_iFadeIndex;
};

// std::codecvt<char, char, mbstate_t>::do_length
class AD5700Codecvt
{
  public:
    unsigned int ClampCountToRange(AD5700State& kState, const char* _First1, const char* _Last1,
                                   unsigned int _Count) const;
};

// Returns the smaller of _Count and the distance between _First1 and _Last1.
// @fnv 0x00ad5700
unsigned int AD5700Codecvt::ClampCountToRange(AD5700State& kState, const char* _First1, const char* _Last1,
                                              unsigned int _Count) const
{
    return _Count < (unsigned int)(_Last1 - _First1) ? _Count : _Last1 - _First1;
}

namespace fnv_00ad5dd0 {
extern "C" void __cdecl FUN_00ad66e0(int a1, int a2, int a3, int a4, unsigned char c2, unsigned char c1);
struct ByteBox
{
    unsigned char v;
};
// @fnv 0x00ad5dd0
void FUN_00ad5dd0(int a1, int a2, int a3, int a4)
{
    ByteBox c7 = {};
    ByteBox c3;
    ByteBox c8 = c3;
    int p2 = a2;
    int m = a1;
    int unk10;
    FUN_00ad66e0(m, p2, a3, a4, c8.v, c7.v);
}
}  // namespace fnv_00ad5dd0

namespace fnv_00ad6190 {
struct FUN_0044a580_cls
{
    void AssignSubstring(int a, int b, int c);
};
struct FUN_00ad6190_Frame
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
};
struct FUN_00ad6190_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_0044a580_cls m_1c;
    void AssignSubstring(int a, int b, int c);
    FUN_00ad6190_cls* FUN_00ad6190(int a);
};
extern int DAT_010173f0;
// @fnv 0x00ad6190
FUN_00ad6190_cls* FUN_00ad6190_cls::FUN_00ad6190(int a)
{
    FUN_00ad6190_Frame frame;
    this->AssignSubstring(a, 0, DAT_010173f0);
    m_1c.AssignSubstring(a + 0x1c, 0, DAT_010173f0);
    return this;
}
}  // namespace fnv_00ad6190

// The real callee is the CRT's strncpy_s at 0x00ec7ce3 in the game image.
// The name here is only a stand-in so that the call stays a plain external call.
extern "C" int __cdecl FNV_strncpy_s_standin(void* dest, unsigned int destsz, const void* src, unsigned int count);

// A one-byte class.  At /Od an empty brace initialiser zero-initialises the
// object in place, which is the "xor eax,eax" + byte store the original shows.
struct FNV_Flag1
{
    unsigned char m_kPointB;
};

// A four-byte class local: at /Od its implicit constructor is not expanded, so
// it only reserves a frame slot (the original's frame has unused 4-byte holes).
struct FNV_Flag4
{
    bool m_kPointB;
    char m_auiShapeKeys[3];
};

// @fnv 0x00ad6ab0
int FUN_00ad6ab0(void* pSource, void* pSourceEnd, void* pDest, int unused)
{
    unsigned char rg;
    unsigned char qT;
    FNV_Flag1 RunFourthVirtual = {};
    qT = rg;
    FNV_Flag4 v;
    int yz2 = (int)pSourceEnd;
    int va = (int)pSource;
    unsigned char ah = RunFourthVirtual.m_kPointB;
    void* cf = pDest;
    unsigned int gM = (unsigned int)yz2 - (unsigned int)va;
    unsigned int cF = (unsigned int)cf + gM;
    if (gM > 0)
    {
        FNV_strncpy_s_standin(cf, gM, (void*)va, gM);
    }
    return (int)cF;
}

struct BAD6B10Iterator
{
    int* m_piPtr;
};

struct BAD6B10PtrCategory
{
    char m_cKind;
};
struct BAD6B10CheckedTag
{
};

void __cdecl FUN_00ad6d30(BAD6B10Iterator kFirst, BAD6B10Iterator kLast, int* piDest, void* pvAllocator,
                          BAD6B10PtrCategory kCategory, BAD6B10CheckedTag kChecked);

// Forwards the iterator range, destination, allocator, category and checked tag to FUN_00ad6d30.
// @fnv 0x00ad6b10
void __cdecl FUN_00ad6b10(BAD6B10Iterator kFirst, BAD6B10Iterator kLast, int* piDest, void* pvAllocator)
{
    BAD6B10CheckedTag kChecked = {};
    BAD6B10PtrCategory kCategorySource4;
    BAD6B10PtrCategory kCategory = kCategorySource4;
    BAD6B10Iterator kLastBase = kLast;
    int* kDest;
    BAD6B10Iterator kFirstBase3 = kFirst;
    FUN_00ad6d30(kFirstBase3, kLastBase, piDest, pvAllocator, kCategory, kChecked);
}

// Candidate: FUN_00ad6b60
struct FlagBox
{
    unsigned char v;
};
int __cdecl FUN_00ad6e20(int a0, int a1, int a2, int a3, unsigned char f4, unsigned char f5);

// Initializes a FlagBox and forwards the four arguments plus two bytes to FUN_00ad6e20, returning its result.
// @fnv 0x00ad6b60
int __cdecl FUN_00ad6b60(int a0, int a1, int a2, int a3)
{
    FlagBox b0 = {};
    unsigned char qq;
    unsigned char cc = qq;
    int dd = a1;
    int n6 = a0;
    int n8;
    return FUN_00ad6e20(n6, dd, a2, a3, cc, b0.v);
}

// Constructor: defaults, with the enabled flag taken from its INI setting (or false when the setting is missing).

class AD6F40Setting
{
  public:
    void* m_pVtbl;
    bool m_bValue;
};

extern AD6F40Setting g_kAD6F40EnabledSetting;
extern bool g_bAD6F40DefaultEnabled;

class AD6F40List
{
  public:
    AD6F40List();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};

class FUN_00ad6f40
{
  public:
    FUN_00ad6f40();
    virtual void Unk_00();

    bool m_bModifierActive;
    bool m_bPaused;
    bool m_bEnableState;
    int m_iFadeIndex;
    bool m_bValueAt0C;
    int m_iCurrent;
    AD6F40List m_kEntries;
    int m_iValue20;
    int m_iValue24;
    int m_iValue28;
    int m_iValue2C;
    int m_iValue30;
    int m_iValue34;
};

// @fnv 0x00ad6f40
FUN_00ad6f40::FUN_00ad6f40()
{
    m_bModifierActive = false;
    bool* pbEnabled = &g_kAD6F40EnabledSetting ? &g_kAD6F40EnabledSetting.m_bValue
                                               : (g_bAD6F40DefaultEnabled = false, &g_bAD6F40DefaultEnabled);
    m_bEnableState = *pbEnabled;
    m_bPaused = false;
    m_iFadeIndex = 0;
    m_bValueAt0C = false;
    m_iValue20 = 0;
    m_iValue24 = 0;
    m_iValue28 = 0;
    m_iValue2C = 0;
    m_iValue30 = 0;
    m_iValue34 = 0;
    m_iCurrent = 0;
}

struct S_ad8700_Sub
{
    int unk00, unk04, unk08;
};
struct S_ad8700_Cb
{
    void Call();
};
struct S_ad8700
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_ad8700_Sub sub14;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void(__cdecl* unk30)();
    void FUN_00ad8700();
};
// Calls the callback stored in unk30 if set, then sets bit 0 of sub14.unk08.
// @fnv 0x00ad8700
void S_ad8700::FUN_00ad8700()
{
    if (unk30)
        unk30();
    S_ad8700_Sub* p = &sub14;
    p->unk08 |= 1;
}

namespace fnv_00acb5f0 {
extern char DAT_010a30a8;

class FUN_00acb5f0_cls
{
  public:
    void FUN_00acb5f0();
};

// @fnv 0x00acb5f0
void FUN_00acb5f0_cls::FUN_00acb5f0()
{
    *(void* volatile*)((char*)this + ((int*)(*(int**)((char*)this - 8)))[1] - 8) = (void*)&DAT_010a30a8;
}
}  // namespace fnv_00acb5f0

extern int DAT_010f1e40;
extern int DAT_01011d78;
struct SeekPosition
{
    int offset;
    __int64 filePosition;
    int state;
};
struct StringBufferSeek
{
    void* vtable;
    int lock;
    char* getFirst;
    char* putFirst;
    char** getFirstRef;
    char** putFirstRef;
    char* getNext;
    char* putNext;
    char** getNextRef;
    char** putNextRef;
    int getCount;
    int putCount;
    int* getCountRef;
    int* putCountRef;
    void* locale;
    char* seekHigh;
    SeekPosition* Seek(SeekPosition* result, int offset, int way, int which);
};
// @fnv 0x00acc1b0
SeekPosition* StringBufferSeek::Seek(SeekPosition* result, int offset, int way, int which)
{
    int offset9;     // write move
    char* kBx;       // write next move
    char* kAx;       // write read base move
    char* gyX;       // write read base limit
    char* gyB;       // write read base current
    char* gy6;       // write next current
    char* aGy;       // write read base end
    char* kJ;        // write selected
    char* kU;        // write base
    char* kV1;       // read sync
    char* aMaximum;  // write end
    char* found;     // write present
    int offset8;     // read move
    char* origin_2;  // read next move
    char* akStart;   // read base move
    char* kMinimum;  // read base limit
    char* posB;      // read base current
    char* pos6;      // read next current
    char* first;     // read base end
    char* pos2;      // read current
    char* next8;     // new high
    char* next6;     // write high
    char* current;   // write current
    if ((current = *putNextRef) != 0 && seekHigh < (next6 = *putNextRef))
        seekHigh = (next8 = *putNextRef);
    if (which & 1 && (pos2 = *getNextRef) != 0)
    {
        if (way == 2)
            offset += int(seekHigh - (first = *getFirstRef));
        else if (way == 1 && (which & 2) == 0)
        {
            pos6 = *getNextRef;
            posB = *getFirstRef;
            offset += int(pos6 - posB);
        }
        else if (way != 0)
            offset = DAT_010f1e40;
        if (0 <= offset && offset <= seekHigh - (kMinimum = *getFirstRef))
        {
            akStart = *getFirstRef;
            origin_2 = *getNextRef;
            offset8 = int(akStart - origin_2 + offset);
            *getCountRef -= offset8;
            *getNextRef += offset8;
            if (which & 2 && (found = *putNextRef) != 0)
            {
                aMaximum = *putNextRef + *putCountRef;
                kV1 = *getNextRef;
                kU = *putFirstRef;
                *putFirstRef = kU;
                *putNextRef = kV1;
                *putCountRef = int(aMaximum - kV1);
            }
        }
        else
            offset = DAT_010f1e40;
    }
    else if (which & 2 && (kJ = *putNextRef) != 0)
    {
        if (way == 2)
            offset += int(seekHigh - (aGy = *getFirstRef));
        else if (way == 1)
        {
            gy6 = *putNextRef;
            gyB = *getFirstRef;
            offset += int(gy6 - gyB);
        }
        else if (way != 0)
            offset = DAT_010f1e40;
        if (0 <= offset && offset <= seekHigh - (gyX = *getFirstRef))
        {
            kAx = *getFirstRef;
            kBx = *putNextRef;
            offset9 = int(kAx - kBx + offset);
            *putCountRef -= offset9;
            *putNextRef += offset9;
        }
        else
            offset = DAT_010f1e40;
    }
    else
        offset = DAT_010f1e40;
    result->offset = offset;
    result->filePosition = 0;
    result->state = DAT_01011d78;
    return result;
}

extern const long _BADOFF;
extern const int _Stinit;

struct StreamPos
{
    long _Myoff;
    __int64 _Fpos;
    int _Mystate;
};

class StringBuf
{
  public:
    void* _Vtable;
    void* _Mylock;
    char* _Gfirst;
    char* _Pfirst;
    char** _IGfirst;
    char** _IPfirst;
    char* _Gnext;
    char* _Pnext;
    char** _IGnext;
    char** _IPnext;
    int _Gcount;
    int _Pcount;
    int* _IGcount;
    int* _IPcount;
    void* _Plocale;
    char* _Seekhigh;

    StreamPos* FUN_00acc490(StreamPos* _Result, StreamPos _Ptr, int _Mode);
};

// Seeks the string buffer to the given offset for the requested mode, updating the get and put pointers and counts, and returns the resulting position.
// @fnv 0x00acc490
StreamPos* StringBuf::FUN_00acc490(StreamPos* _Result, StreamPos _Ptr, int _Mode)
{
    int iPBumpB;
    char* pNext7;
    char* pBack4;
    char* pBack_2;
    char* pNext4;
    char* pFirst4;
    char* pPutNext4;
    char* pLast4;
    char* pNextX;
    int iGBumpTmp;
    char* pGetTmp;
    char* pBack;
    char* pFirst7;
    char* aPGet2;
    char* pCmp6;
    char* pCmp_;
    char* pLast8;
    long offsetA;

    offsetA = (long)_Ptr._Fpos + _Ptr._Myoff;

    pLast8 = *_IPnext;
    if (pLast8 != 0)
    {
        pCmp_ = *_IPnext;
        if (_Seekhigh < pCmp_)
        {
            pCmp6 = *_IPnext;
            _Seekhigh = pCmp6;
        }
    }

    if (offsetA == _BADOFF)
        ;
    else if ((_Mode & 1) && (aPGet2 = *_IGnext) != 0)
    {
        if (0 <= offsetA && offsetA <= _Seekhigh - (pFirst7 = *_IGfirst))
        {
            pBack = *_IGfirst;
            pGetTmp = *_IGnext;
            iGBumpTmp = pBack - pGetTmp + offsetA;
            *_IGcount -= iGBumpTmp;
            *_IGnext += iGBumpTmp;
            if ((_Mode & 2) && (pNextX = *_IPnext) != 0)
            {
                pLast4 = *_IPnext + *_IPcount;
                pPutNext4 = *_IGnext;
                pFirst4 = *_IPfirst;
                *_IPfirst = pFirst4;
                *_IPnext = pPutNext4;
                *_IPcount = pLast4 - pPutNext4;
            }
        }
        else
            offsetA = _BADOFF;
    }
    else if ((_Mode & 2) && (pNext4 = *_IPnext) != 0)
    {
        if (0 <= offsetA && offsetA <= _Seekhigh - (pBack_2 = *_IGfirst))
        {
            pBack4 = *_IGfirst;
            pNext7 = *_IPnext;
            iPBumpB = pBack4 - pNext7 + offsetA;
            *_IPcount -= iPBumpB;
            *_IPnext += iPBumpB;
        }
        else
            offsetA = _BADOFF;
    }
    else
        offsetA = _BADOFF;

    _Result->_Myoff = offsetA;
    _Result->_Fpos = 0;
    _Result->_Mystate = _Stinit;
    return _Result;
}

unsigned int __cdecl FUN_00ec7c56();
extern "C" int __cdecl FUN_00ec7c66(void* dst, unsigned int dstSize, const void* src, unsigned int count);

struct FNVCheckedBytes
{
    char* FUN_00ad40d0(char* pBegin, char* pEnd, unsigned char m_ucType, void* pDest, unsigned int uiDestSize);
};

// @fnv 0x00ad40d0
char* FNVCheckedBytes::FUN_00ad40d0(char* pBegin, char* pEnd, unsigned char m_ucType, void* pDest,
                                    unsigned int uiDestSize)
{
    if (uiDestSize < (unsigned int)(pEnd - pBegin))
        FUN_00ec7c56();
    FUN_00ec7c66(pDest, uiDestSize, pBegin, (unsigned int)(pEnd - pBegin));
    return pEnd;
}

struct Rec12Copy
{
    unsigned int x, y, z;
};
struct CopyTagE
{
    char v;
};
// Copies the 12-byte records in [first,last) to dest backwards, returning the start of the copied range.
// @fnv 0x00ac1a50
Rec12Copy* __cdecl CopyRangeBackward(Rec12Copy* first, Rec12Copy* last, Rec12Copy* dest)
{
    CopyTagE tagC = {};
    CopyTagE tagA;
    CopyTagE tagB = tagA;
    {
        {
            CopyTagE tagH = tagC;
        }
        Rec12Copy* firstCopy = dest;
        Rec12Copy* result = first;
        Rec12Copy* cur = (Rec12Copy*)((char*)firstCopy - ((char*)last - (char*)result) / 12 * 12);
        CopyTagE tagF = {};
        CopyTagE tagE = {};
        CopyTagE c = tagF;
        CopyTagE tagD = tagE;
        Rec12Copy* d = firstCopy;
        Rec12Copy* destArg = last;
        while (result != destArg)
        {
            --destArg;
            --d;
            *d = *destArg;
        }
        return cur;
    }
}

extern "C" void __cdecl FUN_00ac34c0(void* item, void* arg);

class SpawnCallee_cls
{
  public:
    void Probe(int a, int b);
    void Release(void* item);
};

extern SpawnCallee_cls g_ac2370Owner;

struct Scratch_cls
{
    unsigned int a[20];
};
struct SpawnItem_cls
{
    unsigned int u[8];
};

// @fnv 0x00ac2370
void FUN_00ac2370(SpawnItem_cls* apItems, unsigned int count, void* arg)
{
    Scratch_cls scratch;
    SpawnItem_cls* cur = apItems;
    try
    {
        for (; count > 0; count--, apItems++)
        {
            FUN_00ac34c0(apItems, arg);
        }
    }
    catch (...)
    {
        for (; cur != apItems; cur++)
        {
            if ((((SpawnCallee_cls*)((char*)cur + 4))->Probe(1, 0), 1u) & 0u)
            {
                g_ac2370Owner.Release(cur);
            }
        }
        throw;
    }
}

struct AC27Record
{
    unsigned int x, y, z;
};
struct AC27Tag
{
    unsigned char value;
};
struct AC27Zero
{
};
AC27Record* __cdecl FUN_00ac1170(AC27Record*, AC27Record*, AC27Record*);
AC27Record* __cdecl CopyRecords(AC27Record*, AC27Record*, AC27Record*, AC27Tag, AC27Tag, AC27Zero);
AC27Record* __cdecl FUN_00ac3370(AC27Record*, AC27Record*, AC27Record*, void*, AC27Tag, AC27Zero);
struct AC27Pool
{
    void FUN_00aa4060(void*);
};
struct AC27Root
{
    int u38, u34, u30, u2c, u28, u24, u20, u1c, u18, u14, u10, uc;
    AC27Record *p8, *p4;
};
struct AC27Copy
{
    AC27Record *p70, *p6c, *p68, *p64;
    AC27Tag u60, u5f, b5e, b5d;
    AC27Record *p5c, *p58, *p54, *p50;
    int u4c;
    AC27Record* p48;
    int u44;
};
struct AC27Pad32
{
    short a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
};
struct AC27Append
{
    AC27Record *pbc, *pb8, *pb4, *pb0, *pac, *pa8;
    int ua4;
    AC27Record* pa0;
};
struct AC27Destroy
{
    unsigned int ndc;
    AC27Record *pd8, *pd4, *pd0, *pcc, *pc8, *pc4;
};
struct AC27Pad104
{
    int u148, u144, u140, u13c, u138, u134, u130, u12c, u128, u124, u120, u11c;
    int u118, u114, u110, u10c, u108, u104, u100, ufc, uf8, uf4, uf0, uec, ue8, ue4;
};
struct AC27Allocate
{
    AC27Record *p170, *p16c, *p168, *p164, *p160, *p15c, *p158;
    int u154;
    AC27Record* p150;
};
struct AC27Vector
{
    unsigned int unknown0, unknown4, allocator;
    AC27Record *first, *last, *limit;
    void FUN_00ab9cd0();
    unsigned char ReserveItems(unsigned int);
    AC27Vector& Assign(const AC27Vector&);
};
// Copy-assigns right into this vector, reusing existing storage when it fits and otherwise reallocating or destroying the old buffer.
// @fnv 0x00ac27c0
AC27Vector& AC27Vector::Assign(const AC27Vector& right)
{
    AC27Root r;
    if (this != &right)
    {
        if (right.last - right.first == 0)
        {
            FUN_00ab9cd0();
        }
        else
        {
            unsigned int uiRightCount = right.last - right.first;
            if (uiRightCount <= (unsigned int)(last - first))
            {
                AC27Copy AA;
                AC27Tag A6, D7, DA;
                AA.p5c = first;
                AA.p58 = right.last;
                AA.p54 = right.first;
                AC27Zero DT = {};
                DA = A6;
                AA.p48 = AA.p58;
                AA.p50 = AA.p54;
                r.p4 = CopyRecords(AA.p50, AA.p48, AA.p5c, D7, DA, DT);
                AA.p70 = last;
                AA.p6c = AA.p70;
                AA.p68 = r.p4;
                AA.b5d = AA.b5e;
                AA.p64 = AA.p68;
                for (; AA.p64 != AA.p6c; ++AA.p64)
                {
                }
                last = first + (right.last - right.first);
            }
            else
            {
                unsigned int n74 = right.last - right.first;
                if (n74 <= (unsigned int)(first == 0 ? 0 : limit - first))
                {
                    AC27Pad32 A9;
                    AC27Tag A5, B4;
                    AC27Append AA;
                    AC27Tag D7, DA;
                    r.p8 = right.first + (last - first);
                    FUN_00ac1170(right.first, r.p8, first);
                    AA.pbc = last;
                    AA.pb8 = right.last;
                    AA.pb4 = AA.pbc;
                    AA.pb0 = AA.pb8;
                    AA.pac = r.p8;
                    AC27Zero DT = {};
                    DA = D7;
                    AA.pa0 = AA.pb0;
                    AA.pa8 = AA.pac;
                    last = FUN_00ac3370(AA.pa8, AA.pa0, AA.pb4, &allocator, DA, DT);
                }
                else
                {
                    if (first != 0)
                    {
                        AC27Destroy AA;
                        AC27Tag D7, DA;
                        AA.pd4 = last;
                        AA.pd0 = first;
                        AA.pcc = AA.pd4;
                        AA.pc8 = AA.pd0;
                        DA = D7;
                        AA.pc4 = AA.pc8;
                        for (; AA.pc4 != AA.pcc; ++AA.pc4)
                        {
                        }
                        AA.ndc = limit - first;
                        AA.pd8 = first;
                        ((AC27Pool*)&DAT_011f6238)->FUN_00aa4060(AA.pd8);
                    }
                    {
                        unsigned int uiNewCount = right.last - right.first;
                        if (ReserveItems(uiNewCount))
                        {
                            AC27Pad104 A9;
                            AC27Allocate AA;
                            AC27Tag D7, DA;
                            AA.p170 = first;
                            AA.p16c = right.last;
                            AA.p168 = right.first;
                            AA.p164 = AA.p170;
                            AA.p160 = AA.p16c;
                            AA.p15c = AA.p168;
                            AC27Zero DT = {};
                            DA = D7;
                            AA.p150 = AA.p160;
                            AA.p158 = AA.p15c;
                            last = FUN_00ac3370(AA.p158, AA.p150, AA.p164, &allocator, DA, DT);
                        }
                    }
                }
            }
        }
    }
    return *this;
}

struct CopyElem12
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
};

// Copies CopyElem12 elements from the range [src, srcEnd) into dst, returning the end of the destination range.
// @fnv 0x00ac3370
CopyElem12* __cdecl FUN_00ac3370(CopyElem12* src, CopyElem12* srcEnd, CopyElem12* dst)
{
    CopyElem12* begin = dst;
    try
    {
        for (; src != srcEnd; dst = dst + 1, src = src + 1)
        {
            CopyElem12* kP = dst;
            CopyElem12* q = kP;
            CopyElem12* res4;
            if (q != 0)
            {
                *q = *src;
                res4 = q;
            }
            else
            {
                res4 = 0;
            }
        }
    }
    catch (...)
    {
        for (; begin != dst; begin = begin + 1)
        {
        }
        throw;
    }
    return dst;
}

struct FUN_00acbae0_Value
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned __int64 m_08;
    unsigned int m_10;
};
class FUN_00acbae0_cls
{
  public:
    FUN_00acbae0_Value* __thiscall InitValue(FUN_00acbae0_Value* out, unsigned int a2, unsigned int a3,
                                             unsigned int a4);
};
// Fills the output struct with DAT_010f1e40, zeroes m_08, and stores DAT_01011d78 in m_10.
// @fnv 0x00acbae0
FUN_00acbae0_Value* FUN_00acbae0_cls::InitValue(FUN_00acbae0_Value* out, unsigned int a2, unsigned int a3,
                                                unsigned int a4)
{
    unsigned int value = DAT_010f1e40;
    out->m_00 = value;
    out->m_08 = 0;
    out->m_10 = DAT_01011d78;
    return out;
}

struct FUN_00acd060_buf
{
    volatile unsigned int m_cursor;
};

struct FUN_00acd060_cls
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02(int value);
    virtual void vfn03();
    virtual void vfn04();
    virtual int vfn05();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    FUN_00acd060_buf* m_pReferencedObject;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int* m_pReadData;

    int ReadByte();
};

// @fnv 0x00acd060
int FUN_00acd060_cls::ReadByte()
{
    unsigned int q2 = m_pReferencedObject->m_cursor;
    unsigned int q1;
    int res;
    int m1;

    if ((q2 != 0) && ((q1 = m_pReferencedObject->m_cursor) < *m_pReadData + m_pReferencedObject->m_cursor))
    {
        unsigned int RunFourthVirtual = m_pReferencedObject->m_cursor;
        return *(unsigned char*)RunFourthVirtual;
    }
    else
    {
        res = vfn05();
        m1 = -1;
        if ((unsigned char)(unsigned short)(m1 == res))
        {
            return res;
        }
        else
        {
            vfn02(res);
            return res;
        }
    }
}

extern int DAT_010a318c;
extern int DAT_010a2fa4;
extern int DAT_010a2f9c;
void __cdecl FUN_00ec3205(void* component);
struct FUN_00ace2d0_Class
{
    int* virtualBaseOffsets;
    void* componentVTable;
    void InitializeVirtualBase();
};
// @fnv 0x00ace2d0
void FUN_00ace2d0_Class::InitializeVirtualBase()
{
    char* subobject;
    char* virtualBaseObject;
    virtualBaseObject = reinterpret_cast<char*>(this) + 4;
    *reinterpret_cast<void**>(virtualBaseObject + (*reinterpret_cast<int**>(virtualBaseObject - 4))[1] - 4) =
        &DAT_010a318c;
    subobject = reinterpret_cast<char*>(this) + 4;
    *reinterpret_cast<void**>(subobject) = &DAT_010a2fa4;
    *reinterpret_cast<void**>(subobject) = &DAT_010a2f9c;
    FUN_00ec3205(subobject);
}

struct FUN_00ad5430_err
{
    void* m_vptr;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00ec78f1(unsigned int* out);
};
extern "C" char DAT_010176f8[];
extern "C" char DAT_01140ef8[];
extern "C" void __stdcall FUN_00ec7894(void* err2, const char* msg);
void* __cdecl FormHeap_Allocate(unsigned int size);

// Clamps count to zero, reports an error if count*0x18 would overflow, then allocates count*0x18 bytes and returns the pointer.
// @fnv 0x00ad5430
void* __cdecl AllocateCountedBlocks(unsigned int count)
{
    FUN_00ad5430_err err3;
    unsigned int zero;

    if (count <= 0)
    {
        count = 0;
    }
    else if (0xFFFFFFFFu / count < 0x18)
    {
        zero = 0;
        err3.FUN_00ec78f1(&zero);
        err3.m_vptr = DAT_010176f8;
        FUN_00ec7894(&err3, DAT_01140ef8);
    }
    return FormHeap_Allocate(count * 0x18);
}

struct ByteFlag
{
    char v;
};

struct String28
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    void AssignSubstring(const String28& src, int off, int count);
};

struct Elem34
{
    String28 text;
    AC27Vector items;
};

// Copies text and items of each element in [first, last) into dest, and returns dest + (last - first).
// @fnv 0x00ac18c0
Elem34* __cdecl FUN_00ac18c0(Elem34* first, Elem34* last, Elem34* dest)
{
    Elem34* center = dest + (last - first);
    ByteFlag alpha = {};
    ByteFlag begin = {};
    int above;
    int acc;
    int accuracy;
    int acoustic;
    int act;
    int action;
    int active;
    int actor;
    int actors;
    int actual;
    int added;
    int adjacent;
    int advance;
    int after;
    int again;
    int age;
    int aim;
    int alarm;
    int alignment;
    int allocated;
    int allocation;
    int allowed;
    int alternate;
    int amount;
    int amt;
    int ancestor;
    int angle;
    int angles;
    int angular;
    int anim;
    int anims;
    int arc;
    int arg;
    int arr;
    int arrived;
    int assigned;
    int attach;
    int attached;
    int attacked;
    int attempt;
    int attempts;
    int attr;
    int attribute;
    int audio;
    int aval;
    int avoid;
    int avoidance;
    int away;
    int axisx;
    int axisy;
    int axisz;
    int backup;
    int band;
    int bar;
    int base;
    int basis;
    int below;
    int best;
    int bip;
    int bits;
    int blk;
    int blocked;
    int blok;
    int body;
    int bonus;
    int bookmark;
    int bound;
    int bounds;
    int breaks;
    int brightness;
    int buf;
    int buff;
    int builder;
    int built;
    int button;
    int bytes;
    int cached;
    int candidates;
    int capacity;
    int caster;
    int cat;
    int category;
    int challenge;
    int change;
    int changes;
    int character;
    int child;
    int chosen;
    int chunk;
    int cid;
    int ckey;
    int clear;
    int close;
    ByteFlag ammo;
    ByteFlag badge;
    ammo = alpha;
    badge = begin;
    Elem34* blend = dest;
    Elem34* armor = first;
    for (; armor != last; blend = blend + 1, armor = armor + 1)
    {
        blend->text.AssignSubstring(armor->text, 0, DAT_010173f0);
        blend->items.Assign(armor->items);
    }
    return center;
}

void FUN_00ac3170(int, int, int, unsigned char, unsigned char, unsigned char);
struct Tag
{
    unsigned char v;
};

// Forwards a1-a4 to FUN_00ac3170 along with an uninitialized byte and a zeroed Tag byte.
// @fnv 0x00ac1f60
void FUN_00ac1f60(int a1, int a2, int a3, unsigned char a4)
{
    Tag t_ = {};
    unsigned char c3;
    unsigned char c7 = c3;
    char pad[284];
    FUN_00ac3170(a1, a2, a3, a4, c7, t_.v);
}

namespace fnv_00ac2020 {
void FUN_00ac3230(int, int, int, unsigned char, unsigned char, unsigned char);
struct Tag
{
    unsigned char v;
};

// Forwards a1-a4 to FUN_00ac3230 along with an uninitialized byte and a zeroed Tag byte.
// @fnv 0x00ac2020
void FUN_00ac2020(int a1, int a2, int a3, unsigned char a4)
{
    Tag t_ = {};
    unsigned char c3;
    unsigned char c7 = c3;
    char pad[276];
    FUN_00ac3230(a1, a2, a3, a4, c7, t_.v);
}
}  // namespace fnv_00ac2020

struct Iter_ac3230
{
    short h;
    FlagBox x1;
    FlagBox x2;
    FUN_00ac2760_cls* dst;
    FUN_00ac2760_cls* cur;
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
};
// Copies the 56-byte elements in [a, b) backward into the range ending at c, and returns the start address of the destination range.
// @fnv 0x00ac3230
extern "C" int __cdecl FUN_00ac3230(int aiSrcStart, int aiSrcEnd, int c)
{
    int w = c - ((aiSrcEnd - aiSrcStart) / 56) * 56;
    FlagBox f2 = {};
    FlagBox f1 = {};
    {
        Iter_ac3230 it;
        it.x1 = f2;
        it.x2 = f1;
        it.dst = (FUN_00ac2760_cls*)c;
        it.cur = (FUN_00ac2760_cls*)aiSrcEnd;
        while (aiSrcStart != (int)it.cur)
        {
            it.cur = (FUN_00ac2760_cls*)((char*)it.cur - 56);
            it.dst = (FUN_00ac2760_cls*)((char*)it.dst - 56);
            it.dst->AssignSubstring((int)it.cur, 0, DAT_010173f0);
            it.dst->m_1c = it.cur->m_1c;
            it.dst->m_20.FUN_00ac2ca0((int)&it.cur->m_20);
        }
    }
    return w;
}

namespace fnv_00ac3450 {
struct ByteFlag
{
    bool enabled;
};
// Stores the int at *source into each of count consecutive ints starting at dest.
// @fnv 0x00ac3450
void __cdecl FUN_00ac3450(int* dest, unsigned int count, int* source)
{
    int* pDest;
    ByteFlag current = {};
    char tag3;
    bool remaining = current.enabled;
    char tag1 = tag3;
    int* value1 = dest;
    pDest = value1 + count;
    ByteFlag value3 = {};
    bool uninitialized = value3.enabled;
    unsigned int tag2 = count;
    int* pEnd = value1;
    for (; tag2 > 0; --tag2, ++pEnd)
    {
        *pEnd = *source;
    }
}
}  // namespace fnv_00ac3450

struct CopyItem16
{
    unsigned int m_dw0;
    unsigned int m_dw1;
    unsigned int m_dw2;
    unsigned int m_dw3;
    CopyItem16()
    {}
    CopyItem16(const CopyItem16& other)
    {
        m_dw0 = other.m_dw0;
        m_dw1 = other.m_dw1;
        m_dw2 = other.m_dw2;
        m_dw3 = other.m_dw3;
    }
    ~CopyItem16()
    {}
};

// Copies CopyItem16 elements from [first, last) to dest and returns the end of the destination; the catch path only rethrows.
// @fnv 0x00ac3820
CopyItem16* __cdecl FUN_00ac3820(CopyItem16* first, CopyItem16* last, CopyItem16* dest)
{
    CopyItem16* pDestStart = dest;
    try
    {
        for (; first != last; dest++, first++)
        {
            CopyItem16* pDest = dest;
            CopyItem16* objVal = pDest;
            CopyItem16* res3;
            if (objVal != 0)
            {
                *objVal = *first;
                res3 = objVal;
            }
            else
            {
                res3 = 0;
            }
        }
    }
    catch (...)
    {
        for (; pDestStart != dest; ++pDestStart)
        {
        }
        throw;
    }
    return dest;
}

struct S00aca220_Sub
{
    void FUN_0044a730(int, int);
};
struct S00aca220_Base
{
    void FUN_00ec79a1();
};
void FormHeap_Free(void* p);
extern char DAT_010a307c;
struct S00aca220_Obj : public S00aca220_Base
{
    char* m_pVft;
    int m_iWordAt04;
    int m_8;
    S00aca220_Sub m_sub;
    S00aca220_Obj* FUN_00aca220(int flags);
};
// Sets m_pVft, calls m_sub.FUN_0044a730(1, 0) and FUN_00ec79a1, and calls FormHeap_Free(this) when bit 0 of flags is set; returns this.
// @fnv 0x00aca220
S00aca220_Obj* S00aca220_Obj::FUN_00aca220(int flags)
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    m_pVft = &DAT_010a307c;
    m_sub.FUN_0044a730(1, 0);
    FUN_00ec79a1();
    if (flags & 1)
        FormHeap_Free(this);
    return this;
}

namespace fnv_00aca300 {
extern int DAT_010a3070;
extern int DAT_010a307c;
struct StringLike
{
    void Clear(bool, unsigned int);
};
struct FUN_0044d6f0_This
{
    void FUN_00ec79a1();
};
struct PoolSpawn
{
    void* m_vft;
    void* m_p0;
    void* m_p4;
    void* m_p8;
    char m_iThirdValue;
    StringLike m_str;
    void FUN_00aca300();
};
// Sets m_vft to DAT_010a3070 then DAT_010a307c, calls Clear(true, 0) on the string at this+0xc, then calls FUN_00ec79a1 on this.
// @fnv 0x00aca300
void PoolSpawn::FUN_00aca300()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    m_vft = (void*)&DAT_010a3070;
    m_vft = (void*)&DAT_010a307c;
    ((StringLike*)((char*)this + 0xc))->Clear(true, 0);
    ((FUN_0044d6f0_This*)this)->FUN_00ec79a1();
}
}  // namespace fnv_00aca300

struct S00aca340_Str
{
    void Clear(bool, unsigned int);
};
struct S00aca340_Base
{
    void FUN_00ec79a1();
};
void FormHeap_Free(void* p);
extern char DAT_010a3070;
extern char DAT_010a307c;
struct S00aca340_Obj : public S00aca340_Base
{
    void* m_vft;
    void* m_iWordAt04;
    void* m_8;
    S00aca340_Str m_str;
    S00aca340_Obj* FUN_00aca340(int a);
};
// Sets m_vft, clears m_str, calls FUN_00ec79a1, and calls FormHeap_Free(this) when bit 0 of a is set; returns this.
// @fnv 0x00aca340
S00aca340_Obj* S00aca340_Obj::FUN_00aca340(int aiFlags)
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    m_vft = &DAT_010a3070;
    m_vft = &DAT_010a307c;
    m_str.Clear(true, 0);
    FUN_00ec79a1();
    if (aiFlags & 1)
        FormHeap_Free(this);
    return this;
}

struct FUN_00aca270
{
    virtual ~FUN_00aca270();
    FUN_00aca270(void* p);
};

struct FUN_00aca390 : FUN_00aca270
{
    FUN_00aca390(void* p);
    virtual ~FUN_00aca390();
};

// Constructs the FUN_00aca270 base with p; the body only declares an unused 84-byte local.
// @fnv 0x00aca390
FUN_00aca390::FUN_00aca390(void* p) : FUN_00aca270(p)
{
    char pad[84];
}

struct FUN_00aca780_class : public FUN_00aca9a0_class
{
    void FUN_00aca780();
};

// @fnv 0x00aca780
void FUN_00aca780_class::FUN_00aca780()
{
    int a;
    int b;
    FUN_00aca9a0();
}

extern int DAT_010f1e40;
extern int DAT_01011d78;

struct Acbb20Value
{
    unsigned int m00;
    unsigned int m04;
    unsigned __int64 m08;
    unsigned int m10;
};

class Acbb20Cls
{
  public:
    Acbb20Value* FUN_00acbb20(Acbb20Value* out, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5,
                              unsigned int a6, unsigned int a7, unsigned int a8);
};

// Sets out->m00 from DAT_010f1e40, m08 to 0 and m10 from DAT_01011d78, ignoring the other arguments, and returns out.
// @fnv 0x00acbb20
Acbb20Value* Acbb20Cls::FUN_00acbb20(Acbb20Value* out, unsigned int, unsigned int, unsigned int, unsigned int,
                                     unsigned int, unsigned int, unsigned int)
{
    int v = DAT_010f1e40;
    out->m00 = v;
    out->m08 = 0;
    out->m10 = DAT_01011d78;
    return out;
}

struct Ace750Slot
{
    FUN_00ace790_class** entry;
    int scratch;
};

struct Ace750Self
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
    FUN_00ace790_class** unk24;
    FUN_00ace790_class** FUN_00ace750(FUN_00ace790_class** p);
};

// Copies the first entry from unk24 into p, increments its counter, and returns p.
// @fnv 0x00ace750
FUN_00ace790_class** Ace750Self::FUN_00ace750(FUN_00ace790_class** apOutEntry)
{
    int x = 0;
    Ace750Slot slot;
    slot.entry = unk24;
    *apOutEntry = *slot.entry;
    (*apOutEntry)->IncrementCounter();
    x |= 1;
    return apOutEntry;
}

struct S00acede0_Elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    void FUN_0044a730(int a, int b);
};

struct S00acede0_Obj
{
    int m_00;
    int m_04;
    int m_08;
    S00acede0_Elem* m_0c;
    S00acede0_Elem* m_10;
    S00acede0_Elem* m_14;
    void FUN_00acede0();
};

// If m_0c is set, calls FUN_0044a730(1, 0) on each element from m_0c to m_10, frees the m_0c block with FormHeap_Free, then zeroes m_0c, m_10 and m_14.
// @fnv 0x00acede0
void S00acede0_Obj::FUN_00acede0()
{
    int h;
    int text;
    int v;
    int hits5;
    int h2;
    S00acede0_Elem* ups2;
    S00acede0_Elem* p2;
    S00acede0_Elem* zeta;
    S00acede0_Elem* gg3;
    char p;
    char w;
    S00acede0_Elem* theta4;
    S00acede0_Elem* hhX;
    int p5;
    S00acede0_Elem* p6;
    if (m_0c != 0)
    {
        ups2 = m_10;
        p2 = m_0c;
        zeta = ups2;
        gg3 = p2;
        w = p;
        theta4 = zeta;
        hhX = gg3;
        for (; hhX != theta4; hhX = hhX + 1)
        {
            if (1 & (hhX->FUN_0044a730(1, 0), 0))
                FormHeap_Free(hhX);
        }
        p5 = m_14 - m_0c;
        p6 = m_0c;
        FormHeap_Free(p6);
    }
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
}

extern int DAT_011f6d8c;

// C stdio FILE, the fields basic_filebuf::_Init points into.
struct CStream
{
    char* ptr;
    int cnt;
    char* base;
};

// basic_filebuf<char> tail. _State is mbstate_t (int); _Closef is bool so
// `_Closef = (_Which == _Openfl)` zero-extends with xor/sete.
struct FileBufFields
{
    int vptr;
    int mylock;
    int gfirst;
    int pfirst;
    int igfirst;
    int ipfirst;
    int gnext;
    int m_pActionSuccessor;
    int ignext;
    int ipnext;
    int gcount;
    int pcount;
    int igcount;
    int ipcount;
    int plocale;
    int pcvt;
    char mychar;
    char wrotesome;
    int state;
    bool closef;
    void* myfile;
};

enum FileInitKind
{
    FileNew = 0,
    FileOpen = 1,
    FileClose = 2
};

// Initializes the file buffer state, sets closef based on whether param_2 is FileOpen, and wires up CStream pointers when param_1 is non-null.
// @fnv 0x00acfc10
void __thiscall S_00acfb90_Class::FUN_00acfc10(int apStream, int aiInitKind)
{
    int t3;
    int t1;
    int t0;
    int t2;

    ((FileBufFields*)this)->closef = ((FileInitKind)aiInitKind == FileOpen);
    ((FileBufFields*)this)->wrotesome = false;

    reinterpret_cast<FUN_00acda10_cls*>(this)->FUN_00ad0720();

    if (apStream != 0 && sizeof(char) == 1)
    {
        t3 = (int)&((CStream*)apStream)->base;
        t1 = (int)&((CStream*)apStream)->ptr;
        t0 = (int)&((CStream*)apStream)->cnt;
        t2 = (int)&((CStream*)apStream)->cnt;

        ((FileBufFields*)this)->igfirst = t3;
        ((FileBufFields*)this)->ipfirst = t3;
        ((FileBufFields*)this)->ignext = t1;
        ((FileBufFields*)this)->ipnext = t1;
        ((FileBufFields*)this)->igcount = t0;
        ((FileBufFields*)this)->ipcount = t2;
    }

    ((FileBufFields*)this)->myfile = (void*)apStream;
    ((FileBufFields*)this)->state = DAT_011f6d8c;
    ((FileBufFields*)this)->pcvt = 0;
}

namespace fnv_00ad6000 {
void FUN_00ad6800(int, int, int, unsigned char, unsigned char, unsigned char);
struct Tag
{
    unsigned char v;
};

// @fnv 0x00ad6000
void FUN_00ad6000(int a1, int a2, int a3, unsigned char a4)
{
    Tag t_ = {};
    unsigned char c3;
    unsigned char c7 = c3;
    char pad[148];
    FUN_00ad6800(a1, a2, a3, a4, c7, t_.v);
}
}  // namespace fnv_00ad6000

extern int DAT_010173f0;

struct Str_00ac1600
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int m6;
    void Set(const Str_00ac1600* pkOther, int iZero, int iGlobal);
};

struct Vec3_00ac1600
{
    int x;
    int y;
    int z;
};

struct Rec_00ac1600
{
    int f0;
    Vec3_00ac1600 v;
    Str_00ac1600 s;
};

// Copies f0, v, and s from src into every Rec_00ac1600 element from begin up to end.
// @fnv 0x00ac1600
void __cdecl FUN_00ac1600(Rec_00ac1600* begin, Rec_00ac1600* end, const Rec_00ac1600* src)
{
    int unkA;
    {
        Rec_00ac1600* last = end;
        int unkB;
        Str_00ac1600 unkC;
        Str_00ac1600 unkD;
        Str_00ac1600 unkE;
        {
            Rec_00ac1600* cur = begin;
            for (; cur != last; cur++)
            {
                cur->f0 = src->f0;
                cur->v = src->v;
                cur->s.Set(&src->s, 0, DAT_010173f0);
            }
        }
    }
}

extern int DAT_010a2f9c;
extern int DAT_010a2fa4;

void __cdecl operator delete(void* pv);

struct S00ace060_Obj
{
    void FUN_00acb610();
    void* FUN_00ace060(int flags);
};

void S00ace060_Obj::FUN_00acb610()
{}

// On the object at this-0x50: calls FUN_00acb610, sets the vtable, calls FUN_00ec3205, deletes the memory if bit 0 of flags is set, and returns it.
// @fnv 0x00ace060
void* S00ace060_Obj::FUN_00ace060(int flags)
{
    char* zbase = reinterpret_cast<char*>(this) - 0x50;
    S00ace060_Obj* o;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;
    int tmp5;

    reinterpret_cast<S00ace060_Obj*>(zbase + 0x50)->FUN_00acb610();

    o = reinterpret_cast<S00ace060_Obj*>(zbase + 0x50);
    *reinterpret_cast<void**>(o) = reinterpret_cast<void*>(&DAT_010a2fa4);
    *reinterpret_cast<void**>(o) = reinterpret_cast<void*>(&DAT_010a2f9c);
    FUN_00ec3205(o);

    if (flags & 1)
        ::operator delete(reinterpret_cast<char*>(this) - 0x50);

    return reinterpret_cast<char*>(this) - 0x50;
}

void __cdecl FormHeap_Free(void*);
void __cdecl FUN_00ec3205(void*);
extern int DAT_010a2fa4;
extern int DAT_010a2f9c;

struct StreamOwner;

struct StreamComponent
{
    int* vtable;
    void FUN_00acc8c0();
    StreamOwner* FUN_00ace150(unsigned int flags);
};

struct StreamHeader
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    int unk48, unk4c, unk50, unk54;
};

struct StreamOwner : StreamHeader, StreamComponent
{
};

// On the owner at this-0x58: calls FUN_00acc8c0, sets the vtable, calls FUN_00ec3205, calls FormHeap_Free if bit 0 of flags is set, and returns the owner.
// @fnv 0x00ace150
StreamOwner* StreamComponent::FUN_00ace150(unsigned int flags)
{
    int c, l, k, ba, b;
    StreamOwner* j = (StreamOwner*)((char*)this - 0x58);
    ((StreamComponent*)((char*)j + 0x58))->FUN_00acc8c0();
    StreamComponent* e = (StreamComponent*)((char*)j + 0x58);
    e->vtable = &DAT_010a2fa4;
    e->vtable = &DAT_010a2f9c;
    FUN_00ec3205(e);
    if (flags & 1)
        FormHeap_Free((char*)this - 0x58);
    return (StreamOwner*)((char*)this - 0x58);
}

#include <string.h>
// Skips a drive or UNC "\\server\share\" prefix; returns the path part after it, or 0.
// Returns the text after the first path separator, skipping any ':' prefix and handling a leading double separator specially; null if none or empty.
// @fnv 0x00ac6e70
const char* GetPathTail(const char* path)
{
    const char* result5 = 0;
    if (!path)
        return result5;
    if (!*path)
        return result5;
    const char* p9 = path;
    const char* colonA = strchr(path, ':');
    if (colonA)
    {
        p9 = colonA + 1;
        if (*p9 != '\\' && *p9 != '/')
            return p9;
    }
    const char* sep4 = strpbrk(p9, "\\/");
    if (sep4)
    {
        result5 = sep4 + 1;
        if (result5 == path + 1)
        {
            const char* next = strpbrk(result5, "\\/");
            if (next == result5)
            {
                result5++;
                result5 = strpbrk(result5, "\\/");
                if (result5)
                {
                    result5++;
                    result5 = strpbrk(result5, "\\/");
                }
                if (result5)
                    result5++;
            }
        }
    }
    if (result5 && !*result5)
        result5 = 0;
    return result5;
}

struct ScriptParameterHandler
{
    int SetOutputValues(int unusedFirst, int primaryValue, int unusedThird, int* primaryOutput, int secondaryValue,
                        int unusedSixth, int* secondaryOutput);
};

// Writes primaryValue and secondaryValue to the output pointers and returns 3.
// @fnv 0x00ad56b0
int ScriptParameterHandler::SetOutputValues(int unusedFirst, int primaryValue, int unusedThird, int* primaryOutput,
                                            int secondaryValue, int unusedSixth, int* secondaryOutput)
{
    *primaryOutput = primaryValue;
    *secondaryOutput = secondaryValue;
    return 3;
}
