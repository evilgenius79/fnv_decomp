// bscore/scrapheap.cpp: ScrapHeapBuffer, SHStub (21 functions)

#include "scrapheap_decls.h"

const char kScrapHeapManagerReleaseBufferLabel[] = "ScrapHeapManager::ReleaseBuffer()";

// @fnv 0x00AA53F0
ScrapHeapBuffer::ScrapHeapBuffer()
{
    Init(0x10000);
}

// @fnv 0x00AA5460
ScrapHeapBuffer::~ScrapHeapBuffer()
{
    unsigned int unused[2];
    ScrapHeapManager::Instance().ReleaseBuffer(m_pHeapBase, static_cast<unsigned int>(m_pBufferLimit - m_pHeapBase));
    m_pHeapBase = 0;
    m_pCurrentPosition = 0;
}

// @fnv 0x00AA57B0
void ScrapHeapBuffer::Init(unsigned int size)
{
    unsigned int unused[2];
    m_pHeapBase = ScrapHeapManager::Instance().RequestBuffer(size);
    m_pCurrentPosition = m_pHeapBase;
    m_pBufferLimit = m_pHeapBase + size;
    m_pBufferHeader = 0;
}

const char kScrapHeapManagerRequestBufferLabel[] = "ScrapHeapManager::RequestBuffer()";

struct FUN_00aa5410_Helper
{
    ScrapHeapBuffer* InitWithAlignedSize(unsigned int size);
};

// Rounds size up to a 64KB multiple when the low 16 bits are set, then calls Init(size) and returns this.
// @fnv 0x00aa5410
ScrapHeapBuffer* FUN_00aa5410_Helper::InitWithAlignedSize(unsigned int size)
{
    size = (size & 0xFFFF) ? ((size + 0x10000) & 0xFFFF0000) : size;
    reinterpret_cast<ScrapHeapBuffer*>(this)->Init(size);
    return reinterpret_cast<ScrapHeapBuffer*>(this);
}

// Zeroes the int fields at offsets 0x200, 0x204 and 0x220/0x224 of pThis and returns pThis.
// @fnv 0x00aa5860
void* __fastcall FUN_00aa5860(char* pThis)
{
    *(int*)(pThis + 0x200) = 0;
    *(int*)(pThis + 0x204) = 0;
    int* p = (int*)(pThis + 0x220);
    *p = 0;
    p[1] = 0;
    return pThis;
}

struct FUN_00aa5e90_dummy
{
    void method(char* pBase, unsigned int uiTotalSize, unsigned int uiFreeSize);
};

// If FreeTailOfBlock is a free function with __fastcall, MSVC /Od spills both ecx and edx (`sub esp, 8`).
// Here only `push ecx` and `mov [ebp-4], ecx` is emitted, which means only 1 register parameter or a __thiscall method,
// OR a __stdcall function with one unreferenced local variable!
// Wait: in __stdcall, `push ecx` reserves 4 bytes of stack, and `mov [ebp-4], ecx` would NOT happen unless it's `this`.
// Wait: no! If it's a free function named FreeTailOfBlock, how can `mov [ebp-4], ecx` be emitted without `mov [ebp-8], edx`?
// In MSVC x86, `__fastcall` with ONLY ONE register parameter (and the rest... no, 2nd param goes in edx unless it's > 4 bytes, e.g. a struct of size > 4 or double/int64!).
// Wait: if parameter 1 is `void*` ( goes in ecx ), and parameter 2 is a 12-byte struct (passed on stack! Because > 4 bytes, it does not fit in edx!), then edx is not used!
// Let's check: in MSVC `__fastcall`, arguments <= 4 bytes go into ECX then EDX. If an argument is larger than 4 bytes (like a struct of 12 bytes, or 8 bytes), it is passed on the stack, and does NOT use EDX (and if a third 4-byte arg followed an 8-byte arg, THAT would go in EDX, so all remaining args must make up the 12 bytes, e.g. one 12-byte struct!).
struct Args12
{
    char* a;
    unsigned int b;
    unsigned int c;
};

