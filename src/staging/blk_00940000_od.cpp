
// src/staging/blk_00940000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void* DAT_011d8a80;

// Returns byte at offset 0x4cd of DAT_011d8a80, or 0 if DAT_011d8a80 is null.
// @fnv 0x00944270
char __cdecl FUN_00944270()
{
    char result;
    if (DAT_011d8a80)
        result = ((const char*)DAT_011d8a80)[0x4cd];
    else
        result = 0;
    return result;
}

struct Animation
{
    float m_fMovementRate;
    float FUN_009442a0() const;
};

// @fnv 0x009442a0
float Animation::FUN_009442a0() const
{
    return *(const float*)((const char*)this + 0x10c);
}

struct FUN_009442c0_Class
{
    bool IsFlagSet() const;
};

// @fnv 0x009442c0
bool FUN_009442c0_Class::IsFlagSet() const
{
    return (reinterpret_cast<const int*>(this)[0x12c / 4] & 0x1000) ? true : false;
}

struct FUN_009442e0_class
{
    void FUN_009442e0(float value);
};

// @fnv 0x009442e0
void FUN_009442e0_class::FUN_009442e0(float value)
{
    *(float*)((char*)this + 0x1f4) = value;
}

struct FUN_00944300_class
{
    float FUN_00944300();
};

// @fnv 0x00944300
float FUN_00944300_class::FUN_00944300()
{
    return *(float*)((char*)this + 0x1f4);
}

struct FUN_00944320_Class
{
    unsigned int GetField688();
};

// @fnv 0x00944320
unsigned int FUN_00944320_Class::GetField688()
{
    return *(unsigned int*)((char*)this + 0x688);
}

struct FUN_00944340_Class
{
    char GetByteAtOffset681();
};

// @fnv 0x00944340
char FUN_00944340_Class::GetByteAtOffset681()
{
    return ((char*)this)[0x681];
}

struct FUN_00944360_Class
{
    unsigned char __thiscall GetByteAt66E();
};

// @fnv 0x00944360
unsigned char __thiscall FUN_00944360_Class::GetByteAt66E()
{
    return ((unsigned char*)this)[0x66e];
}

struct FUN_00944380_class
{
    void __thiscall SetFieldE28(float value);
};

// @fnv 0x00944380
void __thiscall FUN_00944380_class::SetFieldE28(float value)
{
    *(float*)((char*)this + 0xe28) = value;
}

struct FUN_009443a0_class
{
    float GetFieldE28();
};

// @fnv 0x009443a0
float FUN_009443a0_class::GetFieldE28()
{
    return *(float*)((char*)this + 0xe28);
}

extern bool DAT_011dea29;
extern bool DAT_011dea2b;

struct FUN_009443c0_Class
{
    bool FUN_009443c0();
};

// Returns true if either DAT_011dea2b or DAT_011dea29 is set, otherwise false.
// @fnv 0x009443c0
bool FUN_009443c0_Class::FUN_009443c0()
{
    if (DAT_011dea2b || DAT_011dea29)
        return true;
    return false;
}

struct DummyFlags
{
    int FUN_00621270(int);
};

struct FUN_00944400_Class
{
    bool HasFlag400();
};

// Returns whether the DummyFlags object at offset 0x410 has flag 0x400 set.
// @fnv 0x00944400
bool FUN_00944400_Class::HasFlag400()
{
    return ((DummyFlags*)((char*)this + 0x410))->FUN_00621270(0x400) != 0;
}

namespace fnv_00944430 {
struct DummyFlags
{
    int FUN_00621270(int);
};

struct FUN_00944430_class
{
    bool HasFlag20000();
};

// @fnv 0x00944430
bool FUN_00944430_class::HasFlag20000()
{
    return ((DummyFlags*)((char*)this + 0x410))->FUN_00621270(0x20000) != 0;
}
}  // namespace fnv_00944430

extern char* _pme;

// Returns byte at offset 0x204 of _pme, or 0 if _pme is null.
// @fnv 0x009444a0
char FUN_009444a0()
{
    char result;
    if (_pme)
        result = _pme[0x204];
    else
        result = 0;
    return result;
}

struct FUN_0094c380_Class
{
    void __thiscall FUN_0094c380();
    void __thiscall FUN_00621370(int);
};

// @fnv 0x0094c380
void __thiscall FUN_0094c380_Class::FUN_0094c380()
{
    FUN_00621370(0);
}

namespace fnv_0094c3a0 {
struct Setting_S
{
    float* Float();
};
extern "C" void* _pme;
struct GlobalObject_0044f440;
extern GlobalObject_0044f440 g_011d9748;

// If _pme is set, stores value multiplied by the float from g_011d9748 into the field at offset 0x274 of _pme.
// @fnv 0x0094c3a0
void SetScaledValue(float value)
{
    if (_pme)
    {
        *(float*)((char*)_pme + 0x274) = value * *(float*)((Setting_S*)&g_011d9748)->Float();
    }
}
}  // namespace fnv_0094c3a0

