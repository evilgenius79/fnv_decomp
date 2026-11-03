// fallout_shared/tesspelllist.cpp: TESSpellList, TESAttributes, FloatValueProvider, SpellListTask and more (19 functions)

#include "tesspelllist.h"

// @fnv 0x0048d0d0
void TESSpellList::ClearComponent()
{
    ClearSpells();
}

// Removes all entries from the spell list and from the list returned by GetOffsetC.
// @fnv 0x0048d0f0
void TESSpellList::ClearSpells()
{
    BSSimpleList<InventoryStackRecord*>* pFirstList =
        reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData());
    BSSimpleList<InventoryStackRecord*>* pSecondList;
    while (pFirstList && pFirstList->GetItem())
        pFirstList->RemoveHead();

    pSecondList = GetOffsetC();
    while (pSecondList && pSecondList->GetItem())
        pSecondList->RemoveHead();
}

// @fnv 0x0047ffa0
TESAttributes::~TESAttributes()
{
    reinterpret_cast<TESForm*>(this)->IsInCombat();
}

// Constructs a TESSpellList and calls IsInCombat on the object viewed as a TESForm.
// @fnv 0x0048cfe0
TESSpellList::TESSpellList()
{
    reinterpret_cast<TESForm*>(this)->IsInCombat();
}

// @fnv 0x0048d400
void TESSpellList::InitItem(TESForm* owner)
{
    struct SpellCursor
    {
        BSSimpleList<InventoryStackRecord*>* current;
        BSSimpleList<InventoryStackRecord*>* previous;
        TESFile* file;
    } listCursor;
    listCursor.previous = 0;
    listCursor.current =
        reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData());
    listCursor.file = owner ? owner->GetFile(-1) : 0;
    while (listCursor.current && listCursor.current->GetItem())
    {
        struct ResolvedForm
        {
            unsigned int id;
            TESForm* form;
        } resolvedForm;
        resolvedForm.id = reinterpret_cast<unsigned int>(listCursor.current->GetItem());
        TESForm::RemapFormIDForFile(resolvedForm.id, listCursor.file);
        resolvedForm.form = TESForm::GetFormByID(resolvedForm.id);
        {
            struct SpellTypes
            {
                SpellItem* spell;
                TESLevSpell* leveled;
            } spellTypes;
            {
                TESActorBase* actor;
                if (!resolvedForm.form)
                {
                    if (reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.current)->GetNext() ||
                        !listCursor.previous)
                        listCursor.current->RemoveHead();
                    else
                    {
                        BGSCameraShot* pRemovedEntry = reinterpret_cast<BGSCameraShot*>(resolvedForm.id);
                        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(listCursor.previous)->Remove(pRemovedEntry);
                        listCursor.current = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(
                            reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.previous)->GetNext());
                    }
                    if (owner)
                    {
                        if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                            Warning("MASTERFILE: Unable to find Actor Effect (%08X) for owner object \"%s\".",
                                    resolvedForm.id, owner->GetEditorID());
                        else
                            Warning("MASTERFILE: Unable to find Actor Effect (%08X) for owner object (%08X).",
                                    resolvedForm.id, owner->GetFormID());
                    }
                    else
                        Warning("MASTERFILE: Unable to find Actor Effect (%08X) for unknown owner.", resolvedForm.id);
                }
                else
                {
                    spellTypes.spell = dynamic_cast<SpellItem*>(resolvedForm.form);
                    spellTypes.leveled = dynamic_cast<TESLevSpell*>(resolvedForm.form);
                    if (spellTypes.spell)
                    {
                        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(listCursor.current)
                            ->SetItem(reinterpret_cast<BGSCameraShot* const&>(spellTypes.spell));
                        actor = dynamic_cast<TESActorBase*>(this);
                        if (actor && actor == g_thePlayer->GetActorBase())
                            g_thePlayer->OnSpellRemoved(spellTypes.spell);
                        listCursor.previous = listCursor.current;
                        listCursor.current = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(
                            reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.current)->GetNext());
                    }
                    else
                    {
                        if (reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.current)->GetNext() ||
                            !listCursor.previous)
                            listCursor.current->RemoveHead();
                        else
                        {
                            BGSCameraShot* pRemovedEntry = reinterpret_cast<BGSCameraShot*>(resolvedForm.id);
                            reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(listCursor.previous)->Remove(pRemovedEntry);
                            listCursor.current = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(
                                reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.previous)->GetNext());
                        }
                        if (spellTypes.leveled)
                            FUN_0048d210(spellTypes.leveled);
                    }
                }
            }
        }
    }
}

