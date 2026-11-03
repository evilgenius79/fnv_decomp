// fallout_shared/testopicinfo.cpp: TESTopicInfo, DelStandIn, TopicLinkLists, TopicInfoCompare and more (52 functions)

#include "testopicinfo_topicinfo_helpers.h"
#include "testopicinfo_topicinfo_TESTopicInfo.h"
#include "testopicinfo_topicinfo_forms.h"
#include "TESFile.h"
#include "testopicinfo_topicinfo_TESTopic.h"
#include "testopicinfo_topicinfo_TESConversationData.h"
#include "Script.h"
#include "ScriptVariableInfo.h"
#include "ScriptReferencedObject.h"
#include "ScriptHeaderData.h"
#include "testopicinfo_topicinfo_ResponseListWrapper.h"
#include "testopicinfo_topicinfo_TESResponse.h"
#include "game_constants.h"
#include "original_script.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

extern TESTopicInfo* g_cachedResultScriptInfo;
extern Script g_resultScripts[2];
extern ScriptVariableInfo* g_loadedScriptVariable;
extern const char g_emptyTopicInfoPrompt[];
extern TESResponseList g_topicInfoResponses;
extern TESTopicInfo* g_cachedResponseInfo;
extern TESTopic* g_loadingTopic;
extern const char g_topicInfoLoadWarning[];

// @fnv 0x0061dbd0
bool TESTopicInfo::LoadForm(TESFile* file)
{
    unsigned int previousInfoID;
    int responseCount;
    {
        unsigned char m_ucFormType = file->GetTESForm();
        if (m_ucFormType != kTopicInfoFormType)
            return false;
        if (!file->GetCached())
            m_ulTopicFlags = file->GetOffset();
        previousInfoID = kNoPreviousTopicInfo;
        struct TopicRecord
        {
            int chunk;
            unsigned int uiChunkType;
        } record;
        record.uiChunkType = 0;
        LoadRecordHeader(file);
        responseCount = 0;
        while (record.chunk = file->GetChunkID())
        {
            switch (record.chunk)
            {
            case kConditionDataChunk:
                GetInfoConditions()->Load(file);
                break;
            case kPreviousTopicInfoChunk:
                file->GetChunkData(&previousInfoID);
                if (previousInfoID)
                    RemapFormIDForFile(previousInfoID, file);
                break;
            case kTopicInfoDataChunk:
                file->GetChunkData(&m_Data, sizeof(m_Data));
                if (m_Data.type >= DIALOGUE_TYPE_DIALOGUE_TYPE_COUNT)
                    MarkForDeletion(true);
                if (m_Data.type == DIALOGUE_TYPE_DT_CONVERSATION)
                    SetTopicInfoData(0);
                break;
            case kAdditionalTopicChunk: {
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                GetAddTopicList()->AddTail(reinterpret_cast<TESTopic*>(topicID));
                break;
            }
            case kTopicInfoQuestChunk:
                file->GetChunkData(&record.uiChunkType);
                RemapFormIDForFile(record.uiChunkType, file);
                break;
            case kConversationLinkToChunk: {
                if (!GetConversationData())
                    SetTopicInfoData(0);
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                GetConversationData()->GetLinkToList()->AddTail(reinterpret_cast<TESTopic*>(topicID));
                break;
            }
            case kConversationLinkFromChunk: {
                if (!GetConversationData())
                    SetTopicInfoData(0);
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                GetConversationData()->GetLinkFromList()->AddTail(reinterpret_cast<TESTopic*>(topicID));
                break;
            }
            case kConversationFollowUpChunk: {
                if (!GetConversationData())
                    SetTopicInfoData(0);
                unsigned int infoID = 0;
                file->GetChunkData(&infoID);
                GetConversationData()->GetFollowUpInfoList()->AddTail(reinterpret_cast<TESTopicInfo*>(infoID));
                break;
            }
            case kTopicInfoPromptChunk: {
                char prompt[kTopicInfoPromptReadSize];
                file->GetChunkData(prompt, sizeof(prompt));
                SetPrompt(prompt);
                break;
            }
            case kTopicInfoPerkSkillChunk: {
                unsigned int formID = 0;
                file->GetChunkData(&formID);
                m_pPerkSkillStat = reinterpret_cast<TESForm*>(formID);
                break;
            }
            case kTopicInfoSpeakerChunk: {
                unsigned int speakerID = 0;
                file->GetChunkData(&speakerID);
                m_pDialogueSpeaker = reinterpret_cast<TESActorBase*>(speakerID);
                break;
            }
            case kTopicInfoDifficultyChunk: {
                unsigned int difficulty;
                file->GetChunkData(&difficulty);
                if (difficulty < SPEECH_CHALLENGE_LEVEL_SCL_COUNT)
                    SetDifficultyLevel(static_cast<SPEECH_CHALLENGE_LEVEL>(difficulty));
                if (m_eDifficultyLevel == SPEECH_CHALLENGE_LEVEL_SCL_NONE)
                    m_eDifficultyLevel = SPEECH_CHALLENGE_LEVEL_SCL_VERYEASY;
                break;
            }
            }
            if (!file->NextChunk())
                break;
        }
        if (m_Data.type == DIALOGUE_TYPE_DT_PERSUASION)
            m_Data.type = DIALOGUE_TYPE_DT_TOPIC;
        if (!IsDeleted())
        {
            if (!g_loadingTopic->InsertInfoAfter(reinterpret_cast<TESQuest*>(record.uiChunkType), this, previousInfoID))
                Warning(g_topicInfoLoadWarning, GetFormID(), g_loadingTopic->GetName(), g_loadingTopic->GetFormID(),
                        record.uiChunkType);
        }
        return true;
    }
}

// @fnv 0x0061ccd0
TESTopicInfo::TESTopicInfo(DIALOGUE_TYPE type)
{
    InitializeComponent();
    m_Data.type = static_cast<char>(type);
    if (type == DIALOGUE_TYPE_DT_CONVERSATION)
    {
        m_pResponseData = new TESTopicInfoData;
        SetRandom(true);
    }
}

// @fnv 0x0061e180
void TESTopicInfo::SetTopicInfoData(TESTopicInfoData* data)
{
    if (data)
    {
        if (!m_pResponseData)
            m_pResponseData = new TESTopicInfoData;
        m_pResponseData->Copy(this, data);
    }
    else
    {
        if (m_pResponseData)
        {
            delete m_pResponseData;
            m_pResponseData = 0;
        }
        m_pResponseData = new TESTopicInfoData;
    }
}

// Clears m_Data and the topic-info fields, sets the form type, prompt, speaker, actor value, perk and difficulty level to defaults.
// @fnv 0x0061cf40
void TESTopicInfo::InitializeComponent()
{
    memset(&m_Data, 0, sizeof(m_Data));
    m_ulTopicFlags = 0;
    m_bGoodbye = false;
    m_uiInfoIndex = kInvalidTopicInfoIndex;
    SetFormType(static_cast<ENUM_FORM_ID>(kTopicInfoFormType));
    m_pResponseData = 0;
    m_pOwnerQuest = 0;
    SetPrompt(g_emptyTopicInfoPrompt);
    SetSpeaker(0);
    SetActorValue(0);
    SetPerk(0);
    SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL_SCL_VERYEASY);
}

