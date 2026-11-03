// fallout_shared/tesscript.cpp: Script, ScriptLocals, DelStandIn, ScriptInitOwner and more (82 functions)

#include "tesscript_decls.h"
// @fnv 0x005aa0f0
Script::Script()
{
    InitializeComponent();
}

// @fnv 0x005ac740
bool Script::IsConsolePlatform()
{
    return DAT_0118c685;
}

// @fnv 0x006ebc50
void ScriptLocals::ProcessPendingTasks()
{
    m_pOwnerScript->Update();
}

// @fnv 0x005ab7d0
void Script::InitItem()
{
    InitItem(this);
}

// @fnv 0x005acc70
void Script::CopyIdentifierBitsToValue(const unsigned int& id, double& value)
{
    memcpy(&value, &id, sizeof(unsigned int));
}

// @fnv 0x00541cb0
TESBoundObject* ScriptLocals::GetActionEntry()
{
    return reinterpret_cast<ScriptActionView*>(this)->vfn_94();
}

// @fnv 0x005533c0
void Script::GetLocalData()
{
    TESBoundObject* object = reinterpret_cast<ScriptLocals*>(this)->GetLocalData();
    if (object)
        object->IsBoundItem();
}

// Returns the bound object from this ScriptLocals instance, or null when the instance pointer is null.
// @fnv 0x00541c80
TESBoundObject* ScriptLocals::GetLocalData()
{
    return this ? GetActionEntry() : 0;
}

// Runs this script on the given reference with the given locals and time via the singleton instance.
// @fnv 0x005ac3c0
void Script::AdvanceScript(TESObjectREFR* ref, ScriptLocals* locals, float time)
{
    ScriptExecutor::Instance()->Run(this, ref, locals, 0, false, false, false, time);
}

// @fnv 0x005aa2a0
void Script::ClearData()
{
    ::operator delete(m_data);
    ::operator delete(m_pText);
    FUN_005aa2e0();
    InitializeActionList();
}

// Deletes this ScriptLocals object.
// @fnv 0x0041af70
void ScriptLocals::Destroy()
{
    delete this;
}

// Zeroes the 0x14-byte object at pThis, clears the int at offset 0 and offset 0x10, and returns pThis.
// @fnv 0x005a8b80
void* __fastcall FUN_005a8b80(void* apObject)
{
    memset(apObject, 0, 0x14);
    *reinterpret_cast<int*>(apObject) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(apObject) + 0x10) = 0;
    return apObject;
}

struct FUN_005a8bc0_shell : public ScriptLocals
{
    void FUN_005a8bc0();
};

void __cdecl Deallocate(void* p);
void __fastcall FUN_005a8c00(void* pThis);
void __fastcall FUN_005a8c90(void* pThis);

// Calls two cleanup helpers, then deallocates the pointer stored at offset 0x10 if it is non-null.
// @fnv 0x005a8bc0
void FUN_005a8bc0_shell::FUN_005a8bc0()
{
    FUN_005a8c00(this);
    FUN_005a8c90(this);
    if (*(void**)((char*)this + 0x10) != 0)
    {
        void* p = *(void**)((char*)this + 0x10);
        Deallocate(p);
    }
}

struct FUN_005a8c90_shell : public ScriptLocals
{
    void FUN_005a8c90();
};

// Deletes every item in the list at offset 0xc, then deletes the list itself and nulls the pointer.
// @fnv 0x005a8c90
void FUN_005a8c90_shell::FUN_005a8c90()
{
    if (*(BSSimpleList<ScriptLocalVariable*>**)((char*)this + 0xc))
    {
        while ((*(BSSimpleList<ScriptLocalVariable*>**)((char*)this + 0xc))->GetItem())
        {
            ScriptLocalVariable* local = (*(BSSimpleList<ScriptLocalVariable*>**)((char*)this + 0xc))->GetItem();
            (*(BSSimpleList<ScriptLocalVariable*>**)((char*)this + 0xc))->RemoveHead();
            delete local;
        }
        delete *(BSSimpleList<ScriptLocalVariable*>**)((char*)this + 0xc);
        *(BSSimpleList<ScriptLocalVariable*>**)((char*)this + 0xc) = 0;
    }
}

struct Act5a
{
    int a;
    unsigned int flags;
};
struct FUN_005a8e20_cls
{
    int pad[2];
    int* actionList;
    Act5a* FUN_005a90b0(void* form, bool create);
    bool FUN_005a8e20(void* form, unsigned int flag);
};
// @fnv 0x005a8e20
bool FUN_005a8e20_cls::FUN_005a8e20(void* form, unsigned int flag)
{
    bool result = false;
    if (!actionList)
        return false;
    Act5a* obj = FUN_005a90b0(form, true);
    if (obj)
    {
        obj->flags |= flag;
        result = true;
    }
    obj = FUN_005a90b0(0, true);
    if (obj)
    {
        obj->flags |= flag;
        result = true;
    }
    return result;
}

struct FUN_005a8ea0_shell : public ScriptLocals
{
    void FUN_005a8ea0();
};

int* __fastcall _ref_006815c0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);

// Walks the list at this+8 and sets the second int of each entry returned by _ref_006815c0 to 0 until the list or entry is null.
// @fnv 0x005a8ea0
void FUN_005a8ea0_shell::FUN_005a8ea0()
{
    void* pList = *(void**)((char*)this + 8);
    while (pList && *_ref_006815c0(pList))
    {
        int* used = (int*)*_ref_006815c0(pList);
        pList = _ref_00726070(pList);
        used[1] = 0;
    }
}

struct FUN_005a9140_shell : public ScriptLocals
{
    double FUN_005a9140(unsigned int, Script*);
};

extern const char DAT_01015890[];
extern int DAT_011cae50;

bool __fastcall _ref_008256d0(unsigned int);
ScriptLocalVariable** __fastcall _ref_006815c0(unsigned int);
unsigned int __fastcall _ref_00726070(unsigned int);

struct TLS_Data_005a9140
{
    char pad[0x270];
    ScriptLocalVariable* pLastLocal;
    unsigned int uiLastID;
    void* pLastLocals;
};

__declspec(thread) TLS_Data_005a9140 tls_005a9140;

// Looks up a script local variable by ID (using a TLS cache), returns its double value, or warns and returns 0.0 if not found.
// @fnv 0x005a9140
double FUN_005a9140_shell::FUN_005a9140(unsigned int auiID, Script* apScript)
{
    ScriptLocalVariable* plocalvar = 0;
    if (tls_005a9140.pLastLocals == this && tls_005a9140.uiLastID == auiID)
    {
        plocalvar = tls_005a9140.pLastLocal;
    }
    if (plocalvar == 0)
    {
        unsigned int pCurrentElementNext = ((TESForm*)this)->GetFormID();
        while (pCurrentElementNext != 0 && !_ref_008256d0(pCurrentElementNext))
        {
            ScriptLocalVariable* pCandidate = *_ref_006815c0(pCurrentElementNext);
            if (*(unsigned int*)pCandidate == auiID)
            {
                plocalvar = pCandidate;
                break;
            }
            pCurrentElementNext = _ref_00726070(pCurrentElementNext);
        }
    }
    tls_005a9140.pLastLocals = this;
    tls_005a9140.uiLastID = auiID;
    tls_005a9140.pLastLocal = plocalvar;
    if (plocalvar != 0)
    {
        return *(double*)((char*)plocalvar + 8);
    }
    Warning(
        "SCRIPTS: Variable ID %08X not found. Try to recompile script '%s'. The script may also have a bad reference variable in an if statement on line %d.",
        auiID, apScript ? ((TESForm*)apScript)->GetName() : DAT_01015890, DAT_011cae50);
    return 0.0;
}

struct ListX
{
    int a[2];
    ~ListX();
};
struct Base5a
{
    virtual ~Base5a();
    char pad[0x44 - 4];
};
struct FUN_005aa1a0 : public Base5a
{
    ListX l1;
    ListX l2;
    virtual void ClearData();
    virtual ~FUN_005aa1a0();
};
// @fnv 0x005aa1a0
FUN_005aa1a0::~FUN_005aa1a0()
{
    ClearData();
}

struct FUN_005aa220_shell : public Script
{
    void ResetScriptData();
};

void* __cdecl memset(void*, int, unsigned int);

__declspec(thread) extern char tls_pad[0x268];
__declspec(thread) extern bool tls_bIsInitialized;

// Clears the script's data fields and TLS state, then sets the form type to 0x11.
// @fnv 0x005aa220
void FUN_005aa220_shell::ResetScriptData()
{
    memset(&m_kHeader, 0, sizeof(m_kHeader));
    m_data = 0;
    m_pText = 0;
    tls_bIsInitialized = false;
    m_pOwnerQuest = 0;
    m_fValueAtOffset34 = 0.0f;
    fValueAtOffset38 = 0.0f;
    m_fValueAtOffset3C = 0.0f;
    SetFormType((ENUM_FORM_ID)0x11);
}

// Deletes every item in the variable list and removes each head until the list is empty.
// @fnv 0x005aa2e0
void Script::FUN_005aa2e0()
{
    BSSimpleList<ScriptVariableInfo*>* pList = GetVariableList();
    while (pList && !pList->IsEmpty())
    {
        delete pList->GetItem();
        pList->RemoveHead();
    }
}

struct FUN_005aa420_shell : public Script
{
    void CopyFromScript(Script*);
};

void* __cdecl memcpy(void*, const void*, unsigned int);

// Copies the header, data, referenced objects, variables and text from another Script into this one, resetting the variable count.
// @fnv 0x005aa420
void FUN_005aa420_shell::CopyFromScript(Script* apScriptToCopy)
{
    if (!apScriptToCopy)
        return;

    memcpy(&m_kHeader, apScriptToCopy->GetHeader(), sizeof(ScriptHeaderData));
    m_kHeader.variableCount = 0;

    SetScriptData(m_kHeader.dataSize, apScriptToCopy->GetData());

    InitializeActionList();
    CopyScriptReferences(apScriptToCopy->GetReferencedObjectList(), GetReferencedObjectList(), this);

    FUN_005aa2e0();
    CopyListToView(apScriptToCopy->GetVariableList(), GetVariableList(), this);

    if (apScriptToCopy->GetText())
        SetText(apScriptToCopy->GetText());
    else
        SetText(0);

    SetInitializationState(apScriptToCopy->IsFormInitialized());
}

struct G2
{
    void _ref_00905330(int* p);
    void AddHead(int* p);
};
struct ATM
{
    void QueryPerformanceCounter(int a);
    void WaitForTasksDuringRendering();
};
extern G2 g_011cac98;
extern G2 g_011caca8;
extern ATM g_011cacf8;
bool FUN_005aa680(int p);
// Queries the performance counter, and if value is non-zero references it and adds it to a list unless FUN_005aa680 accepts it, then waits for rendering tasks.
// @fnv 0x005aa580
void FUN_005aa580(int value)
{
    g_011cacf8.QueryPerformanceCounter(0);
    if (value)
    {
        g_011cac98._ref_00905330(&value);
        if (!FUN_005aa680(value))
            g_011caca8.AddHead(&value);
    }
    g_011cacf8.WaitForTasksDuringRendering();
}

