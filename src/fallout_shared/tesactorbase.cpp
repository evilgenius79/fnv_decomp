// fallout_shared/tesactorbase.cpp: TESActorBase, Reset3DMobIterator, ActorBaseTarget, ActorBaseSaveView and more (23 functions)

#include "tesactorbase_decls.h"

// @fnv 0x0048cee0
SEX TESActorBase::GetSex()
{
    return reinterpret_cast<MissileProjectile*>(reinterpret_cast<char*>(this) + 4)->GetCharacterSex();
}

// Returns true if the form is an actor base (type 42) whose actor base data has flag 0x10 set; otherwise false.
// @fnv 0x005f0d00
bool TESActorBase::SetPlayable()
{
    if (reinterpret_cast<TESForm*>(this)->GetFormType() == 42)
        return reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)->GetFlag(0x10);
    return false;
}

// @fnv 0x005f1630
void TESActorBase::NotifyFormIDChanged(int changeFlags)
{
    if (g_dataHandler->FormIDExists(reinterpret_cast<TESForm*>(this)->GetFormID()))
    {
        if (g_BGSSaveLoadGame->ShouldSaveForm(reinterpret_cast<TESForm*>(this), false))
            reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)->AddFormChangeFlags(changeFlags);
    }
    else
        reinterpret_cast<TESForm*>(this)->NotifyFormIDChanged(changeFlags);
}

// Loads the actor base from the buffer: base form, actor data, crime, attributes, AI form, and optionally the full name when change flag 0x20 is set.
// @fnv 0x005f1fd0
void TESActorBase::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::LoadGame(buffer);
    reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)->FUN_0047ea70(buffer);
    reinterpret_cast<Crime*>(reinterpret_cast<char*>(this) + 0x7c)->LoadGame(buffer);
    reinterpret_cast<TESAttributes*>(reinterpret_cast<char*>(this) + 0xb8)->LoadDataIfChanged(buffer);
    reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(this) + 0x90)->FUN_0047f980(buffer);
    if (buffer->GetChangeFlags(0x20))
    {
        char name[264];
        buffer->LoadString(name);
        reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 0xd0)->SetFullName(name);
    }
}

// @fnv 0x005f2150
Reset3DMobIterator::Reset3DMobIterator()
{
    FUN_005d8b10();
    vtable = (void*)&DAT_01047670;
}

// If reset is set, runs the 3D mob iterator over this actor base twice and resets the player's process 3D when this is the player's base.
// @fnv 0x005f20a0
void TESActorBase::FUN_005f20a0(bool reset)
{
    if (!reset)
        return;
    Reset3DMobIterator mobIter;
    mobIter.base = this;
    mobIter.reset = reset;
    mobIter.FUN_006ecd40(0);
    g_kProcessLists.ProcessMobileObjects(&mobIter);
    mobIter.FUN_006ecd40(1);
    g_kProcessLists.ProcessMobileObjects(&mobIter);
    if (g_thePlayer->GetActorBase() == this)
    {
        if (g_thePlayer->GetProcess())
            g_thePlayer->GetProcess()->Reset3D(reset);
    }
}

// If the actor's object reference equals base and it has a process, resets that process's 3D state with reset.
// @fnv 0x005f2170
void Reset3DMobIterator::operator()(Actor* actor)
{
    if (actor->GetObjectReference() == base && actor->GetProcess())
        actor->GetProcess()->Reset3D(reset);
}

// @fnv 0x005f1590
bool TESActorBase::ShouldUseDefaultAppearance(TESObjectREFR* ref)
{
    bool result = true;
    if (g_BGSSaveLoadGame->FUN_0042ce10())
    {
        if (static_cast<Actor*>(ref)->FUN_00576d30() &&
            g_BGSSaveLoadGame->HasFormChangeFlags(reinterpret_cast<TESForm*>(ref), GlobalObject_008c71b0(0x08000020)))
            result = false;
    }
    else
    {
        if (ref->IsDead(false) &&
            g_BGSSaveLoadGame->HasFormChangeFlags(reinterpret_cast<TESForm*>(ref), GlobalObject_008c71b0(0x400)))
            result = false;
    }
    return result;
}