// Removes every entry from the add-topic list returned by GetAddTopicList until the list is empty.
// @fnv 0x0061d250
void TESTopicInfo::ResetResponseList()
{
    BSSimpleList<TESTopic*>* topics = GetAddTopicList();
    while (topics && !topics->IsEmpty())
        topics->RemoveHead();
}

// @fnv 0x0061d230
void TESTopicInfo::ClearResponses()
{
    g_topicInfoResponses.ClearResponses();
}

// @fnv 0x0061cff0
void TESTopicInfo::ClearData()
{
    if (!IsTemporary())
    {
        if (GetInfoIndex() != kInvalidTopicInfoIndex)
        {
            TESTopic* owner = TESTopic::GetTopicFromInfo(this);
            if (owner)
                SetOwnerTopic(owner);
        }
        GetInfoConditions()->InitializeConditionItems();
        ClearResponses();
        ResetResponseList();
        Script emptyScript;
        g_resultScripts[0].CopyScriptContents(&emptyScript);
        g_resultScripts[1].CopyScriptContents(&emptyScript);
    }
    g_cachedResponseInfo = 0;
    g_cachedResultScriptInfo = 0;
    if (m_pResponseData)
        delete m_pResponseData;
}

// @fnv 0x0061d140
void TESTopicInfo::SetOwnerTopic(TESTopic* owner)
{
    if (owner && GetInfoIndex() != kInvalidTopicInfoIndex)
    {
        QuestDialogueInfo* questInfo = owner->GetQuestInfoForInfo(this);
        if (questInfo)
        {
            TopicInfoArray* infoArray = questInfo->GetInfoArray();
            int iCount;
            if (infoArray->GetAt(GetInfoIndex()) == this)
                infoArray->RemoveAt(GetInfoIndex());
            else
            {
                bool bFound = false;
                iCount = infoArray->GetSize();
                for (int index = 0; index < iCount; index++)
                {
                    if (infoArray->GetAt(index) == this)
                    {
                        infoArray->RemoveAt(index);
                        bFound = true;
                        break;
                    }
                }
            }
            infoArray->Compact();
            TESTopic::CompactTopicInfos(infoArray);
        }
    }
}

// @fnv 0x0061db30
void TESTopicInfo::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags().ContainsAnyFlags(0x80000000))
        m_bGoodbye = true;
}

// @fnv 0x0061db80
void TESTopicInfo::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    if (buffer->GetOldChangeFlags().ContainsAnyFlags(0x80000000))
        m_bGoodbye = false;
}

// @fnv 0x0061f150
void TESTopicInfo::AddTopicList()
{
    pPlayer->AddTopics(GetAddTopicList());
}

// Loads TESResponse records from the file's response chunk into list or g_topicInfoResponses, caching this as g_cachedResponseInfo when list is null.
// @fnv 0x0061e780
TESResponseList* TESTopicInfo::DuplicateResponseList(TESResponseList* pResponseList)
{
    unsigned char form;
    {
        struct ResponseRead
        {
            TESResponse* response;
            int chunk;
            TESFile* file;
        } responseReader;
        if (this == g_cachedResponseInfo)
        {
            if (pResponseList)
            {
                pResponseList->SetResponseList(g_topicInfoResponses.QResponseList());
                return pResponseList;
            }
            else
                return &g_topicInfoResponses;
        }
        if (!pResponseList)
        {
            g_cachedResponseInfo = this;
            ClearResponses();
        }
        responseReader.file = GetFile(-1);
        if (!responseReader.file || !m_ulTopicFlags)
            return pResponseList ? pResponseList : &g_topicInfoResponses;
        responseReader.file = responseReader.file->GetParentTESFile();
        if (!responseReader.file->SetOffset(m_ulTopicFlags))
            return pResponseList ? pResponseList : &g_topicInfoResponses;
        form = responseReader.file->GetTESForm();
        if (form != kTopicInfoFormType)
            return pResponseList ? pResponseList : &g_topicInfoResponses;
        responseReader.response = 0;
        while (responseReader.chunk = responseReader.file->GetChunkID())
        {
            switch (responseReader.chunk)
            {
            case 0x54445254:  // TRDT reader.response data
                responseReader.response = new TESResponse;
                responseReader.response->Load(responseReader.file);
                responseReader.response->InitItem(this);
                if (pResponseList)
                    pResponseList->AddTail(responseReader.response);
                else
                    g_topicInfoResponses.AddTail(responseReader.response);
                break;
            case 0x314d414e:  // NAM1 reader.response text
                if (responseReader.response)
                {
                    unsigned int size = responseReader.file->GetChunkSize();
                    char* text = static_cast<char*>(_alloca(size));
                    responseReader.file->GetChunkData(text, size);
                    responseReader.response->SetResponseText(text);
                }
                break;
            case 0x4d414e53:  // SNAM speaker idle
                if (responseReader.response)
                {
                    struct IdleReference
                    {
                        unsigned int formID;
                        TESForm* form;
                    } reference;
                    reference.formID = 0;
                    responseReader.file->GetChunkData(&reference.formID);
                    RemapFormIDForFile(reference.formID, responseReader.file);
                    TESIdleForm* idle = 0;
                    reference.form = GetFormByID(reference.formID);
                    if (reference.form && reference.form->GetFormType() == 72)
                        idle = static_cast<TESIdleForm*>(reference.form);
                    if (reference.formID && !idle)
                        Warning("DEFAULT: Unable to find idle (%08X) for info (%08X).", reference.formID, GetFormID());
                    responseReader.response->SetSpeakerIdle(idle);
                }
                break;
            case 0x4d414e4c:  // LNAM listener idle
                if (responseReader.response)
                {
                    struct IdleReference
                    {
                        unsigned int formID;
                        TESForm* form;
                    } reference;
                    reference.formID = 0;
                    responseReader.file->GetChunkData(&reference.formID);
                    RemapFormIDForFile(reference.formID, responseReader.file);
                    TESIdleForm* idle = 0;
                    reference.form = GetFormByID(reference.formID);
                    if (reference.form && reference.form->GetFormType() == 72)
                        idle = static_cast<TESIdleForm*>(reference.form);
                    if (reference.formID && !idle)
                        Warning("DEFAULT: Unable to find idle (%08X) for info (%08X).", reference.formID, GetFormID());
                    responseReader.response->GetListenerIdle(idle);
                }
                break;
            }
            if (!responseReader.file->NextChunk())
                break;
        }
        return pResponseList ? pResponseList : &g_topicInfoResponses;
    }
}

