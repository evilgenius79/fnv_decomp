// bsshader/bsbatchrenderer.cpp: BSBatchRenderer, BSBatchRenderer__GeometryGroup, Thing, BSBatchRenderer_AlphaDepth and more (43 functions)

#include "bsbatchrenderer_types_BSBatchRenderer.h"
#include "bsbatchrenderer_private.h"

// @fnv 0x00b9a490
void BSBatchRenderer__GeometryGroup::ClearPassTextureSlots()
{
    BSBatchRenderer__PassList* list = &PassTextureSlotCollection;
    list->ResetPassList();
    list->m_pCachedListItems = list->pHead;
    list->pHead = 0;
    list->pTail = 0;
    list->Allocator.ItemUpdateArray = 0;
    if (m_pGroupRenderer)
        m_pGroupRenderer->ClearAllGroups(0);
    m_usPassCountLocal = 0;
}

// Frees the owned object pointer if set and clears it to null.
// @fnv 0x00b9a410
BSBatchRenderer__GeometryGroup::~BSBatchRenderer__GeometryGroup()
{
    if (m_pGroupRenderer)
    {
        delete m_pGroupRenderer;
        m_pGroupRenderer = 0;
    }
}

// @fnv 0x00b9a090
bool BSBatchRenderer::FindPassBucket(unsigned int& uiGroupKey, int& bucketIndex, bool& alpha)
{
    bool result = true;
    unsigned int groupIndex = 0;
    if (!uiGroupKey)
        result = FindOrCreateGroupBucket(uiGroupKey, bucketIndex);
    else
    {
        reinterpret_cast<NiTPointerMap<unsigned int, TESObjectREFR*>*>(&m_kGroupIndexMap)
            ->GetAt(uiGroupKey, reinterpret_cast<TESObjectREFR*&>(groupIndex));
        if (!FindBucketIndex(groupIndex, bucketIndex))
            result = FindOrCreateGroupBucket(uiGroupKey, bucketIndex);
    }
    if (result)
    {
        reinterpret_cast<NiTPointerMap<unsigned int, TESObjectREFR*>*>(&m_kGroupIndexMap)
            ->GetAt(uiGroupKey, reinterpret_cast<TESObjectREFR*&>(groupIndex));
        BSBatchRenderer__PassGroup* groups = reinterpret_cast<BSBatchRenderer__PassGroup*>(m_pPassBucketEntries);
        BSBatchRenderer__RenderPass* pass =
            reinterpret_cast<BSBatchRenderer__RenderPass*>(groups[groupIndex].buckets[bucketIndex].m_pRenderPass);
        alpha = pass->pInfo->bAlpha;
    }
    return result;
}

// Scans the five 20-byte bucket slots of a group for a non-null pointer and stores the matching slot index in bucketIndex.
// @fnv 0x00b98ae0
bool BSBatchRenderer::FindBucketIndex(unsigned int groupIndex, int& bucketIndex)
{
    int i = 0;
    do
    {
        unsigned int offset = groupIndex * 104 + i * 20;
        if (*reinterpret_cast<void**>(reinterpret_cast<char*>(m_pPassBucketEntries) + offset + 4))
        {
            bucketIndex = i;
            i = 5;
        }
        ++i;
    } while (i < 5);
    return i == 6;
}
// @fnv 0x00b9aec0
void BSBatchRenderer::ReleaseGeometryGroups()
{
    int count = m_iActiveGroupCount - 1;
    m_iActiveGroupCount = BSBatchRenderer_Max(0, count);
    if (m_iActiveGroupCount <= 0)
    {
        if (!m_pAlphaGeometryGroups[0]->m_usPassCountLocal)
        {
            reinterpret_cast<BSBatchRenderer__AlphaList*>(&AlphaGeometryList[0])->Remove(m_pAlphaGeometryGroups[0]);
            BSBatchRenderer__GeometryGroup* group = m_pAlphaGeometryGroups[0];
            if (group)
            {
                group->~BSBatchRenderer__GeometryGroup();
                g_memoryManager.Deallocate(group);
            }
        }
        m_pAlphaGeometryGroups[0] = 0;
        if (!m_pAlphaGeometryGroups[1]->m_usPassCountLocal)
        {
            reinterpret_cast<BSBatchRenderer__AlphaList*>(&AlphaGeometryList[1])->Remove(m_pAlphaGeometryGroups[1]);
            BSBatchRenderer__GeometryGroup* group = m_pAlphaGeometryGroups[1];
            if (group)
            {
                group->~BSBatchRenderer__GeometryGroup();
                g_memoryManager.Deallocate(group);
            }
        }
        m_pAlphaGeometryGroups[1] = 0;
        m_bHasActiveGroups = false;
    }
}

// @fnv 0x00b99730
template <> void BSSimpleList<unsigned short>::RemoveHead()
{
    BSSimpleList<unsigned short>* next = m_pkNext;
    if (next)
    {
        m_pkNext = next->m_pkNext;
        m_item = next->m_item;
        next->m_pkNext = 0;
        next->RemoveAll();
        g_memoryManager.Deallocate(next);
    }
    else
    {
        m_item = 0;
    }
}

struct Node_00b98e20
{
    unsigned short m_item;
    Node_00b98e20* m_pkNext;

    Node_00b98e20(const unsigned short& item) : m_item(item), m_pkNext(0)
    {}
    void* operator new(size_t stSize)
    {
        return g_memoryManager.Allocate(stSize);
    }
};

// @fnv 0x00b98e20
void __fastcall FUN_00b98e20(Node_00b98e20* pThis, int, const unsigned short* pItem)
{
    if (*pItem)
    {
        if (pThis->m_item)
        {
            Node_00b98e20* pkNew = new Node_00b98e20(pThis->m_item);
            pkNew->m_pkNext = pThis->m_pkNext;
            pThis->m_pkNext = pkNew;
            pThis->m_item = *pItem;
        }
        else
        {
            pThis->m_item = *pItem;
        }
    }
}

template <> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>
{
  public:
    void* AddHead();
};

// Appends a new node holding *elem to the list, reusing a free node from self[3] or allocating one, and updates head, tail and count.
// @fnv 0x00b99840
void __fastcall FUN_00b99840(int* self, int, const int* pElement)
{
    int* node = (int*)self[3];
    if (!node)
    {
        node = (int*)((NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>*)(self + 4))->AddHead();
    }
    else
    {
        self[3] = *node;
    }

    node[2] = *pElement;
    node[0] = 0;
    node[1] = self[2];

    int* tail = (int*)self[2];
    if (tail)
    {
        *tail = (int)node;
        self[4]++;
        self[2] = (int)node;
    }
    else
    {
        self[4]++;
        self[1] = (int)node;
        self[2] = (int)node;
    }
}

void __cdecl FUN_00b988e0();
void __cdecl FUN_00b994f0(void*, unsigned short, int, int, int);

struct PassListElement
{
    void* pPass;
    unsigned short m_usPassCountLocal;
};

struct PassListNode
{
    PassListNode* m_pkNext;
    PassListNode* m_pkPrev;
    PassListElement* m_kElement;
};

static inline PassListElement* const& GetNext(PassListNode*& pkPos)
{
    PassListElement* const& kElem = pkPos->m_kElement;
    pkPos = pkPos->m_pkNext;
    return kElem;
}

// If the pass list has entries, iterates each element and calls FUN_00b994f0 on those with a pass, then resets the list head, tail and count.
// @fnv 0x00b99990
void __cdecl ClearPassList(BSBatchRenderer__PassList* pList, int a2)
{
    if (pList->Allocator.ItemUpdateArray > 0)
    {
        FUN_00b988e0();

        PassListNode* pNode = static_cast<PassListNode*>(pList->pHead);
        PassListElement* pElement = pNode ? GetNext(pNode) : 0;

        while (pElement)
        {
            if (pElement->pPass)
            {
                FUN_00b994f0(pElement, pElement->m_usPassCountLocal, 1, a2, 1);
            }

            pElement = pNode ? GetNext(pNode) : 0;
        }

        pList->ResetPassList();
        pList->m_pCachedListItems = pList->pHead;
        pList->pHead = 0;
        pList->pTail = 0;
        pList->Allocator.ItemUpdateArray = 0;

        FUN_00b988e0();
    }
}

struct FUN_00b99630_Arg
{
    void(__cdecl* fn)();
};

void __cdecl CompareSortPassesByDepth();
void __fastcall SortList(void*, FUN_00b99630_Arg);

extern char DAT_011ffe35;
extern int DAT_011ffe38;

// @fnv 0x00b99a10
void __fastcall FUN_00b99a10(char* this_ptr, int, int param_1, char param_2)
{
    DAT_011ffe38 = param_1;
    DAT_011ffe35 = param_2;
    FUN_00b99630_Arg arg = {CompareSortPassesByDepth};
    SortList(*(char**)(this_ptr + 0x70) + 0xc, arg);
    SortList(*(char**)(this_ptr + 0x74) + 0xc, arg);
}

struct PassGroup_Layout
{
    BSBatchRenderer__PassList kPassLists[5];
    unsigned int ItemUpdateArray;
};

// @fnv 0x00b99a50
void __fastcall ClearPassGroups(PassGroup_Layout* pThis, int, bool)
{
    for (int j = 0; j < 5; ++j)
    {
        BSBatchRenderer__PassList& kList = pThis->kPassLists[j];
        if (kList.Allocator.ItemUpdateArray > 0)
        {
            kList.ResetPassList();
            kList.m_pCachedListItems = kList.pHead;
            kList.pHead = 0;
            kList.pTail = 0;
            kList.Allocator.ItemUpdateArray = 0;
        }
    }
    pThis->ItemUpdateArray = 0;
}

struct BSBatchRenderer_GroupEntry_00b99bc0
{
    BSBatchRenderer__PassList passLists[5];
    unsigned int ItemUpdateArray;
};

struct BSBatchRenderer_MapItem_00b99bc0
{
    BSBatchRenderer_MapItem_00b99bc0* m_pkNext;
    int m_key;
    int m_val;
};

struct BSBatchRenderer_Map_00b99bc0
{
    virtual ~BSBatchRenderer_Map_00b99bc0();
    virtual unsigned int KeyToHashIndex(int key) const;
    unsigned int m_uiHashSize;
    BSBatchRenderer_MapItem_00b99bc0** m_ppkHashTable;
    unsigned int m_uiCount;

