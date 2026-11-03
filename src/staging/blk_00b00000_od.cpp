
// src/staging/blk_00b00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00b007d0_shell
{
    int FUN_00b007d0();
};

struct FUN_00b00860_shell
{
    void FUN_00b00860();
};

// @fnv 0x00b00860
void FUN_00b00860_shell::FUN_00b00860()
{
    ((FUN_00b007d0_shell*)this)->FUN_00b007d0();
}

extern int DAT_010a47b3;

struct FUN_00b008e0_class
{
    int* __thiscall FUN_00b008e0();
};

// @fnv 0x00b008e0
int* __thiscall FUN_00b008e0_class::FUN_00b008e0()
{
    return &DAT_010a47b3;
}

struct FUN_00b00950
{
    void __thiscall CloseHandleWrapper();
    void __thiscall DoWork();
};

// @fnv 0x00b00950
void __thiscall FUN_00b00950::DoWork()
{
    CloseHandleWrapper();
}

struct FUN_00b01bc0_class
{
    bool __thiscall IsFlag2Clear(int flags, int unused);
};

// @fnv 0x00b01bc0
bool __thiscall FUN_00b01bc0_class::IsFlag2Clear(int flags, int unused)
{
    return (flags & 2) == 0;
}

struct FUN_00b01be0_Class
{
    bool __thiscall IsFlag4Clear(unsigned int flags, unsigned int unused);
};

// @fnv 0x00b01be0
bool __thiscall FUN_00b01be0_Class::IsFlag4Clear(unsigned int flags, unsigned int unused)
{
    return !(flags & 4);
}

extern int DAT_010a48e8;

struct FUN_00b029a0_class
{
    void __thiscall FUN_00b029a0();
};

// @fnv 0x00b029a0
void __thiscall FUN_00b029a0_class::FUN_00b029a0()
{
    *(int**)(this) = &DAT_010a48e8;
}

struct FUN_00b18320_Class
{
    char GetByteAtOffset4C();
};

// @fnv 0x00b18320
char FUN_00b18320_Class::GetByteAtOffset4C()
{
    return ((const char*)this)[0x4c];
}

struct FUN_00b008f0_class
{
    int* __thiscall FUN_00b008f0();
};

// @fnv 0x00b008f0
int* __thiscall FUN_00b008f0_class::FUN_00b008f0()
{
    return 0;
}

extern int DAT_011f8250;
// @fnv 0x00b00970
void FUN_00b00970(int value)
{
    DAT_011f8250 = value;
}

