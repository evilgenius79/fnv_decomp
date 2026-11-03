
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_01189c40;

struct FUN_00404b10_class
{
    void* m_p;
    void __thiscall FUN_00404b90(int);
    void* __thiscall Initialize();
};

// Calls FUN_00404b90 with DAT_01189c40, sets m_p to "@K@", and returns this.
// @fnv 0x00404b10
void* __thiscall FUN_00404b10_class::Initialize()
{
    FUN_00404b90(DAT_01189c40);
    m_p = "@K@";
    return this;
}

extern int DAT_01012188;
struct FUN_00404d00_class
{
    void* m_vtbl;
    unsigned char m_kPointB;
    int m_auiShapeKeys[0x41];
    int m_i;
    FUN_00404d00_class();
};
// @fnv 0x00404d00
FUN_00404d00_class::FUN_00404d00_class()
{
    m_vtbl = &DAT_01012188;
    m_auiShapeKeys[0x40] = 0;
    m_kPointB = 0;
}

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
// Hashes the key, walks the bucket chain matching keys, and returns the stored value via the out parameter on a hit.
// @fnv 0x0049c390
bool NiTMapBase::Lookup(unsigned short key, AnimSequenceBase*& value)
{
    unsigned int uiIndex = FUN_0049c390_hash(key);
    NiTMapItem* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (FUN_0049c390_match(key, pkItem->m_usKey))
        {
            value = pkItem->m_pkValue;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

namespace fnv_00853130 {
struct CombatThreatRecord
{
    void* m_pThreatActor;
    float fRadius;
    void* m_fStartTime;
};

struct NiTMapItem
{
    NiTMapItem* pkNext;
    unsigned int uiHash;
    CombatThreatRecord* pkData;
};

struct NiTMapBase
{
    int m_uiHashSize;
    NiTMapItem** m_ppkHashTable;
    virtual ~NiTMapBase();
    virtual unsigned int __thiscall GetHash(unsigned int key);
    virtual bool __thiscall Matches(unsigned int key, unsigned int uiHash);
    bool __thiscall GetAt(unsigned int key, CombatThreatRecord*& value);
};

// Looks up key in the hash table, returning true and setting value to the matching item's data, or false if not found.
// @fnv 0x00853130
bool __thiscall NiTMapBase::GetAt(unsigned int key, CombatThreatRecord*& value)
{
    NiTMapItem* item;
    unsigned int index = GetHash(key);
    item = m_ppkHashTable[index];
    while (item)
    {
        if (Matches(key, item->uiHash))
        {
            value = item->pkData;
            return true;
        }
        item = item->pkNext;
    }
    return false;
}
}  // namespace fnv_00853130

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
// Iterates the container's entries, deletes each stored object, then removes all entries.
// @fnv 0x009a5270
void __thiscall FUN_009a5270_class::DeleteAllEntries()
{
    void* position = GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        CombatThreatRecord* pEntry = 0;
        GetNext(position, key, pEntry);
        delete pEntry;
    }
    RemoveAll();
}

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

// Allocates a SpawnedObj404a80 and stores it in DAT_011c8048 if that global is currently null.
// @fnv 0x00404a80
void __cdecl EnsureSpawnedObj()
{
    if (DAT_011c8048 == 0)
    {
        DAT_011c8048 = new SpawnedObj404a80();
    }
}

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

// Constructs the object, initializing m_kBuffer with the given size and a zero fill.
// @fnv 0x00404b90
FUN_00404b90::FUN_00404b90(int iSize) : m_kBuffer(iSize, 0)
{}

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

// Empty virtual function body; does nothing.
// @fnv 0x00438af0
inline void FUN_00438af0_Class::vf00()
{}
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
// @fnv 0x0049c250
bool FUN_0049c250_shell::FUN_0049c250(unsigned short key)
{
    unsigned int hashIndex = KeyToHashIndex(key);
    MapEntry49c250* item = m_ppkHashTable[hashIndex];
    if (item != 0)
    {
        if (IsKeysEqual(key, item->m_usKey))
        {
            m_ppkHashTable[hashIndex] = item->m_pkNext;
            ClearValue(item);
            DeleteItem(item);
            m_uiCount -= 1;
            return true;
        }
        else
        {
            MapEntry49c250* prior = item;
            MapEntry49c250* next = prior->m_pkNext;
            while (next != 0 && !IsKeysEqual(key, next->m_usKey))
            {
                prior = next;
                next = next->m_pkNext;
            }
            if (next != 0)
            {
                prior->m_pkNext = next->m_pkNext;
                ClearValue(next);
                DeleteItem(next);
                m_uiCount -= 1;
                return true;
            }
        }
    }
    return false;
}

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
// Reads the key and value of the node at position, then advances position to the next node or the next non-empty bucket, or null.
// @fnv 0x006b7f20
void C6b7f20_Map::FUN_006b7f20(C6b7f20_Node** position, unsigned int* outKey, void** outValue)
{
    unsigned int bucket;
    {
        C6b7f20_Node* current = *position;
        *outKey = current->key;
        *outValue = current->value;
        if (current->next != 0)
        {
            *position = current->next;
        }
        else
        {
            bucket = GetBucket(current->key);
            ++bucket;
            for (; bucket < bucketCount; ++bucket)
            {
                current = buckets[bucket];
                if (current != 0)
                {
                    *position = current;
                    return;
                }
            }
            *position = 0;
        }
    }
}

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

// Empty inline virtual method body; does nothing.
// @fnv 0x00844700
inline void FUN_00844700_Class::vf00()
{}
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

// Looks up the bucket for key, updates the matching node's value, or allocates a new node, links it into the bucket and increments the count.
// @fnv 0x00a0c6c0
void FUN_00a0c6c0_cls::InsertOrUpdate(unsigned int key, AnimSequenceBase* value)
{
    unsigned int index = FUN_00a0c6c0_hash(key);
    FUN_00a0c6c0_node* item = m_ppkHashTable[index];
    unsigned int n = 0;
    while (item != 0)
    {
        n++;
        if (FUN_00a0c6c0_match(key, item->m_uiKey))
        {
            item->m_pkValue = value;
            return;
        }
        item = item->m_pkNext;
    }
    item = FUN_00a0c6c0_v5();
    FUN_00a0c6c0_v3(item, key, value);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_uiCount++;
}

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
// Looks up key in the bucket chain, replaces the value if found, otherwise allocates a new item, inserts it at the bucket head and increments size.
// @fnv 0x006c6920
void Map6920::FUN_006c6920(unsigned int key, NiPointer<NiAVObject> value)
{
    unsigned int index = Hash(key);
    MapItem6920* item = buckets[index];
    unsigned int count = 0;
    while (item)
    {
        count++;
        if (Equal(key, item->key))
        {
            item->value = value;
            return;
        }
        item = item->next;
    }
    item = Allocate();
    Set(item, key, value);
    item->next = buckets[index];
    buckets[index] = item;
    size++;
}

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

// Looks up the hash bucket for key, unlinks the matching item, clears and deletes it, decrements the count, and returns whether it was found.
// @fnv 0x00a1e240
bool RMapBase::FUN_00a1e240(unsigned int key)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    RMapItem* pkItem = m_ppkHashTable[uiIndex];
    if (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            m_ppkHashTable[uiIndex] = pkItem->m_pkNext;
            ClearValue(pkItem);
            DeleteItem(pkItem);
            m_uiCount--;
            return true;
        }
        else
        {
            RMapItem* pkPrev = pkItem;
            RMapItem* pkCurr = pkPrev->m_pkNext;
            while (pkCurr && !IsKeysEqual(key, pkCurr->m_key))
            {
                pkPrev = pkCurr;
                pkCurr = pkCurr->m_pkNext;
            }
            if (pkCurr)
            {
                pkPrev->m_pkNext = pkCurr->m_pkNext;
                ClearValue(pkCurr);
                DeleteItem(pkCurr);
                m_uiCount--;
                return true;
            }
        }
    }
    return false;
}

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
// Hashes the key, walks the bucket chain comparing keys, copies the matching value into val and returns true, else false.
// @fnv 0x00ae7e60
bool E60Map::LookupValue(unsigned int key, E60Val& val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    E60Item* pkItem = m_ppHashTable[uiIndex];
    int u1, u2;
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            val.FUN_006e5cc0(&pkItem->m_val);
            return true;
        }
        pkItem = pkItem->m_pNext;
    }
    return false;
}

namespace nae7 {
struct Val
{
    int m_p;
    Val& FUN_006e5cc0(const Val& o);
    Val& operator=(const Val& o);
};
struct Item
{
    Item* m_pkNext;
    unsigned int m_key;
    Val m_val;
};
struct Map
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    void FUN_00ae7ee0(Item*& pos, unsigned int& key, Val& val) const;
};
}
// Copies the key and value of the item at pos out, then advances pos to the next item in its chain or the next occupied bucket, or to null at the end.
// @fnv 0x00ae7ee0
void nae7::Map::FUN_00ae7ee0(Item*& pos, unsigned int& key, Val& val) const
{
    __int64 spare;
    Item* pkItem = pos;
    key = pkItem->m_key;
    val.FUN_006e5cc0(pkItem->m_val);
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
