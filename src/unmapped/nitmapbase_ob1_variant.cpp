
// src/unmapped/nitmapbase_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/unmapped/nitmapbase.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_01189c40;
struct FUN_00404b10_class
{
    void* m_p;
    void __thiscall FUN_00404b90(int);
    void* __thiscall Initialize();
};
extern int DAT_01012188;
struct FUN_00404d00_class
{
    void* m_vtbl;
    unsigned char m_kPointB;
    int m_auiShapeKeys[0x41];
    int m_i;
    FUN_00404d00_class();
};
struct AnimSequenceBase;
struct NiTMapItem
{
    NiTMapItem* m_pkNext;
    unsigned short m_usKey;
    AnimSequenceBase* m_pkValue;
};
struct NiTMapBase
{
    virtual ~NiTMapBase();
    unsigned int m_uiHashSize;
    NiTMapItem** m_ppkHashTable;
    virtual unsigned int FUN_0049c390_hash(unsigned short key);
    virtual bool FUN_0049c390_match(unsigned short key, unsigned short usKey);
    bool Lookup(unsigned short key, AnimSequenceBase*& value);
};
struct CombatThreatRecord
{
    ~CombatThreatRecord();
};
struct FUN_009a5270_class
{
    void* __thiscall GetFirstPos();
    void __thiscall GetNext(void*&, unsigned int&, CombatThreatRecord*&);
    void __thiscall RemoveAll();
    void __thiscall DeleteAllEntries();
};
void* __cdecl FormHeap_Allocate(unsigned int size);
extern void* DAT_011c8048;
struct SpawnedObj404a80
{
    char m00[0x120];
    SpawnedObj404a80();
    static void* operator new(unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
};
void __cdecl EnsureSpawnedObj();
class B90Base
{
  public:
    B90Base();
    virtual ~B90Base();

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
};
struct B90Buffer
{
    B90Buffer(int iSize, char cFill);

    int unk00;
};
class FUN_00404b90 : public B90Base
{
  public:
    FUN_00404b90(int iSize);
    virtual ~FUN_00404b90();

    B90Buffer m_kBuffer;
};
struct FUN_00438af0_Item
{
    FUN_00438af0_Item* next;
};
struct FUN_00438af0_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(FUN_00438af0_Item*);
    virtual void vf14();
    virtual void vf18(FUN_00438af0_Item*);

    unsigned int unk04;
    FUN_00438af0_Item** unk08;
    int unk0C;

    void __thiscall FUN_00438af0();
};
inline void FUN_00438af0_Class::vf04()
{}
inline void FUN_00438af0_Class::vf08()
{}
inline void FUN_00438af0_Class::vf0c()
{}
inline void FUN_00438af0_Class::vf10(FUN_00438af0_Item*)
{}
inline void FUN_00438af0_Class::vf14()
{}
inline void FUN_00438af0_Class::vf18(FUN_00438af0_Item*)
{}
void __thiscall FUN_00438af0_Class::FUN_00438af0()
{
    unsigned int index;

    for (index = 0; index < this->unk04; ++index)
    {
        while (this->unk08[index] != 0)
        {
            FUN_00438af0_Item* item = this->unk08[index];
            this->unk08[index] = this->unk08[index]->next;
            this->vf10(item);
            this->vf18(item);
        }
    }

    this->unk0C = 0;
}
struct AnimSequenceBase;
struct MapEntry49c250
{
    MapEntry49c250* m_pkNext;
    unsigned short m_usKey;
    AnimSequenceBase* m_pkValue;
};
struct FUN_0049c250_shell
{
    virtual ~FUN_0049c250_shell();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short left, unsigned short right);
    virtual void SetValue(MapEntry49c250* entry, unsigned short key, AnimSequenceBase* value);
    virtual void ClearValue(MapEntry49c250* entry);
    virtual MapEntry49c250* NewItem();
    virtual void DeleteItem(MapEntry49c250* entry);

    unsigned int m_uiHashSize;
    MapEntry49c250** m_ppkHashTable;
    unsigned int m_uiCount;

    bool FUN_0049c250(unsigned short key);
};
struct C6b7f20_Node
{
    C6b7f20_Node* next;
    unsigned int key;
    void* value;
};
struct C6b7f20_Map
{
    virtual void unknownVirtual();
    virtual unsigned int GetBucket(unsigned int key);
    unsigned int bucketCount;
    C6b7f20_Node** buckets;
    void __thiscall FUN_006b7f20(C6b7f20_Node** position, unsigned int* outKey, void** outValue);
};
struct FUN_00844700_Node
{
    FUN_00844700_Node* next;
    unsigned int key;
    unsigned int value;
};
struct FUN_00844700_Class
{
    virtual void vf00();
    virtual int vf04(unsigned int key);
    virtual bool vf08(unsigned int key, unsigned int nodeKey);
    virtual void vf0c(void* node, unsigned int key, unsigned int value);
    virtual void vf10();
    virtual void* vf14();