struct FUN_0094c8c0_class
{
    unsigned int __thiscall GetField6EC();
};

// @fnv 0x0094c8c0
unsigned int __thiscall FUN_0094c8c0_class::GetField6EC()
{
    return *(unsigned int*)((char*)this + 0x6ec);
}

struct Biped;
struct TESObjectREFR
{
    Biped* GetBipedComponent();
    Biped* pBiped;
};
struct PlayerCharacter : TESObjectREFR
{
    Biped* FUN_00950b00(bool firstPerson);
};
// @fnv 0x00950b00
Biped* PlayerCharacter::FUN_00950b00(bool firstPerson)
{
    if (firstPerson)
        return *(Biped**)((char*)this + 0x68c);
    return GetBipedComponent();
}

struct FUN_0095f6a0_Class
{
    void FUN_00961280();
    void FUN_0095f6a0();
};

// @fnv 0x0095f6a0
void FUN_0095f6a0_Class::FUN_0095f6a0()
{
    FUN_00961280();
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_0094df30_Class
{
    NiPoint3& FUN_0094df30(NiPoint3& akDest);
};

// Copies the NiPoint3 stored at offset 0x7a0 of this object into akDest and returns akDest.
// @fnv 0x0094df30
NiPoint3& FUN_0094df30_Class::FUN_0094df30(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<const char*>(this) + 0x7a0);
    return akDest;
}

class TESQuest;
class BGSQuestObjective
{
  public:
    TESQuest* FUN_0044edb0();
    void AddMatchingTargetsToList(void*);
};
class QuestObjectiveList
{
  public:
    bool FUN_008256d0();
};
class TESQuest
{
  public:
    QuestObjectiveList* FUN_005d43e0();
};
class QuestObjectiveNode
{
  public:
    BGSQuestObjective*& FUN_006815c0();
    QuestObjectiveNode* FUN_00726070();
};
class G2
{
  public:
    void AddHead(int*);
};

struct FUN_00952a20_shell
{
    char pad0[0x6b8];
    TESQuest* pQuest;
    char pad6bc[8];
    char kTargetList[8];
    QuestObjectiveNode* GetOffset6BC();
    void FUN_00952a20(BGSQuestObjective* apObjective);
};

// @fnv 0x00952a20
void FUN_00952a20_shell::FUN_00952a20(BGSQuestObjective* apObjective)
{
    QuestObjectiveNode* pIter = GetOffset6BC();
    TESQuest* pObjQuest = apObjective->FUN_0044edb0();
    bool bFound = false;
    bool bSameQuest = false;
    while (pIter && pIter->FUN_006815c0())
    {
        BGSQuestObjective* pObjective = pIter->FUN_006815c0();
        if (apObjective == pObjective)
        {
            bSameQuest = true;
            break;
        }
        if (!bFound && pObjective->FUN_0044edb0() == pObjQuest)
            bFound = true;
        pIter = pIter->FUN_00726070();
    }
    bool bHasObjectives =
        apObjective->FUN_0044edb0()->FUN_005d43e0() && !apObjective->FUN_0044edb0()->FUN_005d43e0()->FUN_008256d0();
    if (bHasObjectives && !bSameQuest)
        ((G2*)GetOffset6BC())->AddHead((int*)&apObjective);
    if (apObjective->FUN_0044edb0() == pQuest)
        apObjective->AddMatchingTargetsToList(kTargetList);
}

struct FUN_00952b30_BSSimpleList
{
    void* m_pInventoryEntryData;
    FUN_00952b30_BSSimpleList* GetNext();
    FUN_00952b30_BSSimpleList* _ref_006815c0();
};
struct BSAudio
{
    void* GetAudioBackendData();
};
struct TESObject
{
    unsigned int GetNext();
};
struct FUN_00952b30_Class
{
    BSAudio* FindAudioEntry();
};

// @fnv 0x00952b30
BSAudio* FUN_00952b30_Class::FindAudioEntry()
{
    FUN_00952b30_BSSimpleList* node = (FUN_00952b30_BSSimpleList*)((char*)this + 0x6bc);
    while (node && node->_ref_006815c0()->m_pInventoryEntryData)
    {
        BSAudio* entry = (BSAudio*)node->_ref_006815c0()->m_pInventoryEntryData;
        if (entry->GetAudioBackendData() == *(void**)((char*)this + 0x6b8) && ((TESObject*)entry)->GetNext() == 1)
            return entry;
        node = node->GetNext();
    }
    return 0;
}

