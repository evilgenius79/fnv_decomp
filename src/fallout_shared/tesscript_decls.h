// fallout_shared/tesscript_decls.h: declares TESForm, Script, SpellItem, MagicItem, EffectSetting and more
#ifndef FNV_TESSCRIPT_DECLS_H
#define FNV_TESSCRIPT_DECLS_H

#include <stdarg.h>
#include <new>
#include <malloc.h>
class TESQuest;
class NiNode;
class BSFadeNode;
class FormFlagRecord;
class TESBoundObject;
class ScriptFunctionInfo;
class Script;
class ScriptLocals;
class ScriptVariableInfo;
class ScriptReferencedObject;
class ScriptLocalVariable;
class ScriptParameter;
class ScriptDefinition;
class ExtraDataList;
#include <string.h>
// Source layout: TESForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESFORM_H
#define FNV_TESFORM_H
#include "tesscript_layout.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    ENUM_FORM_ID GetFormType() const;
    bool IsFormInitialized() const;
    void SetFile(TESFile* file);
    static TESForm* GetFormByID(unsigned int id);
    TESForm();
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESForm, m_ucFormType) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESForm, m_uiFormFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESForm, m_kSourceFiles) == 0x10);
#endif
// Source layout: Script. PC corrections are in generate_headers.py.
#ifndef FNV_SCRIPT_H
#define FNV_SCRIPT_H
#include "layout_support.h"
#include "ScriptHeaderData.h"
#include "TESForm.h"
#pragma pack(push, 4)
class Script : public TESForm
{
  public:
    ScriptHeaderData m_kHeader;                                          // +0x18
    char* m_pText;                                                    // +0x2C
    char* m_data;                                                     // +0x30
    float m_fValueAtOffset34;                                         // +0x34
    float fValueAtOffset38;                                           // +0x38
    float m_fValueAtOffset3C;                                         // +0x3C
    TESQuest* m_pOwnerQuest;                                          // +0x40
    BSSimpleList<ScriptReferencedObject*> m_kReferencedObjectList;  // +0x44
    BSSimpleList<ScriptVariableInfo*> m_kVariableList;                    // +0x4C
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual bool Load(TESFile* file);
    virtual void CopyFrom(const TESForm* form);
    void InitializeActionList();
    static void CopyListToView(BSSimpleList<ScriptVariableInfo*>* source, BSSimpleList<ScriptVariableInfo*>* dest,
                               Script* script);
    static void CopyScriptReferences(BSSimpleList<ScriptReferencedObject*>* source,
                                     BSSimpleList<ScriptReferencedObject*>* dest, Script* script);
    void SetText(const char* text);
    ScriptLocals* GetOrCreateScriptLocals();
    BSSimpleList<ScriptLocalVariable*>* GetScriptEntryList();
    bool Run(TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* container, bool flag);
    virtual void InitItem();
    static void CopyIdentifierBitsToValue(const unsigned int& id, double& value);
    static bool IsConsolePlatform();
    static void InitializeScriptRuntime();
    static bool IsReferenceScriptActive(TESObjectREFR* ref);
    static bool IsReferenceScriptEnabled(TESObjectREFR* ref);
    static void ClearReferenceScriptState(TESObjectREFR* ref);
    static void ClearScriptLocalsForReference(TESObjectREFR* ref);
    void AdvanceScript(TESObjectREFR* ref, ScriptLocals* locals, float time);
    static void SetScriptLocalsFromExtraData(TESObjectREFR* ref, ExtraDataList* extra);
    void GetLocalData();
    void FUN_005aa2e0();
    void FUN_005ae2e0();
    void Update();

