// fallout_shared/tesidleform.cpp: TESIdleForm, IdleCopy, IdleFormDetach, IdleInit (29 functions)

#include "tesidleform_match_decls.h"
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};

extern "C" char* __cdecl strrchr(const char* string, int character);
extern "C" int __cdecl stricmp(const char* string1, const char* string2);

// @fnv 0x005fe3b0
void TESIdleForm::ResetFormData(void)
{
    data.m_ucAnimationGroupSection = 7;
    data.m_ucLoopingMin = 0;
    data.m_ucLoopingMax = 0;
    data.m_usReplayDelay = 0;
    data.m_ucIdleFlags = 0;
    m_pParentIdleForm = 0;
    m_pIdleForm = 0;
}

// @fnv 0x005ff280
bool TESIdleForm::IsIdleFile(void)
{
    bool isIdleFile = false;
    const char* extension = strrchr(GetModelFilePath(), '.');
    if (extension && stricmp(extension, ".kf") == 0)
        isIdleFile = true;
    return isIdleFile;
}

// @fnv 0x005ff430
bool TESIdleForm::IsValidForReferences(TESObjectREFR* actionRef, TESObjectREFR* targetRef, bool recurseUp)
{
    bool conditionsMet = false;
    if (reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
            ->ContainsTrait(actionRef, targetRef))
    {
        if (recurseUp && reinterpret_cast<LowProcess*>(this)->GetActiveCombatTarget())
        {
            conditionsMet = reinterpret_cast<TESIdleForm*>(reinterpret_cast<LowProcess*>(this)->GetActiveCombatTarget())
                                ->IsValidForReferences(actionRef, targetRef, recurseUp);
        }
        else
        {
            conditionsMet = true;
        }
    }
    return conditionsMet;
}

// @fnv 0x005fe400
void TESIdleForm::ClearData()
{
    if (g_dataHandler->FUN_004516b0() && !g_dataHandler->FUN_004226e0() && DAT_011cb6a0->FUN_00843150() &&
        GetInitialized())
        UnregisterIdleForm();
    reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
        ->InitializeConditionItems();
}

// @fnv 0x005ff2e0
TESIdleForm* TESIdleForm::FindIdleFormForObject(TESObjectREFR* actionRef, TESObjectREFR* targetRef,
                                                BSSimpleList<IdleReplayDelayEntry*>* replayDelays)
{
    TESIdleForm* idle = 0;
    if (!IsDeleted() && reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
                            ->ContainsTrait(actionRef, targetRef))
    {
        bool delayed;
        if (IsIdleFile())
        {
            BSSimpleList<IdleReplayDelayEntry*>* pDelayIter = replayDelays;
            delayed = false;
            while (pDelayIter && !delayed && !reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(pDelayIter)->IsEmpty())
            {
                IdleReplayDelayEntry* pDelayEntry = reinterpret_cast<IdleReplayDelayEntry*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pDelayIter)->GetItem());
                if (*reinterpret_cast<TESIdleForm**>(pDelayEntry) == this)
                    delayed = true;
                pDelayIter = reinterpret_cast<BSSimpleList<IdleReplayDelayEntry*>*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pDelayIter)->GetNext());
            }
            if (!delayed)
                idle = this;
        }
        else if (FUN_005ff1d0())
            idle = this;
        unsigned int count = GetChildCount();
        if (count)
        {
            TESIdleForm* childIdle = 0;
            for (unsigned int i = 0; i < count; ++i)
            {
                TESIdleForm* child = GetChildByIndex(i);
                if (child)
                    childIdle = child->FindIdleFormForObject(actionRef, targetRef, replayDelays);
                if (childIdle)
                    break;
            }
            if (childIdle)
                idle = childIdle;
        }
    }
    return idle;
}

