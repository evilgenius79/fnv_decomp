// fallout_shared/tesquest.cpp: TESQuest, PlayerQuestData, FakeQuest, QuestSaveSize and more (39 functions)

#include "tesquest_types.h"

// @fnv 0x0060d700
unsigned int TESQuest::GetStageMask()
{
    return m_ucEnabled;
}

// @fnv 0x0060c740
void TESQuest::ResetFormData()
{
    SetEnabled(true);
    m_ucEnabled = 0;
}

// Deletes every stage object in the quest's stage list and removes each entry until the list is empty.
// @fnv 0x0060c7d0
void TESQuest::RemoveAllStages()
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    while (stages && !stages->IsEmpty())
    {
        delete stages->GetItem();
        stages->RemoveHead();
    }
}

// Walks the quest's stage list and returns whether the stage with the given index is marked done, or false if not found.
// @fnv 0x0060d600
bool TESQuest::HasStage(unsigned char ucStageIndex)
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    while (stages && !stages->IsEmpty())
    {
        if (stages->GetItem()->GetIndex() == ucStageIndex)
            return stages->GetItem()->GetDone();
        stages = stages->GetNext();
    }
    return false;
}

// @fnv 0x0060c760
void TESQuest::ClearData()
{
    GetConditions()->InitializeConditionItems();
    RemoveAllStages();
    ClearObjectives();
    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = 0;
    }
}

// Deletes every BGSQuestObjective in the objective list and removes each entry until the list is empty.
// @fnv 0x0060c870
void TESQuest::ClearObjectives()
{
    BSSimpleList<BGSQuestObjective*>* objectives = GetObjectiveList();
    while (objectives && !objectives->IsEmpty())
    {
        delete objectives->GetItem();
        objectives->RemoveHead();
    }
}

// @fnv 0x0060f110
void TESQuest::GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                       BSSimpleList<BGSQuestObjective*>* objectives)
{
    if (!targets)
        return;
    targets->RemoveAll();
    if (GetCompleted())
        return;
    BSSimpleList<BGSQuestObjective*>* pObjectiveNode = GetObjectiveList();
    while (pObjectiveNode && pObjectiveNode->GetItem())
    {
        if (objectives->IsInList(pObjectiveNode->GetItem()))
            pObjectiveNode->GetItem()->GetTargetsAndObjectives(targets);
        pObjectiveNode = pObjectiveNode->GetNext();
    }
}

// Scans the stage list for the highest done stage index and stores it into the quest's highest completed stage field if greater.
// @fnv 0x0060d670
void TESQuest::UpdateStageMask()
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    unsigned char currentStage = 0;
    while (stages && !stages->IsEmpty())
    {
        QuestStage* stage = stages->GetItem();
        if (stage->GetDone() && stage->GetIndex() > currentStage)
            currentStage = stage->GetIndex();
        stages = stages->GetNext();
    }
    if (currentStage > m_ucEnabled)
        m_ucEnabled = currentStage;
}

// @fnv 0x0060d510
bool TESQuest::IsStageComplete(unsigned char ucStageIndex)
{
    BSSimpleList<QuestStage*>* stages = GetStageList();
    while (stages && !stages->IsEmpty())
    {
        if (stages->GetItem()->GetIndex() == ucStageIndex)
        {
            if (!GetCompleted() || GetAllowRepeatStages())
                SetEnabled(true);
            if (ucStageIndex > m_ucEnabled)
                m_ucEnabled = ucStageIndex;
            stages->GetItem()->MarkDone(this, false);
            MarkAsModified(0x80000000U);
            return true;
        }
        stages = stages->GetNext();
    }
    return false;
}

// @fnv 0x0060EFD0
bool TESQuest::HasTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                       BSSimpleList<BGSQuestObjective*>* objectives)
{
    BSSimpleList<RegionObjectEntry*>* currentTarget = targets;
    BSSimpleList<BGSQuestObjective*>* currentObjective = GetObjectiveList();
    if (currentTarget && currentObjective)
    {
        while (currentObjective)
        {
            if (currentObjective->GetItem() && currentObjective->GetItem()->GetState() == QOS_DISPLAYED &&
                objectives->IsInList(currentObjective->GetItem()))
            {
                BSSimpleList<RegionObjectEntry*>* objectiveTarget = currentObjective->GetItem()->GetTargetList();
                while (objectiveTarget)
                {
                    RegionObjectEntry* target = objectiveTarget->GetItem();
                    if (target && target->GetConditions()->ContainsTrait(target->GetReference(false), 0))
                    {
                        if (!currentTarget || !currentTarget->GetItem() || currentTarget->GetItem() != target)
                            return false;
                        if (currentTarget)
                            currentTarget = currentTarget->GetNext();
                    }
                    objectiveTarget = objectiveTarget->GetNext();
                }
            }
            currentObjective = currentObjective->GetNext();
        }
    }
    if (currentTarget && !currentTarget->IsEmpty())
        return false;
    return true;
}

// @fnv 0x0060CBA0
void TESQuest::InitItem()
{
    if (IsFormInitialized())
        return;
    tESScriptableFormComponent.InitItem(this);
    if (tESScriptableFormComponent.GetScript())
    {
        m_pScriptLocals = tESScriptableFormComponent.GetScript()->GetOrCreateScriptLocals();
        tESScriptableFormComponent.GetScript()->SetOwnerQuest(this);
        if (m_pScriptLocals)
            SetFormFlags(0x40000000);
        if (bActivateAllQuestScripts.Bool()->b)
            SetEnabled(true);
    }
    if (GetConditions())
        GetConditions()->InitItem(this);
    BSSimpleList<QuestStage*>* stage = GetStageList();
    while (stage && !stage->IsEmpty())
    {
        stage->GetItem()->InitItem(this);
        stage = stage->GetNext();
    }
    BSSimpleList<BGSQuestObjective*>* objective = GetObjectiveList();
    while (objective && !objective->IsEmpty())
    {
        objective->GetItem()->InitItem(this);
        objective = objective->GetNext();
    }
    SetStartsEnabled(GetEnabled());
    SetInitializationState(true);
}

// @fnv 0x0060EE40
void TESQuest::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    if (buffer->GetOldChangeFlags(0x80000000U))
    {
        BSSimpleList<QuestStage*>* stages = &m_kStageList;
        while (stages)
        {
            QuestStage* stage = stages->GetItem();
            if (stage)
            {
                stage->MarkDone(false);
                BSSimpleList<PlayerQuestData*>* items = stage->GetStageItemList();
                while (items)
                {
                    PlayerQuestData* item = items->GetItem();
                    if (item && item->GetLogDate())
                    {
                        delete item->GetLogDate();
                        item->SetLogDate(0);
                    }
                    items = items->GetNext();
                }
            }
            stages = stages->GetNext();
        }
        m_ucEnabled = 0;
    }
    if (buffer->GetOldChangeFlags(0x40000000U) && m_pScriptLocals)
        m_pScriptLocals->Revert(buffer);
    if (buffer->GetOldChangeFlags(0x20000000U))
    {
        BSSimpleList<BGSQuestObjective*>* objectives = &m_kObjectives;
        while (objectives)
        {
            BGSQuestObjective* objective = objectives->GetItem();
            if (objective)
                objective->SetState(QOS_DORMANT);
            objectives = objectives->GetNext();
        }
    }
}

