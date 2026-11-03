// fallout/dialogue/menutopic.cpp: TopicMenuController, MenuTopic, TESTopicInfo, TopicHolder and more (33 functions)

#include "menutopic_decls.h"
#include "menutopic_types_MenuTopic.h"
#include "menutopic_types_MenuTopicManager.h"

// @fnv 0x0083e170
DialogueResponse* MenuTopic::GetActiveResponse()
{
    if (m_pCurrentResponseList)
    {
        return m_pCurrentResponseList->GetItem();
    }
    else
    {
        return 0;
    }
}

// @fnv 0x0083e4c0
MenuTopic* TopicMenuController::GetSelectedTopic()
{
    if (m_pCurrentTopicList)
    {
        return m_pCurrentTopicList->GetItem();
    }
    else
    {
        return 0;
    }
}

// @fnv 0x0083e4f0
MenuTopic* TopicMenuController::GetFirstTopic()
{
    return FUN_0083f260()->GetItem();
}

// Advances the stored iterator to its next entry and returns whether it exists and has an item.
// @fnv 0x0083e3e0
bool TopicMenuController::AdvanceTopic()
{
    if (m_pCurrentTopicList)
        m_pCurrentTopicList = m_pCurrentTopicList->GetNext();
    return m_pCurrentTopicList && m_pCurrentTopicList->GetItem();
}

// Advances the stored iterator when advance is set and it is non-null, then returns whether the iterator exists and has an item.
// @fnv 0x0083e370
bool TopicMenuController::SelectTopic(bool advance)
{
    m_pCurrentTopicList = FUN_0083f260();
    if (advance && m_pCurrentTopicList)
        m_pCurrentTopicList = m_pCurrentTopicList->GetNext();
    return m_pCurrentTopicList && m_pCurrentTopicList->GetItem();
}

// @fnv 0x004d5c60
void TopicMenuController::IncrementMiscStat(int aiStatId)
{
    MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)aiStatId, 1);
}

// @fnv 0x0083e620
bool TopicMenuController::Initialize(MobileObject* speaker, TESTopic* requestedTopic)
{
    // Keep the greeting context together in the original stack-frame order.
    struct GreetingLocals
    {
        BSSimpleList<MenuTopic*>* topicList;
        TESQuest* quest;
        unsigned char padding0, padding1, padding2;
        bool dispositionFailure;
        TESTopicInfo* info;
        MenuTopic* menuTopic;
        TESTopic* topic;
    } locals;
    FUN_0083e230();
    locals.topicList = new BSSimpleList<MenuTopic*>;
    m_kTopicListStack.AddHead(locals.topicList);
    m_pDialogueSpeaker = (TESObjectREFR*)speaker;
    m_bControllerFlag = false;
    m_iTopicIndex = 0;
    locals.topic = requestedTopic;
    if (!locals.topic)
        locals.topic = TESTopic::GetAudioBackendData((DIALOGUE_TYPE)0, 0);
    locals.menuTopic = 0;
    if (locals.topic)
    {
        locals.info = locals.topic->FindMatchingTopicInfo(locals.dispositionFailure, (MobileObject*)m_pDialogueSpeaker,
                                                          g_thePlayer);
        if (locals.info)
        {
            locals.quest = locals.topic->GetParentQuest(locals.info);
            locals.menuTopic =
                new MenuTopic(locals.quest, locals.topic, locals.info, (MobileObject*)m_pDialogueSpeaker, false);
            locals.menuTopic->FUN_0045cd60(2147483648.0f)->FUN_00965250();
            locals.menuTopic->FillResponseList();
            FUN_0083f260()->AddTail(locals.menuTopic);
        }
    }
    if (locals.menuTopic)
    {
        locals.menuTopic->GetTopicInfo()->AddTopicList();
        locals.menuTopic->GetTopicInfo()->RunResultScript(false, (MobileObject*)m_pDialogueSpeaker);
    }
    else
        Warning((const char*)6, "No GREETING topic was found for %s. Selecting stock GREETING.",
                m_pDialogueSpeaker->GetFullName());
    SelectTopic(false);
    return locals.menuTopic && locals.menuTopic->GetTopicInfo() &&
           ((TESTopic*)locals.menuTopic->GetTopicInfo())->IsRemappedRumors();
}