struct FUN_005f0b00_shell : public TESActorBase
{
    int FUN_005f0b00();
};

struct VTableHolder_005f0b00
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual int vfn_4();
};

// @fnv 0x005f0b00
int FUN_005f0b00_shell::FUN_005f0b00()
{
    return ((VTableHolder_005f0b00*)((char*)this + 0xb0))->vfn_4();
}

struct FUN_005f0b50_shell : public TESActorBase
{
    bool FUN_005f0b50();
};

// @fnv 0x005f0b50
bool FUN_005f0b50_shell::FUN_005f0b50()
{
    if (GetFormType() == 0x2b)
    {
        if (reinterpret_cast<TESActorBaseData*>((char*)this + 0x30)->GetFlag(0x10) ||
            reinterpret_cast<TESActorBaseData*>((char*)this + 0x30)->GetFlag(1))
            return true;
        else
            return false;
    }
    return true;
}

struct FUN_005f0c80_shell : public TESActorBase
{
    bool FUN_005f0c80();
};

// @fnv 0x005f0c80
bool FUN_005f0c80_shell::FUN_005f0c80()
{
    if (GetFormType() == 0x2b)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x800000))
            return true;
        else
            return false;
    }
    return false;
}

struct BGSBodyPartData
{
    static BGSBodyPartData* ms_pBodyPartDataInstance;
    static BGSBodyPartData* ms_pBodyPartData;
};

// @fnv 0x005f0f80
BGSBodyPartData* __fastcall FUN_005f0f80(TESActorBase* apActorBase)
{
    if (BGSBodyPartData::ms_pBodyPartDataInstance && apActorBase == g_thePlayer->GetActorBase())
        return BGSBodyPartData::ms_pBodyPartDataInstance;
    return BGSBodyPartData::ms_pBodyPartData;
}

struct FUN_005f0b30_shell
{
    void FUN_005f0b30(int a1);
};

// @fnv 0x005f0b30
void FUN_005f0b30_shell::FUN_005f0b30(int aiValue)
{
    ((Reset3DMobIterator*)((char*)this + 0xb0))->FUN_006ecd40(aiValue);
}

bool __fastcall FUN_005f0b50(TESActorBase*);

struct FUN_005f0ba0_shell : TESActorBase
{
    bool FUN_005f0ba0();
};

// @fnv 0x005f0ba0
bool FUN_005f0ba0_shell::FUN_005f0ba0()
{
    if (!FUN_005f0b50(this))
        return false;
    if (GetFormType() == 0x2b)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x40000))
            return false;
    }
    return true;
}

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_005f0f50_shell : ArrSI
{
    char HasFlag80000();
};

// @fnv 0x005f0f50
char __thiscall FUN_005f0f50_shell::HasFlag80000()
{
    unsigned int flags = GetFlags();
    return (flags & 0x80000) != 0;
}

struct Dummy : TESBoundObject
{
    bool FUN_005f0c40();
};
// Returns true if this form is an actor base (type 0x2B) whose actor base data has flag 0x20 set; otherwise false.
// @fnv 0x005f0c40
bool Dummy::FUN_005f0c40()
{
    if (GetFormType() == 0x2B)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x20))
            return true;
        else
            return false;
    }
    return false;
}

struct FUN_0047e360_Cls
{
    void ClearFlags(unsigned int);
};
struct BGSSaveLoadGame_Hack
{
    bool IsFormChanged(TESForm*);
};
struct TESForm_Hack
{
    void MarkAsUnmodified(unsigned int);
};
struct FUN_005f1690_Cls : TESForm
{
    void FUN_005f1690(int);
};
// @fnv 0x005f1690
void FUN_005f1690_Cls::FUN_005f1690(int aiChangeFlags)
{
    if (g_dataHandler->FormIDExists(GetFormID()) && ((BGSSaveLoadGame_Hack*)g_BGSSaveLoadGame)->IsFormChanged(this))
        ((FUN_0047e360_Cls*)((char*)this + 0x30))->ClearFlags(aiChangeFlags);
    else
        ((TESForm_Hack*)this)->MarkAsUnmodified(aiChangeFlags);
}