template <> class BSSimpleList<int>
{
  public:
    int item;
    BSSimpleList<int>* next;
    ~BSSimpleList();
};
struct FUN_0048d060 : public BaseFormComponent
{
    BSSimpleList<int> a;
    BSSimpleList<int> b;
    ~FUN_0048d060();
    void ClearComponent();
};
// @fnv 0x0048d060
FUN_0048d060::~FUN_0048d060()
{
    ClearComponent();
}

// @fnv 0x0048d150
int __fastcall GetOffsetC(int apBase)
{
    return apBase + 0xc;
}

struct TESDataHandler
{
    bool FUN_004516b0();
};
extern TESDataHandler* g_dataHandler;
struct LH
{
    bool IsInList(SpellItem* const&) const;
    void AddHead(SpellItem*&);
};
struct PadX
{
    char pad[0x7c];
};
struct FloatValueProvider : public BaseProcess
{
    bool FUN_0048d170(SpellItem* apSpell);
};
struct ZX2 : public PadX, public FloatValueProvider
{
};
// @fnv 0x0048d170
bool FloatValueProvider::FUN_0048d170(SpellItem* apSpell)
{
    if (!apSpell)
        return false;
    if (((LH*)GetCurrentProcessData())->IsInList(apSpell))
        return false;
    ((LH*)GetCurrentProcessData())->AddHead(apSpell);
    if (this == static_cast<FloatValueProvider*>((ZX2*)g_thePlayer->GetActorBase()) && !g_dataHandler->FUN_004516b0())
        g_thePlayer->OnSpellRemoved(apSpell);
    return true;
}

namespace fnv_0048d290 {
struct FUN_0048d290_shell : public TESSpellList
{
    bool FUN_0048d290(TESForm*);
};

class TESDataHandler;
extern TESDataHandler* g_dataHandler;
struct DHX
{
    bool FUN_004516b0();
};
struct ZX2
{
    bool FUN_0048d170(SpellItem*);
    bool FUN_0048d210(TESLevSpell*);
};
// @fnv 0x0048d290
bool FUN_0048d290_shell::FUN_0048d290(TESForm* apSpellIn)
{
    if (((DHX*)g_dataHandler)->FUN_004516b0())
    {
        ((ZX2*)this)->FUN_0048d170((SpellItem*)apSpellIn);
        return true;
    }
    SpellItem* pSpell = dynamic_cast<SpellItem*>(apSpellIn);
    TESLevSpell* pLevSpell = dynamic_cast<TESLevSpell*>(apSpellIn);
    if (pSpell)
        return ((ZX2*)this)->FUN_0048d170(pSpell);
    else if (pLevSpell)
        return ((ZX2*)this)->FUN_0048d210(pLevSpell);
    return false;
}
}  // namespace fnv_0048d290

struct ListNode
{
    ActorPackageContext*& _ref_006815c0();
    ListNode* _ref_00726070();
};
struct Holder_0048d830 : BaseProcess
{
    bool ContainsPackage(ActorPackageContext* package);
};
// @fnv 0x0048d830
bool Holder_0048d830::ContainsPackage(ActorPackageContext* package)
{
    ListNode* node = reinterpret_cast<ListNode*>(GetCurrentProcessData());
    while (node)
    {
        ActorPackageContext* entry = node->_ref_006815c0();
        if (entry == package)
            return true;
        node = node->_ref_00726070();
    }
    return false;
}

struct FUN_0048d880_shell : public BSSimpleList<void*>
{
    BSSimpleList<void*>* GetOffsetC();
    bool FUN_0048d880(void* item);
};

// Walks the list returned by GetOffsetC and returns true if any entry equals item, otherwise false.
// @fnv 0x0048d880
bool FUN_0048d880_shell::FUN_0048d880(void* item)
{
    BSSimpleList<void*>* node = GetOffsetC();
    while (node)
    {
        void* entry = node->GetItem();
        if (entry == item)
            return true;
        node = node->GetNext();
    }
    return false;
}