// Initializes a MenuTopic from quest, topic, info and speaker, optionally substituting a refusal info and resolving owner quest/topic.
// @fnv 0x0083db00
MenuTopic::MenuTopic(TESQuest* quest, TESTopic* topic, TESTopicInfo* info, MobileObject* speaker,
                     bool substituteRefusal)
{
    // Selected and owning topic contexts can differ after refusal substitution.
    struct TopicLocals
    {
        TESTopicInfo* refusalInfo;
        TESTopic* refusalTopic;
        TESQuest* ownerQuest;
        TESTopic* ownerTopic;
        TESQuest* selectedQuest;
        TESTopic* selectedTopic;
    } locals;
    m_pCurrentResponseList = 0;
    pQuest = 0;
    pTopic = 0;
    pInfo = 0;
    m_pOriginalTopic = topic;
    if (topic->IsRemappedRumors())
    {
        m_bIsRemappedRumor = true;
        m_bFirstFlag = false;
    }
    else
        m_bIsRemappedRumor = false;
    m_bIsRefusal = false;
    m_bThirdFlag = false;
    locals.selectedQuest = quest;
    locals.selectedTopic = topic;
    if (topic && info)
    {
        m_bInfoHasBeenRead = !info->IsNew();
        pInfo = info;
        if (substituteRefusal && !info->IsRefusal())
        {
            locals.refusalTopic = TESTopic::GetAudioBackendData((DIALOGUE_TYPE)6, 12);
            locals.refusalInfo =
                locals.refusalTopic ? locals.refusalTopic->FindMatchingTopicInfo(speaker, g_thePlayer) : 0;
            if (locals.refusalInfo)
            {
                pInfo = locals.refusalInfo;
                locals.selectedTopic = locals.refusalTopic;
                locals.selectedQuest = locals.selectedTopic->GetParentQuest(locals.refusalInfo);
            }
            m_bIsRefusal = true;
        }
        else
            m_bIsRefusal = info->IsRefusal();
        if (((MenuTopicPlayer*)g_thePlayer)->actorValues.GetActorValue(9) <= *g_011d0dc8.Int() &&
            topic->HasDummyPrompt())
            m_kPrompt.FUN_00438470(topic->GetDummyPrompt());
        else if (info->HasPrompt())
            m_kPrompt.FUN_00438470(info->GetPrompt());
        else
            m_kPrompt.Set(topic->tESFullNameComponent.GetFullName());
        m_kPrompt.FUN_00438470(FUN_0083d8b0());
        if (!m_bIsRemappedRumor)
            m_bFirstFlag = pInfo->GetConversationData() && !pInfo->GetConversationData()->GetLinkToList()->IsEmpty();
        if (topic->IsPersuasion())
            m_bThirdFlag = true;
        locals.ownerQuest = pInfo->GetParentQuest();
        locals.ownerTopic = TESTopic::GetTopicFromInfo(pInfo);
        if (locals.selectedQuest != locals.ownerQuest || locals.selectedTopic != locals.ownerTopic)
            FUN_0083df80(locals.ownerQuest, locals.ownerTopic, pInfo, speaker);
        else
            FUN_0083df80(locals.selectedQuest, locals.selectedTopic, pInfo, speaker);
    }
    pTopic = locals.selectedTopic;
    pQuest = locals.selectedQuest;
}

// Initializes the object's two fields to zero.
// @fnv 0x0083e1a0
TopicMenuController::TopicMenuController()
{
    m_pCurrentTopicList = 0;
    m_pDialogueSpeaker = 0;
}

// @fnv 0x0083e590
TopicMenuController* TopicMenuController::GetInstance()
{
    if (!g_011ddde4)
        g_011ddde4 = new TopicMenuController();
    return g_011ddde4;
}

// @fnv 0x0083ec10
bool TESTopicInfo::FUN_0083ec10()
{
    return m_Data.flags & 0x40;
}

// @fnv 0x0083ebb0
void TopicMenuController::RunTopicResultScript()
{
    // Keep the topic and info locals in the original stack-frame order.
    struct TopicLocals
    {
        MenuTopic* topic;    // [ebp-0x8]
        TESTopicInfo* info;  // [ebp-0x4]
    } locals;
    locals.topic = GetSelectedTopic();
    locals.info = 0;
    if (locals.topic)
    {
        if (!locals.topic->GetTopicInfo()->FUN_0083ec10())
            locals.info = locals.topic->GetTopicInfo();
    }
    if (locals.info)
        locals.info->RunResultScript(false, (MobileObject*)m_pDialogueSpeaker);
}

struct FUN_0083de40_shell : public TESTopicInfo
{
    bool FUN_0083de40();
};

unsigned int __fastcall FUN_004048e0(void*);

// @fnv 0x0083de40
bool FUN_0083de40_shell::FUN_0083de40()
{
    return FUN_004048e0(reinterpret_cast<char*>(this) + 0x28) > 0;
}

struct FUN_0083de60_shell : public TESTopic
{
    bool FUN_0083de60();
};

// Returns true when the form ID is 0xFD or 0x118.
// @fnv 0x0083de60
bool FUN_0083de60_shell::FUN_0083de60()
{
    return GetFormID() == 0xFD || GetFormID() == 0x118;
}

struct FUN_0083e230_shell : public TopicMenuController
{
    void FUN_0083e230();
};

bool __fastcall _ref_008256d0(void* pThis);
BSSimpleList<char const*>** __fastcall _ref_006815c0(void* pThis);
void __fastcall _ref_0063f7b0(void* pThis);

struct FUN_0083e2d0_helper
{
    void FUN_0083e2d0(void* pList, bool bDeleteGreeting);
};

// @fnv 0x0083e230
void FUN_0083e230_shell::FUN_0083e230()
{
    bool bdeletegreeting;
    BSSimpleList<char const*>* pCurrentElementNext;

    *(int*)((char*)this + 0xc) = 0;
    while (!_ref_008256d0((char*)this + 4))
    {
        pCurrentElementNext = *_ref_006815c0((char*)this + 4);
        _ref_0063f7b0((char*)this + 4);
        bdeletegreeting = _ref_008256d0((char*)this + 4);
        ((FUN_0083e2d0_helper*)this)->FUN_0083e2d0(pCurrentElementNext, bdeletegreeting);
        ((BSSimpleList<int>*)pCurrentElementNext)->RemoveAll();
        delete pCurrentElementNext;
    }
}