extern int DAT_011f8af4;
extern int DAT_011f8b38[16];
struct TaskletManager
{
    int* __thiscall FUN_00b00a00();
};
TaskletManager& __cdecl GetTaskletManager();
// Appends param_1 to the DAT_011f8b38 queue when the manager's field at offset 8 is zero and the queue count is below 16, returning 1 on success and 0 otherwise.
// @fnv 0x00b00da0
char QueueTasklet(int param_1)
{
    int* obj = (int*)((char*)&GetTaskletManager() + 8);
    char result;
    if (*obj == 0 && DAT_011f8af4 < 16)
    {
        DAT_011f8b38[DAT_011f8af4] = param_1;
        DAT_011f8af4++;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

struct FUN_00b12af0_shell
{
    void __thiscall FUN_00b12af0();
};
struct FUN_00b130a0
{
    float a, b, c;
    float d, e, f;
    FUN_00b130a0();
};
// Zeroes the six float members a-f and calls FUN_00b12af0 on the object at offset 0x1c.
// @fnv 0x00b130a0
FUN_00b130a0::FUN_00b130a0()
{
    c = 0.0f;
    b = 0.0f;
    a = 0.0f;
    float* p = &d;
    p[2] = 0.0f;
    p[1] = 0.0f;
    p[0] = 0.0f;
    ((FUN_00b12af0_shell*)((char*)this + 0x1c))->FUN_00b12af0();
}

struct FUN_00b0cf90_class
{
    float x, y, z;
    float* __thiscall AddVector(float* pDest, const float* pSource);
};
// Adds the object's x, y and z to the three components of pSource and writes the sums into pDest, returning pDest.
// @fnv 0x00b0cf90
float* FUN_00b0cf90_class::AddVector(float* pDest, const float* pSource)
{
    float f7 = pSource[0] + x;
    float f1 = pSource[1] + y;
    float f2 = pSource[2] + z;
    pDest[0] = f7;
    pDest[1] = f1;
    pDest[2] = f2;
    return pDest;
}

struct FUN_00afeac0_shell
{
    int __thiscall OpenFile(int arg);
};

struct FUN_00b00900
{
    int m0;
    int m4;
    int m8;
    char mc;
    int OpenFile(int arg);
    FUN_00b00900(int a, int b, int c, char d);
};

// Initialises the object: stores b, c and d into m4, m8 and mc, then sets m0 from OpenFile(a).
// @fnv 0x00b00900
FUN_00b00900::FUN_00b00900(int aiValue, int aiSecond, int aiThird, char d)
{
    m0 = 0;
    m4 = aiSecond;
    m8 = aiThird;
    mc = d;
    m0 = OpenFile(aiValue);
}

struct FUN_00b00cf0_vt
{
    virtual void vfn_0();
    virtual void vfn_1();
};
struct FUN_00b00cf0_shell
{
    void __thiscall CallVirtualOnAllEntries();
};
// Iterates DAT_011f8b38 up to DAT_011f8af4 and calls vfn_1 on each non-null entry.
// @fnv 0x00b00cf0
void FUN_00b00cf0_shell::CallVirtualOnAllEntries()
{
    for (int i = 0; i < DAT_011f8af4; ++i)
    {
        if (DAT_011f8b38[i])
            ((FUN_00b00cf0_vt*)DAT_011f8b38[i])->vfn_1();
    }
}

struct FUN_00b12b50_class
{
    float* TransformVector(float* dst, const float* src) const;
};

// Multiplies a 3x3 matrix stored in this by a 3-component vector src and writes the result to dst, returning dst.
// @fnv 0x00b12b50
float* FUN_00b12b50_class::TransformVector(float* dst, const float* src) const
{
    float t0 = src[2] * ((const float*)this)[2] + (src[1] * ((const float*)this)[1] + src[0] * ((const float*)this)[0]);
    float t1 = src[2] * ((const float*)this)[5] + (src[1] * ((const float*)this)[4] + src[0] * ((const float*)this)[3]);
    float t2 = src[2] * ((const float*)this)[8] + (src[1] * ((const float*)this)[7] + src[0] * ((const float*)this)[6]);
    dst[0] = t0;
    dst[1] = t1;
    dst[2] = t2;
    return dst;
}

struct FUN_00b008b0_t
{
    int m0;
    FUN_00b008b0_t* __thiscall FUN_00b008b0(int v);
};

// @fnv 0x00b008b0
FUN_00b008b0_t* __thiscall FUN_00b008b0_t::FUN_00b008b0(int aiValue)
{
    m0 = aiValue;
    return this;
}

extern int DAT_011f8af0;
extern int DAT_011f8af8[];

struct FUN_00b00c90_vt
{
    virtual void vfn_0();
    virtual void vfn_1();
};

// Iterates DAT_011f8af8 up to DAT_011f8af0 and calls vfn_1 on each non-null entry.
// @fnv 0x00b00c90
void __fastcall CallVfn1OnAllEntries(int param_1)
{
    int iIndex;
    for (iIndex = 0; iIndex < DAT_011f8af0; iIndex = iIndex + 1)
    {
        if (DAT_011f8af8[iIndex] != 0)
        {
            ((FUN_00b00c90_vt*)DAT_011f8af8[iIndex])->vfn_1();
        }
    }
}

extern int DAT_011f8af0;
extern int DAT_011f8af8[16];

// @fnv 0x00b00d50
char FUN_00b00d50(int param_1)
{
    char local2;
    int* piVar2 = (int*)((char*)&GetTaskletManager() + 8);
    if (*piVar2 == 0 && DAT_011f8af0 < 0x10)
    {
        DAT_011f8af8[DAT_011f8af0] = param_1;
        DAT_011f8af0 = DAT_011f8af0 + 1;
        local2 = 1;
    }
    else
    {
        local2 = 0;
    }
    return local2;
}

struct FUN_00b01020
{
    virtual ~FUN_00b01020();
};
struct FUN_00b01c20 : public FUN_00b01020
{
    virtual ~FUN_00b01c20();
};
// @fnv 0x00b01c20
FUN_00b01c20::~FUN_00b01c20()
{}

extern int DAT_010a4880;
extern int DAT_010a48ac;
extern "C" __declspec(dllimport) void __stdcall FreeLibrary(void*);
extern "C" __declspec(dllimport) void __stdcall DestroyWindow(void*);

struct FUN_00b01f00_class
{
    void DestroyAndFreeLibraries();
};

// @fnv 0x00b01f00
void FUN_00b01f00_class::DestroyAndFreeLibraries()
{
    *(int*)this = (int)&DAT_010a4880;
    FreeLibrary(*(void**)((char*)this + 0x270));
    DestroyWindow((void*)((char*)this + 0x54));
    *(int*)this = (int)&DAT_010a48ac;
    FreeLibrary(*(void**)((char*)this + 0xc));
}

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00b02970
{
    void FUN_00b02860();
    void* DeleteThis(unsigned int flags);
};
// @fnv 0x00b02970
void* FUN_00b02970::DeleteThis(unsigned int flags)
{
    FUN_00b02860();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00b0e7f0 {
struct MemoryManager
{
    void __thiscall Deallocate(void* ptr);
};

extern MemoryManager _g_memoryManager;

struct FUN_00b0e7f0_class
{
    void* unknown[3];
    int m_pBuffer;
    int m_nSize;
    int m_nCapacity;

    void __thiscall Clear();
};

// Deallocates m_pBuffer through the memory manager if set, then resets m_pBuffer, m_nSize and m_nCapacity to zero.
// @fnv 0x00b0e7f0
void FUN_00b0e7f0_class::Clear()
{
    struct Locals
    {
        int count;
        void* buffer;
        int first;
        int second;
        int copiedFirst;
        int copiedSecond;
        char padding1;
        char padding2;
        char source;
        char destination;
    } locals;

    if (m_pBuffer)
    {
        locals.first = m_nSize;
        locals.second = m_pBuffer;
        locals.copiedFirst = locals.first;
        locals.copiedSecond = locals.second;
        locals.destination = locals.source;
        locals.count = (m_nCapacity - m_pBuffer) >> 2;
        locals.buffer = (void*)m_pBuffer;
        _g_memoryManager.Deallocate(locals.buffer);
    }

    m_pBuffer = 0;
    m_nSize = 0;
    m_nCapacity = 0;
}
}  // namespace fnv_00b0e7f0

class FUN_00b004d0_cls
{
  public:
    void FUN_00b004d0();
};

// @fnv 0x00b004d0
void FUN_00b004d0_cls::FUN_00b004d0()
{}

struct FUN_00b00820_tail
{
    unsigned int pendingState;
    unsigned int otherState;
    unsigned __int64 sequence;
};
struct FUN_00b00820_shell
{
    FUN_00b00820_shell* FUN_00b00820(unsigned int value);
    void FUN_00b006b0(unsigned int value);
};

// Clears pendingState and sequence at offset 0x248, calls FUN_00b006b0 with value, and returns this.
// @fnv 0x00b00820
FUN_00b00820_shell* FUN_00b00820_shell::FUN_00b00820(unsigned int value)
{
    reinterpret_cast<FUN_00b00820_tail*>(reinterpret_cast<char*>(this) + 0x248)->pendingState = 0;
    reinterpret_cast<FUN_00b00820_tail*>(reinterpret_cast<char*>(this) + 0x248)->sequence = 0;
    FUN_00b006b0(value);
    return this;
}

struct FUN_00b00880_cls
{
    int unk00;
    unsigned char m_bFlag;
    FUN_00b00880_cls* ClearFlag();
};

// @fnv 0x00b00880
FUN_00b00880_cls* FUN_00b00880_cls::ClearFlag()
{
    m_bFlag = 0;
    return this;
}

struct FUN_00b008a0_cls
{
    int unk00;
    void FUN_00b008a0();
};

// @fnv 0x00b008a0
void FUN_00b008a0_cls::FUN_00b008a0()
{}

class BSWin32TaskletManager
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual bool vf10(int& value);

    unsigned char unk04;

    bool __thiscall GetTaskletValue(void* result);
};

inline void BSWin32TaskletManager::vf00()
{}
inline void BSWin32TaskletManager::vf04()
{}
inline void BSWin32TaskletManager::vf08()
{}
inline void BSWin32TaskletManager::vf0c()
{}
inline bool BSWin32TaskletManager::vf10(int&)
{
    return false;
}

// If unk04 is set, calls vf10 to obtain a value and stores it through result, returning the call's success; otherwise stores 0 and returns false.
// @fnv 0x00b00a80
bool __thiscall BSWin32TaskletManager::GetTaskletValue(void* result)
{
    bool operationSucceeded;

    {
        int outputValue;

        {
            unsigned char enabled = this->unk04;

            {
                int copiedValue;

                if (enabled != 0)
                {
                    operationSucceeded = this->vf10(outputValue);
                    copiedValue = outputValue;
                    *static_cast<int*>(result) = copiedValue;
                }
                else
                {
                    operationSucceeded = false;
                    *static_cast<int*>(result) = 0;
                }
            }
        }
    }

    return operationSucceeded;
}

struct FUN_00b00ae0_class
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual bool virtual5(void* value);
    bool enabled;
    bool __thiscall FUN_00b00ae0(void** value);
};
// Returns true only if enabled is set and the pointed-to value is non-null and passes virtual5.
// @fnv 0x00b00ae0
bool FUN_00b00ae0_class::FUN_00b00ae0(void** value)
{
    bool flag = enabled;
    {
        void* current;
        {
            void* payload;
            return (flag && (current = *value)) ? virtual5(payload = *value) : false;
        }
    }
}

class FUN_00b00b40_cls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual bool v18(void* a, void* b, bool c);
    bool m_04;
    bool TryProcessPair(void** a, void** b, bool c);
};