    __forceinline BSBatchRenderer_MapItem_00b99bc0* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    __forceinline void GetNext(BSBatchRenderer_MapItem_00b99bc0*& pos, int& key, int& val) const
    {
        BSBatchRenderer_MapItem_00b99bc0* pkItem = pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (i++; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }
};

struct BSBatchRenderer_View_00b99bc0
{
    void* vftable;
    void* unk04;
    BSBatchRenderer_GroupEntry_00b99bc0* pGroups;
    BSBatchRenderer_Map_00b99bc0 kMap;
    char pad[0x2c - 0x1c];
    BSSimpleList<unsigned short> kList;
};

// Iterates the map, clears each group's pass lists and resets its counter, then removes all entries from kList.
// @fnv 0x00b99bc0
void __fastcall ClearAllGroups(BSBatchRenderer_View_00b99bc0* pThis, int, int unusedArg)
{
    BSBatchRenderer_MapItem_00b99bc0* pItem = pThis->kMap.GetFirstPos();
    while (pItem)
    {
        int key;
        int iGroupIndex;
        pThis->kMap.GetNext(pItem, key, iGroupIndex);

        BSBatchRenderer_GroupEntry_00b99bc0* group = &pThis->pGroups[iGroupIndex];
        for (int i = 0; i < 5; ++i)
        {
            BSBatchRenderer__PassList* list = &group->passLists[i];
            if (list->Allocator.ItemUpdateArray > 0)
            {
                list->ResetPassList();
                list->m_pCachedListItems = list->pHead;
                list->pHead = 0;
                list->pTail = 0;
                list->Allocator.ItemUpdateArray = 0;
            }
        }
        group->ItemUpdateArray = 0;
    }

    pThis->kList.RemoveAll();
}

// Returns true when v falls in the ranges 0x1c4-0x1c7, 0x231-0x234, or 0x284-0x287.
// @fnv 0x00b630f0
bool __cdecl FUN_00b630f0(unsigned int v)
{
    if ((v >= 0x1c4 && v <= 0x1c7) || (v >= 0x231 && v <= 0x234) || (v - 0x284) <= 3)
        return true;
    return false;
}

struct FUN_00e879b0_holder
{
    void CallSlot68WithField(int, int);
};
struct NiRenderer
{
    char pad[0x8b8];
    FUN_00e879b0_holder* sub;
};
extern NiRenderer* DAT_011f9508;
// @fnv 0x00b984d0
void __cdecl FUN_00b984d0(int aiValue)
{
    DAT_011f9508->sub->CallSlot68WithField(aiValue, 0);
}

namespace fnv_00b98540 {
struct FUN_00b98540_Dev
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void SetState(unsigned int id, unsigned int value, int a, int b);
};
struct FUN_00b98540_Renderer
{
    unsigned char pad[0x8b8];
    FUN_00b98540_Dev* device;
};
extern FUN_00b98540_Renderer* DAT_011f9508;
extern int DAT_011f94b8;
extern int DAT_011ffa28;

// If no pending count, sets a device state (0xb5 or 0x9a) based on flag and renderer mode, then adds count to DAT_011ffa28.
// @fnv 0x00b98540
void __cdecl FUN_00b98540(bool flag, int count)
{
    if (DAT_011ffa28 == 0)
    {
        if (DAT_011f94b8 == 1)
        {
            unsigned int value;
            if (flag)
                value = 0x434f5441;
            else
            {
                float zero = 0.0f;
                value = *(unsigned int*)&zero;
            }
            DAT_011f9508->device->SetState(0xb5, value, 0, 0);
            DAT_011ffa28 += count;
            return;
        }
        if (DAT_011f94b8 == 2)
        {
            DAT_011f9508->device->SetState(0x9a, (flag ? 0x01000000 : 0) + 0x304d3241, 0, 0);
            DAT_011ffa28 += count;
            return;
        }
    }
    DAT_011ffa28 = DAT_011ffa28 + count;
}
}  // namespace fnv_00b98540

struct Node
{
    Node* m_pkNext;
    Node* m_pkPrev;
    void* m_element;
};

struct FUN_00b99630_shell : public BSBatchRenderer__PassList
{
    void SortList(int(__cdecl* cmp)(const void*, const void*));
};

// Bottom-up merge sort of the linked list using cmp on each node's m_element, rebuilding m_pkNext/m_pkPrev links and updating pHead and pTail.
// @fnv 0x00b99630
void FUN_00b99630_shell::SortList(int(__cdecl* cmp)(const void*, const void*))
{
    ResetPassList();

    if (!pHead)
        return;

    unsigned int uiRunSize = 1;
    unsigned int uiMergeCount;
    Node* tail;

    do
    {
        Node* p = (Node*)pHead;
        pHead = 0;
        tail = 0;
        uiMergeCount = 0;

        while (p)
        {
            uiMergeCount++;
            Node* pRight = p;
            int iLeftCount = 0;
            for (unsigned int i = 0; i < uiRunSize; i++)
            {
                iLeftCount++;
                pRight = pRight->m_pkNext;
                if (!pRight)
                    break;
            }

            int iRightCount = uiRunSize;

            while (iLeftCount > 0 || (iRightCount > 0 && pRight))
            {
                Node* pNode;
                if (iLeftCount == 0)
                {
                    pNode = pRight;
                    pRight = pRight->m_pkNext;
                    iRightCount--;
                }
                else if (iRightCount == 0 || !pRight)
                {
                    pNode = p;
                    p = p->m_pkNext;
                    iLeftCount--;
                }
                else if (cmp(&p->m_element, &pRight->m_element) <= 0)
                {
                    pNode = p;
                    p = p->m_pkNext;
                    iLeftCount--;
                }
                else
                {
                    pNode = pRight;
                    pRight = pRight->m_pkNext;
                    iRightCount--;
                }

                if (tail)
                {
                    tail->m_pkNext = pNode;
                }
                else
                {
                    pHead = pNode;
                }
                pNode->m_pkPrev = tail;
                tail = pNode;
            }

            p = pRight;
        }

        tail->m_pkNext = 0;
        uiRunSize *= 2;
    } while (uiMergeCount != 1);

    pTail = tail;
}

struct NodePoolView
{
    unsigned int count;
    void* AddHead();
};
struct FUN_00b99890_Node
{
    FUN_00b99890_Node* next;
    FUN_00b99890_Node* prev;
    unsigned int item;
};
struct FUN_00b99890_List
{
    int pad;
    FUN_00b99890_Node* head;
    FUN_00b99890_Node* tail;
    FUN_00b99890_Node* freeList;
    NodePoolView pool;
};
// Takes a node from the free list or pool, stores the value, and links it at the head of the list, updating tail when empty.
// @fnv 0x00b99890
void __fastcall PushFront(FUN_00b99890_List* list, int, unsigned int* value)
{
    FUN_00b99890_Node* node = list->freeList;
    if (!node)
        node = (FUN_00b99890_Node*)list->pool.AddHead();
    else
        list->freeList = node->next;
    node->item = *value;
    node->next = list->head;
    node->prev = 0;
    if (list->head)
    {
        list->head->prev = node;
        list->pool.count++;
        list->head = node;
    }
    else
    {
        list->pool.count++;
        list->tail = node;
        list->head = node;
    }
}

struct FUN_00b998e0
{
    int a;
    int b;
    int c;
    FUN_00b998e0();
};
// @fnv 0x00b998e0
FUN_00b998e0::FUN_00b998e0()
{
    c = 0;
    a = 0;
    b = 0;
}

// @fnv 0x00b99b70
BSBatchRenderer__PassList* __fastcall DestroyPassList(BSBatchRenderer__PassList* p, int, unsigned int flags)
{
    p->BSBatchRenderer__PassList::~BSBatchRenderer__PassList();
    if (flags & 1)
        g_memoryManager.Deallocate(p);
    return p;
}

struct FUN_00b99bb0
{
    BSBatchRenderer__PassList passes[5];
    ~FUN_00b99bb0();
};
// @fnv 0x00b99bb0
FUN_00b99bb0::~FUN_00b99bb0()
{}

namespace fnv_00b9a3c0 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct PassGroup_Layout
{
    int x[26];
    void ClearPassGroups(bool);
};

struct FUN_00b9a3c0_shell : public BSBatchRenderer
{
    bool FUN_00b9a3c0(unsigned int&, int&, bool&, bool);
};

// @fnv 0x00b9a3c0
bool FUN_00b9a3c0_shell::FUN_00b9a3c0(unsigned int& auiPass, int& aiBucket, bool& abFlag, bool)
{
    unsigned int idx = 0;
    ((DummyPointerMap*)((char*)this + 0xc))->GetAt(auiPass, idx);
    PassGroup_Layout* pGroups = *(PassGroup_Layout**)((char*)this + 8);
    ((PassGroup_Layout*)((char*)pGroups + idx * 0x68))->ClearPassGroups(false);
    return ((BSBatchRenderer*)this)->FindPassBucket(auiPass, aiBucket, abFlag);
}
}  // namespace fnv_00b9a3c0

struct FUN_00b9a4d0_Owner
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void Notify(int a, int b, int c);
    unsigned char pad[0x28];
    BSSimpleList<unsigned short> list;
};
struct FUN_00b9a4d0_Obj
{
    unsigned char flags;
    unsigned char pad1;
    unsigned short count;
    unsigned int pad4;
    FUN_00b9a4d0_Owner* owner;
    BSBatchRenderer__PassList passList;
};
void __cdecl ClearPassList(BSBatchRenderer__PassList*, int);

// If flags bit 0 is set, forwards arg to ClearPassList on passList; otherwise notifies owner with (1, 0x2f1, arg); then clears owner's list and resets count to 0.
// @fnv 0x00b9a4d0
void __fastcall FUN_00b9a4d0(FUN_00b9a4d0_Obj* self, int unused, int arg)
{
    if ((self->flags & 1) > 0)
        ClearPassList(&self->passList, arg);
    else if (self->owner)
        self->owner->Notify(1, 0x2f1, arg);
    if (self->owner)
        self->owner->list.RemoveAll();
    self->count = 0;
}

struct FUN_00b9a530
{
    BSBatchRenderer__PassList passes[5];
    int tail;
    FUN_00b9a530();
};
// Initializes the pass list container by setting its tail counter to zero.
// @fnv 0x00b9a530
FUN_00b9a530::FUN_00b9a530()
{
    tail = 0;
}

struct MyPassList : public BSBatchRenderer__PassList
{
    MyPassList()
    {
        pHead = 0;
        pTail = 0;
        m_pCachedListItems = 0;
    }
    void Clear()
    {
        ResetPassList();
        m_pCachedListItems = pHead;
        pHead = 0;
        pTail = 0;
        Allocator.ItemUpdateArray = 0;
    }
};

struct FUN_00b9a560
{
    char b0;
    short s2;
    void* p4;
    void* p8;
    MyPassList passList;

    FUN_00b9a560(void* p);
    ~FUN_00b9a560();
};

// Initializes the object: clears b0, p8 and s2, stores p in p4, and clears passList.
// @fnv 0x00b9a560
FUN_00b9a560::FUN_00b9a560(void* p)
{
    b0 = 0;
    p8 = 0;
    p4 = p;
    s2 = 0;
    passList.Clear();
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011ffe3c;
// @fnv 0x00b9aa70
GlobalObjectO2_00a7b610* __cdecl FUN_00b9aa70()
{
    return &g_011ffe3c;
}

struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};