    Script();
    virtual ~Script();
    virtual void InitializeComponent();
    char* GetData();
    char* GetText();
    ScriptReferencedObject* GetReferencedForm(unsigned int index, ScriptLocals* locals);
    ScriptHeaderData* GetHeader();
    const char* GetVariableName(unsigned int index);
    static bool GetValue(double& value, const char* data, unsigned int& offset, TESObjectREFR* reference,
                         TESObjectREFR* container, Script* script, ScriptLocals* locals, bool skip);
    void CopyScriptContents(Script* script);
    void SetScriptData(unsigned int size, char* data);
    BSSimpleList<ScriptReferencedObject*>* GetReferencedObjectList();
    BSSimpleList<ScriptVariableInfo*>* GetVariableList();
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Script) == 0x54);
FNV_STATIC_ASSERT(offsetof(Script, m_kHeader) == 0x18);
FNV_STATIC_ASSERT(offsetof(Script, m_pText) == 0x2C);
FNV_STATIC_ASSERT(offsetof(Script, m_data) == 0x30);
FNV_STATIC_ASSERT(offsetof(Script, m_fValueAtOffset34) == 0x34);
FNV_STATIC_ASSERT(offsetof(Script, fValueAtOffset38) == 0x38);
FNV_STATIC_ASSERT(offsetof(Script, m_fValueAtOffset3C) == 0x3C);
FNV_STATIC_ASSERT(offsetof(Script, m_pOwnerQuest) == 0x40);
FNV_STATIC_ASSERT(offsetof(Script, m_kReferencedObjectList) == 0x44);
FNV_STATIC_ASSERT(offsetof(Script, m_kVariableList) == 0x4C);
#endif

#ifndef FNV_SCRIPT_REFERENCED_OBJECT_H
#define FNV_SCRIPT_REFERENCED_OBJECT_H
#include "layout_support.h"
#pragma pack(push, 4)
class ScriptReferencedObject
{
  public:
    BSStringT<char> m_kFormName;  // +0x0
    TESForm* pForm;               // +0x8
    unsigned int m_uiFormID;      // +0xC
    ScriptReferencedObject();
    ScriptReferencedObject(ScriptReferencedObject* source);
    ~ScriptReferencedObject();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptReferencedObject) == 0x10);
FNV_STATIC_ASSERT(offsetof(ScriptReferencedObject, m_kFormName) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptReferencedObject, pForm) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptReferencedObject, m_uiFormID) == 0xC);
#endif

#ifndef FNV_SCRIPT_LOCAL_H
#define FNV_SCRIPT_LOCAL_H
#include "layout_support.h"
#pragma pack(push, 4)
class ScriptLocalVariable
{
  public:
    ScriptLocalVariable(ScriptVariableInfo* variable);
    unsigned int uiID;  // +0x0
    unsigned char layoutPadding4[4];
    double fValue;     // +0x8
    bool m_bIsString;  // +0x10
    unsigned char layoutPadding11[7];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptLocalVariable) == 0x18);
FNV_STATIC_ASSERT(offsetof(ScriptLocalVariable, uiID) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptLocalVariable, fValue) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptLocalVariable, m_bIsString) == 0x10);
#endif

#include "ScriptVariableInfo.h"
#include "tesscript_types_SCRIPT_PARAMETER.h"
class SpellItem : public TESForm
{
};
class MagicItem : public TESForm
{
};
class EffectSetting : public TESForm
{
};
class EnchantmentItem;
class TESEnchantableForm : public BaseFormComponent
{
  public:
    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    unsigned short padding;
    int m_eCastingType;
    EnchantmentItem* FindFormEnchantment();
};
class TESObjectBOOK : public TESForm
{
  public:
    unsigned char components[0x74 - 0x18];
    TESEnchantableForm enchantable;
};
struct ScriptParameterKind
{
    const char* name;
    unsigned char valueKind;
    bool isReference;
    unsigned short reserved;
};
extern ScriptParameterKind DAT_0118cdd0[];
int Warning(const char*, ...);
class TESContainer
{
  public:
    static bool IsValidContainerType(unsigned char type);
};
bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                 ScriptLocals*, ...);