// @fnv 0x0061d290
void TESTopicInfo::InitItem()
{
    if (IsFormInitialized())
        return;
    TESFile* pFile = GetFile(-1);
    {
        BSSimpleList<TESTopic*>* previous = 0;
        TESResponse* pResponse;
        {
            BSSimpleList<TESTopic*>* pTopics = GetAddTopicList();
            while (pTopics && pTopics->GetItem())
            {
                unsigned int formID = reinterpret_cast<unsigned int>(pTopics->GetItem());
                RemapFormIDForFile(formID, pFile);
                TESTopic* topic = dynamic_cast<TESTopic*>(GetFormByID(formID));
                if (!topic)
                {
                    if (pTopics->GetNext() || !previous)
                        pTopics->RemoveHead();
                    else
                    {
                        previous->Remove(reinterpret_cast<TESTopic*>(formID));
                        pTopics = previous->GetNext();
                    }
                    TESTopic* ownerTopic = TESTopic::GetTopicFromInfo(this);
                    TESQuest* ownerQuest = 0;
                    if (ownerTopic)
                        ownerQuest = ownerTopic->GetParentQuest(this);
                    {
                        BSStringT<char> text;
                        FormatDebugInfo(text, true);
                        char description[260];
                        if (ownerTopic && ownerQuest)
                            sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                    GetFormID(), text.String(), ownerQuest->GetEditorName(), ownerQuest->GetFormID(),
                                    ownerTopic->GetName(), ownerTopic->GetFormID());
                        else
                            sprintf(description, "TopicInfo %08X \"%s\"", GetFormID(), text.String());
                        Warning("MASTERFILE: Unable to find topic (%08X) for %s", formID, description);
                    }
                }
                else
                {
                    pTopics->SetItem(topic);
                    previous = pTopics;
                    pTopics = pTopics->GetNext();
                }
            }
            unsigned int speakerID = reinterpret_cast<unsigned int>(GetSpeaker());
            if (speakerID)
            {
                RemapFormIDForFile(speakerID, GetFile(-1));
                SetSpeaker(dynamic_cast<TESActorBase*>(GetFormByID(speakerID)));
            }
            if (GetInfoConditions())
                GetInfoConditions()->InitItem(this);
            if (GetConversationData())
                GetConversationData()->InitItem(this);
            pResponse = g_topicInfoResponses.QResponseList();
            while (pResponse)
            {
                pResponse->InitItem(this);
                pResponse = pResponse->GetNext();
            }
            if (m_pPerkSkillStat)
            {
                struct PerkSkillResolution
                {
                    unsigned int formID;
                    TESForm* form;
                    ActorValueInfo* actorValue;
                } resolved;
                resolved.formID = reinterpret_cast<unsigned int>(m_pPerkSkillStat);
                RemapFormIDForFile(resolved.formID, GetFile(-1));
                resolved.form = GetFormByID(resolved.formID);
                resolved.actorValue = dynamic_cast<ActorValueInfo*>(resolved.form);
                if (resolved.actorValue)
                    m_pPerkSkillStat = resolved.actorValue;
                else
                {
                    BGSPerk* perk = dynamic_cast<BGSPerk*>(resolved.form);
                    m_pPerkSkillStat = perk;
                }
            }
            SetInitializationState(true);
        }
    }
}

