
// inventorychanges_ctxr_variant.cpp: rename variant for 0x004cb5f0 (integration 2026-10-30): the unit's skeleton with movePlural, moveVerb renamed, whose names are bound elsewhere.
#include "inventorychanges_packet.h"
#include "../../include/TESObjectREFR.h"
#include "Actor.h"
#include "BaseProcess.h"
#include "AutoMemContext.h"
#include "game_constants.h"
extern const char g_inventoryChangesSourceFilename[];
void DeleteItemChange(InventoryStackRecord* item);
struct FUN_004bc5f0_shell : public InventoryStackRecord
{
    void FUN_004bc5f0();
};
struct FUN_004bc780_shell : public InventoryStackRecord
{
    void ClearExtraDataList();
};
struct _DummyExtraDataList
{
    virtual ~_DummyExtraDataList();
    void RemoveAll(bool);
};
struct _DummySimpleList
{
    ExtraDataList** _ref_006815c0();
    _DummySimpleList* _ref_00726070();
    void _ref_00905330(ExtraDataList**);
};
struct XExtra
{
    bool HasOnlyAllowedExtraData(int a);
    bool FUN_00418ab0(int a);
    short FUN_00418770();
};
struct XNode
{
    XExtra** _ref_006815c0();
    XNode* _ref_00726070();
};
struct FUN_004bc8f0_stand
{
    XNode* first;
    int FUN_004bc8f0(bool abWornIgnore);
};
struct FUN_004bc980_shell : public InventoryStackRecord
{
    int FUN_004bc980();
};
struct ExtraNode;
ExtraNode* __fastcall _ref_00726070(ExtraNode*);
ExtraDataList** __fastcall _ref_006815c0(ExtraNode*);
struct ListRemover
{
    void _ref_00905330(ExtraDataList**);
};
short __fastcall FUN_00418770(const ExtraDataList*);
struct FUN_0041d120_shell
{
    bool HasOnlyAllowedExtraData(int);
};
struct ExtraVDtor
{
    virtual ~ExtraVDtor();
};
struct ExtraEmptyShell
{
    bool IsEmpty();
};
struct FUN_004bca80_shell : public InventoryStackRecord
{
    int CountAndPruneEntries();
};
struct ExtraHelper_004bca80
{
    virtual ~ExtraHelper_004bca80();
    short FUN_00418770();
    bool HasOnlyAllowedExtraData(int);
    int ItemsInList();
    void RemoveExtra24();
};
struct ListHelper_004bca80
{
    ExtraHelper_004bca80** _ref_006815c0();
    ListHelper_004bca80* _ref_00726070();
    void _ref_00905330(ExtraHelper_004bca80**);
};
struct FUN_004bddd0_shell : public InventoryStackRecord
{
    bool FUN_004bddd0(bool);
};
struct ExtraDataList_shell
{
    bool FUN_00418ab0(bool);
};
struct Script;
struct FUN_004bde40_shell : public InventoryStackRecord
{
    Script* FUN_004bde40();
};
Script* __fastcall FUN_00418800(ExtraDataList*);
ExtraDataList** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
int __fastcall FUN_004be080(void* pThis);
int __fastcall FUN_004be060(void* pThis);
float __fastcall FUN_004be180(char* pThis);
struct ItemNode;
struct ExtraNode;
InventoryStackRecord** __fastcall _ref_006815c0(ItemNode*);
ItemNode* __fastcall _ref_00726070(ItemNode*);
ExtraDataList** __fastcall _ref_006815c0(ExtraNode*);
ExtraNode* __fastcall _ref_00726070(ExtraNode*);
int __fastcall _FNV_GetFormType(unsigned int);
bool __fastcall FUN_004bfd80(unsigned int);
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00418ab0_shell
{
    bool FUN_00418ab0(bool);
};
struct FUN_004bfc80_shell : public InventoryChanges
{
    bool FUN_004bfc80();
};
unsigned char __fastcall FUN_004bfd80(unsigned char* p);
class TESObjectWEAP
{
  public:
    bool IsRangedWeapon();
};
bool __fastcall FUN_004c0c60(TESObjectWEAP* weap);
bool __fastcall FUN_004c0bf0(TESObjectWEAP* weap);
bool __fastcall FUN_004c0c30(char* pThis);
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct NiPoint3;
struct TESAnimGroup;
struct TESIdleForm;
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    char m_kNodeTranslation[12];
    char m_kRootTranslation[12];
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];
struct FUN_004c0c90_shell : public Animation
{
    void FUN_004c0c90(float);
};
struct FUN_004c94d0_shell
{
    unsigned char GetFlag() const;
};
bool __fastcall FUN_004d1360(char* pThis);
struct VATSCommand
{
    int eType;
    void* pTarget;
    unsigned char cCount;
    bool bFadeQueuedCur;
    ~VATSCommand();
};
struct VATS_CommandList
{
    VATSCommand* pItem;
    VATS_CommandList* pNext;
    VATSCommand** FUN_006815c0();
    VATS_CommandList* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00905330(VATSCommand* const&);
};
struct Setting_S
{
    float* Float();
};
struct GameTimerRecord
{
    void SetGlobalTimeMultiplier(float, bool);
};
extern Setting_S originalRuntimeFloatSetting543;
extern GameTimerRecord g_timeGlobal;
extern float DAT_011f21e0;
struct VATS
{
    VATS_CommandList m_kCommandList;
    int eMode;
    VATSCommand* FUN_009c71c0();
    void ProcessVATSCommands();
    void FUN_009c8950(bool abForceQuit, bool abFinishCommandPlayback);
};
struct FUN_004bd9d0_shell
{
    float FUN_004bd9d0(int a1, unsigned char a2);
};
extern unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);
struct FUN_00766a10_shell
{
    void SetCapacity(unsigned int a);
};
struct FUN_0042dec0_shell : public BaseExtraList
{
    void FUN_0042dec0();
    void RemoveExtra(unsigned char);
};
struct GetModHelper_4bcf00
{
    float GetModdedWeaponValue(int, int);
};
struct FUN_004bcf00_stand
{
    int GetModdedValue(bool);
};
struct FUN_004bcf60_shell
{
    float GetEffectValue(int effect, unsigned char value);
};
struct FUN_004bd570_this
{
    int FUN_004bd570(unsigned int);
};
struct FUN_00418660_shell
{
    TESForm* FUN_00418660();
};
struct FUN_004bd740_stand
{
    TESForm* GetExtraForm();
};
struct FUN_00418ba0_shell
{
    bool FUN_00418ba0();
};
struct FUN_0042e560_shell
{
    unsigned char FUN_0042e560();
};
struct FUN_004bd820_stand
{
    unsigned char FUN_004bd820();
};
struct Caller_42
{
    void FUN_0042e6f0();
};
struct Holder_70
{
    _DummySimpleList* first;
    void FUN_004bdc70();
};
struct FUN_004187d0_Class
{
    BSExtraData* FUN_004187d0();
};
struct FUN_004bdcc0_Class
{
    _DummySimpleList* first;
    BSExtraData* FUN_004bdcc0();
};
struct ScriptLocals;
struct ItemChangeShell : public InventoryStackRecord
{
    ScriptLocals* FUN_004bdea0();
};
struct ExtraDataList_shell2 : public ExtraDataList
{
    ScriptLocals* GetScriptLocalData();
};
struct StartMenu
{
    const char* GetMenuTitle();
};
struct GlobalObject_0040c150 : public StartMenu
{
};
extern GlobalObject_0040c150 g_011d35b8;
struct TESModel
{
    unsigned int GetModelLength() const;
};
struct TESFullName : public BaseFormComponent
{
    unsigned int GetModelLength() const;
    const char* GetFullName();
};
struct TESBoundObject : public BaseFormComponent
{
};
struct ActorPackage_004be2d0
{
    TESBoundObject* GetTarget();
};
struct FUN_004be2d0_shell
{
    const char* GetTargetFullName();
};
struct IsEmptyNode
{
    bool _ref_008256d0();
};
struct CallerNode
{
    void FUN_00426020(int, int, int, int);
};
struct FUN_004bed00_host
{
    _DummySimpleList* first;
    int unk04;
    int unk08;
    void FUN_004bed00();
};
struct IndexedPointerCollection
{
    void DestroyList();
    void* FUN_004bf630(unsigned int);
};
void _Deallocate(void*);
struct FUN_004bfb30_shell
{
    unsigned int GetAtIfValid(int);
};
struct DAT_011c6444_type
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual ~DAT_011c6444_type();
};
extern DAT_011c6444_type* DAT_011c6444;
void FUN_004c1c40();
struct ScriptS
{
    void* _ref_006815c0();
    void* _ref_00726070();
    void* GetHeader();
    TESObject* GetNext();
};
struct FUN_00474a40
{
    ScriptS* GetScript();
};
struct FUN_00474a00
{
    TESForm* GetForm();
};
struct FUN_004c7300_shell : public InventoryChanges
{
    int GetObjectCount(TESForm*);
    InventoryStackRecord* FindInventoryItem(TESObjectREFR* pRef, bool* pFound);
};
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct Unk_004ca1a0
{
    List_009e03e0* pList;
    void DestroyList();
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct TESScriptableForm : public TESForm
{
    virtual ~TESScriptableForm();
};
void FUN_004ce300(TESForm* a, unsigned int b);
struct FUN_004ce340_stand
{
    void FUN_004ce340(int a0, int a1, bool a2, bool a3, bool a4, bool a5, int a6, int a7);
    void FUN_004ce380(int a0, int a1, bool a2, bool a3, bool a4, bool a5, int a6, int a7);
};
struct C008256d0
{
    bool _ref_008256d0();
};
struct C004bed00
{
    void FUN_004bed00();
};
struct S_004d4030
{
    ItemNode* head;
    void FUN_004d4030();
};
struct FUN_004bd880_stand
{
    char _pad[0x180];
    void* f180;
    void* f184;
    void* f188;
    void* GetSlotPointer(int);
};
struct VTableHelper
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v195(float);
};
void __fastcall FUN_004bf0e0(InventoryChanges* pThis);
struct XIdle;
struct XArr
{
    void SetAt(unsigned int i, XIdle*& v);
};
struct FUN_004bfb70_stand
{
    char pad[0xe3c];
    XArr arr;
    void SetIdleAt(unsigned int i, XIdle* v);
};
struct FUN_004c0c60_Helper
{
    char pad[0xf4];
    signed char type;
    bool IsGunWeapon()
    {
        switch (type)
        {
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return true;
        default:
            return false;
        }
    }
};
bool __fastcall FUN_004c0c60(FUN_004c0c60_Helper* pThis);
struct FUN_004c0cd0_This
{
    char pad[0x1f0];
    int field_1f0;
};
struct FUN_004c0cd0_Arg
{
    int val;
};
void __fastcall SetField1F0(FUN_004c0cd0_This* pThis, FUN_004c0cd0_Arg arg);
void* __cdecl operator new(unsigned int);
void __fastcall FUN_004bf0e0(InventoryChanges*);
struct SL
{
    SL();
    void* a;
    void* b;
};
struct FUN_004befb0
{
    SL* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    FUN_004befb0(TESObjectREFR* apRef);
};
struct TESContainer;
struct FUN_004bfba0_shell
{
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, int, int);
};
struct FUN_004bffb0_shell
{
    TESContainer* FUN_004bffb0();
};
struct QEntry1
{
    int count;
    TESBoundObject* form;
};
struct QEntry2
{
    int pad;
    int count;
    TESBoundObject* form;
};
struct QNode1
{
    QEntry1** _ref_006815c0();
    QNode1* _ref_00726070();
};
struct QNode2
{
    QEntry2** _ref_006815c0();
    QNode2* _ref_00726070();
    bool _ref_008256d0();
};
struct FUN_004d0360_shell
{
    QNode2* list;
    bool FUN_004d0360();
};
struct ContainerItemExtra;
struct TESBoundObject;
struct TESForm;
struct InventoryItemEntry
{
    void Save();
    void InitItem(TESForm*);
    bool Compare(InventoryItemEntry*);
    void Copy(InventoryItemEntry*);
    void* __vecDelDtor(unsigned int);
    int m_iCountDelta;
    TESBoundObject* pObj;
    ContainerItemExtra* m_pExtraData;
};
typedef char _sizecheck_ContainerObject[sizeof(InventoryItemEntry) == 12 ? 1 : -1];
struct FUN_004d1610_shell : public InventoryChanges
{
    void FUN_004d1610();
};
struct ContNode;
struct FUN_004bffb0_S
{
    void* FUN_004bffb0();
};
ContNode* __fastcall FUN_00717e50(void*);
bool __fastcall FUN_008256d0(ContNode*);
InventoryItemEntry** __fastcall FUN_006815c0(ContNode*);
ContNode* __fastcall FUN_00726070(ContNode*);
struct FUN_00410360
{
    FUN_00410360();
    char pad[0x20];
};
struct FUN_004bc550
{
    FUN_004bc550(TESBoundObject*, int);
    char pad[0xc];
};
struct FUN_00419ad0_S
{
    void FUN_00419ad0(unsigned short);
};
void* __cdecl GetHealthForm(TESBoundObject*);
struct FUN_0040ea20_S
{
    void FUN_0040ea20(ExtraDataList*, void*);
};
struct FUN_005ae3d0_S
{
    void FUN_005ae3d0(ExtraDataList**);
};
struct FUN_004c3380_S
{
    void FUN_004c3380(InventoryStackRecord*, bool);
};
struct RefV_004d17a0
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
    virtual void MarkAsModified(unsigned int);
};
struct Extra_004d17a0
{
    virtual ~Extra_004d17a0();
    void* GetExtraLeveledItem();
    void FUN_0041d000();
    short FUN_00418770();
};
struct ExtraNode_004d17a0
{
    Extra_004d17a0** _ref_006815c0();
    ExtraNode_004d17a0* _ref_00726070();
    bool _ref_008256d0();
    void _ref_00905330(Extra_004d17a0**);
};
struct ItemNode_004d17a0
{
    InventoryStackRecord** _ref_006815c0();
    ItemNode_004d17a0* _ref_00726070();
    bool _ref_008256d0();
    void _ref_00905330(InventoryStackRecord**);
};
struct ItemCount_004d17a0
{
    int _ref_00726070();
    void FUN_006ecd40(int);
};
struct FUN_004d17a0_t
{
    ItemNode_004d17a0* m_pEntryList;
    RefV_004d17a0* pRef;
    void FUN_004d17a0();
};
struct FUN_00418c00_shell
{
    bool CheckExtraByType(int);
};
struct FUN_004bd8d0_shell : public InventoryStackRecord
{
    bool FUN_004bd8d0(unsigned char, float*);
};
struct TESNPC
{
    int GetSex();
};
struct FUN_00481230_stand
{
    const char* FUN_00481230(int);
};
struct TESTextureLoader
{
    static const char* __cdecl GetTextureResourceName(TESForm*, TESObjectREFR*);
};
extern GlobalObject_0040c150 g_011d33f0;
struct ItemChange_004be200 : public FUN_004bd740_stand
{
    const char* GetIconFilename(TESObjectREFR* apRef);
};
struct MagicTargetDispel : MagicTarget
{
    void Dispel(TESBoundObject*, bool);
};
struct ActorDispelView : MobileObject, MagicCaster, MagicTargetDispel
{
};
struct FUN_004bfe50_inode
{
    InventoryStackRecord** FUN_006815c0();
    FUN_004bfe50_inode* FUN_00726070();
};
struct FUN_004bfe50_enode
{
    ExtraDataList** FUN_006815c0();
    FUN_004bfe50_enode* FUN_00726070();
};
struct FUN_004bddd0_t
{
    bool FUN_004bddd0(bool);
};
struct FUN_004c0cf0_t
{
    void FUN_004c0cf0(bool*, unsigned int, int, Actor*, ExtraDataList*, int, bool, InventoryStackRecord*, int);
};
struct FUN_004bfe50_t : InventoryChanges
{
    void RemoveWornItems(bool abSkipCanNotWear, TESObjectREFR* apRef);
};
int __fastcall FNV_GetFormType(TESForm*);
bool __fastcall FUN_004c94d0(TESForm*);
bool __fastcall IsFlag80Clear(TESForm*);
struct TESContainer
{
    bool HasObjectOfType(TESObject*);
    int GetObjectCount(TESObject*);
};
struct FUN_00480d90_shell : public TESBipedModelForm
{
    bool FUN_00480d90();
};
struct FUN_004bc8f0_shell : public InventoryStackRecord
{
    int FUN_004bc8f0(bool);
};
struct FUN_00726070_shell : public InventoryStackRecord
{
    int FUN_00726070();
};
struct Flt
{
    operator unsigned int() const;
};
struct TESBipedModelFormEx
{
    static TESBipedModelForm* __cdecl GetFormAsBipedModel(TESForm*);
};
struct TESLevItem : public TESBoundObject
{
};
struct FUN_004c8fd0_t : public InventoryChanges
{
    int FUN_004c8fd0(bool);
};
struct ContEntry4cfe20
{
    int count;
    ::TESBoundObject* pObj;
};
struct ContNode4cfe20
{
    bool _ref_008256d0();
    ContEntry4cfe20** _ref_006815c0();
    ContNode4cfe20* _ref_00726070();
};
struct Container4cfe20
{
    ContNode4cfe20* FUN_00717e50();
};
struct ChangeCount4cfe20
{
    int _ref_00726070();
};
struct ExtraNode4cfe20
{
    ::ExtraDataList** _ref_006815c0();
    ExtraNode4cfe20* _ref_00726070();
};
struct ChangeNode4cfe20
{
    bool _ref_008256d0();
    ::InventoryStackRecord** _ref_006815c0();
    ChangeNode4cfe20* _ref_00726070();
};
struct ExtraRef4cfe20
{
    ::TESObjectREFR* FUN_0041c8d0();
};
struct FUN_004cfe20_t : public ::InventoryChanges
{
    Container4cfe20* FUN_004bffb0();
    ::InventoryStackRecord* FUN_004bfba0(::TESBoundObject*, int, int);
    bool HasItem(unsigned int aId);
};
struct FUN_00419d10
{
    void SetExtra(void*);
};
struct FUN_004bdd20_Stand
{
    void SetPerkExtra(void* apExtra);
};
struct SaveFormIDHelper
{
    void SerializeFormData(void*, int);
};
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
struct FUN_00426a30_shell
{
    void WriteNodeList(BGSSaveFormBuffer*);
};
struct FUN_004bed60_shell
{
    BSSimpleList<BGSPerk*>* list;
    int pad0;
    int pad1;
    void SavePerkList(BGSSaveFormBuffer* buffer);
};
struct SpawnedEntry
{
    unsigned int unk00;
    unsigned int unk04;
    SpawnedEntry();
};
struct FUN_004bc810_cls
{
    SpawnedEntry* m_afEntries;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0C;
    ContNode* FUN_00559450();
    void FUN_004bc810(FUN_004bc810_cls* src);
};
struct FUN_004bd7a0_stand
{
    ExtraNode* FUN_00559450();
    int FindFirstNonNegativeValue();
};
struct FUN_0042de90_obj
{
    signed char GetExtraByteValue();
};
class B4BDF00Form
{
  public:
    int GetFormType();
};
unsigned int __cdecl FUN_004873d0(B4BDF00Form* pkWeapon);
class B4BDF00Data;
float __cdecl FUN_00644ce0(void* pvActor, B4BDF00Form* pkWeapon, float fScale, float fValue, int iUnused, int iFlag,
                           B4BDF00Data* pkData, int iMode);