struct FUN_0083e430_shell : public TopicMenuController
{
    bool FUN_0083e430(int);
};

// @fnv 0x0083e430
bool FUN_0083e430_shell::FUN_0083e430(int aiIndex)
{
    int a = 0;
    BSSimpleList<MenuTopic*>* pMenuTopicEntry = FUN_0083f260();
    if (pMenuTopicEntry)
    {
        pMenuTopicEntry = pMenuTopicEntry->GetNext();
    }
    while (pMenuTopicEntry && a < aiIndex)
    {
        pMenuTopicEntry = pMenuTopicEntry->GetNext();
        ++a;
    }
    if (pMenuTopicEntry)
    {
        m_pCurrentTopicList = pMenuTopicEntry;
    }
    return pMenuTopicEntry && m_pCurrentTopicList->GetItem();
}

namespace fnv_0083f260 {
struct FUN_0083f260_shell : public TopicMenuController
{
    void* FUN_0083f260();
};

void** __fastcall _ref_006815c0(void* pThis);

// @fnv 0x0083f260
void* FUN_0083f260_shell::FUN_0083f260()
{
    return *_ref_006815c0((char*)this + 4);
}
}  // namespace fnv_0083f260

struct FUN_00965250_shell : public TESTopic
{
    void FUN_00965250(float);
};

// @fnv 0x00965250
void FUN_00965250_shell::FUN_00965250(float afValue)
{
    *(float*)((char*)this + 0x28) = afValue;
}

namespace fnv_0083e2d0 {
struct TopicItem
{
    char pad[0x24];
    bool bKeep;
    ~TopicItem();
};
void __fastcall _ref_0063f7b0(void* pThis);
void** __fastcall _ref_006815c0(void* pThis);
bool __fastcall _ref_008256d0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);
struct TopicHolder
{
    void* head;
    void FUN_0083e2d0(void* list, bool flag);
};
// @fnv 0x0083e2d0
void TopicHolder::FUN_0083e2d0(void* list, bool flag)
{
    head = 0;
    void* node = list;
    if (!flag && node)
        node = _ref_00726070(node);
    while (node && !_ref_008256d0(node))
    {
        TopicItem* item = (TopicItem*)*_ref_006815c0(node);
        if (!item->bKeep)
            delete (TopicItem*)*_ref_006815c0(node);
        _ref_0063f7b0(node);
    }
}
}  // namespace fnv_0083e2d0

struct FUN_0083ec30_shell : public TopicMenuController
{
    void UpdateTopicList();
};

struct FUN_00464e30_shell
{
    BSSimpleList<TESTopic*>* GetSelfOffset6A8();
};
struct FUN_0083ec30_topic : MenuTopic
{
    bool IsChoice();
    TESTopic* GetAudioBackendData();
};
struct FUN_0083ec30_mgr : TopicMenuController
{
    void PopTopicList();
    void FUN_0083e2d0(BSSimpleList<MenuTopic*>*, bool);
};

// @fnv 0x0083ec30
void FUN_0083ec30_shell::UpdateTopicList()
{
    FUN_0083ec30_topic* pMenuTopicEntry = (FUN_0083ec30_topic*)GetSelectedTopic();
    if (pMenuTopicEntry && pMenuTopicEntry->GetTopicInfo())
        pMenuTopicEntry->GetTopicInfo()->AddTopicList();
    if (m_bControllerFlag && pMenuTopicEntry && !pMenuTopicEntry->IsChoice())
    {
        ((FUN_0083ec30_mgr*)this)->PopTopicList();
        m_bControllerFlag = false;
    }
    else if (pMenuTopicEntry && !pMenuTopicEntry->m_bIsRemappedRumor)
    {
        bool bIsChoice = pMenuTopicEntry->IsChoice();
        BSSimpleList<TESTopic*>* pList = bIsChoice
                                             ? pMenuTopicEntry->GetTopicInfo()->GetConversationData()->GetLinkToList()
                                             : ((FUN_00464e30_shell*)g_thePlayer)->GetSelfOffset6A8();
        TESTopic* pTopic = pMenuTopicEntry->GetAudioBackendData();
        if (pList)
        {
            ((FUN_0083ec30_mgr*)this)->FUN_0083e2d0(FUN_0083f260(), false);
            BuildTopicList(pList, false, bIsChoice, pTopic);
        }
        if (m_bControllerFlag)
            m_bControllerFlag = false;
    }
}

float __fastcall FUN_00526ae0(TESTopic*);
struct FUN_0083f110_topic : MenuTopic
{
    TESTopic* GetAudioBackendData();
};

