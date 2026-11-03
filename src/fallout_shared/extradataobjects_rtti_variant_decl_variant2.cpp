
// src/fallout_shared/extradataobjects_rtti_variant_decl_variant2.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00433db0: the skeleton of src/fallout_shared/extradataobjects_rtti_variant.cpp
// with declarations corrected to what the original code does (extradataobjects_private_packet_rtti_variant.h: class TESObjectREFR { public: virtual ~TESObje -> class TESObjectREFR : public TESForm { public:; extradataobjects_private_packet_rtti_variant.h: TESForm += TESFile* FUN_00484e60(int index);; extradataobjects_additions.h: ExtraDecalRefs += void FUN_004). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/extradataobjects_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR). The skeleton of src/fallout_shared/extradataobjects.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "extradataobjects_private_packet_rtti_variant_decl_extradataobjects_rtti_variant2.h"
// @fnv 0x00877a30
template <> TESObjectREFR*& NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >::GetAt(unsigned int index)
{
    return data[index];
}
#include "extradataobjects_additions_decl_extradataobjects_rtti_variant2.h"
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
// Copies source into pString, reallocating when needed, and returns whether the resulting string is non-empty.
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

void ResolveFormID(unsigned int*, TESFile*);
TESForm* LookupFormByID(unsigned int);
void FUN_005b5e40(const char*, ...);
void __cdecl operator delete(void*);

// Walks m_kDecalReferences, resolving each decal's m_pHitReference form ID against the given TESForm and removing entries that cannot be resolved.
// @fnv 0x00433db0
void ExtraDecalRefs::FUN_00433db0(TESForm* form)
{
    BSSimpleList<ReferenceIntersectionData*>* position = &m_kDecalReferences;
    BSSimpleList<ReferenceIntersectionData*>* previous = 0;
    while (position && !position->IsEmpty())
    {
        bool removed = false;
        ReferenceIntersectionData* decal = position->GetItem();
        unsigned int formID = reinterpret_cast<unsigned int>(decal->m_pHitReference);
        ResolveFormID(&formID, form->FUN_00484e60(-1));
        TESObjectREFR* resolvedB = dynamic_cast<TESObjectREFR*>(LookupFormByID(formID));
        if (!resolvedB)
        {
            FUN_005b5e40("MASTERFILE: Unable to find decal reference %08X.", formID);
            if (previous)
            {
                previous->Remove(decal);
                position = previous->GetNext();
            }
            else
            {
                position->RemoveHead();
            }
            delete decal;
            decal = 0;
            removed = true;
        }
        else
        {
            decal->m_pHitReference = resolvedB;
        }
        if (!removed)
        {
            previous = position;
            position = position->GetNext();
        }
    }
}