namespace fnv_005aa5d0 {
struct G2
{
    void _ref_00905330(int* p);
};
struct ATM
{
    void QueryPerformanceCounter(int a);
    void WaitForTasksDuringRendering();
};
extern G2 g_011cac98;
extern G2 g_011caca8;
extern G2 g_011cacb8;
extern G2 g_011cace8;
extern ATM g_011cacf8;
// If value is nonzero, queries the performance counter, passes value to four objects' _ref_00905330, then waits for tasks during rendering.
// @fnv 0x005aa5d0
void FUN_005aa5d0(int value)
{
    if (value)
    {
        g_011cacf8.QueryPerformanceCounter(0);
        g_011caca8._ref_00905330(&value);
        g_011cac98._ref_00905330(&value);
        g_011cace8._ref_00905330(&value);
        g_011cacb8._ref_00905330(&value);
        g_011cacf8.WaitForTasksDuringRendering();
    }
}
}  // namespace fnv_005aa5d0

namespace fnv_005aa630 {
class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

extern BSSimpleList<Actor*> g_011cac98;
extern ActorTaskManager g_011cacf8;

// Checks whether apRef is non-null and present in g_011cac98, bracketing the check with calls on g_011cacf8, and returns the result.
// @fnv 0x005aa630
bool __cdecl FUN_005aa630(Actor* apRef)
{
    bool bretval = false;
    g_011cacf8.QueryPerformanceCounter(0);
    if (apRef && g_011cac98.IsInList(apRef))
        bretval = true;
    g_011cacf8.WaitForTasksDuringRendering();
    return bretval;
}
}  // namespace fnv_005aa630

namespace fnv_005aa680 {
struct ActorTaskManager
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

extern BSSimpleList<Actor*> g_011caca8;
extern ActorTaskManager g_011cacf8;

// Checks whether apRef is non-null and present in g_011caca8, calling QueryPerformanceCounter and WaitForTasksDuringRendering around the check.
// @fnv 0x005aa680
bool __cdecl FUN_005aa680(Actor* apRef)
{
    bool bretval = false;
    g_011cacf8.QueryPerformanceCounter(0);
    if (apRef && g_011caca8.IsInList(apRef))
        bretval = true;
    g_011cacf8.WaitForTasksDuringRendering();
    return bretval;
}
}  // namespace fnv_005aa680

namespace fnv_005aa720 {
class ActorTaskManager
{
  public:
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};

extern ActorTaskManager g_011cacf8;

void __fastcall FUN_00573f40(TESObjectREFR* ref);
bool __fastcall FUN_005aa8c0(BSFadeNode* fadeNode);

extern BSSimpleList<TESObjectREFR*> g_011caca8;
extern BSSimpleList<TESObjectREFR*> g_011cac98;
extern BSSimpleList<TESObjectREFR*> g_011cace8;
extern BSSimpleList<TESObjectREFR*> g_011cacb8;

// @fnv 0x005aa720
void FUN_005aa720()
{
    BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
    g_011cacf8.QueryPerformanceCounter(0);
    while (!g_011caca8.IsEmpty())
    {
        TESObjectREFR* pref = g_011caca8.GetItem();
        g_011caca8.RemoveHead();
        FUN_00573f40(pref);
    }
    while (!g_011cac98.IsEmpty())
    {
        TESObjectREFR* pref = g_011cac98.GetItem();
        g_011cac98.RemoveHead();
        pref->FUN_00574400();
    }
    pCurrentElementNext = &g_011cace8;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        TESObjectREFR* pref;
        NiNode* pav;
        BSSimpleList<TESObjectREFR*>* m_pActionSuccessor = pCurrentElementNext->GetNext();
        pref = pCurrentElementNext->GetItem();
        pav = pref->GetNiNode_v();
        BSFadeNode* pfade = pav ? pav->GetFadeNode() : 0;
        if (!pfade || !FUN_005aa8c0(pfade))
        {
            pref->FUN_00574400();
            g_011cace8.Remove(pref);
            if (pCurrentElementNext == &g_011cace8)
                m_pActionSuccessor = &g_011cace8;
        }
        pCurrentElementNext = m_pActionSuccessor;
    }
    while (!g_011cacb8.IsEmpty())
    {
        TESObjectREFR* pref = g_011cacb8.GetItem();
        g_011cacb8.RemoveHead();
        delete pref;
    }
    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aa720

struct FUN_005aae70_shell : public Script
{
    void FUN_005aae70(unsigned int, char*);
};

void __cdecl Deallocate(void*);
char* __cdecl AllocateZeroed(unsigned int, unsigned int);

// Frees m_data, stores auiDataSize at offset 0x20, and if nonzero allocates that many bytes and copies apCompileData into m_data.
// @fnv 0x005aae70
void FUN_005aae70_shell::FUN_005aae70(unsigned int auiDataSize, char* apCompileData)
{
    Deallocate(m_data);
    m_data = 0;
    *(unsigned int*)((char*)this + 0x20) = auiDataSize;
    if (*(unsigned int*)((char*)this + 0x20))
    {
        m_data = AllocateZeroed(1, *(unsigned int*)((char*)this + 0x20));
        memcpy(m_data, apCompileData, *(unsigned int*)((char*)this + 0x20));
    }
}

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};

MemoryManager* __cdecl FUN_00401020(void);

// Multiplies aSize by aNum, allocates that many bytes from the memory manager, zeroes them with memset, and returns the pointer.
// @fnv 0x005aaee0
char* __cdecl AllocateZeroed(unsigned int aNum, unsigned int aSize)
{
    aSize = aSize * aNum;
    void* pBuffer = FUN_00401020()->Allocate(aSize);
    memset(pBuffer, 0, aSize);
    return (char*)pBuffer;
}

void* __cdecl operator new(unsigned int);
bool __fastcall _ref_008256d0(void*);
int* __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

class SoundListEntry;
class SoundListView
{
  public:
    void AddTail(SoundListEntry* const&);
};

struct FUN_005ab8b0
{
    int pad[4];
    FUN_005ab8b0(int);
};

// Copies each element of pCopyFromList into a new FUN_005ab8b0 and appends it to pCopyToList until the source list is exhausted or _ref_008256d0 returns true.
// @fnv 0x005ab7f0
void __cdecl CopyListToTail(void* pSourceList, SoundListView* pCopyToList)
{
    if (!pCopyToList || !pSourceList)
        return;

    while (pSourceList && !_ref_008256d0(pSourceList))
    {
        SoundListEntry* pNewRefObject = (SoundListEntry*)new FUN_005ab8b0(*_ref_006815c0(pSourceList));
        pCopyToList->AddTail(pNewRefObject);
        pSourceList = _ref_00726070(pSourceList);
    }
}

struct FUN_005abe50_shell : public Script
{
    void FUN_005abe50(char*);
};

void __cdecl Deallocate(void*);
unsigned int __cdecl strlen(const char*);
void* __cdecl memcpy(void*, const void*, unsigned int);
char* __cdecl AllocateZeroed(int, int);

// Frees the stored string, then copies newText into a newly allocated buffer (or clears it when newText is null).
// @fnv 0x005abe50
void FUN_005abe50_shell::FUN_005abe50(char* newText)
{
    if (m_pText)
    {
        Deallocate(m_pText);
    }
    if (newText)
    {
        int iSize = strlen(newText);
        m_pText = AllocateZeroed(1, iSize + 1);
        memcpy(m_pText, newText, iSize);
    }
    else
    {
        m_pText = 0;
    }
}

struct FUN_005abf60_shell : public Script
{
    ScriptLocals* FUN_005abf60();
};

void* __cdecl operator new(unsigned int);
void* __fastcall CopyVariableList(Script*);

// Allocates a ScriptLocals, stores the result of CopyVariableList(this) at offset 0xc and this at offset 0, then returns it.
// @fnv 0x005abf60
ScriptLocals* FUN_005abf60_shell::FUN_005abf60()
{
    AutoMemContext tempMemContext(static_cast<MEM_CONTEXT>(0x15), true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 0xcde);
    ScriptLocals* sl = new ScriptLocals;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(sl) + 0xc) = CopyVariableList(this);
    *reinterpret_cast<Script**>(sl) = this;
    return sl;
}

// @fnv 0x005ac190
void __cdecl FUN_005ac190(TESObjectREFR* ownerObject, ExtraDataList* apExtra)
{
    if (apExtra && apExtra->FUN_00418830())
    {
        ScriptLocals* locals = apExtra->FUN_00418830();
        if (!locals->m_pLocalVariableList)
        {
            ScriptExecutor::Instance()->FUN_005e2730(locals->m_pOwnerScript, ownerObject, locals);
        }
    }
}

struct FUN_005ac1e0_shell : public Script
{
    bool FUN_005ac1e0(TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool);
};

extern SettingT_GameSettingCollection_ g_011cac68;

// Runs the script via the script runner, decrementing a timer and resetting it from the game setting or a referenced value when the header flag is set.
// @fnv 0x005ac1e0
bool FUN_005ac1e0_shell::FUN_005ac1e0(TESObjectREFR* ownerObject, ScriptLocals* ownerVars,
                                      TESObjectREFR* ownerContainer, bool abIsPartialScript)
{
    if (!abIsPartialScript && GetHeader()->dataSize <= 4)
        return false;

    if (GetHeader()->m_bQuest && fValueAtOffset38 > 0.0)
    {
        fValueAtOffset38 -= g_timeGlobal.FUN_0084d030();
        m_fValueAtOffset3C += g_timeGlobal.FUN_0084d030();
        if (fValueAtOffset38 > 0.0)
            return false;
    }

    bool bretVal = ScriptExecutor::Instance()->Run(this, ownerObject, ownerVars, ownerContainer, abIsPartialScript,
                                                   false, false, 0.0f);

    if (GetHeader()->m_bQuest && g_011cac68.Float()->f > 0.0)
    {
        if (m_pOwnerQuest && m_pOwnerQuest->FUN_00792760() > 0.0)
        {
            fValueAtOffset38 += m_pOwnerQuest->FUN_00792760();
        }
        else
        {
            fValueAtOffset38 += g_011cac68.Float()->f;
        }
        m_fValueAtOffset3C = 0.0f;
    }

    FUN_005ae2e0();
    return bretVal;
}