// Frees the trailing portion of a memory block with VirtualFree using MEM_DECOMMIT.
// @fnv 0x00aa5e90
void __fastcall FreeTailOfBlock(void* pThis, Args12 args)
{
    VirtualFree(args.a + args.b - args.c, args.c, 0x4000);
}

struct FUN_00aa54a0_s
{
    struct Header
    {
        unsigned int uiSize;
        Header* pPrev;
    };
    char* pBase;
    char* pCurrent;
    char* pCommitEnd;
    Header* pLast;
    void* FUN_00aa54a0(unsigned int aiSize, unsigned int aAlignment);
};

// @fnv 0x00aa54a0
void* FUN_00aa54a0_s::FUN_00aa54a0(unsigned int aiSize, unsigned int aAlignment)
{
    void* pmem = 0;
    char* pmemLoc = pCurrent + 8;
    unsigned int uialignmentOffset = aAlignment ? (aAlignment - 1) & (unsigned int)pmemLoc : 0;
    Header* pheader;
    if (uialignmentOffset)
    {
        pmemLoc = aAlignment - uialignmentOffset + pmemLoc;
        pheader = (Header*)(pmemLoc - 8);
    }
    else
    {
        pheader = (Header*)pCurrent;
    }
    char* pnextStackLoc = pmemLoc + aiSize;
    if (pnextStackLoc >= pCommitEnd)
    {
        unsigned int imemAllocated = pCommitEnd - pBase;
        if (imemAllocated < 0x800000)
        {
            unsigned int imemNeeded = pnextStackLoc - pCommitEnd;
            unsigned int imemToCommit = imemAllocated;
            unsigned int itotalMemoryAfterCommit = imemAllocated + imemToCommit;
            while (imemToCommit < imemNeeded)
            {
                itotalMemoryAfterCommit <<= 1;
                imemToCommit = itotalMemoryAfterCommit - imemAllocated;
            }
            ScrapHeapManager::Instance().ReleaseBufferContents(pBase, pCommitEnd - pBase, imemToCommit);
            pCommitEnd += imemToCommit;
        }
    }
    if (pnextStackLoc < pCommitEnd)
    {
        pheader->uiSize = aiSize;
        pheader->pPrev = pLast;
        pLast = pheader;
        pCurrent = pnextStackLoc;
        pmem = pmemLoc;
        int iUnused0;
        int iUnused1;
    }
    return pmem;
}

struct SHHeader
{
    unsigned int size;
    SHHeader* prev;
};
struct SHStub
{
    char* pBase;
    char* pCur;
    char* pCommitEnd;
    SHHeader* pLast;
    void FUN_00aa5610(void* apMem);
};
// Marks the block header before apMem as freed, advances pCur past the last live block, and releases half the committed memory when free space exceeds it.
// @fnv 0x00aa5610
void SHStub::FUN_00aa5610(void* apMem)
{
    SHHeader* pheader;
    unsigned int imemFree;
    unsigned int imemCommited;
    unsigned int imemToFree;
    {
        unsigned int uideallocated;
        char* pbaseLoc;
    }
    if (apMem == 0)
        return;
    pheader = (SHHeader*)((char*)apMem - 8);
    if ((pheader->size & 0x80000000) == 0)
    {
        pheader->size |= 0x80000000;
        for (;;)
        {
            if (pLast == 0)
            {
                pCur = pBase;
                break;
            }
            else if ((pLast->size & 0x80000000) == 0)
            {
                pCur = (char*)pLast + pLast->size + 8;
                break;
            }
            else
            {
                pLast = pLast->prev;
            }
        }
        imemFree = pCommitEnd - pCur;
        imemCommited = pCommitEnd - pBase;
        imemToFree = imemCommited >> 1;
        if (imemFree > imemToFree && imemCommited > 0x10000)
        {
            ScrapHeapManager::Instance().FreeTailOfBlock(pBase, pCommitEnd - pBase, imemToFree);
            pCommitEnd -= imemToFree;
        }
    }
}

struct FUN_00aa59b0_shell : public ScrapHeapManager
{
    char* FUN_00aa59b0(unsigned int*);
};

