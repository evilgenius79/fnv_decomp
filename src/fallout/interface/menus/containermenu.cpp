// fallout/interface/menus/containermenu.cpp: ContainerMenu, MenuStateTarget, MenuLogic, ContainerValue and more (40 functions)

#include "containermenu_decls.h"
#include "containermenu_packet.h"
// Reads a save-file signature and header fields from the file into headerArg, returning early if the signature matches DAT_011a2224.
// @fnv 0x0084dab0
void ReadSaveFileHeader(void* pFile, void* pHeader)
{
    ((SaveLoadFile*)pFile)->SetFilePosition(0);
    char signature[260];
    signature[0] = 0;
    fnv_zlib_memset(signature + 1, 0, 259);
    ((SaveLoadFile*)pFile)->Read(signature, strlen(DAT_011a2224));
    if (FUN_00408b20(signature, DAT_011a2224))
        return;
    unsigned skill;
    BGSLoadGameBuffer storage;
    storage.ReadAndVerifySize((SaveLoadFile*)pFile);
    {
        TESLandTexture* parentTexture;
        BGSLoadGameBuffer* pLoadBuffer = &storage;
        char* saveTime;
        int saveVersion = 0;
        pLoadBuffer->ReadDataBlock(&saveVersion, 4);
        ((BGSAcousticSpace*)pHeader)->SetNoonSound((TESSound*)saveVersion);
        if (saveVersion == 48)
        {
            char* data = pLoadBuffer->GetCombinedValue();
            if (data[4] == '|')
                ((SaveHeaderOps*)pHeader)->QueueWeapon(ENGLISH);
            else
            {
                char language[64];
                pLoadBuffer->ReadDataBlock(language, 64);
                ((SaveHeaderOps*)pHeader)->QueueWeapon(language);
            }
        }
        else
        {
            char language[64];
            pLoadBuffer->ReadDataBlock(language, 64);
            ((SaveHeaderOps*)pHeader)->QueueWeapon(language);
        }
        saveTime = 0;
        skill = 0;
        pLoadBuffer->ReadDataBlock(&saveTime, 4);
        pLoadBuffer->ReadDataBlock(&skill, 4);
        parentTexture = 0;
        pLoadBuffer->ReadDataBlock(&parentTexture, 4);
        ((TESRegionGrassObject*)pHeader)->AssignLandTexture((TESLandTexture*)parentTexture);
        ((TESEnchantableForm*)pHeader)->SetCastingType((MagicSystem__CastingType)(unsigned)pLoadBuffer->LoadString(0));
        ((BGSQuestObjective*)pHeader)->SetOwnerQuest((TESQuest*)pLoadBuffer->LoadString(0));
        if (saveVersion > 47)
        {
            unsigned spell = 0;
            pLoadBuffer->ReadDataBlock(&spell, 4);
            ((BGSDehydrationStage*)pHeader)->FUN_0050f9a0((SpellItem*)spell);
        }
        ((TESConditionItem*)pHeader)->SetObjectType((int)pLoadBuffer->LoadString(0));
        ((InterfaceManager*)pHeader)->FUN_00984f60((unsigned)pLoadBuffer->LoadString(0));
        ((TESResponse*)pHeader)->SetSpeakerIdle((TESIdleForm*)saveTime);
        ((TESRecipe*)pHeader)->SetSkill(skill);
        ((TESRecipe*)pHeader)->SetSkillLevel(((SaveLoadFile*)pFile)->GetFilePosition());
    }
}

// @fnv 0x0075b750
void ContainerMenu::Close()
{
    if (DAT_011d93f8)
    {
        DAT_011d93f8->m_kFadeSequence.StopWithFade(100);

        switch (DAT_011d93f8->m_eContainerMenuMode)
        {
        case 1:
            ((ContainerMenu*)DAT_011d93f8)->UpdateContainer(DAT_011d93f8->m_pContainer, false);
            break;
        case 2: {
            TESObjectREFR* actor =
                ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor() ? DAT_011d93f8->m_pContainer : 0;
            if (!actor && DAT_011d93f8->m_iStolenItemCount > 0)
            {
                ((Actor*)g_thePlayer)
                    ->StealAlarm(DAT_011d93f8->m_pContainer, 0, 0, DAT_011d93f8->m_iStolenItemCount,
                                 DAT_011d93f8->m_pContainer->GetOwner());
            }
            ((ContainerMenu*)DAT_011d93f8)->UpdateContainer(DAT_011d93f8->m_pContainer, false);
            break;
        }
        case 4:
            if (!((HUDMainMenu*)&DAT_011f2250)->RefreshTargetDisplay())
                ((CloseVirtualSlots*)g_thePlayer)->vfn_340(9);
            break;
        case 3: {
            bool processContainer = false;
            if (((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor() &&
                ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->vfn_1e4())
            {
                if (((Actor*)DAT_011d93f8->m_pContainer)->GetProcess() &&
                    ((CloseVirtualSlots*)((Actor*)DAT_011d93f8->m_pContainer)->GetProcess())->GetCastsShadows())
                    processContainer = true;
            }
            if (((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsCreature())
            {
                void* form = DAT_011d93f8->m_pContainer->GetObjectReference();
                ((TESCreature*)form)->UpdateModel3D(DAT_011d93f8->m_pContainer, true, true, true);
            }
            else
            {
                void* form = DAT_011d93f8->m_pContainer->GetObjectReference();
                ((TESNPC*)form)
                    ->RebuildHeadModel(DAT_011d93f8->m_pContainer,
                                       ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->vfn_1e8(true));
            }
            if (processContainer && ((Actor*)DAT_011d93f8->m_pContainer)->IsFirstActorFlagSet())
            {
                if (!((CloseVirtualSlots*)((Actor*)DAT_011d93f8->m_pContainer)->GetProcess())->GetCastsShadows())
                    ((Actor*)DAT_011d93f8->m_pContainer)->SetIsSwimming(false);
            }
            {
                BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01072278, 0x121).Play(false);
            }
            StartDialogueForTopic(0);
            break;
        }
        }

        ((BSSimpleList<ActorCause*>*)&DAT_011d93f8->m_kContainerItems)->RemoveAll();
        (*(Tile**)((char*)DAT_011d93f8 + 4))->Set(0x1772, 1);
        DAT_011d93f8->LoadMenuData();
        if (((CloseVirtualSlots*)((Actor*)g_thePlayer)->GetProcess())->vfn_474(true))
            g_thePlayer->UpdatePlayerControls();
        FUN_00778b10();
    }
}

struct FUN_0075b200_shell
{
    int __thiscall GetClass();
};

// @fnv 0x0075b200
int __thiscall FUN_0075b200_shell::GetClass()
{
    return 0x3f0;
}

struct FUN_0075b210_shell : ContainerMenu
{
    void AssignTileByID(int id, Tile* tile);
};

// @fnv 0x0075b210
void FUN_0075b210_shell::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 19)
    {
        m_pTiles[id] = tile;
    }
}

extern void* DAT_011d8a80;

// @fnv 0x0075b6e0
void FUN_0075b6e0(int param1)
{
    if (DAT_011d8a80)
        *(char*)((char*)DAT_011d8a80 + 0x4cd) = (char)param1;
}

// @fnv 0x0075b700
int __cdecl FUN_0075b700()
{
    return 1008;
}

struct FUN_0075cc70_shell
{
    void* FUN_0075cc70();
};

// @fnv 0x0075cc70
void* FUN_0075cc70_shell::FUN_0075cc70()
{
    return reinterpret_cast<char*>(this) + 0xDF4;
}

int __cdecl _mbscmp(unsigned char const*, unsigned char const*);
struct FUN_00a011f0_shell
{
    char* __thiscall FUN_00a011f0(int);
};

// Compares the strings returned by FUN_00a011f0(0xfc4) on both items using _mbscmp and returns the result.
// @fnv 0x0075d130
int FUN_0075d130(FUN_00a011f0_shell** apItem1, FUN_00a011f0_shell** apItem2)
{
    return _mbscmp((unsigned char const*)(*apItem1)->FUN_00a011f0(0xfc4),
                   (unsigned char const*)(*apItem2)->FUN_00a011f0(0xfc4));
}

void __cdecl _Deallocate(void*);
struct FUN_0075b240_shell
{
    void FUN_0075b270();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_0075b270, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0075b240
void* FUN_0075b240_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0075b270();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0075c250_Holder
{
    bool HandleKey(int aiKey);
};
// Handles key 0x20 by closing ContainerMenu and reports whether the key was handled.
// @fnv 0x0075c250
bool FUN_0075c250_Holder::HandleKey(int aiKey)
{
    bool bhandled = false;
    switch (aiKey)
    {
    case 0x20:
        ContainerMenu::Close();
        bhandled = true;
        break;
    }
    return bhandled;
}

struct FUN_0075cf70_shell
{
    void __thiscall ClearTileValues(int aiID, Tile* apTarget);
};
// Sets the value 0xFA3 to 0 on the Tile objects at offsets 0x5C, 0x58 and 0x4C of this object.
// @fnv 0x0075cf70
void __thiscall FUN_0075cf70_shell::ClearTileValues(int aiID, Tile* apTarget)
{
    (*(Tile**)((char*)this + 0x5C))->Set(0xFA3, 0);
    (*(Tile**)((char*)this + 0x58))->Set(0xFA3, 0);
    (*(Tile**)((char*)this + 0x4C))->Set(0xFA3, 0);
}

struct FUN_0075b710_shell
{
    int _pad[10];
    int field28[19];
    bool __thiscall FUN_0075b710();
};
// Returns false if any of the 19 ints in field28 is zero, otherwise returns true.
// @fnv 0x0075b710
bool __thiscall FUN_0075b710_shell::FUN_0075b710()
{
    for (int i = 0; i < 0x13; ++i)
    {
        if (field28[i] == 0)
            return false;
    }
    return true;
}

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};
struct Date
{
    virtual ~Date();
};
struct ListX
{
    virtual ~ListX();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct FUN_0075b270 : Menu_007a8b10
{
    char pad0[0x78 - 4];
    ListX m_kNode;
    char pad1[0x98 - 0x78 - 4];
    FUN_007308e0 m_kPointA;
    char pad2[0xc8 - 0x98 - 4];
    FUN_007308e0 m_kPointB;
    char pad3[0x100 - 0xc8 - 4];
    Date m_date;
    virtual ~FUN_0075b270();
};
// @fnv 0x0075b270
FUN_0075b270::~FUN_0075b270()
{
    DAT_011d93f8 = 0;
}

struct FUN_0075cc90_Local
{
    unsigned int m_unk00;
    FUN_0075cc90_Local();
    ~FUN_0075cc90_Local();
    void Clear();
};

struct FUN_0075cc90_Node
{
    FUN_0075cc90_Node* Next();
    void** Value();
};

struct FUN_0075cc90_Obj
{
    void Attach(void* a, FUN_0075cc90_Local* l);
    int Query(int a, int b);
};

struct FUN_0075cc90_Sink
{
    void Deliver(void* a);
    void Apply(void* v, int r);
};

struct FUN_0075cc90_cls
{
    void AttachAndDeliver(void* a1, void* a2, void* a3);
};

// If a1, a2 and a3 are non-null, attaches a1 to a2, delivers a1 to a3, then applies each node value from the local list to a3 and clears the list.
// @fnv 0x0075cc90
void FUN_0075cc90_cls::AttachAndDeliver(void* a1, void* apObj, void* apSink)
{
    FUN_0075cc90_Local pad;
    unsigned int list;
    if (apObj != 0 && a1 != 0 && apSink != 0)
    {
        ((FUN_0075cc90_Obj*)apObj)->Attach(a1, &pad);
        ((FUN_0075cc90_Sink*)apSink)->Deliver(a1);
        FUN_0075cc90_Node* p;
        for (p = (FUN_0075cc90_Node*)&pad; p != 0 && *p->Value() != 0; p = p->Next())
        {
            ((FUN_0075cc90_Sink*)apSink)->Apply(*p->Value(), ((FUN_0075cc90_Obj*)*p->Value())->Query(0, 0));
        }
        pad.Clear();
    }
}

class TESForm
{
  public:
    virtual ~TESForm();
    int GetFormType();
};
class TESBoundObject : public TESForm
{
  public:
};
class TESFullName
{
  public:
    virtual ~TESFullName();
    int GetLength() const;
};
class TESBipedModelForm
{
  public:
    virtual ~TESBipedModelForm();
    static TESBipedModelForm* GetFormAsBipedModel(TESForm* apForm);
    bool IsPlayable();
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    bool IsPlayable();
};
class TESAmmo : public TESBoundObject
{
  public:
    unsigned char GetFlag() const;
};
struct ScriptStub
{
    int GetCount();
};
struct ExtraListStub
{
    ScriptStub* GetScript();
};
struct InventoryEntryStub
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
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    ExtraListStub extraList;
};
class RefEx : public TESObjectREFR
{
  public:
    TESBoundObject* GetBaseObject();
};
class PlayerCharacterEx : public PlayerCharacter
{
  public:
    InventoryEntryStub* GetEntryFor(TESBoundObject* apObject);
};

// @fnv 0x0075cfc0
bool IsRefBaseObjectUnplayable(RefEx* apRef)
{
    bool bResult = false;
    if (DAT_011d93f8)
    {
        TESBoundObject* pObject = apRef ? apRef->GetBaseObject() : 0;
        if (DAT_011d93f8->m_eContainerMenuMode == 4)
        {
            bResult =
                static_cast<PlayerCharacterEx*>(g_thePlayer)->GetEntryFor(pObject)->extraList.GetScript()->GetCount() <
                0;
        }
        else
        {
            TESBipedModelForm* pBiped = TESBipedModelForm::GetFormAsBipedModel(pObject);
            TESFullName* pFullName = dynamic_cast<TESFullName*>(pObject);
            TESObjectWEAP* pWeapon =
                apRef->GetBaseObject()->GetFormType() == 0x28 ? (TESObjectWEAP*)apRef->GetBaseObject() : 0;
            TESAmmo* pAmmo = apRef->GetBaseObject()->GetFormType() == 0x29 ? (TESAmmo*)apRef->GetBaseObject() : 0;
            if (!pObject || (pBiped && !pBiped->IsPlayable()) || !pFullName || !pFullName->GetLength() ||
                (pWeapon && !pWeapon->IsPlayable()) || (pAmmo && !pAmmo->GetFlag()))
            {
                bResult = true;
            }
        }
    }
    return bResult;
}

int __cdecl FUN_00406d00(char* buf, unsigned size, const char* fmt, char* name, int count);

struct ContainerLikeObj
{
    bool FUN_004bddd0(int);
    int FUN_00726070();
    char* GetTargetFullName();
    void* FUN_0073ac90(int, int);
    void FUN_00700320();
    void FUN_00a01350(int, char*, int);
    void FUN_00a01350(void*);
    void FUN_00707e10(char*);
    void* FUN_00a011f0(int, int);
    void* FUN_007b5370(int);
    void FUN_00a012d0(int, float, int);
};

// @fnv 0x0075d160
void __cdecl FUN_0075d160(void* param1, void* param2)
{
    char buf[0x80];

    if (((ContainerLikeObj*)param2)->FUN_004bddd0(0))
    {
        (*(ContainerLikeObj**)((ContainerLikeObj*)((char*)param1 + 4))->FUN_0073ac90(0xfa3, 1))->FUN_00700320();
    }

    if (((ContainerLikeObj*)param2)->FUN_00726070() > 1)
    {
        FUN_00406d00(buf, 0x80, "%s (%d)", ((ContainerLikeObj*)param2)->GetTargetFullName(),
                     ((ContainerLikeObj*)param2)->FUN_00726070());
        ((ContainerLikeObj*)param1)->FUN_00a01350(0xfc4, buf, 1);
    }

    ((ContainerLikeObj*)param1)->FUN_00707e10(((ContainerLikeObj*)param2)->GetTargetFullName());
    (*(ContainerLikeObj**)((ContainerLikeObj*)((char*)param1 + 4))->FUN_007b5370(0xfc4))
        ->FUN_00a01350(((ContainerLikeObj*)param1)->FUN_00a011f0(0xfc4, 1));
    ((ContainerLikeObj*)param1)->FUN_00a012d0(0xfb0, 0.0f, 1);
}

struct FUN_0075d430_base
{
    virtual void vfn_0000() = 0;
    virtual void vfn_0004() = 0;
    virtual void vfn_0008() = 0;
    virtual void FUN_0075d430_call(int param1, int param2) = 0;
};

struct FUN_0075d430_shell : FUN_0075d430_base
{
    char unk04[0x20];
    int unk24;
    char unk28[0x58];
    int unk80;

    bool __thiscall FUN_0075d430(int param1, int param2);
};

extern void __cdecl FUN_0075b750();

// @fnv 0x0075d430
bool __thiscall FUN_0075d430_shell::FUN_0075d430(int param1, int aiUnused)
{
    bool result = false;

    if (param1 == 0x0b && unk80 != 4 && unk80 != 3 && unk24 == 1)
    {
        FUN_0075d430_call(0x0a, 0);
        result = true;
    }
    else if (param1 == 0x0a)
    {
        FUN_0075b750();
        result = true;
    }

    return result;
}

// Menu input handler: on accept (1) or cancel (6), play the matching state depending on the controller state.

class InputDeviceState
{
  public:
    long GetState();
};

InputDeviceState* __cdecl GetInputDeviceState();

class MenuStateTarget
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void SetState(int iState, int iUnk);

    void ApplyMenuAction(int iAction, int iUnused);
};

