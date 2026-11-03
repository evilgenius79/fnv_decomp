
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_01017458;

struct FUN_0044b4b0_Class
{
    int* p;
    void FUN_0044b4b0();
};

// @fnv 0x0044b4b0
void FUN_0044b4b0_Class::FUN_0044b4b0()
{
    p = &DAT_01017458;
}

int __cdecl FinishScriptRunLock(void*);
struct FUN_0044b730_Class
{
    int* p;
    void FUN_0044b730();
};
// @fnv 0x0044b730
void FUN_0044b730_Class::FUN_0044b730()
{
    FinishScriptRunLock((char*)this + 0x18);
}

extern int __cdecl InitScriptRunLock(void*);

struct FUN_0044bbc0_Class
{
    void FUN_0044bbc0();
};

// @fnv 0x0044bbc0
void FUN_0044bbc0_Class::FUN_0044bbc0()
{
    InitScriptRunLock((char*)this + 0x18);
}

struct FUN_0044c1c0_Class
{
    bool __thiscall IsGreaterOrEqual(unsigned int a, unsigned int b);
};

// @fnv 0x0044c1c0
bool __thiscall FUN_0044c1c0_Class::IsGreaterOrEqual(unsigned int auiValue, unsigned int auiThreshold)
{
    return auiValue >= auiThreshold;
}

struct FUN_0044f200_Class
{
    int* p;
    void FUN_0044f200();
    void FilterListByQueueData();
};

// @fnv 0x0044f200
void FUN_0044f200_Class::FUN_0044f200()
{
    while (reinterpret_cast<int*>(this)[8])
        FilterListByQueueData();
}

struct RecursiveSpinLock
{
    void __thiscall Lock(const char*);
    void __thiscall Unlock();
};
struct FUN_0044bd60_Class
{
    void* m;
    void* n;
    void* o;
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    RecursiveSpinLock lock;
    void* __thiscall FUN_00449f80(int* a, void* b);
    bool __thiscall FUN_0044bd60(void* a, void* b);
};
bool __fastcall LookupBucket(void*);
// Locks the object's lock, calls FUN_00449f80 with a and b, passes the result to LookupBucket, unlocks, and returns that bool.
// @fnv 0x0044bd60
bool __thiscall FUN_0044bd60_Class::FUN_0044bd60(void* a, void* b)
{
    lock.Lock(0);
    bool r = LookupBucket(FUN_00449f80((int*)a, b));
    lock.Unlock();
    return r;
}

struct AutoMemHelper
{
    int m;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct InterfacedClass
{
    InterfacedClass();
    ~InterfacedClass();
    virtual void Interface();
};
struct CF_0081c630
{
    int v;
    CF_0081c630();
};
struct SL
{
    void* item;
    void* next;
    SL();
};
class bhkRigidBody;
template <class T> class LockFreeQueue
{
  public:
    class QueueDeleteManagerTag
    {
    };
};
template <class T> class ThreadInterfaceManager
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ThreadInterfaceManager(unsigned int);
};
extern const char _kThreadSafeStructuresSourceFile[];

struct FUN_0044c920 : InterfacedClass
{
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;
    FUN_0044c920(unsigned int a, unsigned int buckets, int c);
};