struct PassListStandin
{
    void FUN_00b99840(void*);
    void PushFront(void*);
};

struct FUN_00b9a5b0 : public BSFadeNode
{
    char pad[0x98 - 4];
    FUN_00b9a5b0(void* edx, int count);
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void AdvanceFade();
    virtual void Unused4();
    virtual void Unused5();
    virtual void Unused6();
    virtual void Unused7();
    virtual void Unused8();
    virtual void Unused9();
    virtual void Unused10();
    virtual void Unused11();
    virtual void Unused12();
    virtual void Unused13();
    virtual void Unused14();
    virtual void Unused15();
    virtual void Unused16();
    virtual void Unused17();
    virtual void Unused18();
    virtual void Unused19();
    virtual void Unused20();
    virtual void Unused21();
    virtual void Unused22();
    virtual void Unused23();
    virtual void Unused24();
    virtual void Unused25();
    virtual void Unused26();
    virtual void Unused27();
    virtual void Unused28();
    virtual void Unused29();
    virtual void Unused30();
    virtual void Unused31();
    virtual void Unused32();
    virtual void Unused33();
    virtual void Unused34();
    virtual void Method35(void* pPass, unsigned int id);
};

// @fnv 0x00b9abc0
void __fastcall DispatchPass(void* pThis, int dummy, void* pPass, bool bFlag)
{
    unsigned char* pBytes = (unsigned char*)pThis;
    if ((pBytes[0] & 1u) > 0)
    {
        if (bFlag)
        {
            ((PassListStandin*)(pBytes + 0xc))->PushFront(&pPass);
        }
        else
        {
            ((PassListStandin*)(pBytes + 0xc))->FUN_00b99840(&pPass);
        }
    }
    else
    {
        if (*(void**)(pBytes + 8) == 0)
        {
            *(void**)(pBytes + 8) = new FUN_00b9a5b0(*(void**)(pBytes + 4), 0x64);
        }
        FUN_00b9a5b0* pObj = *(FUN_00b9a5b0**)(pBytes + 8);
        pObj->Method35(pPass, *(unsigned short*)((char*)pPass + 4));
    }
    (*(unsigned short*)(pBytes + 2))++;
}

struct SortPt
{
    float x, y, z;
    float Dot(const SortPt& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};
struct SortBound
{
    SortPt kTargetCenter;
    float fRadius;
};
extern SortBound DAT_011f4288;
extern char DAT_011ffe35;
extern int DAT_011ffe38;
struct SortCamera
{
    char pad[0x68];
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    SortPt GetWorldTranslation() const
    {
        SortPt kPt;
        kPt.x = m00;
        kPt.y = m10;
        kPt.z = m20;
        return kPt;
    }
};
struct SortGeom
{
    char pad[0x20];
    SortBound* pWorldBound;
    const SortBound& GetBoundingVolume() const
    {
        return pWorldBound ? *pWorldBound : DAT_011f4288;
    }
};
struct SortPass
{
    SortGeom* pGeom;
};
// @fnv 0x00b98b20
int __cdecl CompareSortPassesByDepth(const void* apA, const void* apB)
{
    SortPass* pA = *(SortPass**)apA;
    SortPass* pB = *(SortPass**)apB;
    SortPt kWorldPosition = ((SortCamera*)DAT_011ffe38)->GetWorldTranslation();
    float fDepthB, fDepthA;
    if (DAT_011ffe35)
    {
        fDepthA =
            pA->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition) - pA->pGeom->GetBoundingVolume().fRadius;
        fDepthB =
            pB->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition) - pB->pGeom->GetBoundingVolume().fRadius;
    }
    else
    {
        fDepthA = pA->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition);
        fDepthB = pB->pGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition);
    }
    if (fDepthA == fDepthB)
        return 0;
    if (fDepthA < fDepthB)
        return 1;
    return -1;
}

struct FUN_00b99390_S
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void vf0(unsigned int);
    virtual void vf4(unsigned int);
    virtual void vf8(unsigned int);
    virtual void vfc(unsigned int);
    virtual void v100(unsigned int);
};
struct FUN_00b7dd50_c
{
    void FUN_00b7dd50();
};
struct FUN_00b7deb0_c2
{
    void FUN_00b7deb0();
};
struct FUN_00b7deb0_class
{
    void FUN_00b7deb0();
};
void __cdecl FUN_00b97de0(unsigned int, unsigned int);
void __cdecl FUN_00b988e0();
extern short DAT_011ae63c;
extern unsigned int _DAT_0126f680[16];
extern unsigned int DAT_011ffe30;
extern FUN_00b99390_S* DAT_011ffe2c;
extern bool DAT_011ad8ec;
// @fnv 0x00b99390
void __cdecl SetShaderPass(unsigned int pass, FUN_00b99390_S* shader)
{
    FUN_00b988e0();
    DAT_011ae63c = -1;
    shader->vf0(pass);
    for (int i = 0; i < 16; i++)
        _DAT_0126f680[i] = 0;
    switch (pass)
    {
    case 0xfc:
    case 0xfd:
        ((FUN_00b7dd50_c*)shader)->FUN_00b7dd50();
        FUN_00b97de0(1, 0);
        break;
    case 0x102:
        ((FUN_00b7dd50_c*)shader)->FUN_00b7dd50();
        break;
    case 0xca:
        ((FUN_00b7deb0_class*)shader)->FUN_00b7deb0();
        break;
    case 0xd1:
        ((FUN_00b7deb0_c2*)shader)->FUN_00b7deb0();
        break;
    default:
        shader->vfc(pass);
        shader->vf8(pass);
        shader->v100(pass);
        break;
    }
    shader->vf4(pass);
    DAT_011ffe30 = pass;
    DAT_011ffe2c = shader;
    DAT_011ad8ec = true;
}

namespace fnv_00b994f0 {
struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
};
struct Shader_b994f0
{
    char pad[0x68];
    int iType;
    bool IsLit() const
    {
        return iType >= 1 && iType <= 5;
    }
    bool IsType11() const
    {
        return iType == 0x11;
    }
    void FUN_00b7ac20(unsigned int);
    void FUN_00bb96d0(unsigned int);
};
struct Prop_b994f0
{
    char pad[0x18];
    unsigned short usFlags;
    bool GetFlag9() const
    {
        return (usFlags >> 9) & 1;
    }
};
struct Geom_b994f0
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void* IsA12();
    virtual void* IsA13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void RenderImmediate55(NiRenderer*);
    char pad04[0x98];
    Prop_b994f0* pProp;
    char pada0[0x20];
    Shader_b994f0* pShader;
};
struct Pass_b994f0
{
    Geom_b994f0* pGeom;
    unsigned short m_usShaderPassType;
};

struct Handler_b994f0
{
    bool FUN_00e72c20(Geom_b994f0*, int);
};
extern Handler_b994f0* DAT_011f9508;
extern Pass_b994f0* DAT_011f91e0;
extern unsigned int DAT_011f91e4;
extern bool DAT_011f9421;
extern Shader_b994f0* DAT_011ffe2c;
extern unsigned int DAT_011ffe30;
int __cdecl FUN_00b98540(int, int);
void __cdecl SetShaderPass(unsigned int, Shader_b994f0*);
void __cdecl FUN_00b99110(Pass_b994f0*, bool, bool, bool);
void __cdecl DrawGeometryPass(Pass_b994f0*, bool, bool, bool);

// @fnv 0x00b994f0
void FUN_00b994f0(Pass_b994f0* prenderpass, unsigned int uiPassId, bool balphaTest, bool abAlphaPass,
                  bool abGeometryRenderStates)
{
    if (prenderpass->m_usShaderPassType != uiPassId)
        return;
    DAT_011f91e4 = uiPassId;
    DAT_011f91e0 = prenderpass;
    Shader_b994f0* pshader = prenderpass->pGeom->pShader;
    bool bfirstpass = false;
    if (DAT_011ffe30 != uiPassId || uiPassId == 0x2f6 || pshader != DAT_011ffe2c)
    {
        bfirstpass = true;
        SetShaderPass(uiPassId, pshader);
    }
    if (DAT_011f9421)
    {
        Prop_b994f0* pProp = prenderpass->pGeom->pProp;
        if (pProp && pProp->GetFlag9())
            FUN_00b98540(1, 0);
        else
            FUN_00b98540(0, 0);
    }
    if (DAT_011f9508->FUN_00e72c20(prenderpass->pGeom, 0))
    {
        FUN_00b99110(prenderpass, balphaTest, abAlphaPass, abGeometryRenderStates);
    }
    else if (prenderpass->pGeom->IsA12())
    {
        prenderpass->pGeom->RenderImmediate55(NiRenderer::ms_pRenderer);
    }
    else if (prenderpass->pGeom->IsA13())
    {
        prenderpass->pGeom->RenderImmediate55(NiRenderer::ms_pRenderer);
    }
    else
    {
        DrawGeometryPass(prenderpass, balphaTest, abAlphaPass, abGeometryRenderStates);
    }
    if (bfirstpass && DAT_011ffe2c)
    {
        if (DAT_011ffe2c->IsLit())
            DAT_011ffe2c->FUN_00b7ac20(uiPassId);
        else if (DAT_011ffe2c->IsType11())
            DAT_011ffe2c->FUN_00bb96d0(uiPassId);
    }
}
}  // namespace fnv_00b994f0

