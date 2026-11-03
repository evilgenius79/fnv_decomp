// fallout_shared/testopic.cpp: TESTopic, NavShell2, TopicFlagStandIn, TopicSaver and more (49 functions)

#include "TESTopic.h"
#include "TESTopicInfo.h"
#include "TESQuest.h"
#include "QuestDialogueInfo.h"
#include "INFO_LINK_ELEMENT.h"
#include "TESTopicInfoData.h"
#include "DialogueItem.h"
#include "MobileObject.h"
#include "PlayerCharacter.h"
#include "game_constants.h"
extern PlayerCharacter* g_thePlayer;
extern unsigned int DialogueRandom();

// @fnv 0x0061a790
TESTopicInfo* TESTopic::FindMatchingTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener,
                                              bool filter, TESTopic* previousTopic,
                                              BSSimpleList<DialogueItem*>* history)
{
    return FindMatchingTopicInfo(this, deferred, speaker, listener, filter, previousTopic, history);
}

// Picks a TESTopicInfo from the topic's quest info lists, honoring conditions, history, filters and random selection, and reports deferred info via deferred.
// Scans quest topic info for dialogue candidates, applies link and history checks, and may return a deferred or randomly selected candidate.
// @fnv 0x0061a7d0
TESTopicInfo* TESTopic::FindMatchingTopicInfo(const TESTopic* originalTopic, bool& deferred, TESObjectREFR* speaker,
                                              TESObjectREFR* listener, bool filter, TESTopic* previousTopic,
                                              BSSimpleList<DialogueItem*>* history)
{
    const TESTopic* pTopic = originalTopic;
    if (pTopic && pTopic->IsRemappedRumors())
        pTopic = GetAudioBackendData(DIALOGUE_TYPE_DT_CONVERSATION, kRemappedRumorsSubtype);
    deferred = false;
    if (!pTopic || pTopic->IsDeleted())
        return 0;
    TESTopicInfo* usedCandidate = 0;
    BSSimpleList<TESTopicInfo*> listRandomInfos;
    unsigned int randomCount = 0;
    bool bWasPlaying = false;
    BSSimpleList<QuestDialogueInfo*>* pQuestInfoList = pTopic->GetQuestInfoList();
    TESTopicInfo* lastDeferredInfo = 0;
    while (pQuestInfoList && pQuestInfoList->GetItem() && !bWasPlaying)
    {
        QuestDialogueInfo* questInfo = pQuestInfoList->GetItem();
        TESQuest* quest = questInfo->pQuest;
        pQuestInfoList = pQuestInfoList->GetNext();
        if (quest && quest->GetEnabled() && quest->GetConditions()->ContainsTrait(speaker, listener))
        {
            TopicInfoArray sortedArray;
            TopicInfoArray* pSourceArray = questInfo->GetInfoArray();
            unsigned int sourceCount = pSourceArray->GetSize();
            for (unsigned int sourceIndex = 0; sourceIndex < sourceCount; sourceIndex++)
                sortedArray.Add(pSourceArray->GetAt(sourceIndex));
            unsigned int linkSize = questInfo->m_kInfoLinks.GetSize();
            for (unsigned int linkIndex = 0; linkIndex < linkSize; linkIndex++)
            {
                if (questInfo->m_kInfoLinks.GetAt(linkIndex).pInfo)
                {
                    int desiredIndex = questInfo->m_kInfoLinks.GetAt(linkIndex).m_iIndex;
                    if (desiredIndex < 0 || static_cast<unsigned int>(desiredIndex) > sortedArray.GetSize())
                        desiredIndex = sortedArray.GetSize();
                    sortedArray.InsertInfoAt(desiredIndex, questInfo->m_kInfoLinks.GetAt(linkIndex).pInfo);
                }
            }
            unsigned int currentIndex = 0;
            TESTopicInfo* pTopicInfo = 0;
            if (sortedArray.GetSize() > currentIndex)
                pTopicInfo = sortedArray.GetAt(currentIndex);
            while (pTopicInfo)
            {
                bool bDeferred = false;
                bool bAllowed = true;
                if (pTopicInfo && pTopicInfo->IsSayOnceADay() && speaker->IsMobileObject())
                {
                    MobileObject* mobileSpeaker = static_cast<MobileObject*>(speaker);
                    if (mobileSpeaker->HasSaidTopicInfo(pTopicInfo))
                        bAllowed = false;
                }
                if (pTopicInfo && bAllowed && pTopicInfo->IsInfoValidForDialogue(bDeferred, 0, speaker, listener))
                {
                    deferred = false;
                    bool select = true;
                    if (filter || (previousTopic && previousTopic->GetDialogueType() == DIALOGUE_TYPE_DT_TOPIC))
                    {
                        TESTopicInfoData* conversationData = pTopicInfo->GetConversationData();
                        if (conversationData)
                        {
                            if (previousTopic)
                            {
                                select = false;
                                BSSimpleList<TESTopic*>* topicNode = conversationData->GetLinkFromList();
                                while (topicNode && !topicNode->IsEmpty())
                                {
                                    if (topicNode->GetItem() == previousTopic ||
                                        topicNode->GetItem()->GetFormID() == kAnyPreviousTopicFormID)
                                    {
                                        select = true;
                                        break;
                                    }
                                    topicNode = topicNode->GetNext();
                                }
                                if (!filter && topicNode && topicNode->IsEmpty())
                                    select = true;
                            }
                            else if (!conversationData->GetLinkFromList()->IsEmpty() && listener != g_thePlayer)
                                select = false;
                        }
                        if (select)
                        {
                            if (pTopicInfo->IsRandomEnd())
                                bWasPlaying = true;
                            BSSimpleList<DialogueItem*>* historyNode = history;
                            while (historyNode && !historyNode->IsEmpty())
                            {
                                DialogueItem* dialogue = historyNode->GetItem();
                                if (dialogue->GetInfo() == pTopicInfo)
                                {
                                    usedCandidate = pTopicInfo;
                                    select = false;
                                    break;
                                }
                                if (!questInfo->pQuest->GetAllowRepeatedTopics() &&
                                    dialogue->GetQuest() == questInfo->pQuest &&
                                    dialogue->GetAudioBackendData() == originalTopic)
                                {
                                    usedCandidate = pTopicInfo;
                                    select = false;
                                    break;
                                }
                                historyNode = historyNode->GetNext();
                            }
                        }
                    }
                    if (select)
                    {
                        if (pTopicInfo->IsRandomEnd())
                            bWasPlaying = true;
                        if (listRandomInfos.IsEmpty() && !pTopicInfo->IsRandom())
                            return pTopicInfo;
                        else
                        {
                            if (!pTopicInfo->IsRandom())
                            {
                                bWasPlaying = true;
                                break;
                            }
                            else
                            {
                                listRandomInfos.AddHead(pTopicInfo);
                                randomCount++;
                            }
                        }
                    }
                }
                if (!filter && bDeferred)
                {
                    lastDeferredInfo = pTopicInfo;
                    deferred = true;
                }
                if (bWasPlaying)
                    break;
                currentIndex++;
                if (currentIndex < sortedArray.GetSize())
                    pTopicInfo = sortedArray.GetAt(currentIndex);
                else
                    pTopicInfo = 0;
            }
        }
    }
    if (listRandomInfos.IsEmpty())
    {
        if (filter)
            return 0;
        else
            return lastDeferredInfo;
    }
    else
    {
        int randomChoice = randomCount ? DialogueRandom() % randomCount + 1 : 0;
        int seen = 0;
        BSSimpleList<TESTopicInfo*>* pCandidate = &listRandomInfos;
        TESTopicInfo* result = 0;
        TESTopicInfo* pSelectedInfo = 0;
        while (seen < randomChoice && pCandidate)
        {
            pSelectedInfo = pCandidate->GetItem();
            if (pSelectedInfo)
            {
                result = pSelectedInfo;
                seen++;
            }
            pCandidate = pCandidate->GetNext();
        }
        listRandomInfos.RemoveAll();
        return result;
    }
}

struct TESObject
{
    TESObject* GetNext();
    int _FNV_GetFormType();
};
struct FUN_00616f40_shell
{
    bool BuildVoiceFilePath(TESObject* o, int a, int b, int c, int d);
    bool DispatchOnNextFormType(TESObject* obj, int a, int b, int c, int d);
};
// If obj is non-null and its next object's form type is 0x16, 0x2a or 0x2b, forwards that next object to BuildVoiceFilePath; otherwise returns false.
// @fnv 0x00616f40
bool FUN_00616f40_shell::DispatchOnNextFormType(TESObject* obj, int a, int b, int c, int d)
{
    if (obj)
    {
        switch (obj->GetNext()->_FNV_GetFormType())
        {
        case 0x16:
        case 0x2a:
        case 0x2b:
            return BuildVoiceFilePath(obj->GetNext(), a, b, c, d);
        }
    }
    return false;
}