    int unk04;
    FUN_00844700_Node** nodes;
    int count;

    void __thiscall FUN_00844700(unsigned int key, unsigned int value);
};
inline int FUN_00844700_Class::vf04(unsigned int)
{
    return 0;
}
inline bool FUN_00844700_Class::vf08(unsigned int, unsigned int)
{
    return false;
}
inline void FUN_00844700_Class::vf0c(void*, unsigned int, unsigned int)
{}
inline void FUN_00844700_Class::vf10()
{}
inline void* FUN_00844700_Class::vf14()
{
    return 0;
}
void __thiscall FUN_00844700_Class::FUN_00844700(unsigned int key, unsigned int value)
{
    int counter = this->vf04(key);
    FUN_00844700_Node* node = this->nodes[counter];
    int index = 0;

    while (node != 0)
    {
        ++index;

        if (this->vf08(key, node->key))
        {
            node->value = value;
            return;
        }

        node = node->next;
    }

    node = static_cast<FUN_00844700_Node*>(this->vf14());
    this->vf0c(node, key, value);
    node->next = this->nodes[counter];
    this->nodes[counter] = node;
    ++this->count;
}
struct AnimSequenceBase;
struct FUN_00a0c6c0_node
{
    FUN_00a0c6c0_node* m_pkNext;
    unsigned int m_uiKey;
    AnimSequenceBase* m_pkValue;
};
struct FUN_00a0c6c0_cls
{
    virtual void FUN_00a0c6c0_v0();
    virtual unsigned int FUN_00a0c6c0_hash(unsigned int key);
    virtual bool FUN_00a0c6c0_match(unsigned int key, unsigned int usKey);
    virtual void FUN_00a0c6c0_v3(FUN_00a0c6c0_node* node, unsigned int key, AnimSequenceBase* value);
    virtual void FUN_00a0c6c0_v4();
    virtual FUN_00a0c6c0_node* FUN_00a0c6c0_v5();
    unsigned int m_uiHashSize;
    FUN_00a0c6c0_node** m_ppkHashTable;
    unsigned int m_uiCount;
    void InsertOrUpdate(unsigned int key, AnimSequenceBase* value);
};
class NiAVObject;
template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer(const NiPointer&);
    ~NiPointer();
    NiPointer& operator=(const NiPointer&);
};
struct MapItem6920
{
    MapItem6920* next;
    unsigned int key;
    NiPointer<NiAVObject> value;
};
struct Map6920
{
    virtual ~Map6920();
    virtual unsigned int Hash(unsigned int);
    virtual bool Equal(unsigned int, unsigned int);
    virtual void Set(MapItem6920*, unsigned int, NiPointer<NiAVObject>);
    virtual void Free(MapItem6920*);
    virtual MapItem6920* Allocate();
    unsigned int hashSize;
    MapItem6920** buckets;
    unsigned int size;
    void FUN_006c6920(unsigned int key, NiPointer<NiAVObject> value);
};
struct RMapItem
{
    RMapItem* m_pkNext;
    unsigned int m_key;
};
class RMapBase
{
  public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2);
    virtual void v0C();
    virtual void ClearValue(RMapItem* pkItem);
    virtual void v14();
    virtual void DeleteItem(RMapItem* pkItem);

    unsigned int m_uiHashSize;
    RMapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    bool FUN_00a1e240(unsigned int key);
};
struct E60Val
{
    int a, b;
    void __thiscall FUN_006e5cc0(E60Val* src);
};
struct E60Item
{
    E60Item* m_pNext;
    unsigned int m_key;
    E60Val m_val;
};
class E60Map
{
  public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int a, unsigned int b);
    unsigned int m_uiHashSize;
    E60Item** m_ppHashTable;
    bool LookupValue(unsigned int key, E60Val& val);
};

