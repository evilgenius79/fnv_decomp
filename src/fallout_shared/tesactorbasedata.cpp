// fallout_shared/tesactorbasedata.cpp: TABStub, FormNode, FlagSet, E2F0Interface and more (53 functions)

#include "tesactorbasedata.h"

struct BaseFC
{
    char pad[0x28];
    BaseFC();
    virtual void V0();
};
struct RecursiveSpinLock
{
    char p[4];
    RecursiveSpinLock();
    ~RecursiveSpinLock();
};
struct FUN_0047c700 : BaseFC
{
    RecursiveSpinLock lock;
    FUN_0047c700();
    virtual void V0();
    void InitActorBaseData();
};
// @fnv 0x0047c700
FUN_0047c700::FUN_0047c700()
{
    InitActorBaseData();
}

struct IntList
{
    ~IntList();
};
struct FUN_0047c880
{
    char pad[0x28];
    IntList list;
    virtual ~FUN_0047c880();
    void FUN_0047c9b0();
};
// @fnv 0x0047c880
FUN_0047c880::~FUN_0047c880()
{
    FUN_0047c9b0();
}

struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESHealthForm;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_0047c8e0_shell : public TESActorBaseData
{
    void InitActorBaseData();
};

struct SETTING_VALUE
{
    float f;
};

struct SettingT_GameSettingCollection_
{
    SETTING_VALUE* Float();
};

struct GlobalObject2_0040c150
{
    int* Int();
};

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting18;
extern SettingT_GameSettingCollection_ g_011c5074;
extern GlobalObject2_0040c150 g_011c50d8;

// @fnv 0x0047c8e0
void FUN_0047c8e0_shell::InitActorBaseData()
{
    *(unsigned int*)((char*)this + 0x04) = 0;
    *(unsigned short*)((char*)this + 0x08) = (unsigned short)originalRuntimeFloatSetting18.Float()->f;
    *(unsigned short*)((char*)this + 0x0a) = 0;
    *(unsigned short*)((char*)this + 0x0c) = 1;
    *(unsigned short*)((char*)this + 0x0e) = 0;
    *(unsigned short*)((char*)this + 0x10) = 0;
    *(unsigned short*)((char*)this + 0x12) = 100;
    *(float*)((char*)this + 0x14) = g_011c5074.Float()->f;
    *(unsigned short*)((char*)this + 0x18) = (unsigned short)*g_011c50d8.Int();
    *(unsigned int*)((char*)this + 0x20) = 0;
    *(unsigned int*)((char*)this + 0x1c) = 0;
    *(unsigned int*)((char*)this + 0x24) = 0;
    *(unsigned short*)((char*)this + 0x1a) = 0;
    *(unsigned int*)((char*)this + 0x28) = 0;
}

struct FUN_0047c9d0_shell : public TESActorBaseData
{
    void DeleteRegionColorEntries();
};

class NiColor;
class TESRegion
{
  public:
    NiColor* GetDiffuseColor();
};

void __cdecl operator delete(void*);
bool __fastcall _ref_008256d0(void*);
void** __fastcall _ref_006815c0(void*);
void __fastcall _ref_0063f7b0(void*);

// Iterates the region's color list, deleting each entry and advancing until the list is empty or _ref_008256d0 reports a stop.
// @fnv 0x0047c9d0
void FUN_0047c9d0_shell::DeleteRegionColorEntries()
{
    void* pList = ((TESRegion*)this)->GetDiffuseColor();
    while (pList && !_ref_008256d0(pList))
    {
        void* item = *_ref_006815c0(pList);
        operator delete(item);
        _ref_0063f7b0(pList);
    }
}

struct TABStub
{
    bool GetTemplateUseFlag(int);
    bool FUN_0047cca0();
};
// @fnv 0x0047cca0
bool TABStub::FUN_0047cca0()
{
    return GetTemplateUseFlag(0xf);
}

struct FUN_0047ccc0_shell : public TESActorBaseData
{
    void FUN_0047ccc0(bool);
};

struct FUN_0047cce0_shell
{
    void FUN_0047cce0(int, bool);
};

// @fnv 0x0047ccc0
void FUN_0047ccc0_shell::FUN_0047ccc0(bool abVal)
{
    reinterpret_cast<FUN_0047cce0_shell*>(this)->FUN_0047cce0(0xf, abVal);
}

struct DummyClass_0047cce0
{
    char pad[0x1a];
    unsigned short flags;
    void FUN_0047cce0(int index, bool set);
};

// Sets or clears bit `index` in the 16-bit flags field when index is in [0,16).
// @fnv 0x0047cce0
void DummyClass_0047cce0::FUN_0047cce0(int index, bool set)
{
    if (index >= 0 && index < 16)
    {
        unsigned short mask = 1 << index;
        if (set)
            flags |= mask;
        else
            flags &= ~mask;
    }
}

struct FUN_0047cd40_shell : public TESActorBaseData
{
    bool FUN_0047cd40(int);
};

// Returns true if the 16-bit flag word at offset 0x1a has the bit for aeFlag set; out-of-range flags return true.
// @fnv 0x0047cd40
bool FUN_0047cd40_shell::FUN_0047cd40(int aeFlag)
{
    if (aeFlag >= 0 && aeFlag < 16)
    {
        unsigned short usFlagMask = 1 << aeFlag;
        if (*((unsigned short*)((char*)this + 0x1a)) & usFlagMask)
            return true;
        return false;
    }
    return true;
}

struct FUN_0047cd90_shell : public TESActorBaseData
{
    void FUN_0047cd90(unsigned short);
};

// @fnv 0x0047cd90
void FUN_0047cd90_shell::FUN_0047cd90(unsigned short asVal)
{
    *(unsigned short*)((char*)this + 0x1a) = asVal;
}

struct FUN_0047cdb0_shell : public TESActorBaseData
{
    bool FUN_0047cdb0();
};

bool __fastcall FUN_0047cdd0(TESActorBaseData*);

// @fnv 0x0047cdb0
bool FUN_0047cdb0_shell::FUN_0047cdb0()
{
    bool bretval = FUN_0047cdd0(this);
    return bretval;
}

struct FUN_0047cdd0_shell : public TESActorBaseData
{
    bool FUN_0047cdd0();
};

int __fastcall _FNV_GetFormType(void*);

// Returns true if the pointer at offset 0x24 is non-null and its form type is 0x2c or 0x2d.
// @fnv 0x0047cdd0
bool FUN_0047cdd0_shell::FUN_0047cdd0()
{
    bool bretval = false;
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24))
    {
        switch (_FNV_GetFormType(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24)))
        {
        case 0x2c:
        case 0x2d:
            bretval = true;
            break;
        }
    }
    return bretval;
}

class BGSSaveLoadGame
{
  public:
    bool SetThreadAllowChanges(bool);
};

class TESDataHandler
{
  public:
    static TESForm* __cdecl CreateFormForType(int);
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
int __fastcall _FNV_GetFormType(TESActorBase*);

struct DummyBase1
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void CopyFrom(TESActorBase*);
    int pad[11];
};

struct DummyBase2
{
    virtual void b00();
    virtual void b01();
    virtual void b02();
    virtual void b03();
    virtual void CopyFromBase(TESActorBase*);
};

struct DummyActorBase : DummyBase1, DummyBase2
{
};

// @fnv 0x0047d130
TESActorBase* __cdecl FUN_0047d130(TESActorBase* apOriginalBase, TESActorBase* apTemplateBase)
{
    DummyActorBase* pnewbase;
    bool breset = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    pnewbase = (DummyActorBase*)TESDataHandler::CreateFormForType(_FNV_GetFormType(apOriginalBase));
    pnewbase->CopyFrom(apOriginalBase);
    pnewbase->CopyFromBase(apTemplateBase);
    g_BGSSaveLoadGame->SetThreadAllowChanges(breset);
    return (TESActorBase*)pnewbase;
}

