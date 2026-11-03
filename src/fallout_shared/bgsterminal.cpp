// fallout_shared/bgsterminal.cpp: BGSTerminal, TermHack, PlayerCharacter, TerminalCleanup and more (31 functions)

#include "bgsterminal_decls.h"

// Loads a terminal record from the file, dispatching each chunk to set the editor ID, model, script, menu items, sounds, and conditions.
// @fnv 0x00500000
bool BGSTerminal::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    TerminalMenuItem* current = 0;
    int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 'LDOM':
        case 'TDOM':
        case 'DDOM':
        case 'DSOM':
            TESModel::LoadModelData(this, file);
            break;
        case 'SDOM': {
            void* textureData;
            unsigned int textureSize = file->GetChunkSize();
            textureData = _alloca(textureSize);
            file->GetChunkData(textureData, textureSize);
            ParseTextureSwapData(textureData, textureSize, file->GetFormVersion());
            break;
        }
        case 'IRCS': {
            Script* script = 0;
            file->GetChunkData((unsigned int*)&script);
            SetScript(script);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 'CSED':
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 'DSLS':
        case 'RVCS': {
            if (file->GetChunkID() == 'DSLS')
            {
                DAT_011c83d4 = new ScriptVariableInfo;
                DAT_011c83d4->Load(file);
                current->m_kScript.GetVariableList()->AddTail(DAT_011c83d4);
            }
            else if (DAT_011c83d4)
            {
                char* variableName = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(variableName, 0x200);
                DAT_011c83d4->m_kName.Set(variableName, 0);
            }
            break;
        }
        case 'RHCS':
            file->GetChunkData(current->m_kScript.GetHeader(), 0);
            if (file->IsEndianConversionRequired())
                current->m_kScript.GetHeader()->Endian();
            break;
        case 'ADCS': {
            unsigned int size = file->GetChunkSize();
            char* data = (char*)_alloca(size);
            memset(data, 0, size);
            file->GetChunkData(data, 0);
            current->m_kScript.SetScriptData(size, data);
            break;
        }
        case 'ORCS': {
            unsigned int formID;
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            reference->form = (TESForm*)formID;
            current->m_kScript.GetReferencedObjectList()->AddTail(reference);
            break;
        }
        case 'VRCS': {
            struct
            {
                ScriptReferencedObject* reference;
                unsigned int variableID;
            } loadedVariable;
            loadedVariable.reference = new ScriptReferencedObject;
            file->GetChunkData(&loadedVariable.variableID);
            loadedVariable.reference->variableID = loadedVariable.variableID;
            current->m_kScript.GetReferencedObjectList()->AddTail(loadedVariable.reference);
            break;
        }
        case 'MANS': {
            TESSound* sound = 0;
            file->GetChunkData((unsigned int*)&sound);
            SetLoopingSound(sound);
            break;
        }
        case 'MANP': {
            BGSNote* password = 0;
            file->GetChunkData((unsigned int*)&password);
            FUN_00500a20(password);
            break;
        }
        case 'MAND':
            file->GetChunkData(&Data, 4);
            break;
        case 'TXTI': {
            char* text = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(text, 0);
            TerminalMenuItem* item = new TerminalMenuItem;
            item->ResponseText.Set(text, 0);
            AddMenuItem(item);
            current = item;
            break;
        }
        case 'MANR': {
            if (current)
            {
                char* text = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(text, 0);
                current->m_kMenuText.Set(text, 0);
            }
            break;
        }
        case 'MANI': {
            if (current)
            {
                BGSNote* note = 0;
                file->GetChunkData((unsigned int*)&note);
                current->m_pNote = note;
            }
            break;
        }
        case 'MANT': {
            if (current)
            {
                BGSTerminal* menu = 0;
                file->GetChunkData((unsigned int*)&menu);
                current->m_pTerminal = menu;
            }
            break;
        }
        case 'MANA':
            if (current)
                file->GetChunkData(&current->cFlags, 1);
            break;
        case 'ADTC':
            if (current)
                current->Conditions.Load(file);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the terminal's password and each menu item's note/submenu forms, runs their InitItem scripts and conditions, and warns on lookup or script errors.
// @fnv 0x004ffcb0
void BGSTerminal::InitItem()
{
    int count;
    if (IsFormInitialized())
        return;
    TESObjectACTI::InitItem();
    unsigned int formID = (unsigned int)pPassword;
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        pPassword = dynamic_cast<BGSNote*>(TESForm::GetFormByID(formID));
        if (!pPassword)
            Warning("MASTERFILE: Unable to find password (%08X) on terminal '%s' (%08X).", formID, GetEditorID(),
                    GetFormID());
    }
    count = 0;
    BSSimpleList<TerminalMenuItem*>* pList = FUN_00461150();
    while (pList && !pList->IsEmpty())
    {
        TerminalMenuItem* item = pList->GetItem();
        pList = pList->GetNext();
        if (item->m_pNote)
        {
            formID = (unsigned int)item->m_pNote;
            TESForm::RemapFormIDForFile(formID, GetFile(-1));
            item->m_pNote = dynamic_cast<BGSNote*>(TESForm::GetFormByID(formID));
            if (!item->m_pNote)
                Warning("MASTERFILE: Unable to find display note (%08X) for menu item %i on terminal '%s' (%08X).",
                        formID, count, GetEditorID(), GetFormID());
        }
        if (item->m_pTerminal)
        {
            formID = (unsigned int)item->m_pTerminal;
            TESForm::RemapFormIDForFile(formID, GetFile(-1));
            item->m_pTerminal = dynamic_cast<BGSTerminal*>(TESForm::GetFormByID(formID));
            if (!item->m_pTerminal)
                Warning("MASTERFILE: Unable to find submenu (%08X) for menu item %i on terminal '%s' (%08X).", formID,
                        count, GetEditorID(), GetFormID());
        }
        struct
        {
            int errors;
            int previous;
        } errors;
        errors.previous = Warning();
        SetWarningState(true);
        MessageHandler::SetWarningCount(0);
        item->m_kScript.InitItem(this);
        SetWarningState(false);
        errors.errors = Warning();
        MessageHandler::SetWarningCount(errors.previous);
        if (errors.errors)
            Warning(
                "MASTERFILE: Errors were encountered during InitItem for result script on menu item %d for terminal '%s' (%08X)\n\nSee Warnings file for more information.",
                count, GetEditorID(), GetFormID());
        errors.previous = Warning();
        SetWarningState(true);
        MessageHandler::SetWarningCount(0);
        item->Conditions.InitItem(this);
        SetWarningState(false);
        errors.errors = Warning();
        MessageHandler::SetWarningCount(errors.previous);
        if (errors.errors)
            Warning(
                "MASTERFILE: Errors were encountered during InitItem for conditions on menu item %d for terminal '%s' (%08X)\n\nSee Warnings file for more information.",
                count, GetEditorID(), GetFormID());
        ++count;
    }
    SetInitializationState(true);
}