// For actions 1 and 6, sets the menu state based on whether the input device state is negative.
// @fnv 0x0075d4a0
void MenuStateTarget::ApplyMenuAction(int iAction, int iUnused)
{
    if (iAction == 1 || iAction == 6)
    {
        if (GetInputDeviceState()->GetState() < 0)
            SetState(iAction == 1 ? 0 : 5, 0);
        else
            SetState(iAction == 1 ? 2 : 7, 0);
    }
}

struct ActorView
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void vfn_00e8();
    virtual void vfn_00ec();
    virtual void vfn_00f0();
    virtual void vfn_00f4();
    virtual void vfn_00f8();
    virtual void vfn_00fc();
    virtual bool IsActor();
    virtual void vfn_0104();
    virtual void vfn_0108();
    virtual void vfn_010c();
    virtual void vfn_0110();
    virtual void vfn_0114();
    virtual void vfn_0118();
    virtual void vfn_011c();
    virtual void vfn_0120();
    virtual void vfn_0124();
    virtual void vfn_0128();
    virtual void vfn_012c();
    virtual void vfn_0130();
    virtual void vfn_0134();
    virtual void vfn_0138();
    virtual void vfn_013c();
    virtual void vfn_0140();
    virtual void vfn_0144();
    virtual void vfn_0148();
    virtual void vfn_014c();
    virtual void vfn_0150();
    virtual void vfn_0154();
    virtual void vfn_0158();
    virtual void vfn_015c();
    virtual void vfn_0160();
    virtual void vfn_0164();
    virtual void vfn_0168();
    virtual void vfn_016c();
    virtual void vfn_0170();
    virtual void vfn_0174();
    virtual void vfn_0178();
    virtual void vfn_017c();
    virtual void vfn_0180();
    virtual void vfn_0184();
    virtual void vfn_0188();
    virtual void vfn_018c();
    virtual void vfn_0190();
    virtual void vfn_0194();
    virtual void vfn_0198();
    virtual void vfn_019c();
    virtual bool CanInteract(int);
    virtual void vfn_01a4();
    virtual void vfn_01a8();
    virtual void vfn_01ac();
    virtual void vfn_01b0();
    virtual void vfn_01b4();
    virtual void vfn_01b8();
    virtual void vfn_01bc();
    virtual void vfn_01c0();
    virtual void vfn_01c4();
    virtual void vfn_01c8();
    virtual void vfn_01cc();
    virtual void vfn_01d0();
    virtual void vfn_01d4();
    virtual void vfn_01d8();
    virtual void vfn_01dc();
    virtual void vfn_01e0();
    virtual void vfn_01e4();
    virtual void vfn_01e8();
    virtual void vfn_01ec();
    virtual void vfn_01f0();
    virtual void vfn_01f4();
    virtual void vfn_01f8();
    virtual void vfn_01fc();
    virtual void vfn_0200();
    virtual void vfn_0204();
    virtual void vfn_0208();
    virtual void vfn_020c();
    virtual void vfn_0210();
    virtual void vfn_0214();
    virtual void vfn_0218();
    virtual void vfn_021c();
    virtual void vfn_0220();
    virtual void vfn_0224();
    virtual void vfn_0228();
    virtual bool IsDisabled(int);
    virtual void vfn_0230();
    virtual void vfn_0234();
    virtual void vfn_0238();
    virtual void vfn_023c();
    virtual void vfn_0240();
    virtual void vfn_0244();
    virtual void vfn_0248();
    virtual void vfn_024c();
    virtual void vfn_0250();
    virtual void vfn_0254();
    virtual void vfn_0258();
    virtual void vfn_025c();
    virtual void vfn_0260();
    virtual void vfn_0264();
    virtual void vfn_0268();
    virtual void vfn_026c();
    virtual void vfn_0270();
    virtual void vfn_0274();
    virtual void vfn_0278();
    virtual void vfn_027c();
    virtual void vfn_0280();
    virtual void vfn_0284();
    virtual void vfn_0288();
    virtual void vfn_028c();
    virtual void vfn_0290();
    virtual void vfn_0294();
    virtual void vfn_0298();
    virtual void vfn_029c();
    virtual void vfn_02a0();
    virtual void vfn_02a4();
    virtual void vfn_02a8();
    virtual void vfn_02ac();
    virtual void vfn_02b0();
    virtual void vfn_02b4();
    virtual void vfn_02b8();
    virtual void vfn_02bc();
    virtual void vfn_02c0();
    virtual void vfn_02c4();
    virtual void vfn_02c8();
    virtual void vfn_02cc();
    virtual void vfn_02d0();
    virtual void vfn_02d4();
    virtual void vfn_02d8();
    virtual void vfn_02dc();
    virtual void vfn_02e0();
    virtual void vfn_02e4();
    virtual void vfn_02e8();
    virtual void vfn_02ec();
    virtual void vfn_02f0();
    virtual void vfn_02f4();
    virtual void vfn_02f8();
    virtual void vfn_02fc();
    virtual void vfn_0300();
    virtual void vfn_0304();
    virtual void vfn_0308();
    virtual void vfn_030c();
    virtual void vfn_0310();
    virtual void vfn_0314();
    virtual void vfn_0318();
    virtual void vfn_031c();
    virtual void vfn_0320();
    virtual void vfn_0324();
    virtual void vfn_0328();
    virtual void vfn_032c();
    virtual void vfn_0330();
    virtual void vfn_0334();
    virtual void vfn_0338();
    virtual void vfn_033c();
    virtual void vfn_0340();
    virtual void vfn_0344();
    virtual void vfn_0348();
    virtual void vfn_034c();
    virtual void vfn_0350();
    virtual void vfn_0354();
    virtual void vfn_0358();
    virtual void vfn_035c();
    virtual void vfn_0360();
    virtual void vfn_0364();
    virtual void vfn_0368();
    virtual void vfn_036c();
    virtual void vfn_0370();
    virtual void vfn_0374();
    virtual void vfn_0378();
    virtual void vfn_037c();
    virtual void vfn_0380();
    virtual void vfn_0384();
    virtual bool IsValid();
    bool FUN_0087f3d0();
    ActorView* FUN_008d8520();
};
struct CurrentItem
{
    int FUN_004fd4f0();
};
struct SourceForm
{
    int FUN_00401170();
    bool FUN_004c0bf0();
    CurrentItem* GetOrFallback(ActorView* actor);
};
struct InventoryEntry
{
    SourceForm* FUN_0044ddc0();
};
struct ActiveList
{
    bool FUN_008256d0();
};
struct ExpectedReference
{
    bool FUN_004997b0();
};
extern ExpectedReference* DAT_011dea3c;
struct MenuLogic : ContainerMenu
{
    bool FUN_0075d510(InventoryEntry* entry, ExpectedReference* reference, ActorView* actor);
};
// @fnv 0x0075d510
bool MenuLogic::FUN_0075d510(InventoryEntry* entry, ExpectedReference* reference, ActorView* actor)
{
    if (m_eContainerMenuMode == 2 &&
        *reinterpret_cast<void**>(otherData + 0x70) == static_cast<void*>(otherData + 0x10) &&
        reference == DAT_011dea3c && DAT_011dea3c->FUN_004997b0() && actor->IsActor() && !actor->IsDisabled(0) &&
        !actor->CanInteract(0) && entry->FUN_0044ddc0()->FUN_00401170() == 0x28 &&
        reinterpret_cast<ActiveList*>(&m_kContainerItems)->FUN_008256d0())
    {
        ActorView* a = 0;
        if (actor->IsActor())
        {
            a = actor;
            if (a->FUN_0087f3d0())
                return false;
            if (a->FUN_008d8520())
            {
                if (a->FUN_008d8520()->IsValid())
                    return false;
            }
        }
        SourceForm* b = entry->FUN_0044ddc0();
        if (b->FUN_004c0bf0())
        {
            if (b->GetOrFallback(a))
            {
                if (b->GetOrFallback(a)->FUN_004fd4f0() == 0x20000)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

struct ExtraDataList
{
    TESForm* GetOwner();
    short FUN_00418770();
};
struct ItemNode
{
    ExtraDataList** FUN_006815c0();
    ItemNode* FUN_00726070();
};
struct ItemEntry
{
    float FUN_004bd400();
    ItemNode* FUN_00559450();
};
extern "C" int __cdecl TruncateFloatToInt(float);
struct ContainerValue : ContainerMenu
{
    int GetContainerValue(ItemEntry* entry, int amount, bool includeUnowned);
};
// @fnv 0x0075e240
int ContainerValue::GetContainerValue(ItemEntry* entry, int amount, bool includeUnowned)
{
    TESForm* owner = 0;
    int value = TruncateFloatToInt(entry->FUN_004bd400());
    int count = amount;
    int total = 0;
    if (((CloseVirtualSlots*)m_pContainer)->IsActor())
        owner = (TESForm*)m_pContainer;
    else
        owner = m_pContainer->GetOwner();
    for (ItemNode* node = entry->FUN_00559450(); count > 0 && node && *node->FUN_006815c0();
         node = node->FUN_00726070())
    {
        TESForm* itemOwner = (*node->FUN_006815c0())->GetOwner();
        if ((!itemOwner && includeUnowned) || (itemOwner && (*node->FUN_006815c0())->GetOwner() == owner))
            total += (*node->FUN_006815c0())->FUN_00418770() * value;
        count -= (*node->FUN_006815c0())->FUN_00418770();
    }
    if (includeUnowned)
        total += count * value;
    return total;
}

struct MenuTile
{
    virtual ~MenuTile();
    MenuTile* ReadFile(const char*);
    ContainerMenu* GetMenu();
    float FUN_00a011b0(int);
    static float FUN_00a01530();
    void Set(int, float, bool);
    void Set(int, const char*, bool);
};
struct MenuInput
{
    void FUN_00718630(int, int, int);
};
struct MenuSystem
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
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
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    MenuInput input;
    MenuTile* FUN_00586150();
};
MenuSystem* FUN_004b7210();
struct ContainerVirtual
{
    virtual ~ContainerVirtual();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual int GetClass();
};
struct MenuList
{
    void Initialize(Tile*, const char*);
};
struct MenuData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    MenuTile* tile28;
    MenuTile* tile2c;
    MenuTile* tile30;
    MenuTile* tile34;
    MenuTile* tile38;
    MenuTile* tile3c;
    MenuTile* tile40;
    MenuTile* tile44;
    MenuTile* tile48;
    MenuTile* tile4c;
    MenuTile* tile50;
    MenuTile* tile54;
    MenuTile* tile58;
    MenuTile* tile5c;
    MenuTile* tile60;
    MenuTile* tile64;
    MenuTile* tile68;
    MenuTile* tile6c;
    MenuTile* tile70;
    TESObjectREFR* reference;
    int unk78;
    int unk7c;
    int mode;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    MenuList list98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    MenuList listc8;
    void FUN_00a1dc70(MenuTile*, bool);
    bool FUN_0075b710();
    MenuTile* FUN_00726070();
    void FUN_0075bc80();
    void FUN_00a1dc20(int);
    void FUN_0075c280(int);
};
ContainerVirtual* FUN_00a09030(int);
void FNV_Warning(const char*, ...);
MenuTile* FUN_00a08b20(MenuTile*, const char*);
int TraitNameToID(const char*);
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011d4378, DAT_011d2d0c, DAT_011d33fc, DAT_011d2c7c, DAT_011d412c, DAT_011d330c,
    DAT_011d20c4, DAT_011d396c;
// Loads container_menu.xml, validates the container menu, initializes its lists and title tiles, stores the reference and mode, and returns the menu tile.
// @fnv 0x0075b310
MenuTile* FUN_0075b310(TESObjectREFR* reference, int mode)
{
    MenuSystem* tile = FUN_004b7210();
    FUN_0075b6e0(0);
    if (!reference && mode != 4)
        return 0;
    ContainerVirtual* old = FUN_00a09030(FUN_0075b700());
    if (old)
        delete old;
    MenuTile* manager = tile->FUN_00586150()->ReadFile("Data\\Menus\\container_menu.xml");
    DAT_011d93f8 = manager ? manager->GetMenu() : 0;
    if (DAT_011d93f8 && ((ContainerVirtual*)DAT_011d93f8)->GetClass() == FUN_0075b700())
    {
        ((MenuData*)DAT_011d93f8)->FUN_00a1dc70(manager, false);
        if (!((MenuData*)DAT_011d93f8)->FUN_0075b710())
        {
            FNV_Warning("MENUS: Container Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (manager->FUN_00a011b0(4007) == 6006.0 || manager->FUN_00a011b0(4007) == 102.0)
            manager->Set(4013, MenuTile::FUN_00a01530(), true);
        tile->input.FUN_00718630(22, FUN_0075b700(), 512);
        ((MenuData*)DAT_011d93f8)->list98.Initialize((Tile*)((MenuData*)DAT_011d93f8)->tile38, "CM_list_template");
        ((MenuData*)DAT_011d93f8)->listc8.Initialize((Tile*)((MenuData*)DAT_011d93f8)->tile48, "CM_list_template");
        ((MenuData*)DAT_011d93f8)->tile2c->Set(4036, DAT_011d4378.FUN_00403df0(), true);
        ((MenuData*)DAT_011d93f8)->tile50->Set(4036, DAT_011d2d0c.FUN_00403df0(), true);
        ((MenuData*)DAT_011d93f8)->tile54->Set(4036, DAT_011d33fc.FUN_00403df0(), true);
        MenuTile* title = FUN_00a08b20(((MenuData*)DAT_011d93f8)->FUN_00726070(), "CM_Subtitle");
        if (title)
            title->Set(4036, "", true);
        ((MenuData*)DAT_011d93f8)->reference = reference;
        ((MenuData*)DAT_011d93f8)->mode = mode;
        ((MenuData*)DAT_011d93f8)->FUN_0075bc80();
        int subtitle = TraitNameToID("_Title");
        if (((MenuData*)DAT_011d93f8)->tile60)
            ((MenuData*)DAT_011d93f8)->tile60->Set(subtitle, DAT_011d2c7c.FUN_00403df0(), true);
        if (((MenuData*)DAT_011d93f8)->tile64)
            ((MenuData*)DAT_011d93f8)->tile64->Set(subtitle, DAT_011d412c.FUN_00403df0(), true);
        if (((MenuData*)DAT_011d93f8)->tile68)
            ((MenuData*)DAT_011d93f8)->tile68->Set(subtitle, DAT_011d330c.FUN_00403df0(), true);
        if (((MenuData*)DAT_011d93f8)->tile6c)
            ((MenuData*)DAT_011d93f8)->tile6c->Set(subtitle, DAT_011d20c4.FUN_00403df0(), true);
        if (((MenuData*)DAT_011d93f8)->tile70)
            ((MenuData*)DAT_011d93f8)->tile70->Set(subtitle, DAT_011d396c.FUN_00403df0(), true);
        ((MenuData*)DAT_011d93f8)->FUN_00a1dc20(0);
        ((MenuData*)DAT_011d93f8)->FUN_0075c280(0);
        return manager;
    }
    else if (DAT_011d93f8 && ((MenuData*)DAT_011d93f8)->FUN_00726070())
    {
        delete (ContainerVirtual*)DAT_011d93f8;
    }
    return 0;
}

class TESSound
{
  public:
    const char* FUN_00511840();
};
struct TESObjectCONTStub : TESBoundObject
{
    TESSound* GetOpenSound();
    TESSound* GetCloseSound();
};
struct BSAudioEx : BSAudio
{
    SoundPlaybackHandle GetSoundHandleByFilePath(const char* apName, unsigned auiFlags, TESSound* apSound);
};
struct ContainerMenuEx : ContainerMenu
{
    void FUN_0075baf0(TESObjectREFR* apRef, bool abOpen);
};

// @fnv 0x0075baf0
void ContainerMenuEx::FUN_0075baf0(TESObjectREFR* apRef, bool abOpen)
{
    TESSound* SoundAssetTmp = 0;
    if (!apRef)
        return;
    switch (apRef->GetObjectReference()->GetFormType())
    {
    case 0x1b:
        if (abOpen)
            SoundAssetTmp = static_cast<TESObjectCONTStub*>(apRef->GetObjectReference())->GetOpenSound();
        else
            SoundAssetTmp = static_cast<TESObjectCONTStub*>(apRef->GetObjectReference())->GetCloseSound();
        break;
    case 0x2a:
    case 0x2b:
        if (abOpen)
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("DRSBodyGenericOpen", 0x121).Play(false);
        else
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("DRSBodyGenericClose", 0x121).Play(false);
        break;
    }
    if (SoundAssetTmp)
        static_cast<BSAudioEx*>(BSAudio::GetSingleton())
            ->GetSoundHandleByFilePath(SoundAssetTmp->FUN_00511840(), 0x121, SoundAssetTmp)
            .Play(false);
}

struct Menu75d250Pane
{
    virtual void vf00();
    virtual int IsBusy();
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
    unsigned GetCount();
    void Reset();
    void SetActive(int abActive);
};

struct Menu75d250
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void SetState(int aiState, int aiUnk);
    virtual void Notify(int aiID, int aiUnk);
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
    int unk94;
    Menu75d250Pane m_fMinimumU;
    Menu75d250Pane m_fMaximumU;
    Menu75d250Pane* m_pActive;
    bool HandleMenuAction(int aiAction, int aiUnused);
};

bool __cdecl FUN_00702450(int aiID);

// Handles menu actions 13/14 by switching between the two panes and actions 3/4 by resetting the active pane and setting state, returning whether handled.
// @fnv 0x0075d250
bool Menu75d250::HandleMenuAction(int aiAction, int aiUnused)
{
    bool bHandled = false;
    if (FUN_00702450(0x3f0))
    {
        switch (aiAction)
        {
        case 13:
            if (!m_fMinimumU.IsBusy() && m_fMinimumU.GetCount() > 0)
            {
                m_fMaximumU.Reset();
                Notify(0x15, 0);
                m_fMinimumU.SetActive(1);
                bHandled = true;
            }
            break;
        case 14:
            if (!m_fMaximumU.IsBusy() && m_fMaximumU.GetCount() > 0)
            {
                m_fMinimumU.Reset();
                Notify(0x16, 0);
                m_fMaximumU.SetActive(1);
                bHandled = true;
            }
            break;
        case 3:
        case 4:
            if (unk80 != 4)
            {
                if (m_pActive == &m_fMinimumU)
                {
                    m_fMinimumU.Reset();
                    SetState(aiAction == 4 ? 0 : 2, 0);
                    m_fMinimumU.SetActive(0);
                }
                else
                {
                    m_fMaximumU.Reset();
                    SetState(aiAction == 4 ? 5 : 7, 0);
                    m_fMaximumU.SetActive(0);
                }
                bHandled = true;
            }
            break;
        }
    }
    return bHandled;
}

struct XRef_0075d6b0
{
    bool FUN_00440da0();
    bool FUN_00440d80();
};
struct XList_0075d6b0
{
    XRef_0075d6b0* FUN_0041de00();
    short FUN_00418770();
};
struct Node_0075d6b0
{
    XList_0075d6b0** FUN_006815c0();
    Node_0075d6b0* FUN_00726070();
};
struct Entry_0075d6b0
{
    ~Entry_0075d6b0();
    SourceForm* FUN_0044ddc0();
    Node_0075d6b0* FUN_00559450();
    Node_0075d6b0* FUN_00726070();
};
struct Ref_0075d6b0
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
    virtual void FUN_17c(SourceForm* item, XList_0075d6b0* extra, int count, bool stolen, int a5, Ref_0075d6b0* from,
                         int a7, int a8, bool a9, int a10);
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void FUN_190(SourceForm* item, XList_0075d6b0* extra, Node_0075d6b0* next);
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
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void FUN_3d0(XRef_0075d6b0* ref, bool a2, bool a3);
    Entry_0075d6b0* FUN_00968be0(SourceForm* item, XList_0075d6b0* extra, int count, bool a4);
    void FUN_009687b0(SourceForm* item, XList_0075d6b0* extra, int count);
};
struct List_0075d6b0
{
    void FUN_005ae3d0(SourceForm* const& item);
};
int __cdecl MinInt(int a, int b);
void __cdecl FUN_009bd5c0(CurrentItem* item, Ref_0075d6b0* to, Ref_0075d6b0* from, SourceForm* form);
struct Menu_0075d6b0 : ContainerMenu
{
    bool FUN_0075d510(Entry_0075d6b0* entry, Ref_0075d6b0* to, Ref_0075d6b0* from);
    void TransferItem(void* a1, Entry_0075d6b0* entry, int count);
};
// Moves count of an entry's item between the container's two references, handling the special container and splitting stacks when needed.
// @fnv 0x0075d6b0
void Menu_0075d6b0::TransferItem(void* a1, Entry_0075d6b0* entry, int count)
{
    if (!entry || !a1)
        return;
    Ref_0075d6b0* from4 = (*(char**)((char*)this + 0xf8) == (char*)this + 0x98) ? (Ref_0075d6b0*)m_pContainer
                                                                                : (Ref_0075d6b0*)DAT_011dea3c;
    Ref_0075d6b0* to8 = (*(char**)((char*)this + 0xf8) == (char*)this + 0x98) ? (Ref_0075d6b0*)DAT_011dea3c
                                                                              : (Ref_0075d6b0*)m_pContainer;
    bool ok = FUN_0075d510(entry, to8, from4);
    XList_0075d6b0* extra = entry->FUN_00559450() ? *entry->FUN_00559450()->FUN_006815c0() : 0;
    if (ok)
    {
        FUN_009bd5c0(entry->FUN_0044ddc0()->GetOrFallback(0), to8, from4, entry->FUN_0044ddc0());
        ((List_0075d6b0*)&m_kContainerItems)->FUN_005ae3d0(entry->FUN_0044ddc0());
        to8->FUN_17c(entry->FUN_0044ddc0(), extra, count, 0, 0, 0, 0, 0, 1, 0);
        return;
    }
    if (extra && extra->FUN_0041de00() && !extra->FUN_0041de00()->FUN_00440da0() &&
        !extra->FUN_0041de00()->FUN_00440d80())
    {
        ((Ref_0075d6b0*)DAT_011dea3c)->FUN_3d0(extra->FUN_0041de00(), 1, 0);
        return;
    }
    if (m_eContainerMenuMode == 4)
    {
        int remaining = count;
        Node_0075d6b0* nodeB = entry->FUN_00559450();
        while (remaining > 0)
        {
            XList_0075d6b0* x4 = nodeB ? *nodeB->FUN_006815c0() : 0;
            int n7 = x4 ? x4->FUN_00418770() : remaining;
            n7 = MinInt(n7, remaining);
            if (from4 == (Ref_0075d6b0*)DAT_011dea3c)
            {
                Entry_0075d6b0* movedB = ((Ref_0075d6b0*)DAT_011dea3c)->FUN_00968be0(entry->FUN_0044ddc0(), x4, n7, 1);
                ((Ref_0075d6b0*)DAT_011dea3c)
                    ->FUN_190(movedB->FUN_0044ddc0(),
                              movedB->FUN_00559450() ? *movedB->FUN_00559450()->FUN_006815c0() : 0,
                              movedB->FUN_00726070());
                delete movedB;
                nodeB = entry->FUN_00559450();
            }
            else if (to8 == (Ref_0075d6b0*)DAT_011dea3c)
            {
                ((Ref_0075d6b0*)DAT_011dea3c)->FUN_009687b0(entry->FUN_0044ddc0(), x4, n7);
                to8->FUN_17c(entry->FUN_0044ddc0(), x4, n7, 0, 0, 0, 0, 0, 1, 0);
                nodeB = nodeB ? nodeB->FUN_00726070() : 0;
            }
            remaining -= n7;
        }
        return;
    }
    to8->FUN_17c(entry->FUN_0044ddc0(), extra, count, m_eContainerMenuMode == 2, 0, from4, 0, 0, 1, 0);
}

namespace fnv_0075e0b0 {
struct AV_75e0b0
{
    virtual void v0();
    virtual void v4();
    virtual int GetValue(int);
    virtual float GetFloat(int);
    int FUN_0066ef20(int);
};
struct Base_75e0b0
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
    AV_75e0b0 av;
};
struct Actor_75e0b0
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual bool IsDead();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void UpdateSkill(int, int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    AV_75e0b0 av;
    void FUN_008c00e0(Actor_75e0b0*, int, int);
    Base_75e0b0* FUN_004181e0();
    void FUN_0094fd30(int);
};
extern Actor_75e0b0* DAT_011dea3c;
struct Random_75e0b0
{
    unsigned int FUN_00aa5230();
};
Random_75e0b0* __stdcall FUN_00476c00(int);
int __cdecl ComputeClampedSettingSum(int, int, float);
void __cdecl FUN_004d5c60(int);
struct Setting_75e0b0
{
    const char* FUN_00403df0();
    float* FUN_00403e20();
};
extern Setting_75e0b0 DAT_011d3f94;
extern Setting_75e0b0 DAT_011cde20;
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
unsigned int __cdecl FUN_0047e040(float);
struct FUN_0075e0b0_shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    bool warned;
    bool failed;
    char unk8a;
    char unk8b;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int embedded;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int* active;
    bool FUN_0075e0b0(Actor_75e0b0* actor, int amount);
};
// @fnv 0x0075e0b0
bool FUN_0075e0b0_shell::FUN_0075e0b0(Actor_75e0b0* actor, int amount)
{
    bool success = true;
    if (actor && amount > 0 && !actor->IsDead())
    {
        int chance = ComputeClampedSettingSum(DAT_011dea3c->av.FUN_0066ef20(42), actor->av.GetValue(42), (float)amount);
        DAT_011dea3c->UpdateSkill(42, 1);
        if (FUN_00476c00(100)->FUN_00aa5230() < (unsigned int)chance)
        {
            if (active == &embedded && !warned)
            {
                FUN_004d5c60(13);
                warned = true;
            }
        }
        else
        {
            DAT_011dea3c->FUN_008c00e0(actor, 0, 0);
            DispatchMessageToSink(DAT_011d3f94.FUN_00403df0(), 2, 0, 0, 2.0f, false);
            success = false;
            failed = true;
        }
        actor->FUN_004181e0();
        unsigned int type = FUN_0047e040(actor->FUN_004181e0()->av.GetFloat(23));
        if (type != 2 && type != 4)
        {
            DAT_011dea3c->FUN_0094fd30((int)*DAT_011cde20.FUN_00403e20());
        }
    }
    return success;
}
}  // namespace fnv_0075e0b0