enum QUEST_CHUNK_ID
{
    CHUNK_EDID = 0x44494445,
    CHUNK_OBND = 0x444e424f,
    CHUNK_SCRI = 0x49524353,
    CHUNK_FULL = 0x4c4c5546,
    CHUNK_ICON = 0x4e4f4349,
    CHUNK_DATA = 0x41544144,
    CHUNK_QOBJ = 0x4a424f51,
    CHUNK_QSTA = 0x41545351,
    CHUNK_INDX = 0x58444e49,
    CHUNK_QSDT = 0x54445351,
    CHUNK_SCDA = 0x41444353,
    CHUNK_SLSD = 0x44534c53,
    CHUNK_SCVR = 0x52564353,
    CHUNK_SCRO = 0x4f524353,
    CHUNK_SCHR = 0x52484353,
    CHUNK_SCRV = 0x56524353,
    CHUNK_CNAM = 0x4d414e43,
    CHUNK_CTDA = 0x41445443
};

// @fnv 0x0060C8E0
BGSQuestObjective* TESQuest::GetObjective(unsigned int index)
{
    struct ObjectiveSearch
    {
        BSSimpleList<BGSQuestObjective*>* objectives;
        unsigned int objectiveIndex;
    } search;
    search.objectives = GetObjectiveList();
    search.objectiveIndex = 0;
    while (search.objectives && !search.objectives->IsEmpty())
    {
        BGSQuestObjective* objective = search.objectives->GetItem();
        if (objective && objective->GetIndex() == index)
            return objective;
        search.objectives = search.objectives->GetNext();
    }
    return 0;
}

// @fnv 0x0060EAF0
void TESQuest::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags(2))
        buffer->ReadTypedData(&data.m_ucEntryType, 1);
    if (buffer->GetChangeFlags(4))
        buffer->ReadTypedData(&data.fQuestDelayTime, 4);
    if (buffer->GetChangeFlags(0x80000000U))
    {
        unsigned int stageCount = buffer->ReadElementCount();
        for (unsigned int i = 0; i < stageCount; ++i)
        {
            unsigned char stageIndex = 0;
            bool done = false;
            buffer->ReadTypedData(&stageIndex, 1);
            buffer->ReadTypedData(&done, 1);
            {
                QuestStage* stage = GetStage(stageIndex);
                if (stage)
                    stage->MarkDone(done);
                else
                    LogWarning("SAVELOAD: Could not find stage %i in quest %s during load.", stageIndex,
                               GetEditorName());
                unsigned int itemCount = buffer->ReadElementCount();
                for (unsigned int j = 0; j < itemCount; ++j)
                {
                    unsigned char itemIndex = 0;
                    bool hasDate = false;
                    Date logDate;
                    buffer->ReadTypedData(&itemIndex, 1);
                    buffer->ReadTypedData(&hasDate, 1);
                    if (hasDate)
                        buffer->ReadTypedData(&logDate, 4);
                    if (hasDate && stage)
                    {
                        PlayerQuestData* item = stage->GetStageItemByIndex(itemIndex);
                        if (item)
                            item->SetLogDate(new Date(logDate));
                    }
                }
            }
        }
        m_ucEnabled = 0;
        UpdateStageMask();
    }
    if (buffer->GetChangeFlags(0x40000000U))
    {
        if (m_pScriptLocals)
            m_pScriptLocals->LoadGame(buffer);
        else
        {
            ScriptLocals locals;
            locals.LoadGame(buffer);
        }
    }
    if (buffer->GetChangeFlags(0x20000000U))
    {
        unsigned int objectiveCount = buffer->ReadElementCount();
        for (unsigned int k = 0; k < objectiveCount; ++k)
        {
            struct SavedObjectiveState
            {
                unsigned int index;
                QUEST_OBJECTIVE_STATE state;
            } savedObjective;
            savedObjective.index = 0;
            savedObjective.state = QOS_DORMANT;
            buffer->ReadTypedData(&savedObjective.index, 4);
            buffer->ReadTypedData(&savedObjective.state, 4);
            BGSQuestObjective* objective = GetObjective(savedObjective.index);
            if (objective)
                objective->SetState(savedObjective.state);
        }
    }
}

// @fnv 0x0060CEB0
bool TESQuest::Load(TESFile* file)
{
    QuestStage* stage;
    {
        unsigned char formType = file->GetTESForm();
        if (formType != FORM_QUEST)
            return false;
        stage = 0;
        PlayerQuestData* item = 0;
        RegionObjectEntry* target = 0;
        BGSQuestObjective* objective = 0;
        LoadRecordHeader(file);
        SetInitializationState(false);
        unsigned char itemIndex = 0;
        int chunk;
        while ((chunk = file->GetChunkID()) != 0)
        {
            switch (chunk)
            {
            case CHUNK_EDID: {
                char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
                file->GetChunkData(editorID, 0x200);
                SetEditorID_AtRuntime(editorID);
                break;
            }
            case CHUNK_OBND:
                readOBNDSubRecord(file);
                break;
            case CHUNK_SCRI: {
                unsigned int script = 0;
                file->GetChunkData(&script);
                tESScriptableFormComponent.SetScript(reinterpret_cast<Script*>(script));
                tESScriptableFormComponent.InitItem(this);
                break;
            }
            case CHUNK_FULL:
                TESFullNameLoader::LoadFullNameChunk(this ? &tESFullNameComponent : 0, file);
                break;
            case CHUNK_ICON:
                TESTexture::ReadTextureData(this ? &tESIconComponent : 0, file);
                break;
            case CHUNK_DATA:
                ReadTypedData(file, &data, sizeof(data));
                break;
            case CHUNK_QOBJ:
                objective = new BGSQuestObjective;
                objective->Load(file);
                GetObjectiveList()->AddTail(objective);
                objective->SetOwnerQuest(this);
                break;
            case CHUNK_QSTA:
                stage = 0;
                item = 0;
                target = new RegionObjectEntry;
                target->Load(file);
                if (!objective)
                {
                    objective = new BGSQuestObjective;
                    GetObjectiveList()->AddTail(objective);
                    objective->SetOwnerQuest(this);
                }
                objective->GetTargetList()->AddTail(target);
                break;
            case CHUNK_INDX:
                stage = new QuestStage;
                stage->Load(file);
                GetStageList()->AddTail(stage);
                break;
            case CHUNK_QSDT:
                if (stage)
                {
                    item = new PlayerQuestData;
                    item->Load(file);
                    item->SetIndex(itemIndex);
                    ++itemIndex;
                    stage->GetStageItemList()->AddTail(item);
                }
                continue;
                break;
            case CHUNK_SCDA:
            case CHUNK_SLSD:
            case CHUNK_SCVR:
            case CHUNK_SCRO:
            case CHUNK_SCHR:
            case CHUNK_SCRV:
                if (item)
                {
                    item->Load(file);
                    continue;
                }
                break;
            case CHUNK_CNAM:
                if (item)
                    item->SetHasLogEntry(true);
                break;
            case CHUNK_CTDA:
                if (item)
                    item->GetConditions()->Load(file);
                else if (target)
                    target->GetConditions()->Load(file);
                else
                    GetConditions()->Load(file);
                break;
            }
            if (!file->NextChunk())
                break;
        }
        if (file->IsEndianConversionRequired())
            data.Endian();
        return true;
    }
}

