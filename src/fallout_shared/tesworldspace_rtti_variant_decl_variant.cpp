
// src/fallout_shared/tesworldspace_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00584e60: the skeleton of src/fallout_shared/tesworldspace_rtti_variant.cpp
// with declarations corrected to what the original code does (tesworldspace_packet_rtti_variant.h: public: bool IsTemporary() const; bool GetHasSpok -> public: virtual void F01(); virtual void F02(); v; tesworldspace_packet_rtti_variant.h: class TESObjectCELL { public: virtual ~TESObje -> class TESObjectCELL : public TESForm { public:; tesworldspace_packet_rtt). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesworldspace_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectCELL, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "tesworldspace_packet_rtti_variant_decl_tesworldspace_rtti_variant.h"
struct GROUP_HEADER
{
    unsigned int uiType;
    unsigned int uiSize;
    unsigned int uiLabel;
    int iGroupType;
};
extern unsigned int kGroupFormType;
TESForm* LookupFormByID(unsigned int);
class FormGroupOwner
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual bool IsParentForm(TESForm* pkForm);
    bool IsFormTypeBelowThreshold(GROUP_HEADER* pkGroup);
    bool FUN_00584d40(GROUP_HEADER* pkGroup);
};
class MobileObject : public TESObjectREFR
{
};
class Actor : public MobileObject
{
};
TESForm* __cdecl LookupFormByID(unsigned int);
struct MapPosition532;
struct FUN_00993820
{
    virtual ~FUN_00993820();
    unsigned int bucketCount;
    MapPosition532** buckets;
    unsigned int size;
    FUN_00993820(int);
    MapPosition532* FUN_004b9ba0();
    void GetNextEntry(MapPosition532*&, Actor*&, unsigned __int64&);
    void SetValue(Actor*, unsigned __int64);
    void FUN_00438af0();
};
struct Child532
{
    void UpdateElements(void*);
};
struct Tail532
{
    void FUN_009a5c40(void*);
};
struct ReferenceArray532
{
    virtual ~ReferenceArray532();
    Child532** data;
    unsigned short capacity, size, effectiveSize, grow;
    unsigned int GetShortAtOffsetA();
    Child532*& FUN_00877a30(unsigned int);
};
struct CombatGroup532 : ReferenceArray532
{
    FUN_00993820* map;
    Tail532* tail;
    void FUN_00993600(void* stream);
};

// The native map enumerates form pointers while cloning each cell into the new world.
struct CellMapAccess545 : NiTPointerMap<unsigned int, TESObjectREFR*>
{
    void FUN_00438af0();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, TESForm*&);
};
struct WorldClone545 : TESWorldSpace
{
    TESForm* FUN_004867a0(bool, TESFile*);
    bool FUN_00587670(TESObjectCELL*);
    void FUN_00588120();
    TESWorldSpace* FUN_00584e60(bool temporary, TESFile* file);
};
// @fnv 0x00584e60
TESWorldSpace* WorldClone545::FUN_00584e60(bool temporary, TESFile* file)
{
    TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(FUN_004867a0(temporary, file));
    static_cast<CellMapAccess545*>(world->cellMap)->FUN_00438af0();
    void* position = static_cast<CellMapAccess545*>(cellMap)->FUN_004b9ba0();
    while (position)
    {
        TESForm* form2 = 0;
        unsigned int key;
        static_cast<CellMapAccess545*>(cellMap)->FUN_006b7f20(position, key, form2);
        if (form2)
        {
            TESObjectCELL* cell3 = dynamic_cast<TESObjectCELL*>(form2->CloneForm(false, file));
            if (cell3)
            {
                cell3->SetAltered(true);
                static_cast<WorldClone545*>(world)->FUN_00587670(cell3);
            }
        }
    }
    TESObjectCELL* persistent3 = GetInteriorCell();
    if (persistent3)
    {
        TESObjectCELL* copy = dynamic_cast<TESObjectCELL*>(persistent3->CloneForm(false, file));
        if (copy)
        {
            world->m_pCell = copy;
            copy->SetAltered(true);
        }
    }
    static_cast<WorldClone545*>(world)->FUN_00588120();
    return world;
}