// Compares two topics by the value returned from FUN_00526ae0, returning -1, 1 or 0 for descending order.
// @fnv 0x0083f110
int FUN_0083f110(FUN_0083f110_topic* apTopicA, FUN_0083f110_topic* apTopicB)
{
    return FUN_00526ae0(apTopicA->GetAudioBackendData()) > FUN_00526ae0(apTopicB->GetAudioBackendData())
               ? -1
               : (FUN_00526ae0(apTopicA->GetAudioBackendData()) < FUN_00526ae0(apTopicB->GetAudioBackendData()) ? 1
                                                                                                                : 0);
}

struct FUN_0083f1d0_t : TopicMenuController
{
    void FUN_0083e2d0(BSSimpleList<MenuTopic*>*, bool);
    BSSimpleList<MenuTopic*>* PopTopicList();
};

// @fnv 0x0083f1d0
BSSimpleList<MenuTopic*>* FUN_0083f1d0_t::PopTopicList()
{
    if (m_kTopicListStack.GetNext())
    {
        BSSimpleList<MenuTopic*>* pCurrentElementNext = m_kTopicListStack.GetItem();
        if (pCurrentElementNext)
        {
            m_kTopicListStack.RemoveHead();
            FUN_0083e2d0(pCurrentElementNext, false);
            pCurrentElementNext->RemoveAll();
            delete pCurrentElementNext;
        }
    }
    return m_kTopicListStack.GetItem();
}