struct FUN_00952830_Class
{
    bool FUN_00952830(BSAudio*, unsigned int, unsigned int);
};
struct FUN_00464e30_shell
{
    FUN_00952b30_Class* GetSelfOffset6A8();
};
struct FUN_009527b0_Class
{
    void FUN_00952830(BSAudio*, unsigned int, unsigned int);
    void __thiscall AddTopics(FUN_00952b30_BSSimpleList*);
};
void __cdecl SortTopicList(unsigned int, FUN_00952b30_Class*);
// Iterates the given topic list, calls FUN_00952830 on each entry, and if any returns true calls SortTopicList with 1 and the result of GetSelfOffset6A8.
// @fnv 0x009527b0
void __thiscall FUN_009527b0_Class::AddTopics(FUN_00952b30_BSSimpleList* apAddTopicList)
{
    if (apAddTopicList)
    {
        bool bNeedsResort = false;
        FUN_00952b30_BSSimpleList* pNode = apAddTopicList;
        while (pNode && ((FUN_00952b30_Class**)pNode->_ref_006815c0())[0])
        {
            if (((FUN_00952830_Class*)this)
                    ->FUN_00952830((BSAudio*)(((FUN_00952b30_Class**)pNode->_ref_006815c0())[0]), 0, 1))
                bNeedsResort = true;
            pNode = pNode->GetNext();
        }
        if (bNeedsResort)
            SortTopicList(1, ((FUN_00464e30_shell*)this)->GetSelfOffset6A8());
    }
}

namespace fnv_00952830 {
struct FUN_00952830_BSSimpleList
{
    FUN_00952830_BSSimpleList* GetNext();
    int* _ref_006815c0();
};
struct FUN_00464e30_shell
{
    FUN_00952830_BSSimpleList* GetSelfOffset6A8();
};
void SortTopicList(int, FUN_00952830_BSSimpleList*);
struct FUN_00952830_Class
{
    bool FUN_00952830(int param_2, unsigned char param_3, int pad);
};
// Returns false if param_2 is zero or already present in the list; otherwise adds it to the head of the list at offset 0x6a8 and optionally calls SortTopicList.
// @fnv 0x00952830
bool FUN_00952830_Class::FUN_00952830(int aiValue, unsigned char param_3, int pad)
{
    FUN_00952830_BSSimpleList* pEntry;
    if (aiValue == 0)
        return false;
    pEntry = ((FUN_00464e30_shell*)this)->GetSelfOffset6A8();
    while (pEntry && *pEntry->_ref_006815c0())
    {
        if (*pEntry->_ref_006815c0() == aiValue)
            return false;
        pEntry = pEntry->GetNext();
    }
    ((G2*)((char*)this + 0x6a8))->AddHead(&aiValue);
    if (param_3)
        SortTopicList(1, ((FUN_00464e30_shell*)this)->GetSelfOffset6A8());
    return true;
}
}  // namespace fnv_00952830

extern float DAT_011ac3a4;

// @fnv 0x009443f0
float __cdecl FUN_009443f0()
{
    return DAT_011ac3a4;
}

struct BaseA
{
    char pad[0x18];
};

struct BaseB
{
    int dummy;
};

struct DerivedNode : public BaseA, public BaseB
{
};

struct ListNode
{
    DerivedNode* FUN_00726070();
};

struct ArgObj
{
    char pad[0x74];
    ListNode list;
};

struct FUN_0094c950_shell
{
    char pad[0x6f0];
    ArgObj* field_6f0;

    void FUN_0094c8e0(BaseB* p);
    void SetArg(ArgObj* pArg);
};

// Updates field_6f0 to pArg when it differs, clearing it if pArg's list lookup fails, and forwards the list result to FUN_0094c8e0.
// @fnv 0x0094c950
void FUN_0094c950_shell::SetArg(ArgObj* pArg)
{
    if (pArg && !pArg->list.FUN_00726070())
    {
        field_6f0 = 0;
        return;
    }
    if (field_6f0 && field_6f0 == pArg)
    {
        return;
    }
    if (field_6f0 && !pArg)
    {
        FUN_0094c8e0(0);
    }
    field_6f0 = pArg;
    if (field_6f0)
    {
        FUN_0094c8e0(field_6f0->list.FUN_00726070());
    }
    else
    {
        FUN_0094c8e0(0);
    }
}

extern unsigned char DAT_011c7a5a;
// @fnv 0x0094dba0
unsigned char __cdecl FUN_0094dba0()
{
    return DAT_011c7a5a;
}

struct FUN_00952f90_helper
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(int arg);
};

struct FUN_00952f90_member
{
    void __thiscall ClearTeleportPath();
};

class FUN_00952f90_cls
{
  public:
    char unk0000[0x6f4];
    FUN_00952f90_helper* m_6f4;
    FUN_00952f90_member m_6f8;
    void __thiscall ClearHelper();
};

// Calls v10(1) on m_6f4 if non-null, then nulls m_6f4 and calls ClearTeleportPath on m_6f8.
// @fnv 0x00952f90
void FUN_00952f90_cls::ClearHelper()
{
    unsigned int tmp = (unsigned int)m_6f4;
    FUN_00952f90_helper* p = (FUN_00952f90_helper*)tmp;
    p != 0 ? p->v10(1) : 0;
    m_6f4 = 0;
    m_6f8.ClearTeleportPath();
}