// @fnv 0x004ffc50
void BGSTerminal::ResetFormData()
{
    TESObjectACTI::ResetFormData();
    pPassword = 0;
    memset(&Data, 0, sizeof(Data));
}

// Returns true if note is non-null and present in the notes list.
// @fnv 0x00966c10
bool PlayerCharacter::HasNote(BGSNote* note)
{
    return note && notes.IsInList(note);
}

struct BaseExtraList
{
    void RemoveExtra(unsigned char);
};

// @fnv 0x00501a10
void __cdecl FUN_00501a10(Script* apScript)
{
    if (apScript)
        reinterpret_cast<BaseExtraList*>(apScript->GetReferencedObjectList())->RemoveExtra(0x50);
}

struct TESObjectREFR
{
    TESObjectREFR* GetLinkedRef(void);
    bool FUN_00568680(void);
    bool IsReferenceActive(bool);
};

// @fnv 0x005012c0
bool __cdecl FUN_005012c0(TESObjectREFR* apRef)
{
    bool bretval = false;
    if (apRef)
    {
        TESObjectREFR* plinkedref = apRef->GetLinkedRef();
        if (plinkedref)
        {
            if (plinkedref->FUN_00568680())
            {
                if (!plinkedref->IsReferenceActive(true))
                    bretval = true;
            }
        }
    }
    return bretval;
}

struct FUN_005015d0_shell
{
    unsigned char m_a5;
    bool FUN_005015d0();
};

// @fnv 0x005015d0
bool FUN_005015d0_shell::FUN_005015d0()
{
    return ((unsigned char*)this)[0xa5] & 2;
}

struct BSSimpleList_REF
{
    void __thiscall FUN_0041bf80(int a1);
};

struct FUN_00501b40_shell
{
    bool __thiscall FUN_005015d0();
    void FUN_00501b40(Script* a1);
};