struct FormIDEntry
{
    unsigned int iFormID;
    unsigned char m_ucFormType;
};
struct TESSaveLoadGame
{
    bool FUN_00862110();
    FormIDEntry* GetCurrentFormHeader();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct Interface
{
    static void PrintDebugMessage(const char*, ...);
};
unsigned int BSStringLength(const char*);
TESForm* GetFormByID(unsigned int);
struct FUN_0083f280_str : BSStringT<char>
{
    operator const char*() const;
};
struct FUN_0083f280_t : MenuTopic
{
    unsigned short FUN_0083f280();
};

// Computes the save size of a MenuTopic by summing field sizes and optionally logs the size and form header details.
// @fnv 0x0083f280
unsigned short FUN_0083f280_t::FUN_0083f280()
{
    unsigned short isize = 0;
    {
        unsigned short itempStartSize = isize;
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            isize += 4;
            isize += 2;
        }
        const char* ptext = (const FUN_0083f280_str&)m_kPrompt;
        isize += 1;
        isize += BSStringLength(ptext);
        isize += 1;
        isize += 1;
        isize += 1;
        isize += 4;
        isize += 4;
        isize += 4;
        if (*g_011de4e8.Bool())
        {
            FormIDEntry* pheader = g_TESSaveLoadGame->GetCurrentFormHeader();
            if (pheader)
            {
                TESForm* pform = GetFormByID(pheader->iFormID);
                Interface::PrintDebugMessage(
                    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                    isize - itempStartSize, pheader->iFormID, pform->GetName(), *(unsigned int*)((char*)pheader + 5),
                    729, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
            }
            else
            {
                Interface::PrintDebugMessage(
                    "GetSaveSize(): %-5i ending at line %i in file %s", isize - itempStartSize, 729,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
            }
        }
    }
    return isize;
}

struct ListX
{
    ~ListX();
};
struct FUN_0083e1d0
{
    int _00;
    ListX _04;
    ~FUN_0083e1d0();
};
// @fnv 0x0083e1d0
FUN_0083e1d0::~FUN_0083e1d0()
{
    ((TopicMenuController*)this)->FUN_0083e230();
}

// If the global pointer g_011ddde4 is non-null, deletes it and resets it to null.
// @fnv 0x0083e510
void FUN_0083e510()
{
    if (g_011ddde4)
    {
        delete g_011ddde4;
        g_011ddde4 = 0;
    }
}

void _Deallocate(void*);
struct Struct_0083e560
{
    void FUN_0083e1d0();
    void* FUN_0083e560(unsigned int);
};
// Calls FUN_0083e1d0, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x0083e560
void* Struct_0083e560::FUN_0083e560(unsigned int flags)
{
    FUN_0083e1d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0083f0d0_shell
{
    char _pad[0x25];
    char f25;
    int FUN_0083f0d0();
};
// Returns 1 if bit 0x10 of f25 is set, otherwise 2 plus 1 when bit 0x20 is set.
// @fnv 0x0083f0d0
int FUN_0083f0d0_shell::FUN_0083f0d0()
{
    return (f25 & 0x10) ? 1 : (((f25 & 0x20) != 0) + 2);
}

struct G2
{
    void AddHead(int*&);
};
struct Owner83F1A0
{
    int _pad;
    G2 _list;
    void AddHeadIfNotNull(int*);
};
// @fnv 0x0083f1a0
void Owner83F1A0::AddHeadIfNotNull(int* a1)
{
    if (a1)
    {
        _list.AddHead(a1);
    }
}

class Actor : public TESObjectREFR
{
};

struct ActorProxy
{
    bool HasNoRumors();
};

struct FUN_00619df0_shell
{
    bool FUN_00619df0();
    TESTopicInfo* FUN_0061a790(bool* apbFlag, TESObjectREFR* apSpeaker, PlayerCharacter* apPlayer, int a4,
                               TESTopic* apTopic, int a6);
    TESQuest* FindQuestForTopicInfo(TESTopicInfo* apInfo);
};

struct FUN_0042df90_shell
{
    MenuTopic* FUN_0042df90(TESObjectREFR* apRef);
    void FUN_0042dee0(MenuTopic* apTopic);
};
FUN_0042df90_shell* __fastcall FUN_005d43c0(TESObjectREFR* apRef);

struct FUN_0083e0c0_shell
{
    bool HasCur();
};

struct FUN_00619b20_shell
{
    bool FUN_00619b20();
};

struct FUN_009611e0_shell
{
    FUN_00619b20_shell* FUN_009611e0();
};

struct FUN_005f65d0_list
{
    bool FUN_005f65d0(MenuTopic*& arpTopic);
    void SortItems(int (*apCompare)(FUN_0083f110_topic*, FUN_0083f110_topic*));
};

struct FUN_00425ff0
{
    ~FUN_00425ff0();
};

struct FUN_0083ed50_ref
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12(unsigned int auiFlags);
};

struct FUN_0083ed50_shell : public TopicMenuController
{
    void BuildMenuTopics(BSSimpleList<TESTopic*>* apList, bool abFlag, bool abNoSort, TESTopic* apTopic);
};

// Iterates a TESTopic list, filters by flag and type against an actor value, builds MenuTopic entries, adds new ones to the list, and optionally sorts it.
// @fnv 0x0083ed50
void FUN_0083ed50_shell::BuildMenuTopics(BSSimpleList<TESTopic*>* apList, bool abFlag, bool abNoSort, TESTopic* apTopic)
{
    bool bStateChanged = false;
    Actor* pActorCur = dynamic_cast<Actor*>(m_pDialogueSpeaker);
    while (apList && apList->GetItem())
    {
        TESTopic* pTopic = apList->GetItem();
        apList = apList->GetNext();
        if (abFlag && !((FUN_0083de60_shell*)pTopic)->FUN_0083de60())
            continue;
        if (!abFlag && ((FUN_0083de60_shell*)pTopic)->FUN_0083de60())
            continue;

        int iTypeValue = ((FUN_0083f0d0_shell*)pTopic)->FUN_0083f0d0();
        if (((MenuTopicPlayer*)g_thePlayer)->actorValues.GetActorValue(9) <= *g_011d0dc8.Int())
        {
            if (iTypeValue == 3)
                continue;
        }
        else
        {
            if (iTypeValue == 1)
                continue;
        }

        if (((FUN_00619df0_shell*)pTopic)->FUN_00619df0() && !((ActorProxy*)pActorCur)->HasNoRumors())
        {
            MenuTopic* pExisting = 0;
            pExisting = FUN_005d43c0(m_pDialogueSpeaker)->FUN_0042df90(m_pDialogueSpeaker);
            if (pExisting && !bStateChanged)
            {
                if (((FUN_0083e0c0_shell*)pExisting)->HasCur() && !bStateChanged &&
                    !((FUN_005f65d0_list*)FUN_0083f260())->FUN_005f65d0(pExisting))
                    FUN_0083f260()->AddTail(pExisting);
                bStateChanged = true;
            }
        }

        bool bChoice = false;
        TESTopicInfo* pInfo =
            ((FUN_00619df0_shell*)pTopic)->FUN_0061a790(&bChoice, m_pDialogueSpeaker, g_thePlayer, 0, apTopic, 0);
        if (pInfo)
        {
            TESQuest* pQuest4 = ((FUN_00619df0_shell*)pTopic)->FindQuestForTopicInfo(pInfo);
            bool bSave = false;
            bool bCreate5 = true;
            if (((FUN_00619df0_shell*)pTopic)->FUN_00619df0())
            {
                if (!bStateChanged && !((ActorProxy*)pActorCur)->HasNoRumors())
                    bSave = true;
                else
                    bCreate5 = false;
            }
            MenuTopic* pMenuTopic = 0;
            if (bCreate5)
                pMenuTopic = new MenuTopic(pQuest4, pTopic, pInfo, (MobileObject*)m_pDialogueSpeaker, bChoice);
            if (bCreate5 && ((FUN_0083e0c0_shell*)pMenuTopic)->HasCur() &&
                !((FUN_005f65d0_list*)FUN_0083f260())->FUN_005f65d0(pMenuTopic))
            {
                FUN_0083f260()->AddTail(pMenuTopic);
            }
            else if (pMenuTopic)
            {
                delete (FUN_00425ff0*)pMenuTopic;
                pMenuTopic = 0;
            }
            if (bSave && pMenuTopic && !((FUN_009611e0_shell*)pMenuTopic)->FUN_009611e0()->FUN_00619b20())
            {
                FUN_005d43c0(m_pDialogueSpeaker)->FUN_0042dee0(pMenuTopic);
                ((FUN_0083ed50_ref*)m_pDialogueSpeaker)->v12(0x80000000);
            }
        }
    }
    if (!abNoSort)
        ((FUN_005f65d0_list*)FUN_0083f260())->SortItems(FUN_0083f110);
}

struct LoadHeader
{
    unsigned int formID;
    unsigned char kind;
    unsigned char flagsLow, flagsByte1, flagsByte2, flagsHigh;
    unsigned char version;
};
struct TopicLoader
{
    bool IsLoading();
    void Read(void*, unsigned int);
    void ReadID(unsigned int*, unsigned int);
    LoadHeader* Header();
    unsigned int Position();
    unsigned char Version();
};

TESForm* GetFormByID(unsigned int);
void FNV_Warning(const char*, ...);
void* memset(void*, int, unsigned int);
struct TopicText : BSStringT<char>
{
    bool Set(const char*, unsigned int);
};
struct TopicLoad : MenuTopic
{
    void LoadFromSave(void*);
};
// @fnv 0x0083f680
void TopicLoad::LoadFromSave(void*)
{
    unsigned int uiChunkType, infoID, topicID;
    {
        unsigned short start = 0;
        unsigned int chunkSize = 0;
        if (((TopicLoader*)g_TESSaveLoadGame)->IsLoading())
        {
            unsigned int tag;
            ((TopicLoader*)g_TESSaveLoadGame)->Read(&tag, 4);
            if (tag != 0x424c4f4b)
            {
                LoadHeader* header = ((TopicLoader*)g_TESSaveLoadGame)->Header();
                if (header)
                {
                    TESForm* form = GetFormByID(header->formID);
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x305,
                        header->formID, form->GetName(), header->version, *(unsigned int*)&header->flagsLow);
                }
                else
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x305,
                        ((TopicLoader*)g_TESSaveLoadGame)->Version());
            }
            chunkSize = ((TopicLoader*)g_TESSaveLoadGame)->Position();
            ((TopicLoader*)g_TESSaveLoadGame)->Read(&start, 2);
        }
        char text[260];
        memset(text, 0, 260);
        unsigned char length;
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&length, 1);
        if (length)
        {
            ((TopicLoader*)g_TESSaveLoadGame)->Read(text, length);
            ((TopicText*)&m_kPrompt)->Set(text, 0);
        }
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&m_bFirstFlag, 1);
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&m_bIsRemappedRumor, 1);
        ((TopicLoader*)g_TESSaveLoadGame)->Read(&m_bInfoHasBeenRead, 1);
        ((TopicLoader*)g_TESSaveLoadGame)->ReadID(&uiChunkType, 4);
        pQuest = dynamic_cast<TESQuest*>(GetFormByID(uiChunkType));
        ((TopicLoader*)g_TESSaveLoadGame)->ReadID(&infoID, 4);
        pTopic = dynamic_cast<TESTopic*>(GetFormByID(infoID));
        ((TopicLoader*)g_TESSaveLoadGame)->ReadID(&topicID, 4);
        pInfo = dynamic_cast<TESTopicInfo*>(GetFormByID(topicID));
        if (((TopicLoader*)g_TESSaveLoadGame)->IsLoading())
        {
            unsigned int end = ((TopicLoader*)g_TESSaveLoadGame)->Position();
            LoadHeader* current = ((TopicLoader*)g_TESSaveLoadGame)->Header();
            if (current)
            {
                TESForm* form2 = GetFormByID(current->formID);
                if (end > chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        end - (chunkSize + start),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        current->formID, form2->GetName(), current->version, *(unsigned int*)&current->flagsLow);
                else if (end < chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        chunkSize + start - end,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        current->formID, form2->GetName(), current->version, *(unsigned int*)&current->flagsLow);
            }
            else
            {
                if (end > chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        end - (chunkSize + start),
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        ((TopicLoader*)g_TESSaveLoadGame)->Version());
                else if (end < chunkSize + start)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        chunkSize + start - end,
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x329,
                        ((TopicLoader*)g_TESSaveLoadGame)->Version());
            }
        }
    }
}