class TESForm
{
  public:
    virtual ~TESForm();
    int FNV_GetFormType();
};
class TESBoundObject : public TESForm
{
};
class MagicItem
{
  public:
    virtual ~MagicItem();
};
struct EnchantmentItemBase
{
    virtual ~EnchantmentItemBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class EnchantmentItem : public EnchantmentItemBase, public MagicItem
{
};
class TESEnchantableForm
{
  public:
    virtual ~TESEnchantableForm();
    EnchantmentItem* GetEnchantment();
};
class MagicTarget
{
  public:
    int unk00;
    int unk04;
    int unk08;
    bool HasSpell(MagicItem* apSpell, bool abFlag);
    void RemoveSpellStub(TESBoundObject* apForm, bool abFlag);
};
class EnchantedFormList
{
  public:
    void* m_item;
    EnchantedFormList* m_next;
    ~EnchantedFormList();
    void Remove(TESBoundObject* const& arItem);
    bool IsEmptyStub();
};
struct PlayerEnchantStub
{
    int unk00;
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
    int unk30;
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
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    MagicTarget kMagicTarget;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    EnchantedFormList* pEnchantedForms;
    void RemoveEnchantment(TESBoundObject* apForm, int aiUnused);
};

class TESObjectWEAP : public TESBoundObject
{
  public:
    virtual ~TESObjectWEAP();
};

struct InvEntry
{
    TESBoundObject* GetObj();
    void SetPerkExtra(void* a);
};

struct ProcStub
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual InvEntry* GetWeaponEntry();
};

class PlayerStub
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void Equip(void* a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
    ProcStub* GetCurrentProcess();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    void* unk758;
};

extern PlayerStub* _g_thePlayer;
char __cdecl ConsumeByteAtE4();
void __cdecl FUN_005f5950(int a, int b, void* c, int d, int e, int f, int g);
void __cdecl FUN_00704af0();

// @fnv 0x0095e900
void __cdecl FUN_0095e900()
{
    if (!_g_thePlayer->unk758)
        return;
    if (ConsumeByteAtE4() == 2)
    {
        ProcStub* proc = _g_thePlayer->GetCurrentProcess();
        InvEntry* entry3 = proc->GetWeaponEntry();
        TESObjectWEAP* weap = entry3 ? dynamic_cast<TESObjectWEAP*>(entry3->GetObj()) : 0;
        if (weap)
        {
            FUN_005f5950(5, 1, _g_thePlayer->unk758, 0, 0, 0, 0);
            FUN_005f5950(9, 1, _g_thePlayer->unk758, 0, 0, 0, 0);
            entry3->SetPerkExtra(_g_thePlayer->unk758);
            _g_thePlayer->Equip(_g_thePlayer->unk758, 0, 1, 0, 0, 0, 0, 0, 1, 0);
            FUN_00704af0();
        }
    }
    _g_thePlayer->unk758 = 0;
}

static const char restoreIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds";
struct SavedForm
{
    int FNV_GetFormType();
};
struct RestoreUpdate
{
    float time;
    int flags;
    int unk08;
    RestoreUpdate(float, bool, bool);
};
struct RestoreNode
{
    void SetPosition(const NiPoint3&);
    void Update(RestoreUpdate&);
};
void RefreshNode(RestoreNode*, bool);
struct RestoreController
{
    bool IsFlying();
    void SetPosition(const NiPoint3&);
};
struct RestoreSetting
{
    const char* String();
};
extern RestoreSetting g_011d50bc;
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
struct RestoreData
{
    SavedForm* FindCell(int, int, SavedForm*, bool);
};
extern RestoreData* g_dataHandler;
int TruncateFloatToInt(float);
struct RestorePlayer
{
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
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void InitializeForCell(SavedForm*);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    NiPoint3 savedPosition;
    SavedForm* savedDestination;
    const NiPoint3& GetAngle();
    NiPoint3 GetDestination();
    void MoveWorld(NiPoint3, NiPoint3, SavedForm*, int);
    void MoveCell(NiPoint3, NiPoint3, SavedForm*, int);
    RestoreController* GetController();
    NiPoint3* GetPosition();
    void SetLocation(const NiPoint3&);
    RestoreNode* GetNode(bool);
    void RestorePlayerLocation(bool);
};
// If a saved destination exists, either moves the player to it (travel) or restores the saved position, controller, cell and nodes.
// @fnv 0x0094dbe0
void RestorePlayer::RestorePlayerLocation(bool travel)
{
    if (savedDestination)
    {
        if (travel)
        {
            QueueUIMessage(g_011d50bc.String(), 0, restoreIcon, 0, 2.0f, false);
            SavedForm* cellB = 0;
            SavedForm* world7 = 0;
            if (savedDestination)
            {
                switch (savedDestination->FNV_GetFormType())
                {
                case 0x39:
                    cellB = savedDestination;
                    break;
                case 0x41:
                    world7 = savedDestination;
                    break;
                }
            }
            if (world7)
            {
                MoveWorld(GetDestination(), GetAngle(), world7, 0);
            }
            else if (cellB)
            {
                MoveCell(GetDestination(), GetAngle(), cellB, 0);
            }
        }
        else
        {
            RestorePlayer* player3 = this;
            QueueUIMessage(g_011d50bc.String(), 0, restoreIcon, 0, 2.0f, false);
            RestoreController* controller7 = player3->GetController();
            if (controller7 && !controller7->IsFlying())
                savedPosition.z = player3->GetPosition()->z;
            player3->SetLocation(savedPosition);
            if (controller7)
                controller7->SetPosition(savedPosition);
            SavedForm* cell2_2 = 0;
            SavedForm* world2 = 0;
            if (savedDestination)
            {
                switch (savedDestination->FNV_GetFormType())
                {
                case 0x39:
                    cell2_2 = savedDestination;
                    break;
                case 0x41:
                    world2 = savedDestination;
                    break;
                }
            }
            if (world2)
            {
                int gridX = TruncateFloatToInt(savedPosition.x) >> 12;
                int gridY3 = TruncateFloatToInt(savedPosition.y) >> 12;
                cell2_2 = g_dataHandler->FindCell(gridX, gridY3, world2, false);
            }
            if (cell2_2)
            {
                player3->InitializeForCell(cell2_2);
                InitializeForCell(cell2_2);
            }
            RestoreNode* third_ = GetNode(false);
            RestoreNode* first5 = GetNode(true);
            third_->SetPosition(savedPosition);
            first5->SetPosition(savedPosition);
            RefreshNode(third_, true);
            RefreshNode(first5, true);
            RestoreUpdate updateThird4(0.0f, false, false);
            third_->Update(updateThird4);
            RestoreUpdate updateFirst2(0.0f, false, false);
            first5->Update(updateFirst2);
        }
    }
}