// @fnv 0x00b00b40
bool FUN_00b00b40_cls::TryProcessPair(void** apFirst, void** b, bool abFlag)
{
    bool flagTmp = m_04;
    void* p4;
    void* q;
    void* x7;
    void* y4;
    return (flagTmp && (p4 = *apFirst) != 0 && (q = b[1]) != 0) ? (x7 = b[1], y4 = *apFirst, v18(y4, x7, abFlag))
                                                                : false;
}

class B00C20Item
{
  public:
    virtual void vfn00();
    virtual void Shutdown(int iMode);

    bool m_bShutDown;
};

class B00C20Pool
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void FreeItem(B00C20Item* pkItem);

    void ReleaseItem(B00C20Item*& rpkItem);
};

// If rpkItem is non-null, shuts it down when not already shut down, frees it via FreeItem, and clears the reference.
// @fnv 0x00b00c20
void B00C20Pool::ReleaseItem(B00C20Item*& rpkItem)
{
    B00C20Item* pkItem_ = rpkItem;
    bool bShutDown2;
    B00C20Item* pkFree;
    if (pkItem_)
    {
        if (rpkItem)
        {
            bShutDown2 = rpkItem->m_bShutDown;
            if (!bShutDown2)
                rpkItem->Shutdown(0);
        }
        pkFree = rpkItem;
        FreeItem(pkFree);
        rpkItem = 0;
    }
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* lpPreviousCount);

struct FUN_00b00df0_sub
{
    long m_00;
    void* m_04;
};

class FUN_00b00df0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    FUN_00b00df0_sub m_08;
    void ReleaseAndSignal();
};

// Releases the semaphore in m_08, increments its counter, sets m_05 to 1, then calls vfn_9.
// @fnv 0x00b00df0
void FUN_00b00df0_cls::ReleaseAndSignal()
{
    FUN_00b00df0_sub* p = &m_08;
    ReleaseSemaphore(p->m_04, 1, 0);
    InterlockedIncrement(&p->m_00);
    m_05 = 1;
    vfn_9();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* destination, long exchange,
                                                                           long comparand);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);

extern int DAT_0106c800;
extern int DAT_0106c814;

struct FUN_00b00ec0
{
    int unk00;
    int unk04;
    int m_08;
    int unk0c;
    long m_10;

    ~FUN_00b00ec0() throw();
};

// @fnv 0x00b00ec0
FUN_00b00ec0::~FUN_00b00ec0() throw()
{
    *(void* volatile*)this = (void*)&DAT_0106c800;
    while (InterlockedCompareExchange(&m_10, 1, 0) != 0)
    {
        Sleep(0);
    }
    if (m_08 != 0)
    {
        m_08 = 0;
    }
    m_10 = 0;
    *(void* volatile*)this = (void*)&DAT_0106c814;
}

extern "C" __declspec(dllimport) int __stdcall FindFirstFileA(const char* pattern);
extern "C" __declspec(dllimport) int __stdcall FindClose(int handle);

struct FUN_00b01510_cls
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual int vfn_6(char* data);
    bool __thiscall FUN_00b01510(int arg);
};

// @fnv 0x00b01510
bool FUN_00b01510_cls::FUN_00b01510(int aiUnused)
{
    char data[0x140];
    int handle = FindFirstFileA((const char*)vfn_6(data));
    bool ok;
    if (handle == -1)
    {
        ok = false;
    }
    else
    {
        FindClose(handle);
        ok = true;
    }
    return ok;
}

extern "C" void(__stdcall* fnv_EnterCriticalSection)(void* pkSection);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void* pkSection);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* plPreviousCount);

struct B02670Semaphore
{
    long m_lCount;
    void* m_pSemaphore;
};

struct B02670CriticalSection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B02670Task
{
  public:
    int unk00;
    int unk04;
    B02670Semaphore m_kCompletionSemaphore;
    int unk10;
    B02670CriticalSection m_kLock;
    unsigned char unk2C;
    bool m_bCancelled;
    unsigned char unk2E;
    unsigned char unk2F;
    int unk30;
    int m_iTarget;
    int m_iCompleted;

    void CompleteTask();
};

// Increments m_iCompleted under the lock; if not cancelled and m_iCompleted equals m_iTarget, releases the semaphore and increments its count.
// @fnv 0x00b02670
void B02670Task::CompleteTask()
{
    fnv_EnterCriticalSection(&m_kLock);
    m_iCompleted++;
    bool bSignal = !m_bCancelled && m_iCompleted == m_iTarget;
    fnv_LeaveCriticalSection(&m_kLock);
    if (bSignal)
    {
        B02670Semaphore* pkSemaphore = &m_kCompletionSemaphore;
        ReleaseSemaphore(pkSemaphore->m_pSemaphore, 1, 0);
        InterlockedIncrement(&pkSemaphore->m_lCount);
    }
}

void FUN_00ec7c56();
unsigned int FUN_00b10730(unsigned int a, unsigned int b, unsigned int c);

struct FUN_00b0e510_pair
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned char FUN_00b10490(FUN_00b0e510_pair* other);
};

struct FUN_00b0e510_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned int unk10;
};

struct FUN_00b0e510_big
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

class FUN_00b0e510_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    FUN_00b0e510_pair* FUN_00b0e510(FUN_00b0e510_pair* out, unsigned int a0, unsigned int a1, unsigned int a2,
                                    unsigned int a3);
};

// @fnv 0x00b0e510
FUN_00b0e510_pair* FUN_00b0e510_cls::FUN_00b0e510(FUN_00b0e510_pair* out, unsigned int a0, unsigned int a1,
                                                  unsigned int a2, unsigned int a3)
{
    FUN_00b0e510_pair lo;
    FUN_00b0e510_pair hi;
    unsigned int r;
    FUN_00b0e510_tmp big;
    FUN_00b0e510_big t;

    lo.m_00 = 0;
    if (this == 0 || this->m_0c > a1 || a1 > this->m_10)
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);
    lo.m_00 = this->m_00;
    lo.m_04 = a1;
    hi.m_00 = 0;
    if (this == 0 || this->m_0c > a3 || a3 > this->m_10)
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);
    hi.m_00 = this->m_00;
    hi.m_04 = a3;
    if (lo.FUN_00b10490(&hi) != 0)
    {
        r = FUN_00b10730(hi.m_04, this->m_10, lo.m_04);
        big.unk00 = this->m_10;
        big.unk04 = big.unk00;
        big.unk08 = r;
        big.unk0d = big.unk0c;
        this->m_10 = r;
    }
    *out = lo;
    return out;
}