class BSThread
{
  public:
    unsigned int GetThreadID();
};

struct DummyVtable
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual bool IsActorBase();
};

// @fnv 0x0047d1a0
DummyVtable* __cdecl FindFirstNonActorBaseTemplate(DummyVtable* apBase, unsigned short* aiOutCompositeTemplateUseFlags)
{
    DummyVtable* pNonActorBase = 0;
    *aiOutCompositeTemplateUseFlags = 0xFFFF;
    DummyVtable* pCurrent = apBase;
    while (pCurrent)
    {
        if (pCurrent->IsActorBase())
        {
            DummyVtable* ptempbase = pCurrent;
            *aiOutCompositeTemplateUseFlags &= *(unsigned short*)((char*)ptempbase + 0x4A);
            pCurrent = (DummyVtable*)((BSThread*)((char*)ptempbase + 0x30))->GetThreadID();
        }
        else
        {
            pNonActorBase = pCurrent;
            pCurrent = 0;
        }
    }
    return pNonActorBase;
}

struct FUN_0047d370_shell : public TESActorBaseData
{
    unsigned short FUN_0047d370();
};

// @fnv 0x0047d370
unsigned short FUN_0047d370_shell::FUN_0047d370()
{
    return *(unsigned short*)((char*)this + 0xc);
}

struct FUN_0047d390_shell : public TESActorBaseData
{
    unsigned short FUN_0047d390();
};

// @fnv 0x0047d390
unsigned short FUN_0047d390_shell::FUN_0047d390()
{
    return *(unsigned short*)((char*)this + 0xe);
}

namespace fnv_0047d680 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FactionSaveData;
struct FormRecordHeader;
struct TESFileGroup;
struct ReactionInfo;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct FactionRankPresentation;
struct TESBoundObject;
struct TESFaction;
struct TESForm;
struct TESObjectREFR;
struct TESReputation;
struct blob8
{
    char b[8];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESReactionForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearReactionList();
    int GetLowestReaction(TESForm**, int*, long);
    int GetHighestReaction(TESForm**, int*, long);
    void SetReactionValue(TESForm*, int);
    int GetReactionValue(TESForm*);
    void ModReaction(TESForm*, int);
    int GetFactionCombatRelation(TESForm*);
    void SetFightReaction(TESForm*, int);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(unsigned int, unsigned int);
    void* GetReactionList();
    void RemoveReactionItem(ReactionInfo*);
    void* __vecDelDtor(unsigned int);
    char m_kReactionList[8];
    unsigned char m_ucReactionFlags;
    char _pad_d[3];
};
typedef char _sizecheck_TESReactionForm[sizeof(TESReactionForm) == 16 ? 1 : -1];
struct FUN_0047d680_shell : public TESActorBaseData
{
    int GetFactionRank(TESFaction*, bool);
};

struct TESRegion
{
    NiColor* GetDiffuseColor(void);
};

struct FACTION_RANK_local
{
    TESFaction* faction;
    signed char rank;
};

FACTION_RANK_local** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
bool __fastcall HasFactionFlag8(TESFaction*);

// @fnv 0x0047d680
int FUN_0047d680_shell::GetFactionRank(TESFaction* apFaction, bool abPC)
{
    void* pList = ((TESRegion*)this)->GetDiffuseColor();
    while (pList && *_ref_006815c0(pList))
    {
        FACTION_RANK_local* prank = *_ref_006815c0(pList);
        if (abPC)
        {
            if (prank && !HasFactionFlag8(prank->faction) && prank->faction == apFaction)
                return prank->rank;
        }
        else
        {
            if (prank && prank->faction == apFaction)
                return prank->rank;
        }
        pList = _ref_00726070(pList);
    }
    return -1;
}
}  // namespace fnv_0047d680

struct FUN_0047dd30_shell : public TESActorBaseData
{
    void FUN_0047dd30(int);
};

void FUN_0047e2a0();

// Stores aiNewFlags into the field at offset 4 of this and calls FUN_0047e2a0 with 2.
// @fnv 0x0047dd30
void FUN_0047dd30_shell::FUN_0047dd30(int aiNewFlags)
{
    *(int*)((char*)this + 4) = aiNewFlags;
    ((void(__thiscall*)(void*, int)) & FUN_0047e2a0)(this, 2);
}

namespace fnv_0047de40 {
struct TABStub
{
    char pad[0xe];
    unsigned short v;
    void FUN_0047e2a0(int);
    void FUN_0047de40(unsigned short a);
};
// Stores the given unsigned short into v and calls FUN_0047e2a0 with 2.
// @fnv 0x0047de40
void TABStub::FUN_0047de40(unsigned short ausValue)
{
    v = ausValue;
    FUN_0047e2a0(2);
}
}  // namespace fnv_0047de40

namespace fnv_0047de70 {
struct TABStub
{
    char pad[0x10];
    unsigned short v;
    void FUN_0047e2a0(int);
    void FUN_0047de70(unsigned short a);
};
// Stores the given value in v and calls FUN_0047e2a0 with 2.
// @fnv 0x0047de70
void TABStub::FUN_0047de70(unsigned short ausValue)
{
    v = ausValue;
    FUN_0047e2a0(2);
}
}  // namespace fnv_0047de70

namespace fnv_0047dfe0 {
struct TABStub
{
    char pad[0xc];
    unsigned short v;
    void FUN_0047e2a0(int);
    void FUN_0047dfe0(unsigned short a);
};
// Stores the given value in v and calls FUN_0047e2a0 with 2.
// @fnv 0x0047dfe0
void TABStub::FUN_0047dfe0(unsigned short ausValue)
{
    v = ausValue;
    FUN_0047e2a0(2);
}
}  // namespace fnv_0047dfe0

namespace fnv_0047e010 {
struct TABStub
{
    char pad[8];
    unsigned short v;
    void FUN_0047e2a0(int);
    void FUN_0047e010(unsigned short a);
};
// Stores the given value in v and calls FUN_0047e2a0 with 2.
// @fnv 0x0047e010
void TABStub::FUN_0047e010(unsigned short ausValue)
{
    v = ausValue;
    FUN_0047e2a0(2);
}
}  // namespace fnv_0047e010

struct StartMenu
{
    const char* GetMenuTitle();
};
struct ActorSub
{
    virtual void V0();
    virtual void V1();
    virtual int V2(int);
};
struct Actor
{
    char pad[0xa4];
    ActorSub sub;
    unsigned short GetLevel();
};
extern StartMenu* DAT_01186d20[][50];
extern const char DAT_01011584[];
unsigned int __cdecl FUN_0047e040(float);
// @fnv 0x0047e0e0
const char* FUN_0047e0e0(Actor* actor)
{
    const char* result = 0;
    if (actor)
    {
        unsigned int kind;
        int level;
        level = actor->GetLevel();
        level = level - 1;
        if (level > 0x31)
            level = 0x31;
        if (level < 0)
            level = 0;
        kind = FUN_0047e040((float)actor->sub.V2(0x17));
        if (kind > 2)
        {
            if (kind == 3)
                kind = 0;
            else
                kind = 2;
        }
        if (DAT_01186d20[kind][level])
            result = DAT_01186d20[kind][level]->GetMenuTitle();
    }
    if (!result)
        result = DAT_01011584;
    return result;
}

namespace fnv_0047e1c0 {
struct SettingT_GameSettingCollection_
{
    float* Float();
};
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting25;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting24;
struct S47b
{
    char pad[0x14];
    float v;
    void FUN_0047e2a0(int);
    void SetClampedValue(float a);
};
// Stores a into v, clamps v between the two runtime float settings, then calls FUN_0047e2a0(2).
// @fnv 0x0047e1c0
void S47b::SetClampedValue(float afValue)
{
    v = afValue;
    if (v > *originalRuntimeFloatSetting25.Float())
        v = *originalRuntimeFloatSetting25.Float();
    else if (v < *originalRuntimeFloatSetting24.Float())
        v = *originalRuntimeFloatSetting24.Float();
    FUN_0047e2a0(2);
}
}  // namespace fnv_0047e1c0

