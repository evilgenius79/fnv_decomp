
// src/fallout_shared/tesworldspace_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectCELL, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesworldspace_packet_rtti_variant.h"

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
// @fnv 0x00584d40
bool FormGroupOwner::FUN_00584d40(GROUP_HEADER* pkGroup)
{
    bool bResult = false;
    if (pkGroup && pkGroup->uiType == kGroupFormType)
    {
        switch (pkGroup->iGroupType)
        {
        case 0:
            bResult = IsFormTypeBelowThreshold(pkGroup);
            break;
        case 2:
        case 3:
            bResult = false;
            break;
        case 6: {
            TESObjectCELL* pkCell = dynamic_cast<TESObjectCELL*>(LookupFormByID(pkGroup->uiLabel));
            if (pkCell)
                bResult = IsParentForm((TESForm*)pkCell);
        }
        break;
        case 4:
        case 5:
            break;
        case 1: {
            TESWorldSpace* pkWorld = dynamic_cast<TESWorldSpace*>(LookupFormByID(pkGroup->uiLabel));
            if (pkWorld)
                bResult = IsParentForm((TESForm*)pkWorld);
        }
        break;
        case 7:
            bResult = true;
            break;
        }
    }
    return bResult;
}

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
// @fnv 0x00993600
void CombatGroup532::FUN_00993600(void* stream)
{
    FUN_00993820* oldMapX = map;
    map = new FUN_00993820(0x25);
    MapPosition532* position = oldMapX->FUN_004b9ba0();
    Actor* actor_;
    unsigned __int64 valueTmp;
    unsigned int index;
    Child532* child2;
    while (position)
    {
        oldMapX->GetNextEntry(position, actor_, valueTmp);
        // Persisted pointer-map keys hold a 32-bit form identifier until fixup.
        actor_ = actor_ ? dynamic_cast<Actor*>(LookupFormByID((unsigned int)actor_)) : 0;
        if (actor_)
            map->SetValue(actor_, valueTmp);
    }
    oldMapX->FUN_00438af0();
    delete oldMapX;
    for (index = 0; index < GetShortAtOffsetA(); ++index)
    {
        child2 = FUN_00877a30(index);
        if (child2)
            child2->UpdateElements(stream);
    }
    tail->FUN_009a5c40(stream);
}

class TESClimate : public TESForm
{
};
class TESImageSpace : public TESForm
{
};
class BGSEncounterZone : public TESForm
{
};
class TESWaterForm : public TESForm
{
};
class BGSMusicType : public TESForm
{
};

void __cdecl ResolveFormID5845(unsigned int* puiFormID, TESFile* pkFile);
int __cdecl MasterLog5845(const char* pcFormat, ...);

class TESObjectCELL5845
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
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void LinkPersistent();
};

class CellMap5845
{
  public:
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& uiKey, TESObjectCELL5845*& pkCell);
};

class WorldSpaceOwner5845;
class WorldSpaceLOD5845
{
  public:
    WorldSpaceLOD5845(WorldSpaceOwner5845* pkWorld);
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
};

class WorldSpaceRegion5845
{
  public:
    void Attach(WorldSpaceOwner5845* pkWorld);
};

class WorldSpaceOwner5845
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* GetEditorID() const;

    bool IsTemporary5845();
    TESFile* GetFile(int iIndex);
    int HasEditorID();
    unsigned int GetFormID();
    void SetClimate(TESClimate* p);
    void SetImageSpace(TESImageSpace* p);
    void SetEncounterZone(BGSEncounterZone* p);
    void SetWaterType(TESWaterForm* p);
    void SetLODWaterType(TESWaterForm* p);
    void SetMusicType(BGSMusicType* p);
    void SetParentWorld(TESWorldSpace* p);
    void FinishInit(int i);
    TESObjectCELL5845* GetPersistentCell();
    void FUN_005845e0();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    CellMap5845* m_pkCellMap;
    unsigned int unk34;
    unsigned int unk38;
    WorldSpaceLOD5845* m_pkLOD;
    unsigned int m_uiClimate;
    unsigned int m_uiImageSpace;
    WorldSpaceRegion5845* m_pkRegion;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int m_uiParentWorld;
    unsigned int m_uiWater;
    unsigned int m_uiLODWater;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int m_uiMusicType;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int m_uiEncounterZone;
};

