// fallout/ai/dialoguepackage.cpp: DialoguePackage, DelStandIn, This, DialoguePackageState (18 functions)

#include "dialoguepackage_decls.h"

// @fnv 0x004d52d0
BGSTerrainManager* LoadBGSTerrainManager(const NiPointer<NiNode>& apNode)
{
    return LoadBGSTerrainManager(reinterpret_cast<const char*>(apNode.operator->()));
}

// @fnv 0x009ee040
int __fastcall FUN_009ee040(char* pThis)
{
    return *(int*)(pThis + 0xb0);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x009edd50
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct BSBound;
struct Date
{
    char b[0x24];
    ~Date();
};
struct Q
{
    ~Q();
};
struct FUN_006708b0
{
    virtual void Dummy();
    char pad[0x7c];
    ~FUN_006708b0();
};
struct PC7d
{
    char pad[0x208];
    void* f208;
    BSBound* GetObjectBounds();
    void SetBoundingBox(BSBound*);
};
extern PC7d* g_thePlayer;
struct FUN_009edf40 : public FUN_006708b0
{
    Date d;
    Q* p;
    ~FUN_009edf40();
};
// @fnv 0x009edf40
FUN_009edf40::~FUN_009edf40()
{
    if (this == g_thePlayer->f208)
        g_thePlayer->f208 = 0;
    if ((void*)this == (void*)g_thePlayer->GetObjectBounds())
        g_thePlayer->SetBoundingBox(0);
    delete p;
}

struct FUN_009edd30_shell
{
    bool IsPointerMatch(const void* p);
};

// Returns whether p equals the pointer stored at offset 0xb0 of this object.
// @fnv 0x009edd30
bool FUN_009edd30_shell::IsPointerMatch(const void* apValue)
{
    return apValue == *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xb0);
}

struct FUN_009ef510_shell
{
    unsigned char GetByteAtBC();
};

// @fnv 0x009ef510
unsigned char FUN_009ef510_shell::GetByteAtBC()
{
    return ((unsigned char*)this)[0xbc];
}

struct FUN_008e95c0_shell
{
    unsigned char m_ucUnknownByte[0xbf];
    bool m_bFlag;
    bool __thiscall FUN_008e95c0();
};

// @fnv 0x008e95c0
bool __thiscall FUN_008e95c0_shell::FUN_008e95c0()
{
    return m_bFlag;
}

struct SL
{
    SL();
    int _a;
    int _b;
};
struct FUN_0083b830 : SL
{
    int _c;
    FUN_0083b830();
};
// Initializes the _c member to 0.
// @fnv 0x0083b830
FUN_0083b830::FUN_0083b830()
{
    _c = 0;
}

struct DialoguePackage : TESForm
{
    void CopyFromPackage(TESForm*);
    void FUN_009ee060(TESForm* apCopy);
};
// Calls CopyFromPackage on apCopy, then dynamic_casts apCopy to DialoguePackage and stores the result in pcopy.
// @fnv 0x009ee060
void DialoguePackage::FUN_009ee060(TESForm* apCopy)
{
    CopyFromPackage(apCopy);
    DialoguePackage* pSourcePackage = dynamic_cast<DialoguePackage*>(apCopy);
}

namespace fnv_009ef530 {
struct MobileObject
{
    void FUN_00934250();
};

struct FUN_009ef530_cls
{
    char pad[0x94];
    MobileObject* m_mobile;
    void FUN_009ef530();
};

// If m_mobile is set, calls FUN_00934250 on it.
// @fnv 0x009ef530
void FUN_009ef530_cls::FUN_009ef530()
{
    if (m_mobile)
        m_mobile->FUN_00934250();
}
}  // namespace fnv_009ef530

namespace fnv_009f01d0 {
class TESTopic;
class MobileObject;
class TESObjectREFR;
struct DialogueItem;
struct DialogueResponse;

struct FUN_006797c0_shell
{
    void FUN_006797c0(void* buf);
};

struct BGSSaveFormBuffer
{
    void SerializeFormData(void* form, int flags);
    void SaveData(void* data, int size, int flags);
};

struct Conversation_Stub
{
    void FUN_0083c270(BGSSaveFormBuffer* buf);
    short FUN_0083ba50(DialogueItem* item);
};

struct FUN_0083c900_shell
{
    short GetResponseIndex(DialogueResponse* response);
};

struct DialoguePackage
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009f01d0
void DialoguePackage::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    bool bhasConversation;

    ((FUN_006797c0_shell*)this)->FUN_006797c0(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData((*(MobileObject**)((char*)this + 0x94)), 0);
    apSaveGameBuffer->SerializeFormData((*(MobileObject**)((char*)this + 0xb0)), 0);
    apSaveGameBuffer->SerializeFormData((*(MobileObject**)((char*)this + 0xb4)), 0);
    apSaveGameBuffer->SerializeFormData((*(MobileObject**)((char*)this + 0xb8)), 0);
    apSaveGameBuffer->SerializeFormData((*(TESObjectREFR**)((char*)this + 0x9c)), 0);
    apSaveGameBuffer->SerializeFormData((*(TESTopic**)((char*)this + 0x8c)), 0);
    apSaveGameBuffer->SaveData(&(*(int*)((char*)this + 0x90)), 4, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0x98)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xbc)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xbd)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xbe)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xbf)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xc0)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xc1)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(int*)((char*)this + 0xc4)), 4, 0);
    apSaveGameBuffer->SaveData(&(*(int*)((char*)this + 0xc8)), 4, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xa0)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xcc)), 1, 0);
    apSaveGameBuffer->SaveData(&(*(char*)((char*)this + 0xc2)), 1, 0);
    bhasConversation = (*(Conversation_Stub**)((char*)this + 0xa4));
    apSaveGameBuffer->SaveData(&bhasConversation, 1, 0);
    if (bhasConversation)
    {
        short scurrentResponseIndex;
        short scurrentItemIndex;
        (*(Conversation_Stub**)((char*)this + 0xa4))->FUN_0083c270(apSaveGameBuffer);
        scurrentItemIndex =
            (*(DialogueItem**)((char*)this + 0xa8))
                ? (*(Conversation_Stub**)((char*)this + 0xa4))->FUN_0083ba50((*(DialogueItem**)((char*)this + 0xa8)))
                : -1;
        apSaveGameBuffer->SaveData(&scurrentItemIndex, 2, 0);
        scurrentResponseIndex = ((*(DialogueItem**)((char*)this + 0xa8)) && (*(DialogueResponse**)((char*)this + 0xac)))
                                    ? ((FUN_0083c900_shell*)(*(DialogueItem**)((char*)this + 0xa8)))
                                          ->GetResponseIndex((*(DialogueResponse**)((char*)this + 0xac)))
                                    : -1;
        apSaveGameBuffer->SaveData(&scurrentResponseIndex, 2, 0);
    }
}
}  // namespace fnv_009f01d0