struct S47
{
    char pad[0xa];
    short v;
    void FUN_0047e2a0(int);
    void SetValue(short a);
};
// Stores the given short into v and calls FUN_0047e2a0 with 2.
// @fnv 0x0047e240
void S47::SetValue(short asValue)
{
    v = asValue;
    FUN_0047e2a0(2);
}

namespace fnv_0047e270 {
struct FUN_0047e270_shell : public TESActorBaseData
{
    void SetSpeedMult(unsigned short);
};

void __fastcall FUN_0047e2a0(void*, int, int);

// Stores asSpeedMult at offset 0x12 of this object and calls FUN_0047e2a0 with this and 2.
// @fnv 0x0047e270
void FUN_0047e270_shell::SetSpeedMult(unsigned short asSpeedMult)
{
    *(unsigned short*)((char*)this + 0x12) = asSpeedMult;
    ((void(__thiscall*)(void*, int))FUN_0047e2a0)(this, 2);
}
}  // namespace fnv_0047e270

namespace fnv_0047e2a0 {
struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESHealthForm;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_0047e2a0_shell : public TESActorBaseData
{
    void FUN_0047e2a0(int);
};

// @fnv 0x0047e2a0
void FUN_0047e2a0_shell::FUN_0047e2a0(int aiChangeFlags)
{
    TESActorBase* pactbase = this ? reinterpret_cast<TESActorBase*>(reinterpret_cast<char*>(this) - 0x30) : 0;
    TESForm* pform = reinterpret_cast<TESForm*>(pactbase);
    if (pform)
    {
        typedef void(__thiscall * AddChange_t)(TESForm*, int);
        (*reinterpret_cast<AddChange_t*>((*reinterpret_cast<int*>(pform)) + 0x48))(pform, aiChangeFlags);
    }
}
}  // namespace fnv_0047e2a0

struct FUN_0047e340_shell : public TESActorBaseData
{
    void FUN_0047e340(int);
};

// @fnv 0x0047e340
void FUN_0047e340_shell::FUN_0047e340(int aiChangeFlags)
{
    *(int*)((char*)this + 0x28) |= aiChangeFlags;
}

struct TESActorBaseData_SetFlagBit_helper
{
    void UpdateFlagBit(int flag, bool clear, bool value);
};

class FUN_005f7b50_Class
{
  public:
    void SetFlag200(bool param1, bool param2);
};

// Calls the flag-bit helper on this object with flag 0x200, clearing it when param1 is false and passing param2 as the value.
// @fnv 0x005f7b50
void FUN_005f7b50_Class::SetFlag200(bool param1, bool abValue)
{
    reinterpret_cast<TESActorBaseData_SetFlagBit_helper*>(this)->UpdateFlagBit(0x200, param1 == 0, abValue);
}

namespace fnv_0047ca20 {
struct TESFaction;
struct FactionReaction
{
    void Endian();
    TESFaction* pFaction;
    char m_ucRank;
    char _pad_5[3];
};
typedef char _sizecheck_FACTION_RANK[sizeof(FactionReaction) == 8 ? 1 : -1];
struct FUN_0047ca20_shell : public TESActorBaseData
{
    void CopyFactionRanks(TESActorBaseData*);
};

void* __cdecl memcpy(void*, const void*, unsigned int);
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_0047c9d0_shell
{
    void DeleteRegionColorEntries();
};
class NiColor;
class TESRegion
{
  public:
    NiColor* GetDiffuseColor();
};
void** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
// Calls DeleteRegionColorEntries, then copies each faction rank from apCopy's list into this object's list, allocating and memcpy'ing 8-byte entries.
// @fnv 0x0047ca20
void FUN_0047ca20_shell::CopyFactionRanks(TESActorBaseData* apCopy)
{
    ((FUN_0047c9d0_shell*)this)->DeleteRegionColorEntries();
    SoundListView* pList = (SoundListView*)((TESRegion*)this)->GetDiffuseColor();
    SoundListView* pCopyList = (SoundListView*)((TESRegion*)apCopy)->GetDiffuseColor();
    while (pCopyList)
    {
        FactionReaction* prank = *(FactionReaction**)_ref_006815c0(pCopyList);
        if (prank)
        {
            FactionReaction* pFacRank = new FactionReaction;
            memcpy(pFacRank, prank, 8);
            pList->AddTail((char* const&)pFacRank);
        }
        SoundListView* tempList = (SoundListView*)_ref_00726070(pList);
        if (tempList)
            pList = tempList;
        pCopyList = (SoundListView*)_ref_00726070(pCopyList);
    }
}
}  // namespace fnv_0047ca20

namespace fnv_0047e040 {
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting20;
extern Setting_S originalRuntimeFloatSetting21;
extern Setting_S originalRuntimeFloatSetting22;
extern Setting_S originalRuntimeFloatSetting23;

// Maps a karma value to a level code (0-4) by comparing it against four runtime float thresholds.
// @fnv 0x0047e040
int FUN_0047e040(float afKarma)
{
    int iLevel = 1;
    if (afKarma <= *originalRuntimeFloatSetting20.Float())
    {
        if (afKarma <= *originalRuntimeFloatSetting22.Float())
            iLevel = 4;
        else
            iLevel = 2;
    }
    else
    {
        if (afKarma >= *originalRuntimeFloatSetting21.Float())
        {
            if (afKarma >= *originalRuntimeFloatSetting23.Float())
                iLevel = 3;
            else
                iLevel = 0;
        }
    }
    return iLevel;
}
}  // namespace fnv_0047e040

struct FUN_0047c850
{
    bool EvaluateCondition();
};

// @fnv 0x0047c850
bool FUN_0047c850::EvaluateCondition()
{
    return false;
}

struct FUN_0047d7e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    bool FUN_0047d7e0() const;
};

// @fnv 0x0047d7e0
bool FUN_0047d7e0_Class::FUN_0047d7e0() const
{
    return (m_34 & 4) ? true : false;
}

struct FUN_0047e360_Cls
{
    void __thiscall ClearFlags(unsigned int mask);
};

// @fnv 0x0047e360
void __thiscall FUN_0047e360_Cls::ClearFlags(unsigned int mask)
{
    ((int*)this)[0x28 / 4] &= ~mask;
}

struct ABD_0047c790
{
    bool FUN_0047c790() const;
};

// @fnv 0x0047c790
bool ABD_0047c790::FUN_0047c790() const
{
    return ((const TESActorBaseData*)this)->GetFlag(0x200000);
}

struct TESActorBaseData_0047c7b0
{
    bool GetFlag(unsigned int flag) const;
    bool FUN_0047c7b0() const;
};

bool TESActorBaseData_0047c7b0::GetFlag(unsigned int flag) const
{
    return false;
}

// @fnv 0x0047c7b0
bool TESActorBaseData_0047c7b0::FUN_0047c7b0() const
{
    return GetFlag(0x10000000);
}

namespace fnv_0047c9b0 {
struct FUN_0047c9d0_shell
{
    void DeleteRegionColorEntries();
};
struct FUN_0047c9b0_shell : public FUN_0047c9d0_shell
{
    void FUN_0047c9b0();
};
// @fnv 0x0047c9b0
void FUN_0047c9b0_shell::FUN_0047c9b0()
{
    DeleteRegionColorEntries();
}
}  // namespace fnv_0047c9b0

struct FUN_0047d720Class
{
    char pad[0x34];
    unsigned int factionFlags;
    bool HasFactionFlag8() const;
};