extern void __cdecl FUN_00ec7c56();

struct FUN_00b10490_class
{
    int first;
    int second;
    bool __thiscall FUN_00b10490(const FUN_00b10490_class* rhs);
};

// Calls FUN_00ec7c56 when first is zero or differs from rhs->first, then returns whether second differs from rhs->second.
// @fnv 0x00b10490
bool __thiscall FUN_00b10490_class::FUN_00b10490(const FUN_00b10490_class* rhs)
{
    if (!((unsigned char)(int)(first != 0) && (unsigned char)(int)(first == rhs->first)))
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (false);
    return !((unsigned char)(int)(second == rhs->second));
}

struct FUN_00b108e0_pool
{
    void* FUN_00aa3e40(unsigned int size);
};

extern "C" FUN_00b108e0_pool DAT_011f6238;
extern "C" char DAT_010176f8[];
extern "C" char DAT_01140ef8[];
extern "C" void __stdcall FUN_00ec7894(void* err2, const char* msg);

struct FUN_00b108e0_err
{
    void* m_vptr;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00ec78f1(unsigned int* out);
};

// Checks that count * 0x1c does not overflow, reports an error if it does, then allocates count * 0x1c bytes from the pool and returns the pointer.
// @fnv 0x00b108e0
void* __cdecl AllocatePoolArray(unsigned int count)
{
    if (count <= 0)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 0x1c)
        {
            unsigned int tmp = 0;
            FUN_00b108e0_err err2;
            err2.FUN_00ec78f1(&tmp);
            err2.m_vptr = DAT_010176f8;
            FUN_00ec7894(&err2, DAT_01140ef8);
        }
    }
    return DAT_011f6238.FUN_00aa3e40(count * 0x1c);
}

struct Mat3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    Mat3();
    Mat3 Multiply(const Mat3& rhs) const;
};

// Multiplies this 3x3 matrix by rhs and returns the resulting matrix.
// @fnv 0x00b12940
Mat3 Mat3::Multiply(const Mat3& rhs) const
{
    Mat3 result;
    result.m00 = m00 * rhs.m00 + m01 * rhs.m10 + m02 * rhs.m20;
    result.m01 = m00 * rhs.m01 + m01 * rhs.m11 + m02 * rhs.m21;
    result.m02 = m00 * rhs.m02 + m01 * rhs.m12 + m02 * rhs.m22;
    result.m10 = m10 * rhs.m00 + m11 * rhs.m10 + m12 * rhs.m20;
    result.m11 = m10 * rhs.m01 + m11 * rhs.m11 + m12 * rhs.m21;
    result.m12 = m10 * rhs.m02 + m11 * rhs.m12 + m12 * rhs.m22;
    result.m20 = m20 * rhs.m00 + m21 * rhs.m10 + m22 * rhs.m20;
    result.m21 = m20 * rhs.m01 + m21 * rhs.m11 + m22 * rhs.m21;
    result.m22 = m20 * rhs.m02 + m21 * rhs.m12 + m22 * rhs.m22;
    return result;
}

extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
extern double DAT_010a4d90;
struct RotationMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void __thiscall SetRotationAxisAngle(float angle, float x, float y, float z);
};
// Builds a 3x3 rotation matrix from an angle and axis components, storing the result in m00..m22.
// @fnv 0x00b12ec0
void RotationMatrix::SetRotationAxisAngle(float angle, float afAxisX, float afAxisY, float afAxisZ)
{
    float cosA = (float)((float)(sin((float)(angle / DAT_010a4d90))));
    float sinA = (float)((float)(cos((float)(angle / DAT_010a4d90))));
    float zAxis = 1.0f - sinA;
    float xAxis = afAxisX, yAxis = afAxisY, oneMinusCosA = afAxisZ;
    m00 = zAxis * xAxis * xAxis + sinA;
    m01 = zAxis * xAxis * yAxis + cosA * oneMinusCosA;
    m02 = zAxis * xAxis * oneMinusCosA - cosA * yAxis;
    m10 = zAxis * xAxis * yAxis - cosA * oneMinusCosA;
    m11 = zAxis * yAxis * yAxis + sinA;
    m12 = zAxis * yAxis * oneMinusCosA + cosA * xAxis;
    m20 = zAxis * xAxis * oneMinusCosA + cosA * yAxis;
    m21 = zAxis * yAxis * oneMinusCosA - cosA * xAxis;
    m22 = zAxis * oneMinusCosA * oneMinusCosA + sinA;
}

struct Vec3f
{
    float x, y, z;
};

struct ScratchBlock
{
    Vec3f m_00;
    Vec3f m_0c;
    Vec3f m_18;
};

struct ScratchPair
{
    int m_00;
    int m_04;
};

struct ScratchResult
{
    const float* GetSource();
};

struct ScratchHelper
{
    ScratchResult* Compute(float* out, FUN_00b0cf90_class* owner, Vec3f* tmp, float scale);
};

// @fnv 0x00b13000
float* FUN_00b13000(float* dst, FUN_00b0cf90_class* pOwner, ScratchHelper* pHelper, float fScale)
{
    Vec3f blk;
    float c3;
    ScratchPair pr;
    ScratchBlock tmp;
    pOwner->AddVector(dst, pHelper->Compute(&c3, pOwner, &blk, fScale)->GetSource());
    return dst;
}

void __cdecl FUN_00b17b40(int, int, int, int, unsigned char, unsigned char);
struct Flag
{
    unsigned char v;
};
// @fnv 0x00b17740
void __cdecl FUN_00b17740(int a, int b, int c, int d)
{
    Flag zero = {};
    unsigned char raw4;
    unsigned char copy = raw4;
    {
        int dd_b = b;
        int tau_p;
        int zeta_a;
        zeta_a = a;
        FUN_00b17b40(zeta_a, dd_b, c, d, copy, zero.v);
    }
}

struct BB17790Iterator
{
    int* m_piPtr;
};

struct BB17790PtrCategory
{
    char m_cKind;
};
struct BB17790CheckedTag
{
};

void __cdecl FUN_00b17c20(BB17790Iterator kFirst, BB17790Iterator kLast, int* piDest, void* pvAllocator,
                          BB17790PtrCategory kCategory, BB17790CheckedTag kChecked);