namespace fnv_009ef560 {
struct TESSaveLoadGame
{
    bool FUN_00862110();
    void* GetHitSound();
};

struct SaveManager : public TESSaveLoadGame
{
    unsigned char FUN_008df040();
};

struct Saver
{
    unsigned short FUN_00678fd0();
};

struct Conversation
{
    unsigned short FUN_0083bb30();
};

struct DialoguePackage : public Saver
{
    unsigned char padding[0xa3];
    Conversation* m_pkConversation;

    unsigned short FUN_009ef560();
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct Interface
{
    static void __cdecl PrintDebugMessage(const char* format, int value1, unsigned int value2, const char* value3,
                                          unsigned int value4, int value5, const char* value6);

    static void __cdecl PrintDebugMessage(const char* format, int value1, int value2, const char* value3);
};

extern SaveManager* DAT_011de45c;
extern GlobalObject_0045cf30 g_011de4e8;

TESForm* _GetFormByNumericID(unsigned int formID);

// Accumulates the save size of the dialogue package from its saver, conversation and version-dependent fields, optionally logging the size and form details.
// @fnv 0x009ef560
unsigned short DialoguePackage::FUN_009ef560()
{
    unsigned short scurrentResponseIndex = 0;

    {
        unsigned short scurrentItemIndex;
        void* apSaveGameBuffer;
        TESForm* pForm;

        scurrentResponseIndex += Saver::FUN_00678fd0();
        scurrentItemIndex = scurrentResponseIndex;

        if (DAT_011de45c->FUN_00862110())
        {
            scurrentResponseIndex += 4;
            scurrentResponseIndex += 2;
        }

        scurrentResponseIndex += 4;

        if (DAT_011de45c->FUN_008df040() >= 0x6a)
        {
            scurrentResponseIndex += 1;
        }

        scurrentResponseIndex += 0x10;
        scurrentResponseIndex += 2;

        if (m_pkConversation)
        {
            scurrentResponseIndex += m_pkConversation->FUN_0083bb30();
            scurrentResponseIndex += 2;
            scurrentResponseIndex += 2;
        }

        if (*g_011de4e8.Bool())
        {
            apSaveGameBuffer = DAT_011de45c->GetHitSound();

            if (apSaveGameBuffer)
            {
                pForm = _GetFormByNumericID(*reinterpret_cast<unsigned int*>(apSaveGameBuffer));

                Interface::PrintDebugMessage(
                    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                    scurrentResponseIndex - scurrentItemIndex, *reinterpret_cast<unsigned int*>(apSaveGameBuffer),
                    pForm->GetName(),
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(apSaveGameBuffer) + 5), 0x1f4,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
            }
            else
            {
                Interface::PrintDebugMessage(
                    "GetSaveSize(): %-5i ending at line %i in file %s", scurrentResponseIndex - scurrentItemIndex,
                    0x1f4, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
            }
        }
    }

    return scurrentResponseIndex;
}
}  // namespace fnv_009ef560

namespace fnv_009f0740 {
struct FUN_00679a90_shell
{
    void DispatchToSubobjects(void*);
};

struct Conversation
{
    void FUN_0083c420(BGSLoadFormBuffer*);
};

struct DialoguePackage : public FUN_00679a90_shell
{
    unsigned char pad_0000[0x94];
    MobileObject* m_pkMobileObject;
    unsigned char pad_0098[4];
    TESObjectREFR* m_pkReference;
    unsigned char pad_00A0[4];
    Conversation* m_pkConversation;
    unsigned char pad_00A8[8];
    MobileObject* pActor;
    MobileObject* pTargetActor;
    MobileObject* m_pLinkedReference;

    void FUN_009f0740(BGSLoadFormBuffer*);
};

TESForm* _GetFormByNumericID(unsigned int);

// Calls the base loader, resolves the stored form IDs to MobileObject/TESObjectREFR pointers, then loads the Conversation if present.
// @fnv 0x009f0740
void DialoguePackage::FUN_009f0740(BGSLoadFormBuffer* apLoadGameBuffer)
{
    DispatchToSubobjects(apLoadGameBuffer);

    m_pkMobileObject =
        m_pkMobileObject
            ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(m_pkMobileObject)))
            : 0;

    pActor = pActor ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(pActor))) : 0;

    pTargetActor = pTargetActor
                       ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(pTargetActor)))
                       : 0;

    m_pLinkedReference =
        m_pLinkedReference
            ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(m_pLinkedReference)))
            : 0;

    m_pkReference =
        m_pkReference ? dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(m_pkReference)))
                      : 0;

    if (m_pkConversation)
    {
        m_pkConversation->FUN_0083c420(apLoadGameBuffer);
    }
}
}  // namespace fnv_009f0740