namespace fnv_005ac4f0 {
struct FUN_005ac4f0_shell : public Script
{
    ScriptReferencedObject* GetNthRefByIndex(unsigned int, ScriptLocals*);
};

struct ScriptLocals_shell : public ScriptLocals
{
    double FUN_005a9140(unsigned int auiIndex, Script* apScript);
};

void __cdecl FUN_005acc90(unsigned int* apFormID, double* apValue);
bool __fastcall _ref_008256d0(void* pList);
void* __fastcall _ref_00726070(void* pList);
ScriptReferencedObject** __fastcall _ref_006815c0(void* pList);

struct TLSData
{
    char padding[0x27c];
    ScriptReferencedObject* lastRefObj;
    unsigned int lastIndex;
    ScriptLocals* lastLocals;
    Script* lastScript;
};

__declspec(thread) TLSData g_tlsData;

// Returns the reference at aiIndex in this object's extra-data list, resolving its form ID via the script locals and caching the last result in TLS.
// @fnv 0x005ac4f0
ScriptReferencedObject* FUN_005ac4f0_shell::GetNthRefByIndex(unsigned int aiIndex, ScriptLocals* apScriptLocals)
{
    if (aiIndex == 0)
        return 0;
    if (aiIndex > *(unsigned int*)((char*)this + 0x1c))
        return 0;

    if (g_tlsData.lastScript == this && g_tlsData.lastIndex == aiIndex && g_tlsData.lastLocals == apScriptLocals)
        return g_tlsData.lastRefObj;

    void* pList;
    ScriptReferencedObject* pExtraDataEntry;
    unsigned int iCount = 1;
    pList = ((TESObjectREFR*)this)->GetExtraData();

    while (pList && !_ref_008256d0(pList) && iCount < aiIndex)
    {
        iCount++;
        pList = _ref_00726070(pList);
    }

    if (!pList)
        return 0;

    pExtraDataEntry = *_ref_006815c0(pList);
    if (*(unsigned int*)((char*)pExtraDataEntry + 0xc) != 0 && apScriptLocals != 0)
    {
        double dtemp =
            ((ScriptLocals_shell*)apScriptLocals)->FUN_005a9140(*(unsigned int*)((char*)pExtraDataEntry + 0xc), this);
        unsigned int formID = 0;
        FUN_005acc90(&formID, &dtemp);
        if (formID != 0)
        {
            *(TESForm**)((char*)pExtraDataEntry + 8) = TESForm::GetFormByID(formID);
        }
    }

    g_tlsData.lastScript = this;
    g_tlsData.lastLocals = apScriptLocals;
    g_tlsData.lastIndex = aiIndex;
    g_tlsData.lastRefObj = pExtraDataEntry;
    return pExtraDataEntry;
}
}  // namespace fnv_005ac4f0

// If apExtra has script locals, forwards apActionForm and aiFlag to the locals' FUN_005a8e20 and returns its result; otherwise returns false.
// @fnv 0x005ac750
bool __cdecl FUN_005ac750(TESForm* apActionForm, ExtraDataList* apExtra, unsigned int aiFlag)
{
    bool bres = false;
    if (apExtra && apExtra->FUN_00418830())
    {
        ScriptLocals* locals = apExtra->FUN_00418830();
        bres = locals->FUN_005a8e20(apActionForm, aiFlag);
    }
    return bres;
}

// @fnv 0x005acc90
void __cdecl FUN_005acc90(unsigned int* aiID, const double* adVal)
{
    memcpy(aiID, adVal, sizeof(unsigned int));
}

struct FUN_00792760_shell : public TESQuest
{
    float FUN_00792760();
};

// @fnv 0x00792760
float FUN_00792760_shell::FUN_00792760()
{
    return *(float*)((char*)this + 0x40);
}

namespace fnv_005a8d20 {
struct FUN_005a8d20_shell : public ScriptLocals
{
    void AttachScriptLocals(ScriptLocals*);
};

struct Act5a
{
    void* obj;
    int next;
};
struct FUN_005a8e20_cls
{
    Act5a* FUN_005a90b0(void*, bool);
};
struct G2
{
    void AddHead(int*);
};
struct SL
{
    char b[8];
    SL();
};
// @fnv 0x005a8d20
void FUN_005a8d20_shell::AttachScriptLocals(ScriptLocals* apLocals)
{
    AutoMemContext ctx((MEM_CONTEXT)0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                       300);
    if (!*(void**)((char*)this + 8))
        *(SL**)((char*)this + 8) = new SL();
    Act5a* used = ((FUN_005a8e20_cls*)this)->FUN_005a90b0(apLocals, false);
    if (!used)
    {
        used = new Act5a;
        used->obj = apLocals;
        used->next = 0;
        (*(G2**)((char*)this + 8))->AddHead((int*)&used);
    }
}
}  // namespace fnv_005a8d20

struct FUN_005abed0_shell : public Script
{
    char* FUN_005abed0(unsigned int);
};

struct Flt
{
    operator unsigned int() const;
};
struct VarX
{
    unsigned int id;
    char pad[0x14];
    Flt flt;
};
typedef char*(__thiscall* NameFn)(void*);
int* __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
// @fnv 0x005abed0
char* FUN_005abed0_shell::FUN_005abed0(unsigned int auiID)
{
    void* pList = GetVariableList();
    while (pList && *_ref_006815c0(pList))
    {
        VarX* pVar = (VarX*)*_ref_006815c0(pList);
        pList = _ref_00726070(pList);
        if (pVar->id == auiID)
            return (char*)(unsigned int)pVar->flt;
    }
    Warning("SCRIPTS: Trying to access local variable %d in script '%s' -- variable not found.\r\n", auiID,
            (*(NameFn**)this)[0x130 / 4](this));
    return 0;
}

struct FUN_005ae2e0_shell : public Script
{
    void FUN_005ae2e0();
};

bool __fastcall _ref_008256d0(unsigned int);
int* __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
__declspec(thread) void* g_tlsSlot;
struct RefObj
{
    char pad[8];
    int f8;
    int fc;
};
// Clears the thread-local slot if it holds this object, then walks the extra-data list and zeroes f8 on each referenced object that has a nonzero fc.
// @fnv 0x005ae2e0
void FUN_005ae2e0_shell::FUN_005ae2e0()
{
    if (g_tlsSlot == (void*)this)
        g_tlsSlot = 0;
    void* pCurrentElementNext = ((TESObjectREFR*)this)->GetExtraData();
    while (pCurrentElementNext && !_ref_008256d0((unsigned int)pCurrentElementNext))
    {
        RefObj* prefObject = (RefObj*)*_ref_006815c0(pCurrentElementNext);
        if (prefObject && prefObject->fc)
            prefObject->f8 = 0;
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
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
// @fnv 0x005aa170
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_005aa3f0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_005aa3f0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x005aa3f0
void* DelStandIn::FUN_005aa3f0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_005aa3f0

struct FUN_005a9460_This
{
    unsigned int field_1c4;
    unsigned int FUN_005a9460();
};

// @fnv 0x005a9460
unsigned int FUN_005a9460_This::FUN_005a9460()
{
    return reinterpret_cast<unsigned int*>(this)[0x1c4 / 4];
}

namespace fnv_005aae20 {
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};

struct G2
{
    void RemoveAll();
};

struct GlobalObject2_0096a2d0
{
    void RemoveAll();
};

extern ATM g_011cacf8;
extern G2 g_011cac98;
extern G2 g_011caca8;
extern GlobalObject2_0096a2d0 g_011cacb8;
extern GlobalObject2_0096a2d0 g_011cace8;

// @fnv 0x005aae20
void __cdecl FUN_005aae20()
{
    g_011cacf8.QueryPerformanceCounter(0);
    g_011caca8.RemoveAll();
    g_011cac98.RemoveAll();
    g_011cacb8.RemoveAll();
    g_011cace8.RemoveAll();
    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aae20

extern "C" bool __cdecl FUN_00401500();
extern "C" unsigned int __cdecl AppendChunk(unsigned int, void*, unsigned int);

struct FUN_005abe00
{
    unsigned char m_0x00[0x18];
    ScriptHeaderData m_kHeader;  // +0x18
    void ProcessHeader();
};

// @fnv 0x005abe00
void FUN_005abe00::ProcessHeader()
{
    if (FUN_00401500())
        m_kHeader.Endian();
    AppendChunk(0x52484353, &m_kHeader, 0x14);
    if (FUN_00401500())
        m_kHeader.Endian();
}

// @fnv 0x005ac730
void FUN_005ac730(bool abProcessScripts)
{
    DAT_0118c685 = abProcessScripts;
}

__declspec(thread) int DAT_tls;

// @fnv 0x005ae270
void FUN_005ae270()
{
    *(int*)((char*)&DAT_tls + 0x288) = 0;
    *(int*)((char*)&DAT_tls + 0x284) = 0;
    *(int*)((char*)&DAT_tls + 0x280) = 0xffffffff;
    *(int*)((char*)&DAT_tls + 0x27c) = 0;
}

struct FUN_00857bd0
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0c;
    int m_0x10;
    unsigned int m_0x14;
    void Init(unsigned int value);
};

// @fnv 0x00857bd0
void FUN_00857bd0::Init(unsigned int value)
{
    m_0x14 += value;
}

__declspec(thread) int tlsVar1;
__declspec(thread) int tlsVar2 = -1;
__declspec(thread) int tlsVar3;

// Resets the three thread-local variables to 0, -1 and 0.
// @fnv 0x005a9d60
void FUN_005a9d60()
{
    tlsVar1 = 0;
    tlsVar2 = -1;
    tlsVar3 = 0;
}

namespace fnv_005aa6d0 {
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

struct LH
{
    bool IsInList(int*&);
};

extern ATM g_011cacf8;
extern LH g_011cace8;

// Queries the performance counter, checks whether arg is in the list, waits for tasks during rendering, and returns whether arg was found.
// @fnv 0x005aa6d0
char __cdecl FUN_005aa6d0(int* pItem)
{
    char result = 0;
    g_011cacf8.QueryPerformanceCounter(0);
    if (pItem && g_011cace8.IsInList(pItem))
        result = 1;
    g_011cacf8.WaitForTasksDuringRendering();
    return result;
}
}  // namespace fnv_005aa6d0

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
    bool HasFlag8000();
};

// @fnv 0x005aa910
bool FUN_00456630_helper::HasFlag8000()
{
    return this->FUN_00456630(0x8000);
}

struct FUN_00483d20_shell
{
    unsigned char SaveIfNotTemporary(TESFile*);
};

struct FUN_005abd70_shell : FUN_00483d20_shell
{
    unsigned char FUN_005abd70(TESFile*);
};

// @fnv 0x005abd70
unsigned char FUN_005abd70_shell::FUN_005abd70(TESFile* apFile)
{
    return SaveIfNotTemporary(apFile);
}

struct FUN_00857ba0_class
{
    void __thiscall ReadFromStream(int a, int b, int c);
};

void __thiscall FUN_00857ba0_class::ReadFromStream(int a, int b, int c)
{}

struct FUN_008586d0_class
{
    void __thiscall FUN_008586d0(int a, int b, int c);
};

// @fnv 0x008586d0
void __thiscall FUN_008586d0_class::FUN_008586d0(int a, int b, int c)
{
    reinterpret_cast<FUN_00857ba0_class*>(this)->ReadFromStream(a, b, c);
}

struct FUN_005a9290_shell : public ScriptLocals
{
    void SetScriptVariable(unsigned int, double);
};

struct SCRIPT_LOCAL_s
{
    unsigned int uiID;
    unsigned int pad;
    double fValue;
};
struct LocalListStub
{
    SCRIPT_LOCAL_s** _ref_006815c0();
};
struct EffectSettingStub
{
    FormRecordMetadata* GetBoltSound();
};
struct MobileObject
{
    const char* GetFullName();
};

// Searches the script local list for the given variable ID and assigns the value, warning if the variable is not found.
// @fnv 0x005a9290
void FUN_005a9290_shell::SetScriptVariable(unsigned int auiID, double value)
{
    BSSimpleList<SCRIPT_LOCAL_s*>* pList = (BSSimpleList<SCRIPT_LOCAL_s*>*)((TESForm*)this)->GetFormID();
    while (pList && *((LocalListStub*)pList)->_ref_006815c0())
    {
        SCRIPT_LOCAL_s* pLocal = *((LocalListStub*)pList)->_ref_006815c0();
        pList = pList->GetNext();
        if (pLocal->uiID == auiID)
        {
            pLocal->fValue = value;
            return;
        }
    }
    bool bshowGenericWarning = true;
    if (*(TESForm**)this)
    {
        Warning("SCRIPTS: Trying to set variableID %d in script '%s' -- variable not found.", auiID,
                (*(TESForm**)this)->GetName());
        bshowGenericWarning = false;
    }
    else if (g_TESSaveLoadGame->GetLoading())
    {
        FormRecordMetadata* ploadHeader = ((EffectSettingStub*)g_TESSaveLoadGame)->GetBoltSound();
        TESForm* pform = 0;
        if (ploadHeader)
        {
            pform = TESForm::GetFormByID(ploadHeader->iFormID);
            TESObjectREFR* pref = dynamic_cast<TESObjectREFR*>(pform);
            const char* pfullname;
            if (pref)
                pfullname = ((MobileObject*)pref)->GetFullName();
            else
                pfullname = TESFullName::GetFullName(pform);
            if (pform && pfullname)
            {
                if (pref)
                    Warning(
                        "SAVELOAD: (LoadGame '%s') Trying to set variableID %d on ref '%s' (%08X) -- variable not found. The script may have been changed in the master/plug-in file.",
                        g_TESSaveLoadGame->FUN_005a9460(), auiID, pfullname, ploadHeader->iFormID);
                else
                    Warning(
                        "SAVELOAD: (LoadGame '%s') Trying to set variableID %d on '%s' (%08X) -- variable not found. The script may have been changed in the master/plug-in file.",
                        g_TESSaveLoadGame->FUN_005a9460(), auiID, pfullname, ploadHeader->iFormID);
            }
            else
            {
                Warning(
                    "SAVELOAD: (LoadGame '%s') Trying to set variableID %d on (%08X) -- variable not found. The script may have been changed in the master/plug-in file.",
                    g_TESSaveLoadGame->FUN_005a9460(), auiID, ploadHeader->iFormID);
            }
            bshowGenericWarning = false;
        }
    }
    if (bshowGenericWarning)
        Warning("SCRIPTS: Trying to set variableID %d -- variable not found.", auiID);
}

namespace fnv_005a9f20 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_005a9f20_shell : public ScriptLocals
{
    void FUN_005a9f20(BGSLoadFormBuffer*);
};

struct FUN_005a8ea0_shell
{
    void FUN_005a8ea0();
};

// @fnv 0x005a9f20
void FUN_005a9f20_shell::FUN_005a9f20(BGSLoadFormBuffer* apLoadGameBuffer)
{
    bool bhasScriptEffectData;
    bool bonLoadFlagSet;
    {
        unsigned int iVariableCount = apLoadGameBuffer->ReadElementCount();
        for (unsigned int iIndex = 0; iIndex < iVariableCount; iIndex++)
        {
            double fvalue = 0.0;
            unsigned int ivarID = 0;
            apLoadGameBuffer->ReadTypedData((void*)&ivarID, 4);
            if (ivarID & 0x80000000)
            {
                ivarID &= 0x7fffffff;
                unsigned int irefID = 0;
                apLoadGameBuffer->ReadFormIdentifier(&irefID);
                Script::CopyIdentifierBitsToValue(irefID, fvalue);
            }
            else
            {
                apLoadGameBuffer->ReadTypedData((void*)&fvalue, 8);
            }
            SetVariable(ivarID, fvalue);
        }
    }
    bhasScriptEffectData = false;
    apLoadGameBuffer->ReadTypedData((void*)&bhasScriptEffectData, 1);
    if (bhasScriptEffectData)
    {
        *(double**)((char*)this + 0x10) = new double;
        apLoadGameBuffer->ReadTypedData((void*)*(double**)((char*)this + 0x10), 8);
    }
    bonLoadFlagSet = false;
    if (apLoadGameBuffer->GetVersion() >= 0x15)
        apLoadGameBuffer->ReadTypedData((void*)&bonLoadFlagSet, 1);
    if (*(void**)((char*)this + 8) == 0)
        ScriptExecutor::Instance()->FUN_005e2730(*(Script**)this, apLoadGameBuffer->GetReference(), this);
    else
        ((FUN_005a8ea0_shell*)this)->FUN_005a8ea0();
    if (bonLoadFlagSet)
        FUN_005a8e20(0, 0x1000);
}
}  // namespace fnv_005a9f20