struct FNStub
{
    const char* GetFullName();
};
struct BGSSaveGameBuffer
{
    void SaveGameString(const char*, int);
};
struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0047ea30_holder
{
    void FUN_0047ea30(unsigned int);
};
struct FUN_0048e040_holder
{
    void FUN_0048e040(unsigned int);
};
struct FUN_00480270_holder
{
    void FUN_00480270(unsigned int);
};
struct FUN_0047f940_holder
{
    void SaveChangeData(unsigned int);
};
struct FUN_005f1f30_shell : public BGSLoadFormBuffer
{
    void FUN_005f1f30(unsigned int);
};
// @fnv 0x005f1f30
void FUN_005f1f30_shell::FUN_005f1f30(unsigned int buffer)
{
    ((FUN_00484d60_holder*)this)->SaveIfChanged(buffer);
    ((FUN_0047ea30_holder*)((char*)this + 0x30))->FUN_0047ea30(buffer);
    ((FUN_0048e040_holder*)((char*)this + 0x7c))->FUN_0048e040(buffer);
    ((FUN_00480270_holder*)((char*)this + 0xb8))->FUN_00480270(buffer);
    ((FUN_0047f940_holder*)((char*)this + 0x90))->SaveChangeData(buffer);
    if (((BGSLoadFormBuffer*)buffer)->GetChangeFlags(0x20))
    {
        const char* pfullname = ((FNStub*)((char*)this + 0xd0))->GetFullName();
        ((BGSSaveGameBuffer*)buffer)->SaveGameString(pfullname, 0);
    }
}

struct S005f0bf0
{
    char _pad[0x30];
    TESActorBaseData abd;
    bool FUN_005f0bf0();
};
// Returns true unless the form type is 0x2B and neither the 0x40 nor the 1 flag is set in abd.
// @fnv 0x005f0bf0
bool S005f0bf0::FUN_005f0bf0()
{
    if (((TESForm*)this)->GetFormType() == 0x2B)
    {
        if (abd.GetFlag(0x40) || abd.GetFlag(1))
            return true;
        else
            return false;
    }
    return true;
}

extern int DAT_011840c4, DAT_01183028, DAT_01183998, DAT_01186fcc, DAT_01183a34;
extern float DAT_01016410;
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct FormTarget
{
    unsigned int FUN_00401170();
};
struct ComponentTarget
{
    unsigned int FUN_00726070();
};
struct ItemTarget
{
    float FUN_004be060();
    float FUN_004be180();
};
int __cdecl FUN_004873d0(void*);
float __cdecl FUN_00644ce0(void*, void*, float, float, int, int, int, int);
float __cdecl ConvertUIntToFloat(unsigned int);
double __cdecl FUN_00646360(unsigned short, float);
struct ActorBaseTarget : TESActorBase
{
    float FUN_005f0d60(FormTarget* form);
};
// Looks up a form by type and returns a value derived from the matching item, component or constant, defaulting to 0.0f.
// @fnv 0x005f0d60
float ActorBaseTarget::FUN_005f0d60(FormTarget* form)
{
    float result = 0.0f;
    if (form)
    {
        switch (form->FUN_00401170())
        {
        case 41: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_011840c4, 0);
            if (item)
                result = 1.0f;
            break;
        }
        case 40: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01183998, 0);
            if (item && FUN_004873d0(item))
            {
                float condition = 1.0f;
                enum
                {
                    actorComponentOffset = 0x100
                };
                result = FUN_00644ce0(this ? reinterpret_cast<char*>(this) + actorComponentOffset : 0, item, condition,
                                      1.0f, 0, 0, 0, 0);
            }
            break;
        }
        case 26: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01186fcc, 0);
            if (item)
            {
                enum
                {
                    itemComponentOffset = 0x58
                };
                result = ConvertUIntToFloat(
                    reinterpret_cast<ComponentTarget*>(reinterpret_cast<char*>(item) + itemComponentOffset)
                        ->FUN_00726070());
            }
            break;
        }
        case 24: {
            ItemTarget* item = static_cast<ItemTarget*>(FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01183a34, 0));
            if (item && FUN_004873d0(item))
            {
                float condition = 1.0f;
                result =
                    FUN_00646360(static_cast<unsigned short>(item->FUN_004be060()), condition) + item->FUN_004be180();
            }
            break;
        }
        case 30:
            result = DAT_01016410;
            break;
        }
    }
    return result;
}