// Scans the form array for this idle and its next idle, then moves the next idle to directly follow this one and reorders it.
// @fnv 0x005fefa0
void TESIdleForm::BuildIdleParentPath(NiFormArray* array)
{
    if (!array)
        return;
    struct IdleOrderState
    {
        unsigned int missing;
        unsigned int nextIndex;
        unsigned int index;
        TESIdleForm* next;
        unsigned int size;
    } orderState;
    orderState.missing = 0;
    orderState.index = -1;
    orderState.size = array->GetSize();
    orderState.nextIndex = -1;
    orderState.next = 0;
    for (unsigned int i = 0; i < orderState.size; ++i)
    {
        TESIdleForm* idle = dynamic_cast<TESObjectANIO*>(array->FUN_00877a30(i));
        if (idle)
        {
            if (idle == this)
                orderState.index = i;
            else if (reinterpret_cast<TESIdleForm*>(reinterpret_cast<BGSImpactData*>(idle)->GetDecalTextureSet()) ==
                     this)
            {
                if (!orderState.next)
                {
                    orderState.next = idle;
                    orderState.nextIndex = i;
                }
                else
                {
                    BSStringT<char> name;
                    GetDebugName(&name);
                    Warning("MASTERFILE: Multiple next idles for %s.", name.String());
                }
            }
        }
        else
            ++orderState.missing;
    }
    if (orderState.index != -1 && orderState.nextIndex != -1 && orderState.nextIndex != orderState.index + 1)
    {
        unsigned int removed = 0;
        array->SetSize(orderState.nextIndex, &removed);
        array->Compact();
        if (orderState.nextIndex < orderState.index)
            ++orderState.missing;
        orderState.index -= orderState.missing;
        array->SetFormAtIndex(orderState.index + 1, orderState.next);
        array->Compact();
        orderState.next->BuildIdleParentPath(array);
    }
}

// @fnv 0x005fedb0
bool TESIdleForm::HasMissingPathArray()
{
    bool success = true;
    struct ParentState
    {
        TESIdleForm* parent;
        unsigned int index;
        TESIdleForm* previous;
        NiFormArray* array;
    } state;
    state.parent = m_pParentIdleForm;
    state.previous = m_pIdleForm;
    if (IsFlag40Set())
    {
        NiFormArray* loose = DAT_011cb6a0->GetIdleArray(this);
        if (!loose)
        {
            DAT_011cb6a0->GetFormArray(this);
            loose = DAT_011cb6a0->GetIdleArray(this);
        }
        if (loose)
        {
            unsigned int size = loose->GetSize();
            loose->SetFormAtIndex(size, this);
        }
        else
        {
            Warning("Failed to find loose idle array for '%s' (%08X)", GetName(), GetFormID());
            success = false;
        }
        return success;
    }
    state.index = 0;
    state.array = 0;
    if (state.parent)
        state.array = state.parent->AssignParentPath();
    else
        state.array = DAT_011cb6a0->GetFormArray(this);
    if (state.array)
    {
        if (state.previous)
        {
            unsigned int previousIndex = state.array->GetIndexOfForm(state.previous);
            if (previousIndex != -1)
                ++previousIndex;
            state.index = previousIndex;
        }
        if (state.index == -1 || IsDeleted())
            state.index = state.array->GetSize() + 1;
        state.array->SetFormAtIndex(state.index, this);
        BuildIdleParentPath(state.array);
    }
    else
    {
        BSStringT<char> name;
        GetDebugName(&name);
        Warning("MASTERFILE: Could not find parent array for %s.", name.String());
        success = false;
    }
    return success;
}