// @fnv 0x005845e0
void WorldSpaceOwner5845::FUN_005845e0()
{
    if (!IsTemporary5845())
    {
        unsigned int uiFormIDA;
        uiFormIDA = m_uiClimate;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            TESClimate* pkClimate = dynamic_cast<TESClimate*>(LookupFormByID(uiFormIDA));
            if (!pkClimate)
            {
                if (HasEditorID())
                    MasterLog5845("MASTERFILE: Unable to find climate (%08X) on owner worldspace \"%s\".", uiFormIDA,
                                  GetEditorID());
                else
                    MasterLog5845("MASTERFILE: Unable to find climate (%08X) on owner worldspace (%08X).", uiFormIDA,
                                  GetFormID());
            }
            SetClimate(pkClimate);
        }
        uiFormIDA = m_uiImageSpace;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            TESImageSpace* pkImageSpace2 = dynamic_cast<TESImageSpace*>(LookupFormByID(uiFormIDA));
            if (!pkImageSpace2)
            {
                if (HasEditorID())
                    MasterLog5845("MASTERFILE: Unable to find imagespace (%08X) on owner worldspace \"%s\".", uiFormIDA,
                                  GetEditorID());
                else
                    MasterLog5845("MASTERFILE: Unable to find imagespace (%08X) on owner worldspace (%08X).", uiFormIDA,
                                  GetFormID());
            }
            SetImageSpace(pkImageSpace2);
        }
        uiFormIDA = m_uiEncounterZone;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            BGSEncounterZone* pkEncounterZone = dynamic_cast<BGSEncounterZone*>(LookupFormByID(uiFormIDA));
            if (!pkEncounterZone)
            {
                if (HasEditorID())
                    MasterLog5845("Unable to find encounter zone (%08X) on owner worldspace \"%s\".", uiFormIDA,
                                  GetEditorID());
                else
                    MasterLog5845("Unable to find encounter zone (%08X) on owner worldspace (%08X).", uiFormIDA,
                                  GetFormID());
            }
            SetEncounterZone(pkEncounterZone);
        }
        uiFormIDA = m_uiWater;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            TESWaterForm* pkWaterType4 = dynamic_cast<TESWaterForm*>(LookupFormByID(uiFormIDA));
            if (!pkWaterType4)
            {
                if (HasEditorID())
                    MasterLog5845("MASTERFILE: Unable to find water type (%08X) on owner worldspace \"%s\".", uiFormIDA,
                                  GetEditorID());
                else
                    MasterLog5845("MASTERFILE: Unable to find water type (%08X) on owner worldspace (%08X).", uiFormIDA,
                                  GetFormID());
            }
            SetWaterType(pkWaterType4);
        }
        uiFormIDA = m_uiLODWater;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            TESWaterForm* pkLODWaterType3 = dynamic_cast<TESWaterForm*>(LookupFormByID(uiFormIDA));
            if (!pkLODWaterType3)
            {
                if (HasEditorID())
                    MasterLog5845("MASTERFILE: Unable to find lod water type (%08X) on owner worldspace \"%s\".",
                                  uiFormIDA, GetEditorID());
                else
                    MasterLog5845("MASTERFILE: Unable to find lod water type (%08X) on owner worldspace (%08X).",
                                  uiFormIDA, GetFormID());
            }
            SetLODWaterType(pkLODWaterType3);
        }
        uiFormIDA = m_uiMusicType;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            BGSMusicType* kPkMusicType = dynamic_cast<BGSMusicType*>(LookupFormByID(uiFormIDA));
            if (!kPkMusicType)
            {
                if (HasEditorID())
                    MasterLog5845("MASTERFILE: Unable to find music type (%08X) on owner worldspace \"%s\".", uiFormIDA,
                                  GetEditorID());
                else
                    MasterLog5845("MASTERFILE: Unable to find music type (%08X) on owner worldspace (%08X).", uiFormIDA,
                                  GetFormID());
            }
            SetMusicType(kPkMusicType);
        }
        uiFormIDA = m_uiParentWorld;
        if (uiFormIDA)
        {
            ResolveFormID5845(&uiFormIDA, GetFile(-1));
            TESWorldSpace* pkParentWorldVal = dynamic_cast<TESWorldSpace*>(LookupFormByID(uiFormIDA));
            if (!pkParentWorldVal)
            {
                if (HasEditorID())
                    MasterLog5845("MASTERFILE: Unable to find landscape world (%08X) on owner worldspace \"%s\".",
                                  uiFormIDA, GetEditorID());
                else
                    MasterLog5845("MASTERFILE: Unable to find landscape world (%08X) on owner worldspace (%08X).",
                                  uiFormIDA, GetFormID());
            }
            SetParentWorld(pkParentWorldVal);
        }
        if (m_pkRegion)
            m_pkRegion->Attach(this);
        FinishInit(1);
    }
    TESObjectCELL5845* pkPersistent4;
    void* pos2 = m_pkCellMap->GetFirstPos();
    while (pos2)
    {
        unsigned int uiKey3;
        TESObjectCELL5845* pkCell = 0;
        m_pkCellMap->GetNext(pos2, uiKey3, pkCell);
        if (pkCell)
            pkCell->LinkPersistent();
    }
    pkPersistent4 = GetPersistentCell();
    if (pkPersistent4)
        pkPersistent4->LinkPersistent();
    m_pkLOD = new WorldSpaceLOD5845(this);
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);
extern char DAT_01183028, DAT_01183fb4, DAT_0118ac2c;
struct FormX
{
    int FUN_00401170();
    unsigned int FUN_0084e3a0();
    bool IsLessThan(FormX* pkForm);
};
struct WorldX;
struct ChildX
{
    virtual WorldX* GetParentWorld();
};
struct WorldX;
struct CellX
{
    WorldX* FUN_0054ddd0();
};
struct WorldX
{
    unsigned int FUN_0084e3a0();
    bool IsLessThan(FormX* pkForm);
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c(), v20(), v24(), v28(), v2c(), v30(), v34(),
        v38();
    virtual bool IsChildOf(WorldX* pkWorld);
    bool FUN_00584be0(FormX* pkForm);
};
// @fnv 0x00584be0
bool WorldX::FUN_00584be0(FormX* pkForm)
{
    bool bResult = false;
    switch (pkForm->FUN_00401170())
    {
    case 0x39: {
        CellX* pkCell = (CellX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_01183fb4, 0);
        WorldX* pkWorld = pkCell ? pkCell->FUN_0054ddd0() : 0;
        if (pkWorld == this)
            bResult = true;
        else if (pkWorld)
            bResult = IsChildOf(pkWorld);
        break;
    }
    case 0x41:
        if (FUN_0084e3a0() < pkForm->FUN_0084e3a0())
            bResult = true;
        break;
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x69: {
        ChildX* pkChild = (ChildX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_0118ac2c, 0);
        bResult = IsChildOf(pkChild->GetParentWorld());
        break;
    }
    default:
        bResult = IsLessThan(pkForm);
        break;
    }
    return bResult;
}