class B4BDF00Data
{
  public:
    float FUN_004bcdb0(int iIndex);
    float GetScaledValue(void* pvActor, float fValue, bool bFlag);

    int unk00;
    int unk04;
    B4BDF00Form* m_pkForm;
};
extern float DAT_01012054;
extern double DAT_01012060;
struct BookForm
{
    unsigned int FUN_00401170();
    float FUN_004be060();
};
unsigned int __cdecl FUN_004873d0(BookForm*);
float __cdecl FUN_00646360(unsigned short, float);
void __cdecl FUN_00476b20(float);
struct ItemChangeCalc
{
    int unknown00;
    int unknown04;
    BookForm* item;
    float FUN_004bcdb0(int);
    void UpdateItemChange(int unused);
};
struct NewExtraList
{
    virtual ~NewExtraList();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NewExtraList();
};
struct ExtraListFlagger
{
    void SetFlagBits(bool, bool);
};
struct ExtraListDeleter
{
    virtual ~ExtraListDeleter();
};
struct ItemChange_004be3d0 : public InventoryStackRecord
{
    void SetExtraListFlag(bool abNew, bool abFlag, bool abDelete);
};
struct RefBase_4bf330
{
    TESBoundObject* GetBaseObj_44ddc0();
};
struct Extra_4bf330
{
    char GetSlot_42de90();
    void Clear_42dec0();
    bool IsEmpty();
    short GetCount_418770();
    int GetVal_40fe20();
};
struct ExtraList_4bf330
{
    Extra_4bf330* item;
    ExtraList_4bf330* next;
    ~ExtraList_4bf330();
    Extra_4bf330*& GetItem();
    ExtraList_4bf330* GetNext();
    bool IsEmpty();
    void Remove(Extra_4bf330* const& item);
};
struct Change_4bf330
{
    ExtraList_4bf330* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    ~Change_4bf330();
    int GetCount_726070();
};
struct ChangeList_4bf330
{
    void Remove(Change_4bf330* const& item);
};
struct Inv_4bf330
{
    ChangeList_4bf330* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    Change_4bf330* FUN_004bfba0(TESBoundObject*, int, int);
    void ClearExtraForSlot(RefBase_4bf330* apRef, int aiSlot);
};
extern const char g_inventoryChangesSourceFilename[];
struct InventoryIterator
{
    ~InventoryIterator();
};
struct ExtraListTyped
{
    char GetListType();
};
struct ExtraListNode
{
    ExtraListTyped** GetItem();
    ExtraListNode* GetNext();
};
struct ItemChangeLists : public InventoryStackRecord
{
    ExtraListNode* GetExtraLists();
};
struct InventoryChangesIter : public InventoryChanges
{
    InventoryIterator* CreateIterator();
    InventoryStackRecord* NextItem(InventoryIterator* apIter);
    InventoryStackRecord* FindEntryWithExtraListType(int aiType);
};
struct TESForm;
struct TESBoundObject;
int __fastcall FNV_GetFormType(TESForm*);
struct ContEntry4c6ba0
{
    int count;
    TESBoundObject* pObj;
};
struct ContNode4c6ba0
{
    ContEntry4c6ba0** FUN_006815c0();
    ContNode4c6ba0* FUN_00726070();
};
struct Container4c6ba0
{
    ContNode4c6ba0* FUN_00717e50();
    bool FUN_00481eb0(TESBoundObject*);
};
struct Change4c6ba0
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    int FUN_00726070();
};
struct ChangeNode4c6ba0
{
    Change4c6ba0** FUN_006815c0();
    ChangeNode4c6ba0* FUN_00726070();
};
struct Inv4c6ba0
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0* FUN_004bffb0();
    Change4c6ba0* FUN_004bfba0(TESBoundObject*, int, int);
    TESBoundObject* FindFirstItemOfType(int aType, int* apCount);
};
extern float g_fResetValue;
class FUN_004c6d40_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
    float m_0c;

    int CallA(int a1, int* pCount);
    void CallB(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
    void ResetAndProcess(int a1, unsigned char a2, int a3);
};
struct NiPoint3_ext : NiPoint3
{
    NiPoint3_ext();
    NiPoint3_ext& _ref_0063c8a0(const NiPoint3&);
};
struct NiPoint3b : NiPoint3
{
    NiPoint3b(float, float, float);
};
struct NiMatrix3Helper
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void _ref_006815c0();
    void FUN_00a59540(float, float, float);
    NiPoint3 _ref_004b4500(const NiPoint3&);
};
struct PlacedRef : TESObjectREFR
{
    void* _ref_00575d70(int, bool, bool);
    ExtraDataList* _ref_005d43c0();
};
struct PlacedExtra
{
    void _ref_00419ad0(unsigned short);
};
struct DataHandler
{
    PlacedRef* _ref_004698a0(void*, const NiPoint3&, const NiPoint3&, TESObjectCELL*, void*);
};
extern DataHandler* g_dataHandler;
struct Placement
{
    PlacedRef* PlaceObject(PlacedRef*, void*, int, int, NiPoint3*, NiPoint3*);
};
void* __cdecl operator new(unsigned int);
struct Weapon;
struct Extra;
struct Item;
struct ItemList;
struct BaseNode;
struct ActorStand;
struct Stats
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float vc(int);
    float FUN_0066ef50(int);
    int FUN_0066ef20(int);
};
struct ProcessStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
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
    virtual bool v388();
};
struct ActorStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool v100();
    int unk4;
    int unk8;
    int unkc;
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
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
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
    int unkf8;
    int unkfc;
    Stats stats;
    ProcessStand* FUN_008d8520();
    float GetFatigueRatio();
    bool FUN_008bc9d0(Weapon*, bool);
};
struct Form
{
    int FUN_00401170();
};
struct ValueComp
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual unsigned short v10();
};
struct AmmoComp
{
    virtual void v0();
    virtual void v4();
    virtual float v8(int);
};
struct Ammo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    AmmoComp damage;
};
struct AmmoLink
{
    int unk00, unk04;
    Ammo* FUN_00726070();
};
struct Weapon : Form
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    AmmoLink ammo;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    ValueComp value;
    int FUN_00522c80();
    int GetUnk15C();
    int FUN_00446390();
};
struct Extra
{
    void* GetExtraData(int);
    float FUN_004186f0();
    bool FUN_00418b10();
};
struct FUN_0096a2d0
{
    Extra* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    Extra*& FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_005ae3d0(Extra**);
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
struct FUN_0076b630 : FUN_004459e0
{
    FUN_0096a2d0* extras;
    int count;
    Weapon* weapon;
    FUN_0076b630();
    FUN_0096a2d0* FUN_00559450();
    float FUN_004bd350();
    bool FUN_004bcb70();
    ItemList* FUN_00726070();
    Weapon* FUN_0044ddc0();
    void FUN_006ecd40(int);
};
struct ItemList
{
    FUN_0076b630* item;
    ItemList* next;
    FUN_0076b630*& FUN_006815c0();
    ItemList* FUN_00726070();
    bool FUN_008256d0();
};
struct BaseItem
{
    int count;
    Weapon* form;
};
struct BaseNode
{
    BaseItem* item;
    BaseNode* next;
    BaseItem*& FUN_006815c0();
    BaseNode* FUN_00726070();
};
struct Container
{
    BaseNode* FUN_00717e50();
    bool FUN_00481eb0(Weapon*);
};
struct Target
{
    ItemList* changes;
    ActorStand* owner;
    Container* FUN_004bffb0();
    FUN_0076b630* FUN_004c8c10(int, int);
    FUN_0076b630* FUN_004bfba0(Weapon*, bool, int);
    FUN_0076b630* FindInventoryItem(Weapon*, bool*);
    int FUN_004c8f30(Weapon*);
    FUN_0076b630* SelectBestWeapon(ActorStand*, float*, int, bool);
};
unsigned int __cdecl FUN_004873d0(Weapon*);
float __cdecl ComputeWeaponDamage(ActorStand*, Weapon*, float, int, FUN_0076b630*, FUN_0076b630*);
float __cdecl ScaleByGameSetting(float, int, int);
void* __cdecl operator new(unsigned int);
struct ContainerView
{
    unsigned int CopyUniqueObjects();
};
struct Product
{
    unsigned int unk00, unk04, unk08, unk0c;
    ContainerView* container;
    unsigned int unk14, unk18, unk1c, unk20, unk24;
    Product();
};
extern const char DAT_01020778[];
struct OwnerProduct
{
    ContainerView* FUN_004bffb0();
    Product* FUN_004ca200();
};
extern const double DAT_01020758;
extern char* DAT_011dea3c;
extern char DAT_01183128[];
extern char DAT_01183a34[];
bool __fastcall FUN_004d1360(char*);
float __cdecl FUN_0048ebc0(void*, bool);
void __cdecl FUN_005e58f0(int, char*, float*);
int __cdecl FUN_00ec43fb(void*, int, const char*, const char*, int);
struct ObjectForm
{
    int FUN_00401170();
    float FUN_004be380(unsigned char);
};
struct InventoryEntry
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    ObjectForm* m_pItemObject;
    bool FUN_004bddd0(bool);
    unsigned char HasEffect(int);
    int FUN_0044ddc0();
};
struct InventoryNode
{
    InventoryEntry** FUN_006815c0();
    InventoryNode* FUN_00726070();
    bool FUN_008256d0();
};
struct ActorProcessView
{
    BaseProcess* FUN_008d8520();
};
struct InventoryListView
{
    InventoryNode* first;
    int FUN_004c8f30(int);
    float GetInventoryWeight(ActorProcessView*);
};
struct FUN_004d43c0_cls
{
    ContNode* m_pFirstNode;
    int FindItemIndex(int a1, InventoryItemEntry* a2);
};
int __fastcall FUN_0044ddc0(InventoryItemEntry* item);
ContNode* __fastcall FUN_00559450(InventoryItemEntry* item);
struct ItemExtraNode;
struct ChangeEntry
{
    int FUN_0044ddc0();
    ItemExtraNode* FUN_00559450();
};
struct ItemChangeNode
{
    ChangeEntry** _ref_006815c0();
    ItemChangeNode* _ref_00726070();
};
struct ItemExtraNode
{
    int* _ref_006815c0();
    ItemExtraNode* _ref_00726070();
};
struct ItemChangeList
{
    ItemChangeNode* first;
    int GetExtraValueAtPosition(int form, int position);
};
struct Entry_004d4b00
{
    ~Entry_004d4b00();
    int FUN_0044ddc0();
};
struct Iterator_004d4b00
{
    ~Iterator_004d4b00();
};
struct Output_004d4b00
{
    void FUN_005ae3d0(Entry_004d4b00**);
};
struct Host_004d4b00
{
    Iterator_004d4b00* FUN_004ca200();
    Entry_004d4b00* GetNextInventoryEntry(Iterator_004d4b00*);
    void FindEntriesByType(int type, Output_004d4b00* output);
};
struct Record90
{
    unsigned int id;
    unsigned char type;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char version;
};
struct Load90
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    Record90* FUN_004fd3c0();
    unsigned int FUN_00825c00();
    unsigned char FUN_008df040();
    void FUN_00857bd0(unsigned int);
};
extern Load90* g_TESSaveLoadGame;
TESForm* FUN_004839c0(unsigned int);
void FNV_Warning(const char*, ...);
unsigned short FUN_004efaa0();
struct Seq90
{
    void FUN_004efbc0(float);
    float FUN_00508100();
};
struct Idle90
{
    unsigned int FUN_0044ddc0();
};
struct Ptr90
{
    Idle90* p;
    void FUN_0066b0d0(Idle90*);
    operator Idle90*() const;
};
struct Found90
{
    void FUN_0081c470(bool, float);
    void FUN_00621b20(float);
};
struct Caster90
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
    virtual int v13();
    Found90* FUN_00726070();
};
struct Actor90 : MobileObject
{
    Caster90 caster;
};
struct Obj90
{
    virtual void v0();
    void* GetControllers() const;
};
struct Node90
{
    Obj90* FUN_0045bc00(unsigned int);
};
struct Named90
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node90* v3();
};
struct Manager90
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
    virtual Named90* v35(void*);
    Manager90* GetStringAtOffset();
    Seq90* FUN_0047a520(void*);
    void FUN_0048fef0(float);
    void FUN_0047aab0(Seq90*, int, int, float, float, int);
    void FUN_0047aa40(bool);
};
void* FUN_00499b70();
void* FUN_00499b80();
extern int DAT_011f36ac;
Manager90* FUN_00653270(const int*, void*);
struct Animation90 : Animation
{
    void LoadFromSave(TESObjectREFR*);
    void FUN_004974a0();
    void FUN_004955c0(int, unsigned short, int, float, char);
    void FUN_00496080(int, float);
    void FUN_0049bca0(float, void*, bool);
    Manager90* FUN_00496940();
};
Idle90* LoadIdleAnimation(Actor90*, Animation90*, float);
struct ExtraDataListCopy : public ExtraDataList
{
    ExtraDataListCopy();
    void CopyFrom(ExtraDataList* source);
};
struct FUN_004bc650_shell : public InventoryStackRecord
{
    InventoryStackRecord* FUN_004bc650(InventoryStackRecord* other);
};
struct ExtraList_4bd5c0
{
    ExtraList_4bd5c0();
    virtual ~ExtraList_4bd5c0();
    void CopyFrom(void* src);
    void* pHead;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct ExtraListList_4bd5c0
{
    ExtraList_4bd5c0* m_item;
    ExtraListList_4bd5c0* m_pkNext;
    ExtraListList_4bd5c0();
    ExtraList_4bd5c0** GetItem();
    void AddHead(ExtraList_4bd5c0*& item);
    void Remove(ExtraList_4bd5c0* const& item);
};
struct ItemChange_4bd5c0
{
    ExtraListList_4bd5c0* m_pExtraDataLists;
    int m_iCountChange;
    void* m_pItemObject;
    void FUN_004bd5c0(void* extra);
};
struct RefSlot
{
    TESBoundObject* FUN_0044ddc0();
    int FUN_00726070();
};
struct PlayerSlot
{
    unsigned int GetAtIfValid(int);
    void SetIdleAt(int, void*);
};
struct ExtraSlot
{
    bool HasOnlyAllowedExtraData(int);
    void SetHotKey(unsigned char);
    void FUN_00419ad0(int);
};
struct ChangeSlot : InventoryStackRecord
{
    int FUN_00726070();
    int FUN_004bc8f0(bool);
    bool FUN_004bddd0(bool);
};
struct InventorySlot : InventoryChanges
{
    void ClearExtraForSlot(RefSlot*, int);
    ChangeSlot* FUN_004bfba0(TESBoundObject*, int, int);
    void SetInventorySlotExtraData(RefSlot*, ExtraDataList*, int);
};
struct EquipForm;
struct EquipExtra;
struct EquipEntry;
struct EquipActor;
struct EquipAnim;
struct EquipList
{
    EquipExtra* item;
    EquipList* next;
    EquipList();
    EquipExtra** FUN_006815c0();
    EquipList* FUN_00726070();
    bool FUN_005f65d0(EquipExtra*&);
    void FUN_005ae3d0(EquipExtra*&);
    void FUN_00470470();
};
struct EquipExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    EquipExtra();
    bool FUN_00418750();
    bool CompareList(EquipExtra*);
    short FUN_00418770();
    void CopyList(EquipExtra*);
    void FUN_00419ad0(unsigned short);
    signed char GetExtraByteValue();
    void FUN_0042dec0();
    void SetWornState(bool, bool);
    bool FUN_00418b10();
    void FUN_0041ab70(bool);
};
struct EquipEntry
{
    EquipList* extras;
    int count;
    EquipForm* form;
    EquipEntry(EquipForm*, int);
    ~EquipEntry();
    int FUN_004bc8f0(bool);
    int FUN_004bc980();
    bool FUN_004bddd0(bool);
    int FUN_00726070();
    EquipForm* FUN_0044ddc0();
};
struct EquipBiped
{
    bool FUN_00480d10();
    bool FUN_004c0bd0();
    bool FUN_00480d30();
};
struct EquipForm
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
    EquipBiped biped;
    int FUN_00401170();
    bool FUN_004c0bf0();
    float FUN_004e4620();
};
EquipBiped* __cdecl GetFormAsBipedModel(EquipForm*);
struct EquipContainer
{
    int FUN_00482a90(EquipForm*);
};
struct EquipChangeList
{
    void FUN_00905820(EquipEntry*&);
};
struct EquipProcess
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual EquipEntry* v148();
    virtual EquipEntry* v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool v160(EquipEntry*, int, int);
    virtual void v164();
    virtual bool v168(EquipEntry*);
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
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
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468(int);
    virtual void v46c();
    virtual void v470();
    virtual bool v474(int);
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4(EquipActor*);
};
struct EquipAnim
{
    void FUN_004c0c90(float);
};
struct EquipActor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(int);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
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
    virtual int v1d0();
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
    EquipProcess* process;
    EquipProcess* FUN_008d8520();
    void FUN_008b0b00(int);
    EquipAnim* FUN_008b70d0();
    void SetField1F0(EquipForm*);
    void FUN_00571760(EquipForm*);
    void FUN_004534f0(EquipForm*);
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};
bool __cdecl FUN_008c7aa0();
EquipActor* __cdecl FUN_0047b200();
struct EquipQueue
{
    void FUN_0087b360(EquipActor*, EquipForm*);
};
EquipQueue* __cdecl FUN_004537b0();
void __cdecl ApplyPerkModifiers(int, EquipActor*, ...);
struct EquipInv
{
    EquipChangeList* changes;
    EquipActor* owner;
    void FUN_004bf0e0();
    EquipEntry* FUN_004bfba0(EquipForm*, int, int);
    EquipContainer* FUN_004bffb0();
    void AddItemToInventory(EquipForm*, int, EquipActor*, EquipExtra*, bool, bool);
};
extern const char g_inventoryChangesSourceFilename[];
struct BoundShell : TESBoundObject
{