namespace fnv_00b9aa80 {
extern MemoryManager _g_memoryManager;

template <> class NiTPointerMap<unsigned int, unsigned int>
{
  public:
    ~NiTPointerMap();
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_kItemCount;
};

class FUN_00b99bb0
{
  public:
    ~FUN_00b99bb0();
    unsigned char data[0x68];
    static void operator delete[](void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};

class FUN_00b998f0
{
  public:
    ~FUN_00b998f0();
    unsigned char data[0xc];
};

struct FUN_00bd9150_Inst
{
    void FUN_00bd9150();
};

struct ActivePassList
{
    void* head;
    void* next;
    ~ActivePassList()
    {
        ((BSSimpleList<unsigned short>*)this)->RemoveAll();
    }
};

struct FUN_00b9aa80 : NiObject
{
    FUN_00b99bb0* m_pPassBucketEntries;
    NiTPointerMap<unsigned int, unsigned int> m_kGroupIndexMap;
    unsigned int m_uiGroupCount;
    unsigned int m_uiPassCount;
    unsigned int m_uiBucketCount;
    FUN_00bd9150_Inst* m_pGeometryGroupAllocator;
    ActivePassList m_kActivePassList;
    int m_iActiveGroupCount;
    bool m_bHasActiveGroups;
    BSBatchRenderer__GeometryGroup* m_pGeometryGroups[13];
    BSBatchRenderer__GeometryGroup* m_pSecondaryGeometryGroups[2];
    FUN_00b998f0 AlphaGeometryList[2];
    BSBatchRenderer__GeometryGroup* m_pAlphaGeometryGroups[2];
    virtual ~FUN_00b9aa80();
};

// @fnv 0x00b9aa80
FUN_00b9aa80::~FUN_00b9aa80()
{
    ((BSBatchRenderer*)this)->ClearAllGroups(0);
    delete[] m_pPassBucketEntries;
    FUN_00bd9150_Inst* pInstance = m_pGeometryGroupAllocator;
    m_uiGroupCount = 0;
    if (pInstance)
    {
        pInstance->FUN_00bd9150();
        _g_memoryManager.Deallocate(pInstance);
        m_pGeometryGroupAllocator = 0;
    }
    for (unsigned int i = 0; i < 13; i++)
    {
        BSBatchRenderer__GeometryGroup* group = m_pGeometryGroups[i];
        if (group)
        {
            group->~BSBatchRenderer__GeometryGroup();
            _g_memoryManager.Deallocate(group);
        }
    }
    BSBatchRenderer__GeometryGroup* a = m_pSecondaryGeometryGroups[0];
    if (a)
    {
        a->~BSBatchRenderer__GeometryGroup();
        _g_memoryManager.Deallocate(a);
    }
    a = m_pSecondaryGeometryGroups[1];
    if (a)
    {
        a->~BSBatchRenderer__GeometryGroup();
        _g_memoryManager.Deallocate(a);
    }
}
}  // namespace fnv_00b9aa80

extern float DAT_01015f5c;
struct SortPassNode
{
    SortPassNode* m_pkNext;
    SortPassNode* m_pkPrev;
    SortPass* m_element;
};
class NiTListItem_BSBatchRenderer__GeometryGroup___
{
  public:
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkNext;
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkPrev;
    BSBatchRenderer__GeometryGroup* m_element;
};
float __cdecl FUN_00404010(float a, float b);
struct BSBatchRenderer_AlphaDepth : public BSBatchRenderer
{
    float ComputeAlphaDepth(int iIndex, SortCamera* pkCamera, bool bUseRadius);
};

// @fnv 0x00b98c80
float BSBatchRenderer_AlphaDepth::ComputeAlphaDepth(int iIndex, SortCamera* pkCamera, bool bUseRadius)
{
    SortPt kWorldPosition = pkCamera->GetWorldTranslation();
    BSBatchRenderer__GeometryGroup* pkGroup = m_pSecondaryGeometryGroups[iIndex];
    if (pkGroup->m_usPassCountLocal == 0 && AlphaGeometryList[iIndex].m_kItemCount.m_uiCount == 0)
        return DAT_01015f5c;
    if (pkGroup->m_usPassCountLocal == 0)
        return AlphaGeometryList[iIndex].m_pkHead->m_element->m_fProjectionDepth;
    if (AlphaGeometryList[iIndex].m_kItemCount.m_uiCount == 0)
    {
        SortGeom* pkGeom = ((SortPassNode*)pkGroup->PassTextureSlotCollection.pHead)->m_element->pGeom;
        if (bUseRadius)
            return pkGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition) - pkGeom->GetBoundingVolume().fRadius;
        return pkGeom->GetBoundingVolume().kTargetCenter.Dot(kWorldPosition);
    }
    float fListDepth = AlphaGeometryList[iIndex].m_pkHead->m_element->m_fProjectionDepth;
    SortGeom* pkGeom = ((SortPassNode*)pkGroup->PassTextureSlotCollection.pHead)->m_element->pGeom;
    if (bUseRadius)
    {
        const SortBound& kB1 = pkGeom->GetBoundingVolume();
        const SortBound& kB2 = pkGeom->GetBoundingVolume();
        return FUN_00404010(fListDepth, kB1.kTargetCenter.Dot(kWorldPosition) - kB2.fRadius);
    }
    const SortPt& center = pkGeom->GetBoundingVolume().kTargetCenter;
    return FUN_00404010(fListDepth, (float)(static_cast<const volatile float&>(kWorldPosition.x) * center.x +
                                            kWorldPosition.y * center.y + kWorldPosition.z * center.z));
}

// Renders one geometry pass: bind the geometry's transform and render data, run the pass-specific
// shader setup (switch on the pass id), then draw and finish.
struct RenderTransform
{
    unsigned int state0, state4, state8, stateC, state10, state14, state18;
};
struct RenderData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30;
    unsigned int drawData;
};
struct RenderShader;
struct RenderGeometry
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07();
    virtual void v08(), v09(), v0a(), v0b(), v0c(), v0d(), v0e(), v0f();
    virtual void v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17();
    virtual void v18(), v19(), v1a(), v1b(), v1c(), v1d(), v1e(), v1f();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27();
    virtual void v28(), v29(), v2a(), v2b(), v2c(), v2d(), v2e(), v2f();
    virtual void v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37();
    virtual void Finish(void*);
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    unsigned int unk84, unk88, unk8c, unk90, unk94, unk98;
    RenderTransform world;
    RenderData* data;
    unsigned int unkbc;
    RenderShader* shader;
};
struct RenderShader
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07();
    virtual void v08(), v09(), v0a(), v0b(), v0c(), v0d(), v0e(), v0f();
    virtual void v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17();
    virtual void v18(), v19(), v1a();
    virtual void Draw(RenderGeometry*, int, unsigned int, RenderTransform*);
    virtual void v1c(), v1d();
    virtual void PrepareA(RenderTransform*);
    virtual void PrepareB(RenderTransform*);
    virtual void UpdateA(RenderTransform*);
    virtual void UpdateB(RenderTransform*);
    virtual void UpdateActorPresentation(RenderTransform*, bool);
    virtual void Finish(RenderTransform*);
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v2a(), v2b();
    virtual void v2c(), v2d(), v2e(), v2f(), v30(), v31(), v32(), v33();
    virtual void v34(), v35(), v36(), v37(), v38(), v39(), v3a(), v3b();
    virtual void v3c(), v3d(), v3e(), v3f(), v40(), v41(), v42(), v43();
    virtual void Reset(RenderTransform*);
    void FUN_00b7dde0(RenderTransform*);
    void SetupTextureStages(RenderTransform*);
    void SetupShaderPasses(RenderTransform*);
    void FUN_00b7e150(RenderTransform*);
};
struct RenderSetup
{
    void ProcessCollector(void*, RenderData*, void*, bool, unsigned int, unsigned int);
};
struct RenderManager
{
    unsigned int unk000, unk004, unk008;
    RenderTransform* current;
    unsigned int unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned int unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    unsigned int unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    unsigned int unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
    unsigned int unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc;
    unsigned int unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    unsigned int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104, unk108, unk10c;
    unsigned int unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    unsigned int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    unsigned int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    unsigned int unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    unsigned int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4, unk1c8, unk1cc;
    unsigned int unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec;
    unsigned int unk1f0, unk1f4, unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    unsigned int unk210, unk214, unk218, unk21c, unk220, unk224, unk228, unk22c;
    unsigned int unk230, unk234, unk238, unk23c, unk240, unk244, unk248, unk24c;
    unsigned int unk250, unk254, unk258, unk25c, unk260, unk264, unk268, unk26c;
    unsigned int unk270, unk274, unk278, unk27c, unk280, unk284, unk288, unk28c;
    unsigned int unk290, unk294, unk298, unk29c, unk2a0, unk2a4, unk2a8, unk2ac;
    unsigned int unk2b0, unk2b4, unk2b8, unk2bc, unk2c0, unk2c4, unk2c8, unk2cc;
    unsigned int unk2d0, unk2d4, unk2d8, unk2dc, unk2e0, unk2e4, unk2e8, unk2ec;
    unsigned int unk2f0, unk2f4, unk2f8, unk2fc, unk300, unk304, unk308, unk30c;
    unsigned int unk310, unk314, unk318, unk31c, unk320, unk324, unk328, unk32c;
    unsigned int unk330, unk334, unk338, unk33c, unk340, unk344, unk348, unk34c;
    unsigned int unk350, unk354, unk358, unk35c, unk360, unk364, unk368, unk36c;
    unsigned int unk370, unk374, unk378, unk37c, unk380, unk384, unk388, unk38c;
    unsigned int unk390, unk394, unk398, unk39c, unk3a0, unk3a4, unk3a8, unk3ac;
    unsigned int unk3b0, unk3b4, unk3b8, unk3bc, unk3c0, unk3c4, unk3c8, unk3cc;
    unsigned int unk3d0, unk3d4, unk3d8, unk3dc, unk3e0, unk3e4, unk3e8, unk3ec;
    unsigned int unk3f0, unk3f4, unk3f8, unk3fc, unk400, unk404, unk408, unk40c;
    unsigned int unk410, unk414, unk418, unk41c, unk420, unk424, unk428, unk42c;
    unsigned int unk430, unk434, unk438, unk43c, unk440, unk444, unk448, unk44c;
    unsigned int unk450, unk454, unk458, unk45c, unk460, unk464, unk468, unk46c;
    unsigned int unk470, unk474, unk478, unk47c, unk480, unk484, unk488, unk48c;
    unsigned int unk490, unk494, unk498, unk49c, unk4a0, unk4a4, unk4a8, unk4ac;
    unsigned int unk4b0, unk4b4, unk4b8, unk4bc, unk4c0, unk4c4, unk4c8, unk4cc;
    unsigned int unk4d0, unk4d4, unk4d8, unk4dc, unk4e0, unk4e4, unk4e8, unk4ec;
    unsigned int unk4f0, unk4f4, unk4f8, unk4fc, unk500, unk504, unk508, unk50c;
    unsigned int unk510, unk514, unk518, unk51c, unk520, unk524, unk528, unk52c;
    unsigned int unk530, unk534, unk538, unk53c, unk540, unk544, unk548, unk54c;
    unsigned int unk550, unk554, unk558, unk55c, unk560, unk564, unk568, unk56c;
    unsigned int unk570, unk574, unk578, unk57c, unk580, unk584, unk588, unk58c;
    unsigned int unk590, unk594, unk598, unk59c, unk5a0, unk5a4, unk5a8, unk5ac;
    unsigned int unk5b0, unk5b4, unk5b8, unk5bc, unk5c0, unk5c4, unk5c8, unk5cc;
    unsigned int unk5d0, unk5d4, unk5d8, unk5dc, unk5e0, unk5e4, unk5e8, unk5ec;
    unsigned int unk5f0, unk5f4, unk5f8, unk5fc, unk600, unk604, unk608, unk60c;
    unsigned int unk610, unk614, unk618, unk61c, unk620, unk624, unk628, unk62c;
    unsigned int unk630, unk634, unk638, unk63c, unk640, unk644, unk648, unk64c;
    unsigned int unk650, unk654, unk658, unk65c, unk660, unk664, unk668, unk66c;
    unsigned int unk670, unk674, unk678, unk67c, unk680, unk684, unk688, unk68c;
    unsigned int unk690, unk694, unk698, unk69c, unk6a0, unk6a4, unk6a8, unk6ac;
    unsigned int unk6b0, unk6b4, unk6b8, unk6bc, unk6c0, unk6c4, unk6c8, unk6cc;
    unsigned int unk6d0, unk6d4, unk6d8, unk6dc, unk6e0, unk6e4, unk6e8, unk6ec;
    unsigned int unk6f0, unk6f4, unk6f8, unk6fc, unk700, unk704, unk708, unk70c;
    unsigned int unk710, unk714, unk718, unk71c, unk720, unk724, unk728, unk72c;
    unsigned int unk730, unk734, unk738, unk73c, unk740, unk744, unk748, unk74c;
    unsigned int unk750, unk754, unk758, unk75c, unk760, unk764, unk768, unk76c;
    unsigned int unk770, unk774, unk778, unk77c, unk780, unk784, unk788, unk78c;
    unsigned int unk790, unk794, unk798, unk79c, unk7a0, unk7a4, unk7a8, unk7ac;
    unsigned int unk7b0, unk7b4, unk7b8, unk7bc, unk7c0, unk7c4, unk7c8, unk7cc;
    unsigned int unk7d0, unk7d4, unk7d8, unk7dc, unk7e0, unk7e4, unk7e8, unk7ec;
    unsigned int unk7f0, unk7f4, unk7f8, unk7fc, unk800, unk804, unk808, unk80c;
    unsigned int unk810, unk814, unk818, unk81c, unk820, unk824, unk828, unk82c;
    unsigned int unk830, unk834, unk838, unk83c, unk840, unk844, unk848, unk84c;
    unsigned int unk850, unk854, unk858, unk85c, unk860, unk864, unk868, unk86c;
    unsigned int unk870, unk874, unk878, unk87c, unk880, unk884, unk888, unk88c;
    unsigned int unk890, unk894, unk898, unk89c, unk8a0, unk8a4, unk8a8;
    RenderSetup* setup;
    void* group;
};
extern RenderManager* DAT_011f4748;
extern bool DAT_011ad8ec;
bool __cdecl FUN_00b630f0(unsigned int);
struct ShaderPassEntry
{
    RenderGeometry* geometry;
    unsigned short id;
    unsigned char flags;
    bool alpha;
};
// Sets the manager's current transform, prepares the shader for the pass id, applies optional updates, draws the geometry and finishes the shader.
// @fnv 0x00b98e80
void __cdecl DrawGeometryPass(ShaderPassEntry* pass, bool updateB, bool updateA, bool updateAlpha)
{
    unsigned int id = pass->id;
    RenderManager* manager = DAT_011f4748;
    RenderGeometry* geometry = pass->geometry;
    RenderShader* shader = geometry->shader;
    RenderData* data = geometry->data;
    RenderTransform* world = &geometry->world;
    manager->current = world;
    manager->unk010 = 0;
    manager->setup->ProcessCollector(manager->group, data, 0, false, 0, 0);
    unsigned int drawData = data->drawData;
    switch (id)
    {
    case 252:
    case 253:
        shader->FUN_00b7dde0(world);
        if (updateB)
            shader->UpdateB(world);
        if (updateA)
            shader->UpdateA(world);
        break;
    case 258:
        shader->FUN_00b7e150(world);
        if (updateB)
            shader->UpdateB(world);
        if (updateA)
            shader->UpdateA(world);
        break;
    case 202:
        shader->SetupTextureStages(world);
        if (updateB)
            shader->UpdateB(world);
        if (updateA)
            shader->UpdateA(world);
        if (updateAlpha)
            shader->UpdateActorPresentation(world, pass->alpha);
        break;
    case 209:
        shader->SetupShaderPasses(world);
        if (updateB)
            shader->UpdateB(world);
        if (updateA)
            shader->UpdateA(world);
        if (updateAlpha)
            shader->UpdateActorPresentation(world, pass->alpha);
        break;
    default:
        shader->PrepareA(world);
        shader->PrepareB(world);
        if (pass->alpha)
        {
            if (updateA && !FUN_00b630f0(id))
                shader->UpdateA(world);
            if (updateB && !(id >= 4 && id <= 5) && !(id >= 14 && id <= 15) && id != 570)
                shader->UpdateB(world);
        }
        else if (DAT_011ad8ec && !FUN_00b630f0(id))
        {
            shader->Reset(world);
            DAT_011ad8ec = false;
        }
        if (updateAlpha)
            shader->UpdateActorPresentation(world, pass->alpha);
        break;
    }
    shader->Draw(geometry, 0, drawData, world);
    geometry->Finish(manager);
    shader->Finish(world);
}