// @fnv 0x00501b40
void FUN_00501b40_shell::FUN_00501b40(Script* pScript)
{
    if (pScript)
    {
        if (FUN_005015d0())
            ((BSSimpleList_REF*)pScript->GetReferencedObjectList())->FUN_0041bf80(-1);
        else
            ((BSSimpleList_REF*)pScript->GetReferencedObjectList())->FUN_0041bf80(-2);
    }
}

struct FUN_00511860_shell
{
    void FUN_00511860(void* apSaveGameBuffer);
};

void __thiscall FUN_00511860_shell::FUN_00511860(void* apSaveGameBuffer)
{}

struct FUN_00501b90_shell : FUN_00511860_shell
{
    void FUN_00501b90(void* apSaveGameBuffer);
};

// @fnv 0x00501b90
void __thiscall FUN_00501b90_shell::FUN_00501b90(void* apSaveGameBuffer)
{
    this->FUN_00511860(apSaveGameBuffer);
}

struct FUN_00501270_shell : public TESForm
{
    int FUN_005011a0(TESObjectREFR* apRef);
    unsigned int FUN_00501270(TESObjectREFR* apRef);
};
// @fnv 0x00501270
unsigned int FUN_00501270_shell::FUN_00501270(TESObjectREFR* apRef)
{
    int ilockval;
    ilockval = FUN_005011a0(apRef);
    ilockval <<= 1;
    ilockval += GetFormID() & 1;
    ilockval += 4;
    if (ilockval > 12)
        ilockval = 12;
    return ilockval;
}

struct TermHack
{
    float __thiscall FUN_005017a0(TESObjectREFR* apItemActivated);
    bool __thiscall IsSkillSufficient(TESObjectREFR* apItemActivated, float afSkill);
};
// Returns whether the skill value returned by FUN_005017a0 for the activated reference is less than or equal to afSkill.
// @fnv 0x00501760
bool __thiscall TermHack::IsSkillSufficient(TESObjectREFR* apItemActivated, float afSkill)
{
    return FUN_005017a0(apItemActivated) <= afSkill;
}

struct Dummy0041BF50
{
    unsigned char __thiscall FUN_0041bf50();
};
// Returns true if apRef is non-null and the state byte from its referenced object list has bit 0x80 set.
// @fnv 0x00501870
bool __cdecl FUN_00501870(TESObjectREFR* apRef)
{
    bool bretval;
    unsigned char cstate;
    bretval = false;
    if (apRef)
    {
        cstate = ((Dummy0041BF50*)((Script*)apRef)->GetReferencedObjectList())->FUN_0041bf50();
        if (cstate & 0x80)
            bretval = true;
    }
    return bretval;
}

struct FUN_0041c060_Cls
{
    char __thiscall FUN_0041c060();
};
struct FUN_00501a30_shell
{
    unsigned char _pad[0xA4];
    char _mA4;
    int __thiscall FUN_00501a30(Script* apScript);
};
// @fnv 0x00501a30
int __thiscall FUN_00501a30_shell::FUN_00501a30(Script* apScript)
{
    char c = -1;
    if (apScript)
    {
        c = ((FUN_0041c060_Cls*)apScript->GetReferencedObjectList())->FUN_0041c060();
    }
    if (c < 0)
    {
        c = _mA4;
    }
    return c;
}

struct FUN_00501a80_shell : FUN_005015d0_shell
{
    void FUN_00501a80(Script* a1, int a2);
};
// @fnv 0x00501a80
void FUN_00501a80_shell::FUN_00501a80(Script* apScript, int aiValue)
{
    if (apScript)
    {
        if (aiValue == ((unsigned char*)this)[0xA4] && !FUN_005015d0())
            ((BSSimpleList_REF*)(apScript->GetReferencedObjectList()))->FUN_0041bf80(-1);
        else
            ((BSSimpleList_REF*)(apScript->GetReferencedObjectList()))->FUN_0041bf80((unsigned char)aiValue);
    }
}

struct FUN_0041c060_shell
{
    char __thiscall FUN_0041c060();
};
struct FUN_00501ae0_shell : FUN_005015d0_shell
{
    bool FUN_00501ae0(TESObjectREFR* apRef);
};
// @fnv 0x00501ae0
bool FUN_00501ae0_shell::FUN_00501ae0(TESObjectREFR* apRef)
{
    bool bunlocked;
    bunlocked = FUN_005015d0();
    if (apRef)
    {
        char clock;
        clock = ((FUN_0041c060_shell*)((Script*)apRef)->GetReferencedObjectList())->FUN_0041c060();
        if (clock == -2)
            bunlocked = true;
        else if (clock != -1)
            bunlocked = false;
    }
    return bunlocked;
}