// @fnv 0x0047d720
bool FUN_0047d720Class::HasFactionFlag8() const
{
    return (factionFlags & 8) ? true : false;
}

struct FUN_0047d7c0_Class
{
    int __dummy;
    bool FUN_0047d7c0() const;
};

// @fnv 0x0047d7c0
bool FUN_0047d7c0_Class::FUN_0047d7c0() const
{
    return (*(const int*)((const char*)this + 0x34) & 2) ? true : false;
}

struct SoundH
{
    void* Deallocate();
};
void __cdecl FUN_00485910(int, int);
void __cdecl AppendChunk(int, void*, int);
bool __cdecl FUN_00401500();
struct FUN_0047cb90_t
{
    void SwapEndianness();
};
struct FUN_0047cac0_t
{
    void DestroySoundHandles();
};
// @fnv 0x0047cac0
void FUN_0047cac0_t::DestroySoundHandles()
{
    if (FUN_00401500())
        ((FUN_0047cb90_t*)((char*)this + 4))->SwapEndianness();
    AppendChunk(0x53424341, (char*)this + 4, 0x18);
    if (FUN_00401500())
        ((FUN_0047cb90_t*)((char*)this + 4))->SwapEndianness();
    if (*(unsigned int*)((char*)this + 0x1c))
    {
        unsigned int itempint = (unsigned int)((SoundH*)*(unsigned int*)((char*)this + 0x1c))->Deallocate();
        FUN_00485910(0x4d414e49, itempint);
    }
    if (*(unsigned int*)((char*)this + 0x20))
    {
        unsigned int itempint = (unsigned int)((SoundH*)*(unsigned int*)((char*)this + 0x20))->Deallocate();
        FUN_00485910(0x4b435456, itempint);
    }
    if (*(unsigned int*)((char*)this + 0x24))
    {
        unsigned int itempint = (unsigned int)((SoundH*)*(unsigned int*)((char*)this + 0x24))->Deallocate();
        FUN_00485910(0x544c5054, itempint);
    }
}

namespace fnv_0047d220 {
struct TgtOps
{
    void* GetPosition();
};
struct FUN_0047dd30_shell
{
    void FUN_0047dd30(int);
};
struct BSShaderPPLightingProperty
{
    unsigned short GetDiffuseTextureIndex();
};
struct S47
{
    void SetValue(short);
    void FUN_0047dea0(short);
};
struct FUN_0047d370_shell
{
    unsigned short FUN_0047d370();
};
struct FUN_0047d390_shell
{
    unsigned short FUN_0047d390();
};
struct FUN_0047d3b0_shell
{
    unsigned short FUN_0047d3b0();
};
struct FUN_0047d3d0_shell
{
    unsigned short FUN_0047d3d0();
};
unsigned short __fastcall GetShortAtOffset12(const char*);
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct RegionPointList
{
    void SetDistanceInsideAtMax(unsigned int);
};
struct BSThread
{
    unsigned int GetThreadID();
};
struct TESRecipe
{
    void SetSkill(int);
};
struct ABDHelper_47d220
{
    void FUN_0047e010(unsigned short);
    void SetClampedValue(float);
    void FUN_0047dfe0(unsigned short);
    void FUN_0047de40(unsigned short);
    void FUN_0047de70(unsigned short);
    void SetSpeedMult(unsigned short);
    void CopyFactionRanks(TESActorBaseData*);
    void FUN_0050f9a0(TESLevItem*);
};
struct ABD_47d220
{
    void CopyFromActorBaseData(BaseFormComponent* apCopyFC);
};

// @fnv 0x0047d220
void ABD_47d220::CopyFromActorBaseData(BaseFormComponent* apCopyFC)
{
    TESActorBaseData* pCopy = dynamic_cast<TESActorBaseData*>(apCopyFC);
    if (!pCopy)
        return;
    ((FUN_0047dd30_shell*)this)->FUN_0047dd30(*(int*)((TgtOps*)pCopy)->GetPosition());
    ((ABDHelper_47d220*)this)->FUN_0047e010(pCopy->GetFatigue());
    ((ABDHelper_47d220*)this)->SetClampedValue(pCopy->GetHealthRegeneration());
    ((S47*)this)->SetValue(((BSShaderPPLightingProperty*)pCopy)->GetDiffuseTextureIndex());
    ((ABDHelper_47d220*)this)->FUN_0047dfe0(((FUN_0047d370_shell*)pCopy)->FUN_0047d370());
    ((ABDHelper_47d220*)this)->FUN_0047de40(((FUN_0047d390_shell*)pCopy)->FUN_0047d390());
    ((ABDHelper_47d220*)this)->FUN_0047de70(((FUN_0047d3b0_shell*)pCopy)->FUN_0047d3b0());
    ((ABDHelper_47d220*)this)->SetSpeedMult(GetShortAtOffset12((const char*)pCopy));
    ((S47*)this)->FUN_0047dea0(((FUN_0047d3d0_shell*)pCopy)->FUN_0047d3d0());
    ((ABDHelper_47d220*)this)->CopyFactionRanks(pCopy);
    ((ABDHelper_47d220*)this)->FUN_0050f9a0((TESLevItem*)((BGSTerrainManager*)pCopy)->GetMinLevel());
    ((RegionPointList*)this)->SetDistanceInsideAtMax((unsigned int)pCopy->GetVoiceType());
    ((TESRecipe*)this)->SetSkill(((BSThread*)pCopy)->GetThreadID());
    ((TESActorBaseData*)this)->actorData.m_usField16 = pCopy->actorData.m_usField16;
}
}  // namespace fnv_0047d220

namespace fnv_0047e380 {
struct FormIDEntry
{
    unsigned int iFormID;
    unsigned char padding[5];
};

struct TESForm
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual const char* GetName() = 0;
};

struct BSSimpleListTESRaceSize
{
    int __thiscall GetSize();
};

struct TESSaveLoadGame
{
    bool __thiscall FUN_00862110();
    FormIDEntry* __thiscall GetHitSound();
};

struct GlobalObject_0045cf30
{
    unsigned char* __thiscall Bool();
};

struct Interface
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};

struct TESActorBaseData_0047e380
{
    unsigned short __thiscall FUN_0047e380(unsigned int aiFlags);
};

extern TESSaveLoadGame* DAT_011de45c;
extern GlobalObject_0045cf30 g_011de4e8;
TESForm* __cdecl _ref_004839c0(unsigned int);

