// bscore/memorypool.cpp: MemoryPool (13 functions)

#include "memorypool_decls.h"

// @fnv 0x00aa6e00
void MemoryPool::PushFreeBlock(void* apBlock)
{
    MemoryPool__FreePoolBlock* block = reinterpret_cast<MemoryPool__FreePoolBlock*>(apBlock);
    block->m_pPreviousBlock = 0;
    block->pNext = m_pFreeBlockHead;
    if (m_pFreeBlockHead)
        m_pFreeBlockHead->m_pPreviousBlock = block;
    m_pFreeBlockHead = block;
    ++m_uiFreeBlockCount;
}

struct DummyClass_00aa6db0
{
    char pad[0x48];
    unsigned short* pData;  // +0x48
    unsigned int ItemUpdateArray;   // +0x4c

    unsigned int FindFree();
};

// @fnv 0x00aa6db0
unsigned int __fastcall FUN_00aa6db0(DummyClass_00aa6db0* pThis)
{
    for (unsigned int i = 0; i < pThis->ItemUpdateArray; ++i)
    {
        if (pThis->pData[i] == 0xFFFF)
        {
            return i;
        }
    }
    return 0xFFFFFFFF;
}

struct Node_00aa6e60
{
    Node_00aa6e60* prev;
    Node_00aa6e60* next;
};

struct FUN_00aa6e60_shell
{
    char pad[0x54];
    int count;
    void UnlinkNode(Node_00aa6e60* node);
};

// Unlinks node from its doubly linked list by patching its neighbours' pointers and decrementing count.
// @fnv 0x00aa6e60
void FUN_00aa6e60_shell::UnlinkNode(Node_00aa6e60* node)
{
    if (node->prev != 0)
    {
        node->prev->next = node->next;
    }
    if (node->next != 0)
    {
        node->next->prev = node->prev;
    }
    count--;
}

struct FUN_00aa6eb0_shell : public MemoryPool
{
    void FUN_00aa6eb0(unsigned int, bool);
};

struct Helper_00aa6eb0
{
    void FUN_00aa7260();
    void FreeMemory(unsigned int, void*);
};

struct DoublyLinkedListNode
{
    DoublyLinkedListNode* pPrev;
    DoublyLinkedListNode* pNext;
};

// @fnv 0x00aa6eb0
void FUN_00aa6eb0_shell::FUN_00aa6eb0(unsigned int aiPageIndex, bool abSortRequired)
{
    char* ppageAddress = *(char**)((char*)this + 0x4) + (aiPageIndex << 12);
    if (abSortRequired)
    {
        ((Helper_00aa6eb0*)this)->FUN_00aa7260();
    }
    DoublyLinkedListNode* pfirstFreeBlock = (DoublyLinkedListNode*)ppageAddress;
    unsigned int ientriesPerPage = 0x1000 / *(unsigned int*)((char*)this + 0x40);
    DoublyLinkedListNode* plastFreeBlock =
        (DoublyLinkedListNode*)(ppageAddress + (ientriesPerPage - 1) * *(unsigned int*)((char*)this + 0x40));

    if (pfirstFreeBlock->pPrev != 0)
    {
        pfirstFreeBlock->pPrev->pNext = plastFreeBlock->pNext;
    }
    else
    {
        *(DoublyLinkedListNode**)((char*)this + 0x8) = plastFreeBlock->pNext;
    }

    if (plastFreeBlock->pNext != 0)
    {
        plastFreeBlock->pNext->pPrev = pfirstFreeBlock->pPrev;
    }

    *(unsigned int*)((char*)this + 0x54) -= ientriesPerPage;
    ((Helper_00aa6eb0*)this)->FreeMemory(aiPageIndex, ppageAddress);
    (*(unsigned short**)((char*)this + 0x48))[aiPageIndex] = 0xffff;
    *(unsigned int*)((char*)this + 0x58) -= 1;
}

