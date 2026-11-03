// fallout/interface/listbox_h_unit.cpp: Helper, xEntryMenu, SomeClass (11 functions)

#include "listbox.h"

struct Helper
{
    void FUN_007308e0();
    void* FUN_00731580(unsigned int flags);
};
void __cdecl _Deallocate(void*);
// @fnv 0x00731580
void* Helper::FUN_00731580(unsigned int flags)
{
    FUN_007308e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct WeatherEntry;
typedef int(__cdecl* CmpFunc)(WeatherEntry*, WeatherEntry*);
struct ShellTmp
{
    int _pad;
    BSSimpleList<WeatherEntry*> _list;
    void AssignTileIndices();
    void FUN_007a2e00(CmpFunc a1);
};
// @fnv 0x007a2e00
void ShellTmp::FUN_007a2e00(CmpFunc pCompare)
{
    _list.Sort(pCompare);
    AssignTileIndices();
}

struct WeatherEntry;
struct Unk007a78e0
{
    void ProcessEntries();
};
struct Holder007a49b0
{
    int _pad;
    BSSimpleList<WeatherEntry*> _list;
    void SortWeatherList(int (*)(WeatherEntry*, WeatherEntry*));
};
// Sorts the weather entry list using the given comparison function, then calls ProcessEntries on this object.
// @fnv 0x007a49b0
void Holder007a49b0::SortWeatherList(int (*a1)(WeatherEntry*, WeatherEntry*))
{
    _list.Sort(a1);
    ((Unk007a78e0*)this)->ProcessEntries();
}

struct DummyClass
{
    void FUN_007a28c0();
    void* FUN_007a6160(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_007a28c0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x007a6160
void* DummyClass::FUN_007a6160(unsigned int flags)
{
    FUN_007a28c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S_007a61c0
{
    void FUN_007a4470();
    void* FUN_007a61c0(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_007a4470, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007a61c0
void* S_007a61c0::FUN_007a61c0(unsigned int flags)
{
    FUN_007a4470();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

class ListItemTile
{
  public:
    virtual ~ListItemTile();
};
class ListItemData
{
  public:
    ~ListItemData();
};
template <class T> class ListBoxItem
{
  public:
    ListItemTile* tile;
    T data;
};
struct ListNodeCalls
{
    void FUN_006ecd40(int value);
};
struct TileValueCalls
{
    void FUN_00a012d0(int trait, float value, bool update);
};
int __cdecl TraitNameToID(const char* name);
extern "C" bool s_bAllowDetach;
class FUN_007308e0 : public ListBox<ListItemData*>
{
  public:
    bool FUN_007242c0(unsigned int flag);
    void UpdateScrollPages();
    void FUN_0071a740();
    void FUN_00730950();
};
// @fnv 0x00730950
void FUN_007308e0::FUN_00730950()
{
    while (items.m_pkNext && items.m_pkNext->GetItem())
    {
        BSSimpleList<ListBoxItem<ListItemData*>*>* next = items.m_pkNext->GetNext();
        if (!s_bAllowDetach)
            delete items.m_pkNext->GetItem()->tile;
        if (FUN_007242c0(1))
            delete items.m_pkNext->GetItem()->data;
        delete items.m_pkNext->GetItem();
        ((ListNodeCalls*)items.m_pkNext)->FUN_006ecd40(0);
        delete items.m_pkNext;
        items.m_pkNext = next;
    }
    if (items.m_item)
    {
        if (!s_bAllowDetach)
            delete items.m_item->tile;
        if (FUN_007242c0(1))
            delete items.m_item->data;
        delete items.m_item;
    }
    items.m_item = 0;
    m_usSelectedIndex = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        ((TileValueCalls*)m_pListTile)->FUN_00a012d0(TraitNameToID("_num_filtered"), 0.0f, true);
    UpdateScrollPages();
    m_pSelectedTile = 0;
    FUN_0071a740();
}

template <> class ListBoxItem<unsigned int>
{
  public:
    Tile* pTile;
    unsigned int data;
    bool m_bFiltered;
};
float FUN_004bd510(float value, float step);
int TraitNameToID(const char* name);

struct LB_00730f40 : BSSimpleList<ListBoxItem<unsigned int>*>
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Tile* GetTileAt(unsigned int index, bool b);
    TileListBoxCalls* m_pListTile;
    TileListBoxCalls* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    bool IsEnabled();
    Tile* FUN_00730f40(int event);
};

// Computes a candidate tile from the event and returns it when it differs from the selected tile.
// @fnv 0x00730f40
Tile* LB_00730f40::FUN_00730f40(int event)
{
    Tile* selected = 0;
    int delta = 0;
    switch (event)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = m_pListTile
                    ? (int)FUN_004bd510(
                          -m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(TraitNameToID("_scroll_delta")), 1.0f)
                    : 0;
        break;
    case 16:
        delta = m_pListTile
                    ? (int)FUN_004bd510(
                          m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(TraitNameToID("_scroll_delta")), 1.0f)
                    : 0;
        break;
    }
    if (IsEnabled() && delta && m_usSelectedIndex)
    {
        int index = m_usSelectedIndex - 1;
        int last;
        if (m_pSelectedTile)
        {
            int current = (int)m_pSelectedTile->GetFloat(0xfac);
            last = current + delta;
            if (last < 0)
                last = 0;
            else if (last > index)
                last = index;
        }
        else
        {
            if (delta > 0)
                last = 0;
            else
                last = index;
        }
        while (true)
        {
            BSSimpleList<ListBoxItem<unsigned int>*>* entry = this;
            for (; !selected && entry && entry->GetItem(); entry = entry->GetNext())
            {
                if (((TileListBoxCalls*)entry->GetItem()->pTile)->GetFloat(0xfac) == last)
                    selected = entry->GetItem()->pTile;
            }
            if (selected && !selected->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))
            {
                selected = 0;
                if (delta > 0 && ++last > index)
                {
                    last = index - 1;
                    while ((!selected || !selected->ContainsTrait(GetTileValueID(kListBoxEnabled, -1))) && last >= 0)
                    {
                        selected = GetTileAt(last--, false);
                    }
                    break;
                }
                else if (delta < 0 && --last < 0)
                {
                    last = 1;
                    while ((!selected || !selected->ContainsTrait(GetTileValueID(kListBoxEnabled, -1))) &&
                           last <= index)
                    {
                        selected = GetTileAt(last++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return selected != m_pSelectedTile ? selected : 0;
}

class xEntryObj
{
  public:
    virtual ~xEntryObj();
};

class InventoryStackRecord
{
  public:
    int m_i0;
    ~InventoryStackRecord();
};

struct xEntryItem
{
    xEntryObj* m_pEntryObject;
    InventoryStackRecord* m_pChange;
};

class List_009e03e0
{
  public:
    xEntryItem* m_pInventoryEntryData;
    List_009e03e0* m_pNext;
    ~List_009e03e0();
    xEntryItem** Head();
    List_009e03e0* GetNext();
    void Initialize(unsigned int ui);
};

class xTileT
{
  public:
    void Set(int iKey, float fVal, bool bProp);
};
int xTraitID(const char* pName);
extern bool s_bAllowDetachX;

class xEntryMenu
{
  public:
    int m_i0;
    xEntryItem* m_pSelected;
    List_009e03e0* m_pEntries;
    xTileT* m_pTile;
    int m_i10;
    int m_aiPad[2];
    unsigned short m_us1c;
    float m_f20;
    bool CanDelete(unsigned int ui);
    void Refresh();
    void Rebuild();
    void ClearEntries();
};

// Frees all xEntryItem entries and the selected item, resets m_us1c, m_f20, m_i10, and refreshes the menu.
// @fnv 0x007a2bd0
void xEntryMenu::ClearEntries()
{
    while (m_pEntries && *m_pEntries->Head())
    {
        List_009e03e0* pNext = m_pEntries->GetNext();
        if (!s_bAllowDetachX)
            delete (*m_pEntries->Head())->m_pEntryObject;
        if (CanDelete(1))
            delete (*m_pEntries->Head())->m_pChange;
        delete *m_pEntries->Head();
        m_pEntries->Initialize(0);
        delete m_pEntries;
        m_pEntries = pNext;
    }
    if (m_pSelected)
    {
        if (!s_bAllowDetachX)
            delete m_pSelected->m_pEntryObject;
        if (CanDelete(1))
            delete m_pSelected->m_pChange;
        delete m_pSelected;
    }
    m_pSelected = 0;
    m_us1c = 0;
    m_f20 = 0.0f;
    if (m_pTile)
        m_pTile->Set(xTraitID("_num_filtered"), 0.0f, true);
    Refresh();
    m_i10 = 0;
    Rebuild();
}

struct ClearTile
{
    virtual ~ClearTile();
    void FUN_00a012d0(int, float, bool);
};
struct ClearData
{
    ~ClearData();
};
struct ClearTilePayloadPair
{
    ClearTile* unk00;
    ClearData* unk04;
};
struct ClearNode
{
    ClearTilePayloadPair* unk00;
    ClearNode* unk04;
    ClearTilePayloadPair*& FUN_006815c0();
    ClearNode* FUN_00726070();
    void FUN_006ecd40(ClearTilePayloadPair*);
    ~ClearNode();
};
extern unsigned char DAT_011d8909;
extern const char str_0106f8d0[];
int __cdecl TraitNameToID(const char*);
void __cdecl FormHeap_Free(void*);
struct Target007a4780
{
    void* unk00;
    ClearTilePayloadPair* unk04;
    ClearNode* unk08;
    ClearTile* unk0c;
    ClearTile* unk10;
    void* unk14;
    const char* unk18;
    unsigned short unk1c;
    float unk20;
    bool FUN_007242c0(unsigned int);
    void FUN_007a7d80();
    void UpdateSelectionState();
    void FUN_007a4780();
};
// Clears the entries, resets fields, and calls FUN_00a012d0 on unk0c with a value from TraitNameToID.
// @fnv 0x007a4780
void Target007a4780::FUN_007a4780()
{
    while (unk08 && unk08->FUN_006815c0())
    {
        ClearNode* next = unk08->FUN_00726070();
        if (!DAT_011d8909)
            delete unk08->FUN_006815c0()->unk00;
        if (FUN_007242c0(1))
            delete unk08->FUN_006815c0()->unk04;
        delete unk08->FUN_006815c0();
        unk08->FUN_006ecd40(0);
        delete unk08;
        unk08 = next;
    }
    if (unk04)
    {
        if (!DAT_011d8909)
            delete unk04->unk00;
        if (FUN_007242c0(1))
            delete unk04->unk04;
        delete unk04;
    }
    unk04 = 0;
    unk1c = 0;
    unk20 = 0.0f;
    if (unk0c)
        unk0c->FUN_00a012d0(TraitNameToID(str_0106f8d0), 0.0f, true);
    FUN_007a7d80();
    unk10 = 0;
    UpdateSelectionState();
}

struct LB_007a4d50 : BSSimpleList<ListBoxItem<unsigned int>*>
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual Tile* GetTileAt(unsigned int index, bool b);
    TileListBoxCalls* m_pListTile;
    TileListBoxCalls* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    bool IsEnabled();
    Tile* FUN_007a4d50(int event);
};

// Finds a candidate tile using the event-derived delta, skips disabled tiles, and returns it if it differs from m_pSelectedTile.
// @fnv 0x007a4d50
Tile* LB_007a4d50::FUN_007a4d50(int event)
{
    Tile* pNewTile = 0;
    int iDelta = 0;
    switch (event)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pListTile
                     ? (int)FUN_004bd510(
                           -m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(TraitNameToID("_scroll_delta")), 1.0f)
                     : 0;
        break;
    case 16:
        iDelta = m_pListTile
                     ? (int)FUN_004bd510(
                           m_pListTile->GetFloat(0xfb0) / m_pListTile->GetFloat(TraitNameToID("_scroll_delta")), 1.0f)
                     : 0;
        break;
    }
    if (IsEnabled() && iDelta && m_usSelectedIndex)
    {
        int iTargetIndex;
        int iMaxIndex = m_usSelectedIndex - 1;
        if (m_pSelectedTile)
        {
            int hiIdx = (int)m_pSelectedTile->GetFloat(0xfac);
            iTargetIndex = hiIdx + iDelta;
            if (iTargetIndex < 0)
            {
                iTargetIndex = 0;
            }
            else if (iTargetIndex > iMaxIndex)
            {
                iTargetIndex = iMaxIndex;
            }
        }
        else if (iDelta > 0)
        {
            iTargetIndex = 0;
        }
        else
        {
            iTargetIndex = iMaxIndex;
        }
        while (true)
        {
            for (BSSimpleList<ListBoxItem<unsigned int>*>* node = this; !pNewTile && node && node->GetItem();
                 node = node->GetNext())
            {
                if (((TileListBoxCalls*)node->GetItem()->pTile)->GetFloat(0xfac) == iTargetIndex)
                {
                    pNewTile = node->GetItem()->pTile;
                }
            }
            if (pNewTile && !pNewTile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))
            {
                pNewTile = 0;
                if (iDelta > 0 && ++iTargetIndex > iMaxIndex)
                {
                    iTargetIndex = iMaxIndex - 1;
                    while ((!pNewTile || !pNewTile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1))) &&
                           iTargetIndex >= 0)
                    {
                        pNewTile = GetTileAt(iTargetIndex--, false);
                    }
                    break;
                }
                else if (iDelta < 0 && --iTargetIndex < 0)
                {
                    iTargetIndex = 1;
                    while ((!pNewTile || !pNewTile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1))) &&
                           iTargetIndex <= iMaxIndex)
                    {
                        pNewTile = GetTileAt(iTargetIndex++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return pNewTile != m_pSelectedTile ? pNewTile : 0;
}

class ListBoxBaseWithVTable
{
  public:
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
    virtual Tile* GetTile(int index, int unk) = 0;
};

class SomeClass : public ListBox<BGSNote*>
{
  public:
    Tile* FUN_007a31e0(int param);
};

// Finds an enabled tile at the event-derived target index and returns it when it differs from the current selection.
// @fnv 0x007a31e0
Tile* SomeClass::FUN_007a31e0(int param)
{
    Tile* pResultTile = NULL;
    int delta = 0;

    switch (param)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = m_pListTile
                    ? (int)FUN_004bd510(-((TileListBoxCalls*)m_pListTile)->GetFloat(4016) /
                                            ((TileListBoxCalls*)m_pListTile)->GetFloat(TraitNameToID("_scroll_delta")),
                                        1.0f)
                    : 0;
        break;
    case 16:
        delta = m_pListTile
                    ? (int)FUN_004bd510(((TileListBoxCalls*)m_pListTile)->GetFloat(4016) /
                                            ((TileListBoxCalls*)m_pListTile)->GetFloat(TraitNameToID("_scroll_delta")),
                                        1.0f)
                    : 0;
        break;
    }

    if (IsEnabled() && delta && m_usSelectedIndex)
    {
        int maxIndex = m_usSelectedIndex - 1;
        int targetIndex;

        if (m_pSelectedTile)
        {
            int curIndex = (int)((TileListBoxCalls*)m_pSelectedTile)->GetFloat(4012);
            targetIndex = curIndex + delta;
            if (targetIndex < 0)
                targetIndex = 0;
            else if (targetIndex > maxIndex)
                targetIndex = maxIndex;
        }
        else
        {
            if (delta > 0)
                targetIndex = 0;
            else
                targetIndex = maxIndex;
        }

        while (true)
        {
            for (BSSimpleList<ListBoxItem<BGSNote*>*>* iter = this ? &items : NULL;
                 !pResultTile && iter && iter->GetItem(); iter = iter->GetNext())
            {
                if (((TileListBoxCalls*)iter->GetItem()->tile)->GetFloat(4012) == (float)targetIndex)
                {
                    pResultTile = (Tile*)iter->GetItem()->tile;
                }
            }

            if (pResultTile && !pResultTile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))
            {
                pResultTile = NULL;
                if (delta > 0 && ++targetIndex > maxIndex)
                {
                    targetIndex = maxIndex - 1;
                    while ((!pResultTile || !pResultTile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1))) &&
                           targetIndex >= 0)
                    {
                        pResultTile = ((ListBoxBaseWithVTable*)this)->GetTile(targetIndex--, 0);
                    }
                    break;
                }
                else if (delta < 0 && --targetIndex < 0)
                {
                    targetIndex = 1;
                    while ((!pResultTile || !pResultTile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1))) &&
                           targetIndex <= maxIndex)
                    {
                        pResultTile = ((ListBoxBaseWithVTable*)this)->GetTile(targetIndex++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return (pResultTile != m_pSelectedTile) ? pResultTile : NULL;
}