struct TrimGlyph
{
    int texture;
    float uv[8];
    float width, height, leading, spacing, top;
};
struct TrimFontData
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
    TrimGlyph letters[256];
};
struct TrimFont
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    TrimFontData* data;
};
struct TrimManager
{
    void GetStringDimensions(float*, const char*, int, float, int);
    TrimFont* FUN_005bd5c0(int);
};
TrimManager* FUN_005bd5b0();
struct TrimTile
{
    float FUN_00a011b0(int);
    bool IsTraitNonZero(int);
    void FUN_00a01350(int, const char*, bool);
    TrimTile* FUN_0045cd60();
};
extern float DAT_01016970;
extern double DAT_01072310, DAT_010356b0, DAT_01021928;
void* FUN_00403d30(void*, int, unsigned int);
int FUN_00406d50(char*, unsigned int, const char*);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct TrimMenu
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    TrimTile* root;
    TrimTile* label;
    void SetLabelText(const char*);
};
// @fnv 0x0075e8c0
void TrimMenu::SetLabelText(const char* text)
{
    if (!text || !text[0])
        return;
    int font8 = (int)label->FUN_00a011b0(4025);
    float dimensions9[3];
    FUN_005bd5b0()->GetStringDimensions(dimensions9, text, font8, DAT_01016970, 0);
    float widthTmp = label->FUN_0045cd60()->FUN_00a011b0(4017) - DAT_01072310;
    if (root->IsTraitNonZero(4003))
        widthTmp -= DAT_010356b0;
    if (dimensions9[0] > widthTmp)
    {
        char* buffer = new char[260];
        TrimGlyph* letters = FUN_005bd5b0()->FUN_005bd5c0(font8 - 1)->data->letters;
        float total2 = 0.0f;
        int index = 0;
        FUN_00403d30(buffer, 0, 260);
        total2 += (letters[46].leading + letters[46].width + letters[46].spacing) * DAT_01021928;
        while (total2 <= widthTmp && index < 260)
        {
            buffer[index] = text[index];
            total2 += letters[text[index]].leading + letters[text[index]].width + letters[text[index]].spacing;
            index++;
        }
        FUN_00406d50(buffer, 260, "...");
        label->FUN_00a01350(4036, buffer, true);
        delete[] buffer;
    }
    else
        label->FUN_00a01350(4036, text, true);
}