namespace fnv_005ac020 {
struct FUN_005ac020_shell : public Script
{
    void* CopyVariableList();
};

struct AutoMemHelper
{
    int aiMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct SL
{
    int a;
    int b;
    SL();
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct S006815c0
{
    ScriptVariableInfo** FUN_006815c0();
    S006815c0* FUN_00726070();
};
struct FUN_005ac150
{
    char data[0x18];
    FUN_005ac150(ScriptVariableInfo*);
};

// @fnv 0x005ac020
void* FUN_005ac020_shell::CopyVariableList()
{
    AutoMemHelper tempMemContext(0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                                 0xceb);
    S006815c0* pList;
    SoundListView* pNewList;

    pNewList = (SoundListView*)new SL;
    pList = (S006815c0*)GetVariableList();
    while (pList && *pList->FUN_006815c0())
    {
        char* pLocal;
        ScriptVariableInfo* pVar;
        pVar = *pList->FUN_006815c0();
        pList = pList->FUN_00726070();
        pLocal = (char*)new FUN_005ac150(pVar);
        pNewList->AddTail(pLocal);
    }
    return pNewList;
}
}  // namespace fnv_005ac020

namespace fnv_005ab930 {
struct FUN_005e2910
{
    char* m_pInventoryEntryData;
    char m_bIsDeleted;
    FUN_005e2910(char*);
    ~FUN_005e2910();
};

struct FUN_008256d0
{
    char* m_pInventoryEntryData;
    unsigned char FUN_008256d1() const;
    FUN_005e2910* FUN_006815c0() const;
    FUN_008256d0* FUN_00726070();
};

struct SoundListView
{
    void AddTail(FUN_005e2910* const&);
};

struct FUN_005e2910Big
{
    char* m_pInventoryEntryData;
    char m_bIsDeleted;
    FUN_005e2910Big(char*);
    ~FUN_005e2910Big();
    char m_bFiller[0x18];
};

// @fnv 0x005ab930
void CopyListToView(FUN_008256d0* pSourceList, SoundListView* pTargetView)
{
    if (!pTargetView || !pSourceList)
        return;

    while (pSourceList && !pSourceList->FUN_008256d1())
    {
        FUN_005e2910* const pNewItem =
            (FUN_005e2910*)new FUN_005e2910Big(pSourceList->FUN_006815c0()->m_pInventoryEntryData);
        pTargetView->AddTail(pNewItem);
        pSourceList = pSourceList->FUN_00726070();
    }
}
}  // namespace fnv_005ab930

namespace fnv_005aa090 {
void __cdecl _Deallocate(void*);

struct Script;
void* __fastcall CopyVariableList(Script*);
struct FUN_005a8ea0_shell
{
    void FUN_005a8ea0();
};

struct FUN_005aa090
{
    Script* pScript;
    int pad0;
    int pad1;
    void* pData;
    void* pAlloc;
    void __fastcall FUN_005a8c90();
    void Method(int dummy);
};

// Calls FUN_005a8c90 and FUN_005a8ea0, refreshes pData from pScript, frees pAlloc and clears it.
// @fnv 0x005aa090
void FUN_005aa090::Method(int dummy)
{
    FUN_005a8c90();
    ((FUN_005a8ea0_shell*)this)->FUN_005a8ea0();
    if (pScript)
        pData = CopyVariableList(pScript);
    if (pAlloc)
    {
        void* tmp = pAlloc;
        _Deallocate(tmp);
    }
    pAlloc = 0;
}
}  // namespace fnv_005aa090

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
bool FUN_00401500();
void AppendChunk(unsigned int, char*, unsigned int);
struct FUN_005abd90 : TESForm
{
    void Save();
};
// @fnv 0x005abd90
void FUN_005abd90::Save()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    TESForm::ClearData();
    if (FUN_00401500())
        reinterpret_cast<ScriptHeaderData*>(reinterpret_cast<char*>(this) + 0x18)->Endian();
    AppendChunk(0x52484353, reinterpret_cast<char*>(this) + 0x18, 0x14);
    if (FUN_00401500())
        reinterpret_cast<ScriptHeaderData*>(reinterpret_cast<char*>(this) + 0x18)->Endian();
    reinterpret_cast<FUN_00485680*>(this)->M();
}

namespace fnv_005ac6a0 {
int __cdecl FUN_00404dc0(const char*, const char*);
struct Flt
{
    operator unsigned int() const;
};
struct FUN_005ac6a0 : Script
{
    char Method_005ac6a0(const char* name, unsigned int* id);
};
// @fnv 0x005ac6a0
char FUN_005ac6a0::Method_005ac6a0(const char* pcName, unsigned int* puiID)
{
    BSSimpleList<ScriptVariableInfo*>* node = GetVariableList();
    while (node && node->GetItem())
    {
        ScriptVariableInfo* variable = node->GetItem();
        node = node->GetNext();
        if (FUN_00404dc0((const char*)(unsigned int)*(Flt*)((char*)variable + 0x18), pcName) == 0)
        {
            *puiID = variable->data.uiID;
            if (variable->data.m_bIsString)
                return 's';
            else
                return 'f';
        }
    }
    *puiID = 0;
    return 0;
}
}  // namespace fnv_005ac6a0

namespace fnv_005aa500 {
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};

struct ContNode
{
    void FUN_00905330(void*);
};

struct G2 : public ContNode
{
    void AddHead(int*);
};

struct GlobalObject2_0096a2d0 : public G2
{
};

extern ATM g_011cacf8;
extern G2 g_011caca8;
extern G2 g_011cac98;
extern GlobalObject2_0096a2d0 g_011cace8;

bool __cdecl FUN_005aa630(int);
bool __cdecl FUN_005aa6d0(int);

// @fnv 0x005aa500
void __cdecl FUN_005aa500(int aiTask, unsigned char abAlternate)
{
    g_011cacf8.QueryPerformanceCounter(0);

    if (aiTask != 0)
    {
        g_011caca8.FUN_00905330(&aiTask);

        if (abAlternate == 0)
        {
            if (!FUN_005aa630(aiTask))
                g_011cac98.AddHead(&aiTask);
        }
        else
        {
            if (!FUN_005aa6d0(aiTask))
                g_011cace8.AddHead(&aiTask);
        }
    }

    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aa500

namespace fnv_005aaaf0 {
struct G2;

struct List_009e03e0
{
    void RemoveAll();
};

struct G2 : public List_009e03e0
{
    void AddHead(int* value);
};

struct GlobalObject2_0096a2d0 : public G2
{
};

class ATM
{
  public:
    void QueryPerformanceCounter(int value);
    void WaitForTasksDuringRendering();
};

class BGSLoadFormBuffer
{
  public:
    int ReadElementCount();
    unsigned int ReadFormIdentifier();
};

struct ExpandedTESObjectREFR : public TESObjectREFR
{
    unsigned char padding[0x50];

    __forceinline ExpandedTESObjectREFR() : TESObjectREFR()
    {}
};

TESForm* _GetFormByNumericID(unsigned int formID);

G2 g_011cac98;
G2 g_011caca8;
GlobalObject2_0096a2d0 g_011cacb8;
GlobalObject2_0096a2d0 g_011cace8;
ATM g_011cacf8;

// @fnv 0x005aaaf0
void __cdecl LoadReferenceLists(BGSLoadFormBuffer* buffer)
{
    g_011cacf8.QueryPerformanceCounter(0);
    g_011caca8.RemoveAll();
    g_011cac98.RemoveAll();
    g_011cacb8.RemoveAll();
    g_011cace8.RemoveAll();

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011caca8.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011cac98.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011cacb8.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011cace8.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aaaf0

struct CStringArgument
{
    const char* input;
};

struct S7010
{
    unsigned int Length();
};

struct GO
{
    operator unsigned int() const;
};

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
};

void* __cdecl __memcpy(void* destination, void* source, unsigned int size);

struct ScriptInitOwner : public Script
{
    bool IsDifferentFromCompileData(CStringArgument* apCompileData);
    void InitFromCompileData(CStringArgument* apCompileData);
};

// @fnv 0x005aaf20
void ScriptInitOwner::InitFromCompileData(CStringArgument* apCompileData)
{
    this->InitItem();

    if (((S7010*)((char*)apCompileData + 0x0C))->Length() == 0)
    {
        this->MarkForDeletion(true);
    }
    else if (this->IsDifferentFromCompileData(apCompileData))
    {
        this->SetEditorID_AtRuntime((const char*)(((GO*)((char*)apCompileData + 0x0C))->operator unsigned int()));

        __memcpy((char*)this + 0x18, (char*)apCompileData + 0x28, 0x14);

        this->SetScriptData(*(unsigned int*)((char*)this + 0x20), *(char**)((char*)apCompileData + 0x20));

        this->InitializeActionList();
        this->FUN_005aa2e0();

        if (*(unsigned int*)((char*)this + 0x20) != 0)
        {
            Script::CopyScriptReferences(
                (BSSimpleList<ScriptReferencedObject*>*)((TESObjectREFR*)apCompileData)->GetExtraData(),
                (BSSimpleList<ScriptReferencedObject*>*)((TESObjectREFR*)this)->GetExtraData(), (Script*)this);

            Script::CopyListToView(
                (BSSimpleList<ScriptVariableInfo*>*)(unsigned char*)((TESFaction_RankDataView*)apCompileData)
                    ->GetRankDataList(),
                this->GetVariableList(), (Script*)this);
        }

        this->MarkForDeletion(false);
        this->SetAltered(true);
    }
}

struct FUN_005ac340_t
{
    void RunScriptOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals);
};

// Runs the script on the target reference with the given effect locals via the script runner singleton.
// @fnv 0x005ac340
void FUN_005ac340_t::RunScriptOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptExecutor::Instance()->Run((Script*)this, apTargetRef, apEffectLocals, 0, 0, 1, 0, 0.0f);
}

struct FUN_005ac380
{
    void ExecuteEffectOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals);
};