struct FormChangeMask
{
    int m_flags;
    FormChangeMask();
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    FormChangeMask __thiscall GetChangeFlags(unsigned int);
    void __thiscall ReadTypedData(void*, unsigned int);
};
struct BaseStub501bb0
{
    void __thiscall FUN_005118c0(BGSLoadFormBuffer*);
};
struct Host501bb0 : BaseStub501bb0
{
    void __thiscall FUN_00501bb0(BGSLoadFormBuffer*);
};
// @fnv 0x00501bb0
void Host501bb0::FUN_00501bb0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ucTempData;
    FUN_005118c0(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x80000000))
    {
        if (apLoadGameBuffer->GetVersion() < 13)
        {
            apLoadGameBuffer->ReadTypedData(&ucTempData, 1);
        }
    }
}

struct FUN_00501250_shell
{
    bool __thiscall IsFlagSet();
};
// @fnv 0x00501250
bool __thiscall FUN_00501250_shell::IsFlagSet()
{
    return (*(unsigned char*)((char*)this + 0xa5) & 1) ? true : false;
}

struct Setting_S
{
    float* Float();
};
struct GlobalObject_0044f440 : Setting_S
{
};
extern GlobalObject_0044f440 g_011d961c;
extern GlobalObject_0044f440 g_011d9660;
extern GlobalObject_0044f440 g_011d9684;
extern GlobalObject_0044f440 g_011d95d4;
extern GlobalObject_0044f440 g_011d9640;

// @fnv 0x005017a0
float TermHack::FUN_005017a0(TESObjectREFR* apItemActivated)
{
    switch (((FUN_00501270_shell*)this)->FUN_005011a0(apItemActivated))
    {
    case 0:
        return *g_011d961c.Float();
    case 1:
        return *g_011d9660.Float();
    case 2:
        return *g_011d9684.Float();
    case 3:
        return *g_011d95d4.Float();
    case 4:
        return *g_011d9640.Float();
    default:
        return 3.402823466e+38F;
    }
}

extern "C" void ApplyPerkModifiers(int, void*, ...);
extern double _gModifierZero;
extern void* g_thePlayer;

// Checks the script's referenced object state: returns false for state 0, compares a perk modifier against _gModifierZero for state 1, and true otherwise.
// @fnv 0x00501990
bool __cdecl FUN_00501990(Script* apScript)
{
    if (apScript)
    {
        unsigned char cstate = reinterpret_cast<Dummy0041BF50*>(apScript->GetReferencedObjectList())->FUN_0041bf50();
        switch (cstate & 0x7f)
        {
        case 0:
            return false;
        case 1: {
            float fPerkModifier = 0.0f;
            ApplyPerkModifiers(0x14, g_thePlayer, &fPerkModifier);
            return fPerkModifier == _gModifierZero;
        }
        default:
            return true;
        }
    }
    return false;
}

struct ListProxy
{
    unsigned char __thiscall FUN_0041bf50();
    void __thiscall SetExtraState(unsigned char a1);
};
struct VProxy
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
    virtual void v18(unsigned int a1);
};
// @fnv 0x00501930
void __cdecl SetScriptLockState(Script* apRef, bool abLock)
{
    unsigned char cstate;
    if (apRef)
    {
        cstate = ((ListProxy*)apRef->GetReferencedObjectList())->FUN_0041bf50();
        if (abLock)
            cstate++;
        else
            cstate = 0;
        ((ListProxy*)apRef->GetReferencedObjectList())->SetExtraState(cstate);
        ((VProxy*)apRef)->v18(0x80000000);
    }
}

class ScriptLocals;

struct ExtraDataList
{
    ScriptLocals* GetScriptLocalData();
};

struct FUN_005ac1e0_shell
{
    bool __thiscall Execute(TESObjectREFR* apRef, ScriptLocals* apLocals, ScriptLocals* apNullLocals, bool abFlag);
};

struct FUN_00501830_shell
{
    unsigned char _pad[0x10];
    Script m_kScript;

    void __thiscall FUN_00501830(Script* apScript);
};

// @fnv 0x00501830
void FUN_00501830_shell::FUN_00501830(Script* apScript)
{
    m_kScript.GetHeader()->quest = false;

    reinterpret_cast<FUN_005ac1e0_shell*>(&m_kScript)
        ->Execute(reinterpret_cast<TESObjectREFR*>(apScript),
                       reinterpret_cast<ExtraDataList*>(apScript->GetReferencedObjectList())->GetScriptLocalData(), 0,
                       true);
}