struct Helper00905330
{
    void _ref_00905330(int&);
};
struct Host0048d8d0 : BaseProcess
{
    void ForwardToHelper(int);
};
// @fnv 0x0048d8d0
void Host0048d8d0::ForwardToHelper(int a)
{
    ((Helper00905330*)GetCurrentProcessData())->_ref_00905330(a);
}

struct SpellListHandle
{
    bool FUN_005f65d0();
    void FUN_005ae3d0();
};
struct SpellListTask
{
    SpellListHandle* GetOffsetC(TESLevSpell*& spell);
    bool FUN_0048d210(TESLevSpell* spell);
};
struct PlayerBaseData
{
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
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
};
struct PlayerProcess : PlayerBaseData, SpellListTask
{
};
struct PlayerProcessAccessor
{
    PlayerProcess* FUN_004181e0();
};
// @fnv 0x0048d210
bool SpellListTask::FUN_0048d210(TESLevSpell* spell)
{
    if (!spell)
        return false;
    if (this == static_cast<SpellListTask*>(reinterpret_cast<PlayerProcessAccessor*>(g_thePlayer)->FUN_004181e0()))
        return false;
    if (GetOffsetC(spell)->FUN_005f65d0())
        return false;
    GetOffsetC(spell)->FUN_005ae3d0();
    return true;
}

struct SpellNode
{
    void*& Item();
    SpellNode* Next();
    int Count();
};

struct SpellListView
{
    SpellNode* SpellsHead();
    SpellNode* LevSpellsHead();
    bool ContainsEntryA(void* spell);
    bool ContainsEntryB(void* lev);
    bool DiffersFrom(BaseFormComponent* apOther);
};

// Compares this spell list against another TESSpellList, returning true if any spell or level spell is missing or the counts differ.
// @fnv 0x0048d700
bool SpellListView::DiffersFrom(BaseFormComponent* apOther)
{
    SpellListView* pOtherList = (SpellListView*)dynamic_cast<TESSpellList*>(apOther);
    if (!pOtherList)
        return true;
    int iSpellCount = 0;
    SpellNode* pSpellNode = SpellsHead();
    while (pSpellNode)
    {
        void* pSpell = pSpellNode->Item();
        if (pSpell)
        {
            if (!pOtherList->ContainsEntryA(pSpell))
                return true;
            iSpellCount++;
        }
        pSpellNode = pSpellNode->Next();
    }
    if (pOtherList->SpellsHead()->Count() != iSpellCount)
        return true;
    {
        int iLevSpellCount = 0;
        SpellNode* pLevSpellNode = LevSpellsHead();
        while (pLevSpellNode)
        {
            void* pLevSpell = pLevSpellNode->Item();
            if (pLevSpell)
            {
                if (!pOtherList->ContainsEntryB(pLevSpellNode->Item()))
                    return true;
                iLevSpellCount++;
            }
            pLevSpellNode = pLevSpellNode->Next();
        }
        if (pOtherList->LevSpellsHead()->Count() != iLevSpellCount)
            return true;
    }
    return false;
}