// Computes the save size of the actor base data from flags and race list, optionally logging the size and form details.
// @fnv 0x0047e380
unsigned short TESActorBaseData_0047e380::FUN_0047e380(unsigned int aiFlags)
{
    unsigned short pform;
    unsigned short pheader;
    FormIDEntry* isize;
    TESForm* itempStartSize;

    pform = 0;
    pheader = pform;

    if (DAT_011de45c->FUN_00862110())
    {
        pform += 4;
        pform += 2;
    }

    if (aiFlags & 2)
        pform += 0x18;

    pform += 2;
    pform += reinterpret_cast<BSSimpleListTESRaceSize*>(reinterpret_cast<unsigned char*>(this) + 0x2c)->GetSize() * 5;

    if (*g_011de4e8.Bool())
    {
        isize = DAT_011de45c->GetHitSound();
        if (isize)
        {
            itempStartSize = _ref_004839c0(isize->iFormID);
            Interface::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", pform - pheader,
                isize->iFormID, itempStartSize->GetName(),
                *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(isize) + 5), 0xC4E,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
        else
        {
            Interface::PrintDebugMessage(
                "GetSaveSize(): %-5i ending at line %i in file %s", pform - pheader, 0xC4E,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
    }

    return pform;
}
}  // namespace fnv_0047e380

struct FUN_0047c770_cls
{
    int unk00;
    void Helper(unsigned int flags);
    void FUN_0047c770();
};

// @fnv 0x0047c770
void FUN_0047c770_cls::FUN_0047c770()
{
    Helper(0x100000);
}

struct EndianTag
{
};

void SwapInt(int* p, EndianTag t);
void SwapShort(short* p, EndianTag t);

struct Header47cb90
{
    int unk00;
    short unk04;
    short unk06;
    short unk08;
    short unk0A;
    short unk0C;
    short unk0E;
    int unk10;
    short unk14;
    short unk16;
    void SwapEndianness();
};

// Byte-swaps every integer and short field of the header structure to convert its endianness.
// @fnv 0x0047cb90
void Header47cb90::SwapEndianness()
{
    SwapInt(&unk00, EndianTag());
    SwapShort(&unk04, EndianTag());
    SwapShort(&unk06, EndianTag());
    SwapShort(&unk08, EndianTag());
    SwapShort(&unk0A, EndianTag());
    SwapShort(&unk0C, EndianTag());
    SwapShort(&unk0E, EndianTag());
    SwapInt(&unk10, EndianTag());
    SwapShort(&unk14, EndianTag());
    SwapShort(&unk16, EndianTag());
}

class FactionRec
{
  public:
    bool FUN_0047d7c0();
};

struct FactionLink
{
    FactionRec* pFaction;
};

class FormNode
{
  public:
    FormNode* FUN_005d8a70();
    bool FUN_008256d0();
    FactionLink** FUN_006815c0();
    FormNode* FUN_00726070();
    bool CheckFactionLinks();
};

// Walks the node chain from FUN_005d8a70, returning false if any node or its linked faction fails its check.
// @fnv 0x0047d740
bool FormNode::CheckFactionLinks()
{
    bool bValid = true;
    FormNode* p = FUN_005d8a70();
    if (p->FUN_008256d0())
    {
        bValid = false;
    }
    while (p != 0 && bValid)
    {
        FactionLink* x = *p->FUN_006815c0();
        if (x != 0)
        {
            if (!x->pFaction->FUN_0047d7c0())
            {
                bValid = false;
            }
        }
        p = p->FUN_00726070();
    }
    return bValid;
}

struct FlagSet;

struct NameRef
{
    unsigned int m_00;
    NameRef(const char* s);
    NameRef(const NameRef& o) : m_00(o.m_00)
    {}
};

struct GlobalMgr
{
    unsigned char Test(int value, NameRef name);
};

extern GlobalMgr* DAT_011ddf38;

extern const char DAT_01183028[];
extern const char DAT_01186cb4[];

int __cdecl FUN_00ec43fb(FlagSet* self, int a, const char* b, const char* c, int d);

struct FlagSet
{
    unsigned int unk00;
    unsigned int m_04;
    void FUN_0047dd50(int aMask, unsigned char aSet, unsigned char aForce);
    void FUN_0047e2a0(const char* s);
    void FUN_0047e2a0(int n);
    void ApplyToForm(const char* s);
};

// @fnv 0x0047dd50
void FlagSet::FUN_0047dd50(int aMask, unsigned char aSet, unsigned char aForce)
{
    unsigned char cur = (m_04 & aMask) != 0;
    if (cur != aSet)
    {
        if (aMask == 1)
        {
            int r = FUN_00ec43fb(this, 0, DAT_01186cb4, DAT_01183028, 0);
            if (r != 0)
            {
                if (!DAT_011ddf38->Test(r, NameRef("")))
                {
                    FUN_0047e2a0("");
                }
                else
                {
                    ApplyToForm("");
                }
            }
        }
        else if (aForce)
        {
            FUN_0047e2a0(2);
        }
    }
    (aSet ? (m_04 |= aMask) : (m_04 = (~aMask) & m_04));
}

class E2F0Interface
{
  public:
    virtual void vfunc00();

    void ApplyToForm(void* pArg);
};

class E2F0Form
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void Apply(void* pArg);

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
};

class E2F0Derived : public E2F0Form, public E2F0Interface
{
};

// Casts this interface pointer to the derived form and, if non-null, calls Apply on it with pArg.
// @fnv 0x0047e2f0
void E2F0Interface::ApplyToForm(void* pArg)
{
    E2F0Derived* pkDerived = static_cast<E2F0Derived*>(this);
    E2F0Form* pkForm3 = pkDerived;
    if (pkForm3)
        pkForm3->Apply(pArg);
}

class TESForm
{
  public:
    virtual void RTTIAnchor();
};
class TESAttackDamageForm
{
  public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int GetResult();
};
// Casts form to TESAttackDamageForm and returns its GetResult, or 0 if the cast fails.
// @fnv 0x0047fef0
int __cdecl GetAttackDamageResult(TESForm* form)
{
    TESAttackDamageForm* found = dynamic_cast<TESAttackDamageForm*>(form);
    if (found != 0)
    {
        return found->GetResult();
    }
    else
    {
        return 0;
    }
}

struct FUN_0047d410_link
{
    void* pFaction;
    signed char rank;
};

struct FUN_0047d410_node
{
    FUN_0047d410_node* FUN_00726070();
    FUN_0047d410_link** FUN_006815c0();
    int FUN_005ae380();
};

struct FUN_0047d410_cls : public TESActorBaseData
{
    void* FUN_00717e50();
    unsigned short FUN_0047d3f0();
    unsigned short FUN_0047d370();
    unsigned short FUN_0047d390();
    unsigned short FUN_0047d3b0();
    int FUN_00441110();
    unsigned short GetShortAtOffset12();
    unsigned short FUN_0047d3d0();
    FUN_0047d410_node* FUN_005d8a70();
    int FUN_0059bb30();
    int GetFactionRank(void* pFaction, int flag);
    bool IsDifferentFrom(BaseFormComponent* component);
};

// Compares this actor base data against another component field by field, returning true on the first mismatch and false when all compared values match.
// @fnv 0x0047d410
bool FUN_0047d410_cls::IsDifferentFrom(BaseFormComponent* component)
{
    FUN_0047d410_cls* other = (FUN_0047d410_cls*)dynamic_cast<TESActorBaseData*>(component);
    if (other == 0)
    {
        return true;
    }
    if (*(int*)this->FUN_00717e50() != *(int*)other->FUN_00717e50())
    {
        return true;
    }
    if (this->GetFatigue() != other->GetFatigue())
    {
        return true;
    }
    if (this->GetHealthRegeneration() != other->GetHealthRegeneration())
    {
        return true;
    }
    if (this->FUN_0047d3f0() != other->FUN_0047d3f0())
    {
        return true;
    }
    if (this->FUN_0047d370() != other->FUN_0047d370())
    {
        return true;
    }
    if (this->FUN_0047d390() != other->FUN_0047d390())
    {
        return true;
    }
    if (this->FUN_0047d3b0() != other->FUN_0047d3b0())
    {
        return true;
    }
    if (this->FUN_00441110() != other->FUN_00441110())
    {
        return true;
    }
    if (this->GetShortAtOffset12() != other->GetShortAtOffset12())
    {
        return true;
    }
    if (this->FUN_0047d3d0() != other->FUN_0047d3d0())
    {
        return true;
    }
    if (this->FUN_005d8a70()->FUN_005ae380() != other->FUN_005d8a70()->FUN_005ae380())
    {
        return true;
    }
    FUN_0047d410_node* node2 = this->FUN_005d8a70();
    FUN_0047d410_link* link;
    while (node2 != 0)
    {
        link = *node2->FUN_006815c0();
        if (link != 0)
        {
            if (other->GetFactionRank(link->pFaction, 0) != link->rank)
            {
                return true;
            }
        }
        node2 = node2->FUN_00726070();
    }
    if (this->GetVoiceType() != other->GetVoiceType())
    {
        return true;
    }
    if (this->FUN_0059bb30() != other->FUN_0059bb30())
    {
        return true;
    }
    if ((unsigned short)this->actorData.m_usField16 != (unsigned short)other->actorData.m_usField16)
    {
        return true;
    }
    return false;
}