// @fnv 0x00aa59b0
char* FUN_00aa59b0_shell::FUN_00aa59b0(unsigned int* auiRequestedSize)
{
    if (count == 0)
    {
        return AllocateBuffer(*auiRequestedSize);
    }
    char* ilargestBufferSize;
    int ilargestBufferIndex;
    RecursiveSpinLock* pbuffer;
    RecursiveSpinLock* pbuffer1;
    char* i;
    RecursiveSpinLock* pbuffer2;
    char* iUnused0;
    unsigned int iUnused1;
    unsigned int pLockA;
    int pLockB;
    unsigned int pLockC;
    bufferLock.Lock(kScrapHeapManagerRequestBufferLabel);
    if (count == 0)
    {
        i = AllocateBuffer(*auiRequestedSize);
        pbuffer2 = &bufferLock;
        pbuffer2->listCount--;
        if (pbuffer2->listCount == 0)
        {
            pbuffer2->lockWord = 0;
        }
        return i;
    }
    pLockA = 0;
    pLockC = 0;
    for (iUnused1 = 0; iUnused1 < count; iUnused1++)
    {
        if (entries[iUnused1].size >= *auiRequestedSize)
        {
            *auiRequestedSize = entries[iUnused1].size;
            ilargestBufferSize = entries[iUnused1].buffer;
            RemoveEntry(iUnused1);
            pbuffer1 = &bufferLock;
            pbuffer1->listCount--;
            if (pbuffer1->listCount == 0)
            {
                pbuffer1->lockWord = 0;
            }
            return ilargestBufferSize;
        }
        if (entries[iUnused1].size > pLockC)
        {
            pLockC = entries[iUnused1].size;
            pLockA = iUnused1;
        }
    }
    iUnused0 = entries[pLockA].buffer;
    RemoveEntry(pLockA);
    ReleaseBufferContents(iUnused0, pLockC, *auiRequestedSize - pLockC);
    pbuffer = &bufferLock;
    pbuffer->listCount--;
    if (pbuffer->listCount == 0)
    {
        pbuffer->lockWord = 0;
    }
    return iUnused0;
}

struct FUN_00aa5b70_shell : public ScrapHeapManager
{
    void FUN_00aa5b70(char*, unsigned int);
};

// @fnv 0x00aa5b70
void FUN_00aa5b70_shell::FUN_00aa5b70(char* apBuffer, unsigned int aiCommittedSize)
{
    int iUnused0;
    int iUnused1;
    if (count >= 64)
    {
        FreeBuffer(apBuffer, aiCommittedSize);
    }
    bufferLock.Lock(kScrapHeapManagerReleaseBufferLabel);
    if (count >= 64)
    {
        FreeBuffer(apBuffer, aiCommittedSize);
        RecursiveSpinLock* pLock = &bufferLock;
        pLock->listCount--;
        if (pLock->listCount == 0)
        {
            pLock->lockWord = 0;
        }
    }
    else
    {
        entries[count].buffer = apBuffer;
        entries[count].size = aiCommittedSize;
        count++;
        totalSize += aiCommittedSize;
        RecursiveSpinLock* pLock2 = &bufferLock;
        pLock2->listCount--;
        if (pLock2->listCount == 0)
        {
            pLock2->lockWord = 0;
        }
    }
}

struct FUN_00aa5e30_shell : public ScrapHeapManager
{
    void CommitMemory(char*, unsigned int, unsigned int);
};

__declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned long, unsigned long, unsigned long);

// @fnv 0x00aa5e30
void FUN_00aa5e30_shell::CommitMemory(char* apBuffer, unsigned int aiBufferSize, unsigned int aiAdditionalSize)
{
    int imemoryPass = 0;
    while (!(bool)(int)(VirtualAlloc(apBuffer + aiBufferSize, aiAdditionalSize, 0x1000, 4) != 0))
    {
        bool ballowSystemAlloc = true;
        imemoryPass = g_memoryManager.HandleAllocationFailure(0, imemoryPass, &ballowSystemAlloc);
    }
}