    int FUN_00401170();

    bool FUN_004c0bf0();

    int FUN_00482a90();
};
struct ExtraShell : ExtraDataList
{

    ExtraShell();

    bool FUN_00418750();

    short FUN_00418770();

    bool CompareList(ExtraShell*);

    void FUN_00419ad0(int);

    void CopyList(ExtraShell*);

    signed char GetExtraByteValue();

    void FUN_0042dec0();
};
struct ExtraNodeShell : BSSimpleList<ExtraDataList*>
{

    ExtraNodeShell();

    ExtraShell** _ref_006815c0();

    ExtraNodeShell* _ref_00726070();

    bool FUN_005f65d0(ExtraShell**);

    void FUN_005ae3d0(ExtraShell**);
};
struct ItemShell : InventoryStackRecord
{

    ItemShell(BoundShell*, int);

    int FUN_004bc8f0(bool);

    int FUN_004bc980();

    bool FUN_004bddd0(bool);
};
struct ItemListShell : BSSimpleList<InventoryStackRecord*>
{

    void _ref_00905820(InventoryStackRecord**);
};
struct RefShell : TESObjectREFR
{

    void Invalidate(unsigned mask)
    {

        typedef void(__thiscall * Callback)(TESObjectREFR*, unsigned);

        ((Callback)(*(void***)this)[18])(this, mask);
    }
};
struct ChangesShell : InventoryChanges
{

    ItemShell* FUN_004bfba0(BoundShell*, int, int);

    BoundShell* FUN_004bffb0(BoundShell*);

    void AddItemExtraData(BoundShell*, int, int, ExtraShell*, ExtraNodeShell**);
};
struct TESHealthForm
{
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual unsigned int GetHealth();
};
struct W20Form;
struct W20Ref;
struct W20AmmoExtra
{
    unsigned int unk00, unk04, unk08, unk0c;
    int count;
};
struct W20Extra
{
    virtual ~W20Extra();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    W20Extra();
    float FUN_004186f0();
    bool FUN_00418ba0();
    bool IsEmpty();
    short FUN_00418770();
    void FUN_00419ad0(short);
    void FUN_00419fb0(float);
    void CopyListForContainer(W20Extra*, bool);
    bool CompareListForContainer(W20Extra*, bool, bool);
    W20Form* GetOwner();
    void FUN_0041aed0();
    void RemoveExtra24();
    void SetWornState(bool, bool);
    void FUN_0041c7f0(W20Ref*);
    W20AmmoExtra* GetExtraAmmo();
    void SetOwnership(int, int);
};
struct W20ExtraList
{
    W20Extra* data;
    W20ExtraList* next;
    W20ExtraList();
    ~W20ExtraList();
    W20Extra** _ref_006815c0();
    W20ExtraList* _ref_00726070();
    void Remove(W20Extra**);
    void AddHead(W20Extra**);
    bool IsEmpty();
};
struct W20Entry
{
    W20ExtraList* extras;
    int count;
    W20Form* form;
    W20Entry(W20Form*, int);
    ~W20Entry();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    W20Entry* _ref_00726070();
};
struct W20EntryList
{
    void Remove(W20Entry**);
    void AddTail(W20Entry**);
};
struct W20Form : TESBoundObject
{
    int FNV_GetFormType();
    int GetWeaponType();
    bool FUN_004c0bf0();
    float GetEffectValue(int, unsigned char);
    W20Form* GetCurrentAmmo(W20Ref*);
};
struct W20Ref
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void v48(int);
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual bool v100();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual const char* v130();
    W20Form* FUN_007af430();
    W20Extra* GetExtra();
    unsigned int GetFormID();
    void FUN_00568bd0(float);
    float GetScale();
    bool FUN_005653d0();
};
extern W20Ref* g_thePlayer;
struct W20Inventory
{
    W20EntryList* entries;
    W20Ref* owner;
    float weight;
    float previous;
    bool dirty;
    W20Entry* FUN_004bfba0(W20Form*, bool, int);
    void FUN_004c29a0(W20Form*, int, int);
    void FUN_004c1c90(W20Ref*, int, int, bool);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void FNV_Warning(const char*, ...);
int FUN_004873d0(W20Form*);
unsigned int FUN_0042f5a0(unsigned int, unsigned int);
struct AddForm;
struct AddRef;
struct AddProcess;
struct AddExtra;
struct AddEntry;
struct AddAmmoExtra
{
    int unk00, unk04, unk08, unk0c;
    int count;
};
struct AddExtra
{
    virtual ~AddExtra();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    AddExtra();
    AddAmmoExtra* GetExtraAmmo();
    AddRef* FUN_00418660();
    void FUN_0041aed0();
    void SetWornState(bool, bool);
    AddRef* FUN_0041c8d0();
    void FUN_0041c7f0(AddRef*);
    bool IsEmpty();
    void* FUN_00418800();
    bool FUN_00418750();
    short FUN_00418770();
    void FUN_00419ad0(short);
    bool CompareListForContainer(AddExtra*, bool, bool);
};
struct AddNode
{
    AddExtra* data;
    AddNode* next;
    AddNode();
    AddExtra*& FUN_006815c0();
    AddNode* FUN_00726070();
    void _ref_005ae3d0(AddExtra*&);
    void _ref_00905330(AddExtra* const&);
    int _ref_005ae380();
    bool _ref_008256d0();
};
struct AddEntry
{
    AddNode* extras;
    int count;
    AddForm* form;
    AddEntry(AddForm*, int);
    ~AddEntry();
    int FUN_00726070();
    void FUN_006ecd40(int);
    bool FUN_004bddd0(bool);
    AddForm* FUN_0044ddc0();
};
struct AddProcess
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual AddEntry* ammoA();
    virtual AddEntry* p();
};
struct AddRef
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool isActor();
    AddProcess* FUN_008d8520();
    AddExtra* FUN_005d43c0();
};
struct AddForm
{
    int FUN_00401170();
    bool FUN_004c0bf0();
    AddForm* _ref_00525980(AddRef*);
};
struct AddContainer
{
    int _ref_00482a90(AddForm*);
};
struct AddChanges
{
    void _ref_00905330(AddEntry* const&);
};
struct AddInventory
{
    AddChanges* changes;
    AddRef* owner;
    float weight, previousWeight;
    bool dirty;
    AddEntry* FUN_004bfba0(AddForm*, int, int);
    void FUN_004c3380(AddEntry*, bool);
    AddContainer* FUN_004bffb0();
    void FUN_004c29a0(AddForm*, AddExtra*, int);
};
extern AddRef* addPlayer;
extern float DAT_01012054;
bool __cdecl FUN_00705020();
bool __cdecl FUN_00705000();
int __cdecl FUN_00679ba0(void*);
struct Inv4c6a10
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0* FUN_004bffb0();
    Change4c6ba0* FUN_004bfba0(TESBoundObject*, int, int);
    TESBoundObject* FindInventoryItemByType(int aType, int* apCount);
};
class TESAmmo : public TESBoundObject
{
};
extern float DAT_01015f5c;
struct AmmoScorer
{
    float FUN_005f0d60(TESAmmo*);
};
struct AmmoContainerEntry
{
    int count;
    TESBoundObject* object;
};
struct AmmoContainerNode
{
    AmmoContainerEntry** FUN_006815c0();
    AmmoContainerNode* FUN_00726070();
};
struct AmmoContainer
{
    AmmoContainerNode* FUN_00717e50();
    bool FUN_00481eb0(TESAmmo*);
    int FUN_00482a90(TESAmmo*);
};
struct AmmoInventory
{
    ItemList* changes;
    AmmoContainer* FUN_004bffb0();
    FUN_0076b630* FUN_004bfba0(TESAmmo*, int, int);
    FUN_0076b630* FindBestAmmoChange(AmmoScorer*, int);
};
struct Scope64
{
    int value;
    Scope64(int, int, const char*, int);
    ~Scope64();
};
struct Form64
{
    int FUN_00401170();
    int FUN_00446390();
};
struct Extra64
{
    bool FUN_00418750();
    bool HasOnlyAllowedExtraData(int);
    short FUN_00418770();
    void FUN_00419ad0(int);
    bool FUN_00418ab0(int);
};
struct ExtraNode64
{
    Extra64* data;
    ExtraNode64* next;
    ExtraNode64();
    Extra64** FUN_006815c0();
    ExtraNode64* FUN_00726070();
    unsigned int FUN_005ae380();
    void FUN_005ae3d0(Extra64* const&);
    void FUN_00905820(Extra64* const&);
};
struct Change64
{
    ExtraNode64* extras;
    int count;
    Form64* form;
    Change64();
    Change64(Form64*, int);
    int FUN_00726070();
    ExtraNode64* FUN_00559450();
    int CountAndPruneEntries();
    int FUN_004bc8f0(int);
    void FUN_00403550(Form64*);
    void* FUN_004bde40();
    int FindFirstNonNegativeValue();
    void* GetExtraForm();
    Form64* FUN_0044ddc0();
    bool FUN_004bddd0(int);
    bool FUN_004bcb70();
};
struct BaseItem64
{
    int count;
    Form64* form;
};
struct BaseNode64
{
    ~BaseNode64();
    BaseItem64** FUN_006815c0();
    BaseNode64* FUN_00726070();
    void FUN_00470470();
};
struct BaseContainer64
{
    BaseNode64* CopyUniqueObjects();
    int FUN_00482a90(Form64*);
    bool FUN_00481eb0(Form64*);
};
struct ChangeNode64
{
    Change64** FUN_006815c0();
    ChangeNode64* FUN_00726070();
};
struct Inventory64
{
    ChangeNode64* changes;
    BaseContainer64* FUN_004bffb0();
    Change64* FUN_004bfba0(Form64*, int, int);
    void* FUN_00726070();
    Change64* FUN_004c94f0(int);
};
extern const char DAT_01020778[];
struct InventoryTrace4ca330
{
    unsigned int m_slot;
    InventoryTrace4ca330(int category, int enabled, const char* file, int line);
    ~InventoryTrace4ca330();
};
struct InventoryForm4ca330
{
    int FUN_00401170();
    int FUN_00446390();
};
struct InventoryExtra4ca330
{
    bool HasOnlyAllowedExtraData(int flag);
    bool FUN_00418ab0(int flag);
    short FUN_00418770();
    unsigned char FUN_00418750();
    void FUN_00419ad0(int count);
};
struct InventoryNode4ca330
{
    InventoryExtra4ca330** FUN_006815c0();
    InventoryNode4ca330* FUN_00726070();
    int FUN_005ae380();
};
struct InventoryRecord4ca330
{
    InventoryNode4ca330* m_extraList;
    InventoryForm4ca330* m_form;
    unsigned int m_flags;
};
struct InventoryChange4ca330
{
    InventoryNode4ca330* m_extraList;
    int m_quantity;
    InventoryForm4ca330* m_form;