namespace fnv_0047ce10 {
struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct ContainerItemExtra;
struct GameFormRecord;
struct TeleportableReference;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct LeveledObject;
struct CellDataNode;
struct MagicCaster;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESGlobal;
struct TESLeveledList;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct FileEntryList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct DistantTreeTextureInfo;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct FUN_0047ce10_shell : public TESActorBaseData
{
    void FUN_0047ce10(TESObjectREFR*);
};

struct ExtraShell
{
    int FUN_00418520();
    void FUN_0041aeb0();
    void FUN_0041af50();
};
struct FormShell
{
    int FUN_00401170();
    char pad[48];
};
struct LeveledShell
{
    char x;
    void AddLeveledItemsToContainer(class RefShell*, class TESContainer*);
};
struct NPCShell : FormShell, LeveledShell
{
};
struct CreatureShell : FormShell, LeveledShell
{
};
struct ItemShell
{
    int pad;
    void* value;
};
struct ListShell
{
    ItemShell** FUN_006815c0();
};
class TESContainer
{
  public:
    int data[3];
    TESContainer();
    ~TESContainer();
    ListShell* FUN_00717e50();
};
class RefShell
{
  public:
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62();
    virtual bool isActor();
    virtual bool isOther();
    virtual void v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(),
        v79(), v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(),
        v95(), v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(),
        v109(), v110(), v111(), v112(), v113(), v114();
    virtual void reset(int, int);
    virtual void v116(), v117(), v118(), v119(), v120(), v121(), v122(), v123(), v124(), v125(), v126(), v127(), v128(),
        v129(), v130(), v131(), v132(), v133(), v134(), v135(), v136(), v137(), v138(), v139(), v140(), v141(), v142(),
        v143(), v144();
    virtual void update();
    bool FUN_0056afc0();
    void* FUN_008d8520();
    ExtraShell* FUN_005d43c0();
    void FUN_00884f80();
    void* FUN_007af430();
    void FUN_0056b020(void*, void*);
    void FUN_00575690(void*);
    void FUN_00565730();
};
struct GlobalShell
{
    bool FUN_004121b0();
};
struct StateShell
{
    int FUN_00559450();
    void FUN_006ebd10(int);
};
struct InvShell
{
    void FUN_004d1440();
    void FUN_004d1610();
    void FUN_004d1960();
    bool FUN_0042cde0();
};
extern "C" char DAT_011ddf38;
StateShell* GetPathManager();
void* FUN_0047d130(void*, void*);
InvShell* FUN_004bf220(RefShell*);
struct OwnerShell
{
    bool FUN_0047cdb0();
    FormShell* FUN_0059bb30();
    void FUN_0047ce10(RefShell* ref);
};
// @fnv 0x0047ce10
void OwnerShell::FUN_0047ce10(RefShell* ref)
{
    if (!ref || !FUN_0047cdb0() || ref->FUN_0056afc0())
        return;
    LeveledShell* level = 0;
    if (FUN_0059bb30()->FUN_00401170() == 45)
    {
        NPCShell* npc2 = (NPCShell*)FUN_0059bb30();
        level = npc2;
    }
    else if (FUN_0059bb30()->FUN_00401170() == 44)
    {
        CreatureShell* creature3 = (CreatureShell*)FUN_0059bb30();
        level = creature3;
    }
    if (level)
    {
        TESContainer container;
        level->AddLeveledItemsToContainer(ref, &container);
        void* base6 = (*container.FUN_00717e50()->FUN_006815c0())->value;
        if (!*(GlobalShell**)&DAT_011ddf38 || !(*(GlobalShell**)&DAT_011ddf38)->FUN_004121b0())
        {
            if (ref->isActor())
            {
                RefShell* actor4 = ref;
                if (actor4->FUN_008d8520())
                    actor4->update();
            }
            ref->reset(0, 1);
        }
        if (GetPathManager()->FUN_00559450())
            GetPathManager()->FUN_006ebd10(ref->FUN_005d43c0()->FUN_00418520());
        ref->FUN_005d43c0()->FUN_0041aeb0();
        ref->FUN_005d43c0()->FUN_0041af50();
        if (ref->isOther())
        {
            RefShell* other3 = ref;
            other3->FUN_00884f80();
        }
        void* oldbase2 = ref->FUN_007af430();
        void* newbase = FUN_0047d130(oldbase2, base6);
        ref->FUN_0056b020(oldbase2, base6);
        ref->FUN_00575690(newbase);
        ref->FUN_00565730();
        InvShell* inventory = FUN_004bf220(ref);
        inventory->FUN_004d1440();
        inventory->FUN_004d1610();
        inventory->FUN_004d1960();
        if (inventory->FUN_0042cde0())
        {
            ref->FUN_005d43c0()->FUN_0041aeb0();
            inventory = 0;
        }
    }
}
}  // namespace fnv_0047ce10

class FactionReaction
{
  public:
    TESFaction* pFaction;
    unsigned char ucRank;
};

class TESFaction
{
  public:
    unsigned int GetFormID();
};

class FormObj
{
  public:
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual const char* GetName();
};

class SaveRefRecord
{
  public:
    unsigned int formId;
};

class SaveGameBuffer
{
  public:
    unsigned char* GetWritePos();
    bool IsSaving();
    void WriteBytes(const void* p, unsigned int n);
    void WriteDword(const void* p, unsigned int n);
    SaveRefRecord* GetSavedRef();
};

class SettingRef
{
  public:
    unsigned char* GetFlag();
};

extern SaveGameBuffer* DAT_011de45c;
extern SettingRef DAT_011de4e8;

void __cdecl FUN_005b5e40(const char* fmt, const char* file, int line);
int __cdecl FUN_0040fbe0(const char* fmt, ...);
FormObj* __cdecl LookupFormByID(unsigned int formId);

class FUN_0047e4a0_cls : public TESActorBaseData
{
  public:
    BSSimpleList<FactionReaction*>* GetFactionHead();
    void SaveFactionData(int flags);
};

// @fnv 0x0047e4a0
void FUN_0047e4a0_cls::SaveFactionData(int flags)
{
    unsigned char* startPosP;
    unsigned char* blockPosY;
    unsigned short kBlockSize;
    kBlockSize = 0;
    blockPosY = 0;
    unsigned int magic;
    unsigned char* countPos_;
    unsigned short aCount;
    BSSimpleList<FactionReaction*>* nodeV;
    FactionReaction* itemL;
    unsigned int formIdQ;
    unsigned char rank;
    unsigned char* endPos;
    unsigned char* baseStart;
    unsigned char* endPosB;
    FormObj* _obj;
    SaveRefRecord* aRefF;

    startPosP = DAT_011de45c->GetWritePos();
    if (*DAT_011de4e8.GetFlag())
    {
        startPosP = DAT_011de45c->GetWritePos();
    }
    if (DAT_011de45c->IsSaving())
    {
        magic = 0x424c4f4b;
        DAT_011de45c->WriteBytes(&magic, 4);
        blockPosY = DAT_011de45c->GetWritePos();
        DAT_011de45c->WriteBytes(&kBlockSize, 2);
    }
    if (flags & 2)
    {
        DAT_011de45c->WriteBytes(&actorData, 0x18);
    }
    aCount = 0;
    countPos_ = DAT_011de45c->GetWritePos();
    DAT_011de45c->WriteBytes(&aCount, 2);
    nodeV = GetFactionHead();
    while (nodeV)
    {
        itemL = nodeV->GetItem();
        if (itemL)
        {
            formIdQ = itemL->pFaction->GetFormID();
            rank = itemL->ucRank;
            DAT_011de45c->WriteDword(&formIdQ, 4);
            DAT_011de45c->WriteBytes(&rank, 1);
            aCount++;
        }
        nodeV = nodeV->GetNext();
    }
    *(unsigned short*)countPos_ = aCount;

    if (*DAT_011de4e8.GetFlag())
    {
        endPos = DAT_011de45c->GetWritePos();
        aRefF = DAT_011de45c->GetSavedRef();
        if (aRefF)
        {
            _obj = LookupFormByID(aRefF->formId);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         endPos - startPosP, aRefF->formId, _obj->GetName(),
                         *(unsigned int*)((unsigned char*)aRefF + 5), 0xc77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", endPos - startPosP, 0xc77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp");
        }
    }

    if (DAT_011de45c->IsSaving())
    {
        endPosB = DAT_011de45c->GetWritePos();
        baseStart = blockPosY;
        if (endPosB > baseStart + 0xffff)
        {
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 0xc77);
        }
        *(unsigned short*)blockPosY = (unsigned short)(endPosB - baseStart);
    }
}