class MenuTopic;
class TESTopic;
class TESTopicInfo;
class TESQuest;
class MobileObject;
class PlayerCharacter;

extern "C" char DAT_0107dd28;

class SpeakerVt
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
    virtual bool v63();
    virtual bool v64();
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
    virtual int v209(void* a, int b);
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
    virtual void v280(void* a, float b);
    void LoadRecord(void* p);
};

struct InfoShell
{
    bool IsChallengeFlagSet();
    void MarkAsRefusal();
    bool FUN_00619b20();
    bool IsSayOnceADay();
    int FUN_0061f2b0();
    int GetType();
};

struct TopicShell
{
    TESTopicInfo* FUN_0061a790(char* a, void* b, void* c, int d, int e, int f);
    TESQuest* FindQuestForTopicInfo(TESTopicInfo* p);
};

struct ProcShell
{
    int GetProcessLevel();
};

struct MenuList
{
    void AddTail(MenuTopic*& item);
    void AddTail(MenuTopic* const& item);
};

struct ListShell
{
    void FUN_00905330();
};

class FloatSetting
{
  public:
    float* Float();
};
extern FloatSetting g_011d0a24;

class AvOwner
{
  public:
    float FUN_0066ef50(int a);
};
class MenuPlayer
{
  public:
    char pad[0xa4];
    AvOwner actorValues;
};