struct Obj114;
struct Handle114;
struct Vec114
{
    float x, y, z;
};
struct String114
{
    unsigned int data;
    unsigned int size;
    String114();            // 0x4037b0
    String114(String114*);  // 0x4047f0
    ~String114();           // 0x4037d0
    void FUN_00438470(String114*);
    void* FUN_00559450();
};
struct Handle114
{
    unsigned int a, b, c;
    Handle114(const Handle114&);  // 0x418900
    ~Handle114();                 // 0x483710
    void* FUN_00559450();
    Handle114& FUN_00ad7480();
    Handle114& FUN_00418900(const Handle114&);
    void FUN_00ad8be0(float, float);
    void SetPos(float, float, float);
    void SetNiNode(Obj114*);
    void FUN_00ad8870(int, int);
};
struct Obj114
{
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00c();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01c();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02c();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03c();
    virtual void virtual040();
    virtual void v44(Obj114*, int, int, int, int, int);
    virtual void virtual048();
    virtual void virtual04c();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05c();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06c();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07c();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08c();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09c();
    virtual void virtual0a0();
    virtual void virtual0a4();
    virtual void virtual0a8();
    virtual void virtual0ac();
    virtual void virtual0b0();
    virtual void virtual0b4();
    virtual void virtual0b8();
    virtual void virtual0bc();
    virtual void virtual0c0();
    virtual void virtual0c4();
    virtual void virtual0c8();
    virtual void virtual0cc();
    virtual void virtual0d0();
    virtual void virtual0d4();
    virtual void virtual0d8();
    virtual void virtual0dc();
    virtual void virtual0e0();
    virtual void virtual0e4();
    virtual void virtual0e8();
    virtual void virtual0ec();
    virtual void virtual0f0();
    virtual void virtual0f4();
    virtual void virtual0f8();
    virtual void virtual0fc();
    virtual bool v100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10c();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual bool v11c();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12c();
    virtual void virtual130();
    virtual void virtual134();
    virtual void virtual138();
    virtual void virtual13c();
    virtual void virtual140();
    virtual void virtual144();
    virtual void virtual148();
    virtual void virtual14c();
    virtual void virtual150();
    virtual void virtual154();
    virtual void virtual158();
    virtual void virtual15c();
    virtual void virtual160();
    virtual void virtual164();
    virtual void virtual168();
    virtual void virtual16c();
    virtual void virtual170();
    virtual void virtual174();
    virtual void virtual178();
    virtual void virtual17c();
    virtual void virtual180();
    virtual void virtual184();
    virtual void virtual188();
    virtual void virtual18c();
    virtual void virtual190();
    virtual void virtual194();
    virtual void virtual198();
    virtual void virtual19c();
    virtual void virtual1a0();
    virtual void virtual1a4();
    virtual void virtual1a8();
    virtual void virtual1ac();
    virtual void virtual1b0();
    virtual void virtual1b4();
    virtual void virtual1b8();
    virtual void virtual1bc();
    virtual void virtual1c0();
    virtual void virtual1c4();
    virtual void virtual1c8();
    virtual void virtual1cc();
    virtual Obj114* v1d0();
    virtual void virtual1d4();
    virtual void virtual1d8();
    virtual void virtual1dc();
    virtual void virtual1e0();
    virtual Obj114* v1e4();
    virtual void virtual1e8();
    virtual void virtual1ec();
    virtual void virtual1f0();
    virtual Vec114& v1f4();
    virtual void virtual1f8();
    virtual void virtual1fc();
    virtual void v200(int);
    virtual void virtual204();
    virtual void virtual208();
    virtual void virtual20c();
    virtual void virtual210();
    virtual void virtual214();
    virtual void virtual218();
    virtual void virtual21c();
    virtual void virtual220();
    virtual void virtual224();
    virtual void virtual228();
    virtual bool v22c(int);
    virtual void virtual230();
    virtual void virtual234();
    virtual void virtual238();
    virtual void virtual23c();
    virtual void virtual240();
    virtual void virtual244();
    virtual void virtual248();
    virtual void virtual24c();
    virtual void virtual250();
    virtual void virtual254();
    virtual void virtual258();
    virtual void virtual25c();
    virtual void virtual260();
    virtual void virtual264();
    virtual void virtual268();
    virtual void virtual26c();
    virtual void virtual270();
    virtual void virtual274();
    virtual void virtual278();
    virtual void virtual27c();
    virtual void virtual280();
    virtual float v284(void*, Handle114*, Obj114*, Obj114*, void*, Obj114*, Obj114*, Obj114*, int, int, int, int, int);
    virtual void virtual288();
    virtual void virtual28c();
    virtual void virtual290();
    virtual void virtual294();
    virtual void virtual298();
    virtual void virtual29c();
    virtual void virtual2a0();
    virtual void virtual2a4();
    virtual void virtual2a8();
    virtual void virtual2ac();
    virtual void virtual2b0();
    virtual void virtual2b4();
    virtual void virtual2b8();
    virtual void virtual2bc();
    virtual void virtual2c0();
    virtual void virtual2c4();
    virtual void virtual2c8();
    virtual void virtual2cc();
    virtual void virtual2d0();
    virtual void virtual2d4();
    virtual void virtual2d8();
    virtual void virtual2dc();
    virtual void virtual2e0();
    virtual void virtual2e4();
    virtual bool v2e8();
    virtual void virtual2ec();
    virtual void virtual2f0();
    virtual void virtual2f4();
    virtual void virtual2f8();
    virtual void virtual2fc();
    virtual void virtual300();
    virtual void virtual304();
    virtual void virtual308();
    virtual void virtual30c();
    virtual void virtual310();
    virtual void virtual314();
    virtual void virtual318();
    virtual void virtual31c();
    virtual void virtual320();
    virtual void virtual324();
    virtual void virtual328();
    virtual void virtual32c();
    virtual void virtual330();
    virtual void virtual334();
    virtual void virtual338();
    virtual void virtual33c();
    virtual void virtual340();
    virtual void virtual344();
    virtual void virtual348();
    virtual void virtual34c();
    virtual void virtual350();
    virtual void virtual354();
    virtual void virtual358();
    virtual void virtual35c();
    virtual void virtual360();
    virtual void virtual364();
    virtual void virtual368();
    virtual bool v36c();
    virtual void virtual370();
    virtual void v374(int);
    virtual bool v378();
    virtual int v37c();
    virtual void v380(int);
    virtual void virtual384();
    virtual void virtual388();
    virtual void virtual38c();
    virtual void virtual390();
    virtual void virtual394();
    virtual void virtual398();
    virtual void virtual39c();
    virtual void virtual3a0();
    virtual void virtual3a4();
    virtual void virtual3a8();
    virtual void virtual3ac();
    virtual void virtual3b0();
    virtual void virtual3b4();
    virtual void virtual3b8();
    virtual void virtual3bc();
    virtual void virtual3c0();
    virtual void virtual3c4();
    virtual void virtual3c8();
    virtual void virtual3cc();
    virtual void virtual3d0();
    virtual void virtual3d4();
    virtual void virtual3d8();
    virtual void virtual3dc();
    virtual void virtual3e0();
    virtual void virtual3e4();
    virtual void virtual3e8();
    virtual void virtual3ec();
    virtual void virtual3f0();
    virtual void virtual3f4();
    virtual void virtual3f8();
    virtual void virtual3fc();
    virtual void virtual400();
    virtual void virtual404();
    virtual void virtual408();
    virtual void virtual40c();
    virtual void virtual410();
    virtual void virtual414();
    virtual void virtual418();
    virtual void virtual41c();
    virtual void virtual420();
    virtual void virtual424();
    virtual void virtual428();
    virtual void virtual42c();
    virtual void virtual430();
    virtual void virtual434();
    virtual void virtual438();
    virtual void virtual43c();
    virtual void virtual440();
    virtual void virtual444();
    virtual void virtual448();
    virtual void virtual44c();
    virtual void virtual450();
    virtual void virtual454();
    virtual void virtual458();
    virtual void virtual45c();
    virtual void virtual460();
    virtual void virtual464();
    virtual void virtual468();
    virtual void virtual46c();
    virtual void virtual470();
    virtual void virtual474();
    virtual void virtual478();
    virtual void virtual47c();
    virtual void virtual480();
    virtual void virtual484();
    virtual void virtual488();
    virtual void virtual48c();
    virtual void virtual490();
    virtual void virtual494();
    virtual void virtual498();
    virtual void virtual49c();
    virtual void virtual4a0();
    virtual void virtual4a4();
    virtual void virtual4a8();
    virtual void virtual4ac();
    virtual void virtual4b0();
    virtual void virtual4b4();
    virtual void virtual4b8();
    virtual void virtual4bc();
    virtual void virtual4c0();
    virtual void virtual4c4();
    virtual void virtual4c8();
    virtual void virtual4cc();
    virtual void virtual4d0();
    virtual void virtual4d4();
    virtual void virtual4d8();
    virtual void virtual4dc();
    virtual void virtual4e0();
    virtual void virtual4e4();
    virtual void virtual4e8();
    virtual void virtual4ec();
    virtual void virtual4f0();
    virtual void virtual4f4();
    virtual void virtual4f8();
    virtual void virtual4fc();
    virtual void virtual500();
    virtual void virtual504();
    virtual void virtual508();
    virtual void virtual50c();
    virtual void virtual510();
    virtual void virtual514();
    virtual void virtual518();
    virtual void virtual51c();
    virtual void virtual520();
    virtual void virtual524();
    virtual void virtual528();
    virtual void virtual52c();
    virtual void virtual530();
    virtual void virtual534();
    virtual void virtual538();
    virtual void virtual53c();
    virtual void virtual540();
    virtual void virtual544();
    virtual void virtual548();
    virtual void virtual54c();
    virtual void virtual550();
    virtual void virtual554();
    virtual void virtual558();
    virtual void virtual55c();
    virtual void virtual560();
    virtual void virtual564();
    virtual void virtual568();
    virtual void virtual56c();
    virtual void virtual570();
    virtual void virtual574();
    virtual void virtual578();
    virtual void virtual57c();
    virtual void virtual580();
    virtual void virtual584();
    virtual void virtual588();
    virtual void virtual58c();
    virtual void virtual590();
    virtual void virtual594();
    virtual void virtual598();
    virtual void virtual59c();
    virtual void virtual5a0();
    virtual void virtual5a4();
    virtual void virtual5a8();
    virtual void virtual5ac();
    virtual void virtual5b0();
    virtual void virtual5b4();
    virtual void virtual5b8();
    virtual void virtual5bc();
    virtual void virtual5c0();
    virtual void virtual5c4();
    virtual void virtual5c8();
    virtual void virtual5cc();
    virtual void virtual5d0();
    virtual void virtual5d4();
    virtual void virtual5d8();
    virtual void virtual5dc();
    virtual void virtual5e0();
    virtual void virtual5e4();
    virtual void virtual5e8();
    virtual void virtual5ec();
    virtual void virtual5f0();
    virtual void virtual5f4();
    virtual void virtual5f8();
    virtual void virtual5fc();
    virtual void virtual600();
    virtual void virtual604();
    virtual void virtual608();
    virtual void virtual60c();
    virtual void virtual610();
    virtual void virtual614();
    virtual void virtual618();
    virtual void virtual61c();
    virtual void virtual620();
    virtual void virtual624();
    virtual void virtual628();
    virtual void virtual62c();
    virtual void virtual630();
    virtual void v634(Obj114*);
    virtual void virtual638();
    virtual void virtual63c();
    virtual void virtual640();
    virtual void v644(int);
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
    unsigned char flag80;
    Obj114* FUN_008d8520();
    void FUN_0083b9a0();
    Obj114* FUN_0083c820();
    void FUN_0083c7b0();
    void FUN_0083c7e0();
    void FUN_0083b9f0();
    Obj114* FUN_0084e3a0();
    Obj114* FUN_009611e0();
    void FUN_00934250();
    Obj114* FUN_007af430();
    Handle114 PlaySoundByFormID(Obj114*, int, unsigned int, int);
    void FUN_0083c850(int);
    void SetFlag86(bool);
    Obj114* FUN_0044ddc0();
    bool GetField24();
    Obj114* FUN_00441110();
    Obj114* FUN_006815c0();
    void* FUN_004048e0();
    Obj114* FUN_00516bf0();
    String114* FUN_00460140();
    void* FUN_00559450();
    bool FUN_008c1bc0();
};
struct Manager114
{
    Handle114 FUN_00ad7480(char*, unsigned int, int);
    void FUN_00adbfd0(void*, void (*)(), Obj114*);
};
extern Manager114* __cdecl FUN_00ad9060();
void FUN_00935cc0();
void FUN_00936ac0();
struct Setting114
{
    bool* FUN_00408d60();
};
extern Setting114 DAT_011e05ec, DAT_011d8928;
extern unsigned char DAT_011f122d;
struct Player114
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
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    void* process;
};
extern Player114* DAT_011dea3c;
void __cdecl FUN_005b5e40(const char*, ...);
void __cdecl FUN_00406d30(char*, unsigned int, void*);
Manager114* __cdecl FUN_00453a70();
float __cdecl FUN_005790d0();
float __cdecl FUN_005790b0();
void __cdecl FUN_00705210(void*, Handle114, Vec114, Obj114*, int);
struct Dialogue114
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
    Handle114 sound;
    unsigned int unk8c;
    float delay;
    Obj114* current;
    bool active;
    unsigned char unk99;
    unsigned short unk9a;
    unsigned int unk9c;
    bool flagA0;
    unsigned char unka1;
    unsigned short unka2;
    Obj114 *list, *item, *response, *first, *second, *third;
    unsigned int unkbc;
    unsigned char unkc0;
    bool flagC1;
    unsigned short unkc2;
    Obj114* valueC4;
    Obj114* valueC8;
    bool ready;
    bool GetByteAtBC();
    bool FUN_006727b0();
    void FUN_00705b10(Obj114*);
    void FUN_009ee0a0(bool process);
};