struct FACTION_RANK_Data
{
    TESFaction* m_pFaction;
    signed char m_rank;
    char pad[3];
};

class FactionNode
{
  public:
    FACTION_RANK_Data*& GetItem();
    FactionNode* GetNext();
    void RemoveHead();
    void AddHead(FACTION_RANK_Data*& item);
};

struct FUN_0047d800_shell
{
    FactionNode* FUN_005d8a70();
    void FUN_0047d800(TESFaction* faction, signed char rank);
};

// Sets the rank of a faction in the linked list, removing the entry when rank is -1 and adding a new entry when the faction is not found.
// @fnv 0x0047d800
void FUN_0047d800_shell::FUN_0047d800(TESFaction* faction, signed char rank)
{
    if (faction == 0)
        return;

    FactionNode* pNode = FUN_005d8a70();
    while (pNode != 0)
    {
        FACTION_RANK_Data* rankData = pNode->GetItem();
        if (rankData != 0 && rankData->m_pFaction == faction)
        {
            if (rank == -1)
                pNode->RemoveHead();
            else
                rankData->m_rank = rank;
            return;
        }
        pNode = pNode->GetNext();
    }

    FACTION_RANK_Data* rankData = new FACTION_RANK_Data;
    rankData->m_pFaction = faction;
    rankData->m_rank = rank;
    FUN_005d8a70()->AddHead(rankData);
}

namespace fnv_0047e6f0 {
struct LoadingFormHeader
{
    unsigned int flags;
    unsigned char version;
};

struct LoadingFormInfo
{
    unsigned int formID;
    const LoadingFormHeader* Header() const
    {
        return (const LoadingFormHeader*)((const char*)this + 5);
    }
};

struct TESSaveLoadGame
{
    bool FUN_00862110();
    void FUN_008579e0(void* buf, unsigned int size);
    LoadingFormInfo* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    void FUN_00857aa0(unsigned int* pOut, int size);
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

class TESFormVfunc : public TESForm
{
  public:
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual const char* GetName();
};

class FactionReaction
{
  public:
    TESFaction* pFaction;
    char m_ucRank;
};

void* __cdecl operator new(unsigned int);
TESForm* __cdecl LookupFormByID(unsigned int);
void __cdecl FNV_Warning(const char*, ...);

struct TESActorBaseData_Shell : public TESActorBaseData
{
    void DeleteRegionColorEntries();
    BSSimpleList<FactionReaction*>* FUN_005d8a70();
    void FUN_0047e6f0(unsigned int changeFlags, void* pBuffer);
};

// Reads actor base data and faction rank entries from the save stream, then verifies the block size against the expected read size.
// @fnv 0x0047e6f0
void TESActorBaseData_Shell::FUN_0047e6f0(unsigned int changeFlags, void* pBuffer)
{
    TESForm* formVal;
    unsigned int curOff;
    LoadingFormInfo* info;
    FactionReaction* rank2;
    TESForm* form2;
    char val;
    unsigned int factID;
    unsigned short totalItems;
    int idx;
    TESForm* loadedForm;
    LoadingFormInfo* loadBuffer;
    unsigned int type;
    unsigned short readSize = 0;
    unsigned int offsetA = 0;

    if (g_TESSaveLoadGame->FUN_00862110())
    {
        g_TESSaveLoadGame->FUN_008579e0(&type, 4);
        if (type != 0x424C4F4B)
        {
            loadBuffer = g_TESSaveLoadGame->FUN_004fd3c0();
            if (loadBuffer)
            {
                loadedForm = LookupFormByID(loadBuffer->formID);
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3200,
                    loadBuffer->formID, ((TESFormVfunc*)loadedForm)->GetName(),
                    ((LoadingFormHeader*)((char*)loadBuffer + 5))->version,
                    ((LoadingFormHeader*)((char*)loadBuffer + 5))->flags);
            }
            else
            {
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3200,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
        offsetA = g_TESSaveLoadGame->FUN_00825c00();
        g_TESSaveLoadGame->FUN_008579e0(&readSize, 2);
    }

    if (changeFlags & 2)
    {
        g_TESSaveLoadGame->FUN_008579e0(&this->actorData, sizeof(this->actorData));
    }

    this->DeleteRegionColorEntries();

    g_TESSaveLoadGame->FUN_008579e0(&totalItems, 2);
    for (idx = 0; idx < totalItems; ++idx)
    {
        g_TESSaveLoadGame->FUN_00857aa0(&factID, 4);
        g_TESSaveLoadGame->FUN_008579e0(&val, 1);
        form2 = LookupFormByID(factID);
        if (form2)
        {
            rank2 = new FactionReaction;
            rank2->pFaction = (TESFaction*)form2;
            rank2->m_ucRank = val;
            this->FUN_005d8a70()->AddHead(rank2);
        }
    }

    if (g_TESSaveLoadGame->FUN_00862110())
    {
        curOff = g_TESSaveLoadGame->FUN_00825c00();
        info = g_TESSaveLoadGame->FUN_004fd3c0();
        if (info)
        {
            formVal = LookupFormByID(info->formID);
            if (curOff > (unsigned int)(readSize + offsetA))
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    curOff - (readSize + offsetA),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234, info->formID,
                    ((TESFormVfunc*)formVal)->GetName(), ((LoadingFormHeader*)((char*)info + 5))->version,
                    ((LoadingFormHeader*)((char*)info + 5))->flags);
            }
            else if (curOff < (unsigned int)(readSize + offsetA))
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    (readSize + offsetA) - curOff,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234, info->formID,
                    ((TESFormVfunc*)formVal)->GetName(), ((LoadingFormHeader*)((char*)info + 5))->version,
                    ((LoadingFormHeader*)((char*)info + 5))->flags);
            }
        }
        else
        {
            if (curOff > (unsigned int)(readSize + offsetA))
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    curOff - (readSize + offsetA),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234,
                    g_TESSaveLoadGame->FUN_008df040());
            }
            else if (curOff < (unsigned int)(readSize + offsetA))
            {
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    (readSize + offsetA) - curOff,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBaseData.cpp", 3234,
                    g_TESSaveLoadGame->FUN_008df040());
            }
        }
    }
}
}  // namespace fnv_0047e6f0

void __cdecl ResolveFormID(unsigned int* pId, TESFile* pFile);

bool __cdecl FUN_0040eb10(float a, float b, float c);

void __cdecl FNV_Warning(const char* fmt, ...);

extern const char DAT_01184704[];

extern const char DAT_01186318[];

extern const char DAT_01186f7c[];

extern float DAT_01186d08[];

extern int DAT_01186f78;

extern float DAT_011c52a4;

extern float DAT_011c52a0;

extern float DAT_011c529c;

extern SettingT_GameSettingCollection_ DAT_011c5090;

extern SettingT_GameSettingCollection_ DAT_011c4e54;