struct FUN_00619010_shell : public TESTopic
{
    void FUN_00619010(char*);
};

// @fnv 0x00619010
void FUN_00619010_shell::FUN_00619010(char* apPrompt)
{
    m_kDummyPrompt.Set(apPrompt, 0);
}

// @fnv 0x00619410
bool __fastcall FUN_00619410(const char* pFlags)
{
    return (bool)(pFlags[0x25] & 2);
}

struct FUN_006195d0_shell : public TESTopic
{
    QuestDialogueInfo* GetOrCreateQuestInfo(TESQuest*, bool);
};

void* __cdecl operator new(unsigned int);
QuestDialogueInfo* __fastcall FUN_00619740(void*);

struct QuestInfoStub : public QuestDialogueInfo
{
    QuestInfoStub()
    {
        FUN_00619740(this);
    }
};

// Searches the quest info list for an entry matching apQuest, creating and appending a new entry if none is found.
// @fnv 0x006195d0
QuestDialogueInfo* FUN_006195d0_shell::GetOrCreateQuestInfo(TESQuest* apQuest, bool abReSort)
{
    if (!apQuest)
        return 0;

    BSSimpleList<QuestDialogueInfo*>* pList = GetQuestInfoList();
    QuestDialogueInfo* pQuestInfo = 0;

    while (pList && pList->GetItem() && !pQuestInfo)
    {
        pQuestInfo = pList->GetItem();
        pList = pList->GetNext();
        if (pQuestInfo->bInitialized)
        {
            if ((!pQuestInfo->pQuest || pQuestInfo->pQuest->GetFormID() != (unsigned int)apQuest) &&
                (!pQuestInfo->m_pAlternateQuest || pQuestInfo->m_pAlternateQuest->GetFormID() != (unsigned int)apQuest))
            {
                pQuestInfo = 0;
            }
        }
        else
        {
            if (pQuestInfo && pQuestInfo->pQuest != apQuest && pQuestInfo->m_pAlternateQuest != apQuest)
            {
                pQuestInfo = 0;
            }
        }
    }

    if (!pQuestInfo)
    {
        pQuestInfo = new QuestDialogueInfo;
        pQuestInfo->pQuest = apQuest;
        GetQuestInfoList()->AddTail(pQuestInfo);
    }

    return pQuestInfo;
}

struct FUN_00619a70_shell : public TESTopicInfo
{
    unsigned short FUN_00619a70();
};

// @fnv 0x00619a70
unsigned short FUN_00619a70_shell::FUN_00619a70()
{
    return *(unsigned short*)((char*)this + 0x20);
}

struct FUN_00619b20_shell : public TESTopicInfo
{
    bool FUN_00619b20();
};

// @fnv 0x00619b20
bool FUN_00619b20_shell::FUN_00619b20()
{
    return (bool)(*reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x25) & 4);
}

struct FUN_00619d00_shell : public TESTopic
{
    TESQuest* FindQuestForTopicInfo(TESTopicInfo*);
};

extern TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo*, unsigned int);
extern BSSimpleList<QuestDialogueInfo*>* __fastcall _ref_00726070(const BSSimpleList<QuestDialogueInfo*>*);

// Searches the topic's quest info list for apInfo and returns the owning quest, recursing into the remapped rumor topic when applicable.
// @fnv 0x00619d00
TESQuest* FUN_00619d00_shell::FindQuestForTopicInfo(TESTopicInfo* apInfo)
{
    if (!apInfo)
        return 0;

    if (IsRemappedRumors())
        return reinterpret_cast<FUN_00619d00_shell*>(TESTopic::GetAudioBackendData(DIALOGUE_TYPE_DT_CONVERSATION, 5))
            ->FindQuestForTopicInfo(apInfo);

    const BSSimpleList<QuestDialogueInfo*>* pList = GetQuestInfoList();
    unsigned int maxSize = 0;

    while (
        pList &&
        *reinterpret_cast<QuestDialogueInfo**>(
            reinterpret_cast<TESTopicInfoData*>(const_cast<BSSimpleList<QuestDialogueInfo*>*>(pList))->GetLinkFromList()))
    {
        QuestDialogueInfo* pQuestInfo = *reinterpret_cast<QuestDialogueInfo**>(
            reinterpret_cast<TESTopicInfoData*>(const_cast<BSSimpleList<QuestDialogueInfo*>*>(pList))->GetLinkFromList());
        pList = _ref_00726070(pList);

        maxSize = reinterpret_cast<TESForm*>(pQuestInfo->GetInfoArray())->GetFormID();
        if (maxSize)
        {
            for (unsigned int i = 0; i < maxSize; ++i)
            {
                TESTopicInfo* pInfo = GetTopicInfoByIndex(pQuestInfo, i);
                if (pInfo == apInfo)
                    return pQuestInfo->pQuest;
            }
        }
    }

    return 0;
}

struct FUN_00619df0_shell : public TESTopic
{
    bool FUN_00619df0();
};

// @fnv 0x00619df0
bool FUN_00619df0_shell::FUN_00619df0()
{
    return (*((char*)this + 0x25) & 1) ? true : false;
}

TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo* apQuestInfo, unsigned int aiIndex);

struct FUN_00619e10_impl : public TESTopic
{
    TESTopicInfo* FindTopicInfoByFormID(unsigned int aiInfoID, bool abReverse);
};

// Scans the quest info list, searching each info array forward or backward for a TESTopicInfo whose FormID equals aiInfoID, and returns it or null.
// @fnv 0x00619e10
TESTopicInfo* FUN_00619e10_impl::FindTopicInfoByFormID(unsigned int aiInfoID, bool abReverse)
{
    BSSimpleList<QuestDialogueInfo*>* pList = GetQuestInfoList();
    unsigned int maxSize = 0;

    while (pList && pList->GetItem())
    {
        QuestDialogueInfo* pQuestInfo = pList->GetItem();
        pList = pList->GetNext();
        maxSize = pQuestInfo->GetInfoArray()->GetSize();
        if (maxSize != 0)
        {
            if (abReverse)
            {
                for (int i = maxSize - 1; i >= 0; --i)
                {
                    TESTopicInfo* pInfo = GetTopicInfoByIndex(pQuestInfo, i);
                    if (pInfo && pInfo->GetFormID() == aiInfoID)
                    {
                        return pInfo;
                    }
                }
            }
            else
            {
                for (unsigned int i = 0; i < maxSize; ++i)
                {
                    TESTopicInfo* pInfo = GetTopicInfoByIndex(pQuestInfo, i);
                    if (pInfo && pInfo->GetFormID() == aiInfoID)
                    {
                        return pInfo;
                    }
                }
            }
        }
    }
    return 0;
}

// Returns the topic info at aiInfoIndex from apQuestInfo's info array if the index is in range, otherwise returns 0.
// @fnv 0x00619f20
TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo* apQuestInfo, unsigned int aiInfoIndex)
{
    if (!apQuestInfo)
        return 0;

    if (aiInfoIndex >= 0 && aiInfoIndex < ((TESForm*)apQuestInfo->GetInfoArray())->GetFormID())
        return apQuestInfo->GetInfoArray()->GetAt(aiInfoIndex);
    else
        return 0;
}

struct TopicInfoStandin
{
    void FUN_0061f340(unsigned short index);
};
// For each entry in apInfoArray up to its form ID, calls FUN_0061f340 on the entry with its index as a 16-bit value.
// @fnv 0x00619fe0
void FUN_00619fe0(TopicInfoArray* apInfoArray)
{
    if (apInfoArray)
    {
        unsigned int maxSize = ((TESForm*)apInfoArray)->GetFormID();
        for (unsigned int i = 0; i < maxSize; i++)
        {
            TopicInfoStandin* pInfo = (TopicInfoStandin*)apInfoArray->GetAt(i);
            if (pInfo)
            {
                pInfo->FUN_0061f340((unsigned short)i);
            }
        }
    }
}

class AutoMemContext
{
    int dummy;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};

class TESGlobal;
class TESGlobalMap
{
  public:
    void SetAt(const char*, TESGlobal*);
};

struct FullNameEx
{
    int dummy;
    void SetFullName(const char* name);
};

struct TESTopicEx
{
    char pad1[0x14];
    FullNameEx fullName;
    char pad2[0x2c];