// @fnv 0x009ee0a0
void Dialogue114::FUN_009ee0a0(bool process)
{
    bool started15 = false;
    bool reset26 = true;
    if ((current && !current->flag80) || first->FUN_008d8520()->v11c())
        return;
    if (!active)
    {
        if (!item)
        {
            started15 = true;
            if (!list)
            {
                first->v200(1);
                second->v200(1);
                return;
            }
            if (GetByteAtBC() && !flagC1)
            {
                second->FUN_008d8520()->v644(1);
                second->FUN_008d8520()->v634(first);
            }
            list->FUN_0083b9a0();
            item = list->FUN_0083c820();
            if (item)
            {
                item->FUN_0083c7b0();
                response = item->FUN_0083c820();
            }
            else
            {
                first->v200(1);
                if (!FUN_006727b0())
                    second->v200(1);
            }
        }
        else if (response)
        {
            item->FUN_0083c7e0();
            response = item->FUN_0083c820();
        }
        if (first)
        {
            if (!first->v2e8() && !first->v22c(0))
            {
                if (!response)
                {
                    list->FUN_0083b9f0();
                    item = list->FUN_0083c820();
                }
            }
            else if (!response)
                item = 0;
        }
    }
    if (item)
    {
        if (!response)
        {
            item->FUN_0083c7b0();
            response = item->FUN_0083c820();
            if (!response)
                FUN_005b5e40("AI: No responses found for conversation Topic Info (%08X).",
                             item->FUN_0084e3a0()->FUN_0084e3a0());
        }
        if (response)
        {
            Obj114* actor18 = item->FUN_009611e0();
            if (actor18->v100())
            {
                Obj114* speaker23 = item->FUN_009611e0();
                if (speaker23 && process)
                {
                    String114 text6;
                    if (current)
                    {
                        current->FUN_00934250();
                        current = 0;
                    }
                    bool speak13 = true;
                    if (response->FUN_007af430() && ready)
                    {
                        Obj114* topic21 = response->FUN_007af430()->FUN_0084e3a0();
                        Handle114 handle23 = speaker23->PlaySoundByFormID(topic21, 0, 0x40000102, 1);
                        Manager114* manager3 = FUN_00ad9060();
                        manager3->FUN_00adbfd0(handle23.FUN_00559450(), FUN_00935cc0, first->FUN_0084e3a0());
                        ready = false;
                        speak13 = false;
                    }
                    if (speak13 && ready)
                    {
                        text6.FUN_00438470(response->FUN_00460140());
                        if (!speaker23->FUN_008d8520()->v37c() && !speaker23->FUN_008d8520()->v36c() &&
                            *DAT_011e05ec.FUN_00408d60() && !speaker23->FUN_008d8520()->v378())
                        {
                            valueC4 = response->FUN_0044ddc0();
                            valueC8 = response->FUN_0084e3a0();
                            FUN_00705b10(valueC4);
                            if (item)
                                item->FUN_0083c850(0);
                            current = speaker23;
                            speaker23->SetFlag86(response->GetField24());
                            float duration13 = speaker23->v284(
                                text6.FUN_00559450(), &sound, response->FUN_0044ddc0(), response->FUN_0084e3a0(),
                                response->FUN_006815c0()->FUN_004048e0(), response->FUN_009611e0(),
                                response->FUN_00441110(), second, 1, 0, 1, 1, flagA0);
                            if (third)
                            {
                                Obj114* data15 = third->FUN_007af430();
                                if (data15->FUN_00516bf0() == speaker23)
                                {
                                    Obj114* target20 = second;
                                    if (second == third)
                                        target20 = first;
                                    current = third;
                                    third->SetFlag86(response->GetField24());
                                    duration13 = third->v284(
                                        text6.FUN_00559450(), &sound, response->FUN_0044ddc0(),
                                        response->FUN_0084e3a0(), response->FUN_006815c0()->FUN_004048e0(),
                                        response->FUN_009611e0(), response->FUN_00441110(), target20, 0, 0, 0, 1, 1);
                                }
                            }
                            if (speaker23->FUN_008d8520()->v36c())
                                active = true;
                            else
                            {
                                Manager114* manager228 = FUN_00ad9060();
                                manager228->FUN_00adbfd0(sound.FUN_00559450(), FUN_00936ac0, first->FUN_0084e3a0());
                                if (first != second)
                                    delay = 50.0f;
                                speaker23->flag80 = 0;
                            }
                            return;
                        }
                        else
                        {
                            if (speaker23->FUN_008d8520()->v36c() && !speaker23->FUN_008d8520()->v378())
                                return;
                            else
                            {
                                if (!*DAT_011e05ec.FUN_00408d60() && item)
                                    item->FUN_0083c850(0);
                                current = speaker23;
                                speaker23->SetFlag86(response->GetField24());
                                speaker23->v284(text6.FUN_00559450(), &sound, response->FUN_0044ddc0(),
                                                response->FUN_0084e3a0(), response->FUN_006815c0()->FUN_004048e0(),
                                                response->FUN_009611e0(), response->FUN_00441110(), second, 1, 0, 0, 1,
                                                flagA0);
                                if (third)
                                {
                                    if (third)
                                    {
                                        Obj114* data218 = third->FUN_007af430();
                                        if (data218->FUN_00516bf0() == speaker23)
                                        {
                                            Obj114* target24 = second;
                                            if (second == third)
                                                target24 = first;
                                            current = third;
                                            third->SetFlag86(response->GetField24());
                                            third->v284(text6.FUN_00559450(), &sound, response->FUN_0044ddc0(),
                                                        response->FUN_0084e3a0(),
                                                        response->FUN_006815c0()->FUN_004048e0(),
                                                        response->FUN_009611e0(), response->FUN_00441110(), target24, 0,
                                                        0, 0, 1, 1);
                                        }
                                    }
                                }
                                Manager114* manager334 = FUN_00ad9060();
                                manager334->FUN_00adbfd0(sound.FUN_00559450(), FUN_00936ac0, first->FUN_0084e3a0());
                                speaker23->flag80 = 0;
                                reset26 = false;
                                current = speaker23;
                                speaker23->FUN_008d8520()->v380(0);
                                active = false;
                                speaker23->FUN_008d8520()->v374(0);
                                if (first != second)
                                    delay = 2.0f;
                                Obj114* obj21 = current->v1e4();
                                Obj114* obj25 = second->v1e4();
                            }
                        }
                    }
                }
                if (reset26)
                {
                    if (first->FUN_008d8520())
                        first->FUN_008d8520()->v44(first, 0, 2, 0, 1, 1);
                    if (first != current && current && current->FUN_008d8520())
                        second->FUN_008d8520()->v44(second, 0, 2, 0, 1, 1);
                }
            }
            else if (actor18 && process)
            {
                char path27[512];
                String114 text22;
                String114 copy14(response->FUN_00460140());
                if (response->FUN_00460140()->FUN_00559450())
                {
                    FUN_00406d30(path27, 512, response->FUN_00460140()->FUN_00559450());
                    if (current)
                    {
                        current->FUN_00934250();
                        current = 0;
                    }
                    text22.FUN_00438470(response->FUN_00460140());
                    if (third)
                    {
                        Obj114* data310 = third->FUN_007af430();
                        third->SetFlag86(response->GetField24());
                        current = third;
                        third->v284(text22.FUN_00559450(), &sound, response->FUN_0044ddc0(), response->FUN_0084e3a0(),
                                    response->FUN_006815c0()->FUN_004048e0(), response->FUN_009611e0(),
                                    response->FUN_00441110(), second, 0, 0, 0, 1, 1);
                        Manager114* manager45 = FUN_00ad9060();
                        manager45->FUN_00adbfd0(sound.FUN_00559450(), FUN_00936ac0, third->FUN_0084e3a0());
                        third->flag80 = 0;
                        reset26 = false;
                    }
                    else
                    {
                        unsigned int flags22 = 0x104;
                        flags22 |= 2;
                        sound.FUN_00418900(FUN_00453a70()->FUN_00ad7480(path27, flags22, 0));
                        Vec114 position1 = actor18->v1f4();
                        sound.FUN_00ad8be0(FUN_005790b0(), FUN_005790d0());
                        sound.SetPos(position1.x, position1.y, position1.z);
                        sound.SetNiNode(actor18->v1d0());
                        sound.FUN_00ad8870(1, 0);
                    }
                }
                if ((this == DAT_011dea3c->process || DAT_011f122d) && list->FUN_0083c820() &&
                    list->FUN_0083c820()->FUN_0083c820() &&
                    list->FUN_0083c820()->FUN_0083c820()->FUN_006815c0()->FUN_00559450())
                {
                    if (*DAT_011d8928.FUN_00408d60() || (actor18->v100() && actor18->FUN_008c1bc0()))
                        FUN_00705210(list->FUN_0083c820()->FUN_0083c820()->FUN_006815c0()->FUN_00559450(), sound,
                                     actor18->v1f4(), second, 0);
                }
                if (delay <= 0.0 && second != actor18)
                    delay = 10.0f;
            }
        }
    }
    else
    {
        first->v200(1);
        if (!FUN_006727b0())
            second->v200(1);
    }
}