struct SavedRecord
{
    unsigned int id;
    unsigned char kind;
    unsigned char flags[4];
    unsigned char version;
};
struct TESSaveLoadGame
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857aa0(unsigned int*, unsigned int);
    SavedRecord* CurrentRecord();
    unsigned int Position();
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
TESForm* LookupFormByID(unsigned int);
struct LoadedList
{
    void* item;
    LoadedList* next;
    void RemoveAll();
    void AddHead(SpellItem*&);
    void AddHead(TESLevSpell*&);
    bool IsInList(TESLevSpell*&);
};
struct LoadedSpells
{
    void* vtable;
    LoadedList spells;
    LoadedList leveledSpells;
    void LoadSpellList(unsigned int, unsigned int);
};
// Reads a spell-list block from the save buffer, clearing and refilling the spell and leveled-spell lists and warning on header or size mismatches.
// @fnv 0x0048dca0
void LoadedSpells::LoadSpellList(unsigned int flags, unsigned int unused)
{
    int p;
    if (flags & 16)
    {
        unsigned short h = 0;
        unsigned int a = 0;
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            unsigned int s;
            g_TESSaveLoadGame->FUN_008579e0(&s, 4);
            if (s != 0x424c4f4b)
            {
                SavedRecord* f = g_TESSaveLoadGame->CurrentRecord();
                if (f)
                {
                    TESForm* eb = LookupFormByID(f->id);
                    Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1371, f->id,
                        eb->GetEditorID(), f->version, *(unsigned int*)f->flags);
                }
                else
                {
                    Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1371,
                        g_TESSaveLoadGame->FUN_008df040());
                }
            }
            a = g_TESSaveLoadGame->Position();
            g_TESSaveLoadGame->FUN_008579e0(&h, 2);
        }
        spells.RemoveAll();
        leveledSpells.RemoveAll();
        unsigned short i;
        g_TESSaveLoadGame->FUN_008579e0(&i, 2);
        for (p = 0; p < i; p++)
        {
            unsigned int b;
            g_TESSaveLoadGame->FUN_00857aa0(&b, 4);
            SpellItem* q = dynamic_cast<SpellItem*>(LookupFormByID(b));
            TESLevSpell* cf = dynamic_cast<TESLevSpell*>(LookupFormByID(b));
            if (q)
            {
                spells.AddHead(q);
            }
            else if (cf)
            {
                bool ba = true;
                if (g_TESSaveLoadGame->FUN_008df040() < 71 && leveledSpells.IsInList(cf))
                    ba = false;
                if (ba)
                    leveledSpells.AddHead(cf);
            }
            else
            {
                Warning("MASTERFILE: Could not find spell %08X", b);
            }
        }
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            unsigned int l = g_TESSaveLoadGame->Position();
            SavedRecord* k = g_TESSaveLoadGame->CurrentRecord();
            if (k)
            {
                TESForm* c = LookupFormByID(k->id);
                if (l > a + h)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        l - (a + h), "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1407,
                        k->id, c->GetEditorID(), k->version, *(unsigned int*)k->flags);
                }
                else if (l < a + h)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        a + h - l, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1407,
                        k->id, c->GetEditorID(), k->version, *(unsigned int*)k->flags);
                }
            }
            else
            {
                if (l > a + h)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        l - (a + h), "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1407,
                        g_TESSaveLoadGame->FUN_008df040());
                }
                else if (l < a + h)
                {
                    Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        a + h - l, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1407,
                        g_TESSaveLoadGame->FUN_008df040());
                }
            }
        }
    }
}

class ActorPackageContext
{
  public:
    bool _ref_00440d80();
    unsigned int _ref_0084e3a0();
};
struct TESSpellListShell : TESSpellList
{
    ListNode* _ref_00717e50();
    void FUN_0048d330();
};
void __cdecl FUN_00485910(unsigned int type, unsigned int formId);
// @fnv 0x0048d330
void TESSpellListShell::FUN_0048d330()
{
    ListNode* currentLeveledSpell = _ref_00717e50();
    unsigned int currentSpell;
    ActorPackageContext* spell;
    while (currentLeveledSpell != 0 && (spell = currentLeveledSpell->_ref_006815c0()) != 0)
    {
        if (!spell->_ref_00440d80())
        {
            currentSpell = spell->_ref_0084e3a0();
            FUN_00485910(0x4f4c5053, currentSpell);
        }
        currentLeveledSpell = currentLeveledSpell->_ref_00726070();
    }
    ListNode* leveledSpell = (ListNode*)GetOffsetC();
    {
        ActorPackageContext* formId;
        while (leveledSpell != 0 && (formId = leveledSpell->_ref_006815c0()) != 0)
        {
            if (!formId->_ref_00440d80())
            {
                unsigned int leveledFormId = formId->_ref_0084e3a0();
                FUN_00485910(0x4f4c5053, leveledFormId);
            }
            leveledSpell = leveledSpell->_ref_00726070();
        }
    }
}

namespace fnv_0048da20 {
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};

class TESWorldSpace;
class TES
{
  public:
    TESWorldSpace* GetHitSound();
};