extern SettingT_GameSettingCollection_ DAT_011c5144;

extern SettingT_GameSettingCollection_ DAT_011c4f64;

struct FormFileVtbl
{

    virtual void Reserved00();

    virtual void Reserved01();

    virtual void Reserved02();

    virtual void Reserved03();

    virtual void Reserved04();

    virtual void Reserved05();

    virtual void Reserved06();

    virtual void Reserved07();

    virtual void Reserved08();

    virtual void Reserved09();

    virtual void Reserved10();

    virtual void Reserved11();

    virtual void Reserved12();

    virtual void Reserved13();

    virtual void Reserved14();

    virtual void Reserved15();

    virtual void Reserved16();

    virtual void Reserved17();

    virtual void Reserved18();

    virtual void Reserved19();

    virtual void Reserved20();

    virtual void Reserved21();

    virtual void Reserved22();

    virtual void Reserved23();

    virtual void Reserved24();

    virtual void Reserved25();

    virtual void Reserved26();

    virtual void Reserved27();

    virtual void Reserved28();

    virtual void Reserved29();

    virtual void Reserved30();

    virtual void Reserved31();

    virtual void Reserved32();

    virtual void Reserved33();

    virtual void Reserved34();

    virtual void Reserved35();

    virtual void Reserved36();

    virtual void Reserved37();

    virtual void Reserved38();

    virtual void Reserved39();

    virtual void Reserved40();

    virtual void Reserved41();

    virtual void Reserved42();

    virtual void Reserved43();

    virtual void Reserved44();

    virtual void Reserved45();

    virtual void Reserved46();

    virtual void Reserved47();

    virtual void Reserved48();

    virtual void Reserved49();

    virtual void Reserved50();

    virtual void Reserved51();

    virtual void Reserved52();

    virtual void Reserved53();

    virtual void Reserved54();

    virtual void Reserved55();

    virtual void Reserved56();

    virtual void Reserved57();

    virtual void Reserved58();

    virtual void Reserved59();

    virtual void Reserved60();

    virtual void Reserved61();

    virtual void Reserved62();

    virtual void Reserved63();

    virtual void Reserved64();

    virtual void Reserved65();

    virtual void Reserved66();

    virtual void Reserved67();

    virtual void Reserved68();

    virtual void Reserved69();

    virtual void Reserved70();

    virtual void Reserved71();

    virtual void Reserved72();

    virtual void Reserved73();

    virtual void Reserved74();

    virtual void Reserved75();

    virtual const char* GetEditorID();
};

__if_not_exists(BGSVoiceType::BGSVoiceType)
{
    class BGSVoiceType
    {
      public:
        virtual void RTTIAnchor();
    };
}

__if_not_exists(TESLevItem::TESLevItem)
{
    class TESLevItem
    {
      public:
        virtual void RTTIAnchor();
    };
}

struct FormHelper
{

    TESFile* GetFile(int n);

    unsigned int GetFormID();
};

struct ActorBaseInitItemView : public TESActorBaseData
{

    void FUN_0047d8b0(TESForm* param);
};

// Updates faction and template pointers using the file from param->GetFile(-1), then adjusts actorData.m_fField10 for recognized values.
// @fnv 0x0047d8b0
void ActorBaseInitItemView::FUN_0047d8b0(TESForm* param)

{

    TESFile* file4;

    TESForm* form4;

    FormNode* node2;

    FactionLink* link5;

    FactionRec* faction;

    int i2;

    node2 = ((FormNode*)this)->FUN_005d8a70();

    file4 = param ? ((FormHelper*)param)->GetFile(-1) : 0;

    while (node2 != 0)
    {

        link5 = *node2->FUN_006815c0();

        if (link5 != 0)
        {

            if (link5->pFaction != 0)
            {

                faction = link5->pFaction;

                ResolveFormID((unsigned int*)&faction, file4);

                link5->pFaction =
                    (FactionRec*)dynamic_cast< ::TESFaction*>((TESForm*)LookupFormByID((unsigned int)faction));
            }

            if (link5->pFaction != 0)
            {

                node2 = node2->FUN_00726070();
            }
            else
            {

                _ref_0063f7b0(node2);
            }
        }
        else
        {

            node2 = node2->FUN_00726070();
        }
    }

    form4 = (TESForm*)m_kFactionList;

    if (form4 != 0)
    {

        ResolveFormID((unsigned int*)&form4, file4);

        m_kFactionList = (::BGSVoiceType*)dynamic_cast<BGSVoiceType*>((TESForm*)LookupFormByID((unsigned int)form4));
    }

    form4 = (TESForm*)m_pBaseTemplateForm;

    if (form4 != 0)
    {

        ResolveFormID((unsigned int*)&form4, file4);

        m_pBaseTemplateForm = (::TESLevItem*)dynamic_cast<TESLevItem*>((TESForm*)LookupFormByID((unsigned int)form4));

        if (m_pBaseTemplateForm == 0)
        {

            FNV_Warning("MASTERFILE: Unable to find death item (%08X) on ActorBase (%08X) '%s'.", (unsigned int)form4,
                        ((FormHelper*)param)->GetFormID(), ((FormFileVtbl*)param)->GetEditorID());
        }
    }

    form4 = m_ppTemplateForms;

    if (form4 != 0)
    {

        ResolveFormID((unsigned int*)&form4, file4);

        m_ppTemplateForms = (TESForm*)LookupFormByID((unsigned int)form4);

        if (m_ppTemplateForms == 0)
        {

            FNV_Warning("MASTERFILE: Unable to find template form (%08X) on ActorBase (%08X) '%s'.",
                        (unsigned int)form4, ((FormHelper*)param)->GetFormID(), ((FormFileVtbl*)param)->GetEditorID());
        }
    }

    if (!(m_ppTemplateForms != 0 && ((FUN_0047cd40_shell*)this)->FUN_0047cd40(0)))
    {

        if (DAT_01186f78 == -1)
        {

            for (i2 = 0; i2 < 5; i2++)
            {

                if ((int)FUN_0047e040(DAT_01186d08[i2]) != i2)
                {

                    DAT_01186f78 = 1;

                    DAT_011c52a4 = DAT_011c5090.Float()->f - DAT_011c4e54.Float()->f;

                    DAT_011c52a0 = DAT_011c4e54.Float()->f - DAT_011c5144.Float()->f;

                    DAT_011c529c = DAT_011c4f64.Float()->f - DAT_011c5144.Float()->f;

                    break;
                }
            }

            if (DAT_01186f78 != 1)
            {

                DAT_01186f78 = 0;
            }
        }

        if (DAT_01186f78 == 1)
        {

            if (FUN_0040eb10(actorData.m_fField10, DAT_01186d08[1], 0.001f))
            {

                actorData.m_fField10 = DAT_011c4e54.Float()->f - DAT_011c52a0 * 0.5f;
            }
            else if (FUN_0040eb10(actorData.m_fField10, DAT_01186d08[0], 0.001f))
            {

                actorData.m_fField10 = DAT_011c4e54.Float()->f + DAT_011c52a4 * 0.5f;
            }
            else if (FUN_0040eb10(actorData.m_fField10, DAT_01186d08[2], 0.001f))
            {

                actorData.m_fField10 = DAT_011c5144.Float()->f + DAT_011c529c * 0.5f;
            }
            else if (FUN_0040eb10(actorData.m_fField10, DAT_01186d08[3], 0.001f))
            {

                actorData.m_fField10 = DAT_011c5090.Float()->f + 100.0;
            }
            else if (FUN_0040eb10(actorData.m_fField10, DAT_01186d08[4], 0.001f))
            {

                actorData.m_fField10 = DAT_011c4f64.Float()->f - 100.0;
            }
            else
            {

                FNV_Warning("Invalid karma value found. Unable to fix.");
            }
        }
    }
}