struct Sound
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
    virtual int VCall130();
};
struct TESSound
{
    unsigned int m_00;
};
struct FUN_008579e0_shell
{
    void __thiscall FUN_008579e0(void* buf, unsigned int n);
};
struct TimeGlobal : FUN_008579e0_shell
{
    unsigned int __thiscall GetTimeStamp();
};
struct EffectSetting : TimeGlobal
{
    TESSound* __thiscall GetBoltSound();
};
struct TESSaveLoadGame : EffectSetting
{
    bool __thiscall FUN_00862110();
    unsigned char __thiscall FUN_008df040();
};
extern TESSaveLoadGame* DAT_011de45c;
TESForm* __cdecl _ref_004839c0(unsigned int a);
class TESTopic : public TESForm
{
};
void __cdecl FUN_005b5e40(const char* fmt, ...);
void* __cdecl FUN_00ec43fb(void* a, int b, void* c, void* d, int e);
extern char DAT_01015718;
extern char DAT_010156a8;
extern char DAT_01015588;
extern char DAT_01015500;
extern char DAT_010154a0;
extern char DAT_01015440;
extern char DAT_01093108;
extern void* DAT_01183028;
extern void* DAT_01184720;
struct SLObj
{
    void __thiscall LoadFromSave();
    int __thiscall FUN_0083bac0(unsigned short a);
};
struct DialogueItem_shell
{
    int __thiscall GetResponseByIndex(short a);
};
struct This
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48;
    int f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c, f80, f84, f88;
    void* f8c;
    int f90;
    int f94;
    unsigned char f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    void __thiscall FUN_00679340();
    void __thiscall FUN_00484d00(void* a, unsigned int b);
    void __thiscall FUN_00484d40(unsigned int* a, int b);
    void __thiscall LoadSaveData();
};
// @fnv 0x009efa50
void This::LoadSaveData()
{
    FUN_00679340();
    {
        unsigned short w18 = 0;
        int flag = 0;
        if (DAT_011de45c->FUN_00862110())
        {
            unsigned int i;
            DAT_011de45c->FUN_008579e0(&i, 4);
            if (i != 0x424c4f4b)
            {
                TESSound* rec = DAT_011de45c->GetBoltSound();
                if (rec != 0)
                {
                    TESForm* pForm = _ref_004839c0(rec->m_00);
                    FUN_005b5e40(&DAT_01015718, &DAT_01093108, 0x239, rec->m_00, ((Sound*)pForm)->VCall130(),
                                 *(unsigned char*)((char*)rec + 9), *(int*)((char*)rec + 5));
                }
                else
                {
                    FUN_005b5e40(&DAT_010156a8, &DAT_01093108, 0x239, DAT_011de45c->FUN_008df040());
                }
            }
            flag = DAT_011de45c->GetTimeStamp();
            DAT_011de45c->FUN_008579e0(&w18, 2);
        }
        FUN_00484d00(&f90, 4);
        if ((int)DAT_011de45c->FUN_008df040() >= 0x6a)
        {
            FUN_00484d00(&f98, 1);
        }
        unsigned int id;
        FUN_00484d40(&id, 4);
        f94 = (int)id;
        unsigned int a18;
        FUN_00484d40(&a18, 4);
        fb0 = (int)a18;
        unsigned int a10;
        FUN_00484d40(&a10, 4);
        fb4 = (int)a10;
        unsigned int a14;
        FUN_00484d40(&a14, 4);
        f8c = dynamic_cast<TESTopic*>(_ref_004839c0(a14));
        if ((int)DAT_011de45c->FUN_008df040() >= 0x20)
        {
            unsigned short w34;
            FUN_00484d00(&w34, 2);
            if (w34 != 0)
            {
                fa4 = (int)new FUN_0083b830;
                ((SLObj*)fa4)->LoadFromSave();
                short w38;
                FUN_00484d00(&w38, 2);
                if (w38 != -1)
                {
                    fa8 = ((SLObj*)fa4)->FUN_0083bac0((unsigned short)w38);
                }
                else
                {
                    fa8 = 0;
                }
                short w3c;
                FUN_00484d00(&w3c, 2);
                fac = w3c;
                if (fa8 != 0 && w3c != -1)
                {
                    fac = ((DialogueItem_shell*)fa8)->GetResponseByIndex((unsigned short)w3c);
                }
                else
                {
                    fac = 0;
                }
            }
        }
        if ((int)DAT_011de45c->FUN_008df040() < 0x20)
        {
            unsigned int a40;
            FUN_00484d00(&a40, 4);
            fa4 = (int)a40;
            if (a40 != 0)
            {
                short w44;
                FUN_00484d00(&w44, 2);
                fa8 = w44;
                short w48;
                FUN_00484d00(&w48, 2);
                fac = w48;
            }
            else
            {
                fa8 = 0;
                fac = 0;
            }
        }
        if (DAT_011de45c->FUN_00862110())
        {
            unsigned int ts = DAT_011de45c->GetTimeStamp();
            TESSound* tag = DAT_011de45c->GetBoltSound();
            if (tag != 0)
            {
                TESForm* snd = _ref_004839c0(tag->m_00);
                if ((unsigned int)ts > (unsigned int)w18 + (unsigned int)flag)
                {
                    FUN_005b5e40(&DAT_01015588, (int)((unsigned int)ts - ((unsigned int)w18 + (unsigned int)flag)),
                                 &DAT_01093108, 0x288, tag->m_00, ((Sound*)snd)->VCall130(),
                                 *(unsigned char*)((char*)tag + 9), *(int*)((char*)tag + 5));
                }
                else if ((unsigned int)ts < (unsigned int)w18 + (unsigned int)flag)
                {
                    FUN_005b5e40(&DAT_01015500, (int)(((unsigned int)w18 + (unsigned int)flag) - (unsigned int)ts),
                                 &DAT_01093108, 0x288, tag->m_00, ((Sound*)snd)->VCall130(),
                                 *(unsigned char*)((char*)tag + 9), *(int*)((char*)tag + 5));
                }
            }
            else
            {
                if ((unsigned int)ts > (unsigned int)w18 + (unsigned int)flag)
                {
                    FUN_005b5e40(&DAT_010154a0, (int)((unsigned int)ts - ((unsigned int)w18 + (unsigned int)flag)),
                                 &DAT_01093108, 0x288, DAT_011de45c->FUN_008df040());
                }
                else if ((unsigned int)ts < (unsigned int)w18 + (unsigned int)flag)
                {
                    FUN_005b5e40(&DAT_01015440, (int)(((unsigned int)w18 + (unsigned int)flag) - (unsigned int)ts),
                                 &DAT_01093108, 0x288, DAT_011de45c->FUN_008df040());
                }
            }
        }
    }
}