// @fnv 0x0061c360
void TESTopicInfoData::InitItem(TESForm* owner)
{
    BSSimpleList<TESTopic*>* pPreviousTopic = 0;
    BSSimpleList<TESTopic*>* pTopicList = GetLinkToList();
    TESFile* pFile = owner ? owner->GetFile(-1) : 0;
    {
        struct InfoCursor
        {
            BSSimpleList<TESTopicInfo*>* current;
            BSSimpleList<TESTopicInfo*>* previous;
        } infoCursor;

        while (pTopicList && pTopicList->GetItem())
        {
            struct TopicResolution
            {
                TESTopic* topic;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(pTopicList->GetItem());
            TESForm::RemapFormIDForFile(resolved.formID, pFile);
            resolved.topic = 0;
            resolved.form = TESForm::GetFormByID(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_DIAL_ID)
                resolved.topic = static_cast<TESTopic*>(resolved.form);

            if (!resolved.topic)
            {
                if (pTopicList->GetNext() || !pPreviousTopic)
                    pTopicList->RemoveHead();
                else
                {
                    pPreviousTopic->Remove(reinterpret_cast<TESTopic*>(resolved.formID));
                    pTopicList = pPreviousTopic->GetNext();
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = TESTopic::GetTopicFromInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = context.topic->GetParentQuest(context.info);
                {
                    BSStringT<char> text;
                    context.info->FormatDebugInfo(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                context.info->GetFormID(), text.String(), context.quest->GetEditorName(),
                                context.quest->GetFormID(), context.topic->GetName(), context.topic->GetFormID());
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", context.info->GetFormID(), text.String());
                    Warning("MASTERFILE: Unable to find topic (%08X) for conversation data 'Link To' on %s",
                            resolved.formID, description);
                }
            }
            else
            {
                pTopicList->SetItem(resolved.topic);
                pPreviousTopic = pTopicList;
                pTopicList = pTopicList->GetNext();
            }
        }

        pPreviousTopic = 0;
        pTopicList = GetLinkFromList();
        while (pTopicList && pTopicList->GetItem())
        {
            struct TopicResolution
            {
                TESTopic* topic;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(pTopicList->GetItem());
            TESForm::RemapFormIDForFile(resolved.formID, pFile);
            resolved.topic = 0;
            resolved.form = TESForm::GetFormByID(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_DIAL_ID)
                resolved.topic = static_cast<TESTopic*>(resolved.form);

            if (!resolved.topic)
            {
                if (pTopicList->GetNext() || !pPreviousTopic)
                    pTopicList->RemoveHead();
                else
                {
                    pPreviousTopic->Remove(reinterpret_cast<TESTopic*>(resolved.formID));
                    pTopicList = pPreviousTopic->GetNext();
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = TESTopic::GetTopicFromInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = context.topic->GetParentQuest(context.info);
                {
                    BSStringT<char> text;
                    context.info->FormatDebugInfo(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                context.info->GetFormID(), text.String(), context.quest->GetEditorName(),
                                context.quest->GetFormID(), context.topic->GetName(), context.topic->GetFormID());
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", context.info->GetFormID(), text.String());
                    Warning("MASTERFILE: Unable to find topic (%08X) for conversation data 'Link From' on %s",
                            resolved.formID, description);
                }
            }
            else
            {
                pTopicList->SetItem(resolved.topic);
                pPreviousTopic = pTopicList;
                pTopicList = pTopicList->GetNext();
            }
        }

        infoCursor.current = GetFollowUpInfoList();
        infoCursor.previous = 0;
        while (infoCursor.current && infoCursor.current->GetItem())
        {
            struct InfoResolution
            {
                TESTopicInfo* followUp;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(infoCursor.current->GetItem());
            TESForm::RemapFormIDForFile(resolved.formID, pFile);
            resolved.followUp = 0;
            resolved.form = TESForm::GetFormByID(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_INFO_ID)
                resolved.followUp = static_cast<TESTopicInfo*>(resolved.form);

            if (!resolved.followUp)
            {
                if (infoCursor.current->GetNext() || !infoCursor.previous)
                    infoCursor.current->RemoveHead();
                else
                {
                    infoCursor.previous->Remove(reinterpret_cast<TESTopicInfo*>(resolved.formID));
                    infoCursor.current = infoCursor.previous->GetNext();
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = TESTopic::GetTopicFromInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = context.topic->GetParentQuest(context.info);
                {
                    BSStringT<char> text;
                    context.info->FormatDebugInfo(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                context.info->GetFormID(), text.String(), context.quest->GetEditorName(),
                                context.quest->GetFormID(), context.topic->GetName(), context.topic->GetFormID());
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", context.info->GetFormID(), text.String());
                    Warning("MASTERFILE: Unable to find topic (%08X) for conversation data 'Follow Up' on %s",
                            resolved.formID, description);
                }
            }
            else
            {
                infoCursor.current->SetItem(resolved.followUp);
                infoCursor.previous = infoCursor.current;
                infoCursor.current = infoCursor.current->GetNext();
            }
        }
    }
}

// @fnv 0x0061eb60
Script* TESTopicInfo::GetResultScript(unsigned int onEnd)
{
    unsigned int resultIndex = onEnd;
    if (this == g_cachedResultScriptInfo)
        return &g_resultScripts[resultIndex];
    g_cachedResultScriptInfo = this;
    Script emptyScript;
    g_resultScripts[0].CopyScriptContents(&emptyScript);
    g_resultScripts[0].NotifySaveLoadGameOfFormChange();
    g_resultScripts[0].GetHeader()->m_bQuest = false;
    g_resultScripts[1].CopyScriptContents(&emptyScript);
    g_resultScripts[1].NotifySaveLoadGameOfFormChange();
    g_resultScripts[1].GetHeader()->m_bQuest = false;
    if (!HasResultScript())
        return &g_resultScripts[resultIndex];
    g_resultScripts[0].SetInitializationState(false);
    g_resultScripts[1].SetInitializationState(false);
    TESFile* file = GetFile(-1);
    if (!file || !m_ulTopicFlags)
        return &g_resultScripts[resultIndex];
    file = file->GetParentTESFile();
    if (!file->SetOffset(m_ulTopicFlags))
        return &g_resultScripts[resultIndex];
    unsigned char form = file->GetTESForm();
    if (form != kTopicInfoFormType)
        return &g_resultScripts[resultIndex];
    unsigned int scriptIndex = 0;
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case kNextScriptChunk:
            scriptIndex++;
            break;
        case kScriptVariableDataChunk:
        case kScriptVariableNameChunk:
            if (file->GetChunkID() == kScriptVariableDataChunk)
            {
                g_loadedScriptVariable = new ScriptVariableInfo;
                g_loadedScriptVariable->Load(file);
                g_resultScripts[scriptIndex].GetVariableList()->AddTail(g_loadedScriptVariable);
            }
            else if (g_loadedScriptVariable)
            {
                char* variableName = static_cast<char*>(_alloca(file->GetChunkSize()));
                file->GetChunkData(variableName, kScriptVariableNameReadSize);
                g_loadedScriptVariable->m_kName.Set(variableName, 0);
            }
            break;
        case kScriptHeaderChunk:
            file->GetChunkData(g_resultScripts[scriptIndex].GetHeader(), 0);
            if (file->IsEndianConversionRequired())
                g_resultScripts[scriptIndex].GetHeader()->Endian();
            break;
        case kScriptCompiledDataChunk: {
            unsigned int size = file->GetChunkSize();
            char* data = static_cast<char*>(_alloca(size));
            memset(data, 0, size);
            file->GetChunkData(data, 0);
            g_resultScripts[scriptIndex].SetScriptData(size, data);
            break;
        }
        case kScriptFormReferenceChunk: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int formID;
            file->GetChunkData(&formID);
            reference->pForm = reinterpret_cast<TESForm*>(formID);
            g_resultScripts[scriptIndex].GetReferencedObjectList()->AddTail(reference);
            break;
        }
        case kScriptVariableReferenceChunk: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int variableID;
            file->GetChunkData(&variableID);
            reference->m_uiFormID = variableID;
            g_resultScripts[scriptIndex].GetReferencedObjectList()->AddTail(reference);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    g_resultScripts[0].InitItem(this);
    g_resultScripts[1].InitItem(this);
    return &g_resultScripts[resultIndex];
}

struct FUN_00409480_shell : public TESTopicInfo
{
    void FUN_00409480(TESActorBase*);
};

// @fnv 0x00409480
void FUN_00409480_shell::FUN_00409480(TESActorBase* apActor)
{
    *reinterpret_cast<TESActorBase**>(reinterpret_cast<char*>(this) + 0x3C) = apActor;
}

struct FUN_00508d70_shell : public TESForm
{
    bool FUN_00508d70();
};

// @fnv 0x00508d70
bool FUN_00508d70_shell::FUN_00508d70()
{
    return (m_uiFormFlags & 0x2000) ? true : false;
}

void __fastcall RemoveAllLists(void*);

struct FUN_0061c190
{
    BSSimpleList<int> m_kLinkFromList;
    BSSimpleList<int> m_kLinkToList;
    BSSimpleList<int> m_kFollowUpInfoList;

    ~FUN_0061c190();
};

// Destructor that calls RemoveAllLists on this object.
// @fnv 0x0061c190
FUN_0061c190::~FUN_0061c190()
{
    RemoveAllLists(this);
}

struct FUN_0061cc60_node
{
    void AppendResponse(int);
};
struct FUN_0061cc60_holder
{
    FUN_0061cc60_node* head;
    void AddNode(int a);
};
// If head is null, stores a as the head node; otherwise forwards a to head->AppendResponse.
// @fnv 0x0061cc60
void FUN_0061cc60_holder::AddNode(int pNode)
{
    if (head == 0)
    {
        head = (FUN_0061cc60_node*)pNode;
    }
    else
    {
        head->AppendResponse(pNode);
    }
}

struct RecursiveSpinLock
{
    int x[2];
    RecursiveSpinLock();
    ~RecursiveSpinLock();
};
struct FUN_0061ce40_holder
{
    RecursiveSpinLock a;
    RecursiveSpinLock b;
    RecursiveSpinLock c;
    FUN_0061ce40_holder();
};
// @fnv 0x0061ce40
FUN_0061ce40_holder::FUN_0061ce40_holder()
{}

struct FUN_0061cfd0_shell : public TESTopicInfo
{
    void FUN_0061cfd0(char*);
};

// @fnv 0x0061cfd0
void FUN_0061cfd0_shell::FUN_0061cfd0(char* apPrompt)
{
    reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x28)->Set(apPrompt, 0);
}

// Reads the flags byte at offset 0x26 and returns 1 if bit 0x10 is set, 3 if bit 0x20 is set, otherwise 2.
// @fnv 0x0061e720
int __fastcall FUN_0061e720(const char* pThis)
{
    return (pThis[0x26] & 0x10) ? 1 : ((pThis[0x26] & 0x20) ? 3 : 2);
}

struct FUN_0061e760_shell : public TESTopicInfo
{
    TESResponseList* FUN_0061e760(TESResponseList* list);
};

// @fnv 0x0061e760
TESResponseList* FUN_0061e760_shell::FUN_0061e760(TESResponseList* list)
{
    return DuplicateResponseList(list);
}

struct FUN_0061eb40_shell : public TESResponse
{
    void FUN_0061eb40(char*);
};

// @fnv 0x0061eb40
void FUN_0061eb40_shell::FUN_0061eb40(char* apResponseText)
{
    reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x18)->Set(apResponseText, 0);
}

struct FUN_0061f260_shell : public TESTopicInfo
{
    bool FUN_0061f260();
};

// @fnv 0x0061f260
bool FUN_0061f260_shell::FUN_0061f260()
{
    return (bool)(*reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x25) & 0x10);
}

struct FUN_0061f340_shell : public TESTopicInfo
{
    void FUN_0061f340(unsigned short);
};

// @fnv 0x0061f340
void FUN_0061f340_shell::FUN_0061f340(unsigned short usIndex)
{
    *(unsigned short*)((char*)this + 0x20) = usIndex;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0061cb30
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_0061d110 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndDeallocate(unsigned int flags);
};
// Calls the destructor on this object, then deallocates it when bit 0 of flags is set, and returns this.
// @fnv 0x0061d110
void* DelStandIn::DestroyAndDeallocate(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0061d110

struct List_009e03e0
{
    void RemoveAll();
};

struct FUN_0061c330_shell
{
    char pad0[8];
    List_009e03e0 m_list8;
    char pad16[8];
    List_009e03e0 m_list16;
    void RemoveAllLists();
};

// Calls RemoveAll on the list at offset 8, on this object's own list, and on the list at offset 0x10.
// @fnv 0x0061c330
void FUN_0061c330_shell::RemoveAllLists()
{
    m_list8.RemoveAll();
    ((List_009e03e0*)this)->RemoveAll();
    ((List_009e03e0*)((char*)this + 0x10))->RemoveAll();
}

struct FUN_0061cc40_shell
{
    void FUN_0061cc40(int askilllevel);
};

// @fnv 0x0061cc40
void FUN_0061cc40_shell::FUN_0061cc40(int askilllevel)
{
    reinterpret_cast<int*>(this)[10] = askilllevel;
}

struct FUN_0061cc90_shell : TESResponse
{
    void AppendResponse(TESResponse* a);
};

// Walks the response chain to its last node and links the given response onto the end of it.
// @fnv 0x0061cc90
void __thiscall FUN_0061cc90_shell::AppendResponse(TESResponse* apResponse)
{
    TESResponse* next = this;
    while (next->GetNext() != 0)
    {
        next = next->GetNext();
    }
    next->pNext = apResponse;
}

struct FUN_0061e5e0_shell
{
    char _pad[0x20];
    char _pad2[3];
    char m_kMemberDescriptor;
    char* GetFieldPtr();
};

// @fnv 0x0061e5e0
char* FUN_0061e5e0_shell::GetFieldPtr()
{
    return &m_kMemberDescriptor;
}

struct TESFormStub
{
    void __thiscall FUN_00484c50(unsigned int, unsigned int);
};

struct FUN_0061dad0_shell
{
    void __thiscall FUN_0061dad0(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// @fnv 0x0061dad0
void __thiscall FUN_0061dad0_shell::FUN_0061dad0(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    ((TESFormStub*)this)->FUN_00484c50(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x80000000)
        ((unsigned char*)this)[0x22] = 1;
}

struct FUN_0061db00_shell : TESForm
{
    void Revert(unsigned int);
};

// Calls TESForm::Revert with the given buffer and, if the high bit of aiFlags is set, clears byte at offset 0x22.
// @fnv 0x0061db00
void FUN_0061db00_shell::Revert(unsigned int aiFlags)
{
    TESForm::Revert((BGSLoadFormBuffer*)aiFlags);
    if (aiFlags & 0x80000000)
        ((char*)this)[0x22] = 0;
}

struct TESRecipe
{
    void SetSkillLevel(int);
};

struct FUN_006174d0_shell
{
    void CopyResponse(TESResponse* source);
};

struct FUN_0061cb60_shell : TESResponseList
{
    void FUN_0061cb60(TESResponse* head);
};

// @fnv 0x0061cb60
void FUN_0061cb60_shell::FUN_0061cb60(TESResponse* head)
{
    ClearResponses();
    TESResponse* previous = 0;
    while (head)
    {
        TESResponse* response = new TESResponse;
        ((FUN_006174d0_shell*)response)->CopyResponse(head);
        if (previous)
            ((TESRecipe*)previous)->SetSkillLevel((int)response);
        else
            AddTail(response);
        previous = response;
        head = head->GetNext();
    }
}

struct FUN_0061d6a0_shell : public TESTopicInfo
{
    void FUN_0061d6a0(bool set);
};

// @fnv 0x0061d6a0
void FUN_0061d6a0_shell::FUN_0061d6a0(bool set)
{
    if (!IsTemporary() && set && IsFormInitialized())
    {
        TESTopic* owner = TESTopic::GetTopicFromInfo(this);
        if (owner)
            owner->SetAltered(true);
    }
    TESForm::SetAltered(set);
}

extern "C" void* _data_011c16bc;
struct FUN_00680a70_shell
{
    void __thiscall CopyConditions(PerkEntryConditionSet* dst, PerkEntryConditionSet* src);
};
struct FUN_0061e0f0_shell : TESTopicInfo
{
    void __thiscall FUN_0061e0f0(PerkEntryConditionSet* apCond);
};
// @fnv 0x0061e0f0
void __thiscall FUN_0061e0f0_shell::FUN_0061e0f0(PerkEntryConditionSet* apCond)
{
    if (apCond)
        ((FUN_00680a70_shell*)((char*)this + 0x18))->CopyConditions(apCond, (PerkEntryConditionSet*)this);
    else
    {
        PerkEntryConditionSet temp;
        ((FUN_00680a70_shell*)((char*)this + 0x18))->CopyConditions(&temp, (PerkEntryConditionSet*)this);
    }
}

struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct BSStringT_char
{
    BSStringT_char& operator+=(const char*);
};
struct TESResponse_shell : TESResponse
{
    const char* GetDialogueText();
};
struct FUN_0061e2b0_shell : TESTopicInfo
{
    void BuildResponseText(BSStringT<char>& text, bool firstOnly);
};
// @fnv 0x0061e2b0
void FUN_0061e2b0_shell::BuildResponseText(BSStringT<char>& text, bool firstOnly)
{
    ((BSStr*)&text)->Set(0, 0);
    TESResponse* response = DuplicateResponseList(0)->QResponseList();
    while (response)
    {
        ((BSStringT_char*)&text)->operator+=(((TESResponse_shell*)response)->GetDialogueText());
        if (response->GetNext())
            ((BSStringT_char*)&text)->operator+=(" | ");
        if (firstOnly)
            break;
        response = response->GetNext();
    }
}

struct FUN_0061cdc0_shell
{
    char pad1[0x25];
    signed char m_flags;  // +0x25
    void FUN_0061cdc0(bool value);
};

// @fnv 0x0061cdc0
void FUN_0061cdc0_shell::FUN_0061cdc0(bool abSet)
{
    abSet ? m_flags |= 2 : m_flags &= ~2;
}

struct FUN_0061f280_This
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19(unsigned int)
    {}
    char _pad[30];
    unsigned char field22;
    void FUN_0061f280();
};
// @fnv 0x0061f280
void FUN_0061f280_This::FUN_0061f280()
{
    field22 = 0;
    v19(0x80000000);
}

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011d0dc8;
int __fastcall FUN_0061e720(const char*);
struct CondOps
{
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*, bool&, bool);
};
struct QuestOps
{
    CondOps* GetConditions();
};
struct AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetActorValue(int);
};
struct ActorS
{
    char pad[0xa4];
    AVOwner avOwner;
};
struct FUN_0061e600_t : public TESTopicInfo
{
    bool FUN_00619b20();
    bool IsNew();
    bool FUN_0061e600(bool& rbDeferred, TESQuest* apQuest, TESObjectREFR* apSpeaker, TESObjectREFR* apListener);
};

// @fnv 0x0061e600
bool FUN_0061e600_t::FUN_0061e600(bool& rbDeferred, TESQuest* apQuest, TESObjectREFR* apSpeaker,
                                  TESObjectREFR* apListener)
{
    bool bResult;
    ActorS* pActor;
    if (IsDeleted())
        return false;
    if (FUN_00619b20() && IsNew())
        return false;
    {
        int iType = FUN_0061e720((const char*)this);
        pActor = 0;
        if (apListener && ((TESForm*)apListener)->IsActor())
            pActor = (ActorS*)apListener;
        if (pActor && pActor->avOwner.GetActorValue(9) <= *g_011d0dc8.Int())
        {
            if (iType == 3)
                return false;
        }
        else if (iType == 1)
            return false;
        bResult = false;
        {
            bool bQuestOK = true;
            if (apQuest)
                bQuestOK =
                    ((QuestOps*)apQuest)->GetConditions()->ContainsTrait(apSpeaker, apListener, rbDeferred, false);
            if (bQuestOK)
                bResult =
                    ((CondOps*)((Script*)this)->GetHeader())->ContainsTrait(apSpeaker, apListener, rbDeferred, false);
        }
    }
    return bResult;
}

struct BSS
{
    virtual ~BSS();
    unsigned long value;
};

struct ListX
{
    virtual ~ListX();
    unsigned long value;
};

struct Base5a
{
    virtual ~Base5a();
};

struct FUN_0061ceb0 : public Base5a
{
    unsigned char basePadding[0x14];
    PerkEntryConditionSet m_kInfoConditions;
    unsigned char conditionPadding[8];
    BSS m_kPrompt;
    ListX m_kAddTopicList;

    ~FUN_0061ceb0();
};

// @fnv 0x0061ceb0
FUN_0061ceb0::~FUN_0061ceb0()
{
    ((TESTopicInfo*)this)->TESTopicInfo::ClearData();
}

extern unsigned int kGroupFormType;

struct FUN_00485b60
{
    bool FUN_00485be0(unsigned int);
};

struct GROUP_PARENT_CHECK
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual bool CheckFormGRUP(FormRecordHeader*, bool, bool) = 0;
};

struct FUN_0061d820_shell
{
    bool CheckGroupForm(FormRecordHeader*, bool, bool);
};

// @fnv 0x0061d820
bool FUN_0061d820_shell::CheckGroupForm(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval;
    TESTopic* pparenttopic;

    bretval = false;
    if (apGroupFORM)
    {
        if (reinterpret_cast<unsigned int*>(apGroupFORM)[0] == kGroupFormType)
        {
            pparenttopic = TESTopic::GetTopicFromInfo(reinterpret_cast<TESTopicInfo*>(this));

            if (pparenttopic)
            {
                if (abAllowParentGroups)
                {
                    bretval = reinterpret_cast<GROUP_PARENT_CHECK*>(pparenttopic)
                                  ->CheckFormGRUP(apGroupFORM, abAllowParentGroups, abCurrentOnly);
                }

                if (!bretval && reinterpret_cast<unsigned int*>(apGroupFORM)[3] == 7 &&
                    reinterpret_cast<FUN_00485b60*>(pparenttopic)
                        ->FUN_00485be0(reinterpret_cast<unsigned int*>(apGroupFORM)[2]))
                {
                    bretval = true;
                }
            }
        }
    }

    return bretval;
}

struct TopicLinkLists
{
    BSSimpleList<int>* GetLinkFromList();
    BSSimpleList<int>* GetLinkToList();
    BSSimpleList<int>* GetFollowUpList();
    void ClearLinks();
    void CopyLinksFrom(int unused, TopicLinkLists* source);
};

// Clears this object's link lists, then copies the source's from-list, to-list and follow-up-list items into them.
// @fnv 0x0061c210
void TopicLinkLists::CopyLinksFrom(int unused, TopicLinkLists* source)
{
    if (!source)
        return;
    ClearLinks();
    int item9;
    {
        BSSimpleList<int>* iter = 0;
        item9 = 0;
        for (iter = source->GetLinkFromList(); iter && iter->GetItem();)
        {
            item9 = iter->GetItem();
            iter = iter->GetNext();
            GetLinkFromList()->AddTail(item9);
        }
        iter = source->GetLinkToList();
        item9 = 0;
        for (; iter && iter->GetItem();)
        {
            item9 = iter->GetItem();
            iter = iter->GetNext();
            GetLinkToList()->AddTail(item9);
        }
    }
    BSSimpleList<int>* follow2 = source->GetFollowUpList();
    int followItem4;
    while (follow2 && (followItem4 = follow2->GetItem()) != 0)
    {
        follow2 = follow2->GetNext();
        GetFollowUpList()->AddTail(followItem4);
    }
}

struct DialogueFormType : TESForm
{
    int FUN_00401170();
};
struct DialogueTopicCompare
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual bool Compare(TESTopic*);
};
TESTopic* FindTopicByInfo(TESForm*);
struct TopicInfoCompare : TESTopicInfo
{
    bool IsLessThan(TESForm*);
    bool FUN_0061d710(TESForm*);
};
// @fnv 0x0061d710
bool TopicInfoCompare::FUN_0061d710(TESForm* form)
{
    bool bResult = false;
    switch (static_cast<DialogueFormType*>(form)->FUN_00401170())
    {
    case 0x46: {
        TESTopicInfo* pOtherInfo = dynamic_cast<TESTopicInfo*>(form);
        if (pOtherInfo)
        {
            TESTopic* pSourceTopic = FindTopicByInfo(this);
            TESTopic* otherOwner = FindTopicByInfo(pOtherInfo);
            if (otherOwner && pSourceTopic && otherOwner != pSourceTopic)
            {
                bResult = reinterpret_cast<DialogueTopicCompare*>(pSourceTopic)->Compare(otherOwner);
            }
        }
        break;
    }
    case 0x45: {
        TESTopic* topic = dynamic_cast<TESTopic*>(form);
        if (topic)
        {
            TESTopic* owner = FindTopicByInfo(this);
            if (owner && owner != topic)
                bResult = reinterpret_cast<DialogueTopicCompare*>(owner)->Compare(topic);
        }
        break;
    }
    default:
        bResult = IsLessThan(form);
    }
    return bResult;
}