extern MemoryPool* DAT_011f67b8[];
extern MemoryPool* ms_pPoolAddressMap[];
struct FUN_00aa6980_stub
{
    char pad[4];
    unsigned int f4;
    char pad2[0x38];
    unsigned int f40;
    char pad3[0xc];
    unsigned int f50;
    void RegisterInPools();
};
// @fnv 0x00aa6980
void FUN_00aa6980_stub::RegisterInPools()
{
    unsigned int index = f40 >> 2;
    DAT_011f67b8[index] = (MemoryPool*)this;
    unsigned int count = f50 >> 24;
    if (f50 % 0x1000000 != 0)
        count++;
    {
        unsigned int base = f4 >> 24;
        for (unsigned int i = 0; i < count; i++)
            ms_pPoolAddressMap[base + i] = (MemoryPool*)this;
    }
}

struct FUN_00aa6c70_shell : public MemoryPool
{
    void Free(void*);
};

// @fnv 0x00aa6c70
void FUN_00aa6c70_shell::Free(void* apPointer)
{
    unsigned int ipageIndex;
    int u1, u2;
    if (!apPointer)
        return;
    m_kCriticalSection.Lock("MemoryPool::Free");
    PushFreeBlock(apPointer);
    ipageIndex = ((unsigned int)apPointer - (unsigned int)m_pPoolBase) >> 12;
    m_pPageBlockCounts[ipageIndex]--;
    {
        RecursiveSpinLock* pl = &m_kCriticalSection;
        pl->m_uiRecursionCount = pl->m_uiRecursionCount - 1;
        if (pl->m_uiRecursionCount == 0)
            pl->m_uiOwningThreadID = 0;
    }
}

namespace fnv_00aa6f90 {
struct FUN_00aa6f90_shell : public MemoryPool
{
    void FreeUnusedPagesForAllPools();
};

struct FUN_00aa6eb0_shell
{
    void FUN_00aa6eb0(unsigned int, bool);
};
struct Helper_00aa6eb0
{
    void FUN_00aa7260();
};
// @fnv 0x00aa6f90
void FUN_00aa6f90_shell::FreeUnusedPagesForAllPools()
{
    bool blistSorted;
    m_kCriticalSection.Lock("MemoryPool::FreeUnusedPagesForAllPools()");
    blistSorted = false;
    for (unsigned int i = 0; i < m_uiPageCount; i++)
    {
        if (m_pPageBlockCounts[i] == 0)
        {
            int u1, u2;
            if (!blistSorted)
            {
                ((Helper_00aa6eb0*)this)->FUN_00aa7260();
                blistSorted = true;
            }
            ((FUN_00aa6eb0_shell*)this)->FUN_00aa6eb0(i, false);
        }
    }
    {
        RecursiveSpinLock* pl = &m_kCriticalSection;
        pl->m_uiRecursionCount = pl->m_uiRecursionCount - 1;
        if (pl->m_uiRecursionCount == 0)
            pl->m_uiOwningThreadID = 0;
    }
}
}  // namespace fnv_00aa6f90

