
// src/fallout_shared/tesland_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py (flags of tesland_od_variant.cpp) for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesland.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesland_decls.h"
#pragma optimize("", off)
int TruncateFloatToInt(float value);

struct TESForm
{
    virtual ~TESForm();
    void Revert(unsigned int);
};

struct TESObjectLAND : ::TESForm
{
};
struct LandDuplicateCalls
{
    ::TESForm* FUN_004867a0(bool createEditorID, void* copyMap);
};
struct LandDuplicateEntry : LandDuplicateCalls
{
    ::TESForm* FUN_00534880(bool createEditorID, void* copyMap);
};
// @fnv 0x00534880
::TESForm* LandDuplicateEntry::FUN_00534880(bool createEditorID, void* copyMap)
{
    ::TESObjectLAND* duplicate;
    duplicate = dynamic_cast< ::TESObjectLAND*>(FUN_004867a0(false, copyMap));
    return duplicate;
}

__if_exists(::TESForm::Revert)
{
    __if_not_exists(::TESObjectCELL::Revert)
    {
        struct TESObjectCELL : ::TESForm
        {
        };
    }
}
extern void* DAT_01187020;

TESForm* LookupFormByID(unsigned int auiFormId);

struct LandSaveGroup5391
{
    void* typeTag;
    unsigned int unk04;
    unsigned int formID;
    unsigned int groupType;
};

struct LandSaveCell5391
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual bool ContainsGroup(LandSaveGroup5391* group);
};

struct FUN_005391d0_class
{
    LandSaveCell5391* __thiscall FUN_007af430();
    bool __thiscall FUN_005391d0(LandSaveGroup5391* apGroupFORM);
};

// @fnv 0x005391d0
bool FUN_005391d0_class::FUN_005391d0(LandSaveGroup5391* apGroupFORM)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->typeTag == DAT_01187020)
    {
        switch (apGroupFORM->groupType)
        {
        case 8:
        case 9: {
            void* found = dynamic_cast< ::TESObjectCELL*>(LookupFormByID(apGroupFORM->formID));
            if (found && FUN_007af430() == found)
                bretval = false;
            break;
        }
        default: {
            LandSaveCell5391* pCell = FUN_007af430();
            bretval = pCell->ContainsGroup(apGroupFORM);
            break;
        }
        }
    }
    return bretval;
}