struct FUN_0061d8c0_input
{
    unsigned int unk00;
    unsigned int unk04;
    TESTopicInfo* unk08;
    unsigned int unk0C;
};

struct FUN_0061d8c0_output
{
    TESResponse* pResponse;
    unsigned int unk04;
    unsigned int formID;
    unsigned int unk0C;
    unsigned int unk10;
};

extern TESTopicInfo* DAT_01187344;
extern TESResponse* DAT_01187020;
int __cdecl FindTopicByInfo(void* object);

struct FUN_0061d8c0_shell
{
    void GetResponseForTopicInfo(FUN_0061d8c0_output* output, FUN_0061d8c0_input* input);
};

// @fnv 0x0061d8c0
void FUN_0061d8c0_shell::GetResponseForTopicInfo(FUN_0061d8c0_output* output, FUN_0061d8c0_input* input)
{
    int iVar1;

    if (output != 0)
    {
        output->pResponse = 0;
        if (input != 0)
        {
            switch (input->unk0C)
            {
            case 0:
                if (input->unk08 == DAT_01187344)
                {
                    iVar1 = FindTopicByInfo(this);
                    if (iVar1 != 0)
                    {
                        output->pResponse = DAT_01187020;
                        output->unk0C = 7;
                        output->formID = ((TESForm*)iVar1)->GetFormID();
                        output->unk04 = 0;
                        output->unk10 = 0;
                    }
                }
                break;
            }
        }
    }
}