// @fnv 0x005ac380
void FUN_005ac380::ExecuteEffectOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptExecutor::Instance()->Run((Script*)this, apTargetRef, apEffectLocals, 0, 0, 0, 1, 0.0f);
}

enum COMPILER_NAME
{
    COMPILER_NAME_DEFAULT = 0,
    COMPILER_NAME_SCRIPT = 1
};

class ScriptCompiler
{
  public:
    bool FUN_005aedb0(Script* script, TESObjectREFR* ownerObject, COMPILER_NAME compilerIndex, bool flag);
};

class AutoMemHelper
{
  public:
    AutoMemHelper(int size, bool flag, const char* fileName, int line);
    ~AutoMemHelper();

  private:
    void* m_pBuffer;
};

extern int __tls_index;
__declspec(thread) unsigned char FUN_005ac400_tls[0x269];

struct ScriptCompileAndRun
{
    void FUN_005ac400(ScriptCompiler* compiler, COMPILER_NAME compilerIndex, TESObjectREFR* ownerObject);
};

// Compiles the script with the given compiler index and owner object, and if compilation succeeds and the script has data, runs it with the owner's locals.
// @fnv 0x005ac400
void ScriptCompileAndRun::FUN_005ac400(ScriptCompiler* compiler, COMPILER_NAME compilerIndex,
                                       TESObjectREFR* ownerObject)
{
    AutoMemHelper tempMemContext(0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                                 0xd53);

    if (compiler->FUN_005aedb0((Script*)this, ownerObject, compilerIndex, false) &&
        ((Script*)this)->m_kHeader.dataSize != 0)
    {
        if (compilerIndex == 1)
            FUN_005ac400_tls[0x268] = 1;

        ScriptLocals* ownerVars = 0;
        if (ownerObject != 0)
            ownerVars = ownerObject->GetReferenceLocals();

        ((Script*)this)->Run(ownerObject, ownerVars, 0, true);

        FUN_005ac400_tls[0x268] = 0;
    }
}

struct FUN_005a9480_ItemRef
{
    unsigned int pad0;
    unsigned int pad4;
    unsigned int pad8;
    unsigned int formID;
};

void* __fastcall FUN_005d43c0(void* pThis);
int* __fastcall FUN_006815c0(void* pThis);
void* __fastcall FUN_00726070(void* pThis);

struct FUN_005a9480_holder
{
    void* pHead;
    bool FUN_005a9480(unsigned int formID);
};

// Walks the linked list from pHead and returns true if any node's item has a formID matching formID.
// @fnv 0x005a9480
bool FUN_005a9480_holder::FUN_005a9480(unsigned int formID)
{
    if (pHead == 0)
    {
        return false;
    }
    void* node = FUN_005d43c0(pHead);
    while (node != 0 && *FUN_006815c0(node) != 0)
    {
        FUN_005a9480_ItemRef* item = (FUN_005a9480_ItemRef*)*FUN_006815c0(node);
        if (item->formID == formID)
        {
            return true;
        }
        node = FUN_00726070(node);
    }
    return false;
}

struct ScriptVariableValue
{
    unsigned int id;
    unsigned int unknown04;
    double value;
    bool isInteger;
};
struct ScriptLocalList
{
    ScriptVariableValue** FUN_006815c0();
    ScriptLocalList* FUN_00726070();
};
struct GlobalGameState
{
    bool FUN_00862110();
    void* FUN_004fd3e0();
};
struct FlagManager
{
    unsigned char* FUN_00408d60();
};
struct MessageProducer
{
    void* unk00;
};
struct Formatter
{
    unsigned int getItem(int item, unsigned int line, const char* text)
    {
        typedef unsigned int(__thiscall * Callback)(Formatter*, int, unsigned int, const char*);
        Callback fn = *(Callback*)(*(char**)this + 0x130);
        return fn(this, item, line, text);
    }
};
extern GlobalGameState* DAT_011de45c;
extern FlagManager DAT_011de4e8;
extern const char DAT_01036d58;
extern const char DAT_01012cb0;
extern const char DAT_01012c78;
extern Formatter* __cdecl FUN_004839c0(void* item);
extern void __cdecl FUN_0040fbe0(const char* message, ...);
struct ScriptLocalsExt : ScriptLocals
{
    bool FUN_005a9480(unsigned int id);
};
// @fnv 0x005a94f0
unsigned short __fastcall GetScriptLocalsSerializedSize(ScriptLocals* pLocals)
{
    unsigned short bytes = 0;
    unsigned short original = bytes;
    if (DAT_011de45c->FUN_00862110())
    {
        bytes += 4;
        bytes += 2;
    }
    bytes += 2;
    ScriptLocalList* entry = (ScriptLocalList*)pLocals->m_pVariableList;
    while (entry)
    {
        ScriptVariableValue* value = *entry->FUN_006815c0();
        if (value && value->value != 0.0)
        {
            if (((ScriptLocalsExt*)pLocals)->FUN_005a9480(value->id))
                bytes += 8;
            else
                bytes += 12;
        }
        entry = entry->FUN_00726070();
    }
    bytes += 1;
    if (pLocals->m_pExtendedLocals)
        bytes += 8;
    if (*DAT_011de4e8.FUN_00408d60())
    {
        void* info = DAT_011de45c->FUN_004fd3e0();
        if (info)
        {
            Formatter* formatter = FUN_004839c0(*(void**)info);
            FUN_0040fbe0(&DAT_01012cb0, (unsigned int)bytes - (unsigned int)original, *(void**)info,
                         ((TESForm*)formatter)->GetName(), *(int*)((char*)info + 5), 638, &DAT_01036d58);
        }
        else
        {
            FUN_0040fbe0(&DAT_01012c78, (unsigned int)bytes - (unsigned int)original, 638, &DAT_01036d58);
        }
    }
    return bytes;
}

void* __fastcall CopyVariableList(Script*);

struct FUN_005a9d00_shell : public ScriptLocals
{
    void FUN_005a8c90();
    void FUN_005a8ea0();
    void FUN_005a9d00();
};

// @fnv 0x005a9d00
void FUN_005a9d00_shell::FUN_005a9d00()
{
    FUN_005a8c90();
    FUN_005a8ea0();
    if (m_pOwnerScript)
        m_pVariableList = (BSSimpleList<ScriptLocalVariable*>*)CopyVariableList(m_pOwnerScript);
    if (m_pExtendedLocals)
        delete (void*)m_pExtendedLocals;
    m_pExtendedLocals = 0;
}

class BGSSaveFormBuffer
{
  public:
    unsigned int FUN_00865f20();
    void FUN_00865e50(void* data, unsigned int size, int flag);
    void FUN_00865db0(unsigned int value, unsigned int flag);
    void FUN_00865ff0(int count, unsigned int offset);
};

void __cdecl FUN_005acc90(unsigned int* aiID, const double* adVal);

struct SaveLocals9db0 : public ScriptLocals
{
    bool FUN_005a9480(unsigned int id);
    char HasActionFlag(int a, int b);
    void FUN_005a9db0(BGSSaveFormBuffer* buffer);
};

// @fnv 0x005a9db0
void SaveLocals9db0::FUN_005a9db0(BGSSaveFormBuffer* buffer)
{
    int count3 = 0;
    unsigned int offset = buffer->FUN_00865f20();
    BSSimpleList<ScriptLocalVariable*>* node3 = m_pVariableList;
    while (node3)
    {
        ScriptLocalVariable* local_ = node3->GetItem();
        if (local_ && local_->fValue != 0.0)
        {
            if (FUN_005a9480(local_->uiID))
            {
                unsigned int value7 = 0;
                FUN_005acc90(&value7, &local_->fValue);
                unsigned int id3 = local_->uiID | 0x80000000;
                buffer->FUN_00865e50(&id3, 4, 0);
                buffer->FUN_00865db0(value7, 0);
            }
            else
            {
                buffer->FUN_00865e50(local_, 4, 0);
                buffer->FUN_00865e50(&local_->fValue, 8, 0);
            }
            count3++;
        }
        node3 = node3->GetNext();
    }
    buffer->FUN_00865ff0(count3, offset);
    unsigned char hasEffect = m_pExtendedLocals != 0;
    buffer->FUN_00865e50(&hasEffect, 1, 0);
    if (hasEffect)
    {
        buffer->FUN_00865e50(m_pExtendedLocals, 8, 0);
    }
    char result2 = HasActionFlag(0, 0x1000);
    buffer->FUN_00865e50(&result2, 1, 0);
}