extern const char str_010721f4[];
extern const char DAT_01011584[];
extern unsigned char DAT_011a002c;
extern void* DAT_011d93fc;

struct ContainerMenu;

unsigned __cdecl FUN_00457fe0();
void* __cdecl FUN_00a08b20(void* obj, const char* name);
unsigned __fastcall GetRaceCount(char* buf);
void* __fastcall FUN_0044ddc0(void* obj);
int __fastcall FUN_00401170(void* obj);
void __cdecl UpdateAnimationTileFade(int a, int b, int c, void* d, int e);

struct MenuObj
{
    void* FUN_00726070();
};

struct TileObj
{
    void FUN_00a01350(int id, const char* value, bool flag);
};

struct RefObj
{
    float FUN_004be180();
    float FUN_004be060();
};

struct Cls75eac0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    char m_c8[52];
    int m_fc;
    void Update();
};

extern ContainerMenu* DAT_011d93f8;

// @fnv 0x0075eac0
void Cls75eac0::Update()
{
    if (m_fc != 0 && FUN_00457fe0() > (unsigned int)m_fc)
    {
        m_fc = 0;
        TileObj* tile = (TileObj*)FUN_00a08b20(((MenuObj*)DAT_011d93f8)->FUN_00726070(), str_010721f4);
        if (tile != 0)
        {
            tile->FUN_00a01350(0xfc4, DAT_01011584, true);
        }
    }
    if (GetRaceCount(m_c8) > 0 && DAT_011a002c != 0)
    {
        if (DAT_011d93fc != 0 && FUN_00401170(FUN_0044ddc0(DAT_011d93fc)) == 0x28)
        {
            UpdateAnimationTileFade(m_60, m_64, m_68, DAT_011d93fc, 0);
        }
        else if (DAT_011d93fc != 0 && FUN_00401170(FUN_0044ddc0(DAT_011d93fc)) == 0x18)
        {
            UpdateAnimationTileFade(
                (DAT_011d93fc != 0 && ((RefObj*)FUN_0044ddc0(DAT_011d93fc))->FUN_004be060() != 0.0) ? m_6c : 0,
                (DAT_011d93fc != 0 && ((RefObj*)FUN_0044ddc0(DAT_011d93fc))->FUN_004be180() != 0.0) ? m_70 : 0, 0,
                DAT_011d93fc, 0);
        }
    }
}