// Reads the idle form's chunk stream (EDID, OBND, MODL/MODT, DATA, CTDA, ANAM), applying each subrecord and returning true on success.
// @fnv 0x005fe810
bool TESIdleForm::Load(TESFile* file)
{
    if (reinterpret_cast<TESFileFormInt*>(file)->GetTESForm() != 0x48)
        return false;
    LoadRecordHeader(file);
    struct ReferenceItemCountEntry
    {
        FUN_005a71d0 links;
        char* editorID;
        int chunk;
    } idleRecord;
    while ((idleRecord.chunk = file->GetChunkID()) != 0)
    {
        switch (idleRecord.chunk)
        {
        case 0x44494445:
            idleRecord.editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(idleRecord.editorID, 512);
            SetEditorID_AtRuntime(idleRecord.editorID);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &data, 8);
            break;
        case 0x41445443:
            reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())->Load(file);
            break;
        case 0x4d414e41:
            memset(&idleRecord.links, 0, 8);
            file->GetChunkData(&idleRecord.links, 8);
            if (file->IsEndianConversionRequired())
                idleRecord.links.FUN_00462230();
            m_pParentIdleForm = reinterpret_cast<TESIdleForm*>(idleRecord.links.parent);
            m_pIdleForm = reinterpret_cast<TESIdleForm*>(idleRecord.links.previous);
            DAT_011cb6a0->AddIdleToArray(this);
            break;
        }
        if (idleRecord.chunk == 0x41544144 && file->IsEndianConversionRequired())
            data.SwapEndian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

struct FUN_005fea20_shell
{
    void SwapEndian();
};

// Swaps the byte order of the 16-bit value at object offset 4 using BSEndian.
// @fnv 0x005fea20
void FUN_005fea20_shell::SwapEndian()
{
    BSEndian((unsigned short*)((char*)this + 4), EndianSizeTag<2>());
}

struct FUN_005ff190_shell
{
    char pad[0x38];
    unsigned char m_0x38;
    void FUN_005ff190(bool set);
};

// @fnv 0x005ff190
void FUN_005ff190_shell::FUN_005ff190(bool set)
{
    bool b = set;
    m_0x38 &= 0xC0;
    m_0x38 |= b;
}

struct FUN_005ff1d0_shell : public TESIdleForm
{
    bool FUN_005ff1d0();
};

// Returns true when the flag bit 0x80 is set in the byte at offset 0x38 of this TESIdleForm, otherwise false.
// @fnv 0x005ff1d0
bool FUN_005ff1d0_shell::FUN_005ff1d0()
{
    if (*(unsigned char*)((char*)this + 0x38) & 0x80)
        return true;
    else
        return false;
}

struct FUN_005ff200_shell
{
    unsigned char m_0x38;
    bool IsFlag40Set();
};

// @fnv 0x005ff200
bool FUN_005ff200_shell::IsFlag40Set()
{
    if (((unsigned char*)this)[0x38] & 0x40)
        return true;
    else
        return false;
}

struct FUN_005ff220_shell
{
    void SetFlag40(bool bFlag);
};

// Sets or clears bit 0x40 in the byte at offset 0x38 of this object based on bFlag.
// @fnv 0x005ff220
void FUN_005ff220_shell::SetFlag40(bool abSet)
{
    if (abSet)
        ((unsigned char*)this)[0x38] |= 0x40;
    else
        ((unsigned char*)this)[0x38] &= ~0x40;
}

struct FUN_005ff260_shell
{
    unsigned char m_3e;
    bool FUN_005ff260();
};

// @fnv 0x005ff260
bool FUN_005ff260_shell::FUN_005ff260()
{
    if (reinterpret_cast<unsigned char*>(this)[0x3e] & 1)
        return true;
    else
        return false;
}

struct FUN_005ff4a0_shell : public TESIdleForm
{
    unsigned int FUN_005ff4a0();
};

// Returns the form ID of the TESForm pointer stored at offset 0x40, or 0 if that pointer is null.
// @fnv 0x005ff4a0
unsigned int FUN_005ff4a0_shell::FUN_005ff4a0()
{
    unsigned int iretval = 0;
    if (reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x40)[0])
        iretval = reinterpret_cast<TESForm**>(reinterpret_cast<char*>(this) + 0x40)[0]->GetFormID();
    return iretval;
}