// Forwards the iterator range, destination pointer and allocator to FUN_00b17c20 along with an uninitialized category and a checked tag.
// @fnv 0x00b17790
void __cdecl FUN_00b17790(BB17790Iterator kFirst, BB17790Iterator kLast, int* piDest, void* pvAllocator)
{
    BB17790CheckedTag kChecked = {};
    BB17790PtrCategory kCategorySource4;
    BB17790PtrCategory kCategory = kCategorySource4;
    BB17790Iterator kLastBase = kLast;
    int* kDest;
    BB17790Iterator kFirstBase3 = kFirst;
    FUN_00b17c20(kFirstBase3, kLastBase, piDest, pvAllocator, kCategory, kChecked);
}

struct SortEntry
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
    float key;
};
// Orders three SortEntry pointers by their key field using compare-and-swap passes.
// @fnv 0x00b17850
void SortThreeEntries(SortEntry** apFirst, SortEntry** apSecond, SortEntry** apThird)
{
    {
        float left0 = (*apSecond)->key;
        float right0 = (*apFirst)->key;
        if (((unsigned char)(left0 > right0 ? 1 : 0)) && apSecond != apFirst)
        {
            SortEntry* swap0 = *apSecond;
            *apSecond = *apFirst;
            *apFirst = swap0;
        }
    }
    {
        float right1 = (*apThird)->key;
        float left1 = (*apSecond)->key;
        if (((unsigned char)(right1 > left1 ? 1 : 0)) && apThird != apSecond)
        {
            SortEntry* swap1 = *apThird;
            *apThird = *apSecond;
            *apSecond = swap1;
        }
    }
    {
        float right2 = (*apSecond)->key;
        float left2 = (*apFirst)->key;
        if (((unsigned char)(right2 > left2 ? 1 : 0)) && apSecond != apFirst)
        {
            SortEntry* swap2 = *apSecond;
            *apSecond = *apFirst;
            *apFirst = swap2;
        }
    }
}

struct FUN_00b17e90_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int* m_0c;
    int* m_10;
    int* m_14;

    bool ResizeArray(unsigned int count);
};

struct FUN_00b17e90_pad
{
    unsigned int u00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0c;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1c;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    unsigned int u34;
    unsigned int u38;
    unsigned int u3c;
    unsigned int u40;
    unsigned int u44;
    unsigned int u48;
    unsigned int u4c;
    unsigned int u50;
    unsigned int u54;
    unsigned int u58;
    unsigned int u5c;
    unsigned int u60;
    unsigned int u64;
    unsigned int u68;
    unsigned int u6c;
    unsigned int u70;
    unsigned int u74;
    unsigned int u78;
    unsigned int u7c;
    unsigned int u80;
};

void FUN_00b0fb80();
int* FUN_00b16b00(unsigned int count, int zero);

// @fnv 0x00b17e90
bool FUN_00b17e90_cls::ResizeArray(unsigned int count)
{
    FUN_00b17e90_pad scratch;
    unsigned int cap;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (count == 0)
    {
        return false;
    }
    else
    {
        cap = 0x3fffffff;
        if ((cap > 0 ? cap : 1) < count)
        {
            FUN_00b0fb80();
        }
        else
        {
            m_0c = FUN_00b16b00(count, 0);
            m_10 = m_0c;
            m_14 = m_0c + count;
        }
    }
    return true;
}

namespace fnv_00b00980 {
#include <windows.h>

extern unsigned int DAT_011f826c;
extern CRITICAL_SECTION DAT_011f8254;
void __cdecl FUN_00fdc3f0();
int __cdecl FUN_00ec658f(void(__cdecl* fn)());

// Initializes the critical section once, then calls the stored callback with a, b, c under the lock, returning 1 if no callback is set.
// @fnv 0x00b00980
unsigned char __cdecl CallLockedCallback(int a, int b, int c)
{
    unsigned char result;
    unsigned char called;
    if ((DAT_011f826c & 1) == 0)
    {
        DAT_011f826c |= 1;
        InitializeCriticalSection(&DAT_011f8254);
        FUN_00ec658f(FUN_00fdc3f0);
    }
    EnterCriticalSection(&DAT_011f8254);
    if (DAT_011f8250 != 0)
    {
        result = reinterpret_cast<unsigned char(__cdecl*)(int, int, int)>(DAT_011f8250)(a, b, c);
    }
    else
    {
        result = 1;
    }
    called = result;
    LeaveCriticalSection(&DAT_011f8254);
    return called;
}
}  // namespace fnv_00b00980

void* _memmove(void* pDst, const void* pSrc, unsigned int uiSize);
struct BufferPos
{
    char* pcData;
    unsigned int uiElapsedMilliseconds;
};
struct FUN_00b01800_shell
{
    char pad00[0x10];
    unsigned int m_uiBufferSize;
    unsigned int m_uiBufferFill;
    unsigned int m_uiBufferPos;
    unsigned int unk1C;
    char* m_pString;
    unsigned int ReadAtOffset(void* pDst, unsigned int uiSize, unsigned int uiElapsedMilliseconds);
    unsigned int FUN_00b01800(void* pDst, unsigned int uiSize);
};

// @fnv 0x00b01800
unsigned int FUN_00b01800_shell::FUN_00b01800(void* pDst, unsigned int uiSize)
{
    unsigned int uiDone = 0;
    unsigned int uiAvail = m_uiBufferFill - m_uiBufferPos;
    if (uiSize > uiAvail)
    {
        if (uiAvail > 0)
        {
            BufferPos kPos = {m_pString + m_uiBufferPos, 0};
            _memmove(pDst, kPos.pcData, uiAvail);
            pDst = (char*)pDst + uiAvail;
            uiSize -= uiAvail;
            uiDone = uiAvail;
        }
        m_uiBufferFill = 0;
        m_uiBufferPos = 0;
        if (uiSize > m_uiBufferSize)
        {
            return ReadAtOffset(pDst, uiSize, uiDone) + uiDone;
        }
        else
        {
            m_uiBufferFill = ReadAtOffset(m_pString, m_uiBufferSize, uiDone);
            if (m_uiBufferFill < uiSize)
                uiSize = m_uiBufferFill;
        }
    }
    {
        BufferPos kSrc = {m_pString + m_uiBufferPos, 0};
        _memmove(pDst, kSrc.pcData, uiSize);
    }
    m_uiBufferPos += uiSize;
    return uiDone + uiSize;
}