struct Ref;
struct Data
{
    void* Resolve();
};
struct Package
{
    Data* GetData();
    Ref* Target(Ref*);
    int Type();
    bool Test();
};
struct Handle
{
    Ref* Get();
};
struct Process
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void Set(Ref*, int);
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
    virtual Ref* Target();
    Handle handle;
};
struct Ref
{
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
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool Dead(int);
    virtual void v230();
    virtual bool Invalid();
    bool GetDisabled();
    bool FUN_00437bf0();
    Process* GetCurrentProcess();
    Package* GetAssignedPackage();
    void* GetNext();
    bool ActorTest();
};
extern Ref* player;
struct Controller
{
    bool IsPlayerTargeted(Ref* actor, bool mode);
};
// Checks whether actor is alive and enabled and, depending on mode, whether its package or current process targets the player.
// @fnv 0x00954a70
bool Controller::IsPlayerTargeted(Ref* actor, bool mode)
{
    if (actor->Dead(0) || actor->GetDisabled() || actor->Invalid() || actor->FUN_00437bf0())
        return false;
    actor->GetCurrentProcess()->Set(actor, 1);
    Package* package = actor->GetAssignedPackage();
    Process* process = actor->GetCurrentProcess();
    Handle* handle8 = &process->handle;
    if (mode)
    {
        Ref* target8 = 0;
        if (handle8 && handle8->Get())
        {
            target8 = handle8->Get();
            if (!target8)
            {
                void* resolvedA = package->GetData()->Resolve();
                if (resolvedA && resolvedA == player->GetNext())
                    target8 = player;
            }
        }
        if ((package && package->Target(actor) == player) ||
            ((target8 == player || actor->GetCurrentProcess()->Target() == player) && package->Type() != 9))
        {
            if (target8 == player)
            {
                if (actor->ActorTest())
                    return false;
                else
                    return true;
            }
            return true;
        }
    }
    else
    {
        if (package && (package->Type() == 1 || package->Type() == 7) && package->GetData())
        {
            Process* aProcess2 = actor->GetCurrentProcess();
            Handle* kTarget2 = &aProcess2->handle;
            Ref* handleA = kTarget2->Get();
            if (!handleA)
            {
                void* resolved9 = package->GetData()->Resolve();
                if (resolved9 && resolved9 == player->GetNext())
                    handleA = player;
            }
            if (handleA == player)
            {
                if (package->Test())
                    return false;
                else
                    return true;
            }
        }
    }
    return false;
}