extern int DAT_0106ff84;
void* __cdecl FUN_00403d30(void*, int, unsigned int);
struct Base0071
{
    Base0071();
    ~Base0071();
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct FUN_0071f240 : Base0071
{
    unsigned int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned int unk48, unk4c, unk50;
    FUN_0071f240();
};
// Sets the vtable, zeroes the 0x20-byte block at unk28, and clears unk4c, unk48 and unk50.
// @fnv 0x0071f240
FUN_0071f240::FUN_0071f240()
{
    vtable = &DAT_0106ff84;
    FUN_00403d30(&unk28, 0, 0x20);
    unk4c = 0;
    unk48 = 0;
    unk50 = 0;
}

// 0x0075cd70  unit_5a9677af71cd.cpp  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall, 2 stack args (ret 8): optional tile lookup, then a switch over the
// tile id (0x14..0x16) driving two mutually exclusive state objects, then the
// shared refresh path that re-inits the visible tile texts.
extern "C" unsigned char DAT_011a002c;
extern "C" void* DAT_011d93fc;

class HighProcess
{
  public:
    int GetProcessLevel();
};

struct TileInt75
{
    void FUN_00700320(int id, int value);
};
struct TileStr75
{
    void FUN_00a01350(int id, const char* value, bool flag);
};
struct StateObj75
{
    void* FUN_007a1910();
};
struct RetObj75
{
    const char* GetIconFilename(int arg);
};

void __cdecl FUN_00707e30(void* a, void* b);

struct Emb75
{
    virtual void v00(int flags);
};

struct Menu75
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(int a, int b);
    virtual void v14(int a, int b);

    char pad00[0x24];
    void* tiles28[4];
    int i38;
    char pad3c[0x48 - 0x3c];
    int i48;
    void* p4c;
    char pad50[0x58 - 0x50];
    void* p58;
    void* p5c;
    char pad60[0x98 - 0x60];
    Emb75 a98;
    char pad9c[0xc8 - 0x9c];
    Emb75 b0;
    char padcc[0xf8 - 0xcc];
    void* state;

    void UpdateProcessTile(int idx, HighProcess* proc);
};

// Handles tile index 0x14-0x16: switches the active state between a98 and b0, updates tiles from the state object, and sets DAT_011a002c.
// @fnv 0x0075cd70
void Menu75::UpdateProcessTile(int iTileIndex, HighProcess* pProcess)
{
    if (pProcess == 0 && iTileIndex >= 0 && iTileIndex < 0x13)
    {
        pProcess = (HighProcess*)tiles28[iTileIndex];
    }

    switch (iTileIndex)
    {
    case 0x15:
        v14(0x14, 0);
        b0.v00(0);
        state = &a98;
        break;
    case 0x16:
        v14(0x14, 0);
        a98.v00(0);
        state = &b0;
        break;
    case 0x14:
        if (pProcess)
        {
            DAT_011a002c = 1;
            if (state != &a98 && pProcess->GetProcessLevel() == i38)
            {
                v10(0x15, 0);
            }
            else
            {
                if (state != &b0 && pProcess->GetProcessLevel() == i48)
                {
                    v10(0x16, 0);
                }
            }
            DAT_011d93fc = ((StateObj75*)state)->FUN_007a1910();
            if (DAT_011d93fc)
            {
                FUN_00707e30(DAT_011d93fc, p5c);
                ((TileInt75*)p5c)->FUN_00700320(0xfa3, 1);
                ((TileStr75*)p58)->FUN_00a01350(0xfcc, ((RetObj75*)DAT_011d93fc)->GetIconFilename(0), 1);
                ((TileInt75*)p58)->FUN_00700320(0xfa3, 1);
                ((TileInt75*)p4c)->FUN_00700320(0x1004, (state != &a98) + 1);
                ((TileInt75*)p4c)->FUN_00700320(0xfa3, 1);
            }
        }
    }
}

// HandleContainerMenuActivate v1
extern void* DAT_011d93fc;
extern const char DAT_01012058[];
struct EntrySrc75
{
    void* FindItemData(void** pp);
};
struct FloatSrc75
{
    float FUN_00a011b0();
};
bool __fastcall FUN_004d1360(void* player);

float __cdecl FUN_0048ebc0(int a, bool b);
struct Sound75
{
    double FUN_00577250(int a);
};
struct StrThis75
{
    const char* FUN_00403df0();
};
extern StrThis75 g_011d2628;
struct Name75
{
    const char* FUN_0055d520();
};
struct Msg75
{
    static bool __cdecl DispatchMessageToSink(const char* msg, int a2, const char* a3, const char* a4, float a5,
                                              bool a6);
};

class TESTopic : public TESForm
{
  public:
    virtual ~TESTopic();
};
TESForm* __cdecl FUN_00483a00(void* a1);

extern char DAT_010722dc;
extern int DAT_01183028;
extern int DAT_01184720;
struct FloatThis75
{
    double FUN_008a0c20();
};
struct MenuEc75
{
    void PlaySelectedTopicInfo(int id);
};
struct Form75
{
    void* __thiscall GetExtraForm();
};
void* __fastcall FUN_007af430(void* p);
struct MenuE0B75
{
    bool __thiscall FUN_0075e0b0(void* refObj, int stolenDelta);
};
struct MenuD6B75
{
    void TransferItem(void* entry, void* fc, int param);
};
struct MenuC28B75
{
    void FUN_0075c280(int a);
};
struct PlayerAct75
{
    void PlayActorSound(void* a1, int a2, int a3);
};
struct ActorProc75
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual void vfn_00e8();
    virtual void vfn_00ec();
    virtual void vfn_00f0();
    virtual void vfn_00f4();
    virtual void vfn_00f8();
    virtual void vfn_00fc();
    virtual void vfn_0100();
    virtual void vfn_0104();
    virtual void vfn_0108();
    virtual void vfn_010c();
    virtual void vfn_0110();
    virtual void vfn_0114();
    virtual void vfn_0118();
    virtual void vfn_011c();
    virtual void vfn_0120();
    virtual void vfn_0124();
    virtual void vfn_0128();
    virtual void vfn_012c();
    virtual void vfn_0130();
    virtual void vfn_0134();
    virtual void vfn_0138();
    virtual void vfn_013c();
    virtual void vfn_0140();
    virtual void vfn_0144();
    virtual void vfn_0148();
    virtual void* vfn_014c();
    virtual void vfn_0150();
    virtual void vfn_0154();
    virtual void vfn_0158();
    virtual void vfn_015c();
    virtual void vfn_0160();
    virtual void vfn_0164();
    virtual void vfn_0168(int);
};
struct ProcGet75
{
    ActorProc75* FUN_008d8520();
};
struct Inv75
{
    static Inv75* __cdecl FUN_004bf220(void* refr);
    int FUN_004c8f30(void* form);
};

// @fnv 0x0075dc80
void __cdecl HandleContainerMenuActivate(int aiCount)
{
    void* expected;
    void* refObj;
    void* entry;
    {
        bool flag;
        {
            char msgtext[260];
            entry = ((EntrySrc75*)*(void**)&DAT_011d93f8->otherData[0x70])->FindItemData(&DAT_011d93fc);
            refObj = (DAT_011d93f8->m_pContainer && ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor())
                         ? (void*)DAT_011d93f8->m_pContainer
                         : 0;
            flag = false;
            expected = (*(void**)&DAT_011d93f8->otherData[0x70] == (void*)&DAT_011d93f8->otherData[0x10])
                           ? (void*)DAT_011dea3c
                           : (void*)DAT_011d93f8->m_pContainer;
            if (aiCount == 0 || DAT_011d93fc == 0 || entry == 0)
                flag = true;
            if (((FloatSrc75*)*(void**)((ContainerLikeObj*)((int*)entry + 1))->FUN_007b5370(4009))->FUN_00a011b0() ==
                128.0)
                flag = true;
            if (DAT_011d93f8->m_eContainerMenuMode == 3 &&
                *(void**)&DAT_011d93f8->otherData[0x70] == (void*)&DAT_011d93f8->otherData[0x10] && refObj != 0)
            {
                if (((Sound75*)refObj)->FUN_00577250(0) +
                        FUN_0048ebc0((int)FUN_0044ddc0(DAT_011d93fc), FUN_004d1360((void*)DAT_011dea3c)) * aiCount >=
                    ((FloatThis75*)refObj)->FUN_008a0c20())
                {
                    FUN_00406d00(msgtext, 260, DAT_01012058, (char*)((Name75*)refObj)->FUN_0055d520(),
                                 (int)g_011d2628.FUN_00403df0());
                    Msg75::DispatchMessageToSink(msgtext, 2, 0, 0, 2.0f, false);
                    flag = true;
                    int id = (int)dynamic_cast<TESTopic*>(FUN_00483a00(&DAT_010722dc));
                    ((MenuEc75*)DAT_011d93f8)->PlaySelectedTopicInfo(id);
                }
            }
        }
        if (DAT_011d93f8 != 0 && DAT_011d93f8->m_eContainerMenuMode == 2)
        {
            if ((expected == (void*)DAT_011dea3c && refObj != 0) ||
                (expected != (void*)DAT_011dea3c &&
                 ((Form75*)DAT_011d93fc)->GetExtraForm() != FUN_007af430((void*)DAT_011dea3c)))
            {
                int stolenDelta;
                bool isC8 = (*(void**)&DAT_011d93f8->otherData[0x70] == (void*)&DAT_011d93f8->otherData[0x40]);
                stolenDelta =
                    ((ContainerValue*)DAT_011d93f8)->GetContainerValue((ItemEntry*)DAT_011d93fc, aiCount, isC8) *
                    (isC8 ? 1 : -1);
                DAT_011d93f8->m_iStolenItemCount += stolenDelta;
                if (!isC8)
                    stolenDelta = 1;
                if (refObj != 0)
                {
                    if (!((MenuE0B75*)DAT_011d93f8)->FUN_0075e0b0(refObj, stolenDelta))
                    {
                        flag = true;
                        ContainerMenu::Close();
                    }
                }
            }
        }
        if (!flag)
        {
            void* processBaseObject;
            void* pCachedForm = (void*)FUN_0044ddc0(DAT_011d93fc);
            processBaseObject = ((ProcGet75*)DAT_011dea3c)->FUN_008d8520()->vfn_014c();
            ((PlayerAct75*)DAT_011dea3c)->PlayActorSound(pCachedForm, 1, 0);
            ((MenuD6B75*)DAT_011d93f8)->TransferItem(entry, DAT_011d93fc, aiCount);
            ((MenuC28B75*)DAT_011d93f8)->FUN_0075c280((int)pCachedForm);
            if (processBaseObject != 0)
            {
                if (Inv75::FUN_004bf220((void*)DAT_011dea3c)->FUN_004c8f30((void*)FUN_0044ddc0(processBaseObject)) == 0)
                {
                    ((ProcGet75*)DAT_011dea3c)->FUN_008d8520()->vfn_0168(0);
                }
            }
        }
    }
}