    TESTopicEx(int type);

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
    virtual void SetFormID(unsigned int id, bool bUpdate);
    virtual void v75();
    virtual void v76();
    virtual void SetEditorID(const char* id);
};

struct TopicDefaultEntry
{
    TESTopicEx* topic;
    unsigned int formID;
    const char* editorID;
};

struct DataHandlerEx
{
    void AddTopic(TESTopicEx* topic);
};

extern int DAT_0119a41c[];
extern TopicDefaultEntry* DAT_0119a43c[];
extern DataHandlerEx* g_dataHandler;
extern TESGlobalMap* DAT_011c54c8;
const char* __cdecl PrepareScriptMessage(const char*, bool);

// @fnv 0x0061a040
void __cdecl CreateDefaultTopics()
{
    AutoMemContext memContext((MEM_CONTEXT)0x35, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESTopic.cpp", 0x1573);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < DAT_0119a41c[i]; j++)
        {
            if (DAT_0119a43c[i][j].topic == 0)
            {
                DAT_0119a43c[i][j].topic = new TESTopicEx(i);
                DAT_0119a43c[i][j].topic->SetFormID(DAT_0119a43c[i][j].formID, true);
                DAT_0119a43c[i][j].topic->SetEditorID(DAT_0119a43c[i][j].editorID);
                DAT_0119a43c[i][j].topic->fullName.SetFullName(
                    PrepareScriptMessage(DAT_0119a43c[i][j].editorID, false));
                g_dataHandler->AddTopic(DAT_0119a43c[i][j].topic);
                DAT_011c54c8->SetAt(DAT_0119a43c[i][j].editorID, (TESGlobal*)DAT_0119a43c[i][j].topic);
            }
        }
    }
}

namespace fnv_0061a2d0 {
struct TopicSubTypeEntry
{
    const char* name;
    int a;
    int b;
};

extern int DAT_0119a41c[];
extern TopicSubTypeEntry* DAT_0119a43c[];

// Returns the name of the topic sub-type entry at index for the given type, or null if index is out of range.
// @fnv 0x0061a2d0
const char* __cdecl GetTopicSubTypeName(int type, int index)
{
    if (index < 0)
        return 0;
    if (index >= DAT_0119a41c[type])
        return 0;
    return DAT_0119a43c[type][index].name;
}
}  // namespace fnv_0061a2d0

namespace fnv_0061a310 {
class DataHandler;
extern DataHandler* g_dataHandler;

TESTopicInfoData* __fastcall FUN_004612e0(DataHandler* pThis);
TESTopicInfoData* __fastcall _ref_00726070(TESTopicInfoData* pThis);

struct TopicHelper
{
    TESTopicInfo* FindTopicInfoByFormID(unsigned int formID, int arg2);
};

// Walks the data handler's topic list and returns the first TESTopic whose lookup of pInfo's form ID yields pInfo, else null.
// @fnv 0x0061a310
TESTopic* __cdecl FindTopicByInfo(TESTopicInfo* pTopicInfo)
{
    TESTopicInfoData* pList = FUN_004612e0(g_dataHandler);
    while (pList && *(TESTopic**)pList->GetLinkFromList())
    {
        TESTopic* pTopic = *(TESTopic**)pList->GetLinkFromList();
        pList = _ref_00726070(pList);
        if (((TopicHelper*)pTopic)->FindTopicInfoByFormID(pTopicInfo->GetFormID(), 0) == pTopicInfo)
        {
            return pTopic;
        }
    }
    return 0;
}
}  // namespace fnv_0061a310

bool __cdecl FUN_0061a450(TESTopic* pMenuTopicEntry, TESTopic* apTopic, bool abUsePriority);
bool __fastcall _ref_008256d0(void* p);
BSSimpleList<TESTopic*>* __fastcall _ref_00726070(void* p);

struct SoundListView
{
    void AddTail(TESTopic*&);
};

// @fnv 0x0061a380
void __cdecl AddTopicToList(TESTopic* apTopic, BSSimpleList<TESTopic*>* apTopicList, bool abUsePriority)
{
    if (apTopic && apTopicList)
    {
        if (_ref_008256d0(apTopicList))
        {
            ((BSSimpleList<char const*>*)apTopicList)->AddHead((char const*&)apTopic);
        }
        else
        {
            BSSimpleList<TESTopic*>* pCurrentElementNext = apTopicList;
            while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
            {
                TESTopic* pMenuTopicEntry = *(TESTopic**)((TESTopicInfoData*)pCurrentElementNext)->GetLinkFromList();
                if (pMenuTopicEntry == apTopic)
                    break;
                if (FUN_0061a450(pMenuTopicEntry, apTopic, abUsePriority))
                {
                    ((BSSimpleList<char const*>*)pCurrentElementNext)->AddHead((char const*&)apTopic);
                    break;
                }
                if (!_ref_00726070(pCurrentElementNext))
                {
                    ((SoundListView*)pCurrentElementNext)->AddTail(apTopic);
                    break;
                }
                pCurrentElementNext = _ref_00726070(pCurrentElementNext);
            }
        }
    }
}

int __cdecl _stricmp(const char*, const char*);
float __fastcall FUN_00526ae0(TESTopic*);
bool __cdecl FUN_0040eb10(float, float, float);
extern double DAT_01030f28;

// Compares two TESTopic objects by priority (when abUsePriority) or by name, returning whether the first sorts before the second.
// @fnv 0x0061a450
bool __cdecl FUN_0061a450(TESTopic* apTopic1, TESTopic* apTopic2, bool abUsePriority)
{
    if (apTopic1 != 0 && apTopic2 != 0)
    {
        const char* topic1name = apTopic1->GetName();
        const char* topic2name = apTopic2->GetName();
        if (abUsePriority)
        {
            float fPriorityDiff = FUN_00526ae0(apTopic2) - FUN_00526ae0(apTopic1);
            if (fPriorityDiff > DAT_01030f28)
                return true;
            else if (FUN_0040eb10(fPriorityDiff, 0.0f, 0.001f))
            {
                if (*topic1name < *topic2name)
                    return true;
                else
                    return _stricmp(apTopic1->GetName(), apTopic2->GetName()) > 0;
            }
        }
        else
        {
            if (*topic1name < *topic2name)
                return true;
            else
                return _stricmp(apTopic1->GetName(), apTopic2->GetName()) > 0;
        }
    }
    return false;
}

struct FUN_0061a760_shell : public TESTopic
{
    TESTopicInfo* GetTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener);
};
// Returns the topic info for the given speaker and listener by delegating to the topic info lookup with deferred output and no extra filters.
// @fnv 0x0061a760
TESTopicInfo* FUN_0061a760_shell::GetTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener)
{
    return FindMatchingTopicInfo(deferred, speaker, listener, false, 0, 0);
}

// @fnv 0x0061aed0
bool __fastcall IsFlag20Set(char* pThis)
{
    return (bool)(pThis[0x25] & 0x20);
}

__int64 __cdecl __time64(__int64*);

// @fnv 0x0061b9d0
__int64 __cdecl GetTime64(__int64* pTime)
{
    return __time64(pTime);
}

// @fnv 0x0061b9f0
int __fastcall GetSignedByteAtOffset36(signed char* pThis)
{
    return pThis[0x24];
}

namespace fnv_0061ba10 {
struct DataHandlerStandin
{
    TESTopicInfoData* FUN_004612e0();
};
extern DataHandlerStandin* g_dataHandler;
struct TopicStandin
{
    bool HasInfoForQuest(TESQuest* quest, int flag);
    bool SortList();
};
struct ConvStandin
{
    TESTopicInfoData* _ref_00726070();
};
// Walks the data handler's list of topics, testing each against apQuest and calling SortList, returning false as soon as one fails.
// @fnv 0x0061ba10
bool CheckTopicsForQuest(TESQuest* apQuest)
{
    bool result = true;
    TESTopicInfoData* pCurrentElementNext = g_dataHandler->FUN_004612e0();
    while (pCurrentElementNext && *(TopicStandin**)pCurrentElementNext->GetLinkFromList() && result)
    {
        if (!apQuest || (*(TopicStandin**)pCurrentElementNext->GetLinkFromList())->HasInfoForQuest(apQuest, 0))
        {
            result = (*(TopicStandin**)pCurrentElementNext->GetLinkFromList())->SortList();
        }
        pCurrentElementNext = ((ConvStandin*)pCurrentElementNext)->_ref_00726070();
    }
    return result;
}
}  // namespace fnv_0061ba10