namespace fnv_00aa58d0 {
struct FUN_00aa58d0_Alloc
{
    void* Allocate(unsigned int);
};

struct FUN_00aa5860
{
    char data[0x240];
    FUN_00aa5860();
    // Overloaded operator new that forwards the requested size to the memory manager's Allocate method and returns the allocated pointer.
// @fnv 0x00aa58d0
    void* operator new(unsigned int uiSize)
    {
        return ((FUN_00aa58d0_Alloc*)&g_memoryManager)->Allocate(uiSize);
    }
    void operator delete(void*);
};

extern FUN_00aa5860* DAT_011f63b4;

void FUN_00aa58d0()
{
    DAT_011f63b4 = new FUN_00aa5860;
}
}  // namespace fnv_00aa58d0

struct FUN_00aa55e0_s : ScrapHeapBuffer
{
    void* AllocateWithSize(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};

// Allocates a block using the first and fourth arguments and returns the resulting pointer.
// @fnv 0x00aa55e0
void* FUN_00aa55e0_s::AllocateWithSize(unsigned int a, unsigned int uiUnused2, unsigned int uiUnused3, unsigned int d)
{
    void* result = Allocate(a, d);
    return result;
}

struct FUN_00aa5710_shell
{
    int __thiscall FUN_00aa5710(int param);
};

// @fnv 0x00aa5710
int __thiscall FUN_00aa5710_shell::FUN_00aa5710(int param)
{
    if (param == 0)
        return 0;
    int* p = (int*)(param - 8);
    return *p & 0x7fffffff;
}

struct FUN_00aa5740_holder
{
    char* start;
    char* cur;
    unsigned int pad8;
    unsigned int used;
    void Reset(unsigned int size);
};

// Resets the holder by pointing cur at start and clearing used.
// @fnv 0x00aa5740
void FUN_00aa5740_holder::Reset(unsigned int size)
{
    cur = start;
    used = 0;
}

struct ScrapBlock
{
    unsigned int flags;
    ScrapBlock* next;
};

struct FUN_00aa5800_s : ScrapHeapBuffer
{
    unsigned int FUN_00aa5800();
};

// @fnv 0x00aa5800
unsigned int FUN_00aa5800_s::FUN_00aa5800()
{
    unsigned int count = 0;
    if (m_pCurrentPosition != m_pHeapBase)
    {
        ScrapBlock* block = (ScrapBlock*)m_pBufferHeader;
        while (block)
        {
            if (!(block->flags & 0x80000000))
                count++;
            block = block->next;
        }
    }
    return count;
}

struct FUN_00aa58b0_holder
{
    void FreeAllBuffers();
    void FUN_00aa58b0();
};

// @fnv 0x00aa58b0
void FUN_00aa58b0_holder::FUN_00aa58b0()
{
    FreeAllBuffers();
}

struct FUN_00aa5f30_holder
{
    void FUN_00aa5f30(char* apBuffer, unsigned int aiCommittedSize);
};

// @fnv 0x00aa5f30
void FUN_00aa5f30_holder::FUN_00aa5f30(char* apBuffer, unsigned int aiCommittedSize)
{
    VirtualFree(apBuffer, 0, 0x8000);
}

struct MemoryManagerDealloc
{
    void Deallocate(void*);
};
struct FUN_00aa5950_s
{
    ~FUN_00aa5950_s();
    static void operator delete(void* p)
    {
        ((MemoryManagerDealloc*)&g_memoryManager)->Deallocate(p);
    }
};
extern FUN_00aa5950_s* DAT_011f63b4;
// Deletes the object pointed to by DAT_011f63b4 and sets the pointer to null.
// @fnv 0x00aa5950
void FUN_00aa5950()
{
    delete DAT_011f63b4;
    DAT_011f63b4 = 0;
}

namespace fnv_00866d10 {
struct FUN_00aa5860 : public ScrapHeapManager
{
    FUN_00aa5860();
    unsigned char tail[0x18];
};
extern ScrapHeapManager* DAT_011f63b4;
// Returns the global ScrapHeapManager singleton, allocating a FUN_00aa5860 instance on first call if DAT_011f63b4 is null.
// @fnv 0x00866d10
ScrapHeapManager* GetScrapHeapManager()
{
    if (DAT_011f63b4 == 0)
        DAT_011f63b4 = new FUN_00aa5860;
    return DAT_011f63b4;
}
}  // namespace fnv_00866d10

struct MySpinLock : RecursiveSpinLock
{
    void Unlock()
    {
        listCount--;
        if (listCount == 0)
            lockWord = 0;
    }
};

struct FUN_00aa5c80_shell : ScrapHeapManager
{
    void FreeAllBuffers();
};

// Frees every buffer in the entries array, then resets count and totalSize to zero and unlocks bufferLock.
// @fnv 0x00aa5c80
void FUN_00aa5c80_shell::FreeAllBuffers()
{
    if (!count)
        return;

    unsigned int i;
    Entry entry;

    bufferLock.Lock("ScrapHeapManager::FreeAllBuffers()");

    for (i = 0; i < count; i++)
    {
        FreeBuffer(entries[i].buffer, entries[i].size);
    }

    count = 0;
    totalSize = 0;
    ((MySpinLock&)bufferLock).Unlock();
}

namespace fnv_00aa5d40 {
struct MySpinLock : RecursiveSpinLock
{
    void Unlock()
    {
        listCount--;
        if (listCount == 0)
            lockWord = 0;
    }
};

struct TwoPointerRecord
{
    void* p1;
    void* p2;
};

struct FUN_00aa5d40_shell : ScrapHeapManager
{
    unsigned int FreeBuffers(unsigned int aiSize);
};

// Frees buffers from the end of the entry list until at least aiSize bytes are freed, updating count and totalSize, and returns the freed size.
// @fnv 0x00aa5d40
unsigned int FUN_00aa5d40_shell::FreeBuffers(unsigned int aiSize)
{
    if (!count)
        return 0;

    bufferLock.Lock("ScrapHeapManager::FreeBuffers()");

    unsigned int ifreedSize = 0;
    unsigned int iElementIndex;

    {
        TwoPointerRecord tempAutoEvent;
    }

    while (count && ifreedSize < aiSize)
    {
        iElementIndex = count - 1;
        ifreedSize += entries[iElementIndex].size;
        FreeBuffer(entries[iElementIndex].buffer, entries[iElementIndex].size);
        count--;
    }

    totalSize -= ifreedSize;
    ((MySpinLock&)bufferLock).Unlock();
    return ifreedSize;
}
}  // namespace fnv_00aa5d40

namespace fnv_00aa5770 {
struct ScrapBlock
{
    int unk00;
    ScrapBlock* next;
};

struct ScrapHeap_00aa5770
{
    char* m_pHeapBase;
    char* m_pCurrentPosition;
    char* m_pBufferLimit;
    void* m_pBufferHeader;
    unsigned int m_uiBufferSize;