int FUN_006705b0(int a, int b);
unsigned int DialogueRandom();
int FUN_005b5e40(int a, const char* b);
int FUN_004d5c60(int a);
TESTopic* GetTopicSubTypeName(int a, int b);
float FUN_00648f60(int a);
int ComputeWeightedValue(float a, float b, int c);

class Mgr
{
  public:
    void* m_pCurrentTopicList;
    void* m_kTopicListStack[2];
    SpeakerVt* m_pDialogueSpeaker;
    bool m_bControllerFlag;
    char pad[3];
    int m_iTopicIndex;
    MenuTopic* FUN_0083e4f0();
    void FUN_0083e370(int a);
    void AddHeadIfNotNull(void* p);
    ListShell* FUN_0083f260(MenuTopic** p);
    bool CheckTopicInfoChance(MenuTopic* pTopic);
};

// @fnv 0x0083e850
bool Mgr::CheckTopicInfoChance(MenuTopic* pTopic)
{
    if (pTopic && ((InfoShell*)pTopic->GetTopicInfo())->IsChallengeFlagSet())
    {
        int iChance2 = ComputeWeightedValue(((MenuPlayer*)g_thePlayer)->actorValues.FUN_0066ef50(0x2b),
                                            m_pDialogueSpeaker->v64() ? (float)m_pDialogueSpeaker->v209(g_thePlayer, 0)
                                                                      : *g_011d0a24.Float(),
                                            ((InfoShell*)pTopic->GetTopicInfo())->FUN_0061f2b0());
        int iRoll5 = DialogueRandom() % 100;
        if (iRoll5 >= iChance2)
        {
            m_bControllerFlag = true;
            FUN_004d5c60(0x1f);
            char _flag;
            TESTopic* pT2 = GetTopicSubTypeName(0, 0xb);
            TESTopicInfo* pInfo = ((TopicShell*)pT2)
                                      ->FUN_0061a790(&_flag, m_pDialogueSpeaker, g_thePlayer, 0,
                                                     ((ProcShell*)pTopic)->GetProcessLevel(), 0);
            if (!pInfo)
            {
                FUN_005b5e40(6, (const char*)&DAT_0107dd28);
            }
            else
            {
                BSSimpleList<MenuTopic*>* pList = new BSSimpleList<MenuTopic*>;
                MenuTopic* pNew = new MenuTopic(((TopicShell*)pT2)->FindQuestForTopicInfo(pInfo), pT2, pInfo,
                                                (MobileObject*)m_pDialogueSpeaker, false);
                pNew->FillResponseList();
                ((InfoShell*)pTopic->GetTopicInfo())->MarkAsRefusal();
                if (((InfoShell*)pTopic->GetTopicInfo())->FUN_00619b20() ||
                    ((InfoShell*)pTopic->GetTopicInfo())->IsSayOnceADay())
                {
                    if (((InfoShell*)pTopic->GetTopicInfo())->IsSayOnceADay() && m_pDialogueSpeaker->v63())
                    {
                        SpeakerVt* pSpk7 = m_pDialogueSpeaker;
                        pSpk7->LoadRecord(pTopic->GetTopicInfo());
                    }
                    FUN_0083f260(&pTopic)->FUN_00905330();
                }
                ((MenuList*)pList)->AddTail(FUN_0083e4f0());
                ((MenuList*)pList)->AddTail(pNew);
                AddHeadIfNotNull(pList);
                FUN_0083e370(1);
            }
            if (m_pDialogueSpeaker->v64())
                m_pDialogueSpeaker->v280(g_thePlayer, FUN_00648f60(iChance2));
        }
        else
        {
            m_iTopicIndex = FUN_006705b0(4, ((InfoShell*)pTopic->GetTopicInfo())->GetType() - 1);
        }
    }
    return m_bControllerFlag;
}