void FUN_00b71300();
// @fnv 0x00b998f0
void FUN_00b998f0()
{
    FUN_00b71300();
}

namespace fnv_00b9ac80 {
inline void* operator new(size_t, void* p)
{
    return p;
}

struct SortPt
{
    float x;
    float y;
    float z;
    float operator*(const SortPt& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

struct SortBound
{
    SortPt kTargetCenter;
    float fRadius;
};

struct SortCamera
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
    float m_dirX;
    int unk6C;
    int unk70;
    float m_dirY;
    int unk78;
    int unk7C;
    float m_dirZ;
    SortPt GetWorldTranslation() const
    {
        SortPt pt = {m_dirX, m_dirY, m_dirZ};
        return pt;
    }
};

struct PassListStandin : public BSBatchRenderer__PassList
{
    PassListStandin()
    {
        pHead = 0;
        pTail = 0;
        m_pCachedListItems = 0;
    }
};

struct GroupStandin
{
    unsigned char m_ucEntryType;
    unsigned char f01;
    unsigned short m_usPassCountLocal;
    unsigned int auiGroupKey;
    BSBatchRenderer* m_pGroupRenderer;
    PassListStandin PassTextureSlotCollection;
    float m_fProjectionDepth;

    void* operator new(size_t size)
    {
        return g_memoryManager.Allocate(size);
    }

    GroupStandin()
    {
        BSBatchRenderer__PassList* pkPL = &PassTextureSlotCollection;
        m_usPassCountLocal = 0;
        m_ucEntryType = 0;
        m_pGroupRenderer = 0;
        auiGroupKey = 0x2f7;
        pkPL->ResetPassList();
        pkPL->m_pCachedListItems = pkPL->pHead;
        pkPL->pHead = 0;
        pkPL->pTail = 0;
        pkPL->Allocator.ItemUpdateArray = 0;
    }
};
struct AlphaNode
{
    AlphaNode* m_pkNext;
    AlphaNode* m_pkPrev;
    GroupStandin* m_element;
};
struct NodeAllocator
{
    unsigned int m_uiCount;
    AlphaNode* FUN_0043a010();
};
struct AlphaListCursor
{
    AlphaNode* m_pkTail;
    NodeAllocator m_kItemCount;
};
static inline AlphaNode*& ListHead(AlphaListCursor* pkList)
{
    return *(AlphaNode**)((char*)pkList - 4);
}
struct PoolLock
{
    void Lock(int);
};
extern PoolLock g_011c5f80;
extern int DAT_011c5f80;
extern void* DAT_011c5f58;
extern unsigned int DAT_011c5f84;
void __cdecl FUN_0043a080();
static inline AlphaNode* PoolCreateNode()
{
    g_011c5f80.Lock(0);
    AlphaNode* pkNode = (AlphaNode*)DAT_011c5f58;
    if (pkNode == 0)
    {
        FUN_0043a080();
        pkNode = (AlphaNode*)DAT_011c5f58;
    }
    DAT_011c5f58 = pkNode->m_pkNext;
    pkNode->m_element = 0;
    pkNode->m_pkNext = 0;
    pkNode->m_pkPrev = 0;
    if (--DAT_011c5f84 == 0)
        DAT_011c5f80 = 0;
    return pkNode;
}
// @fnv 0x00b9ac80
void __fastcall AddSortedGroup(BSBatchRenderer* pRenderer, int dummy, SortBound* pBound, bool bFlag1,
                               SortCamera* pCamera, bool bFlag2)
{
    if (pRenderer->m_iActiveGroupCount == 0 && pCamera != 0)
    {
        GroupStandin** idx = (GroupStandin**)pRenderer->m_pAlphaGeometryGroups;
        AlphaListCursor* pkList = (AlphaListCursor*)((char*)pRenderer->AlphaGeometryList + 4);
        long iRemaining = 2;
        while (iRemaining ? true : false)
        {
            GroupStandin* c;
            c = new GroupStandin;
            BSBatchRenderer__PassList* j = &c->PassTextureSlotCollection;
            j->ResetPassList();
            j->m_pCachedListItems = j->pHead;
            j->pHead = 0;
            j->pTail = 0;
            j->Allocator.ItemUpdateArray = 0;
            if (c->m_pGroupRenderer)
                c->m_pGroupRenderer->ClearAllGroups(0);
            c->m_usPassCountLocal = 0;
            if (bFlag2)
            {
                SortPt pkPos = pCamera->GetWorldTranslation();
                float res = pBound->kTargetCenter * pkPos;
                c->m_fProjectionDepth = res - pBound->fRadius;
            }
            else
            {
                SortPt pkPos;
                pkPos = pCamera->GetWorldTranslation();
                c->m_fProjectionDepth = pBound->kTargetCenter * pkPos;
            }
            if (!bFlag1)
                c->m_ucEntryType |= 1;
            else
                c->m_ucEntryType &= 0xfe;
            AlphaNode* pkNew = ListHead(pkList);
            bool pkGroup = false;
            while (pkGroup == 0)
            {
                if (pkNew == 0)
                    break;
                if (pkNew->m_element->m_fProjectionDepth < c->m_fProjectionDepth)
                {
                    AlphaNode* val = PoolCreateNode();
                    val->m_element = c;
                    val->m_pkNext = pkNew;
                    val->m_pkPrev = pkNew->m_pkPrev;
                    if (pkNew->m_pkPrev)
                        pkNew->m_pkPrev->m_pkNext = val;
                    else
                        ListHead(pkList) = val;
                    pkNew->m_pkPrev = val;
                    pkList->m_kItemCount.m_uiCount += 1;
                    pkGroup = true;
                }
                pkNew = pkNew->m_pkNext;
            }
            if (pkGroup == 0)
            {
                AlphaNode* val = pkList->m_kItemCount.FUN_0043a010();
                val->m_element = c;
                val->m_pkNext = 0;
                val->m_pkPrev = pkList->m_pkTail;
                if (pkList->m_pkTail)
                    pkList->m_pkTail->m_pkNext = val;
                else
                    ListHead(pkList) = val;
                ++pkList->m_kItemCount.m_uiCount;
                pkList->m_pkTail = val;
            }
            *idx = c;
            idx++;
            pkList = (AlphaListCursor*)((char*)pkList + 12);
            iRemaining--;
        }
        pRenderer->m_bHasActiveGroups = bFlag1;
    }
    pRenderer->m_iActiveGroupCount += 1;
}
}  // namespace fnv_00b9ac80

class DummyPointerMap
{
  public:
    bool GetAt(unsigned int uiKey, unsigned int& ruiValue) const;
};

class B999Renderer
{
  public:
    int unk00, unk04, unk08;
    DummyPointerMap m_kPassMap;
    int unk10, unk14, unk18, unk1C;
    unsigned int m_uiCurrentFirstPass;
    unsigned int m_uiCurrentLastPass;
    int unk28;
    BSSimpleList<unsigned short> m_kActivePassIndexList;