namespace fnv_00aa6aa0 {
struct FUN_00aa6aa0_shell : public MemoryPool
{
    void* Allocate(unsigned int);
};

struct Node_00aa6e60;
struct FUN_00aa6e60_shell
{
    void UnlinkNode(Node_00aa6e60*);
};
struct DummyClass_00aa6db0;
unsigned int __fastcall FUN_00aa6db0(DummyClass_00aa6db0*);
struct MemoryPool_PCP
{
    bool CommitPage(unsigned int, char*&);
};
// Locks the pool, allocates a new page and free list if empty, pops a free block, updates page usage, and returns the block or null.
// @fnv 0x00aa6aa0
void* FUN_00aa6aa0_shell::Allocate(unsigned int requested)
{
    void* pmem;
    {
        char* pfirstFreePage;
        {
            unsigned int ientriesPerPage;
            {
                unsigned int inewPageIndex;
                {
                    unsigned int i;
                    {
                        MemoryPool__FreePoolBlock* ptemp;
                        {
                            unsigned int ipageIndex;
                            {
                                int d1;
                                {
                                    int d2;
                                    {
                                        RecursiveSpinLock* l1;
                                        {
                                            RecursiveSpinLock* l2;
                                            {
                                                RecursiveSpinLock* l3;
                                                m_kCriticalSection.Lock("MemoryPool::Allocate");
                                                if (!m_pFreeBlockHead)
                                                {
                                                    inewPageIndex = FUN_00aa6db0((DummyClass_00aa6db0*)this);
                                                    if (inewPageIndex == -1)
                                                    {
                                                        l1 = &m_kCriticalSection;
                                                        l1->m_uiRecursionCount--;
                                                        if (!l1->m_uiRecursionCount)
                                                            l1->m_uiOwningThreadID = 0;
                                                        return 0;
                                                    }
                                                    pfirstFreePage = 0;
                                                    ientriesPerPage = 0x1000 / m_uiAllocationSize;
                                                    if (!((MemoryPool_PCP*)this)
                                                             ->CommitPage(inewPageIndex, pfirstFreePage))
                                                    {
                                                        l2 = &m_kCriticalSection;
                                                        l2->m_uiRecursionCount--;
                                                        if (!l2->m_uiRecursionCount)
                                                            l2->m_uiOwningThreadID = 0;
                                                        return 0;
                                                    }
                                                    m_pPageBlockCounts[inewPageIndex] = 0;
                                                    for (i = 0; i < ientriesPerPage; i++)
                                                        PushFreeBlock(pfirstFreePage + i * m_uiAllocationSize);
                                                    m_uiAllocatedPageCount++;
                                                    if (m_uiAllocatedPageCount > m_uiPeakPageCount)
                                                        m_uiPeakPageCount = m_uiAllocatedPageCount;
                                                }
                                                pmem = 0;
                                                if (m_pFreeBlockHead)
                                                {
                                                    pmem = m_pFreeBlockHead;
                                                    ptemp = m_pFreeBlockHead;
                                                    m_pFreeBlockHead = m_pFreeBlockHead->pNext;
                                                    ((FUN_00aa6e60_shell*)this)->UnlinkNode((Node_00aa6e60*)ptemp);
                                                    ipageIndex = (unsigned int)((char*)pmem - m_pPoolBase) >> 12;
                                                    m_pPageBlockCounts[ipageIndex]++;
                                                }
                                                l3 = &m_kCriticalSection;
                                                l3->m_uiRecursionCount--;
                                                if (!l3->m_uiRecursionCount)
                                                    l3->m_uiOwningThreadID = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return pmem;
}
}  // namespace fnv_00aa6aa0

struct MemoryManager
{
    void _DeallocateAlias(void* p);
};
extern MemoryManager g_memoryManager;

struct FUN_00aa6800
{
    char pad0[4];
    char* m_pPoolBase;
    char pad1[0x40];
    void* pBlock;
    void FreeAllocation();
    void ClearPoolSlots();
    ~FUN_00aa6800();
};

// @fnv 0x00aa6800
FUN_00aa6800::~FUN_00aa6800()
{
    if (m_pPoolBase)
    {
        FreeAllocation();
        ClearPoolSlots();
    }
    void* block = pBlock;
    g_memoryManager._DeallocateAlias(block);
}

void* _fnv_zlib_memset(void* dest, int value, unsigned int count);

struct PoolInfo
{
    unsigned int f0;
    unsigned int f1;
    unsigned int f2;
    unsigned int f3;
    unsigned int f4;
    unsigned int f5;
    unsigned int f6;
    unsigned int f7;
    unsigned int f8;
    unsigned int f9;
};

struct FUN_00aa6d00_holder
{
    unsigned int m0;
    char pad0[0x3c];
    unsigned int m40;
    unsigned int m44;
    char pad1[4];
    unsigned int m4c;
    unsigned int m50;
    unsigned int m54;
    unsigned int m58;
    PoolInfo GetPoolInfo();
};

// Builds a PoolInfo from the holder's fields, computing f1 from m4c and f9 as f5 divided by m40 minus m54.
// @fnv 0x00aa6d00
PoolInfo FUN_00aa6d00_holder::GetPoolInfo()
{
    PoolInfo info;
    _fnv_zlib_memset(&info, 0, sizeof(PoolInfo));
    info.f0 = m0;
    info.f1 = m4c * 2 + 0x80;
    info.f2 = m40;
    info.f3 = m50;
    info.f4 = m4c;
    info.f5 = m58 << 12;
    info.f6 = m58;
    info.f7 = m44;
    info.f8 = m54;
    info.f9 = info.f5 / m40 - m54;
    return info;
}

struct FUN_00aa7260_holder
{
    char pad0[8];
    void* ptr;
    char pad1[0x48];
    unsigned int count;
    void* SortList(void* p);
    void FUN_00aa7260();
};

// If count is greater than 1, replaces ptr with the result of SortList(ptr).
// @fnv 0x00aa7260
void FUN_00aa7260_holder::FUN_00aa7260()
{
    if (count > 1)
    {
        ptr = SortList(ptr);
    }
}

struct MemoryPool;
extern MemoryPool* ms_pPoolAddressMap[];
extern MemoryPool* DAT_011f67b8[];
extern int DAT_01000000;

struct FUN_00aa6a10_shell
{
    char pad0[4];
    unsigned int f4;
    char pad8[0x38];
    unsigned int f40;
    char pad44[0xc];
    unsigned int f50;

    void ClearPoolSlots();
};

// Clears a pool entry indexed by f40>>2 and zeroes count slots starting at f4>>24, where count is f50>>24 plus one if f50 has a remainder.
// @fnv 0x00aa6a10
void FUN_00aa6a10_shell::ClearPoolSlots()
{
    unsigned int count;
    unsigned int base = f40 >> 2;
    DAT_011f67b8[base] = 0;

    count = f50 >> 24;
    if (f50 % (unsigned int)&DAT_01000000)
        count++;

    unsigned int index = f4 >> 24;
    for (unsigned int i = 0; i < count; i++)
    {
        ms_pPoolAddressMap[index + i] = 0;
    }
}

namespace fnv_00aa66a0 {
struct MemoryManager
{
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;

struct PageRefCount66a0
{
    unsigned short iCount;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};

struct PoolSpinLock66a0
{
    unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    PoolSpinLock66a0()
    {
        m_uiOwningThreadID = 0;
        m_uiRecursionCount = 0;
    }
};

struct FUN_00aa66a0
{
    const char* pDescription;
    char* m_pPoolBase;
    void* m_pFreeBlockHead;
    unsigned int iReserved0C;
    unsigned int iReserved10;
    unsigned int iReserved14;
    unsigned int iReserved18;
    unsigned int iReserved1C;
    PoolSpinLock66a0 kLock;
    unsigned int iLockReserved28;
    unsigned int iLockReserved2C;
    unsigned int iLockReserved30;
    unsigned int iLockReserved34;
    unsigned int iLockReserved38;
    unsigned int iLockReserved3C;
    unsigned int m_uiAllocationSize;
    unsigned int m_uiPeakPageCount;
    unsigned short* m_pPageBlockCounts;
    unsigned int m_uiPageCount;
    unsigned int m_uiPoolSize;
    unsigned int m_uiFreeBlockCount;
    unsigned int m_uiAllocatedPageCount;
    unsigned int iFirstReserve;
    unsigned int iSecondReserve;
    FUN_00aa66a0(unsigned int aiBlockSize, unsigned int aiPoolSize, const char* apDesc);
    void FUN_00aa65b0();
    void RegisterInPools();
};

// Initializes a memory pool: rounds the block size, allocates the page ref-count array, computes reserve counts and sets each page count to 0xffff.
// @fnv 0x00aa66a0
FUN_00aa66a0::FUN_00aa66a0(unsigned int aiBlockSize, unsigned int aiPoolSize, const char* apDesc)
    : pDescription(apDesc), m_pPoolBase(0), m_pFreeBlockHead(0), m_uiPeakPageCount(0), m_pPageBlockCounts(0),
      m_uiPoolSize(aiPoolSize), m_uiFreeBlockCount(0), m_uiAllocatedPageCount(0)
{
    unsigned int nA;
    unsigned int i;
    m_uiPageCount = aiPoolSize >> 12;
    m_uiAllocationSize = aiBlockSize;
    if (m_uiAllocationSize)
        m_uiAllocationSize = (m_uiAllocationSize + 3) & ~3;
    FUN_00aa65b0();
    if (!m_pPoolBase)
        return;
    m_pPageBlockCounts = (unsigned short*)new PageRefCount66a0[aiPoolSize >> 12];
    nA = 0x1000 / m_uiAllocationSize;
    iFirstReserve = nA / 6;
    iSecondReserve = nA - iFirstReserve;
    for (i = 0; i < m_uiPageCount; i++)
        m_pPageBlockCounts[i] = 0xffff;
    RegisterInPools();
}
}  // namespace fnv_00aa66a0