typedef void* NiTMapIterator;

struct HeapManager
{
    void Deallocate(void* p);
};
extern HeapManager g_memoryManager;

template <class TKEY, class TVAL> class PtrMapItem
{
  public:
    PtrMapItem* m_pkNext;
    TKEY m_key;
    TVAL m_val;
};

template <class TKEY, class TVAL> class PtrMapBase
{
  public:
    virtual ~PtrMapBase();
    virtual unsigned int KeyToHashIndex(TKEY key) const;
    virtual bool IsKeysEqual(TKEY key1, TKEY key2) const;
    virtual void SetValue(PtrMapItem<TKEY, TVAL>* pkItem, TKEY key, TVAL val);
    virtual void ClearValue(PtrMapItem<TKEY, TVAL>* pkItem);
    virtual PtrMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(PtrMapItem<TKEY, TVAL>* pkItem);

    NiTMapIterator GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(NiTMapIterator& pos, TKEY& key, TVAL& val) const
    {
        PtrMapItem<TKEY, TVAL>* pkItem = (PtrMapItem<TKEY, TVAL>*)pos;

        key = pkItem->m_key;
        val = pkItem->m_val;

        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }

        unsigned int i = KeyToHashIndex(pkItem->m_key);
        for (++i; i < m_uiHashSize; i++)
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

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                PtrMapItem<TKEY, TVAL>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    PtrMapItem<TKEY, TVAL>** m_ppkHashTable;
    unsigned int m_uiCount;
};

struct MapOwnerStandIn
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    PtrMapBase<unsigned int, void*> m_kFormatEntries;

    void FUN_00ec2e50();
};

// @fnv 0x00ec2e50
void MapOwnerStandIn::FUN_00ec2e50()
{
    NiTMapIterator pos = m_kFormatEntries.GetFirstPos();
    while (pos)
    {
        unsigned int uiKey = 0;
        void* pValue = 0;
        m_kFormatEntries.GetNext(pos, uiKey, pValue);
        void* pFree = pValue;
        g_memoryManager.Deallocate(pFree);
    }
    m_kFormatEntries.RemoveAll();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
struct RefX
{
    virtual void v0();
    virtual void DeleteThis();
    long m_ref;
    void AcquireReference()
    {
        InterlockedIncrement(&m_ref);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            DeleteThis();
    }
};
class PtrX
{
  public:
    RefX* m_p;
    PtrX(const PtrX& o) : m_p(o.m_p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    ~PtrX()
    {
        if (m_p)
            m_p->DecRef();
    }
    void FUN_006e5cc0(const PtrX& o);
};
struct ItemX
{
    ItemX* m_pNext;
    unsigned int m_key;
    PtrX m_val;
};
class MapX
{
  public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int a, unsigned int b);
    virtual void SetValue(ItemX* item, unsigned int key, PtrX val);
    virtual void v10();
    virtual ItemX* NewItem();
    unsigned int m_uiHashSize;
    ItemX** m_ppHashTable;
    unsigned int m_uiCount;
    void FUN_00ae7cc0(unsigned int key, PtrX val);
};
inline void DeadX()
{
    int d0;
    int d1;
}
// @fnv 0x00ae7cc0
void MapX::FUN_00ae7cc0(unsigned int key, PtrX val)
{
    DeadX();
    unsigned int index_qtj = KeyToHashIndex(key);
    ItemX* item = m_ppHashTable[index_qtj];
    int depth_h = 0;
    while (item)
    {
        ++depth_h;
        if (IsKeysEqual(key, item->m_key))
        {
            item->m_val.FUN_006e5cc0(val);
            return;
        }
        item = item->m_pNext;
    }
    item = NewItem();
    SetValue(item, key, val);
    item->m_pNext = m_ppHashTable[index_qtj];
    m_ppHashTable[index_qtj] = item;
    m_uiCount++;
}