struct Setting97
{
    float& FUN_00403e20();
    unsigned char& FUN_00408d60();
    int FUN_0044ddc0();
    double FUN_00450410();
};
extern Setting97 DAT_011e097c;
extern Setting97 DAT_0120315c;
extern Setting97 DAT_01203168;
extern Setting97 DAT_01203174;
extern Setting97 DAT_011e0970;
extern Setting97 DAT_011ce870;
extern Setting97 DAT_011f2250;
extern Setting97 DAT_011e0b84;
extern Setting97 DAT_011ce5a0;
extern Setting97 DAT_011ce344;
extern Setting97 DAT_011cfe2c;
extern Setting97 DAT_011cea44;
extern Setting97 DAT_01203150;
extern Setting97 DAT_011d48dc;
extern Setting97 DAT_011d4a2c;
struct Data97
{
    int FUN_0044ddc0();
    float FUN_00508070();
    unsigned char FUN_004bd8d0(int, float*);
};
struct Node97
{
    void* FUN_006815c0();
    float FUN_0084d030();
};
struct Root97
{
    Node97* FUN_0043d450();
};
struct Actor97
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual Data97* getData();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual Root97* getRoot();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual void vf428();
    virtual void vf42c();
    virtual void vf430();
    virtual void vf434();
    virtual void vf438();
    virtual void vf43c();
    virtual void vf440();
    virtual void vf444();
    virtual void vf448();
    virtual void vf44c();
    virtual void vf450();
    virtual unsigned char isScoped();
};
struct Vec97
{
    float x, y, z;
    Vec97& FUN_00439ef0();
    float FUN_00457990();
};
struct World97
{
    Vec97* FUN_0045bb80(Vec97*, void*);
};
extern World97* DAT_011e07d0;
struct Other97
{
    void FUN_00712e60();
};
struct Manager97
{
    Other97* FUN_006629f0();
    float FUN_0099e040();
};
Manager97* __stdcall FUN_0045c670(void* unused);
Manager97* __cdecl FUN_0045c670();
extern int DAT_011ad840;
float __cdecl FUN_00408840(float);
float __cdecl LogFloat(float);
void __cdecl FUN_007f3bd0(int);
extern unsigned char DAT_011e07b8, DAT_011a3b31;
extern Actor97* DAT_011f21cc;
struct Time97
{
    float FUN_0084d030();
};
extern Time97 DAT_011f6394;
struct FUN_00939880
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    FUN_00939880();
    void FUN_00946020(float, float, float);
    void FUN_00946140(float);
    float FUN_00946190();
    unsigned char FUN_00946280();
};
struct Update97
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    Actor97* actor;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    unsigned short unk648;
    unsigned char state64a;
    unsigned char unk64b;
    unsigned char state64c;
    unsigned char unk64d;
    unsigned short unk64e;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    float currentHorizontal;
    float currentVertical;
    unsigned char FUN_00967ae0();
    unsigned char FUN_008bbc10();
    void SetActiveState(int, int, int);
    int FUN_008a7570();
    float FUN_00950610(float);
    void UpdateScopeZoom(float elapsed);
};
// @fnv 0x0095de30
void Update97::UpdateScopeZoom(float elapsed)
{
    static Actor97* previous = 0;
    if (DAT_011e097c.FUN_00408d60())
    {
        float weapon;
        Data97* unusedScale = actor->getData() ? (Data97*)actor->getData()->FUN_0044ddc0() : 0;
        float normalVertical = DAT_0120315c.FUN_00403e20();
        float scope = DAT_01203168.FUN_00403e20();
        float normalHorizontal = DAT_01203174.FUN_00403e20();
        weapon = DAT_011e0970.FUN_00403e20();
        float speed = DAT_011ce870.FUN_00403e20();
        float resetVertical = 1.0f;
        FUN_0045c670(&DAT_011ad840)->FUN_006629f0()->FUN_00712e60();
        if (unusedScale && actor->isScoped())
        {
            weapon = FUN_00408840(unusedScale->FUN_00508070());
            float data;
            Data97* mod = actor->getData();
            data = 0.0f;
            if (mod->FUN_004bd8d0(14, &data))
                weapon -= data;
        }
        if (FUN_00967ae0())
        {
            if (FUN_008bbc10())
                SetActiveState(0, 0, 0);
            currentVertical = normalHorizontal;
            currentHorizontal = normalVertical;
        }
        else if (DAT_011e07b8 && DAT_011a3b31)
        {
            if (normalVertical != FUN_0045c670()->FUN_0099e040())
                FUN_00950610(normalVertical);
        }
        else
        {
            float vertical = normalVertical;
            float step = scope;
            float horizontal = elapsed * 30.0 / speed;
            if (FUN_008bbc10() && weapon > 5.0 &&
                ((FUN_008a7570() != 9 && FUN_008a7570() != 17) || DAT_011f2250.FUN_0044ddc0() == 4))
            {
                vertical = weapon;
                step = weapon / normalVertical * scope;
            }
            if ((DAT_011f2250.FUN_0044ddc0() == 2 || DAT_011f2250.FUN_0044ddc0() == 3) && DAT_011f21cc &&
                state64c == state64a)
            {
                Node97* a;
                {
                    Root97* b;
                    {
                        float c;
                        {
                            float d;
                            {
                                float e;
                                {
                                    float f;
                                    {
                                        Vec97 g;
                                        {
                                            float h;
                                            b = DAT_011f21cc->getRoot();
                                            a = b->FUN_0043d450();
                                            DAT_011e07d0->FUN_0045bb80(&g, a->FUN_006815c0())->FUN_00439ef0();
                                            e = g.FUN_00457990();
                                            d = a->FUN_0084d030() * DAT_011e0b84.FUN_00450410() / e;
                                            c = DAT_011ce5a0.FUN_00403e20() - DAT_011ce344.FUN_00403e20();
                                            f = e / DAT_011cfe2c.FUN_00403e20();
                                            if (f > 1.0)
                                                f = 1.0f;
                                            h = DAT_011ce344.FUN_00403e20() + c * f;
                                            vertical = LogFloat(d) * h;
                                            if (vertical < DAT_011cea44.FUN_00403e20())
                                                vertical = DAT_011cea44.FUN_00403e20();
                                            step = vertical;
                                            if (step >= DAT_01203150.FUN_00403e20())
                                                step = DAT_01203150.FUN_00403e20();
                                            static FUN_00939880* horizontalBlend = new FUN_00939880;
                                            static FUN_00939880* verticalBlend = new FUN_00939880;
                                            if (previous != DAT_011f21cc)
                                            {
                                                float i = 0.75f;
                                                if (DAT_011f2250.FUN_0044ddc0() == 1)
                                                    i = DAT_011d48dc.FUN_00403e20();
                                                else if (DAT_011f2250.FUN_0044ddc0() == 2)
                                                    i = DAT_011d4a2c.FUN_00403e20();
                                                horizontalBlend->FUN_00946020(currentHorizontal, vertical, i);
                                                verticalBlend->FUN_00946020(currentVertical, step, i);
                                                previous = DAT_011f21cc;
                                            }
                                            horizontalBlend->FUN_00946140(DAT_011f6394.FUN_0084d030());
                                            verticalBlend->FUN_00946140(DAT_011f6394.FUN_0084d030());
                                            currentHorizontal = horizontalBlend->FUN_00946190();
                                            currentVertical = verticalBlend->FUN_00946190();
                                            if (verticalBlend->FUN_00946280())
                                            {
                                                FUN_007f3bd0(1);
                                                DAT_011a3b31 = 1;
                                            }
                                            else
                                            {
                                                FUN_007f3bd0(0);
                                                DAT_011a3b31 = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if (DAT_011f2250.FUN_0044ddc0() == 4)
            {
                previous = 0;
                currentHorizontal = vertical;
                currentVertical = step;
                DAT_011a3b31 = 1;
            }
            else
            {
                previous = 0;
                if (currentHorizontal > vertical)
                {
                    currentHorizontal = currentHorizontal - horizontal;
                    if (currentHorizontal < vertical)
                        currentHorizontal = vertical;
                }
                else if (currentHorizontal < vertical)
                {
                    currentHorizontal = currentHorizontal + horizontal;
                    if (currentHorizontal > vertical)
                        currentHorizontal = vertical;
                }
                if (currentVertical > step)
                {
                    currentVertical = currentVertical - horizontal;
                    if (currentVertical < step)
                    {
                        currentVertical = step;
                        DAT_011a3b31 = 1;
                    }
                    else
                        DAT_011a3b31 = 0;
                }
                else if (currentVertical < step)
                {
                    currentVertical = currentVertical + horizontal;
                    if (currentVertical > step)
                    {
                        currentVertical = step;
                        DAT_011a3b31 = 1;
                    }
                    else
                        DAT_011a3b31 = 0;
                }
                else
                    DAT_011a3b31 = 1;
            }
        }
    }
}

struct InputState
{
    void* FUN_00a24660(int, int);
};
struct InputManager
{
    InputState* FUN_00877720();
};
extern InputManager* DAT_011dea0c;
extern bool DAT_011e0d5c;
void __cdecl FUN_00705ad0(int);
int __cdecl GetLODMultTypeIfKeySet();
struct Item;
struct ItemEntry
{
    Item* FUN_006fa820();
};
struct Entry;
ItemEntry* __cdecl FUN_004b5260(Entry*);
struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011d1230;
struct Quest
{
    void FUN_004213c0(void*, void*);
    void RemoveExtra(int);
};
struct ActorRef
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void FUN_SLOT48(int);
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual Entry* FUN_SLOT1d0();
    void* FUN_007af430();
    Quest* FUN_005d43c0();
};
extern void* DAT_011ca27c;
extern void* DAT_011ca280;
ActorRef* __cdecl FUN_00703350();
struct Item
{
    virtual void itemslot000();
    virtual void itemslot004();
    virtual void itemslot008();
    virtual void itemslot00c();
    virtual void itemslot010();
    virtual void itemslot014();
    virtual void itemslot018();
    virtual void itemslot01c();
    virtual void itemslot020();
    virtual void itemslot024();
    virtual void itemslot028();
    virtual void itemslot02c();
    virtual void itemslot030();
    virtual void itemslot034();
    virtual void itemslot038();
    virtual void itemslot03c();
    virtual void itemslot040();
    virtual void itemslot044();
    virtual void itemslot048();
    virtual void itemslot04c();
    virtual void itemslot050();
    virtual void itemslot054();
    virtual void itemslot058();
    virtual void itemslot05c();
    virtual void itemslot060();
    virtual void itemslot064();
    virtual void itemslot068();
    virtual void itemslot06c();
    virtual void itemslot070();
    virtual void itemslot074();
    virtual void itemslot078();
    virtual void itemslot07c();
    virtual void itemslot080();
    virtual void itemslot084();
    virtual void itemslot088();
    virtual void itemslot08c();
    virtual void itemslot090();
    virtual int FUN_SLOT94();
    float FUN_004b5400();
};
struct State
{
    int unk0;
    int unk4;
    int FUN_00559450();
};
struct Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    State state;
    int mode;
    void FUN_00960520(float);
    void FUN_00961280();
    void FUN_0095f930(ActorRef*, int, float);
    void FUN_0095f6c0(float);
};
// @fnv 0x0095f6c0
void Owner::FUN_0095f6c0(float delta)
{
    InputState* input = DAT_011dea0c->FUN_00877720();
    unsigned char pressed = input->FUN_00a24660(27, 1) != 0;
    if (pressed)
        FUN_00705ad0(0);
    int status = GetLODMultTypeIfKeySet();
    bool second;
    {
        bool first = status == 1;
        second = status == 2;
        if (status == 1)
            FUN_00705ad0(2);
        if (!pressed && !DAT_011e0d5c && !state.FUN_00559450() && !first && !second)
            return;
        if (state.FUN_00559450())
        {
            if (mode == 1)
            {
                if ((DAT_011e0d5c && !pressed) || second)
                    FUN_00960520(delta);
                else
                {
                    FUN_00961280();
                    DAT_011e0d5c = false;
                }
            }
        }
        else if ((pressed || first) && mode == 0)
        {
            ActorRef* actor = FUN_00703350();
            if (actor)
            {
                if (actor->FUN_007af430() == DAT_011ca27c || actor->FUN_007af430() == DAT_011ca280)
                    return;
                Entry* itemEntry = actor->FUN_SLOT1d0();
                ItemEntry* entry = itemEntry ? FUN_004b5260(itemEntry) : 0;
                Item* item = entry ? entry->FUN_006fa820() : 0;
                if (item && item->FUN_SLOT94())
                {
                    float value = item->FUN_004b5400();
                    if (*DAT_011d1230.FUN_00403e20() >= value)
                    {
                        FUN_0095f930(actor, 1, 1000.0f);
                        if (state.FUN_00559450())
                            actor->FUN_SLOT48(4);
                        pressed = false;
                        DAT_011e0d5c = true;
                        actor->FUN_005d43c0()->FUN_004213c0(actor, this);
                        actor->FUN_005d43c0()->RemoveExtra(124);
                    }
                }
            }
        }
    }
}

struct Form
{
    int FUN_00401170();
};
struct Node
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int payload18;
    Node* FUN_00726070();
};
struct Target
{
    void UpdateEffectsByFlags(void* data);
};
struct Virtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14(void* data, int obj, int val);
};
extern char DAT_01183108;
extern char DAT_011839b4;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, const void*, const void*, int);
struct Obj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84;
    Virtual unk88;
    int unk8c, unk90;
    Target unk94;
    void ApplyFormPayload(Form* form, int unused);
};
// If form's type is 24 or 26, resolves a node via FUN_00ec43fb and passes its payload18 to unk88.vf14 and unk94.UpdateEffectsByFlags.
// @fnv 0x0095ea30
void Obj::ApplyFormPayload(Form* form, int unused)
{
    if (form->FUN_00401170() != 24 && form->FUN_00401170() != 26)
        return;
    Node* result = static_cast<Node*>(FUN_00ec43fb(form, 0, &DAT_01183108, &DAT_011839b4, 0));
    Node* node = result ? result->FUN_00726070() : 0;
    if (node)
    {
        unk88.vf14(node ? &node->payload18 : 0, (int)form, 0);
        unk94.UpdateEffectsByFlags(node ? &node->payload18 : 0);
    }
}

// For form type 0x18 or 0x1A with an enchantment, removes the spell if present, removes apForm from pEnchantedForms, and deletes the list when it becomes empty.
// @fnv 0x0095eb10
void PlayerEnchantStub::RemoveEnchantment(TESBoundObject* apForm, int aiUnused)
{
    if (apForm->FNV_GetFormType() != 0x18 && apForm->FNV_GetFormType() != 0x1A)
    {
        return;
    }
    if (pEnchantedForms == 0)
    {
        return;
    }
    TESEnchantableForm* pEnchantable = dynamic_cast<TESEnchantableForm*>(apForm);
    EnchantmentItem* pEnchantmentItem = pEnchantable ? pEnchantable->GetEnchantment() : 0;
    if (pEnchantmentItem == 0)
    {
        return;
    }
    if (kMagicTarget.HasSpell(pEnchantmentItem, true))
    {
        kMagicTarget.RemoveSpellStub(apForm, false);
    }
    pEnchantedForms->Remove(apForm);
    if (pEnchantedForms->IsEmptyStub())
    {
        delete pEnchantedForms;
        pEnchantedForms = 0;
    }
}