struct S650Form
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
    virtual unsigned char v37();
    int FUN_00401170();
    unsigned char FUN_004c94d0();
};
struct S650Ref
{
    S650Form* FUN_0044ddc0();
    bool FUN_004bddd0(bool);
};
struct S650List
{
    void* FindItemData(S650Ref**);
};
struct S650Group
{
    int GetConditionIndex(S650Form*);
};
S650Group* __cdecl FUN_00483a00(char*);
extern "C" char DAT_010722f4;
extern "C" char DAT_011D93F8;
struct S650Global
{
    char pad[0x80];
    int mode;
    int unk84;
    int unk88;
    int first;
    int second;
    int unk94;
    S650List list1;
    char pad99[0xc8 - 0x99];
    S650List list2;
};
struct S650
{
    static bool FUN_0075e650(S650Ref* arg);
};
// Looks up the ref in list1/list2, applies a type-based filter switch, then adds group, form and mode checks to return whether the ref passes.
// @fnv 0x0075e650
bool S650::FUN_0075e650(S650Ref* pRef)
{
    bool result2 = false;
    int type6 = pRef->FUN_0044ddc0()->FUN_00401170();
    void* found8 = (*(S650Global**)&DAT_011D93F8)->list1.FindItemData(&pRef);
    int filterVal = 0;
    bool firstB = true;
    if (found8)
    {
        filterVal = (*(S650Global**)&DAT_011D93F8)->first;
    }
    else
    {
        found8 = (*(S650Global**)&DAT_011D93F8)->list2.FindItemData(&pRef);
        filterVal = (*(S650Global**)&DAT_011D93F8)->second;
        firstB = false;
    }
    switch (filterVal)
    {
        break;
    case 1:
        result2 = type6 != 0x28;
        break;
    case 2:
        result2 = type6 != 0x18 && type6 != 0x1a;
        break;
    case 3:
        result2 = type6 != 0x1d && type6 != 0x2f && type6 != 0x19;
        break;
    case 4:
        result2 = type6 == 0x28 || type6 == 0x18 || type6 == 0x1a || type6 == 0x1d || type6 == 0x2f || type6 == 0x29 ||
                  type6 == 0x19 || type6 == 0x6c || type6 == 0x73 || type6 == 0x74;
        break;
    case 5:
        result2 = type6 != 0x29;
    }
    if (type6 == 0x29)
    {
        S650Group* group = FUN_00483a00(&DAT_010722f4);
        S650Form* form = pRef->FUN_0044ddc0();
        if (group && group->GetConditionIndex(form) >= 0)
            result2 = true;
        if (form && !form->FUN_004c94d0())
            result2 = true;
    }
    if (firstB)
    {
        result2 = result2 || type6 == 0x2e || pRef->FUN_0044ddc0()->v37();
    }
    else if ((*(S650Global**)&DAT_011D93F8)->mode == 2)
    {
        result2 = result2 || pRef->FUN_004bddd0(false);
    }
    return result2;
}

class PlaybackString
{
  public:
    char* text;
    unsigned short length;
    unsigned short capacity;
    PlaybackString(const PlaybackString&);
    ~PlaybackString();
    unsigned GetLength() const;
    const char* GetString() const;
};
class PlaybackHandle
{
  public:
    unsigned soundID;
    bool assumeSuccess;
    unsigned state;
    PlaybackHandle(const PlaybackHandle&);
    ~PlaybackHandle();
    PlaybackHandle& operator=(const PlaybackHandle&);
};
class PlaybackSound : public TESSound
{
  public:
    unsigned FUN_0084e3a0();
};
class PlaybackResponse
{
  public:
    PlaybackSound* GetSoundByEditorID();
    unsigned GetSoundID();
    PlaybackString* GetText();
    unsigned GetEmotion();
    unsigned GetEmotionValue();
    unsigned GetFlags();
    PlaybackString* GetVoiceFilePath();
};
class PlaybackActor : public Actor
{
  public:
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
    virtual void slot048();
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
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual float PlayVoice(const char*, PlaybackHandle*, unsigned, unsigned, unsigned, unsigned, unsigned,
                            ExpectedReference*, bool, bool, unsigned, unsigned, bool);
    PlaybackHandle GetActorSoundHandle(unsigned, unsigned, unsigned, bool);
};
class PlaybackTopicInfo
{
  public:
    void* GetQuest();
};
class PlaybackTopic
{
  public:
    PlaybackTopicInfo* SelectInfo(Actor*, ExpectedReference*);
};
class PlaybackDialogue
{
  public:
    void* quest;
    PlaybackTopic* topic;
    PlaybackTopicInfo* info;
    TESObjectREFR* speaker;
    void* responses;
    void* current;
    unsigned flags;
    PlaybackDialogue(void*, PlaybackTopic*, PlaybackTopicInfo*, Actor*);
    ~PlaybackDialogue();
    void Begin();
    PlaybackResponse* GetCurrentItem();
};
class PlaybackMenu : public ContainerMenu
{
  public:
    void PlaySelectedTopicInfo(PlaybackTopic* topic);
    void ShowMessageWithSound(PlaybackString, PlaybackHandle);
};
// Selects a topic info for the current actor, begins a dialogue, and plays the current response's sound or voice, then updates the menu.
// @fnv 0x0075ec60
void PlaybackMenu::PlaySelectedTopicInfo(PlaybackTopic* topic)
{
    PlaybackTopicInfo* _item = 0;
    ExpectedReference* _context = DAT_011dea3c;
    Actor* _actor = DAT_011d93f8->m_pContainer && reinterpret_cast<ActorView*>(DAT_011d93f8->m_pContainer)->IsActor()
                        ? dynamic_cast<Actor*>(DAT_011d93f8->m_pContainer)
                        : 0;
    if (topic)
        _item = topic->SelectInfo(_actor, _context);
    if (_item)
    {
        PlaybackDialogue _data(_item->GetQuest(), topic, _item, _actor);
        _data.Begin();
        PlaybackResponse* _entry = _data.GetCurrentItem();
        if (_entry)
        {
            if (_entry->GetSoundByEditorID())
            {
                unsigned soundID = _entry->GetSoundByEditorID()->FUN_0084e3a0();
                reinterpret_cast<PlaybackHandle&>(m_kFadeSequence) =
                    reinterpret_cast<PlaybackActor*>(_actor)->GetActorSoundHandle(soundID, 0, 0x102, true);
            }
            else
            {
                float duration = reinterpret_cast<PlaybackActor*>(_actor)->PlayVoice(
                    _entry->GetVoiceFilePath()->GetString(), reinterpret_cast<PlaybackHandle*>(&m_kFadeSequence),
                    _entry->GetFlags(), _entry->GetSoundID(), _entry->GetText()->GetLength(), _entry->GetEmotion(),
                    _entry->GetEmotionValue(), DAT_011dea3c, true, true, 0, 0, true);
            }
            ShowMessageWithSound(*_entry->GetText(), reinterpret_cast<PlaybackHandle&>(m_kFadeSequence));
        }
    }
}

struct StrMem
{
    char* data;
    unsigned short length, capacity;
    ~StrMem();
    unsigned int FUN_004048e0();
    const char* FUN_00559450();
};
// Native twelve-byte audio handle; its empty but nontrivial destructor is
// retained for the by-value parameter's genuine cleanup contract.
struct BSSoundHandleEx
{
    unsigned int soundID;
    bool assumeSuccess;
    unsigned char unk05, unk06, unk07;
    unsigned int state;
    ~BSSoundHandleEx();
    int FUN_00ad8b30();
};
struct BoolSetting539
{
    bool* FUN_00408d60();
};
struct FloatSetting539
{
    float* FUN_00403e20();
};
extern BoolSetting539 DAT_011d8928;
extern FloatSetting539 DAT_011d2178;
extern const char DAT_010721f4[];
extern "C" unsigned int __cdecl strlen(const char*);
unsigned int __cdecl FUN_00457fe0();
struct ActorAccess539
{
    bool FUN_008c1bc0();
};
struct MenuRoot539
{
    void* FUN_00726070();
};
struct TextTile539
{
    void FUN_00a01350(int, const char*, bool);
};
struct MenuDeadline539
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
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int deadline;
    void ShowMessageWithSound(StrMem message, BSSoundHandleEx sound);
};
// @fnv 0x0075eea0
void MenuDeadline539::ShowMessageWithSound(StrMem strMessage, BSSoundHandleEx soundHandle)
{
    float duration3 = 0.0f;
    Actor* actor = (DAT_011d93f8->m_pContainer && ((CloseVirtualSlots*)DAT_011d93f8->m_pContainer)->IsActor())
                       ? dynamic_cast<Actor*>(DAT_011d93f8->m_pContainer)
                       : 0;
    if (strMessage.FUN_004048e0() > 0 &&
        (*DAT_011d8928.FUN_00408d60() || (actor && ((ActorAccess539*)actor)->FUN_008c1bc0())))
    {
        TextTile539* tile = (TextTile539*)FUN_00a08b20(((MenuRoot539*)DAT_011d93f8)->FUN_00726070(), DAT_010721f4);
        if (tile)
            tile->FUN_00a01350(0xfc4, strMessage.FUN_00559450(), true);
        duration3 = (float)soundHandle.FUN_00ad8b30();
        if (duration3 == 0.0)
            duration3 = strlen(strMessage.FUN_00559450()) * *DAT_011d2178.FUN_00403e20() * 1000.0;
        deadline = (unsigned int)(FUN_00457fe0() + duration3);
    }
}

struct xRef
{
    bool IsDisabled();
    bool IsDeleted();
};
struct xExtra
{
    xRef* GetRef();
};
struct xInner
{
    xExtra** First();
};
struct xItem
{
    xInner* Get();
    int GetCount();
    unsigned int GetFlags();
};
struct xVal
{
    float GetFloat();
};
struct xValMap
{
    xVal* const& Find(int i);
};
struct xTile
{
    int m_i0;
    xValMap m_kFormatEntries;
};
class xCont
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual bool IsActorX();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void AddItem(unsigned int a, void* b, int c, bool d, int e, void* f, int g, int h, int i, int j);
};
class xPlayer
{
  public:
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
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void Activate(void* pRef, int a, int b);
};
struct xMenu
{
    int m_aiPad[0x1d];
    xCont* m_pkCont;
    int m_aiPad2[2];
    int m_iMode;
    int m_iTotal;
    char m_acPad[1];
    bool m_bDone;
    int Transfer(xItem* pItem, int iCount, int a);
    bool Check(xCont* pCont, int iCount);
};
extern xMenu* xContMenu;
extern xPlayer* xThePlayer;