namespace fnv_009eff60 {
TESForm* LookupFormByID(unsigned int formID);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* object);

class TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

class DialogueItem
{
  public:
    DialogueResponse* GetResponseByIndex(short index);
    void FUN_0083c8a0(DialogueResponse* response);
};

class Conversation
{
  public:
    DialogueItem* currentItem;
    Character* speaker;
    PlayerCharacter* listener;
    Conversation(Character* speaker, PlayerCharacter* listener, TESTopic* topic);
    void FUN_0083c220();
    DialogueItem* FUN_0083bac0(short index);
    void FUN_0083c8a0(DialogueItem* item);
};

struct DialoguePackageState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    TESTopic* topic;
    unsigned int unk90;
    Actor* target;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    Conversation* conversation;
    DialogueItem* item;
    DialogueResponse* response;
    Actor* speaker;
    Actor* listener;

    void FUN_006796c0();
    void ResolveReferences();
};

// Resolves target, speaker and listener from stored IDs, then rebuilds the conversation, item and response from saved indices.
// @fnv 0x009eff60
void DialoguePackageState::ResolveReferences()
{
    FUN_006796c0();
    // Serialized actor IDs are resolved in target, speaker, listener order.
    unsigned int listenerID = (unsigned int)target;
    target = dynamic_cast<Actor*>(LookupFormByID(listenerID));
    unsigned int targetID;
    unsigned int speakerID = (unsigned int)speaker;
    speaker = dynamic_cast<Actor*>(LookupFormByID(speakerID));
    targetID = (unsigned int)listener;
    listener = dynamic_cast<Actor*>(LookupFormByID(targetID));

    if (g_TESSaveLoadGame->FUN_008df040() >= 32 && conversation)
        conversation->FUN_0083c220();
    if (g_TESSaveLoadGame->FUN_008df040() < 32)
    {
        // Retain the saved conversation marker and its two serialized indices.
        Conversation* itemIndex = conversation;
        short oldConversation = (short)(unsigned int)item;
        short responseIndex = (short)(unsigned int)response;
        if (itemIndex)
        {
            conversation = new Conversation((Character*)speaker, (PlayerCharacter*)listener, topic);
            if (oldConversation != -1)
                item = conversation->FUN_0083bac0(oldConversation);
            else
                item = 0;
            if (item && responseIndex != -1)
                response = item->GetResponseByIndex(responseIndex);
            else
                response = 0;
            conversation->FUN_0083c8a0(item);
            item->FUN_0083c8a0(response);
        }
    }
}
}  // namespace fnv_009eff60

