
// src/fallout_shared/extradataobjects_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00433ed0: the skeleton of src/fallout_shared/extradataobjects_rtti_variant.cpp
// with declarations corrected to what the original code does (extradataobjects_private_packet_rtti_variant.h: TESForm += TESFile* FUN_00484e60(int);; extradataobjects_private_packet_rtti_variant.h: TESObjectREFR += bool FUN_005653d0(); class ExtraDataList* FUN_005d43c0();). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/extradataobjects_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR). The skeleton of src/fallout_shared/extradataobjects.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "extradataobjects_private_packet_rtti_variant_decl_extradataobjects_rtti_variant.h"
// @fnv 0x00877a30
template <> TESObjectREFR*& NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >::GetAt(unsigned int index)
{
    return data[index];
}
#include "extradataobjects_additions.h"
int LockExtraData::EnumToNumericValue(LOCK_LEVEL level)
{
    int value = 0;
    switch (level)
    {
    case LOCK_LEVEL_LL_VERYEASY:
        value = GameSettingCollection::iLockLevelMaxVeryEasy.Int()->i;
        break;
    case LOCK_LEVEL_LL_EASY:
        value = GameSettingCollection::iLockLevelMaxEasy.Int()->i;
        break;
    case LOCK_LEVEL_LL_AVERAGE:
        value = GameSettingCollection::iLockLevelMaxAverage.Int()->i;
        break;
    case LOCK_LEVEL_LL_HARD:
        value = GameSettingCollection::iLockLevelMaxHard.Int()->i;
        break;
    case LOCK_LEVEL_LL_VERYHARD:
        value = GameSettingCollection::iLockLevelMaxVeryHard.Int()->i;
        break;
    case LOCK_LEVEL_LL_IMPOSSIBLE:
        value = GameSettingCollection::iLockLevelMaxImpossible.Int()->i;
        break;
    }
    return value;
}
// @fnv 0x00438470
template <> bool BSStringT<char>::Set(const BSStringT<char>& source)
{
    unsigned int length = source.GetLength();
    if (length <= GetMaxLength())
    {
        if (length)
            memcpy(pString, source.GetString(), length + 1);
        else
        {
            if (pString)
                delete[] pString;
            pString = 0;
            length = 0;
            SetMaxLength(length);
        }
    }
    else
    {
        char* old = pString;
        pString = new char[length + 1];
        memcpy(pString, source.GetString(), length + 1);
        if (old)
            delete[] old;
        SetMaxLength(length);
    }
    SetLength(length);
    return length != 0;
}

struct ReflectReference554
{
    TESObjectREFR* m_pWorldReferenceInfo;
    unsigned int flags;
};
class ExtraDataList
{
  public:
    void FUN_0041f4c0(TESForm*, bool);
    void FUN_0041f650(TESForm*, bool);
};
void ResolveFormID(unsigned int*, TESFile*);
TESForm* LookupFormByID(unsigned int);
void FUN_005b5e40(const char*, ...);
void __cdecl operator delete(void*);
struct ReflectReferences554 : BSExtraData
{
    BSSimpleList<ReflectReference554*> references;
    void FUN_00433ed0(TESForm* form);
};
// @fnv 0x00433ed0
void ReflectReferences554::FUN_00433ed0(TESForm* form)
{
    BSSimpleList<ReflectReference554*>* position = &references;
    BSSimpleList<ReflectReference554*>* previous = 0;
    while (position && !position->IsEmpty())
    {
        bool removed = false;
        ReflectReference554* item3 = position->GetItem();
        unsigned int formID5 = reinterpret_cast<unsigned int>(item3->m_pWorldReferenceInfo);
        ResolveFormID(&formID5, form->FUN_00484e60(-1));
        TESObjectREFR* reference_2 = dynamic_cast<TESObjectREFR*>(LookupFormByID(formID5));
        if (!reference_2 || !reference_2->FUN_005653d0())
        {
            if (!reference_2)
                FUN_005b5e40("MASTERFILE: Unable to find water reflector reference %08X.", formID5);
            else
                FUN_005b5e40(
                    "MASTERFILE: Reference %08X is not persistent so cannot reflect or refract other references.",
                    formID5);
            if (previous)
            {
                previous->Remove(item3);
                position = previous->GetNext();
            }
            else
            {
                position->RemoveHead();
            }
            delete item3;
            item3 = 0;
            removed = true;
        }
        else
        {
            if (item3->flags & 1)
                reference_2->FUN_005d43c0()->FUN_0041f4c0(form, true);
            if (item3->flags & 2)
                reference_2->FUN_005d43c0()->FUN_0041f650(form, true);
            item3->m_pWorldReferenceInfo = reference_2;
        }
        if (!removed)
        {
            previous = position;
            position = position->GetNext();
        }
    }
}