// Activates a valid referenced item; otherwise may transfer it, update menu state, and call AddItem.
// @fnv 0x0075da60
void FUN_0075da60(xTile* pTile, xItem* pItem)
{
    if (!pItem || !xContMenu || !pTile || xContMenu->m_bDone)
        return;
    xExtra* qfTOqo = 0;
    if (pItem->Get())
        qfTOqo = *pItem->Get()->First();
    if (qfTOqo && qfTOqo->GetRef() && !qfTOqo->GetRef()->IsDisabled() && !qfTOqo->GetRef()->IsDeleted())
    {
        xThePlayer->Activate(qfTOqo->GetRef(), 1, 0);
        return;
    }
    if (pTile->m_kFormatEntries.Find(0xfa9)->GetFloat() == 128.0)
        return;
    if (xContMenu->m_iMode == 2)
    {
        xCont* pActor = xContMenu->m_pkCont->IsActorX() ? xContMenu->m_pkCont : 0;
        int iTransferred = xContMenu->Transfer(pItem, pItem->GetCount(), 1);
        xContMenu->m_iTotal += iTransferred;
        xContMenu->m_bDone = !xContMenu->Check(pActor, iTransferred);
    }
    xContMenu->m_pkCont->AddItem(pItem->GetFlags(), pItem->Get() ? *pItem->Get()->First() : 0, pItem->GetCount(),
                                 xContMenu->m_iMode == 2, 0, xThePlayer, 0, 0, 1, 0);
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);

TESForm* FUN_00483a00(const char* pcName);
void FUN_00763ff0();
struct TileX
{
    void FUN_00700320(int m_uiSoundID, int iVal);
    void FUN_00a01350(int m_uiSoundID, int iVal);
};
struct RefX
{
    int FUN_0055d520();
};
struct MgrX
{
    void PlaySelectedTopicInfo(TESTopic* pkForm);
};
struct GlobX
{
    int FUN_00403df0(int i);
};
extern GlobX DAT_011d3c40;
struct SubX
{
    int FUN_00408da0();
};
struct PlayerX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SubX kSub;
};
struct HudX
{
    PlayerX* FUN_008a1710();
};
struct MenuX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    TileX* m28;
    TileX* m2c;
    TileX* m30;
    int unk34;
    int unk38;
    TileX* m3c;
    int unk40;
    TileX* m44;
    int unk48;
    int unk4c;
    TileX* m50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    RefX* m74;
    int unk78;
    int unk7c;
    int m80;
    void SetLabelText(int i);
    void FUN_0075baf0(RefX* pkRef, bool b);
    void FUN_0075bc80();
};
// Switches on m80 to update labels, play the trader sound and selected topic info, or set tile traits to zero.
// @fnv 0x0075bc80
void MenuX::FUN_0075bc80()
{
    switch (m80)
    {
    case 1:
    case 2:
        if (m74)
        {
            SetLabelText(m74->FUN_0055d520());
            FUN_0075baf0(m74, true);
        }
        break;
    case 3:
        if (m74)
        {
            SetLabelText(m74->FUN_0055d520());
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("DRSTraderOpen", 0x121).Play(false);
            FUN_00763ff0();
            TESTopic* pkForm = dynamic_cast<TESTopic*>(FUN_00483a00("FollowersTrade"));
            ((MgrX*)DAT_011d93f8)->PlaySelectedTopicInfo(pkForm);
        }
        m50->FUN_00700320(0xfa3, 0);
        break;
    case 4:
        m2c->FUN_00a01350(0xfc4, DAT_011d3c40.FUN_00403df0(1));
        if (((HudX*)DAT_011dea3c)->FUN_008a1710())
            SetLabelText(((HudX*)DAT_011dea3c)->FUN_008a1710()->kSub.FUN_00408da0());
        m50->FUN_00700320(0xfa3, 0);
        m28->FUN_00700320(0xfa3, 0);
        m30->FUN_00700320(0xfa3, 0);
        m3c->FUN_00700320(0xfa3, 0);
        m44->FUN_00700320(0xfa3, 0);
        break;
    }
}

struct SoundHandle75
{
    unsigned unk00;
    bool unk04;
    unsigned unk08;
    ~SoundHandle75();
    bool Play(bool);
};
struct Audio75
{
    SoundHandle75 GetSoundHandleByEditorID(const char*, unsigned);
};
Audio75* FUN_00453a70();
struct Item75
{
    void* FUN_0044ddc0();
    int FUN_00726070();
};
extern Item75* g_011d93fc;
extern unsigned char DAT_011a002c;
struct Player75
{
};
extern Player75* _g_thePlayer;
bool __fastcall FUN_004d1360(Player75*);
bool FUN_00481f10(void*);
double FUN_0048ebc0(void*, bool);
struct Setting75
{
    int* Int();
};
extern Setting75 g_011d2418;
void HandleContainerMenuActivate(int);
void CreateQuantityMenu(int, void (*)(int), int);
void FUN_0075da60(void*, void*);
void FUN_0075e650(void*, void*);
void FUN_00706f30(int);
struct List75
{
    virtual void reset(int);
    void FUN_007312e0();
    void FUN_007314c0(void (*)(void*, void*), int, int);
    void ApplyFilter(void (*)(void*, void*));
    unsigned FUN_0071ae60();
};
struct Menu_0075be80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    void* unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    List75 unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    List75 unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    List75* unkf8;
    bool FUN_0075d510(Item75*, Player75*, void*);
    void UpdatePaneTitle(int);
    static void FUN_0075b750();
    void FUN_0075be80(int, void*);
};
// Handles container menu activation by ID, cycling item lists or triggering take-all and quantity menu actions.
// @fnv 0x0075be80
void Menu_0075be80::FUN_0075be80(int aiActionId, void* tile)
{
    if (!tile && aiActionId >= 0 && aiActionId < 19)
        tile = ((void**)&unk28)[aiActionId];
    switch (aiActionId)
    {
    case 20:
        if (g_011d93fc)
        {
            DAT_011a002c = 0;
            bool take = (FUN_00481f10(g_011d93fc->FUN_0044ddc0()) ||
                         FUN_0048ebc0(g_011d93fc->FUN_0044ddc0(), FUN_004d1360(_g_thePlayer)) <= 0.0) &&
                        (unk80 == 1 || unk80 == 2) && unkf8 == &unkc8;
            if (g_011d93fc->FUN_00726070() > *g_011d2418.Int() && !FUN_0075d510(g_011d93fc, _g_thePlayer, unk74) &&
                !take)
            {
                unkf8->FUN_007312e0();
                unkf8->reset(0);
                CreateQuantityMenu(g_011d93fc->FUN_00726070(), HandleContainerMenuActivate, 0x7fffffff);
            }
            else if (take)
                HandleContainerMenuActivate(g_011d93fc->FUN_00726070());
            else
                HandleContainerMenuActivate(1);
        }
        break;
    case 10:
        unkc8.FUN_007314c0(FUN_0075da60, 0, 0x7fffffff);
        FUN_00453a70()->GetSoundHandleByEditorID("UIItemTakeAll", 0x121).Play(false);
        FUN_0075b750();
        break;
    case 11:
        FUN_0075b750();
        break;
    case 0:
    case 1:
    case 2:
        FUN_00706f30(unk94);
        do
        {
            unk8c += aiActionId == 0 ? -1 : 1;
            if (unk8c < 0)
                unk8c = 5;
            else if (unk8c > 5)
                unk8c = 0;
            UpdatePaneTitle(unk2c);
            unk98.ApplyFilter(FUN_0075e650);
        } while (!unk98.FUN_0071ae60() && unk8c != 0);
        break;
    case 5:
    case 6:
    case 7:
        FUN_00706f30(unk94);
        do
        {
            unk90 += aiActionId == 5 ? -1 : 1;
            if (unk90 < 0)
                unk90 = 5;
            else if (unk90 > 5)
                unk90 = 0;
            UpdatePaneTitle(unk40);
            unkc8.ApplyFilter(FUN_0075e650);
        } while (!unkc8.FUN_0071ae60() && unk90 != 0);
        break;
    }
}

struct CategoryNameReference
{
    const char* FUN_0055d520();
};
extern InventoryMenuSetting DAT_011c3cb4;
extern InventoryMenuSetting DAT_011d29b8, DAT_011d4d50, DAT_011d40b4, DAT_011d2acc, DAT_011d4918;
int __cdecl FUN_00406d30(char* buffer, unsigned int length, const char* source);
void __cdecl FUN_00730490(char* buffer, int length);
enum CategoryFilter
{
    FILTER_ALL = 0,
    FILTER_1 = 1,
    FILTER_2 = 2,
    FILTER_3 = 3,
    FILTER_4 = 4,
    FILTER_5 = 5
};
struct CategoryTitleMenu
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
    TileObj* leftPane;
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
    CategoryNameReference* container;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    CategoryFilter leftCategory;
    CategoryFilter rightCategory;
    void SetLabelText(const char* name);
    void UpdatePaneTitle(TileObj* pane);
};
// UI invariant: both category values are initialized to0 and their event writers
// wrap every increment/decrement into0..5 before calling this title updater.
// Every valid path that uses title below first initializes the real buffer.
// Sets pane title text from the selected category and calls FUN_00730490 when the setting equals "ENGLISH".
// @fnv 0x0075e380
void CategoryTitleMenu::UpdatePaneTitle(TileObj* pane)
{
    bool nonEnglish;
    CategoryFilter category5 = pane == leftPane ? leftCategory : rightCategory;
    nonEnglish = FUN_00408b20(DAT_011c3cb4.FUN_00403df0(), "ENGLISH") != 0;
    char title[260];
    if (!container || !pane)
        return;
    switch (category5)
    {
    case 0:
        if (pane == leftPane)
        {
            FUN_00406d30(title, 260, DAT_011d4378.FUN_00403df0());
            if (!nonEnglish)
                FUN_00730490(title, 260);
            pane->FUN_00a01350(0xfc4, title, true);
        }
        else
        {
            SetLabelText(container->FUN_0055d520());
        }
        break;
    case 1:
        FUN_00406d30(title, 260, DAT_011d29b8.FUN_00403df0());
        if (!nonEnglish)
            FUN_00730490(title, 260);
        break;
    case 2:
        FUN_00406d30(title, 260, DAT_011d4d50.FUN_00403df0());
        if (!nonEnglish)
            FUN_00730490(title, 260);
        break;
    case 3:
        FUN_00406d30(title, 260, DAT_011d40b4.FUN_00403df0());
        if (!nonEnglish)
            FUN_00730490(title, 260);
        break;
    case 4:
        FUN_00406d30(title, 260, DAT_011d2acc.FUN_00403df0());
        if (!nonEnglish)
            FUN_00730490(title, 260);
        break;
    case 5:
        FUN_00406d30(title, 260, DAT_011d4918.FUN_00403df0());
        if (!nonEnglish)
            FUN_00730490(title, 260);
        break;
    }
    if (category5)
        pane->FUN_00a01350(0xfc4, title, true);
}