class ScriptLocals
{
  public:
    Script* m_pOwnerScript;
    char m_cActionFlags;
    BSSimpleList<FormFlagRecord*>* m_pLocalVariableList;
    BSSimpleList<ScriptLocalVariable*>* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;
    ScriptLocals();
    ~ScriptLocals();
    void Destroy();
    double GetVariable(unsigned int index, Script* script);
    void SetVariable(unsigned int index, double value);
    BSSimpleList<ScriptLocalVariable*>* GetLocalList();
    void CopyActionListFrom(ScriptLocals* locals);
    FormFlagRecord* FUN_005a90b0(ScriptLocals* locals, bool create);
    void ProcessPendingTasks();
    TESBoundObject* GetActionEntry();
    TESBoundObject* GetLocalData();
    bool FUN_005a8e20(TESForm* form, unsigned int flag);
    void FUN_005a85c0();
};
class TESQuest : public TESForm
{
  public:
    ScriptLocals* GetScriptLocalData();
    float FUN_00792760();
};
class ExtraDataList
{
  public:
    TESObjectREFR* GetReplacementReference();
    ScriptLocals* FUN_00418830();
};
class InventoryStackRecord
{
  public:
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    ~InventoryStackRecord();
    ScriptLocals* GetScriptLocalData();
};
class TESObjectREFR : public TESForm
{
  public:
    void Enable();
    void FUN_00574400();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    const char* GetFullName();
    ExtraDataList* GetExtraData();
    TESBoundObject* GetObjectReference();
    InventoryStackRecord* FindEntryForObject(TESBoundObject* object, unsigned int formID);
    ScriptLocals* GetReferenceLocals();
};
class TESGlobalValueReader
{
  public:
    float GetValue();
};
enum SCRIPT_OUTPUT
{
    SCRIPT_OUTPUT_START_OF_FLOW_SECTION = 16
};
typedef bool(__cdecl* FNVScriptExecuteFunction)(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                                Script*, ScriptLocals*, double&, unsigned int&);
class ScriptFunctionInfo
{
  public:
    char* pFunctionName;
    char* m_pShortName;
    SCRIPT_OUTPUT m_eOutputType;
    char* m_pDescription;
    bool m_bRequiresReference;
    unsigned short m_usParameterCount;
    ScriptParameter* pParameters;
    FNVScriptExecuteFunction m_pfnExecute;
    void* m_pfnCompile;
    void* m_pfnCondition;
    bool m_bFunctionFlag;
    bool m_bSetsExecutionFlag;
};
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);

enum MEM_CONTEXT
{
    MEM_CONTEXT_SCRIPT = 21
};
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
union SETTING_VALUE
{
    float f;
    bool b;
    unsigned int ui;
    int i;
    char* s;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT_GameSettingCollection_ DAT_011cac68;
extern float DAT_011cad20[8];
extern int DAT_011cad40;
char* AllocateZeroed(unsigned int count, unsigned int size);
class FormRecordMetadata
{
  public:
    unsigned int iFormID;
};
class TESSaveLoadGame
{
  public:
    bool GetLoading();
    FormRecordMetadata* GetCurrentlyLoadingFormHeader();
    const char* FUN_005a9460();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    static const char* GetFullName(TESForm* form);
};
#endif
class NiNode
{
  public:
    virtual ~NiNode();
    virtual void vfn_04();
    virtual const void* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
};
class BSFadeNode : public NiNode
{
  public:
    bool IsVisible();
};
class RecursiveSpinLock
{
  public:
    void FUN_004538a0(unsigned int threadID);
    void FUN_004538c0();
};
extern RecursiveSpinLock DAT_011cacf8;
extern BSSimpleList<TESObjectREFR*> DAT_011caca8;
extern BSSimpleList<TESObjectREFR*> DAT_011cac98;
extern BSSimpleList<TESObjectREFR*> DAT_011cace8;
extern BSSimpleList<TESObjectREFR*> DAT_011cacb8;
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
class ScriptExecutor
{
  public:
    static ScriptExecutor* Instance();
    void FUN_005e2730(Script* script, TESObjectREFR* ref, ScriptLocals* locals);
    bool Run(Script*, TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool, bool, bool, float);
};
extern int DAT_011cae50;
class FormFlagRecord
{
  public:
    TESForm* pForm;
    unsigned int iFlags;
};
extern bool DAT_0118c685;
#endif

class TESBoundObject
{
  public:
    bool IsBoundItem();
};
class ScriptActionView
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual TESBoundObject* vfn_94();
};