// @fnv 0x0060c9c0
void TESQuest::SetEnabled(bool enabled)
{
    enabled
        ? reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType |= 1
        : reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType &= ~1;
    MarkAsModified(2);
}

// @fnv 0x0060cd00
void TESQuest::SetStartsEnabled(bool enabled)
{
    enabled
        ? reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType |= 16
        : reinterpret_cast<QuestData*>(reinterpret_cast<TESRecipe*>(this)->GetIngredientList())->m_ucEntryType &= ~16;
}

// @fnv 0x0060d4d0
void TESQuest::RunScript()
{
    if (tESScriptableFormComponent.GetScript())
        tESScriptableFormComponent.GetScript()->Run(0, m_pScriptLocals, 0, false);
}

// @fnv 0x0060d490
void PlayerQuestData::SetHasLogEntry(bool abHasLogEntry)
{
    bHasLogEntry = abHasLogEntry;
}

// @fnv 0x0060d4b0
void PlayerQuestData::SetIndex(unsigned char index)
{
    m_ucClipIdentifier = index;
}

struct FUN_004b1000_shell
{
    short a[2];
    short* CopyShortPair(const short* b);
};

// Copies the first two shorts from b into the object's a array and returns a pointer to it.
// @fnv 0x004b1000
short* FUN_004b1000_shell::CopyShortPair(const short* pSource)
{
    a[0] = pSource[0];
    a[1] = pSource[1];
    return a;
}

struct MiscStatManager
{
    enum MiscStat
    {
    };
    static void __cdecl AddMiscStat(MiscStat id, int val);
};

// @fnv 0x0060cad0
void FUN_0060cad0(int aeStatId)
{
    MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)aeStatId, -1);
}

struct FUN_0060d5e0_shell : TESRecipe
{
    bool HasFlag8();
};

// @fnv 0x0060d5e0
bool FUN_0060d5e0_shell::HasFlag8()
{
    return (reinterpret_cast<unsigned char*>(this->GetIngredientList())[0] & 8) != 0;
}

struct FUN_0060da90_shell
{
    void* GetOffsetPointer();
};

// @fnv 0x0060da90
void* FUN_0060da90_shell::GetOffsetPointer()
{
    return reinterpret_cast<char*>(this) + 0x6B0;
}

struct FUN_00737e30_shell
{
    unsigned int m_210;
    unsigned int GetFieldAt210();
};

// @fnv 0x00737e30
unsigned int FUN_00737e30_shell::GetFieldAt210()
{
    return ((unsigned int*)this)[0x210 / 4];
}

struct FUN_004b0fa0_shell
{
    short m_iWordAt00;
    short m_cByteAtOffset2;
    FUN_004b0fa0_shell();
};

// @fnv 0x004b0fa0
FUN_004b0fa0_shell::FUN_004b0fa0_shell()
{
    m_iWordAt00 = 0;
    m_cByteAtOffset2 = 0;
}

struct FUN_0060d8d0_shell : TESRecipe
{
    bool HasFlag0x10();
};

// @fnv 0x0060d8d0
bool FUN_0060d8d0_shell::HasFlag0x10()
{
    return (*reinterpret_cast<unsigned char*>(this->GetIngredientList()) & 0x10) != 0;
}

struct FUN_0060e680_shell
{
    void SetFlags(unsigned int arg);
};

// @fnv 0x0060e680
void FUN_0060e680_shell::SetFlags(unsigned int auiFlags)
{
    *(unsigned int*)((char*)this + 0x54) = *(unsigned int*)((char*)this + 0x54) | auiFlags;
}

