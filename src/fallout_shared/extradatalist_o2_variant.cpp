
// src/fallout_shared/extradatalist_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/extradatalist.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "extradatalist_packet.h"
#include "ExtraDataList.h"
#include "ExtraContainerChanges.h"
#include "InventoryChanges.h"
#include "game_constants.h"

class B5Owner;
class B5Item
{
  public:
    virtual ~B5Item();
    virtual void Free();
    long refCount;
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
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    unsigned int key;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            Free();
    }
};

struct B5Holder
{
    B5Item* q;
    B5Holder(B5Item* x) : q(x)
    {
        InterlockedIncrement(&q->refCount);
    }
    ~B5Holder()
    {
        if (InterlockedDecrement(&q->refCount) == 0)
            q->Free();
    }
};

template <class T> class MyList
{
  public:
    NiTListItem<T>* head;
    NiTListItem<T>* tail;
    struct Allocator
    {
        unsigned int count;
        NiTListItem<T>* FUN_0043a010();
    } allocator;
    __declspec(noinline) void FUN_00a5a310(const T& value)
    {
        NiTListItem<T>* node = allocator.FUN_0043a010();
        node->m_element = value;
        node->m_pkNext = 0;
        node->m_pkPrev = tail;
        if (tail)
            tail->m_pkNext = node;
        else
            head = node;
        ++allocator.count;
        tail = node;
    }
    inline NiTListItem<T>* GetHeadPos() const
    {
        return head;
    }
    inline const T& GetNext(NiTListItem<T>*& pos) const
    {
        const T& el = pos->m_element;
        pos = pos->m_pkNext;
        return el;
    }
};

class B5Owner
{
  public:
    void FUN_00b5eed0(unsigned int key);
    __declspec(noinline) void AddBound(const NiPointer<B5Item>& ptr);
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
    MyList<B5Item*> m_b4;
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
    MyList<NiPointer<B5Item> > pending;
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
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    unsigned char m_1fc;
};

// @fnv 0x00b5eed0
void B5Owner::FUN_00b5eed0(unsigned int key)
{
    if (key == 0)
        return;
    if (m_1fc == 0)
        return;
    NiTListItem<B5Item*>* pos = m_b4.GetHeadPos();
    while (pos)
    {
        B5Item* item = m_b4.GetNext(pos);
        if (item && item->key == key)
        {
            const NiPointer<B5Item> h(item);
            AddBound(h);
            return;
        }
    }
}

struct B5Lock
{
    unsigned int owner;
    unsigned int count;
    void Lock(const char* name);
};
extern B5Lock DAT_011f9ea0;
void B5Owner::AddBound(const NiPointer<B5Item>& ptr)
{
    if (ptr.m_pObject && m_1fc)
    {
        DAT_011f9ea0.Lock(0);
        pending.FUN_00a5a310(ptr);
        if (--DAT_011f9ea0.count == 0)
            DAT_011f9ea0.owner = 0;
    }
}