    void FUN_00aa5770();
};

// Walks the m_pBufferHeader linked list of ScrapBlock entries when m_pCurrentPosition differs from m_pHeapBase.
// @fnv 0x00aa5770
void ScrapHeap_00aa5770::FUN_00aa5770()
{
    if (this->m_pCurrentPosition != this->m_pHeapBase)
    {
        ScrapBlock* block = (ScrapBlock*)this->m_pBufferHeader;
        if (0)
        {
        }
        if (0)
        {
        }
        while (block)
        {
            block = block->next;
        }
    }
}
}  // namespace fnv_00aa5770

struct FUN_00aa5ec0_shell : public ScrapHeapManager
{
    char* FUN_00aa5ec0(unsigned int);
};

// Allocates a 8MB buffer via VirtualAlloc, then retries with aiInitialSize on failure, calling g_memoryManager.HandleAllocationFailure each time.
// @fnv 0x00aa5ec0
char* FUN_00aa5ec0_shell::FUN_00aa5ec0(unsigned int aiInitialSize)
{
    char* pbuffer = (char*)VirtualAlloc(0, 0x800000u, 0x2000u, 4);
    int imemoryPass = 0;
    while (!(bool)(int)(VirtualAlloc(pbuffer, aiInitialSize, 0x1000u, 4) != 0))
    {
        bool ballowSystemAlloc = true;
        imemoryPass = g_memoryManager.HandleAllocationFailure(0, imemoryPass, &ballowSystemAlloc);
    }
    return pbuffer;
}