// Allocates bucket array, slot array and manager, and initializes the bucket count, parameter and counter fields.
// @fnv 0x0044c920
FUN_0044c920::FUN_0044c920(unsigned int auiSlotCount, unsigned int auiBucketCount, int aiParam)
{
    AutoMemHelper mem(6, true, _kThreadSafeStructuresSourceFile, 0x390);
    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new unsigned int[auiSlotCount * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(auiSlotCount);
}

struct FUN_0044c760_class : InterfacedClass
{
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_0044c760_class(unsigned int a, unsigned int b, unsigned int c);
};

// Initializes the object: allocates bucket and slot arrays, stores the bucket count and parameter, and creates the manager.
// @fnv 0x0044c760
FUN_0044c760_class::FUN_0044c760_class(unsigned int auiSlotCount, unsigned int auiBucketCount, unsigned int aiParam)
    : InterfacedClass()
{
    AutoMemHelper autoMemHelper(6, true, _kThreadSafeStructuresSourceFile, 0x390);

    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new unsigned int[3 * auiSlotCount];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(auiSlotCount);
}

void* __cdecl operator new(unsigned int);

struct FUN_006ec660 : InterfacedClass
{
    int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_006ec660(unsigned int a, unsigned int b, int c);
};

// Allocates the bucket array, slot array and manager from the given sizes, storing the counts and parameter.
// @fnv 0x006ec660
FUN_006ec660::FUN_006ec660(unsigned int auiSlotCount, unsigned int auiBucketCount, int aiParam)
{
    AutoMemHelper memHelper(6, true, _kThreadSafeStructuresSourceFile, 0x390);

    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new int[auiSlotCount * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(auiSlotCount);
}

template <class T> class NiPointer
{
};
class QueuedReference
{
};

template <> class LockFreeQueue<NiPointer<QueuedReference> >
{
  public:
    class LockFreeQueueEntry
    {
      public:
        void* m_pFirst;
        void* m_pSecond;
        LockFreeQueueEntry();
    };
};

typedef LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag FUN_0044b500_LockFreeQueueInterface;

template <> ThreadInterfaceManager<FUN_0044b500_LockFreeQueueInterface>::ThreadInterfaceManager(unsigned int);

struct FUN_0044b500 : public InterfacedClass
{
    LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueEntry* m_pHead;
    LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueEntry* m_pTail;
    void* m_pIntegerData;
    unsigned int* m_pSlots;
    ThreadInterfaceManager<FUN_0044b500_LockFreeQueueInterface>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_0044b500(unsigned int numBuckets, void* value);
};

// @fnv 0x0044b500
FUN_0044b500::FUN_0044b500(unsigned int numBuckets, void* value)
{
    AutoMemHelper autoMemHelper(6, true, _kThreadSafeStructuresSourceFile, 0xfd);

    m_iArrayLength = 0;
    m_pHead = new LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueEntry;
    m_pTail = m_pHead;
    m_pIntegerData = value;
    m_pSlots = new unsigned int[numBuckets * 2];
    m_pManager = new ThreadInterfaceManager<FUN_0044b500_LockFreeQueueInterface>(numBuckets);
}

extern int DAT_0108864c;

struct FUN_00906160
{
    InterfacedClass m_interface;
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    unsigned char m_kNode[8];

    FUN_00906160(int a, unsigned int b, int c);
};

// @fnv 0x00906160
FUN_00906160::FUN_00906160(int a, unsigned int auiBucketCount, int aiParam)
{
    reinterpret_cast<int*>(this)[0] = reinterpret_cast<int>(&DAT_0108864c);
    reinterpret_cast<SL*>(m_kNode)->SL::SL();

    AutoMemHelper helper(6, true, _kThreadSafeStructuresSourceFile, 0x390);

    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new unsigned int[a * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(a);
}

struct Item
{
    bool FUN_0044e550();
    bool FindEntry();
    bool FUN_00528bb0();
};
struct Iteration
{
    int unk00;
    unsigned int index;
    unsigned int value;
    bool FUN_006ebde0();
    bool IsFlagSet();
    void FUN_0044de40(bool);
    void FUN_0044de80(bool);
};
struct FUN_0044b8d0_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    RecursiveSpinLock lock;
    Item* FUN_00449f80(unsigned int, unsigned int*, unsigned int);
    Item* FUN_00449f80(unsigned int);
    unsigned int FUN_0044ddc0();
    bool ProcessIteration(Iteration*, unsigned int*, unsigned int, bool);
};
// Locks, walks the iteration to find a matching item via FUN_00449f80, stores its value in result, and returns whether the item passes FUN_00528bb0.
// @fnv 0x0044b8d0
bool FUN_0044b8d0_Class::ProcessIteration(Iteration* pIteration, unsigned int* puiResult, unsigned int extra,
                                          bool retry)
{
    lock.Lock(0);
    bool success = false;
    if (pIteration->FUN_006ebde0())
    {
        success = false;
    }
    else
    {
        while (true)
        {
            if (!pIteration->IsFlagSet())
            {
                success = FUN_00449f80(pIteration->index, &pIteration->value, extra)->FUN_0044e550();
                pIteration->FUN_0044de40(true);
            }
            else
            {
                success = FUN_00449f80(pIteration->index, &pIteration->value, extra)->FindEntry();
            }
            if (!success)
            {
                pIteration->index++;
                if (pIteration->index >= FUN_0044ddc0())
                {
                    pIteration->FUN_0044de80(true);
                }
                else if (retry)
                {
                    pIteration->FUN_0044de40(false);
                    continue;
                }
            }
            else
            {
                *puiResult = pIteration->value;
            }
            break;
        }
    }
    if (success)
    {
        success = FUN_00449f80(*puiResult)->FUN_00528bb0();
    }
    lock.Unlock();
    return success;
}

struct FUN_0044c000_Target
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual int v09(unsigned int a, unsigned int b, unsigned int c, unsigned int d) = 0;
};

struct FUN_0044c000_cls
{
    FUN_0044c000_Target* m_00;

    void InsertOrReplace(int x);
    void FUN_0044c000(unsigned int a, unsigned int b, unsigned char c);
};

// Calls v09 on m_00 with a, a, b, c and passes the result to InsertOrReplace.
// @fnv 0x0044c000
void FUN_0044c000_cls::FUN_0044c000(unsigned int uiValue, unsigned int b, unsigned char c)
{
    InsertOrReplace(m_00->v09(uiValue, uiValue, b, c));
}

struct FUN_0044c270 : InterfacedClass
{
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_0044c270(unsigned int a, unsigned int buckets, int c);
};

// Initializes the object: allocates bucket and slot arrays, stores the bucket count and parameter, and creates the manager.
// @fnv 0x0044c270
FUN_0044c270::FUN_0044c270(unsigned int a, unsigned int auiBucketCount, int aiParam)
{
    AutoMemHelper mem(6, true, _kThreadSafeStructuresSourceFile, 0x390);
    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new unsigned int[a * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(a);
}

struct BaseInterface
{
    virtual void Interface();
    void FUN_0044b4b0();
    ~BaseInterface()
    {
        FUN_0044b4b0();
    }
};
struct FUN_0044c3f0 : BaseInterface
{
    void* first;
    void* unused;
    void* second;
    void FUN_0044c480(int flag);
    ~FUN_0044c3f0();
};
// Calls FUN_0044c480(1), then frees the second and first pointers with operator delete.
// @fnv 0x0044c3f0
FUN_0044c3f0::~FUN_0044c3f0()
{
    FUN_0044c480(1);
    void* savedSecond = second;
    ::operator delete(savedSecond);
    void* savedFirst = first;
    ::operator delete(savedFirst);
}

extern const char _kThreadSafeStructuresSourceFile[];

struct TSNode;
struct TSNodePtr
{
    TSNode* p;
    TSNode* Get();
    void Clear();
};
struct TSNode
{
    int unk00;
    int unk04;
    TSNodePtr m_next;
};
struct TSManager
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    TSManager(unsigned int);
    ~TSManager();
    unsigned int GetParam();
};

struct TSHashTable
{
    void* vtbl;
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    TSNodePtr* m_pBuckets;
    int m_iParam;
    TSManager* m_pManager;
    int m_iArrayLength;
    int unk1C;
    RecursiveSpinLock m_lock;

    void FreeNode(TSNode* node);
    void FUN_0044c480(bool bNoRecreate);
};

// Locks the table, deletes m_pManager, frees every bucket node, and unless bNoRecreate recreates m_pManager with the saved param, then unlocks.
// @fnv 0x0044c480
void TSHashTable::FUN_0044c480(bool bNoRecreate)
{
    AutoMemHelper memContext2(6, true, _kThreadSafeStructuresSourceFile, 0x42c);
    if (m_pManager == 0)
        return;
    m_lock.Lock(0);
    unsigned int aParam = m_pManager->GetParam();
    delete m_pManager;
    m_pManager = 0;
    m_iArrayLength = 0;
    for (unsigned int i = 0; i < m_uiBuckets; i++)
    {
        TSNode* pNode = m_pBuckets[i].Get();
        m_pBuckets[i].Clear();
        while (pNode)
        {
            TSNode* next = pNode->m_next.Get();
            pNode->m_next.Clear();
            pNode->unk04 = 0;
            FreeNode(pNode);
            pNode = next;
        }
    }
    if (!bNoRecreate)
        m_pManager = new TSManager(aParam);
    m_lock.Unlock();
}

struct QueueEntry44c640
{
    bool TryA();
    bool TryB();
};
struct QueueIter44c640
{
    int unk00;
    unsigned int uiIndex;
    void* pItem;
    bool IsDone();
    bool IsAlt();
    void SetVisible(bool);
    void SetFinished(bool);
};
struct Queue44c640
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    RecursiveSpinLock lock;
    QueueEntry44c640* GetEntry(unsigned int idx, void** item, int param);
    unsigned int GetCount();
    bool TryGetNextEntry(QueueIter44c640* iter, void** out, int param, bool repeat);
};