struct FUN_005ff160_shell : public TESIdleForm
{
    int GetFlagsMasked();
};

// Reads the byte at offset 0x38, clears bits 0x40 and 0x80, and returns the result.
// @fnv 0x005ff160
int FUN_005ff160_shell::GetFlagsMasked()
{
    unsigned char ctemp = ((unsigned char*)this)[0x38];
    ctemp &= 0xffffff3f;
    return ctemp;
}

struct FUN_00600d90_shell
{
    void FUN_00600d90();
};

struct FUN_00600d70_shell
{
    void FUN_00600d70();
};

// @fnv 0x00600d70
void FUN_00600d70_shell::FUN_00600d70()
{
    ((FUN_00600d90_shell*)this)->FUN_00600d90();
}

void __cdecl _Deallocate(void*);
struct FUN_005fe130_shell
{
    void FUN_005fe180();
    void* FUN_005fe130(unsigned int);
};
// Calls FUN_005fe180, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x005fe130
void* FUN_005fe130_shell::FUN_005fe130(unsigned int flags)
{
    FUN_005fe180();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005fe160_shell : public TESModel
{
    FUN_005fe160_shell();
};
// @fnv 0x005fe160
FUN_005fe160_shell::FUN_005fe160_shell()
{}

struct FUN_005ff4d0_shell : public TESIdleForm
{
    TESIdleForm* GetIdleFormByIndex(unsigned int);
};

struct FUN_004d6170_shell
{
    TESForm* FUN_004d6170(unsigned int);
};
struct Off40_5ff4d0
{
    char _0[0x40];
    FUN_004d6170_shell* p;
};
// Looks up the form at aiIndex through the pointer at offset 0x40 and returns it cast to TESIdleForm, or null if that pointer is unset.
// @fnv 0x005ff4d0
TESIdleForm* FUN_005ff4d0_shell::GetIdleFormByIndex(unsigned int aiIndex)
{
    TESIdleForm* pretidle = 0;
    if (((Off40_5ff4d0*)this)->p)
    {
        pretidle = dynamic_cast<TESIdleForm*>(((Off40_5ff4d0*)this)->p->FUN_004d6170(aiIndex));
    }
    return pretidle;
}

unsigned int __cdecl GetRandomNumberInRange(int a, int b);

struct FUN_005ff770_shell
{
    char pad[0x39];
    unsigned char m_39;
    unsigned char m_3a;
    char GetRandomValue();
};

// Returns 0 if m_39 or m_3a is zero, m_39 if it is 0xff, m_3a-1 if m_3a <= m_39, else a random value in [m_39, m_3a] minus 1.
// @fnv 0x005ff770
char FUN_005ff770_shell::GetRandomValue()
{
    if (!m_39 || !m_3a)
        return 0;
    if (m_39 == 0xff)
        return (char)m_39;
    if (m_3a <= m_39)
        return (char)(m_3a - 1);
    return (char)(GetRandomNumberInRange(m_39, m_3a) - 1);
}

extern "C" unsigned int __cdecl _BSStringLength(const char*);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char* dest, unsigned int size, const char* src);
};
struct BSStr
{
    int StrCmp(const char* str, bool caseSensitive) const;
    bool Set(const char* str, unsigned int len);
};
struct FUN_005ff7f0_shell
{
    bool SetStringIfChanged(const char* str);
};
// @fnv 0x005ff7f0
bool FUN_005ff7f0_shell::SetStringIfChanged(const char* str)
{
    unsigned int len = _BSStringLength(str) + 1;
    char* buf = (char*)_alloca(len);
    TaskQueueInterface::CopyStringToBuffer(buf, len, str);
    if (((BSStr*)((char*)this + 0x4c))->StrCmp(buf, true) == 0)
        return false;
    ((BSStr*)((char*)this + 0x4c))->Set(buf, 0);
    return true;
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm* form);
};

struct FUN_005fe510_compare_shell
{
    bool Compare(PerkEntryConditionSet* condition);
};