void __cdecl _Deallocate(void*);
struct FakeQuest
{
    void FUN_0060c660();
    void* FUN_0060c630(unsigned int);
};
// @fnv 0x0060c630
void* FakeQuest::FUN_0060c630(unsigned int flags)
{
    FUN_0060c660();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void __cdecl _security_check_cookie(unsigned int);
extern "C" unsigned int DAT_011c16bc;
extern "C" unsigned int __cdecl BSStringLength(const char*);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct BSStringT_char
{
    char* StrCmp(const char*, bool) const;
};
struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct FUN_0060dab0_shell
{
    bool FUN_0060dab0(const char* arg);
};
// @fnv 0x0060dab0
bool FUN_0060dab0_shell::FUN_0060dab0(const char* pcString)
{
    unsigned int size = BSStringLength(pcString) + 1;
    char* buffer = static_cast<char*>(_alloca(size));
    TaskQueueInterface::CopyStringToBuffer(buffer, size, pcString);
    if (!reinterpret_cast<BSStringT_char*>(reinterpret_cast<char*>(this) + 0x64)->StrCmp(buffer, true))
        return false;
    reinterpret_cast<BSStr*>(reinterpret_cast<char*>(this) + 0x64)->Set(buffer, 0);
    return true;
}

struct Flt
{
    operator unsigned int();
};
struct FUN_0060c5f0_Class
{
    char _pad[0x64];
    Flt fld64;
    const char* GetStringOrEmpty();
};
// Returns the string pointer stored in fld64, or an empty string when fld64 is zero.
// @fnv 0x0060c5f0
const char* FUN_0060c5f0_Class::GetStringOrEmpty()
{
    return (unsigned int)fld64 ? (const char*)(unsigned int)fld64 : "";
}

struct BGSSaveFormBuffer : BGSLoadFormBuffer
{
    void FUN_005621f0(unsigned int);
};
struct FUN_0060e7c0_outer
{
    char _pad[0x5c];
    int _5c;
    void FUN_0060e7c0(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x0060e7c0
void FUN_0060e7c0_outer::FUN_0060e7c0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    if (apSaveGameBuffer->GetChangeFlags(0x40000000) && _5c == 0)
        apSaveGameBuffer->FUN_005621f0(0x40000000);
}

namespace stand {
struct TESScriptableForm
{
    virtual void f0();
    TESScriptableForm();
    void* m_pFormScript;
    bool m_bHasScript;
};
struct TESIcon
{
    virtual void f0();
    TESIcon();
    ~TESIcon();
    void* p;
    unsigned int n;
};
struct TESFullName
{
    virtual void f0();
    TESFullName();
    ~TESFullName();
    void* p;
    unsigned int n;
};
}
struct FUN_0060c5c0
{
    FUN_0060c5c0();
    unsigned int a;
    float b;
};
struct SL
{
    SL();
    ~SL();
    void* a;
    void* b;
};
struct CondS
{
    CondS();
    ~CondS();
    void* a;
    void* b;
};
struct StrMem
{
    StrMem();
    ~StrMem();
    char* p;
    unsigned short a;
    unsigned short b;
};
struct FUN_0060c4b0_QI
{
    void ResetFormData();
};
struct FUN_0060c4b0 : public TESForm, public stand::TESScriptableForm, public stand::TESIcon, public stand::TESFullName
{
    FUN_0060c5c0 data;
    SL m_kStageList;
    SL m_kObjectives;
    CondS m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    StrMem strEditorID;
    FUN_0060c4b0();
    virtual ~FUN_0060c4b0();
};
// @fnv 0x0060c4b0
FUN_0060c4b0::FUN_0060c4b0()
{
    SetFormType(FORM_QUEST);
    m_pScriptLocals = 0;
    ((FUN_0060c4b0_QI*)this)->ResetFormData();
}

void __cdecl FUN_0077a480(void* apQuest);

struct FUN_0060caf0_shell : TESQuest
{
    void FUN_0060caf0(bool abCompleted);
};

// Sets or clears the completed flag bit 0x40 on the quest, calls vtable slot 18 with 2, and notifies via FUN_0077a480 when newly completed.
// @fnv 0x0060caf0
void FUN_0060caf0_shell::FUN_0060caf0(bool abCompleted)
{
    if (abCompleted && GetCompleted())
        return;
    if (abCompleted && !(data.m_ucEntryType & 0x40))
    {
        data.m_ucEntryType |= 0x40;
        data.m_ucEntryType |= 2;
        ((void(__thiscall*)(void*, unsigned int))(*(void***)this)[18])(this, 2);
        FUN_0077a480(this);
    }
    else if (!abCompleted && (data.m_ucEntryType & 0x40))
    {
        data.m_ucEntryType &= ~0x40;
        ((void(__thiscall*)(void*, unsigned int))(*(void***)this)[18])(this, 2);
    }
}

struct TopicMenuController
{
    static void __cdecl IncrementMiscStat(int id);
};

struct FUN_0060ca30_shell
{
    // Virtual destructor for the shell type; performs no work.
// @fnv 0x0060ca30
    virtual ~FUN_0060ca30_shell()
    {}
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void RemoveTopic(int id)
    {}

    unsigned char _pad[0x38];
    unsigned char data;

    void FUN_0060ca30(bool abCompleted);
};

void FUN_0060ca30_shell::FUN_0060ca30(bool abCompleted)
{
    if (abCompleted && !(data & 2))
    {
        data |= 2;
        RemoveTopic(2);
        TopicMenuController::IncrementMiscStat(0);
        FUN_0077a480(this);
    }
    else if (!abCompleted && (data & 2))
    {
        data &= ~2;
        RemoveTopic(2);
        FUN_0060cad0(0);
    }
}

class QuestBase
{
  public:
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
    virtual ~QuestBase();
};

class FUN_0060c660 : public QuestBase, public TESScriptableForm, public TESIcon, public TESFullName
{
  public:
    QuestData data;
    BSSimpleList<QuestStage*> m_kStageList;
    BSSimpleList<BGSQuestObjective*> m_kObjectives;
    PerkEntryConditionSet m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    unsigned char layoutPadding61[3];
    BSStringT<char> strEditorID;

    void ResetDefaults();
    virtual ~FUN_0060c660();
};

// Destructor that calls ResetDefaults to reset the quest's state.
// @fnv 0x0060c660
FUN_0060c660::~FUN_0060c660()
{
    ResetDefaults();
}

struct FUN_0060c950_item
{
    bool FUN_005a5e70();
    void FUN_005ec5d0(int a1);
};

struct FUN_0060c950_node
{
    FUN_0060c950_item** FUN_006815c0();
    FUN_0060c950_node* FUN_00726070();
};

struct FUN_0060c950_cls
{
    FUN_0060c950_node* FUN_005d43e0();
    void FUN_0060c950(int a1);
};

// @fnv 0x0060c950
void FUN_0060c950_cls::FUN_0060c950(int a1)
{
    FUN_0060c950_node* node = FUN_005d43e0();
    while (node && *node->FUN_006815c0())
    {
        (*node->FUN_006815c0())->FUN_005ec5d0((*node->FUN_006815c0())->FUN_005a5e70() ? 3 : 2);
        node = node->FUN_00726070();
    }
}

struct FNV_InitNode;
struct FNV_SubObject
{
    void FUN_00483710();
    void FUN_005ec280();
};
struct FNV_NodeValue
{
    FNV_SubObject* object;
};
struct FNV_InitNode
{
    bool FUN_008256d0();
    FNV_NodeValue* FUN_006815c0();
    FNV_InitNode* FUN_00726070();
};
struct FNV_InitPart
{
    void FUN_0048cca0();
    void FUN_00487010();
    void FUN_0048e370(unsigned int);
    void FUN_0060ce80();
};
struct FUN_0060cd60_shell : TESQuest
{
    void FUN_004855a0();
    void FUN_00485e20(void*, unsigned int);
    FNV_SubObject* FUN_005f5760();
    FNV_InitNode* FUN_005d43c0();
    FNV_InitNode* FUN_005d43e0();
    void FUN_00485680();
    void FUN_0060cd60();
};
struct FNV_EventObject
{
    void ProcessItems();
};
extern "C" bool __cdecl FUN_00401500();

// @fnv 0x0060cd60
void FUN_0060cd60_shell::FUN_0060cd60()
{
    FUN_004855a0();
    reinterpret_cast<FNV_InitPart*>(&tESScriptableFormComponent)->FUN_0048cca0();
    reinterpret_cast<FNV_InitPart*>(&tESIconComponent + 1)->FUN_00487010();
    reinterpret_cast<FNV_InitPart*>(&tESIconComponent)->FUN_0048e370(0x4e4f4349);
    if (FUN_00401500())
    {
        reinterpret_cast<FNV_InitPart*>(&tESFullNameComponent + 1)->FUN_0060ce80();
    }
    FUN_00485e20(reinterpret_cast<char*>(&tESFullNameComponent) + 12, 8);
    if (FUN_00401500())
    {
        reinterpret_cast<FNV_InitPart*>(&tESFullNameComponent + 1)->FUN_0060ce80();
    }
    if (FUN_005f5760() != 0)
    {
        reinterpret_cast<FNV_EventObject*>(FUN_005f5760())->ProcessItems();
    }
    FNV_InitNode* node = FUN_005d43c0();
    while (node != 0 && !node->FUN_008256d0())
    {
        node->FUN_006815c0()->object->FUN_00483710();
        node = node->FUN_00726070();
    }
    FNV_InitNode* pOtherNode = FUN_005d43e0();
    while (pOtherNode != 0 && !pOtherNode->FUN_008256d0())
    {
        pOtherNode->FUN_006815c0()->object->FUN_005ec280();
        pOtherNode = pOtherNode->FUN_00726070();
    }
    FUN_00485680();
}

struct QuestEntryStandIn
{
    TESQuest* GetQuest();
    void* GetOwnerProcess();
    void* CheckQuest(TESQuest* apQuest);
};

struct PlayerQuestListStandIn
{
    BSSimpleList<QuestEntryStandIn*>* GetQuestEntryList();
};

extern PlayerQuestListStandIn* g_thePlayer;

// Clears apList, then walks the player's quest entry list and appends or prepends entries whose quest matches apQuest or passes the completed/any filter.
// @fnv 0x0060d8f0
void __cdecl FUN_0060d8f0(BSSimpleList<QuestEntryStandIn*>* apList, TESQuest* apQuest, bool abCompleted, bool abAddTail,
                          bool abAny)
{
    if (!apList)
        return;
    apList->RemoveAll();
    BSSimpleList<TESQuest*> kSeen;
    BSSimpleList<QuestEntryStandIn*>* pNode = g_thePlayer->GetQuestEntryList();
    while (pNode && pNode->GetItem())
    {
        TESQuest* pQuest;
        QuestEntryStandIn* pEntry2 = pNode->GetItem();
        pQuest = pEntry2->GetQuest();
        pNode = pNode->GetNext();
        if (pQuest)
        {
            bool bOk3 = !apQuest || (apQuest && pQuest == apQuest);
            if (bOk3 && !apQuest)
            {
                bOk3 = (abCompleted == pQuest->GetCompleted() || abAny) && !kSeen.IsInList(pQuest);
                if (bOk3)
                    kSeen.AddHead(pQuest);
            }
            if (bOk3 && pEntry2->GetOwnerProcess() && pEntry2->CheckQuest(pQuest))
            {
                if (abAddTail)
                    apList->AddTail(pEntry2);
                else
                    apList->AddHead(pEntry2);
            }
        }
    }
    kSeen.RemoveAll();
}

struct SaveFormInfo
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flagsStart;
};

struct SaveLoadGameStub
{
    bool FUN_00862110();
    SaveFormInfo* GetCurrentForm();
};
extern SaveLoadGameStub* g_TESSaveLoadGame;

struct FormSaveSizeStub
{
    unsigned short GetSaveSize(unsigned int changedFlags);
};

struct ScriptLocalsSaveStub
{
    unsigned short GetSaveSize();
};

struct StageItemListStub
{
    int GetSize();
};

struct QuestStageStub
{
    StageItemListStub* GetStageItemList();
};

struct StageNodeStub
{
    QuestStageStub*& GetItem();
    StageNodeStub* GetNext();
};

extern SettingT<INISettingCollection> bDebugSaveGameSize;
TESForm* __cdecl LookupFormByID(unsigned int formID);
void __cdecl SaveGameSizeWarning(const char* message, ...);

struct QuestSaveSize : TESQuest
{
    StageNodeStub* GetStageNodes();
    unsigned short FUN_0060dba0(unsigned int changedFlags);
};

// @fnv 0x0060dba0
unsigned short QuestSaveSize::FUN_0060dba0(unsigned int changedFlags)
{
    unsigned short size7 = 0;
    size7 += ((FormSaveSizeStub*)this)->GetSaveSize(changedFlags);
    unsigned short baseSize2 = size7;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        size7 += 4;
        size7 += 2;
    }
    if (changedFlags & 2)
    {
        size7 += 1;
    }
    if (changedFlags & 0x80000000)
    {
        StageNodeStub* node9 = GetStageNodes();
        size7 += 1;
        while (node9)
        {
            QuestStageStub* stage = node9->GetItem();
            if (stage)
            {
                size7 += 2;
                StageItemListStub* items2 = stage->GetStageItemList();
                size7 += items2->GetSize() * 5 + 1;
            }
            node9 = node9->GetNext();
        }
    }
    if (changedFlags & 0x40000000)
    {
        size7 += ((ScriptLocalsSaveStub*)m_pScriptLocals)->GetSaveSize();
    }
    if (bDebugSaveGameSize.Bool()->b)
    {
        SaveFormInfo* info = g_TESSaveLoadGame->GetCurrentForm();
        if (info)
        {
            TESForm* form = LookupFormByID(info->formID);
            SaveGameSizeWarning("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                                size7 - baseSize2, info->formID, form->GetName(), *(unsigned int*)&info->flagsStart,
                                3920, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
        else
        {
            SaveGameSizeWarning("GetSaveSize(): %-5i ending at line %i in file %s", size7 - baseSize2, 3920,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
    }
    return size7;
}

struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int auiFlags);
};

struct QuestScriptLocals
{
    void ResetLocals();
};

struct FUN_0060e6a0_shell : TESQuest
{
    void FUN_0060e6a0(unsigned int auiFlags);
};

// @fnv 0x0060e6a0
void FUN_0060e6a0_shell::FUN_0060e6a0(unsigned int auiFlags)
{
    ((FUN_004534f0_shell*)this)->FUN_004534f0(auiFlags);
    if (auiFlags & 0x80000000)
    {
        BSSimpleList<QuestStage*>* pStageIter = GetStageList();
        while (pStageIter)
        {
            QuestStage* pStage = pStageIter->GetItem();
            if (pStage)
            {
                pStage->MarkDone(false);
                BSSimpleList<PlayerQuestData*>* pItemIter = pStage->GetStageItemList();
                while (pItemIter)
                {
                    PlayerQuestData* pItem3 = pItemIter->GetItem();
                    Date* pDate3 = pItem3 ? pItem3->GetLogDate() : 0;
                    if (pDate3)
                    {
                        pItem3->SetLogDate(0);
                        delete pDate3;
                    }
                    pItemIter = pItemIter->GetNext();
                }
            }
            pStageIter = pStageIter->GetNext();
        }
        m_ucEnabled = 0;
    }
    if ((auiFlags & 0x40000000) && m_pScriptLocals)
    {
        ((QuestScriptLocals*)m_pScriptLocals)->ResetLocals();
    }
}

struct QuestSaveManager
{
    unsigned char* FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void*, unsigned int);
    SaveFormInfo* FUN_004fd3e0();
};
struct QuestSaveItem
{
    unsigned char FUN_005dc980();
    Date* FUN_008d8520();
};
struct QuestSaveItemNode
{
    QuestSaveItem*& FUN_006815c0();
    QuestSaveItemNode* FUN_00726070();
};
struct QuestSaveStage
{
    unsigned char FUN_009373f0();
    bool FUN_005dc960();
    QuestSaveItemNode* FUN_00717e50();
};
struct QuestSaveStageNode
{
    QuestSaveStage*& FUN_006815c0();
    QuestSaveStageNode* FUN_00726070();
};
struct QuestSaveLocals
{
    void WriteScriptLocals();
};
struct QuestSave : TESQuest
{
    void FUN_00484c20(unsigned int);
    unsigned char* FUN_005a8080();
    void FUN_00484ce0(void*, unsigned int);
    QuestSaveStageNode* FUN_005d43c0();
    void FUN_0060dd50(unsigned int flags);
};
void __cdecl FUN_0040fbe0(const char*, ...);
void __cdecl FUN_005b5e40(const char*, ...);

// Writes the quest's save data: flags, stage and item lists, optional locals, debug size logging, and a block-size header when block saving is active.
// @fnv 0x0060dd50
void QuestSave::FUN_0060dd50(unsigned int flags)
{
    FUN_00484c20(flags);
    unsigned short h = 0;  // Reserved block size.
    unsigned char* p = 0;  // Address of the reserved block-size field.
    unsigned char* a = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
    if (bDebugSaveGameSize.Bool()->b)
        a = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
    if (((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int marker = 0x424c4f4b;
        ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_008579b0(&marker, 4);
        p = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_008579b0(&h, 2);
    }
    if (flags & 2)
    {
        unsigned char questFlags = *FUN_005a8080();
        FUN_00484ce0(&questFlags, 1);
    }
    if (flags & 0x80000000)
    {
        unsigned char p = 0;  // Number of saved stages.
        unsigned char* j = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        FUN_00484ce0(&p, 1);
        QuestSaveStageNode* h = FUN_005d43c0();  // Stage iterator.
        while (h)
        {
            QuestSaveStage* stage = h->FUN_006815c0();
            if (stage)
            {
                unsigned char eb = stage->FUN_009373f0();  // Stage index.
                bool f = stage->FUN_005dc960();            // Stage completion flag.
                FUN_00484ce0(&eb, 1);
                FUN_00484ce0(&f, 1);
                unsigned char q = 0;  // Number of saved stage items.
                unsigned char* cf = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
                FUN_00484ce0(&q, 1);
                QuestSaveItemNode* s = stage->FUN_00717e50();  // Stage-item iterator.
                while (s)
                {
                    QuestSaveItem* item = s->FUN_006815c0();
                    if (item)
                    {
                        unsigned char j = item->FUN_005dc980();  // Stage-item index.
                        Date* p = item->FUN_008d8520();          // Log date, if present.
                        FUN_00484ce0(&j, 1);
                        if (p)
                        {
                            ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_008579b0(p, 4);
                        }
                        else
                        {
                            Date emptyDate;
                            ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_008579b0(&emptyDate, 4);
                        }
                        ++q;
                    }
                    s = s->FUN_00726070();
                }
                *cf = q;
                ++p;
            }
            h = h->FUN_00726070();
        }
        *j = p;
    }
    if (flags & 0x40000000)
        ((QuestSaveLocals*)m_pScriptLocals)->WriteScriptLocals();
    if (bDebugSaveGameSize.Bool()->b)
    {
        unsigned char* end = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        SaveFormInfo* formInfo = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_004fd3e0();
        if (formInfo)
        {
            TESForm* form = LookupFormByID(formInfo->formID);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end - a,
                         formInfo->formID, form->GetName(), *(unsigned int*)&formInfo->flagsStart, 4003,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", end - a, 4003,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp");
        }
    }
    if (((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned char* h = ((QuestSaveManager*)g_TESSaveLoadGame)->FUN_00825c00();
        unsigned char* j = p;  // Beginning of the saved block.
        if (h > j + 65535)
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESQuest.cpp", 4003);
        *(unsigned short*)p = (unsigned short)(h - j);
    }
}

extern "C" void* DAT_011de45c;
extern "C" char UNK_0104ad80[];
extern "C" char UNK_0104adc0[];
extern "C" char UNK_010156a8[];
extern "C" char UNK_01015718[];
extern "C" char UNK_01015588[];
extern "C" char UNK_01015500[];
extern "C" char UNK_010154a0[];
extern "C" char UNK_01015440[];
void __cdecl FUN_005b5e40(const char*, ...);
void* __cdecl LookupFormByID(void*);
struct StreamReader
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    unsigned int FUN_00825c00();
    void* FUN_004fd3c0();
    unsigned char FUN_008df040();
    void SetFlags(unsigned int);
};
struct QuestInput
{
    void FUN_00484c50(unsigned int, unsigned int);
    void FUN_00484d00(void*, unsigned int);
    unsigned char* FUN_005a8080();
    void* FUN_0060db40(unsigned char);
    void FUN_0060d670();
};
struct StageSave
{
    void FUN_0067fdb0(unsigned char);
    void* FindItemByDoneFlag(unsigned char);
};
struct StageEntry
{
    void* FUN_008d8520();
    void FUN_00407800(void*);
};
struct SavedDate
{
    unsigned int value;
    void CopyShortPair(const Date*);
    void FUN_007b3fa0(unsigned int);
};
struct LogValue
{
    short low, high;
    LogValue();
    ~LogValue();
    unsigned short FUN_004b1030();
    unsigned short FUN_004b1050();
};
void FUN_00483710(LogValue*);
struct LocalsState
{
    void FUN_005a9950();
    void* FUN_0041af70(unsigned int);
};
typedef unsigned int(__thiscall* TagMethod)(void*);
struct QuestLoader : TESQuest
{
    void LoadQuestData(unsigned int flags, unsigned int extra);
};
// Reads quest data from the stream: enabled flag, stages with dates, script locals, and logs size mismatches.
// @fnv 0x0060e0d0
void QuestLoader::LoadQuestData(unsigned int flags, unsigned int extra)
{
    ((QuestInput*)this)->FUN_00484c50(flags, extra);
    unsigned short sizeRead = 0;
    unsigned int start = 0;
    if (((StreamReader*)DAT_011de45c)->FUN_00862110())
    {
        unsigned int tag;
        ((StreamReader*)DAT_011de45c)->FUN_008579e0(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            void* entry = ((StreamReader*)DAT_011de45c)->FUN_004fd3c0();
            if (entry)
            {
                void* view = LookupFormByID(*(void**)entry);
                FUN_005b5e40(UNK_01015718, UNK_0104ad80, 0xfaf, *(void**)entry, ((TagMethod*)*(void**)view)[76](view),
                             *(unsigned char*)((char*)entry + 9), *(unsigned int*)((char*)entry + 5));
            }
            else
            {
                FUN_005b5e40(UNK_010156a8, UNK_0104ad80, 0xfaf, ((StreamReader*)DAT_011de45c)->FUN_008df040());
            }
        }
        start = ((StreamReader*)DAT_011de45c)->FUN_00825c00();
        ((StreamReader*)DAT_011de45c)->FUN_008579e0(&sizeRead, 2);
    }
    if (flags & 2)
    {
        unsigned char enabled;
        ((QuestInput*)this)->FUN_00484d00(&enabled, 1);
        *((QuestInput*)this)->FUN_005a8080() = enabled;
    }
    if (flags & 0x80000000)
    {
        unsigned char stageCount;
        ((QuestInput*)this)->FUN_00484d00(&stageCount, 1);
        for (int i = 0; i < stageCount; ++i)
        {
            unsigned char stageId;
            unsigned char isComplete;
            ((QuestInput*)this)->FUN_00484d00(&stageId, 1);
            ((QuestInput*)this)->FUN_00484d00(&isComplete, 1);
            StageSave* questStage = (StageSave*)((QuestInput*)this)->FUN_0060db40(stageId);
            if (questStage)
            {
                questStage->FUN_0067fdb0(isComplete);
            }
            else
            {
                FUN_005b5e40(UNK_0104adc0, stageId, this->GetEditorName());
            }
            {
                unsigned char itemCount;
                ((QuestInput*)this)->FUN_00484d00(&itemCount, 1);
                for (int j = 0; j < itemCount; ++j)
                {
                    Date dateValue;
                    {
                        unsigned char itemId;
                        ((QuestInput*)this)->FUN_00484d00(&itemId, 1);
                        ((StreamReader*)DAT_011de45c)->FUN_008579e0(&dateValue, 4);
                        if (questStage)
                        {
                            StageEntry* item = (StageEntry*)questStage->FindItemByDoneFlag(itemId);
                            if (item)
                            {

                                if (((LogValue*)&dateValue)->FUN_004b1030() == 0 &&
                                    ((LogValue*)&dateValue)->FUN_004b1050() == 0)
                                {
                                    SavedDate* pOldDate = (SavedDate*)item->FUN_008d8520();
                                    if (pOldDate)
                                    {
                                        delete (Date*)pOldDate;
                                        item->FUN_00407800(0);
                                    }
                                }
                                else
                                {
                                    SavedDate* pOldDate = (SavedDate*)item->FUN_008d8520();
                                    if (pOldDate)
                                    {
                                        pOldDate->CopyShortPair(&dateValue);
                                    }
                                    else
                                    {
                                        pOldDate = (SavedDate*)new Date(dateValue);
                                        item->FUN_00407800(pOldDate);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        this->m_ucEnabled = 0;
        ((QuestInput*)this)->FUN_0060d670();
    }
    if (flags & 0x40000000)
    {
        if (!this->m_pScriptLocals)
        {
            ScriptLocals* replacement = new ScriptLocals;
            {
                ((LocalsState*)replacement)->FUN_005a9950();
                delete replacement;
                ((StreamReader*)DAT_011de45c)->SetFlags(0x40000000);
            }
        }
        else
        {
            ((LocalsState*)this->m_pScriptLocals)->FUN_005a9950();
        }
    }
    if (((StreamReader*)DAT_011de45c)->FUN_00862110())
    {
        void* entry;
        {
            unsigned int actual = ((StreamReader*)DAT_011de45c)->FUN_00825c00();
            entry = ((StreamReader*)DAT_011de45c)->FUN_004fd3c0();
            if (entry)
            {
                void* view = LookupFormByID(*(void**)entry);
                if (actual > start + sizeRead)
                    FUN_005b5e40(UNK_01015588, actual - (start + sizeRead), UNK_0104ad80, 0x1010, *(void**)entry,
                                 ((TagMethod*)*(void**)view)[76](view), *(unsigned char*)((char*)entry + 9),
                                 *(unsigned int*)((char*)entry + 5));
                else if (actual < start + sizeRead)
                    FUN_005b5e40(UNK_01015500, (start + sizeRead) - actual, UNK_0104ad80, 0x1010, *(void**)entry,
                                 ((TagMethod*)*(void**)view)[76](view), *(unsigned char*)((char*)entry + 9),
                                 *(unsigned int*)((char*)entry + 5));
            }
            else
            {
                if (actual > start + sizeRead)
                    FUN_005b5e40(UNK_010154a0, actual - (start + sizeRead), UNK_0104ad80, 0x1010,
                                 ((StreamReader*)DAT_011de45c)->FUN_008df040());
                else if (actual < start + sizeRead)
                    FUN_005b5e40(UNK_01015440, (start + sizeRead) - actual, UNK_0104ad80, 0x1010,
                                 ((StreamReader*)DAT_011de45c)->FUN_008df040());
            }
        }
    }
}

// WriteToBuffer - data round worker13 v06
struct F810Buf;
struct F810Flags
{
    bool FUN_004280f0();
};
struct F810Item1;
struct F810Item2;
struct F810Item3;
struct F810Node2
{
    F810Item2* pItem;
    F810Node2* pNext;
    F810Item2** FUN_006815c0();
    F810Node2* FUN_00726070();
};
struct F810Node3
{
    F810Item3* pItem;
    F810Node3* pNext;
    F810Item3** FUN_006815c0();
    F810Node3* FUN_00726070();
};
struct F810Item1
{
    unsigned char FUN_009373f0();
    bool FUN_005dc960();
    F810Node2* FUN_00717e50();
};
struct F810Item2
{
    bool FUN_005dc980();
    void* FUN_008d8520();
};
struct F810Item3
{
    void* FUN_007af430();
    F810Node3* FUN_00726070();
};
struct F810Node1
{
    F810Item1* pItem;
    F810Node1* pNext;
    F810Item1** FUN_006815c0();
    F810Node1* FUN_00726070();
};
struct F810Obj
{
    void FUN_005a9db0(F810Buf* buf);
};
struct F810Buf
{
    F810Flags* FUN_00428110(void* out, unsigned int tag);
    void FUN_00865e50(void* data, int size, int flag);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int count, unsigned int total);
};
struct FUN_0060e810_shell
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned char cFlag3c;
    unsigned char r3d;
    unsigned char r3e;
    unsigned char r3f;
    unsigned int iVal40;
    F810Node1 list44;
    F810Node3 list4c;
    unsigned int f54;
    unsigned int f58;
    F810Obj* pObj5c;
    void SaveIfChanged(F810Buf* buf);
    void WriteToBuffer(F810Buf* buf);
};

// Serializes cFlag3c, iVal40, the list44 and list4c lists and pObj5c into buf, each guarded by a tag check, writing counts via FUN_00865ff0.
// @fnv 0x0060e810
void FUN_0060e810_shell::WriteToBuffer(F810Buf* buf)
{
    unsigned int flagsE;
    unsigned int tagD;
    unsigned int flags2;
    unsigned int flag2;
    unsigned int flag;
    F810Node3* next0;
    void* valY;
    F810Item3* entry;
    int iterY;
    F810Node3* head1;
    unsigned int cntY;
    unsigned char gotB;
    unsigned char opts;
    void* val1;
    F810Item2* item2;
    F810Node2* listD;
    unsigned int cntA;
    int idxD;
    unsigned char rawD;
    unsigned char flg;
    F810Item1* itemD;
    F810Node1* nodeC;
    unsigned int cnt1;
    int idx0;
    SaveIfChanged(buf);
    if (buf->FUN_00428110(&flag, 2)->FUN_004280f0())
    {
        buf->FUN_00865e50(&cFlag3c, 1, 0);
    }
    if (buf->FUN_00428110(&flag2, 4)->FUN_004280f0())
    {
        buf->FUN_00865e50(&iVal40, 4, 0);
    }
    if (buf->FUN_00428110(&flags2, 0x80000000)->FUN_004280f0())
    {
        idx0 = 0;
        cnt1 = buf->FUN_00865f20();
        nodeC = &list44;
        while (nodeC != 0)
        {
            itemD = *nodeC->FUN_006815c0();
            if (itemD != 0)
            {
                rawD = itemD->FUN_009373f0();
                flg = itemD->FUN_005dc960();
                buf->FUN_00865e50(&rawD, 1, 0);
                buf->FUN_00865e50(&flg, 1, 0);
                idxD = 0;
                cntA = buf->FUN_00865f20();
                listD = itemD->FUN_00717e50();
                while (listD != 0)
                {
                    item2 = *listD->FUN_006815c0();
                    if (item2 != 0)
                    {
                        opts = item2->FUN_005dc980();
                        val1 = item2->FUN_008d8520();
                        gotB = (val1 != 0);
                        buf->FUN_00865e50(&opts, 1, 0);
                        buf->FUN_00865e50(&gotB, 1, 0);
                        if (gotB)
                        {
                            buf->FUN_00865e50(val1, 4, 0);
                        }
                        idxD++;
                    }
                    listD = listD->FUN_00726070();
                }
                buf->FUN_00865ff0(idxD, cntA);
                idx0++;
            }
            nodeC = nodeC->FUN_00726070();
        }
        buf->FUN_00865ff0(idx0, cnt1);
    }
    if (buf->FUN_00428110(&tagD, 0x40000000)->FUN_004280f0())
    {
        pObj5c->FUN_005a9db0(buf);
    }
    if (buf->FUN_00428110(&flagsE, 0x20000000)->FUN_004280f0())
    {
        iterY = 0;
        cntY = buf->FUN_00865f20();
        head1 = &list4c;
        while (head1 != 0)
        {
            entry = *head1->FUN_006815c0();
            if (entry != 0)
            {
                valY = entry->FUN_007af430();
                if (valY != 0)
                {
                    next0 = entry->FUN_00726070();
                    buf->FUN_00865e50(&next0, 4, 0);
                    buf->FUN_00865e50(&valY, 4, 0);
                    iterY++;
                }
            }
            head1 = head1->FUN_00726070();
        }
        buf->FUN_00865ff0(iterY, cntY);
    }
}

struct ScriptX
{
    ScriptLocals* CreateEventList();
};
struct ScriptableBase
{
    virtual void f0();
    ScriptX* m_pFormScript;
    bool m_bHasScript;
    unsigned char layoutPadding[3];
    ScriptX* FUN_00726070();
};
struct IconBase
{
    virtual void f0();
    void* p;
    unsigned int n;
};
struct NameBase
{
    virtual void f0();
    void* p;
    unsigned int n;
};
struct StageItem
{
    Date* FUN_008d8520();
    void FUN_00407800(Date*);
};
struct SItemNode
{
    StageItem** FUN_006815c0();
    SItemNode* FUN_00726070();
};
struct Stage
{
    void FUN_0067fdb0(bool);
    SItemNode* FUN_00717e50();
};
struct StageNode
{
    Stage** FUN_006815c0();
    StageNode* FUN_00726070();
};
struct ObjItem
{
    void FUN_005ec5d0(int);
};
struct ObjNode
{
    ObjItem** FUN_006815c0();
    ObjNode* FUN_00726070();
};
struct QuestShell : TESForm, ScriptableBase, IconBase, NameBase
{
    FUN_0060c5c0 data;
    SL m_kStageList;
    SL m_kObjectives;
    CondS m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    StrMem strEditorID;
    StageNode* FUN_005d43c0();
    ObjNode* FUN_005d43e0();
    bool HasFlag0x10();
    void FUN_0060c9c0(bool);
    void FUN_0060ca30(bool);
    void FUN_0060caf0(bool);
    void SetFlag20(bool);
    void FUN_0060d720();
};
void __cdecl FUN_00619b60(QuestShell*);

// @fnv 0x0060d720
void QuestShell::FUN_0060d720()
{
    StageNode* aStageNode;
    ObjNode* objNode;
    Stage* stage;
    {
        SItemNode* itemNode;
        Date* logDate3;
        StageItem* stageItemA;

        aStageNode = FUN_005d43c0();
        while (aStageNode)
        {
            stage = *aStageNode->FUN_006815c0();
            if (stage)
            {
                stage->FUN_0067fdb0(false);
                itemNode = stage->FUN_00717e50();
                while (itemNode)
                {
                    stageItemA = *itemNode->FUN_006815c0();
                    logDate3 = stageItemA ? stageItemA->FUN_008d8520() : 0;
                    if (logDate3)
                    {
                        stageItemA->FUN_00407800(0);
                        delete logDate3;
                    }
                    itemNode = itemNode->FUN_00726070();
                }
            }
            aStageNode = aStageNode->FUN_00726070();
        }
    }

    m_ucEnabled = 0;

    objNode = FUN_005d43e0();
    while (objNode && *objNode->FUN_006815c0())
    {
        (*objNode->FUN_006815c0())->FUN_005ec5d0(0);
        objNode = objNode->FUN_00726070();
    }

    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = FUN_00726070()->CreateEventList();
    }

    FUN_00619b60(this);
    FUN_0060c9c0(HasFlag0x10());
    FUN_0060ca30(false);
    FUN_0060caf0(false);
    SetFlag20(false);
}
