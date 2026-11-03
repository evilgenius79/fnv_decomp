// fallout_shared/tescondition.cpp: free functions (14 functions)

#include "tescondition_decls.h"

// Runs the condition on subject and target references, discarding the result and passing false.
// @fnv 0x00680c30
bool PerkEntryConditionSet::ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target)
{
    bool result;
    return ContainsTrait(subject, target, result, false);
}

// Calls InitItem(form) on each TESConditionItem in the list obtained from GetItem(), walking the list until it is empty.
// @fnv 0x00680a20
void PerkEntryConditionSet::InitItem(TESForm* form)
{
    BSSimpleList<TESConditionItem*>* current = (BSSimpleList<TESConditionItem*>*)&m_kConditionItems.GetItem();
    while (current && !current->IsEmpty())
    {
        current->GetItem()->InitItem(form);
        current = current->GetNext();
    }
}

// Deletes each TESConditionItem in the list obtained from GetItem and removes the head until the list is empty.
// @fnv 0x00680fe0
void PerkEntryConditionSet::InitializeConditionItems()
{
    BSSimpleList<TESConditionItem*>* current = (BSSimpleList<TESConditionItem*>*)&m_kConditionItems.GetItem();
    while (current && !current->IsEmpty())
    {
        delete current->GetItem();
        current->RemoveHead();
    }
}

// @fnv 0x00680960
void PerkEntryConditionSet::Load(TESFile* file)
{
    if (file)
    {
        TESConditionItem* item = 0;
        switch (file->GetChunkID())
        {
        case 0x41445443:
            item = new TESConditionItem;
            item->Load(file);
            ((PackageList*)this)->AddPackage((TESPackage*)item);
            break;
        }
    }
}

// @fnv 0x00680b70
bool PerkEntryConditionSet::Compare(PerkEntryConditionSet* other)
{
    BSSimpleList<TESConditionItem*>* left = (BSSimpleList<TESConditionItem*>*)&m_kConditionItems.GetItem();
    BSSimpleList<TESConditionItem*>* right = (BSSimpleList<TESConditionItem*>*)&other->m_kConditionItems.GetItem();
    struct ItemPair
    {
        TESConditionItem* leftItem;
        TESConditionItem* rightItem;
    } items;
    while (right && !right->IsEmpty())
    {
        if (!left || left->IsEmpty())
            return true;
        items.leftItem = left->GetItem();
        items.rightItem = right->GetItem();
        if (items.leftItem->Compare(items.rightItem))
            return true;
        left = left->GetNext();
        right = right->GetNext();
    }
    if (left && !left->IsEmpty())
        return true;
    return false;
}

// @fnv 0x00680c60
bool PerkEntryConditionSet::ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result, bool filter)
{
    struct EvaluationState
    {
        char padding00, padding01, padding02;
        bool unknown;
        TESConditionItem* item;
        char padding10, padding11, padding12;
        bool skip;
        TESObjectREFR* replacement;
        char padding20, padding21;
        bool inOr;
        bool all;
        BSSimpleList<TESConditionItem*>* current;
        bool value;
        bool orFalse;
        bool definiteFalse;
        bool orUnknown;
    } state;
    state.current = (BSSimpleList<TESConditionItem*>*)&m_kConditionItems.GetItem();
    if (state.current->IsEmpty())
    {
        result = false;
        return true;
    }
    state.all = true;
    state.value = false;
    state.inOr = false;
    state.orUnknown = false;
    state.orFalse = false;
    result = false;
    state.definiteFalse = false;
    if (target)
    {
        state.replacement = target->FUN_005693d0();
        if (state.replacement)
            target = state.replacement;
    }
    while (state.current && !state.current->IsEmpty())
    {
        state.item = state.current->GetItem();
        state.skip = false;
        if (filter)
        {
            switch ((int)*(unsigned short*)((TESTopicInfoData*)state.item)->GetLinkToList())
            {
            case 68:
            case 69:
            case 70:
            case 71:
            case 72:
            case 372:
                break;
            default:
                state.skip = true;
            }
        }
        state.unknown = false;
        if (!state.inOr)
        {
            if (!state.item->IsFlagSet())
            {
                state.value = state.skip ? true : state.item->ContainsTrait(subject, target, state.unknown);
                state.all = state.all && state.value;
                if (state.unknown)
                    result = true;
                else if (!state.value)
                    state.definiteFalse = true;
            }
            else
            {
                state.value = state.item->ContainsTrait(subject, target, state.unknown);
                state.inOr = true;
                state.orFalse = false;
                state.orUnknown = state.unknown;
                if (!state.unknown && !state.value)
                    state.orFalse = true;
            }
        }
        else
        {
            if (!state.value)
            {
                state.value = state.skip ? state.skip : state.item->ContainsTrait(subject, target, state.unknown);
                state.orUnknown = state.orUnknown || state.unknown;
                if (!state.unknown && !state.value)
                    state.orFalse = true;
            }
            if (!state.item->IsFlagSet())
            {
                state.inOr = false;
                state.all = state.all && state.value;
                if (!state.all)
                {
                    if (state.orUnknown && !state.orFalse)
                        result = true;
                    else
                        state.definiteFalse = true;
                }
            }
        }
        if (!state.all && !state.inOr && !result)
            break;
        state.current = state.current->GetNext();
    }
    if (state.inOr)
    {
        state.all = state.all && state.value;
        if (!state.all)
        {
            if (state.orUnknown && !state.orFalse)
                result = true;
            else
                state.definiteFalse = true;
        }
    }
    if (state.all || state.definiteFalse)
        result = false;
    return state.all;
}

extern int DAT_01046b48;