struct FUN_005fe510_shell
{
    char pad_0x00[0x38];
    unsigned char m_0x38;
    unsigned char m_0x39;
    unsigned char m_0x3a;
    char pad_0x3b;
    unsigned short m_0x3c;
    char pad_0x3d;
    unsigned char m_0x3e;

    bool IsDifferentFrom(TESForm* apCompare);
};

// Compares this TESIdleForm against apCompare: returns true if apCompare is not a TESIdleForm or if any compared field or add-topic list differs.
// @fnv 0x005fe510
bool FUN_005fe510_shell::IsDifferentFrom(TESForm* apCompare)
{
    TESIdleForm* pOtherIdle = dynamic_cast<TESIdleForm*>(apCompare);
    if (!pOtherIdle)
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->FUN_00485270(pOtherIdle))
        return true;

    if (reinterpret_cast<FUN_005fe510_compare_shell*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
            ->Compare(reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<TESTopicInfo*>(pOtherIdle)->GetAddTopicList())))
        return true;

    if (m_0x38 != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x38)
        return true;

    if (m_0x39 != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x39)
        return true;

    if (m_0x3a != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x3a)
        return true;

    if (m_0x3c != reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)->m_0x3c)
        return true;

    if (*(reinterpret_cast<unsigned char*>(this) + 0x3e) !=
        *(reinterpret_cast<unsigned char*>(reinterpret_cast<FUN_005fe510_shell*>(pOtherIdle)) + 0x3e))
        return true;

    return false;
}

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct FUN_004891d0_obj
{
    void WriteToBuffer(unsigned int, unsigned int);
};

struct Idle_008b2010
{
    Idle_008b2010* GetState();
};

struct TESConditionSave
{
    void ProcessItems();
};

struct FUN_00485e00_shell
{
    void FUN_00485e20(int, int);
};

struct FUN_005fea50_shell
{
    void FUN_005fea50();
};

bool __cdecl _FUN_00401500();
void __cdecl _FUN_00485990(unsigned int, void*, unsigned int);

// @fnv 0x005fea50
void FUN_005fea50_shell::FUN_005fea50()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();

    reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<char*>(this) + 0x18)->WriteToBuffer(0x4c444f4d, 0x54444f4d);

    reinterpret_cast<TESConditionSave*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())->ProcessItems();

    FUN_005a71d0 a;
    BGSImpactData* pImpactData;

    memset(&a, 0, 8);

    if (reinterpret_cast<Idle_008b2010*>(this)->GetState())
    {
        a.parent = reinterpret_cast<TESForm*>(reinterpret_cast<Idle_008b2010*>(this)->GetState())->GetFormID();
    }

    if (!reinterpret_cast<TESForm*>(this)->IsDeleted())
    {
        pImpactData = reinterpret_cast<BGSImpactData*>(reinterpret_cast<BGSImpactData*>(this)->GetDecalTextureSet());
        while (pImpactData && reinterpret_cast<TESForm*>(pImpactData)->IsDeleted())
            pImpactData = reinterpret_cast<BGSImpactData*>(pImpactData->GetDecalTextureSet());
        if (pImpactData)
            a.previous = reinterpret_cast<TESForm*>(pImpactData)->GetFormID();
    }

    if (_FUN_00401500())
        a.FUN_00462230();

    _FUN_00485990(0x4d414e41, &a, 8);

    if (_FUN_00401500())
        a.FUN_00462230();

    if (_FUN_00401500())
        reinterpret_cast<IdleAnimationData*>(reinterpret_cast<char*>(this) + 0x38)->SwapEndian();

    reinterpret_cast<FUN_00485e00_shell*>(this)->FUN_00485e20(
        reinterpret_cast<int>(reinterpret_cast<char*>(this) + 0x38), 8);

    if (_FUN_00401500())
        reinterpret_cast<IdleAnimationData*>(reinterpret_cast<char*>(this) + 0x38)->SwapEndian();

    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct FUN_00680a70_obj
{
    void CopyConditions(FUN_00680a70_obj* a1, int a2);
};