namespace fnv_0083f3e0 {
template <class T> unsigned int BSStringLength(const T* pString);

struct SaveFormHeader83f3
{
    unsigned int auiFormId;
    unsigned char ucType;
    unsigned char aucFlags[4];  // unaligned (byte-packed) change flags
};

struct TESSaveLoadGame
{
    char* FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void* pData, int iSize);
    void FUN_00857a10(void* pData, int iSize);
    SaveFormHeader83f3* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    bool* FUN_00408d60();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct NamedForm83f3
{
    unsigned int FUN_0084e3a0();
};

TESForm* __cdecl LookupFormByID(unsigned int auiFormId);
void __cdecl FUN_0040fbe0(const char* pcFormat, ...);
void __cdecl FUN_005b5e40(const char* pcFormat, ...);

class MenuTopic83f3 : public MenuTopic
{
  public:
    void SaveTopic();
};

// Writes a BLOK record for this topic to the save stream: text length and string, three bytes, quest/topic/info form IDs, and patches the block size.
// @fnv 0x0083f3e0
void MenuTopic83f3::SaveTopic()
{
    unsigned short usLen = 0;
    char* pcSizeLoc = 0;
    char* pcStart = g_TESSaveLoadGame->FUN_00825c00();
    if (*g_011de4e8.FUN_00408d60())
        pcStart = g_TESSaveLoadGame->FUN_00825c00();
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        unsigned int uiTag = 'BLOK';
        g_TESSaveLoadGame->FUN_008579b0(&uiTag, 4);
        pcSizeLoc = g_TESSaveLoadGame->FUN_00825c00();
        g_TESSaveLoadGame->FUN_008579b0(&usLen, 2);
    }
    const char* pcTopic = m_kPrompt.String();
    unsigned char ucTextLen = BSStringLength(pcTopic);
    g_TESSaveLoadGame->FUN_008579b0(&ucTextLen, 1);
    if (ucTextLen)
        g_TESSaveLoadGame->FUN_008579b0((void*)pcTopic, ucTextLen);
    g_TESSaveLoadGame->FUN_008579b0(&m_bFirstFlag, 1);
    g_TESSaveLoadGame->FUN_008579b0(&m_bIsRemappedRumor, 1);
    g_TESSaveLoadGame->FUN_008579b0(&m_bInfoHasBeenRead, 1);
    unsigned int uiQuestID = 0;
    if (pQuest)
        uiQuestID = ((NamedForm83f3*)pQuest)->FUN_0084e3a0();
    g_TESSaveLoadGame->FUN_00857a10(&uiQuestID, 4);
    unsigned int uiID2 = 0;
    if (pTopic)
        uiID2 = ((NamedForm83f3*)pTopic)->FUN_0084e3a0();
    g_TESSaveLoadGame->FUN_00857a10(&uiID2, 4);
    unsigned int uiResp = 0;
    if (pInfo)
        uiResp = ((NamedForm83f3*)pInfo)->FUN_0084e3a0();
    g_TESSaveLoadGame->FUN_00857a10(&uiResp, 4);
    if (*g_011de4e8.FUN_00408d60())
    {
        char* pcEnd = g_TESSaveLoadGame->FUN_00825c00();
        SaveFormHeader83f3* pkHeader = g_TESSaveLoadGame->FUN_004fd3e0();
        if (pkHeader)
        {
            TESForm* pkForm = LookupFormByID(pkHeader->auiFormId);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         pcEnd - pcStart, pkHeader->auiFormId, pkForm->GetName(), *(unsigned int*)pkHeader->aucFlags,
                         0x2ff, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
        }
        else
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", pcEnd - pcStart, 0x2ff,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp");
    }
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        char* pcNow = g_TESSaveLoadGame->FUN_00825c00();
        char* pcMark = pcSizeLoc;
        if (pcNow > pcMark + 0xffff)
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\MenuTopic.cpp", 0x2ff);
        *(unsigned short*)pcSizeLoc = pcNow - pcMark;
    }
}
}  // namespace fnv_0083f3e0

struct TESResponse;
struct TESResponseList
{
    TESResponse* QResponseList();
    void AddTail(TESResponse*);
    void Remove(TESResponse*);
    unsigned int GetListCount();
    void ClearResponses();
    void SetResponseList(TESResponse*);
    void ResetFaceGen();
    void InsertBefore(TESResponse*, TESResponse*);
    void InsertAfter(TESResponse*, TESResponse*);
    void* __vecDelDtor(unsigned int);
    TESResponse* pHead;
};
typedef char _sizecheck_ResponseListWrapper[sizeof(TESResponseList) == 4 ? 1 : -1];
struct FUN_0083df80_shell : public MenuTopic
{
    void FUN_0083df80(TESObjectREFR*);
};

struct TESResponse;

struct TESResponse
{
    int GetLength();
    TESResponse* GetNext();
};
struct ResponseFillList : TESResponseList
{
    ResponseFillList();
    ~ResponseFillList();
    operator TESResponse*() const;
};
struct FUN_0061e760_shell
{
    TESResponseList* FUN_0061e760(TESResponseList*);
};
struct TESIdleForm;
class DialogueResponse
{
  public:
    DialogueResponse(TESQuest*, TESTopic*, TESTopicInfo*, TESObjectREFR*, TESResponse*);
    BSStringT<char> m_kResponseText;
    unsigned int eEmotion;
    unsigned int m_uiEmotionValue;
    BSStringT<char> m_kResponseNotes;
    TESIdleForm* m_pFirstIdleForm;
    TESIdleForm* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESTopicInfo* pInfo;
    TESQuest* pQuest;
};
struct ResponseFillOwner : MenuTopic
{
    void FUN_0083df80(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker);
};

// Iterates the response list obtained from pInfo and appends eligible DialogueResponse entries to m_kResponseList.
// @fnv 0x0083df80
void ResponseFillOwner::FUN_0083df80(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo,
                                     TESObjectREFR* apSpeaker)
{
    ResponseFillList lResponseList;
    int i;
    TESResponse* presponse;

    ((FUN_0061e760_shell*)pInfo)->FUN_0061e760(&lResponseList);
    presponse = lResponseList;
    i = 0;
    while (presponse)
    {
        if (presponse->GetLength() && (!m_bIsRemappedRumor || i == 0))
        {
            ::DialogueResponse* pMenuResponse = reinterpret_cast< ::DialogueResponse*>(
                new DialogueResponse(apQuest, apTopic, apInfo, apSpeaker, presponse));
            m_kResponseList.AddTail(pMenuResponse);
            i++;
        }
        presponse = presponse->GetNext();
    }
}