namespace fnv_009ef6e0 {
struct DialogueSaveRecord
{
    unsigned int formID;
    unsigned char type;
    unsigned char flags;
};
class DialogueSaveGameWriter
{
  public:
    unsigned int FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void*, int);
    unsigned char FUN_008df040();
    DialogueSaveRecord* FUN_004fd3e0();
};
struct TESSaveLoadGame;
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
class DialogueItem
{
  public:
    short GetResponseIndex(DialogueResponse*);
};
class Conversation_Stub
{
  public:
    unsigned short FUN_0083bb30();
    void SaveConversation();
    short FUN_0083ba50(DialogueItem*);
};
TESForm* LookupFormByID(unsigned int);
void FUN_0040fbe0(const char*, ...);
void FNV_Warning(const char*, ...);
class DialoguePackage
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    TESForm* speaker;
    unsigned int state;
    TESForm* topic;
    unsigned char flags;
    unsigned int unk9C;
    unsigned int unkA0;
    Conversation_Stub* conversation;
    DialogueItem* item;
    DialogueResponse* response;
    TESForm* quest;
    TESForm* info;
    void SavePackage();
    void FUN_00484ce0(void*, int);
    void ForwardToSaveLoadGame(void*, int);
    void FUN_009ef6e0();
};

// Writes the DialoguePackage state, topic, quest, info, speaker, conversation item and response indices to the save-game writer, then patches the block size.
// @fnv 0x009ef6e0
void DialoguePackage::FUN_009ef6e0()
{
    SavePackage();
    unsigned short size5 = 0;    // blockSize
    unsigned short* offset = 0;  // blockStart
    // Initial save position.
    unsigned int saved7 = ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00825c00();
    if (*g_011de4e8.Bool())
        saved7 = ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00825c00();
    if (((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int blockTag = 0x424c4f4b;
        ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_008579b0(&blockTag, 4);
        offset = (unsigned short*)((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00825c00();
        ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_008579b0(&size5, 2);
    }
    FUN_00484ce0(&state, 4);
    if (((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_008df040() >= 106)
        FUN_00484ce0(&flags, 1);
    unsigned int form7 = 0;  // topicID
    if (topic)
        form7 = topic->GetFormID();
    ForwardToSaveLoadGame(&form7, 4);
    unsigned int form2 = 0;
    if (quest)
        form2 = quest->GetFormID();
    ForwardToSaveLoadGame(&form2, 4);
    unsigned int formVal = 0;  // infoID
    if (info)
        formVal = info->GetFormID();
    ForwardToSaveLoadGame(&formVal, 4);
    unsigned int form5 = 0;  // speakerID
    if (speaker)
        form5 = speaker->GetFormID();
    ForwardToSaveLoadGame(&form5, 4);
    unsigned short countB = 0;  // count
    if (conversation)
        countB = conversation->FUN_0083bb30();
    ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_008579b0(&countB, 2);
    if (countB)
    {
        conversation->SaveConversation();
        short itemIndex = -1;
        if (item)
            itemIndex = conversation->FUN_0083ba50(item);
        FUN_00484ce0(&itemIndex, 2);
        short responseIndex = -1;
        if (item && response)
            responseIndex = item->GetResponseIndex(response);
        FUN_00484ce0(&responseIndex, 2);
    }
    if (*g_011de4e8.Bool())
    {
        unsigned int end = ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00825c00();
        DialogueSaveRecord* record = ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_004fd3e0();
        if (record)
        {
            TESForm* form = LookupFormByID(record->formID);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end - saved7,
                         record->formID, form->GetName(), (unsigned int&)record->flags, 0x231,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", end - saved7, 0x231,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
        }
    }
    if (((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int end = ((DialogueSaveGameWriter*)g_TESSaveLoadGame)->FUN_00825c00();
        unsigned int offset2 = (unsigned int)offset;
        if (end > offset2 + 0xffff)
            FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp", 0x231);
        *offset = (unsigned short)(end - offset2);
    }
}
}  // namespace fnv_009ef6e0

namespace fnv_009f0460 {
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    void FUN_008648e0(void* p);
    unsigned FUN_008648a0();
    void FUN_00864980(void* p, unsigned n);
};
TESForm* __cdecl LookupFormByID(unsigned id);
struct List0083b830SV
{
    int a, b, c;
    List0083b830SV();
    void* operator new(unsigned);
    void* FUN_0083bac0(unsigned short i);
    void FUN_0083c330(BGSLoadFormBuffer* buf);
};
struct DlgItemX
{
    void* GetResponseByIndex(unsigned short i);
};
struct TESPackage
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
    void LoadGame(BGSLoadFormBuffer* buf);
};
struct FUN_009f0460_class : TESPackage
{
    TESTopic* m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    char ma0;
    char ma1, ma2, ma3;
    List0083b830SV* ma4;
    DlgItemX* ma8;
    void* mac;
    int mb0;
    int mb4;
    int mb8;
    char mbc, mbd, mbe, mbf, mc0, mc1, mc2, pc3;
    int mc4;
    int mc8;
    char mcc;
    void FUN_009f0460(BGSLoadFormBuffer* buf);
};
// Loads the base package, reads fields from the buffer, and conditionally loads a list with two indexed selections.
// @fnv 0x009f0460
void FUN_009f0460_class::FUN_009f0460(BGSLoadFormBuffer* apSaveBuffer)
{
    TESPackage::LoadGame(apSaveBuffer);
    apSaveBuffer->FUN_008648e0(&m94);
    apSaveBuffer->FUN_008648e0(&mb0);
    apSaveBuffer->FUN_008648e0(&mb4);
    apSaveBuffer->FUN_008648e0(&mb8);
    apSaveBuffer->FUN_008648e0(&m9c);
    m8c = dynamic_cast<TESTopic*>(LookupFormByID(apSaveBuffer->FUN_008648a0()));
    apSaveBuffer->FUN_00864980(&m90, 4);
    apSaveBuffer->FUN_00864980(&m98, 1);
    apSaveBuffer->FUN_00864980(&mbc, 1);
    apSaveBuffer->FUN_00864980(&mbd, 1);
    apSaveBuffer->FUN_00864980(&mbe, 1);
    apSaveBuffer->FUN_00864980(&mbf, 1);
    apSaveBuffer->FUN_00864980(&mc0, 1);
    apSaveBuffer->FUN_00864980(&mc1, 1);
    apSaveBuffer->FUN_00864980(&mc4, 4);
    apSaveBuffer->FUN_00864980(&mc8, 4);
    apSaveBuffer->FUN_00864980(&ma0, 1);
    apSaveBuffer->FUN_00864980(&mcc, 1);
    if (apSaveBuffer->GetVersion() >= 3)
        apSaveBuffer->FUN_00864980(&mc2, 1);
    bool b = false;
    apSaveBuffer->FUN_00864980(&b, 1);
    if (b)
    {
        ma4 = new List0083b830SV();
        ma4->FUN_0083c330(apSaveBuffer);
        short i1 = -1;
        apSaveBuffer->FUN_00864980(&i1, 2);
        if (i1 != -1)
            ma8 = (DlgItemX*)ma4->FUN_0083bac0(i1);
        short i2 = -1;
        apSaveBuffer->FUN_00864980(&i2, 2);
        if (ma8 && i2 != -1)
            mac = ma8->GetResponseByIndex(i2);
    }
}
}  // namespace fnv_009f0460