struct FormIDEntry
{
    unsigned int formID;
    unsigned char type;
    unsigned char flags;
};

struct TESSaveLoadGame
{
    bool FUN_00862110();
    unsigned char FUN_008df040();
    FormIDEntry* GetCurrentForm();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct SaveSizeNamedForm
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
SaveSizeNamedForm* LookupFormByIDForSize(unsigned int formID);

int __cdecl SaveSizeMessage(const char* fmt, ...);
unsigned int BSStringLength(const char* str);

struct SaveSizeFormPart
{
    int unk00;
    unsigned short GetSaveSize(unsigned int changeFlags);
};
struct SaveSizeActorBaseData
{
    int unk00;
    unsigned short GetSaveSizeABD(unsigned int changeFlags);
};
struct SaveSizeContainer
{
    int unk00;
    unsigned short GetSaveSizeCont(unsigned int changeFlags);
};
struct SaveSizeAIForm
{
    int unk00;
    unsigned short GetSaveSizeAI(unsigned int changeFlags);
};
struct SaveSizeAttributes
{
    int unk00;
    unsigned short GetSaveSizeAttr(int changeFlags);
};

struct ActorBaseSaveView
{
    SaveSizeFormPart form;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    SaveSizeActorBaseData actorData;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    SaveSizeContainer container;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    SaveSizeAIForm aiForm;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    SaveSizeAttributes attributes;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FNStub fullName;