namespace fnv_0075c280 {
struct MenuForm;
struct MenuReference;
struct MenuExtra;
struct FUN_00410360
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    FUN_00410360();
    void FUN_0041de40(MenuReference*);
    void FUN_00419970(float);
};
struct FUN_0096a2d0
{
    int unk00, unk04;
    FUN_0096a2d0();
    FUN_00410360** FUN_006815c0();
    void FUN_005ae3d0(FUN_00410360**);
};
struct FUN_004bc550
{
    FUN_0096a2d0* extra;
    int unk04, unk08;
    FUN_004bc550(TESBoundObject*, int);
    const char* GetTargetFullName();
    FUN_0096a2d0* FUN_00559450();
};
struct MenuInventory
{
    unsigned int FUN_0044ddc0();
    FUN_004bc550** FUN_006a7ad0(unsigned int);
};
struct MenuProcess
{
    MenuReference* FUN_0041df00();
};
struct MenuReference
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsDead(int);
    MenuInventory* FUN_0075cc70();
    MenuProcess* FUN_005d43c0();
    bool FUN_00437b90();
    MenuForm* FUN_007af430();
    float FUN_00568ad0();
    void GetTwoValues(float*, float*);
};
struct MenuForm
{
    int FUN_00401170();
    MenuForm* FUN_00525980(MenuReference*);
};
struct MenuTileValue
{
    void FUN_00a012d0(float, bool);
};
struct MenuTileHolder
{
    MenuTileValue** FUN_007b5370(int);
};
struct MenuEntry
{
    int unk00;
    MenuTileHolder tile;
};
struct MenuList
{
    virtual void slot0();
    virtual void* GetSelected();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void Clear();
    virtual void Sort(int (*)(FUN_00a011f0_shell**, FUN_00a011f0_shell**));
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    void FUN_007312e0();
    MenuEntry* FUN_0071a320(FUN_004bc550*, const char*, int, int);
    void PopulateInventoryList(MenuReference*, void (*)(), int, int, int, int);
    void FUN_007314c0(void (*)(), int, int);
    void ApplyFilter(void (*)());
    unsigned int FUN_0071ae60();
    void UpdateCurrentValueTile(int);
    void* CallVirtualZero(int);
};
struct MenuFormList
{
    int unk00, unk04;
    MenuForm** FUN_006815c0();
    MenuFormList* FUN_00726070();
};
struct InventoryMenu
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void Click(int, int);
    virtual void Select(int, int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    MenuReference* container;
    MenuFormList forms;
    int mode;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int selection;
    MenuList m_kList;
    MenuList otherList;
    MenuList* active;

    void AttachAndDeliver(MenuForm*, void*, MenuList*);
    void FUN_0075c280(MenuForm*);
};
struct StrMem
{
    char* text;
    unsigned short length, capacity;
    StrMem();
    ~StrMem();
    const char* FUN_00559450();
};
struct MenuSetting
{
    const char* FUN_00403df0();
};
extern MenuSetting DAT_011d3f70, DAT_011d1e60;
extern MenuReference* DAT_011dea3c;
extern const char DAT_01012058[], DAT_010722d0[];
extern float DAT_0101e704;
void IsRefBaseObjectUnplayable();
void FUN_0075d160();
void FUN_0075e650();
void* FUN_004bf220(MenuReference*);
void FUN_00406f60(StrMem*, const char*, ...);
int FUN_00406d00(char*, unsigned int, const char*, ...);
float FUN_004bd510(float, float);
int FUN_00406d90(float);
bool FUN_004b71d0();
struct MenuInput
{
    void FUN_00715860(void*, int);
};
MenuInput* FUN_004b7210();
struct MenuTile
{
    void FUN_00a01350(int, const char*, bool);
};
struct MenuRoot
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;

    MenuTile* tile;
};

// Populates m_kList and otherList with inventory items, applies filters and sorting, and updates the active list selection and weight/capacity display.
// @fnv 0x0075c280
void InventoryMenu::FUN_0075c280(MenuForm* filter)
{
    int unused4 = 0;
    float weight7, capacity4;
    char label5[64];
    if (active && active->GetSelected())
        active->FUN_007312e0();
    if (mode == 4)
    {
        MenuInventory* _inventory = DAT_011dea3c->FUN_0075cc70();
        otherList.Clear();
        for (unsigned int iA = 0; iA < _inventory->FUN_0044ddc0(); iA++)
            otherList.FUN_0071a320(*_inventory->FUN_006a7ad0(iA), (*_inventory->FUN_006a7ad0(iA))->GetTargetFullName(),
                                   0, 0);
        if (filter)
            AttachAndDeliver(filter, FUN_004bf220(DAT_011dea3c), &m_kList);
        else
            m_kList.PopulateInventoryList(DAT_011dea3c, IsRefBaseObjectUnplayable, 0, 0, 0, 0);
    }
    else if (filter)
    {
        void* playerInventory4 = FUN_004bf220(DAT_011dea3c);
        void* otherInventory = container ? FUN_004bf220(container) : 0;
        MenuForm* ammo4 = filter->FUN_00401170() == 40 ? filter->FUN_00525980(container->IsActor() ? container : 0) : 0;
        AttachAndDeliver(filter, playerInventory4, &m_kList);
        if (ammo4)
            AttachAndDeliver(ammo4, playerInventory4, &m_kList);
        if (mode == 3)
            otherList.PopulateInventoryList(container, IsRefBaseObjectUnplayable, 0, 0, 0, 0);
        else
        {
            AttachAndDeliver(filter, otherInventory, &otherList);
            if (ammo4)
                AttachAndDeliver(ammo4, otherInventory, &otherList);
        }
    }
    else
    {
        m_kList.PopulateInventoryList(DAT_011dea3c, IsRefBaseObjectUnplayable, 0, 0, 0, 0);
        otherList.PopulateInventoryList(container, IsRefBaseObjectUnplayable, 0, 0, 0, 0);
    }
    for (MenuFormList* node9 = &forms; node9 && *node9->FUN_006815c0(); node9 = node9->FUN_00726070())
    {
        if (!filter || filter == *node9->FUN_006815c0())
        {
            FUN_004bc550* entry2 = new FUN_004bc550((TESBoundObject*)*node9->FUN_006815c0(), 1);
            StrMem name;
            MenuEntry* tile2 = 0;
            FUN_00406f60(&name, DAT_01012058, DAT_011d3f70.FUN_00403df0(), entry2->GetTargetFullName());
            tile2 = otherList.FUN_0071a320(entry2, name.FUN_00559450(), 0, 0);
            (*tile2->tile.FUN_007b5370(0xfa9))->FUN_00a012d0(DAT_0101e704, true);
        }
    }
    if (container && container->IsActor() && container->IsDead(0))
    {
        MenuReference* weapon = container->FUN_005d43c0()->FUN_0041df00();
        if (weapon && !weapon->FUN_00437b90() && (!filter || filter == weapon->FUN_007af430()))
        {
            FUN_004bc550* weaponEntry = new FUN_004bc550((TESBoundObject*)weapon->FUN_007af430(), 1);
            MenuEntry* weaponTile3 = 0;
            weaponTile3 = otherList.FUN_0071a320(weaponEntry, weaponEntry->GetTargetFullName(), 0, 0);
            if (weaponEntry->FUN_00559450())
                weaponEntry->extra = new FUN_0096a2d0;
            if (!*weaponEntry->FUN_00559450()->FUN_006815c0())
            {
                FUN_00410360* extra6 = new FUN_00410360;
                weaponEntry->FUN_00559450()->FUN_005ae3d0(&extra6);
            }
            (*weaponEntry->FUN_00559450()->FUN_006815c0())->FUN_0041de40(weapon);
            (*weaponEntry->FUN_00559450()->FUN_006815c0())->FUN_00419970(weapon->FUN_00568ad0());
        }
    }
    m_kList.FUN_007314c0(FUN_0075d160, 0, 0x7fffffff);
    m_kList.ApplyFilter(FUN_0075e650);
    m_kList.Sort(FUN_0075d130);
    otherList.FUN_007314c0(FUN_0075d160, 0, 0x7fffffff);
    otherList.ApplyFilter(FUN_0075e650);
    otherList.Sort(FUN_0075d130);
    DAT_011dea3c->GetTwoValues(&weight7, &capacity4);
    FUN_00406d00(label5, 64, DAT_010722d0, DAT_011d1e60.FUN_00403df0(), FUN_00406d90(FUN_004bd510(weight7, 1.0f)),
                 FUN_00406d90(FUN_004bd510(capacity4, 1.0f)));
    ((MenuRoot*)DAT_011d93f8)->tile->FUN_00a01350(0xfc4, label5, true);
    if (!active && FUN_004b71d0())
        active = &otherList;
    if (active)
    {
        if (active->FUN_0071ae60() > 0)
            active->UpdateCurrentValueTile(1);
        else
        {
            selection = -1;
            Click(active == &m_kList ? 2 : 7, 0);
            selection = 3;
            if (active->FUN_0071ae60() > 0)
                active->UpdateCurrentValueTile(1);
            else
            {
                Select(active == &m_kList ? 22 : 21, 0);
                if (FUN_004b71d0())
                    FUN_004b7210()->FUN_00715860(active->CallVirtualZero(0xfc3), 1);
            }
        }
    }
}
}  // namespace fnv_0075c280

struct TESModelTextureSwap : TESBoundObject
{
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual char* GetSwapName();
};
struct ObjRef
{
    TESBoundObject* FUN_0044ddc0();
    void* FUN_00559450();
    int FUN_004459e0(int a1);
};
struct ObjRaw
{
    int* FUN_006815c0();
};
struct InvChg
{
    ObjRef* FindEntryWithExtraListType(int a1);
    void ClearExtraForSlot(ObjRef* b, int a2);
    void SetInventorySlotExtraData(ObjRef* p, int v, int a3);
};
struct Loader
{
    void FUN_0045a5e0(char* name);
    void* LoadModel(char* name, int a1, int a2, int a3, int a4, int a5);
};
struct PlayerObj
{
    void PlayActorSound(TESBoundObject* o, int a1, int a2);
};
extern Loader* DAT_011c3b3c;
InvChg* __cdecl FUN_004bf220(void* arg);
TESModelTextureSwap* __cdecl GetBipedModelTextureSwap(TESBoundObject* o, void* player);

struct ThiS
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    unsigned char f24;
    int f28;
    void FUN_007017b0();
    void FUN_007019e0(ObjRef* p1);
};

// Calls inventory change routines, passes texture swap names to loader routines, updates a player object, and clears a field.
// @fnv 0x007019e0
void ThiS::FUN_007019e0(ObjRef* apObjRef)
{
    InvChg* aX = FUN_004bf220(DAT_011dea3c);
    if (!(apObjRef != 0 && f24 != 0 && aX != 0))
        return;
    ObjRef* b = aX->FindEntryWithExtraListType(f28);
    int v4 = apObjRef->FUN_00559450() ? *(int*)((ObjRaw*)apObjRef->FUN_00559450())->FUN_006815c0() : 0;
    TESModelTextureSwap* c_;
    TESModelTextureSwap* d;
    if (b != 0)
    {
        aX->ClearExtraForSlot(b, f28);
        if (b->FUN_0044ddc0() != 0)
        {
            c_ = GetBipedModelTextureSwap(b->FUN_0044ddc0(), DAT_011dea3c);
            if (c_ == 0)
                c_ = dynamic_cast<TESModelTextureSwap*>(b->FUN_0044ddc0());
            if (c_ != 0)
                DAT_011c3b3c->FUN_0045a5e0(c_->GetSwapName());
        }
    }
    aX->SetInventorySlotExtraData(apObjRef, v4, f28);
    if (apObjRef->FUN_0044ddc0() != 0)
    {
        d = GetBipedModelTextureSwap(apObjRef->FUN_0044ddc0(), DAT_011dea3c);
        if (d == 0)
            d = dynamic_cast<TESModelTextureSwap*>(apObjRef->FUN_0044ddc0());
        if (d != 0)
            DAT_011c3b3c->LoadModel(d->GetSwapName(), 0, 1, 0, 0, 0);
    }
    FUN_007017b0();
    ((PlayerObj*)DAT_011dea3c)->PlayActorSound(apObjRef->FUN_0044ddc0(), 1, 0);
    f24 = 0;
    ObjRef* aRef = b;
    ObjRef* aCopyP = aRef;
    (void)(aCopyP ? aCopyP->FUN_004459e0(1) : 0);
}

void __cdecl _FUN_00755270(int);

struct CompanionWheelInventory : Menu
{
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
    TESObjectREFR* pCompanion;

    void PlayTopicResponse(TESTopic*);
    void RunTopicResultScripts(TESTopic*);
    void FUN_007568d0();
};
// Looks up the FollowersTrade topic and, when pCompanion is non-null, passes it to FUN_007573d0 and FUN_007575b0.
// @fnv 0x007568d0
void CompanionWheelInventory::FUN_007568d0()
{
    _FUN_00755270(1);
    TESTopic* topic = dynamic_cast<TESTopic*>(FUN_00483a00("FollowersTrade"));
    if (pCompanion != 0)
    {
        PlayTopicResponse(topic);
        RunTopicResultScripts(topic);
    }
}