// @fnv 0x0044c640
bool Queue44c640::TryGetNextEntry(QueueIter44c640* iter, void** out, int param, bool repeat)
{
    lock.Lock(0);
    bool result = false;
    if (iter->IsDone())
    {
        result = false;
    }
    else
    {
        while (1)
        {
            if (!iter->IsAlt())
            {
                result = GetEntry(iter->uiIndex, &iter->pItem, param)->TryA();
                iter->SetVisible(true);
            }
            else
            {
                result = GetEntry(iter->uiIndex, &iter->pItem, param)->TryB();
            }
            if (!result)
            {
                iter->uiIndex++;
                if (iter->uiIndex >= GetCount())
                {
                    iter->SetFinished(true);
                }
                else if (repeat)
                {
                    iter->SetVisible(false);
                    continue;
                }
            }
            else
            {
                *out = iter->pItem;
            }
            break;
        }
    }
    lock.Unlock();
    return result;
}

class C44C8E0Hasher
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual unsigned int Hash(int iKey, int iKeyAgain, int iSize);
};

class C44C8E0Map
{
  public:
    C44C8E0Hasher* m_pkHasher;

    int GetBucket(unsigned int uiHash);
    int LookupBucket(int iKey, int iSize);
};

// Computes the hash of iKey with the map's hasher and returns the bucket index for that hash.
// @fnv 0x0044c8e0
int C44C8E0Map::LookupBucket(int iKey, int iSize)
{
    return GetBucket(m_pkHasher->Hash(iKey, iKey, iSize));
}

