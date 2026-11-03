
// src/fallout_shared/extradataobjects_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectREFR). The skeleton of src/fallout_shared/extradataobjects.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "extradataobjects_private_packet_rtti_variant.h"
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

class ExtraDataList
{
  public:
    void FUN_0041f840();
};

struct LitWaterRef
{
    bool IsPersistent();
    ExtraDataList* FUN_005d43c0(void* apOwner, bool abFlag);
};

struct LitWaterOwner
{
    TESFile* GetFile(int aiIndex);
};

void __cdecl ResolveFormID(unsigned int* apFormID, TESFile* apFile);
TESForm* __cdecl LookupFormByID(unsigned int auiFormID);
void __cdecl FNV_Warning(const char* apFormat, ...);

struct ExtraLitWaterRefsStandIn
{
    int unk00;
    int unk04;
    int unk08;
    BSSimpleList<LitWaterRef*> kRefs;
    void FUN_00434050(LitWaterOwner* apOwner);
};

// @fnv 0x00434050
void ExtraLitWaterRefsStandIn::FUN_00434050(LitWaterOwner* apOwner)
{
    BSSimpleList<LitWaterRef*>* pNodeB8 = &kRefs;
    BSSimpleList<LitWaterRef*> kResolved4;
    while (pNodeB8 && !pNodeB8->IsEmpty())
    {
        LitWaterRef* pItem3 = pNodeB8->GetItem();
        unsigned int auiFormId = (unsigned int)pItem3;
        ResolveFormID(&auiFormId, apOwner->GetFile(-1));
        LitWaterRef* pRef = (LitWaterRef*)dynamic_cast<TESObjectREFR*>(LookupFormByID(auiFormId));
        if (!pRef || !pRef->IsPersistent())
        {
            if (!pRef)
                FNV_Warning("MASTERFILE: Unable to find lit water reference %08X.", auiFormId);
            else
                FNV_Warning(
                    "MASTERFILE: Reference %08X is not persistent so cannot reflect or refract other references.",
                    auiFormId);
        }
        else
        {
            pRef->FUN_005d43c0(apOwner, true)->FUN_0041f840();
            kResolved4.AddHead(pRef);
        }
        pNodeB8 = pNodeB8->GetNext();
    }
    kRefs.RemoveAll();
    BSSimpleList<LitWaterRef*>* pIter = &kResolved4;
    while (pIter && pIter->GetItem())
    {
        kRefs.AddHead(pIter->GetItem());
        pIter = pIter->GetNext();
    }
    kResolved4.RemoveAll();
}