struct FUN_005054b0_shell
{
    void FUN_004851b0(TESForm* apForm);
};

bool __fastcall FUN_004077c0(void const* apForm);

struct FUN_005fe470_shell : public TESIdleForm
{
    void CopyFromIdleForm(TESForm* apForm);
};

// Casts apForm to TESIdleForm, copies its base data and add-topic list, then restores the previous flag if FUN_004077c0 returns false.
// @fnv 0x005fe470
void FUN_005fe470_shell::CopyFromIdleForm(TESForm* apForm)
{
    TESIdleForm* other = dynamic_cast<TESIdleForm*>(apForm);
    if (!other)
        return;
    reinterpret_cast<FUN_005054b0_shell*>(this)->FUN_004851b0(other);
    reinterpret_cast<FUN_00680a70_obj*>(reinterpret_cast<TESTopicInfo*>(this)->GetAddTopicList())
        ->CopyConditions(reinterpret_cast<FUN_00680a70_obj*>(reinterpret_cast<TESTopicInfo*>(other)->GetAddTopicList()),
                         0);
    bool bFlag = reinterpret_cast<FUN_005ff200_shell*>(this)->IsFlag40Set();
    data = other->data;
    if (!FUN_004077c0(this))
        reinterpret_cast<FUN_005ff220_shell*>(this)->SetFlag40(bFlag);
}

struct FormCopyMap
{
    bool GetAt(TESForm* key, TESForm*& value);
};
struct IdleArrayMethods
{
    void FUN_0061bdc0();
    unsigned int FUN_0084e3a0();
    TESForm*& FUN_00877a30(unsigned int);
    void FUN_00864280(unsigned int);
    void FUN_0061bd20(unsigned int, TESForm*&);
};
struct IdleCopy : TESIdleForm
{
    TESForm* FUN_004867a0(unsigned char, FormCopyMap*);
    void FUN_008d8040(TESIdleForm*);
    void FUN_00673400(TESIdleForm*);
    IdleArrayMethods* FUN_005fe770();
    TESIdleForm* CopyIdleForm(unsigned char flag, FormCopyMap* map);
};
// Creates a copy of a TESIdleForm via FUN_004867a0, remaps two referenced forms through map, and copies the idle array entries into the copy's array.
// @fnv 0x005fe600
TESIdleForm* IdleCopy::CopyIdleForm(unsigned char flag, FormCopyMap* map)
{
    TESIdleForm* p;
    TESForm* h;
    TESIdleForm* i;
    TESIdleForm* s;
    TESForm* f;
    IdleArrayMethods* eb;
    unsigned int cf;
    unsigned int q;
    TESForm* b;
    TESForm* ba;
    TESForm* k;
    i = dynamic_cast<TESIdleForm*>(FUN_004867a0(flag, map));
    h = 0;
    if (!map->GetAt(m_pParentIdleForm, h) || !h)
        h = m_pParentIdleForm;
    s = static_cast<TESIdleForm*>(h);
    static_cast<IdleCopy*>(i)->FUN_008d8040(s);
    h = 0;
    if (!map->GetAt(m_pIdleForm, h) || !h)
        h = m_pIdleForm;
    p = static_cast<TESIdleForm*>(h);
    static_cast<IdleCopy*>(i)->FUN_00673400(p);
    if (m_pParentPath)
    {
        reinterpret_cast<IdleArrayMethods*>(m_pParentPath)->FUN_0061bdc0();
        cf = reinterpret_cast<IdleArrayMethods*>(m_pParentPath)->FUN_0084e3a0();
        eb = static_cast<IdleCopy*>(i)->FUN_005fe770();
        eb->FUN_00864280(cf);
        f = 0;
        for (q = 0; q < cf; q++)
        {
            ba = reinterpret_cast<IdleArrayMethods*>(m_pParentPath)->FUN_00877a30(q);
            b = ba->CreateForm(reinterpret_cast<void*>(flag), map);
            k = b;
            eb->FUN_0061bd20(q, k);
            f = b;
        }
    }
    return i;
}