    bool FUN_00b98ae0(unsigned int uiValue, int iSubBucketIndex);
    bool FUN_00b99900(unsigned int& ruiPass, int iSubBucketIndex);
};

// When a list value is in range, removes the head, looks up that value, and calls FUN_00b98ae0.
// @fnv 0x00b99900
bool B999Renderer::FUN_00b99900(unsigned int& ruiPass, int iSubBucketIndex)
{
    BSSimpleList<unsigned short>* pkList = &m_kActivePassIndexList;
    if (!pkList->m_pkNext && !pkList->m_item)
        return false;

    ruiPass = pkList->m_item;
    while (ruiPass < m_uiCurrentFirstPass)
    {
        pkList = pkList->m_pkNext;
        if (!pkList)
            return false;
        ruiPass = pkList->m_item;
    }
    if (ruiPass > m_uiCurrentLastPass)
        return false;

    {
        m_kActivePassIndexList.RemoveHead();
        unsigned int uiValue = 0;
        m_kPassMap.GetAt(ruiPass, uiValue);
        return FUN_00b98ae0(uiValue, iSubBucketIndex);
    }
}

namespace fnv_00b99110 {
extern bool __cdecl FUN_00b630f0(unsigned int);
extern bool DAT_011ad8ec;
struct DrawPartition
{
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
    unsigned int vertexData;
};
struct PartitionFlags
{
    unsigned char active, continuation, unk2, unk3;
};
struct SkinData
{
    unsigned int unk0, unk4, count;
    DrawPartition* partitions;
};
extern unsigned int DAT_011f49d8;
struct SkinInstance
{
    virtual void v0();
    virtual void v1();
    virtual void* GetType();
    unsigned int unk4, unk8;
    SkinData* data;
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
    PartitionFlags* flags;
};
struct DrawShader;
struct DrawBound
{
    float x, y, z, radius;
};
extern DrawBound DAT_011f4288;
struct DrawGeometry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    DrawBound* unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    struct DrawData* data;
    SkinInstance* skin;
    DrawShader* shader;
    __declspec(noinline) const DrawBound& FUN_0043d450() const
    {
        return unk20 ? *unk20 : DAT_011f4288;
    }
};
struct DrawRenderer;
struct DrawData
{
    unsigned int unk0, unk4, unk8;
    unsigned short unkC, flags;
};
struct DrawShader
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void Setup(DrawGeometry*, SkinInstance*, DrawPartition*, unsigned int, void*, unsigned int, void*,
                       const DrawBound&);
    virtual void v26();
    virtual void* Draw(DrawGeometry*, DrawPartition*, unsigned int, void*);
    virtual void v28();
    virtual void v29();
    virtual void Begin(void*);
    virtual void State(void*);
    virtual void Alpha(void*);
    virtual void Depth(void*);
    virtual void Blend(void*, bool);
    virtual void End(void*);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void Reset(void*);
};
struct DrawContext
{
    void ProcessCollector(void*, DrawData*, SkinInstance*, unsigned int, unsigned int, unsigned int);
};
struct DrawRenderer
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    void* current;
    unsigned int currentIndex;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    void FUN_00e6d310(void*, DrawPartition*, DrawData*);
    DrawContext* context;
    void* driver;
    void SetProperties(void* properties)
    {
        current = properties;
        currentIndex = 0;
    }
};
extern DrawRenderer* DAT_011f4748;
extern unsigned int DAT_011f49d8;
struct DrawPass
{
    DrawGeometry* geometry;
    unsigned short pass;
    unsigned char unk6;
    bool alpha;
};
inline bool S00b99110_IsExact(void* rtti, SkinInstance* obj)
{
    if (!obj)
        return false;
    return obj->GetType() == rtti;
}
// Sets up the renderer and shader, then iterates skin partitions to draw geometry with optional alpha, depth, and blend state handling.
// @fnv 0x00b99110
void __cdecl FUN_00b99110(DrawPass* pass, bool depth, bool alpha, bool blend)
{
    unsigned int passId = pass->pass;
    DrawRenderer* renderer = DAT_011f4748;
    DrawGeometry* geometry = pass->geometry;
    SkinInstance* skin = geometry->skin;
    DrawData* data = geometry->data;
    DrawShader* shader = geometry->shader;
    SkinData* skinData = skin->data;
    unsigned int* properties = &geometry->unk9c;
    DrawPartition* partitions = skinData->partitions;
    renderer->SetProperties(properties);
    renderer->context->ProcessCollector(renderer->driver, data, skin, 1, 0, 0);
    unsigned int count = skinData->count;
    PartitionFlags* flags = 0;
    if (S00b99110_IsExact(&DAT_011f49d8, skin))
        flags = skin->flags;
    bool first = true;
    unsigned int i = 0;
    while (i < count)
    {
        if (!flags || flags[i].active)
        {
            DrawPartition* partition = &partitions[i];
            unsigned int vertexData = partition->vertexData;
            const DrawBound& geometryFlags = geometry->FUN_0043d450();
            shader->Setup(geometry, skin, partition, vertexData, properties, 0, &geometry->unk68, geometryFlags);
            if (first)
            {
                shader->Begin(properties);
                shader->State(properties);
                if (pass->alpha && !FUN_00b630f0(passId))
                {
                    if (alpha)
                        shader->Alpha(properties);
                    if (depth && !(passId >= 4 && passId <= 5) && !(passId >= 14 && passId <= 15))
                        shader->Depth(properties);
                }
                else if (DAT_011ad8ec)
                {
                    shader->Reset(properties);
                    DAT_011ad8ec = false;
                }
                if (blend)
                    shader->Blend(properties, pass->alpha);
                first = false;
            }
            void* draw = shader->Draw(geometry, partition, vertexData, properties);
            renderer->FUN_00e6d310(draw, partition, data);
            if (flags)
            {
                for (unsigned int next = i + 1; next < count && !flags[i + 1].continuation;)
                {
                    ++i;
                    ++next;
                    if (flags[i].active)
                    {
                        DrawPartition* p = &partitions[i];
                        unsigned int uiVertexData = p->vertexData;
                        draw = shader->Draw(geometry, p, uiVertexData, properties);
                        if (!draw)
                            return;
                        renderer->FUN_00e6d310(draw, p, data);
                    }
                }
            }
        }
        ++i;
    }
    geometry->data->flags &= 0xf000;
    shader->End(properties);
}
}  // namespace fnv_00b99110

struct BSBatchRenderer__ActivePassList_b6359Pool
{
  public:
    void* FUN_00aa3e40(unsigned int size);
};
extern BSBatchRenderer__ActivePassList_b6359Pool DAT_011f6238;

typedef int(__cdecl* ActivePassCompare)(unsigned int, unsigned short);

struct ItemValue
{
    unsigned int value;
};
struct ActivePassNode
{
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
    ActivePassNode(unsigned short x) : item(x), next(0)
    {}
    unsigned short item;
    ActivePassNode* next;
    void InsertItem(ItemValue volatile item, ActivePassCompare cmp);
    void FUN_00b98e20(const unsigned short* item);
};

// Inserts item.value into the linked list of ActivePassNode items, using cmp to find the sorted position.
// @fnv 0x00b99770
void ActivePassNode::InsertItem(ItemValue volatile item, ActivePassCompare afCompare)
{
    unsigned int key = item.value;
    if ((unsigned short)key == 0)
        return;

    ActivePassNode* prev = 0;
    bool done = false;
    ActivePassNode* cur = this;
    if (cur == 0)
        return;

    while (cur != 0)
    {
        if (done)
            break;

        if (cur->item == 0)
        {
            cur->item = (unsigned short)key;
            done = true;
        }
        else if (afCompare(key, cur->item) <= 0)
        {
            if (prev == 0)
            {
                this->FUN_00b98e20((const unsigned short*)&item);
            }
            else
            {
                ActivePassNode* n = new ActivePassNode((unsigned short)key);
                prev->next = n;
                n->next = cur;
            }
            done = true;
        }
        else
        {
            if (cur->next == 0)
            {
                ActivePassNode* n = new ActivePassNode((unsigned short)key);
                cur->next = n;
                done = true;
            }
        }
        prev = cur;
        cur = cur->next;
    }
}

namespace fnv_00b99a90 {
struct Node
{
    Node* m_next;
    Node* m_pSecondNode;
    int m_uiFilterValue;
};

struct Entry
{
    int m_unk00;
    Node* m_pHeadNode;
    Node* m_last;
    Node* m_free;
    int m_uiItemCount;
};

struct Thing
{
    char pad[0x64];
    int m_total;
    void AddNode(int index, int value);
};

extern "C" Node* __fastcall FUN_0043a010(void* alloc);

// Allocates or reuses a free node, stores value, and prepends it to the entry's linked list, updating counts.
// @fnv 0x00b99a90
void Thing::AddNode(int index, int value)
{
    Entry* entry = (Entry*)((char*)this + index * 0x14);
    Node* node;
    if (entry->m_free == 0)
    {
        node = FUN_0043a010(&entry->m_uiItemCount);
    }
    else
    {
        node = entry->m_free;
        entry->m_free = node->m_next;
    }
    node->m_uiFilterValue = value;
    node->m_next = entry->m_pHeadNode;
    node->m_pSecondNode = 0;
    if (entry->m_pHeadNode != 0)
    {
        entry->m_pHeadNode->m_pSecondNode = node;
        entry->m_pHeadNode = node;
        entry->m_uiItemCount++;
        m_total++;
        return;
    }
    entry->m_last = node;
    entry->m_pHeadNode = node;
    entry->m_uiItemCount++;
    m_total++;
}
}  // namespace fnv_00b99a90