struct StripDestination
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned short unk24;
    unsigned short stripCount;
    void FUN_00b2fdc0(unsigned short id, unsigned short* step, unsigned short indices);
};
struct StripBuilder
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int rowCount;
    unsigned short width;
    unsigned int baseIndex;
    void BuildStripIndices(unsigned short id, StripDestination* destination);
};
// @fnv 0x00b135a0
void StripBuilder::BuildStripIndices(unsigned short ausStripId, StripDestination* destination)
{
    if (width >= 2)
    {
        int position = width;
        float columns = position == 0 ? 1.0 : (double)width / position;
        int rows = rowCount;
        unsigned short* step;
        int indices = (rows - 1) * (2 * position + 4);
        step = new unsigned short[indices];
        destination->FUN_00b2fdc0(ausStripId, step, (unsigned short)indices);
        int count = 0;
        float index = 0.0f;
        for (int row = 0; row < rows - 1; row++)
        {
            int start = (int)index;
            step[count++] = (unsigned short)(baseIndex + (width + 1) + (int)index);
            step[count++] = (unsigned short)(baseIndex + (int)index);
            index += columns;
            for (int column = 1; column < position; column++)
            {
                step[count++] = (unsigned short)(baseIndex + (width + 1) + (int)index);
                step[count++] = (unsigned short)(baseIndex + (int)index);
                index += columns;
            }
            step[count++] = (unsigned short)(baseIndex + (width + 1) + start + width);
            step[count++] = (unsigned short)(baseIndex + start + width);
            index = (float)(start + width + 1);
            step[count++] = (unsigned short)(baseIndex + (width + 1) + start);
            step[count++] = (unsigned short)(baseIndex + (width + 1) + start);
        }
        destination->stripCount++;
    }
}

extern "C" char DAT_010176f8[];
extern "C" char DAT_01140ef8[];
extern "C" void __stdcall FUN_00ec7894(void* err2, const char* msg);

// @fnv 0x00b16b00
int* FUN_00b16b00(unsigned int count, int aiUnused)
{
    if (count <= 0)
        count = 0;
    else if (0xffffffffu / count < 4)
    {
        FUN_00b108e0_err val;
        unsigned int err = 0;
        val.FUN_00ec78f1(&err);
        val.m_vptr = DAT_010176f8;
        FUN_00ec7894(&val, DAT_01140ef8);
    }
    return (int*)operator new(count << 2);
}

extern "C" unsigned int __cdecl wcslen(const wchar_t* s);
extern "C" void* __cdecl memmove(void* dst, const void* src, unsigned int size);

struct Pad36
{
    unsigned int unk00[9];
};
struct WStr
{
    wchar_t* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    bool FUN_00afff50(const wchar_t* text, unsigned int length);
    WStr& Append(const wchar_t* text);
};

// Appends text to the string, growing the buffer when needed and updating the length, or assigns it when the string is empty.
// @fnv 0x00b00120
WStr& WStr::Append(const wchar_t* awcText)
{
    unsigned int addLen, newLen;
    if (awcText)
    {
        wchar_t* p = pString;
        if (p)
        {
            wchar_t* s1;
            addLen = awcText ? wcslen(awcText) : 0;
            newLen = (sLen == 0xFFFF ? (s1 = pString, wcslen(s1)) : sLen) + addLen;
            if (newLen > sMaxLen)
            {
                Pad36 pad1;
                wchar_t* s2 = pString;
                FUN_00afff50(s2, newLen);
            }
            {
                Pad36 pad;
                wchar_t* dst;
                wchar_t* s3;
                dst = pString + (sLen == 0xFFFF ? (s3 = pString, wcslen(s3)) : sLen);
                memmove(dst, awcText, addLen * 2 + 2);
            }
            sLen = newLen <= 0xFFFF ? (unsigned short)newLen : 0xFFFF;
        }
        else
        {
            FUN_00afff50(awcText, 0);
        }
    }
    return *this;
}

unsigned int strlen(const char* s);
const char* strrchr(const char* s, int c);
void* memcpy(void* d, const void* s, unsigned int n);
int strcpy_s(char* d, unsigned int n, const char* s);

struct DirFileTime
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};
struct DirectoryFindData
{
    unsigned int dwFileAttributes;
    DirFileTime ftCreationTime;
    DirFileTime ftLastAccessTime;
    DirFileTime ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
extern void*(__stdcall* DAT_00fdf070)(const char* pattern, DirectoryFindData* data);
extern int(__stdcall* DAT_00fdf068)(void* handle, DirectoryFindData* data);

struct DirAllocator
{
    void* Allocate(unsigned int size);
};
extern DirAllocator g_dirAllocator;

// Enumerates files matching pattern, builds full paths from path and adds each to list, then closes the find handle.
// @fnv 0x00b01930
void CollectDirectoryEntries(const char* pattern, const char* path, BSSimpleList<char*>* list)
{
    DirectoryFindData findData_2;
    void* hFind9 = DAT_00fdf070(pattern, &findData_2);
    if (hFind9 != (void*)-1)
    {
        unsigned int dirLen3 = strlen(path);
        const char* slashTmp = strrchr(path, '\\');
        if (slashTmp)
        {
            dirLen3 -= strlen(slashTmp + 1);
        }
        do
        {
            unsigned int total = dirLen3 + strlen(findData_2.cFileName) + 1;
            char* name;
            void* aMem;
            name = (char*)(aMem = g_dirAllocator.Allocate(total));
            char* aDest = name;
            memcpy(aDest, path, dirLen3);
            name[dirLen3] = 0;
            char* searchTmp = name;
            char* fileName4 = (char*)strrchr(searchTmp, '\\');
            if (fileName4)
            {
                fileName4++;
                unsigned int remainVal = total - (fileName4 - name);
                strcpy_s(fileName4, remainVal, findData_2.cFileName);
                list->AddHead(name);
                {
                    unsigned int u1, u2, u3;
                }
            }
        } while (DAT_00fdf068(hFind9, &findData_2));
        FindClose((int)hFind9);
    }
}

// @fnv 0x00b10830
void __cdecl FUN_00b10830(unsigned int count)
{
    if (count <= 0u)
    {
        count = 0;
    }
    else
    {
        if (0xffffffffu / count < 4u)
        {
            FUN_00b108e0_err value;
            unsigned int error = 0;
            value.FUN_00ec78f1(&error);
            value.m_vptr = (void*)DAT_010176f8;
            FUN_00ec7894(&value, DAT_01140ef8);
        }
    }
    DAT_011f6238.FUN_00aa3e40(count << 2);
}

typedef struct B10C20Elem
{
    int m00, m04, m08, m0c, m10, m14, m18;
} B10C20Elem;

// Copies each element from the range [first, last) into dest, returning the advanced dest pointer.
// @fnv 0x00b10c20
B10C20Elem* __cdecl FUN_00b10c20(B10C20Elem* first, B10C20Elem* last, B10C20Elem* dest)
{
    B10C20Elem* original = dest;
    try
    {
        for (; first != last; ++dest, ++first)
        {
            B10C20Elem* p = dest;
            B10C20Elem* q = p;
            B10C20Elem* r;
            if (q != 0)
            {
                *q = *first;
                r = q;
            }
            else
            {
                r = 0;
            }
        }
    }
    catch (...)
    {
        for (; original != dest; ++original)
            ;
        throw;
    }
    return dest;
}

struct S_b16cd0
{
    int m0, m4, m8, mc, md, me;
};

// @fnv 0x00b16cd0
void __cdecl CopyStructArray(S_b16cd0* apDest, unsigned int auiCount, S_b16cd0* apSource)
{
    void* v14 = (void*)apDest;
    try
    {
        for (; auiCount > 0; auiCount -= 1, apDest += 1)
        {
            void* v18 = (void*)apDest;
            S_b16cd0* v1c3 = (S_b16cd0*)v18;
            void* v20;
            if (v1c3)
            {
                *v1c3 = *apSource;
                v20 = v1c3;
            }
            else
            {
                v20 = 0;
            }
            (void)v20;
        }
    }
    catch (...)
    {
        for (; v14 != (void*)apDest; v14 = (char*)v14 + 0x18)
        {
        }
        throw;
    }
}

struct CopyElem12
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
};