// @fnv 0x005018b0
void FUN_005018b0(Script* apRef, bool abVal)
{
    unsigned char cstate;
    unsigned char ucNewState;
    if (apRef != 0)
    {
        cstate = ((ListProxy*)apRef->GetReferencedObjectList())->FUN_0041bf50();
        if (abVal)
        {
            cstate = cstate | 0x80;
            ucNewState = cstate;
        }
        else
        {
            cstate = cstate & 0xffffff7f;
            ucNewState = cstate;
        }
        ((ListProxy*)apRef->GetReferencedObjectList())->SetExtraState(cstate);
        ((VProxy*)apRef)->v18(0x80000000);
    }
}

int __cdecl FUN_00404dc0(const char* pcString1, const char* pcString2);
int __cdecl FUN_00408b20(const char* pcString1, const char* pcString2);

class B408A80String
{
  public:
    const char* CStr();
    int FUN_00408a80(const char* pcOther, bool bIgnoreCase);

    char* m_pcData;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

// Compares this string's C string with pcOther, case-insensitively when bIgnoreCase is set, returning 0 when both are null.
// @fnv 0x00408a80
int B408A80String::FUN_00408a80(const char* pcOther, bool bIgnoreCase)
{
    int iResult;
    if (pcOther && CStr())
        iResult = bIgnoreCase ? FUN_00404dc0(CStr(), pcOther) : FUN_00408b20(CStr(), pcOther);
    else if (!pcOther && !CStr())
        iResult = 0;
    else
        iResult = pcOther ? -1 : 1;
    return iResult;
}

struct TerminalCleanup
{
    void FUN_00483710();
    void FUN_00501050();
    void FUN_004ffc90();
};

// @fnv 0x004ffc90
void TerminalCleanup::FUN_004ffc90()
{
    FUN_00483710();
    FUN_00501050();
}

extern "C" void* memcpy(void*, const void*, unsigned int);

struct TerminalPasswordAccess
{
    BGSNote* GetPassword();
};
struct BSStringCopy
{
    BSStringCopy& operator=(const BSStringCopy& arString);
};
struct ScriptCopy
{
    void CopyFrom(Script* apScript);
};
struct ConditionCopy
{
    void CopyFrom(PerkEntryConditionSet* apConditions, bool abFlag);
};

struct BGSTerminalEx : BGSTerminal
{
    void ClearMenuItems();
    void CopyActivator(TESForm* apForm);
    void CopyFromTerminal(TESForm* apForm);
};

// @fnv 0x00500cb0
void BGSTerminalEx::CopyFromTerminal(TESForm* apForm)
{
    BGSTerminal* pTerminal = dynamic_cast<BGSTerminal*>(apForm);
    if (!pTerminal)
        return;
    BSSimpleList<TerminalMenuItem*>* pIter = 0;
    FUN_00500a20(((TerminalPasswordAccess*)pTerminal)->GetPassword());
    memcpy(&Data, &pTerminal->Data, sizeof(Data));
    ClearMenuItems();
    pIter = pTerminal->FUN_00461150();
    while (pIter && !pIter->IsEmpty())
    {
        TerminalMenuItem* pSrc = pIter->GetItem();
        pIter = pIter->GetNext();
        TerminalMenuItem* pItem = new TerminalMenuItem;
        *(BSStringCopy*)&pItem->ResponseText = *(BSStringCopy*)&pSrc->ResponseText;
        *(BSStringCopy*)&pItem->m_kMenuText = *(BSStringCopy*)&pSrc->m_kMenuText;
        pItem->m_pNote = pSrc->m_pNote;
        pItem->m_pTerminal = pSrc->m_pTerminal;
        pItem->cFlags = pSrc->cFlags;
        ((ScriptCopy*)&pItem->m_kScript)->CopyFrom(&pSrc->m_kScript);
        ((ConditionCopy*)&pItem->Conditions)->CopyFrom(&pSrc->Conditions, false);
        AddMenuItem(pItem);
    }
    CopyActivator(pTerminal);
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct TerminalStringCmp
{
    bool IsDifferent(const BSStringT<char>* apOther);
};
struct TerminalScriptCmp
{
    bool IsDifferent(Script* apOther);
};
struct TerminalConditionCmp
{
    bool IsDifferent(PerkEntryConditionSet* apOther);
};
struct TerminalMenuList
{
    int GetSize();
};

struct TerminalCompare : public BGSTerminal
{
    void* GetCompareKey();
    bool CompareBase(BGSTerminal* apOther);
    bool IsDifferentFrom(TESForm* apForm);
};

// @fnv 0x00500e60
bool TerminalCompare::IsDifferentFrom(TESForm* apForm)
{
    BGSTerminal* pTerminal = dynamic_cast<BGSTerminal*>(apForm);
    if (!pTerminal)
        return true;
    if (GetCompareKey() != static_cast<TerminalCompare*>(pTerminal)->GetCompareKey())
        return true;
    if (memcmp(&Data, &pTerminal->Data, sizeof(TerminalCompareData)))
        return true;

    BSSimpleList<TerminalMenuItem*>* pThisIter5 = FUN_00461150();
    BSSimpleList<TerminalMenuItem*>* pOtherIter = pTerminal->FUN_00461150();
    if (((TerminalMenuList*)pThisIter5)->GetSize() != ((TerminalMenuList*)pOtherIter)->GetSize())
        return true;

    while (pOtherIter && !pOtherIter->IsEmpty() && pThisIter5 && !pThisIter5->IsEmpty())
    {
        TerminalMenuItem* pOtherItem = pOtherIter->GetItem();
        TerminalMenuItem* pThisItem5 = pThisIter5->GetItem();
        if (((TerminalStringCmp*)&pThisItem5->ResponseText)->IsDifferent(&pOtherItem->ResponseText))
            return true;
        if (((TerminalStringCmp*)&pThisItem5->m_kMenuText)->IsDifferent(&pOtherItem->m_kMenuText))
            return true;
        if (((TerminalScriptCmp*)&pThisItem5->m_kScript)->IsDifferent(&pOtherItem->m_kScript))
            return true;
        if (((TerminalConditionCmp*)&pThisItem5->Conditions)->IsDifferent(&pOtherItem->Conditions))
            return true;
        if (pThisItem5->m_pNote != pOtherItem->m_pNote)
            return true;
        if (pThisItem5->m_pTerminal != pOtherItem->m_pTerminal)
            return true;
        if (pThisItem5->cFlags != pOtherItem->cFlags)
            return true;
        pOtherIter = pOtherIter->GetNext();
        pThisIter5 = pThisIter5->GetNext();
    }

    if (CompareBase(pTerminal))
        return true;
    return false;
}

struct FUN_00501050_ref
{
    int FUN_005010c0(int aFlag);
};

struct FUN_00501050_sub
{
    bool FUN_008256d0();
    FUN_00501050_ref** FUN_006815c0();
    void FUN_0063f7b0();
};

class FUN_00501050_cls
{
  public:
    unsigned char unk00[0x98];
    FUN_00501050_sub sub;
    void FUN_00501050();
};

// @fnv 0x00501050
void FUN_00501050_cls::FUN_00501050()
{
    while (sub.FUN_008256d0() == 0)
    {
        FUN_00501050_ref* a = *sub.FUN_006815c0();
        sub.FUN_0063f7b0();
        FUN_00501050_ref* tmp = a;
        FUN_00501050_ref* b2 = tmp;
        (b2 != 0 ? b2->FUN_005010c0(1) : 0);
    }
}

struct SaveForm
{
    void FUN_004855a0();
    void FUN_00485680();
};
struct SaveFullName : TESFullName
{
    void FUN_00487010();
};
struct SaveModel : TESModelTextureSwap
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct SaveScriptable : TESScriptableForm
{
    void FUN_0048cca0();
};
struct S_00477f20 : BGSDestructibleObjectForm
{
    void FUN_00477f20();
};
struct SaveDescription : TESDescription
{
    void FUN_00482cb0();
};
struct SaveScript
{
    void FUN_005abe00();
};
struct TESConditionSave
{
    void ProcessItems();
};
struct SaveGameString
{
    operator const char*() const;
};
struct ActivatorSoundFields : TESBoundAnimObject,
                              TESFullName,
                              TESModelTextureSwap,
                              TESScriptableForm,
                              BGSDestructibleObjectForm
{
    unsigned int unk70;
    TESSound* loopingSound;
};
struct SaveSound
{
    unsigned int GetFormID();
};
struct SaveActivator : TESBoundAnimObject, SaveFullName, SaveModel, SaveScriptable, S_00477f20
{
    unsigned int unk70;
    TESSound* loopingSound;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
};
struct TerminalSave : SaveActivator, SaveDescription
{
    BSSimpleList<TerminalMenuItem*> m_kMenuItems;
    BGSNote* pPassword;
    TerminalCompareData Data;
    BSSimpleList<TerminalMenuItem*>* FUN_00461150();
    BGSNote* FUN_004fd400();
    void FUN_00500a40();
};
bool __cdecl FUN_00401500();
unsigned int __cdecl BSStringLength(const char*);
void __cdecl FUN_004856f0(unsigned int, const void*, unsigned int);
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl FUN_00485910(unsigned int, unsigned int);
void __cdecl AppendChunk(unsigned int, void*, unsigned int);

// @fnv 0x00500a40
void TerminalSave::FUN_00500a40()
{
    reinterpret_cast<SaveForm*>(this)->FUN_004855a0();
    SaveFullName::FUN_00487010();
    SaveModel::ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    SaveScriptable::FUN_0048cca0();
    S_00477f20::FUN_00477f20();
    SaveDescription::FUN_00482cb0();
    if (loopingSound)
    {
        unsigned int soundID = reinterpret_cast<SaveSound*>(loopingSound)->GetFormID();
        FUN_00485910(0x4d414e53, soundID);
    }
    if (FUN_004fd400())
    {
        unsigned int passwordID = FUN_004fd400()->GetFormID();
        FUN_00485910(0x4d414e50, passwordID);
    }
    if (FUN_00401500())
        reinterpret_cast<TerminalCleanup*>(&Data)->FUN_00483710();
    AppendChunk(0x4d414e44, &Data, 4);
    if (FUN_00401500())
        reinterpret_cast<TerminalCleanup*>(&Data)->FUN_00483710();
    BSSimpleList<TerminalMenuItem*>* pMenuNode = FUN_00461150();
    while (pMenuNode && !pMenuNode->IsEmpty())
    {
        TerminalMenuItem* item = pMenuNode->GetItem();
        pMenuNode = pMenuNode->GetNext();
        if (static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->ResponseText)))
            FUN_004856f0(
                0x54585449, static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->ResponseText)),
                BSStringLength(static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->ResponseText))) + 1);
        else
            FUN_00485910(0x54585449, 0);
        if (static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->m_kMenuText)))
            FUN_004856f0(
                0x4d414e52, static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->m_kMenuText)),
                BSStringLength(static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->m_kMenuText))) + 1);
        else
            FUN_00485910(0x4d414e52, 0);
        FUN_004858f0(0x4d414e41, item->cFlags);
        if (item->m_pNote)
        {
            unsigned int noteID = item->m_pNote->GetFormID();
            FUN_00485910(0x4d414e49, noteID);
        }
        if (item->m_pTerminal)
        {
            unsigned int submenuID = item->m_pTerminal->GetFormID();
            FUN_00485910(0x4d414e54, submenuID);
        }
        reinterpret_cast<SaveScript*>(&item->m_kScript)->FUN_005abe00();
        reinterpret_cast<TESConditionSave*>(&item->Conditions)->ProcessItems();
    }
    reinterpret_cast<SaveForm*>(this)->FUN_00485680();
}