struct DebugTextOut;
int __cdecl DebugTextPrintf(DebugTextOut* out, const char* fmt, ...);

struct TESResponseText : TESResponse
{
    const char* GetDialogueText();
};

struct ResponseListHolder
{
    TESResponseText* QHead();
};

struct TopicInfoDebug : TESTopicInfo
{
    ResponseListHolder* GetResponses(int list);
    const char* GetFormTypeName();
    const char* GetEditorIDText();
    void PrintDebugInfo(DebugTextOut* out);
};

// Builds topic, quest and response text fragments and prints the form type, editor ID, form ID and those fragments via DebugTextPrintf.
// @fnv 0x0061d950
void TopicInfoDebug::PrintDebugInfo(DebugTextOut* out)
{
    char topicText3[260];
    topicText3[0] = 0;
    TESTopic* topicA = TESTopic::GetTopicFromInfo(this);
    if (topicA)
    {
        sprintf(topicText3, ", Topic '%s' (%08X)", topicA->GetName(), topicA->GetFormID());
    }
    char questText2[260];
    questText2[0] = 0;
    if (topicA && IsFormInitialized())
    {
        TESQuest* quest = topicA->GetParentQuest(this);
        if (quest)
        {
            sprintf(questText2, "Quest '%s' (%08X)", quest->GetEditorName(), quest->GetFormID());
        }
    }
    char responseText9[260];
    responseText9[0] = 0;
    TESResponseText* response = GetResponses(0)->QHead();
    if (response)
    {
        sprintf(responseText9, ", Text: \"%s\"", response->GetDialogueText());
    }
    DebugTextPrintf(out, "%s Form '%s' (%08X): %s%s%s", GetFormTypeName(), GetEditorIDText(), GetFormID(), questText2,
                    topicText3, responseText9);
}