void __cdecl FormHeap_Free(void* apMemory);

struct CleanupBaseDtor
{
    virtual void unk00();
    ~CleanupBaseDtor();
};

struct FUN_0044cae0_cls : CleanupBaseDtor
{
    int m_04;
    int unk08;
    int m_0c;

    void Shutdown(int aFlag);

    ~FUN_0044cae0_cls();
};

// @fnv 0x0044cae0
FUN_0044cae0_cls::~FUN_0044cae0_cls()
{
    Shutdown(1);
    void* pC_ = (void*)m_0c;
    FormHeap_Free(pC_);
    void* p4 = (void*)m_04;
    FormHeap_Free(p4);
}

struct Dispatch
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A(unsigned int value);
    void FUN_0044dde0(unsigned int* argument);
};
void __cdecl FormHeap_Free(void* object);
// Calls Slot0A with the value pointed to by argument, then passes argument to FormHeap_Free.
// @fnv 0x0044dde0
void Dispatch::FUN_0044dde0(unsigned int* puiValue)
{
    Slot0A(*puiValue);
    void* target = puiValue;
    FormHeap_Free(target);
}

struct FUN_0044de20_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0C;
    bool IsFlagSet();
};
// @fnv 0x0044de20
bool FUN_0044de20_cls::IsFlagSet()
{
    return (this->unk0C & 1) ? true : false;
}

struct FUN_006661e0 : InterfacedClass
{
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    void FUN_0044c480(int flag);
    ~FUN_006661e0();
};
// Calls FUN_0044c480(1), then deletes m_pBuckets and m_pSlots.
// @fnv 0x006661e0
FUN_006661e0::~FUN_006661e0()
{
    FUN_0044c480(1);
    delete m_pBuckets;
    delete m_pSlots;
}

struct FUN_006ec870 : InterfacedClass
{
    int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;

    void __thiscall FUN_0044c480(int value);
    ~FUN_006ec870();
};

// @fnv 0x006ec870
FUN_006ec870::~FUN_006ec870()
{
    FUN_0044c480(1);
    delete m_pBuckets;
    delete m_pSlots;
}

class AutoMemHelper44B
{
  public:
    AutoMemHelper44B(int iPool, bool bEnable, const char* pcFile, int iLine);
    ~AutoMemHelper44B();