struct Ref;
struct Form
{
    int Type();
};
struct Ref
{
    Form* GetOwner();
    bool CanBeUsed(Ref*, bool);
};
struct Player
{
    int Check(Ref*);
    void Penalize(int);
};
extern Player* _g_thePlayer;
bool FUN_00709bc0();
struct Open
{
    static int GetOpenState(Ref*);
};
bool FUN_005012c0(Ref*);
struct Text
{
    char* data;
    unsigned short length, capacity;
    Text();
    ~Text();
    operator const char*() const;
};
struct Sound
{
    int id;
    int state;
    int flags;
    ~Sound();
    bool Play(bool);
};
struct Audio
{
    Sound GetSoundHandleByEditorID(const char*, unsigned int);
    static Audio* GetSingleton();
};
struct Setting
{
    const char* GetString();
    const char* String();
    float* Float();
};
extern Setting g_011c8394, g_011d4810, originalRuntimeFloatSetting282;
const char* GetActorValueName(int);
int Format(Text*, const char*, ...);
float Clamp(float, float);
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
struct Activate
{
    virtual void Run(Ref*, Ref*);
};
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float Get(int);
};
struct OwnerActor
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
    Values values;
};
struct Faction
{
    bool Test();
};
unsigned int FUN_0047e040(float);
void FUN_0047a560(Ref*, Ref*, int);
struct Terminal
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
    Activate activation;
    float FUN_005017a0(Ref*);
    bool FUN_005015d0();
    bool ActivateTerminal(Ref*, Ref*, int, int, int);
};
// @fnv 0x00501310
bool Terminal::ActivateTerminal(Ref* target, Ref* user, int arg3, int arg4, int arg5)
{
    if (FUN_00709bc0())
    {
        return false;
    }
    else if (Open::GetOpenState(target) == 1)
    {
        activation.Run(target, user);
    }
    else if (user == (Ref*)_g_thePlayer && _g_thePlayer->Check(target) == 4)
    {
        Text message;
        Format(&message, g_011c8394.GetString(), GetActorValueName(40), (int)Clamp(FUN_005017a0(target), 1.0f));
        QueueUIMessage(message, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_angry.dds", 0, 2.0f, false);
        Audio::GetSingleton()->GetSoundHandleByEditorID("UIPopUpMessageGeneral", 0x121).Play(false);
    }
    else if (user == (Ref*)_g_thePlayer && FUN_005012c0(target))
    {
        QueueUIMessage(g_011d4810.String(), 0, 0, 0, 2.0f, false);
        return false;
    }
    else
    {
        Ref* actor = user;
        if (target->GetOwner() && !target->CanBeUsed(actor, true) && !FUN_005015d0())
        {
            bool crime = false;
            Form* owner = target->GetOwner();
            int unused = 0;
            if (owner->Type() == 8)
            {
                Faction* faction = (Faction*)owner;
                if (!faction->Test())
                    crime = true;
            }
            else
            {
                OwnerActor* pOwnerActor = (OwnerActor*)owner;
                if (pOwnerActor)
                {
                    unsigned int rank = FUN_0047e040(pOwnerActor->values.Get(23));
                    if (rank != 2 && rank != 4)
                        crime = true;
                }
            }
            if (crime)
                _g_thePlayer->Penalize((int)*originalRuntimeFloatSetting282.Float());
        }
        FUN_0047a560(target, user, 0);
    }
    return true;
}

struct TermFormBase
{
    virtual void Vf00();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct TermFullName
{
    virtual void Vf30();
    int unk04, unk08;
};
struct TermModel
{
    virtual void Vf3c();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct TermScriptable
{
    virtual void Vf5c();
    int unk04, unk08;
};
struct TermDestructible
{
    virtual void Vf68();
    int unk04;
};
struct TermOpenClose
{
    virtual void Vf70();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct TermActivator : TermFormBase, TermFullName, TermModel, TermScriptable, TermDestructible, TermOpenClose
{
    TermActivator();
    ~TermActivator();
};
struct TermDescription
{
    virtual void Vf90();
    unsigned int text;
    TermDescription();
};
struct TermMenuList
{
    void* item;
    TermMenuList* next;
    TermMenuList();
    ~TermMenuList();
};

struct FUN_004ffaa0 : TermActivator, TermDescription
{
    TermMenuList m_kMenuItems;
    void* pPassword;
    unsigned int Data;
    FUN_004ffaa0();
    void SetFormType(int eType);
    void ResetFormData();
};

// @fnv 0x004ffaa0
FUN_004ffaa0::FUN_004ffaa0()
{
    SetFormType(0x17);
    ResetFormData();
}

extern float DAT_011c83c4;
extern void* DAT_011dea3c;
float* __fastcall FUN_00403e20(float*);
unsigned short __fastcall FUN_0087f9f0(void*);
struct RefLevel
{
    unsigned int __thiscall FUN_00567e10(bool);
};

// Returns the initial result, optionally adding a scaled level value and capping it at 4 when the flag is set.
// @fnv 0x005011a0
int __thiscall FUN_00501270_shell::FUN_005011a0(TESObjectREFR* apRef)
{
    unsigned int result = reinterpret_cast<FUN_00501a30_shell*>(this)->FUN_00501a30(reinterpret_cast<Script*>(apRef));
    if (reinterpret_cast<FUN_00501250_shell*>(this)->IsFlagSet())
    {
        unsigned int level =
            apRef ? reinterpret_cast<RefLevel*>(apRef)->FUN_00567e10(false) : FUN_0087f9f0(DAT_011dea3c);
        result += (unsigned int)((double)level * *FUN_00403e20(&DAT_011c83c4));
        if (result > 4)
            result = 4;
    }
    return result;
}