extern unsigned char DAT_011ad7b4;
extern double DAT_01012060;

class FUN_005aa8c0_cls
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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    float m_fB8;
    bool HasFlag8000();
    bool FUN_005aa8c0();
};

// Returns true if HasFlag8000() is true, DAT_011ad7b4 is zero, or m_fB8 exceeds DAT_01012060.
// @fnv 0x005aa8c0
bool FUN_005aa8c0_cls::FUN_005aa8c0()
{
    return (HasFlag8000() || DAT_011ad7b4 == 0 || m_fB8 > DAT_01012060) ? 1 : 0;
}

int __cdecl StrICmp(const char*, const char*);

struct ScrVarStub
{
    bool IsDifferent(ScrVarStub* other);
};

struct RefObjStub
{
    int unk00;
    int unk04;
    TESForm* form;
};

struct VarListStub
{
    ScrVarStub** Item();
    VarListStub* Next();
    int Count();
};

struct RefListStub
{
    RefObjStub** Item();
    RefListStub* Next();
    int Count();
};

struct NameStr
{
    int unk00;
    int unk04;
    unsigned int Length();
    operator const char*() const;
};

struct CompileDataStub
{
    int unk00;
    int unk04;
    int unk08;
    NameStr name;
    int unk14;
    int unk18;
    int unk1C;
    char* data;
    int unk24;
    ScriptHeaderData header;
    VarListStub* GetVars();
    RefListStub* GetRefs();
};

struct ScriptCmpOwner : public Script
{
    int HasName();
    VarListStub* GetVarList();
    RefListStub* GetRefList();
    bool IsDifferentFromCompileData(CompileDataStub* apData);
};

// @fnv 0x005ab040
bool ScriptCmpOwner::IsDifferentFromCompileData(CompileDataStub* apData)
{
    unsigned int i8;
    ScriptHeaderData* headerTmp;
    char* dataB;
    VarListStub* newVars;
    VarListStub* oldVars;
    ScrVarStub* newVar4;
    ScrVarStub* oldVar4;
    RefListStub* newRefs3;
    RefListStub* oldRefs4;
    RefObjStub* newRef;
    RefObjStub* oldRef;

    if (HasName() && apData->name.Length())
    {
        if (StrICmp(GetName(), apData->name))
            return true;
    }

    headerTmp = &apData->header;
    if (m_kHeader.dataSize != headerTmp->dataSize)
        return true;
    if (m_kHeader.m_uiReferenceID != headerTmp->m_uiReferenceID)
        return true;

    dataB = apData->data;
    for (i8 = 0; i8 < m_kHeader.dataSize; i8++)
    {
        if (m_data[i8] != dataB[i8])
            return true;
    }

    newVars = apData->GetVars();
    oldVars = GetVarList();
    if (newVars->Count() != oldVars->Count())
        return true;
    while (newVars && oldVars)
    {
        oldVar4 = *oldVars->Item();
        newVar4 = *newVars->Item();
        if (newVar4 && oldVar4 && newVar4->IsDifferent(oldVar4))
            return true;
        newVars = newVars->Next();
        oldVars = oldVars->Next();
    }

    newRefs3 = apData->GetRefs();
    oldRefs4 = GetRefList();
    if (newRefs3->Count() != oldRefs4->Count())
        return true;
    while (newRefs3 && oldRefs4)
    {
        oldRef = *oldRefs4->Item();
        newRef = *newRefs3->Item();
        if (newRef && oldRef && newRef->form != oldRef->form)
            return true;
        newRefs3 = newRefs3->Next();
        oldRefs4 = oldRefs4->Next();
    }
    return false;
}

struct FUN_005a8c00_cls
{
    int unk00;
    int unk04;
    void* m_08;
};

struct FUN_005a8c00_list
{
    void _ref_0063f7b0();
    int _ref_004702f0(int flag);
};

// @fnv 0x005a8c00
void __fastcall FUN_005a8c00(void* pThis)
{
    unsigned int v;
    void* arg;
    void* t;
    void* l;
    if (((FUN_005a8c00_cls*)pThis)->m_08 != 0)
    {
        while (*_ref_006815c0(((FUN_005a8c00_cls*)pThis)->m_08) != 0)
        {
            v = *(unsigned int*)_ref_006815c0(((FUN_005a8c00_cls*)pThis)->m_08);
            ((FUN_005a8c00_list*)((FUN_005a8c00_cls*)pThis)->m_08)->_ref_0063f7b0();
            arg = (void*)v;
            Deallocate(arg);
        }
        t = ((FUN_005a8c00_cls*)pThis)->m_08;
        l = t;
        l != 0 ? ((FUN_005a8c00_list*)l)->_ref_004702f0(1) : 0;
        ((FUN_005a8c00_cls*)pThis)->m_08 = 0;
    }
}

struct StateX
{
    char* FUN_00825c00();
    void FUN_008579b0(const void* p, unsigned int n);
    void FUN_00857a10(const void* p, unsigned int n);
};
void __cdecl FUN_005b5e40(const char* pFmt, const char* file, int line);

struct ThisX
{
    int m_00;
    int m_04;
    int m_08;
    ScriptLocalList* m_0c;
    void* m_10;
    bool FUN_005a9480(unsigned int id);
    void WriteScriptLocals();
};

// Serializes the script local variable list to the save stream, writing a BLOCK chunk header, count, tagged values and an optional tail, with debug logging.
// @fnv 0x005a9670
void ThisX::WriteScriptLocals()
{
    char* posTmp;
    char* endPos;
    Formatter* pFmt;
    char* curPos;
    void* formPtr;
    unsigned int converted;
    unsigned int tagged;
    ScriptVariableValue* pCur;
    unsigned int chunkTag;
    unsigned short written;
    ScriptLocalList* pList;
    char* fromPos;
    unsigned short numHdr;
    char* posNum;
    bool hasTail;
    char* posB;
    numHdr = 0;
    posB = 0;
    fromPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
        fromPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
    if (DAT_011de45c->FUN_00862110())
    {
        chunkTag = 0x424c4f4b;
        ((StateX*)DAT_011de45c)->FUN_008579b0(&chunkTag, 4);
        posB = ((StateX*)DAT_011de45c)->FUN_00825c00();
        ((StateX*)DAT_011de45c)->FUN_008579b0(&numHdr, 2);
    }
    written = 0;
    posNum = ((StateX*)DAT_011de45c)->FUN_00825c00();
    ((StateX*)DAT_011de45c)->FUN_008579b0(&written, 2);
    pList = m_0c;
    while (pList)
    {
        pCur = *pList->FUN_006815c0();
        if (pCur && pCur->value != 0.0)
        {
            if (FUN_005a9480(pCur->id))
            {
                converted = 0;
                FUN_005acc90(&converted, &pCur->value);
                tagged = pCur->id | 0x80000000;
                ((StateX*)DAT_011de45c)->FUN_008579b0(&tagged, 4);
                ((StateX*)DAT_011de45c)->FUN_00857a10(&converted, 4);
            }
            else
            {
                ((StateX*)DAT_011de45c)->FUN_008579b0(pCur, 4);
                ((StateX*)DAT_011de45c)->FUN_008579b0(&pCur->value, 8);
            }
            written++;
        }
        pList = pList->FUN_00726070();
    }
    *(unsigned short*)posNum = written;
    hasTail = false;
    if (m_10)
        hasTail = true;
    ((StateX*)DAT_011de45c)->FUN_008579b0(&hasTail, 1);
    if (hasTail)
        ((StateX*)DAT_011de45c)->FUN_008579b0(m_10, 8);
    if (*DAT_011de4e8.FUN_00408d60())
    {
        curPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
        formPtr = DAT_011de45c->FUN_004fd3e0();
        if (formPtr)
        {
            pFmt = FUN_004839c0(*(void**)formPtr);
            typedef unsigned int(__thiscall * GetItemFn)(Formatter*);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         curPos - fromPos, *(int*)formPtr, (*(GetItemFn*)(*(char**)pFmt + 0x130))(pFmt),
                         *(int*)((char*)formPtr + 5), 694,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", curPos - fromPos, 694,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp");
        }
    }
    if (DAT_011de45c->FUN_00862110())
    {
        endPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
        posTmp = posB;
        if (endPos > posTmp + 0xffff)
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 694);
        *(unsigned short*)posB = (unsigned short)(endPos - posTmp);
    }
}

class BGSSaveFormBuffer_Write : public BGSSaveFormBuffer
{

  public:
    void FUN_00865df0(TESObjectREFR* reference, unsigned int flag);
};

// Writes each of four global TESObjectREFR lists to the save buffer, counting non-null entries and patching each count at its recorded offset.
// @fnv 0x005aa930
void __cdecl WriteReferenceLists(BGSSaveFormBuffer* buffer)

{

    int count1;

    unsigned int offset1;

    BSSimpleList<TESObjectREFR*>* list1;

    {

        TESObjectREFR* item9;

        int count2;

        unsigned int offset6;

        BSSimpleList<TESObjectREFR*>* listVal;

        TESObjectREFR* aItem2;

        int count7;

        unsigned int offsetVal;

        BSSimpleList<TESObjectREFR*>* list9;

        TESObjectREFR* item8;

        int count9;

        {

            unsigned int offset4;

            BSSimpleList<TESObjectREFR*>* list4;

            TESObjectREFR* item6;

            DAT_011cacf8.FUN_004538a0(0);

            count1 = 0;

            offset1 = buffer->FUN_00865f20();

            list1 = &DAT_011caca8;

            while (list1 != 0)
            {

                item9 = (TESObjectREFR*)*FUN_006815c0(list1);

                if (item9 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(item9, 0);

                    count1 = count1 + 1;
                }

                list1 = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(list1);
            }

            buffer->FUN_00865ff0(count1, offset1);

            count2 = 0;

            offset6 = buffer->FUN_00865f20();

            listVal = &DAT_011cac98;

            while (listVal != 0)
            {

                aItem2 = (TESObjectREFR*)*FUN_006815c0(listVal);

                if (aItem2 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(aItem2, 0);

                    count2 = count2 + 1;
                }

                listVal = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(listVal);
            }

            buffer->FUN_00865ff0(count2, offset6);

            count7 = 0;

            offsetVal = buffer->FUN_00865f20();

            list9 = &DAT_011cacb8;

            while (list9 != 0)
            {

                item8 = (TESObjectREFR*)*FUN_006815c0(list9);

                if (item8 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(item8, 0);

                    count7 = count7 + 1;
                }

                list9 = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(list9);
            }

            buffer->FUN_00865ff0(count7, offsetVal);

            count9 = 0;

            offset4 = buffer->FUN_00865f20();

            list4 = &DAT_011cace8;

            while (list4 != 0)
            {

                item6 = (TESObjectREFR*)*FUN_006815c0(list4);

                if (item6 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(item6, 0);

                    count9 = count9 + 1;
                }

                list4 = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(list4);
            }

            buffer->FUN_00865ff0(count9, offset4);
        }
    }

    DAT_011cacf8.FUN_004538c0();
}

int _mbscmp(const unsigned char* a, const unsigned char* b);
unsigned int __cdecl strlen(const char*);