struct FUN_0061bcd0_shell : public TESTopic
{
    void FUN_0061bcd0();
};

extern int DAT_01011584;

struct FUN_00619010_helper
{
    void FUN_00619010(int* pData);
};

// Clears the form's data via TESForm::ClearData, then passes DAT_01011584 to FUN_00619010 on this object.
// @fnv 0x0061bcd0
void FUN_0061bcd0_shell::FUN_0061bcd0()
{
    TESForm::ClearData();
    reinterpret_cast<FUN_00619010_helper*>(this)->FUN_00619010(&DAT_01011584);
}

extern int DAT_0104d458;

struct Dummy_0061bf20
{
    int* vtable;
    void FUN_006b3f40(int, int);
};

// Sets the object's vtable to DAT_0104d458, calls FUN_006b3f40(0, 0), and returns the object.
// @fnv 0x0061bf20
Dummy_0061bf20* __fastcall ConstructDummy(Dummy_0061bf20* apObject)
{
    apObject->vtable = &DAT_0104d458;
    apObject->FUN_006b3f40(0, 0);
    return apObject;
}

struct NavMeshPtr
{
    int p;
    ~NavMeshPtr();
};
struct S2f850
{
    unsigned int AppendValue(const NavMeshPtr&);
};
struct NavShell2 : public S2f850
{
    unsigned int FUN_00469500(NavMeshPtr apNavMesh);
};
// Calls AppendValue with apNavMesh and returns its result.
// @fnv 0x00469500
unsigned int NavShell2::FUN_00469500(NavMeshPtr apNavMesh)
{
    unsigned int ireturn = AppendValue(apNavMesh);
    return ireturn;
}

struct TopicFlagStandIn
{
    char pad[0x26];
    char flags;
    bool FUN_0061aef0();
};
// @fnv 0x0061aef0
bool TopicFlagStandIn::FUN_0061aef0()
{
    return (flags & 1) ? true : false;
}

void* __cdecl memset(void*, int, unsigned int);
struct SL
{
    int a;
    int b;
    SL();
    ~SL();
};
struct StrMem
{
    int a;
    int b;
    StrMem();
    ~StrMem();
};
struct SFTX
{
    void SetFormType(int);
};
struct DDX
{
    unsigned char type;
    unsigned char flags;
};
struct SL_d0046ffb0 : SL
{
    ~SL_d0046ffb0();
};
struct FUN_00618580 : public TESForm, public TESFullName
{
    DDX m_Data;
    float m_fTopicParamB;
    SL_d0046ffb0 m_kQuestInfoList;
    StrMem m_kDummyPrompt;
    int m_iTopicFlags;
    StrMem cPrompt2;
    FUN_00618580(unsigned char aType);
    ~FUN_00618580();
};
// @fnv 0x00618580
FUN_00618580::FUN_00618580(unsigned char aType)
{
    memset(&m_Data, 0, sizeof(m_Data));
    m_iTopicFlags = 0;
    m_fTopicParamB = 50.0f;
    m_Data.type = aType;
    ((SFTX*)this)->SetFormType(0x45);
}

namespace fnv_006189c0 {
struct FileStub
{
    bool IsMasterFile();
    void RunProbe(void*);
};
struct DHStub
{
    bool GetByteAt618();
    void FUN_00460270(TESTopicInfo*, bool);
};
extern DHStub* g_dataHandler;
struct Arr
{
    unsigned int* GetAt(int);
};
struct TopicSaver
{
    bool SaveTopicInfo(FileStub* apFile);
};
// @fnv 0x006189c0
bool TopicSaver::SaveTopicInfo(FileStub* apFile)
{
    TESTopicInfo* info;
    unsigned int i4;
    unsigned int aMaxSize;
    TopicInfoArray* pArray;
    QuestDialogueInfo* pQuestInfo;
    bool mastersave;
    BSSimpleList<QuestDialogueInfo*>* pList6;

    ((TESTopic*)this)->SaveForm();
    apFile->RunProbe(this);
    mastersave = g_dataHandler->GetByteAt618();
    pList6 = ((TESTopic*)this)->GetQuestInfoList();
    while (pList6 && pList6->GetItem())
    {
        pQuestInfo = pList6->GetItem();
        pList6 = pList6->GetNext();
        pArray = pQuestInfo->GetInfoArray();
        aMaxSize = ((TESForm*)pArray)->GetFormID();
        for (i4 = 0; i4 < aMaxSize; ++i4)
        {
            info = (TESTopicInfo*)*((Arr*)pArray)->GetAt(i4);
            if (info)
                g_dataHandler->FUN_00460270(info, apFile->IsMasterFile());
        }
    }
    return true;
}
}  // namespace fnv_006189c0

namespace fnv_0061a270 {
extern int DAT_0119a41c[];
extern int* DAT_0119a43c[];

// For each of 8 tables, zeroes the first int of every 12-byte entry up to the table's count in DAT_0119a41c.
// @fnv 0x0061a270
void ClearTableEntries()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < DAT_0119a41c[i]; ++j)
        {
            *(int*)((char*)DAT_0119a43c[i] + j * 12) = 0;
        }
    }
}
}  // namespace fnv_0061a270

struct TESFaction_RankDataView
{
    unsigned char* __thiscall GetRankDataList(void);
};

struct FUN_0061af10_shell : TESFaction_RankDataView
{
    bool HasFlag4();
};

// @fnv 0x0061af10
bool FUN_0061af10_shell::HasFlag4()
{
    return (*GetRankDataList() & 4) != 0;
}

struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct BSStringT_char
{
    int StrCmp(const char*, bool) const;
};
unsigned int __cdecl BSStringLength(const char*);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
extern "C" void* __cdecl _alloca(unsigned int);
struct TESTopic_shell
{
    bool SetStringIfDifferent(const char*);
};
// @fnv 0x006184f0
bool TESTopic_shell::SetStringIfDifferent(const char* apString)
{
    char* p2;
    unsigned int n = BSStringLength(apString) + 1;
    p2 = (char*)_alloca(n);
    TaskQueueInterface::CopyStringToBuffer(p2, n, apString);
    if (((BSStringT_char*)((char*)this + 0x40))->StrCmp(p2, true) == 0)
        return false;
    ((BSStr*)((char*)this + 0x40))->Set(p2, 0);
    return true;
}