struct IdleFormRemovableArray
{
    unsigned int GetIndexOf(TESForm* form);
    TESForm* RemoveAt(unsigned int index);
    void Compact();
    TESForm*& GetAt(unsigned int index);
};

struct IdleManagerStub
{
    IdleFormRemovableArray* GetLooseIdles(TESIdleForm* idle);
    IdleFormRemovableArray* GetRootArray(TESIdleForm* idle);
};

struct IdleChildHolder
{
    IdleFormRemovableArray* GetChildArray();
};

struct IdleFormLinks
{
    bool IsLooseIdle();
    void SetLooseIdle(bool set);
    IdleChildHolder* GetParentIdle();
    void SetParentLink(int value);
    IdleFormLinks* GetPrevIdle();
    void SetPrevIdle(IdleFormLinks* prev);
    bool GetInitialized() const;
    unsigned int GetFormIDValue();
};

struct IdleFormDetach : public IdleFormLinks
{
    void DetachFromIdleList();
};

// Removes this idle form from its loose-idle or sibling array, compacts the array, and relinks the neighbouring entry's previous pointer.
// @fnv 0x005ff610
void IdleFormDetach::DetachFromIdleList()
{
    if (IsLooseIdle())
    {
        IdleFormRemovableArray* pArray = ((IdleManagerStub*)DAT_011cb6a0)->GetLooseIdles((TESIdleForm*)this);
        unsigned int uiIndex_2 = pArray->GetIndexOf((TESForm*)this);
        if (uiIndex_2 != -1)
        {
            pArray->RemoveAt(uiIndex_2);
            pArray->Compact();
        }
        SetLooseIdle(false);
    }
    else
    {
        IdleFormRemovableArray* pSiblingsA = 0;
        if (GetParentIdle())
            pSiblingsA = GetParentIdle()->GetChildArray();
        else
            pSiblingsA = ((IdleManagerStub*)DAT_011cb6a0)->GetRootArray((TESIdleForm*)this);
        if (pSiblingsA)
        {
            unsigned int uiPos4 = pSiblingsA->GetIndexOf((TESForm*)this);
            if (uiPos4 != -1)
            {
                pSiblingsA->RemoveAt(uiPos4);
                pSiblingsA->Compact();
                SetParentLink(0);
                IdleFormLinks* pNext2 = (IdleFormLinks*)pSiblingsA->GetAt(uiPos4);
                if (pNext2)
                {
                    if (pNext2->GetInitialized())
                    {
                        pNext2->SetPrevIdle(GetPrevIdle());
                    }
                    else
                    {
                        IdleFormLinks* pPrev8 = GetPrevIdle();
                        pNext2->SetPrevIdle((IdleFormLinks*)(pPrev8 ? pPrev8->GetFormIDValue() : 0));
                    }
                    SetPrevIdle(0);
                }
            }
        }
    }
}