namespace fnv_00b99b00 {
struct Node
{
    Node* m_next;
    Node* m_pSecondNode;
    int m_uiFilterValue;
};

struct Entry
{
    int m_unk00;
    Node* m_pHeadNode;
    Node* m_last;
    Node* m_free;
    int m_uiItemCount;
};

struct Thing
{
    char pad[0x64];
    int m_total;
    void AppendNode(int index, int value);
};

extern "C" Node* __fastcall FUN_0043a010(void* alloc);

// Allocates or reuses a Node, sets its value, and appends it to the linked list at the given index.
// @fnv 0x00b99b00
void Thing::AppendNode(int index, int value)
{
    Entry* entry = (Entry*)((char*)this + index * 0x14);
    Node* node;
    if (entry->m_free == 0)
    {
        node = FUN_0043a010(&entry->m_uiItemCount);
    }
    else
    {
        node = entry->m_free;
        entry->m_free = node->m_next;
    }
    node->m_uiFilterValue = value;
    node->m_next = 0;
    node->m_pSecondNode = entry->m_last;
    if (entry->m_last != 0)
    {
        entry->m_last->m_next = node;
        entry->m_last = node;
        entry->m_uiItemCount++;
        m_total++;
        return;
    }
    entry->m_pHeadNode = node;
    entry->m_last = node;
    entry->m_uiItemCount++;
    m_total++;
}
}  // namespace fnv_00b99b00

struct NiProperty99
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
    bool GetAlphaBlending() const
    {
        return (bool)(m_usFlags & 1);
    }
    bool GetAlphaTesting() const
    {
        return (bool)((m_usFlags >> 9) & 1);
    }
};
struct ShaderProperty99
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
    unsigned int m_uiValue1;
    float m_fAlpha;
    float m_fFadeAlpha;
};
struct Geometry99
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
    NiProperty99* m_pkAlphaProperty;
    int unka0;
    int unka4;
    ShaderProperty99* m_pkShaderProperty;
    NiProperty99* m_pkStencilProperty;
};
struct RenderPass99
{
    Geometry99* m_pkRenderableGeometry;
    unsigned short m_usPassEnum;
    unsigned char unk06;
    bool m_bIsAlpha;
};
struct PassGroup99
{
    void ClearPassGroups(bool bFree);
    void AddNode(int iMode, RenderPass99* pkPass);
    void AppendNode(int iMode, RenderPass99* pkPass);
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
    int m_iArrayLength;
};
struct PassMap99
{
    bool GetAt(unsigned int uiKey, unsigned int& uiValue) const;
    void FUN_00844700(unsigned int uiKey, unsigned int uiValue);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
};
struct PassList99
{
    void InsertItem(unsigned int uiPass, int(__cdecl* pfnCompare)(unsigned short, unsigned short));
};
int __cdecl CompareShorts(unsigned short usA, unsigned short usB);

struct S00b99c90_Shell
{
    int unk00;
    int unk04;
    PassGroup99* m_pPassBucketEntries;
    PassMap99 m_kGroupIndexMap;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    PassList99 m_kActivePassList;
    void AddPassToGroup(RenderPass99* pkPass, unsigned int uiPassEnum);
};

// Classifies the pass using shader, stencil, and alpha state, ensures its pass enum has a group index, then adds it to a pass bucket.
// @fnv 0x00b99c90
void S00b99c90_Shell::AddPassToGroup(RenderPass99* pkPass, unsigned int uiPassEnum)
{
    if (!pkPass || !pkPass->m_pkRenderableGeometry)
        return;

    Geometry99* pkGeometry = pkPass->m_pkRenderableGeometry;
    bool bStencil = false;
    ShaderProperty99* pkShaderProp = pkGeometry->m_pkShaderProperty;
    if (pkPass->m_pkRenderableGeometry->m_pkStencilProperty &&
        (pkGeometry->m_pkStencilProperty->m_usFlags & 0xc00) == 0xc00)
        bStencil = true;

    bool bAlpha = false;
    NiProperty99* pkAlphaProp = pkGeometry->m_pkAlphaProperty;
    if (pkAlphaProp)
    {
        bAlpha = pkAlphaProp->GetAlphaTesting() && pkPass->m_bIsAlpha;
        if (bAlpha && (pkShaderProp->m_fAlpha < 1.0f || pkShaderProp->m_fFadeAlpha < 1.0f) &&
            !pkGeometry->m_pkAlphaProperty->GetAlphaBlending() && uiPassEnum != 2)
            bAlpha = false;
    }
    if (uiPassEnum == 0xe || uiPassEnum == 0xf || uiPassEnum == 4 || uiPassEnum == 5 || uiPassEnum == 0x23a)
        bAlpha = true;

    int iGroup;
    if ((pkShaderProp->m_uiValue1 & 0x400000) > 0)
        iGroup = 4;
    else if (bAlpha)
        iGroup = !bStencil + 2;
    else
        iGroup = bStencil ? 1 : 0;

    unsigned int uiPass = pkPass->m_usPassEnum;
    if (uiPassEnum)
        uiPass = uiPassEnum;

    unsigned int uiFound;
    unsigned int uiIndex;
    if (!m_kGroupIndexMap.GetAt(uiPass, uiFound))
    {
        uiIndex = m_kGroupIndexMap.m_uiCount;
        m_kGroupIndexMap.FUN_00844700(uiPass, uiIndex);
        m_pPassBucketEntries[uiIndex].ClearPassGroups(false);
    }
    else
        uiIndex = uiFound;
    if (m_pPassBucketEntries[uiIndex].m_iArrayLength == 0)
        m_kActivePassList.InsertItem(uiPass, CompareShorts);

    if (pkPass->m_bIsAlpha && (uiPass < 0x238 || uiPass > 0x23e))
        m_pPassBucketEntries[uiIndex].AddNode(iGroup, pkPass);
    else
        m_pPassBucketEntries[uiIndex].AppendNode(iGroup, pkPass);
}