    unsigned short FUN_005f16f0(unsigned int changeFlags);
};

// Accumulates the save size of the actor base's parts and optionally logs the total with the current form's ID and editor ID.
// @fnv 0x005f16f0
unsigned short ActorBaseSaveView::FUN_005f16f0(unsigned int changeFlags)
{
    unsigned short totalSize = 0;
    unsigned short startSize = totalSize;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        totalSize += 4;
        totalSize += 2;
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6d)
    {
        totalSize += form.GetSaveSize(changeFlags);
    }
    totalSize += attributes.GetSaveSizeAttr(changeFlags);
    totalSize += actorData.GetSaveSizeABD(changeFlags);
    totalSize += container.GetSaveSizeCont(changeFlags);
    totalSize += aiForm.GetSaveSizeAI(changeFlags);
    if (changeFlags & 0)
    {
        totalSize += 4;
    }
    if (changeFlags & 0x20)
    {
        totalSize += 1;
        totalSize += BSStringLength(fullName.GetFullName());
    }
    if (*g_011de4e8.Bool())
    {
        FormIDEntry* pFormHeader = g_TESSaveLoadGame->GetCurrentForm();
        if (pFormHeader)
        {
            SaveSizeNamedForm* namedForm = LookupFormByIDForSize(pFormHeader->formID);
            SaveSizeMessage("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                            totalSize - startSize, pFormHeader->formID, namedForm->GetEditorID(),
                            *(unsigned int*)&pFormHeader->flags, 550,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
        else
        {
            SaveSizeMessage("GetSaveSize(): %-5i ending at line %i in file %s", totalSize - startSize, 550,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
    }
    return totalSize;
}

namespace fnv_005f18c0 {
struct SaveRecord
{
    unsigned int formID;
    unsigned char type;
    unsigned char flagsLow;
    unsigned char flagsByte1;
    unsigned char flagsByte2;
    unsigned char flagsByte3;
};
struct TESSaveLoadGame
{
    unsigned int GetTimeStamp();
    bool FUN_00862110();
    unsigned char FUN_008df040();
    void FUN_008579b0(void*, int);
    SaveRecord* GetHitSound();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct SaveAttributes
{
    void FUN_00480210(unsigned int);
};
struct SaveActorData
{
    void SaveFactionData(unsigned int);
};
struct SaveInventory
{
    void SaveSpellList(unsigned int);
};
struct SaveAI
{
    void FUN_0047f840(unsigned int);
};
struct SaveList
{
    unsigned int FUN_00726070();
};
struct SaveActorBase
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
    SaveActorData actorData;
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
    SaveInventory inventory;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    SaveAI ai;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    SaveList list;
    unsigned int unkb4;
    SaveAttributes attributes;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    FNStub fullName;
    void FUN_00484c20(unsigned int);
    void FUN_00484ce0(const void*, int);
    void FUN_005f18c0(unsigned int flags);
};
struct SaveForm
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
    virtual const char* Describe();
};
SaveForm* LookupFormByID(unsigned int);
unsigned int FUN_0044a670(const char*);
void FUN_0040fbe0(const char*, ...);
void FNV_Warning(const char*, ...);

// @fnv 0x005f18c0
void SaveActorBase::FUN_005f18c0(unsigned int flags)
{
    unsigned short size = 0;
    unsigned short* pos2 = 0;
    unsigned int offset2 = g_TESSaveLoadGame->GetTimeStamp();
    if (*g_011de4e8.Bool())
        offset2 = g_TESSaveLoadGame->GetTimeStamp();
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        unsigned int tag = 0x424c4f4b;
        g_TESSaveLoadGame->FUN_008579b0(&tag, 4);
        pos2 = (unsigned short*)g_TESSaveLoadGame->GetTimeStamp();
        g_TESSaveLoadGame->FUN_008579b0(&size, 2);
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 109)
        FUN_00484c20(flags);
    attributes.FUN_00480210(flags);
    actorData.SaveFactionData(flags);
    inventory.SaveSpellList(flags);
    ai.FUN_0047f840(flags);
    if (flags & 0)
    {
        unsigned int first = list.FUN_00726070();
        FUN_00484ce0(&first, 4);
    }
    if (flags & 0x20)
    {
        const char* data = fullName.GetFullName();
        unsigned char pos = (unsigned char)FUN_0044a670(data);
        FUN_00484ce0(&pos, 1);
        if (pos)
            FUN_00484ce0(data, pos);
    }
    if (*g_011de4e8.Bool())
    {
        unsigned int end = g_TESSaveLoadGame->GetTimeStamp();
        SaveRecord* record = g_TESSaveLoadGame->GetHitSound();
        if (record)
        {
            SaveForm* form = LookupFormByID(record->formID);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         end - offset2, record->formID, form->Describe(), *(unsigned int*)&record->flagsLow, 587,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", end - offset2, 587,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
    }
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        unsigned int current = g_TESSaveLoadGame->GetTimeStamp();
        unsigned int block = (unsigned int)pos2;
        if (current > block + 0xffff)
            FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 587);
        *pos2 = (unsigned short)(current - block);
    }
}
}  // namespace fnv_005f18c0

namespace fnv_005f1b30 {
void* __cdecl memset(void*, int, unsigned int);
void __cdecl FUN_005b5e40(const char*, ...);

struct LoadHdr
{
    int id;
    char b04;
    char b05;
    char b06;
    char b07;
    char b08;
    unsigned char ver;
};

struct FormName
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual const char* GetName();
};

FormName* __cdecl LookupFormByID(unsigned int);

struct TESSaveLoadGame
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    LoadHdr* FUN_004fd3c0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct Sub30
{
    int data;
    void FUN_0047e6f0(unsigned int, unsigned int);
};
struct Sub7C
{
    int data;
    void LoadSpellList(unsigned int, unsigned int);
};
struct Sub90
{
    int data;
    void FUN_0047f8c0(unsigned int, unsigned int);
};
struct SubB0
{
    int data;
    void FUN_006ecd40(void*);
};
struct SubB8
{
    int data;
    void FUN_00480240(unsigned int, unsigned int);
};
struct SubD0
{
    int data;
    void FUN_00489100(const char*);
};

struct ActorBaseLoad
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    Sub30 sub30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    Sub7C sub7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    Sub90 sub90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    SubB0 subB0;
    int fieldB4;
    SubB8 subB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fieldCC;
    SubD0 subD0;