struct IdleBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~IdleBase();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct IdleModel
{
    virtual ~IdleModel();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct IdleChildren
{
    virtual ~IdleChildren();
};
struct IdleBaseArray
{
    unsigned int Find(void*);
    IdleBase* At(unsigned int);
    IdleBase* Remove(unsigned int);
    void Compact();
};
struct IdleLink : IdleBase
{
    void SetParent(int);
    IdleLink* Previous();
    void SetPrevious(IdleLink*);
};
struct IdleParent
{
    void RemoveIdle(void*);
};
struct IdleManager
{
    IdleBaseArray* FindRoot(void*);
    IdleBaseArray* FindOther(void*);
};
struct IdleHandler
{
    bool Busy();
};

struct FUN_005fe180 : IdleBase, IdleModel
{
    PerkEntryConditionSet conditions;
    int data38;
    int data3c;
    IdleChildren* children;
    int parent44;
    int prev48;
    BSStringT<char> name;
    virtual ~FUN_005fe180();
    void Clear();
    IdleParent* Parent();
    IdleLink* Previous();
    unsigned int Count();
    IdleLink* Child(unsigned int);
};
// Clears the idle, unlinks it from its parent or the root/other arrays, then detaches and deletes all children and the children container.
// @fnv 0x005fe180
FUN_005fe180::~FUN_005fe180()
{
    Clear();
    if (!g_dataHandler->FUN_004226e0())
    {
        if (Parent())
        {
            Parent()->RemoveIdle(this);
        }
        else
        {
            IdleBaseArray* array = ((IdleManager*)DAT_011cb6a0)->FindRoot(this);
            if (array)
            {
                unsigned int index = array->Find(this);
                if (index != -1)
                {
                    IdleLink* next = (IdleLink*)array->At(index + 1);
                    if (next)
                        next->SetPrevious(Previous());
                    array->Remove(index);
                    array->Compact();
                }
            }
            array = ((IdleManager*)DAT_011cb6a0)->FindOther(this);
            if (array)
            {
                unsigned int other = array->Find(this);
                if (other != -1)
                {
                    array->Remove(other);
                    array->Compact();
                }
            }
        }
    }
    if (children)
    {
        unsigned int count = Count();
        if (count)
        {
            for (unsigned int pos = 0; pos < count; pos++)
            {
                IdleLink* child = Child(pos);
                child->SetParent(0);
                delete child;
            }
        }
        delete children;
    }
}

struct TESConditionInit
{
    void InitItem(TESForm*);
};
struct IdleInit : TESIdleForm
{
    TESConditionInit* GetAddTopicList();
    int GetFlagsMasked();
    void FUN_005ff190(int);
    void FUN_008d8040(TESIdleForm*);
    void FUN_00673400(TESIdleForm*);
    void FUN_00484ab0(int);
    void InitLoad();
};
TESForm* __cdecl LookupFormByID(unsigned int);
void __cdecl ResolveFormID(unsigned int*, TESFile*);
void __cdecl FNV_Warning(const char*, ...);
// Initializes the idle form once: sets up the add-topic list, validates the anim group, resolves parent and previous idle forms, and marks it initialized.
// @fnv 0x005feb90
void IdleInit::InitLoad()
{
    if (GetInitialized())
        return;
    GetAddTopicList()->InitItem(this);
    int id = GetFlagsMasked();
    if (id >= 8)
    {
        switch (id)
        {
        case 20:
        case 21:
            break;
        default:
            FNV_Warning(
                "MASTERFILE: Invalid anim group section encountered on idle '%s' (%08X). Resetting to Special Idle.",
                GetName(), GetFormID());
            FUN_005ff190(7);
            break;
        }
    }
    unsigned int uiFormId = (unsigned int)m_pParentIdleForm;
    if (uiFormId)
    {
        ResolveFormID(&uiFormId, GetFile(-1));
        TESIdleForm* parent = dynamic_cast<TESIdleForm*>(LookupFormByID(uiFormId));
        if (!parent)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            FNV_Warning("MASTERFILE: Could not find parent idle (%08X) for %s.", uiFormId, name.String());
        }
        FUN_008d8040(parent);
    }
    uiFormId = (unsigned int)m_pIdleForm;
    if (uiFormId)
    {
        ResolveFormID(&uiFormId, GetFile(-1));
        TESIdleForm* previous = dynamic_cast<TESIdleForm*>(LookupFormByID(uiFormId));
        if (!previous)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            FNV_Warning("MASTERFILE: Could not find previous idle (%08X) for %s.", uiFormId, name.String());
        }
        FUN_00673400(previous);
    }
    FUN_00484ab0(1);
}