namespace fnv_00b9a5b0 {
extern void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" void _ReadWriteBarrier();
extern const void* DAT_010b7dc8[];
extern const void* DAT_0106cf88[];
extern const void* DAT_0106cf68[];

class FUN_00a5d3a0
{
  public:
    const void** vptr;
    unsigned int refCount;
    FUN_00a5d3a0();
    ~FUN_00a5d3a0();
};
struct MapBase
{
    const void** vptr;
    unsigned int hashSize;
    void** buckets;
    unsigned int count;
    MapBase() : vptr(DAT_0106cf88), hashSize(37), count(0)
    {
        buckets = (void**)NiMalloc(37 * sizeof(void*));
        struct S
        {
            unsigned int s;
        };
        S sz = {hashSize * sizeof(void*)};
        fnv_zlib_memset(buckets, 0, sz.s);
    }
    ~MapBase();
};
struct RenderMap : MapBase
{
    RenderMap(int)
    {
        vptr = DAT_0106cf68;
    }
    ~RenderMap();
};
struct ActiveList
{
    unsigned short item;
    ActiveList* next;
    ActiveList()
    {
        item = 0;
        next = 0;
    }
    ~ActiveList();
};
struct AlphaList
{
    void* head;
    void* tail;
    unsigned int count;
    __declspec(noinline) AlphaList()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    __declspec(noinline) ~AlphaList()
    {
        FUN_00b71300();
    }
    void FUN_00b71300();
};
struct FUN_00bd9120
{
    int data;
    FUN_00bd9120();
    static void* operator new(size_t n)
    {
        return g_memoryManager.Allocate(n);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct RenderPassListCollection
{
    BSBatchRenderer__PassList lists[5];
    unsigned int count;
    RenderPassListCollection();
    ~RenderPassListCollection();
    static void* operator new[](size_t n)
    {
        return g_memoryManager.Allocate(n);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct FUN_00b9a560 : BSBatchRenderer__GeometryGroup
{
    FUN_00b9a560(void*) throw();
    static void* operator new(size_t n)
    {
        return g_memoryManager.Allocate(n);
    }
};

struct AudioTlsState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};
extern __declspec(thread) AudioTlsState DAT_01272000;
struct MemGuard
{
    unsigned int oldContext;
    MemGuard(unsigned int value)
    {
        oldContext = DAT_01272000.context;
        DAT_01272000.context = value;
    }
    ~MemGuard()
    {
        DAT_01272000.context = oldContext;
    }
};

class FUN_00b9a5b0 : public FUN_00a5d3a0
{
  public:
    RenderPassListCollection* passes;
    RenderMap map;
    unsigned int passCount;
    unsigned int firstPass;
    unsigned int lastPass;
    FUN_00bd9120* instance;
    ActiveList active;
    int grouping;
    bool zPrePass;
    FUN_00b9a560* groups[13];
    FUN_00b9a560* alpha[2];
    AlphaList alphaLists[2];
    FUN_00b9a560* currentAlpha[2];
    FUN_00b9a5b0(unsigned int count, int mode);
    void ClearAllGroups(int);
};

// Allocates the pass collection and initializes group and alpha entries according to mode; modes 99 and 101 initialize both alpha lists.
// @fnv 0x00b9a5b0
FUN_00b9a5b0::FUN_00b9a5b0(unsigned int aiPassCount, int mode) : map((vptr = DAT_010b7dc8, 0))
{
    MemGuard context(0x26);
    instance = new FUN_00bd9120;
    passes = new RenderPassListCollection[aiPassCount];
    passCount = aiPassCount;
    grouping = 0;
    ClearAllGroups(0);
    switch (mode)
    {
    case 99:
        groups[0] = new FUN_00b9a560((void*)0x2f7);
        groups[1] = new FUN_00b9a560((void*)0x2f7);
        groups[2] = new FUN_00b9a560((void*)0x2f7);
        groups[3] = new FUN_00b9a560((void*)0x2f7);
        groups[4] = new FUN_00b9a560((void*)0x2f7);
        groups[5] = new FUN_00b9a560((void*)0x2f7);
        groups[6] = new FUN_00b9a560((void*)6);
        groups[7] = new FUN_00b9a560((void*)1);
        groups[8] = new FUN_00b9a560((void*)4);
        groups[9] = new FUN_00b9a560((void*)0x2f7);
        groups[10] = new FUN_00b9a560((void*)0x2f7);
        groups[11] = new FUN_00b9a560((void*)6);
        groups[12] = new FUN_00b9a560((void*)4);
        alpha[0] = new FUN_00b9a560((void*)0x2f7);
        alpha[1] = new FUN_00b9a560((void*)0x2f7);
        alpha[0]->m_ucEntryType |= 1;
        alpha[1]->m_ucEntryType |= 1;
        alphaLists[0].FUN_00b71300();
        alphaLists[1].FUN_00b71300();
        break;
    case 100:
        groups[0] = 0;
        groups[1] = 0;
        groups[2] = 0;
        groups[3] = 0;
        groups[4] = 0;
        groups[5] = 0;
        groups[6] = 0;
        groups[7] = 0;
        groups[8] = 0;
        groups[9] = 0;
        groups[10] = 0;
        groups[11] = 0;
        groups[12] = 0;
        alpha[0] = 0;
        alpha[1] = 0;
        break;
    case 101:
        groups[0] = 0;
        groups[1] = 0;
        groups[2] = 0;
        groups[3] = 0;
        groups[4] = 0;
        groups[5] = 0;
        groups[6] = 0;
        groups[7] = 0;
        groups[8] = 0;
        groups[9] = new FUN_00b9a560((void*)0x2f7);
        groups[10] = 0;
        groups[11] = 0;
        groups[12] = 0;
        alpha[0] = new FUN_00b9a560((void*)0x2f7);
        alpha[1] = new FUN_00b9a560((void*)0x2f7);
        alpha[0]->m_ucEntryType |= 1;
        alpha[1]->m_ucEntryType |= 1;
        alphaLists[0].FUN_00b71300();
        alphaLists[1].FUN_00b71300();
        break;
    }
}
}  // namespace fnv_00b9a5b0

namespace fnv_00b99e20 {
extern unsigned char DAT_011f94a6;
extern unsigned char DAT_011f9421;
extern int DAT_011ffa28;
extern int DAT_011ffa24;
extern int DAT_011ff9e8;

void FUN_00bbb840();
bool FUN_00b630f0(unsigned int);

struct RendererState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    bool bFlag164;
    bool bFlag165;
};
RendererState* FUN_00b4f5c0();

void FUN_00b984d0(int, int);
void FUN_00b97ed0(int, int);
int FUN_00b98540(int, int);
void FUN_00b994f0(void*, unsigned short, bool, int, int);
void FUN_00b988e0();

struct BatchPassIndexMap : NiTPointerMap<unsigned int, unsigned int>
{
    __declspec(noalias) bool GetAt(unsigned int key, unsigned int& result) const;
};

struct PassNode
{
    PassNode* m_pkNext;
    PassNode* m_pkPrev;
    void* m_element;
};

struct PassBucket
{
    void** m_ppVirtualMethodTable;
    PassNode* m_pkHead;
    PassNode* m_pkTail;
    int m_uiCount;
    int unk10;
    bool IsEmpty() const
    {
        return m_pkHead == 0;
    }
    PassNode* GetHeadPos() const
    {
        return m_pkHead;
    }
    void* GetNext(PassNode*& kPos) const
    {
        void* const& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct RenderPassListCollection
{
    PassBucket buckets[5];
    int unk64;
    void ClearPassGroups(bool);
};

struct ActivePass
{
    unsigned short m_item;
    ActivePass* m_pkNext;
    bool IsEmpty() const
    {
        return !m_pkNext && !m_item;
    }
    ActivePass* GetHead()
    {
        if (m_pkNext || m_item)
            return this;
        return 0;
    }
};

class BatchRendererQ
{
  public:
    void** m_ppVirtualMethodTable;
    int m_iObjectReferenceCount;
    RenderPassListCollection* m_pPassBucketEntries;
    BatchPassIndexMap m_kGroupIndexMap;
    unsigned int m_uiGroupCount;
    unsigned int m_uiPassCount;
    unsigned int m_uiBucketCount;
    void* m_pGeometryGroupAllocator;
    ActivePass m_kActivePassList;

    __forceinline void RenderGroup(unsigned int uiRenderPassIndex, unsigned int uiPass, int arg3)
    {
        for (int i = 0; i < 5; i++)
        {
            if (m_pPassBucketEntries[uiRenderPassIndex].buckets[i].IsEmpty())
                continue;

            bool bAlpha = false;
            if (i == 0)
            {
                FUN_00b984d0(1, 0);
                FUN_00b97ed0(0, 0);
                if (DAT_011f9421)
                    FUN_00b98540(0, 1);
            }
            else if (i == 1)
            {
                FUN_00b984d0(3, 1);
                FUN_00b97ed0(0, 0);
                if (DAT_011f9421)
                    FUN_00b98540(0, 1);
            }
            else if (i == 2)
            {
                FUN_00b984d0(3, 1);
                FUN_00b97ed0(1, 1);
                bAlpha = true;
                if (DAT_011f9421)
                    FUN_00b98540(1, 1);
            }
            else if (i == 3)
            {
                FUN_00b984d0(1, 1);
                FUN_00b97ed0(1, 1);
                bAlpha = true;
                if (DAT_011f9421)
                    FUN_00b98540(1, 1);
            }
            else if (i == 4)
            {
                FUN_00b984d0(1, 1);
                FUN_00b97ed0(1, 1);
                bAlpha = true;
                if (DAT_011f9421)
                    FUN_00b98540(0, 1);
            }

            PassBucket& kBucket = m_pPassBucketEntries[uiRenderPassIndex].buckets[i];
            PassNode* kPos = kBucket.GetHeadPos();
            while (kPos)
            {
                void* pInfo = kBucket.GetNext(kPos);
                FUN_00b994f0(pInfo, (unsigned short)uiPass, bAlpha, arg3, 0);
            }

            if (DAT_011f9421)
            {
                DAT_011ffa28--;
                FUN_00b98540(0, 0);
            }
            FUN_00b98540(0, 0);
            if (DAT_011ffa24)
                DAT_011ffa24--;
            if (DAT_011ff9e8)
                DAT_011ff9e8--;
        }
        m_pPassBucketEntries[uiRenderPassIndex].ClearPassGroups(false);
    }
    void FUN_00b99e20(unsigned int uiMinPass, unsigned int uiMaxPass, int arg3);
};

// Iterates active passes in range, renders matching groups via RenderGroup, then resets renderer state.
// @fnv 0x00b99e20
void BatchRendererQ::FUN_00b99e20(unsigned int uiMinPass, unsigned int uiMaxPass, int arg3)
{
    unsigned int minPass = uiMinPass;
    unsigned int maxPass = uiMaxPass;
    if (uiMinPass == 0)
    {
        minPass = 1;
        maxPass = 753;
    }

    if (DAT_011f94a6)
        FUN_00bbb840();

    if (!m_kActivePassList.IsEmpty())
    {
        ActivePass* pPass = &m_kActivePassList;
        while (pPass)
        {
            unsigned int item = pPass->m_item;
            if (item > maxPass || item < minPass)
            {
                pPass = pPass->m_pkNext;
                continue;
            }
            {
                unsigned int uiValue = 0;
                m_kGroupIndexMap.GetAt(item, uiValue);

                if (FUN_00b630f0(item) && (FUN_00b4f5c0()->bFlag164 || FUN_00b4f5c0()->bFlag165))
                {
                    m_pPassBucketEntries[uiValue].ClearPassGroups(false);
                    pPass = pPass->m_pkNext;
                    continue;
                }
                RenderGroup(uiValue, item, arg3);
            }
            pPass = pPass->m_pkNext;
        }
    }

    FUN_00b984d0(1, 0);
    FUN_00b97ed0(0, 0);
    FUN_00b988e0();
}
}  // namespace fnv_00b99e20

unsigned MapKeyToHashIndex(const void* map, unsigned key);
bool MapIsKeysEqual(const void* map, unsigned a, unsigned b);
template <class K, class V> struct BatchMapItem
{
    BatchMapItem* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> struct BatchPassMap
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    BatchMapItem<K, V>** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(K key, V& result) const;
};
template <class K, class V> bool BatchPassMap<K, V>::GetAt(K key, V& result) const
{
    unsigned index = MapKeyToHashIndex(this, key);
    BatchMapItem<K, V>* item = m_ppkHashTable[index];
    while (item)
    {
        if (MapIsKeysEqual(this, key, item->m_key))
        {
            result = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

struct BatchPass
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    bool kind;
};
struct BatchLink
{
    BatchLink* next;
    BatchLink* prev;
    BatchPass* pass;
};
struct BatchQueue
{
    int unk00;
    BatchLink* head;
    BatchLink* tail;
    BatchLink* freeHead;
    unsigned count;
    bool IsEmpty() const
    {
        return head == 0;
    }
    BatchPass* const& GetHead() const
    {
        return head->pass;
    }
    void RemoveHead()
    {
        if (head)
        {
            if (head == tail)
                tail = 0;
            BatchLink* next = 0;
            if (head->next)
            {
                next = head->next;
                next->prev = 0;
            }
            if (freeHead)
                freeHead->prev = head;
            head->next = freeHead;
            freeHead = head;
            --count;
            head = next;
        }
    }
};
struct BatchGroup
{
    BatchQueue queues[5];
    unsigned count;
};
extern bool DAT_011f9421;
extern int DAT_011ffa24, DAT_011ff9e8, DAT_011ffa28;
void FUN_00b984d0(int, int);
void FUN_00b97ed0(int, int);
int FUN_00b98540(int, int);
void FUN_00b994f0(void*, unsigned int, bool, int, int);
struct BatchRenderer
{
    int unk00, unk04;
    BatchGroup* groups;
    BatchPassMap<unsigned int, unsigned int> map;
    bool FUN_00b9a090(unsigned&, int&, bool&);
    bool FUN_00b9a120(unsigned&, int&, bool&, int);
};
// Processes a batch queue by applying state, rendering passes, and removing them until a kind change or empty queue is reached.
// @fnv 0x00b9a120
bool BatchRenderer::FUN_00b9a120(unsigned& key, int& bucket, bool& kind, int flags)
{
    unsigned index = 0;
    map.GetAt(key, index);
    bool first = groups[index].queues[bucket].head->pass->kind;
    bool alpha = false;

    if (bucket == 0)
    {
        FUN_00b984d0(1, 0);
        FUN_00b97ed0(0, 1);
        FUN_00b98540(0, 1);
    }
    if (bucket == 1)
    {
        FUN_00b984d0(3, 1);
        FUN_00b97ed0(0, 1);
        FUN_00b98540(0, 1);
    }
    if (bucket == 2)
    {
        FUN_00b984d0(3, 1);
        FUN_00b97ed0(1, 1);
        alpha = true;
        if (DAT_011f9421)
            FUN_00b98540(1, 1);
    }
    if (bucket == 3)
    {
        FUN_00b984d0(1, 1);
        FUN_00b97ed0(1, 1);
        alpha = true;
        if (DAT_011f9421)
            FUN_00b98540(1, 1);
    }
    if (bucket == 4)
    {
        FUN_00b984d0(1, 1);
        FUN_00b97ed0(1, 1);
        alpha = true;
        if (DAT_011f9421)
            FUN_00b98540(0, 1);
    }

    BatchPass* pass = groups[index].queues[bucket].GetHead();
    bool found = false;
    while (pass)
    {
        if (pass->kind != first)
        {
            kind = pass->kind;
            found = true;
            break;
        }
        FUN_00b994f0(pass, key, alpha, flags, 0);
        BatchGroup& group = groups[index];
        group.queues[bucket].RemoveHead();
        --group.count;
        BatchGroup& current = groups[index];
        if (current.queues[bucket].IsEmpty())
            break;
        pass = groups[index].queues[bucket].GetHead();
    }

    if (DAT_011ffa24)
        --DAT_011ffa24;
    if (DAT_011ff9e8)
        --DAT_011ff9e8;
    if (DAT_011f9421)
    {
        --DAT_011ffa28;
        FUN_00b98540(0, 0);
    }
    FUN_00b98540(0, 0);
    bool result = true;
    if (!found)
        result = FUN_00b9a090(key, bucket, kind);
    return result;
}