    int CountAndPruneEntries();
    int FUN_004bc8f0(int ignoreEquipped);
    int FindFirstNonNegativeValue();
    int GetExtraForm();
    int FUN_004bde40();
    bool FUN_004bddd0(int flag);
    bool FUN_004bcb70();
    InventoryNode4ca330* FUN_00559450();
    InventoryForm4ca330* FUN_0044ddc0();
    int FUN_00726070();
};
struct InventoryContainer4ca330
{
    int FUN_00482a90(InventoryForm4ca330* form);
    bool FUN_00481eb0(InventoryForm4ca330* form);
};
struct InventoryList4ca330
{
    InventoryRecord4ca330** FUN_006815c0();
    InventoryList4ca330* FUN_00726070();
};
struct InventoryChangeNode4ca330
{
    InventoryChange4ca330** FUN_006815c0();
    InventoryChangeNode4ca330* FUN_00726070();
};
struct InventoryBaseHost4ca330
{
    InventoryChangeNode4ca330* first;
    InventoryChange4ca330* FUN_004bfba0(InventoryForm4ca330* form, int create, int unused);
    InventoryContainer4ca330* FUN_004bffb0();
    InventoryList4ca330* FUN_00726070();
};
struct InventoryOutputExtras4ca330
{
    void* m_pFirstNode;
    void* m_pTail;
    InventoryOutputExtras4ca330();
    void FUN_005ae3d0(InventoryExtra4ca330** extra);
    void FUN_00905820(InventoryExtra4ca330** extra);
};
struct InventoryOutput4ca330
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330* m_form;
    InventoryOutput4ca330();
    void FUN_00403550(InventoryForm4ca330* form);
};
struct InventoryOutputFromForm4ca330
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330* m_form;
    InventoryOutputFromForm4ca330(InventoryForm4ca330* form, int count);
};
struct InventoryCursor4ca330
{
    unsigned int m_uiContentCount;
    InventoryList4ca330* m_firstNode;
    unsigned int m_unknown08;
    InventoryOutput4ca330* m_pTileTemplate;
    InventoryContainer4ca330* m_sourceContainer;
    InventoryChangeNode4ca330* m_secondPhase;
    int m_phase;
    InventoryNode4ca330* m_activeExtras;
    InventoryNode4ca330* m_extrasToCount;
    InventoryNode4ca330* m_extrasToCopy;
};
struct Obj4cb320;
bool __cdecl IsCountable4cb320(Obj4cb320* apObj);
struct ContEntry4cb320
{
    int count;
    Obj4cb320* pObj;
};
struct ContNode4cb320
{
    bool IsEmpty();
    ContEntry4cb320** GetItem();
    ContNode4cb320* GetNext();
};
struct Cont4cb320
{
    ContNode4cb320* GetHead();
    bool HasObjectOfType(Obj4cb320*);
};
struct Change4cb320
{
    void* pExtraLists;
    int m_iCountChange;
    Obj4cb320* pObj;
    int GetCount();
};
struct ChangeNode4cb320
{
    bool IsEmpty();
    Change4cb320** GetItem();
    ChangeNode4cb320* GetNext();
};
struct Inv4cb320
{
    ChangeNode4cb320* m_pEntryList;
    Cont4cb320* GetContainer();
    Change4cb320* FindChange(Obj4cb320*, int, int);
    int GetCountableItemCount();
};
struct CO4cb4b0
{
    int count;
    TESObject* pObj;
};
struct CN4cb4b0
{
    bool _ref_008256d0();
    CO4cb4b0** _ref_006815c0();
    CN4cb4b0* _ref_00726070();
};
struct Cont4cb4b0
{
    CN4cb4b0* _ref_00717e50();
};
struct IC4cb4b0
{
    int unk00;
    int count;
    TESObject* pObj;
};
struct IN4cb4b0
{
    bool _ref_008256d0();
    IC4cb4b0** _ref_006815c0();
    IN4cb4b0* _ref_00726070();
};
bool __cdecl FUN_00481f10(TESObject*);
struct Inv4cb4b0
{
    IN4cb4b0* m_pEntryList;
    Cont4cb4b0* _ref_004bffb0();
    void _ref_004c37d0(int, TESObject*, int, int, int, int, int, int, int, int, int, int);
    void FUN_004cb4b0(int a1, int a2, int a3);
};
namespace InventoryCopy {
struct FUN_004bc550;
typedef FUN_004bc550 Item;
struct FUN_00410360;
typedef FUN_00410360 Extra;
struct ExtraNode;
struct BaseNode;
struct ItemNode;
struct Container;
struct Inventory;
struct FormView
{
    int FUN_00401170();
};
struct CopiedForm
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
    virtual void v108(TESBoundObject*);
};
struct FUN_00410360
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void* GetExtraData(int);
    void RemoveExtra(void*, int);
    void CopyListForContainer(FUN_00410360*, int);
    void AddExtra(void*);
};
typedef FUN_00410360 Extra;
struct ExtraNode
{
    Extra** FUN_006815c0();
    ExtraNode* FUN_00726070();
    int FUN_005ae380();
    void FUN_00905820(Extra**);
};
struct FUN_004bc550
{
    ExtraNode* list;
    int count;
    TESBoundObject* form;
    FUN_004bc550(TESBoundObject*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
    void FUN_004bcd10();
    void* FUN_004bde40();
};
typedef FUN_004bc550 Item;
struct BaseEntry
{
    int count;
    TESBoundObject* form;
};
struct BaseNode
{
    BaseEntry** FUN_006815c0();
    bool FUN_008256d0();
    BaseNode* FUN_00726070();
};
struct ItemNode
{
    Item** FUN_006815c0();
    bool FUN_008256d0();
    ItemNode* FUN_00726070();
};
struct Container
{
    BaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
};
struct Registry
{
    void FUN_004603b0(CopiedForm*);
    void FUN_00861780(CopiedForm*);
};
extern Registry* DAT_011c3f2c;
extern Registry* DAT_011de45c;
Inventory* __cdecl FUN_004bf220(void*);
void* __cdecl FUN_004826d0(TESBoundObject*);
CopiedForm* __cdecl FUN_00465110(int);
void __cdecl FUN_004ce300(CopiedForm*, int);
struct Inventory
{
    ItemNode* head;
    Container* FUN_004bffb0();
    Item* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004c3380(Item*, int);
    void FUN_004cd9c0(void*, void*);
};
// @fnv 0x004cd9c0
void Inventory::FUN_004cd9c0(void* source, void* destination)
{
    if (!destination || !source)
        return;
    TESBoundObject* formSlot11 = 0;
    Item* copySlot14 = 0;
    Inventory* targetSlot4 = 0;
    targetSlot4 = FUN_004bf220(destination);
    if (!targetSlot4)
        return;
    BaseNode* baseSlot45 = FUN_004bffb0()->FUN_00717e50();
    TESLevItem* leveledSlot24 = 0;
    while (baseSlot45 && !baseSlot45->FUN_008256d0())
    {
        formSlot11 = (*baseSlot45->FUN_006815c0())->form;
        leveledSlot24 = dynamic_cast<TESLevItem*>((*baseSlot45->FUN_006815c0())->form);
        if (formSlot11)
        {
            int baseCountSlot31 = FUN_004bffb0()->FUN_00482a90(formSlot11);
            Item* itemSlot25 = FUN_004bfba0(formSlot11, 1, 0);
            int totalSlot2 = 0;
            int magnitudeSlot60 = baseCountSlot31;
            if (magnitudeSlot60 < 0)
                magnitudeSlot60 *= -1;
            if (itemSlot25)
                totalSlot2 += magnitudeSlot60 + itemSlot25->FUN_00726070();
            else
                totalSlot2 += magnitudeSlot60;
            if (totalSlot2 > 0)
            {
                CopiedForm* clone = 0;
                if (FUN_004826d0(formSlot11))
                {
                    clone = FUN_00465110(((FormView*)formSlot11)->FUN_00401170());
                    clone->v108(formSlot11);
                    FUN_004ce300(clone, 0);
                    DAT_011c3f2c->FUN_004603b0(clone);
                    DAT_011de45c->FUN_00861780(clone);
                    int quantity = baseCountSlot31;
                    if (itemSlot25)
                        quantity += itemSlot25->FUN_00726070();
                    copySlot14 = new Item((TESBoundObject*)clone, quantity);

                    if (itemSlot25 && itemSlot25->FUN_00559450() && itemSlot25->FUN_00559450()->FUN_005ae380())
                    {
                        ExtraNode* nodeA = itemSlot25->FUN_00559450();
                        if (nodeA && *nodeA->FUN_006815c0())
                        {
                            while (nodeA && *nodeA->FUN_006815c0())
                            {
                                Extra* extraASlot11 = new Extra;
                                void* removedASlot21 = (*nodeA->FUN_006815c0())->GetExtraData(0xd);
                                if (removedASlot21)
                                    (*nodeA->FUN_006815c0())->RemoveExtra(removedASlot21, 0);
                                extraASlot11->CopyListForContainer(*nodeA->FUN_006815c0(), 1);
                                copySlot14->FUN_00559450()->FUN_00905820(&extraASlot11);
                                if (removedASlot21)
                                    (*nodeA->FUN_006815c0())->AddExtra(removedASlot21);
                                nodeA = nodeA->FUN_00726070();
                            }
                        }
                    }
                }
                else
                {
                    copySlot14 = new Item(formSlot11, totalSlot2);
                    if (itemSlot25 && itemSlot25->FUN_00559450() && itemSlot25->FUN_00559450()->FUN_005ae380())
                    {
                        ExtraNode* nodeB = itemSlot25->FUN_00559450();
                        if (nodeB && *nodeB->FUN_006815c0())
                        {
                            while (nodeB && *nodeB->FUN_006815c0())
                            {
                                Extra* extraB = new Extra;
                                extraB->CopyListForContainer(*nodeB->FUN_006815c0(), 1);
                                copySlot14->FUN_00559450()->FUN_00905820(&extraB);
                                nodeB = nodeB->FUN_00726070();
                            }
                        }
                    }
                }
                targetSlot4->FUN_004c3380(copySlot14, 1);
            }
        }
        baseSlot45 = baseSlot45->FUN_00726070();
    }
    Item* changedSlot20 = 0;
    ItemNode* nodeSlot26 = head;
    while (nodeSlot26 && !nodeSlot26->FUN_008256d0())
    {
        changedSlot20 = *nodeSlot26->FUN_006815c0();
        if (changedSlot20 && changedSlot20->FUN_00726070() > 0)
        {
            formSlot11 = changedSlot20->FUN_0044ddc0();
            changedSlot20->FUN_004bcd10();
            CopiedForm* clone2 = 0;
            if (changedSlot20->FUN_004bde40())
            {
                clone2 = FUN_00465110(((FormView*)changedSlot20->FUN_0044ddc0())->FUN_00401170());
                clone2->v108(changedSlot20->FUN_0044ddc0());
                FUN_004ce300(clone2, 0);
                DAT_011c3f2c->FUN_004603b0(clone2);
                DAT_011de45c->FUN_00861780(clone2);
                copySlot14 = new Item((TESBoundObject*)clone2, changedSlot20->FUN_00726070());
                if (changedSlot20 && changedSlot20->FUN_00559450() && changedSlot20->FUN_00559450()->FUN_005ae380())
                {
                    ExtraNode* nodeC = changedSlot20->FUN_00559450();
                    if (nodeC && *nodeC->FUN_006815c0())
                    {
                        while (nodeC && *nodeC->FUN_006815c0())
                        {
                            Extra* extraCSlot22 = new Extra;
                            void* removedCSlot8 = (*nodeC->FUN_006815c0())->GetExtraData(0xd);
                            if (removedCSlot8)
                                (*nodeC->FUN_006815c0())->RemoveExtra(removedCSlot8, 0);
                            extraCSlot22->CopyListForContainer(*nodeC->FUN_006815c0(), 1);
                            copySlot14->FUN_00559450()->FUN_00905820(&extraCSlot22);
                            if (removedCSlot8)
                                (*nodeC->FUN_006815c0())->AddExtra(removedCSlot8);
                            nodeC = nodeC->FUN_00726070();
                        }
                    }
                }
            }
            else
            {
                copySlot14 = new Item(changedSlot20->FUN_0044ddc0(), changedSlot20->FUN_00726070());
                if (changedSlot20 && changedSlot20->FUN_00559450() && changedSlot20->FUN_00559450()->FUN_005ae380())
                {
                    ExtraNode* nodeD = changedSlot20->FUN_00559450();
                    if (nodeD && *nodeD->FUN_006815c0())
                    {
                        while (nodeD && *nodeD->FUN_006815c0())
                        {
                            Extra* extraD = new Extra;
                            extraD->CopyListForContainer(*nodeD->FUN_006815c0(), 1);
                            copySlot14->FUN_00559450()->FUN_00905820(&extraD);
                            nodeD = nodeD->FUN_00726070();
                        }
                    }
                }
            }
            targetSlot4->FUN_004c3380(copySlot14, 1);
            copySlot14 = 0;
        }
        nodeSlot26 = nodeSlot26->FUN_00726070();
    }
}
}
extern float DAT_010162c0;
struct MoveForm
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
    virtual bool IsQuestItem();
    int FUN_00401170();
};
struct MoveOwner;
struct MoveOwnershipProxy
{
    void* FUN_004216f0();
};
struct MoveExtra
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MoveExtra();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    unsigned int ItemsInList();
    void* FUN_00418660();
    short FUN_00418770();
    void FUN_00419700(void*);
    void FUN_0041aed0();
    void FUN_00419ad0(unsigned short);
};
struct MoveExtraNode
{
    MoveExtra** FUN_006815c0();
    MoveExtraNode* FUN_00726070();
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void FUN_00470470();
    unsigned int FUN_005ae380();
    ~MoveExtraNode();
    static void operator delete(void*);
};
struct MoveItem
{
    MoveExtraNode* head;
    int count;
    TESBoundObject* form;
    MoveItem(TESBoundObject*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    bool FUN_004bddd0(bool);
    bool FUN_004bcb70();
    int FUN_00726070();
    MoveExtraNode* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
    void FUN_004bd5c0(void*);
};
struct MoveItemNode
{
    bool FUN_008256d0();
    MoveItem** FUN_006815c0();
    MoveItemNode* FUN_00726070();
};
struct MoveBaseEntry
{
    int count;
    TESBoundObject* form;
};
struct MoveBaseNode
{
    bool FUN_008256d0();
    MoveBaseEntry** FUN_006815c0();
    MoveBaseNode* FUN_00726070();
};
struct MoveContainer
{
    MoveBaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
    bool FUN_00481eb0(TESBoundObject*);
};
struct MoveOwner
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
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool IsActor();
    MoveOwnershipProxy* FUN_005d43c0();
    void* FUN_007af430();
    void* FUN_00567790();
    unsigned int FUN_008adcf0(TESBoundObject*, bool, bool);
};
extern MoveOwner* inventoryPlayer;
struct MoveFilterResult
{
    bool FUN_005f65d0();
};
struct MoveFilter
{
    MoveFilterResult* FUN_00500940(TESForm* const&);
};
struct MoveFormInfo
{
    bool FUN_00480d90();
};
MoveFormInfo* FUN_00480db0(TESBoundObject*);
bool FUN_00481f10(TESBoundObject*);
int FUN_0048e8a0(TESBoundObject*);
struct MoveString
{
    char* text;
    unsigned short length, capacity;
    MoveString();
    ~MoveString();
    const char* FUN_00559450();
};
struct MoveSetting
{
    const char* FUN_00403df0();
};
extern MoveSetting movePlural_r004cb5f0, moveVerb_r004cb5f0;
const char* FUN_00482720(TESBoundObject*);
void FUN_00406f60(MoveString*, const char*, ...);
void DispatchMessageToSink(const char*, int, const char*, unsigned int, float, int);
void FUN_00704af0();
struct InventoryMove
{
    MoveItemNode* head;
    MoveContainer* FUN_004bffb0();
    MoveItem* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004c0cf0(bool*, TESBoundObject*, int, MoveOwner*, MoveExtra*, bool, bool, MoveItem*, bool*);
    void FUN_004c37d0(MoveOwner*, TESBoundObject*, bool, int, MoveExtra*, int, MoveOwner*, int, int, bool, int,
                      MoveItem*);
    float FUN_004ce380(MoveOwner*, MoveOwner*, bool, bool, bool, bool, int, MoveFilter*);
};
union SETTING_VALUE
{
    float f;
};
template <> class SettingT<GameSettingCollection>
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting31;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting32;
void __cdecl FUN_008ba2f0(ActorValueOwner*, int, float, float, int);
struct WeightExtra
{
    bool FUN_00418ba0();
    bool CheckExtraByType(int);
    short FUN_00418770();
};
struct WeightExtraNode
{
    WeightExtra** FUN_006815c0();
    WeightExtraNode* FUN_00726070();
};
struct WeightWeapon
{
    int GetSlotPointer(int);
};
struct WeightEntry : InventoryStackRecord
{
    unsigned char HasEffect(int);
    int FUN_00726070();
    WeightExtraNode* FUN_00559450();
    WeightWeapon* FUN_0044ddc0();
    int FUN_004bc8f0(bool);
    bool FUN_004bddd0(bool);
};
struct WeightChangeNode
{
    bool FUN_008256d0();
    WeightEntry** FUN_006815c0();
    WeightChangeNode* FUN_00726070();
};
struct WeightBaseEntry
{
    int count_2;
    TESBoundObject* form4;
};
struct WeightBaseNode
{
    bool FUN_008256d0();
    WeightBaseEntry** FUN_006815c0();
    WeightBaseNode* FUN_00726070();
};
struct WeightContainer
{
    WeightBaseNode* FUN_00717e50();
    bool FUN_00481eb0(TESBoundObject*);
};
struct WeightInventory : InventoryChanges
{
    WeightContainer* FUN_004bffb0();
    WeightEntry* FUN_004bfba0(TESBoundObject*, int, int);
    float FUN_004d0900(bool useAmmoWeight);
};
struct ValueForm : TESForm
{
    int FUN_0084e3a0();
};
struct ValueBaseEntry
{
    int count;
    ValueForm* object;
};
struct ValueBaseNode
{
    ValueBaseEntry** FUN_006815c0();
    ValueBaseNode* FUN_00726070();
    bool FUN_008256d0();
};
struct ValueChange : InventoryStackRecord
{
    int FUN_00726070();
};
struct ValueChangeNode
{
    ValueChange** FUN_006815c0();
    ValueChangeNode* FUN_00726070();
    bool FUN_008256d0();
};
struct ValueContainer
{
    ValueBaseNode* FUN_00717e50();
    bool FUN_00481eb0(ValueForm*);
};
struct ValueInventory : InventoryChanges
{
    ValueContainer* FUN_004bffb0();
    ValueChange* FUN_004bfba0(ValueForm*, int, int);
    int FUN_004d0f40(bool includeQuestItems, bool includeType15);
};
int __cdecl FUN_0048e8a0(ValueForm*);
struct Extra4d1440
{
    float FUN_00488d50();
};
struct Entry4d1440
{
    int count;
    TESForm* pObj;
    Extra4d1440* m_pExtraData;
};
struct Node4d1440
{
    bool _ref_008256d0();
    Entry4d1440** _ref_006815c0();
    Node4d1440* _ref_00726070();
};
struct Cont4d1440
{
    Node4d1440* FUN_00717e50();
};
struct List4d1440
{
    int unk00;
    int unk04;
    int unk08;
    List4d1440();
    ~List4d1440();
    void FUN_00482090(float);
    void AddLeveledItemsToChanges(int, InventoryChanges*);
};
struct LevList4d1440
{
    void FUN_00487f70(unsigned short, int, List4d1440*, int);
};
struct LevItem4d1440
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
    LevList4d1440 leveledList;
};
struct Ref4d1440
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    unsigned short FUN_0087f9f0();
    int FUN_00567e10(bool);
};
int __cdecl FUN_00ec7d40(int);
struct Inv4d1440 : public InventoryChanges
{
    Cont4d1440* FUN_004bffb0();
    Ref4d1440* FUN_00726070();
    bool HasExtraDataWithValue(int);
    void FUN_004d1440();
};
namespace InventoryTransfer {
struct Extra;
struct ExtraNode;
struct Item;
struct Inventory;
struct AutoMemContext
{
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
extern const char DAT_01020778[];
struct Form
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
    virtual bool v094();
};
struct Extra
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Extra();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void* GetExtraData(int);
    void SetOriginalReference(void*);
    void FUN_00418600();
    short FUN_00418770();
    void FUN_00419ad0(int);
    void RemoveExtra24();
    bool HasOnlyAllowedExtraData(int);
};
struct ExtraNode
{
    Extra* value;
    ExtraNode* next;
    ExtraNode();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Extra** FUN_006815c0();
    ExtraNode* FUN_00726070();
    void FUN_00905820(Extra**);
    void FUN_005ae3d0(Extra**);
};
struct Item
{
    ExtraNode* list;
    int count;
    TESBoundObject* form;
    Item();
    ~Item();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    Form* FUN_0044ddc0();
    void* FUN_004bde40();
    void FUN_00403550(TESBoundObject*);
    void FUN_00403550(Form*);
    void FUN_006ecd40(int);
    void ProcessNodes();
    bool FUN_004bcb70();
    int FUN_004bcc30();
    bool FUN_004bddd0(int);
    int FUN_004bc8f0(int);
    int GetFormTypeCategory();
};
struct BaseEntry
{
    int count;
    TESBoundObject* form;
};
struct BaseNode
{
    BaseEntry** FUN_006815c0();
    BaseNode* FUN_00726070();
};
struct ItemNode
{
    Item** FUN_006815c0();
    ItemNode* FUN_00726070();
};
struct Container
{
    BaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
    bool FUN_00481eb0(TESBoundObject*);
};
struct Inventory
{
    ItemNode* head;
    Container* FUN_004bffb0();
    Item* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004c3380(Item*, int);
    void FUN_004d26d0(Inventory*, void*, bool);
};
// @fnv 0x004d26d0
void Inventory::FUN_004d26d0(Inventory* target, void* owner, bool exclude)
{
    AutoMemContext contextSlot2(0x36, true, DAT_01020778, 0x26b7);
    BaseNode* baseSlot2 = FUN_004bffb0()->FUN_00717e50();
    Item* transferSlot3 = 0;
    while (baseSlot2 && *baseSlot2->FUN_006815c0())
    {
        BaseEntry* entrySlot7 = *baseSlot2->FUN_006815c0();
        TESLevItem* leveledSlot21 = dynamic_cast<TESLevItem*>(entrySlot7->form);
        transferSlot3 = new Item;
        int baseCountSlot38 = FUN_004bffb0()->FUN_00482a90(entrySlot7->form);
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode;
        if (entrySlot7 && !leveledSlot21)
        {
            Item* current = FUN_004bfba0(entrySlot7->form, 1, 0);
            if (current)
                current->ProcessNodes();
            if (entrySlot7 && current &&
                (((!current->FUN_004bcb70() || current->FUN_004bcc30() < 1) && current->count + baseCountSlot38 == 0) ||
                 (current->FUN_0044ddc0()->v094() && exclude) || current->FUN_004bddd0(0)))
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
            else if (entrySlot7 && (!current || (current && !current->FUN_004bc8f0(0))))
            {
                int magnitude = baseCountSlot38;
                if (magnitude < 0)
                    magnitude *= -1;
                if (current)
                    transferSlot3->count = magnitude + current->count - current->FUN_004bc8f0(0);
                else
                    transferSlot3->count = magnitude;
                transferSlot3->FUN_00403550(entrySlot7->form);
                if (current && current->FUN_004bde40())
                {
                    ExtraNode* scripted = current->FUN_00559450();
                    while (scripted && *scripted->FUN_006815c0())
                    {
                        (*scripted->FUN_006815c0())->SetOriginalReference(owner);
                        transferSlot3->list->FUN_00905820(scripted->FUN_006815c0());
                        scripted = scripted->FUN_00726070();
                    }
                    target->FUN_004c3380(transferSlot3, 1);
                }
                else
                {
                    if (!transferSlot3->FUN_004bddd0(0))
                    {
                        Extra* extraA = new Extra;
                        extraA->SetOriginalReference(owner);
                        extraA->FUN_00419ad0(transferSlot3->FUN_00726070());
                        transferSlot3->list->FUN_005ae3d0(&extraA);
                        target->FUN_004c3380(transferSlot3, 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else if (current)
            {
                int extraCountSlot33 = 0;
                if (current->list)
                    extraCountSlot33 = current->FUN_004bc8f0(0);
                ExtraNode* extrasSlot23 = current->list;
                while (extrasSlot23 && *extrasSlot23->FUN_006815c0() && !transferSlot3)
                {
                    Extra* extraB = *extrasSlot23->FUN_006815c0();
                    transferSlot3->FUN_00403550(current->form);
                    transferSlot3->FUN_006ecd40(extraB->FUN_00418770());
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode;
                    extraB->SetOriginalReference(owner);
                    transferSlot3->list->FUN_005ae3d0(&extraB);
                    if (!transferSlot3->FUN_004bddd0(0))
                        target->FUN_004c3380(transferSlot3, 1);
                    extrasSlot23 = extrasSlot23->FUN_00726070();
                }
                if (current->FUN_004bc8f0(0) < baseCountSlot38 + current->count)
                {
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode;
                    if (current)
                        transferSlot3->count = baseCountSlot38 + current->count - current->FUN_004bc8f0(0);
                    else
                        transferSlot3->count = baseCountSlot38;
                    transferSlot3->FUN_00403550(entrySlot7->form);
                    if (!transferSlot3->FUN_004bddd0(0))
                    {
                        Extra* extraC = new Extra;
                        extraC->SetOriginalReference(owner);
                        extraC->FUN_00419ad0(transferSlot3->FUN_00726070());
                        transferSlot3->list->FUN_005ae3d0(&extraC);
                        target->FUN_004c3380(transferSlot3, 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        baseSlot2 = baseSlot2->FUN_00726070();
    }
    ItemNode* nodeSlot1 = head;
    while (nodeSlot1 && *nodeSlot1->FUN_006815c0())
    {
        transferSlot3 = new Item;
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode;
        Item* changed = *nodeSlot1->FUN_006815c0();
        if (changed && changed->FUN_00726070() > 0 && (!FUN_004bffb0() || !FUN_004bffb0()->FUN_00481eb0(changed->form)))
        {
            if (changed->FUN_004bc8f0(0) || changed->FUN_004bde40())
            {
                ExtraNode* walkSlot1 = changed->list;
                int countSlot56 = 0;
                bool hasSpecialSlot4 = false;
                while (walkSlot1 && *walkSlot1->FUN_006815c0())
                {
                    if ((*walkSlot1->FUN_006815c0())->GetExtraData(0x2f))
                        hasSpecialSlot4 = true;
                    walkSlot1 = walkSlot1->FUN_00726070();
                }
                walkSlot1 = changed->list;
                if (!hasSpecialSlot4 || changed->GetFormTypeCategory() != 4)
                {
                    while (walkSlot1 && *walkSlot1->FUN_006815c0())
                    {
                        Extra* extraD = *walkSlot1->FUN_006815c0();
                        extraD->SetOriginalReference(owner);
                        transferSlot3->list->FUN_005ae3d0(&extraD);
                        walkSlot1 = walkSlot1->FUN_00726070();
                        countSlot56 += extraD->FUN_00418770();
                    }
                }
                else
                {
                    if (changed->GetFormTypeCategory() == 4 && changed->FUN_004bde40())
                        changed->FUN_006ecd40(1);
                    while (walkSlot1 && *walkSlot1->FUN_006815c0())
                    {
                        Extra* extraE = *walkSlot1->FUN_006815c0();
                        extraE->RemoveExtra24();
                        extraE->SetOriginalReference(owner);
                        transferSlot3->list->FUN_005ae3d0(&extraE);
                        walkSlot1 = walkSlot1->FUN_00726070();
                        countSlot56 = 1;
                    }
                }
                transferSlot3->FUN_00403550(changed->form);
                transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                if (!transferSlot3->FUN_004bddd0(0) && countSlot56 < changed->FUN_00726070())
                {
                    Extra* extraF = new Extra;
                    extraF->SetOriginalReference(owner);
                    extraF->FUN_00419ad0(changed->FUN_00726070() - countSlot56);
                    transferSlot3->list->FUN_005ae3d0(&extraF);
                }
                if (!transferSlot3->FUN_004bddd0(0))
                    target->FUN_004c3380(transferSlot3, 1);
                else
                {
                    if (*transferSlot3->list->FUN_006815c0())
                        (*transferSlot3->list->FUN_006815c0())->FUN_00418600();
                    delete transferSlot3;
                    transferSlot3 = 0;
                }
            }
            else
            {
                Extra* chosen = 0;
                if (changed->list)
                {
                    ExtraNode* walk2Slot3 = changed->list;
                    int count2Slot41 = 0;
                    while (walk2Slot3 && *walk2Slot3->FUN_006815c0() && !chosen)
                    {
                        chosen = *walk2Slot3->FUN_006815c0();
                        count2Slot41 += chosen->FUN_00418770();
                        if (chosen->HasOnlyAllowedExtraData(0))
                            chosen = 0;
                        walk2Slot3 = walk2Slot3->FUN_00726070();
                    }
                    if (chosen)
                    {
                        if (!transferSlot3->list)
                            transferSlot3->list = new ExtraNode;
                        chosen->SetOriginalReference(owner);
                        transferSlot3->list->FUN_005ae3d0(&chosen);
                        if (!transferSlot3->FUN_004bddd0(0) && count2Slot41 < changed->FUN_00726070())
                        {
                            Extra* extraG = new Extra;
                            extraG->SetOriginalReference(owner);
                            extraG->FUN_00419ad0(changed->FUN_00726070() - count2Slot41);
                            transferSlot3->list->FUN_005ae3d0(&extraG);
                        }
                    }
                    else
                    {
                        Extra* extraH = new Extra;
                        extraH->SetOriginalReference(owner);
                        extraH->FUN_00419ad0(changed->FUN_00726070());
                        transferSlot3->list->FUN_005ae3d0(&extraH);
                    }
                    transferSlot3->FUN_00403550(changed->form);
                    transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                    if (!transferSlot3->FUN_004bddd0(0))
                    {
                        transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                        target->FUN_004c3380(transferSlot3, 1);
                    }
                    else
                    {
                        if (*transferSlot3->list->FUN_006815c0())
                            (*transferSlot3->list->FUN_006815c0())->FUN_00418600();
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
                else
                {
                    transferSlot3->FUN_00403550(changed->FUN_0044ddc0());
                    transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                    chosen = new Extra;
                    chosen->SetOriginalReference(owner);
                    chosen->FUN_00419ad0(transferSlot3->FUN_00726070());
                    transferSlot3->list->FUN_005ae3d0(&chosen);
                    target->FUN_004c3380(transferSlot3, 1);
                }
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        nodeSlot1 = nodeSlot1->FUN_00726070();
    }
}
}
struct CleanupReference;
struct CleanupExtra
{
    virtual ~CleanupExtra();
    CleanupReference* FUN_00418630();
    void FUN_00418600();
    unsigned int ItemsInList();
    short FUN_00418770();
    void RemoveExtra24();
    void* FUN_00418800();
};
struct CleanupExtraNode
{
    CleanupExtra** FUN_006815c0();
    CleanupExtraNode* FUN_00726070();
    void FUN_0063f7b0();
    void FUN_00905330(CleanupExtra* const&);
};
struct CleanupItem : InventoryStackRecord
{
    CleanupExtraNode* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
};
struct CleanupItemNode
{
    CleanupItem** FUN_006815c0();
    void FUN_00905330(CleanupItem* const&);
};
struct CleanupInventory;
struct CleanupReferenceExtra
{
    CleanupInventory* FUN_00418520();
};
struct CleanupReference
{
    void* FUN_0055d310();
    CleanupReferenceExtra* FUN_005d43c0();
};
struct CleanupInventory
{
    CleanupItemNode* first;
    CleanupItem* FUN_004bfba0(TESBoundObject*, int, int);
    void RemoveAllItems();
};
// Save-game block loader (FUN_004d3cc0): block header checks, item list rebuild, size validation logs.
class TESForm;
struct LoadingFormInfo
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flags0;
    unsigned char flags1;
    unsigned char flags2;
    unsigned char flags3;
    unsigned char version;
};
class SaveLoadGame
{
  public:
    bool IsLoading();                             // 0x862110
    void ReadData(void* dst, unsigned int size);  // 0x8579e0
    LoadingFormInfo* GetLoadingForm();            // 0x4fd3c0
    unsigned char GetVersion();                   // 0x8df040
    unsigned int GetOffset();                     // 0x825c00
};
extern SaveLoadGame* DAT_011de45c;
TESForm* LookupFormByID(unsigned int formID);
// 0x4839c0
void LogSaveError(const char* fmt, ...);
// 0x5b5e40
class LoadItem
{
  public:
    void* unk00;
    int unk04;
    void* unk08;
    LoadItem();             // 0x76b630
    void Prepare();         // 0x4be930
    LoadItem* GetLoadedForm();  // 0x44ddc0
    void Finish();          // 0x4bc780
    ~LoadItem();
};
class LoadItemList
{
  public:
    void AddHead(LoadItem** item);  // 0x5ae3d0
};
class FUN_004d3cc0_cls
{
  public:
    LoadItemList* pItems;
    void FinishLoad();  // 0x4cbbc0
    void FUN_004d3cc0();
};
struct Blob4_4d4090
{
    int m_data;
    Blob4_4d4090(int v);
};
struct SaveBuffer_4d4090
{
    virtual TESIdleForm* GetSpeakerIdle();
    Blob4_4d4090 GetChangeFlags();
    void SetChangeFlags(Blob4_4d4090 flags);
    void SetSpeakerIdle(TESIdleForm* idle);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
struct ItemSave_4d4090
{
    void SavePerkList(SaveBuffer_4d4090* buffer);
};
struct InvChangesSave : InventoryChanges
{
    void FUN_004d4090(SaveBuffer_4d4090* buffer);
};
struct WalkForm
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
    virtual bool excluded();
    int FUN_00401170();
    bool FUN_0046e8c0();
};
struct WalkBiped
{
    bool FUN_00480d90();
};
WalkBiped* GetFormAsBipedModel(WalkForm*);
struct WalkBaseEntry
{
    int count;
    WalkForm* form;
};
struct WalkBaseNode
{
    WalkBaseEntry** FUN_006815c0();
    WalkBaseNode* FUN_00726070();
};
struct WalkContainer
{
    WalkBaseNode* FUN_00717e50();
    int GetObjectCount(WalkForm*);
};
struct WalkChange
{
    WalkForm* FUN_0044ddc0();
    int FUN_00726070();
    void* FUN_00559450();
};
struct WalkNode
{
    WalkChange** FUN_006815c0();
    WalkNode* FUN_00726070();
};
struct WalkTemp
{
    void* extra;
    int count;
    WalkForm* form;
    WalkTemp();
    ~WalkTemp();
    void FUN_006ecd40(int);
    void FUN_00403550(WalkForm*);
};
struct WalkInventory
{
    WalkNode* first;
    WalkContainer* FUN_004bffb0();
    void* FUN_004bfba0(WalkForm*, int, int);
    int ForEachInventoryItem(bool(__cdecl* callback)(WalkTemp*, void*), void* context, int flags);
};
struct IterForm
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual bool IsFiltered();
    int FUN_00401170();
    bool FUN_0046e8c0();
};
struct BipedIter
{
    bool FUN_00480d90();
};
BipedIter* __cdecl GetFormAsBipedModel(IterForm*);
struct BaseEntryIter
{
    int count;
    IterForm* form;
};
struct BaseNodeIter
{
    BaseEntryIter** FUN_006815c0();
    BaseNodeIter* FUN_00726070();
};
struct ChangeIter
{
    IterForm* FUN_0044ddc0();
    int FUN_00726070();
    void* FUN_00559450();
};
struct ChangeNodeIter
{
    ChangeIter** FUN_006815c0();
    ChangeNodeIter* FUN_00726070();
};
struct IterContainer
{
    BaseNodeIter* FUN_00717e50();
    int GetObjectCount(IterForm*);
};
struct IterState
{
    void* extra;
    int unk04;
    int unk08;
    BaseNodeIter* base;
    ChangeNodeIter* change;
    bool done;
    void FUN_006ecd40(int);
    void FUN_00403550(IterForm*);
};
struct InventoryIterOwner
{
    ChangeNodeIter* changes;
    IterContainer* FUN_004bffb0();
    int FUN_004bfba0(IterForm*, int, int);
    bool AdvanceInventoryIterator(IterState*, void**, int);
};
int __fastcall FNV_GetFormType(TESForm* pForm);
struct TopicEntry4d4 : FUN_004459e0
{
    TESForm* FUN_0044ddc0();
};
struct FUN_004bf630
{
    ~FUN_004bf630();
};
struct TopicForm4d4
{
    int FUN_004bd570(unsigned int uiIndex);
};
struct TopicList4d4
{
    void FUN_005ae3d0(FUN_004459e0*& pkItem);
};
struct FUN_004d4ca0_shell
{
    FUN_004bf630* FUN_004ca200();
    FUN_004459e0* GetNextInventoryEntry(FUN_004bf630* pkIter);
    void CollectTopicEntries(TESForm* pkForm, TopicList4d4* pkList);
};
struct InvExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    InvExtra();
    bool HasOnlyAllowedExtraData(int);
    bool CompareListForContainer(InvExtra*, int, int);
    short FUN_00418770();
    void FUN_00419ad0(unsigned short);
    void DuplicateExtraListForContainer(InvExtra*);
};
struct InvNode
{
    InvExtra* data;
    InvNode* next;
    InvNode();
    InvExtra** FUN_006815c0();
    InvNode* FUN_00726070();
    void FUN_005ae3d0(InvExtra*&);
};
struct InvEntry
{
    InvNode* list;
    int count;
    void* object;
    InvEntry(void*, int);
    InvNode* FUN_00559450();
    void* FUN_0044ddc0();
    int FUN_00726070();
    void FUN_006ecd40(int);
};
struct InvArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned FUN_0044ddc0();
    InvEntry*& FUN_00877a30(unsigned);
    unsigned FUN_007cb2e0(InvEntry*&);
};
float __cdecl FUN_0048ebc0(void*, bool);
struct InvHost
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    InvArray entries;
    float weight;
    bool FUN_004d1360();
    void FUN_009687b0(void* object, InvExtra* extra, int amount);
};
extern const char g_inventoryChangesSourceFilename[];
void* operator new(unsigned int);
struct Transfer4c37C37Form
{
    virtual void Pad48_0();
    virtual void Pad48_1();
    virtual void Pad48_2();
    virtual void Pad48_3();
    virtual void Pad48_4();
    virtual void Pad48_5();
    virtual void Pad48_6();
    virtual void Pad48_7();
    virtual void Pad48_8();
    virtual void Pad48_9();
    virtual void Pad48_10();
    virtual void Pad48_11();
    virtual void Pad48_12();
    virtual void Pad48_13();
    virtual void Pad48_14();
    virtual void Pad48_15();
    virtual void Pad48_16();
    virtual void Pad48_17();
    virtual void Vcall48(int arg);
    virtual void Pad190_19();
    virtual void Pad190_20();
    virtual void Pad190_21();
    virtual void Pad190_22();
    virtual void Pad190_23();
    virtual void Pad190_24();
    virtual void Pad190_25();
    virtual void Pad190_26();
    virtual void Pad190_27();
    virtual void Pad190_28();
    virtual void Pad190_29();
    virtual void Pad190_30();
    virtual void Pad190_31();
    virtual void Pad190_32();
    virtual void Pad190_33();
    virtual void Pad190_34();
    virtual void Pad190_35();
    virtual void Pad190_36();
    virtual void Pad190_37();
    virtual void Pad190_38();
    virtual void Pad190_39();
    virtual void Pad190_40();
    virtual void Pad190_41();
    virtual void Pad190_42();
    virtual void Pad190_43();
    virtual void Pad190_44();
    virtual void Pad190_45();
    virtual void Pad190_46();
    virtual void Pad190_47();
    virtual void Pad190_48();
    virtual void Pad190_49();
    virtual void Pad190_50();
    virtual void Pad190_51();
    virtual void Pad190_52();
    virtual void Pad190_53();
    virtual void Pad190_54();
    virtual void Pad190_55();
    virtual void Pad190_56();
    virtual void Pad190_57();
    virtual void Pad190_58();
    virtual void Pad190_59();
    virtual void Pad190_60();
    virtual void Pad190_61();
    virtual void Pad190_62();
    virtual void Pad190_63();
    virtual void Pad190_64();
    virtual void Pad190_65();
    virtual void Pad190_66();
    virtual void Pad190_67();
    virtual void Pad190_68();
    virtual void Pad190_69();
    virtual void Pad190_70();
    virtual void Pad190_71();
    virtual void Pad190_72();
    virtual void Pad190_73();
    virtual void Pad190_74();
    virtual void Pad190_75();
    virtual void Pad190_76();
    virtual void Pad190_77();
    virtual void Pad190_78();
    virtual void Pad190_79();
    virtual void Pad190_80();
    virtual void Pad190_81();
    virtual void Pad190_82();
    virtual void Pad190_83();
    virtual void Pad190_84();
    virtual void Pad190_85();
    virtual void Pad190_86();
    virtual void Pad190_87();
    virtual void Pad190_88();
    virtual void Pad190_89();
    virtual void Pad190_90();
    virtual void Pad190_91();
    virtual void Pad190_92();
    virtual void Pad190_93();
    virtual void Pad190_94();
    virtual void Pad190_95();
    virtual void Pad190_96();
    virtual void Pad190_97();
    virtual void Pad190_98();
    virtual void Pad190_99();
    virtual void Vcall190(int a, void* b, int c);
};
struct Transfer4c37Obj44
{
    int FUN_0044ddc0();
};
struct Transfer4c37Cont14c
{
    virtual void Pad14c_0();
    virtual void Pad14c_1();
    virtual void Pad14c_2();
    virtual void Pad14c_3();
    virtual void Pad14c_4();
    virtual void Pad14c_5();
    virtual void Pad14c_6();
    virtual void Pad14c_7();
    virtual void Pad14c_8();
    virtual void Pad14c_9();
    virtual void Pad14c_10();
    virtual void Pad14c_11();
    virtual void Pad14c_12();
    virtual void Pad14c_13();
    virtual void Pad14c_14();
    virtual void Pad14c_15();
    virtual void Pad14c_16();
    virtual void Pad14c_17();
    virtual void Pad14c_18();
    virtual void Pad14c_19();
    virtual void Pad14c_20();
    virtual void Pad14c_21();
    virtual void Pad14c_22();
    virtual void Pad14c_23();
    virtual void Pad14c_24();
    virtual void Pad14c_25();
    virtual void Pad14c_26();
    virtual void Pad14c_27();
    virtual void Pad14c_28();
    virtual void Pad14c_29();
    virtual void Pad14c_30();
    virtual void Pad14c_31();
    virtual void Pad14c_32();
    virtual void Pad14c_33();
    virtual void Pad14c_34();
    virtual void Pad14c_35();
    virtual void Pad14c_36();
    virtual void Pad14c_37();
    virtual void Pad14c_38();
    virtual void Pad14c_39();
    virtual void Pad14c_40();
    virtual void Pad14c_41();
    virtual void Pad14c_42();
    virtual void Pad14c_43();
    virtual void Pad14c_44();
    virtual void Pad14c_45();
    virtual void Pad14c_46();
    virtual void Pad14c_47();
    virtual void Pad14c_48();
    virtual void Pad14c_49();
    virtual void Pad14c_50();
    virtual void Pad14c_51();
    virtual void Pad14c_52();
    virtual void Pad14c_53();
    virtual void Pad14c_54();
    virtual void Pad14c_55();
    virtual void Pad14c_56();
    virtual void Pad14c_57();
    virtual void Pad14c_58();
    virtual void Pad14c_59();
    virtual void Pad14c_60();
    virtual void Pad14c_61();
    virtual void Pad14c_62();
    virtual void Pad14c_63();
    virtual void Pad14c_64();
    virtual void Pad14c_65();
    virtual void Pad14c_66();
    virtual void Pad14c_67();
    virtual void Pad14c_68();
    virtual void Pad14c_69();
    virtual void Pad14c_70();
    virtual void Pad14c_71();
    virtual void Pad14c_72();
    virtual void Pad14c_73();
    virtual void Pad14c_74();
    virtual void Pad14c_75();
    virtual void Pad14c_76();
    virtual void Pad14c_77();
    virtual void Pad14c_78();
    virtual void Pad14c_79();
    virtual void Pad14c_80();
    virtual void Pad14c_81();
    virtual void Pad14c_82();
    virtual Transfer4c37Obj44* Vcall14c();
};
struct Transfer4c37MidObj;
struct Transfer4c37C37Obj
{
    virtual void Pad100_0();
    virtual void Pad100_1();
    virtual void Pad100_2();
    virtual void Pad100_3();
    virtual void Pad100_4();
    virtual void Pad100_5();
    virtual void Pad100_6();
    virtual void Pad100_7();
    virtual void Pad100_8();
    virtual void Pad100_9();
    virtual void Pad100_10();
    virtual void Pad100_11();
    virtual void Pad100_12();
    virtual void Pad100_13();
    virtual void Pad100_14();
    virtual void Pad100_15();
    virtual void Pad100_16();
    virtual void Pad100_17();
    virtual void Pad100_18();
    virtual void Pad100_19();
    virtual void Pad100_20();
    virtual void Pad100_21();
    virtual void Pad100_22();
    virtual void Pad100_23();
    virtual void Pad100_24();
    virtual void Pad100_25();
    virtual void Pad100_26();
    virtual void Pad100_27();
    virtual void Pad100_28();
    virtual void Pad100_29();
    virtual void Pad100_30();
    virtual void Pad100_31();
    virtual void Pad100_32();
    virtual void Pad100_33();
    virtual void Pad100_34();
    virtual void Pad100_35();
    virtual void Pad100_36();
    virtual void Pad100_37();
    virtual void Pad100_38();
    virtual void Pad100_39();
    virtual void Pad100_40();
    virtual void Pad100_41();
    virtual void Pad100_42();
    virtual void Pad100_43();
    virtual void Pad100_44();
    virtual void Pad100_45();
    virtual void Pad100_46();
    virtual void Pad100_47();
    virtual void Pad100_48();
    virtual void Pad100_49();
    virtual void Pad100_50();
    virtual void Pad100_51();
    virtual void Pad100_52();
    virtual void Pad100_53();
    virtual void Pad100_54();
    virtual void Pad100_55();
    virtual void Pad100_56();
    virtual void Pad100_57();
    virtual void Pad100_58();
    virtual void Pad100_59();
    virtual void Pad100_60();
    virtual void Pad100_61();
    virtual void Pad100_62();
    virtual void Pad100_63();
    virtual bool Vcall100();
    virtual void Pad188_65();
    virtual void Pad188_66();
    virtual void Pad188_67();
    virtual void Pad188_68();
    virtual void Pad188_69();
    virtual void Pad188_70();
    virtual void Pad188_71();
    virtual void Pad188_72();
    virtual void Pad188_73();
    virtual void Pad188_74();
    virtual void Pad188_75();
    virtual void Pad188_76();
    virtual void Pad188_77();
    virtual void Pad188_78();
    virtual void Pad188_79();
    virtual void Pad188_80();
    virtual void Pad188_81();
    virtual void Pad188_82();
    virtual void Pad188_83();
    virtual void Pad188_84();
    virtual void Pad188_85();
    virtual void Pad188_86();
    virtual void Pad188_87();
    virtual void Pad188_88();
    virtual void Pad188_89();
    virtual void Pad188_90();
    virtual void Pad188_91();
    virtual void Pad188_92();
    virtual void Pad188_93();
    virtual void Pad188_94();
    virtual void Pad188_95();
    virtual void Pad188_96();
    virtual void Pad188_97();
    virtual bool Vcall188(int a, int b, void* c);
    virtual void Pad3ec_99();
    virtual void Pad3ec_100();
    virtual void Pad3ec_101();
    virtual void Pad3ec_102();
    virtual void Pad3ec_103();
    virtual void Pad3ec_104();
    virtual void Pad3ec_105();
    virtual void Pad3ec_106();
    virtual void Pad3ec_107();
    virtual void Pad3ec_108();
    virtual void Pad3ec_109();
    virtual void Pad3ec_110();
    virtual void Pad3ec_111();
    virtual void Pad3ec_112();
    virtual void Pad3ec_113();
    virtual void Pad3ec_114();
    virtual void Pad3ec_115();
    virtual void Pad3ec_116();
    virtual void Pad3ec_117();
    virtual void Pad3ec_118();
    virtual void Pad3ec_119();
    virtual void Pad3ec_120();
    virtual void Pad3ec_121();
    virtual void Pad3ec_122();
    virtual void Pad3ec_123();
    virtual void Pad3ec_124();
    virtual void Pad3ec_125();
    virtual void Pad3ec_126();
    virtual void Pad3ec_127();
    virtual void Pad3ec_128();
    virtual void Pad3ec_129();
    virtual void Pad3ec_130();
    virtual void Pad3ec_131();
    virtual void Pad3ec_132();
    virtual void Pad3ec_133();
    virtual void Pad3ec_134();
    virtual void Pad3ec_135();
    virtual void Pad3ec_136();
    virtual void Pad3ec_137();
    virtual void Pad3ec_138();
    virtual void Pad3ec_139();
    virtual void Pad3ec_140();
    virtual void Pad3ec_141();
    virtual void Pad3ec_142();
    virtual void Pad3ec_143();
    virtual void Pad3ec_144();
    virtual void Pad3ec_145();
    virtual void Pad3ec_146();
    virtual void Pad3ec_147();
    virtual void Pad3ec_148();
    virtual void Pad3ec_149();
    virtual void Pad3ec_150();
    virtual void Pad3ec_151();
    virtual void Pad3ec_152();
    virtual void Pad3ec_153();
    virtual void Pad3ec_154();
    virtual void Pad3ec_155();
    virtual void Pad3ec_156();
    virtual void Pad3ec_157();
    virtual void Pad3ec_158();
    virtual void Pad3ec_159();
    virtual void Pad3ec_160();
    virtual void Pad3ec_161();
    virtual void Pad3ec_162();
    virtual void Pad3ec_163();
    virtual void Pad3ec_164();
    virtual void Pad3ec_165();
    virtual void Pad3ec_166();
    virtual void Pad3ec_167();
    virtual void Pad3ec_168();
    virtual void Pad3ec_169();
    virtual void Pad3ec_170();
    virtual void Pad3ec_171();
    virtual void Pad3ec_172();
    virtual void Pad3ec_173();
    virtual void Pad3ec_174();
    virtual void Pad3ec_175();
    virtual void Pad3ec_176();
    virtual void Pad3ec_177();
    virtual void Pad3ec_178();
    virtual void Pad3ec_179();
    virtual void Pad3ec_180();
    virtual void Pad3ec_181();
    virtual void Pad3ec_182();
    virtual void Pad3ec_183();
    virtual void Pad3ec_184();
    virtual void Pad3ec_185();
    virtual void Pad3ec_186();
    virtual void Pad3ec_187();
    virtual void Pad3ec_188();
    virtual void Pad3ec_189();
    virtual void Pad3ec_190();
    virtual void Pad3ec_191();
    virtual void Pad3ec_192();
    virtual void Pad3ec_193();
    virtual void Pad3ec_194();
    virtual void Pad3ec_195();
    virtual void Pad3ec_196();
    virtual void Pad3ec_197();
    virtual void Pad3ec_198();
    virtual void Pad3ec_199();
    virtual void Pad3ec_200();
    virtual void Pad3ec_201();
    virtual void Pad3ec_202();
    virtual void Pad3ec_203();
    virtual void Pad3ec_204();
    virtual void Pad3ec_205();
    virtual void Pad3ec_206();
    virtual void Pad3ec_207();
    virtual void Pad3ec_208();
    virtual void Pad3ec_209();
    virtual void Pad3ec_210();
    virtual void Pad3ec_211();
    virtual void Pad3ec_212();
    virtual void Pad3ec_213();
    virtual void Pad3ec_214();
    virtual void Pad3ec_215();
    virtual void Pad3ec_216();
    virtual void Pad3ec_217();
    virtual void Pad3ec_218();
    virtual void Pad3ec_219();
    virtual void Pad3ec_220();
    virtual void Pad3ec_221();
    virtual void Pad3ec_222();
    virtual void Pad3ec_223();
    virtual void Pad3ec_224();
    virtual void Pad3ec_225();
    virtual void Pad3ec_226();
    virtual void Pad3ec_227();
    virtual void Pad3ec_228();
    virtual void Pad3ec_229();
    virtual void Pad3ec_230();
    virtual void Pad3ec_231();
    virtual void Pad3ec_232();
    virtual void Pad3ec_233();
    virtual void Pad3ec_234();
    virtual void Pad3ec_235();
    virtual void Pad3ec_236();
    virtual void Pad3ec_237();
    virtual void Pad3ec_238();
    virtual void Pad3ec_239();
    virtual void Pad3ec_240();
    virtual void Pad3ec_241();
    virtual void Pad3ec_242();
    virtual void Pad3ec_243();
    virtual void Pad3ec_244();
    virtual void Pad3ec_245();
    virtual void Pad3ec_246();
    virtual void Pad3ec_247();
    virtual void Pad3ec_248();
    virtual void Pad3ec_249();
    virtual void Pad3ec_250();
    virtual void Vcall3ec(int a, int b, int c, int d);
    Transfer4c37Cont14c* FUN_008d8520();
    int FUN_008d6f30();
    void* FUN_007af430();
    bool FUN_00440da0();
    bool FUN_0088d7d0(int a, int b, void* c, int d, int e, int f);
    Transfer4c37MidObj* FUN_005d43c0();
    int FUN_00567790();
    int FUN_00966a70(int a, int b);
    void FUN_0094fd30(int a);
    int FUN_008a1710();
};
struct Transfer4c37Form4
{
    virtual ~Transfer4c37Form4();
    int ItemsInList();
    int GetExtraData(int a);
    short FUN_00418770();
    void FUN_0042dec0();
};
struct Transfer4c37FirstObj
{
    void _ref_00905330(Transfer4c37Form4** pp);
};
struct Transfer4c37NewObj
{
    void* m00;
    int m04;
    int m08;
    int FUN_004459e0(int a);
    Transfer4c37NewObj();
    ~Transfer4c37NewObj();
    int _ref_00726070();
    void FUN_006ecd40(int a);
    int FUN_00559450();
    int FUN_0044ddc0();
    void ClearExtraDataList();
};
struct Transfer4c37Ret720
{
    int m00;
    int m04;
    int m08;
    int m0c;
};
struct Transfer4c37Obj20
{
    virtual ~Transfer4c37Obj20();
    Transfer4c37Obj20();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    void SetLeveledItemIndex(int a);
    int FUN_0041d000();
    void CopyListForReference(void* a, int b);
    void FUN_00419700(void* a);
    void FUN_00419ad0(int a);
    int ItemsInList();
    short FUN_00418770();
    void FUN_0041aed0();
    void* FUN_00418660();
    bool FUN_004bca60();
};
struct Transfer4c37ItemObj;
struct Transfer4c37EntryHeadS
{
    void _ref_00905330(Transfer4c37ItemObj** pp);
    void FUN_005ae3d0(Transfer4c37Obj20** pp);
};
struct Transfer4c37Node84
{
    Transfer4c37ItemObj** FUN_006815c0();
    Transfer4c37Node84* FUN_00726070();
};
unsigned char __cdecl FUN_00481f10(int a);
unsigned char __cdecl FUN_00702680(int a, int b);
int __fastcall FUN_00401170(int a);
void* __cdecl FUN_00401000(int a);
struct Transfer4c37Obj96
{
    void* item;
    void* next;
    Transfer4c37Obj96();
};
struct Transfer4c37CurHead
{
    void FUN_005ae3d0(void* pp);
};
struct Transfer4c37MidObj
{
    void CopyListForReference(void* a, int b);
    void RemoveExtraData30();
    void FUN_0041c900();
    int FUN_0041b320();
    void FUN_0041b2a0(void* a);
    int FUN_004216f0();
};
struct Transfer4c37AuxObj
{
    int FUN_005f0cc0();
};
struct Transfer4c37ResObj
{
    virtual void RPad_0();
    virtual void RPad_1();
    virtual void RPad_2();
    virtual void RPad_3();
    virtual void RPad_4();
    virtual void RPad_5();
    virtual void RPad_6();
    virtual void RPad_7();
    virtual void RPad_8();
    virtual void RPad_9();
    virtual void RPad_10();
    virtual void RPad_11();
    virtual void RPad_12();
    virtual void RPad_13();
    virtual void RPad_14();
    virtual void RPad_15();
    virtual void RPad_16();
    virtual void RPad_17();
    virtual void Vcall48(int a);
    virtual void RPadC4_19();
    virtual void RPadC4_20();
    virtual void RPadC4_21();
    virtual void RPadC4_22();
    virtual void RPadC4_23();
    virtual void RPadC4_24();
    virtual void RPadC4_25();
    virtual void RPadC4_26();
    virtual void RPadC4_27();
    virtual void RPadC4_28();
    virtual void RPadC4_29();
    virtual void RPadC4_30();
    virtual void RPadC4_31();
    virtual void RPadC4_32();
    virtual void RPadC4_33();
    virtual void RPadC4_34();
    virtual void RPadC4_35();
    virtual void RPadC4_36();
    virtual void RPadC4_37();
    virtual void RPadC4_38();
    virtual void RPadC4_39();
    virtual void RPadC4_40();
    virtual void RPadC4_41();
    virtual void RPadC4_42();
    virtual void RPadC4_43();
    virtual void RPadC4_44();
    virtual void RPadC4_45();
    virtual void RPadC4_46();
    virtual void RPadC4_47();
    virtual void RPadC4_48();
    virtual void VcallC4(int a);
    void FUN_00567490(float f);
    Transfer4c37MidObj* FUN_005d43c0();
    int FUN_00567770();
    void FUN_00567ad0(void* a);
    void* FUN_007af430();
};
struct Transfer4c37M68Obj
{
    int FUN_00546a40();
    unsigned char FUN_00546ca0(void* a);
};
struct Transfer4c37M00Obj
{
    bool FUN_008256d0();
};
struct Transfer4c37LogObj
{
    const char* FUN_004c69f0();
};
extern Transfer4c37LogObj DAT_011d31f8;
int __cdecl DispatchMessageToSink(const char*, int, const char*, int, float, int);
struct Transfer4c37T70Obj
{
    int GetWorldModel(int a);
};
void __cdecl FUN_005ac750(void* a, void* b, int c);
struct Transfer4c37ItemObj
{
    int ItemsInList();
    short FUN_00418770();
    bool FUN_00418ab0(int a);
    void* FUN_00418660();
    int FUN_0041c8d0();
    float FUN_00418860();
    bool FUN_00418750();
    Transfer4c37Ret720* GetExtraLeveledItem();
    void* FUN_00418800();
    void FUN_00419ad0(int a);
    int FUN_0041d000();
    signed char GetExtraByteValue();
    virtual ~Transfer4c37ItemObj();
    bool FUN_004bca60();
    int FUN_0041b010(int a);
    void FUN_0041c900();
    void FUN_00419700(void* a);
};
struct Transfer4c37EntryFirst
{
    Transfer4c37ItemObj** _ref_006815c0();
    Transfer4c37EntryFirst* FUN_00726070();
};
struct Transfer4c37Tail470
{
    void FUN_00470470();
};
struct Transfer4c37Entry
{
    ~Transfer4c37Entry();
    void* m00;
    int m04;
    bool FUN_004bddd0(int a);
    int FUN_004bc980();
    int FUN_004bc8f0(int a);
    void* FUN_004bde40();
    int FUN_0044ddc0();
    int FUN_00726070();
    bool FUN_004bcb70();
    void ClearExtraDataList();
    int m08;
    void* FUN_00559450();
};
struct Transfer4c37Cont
{
    int FUN_00482a90(int a);
};
struct Transfer4c37EntryNew
{
    void* extras;
    int count;
    void* form;
    Transfer4c37EntryNew(int a, int b);
};
struct Transfer4c37ThisHead
{
    void FUN_00905820(Transfer4c37Entry** pp);
    void _ref_00905330(Transfer4c37Entry** pp);
};
struct Transfer4c37D7Obj
{
    bool FUN_0047d7c0();
};
struct Transfer4c37Sub100
{
    virtual void SPad_0();
    virtual void SPad_1();
    virtual void SPad_2();
    virtual float Vcall3(int a);
};
struct Transfer4c37ActorValueView
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
    int unk88;
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
    int unkc8;
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
    int unkf8;
    int unkfc;
    Transfer4c37Sub100 values;
};
struct Transfer4c37Glob20
{
    float* FUN_00403e20();
};
extern Transfer4c37Glob20 DAT_011cde20;
int __cdecl FUN_0047e040(float a);
int __cdecl FUN_00ec62c0(float a);
struct Transfer4c37FormFull
{
    virtual void PadF_0();
    virtual void PadF_1();
    virtual void PadF_2();
    virtual void PadF_3();
    virtual void PadF_4();
    virtual void PadF_5();
    virtual void PadF_6();
    virtual void PadF_7();
    virtual void PadF_8();
    virtual void PadF_9();
    virtual void PadF_10();
    virtual void PadF_11();
    virtual void PadF_12();
    virtual void PadF_13();
    virtual void PadF_14();
    virtual void PadF_15();
    virtual void PadF_16();
    virtual void PadF_17();
    virtual void Vcall48(int arg);
    virtual void PadF_19();
    virtual void PadF_20();
    virtual void PadF_21();
    virtual void PadF_22();
    virtual void PadF_23();
    virtual void PadF_24();
    virtual void PadF_25();
    virtual void PadF_26();
    virtual void PadF_27();
    virtual void PadF_28();
    virtual void PadF_29();
    virtual void PadF_30();
    virtual void PadF_31();
    virtual void PadF_32();
    virtual void PadF_33();
    virtual void PadF_34();
    virtual void PadF_35();
    virtual void PadF_36();
    virtual void PadF_37();
    virtual void PadF_38();
    virtual void PadF_39();
    virtual void PadF_40();
    virtual void PadF_41();
    virtual void PadF_42();
    virtual void PadF_43();
    virtual void PadF_44();
    virtual void PadF_45();
    virtual void PadF_46();
    virtual void PadF_47();
    virtual void PadF_48();
    virtual void PadF_49();
    virtual void PadF_50();
    virtual void PadF_51();
    virtual void PadF_52();
    virtual void PadF_53();
    virtual void PadF_54();
    virtual void PadF_55();
    virtual void PadF_56();
    virtual void PadF_57();
    virtual void PadF_58();
    virtual void PadF_59();
    virtual void PadF_60();
    virtual void PadF_61();
    virtual void PadF_62();
    virtual void PadF_63();
    virtual bool Vcall100();
    int FUN_0088c830(int a, int b, void* c, int d, int e, int f);
};
struct Transfer4c37C37This
{
    int m00;
    Transfer4c37FormFull* m04;
    float m08;
    float m0c;
    unsigned char m10;
    Transfer4c37Cont* FUN_004bffb0();
    Transfer4c37Entry* FUN_004bfba0(int a, int b, int c);
    void SetInventorySlotExtraData(Transfer4c37Entry* e, void* f, int v);
    Transfer4c37ResObj* PlaceObject(void* a, int b, int c, int d, int e, int f);
    int FUN_004c37d0(Transfer4c37C37Obj* p0, int p1, unsigned char p2, int p3, Transfer4c37Form4* p4, unsigned char p5,
                     Transfer4c37C37Form* p6, int p7, int p8, unsigned char p9, unsigned char p10,
                     Transfer4c37Entry* p11);
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int v);
    FUN_008c71b0(const FUN_008c71b0& other);
};
struct LoadBuffer4160
{
    virtual void Slot0();
    virtual int GetVersion();
    void FUN_00428110(unsigned int* out);
    void FUN_0042ce30(unsigned int* out);
    void FUN_007037c0(int version);
    void SetValue(FUN_008c71b0 flags);
    void SetValue(unsigned int flags);
    void FUN_0086cf00(FUN_008c71b0 flags);
    void FUN_0086cf00(unsigned int flags);
    unsigned int FUN_00864a60();
};
struct Item4160 : FUN_0076b630
{
    void FUN_004bee00(LoadBuffer4160* buffer);
    void ClearExtraDataList();
};
struct ChangeList4160
{
    void FUN_005ae3d0(FUN_004459e0** item);
};
struct Inventory4160
{
    ChangeList4160* changes;
    void FUN_004d4160(LoadBuffer4160* buffer);
};
extern const char g_inventoryChangesSourceFilename[];
struct FUN_0076b630_ex : public FUN_0076b630
{
    void SetExtraListFlag(int, int, int);
};
struct MoveFormInfo_ex : public MoveFormInfo
{
    bool FUN_00480af0(int, int, void*);
};
void* __cdecl FUN_00475020(Weapon*);
extern const char DAT_01020778[];
class VSubC5
{
  public:
    virtual void v0();
    virtual bool v4();
};
class IngredientItem : public TESBoundObject
{
  public:
    char padC5[0x38];
    VSubC5 sub;
};
class AlchemyItem : public TESBoundObject
{
  public:
    char padC5[0x38];
    VSubC5 sub;
};
struct E4C5
{
    int count;
    TESBoundObject* p4;
    TESBoundObject* p8;
    int FUN_00726070();
};
struct ENodeC5
{
    E4C5** FUN_006815c0();
    bool FUN_008256d0();
    ENodeC5* FUN_00726070();
};
struct MemHelperC5
{
    void* m_p;
    MemHelperC5(int, bool, const char*, int);
    ~MemHelperC5();
};
struct CItemC5
{
    TESBoundObject* p0;
    int i4;
    int i8;
    CItemC5(TESBoundObject*, int);
    int FUN_00726070();
};
struct CContainerC5
{
    ENodeC5* FUN_00717e50();
    bool FUN_00481eb0(TESBoundObject*);
};
struct CTargetC5
{
    ENodeC5* m_pFirstNode;
    CContainerC5* FUN_004bffb0();
    CItemC5* FUN_004bfba0(TESBoundObject*, int, int);
    void* FUN_004cafe0();
};
struct ProcV6;
struct Actor6
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool v100();
    ProcV6* FUN_008d8520();
};
struct ProcV6
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void v1d0(void* p);
};
struct ContObj6
{
    int count;
    void* pObj;
    void* pExtra;
};
struct Node1_6;
struct Cont6
{
    Node1_6* FUN_00717e50();
};
struct Node1_6
{
    ContObj6** FUN_006815c0();
    Node1_6* FUN_00726070();
    bool FUN_008256d0();
};
struct ItemCh6
{
    void* pExtraList;
    int m_iCountChange;
    void* m_pItemObject;
    int FUN_00726070();
};
struct Node2_6
{
    ItemCh6** FUN_006815c0();
    Node2_6* FUN_00726070();
    bool FUN_008256d0();
};
struct Item2_6
{
    int FUN_00726070();
    int FUN_0044ddc0();
};
bool __cdecl MatchesObjectType(void* a, void* b);
int __cdecl FUN_00679ba0(void* a);
int __fastcall FUN_0044ddc0(ItemCh6* p);
struct FUN_004cffe0_t
{
    void* m_pEntryList;
    bool HasItem(void* pRef);
    void* FUN_004bffb0();
    Item2_6* FUN_004bfba0(void* pForm, int a, int b);
    bool CheckItemRequirement(void* a1, void* a2, int a3, int* a4, void* a5, Actor6* a6);
};
namespace Rebuild004d0650 {
struct Object
{
};
struct Extra
{
    bool HasOnlyAllowedExtraData(int);
};
struct FUN_0096a2d0
{
    char data[8];
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    unsigned FUN_005ae380();
    Extra** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_00905820(Extra* const&);
    void FUN_005ae3d0(Extra**);
    void* FUN_004702f0(unsigned);
};
struct FUN_004bc550
{
    FUN_0096a2d0* list;
    int count;
    Object* form;
    FUN_004bc550(Object*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int FUN_00726070();
    FUN_0096a2d0* FUN_00559450();
};
struct Entry
{
    int count;
    Object* form;
};
struct Node
{
    Entry** FUN_006815c0();
    Node* FUN_00726070();
    bool FUN_008256d0();
};
struct Container
{
    int FUN_00482a90(Object*);
    Node* FUN_00717e50();
};
struct Inventory
{
    FUN_004bc550* FUN_004bfba0(Object*, int, int);
    Container* FUN_004bffb0();
    FUN_004bc550* FUN_004d0650(Object*, int);
};
// @fnv 0x004d0650
FUN_004bc550* Inventory::FUN_004d0650(Object* object, int arg)
{
    FUN_004bc550* source3 = FUN_004bfba0(object, 1, arg);
    FUN_004bc550* result2 = 0;
    if (source3)
    {
        int count2 = FUN_004bffb0()->FUN_00482a90(object);
        result2 = new FUN_004bc550(object, count2 + source3->FUN_00726070());
        if (source3->FUN_00559450() && source3->FUN_00559450()->FUN_005ae380())
        {
            if (!result2->FUN_00559450())
                result2->list = new FUN_0096a2d0;
            Extra* extra7 = *source3->FUN_00559450()->FUN_006815c0();
            if (extra7->HasOnlyAllowedExtraData(0))
            {
                FUN_0096a2d0* node5 = source3->FUN_00559450();
                while (node5 && *node5->FUN_006815c0())
                {
                    extra7 = *node5->FUN_006815c0();
                    result2->list->FUN_00905820(extra7);
                    node5 = node5->FUN_00726070();
                }
            }
            else
            {
                result2->list->FUN_005ae3d0(&extra7);
            }
        }
        else
        {
            if (result2->FUN_00559450())
            {
                delete result2->list;
                result2->list = 0;
            }
        }
    }
    else
    {
        Node* base6 = FUN_004bffb0()->FUN_00717e50();
        Object* form2 = 0;
        while (base6 && !base6->FUN_008256d0())
        {
            form2 = (*base6->FUN_006815c0())->form;
            if (form2 == object)
            {
                result2 = new FUN_004bc550(object, (*base6->FUN_006815c0())->count);
                break;
            }
            base6 = base6->FUN_00726070();
        }
    }
    return result2;
}
}
struct InventoryScanNode
{
    InventoryStackRecord** FUN_006815c0();
    InventoryScanNode* FUN_00726070();
    bool FUN_008256d0();
};
struct InventoryScanExtra : ExtraDataList
{
    int FUN_0041d360();
};
// 0x004d2480  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 1 stack arg (ret 4) -> bool.  SEH from AutoMemHelper local.
struct AutoMemHelper
{
    int m_iOldMemContext;
    AutoMemHelper(int context, bool track, const char* file, int line);
    ~AutoMemHelper();
};
struct GlobalObject_0096a2d0
{
    void Lock(const char* name);
};
struct BSSpinLockUnlock
{
    void Unlock();
};
extern GlobalObject_0096a2d0 g_011c64e0;
extern const char g_inventoryChangesSourceFilename[];
struct Sh00568bb0
{
    void FUN_00568bb0(void* p);
};
struct Sh00575690
{
    void FUN_00575690(void* p);
};
struct Sh005d43c0
{
    void* FUN_005d43c0();
};
struct Sh00419f80
{
    void FUN_00419f80(void* p);
};
struct Sh00411fd0
{
    void RemoveAllCopyableExtra(void* p);
};
struct Sh00418830
{
    void* FUN_00418830();
};
struct Sh00418800
{
    void* FUN_00418800();
};
struct Sh005ac1e0
{
    bool FUN_005ac1e0(void* a, void* b, void* c, bool d);
};
struct Sh0087ce80
{
    void FUN_0087ce80(void* p);
};
struct Sh00436aa0
{
    void* FUN_00436aa0();
};
struct Sh0049eea0
{
    void FUN_0049eea0(const void* p);
};
struct Sh004013e0
{
    bool GetInitialized() const;
};
struct C004d2480
{
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;
    int unk04;
    int unk08;
    int unk0c;
    bool m_bChanged;

    bool FUN_004d2480(TESObjectREFR* apRef);
};
class FUN_008515f0
{
  public:
    int a;
    ~FUN_008515f0();
};
class ListZ
{
  public:
    void FUN_00905330(FUN_008515f0**);
    int FUN_005ae380();
};
class Holder
{
  public:
    ListZ* m0;
    int m4;
    void RemoveAndDelete(FUN_008515f0* p);
};
class TESEnchantableForm
{
  public:
    virtual void v00();
    unsigned short FUN_004a8ae0();
};
namespace charge4bd {
struct C4Enchant
{
    float GetValue();
};
struct C4Node
{
    C4Enchant* pItem;
    C4Node* pNext;
    C4Enchant** FUN_006815c0();
};
struct C4Entry
{
    C4Node* pList;
    int unk04;
    TESBoundObject* pForm;
    float FUN_004bd350();
};
}
using namespace charge4bd;
struct XActor17;
struct XProcess17;
struct XExtra17;
struct XExtra17;
struct XNodeE17
{
    XExtra17** _ref_006815c0();
    XNodeE17* _ref_00726070();
    bool _ref_008256d0();
    void _ref_00905330(XExtra17**);
};
struct XNodeC17
{
    void _ref_00905330(InventoryStackRecord**);
};
struct XDism17Part17
{
    unsigned char b0;
    unsigned char b1;
};
struct XDism17Arr17
{
    void* a;
    void* b;
    unsigned int FUN_0044ddc0();
};
struct XDism17
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    XDism17Arr17 arr;
    XDism17Part17* GetInfoAt(unsigned int);
};
struct XExtra17
{
    virtual ~XExtra17();
    bool FUN_00418b10();
    bool FUN_00418ab0(bool);
    void SetWornState(bool, bool);
    int ItemsInList();
    char GetExtraByteValue();
    void FUN_00419ad0(short);
    bool FUN_004bca60();
    bool CompareListForContainer(XExtra17*, int, bool);
    short FUN_00418770();
    void SetHotKey(unsigned char);
    XDism17* FUN_0042e8c0();
};
struct XChange17
{
    int _ref_00726070();
    int FUN_004bc8f0(bool);
    void* FUN_00559450();
    ~XChange17();
};
struct XBiped17
{
    bool FUN_00418b10();
};
struct XBiped17Sub17
{
    bool FUN_00480d10();
    bool FUN_004c0bd0();
};
struct XArmor17
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    XBiped17Sub17 biped;
};
struct XFound17
{
    int FUN_0044ddc0();
};
struct XTQ17
{
    void SendCommand22(XActor17*, int);
};
struct XRefr17
{
    void FUN_00571b50();
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};
struct XForm17
{
    bool FUN_00483710();
};
struct XNPC17
{
    void SetField1F0(void*);
};
struct XListObj17
{
    void FUN_00470470();
};
struct XInv17
{
    XNodeC17* pList;
    XActor17* pRef;
    InventoryStackRecord* FUN_004bfba0(unsigned int, int, int);
    TESContainer* FUN_004bffb0();
};
void __fastcall FUN_004bf0e0(InventoryChanges*);
int __fastcall FUN_00401170(unsigned int);
XBiped17* __cdecl FUN_00480db0(unsigned int);
bool __fastcall FUN_004c0bf0(TESObjectWEAP*);
bool __cdecl FUN_008c7aa0();
extern XExtra17* DAT_011c6448;
struct XProcess17
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual InventoryStackRecord* CurrentWeapon();
    virtual InventoryStackRecord* CurrentAmmo();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void SetWeapon(int, int, bool);
    virtual void v164();
    virtual void SetAmmo(int);
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
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
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void SetUpdate(int);
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void UpdateArmor(XActor17*);
};
struct XActor17
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void MarkAsModified(int);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
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
    virtual bool CanRemove(bool);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    XProcess17* process;
    XProcess17* FUN_008d8520();
    XExtra17* FUN_005d43c0();
    void FUN_00571b50();
    void FUN_00483710();
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
    void SetField1F0(void*);
};
struct XHost17
{
    bool FUN_004c0cf0(bool*, unsigned int, int, XActor17*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
};

extern float DAT_010162c0;
extern const char DAT_0101c178[];
extern const char DAT_01012058[];
extern const char DAT_0101dcc4[];
extern const char DAT_010207c0[];
extern const char DAT_010208e0[];

struct MoveActorExt : MoveOwner
{
    bool FUN_008b8e90(MoveForm*);
};
const char* __cdecl FUN_0048e730(TESBoundObject*, MoveOwner*);
void __cdecl FUN_00406d00(char*, unsigned int, const char*, const char*, const char*);
struct InventoryMoveTarget : InventoryMove
{
    void FUN_004cb5f0(MoveOwner*, MoveOwner*, MoveForm*);
};
// @fnv 0x004cb5f0
void InventoryMoveTarget::FUN_004cb5f0(MoveOwner* source, MoveOwner* destination, MoveForm* onlyForm)
{
    MoveItem* item = 0;
    TESBoundObject* form = 0;
    MoveItemNode* itemNode = head;
    while (itemNode && !itemNode->FUN_008256d0())
    {

        MoveItemNode* savedItemNext = itemNode->FUN_00726070();
        item = *itemNode->FUN_006815c0();
        bool restartItems = false;

        if (item && item->FUN_00726070() > 0 && !((MoveForm*)item->FUN_0044ddc0())->IsQuestItem())
        {
            MoveExtraNode* pExtra = item->FUN_00559450();
            form = item->FUN_0044ddc0();
            MoveOwner* actor = 0;
            if (destination->IsActor())
                actor = destination;
            if (pExtra && *pExtra->FUN_006815c0())
            {
                while (pExtra && *pExtra->FUN_006815c0() && !restartItems)
                {
                    MoveExtraNode* savedExtraNext2 = pExtra->FUN_00726070();
                    MoveExtra* extra = *pExtra->FUN_006815c0();
                    bool restartExtras = false;
                    MoveForm* original4 = (MoveForm*)extra->FUN_00418660();
                    MoveForm* baseExtraA = 0;
                    MoveForm* modExtra_2 = 0;
                    if (original4)
                    {
                        if (original4->FUN_00401170() == 8)
                            modExtra_2 = original4;
                        else
                            baseExtraA = original4;
                    }

                    if (!onlyForm || onlyForm == (MoveForm*)extra->FUN_00418660())
                    {
                        if (actor && !onlyForm)
                            onlyForm = (MoveForm*)actor->FUN_007af430();
                        if (extra->FUN_00418660() && (MoveForm*)extra->FUN_00418660() != (MoveForm*)source &&
                            (!actor || actor->FUN_007af430() == baseExtraA ||
                             ((MoveActorExt*)actor)->FUN_008b8e90(modExtra_2)))
                        {

                            if (item->FUN_00559450()->FUN_005ae380() <= 1)
                                restartItems = true;
                            else
                                restartExtras = true;

                            if (onlyForm)
                            {
                                MoveString formattedItem;
                                int copies = extra->FUN_00418770();
                                if (copies > 1)
                                {
                                    FUN_00406f60(&formattedItem, DAT_0101c178, copies, FUN_00482720(form),
                                                 moveVerb_r004cb5f0.FUN_00403df0(),
                                                 movePlural_r004cb5f0.FUN_00403df0());
                                }
                                else
                                {
                                    FUN_00406f60(&formattedItem, DAT_01012058, FUN_00482720(form),
                                                 movePlural_r004cb5f0.FUN_00403df0());
                                }
                                char message4[260];
                                FUN_00406d00(message4, 260, DAT_0101dcc4, DAT_010207c0,
                                             FUN_0048e730(form, inventoryPlayer));
                                DispatchMessageToSink(formattedItem.FUN_00559450(), 0, DAT_010208e0,
                                                      inventoryPlayer->FUN_008adcf0(form, false, false), DAT_010162c0,
                                                      0);
                            }
                            FUN_004c37d0(source, form, false, extra->FUN_00418770(), extra, 0, destination, 0, 0, true,
                                         0, 0);
                            itemNode = head;
                        }
                    }

                    if (restartItems)
                    {
                        itemNode = head;
                        pExtra = 0;
                    }
                    else if (restartExtras)
                    {
                        pExtra = item->FUN_00559450();
                    }
                    else
                    {
                        if (savedExtraNext2 != pExtra->FUN_00726070())
                            pExtra = item->FUN_00559450();
                        else
                            pExtra = savedExtraNext2;
                        if (!pExtra)
                        {
                            if (savedItemNext != itemNode->FUN_00726070())
                                itemNode = head;
                            else
                                itemNode = savedItemNext;
                        }
                    }
                }
            }
            else
            {
                if (savedItemNext != itemNode->FUN_00726070())
                    itemNode = head;
                else
                    itemNode = savedItemNext;
            }
        }
        else
        {
            if (savedItemNext != itemNode->FUN_00726070())
                itemNode = head;
            else
                itemNode = savedItemNext;
        }
    }
}