struct ScriptCompareOwner : public Script
{
    bool IsDifferentFrom(Script* apOther);
};

// @fnv 0x005ab240
bool ScriptCompareOwner::IsDifferentFrom(Script* apOther)
{
    unsigned int i8;
    BSSimpleList<ScriptReferencedObject*>* pOtherIter7;
    ScriptHeaderData* pHeader;
    char* pData6;
    BSSimpleList<ScriptReferencedObject*>* kPIter;
    ScriptReferencedObject* pOtherRef8;
    ScriptReferencedObject* pRef;
    if (!apOther)
        return true;
    pHeader = apOther->GetHeader();
    if (m_kHeader.dataSize != pHeader->dataSize)
        return true;
    if (m_kHeader.m_uiReferenceID != pHeader->m_uiReferenceID)
        return true;
    if (m_kHeader.m_bCompiled != pHeader->m_bCompiled)
        return true;
    pData6 = apOther->GetData();
    for (i8 = 0; i8 < m_kHeader.dataSize; i8++)
    {
        if (m_data[i8] != pData6[i8])
            return true;
    }
    if (GetText() && apOther->GetText())
    {
        if (strlen(GetText()) != strlen(apOther->GetText()))
            return true;
        else if (_mbscmp((const unsigned char*)GetText(), (const unsigned char*)apOther->GetText()))
            return true;
    }
    else if (GetText() || apOther->GetText())
        return true;
    pOtherIter7 = apOther->GetReferencedObjectList();
    kPIter = GetReferencedObjectList();
    while (pOtherIter7 && kPIter)
    {
        pRef = kPIter->GetItem();
        pOtherRef8 = pOtherIter7->GetItem();
        if (pOtherRef8 && pRef && pOtherRef8->pForm != pRef->pForm)
            return true;
        pOtherIter7 = pOtherIter7->GetNext();
        kPIter = kPIter->GetNext();
    }
    return false;
}

struct FUN_00501c10_s
{
    void* CallAndReturnSelf(const void* src);
};

namespace ns5a {
struct FUN_005ab8b0
{
    BSStringT<char> name;
    int unk;
    int unk0C;
    FUN_005ab8b0(const FUN_005ab8b0& src);
};
}

// @fnv 0x005ab8b0
ns5a::FUN_005ab8b0::FUN_005ab8b0(const FUN_005ab8b0& src)
{
    ((FUN_00501c10_s*)this)->CallAndReturnSelf(&src);
    unk = src.unk;
    unk0C = src.unk0C;
}

struct ScriptResolve : Script
{
    ScriptReferencedObject* GetNthRefByIndex(int, ScriptLocals*);
};
struct RefRead : TESObjectREFR
{
    ExtraDataList* FUN_005d43c0();
    ScriptLocals* FUN_005673e0();
};
struct ExtraRead : ExtraDataList
{
    TESObjectREFR* FUN_0041c8d0();
};
struct InventoryRead : TESObjectREFR
{
    InventoryStackRecord* FUN_00576260(TESBoundObject*, unsigned int);
};
void FUN_005acc70(const unsigned int*, double*);
ScriptFunctionInfo* FUN_005b1120(int);
void FUN_005accb0(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                  ScriptLocals*);
void FUN_00401460(void*, const void*, unsigned int);
// @fnv 0x005ac7a0
bool ReadScriptValue(double* value, const char* data, unsigned int* offset, TESObjectREFR* reference,
                     TESObjectREFR* container, Script* script, ScriptLocals* locals, bool skip)
{
    ScriptLocals* a;
    ScriptReferencedObject* p;
    char h;
    short i;
    TESQuest* s;
    RefRead* f;
    TESObjectREFR* eb;
    InventoryStackRecord* cf;
    ScriptFunctionInfo* q;
    int b;
    RefRead* ba;
    ScriptParameter* k;
    FNVScriptExecuteFunction l;
    short c;
    unsigned int e;
    a = locals;
    if (!a)
        return false;
    p = 0;
    if (skip && script->IsFormInitialized())
        skip = false;
    h = data[*offset];
    *offset += 1;
    switch (h)
    {
    case 'G':
    case 'Z':
    case 'r': {
        i = *(short*)(data + *offset);
        *offset += 2;
        p = ((ScriptResolve*)script)->GetNthRefByIndex(i, locals);
        if (p)
        {
            if (p->pForm || skip)
            {
                if (h == 'G')
                {
                    *value = ((TESGlobalValueReader*)p->pForm)->GetValue();
                    return true;
                }
                else if (h == 'Z')
                {
                    e = p->pForm->GetFormID();
                    FUN_005acc70(&e, value);
                    return true;
                }
                else
                {
                    h = data[*offset];
                    *offset += 1;
                    if (h != 'X')
                    {
                        s = 0;
                        if (p->pForm && p->pForm->GetFormType() == 0x47)
                            s = (TESQuest*)p->pForm;
                        if (s)
                            a = s->GetScriptLocalData();
                        else
                        {
                            f = 0;
                            if (p->pForm)
                            {
                                switch (p->pForm->GetFormType())
                                {
                                case 0x3a:
                                case 0x3b:
                                case 0x3c:
                                case 0x3d:
                                case 0x3e:
                                case 0x3f:
                                case 0x40:
                                case 0x69:
                                    f = (RefRead*)p->pForm;
                                    break;
                                }
                            }
                            if (f)
                            {
                                if (((ExtraRead*)f->FUN_005d43c0())->FUN_0041c8d0())
                                {
                                    eb = ((ExtraRead*)f->FUN_005d43c0())->FUN_0041c8d0();
                                    cf = ((InventoryRead*)eb)->FUN_00576260(f->GetObjectReference(), f->GetFormID());
                                    if (cf)
                                        a = cf->GetScriptLocalData();
                                    delete cf;
                                }
                                else
                                    a = f->FUN_005673e0();
                            }
                        }
                        if (!a)
                            return false;
                    }
                }
            }
            else
            {
                if (p->m_uiFormID)
                {
                    *value = 0.0;
                    return true;
                }
                else
                    return false;
            }
        }
        else
            return false;
        break;
    }
    case 'n':
        *value = *(int*)(data + *offset);
        *offset += 4;
        return true;
    case 'z':
        FUN_00401460(value, data + *offset, 8);
        *offset += 8;
        return true;
    }
    if (h == 'X')
    {
        b = *(short*)(data + *offset);
        *offset += 2;
        *offset += 2;
        q = FUN_005b1120(b);
        if (!q)
            return false;
        else
        {
            ba = (RefRead*)reference;
            if (p && p->pForm)
            {
                ba = 0;
                if (p->pForm)
                {
                    switch (p->pForm->GetFormType())
                    {
                    case 0x3a:
                    case 0x3b:
                    case 0x3c:
                    case 0x3d:
                    case 0x3e:
                    case 0x3f:
                    case 0x40:
                    case 0x69:
                        ba = (RefRead*)p->pForm;
                        break;
                    }
                }
            }
            k = q->pParameters;
            if (skip)
            {
                if (k)
                    FUN_005accb0(k, data, offset, ba, container, script, locals);
            }
            else
            {
                if (!q->m_bRequiresReference || (q->m_bRequiresReference && ba))
                {
                    l = q->m_pfnExecute;
                    if (l && l(k, data, ba, container, script, locals, *value, *offset))
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    else
    {
        c = *(short*)(data + *offset);
        *offset += 2;
        switch (h)
        {
        case 'f':
        case 'l':
        case 's':
            *value = a->GetVariable(c, script);
            return true;
        default:
            return false;
        }
    }
    return false;
}

struct ExtractParameter
{
    const char* name;
    unsigned int type;
    bool optional;
};
struct ExtractScript
{
    ScriptReferencedObject* GetNthRefByIndex(int, ScriptLocals*);
    bool FUN_004013e0();
};
struct ExtractForm
{
    virtual void slot00();
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
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual bool IsReference();
    int FUN_00401170();
};
bool FUN_00481f30(int);
extern const char extractUnimplemented[];
bool ReadScriptValue(double*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, ExtractScript*, ScriptLocals*,
                     bool);
// @fnv 0x005accb0
bool __cdecl FUN_005accb0(const ExtractParameter* parameters, const char* data, unsigned int* offset,
                          TESObjectREFR* reference, TESObjectREFR* container, ExtractScript* script,
                          ScriptLocals* locals, ...)
{
    if (!parameters)
        return false;
    va_list args2;
    va_start(args2, locals);
    short count = *reinterpret_cast<const short*>(data + *offset);
    *offset += 2;
    short index;
    for (index = 0; index < count; ++index)
    {
        if (DAT_0118cdd0[parameters[index].type].isReference)
        {
            if (data[(*offset)++] != 'r')
                return false;
            short refIndex3 = *reinterpret_cast<const short*>(data + *offset);
            *offset += 2;
            ScriptReferencedObject* ref = script->GetNthRefByIndex(refIndex3, locals);
            if (script->FUN_004013e0() && ref && ref->pForm)
            {
                bool valid = false;
                switch (parameters[index].type)
                {
                case 3: {
                    if (FUN_00481f30(reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170()))
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = 0;
                        if (ref->pForm && reinterpret_cast<ExtractForm*>(ref->pForm)->IsReference())
                            *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 50: {
                    if (FUN_00481f30(reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170()) ||
                        reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 53: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm && (reinterpret_cast<ExtractForm*>(ref->pForm)->IsReference() ||
                                       reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85))
                        *formOutput = ref->pForm;
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 4:
                case 24:
                case 26: {
                    switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                    {
                    case 58:
                    case 59:
                    case 60:
                    case 61:
                    case 62:
                    case 63:
                    case 64:
                    case 105: {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = 0;
                        if (ref->pForm)
                        {
                            switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                            {
                            case 58:
                            case 59:
                            case 60:
                            case 61:
                            case 62:
                            case 63:
                            case 64:
                            case 105:
                                *formOutput = ref->pForm;
                                break;
                            }
                        }
                        if (*formOutput)
                            valid = true;
                    }
                    break;
                    }
                }
                break;
                case 6: {
                    switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                    {
                    case 59:
                    case 60: {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                    break;
                    }
                }
                break;
                case 9: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 57)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 27: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 65)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 7: {
                    SpellItem** spellOutput = va_arg(args2, SpellItem**);
                    *spellOutput = dynamic_cast<SpellItem*>(ref->pForm);
                    if (*spellOutput)
                        valid = true;
                    else
                    {
                        TESObjectBOOK* book = 0;
                        if (ref->pForm && reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 25)
                            book = reinterpret_cast<TESObjectBOOK*>(ref->pForm);
                        *spellOutput = reinterpret_cast<SpellItem*>(book);
                        if (book && book->enchantable.FindFormEnchantment())
                            valid = true;
                    }
                }
                break;
                case 11: {
                    MagicItem** formOutput = va_arg(args2, MagicItem**);
                    *formOutput = dynamic_cast<MagicItem*>(ref->pForm);
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 31: {
                    EffectSetting** formOutput = va_arg(args2, EffectSetting**);
                    *formOutput = dynamic_cast<EffectSetting*>(ref->pForm);
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 12: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 13)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 54: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 102)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 13: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 69)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 14: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 71)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 15: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 12)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 47: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 97)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 16: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 7)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 17: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 8)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 62: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 104)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 65: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 113)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 63: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 109)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 64: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 108)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 66: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 116)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 67: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 115)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 68: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 117)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 69: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 55)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 19: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 6)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 20: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 39 ||
                        reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 21: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm && reinterpret_cast<ExtractForm*>(ref->pForm)->IsReference())
                        *formOutput = ref->pForm;
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 25: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 42:
                        case 43:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 29: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 73)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 30: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 74)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 33: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 53)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 42: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 84)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 43: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 83)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 34: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 42)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 35: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 42:
                            *formOutput = ref->pForm;
                            break;
                        case 8:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 36: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 79)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 37: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 38: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 5)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 39: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 86)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 40: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 49)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 49: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 98)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 56: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 42:
                            *formOutput = ref->pForm;
                            break;
                        case 45:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 57: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 43:
                            *formOutput = ref->pForm;
                            break;
                        case 44:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 58: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 45)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 59: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 44)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 60: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 52)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 61: {
                    if (ref->pForm)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                default:
                    Warning(extractUnimplemented, parameters[index].type);
                    return false;
                }
                if (!valid)
                    return false;
            }
            else
                return false;
        }
        else
        {
            switch (parameters[index].type)
            {
            case 0: {
                short length = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->FUN_004013e0())
                {
                    char* textOutput = va_arg(args2, char*);
                    memcpy(textOutput, data + *offset, length);
                    textOutput[length] = 0;
                }
                *offset += length;
            }
            break;
            case 1:
            case 23: {
                double value = 0.0;
                if (ReadScriptValue(&value, data, offset, reference, container, script, locals, true))
                {
                    if (script->FUN_004013e0())
                    {
                        int* intOutput = va_arg(args2, int*);
                        *intOutput = (int)value;
                    }
                }
                else
                    return false;
            }
            break;
            case 2: {
                double value = 0.0;
                if (ReadScriptValue(&value, data, offset, reference, container, script, locals, true))
                {
                    if (script->FUN_004013e0())
                    {
                        float* floatOutput = va_arg(args2, float*);
                        *floatOutput = (float)value;
                    }
                }
                else
                    return false;
            }
            break;
            case 8: {
                if (script->FUN_004013e0())
                {
                    char* byteOutput = va_arg(args2, char*);
                    *byteOutput = data[*offset];
                }
                *offset += 1;
            }
            break;
            case 5:
            case 41:
            case 51:
            case 52:
            case 55: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->FUN_004013e0())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 28: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->FUN_004013e0())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 10: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->FUN_004013e0())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 32: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->FUN_004013e0())
                {
                    char* byteOutput = va_arg(args2, char*);
                    *byteOutput = (char)value;
                }
            }
            break;
            case 18: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->FUN_004013e0())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            default:
                return false;
            }
        }
    }
    va_end(args2);
    return true;
}