struct TopicInfoCopy : TESTopicInfo
{
    void FUN_0061e330(TESForm* form);
    void FUN_004851b0(TESForm* form);
    TopicInfoData* GetFieldPtr();
    void FUN_0061d250();
    void FUN_0061d230();
    TESResponseList* FUN_0061e780(int create);
    BSStringT<char>* GetExtraDataList();
    SPEECH_CHALLENGE_LEVEL FUN_008041a0();
    PerkEntryConditionSet* FUN_00500940();
    TESTopicInfoData* GetField38();
    void FUN_0061e180(TESTopicInfoData* data);
    TESQuest* FUN_006733e0();
    void FUN_00673400(TESQuest* quest);
    bool FUN_004013e0();
    void FUN_00484ab0(bool value);
};
struct ResponseCopy : TESResponse
{
    void CopyResponse(TESResponse* source);
};
struct ScriptCopy : Script
{
    void CopyFromScript(Script* source);
};
// Copies topic info data from another TESTopicInfo: add-topic list, responses, prompt, perk/actor value, difficulty, speaker, result scripts and quest.
// @fnv 0x0061e330
void TopicInfoCopy::FUN_0061e330(TESForm* form)
{
    TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(form);
    if (!topic)
        return;
    BSSimpleList<TESTopic*>* source = 0;
    TESTopic* node = 0;
    FUN_004851b0(form);
    m_Data = static_cast<TopicInfoCopy*>(topic)->GetFieldPtr()[0];
    FUN_0061d250();
    source = topic->GetAddTopicList();
    while (source && source->GetItem())
    {
        node = source->GetItem();
        source = source->GetNext();
        GetAddTopicList()->AddTail(node);
    }
    FUN_0061d230();
    TESResponse* response = static_cast<TopicInfoCopy*>(topic)->FUN_0061e780(0)->QResponseList();
    while (response)
    {
        TESResponse* copy = new TESResponse;
        static_cast<ResponseCopy*>(copy)->CopyResponse(response);
        FUN_0061e780(0)->AddTail(copy);
        response = response->GetNext();
    }
    SetPrompt(static_cast<TopicInfoCopy*>(topic)->GetExtraDataList()->String());
    if (topic->m_pPerkSkillStat)
    {
        switch (topic->m_pPerkSkillStat->GetFormType())
        {
        case ENUM_FORM_ID_PERK_ID:
            SetPerk(reinterpret_cast<BGSPerk*>(topic->m_pPerkSkillStat));
            break;
        case ENUM_FORM_ID_AVIF_ID:
            SetActorValue(reinterpret_cast<ActorValueInfo*>(topic->m_pPerkSkillStat));
            break;
        default:
            m_pPerkSkillStat = topic->m_pPerkSkillStat;
        }
    }
    else
    {
        SetPerk(0);
    }
    SetDifficultyLevel(static_cast<TopicInfoCopy*>(topic)->FUN_008041a0());
    SetSpeaker(topic->GetSpeaker());
    static_cast<ScriptCopy*>(GetResultScript(0))->CopyFromScript(topic->GetResultScript(0));
    static_cast<ScriptCopy*>(GetResultScript(1))->CopyFromScript(topic->GetResultScript(1));
    reinterpret_cast<FUN_0061f340_shell*>(this)->FUN_0061f340(topic->GetInfoIndex());
    reinterpret_cast<FUN_0061e0f0_shell*>(this)->FUN_0061e0f0(static_cast<TopicInfoCopy*>(topic)->FUN_00500940());
    if (static_cast<TopicInfoCopy*>(topic)->GetField38())
        FUN_0061e180(static_cast<TopicInfoCopy*>(topic)->GetField38());
    FUN_00673400(static_cast<TopicInfoCopy*>(topic)->FUN_006733e0());
    FUN_00484ab0(static_cast<TopicInfoCopy*>(topic)->FUN_004013e0());
}