    void FUN_00484c50(unsigned int, unsigned int);
    void FUN_00484d00(void*, int);
    void FUN_005f1b30(unsigned int, unsigned int);
};

// Reads the actor base block from the save stream, dispatches to sub-structs, and verifies the block boundary against the expected end position.
// @fnv 0x005f1b30
void ActorBaseLoad::FUN_005f1b30(unsigned int aiFlags, unsigned int a2)
{
    FormName* form5;
    LoadHdr* hdrB;
    int hdrWord;
    unsigned int curPosC;
    unsigned short usVarZ;
    usVarZ = 0;
    curPosC = 0;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        g_TESSaveLoadGame->FUN_008579e0(&hdrWord, 4);
        if (hdrWord != 0x424c4f4b)
        {
            hdrB = g_TESSaveLoadGame->FUN_004fd3c0();
            if (hdrB != 0)
            {
                form5 = LookupFormByID(hdrB->id);
                FUN_005b5e40(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 596, hdrB->id,
                    form5->GetName(), hdrB->ver, *(int*)((char*)hdrB + 5));
            }
            else
            {
                FUN_005b5e40(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 596,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
        curPosC = g_TESSaveLoadGame->FUN_00825c00();
        g_TESSaveLoadGame->FUN_008579e0(&usVarZ, 2);
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6d)
        FUN_00484c50(aiFlags, a2);
    subB8.FUN_00480240(aiFlags, a2);
    sub30.FUN_0047e6f0(aiFlags, a2);
    sub7C.LoadSpellList(aiFlags, a2);
    sub90.FUN_0047f8c0(aiFlags, a2);
    if (aiFlags & 0)
    {
        void* scriptVal;
        FUN_00484d00(&scriptVal, 4);
        subB0.FUN_006ecd40(scriptVal);
    }
    if (aiFlags & 0x20)
    {
        unsigned char flagByte;
        char nameBuf[0x104];
        memset(nameBuf, 0, 0x104);
        FUN_00484d00(&flagByte, 1);
        if (flagByte != 0)
            FUN_00484d00(nameBuf, flagByte);
        subD0.FUN_00489100(nameBuf);
    }
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        FormName* form25;
        unsigned int endPos0;
        LoadHdr* hdr2A;
        endPos0 = g_TESSaveLoadGame->FUN_00825c00();
        hdr2A = g_TESSaveLoadGame->FUN_004fd3c0();
        if (hdr2A != 0)
        {
            form25 = LookupFormByID(hdr2A->id);
            if (endPos0 > usVarZ + curPosC)
            {
                FUN_005b5e40(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    endPos0 - (usVarZ + curPosC),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628, hdr2A->id,
                    form25->GetName(), hdr2A->ver, *(int*)((char*)hdr2A + 5));
            }
            else if (endPos0 < usVarZ + curPosC)
            {
                FUN_005b5e40(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    (usVarZ + curPosC) - endPos0,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628, hdr2A->id,
                    form25->GetName(), hdr2A->ver, *(int*)((char*)hdr2A + 5));
            }
        }
        else
        {
            if (endPos0 > usVarZ + curPosC)
            {
                FUN_005b5e40(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    endPos0 - (usVarZ + curPosC),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628,
                    g_TESSaveLoadGame->FUN_008df040());
            }
            else if (endPos0 < usVarZ + curPosC)
            {
                FUN_005b5e40(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    (usVarZ + curPosC) - endPos0,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
    }
}
}  // namespace fnv_005f1b30