struct FUN_005e9530_Obj
{
    void* vftable;
    unsigned char b4;
    unsigned char b5;
    __thiscall FUN_005e9530_Obj();
};

// Sets the object's vftable to DAT_01046b48 and clears bytes b4 and b5, then returns the object.
// @fnv 0x005e9530
void* __fastcall FUN_005e9530(FUN_005e9530_Obj* pThis)
{
    pThis->vftable = &DAT_01046b48;
    pThis->b4 = 0;
    pThis->b5 = 0;
    return pThis;
}

class FUN_006808b0
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
    ~FUN_006808b0();
};

// @fnv 0x006808b0
FUN_006808b0::~FUN_006808b0()
{
    ((PerkEntryConditionSet*)this)->InitializeConditionItems();
}

// Evaluates a comparison condition code (0-5) between two floats and returns true if the comparison holds.
// @fnv 0x00681050
bool __cdecl CompareFloatsByCondition(int aiCondition, float afVal1, float afVal2)
{
    switch (aiCondition)
    {
    case 0:
        if (afVal1 != afVal2)
            return false;
        break;
    case 1:
        if (afVal1 == afVal2)
            return false;
        break;
    case 2:
        if (afVal1 <= afVal2)
            return false;
        break;
    case 3:
        if (afVal1 < afVal2)
            return false;
        break;
    case 4:
        if (afVal1 >= afVal2)
            return false;
        break;
    case 5:
        if (afVal1 > afVal2)
            return false;
        break;
    }
    return true;
}

struct TESItem_680910
{
    void SerializeCondition();
};
struct ListNode_680910
{
    TESItem_680910* item;
    ListNode_680910* _ref_006815c0();
    bool _ref_008256d0();
    ListNode_680910* _ref_00726070();
};
struct FUN_00680910_shell : ListNode_680910
{
    void ProcessItems();
};
// @fnv 0x00680910
void FUN_00680910_shell::ProcessItems()
{
    ListNode_680910* pNode = this->_ref_006815c0();
    while (pNode != 0 && !pNode->_ref_008256d0())
    {
        pNode->_ref_006815c0()->item->SerializeCondition();
        pNode = pNode->_ref_00726070();
    }
}

struct FUN_00680a70_shell
{
    void CopyConditions(PerkEntryConditionSet*, PerkEntryConditionSet*);
};
struct FUN_00404760_shell
{
    void FUN_00404760(PerkEntryConditionSet*);
};
// Passes source to the object at this+0x1c, or an empty value when source is null.
// @fnv 0x00404760
void FUN_00404760_shell::FUN_00404760(PerkEntryConditionSet* source)
{
    if (source)
        ((FUN_00680a70_shell*)((char*)this + 0x1c))->CopyConditions(source, 0);
    else
    {
        PerkEntryConditionSet empty;
        ((FUN_00680a70_shell*)((char*)this + 0x1c))->CopyConditions(&empty, 0);
    }
}

struct FUN_005ea2c0_cls
{
    void FUN_006808b0();
    void* FUN_005ea2c0(unsigned int flags);
};

extern "C" void __stdcall FUN_00ec5fce(void* object, int elementSize, int count, void (FUN_005ea2c0_cls::*callback)());

extern "C" void __cdecl FormHeap_Free(void* apMemory);

// @fnv 0x005ea2c0
void* FUN_005ea2c0_cls::FUN_005ea2c0(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x8, reinterpret_cast<int*>(this)[-1], &FUN_005ea2c0_cls::FUN_006808b0);

        if (flags & 1)
        {
            FormHeap_Free(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    FUN_006808b0();

    if (flags & 1)
    {
        FormHeap_Free(this);
    }

    return this;
}

struct ListOps_680a70
{
    void FUN_00680fe0();
    ListOps_680a70* FUN_006815c0();
    TESForm** FUN_006815c0(PerkEntryConditionSet* other);
    bool FUN_008256d0();
    ListOps_680a70* FUN_00726070();
    void CopyFromRefObj(TESForm* form);
    void FUN_00905820(TESConditionItem** item);
};

// Clears this list, then walks the nodes of a1, appending a new TESConditionItem built from each node's form to the destination list.
// @fnv 0x00680a70
void FUN_00680a70_shell::CopyConditions(PerkEntryConditionSet* apSourceList, PerkEntryConditionSet* a2)
{
    ((ListOps_680a70*)this)->FUN_00680fe0();
    ListOps_680a70* dst = ((ListOps_680a70*)this)->FUN_006815c0();
    ListOps_680a70* src3 = ((ListOps_680a70*)apSourceList)->FUN_006815c0();
    while (src3 != 0 && !src3->FUN_008256d0())
    {
        TESConditionItem* item = new TESConditionItem();
        ((ListOps_680a70*)item)->CopyFromRefObj(*src3->FUN_006815c0(a2));
        dst->FUN_00905820(&item);
        if (dst->FUN_00726070() != 0)
        {
            dst = dst->FUN_00726070();
        }
        src3 = src3->FUN_00726070();
    }
}

struct FUN_00680f70_cls : ListNode_680910
{
    TESItem_680910* GetItemByIndex(int index);
};

// Walks the node list from _ref_006815c0, skipping nodes where _ref_008256d0 is true, and returns the TESItem_680910 at the given index or 0.
// @fnv 0x00680f70
TESItem_680910* FUN_00680f70_cls::GetItemByIndex(int index)
{
    int iCurrent = 0;
    ListNode_680910* pNode = _ref_006815c0();
    while (pNode != 0 && !pNode->_ref_008256d0())
    {
        if (iCurrent == index)
        {
            return *(TESItem_680910**)pNode->_ref_006815c0();
        }
        iCurrent = iCurrent + 1;
        pNode = pNode->_ref_00726070();
    }
    return 0;
}