struct Holder6186a0
{
    void FUN_006186d0();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_006186d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006186a0
void* Holder6186a0::DestroyIfFlagged(unsigned int flags)
{
    FUN_006186d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
void __cdecl _FUN_00485910(unsigned int, unsigned int);
extern TESTopic* g_loadingTopic;
struct FUN_00618960_obj
{
    char _pad[0x3C];
    unsigned int unk3C;
    void InitLoadingTopic();
};
// @fnv 0x00618960
void FUN_00618960_obj::InitLoadingTopic()
{
    ((FUN_004855a0*)this)->M();
    _FUN_00485910(0x58444958, unk3C);
    g_loadingTopic = (TESTopic*)this;
    ((FUN_00485680*)this)->M();
}

namespace fnv_00619a90 {
struct FUN_00619f70_shell
{
    unsigned int* FindQuestInfoArray(unsigned int);
};
struct FUN_0061f280_shell
{
    void FUN_0061f280();
};
struct FUN_00619b20_shell
{
    bool FUN_00619b20();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct BSTempEffectDebris
{
    bool IsNew();
};
struct FUN_00619a90_shell
{
    void ProcessTopicInfoList(unsigned int param);
};

// Retrieves a list for param, then for each entry calls FUN_00619b20 and, if true and IsNew, calls FUN_0061f280.
// @fnv 0x00619a90
void __thiscall FUN_00619a90_shell::ProcessTopicInfoList(unsigned int param)
{
    unsigned int* list = ((FUN_00619f70_shell*)this)->FindQuestInfoArray(param);
    if (list)
    {
        unsigned int count = ((TESForm*)list)->GetFormID();
        unsigned int i = 0;
        for (; i < count; ++i)
        {
            TESTopicInfo* info = *(TESTopicInfo**)((Arr*)list)->GetAt(i);
            if (info && ((FUN_00619b20_shell*)info)->FUN_00619b20() && ((BSTempEffectDebris*)info)->IsNew())
                ((FUN_0061f280_shell*)info)->FUN_0061f280();
        }
    }
}
}  // namespace fnv_00619a90

namespace fnv_0061a720 {
struct FUN_0061a760_shell
{
    TESTopicInfo* GetTopicInfo(bool&, TESObjectREFR*, TESObjectREFR*);
};
struct FUN_0061a720_shell : FUN_0061a760_shell
{
    TESTopicInfo* FUN_0061a720(MobileObject*, PlayerCharacter*);
};
// Calls GetTopicInfo with speaker and listener; returns its TESTopicInfo unless the deferred flag was set, in which case returns null.
// @fnv 0x0061a720
TESTopicInfo* FUN_0061a720_shell::FUN_0061a720(MobileObject* speaker, PlayerCharacter* listener)
{
    bool deferred = false;
    TESTopicInfo* info;
    info = GetTopicInfo(deferred, speaker, listener);
    if (deferred)
        return 0;
    else
        return info;
}
}  // namespace fnv_0061a720

struct FUN_0061b320_shell : public TESTopic
{
    DialogueItem* FUN_0061b320(TESObjectREFR*, TESObjectREFR*, TESTopic*, void*, bool);
};

struct FUN_0083c520
{
    char data[0x1c];
    FUN_0083c520(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker);
};
struct TopicInfo_Ext
{
    TESQuest* FUN_006733e0();
    void RunResultScript(bool, TESObjectREFR*);
    void FUN_0061f150();
};
bool __fastcall FUN_00579200(char const*);
// @fnv 0x0061b320
DialogueItem* FUN_0061b320_shell::FUN_0061b320(TESObjectREFR* apSpeaker, TESObjectREFR* apTarget,
                                               TESTopic* apPreviousTopic, void* apConversationList, bool abRunImmediate)
{
    bool bIgnoreMe;
    TESTopicInfo* info = FindMatchingTopicInfo(bIgnoreMe, apSpeaker, apTarget, true, apPreviousTopic,
                                               (BSSimpleList<DialogueItem*>*)apConversationList);
    if (info)
    {
        DialogueItem* pDialogueItem =
            (DialogueItem*)new FUN_0083c520(((TopicInfo_Ext*)info)->FUN_006733e0(), this, info, apSpeaker);
        if (abRunImmediate && pDialogueItem && pDialogueItem->GetInfo() &&
            FUN_00579200((char const*)pDialogueItem->GetInfo()))
        {
            ((TopicInfo_Ext*)pDialogueItem->GetInfo())->RunResultScript(false, apSpeaker);
            ((TopicInfo_Ext*)pDialogueItem->GetInfo())->FUN_0061f150();
        }
        return pDialogueItem;
    }
    else
    {
        return 0;
    }
}

namespace fnv_00618aa0 {
extern "C" void* __cdecl _alloca(unsigned int);

struct TESFileRef
{
    int _ref_00472660();
    unsigned int _ref_00401660();
    int _ref_004726b0();
    bool _ref_004726f0();
    bool _ref_004727f0(void*);
    bool _ref_00472890(void*, unsigned int);
};
void __cdecl _ref_00487050(void*, ::TESFile*);

struct ArrSI
{
    unsigned int GetFlags();
};
struct TESConditionItem
{
    void SetObjectType(int);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct NiTLargeArraySetSizeHelper
{
    void SetSize(unsigned int);
};
struct ArrX
{
    void FUN_0061bf70(int, int);
};
struct TopicDefaultEntryX
{
    void* pTopic;
    int unk;
    const char* pName;
};

struct ParentSpaceNode
{
    int a;
    int b;
    int c;
};
struct NavMeshTriangleEdgeReference
{
    int a;
    int b;
    int c;
};
template <> class BSSimpleArray<NavMeshTriangleEdgeReference, 1024>
{
  public:
    unsigned int Add(const NavMeshTriangleEdgeReference&);
};
extern int DAT_0119a41c[];
extern void* DAT_0119a43c[];
typedef BSSimpleArray<ParentSpaceNode, 1024> PSNArr;
BSSimpleList<QuestDialogueInfo*>* __fastcall _ref_00726070(const BSSimpleList<QuestDialogueInfo*>*);
struct FUN_006195d0_shell : public TESTopic
{
    QuestDialogueInfo* GetOrCreateQuestInfo(TESQuest*, bool);
};
struct FUN_00619010_shell : public TESTopic
{
    void FUN_00619010(char*);
};

extern TESTopic* g_loadingTopic;

struct FUN_00618aa0_t : public TESTopic
{
    bool FUN_00618aa0(::TESFile* pFile);
};

// @fnv 0x00618aa0
bool FUN_00618aa0_t::FUN_00618aa0(::TESFile* pFile)
{
    unsigned char formid = (unsigned char)((TESFileRef*)pFile)->_ref_00472660();
    QuestDialogueInfo* pLastQuestInfo = 0;
    if (formid != 0x45)
        return false;

    LoadRecordHeader(pFile);

    BSSimpleList<QuestDialogueInfo*>* pQuestInfoList = GetQuestInfoList();
    while (pQuestInfoList && *(int*)((TESTopicInfoData*)pQuestInfoList)->GetLinkFromList() != 0)
    {
        QuestDialogueInfo* pQuestInfo = *(QuestDialogueInfo**)((TESTopicInfoData*)pQuestInfoList)->GetLinkFromList();
        if (pQuestInfo)
        {
            ((GlobalObject_00869f00*)((char*)pQuestInfo + 0x1c))->Clear(true);
        }
        pQuestInfoList = (_ref_00726070)(pQuestInfoList);
    }

    int chunkid;
    while ((chunkid = ((TESFileRef*)pFile)->_ref_004726b0()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorID = (char*)_alloca(((TESFileRef*)pFile)->_ref_00401660());
            ((TESFileRef*)pFile)->_ref_00472890(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(pFile);
            break;
        case 0x4c4c5546:
            _ref_00487050(this ? (void*)&tESFullNameComponent : 0, pFile);
            break;
        case 0x49545351: {
            unsigned int uiChunkType = 0;
            ((TESFileRef*)pFile)->_ref_004727f0(&uiChunkType);
            TESForm::RemapFormIDForFile(uiChunkType, GetFile(-1));
            QuestDialogueInfo* pQuestInfo = ((FUN_006195d0_shell*)this)->GetOrCreateQuestInfo((TESQuest*)uiChunkType, false);
            if (pQuestInfo)
            {
                pLastQuestInfo = pQuestInfo;
                unsigned int uiOldSize = ((ArrSI*)pQuestInfo->GetInfoArray())->GetFlags();
                ((NiTLargeArraySetSizeHelper*)pQuestInfo->GetInfoArray())->SetSize(uiOldSize + 100);
                ((TESConditionItem*)pQuestInfo->GetInfoArray())->SetObjectType(10);
            }
            break;
        }
        case 0x43464e49: {
            unsigned int infoID = 0;
            ((TESFileRef*)pFile)->_ref_004727f0(&infoID);
            TESForm::RemapFormIDForFile(infoID, GetFile(-1));
            if (pLastQuestInfo)
            {
                INFO_LINK_ELEMENT infolink;
                infolink.pInfo = 0;
                infolink.nID = infoID;
                infolink.m_iIndex = -1;
                ((BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*)((char*)pLastQuestInfo + 0x1c))
                    ->Add(*(NavMeshTriangleEdgeReference*)&infolink);
            }
            break;
        }
        case 0x58464e49: {
            int m_iIndex = -1;
            ((TESFileRef*)pFile)->_ref_004727f0(&m_iIndex);
            if (pLastQuestInfo)
            {
                int IdxJustAdded;
                if ((IdxJustAdded = ((ArrSI*)((char*)pLastQuestInfo + 0x1c))->GetFlags() - 1) >= 0)
                {
                    *(int*)((char*)&((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(IdxJustAdded) + 8) = m_iIndex;
                    int size = ((ArrSI*)((char*)pLastQuestInfo + 0x1c))->GetFlags();
                    for (int iter = 0; iter < IdxJustAdded; iter++)
                    {
                        if (*(int*)&((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(iter) ==
                            *(int*)&((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(IdxJustAdded))
                        {
                            *(int*)((char*)&((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(iter) + 8) = m_iIndex;
                            ((ArrX*)((char*)pLastQuestInfo + 0x1c))->FUN_0061bf70(IdxJustAdded, 1);
                            break;
                        }
                    }
                }
            }
            break;
        }
        case 0x4d414e50:
            ((TESFileRef*)pFile)->_ref_004727f0(&m_fTopicParamB);
            break;
        case 0x4d554454: {
            char szBuffer[256];
            ((TESFileRef*)pFile)->_ref_00472890(szBuffer, 0x100);
            ((FUN_00619010_shell*)this)->FUN_00619010(szBuffer);
            break;
        }
        case 0x41544144:
            ((TESFileRef*)pFile)->_ref_00472890(&m_Data, 2);
            break;
        case 0x58444958:
            ((TESFileRef*)pFile)->_ref_004727f0(&m_iTopicFlags);
            break;
        }
        if (!((TESFileRef*)pFile)->_ref_004726f0())
            break;
    }

    if (GetFormID() <= 0x7ff)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            for (unsigned int j = 0; j < (unsigned int)DAT_0119a41c[i]; j++)
            {
                if (((TopicDefaultEntryX*)DAT_0119a43c[i])[j].pTopic == this)
                {
                    m_Data.type = (char)i;
                    SetEditorID_AtRuntime(((TopicDefaultEntryX*)DAT_0119a43c[i])[j].pName);
                }
            }
        }
    }

    SetInitializationState(false);
    g_loadingTopic = this;
    return true;
}
}  // namespace fnv_00618aa0

struct FUN_00484020_shell
{
    bool IsLessThan(TESForm*);
};
int __fastcall FNV_GetFormType(TESForm*);
struct FUN_00619430_shell : TESTopic
{
    bool FUN_00619430(TESForm* apForm);
};
// @fnv 0x00619430
bool FUN_00619430_shell::FUN_00619430(TESForm* apForm)
{
    bool bResult = false;
    switch (FNV_GetFormType(apForm))
    {
    case 0x46: {
        TESTopicInfo* pTopicInfo = dynamic_cast<TESTopicInfo*>(apForm);
        if (pTopicInfo)
        {
            TESTopic* pMenuTopicEntry = TESTopic::GetTopicFromInfo(pTopicInfo);
            if (pMenuTopicEntry)
            {
                if (pMenuTopicEntry == this)
                    bResult = true;
                else
                    bResult = Sort(pMenuTopicEntry);
            }
        }
    }
    break;
    case 0x45: {
        TESTopic* pothertopic = dynamic_cast<TESTopic*>(apForm);
        if (pothertopic && GetFormID() < pothertopic->GetFormID())
            bResult = true;
    }
    break;
    default:
        bResult = ((FUN_00484020_shell*)this)->IsLessThan(apForm);
        break;
    }
    return bResult;
}

TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo* info, unsigned int index);

struct FUN_00619c50_shell : TESTopic
{
    TESTopic* FindTopicByInfoID(unsigned int topicID);
};

// @fnv 0x00619c50
TESTopic* FUN_00619c50_shell::FindTopicByInfoID(unsigned int topicID)
{
    BSSimpleList<QuestDialogueInfo*>* pList = GetQuestInfoList();
    unsigned int count_2 = 0;
    while (pList && pList->GetItem())
    {
        QuestDialogueInfo* pInfo = pList->GetItem();
        pList = pList->GetNext();
        count_2 = reinterpret_cast<TESForm*>(pInfo->GetInfoArray())->GetFormID();
        if (count_2)
        {
            for (unsigned int i = 0; i < count_2; ++i)
            {
                TESTopicInfo* result = GetTopicInfoByIndex(pInfo, i);
                if (result == reinterpret_cast<TESTopicInfo*>(topicID))
                    return reinterpret_cast<TESTopic*>(pInfo);
            }
        }
    }
    return 0;
}

namespace fnv_0061a5a0 {
struct DH;
extern DH* g_dataHandler;
struct FUN_004612e0_shell
{
    void* FUN_004612e0();
};
struct ListX
{
    ~ListX();
};
struct SL : ListX
{
    SL();
    void* m_item;
    void* m_next;
};
struct G2
{
    void AddHead(int*);
};
struct GridArray
{
    int GetCenterX() const;
};
struct ItemList
{
    void FUN_0063f7b0();
};
struct VATSCommand;
struct VATS_CommandList
{
    void FUN_00905330(VATSCommand* const&);
};
bool __fastcall _ref_008256d0(void*);
struct TopicSort_0061a5a0
{
    static bool __cdecl FUN_0061a450(TESTopic*, TESTopic*, bool);
    static void __cdecl AddTopicToList(TESTopic*, BSSimpleList<TESTopic*>*, bool);
};

// Sorts the topic list by priority, moving out-of-order topics into a temporary list and reinserting them via AddTopicToList.
// @fnv 0x0061a5a0
void SortTopicList(bool abSortByPriority, BSSimpleList<TESTopic*>* apTopicList)
{
    BSSimpleList<TESTopic*>* pBaseList = apTopicList;
    if (!pBaseList)
        pBaseList = (BSSimpleList<TESTopic*>*)((FUN_004612e0_shell*)g_dataHandler)->FUN_004612e0();
    SL sortlist;
    BSSimpleList<TESTopic*>* pCurrentElementNext = pBaseList;
    BSSimpleList<TESTopic*>* plastlist = 0;
    while (pCurrentElementNext && (*(TESTopic**)((TESTopicInfoData*)(pCurrentElementNext))->GetLinkFromList()))
    {
        bool badvanced = false;
        if (((BSSimpleList<TESTopic*>*)((GridArray*)(pCurrentElementNext))->GetCenterX()))
        {
            TESTopic* ptopic1 = (*(TESTopic**)((TESTopicInfoData*)(pCurrentElementNext))->GetLinkFromList());
            TESTopic* ptopic2 =
                (*(TESTopic**)((TESTopicInfoData*)(((BSSimpleList<TESTopic*>*)((GridArray*)(pCurrentElementNext))->GetCenterX())))
                      ->GetLinkFromList());
            if (TopicSort_0061a5a0::FUN_0061a450(ptopic1, ptopic2, abSortByPriority))
            {
                if (plastlist)
                {
                    ((VATS_CommandList*)plastlist)->FUN_00905330((VATSCommand* const&)ptopic1);
                    pCurrentElementNext = ((BSSimpleList<TESTopic*>*)((GridArray*)(plastlist))->GetCenterX());
                }
                else
                {
                    ((ItemList*)pCurrentElementNext)->FUN_0063f7b0();
                }
                ((G2*)&sortlist)->AddHead((int*)&ptopic1);
                badvanced = true;
            }
        }
        if (!badvanced)
        {
            plastlist = pCurrentElementNext;
            pCurrentElementNext = ((BSSimpleList<TESTopic*>*)((GridArray*)(pCurrentElementNext))->GetCenterX());
        }
    }
    while (!_ref_008256d0(&sortlist))
    {
        TESTopic* pMenuTopicEntry = (*(TESTopic**)((TESTopicInfoData*)(&sortlist))->GetLinkFromList());
        ((ItemList*)&sortlist)->FUN_0063f7b0();
        TopicSort_0061a5a0::AddTopicToList(pMenuTopicEntry, pBaseList, abSortByPriority);
    }
}
}  // namespace fnv_0061a5a0

struct FUN_00619bc0_shell : TESTopic
{
    bool HasInfoForQuest(TESQuest* apQuest, bool apCheck);
};

// Scans the quest info list for an entry whose pQuest matches apQuest and returns whether its info array form ID is positive, or true when apCheck is false.
// @fnv 0x00619bc0
bool FUN_00619bc0_shell::HasInfoForQuest(TESQuest* apQuest, bool apCheck)
{
    if (!apQuest)
        return false;
    BSSimpleList<QuestDialogueInfo*>* pList = GetQuestInfoList();
    while (pList && pList->GetItem())
    {
        QuestDialogueInfo* pInfo = pList->GetItem();
        pList = pList->GetNext();
        if (pInfo->pQuest == apQuest)
        {
            return reinterpret_cast<TESForm*>(pInfo->GetInfoArray())->GetFormID() > 0 || !apCheck;
        }
    }
    return false;
}

struct FUN_00619f70_shell : public TESTopic
{
    TopicInfoArray* FindQuestInfoArray(TESTopicInfo* apInfo);
};

// @fnv 0x00619f70
TopicInfoArray* FUN_00619f70_shell::FindQuestInfoArray(TESTopicInfo* apInfo)
{
    BSSimpleList<QuestDialogueInfo*>* list = GetQuestInfoList();
    while (list && list->GetItem())
    {
        QuestDialogueInfo* info = list->GetItem();
        list = list->GetNext();
        if (info->pQuest == (TESQuest*)apInfo && (apInfo || !info->m_pAlternateQuest))
            return info->GetInfoArray();
    }
    return 0;
}

struct FUN_006189a0_target
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
    virtual void Forward(int a);
};

struct FUN_006189a0_cls
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
    virtual void Forward(int a);
    void FUN_006189a0(int a);
};

// @fnv 0x006189a0
void FUN_006189a0_cls::FUN_006189a0(int a)
{
    Forward(a);
}

class FUN_00935a40_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00935a40_cls* m_pFirstNode;

    bool FUN_00574900();
    FUN_00935a40_cls* FUN_005e3fa0();
    FUN_00935a40_cls* FUN_005d43c0();
    FUN_00935a40_cls* FUN_0042efe0();
    FUN_00935a40_cls* FUN_00726070();
    FUN_00935a40_cls** FUN_006815c0();

    bool HasEntryWithKey(int key);
};

// Walks the entry list reached through FUN_00574900/FUN_005e3fa0/FUN_005d43c0/FUN_0042efe0 and returns true if any entry's unk00 equals key.
// @fnv 0x00935a40
bool FUN_00935a40_cls::HasEntryWithKey(int key)
{
    FUN_00935a40_cls* res = 0;
    if (this->FUN_00574900())
    {
        res = this->FUN_005e3fa0()->FUN_005d43c0()->FUN_0042efe0();
    }
    else
    {
        res = this->FUN_005d43c0()->FUN_0042efe0();
    }
    if (res != 0)
    {
        FUN_00935a40_cls* cur = res->m_pFirstNode;
        while (cur != 0 && *cur->FUN_006815c0() != 0)
        {
            FUN_00935a40_cls* item = *cur->FUN_006815c0();
            if (item->unk00 == key)
            {
                return true;
            }
            cur = cur->FUN_00726070();
        }
    }
    return false;
}

namespace fnv_00619030 {
extern PlayerCharacter* g_thePlayer;

extern TESForm* LookupFormByID(unsigned int formID);
extern void ResolveFormID(unsigned int* formID, TESFile* file);
extern void FNV_Warning(const char* fmt, ...);

struct BSSimpleArray_Helper
{
    void RemoveAt(int index, bool flag = true);
};

struct NiTLargeArray_TESTopicInfo
{
    void Compact();
    void SetSize(unsigned int size);
};

struct TopicInfoStandin : public TESTopicInfo
{
    void SetOwnerQuest(TESQuest* quest);
    void FUN_0061f340(unsigned short index);
};

struct PlayerCharacter_Helper : public PlayerCharacter
{
    void NotifyTopic(TESTopic* topic, int arg2, int arg3);
};

struct TESTopic_Shell : public TESTopic
{
    void InitializeTopic();
    bool IsRandom();
};

// Initializes the topic's quest info entries, resolves their quests and infos, compacts the info arrays, and notifies the player if the topic is random.
// @fnv 0x00619030
void TESTopic_Shell::InitializeTopic()
{
    if (GetInitialized())
        return;

    BSSimpleList<QuestDialogueInfo*>* pIter = GetQuestInfoList();
    BSSimpleList<QuestDialogueInfo*>* prev = 0;
    while (pIter && pIter->GetItem())
    {
        QuestDialogueInfo* questInfo = pIter->GetItem();
        TopicInfoArray* array;
        if (questInfo)
        {
            if (!questInfo->bInitialized)
            {
                int count = questInfo->m_kInfoLinks.GetSize();
                for (int i = 0; i < count; i++)
                {
                    unsigned int formID = questInfo->m_kInfoLinks.GetAt(i).nID;
                    TESTopicInfo* pTopicInfo = dynamic_cast<TESTopicInfo*>(LookupFormByID(formID));
                    questInfo->m_kInfoLinks.GetAt(i).pInfo = pTopicInfo;
                    if (pTopicInfo)
                    {
                        unsigned int index;
                        bool bFound = false;
                        for (index = 0; index < questInfo->GetInfoArray()->GetSize(); index++)
                        {
                            if (questInfo->GetInfoArray()->GetAt(index) == pTopicInfo)
                            {
                                bFound = true;
                                break;
                            }
                        }
                        if (bFound)
                        {
                            ((BSSimpleArray_Helper*)&questInfo->m_kInfoLinks)->RemoveAt(i, true);
                            count--;
                            i--;
                        }
                    }
                    else
                    {
                        unsigned int uiChunkType = (unsigned int)questInfo->pQuest;
                        TESQuest* quest = dynamic_cast<TESQuest*>(LookupFormByID(uiChunkType));
                        ((BSSimpleArray_Helper*)&questInfo->m_kInfoLinks)->RemoveAt(i, true);
                        count--;
                        i--;
                    }
                }

                if (questInfo->pQuest)
                {
                    unsigned int uiChunkType = (unsigned int)questInfo->pQuest;
                    questInfo->pQuest = dynamic_cast<TESQuest*>(LookupFormByID(uiChunkType));
                }
                else if (questInfo->m_pAlternateQuest)
                {
                    unsigned int formID = (unsigned int)questInfo->m_pAlternateQuest;
                    ResolveFormID(&formID, GetFile(-1));
                    questInfo->m_pAlternateQuest = dynamic_cast<TESQuest*>(LookupFormByID(formID));
                }
                else
                {
                    int size = 0;
                    if (questInfo->GetInfoArray())
                        size = questInfo->GetInfoArray()->GetSize();
                    int nonDeletedCount = 0;
                    if (size)
                    {
                        for (int k = 0; k < size; k++)
                        {
                            TESTopicInfo* info = questInfo->GetInfoArray()->GetAt(k);
                            if (!info->GetDeleted())
                                nonDeletedCount++;
                        }
                    }
                    if (nonDeletedCount > 0)
                    {
                        FNV_Warning(
                            "MASTERFILE: No Quest Reference on Topic \"%s\" (%d non-deleted infos attached to this quest).",
                            GetName(), nonDeletedCount);
                    }
                }
                questInfo->bInitialized = true;
            }

            array = questInfo->GetInfoArray();
            if (array)
            {
                ((NiTLargeArray_TESTopicInfo*)array)->Compact();
                ((NiTLargeArray_TESTopicInfo*)array)->SetSize(array->GetSize());
                unsigned int infoCount = array->GetSize();
                for (unsigned int i = 0; i < infoCount; i++)
                {
                    TESTopicInfo* curInfo = array->GetAt(i);
                    if (curInfo)
                    {
                        ((TopicInfoStandin*)curInfo)->SetOwnerQuest(questInfo->pQuest);
                        curInfo->InitItem();
                        ((TopicInfoStandin*)curInfo)->FUN_0061f340((unsigned short)i);
                    }
                }
            }
        }
        prev = pIter;
        pIter = pIter->GetNext();
    }

    if (IsRandom())
    {
        ((PlayerCharacter_Helper*)g_thePlayer)->NotifyTopic(this, 0, 0);
    }
    SetInitializationState(true);
}
}  // namespace fnv_00619030

class TopicInfoArrayMethods : public TopicInfoArray
{
  public:
    void FUN_0061bd20(unsigned int index, TESTopicInfo*& value);
    void FUN_00864240(unsigned int index, TESTopicInfo*& value);
    void FUN_0061bdc0();
};
class TopicInfoMethods : public TESTopicInfo
{
  public:
    void FUN_0061f340(unsigned short index);
};
class TopicMethods : public TESTopic
{
  public:
    QuestDialogueInfo* GetOrCreateQuestInfo(TESQuest* quest, bool create);
    TESTopicInfo* FindTopicInfoByFormID(unsigned int formID, bool searchAll);
    bool AddTopicInfo(TESQuest* quest, TESTopicInfo* info, unsigned int previousInfoID);
};
extern TESTopic* g_loadingTopic;
void FNV_Warning(const char* format, ...);
TESTopicInfo* GetTopicInfoByIndex(QuestDialogueInfo* questInfo, int index);
void FUN_00619fe0(TopicInfoArray* array);

// @fnv 0x00619820
bool TopicMethods::AddTopicInfo(TESQuest* quest, TESTopicInfo* info, unsigned int previousInfoID)
{
    if (!quest || !info)
        return false;
    QuestDialogueInfo* questInfo = GetOrCreateQuestInfo(quest, false);
    if (previousInfoID)
    {
        TESTopicInfo* previousInfo;
        {
            unsigned int insertionIndex;
            {
                unsigned int i;
                {
                    int lastIndex;
                    if (previousInfoID != 0xffffffffu && info->GetInfoIndex() != 0xffff)
                    {
                        TESTopicInfo* empty = 0;
                        static_cast<TopicInfoArrayMethods*>(questInfo->GetInfoArray())
                            ->FUN_0061bd20(info->GetInfoIndex(), empty);
                    }
                    if (previousInfoID != 0xffffffffu)
                    {
                        previousInfo = FindTopicInfoByFormID(previousInfoID, true);
                        if (previousInfo && previousInfoID)
                        {
                            insertionIndex = 0xffffffffu;
                            if (previousInfo->GetInfoIndex() == 0xffff)
                            {
                                for (i = 0; i < questInfo->GetInfoArray()->GetSize(); i++)
                                {
                                    if (questInfo->GetInfoArray()->GetAt(i) == previousInfo)
                                    {
                                        insertionIndex = i + 1;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                insertionIndex = previousInfo->GetInfoIndex() + 1;
                            }
                            questInfo->GetInfoArray()->InsertInfoAt(insertionIndex, info);
                        }
                        else
                        {
                            FNV_Warning(
                                "QUESTS: Could not find previous info (%08X) for TopicInfo (%08X) in Topic \"%s\" (%08X).",
                                previousInfoID, info->GetFormID(), g_loadingTopic->GetName(),
                                g_loadingTopic->GetFormID());
                            questInfo->GetInfoArray()->InsertInfoAt(0, info);
                        }
                    }
                    else if (info->GetInfoIndex() == 0xffff)
                    {
                        lastIndex = questInfo->GetInfoArray()->GetSize() - 1;
                        while (lastIndex > 0 && !GetTopicInfoByIndex(questInfo, lastIndex))
                            lastIndex--;
                        lastIndex++;
                        static_cast<TopicInfoMethods*>(info)->FUN_0061f340((unsigned short)lastIndex);
                        static_cast<TopicInfoArrayMethods*>(questInfo->GetInfoArray())->FUN_00864240(lastIndex, info);
                    }
                }
            }
        }
    }
    else
    {
        questInfo->GetInfoArray()->InsertInfoAt(0, info);
    }
    static_cast<TopicInfoArrayMethods*>(questInfo->GetInfoArray())->FUN_0061bdc0();
    FUN_00619fe0(questInfo->GetInfoArray());
    return true;
}

struct SettingFloat
{
    float* Float();
};

extern SettingFloat DAT_011cff1c;
extern SettingFloat DAT_011d14d0;

// Returns the negated DAT_011cff1c value minus DAT_011d14d0 multiplied by (1.0f minus iValue / 100.0f).
// @fnv 0x00648f60
float FUN_00648f60(int iValue)
{
    return -*DAT_011cff1c.Float() - *DAT_011d14d0.Float() * (1.0f - iValue / 100.0f);
}

#include <stdlib.h>
struct FUN_005c90d0
{
    ~FUN_005c90d0();
};
struct DialogueList;

struct FormTypeView
{
    int FUN_00401170();
};
unsigned int __cdecl GetTime64(int);
struct DialogueList
{
    DialogueItem*& FUN_006815c0();
    bool FUN_008256d0();
    void FUN_0063f7b0();
    unsigned int FUN_005ae380();
    DialogueList* FUN_00726070();
    void AddTail(DialogueItem*&);
};
struct TopicList
{
    TESTopic*& FUN_006815c0();
    bool FUN_008256d0();
    unsigned int FUN_005ae380();
    TopicList* FUN_00726070();
};
struct ConversationDataView
{
    TopicList* FUN_00413f40();
};
struct InfoView
{
    bool FUN_00579200();
    void RunResultScript(bool, TESObjectREFR*);
    void FUN_0061f150();
    ConversationDataView* GetField38();
    int GetSignedByteAtOffset36();
};
struct ItemView
{
    InfoView* FUN_0084e3a0();
    bool FUN_0083c7b0();
    ItemView* FUN_0083c820();
    BSStringT<char>* FUN_006815c0();
    TESForm* FUN_009611e0();
};
struct DataHandlerView
{
    FUN_0061b320_shell* FUN_00461690(int);
};
struct AIView
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
    virtual int GetDisposition();
};
struct ActorBaseView : TESForm
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    AIView ai;
};
extern unsigned char DAT_011cbeac;
void __cdecl DebugLog(const char*, ...);
void __cdecl FUN_00403d30(void*, int, unsigned int);
// Adds dialogue items to history by selecting topics for speaker and listener, with random selection among available topic links.
// @fnv 0x0061b440
unsigned int __cdecl GenerateConversation(TESObjectREFR* speaker, TESObjectREFR* listener, DialogueList* history,
                                          FUN_0061b320_shell* initialTopic)
{
    int used[500];
    DialogueItem* choice;
    bool item;
    if (!history)
        return 0;
    while (history && !history->FUN_008256d0())
    {
        delete (FUN_005c90d0*)history->FUN_006815c0();
        history->FUN_0063f7b0();
    }
    if (!speaker || !listener)
        return 0;
    TESObjectREFR* previous = speaker;
    TESObjectREFR* currentSpeaker = listener;
    FUN_0061b320_shell* nextItem = 0;
    TESTopic* currentListener = 0;
    TESBoundObject* topic = previous->GetObjectReference();
    if (topic && ((FormTypeView*)topic)->FUN_00401170() == 43 && !((ActorBaseView*)topic)->ai.GetDisposition())
        return 0;
    nextItem = initialTopic;
    if (!nextItem)
        nextItem = ((DataHandlerView*)g_dataHandler)->FUN_00461690(210);
    DialogueItem* base = 0;
    int exhausted = -1;
    srand((unsigned int)GetTime64(0));
    while (nextItem && history->FUN_005ae380() < 100)
    {
        TopicList* topics;
        base = nextItem->FUN_0061b320(previous, currentSpeaker, currentListener, history, false);
        if (!base)
        {
            if (!initialTopic || ((InfoView*)initialTopic)->GetSignedByteAtOffset36() == 1)
            {
                nextItem = ((DataHandlerView*)g_dataHandler)->FUN_00461690(212);
                base = nextItem->FUN_0061b320(previous, currentSpeaker, currentListener, history, false);
            }
            if (!base)
                break;
        }
        if (base && ((ItemView*)base)->FUN_0084e3a0() && ((ItemView*)base)->FUN_0084e3a0()->FUN_00579200())
        {
            ((ItemView*)base)->FUN_0084e3a0()->RunResultScript(false, speaker);
            ((ItemView*)base)->FUN_0084e3a0()->RunResultScript(true, speaker);
            ((ItemView*)base)->FUN_0084e3a0()->FUN_0061f150();
        }
        history->AddTail(base);
        currentListener = (TESTopic*)nextItem;
        nextItem = 0;
        choice = 0;
        item = false;
        FUN_00403d30(used, 0, 2000);
        exhausted = -1;
        while (!choice && !item)
        {
            int count;
            if (((ItemView*)base)->FUN_0084e3a0() && ((ItemView*)base)->FUN_0084e3a0()->GetField38())
            {
                topics = ((ItemView*)base)->FUN_0084e3a0()->GetField38()->FUN_00413f40();
                count = topics->FUN_005ae380();
                if (count)
                {
                    if (exhausted == -1)
                        exhausted = rand() % count + 1;
                    else
                        while (used[exhausted - 1])
                            exhausted = rand() % count + 1;
                }
                if (exhausted > 0)
                    used[exhausted - 1] = 1;
                int n = 0;
                while (n < exhausted && topics && !topics->FUN_008256d0())
                {
                    nextItem = (FUN_0061b320_shell*)topics->FUN_006815c0();
                    topics = topics->FUN_00726070();
                    n++;
                }
                switch (((ItemView*)base)->FUN_0084e3a0()->GetSignedByteAtOffset36())
                {
                case 2:
                    if (rand() % 2 != 0)
                        break;
                case 0: {
                    TESObjectREFR* temp = previous;
                    previous = currentSpeaker;
                    currentSpeaker = temp;
                    break;
                }
                }
                item = true;
                for (unsigned int i = 0; i < (unsigned int)count && item; i++)
                    if (!used[i])
                        item = false;
                choice = nextItem->FUN_0061b320(previous, currentSpeaker, currentListener, history, false);
            }
            else
                item = true;
        }
    }
    if (DAT_011cbeac)
    {
        DebugLog("------NEW CONVERSATION CREATED---------------------");
        DialogueList* node = history;
        {
            int index = 1;
            while (node && node->FUN_006815c0())
            {
                ItemView* entry = (ItemView*)node->FUN_006815c0();
                node = node->FUN_00726070();
                if (entry)
                {
                    if (entry->FUN_0083c7b0())
                    {
                        DebugLog("Item %d: %s says '%s'", index, entry->FUN_009611e0()->GetName(),
                                 entry->FUN_0083c820()->FUN_006815c0()->String());
                    }
                    else
                    {
                        DebugLog("Item %d: %s has no response!", index, entry->FUN_009611e0()->GetName());
                    }
                }
                index++;
            }
        }
    }
    return history->FUN_005ae380();
}