class TESSaveLoadGame
{
  public:
    void FUN_008579b0(void* pData, int size);
    void FUN_00857a10(void* pData, int size);
    bool FUN_00862110();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};

extern GlobalObject_0045cf30 g_011de4e8;

class ActorMagicSpellList
{
  public:
    BSSimpleList<SpellItem*>* GetSpells();
};

class FUN_0048d880_shell
{
  public:
    BSSimpleList<void*>* GetOffsetC();
};

TESForm* LookupFormByID(unsigned int formID);
extern "C" void FUN_0040fbe0(const char* fmt, ...);

class TESSpellList_Target : public TESSpellList
{
  public:
    void SaveSpellList(unsigned int flags);
};

// If flags has bit 0x10, writes a BLOCK header and the spell count plus each spell's form ID to the save stream, with optional timing diagnostics.
// @fnv 0x0048da20
void TESSpellList_Target::SaveSpellList(unsigned int flags)
{
    if (flags & 0x10)
    {
        unsigned short unk0CVal = 0;
        unsigned short* pBlockSize3 = 0;
        unsigned int startPosData;
        unsigned int blok;
        unsigned short spellCount1;
        unsigned short* pNumSpells;
        BSSimpleList<SpellItem*>* curNodePtr;
        SpellItem* spell3;
        unsigned int spellID1;
        BSSimpleList<SpellItem*>* levNode2;
        SpellItem* levSpell2;
        unsigned int leveledID;
        unsigned int currentPos1;
        void* createdObj2;
        TESForm* form;
        unsigned int startBlock;
        unsigned int posNow1;

        startPosData = reinterpret_cast<TimeGlobal*>(g_TESSaveLoadGame)->GetTimeStamp();
        if (*g_011de4e8.Bool())
            startPosData = reinterpret_cast<TimeGlobal*>(g_TESSaveLoadGame)->GetTimeStamp();

        if (g_TESSaveLoadGame->FUN_00862110())
        {
            blok = 0x424C4F4B;
            g_TESSaveLoadGame->FUN_008579b0(&blok, 4);
            pBlockSize3 = (unsigned short*)reinterpret_cast<TimeGlobal*>(g_TESSaveLoadGame)->GetTimeStamp();
            g_TESSaveLoadGame->FUN_008579b0(&unk0CVal, 2);
        }

        spellCount1 = 0;
        pNumSpells = (unsigned short*)reinterpret_cast<TimeGlobal*>(g_TESSaveLoadGame)->GetTimeStamp();
        g_TESSaveLoadGame->FUN_008579b0(&spellCount1, 2);

        curNodePtr = reinterpret_cast<ActorMagicSpellList*>(this)->GetSpells();
        while (curNodePtr)
        {
            spell3 = curNodePtr->GetItem();
            if (spell3)
            {
                spellID1 = spell3->GetFormID();
                g_TESSaveLoadGame->FUN_00857a10(&spellID1, 4);
                spellCount1++;
            }
            curNodePtr = curNodePtr->GetNext();
        }

        levNode2 =
            reinterpret_cast<BSSimpleList<SpellItem*>*>(reinterpret_cast<FUN_0048d880_shell*>(this)->GetOffsetC());
        while (levNode2)
        {
            levSpell2 = levNode2->GetItem();
            if (levSpell2)
            {
                leveledID = levSpell2->GetFormID();
                g_TESSaveLoadGame->FUN_00857a10(&leveledID, 4);
                spellCount1++;
            }
            levNode2 = levNode2->GetNext();
        }

        *pNumSpells = spellCount1;

        if (*g_011de4e8.Bool())
        {
            currentPos1 = reinterpret_cast<TimeGlobal*>(g_TESSaveLoadGame)->GetTimeStamp();
            createdObj2 = reinterpret_cast<TES*>(g_TESSaveLoadGame)->GetHitSound();
            if (createdObj2)
            {
                form = LookupFormByID(*(unsigned int*)createdObj2);
                FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                             currentPos1 - startPosData, *(unsigned int*)createdObj2, form->GetEditorID(),
                             *(unsigned int*)((char*)createdObj2 + 5), 1359,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp");
            }
            else
            {
                FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", currentPos1 - startPosData, 1359,
                             "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp");
            }
        }

        if (g_TESSaveLoadGame->FUN_00862110())
        {
            posNow1 = reinterpret_cast<TimeGlobal*>(g_TESSaveLoadGame)->GetTimeStamp();
            startBlock = (unsigned int)pBlockSize3;
            if (posNow1 > startBlock + 0xFFFF)
            {
                Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp", 1359);
            }
            *pBlockSize3 = (unsigned short)(posNow1 - startBlock);
        }
    }
}
}  // namespace fnv_0048da20