// Copies each CopyElem12 from the range [src, srcEnd) into dst, returning the advanced destination pointer.
// @fnv 0x00b17b40
CopyElem12* __cdecl FUN_00b17b40(CopyElem12* src, CopyElem12* srcEnd, CopyElem12* dst)
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

typedef void* HANDLE;
typedef unsigned long DWORD;
typedef DWORD(__stdcall* ThreadStartFn)(void*);
struct CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) HANDLE __stdcall CreateSemaphoreA(void*, long, long, const char*);
extern "C" __declspec(dllimport) HANDLE
    __stdcall CreateThread(void*, unsigned long, ThreadStartFn, void*, DWORD, DWORD*);

struct BSSemaphoreStandIn
{
    int count;
    HANDLE semaphore;
    int maxCount;
};

struct CriticalSectionInit
{
    CRITICAL_SECTION* section;
    int state;
};

struct TaskThreadPoolBase
{
    bool bActive;
    bool m_bThirdThreadFlag;
    BSSemaphoreStandIn baseSemaphore;
    TaskThreadPoolBase();
    virtual ~TaskThreadPoolBase();
};

DWORD __stdcall WorkerThreadProc(void* param);
DWORD __stdcall MainThreadProc(void* param);

struct FUN_00b01d50 : TaskThreadPoolBase
{
    HANDLE mainThread;
    unsigned int numThreads;
    unsigned int numCreated;
    HANDLE threads[6];
    DWORD threadIDs[6];
    bool unk50;
    CRITICAL_SECTION critSection;
    void* slots[64];
    int unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188;
    int unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8;
    int unk1ac, unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8;
    int unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8;
    int unk1ec, unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208;
    int unk20c, unk210, unk214, unk218, unk21c, unk220, unk224, unk228;
    int unk22c, unk230, unk234, unk238, unk23c, unk240, unk244, unk248;
    int unk24c, unk250, unk254, unk258, unk25c, unk260, unk264, unk268;
    BSSemaphoreStandIn semaphore;

    FUN_00b01d50(unsigned int count);
    virtual ~FUN_00b01d50();
};

// Initializes the thread pool by creating a critical section, a semaphore, and up to six worker threads plus one main thread.
// @fnv 0x00b01d50
FUN_00b01d50::FUN_00b01d50(unsigned int count)
{
    mainThread = 0;
    numThreads = count > 6 ? 6 : count;
    numCreated = 0;
    unk50 = false;
    DWORD threadID;
    {
        CriticalSectionInit initCS;
        initCS.section = &critSection;
        InitializeCriticalSection(initCS.section);
    }
    {
        BSSemaphoreStandIn* pSem = &semaphore;
        pSem->count = 0;
        pSem->maxCount = 0x7fffffff;
        pSem->semaphore = CreateSemaphoreA(0, pSem->count, pSem->maxCount, 0);
    }
    unsigned int i;
    for (i = 0; i < 64; i++)
        slots[i] = 0;
    for (i = 0; i < 6; i++)
    {
        threads[i] = 0;
        threadIDs[i] = 0;
    }
    for (i = 0; i < numThreads; i++)
    {
        threads[i] = CreateThread(0, 0, WorkerThreadProc, this, 4, &threadIDs[i]);
        if (threads[i] == 0)
            break;
        else
            numCreated++;
    }
    bActive = numCreated > 0;
    if (bActive)
        mainThread = CreateThread(0, 0, MainThreadProc, this, 0, &threadID);
}

extern int DAT_010a48ac;

struct FUN_00b02720_shell
{
    void* __thiscall Init();
};

// Initializes the object's vtable, zeroes two bytes, and creates a semaphore with initial count 0 and maximum count 1.
// @fnv 0x00b02720
void* __thiscall FUN_00b02720_shell::Init()
{
    *(int*)this = (int)&DAT_010a48ac;
    ((unsigned char*)this)[4] = 0;
    ((unsigned char*)this)[5] = 0;
    int* p = (int*)((char*)this + 8);
    *p = 0;
    p[2] = 1;
    p[1] = (int)CreateSemaphoreA(0, *p, p[2], 0);
    return this;
}

extern int DAT_010a48d8;
struct FUN_00b027c0
{
    void* vtable;
    char bActive;
    void* pGroup;
    FUN_00b027c0();
};
struct CSFields
{
    long LockCount;
    long Semaphore;
    long Pad1;
};
// Constructor that sets the vtable and bActive, creates a semaphore (max count 1) and a critical section, and zeroes several fields.
// @fnv 0x00b027c0
FUN_00b027c0::FUN_00b027c0()
{
    vtable = &DAT_010a48e8;
    bActive = 1;
    vtable = &DAT_010a48d8;
    CSFields* pCS = (CSFields*)((char*)this + 8);
    pCS->LockCount = 0;
    pCS->Pad1 = 1;
    pCS->Semaphore = (long)CreateSemaphoreA(0, 0, 1, 0);
    CRITICAL_SECTION* pCS2 = (CRITICAL_SECTION*)((char*)this + 0x14);
    InitializeCriticalSection(pCS2);
    ((char*)this)[0x2c] = 0;
    ((char*)this)[0x2d] = 0;
    ((char*)this)[0x2e] = 0;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
}

struct B0Elem
{
    int m0, m4, m8, mc, m10, m14, m18;
};
struct B0Vector
{
    int unk00, unk04, unk08;
    B0Elem* m_pHeadNode;
    B0Elem* m_last;
    B0Elem* m_pFreeList;
    void FUN_00b0ea80();
};
struct B0Locals
{
    int current;
    B0Elem* first1;
    B0Elem* last1;
    B0Elem* n;
    B0Elem* tags;
    B0Elem* toFree;
    B0Elem* iter;
    unsigned char pad0, pad1, oldtag, newtag;
};
// Deallocates the B0Elem node array and resets m_pHeadNode, m_last, and m_pFreeList to null.
// @fnv 0x00b0ea80
void B0Vector::FUN_00b0ea80()
{
    if (m_pHeadNode != 0)
    {
        B0Locals v;
        v.last1 = m_last;
        v.n = m_pHeadNode;
        v.tags = v.last1;
        v.toFree = v.n;
        v.newtag = v.oldtag;
        for (v.iter = v.toFree; v.iter != v.tags; ++v.iter)
        {
        }
        v.current = m_pFreeList - m_pHeadNode;
        v.first1 = m_pHeadNode;
        g_memoryManager.Deallocate(v.first1);
    }
    m_pHeadNode = 0;
    m_last = 0;
    m_pFreeList = 0;
}