    int m_iSaved;
};

extern const char g_pcFile44B[];

class Container44B;

class Iterator44B
{
  public:
    Iterator44B(Container44B* pkContainer, void** ppvFirst, void** ppvLast);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class Container44B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppvBuckets;

    Iterator44B* CreateBucketIterator(int iSubBucketIndex);
};

// @fnv 0x0044b660
Iterator44B* Container44B::CreateBucketIterator(int iBucketIndex)
{
    AutoMemHelper44B kHelper(6, true, g_pcFile44B, 0x95);
    return new Iterator44B(this, &m_ppvBuckets[iBucketIndex * 2], &m_ppvBuckets[iBucketIndex * 2 + 1]);
}

void* __cdecl FUN_00401460(void*, const void*, unsigned int);

struct FUN_0044f220_Queue
{
    void* vtable;
    void* m_pData;
    int __thiscall FUN_0044f3e0();
    void __thiscall FUN_0044dde0(void*);
};

struct FUN_0044f220_Node
{
    int unk00;
    int unk04;
    FUN_0044f220_Node* __thiscall FUN_00726070();
    void __thiscall FUN_006ecd40(void*);
};

struct FUN_0044f220_Class : FUN_0044f200_Class
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_0044f220_Node* m_pHead;
    int m_iArrayLength;
};

// Copies the queue's data into a temporary array, keeps only list nodes whose address appears in it, relinks them, and stores the kept count.
// @fnv 0x0044f220
void FUN_0044f200_Class::FilterListByQueueData()
{
    AutoMemHelper guard5(6, true, _kThreadSafeStructuresSourceFile, 0x362);
    int numSlots = ((FUN_0044f220_Queue*)p)->FUN_0044f3e0() * 3;
    unsigned int* pArray = new unsigned int[numSlots];
    FUN_00401460(pArray, ((FUN_0044f220_Queue*)p)->m_pData, numSlots * 4);
    FUN_0044f220_Node* pTail = 0;
    int iCount2 = 0;
    while (((FUN_0044f220_Class*)this)->m_pHead != 0)
    {
        FUN_0044f220_Node* pEntry2 = ((FUN_0044f220_Class*)this)->m_pHead;
        ((FUN_0044f220_Class*)this)->m_pHead = ((FUN_0044f220_Class*)this)->m_pHead->FUN_00726070();
        bool found4 = false;
        for (unsigned int i2 = 0; i2 < (unsigned int)numSlots; ++i2)
        {
            if ((unsigned int)pEntry2 == pArray[i2])
            {
                found4 = true;
                break;
            }
        }
        if (found4)
        {
            pEntry2->FUN_006ecd40(pTail);
            pTail = pEntry2;
            ++iCount2;
        }
        else
        {
            pEntry2->FUN_006ecd40(0);
            ((FUN_0044f220_Queue*)p)->FUN_0044dde0(pEntry2);
        }
    }
    delete[] pArray;
    ((FUN_0044f220_Class*)this)->m_pHead = pTail;
    ((FUN_0044f220_Class*)this)->m_iArrayLength = iCount2;
}

struct FUN_00665cb0 : InterfacedClass
{
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_00665cb0(unsigned int a, unsigned int buckets, int c);
};

// Allocates bucket array, slot array and manager, and stores the bucket count and parameter.
// @fnv 0x00665cb0
FUN_00665cb0::FUN_00665cb0(unsigned int a, unsigned int uiBucketCount, int iParam)
{
    AutoMemHelper mem(6, true, _kThreadSafeStructuresSourceFile, 0x390);
    m_iArrayLength = 0;
    m_uiBuckets = uiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new unsigned int[a * 3];
    m_iParam = iParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(a);
}

struct HashBase44c1e0
{
    virtual void Interface();
    ~HashBase44c1e0();
};
struct HashMap44c1e0 : HashBase44c1e0
{
    unsigned int* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    void FUN_0044c480(int flag);
    ~HashMap44c1e0();
};
// Destructor that calls FUN_0044c480(1) and deletes m_pBuckets and m_pSlots.
// @fnv 0x0044c1e0
HashMap44c1e0::~HashMap44c1e0()
{
    FUN_0044c480(1);
    delete m_pBuckets;
    delete m_pSlots;
}