namespace fnv_0048d630 {
struct SpellNode
{
    void*& FUN_006815c0();
    SpellNode* FUN_00726070();
    void FUN_005ae3d0(void*& spell);
};

struct SpellListAccess : TESSpellList
{
    SpellNode* FUN_00717e50();
    void FUN_0048d630(BaseFormComponent* source);
};

// Copies all spells from the source TESSpellList into this list, clearing existing entries first.
// @fnv 0x0048d630
void SpellListAccess::FUN_0048d630(BaseFormComponent* source)
{
    TESSpellList* a = dynamic_cast<TESSpellList*>(source);
    if (a == 0)
        return;

    ClearSpells();

    SpellNode* f = reinterpret_cast<SpellListAccess*>(a)->FUN_00717e50();
    SpellNode* b = FUN_00717e50();
    void* d;
    while (f != 0)
    {
        d = f->FUN_006815c0();
        if (d != 0)
            b->FUN_005ae3d0(d);
        f = f->FUN_00726070();
    }

    SpellNode* e = reinterpret_cast<SpellNode*>(a->GetOffsetC());
    {
        SpellNode* c = reinterpret_cast<SpellNode*>(GetOffsetC());
        while (e != 0)
        {
            void* g = e->FUN_006815c0();
            if (g != 0)
                c->FUN_005ae3d0(g);
            e = e->FUN_00726070();
        }
    }
}
}  // namespace fnv_0048d630

struct S0048d8f0_Record
{
    unsigned int id;
    unsigned char unk04;
    unsigned char flags[4];
};
struct S0048d8f0_SaveGame
{
    bool FUN_00862110();
    S0048d8f0_Record* FUN_004fd3e0();
};
extern S0048d8f0_SaveGame* DAT_011de45c;
struct S0048d8f0_SettingStub
{
    unsigned char* Bool();
};
extern S0048d8f0_SettingStub g_011de4e8;
struct S0048d8f0_FormStub
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
};
S0048d8f0_FormStub* LookupSaveForm(unsigned int formID);
void SaveSizeDebugPrint(const char* fmt, ...);
struct S0048d8f0_SizedList
{
    void* item;
    S0048d8f0_SizedList* next;
    int GetSize();
};
struct S0048d8f0_SpellListSaveSizer
{
    void* vtable;
    S0048d8f0_SizedList spells;
    S0048d8f0_SizedList leveledSpells;
    unsigned short FUN_0048d8f0(unsigned int saveFlags);
};

// When saveFlags bit 0x10 is set, adds two bytes and list-size contributions, plus six bytes when the save-state check succeeds.
// @fnv 0x0048d8f0
unsigned short S0048d8f0_SpellListSaveSizer::FUN_0048d8f0(unsigned int saveFlags)
{
    unsigned short size = 0;
    if (saveFlags & 0x10)
    {
        unsigned short start = size;
        if (DAT_011de45c->FUN_00862110())
        {
            size += 4;
            size += 2;
        }
        size += 2;
        size += spells.GetSize() * 4;
        size += leveledSpells.GetSize() * 4;
        if (*g_011de4e8.Bool())
        {
            S0048d8f0_Record* record = DAT_011de45c->FUN_004fd3e0();
            if (record)
            {
                S0048d8f0_FormStub* form = LookupSaveForm(record->id);
                SaveSizeDebugPrint("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                                   size - start, record->id, form->GetEditorID(), *(unsigned int*)record->flags, 0x51b,
                                   "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp");
            }
            else
            {
                SaveSizeDebugPrint("GetSaveSize(): %-5i ending at line %i in file %s", size - start, 0x51b,
                                   "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSpellList.cpp");
            }
        }
    }
    return size;
}