struct FUN_00b10940_cat
{
    bool unk00;
};
struct FUN_00b10940_tag
{
    bool unk00;
};
struct FUN_00b10940_pair
{
    unsigned int lo;
    unsigned int hi;
};

void __cdecl FUN_00b10c20(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, FUN_00b10940_cat a5,
                          FUN_00b10940_tag a6);

// Forwards first, last, dest and al to FUN_00b10c20 along with an uninitialized one-byte tag and a zeroed one-byte kind.
// @fnv 0x00b10940
void __cdecl FUN_00b10940(unsigned int first, unsigned int last, unsigned int dest, unsigned int al)
{
    FUN_00b10940_tag kind = {};
    FUN_00b10940_cat tag;
    FUN_00b10940_cat iter;
    tag = iter;
    unsigned int n = last;
    FUN_00b10940_pair val;
    val.lo = first;
    FUN_00b10c20(val.lo, n, dest, al, tag, kind);
}

void __cdecl FormHeap_Free(int block);

struct FUN_00b15600_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    int m_14;
    void FUN_00b15600();
};

struct Rng
{
    int a;
    int b;
};
// If m_0c is set, passes it to FormHeap_Free; then zeroes m_0c, m_10 and m_14.
// @fnv 0x00b15600
void FUN_00b15600_cls::FUN_00b15600()
{
    if (!!m_0c)
    {
        unsigned char it;
        char c3;
        Rng pForm;
        pForm.a = m_10;
        pForm.b = m_0c;
        Rng tmp = pForm;
        it = c3;
        unsigned long c1;
        for (c1 = tmp.b; c1 != tmp.a; c1 += 0x18)
        {
        }
        int kCount;
        kCount = (m_14 - m_0c) / 0x18;
        long block = m_0c;
        FormHeap_Free(block);
    }
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
}

extern "C" int __cdecl strcat_s(char* d, unsigned int n, const char* s);
struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};
struct _WIN32_FIND_DATAA
{
    unsigned long dwFileAttributes;
    _FILETIME ftCreationTime;
    _FILETIME ftLastAccessTime;
    _FILETIME ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
__declspec(dllimport) int __stdcall FindFirstFileA(const char*, _WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(int, _WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall CompareFileTime(const _FILETIME*, const _FILETIME*);
struct FUN_00afd390_class
{
    const char* text;
    unsigned int flags;
    void* FUN_00afd390(const char*, int);
};
struct DirectoryArchive
{
    bool FindHashEntry(FUN_00afd390_class*, int*, int);
    bool FUN_00afac90(int, FUN_00afd390_class*, int);
    int FUN_00b01590(const char* root, const char* directory, const _FILETIME* since);
};
// Recursively walks root plus directory with FindFirstFileA, counting files written after since for which FUN_00afac90 returns true.
// @fnv 0x00b01590
int DirectoryArchive::FUN_00b01590(const char* root, const char* directory, const _FILETIME* since)
{
    int count3 = 0;
    char next[260];
    char data2[260];
    _WIN32_FIND_DATAA data5;
    int state;
    bool current;
    unsigned char result;
    FUN_00afd390_class meshName3;
    int countB;
    bool value;
    strcpy_s(next, 260, root);
    strcat_s(next, 260, directory);
    strcat_s(next, 260, "*.*");
    state = FindFirstFileA(next, &data5);
    if (state == -1)
        return 0;
    current = true;
    strcpy_s(data2, 260, directory);
    result = (unsigned char)strlen(data2);
    if (result > 1)
        data2[result - 1] = 0;
    meshName3.FUN_00afd390(data2, 2);
    value = false;
    if (FindHashEntry(&meshName3, &countB, 0))
        value = true;
    while (current)
    {
        if ((data5.dwFileAttributes & 0x10) && data5.cFileName[0] != '.')
        {
            strcpy_s(next, 260, directory);
            strcat_s(next, 260, data5.cFileName);
            strcat_s(next, 260, "\\");
            count3 += FUN_00b01590(root, next, since);
        }
        else if (value)
        {
            if (CompareFileTime(&data5.ftLastWriteTime, since) > 0)
            {
                FUN_00afd390_class fileName;
                fileName.FUN_00afd390(data5.cFileName, 0);
                if (FUN_00afac90(countB, &fileName, 0))
                    count3++;
            }
        }
        current = (bool)FindNextFileA(state, &data5);
    }
    FindClose(state);
    return count3;
}

// Looks up path with DAT_00fdf070, copies the match's last write time into out and closes the handle; returns whether the lookup succeeded.
// @fnv 0x00b01b60
bool FUN_00b01b60(const char* path, DirFileTime* apOutTime)
{
    void* h;
    DirectoryFindData findData;
    h = DAT_00fdf070(path, &findData);
    if (h != reinterpret_cast<void*>(-1))
    {
        *apOutTime = findData.ftLastWriteTime;
        FindClose(reinterpret_cast<int>(h));
        return true;
    }
    return false;
}

typedef int(__stdcall* FindFirstFileAFn)(const char* pattern, _WIN32_FIND_DATAA* findData);
typedef int(__stdcall* FindFirstFileA1Fn)(const char* pattern);

// Checks whether a file matching the given pattern exists by calling FindFirstFileA and closing the handle immediately.
// @fnv 0x00b01af0
bool __cdecl FUN_00b01af0(const char* pattern)
{
    _WIN32_FIND_DATAA findData;
    HANDLE handle = (HANDLE)((FindFirstFileAFn)(FindFirstFileA1Fn)&FindFirstFileA)(pattern, &findData);
    {
        bool found;
        if (handle != (HANDLE)-1)
        {
            found = true;
            FindClose((int)handle);
        }
        else
        {
            found = false;
        }
        return found;
    }
}

typedef long LONG;
typedef void* HANDLE;
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct FUN_00b02920_class
{
    void __thiscall FUN_00b02920(int unused);
};

// @fnv 0x00b02920
void __thiscall FUN_00b02920_class::FUN_00b02920(int unused)
{
    if (*(int*)((char*)this + 0x38) != *(int*)((char*)this + 0x34))
    {
        char* ptr = (char*)this + 8;
        WaitForSingleObject(*(HANDLE*)(ptr + 4), 0xffffffff);
        InterlockedDecrement((LONG*)ptr);
    }
    *(char*)((char*)this + 4) = 1;
    *(char*)((char*)this + 0x2c) = 0;
}