void __cdecl FNV_Warning(const char* fmt, ...);
extern int DAT_011cad40;
extern float DAT_011cad20[8];

struct S4eb0_flag
{
    unsigned char pad[0x10];
    bool b10;
};

struct S4eb0_list
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    ScriptReferencedObject** FUN_006815c0();
    S4eb0_list* FUN_00726070();
    void FUN_00905330(ScriptReferencedObject** p);
};

void ResolveFormID(TESForm** form, TESFile* file);
TESForm* FUN_004839c0(TESForm* form);

struct Scr : TESForm
{
    char pad18[4];
    unsigned int m_uiReferenceID;
    unsigned int dataSize;
    char pad24[0xc];
    char* m_data;
    float m_fValueAtOffset34;
    float fValueAtOffset38;
    float fQuestScriptBuffer;
    TESQuest* m_pOwnerQuest;

    bool FUN_004013e0();
    bool FUN_00483710();
    S4eb0_list* FUN_005d43c0();
    S4eb0_flag* FUN_00500940();
    void FUN_00484ab0(bool initialized);
    void FUN_005ab400(TESForm* form);
};

// @fnv 0x005ab400
void Scr::FUN_005ab400(TESForm* form)
{
    if (FUN_004013e0() || form == 0)
        return;
    AutoMemContext saveCtx((MEM_CONTEXT)21, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 0xab5);
    if (form != this && IsTemporary())
    {
        SetFile(form->GetFile(-1));
    }
    int num = 0;
    S4eb0_list* iter = FUN_005d43c0();
    S4eb0_list* pPrev = 0;
    TESFile* pTemp = form ? form->GetFile(-1) : 0;
    while (iter && !iter->FUN_008256d0())
    {
        ScriptReferencedObject* refTmp = *iter->FUN_006815c0();
        TESForm* form7 = refTmp->pForm;
        unsigned int idB = refTmp->m_uiFormID;
        bool ok3 = false;
        if (form7)
        {
            ResolveFormID(&form7, pTemp);
            refTmp->pForm = FUN_004839c0(form7);
            if (refTmp->pForm)
                ok3 = true;
        }
        else if (idB)
        {
            ok3 = true;
        }
        if (ok3)
        {
            pPrev = iter;
            iter = iter->FUN_00726070();
        }
        else
        {
            if (pPrev)
            {
                pPrev->FUN_00905330(iter->FUN_006815c0());
                iter = pPrev->FUN_00726070();
            }
            else
            {
                iter->FUN_0063f7b0();
            }
            if (form7)
            {
                FNV_Warning(
                    "MASTERFILE: Could not find referenced object (%08X) on Script (%08X) '%s'.  Script will not be executed.",
                    form7, GetFormID(), GetName());
            }
            else
            {
                FNV_Warning(
                    "MASTERFILE: Referenced object %d on Script (%08X) '%s' is invalid.  Script will not be executed.",
                    num, GetFormID(), GetName());
            }
            dataSize = 0;
        }
        num++;
    }
    if (num != m_uiReferenceID && dataSize != 0)
    {
        FNV_Warning(
            "MASTERFILE: Referenced object list on Script (%08X) '%s' is corrupt.  Expected %d objects, found %d.",
            GetFormID(), GetName(), m_uiReferenceID, num);
        dataSize = 0;
    }
    if (m_data)
        FUN_00483710();
    if (FUN_00500940()->b10)
    {
        if (DAT_011cac68.Float()->f > 0.0)
        {
            float t = DAT_011cac68.Float()->f;
            if (DAT_011cad40 == 0)
            {
                for (int j = 0; j < 8; j++)
                {
                    t = t / 2.0;
                    DAT_011cad20[j] = t;
                }
            }
            int mask3 = DAT_011cad40 & 0xff;
            int k = 0;
            if (m_pOwnerQuest != 0 && m_pOwnerQuest->FUN_00792760() > 0.0)
            {
                fValueAtOffset38 = 0.0f;
            }
            else if (mask3 == 0)
            {
                fValueAtOffset38 = DAT_011cac68.Float()->f;
            }
            else
            {
                while (mask3)
                {
                    if (mask3 & 1)
                        fValueAtOffset38 += DAT_011cad20[k];
                    k++;
                    mask3 >>= 1;
                }
            }
            DAT_011cad40++;
        }
    }
    if (form->GetFormType() == 0x47)
        m_pOwnerQuest = (TESQuest*)form;
    SetInitializationState(true);
}

extern const char DAT_01015588[];
struct SavedFormHeader
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flagsLow, flagsByte1, flagsByte2, flagsByte3;
    unsigned char version;
};
struct ScriptSaveReader : TESSaveLoadGame
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857aa0(unsigned int*, unsigned int);
    SavedFormHeader* FUN_004fd3c0();
    unsigned int FUN_00825c00();
    unsigned char FUN_008df040();
};
TESForm* __cdecl _ref_004839c0(unsigned int);
void __cdecl FUN_005acc70(const unsigned int&, double&);
struct LoadScriptLocals : ScriptLocals
{
    void FUN_005a9950();
};
// Reads script locals from the save stream, handling version 117+ reference encoding and optional extended locals, then verifies the block size.
// @fnv 0x005a9950
void LoadScriptLocals::FUN_005a9950()
{
    unsigned short a = 0;
    unsigned int i = 0;
    unsigned short s;
    unsigned char h;
    int p;
    if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int blockTag;
        ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&blockTag, 4);
        if (blockTag != 0x424c4f4b)
        {
            SavedFormHeader* header = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_004fd3c0();
            if (header)
            {
                TESForm* form = _ref_004839c0(header->formID);
                Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    &DAT_01036d58, 700, header->formID, form->GetName(), header->version,
                    *(unsigned int*)&header->flagsLow);
            }
            else
            {
                Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    &DAT_01036d58, 700, ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040());
            }
        }
        i = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00825c00();
        ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&a, 2);
    }
    ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&s, 2);
    for (p = 0; p < s; p++)
    {
        unsigned int i = 0;
        double p = 0.0;
        if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040() >= 117)
        {
            ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&i, 4);
            if (i & 0x80000000)
            {
                i &= 0x7fffffff;
                unsigned int refID;
                ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00857aa0(&refID, 4);
                FUN_005acc70(refID, p);
            }
            else
            {
                ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&p, 8);
            }
        }
        if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040() < 117)
        {
            ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&i, 4);
            ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&p, 8);
        }
        SetVariable(i, p);
    }
    ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&h, 1);
    if (h)
    {
        m_pExtendedLocals = (ScriptDefinition*)new double;
        ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(m_pExtendedLocals, 8);
    }
    if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int s = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00825c00();
        SavedFormHeader* h = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_004fd3c0();
        if (h)
        {
            TESForm* form = _ref_004839c0(h->formID);
            if (s > i + a)
                Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    s - (i + a), &DAT_01036d58, 747, h->formID, form->GetName(), h->version,
                    *(unsigned int*)&h->flagsLow);
            else if (s < i + a)
                Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    i + a - s, &DAT_01036d58, 747, h->formID, form->GetName(), h->version,
                    *(unsigned int*)&h->flagsLow);
        }
        else
        {
            if (s > i + a)
                Warning("SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        s - (i + a), &DAT_01036d58, 747, ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040());
            else if (s < i + a)
                Warning("SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        i + a - s, &DAT_01036d58, 747, ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040());
        }
    }
}

namespace fnv_005aa350 {
struct TlsSlot
{
    char pad[0x24F0];
    void* pCached;
};

struct ItemX
{
    void* FUN_005aa3f0(unsigned int flags);
};
struct ListX
{
    bool FUN_008256d0();
    ItemX** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ClsX
{
    ListX* FUN_005d43c0();
    void FUN_005aa350();
};

extern __declspec(thread) TlsSlot DAT_0126fd98;

// Clears the TLS cached pointer if it points to this object, then iterates the list from FUN_005d43c0 and calls FUN_005aa3f0(1) on each item.
// @fnv 0x005aa350
void ClsX::FUN_005aa350()
{
    if (DAT_0126fd98.pCached == this)
        DAT_0126fd98.pCached = 0;
    ListX* pList = FUN_005d43c0();
    while (pList != 0 && !pList->FUN_008256d0())
    {
        ItemX* b = *pList->FUN_006815c0();
        ItemX* pItem = b;
        // the result is discarded but stays in an implicit temp (VM /Od slot layout)
        (void)(pItem ? pItem->FUN_005aa3f0(1) : 0);
        pList->FUN_0063f7b0();
    }
}
}  // namespace fnv_005aa350