extern "C" void* __cdecl _alloca(unsigned int);
void FUN_00403d30(void*, int, unsigned int);
struct ScriptOps : Script
{
    void FUN_00484490();
    void FUN_00484ab0(int);
};
struct FileOps : TESFile
{
    bool GetChunkData();
};
struct FUN_0061eb60_class : TESTopicInfo
{
    Script* FUN_0061eb60(unsigned int);
};
// Returns one of two cached result Script objects for this topic info, resetting and reloading them from the file's SC* chunks when the cache misses.
// @fnv 0x0061eb60
Script* FUN_0061eb60_class::FUN_0061eb60(unsigned int auiIndex)
{
    unsigned int h = auiIndex;
    if (this == g_cachedResultScriptInfo)
        return &g_resultScripts[h];
    g_cachedResultScriptInfo = this;
    Script i;
    g_resultScripts[0].CopyScriptContents(&i);
    ((ScriptOps*)&g_resultScripts[0])->FUN_00484490();
    g_resultScripts[0].GetHeader()->m_bQuest = false;
    g_resultScripts[1].CopyScriptContents(&i);
    ((ScriptOps*)&g_resultScripts[1])->FUN_00484490();
    g_resultScripts[1].GetHeader()->m_bQuest = false;
    if (!HasResultScript())
        return &g_resultScripts[h];
    ((ScriptOps*)&g_resultScripts[0])->FUN_00484ab0(0);
    ((ScriptOps*)&g_resultScripts[1])->FUN_00484ab0(0);
    TESFile* a = GetFile(-1);
    if (!a || !m_ulTopicFlags)
        return &g_resultScripts[h];
    a = a->GetParentTESFile();
    if (!a->SetOffset(m_ulTopicFlags))
        return &g_resultScripts[h];
    unsigned char p = a->GetTESForm();
    if (p != 0x46)
        return &g_resultScripts[h];
    int s = 0;
    int f;
    while (f = a->GetChunkID())
    {
        switch (f)
        {
        case 0x5458454e:
            s += 1;
            break;
        case 0x44534c53:
        case 0x52564353:
            if (a->GetChunkID() == 0x44534c53)
            {
                g_loadedScriptVariable = new ScriptVariableInfo;
                g_loadedScriptVariable->Load(a);
                g_resultScripts[s].GetVariableList()->AddTail(g_loadedScriptVariable);
            }
            else if (g_loadedScriptVariable)
            {
                char* name = (char*)_alloca(a->GetChunkSize());
                a->GetChunkData(name, 0x200);
                g_loadedScriptVariable->m_kName.Set(name, 0);
            }
            break;
        case 0x52484353:
            a->GetChunkData(g_resultScripts[s].GetHeader(), 0);
            if (((FileOps*)a)->GetChunkData())
                g_resultScripts[s].GetHeader()->Endian();
            break;
        case 0x41444353: {
            unsigned int size = a->GetChunkSize();
            char* data = (char*)_alloca(size);
            FUN_00403d30(data, 0, size);
            a->GetChunkData(data, 0);
            g_resultScripts[s].SetScriptData(size, data);
            break;
        }
        case 0x4f524353: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int id;
            a->GetChunkData(&id);
            reference->pForm = (TESForm*)id;
            g_resultScripts[s].GetReferencedObjectList()->AddTail(reference);
            break;
        }
        case 0x56524353: {
            ScriptReferencedObject* variable = new ScriptReferencedObject;
            unsigned int id;
            a->GetChunkData(&id);
            variable->m_uiFormID = id;
            g_resultScripts[s].GetReferencedObjectList()->AddTail(variable);
            break;
        }
        }
        if (!a->NextChunk())
            break;
    }
    g_resultScripts[0].InitItem(this);
    g_resultScripts[1].InitItem(this);
    return &g_resultScripts[h];
}

extern GlobalObject2_0040c150 g_011cc06c;
extern GlobalObject2_0040c150 g_011cc03c;
extern GlobalObject2_0040c150 g_011cc058;
extern GlobalObject2_0040c150 g_011cc024;
extern GlobalObject2_0040c150 g_011cbf54;

class B61F2B0Object
{
  public:
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
    int m_iZ;

    int FUN_0061f2b0();
};

// @fnv 0x0061f2b0
int B61F2B0Object::FUN_0061f2b0()
{
    switch (m_iZ)
    {
    case 1:
        return *g_011cc06c.Int();
    case 2:
        return *g_011cc03c.Int();
    case 3:
        return *g_011cc058.Int();
    case 4:
        return *g_011cc024.Int();
    case 5:
        return *g_011cbf54.Int();
    }
    return -1;
}

extern unsigned int kGroupFormType;
TESForm* LookupFormByID(unsigned int id);
struct S_00619510_Obj
{
    unsigned int unk00;
    int unk04;
    unsigned int unk08;
    int unk0C;
};
struct FUN_00619510_shell
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
    virtual bool v15(TESTopic* t);
    bool IsFormTypeBelowThreshold(S_00619510_Obj* o);
    bool IsFormInGroup(S_00619510_Obj* arg);
};
// @fnv 0x00619510
bool FUN_00619510_shell::IsFormInGroup(S_00619510_Obj* pGroupObj)
{
    bool result = false;
    if (pGroupObj != 0 && pGroupObj->unk00 == kGroupFormType)
    {
        switch (pGroupObj->unk0C)
        {
        case 0:
            result = IsFormTypeBelowThreshold(pGroupObj);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            result = false;
            break;
        case 7: {
            TESTopic* t = dynamic_cast<TESTopic*>(LookupFormByID(pGroupObj->unk08));
            if (t)
                result = v15(t);
            break;
        }
        }
    }
    return result;
}

struct FUN_0061ce10
{
    virtual ~FUN_0061ce10();
};
// Destructor for the FUN_0061ce10 class that performs no additional cleanup.
// @fnv 0x0061ce10
FUN_0061ce10::~FUN_0061ce10()
{}
